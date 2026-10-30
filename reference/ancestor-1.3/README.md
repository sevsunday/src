# reference/ancestor-1.3/ — BZ2 1.3.7.2-b132L DLL source pack (Tier A)

Source: `BlackDragonN001/LuaMission` commit `353698f578e00ea5f9806fea701b5bd7c69d94ce` (master,
2017-10-19, "-Fixed copy paste errors."), folder `BZ2 1.3.7.2-b132L Dll Source Code/`, extracted
2026-10-28 with `git archive` from the preservation mirror; all 124 blob hashes re-checked.
The folder's own `Readme_Source.txt` is the pack's statement of terms.

Layout as found:

- `Missions/Shared/` — `DllBase`, `DLLUtils`, `MathUtils`, `StartingVehicles`, `Taunts`,
  `TRNAllies`, `PUPMgr`, `Trace`, `SubMission`, `SPMission`, `MPVehicles`, `cintools`,
  `ScriptUtilsExtention`, `MultSTMission.h`
- `Missions/Strategy02/`, `Deathmatch01/`, `Instant/`, `MPInstant/`, `StratCTF/` — the stock mission DLLs
- `Missions/LuaMission/` — `LuaBindings.cpp/.h` + `LuaMission.cpp/.h` (the 2017 split VSR's `luamission/` descends from)
- `Missions/lua_5_1_5/` — Lua 5.1.5 headers + project (NOT used here; VSR embeds Lua 5.2 — see `third_party/lua-5.2.4/`)
- `Missions/Missions.sln` + per-project `.vcxproj` — kept as the structural model for `build/build.cmd`
- `Source/fun3d/{AiCmds.h, ScriptUtils.h}` — the 1.3-era SDK headers (NOT the BZCC ones; the build reads those from `%BZCC_DIR%`)
- `Source/network/vars.txt` — the 1.3-era ivar/svar list
- `Debug/*.lib` — 1.3-era import libraries (not used)

Seeds (see `../manifest/FILE_MAP.md`): `shared/{dllbase, dllutils, startingvehicles, taunts, trnallies, pupmgr, trace, submission.h}`,
`strategy02`, `deathmatch01`, `instantmission`, `luamission/{luamission, luabindings}`.