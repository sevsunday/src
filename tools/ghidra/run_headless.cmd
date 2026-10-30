@echo off
setlocal
rem ===========================================================================
rem  run_headless.cmd <Strategy02|LuaMission|Instant|deathmatch01> [outdir]
rem
rem  Decompiles original\missions\<name>.dll with its PDB through the portable
rem  Ghidra under tools\_local\ (installed by tools\ghidra\install.py) and
rem  exports the attempt2-shaped set with VsrExportDecompile.java.
rem  Default outdir: reference\decompiled\<name lower>-ghidra<version>\
rem ===========================================================================
set "ROOT=%~dp0..\.."
for %%I in ("%ROOT%") do set "ROOT=%%~fI"
set "NAME=%~1"
if "%NAME%"=="" ( echo usage: run_headless.cmd ^<Strategy02^|LuaMission^|Instant^|deathmatch01^> [outdir] & exit /b 1 )
set "DLL=%ROOT%\original\missions\%NAME%.dll"
if not exist "%DLL%" ( echo missing "%DLL%" & exit /b 1 )
if not exist "%ROOT%\original\missions\%NAME%.pdb" ( echo missing PDB next to the DLL & exit /b 1 )

set "GHIDRA=%ROOT%\tools\_local\ghidra%GHIDRA_SUFFIX%"
set "JAVA_HOME=%ROOT%\tools\_local\jdk%GHIDRA_SUFFIX%"
if not exist "%GHIDRA%\support\analyzeHeadless.bat" ( echo Ghidra not installed - run: python tools\ghidra\install.py & exit /b 1 )
if not exist "%JAVA_HOME%\bin\java.exe" ( echo JDK not installed - run: python tools\ghidra\install.py & exit /b 1 )
set "PATH=%JAVA_HOME%\bin;%PATH%"

set "GVER="
for /f "tokens=2 delims==" %%V in ('findstr /b "application.version=" "%GHIDRA%\Ghidra\application.properties"') do set "GVER=%%V"
for /f "delims=" %%L in ('powershell -NoProfile -Command "'%NAME%'.ToLower()"') do set "LOWER=%%L"
set "OUT=%~2"
if "%OUT%"=="" set "OUT=%ROOT%\reference\decompiled\%LOWER%-ghidra%GVER%"
if not exist "%OUT%" mkdir "%OUT%"

set "PROJ=%ROOT%\out\ghidra-projects"
if not exist "%PROJ%" mkdir "%PROJ%"
rem Fresh project every run so nothing from a previous analysis leaks in.
if exist "%PROJ%\%NAME%.rep" rmdir /s /q "%PROJ%\%NAME%.rep"
if exist "%PROJ%\%NAME%.gpr" del /q "%PROJ%\%NAME%.gpr"

echo [ghidra] %GVER%  java=%JAVA_HOME%
echo [ghidra] import %DLL%
echo [ghidra] out    %OUT%
rem  The PDB analyzer looks next to the imported file first, so the PDB in
rem  original\missions\ is found without a symbol server.
call "%GHIDRA%\support\analyzeHeadless.bat" "%PROJ%" "%NAME%" ^
    -import "%DLL%" -loader PeLoader ^
    -analysisTimeoutPerFile 3600 ^
    -scriptPath "%ROOT%\tools\ghidra" ^
    -postScript VsrExportDecompile.java "%OUT%" ^
    -log "%OUT%\ghidra-headless.log" ^
    -scriptlog "%OUT%\ghidra-script.log" ^
    -deleteProject
set "RC=%errorlevel%"
if not "%RC%"=="0" ( echo [ghidra] analyzeHeadless exit %RC% & exit /b %RC% )
if exist "%OUT%\EXPORT_INFO.txt" type "%OUT%\EXPORT_INFO.txt"
exit /b 0
