# FILE_MAP — which ancestor seeds which VSR file

Every file GBD's PDBs record under `e:\github\vsr_dll_source\missions\` (see `pdb/SUMMARY.md`),
the ancestor it is seeded from, and the size delta the port has to close. VSR line counts are
`max_line` from `strategy02-attempt2/files.tsv` (last line that produced code = lower bound);
`instantmission`, `deathmatch01`, `pupmgr`, `trace` from the task-13 sets (`instant-ghidra12.2`, `deathmatch01-ghidra12.2`).

Ancestors: **D3** = `reference/ancestor-1.3/Missions/` (GBD's public 1.3.7.2 pack, 2017, Tier A);
**D4** = `reference/ancestor-bz1helper-2015/Shared/` (2015 BZ1Helper family, Tier A′).
Where both hold a file, the one structurally closer to the decompile is the primary seed and the
other is consulted for the diff. `decompile-only` = no usable ancestor.

Rule for every seeded file: ancestor → overlay PDB-true declarations (names, signatures,
layouts from `vsr_types.h` / `functions.tsv`) → bring each body to VSR against the regenerated
decompile → cross-check with GBD's Lua port where it covers the function (`original/lua/`).

## missions/shared

| VSR file | VSR lines | Primary seed | Lines | Also | Delta / notes |
|---|---:|---|---:|---|---|
| `dllbase.cpp` | 402 | D3 `Shared/DllBase.cpp` | 342 | D4 `DllBase.cpp` (identical 342) | +60: `SetWorld` keeps `Missions[3]` per world, `GetMisnAPI` installs the five `SetPre*Callback`s (`dllbase.cpp.decomp.c:562-597`) |
| `dllbase.h` | — | D3 `Shared/DllBase.h` | 109 | D4 | 23-entry vtable per decompile (`DLLBase` vftable) |
| `dllutils.cpp` | 77 | D3 `Shared/DLLUtils.cpp` | 66 | D4 (identical) | +11: `GetCheckedNetworkSvar(listType, str)` 49-77 is VSR's |
| `dllutils.h` | — | D3 `Shared/DLLUtils.h` | 20 | | |
| `startingvehicles.cpp` | 154 | D3 `Shared/StartingVehicles.cpp` | 119 | D4 (100) | +35: `startingVariant` suffix + bare-name fallback, `Save/Load` 128-154 |
| `submission.h` | — | D3 `Shared/SubMission.h` | 63 | D4 | header only in the PDBs (no `.cpp` linked) |
| `taunts.cpp` | 220 | **D4 `Taunts.cpp`** | 321 | D3 `Shared/Taunts.cpp` (723, in-source string tables) | VSR reads `.trn [DLL] TauntODFFile` → `.odf [TauntCategories]` → `.otf` lines (`taunts.cpp.decomp.c`), i.e. the file-driven 2015 shape, trimmed; D3's table version is the wrong shape |
| `taunts.h` | — | D4 `Taunts.h` | 29 | D3 (24) | |
| `trace.cpp` | 0 | D3 `Shared/Trace.cpp` | 25 | D4 (identical) | deathmatch01 only; release build — no procedure survives (`Trace()` expands to `{}`), ported as the D3 text |
| `trnallies.cpp` | 53 | D3 `Shared/TRNAllies.cpp` | 48 | D4 (42) | `[DefaultAllies] Entry1..N` = `"A_B"` → `Ally(A,B)` |
| `trnallies.h` | — | D3 `Shared/TRNAllies.h` | 11 | D4 | |
| `pupmgr.cpp` | 144 | D3 `Shared/PUPMgr.cpp` | 132 | D4 (140) | deathmatch01 only; +12 = header comment / blank lines — the five functions are the 1.3 code unchanged (prefix list, lengths, 10 s default; verified against dumpbin). Cross-check Lua port `Helpers/_PUPMgr.lua` |
| `pupmgr.h` | — | D3 `Shared/PUPMgr.h` | 37 | D4 (38) | |

## missions/strategy02 · instant · deathmatch01

| VSR file | VSR lines | Primary seed | Lines | Cross-check | Delta / notes |
|---|---:|---|---:|---|---|
| `strategy02.cpp` | 3,859 | D3 `Strategy02/Strategy02.cpp` | 1,914 | Lua port `Scripts/Strategy.lua` (2,811) | ×2: VSR added ST:Capture, MPI CPU base spawn + scrap trickle, `m_RestorePlayers`, camera pods, morph auto-deploy, recycler invulnerability, spawn-kill penalty, thug scav/pilot management, `[DLL]` `.trn` keys; function table in `RESEARCH_NOTES` §3.3 |
| `strategy02.h` | 58 | D3 `Strategy02/strategy02.h` | 169 | | VSR's header is SHORTER: the state moved into `BZ1Helper` (`TeamInfo` ×16, `MapInfo`) — `Strategy02` itself adds only its own fields (`sizeof` `0xECA4` incl. the base) |
| `instantmission.cpp` | 1,760 | D3 `Instant/InstantMission.cpp` | 1,099 | Lua port `Scripts/InstantMission.lua` (979) | +660: 23 functions (62-1760), `instant-ghidra12.2` |
| `instantmission.h` | — | D3 `Instant/InstantMission.h` | 153 | | layout in `pdb/instant.types.json` |
| `deathmatch01.cpp` | 2,778 | D3 `Deathmatch01/deathmatch01.cpp` | 2,255 | Lua port `Scripts/Deathmatch.lua` (1,943) | +520: 46 functions (84-2778) incl. `ExecuteRace` / `ExecuteRabbit` / `UpdateAnimals` / `SetupAnimal`, `deathmatch01-ghidra12.2` |
| `deathmatch01.h` | — | D3 `Deathmatch01/deathmatch01.h` | 198 | | layout in `pdb/deathmatch01.types.json` |

## missions/luamission

| VSR file | VSR lines | Primary seed | Lines | Delta / notes |
|---|---:|---|---:|---|
| `luamission.cpp` | 985 | D3 `LuaMission/LuaMission.cpp` | 746 | +240: `LuaMission : BZ1Helper` (was `: DLLBase`), `PreTeleport`, `CreateLuaStringTable`, enum tables, `LuaMissionVersion` 186.0, script `<missionfile>.lua` loader; Lua 5.2 API (D3 is 5.1) |
| `luamission.h` | — | D3 `LuaMission/LuaMission.h` | 74 | |
| `luabindings.cpp` | 6,656 | D3 `LuaMission/LuaBindings.cpp` | 5,614 | +1,040: 486-entry `sLuaScriptUtils` (VSR-only bindings listed in `RESEARCH_NOTES` §3.5: `DoTaunt`, `AddToDispatch`, portal channel API, `LoadValue/SaveValue`, …); Lua 5.1 → 5.2 calls (`luaL_setfuncs`, `lua_pushunsigned`, …) |
| `luabindings.h` | — | D3 `LuaMission/LuaBindings.h` | 1,050 | |

D4's `LUAMission/LUAMission.cpp` (2015, 219 KB monolith, LuaJIT) is NOT a seed — VSR follows D3's 2017 split.

## missions/vsrcore (18 helpers → `VSRCore.lib`, + `shared/taunts.cpp`)

| VSR file | VSR lines .cpp / .h | Primary seed (D4 `Shared/`) | Lines .cpp / .h | Delta / notes |
|---|---|---|---|---|
| `bz1helper` | 5,248 / 1,277 | `BZ1Helper` | 3,244 / 833 | +2,000: 24-file integrity check, `PatchData.txt` version, `OffMapPos`, `TEAMINFO MISMATCH` save audit, `MPISwitchTeams`, `m_GameVersion 20185`, `vsrbasesetup.cfg`, `BZ1Interface` HUD vars, `PreOrdnanceHit` damage multiplier, low-altitude respawn, … (identifier overlap 5/9) |
| `bzcscriptutils` | 5,059 / 1,319 | `BZCScriptUtils` | 2,937 / 797 | +2,100: `ODFNameBlackListMap`, `OpenODF2`, log file (`VSR_<ts>.log`), `GetConfigODF`, `Hash()` (`bzcscriptutils.h.decomp.c:629`), dual-ODF getters (overlap 8/9) |
| `dispatchhelper` | 2,183 / 295 | `DispatchHelper` | 1,692 / 108 | +500 (`Execute` ≈1,880 lines): per-difficulty `<odf>_config.odf` weapon slots, `Escort Target lost, Going Bezerk!`, `Minelayer Shot, Mining`, `Turret Shot, Deploying` (overlap 6/9); port LAST in tier 3 |
| `portalhelper` | 1,985 / 489 | `PortalHelper` | 1,159 / 80 | +800: `DestinationMin/MaxRange`, `MatchTypeUsesChannels`, `ShufflePortalUp/Down`, `TeleportFilter`, channel UI (overlap 5/9) |
| `buildinghelper` | 1,020 / 358 | `BuildingHelper` | 467 / 72 | +550: `[SupplyDepotClass]` rates, taps, `SizeRatioX/Z`, animation banks |
| `productionclasshelper` | 758 / — | `ProductionClassHelper` | 607 / 69 | +150: `ScrapHold` → `base%dshold`, armory sounds by classlabel, `BZCundep` hand-off |
| `attacherhelper` | 686 / 206 | `AttacherHelper` | 516 / 44 | +170: 8 taps (`AttacherClass` 0x40C), Cerberus tail, symmetry mask (overlap 6/6) |
| `carrierhelper` | 637 / 187 | `CarrierHelper` | 317 / 48 | +320: `[CarrierClass]`/`[DroneClass]` keys, `DroneClass` 0x2C |
| `morphobjecthelper` | 577 / 178 | `MorphObjectHelper` | 438 / 43 | +140: cloak energy, `MorphObjectToggle`, `SwitchAllWeapons` |
| `mathutils` | 529 / 166 | `MathUtils` | 445 / 105 | +85: `GetRandomInt/Float`, extra matrix/quaternion helpers (D3 `Shared/MathUtils` 444/139 is the same lineage) |
| `undeployhelper` | 301 / 56 | `UndeployHelper` | 224 / 26 | +77: `UndeployClass` target ODF, `No Free Groups` message, scrap restore |
| `aiweaponhelper` | 201 / — | `AIWeaponHelper` | 202 / 12 | ≈0: per-difficulty `WeaponName1..16` / masks, `SkipRequirements`, `GiveWeapon` |
| `poweruphelper` | 192 / 90 | (none in D4 — `PowerupHelper` absent) | — | **decompile-only** unless a 2015 `PowerupHelper` is found; class-hash constants via recovered `Hash()` |
| `powerhelper` | 165 / 96 | `PowerHelper` | 131 / 45 | +34: `powerRadius`/`powerRange`, Betty VO |
| `scraphelper` | 137 / 47 | `ScrapHelper` | 132 / 30 | ≈0: `RestrictHeight/Slope`, 1023-object cap |
| `utilityshiphelper` | 366 / 96 | **decompile-only** | (D4 123 / 32, 1 of 6 identifiers) | network scavenger credit `AddScrap(GetCommanderTeam(team), Δ × m_ScrapMultiplier)`, service bitmask, `EscortPriority` |
| `vehiclehelper` | 310 / 171 | **decompile-only** | — | remote control, cloak energy, `ShowSkill`, HUD gauge |
| `gravityhelper` | 163 / 56 | **decompile-only** | — | `.trn [Gravity]` ×16 lerp via `SetGravity` |
| `objecthelper` | 119 / 188 | **decompile-only** | — | per-object record, routes `CanTeleport` to portal helper |
| `ambientsoundhelper` | 184 / 101 | **decompile-only** | — | `.trn [Audio]` ×32 |

Correction to the plan's count: D4 has no `PowerupHelper`, so `poweruphelper` joins the decompile-only
set (six files, not five) unless its 2015 source turns up elsewhere in the D4 tree (none found by name;
`PilotResourceHelper`, `RecallMineHelper`, `ShieldHelper` are different helpers).

## Not in VSR

D4 helpers VSR's PDBs never mention (`AmmoDrain`, `Anchor`, `APC`, `AttacherWeapon`, `Deploy`, `DropShip`,
`EnergyArmor`, `Fury`, `Geyser`, `HQCP`, `Jammer`, `LavaDamage`, `Limiter`, `LPad`, `PilotResource`, `Quake`,
`RecallMine`, `Recycle`, `ReplaceOnDeath`, `Satellite`, `Shield`, `SwitchClass`, `Transport`, `cintools`,
`ScriptUtilsExtension`, `SPMission`, `MPVehicles`, `MultSTMission.h`) and D3's `MPInstant`, `StratCTF`,
`cintools`, `ScriptUtilsExtention`, `SPMission`, `MPVehicles` are kept as fetched but are not ported.
