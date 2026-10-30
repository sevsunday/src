# instant-ghidra12.2 — decompile of Instant.dll (Tier B)

Produced 2026-10-29 on this machine by `tools/ghidra/run_headless.cmd Instant` with the pinned portable
Ghidra 12.2 (`tools/ghidra/VERSIONS.txt`: zip SHA-256 `2c2cd776…`, JDK 25.0.5) from
`original/missions/Instant.dll` + `.pdb` (`EXPORT_INFO.txt`: executable SHA-256
`c17c7d1c…c5051bd7e407d`, which is the value in `original/missions/SHA256SUMS.txt`; image base `0x4fc00000`;
source-line map available). Logs: `ghidra-headless.log`, `ghidra-script.log`. First decompile of this
DLL — no earlier copy to diff against; cross-checked against the verified Strategy02 set.

## Result

| Aspect | Result |
|---|---|
| Functions | 1,899 (932 project functions, 45 source files); **932 decompiled, 0 failed** |
| Shared source vs `../strategy02-ghidra12.2` | 864 functions appear in both sets with **identical original-line ranges**; 827 also identical in size, 37 differ only in size (LTCG per link: `taunts.cpp`, `attacherhelper.cpp`, `buildinghelper.cpp`, `bz1helper.cpp` bodies a few bytes apart) |
| Only here | `instantmission.cpp` — 23 functions, original lines 62-1760 (11,438 bytes), plus this DLL's `BuildMission` |
| Not here | `dllutils.cpp` / `startingvehicles.cpp` — not linked into Instant.dll |

**Conclusion.** Clean first-generation Tier B set. Cite it for `instantmission.cpp`; for the shared
source any of the four sets is citable.

## Contents

Same shape as the Strategy02 sets (`src/**/*.decomp.c`, `all_functions.tsv`, `user_functions.tsv`,
`globals.tsv`, `user_namespaces.txt`, `vsr_types.h`) plus `EXPORT_INFO.txt`. Same stale-`TeamInfo`
warning in Ghidra's `vsr_types.h` as the other exports; live layouts in
`reference/manifest/pdb/instant.types.json`.

Derived tables: `reference/manifest/instant-ghidra12.2/` (`tools/manifest_from_tsv.py --set instant-ghidra12.2`).
