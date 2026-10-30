// Reconstructed by Ghidra from Strategy02.dll + Strategy02.pdb
// Original source file: /e:/github/vsr_dll_source/missions/vsrcore/buildinghelper.h
// Functions are ordered by original source line. This is decompiler
// output, not the author's source: names/types come from the PDB,
// local variable names and control flow are reconstructed.

// ---------------------------------------------------------------------
// operator==  @ 4fc1d1d8  lines 69-341

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool __cdecl operator==(BuildingClass *a,BuildingClass *b)

{
  double dVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  double dVar10;
  Vector *pVVar11;
  int *piVar12;
  float *pfVar13;
  int iVar14;
  char (*_Str1) [64];
  undefined4 unaff_EBP;
  int iVar15;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  char *pcVar16;
  undefined1 auStack_a4 [3];
  char local_a1;
  BuildingClass *local_a0;
  int local_9c;
  int *local_98;
  int local_94;
  int local_90;
  char local_8c [64];
  char local_4c [68];
  uint local_8;
  
  local_8 = __security_cookie ^ (uint)auStack_a4;
  iVar14 = a->BuildingObject;
  local_a0 = a;
  if (iVar14 != b->BuildingObject) {
    memset(local_4c,0,0x40);
    memset(local_8c,0,0x40);
    GetODFName(iVar14,local_4c);
    GetODFName(b->BuildingObject,local_8c);
    pcVar16 = "BUILDINGCLASS MISMATCH: BuildingObject: %08x \'%s\' and %08x \'%s\'";
    goto LAB_4fc1d249;
  }
  local_98 = a->BuildingTap;
  pfVar13 = &a->TapOffsetMatrix[0].front.z;
  pVVar11 = &b->TapOffsetMatrix[0].front;
  local_94 = (int)b - (int)a;
  iVar14 = 0;
  local_9c = (int)a - (int)b;
  do {
    local_90 = *local_98;
    iVar15 = 0;
    if (local_90 != *(int *)(local_94 + (int)local_98)) {
      memset(local_8c,0,0x40);
      memset(local_4c,0,0x40);
      GetODFName(local_90,local_8c);
      GetODFName(b->BuildingTap[iVar14],local_4c);
      FormatLogMessage("BUILDINGCLASS MISMATCH: BuildingTap%d: %08x \'%s\' and %08x \'%s\'",iVar14,
                       a->BuildingTap[iVar14],local_8c,b->BuildingTap[iVar14],local_4c);
      return false;
    }
    local_a1 = a->TapAnimated[iVar14];
    if ((bool)local_a1 != b->TapAnimated[iVar14]) {
      pcVar16 = "BUILDINGCLASS MISMATCH: TapAnimated%d: %d and %d";
      goto LAB_4fc1d998;
    }
    local_a1 = a->PlayTapAnim[iVar14];
    if ((bool)local_a1 != b->PlayTapAnim[iVar14]) {
      pcVar16 = "BUILDINGCLASS MISMATCH: PlayTapAnim%d: %d and %d";
      goto LAB_4fc1d998;
    }
    if (((((((*(float *)(local_9c + (int)pVVar11) != pVVar11->x) || (pfVar13[-1] != pVVar11->y)) ||
           (*pfVar13 != pVVar11->z)) ||
          ((pfVar13[-10] != *(float *)((int)(pVVar11 + -3) + 4) ||
           (pfVar13[-9] != *(float *)((int)(pVVar11 + -3) + 8))))) ||
         ((pfVar13[-8] != pVVar11[-2].x ||
          ((pfVar13[-6] != *(float *)((int)(pVVar11 + -2) + 8) || (pfVar13[-5] != pVVar11[-1].x)))))
         ) || (pfVar13[-4] != *(float *)((int)(pVVar11 + -1) + 4))) ||
       (((pfVar13[2] != ((Vector *)((int)(pVVar11 + 1) + 4))->x ||
         (pfVar13[3] != *(float *)((int)(pVVar11 + 1) + 8))) || (pfVar13[4] != pVVar11[2].x)))) {
      dVar1 = (double)b->TapOffsetMatrix[iVar14].posit.z;
      dVar2 = (double)b->TapOffsetMatrix[iVar14].posit.y;
      dVar3 = (double)b->TapOffsetMatrix[iVar14].posit.x;
      dVar4 = (double)a->TapOffsetMatrix[iVar14].posit.z;
      dVar5 = (double)a->TapOffsetMatrix[iVar14].posit.x;
      dVar6 = (double)b->TapOffsetMatrix[iVar14].right.z;
      dVar7 = (double)b->TapOffsetMatrix[iVar14].right.y;
      dVar8 = (double)b->TapOffsetMatrix[iVar14].right.x;
      dVar9 = (double)a->TapOffsetMatrix[iVar14].right.z;
      dVar10 = (double)a->TapOffsetMatrix[iVar14].right.y;
      FormatLogMessage("BUILDINGCLASS MISMATCH: TapOffsetMatrix%d Front: %f %f %f and %f %f %f, TapOffsetMatrix%d Right: %f %f %f and %f %f %f, TapOffsetMatrix%d Up: %f %f %f and %f %f %f, TapOffsetMatrix%d Posit: %f %f %f and %f %f %f"
                       ,iVar14,(double)*(float *)(local_9c + (int)pVVar11),
                       (double)a->TapOffsetMatrix[iVar14].front.y,
                       (double)a->TapOffsetMatrix[iVar14].front.z,(double)pVVar11->x,
                       (double)b->TapOffsetMatrix[iVar14].front.y,
                       (double)b->TapOffsetMatrix[iVar14].front.z,iVar14,
                       (double)CONCAT44(SUB84(dVar10,0),
                                        (int)((ulonglong)(double)a->TapOffsetMatrix[iVar14].right.x
                                             >> 0x20)),
                       (double)CONCAT44(SUB84(dVar9,0),(int)((ulonglong)dVar10 >> 0x20)),
                       (double)CONCAT44(SUB84(dVar8,0),(int)((ulonglong)dVar9 >> 0x20)),
                       (double)CONCAT44(SUB84(dVar7,0),(int)((ulonglong)dVar8 >> 0x20)),
                       (double)CONCAT44(SUB84(dVar6,0),(int)((ulonglong)dVar7 >> 0x20)),
                       (double)CONCAT44(iVar14,(int)((ulonglong)dVar6 >> 0x20)),
                       SUB84((double)a->TapOffsetMatrix[iVar14].up.x,0),
                       (double)a->TapOffsetMatrix[iVar14].up.y,
                       (double)a->TapOffsetMatrix[iVar14].up.z,
                       (double)b->TapOffsetMatrix[iVar14].up.x,
                       (double)b->TapOffsetMatrix[iVar14].up.y,
                       (double)b->TapOffsetMatrix[iVar14].up.z,
                       (double)CONCAT44(SUB84(dVar5,0),iVar14),(int)((ulonglong)dVar5 >> 0x20),
                       (double)CONCAT44(SUB84(dVar4,0),
                                        (int)((ulonglong)(double)a->TapOffsetMatrix[iVar14].posit.y
                                             >> 0x20)),
                       (double)CONCAT44(SUB84(dVar3,0),(int)((ulonglong)dVar4 >> 0x20)),
                       (double)CONCAT44(SUB84(dVar2,0),(int)((ulonglong)dVar3 >> 0x20)),
                       (double)CONCAT44(SUB84(dVar1,0),(int)((ulonglong)dVar2 >> 0x20)),
                       (double)CONCAT44(unaff_EDI,(int)((ulonglong)dVar1 >> 0x20)),
                       (double)CONCAT44(unaff_EBP,unaff_ESI));
      return false;
    }
    local_98 = local_98 + 1;
    iVar14 = iVar14 + 1;
    pfVar13 = pfVar13 + 0x10;
    pVVar11 = (Vector *)((int)(pVVar11 + 5) + 4);
  } while (iVar14 < 8);
  if (a->IsPowered == b->IsPowered) {
    if (a->IsAnimated == b->IsAnimated) {
      if (a->PlayAnim == b->PlayAnim) {
        if (a->CanCollide == b->CanCollide) {
          if (a->CanBeIdleVictim == b->CanBeIdleVictim) {
            if (a->IsAPCRefill == b->IsAPCRefill) {
              if (a->IsRecyclePoint == b->IsRecyclePoint) {
                if (a->GunTowerOff == b->GunTowerOff) {
                  if (a->CanDemolish == b->CanDemolish) {
                    if (a->PoweredByTaps == b->PoweredByTaps) {
                      if (a->OwnsTerrain == b->OwnsTerrain) {
                        if (a->ObjClassHash == b->ObjClassHash) {
                          if (a->ODFNameHash == b->ODFNameHash) {
                            if (a->PowerType == b->PowerType) {
                              if (a == b) {
                                if (a->TapNumber == b->TapNumber) {
                                  if (a->PowerState == b->PowerState) {
                                    if (a->PowerMask == b->PowerMask) {
                                      if (a->PowerMatch == b->PowerMatch) {
                                        if (a->PowerProvide == b->PowerProvide) {
                                          if (a->PowerupAcceptMask == b->PowerupAcceptMask) {
                                            if (a->CurTeamNum == b->CurTeamNum) {
                                              if (a->PTeam == b->PTeam) {
                                                if (a->MaxHealth == b->MaxHealth) {
                                                  if (a->MaxAmmo == b->MaxAmmo) {
                                                    piVar12 = a->TerrainSizeRatio;
                                                    iVar14 = iVar15;
                                                    do {
                                                      local_a0 = *(BuildingClass **)
                                                                  (local_94 + (int)piVar12);
                                                      if (*piVar12 !=
                                                          *(int *)(local_94 + (int)piVar12)) {
                                                        pcVar16 = 
                                                  "BUILDINGCLASS MISMATCH: TerrainSizeRatio%d: %d and %d"
                                                  ;
                                                  goto LAB_4fc1d998;
                                                  }
                                                  iVar14 = iVar14 + 1;
                                                  piVar12 = piVar12 + 1;
                                                  } while (iVar14 < 2);
                                                  if (a->BuildSupport == b->BuildSupport) {
                                                    if (a->CollisionRadius != b->CollisionRadius) {
                                                      pcVar16 = 
                                                  "BUILDINGCLASS MISMATCH: CollisionRadius: %f and %f"
                                                  ;
LAB_4fc1d249:
                                                  FormatLogMessage(pcVar16);
                                                  return false;
                                                  }
                                                  local_a0 = (BuildingClass *)a->UpgradeName;
                                                  iVar14 = _stricmp((char *)local_a0,b->UpgradeName)
                                                  ;
                                                  if (iVar14 == 0) {
                                                    _Str1 = a->WeaponNames;
                                                    do {
                                                      local_a0 = (BuildingClass *)
                                                                 (*_Str1 + local_94);
                                                      iVar14 = _stricmp(*_Str1,(char *)local_a0);
                                                      if (iVar14 != 0) {
                                                        pcVar16 = 
                                                  "BUILDINGCLASS MISMATCH: WeaponNames%d: \'%s\' and \'%s\'"
                                                  ;
LAB_4fc1d998:
                                                  FormatLogMessage(pcVar16);
                                                  return false;
                                                  }
                                                  iVar15 = iVar15 + 1;
                                                  _Str1 = _Str1 + 1;
                                                  } while (iVar15 < 5);
                                                  if ((((a->Position).x == (b->Position).x) &&
                                                      ((a->Position).y == (b->Position).y)) &&
                                                     ((a->Position).z == (b->Position).z)) {
                                                    if ((((a->BuildingFront).x ==
                                                          (b->BuildingFront).x) &&
                                                        ((a->BuildingFront).y ==
                                                         (b->BuildingFront).y)) &&
                                                       ((a->BuildingFront).z == (b->BuildingFront).z
                                                       )) {
                                                      if (a->HealthRate == b->HealthRate) {
                                                        if (a->AmmoRate == b->AmmoRate) {
                                                          if (a->LocalAmmoRate == b->LocalAmmoRate)
                                                          {
                                                            if (a->ServiceRate == b->ServiceRate) {
                                                              if (a->ServiceCraft == b->ServiceCraft
                                                                 ) {
                                                                return true;
                                                              }
                                                              pcVar16 = 
                                                  "OBJECTLIST MISMATCH: ServiceCraft: %d and %d";
                                                  goto LAB_4fc1d3e2;
                                                  }
                                                  pcVar16 = 
                                                  "OBJECTLIST MISMATCH: ServiceRate: %f and %f";
                                                  }
                                                  else {
                                                    pcVar16 = 
                                                  "OBJECTLIST MISMATCH: LocalAmmoRate: %f and %f";
                                                  }
                                                  }
                                                  else {
                                                    pcVar16 = 
                                                  "OBJECTLIST MISMATCH: AmmoRate: %f and %f";
                                                  }
                                                  }
                                                  else {
                                                    pcVar16 = 
                                                  "OBJECTLIST MISMATCH: HealthRate: %f and %f";
                                                  }
                                                  goto LAB_4fc1d249;
                                                  }
                                                  pcVar16 = 
                                                  "BUILDINGCLASS MISMATCH: BuildingFront: %f %f %f and %f %f %f"
                                                  ;
                                                  }
                                                  else {
                                                    pcVar16 = 
                                                  "BUILDINGCLASS MISMATCH: Position: %f %f %f and %f %f %f"
                                                  ;
                                                  }
                                                  FormatLogMessage(pcVar16);
                                                  return false;
                                                  }
                                                  pcVar16 = 
                                                  "BUILDINGCLASS MISMATCH: UpgradeName: \'%s\' and \'%s\'"
                                                  ;
                                                  }
                                                  else {
                                                    pcVar16 = 
                                                  "BUILDINGCLASS MISMATCH: BuildSupport: %d and %d";
                                                  }
                                                  }
                                                  else {
                                                    pcVar16 = 
                                                  "BUILDINGCLASS MISMATCH: MaxAmmo: %d and %d";
                                                  }
                                                }
                                                else {
                                                  pcVar16 = 
                                                  "BUILDINGCLASS MISMATCH: MaxHealth: %d and %d";
                                                }
                                              }
                                              else {
                                                pcVar16 = "BUILDINGCLASS MISMATCH: PTeam: %d and %d"
                                                ;
                                              }
                                            }
                                            else {
                                              pcVar16 = 
                                              "BUILDINGCLASS MISMATCH: CurTeamNum: %d and %d";
                                            }
                                          }
                                          else {
                                            pcVar16 = 
                                            "BUILDINGCLASS MISMATCH: PowerupAcceptMask: %d and %d";
                                          }
                                        }
                                        else {
                                          pcVar16 = 
                                          "BUILDINGCLASS MISMATCH: PowerProvide: %d and %d";
                                        }
                                      }
                                      else {
                                        pcVar16 = "BUILDINGCLASS MISMATCH: PowerMatch: %d and %d";
                                      }
                                    }
                                    else {
                                      pcVar16 = "BUILDINGCLASS MISMATCH: PowerMask: %d and %d";
                                    }
                                  }
                                  else {
                                    pcVar16 = "BUILDINGCLASS MISMATCH: PowerState: %d and %d";
                                  }
                                }
                                else {
                                  pcVar16 = "BUILDINGCLASS MISMATCH: TapNumber: %d and %d";
                                }
                              }
                              else {
                                pcVar16 = "BUILDINGCLASS MISMATCH: AnimDir: %d and %d";
                              }
                            }
                            else {
                              pcVar16 = "BUILDINGCLASS MISMATCH: PowerType: %d and %d";
                            }
                          }
                          else {
                            pcVar16 = "BUILDINGCLASS MISMATCH: ODFNameHash: %d and %d";
                          }
                        }
                        else {
                          pcVar16 = "BUILDINGCLASS MISMATCH: ObjClassHash: %d and %d";
                        }
                      }
                      else {
                        pcVar16 = "BUILDINGCLASS MISMATCH: OwnsTerrain: %d and %d";
                      }
                    }
                    else {
                      pcVar16 = "BUILDINGCLASS MISMATCH: PoweredByTaps: %d and %d";
                    }
                  }
                  else {
                    pcVar16 = "BUILDINGCLASS MISMATCH: CanDemolish: %d and %d";
                  }
                }
                else {
                  pcVar16 = "BUILDINGCLASS MISMATCH: GunTowerOff: %d and %d";
                }
              }
              else {
                pcVar16 = "BUILDINGCLASS MISMATCH: IsRecyclePoint: %d and %d";
              }
            }
            else {
              pcVar16 = "BUILDINGCLASS MISMATCH: IsAPCRefill: %d and %d";
            }
          }
          else {
            pcVar16 = "BUILDINGCLASS MISMATCH: CanBeIdleVictim: %d and %d";
          }
        }
        else {
          pcVar16 = "BUILDINGCLASS MISMATCH: CanCollide: %d and %d";
        }
      }
      else {
        pcVar16 = "BUILDINGCLASS MISMATCH: PlayAnim: %d and %d";
      }
    }
    else {
      pcVar16 = "BUILDINGCLASS MISMATCH: IsAnimated: %d and %d";
    }
  }
  else {
    pcVar16 = "BUILDINGCLASS MISMATCH: IsPowered: %d and %d";
  }
LAB_4fc1d3e2:
  FormatLogMessage(pcVar16);
  return false;
}


// ---------------------------------------------------------------------
// BuildingHelper::GetNumBuildingObjects  @ 4fc09793  lines 358-358

int __thiscall BuildingHelper::GetNumBuildingObjects(BuildingHelper *this)

{
  return (*(int *)&(this->BuildingList).field_0x4 - *(int *)&this->BuildingList) / 0x458;
}


