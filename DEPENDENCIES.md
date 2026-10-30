# DEPENDENCIES — pinned sources

Every external input is pinned to a commit, URL or hash. Remote reachability
and the pins below were verified on 2026-10-28. Re-verify with the commands
given before relying on a fresh fetch.

| ID | What | Tier | Pin |
|---|---|---|---|
| D1 | VSR Workshop repository | A | `BlackDragonN001/VSR_Workshop` — `master` `58a5f56c308c152ab25acb8470429351c44eb713`, `Lua-Stock-Missions` `ea4173fbddbeba2b2f97e499bea87967bfbdc147`, `Test_Variant` `644e79f05d2c6ed4d52889ec1402d446d7edb230` |
| D2 | The four VSR DLLs + PDBs | A | `Upload/VSR/Missions/` at D1 `master`; SHA-256 in `original/missions/SHA256SUMS.txt` |
| D3 | BZ2 1.3.7.2-b132L DLL source pack | A | `BlackDragonN001/LuaMission` `353698f578e00ea5f9806fea701b5bd7c69d94ce` (2017-10-19), folder `BZ2 1.3.7.2-b132L Dll Source Code/` |
| D4 | BZ1Helper helper family (2015) | A′ | `Nielk1/BZ2-LuaMission` branch `BZC-LuaMission-Integration` `6fda4f5ab3c2f2aae882ebe22b9ef6180e42f744` (2015-11-28), folder `BZ2 LUA Dll Source Code/Missions/Shared/` |
| D5 | BZCC SDK (Rebellion) | A′ | installed game `%BZCC_DIR%`; the shipped DLLs and the lockstep-tested build used the 2.0.185 SDK (Steam build 3807009); the build machine moved to the `devtest` beta 2.0.206.10 on 2026-10-29 and the released binaries are built against that set — shown to be the same code for all four DLLs (D5 section) |
| D6 | Lua 5.2.4 | — (MIT) | `https://www.lua.org/ftp/lua-5.2.4.tar.gz`, 252,651 bytes; SHA-256 recorded below after download |
| D7 | Ghidra + JDK (tools) | — | latest Ghidra 11.x release + Temurin JDK 21; exact versions in `tools/ghidra/VERSIONS.txt` |
| D8 | Existing Strategy02 decompile | B (pending regeneration) | `reference/decompiled/strategy02-attempt2/` |
| D9 | Parity-test Workshop content | — | Steam Workshop items listed below, installed |
| D10 | Third-party engine reference | C | `BZ_REA` documentation (`reference/engine/`); VRV mod (not copied) |
| D11 | GBD's first Strategy02 Lua conversion (C++ text) | A | `BlackDragonN001/vsr_dll_lua` — `main` `873669df40e82344923f175c56611da5a5746f5f` (the only commit); `original/lua/vsr_dll_lua_873669d/` |

## D1 — VSR Workshop repository

- Remote: `https://github.com/BlackDragonN001/VSR_Workshop.git`
- Refs (verified `git ls-remote` 2026-10-28):
  - `refs/heads/master` `58a5f56c308c152ab25acb8470429351c44eb713` (2026-10-18)
  - `refs/heads/Lua-Stock-Missions` `ea4173fbddbeba2b2f97e499bea87967bfbdc147` (2026-03-03, "Lua versions of Strategy/Deathmatch/Instant with some test maps")
  - `refs/heads/Test_Variant` `644e79f05d2c6ed4d52889ec1402d446d7edb230` (2026-03-22)
- No tags. 341 commits across all refs.
- Latest DLL build commit: `d0f63c6` 2026-02-20 "Fixed bug in Service Truck AI Dispatch code".
- Exported from `master` into this repository: the DLLs + PDBs (D2), `Upload/VSR Documents/` and the Workshop item
  files (`original/docs/`), and the 47 `Upload/VSR/Config/Shell/bzshell_multi*` lobby pages (`original/shell/`,
  `SHA256SUMS.txt`); from the two branches, their changed files (`original/lua/`).
- Verify: `git ls-remote https://github.com/BlackDragonN001/VSR_Workshop.git`
- Full-history mirror kept outside this repository (see `reference/manifest/REPO_REFS.txt`).

## D2 — the binaries

Source path at D1 `master`: `Upload/VSR/Missions/{Strategy02,LuaMission,Instant,deathmatch01}.{dll,pdb}`.

| File | Bytes | SHA-256 |
|---|---:|---|
| `Strategy02.dll` | 465,408 | `A4B3CE223FC305DF88507B07D1E0790CED781DF5147CCCE4886D776C45C0B6BB` |
| `Strategy02.pdb` | 3,739,648 | `78C1F2F35333D860230E93D9E0FE2C0A3E32984B6A2E180C1E6742AC0EC6C670` |
| `LuaMission.dll` | 433,152 | `A7097E937761F2EF81D84693EF537C0102CC359AD3D6A7AA1D7D01A6B98A5A2A` |
| `LuaMission.pdb` | 3,477,504 | `C1820D1B74D8288618CD437514CDE3DF2BD667FDE8CBAFA5CE2850597861C0B7` |
| `Instant.dll` | 445,952 | `C17C7D1C7FA7A75B87F3350F3B66599E207E9ECE580D555B5C7C5051BD7E407D` |
| `Instant.pdb` | 3,526,656 | `F9CDE5DEA13CE5B367152514B5DB48C580EE1E043AA9D0F373DC073D8D7B729F` |
| `deathmatch01.dll` | 449,536 | `B982C41694ABA3E7D48FE4BC2D145D6D4F0261D529DEA17D644212478C5E6020` |
| `deathmatch01.pdb` | 3,575,808 | `FC5599C79D980682B8A015A8426E074BB9B3A90C9C3CC1E151431B3D7EAC887E` |

- PE32 x86, single export `GetMisnAPI`, no `VERSIONINFO` resource.
- Link time 2026-02-20 16:26:58–59 UTC.
- Byte-identical to the live Steam Workshop install
  `…\steamapps\workshop\content\624970\1325933293\VSR\Missions\`.
- Verify: `Get-FileHash original\missions\*.dll, original\missions\*.pdb -Algorithm SHA256` against `original/missions/SHA256SUMS.txt`.

## D3 — BZ2 1.3.7.2-b132L DLL source pack

- Remote: `https://github.com/BlackDragonN001/LuaMission.git`
- Commit: `353698f578e00ea5f9806fea701b5bd7c69d94ce` (`master`, 2017-10-19, "-Fixed copy paste errors.")
- Folder: `BZ2 1.3.7.2-b132L Dll Source Code/`
  - `Missions/{Shared, Strategy02, Deathmatch01, Instant, MPInstant, StratCTF, LuaMission, lua_5_1_5}`, `Missions.sln`, `*.vcxproj`
  - `Source/fun3d/{AiCmds.h, ScriptUtils.h}` (1.3-era), `Source/network/vars.txt`
  - `Readme_Source.txt`, `Debug/lua51_lib.lib`
- Seeds: `shared/{dllbase, dllutils, startingvehicles, taunts, trnallies, pupmgr, trace}`, `strategy02`, `deathmatch01`, `instantmission`, `luamission/{luamission, luabindings}`.
- Fetched 2026-10-28: 124 files, every blob hash re-checked against the mirror.
- Fetch:
  ```
  git clone --mirror https://github.com/BlackDragonN001/LuaMission.git <mirror>
  git -C <mirror> rev-parse 353698f578e00ea5f9806fea701b5bd7c69d94ce
  git -C <mirror> archive 353698f578e00ea5f9806fea701b5bd7c69d94ce "BZ2 1.3.7.2-b132L Dll Source Code" | tar -x -C reference/ancestor-1.3/
  ```

## D4 — BZ1Helper helper family (2015)

- Remote: `https://github.com/Nielk1/BZ2-LuaMission.git`
- Branch / commit: `BZC-LuaMission-Integration` `6fda4f5ab3c2f2aae882ebe22b9ef6180e42f744` (2015-11-28, "More CLeanup")
- Folder: `BZ2 LUA Dll Source Code/Missions/Shared/`
- Files VSR uses: `BZ1Helper`, `BZCScriptUtils`, `AIWeaponHelper`, `AttacherHelper`, `BuildingHelper`, `CarrierHelper`, `DispatchHelper`, `MorphObjectHelper`, `PortalHelper`, `PowerHelper`, `ProductionClassHelper`, `ScrapHelper`, `UndeployHelper`, `UtilityShipHelper`, `MathUtils` (the folder also holds helpers VSR does not use; they are kept for completeness).
- Seeds 13 of the 18 `vsrcore/` files. `utilityshiphelper` (2015 copy is a third of VSR's size), `ambientsoundhelper`, `gravityhelper`, `objecthelper`, `vehiclehelper` are written from the decompile.
- Fetched 2026-10-28: 102 files, every blob hash re-checked against the mirror. No `LICENSE` file at that commit (`reference/ancestor-bz1helper-2015/LICENSE-AS-FOUND.md`).
- Fetch:
  ```
  git clone --mirror https://github.com/Nielk1/BZ2-LuaMission.git <mirror>
  git -C <mirror> rev-parse 6fda4f5ab3c2f2aae882ebe22b9ef6180e42f744
  git -C <mirror> archive 6fda4f5ab3c2f2aae882ebe22b9ef6180e42f744 "BZ2 LUA Dll Source Code/Missions/Shared" | tar -x -C reference/ancestor-bz1helper-2015/
  ```

## D5 — BZCC SDK

- `%BZCC_DIR%` = `C:\Program Files (x86)\Steam\steamapps\common\BZ2R` on the build machine.
- `battlezone2.exe` 2.0.185, 5,316,976 bytes, SHA-256 `2319FB1CBB3A1D35E8D3FFDDB501F8B9518DB1C9EBAB893D34D7024D8535F426`.
- `ScriptUtils.h` 117,583 bytes, SHA-256 `C60CB3BDC8A5E9FF342F1239CC4B197713A621E4640A55B4240CA0F6B77A65F7` (`BZCC_DEFAULT_TPS 20`; `LATEST_DLL_VERSION 0x4C89322E`).
- `AiCmds.h` 1,140 bytes. `battlezone2.lib` 288,472 bytes.
- Steam `appmanifest_624970.acf`: `buildid 3807009`.
- Matches VSR's `m_GameVersion = 20185` (`bz1helper.cpp`).
- Never committed. Read by `build/build.cmd` from `%BZCC_DIR%`.
- **State of the build machine since 2026-10-29 20:22:** Steam was switched to the `devtest` beta (2.0.206.10,
  buildid 25009108; `battlezone2.exe` 5,606,408 bytes, SHA-256 `7C0889D8503B0F8CD696354AE72C3B8B6FB7EAE899FFE1B4FBAF5B6230DA82CC`),
  which replaced the SDK files in the game folder: `ScriptUtils.h` is now 133,906 bytes
  (`4428B2AA5C7B6772EF9848D36954A1EB3B156A300A96189ED576D1C922BBAA70`, 532 `DLLEXPORT`s; `LATEST_DLL_VERSION`
  still `0x4C89322E`) and `battlezone2.lib` 311,350 bytes (`15EA6C6EE755E8724C87D62BF668B9CB5E32CAF676B0F363ECE53E6E78046D32`).
  The 2.0.185 header pinned above is no longer on this machine, and no snapshot was taken first.
- **Consequences, as first recorded.** The deployed / lockstep-tested `Strategy02.dll` (`ee340b6e…`, built
  2026-10-29 14:42, `STATUS.md` → Parity results) was compiled against the 2.0.185 SDK and is unaffected. A
  rebuild compiles against the 2.0.206.10 header, so a rebuilt binary would not be the tested one unless the
  two SDKs could be shown to produce the same code.
- **Resolved 2026-10-30.** All four DLLs were rebuilt against the 2.0.206.10 set (`AiCmds.h` 1,140 bytes
  `47C08CB3E28AF73D7F2EC364C5237060EF22A01636A4192DED393BF1567A5690`, unchanged) and compared with the
  2.0.185 builds of 2026-10-29 14:42 by `tools/compare_pe.py`: **EQUIVALENT, 0 mismatches, for all four** —
  `.text` and `.data` identical, the same 581 / 584 / 584 / 586 import names in the same order, the same
  export, the same relocation counts; only the linker's debug metadata differs (and that because the rebuild
  added `/PDBALTPATH` and `/Brepro`). The header grew by new declarations our code does not use and no
  layout we depend on moved; the import library resolves the same names. The 2.0.206.10 set is therefore
  the pin from here on, the 2.0.185 hashes above stay as the record of what GBD's PDBs line-match, and the
  released binaries under `release/2026-10-30/` are the 2.0.206.10 build. Nothing remains to re-acquire.
- The 133,906-byte `ScriptUtils.h` is the 2.0.206 SDK's header (it is also the one in the EXU2 / statsgate
  trees); the 2.0.185 pin above is the one GBD's PDBs line-match.

## D6 — Lua 5.2.4

- `https://www.lua.org/ftp/lua-5.2.4.tar.gz` — 252,651 bytes, downloaded 2026-10-28.
- SHA-256 `b9e2e4aad6789b3b63a056d442f7b39f0ecfca3ae0f1fc0ae4e9614401b69f4b` (equals lua.org's published hash). Per-file hashes in `third_party/lua-5.2.4/SHA256SUMS.txt`.
- All 92 symbols in `reference/manifest/lua_api_Strategy02.tsv` are declared in 5.2.4's `lua.h` / `lauxlib.h` / `lualib.h` (checked on download).
- Rationale: the DLLs embed the string `"Lua 5.2"` and export 92 Lua C-API symbols that belong to the 5.2 API (`lua_pushunsigned`, `luaL_checkunsigned`, …). GBD linked `lua51_lib.lib` built from the BZCC engine tree's bundled Lua (library name notwithstanding). 5.2.4 is the final public 5.2 release and the closest available source.
- Verified at build against `reference/manifest/lua_api_Strategy02.tsv`.

## D7 — Ghidra + JDK

- Ghidra: latest 11.x from `https://api.github.com/repos/NationalSecurityAgency/ghidra/releases/latest` → `tools/_local/ghidra/`.
- JDK: Temurin 21 from `https://api.adoptium.net/v3/binary/latest/21/ga/windows/x64/jdk/hotspot/normal/eclipse` → `tools/_local/jdk21/`.
- Exact versions and archive hashes are written to `tools/ghidra/VERSIONS.txt` on install. Nothing under `tools/_local/` is committed.

## D8 — existing decompile (Tier B, pending regeneration)

- A PDB-symbolized Ghidra decompile of `Strategy02.dll` produced 2026-10-15 plus the two `lua_api_*.tsv` export tables.
- Kept at `reference/decompiled/strategy02-attempt2/` until the regeneration in task 8 supersedes it; differences are recorded there.

## D9 — parity-test content

Steam Workshop items under `…\steamapps\workshop\content\624970\`:

| Item | What |
|---|---|
| `1325933293` | VSR (the mod) |
| `3532748119` | VSR Asset Pack |
| `1329659846` | Aegeis' VSR map pack |
| `2785557433` | FE:R Shared |
| `2785542655` | FE:R Hadean |
| `2814914461` | FE:R Cerberi |
| `2049956570` | ISDF Model Pack |
| `3493379153` | FE:R Scion |
| `2467249743` | Gravey's VSR Map Pack |

These are exactly the `assetDependencies` of `1325933293.ini`.

## D10 — third-party reference (Tier C)

- `BZ_REA` engine documentation for 2.0.185 — copied into `reference/engine/` with `SOURCES.md`. Checklists only; no code.
- The VRV mod source (`https://gitlab.com/vacuum34/vrv.git`, `main`) — not copied. Its stock-1.3 copies are modified and are superseded by D3.

## D11 — GBD's first Strategy02 Lua conversion

- Remote: `https://github.com/BlackDragonN001/vsr_dll_lua.git` ("VSR CPP Lua conversions")
- Ref / commit (verified `git clone` 2026-10-30): `refs/heads/main` `873669df40e82344923f175c56611da5a5746f5f`
  (2025-08-02, "Initial Strategy02 Conversion, WIP. Spent 5 hours on this..."). One commit, one file.
- File: `Lua/Strategy.lua`, 132,453 bytes, blob `d7fe3fb99ef7596f6e990eca343a3c286786e204`, SHA-256
  `28657155E66C1DF8448198053F8141F0FF3045B190295C728D6FF991A607F75C`; kept byte-exact at
  `original/lua/vsr_dll_lua_873669d/Lua/Strategy.lua`.
- Why it is pinned: lines 776-3652 are the C++ of GBD's `Strategy02.cpp` with a mechanical search-and-replace
  applied (`original/lua/README.md`) — the only GBD-authored text of that file in public, and the text
  cross-check recorded in `STATUS.md` ("GBD-text cross-check"). The finished Lua port (D1
  `Lua-Stock-Missions`) is a separate, later rewrite.
- Verify: `git ls-remote https://github.com/BlackDragonN001/vsr_dll_lua.git` and
  `git hash-object --no-filters original/lua/vsr_dll_lua_873669d/Lua/Strategy.lua` (expect `d7fe3fb9…`).

## Dead ends (recorded so nobody re-walks them)

- The Rebellion "source announcement" URL redirects to a generic product page.
- `matesfamily.org/bz2/` is an index page; the 1.3 pack itself is D3.
