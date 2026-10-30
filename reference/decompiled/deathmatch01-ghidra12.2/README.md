# deathmatch01-ghidra12.2 — decompile of deathmatch01.dll (Tier B)

Produced 2026-10-29 on this machine by `tools/ghidra/run_headless.cmd deathmatch01` with the pinned portable
Ghidra 12.2 (`tools/ghidra/VERSIONS.txt`: zip SHA-256 `2c2cd776…`, JDK 25.0.5) from
`original/missions/deathmatch01.dll` + `.pdb` (`EXPORT_INFO.txt`: executable SHA-256
`b982c416…212478c5e6020`, which is the value in `original/missions/SHA256SUMS.txt`; image base `0x4fc00000`;
source-line map available). Logs: `ghidra-headless.log`, `ghidra-script.log`. First decompile of this
DLL — no earlier copy to diff against; cross-checked against the verified Strategy02 set.

## Result

| Aspect | Result |
|---|---|
| Functions | 1,929 (960 project functions, 47 source files); **960 decompiled, 0 failed** |
| Shared source vs `../strategy02-ghidra12.2` | 864 functions appear in both sets with **identical original-line ranges**; 823 also identical in size, 41 differ only in size (LTCG per link) |
| Only here | `deathmatch01.cpp` — 46 functions, original lines 84-2778 (13,259 bytes) incl. `BuildMission`; `pupmgr.cpp` — 5 functions, lines 22-144 (999 bytes: `Init` / `Execute` / `Load` / `Save` / `PostLoad`, the 1.3 PUPMgr unchanged); `dllutils.cpp` here holds only `GetCheckedNetworkSvar` (its `IsRecycler` / `CountAlliedPlayers` are Strategy02's) |
| Not here | `startingvehicles.cpp` (Strategy02 only); `trace.cpp` produces no procedures (release build) |

**Conclusion.** Clean first-generation Tier B set. Cite it for `deathmatch01.cpp` and `pupmgr.cpp`; for the
shared source any of the four sets is citable.

## Contents

Same shape as the Strategy02 sets (`src/**/*.decomp.c`, `all_functions.tsv`, `user_functions.tsv`,
`globals.tsv`, `user_namespaces.txt`, `vsr_types.h`) plus `EXPORT_INFO.txt`. Same stale-`TeamInfo`
warning in Ghidra's `vsr_types.h` as the other exports; live layouts in
`reference/manifest/pdb/deathmatch01.types.json`.

Derived tables: `reference/manifest/deathmatch01-ghidra12.2/` (`tools/manifest_from_tsv.py --set deathmatch01-ghidra12.2`).
