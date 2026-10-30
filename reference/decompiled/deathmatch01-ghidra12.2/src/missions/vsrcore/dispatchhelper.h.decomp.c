// Reconstructed by Ghidra from deathmatch01.dll + deathmatch01.pdb
// Original source file: /e:/github/vsr_dll_source/missions/vsrcore/dispatchhelper.h
// Functions are ordered by original source line. This is decompiler
// output, not the author's source: names/types come from the PDB,
// local variable names and control flow are reconstructed.


// ---------------------------------------------------------------------
// operator==  @ 4fc1ee69  lines 89-295


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool __cdecl operator==(DispatchClass *param_1,DispatchClass *param_2)

{
  int *in_ECX;
  int iVar1;
  int *in_EDX;
  float *pfVar2;
  char *unaff_ESI;
  int unaff_EDI;
  char *pcVar3;
  undefined1 local_8c [64];
  undefined1 local_4c [68];
  undefined4 local_8;
  
  local_8 = __security_cookie ^ (uint)(local_4c + 0x48);
  if (*in_ECX == *in_EDX) {
    if (in_ECX[1] == in_EDX[1]) {
      if (in_ECX[2] == in_EDX[2]) {
        if ((((float)in_ECX[3] != (float)in_EDX[3]) || ((float)in_ECX[4] != (float)in_EDX[4])) ||
           ((float)in_ECX[5] != (float)in_EDX[5])) {
          FormatLogMessage("DISPATCHCLASS MISMATCH: DispatchSpot: %f %f %f and %f %f %f");
          return false;
        }
        if (in_ECX[6] == in_EDX[6]) {
          if (in_ECX[7] == in_EDX[7]) {
            if (in_ECX[8] == in_EDX[8]) {
              if ((char)in_ECX[9] == (char)in_EDX[9]) {
                if (*(char *)((int)in_ECX + 0x25) == *(char *)((int)in_EDX + 0x25)) {
                  if (*(char *)((int)in_ECX + 0x26) == *(char *)((int)in_EDX + 0x26)) {
                    if (*(char *)((int)in_ECX + 0x27) == *(char *)((int)in_EDX + 0x27)) {
                      if ((char)in_ECX[10] == (char)in_EDX[10]) {
                        if (*(char *)((int)in_ECX + 0x29) == *(char *)((int)in_EDX + 0x29)) {
                          if (*(char *)((int)in_ECX + 0x2a) == *(char *)((int)in_EDX + 0x2a)) {
                            if (*(char *)((int)in_ECX + 0x2b) == *(char *)((int)in_EDX + 0x2b)) {
                              if ((char)in_ECX[0xb] == (char)in_EDX[0xb]) {
                                if (*(char *)((int)in_ECX + 0x2d) == *(char *)((int)in_EDX + 0x2d))
                                {
                                  if (*(char *)((int)in_ECX + 0x2e) == *(char *)((int)in_EDX + 0x2e)
                                     ) {
                                    if (in_ECX[0xc] == in_EDX[0xc]) {
                                      if (in_ECX[0xd] == in_EDX[0xd]) {
                                        if (in_ECX[0xe] == in_EDX[0xe]) {
                                          if (in_ECX[0xf] == in_EDX[0xf]) {
                                            if ((float)in_ECX[0x10] == (float)in_EDX[0x10]) {
                                              if ((float)in_ECX[0x11] == (float)in_EDX[0x11]) {
                                                if ((float)in_ECX[0x12] == (float)in_EDX[0x12]) {
                                                  pfVar2 = (float *)(in_EDX + 0x13);
                                                  iVar1 = 0;
                                                  do {
                                                    if (*(float *)(((int)in_ECX - (int)in_EDX) +
                                                                  (int)pfVar2) != *pfVar2) {
                                                      FormatLogMessage(
                                                  "DISPATCHCLASS MISMATCH: CloakChance%d: %f and %f"
                                                  );
                                                  return false;
                                                  }
                                                  iVar1 = iVar1 + 1;
                                                  pfVar2 = pfVar2 + 1;
                                                  } while (iVar1 < 0x36);
                                                  if ((float)in_ECX[0x49] == (float)in_EDX[0x49]) {
                                                    if ((float)in_ECX[0x4a] == (float)in_EDX[0x4a])
                                                    {
                                                      if ((float)in_ECX[0x4b] == (float)in_EDX[0x4b]
                                                         ) {
                                                        if (in_ECX[0x4c] == in_EDX[0x4c]) {
                                                          if (in_ECX[0x4d] == in_EDX[0x4d]) {
                                                            if (in_ECX[0x4e] == in_EDX[0x4e]) {
                                                              if (in_ECX[0x4f] == in_EDX[0x4f]) {
                                                                if (in_ECX[0x50] == in_EDX[0x50]) {
                                                                  if (in_ECX[0x51] == in_EDX[0x51])
                                                                  {
                                                                    return true;
                                                                  }
                                                                  pcVar3 = 
                                                  "DISPATCHCLASS MISMATCH: CloakPriority: %d and %d"
                                                  ;
                                                  }
                                                  else {
                                                    pcVar3 = 
                                                  "DISPATCHCLASS MISMATCH: FleeHealthValue: %d and %d"
                                                  ;
                                                  }
                                                  }
                                                  else {
                                                    pcVar3 = 
                                                  "DISPATCHCLASS MISMATCH: Command: %d and %d";
                                                  }
                                                  }
                                                  else {
                                                    pcVar3 = 
                                                  "DISPATCHCLASS MISMATCH: MaxAmmo: %d and %d";
                                                  }
                                                  }
                                                  else {
                                                    pcVar3 = 
                                                  "DISPATCHCLASS MISMATCH: MaxHealth: %d and %d";
                                                  }
                                                  }
                                                  else {
                                                    pcVar3 = 
                                                  "DISPATCHCLASS MISMATCH: MinFireAmmo: %d and %d";
                                                  }
                                                  goto LAB_4fc1efec;
                                                  }
                                                  pcVar3 = 
                                                  "DISPATCHCLASS MISMATCH: ServiceChance: %f and %f"
                                                  ;
                                                  }
                                                  else {
                                                    pcVar3 = 
                                                  "DISPATCHCLASS MISMATCH: GetRepairRatio: %f and %f"
                                                  ;
                                                  }
                                                  }
                                                  else {
                                                    pcVar3 = 
                                                  "DISPATCHCLASS MISMATCH: FleeHealthRatio: %f and %f"
                                                  ;
                                                  }
                                                }
                                                else {
                                                  pcVar3 = 
                                                  "DISPATCHCLASS MISMATCH: TimeDeploy: %f and %f";
                                                }
                                              }
                                              else {
                                                pcVar3 = 
                                                "DISPATCHCLASS MISMATCH: EngageRange: %f and %f";
                                              }
                                            }
                                            else {
                                              pcVar3 = 
                                              "DISPATCHCLASS MISMATCH: RandomDist: %f and %f";
                                            }
                                            goto LAB_4fc1eed7;
                                          }
                                          pcVar3 = "DISPATCHCLASS MISMATCH: ServiceTimer: %d and %d"
                                          ;
                                        }
                                        else {
                                          pcVar3 = "DISPATCHCLASS MISMATCH: DeployTimer: %d and %d";
                                        }
                                      }
                                      else {
                                        pcVar3 = "DISPATCHCLASS MISMATCH: CloakIdleTime: %d and %d";
                                      }
                                    }
                                    else {
                                      pcVar3 = "DISPATCHCLASS MISMATCH: IdleTime: %d and %d";
                                    }
                                  }
                                  else {
                                    pcVar3 = "DISPATCHCLASS MISMATCH: DecloakNextTick: %d and %d";
                                  }
                                }
                                else {
                                  pcVar3 = "DISPATCHCLASS MISMATCH: CloakNextTick: %d and %d";
                                }
                              }
                              else {
                                pcVar3 = "DISPATCHCLASS MISMATCH: CloakLocked: %d and %d";
                              }
                            }
                            else {
                              pcVar3 = "DISPATCHCLASS MISMATCH: IsCloaked: %d and %d";
                            }
                          }
                          else {
                            pcVar3 = "DISPATCHCLASS MISMATCH: MorphIsAssault: %d and %d";
                          }
                        }
                        else {
                          pcVar3 = "DISPATCHCLASS MISMATCH: CanGetRepair: %d and %d";
                        }
                      }
                      else {
                        pcVar3 = "DISPATCHCLASS MISMATCH: CanGetReload: %d and %d";
                      }
                    }
                    else {
                      pcVar3 = "DISPATCHCLASS MISMATCH: CanFlee: %d and %d";
                    }
                  }
                  else {
                    pcVar3 = "DISPATCHCLASS MISMATCH: IsMorpher: %d and %d";
                  }
                }
                else {
                  pcVar3 = "DISPATCHCLASS MISMATCH: IsCloaker: %d and %d";
                }
              }
              else {
                pcVar3 = "DISPATCHCLASS MISMATCH: SkipAIPCheck: %d and %d";
              }
            }
            else {
              pcVar3 = "DISPATCHCLASS MISMATCH: DispatchState: %d and %d";
            }
          }
          else {
            pcVar3 = "DISPATCHCLASS MISMATCH: DispatchType: %d and %d";
          }
        }
        else {
          pcVar3 = "DISPATCHCLASS MISMATCH: CurrTeam: %d and %d";
        }
LAB_4fc1efec:
        FormatLogMessage(pcVar3);
        return false;
      }
      memset(local_4c,0,0x40);
      memset(local_8c,0,0x40);
      GetODFName(unaff_EDI,unaff_ESI);
      GetODFName(unaff_EDI,unaff_ESI);
      pcVar3 = "DISPATCHCLASS MISMATCH: FleeTarget: %08x \'%s\' and %08x \'%s\'";
    }
    else {
      memset(local_4c,0,0x40);
      memset(local_8c,0,0x40);
      GetODFName(unaff_EDI,unaff_ESI);
      GetODFName(unaff_EDI,unaff_ESI);
      pcVar3 = "DISPATCHCLASS MISMATCH: DispatchTarget: %08x \'%s\' and %08x \'%s\'";
    }
  }
  else {
    memset(local_8c,0,0x40);
    memset(local_4c,0,0x40);
    GetODFName(unaff_EDI,unaff_ESI);
    GetODFName(unaff_EDI,unaff_ESI);
    pcVar3 = "DISPATCHCLASS MISMATCH: DispatchObject: %08x \'%s\' and %08x \'%s\'";
  }
LAB_4fc1eed7:
  FormatLogMessage(pcVar3);
  return false;
}

