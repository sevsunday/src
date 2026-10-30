// Reconstructed by Ghidra from Strategy02.dll + Strategy02.pdb
// Original source file: /e:/github/vsr_dll_source/missions/vsrcore/gravityhelper.h
// Functions are ordered by original source line. This is decompiler
// output, not the author's source: names/types come from the PDB,
// local variable names and control flow are reconstructed.


// ---------------------------------------------------------------------
// operator==  @ 4fc15c5b  lines 25-56


bool __cdecl operator==(GravityInfo *param_1,GravityInfo *param_2)

{
  float *in_ECX;
  float *in_EDX;
  char *pcVar1;
  
  if (*in_ECX == *in_EDX) {
    if (in_ECX[1] == in_EDX[1]) {
      if (in_ECX[2] == in_EDX[2]) {
        if (in_ECX[3] == in_EDX[3]) {
          if (in_ECX[4] == in_EDX[4]) {
            return true;
          }
          FormatLogMessage("GRAVITYINFO MISMATCH: OnCounter: %d and %d");
          return false;
        }
        pcVar1 = "GRAVITYINFO MISMATCH: Gravity: %f and %f";
      }
      else {
        pcVar1 = "GRAVITYINFO MISMATCH: Gravitation: %f and %f";
      }
    }
    else {
      pcVar1 = "GRAVITYINFO MISMATCH: OnPeriod: %f and %f";
    }
  }
  else {
    pcVar1 = "GRAVITYINFO MISMATCH: TranPeriod: %f and %f";
  }
  FormatLogMessage(pcVar1);
  return false;
}

