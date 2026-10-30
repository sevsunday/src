# reference/engine/SOURCES.md — third-party engine documentation (Tier C)

Checklists only. No code is copied from these files into `source/`; `tools/check_no_thirdparty.py`
enforces it. A claim from here appears in our documents only as `[third-party, unverified]` unless
reproduced (SDK header, binary inspection, in-game test), in which case the reproduction is cited.

## Origin

`BZ_REA` — the Battlezone Combat Commander engine research documentation produced by the VRV mod
project (vacuum34). Copied 2026-10-28 from a local checkout of its `engine/` folder. The set carries
no `LICENSE` file; its own `SOURCES.md` describes the third-party texts under its `sources/` as
"local-only third-party source references" and states that "No SDK, game binaries or decompiler
output is imported". Author's own words on its status: "**The research is active.** The collected
interfaces and initial findings do not constitute a recovered or fully documented engine."

Measured target per its `BINARY-CARRIERS.md`: `battlezone2.exe` 2.0.185, 5,316,976 bytes, SHA-256
`2319fb1cbb3a1d35e8d3ffddb501f8b9518db1c9ebab893d34d7024d8535f426` — the same hash as the game
installed on this build machine (`DEPENDENCIES.md` D5), so its RVAs refer to the binary VSR's
DLLs run against. Its procedure-level claims come from a decrypted capture of that binary
(`public-2.0.185-live.exe`, base `0xde0000`), not from the shipped file.

## Files kept (6 of 42)

| File | Bytes | SHA-256 (prefix) | Title | Why kept |
|---|---:|---|---|---|
| `bz_rea/MISSION-ABI.md` | 22,106 | `328100ac8b2f64c5…` | Mission DLL ABI: public 2.0.185 | `MisnImport` / `MisnExport` / `MisnExport2` layouts, `SetPre*Callback` RVAs, `EjectKillRetCodes`, which callbacks are absent in 2.0.185 — compile-checked against the installed `ScriptUtils.h`, so effectively A′ where it restates the header |
| `bz_rea/MISSION-STATE.md` | 11,325 | `53b12806dd034365…` | Mission state, compatibility stubs and scoreboard access | what `AddScore` / `AddKills` / `AddDeaths` / `GetCurWorld` gates do natively — context for `Strategy02::DeadObject` |
| `bz_rea/OBJECT-STATE.md` | 17,719 | `d322d71a1c6a7cab…` | Object state, handle gates and native SDK behavior | `GetTeamNum`, health getters, `SetTeamNum` refusal for MP players — context for the helpers' per-object code |
| `bz_rea/OBJECT-CLASS-LOAD.md` | 8,606 | `23a7efb7db674436…` | GameObjectClass construction and ODF inheritance | ODF defaults the engine applies when a key is missing (`customCost`, `customTime`, `aiAddHealth`…) |
| `bz_rea/ODF.md` | 30,118 | `d70d3a969f2889fe…` | ODF access: public 2.0.185 interface and native wrappers | typed-getter coercions, 15-char inline value claim, key hashing — checklist for every `GetODF*` call the port writes |
| `bz_rea/NETWORK-VARIABLES.md` | 20,042 | `9ddf5a18a2bd0dae…` | Network variable keys, remapping and replication | `ivar` / `svar` storage and remapping — context for `VSR_NETVARS.md` |

The other 36 files (`NETWORK-*.md`, `API-REFERENCE.md`, `object-model.json`, …) stay in the local
`BZ_REA` checkout and are cited by name where a cross-check used them.

## How to use

- Read for *what to look for* in the decompile, never for *what to write*.
- Any numeric claim (offset, default, enum value) that ends up in `source/` must be re-derived from
  the decompile or the SDK header and cited to that, not to these files.
- `QA.md` gate 6: reviewers of a port are not shown these files.
