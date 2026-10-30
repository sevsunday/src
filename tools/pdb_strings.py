#!/usr/bin/env python3
"""
pdb_strings.py - extract source paths and build-environment strings from the
shipped PDBs (Tier A) without any external tool.

A PDB is an MSF container; its string tables are plain ASCII/UTF-8. Scanning
the raw bytes for printable runs recovers every source path, every linked
library path and the compiler/SDK paths the PDB records. This is the evidence
behind reference/manifest/BUILD_ENVIRONMENT.md and the per-DLL file
membership; re-run it whenever the originals change.

Usage:
    python tools/pdb_strings.py [--pdb-dir original/missions] [--out reference/manifest/pdb]

Outputs (per PDB, lowercase stem):
    <dll>.sources.txt   unique source paths under vsr_dll_source (as stored)
    <dll>.env.txt       compiler / SDK / library / object paths
    <dll>.other.txt     every other path-like string (for inspection)
and
    SUMMARY.md          per-DLL membership matrix of the project source files

stdlib only.
"""
from __future__ import annotations

import argparse
import os
import re
import sys
from collections import OrderedDict
from pathlib import Path

PRINTABLE = re.compile(rb"[\x20-\x7e]{6,}")
PATHLIKE = re.compile(r"(?i)(?:[a-z]:[\\/]|[\\/]{1,2}[a-z])[^\s\"'<>|*?]{3,}")

PROJECT_ROOT_RE = re.compile(r"(?i)vsr_dll_source[\\/](.+)$")
ENV_MARKERS = (
    "microsoft visual studio",
    "windows kits",
    "vctools",
    "program files",
    "\\bzcc\\",
    "/bzcc/",
    "battlezone2",
    "source_3rdparty",
    "lua51_lib",
    "lua52",
    ".lib",
    ".obj",
    ".asm",
    ".pdb",
    "source\\fun3d",
    "source/fun3d",
)
# The project's own source files, as recorded by the PDB (lowercase).
SOURCE_EXT = (".cpp", ".h", ".c", ".hpp", ".inl")


def extract_strings(data: bytes) -> list[str]:
    out = []
    for m in PRINTABLE.finditer(data):
        try:
            out.append(m.group(0).decode("ascii"))
        except UnicodeDecodeError:
            continue
    return out


def classify(strings: list[str]):
    sources: "OrderedDict[str, None]" = OrderedDict()
    env: "OrderedDict[str, None]" = OrderedDict()
    other: "OrderedDict[str, None]" = OrderedDict()
    for s in strings:
        for pm in PATHLIKE.finditer(s):
            p = pm.group(0).rstrip(".,;:)")
            low = p.lower()
            if "vsr_dll_source" in low and low.endswith(SOURCE_EXT):
                sources[p] = None
            elif "vsr_dll_source" in low:
                env[p] = None  # libs, pdb output, obj dirs inside the project
            elif any(k in low for k in ENV_MARKERS):
                env[p] = None
            else:
                other[p] = None
    return list(sources), list(env), list(other)


def compiler_strings(strings: list[str]) -> list[str]:
    hits = []
    for s in strings:
        low = s.lower()
        if ("microsoft (r)" in low and ("compiler" in low or "link" in low or "assembler" in low)) \
           or low.startswith("cl.exe") or " /zi" in low or "/mt" in low and "/o" in low \
           or "msvc" in low and "14." in low:
            hits.append(s)
    return sorted(set(hits))


def project_rel(path: str) -> str:
    m = PROJECT_ROOT_RE.search(path)
    if not m:
        return path
    return m.group(1).replace("/", "\\").lower()


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--pdb-dir", default="original/missions")
    ap.add_argument("--out", default="reference/manifest/pdb")
    args = ap.parse_args(argv)

    root = Path(__file__).resolve().parents[1]
    pdb_dir = (root / args.pdb_dir).resolve()
    out_dir = (root / args.out).resolve()
    out_dir.mkdir(parents=True, exist_ok=True)

    pdbs = sorted(pdb_dir.glob("*.pdb"), key=lambda p: p.name.lower())
    if not pdbs:
        print(f"no .pdb under {pdb_dir}", file=sys.stderr)
        return 1

    membership: "OrderedDict[str, dict[str, bool]]" = OrderedDict()
    dll_names = []
    per_dll_counts = {}

    for pdb in pdbs:
        stem = pdb.stem.lower()
        dll_names.append(stem)
        data = pdb.read_bytes()
        strings = extract_strings(data)
        sources, env, other = classify(strings)
        comp = compiler_strings(strings)

        rel_sources = sorted({project_rel(s) for s in sources})
        per_dll_counts[stem] = len(rel_sources)
        for rs in rel_sources:
            membership.setdefault(rs, {})[stem] = True

        (out_dir / f"{stem}.sources.txt").write_text(
            f"# source paths recorded in {pdb.name} (unique, as stored, {len(sources)} raw -> {len(rel_sources)} project-relative)\n"
            + "\n".join(sorted(set(sources), key=str.lower)) + "\n",
            encoding="utf-8", newline="\n")
        (out_dir / f"{stem}.env.txt").write_text(
            f"# build-environment strings recorded in {pdb.name}\n\n# compiler/linker banners\n"
            + "\n".join(comp) + "\n\n# paths (compiler, SDK, libraries, objects, outputs)\n"
            + "\n".join(sorted(set(env), key=str.lower)) + "\n",
            encoding="utf-8", newline="\n")
        (out_dir / f"{stem}.other.txt").write_text(
            f"# other path-like strings in {pdb.name} (inspection only)\n"
            + "\n".join(sorted(set(other), key=str.lower)) + "\n",
            encoding="utf-8", newline="\n")
        print(f"{pdb.name}: {len(strings)} strings, {len(rel_sources)} project source files, {len(env)} env paths")

    # membership matrix
    lines = [
        "# PDB source-file membership (generated by tools/pdb_strings.py)",
        "",
        "Source paths recorded in each shipped PDB, relative to `e:\\github\\vsr_dll_source\\`,",
        "lowercase as stored. `x` = the file contributed code to that DLL.",
        "",
        "| file | " + " | ".join(dll_names) + " |",
        "|---|" + "|".join(":-:" for _ in dll_names) + "|",
    ]
    for rs in sorted(membership):
        row = membership[rs]
        lines.append("| `" + rs + "` | " + " | ".join("x" if row.get(d) else "" for d in dll_names) + " |")
    lines += ["", "| DLL | project source files |", "|---|---:|"]
    for d in dll_names:
        lines.append(f"| {d} | {per_dll_counts[d]} |")
    (out_dir / "SUMMARY.md").write_text("\n".join(lines) + "\n", encoding="utf-8", newline="\n")
    print(f"wrote {out_dir / 'SUMMARY.md'} ({len(membership)} files)")
    return 0


if __name__ == "__main__":
    sys.exit(main())
