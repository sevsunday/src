# PROVENANCE — trust tiers

Every input to this repository, and every claim in its documents, carries one
of four trust tiers. The tier says how much a reader may rely on it and what
must happen before it becomes a fact or a line of code.

## Tier A — GBD's own artifacts

Produced by General BlackDragon (or committed to his repositories by the VSR
team) for VSR itself.

- The four DLLs and their PDBs, as shipped in the Steam Workshop item
  `1325933293` and committed to `BlackDragonN001/VSR_Workshop`
  (`original/missions/`).
- GBD's Lua port of `Strategy02` / `Deathmatch01` / `InstantMission`
  (`VSR_Workshop` branch `Lua-Stock-Missions`, commit `ea4173f`;
  `original/lua/`).
- The `Test_Variant` branch content (commit `644e79f`; `original/lua/`).
- GBD's first, abandoned Strategy02 conversion (`BlackDragonN001/vsr_dll_lua`,
  commit `873669d`; `original/lua/vsr_dll_lua_873669d/`) — from line 776 on it
  is the C++ of his `Strategy02.cpp` under a mechanical search-and-replace.
- The VSR shell pages (`Upload/VSR/Config/Shell/bzshell_multi*.cfg` at
  `58a5f56`; `original/shell/`) that bind the lobby options to the netvars.
- `VSR Documents/` (changelogs, developer notes, `vsr-netvars.txt`, map info),
  the Workshop item `.ini` / `.cfg` / `.des` files (`original/docs/`).
- The BZ2 1.3.7.2-b132L mission-DLL source pack in GBD's public
  `BlackDragonN001/LuaMission` repository (`reference/ancestor-1.3/`). It is
  the stock source VSR's `shared/`, `strategy02`, `deathmatch01`, `instant`
  and `luamission` files descend from.

Tier A content is kept byte-exact and append-only. Nothing in `original/` is
ever edited.

## Tier A′ — public primary source by the original authors, at another version

Authoritative for what it is; not VSR's version of the code. Every function
taken from it is diffed against the decompile before it is accepted.

- The 2015 `BZ1Helper` helper family in `Nielk1/BZ2-LuaMission`, branch
  `BZC-LuaMission-Integration`, commit `6fda4f5`
  (`reference/ancestor-bz1helper-2015/`). "BZ1Helper" is the name of GBD's
  helper framework from his Battlezone Classic mod on BZ2; VSR's class chain
  is `Strategy02 : LuaMission : BZ1Helper : DLLBase`.
- Rebellion's BZCC SDK as installed with the game (`ScriptUtils.h`,
  `AiCmds.h`, `battlezone2.lib` in `%BZCC_DIR%`). Read at build time, never
  committed.

## Tier B — machine-derived from Tier A

Trusted after it has been regenerated here and diffed against the earlier
copy.

- The Ghidra decompile of the DLLs produced with their PDBs
  (`reference/decompiled/`).
- Function, global and type tables extracted from the PDBs
  (`reference/manifest/`).
- The Lua C-API export tables (`reference/manifest/lua_api_*.tsv`).

A Tier B artifact that has not yet been regenerated is marked
`pending regeneration` in its folder's `README` and is not quoted as fact.

## Tier C — third-party work

Hints and checklists only. No code is copied from Tier C sources. A Tier C
claim appears in our documents only as `[third-party, unverified]` unless it
has been reproduced here (in-game test, SDK header, binary inspection), in
which case the reproduction is cited instead.

- `BZ_REA` engine documentation (`reference/engine/`).
- The VRV mod's source and documentation (not copied into this repository;
  cited by file and line where a cross-check was useful).

`tools/check_no_thirdparty.py` fails the build if any identifier or header
belonging to those projects appears under `source/`.

## Per-file provenance header

Every file under `source/` begins with one line in this form:

```
// PROVENANCE: ancestor <D3|D4 path @ commit> + decompile <file:line-line> | gbd-lua-port <file:function> | decompile-only | new
```

- `ancestor …` — the Tier A / A′ file it was seeded from.
- `decompile …` — the regenerated decompile range it was brought to parity with.
- `gbd-lua-port …` — the Lua-port function that cross-checks it, when one exists.
- `decompile-only` — no usable ancestor; written from the decompile.
- `new` — glue that has no counterpart in GBD's tree (kept to a minimum and
  listed in `STATUS.md`).

## Claims in documents

- Tier A / A′ / B: cite `file:line` or commit hash.
- Tier C: label `[third-party, unverified]` or cite the reproduction.
- Numbers that came from an automated survey rather than a direct read are
  re-read from the Tier A/B source before they are quoted as fact.
