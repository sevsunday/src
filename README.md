# VSR_DLL_Source

Preservation and source reconstruction of the four VSR mission DLLs for
Battlezone: Combat Commander (BZCC).

## What is here

| Path | Contents | Trust tier |
|---|---|---|
| `original/` | The shipped DLLs and PDBs, GBD's Lua port of the three mission files, VSR documents and Workshop metadata — byte-exact, append-only | A |
| `reference/ancestor-1.3/` | The BZ2 1.3.7.2 stock mission-DLL source pack from GBD's public repository | A |
| `reference/ancestor-bz1helper-2015/` | The 2015 `BZ1Helper` helper family (GBD / Nielk1) that VSR's `vsrcore/` grew from | A′ |
| `reference/decompiled/` | PDB-symbolized Ghidra decompile of the shipped DLLs, regenerated here | B |
| `reference/manifest/` | File lists, line counts, function and global tables, build environment, repo refs, file map | B |
| `reference/engine/` | Third-party engine documentation used as a checklist only | C |
| `source/` | The reconstruction, file for file in GBD's tree: `missions/{shared,strategy02,instant,deathmatch01,luamission,vsrcore}` | — |
| `third_party/lua-5.2.4/` | Lua 5.2.4 (MIT), the public release closest to the Lua embedded in the DLLs | — |
| `release/<date>/` | The four built DLLs with PDBs and `SHA256SUMS.txt`, for running without building; each folder's `README.md` states what was tested | — |
| `build/build.cmd` | The only build entry point; mirrors GBD's link structure | — |
| `tools/` | Scaffolder, layout-assert generator, parity gates, Ghidra runbook | — |
| `docs/` | Background, recovery status, netvar reference | — |

Trust tiers are defined in `PROVENANCE.md`. Every file under `source/` carries
a `// PROVENANCE:` header naming its ancestor, the decompile range it was
checked against, and the Lua-port function that cross-checks it.

## Method

A three-way port, not transcription from pseudo-code:

1. Start from the public ancestor of each file (the 1.3 pack or the 2015
   helper family).
2. Overlay the PDB-true declarations: class names, field layouts, function
   signatures, source-line ranges.
3. Bring each function body to VSR using the regenerated decompile as the
   diff oracle and GBD's own Lua port as a cross-check.

Only the handful of helpers without a usable ancestor (`gravityhelper`,
`objecthelper`, `vehiclehelper`, `ambientsoundhelper`, `utilityshiphelper`)
are written from the decompile alone.

The target is behavioural parity, not GBD's exact text and not a byte-identical
binary. BZCC is lockstep with per-turn CRC checks, so GBD's DLL on one machine
and ours on another exposes any divergence within seconds. Mechanical gates
(struct layout asserts, symbol roster, string table, export table) catch
divergence before a game is launched. See `QA.md`.

## Building

```
set BZCC_DIR=C:\Program Files (x86)\Steam\steamapps\common\BZ2R
build\build.cmd
build\build.cmd check
```

Requires Visual Studio 2022 with the MSVC x86 toolset and a Windows 10/11 SDK.
The SDK headers `ScriptUtils.h` / `AiCmds.h` and `battlezone2.lib` are read
from `%BZCC_DIR%` at build time and are never committed; the 2.0.185 and
2.0.206.10 sets produce the same code (`DEPENDENCIES.md` D5). Output lands in
`out/Win32/Release/bin/missions/`. `python tools\compare_pe.py <released.dll>
<rebuilt.dll>` tells whether a rebuild is the same code as a file under
`release/` (linker metadata aside); not building at all is fine too — see
`release/2026-10-30/README.md`.

## Status

All 65 source files are ported; the four DLLs build with zero warnings and pass
the strict mechanical gates (symbol roster, string table, exports, imports).
`Strategy02.dll` has passed a two-machine lockstep A/B against GBD's binary in
both roles (2026-10-29/30, BZCC 2.0.206.10) and is in use for team-strat games;
the other three DLLs are built and gate-clean but not lockstep-tested (team
strat is the project's scope). The built files are under `release/2026-10-30/`.
`STATUS.md` tracks every source file through
`stub → ported → reviewed → compiles → parity` and holds the parity record;
`docs/RECOVERY.md` is the narrative version.

## Pins

Every external input is pinned to a commit, URL or hash in `DEPENDENCIES.md`.
