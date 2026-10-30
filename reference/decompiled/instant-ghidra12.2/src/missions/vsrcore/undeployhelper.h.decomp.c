// Reconstructed by Ghidra from Instant.dll + Instant.pdb
// Original source file: /e:/github/vsr_dll_source/missions/vsrcore/undeployhelper.h
// Functions are ordered by original source line. This is decompiler
// output, not the author's source: names/types come from the PDB,
// local variable names and control flow are reconstructed.


// ---------------------------------------------------------------------
// operator==  @ 4fc1bd6a  lines 22-56


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool __cdecl operator==(UndeployClass *param_1,UndeployClass *param_2)

{
  int *in_ECX;
  int *in_EDX;
  char *unaff_ESI;
  int unaff_EDI;
  char *pcVar1;
  undefined1 local_8c [64];
  undefined1 local_4c [68];
  undefined4 local_8;
  
  local_8 = __security_cookie ^ (uint)(local_4c + 0x48);
  if (*in_ECX == *in_EDX) {
    if ((char)in_ECX[1] == (char)in_EDX[1]) {
      if (in_ECX[2] == in_EDX[2]) {
        if ((float)in_ECX[3] == (float)in_EDX[3]) {
          return true;
        }
        pcVar1 = "UNDEPLOYCLASS MISMATCH: UndeployFrames: %f and %f";
        goto LAB_4fc1bdd8;
      }
      pcVar1 = "UNDEPLOYCLASS MISMATCH: UndeployTime: %d and %d";
    }
    else {
      pcVar1 = "UNDEPLOYCLASS MISMATCH: IsAnimated: %d and %d";
    }
    FormatLogMessage(pcVar1);
  }
  else {
    memset(local_8c,0,0x40);
    memset(local_4c,0,0x40);
    GetODFName(unaff_EDI,unaff_ESI);
    GetODFName(unaff_EDI,unaff_ESI);
    pcVar1 = "UNDEPLOYCLASS MISMATCH: UndeployingObject: %08x \'%s\' and %08x \'%s\'";
LAB_4fc1bdd8:
    FormatLogMessage(pcVar1);
  }
  return false;
}

