// Reconstructed by Ghidra from deathmatch01.dll + deathmatch01.pdb
// Original source file: /e:/github/vsr_dll_source/missions/vsrcore/objecthelper.h
// Functions are ordered by original source line. This is decompiler
// output, not the author's source: names/types come from the PDB,
// local variable names and control flow are reconstructed.


// ---------------------------------------------------------------------
// operator==  @ 4fc23f30  lines 55-174


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool __cdecl operator==(ObjectClass *param_1,ObjectClass *param_2)

{
  char *pcVar1;
  int *in_ECX;
  int iVar2;
  int *in_EDX;
  char *unaff_ESI;
  int unaff_EDI;
  undefined1 local_8c [64];
  undefined1 local_4c [68];
  undefined4 local_8;
  
  local_8 = __security_cookie ^ (uint)(local_4c + 0x48);
  if (*in_ECX == *in_EDX) {
    if (in_ECX[1] == in_EDX[1]) {
      if (in_ECX[2] == in_EDX[2]) {
        if (in_ECX[3] == in_EDX[3]) {
          if (in_ECX[4] == in_EDX[4]) {
            if ((char)in_ECX[5] == (char)in_EDX[5]) {
              if (*(char *)((int)in_ECX + 0x15) == *(char *)((int)in_EDX + 0x15)) {
                if (*(char *)((int)in_ECX + 0x16) == *(char *)((int)in_EDX + 0x16)) {
                  if (*(char *)((int)in_ECX + 0x17) == *(char *)((int)in_EDX + 0x17)) {
                    if (in_ECX[6] == in_EDX[6]) {
                      if (in_ECX[7] == in_EDX[7]) {
                        if (in_ECX[8] == in_EDX[8]) {
                          if ((float)in_ECX[9] != (float)in_EDX[9]) {
                            pcVar1 = "OBJECTLIST MISMATCH: EngageRange: %f and %f";
                            goto LAB_4fc23f9e;
                          }
                          iVar2 = 0;
                          do {
                            pcVar1 = (char *)((int)in_ECX + iVar2 + 0x28);
                            if (*pcVar1 != pcVar1[(int)in_EDX - (int)in_ECX]) {
                              pcVar1 = "OBJECTLIST MISMATCH: IsObjectified%d: %d and %d";
LAB_4fc241b9:
                              FormatLogMessage(pcVar1);
                              return false;
                            }
                            if (*(char *)((int)in_ECX + iVar2 + 0x38) !=
                                *(char *)((int)in_EDX + iVar2 + 0x38)) {
                              pcVar1 = "OBJECTLIST MISMATCH: IsBeingJammed%d: %d and %d";
                              goto LAB_4fc241b9;
                            }
                            iVar2 = iVar2 + 1;
                          } while (iVar2 < 0x10);
                          if ((((float)in_ECX[0x12] != (float)in_EDX[0x12]) ||
                              ((float)in_ECX[0x13] != (float)in_EDX[0x13])) ||
                             ((float)in_ECX[0x14] != (float)in_EDX[0x14])) {
                            FormatLogMessage("OBJECTLIST MISMATCH: Position: %f %f %f and %f %f %f")
                            ;
                            return false;
                          }
                          if (in_ECX[0x15] == in_EDX[0x15]) {
                            if (in_ECX[0x16] == in_EDX[0x16]) {
                              return true;
                            }
                            pcVar1 = "OBJECTLIST MISMATCH: MaxAmmo: %d and %d";
                          }
                          else {
                            pcVar1 = "OBJECTLIST MISMATCH: MaxHealth: %d and %d";
                          }
                        }
                        else {
                          pcVar1 = "OBJECTLIST MISMATCH: PTeam: %d and %d";
                        }
                      }
                      else {
                        pcVar1 = "OBJECTLIST MISMATCH: CurTeamNum: %d and %d";
                      }
                    }
                    else {
                      pcVar1 = "OBJECTLIST MISMATCH: OriginalTeam: %d and %d";
                    }
                  }
                  else {
                    pcVar1 = "OBJECTLIST MISMATCH: CanBeIdleVictim: %d and %d";
                  }
                }
                else {
                  pcVar1 = "OBJECTLIST MISMATCH: CanTeleport: %d and %d";
                }
              }
              else {
                pcVar1 = "OBJECTLIST MISMATCH: CanObjectifyDeployed: %d and %d";
              }
            }
            else {
              pcVar1 = "OBJECTLIST MISMATCH: CanObjectify: %d and %d";
            }
          }
          else {
            pcVar1 = "OBJECTLIST MISMATCH: CategoryID: %d and %d";
          }
        }
        else {
          pcVar1 = "OBJECTLIST MISMATCH: BZCClassHash: %d and %d";
        }
      }
      else {
        pcVar1 = "OBJECTLIST MISMATCH: ObjClassHash: %d and %d";
      }
    }
    else {
      pcVar1 = "OBJECTLIST MISMATCH: ODFNameHash: %d and %d";
    }
    FormatLogMessage(pcVar1);
  }
  else {
    memset(local_8c,0,0x40);
    memset(local_4c,0,0x40);
    GetODFName(unaff_EDI,unaff_ESI);
    GetODFName(unaff_EDI,unaff_ESI);
    pcVar1 = "OBJECTLIST MISMATCH: ObjectHandle: %08x \'%s\' and %08x \'%s\'";
LAB_4fc23f9e:
    FormatLogMessage(pcVar1);
  }
  return false;
}


// ---------------------------------------------------------------------
// ObjectHelper::GetNumHandles  @ 4fc08d9f  lines 188-188


int __thiscall ObjectHelper::GetNumHandles(ObjectHelper *this)

{
  return (*(int *)&(this->HandleList).field_0x4 - *(int *)&this->HandleList) / 0x5c;
}

