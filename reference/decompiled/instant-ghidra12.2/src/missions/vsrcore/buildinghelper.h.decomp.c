// Reconstructed by Ghidra from Instant.dll + Instant.pdb
// Original source file: /e:/github/vsr_dll_source/missions/vsrcore/buildinghelper.h
// Functions are ordered by original source line. This is decompiler
// output, not the author's source: names/types come from the PDB,
// local variable names and control flow are reconstructed.


// ---------------------------------------------------------------------
// operator==  @ 4fc1c7d3  lines 69-341


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool __cdecl operator==(BuildingClass *param_1,BuildingClass *param_2)

{
  int *in_ECX;
  float *pfVar1;
  int *piVar2;
  int *in_EDX;
  float *pfVar3;
  int iVar4;
  int iVar5;
  char *unaff_ESI;
  int unaff_EDI;
  char *pcVar6;
  undefined1 auStack_a4 [3];
  char local_a1;
  int *local_a0;
  int local_9c;
  int *local_98;
  int local_94;
  int local_90;
  undefined1 local_8c [64];
  undefined1 local_4c [68];
  uint local_8;
  
  local_8 = __security_cookie ^ (uint)auStack_a4;
  local_a0 = in_ECX;
  if (*in_ECX != *in_EDX) {
    memset(local_4c,0,0x40);
    memset(local_8c,0,0x40);
    GetODFName(unaff_EDI,unaff_ESI);
    GetODFName(unaff_EDI,unaff_ESI);
    pcVar6 = "BUILDINGCLASS MISMATCH: BuildingObject: %08x \'%s\' and %08x \'%s\'";
    goto LAB_4fc1c844;
  }
  local_98 = in_ECX + 1;
  pfVar3 = (float *)(in_ECX + 0x17);
  pfVar1 = (float *)(in_EDX + 0x15);
  local_94 = (int)in_EDX - (int)in_ECX;
  iVar4 = 0;
  local_9c = (int)in_ECX - (int)in_EDX;
  do {
    local_90 = *local_98;
    iVar5 = 0;
    if (local_90 != *(int *)(local_94 + (int)local_98)) {
      memset(local_8c,0,0x40);
      memset(local_4c,0,0x40);
      GetODFName(unaff_EDI,unaff_ESI);
      GetODFName(unaff_EDI,unaff_ESI);
      FormatLogMessage("BUILDINGCLASS MISMATCH: BuildingTap%d: %08x \'%s\' and %08x \'%s\'");
      return false;
    }
    local_a1 = *(char *)((int)in_ECX + iVar4 + 0x24);
    if (local_a1 != *(char *)((int)in_EDX + iVar4 + 0x24)) {
      pcVar6 = "BUILDINGCLASS MISMATCH: TapAnimated%d: %d and %d";
      goto LAB_4fc1cf93;
    }
    local_a1 = *(char *)((int)in_ECX + iVar4 + 0x2c);
    if (local_a1 != *(char *)((int)in_EDX + iVar4 + 0x2c)) {
      pcVar6 = "BUILDINGCLASS MISMATCH: PlayTapAnim%d: %d and %d";
      goto LAB_4fc1cf93;
    }
    if (((((((*(float *)(local_9c + (int)pfVar1) != *pfVar1) || (pfVar3[-1] != pfVar1[1])) ||
           (*pfVar3 != pfVar1[2])) || ((pfVar3[-10] != pfVar1[-8] || (pfVar3[-9] != pfVar1[-7]))))
         || ((pfVar3[-8] != pfVar1[-6] || ((pfVar3[-6] != pfVar1[-4] || (pfVar3[-5] != pfVar1[-3])))
             ))) || (pfVar3[-4] != pfVar1[-2])) ||
       (((pfVar3[2] != pfVar1[4] || (pfVar3[3] != pfVar1[5])) || (pfVar3[4] != pfVar1[6])))) {
      FormatLogMessage(
                      "BUILDINGCLASS MISMATCH: TapOffsetMatrix%d Front: %f %f %f and %f %f %f, TapOffsetMatrix%d Right: %f %f %f and %f %f %f, TapOffsetMatrix%d Up: %f %f %f and %f %f %f, TapOffsetMatrix%d Posit: %f %f %f and %f %f %f"
                      );
      return false;
    }
    local_98 = local_98 + 1;
    iVar4 = iVar4 + 1;
    pfVar3 = pfVar3 + 0x10;
    pfVar1 = pfVar1 + 0x10;
  } while (iVar4 < 8);
  if ((char)in_ECX[0x8d] == (char)in_EDX[0x8d]) {
    if (*(char *)((int)in_ECX + 0x235) == *(char *)((int)in_EDX + 0x235)) {
      if (*(char *)((int)in_ECX + 0x236) == *(char *)((int)in_EDX + 0x236)) {
        if (*(char *)((int)in_ECX + 0x237) == *(char *)((int)in_EDX + 0x237)) {
          if ((char)in_ECX[0x8e] == (char)in_EDX[0x8e]) {
            if (*(char *)((int)in_ECX + 0x239) == *(char *)((int)in_EDX + 0x239)) {
              if (*(char *)((int)in_ECX + 0x23a) == *(char *)((int)in_EDX + 0x23a)) {
                if (*(char *)((int)in_ECX + 0x23b) == *(char *)((int)in_EDX + 0x23b)) {
                  if ((char)in_ECX[0x8f] == (char)in_EDX[0x8f]) {
                    if (*(char *)((int)in_ECX + 0x23d) == *(char *)((int)in_EDX + 0x23d)) {
                      if (*(char *)((int)in_ECX + 0x23f) == *(char *)((int)in_EDX + 0x23f)) {
                        if (in_ECX[0x90] == in_EDX[0x90]) {
                          if (in_ECX[0x91] == in_EDX[0x91]) {
                            if (in_ECX[0x92] == in_EDX[0x92]) {
                              if (in_ECX == in_EDX) {
                                if (in_ECX[0x9c] == in_EDX[0x9c]) {
                                  if (in_ECX[0x9d] == in_EDX[0x9d]) {
                                    if (in_ECX[0x9e] == in_EDX[0x9e]) {
                                      if (in_ECX[0x9f] == in_EDX[0x9f]) {
                                        if (in_ECX[0xa0] == in_EDX[0xa0]) {
                                          if (in_ECX[0xa1] == in_EDX[0xa1]) {
                                            if (in_ECX[0xa2] == in_EDX[0xa2]) {
                                              if (in_ECX[0xa3] == in_EDX[0xa3]) {
                                                if (in_ECX[0xa4] == in_EDX[0xa4]) {
                                                  if (in_ECX[0xa5] == in_EDX[0xa5]) {
                                                    piVar2 = in_ECX + 0xa7;
                                                    iVar4 = iVar5;
                                                    do {
                                                      local_a0 = *(int **)(local_94 + (int)piVar2);
                                                      if (*piVar2 !=
                                                          *(int *)(local_94 + (int)piVar2)) {
                                                        pcVar6 = 
                                                  "BUILDINGCLASS MISMATCH: TerrainSizeRatio%d: %d and %d"
                                                  ;
                                                  goto LAB_4fc1cf93;
                                                  }
                                                  iVar4 = iVar4 + 1;
                                                  piVar2 = piVar2 + 1;
                                                  } while (iVar4 < 2);
                                                  if (in_ECX[0xa9] == in_EDX[0xa9]) {
                                                    if ((float)in_ECX[0xaa] != (float)in_EDX[0xaa])
                                                    {
                                                      pcVar6 = 
                                                  "BUILDINGCLASS MISMATCH: CollisionRadius: %f and %f"
                                                  ;
LAB_4fc1c844:
                                                  FormatLogMessage(pcVar6);
                                                  return false;
                                                  }
                                                  local_a0 = in_ECX + 0xab;
                                                  iVar4 = _stricmp((char *)local_a0,
                                                                   (char *)(in_EDX + 0xab));
                                                  if (iVar4 == 0) {
                                                    piVar2 = in_ECX + 0xbb;
                                                    do {
                                                      local_a0 = (int *)(local_94 + (int)piVar2);
                                                      iVar4 = _stricmp((char *)piVar2,
                                                                       (char *)local_a0);
                                                      if (iVar4 != 0) {
                                                        pcVar6 = 
                                                  "BUILDINGCLASS MISMATCH: WeaponNames%d: \'%s\' and \'%s\'"
                                                  ;
LAB_4fc1cf93:
                                                  FormatLogMessage(pcVar6);
                                                  return false;
                                                  }
                                                  iVar5 = iVar5 + 1;
                                                  piVar2 = piVar2 + 0x10;
                                                  } while (iVar5 < 5);
                                                  if ((((float)in_ECX[0x10b] == (float)in_EDX[0x10b]
                                                       ) && ((float)in_ECX[0x10c] ==
                                                             (float)in_EDX[0x10c])) &&
                                                     ((float)in_ECX[0x10d] == (float)in_EDX[0x10d]))
                                                  {
                                                    if ((((float)in_ECX[0x10e] ==
                                                          (float)in_EDX[0x10e]) &&
                                                        ((float)in_ECX[0x10f] ==
                                                         (float)in_EDX[0x10f])) &&
                                                       ((float)in_ECX[0x110] == (float)in_EDX[0x110]
                                                       )) {
                                                      if ((float)in_ECX[0x111] ==
                                                          (float)in_EDX[0x111]) {
                                                        if ((float)in_ECX[0x112] ==
                                                            (float)in_EDX[0x112]) {
                                                          if ((float)in_ECX[0x113] ==
                                                              (float)in_EDX[0x113]) {
                                                            if ((float)in_ECX[0x114] ==
                                                                (float)in_EDX[0x114]) {
                                                              if ((char)in_ECX[0x115] ==
                                                                  (char)in_EDX[0x115]) {
                                                                return true;
                                                              }
                                                              pcVar6 = 
                                                  "OBJECTLIST MISMATCH: ServiceCraft: %d and %d";
                                                  goto LAB_4fc1c9dd;
                                                  }
                                                  pcVar6 = 
                                                  "OBJECTLIST MISMATCH: ServiceRate: %f and %f";
                                                  }
                                                  else {
                                                    pcVar6 = 
                                                  "OBJECTLIST MISMATCH: LocalAmmoRate: %f and %f";
                                                  }
                                                  }
                                                  else {
                                                    pcVar6 = 
                                                  "OBJECTLIST MISMATCH: AmmoRate: %f and %f";
                                                  }
                                                  }
                                                  else {
                                                    pcVar6 = 
                                                  "OBJECTLIST MISMATCH: HealthRate: %f and %f";
                                                  }
                                                  goto LAB_4fc1c844;
                                                  }
                                                  pcVar6 = 
                                                  "BUILDINGCLASS MISMATCH: BuildingFront: %f %f %f and %f %f %f"
                                                  ;
                                                  }
                                                  else {
                                                    pcVar6 = 
                                                  "BUILDINGCLASS MISMATCH: Position: %f %f %f and %f %f %f"
                                                  ;
                                                  }
                                                  FormatLogMessage(pcVar6);
                                                  return false;
                                                  }
                                                  pcVar6 = 
                                                  "BUILDINGCLASS MISMATCH: UpgradeName: \'%s\' and \'%s\'"
                                                  ;
                                                  }
                                                  else {
                                                    pcVar6 = 
                                                  "BUILDINGCLASS MISMATCH: BuildSupport: %d and %d";
                                                  }
                                                  }
                                                  else {
                                                    pcVar6 = 
                                                  "BUILDINGCLASS MISMATCH: MaxAmmo: %d and %d";
                                                  }
                                                }
                                                else {
                                                  pcVar6 = 
                                                  "BUILDINGCLASS MISMATCH: MaxHealth: %d and %d";
                                                }
                                              }
                                              else {
                                                pcVar6 = "BUILDINGCLASS MISMATCH: PTeam: %d and %d";
                                              }
                                            }
                                            else {
                                              pcVar6 = 
                                              "BUILDINGCLASS MISMATCH: CurTeamNum: %d and %d";
                                            }
                                          }
                                          else {
                                            pcVar6 = 
                                            "BUILDINGCLASS MISMATCH: PowerupAcceptMask: %d and %d";
                                          }
                                        }
                                        else {
                                          pcVar6 = "BUILDINGCLASS MISMATCH: PowerProvide: %d and %d"
                                          ;
                                        }
                                      }
                                      else {
                                        pcVar6 = "BUILDINGCLASS MISMATCH: PowerMatch: %d and %d";
                                      }
                                    }
                                    else {
                                      pcVar6 = "BUILDINGCLASS MISMATCH: PowerMask: %d and %d";
                                    }
                                  }
                                  else {
                                    pcVar6 = "BUILDINGCLASS MISMATCH: PowerState: %d and %d";
                                  }
                                }
                                else {
                                  pcVar6 = "BUILDINGCLASS MISMATCH: TapNumber: %d and %d";
                                }
                              }
                              else {
                                pcVar6 = "BUILDINGCLASS MISMATCH: AnimDir: %d and %d";
                              }
                            }
                            else {
                              pcVar6 = "BUILDINGCLASS MISMATCH: PowerType: %d and %d";
                            }
                          }
                          else {
                            pcVar6 = "BUILDINGCLASS MISMATCH: ODFNameHash: %d and %d";
                          }
                        }
                        else {
                          pcVar6 = "BUILDINGCLASS MISMATCH: ObjClassHash: %d and %d";
                        }
                      }
                      else {
                        pcVar6 = "BUILDINGCLASS MISMATCH: OwnsTerrain: %d and %d";
                      }
                    }
                    else {
                      pcVar6 = "BUILDINGCLASS MISMATCH: PoweredByTaps: %d and %d";
                    }
                  }
                  else {
                    pcVar6 = "BUILDINGCLASS MISMATCH: CanDemolish: %d and %d";
                  }
                }
                else {
                  pcVar6 = "BUILDINGCLASS MISMATCH: GunTowerOff: %d and %d";
                }
              }
              else {
                pcVar6 = "BUILDINGCLASS MISMATCH: IsRecyclePoint: %d and %d";
              }
            }
            else {
              pcVar6 = "BUILDINGCLASS MISMATCH: IsAPCRefill: %d and %d";
            }
          }
          else {
            pcVar6 = "BUILDINGCLASS MISMATCH: CanBeIdleVictim: %d and %d";
          }
        }
        else {
          pcVar6 = "BUILDINGCLASS MISMATCH: CanCollide: %d and %d";
        }
      }
      else {
        pcVar6 = "BUILDINGCLASS MISMATCH: PlayAnim: %d and %d";
      }
    }
    else {
      pcVar6 = "BUILDINGCLASS MISMATCH: IsAnimated: %d and %d";
    }
  }
  else {
    pcVar6 = "BUILDINGCLASS MISMATCH: IsPowered: %d and %d";
  }
LAB_4fc1c9dd:
  FormatLogMessage(pcVar6);
  return false;
}


// ---------------------------------------------------------------------
// BZ1Helper::ShouldRemoveAlignTerrainReplace  @ 4fc0a64b  lines 351-351


bool __cdecl BZ1Helper::ShouldRemoveAlignTerrainReplace(AlignTerrainReplaceClass *param_1)

{
  bool bVar1;
  
  bVar1 = IsAround(param_1->AlignHandle);
  return (bool)('\x01' - bVar1);
}


// ---------------------------------------------------------------------
// BuildingHelper::GetNumBuildingObjects  @ 4fc08d77  lines 358-358


int __thiscall BuildingHelper::GetNumBuildingObjects(BuildingHelper *this)

{
  return (*(int *)&(this->BuildingList).field_0x4 - *(int *)&this->BuildingList) / 0x458;
}

