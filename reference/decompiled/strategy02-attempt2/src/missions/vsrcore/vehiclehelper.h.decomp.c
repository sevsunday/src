// Reconstructed by Ghidra from Strategy02.dll + Strategy02.pdb
// Original source file: /e:/github/vsr_dll_source/missions/vsrcore/vehiclehelper.h
// Functions are ordered by original source line. This is decompiler
// output, not the author's source: names/types come from the PDB,
// local variable names and control flow are reconstructed.

// ---------------------------------------------------------------------
// operator==  @ 4fc23eb2  lines 46-164

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool __cdecl operator==(VehicleClass *a,VehicleClass *b)

{
  float fVar1;
  float fVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  int h;
  undefined4 unaff_EDI;
  char *pcVar8;
  char ODFNameA [64];
  char ODFNameB [68];
  uint local_8;
  
  local_8 = __security_cookie ^ (uint)&stack0xfffffffc;
  h = a->ObjectHandle;
  if (h == b->ObjectHandle) {
    if (a->ODFNameHash == b->ODFNameHash) {
      if (a->ObjClassHash == b->ObjClassHash) {
        if (a->BZCClassHash == b->BZCClassHash) {
          if (a->LastCommand == b->LastCommand) {
            if (a->MaxHealth == b->MaxHealth) {
              if (a->ShowSkill == b->ShowSkill) {
                if (a->BlockDeploy == b->BlockDeploy) {
                  if (a->AllowRemoteControl == b->AllowRemoteControl) {
                    if (a->CanBeIdleVictim == b->CanBeIdleVictim) {
                      if (a->ShowSkillTeamFilter == b->ShowSkillTeamFilter) {
                        if (a->ShowSkillTimer == b->ShowSkillTimer) {
                          if (a->CurTeamNum == b->CurTeamNum) {
                            if (a->PTeam == b->PTeam) {
                              if (a->CloakMaxEnergy == b->CloakMaxEnergy) {
                                if (a->CloakCurEnergy == b->CloakCurEnergy) {
                                  if (a->CloakCostEnergy == b->CloakCostEnergy) {
                                    if (a->CloakAddEnergy == b->CloakAddEnergy) {
                                      if (a->EngageRange == b->EngageRange) {
                                        fVar1 = (b->Position).x;
                                        fVar2 = (a->Position).x;
                                        if (((fVar2 == fVar1) &&
                                            ((a->Position).y == (b->Position).y)) &&
                                           ((a->Position).z == (b->Position).z)) {
                                          return true;
                                        }
                                        dVar3 = (double)(b->Position).z;
                                        dVar4 = (double)(b->Position).y;
                                        dVar5 = (double)fVar1;
                                        dVar6 = (double)(a->Position).z;
                                        dVar7 = (double)(a->Position).y;
                                        FormatLogMessage(
                                                  "VEHICLELIST MISMATCH: Position: %f %f %f and %f %f %f"
                                                  ,(double)CONCAT44(SUB84(dVar7,0),
                                                                    (int)((ulonglong)(double)fVar2
                                                                         >> 0x20)),
                                                  (double)CONCAT44(SUB84(dVar6,0),
                                                                   (int)((ulonglong)dVar7 >> 0x20)),
                                                  (double)CONCAT44(SUB84(dVar5,0),
                                                                   (int)((ulonglong)dVar6 >> 0x20)),
                                                  (double)CONCAT44(SUB84(dVar4,0),
                                                                   (int)((ulonglong)dVar5 >> 0x20)),
                                                  (double)CONCAT44(SUB84(dVar3,0),
                                                                   (int)((ulonglong)dVar4 >> 0x20)),
                                                  (double)CONCAT44(unaff_EDI,
                                                                   (int)((ulonglong)dVar3 >> 0x20)))
                                        ;
                                        return false;
                                      }
                                      pcVar8 = "VEHICLELIST MISMATCH: EngageRange: %f and %f";
                                      goto LAB_4fc23f20;
                                    }
                                    pcVar8 = "VEHICLELIST MISMATCH: CloakAddEnergy: %d and %d";
                                  }
                                  else {
                                    pcVar8 = "VEHICLELIST MISMATCH: CloakCostEnergy: %d and %d";
                                  }
                                }
                                else {
                                  pcVar8 = "VEHICLELIST MISMATCH: CloakCurEnergy: %d and %d";
                                }
                              }
                              else {
                                pcVar8 = "VEHICLELIST MISMATCH: CloakMaxEnergy: %d and %d";
                              }
                            }
                            else {
                              pcVar8 = "VEHICLELIST MISMATCH: PTeam: %d and %d";
                            }
                          }
                          else {
                            pcVar8 = "VEHICLELIST MISMATCH: CurTeamNum: %d and %d";
                          }
                        }
                        else {
                          pcVar8 = "VEHICLELIST MISMATCH: ShowSkillTimer: %d and %d";
                        }
                      }
                      else {
                        pcVar8 = "VEHICLELIST MISMATCH: ShowSkillTeamFilter: %d and %d";
                      }
                    }
                    else {
                      pcVar8 = "VEHICLELIST MISMATCH: CanBeIdleVictim: %d and %d";
                    }
                  }
                  else {
                    pcVar8 = "VEHICLELIST MISMATCH: AllowRemoteControl: %d and %d";
                  }
                }
                else {
                  pcVar8 = "VEHICLELIST MISMATCH: BlockDeploy: %d and %d";
                }
              }
              else {
                pcVar8 = "VEHICLELIST MISMATCH: ShowSkill: %d and %d";
              }
            }
            else {
              pcVar8 = "VEHICLELIST MISMATCH: MaxHealth: %d and %d";
            }
          }
          else {
            pcVar8 = "VEHICLELIST MISMATCH: LastCommand: %d and %d";
          }
        }
        else {
          pcVar8 = "VEHICLELIST MISMATCH: BZCClassHash: %d and %d";
        }
      }
      else {
        pcVar8 = "VEHICLELIST MISMATCH: ObjClassHash: %d and %d";
      }
    }
    else {
      pcVar8 = "VEHICLELIST MISMATCH: ODFNameHash: %d and %d";
    }
    FormatLogMessage(pcVar8);
  }
  else {
    memset(ODFNameA,0,0x40);
    memset(ODFNameB,0,0x40);
    GetODFName(h,ODFNameA);
    GetODFName(b->ObjectHandle,ODFNameB);
    pcVar8 = "VEHICLELIST MISMATCH: ObjectHandle: %08x \'%s\' and %08x \'%s\'";
LAB_4fc23f20:
    FormatLogMessage(pcVar8);
  }
  return false;
}


// ---------------------------------------------------------------------
// BZ1Helper::ShouldRemoveAlignTerrainReplace  @ 4fc0b065  lines 171-171

bool __cdecl BZ1Helper::ShouldRemoveAlignTerrainReplace(AlignTerrainReplaceClass *entry)

{
  bool bVar1;
  
  bVar1 = IsAround(entry->AlignHandle);
  return (bool)('\x01' - bVar1);
}


