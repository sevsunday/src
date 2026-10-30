# NETVARS — what the VSR DLLs read from the lobby, with evidence

Every `network.session.ivarN` / `svarN` the VSR mission DLLs consume, where that is proven, and how
the VSR shell writes it. Trust tiers per `../PROVENANCE.md`:
**A** GBD's own documents / configs · **B** the PDB-symbolized decompiles (Strategy02 regenerated with
Ghidra 12.2 on 2026-10-28, roster identical to the received copy —
`reference/decompiled/strategy02-ghidra12.2/DIFF_vs_strategy02-attempt2.md`; LuaMission / Instant /
deathmatch01 under `reference/decompiled/<dll>-ghidra12.2/`) · **A′** the 1.3 source pack.
Every read below was re-checked against the ported source (`P:<file>:<line>` into `source/missions/`)
once the port was complete; the deathmatch01 rows (§2a) and the Instant note (§5) were added then.
The port must reproduce every behaviour below exactly as GBD built it, including the netvar collisions in
§1; they are documented so nobody "fixes" them before parity is proven.

Sources and how they are cited:

| Tag | Source | Tier |
|---|---|---|
| `N:<line>` | `original/docs/VSR Documents/Developer Notes/vsr-netvars.txt` (GBD's spec; 287 lines) | A |
| `S:<cfg>:<line>` | `Upload/VSR/Config/Shell/bzshell_multi_*.cfg` in GBD's Workshop repository at `58a5f56` (what the lobby UI binds; not copied here — see `reference/manifest/REPO_REFS.txt`) | A |
| `D:<file> <orig lines>` (+ `a2:<line>` = line in `reference/decompiled/strategy02-attempt2/src/missions/.../<file>.decomp.c`) | the decompile; original source line ranges come from the PDB (`reference/manifest/strategy02-attempt2/functions.tsv`) and are stable across regenerations | B |
| `13:vars.txt` | `reference/ancestor-1.3/Source/network/vars.txt` | A′ |
| `P:<file>:<line>` | the ported source under `source/missions/{strategy02,deathmatch01,vsrcore,shared}/` | B |

Scope column: **ST** Strategy02 · **MPI** Strategy02 in one-team mode (`ivar12 = 1`) · **FFA**
Strategy02 with teamplay off · **DM** deathmatch01 · **All** read by `BZ1Helper` (every DLL) ·
**eng** read by the engine, not the DLL.

## 1. The two discrepancies, resolved from the decompile

**Ally slots.** `Strategy02::Init` (`D:strategy02.cpp 1634-1999`, loop at `a2:2022-2042`) runs only when
`!IsTeamplayOn() || m_IsMPI`. Its counter `iVar7` goes 0x51 → 0x5F (81 → 95, 15 iterations). Each
iteration reads **`ivar(iVar7 − 0x2E)` = `ivar35..49` into `m_AllyTeams[1..15]`** (a value < 1 defaults
to the slot's own index, `iVar7 − 0x50`) and **`ivar(iVar7)` = `ivar81..95`, clamped 0..1, into
`m_ThugFlag[1..15]`** (the byte store lands at `BuildEmpty + 0x30 + iVar7` = `0xE7D5..0xE7E3`;
`m_ThugFlag[16]` sits at `0xE7D4` in the PDB layout). The FFA shell agrees: `S:bzshell_multi_client_VSRffa2.cfg:15-29`
sets `SetIntegerRange("network.session.ivar35..49", 1, 15)` and binds the per-slot team sliders to
`ivar35..49` and the Commander/Thug buttons to `ivar81..94`. **`N:132` ("ivar23, 60, and 67-80: FFA
Alliance setting teams") does not describe what the shipped DLL reads;** the DLL reads 35–49.

**`ivar81` double read.** In a network game `BZ1Helper::Init` (`D:bz1helper.cpp 2601-2853`,
`a2:2763-2792`) does `m_ScrapMultiplier = GetVarItemInt("network.session.ivar81")` with no clamp
(single-player path `a2:2758-2759` forces `m_DamageMultiplier = 1.0`, `m_ScrapMultiplier = 1`).
`Strategy02::Init` then reads the same `ivar81` as slot 1's thug flag. The only consumer of
`m_ScrapMultiplier` is `UtilityShipHelper::Execute` (`D:utilityshiphelper.cpp 215-318`, `a2:303-312`):
when `IsNetworkOn()` and a scavenger's held scrap dropped since last tick,
`AddScrap(GetCommanderTeam(team), Δheld × m_ScrapMultiplier)`. Consequences:

- Team strat (`bzshell_multi_VSRst.cfg` and every `*st*` page never bind `ivar81`): the slot stays 0,
  `m_ScrapMultiplier = 0`, the credit path is **inert** — scavenger income is the engine's native deposit only.
- FFA / MPI pages (`VSRffa2`, `VSRffampi4`): `ivar81` is slot 1's Commander (0) / Thug (1) toggle, so the
  "scrap multiplier" equals *whether slot 1 is a thug*. With a thug in slot 1, every scavenger deposit in the
  game is credited a second time, to `GetCommanderTeam()` of the scavenger's team.

This is a latent BZ1Helper-era netvar (a scrap multiplier in GBD's Battlezone Classic framework) that
VSR's FFA layout re-used. `ivar89 / 90 / 91` collide the same way (daywreckers / site camera / skill levels
in `BZ1Helper::Init` vs slot 9–11 thug flags in the FFA pages).

**A shell slip, recorded for completeness:** `S:bzshell_multi_client_VSRffa2.cfg:511` binds slot 5's
`Team: %d` *label* to `ivar70` while the slot's slider (`:523`) writes `ivar39`. Display-only; the DLL
never reads `ivar70`.

## 2. ivars

| Var | Meaning | Scope | Read by (D) | Shell (S) | N | Notes |
|---|---|---|---|---|---|---|
|  0 | kill limit (0 = none) | ST/DM | `Strategy02::Init` → `m_KillLimit` (`a2:1902`) | every page | `N:3` | game over by kill limit in `DeadObject` (`a2:3779-3781`)  |
|  1 | time limit, minutes (0 = none) | ST/DM | `m_TotalGameTime` (`a2:1904`), `× TPS × 60` (`a2:2168`) | every page | `N:5` | `[mission] Time Left …` via `SetTimerBox`  |
|  2 | player limit | ST | MPI spawn loop reads it as the CPU-team count (`a2:3232`) | `VSRst*` | `N:7` |  |
|  3 | teamplay | eng | `IsTeamplayOn()` | `VSRffa/ffacap/ffampi` | `N:9` | gates the FFA loop  |
|  4 | selectable-vehicle bitfield | eng | — | `VSRst/ffa/…` | `N:11` |  |
|  5 | game type 0 all / 1 DM / 2 strat | All | `BZ1Helper::Init` → `m_GameType` (`a2:2769`) | — | `N:13-16` | `m_GameType == 2` gates the `PreOrdnanceHit` damage injection (`D:bz1helper.cpp`, `a2:3395-3498`)  |
|  7 | starting-force mask | ST/MPI | `m_StartingVehiclesMask` (`a2:1906`) → `StartingVehicleManager::CreateVehicles` (`P:strategy02.cpp:1389`) | `VSRst2.cfg:251-266` writes 0 / 3 / 219 / −1 | `N:20-22` | 219 = `0b11011011` from the VSR "Starting Force" page **DM reads the same slot as the game subtype** (§2a). |
|  9 | unit limit / DM laps / bots | eng/DM | DM: `m_TotalRaceLaps` (race) / `m_MaxAIUnits` (otherwise, ≤ 256) (`P:deathmatch01.cpp:1025,1044`) | every page (labelled near `PilotLife`) | `N:30-31` |  |
|  12 | 0 two teams / 1 one team = MPI | ST | `m_IsMPI` (`a2:1908`); `BZ1Helper` ctor `MPISwitchTeams` when `ivar53 == 2 \|\| ivar12 == 1 \|\| options.instant.awarev13` | `VSRst/ffa` | `N:40` |  |
|  13 | MPI CPU race #1 (ASCII) / DM spawn-kill secs | MPI/DM | `m_AIRace[0]` (`a2:1912`) (`P:strategy02.cpp:1396`); DM `m_MaxSpawnKillTime = v × TPS` (`P:deathmatch01.cpp:1033`) | `VSRffampi3.cfg` | `N:42-49` | Strategy02's own spawn-kill window is the constant 15 s (`P:strategy02.cpp:26`), not this ivar. |
|  14 | points for AI kill | ST | `m_PointsForAIKill` (`a2:1964`) (`P:strategy02.cpp:1436`) | every page (`PointsForKill`) | `N:51` | VSR's `deathmatch01` does not read it (the 1.3 spec says DM does). |
|  15 | +1 kill for AI kill | ST | `m_KillForAIKill` (`a2:1966`) (`P:strategy02.cpp:1437`) | every page (`KillForKill`) | `N:54` | as above. |
|  16 | respawn with sniper / DM humans-vs-bots | ST/DM | `m_RespawnWithSniper` (`a2:1968`) → `GetInitialPlayerPilotODF` reads `[GameObjectClass] PilotRespawnWithSniper / PilotRespawnWithOutSniper` from the recycler ODF; DM `m_HumansVsBots` (`P:deathmatch01.cpp:1066`, allies teams 1–11 against the bots) | every page (`SniperRespawn`) | `N:57` | VSR R55: 0 off / 1 start / 2 respawn (`VSR changes since BZCC.txt`)  |
|  17 | human turret AI skill 0..3 | ST | `a2:2000-2007` | every page | `N:61` |  |
|  18 | human other-unit AI skill 0..3 | ST | `a2:2008-2015` | every page | `N:63` |  |
|  21 | CPU turret skill (MPI) | MPI | `a2:1922-1929` | `*mpi*` pages | `N:69` |  |
|  22 | CPU other skill (MPI) / DM bot skill | MPI/DM | `a2:1930-1937` (`P:strategy02.cpp:1408`); DM `m_AIUnitSkill` 0..4, else 3 (`P:deathmatch01.cpp:1059`) | `*mpi*` pages | `N:71` |  |
|  23 | MPI human scrap cheat 0..3 / DM rabbit mode | MPI/DM | `m_HumanForce` (`a2:1938-1945`) → human trickle `TPS × {10,8,6,4}` turns (`a2:3454-3523`); DM `m_RabbitMode` (`P:deathmatch01.cpp:1085`) | `*mpi*` pages | `N:73,80` (`N:77` "FFA alliances" is not read) |  |
|  24 | MPI CPU scrap cheat 0..3 (default 2) | MPI | `m_CPUForce` (`a2:1946-1953`) → CPU starting units + trickle `TPS × 3 / 2 / 1 / ÷5` | `*mpi*` pages | `N:82` |  |
|  25 | recycler invulnerability, minutes / DM ship-only | ST/DM | unnamed `GetVarItemInt` (`a2:2158-2159`) → `m_RecyInvulnerabilityTime = TPS × 60 × min`; `ExecuteRecyInvulnerability` (`a2:2300-2365`) pins recycler health, `[strat] recyclersVulnerable / invulnerableExpiresMin / Sec`; DM `m_ShipOnlyMode` (`P:deathmatch01.cpp:1088`) | every `*st*`/`*ffa*` page (`RecyProtect`) | `N:89` | the decompile shows the read at the `m_RecyInvulnerabilityTime` assignment; the literal `"ivar25"` is in `globals.tsv` The port names the member the decompile left unnamed (`P:strategy02.cpp:1579`). |
|  26 | damage %, `/10` | All (network) | `BZ1Helper::Init` clamp 10..100 → `m_DamageMultiplier = v / 10` (`a2:2770-2780`) | `addm` pages only | `N:91` | `PreOrdnanceHit` adds `GetOrdnanceDamageDealt × (mult − 1)` when `m_GameType == 2 && mult > 1`  |
|  28 | AI pilot lifespan s | eng | — | every page (`SniperRespawn` block, range 0..99999) | `N:102-107` | engine-side  |
|  29 | TLI disable | eng | — | every page | `N:109` |  |
|  30 | weapon linking | eng | — | every page | `N:113` |  |
|  31 | gravity ×2 | All (network) | `BZ1Helper::Init`: `v × 0.5 → mapInfo.Gravity, SetGravity()` if > 0 (`a2:2787-2792`) (`P:bz1helper.cpp:1466`); DM also reads it itself into `m_Gravity` and calls `SetGravity(v × 0.5)` (25 when not networked) (`P:deathmatch01.cpp:1026-1029,1054`) | `addm` pages | `N:115` |  |
|  32 | friendly fire | All | `Strategy02::Init` `m_bIsFriendlyFireOn` (`a2:1970`); `BZ1Helper::Init` `m_IsFriendlyFireOn` (`a2:2763`) | every page | `N:118` | `PreSnipe`: network + FF off + allied → `PRESNIPE_ONLYBULLETHIT`  |
|  35–49 | per-slot ally team (1..15) | FFA/MPI | `m_AllyTeams[1..15]` (`a2:2024-2029`) (`P:strategy02.cpp:1483-1488`, `"network.session.ivar%d"` with `34 + i`) | `VSRffa2:15-29`, `VSRffampi4` | **not in N** (`N:132` says 23/60/67-80) | §1 **`ivar35` is the stock score limit** (`13:vars.txt:147`), which VSR's `deathmatch01` still reads as `m_ScoreLimit` (`P:deathmatch01.cpp:1027`); no conflict inside one DLL. |
|  53 | ST game type: 0 normal / 4 ST:Capture | ST | `m_GameType` (`a2:1955`) | `VSRst.cfg:894` `Cmd("ivar53 4")` on the Capture-mode button | `N:125` | `BZ1Helper` ctor also tests `ivar53 == 2`  |
|  54 | capture seconds 30..120 | ST:Cap | `m_CaptureTime = TPS × clamp(v,30,120)` (`a2:1957-1963`) | `VSRstcap:14` range 0..120, `:799` | — | shell default 60  |
|  55 | allied AI pilot keeps its team | ST | `m_SetThugPilotFlag` (`a2:1972`) → `PreGetIn` | — | — |  |
|  60 | max lives | All (network) | `BZ1Helper::Init` `m_MaxLives` (`a2:2765`) | — | `N:132` (as "FFA ally") | the DLL reads it as max lives, not as an ally slot  |
|  81 | scrap multiplier (BZ1Helper) **and** slot-1 thug flag | All / FFA | `m_ScrapMultiplier` (`a2:2767`); `m_ThugFlag[1]` (`a2:2030-2039`) | `VSRffa2`, `VSRffampi4` | `N:134` | §1  |
|  82–95 | per-slot thug flag 0/1 | FFA/MPI | `m_ThugFlag[2..15]` (`a2:2030-2039`) (`P:strategy02.cpp:1490-1496`, `80 + i`, clamped 0..1) | `VSRffa2`, `VSRffampi4` (to 94 / 90) | `N:134` |  |
|  89 | CPU uses daywreckers | All (network) | `m_CPUUseDayWreckers` (`a2:2781`) | `VSRffa2:…` (as slot-9 thug!) | — | **overlap**: in FFA pages `ivar89..94` are slot 9..14 thug flags; `BZ1Helper` reads 89/90/91 as daywrecker / site-cam / skill-level toggles. Same class of collision as `ivar81`.  |
|  90 | site camera in MP | All (network) | `m_EnableSiteCamMP` (`a2:2783`) | (slot-10 thug in FFA) | — | overlap as above  |
|  91 | use skill levels | All (network) | `m_UseSkillLevels` (`a2:2785`) | (slot-11 thug in FFA) | — | overlap as above  |
|  96–104 | MPI CPU race #2..#10 (ASCII) | MPI | `m_AIRace[1..4]` from 96..99 (`a2:1914-1921`) | `VSRffampi3` binds 96..104 | `N:136` | the DLL only reads 96..99 (5 CPU teams)  |
|  115 | DLL logging | All | `BZ1Helper` ctor `Logging = ivar115 \|\| civar5` (`a2:301-309`) | — | — | `VSR_<timestamp>.log`  |
|  117 | delete loose scrap at start | ST | `Strategy02::AddObject`/tick 0: every `CLASS_SCRAP` removed (`a2:480-483`) | every `*st*`/`*ffa*` page (`StartingLoose`) | — | a lobby with it on has `income_loose = 0` by construction  |
|  118 | spawn facing centre | ST | `m_SpawnFacingCenter` (`a2:1974`) | — | `N:138` |  |
|  119 | restore player on rejoin: 1 by name / 2 by slot | ST | `m_RestorePlayers` clamp 0..2 (`a2:1976-1983`); snapshot in `Execute` (`a2:…`), restore in `SetupPlayer` | every `*st*` page (`SmartRejoinNick/Slot`) | `N:140` |  |
|  120 | pilot respawn invulnerability s (≤120) | ST | `m_PilotInvunerability = TPS × clamp(v,0,120)` (`a2:1984-1991`) | every page, range 0..120 (`PilotProtect`) | `N:142` |  |
|  121 | morph-tank auto-deploy 0..3 | ST | `m_MorphTankAutoDeployType` (`a2:1992-1999`) → `SetCommand(h, 0x2E + type)` on `CLASS_MORPHTANK` | `VSRst2/ffa3/…mpi2` (`MorphTankLock*`) | — |  |
|  127 | recycler variant: Stock / VSR Standard / Plus / Experimental | shell | **not read by the DLL** (no `"ivar127"` literal in `globals.tsv`) | `VSRst.cfg:867` default `Cmd("ivar127 2")`, `:929-1000` radio buttons | — | the shell swaps `svar5` (recycler ODF) and asset lists; the DLL sees only the resulting `svar5`  |

Engine-only / unused by Strategy02: 8, 10, 11, 19, 20, 27, 33, 34, 63 (`N:28-127`) — 19 and 27 are
deathmatch01's (§2a).

### 2a. deathmatch01 (`P:deathmatch01.cpp:1021-1099`, `Init`)

The VSR `deathmatch01.dll` keeps the stock 1.3 deathmatch settings (`13:vars.txt`) with no VSR slots of its
own; the VSR shell only ships the extra-options pages `bzshell_multi_addm.cfg` / `bzshell_multi_client_addm.cfg`
for it (`addm:<line>`), the main DM page is the stock one.

| Var | DM meaning | Read by (P) | Shell | 13:vars.txt |
|---|---|---|---|---|
| 0 | kill limit | `m_KillLimit` (`:1021`) | stock DM page | — |
| 1 | time limit, minutes | `m_TotalGameTime` (`:1022`) | stock DM page | — |
| 7 | **game subtype** `& 0xFF` (0 normal / 1 KOTH / 2 CTF / 3 Loot / 4 reserved / 5 Race (respawn as pilot) / 6 Race 2 (respawn as vehicle) / 7 Normal 2 (respawn as vehicle) — `DMSubtype_*` in the SDK's `ScriptUtils.h`) and **respawn type** `>> 8` | `m_MissionType`, `m_RespawnType` (`:1024,1039-1040`) | stock DM page | `:45` |
| 9 | race laps (race subtypes) / number of AI bots otherwise, capped at 256 | `m_TotalRaceLaps`, `m_MaxAIUnits` (`:1025,1044`) | `addm:297-310` | `:51-52` |
| 13 | spawn-kill window, seconds (× TPS) | `m_MaxSpawnKillTime` (`:1033`) | `addm:183` | `:69` |
| 16 | humans vs bots: all human teams 1–11 allied | `m_HumansVsBots` (`:1066-1083`) | stock DM page | `:81` |
| 19 | weenie (one-shot-kill) mode | `m_WeenieMode` (`:1087`) | stock DM page | `:87` |
| 22 | bot skill 0..4 (else 3; 3 when not networked) | `m_AIUnitSkill` (`:1059-1064`) | `addm:337-405` | `:93` |
| 23 | rabbit mode | `m_RabbitMode` (`:1085`) | stock DM page | `:97` |
| 25 | ship-only mode (respawn in a ship, no eject) | `m_ShipOnlyMode` (`:1088`) | stock DM page | `:106` |
| 27 | number of animals, capped at 8 | `m_MaxAnimals` (`:1091-1093`) | `addm:504-517` | `:122` |
| 31 | gravity × 2 (DM reads it itself, 25 when not networked) | `m_Gravity` → `SetGravity(v × 0.5)` (`:1026-1029,1054`) | `addm:467-480` | `:137` |
| 32 | friendly fire | `m_bIsFriendlyFireOn` (`:1031`) | stock DM page | `:140` |
| 35 | score limit, team-summed | `m_ScoreLimit` (`:1027`) | stock DM page | `:147` |
| svar12 | animal ODF (`mcjak01` default) when `ivar27 > 0` | `GetCheckedNetworkSvar(12, NETLIST_Animals)` (`:1097`) | — | `:246` |

Not read by deathmatch01 although the 1.3 spec lists them for DM: `ivar14` / `ivar15` (AI-kill scoring) and
`ivar26` (its damage multiplier is `BZ1Helper`'s, §2 row 26). `ivar2` (player limit) is skipped on purpose
("Assume the netmgr takes care of that", `:1023`).

## 3. svars

| Var | Meaning | Read by (D) | Shell | N |
|---|---|---|---|---|
| 0 | map `.bzn` | `Strategy02::Init` → `.trn` (`a2:1865`) → `[DLL] RespawnAtLowAltitude / FriendlySpawnpointMaxAllyRange / FriendlySpawnpointMinEnemyRange / RandomSpawnpointMinEnemyRange / CaptureTarget%d / CaptureIsRandom`, `[VSR] MapAmbientSound` (`a2:1890-1898`) | `bzshell_multi_option.cfg` | `N:145` |
| 1, 2 | team-group names | `taunts.cpp` `DoTaunt` uses `svar2` as the CPU taunt name (`a2:184`) | `VSRst/ffa` (svar2) | `N:147-149` |
| 3 | AIP base name | `GetCheckedNetworkSvar(3)` → `CustomAIPNameBase`, default `"VSR_"` (`a2:722-731`); AIP = `"%s%c%d_%d.aip"` | `*mpi3` | `N:151-166` |
| 4 | alt `MPVehicles.txt` | — | `VSRst/ffa` | `N:168` |
| 5 | recycler base ODF | list 2 → initial recycler, default `"ivrecy_m"` (`a2:841-849`); race letter substituted | `VSRst2/ffa2/ffa3/…` (set by the `ivar127` variant buttons) | `N:173-177` |
| 6 | starting-force list | non-empty → `StartingVehicleManager::Init()` (`a2:1858-1861`) | `VSRst/ffa`, `*only` | `N:179-183` |
| 7 | extra-options shell page suffix | shell only | `VSRst/ffa` | `N:185-195`; `VSR Map Info/VSR Prefixes.txt` |
| 8 | asset-check ODF (`MPIVSRCheck.odf` / `STvsrcheck.odf`) | engine preload; the DLL's own 24-file integrity check is separate (`D:bz1helper.cpp`, `a2:2816-2850`) | `VSRst/ffa` | `N:197-214` |
| 11 | MPI team-group-3 name | — | `VSRst/ffa` | `N:225-229` |
| 12 | CPU recycler base (ST) / DM animal ODF | list 2 → `"%cvrecycpu_vsr"` default (`a2:3271-3281`; `P:strategy02.cpp:2316`); DM: `GetCheckedNetworkSvar(12, NETLIST_Animals)`, default `mcjak01`, only when `ivar27 > 0` (`P:deathmatch01.cpp:1097-1099`) | `VSRst/ffa` | `N:237-245`; `13:vars.txt:246` |

civars: `civar5` DLL logging (`a2:301-309`), `civar0/1/2/3` engine-side (`N:251-259`).

## 4. `.trn` keys the DLL reads

`[DLL] RespawnAtLowAltitude, FriendlySpawnpointMaxAllyRange (100), FriendlySpawnpointMinEnemyRange (400),
RandomSpawnpointMinEnemyRange (450), CaptureTarget1..16, CaptureIsRandom, TauntODFFile ("Taunts"),
MPISwitchTeams%d ("A_B"), ReinforcementMinRadius (150), ReinforcementMaxRadius (250), ReinforcementCliffTolerance (100),
MinScrapHeight (−1e6), MaxScrapHeight (1e6), RestrictAllScrap, SpawnMinRadius (20), SpawnMaxRadius (50)`;
`[VSR] MapAmbientSound`; `[World] WorldLetter, Gravity (12.5)`; `[Size] Height, MetersPerGrid, HeightGranularity,
Width, Depth, MinX, MinZ`; `[Gravity] Gravity%d, OnPeriod%d, TranPeriod%d` (×16); `[Audio] AmbientSound%d, Position%d,
IsMusic%d, MinDelay%d, MaxDelay%d, BasePan%d, PanVariance%d, Rate%d` (×32); `[DefaultAllies] Entry1..N`;
path names `Player_%d`, `Enemy_%d`, `capturegoal%d`, `%dgtow%d`, `edge_path`. All `[B]`, from the string
table (`reference/manifest/strategy02-attempt2/strings.tsv`) and the `GetODF*` call sites in the decompile.

## 5. Instant Action (`Instant.dll`) — interface variables, not netvars

`InstantMission::DoGenericStrategy` reads the single-player shell's `options.instant.*` variables, never
`network.session.*` (`P:instantmission.cpp:838-877,990,1081`): `bool0` can respawn, `awarev13` (also read by
`BZ1Helper`'s constructor as the MPI-switch-teams trigger, `P:bz1helper.cpp:124`), `string0` custom AIP prefix,
`string1` / `string2` custom human / CPU recycler, `myrace` / `hisrace`, `int<Team>` per-CPU-team race for
teams 6–15, `int16` the human's ally team, `int<11+i>` the CPU teams' ally slots (default `i − 4`);
`BZ1Helper::Init` reads `bool2` (CPU daywreckers) and `bool4` (skill levels) when not networked
(`P:bz1helper.cpp:1449-1450`).
