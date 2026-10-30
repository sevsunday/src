// Reconstructed by Ghidra from deathmatch01.dll + deathmatch01.pdb
// Original source file: /e:/github/vsr_dll_source/missions/deathmatch01/deathmatch01.cpp
// Functions are ordered by original source line. This is decompiler
// output, not the author's source: names/types come from the PDB,
// local variable names and control flow are reconstructed.


// ---------------------------------------------------------------------
// Deathmatch01::Deathmatch01  @ 4fc42bbd  lines 84-100


/* WARNING: Function: _EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: _EH_epilog3 replaced with injection: EH_epilog3 */

Deathmatch01 * __thiscall Deathmatch01::Deathmatch01(Deathmatch01 *this)

{
  bool *pbVar1;
  
  LuaMission::LuaMission((LuaMission *)this);
  pbVar1 = this->m_AILastWentForPowerup + 0x96;
  this->_padding_ = (int)_vftable_;
  pbVar1[0] = true;
  pbVar1[1] = false;
  pbVar1[2] = false;
  pbVar1[3] = false;
  EnableHighTPS((int *)pbVar1);
  AllowRandomTracks(true);
  this[1]._padding_ = 0x12e;
  this[1]._padding_ = (int)((int)this->m_AICraftHandles + 0x3c1);
  this[1]._padding_ = (int)(this->m_AITargetHandles + 0x3d);
  this[1]._padding_ = (int)(this->m_AITargetHandles + 0x76);
  this[1]._padding_ = (int)(this->m_AILastWentForPowerup + 0x9e);
  this[1]._padding_ = 0x37;
  this[1]._padding_ = 0x240;
  this[1]._padding_ = 0x169;
  return this;
}


// ---------------------------------------------------------------------
// Deathmatch01::~Deathmatch01  @ 4fc42ba7  lines 102-104


void __thiscall Deathmatch01::~Deathmatch01(Deathmatch01 *this)

{
  this->_padding_ = (int)_vftable_;
  CleanupTaunts();
  LuaMission::~LuaMission((LuaMission *)this);
  return;
}


// ---------------------------------------------------------------------
// Deathmatch01::AddObject  @ 4fc42b44  lines 107-139


void __thiscall Deathmatch01::AddObject(Deathmatch01 *this,int param_1)

{
  bool bVar1;
  float fVar2;
  float fVar3;
  
  if (*(int *)(this->m_AILastWentForPowerup + 0x9e) == 0) {
    LuaMission::AddObject((LuaMission *)this,param_1);
  }
  bVar1 = IsPlayer(param_1);
  if (!bVar1) {
    fVar3 = GetRandomFloat(4.0);
    fVar2 = (float)(int)fVar3;
    if ((float)(int)fVar3 == 5.60519e-45) {
      fVar2 = 4.2039e-45;
    }
    fVar3 = this->m_FRIENDLY_SPAWNPOINT_MAX_ALLY;
    if (3 < (int)this->m_FRIENDLY_SPAWNPOINT_MAX_ALLY) {
      fVar3 = fVar2;
    }
    SetSkill(param_1,(int)fVar3);
  }
  return;
}


// ---------------------------------------------------------------------
// Deathmatch01::DeleteObject  @ 4fc42b2e  lines 142-146


void __thiscall Deathmatch01::DeleteObject(Deathmatch01 *this,int param_1)

{
  if (*(int *)(this->m_AILastWentForPowerup + 0x9e) == 0) {
    LuaMission::DeleteObject((LuaMission *)this,param_1);
    return;
  }
  return;
}


// ---------------------------------------------------------------------
// Deathmatch01::GetCanEject  @ 4fc42af0  lines 152-170


bool __thiscall Deathmatch01::GetCanEject(Deathmatch01 *this,int param_1)

{
  int iVar1;
  bool bVar2;
  
  if (((*(char *)((int)this->m_AITargetHandles + 0xeb) == '\0') &&
      (((*(char *)((int)this->m_AICraftHandles + 999) == '\0' || (param_1 != this[1]._padding_)) &&
       (iVar1 = *(int *)(this->m_AILastWentForPowerup + 0xb2), -1 < iVar1)))) &&
     ((iVar1 < 2 || (iVar1 == 3)))) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  return bVar2;
}


// ---------------------------------------------------------------------
// Deathmatch01::GetRespawnInVehicle  @ 4fc42ad3  lines 175-188


bool __thiscall Deathmatch01::GetRespawnInVehicle(Deathmatch01 *this)

{
  if ((*(char *)((int)this->m_AITargetHandles + 0xeb) == '\0') &&
     (1 < *(int *)(this->m_AILastWentForPowerup + 0xb2) - 6U)) {
    return false;
  }
  return true;
}


// ---------------------------------------------------------------------
// Deathmatch01::GetInitialFlagODF  @ 4fc42aa9  lines 193-197


char * __thiscall Deathmatch01::GetInitialFlagODF(Deathmatch01 *this,char param_1)

{
  strcpy_s(TempODFName,0x40,"ioflag01");
  TempODFName[0] = param_1;
  return TempODFName;
}


// ---------------------------------------------------------------------
// Deathmatch01::GetInitialFlagStandODF  @ 4fc42a7f  lines 201-205


char * __thiscall Deathmatch01::GetInitialFlagStandODF(Deathmatch01 *this,char param_1)

{
  strcpy_s(TempODFName,0x40,"iostand01");
  TempODFName[0] = param_1;
  return TempODFName;
}


// ---------------------------------------------------------------------
// Deathmatch01::GetInitialPlayerPilotODF  @ 4fc42a55  lines 210-214


char * __thiscall Deathmatch01::GetInitialPlayerPilotODF(Deathmatch01 *this,char param_1)

{
  strcpy_s(TempODFName,0x40,"isuser");
  TempODFName[0] = param_1;
  return TempODFName;
}


// ---------------------------------------------------------------------
// Deathmatch01::GetNextVehicleODF  @ 4fc42a2b  lines 219-230


char * __thiscall Deathmatch01::GetNextVehicleODF(Deathmatch01 *this,int param_1,bool param_2)

{
  RandomizeType RVar1;
  char *pcVar2;
  
  RVar1 = Randomize_ByRace;
  if (*(int *)(this->m_AILastWentForPowerup + 0xb6) != 1) {
    RVar1 = Randomize_None;
    if (*(int *)(this->m_AILastWentForPowerup + 0xb6) == 2) {
      RVar1 = Randomize_Any;
    }
  }
  pcVar2 = GetPlayerODF(param_1,RVar1);
  return pcVar2;
}


// ---------------------------------------------------------------------
// Deathmatch01::GetNextRandomVehicleODF  @ 4fc42a17  lines 233-235


char * __thiscall Deathmatch01::GetNextRandomVehicleODF(Deathmatch01 *this,int param_1)

{
  char *pcVar1;
  
  pcVar1 = GetPlayerODF(param_1,Randomize_None);
  return pcVar1;
}


// ---------------------------------------------------------------------
// Deathmatch01::GetSpawnpointForTeam  @ 4fc427f8  lines 240-338


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Variable defined which should be unmapped: __return_storage_ptr__ */
/* WARNING: Type propagation algorithm not settling */

Vector * __thiscall
Deathmatch01::GetSpawnpointForTeam(Deathmatch01 *this,Vector *__return_storage_ptr__,int param_1)

{
  float *pfVar1;
  float fVar2;
  int iVar3;
  undefined1 *puVar4;
  Deathmatch01 *pDVar5;
  uint uVar6;
  uint extraout_EAX;
  uint extraout_EAX_00;
  uint extraout_EAX_01;
  uint uVar7;
  uint extraout_ECX;
  int iVar8;
  uint uVar9;
  uint uVar10;
  undefined4 auStackY_40 [2];
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  SpawnpointInfo *local_14;
  undefined1 *local_10;
  Deathmatch01 *local_c;
  undefined4 local_8;
  
  local_8 = (float)(__security_cookie ^ (int)auStackY_40 + 0x3cU);
  local_1c = 0.0;
  local_20 = 0.0;
  local_24 = 0.0;
  auStackY_40[1] = 0x4fc42827;
  local_c = this;
  uVar6 = GetAllSpawnpoints(&local_14,param_1);
  if (uVar6 == 0) {
    local_14 = (SpawnpointInfo *)&local_24;
    goto LAB_4fc42832;
  }
  iVar3 = uVar6 * -4;
  *(uint *)((int)auStackY_40 + iVar3 + 0xcU) = uVar6 * 4;
  uVar10 = 0;
  local_10 = (undefined1 *)((int)auStackY_40 + iVar3 + 0x10U);
  *(undefined4 *)((int)auStackY_40 + iVar3 + 8U) = 0;
  *(int *)((int)auStackY_40 + uVar6 * 0xfffffffc + 4) = (int)auStackY_40 + iVar3 + 0x10U;
  auStackY_40[-uVar6] = 0x4fc4285a;
  memset(*(void **)((int)auStackY_40 + uVar6 * 0xfffffffc + 4),
         *(int *)((int)auStackY_40 + iVar3 + 8U),*(size_t *)((int)auStackY_40 + iVar3 + 0xcU));
  uVar9 = 0;
  uVar7 = 0;
  if (uVar6 == 0) {
LAB_4fc428dc:
    if (uVar6 != 0) {
      uVar7 = uVar10;
      uVar9 = uVar10;
      do {
        fVar2 = (float)local_c->m_AITargetHandles[0x70];
        pfVar1 = (float *)((int)&local_14->m_DistanceToClosestSameTeam + uVar10);
        if (((*pfVar1 <= fVar2 && fVar2 != *pfVar1) ||
            (pfVar1 = (float *)((int)&local_14->m_DistanceToClosestAlly + uVar10),
            *pfVar1 <= fVar2 && fVar2 != *pfVar1)) &&
           ((float)local_c->m_AITargetHandles[0x71] <=
            *(float *)((int)&local_14->m_DistanceToClosestEnemy + uVar10))) {
          *(uint *)(local_10 + uVar9 * 4) = uVar7;
          uVar9 = uVar9 + 1;
        }
        uVar7 = uVar7 + 1;
        uVar10 = uVar10 + 0x24;
      } while (uVar7 < uVar6);
      *(undefined4 *)((int)auStackY_40 + iVar3 + 0xcU) = 0;
      uVar10 = *(uint *)((int)auStackY_40 + iVar3 + 0xcU);
      if (uVar9 != 0) {
        local_c = (Deathmatch01 *)
                  (float)((double)(int)uVar9 +
                         (double)(&__xmm_41f00000000000000000000000000000)[-((int)uVar9 >> 0x1f)]);
        do {
          pDVar5 = local_c;
          *(uint *)((int)auStackY_40 + iVar3 + 0xcU) = uVar7;
          *(Deathmatch01 **)((int)auStackY_40 + iVar3 + 0xcU) = pDVar5;
          *(undefined4 *)((int)auStackY_40 + iVar3 + 8U) = 0x4fc42959;
          local_18 = GetRandomFloat(*(float *)((int)auStackY_40 + iVar3 + 0xcU));
          *(undefined4 *)((int)auStackY_40 + iVar3 + 0xcU) = 0x4fc42967;
          _ftoui3();
          uVar7 = extraout_EAX_00;
          uVar6 = extraout_EAX_00;
        } while (uVar9 <= extraout_EAX_00);
        goto LAB_4fc428cd;
      }
    }
    puVar4 = local_10;
    if (uVar6 == 0) {
LAB_4fc429f2:
      *(int *)((int)auStackY_40 + iVar3 + 0xcU) = param_1;
      *(Vector **)((int)auStackY_40 + iVar3 + 8U) = __return_storage_ptr__;
      *(undefined4 *)((int)auStackY_40 + uVar6 * 0xfffffffc + 4) = 0x4fc429fe;
      GetRandomSpawnpoint(*(Vector **)((int)auStackY_40 + iVar3 + 8U),
                          *(int *)((int)auStackY_40 + iVar3 + 0xcU));
      return __return_storage_ptr__;
    }
    uVar7 = uVar10;
    uVar9 = uVar10;
    do {
      if ((float)local_c->m_AITargetHandles[0x72] <=
          *(float *)((int)&local_14->m_DistanceToClosestEnemy + uVar7)) {
        *(uint *)(local_10 + uVar9 * 4) = uVar10;
        uVar9 = uVar9 + 1;
      }
      uVar10 = uVar10 + 1;
      uVar7 = uVar7 + 0x24;
    } while (uVar10 < uVar6);
    if (uVar9 == 0) goto LAB_4fc429f2;
    local_c = (Deathmatch01 *)
              (float)((double)(int)uVar9 +
                     (double)(&__xmm_41f00000000000000000000000000000)[-((int)uVar9 >> 0x1f)]);
    do {
      pDVar5 = local_c;
      *(uint *)((int)auStackY_40 + iVar3 + 0xcU) = uVar10;
      *(Deathmatch01 **)((int)auStackY_40 + iVar3 + 0xcU) = pDVar5;
      *(undefined4 *)((int)auStackY_40 + iVar3 + 8U) = 0x4fc429d2;
      local_18 = GetRandomFloat(*(float *)((int)auStackY_40 + iVar3 + 0xcU));
      *(undefined4 *)((int)auStackY_40 + iVar3 + 0xcU) = 0x4fc429e0;
      _ftoui3();
      uVar10 = extraout_ECX;
    } while (uVar9 <= extraout_EAX_01);
    iVar3 = *(int *)(puVar4 + extraout_EAX_01 * 4);
  }
  else {
    iVar8 = 0;
    do {
      if (*(int *)((int)&local_14->m_Team + iVar8) == param_1) {
        *(uint *)(local_10 + uVar9 * 4) = uVar7;
        uVar9 = uVar9 + 1;
      }
      uVar7 = uVar7 + 1;
      iVar8 = iVar8 + 0x24;
    } while (uVar7 < uVar6);
    *(undefined4 *)((int)auStackY_40 + iVar3 + 0xcU) = 0;
    uVar10 = *(uint *)((int)auStackY_40 + iVar3 + 0xcU);
    if (uVar9 == 0) goto LAB_4fc428dc;
    local_18 = (float)((double)(int)uVar9 +
                      (double)(&__xmm_41f00000000000000000000000000000)[-((int)uVar9 >> 0x1f)]);
    do {
      fVar2 = local_18;
      *(uint *)((int)auStackY_40 + iVar3 + 0xcU) = uVar7;
      *(float *)((int)auStackY_40 + iVar3 + 0xcU) = fVar2;
      *(undefined4 *)((int)auStackY_40 + iVar3 + 8U) = 0x4fc428b4;
      local_c = (Deathmatch01 *)GetRandomFloat(*(float *)((int)auStackY_40 + iVar3 + 0xcU));
      *(undefined4 *)((int)auStackY_40 + iVar3 + 0xcU) = 0x4fc428c2;
      _ftoui3();
      uVar6 = extraout_EAX;
      uVar7 = extraout_EAX;
    } while (uVar9 <= extraout_EAX);
LAB_4fc428cd:
    iVar3 = *(int *)(local_10 + uVar6 * 4);
  }
  local_14 = local_14 + iVar3;
LAB_4fc42832:
  __return_storage_ptr__->x = (local_14->m_Position).x;
  __return_storage_ptr__->y = (local_14->m_Position).y;
  __return_storage_ptr__->z = (local_14->m_Position).z;
  return __return_storage_ptr__;
}


// ---------------------------------------------------------------------
// Deathmatch01::SetupTeam  @ 4fc42418  lines 352-493


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall Deathmatch01::SetupTeam(Deathmatch01 *this,int param_1)

{
  byte bVar1;
  Vector VVar2;
  float fVar3;
  bool bVar4;
  char cVar5;
  int iVar6;
  Vector *pVVar7;
  byte *pbVar8;
  uint uVar9;
  char *pcVar10;
  int iVar11;
  byte *pbVar12;
  Deathmatch01 *this_00;
  float fVar13;
  Deathmatch01 *pDVar14;
  undefined4 uVar15;
  Deathmatch01 *this_01;
  char **local_bc;
  float local_b8;
  float local_b4;
  float local_b0;
  Vector local_ac;
  int local_a0;
  Deathmatch01 *local_9c;
  int local_98;
  undefined4 local_94;
  int local_90;
  int *local_8c;
  char local_88 [64];
  byte local_48 [64];
  undefined4 local_8;
  
  local_8 = __security_cookie ^ (uint)(local_48 + 0x44);
  if (((uint)param_1 < 0x10) &&
     ((local_9c = this, bVar4 = IsTeamplayOn(), !bVar4 ||
      (*(char *)((int)this->m_AICraftHandles + param_1 + 0x3d4) == '\0')))) {
    cVar5 = GetRaceOfTeam(param_1);
    local_94 = CONCAT31(local_94._1_3_,cVar5);
    bVar4 = IsTeamplayOn();
    if (bVar4) {
      uVar15 = local_94;
      iVar6 = WhichTeamGroup(param_1);
      SetMPTeamRace(iVar6,(char)uVar15);
    }
    if (DMIsRaceSubtype[*(int *)(this->m_AILastWentForPowerup + 0xb2)] == false) {
      pVVar7 = GetSpawnpointForTeam(this,&local_ac,param_1);
      pVVar7 = GetPositionNear(&local_ac,*pVVar7,10.0,30.0);
    }
    else {
      pVVar7 = GetSpawnpoint(&local_ac,0);
    }
    pDVar14 = local_9c;
    local_b8 = pVVar7->x;
    local_b4 = pVVar7->y;
    local_b0 = pVVar7->z;
    local_9c->m_AITargetHandles[param_1 * 3 + 0x3d] = (int)local_b8;
    local_9c->m_AITargetHandles[param_1 * 3 + 0x3e] = (int)local_b4;
    local_9c->m_AITargetHandles[param_1 * 3 + 0x3f] = (int)local_b0;
    if (*(int *)(local_9c->m_AILastWentForPowerup + 0xb2) == 2) {
      sprintf_s<64>((char (*) [64])local_48,"base%d");
      sprintf_s<64>(&local_88,"m_base%d");
      GetAiPaths(&local_90,&local_bc);
      local_a0 = 0;
      if (0 < local_90) {
        do {
          local_8c = (int *)local_bc[local_a0];
          pbVar12 = local_48;
          pbVar8 = (byte *)local_8c;
          do {
            bVar1 = *pbVar8;
            bVar4 = bVar1 < *pbVar12;
            if (bVar1 != *pbVar12) {
LAB_4fc425c0:
              uVar9 = -(uint)bVar4 | 1;
              goto LAB_4fc425c5;
            }
            if (bVar1 == 0) break;
            bVar1 = pbVar8[1];
            bVar4 = bVar1 < pbVar12[1];
            if (bVar1 != pbVar12[1]) goto LAB_4fc425c0;
            pbVar8 = pbVar8 + 2;
            pbVar12 = pbVar12 + 2;
          } while (bVar1 != 0);
          uVar9 = 0;
LAB_4fc425c5:
          if (uVar9 == 0) {
            this_01 = (Deathmatch01 *)local_88;
            local_98 = GetHandle((char *)this_01);
            if (local_98 == 0) {
              iVar6 = param_1;
              pbVar12 = (byte *)local_8c;
              pcVar10 = GetInitialFlagStandODF(this_01,(char)local_94);
              local_98 = BuildObject(pcVar10,iVar6,(char *)pbVar12);
            }
            SetAnimation(local_98,"loop",0);
            if (local_98 == 0) {
              iVar6 = param_1;
              pbVar12 = (byte *)local_8c;
              pcVar10 = GetInitialFlagODF(this_00,(char)local_94);
              local_8c = (int *)BuildObject(pcVar10,iVar6,(char *)pbVar12);
            }
            else {
              iVar6 = param_1;
              iVar11 = local_98;
              pcVar10 = GetInitialFlagODF(this_00,(char)local_94);
              local_8c = (int *)BuildObject(pcVar10,iVar6,iVar11);
            }
            SetAnimation((int)local_8c,"loop",0);
            if (param_1 == 1) {
              pDVar14->m_AITargetHandles[0x7a] = local_98;
              pDVar14->m_AITargetHandles[0x76] = (int)local_8c;
            }
            else if (param_1 == 6) {
              pDVar14->m_AITargetHandles[0x7b] = local_98;
              pDVar14->m_AITargetHandles[0x77] = (int)local_8c;
            }
          }
          local_a0 = local_a0 + 1;
        } while (local_a0 < local_90);
      }
    }
    else if ((DMIsRaceSubtype[*(int *)(local_9c->m_AILastWentForPowerup + 0xb2)] != false) &&
            (*(char *)((int)local_9c->m_AICraftHandles + 0x3e5) == '\0')) {
      fVar3 = 0.0;
      do {
        fVar13 = fVar3;
        sprintf_s<64>(&TempODFName,"checkpoint%d");
        iVar6 = GetHandle(TempODFName);
        fVar3 = (float)((int)fVar13 + 1);
      } while (iVar6 != 0);
      local_9c->m_TeamPos[0x1f] = fVar13;
      *(undefined1 *)((int)local_9c->m_AICraftHandles + 0x3e5) = 1;
      pDVar14 = local_9c;
    }
    bVar4 = IsTeamplayOn();
    if (bVar4) {
      iVar6 = GetFirstAlliedTeam(param_1);
      local_90 = iVar6;
      iVar11 = GetLastAlliedTeam(param_1);
      if (iVar6 <= iVar11) {
        local_8c = pDVar14->m_AITargetHandles + iVar6 * 3 + 0x3e;
        do {
          if (iVar6 != param_1) {
            VVar2.y = local_b4;
            VVar2.x = local_b8;
            VVar2.z = local_b0;
            GetPositionNear(&local_ac,VVar2,10.0,30.0);
            local_8c[-1] = (int)local_ac.x;
            *local_8c = (int)local_ac.y;
            local_8c[1] = (int)local_ac.z;
            iVar6 = local_90;
          }
          local_8c = local_8c + 3;
          iVar6 = iVar6 + 1;
          local_90 = iVar6;
          iVar11 = GetLastAlliedTeam(param_1);
        } while (iVar6 <= iVar11);
        pDVar14 = local_9c;
      }
    }
    *(undefined1 *)((int)pDVar14->m_AICraftHandles + param_1 + 0x3d4) = 1;
  }
  return;
}


// ---------------------------------------------------------------------
// Deathmatch01::FindGoodAITarget  @ 4fc42109  lines 498-671


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall Deathmatch01::FindGoodAITarget(Deathmatch01 *this,int param_1)

{
  int *piVar1;
  bool bVar2;
  int iVar3;
  float fVar4;
  int iVar5;
  float local_20;
  float local_1c;
  int *local_18;
  int *local_14;
  float local_10;
  int *local_c;
  int *local_8;
  
  iVar3 = param_1;
  piVar1 = this->m_AITargetHandles + param_1 + 0x9c;
  bVar2 = IsAliveAndPilot2(*piVar1);
  if (!bVar2) {
    *piVar1 = 0;
    return;
  }
  if ((*(char *)((int)this->m_AICraftHandles + 999) != '\0') && (*piVar1 != this[1]._padding_)) {
    param_1 = this[1]._padding_;
    bVar2 = IsAlive(&param_1);
    if (!bVar2) {
      return;
    }
    Attack(*piVar1,this[1]._padding_,1);
    return;
  }
  local_10 = (float)(*misnImport.GetNearestEnemy)(*piVar1);
  iVar5 = 1;
  do {
    local_1c = (float)GetPlayerHandle(iVar5);
    if ((local_10 == local_1c) && (bVar2 = IsAliveAndPilot((int *)&local_1c), bVar2)) {
      local_10 = 0.0;
    }
    iVar5 = iVar5 + 1;
  } while (iVar5 < 0x10);
  piVar1 = this->m_AITargetHandles + iVar3 + 0x9c;
  if (local_10 != 0.0) {
    if (*(char *)((int)this->m_AICraftHandles + iVar3 + 0x3ea) == '\0') {
      local_c = (int *)GetNearestPerson(*piVar1,true,100.0);
      local_18 = (int *)(*misnImport.GetDistanceObject)(piVar1,(int *)&local_10);
      local_14 = (int *)((float)local_18 * ___real_3f99999a);
      if ((local_c != (int *)0x0) &&
         (local_1c = (*misnImport.GetDistanceObject)(piVar1,(int *)&local_c),
         local_1c < (float)local_14)) {
        Goto(*piVar1,(int)local_c,1);
LAB_4fc42240:
        *(undefined1 *)((int)this->m_AICraftHandles + iVar3 + 0x3ea) = 1;
        this->m_EmptyVehicles[iVar3 + 9] = 0;
        this[1].m_SpawnedAtTime[iVar3 + -0x270b] = (int)local_c;
        return;
      }
      local_8 = (int *)GetNearestPowerup(*piVar1,true,100.0);
      if ((local_8 != (int *)0x0) &&
         (local_1c = (*misnImport.GetDistanceObject)(piVar1,(int *)&local_8),
         local_1c < (float)local_14)) {
        Goto(*piVar1,(int)local_8,1);
        local_c = local_8;
        goto LAB_4fc42240;
      }
    }
    if (local_10 != 0.0) goto LAB_4fc423f0;
  }
  local_14 = __real_501502f9;
  local_1c = 0.0;
  if ((*(char *)((int)this->m_AICraftHandles + 0x3e6) == '\0') &&
     (local_c = (int *)0x0, 0 < (int)this->m_FRIENDLY_SPAWNPOINT_MIN_ENEMY)) {
    local_8 = this->m_AITargetHandles + 0x9c;
    do {
      if ((local_c != (int *)iVar3) && (*piVar1 != 0)) {
        local_18 = (int *)*local_8;
        bVar2 = IsAlive((int *)&local_18);
        if ((bVar2) && (bVar2 = IsAlly(*piVar1,*local_8), !bVar2)) {
          local_18 = (int *)*local_8;
          local_20 = (float)*piVar1;
          local_18 = (int *)(*misnImport.GetDistanceObject)((int *)&local_20,(int *)&local_18);
          if ((___real_3c23d70a < (float)local_18) && ((float)local_18 < (float)local_14)) {
            local_1c = (float)*local_8;
            local_14 = local_18;
          }
        }
      }
      local_c = (int *)((int)local_c + 1);
      local_8 = local_8 + 1;
    } while ((int)local_c < (int)this->m_FRIENDLY_SPAWNPOINT_MIN_ENEMY);
  }
  iVar3 = 1;
  fVar4 = local_1c;
  do {
    local_1c = (float)GetPlayerHandle(iVar3);
    if (local_1c != 0.0) {
      local_20 = local_1c;
      bVar2 = IsAliveAndPilot((int *)&local_20);
      if (!bVar2) {
        local_18 = (int *)*piVar1;
        local_c = (int *)(*misnImport.GetDistanceObject)((int *)&local_18,(int *)&local_1c);
        if (___real_3c23d70a < (float)local_c) {
          if ((float)local_c < (float)local_14) {
            fVar4 = local_1c;
            local_14 = local_c;
          }
        }
      }
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0x10);
  if (fVar4 != 0.0) {
    local_10 = fVar4;
  }
  iVar3 = param_1;
LAB_4fc423f0:
  this[1].m_SpawnedAtTime[iVar3 + -0x270b] = (int)local_10;
  if (local_10 != 0.0) {
    Attack(*piVar1,(int)local_10,1);
  }
  *(undefined1 *)((int)this->m_AICraftHandles + iVar3 + 0x3ea) = 0;
  return;
}


// ---------------------------------------------------------------------
// Deathmatch01::BuildBotCraft  @ 4fc41fff  lines 675-725


void __thiscall Deathmatch01::BuildBotCraft(Deathmatch01 *this,int param_1)

{
  Vector VVar1;
  Deathmatch01 *this_00;
  int iVar2;
  Vector *pVVar3;
  char *pcVar4;
  int iVar5;
  int iVar6;
  float fVar7;
  int iVar8;
  Vector local_24;
  Vector local_18;
  int local_c;
  Deathmatch01 *local_8;
  
  if (*(char *)((int)this->m_AICraftHandles + 999) == '\0') {
    if (*(char *)((int)this->m_AICraftHandles + 0x3e6) == '\0') {
      iVar8 = param_1 % 5 + 0xb;
    }
    else {
      iVar8 = 0xf;
    }
  }
  else {
    iVar8 = 0xe;
  }
  iVar6 = 1;
  iVar5 = 0;
  local_8 = this;
  do {
    if (*(char *)((int)this->m_AICraftHandles + iVar5 + 0x3d4) != '\0') {
      iVar2 = GetPlayerHandle(iVar5);
      this = local_8;
      if (iVar2 != 0) {
        iVar6 = iVar5;
      }
    }
    iVar5 = iVar5 + 1;
  } while (iVar5 < 0x10);
  local_c = iVar6;
  GetRandomSpawnpoint(&local_18,iVar8);
  VVar1.y = local_18.y;
  VVar1.x = local_18.x;
  VVar1.z = local_18.z;
  pVVar3 = GetPositionNear(&local_24,VVar1,30.0,100.0);
  local_18.x = pVVar3->x;
  local_18.y = pVVar3->y;
  local_18.z = pVVar3->z;
  fVar7 = GetRandomFloat(4.0);
  local_18.y = fVar7 + __real_40000000 + local_18.y;
  pcVar4 = GetPlayerODF(local_c,Randomize_Any);
  iVar8 = BuildObject(pcVar4,iVar8,&local_18);
  this_00 = local_8;
  local_8->m_AITargetHandles[param_1 + 0x9c] = iVar8;
  SetRandomHeadingAngle(iVar8);
  SetNoScrapFlagByHandle(this_00->m_AITargetHandles[param_1 + 0x9c]);
  AddPilotByHandle(this_00->m_AITargetHandles[param_1 + 0x9c]);
  FindGoodAITarget(this_00,param_1);
  return;
}


// ---------------------------------------------------------------------
// Deathmatch01::SetupAnimal  @ 4fc41f31  lines 729-755


void __thiscall Deathmatch01::SetupAnimal(Deathmatch01 *this,int param_1)

{
  Vector VVar1;
  Deathmatch01 *pDVar2;
  Vector *pVVar3;
  int iVar4;
  float fVar5;
  Vector local_24;
  Vector local_18;
  Deathmatch01 *local_c;
  float local_8;
  
  local_c = this;
  local_8 = GetRandomFloat(6.0);
  iVar4 = (int)local_8 + 8;
  if ((*(char *)((int)this->m_AICraftHandles + 0x3e6) != '\0') ||
     (*(char *)((int)this->m_AICraftHandles + 999) != '\0')) {
    iVar4 = 0xd;
  }
  GetRandomSpawnpoint(&local_18,-1);
  VVar1.y = local_18.y;
  VVar1.x = local_18.x;
  VVar1.z = local_18.z;
  pVVar3 = GetPositionNear(&local_24,VVar1,10.0,30.0);
  local_18.x = pVVar3->x;
  local_18.y = pVVar3->y;
  local_18.z = pVVar3->z;
  fVar5 = GetRandomFloat(4.0);
  pDVar2 = local_c;
  local_18.y = fVar5 + __real_40000000 + local_18.y;
  iVar4 = BuildObject((char *)&local_c->h_first,iVar4,&local_18);
  pDVar2[1].m_SpawnedAtTime[param_1 + -0x25fb] = iVar4;
  SetRandomHeadingAngle(iVar4);
  SetNoScrapFlagByHandle(pDVar2[1].m_SpawnedAtTime[param_1 + -0x25fb]);
  return;
}


// ---------------------------------------------------------------------
// Deathmatch01::ObjectifyFlag  @ 4fc41e81  lines 760-783


void __thiscall Deathmatch01::ObjectifyFlag(Deathmatch01 *this)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  
  iVar2 = GetPlayerHandle();
  if (iVar2 != 0) {
    iVar2 = GetTeamNum(iVar2);
    iVar2 = WhichTeamGroup(iVar2);
    bVar1 = IsTeamplayOn();
    if ((bVar1) && (-1 < iVar2)) {
      if (iVar2 == 0) {
        iVar2 = this->m_AITargetHandles[0x76];
        iVar3 = this->m_AITargetHandles[0x77];
      }
      else {
        iVar2 = this->m_AITargetHandles[0x77];
        iVar3 = this->m_AITargetHandles[0x76];
      }
      SetObjectiveOff(iVar2);
      SetObjectiveOn(iVar2);
      pcVar4 = GetBZCCLocalizedString("cfg","Defend Flag!");
      SetObjectiveName(iVar2,pcVar4);
      SetObjectiveOff(iVar3);
      SetObjectiveOn(iVar3);
      pcVar4 = GetBZCCLocalizedString("cfg","Capture Flag!");
      SetObjectiveName(iVar3,pcVar4);
    }
  }
  return;
}


// ---------------------------------------------------------------------
// Deathmatch01::ObjectifyRabbit  @ 4fc41e32  lines 788-802


void __thiscall Deathmatch01::ObjectifyRabbit(Deathmatch01 *this)

{
  int iVar1;
  char *pcVar2;
  
  iVar1 = GetPlayerHandle();
  if (iVar1 == this[1]._padding_) {
                    /* WARNING: Could not recover jumptable at 0x4fc41e46. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    ClearObjectives();
    return;
  }
  SetObjectiveOff(this[1]._padding_);
  SetObjectiveOn(this[1]._padding_);
  pcVar2 = GetBZCCLocalizedString("cfg","Wabbit!");
  SetObjectiveName(this[1]._padding_,pcVar2);
  return;
}


// ---------------------------------------------------------------------
// Deathmatch01::SetNewRabbit  @ 4fc41d42  lines 807-886


void __thiscall Deathmatch01::SetNewRabbit(Deathmatch01 *this,int param_1)

{
  bool bVar1;
  char *pcVar2;
  int iVar3;
  int *local_8;
  
  bVar1 = IsAround(param_1);
  if (bVar1) {
    iVar3 = this[1]._padding_;
    this->m_AICraftHandles[0xec] = 0;
    SetObjectiveOff(iVar3);
    this[1]._padding_ = param_1;
    this[1]._padding_ = 0;
    bVar1 = IsPlayer(param_1);
    if (bVar1) {
      *(undefined1 *)(this->m_AICraftHandles + 0xfa) = 1;
      iVar3 = GetTeamNum(param_1);
      this->m_AICraftHandles[0xe9] = iVar3;
    }
    else {
      *(undefined1 *)(this->m_AICraftHandles + 0xfa) = 0;
      this->m_AICraftHandles[0xe9] = 0;
      SetTeamNum(param_1,0xf);
    }
    iVar3 = 1;
    do {
      GetPlayerHandle(iVar3);
      iVar3 = iVar3 + 1;
    } while (iVar3 < 0x10);
    iVar3 = 0;
    if (0 < (int)this->m_FRIENDLY_SPAWNPOINT_MIN_ENEMY) {
      local_8 = this->m_AITargetHandles + 0x9c;
      do {
        if (*local_8 != param_1) {
          FindGoodAITarget(this,iVar3);
        }
        iVar3 = iVar3 + 1;
        local_8 = local_8 + 1;
      } while (iVar3 < (int)this->m_FRIENDLY_SPAWNPOINT_MIN_ENEMY);
    }
    iVar3 = GetPlayerHandle();
    if (iVar3 == this[1]._padding_) {
      pcVar2 = GetBZCCLocalizedString("mission","It\'s wabbit hunting season. Do you feel lucky?");
      AddToMessagesBox(pcVar2);
    }
    else {
      ObjectifyRabbit(this);
    }
  }
  return;
}


// ---------------------------------------------------------------------
// Deathmatch01::SetupPlayer  @ 4fc41b0f  lines 890-971


int __thiscall Deathmatch01::SetupPlayer(Deathmatch01 *this,int param_1)

{
  bool bVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  Vector *pVVar5;
  char *pcVar6;
  Deathmatch01 *pDVar7;
  Deathmatch01 *this_00;
  Vector local_20;
  Vector local_14;
  Deathmatch01 *local_8;
  
  local_14.x = 0.0;
  local_14.y = 0.0;
  local_14.z = 0.0;
  if ((uint)param_1 < 0x10) {
    this->m_TeamPos[param_1 + -0x13] = *(float *)(this->m_AILastWentForPowerup + 0xa6);
    local_8 = this;
    iVar3 = WhichTeamGroup(param_1);
    bVar1 = IsTeamplayOn();
    if ((!bVar1) || (iVar3 < 0)) {
      if (DMIsRaceSubtype[*(int *)(this->m_AILastWentForPowerup + 0xb2)] == false) {
        pVVar5 = GetRandomSpawnpoint(&local_20,-1);
      }
      else {
        pVVar5 = GetSpawnpoint(&local_20,0);
      }
      local_14.x = pVVar5->x;
      local_14.y = pVVar5->y;
      local_14.z = pVVar5->z;
      pVVar5 = GetPositionNear(&local_20,*pVVar5,10.0,30.0);
      this = local_8;
      local_14.x = pVVar5->x;
      local_14.z = pVVar5->z;
      local_14.y = pVVar5->y + __real_3f800000;
      SetupTeam(local_8,param_1);
    }
    else {
      iVar4 = GetCommanderTeam(param_1);
      SetupTeam(this,iVar4);
      local_14.x = (float)this->m_AITargetHandles[param_1 * 3 + 0x3d];
      local_14.z = (float)this->m_AITargetHandles[param_1 * 3 + 0x3f];
      local_14.y = TerrainFindFloor(local_14.x,local_14.z);
      local_14.y = local_14.y + __real_3f800000;
    }
    if (DMIsRaceSubtype[*(int *)(this->m_AILastWentForPowerup + 0xb2)] != false) {
      pVVar5 = GetSpawnpoint(&local_20,0);
      pVVar5 = GetPositionNear(&local_20,*pVVar5,10.0,30.0);
      RaceSetObjective = false;
      local_14.x = pVVar5->x;
      local_14.z = pVVar5->z;
      local_14.y = pVVar5->y + __real_3f800000;
      local_8->m_TeamPos[param_1 + -1] = 1.4013e-45;
      local_8->m_TeamPos[param_1 + 0xf] = 0.0;
      local_8->m_TeamPos[param_1 + 0x20] = 0.0;
      local_8->m_TeamPos[0x32] = 0.0;
      this = local_8;
    }
    pVVar5 = &local_14;
    iVar4 = param_1;
    pcVar6 = GetPlayerODF(param_1,Randomize_None);
    pDVar7 = (Deathmatch01 *)BuildObject(pcVar6,iVar4,pVVar5);
    if (DMIsRaceSubtype[*(int *)(this->m_AILastWentForPowerup + 0xb2)] == false) {
      SetRandomHeadingAngle((int)pDVar7);
    }
    this_00 = pDVar7;
    SetNoScrapFlagByHandle((int)pDVar7);
    cVar2 = GetRaceOfTeam(param_1);
    pcVar6 = GetInitialPlayerPilotODF(this_00,cVar2);
    SetPilotClass((int)pDVar7,pcVar6);
    if (param_1 == 0) {
      MakeInert((int)pDVar7);
    }
    bVar1 = IsTeamplayOn();
    if ((bVar1) && (-1 < iVar3)) {
      iVar3 = GetCommanderTeam(param_1);
      SetupTeam(this,7 - iVar3);
    }
  }
  else {
    pDVar7 = (Deathmatch01 *)0x0;
  }
  return (int)pDVar7;
}


// ---------------------------------------------------------------------
// Deathmatch01::InitialSetup  @ 4fc41af5  lines 974-980


void __thiscall Deathmatch01::InitialSetup(Deathmatch01 *this)

{
  LuaMission::InitialSetup((LuaMission *)this);
  *(undefined2 *)((int)this->m_AICraftHandles + 0x3c1) = 0x100;
  *(undefined1 *)(this->m_AICraftHandles + 0xf9) = 0;
  return;
}


// ---------------------------------------------------------------------
// Deathmatch01::CrunchEmptyVehicleList  @ 4fc41aa5  lines 985-1013


void __thiscall Deathmatch01::CrunchEmptyVehicleList(Deathmatch01 *this)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  
  iVar1 = 0;
  iVar4 = 0x20;
  piVar2 = this->m_AITargetHandles + 0x7c;
  piVar3 = piVar2;
  do {
    if (*piVar3 != 0) {
      *piVar2 = *piVar3;
      iVar1 = iVar1 + 1;
      piVar2 = piVar2 + 1;
    }
    piVar3 = piVar3 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  *(int *)(this->m_AILastWentForPowerup + 0xba) = iVar1;
  if (iVar1 < 0x20) {
    piVar2 = this->m_AITargetHandles + iVar1 + 0x7c;
    for (iVar4 = 0x20 - iVar1; iVar4 != 0; iVar4 = iVar4 + -1) {
      *piVar2 = 0;
      piVar2 = piVar2 + 1;
    }
  }
  return;
}


// ---------------------------------------------------------------------
// Deathmatch01::UpdateEmptyVehicles  @ 4fc419e7  lines 1019-1076


void __thiscall Deathmatch01::UpdateEmptyVehicles(Deathmatch01 *this)

{
  int iVar1;
  char cVar2;
  bool bVar3;
  int iVar4;
  int *piVar5;
  int local_c;
  char local_5;
  
  if (*(int *)(this->m_AILastWentForPowerup + 0xba) != 0) {
    cVar2 = '\0';
    piVar5 = this->m_AITargetHandles + 0x7c;
    local_5 = '\0';
    iVar4 = 0x20;
    do {
      iVar1 = *piVar5;
      if (iVar1 != 0) {
        local_c = iVar1;
        bVar3 = IsAround(iVar1);
        if (bVar3) {
          bVar3 = IsPlayer(*piVar5);
          if (!bVar3) {
            bVar3 = IsAliveAndPilot(&local_c);
            if (!bVar3) {
              cVar2 = local_5;
              goto LAB_4fc41a4e;
            }
          }
        }
        *piVar5 = 0;
        local_5 = '\x01';
        cVar2 = '\x01';
      }
LAB_4fc41a4e:
      piVar5 = piVar5 + 1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    if (cVar2 != '\0') {
      CrunchEmptyVehicleList(this);
    }
    iVar4 = CountPlayers();
    if (iVar4 + 1 + (iVar4 >> 1) < *(int *)(this->m_AILastWentForPowerup + 0xba)) {
      SelfDamage(this->m_AITargetHandles[0x7c],1e+20);
      this->m_AITargetHandles[0x7c] = 0;
      CrunchEmptyVehicleList(this);
    }
  }
  return;
}


// ---------------------------------------------------------------------
// Deathmatch01::AddEmptyVehicle  @ 4fc41984  lines 1081-1109


void __thiscall Deathmatch01::AddEmptyVehicle(Deathmatch01 *this,int param_1)

{
  if (param_1 != 0) {
    if (0x1f < *(int *)(this->m_AILastWentForPowerup + 0xba)) {
      UpdateEmptyVehicles(this);
      if (this->m_AITargetHandles[0x7c] != 0) {
        SelfDamage(this->m_AITargetHandles[0x7c],1e+20);
        this->m_AITargetHandles[0x7c] = 0;
        CrunchEmptyVehicleList(this);
      }
    }
    if (*(int *)(this->m_AILastWentForPowerup + 0xba) < 0x20) {
      this->m_AITargetHandles[*(int *)(this->m_AILastWentForPowerup + 0xba) + 0x7c] = param_1;
      *(int *)(this->m_AILastWentForPowerup + 0xba) =
           *(int *)(this->m_AILastWentForPowerup + 0xba) + 1;
    }
  }
  return;
}


// ---------------------------------------------------------------------
// Deathmatch01::Init  @ 4fc414f2  lines 1113-1285


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall Deathmatch01::Init(Deathmatch01 *this)

{
  char cVar1;
  bool bVar2;
  char *pcVar3;
  int iVar4;
  uint uVar5;
  float fVar6;
  char *pcVar7;
  NETWORK_LIST_TYPE unaff_ESI;
  code *pcVar8;
  uint unaff_EDI;
  int iVar9;
  char local_88 [64];
  char local_48 [64];
  undefined4 local_8;
  
  local_8 = __security_cookie ^ (uint)(local_48 + 0x44);
  if ((void *)this[1]._padding_ != (void *)0x0) {
    memset((void *)this[1]._padding_,0,this[1]._padding_ << 2);
  }
  if ((void *)this[1]._padding_ != (void *)0x0) {
    memset((void *)this[1]._padding_,0,this[1]._padding_ << 2);
  }
  if ((void *)this[1]._padding_ != (void *)0x0) {
    memset((void *)this[1]._padding_,0,this[1]._padding_ << 2);
  }
  if ((void *)this[1]._padding_ != (void *)0x0) {
    memset((void *)this[1]._padding_,0,this[1]._padding_);
  }
  RaceSetObjective = false;
  pcVar3 = GetMapTRNFilename();
  pcVar7 = local_88;
  strcpy_s(pcVar7,0x80,pcVar3);
  OpenODF2(pcVar7);
  GetODFBool(local_88,"DLL","RespawnAtLowAltitude",(bool *)(this->m_AITargetHandles + 0x3b),false);
  GetODFFloat(local_88,"DLL","CheckpointRadius",(float *)(this->m_AITargetHandles + 0x73),35.0);
  GetODFFloat(local_88,"DLL","FriendlySpawnpointMaxAllyRange",
              (float *)(this->m_AITargetHandles + 0x70),100.0);
  GetODFFloat(local_88,"DLL","FriendlySpawnpointMinEnemyRange",
              (float *)(this->m_AITargetHandles + 0x71),300.0);
  pcVar7 = local_88;
  GetODFFloat(pcVar7,"DLL","RandomSpawnpointMinEnemyRange",(float *)(this->m_AITargetHandles + 0x72)
              ,150.0);
  GetMapTRNFilename();
  TRNAllies::SetupTRNAllies(pcVar7);
  this->m_TeamPos[0x30] = -NAN;
  pcVar8 = GetVarItemInt_exref;
  iVar4 = GetVarItemInt("network.session.ivar0");
  *(int *)(this->m_AILastWentForPowerup + 0xae) = iVar4;
  iVar4 = GetVarItemInt("network.session.ivar1");
  *(int *)(this->m_AILastWentForPowerup + 0xa2) = iVar4;
  uVar5 = GetVarItemInt("network.session.ivar7");
  fVar6 = (float)GetVarItemInt("network.session.ivar9");
  this->m_TeamPos[0x31] = fVar6;
  iVar4 = GetVarItemInt("network.session.ivar31");
  this->m_AICraftHandles[0xed] = iVar4;
  iVar4 = GetVarItemInt("network.session.ivar35");
  this->m_AICraftHandles[0xee] = iVar4;
  SetGravity((float)this->m_AICraftHandles[0xed] * __real_3f000000);
  iVar4 = GetVarItemInt("network.session.ivar32");
  *(bool *)((int)this->m_AITargetHandles + 0xed) = iVar4 != 0;
  iVar4 = GetVarItemInt("network.session.ivar13");
  iVar4 = iVar4 * *(int *)(this->m_AILastWentForPowerup + 0x96);
  *(int *)(this->m_AILastWentForPowerup + 0xfe) = iVar4;
  if (iVar4 < 0) {
    *(undefined4 *)(this->m_AILastWentForPowerup + 0xfe) = 0;
  }
  this->m_FRIENDLY_SPAWNPOINT_MIN_ENEMY = 0.0;
  this->m_RANDOM_SPAWNPOINT_MIN_ENEMY = 0.0;
  *(uint *)(this->m_AILastWentForPowerup + 0xb2) = uVar5 & 0xff;
  bVar2 = DMIsRaceSubtype[uVar5 & 0xff];
  *(uint *)(this->m_AILastWentForPowerup + 0xb6) = (int)uVar5 >> 8 & 0xff;
  if (bVar2 == false) {
    fVar6 = (float)GetVarItemInt("network.session.ivar9");
    this->m_RANDOM_SPAWNPOINT_MIN_ENEMY = fVar6;
    if (0xff < (int)fVar6) {
      this->m_RANDOM_SPAWNPOINT_MIN_ENEMY = 3.58732e-43;
    }
    bVar2 = IsNetworkOn();
    if (!bVar2) {
      this->m_RANDOM_SPAWNPOINT_MIN_ENEMY = 0.0;
      this->m_AICraftHandles[0xed] = 0x19;
      SetGravity(12.5);
    }
  }
  fVar6 = (float)GetVarItemInt("network.session.ivar22");
  this->m_FRIENDLY_SPAWNPOINT_MAX_ALLY = fVar6;
  if (((int)fVar6 < 0) || (4 < (int)fVar6)) {
    this->m_FRIENDLY_SPAWNPOINT_MAX_ALLY = 4.2039e-45;
  }
  bVar2 = IsNetworkOn();
  if (!bVar2) {
    this->m_FRIENDLY_SPAWNPOINT_MAX_ALLY = 4.2039e-45;
  }
  iVar4 = GetVarItemInt("network.session.ivar16");
  *(bool *)((int)this->m_AICraftHandles + 0x3e6) = iVar4 != 0;
  if (iVar4 != 0) {
    iVar4 = 1;
    do {
      iVar9 = 1;
      do {
        if (iVar4 != iVar9) {
          Ally(iVar4,iVar9);
        }
        iVar9 = iVar9 + 1;
      } while (iVar9 < 0xc);
      iVar4 = iVar4 + 1;
    } while (iVar4 < 0xc);
    pcVar8 = GetVarItemInt_exref;
  }
  iVar4 = (*pcVar8)("network.session.ivar23");
  *(bool *)((int)this->m_AICraftHandles + 999) = iVar4 != 0;
  iVar4 = (*pcVar8)("network.session.ivar19");
  *(bool *)((int)this->m_AITargetHandles + 0xea) = iVar4 != 0;
  iVar4 = (*pcVar8)("network.session.ivar25");
  this->m_RaceCheckpointRadius = 0.0;
  *(bool *)((int)this->m_AITargetHandles + 0xeb) = iVar4 != 0;
  fVar6 = (float)(*pcVar8)("network.session.ivar27");
  this->f_last = fVar6;
  if (7 < (int)fVar6) {
    this->f_last = 1.12104e-44;
    fVar6 = 1.12104e-44;
  }
  if (0 < (int)fVar6) {
    sprintf_s<128>((char (*) [128])local_88,"network.session.svar%d");
    pcVar7 = GetVarItemStr(local_88);
    if (pcVar7 == (char *)0x0) {
LAB_4fc418b1:
      pcVar7 = "mcjak01";
    }
    else {
      pcVar7 = DLLUtils::GetCheckedNetworkSvar(unaff_EDI,unaff_ESI);
      if (pcVar7 == (char *)0x0) goto LAB_4fc418b1;
      pcVar3 = pcVar7;
      do {
        cVar1 = *pcVar3;
        pcVar3 = pcVar3 + 1;
      } while (cVar1 != '\0');
      if ((uint)((int)pcVar3 - (int)(pcVar7 + 1)) < 2) goto LAB_4fc418b1;
    }
    strcpy_s((char *)&this->h_first,0x40,pcVar7);
  }
  iVar4 = GetLocalPlayerTeamNumber();
  iVar9 = GetPlayerHandle();
  if (iVar9 != 0) {
    RemoveObject(iVar9);
  }
  bVar2 = ImServer();
  if (!bVar2) {
    bVar2 = IsNetworkOn();
    if (bVar2) goto LAB_4fc41960;
  }
  if (*(int *)(this->m_AILastWentForPowerup + 0xaa) == 0) {
    *(int *)(this->m_AILastWentForPowerup + 0xaa) =
         *(int *)(this->m_AILastWentForPowerup + 0x96) *
         *(int *)(this->m_AILastWentForPowerup + 0xa2) * 0x3c;
  }
  iVar9 = SetupPlayer(this,iVar4);
  SetAsUser(iVar9,iVar4);
  AddPilotByHandle(iVar9);
  if ((*(char *)((int)this->m_AICraftHandles + 999) != '\0') && (this[1]._padding_ == 0)) {
    GetObjInfo(iVar9,Get_CFG,local_48);
    if (iVar9 != 0) {
      SetNewRabbit(this,iVar9);
    }
  }
LAB_4fc41960:
  CreateObjectives(this);
  PUPMgr::Init();
  *(undefined2 *)((int)this->m_AICraftHandles + 0x3c1) = 1;
  return;
}


// ---------------------------------------------------------------------
// Deathmatch01::ObjectifyRacePoint  @ 4fc41469  lines 1290-1319


void __thiscall Deathmatch01::ObjectifyRacePoint(Deathmatch01 *this)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < (int)this->m_TeamPos[0x1f]) {
    do {
      iVar2 = iVar2 + 1;
      sprintf_s<64>(&TempODFName,"checkpoint%d");
      iVar1 = GetHandle(TempODFName);
      SetObjectiveOff(iVar1);
    } while (iVar2 < (int)this->m_TeamPos[0x1f]);
  }
  iVar2 = GetLocalPlayerTeamNumber();
  if ((-1 < iVar2) &&
     ((this->m_TeamPos[0x31] == 0.0 ||
      ((int)this->m_TeamPos[iVar2 + 0x20] < (int)this->m_TeamPos[0x31])))) {
    sprintf_s<64>(&TempODFName,"checkpoint%d");
    iVar2 = GetHandle(TempODFName);
    if (iVar2 != 0) {
      SetObjectiveOn(iVar2);
    }
  }
  return;
}


// ---------------------------------------------------------------------
// Deathmatch01::ExecuteRabbit  @ 4fc4117b  lines 1324-1490


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall Deathmatch01::ExecuteRabbit(Deathmatch01 *this)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  uint uVar6;
  code *pcVar7;
  char local_48 [64];
  undefined4 local_8;
  
  local_8 = __security_cookie ^ (uint)(local_48 + 0x44);
  iVar3 = this[1]._padding_;
  bVar1 = IsAround(iVar3);
  pcVar7 = GetPlayerHandle_exref;
  if (bVar1) {
    this->m_AICraftHandles[0xec] = 0;
    if (((char)this->m_AICraftHandles[0xfa] != '\0') &&
       (iVar2 = GetPlayerHandle(this->m_AICraftHandles[0xe9]), iVar3 != iVar2)) {
      iVar3 = GetPlayerHandle(this->m_AICraftHandles[0xe9]);
      GetObjInfo(iVar3,Get_CFG,local_48);
      if (iVar3 != 0) {
        SetNewRabbit(this,iVar3);
      }
    }
  }
  else {
    this->m_AICraftHandles[0xec] = this->m_AICraftHandles[0xec] + 1;
  }
  if ((*(char *)((int)this->m_AICraftHandles + 0x3e9) != '\0') &&
     (iVar3 = GetPlayerHandle(this->m_AICraftHandles[0xeb]), this[1]._padding_ != iVar3)) {
    iVar3 = GetPlayerHandle(this->m_AICraftHandles[0xeb]);
    this[1]._padding_ = iVar3;
  }
  if (1 < this->m_AICraftHandles[0xec]) {
    bVar1 = IsAround(this[1]._padding_);
    if (((!bVar1) && ((char)this->m_AICraftHandles[0xfa] != '\0')) &&
       (this->m_AICraftHandles[0xe9] != this->m_AICraftHandles[0xea])) {
      iVar3 = GetPlayerHandle(this->m_AICraftHandles[0xe9]);
      GetObjInfo(iVar3,Get_CFG,local_48);
      if (iVar3 != 0) {
        SetNewRabbit(this,iVar3);
      }
    }
    bVar1 = IsAround(this[1]._padding_);
    if (!bVar1) {
      bVar1 = IsAround(this[1]._padding_);
      if (!bVar1) {
        iVar3 = 0;
        do {
          uVar6 = *(int *)(this->m_AILastWentForPowerup + 0xa6) + iVar3 & 0x8000000f;
          if ((int)uVar6 < 0) {
            uVar6 = (uVar6 - 1 | 0xfffffff0) + 1;
          }
          iVar2 = GetPlayerHandle(uVar6);
          if (((uVar6 != 0) && (iVar2 != 0)) && (uVar6 != this->m_AICraftHandles[0xea])) {
            GetObjInfo(iVar2,Get_CFG,local_48);
            goto LAB_4fc4134f;
          }
          iVar3 = iVar3 + 1;
        } while (iVar3 < 0x10);
        iVar3 = 0;
        while( true ) {
          uVar6 = *(int *)(this->m_AILastWentForPowerup + 0xa6) + iVar3 & 0x800000ff;
          if ((int)uVar6 < 0) {
            uVar6 = (uVar6 - 1 | 0xffffff00) + 1;
          }
          iVar2 = this->m_AITargetHandles[uVar6 + 0x9c];
          if (iVar2 != 0) break;
          iVar3 = iVar3 + 1;
          if (0xff < iVar3) goto LAB_4fc4135d;
        }
        GetObjInfo(iVar2,Get_CFG,local_48);
LAB_4fc4134f:
        SetNewRabbit(this,iVar2);
        this->m_AICraftHandles[0xea] = 0;
LAB_4fc4135d:
        pcVar4 = GetBZCCLocalizedString("mission","Reset the rabbit... it\'s hunting season!");
        AddToMessagesBox(pcVar4);
        pcVar7 = GetPlayerHandle_exref;
        goto LAB_4fc4137d;
      }
      iVar3 = this[1]._padding_;
      GetObjInfo(iVar3,Get_CFG,local_48);
      if (iVar3 != 0) {
        SetNewRabbit(this,iVar3);
      }
    }
  }
LAB_4fc4137d:
  bVar1 = IsAround(this[1]._padding_);
  if (bVar1) {
    iVar3 = GetWhoShotMe(this[1]._padding_);
    if (((iVar3 != 0) && (iVar3 != this[1]._padding_)) && (iVar3 != this[1]._padding_)) {
      iVar5 = GetTeamNum(iVar3);
      iVar2 = this->m_AICraftHandles[0xeb];
      if (((iVar5 == iVar2) || (iVar2 == 0)) && (iVar2 = (*pcVar7)(iVar2), iVar2 != 0)) {
        iVar3 = iVar2;
      }
      this->m_AICraftHandles[0xeb] = 0;
      this[1]._padding_ = iVar3;
      *(undefined1 *)((int)this->m_AICraftHandles + 0x3e9) = 0;
      iVar3 = 1;
      do {
        iVar2 = (*pcVar7)(iVar3);
        if (iVar2 == this[1]._padding_) {
          *(undefined1 *)((int)this->m_AICraftHandles + 0x3e9) = 1;
          this->m_AICraftHandles[0xeb] = iVar3;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < 0x10);
    }
    if ((*(int *)(this->m_AILastWentForPowerup + 0xa6) %
         (*(int *)(this->m_AILastWentForPowerup + 0x96) * 5) == 0) &&
       ((iVar3 = CountPlayers(), 1 < iVar3 || (0 < (int)this->m_FRIENDLY_SPAWNPOINT_MIN_ENEMY)))) {
      AddScore(this[1]._padding_,1);
    }
    if (*(int *)(this->m_AILastWentForPowerup + 0xa6) %
        *(int *)(this->m_AILastWentForPowerup + 0x96) == 0) {
      ObjectifyRabbit(this);
    }
  }
  return;
}


// ---------------------------------------------------------------------
// Deathmatch01::ExecuteRace  @ 4fc40cfc  lines 1494-1627


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall Deathmatch01::ExecuteRace(Deathmatch01 *this)

{
  int iVar1;
  uint uVar2;
  char *pcVar3;
  float fVar4;
  uint uVar5;
  float fVar6;
  float *pfVar7;
  bool bVar8;
  int iVar9;
  int local_2c;
  float *local_28;
  float *local_24;
  float *local_20;
  char local_19;
  char acStack_18 [16];
  undefined4 local_8;
  
  local_8 = __security_cookie ^ (uint)(acStack_18 + 0x14);
  if ((!RaceSetObjective) ||
     (*(int *)(this->m_AILastWentForPowerup + 0xa6) % *(int *)(this->m_AILastWentForPowerup + 0x96)
      == 0)) {
    RaceSetObjective = true;
    ObjectifyRacePoint(this);
  }
  pfVar7 = &this->f_first;
  uVar5 = 0;
  local_19 = '\0';
  bVar8 = true;
  do {
    if (!bVar8) {
                    /* WARNING: Subroutine does not return */
      __report_rangecheckfailure();
    }
    acStack_18[uVar5] = '\0';
    local_28 = (float *)GetPlayerHandle(uVar5);
    if (local_28 != (float *)0x0) {
      sprintf_s<64>(&TempODFName,"checkpoint%d");
      local_2c = GetHandle(TempODFName);
      if (((local_2c != 0) &&
          (local_24 = (float *)(*misnImport.GetDistanceObject)((int *)&local_28,&local_2c),
          (float)local_24 < (float)this->m_AITargetHandles[0x73])) &&
         ((this->m_TeamPos[0x31] == 0.0 || ((int)pfVar7[0x21] < (int)this->m_TeamPos[0x31])))) {
        *pfVar7 = (float)((int)*pfVar7 + 1);
        if ((int)this->m_TeamPos[0x1f] < (int)*pfVar7) {
          pfVar7[0x21] = (float)((int)pfVar7[0x21] + 1);
          *pfVar7 = 1.4013e-45;
        }
        ObjectifyRacePoint(this);
        pfVar7[0x10] = (float)((int)pfVar7[0x10] + 1);
        fVar6 = *pfVar7;
        acStack_18[uVar5] = '\x01';
        local_19 = '\x01';
        if ((fVar6 == 1.4013e-45) && (uVar2 = GetLocalPlayerTeamNumber(), uVar5 == uVar2)) {
          if (this->m_TeamPos[0x31] == 0.0) {
            pcVar3 = GetBZCCLocalizedString("mission","Lap %d Completed");
            sprintf_s<1024>(&StaticTempMsgStr,pcVar3);
          }
          else {
            pcVar3 = GetBZCCLocalizedString("mission","Lap %d/%d Completed");
            sprintf_s<1024>(&StaticTempMsgStr,pcVar3);
          }
          AddToMessagesBox(StaticTempMsgStr);
        }
      }
    }
    uVar5 = uVar5 + 1;
    pfVar7 = pfVar7 + 1;
    bVar8 = uVar5 < 0x10;
  } while ((int)uVar5 < 0x10);
  if (local_19 != '\0') {
    local_28 = this->m_TeamPos + 0xf;
    fVar6 = 0.0;
    local_20 = this->m_TeamPos + 0x20;
    do {
      if (acStack_18[(int)fVar6] != '\0') {
        local_2c = GetPlayerHandle((int)fVar6);
        bVar8 = true;
        fVar4 = 0.0;
        local_24 = local_28;
        do {
          if (fVar6 != fVar4) {
            if (*(int *)((-0xa54c - (int)this) + (int)local_28 + (int)local_20) <= (int)*local_24) {
              bVar8 = false;
            }
          }
          fVar4 = (float)((int)fVar4 + 1);
          local_24 = local_24 + 1;
        } while ((int)fVar4 < 0x10);
        if ((bVar8) && (fVar6 != this->m_TeamPos[0x30])) {
          GetPlayerName(local_2c);
          pcVar3 = GetBZCCLocalizedString("mission","%s takes the lead");
          sprintf_s<1024>(&StaticTempMsgStr,pcVar3);
          AddToMessagesBox(StaticTempMsgStr);
          this->m_TeamPos[0x30] = fVar6;
        }
        iVar1 = local_2c;
        bVar8 = true;
        fVar4 = 0.0;
        local_24 = local_28;
        do {
          if (fVar6 != fVar4) {
            if ((int)local_28[(int)fVar6] < (int)*local_24) {
              bVar8 = false;
            }
          }
          fVar4 = (float)((int)fVar4 + 1);
          local_24 = local_24 + 1;
        } while ((int)fVar4 < 0x10);
        if ((bVar8) && (local_20[-0x21] == 1.4013e-45)) {
          AddScore(local_2c,1);
          if (this->m_TeamPos[0x32] == 0.0) {
            if (this->m_TeamPos[0x31] == 0.0) {
              GetPlayerName(iVar1);
              pcVar3 = GetBZCCLocalizedString("mission","Lap %d completed by %s");
              sprintf_s<1024>(&StaticTempMsgStr,pcVar3);
            }
            else {
              GetPlayerName(iVar1);
              pcVar3 = GetBZCCLocalizedString("mission","Lap %d/%d completed by %s");
              sprintf_s<1024>(&StaticTempMsgStr,pcVar3);
            }
          }
          AddToMessagesBox(StaticTempMsgStr);
          if (*local_20 == this->m_TeamPos[0x31]) {
            this->m_TeamPos[0x32] = (float)((int)this->m_TeamPos[0x32] + 1);
            fVar4 = this->m_TeamPos[0x32];
            if (fVar4 == 1.4013e-45) {
              GetPlayerName(iVar1);
              pcVar3 = GetBZCCLocalizedString("mission","%s finished in 1st place");
              sprintf_s<1024>(&StaticTempMsgStr,pcVar3);
              iVar9 = 100;
LAB_4fc410f5:
              AddScore(iVar1,iVar9);
            }
            else {
              if (fVar4 == 2.8026e-45) {
                GetPlayerName(iVar1);
                pcVar3 = GetBZCCLocalizedString("mission","%s finished in 2nd place");
                sprintf_s<1024>(&StaticTempMsgStr,pcVar3);
                iVar9 = 0x4b;
                goto LAB_4fc410f5;
              }
              if (fVar4 == 4.2039e-45) {
                GetPlayerName(iVar1);
                pcVar3 = GetBZCCLocalizedString("mission","%s finished in 3rd place");
                sprintf_s<1024>(&StaticTempMsgStr,pcVar3);
                iVar9 = 0x32;
                goto LAB_4fc410f5;
              }
              GetPlayerName(iVar1);
              pcVar3 = GetBZCCLocalizedString("mission","%s finished in %dth place");
              sprintf_s<1024>(&StaticTempMsgStr,pcVar3);
              AddScore(iVar1,0x19);
            }
            if ((int)this->m_TeamPos[0x32] < 2) {
              NoteGameoverWithCustomMessage(StaticTempMsgStr);
              pcVar3 = GetBZCCLocalizedString("mission","10 seconds left...");
              strcpy_s(StaticTempMsgStr,0x400,pcVar3);
            }
            else {
              AddToMessagesBox(StaticTempMsgStr);
            }
            DoGameover(10.0);
          }
        }
      }
      fVar6 = (float)((int)fVar6 + 1);
      local_20 = local_20 + 1;
    } while ((int)fVar6 < 0x10);
  }
  return;
}


// ---------------------------------------------------------------------
// Deathmatch01::ExecuteWeenie  @ 4fc40b46  lines 1630-1682


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall Deathmatch01::ExecuteWeenie(Deathmatch01 *this)

{
  int iVar1;
  int iVar2;
  int iVar3;
  float fVar4;
  int *local_8;
  
  iVar3 = 1;
  do {
    iVar1 = GetPlayerHandle(iVar3);
    if ((((iVar1 != 0) && (iVar2 = GetWhoShotMe(iVar1), iVar2 != 0)) && (iVar2 != iVar1)) &&
       ((fVar4 = GetLastEnemyShot(iVar1), ___real_00000000 <= fVar4 ||
        (*(char *)((int)this->m_AITargetHandles + 0xed) != '\0')))) {
      DamageF(iVar1,3.4028e+38);
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0x10);
  iVar3 = 0;
  if (0 < (int)this->m_FRIENDLY_SPAWNPOINT_MIN_ENEMY) {
    local_8 = this->m_AITargetHandles + 0x9c;
    do {
      iVar1 = *local_8;
      if (((iVar1 != 0) && (iVar2 = GetWhoShotMe(iVar1), iVar2 != 0)) &&
         ((iVar2 != iVar1 &&
          ((fVar4 = GetLastEnemyShot(iVar1), ___real_00000000 <= fVar4 ||
           (*(char *)((int)this->m_AITargetHandles + 0xed) != '\0')))))) {
        DamageF(iVar1,3.4028e+38);
      }
      iVar3 = iVar3 + 1;
      local_8 = local_8 + 1;
    } while (iVar3 < (int)this->m_FRIENDLY_SPAWNPOINT_MIN_ENEMY);
  }
  iVar3 = 0;
  if (0 < (int)this->m_RaceCheckpointRadius) {
    local_8 = &this[1]._padding_;
    do {
      iVar1 = *local_8;
      if ((((iVar1 != 0) && (iVar2 = GetWhoShotMe(iVar1), iVar2 != 0)) && (iVar2 != iVar1)) &&
         ((fVar4 = GetLastEnemyShot(iVar1), ___real_00000000 <= fVar4 ||
          (*(char *)((int)this->m_AITargetHandles + 0xed) != '\0')))) {
        DamageF(iVar1,3.4028e+38);
      }
      iVar3 = iVar3 + 1;
      local_8 = local_8 + 1;
    } while (iVar3 < (int)this->m_RaceCheckpointRadius);
  }
  iVar3 = 0;
  if (0 < *(int *)(this->m_AILastWentForPowerup + 0xba)) {
    local_8 = this->m_AITargetHandles + 0x7c;
    do {
      iVar1 = *local_8;
      if (((iVar1 != 0) && (iVar2 = GetWhoShotMe(iVar1), iVar2 != 0)) &&
         ((iVar2 != iVar1 &&
          ((fVar4 = GetLastEnemyShot(iVar1), ___real_00000000 <= fVar4 ||
           (*(char *)((int)this->m_AITargetHandles + 0xed) != '\0')))))) {
        DamageF(iVar1,3.4028e+38);
      }
      iVar3 = iVar3 + 1;
      local_8 = local_8 + 1;
    } while (iVar3 < *(int *)(this->m_AILastWentForPowerup + 0xba));
  }
  return;
}


// ---------------------------------------------------------------------
// Deathmatch01::ExecuteTrackPlayers  @ 4fc40a43  lines 1688-1741


void __thiscall Deathmatch01::ExecuteTrackPlayers(Deathmatch01 *this)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  Deathmatch01 *local_c;
  Deathmatch01 *local_8;
  
  iVar2 = 1;
  piVar3 = &this[1]._padding_;
  local_c = this;
  local_8 = this;
  do {
    local_8 = (Deathmatch01 *)GetPlayerHandle(iVar2);
    if (local_8 != (Deathmatch01 *)0x0) {
      SetLifespan((int)local_8,-1.0);
      bVar1 = IsAliveAndPilot((int *)&local_8);
      if (bVar1) {
        if (*(char *)((int)this->m_AITargetHandles + 0xeb) != '\0') {
          piVar3[-0x40e] = -0x1000;
          if ((*(int *)(this->m_AILastWentForPowerup + 0xb2) == 0) ||
             (*(int *)(this->m_AILastWentForPowerup + 0xb2) == 7)) {
            AddScore((int)local_8,-5);
          }
          SelfDamage((int)local_8,1e+20);
        }
        local_c = (Deathmatch01 *)*piVar3;
        bVar1 = IsAround((int)local_c);
        if (bVar1) {
          local_c = (Deathmatch01 *)*piVar3;
          bVar1 = IsAliveAndPilot((int *)&local_c);
          if (!bVar1) {
            if (*(char *)((int)this->m_AITargetHandles + 0xeb) == '\0') {
              if (*(int *)(this->m_AILastWentForPowerup + 0xba) < 0x20) {
                this->m_AITargetHandles[*(int *)(this->m_AILastWentForPowerup + 0xba) + 0x7c] =
                     *piVar3;
                *(int *)(this->m_AILastWentForPowerup + 0xba) =
                     *(int *)(this->m_AILastWentForPowerup + 0xba) + 1;
              }
            }
            else {
              SelfDamage(*piVar3,1e+20);
            }
            *piVar3 = 0;
          }
        }
      }
      else {
        *piVar3 = (int)local_8;
      }
    }
    iVar2 = iVar2 + 1;
    piVar3 = piVar3 + 1;
  } while (iVar2 < 0x10);
  return;
}


// ---------------------------------------------------------------------
// Deathmatch01::UpdateGameTime  @ 4fc408c8  lines 1746-1817


void __thiscall Deathmatch01::UpdateGameTime(Deathmatch01 *this)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  
  iVar4 = *(int *)(this->m_AILastWentForPowerup + 0xa6) + 1;
  iVar2 = *(int *)(this->m_AILastWentForPowerup + 0x96);
  *(int *)(this->m_AILastWentForPowerup + 0xa6) = iVar4;
  if (*(int *)(this->m_AILastWentForPowerup + 0xaa) < 1) {
    if (iVar4 % iVar2 == 0) {
      if ((iVar4 / iVar2) / 0xe10 == 0) {
        pcVar3 = GetBZCCLocalizedString("mission","Mission Time %d:%02d");
        sprintf_s<1024>(&TempMsgString,pcVar3);
      }
      else {
        pcVar3 = GetBZCCLocalizedString("mission","Mission Time %d:%02d:%02d");
        sprintf_s<1024>(&TempMsgString,pcVar3);
      }
      SetTimerBox(TempMsgString);
    }
  }
  else {
    iVar4 = *(int *)(this->m_AILastWentForPowerup + 0xaa) + -1;
    *(int *)(this->m_AILastWentForPowerup + 0xaa) = iVar4;
    if (iVar4 % iVar2 == 0) {
      iVar1 = (iVar4 / iVar2) / 0x3c;
      iVar4 = (iVar4 / iVar2) % 0x3c;
      iVar2 = iVar1 / 0x3c;
      iVar1 = iVar1 % 0x3c;
      if (iVar2 == 0) {
        pcVar3 = GetBZCCLocalizedString("mission","Time Left %d:%02d\n");
        sprintf_s<1024>(&TempMsgString,pcVar3);
      }
      else {
        pcVar3 = GetBZCCLocalizedString("mission","Time Left %d:%02d:%02d\n");
        sprintf_s<1024>(&TempMsgString,pcVar3);
      }
      SetTimerBox(TempMsgString);
      if ((iVar2 == 0) &&
         (((iVar4 == 0 && ((iVar1 < 0xb || (iVar1 % 5 == 0)))) || ((iVar1 == 0 && (iVar4 % 5 == 0)))
          ))) {
        AddToMessagesBox(TempMsgString);
      }
    }
    if (*(int *)(this->m_AILastWentForPowerup + 0xaa) == 0) {
      NoteGameoverByTimelimit();
      DoGameover(10.0);
    }
  }
  return;
}


// ---------------------------------------------------------------------
// Deathmatch01::UpdateAIUnits  @ 4fc407ad  lines 1820-1944


void __thiscall Deathmatch01::UpdateAIUnits(Deathmatch01 *this)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  float fVar6;
  Deathmatch01 *local_8;
  
  iVar5 = 0;
  if (*(int *)(this->m_AILastWentForPowerup + 0xa6) % 5 == 0) {
    fVar6 = this->m_FRIENDLY_SPAWNPOINT_MIN_ENEMY;
    if ((int)fVar6 < (int)this->m_RANDOM_SPAWNPOINT_MIN_ENEMY) {
      local_8 = this;
      BuildBotCraft(this,(int)fVar6);
      this->m_FRIENDLY_SPAWNPOINT_MIN_ENEMY =
           (float)((int)this->m_FRIENDLY_SPAWNPOINT_MIN_ENEMY + 1);
    }
    else {
      iVar3 = 0;
      if (0 < (int)fVar6) {
        local_8 = (Deathmatch01 *)(this->m_AITargetHandles + 0x9c);
        do {
          bVar1 = IsNotDeadAndPilot2(local_8->_padding_);
          iVar2 = local_8->_padding_;
          if (!bVar1) {
            SetLifespan(iVar2,300.0);
            iVar2 = 0;
            local_8->_padding_ = 0;
          }
          if (iVar2 == 0) {
            BuildBotCraft(this,iVar3);
            break;
          }
          iVar3 = iVar3 + 1;
          local_8 = (Deathmatch01 *)&local_8->_padding_;
        } while (iVar3 < (int)this->m_FRIENDLY_SPAWNPOINT_MIN_ENEMY);
      }
    }
  }
  if (0 < (int)this->m_FRIENDLY_SPAWNPOINT_MIN_ENEMY) {
    piVar4 = this->m_EmptyVehicles + 9;
    do {
      if (((*(int *)(this->m_AILastWentForPowerup + 0xa6) + iVar5 & 0x1fU) == 0) &&
         (*(char *)((int)this->m_AICraftHandles + iVar5 + 0x3ea) != '\0')) {
        local_8 = (Deathmatch01 *)piVar4[0x2b3];
        *piVar4 = *piVar4 + 1;
        bVar1 = IsAlive((int *)&local_8);
        if ((!bVar1) ||
           ((0x96 < *piVar4 ||
            (fVar6 = (*misnImport.GetDistanceObject)(piVar4 + 0x1b3,piVar4 + 0x2b3),
            fVar6 < __real_40000000)))) {
          FindGoodAITarget(this,iVar5);
        }
      }
      iVar5 = iVar5 + 1;
      piVar4 = piVar4 + 1;
    } while (iVar5 < (int)this->m_FRIENDLY_SPAWNPOINT_MIN_ENEMY);
  }
  return;
}


// ---------------------------------------------------------------------
// Deathmatch01::UpdateAnimals  @ 4fc40705  lines 1947-1999


void __thiscall Deathmatch01::UpdateAnimals(Deathmatch01 *this)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  float fVar4;
  Deathmatch01 *local_c;
  int local_8;
  
  local_8 = 0;
  fVar4 = this->m_RaceCheckpointRadius;
  local_c = this;
  if (0 < (int)fVar4) {
    piVar3 = &this[1]._padding_;
    do {
      if (((Deathmatch01 *)*piVar3 != (Deathmatch01 *)0x0) &&
         (local_c = (Deathmatch01 *)*piVar3, bVar1 = IsAlive((int *)&local_c), !bVar1)) {
        *piVar3 = 0;
      }
      fVar4 = this->m_RaceCheckpointRadius;
      local_8 = local_8 + 1;
      piVar3 = piVar3 + 1;
    } while (local_8 < (int)fVar4);
  }
  if (*(int *)(this->m_AILastWentForPowerup + 0xa6) %
      (*(int *)(this->m_AILastWentForPowerup + 0x96) << 2) == 0) {
    if ((int)fVar4 < (int)this->f_last) {
      SetupAnimal(this,(int)fVar4);
      this->m_RaceCheckpointRadius = (float)((int)this->m_RaceCheckpointRadius + 1);
    }
    else {
      iVar2 = 0;
      if (0 < (int)fVar4) {
        piVar3 = &this[1]._padding_;
        do {
          if (*piVar3 == 0) {
            SetupAnimal(this,iVar2);
            return;
          }
          iVar2 = iVar2 + 1;
          piVar3 = piVar3 + 1;
        } while (iVar2 < (int)this->m_RaceCheckpointRadius);
      }
    }
  }
  return;
}


// ---------------------------------------------------------------------
// Deathmatch01::Execute  @ 4fc404da  lines 2002-2141


void __thiscall Deathmatch01::Execute(Deathmatch01 *this)

{
  bool bVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int unaff_EDI;
  int iVar6;
  int local_20 [5];
  int local_c;
  char local_5;
  
  iVar5 = 0;
  if (*(int *)(this->m_AILastWentForPowerup + 0x9e) == 0) {
    LuaMission::Execute((LuaMission *)this);
  }
  if (*(char *)((int)this->m_AICraftHandles + 0x3c1) == '\0') {
    Init(this);
  }
  UpdateEmptyVehicles(this);
  iVar6 = *(int *)(this->m_AILastWentForPowerup + 0xb2);
  if (DMIsRaceSubtype[iVar6] != false) {
    ExecuteRace(this);
    iVar6 = *(int *)(this->m_AILastWentForPowerup + 0xb2);
  }
  if ((*(char *)((int)this->m_AICraftHandles + 999) != '\0') && ((iVar6 == 0 || (iVar6 == 7)))) {
    ExecuteRabbit(this);
  }
  if (*(char *)((int)this->m_AITargetHandles + 0xea) != '\0') {
    ExecuteWeenie(this);
  }
  if ((*(int *)(this->m_AILastWentForPowerup + 0xb2) == 2) &&
     (*(int *)(this->m_AILastWentForPowerup + 0xa6) % *(int *)(this->m_AILastWentForPowerup + 0x96)
      == 0)) {
    ObjectifyFlag(this);
  }
  ExecuteTrackPlayers(this);
  UpdateGameTime(this);
  if (this->m_RANDOM_SPAWNPOINT_MIN_ENEMY != 0.0) {
    UpdateAIUnits(this);
  }
  if (this->f_last != 0.0) {
    UpdateAnimals(this);
  }
  PUPMgr::Execute();
  iVar6 = 0;
  do {
    if ((((*(char *)((int)this->m_AICraftHandles + iVar6 + 0x3c4) != '\0') &&
         (local_c = GetPlayerHandle(iVar6), local_c != 0)) &&
        (bVar1 = IsFlying(local_20 + 5), !bVar1)) &&
       (*(undefined1 *)((int)this->m_AICraftHandles + iVar6 + 0x3c4) = 0, local_c != 0)) {
      pcVar2 = GetNextVehicleODF(this,iVar6,SUB41(unaff_EDI,0));
      unaff_EDI = 0;
      local_20[4] = BuildEmptyCraftNear(local_c,pcVar2,iVar6,10.0,20.0);
      if (local_20[4] != 0) {
        SetTeamNum(local_20[4],0);
        unaff_EDI = local_20[4];
        AddEmptyVehicle(this,local_20[4]);
      }
    }
    iVar6 = iVar6 + 1;
  } while (iVar6 < 0x10);
  if ((0 < this->m_AICraftHandles[0xee]) && (*(char *)((int)this->m_AITargetHandles + 0xee) == '\0')
     ) {
    local_5 = IsTeamplayOn();
    local_20[2] = 0;
    local_20[3] = 0;
    local_20[0] = 0;
    local_20[1] = 0;
    local_c = 0;
    do {
      iVar6 = GetPlayerHandle(local_c);
      if (iVar6 != 0) {
        if (local_5 == '\0') {
          iVar4 = GetScore(iVar6);
          if (this->m_AICraftHandles[0xee] <= iVar4) {
            NoteGameoverByScore(iVar6);
            DoGameover(5.0);
            *(undefined1 *)((int)this->m_AITargetHandles + 0xee) = 1;
            break;
          }
        }
        else {
          local_20[4] = WhichTeamGroup(local_c);
          if (local_20[4] < 2) {
            iVar3 = GetScore(iVar6);
            iVar4 = local_20[4];
            local_20[local_20[4] + 2] = local_20[local_20[4] + 2] + iVar3;
            if (local_20[iVar4] == 0) {
              local_20[iVar4] = iVar6;
            }
          }
        }
      }
      local_c = local_c + 1;
    } while (local_c < 0x10);
    if (local_5 != '\0') {
      do {
        if (this->m_AICraftHandles[0xee] <= local_20[iVar5 + 2]) {
          NoteGameoverByScore(local_20[iVar5]);
          DoGameover(5.0);
          *(undefined1 *)((int)this->m_AITargetHandles + 0xee) = 1;
          return;
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < 2);
    }
  }
  return;
}


// ---------------------------------------------------------------------
// Deathmatch01::AddPlayer  @ 4fc40479  lines 2144-2163


bool __thiscall Deathmatch01::AddPlayer(Deathmatch01 *this,ulong param_1,int param_2,bool param_3)

{
  int iVar1;
  
  if (*(int *)(this->m_AILastWentForPowerup + 0x9e) == 0) {
    LuaMission::AddPlayer((LuaMission *)this,param_1,param_2,param_3);
  }
  if (*(char *)((int)this->m_AICraftHandles + 0x3c1) == '\0') {
    Init(this);
  }
  if (param_3) {
    iVar1 = SetupPlayer(this,param_2);
    SetAsUser(iVar1,param_2);
    AddPilotByHandle(iVar1);
    SetNoScrapFlagByHandle(iVar1);
  }
  return true;
}


// ---------------------------------------------------------------------
// Deathmatch01::DeletePlayer  @ 4fc40463  lines 2166-2169


void __thiscall Deathmatch01::DeletePlayer(Deathmatch01 *this,ulong param_1)

{
  if (*(int *)(this->m_AILastWentForPowerup + 0x9e) == 0) {
    LuaMission::DeletePlayer((LuaMission *)this,param_1);
    return;
  }
  return;
}


// ---------------------------------------------------------------------
// Deathmatch01::RespawnPilot  @ 4fc4020e  lines 2173-2261


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

EjectKillRetCodes __thiscall Deathmatch01::RespawnPilot(Deathmatch01 *this,int param_1,int param_2)

{
  Vector VVar1;
  bool bVar2;
  bool bVar3;
  char cVar4;
  int iVar5;
  Vector *pVVar6;
  char *pcVar7;
  int iVar8;
  char extraout_DL;
  undefined1 unaff_DI;
  Deathmatch01 *this_00;
  Vector local_1c;
  Vector local_10;
  
  bVar2 = GetRespawnInVehicle(this);
  if ((bVar2) || ((extraout_DL != '\0' && (param_1 == this[1]._padding_)))) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if ((extraout_DL != '\0') && (param_1 == this[1]._padding_)) {
    this->m_AICraftHandles[0xea] = this->m_AICraftHandles[0xe9];
    this[1]._padding_ = 0;
  }
  if (DMIsRaceSubtype[*(int *)(this->m_AILastWentForPowerup + 0xb2)] == false) {
    bVar3 = IsTeamplayOn();
    if ((!bVar3) || (param_2 < 1)) {
      pVVar6 = GetRandomSpawnpoint(&local_1c,-1);
    }
    else {
      pVVar6 = &local_10;
      local_10.x = (float)this->m_AITargetHandles[param_2 * 3 + 0x3d];
      local_10.y = (float)this->m_AITargetHandles[param_2 * 3 + 0x3e];
      local_10.z = (float)this->m_AITargetHandles[param_2 * 3 + 0x3f];
    }
    pVVar6 = GetPositionNear(&local_1c,*pVVar6,10.0,30.0);
  }
  else {
    if (0 < (int)this->m_TeamPos[param_2 + -1] + -1) {
      sprintf_s<64>(&TempODFName,"checkpoint%d");
      pVVar6 = &local_10;
      iVar5 = GetHandle(TempODFName);
      GetPosition(iVar5,pVVar6);
      goto LAB_4fc40353;
    }
    pVVar6 = GetSpawnpoint(&local_1c,0);
  }
  local_10.x = pVVar6->x;
  local_10.y = pVVar6->y;
  local_10.z = pVVar6->z;
LAB_4fc40353:
  if (param_2 - 1U < 0xf) {
    this->m_TeamPos[param_2 + -0x13] = *(float *)(this->m_AILastWentForPowerup + 0xa6);
  }
  VVar1.y = local_10.y;
  VVar1.x = local_10.x;
  VVar1.z = local_10.z;
  pVVar6 = GetPositionNear(&local_1c,VVar1,10.0,20.0);
  local_10.x = pVVar6->x;
  local_10.y = pVVar6->y;
  local_10.z = pVVar6->z;
  iVar5 = param_2;
  if (bVar2) {
    pcVar7 = GetNextVehicleODF(this,param_2,(bool)unaff_DI);
    pVVar6 = &local_10;
  }
  else {
    if ((char)this->m_AITargetHandles[0x3b] == '\0') {
      local_10.y = local_10.y + ___real_43480000;
    }
    pcVar7 = GetNextVehicleODF(this,param_2,(bool)unaff_DI);
    iVar8 = _strnicmp(pcVar7 + 1,"s",1);
    if (iVar8 == 0) {
      pVVar6 = &local_10;
    }
    else {
      this_00 = (Deathmatch01 *)param_2;
      cVar4 = GetRaceOfTeam(param_2);
      pVVar6 = &local_10;
      pcVar7 = GetInitialPlayerPilotODF(this_00,cVar4);
    }
  }
  iVar5 = BuildObject(pcVar7,iVar5,pVVar6);
  SetAsUser(iVar5,param_2);
  SetNoScrapFlagByHandle(iVar5);
  AddPilotByHandle(iVar5);
  SetRandomHeadingAngle(iVar5);
  if (!bVar2) {
    *(undefined1 *)((int)this->m_AICraftHandles + param_2 + 0x3c4) = 1;
  }
  if (param_2 == 0) {
    MakeInert(iVar5);
  }
  return DLLHandled;
}


// ---------------------------------------------------------------------
// Deathmatch01::DeadObject  @ 4fc3fdc5  lines 2264-2486


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

EjectKillRetCodes __thiscall
Deathmatch01::DeadObject(Deathmatch01 *this,int param_1,int param_2,bool param_3,bool param_4)

{
  int iVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  EjectKillRetCodes EVar6;
  int *piVar7;
  int iVar8;
  int unaff_EDI;
  char *pcVar9;
  int local_d0;
  char local_ca;
  char local_c9;
  char local_c8 [64];
  char local_88 [64];
  char local_48 [64];
  undefined4 local_8;
  
  local_8 = __security_cookie ^ (uint)(local_48 + 0x44);
  iVar8 = 0;
  GetObjInfo(param_1,Get_CFG,local_c8);
  iVar1 = this[1]._padding_;
  local_ca = '\0';
  local_c9 = '\0';
  if ((*(char *)((int)this->m_AICraftHandles + 999) != '\0') &&
     (iVar4 = this[1]._padding_, param_2 != iVar4)) {
    local_ca = param_1 == iVar4;
    local_c9 = '\x01';
    if ((bool)local_ca) {
      SetObjectiveOff(iVar4);
      local_d0 = param_2;
      bVar2 = IsAlive(&local_d0);
      if (!bVar2) {
        local_d0 = this[1]._padding_;
        bVar2 = IsAlive(&local_d0);
        if (!bVar2) goto LAB_4fc3febf;
      }
      iVar4 = local_d0;
      GetObjInfo(local_d0,Get_CFG,local_88);
      if (iVar4 != 0) {
        SetNewRabbit(this,iVar4);
      }
    }
  }
LAB_4fc3febf:
  iVar4 = GetTeamNum(param_1);
  local_d0 = 1;
  bVar2 = IsPlayer(param_2);
  if (((param_1 == param_2) || (0xe < iVar4 - 1U)) || ((int)this->m_TeamPos[iVar4 + -0x13] < 1)) {
    bVar3 = false;
  }
  else {
    bVar3 = *(int *)(this->m_AILastWentForPowerup + 0xa6) - (int)this->m_TeamPos[iVar4 + -0x13] <
            *(int *)(this->m_AILastWentForPowerup + 0xfe);
  }
  if (local_c9 == '\0') {
    if (bVar3) {
      local_d0 = -1;
      GetPlayerName(param_1);
      GetPlayerName(param_2);
      pcVar9 = "Spawn kill by %s on %s\n";
      goto LAB_4fc3ff85;
    }
  }
  else {
    local_d0 = -1;
    GetPlayerName(param_1);
    GetPlayerName(param_2);
    if (local_ca == '\0') {
      pcVar9 = "%s killed the wrong target, %s\n";
    }
    else {
      pcVar9 = "Rabbit kill by %s on %s\n";
    }
LAB_4fc3ff85:
    pcVar9 = GetBZCCLocalizedString("mission",pcVar9);
    sprintf_s<1024>(&TempMsgString,pcVar9);
    AddToMessagesBox(TempMsgString);
  }
  GetObjInfo(param_1,Get_GOClass,local_48);
  iVar5 = _stricmp(local_48,"CLASS_TORPEDO");
  if (iVar4 == 0) {
    return DoEjectPilot;
  }
  bVar3 = IsPowerup(param_1);
  if (bVar3) {
    return DoEjectPilot;
  }
  if (iVar5 == 0) {
    return DoEjectPilot;
  }
  if ((param_1 == param_2) || (bVar3 = IsAlly(param_1,param_2), bVar3)) {
    AddKills(param_2,-local_d0);
    if ((local_c9 != '\0') && (local_ca == '\0')) {
      local_d0 = 0;
    }
    if ((*(int *)(this->m_AILastWentForPowerup + 0xb2) != 0) &&
       (*(int *)(this->m_AILastWentForPowerup + 0xb2) != 7)) goto LAB_4fc400a4;
    iVar5 = local_d0 * -5;
  }
  else {
    AddKills(param_2,local_d0);
    if ((*(int *)(this->m_AILastWentForPowerup + 0xb2) != 0) &&
       (*(int *)(this->m_AILastWentForPowerup + 0xb2) != 7)) goto LAB_4fc400a4;
    iVar5 = local_d0 * 5;
  }
  AddScore(param_2,iVar5);
LAB_4fc400a4:
  if (!param_4) {
    if ((local_c9 != '\0') && (local_ca == '\0')) {
      local_d0 = 0;
    }
    AddDeaths(param_1,local_d0);
    if ((*(int *)(this->m_AILastWentForPowerup + 0xb2) == 0) ||
       (*(int *)(this->m_AILastWentForPowerup + 0xb2) == 7)) {
      AddScore(param_1,-local_d0);
    }
    if ((!bVar2) && (0 < (int)this->m_FRIENDLY_SPAWNPOINT_MIN_ENEMY)) {
      DoTaunt(unaff_EDI);
    }
  }
  if ((*(int *)(this->m_AILastWentForPowerup + 0xae) != 0) &&
     (iVar5 = GetKills(param_2), *(int *)(this->m_AILastWentForPowerup + 0xae) <= iVar5)) {
    NoteGameoverByKillLimit(param_2);
    DoGameover(10.0);
  }
  if (!param_4) {
    if ((!param_3) && ((*(char *)((int)this->m_AICraftHandles + 999) == '\0' || (local_ca == '\0')))
       ) {
      *(undefined1 *)((int)this->m_AICraftHandles + iVar4 + 0x3c4) = 1;
      return DoEjectPilot;
    }
    EVar6 = RespawnPilot(this,param_1,iVar4);
    return EVar6;
  }
  iVar4 = 0;
  if (0 < (int)this->m_FRIENDLY_SPAWNPOINT_MIN_ENEMY) {
    piVar7 = this->m_AITargetHandles + 0x9c;
    do {
      if (param_1 == *piVar7) {
        this->m_AITargetHandles[iVar4 + 0x9c] = 0;
        BuildBotCraft(this,iVar4);
        if (param_1 == iVar1) {
          this[1]._padding_ = this->m_AITargetHandles[iVar4 + 0x9c];
        }
        break;
      }
      iVar4 = iVar4 + 1;
      piVar7 = piVar7 + 1;
    } while (iVar4 < (int)this->m_FRIENDLY_SPAWNPOINT_MIN_ENEMY);
  }
  if (0 < (int)this->m_RaceCheckpointRadius) {
    piVar7 = &this[1]._padding_;
    do {
      if (param_1 == *piVar7) {
        SetupAnimal(this,iVar8);
        return DLLHandled;
      }
      iVar8 = iVar8 + 1;
      piVar7 = piVar7 + 1;
    } while (iVar8 < (int)this->m_RaceCheckpointRadius);
  }
  return DLLHandled;
}


// ---------------------------------------------------------------------
// Deathmatch01::PlayerEjected  @ 4fc3fd5c  lines 2489-2521


EjectKillRetCodes __thiscall Deathmatch01::PlayerEjected(Deathmatch01 *this,int param_1)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  EjectKillRetCodes EVar4;
  int extraout_EDX;
  
  if (*(int *)(this->m_AILastWentForPowerup + 0x9e) == 0) {
    LuaMission::PlayerEjected((LuaMission *)this,param_1);
  }
  bVar1 = IsPlayer(param_1);
  iVar3 = GetTeamNum(param_1);
  if (iVar3 == 0) {
    EVar4 = DLLHandled;
  }
  else {
    bVar2 = GetCanEject(this,param_1);
    if (bVar2) {
      *(undefined1 *)((int)this->m_AICraftHandles + extraout_EDX + 0x3c4) = 1;
    }
    EVar4 = DeadObject(this,param_1,param_1,!bVar2,(bool)('\x01' - bVar1));
  }
  return EVar4;
}


// ---------------------------------------------------------------------
// Deathmatch01::ObjectKilled  @ 4fc3fce6  lines 2524-2546


EjectKillRetCodes __thiscall Deathmatch01::ObjectKilled(Deathmatch01 *this,int param_1,int param_2)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  EjectKillRetCodes EVar4;
  undefined1 uVar5;
  undefined1 extraout_DL;
  
  if (*(int *)(this->m_AILastWentForPowerup + 0x9e) == 0) {
    LuaMission::ObjectKilled((LuaMission *)this,param_1,param_2);
  }
  bVar1 = IsPlayer(param_1);
  iVar3 = GetCurWorld();
  if (iVar3 == 0) {
    IsPerson(param_1);
    bVar2 = GetRespawnInVehicle(this);
    uVar5 = extraout_DL;
    if (bVar2) {
      uVar5 = true;
    }
    EVar4 = DeadObject(this,param_1,param_2,(bool)uVar5,(bool)('\x01' - bVar1));
  }
  else {
    EVar4 = DoEjectPilot;
  }
  return EVar4;
}


// ---------------------------------------------------------------------
// Deathmatch01::ObjectSniped  @ 4fc3fc92  lines 2549-2568


EjectKillRetCodes __thiscall Deathmatch01::ObjectSniped(Deathmatch01 *this,int param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  EjectKillRetCodes EVar3;
  
  if (*(int *)(this->m_AILastWentForPowerup + 0x9e) == 0) {
    LuaMission::ObjectSniped((LuaMission *)this,param_1,param_2);
  }
  bVar1 = IsPlayer(param_1);
  iVar2 = GetCurWorld();
  if (iVar2 == 0) {
    EVar3 = DeadObject(this,param_1,param_2,true,(bool)('\x01' - bVar1));
  }
  else {
    EVar3 = DoRespawnSafest;
  }
  return EVar3;
}


// ---------------------------------------------------------------------
// Deathmatch01::CreateObjectives  @ 4fc3fc08  lines 2571-2597


void __thiscall Deathmatch01::CreateObjectives(Deathmatch01 *this)

{
  int iVar1;
  char *pcVar2;
  
  ClearObjectives();
  iVar1 = *(int *)(this->m_AILastWentForPowerup + 0xb2);
  if (iVar1 != 0) {
    if (iVar1 == 1) {
      pcVar2 = "mpobjective_dmkoth.otf";
      goto LAB_4fc3fc88;
    }
    if (iVar1 == 2) {
      pcVar2 = "mpobjective_dmctf.otf";
      goto LAB_4fc3fc88;
    }
    if (iVar1 == 3) {
      pcVar2 = "mpobjective_dmloot.otf";
      goto LAB_4fc3fc88;
    }
    if ((4 < iVar1) && (iVar1 < 7)) {
      pcVar2 = "mpobjective_dmrace.otf";
      goto LAB_4fc3fc88;
    }
  }
  pcVar2 = "mpobjective_dm.otf";
LAB_4fc3fc88:
  AddObjective(pcVar2,-1,-1.0);
  return;
}


// ---------------------------------------------------------------------
// Deathmatch01::Load  @ 4fc3fa33  lines 2600-2666


bool __thiscall Deathmatch01::Load(Deathmatch01 *this,bool param_1)

{
  bool *pbVar1;
  bool bVar2;
  int iVar3;
  undefined1 unaff_DI;
  bool *pbVar4;
  char *pcVar5;
  
  bVar2 = LuaMission::Load((LuaMission *)this,param_1);
  pcVar5 = (char *)0x0;
  SetAutoGroupUnits(false);
  pbVar1 = this->m_AILastWentForPowerup + 0x96;
  pbVar4 = pbVar1;
  EnableHighTPS((int *)pbVar1);
  InitTaunts((int *)pbVar1,(int *)"Bots",(int *)pbVar4,pcVar5);
  WantBotKillMessages();
  pbVar1 = (bool *)this[1]._padding_;
  if (!param_1) {
    if (pbVar1 != (bool *)0x0) {
      if ((bVar2) && (bVar2 = Read(pbVar1,this[1]._padding_), bVar2)) {
        bVar2 = true;
      }
      else {
        bVar2 = false;
      }
    }
    if ((float *)this[1]._padding_ != (float *)0x0) {
      if ((bVar2) && (bVar2 = Read((float *)this[1]._padding_,this[1]._padding_), bVar2)) {
        bVar2 = true;
      }
      else {
        bVar2 = false;
      }
    }
    if ((int *)this[1]._padding_ != (int *)0x0) {
      if ((bVar2) && (bVar2 = Read((int *)this[1]._padding_,this[1]._padding_), bVar2)) {
        bVar2 = true;
      }
      else {
        bVar2 = false;
      }
    }
    if ((int *)this[1]._padding_ != (int *)0x0) {
      if ((bVar2) && (bVar2 = Read((int *)this[1]._padding_,this[1]._padding_), bVar2)) {
        bVar2 = true;
      }
      else {
        bVar2 = false;
      }
    }
    SetGravity((float)this->m_AICraftHandles[0xed] * __real_3f000000);
    PUPMgr::Load((bool)unaff_DI);
    return bVar2;
  }
  if (((pbVar1 != (bool *)0x0) && (this[1]._padding_ != 0)) && (iVar3 = 0, 0 < this[1]._padding_)) {
    do {
      *(undefined1 *)(iVar3 + this[1]._padding_) = 0;
      iVar3 = iVar3 + 1;
    } while (iVar3 < this[1]._padding_);
  }
  if (((this[1]._padding_ != 0) && (this[1]._padding_ != 0)) && (iVar3 = 0, 0 < this[1]._padding_))
  {
    do {
      *(undefined4 *)(this[1]._padding_ + iVar3 * 4) = 0;
      iVar3 = iVar3 + 1;
    } while (iVar3 < this[1]._padding_);
  }
  if (((this[1]._padding_ != 0) && (this[1]._padding_ != 0)) && (iVar3 = 0, 0 < this[1]._padding_))
  {
    do {
      *(undefined4 *)(this[1]._padding_ + iVar3 * 4) = 0;
      iVar3 = iVar3 + 1;
    } while (iVar3 < this[1]._padding_);
  }
  if (((this[1]._padding_ != 0) && (this[1]._padding_ != 0)) && (iVar3 = 0, 0 < this[1]._padding_))
  {
    do {
      *(undefined4 *)(this[1]._padding_ + iVar3 * 4) = 0;
      iVar3 = iVar3 + 1;
    } while (iVar3 < this[1]._padding_);
  }
  CreateObjectives(this);
  return true;
}


// ---------------------------------------------------------------------
// Deathmatch01::PostLoad  @ 4fc3f98c  lines 2670-2706


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool __thiscall Deathmatch01::PostLoad(Deathmatch01 *this,bool param_1)

{
  int iVar1;
  bool bVar2;
  undefined1 unaff_DI;
  char local_48 [64];
  undefined4 local_8;
  
  local_8 = __security_cookie ^ (uint)(local_48 + 0x44);
  bVar2 = LuaMission::PostLoad((LuaMission *)this,param_1);
  if (param_1) {
    return true;
  }
  ConvertHandles((int *)this[1]._padding_,this[1]._padding_);
  if ((bVar2) && (bVar2 = PUPMgr::PostLoad((bool)unaff_DI), bVar2)) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if (*(char *)((int)this->m_AICraftHandles + 999) != '\0') {
    iVar1 = this[1]._padding_;
    GetObjInfo(0,Get_CFG,local_48);
    GetObjInfo(iVar1,Get_CFG,local_48);
    if (iVar1 != 0) {
      SetNewRabbit(this,iVar1);
    }
  }
  return bVar2;
}


// ---------------------------------------------------------------------
// Deathmatch01::Save  @ 4fc3f8b9  lines 2710-2738


bool __thiscall Deathmatch01::Save(Deathmatch01 *this,bool param_1)

{
  bool bVar1;
  undefined1 unaff_BL;
  
  bVar1 = LuaMission::Save((LuaMission *)this,param_1);
  if (param_1) {
    return true;
  }
  if ((bool *)this[1]._padding_ != (bool *)0x0) {
    if ((bVar1) && (bVar1 = Write((bool *)this[1]._padding_,this[1]._padding_), bVar1)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
  }
  if ((float *)this[1]._padding_ != (float *)0x0) {
    if ((bVar1 == false) || (bVar1 = Write((float *)this[1]._padding_,this[1]._padding_), !bVar1)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
  }
  if ((int *)this[1]._padding_ != (int *)0x0) {
    if ((bVar1 == false) || (bVar1 = Write((int *)this[1]._padding_,this[1]._padding_), !bVar1)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
  }
  if ((int *)this[1]._padding_ != (int *)0x0) {
    if ((bVar1 != false) && (bVar1 = Write((int *)this[1]._padding_,this[1]._padding_), bVar1))
    goto LAB_4fc3f979;
    bVar1 = false;
  }
  if (bVar1 == false) {
    return false;
  }
LAB_4fc3f979:
  bVar1 = PUPMgr::Save((bool)unaff_BL);
  if (bVar1) {
    return true;
  }
  return false;
}


// ---------------------------------------------------------------------
// BuildMission  @ 4fc3f88e  lines 2776-2778


/* WARNING: Function: _EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: _EH_epilog3 replaced with injection: EH_epilog3 */

DLLBase * __cdecl BuildMission(void)

{
  Deathmatch01 *pDVar1;
  
  pDVar1 = operator_new(0xb544);
  pDVar1 = Deathmatch01::Deathmatch01(pDVar1);
  return (DLLBase *)pDVar1;
}

