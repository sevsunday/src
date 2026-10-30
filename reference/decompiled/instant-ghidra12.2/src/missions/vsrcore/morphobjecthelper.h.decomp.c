// Reconstructed by Ghidra from Instant.dll + Instant.pdb
// Original source file: /e:/github/vsr_dll_source/missions/vsrcore/morphobjecthelper.h
// Functions are ordered by original source line. This is decompiler
// output, not the author's source: names/types come from the PDB,
// local variable names and control flow are reconstructed.


// ---------------------------------------------------------------------
// operator==  @ 4fc157da  lines 41-178


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool __cdecl operator==(MorphObjectClass *param_1,MorphObjectClass *param_2)

{
  int *in_ECX;
  int iVar1;
  float *pfVar2;
  int *in_EDX;
  int iVar3;
  char *unaff_ESI;
  int unaff_EDI;
  char *pcVar4;
  undefined1 local_8c [64];
  undefined1 local_4c [68];
  uint local_8;
  
  local_8 = __security_cookie ^ (uint)local_8c;
  if (*in_ECX == *in_EDX) {
    if (in_ECX[1] == in_EDX[1]) {
      if ((char)in_ECX[2] == (char)in_EDX[2]) {
        if (*(char *)((int)in_ECX + 9) == *(char *)((int)in_EDX + 9)) {
          if (*(char *)((int)in_ECX + 10) == *(char *)((int)in_EDX + 10)) {
            if (*(char *)((int)in_ECX + 0xb) == *(char *)((int)in_EDX + 0xb)) {
              if (in_ECX[3] == in_EDX[3]) {
                if (in_ECX[4] == in_EDX[4]) {
                  if (in_ECX[5] == in_EDX[5]) {
                    if (in_ECX[6] == in_EDX[6]) {
                      if (in_ECX[7] == in_EDX[7]) {
                        iVar3 = 0;
                        pfVar2 = (float *)(in_EDX + 8);
                        iVar1 = 0;
                        do {
                          if (*(float *)((int)pfVar2 + ((int)in_ECX - (int)in_EDX)) != *pfVar2) {
                            pcVar4 = "MORPHOBJECTCLASS MISMATCH: LocalAmmo%d: %f and %f";
                            goto LAB_4fc15b72;
                          }
                          iVar1 = iVar1 + 1;
                          pfVar2 = pfVar2 + 1;
                        } while (iVar1 < 5);
                        if ((float)in_ECX[0x12] != (float)in_EDX[0x12]) {
                          pcVar4 = "MORPHOBJECTCLASS MISMATCH: EngageRange: %f and %f";
                          goto LAB_4fc15847;
                        }
                        pfVar2 = (float *)(in_EDX + 0x13);
                        do {
                          if (*(float *)((int)pfVar2 + ((int)in_ECX - (int)in_EDX)) != *pfVar2) {
                            pcVar4 = "MORPHOBJECTCLASS MISMATCH: CloakChance%d: %f and %f";
LAB_4fc15b72:
                            FormatLogMessage(pcVar4);
                            return false;
                          }
                          iVar3 = iVar3 + 1;
                          pfVar2 = pfVar2 + 1;
                        } while (iVar3 < 0x36);
                        if ((((float)in_ECX[0x49] != (float)in_EDX[0x49]) ||
                            ((float)in_ECX[0x4a] != (float)in_EDX[0x4a])) ||
                           ((float)in_ECX[0x4b] != (float)in_EDX[0x4b])) {
                          FormatLogMessage(
                                          "MORPHOBJECTCLASS MISMATCH: CurrentWhere: %f %f %f and %f %f %f"
                                          );
                          return false;
                        }
                        if ((char)in_ECX[0x4c] == (char)in_EDX[0x4c]) {
                          if (in_ECX[0x4d] == in_EDX[0x4d]) {
                            if (in_ECX[0x4e] == in_EDX[0x4e]) {
                              if (in_ECX[0x4f] == in_EDX[0x4f]) {
                                if (in_ECX[0x50] == in_EDX[0x50]) {
                                  if ((float)in_ECX[0x51] == (float)in_EDX[0x51]) {
                                    return true;
                                  }
                                  pcVar4 = 
                                  "MORPHOBJECTCLASS MISMATCH: CloakCurEnergyRemainder: %f and %f";
                                  goto LAB_4fc15847;
                                }
                                pcVar4 = "MORPHOBJECTCLASS MISMATCH: CloakAddEnergy: %d and %d";
                              }
                              else {
                                pcVar4 = "MORPHOBJECTCLASS MISMATCH: CloakCostEnergy: %d and %d";
                              }
                            }
                            else {
                              pcVar4 = "MORPHOBJECTCLASS MISMATCH: CloakCurEnergy: %d and %d";
                            }
                          }
                          else {
                            pcVar4 = "MORPHOBJECTCLASS MISMATCH: CloakMaxEnergy: %d and %d";
                          }
                        }
                        else {
                          pcVar4 = "MORPHOBJECTCLASS MISMATCH: BlockDeploy: %d and %d";
                        }
                      }
                      else {
                        pcVar4 = "MORPHOBJECTCLASS MISMATCH: PTeam: %d and %d";
                      }
                    }
                    else {
                      pcVar4 = "MORPHOBJECTCLASS MISMATCH: Command: %d and %d";
                    }
                  }
                  else {
                    pcVar4 = "MORPHOBJECTCLASS MISMATCH: MaxAmmo: %d and %d";
                  }
                }
                else {
                  pcVar4 = "MORPHOBJECTCLASS MISMATCH: NormalAmmo: %d and %d";
                }
              }
              else {
                pcVar4 = "MORPHOBJECTCLASS MISMATCH: IdleTime: %d and %d";
              }
            }
            else {
              pcVar4 = "MORPHOBJECTCLASS MISMATCH: IsCloaker: %d and %d";
            }
          }
          else {
            pcVar4 = "MORPHOBJECTCLASS MISMATCH: CanFire: %d and %d";
          }
        }
        else {
          pcVar4 = "MORPHOBJECTCLASS MISMATCH: ObjectSwitch: %d and %d";
        }
      }
      else {
        pcVar4 = "MORPHOBJECTCLASS MISMATCH: WeaponActive: %d and %d";
      }
      FormatLogMessage(pcVar4);
      return false;
    }
    memset(local_8c,0,0x40);
    memset(local_4c,0,0x40);
    GetODFName(unaff_EDI,unaff_ESI);
    GetODFName(unaff_EDI,unaff_ESI);
    pcVar4 = "MORPHOBJECTCLASS MISMATCH: CurrentWho: %08x \'%s\' and %08x \'%s\'";
  }
  else {
    memset(local_4c,0,0x40);
    memset(local_8c,0,0x40);
    GetODFName(unaff_EDI,unaff_ESI);
    GetODFName(unaff_EDI,unaff_ESI);
    pcVar4 = "MORPHOBJECTCLASS MISMATCH: MorphObject: %08x \'%s\' and %08x \'%s\'";
  }
LAB_4fc15847:
  FormatLogMessage(pcVar4);
  return false;
}

