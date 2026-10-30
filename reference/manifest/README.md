# reference/manifest/

Tier B tables derived from GBD's PDBs, the decompile and the repositories. All regenerable.

| Path | Generator | What |
|---|---|---|
| `pdb/SUMMARY.md` | `tools/pdb_strings.py` | per-DLL source-file membership matrix (65 project paths, as stored in the PDBs) |
| `pdb/<dll>.sources.txt` / `.env.txt` / `.other.txt` | `tools/pdb_strings.py` | raw path strings per PDB: project sources, build environment, everything else |
| `pdb/<dll>.modules.tsv` / `.modules.md` | `tools/pdb_modules.py` | one row per linked module: library, compiler version, language, cwd, exact command line, contributing sources |
| `BUILD_ENVIRONMENT.md` | hand-written from the above | toolchain, project tree, per-project compiler/linker flags, image facts |
| `FILE_MAP.md` | hand-written | which ancestor file seeds which VSR file, with line-count deltas |
| `REPO_REFS.txt` | task 2b | every ref + hash of the preservation mirrors, pins marked |
| `strategy02-attempt2/` (`files.tsv`, `functions.tsv`, `strings.tsv`, `namespaces.txt`, `FILES.md`) | `tools/manifest_from_tsv.py` | per-file line bounds / function counts / code bytes, sorted function table, string table — from the decompile's TSVs |
| `lua_api_{LuaMission,Strategy02}.tsv` | received with the decompile | the 92 Lua C-API exports per DLL with RVA/VA |

Regenerate after any decompile run: `python tools/pdb_strings.py && python tools/pdb_modules.py && python tools/manifest_from_tsv.py --set <set>`.