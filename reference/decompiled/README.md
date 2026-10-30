# reference/decompiled/

Tier B. PDB-symbolized Ghidra decompiles of the shipped DLLs, produced by `tools/ghidra/` on this machine
(runbook `tools/ghidra/RUNBOOK.md`; pinned versions `tools/ghidra/VERSIONS.txt`). Each set's `README.md`
records its provenance and verdict.

| Set | DLL | Status |
|---|---|---|
| `strategy02-attempt2/` | Strategy02.dll | received copy, **Tier B-verified** against `strategy02-ghidra12.2` (task 8); the only text of `Strategy02::Execute` |
| `strategy02-ghidra12.2/` | Strategy02.dll | regenerated here (task 8); `Strategy02::Execute` not decompilable by 12.2 / 12.1.4 / 11.4.3 |
| `luamission-ghidra12.2/` | LuaMission.dll | produced here (task 13); 901 / 901 functions decompiled |
| `instant-ghidra12.2/` | Instant.dll | produced here (task 13); 932 / 932 |
| `deathmatch01-ghidra12.2/` | deathmatch01.dll | produced here (task 13); 960 / 960 |

The shared `shared/` / `vsrcore/` / `luamission/` source has identical original-line ranges in all four
DLLs (one source tree, four links); a function's code size may differ between sets because LTCG decides
inlining per link. A sub-folder is not quoted as fact until it has been produced by `tools/ghidra/` on this
machine and, where an earlier copy exists, diffed against it.
