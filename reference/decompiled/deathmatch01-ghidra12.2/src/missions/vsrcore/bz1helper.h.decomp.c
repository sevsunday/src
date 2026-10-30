// Reconstructed by Ghidra from deathmatch01.dll + deathmatch01.pdb
// Original source file: /e:/github/vsr_dll_source/missions/vsrcore/bz1helper.h
// Functions are ordered by original source line. This is decompiler
// output, not the author's source: names/types come from the PDB,
// local variable names and control flow are reconstructed.


// ---------------------------------------------------------------------
// operator==  @ 4fc08db9  lines 105-208


bool __cdecl operator==(MapInfo *param_1,MapInfo *param_2)

{
  float *in_EDX;
  char *pcVar1;
  
  if (TempMapInfoBuffer.Height == *in_EDX) {
    if (TempMapInfoBuffer.MapWidth == in_EDX[1]) {
      if (TempMapInfoBuffer.MapDepth == in_EDX[2]) {
        if (TempMapInfoBuffer.MPG == in_EDX[3]) {
          if (TempMapInfoBuffer.HeightGranularity == in_EDX[4]) {
            if (TempMapInfoBuffer.MinX == in_EDX[5]) {
              if (TempMapInfoBuffer.MinZ == in_EDX[6]) {
                if (TempMapInfoBuffer.MaxWidth == in_EDX[7]) {
                  if (TempMapInfoBuffer.MaxDepth == in_EDX[8]) {
                    if (TempMapInfoBuffer.MinWidth == in_EDX[9]) {
                      if (TempMapInfoBuffer.MinDepth == in_EDX[10]) {
                        if (TempMapInfoBuffer.Gravity == in_EDX[0xb]) {
                          if ((float)TempMapInfoBuffer.GravityState != in_EDX[0xc]) {
                            pcVar1 = "MAPINFO MISMATCH: GravityState: %d and %d";
                            goto LAB_4fc08fd1;
                          }
                          if (TempMapInfoBuffer.MinScrapHeight == in_EDX[0xd]) {
                            if (TempMapInfoBuffer.MaxScrapHeight == in_EDX[0xe]) {
                              if (TempMapInfoBuffer.RestrictAllScrap ==
                                  (bool)*(char *)(in_EDX + 0xf)) {
                                if (TempMapInfoBuffer.RespawnAtLowAltitude ==
                                    (bool)*(char *)((int)in_EDX + 0x3d)) {
                                  if (TempMapInfoBuffer.SpawnMinRadius == in_EDX[0x10]) {
                                    if (TempMapInfoBuffer.SpawnMaxRadius == in_EDX[0x11]) {
                                      return true;
                                    }
                                    pcVar1 = "MAPINFO MISMATCH: SpawnMaxRadius: %f and %f";
                                  }
                                  else {
                                    pcVar1 = "MAPINFO MISMATCH: SpawnMinRadius: %f and %f";
                                  }
                                  goto LAB_4fc08ddb;
                                }
                                pcVar1 = "MAPINFO MISMATCH: RespawnAtLowAltitude: %d and %d";
                              }
                              else {
                                pcVar1 = "MAPINFO MISMATCH: RestrictAllScrap: %d and %d";
                              }
LAB_4fc08fd1:
                              FormatLogMessage(pcVar1);
                              return false;
                            }
                            pcVar1 = "MAPINFO MISMATCH: MaxScrapHeight: %f and %f";
                          }
                          else {
                            pcVar1 = "MAPINFO MISMATCH: MinScrapHeight: %f and %f";
                          }
                        }
                        else {
                          pcVar1 = "MAPINFO MISMATCH: Gravity: %f and %f";
                        }
                      }
                      else {
                        pcVar1 = "MAPINFO MISMATCH: MinDepth: %f and %f";
                      }
                    }
                    else {
                      pcVar1 = "MAPINFO MISMATCH: MinWidth: %f and %f";
                    }
                  }
                  else {
                    pcVar1 = "MAPINFO MISMATCH: MaxDepth: %f and %f";
                  }
                }
                else {
                  pcVar1 = "MAPINFO MISMATCH: MaxWidth: %f and %f";
                }
              }
              else {
                pcVar1 = "MAPINFO MISMATCH: MinZ: %f and %f";
              }
            }
            else {
              pcVar1 = "MAPINFO MISMATCH: MinX: %f and %f";
            }
          }
          else {
            pcVar1 = "MAPINFO MISMATCH: HeightGranularity: %f and %f";
          }
        }
        else {
          pcVar1 = "MAPINFO MISMATCH: MPG: %f and %f";
        }
      }
      else {
        pcVar1 = "MAPINFO MISMATCH: MapDepth: %f and %f";
      }
    }
    else {
      pcVar1 = "MAPINFO MISMATCH: MapWidth: %f and %f";
    }
  }
  else {
    pcVar1 = "MAPINFO MISMATCH: Height: %f and %f";
  }
LAB_4fc08ddb:
  FormatLogMessage(pcVar1);
  return false;
}


// ---------------------------------------------------------------------
// operator==  @ 4fc090c9  lines 405-988


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool __cdecl operator==(TeamInfo *param_1,TeamInfo *param_2)

{
  int *piVar1;
  int *piVar2;
  int *in_ECX;
  int iVar3;
  int *in_EDX;
  int iVar4;
  char *pcVar5;
  int iVar6;
  char *unaff_ESI;
  int unaff_EDI;
  undefined1 auStack_b4 [4];
  int *local_b0;
  float *local_ac;
  char *local_a8;
  int local_a4;
  char *local_a0;
  int *local_9c;
  int local_98;
  int *local_94;
  undefined1 local_8c [64];
  undefined1 local_4c [68];
  uint local_8;
  
  local_8 = __security_cookie ^ (uint)auStack_b4;
  if (*in_ECX == *in_EDX) {
    if (in_ECX[1] == in_EDX[1]) {
      if (in_ECX[2] == in_EDX[2]) {
        if (in_ECX[3] == in_EDX[3]) {
          if (in_ECX[4] == in_EDX[4]) {
            if (in_ECX[5] == in_EDX[5]) {
              if (in_ECX[6] == in_EDX[6]) {
                local_a4 = (int)in_EDX - (int)in_ECX;
                piVar2 = in_EDX + 0x10;
                iVar4 = 0;
                piVar1 = in_ECX + 7;
                do {
                  local_a8 = (char *)*piVar1;
                  iVar6 = 0;
                  if (local_a8 != *(char **)(local_a4 + (int)piVar1)) {
                    memset(local_8c,0,0x40);
                    memset(local_4c,0,0x40);
                    GetODFName(unaff_EDI,unaff_ESI);
                    GetODFName(unaff_EDI,unaff_ESI);
                    pcVar5 = "TEAMINFO MISMATCH: BaseSlot: %d, %08x \'%s\' and %08x \'%s\'";
                    goto LAB_4fc0a270;
                  }
                  local_a8 = (char *)piVar1[9];
                  if (local_a8 != (char *)*piVar2) {
                    memset(local_8c,0,0x40);
                    memset(local_4c,0,0x40);
                    GetODFName(unaff_EDI,unaff_ESI);
                    GetODFName(unaff_EDI,unaff_ESI);
                    pcVar5 = "TEAMINFO MISMATCH: BaseSlotScrap: %d, %08x \'%s\' and %08x \'%s\'";
                    goto LAB_4fc0a270;
                  }
                  iVar4 = iVar4 + 1;
                  piVar1 = piVar1 + 1;
                  piVar2 = piVar2 + 1;
                } while (iVar4 < 9);
                if (in_ECX[0x19] == in_EDX[0x19]) {
                  if (in_ECX[0x1a] == in_EDX[0x1a]) {
                    if (in_ECX[0x1b] == in_EDX[0x1b]) {
                      if (in_ECX[0x1c] == in_EDX[0x1c]) {
                        if (in_ECX[0x1d] == in_EDX[0x1d]) {
                          if (in_ECX[0x1e] == in_EDX[0x1e]) {
                            if (in_ECX[0x1f] == in_EDX[0x1f]) {
                              piVar2 = in_ECX + 0x20;
                              iVar4 = iVar6;
                              do {
                                local_a8 = (char *)*piVar2;
                                if (local_a8 != *(char **)((int)piVar2 + local_a4)) {
                                  memset(local_8c,0,0x40);
                                  memset(local_4c,0,0x40);
                                  GetODFName(unaff_EDI,unaff_ESI);
                                  GetODFName(unaff_EDI,unaff_ESI);
                                  pcVar5 = 
                                  "TEAMINFO MISMATCH: LimiterObject: %d, %08x \'%s\' and %08x \'%s\'"
                                  ;
LAB_4fc0a270:
                                  FormatLogMessage(pcVar5);
                                  return false;
                                }
                                iVar4 = iVar4 + 1;
                                piVar2 = piVar2 + 1;
                              } while (iVar4 < 3);
                              if (in_ECX[0x23] == in_EDX[0x23]) {
                                if (in_ECX[0x24] == in_EDX[0x24]) {
                                  if (in_ECX[0x25] == in_EDX[0x25]) {
                                    if (in_ECX[0x26] == in_EDX[0x26]) {
                                      if (in_ECX[0x27] == in_EDX[0x27]) {
                                        if (in_ECX[0x28] == in_EDX[0x28]) {
                                          if (in_ECX[0x29] == in_EDX[0x29]) {
                                            if (in_ECX[0x2a] == in_EDX[0x2a]) {
                                              if (in_ECX[0x2b] == in_EDX[0x2b]) {
                                                if (in_ECX[0x2c] == in_EDX[0x2c]) {
                                                  if (in_ECX[0x2d] == in_EDX[0x2d]) {
                                                    if (in_ECX[0x2e] == in_EDX[0x2e]) {
                                                      if (in_ECX[0x2f] == in_EDX[0x2f]) {
                                                        if (in_ECX[0x30] == in_EDX[0x30]) {
                                                          if (in_ECX[0x31] == in_EDX[0x31]) {
                                                            if (in_ECX[0x32] == in_EDX[0x32]) {
                                                              if (in_ECX[0x33] == in_EDX[0x33]) {
                                                                if (in_ECX[0x34] == in_EDX[0x34]) {
                                                                  if (in_ECX[0x35] == in_EDX[0x35])
                                                                  {
                                                                    if (in_ECX[0x36] == in_EDX[0x36]
                                                                       ) {
                                                                      if (in_ECX[0x37] ==
                                                                          in_EDX[0x37]) {
                                                                        if (in_ECX[0x38] ==
                                                                            in_EDX[0x38]) {
                                                                          if (in_ECX[0x39] ==
                                                                              in_EDX[0x39]) {
                                                                            if ((char)in_ECX[0x43]
                                                                                == (char)in_EDX[0x43
                                                  ]) {
                                                    if (*(char *)((int)in_ECX + 0x10d) ==
                                                        *(char *)((int)in_EDX + 0x10d)) {
                                                      if (*(char *)((int)in_ECX + 0x10e) ==
                                                          *(char *)((int)in_EDX + 0x10e)) {
                                                        if (*(char *)((int)in_ECX + 0x10f) ==
                                                            *(char *)((int)in_EDX + 0x10f)) {
                                                          if ((char)in_ECX[0x44] ==
                                                              (char)in_EDX[0x44]) {
                                                            if (*(char *)((int)in_ECX + 0x111) ==
                                                                *(char *)((int)in_EDX + 0x111)) {
                                                              if (*(char *)((int)in_ECX + 0x112) ==
                                                                  *(char *)((int)in_EDX + 0x112)) {
                                                                if (*(char *)((int)in_ECX + 0x113)
                                                                    == *(char *)((int)in_EDX + 0x113
                                                                                )) {
                                                                  piVar2 = in_ECX + 0x45;
                                                                  iVar4 = iVar6;
                                                                  do {
                                                                    if ((char)*piVar2 !=
                                                                        *(char *)((int)piVar2 +
                                                                                 local_a4)) {
                                                                      pcVar5 = 
                                                  "TEAMINFO MISMATCH: BaseSlotUseScrapHold:, %d, %d and %d"
                                                  ;
                                                  goto LAB_4fc0a045;
                                                  }
                                                  iVar4 = iVar4 + 1;
                                                  piVar2 = (int *)((int)piVar2 + 1);
                                                  } while (iVar4 < 9);
                                                  if (*(char *)((int)in_ECX + 0x11d) ==
                                                      *(char *)((int)in_EDX + 0x11d)) {
                                                    if (*(char *)((int)in_ECX + 0x11e) ==
                                                        *(char *)((int)in_EDX + 0x11e)) {
                                                      if (*(char *)((int)in_ECX + 0x11f) ==
                                                          *(char *)((int)in_EDX + 0x11f)) {
                                                        if ((char)in_ECX[0x48] == (char)in_EDX[0x48]
                                                           ) {
                                                          if (*(char *)((int)in_ECX + 0x121) ==
                                                              *(char *)((int)in_EDX + 0x121)) {
                                                            if (*(char *)((int)in_ECX + 0x122) ==
                                                                *(char *)((int)in_EDX + 0x122)) {
                                                              if (*(char *)((int)in_ECX + 0x123) ==
                                                                  *(char *)((int)in_EDX + 0x123)) {
                                                                if ((char)in_ECX[0x49] ==
                                                                    (char)in_EDX[0x49]) {
                                                                  if ((float)in_ECX[0x4a] ==
                                                                      (float)in_EDX[0x4a]) {
                                                                    if ((float)in_ECX[0x4b] ==
                                                                        (float)in_EDX[0x4b]) {
                                                                      if ((float)in_ECX[0x4c] ==
                                                                          (float)in_EDX[0x4c]) {
                                                                        if ((float)in_ECX[0x4d] ==
                                                                            (float)in_EDX[0x4d]) {
                                                                          if ((float)in_ECX[0x4e] ==
                                                                              (float)in_EDX[0x4e]) {
                                                                            if ((float)in_ECX[0x4f]
                                                                                == (float)in_EDX[
                                                  0x4f]) {
                                                    if ((float)in_ECX[0x50] == (float)in_EDX[0x50])
                                                    {
                                                      if ((float)in_ECX[0x51] == (float)in_EDX[0x51]
                                                         ) {
                                                        if ((((float)in_ECX[0x52] ==
                                                              (float)in_EDX[0x52]) &&
                                                            ((float)in_ECX[0x53] ==
                                                             (float)in_EDX[0x53])) &&
                                                           ((float)in_ECX[0x54] ==
                                                            (float)in_EDX[0x54])) {
                                                          if ((((float)in_ECX[0x55] ==
                                                                (float)in_EDX[0x55]) &&
                                                              ((float)in_ECX[0x56] ==
                                                               (float)in_EDX[0x56])) &&
                                                             ((float)in_ECX[0x57] ==
                                                              (float)in_EDX[0x57])) {
                                                            if ((((float)in_ECX[0x58] ==
                                                                  (float)in_EDX[0x58]) &&
                                                                ((float)in_ECX[0x59] ==
                                                                 (float)in_EDX[0x59])) &&
                                                               ((float)in_ECX[0x5a] ==
                                                                (float)in_EDX[0x5a])) {
                                                              if ((char)in_ECX[0x5b] ==
                                                                  (char)in_EDX[0x5b]) {
                                                                local_ac = (float *)((int)in_EDX +
                                                                                    0x16d);
                                                                local_b0 = (int *)((int)in_ECX +
                                                                                  0x16d);
                                                                local_94 = in_EDX;
                                                                iVar4 = _stricmp((char *)local_b0,
                                                                                 (char *)local_ac);
                                                                if (iVar4 == 0) {
                                                                  local_ac = (float *)((int)in_EDX +
                                                                                      0x1ad);
                                                                  local_b0 = (int *)((int)in_ECX +
                                                                                    0x1ad);
                                                                  iVar4 = _stricmp((char *)local_b0,
                                                                                   (char *)local_ac)
                                                                  ;
                                                                  if (iVar4 == 0) {
                                                                    local_ac = (float *)((int)in_EDX
                                                                                        + 0x1ed);
                                                                    local_b0 = (int *)((int)in_ECX +
                                                                                      0x1ed);
                                                                    iVar4 = _stricmp((char *)
                                                  local_b0,(char *)local_ac);
                                                  if (iVar4 == 0) {
                                                    local_a0 = (char *)0x0;
                                                    pcVar5 = (char *)((int)in_ECX + 0x2ed);
                                                    do {
                                                      iVar4 = _stricmp(pcVar5,pcVar5 + local_a4);
                                                      if (iVar4 != 0) {
                                                        pcVar5 = 
                                                  "TEAMINFO MISMATCH: PilotWeapon: %d, \'%s\' and \'%s\'"
                                                  ;
                                                  goto LAB_4fc0a045;
                                                  }
                                                  pcVar5 = pcVar5 + 0x40;
                                                  local_a0 = local_a0 + 1;
                                                  } while ((int)local_a0 < 5);
                                                  local_ac = (float *)((int)in_EDX + 0x42d);
                                                  local_b0 = (int *)((int)in_ECX + 0x42d);
                                                  iVar4 = _stricmp((char *)local_b0,(char *)local_ac
                                                                  );
                                                  if (iVar4 == 0) {
                                                    local_ac = (float *)((int)in_EDX + 0x46d);
                                                    local_b0 = (int *)((int)in_ECX + 0x46d);
                                                    iVar4 = _stricmp((char *)local_b0,
                                                                     (char *)local_ac);
                                                    if (iVar4 == 0) {
                                                      local_ac = (float *)(in_EDX + 0x27c);
                                                      local_98 = 0x216;
                                                      local_9c = in_ECX + 0x1bc;
                                                      local_b0 = in_ECX + 0x3a;
                                                      local_a0 = (char *)((int)in_ECX + 0x4ad);
                                                      do {
                                                        iVar3 = 0;
                                                        local_a8 = local_a0 + local_a4;
                                                        iVar4 = _stricmp(local_a0,local_a8);
                                                        if (iVar4 != 0) {
                                                          pcVar5 = 
                                                  "TEAMINFO MISMATCH: BaseSlotName%d: \'%s\' and \'%s\'"
                                                  ;
                                                  goto LAB_4fc0a045;
                                                  }
                                                  piVar2 = local_9c;
                                                  do {
                                                    local_a8 = *(char **)((int)piVar2 + local_a4);
                                                    if (*piVar2 != *(int *)((int)piVar2 + local_a4))
                                                    {
                                                      pcVar5 = 
                                                  "TEAMINFO MISMATCH: BaseSlotPilotCost%d_%d: %d and %d"
                                                  ;
                                                  goto LAB_4fc0913d;
                                                  }
                                                  local_a8 = (char *)local_94[local_98 + iVar3];
                                                  if ((char *)in_ECX[local_98 + iVar3] != local_a8)
                                                  {
                                                    pcVar5 = 
                                                  "TEAMINFO MISMATCH: BaseSlotScrapCost%d_%d: %d and %d"
                                                  ;
                                                  goto LAB_4fc0913d;
                                                  }
                                                  iVar3 = iVar3 + 1;
                                                  piVar2 = piVar2 + 1;
                                                  } while (iVar3 < 10);
                                                  if (*(char *)((int)in_ECX + iVar6 + 0x9c0) !=
                                                      *(char *)((int)local_94 + iVar6 + 0x9c0)) {
                                                    pcVar5 = 
                                                  "TEAMINFO MISMATCH: ShowPilotCosts%d: %d and %d";
LAB_4fc0a045:
                                                  FormatLogMessage(pcVar5);
                                                  return false;
                                                  }
                                                  if (*local_b0 !=
                                                      *(int *)((int)local_b0 + local_a4)) {
                                                    pcVar5 = 
                                                  "TEAMINFO MISMATCH: BaseSlotBuildCount: %d and %d"
                                                  ;
                                                  goto LAB_4fc096ae;
                                                  }
                                                  if ((float)local_b0[0x239] != local_ac[-9]) {
                                                    pcVar5 = 
                                                  "TEAMINFO MISMATCH: BaseSlotPlayingAnim: %d and %d"
                                                  ;
                                                  goto LAB_4fc096ae;
                                                  }
                                                  if ((float)local_b0[0x242] != *local_ac) {
                                                    pcVar5 = 
                                                  "TEAMINFO MISMATCH: BaseSlotAnimationFrames: %f and %f"
                                                  ;
                                                  goto LAB_4fc0913d;
                                                  }
                                                  local_b0 = local_b0 + 1;
                                                  local_9c = local_9c + 10;
                                                  local_ac = local_ac + 1;
                                                  local_a0 = local_a0 + 0x40;
                                                  local_98 = local_98 + 10;
                                                  iVar6 = iVar6 + 1;
                                                  if (0x26f < local_98) {
                                                    return true;
                                                  }
                                                  } while( true );
                                                  }
                                                  pcVar5 = 
                                                  "TEAMINFO MISMATCH: SatelliteODF: \'%s\' and \'%s\'"
                                                  ;
                                                  }
                                                  else {
                                                    pcVar5 = 
                                                  "TEAMINFO MISMATCH: PlayerPilotODF: \'%s\' and \'%s\'"
                                                  ;
                                                  }
                                                  }
                                                  else {
                                                    pcVar5 = 
                                                  "TEAMINFO MISMATCH: TeamAIPFile: \'%s\' and \'%s\'"
                                                  ;
                                                  }
                                                  }
                                                  else {
                                                    pcVar5 = 
                                                  "TEAMINFO MISMATCH: PlayerName: \'%s\' and \'%s\'"
                                                  ;
                                                  }
                                                  }
                                                  else {
                                                    pcVar5 = 
                                                  "TEAMINFO MISMATCH: ArmoryBuildClass: \'%s\' and \'%s\'"
                                                  ;
                                                  }
                                                  }
                                                  else {
                                                    pcVar5 = 
                                                  "TEAMINFO MISMATCH: MaxPilots: %c and %c";
                                                  }
                                                  goto LAB_4fc096ae;
                                                  }
                                                  pcVar5 = 
                                                  "TEAMINFO MISMATCH: GoalPos: %f %f %f and %f %f %f"
                                                  ;
                                                  }
                                                  else {
                                                    pcVar5 = 
                                                  "TEAMINFO MISMATCH: ReinforcementPos: %f %f %f and %f %f %f"
                                                  ;
                                                  }
                                                  }
                                                  else {
                                                    pcVar5 = 
                                                  "TEAMINFO MISMATCH: PlayerSpawnPos: %f %f %f and %f %f %f"
                                                  ;
                                                  }
                                                  FormatLogMessage(pcVar5);
                                                  return false;
                                                  }
                                                  pcVar5 = 
                                                  "TEAMINFO MISMATCH: m_CPUBuildPodMaxDelay: %d and %d"
                                                  ;
                                                  }
                                                  else {
                                                    pcVar5 = 
                                                  "TEAMINFO MISMATCH: m_CPUBuildPodMinDelay: %d and %d"
                                                  ;
                                                  }
                                                  }
                                                  else {
                                                    pcVar5 = 
                                                  "TEAMINFO MISMATCH: m_CPUBuildingRepairHealthRatio: %d and %d"
                                                  ;
                                                  }
                                                  }
                                                  else {
                                                    pcVar5 = 
                                                  "TEAMINFO MISMATCH: m_CPUBuildingRepairInterval: %d and %d"
                                                  ;
                                                  }
                                                  }
                                                  else {
                                                    pcVar5 = 
                                                  "TEAMINFO MISMATCH: m_CPUBuildingRepairChance: %d and %d"
                                                  ;
                                                  }
                                                  }
                                                  else {
                                                    pcVar5 = 
                                                  "TEAMINFO MISMATCH: m_CPUPilotCheatDelay: %d and %d"
                                                  ;
                                                  }
                                                  }
                                                  else {
                                                    pcVar5 = 
                                                  "TEAMINFO MISMATCH: m_CPUDayWreckerInterval: %f and %f"
                                                  ;
                                                  }
                                                  }
                                                  else {
                                                    pcVar5 = 
                                                  "TEAMINFO MISMATCH: m_CPUDayWreckerChance: %f and %f"
                                                  ;
                                                  }
                                                  goto LAB_4fc0913d;
                                                  }
                                                  pcVar5 = 
                                                  "TEAMINFO MISMATCH: SatelliteObjectify: %d and %d"
                                                  ;
                                                  }
                                                  else {
                                                    pcVar5 = 
                                                  "TEAMINFO MISMATCH: UseSiteCamera: %d and %d";
                                                  }
                                                  }
                                                  else {
                                                    pcVar5 = 
                                                  "TEAMINFO MISMATCH: PlayCommTowerSound: %d and %d"
                                                  ;
                                                  }
                                                  }
                                                  else {
                                                    pcVar5 = 
                                                  "TEAMINFO MISMATCH: GiveBackWeapons: %d and %d";
                                                  }
                                                  }
                                                  else {
                                                    pcVar5 = 
                                                  "TEAMINFO MISMATCH: PlayerWasPilot: %d and %d";
                                                  }
                                                  }
                                                  else {
                                                    pcVar5 = 
                                                  "TEAMINFO MISMATCH: CommTowerAround: %d and %d";
                                                  }
                                                  }
                                                  else {
                                                    pcVar5 = 
                                                  "TEAMINFO MISMATCH: m_CPUDoDispatch: %d and %d";
                                                  }
                                                  }
                                                  else {
                                                    pcVar5 = 
                                                  "TEAMINFO MISMATCH: m_CPUUnitsCanService: %d and %d"
                                                  ;
                                                  }
                                                  }
                                                  else {
                                                    pcVar5 = 
                                                  "TEAMINFO MISMATCH: TookControlThisTurn: %d and %d"
                                                  ;
                                                  }
                                                  }
                                                  else {
                                                    pcVar5 = 
                                                  "TEAMINFO MISMATCH: NoPlayerPilot: %d and %d";
                                                  }
                                                  }
                                                  else {
                                                    pcVar5 = 
                                                  "TEAMINFO MISMATCH: m_UseLimits: %d and %d";
                                                  }
                                                  }
                                                  else {
                                                    pcVar5 = 
                                                  "TEAMINFO MISMATCH: m_HadPilots: %d and %d";
                                                  }
                                                  }
                                                  else {
                                                    pcVar5 = 
                                                  "TEAMINFO MISMATCH: m_UsePilots: %d and %d";
                                                  }
                                                  }
                                                  else {
                                                    pcVar5 = 
                                                  "TEAMINFO MISMATCH: RespawnPlayer: %d and %d";
                                                  }
                                                  }
                                                  else {
                                                    pcVar5 = 
                                                  "TEAMINFO MISMATCH: TeamIsDead: %d and %d";
                                                  }
                                                  }
                                                  else {
                                                    pcVar5 = 
                                                  "TEAMINFO MISMATCH: PlayedScrapDropVO: %d and %d";
                                                  }
                                                  }
                                                  else {
                                                    pcVar5 = 
                                                  "TEAMINFO MISMATCH: DropoffSilos: %d and %d";
                                                  }
                                                  }
                                                  else {
                                                    pcVar5 = 
                                                  "TEAMINFO MISMATCH: DropoffExtractors: %d and %d";
                                                  }
                                                  }
                                                  else {
                                                    pcVar5 = 
                                                  "TEAMINFO MISMATCH: DropoffRecylcers: %d and %d";
                                                  }
                                                  }
                                                  else {
                                                    pcVar5 = 
                                                  "TEAMINFO MISMATCH: RespawnTime: %d and %d";
                                                  }
                                                  }
                                                  else {
                                                    pcVar5 = 
                                                  "TEAMINFO MISMATCH: PlayerLives: %d and %d";
                                                  }
                                                  }
                                                  else {
                                                    pcVar5 = 
                                                  "TEAMINFO MISMATCH: SatellitePrevIndependence: %d and %d"
                                                  ;
                                                  }
                                                  }
                                                  else {
                                                    pcVar5 = 
                                                  "TEAMINFO MISMATCH: SatelliteSiteCamAmmo: %d and %d"
                                                  ;
                                                  }
                                                  }
                                                  else {
                                                    pcVar5 = 
                                                  "TEAMINFO MISMATCH: SatelliteOutOfAmmo: %d and %d"
                                                  ;
                                                  }
                                                  }
                                                  else {
                                                    pcVar5 = 
                                                  "TEAMINFO MISMATCH: SatelliteViewActive: %d and %d"
                                                  ;
                                                  }
                                                  }
                                                  else {
                                                    pcVar5 = 
                                                  "TEAMINFO MISMATCH: NumTeamObjects: %d and %d";
                                                  }
                                                  }
                                                  else {
                                                    pcVar5 = 
                                                  "TEAMINFO MISMATCH: NumBarracks: %d and %d";
                                                  }
                                                  }
                                                  else {
                                                    pcVar5 = 
                                                  "TEAMINFO MISMATCH: ReinforcementCount: %d and %d"
                                                  ;
                                                  }
                                                  }
                                                  else {
                                                    pcVar5 = 
                                                  "TEAMINFO MISMATCH: m_CPUNumEscortUnits: %d and %d"
                                                  ;
                                                  }
                                                }
                                                else {
                                                  pcVar5 = 
                                                  "TEAMINFO MISMATCH: m_CPUNumHuntUnits: %d and %d";
                                                }
                                              }
                                              else {
                                                pcVar5 = 
                                                "TEAMINFO MISMATCH: m_CPUNumPatrolUnits: %d and %d";
                                              }
                                            }
                                            else {
                                              pcVar5 = 
                                              "TEAMINFO MISMATCH: m_CPUMaxEscortUnits: %d and %d";
                                            }
                                          }
                                          else {
                                            pcVar5 = 
                                            "TEAMINFO MISMATCH: m_CPUMaxHuntUnits: %d and %d";
                                          }
                                        }
                                        else {
                                          pcVar5 = 
                                          "TEAMINFO MISMATCH: m_CPUMaxPatrolUnits: %d and %d";
                                        }
                                      }
                                      else {
                                        pcVar5 = 
                                        "TEAMINFO MISMATCH: m_CPUPilotCheatAmount: %d and %d";
                                      }
                                    }
                                    else {
                                      pcVar5 = "TEAMINFO MISMATCH: m_CPUAIDifficulty: %d and %d";
                                    }
                                  }
                                  else {
                                    pcVar5 = "TEAMINFO MISMATCH: CurrPilots: %d and %d";
                                  }
                                }
                                else {
                                  pcVar5 = "TEAMINFO MISMATCH: MaxPilots: %d and %d";
                                }
LAB_4fc096ae:
                                FormatLogMessage(pcVar5);
                                return false;
                              }
                              memset(local_8c,0,0x40);
                              memset(local_4c,0,0x40);
                              GetODFName(unaff_EDI,unaff_ESI);
                              GetODFName(unaff_EDI,unaff_ESI);
                              pcVar5 = "TEAMINFO MISMATCH: LimitPlayer: %08x \'%s\' and %08x \'%s\'"
                              ;
                            }
                            else {
                              memset(local_8c,0,0x40);
                              memset(local_4c,0,0x40);
                              GetODFName(unaff_EDI,unaff_ESI);
                              GetODFName(unaff_EDI,unaff_ESI);
                              pcVar5 = "TEAMINFO MISMATCH: Transport: %08x \'%s\' and %08x \'%s\'";
                            }
                          }
                          else {
                            memset(local_8c,0,0x40);
                            memset(local_4c,0,0x40);
                            GetODFName(unaff_EDI,unaff_ESI);
                            GetODFName(unaff_EDI,unaff_ESI);
                            pcVar5 = "TEAMINFO MISMATCH: ImaPilot: %08x \'%s\' and %08x \'%s\'";
                          }
                        }
                        else {
                          memset(local_8c,0,0x40);
                          memset(local_4c,0,0x40);
                          GetODFName(unaff_EDI,unaff_ESI);
                          GetODFName(unaff_EDI,unaff_ESI);
                          pcVar5 = 
                          "TEAMINFO MISMATCH: SatelliteLastShooter: %08x \'%s\' and %08x \'%s\'";
                        }
                      }
                      else {
                        memset(local_8c,0,0x40);
                        memset(local_4c,0,0x40);
                        GetODFName(unaff_EDI,unaff_ESI);
                        GetODFName(unaff_EDI,unaff_ESI);
                        pcVar5 = "TEAMINFO MISMATCH: SatelliteLock: %08x \'%s\' and %08x \'%s\'";
                      }
                    }
                    else {
                      memset(local_8c,0,0x40);
                      memset(local_4c,0,0x40);
                      GetODFName(unaff_EDI,unaff_ESI);
                      GetODFName(unaff_EDI,unaff_ESI);
                      pcVar5 = "TEAMINFO MISMATCH: SatelliteOff: %08x \'%s\' and %08x \'%s\'";
                    }
                  }
                  else {
                    memset(local_8c,0,0x40);
                    memset(local_4c,0,0x40);
                    GetODFName(unaff_EDI,unaff_ESI);
                    GetODFName(unaff_EDI,unaff_ESI);
                    pcVar5 = "TEAMINFO MISMATCH: SatelliteOn: %08x \'%s\' and %08x \'%s\'";
                  }
                }
                else {
                  memset(local_8c,0,0x40);
                  memset(local_4c,0,0x40);
                  GetODFName(unaff_EDI,unaff_ESI);
                  GetODFName(unaff_EDI,unaff_ESI);
                  pcVar5 = "TEAMINFO MISMATCH: CommTower: %08x \'%s\' and %08x \'%s\'";
                }
              }
              else {
                memset(local_8c,0,0x40);
                memset(local_4c,0,0x40);
                GetODFName(unaff_EDI,unaff_ESI);
                GetODFName(unaff_EDI,unaff_ESI);
                pcVar5 = "TEAMINFO MISMATCH: Constructor: %08x \'%s\' and %08x \'%s\'";
              }
            }
            else {
              memset(local_8c,0,0x40);
              memset(local_4c,0,0x40);
              GetODFName(unaff_EDI,unaff_ESI);
              GetODFName(unaff_EDI,unaff_ESI);
              pcVar5 = "TEAMINFO MISMATCH: Armory: %08x \'%s\' and %08x \'%s\'";
            }
          }
          else {
            memset(local_8c,0,0x40);
            memset(local_4c,0,0x40);
            GetODFName(unaff_EDI,unaff_ESI);
            GetODFName(unaff_EDI,unaff_ESI);
            pcVar5 = "TEAMINFO MISMATCH: Factory: %08x \'%s\' and %08x \'%s\'";
          }
        }
        else {
          memset(local_8c,0,0x40);
          memset(local_4c,0,0x40);
          GetODFName(unaff_EDI,unaff_ESI);
          GetODFName(unaff_EDI,unaff_ESI);
          pcVar5 = "TEAMINFO MISMATCH: Recycler: %08x \'%s\' and %08x \'%s\'";
        }
      }
      else {
        memset(local_8c,0,0x40);
        memset(local_4c,0,0x40);
        GetODFName(unaff_EDI,unaff_ESI);
        GetODFName(unaff_EDI,unaff_ESI);
        pcVar5 = "TEAMINFO MISMATCH: SatellitePlayer: %08x \'%s\' and %08x \'%s\'";
      }
    }
    else {
      memset(local_8c,0,0x40);
      memset(local_4c,0,0x40);
      GetODFName(unaff_EDI,unaff_ESI);
      GetODFName(unaff_EDI,unaff_ESI);
      pcVar5 = "TEAMINFO MISMATCH: Player: %08x \'%s\' and %08x \'%s\'";
    }
  }
  else {
    memset(local_4c,0,0x40);
    memset(local_8c,0,0x40);
    GetODFName(unaff_EDI,unaff_ESI);
    GetODFName(unaff_EDI,unaff_ESI);
    pcVar5 = "TEAMINFO MISMATCH: RealPlayer: %08x \'%s\' and %08x \'%s\'";
  }
LAB_4fc0913d:
  FormatLogMessage(pcVar5);
  return false;
}


// ---------------------------------------------------------------------
// operator==  @ 4fc0a293  lines 1001-1020


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool __cdecl operator==(AlignTerrainReplaceClass *param_1,AlignTerrainReplaceClass *param_2)

{
  int *in_ECX;
  int *in_EDX;
  char *unaff_ESI;
  int unaff_EDI;
  undefined1 local_8c [64];
  undefined1 local_4c [68];
  undefined4 local_8;
  
  local_8 = __security_cookie ^ (uint)(local_4c + 0x48);
  if (*in_ECX == *in_EDX) {
    if ((((float)in_ECX[1] == (float)in_EDX[1]) && ((float)in_ECX[2] == (float)in_EDX[2])) &&
       ((float)in_ECX[3] == (float)in_EDX[3])) {
      return true;
    }
    FormatLogMessage("ALIGNTERRAINREPLACE MISMATCH: NormalVec: %f %f %f and %f %f %f");
  }
  else {
    memset(local_8c,0,0x40);
    memset(local_4c,0,0x40);
    GetODFName(unaff_EDI,unaff_ESI);
    GetODFName(unaff_EDI,unaff_ESI);
    FormatLogMessage("ALIGNTERRAINREPLACE MISMATCH: AlignHandle: %08x \'%s\' and %08x \'%s\'");
  }
  return false;
}


// ---------------------------------------------------------------------
// operator==  @ 4fc0a387  lines 1033-1052


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool __cdecl operator==(DeleteAfterDelayClass *param_1,DeleteAfterDelayClass *param_2)

{
  int *in_ECX;
  int *in_EDX;
  char *unaff_ESI;
  int unaff_EDI;
  undefined1 local_8c [64];
  undefined1 local_4c [68];
  undefined4 local_8;
  
  local_8 = __security_cookie ^ (uint)(local_4c + 0x48);
  if (*in_ECX == *in_EDX) {
    if (in_ECX[1] == in_EDX[1]) {
      return true;
    }
    FormatLogMessage("DELETEAFTERDELAY MISMATCH: TurnsRemaining: %d and %d");
  }
  else {
    memset(local_8c,0,0x40);
    memset(local_4c,0,0x40);
    GetODFName(unaff_EDI,unaff_ESI);
    GetODFName(unaff_EDI,unaff_ESI);
    FormatLogMessage(
                    "DELETEAFTERDELAYLIST MISMATCH: DeleteAfterDelayHandle: %08x \'%s\' and %08x \'%s\'"
                    );
  }
  return false;
}


// ---------------------------------------------------------------------
// operator==  @ 4fc0a42d  lines 1070-1118


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool __cdecl operator==(DeploySoundClass *param_1,DeploySoundClass *param_2)

{
  int iVar1;
  int *in_ECX;
  int *in_EDX;
  char *unaff_ESI;
  int unaff_EDI;
  char *pcVar2;
  undefined1 local_8c [64];
  undefined1 local_4c [68];
  undefined4 local_8;
  
  local_8 = __security_cookie ^ (uint)(local_4c + 0x48);
  if (*in_ECX == *in_EDX) {
    if ((char)in_ECX[1] == (char)in_EDX[1]) {
      if (in_ECX[2] == in_EDX[2]) {
        if (in_ECX[3] == in_EDX[3]) {
          if (in_ECX[4] == in_EDX[4]) {
            if (in_ECX[5] == in_EDX[5]) {
              iVar1 = _stricmp((char *)(in_ECX + 6),(char *)(in_EDX + 6));
              if (iVar1 == 0) {
                return true;
              }
              pcVar2 = "DEPLOYSOUNDCLASS MISMATCH: DeploySound: \'%s\' and \'%s\'";
            }
            else {
              pcVar2 = "DEPLOYSOUNDCLASS MISMATCH: AudioFileTurns: %d and %d";
            }
          }
          else {
            pcVar2 = "DEPLOYSOUNDCLASS MISMATCH: RepeatDelay: %d and %d";
          }
        }
        else {
          pcVar2 = "DEPLOYSOUNDCLASS MISMATCH: StartDelay: %d and %d";
        }
      }
      else {
        pcVar2 = "DEPLOYSOUNDCLASS MISMATCH: AudioHandle: %d and %d";
      }
    }
    else {
      pcVar2 = "DEPLOYSOUNDCLASS MISMATCH: DoesLoop: %d and %d";
    }
    FormatLogMessage(pcVar2);
  }
  else {
    memset(local_8c,0,0x40);
    memset(local_4c,0,0x40);
    GetODFName(unaff_EDI,unaff_ESI);
    GetODFName(unaff_EDI,unaff_ESI);
    FormatLogMessage("DEPLOYSOUNDCLASS MISMATCH: ObjectHandle: %08x \'%s\' and %08x \'%s\'");
  }
  return false;
}


// ---------------------------------------------------------------------
// operator==  @ 4fc0a545  lines 1134-1170


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool __cdecl operator==(BuildAtClass *param_1,BuildAtClass *param_2)

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
    if ((((float)in_ECX[1] == (float)in_EDX[1]) && ((float)in_ECX[2] == (float)in_EDX[2])) &&
       ((float)in_ECX[3] == (float)in_EDX[3])) {
      if (in_ECX[4] == in_EDX[4]) {
        if (in_ECX[5] == in_EDX[5]) {
          if (in_ECX[6] == in_EDX[6]) {
            return true;
          }
          pcVar1 = "BUILDATCLASS MISMATCH: BuilderType: %d and %d";
        }
        else {
          pcVar1 = "BUILDATCLASS MISMATCH: Priority: %d and %d";
        }
      }
      else {
        pcVar1 = "BUILDATCLASS MISMATCH: BuildTurn: %d and %d";
      }
      FormatLogMessage(pcVar1);
    }
    else {
      FormatLogMessage("BUILDATCLASS MISMATCH: DropoffPos: %f %f %f and %f %f %f");
    }
  }
  else {
    memset(local_8c,0,0x40);
    memset(local_4c,0,0x40);
    GetODFName(unaff_EDI,unaff_ESI);
    GetODFName(unaff_EDI,unaff_ESI);
    FormatLogMessage("BUILDATCLASS MISMATCH: BuilderHandle: %08x \'%s\' and %08x \'%s\'");
  }
  return false;
}


// ---------------------------------------------------------------------
// BZ1Helper::ShouldRemoveDeploySound  @ 4fc0a691  lines 1274-1274


bool __cdecl BZ1Helper::ShouldRemoveDeploySound(DeploySoundClass *param_1)

{
  bool bVar1;
  
  bVar1 = IsAround(param_1->ObjectHandle);
  if ((!bVar1) || ((bVar1 = false, param_1->DoesLoop == false && (param_1->StartDelay < 1)))) {
    bVar1 = true;
  }
  return bVar1;
}


// ---------------------------------------------------------------------
// BZ1Helper::ShouldRemoveBuildAt  @ 4fc0a6b3  lines 1277-1277


bool __cdecl BZ1Helper::ShouldRemoveBuildAt(BuildAtClass *param_1)

{
  bool bVar1;
  
  bVar1 = IsAround(param_1->BuilderHandle);
  if ((bVar1) && (m_TurnCounter <= param_1->BuildTurn)) {
    return false;
  }
  return true;
}

