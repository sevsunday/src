# luamission-ghidra12.2 — decompile of LuaMission.dll (Tier B)

Produced 2026-10-29 on this machine by `tools/ghidra/run_headless.cmd LuaMission` with the pinned portable
Ghidra 12.2 (`tools/ghidra/VERSIONS.txt`: zip SHA-256 `2c2cd776…`, JDK 25.0.5) from
`original/missions/LuaMission.dll` + `.pdb` (`EXPORT_INFO.txt`: executable SHA-256
`a7097e93…b98a5a2a`, which is the value in `original/missions/SHA256SUMS.txt`; image base `0x4fc00000`;
source-line map available). Logs: `ghidra-headless.log`, `ghidra-script.log`. First decompile of this
DLL — there is no earlier copy to diff against, so the cross-check below is against the verified
Strategy02 set.

## Result

| Aspect | Result |
|---|---|
| Functions | 1,866 (901 project functions, 44 source files); **901 decompiled, 0 failed** |
| Shared source vs `../strategy02-ghidra12.2` | 856 functions appear in both sets with **identical original-line ranges** on every one; 785 of them also have identical code size, the other 71 differ only in size (LTCG inlining / folding decided per link — the Lua math wrappers in `luabindings.cpp` are the bulk) |
| Only here | `LuaMission.cpp` → `BuildMission` (lines 983-985): this DLL's `BuildMission` lives in `luamission.cpp` under the `LUA_LIB` guard; in the other three it is the mission file's |
| Not here | `dllutils.cpp` / `startingvehicles.cpp` — not linked into LuaMission.dll (Strategy02 / deathmatch01 only, as `FILE_MAP.md` records) |
| `BZ1Helper::Execute` and every other large function | decompiled (the Strategy02 set's one failure, `Strategy02::Execute`, is a Strategy02-only function) |

**Conclusion.** Clean first-generation Tier B set. For the shared `shared/` / `vsrcore/` / `luamission/`
source any of the four sets is citable; cite this one for `LuaMission.dll`-specific questions
(`luamission.cpp` 27 functions, 13-985; `luabindings.cpp` 516 functions, 8-6656).

## Contents

Same shape as the Strategy02 sets (`src/**/*.decomp.c`, `all_functions.tsv`, `user_functions.tsv`,
`globals.tsv`, `user_namespaces.txt`, `vsr_types.h`) plus `EXPORT_INFO.txt`. Ghidra's `vsr_types.h` carries
the same stale-`TeamInfo` warning as the Strategy02 export (`Array num elements calculation error 41280 % 2480`);
the live layouts are in `reference/manifest/pdb/luamission.types.json`.

Derived tables: `reference/manifest/luamission-ghidra12.2/` (`tools/manifest_from_tsv.py --set luamission-ghidra12.2`).
