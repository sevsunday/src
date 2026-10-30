// Reconstructed by Ghidra from Strategy02.dll + Strategy02.pdb
// Original source file: /e:/github/vsr_dll_source/missions/vsrcore/dispatchhelper.h
// Functions are ordered by original source line. This is decompiler
// output, not the author's source: names/types come from the PDB,
// local variable names and control flow are reconstructed.

// ---------------------------------------------------------------------
// operator==  @ 4fc1f889  lines 89-295

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool __cdecl operator==(DispatchClass *a,DispatchClass *b)

{
  float fVar1;
  float fVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  int iVar8;
  float *pfVar9;
  undefined4 unaff_EDI;
  char *pcVar10;
  char ODFNameA__ODFNameB [64];
  char ODFNameB__ODFNameA [68];
  uint local_8;
  
  local_8 = __security_cookie ^ (uint)&stack0xfffffffc;
  iVar8 = a->DispatchObject;
  if (iVar8 == b->DispatchObject) {
    iVar8 = a->DispatchTarget;
    if (iVar8 == b->DispatchTarget) {
      iVar8 = a->FleeTarget;
      if (iVar8 == b->FleeTarget) {
        fVar1 = (b->DispatchSpot).x;
        fVar2 = (a->DispatchSpot).x;
        if (((fVar2 != fVar1) || ((a->DispatchSpot).y != (b->DispatchSpot).y)) ||
           ((a->DispatchSpot).z != (b->DispatchSpot).z)) {
          dVar3 = (double)(b->DispatchSpot).z;
          dVar4 = (double)(b->DispatchSpot).y;
          dVar5 = (double)fVar1;
          dVar6 = (double)(a->DispatchSpot).z;
          dVar7 = (double)(a->DispatchSpot).y;
          FormatLogMessage("DISPATCHCLASS MISMATCH: DispatchSpot: %f %f %f and %f %f %f",
                           (double)CONCAT44(SUB84(dVar7,0),(int)((ulonglong)(double)fVar2 >> 0x20)),
                           (double)CONCAT44(SUB84(dVar6,0),(int)((ulonglong)dVar7 >> 0x20)),
                           (double)CONCAT44(SUB84(dVar5,0),(int)((ulonglong)dVar6 >> 0x20)),
                           (double)CONCAT44(SUB84(dVar4,0),(int)((ulonglong)dVar5 >> 0x20)),
                           (double)CONCAT44(SUB84(dVar3,0),(int)((ulonglong)dVar4 >> 0x20)),
                           (double)CONCAT44(unaff_EDI,(int)((ulonglong)dVar3 >> 0x20)));
          return false;
        }
        if (a->CurrTeam == b->CurrTeam) {
          if (a->DispatchType == b->DispatchType) {
            if (a->DispatchState == b->DispatchState) {
              if (a->SkipAIPCheck == b->SkipAIPCheck) {
                if (a->IsCloaker == b->IsCloaker) {
                  if (a->IsMorpher == b->IsMorpher) {
                    if (a->CanFlee == b->CanFlee) {
                      if (a->CanGetReload == b->CanGetReload) {
                        if (a->CanGetRepair == b->CanGetRepair) {
                          if (a->MorphIsAssault == b->MorphIsAssault) {
                            if (a->IsCloaked == b->IsCloaked) {
                              if (a->CloakLocked == b->CloakLocked) {
                                if (a->CloakNextTick == b->CloakNextTick) {
                                  if (a->DecloakNextTick == b->DecloakNextTick) {
                                    if (a->IdleTime == b->IdleTime) {
                                      if (a->CloakIdleTime == b->CloakIdleTime) {
                                        if (a->DeployTimer == b->DeployTimer) {
                                          if (a->ServiceTimer == b->ServiceTimer) {
                                            if (a->RandomDist == b->RandomDist) {
                                              if (a->EngageRange == b->EngageRange) {
                                                if (a->TimeDeploy == b->TimeDeploy) {
                                                  pfVar9 = b->CloakChance;
                                                  iVar8 = 0;
                                                  do {
                                                    fVar1 = *(float *)(((int)a - (int)b) +
                                                                      (int)pfVar9);
                                                    if (fVar1 != *pfVar9) {
                                                      FormatLogMessage(
                                                  "DISPATCHCLASS MISMATCH: CloakChance%d: %f and %f"
                                                  ,iVar8,(double)fVar1,(double)*pfVar9);
                                                  return false;
                                                  }
                                                  iVar8 = iVar8 + 1;
                                                  pfVar9 = pfVar9 + 1;
                                                  } while (iVar8 < 0x36);
                                                  if (a->FleeHealthRatio == b->FleeHealthRatio) {
                                                    if (a->GetRepairRatio == b->GetRepairRatio) {
                                                      if (a->ServiceChance == b->ServiceChance) {
                                                        if (a->MinFireAmmo == b->MinFireAmmo) {
                                                          if (a->MaxHealth == b->MaxHealth) {
                                                            if (a->MaxAmmo == b->MaxAmmo) {
                                                              if (a->Command == b->Command) {
                                                                if (a->FleeHealthValue ==
                                                                    b->FleeHealthValue) {
                                                                  if (a->CloakPriority ==
                                                                      b->CloakPriority) {
                                                                    return true;
                                                                  }
                                                                  pcVar10 = 
                                                  "DISPATCHCLASS MISMATCH: CloakPriority: %d and %d"
                                                  ;
                                                  }
                                                  else {
                                                    pcVar10 = 
                                                  "DISPATCHCLASS MISMATCH: FleeHealthValue: %d and %d"
                                                  ;
                                                  }
                                                  }
                                                  else {
                                                    pcVar10 = 
                                                  "DISPATCHCLASS MISMATCH: Command: %d and %d";
                                                  }
                                                  }
                                                  else {
                                                    pcVar10 = 
                                                  "DISPATCHCLASS MISMATCH: MaxAmmo: %d and %d";
                                                  }
                                                  }
                                                  else {
                                                    pcVar10 = 
                                                  "DISPATCHCLASS MISMATCH: MaxHealth: %d and %d";
                                                  }
                                                  }
                                                  else {
                                                    pcVar10 = 
                                                  "DISPATCHCLASS MISMATCH: MinFireAmmo: %d and %d";
                                                  }
                                                  goto LAB_4fc1fa0c;
                                                  }
                                                  pcVar10 = 
                                                  "DISPATCHCLASS MISMATCH: ServiceChance: %f and %f"
                                                  ;
                                                  }
                                                  else {
                                                    pcVar10 = 
                                                  "DISPATCHCLASS MISMATCH: GetRepairRatio: %f and %f"
                                                  ;
                                                  }
                                                  }
                                                  else {
                                                    pcVar10 = 
                                                  "DISPATCHCLASS MISMATCH: FleeHealthRatio: %f and %f"
                                                  ;
                                                  }
                                                }
                                                else {
                                                  pcVar10 = 
                                                  "DISPATCHCLASS MISMATCH: TimeDeploy: %f and %f";
                                                }
                                              }
                                              else {
                                                pcVar10 = 
                                                "DISPATCHCLASS MISMATCH: EngageRange: %f and %f";
                                              }
                                            }
                                            else {
                                              pcVar10 = 
                                              "DISPATCHCLASS MISMATCH: RandomDist: %f and %f";
                                            }
                                            goto LAB_4fc1f8f7;
                                          }
                                          pcVar10 = 
                                          "DISPATCHCLASS MISMATCH: ServiceTimer: %d and %d";
                                        }
                                        else {
                                          pcVar10 = "DISPATCHCLASS MISMATCH: DeployTimer: %d and %d"
                                          ;
                                        }
                                      }
                                      else {
                                        pcVar10 = "DISPATCHCLASS MISMATCH: CloakIdleTime: %d and %d"
                                        ;
                                      }
                                    }
                                    else {
                                      pcVar10 = "DISPATCHCLASS MISMATCH: IdleTime: %d and %d";
                                    }
                                  }
                                  else {
                                    pcVar10 = "DISPATCHCLASS MISMATCH: DecloakNextTick: %d and %d";
                                  }
                                }
                                else {
                                  pcVar10 = "DISPATCHCLASS MISMATCH: CloakNextTick: %d and %d";
                                }
                              }
                              else {
                                pcVar10 = "DISPATCHCLASS MISMATCH: CloakLocked: %d and %d";
                              }
                            }
                            else {
                              pcVar10 = "DISPATCHCLASS MISMATCH: IsCloaked: %d and %d";
                            }
                          }
                          else {
                            pcVar10 = "DISPATCHCLASS MISMATCH: MorphIsAssault: %d and %d";
                          }
                        }
                        else {
                          pcVar10 = "DISPATCHCLASS MISMATCH: CanGetRepair: %d and %d";
                        }
                      }
                      else {
                        pcVar10 = "DISPATCHCLASS MISMATCH: CanGetReload: %d and %d";
                      }
                    }
                    else {
                      pcVar10 = "DISPATCHCLASS MISMATCH: CanFlee: %d and %d";
                    }
                  }
                  else {
                    pcVar10 = "DISPATCHCLASS MISMATCH: IsMorpher: %d and %d";
                  }
                }
                else {
                  pcVar10 = "DISPATCHCLASS MISMATCH: IsCloaker: %d and %d";
                }
              }
              else {
                pcVar10 = "DISPATCHCLASS MISMATCH: SkipAIPCheck: %d and %d";
              }
            }
            else {
              pcVar10 = "DISPATCHCLASS MISMATCH: DispatchState: %d and %d";
            }
          }
          else {
            pcVar10 = "DISPATCHCLASS MISMATCH: DispatchType: %d and %d";
          }
        }
        else {
          pcVar10 = "DISPATCHCLASS MISMATCH: CurrTeam: %d and %d";
        }
LAB_4fc1fa0c:
        FormatLogMessage(pcVar10);
        return false;
      }
      memset(ODFNameB__ODFNameA,0,0x40);
      memset(ODFNameA__ODFNameB,0,0x40);
      GetODFName(iVar8,ODFNameB__ODFNameA);
      GetODFName(b->FleeTarget,ODFNameA__ODFNameB);
      pcVar10 = "DISPATCHCLASS MISMATCH: FleeTarget: %08x \'%s\' and %08x \'%s\'";
    }
    else {
      memset(ODFNameB__ODFNameA,0,0x40);
      memset(ODFNameA__ODFNameB,0,0x40);
      GetODFName(iVar8,ODFNameB__ODFNameA);
      GetODFName(b->DispatchTarget,ODFNameA__ODFNameB);
      pcVar10 = "DISPATCHCLASS MISMATCH: DispatchTarget: %08x \'%s\' and %08x \'%s\'";
    }
  }
  else {
    memset(ODFNameA__ODFNameB,0,0x40);
    memset(ODFNameB__ODFNameA,0,0x40);
    GetODFName(iVar8,ODFNameA__ODFNameB);
    GetODFName(b->DispatchObject,ODFNameB__ODFNameA);
    pcVar10 = "DISPATCHCLASS MISMATCH: DispatchObject: %08x \'%s\' and %08x \'%s\'";
  }
LAB_4fc1f8f7:
  FormatLogMessage(pcVar10);
  return false;
}


