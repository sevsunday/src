// Reconstructed by Ghidra from Strategy02.dll + Strategy02.pdb
// Original source file: /e:/github/vsr_dll_source/missions/vsrcore/undeployhelper.h
// Functions are ordered by original source line. This is decompiler
// output, not the author's source: names/types come from the PDB,
// local variable names and control flow are reconstructed.

// ---------------------------------------------------------------------
// operator==  @ 4fc1c76c  lines 22-56

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool __cdecl operator==(UndeployClass *a,UndeployClass *b)

{
  int h;
  char *pcVar1;
  char ODFNameA [64];
  char ODFNameB [68];
  uint local_8;
  
  local_8 = __security_cookie ^ (uint)&stack0xfffffffc;
  h = a->UndeployingObject;
  if (h == b->UndeployingObject) {
    if (a->IsAnimated == b->IsAnimated) {
      if (a->UndeployTime == b->UndeployTime) {
        if (a->UndeployFrames == b->UndeployFrames) {
          return true;
        }
        pcVar1 = "UNDEPLOYCLASS MISMATCH: UndeployFrames: %f and %f";
        goto LAB_4fc1c7da;
      }
      pcVar1 = "UNDEPLOYCLASS MISMATCH: UndeployTime: %d and %d";
    }
    else {
      pcVar1 = "UNDEPLOYCLASS MISMATCH: IsAnimated: %d and %d";
    }
    FormatLogMessage(pcVar1);
  }
  else {
    memset(ODFNameA,0,0x40);
    memset(ODFNameB,0,0x40);
    GetODFName(h,ODFNameA);
    GetODFName(b->UndeployingObject,ODFNameB);
    pcVar1 = "UNDEPLOYCLASS MISMATCH: UndeployingObject: %08x \'%s\' and %08x \'%s\'";
LAB_4fc1c7da:
    FormatLogMessage(pcVar1);
  }
  return false;
}


