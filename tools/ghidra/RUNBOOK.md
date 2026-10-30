# tools/ghidra/RUNBOOK.md — regenerating a decompile (Tier B)

The decompile is Tier B: machine-derived from GBD's DLL + PDB (Tier A). It is quoted as fact
only after it has been produced here, by a pinned Ghidra, and diffed against any earlier copy.

## 1. Install (once per machine, nothing system-wide)

```
python tools\ghidra\install.py
```

Downloads the latest Ghidra 11.x PUBLIC zip and a Temurin JDK 21 zip into `tools\_local\downloads\`,
verifies SHA-256, extracts to `tools\_local\ghidra\` and `tools\_local\jdk21\`, and records the exact
versions, URLs and hashes in `tools\ghidra\VERSIONS.txt` (committed). `tools\_local\` is gitignored.
To pin a specific Ghidra release: `--ghidra-url <zip url>`.

## 2. Decompile one DLL

For single-function experiments without re-analysing: `tools\ghidra\analyze_keep.cmd <dll>` builds a
persistent project under `out\ghidra-projects\<dll>-keep`; `tools\ghidra\process_one.cmd <dll> <addr>
<style> <timeout s> <outfile>` decompiles one function from it (`VsrDecompileOne.java`).

```
tools\ghidra\run_headless.cmd Strategy02
tools\ghidra\run_headless.cmd LuaMission
tools\ghidra\run_headless.cmd Instant
tools\ghidra\run_headless.cmd deathmatch01
```

Each run imports `original\missions\<name>.dll` into a fresh headless project (deleted afterwards),
lets the PDB analyzer apply `<name>.pdb` from the same folder (names, types, source lines), runs
full auto-analysis, then `VsrExportDecompile.java` writes to
`reference\decompiled\<name>-ghidra<version>\`:

| Output | Content |
|---|---|
| `src/<orig path>.decomp.c` | one file per original source file, functions ordered by source line, each headed `// Name @ addr lines a-b` |
| `all_functions.tsv` | `address size user name file minLine maxLine` for every function (user = path under `vsr_dll_source`) |
| `user_functions.tsv` | `file minLine maxLine address size name signature` for the project's functions |
| `globals.tsv` | `address name type value` for every non-function symbol |
| `user_namespaces.txt` | the project's namespaces / classes |
| `vsr_types.h` | every data type as C (`DataTypeWriter`) |
| `EXPORT_INFO.txt` | program hash, image base, Ghidra version, counts |
| `ghidra-headless.log`, `ghidra-script.log` | the run's logs |

Source-line mapping needs Ghidra ≥ 11.2 (`SourceFileManager`); `EXPORT_INFO.txt` says whether it was
available (`source_map_api: yes`). Without it the `file` / line columns are empty and the export is
not comparable to attempt2.

## 3. Diff against the previous copy

```
python tools\diff_decompile.py reference\decompiled\strategy02-attempt2 reference\decompiled\strategy02-ghidra<ver>
```

writes `reference\decompiled\<new>\DIFF_vs_<old>.md`: function roster delta (added / removed /
renamed / resized), per-file line-range changes, string-table delta, and the decompiled-text diff
size per function. Record the verdict in the new folder's `README.md` and in `STATUS.md`
("promoted to Tier B-verified" or the list of differences and their explanation), then regenerate the
manifest tables:

```
python tools\manifest_from_tsv.py --set strategy02-ghidra<ver>
```

## 4. Hygiene

- Never edit anything under `reference\decompiled\*` by hand; re-run instead.
- The headless project lives under `out\ghidra-projects\` (gitignored) and is deleted after each run.
- Ghidra's PDB analyzer must find the PDB; if `ghidra-headless.log` shows "PDB not found", the DLL
  and PDB are not side by side or the PDB's GUID/age does not match the DLL — check
  `original\missions\SHA256SUMS.txt`.
- The exe's protection layer is irrelevant here: only the DLLs are analysed.
