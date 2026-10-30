#!/usr/bin/env python3
"""
check_strings.py - QA gate 4: string-table parity between GBD's DLLs and ours.

Extracts every NUL-terminated printable string (>= 4 chars) from the initialized
data sections (.rdata, .data) of both PE images and compares the sets:

  missing  - literal in GBD's DLL, absent from ours  -> FAIL (a message, ODF key,
                                                         format string or path not yet ported)
  extra    - literal in ours, absent from GBD's      -> WARN (a typo, a debug string,
                                                         or a toolchain artefact)

Strings that belong to the compiler / CRT / Lua rather than to GBD's code are
filtered by two allow lists in tools/parity/: strings_toolchain.txt (patterns both
toolchains emit differently) and strings_allow.txt (project-approved deltas).
Writes reference/manifest/parity/<dll>.strings.md.

Until the port is complete the gate is informational (exit 0 with counts); pass
--strict to fail on missing strings.

Usage: python tools/check_strings.py [--ours out/Win32/Release/bin/missions] [--strict]
stdlib only.
"""
from __future__ import annotations

import argparse
import re
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
DLLS = ["Strategy02", "LuaMission", "Instant", "deathmatch01"]
DATA_SECTIONS = {".rdata", ".data"}
MIN_LEN = 4

# Toolchain / CRT / Lua strings vary with the compiler version and the Lua copy; ignore them.
TOOLCHAIN_PATTERNS = [
    r"^Microsoft", r"^Visual C\+\+", r"^api-ms-win-crt-", r"^VCRUNTIME", r"^MSVCP", r"^KERNEL32", r"^battlezone2\.exe$",
    r"^\.text$|^\.rdata$|^\.data$|^\.reloc$|^\.rsrc$", r"^<assembly", r"^</assembly", r"^\s*<", r"^Unknown exception$",
    r"^bad allocation$", r"^bad array new length$", r"^string too long$", r"^vector<T> too long$", r"^invalid stoi", r"^ios_base",
    r"^RSDS", r"^\$Lua: ", r"^\$Authors: ", r"^\$URL: ", r"^Lua 5\.2", r"^Copyright \(C\) 1994", r"^PUC-Rio",
    r"^_\w+$", r"^\?\?", r"^@", r"^__", r"^e\.\w+\(\w+\)$", r"^E:\\|^e:\\|^C:\\|^c:\\|^d:\\|^D:\\",
    r"^\w\.pdb$", r"\.pdb$", r"^Strategy02\.dll$|^LuaMission\.dll$|^Instant\.dll$|^deathmatch01\.dll$",
    r"^GetMisnAPI$", r"^[\x20-\x7e]{4,8}$",  # very short fragments are mostly code/relocation noise
]


def _import_name_rvas(data: bytes, pe_off: int, sections: list[tuple[int, int, int, int]]) -> set[int]:
    """RVAs of every import hint/name entry (the name itself starts 2 bytes in)."""
    def rva_to_off(rva: int) -> int | None:
        for vsize, vaddr, rawsize, rawptr in sections:
            if vaddr <= rva < vaddr + max(vsize, rawsize):
                return rawptr + (rva - vaddr)
        return None
    (magic,) = struct.unpack_from("<H", data, pe_off + 24)
    dd_off = pe_off + 24 + (96 if magic == 0x10B else 112)
    imp_rva, imp_size = struct.unpack_from("<II", data, dd_off + 8)  # data directory 1 = imports
    names = set()
    off = rva_to_off(imp_rva) if imp_rva else None
    while off is not None:
        oft, _ts, _fc, name_rva, ft = struct.unpack_from("<IIIII", data, off)
        if not (oft or name_rva or ft):
            break
        thunk = rva_to_off(oft or ft)
        while thunk is not None:
            (entry,) = struct.unpack_from("<I", data, thunk)
            if not entry:
                break
            if not entry & 0x80000000:
                names.add(entry)
            thunk += 4
        off += 20
    return names


def pe_data_strings(path: Path) -> set[str]:
    data = path.read_bytes()
    (pe_off,) = struct.unpack_from("<I", data, 0x3C)
    (nsec,) = struct.unpack_from("<H", data, pe_off + 6)
    (opt_size,) = struct.unpack_from("<H", data, pe_off + 20)
    sec_off = pe_off + 24 + opt_size
    sections = []
    for i in range(nsec):
        s = sec_off + i * 40
        name = data[s:s + 8].rstrip(b"\0").decode("ascii", "replace")
        vsize, vaddr, rawsize, rawptr = struct.unpack_from("<IIII", data, s + 8)
        sections.append((vsize, vaddr, rawsize, rawptr, name))
    import_names = _import_name_rvas(data, pe_off, [t[:4] for t in sections])
    out = set()
    for vsize, vaddr, rawsize, rawptr, name in sections:
        if name not in DATA_SECTIONS:
            continue
        blob = data[rawptr:rawptr + min(rawsize, vsize if vsize else rawsize)]
        for m in re.finditer(rb"[\x20-\x7e\t\r\n]{%d,}\x00" % MIN_LEN, blob):
            start = m.start()
            # A run that does not begin right after a NUL has swallowed the printable tail of the
            # preceding datum (a float or pointer byte such as 0x4F 'O'). Pooled literals are
            # 4-byte aligned, so in that case advance to the next alignment boundary. Import
            # hint/name entries (a 2-byte hint, then the name) are 2-aligned by design: the name
            # is taken from the import table instead.
            if start > 0 and blob[start - 1] != 0:
                hint = next((r for r in (vaddr + start - 2, vaddr + start - 1, vaddr + start) if r in import_names), None)
                if hint is not None:
                    start = hint + 2 - vaddr
                else:
                    start += (-(vaddr + start)) & 3
            s = blob[start:m.end() - 1]
            if len(s) < MIN_LEN:
                continue
            try:
                out.add(s.decode("ascii"))
            except UnicodeDecodeError:
                pass
    return out


def load_list(name: str) -> list[re.Pattern]:
    p = ROOT / "tools" / "parity" / name
    pats = []
    if p.exists():
        for l in p.read_text(encoding="utf-8").splitlines():
            l = l.rstrip("\n")
            if not l.strip() or l.startswith("#"):
                continue
            pats.append(re.compile(l))
    return pats


def filtered(strings: set[str], pats: list[re.Pattern]) -> set[str]:
    return {s for s in strings if not any(p.search(s) for p in pats)}


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--ours", default="out/Win32/Release/bin/missions")
    ap.add_argument("--strict", action="store_true")
    args = ap.parse_args(argv)
    pats = [re.compile(p) for p in TOOLCHAIN_PATTERNS] + load_list("strings_toolchain.txt")
    allow = load_list("strings_allow.txt")
    out_dir = ROOT / "reference" / "manifest" / "parity"
    out_dir.mkdir(parents=True, exist_ok=True)
    total_missing = 0
    any_ours = False
    for dll in DLLS:
        theirs_p = ROOT / "original" / "missions" / f"{dll}.dll"
        ours_p = ROOT / args.ours / f"{dll}.dll"
        if not ours_p.exists():
            print(f"{dll}: no build output - run build.cmd first")
            continue
        any_ours = True
        theirs = filtered(pe_data_strings(theirs_p), pats)
        ours = filtered(pe_data_strings(ours_p), pats)
        missing = sorted(s for s in theirs - ours if not any(p.search(s) for p in allow))
        extra = sorted(s for s in ours - theirs if not any(p.search(s) for p in allow))
        total_missing += len(missing)
        md = [f"# {dll}.dll — string parity (tools/check_strings.py)", "",
              f"GBD: {len(theirs)} data-section strings after toolchain filtering. Ours: {len(ours)}.",
              f"missing {len(missing)} · extra {len(extra)}", "", f"## Missing — {len(missing)}", ""]
        md += [f"- `{s!r}`" for s in missing]
        md += ["", f"## Extra — {len(extra)}", ""]
        md += [f"- `{s!r}`" for s in extra]
        (out_dir / f"{dll.lower()}.strings.md").write_text("\n".join(md) + "\n", encoding="utf-8", newline="\n")
        print(f"{dll}: GBD {len(theirs)} / ours {len(ours)} strings; missing {len(missing)}, extra {len(extra)}")
    if not any_ours:
        return 1
    if total_missing and args.strict:
        print("check_strings: FAIL (strict)")
        return 1
    print("check_strings: " + ("OK" if not total_missing else f"{total_missing} missing strings (informational until the port completes; --strict to fail)"))
    return 0


if __name__ == "__main__":
    sys.exit(main())
