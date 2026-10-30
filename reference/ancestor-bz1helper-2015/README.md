# reference/ancestor-bz1helper-2015/ — BZ1Helper helper family (Tier A′)

Source: `Nielk1/BZ2-LuaMission` branch `BZC-LuaMission-Integration`, commit
`6fda4f5ab3c2f2aae882ebe22b9ef6180e42f744` (2015-11-28, "More CLeanup"), folder
`BZ2 LUA Dll Source Code/Missions/Shared/`, extracted 2026-10-28 with `git archive` from the
preservation mirror; all 102 blob hashes re-checked. Kept under `Shared/` to preserve the path.

"BZ1Helper" is General BlackDragon's mission-DLL helper framework from his Battlezone Classic mod on
BZ2 — not Battlezone 1 content. VSR's DLL is built on the same class
(`Strategy02 : LuaMission : BZ1Helper : DLLBase`). This is the 2015 public state of that framework;
VSR's `vsrcore/` is its 2016–2026 continuation.

Files VSR uses (seed → `source/missions/vsrcore/`): `BZ1Helper`, `BZCScriptUtils`, `AIWeaponHelper`,
`AttacherHelper`, `BuildingHelper`, `CarrierHelper`, `DispatchHelper`, `MorphObjectHelper`,
`PortalHelper`, `PowerHelper`, `ProductionClassHelper`, `ScrapHelper`, `UndeployHelper`,
`MathUtils`. `UtilityShipHelper` is here too but is a third of VSR's size (1 of 6 VSR identifiers
present) and is treated as decompile-first. The remaining helpers (`AmmoDrain`, `Anchor`, `APC`,
`Deploy`, `DropShip`, `EnergyArmor`, `Fury`, `Geyser`, `HQCP`, `Jammer`, `LavaDamage`, `Limiter`,
`LPad`, `PilotResource`, `Quake`, `RecallMine`, `Recycle`, `ReplaceOnDeath`, `Satellite`, `Shield`,
`SwitchClass`, `Transport`, …) are not part of VSR's DLL and are kept only for completeness.

Every function taken from here is diffed against the regenerated decompile before acceptance (Tier A′ rule).
License status: `LICENSE-AS-FOUND.md`.