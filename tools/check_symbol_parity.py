#!/usr/bin/env python3
"""
check_symbol_parity.py - QA gate 3: our build's function roster vs GBD's, per DLL.

Reads both PDBs with tools/pdb_types.py (procedures with signatures + module) and
compares the PROJECT functions (modules under missions\\; Lua / CRT / STL compared
by count only). For each DLL:

  missing  - in GBD's PDB, not in ours      (a function not yet emitted; stubs that the
                                             linker dropped also land here until ported)
  extra    - in ours, not in GBD's          (something we added, or a name/signature typo)
  moved    - same function, different module (file membership differs)

Writes reference/manifest/parity/<dll>.symbols.md and prints a summary. The gate
PASSES when missing == extra == moved == 0 for every DLL, or when every difference
is listed in tools/parity/symbol_allow.txt (one qualified name per line, `#` comments).
Until the port is complete the gate is informational: it exits 0 but prints the
counts, unless --strict is given.

Usage: python tools/check_symbol_parity.py [--ours out/Win32/Release/bin/missions] [--strict]
stdlib only.
"""
from __future__ import annotations

import argparse
import sys
from collections import defaultdict
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from pdb_modules import Msf, parse_dbi  # noqa: E402
from pdb_types import Tpi, dump_procs  # noqa: E402
import scaffold_from_manifest as S  # noqa: E402

ROOT = Path(__file__).resolve().parents[1]
DLLS = ["Strategy02", "LuaMission", "Instant", "deathmatch01"]
PROJECT_MODULES = {m.lower() for m in S.MODULE_TO_FILE}


def roster(pdb: Path):
    msf = Msf(pdb.read_bytes())
    tpi = Tpi(msf)
    modules, _ = parse_dbi(msf)
    procs = dump_procs(msf, tpi, modules)
    proj = {}
    other = 0
    for r in procs:
        if r["module"].lower() in PROJECT_MODULES:
            if S.skip_proc_name(r["name"]):
                continue
            key = (r["name"], tuple(S.simplify(p["type"]) for p in r["params"]))
            proj[key] = r
        else:
            other += 1
    return proj, other


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--ours", default="out/Win32/Release/bin/missions")
    ap.add_argument("--strict", action="store_true")
    args = ap.parse_args(argv)
    allow = set()
    af = ROOT / "tools" / "parity" / "symbol_allow.txt"
    if af.exists():
        allow = {l.strip() for l in af.read_text(encoding="utf-8").splitlines() if l.strip() and not l.startswith("#")}
    out_dir = ROOT / "reference" / "manifest" / "parity"
    out_dir.mkdir(parents=True, exist_ok=True)
    total_bad = 0
    any_ours = False
    for dll in DLLS:
        theirs_p = ROOT / "original" / "missions" / f"{dll}.pdb"
        ours_p = ROOT / args.ours / f"{dll}.pdb"
        if not ours_p.exists():
            print(f"{dll}: no build output ({ours_p.relative_to(ROOT)}) - run build.cmd first")
            continue
        any_ours = True
        theirs, theirs_other = roster(theirs_p)
        ours, ours_other = roster(ours_p)
        missing = sorted(k for k in theirs if k not in ours)
        extra = sorted(k for k in ours if k not in theirs)
        moved = sorted(k for k in theirs if k in ours and theirs[k]["module"].lower() != ours[k]["module"].lower())
        bad = [k for k in missing + extra + moved if k[0] not in allow]
        total_bad += len(bad)
        md = [f"# {dll}.dll — symbol parity (tools/check_symbol_parity.py)", "",
              f"GBD: {len(theirs)} project functions (+{theirs_other} Lua/CRT/STL). Ours: {len(ours)} (+{ours_other}).",
              f"missing {len(missing)} · extra {len(extra)} · moved {len(moved)} · allow-listed {len(missing) + len(extra) + len(moved) - len(bad)}", ""]
        for title, rows in (("Missing (in GBD's, not in ours)", missing), ("Extra (in ours, not in GBD's)", extra), ("Moved (different module)", moved)):
            md.append(f"## {title} — {len(rows)}")
            md.append("")
            by_mod = defaultdict(list)
            for k in rows:
                src = theirs.get(k) or ours.get(k)
                by_mod[src["module"]].append(k)
            for mod in sorted(by_mod):
                md.append(f"### {mod}")
                for k in by_mod[mod]:
                    sig = (theirs.get(k) or ours.get(k))["sig"]
                    note = f"  (ours: {ours[k]['module']})" if k in moved else ""
                    md.append(f"- `{sig}`{note}")
                md.append("")
        (out_dir / f"{dll.lower()}.symbols.md").write_text("\n".join(md) + "\n", encoding="utf-8", newline="\n")
        print(f"{dll}: GBD {len(theirs)} / ours {len(ours)} project functions; missing {len(missing)}, extra {len(extra)}, moved {len(moved)}"
              + (f"; {len(bad)} not allow-listed" if bad else ""))
    if not any_ours:
        return 1
    if total_bad and args.strict:
        print("check_symbol_parity: FAIL (strict)")
        return 1
    print("check_symbol_parity: " + ("OK" if not total_bad else f"{total_bad} differences (informational until the port completes; --strict to fail)"))
    return 0


if __name__ == "__main__":
    sys.exit(main())
