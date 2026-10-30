@echo off
setlocal EnableDelayedExpansion
rem ===========================================================================
rem  VSR_DLL_Source build  -  the only build entry point.
rem
rem  Everything below mirrors what GBD's PDBs record (tools/pdb_modules.py ->
rem  reference/manifest/pdb/*.modules.md): projects, per-project compiler
rem  flags, link membership and linker flags. VS 2017 15.9 (cl 19.16.27054,
rem  link 14.16.27054) built the originals; we use the MSVC 14.4x toolset with
rem  the same switches.
rem
rem  Projects (cwd in the PDB = Missions\<Project>):
rem     lua52.lib          <- third_party\lua-5.2.4\src\*.c (minus lua.c, luac.c)
rem                           [GBD linked a prebuilt lua51_lib.lib from the BZCC
rem                            engine tree, compiled as C: the DLL imports
rem                            _setjmp3/longjmp. No flags recorded -> ours.]
rem     VSRCore.lib        <- source\missions\vsrcore\*.cpp + shared\taunts.cpp
rem     LuaMissionLib.lib  <- source\missions\luamission\*.cpp
rem     Strategy02.dll     <- strategy02.cpp + shared{dllbase,dllutils,startingvehicles,trnallies}
rem                           + LuaMissionLib.lib + VSRCore.lib (Taunts comes from here) + lua
rem     LuaMission.dll     <- luamission.cpp + luabindings.cpp (compiled directly, no LuaMissionLib.lib)
rem                           + shared{dllbase,taunts,trnallies} + VSRCore.lib + lua
rem     Instant.dll        <- instantmission.cpp + shared{dllbase,taunts,trnallies}
rem                           + LuaMissionLib.lib + VSRCore.lib + lua
rem     deathmatch01.dll   <- deathmatch01.cpp + shared{dllbase,dllutils,pupmgr,taunts,trace,trnallies}
rem                           + LuaMissionLib.lib + VSRCore.lib + lua
rem     every DLL          +  %BZCC_DIR%\battlezone2.lib
rem
rem  Usage:  build.cmd [all | stub | lua | core | lualib | strategy02 | luamission
rem                     | instant | deathmatch01 | check | clean]
rem          (default: all)
rem  Needs:  %BZCC_DIR% = BZCC install (ScriptUtils.h, AiCmds.h, battlezone2.lib)
rem          Visual Studio 2022 with the MSVC x86 toolset + a Windows 10/11 SDK
rem  Output: out\Win32\Release\bin\missions\*.dll (+ .pdb)        [gitignored]
rem          out\Win32\Release\bin\stub\Strategy02.dll for "stub"
rem          (GBD's tree used Build\...; NTFS is case-insensitive, so "Build"
rem           would be this very folder - hence "out".)
rem ===========================================================================

set "ROOT=%~dp0.."
for %%I in ("%ROOT%") do set "ROOT=%%~fI"
set "SRC=%ROOT%\source\missions"
set "LUASRC=%ROOT%\third_party\lua-5.2.4\src"
set "OUT=%ROOT%\out\Win32\Release"
set "OBJ=%OUT%\obj"
set "BIN=%OUT%\bin\missions"
set "LIBDIR=%OUT%\lib"

set "MODE=%~1"
if "%MODE%"=="" set "MODE=all"

if /i "%MODE%"=="clean" (
    echo [build] removing "%ROOT%\out"
    if exist "%ROOT%\out" rmdir /s /q "%ROOT%\out"
    exit /b 0
)

if /i "%MODE%"=="check" goto :check

rem ---------------------------------------------------------------- toolchain
call :find_vs || exit /b 1

if not defined BZCC_DIR (
    if exist "C:\Program Files (x86)\Steam\steamapps\common\BZ2R\ScriptUtils.h" (
        set "BZCC_DIR=C:\Program Files (x86)\Steam\steamapps\common\BZ2R"
    ) else (
        echo [build] ERROR: BZCC_DIR is not set and the default Steam path was not found.
        exit /b 1
    )
)
for %%F in (ScriptUtils.h AiCmds.h battlezone2.lib) do (
    if not exist "%BZCC_DIR%\%%F" (
        echo [build] ERROR: "%BZCC_DIR%\%%F" not found. BZCC_DIR must point at the game install.
        exit /b 1
    )
)
echo [build] BZCC_DIR = %BZCC_DIR%

rem ---------------------------------------------------------------- flags
rem  Recorded compiler command lines (LF_BUILDINFO in the PDBs), minus the
rem  cosmetic switches (-nologo -diagnostics:classic -FC -errorreport:prompt
rem  -analyze- -Gm- which is gone from the toolset) and the inherited, unused
rem  -IE:\...\Source\CORE\graphics\DXUT\dx11 include. No -std switch was used
rem  (VS2017 default = C++14, same default on 14.4x), no -permissive-.
rem  /wd4471: ScriptUtils.h(90) forward-declares an unscoped enum (PathType)
rem           without an underlying type - SDK header, not our code (ours only).
set "COMMON_DEFS=/D WIN32 /D NDEBUG /D _WINDOWS /D BZ2_USEDX11PHASE2=0 /D WINVER=0x0600 /D _WIN32_WINNT=0x0600 /D _CRT_SECURE_NO_WARNINGS=1 /D _VC80_UPGRADE=0x0710"
rem  Mission-DLL projects: -O1 -Ob2 -Oi -Os -Oy- -GL -EHs -EHc -MD -GS -arch:SSE2 -fp:precise -TP (no -Gy)
set "CXXFLAGS_DLL=/nologo /c /Zi /FS /W4 /WX- /wd4471 /O1 /Ob2 /Oi /Os /Oy- /GL %COMMON_DEFS% /GF /EHsc /MD /GS /arch:SSE2 /fp:precise /Zc:wchar_t /Zc:forScope /Zc:inline /Gd /TP /wd4530 /wd4800"
rem  VSRCore.lib: -O1 -Ob2 -Oi -Os -Oy -GL -MD -GS -Gy -arch:SSE -fp:precise -TP, NO -EHs -EHc, defines WIN32 NDEBUG _WINDOWS _MBCS only
set "CXXFLAGS_CORE=/nologo /c /Zi /FS /W4 /WX- /wd4471 /O1 /Ob2 /Oi /Os /Oy /GL /D WIN32 /D NDEBUG /D _WINDOWS /D _MBCS /D _CRT_SECURE_NO_WARNINGS=1 /GF /MD /GS /Gy /arch:SSE /fp:precise /Zc:wchar_t /Zc:forScope /Zc:inline /Gd /TP /wd4530 /wd4800"
rem  LuaMissionLib.lib: DLL flags + -D_USRDLL -DLUAMISSION_EXPORTS -DLUA_LIB -D_MBCS (no _WINDLL)
set "CXXFLAGS_LUALIB=%CXXFLAGS_DLL% /D _USRDLL /D LUAMISSION_EXPORTS /D LUA_LIB /D _MBCS"
set "CXXINC=/I "%BZCC_DIR%" /I "%SRC%" /I "%SRC%\shared" /I "%SRC%\vsrcore" /I "%SRC%\luamission" /I "%LUASRC%""
rem  Third-party Lua is C (longjmp error handling, like the original's lua51_lib). /GL so LTCG can inline it as it did.
set "CFLAGS_LUA=/nologo /c /Zi /FS /W3 /O1 /Ob2 /Oi /Os /Oy- /GL /TC /D WIN32 /D NDEBUG /D _WINDOWS /D _LIB /D _CRT_SECURE_NO_WARNINGS /GF /MD /GS /arch:SSE2 /fp:precise"
rem  Linker (recorded): /INCREMENTAL:NO /MANIFEST /MANIFESTUAC:"level='asInvoker' uiAccess='false'" /manifest:embed
rem  /DEBUG /SUBSYSTEM:WINDOWS /OPT:REF /OPT:ICF /LTCG:incremental /TLBID:1 /BASE:0x4fC00000 /DYNAMICBASE
rem  /FIXED:NO /NXCOMPAT /MACHINE:X86 /SAFESEH /DLL. We use plain /LTCG (no .iobj state).
rem  Added for the release binaries (no effect on generated code): /PDBALTPATH:%%_PDB%% records only
rem  the PDB's file name in the DLL's debug directory instead of the build machine's full path, and
rem  /Brepro makes the PE timestamp and PDB GUID a hash of the content so a rebuild from the same
rem  inputs reproduces the same bytes.
set "LINKFLAGS=/nologo /DLL /MACHINE:X86 /SUBSYSTEM:WINDOWS /INCREMENTAL:NO /DEBUG /OPT:REF /OPT:ICF /LTCG /TLBID:1 /BASE:0x4FC00000 /DYNAMICBASE /FIXED:NO /NXCOMPAT /SAFESEH /MANIFEST /MANIFESTUAC:"level='asInvoker' uiAccess='false'" /manifest:embed /PDBALTPATH:%%_PDB%% /Brepro"

if not exist "%OBJ%" mkdir "%OBJ%"
if not exist "%BIN%" mkdir "%BIN%"
if not exist "%LIBDIR%" mkdir "%LIBDIR%"
rem  The linker compiles the embedded manifest through CVTRES from a file in %%TEMP%% and records
rem  that path in the PDB. Keep it under the output tree so no user-profile path lands in a PDB.
set "TEMP=%OUT%\tmp"
set "TMP=%OUT%\tmp"
if not exist "%TEMP%" mkdir "%TEMP%"

rem ---------------------------------------------------------------- dispatch
if /i "%MODE%"=="stub"         ( call :build_stub & exit /b !errorlevel! )
if /i "%MODE%"=="lua"          ( call :build_lua & exit /b !errorlevel! )
if /i "%MODE%"=="core"         ( call :build_core & exit /b !errorlevel! )
if /i "%MODE%"=="lualib"       ( call :build_lualib & exit /b !errorlevel! )
if /i "%MODE%"=="strategy02"   ( call :need_libs && call :dll_strategy02   & exit /b !errorlevel! )
if /i "%MODE%"=="luamission"   ( call :need_libs && call :dll_luamission   & exit /b !errorlevel! )
if /i "%MODE%"=="instant"      ( call :need_libs && call :dll_instant      & exit /b !errorlevel! )
if /i "%MODE%"=="deathmatch01" ( call :need_libs && call :dll_deathmatch01 & exit /b !errorlevel! )
if /i not "%MODE%"=="all" (
    echo [build] ERROR: unknown mode "%MODE%"
    exit /b 1
)

call :build_lua        || exit /b 1
call :build_core       || exit /b 1
call :build_lualib     || exit /b 1
call :dll_strategy02   || exit /b 1
call :dll_luamission   || exit /b 1
call :dll_instant      || exit /b 1
call :dll_deathmatch01 || exit /b 1
echo.
echo [build] all four DLLs built into "%BIN%"
exit /b 0

rem ---------------------------------------------------------------- targets
rem  :build_dll <Name> <own-dir> "<own .cpp list>" "<shared .cpp list>" "<extra defines>" "<extra libs>"
:dll_strategy02
call :build_dll Strategy02 strategy02 "strategy02.cpp" "dllbase.cpp dllutils.cpp startingvehicles.cpp trnallies.cpp" "/D _WINDLL" ""%LIBDIR%\LuaMissionLib.lib""
exit /b !errorlevel!
:dll_luamission
call :build_dll LuaMission luamission "luamission.cpp luabindings.cpp" "dllbase.cpp taunts.cpp trnallies.cpp" "/D _USRDLL /D LUAMISSION_EXPORTS /D _WINDLL /D _MBCS" ""
exit /b !errorlevel!
:dll_instant
call :build_dll Instant instant "instantmission.cpp" "dllbase.cpp taunts.cpp trnallies.cpp" "/D _USRDLL /D INSTANT_EXPORTS /D _WINDLL /D _MBCS" ""%LIBDIR%\LuaMissionLib.lib""
exit /b !errorlevel!
:dll_deathmatch01
call :build_dll deathmatch01 deathmatch01 "deathmatch01.cpp" "dllbase.cpp dllutils.cpp pupmgr.cpp taunts.cpp trace.cpp trnallies.cpp" "/D _USRDLL /D DEATHMATCH01_EXPORTS /D _WINDLL /D _MBCS" ""%LIBDIR%\LuaMissionLib.lib""
exit /b !errorlevel!

rem ===========================================================================
:find_vs
set "VSWHERE=%ProgramFiles(x86)%\Microsoft Visual Studio\Installer\vswhere.exe"
if not exist "%VSWHERE%" (
    echo [build] ERROR: vswhere.exe not found; is Visual Studio 2022 installed?
    exit /b 1
)
set "VSROOT="
for /f "usebackq delims=" %%I in (`"%VSWHERE%" -latest -products * -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 -property installationPath`) do set "VSROOT=%%I"
if not defined VSROOT (
    echo [build] ERROR: no Visual Studio with the MSVC x86/x64 toolset found.
    echo [build]        Install "MSVC v143 - VS 2022 C++ x64/x86 build tools" via the VS Installer.
    exit /b 1
)
set "VCENV="
if exist "%VSROOT%\VC\Auxiliary\Build\vcvarsamd64_x86.bat" set "VCENV=%VSROOT%\VC\Auxiliary\Build\vcvarsamd64_x86.bat"
if not defined VCENV if exist "%VSROOT%\VC\Auxiliary\Build\vcvars32.bat" set "VCENV=%VSROOT%\VC\Auxiliary\Build\vcvars32.bat"
if not defined VCENV if exist "%VSROOT%\VC\Auxiliary\Build\vcvarsall.bat" set "VCENV=%VSROOT%\VC\Auxiliary\Build\vcvarsall.bat"
if not defined VCENV (
    echo [build] ERROR: no vcvars script under "%VSROOT%\VC\Auxiliary\Build".
    exit /b 1
)
echo [build] VS = %VSROOT%
if /i "%VCENV:~-12%"=="vcvarsall.bat" (
    call "%VCENV%" amd64_x86 >nul
) else (
    call "%VCENV%" >nul
)
if errorlevel 1 (
    echo [build] ERROR: "%VCENV%" failed.
    exit /b 1
)
where cl.exe >nul 2>&1 || ( echo [build] ERROR: cl.exe not on PATH after vcvars. & exit /b 1 )
if not defined WindowsSdkDir (
    echo [build] ERROR: vcvars set no WindowsSdkDir - install a Windows 10/11 SDK via the VS Installer.
    exit /b 1
)
for /f "tokens=*" %%V in ('cl.exe 2^>^&1 ^| findstr /i "Version"') do echo [build] %%V
echo [build] SDK = %WindowsSdkDir% %WindowsSDKVersion%
exit /b 0

rem ===========================================================================
:need_libs
if not exist "%LIBDIR%\lua52.lib" call :build_lua || exit /b 1
if not exist "%LIBDIR%\VSRCore.lib" call :build_core || exit /b 1
if not exist "%LIBDIR%\LuaMissionLib.lib" call :build_lualib || exit /b 1
exit /b 0

rem ===========================================================================
:build_lua
echo.
echo [build] === lua52.lib ===
set "O=%OBJ%\lua52"
if not exist "%O%" mkdir "%O%"
set "LUAFILES="
for %%F in ("%LUASRC%\*.c") do (
    if /i not "%%~nxF"=="lua.c" if /i not "%%~nxF"=="luac.c" set "LUAFILES=!LUAFILES! "%%F""
)
if "!LUAFILES!"=="" ( echo [build] ERROR: no Lua sources in "%LUASRC%" & exit /b 1 )
cl %CFLAGS_LUA% /MP /Fo"%O%\\" /Fd"%O%\lua52.pdb" !LUAFILES! || exit /b 1
lib /nologo /LTCG /MACHINE:X86 /OUT:"%LIBDIR%\lua52.lib" "%O%\*.obj" || exit /b 1
echo [build] -^> "%LIBDIR%\lua52.lib"
exit /b 0

rem ===========================================================================
:build_core
echo.
echo [build] === VSRCore.lib ===
set "O=%OBJ%\VSRCore"
if not exist "%O%" mkdir "%O%"
set "FILES="
for %%F in ("%SRC%\vsrcore\*.cpp") do set "FILES=!FILES! "%%F""
if exist "%SRC%\shared\taunts.cpp" set "FILES=!FILES! "%SRC%\shared\taunts.cpp""
if "!FILES!"=="" (
    echo [build] ERROR: no .cpp in "%SRC%\vsrcore" - run the scaffold first ^(task 6^).
    exit /b 1
)
cl %CXXFLAGS_CORE% %CXXINC% /MP /Fo"%O%\\" /Fd"%O%\VSRCore.pdb" !FILES! || exit /b 1
lib /nologo /LTCG /MACHINE:X86 /OUT:"%LIBDIR%\VSRCore.lib" "%O%\*.obj" || exit /b 1
echo [build] -^> "%LIBDIR%\VSRCore.lib"
exit /b 0

:build_lualib
echo.
echo [build] === LuaMissionLib.lib ===
set "O=%OBJ%\LuaMissionLib"
if not exist "%O%" mkdir "%O%"
set "FILES="
for %%F in ("%SRC%\luamission\*.cpp") do set "FILES=!FILES! "%%F""
if "!FILES!"=="" (
    echo [build] ERROR: no .cpp in "%SRC%\luamission" - run the scaffold first ^(task 6^).
    exit /b 1
)
cl %CXXFLAGS_LUALIB% %CXXINC% /MP /Fo"%O%\\" /Fd"%O%\LuaMissionLib.pdb" !FILES! || exit /b 1
lib /nologo /LTCG /MACHINE:X86 /OUT:"%LIBDIR%\LuaMissionLib.lib" "%O%\*.obj" || exit /b 1
echo [build] -^> "%LIBDIR%\LuaMissionLib.lib"
exit /b 0

rem ===========================================================================
:build_dll
rem  %1 DLL name  %2 own dir under missions\  %3 own .cpp list  %4 shared .cpp list
rem  %5 extra defines  %6 extra libs (quoted paths, may be empty)
echo.
echo [build] === %~1.dll ===
set "O=%OBJ%\%~1"
if not exist "%O%" mkdir "%O%"
set "FILES="
for %%F in (%~3) do (
    if not exist "%SRC%\%~2\%%F" ( echo [build] ERROR: missing "%SRC%\%~2\%%F" & exit /b 1 )
    set "FILES=!FILES! "%SRC%\%~2\%%F""
)
for %%F in (%~4) do (
    if not exist "%SRC%\shared\%%F" ( echo [build] ERROR: missing "%SRC%\shared\%%F" & exit /b 1 )
    set "FILES=!FILES! "%SRC%\shared\%%F""
)
cl %CXXFLAGS_DLL% %~5 %CXXINC% /MP /Fo"%O%\\" /Fd"%O%\%~1_cl.pdb" !FILES! || exit /b 1
link %LINKFLAGS% /OUT:"%BIN%\%~1.dll" /PDB:"%BIN%\%~1.pdb" /IMPLIB:"%O%\%~1.lib" "%O%\*.obj" %~6 "%LIBDIR%\VSRCore.lib" "%LIBDIR%\lua52.lib" "%BZCC_DIR%\battlezone2.lib" || exit /b 1
echo [build] -^> "%BIN%\%~1.dll"
call :show_exports "%BIN%\%~1.dll"
exit /b 0

rem ===========================================================================
:build_stub
rem  Toolchain proof (task 4): a minimal Strategy02.dll that exports GetMisnAPI
rem  with the version magic and no-op callbacks. Lives outside source\ on purpose.
echo.
echo [build] === stub Strategy02.dll (toolchain proof) ===
set "O=%OBJ%\stub"
set "SBIN=%OUT%\bin\stub"
if not exist "%O%" mkdir "%O%"
if not exist "%SBIN%" mkdir "%SBIN%"
cl %CXXFLAGS_DLL% /D _WINDLL /I "%BZCC_DIR%" /Fo"%O%\\" /Fd"%O%\stub_cl.pdb" "%ROOT%\build\stub\stub_strategy02.cpp" || exit /b 1
link %LINKFLAGS% /OUT:"%SBIN%\Strategy02.dll" /PDB:"%SBIN%\Strategy02.pdb" /IMPLIB:"%O%\Strategy02.lib" "%O%\stub_strategy02.obj" "%BZCC_DIR%\battlezone2.lib" || exit /b 1
echo [build] -^> "%SBIN%\Strategy02.dll"
call :show_exports "%SBIN%\Strategy02.dll"
exit /b 0

rem ===========================================================================
:show_exports
echo [build] exports of %~nx1:
dumpbin /nologo /exports "%~1" | findstr /r /c:"^  *[0-9][0-9]*  *[0-9A-F]"
exit /b 0

rem ===========================================================================
:check
echo [build] === QA gates ===
set "PY="
where python.exe >nul 2>&1 && set "PY=python"
if not defined PY where py.exe >nul 2>&1 && set "PY=py -3"
if not defined PY ( echo [build] ERROR: python not found. & exit /b 1 )
set "RC=0"
rem  The port is complete (STATUS.md task 15), so the parity gates run strict: every roster or
rem  string difference must be explained in tools/parity/*.txt or the gate fails.
for %%S in (check_no_thirdparty.py check_status.py "check_symbol_parity.py --strict" "check_strings.py --strict") do (
    for /f "tokens=1*" %%A in ("%%~S") do (
        if exist "%ROOT%\tools\%%A" (
            echo.
            echo [check] %%A %%B
            %PY% "%ROOT%\tools\%%A" %%B || set "RC=1"
        ) else (
            echo [check] %%A  ^(not present yet^)
        )
    )
)
if "%RC%"=="0" ( echo. & echo [check] all present gates passed ) else ( echo. & echo [check] FAILED )
exit /b %RC%
