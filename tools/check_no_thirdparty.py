#!/usr/bin/env python3
"""
check_no_thirdparty.py - QA gate 5: no third-party (Tier C) code under source/.

Fails when any file under source/ contains an identifier, header name, path or
comment marker that belongs to the VRV mod or to the BZ_REA engine-research
tooling, or references the local Tier C folders. The reconstruction may only
draw on Tier A / A' / B inputs (PROVENANCE.md).

Exit 0 = clean, 1 = findings. stdlib only.
"""
from __future__ import annotations

import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
SRC = ROOT / "source"

# Identifiers / markers that only exist in the forbidden projects.
FORBIDDEN_PATTERNS = [
    # VRV mod
    r"\bVRV[A-Za-z_]*\b", r"\bvrv[_/\\]", r"\bClassicWrecks\b", r"\bEngineApi\.h\b", r"\bTerrainFile\.h\b",
    r"\bWorkshopBootstrap\b", r"\bHoverAces?\b", r"\bbzn_compat\b", r"\bNew-AiOverrides\b", r"\bTest-Publishable\b",
    r"\bEngineCompatibility\b", r"\bvacuum34\b",
    # BZ_REA engine-research tooling
    r"\bBZ_REA\b", r"\bBZDECOMP\b", r"\bpublic-2\.0\.185-live\b", r"\bpublic185\b", r"\bsource-registry\.json\b",
    r"\bLEAF-CONTRACTS\b", r"\bOBJECT-CLASS-LOAD\b", r"\bMISSION-ABI\.md\b",
    # Tier C folders of the analysis workspace
    r"\.v[\\/](?:vrv|BZ_REA_documentation|ExtraUtilities2)", r"\bExtraUtilities2?\b", r"\bEXU2?\b",
]
ALLOW_FILES = set()  # relative paths exempt (none)


def main() -> int:
    pats = [re.compile(p) for p in FORBIDDEN_PATTERNS]
    findings = []
    for p in sorted(SRC.rglob("*")):
        if not p.is_file() or p.suffix.lower() not in (".cpp", ".h", ".c", ".hpp", ".inl", ".def", ".rc"):
            continue
        rel = p.relative_to(ROOT).as_posix()
        if rel in ALLOW_FILES:
            continue
        for i, line in enumerate(p.read_text(encoding="utf-8", errors="replace").splitlines(), 1):
            for pat in pats:
                m = pat.search(line)
                if m:
                    findings.append(f"{rel}:{i}: forbidden token '{m.group(0)}'")
                    break
    if findings:
        print("check_no_thirdparty: FAIL")
        for f in findings:
            print("  " + f)
        return 1
    n = sum(1 for p in SRC.rglob("*") if p.is_file() and p.suffix.lower() in (".cpp", ".h"))
    print(f"check_no_thirdparty: OK ({n} source files, 0 findings)")
    return 0


if __name__ == "__main__":
    sys.exit(main())
