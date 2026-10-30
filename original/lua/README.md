# original/lua/ — GBD's Lua port and the Test_Variant branch (Tier A)

Both branches of BlackDragonN001/VSR_Workshop are a single commit on top of master. Each folder
holds every file that commit added or modified, at the commit, byte-exact (blob hashes re-checked
after export), under its original path relative to the repository root. COMMIT.patch inside each
folder is git format-patch --binary of the commit, so the exact deltas (including the .bzn
binaries) are preserved too. COMMITS.txt carries git log --format=fuller and --stat.

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

## Test_Variant_644e79f/

Commit 644e79f05d2c6ed4d52889ec1402d446d7edb230, 2026-03-22, "Test Variant" — 6 files:
ivrecy_vsrT.autoreg, four *recy_vsrT.odf recycler variants under Recycler Variants/TEST/,
and a RecDescFFA.txt edit.