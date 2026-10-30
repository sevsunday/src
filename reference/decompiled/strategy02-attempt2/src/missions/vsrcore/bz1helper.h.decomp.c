// Reconstructed by Ghidra from Strategy02.dll + Strategy02.pdb
// Original source file: /e:/github/vsr_dll_source/missions/vsrcore/bz1helper.h
// Functions are ordered by original source line. This is decompiler
// output, not the author's source: names/types come from the PDB,
// local variable names and control flow are reconstructed.

// ---------------------------------------------------------------------
// operator==  @ 4fc097a1  lines 105-208

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
                            goto LAB_4fc099b9;
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
                                  goto LAB_4fc097c3;
                                }
                                pcVar1 = "MAPINFO MISMATCH: RespawnAtLowAltitude: %d and %d";
                              }
                              else {
                                pcVar1 = "MAPINFO MISMATCH: RestrictAllScrap: %d and %d";
                              }
LAB_4fc099b9:
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
LAB_4fc097c3:
  FormatLogMessage(pcVar1);
  return false;
}


// ---------------------------------------------------------------------
// operator==  @ 4fc09ab1  lines 405-988

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool __cdecl operator==(TeamInfo *a,TeamInfo *b)

{
  int *piVar1;
  int *piVar2;
  bool *pbVar3;
  char (*pacVar4) [64];
  int iVar5;
  int (*paiVar6) [10];
  int iVar7;
  char (*pacVar8) [64];
  char *pcVar9;
  undefined1 auStack_b4 [4];
  int *local_b0;
  float *local_ac;
  char *local_a8;
  int local_a4;
  char (*local_a0) [64];
  int (*local_9c) [10];
  int local_98;
  TeamInfo *local_94;
  char local_8c [64];
  char local_4c [68];
  uint local_8;
  
  local_8 = __security_cookie ^ (uint)auStack_b4;
  iVar7 = a->RealPlayer;
  local_94 = b;
  if (iVar7 == b->RealPlayer) {
    iVar7 = a->Player;
    if (iVar7 == b->Player) {
      iVar7 = a->SatellitePlayer;
      if (iVar7 == b->SatellitePlayer) {
        iVar7 = a->Recycler;
        if (iVar7 == b->Recycler) {
          iVar7 = a->Factory;
          if (iVar7 == b->Factory) {
            iVar7 = a->Armory;
            if (iVar7 == b->Armory) {
              iVar7 = a->Constructor;
              if (iVar7 == b->Constructor) {
                local_a4 = (int)b - (int)a;
                piVar2 = b->BaseSlotScrap;
                iVar7 = 0;
                piVar1 = a->BaseSlot;
                do {
                  local_a8 = (char *)*piVar1;
                  pacVar8 = (char (*) [64])0x0;
                  if (local_a8 != *(char **)(local_a4 + (int)piVar1)) {
                    memset(local_8c,0,0x40);
                    memset(local_4c,0,0x40);
                    GetODFName((int)local_a8,local_8c);
                    GetODFName(b->BaseSlot[iVar7],local_4c);
                    pcVar9 = "TEAMINFO MISMATCH: BaseSlot: %d, %08x \'%s\' and %08x \'%s\'";
                    goto LAB_4fc0ac58;
                  }
                  local_a8 = (char *)piVar1[9];
                  if (local_a8 != (char *)*piVar2) {
                    memset(local_8c,0,0x40);
                    memset(local_4c,0,0x40);
                    GetODFName((int)local_a8,local_8c);
                    GetODFName(b->BaseSlotScrap[iVar7],local_4c);
                    pcVar9 = "TEAMINFO MISMATCH: BaseSlotScrap: %d, %08x \'%s\' and %08x \'%s\'";
                    goto LAB_4fc0ac58;
                  }
                  iVar7 = iVar7 + 1;
                  piVar1 = piVar1 + 1;
                  piVar2 = piVar2 + 1;
                } while (iVar7 < 9);
                iVar7 = a->CommTower;
                if (iVar7 == b->CommTower) {
                  iVar7 = a->SatelliteOn;
                  if (iVar7 == b->SatelliteOn) {
                    iVar7 = a->SatelliteOff;
                    if (iVar7 == b->SatelliteOff) {
                      iVar7 = a->SatelliteLock;
                      if (iVar7 == b->SatelliteLock) {
                        iVar7 = a->SatelliteLastShooter;
                        if (iVar7 == b->SatelliteLastShooter) {
                          iVar7 = a->ImaPilot;
                          if (iVar7 == b->ImaPilot) {
                            iVar7 = a->Transport;
                            if (iVar7 == b->Transport) {
                              piVar2 = a->LimiterObject;
                              pacVar4 = pacVar8;
                              do {
                                local_a8 = (char *)*piVar2;
                                if (local_a8 != *(char **)((int)piVar2 + local_a4)) {
                                  memset(local_8c,0,0x40);
                                  memset(local_4c,0,0x40);
                                  GetODFName((int)local_a8,local_8c);
                                  GetODFName(b->LimiterObject[(int)pacVar4],local_4c);
                                  pcVar9 = 
                                  "TEAMINFO MISMATCH: LimiterObject: %d, %08x \'%s\' and %08x \'%s\'"
                                  ;
LAB_4fc0ac58:
                                  FormatLogMessage(pcVar9);
                                  return false;
                                }
                                pacVar4 = (char (*) [64])(*pacVar4 + 1);
                                piVar2 = piVar2 + 1;
                              } while ((int)pacVar4 < 3);
                              iVar7 = a->LimitPlayer;
                              if (iVar7 == b->LimitPlayer) {
                                if (a->MaxPilots == b->MaxPilots) {
                                  if (a->CurrPilots == b->CurrPilots) {
                                    if (a->m_CPUAIDifficulty == b->m_CPUAIDifficulty) {
                                      if (a->m_CPUPilotCheatAmount == b->m_CPUPilotCheatAmount) {
                                        if (a->m_CPUMaxPatrolUnits == b->m_CPUMaxPatrolUnits) {
                                          if (a->m_CPUMaxHuntUnits == b->m_CPUMaxHuntUnits) {
                                            if (a->m_CPUMaxEscortUnits == b->m_CPUMaxEscortUnits) {
                                              if (a->m_CPUNumPatrolUnits == b->m_CPUNumPatrolUnits)
                                              {
                                                if (a->m_CPUNumHuntUnits == b->m_CPUNumHuntUnits) {
                                                  if (a->m_CPUNumEscortUnits ==
                                                      b->m_CPUNumEscortUnits) {
                                                    if (a->ReinforcementCount ==
                                                        b->ReinforcementCount) {
                                                      if (a->NumBarracks == b->NumBarracks) {
                                                        if (a->NumTeamObjects == b->NumTeamObjects)
                                                        {
                                                          if (a->SatelliteViewActive ==
                                                              b->SatelliteViewActive) {
                                                            if (a->SatelliteOutOfAmmo ==
                                                                b->SatelliteOutOfAmmo) {
                                                              if (a->SatelliteSiteCamAmmo ==
                                                                  b->SatelliteSiteCamAmmo) {
                                                                if (a->SatellitePrevIndependence ==
                                                                    b->SatellitePrevIndependence) {
                                                                  if (a->PlayerLives ==
                                                                      b->PlayerLives) {
                                                                    if (a->RespawnTime ==
                                                                        b->RespawnTime) {
                                                                      if (a->DropoffRecylcers ==
                                                                          b->DropoffRecylcers) {
                                                                        if (a->DropoffExtractors ==
                                                                            b->DropoffExtractors) {
                                                                          if (a->DropoffSilos ==
                                                                              b->DropoffSilos) {
                                                                            if (a->PlayedScrapDropVO
                                                                                == b->
                                                  PlayedScrapDropVO) {
                                                    if (a->TeamIsDead == b->TeamIsDead) {
                                                      if (a->RespawnPlayer == b->RespawnPlayer) {
                                                        if (a->m_UsePilots == b->m_UsePilots) {
                                                          if (a->m_HadPilots == b->m_HadPilots) {
                                                            if (a->m_UseLimits == b->m_UseLimits) {
                                                              if (a->NoPlayerPilot ==
                                                                  b->NoPlayerPilot) {
                                                                if (a->TookControlThisTurn ==
                                                                    b->TookControlThisTurn) {
                                                                  pbVar3 = a->BaseSlotUseScrapHold;
                                                                  pacVar4 = pacVar8;
                                                                  do {
                                                                    if (*pbVar3 != pbVar3[local_a4])
                                                                    {
                                                                      pcVar9 = 
                                                  "TEAMINFO MISMATCH: BaseSlotUseScrapHold:, %d, %d and %d"
                                                  ;
                                                  goto LAB_4fc0aa2d;
                                                  }
                                                  pacVar4 = (char (*) [64])(*pacVar4 + 1);
                                                  pbVar3 = pbVar3 + 1;
                                                  } while ((int)pacVar4 < 9);
                                                  if (a->m_CPUUnitsCanService ==
                                                      b->m_CPUUnitsCanService) {
                                                    if (a->m_CPUDoDispatch == b->m_CPUDoDispatch) {
                                                      if (a->CommTowerAround == b->CommTowerAround)
                                                      {
                                                        if (a->PlayerWasPilot == b->PlayerWasPilot)
                                                        {
                                                          if (a->GiveBackWeapons ==
                                                              b->GiveBackWeapons) {
                                                            if (a->PlayCommTowerSound ==
                                                                b->PlayCommTowerSound) {
                                                              if (a->UseSiteCamera ==
                                                                  b->UseSiteCamera) {
                                                                if (a->SatelliteObjectify ==
                                                                    b->SatelliteObjectify) {
                                                                  if (a->m_CPUDayWreckerChance ==
                                                                      b->m_CPUDayWreckerChance) {
                                                                    if (a->m_CPUDayWreckerInterval
                                                                        == b->
                                                  m_CPUDayWreckerInterval) {
                                                    if (a->m_CPUPilotCheatDelay ==
                                                        b->m_CPUPilotCheatDelay) {
                                                      if (a->m_CPUBuildingRepairChance ==
                                                          b->m_CPUBuildingRepairChance) {
                                                        if (a->m_CPUBuildingRepairInterval ==
                                                            b->m_CPUBuildingRepairInterval) {
                                                          if (a->m_CPUBuildingRepairHealthRatio ==
                                                              b->m_CPUBuildingRepairHealthRatio) {
                                                            if (a->m_CPUBuildPodMinDelay ==
                                                                b->m_CPUBuildPodMinDelay) {
                                                              if (a->m_CPUBuildPodMaxDelay ==
                                                                  b->m_CPUBuildPodMaxDelay) {
                                                                if ((((a->PlayerSpawnPos).x ==
                                                                      (b->PlayerSpawnPos).x) &&
                                                                    ((a->PlayerSpawnPos).y ==
                                                                     (b->PlayerSpawnPos).y)) &&
                                                                   ((a->PlayerSpawnPos).z ==
                                                                    (b->PlayerSpawnPos).z)) {
                                                                  if ((((a->ReinforcementPos).x ==
                                                                        (b->ReinforcementPos).x) &&
                                                                      ((a->ReinforcementPos).y ==
                                                                       (b->ReinforcementPos).y)) &&
                                                                     ((a->ReinforcementPos).z ==
                                                                      (b->ReinforcementPos).z)) {
                                                                    if ((((a->GoalPos).x ==
                                                                          (b->GoalPos).x) &&
                                                                        ((a->GoalPos).y ==
                                                                         (b->GoalPos).y)) &&
                                                                       ((a->GoalPos).z ==
                                                                        (b->GoalPos).z)) {
                                                                      if (a->TeamRace == b->TeamRace
                                                                         ) {
                                                                        local_ac = (float *)b->
                                                  ArmoryBuildClass;
                                                  local_b0 = (int *)a->ArmoryBuildClass;
                                                  iVar7 = _stricmp((char *)local_b0,(char *)local_ac
                                                                  );
                                                  if (iVar7 == 0) {
                                                    local_ac = (float *)b->PlayerName;
                                                    local_b0 = (int *)a->PlayerName;
                                                    iVar7 = _stricmp((char *)local_b0,
                                                                     (char *)local_ac);
                                                    if (iVar7 == 0) {
                                                      local_ac = (float *)b->TeamAIPFile;
                                                      local_b0 = (int *)a->TeamAIPFile;
                                                      iVar7 = _stricmp((char *)local_b0,
                                                                       (char *)local_ac);
                                                      if (iVar7 == 0) {
                                                        pacVar4 = a->PilotWeapon;
                                                        local_a0 = pacVar8;
                                                        do {
                                                          iVar7 = _stricmp(*pacVar4,*pacVar4 +
                                                                                    local_a4);
                                                          if (iVar7 != 0) {
                                                            pcVar9 = 
                                                  "TEAMINFO MISMATCH: PilotWeapon: %d, \'%s\' and \'%s\'"
                                                  ;
                                                  goto LAB_4fc0aa2d;
                                                  }
                                                  pacVar4 = pacVar4 + 1;
                                                  local_a0 = (char (*) [64])(*local_a0 + 1);
                                                  } while ((int)local_a0 < 5);
                                                  local_ac = (float *)b->PlayerPilotODF;
                                                  local_b0 = (int *)a->PlayerPilotODF;
                                                  iVar7 = _stricmp((char *)local_b0,(char *)local_ac
                                                                  );
                                                  if (iVar7 == 0) {
                                                    local_ac = (float *)b->SatelliteODF;
                                                    local_b0 = (int *)a->SatelliteODF;
                                                    iVar7 = _stricmp((char *)local_b0,
                                                                     (char *)local_ac);
                                                    if (iVar7 == 0) {
                                                      local_ac = b->BaseSlotAnimationFrames;
                                                      local_98 = 0x216;
                                                      local_9c = a->BaseSlotPilotCost;
                                                      local_b0 = a->BaseSlotBuildCount;
                                                      local_a0 = a->BaseSlotName;
                                                      do {
                                                        iVar5 = 0;
                                                        local_a8 = *local_a0 + local_a4;
                                                        iVar7 = _stricmp(*local_a0,local_a8);
                                                        paiVar6 = local_9c;
                                                        if (iVar7 != 0) {
                                                          pcVar9 = 
                                                  "TEAMINFO MISMATCH: BaseSlotName%d: \'%s\' and \'%s\'"
                                                  ;
                                                  goto LAB_4fc0aa2d;
                                                  }
                                                  do {
                                                    local_a8 = *(char **)((int)*paiVar6 + local_a4);
                                                    if ((*paiVar6)[0] !=
                                                        *(int *)((int)*paiVar6 + local_a4)) {
                                                      pcVar9 = 
                                                  "TEAMINFO MISMATCH: BaseSlotPilotCost%d_%d: %d and %d"
                                                  ;
                                                  goto LAB_4fc09b25;
                                                  }
                                                  local_a8 = (char *)local_94->BaseSlot
                                                                     [local_98 + iVar5 + -7];
                                                  if ((char *)a->BaseSlot[local_98 + iVar5 + -7] !=
                                                      local_a8) {
                                                    pcVar9 = 
                                                  "TEAMINFO MISMATCH: BaseSlotScrapCost%d_%d: %d and %d"
                                                  ;
                                                  goto LAB_4fc09b25;
                                                  }
                                                  iVar5 = iVar5 + 1;
                                                  paiVar6 = (int (*) [10])(*paiVar6 + 1);
                                                  } while (iVar5 < 10);
                                                  if (a->ShowPilotCosts[(int)pacVar8] !=
                                                      local_94->ShowPilotCosts[(int)pacVar8]) {
                                                    pcVar9 = 
                                                  "TEAMINFO MISMATCH: ShowPilotCosts%d: %d and %d";
LAB_4fc0aa2d:
                                                  FormatLogMessage(pcVar9);
                                                  return false;
                                                  }
                                                  if (*local_b0 !=
                                                      *(int *)((int)local_b0 + local_a4)) {
                                                    pcVar9 = 
                                                  "TEAMINFO MISMATCH: BaseSlotBuildCount: %d and %d"
                                                  ;
                                                  goto LAB_4fc0a096;
                                                  }
                                                  if ((float)local_b0[0x239] != local_ac[-9]) {
                                                    pcVar9 = 
                                                  "TEAMINFO MISMATCH: BaseSlotPlayingAnim: %d and %d"
                                                  ;
                                                  goto LAB_4fc0a096;
                                                  }
                                                  if ((float)local_b0[0x242] != *local_ac) {
                                                    pcVar9 = 
                                                  "TEAMINFO MISMATCH: BaseSlotAnimationFrames: %f and %f"
                                                  ;
                                                  goto LAB_4fc09b25;
                                                  }
                                                  local_b0 = local_b0 + 1;
                                                  local_9c = local_9c + 1;
                                                  local_ac = local_ac + 1;
                                                  local_a0 = local_a0 + 1;
                                                  local_98 = local_98 + 10;
                                                  pacVar8 = (char (*) [64])(*pacVar8 + 1);
                                                  if (0x26f < local_98) {
                                                    return true;
                                                  }
                                                  } while( true );
                                                  }
                                                  pcVar9 = 
                                                  "TEAMINFO MISMATCH: SatelliteODF: \'%s\' and \'%s\'"
                                                  ;
                                                  }
                                                  else {
                                                    pcVar9 = 
                                                  "TEAMINFO MISMATCH: PlayerPilotODF: \'%s\' and \'%s\'"
                                                  ;
                                                  }
                                                  }
                                                  else {
                                                    pcVar9 = 
                                                  "TEAMINFO MISMATCH: TeamAIPFile: \'%s\' and \'%s\'"
                                                  ;
                                                  }
                                                  }
                                                  else {
                                                    pcVar9 = 
                                                  "TEAMINFO MISMATCH: PlayerName: \'%s\' and \'%s\'"
                                                  ;
                                                  }
                                                  }
                                                  else {
                                                    pcVar9 = 
                                                  "TEAMINFO MISMATCH: ArmoryBuildClass: \'%s\' and \'%s\'"
                                                  ;
                                                  }
                                                  }
                                                  else {
                                                    pcVar9 = 
                                                  "TEAMINFO MISMATCH: MaxPilots: %c and %c";
                                                  }
                                                  goto LAB_4fc0a096;
                                                  }
                                                  pcVar9 = 
                                                  "TEAMINFO MISMATCH: GoalPos: %f %f %f and %f %f %f"
                                                  ;
                                                  }
                                                  else {
                                                    pcVar9 = 
                                                  "TEAMINFO MISMATCH: ReinforcementPos: %f %f %f and %f %f %f"
                                                  ;
                                                  }
                                                  }
                                                  else {
                                                    pcVar9 = 
                                                  "TEAMINFO MISMATCH: PlayerSpawnPos: %f %f %f and %f %f %f"
                                                  ;
                                                  }
                                                  FormatLogMessage(pcVar9);
                                                  return false;
                                                  }
                                                  pcVar9 = 
                                                  "TEAMINFO MISMATCH: m_CPUBuildPodMaxDelay: %d and %d"
                                                  ;
                                                  }
                                                  else {
                                                    pcVar9 = 
                                                  "TEAMINFO MISMATCH: m_CPUBuildPodMinDelay: %d and %d"
                                                  ;
                                                  }
                                                  }
                                                  else {
                                                    pcVar9 = 
                                                  "TEAMINFO MISMATCH: m_CPUBuildingRepairHealthRatio: %d and %d"
                                                  ;
                                                  }
                                                  }
                                                  else {
                                                    pcVar9 = 
                                                  "TEAMINFO MISMATCH: m_CPUBuildingRepairInterval: %d and %d"
                                                  ;
                                                  }
                                                  }
                                                  else {
                                                    pcVar9 = 
                                                  "TEAMINFO MISMATCH: m_CPUBuildingRepairChance: %d and %d"
                                                  ;
                                                  }
                                                  }
                                                  else {
                                                    pcVar9 = 
                                                  "TEAMINFO MISMATCH: m_CPUPilotCheatDelay: %d and %d"
                                                  ;
                                                  }
                                                  }
                                                  else {
                                                    pcVar9 = 
                                                  "TEAMINFO MISMATCH: m_CPUDayWreckerInterval: %f and %f"
                                                  ;
                                                  }
                                                  }
                                                  else {
                                                    pcVar9 = 
                                                  "TEAMINFO MISMATCH: m_CPUDayWreckerChance: %f and %f"
                                                  ;
                                                  }
                                                  goto LAB_4fc09b25;
                                                  }
                                                  pcVar9 = 
                                                  "TEAMINFO MISMATCH: SatelliteObjectify: %d and %d"
                                                  ;
                                                  }
                                                  else {
                                                    pcVar9 = 
                                                  "TEAMINFO MISMATCH: UseSiteCamera: %d and %d";
                                                  }
                                                  }
                                                  else {
                                                    pcVar9 = 
                                                  "TEAMINFO MISMATCH: PlayCommTowerSound: %d and %d"
                                                  ;
                                                  }
                                                  }
                                                  else {
                                                    pcVar9 = 
                                                  "TEAMINFO MISMATCH: GiveBackWeapons: %d and %d";
                                                  }
                                                  }
                                                  else {
                                                    pcVar9 = 
                                                  "TEAMINFO MISMATCH: PlayerWasPilot: %d and %d";
                                                  }
                                                  }
                                                  else {
                                                    pcVar9 = 
                                                  "TEAMINFO MISMATCH: CommTowerAround: %d and %d";
                                                  }
                                                  }
                                                  else {
                                                    pcVar9 = 
                                                  "TEAMINFO MISMATCH: m_CPUDoDispatch: %d and %d";
                                                  }
                                                  }
                                                  else {
                                                    pcVar9 = 
                                                  "TEAMINFO MISMATCH: m_CPUUnitsCanService: %d and %d"
                                                  ;
                                                  }
                                                  }
                                                  else {
                                                    pcVar9 = 
                                                  "TEAMINFO MISMATCH: TookControlThisTurn: %d and %d"
                                                  ;
                                                  }
                                                  }
                                                  else {
                                                    pcVar9 = 
                                                  "TEAMINFO MISMATCH: NoPlayerPilot: %d and %d";
                                                  }
                                                  }
                                                  else {
                                                    pcVar9 = 
                                                  "TEAMINFO MISMATCH: m_UseLimits: %d and %d";
                                                  }
                                                  }
                                                  else {
                                                    pcVar9 = 
                                                  "TEAMINFO MISMATCH: m_HadPilots: %d and %d";
                                                  }
                                                  }
                                                  else {
                                                    pcVar9 = 
                                                  "TEAMINFO MISMATCH: m_UsePilots: %d and %d";
                                                  }
                                                  }
                                                  else {
                                                    pcVar9 = 
                                                  "TEAMINFO MISMATCH: RespawnPlayer: %d and %d";
                                                  }
                                                  }
                                                  else {
                                                    pcVar9 = 
                                                  "TEAMINFO MISMATCH: TeamIsDead: %d and %d";
                                                  }
                                                  }
                                                  else {
                                                    pcVar9 = 
                                                  "TEAMINFO MISMATCH: PlayedScrapDropVO: %d and %d";
                                                  }
                                                  }
                                                  else {
                                                    pcVar9 = 
                                                  "TEAMINFO MISMATCH: DropoffSilos: %d and %d";
                                                  }
                                                  }
                                                  else {
                                                    pcVar9 = 
                                                  "TEAMINFO MISMATCH: DropoffExtractors: %d and %d";
                                                  }
                                                  }
                                                  else {
                                                    pcVar9 = 
                                                  "TEAMINFO MISMATCH: DropoffRecylcers: %d and %d";
                                                  }
                                                  }
                                                  else {
                                                    pcVar9 = 
                                                  "TEAMINFO MISMATCH: RespawnTime: %d and %d";
                                                  }
                                                  }
                                                  else {
                                                    pcVar9 = 
                                                  "TEAMINFO MISMATCH: PlayerLives: %d and %d";
                                                  }
                                                  }
                                                  else {
                                                    pcVar9 = 
                                                  "TEAMINFO MISMATCH: SatellitePrevIndependence: %d and %d"
                                                  ;
                                                  }
                                                  }
                                                  else {
                                                    pcVar9 = 
                                                  "TEAMINFO MISMATCH: SatelliteSiteCamAmmo: %d and %d"
                                                  ;
                                                  }
                                                  }
                                                  else {
                                                    pcVar9 = 
                                                  "TEAMINFO MISMATCH: SatelliteOutOfAmmo: %d and %d"
                                                  ;
                                                  }
                                                  }
                                                  else {
                                                    pcVar9 = 
                                                  "TEAMINFO MISMATCH: SatelliteViewActive: %d and %d"
                                                  ;
                                                  }
                                                  }
                                                  else {
                                                    pcVar9 = 
                                                  "TEAMINFO MISMATCH: NumTeamObjects: %d and %d";
                                                  }
                                                  }
                                                  else {
                                                    pcVar9 = 
                                                  "TEAMINFO MISMATCH: NumBarracks: %d and %d";
                                                  }
                                                  }
                                                  else {
                                                    pcVar9 = 
                                                  "TEAMINFO MISMATCH: ReinforcementCount: %d and %d"
                                                  ;
                                                  }
                                                  }
                                                  else {
                                                    pcVar9 = 
                                                  "TEAMINFO MISMATCH: m_CPUNumEscortUnits: %d and %d"
                                                  ;
                                                  }
                                                }
                                                else {
                                                  pcVar9 = 
                                                  "TEAMINFO MISMATCH: m_CPUNumHuntUnits: %d and %d";
                                                }
                                              }
                                              else {
                                                pcVar9 = 
                                                "TEAMINFO MISMATCH: m_CPUNumPatrolUnits: %d and %d";
                                              }
                                            }
                                            else {
                                              pcVar9 = 
                                              "TEAMINFO MISMATCH: m_CPUMaxEscortUnits: %d and %d";
                                            }
                                          }
                                          else {
                                            pcVar9 = 
                                            "TEAMINFO MISMATCH: m_CPUMaxHuntUnits: %d and %d";
                                          }
                                        }
                                        else {
                                          pcVar9 = 
                                          "TEAMINFO MISMATCH: m_CPUMaxPatrolUnits: %d and %d";
                                        }
                                      }
                                      else {
                                        pcVar9 = 
                                        "TEAMINFO MISMATCH: m_CPUPilotCheatAmount: %d and %d";
                                      }
                                    }
                                    else {
                                      pcVar9 = "TEAMINFO MISMATCH: m_CPUAIDifficulty: %d and %d";
                                    }
                                  }
                                  else {
                                    pcVar9 = "TEAMINFO MISMATCH: CurrPilots: %d and %d";
                                  }
                                }
                                else {
                                  pcVar9 = "TEAMINFO MISMATCH: MaxPilots: %d and %d";
                                }
LAB_4fc0a096:
                                FormatLogMessage(pcVar9);
                                return false;
                              }
                              memset(local_8c,0,0x40);
                              memset(local_4c,0,0x40);
                              GetODFName(iVar7,local_8c);
                              GetODFName(b->LimitPlayer,local_4c);
                              pcVar9 = "TEAMINFO MISMATCH: LimitPlayer: %08x \'%s\' and %08x \'%s\'"
                              ;
                            }
                            else {
                              memset(local_8c,0,0x40);
                              memset(local_4c,0,0x40);
                              GetODFName(iVar7,local_8c);
                              GetODFName(b->Transport,local_4c);
                              pcVar9 = "TEAMINFO MISMATCH: Transport: %08x \'%s\' and %08x \'%s\'";
                            }
                          }
                          else {
                            memset(local_8c,0,0x40);
                            memset(local_4c,0,0x40);
                            GetODFName(iVar7,local_8c);
                            GetODFName(b->ImaPilot,local_4c);
                            pcVar9 = "TEAMINFO MISMATCH: ImaPilot: %08x \'%s\' and %08x \'%s\'";
                          }
                        }
                        else {
                          memset(local_8c,0,0x40);
                          memset(local_4c,0,0x40);
                          GetODFName(iVar7,local_8c);
                          GetODFName(b->SatelliteLastShooter,local_4c);
                          pcVar9 = 
                          "TEAMINFO MISMATCH: SatelliteLastShooter: %08x \'%s\' and %08x \'%s\'";
                        }
                      }
                      else {
                        memset(local_8c,0,0x40);
                        memset(local_4c,0,0x40);
                        GetODFName(iVar7,local_8c);
                        GetODFName(b->SatelliteLock,local_4c);
                        pcVar9 = "TEAMINFO MISMATCH: SatelliteLock: %08x \'%s\' and %08x \'%s\'";
                      }
                    }
                    else {
                      memset(local_8c,0,0x40);
                      memset(local_4c,0,0x40);
                      GetODFName(iVar7,local_8c);
                      GetODFName(b->SatelliteOff,local_4c);
                      pcVar9 = "TEAMINFO MISMATCH: SatelliteOff: %08x \'%s\' and %08x \'%s\'";
                    }
                  }
                  else {
                    memset(local_8c,0,0x40);
                    memset(local_4c,0,0x40);
                    GetODFName(iVar7,local_8c);
                    GetODFName(b->SatelliteOn,local_4c);
                    pcVar9 = "TEAMINFO MISMATCH: SatelliteOn: %08x \'%s\' and %08x \'%s\'";
                  }
                }
                else {
                  memset(local_8c,0,0x40);
                  memset(local_4c,0,0x40);
                  GetODFName(iVar7,local_8c);
                  GetODFName(b->CommTower,local_4c);
                  pcVar9 = "TEAMINFO MISMATCH: CommTower: %08x \'%s\' and %08x \'%s\'";
                }
              }
              else {
                memset(local_8c,0,0x40);
                memset(local_4c,0,0x40);
                GetODFName(iVar7,local_8c);
                GetODFName(b->Constructor,local_4c);
                pcVar9 = "TEAMINFO MISMATCH: Constructor: %08x \'%s\' and %08x \'%s\'";
              }
            }
            else {
              memset(local_8c,0,0x40);
              memset(local_4c,0,0x40);
              GetODFName(iVar7,local_8c);
              GetODFName(b->Armory,local_4c);
              pcVar9 = "TEAMINFO MISMATCH: Armory: %08x \'%s\' and %08x \'%s\'";
            }
          }
          else {
            memset(local_8c,0,0x40);
            memset(local_4c,0,0x40);
            GetODFName(iVar7,local_8c);
            GetODFName(b->Factory,local_4c);
            pcVar9 = "TEAMINFO MISMATCH: Factory: %08x \'%s\' and %08x \'%s\'";
          }
        }
        else {
          memset(local_8c,0,0x40);
          memset(local_4c,0,0x40);
          GetODFName(iVar7,local_8c);
          GetODFName(b->Recycler,local_4c);
          pcVar9 = "TEAMINFO MISMATCH: Recycler: %08x \'%s\' and %08x \'%s\'";
        }
      }
      else {
        memset(local_8c,0,0x40);
        memset(local_4c,0,0x40);
        GetODFName(iVar7,local_8c);
        GetODFName(b->SatellitePlayer,local_4c);
        pcVar9 = "TEAMINFO MISMATCH: SatellitePlayer: %08x \'%s\' and %08x \'%s\'";
      }
    }
    else {
      memset(local_8c,0,0x40);
      memset(local_4c,0,0x40);
      GetODFName(iVar7,local_8c);
      GetODFName(b->Player,local_4c);
      pcVar9 = "TEAMINFO MISMATCH: Player: %08x \'%s\' and %08x \'%s\'";
    }
  }
  else {
    memset(local_4c,0,0x40);
    memset(local_8c,0,0x40);
    GetODFName(iVar7,local_4c);
    GetODFName(b->RealPlayer,local_8c);
    pcVar9 = "TEAMINFO MISMATCH: RealPlayer: %08x \'%s\' and %08x \'%s\'";
  }
LAB_4fc09b25:
  FormatLogMessage(pcVar9);
  return false;
}


// ---------------------------------------------------------------------
// operator==  @ 4fc0ac7b  lines 1001-1020

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool __cdecl operator==(AlignTerrainReplaceClass *a,AlignTerrainReplaceClass *b)

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
  char ODFNameA [64];
  char ODFNameB [68];
  uint local_8;
  
  local_8 = __security_cookie ^ (uint)&stack0xfffffffc;
  h = a->AlignHandle;
  if (h == b->AlignHandle) {
    fVar1 = (b->NormalVec).x;
    fVar2 = (a->NormalVec).x;
    if (((fVar2 == fVar1) && ((a->NormalVec).y == (b->NormalVec).y)) &&
       ((a->NormalVec).z == (b->NormalVec).z)) {
      return true;
    }
    dVar3 = (double)(b->NormalVec).z;
    dVar4 = (double)(b->NormalVec).y;
    dVar5 = (double)fVar1;
    dVar6 = (double)(a->NormalVec).z;
    dVar7 = (double)(a->NormalVec).y;
    FormatLogMessage("ALIGNTERRAINREPLACE MISMATCH: NormalVec: %f %f %f and %f %f %f",
                     (double)CONCAT44(SUB84(dVar7,0),(int)((ulonglong)(double)fVar2 >> 0x20)),
                     (double)CONCAT44(SUB84(dVar6,0),(int)((ulonglong)dVar7 >> 0x20)),
                     (double)CONCAT44(SUB84(dVar5,0),(int)((ulonglong)dVar6 >> 0x20)),
                     (double)CONCAT44(SUB84(dVar4,0),(int)((ulonglong)dVar5 >> 0x20)),
                     (double)CONCAT44(SUB84(dVar3,0),(int)((ulonglong)dVar4 >> 0x20)),
                     (double)CONCAT44(unaff_EDI,(int)((ulonglong)dVar3 >> 0x20)));
  }
  else {
    memset(ODFNameA,0,0x40);
    memset(ODFNameB,0,0x40);
    GetODFName(h,ODFNameA);
    GetODFName(b->AlignHandle,ODFNameB);
    FormatLogMessage("ALIGNTERRAINREPLACE MISMATCH: AlignHandle: %08x \'%s\' and %08x \'%s\'",
                     a->AlignHandle,ODFNameA,b->AlignHandle,ODFNameB);
  }
  return false;
}


// ---------------------------------------------------------------------
// operator==  @ 4fc0ad6f  lines 1033-1052

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool __cdecl operator==(DeleteAfterDelayClass *a,DeleteAfterDelayClass *b)

{
  int h;
  char ODFNameA [64];
  char ODFNameB [68];
  uint local_8;
  
  local_8 = __security_cookie ^ (uint)&stack0xfffffffc;
  h = a->DeleteAfterDelayHandle;
  if (h == b->DeleteAfterDelayHandle) {
    if (a->TurnsRemaining == b->TurnsRemaining) {
      return true;
    }
    FormatLogMessage("DELETEAFTERDELAY MISMATCH: TurnsRemaining: %d and %d",a->TurnsRemaining,
                     b->TurnsRemaining);
  }
  else {
    memset(ODFNameA,0,0x40);
    memset(ODFNameB,0,0x40);
    GetODFName(h,ODFNameA);
    GetODFName(b->DeleteAfterDelayHandle,ODFNameB);
    FormatLogMessage("DELETEAFTERDELAYLIST MISMATCH: DeleteAfterDelayHandle: %08x \'%s\' and %08x \'%s\'"
                     ,a->DeleteAfterDelayHandle,ODFNameA,b->DeleteAfterDelayHandle,ODFNameB);
  }
  return false;
}


// ---------------------------------------------------------------------
// operator==  @ 4fc0ae15  lines 1070-1118

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool __cdecl operator==(DeploySoundClass *a,DeploySoundClass *b)

{
  int iVar1;
  char *format;
  char ODFNameA [64];
  char ODFNameB [68];
  uint local_8;
  
  local_8 = __security_cookie ^ (uint)&stack0xfffffffc;
  iVar1 = a->ObjectHandle;
  if (iVar1 == b->ObjectHandle) {
    if (a->DoesLoop == b->DoesLoop) {
      if (a->AudioHandle == b->AudioHandle) {
        if (a->StartDelay == b->StartDelay) {
          if (a->RepeatDelay == b->RepeatDelay) {
            if (a->AudioFileTurns == b->AudioFileTurns) {
              iVar1 = _stricmp(a->DeploySound,b->DeploySound);
              if (iVar1 == 0) {
                return true;
              }
              format = "DEPLOYSOUNDCLASS MISMATCH: DeploySound: \'%s\' and \'%s\'";
            }
            else {
              format = "DEPLOYSOUNDCLASS MISMATCH: AudioFileTurns: %d and %d";
            }
          }
          else {
            format = "DEPLOYSOUNDCLASS MISMATCH: RepeatDelay: %d and %d";
          }
        }
        else {
          format = "DEPLOYSOUNDCLASS MISMATCH: StartDelay: %d and %d";
        }
      }
      else {
        format = "DEPLOYSOUNDCLASS MISMATCH: AudioHandle: %d and %d";
      }
    }
    else {
      format = "DEPLOYSOUNDCLASS MISMATCH: DoesLoop: %d and %d";
    }
    FormatLogMessage(format);
  }
  else {
    memset(ODFNameA,0,0x40);
    memset(ODFNameB,0,0x40);
    GetODFName(iVar1,ODFNameA);
    GetODFName(b->ObjectHandle,ODFNameB);
    FormatLogMessage("DEPLOYSOUNDCLASS MISMATCH: ObjectHandle: %08x \'%s\' and %08x \'%s\'",
                     a->ObjectHandle,ODFNameA,b->ObjectHandle,ODFNameB);
  }
  return false;
}


// ---------------------------------------------------------------------
// operator==  @ 4fc0af2d  lines 1134-1170

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool __cdecl operator==(BuildAtClass *a,BuildAtClass *b)

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
  char *format;
  char ODFNameA [64];
  char ODFNameB [68];
  uint local_8;
  
  local_8 = __security_cookie ^ (uint)&stack0xfffffffc;
  h = a->BuilderHandle;
  if (h == b->BuilderHandle) {
    fVar1 = (b->DropoffPos).x;
    fVar2 = (a->DropoffPos).x;
    if (((fVar2 == fVar1) && ((a->DropoffPos).y == (b->DropoffPos).y)) &&
       ((a->DropoffPos).z == (b->DropoffPos).z)) {
      if (a->BuildTurn == b->BuildTurn) {
        if (a->Priority == b->Priority) {
          if (a->BuilderType == b->BuilderType) {
            return true;
          }
          format = "BUILDATCLASS MISMATCH: BuilderType: %d and %d";
        }
        else {
          format = "BUILDATCLASS MISMATCH: Priority: %d and %d";
        }
      }
      else {
        format = "BUILDATCLASS MISMATCH: BuildTurn: %d and %d";
      }
      FormatLogMessage(format);
    }
    else {
      dVar3 = (double)(b->DropoffPos).z;
      dVar4 = (double)(b->DropoffPos).y;
      dVar5 = (double)fVar1;
      dVar6 = (double)(a->DropoffPos).z;
      dVar7 = (double)(a->DropoffPos).y;
      FormatLogMessage("BUILDATCLASS MISMATCH: DropoffPos: %f %f %f and %f %f %f",
                       (double)CONCAT44(SUB84(dVar7,0),(int)((ulonglong)(double)fVar2 >> 0x20)),
                       (double)CONCAT44(SUB84(dVar6,0),(int)((ulonglong)dVar7 >> 0x20)),
                       (double)CONCAT44(SUB84(dVar5,0),(int)((ulonglong)dVar6 >> 0x20)),
                       (double)CONCAT44(SUB84(dVar4,0),(int)((ulonglong)dVar5 >> 0x20)),
                       (double)CONCAT44(SUB84(dVar3,0),(int)((ulonglong)dVar4 >> 0x20)),
                       (double)CONCAT44(unaff_EDI,(int)((ulonglong)dVar3 >> 0x20)));
    }
  }
  else {
    memset(ODFNameA,0,0x40);
    memset(ODFNameB,0,0x40);
    GetODFName(h,ODFNameA);
    GetODFName(b->BuilderHandle,ODFNameB);
    FormatLogMessage("BUILDATCLASS MISMATCH: BuilderHandle: %08x \'%s\' and %08x \'%s\'",
                     a->BuilderHandle,ODFNameA,b->BuilderHandle,ODFNameB);
  }
  return false;
}


// ---------------------------------------------------------------------
// BZ1Helper::ShouldRemoveDeploySound  @ 4fc0b079  lines 1274-1274

bool __cdecl BZ1Helper::ShouldRemoveDeploySound(DeploySoundClass *entry)

{
  bool bVar1;
  
  bVar1 = IsAround(entry->ObjectHandle);
  if ((!bVar1) || ((bVar1 = false, entry->DoesLoop == false && (entry->StartDelay < 1)))) {
    bVar1 = true;
  }
  return bVar1;
}


// ---------------------------------------------------------------------
// BZ1Helper::ShouldRemoveBuildAt  @ 4fc0b09b  lines 1277-1277

bool __cdecl BZ1Helper::ShouldRemoveBuildAt(BuildAtClass *entry)

{
  bool bVar1;
  
  bVar1 = IsAround(entry->BuilderHandle);
  if ((bVar1) && (m_TurnCounter <= entry->BuildTurn)) {
    return false;
  }
  return true;
}


