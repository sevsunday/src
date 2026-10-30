// Reconstructed by Ghidra from Strategy02.dll + Strategy02.pdb
// Original source file: /e:/github/vsr_dll_source/missions/vsrcore/gravityhelper.h
// Functions are ordered by original source line. This is decompiler
// output, not the author's source: names/types come from the PDB,
// local variable names and control flow are reconstructed.

// ---------------------------------------------------------------------
// operator==  @ 4fc15c5b  lines 25-56

bool __cdecl operator==(GravityInfo *a,GravityInfo *b)

{
  char *format;
  
  if (a->TranPeriod == b->TranPeriod) {
    if (a->OnPeriod == b->OnPeriod) {
      if (a->Gravitation == b->Gravitation) {
        if (a->Gravity == b->Gravity) {
          if (a->OnCounter != b->OnCounter) {
            FormatLogMessage("GRAVITYINFO MISMATCH: OnCounter: %d and %d",a->OnCounter,b->OnCounter)
            ;
            return false;
          }
          return true;
        }
        format = "GRAVITYINFO MISMATCH: Gravity: %f and %f";
      }
      else {
        format = "GRAVITYINFO MISMATCH: Gravitation: %f and %f";
      }
    }
    else {
      format = "GRAVITYINFO MISMATCH: OnPeriod: %f and %f";
    }
  }
  else {
    format = "GRAVITYINFO MISMATCH: TranPeriod: %f and %f";
  }
  FormatLogMessage(format);
  return false;
}


