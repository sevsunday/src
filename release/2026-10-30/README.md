# Built binaries — 2026-10-30

The four VSR mission DLLs built from the `source/` tree committed together
with this folder, with their PDBs, for anyone who wants to run the
reconstruction without building it. `SHA256SUMS.txt` lists every file.

| File | Size | SHA-256 | Tested |
|---|---|---|---|
| `Strategy02.dll` | 452,096 | `d347a17d…1a3a57`¹ | **yes** — same code as the binary that passed the two-machine lockstep A/B against GBD's DLL in both roles (`STATUS.md` → Parity results), and in use for team-strat games |
| `LuaMission.dll` | 419,840 | `2066a8e7…25ca6f` | built, strict gates pass, not lockstep-tested |
| `Instant.dll` | 434,176 | `81a96611…3e3b67` | built, strict gates pass, not lockstep-tested |
| `deathmatch01.dll` | 437,760 | `7857fcff…309214` | built, strict gates pass, not lockstep-tested |

¹ Full hashes in `SHA256SUMS.txt`.

Only `Strategy02.dll` (team strat) is inside the project's tested scope. The
other three load and pass the mechanical gates (symbol roster, string table,
exports, imports, struct-layout asserts) but have not been played against
GBD's originals.

## How these were built

- Source: the `source/` tree in the commit that added this folder.
- Compiler / linker: MSVC 19.44.35222 (Visual Studio 2022 17.14, x86), flags as
  in `build/build.cmd` (`/O1 /Ob2 /Oi /Os /Oy- /GL /MD /GS /arch:SSE2 /fp:precise`;
  link `/LTCG /OPT:REF /OPT:ICF /BASE:0x4FC00000 /DYNAMICBASE /NXCOMPAT /SAFESEH`).
- BZCC SDK (`ScriptUtils.h` / `AiCmds.h` / `battlezone2.lib` from the game folder):
  the 2.0.206.10 `devtest` set, `ScriptUtils.h` 133,906 bytes
  `4428B2AA5C7B6772EF9848D36954A1EB3B156A300A96189ED576D1C922BBAA70`,
  `battlezone2.lib` 311,350 bytes
  `15EA6C6EE755E8724C87D62BF668B9CB5E32CAF676B0F363ECE53E6E78046D32`
  (`DEPENDENCIES.md` D5). The lockstep-tested binary was compiled against the
  2.0.185 set; `tools/compare_pe.py` shows the two SDKs produce the **same code**
  for all four DLLs — `.text`, `.data`, exports, imports and every relocated
  constant identical — so the SDK difference is settled and the 2.0.185 pin is
  no longer a build prerequisite.
- Linked with `/PDBALTPATH:%_PDB%` and `/Brepro`, so a DLL carries only its
  PDB's file name and a content-derived timestamp: with the same toolset and
  SDK, a clean build from **any** checkout path reproduces all four DLLs byte
  for byte (verified from two different paths). Only the PDBs record the
  checkout path; the released ones were built from a neutral drive root
  (`V:\source\…`). The PDBs also contain the toolchain's own paths
  (`C:\Program Files\Microsoft Visual Studio\…`, the Steam game folder as an
  include directory, Microsoft's CRT source paths `D:\a\…`), which are the
  same on any machine with that toolset. A PDB is not byte-reproducible (the
  type-record order varies between runs) but a rebuilt one carries the same
  GUID and age as the released DLL's RSDS record, so either PDB serves it.
- Gates at build time: `build.cmd check` — `check_no_thirdparty` 0 findings,
  `check_status` 65 ported, `check_symbol_parity --strict` OK,
  `check_strings --strict` OK (2341 / 2247 / 2290 / 2298 strings, 0 missing,
  0 extra).

Why the `Strategy02.dll` hash is not the lockstep run's `ee340b6e…`: that
binary was linked without `/PDBALTPATH` and `/Brepro`, so its debug record held
the build machine's full PDB path and a wall-clock timestamp. Relinking the
same objects with those two flags changes only the linker's metadata (debug
directory, export-directory timestamp, and the addresses that point at the
moved metadata); `tools/compare_pe.py` on the two files reports `EQUIVALENT`
with 0 mismatches over 410,256 compared bytes.

## Installing

1. Put the DLL (and, if you want readable crash dumps, its `.pdb`) in the
   engine's user addon override folder:
   `<Documents>\My Games\Battlezone Combat Commander\addon\missions\`
   (create `addon\missions` if absent; `<Documents>` is the shell's Documents
   folder, which may be redirected — the engine prints the path it uses as
   `@mydocsdir` in its log). The engine prefers that folder over the Workshop
   copy; the Steam install is never touched.
2. Check the hash: `certutil -hashfile Strategy02.dll SHA256` must print the
   value in `SHA256SUMS.txt`.
3. The DLL loads when a map starts, not in the lobby. To confirm which copy
   is in use, open the file for writing while a game is running — the loaded
   copy is locked (win32 error 32); renaming is not a test, Windows allows it
   on a mapped image. Script in `tools/parity/RUNBOOK.md`.
4. If `My Games` is a cloud-synced folder shared between two PCs, both PCs
   silently load the same copy (`tools/parity/RUNBOOK.md` §0b).

## Rebuilding and checking

```
set BZCC_DIR=C:\Program Files (x86)\Steam\steamapps\common\BZ2R
build\build.cmd all
build\build.cmd check
python tools\compare_pe.py release\2026-10-30\Strategy02.dll out\Win32\Release\bin\missions\Strategy02.dll
```

`compare_pe.py` exits 0 and prints `EQUIVALENT` when a rebuild is the same code
as the released file; with the same toolset version and SDK the DLLs come out
byte-identical and `certutil -hashfile` alone settles it.
