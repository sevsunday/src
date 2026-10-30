#!/usr/bin/env python3
"""
check_status.py - keeps STATUS.md and the source tree in agreement.

Checks:
  1. every source/missions/**/*.cpp|.h has a row in STATUS.md (rows may cover "x.cpp/.h")
  2. every row's state is one of stub | ported | reviewed | compiles | parity | -
  3. the file's `// PROVENANCE: ... | status: <s>` line agrees with its STATUS.md row
  4. no STATUS.md row names a file that does not exist
  5. a file in state `reviewed` or later has a reviewer in its row

Exit 0 = consistent, 1 = findings. stdlib only.
"""
from __future__ import annotations

import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
SRC = ROOT / "source" / "missions"
STATES = {"stub", "ported", "reviewed", "compiles", "parity", "—", "-"}
GENERATED = {"shared/vsr_layout_asserts.h"}


def parse_status():
    text = (ROOT / "STATUS.md").read_text(encoding="utf-8")
    rows = {}
    section = None
    for line in text.splitlines():
        m = re.match(r"^### missions/(\w+)", line)
        if m:
            section = m.group(1)
            continue
        if line.startswith("## "):
            section = None
            continue
        if section and line.startswith("|") and not line.startswith("|---") and "File" not in line.split("|")[1]:
            cells = [c.strip() for c in line.strip().strip("|").split("|")]
            if len(cells) < 4:
                continue
            fname, state, reviewer = cells[0], cells[3], cells[4] if len(cells) > 4 else ""
            fname = fname.strip("`")
            files = []
            if fname.endswith(".cpp/.h"):
                base = fname[:-7]
                files = [f"{base}.cpp", f"{base}.h"]
            else:
                files = [fname]
            for f in files:
                rows[f"{section}/{f}"] = (state, reviewer, line)
    return rows


def provenance_status(p: Path) -> str:
    try:
        first = p.read_text(encoding="utf-8", errors="replace").splitlines()[0]
    except (OSError, IndexError):
        return ""
    m = re.search(r"status:\s*([a-z]+)", first)
    return m.group(1) if m else ""


def main() -> int:
    rows = parse_status()
    findings = []
    files = {p.relative_to(SRC).as_posix() for p in SRC.rglob("*") if p.suffix in (".cpp", ".h")}
    files -= GENERATED
    for f in sorted(files):
        if f not in rows:
            findings.append(f"no STATUS.md row for {f}")
            continue
        state, reviewer, _ = rows[f]
        if state not in STATES:
            findings.append(f"{f}: unknown state '{state}'")
        ps = provenance_status(SRC / f)
        if state not in ("—", "-") and ps and ps != state:
            findings.append(f"{f}: STATUS.md says '{state}' but the PROVENANCE line says '{ps}'")
        if state in ("reviewed", "compiles", "parity") and not reviewer:
            findings.append(f"{f}: state '{state}' needs a reviewer")
    for f in sorted(rows):
        if f not in files and f not in GENERATED:
            findings.append(f"STATUS.md row for missing file {f}")
    if findings:
        print("check_status: FAIL")
        for x in findings:
            print("  " + x)
        return 1
    from collections import Counter
    c = Counter(rows[f][0] for f in files if f in rows)
    print("check_status: OK (" + ", ".join(f"{k}: {v}" for k, v in sorted(c.items())) + ")")
    return 0


if __name__ == "__main__":
    sys.exit(main())
