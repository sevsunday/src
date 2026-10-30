// Reconstructed by Ghidra from Strategy02.dll + Strategy02.pdb
// Original source file: /e:/github/vsr_dll_source/missions/vsrcore/portalhelper.h
// Functions are ordered by original source line. This is decompiler
// output, not the author's source: names/types come from the PDB,
// local variable names and control flow are reconstructed.

// ---------------------------------------------------------------------
// operator==  @ 4fc26cc6  lines 95-421

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool __cdecl operator==(PortalClass *a,PortalClass *b)

{
  float fVar1;
  float fVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  double dVar10;
  double dVar11;
  double dVar12;
  double dVar13;
  double dVar14;
  double dVar15;
  double dVar16;
  double dVar17;
  double dVar18;
  double dVar19;
  double dVar20;
  double dVar21;
  double dVar22;
  double dVar23;
  double dVar24;
  double dVar25;
  int *piVar26;
  int iVar27;
  int iVar28;
  undefined4 unaff_EDI;
  char *pcVar29;
  undefined1 auStack_9c [4];
  char *local_98;
  char *local_94;
  char *local_90;
  char local_8c [64];
  char local_4c [68];
  uint local_8;
  
  local_8 = __security_cookie ^ (uint)auStack_9c;
  iVar27 = a->TeleporterObject;
  if (iVar27 == b->TeleporterObject) {
    iVar27 = a->TeleporterDestination;
    if (iVar27 == b->TeleporterDestination) {
      if (a->TeleporterEffectSlot == b->TeleporterEffectSlot) {
        iVar27 = a->PortalMineHost;
        if (iVar27 != b->PortalMineHost) {
          memset(local_8c,0,0x40);
          memset(local_4c,0,0x40);
          GetODFName(iVar27,local_8c);
          GetODFName(b->PortalMineHost,local_4c);
          pcVar29 = "PORTALCLASS MISMATCH: PortalMineHost: %08x \'%s\' and %08x \'%s\'";
          goto LAB_4fc26d33;
        }
        if (a->CanEnter == b->CanEnter) {
          if (a->CanExit == b->CanExit) {
            if (a->MatchTypeUsesChannels == b->MatchTypeUsesChannels) {
              if (a->ExitForwardOnly == b->ExitForwardOnly) {
                if (a->ShowChannel == b->ShowChannel) {
                  if (a->NameFlash == b->NameFlash) {
                    if (a->UseCenter == b->UseCenter) {
                      if (a->KickAI == b->KickAI) {
                        if (a->ContinuousFx == b->ContinuousFx) {
                          if (a->EnterGotoIsExit == b->EnterGotoIsExit) {
                            if (a->ScriptOverrideDest == b->ScriptOverrideDest) {
                              if (a->FxOnVehicle == b->FxOnVehicle) {
                                if (a->MatchType == b->MatchType) {
                                  if (a->MatchCycleIndex == b->MatchCycleIndex) {
                                    if (a->Channel == b->Channel) {
                                      if (a->DestTeamFilter == b->DestTeamFilter) {
                                        if (a->TargetTeamFilter == b->TargetTeamFilter) {
                                          if (a->TeleportFilter == b->TeleportFilter) {
                                            if (a->EffectType == b->EffectType) {
                                              if (a->EffectNumber == b->EffectNumber) {
                                                if (a->EffectState == b->EffectState) {
                                                  iVar28 = 0;
                                                  piVar26 = a->EffectTimer;
                                                  iVar27 = 0;
                                                  local_98 = (char *)((int)b - (int)a);
                                                  do {
                                                    local_94 = *(char **)(local_98 + (int)piVar26);
                                                    if (*piVar26 !=
                                                        *(int *)(local_98 + (int)piVar26)) {
                                                      pcVar29 = 
                                                  "PORTALCLASS MISMATCH: EffectTimer[%d]: %d and %d"
                                                  ;
                                                  goto LAB_4fc276e5;
                                                  }
                                                  iVar27 = iVar27 + 1;
                                                  piVar26 = piVar26 + 1;
                                                  } while (iVar27 < 0x10);
                                                  if (a->EnterRange == b->EnterRange) {
                                                    if (a->ExitSpeed == b->ExitSpeed) {
                                                      if (a->DestMinRange == b->DestMinRange) {
                                                        if (a->DestMaxRange == b->DestMaxRange) {
                                                          if (a->CollisionRadius ==
                                                              b->CollisionRadius) {
                                                            if ((((a->Position).x == (b->Position).x
                                                                 ) && ((a->Position).y ==
                                                                       (b->Position).y)) &&
                                                               ((a->Position).z == (b->Position).z))
                                                            {
                                                              if ((((a->GotoPoint).x ==
                                                                    (b->GotoPoint).x) &&
                                                                  ((a->GotoPoint).y ==
                                                                   (b->GotoPoint).y)) &&
                                                                 ((a->GotoPoint).z ==
                                                                  (b->GotoPoint).z)) {
                                                                fVar1 = (b->ExitPoint).front.x;
                                                                fVar2 = (a->ExitPoint).front.x;
                                                                if (((((fVar2 != fVar1) ||
                                                                      ((a->ExitPoint).front.y !=
                                                                       (b->ExitPoint).front.y)) ||
                                                                     ((((a->ExitPoint).front.z !=
                                                                        (b->ExitPoint).front.z ||
                                                                       (((((a->ExitPoint).right.x !=
                                                                           (b->ExitPoint).right.x ||
                                                                          ((a->ExitPoint).right.y !=
                                                                           (b->ExitPoint).right.y))
                                                                         || ((a->ExitPoint).right.z
                                                                             != (b->ExitPoint).right
                                                                                .z)) ||
                                                                        (((a->ExitPoint).up.x !=
                                                                          (b->ExitPoint).up.x ||
                                                                         ((a->ExitPoint).up.y !=
                                                                          (b->ExitPoint).up.y))))))
                                                                      || ((a->ExitPoint).up.z !=
                                                                          (b->ExitPoint).up.z)))) ||
                                                                    (((a->ExitPoint).posit.x !=
                                                                      (b->ExitPoint).posit.x ||
                                                                     ((a->ExitPoint).posit.y !=
                                                                      (b->ExitPoint).posit.y)))) ||
                                                                   ((a->ExitPoint).posit.z !=
                                                                    (b->ExitPoint).posit.z)) {
                                                                  dVar3 = (double)(b->ExitPoint).
                                                                                  posit.z;
                                                                  dVar4 = (double)(b->ExitPoint).
                                                                                  posit.y;
                                                                  dVar5 = (double)(b->ExitPoint).
                                                                                  posit.x;
                                                                  dVar6 = (double)(a->ExitPoint).
                                                                                  posit.z;
                                                                  dVar7 = (double)(a->ExitPoint).
                                                                                  posit.y;
                                                                  dVar8 = (double)(a->ExitPoint).
                                                                                  posit.x;
                                                                  dVar9 = (double)(b->ExitPoint).up.
                                                                                  z;
                                                                  dVar10 = (double)(b->ExitPoint).up
                                                                                   .y;
                                                                  dVar11 = (double)(b->ExitPoint).up
                                                                                   .x;
                                                                  dVar12 = (double)(a->ExitPoint).up
                                                                                   .z;
                                                                  dVar13 = (double)(a->ExitPoint).up
                                                                                   .y;
                                                                  dVar14 = (double)(a->ExitPoint).up
                                                                                   .x;
                                                                  dVar15 = (double)(b->ExitPoint).
                                                                                   right.z;
                                                                  dVar16 = (double)(b->ExitPoint).
                                                                                   right.y;
                                                                  dVar17 = (double)(b->ExitPoint).
                                                                                   right.x;
                                                                  dVar18 = (double)(a->ExitPoint).
                                                                                   right.z;
                                                                  dVar19 = (double)(a->ExitPoint).
                                                                                   right.y;
                                                                  dVar20 = (double)(a->ExitPoint).
                                                                                   right.x;
                                                                  dVar21 = (double)(b->ExitPoint).
                                                                                   front.z;
                                                                  dVar22 = (double)(b->ExitPoint).
                                                                                   front.y;
                                                                  dVar23 = (double)fVar1;
                                                                  dVar24 = (double)(a->ExitPoint).
                                                                                   front.z;
                                                                  dVar25 = (double)(a->ExitPoint).
                                                                                   front.y;
                                                                  FormatLogMessage(
                                                  "PORTALCLASS MISMATCH: ExitPoint Front: %f %f %f and %f %f %f, ExitPoint Right: %f %f %f and %f %f %f, ExitPoint Up: %f %f %f and %f %f %f, ExitPoint Posit: %f %f %f and %f %f %f"
                                                  ,(double)CONCAT44(SUB84(dVar25,0),
                                                                    (int)((ulonglong)(double)fVar2
                                                                         >> 0x20)),
                                                  (double)CONCAT44(SUB84(dVar24,0),
                                                                   (int)((ulonglong)dVar25 >> 0x20))
                                                  ,(double)CONCAT44(SUB84(dVar23,0),
                                                                    (int)((ulonglong)dVar24 >> 0x20)
                                                                   ),
                                                  (double)CONCAT44(SUB84(dVar22,0),
                                                                   (int)((ulonglong)dVar23 >> 0x20))
                                                  ,(double)CONCAT44(SUB84(dVar21,0),
                                                                    (int)((ulonglong)dVar22 >> 0x20)
                                                                   ),
                                                  (double)CONCAT44(SUB84(dVar20,0),
                                                                   (int)((ulonglong)dVar21 >> 0x20))
                                                  ,(double)CONCAT44(SUB84(dVar19,0),
                                                                    (int)((ulonglong)dVar20 >> 0x20)
                                                                   ),
                                                  (double)CONCAT44(SUB84(dVar18,0),
                                                                   (int)((ulonglong)dVar19 >> 0x20))
                                                  ,(double)CONCAT44(SUB84(dVar17,0),
                                                                    (int)((ulonglong)dVar18 >> 0x20)
                                                                   ),
                                                  (double)CONCAT44(SUB84(dVar16,0),
                                                                   (int)((ulonglong)dVar17 >> 0x20))
                                                  ,(double)CONCAT44(SUB84(dVar15,0),
                                                                    (int)((ulonglong)dVar16 >> 0x20)
                                                                   ),
                                                  (double)CONCAT44(SUB84(dVar14,0),
                                                                   (int)((ulonglong)dVar15 >> 0x20))
                                                  ,(double)CONCAT44(SUB84(dVar13,0),
                                                                    (int)((ulonglong)dVar14 >> 0x20)
                                                                   ),
                                                  (double)CONCAT44(SUB84(dVar12,0),
                                                                   (int)((ulonglong)dVar13 >> 0x20))
                                                  ,(double)CONCAT44(SUB84(dVar11,0),
                                                                    (int)((ulonglong)dVar12 >> 0x20)
                                                                   ),
                                                  (double)CONCAT44(SUB84(dVar10,0),
                                                                   (int)((ulonglong)dVar11 >> 0x20))
                                                  ,(double)CONCAT44(SUB84(dVar9,0),
                                                                    (int)((ulonglong)dVar10 >> 0x20)
                                                                   ),
                                                  (double)CONCAT44(SUB84(dVar8,0),
                                                                   (int)((ulonglong)dVar9 >> 0x20)),
                                                  (double)CONCAT44(SUB84(dVar7,0),
                                                                   (int)((ulonglong)dVar8 >> 0x20)),
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
                                                  if (a->DestinationIndex == b->DestinationIndex) {
                                                    if (a->InEffect == b->InEffect) {
                                                      if (a->OutEffect == b->OutEffect) {
                                                        if (a->OnEffect == b->OnEffect) {
                                                          if (a->VehInEffect == b->VehInEffect) {
                                                            if (a->VehOutEffect == b->VehOutEffect)
                                                            {
                                                              if (a->ContinuousFxRange !=
                                                                  b->ContinuousFxRange) {
                                                                pcVar29 = 
                                                  "PORTALCLASS MISMATCH: ContinuousFxRange: %f and %f"
                                                  ;
                                                  goto LAB_4fc26d33;
                                                  }
                                                  local_90 = b->TeleporterName;
                                                  local_94 = a->TeleporterName;
                                                  iVar27 = _stricmp(local_94,local_90);
                                                  if (iVar27 == 0) {
                                                    local_94 = b->EffectBaseODF;
                                                    local_90 = a->EffectBaseODF;
                                                    iVar27 = _stricmp(local_90,local_94);
                                                    if (iVar27 == 0) {
                                                      piVar26 = a->EffectHardLifeTime;
                                                      do {
                                                        if ((undefined1 *)*piVar26 !=
                                                            *(char **)((int)piVar26 + (int)local_98)
                                                           ) {
                                                          pcVar29 = 
                                                  "PORTALCLASS MISMATCH: EffectHardLifeTime[%d]: %d and %d"
                                                  ;
                                                  local_98 = *(char **)((int)piVar26 + (int)local_98
                                                                       );
                                                  goto LAB_4fc276e5;
                                                  }
                                                  iVar28 = iVar28 + 1;
                                                  piVar26 = piVar26 + 1;
                                                  } while (iVar28 < 0x10);
                                                  local_98 = a->TooFarSound;
                                                  iVar27 = _stricmp(local_98,b->TooFarSound);
                                                  if (iVar27 == 0) {
                                                    local_98 = a->TooCloseSound;
                                                    iVar27 = _stricmp(local_98,b->TooCloseSound);
                                                    if (iVar27 == 0) {
                                                      local_98 = a->ActivateSound;
                                                      iVar27 = _stricmp(local_98,b->ActivateSound);
                                                      if (iVar27 == 0) {
                                                        local_98 = a->DeactivateSound;
                                                        iVar27 = _stricmp(local_98,b->
                                                  DeactivateSound);
                                                  if (iVar27 == 0) {
                                                    if (a->SoundHandle == b->SoundHandle) {
                                                      return true;
                                                    }
                                                    pcVar29 = 
                                                  "PORTALCLASS MISMATCH: SoundHandle: %d and %d";
                                                  }
                                                  else {
                                                    pcVar29 = 
                                                  "PORTALCLASS MISMATCH: DeactivateSound: \'%s\' and \'%s\'"
                                                  ;
                                                  }
                                                  }
                                                  else {
                                                    pcVar29 = 
                                                  "PORTALCLASS MISMATCH: ActivateSound: \'%s\' and \'%s\'"
                                                  ;
                                                  }
                                                  }
                                                  else {
                                                    pcVar29 = 
                                                  "PORTALCLASS MISMATCH: TooCloseSound: \'%s\' and \'%s\'"
                                                  ;
                                                  }
                                                  }
                                                  else {
                                                    pcVar29 = 
                                                  "PORTALCLASS MISMATCH: TooFarSound: \'%s\' and \'%s\'"
                                                  ;
                                                  }
                                                  }
                                                  else {
                                                    pcVar29 = 
                                                  "PORTALCLASS MISMATCH: EffectBaseODF: \'%s\' and \'%s\'"
                                                  ;
                                                  }
                                                  }
                                                  else {
                                                    pcVar29 = 
                                                  "PORTALCLASS MISMATCH: TeleporterName: \'%s\' and \'%s\'"
                                                  ;
                                                  }
                                                  }
                                                  else {
                                                    pcVar29 = 
                                                  "PORTALCLASS MISMATCH: VehOutEffect: %d and %d";
                                                  }
                                                  }
                                                  else {
                                                    pcVar29 = 
                                                  "PORTALCLASS MISMATCH: VehInEffect: %d and %d";
                                                  }
                                                  }
                                                  else {
                                                    pcVar29 = 
                                                  "PORTALCLASS MISMATCH: OnEffect: %d and %d";
                                                  }
                                                  }
                                                  else {
                                                    pcVar29 = 
                                                  "PORTALCLASS MISMATCH: OutEffect: %d and %d";
                                                  }
                                                  }
                                                  else {
                                                    pcVar29 = 
                                                  "PORTALCLASS MISMATCH: InEffect: %d and %d";
                                                  }
                                                  }
                                                  else {
                                                    pcVar29 = 
                                                  "PORTALCLASS MISMATCH: DestinationIndex: %d and %d"
                                                  ;
                                                  }
                                                  goto LAB_4fc276e5;
                                                  }
                                                  pcVar29 = 
                                                  "PORTALCLASS MISMATCH: GotoPoint: %f %f %f and %f %f %f"
                                                  ;
                                                  }
                                                  else {
                                                    pcVar29 = 
                                                  "PORTALCLASS MISMATCH: Position: %f %f %f and %f %f %f"
                                                  ;
                                                  }
                                                  FormatLogMessage(pcVar29);
                                                  return false;
                                                  }
                                                  pcVar29 = 
                                                  "PORTALCLASS MISMATCH: CollisionRadius: %f and %f"
                                                  ;
                                                  }
                                                  else {
                                                    pcVar29 = 
                                                  "PORTALCLASS MISMATCH: DestMaxRange: %f and %f";
                                                  }
                                                  }
                                                  else {
                                                    pcVar29 = 
                                                  "PORTALCLASS MISMATCH: DestMinRange: %f and %f";
                                                  }
                                                  }
                                                  else {
                                                    pcVar29 = 
                                                  "PORTALCLASS MISMATCH: ExitSpeed: %f and %f";
                                                  }
                                                  }
                                                  else {
                                                    pcVar29 = 
                                                  "PORTALCLASS MISMATCH: EnterRange: %f and %f";
                                                  }
                                                  goto LAB_4fc26d33;
                                                }
                                                pcVar29 = 
                                                "PORTALCLASS MISMATCH: EffectState: %d and %d";
                                              }
                                              else {
                                                pcVar29 = 
                                                "PORTALCLASS MISMATCH: EffectNumber: %d and %d";
                                              }
                                            }
                                            else {
                                              pcVar29 = 
                                              "PORTALCLASS MISMATCH: EffectType: %d and %d";
                                            }
                                          }
                                          else {
                                            pcVar29 = 
                                            "PORTALCLASS MISMATCH: TeleportFilter: %d and %d";
                                          }
                                        }
                                        else {
                                          pcVar29 = 
                                          "PORTALCLASS MISMATCH: TargetTeamFilter: %d and %d";
                                        }
                                      }
                                      else {
                                        pcVar29 = "PORTALCLASS MISMATCH: DestTeamFilter: %d and %d";
                                      }
                                    }
                                    else {
                                      pcVar29 = "PORTALCLASS MISMATCH: Channel: %d and %d";
                                    }
                                  }
                                  else {
                                    pcVar29 = "PORTALCLASS MISMATCH: MatchCycleIndex: %d and %d";
                                  }
                                }
                                else {
                                  pcVar29 = "PORTALCLASS MISMATCH: MatchType: %d and %d";
                                }
                              }
                              else {
                                pcVar29 = "PORTALCLASS MISMATCH: FxOnVehicle: %d and %d";
                              }
                            }
                            else {
                              pcVar29 = "PORTALCLASS MISMATCH: ScriptOverrideDest: %d and %d";
                            }
                          }
                          else {
                            pcVar29 = "PORTALCLASS MISMATCH: EnterGotoIsExit: %d and %d";
                          }
                        }
                        else {
                          pcVar29 = "PORTALCLASS MISMATCH: ContinuousFx: %d and %d";
                        }
                      }
                      else {
                        pcVar29 = "PORTALCLASS MISMATCH: KickAI: %d and %d";
                      }
                    }
                    else {
                      pcVar29 = "PORTALCLASS MISMATCH: UseCenter: %d and %d";
                    }
                  }
                  else {
                    pcVar29 = "PORTALCLASS MISMATCH: NameFlash: %d and %d";
                  }
                }
                else {
                  pcVar29 = "PORTALCLASS MISMATCH: ShowChannel: %d and %d";
                }
              }
              else {
                pcVar29 = "PORTALCLASS MISMATCH: ExitForwardOnly: %d and %d";
              }
            }
            else {
              pcVar29 = "PORTALCLASS MISMATCH: MatchTypeUsesChannels: %d and %d";
            }
          }
          else {
            pcVar29 = "PORTALCLASS MISMATCH: CanExit: %d and %d";
          }
        }
        else {
          pcVar29 = "PORTALCLASS MISMATCH: CanEnter: %d and %d";
        }
      }
      else {
        pcVar29 = "PORTALCLASS MISMATCH: TeleporterEffectSlot: %d and %d";
      }
LAB_4fc276e5:
      FormatLogMessage(pcVar29);
      return false;
    }
    memset(local_8c,0,0x40);
    memset(local_4c,0,0x40);
    GetODFName(iVar27,local_8c);
    GetODFName(b->TeleporterDestination,local_4c);
    pcVar29 = "PORTALCLASS MISMATCH: TeleporterDestination: %08x \'%s\' and %08x \'%s\'";
  }
  else {
    memset(local_4c,0,0x40);
    memset(local_8c,0,0x40);
    GetODFName(iVar27,local_4c);
    GetODFName(b->TeleporterObject,local_8c);
    pcVar29 = "PORTALCLASS MISMATCH: TeleporterObject: %08x \'%s\' and %08x \'%s\'";
  }
LAB_4fc26d33:
  FormatLogMessage(pcVar29);
  return false;
}


// ---------------------------------------------------------------------
// operator==  @ 4fc27708  lines 436-477

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool __cdecl operator==(TeleportTargetClass *a,TeleportTargetClass *b)

{
  int iVar1;
  char *format;
  char ODFNameA__ODFNameB [64];
  char ODFNameB__ODFNameA [68];
  uint local_8;
  
  local_8 = __security_cookie ^ (uint)&stack0xfffffffc;
  iVar1 = a->TeleportTarget;
  if (iVar1 == b->TeleportTarget) {
    iVar1 = a->TeleportTargetDestination;
    if (iVar1 == b->TeleportTargetDestination) {
      if (a->DestinationIndex != b->DestinationIndex) {
        FormatLogMessage("TELEPORTTARGETCLASS MISMATCH: DestinationIndex: %d and %d",
                         a->DestinationIndex,b->DestinationIndex);
        return false;
      }
      if (a->DestEnterRange == b->DestEnterRange) {
        if (a->DistanceFromDestination == b->DistanceFromDestination) {
          return true;
        }
        format = "TELEPORTTARGETCLASS MISMATCH: DistanceFromDestination: %f and %f";
      }
      else {
        format = "TELEPORTTARGETCLASS MISMATCH: DestEnterRange: %f and %f";
      }
    }
    else {
      memset(ODFNameB__ODFNameA,0,0x40);
      memset(ODFNameA__ODFNameB,0,0x40);
      GetODFName(iVar1,ODFNameB__ODFNameA);
      GetODFName(b->TeleportTargetDestination,ODFNameA__ODFNameB);
      format = 
      "TELEPORTTARGETCLASS MISMATCH: TeleportTargetDestination: %08x \'%s\' and %08x \'%s\'";
    }
  }
  else {
    memset(ODFNameA__ODFNameB,0,0x40);
    memset(ODFNameB__ODFNameA,0,0x40);
    GetODFName(iVar1,ODFNameA__ODFNameB);
    GetODFName(b->TeleportTarget,ODFNameB__ODFNameA);
    format = "TELEPORTTARGETCLASS MISMATCH: TeleportTarget: %08x \'%s\' and %08x \'%s\'";
  }
  FormatLogMessage(format);
  return false;
}


// ---------------------------------------------------------------------
// PortalHelper::ShouldRemoveTeleportTarget  @ 4fc2785c  lines 489-489

bool __cdecl PortalHelper::ShouldRemoveTeleportTarget(TeleportTargetClass *entry)

{
  float fVar1;
  bool bVar2;
  
  fVar1 = entry->DestEnterRange + 5.0;
  if (((entry->DistanceFromDestination <= fVar1 * fVar1) &&
      (bVar2 = IsAround(entry->TeleportTarget), bVar2)) &&
     (bVar2 = IsAround(entry->TeleportTargetDestination), bVar2)) {
    return false;
  }
  return true;
}


