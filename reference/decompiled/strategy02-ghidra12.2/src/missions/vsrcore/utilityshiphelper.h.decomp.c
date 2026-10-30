// Reconstructed by Ghidra from Strategy02.dll + Strategy02.pdb
// Original source file: /e:/github/vsr_dll_source/missions/vsrcore/utilityshiphelper.h
// Functions are ordered by original source line. This is decompiler
// output, not the author's source: names/types come from the PDB,
// local variable names and control flow are reconstructed.


// ---------------------------------------------------------------------
// operator==  @ 4fc14e5a  lines 32-96


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool __cdecl operator==(UtilityShipClass *param_1,UtilityShipClass *param_2)

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
      if (*(char *)((int)in_ECX + 5) == *(char *)((int)in_EDX + 5)) {
        if (*(char *)((int)in_ECX + 6) == *(char *)((int)in_EDX + 6)) {
          if (in_ECX[2] == in_EDX[2]) {
            if (in_ECX[3] == in_EDX[3]) {
              if (in_ECX[4] == in_EDX[4]) {
                if (in_ECX[5] == in_EDX[5]) {
                  if (in_ECX[6] == in_EDX[6]) {
                    if ((((float)in_ECX[8] == (float)in_EDX[8]) &&
                        ((float)in_ECX[9] == (float)in_EDX[9])) &&
                       ((float)in_ECX[10] == (float)in_EDX[10])) {
                      return true;
                    }
                    FormatLogMessage("BUILDINGCLASS MISMATCH: Position: %f %f %f and %f %f %f");
                    return false;
                  }
                  pcVar1 = "UTILITYSHIPCLASS MISMATCH: DropClassMask: %d and %d";
                }
                else {
                  pcVar1 = "UTILITYSHIPCLASS MISMATCH: EscortPriority: %d and %d";
                }
              }
              else {
                pcVar1 = "UTILITYSHIPCLASS MISMATCH: ScrapAmount: %d and %d";
              }
            }
            else {
              pcVar1 = "UTILITYSHIPCLASS MISMATCH: CurTeamNum: %d and %d";
            }
          }
          else {
            pcVar1 = "UTILITYSHIPCLASS MISMATCH: ObjClassHash: %d and %d";
          }
        }
        else {
          pcVar1 = "UTILITYSHIPCLASS MISMATCH: DoDLLDispatch: %d and %d";
        }
      }
      else {
        pcVar1 = "UTILITYSHIPCLASS MISMATCH: ServiceAllies: %d and %d";
      }
    }
    else {
      pcVar1 = "UTILITYSHIPCLASS MISMATCH: DoDrop: %d and %d";
    }
    FormatLogMessage(pcVar1);
  }
  else {
    memset(local_8c,0,0x40);
    memset(local_4c,0,0x40);
    GetODFName(unaff_EDI,unaff_ESI);
    GetODFName(unaff_EDI,unaff_ESI);
    FormatLogMessage("UTILITYSHIPCLASS MISMATCH: UtilityShipObject: %08x \'%s\' and %08x \'%s\'");
  }
  return false;
}

