# strategy02-attempt2 — PDB-symbolized Ghidra decompile of Strategy02.dll (Tier B, **verified 2026-10-28**)

Produced 2026-10-15 00:18–00:19 (file timestamps) by Ghidra from `Strategy02.dll` + `Strategy02.pdb`
(the same bytes as `original/missions/`; the DLL's SHA-256 `a4b3ce22…`). Received as a 53-file set
(`decompiled/`), no Ghidra project, no script, no README — hence *pending regeneration*: task 8
re-runs the decompile with the pinned Ghidra under `tools/ghidra/`, diffs it against this copy and
records the differences before anything here is quoted as fact.

Every `src/**/*.decomp.c` starts with the same header:

```
// Reconstructed by Ghidra from Strategy02.dll + Strategy02.pdb
// Original source file: /e:/github/vsr_dll_source/missions/<dir>/<file>
// Functions are ordered by original source line. This is decompiler
// output, not the author's source: names/types come from the PDB,
// local variable names and control flow are reconstructed.
```

## Contents

| Path | What |
|---|---|
| `src/missions/{strategy02,luamission,shared,vsrcore}/*.decomp.c` + `src/source/fun3d/scriptutils.h.decomp.c` | 48 files, one per original source file with code, functions in original line order |
| `all_functions.tsv` | 1,925 functions: `address size user name file minLine maxLine` (953 project, 972 Lua/STL/CRT) |
| `user_functions.tsv` | the 953 project functions with full signatures |
| `globals.tsv` | 3,634 named globals: 2,414 `TerminatedCString`, RTTI, vtables, the `luaL_Reg[486]` table |
| `user_namespaces.txt` | the 26 project namespaces / classes |
| `vsr_types.h` | Ghidra's data-type dump (1,506 lines) — `std::vector<>` members appear as opaque 12-byte blobs |

Derived tables: `reference/manifest/strategy02-attempt2/` (`tools/manifest_from_tsv.py`).

## Known limitations (to be re-checked on regeneration)

- Lua C-API calls appear argument-less (`lua_setglobal();`) because no signatures were applied to
  the statically linked Lua; 161 `__security_check_cookie` injections; 12 "Unable to track
  spacebase" frames (`SetupTeam`, `GetSpawnpointForTeam`, `BZ1Helper::Init`, `OpenLogFile`);
  2 unrecovered jump tables in `dllbase.cpp Update`; class-hash compares appear as float literals.
- Image base `0x4fc00000`; `.edata` at `0x4fc68bd0` (one export `GetMisnAPI` @ `0x4fc40409`).
