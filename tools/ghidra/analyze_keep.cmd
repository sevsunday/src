@echo off
setlocal
rem ===========================================================================
rem  analyze_keep.cmd <Strategy02|LuaMission|Instant|deathmatch01>
rem  Import + analyze one DLL (PDB applied) into a PERSISTENT headless project
rem  under out\ghidra-projects\<name>-keep, so single-function experiments can
rem  run against it with process_one.cmd without re-analysing.
rem ===========================================================================
set "ROOT=%~dp0..\.."
for %%I in ("%ROOT%") do set "ROOT=%%~fI"
set "NAME=%~1"
if "%NAME%"=="" ( echo usage: analyze_keep.cmd ^<dll name^> & exit /b 1 )
set "DLL=%ROOT%\original\missions\%NAME%.dll"
set "GHIDRA=%ROOT%\tools\_local\ghidra%GHIDRA_SUFFIX%"
set "JAVA_HOME=%ROOT%\tools\_local\jdk%GHIDRA_SUFFIX%"
set "PATH=%JAVA_HOME%\bin;%PATH%"
set "PROJ=%ROOT%\out\ghidra-projects"
if not exist "%PROJ%" mkdir "%PROJ%"
if exist "%PROJ%\%NAME%-keep.rep" rmdir /s /q "%PROJ%\%NAME%-keep.rep"
if exist "%PROJ%\%NAME%-keep.gpr" del /q "%PROJ%\%NAME%-keep.gpr"
call "%GHIDRA%\support\analyzeHeadless.bat" "%PROJ%" "%NAME%-keep" -import "%DLL%" -loader PeLoader -analysisTimeoutPerFile 3600 -log "%PROJ%\%NAME%-keep.log"
exit /b %errorlevel%
