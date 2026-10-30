// Reconstructed by Ghidra from Instant.dll + Instant.pdb
// Original source file: /e:/github/vsr_dll_source/missions/vsrcore/portalhelper.h
// Functions are ordered by original source line. This is decompiler
// output, not the author's source: names/types come from the PDB,
// local variable names and control flow are reconstructed.


// ---------------------------------------------------------------------
// operator==  @ 4fc25fcd  lines 95-421


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool __cdecl operator==(PortalClass *param_1,PortalClass *param_2)

{
  int *piVar1;
  int *in_ECX;
  int *in_EDX;
  int iVar2;
  int iVar3;
  char *unaff_ESI;
  int unaff_EDI;
  char *pcVar4;
  undefined1 auStack_9c [4];
  int *local_98;
  int *local_94;
  int *local_90;
  undefined1 local_8c [64];
  undefined1 local_4c [68];
  uint local_8;
  
  local_8 = __security_cookie ^ (uint)auStack_9c;
  if (*in_ECX == *in_EDX) {
    if (in_ECX[1] == in_EDX[1]) {
      if (in_ECX[2] == in_EDX[2]) {
        if (in_ECX[3] != in_EDX[3]) {
          memset(local_8c,0,0x40);
          memset(local_4c,0,0x40);
          GetODFName(unaff_EDI,unaff_ESI);
          GetODFName(unaff_EDI,unaff_ESI);
          pcVar4 = "PORTALCLASS MISMATCH: PortalMineHost: %08x \'%s\' and %08x \'%s\'";
          goto LAB_4fc2603a;
        }
        if ((char)in_ECX[4] == (char)in_EDX[4]) {
          if (*(char *)((int)in_ECX + 0x11) == *(char *)((int)in_EDX + 0x11)) {
            if (*(char *)((int)in_ECX + 0x12) == *(char *)((int)in_EDX + 0x12)) {
              if (*(char *)((int)in_ECX + 0x13) == *(char *)((int)in_EDX + 0x13)) {
                if ((char)in_ECX[5] == (char)in_EDX[5]) {
                  if (*(char *)((int)in_ECX + 0x15) == *(char *)((int)in_EDX + 0x15)) {
                    if (*(char *)((int)in_ECX + 0x16) == *(char *)((int)in_EDX + 0x16)) {
                      if (*(char *)((int)in_ECX + 0x17) == *(char *)((int)in_EDX + 0x17)) {
                        if ((char)in_ECX[6] == (char)in_EDX[6]) {
                          if (*(char *)((int)in_ECX + 0x19) == *(char *)((int)in_EDX + 0x19)) {
                            if (*(char *)((int)in_ECX + 0x1a) == *(char *)((int)in_EDX + 0x1a)) {
                              if (*(char *)((int)in_ECX + 0x1b) == *(char *)((int)in_EDX + 0x1b)) {
                                if (in_ECX[7] == in_EDX[7]) {
                                  if (in_ECX[8] == in_EDX[8]) {
                                    if (in_ECX[9] == in_EDX[9]) {
                                      if (in_ECX[10] == in_EDX[10]) {
                                        if (in_ECX[0xb] == in_EDX[0xb]) {
                                          if (in_ECX[0xc] == in_EDX[0xc]) {
                                            if (in_ECX[0xd] == in_EDX[0xd]) {
                                              if (in_ECX[0xe] == in_EDX[0xe]) {
                                                if (in_ECX[0xf] == in_EDX[0xf]) {
                                                  iVar3 = 0;
                                                  piVar1 = in_ECX + 0x10;
                                                  iVar2 = 0;
                                                  local_98 = (int *)((int)in_EDX - (int)in_ECX);
                                                  do {
                                                    local_94 = *(int **)((int)local_98 + (int)piVar1
                                                                        );
                                                    if (*piVar1 !=
                                                        *(int *)((int)local_98 + (int)piVar1)) {
                                                      pcVar4 = 
                                                  "PORTALCLASS MISMATCH: EffectTimer[%d]: %d and %d"
                                                  ;
                                                  goto LAB_4fc269ec;
                                                  }
                                                  iVar2 = iVar2 + 1;
                                                  piVar1 = piVar1 + 1;
                                                  } while (iVar2 < 0x10);
                                                  if ((float)in_ECX[0x20] == (float)in_EDX[0x20]) {
                                                    if ((float)in_ECX[0x21] == (float)in_EDX[0x21])
                                                    {
                                                      if ((float)in_ECX[0x22] == (float)in_EDX[0x22]
                                                         ) {
                                                        if ((float)in_ECX[0x23] ==
                                                            (float)in_EDX[0x23]) {
                                                          if ((float)in_ECX[0x24] ==
                                                              (float)in_EDX[0x24]) {
                                                            if ((((float)in_ECX[0x25] ==
                                                                  (float)in_EDX[0x25]) &&
                                                                ((float)in_ECX[0x26] ==
                                                                 (float)in_EDX[0x26])) &&
                                                               ((float)in_ECX[0x27] ==
                                                                (float)in_EDX[0x27])) {
                                                              if ((((float)in_ECX[0x28] ==
                                                                    (float)in_EDX[0x28]) &&
                                                                  ((float)in_ECX[0x29] ==
                                                                   (float)in_EDX[0x29])) &&
                                                                 ((float)in_ECX[0x2a] ==
                                                                  (float)in_EDX[0x2a])) {
                                                                if ((((((float)in_ECX[0x33] !=
                                                                        (float)in_EDX[0x33]) ||
                                                                      ((float)in_ECX[0x34] !=
                                                                       (float)in_EDX[0x34])) ||
                                                                     ((((float)in_ECX[0x35] !=
                                                                        (float)in_EDX[0x35] ||
                                                                       (((((float)in_ECX[0x2b] !=
                                                                           (float)in_EDX[0x2b] ||
                                                                          ((float)in_ECX[0x2c] !=
                                                                           (float)in_EDX[0x2c])) ||
                                                                         ((float)in_ECX[0x2d] !=
                                                                          (float)in_EDX[0x2d])) ||
                                                                        (((float)in_ECX[0x2f] !=
                                                                          (float)in_EDX[0x2f] ||
                                                                         ((float)in_ECX[0x30] !=
                                                                          (float)in_EDX[0x30]))))))
                                                                      || ((float)in_ECX[0x31] !=
                                                                          (float)in_EDX[0x31])))) ||
                                                                    (((float)in_ECX[0x37] !=
                                                                      (float)in_EDX[0x37] ||
                                                                     ((float)in_ECX[0x38] !=
                                                                      (float)in_EDX[0x38])))) ||
                                                                   ((float)in_ECX[0x39] !=
                                                                    (float)in_EDX[0x39])) {
                                                                  FormatLogMessage(
                                                  "PORTALCLASS MISMATCH: ExitPoint Front: %f %f %f and %f %f %f, ExitPoint Right: %f %f %f and %f %f %f, ExitPoint Up: %f %f %f and %f %f %f, ExitPoint Posit: %f %f %f and %f %f %f"
                                                  );
                                                  return false;
                                                  }
                                                  if (in_ECX[0x3b] == in_EDX[0x3b]) {
                                                    if (in_ECX[0x3c] == in_EDX[0x3c]) {
                                                      if (in_ECX[0x3d] == in_EDX[0x3d]) {
                                                        if (in_ECX[0x3e] == in_EDX[0x3e]) {
                                                          if (in_ECX[0x3f] == in_EDX[0x3f]) {
                                                            if (in_ECX[0x40] == in_EDX[0x40]) {
                                                              if ((float)in_ECX[0x41] !=
                                                                  (float)in_EDX[0x41]) {
                                                                pcVar4 = 
                                                  "PORTALCLASS MISMATCH: ContinuousFxRange: %f and %f"
                                                  ;
                                                  goto LAB_4fc2603a;
                                                  }
                                                  local_90 = in_EDX + 0x43;
                                                  local_94 = in_ECX + 0x43;
                                                  iVar2 = _stricmp((char *)local_94,(char *)local_90
                                                                  );
                                                  if (iVar2 == 0) {
                                                    local_94 = in_EDX + 0x83;
                                                    local_90 = in_ECX + 0x83;
                                                    iVar2 = _stricmp((char *)local_90,
                                                                     (char *)local_94);
                                                    if (iVar2 == 0) {
                                                      piVar1 = in_ECX + 0x93;
                                                      do {
                                                        if ((int *)*piVar1 !=
                                                            *(int **)((int)piVar1 + (int)local_98))
                                                        {
                                                          pcVar4 = 
                                                  "PORTALCLASS MISMATCH: EffectHardLifeTime[%d]: %d and %d"
                                                  ;
                                                  local_98 = *(int **)((int)piVar1 + (int)local_98);
                                                  goto LAB_4fc269ec;
                                                  }
                                                  iVar3 = iVar3 + 1;
                                                  piVar1 = piVar1 + 1;
                                                  } while (iVar3 < 0x10);
                                                  local_98 = in_ECX + 0xa3;
                                                  iVar2 = _stricmp((char *)local_98,
                                                                   (char *)(in_EDX + 0xa3));
                                                  if (iVar2 == 0) {
                                                    local_98 = in_ECX + 0xb3;
                                                    iVar2 = _stricmp((char *)local_98,
                                                                     (char *)(in_EDX + 0xb3));
                                                    if (iVar2 == 0) {
                                                      local_98 = in_ECX + 0xc3;
                                                      iVar2 = _stricmp((char *)local_98,
                                                                       (char *)(in_EDX + 0xc3));
                                                      if (iVar2 == 0) {
                                                        local_98 = in_ECX + 0xd3;
                                                        iVar2 = _stricmp((char *)local_98,
                                                                         (char *)(in_EDX + 0xd3));
                                                        if (iVar2 == 0) {
                                                          if (in_ECX[0xe3] == in_EDX[0xe3]) {
                                                            return true;
                                                          }
                                                          pcVar4 = 
                                                  "PORTALCLASS MISMATCH: SoundHandle: %d and %d";
                                                  }
                                                  else {
                                                    pcVar4 = 
                                                  "PORTALCLASS MISMATCH: DeactivateSound: \'%s\' and \'%s\'"
                                                  ;
                                                  }
                                                  }
                                                  else {
                                                    pcVar4 = 
                                                  "PORTALCLASS MISMATCH: ActivateSound: \'%s\' and \'%s\'"
                                                  ;
                                                  }
                                                  }
                                                  else {
                                                    pcVar4 = 
                                                  "PORTALCLASS MISMATCH: TooCloseSound: \'%s\' and \'%s\'"
                                                  ;
                                                  }
                                                  }
                                                  else {
                                                    pcVar4 = 
                                                  "PORTALCLASS MISMATCH: TooFarSound: \'%s\' and \'%s\'"
                                                  ;
                                                  }
                                                  }
                                                  else {
                                                    pcVar4 = 
                                                  "PORTALCLASS MISMATCH: EffectBaseODF: \'%s\' and \'%s\'"
                                                  ;
                                                  }
                                                  }
                                                  else {
                                                    pcVar4 = 
                                                  "PORTALCLASS MISMATCH: TeleporterName: \'%s\' and \'%s\'"
                                                  ;
                                                  }
                                                  }
                                                  else {
                                                    pcVar4 = 
                                                  "PORTALCLASS MISMATCH: VehOutEffect: %d and %d";
                                                  }
                                                  }
                                                  else {
                                                    pcVar4 = 
                                                  "PORTALCLASS MISMATCH: VehInEffect: %d and %d";
                                                  }
                                                  }
                                                  else {
                                                    pcVar4 = 
                                                  "PORTALCLASS MISMATCH: OnEffect: %d and %d";
                                                  }
                                                  }
                                                  else {
                                                    pcVar4 = 
                                                  "PORTALCLASS MISMATCH: OutEffect: %d and %d";
                                                  }
                                                  }
                                                  else {
                                                    pcVar4 = 
                                                  "PORTALCLASS MISMATCH: InEffect: %d and %d";
                                                  }
                                                  }
                                                  else {
                                                    pcVar4 = 
                                                  "PORTALCLASS MISMATCH: DestinationIndex: %d and %d"
                                                  ;
                                                  }
                                                  goto LAB_4fc269ec;
                                                  }
                                                  pcVar4 = 
                                                  "PORTALCLASS MISMATCH: GotoPoint: %f %f %f and %f %f %f"
                                                  ;
                                                  }
                                                  else {
                                                    pcVar4 = 
                                                  "PORTALCLASS MISMATCH: Position: %f %f %f and %f %f %f"
                                                  ;
                                                  }
                                                  FormatLogMessage(pcVar4);
                                                  return false;
                                                  }
                                                  pcVar4 = 
                                                  "PORTALCLASS MISMATCH: CollisionRadius: %f and %f"
                                                  ;
                                                  }
                                                  else {
                                                    pcVar4 = 
                                                  "PORTALCLASS MISMATCH: DestMaxRange: %f and %f";
                                                  }
                                                  }
                                                  else {
                                                    pcVar4 = 
                                                  "PORTALCLASS MISMATCH: DestMinRange: %f and %f";
                                                  }
                                                  }
                                                  else {
                                                    pcVar4 = 
                                                  "PORTALCLASS MISMATCH: ExitSpeed: %f and %f";
                                                  }
                                                  }
                                                  else {
                                                    pcVar4 = 
                                                  "PORTALCLASS MISMATCH: EnterRange: %f and %f";
                                                  }
                                                  goto LAB_4fc2603a;
                                                }
                                                pcVar4 = 
                                                "PORTALCLASS MISMATCH: EffectState: %d and %d";
                                              }
                                              else {
                                                pcVar4 = 
                                                "PORTALCLASS MISMATCH: EffectNumber: %d and %d";
                                              }
                                            }
                                            else {
                                              pcVar4 = "PORTALCLASS MISMATCH: EffectType: %d and %d"
                                              ;
                                            }
                                          }
                                          else {
                                            pcVar4 = 
                                            "PORTALCLASS MISMATCH: TeleportFilter: %d and %d";
                                          }
                                        }
                                        else {
                                          pcVar4 = 
                                          "PORTALCLASS MISMATCH: TargetTeamFilter: %d and %d";
                                        }
                                      }
                                      else {
                                        pcVar4 = "PORTALCLASS MISMATCH: DestTeamFilter: %d and %d";
                                      }
                                    }
                                    else {
                                      pcVar4 = "PORTALCLASS MISMATCH: Channel: %d and %d";
                                    }
                                  }
                                  else {
                                    pcVar4 = "PORTALCLASS MISMATCH: MatchCycleIndex: %d and %d";
                                  }
                                }
                                else {
                                  pcVar4 = "PORTALCLASS MISMATCH: MatchType: %d and %d";
                                }
                              }
                              else {
                                pcVar4 = "PORTALCLASS MISMATCH: FxOnVehicle: %d and %d";
                              }
                            }
                            else {
                              pcVar4 = "PORTALCLASS MISMATCH: ScriptOverrideDest: %d and %d";
                            }
                          }
                          else {
                            pcVar4 = "PORTALCLASS MISMATCH: EnterGotoIsExit: %d and %d";
                          }
                        }
                        else {
                          pcVar4 = "PORTALCLASS MISMATCH: ContinuousFx: %d and %d";
                        }
                      }
                      else {
                        pcVar4 = "PORTALCLASS MISMATCH: KickAI: %d and %d";
                      }
                    }
                    else {
                      pcVar4 = "PORTALCLASS MISMATCH: UseCenter: %d and %d";
                    }
                  }
                  else {
                    pcVar4 = "PORTALCLASS MISMATCH: NameFlash: %d and %d";
                  }
                }
                else {
                  pcVar4 = "PORTALCLASS MISMATCH: ShowChannel: %d and %d";
                }
              }
              else {
                pcVar4 = "PORTALCLASS MISMATCH: ExitForwardOnly: %d and %d";
              }
            }
            else {
              pcVar4 = "PORTALCLASS MISMATCH: MatchTypeUsesChannels: %d and %d";
            }
          }
          else {
            pcVar4 = "PORTALCLASS MISMATCH: CanExit: %d and %d";
          }
        }
        else {
          pcVar4 = "PORTALCLASS MISMATCH: CanEnter: %d and %d";
        }
      }
      else {
        pcVar4 = "PORTALCLASS MISMATCH: TeleporterEffectSlot: %d and %d";
      }
LAB_4fc269ec:
      FormatLogMessage(pcVar4);
      return false;
    }
    memset(local_8c,0,0x40);
    memset(local_4c,0,0x40);
    GetODFName(unaff_EDI,unaff_ESI);
    GetODFName(unaff_EDI,unaff_ESI);
    pcVar4 = "PORTALCLASS MISMATCH: TeleporterDestination: %08x \'%s\' and %08x \'%s\'";
  }
  else {
    memset(local_4c,0,0x40);
    memset(local_8c,0,0x40);
    GetODFName(unaff_EDI,unaff_ESI);
    GetODFName(unaff_EDI,unaff_ESI);
    pcVar4 = "PORTALCLASS MISMATCH: TeleporterObject: %08x \'%s\' and %08x \'%s\'";
  }
LAB_4fc2603a:
  FormatLogMessage(pcVar4);
  return false;
}


// ---------------------------------------------------------------------
// operator==  @ 4fc26a0f  lines 436-477


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool __cdecl operator==(TeleportTargetClass *param_1,TeleportTargetClass *param_2)

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
    if (in_ECX[1] == in_EDX[1]) {
      if (in_ECX[2] != in_EDX[2]) {
        FormatLogMessage("TELEPORTTARGETCLASS MISMATCH: DestinationIndex: %d and %d");
        return false;
      }
      if ((float)in_ECX[3] == (float)in_EDX[3]) {
        if ((float)in_ECX[4] == (float)in_EDX[4]) {
          return true;
        }
        pcVar1 = "TELEPORTTARGETCLASS MISMATCH: DistanceFromDestination: %f and %f";
      }
      else {
        pcVar1 = "TELEPORTTARGETCLASS MISMATCH: DestEnterRange: %f and %f";
      }
    }
    else {
      memset(local_4c,0,0x40);
      memset(local_8c,0,0x40);
      GetODFName(unaff_EDI,unaff_ESI);
      GetODFName(unaff_EDI,unaff_ESI);
      pcVar1 = 
      "TELEPORTTARGETCLASS MISMATCH: TeleportTargetDestination: %08x \'%s\' and %08x \'%s\'";
    }
  }
  else {
    memset(local_8c,0,0x40);
    memset(local_4c,0,0x40);
    GetODFName(unaff_EDI,unaff_ESI);
    GetODFName(unaff_EDI,unaff_ESI);
    pcVar1 = "TELEPORTTARGETCLASS MISMATCH: TeleportTarget: %08x \'%s\' and %08x \'%s\'";
  }
  FormatLogMessage(pcVar1);
  return false;
}


// ---------------------------------------------------------------------
// PortalHelper::ShouldRemoveTeleportTarget  @ 4fc26b63  lines 489-489


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool __cdecl PortalHelper::ShouldRemoveTeleportTarget(TeleportTargetClass *param_1)

{
  float fVar1;
  bool bVar2;
  
  fVar1 = param_1->DestEnterRange + (float)___real_4014000000000000;
  if (((param_1->DistanceFromDestination <= fVar1 * fVar1) &&
      (bVar2 = IsAround(param_1->TeleportTarget), bVar2)) &&
     (bVar2 = IsAround(param_1->TeleportTargetDestination), bVar2)) {
    return false;
  }
  return true;
}

