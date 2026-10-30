// Reconstructed by Ghidra from Strategy02.dll + Strategy02.pdb
// Original source file: /e:/github/vsr_dll_source/missions/vsrcore/morphobjecthelper.h
// Functions are ordered by original source line. This is decompiler
// output, not the author's source: names/types come from the PDB,
// local variable names and control flow are reconstructed.

// ---------------------------------------------------------------------
// operator==  @ 4fc1610e  lines 41-178

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool __cdecl operator==(MorphObjectClass *a,MorphObjectClass *b)

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
  int iVar10;
  undefined4 unaff_EDI;
  char *pcVar11;
  char local_8c [64];
  char local_4c [68];
  uint local_8;
  
  local_8 = __security_cookie ^ (uint)local_8c;
  iVar8 = a->MorphObject;
  if (iVar8 == b->MorphObject) {
    iVar8 = a->CurrentWho;
    if (iVar8 == b->CurrentWho) {
      if (a->WeaponActive == b->WeaponActive) {
        if (a->ObjectSwitch == b->ObjectSwitch) {
          if (a->CanFire == b->CanFire) {
            if (a->IsCloaker == b->IsCloaker) {
              if (a->IdleTime == b->IdleTime) {
                if (a->NormalAmmo == b->NormalAmmo) {
                  if (a->MaxAmmo == b->MaxAmmo) {
                    if (a->Command == b->Command) {
                      if (a->PTeam == b->PTeam) {
                        iVar10 = 0;
                        pfVar9 = b->LocalAmmo;
                        iVar8 = 0;
                        do {
                          if (*(float *)((int)pfVar9 + ((int)a - (int)b)) != *pfVar9) {
                            pcVar11 = "MORPHOBJECTCLASS MISMATCH: LocalAmmo%d: %f and %f";
                            goto LAB_4fc164a6;
                          }
                          iVar8 = iVar8 + 1;
                          pfVar9 = pfVar9 + 1;
                        } while (iVar8 < 5);
                        if (a->EngageRange != b->EngageRange) {
                          pcVar11 = "MORPHOBJECTCLASS MISMATCH: EngageRange: %f and %f";
                          goto LAB_4fc1617b;
                        }
                        pfVar9 = b->CloakChance;
                        do {
                          if (*(float *)((int)pfVar9 + ((int)a - (int)b)) != *pfVar9) {
                            pcVar11 = "MORPHOBJECTCLASS MISMATCH: CloakChance%d: %f and %f";
LAB_4fc164a6:
                            FormatLogMessage(pcVar11);
                            return false;
                          }
                          iVar10 = iVar10 + 1;
                          pfVar9 = pfVar9 + 1;
                        } while (iVar10 < 0x36);
                        fVar1 = (b->CurrentWhere).x;
                        fVar2 = (a->CurrentWhere).x;
                        if (((fVar2 != fVar1) || ((a->CurrentWhere).y != (b->CurrentWhere).y)) ||
                           ((a->CurrentWhere).z != (b->CurrentWhere).z)) {
                          dVar3 = (double)(b->CurrentWhere).z;
                          dVar4 = (double)(b->CurrentWhere).y;
                          dVar5 = (double)fVar1;
                          dVar6 = (double)(a->CurrentWhere).z;
                          dVar7 = (double)(a->CurrentWhere).y;
                          FormatLogMessage("MORPHOBJECTCLASS MISMATCH: CurrentWhere: %f %f %f and %f %f %f"
                                           ,(double)CONCAT44(SUB84(dVar7,0),
                                                             (int)((ulonglong)(double)fVar2 >> 0x20)
                                                            ),
                                           (double)CONCAT44(SUB84(dVar6,0),
                                                            (int)((ulonglong)dVar7 >> 0x20)),
                                           (double)CONCAT44(SUB84(dVar5,0),
                                                            (int)((ulonglong)dVar6 >> 0x20)),
                                           (double)CONCAT44(SUB84(dVar4,0),
                                                            (int)((ulonglong)dVar5 >> 0x20)),
                                           (double)CONCAT44(SUB84(dVar3,0),
                                                            (int)((ulonglong)dVar4 >> 0x20)),
                                           (double)CONCAT44(unaff_EDI,
                                                            (int)((ulonglong)dVar3 >> 0x20)));
                          return false;
                        }
                        if (a->BlockDeploy == b->BlockDeploy) {
                          if (a->CloakMaxEnergy == b->CloakMaxEnergy) {
                            if (a->CloakCurEnergy == b->CloakCurEnergy) {
                              if (a->CloakCostEnergy == b->CloakCostEnergy) {
                                if (a->CloakAddEnergy == b->CloakAddEnergy) {
                                  if (a->CloakCurEnergyRemainder == b->CloakCurEnergyRemainder) {
                                    return true;
                                  }
                                  pcVar11 = 
                                  "MORPHOBJECTCLASS MISMATCH: CloakCurEnergyRemainder: %f and %f";
                                  goto LAB_4fc1617b;
                                }
                                pcVar11 = "MORPHOBJECTCLASS MISMATCH: CloakAddEnergy: %d and %d";
                              }
                              else {
                                pcVar11 = "MORPHOBJECTCLASS MISMATCH: CloakCostEnergy: %d and %d";
                              }
                            }
                            else {
                              pcVar11 = "MORPHOBJECTCLASS MISMATCH: CloakCurEnergy: %d and %d";
                            }
                          }
                          else {
                            pcVar11 = "MORPHOBJECTCLASS MISMATCH: CloakMaxEnergy: %d and %d";
                          }
                        }
                        else {
                          pcVar11 = "MORPHOBJECTCLASS MISMATCH: BlockDeploy: %d and %d";
                        }
                      }
                      else {
                        pcVar11 = "MORPHOBJECTCLASS MISMATCH: PTeam: %d and %d";
                      }
                    }
                    else {
                      pcVar11 = "MORPHOBJECTCLASS MISMATCH: Command: %d and %d";
                    }
                  }
                  else {
                    pcVar11 = "MORPHOBJECTCLASS MISMATCH: MaxAmmo: %d and %d";
                  }
                }
                else {
                  pcVar11 = "MORPHOBJECTCLASS MISMATCH: NormalAmmo: %d and %d";
                }
              }
              else {
                pcVar11 = "MORPHOBJECTCLASS MISMATCH: IdleTime: %d and %d";
              }
            }
            else {
              pcVar11 = "MORPHOBJECTCLASS MISMATCH: IsCloaker: %d and %d";
            }
          }
          else {
            pcVar11 = "MORPHOBJECTCLASS MISMATCH: CanFire: %d and %d";
          }
        }
        else {
          pcVar11 = "MORPHOBJECTCLASS MISMATCH: ObjectSwitch: %d and %d";
        }
      }
      else {
        pcVar11 = "MORPHOBJECTCLASS MISMATCH: WeaponActive: %d and %d";
      }
      FormatLogMessage(pcVar11);
      return false;
    }
    memset(local_8c,0,0x40);
    memset(local_4c,0,0x40);
    GetODFName(iVar8,local_8c);
    GetODFName(b->CurrentWho,local_4c);
    pcVar11 = "MORPHOBJECTCLASS MISMATCH: CurrentWho: %08x \'%s\' and %08x \'%s\'";
  }
  else {
    memset(local_4c,0,0x40);
    memset(local_8c,0,0x40);
    GetODFName(iVar8,local_4c);
    GetODFName(b->MorphObject,local_8c);
    pcVar11 = "MORPHOBJECTCLASS MISMATCH: MorphObject: %08x \'%s\' and %08x \'%s\'";
  }
LAB_4fc1617b:
  FormatLogMessage(pcVar11);
  return false;
}


