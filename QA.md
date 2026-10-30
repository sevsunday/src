# QA — gates and checklists

Every port task passes these gates before a file's `STATUS.md` state advances.
The gates are mechanical where they can be and reviewed where they cannot.

## State machine (per source file)

```
stub  →  ported  →  reviewed  →  compiles  →  parity
```

- **stub** — the file exists with PDB-true declarations; every function body
  not yet ported keeps the PDB signature, a `// DECOMPILE: <file>:<line>`
  pointer and a safe default return.
- **ported** — every function body has been brought to VSR from its ancestor
  against the decompile (checklist 1 complete for every function).
- **reviewed** — a second pass by a reviewer shown only Tier A / A′ / B
  evidence and the port (gate 6).
- **compiles** — builds in all targets that include it with zero new warnings
  under `/W4`, layout asserts passing (gate 2).
- **parity** — symbol, string and export gates green for its DLL and the
  lockstep A/B session clean (gates 3, 4, 8).

## Gate 1 — per-function checklist

For every function in the file:

- [ ] Signature identical to the PDB (name, parameters, calling convention,
      const-ness, return type).
- [ ] Control flow and constants match the regenerated decompile
      (`reference/decompiled/`), including loop bounds, clamp ranges, default
      values and the order of side effects.
- [ ] Every string literal the function uses appears in `globals.tsv` with
      the same text (format strings, ODF section and key names, console
      messages, localized-string keys).
- [ ] ODF section / key names and their defaults match the decompile.
- [ ] `Save` / `Load` write order, element widths and counts match the
      decompile (`b_count` / `f_count` / `h_count` / `i_count` ranges and
      the `*LIST MISMATCH` field order).
- [ ] GBD's Lua port agrees wherever it covers the function.
- [ ] The ancestor diff has been read line by line; no ancestor-era
      behaviour that VSR removed survives, and no VSR addition is missing.
- [ ] The `// PROVENANCE:` header names ancestor, decompile range and
      Lua-port cross-check.

## Gate 2 — layout asserts

`tools/layout_asserts.py` reads the PDB-derived type dump and emits
`static_assert(sizeof(T) == N)` and `static_assert(offsetof(T, f) == N)` for
every recovered struct and class. The generated header is included by every
translation unit. Known anchors:

| Type | sizeof |
|---|---:|
| `Strategy02` | `0xECA4` |
| `TeamInfo` | `0xA14` |
| `MapInfo` | `0x48` |
| `ObjectClass` | `0x5C` |
| `VehicleClass` | `0x54` |
| `BuildingClass` | `0x458` |
| `PowerClass` | `0x28` |
| `PowerupClass` | `0x104` |
| `AttacherClass` | `0x40C` |
| `UtilityShipClass` | `0x2C` |
| `DispatchClass` | `0x148` |
| `MorphObjectClass` | `0x148` |
| `UndeployClass` | `0x10` |
| `CarrierClass` | `0x30` |
| `DroneClass` | `0x2C` |
| `GravityInfo` | `0x14` |
| `AmbientAudioInfo` | `0x70` |
| `ScrapClass` | `0x4` |
| `PortalClass` | `0x390` |
| `TeleportTargetClass` | `0x14` |
| `AttacherTapClass` | `0x80` |

(All from the live TPI generation, `reference/manifest/pdb/<dll>.types.md`; `source/missions/shared/vsr_layout_asserts.h` pins every one.)
The build fails on any mismatch.

## Gate 3 — symbol parity

`tools/check_symbol_parity.py` extracts the function roster (name, signature,
file membership) from our build's PDB and from GBD's PDB for the same DLL and
diffs them. Every difference is either fixed or explained in `STATUS.md`.
Compiler-generated and STL symbols are compared by count only.

## Gate 4 — string parity

`tools/check_strings.py` requires every literal in the original DLL's string
table to appear in ours, and flags every extra literal in ours. Lua internals
and CRT strings are compared by count only.

## Gate 5 — no third-party code

`tools/check_no_thirdparty.py` fails on any identifier, header name or
comment marker that belongs to the VRV mod or to `BZ_REA` tooling anywhere
under `source/`. The forbidden list lives in the script.

## Gate 6 — independent review

Each tier gets a second review pass. The reviewer sees only Tier A / A′ / B
evidence (ancestor, decompile, PDB tables, Lua port) and the port itself —
never Tier C. The reviewer re-runs checklist 1 on every function and signs the
file's row in `STATUS.md`.

## Gate 7 — facts in documents

Every number or behaviour quoted in `docs/` or in the analysis documents is
either cited to a Tier A / A′ / B `file:line` or commit, or labelled
`[third-party, unverified]`. Numbers first obtained from an automated survey
are re-read from the primary source before being quoted.

## Gate 8 — export table and lockstep parity

- `dumpbin /exports` (or the equivalent PE read in `tools/parity/`) shows a
  single export `GetMisnAPI` on each DLL; `dumpbin /dependents` shows the same
  CRT family as the originals (`MSVCP140` / `VCRUNTIME140` / `api-ms-win-crt-*`,
  i.e. `/MD`).
- `GetMisnAPI` fills `MisnExport.version = 0x4C89322E` and
  `VersionModifier = 'BAL1'`.
- Save-record sizes match (`Strategy02::Save` counts and the `BZ1Helper`
  array ranges).
- The `VSR_<timestamp>.log` strings match the original DLL's when logging is
  enabled.
- LAN A/B: original DLL on one machine, ours on the other, on VSR maps from
  the installed Workshop items. Any `CRC Mismatch` or resync is a failure.
  Results per DLL and per map are recorded in `STATUS.md`.

## Running the gates

```
build\build.cmd check
```

runs gates 2–5 and the export-table half of gate 8. Gate 6 is a human step.
The lockstep half of gate 8 follows `tools/parity/RUNBOOK.md`.

```
python tools\compare_pe.py release\<date>\Strategy02.dll out\Win32\Release\bin\missions\Strategy02.dll
```

answers whether a rebuild is the same code as a released, tested binary:
`EQUIVALENT` means `.text` / `.data` / exports / imports / relocated constants
all match and only the linker's debug metadata differs. Run it after any
toolchain or SDK change before treating a rebuild as the tested one.
