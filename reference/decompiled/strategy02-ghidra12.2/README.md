# strategy02-ghidra12.2 — regenerated decompile of Strategy02.dll (Tier B, verified)

Produced 2026-10-28 on this machine by `tools/ghidra/run_headless.cmd Strategy02` with the pinned portable
Ghidra 12.2 (`tools/ghidra/VERSIONS.txt`: zip SHA-256 `2c2cd776…`, JDK 25.0.5) from
`original/missions/Strategy02.dll` + `.pdb` (`EXPORT_INFO.txt`: executable SHA-256 `a4b3ce22…c45c0b6bb`,
image base `0x4fc00000`, source-line map available). Logs: `ghidra-headless.log`, `ghidra-script.log`.

## Verdict against the received copy (`../strategy02-attempt2`, `DIFF_vs_strategy02-attempt2.md`)

| Aspect | Result |
|---|---|
| Function roster | identical: 1,925 functions, 953 project functions, 48 source files; **0 resized**; the 25 "added/removed" entries are the same 25 CRT thunks with and without their `__` prefix |
| Original-line ranges | identical except an STL helper (`_Orphan_all`) and the ICF-folded shared body of the `ShouldRemove*` predicates (`0x4fc0b065`), whose attributed line depends on which folded copy the line table lists first |
| Strings (`TerminatedCString`) | identical content; the +23/−22 are the same literals with `\n` / `\t` rendered differently by this exporter (fixed for future runs) plus `GetMisnAPI` / `Strategy02.dll` which attempt2 filtered |
| Decompiled text | 84 functions byte-identical, the rest differ in temporaries / formatting as expected between decompiler builds (median similarity 0.94 after normalisation); a second 12.x build (12.1.4, `DIFF_vs_strategy02-ghidra12.1.4.md`) agrees with this one on 731 of 953 |
| `Strategy02::Execute` @ `0x4fc41f90` (orig. lines 2429-3019, 4,819 bytes) | **not decompiled here**: the `decompile` style never finishes under 12.2, 12.1.4 or 11.4.3 (30-minute budget; stripping the PDB-applied locals does not help; the non-C styles complete). The received copy has a clean 793-line decompile of it, so attempt2's producer ran with some analysis state these headless runs do not reproduce. |

**Conclusion.** The received decompile is faithful: everything a port depends on — which functions exist,
their boundaries, their source lines, the string table, the class layouts (which come from the PDB directly,
`reference/manifest/pdb/`) — is reproduced here. `strategy02-attempt2` is therefore **Tier B-verified**, and
the port may cite either set. For `Strategy02::Execute` only the attempt2 text exists; cite it as
*received, not regenerated* until a future Ghidra decompiles it (the kept project under
`out/ghidra-projects/Strategy02-keep` + `tools/ghidra/process_one.cmd` make that a one-command retry).

## Contents

Same shape as attempt2 (`src/**/*.decomp.c`, `all_functions.tsv`, `user_functions.tsv`, `globals.tsv`,
`user_namespaces.txt`, `vsr_types.h`) plus `EXPORT_INFO.txt`. `globals.tsv` lists every non-function symbol
(14,912 rows, vs attempt2's 3,634 named ones). Note Ghidra's `vsr_types.h` here, like attempt2's, carries
both `TeamInfo` generations (`TeamInfo` / `TeamInfo.conflict`) and warns
`Array num elements calculation error 41280 % 2480` — the Java PDB parser built `teamInfo[16]` on the stale
0x9B0 layout; the live 0xA14 layout is in `reference/manifest/pdb/strategy02.types.json`
(`tools/pdb_types.py` takes the newest type record).

Derived tables: `reference/manifest/strategy02-ghidra12.2/` (`tools/manifest_from_tsv.py --set strategy02-ghidra12.2`).
