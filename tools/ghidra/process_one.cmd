@echo off
setlocal
rem ===========================================================================
rem  process_one.cmd <name> <addr hex> <style> <timeout sec> <outfile>
rem  Decompile one function from the persistent project made by analyze_keep.cmd.
rem  Styles: decompile (default export) | normalize | firstpass | register | paramid
rem ===========================================================================
set "ROOT=%~dp0..\.."
for %%I in ("%ROOT%") do set "ROOT=%%~fI"
set "NAME=%~1"
set "GHIDRA=%ROOT%\tools\_local\ghidra%GHIDRA_SUFFIX%"
set "JAVA_HOME=%ROOT%\tools\_local\jdk%GHIDRA_SUFFIX%"
set "PATH=%JAVA_HOME%\bin;%PATH%"
set "PROJ=%ROOT%\out\ghidra-projects"
if not exist "%PROJ%\%NAME%-keep.gpr" ( echo no persistent project - run analyze_keep.cmd %NAME% & exit /b 1 )
call "%GHIDRA%\support\analyzeHeadless.bat" "%PROJ%" "%NAME%-keep" -process "%NAME%.dll" -noanalysis -scriptPath "%ROOT%\tools\ghidra" -postScript VsrDecompileOne.java %2 %3 %4 "%~5" %6
exit /b %errorlevel%
