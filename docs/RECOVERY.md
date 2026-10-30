# RECOVERY — method, dependencies and status of the reconstruction

`../STATUS.md` is the per-file ledger and the authority; this page is the narrative.

## Method: a three-way port

For each of the 65 source files GBD's PDBs name under `missions\` (`reference/manifest/pdb/SUMMARY.md`):

1. **Seed** from the public ancestor (`reference/manifest/FILE_MAP.md`): GBD's 1.3.7.2 pack (Tier A) for
   `shared/`, `strategy02`, `deathmatch01`, `instantmission`, `luamission`; the 2015 BZ1Helper family
   (Tier A′) for 14 `vsrcore/` helpers. Six helpers (`ambientsound`, `gravity`, `object`, `powerup`,
   `utilityship`, `vehicle`) have no usable ancestor and are written from the decompile.
2. **Overlay the PDB** (Tier B): class kind, base, members in offset order with access, static members,
   nested types, methods in declaration order with `virtual` / `static` / `const` and vtable slot, enums with
   values, parameter names. `tools/scaffold_from_manifest.py` wrote all of it; `tools/layout_asserts.py`
   emits 853 `static_assert`s that fail the build on any layout drift (QA gate 2).
3. **Bring the body to VSR** against the regenerated decompile (`reference/decompiled/`), cross-checking with
   GBD's Lua port (`original/lua/`) wherever it covers the function, and reading the ancestor diff line by
   line (QA gate 1).
4. **Gates** before a file's state advances: no third-party code (gate 5), symbol parity (gate 3), string
   parity (gate 4), independent review (gate 6), then the lockstep A/B (gate 8).

Port order is dependency-driven: tier 1 `mathutils`, `bzcscriptutils`, `shared/*` → tier 2 small helpers →
tier 3 `bz1helper` and the large helpers (`dispatchhelper` last) → tier 4 `luamission` / `luabindings`,
`strategy02`, `instantmission`, `deathmatch01`.

## Where things stand

| Stage | State |
|---|---|
| Preservation (originals, documents, both Lua ports, the VSR shell pages, ancestor trees) | complete, hashed, blob-verified; the upstream refs and hashes are in `reference/manifest/REPO_REFS.txt` |
| Toolchain (`build/build.cmd`, GBD's recorded flags, stub load test in the game) | complete — `build/stub/LOADTEST.md` |
| PDB-derived manifests (layouts, methods, enums, build environment, membership) | complete, regenerable (`tools/pdb_*.py`) |
| Scaffold (66 files, PDB-true declarations, 1,205 stubs, 387 ancestor seeds) | complete; all four DLLs build with zero warnings, every layout assert passes |
| QA gates + runbooks | complete; `build.cmd check` |
| Strategy02 decompile regeneration (Ghidra 12.2) | roster identical to the received copy; see its `DIFF_vs_*.md` |
| Decompiles of `LuaMission`, `Instant`, `deathmatch01` | complete (Ghidra 12.2 + PDBs, every function, 0 failures; `reference/manifest/<set>/`) |
| Port tiers 1–4 | complete — all 65 files `ported`, no stubs; ancestor text + PDB declarations, the decompile as diff oracle, `dumpbin` for register-passed / folded arguments, GBD's Lua port as cross-check; shipped bugs kept and marked `// shipped:` (`../STATUS.md`) |
| Mechanical parity (symbols, strings, exports, imports) | complete and strict — `build.cmd check`; string tables identical on all four DLLs, every roster difference an explained inliner decision (`tools/parity/symbol_allow.txt`) |
| Parity (lockstep A/B) | **`Strategy02.dll`: pass** — two machines, BZCC 2.0.206.10 `devtest`, `vsroverlook` team strat, GBD's DLL hosting with ours joining (734 s) and ours hosting with GBD's joining (279 s); no divergence after the join sync, game-over path and clean shutdown on both ends, DLL logs line-identical per role; which DLL ran proven by in-game file locks and hashes (`../STATUS.md` → Lockstep A/B record). Scope decision 2026-10-30: team strat only — `LuaMission` / `Instant` / `deathmatch01` and the FFA / MPI / Capture paths are built and gate-clean but not lockstep-tested. Not yet exercised within scope: 3+ a side, mid-game join / rejoin, Scion / Hadean, portals, a Lua-scripted map, long games |
| Deployment | our `Strategy02.dll` (`ee340b6e…`, built 2026-10-29 against the 2.0.185 SDK) runs on the operator's main machine for community team-strat games from 2026-10-30. The committed binaries are `../release/2026-10-30/` (all four DLLs + PDBs + `SHA256SUMS.txt`): the same source relinked from a neutral path against the 2.0.206.10 SDK, shown by `tools/compare_pe.py` to be the same code as the tested build — which also closed the SDK question of `../DEPENDENCIES.md` D5 |

## Dependencies (pinned in `../DEPENDENCIES.md`)

| ID | What | Pin |
|---|---|---|
| D1 | GBD's Workshop repository | `master 58a5f56`, `Lua-Stock-Missions ea4173f`, `Test_Variant 644e79f` |
| D2 | the four DLLs + PDBs | `original/missions/SHA256SUMS.txt` |
| D3 | 1.3.7.2 stock mission source | `353698f578e00ea5f9806fea701b5bd7c69d94ce` |
| D4 | 2015 BZ1Helper family | `6fda4f5ab3c2f2aae882ebe22b9ef6180e42f744` |
| D5 | BZCC SDK, read from `%BZCC_DIR%` | game 2.0.185 |
| D6 | Lua 5.2.4 | `b9e2e4aad6789b3b63a056d442f7b39f0ecfca3ae0f1fc0ae4e9614401b69f4b` |
| D7 | Ghidra 12.2 + Temurin JDK 25 (portable, `tools/_local/`) | `tools/ghidra/VERSIONS.txt` |
| D8 | the received decompile | `reference/decompiled/strategy02-attempt2/` |
| D9 | Workshop items for parity tests | `1325933293` + its eight asset packs |
| D10 | third-party engine notes (Tier C, no code) | `reference/engine/SOURCES.md` |
| D11 | GBD's first Strategy02 conversion (C++ text from line 776) | `873669df40e82344923f175c56611da5a5746f5f` |

## Corrections made to the original plan

- Compiler settings: the PDBs say VS 2017, `/MD`, `/O1` MinSpace + `/GL` LTCG, `/EHsc` on the DLL projects only,
  `/arch:SSE2`, base `0x4FC00000`, no `-std:` — not the `/MT /O2 /std:c++17` first assumed.
- Output folder is `out/`: on NTFS `Build/` and `build/` are the same folder.
- Six decompile-only helpers, not five (no `PowerupHelper` in either ancestor repository).
- `LuaMission.dll` compiles `luamission.cpp` / `luabindings.cpp` directly; `VSRCore.lib` carries `taunts.cpp`.
- The LTCG database in the PDBs keeps stale class generations; always take the highest type index
  (`tools/pdb_types.py`), as `operator new(0xECA4)` in `BuildMission` confirms.

## Scaffold conventions still in the tree

`source/README.md` lists every token the scaffold introduced (`friend struct VsrLayoutCheck_*`, public nested
types, commented stub parameter names, `#pragma warning(disable: 4505)`, `#if 0 // SEED` blocks) and what each
port removes.
