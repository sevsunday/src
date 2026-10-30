# original/lua/ — GBD's Lua ports and the Test_Variant branch (Tier A)

Both branches of BlackDragonN001/VSR_Workshop are a single commit on top of master. Each folder
holds every file that commit added or modified, at the commit, byte-exact (blob hashes re-checked
after export), under its original path relative to the repository root. COMMIT.patch inside each
folder is git format-patch --binary of the commit, so the exact deltas (including the .bzn
binaries) are preserved too. The third folder is the single commit of a separate repository,
BlackDragonN001/vsr_dll_lua. COMMITS.txt carries git log --format=fuller and --stat for all three.

## Lua-Stock-Missions_ea4173f/

Commit ea4173fbddbeba2b2f97e499bea87967bfbdc147, 2026-03-03, "Lua versions of
Strategy/Deathmatch/Instant with some test maps." — 24 files, +6,559 / −116.

- Upload/VSR/Missions/Scripts/Strategy.lua (2,811 lines; header "Converted from Strategy02.cpp")
- Upload/VSR/Missions/Scripts/Deathmatch.lua (1,943; "Converted from Deathmatch01.cpp")
- Upload/VSR/Missions/Scripts/InstantMission.lua (979; "Converted from InstantMission.cpp")
- Upload/VSR/Missions/Scripts/Helpers/{_AICmd,_GlobalHandler,_StartingVehicles}.lua (new),
  {_DLLUtils,_GlobalVariables,_PUPMgr}.lua (modified), Main/_AnimalController.lua (modified)
- seven test maps, each with a 3-line .lua stub and a re-saved .bzn

This is GBD's own rewrite of the three mission files. It is the cross-check for the C++ port
(see ../../QA.md, gate 1).

## vsr_dll_lua_873669d/

A different repository: BlackDragonN001/vsr_dll_lua ("VSR CPP Lua conversions"), one commit
873669df40e82344923f175c56611da5a5746f5f, 2025-08-02, "Initial Strategy02 Conversion, WIP. Spent
5 hours on this..." — one file, Lua/Strategy.lua (132,453 bytes, 3,652 lines, LF, blob
d7fe3fb99ef7596f6e990eca343a3c286786e204; SHA-256
28657155E66C1DF8448198053F8141F0FF3045B190295C728D6FF991A607F75C). Copied byte-exact with
`git cat-file blob`; the file is the whole commit, so no patch is kept.

It is GBD's abandoned first pass at the Lua port, seven months before the Lua-Stock-Missions
branch above, and it is the only GBD-authored text of Strategy02.cpp in public:

- Lines 1-775 are hand-converted Lua (the member table, Save / Load, AddObject, DeleteObject,
  SetCPUAIPlan, the GetInitial*ODF functions). Line 12 carries his own doubt about one of them.
- Lines 776-3652 (GetSpawnpointForTeam through ExecuteST_Capture) are the C++ of Strategy02.cpp
  with a search-and-replace applied and nothing else: `{` / `}` -> `then` / `end`, `//` -> `--`,
  `!=` -> `~=`, `&&` / `||` -> `and` / `or`, `!` -> `not ` (even inside string literals: "has
  wonnot  Captured" at line 3630), type names -> `local`. Function headers (`void
  Strategy02::Init(void)`), `#ifndef EDITOR`, `memset`, `sprintf_s`, pointer declarations and
  2-D char arrays are intact.

Lines 776-3652 are therefore a text oracle for `source/missions/strategy02/strategy02.cpp`
(same functions, GBD's identifiers and comments). The cross-check against the port is recorded in
`../../STATUS.md` ("GBD-text cross-check"). The Lua-Stock-Missions file above is the finished
port and remains the cross-check for Deathmatch01 / InstantMission.

## Test_Variant_644e79f/

Commit 644e79f05d2c6ed4d52889ec1402d446d7edb230, 2026-03-22, "Test Variant" — 6 files:
ivrecy_vsrT.autoreg, four *recy_vsrT.odf recycler variants under Recycler Variants/TEST/,
and a RecDescFFA.txt edit.