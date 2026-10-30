# BUILD_ENVIRONMENT — how GBD built the shipped DLLs (Tier B, read from the PDBs)

Everything here is read from `original/missions/*.pdb` by `tools/pdb_modules.py` (MSF → DBI →
per-module `S_COMPILE3` / `S_BUILDINFO` → IPI `LF_BUILDINFO`) and `tools/pdb_strings.py`, plus
`dumpbin` on the DLLs. Regenerate with `python tools/pdb_modules.py` after any change to the
originals; the per-module tables are `pdb/<dll>.modules.{tsv,md}`.

## Toolchain

| Item | Value |
|---|---|
| IDE | Visual Studio 2017 Community (15.9) — `C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\` |
| Compiler | `cl.exe` 19.16.27054.0 (toolset `VC\Tools\MSVC\14.16.27023`, `bin\HostX86\x86\CL.exe`) |
| Linker | `link.exe` 14.16.27054.0; `cvtres.exe` 14.16.27054.0 |
| C runtime | Universal CRT 10.0.10240 (`Windows Kits\10\Include\10.0.10240.0\ucrt`, `Lib\10.0.10240.0\ucrt\x86\ucrt.lib`) |
| Win32 SDK | Windows 8.1 SDK (`Windows Kits\8.1\Include\{um,shared,winrt}`, `Lib\winv6.3\um\x86\kernel32.lib`) + NETFXSDK 4.6.1 include |
| CRT model | **dynamic** — `MSVCRT.lib` / `msvcprt.lib` / `vcruntime.lib` (`/MD`): the DLLs import `MSVCP140.dll`, `VCRUNTIME140.dll` and 11 `api-ms-win-crt-*-l1-1-0.dll` |
| Target | x86-32, `__cdecl` default (`-Gd`), `__thiscall` methods |
| Link time | 2026-02-20 16:26:58–59 UTC (all four, one build) |

## Project tree (from `cwd` and output paths)

```
E:\Github\VSR_DLL_Source\
  Missions\Strategy02\      Missions\LuaMission\    Missions\Instant\    Missions\Deathmatch01\
  Missions\VSRCore\         Missions\LuaMissionLib\
  Missions\Release\VSRCore.lib   Missions\Release\LuaMissionLib.lib        (static-lib outputs)
  Debug\battlezone2.lib     debug\lua51_lib.lib                           (import lib + prebuilt Lua)
  Build\Win32\Release\obj\<Project>\<Project>.lib|.exp                     (intermediates)
  Build\Win32\Release\bin\missions\<Project>.dll|.pdb                      (outputs)
  Source\CORE\graphics\DXUT\dx11                                           (an inherited -I; nothing used)
```

Source paths are stored lowercase in the PDB string table (`e:\github\vsr_dll_source\missions\…`);
module and output names keep GBD's casing (`Missions\Strategy02`, `VSRCore.lib`). This repo uses
lowercase `source/missions/…` and `out/` for outputs (NTFS would fold `Build` onto `build`).

## Per-project compiler command lines (verbatim `LF_BUILDINFO` args, `-I` list elided)

**Mission DLL projects** — `Strategy02`, `LuaMission`, `Instant`, `Deathmatch01`
(objects: the project's own `.cpp` + its `shared\` members; for `LuaMission` also
`LuaMission.obj` + `LuaBindings.obj` compiled directly):

```
-c -IE:\Github\VSR_DLL_Source\Source\CORE\graphics\DXUT\dx11 -Zi -nologo -W4 -WX- -diagnostics:classic
-O1 -Ob2 -Oi -Os -Oy- -GL -DWIN32 -DNDEBUG -D_WINDOWS [-D_USRDLL -D<PROJECT>_EXPORTS] -D_VC80_UPGRADE=0x0710
-D_WINDLL [-D_MBCS] -DBZ2_USEDX11PHASE2=0 -DWINVER=0x0600 -D_WIN32_WINNT=0x0600 -D_CRT_SECURE_NO_WARNINGS=1
-GF -Gm- -EHs -EHc -MD -GS -arch:SSE2 -fp:precise -Zc:wchar_t -Zc:forScope -Zc:inline -Gd -TP
-wd4530 -wd4800 -analyze- -FC -errorreport:prompt -I"<MSVC include>" -I"<atlmfc>" -I"<Auxiliary\VS\include>"
-I"<ucrt 10.0.10240.0>" -I"<UnitTest>" -I"<8.1 um>" -I"<8.1 shared>" -I"<8.1 winrt>" -I"<NETFXSDK 4.6.1 um>" -X
```

| Project | own defines beyond the common set |
|---|---|
| `Strategy02` | `-D_WINDLL` only (no `_USRDLL`, no `_EXPORTS`, no `_MBCS`) |
| `LuaMission` | `-D_USRDLL -DLUAMISSION_EXPORTS -D_WINDLL -D_MBCS` |
| `Instant` | `-D_USRDLL -DINSTANT_EXPORTS -D_WINDLL -D_MBCS` |
| `Deathmatch01` | `-D_USRDLL -DDEATHMATCH01_EXPORTS -D_WINDLL -D_MBCS` |

Optimization is **MinSpace** (`-O1 -Ob2 -Oi -Os -Oy-`), as in the 1.3 pack's Release configuration,
with whole-program optimization (`-GL`). No `-std:` (VS2017 default C++14), no `-permissive-`, no `-Gy`.

**`VSRCore.lib`** (cwd `Missions\VSRCore`; 20 helper objects + `Taunts.obj`):

```
-c -Zi -nologo -W4 -WX- -diagnostics:classic -O1 -Ob2 -Oi -Os -Oy -GL -DWIN32 -DNDEBUG -D_WINDOWS -D_MBCS
-GF -Gm- -MD -GS -Gy -arch:SSE -fp:precise -Zc:wchar_t -Zc:forScope -Zc:inline -Gd -TP -wd4530 -wd4800
-analyze- -FC -errorreport:prompt -I… -X
```

Differences from the DLL projects: **no `-EHs -EHc`** (C++ exception handling off — `-wd4530` silences
the STL warning that results), `-Oy` (frame pointers omitted), `-Gy` (function-level linking),
`-arch:SSE` (not SSE2), and none of the `WINVER` / `_WIN32_WINNT` / `BZ2_USEDX11PHASE2` /
`_CRT_SECURE_NO_WARNINGS` defines.

**`LuaMissionLib.lib`** (cwd `Missions\LuaMissionLib`; `LuaMission.obj`, `LuaBindings.obj`): the
mission-DLL command line with `-D_USRDLL -DLUAMISSION_EXPORTS -DLUA_LIB -D_MBCS` and no `-D_WINDLL`.
Linked into `Strategy02`, `Instant`, `Deathmatch01`; `LuaMission.dll` compiles the same two files
itself instead.

**`lua51_lib.lib`** (`E:\Github\VSR_DLL_Source\debug\lua51_lib.lib`): 32 Lua objects
(`lapi … lzio`, `lbaselib … lstrlib`, `linit`) with **no compiler record** in the PDB — a prebuilt
library from the BZCC engine tree (`e:\bzcc\battlezone2\source_3rdparty\lua\src\*.c` appear as
sources of `LuaBindings.obj` only because LTCG inlined them). The DLLs import `_setjmp3` / `longjmp`,
so this Lua was compiled as **C** (longjmp error handling), despite the library's "51" name the
embedded version string is `Lua 5.2` and the 92 exported symbols are the 5.2 API.

## Linker command line (verbatim, `Strategy02`; the others differ only in names)

```
/ERRORREPORT:PROMPT /OUT:E:\Github\VSR_DLL_Source\Build\Win32\Release\bin\missions\Strategy02.dll
/INCREMENTAL:NO /NOLOGO /MANIFEST "/MANIFESTUAC:level='asInvoker' uiAccess='false'" /manifest:embed
/DEBUG /PDB:E:\Github\VSR_DLL_Source\Build\Win32\Release\bin\missions\Strategy02.pdb /SUBSYSTEM:WINDOWS
/OPT:REF /OPT:ICF /LTCG:incremental /TLBID:1 /BASE:0x4fC00000 /DYNAMICBASE /FIXED:NO /NXCOMPAT
/IMPLIB:E:\Github\VSR_DLL_Source\Build\Win32\Release\obj\Strategy02\Strategy02.lib /MACHINE:X86 /SAFESEH
/DYNAMICBASE /DLL
```

(`LuaMission`, `Instant`, `deathmatch01` omit the explicit `/SUBSYSTEM:WINDOWS`; all four images are
subsystem 2.) Inputs per DLL (from the module list): the project's objects, `VSRCore.lib`,
`LuaMissionLib.lib` (except `LuaMission.dll`), `lua51_lib.lib`, `Debug\battlezone2.lib`,
`kernel32.lib`, `MSVCRT.lib`, `msvcprt.lib`, `vcruntime.lib`, `ucrt.lib`, plus a linker-generated
manifest resource (the only `.rsrc` content — there is no `VERSIONINFO`).

## Resulting images

| | Strategy02 | LuaMission | Instant | deathmatch01 |
|---|---|---|---|---|
| Image base | `0x4FC00000` | `0x4FC00000` | `0x4FC00000` | `0x4FC00000` |
| Size of image | `0x82000` | `0x79000` | `0x7C000` | `0x81000` |
| DLL characteristics | `0x140` (DYNAMIC_BASE, NX_COMPAT) | same | same | same |
| Export | `GetMisnAPI` | `GetMisnAPI` | `GetMisnAPI` | `GetMisnAPI` |
| Modules in PDB | 126 | 125 | 126 | 129 |

The shared base makes every RVA in the decompile a plain `VA − 0x4FC00000`.

## What this repository does with it

`build/build.cmd` reproduces the switches per project (minus the cosmetic `-nologo
-diagnostics:classic -FC -errorreport:prompt -analyze-`, minus `-Gm-` which the 14.4x toolset no longer
accepts, and minus the unused DXUT include), the per-DLL membership above, and the linker line with
plain `/LTCG`. The SDK is 10.0.26100 instead of 8.1 + UCRT 10240 and the compiler is 19.4x instead of
19.16; both are recorded in `STATUS.md` as known, accepted differences — symbol parity (QA gate 3)
is judged on the function roster, not on byte identity.
