# BACKGROUND — what VSR's mission DLLs are, and why this repository exists

Trust tiers for every claim: **A** GBD's own artifacts · **A′** the original authors' public source at another
version, or Rebellion's SDK · **B** machine-derived from A and regenerated here · **C** third-party, labelled
`[third-party, unverified]` unless reproduced. Definitions: `../PROVENANCE.md`.

## The DLLs

Battlezone: Combat Commander (BZCC) loads a "mission DLL" for every map. The engine calls into it through a
fixed table of callbacks (`MisnExport`: `InitialSetup`, `AddObject`, `Update`, `AddPlayer`, `ObjectKilled`,
`PlayerEjected`, …) and the DLL calls back into the engine through the SDK (`ScriptUtils.h`, Tier A′). The
DLL owns game setup (recyclers, starting units, spawn points), the end-of-game rule, pilot respawn, scoring,
and every mod-specific rule layered on top.

VSR (Vet Strat Recycler Variant) ships four such DLLs in its Steam Workshop item `1325933293`
(`original/docs/workshop-item/1325933293.ini`, Tier A):

| DLL | Role | Class |
|---|---|---|
| `Strategy02.dll` | multiplayer Strategy, FFA, MPI (co-op), ST:Capture | `Strategy02 : LuaMission : BZ1Helper : DLLBase` |
| `LuaMission.dll` | a Lua-scripted mission host (`<map>.lua`) | `LuaMission : BZ1Helper : DLLBase` |
| `Instant.dll` | Instant Action | `instantMission : LuaMission : …` |
| `deathmatch01.dll` | Deathmatch, KOTH, CTF, Loot, Race | `Deathmatch01 : LuaMission : …` |

All four share `BZ1Helper` — General BlackDragon's helper framework from his Battlezone Classic mod on BZ2
("BZ1" is that mod's name, not Battlezone 1) — and its 18 helpers under `missions/vsrcore/` (scrap, power,
powerups, buildings, portals, attachers, carriers, morph objects, AI dispatch, …). The class chain and every
layout are read from the PDBs (`reference/manifest/pdb/*.types.md`, Tier B).

## Why they can be rebuilt

1. **The PDBs shipped with the DLLs** (Tier A). A PDB records every class with exact field offsets, every
   function with its signature and source-line range, and — in these PDBs — the full compiler command line
   per object file (`reference/manifest/BUILD_ENVIRONMENT.md`). We parse the PDBs directly
   (`tools/pdb_types.py`, `tools/pdb_modules.py`); no step depends on a decompiler's guess for a layout.
2. **The ancestors are public.** GBD's own repository holds the complete BZ2 1.3.7.2 stock mission source
   (`reference/ancestor-1.3/`, Tier A) from which `shared/`, `strategy02`, `deathmatch01`, `instantmission`
   and `luamission` descend; Nielk1's repository holds the 2015 BZ1Helper family
   (`reference/ancestor-bz1helper-2015/`, Tier A′) from which 14 of the 20 `vsrcore/` files descend.
   `reference/manifest/FILE_MAP.md` pairs every VSR file with its seed and the size delta.
3. **GBD's Lua port exists** (`original/lua/`, Tier A): his own rewrite of the three mission files in Lua, a
   second, independent statement of the same logic to check the C++ against.
4. **The decompile is reproducible** (Tier B): `tools/ghidra/` regenerates the PDB-symbolized decompile;
   the regenerated roster matches the received copy function for function
   (`reference/decompiled/strategy02-ghidra12.2/DIFF_vs_strategy02-attempt2.md`).
5. **Parity is testable.** BZCC is lockstep with a per-turn CRC. GBD's DLL on one machine and ours on another
   exposes any behavioural difference within seconds (`tools/parity/RUNBOOK.md`).

## What "rebuild" means here

Not GBD's exact text (unavailable) and not a byte-identical binary (unnecessary: the engine loads any DLL
that exports `GetMisnAPI` with `version 0x4C89322E` / `'BAL1'`, SDK `ScriptUtils.h:23,31`). The target is
**behavioural parity**, reached file by file through `stub → ported → reviewed → compiles → parity`
(`../QA.md`), with mechanical gates (layout asserts, symbol roster, string table, export table, save-record
sizes) ahead of the lockstep test.

## What the shipped binaries tell us (Tier B)

- Built 2026-02-20 with Visual Studio 2017 15.9: `/O1 /Ob2 /Oi /Os /Oy-` (MinSpace) + `/GL`, `/MD`, `/EHsc`
  on the mission projects, `/arch:SSE2`, `/LTCG:incremental`, image base `0x4FC00000`, `/SAFESEH`
  (`reference/manifest/BUILD_ENVIRONMENT.md`).
- `sizeof(Strategy02) = 0xECA4`, `TeamInfo = 0xA14`, `BZ1Helper = 0xA428`, `LuaMission = 0xA458`,
  `Deathmatch01 = 0xB544` (live TPI generation; the LTCG database also carries four stale `Strategy02`
  layouts from earlier builds).
- Lua 5.2 API, 92 exported symbols, compiled as C (`_setjmp3` / `longjmp` imports); `third_party/lua-5.2.4/`
  is the closest public source.
- No telemetry or external hooks: the callbacks do score / kill bookkeeping and Lua forwarding.
