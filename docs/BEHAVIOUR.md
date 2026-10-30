# BEHAVIOUR — what the VSR DLLs do, function by function, with evidence

The companion to `NETVARS.md`: that page says what the DLLs *read*; this one says what they *do* with
it — the class chain, the per-function logic of `Strategy02`, the shared files, and every `vsrcore/`
helper with the ODF keys and defaults it consumes. It is the page to read before touching a file under
`source/`, and the map from an in-game observation ("the recycler was invulnerable for ten minutes",
"the CPU got a tank at force 2") to the line that does it.

Trust tiers per `../PROVENANCE.md`. Every number below was re-read on 2026-10-30 from the cited line.
Citation tags are those of `NETVARS.md`:

| Tag | Source | Tier |
|---|---|---|
| `P:<file>:<line>` | the ported source under `source/missions/{strategy02,shared,vsrcore,luamission}/` — behaviour-identical to the binary by the lockstep A/B for `Strategy02.dll` (`../STATUS.md`) | B |
| `D:<file> <orig lines>` | GBD's original source line range for a function, from the PDB (`reference/manifest/strategy02-attempt2/functions.tsv`) | B |
| `a2:<line>` | line in `reference/decompiled/strategy02-attempt2/src/missions/strategy02/strategy02.cpp.decomp.c` (other files named explicitly) | B |
| `G:<line>` | GBD's own C++ text of `Strategy02.cpp`, `original/lua/vsr_dll_lua_873669d/Lua/Strategy.lua` (lines 776-3652; `../STATUS.md` "GBD-text cross-check") | A |
| `Doc:<file>` | `original/docs/VSR Documents/<file>` | A |

Units: the engine runs the DLL at `m_GameTPS` turns per second (20 on every VSR map; `BZCC_DEFAULT_TPS 20`
in the SDK header), so a "tick" is 50 ms and every time constant below that is stored in turns is written
as `TPS × seconds`.

## 1. Class chain and the sizes the port must keep

```
DLLBase (shared/dllbase.cpp)          the 1.3 mission base: default virtuals, the Mission vtable trampolines,
   |                                  SetWorld() keeps Missions[3] (one per lockstep world)
BZ1Helper (vsrcore/bz1helper.cpp)     GBD's helper framework: 17 helper objects, TeamInfo[16], MapInfo,
   |                                  resync diagnostics, the VSR asset check, the MP damage multiplier
LuaMission (luamission/luamission.cpp) the Lua host: loads <map>.lua, forwards every callback when a script runs
   |
Strategy02 (strategy02/strategy02.cpp) team / FFA / MPI / Capture strategy
```

`Instant.dll` and `deathmatch01.dll` replace the top of the chain with `instantMission` / `Deathmatch01`;
`LuaMission.dll` stops at `LuaMission`. The sizes GBD's PDBs record, pinned by the 853 `static_assert`s of
`source/missions/shared/vsr_layout_asserts.h` (QA gate 2): `DLLBase` 0x4 · `BZ1Helper` 0xA428 · `LuaMission`
0xA458 · `Strategy02` 0xECA4 · `instantMission` 0xAC50 · `Deathmatch01` 0xB544 · `BZ1Helper::TeamInfo` 0xA14
(×16) · `BZ1Helper::MapInfo` 0x48 · `SpawnpointInfo` 0x24. Helper records: `ObjectClass` 0x5C ·
`VehicleClass` 0x54 · `BuildingClass` 0x458 · `PowerClass` 0x28 · `PowerupClass` 0x104 · `PortalClass` 0x390 ·
`TeleportTargetClass` 0x14 · `AttacherClass` 0x40C (host + 8 × `AttacherTapClass` 0x80) · `UtilityShipClass`
0x2C · `ScrapClass` 0x4 · `DispatchClass` 0x148 · `UndeployClass` 0x10 · `MorphObjectClass` 0x148 · `CarrierClass`
0x30 · `DroneClass` 0x2C · `GravityInfo` 0x14 (×16) · `AmbientAudioInfo` 0x70 (×32). `Strategy02`'s own
lists: `ThugScavengerClass` / `ThugPilotClass` / `MorphTankClass` / `CommBunkerClass` 0x8, `EmptyShipClass` 0xC.
`BuildMission()` is `new Strategy02` → `operator new(0xECA4)` (`a2:3922-3936`).

The `Strategy02` constructor (`D:strategy02.cpp 72-113`) sets `m_GameTPS = 20`, calls `EnableHighTPS`,
`AllowRandomTracks(true)` and `TRNAllies::SetupTRNAllies(GetMapTRNFilename())`, and declares the
save ranges `b_count 0x1BE, f_count 0x86, h_count 0x40, i_count 0xFF` with `i_array = &m_TotalGameTime`
(`a2:45`). The engine entry is `GetMisnAPI` (`shared/dllbase.cpp`, `D:dllbase.cpp 377-402`):
`misnExport.version = 0x4C89322E`, `VersionModifier = 'BAL1'` (`0x42414c31`), 18 import pointers copied,
five `SetPre*Callback`s installed. No `CreateObject` / `Setup` / `PostRun` / `ProcessCommand` override in
`Strategy02` — those fall through to `LuaMission` / `DLLBase`. Every `Strategy02` callback first forwards
to `LuaMission::*` when `!StopScript` (a Lua script is loaded), then does its own work.

## 2. `strategy02.cpp` — the function table

Original line ranges from the PDB (`D:`), byte sizes from the Strategy02 build:

```
29-32 ShouldRemoveThugScavengerObject 122 · 40 ShouldRemoveThugPilotObject 49 · 50 ShouldRemoveEmptyShipObject 42 · 58 ShouldRemoveMorphTankObject 35
72-113 Strategy02() 402 · 115-117 ~Strategy02 301 · 120-222 Load 855 · 225-255 PostLoad 143 · 258-315 Save 539 · 318-320 GetNextRandomVehicleODF 20
323-329 UpdateObjectives 51 · 332-648 AddObject 1472 · 651-741 DeleteObject 150 · 744-776 SetCPUAIPlan 368 · 786-830 GetInitialPlayerPilotODF 420
834-844 GetInitialRecyclerODF 129 · 872-1006 GetSpawnpointForTeam 749 · 1011-1027 IsRecyclerODF 146 · 1033-1049 / 1053-1069 BuildStartingVehicle ×2
1082-1284 SetupTeam 1966 · 1290-1630 SetupPlayer 2985 · 1634-1999 Init 2626 · 2003-2074 UpdateGameTime 379 · 2078-2136 ExecuteRecyInvulnerability 370
2139-2426 ExecuteCheckIfGameOver 1521 · 2429-3019 Execute 4819 · 3022-3045 AddPlayer 114 · 3048-3054 DeletePlayer 45 · 3058-3154 RespawnPilot 778
3158-3303 DeadObject 1024 · 3306-3323 PlayerEjected 79 · 3326-3345 ObjectKilled 98 · 3349-3368 ObjectSniped 84 · 3424-3455 PreGetIn 206
3459-3461 BuildMission 43 · 3465-3604 ScavengerManagementCode 586 · 3607-3859 ExecuteST_Capture 2260
```

Decompile offsets (`a2:`): `AddObject` 426, `SetupTeam` 1163, `SetupPlayer` 1417, `Init` 1821,
`ExecuteRecyInvulnerability` 2300, `ExecuteCheckIfGameOver` 2369, `Execute` 2737, `RespawnPilot` 3577,
`DeadObject` 3672, `PlayerEjected` 3802, `ObjectKilled` 3829, `ObjectSniped` 3857, `PreGetIn` 3881,
`BuildMission` 3922, `ScavengerManagementCode` 3939, `ExecuteST_Capture` 4069. `Strategy02::Execute` is the
one function no Ghidra release decompiles cleanly; the received attempt2 text is the reference for it
(`../STATUS.md` task 8).

Constants (`P:strategy02.cpp:17-60`): `VEHICLE_SPACING_DISTANCE 20.0` · `ScoreDecrementForSpawnKill 500` ·
`ScoreForWinning 100` · `MaxSpawnKillTime 15` s · `RespawnDistanceAwayXZRange 32.0` · `RespawnDistanceAwayYRange
8.0` · `RespawnPilotHeight 200.0` · `AllyMinRadiusAway 30.0` / `AllyMaxRadiusAway 60.0` · `endDelta 10.0` s ·
`FRIENDLY_SPAWNPOINT_MAX_ALLY 100.0` · `FRIENDLY_SPAWNPOINT_MIN_ENEMY 400.0` · `RANDOM_SPAWNPOINT_MIN_ENEMY 450.0`
· `MAX_AI_TEAMS 5`. GBD's text has the same values (`G:` top of the C++ range; also the finished Lua port's
header).

## 3. `Strategy02` — what each function does

### Init (`D:strategy02.cpp 1634-1999`, `P:strategy02.cpp:1339-1657`)

- `svar6` non-empty → `StartingVehicleManager::Init()` (`a2:1858-1861`).
- `svar0` (map) → `<map>.trn` → `[DLL] RespawnAtLowAltitude` (false) / `FriendlySpawnpointMaxAllyRange` /
  `FriendlySpawnpointMinEnemyRange` / `RandomSpawnpointMinEnemyRange` (the three constants above) /
  `CaptureTarget1..16` / `CaptureIsRandom` (false), and `[VSR] MapAmbientSound` → `EasterEggSound =
  StartAudio2D(..., 44100 Hz, looped)` (`P:1353-1378`).
- The netvar block is `NETVARS.md` §1–§2 in full; the order is `ivar0` kill limit, `ivar1` time limit
  (minutes, `× TPS × 60` at `a2:2168`), `ivar7` starting-vehicle mask, `ivar12` MPI, and when MPI `ivar13 / 96 /
  97 / 98 / 99` CPU races, `ivar21 / 22` CPU skills (clamp 0..3), `ivar23 / 24` human / CPU force (0..3); then
  `ivar53` game type (4 = ST:Capture), `ivar54` capture seconds (clamp 30..120, stored `× TPS`), `ivar14 / 15`
  AI-kill points / kills, `ivar16` sniper mode, `ivar32` friendly fire, `ivar55` thug-pilot flag, `ivar118` spawn
  facing centre, `ivar119` restore-players (0..2), `ivar120` pilot invulnerability seconds (0..120, `× TPS`),
  `ivar121` morph-tank auto-deploy (0..3), `ivar17 / 18` human skills, and — only when `!IsTeamplayOn() || m_IsMPI`
  — the fifteen-slot loop `ivar35+k → m_AllyTeams[k+1]`, `ivar81+k → m_ThugFlag[k+1]` (`P:1483-1496`).
- Capture setup (`P:1610-1651`): for every path named `capturegoal%d` (≤ 16 goals), pick a `CaptureTarget`
  — `floor(GetRandomFloat(N))` clamped to `N` when `CaptureIsRandom`, else the next in order wrapping to 0 —
  `BuildObject` it on team 0 at the path, `SetObjectiveOn`, count it; `Error: Map has no Capture ODF's set!`
  / `Error: ODF '%s' doesn't exist!` to the console otherwise.

### SetupTeam (`D:1082-1284`, `P:897-1053`)

Runs once per commanding team. `DoTaunt(TAUNTS_GameStart)` for team 1 in MPI (`P:905`). Spawn point: in MPI
the path `Player_%d` (`m_PlayersSpawned + 1`) via `GetPathPoints`, else — or when that position is the null
vector — `GetSpawnpointForTeam` (`P:917-930`; decompile `a2:1227-1266`: the dot-product test exists only
inside the MPI branch, see `../STATUS.md` cross-check item 7). Records `m_TeamPos[3*Team..]`, builds the
recycler (`GetInitialRecyclerODF`, `svar5` list-2 → default `ivrecy_m`, `a2:841-849`) at `GetPositionNear(pos,
20, 40)` with `SetRandomHeadingAngle`, `SetScrap(Team, 40)` (`P:994`), the starting vehicles through
`StartingVehicleManager::CreateVehicles(Team, race, startingVariant, ivar7 mask, pos)` where `startingVariant`
comes from the recycler ODF's `[GameObjectClass] startingVariant` (following `classlabel`) or, failing that,
the text after the recycler name's last `_` (`P:960-991`), the pilot class for every player on the team
(`GetInitialPlayerPilotODF(race, team, false)`, `P:1002`), and each allied team's `m_TeamPos` at
`GetPositionNear(pos, 30, 60)` (`P:1006-1043`).

### SetupPlayer (`D:1290-1630`, `P:1058-1336`)

Teamplay: commanders (`!m_ThugFlag[Team]`) get `SetupTeam` and spawn next to their recycler while
`NumCommanders < m_NumSpawnPoints`; when the map has no base slot left the player is converted to a thug
(`UnAlly` from every team, `m_ThugFlag[Team] = true`) and cycled onto the next commander team
(`P:1080-1145`) — but is still built at the (unassigned) commander position, as shipped (`../STATUS.md`
row). Thugs spawn `AllyMinRadiusAway..AllyMaxRadiusAway` from their commander. Restore-players (`ivar119`,
`P:1223-1299`): when a snapshot exists for the player the saved ship ODF, pilot, weapons, ammo, health,
matrix / velocity / omega, scav scrap and deploy state are re-applied; camera pods (`vcamr_vsr`) always get the
plain respawn. Then `SetPilotClass(..., GetInitialPlayerPilotODF(race, team, false))`, facing the map centre when
`ivar118` (`P:1316-1327`); team 0 → `MakeInert` (`P:1332`).

### GetSpawnpointForTeam (`D:872-1006`, `P:700-828`)

`GetAllSpawnpoints(Team)` → prefer a spawn whose `DistanceToClosestEnemy > FriendlySpawnpointMinEnemyRange`
(400) and `DistanceToClosestAlly < FriendlySpawnpointMaxAllyRange` (100), else one with
`DistanceToClosestEnemy > RandomSpawnpointMinEnemyRange` (450), else any (random pick in each tier). FFA reads
`SameTeam` from the alliance query and `Ally` / `Enemy` from the team query — as shipped (`../STATUS.md` row).

### AddObject (`D:332-648`, `P:328-542`)

- `ivar117` at tick 0 → every `CLASS_SCRAP` is removed (`P:354`); out-of-bounds `CLASS_NAVBEACON` removed
  (`P:373`); MPI CPU objects → `AddToDispatch(h, 15.0, false, 0, false)` (`P:365`).
- `SetSkill` from the turret / non-turret skill of the owner's side (`CLASS_TURRETTANK` decides, `P:389-391`).
- `CLASS_SPAWNBUOY` counted at tick 0 → `m_NumSpawnPoints` (`P:394`).
- Recycler handles recorded (`CLASS_RECYCLER*`); `[FactoryClass] buildEmptyItem` (0) + `BuildItem%d` give the
  empty-ship ODF per team (`P:410-415`).
- Thug scavengers (`CLASS_SCAVENGER/H`) and thug pilots (`CLASS_PERSON`, switch timer `TPS × 15`) are listed
  for `ScavengerManagementCode`; empty ships get `SetMaxHealth(h, 0)` for `m_PilotInvunerability` turns;
  `CLASS_MORPHTANK` is auto-deployed with `SetCommand(h, CMD_CLOSE + ivar121)` when `ivar121 > 0` (`P:494`);
  `CLASS_COMMBUKNER` (sic) / `CLASS_COMMTOWER` take base slots (`P:522`).

### Execute (`D:2429-3019`, `P:2066-2481`)

Per tick: `UpdateGameTime`, `ExecuteRecyInvulnerability`, `ExecuteCheckIfGameOver`, `ExecuteST_Capture`
when `m_GameType == 4`; the per-player pass (camera pods `vcamr_vsr` → `SetPerceivedTeam 0` and un-ally,
`P:2121-2123`; the restore-players snapshot taken every tick for non-pod, non-`vsatview_vsr` ships,
`P:2154-2209`; pilot-invulnerability countdown); empty-ship invulnerability (`P:2232-2252`); the morph-tank
auto-deploy pass (`P:2256-2271`); `ScavengerManagementCode` when `!teamplay || MPI`; the **MPI CPU base spawn**
once (`P:2278-2436`): `MaxAI_Teams = m_NumSpawnPoints − numCommanders` (teamplay: `− 1`), capped at
`(MAX_TEAMS−1) − PlayerLimit` and 0..5; for CPU teams 11.. a recycler from `svar12` (list 2, default
`%cvrecycpu_vsr`) at path `Enemy_%d` unless one is pre-placed, `SetScrap 40`, `SetCPUAIPlan(team, team−5)`,
`SetTeamNameForStat("Computer Team %d")`, `startingVariant` as in SetupTeam, `CreateVehicles`, then the force
table (`P:2397-2424`, `x` = 0..4): always 1 × `%cvscav%s` and 2 × `%cvturr%s`; force ≥ 1 adds 2 × `%cbspir%s`
at paths `%dgtow1..2` (turret fallback) and 2 × `%cvsent%s` (scout fallback); force ≥ 2 adds 1 more sentry,
2 more gun towers at `%dgtow3..4` and 3 × `%cvtank%s` — all at `GetPositionNear(recycler, 30, 60)`; the
`ERROR: CPU %d (Team: %d) spawn skipped: Too many possible Humans (%d) for map Spawns (%d)…` message when the
slot count is exceeded. **MPI scrap trickle** (`P:2440-2478`): CPU teams (6..15) get `+1` scrap every `TPS × 3 /
× 2 / × 1 / ÷ 5` turns for force 0..3 and additionally every `TPS × {10, 9, 8, 7, 6} / 10` turns for 1..5
humans; human teams get `+1` every `TPS × 10 / × 8 / × 6 / × 4` turns for `m_HumanForce` 0..3 when it is
non-zero.

### UpdateGameTime (`D:2003-2074`, `P:1660-1730`)

`[mission] "Time Left %d:%02d[:%02d]\n"` when a time limit is set, else `"Mission Time %d:%02d[:%02d]"`, into
`SetTimerBox` (`P:1680-1727`); at zero remaining `NoteGameoverByTimelimit(); DoGameover(endDelta)` (`P:1704`).

### ExecuteRecyInvulnerability (`D:2078-2136`, `P:1733-1789`)

While `m_RecyInvulnerabilityTime > 0` (`ivar25` minutes `× 60 × TPS`, `a2:2158-2159`), every tick
`SetCurHealth(recycler, GetMaxHealth(recycler))` for each set-up team (slot-1 fallback through
`DLLUtils::IsRecycler`); `[strat] recyclersVulnerable / invulnerableExpiresMin / invulnerableExpiresSec`
messages every 60 s, every 15 s inside the last minute, colour `0xFFFF00FF` (`P:1773-1784`).

### ExecuteCheckIfGameOver (`D:2139-2426`, `P:1792-2064`)

A team is *functioning* when its recycler (vehicle or `GetObjectByTeamSlot(team, 1)`) is alive or its
factory (`slot 2`) exists, or an allied team's is; the respawn anchor `m_TeamPos` is re-noted when
`(m_ElapsedGameTime & 0xFF) == 0` (`P:1855`). Two or more functioning teams → return. None, after `TPS × 5`
→ `NoteGameoverByNoBases(); DoGameover(endDelta)` (`P:1937-1941`). One: MPI → `"All Human bases destroyed!"`
(`P:1924`) or `"Computer Team %d has won, destroyed all enemy bases."`; teamplay →
`NoteGameoverByLastTeamWithBase(WhichTeamGroup(i))`; FFA → `NoteGameoverByLastWithBase(player)` or, with
allies, the `[Network] HitLastWithBaseStr` message that is built but never shown (as shipped,
`P:2025-2028`); `+ScoreForWinning` (100) to every winning player (`P:2032, 2045, 2055`); `DoGameover(endDelta)`.
Taunts `TAUNTS_CPURecyDestroyed` / `TAUNTS_HumanRecyDestroyed` when a recycler goes (`P:1964-1966`).

### RespawnPilot (`D:3058-3154`, `P:2520-2617`)

Spawn at `m_TeamPos[team]` (else `GetSafestSpawnpoint`), set `m_SpawnedAtTime[team]`. Height: 200 default;
with a victim position, `d = dist2D(victim, spawn)`: `d < 100` → 35, else `clamp(30 + √d × 1.25, 40, 70 + 15
× CountAlliedPlayers(team))` (`P:2545-2569`); `RespawnAtLowAltitude` → 2.0 (`P:2574`); ± 32 m in X / Z, floor
+ 2.5 minimum, + 0..8 m (`P:2578-2593`). Pilot ODF `GetInitialPlayerPilotODF(race, team, true)`
(`P:2595`): the recycler ODF's `[GameObjectClass] PilotRespawnWithSniper` / `PilotRespawnWithOutSniper` by
`ivar16`, else `%cspilo` / `%csuser_m`, with the console error `ERROR: '%s' does not exist. Giving you pilot
DEFAULT ISDF! FIX IT!` (`P:613-657`). Pilot invulnerability: `SetMaxHealth(h, 0)` with the real maximum saved
for `m_PilotInvunerability` turns. `SetAsUser`, `AddPilotByHandle`, `SetRandomHeadingAngle`; team 0 →
`MakeInert`.

### DeadObject (`D:3158-3303`, `P:2620-2762`) — scoring

Return `DoEjectPilot` for team 0, powerups and `CLASS_TORPEDO` (`P:2629-2636`). `cost =
GetActualScrapCost(dead)`. Dead player: `AddDeaths +1` when died as a person (`P:2656-2658`). Dead AI:
`AddDeaths +1` under `ivar15`, `AddScore(dead, −floor(cost/20))` under `ivar14` unless Capture
(`P:2663-2666`). Killer on the same / allied team (not a suicide): `AddKills −1`, `AddScore −floor(cost/10)`
unless Capture; enemy: `AddKills +1`, `AddScore +floor(cost/10)` (`P:2677-2691`); for AI victims the same
under `ivar15` / `ivar14` (`P:2699-2709`). **Spawn kill**: killer ≠ victim, victim human, victim team 1..15,
`m_SpawnedAtTime[team] > 0`, and `elapsed − spawnedAt < TPS × 15` → `"Spawn kill by %s on %s\n"` and
`AddScore(killer, −500)` (`P:2717-2730`). Kill limit reached → `NoteGameoverByKillLimit; DoGameover(10.0)`
(`P:2734-2737`). Dead person → `RespawnPilot`. `ObjectKilled` / `ObjectSniped` / `PlayerEjected` act only in
world 0 and route into `DeadObject` (`PlayerEjected` as `DeadObject(h, h, false, !IsPlayer(h))`, `P:2774`).

### PreGetIn (`D:3424-3455`, `P:2818-2848`)

World 0 only. An allied AI pilot entering an empty craft is re-teamed to the craft (`SetTeamNum`) unless
`ivar55`; pilot invulnerability is released (`SetMaxHealth` restored); in MPI a craft on a team > 10 is
`AddToDispatch`ed (`P:2845`).

### ScavengerManagementCode (`D:3465-3604`, `P:2858-2920`)

Non-teamplay only. Thug scavengers: the held scrap is paid to the commander team up to its `GetMaxScrap`,
the remainder stays on the scavenger (`SetScavengerCurScrap`, `P:2874-2892`); a deployed thug scavenger is
re-teamed to the commander. Thug pilots are re-teamed to the allied non-thug team when their `SwitchTickTimer`
runs out (`P:2899-2918`).

### ExecuteST_Capture (`D:3607-3859`, `P:2924-3163`)

Goals at paths `capturegoal%d`. A dead goal is removed and the arrays shifted down (`P:2952-2965` — the rest
of that pass runs on the previous slot, as shipped). Messages `-- A Goal is being Captured by %s!`, `-- %s
Captured a Goal [from %s]!`, `-- %s has won! Captured All Goals!` / `Captured %d Goals!`, `-- Team %d has won!
…`, `-- No Capture Goals! Game will be over very soon!`; winner = `ivar0` score reached, or every goal held
by the team / its allies and none being captured (`P:3094-3110`); `+ScoreForWinning`, `NoteGameoverByScore` /
`NoteGameoverWithCustomMessage`, `DoGameover(endDelta)`. Objective files `mpobjective_stcap.otf` /
`mpobjective_st.otf` (`UpdateObjectives`).

### SetCPUAIPlan (`D:744-776`, `P:577-603`)

AIP `"%s%c%d_%d.aip"` = `CustomAIPNameBase` (`svar3` through `GetCheckedNetworkSvar`, default `"VSR_"`,
`a2:722-731`) + race + `(team − 5)` + `rand(0..2)`, falling back to `"%s%c%d_0.aip"`; `DoTaunt(TAUNTS_Random)`
on a later change (`P:600`).

## 4. `shared/` — the 1.3 files VSR kept

- `dllbase.cpp` (`D:1-402`): default virtuals; free-function trampolines through the `Mission` vtable;
  `SetWorld` keeps `Missions[3]` per lockstep world; `GetMisnAPI` (§1).
- `dllutils.cpp`: `IsRecycler(h)` accepts `CLASS_RECYCLER`, `CLASS_RECYCLERVEHICLE`, `CLASS_RECYCLERVEHICLEH`;
  `CountAlliedPlayers(team)` over teams 1-15; `GetCheckedNetworkSvar(listType, n)`.
- `startingvehicles.cpp`: `Init()` copies ≤ 32 entries of `NETLIST_StratStarting` into
  `s_StartingVehicleList[32][64]`; `CreateVehicles(Team, Race, Variant, Bitmask, Where)` builds, for each bit
  of the `ivar7` mask, entry[i] with `[0] ← race` and the `startingVariant` suffix (bare name when the suffixed
  ODF does not exist) at `GetPositionNear(Where, 30, 60)` + `SetBestGroup`.
- `taunts.cpp` (compiled into `VSRCore.lib`): `InitTaunts` reads `.trn [DLL] TauntODFFile` (default `"Taunts"`)
  → `<name>.odf [TauntCategories] Category0..N` → `<name><Category>.otf` lines into `TauntList[16]`;
  `DoTaunt`: 5 % chance of the random category, no immediate repeat, `"%.255s : %.*s\n"` with the CPU team
  name (`svar2`, default `"Team Computer"`), one taunt per `TPS × 20` turns, honours `options.play.taunts`.
  The taunt text lives in `.otf` files, not in the DLL.
- `trnallies.cpp`: `SetupTRNAllies(trn)` reads `[DefaultAllies] Entry1..N` = `"A_B"` → `Ally(A, B)`.
- `pupmgr.cpp` (deathmatch01 only) and `trace.cpp` are the 1.3 files unchanged (`../STATUS.md`).

## 5. `vsrcore/` — the helper framework

Pattern: `Add<X>Object(handle, …)` reads the ODF keys at `BZ1Helper::AddObject` time into a per-object
record; `Execute(bz1)` runs once per tick from `BZ1Helper::Execute` in this order (`P:bz1helper.cpp:1181-1196`):
Gravity → AmbientSound → Object (which drives Portal for teleport-capable objects) → Vehicle → Power → Powerup →
Building → ProductionClass → Undeploy → UtilityShip → Portal → Attacher → Scrap → Dispatch → MorphObject →
Carrier. Every helper's `PostLoad` converts handles and, on a resync, compares its list against the
`Temp<X>Buffer` the far end sent and logs the first differing member (`<X>LIST MISMATCH` /
`TEAMINFO MISMATCH: …`, ~70 strings) — the diagnostics the lockstep A/B reads.

**bz1helper** — ctor (`P:bz1helper.cpp:55-160`): allocates the 17 helpers; `.trn [World] WorldLetter`;
`[DLL] MPISwitchTeams%d` (`"A_B"`) when `ivar53 == 2 || ivar12 == 1 || options.instant.awarev13`; `Logging =
ivar115 || civar5`; `m_GameVersion = 20185` (`P:146`); `PatchData.txt [VersionInfo] Version` → `m_ModVersion`
(`P:148-149`); log file `VSR_<date>.log` (`P:152`); banner `PrintConsoleMessage("VSR BZCC DLL Created by
General BlackDragon")` (`P:156`); `IFace_Exec("vsrbasesetup.cfg")` when present (`P:157-158`). `Init`
(`P:1371-1505`): `.trn [Size] Height / MetersPerGrid / HeightGranularity / MinZ …` (4096 × 4096, −2048 when
absent), `[World] Gravity` (12.5), `[DLL] ReinforcementMinRadius 150 / ReinforcementMaxRadius 250 /
ReinforcementCliffTolerance 100 / MinScrapHeight −1e6 / MaxScrapHeight 1e6 / RestrictAllScrap false /
RespawnAtLowAltitude false / SpawnMinRadius 20 / SpawnMaxRadius 50` (`P:1397-1405`); netvars `ivar32` friendly
fire, `ivar60` max lives, **`ivar81` scrap multiplier**, `ivar5` game type, `ivar26` damage % (clamp 10..100,
`/ 10` → `m_DamageMultiplier`), `ivar89 / 90 / 91` day wreckers / site cam / skill levels, `ivar31` gravity
(`× 0.5 → SetGravity`) (`P:1451-1466`; `NETVARS.md` §1 for the `ivar81` / `89-91` collisions); `OffMapPos =
(−4000, floor, −4000)`; the **asset check** (`P:1488-1505`) — 24 files must exist (`MPIVSRCheck.odf,
STvsrcheck.odf, aip_VSR.autoreg, vsrbasesetup.cfg, vsra.txt, evlegs_vsr.odf, BZCundep1.odf, BZCundep2.odf,
ivcamr_vsr.odf, hbport_vsr.odf, evmine_vsr.odf, BZCNullCube.msh, apserv_vsr.odf, ivrbomb_vsr.inf,
vsr_bh_e_new_e6_0.aip, apvsrbldg.odf, iweapon_12svsr.odf, fweapon_12xvsr.odf, aplmg.inf, racename_e.txt,
evscout00_s.dds, evscav00_s.dds, evcons00_s.dds, ivscout12smartvsr.odf`) or `-- Aborting!` +
`NoteGameoverByNoBases(); DoGameover(10.0)` (network) / `FailMission(now + 10, "instantl.txt")`. `PreSnipe`:
`[SniperShellClass] TeamFilter` (0); network + friendly fire off + allied → `PRESNIPE_ONLYBULLETHIT`.
**`PreOrdnanceHit`** (`P:1247-1310`): when `IsNetworkOn() && m_GameType == 2 && m_DamageMultiplier > 1.0`,
deals the extra share `long(damage × mult) − damage` through `Damage()`, except for `[SprayBombClass]
ExplodeOnHit` / `HitExplodeTypes` ordnance. `AddObject` (`P:481-875`) keys: `BZCClasslabel, unitName2, HeightOffset,
AlignToTerrain, canDetect, scanTeamLimit, CanHQCPObjectify[Deployed], CanTeleport, CanBeIdleVictim (true),
AutoSetGroup, [BuildingClass] DeploySound / DeploySoundStartDelay / DeploySoundLoop / DeploySoundRepeatDelay,
PerceivedTeam (−1), DeleteOnLoad, [Silo|Extractor|Recycler]Class ScrapDropPoint (true), UseBZ2Pools,
deployClass / deployName, [MorphTankClass] HiddenWhenMorphed + MaxCloakEnergy / CloakEnergyCost / AddCloakEnergy,
[CraftClass] CanAICloak / CanRemoteControl / HuntIsResupply / AIEscortPriority, ShowSkill (when `maxAmmo >
0`) / ShowSkillTeamFilter (3)` (`P:535-875`); `"FIXME: AddObject Skipping Duplicate: %08x…"`. `BZ1Interface`
pushes `script.dll.pilotcost%d / base%dhull / basename%d / currpilots / maxpilots / pilotname / hull2 / ammo2
/ gauge / cloak / escape.active / repeataudio`. `[Start]` / `[Cheat]` / `[IdleDispatcher]` keys of the
`_config` ODF: `pilotAmount 0 / pilotDelay 15 / Difficulty 0 / UnitsService false / DoDLLDispatch true /
MaxPatrolUnits / MaxHuntUnits / MaxEscortUnits 0 / BuildingRepairChance 0.8 / BuildingRepairInterval 30 /
BuildingRepairHealthRatio 0.5 / BuildPodMinDelay 5 / BuildPodMaxDelay 60 / DayWreckerChance 0 /
DayWreckerInterval 30` (`P:1727-1747`).

**gravityhelper** (`P:gravityhelper.cpp:59-65, 131`): `.trn [Gravity] Gravity%d` (12.5), `OnPeriod%d`,
`TranPeriod%d` × 16 states; lerps `mapInfo.Gravity` through `SetGravity()` until within 0.001; the network
override is `ivar31` in `BZ1Helper::Init`. VSR's hover feel is ODF values on the engine integrator, not DLL
code.

**scraphelper** (`P:scraphelper.cpp:96-135`): `[ScrapClass] RestrictHeight` (false), `RestrictSlope` (0.0);
scrap outside `Min/MaxScrapHeight` or on too steep a slope is deleted; **when the list reaches 1024 pieces or
`TotalMapObjects > 2048` the oldest scrap is deleted** with `"WARNING: Too many objects on map! Deleting oldest
scrap!"` (the 2015 ancestor used 2048 / 3000).

**powerhelper** (`P:powerhelper.cpp:98-108`): `[BuildingClass] DoBettyLost` (true), `[PowerPlantClass]
powerRadius` else `powerRange` (default `ScaleDistance(100.0)`), `PowerClassMask / PowerClassMatch /
PowerClassProvides` (0); the Betty "power lost" voice.

**poweruphelper** (`P:poweruphelper.cpp:105-149`): `[HealthPowerupClass] healthUp` / `[ServicePowerupClass]
serviceUp`, `[AmmoPowerupClass] healthUp` (sic — the ammo value is read from `healthUp`) / `serviceUp`,
`localAmmoUp`, `[WeaponPowerupClass] weaponName`, `[PowerUpClass] soundPickup / soundReject / HitMask (−1) /
MaxVelocityOffset / MinVelocityOffset`; a random kick after spawn when the offsets are set.

**undeployhelper** (`P:undeployhelper.cpp:108-228`): triggered by the base-slot item `BZCundep*`;
`[DeployableClass] | [TrackedDeployableClass] timeUndeploy` (5.0, floored at 0); target ODF `[GameObjectClass]
UndeployClass`, else the ODF with `[1] ← 'v'`; `"-- Can't Undeploy, No Free Groups."`; scrap restored when the
object was a recycler vehicle.

**vehiclehelper** (`P:vehiclehelper.cpp`, keys read in `BZ1Helper::AddObject`): `CanRemoteControl` (a player
takes over the AI on `CMD_HUNT`), `ShowSkill` / `ShowSkillTeamFilter`, the cloak energy model (`CloakCurEnergy
−= CloakEnergyCost / TPS` while cloaked, `+= AddCloakEnergy / TPS` otherwise; forced decloak at 0;
`[GameObjectClass] CloakFailSound`, default `cloakfail.wav`), the `CloakGauge` HUD variable; `HuntIsResupply`,
`CanBeIdleVictim`, `HiddenWhenMorphed`.

**utilityshiphelper** (`P:utilityshiphelper.cpp:96-147, 236-244`): `[CraftClass] DoDLLDispatch` (true);
`[ScavengerClass|ScavengerHClass] doDrop (false) / doDropRecycler / doDropExtractor / doDropSilo (true)`;
`[ServiceTruck|ServiceTruckH] ServiceAllies / ServiceSTs (false) / serviceCraft / serviceBuildings (true) /
servicePilots / serviceOther (false)` → service bitmask; escort priorities; the scavenger scrap gauge;
**network: `AddScrap(GetCommanderTeam(team), (prev − cur) × m_ScrapMultiplier)` whenever a scavenger's held scrap
drops** (`P:236-244`) — the `ivar81` scrap multiplier in action.

**productionclasshelper** (`P:productionclasshelper.cpp:30-116, 251-390`): base-slot names from
`[GameObjectClass] shellName` else Recycler / Factory / Armory / Constructor / Satellite (slots 1-9, 5-8 repeat
1-4); `ScrapHold` → `base%dshold` at `OffMapPos`; `UseBZ1Limits / UseBZ1Pilots / NoPlayerPilot / UseBZ2Pools /
ShowPilotCosts` (all false); `buildItem1..10` pilot / scrap costs onto the command panel (`CommandPanel.Command0.
Item.Cost.PilotCost*`); animations `build` + `BZCLoop`; `UndeployClass`; `[ArmoryClass] reloadMsg` and the
per-classlabel armory sounds (`ammopack / repairkit / servicepod / wpnpower / camerapod / daywrecker`).

**dispatchhelper** (`P:dispatchhelper.cpp:99-302, 1302`): `[CraftClass] DoDLLDispatch` (true), `BZCClasslabel`
`nodispatch` opt-out; per difficulty from `<odf>_config.odf` `Easy|Medium|Hard|ExtremeWeaponSlot%d`:
`AIHuntChance / AIPatrolChance / AISniperChance / AIEscortChance / AIServiceChance` (0.0), `AIRepairHealthRatio`
(0.15); `[DeployableClass] timeDeploy` (5.0); `[CraftClass] CanAIFlee`, `AIFleeHealthRatio` (0.75), `CanAIRepair`
(when `maxHealth`), `CanAIReload` (when `maxAmmo`), `CanAICloak`, `RetargetOnStrafe` (false, read by
`PreOrdnanceHit`); `[MorphObjectClass] MorphIsAssault` (true); `ServiceTimer = 10 s`; dispatch types
hunter / patrol / escort / turret / minelayer / service; log strings `"Hunt Task Starting"`, `"Escort Target
lost, Going Bezerk!"`, `"Minelayer Shot, Mining"`, `"Turret Shot, Deploying"`, `"AI Attempting to Cloak unit,
Chance: %f"`. At ~1,880 decompiled lines the largest helper; ported last (tier 3).

**aiweaponhelper** (`P:aiweaponhelper.cpp:64-111`): per hardpoint 5 → 1 from `Easy|Medium|Hard|ExtremeWeaponSlot%d`:
`WeaponName1..16, WeaponMask1..16, MinWeaponMask (1), SkipRequirements (false), HardpointOverride (false)`;
`[WeaponPowerupClass] weaponName`, `[GameObjectClass] scrapCost` debited with `AddScrap(team, −cost)` unless
`SkipRequirements`; `GiveWeapon`.

**buildinghelper** (`P:buildinghelper.cpp:115-186`): `RequirePowerMask (0)`, `GameObjectClassPowerMask / Match /
Provides (0)`, `CollisionRadius (0)`, `CanCollide (false)`, `ownsTerrain (true)`, `CanAcceptPowerups (false)`,
`AcceptPowerupMask`, `[BuildingClass] SizeRatioX / SizeRatioZ (1)`, `buildSupport ('A')`, `upgradeName`,
`APCRefillPoint`, `RecyclePoint`, `[SupplyDepotClass] healthRate / ammoRate / localAmmoRate / supplyRate (0) /
serviceCraft (true)`, `IsAnimated (true)` + `animCount` / `animName%d` (`BZCloop`), `[TurretCraftClass |
PoweredBuildingClass] PoweredByTaps / autoBuildTaps (true)`, `canDemolish (true)`.

**attacherhelper** (`P:attacherhelper.cpp:82-177, 251-271`): `[GameObjectClass] AttachedObject1..8`,
`AttachedIndependent%d (true) / AttachedCoordinateFire%d (false) / AttachedDeployState%d (−1) / AttachedPDSMode%d
(false) / AttachedWeaponSymmetryMask%d ("00000") / AttachedOffset%d / AttachedRotation%d` (degrees → radians),
`[CraftClass] RangeScan` must be 0 on a tap; the Cerberus tail animation (`CerbTailIdle / Left / Right`,
`CerbTailFireAngle` 0.60); `"ERROR: ODF '%s', '%s' attempted to attach itself, preventing infinite loop."`.

**carrierhelper** (`P:carrierhelper.cpp:160-214`): `[CarrierClass] controlRange (0) / defendRange (=
controlRange) / recallRange (50) / droneIdleTime (120) / maxDrones (0) / minAttackForce (0) / repairRange (100)
/ healthRepairAmount / ammoRepairAmount (0) / serviceAllies (false)`; `[DroneClass] RandomTargetRange (0) /
canSwitchCarrier (true)`; the carrier's `[DispenserClass] objectClass` slot and its `localAmmo`.

**morphobjecthelper** (`P:morphobjecthelper.cpp:102-256, 406-456`): `[CraftClass] CanAICloak`, `MaxCloakEnergy /
CloakEnergyCost / AddCloakEnergy`, `[MorphObjectClass] SwitchODF / CanFireWhenSwitched (true) / SwitchAllWeapons
(true)`, the toggle object by `BZCClasslabel "MorphObjectToggle"`, weapon swap through `[WeaponClass] altName`,
`[DispenserClass] objectClass`.

**portalhelper** (`P:portalhelper.cpp:131-291`): `[TeleportalClass] PortalEffect / InEffect / OutEffect / OnEffect
/ VehInEffect / VehOutEffect (0) / FxOnVehicle (false) / soundActivate / soundDeactivate / TeleporterChannel (0) /
ShowChannel (true) / CanEnter / CanExit (true) / MatchType (0) / MatchTypeUsesChannels (true) / ContinuousFx
(false) / ContinuousFxRange (0) / TeleportColorFade / TeleportFilter (15; 0 → 31) / ExitVelocity (0) /
ExitForwardOnly (false) / ExitKickAI (false) / ExitUsesCenter (true) / EnterGotoIsExit (false) / EnterRange (10)
/ DestinationMinRange / DestinationMaxRange (0) / TeleportTeamFilter (7) / DestinationTeamFilter (3) /
AllowOnlyTwo (false)`; `[TeleportalSwitchClass] PortalChannel (−1)`; `[TeleportalMineClass] TooFarSound /
TooCloseSound`; UI `"Channel %d"`.

**objecthelper**: the generic per-object record; routes `CanTeleport` objects to
`PortalHelper::ExecuteObject`. **ambientsoundhelper** (`P:ambientsoundhelper.cpp:63-85`): `.trn [Audio]
AmbientSound%d / Position%d / IsMusic%d / MinDelay%d / MaxDelay%d / BasePan%d / PanVariance%d / Rate%d (44100)`
× 32. **mathutils**: matrix / quaternion helpers, `GetRandomInt / GetRandomFloat`. **bzcscriptutils**: the
two-file `GetODF*` getters that follow `classlabel` inheritance, `OpenODF2` with the name / blacklist maps,
`FormatConsoleMessage / FormatLogMessage / OpenLogFile`, the `Is{Recycler, Factory, Armory, Constructor,
ServiceTruck, Building, PoweredBuilding, Craft, Weapon, Misc}` class tests, `GetEngageRange`, `GetMinFireAmmo`,
`GetOrdnanceDamageDealt` (armor class `N/L/H`, shield class `A/D/S`), `GiveWeapon`, `ReplaceWeapons`,
`GetBuildItem`, `GetPilotCost / GetScrapCost / GetScrapValue`, `GetWorldVariantODF`, `GetConfigODF`
(`<odf>_config.odf`, then `<classlabel>_config.odf`), `GetClasslabelString`, `TeamFilterCheck`,
`GetWindingNumber`, `Hash`.

## 6. `luamission/` in one paragraph

`LuaMission` loads `<missionfile>.lua` (`LoadFile` + `luaL_loadbufferx`; `Lua script: '%s' loaded` / `No Lua
script: '%s'`), nils `io` and `os`, installs the `Handle` / `Vector` / `Matrix` / `Quaternion` metatables,
`IdentityMatrix`, nine enum tables (`AiCommand, DMSubGameTypes, EjectKillRetCodes, PreGetInReturnValues,
PrePickupPowerupReturnValues, PreSnipeReturnValues, RandomizeTypes, TauntTypes, TeamRelationshipTypes`) and
`LuaMissionVersion = 186`, and calls the script's globals `InitialSetup, Start, Load, Save, PreOrdnanceHit,
PreGetIn, PreSnipe, PrePickupPowerup, PostTargetChangedCallback, CreateObject, AddObject, DeleteObject,
AddPlayer, DeletePlayer, PlayerEjected, ObjectKilled, ObjectSniped, GetNextRandomVehicleODF, Update, PostRun,
ProcessCommand, SetRandomSeed, PreTeleport` (`Lua script <X> error: invalid return param.` on a bad return).
`luabindings.cpp` registers 485 functions (`sLuaScriptUtils`, read verbatim from `.rdata`; 17 Lua names differ
from the C++ symbol, e.g. `GetCfg` → `GetObjInfo_CFG`, `IsValid` → `IsAround`). The VSR-only bindings beyond
stock LuaMission include `DoTaunt, SetTauntCPUName, GetRecyclerHandle / GetFactoryHandle / GetArmoryHandle,
GetTPS, IsInsideArea, GetWindingNumber, DoesPathExist, AddToDispatch, ReplaceWeapons, GetTransform2` and the
twelve portal bindings (`SetPortalChannel … ClearPortalDest`). Full list and the `// shipped:` corrections:
`../STATUS.md` rows `luamission.cpp` / `luabindings.cpp`.

## 7. GBD's documents — which file says what (`original/docs/VSR Documents/`)

| File | What is in it |
|---|---|
| `Feared_1_Comments.txt` (58 KB) | **the master changelog**, Release 1 (2018-03-09) → Release 126; "VSR is completely converted as of Release 53, thanks to General BlackDragon" |
| `VSR changes since BZCC.txt` | release highlights: R13 omegaKick removed from Chain Gun / Pummel; R40 MAG 30 → 20 scrap; **R55 ST: Capture mode**; R56 sniper option default off; R64 sniper rifle requires Relay Bunker / Antenna Mound / Eyes of Xyr; R83 camera pods 500 m radar; R95 turrets / GTs use 1.3 aiming; R105 camera pods can bail out; R113 shibbit damage 100 / 75 / 50 % by armour |
| `VSR BZCC Changelog GBD.txt` | R53: re-enabled the VSR DLLs / MPI / ST extra options; "AI start on Team 6 and go up to 15" |
| `Developer Notes/vsr-netvars.txt` (11.7 KB) | GBD's ivar / svar spec — the `N:` tier of `NETVARS.md` (with its known slips) |
| `Developer Notes/VSR Changelog - GBD 5.1.txt` (20 KB) | the 1.3-era "DLL things": FFA alliance code, `PilotRespawnWithSniper` / `WithOutSniper`, `base#hull` shell vars, Remote Satellite `BZCClasslabel = "comm"`, Portal `"portal"`, `DLLPatrolship` / `DLLMinelayer` / `DLLHuntUnit`, `DLLAnchor`, the idle-turret dispatcher |
| `Developer Notes/PROJECT NOTES VSR 4.3.txt` / `4.4.txt` | 2013 development notes: "DLL Updates by General Blackdragon", `< 6.4` / `>= 6.4` DLL builds, the recycler test matrix Classic / Plus / Experimental × ISDF / Scion / Hadean / IC |
| `Developer Notes/Darkfox Hadean Changes.txt` (22 KB) | the Hadean faction balance pass |
| `Developer Notes/VSR AIP Pathpoints.txt` / `VSR AIP Provides.txt` | what an AIP may reference on a VSR map |
| `Old Documents/Changes.devtxt`, `VSR 6.0 Changes (1.3).txt` | the 1.3-era change lists |
| `Old Documents/vsr-asset-credits.txt` | Project Lead Zero Angel; Scripting / Programming Vearie + General Blackdragon; **VSR DLL: General Blackdragon**; BZCC conversion Feared_1 |
| `VSR Map Info/Map inf vars.txt` (18 KB) | the `.inf` keys a VSR map sets — `svar7` picks the lobby page (`original/shell/`) |
| `VSR Map Info/CapturePointsPerMap.txt`, `Enable ST Capture.txt`, `FFA Path Instructions.txt`, `Game Mode Map Paths.txt`, `IA Path Instructions.txt`, `VSR Prefixes.txt` | the path names each mode expects (`Player_%d`, `Enemy_%d`, `capturegoal%d`, `%dgtow%d`, `edge_path`) and the ODF prefix scheme |
| `Cerberi Changelog.txt`, `Note on Updated Assets.txt`, `ODF Inheritance.devtxt`, `VSRTopSecretModelChangelog.txt`, `The Vearidon's Map Pack BZCC Conversion Readme.txt` | asset-side notes |

`original/docs/workshop-item/1325933293.ini` is the Steam Workshop item: `modName = "Vet Strat Recycler
Variant"`, `modType = "config"`, `assetDependencies` = the eight packs of `../DEPENDENCIES.md` D9.

## 8. Lessons from the port (read before changing the method)

- **LTCG folds per DLL.** The four DLLs share `shared/` and `vsrcore/` sources, but each link constant-folds
  and dead-strips independently: `InitTaunts`'s `pCPUTeamName` branch is absent from the Strategy02 decompile
  and present in Instant's; `BuildStartingVehicle`'s `SetGroup` branch is absent from the binary because every
  caller passes `aGrp = -1`. A branch missing from one decompile is not evidence it was missing from the source
  — check the other three builds (`tools/diff_decompile.py`) before deciding. A cross-build diff of all 324
  shared functions found no other literal-level difference.
- **The decompile loses register-passed and folded arguments.** `ecx` / `edx` fastcall arguments and arguments
  folded to constants come out as `unaff_*` temporaries or vanish; `dumpbin /DISASM` on the address range
  settled every such case (the Lua binding argument indices, `AddToDispatch`'s arguments, several helper
  defaults). Record the address range in the file's `// PROVENANCE:` line.
- **Class-hash compares look like float literals** in the decompile (`fVar5 == 5.29286e-36`); the tables
  `Hash_GOClass[]` / `ClassLabelBuildings[]` in `globals.tsv` resolve them.
- **`Strategy02::Execute` does not decompile** in Ghidra 11.4 / 12.1 / 12.2; the received text is the oracle
  and `dumpbin` the arbiter.
- **The PDB's LTCG database keeps stale type generations.** Always take the highest type index for a class
  (`tools/pdb_types.py`); `operator new(0xECA4)` in `BuildMission` is the check.
- **GBD's two Lua artifacts differ in kind.** `Lua-Stock-Missions` is a rewrite (names and comments; no
  statement-level trust); `vsr_dll_lua` lines 776-3652 are his C++ under a regex and can be diffed as text
  (`../STATUS.md` "GBD-text cross-check") — but it is seven months older than the binary.
- **Shipped bugs are kept and marked `// shipped:`** (`CLASS_COMMBUKNER`, the FFA spawnpoint query swap, the
  no-free-base-slot fallback, the `HitLastWithBaseStr` message that is never shown, the ST:Capture `x--` pass).
  Parity is with the binary, not with what GBD meant.
