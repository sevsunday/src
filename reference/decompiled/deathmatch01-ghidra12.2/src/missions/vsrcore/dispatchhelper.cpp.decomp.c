// Reconstructed by Ghidra from deathmatch01.dll + deathmatch01.pdb
// Original source file: /e:/github/vsr_dll_source/missions/vsrcore/dispatchhelper.cpp
// Functions are ordered by original source line. This is decompiler
// output, not the author's source: names/types come from the PDB,
// local variable names and control flow are reconstructed.


// ---------------------------------------------------------------------
// `dynamic_initializer_for_'TempDispatchBuffer''  @ 4fc017ed  lines 13-13


void __cdecl _dynamic_initializer_for__TempDispatchBuffer__(void)

{
  atexit(_dynamic_atexit_destructor_for__TempDispatchBuffer__);
  return;
}


// ---------------------------------------------------------------------
// DispatchHelper::~DispatchHelper  @ 4fc1f401  lines 23-25


void __thiscall DispatchHelper::~DispatchHelper(DispatchHelper *this)

{
  m_DispatchHelper = (DispatchHelper *)0x0;
  this->_padding_ = (int)_vftable_;
  std::
  vector<MorphObjectHelper::MorphObjectClass,std::allocator<MorphObjectHelper::MorphObjectClass>_>::
  _Tidy((vector<MorphObjectHelper::MorphObjectClass,std::allocator<MorphObjectHelper::MorphObjectClass>_>
         *)&this->DispatchList);
  return;
}


// ---------------------------------------------------------------------
// DispatchHelper::PostLoad  @ 4fc1f416  lines 48-73


bool __thiscall DispatchHelper::PostLoad(DispatchHelper *this,bool param_1)

{
  bool bVar1;
  int iVar2;
  DispatchClass *unaff_ESI;
  int *piVar3;
  int iVar4;
  DispatchClass *unaff_EDI;
  
  piVar3 = *(int **)&this->DispatchList;
  if (piVar3 != *(int **)&(this->DispatchList).field_0x4) {
    do {
      ConvertHandles(piVar3,1);
      ConvertHandles(piVar3 + 1,1);
      ConvertHandles(piVar3 + 2,1);
      piVar3 = piVar3 + 0x52;
    } while (piVar3 != *(int **)&(this->DispatchList).field_0x4);
  }
  iVar2 = (*(int *)&(this->DispatchList).field_0x4 - *(int *)&this->DispatchList) / 0x148;
  if ((int)(TempDispatchBuffer._4_4_ - TempDispatchBuffer._0_4_) / 0x148 == iVar2) {
    iVar4 = 0;
    if (0 < iVar2) {
      do {
        bVar1 = ::operator==(unaff_EDI,unaff_ESI);
        if (!bVar1) {
          FormatLogMessage("DispatchList Index Mismatch: %d");
          return true;
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < (*(int *)&(this->DispatchList).field_0x4 - *(int *)&this->DispatchList) /
                       0x148);
    }
  }
  else {
    FormatLogMessage("DispatchList Size Mismatch! Old: %d New: %d");
  }
  return true;
}


// ---------------------------------------------------------------------
// DispatchHelper::AddToDispatch  @ 4fc1f4d3  lines 91-368


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool __thiscall
DispatchHelper::AddToDispatch
          (DispatchHelper *this,int param_1,float param_2,bool param_3,int param_4,bool param_5,
          bool param_6,bool param_7,bool param_8)

{
  vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_> *this_00;
  byte *pbVar1;
  DispatchHelper *pDVar2;
  bool bVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  long lVar7;
  DispatchHelper *this_01;
  float unaff_ESI;
  float *unaff_EDI;
  int *piVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  undefined3 in_stack_00000015;
  bool *pbVar13;
  bool *pbVar14;
  char *pcVar15;
  undefined1 uVar16;
  char *pcVar17;
  char *pcVar18;
  undefined1 uVar19;
  undefined1 auStack_180 [2];
  char local_17e;
  char local_17d;
  float local_17c;
  float local_178;
  float local_174;
  float local_170;
  char *local_16c;
  int local_168;
  int local_164;
  BZ1Helper *local_160;
  DispatchHelper *local_15c;
  uint local_158;
  int local_154;
  char *local_150;
  uint local_14c;
  int local_148;
  char local_144 [64];
  bool local_104 [64];
  undefined1 local_c4 [64];
  char local_84 [64];
  char local_44 [64];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)auStack_180;
  local_154 = param_1;
  local_15c = this;
  memset(local_44,0,0x40);
  bVar3 = GetObjInfo(param_1,Get_GOClass,local_44);
  if (!bVar3) {
    return false;
  }
  uVar4 = Hash((char *)unaff_EDI,(uint)unaff_ESI);
  local_158 = uVar4;
  memset(local_c4,0,0x40);
  pbVar14 = local_104;
  pcVar15 = (char *)0x0;
  memset(pbVar14,0,0x40);
  pbVar13 = local_104;
  bVar3 = false;
  GetAndOpenODFNames((int)pbVar13,(char *)0x0,pbVar14,pcVar15);
  local_17e = '\x01';
  GetODFBool("CraftClass","DoDLLDispatch",&local_17e,(char *)0x1,pbVar13,bVar3);
  if (local_17e == '\0') {
    return false;
  }
  pcVar15 = GetLabel(param_1);
  local_150 = pcVar15;
  if ((pcVar15 != (char *)0x0) && (iVar5 = _strnicmp(pcVar15,"nodispatch",10), iVar5 == 0)) {
    return false;
  }
  pcVar18 = local_84;
  pcVar17 = (char *)0x0;
  memset(pcVar18,0,0x40);
  GetODFString("GameObjectClass","BZCClasslabel",(char *)0x40,local_84,0,pcVar18,pcVar17);
  local_14c = Hash((char *)unaff_EDI,(uint)unaff_ESI);
  pDVar2 = local_15c;
  if ((((((uVar4 != 0x4de8a34) && (uVar4 != 0x1c628d2e)) && (uVar4 != 0x83416d25)) &&
       (((uVar4 != 0xc864a6ef && (uVar4 != 0x1aefd513)) &&
        ((uVar4 != 0xa7275daa && ((uVar4 != 0x4a7aef92 && (uVar4 != 0x32493554)))))))) &&
      (uVar4 != 0xedb121ba)) && ((uVar4 != 0xf9df4e76 && (uVar4 != 0x25fd9ee0)))) {
    return false;
  }
  if (local_14c == 0x326aa115) {
    return false;
  }
  this_00 = &local_15c->DispatchList;
  for (piVar6 = *(int **)this_00; piVar6 != *(int **)&(local_15c->DispatchList).field_0x4;
      piVar6 = piVar6 + 0x52) {
    if (*piVar6 == param_1) {
      return false;
    }
  }
  std::
  vector<MorphObjectHelper::MorphObjectClass,std::allocator<MorphObjectHelper::MorphObjectClass>_>::
  _Resize<<lambda_6e1c0ab678e9364d699d8dd7ba7d9fb6>_>
            ((vector<MorphObjectHelper::MorphObjectClass,std::allocator<MorphObjectHelper::MorphObjectClass>_>
              *)this_00,(*(int *)&(local_15c->DispatchList).field_0x4 - *(int *)this_00) / 0x148 + 1
             ,(<lambda_6e1c0ab678e9364d699d8dd7ba7d9fb6>)this_00);
  piVar8 = (int *)(*(int *)this_00 + -0x148 +
                  ((*(int *)&(pDVar2->DispatchList).field_0x4 - *(int *)this_00) / 0x148) * 0x148);
  piVar6 = piVar8;
  memset(piVar8,0,0x148);
  local_16c = GetConfigODF((int)piVar6);
  *(bool *)(piVar8 + 9) = param_3;
  lVar7 = GetMaxHealth(param_1);
  piVar8[0x4d] = lVar7;
  lVar7 = GetMaxAmmo(param_1);
  piVar8[0x4e] = lVar7;
  local_148 = GetTeamNum(param_1);
  local_164 = local_148 * 0xa14;
  local_17d = '\x01';
  local_174 = 0.0;
  local_17c = 0.0;
  local_170 = 0.0;
  local_160 = BZ1Helper::m_BZ1Helper;
  local_178 = 0.0;
  fVar12 = 0.0;
  fVar10 = 0.0;
  fVar9 = 0.0;
  fVar11 = 0.0;
  if (local_16c != (char *)0x0) {
    bVar3 = OpenODF2((char *)unaff_EDI);
    if (bVar3) {
      memset(local_144,0,0x40);
      pcVar15 = local_16c;
      local_168 = 5;
      do {
        iVar5 = *(int *)((int)local_160->teamInfo[0].LimiterObject + local_164 + 0x18);
        if (iVar5 == 1) {
          pcVar18 = "EasyWeaponSlot%d";
LAB_4fc1f7e5:
          sprintf_s<64>(&local_144,pcVar18);
        }
        else {
          if (iVar5 == 2) {
            pcVar18 = "MediumWeaponSlot%d";
            goto LAB_4fc1f7e5;
          }
          if (iVar5 == 3) {
            pcVar18 = "HardWeaponSlot%d";
            goto LAB_4fc1f7e5;
          }
          if (iVar5 == 4) {
            pcVar18 = "ExtremeWeaponSlot%d";
            goto LAB_4fc1f7e5;
          }
        }
        GetODFFloat(pcVar15,local_144,"AIHuntChance",&local_174,0.0);
        GetODFFloat(pcVar15,local_144,"AIPatrolChance",&local_17c,0.0);
        GetODFFloat(pcVar15,local_144,"AISniperChance",&local_170,0.0);
        GetODFFloat(pcVar15,local_144,"AIEscortChance",&local_178,0.0);
        GetODFFloat(pcVar15,local_144,"AIRepairHealthRatio",(float *)(piVar8 + 0x4a),
                    ___real_3e19999a);
        GetODFFloat(pcVar15,local_144,"AIServiceChance",(float *)(piVar8 + 0x4b),0.0);
        local_168 = local_168 + -1;
      } while (local_168 != 0);
      ReadChanceValues(this_01,local_16c,"CloakChances",(float *)(piVar8 + 0x13),0.0);
      param_1 = local_154;
      pcVar15 = local_150;
      uVar4 = local_158;
    }
    if (0.0 <= local_174) {
      if (__real_3f800000 < local_174) {
        local_174 = __real_3f800000;
      }
    }
    else {
      local_174 = 0.0;
    }
    fVar12 = local_17c;
    fVar10 = local_170;
    fVar9 = local_178;
    fVar11 = local_174;
  }
  if (0.0 <= fVar12) {
    local_17c = fVar12;
    if (__real_3f800000 < fVar12) {
      local_17c = __real_3f800000;
    }
  }
  else {
    local_17c = 0.0;
  }
  if (0.0 <= fVar10) {
    local_170 = fVar10;
    if (__real_3f800000 < fVar10) {
      local_170 = __real_3f800000;
    }
  }
  else {
    local_170 = 0.0;
  }
  if (0.0 <= fVar9) {
    local_178 = fVar9;
    if (__real_3f800000 < fVar9) {
      local_178 = __real_3f800000;
    }
  }
  else {
    local_178 = 0.0;
  }
  local_174 = fVar11;
  if (uVar4 == 0x4a7aef92) {
    piVar8[7] = 1;
    goto LAB_4fc1fb15;
  }
  if (local_14c == 0x53179125) {
    piVar8[7] = 3;
    goto LAB_4fc1fb15;
  }
  if ((uVar4 == 0xf9df4e76) || (uVar4 == 0x25fd9ee0)) {
    piVar8[7] = 6;
    goto LAB_4fc1fb15;
  }
  if (!param_7) {
    if (pcVar15 == (char *)0x0) {
LAB_4fc1fa0d:
      iVar5 = GetRandomInt((int)unaff_EDI,(int)unaff_ESI);
      if (iVar5 == 0) {
        fVar12 = GetRandomFloat(1.0);
        if (fVar12 < local_174) goto LAB_4fc1fabb;
        fVar12 = GetRandomFloat(1.0);
        if (local_17c <= fVar12) {
LAB_4fc1faf2:
          fVar12 = GetRandomFloat(1.0);
          if (local_178 <= fVar12) goto LAB_4fc1fb15;
          goto LAB_4fc1fa47;
        }
      }
      else if (iVar5 == 1) {
        fVar12 = GetRandomFloat(1.0);
        if (local_17c <= fVar12) {
          fVar12 = GetRandomFloat(1.0);
          if (local_174 <= fVar12) goto LAB_4fc1faf2;
          goto LAB_4fc1fabb;
        }
      }
      else {
        if (iVar5 != 2) goto LAB_4fc1fb15;
        fVar12 = GetRandomFloat(1.0);
        if (fVar12 < local_178) goto LAB_4fc1fa47;
        fVar12 = GetRandomFloat(1.0);
        if (fVar12 < local_174) goto LAB_4fc1fabb;
        fVar12 = GetRandomFloat(1.0);
        if (local_17c <= fVar12) goto LAB_4fc1fb15;
      }
      piVar8[7] = 2;
      goto LAB_4fc1fb15;
    }
    iVar5 = _strnicmp(pcVar15,"hunter",6);
    if (iVar5 != 0) {
      iVar5 = _strnicmp(pcVar15,"patrol",6);
      if (iVar5 == 0) {
        piVar8[7] = 2;
        goto LAB_4fc1fb15;
      }
      iVar5 = _strnicmp(pcVar15,"escort",6);
      if (iVar5 != 0) goto LAB_4fc1fa0d;
LAB_4fc1fa47:
      piVar8[7] = 5;
      goto LAB_4fc1fb15;
    }
  }
LAB_4fc1fabb:
  piVar8[7] = 4;
LAB_4fc1fb15:
  fVar12 = GetRandomFloat(1.0);
  if (fVar12 < local_170) {
    memset(local_144,0,0x40);
    GetRace(param_1);
    sprintf_s<64>(&local_144,"%csuser");
    SetPilotClass(param_1,local_144);
  }
  pbVar1 = (byte *)((int)piVar8 + 0x25);
  uVar19 = 0x24;
  pcVar15 = "MorphTankClass";
  GetODFBool("MorphTankClass","HiddenWhenMorphed",(char *)pbVar1,(char *)0x0,(bool *)unaff_EDI,
             SUB41(unaff_ESI,0));
  GetODFBool("CraftClass","CanAICloak",&local_17d,(char *)(uint)*pbVar1,(bool *)pcVar15,(bool)uVar19
            );
  if (local_17d == '\0') {
    *pbVar1 = 0;
  }
  GetODFFloat("DeployableClass","timeDeploy",(char *)(piVar8 + 0x12),___real_40a00000,unaff_EDI,
              unaff_ESI);
  if ((((uVar4 == 0x83416d25) || (uVar4 == 0x1c628d2e)) || (uVar4 == 0xc864a6ef)) ||
     (uVar4 == 0x4de8a34)) {
    GetODFBool("CraftClass","CanAIFlee",(char *)((int)piVar8 + 0x27),_param_5,(bool *)unaff_EDI,
               SUB41(unaff_ESI,0));
    if (*(char *)((int)piVar8 + 0x27) != '\0') {
      GetODFFloat("CraftClass","AIFleeHealthRatio",(char *)(piVar8 + 0x49),___real_3f400000,
                  unaff_EDI,unaff_ESI);
    }
  }
  else {
    *(undefined1 *)((int)piVar8 + 0x27) = 0;
  }
  uVar19 = SUB41(unaff_ESI,0);
  if ((local_160->teamInfo[0].BaseSlotUseScrapHold[local_164 + 0x29] != false) || (param_8)) {
    uVar16 = 0xc0;
    pcVar15 = "CraftClass";
    GetODFBool("CraftClass","CanAIRepair",(char *)((int)piVar8 + 0x29),
               (char *)(uint)(piVar8[0x4d] != 0),(bool *)unaff_EDI,(bool)uVar19);
    GetODFBool("CraftClass","CanAIReload",(char *)(piVar8 + 10),(char *)(uint)(piVar8[0x4e] != 0),
               (bool *)pcVar15,(bool)uVar16);
  }
  iVar5 = _stricmp(local_84,"morphobject");
  if (iVar5 == 0) {
    *(undefined1 *)((int)piVar8 + 0x26) = 1;
    GetODFBool("MorphObjectClass","MorphIsAssault",(char *)((int)piVar8 + 0x2a),(char *)0x1,
               (bool *)unaff_EDI,(bool)uVar19);
  }
  fVar10 = __real_3f800000;
  fVar12 = (float)piVar8[0x4a];
  if (0.0 <= fVar12) {
    if (__real_3f800000 < fVar12) {
      fVar12 = __real_3f800000;
    }
  }
  else {
    fVar12 = 0.0;
  }
  piVar8[0x4a] = (int)fVar12;
  fVar12 = (float)piVar8[0x4b];
  fVar9 = 0.0;
  if (0.0 <= fVar12) {
    if (fVar12 <= fVar10) {
      fVar9 = fVar12;
    }
    else {
      fVar9 = fVar10;
    }
  }
  piVar8[0x4b] = (int)fVar9;
  *piVar8 = param_1;
  iVar5 = param_1;
  lVar7 = GetCurHealth(param_1);
  piVar8[0x50] = lVar7;
  fVar12 = GetEngageRange(iVar5);
  piVar8[0x11] = (int)fVar12;
  iVar5 = SecondsToTurns(param_2);
  fVar12 = __real_41200000;
  piVar8[0xc] = iVar5 + BZ1Helper::m_TurnCounter;
  iVar5 = SecondsToTurns(fVar12);
  piVar8[0xf] = iVar5;
  piVar8[0x51] = param_4;
  piVar8[6] = local_148;
  if (*pbVar1 != 0) {
    if (param_6) {
      Cloak(local_15c,param_1,param_4);
    }
    else {
      iVar5 = SecondsToTurns(param_2);
      piVar8[0xd] = iVar5 + BZ1Helper::m_TurnCounter;
    }
  }
  return true;
}


// ---------------------------------------------------------------------
// DispatchHelper::DeleteDispatchObject  @ 4fc1fe2b  lines 371-394


void __thiscall DispatchHelper::DeleteDispatchObject(DispatchHelper *this,int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  piVar2 = *(int **)&this->DispatchList;
  iVar3 = param_2 * 0xa14;
  while( true ) {
    if (piVar2 == *(int **)&(this->DispatchList).field_0x4) {
      return;
    }
    if (*piVar2 == param_1) break;
    piVar2 = piVar2 + 0x52;
  }
  iVar1 = piVar2[7];
  if (iVar1 == 2) {
    piVar2 = (int *)((int)BZ1Helper::m_BZ1Helper->teamInfo + iVar3 + 0xac);
    *piVar2 = *piVar2 + -1;
    return;
  }
  if (iVar1 == 4) {
    piVar2 = (int *)((int)BZ1Helper::m_BZ1Helper->teamInfo + iVar3 + 0xb0);
    *piVar2 = *piVar2 + -1;
    return;
  }
  if (iVar1 == 5) {
    piVar2 = (int *)((int)BZ1Helper::m_BZ1Helper->teamInfo + iVar3 + 0xb4);
    *piVar2 = *piVar2 + -1;
    return;
  }
  return;
}


// ---------------------------------------------------------------------
// DispatchHelper::Execute  @ 4fc1fe8a  lines 397-1857


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall DispatchHelper::Execute(DispatchHelper *this,BZ1Helper *param_1)

{
  Vector VVar1;
  Vector VVar2;
  Vector VVar3;
  Vector VVar4;
  Vector VVar5;
  Vector VVar6;
  Vector VVar7;
  Vector VVar8;
  Vector VVar9;
  Vector VVar10;
  Vector VVar11;
  Vector VVar12;
  Vector VVar13;
  Vector VVar14;
  Vector VVar15;
  Vector VVar16;
  Vector VVar17;
  Vector VVar18;
  Vector VVar19;
  Vector VVar20;
  _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
  _Var21;
  BZ1Helper *pBVar22;
  bool bVar23;
  int iVar24;
  _Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_> _Var25;
  _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
  _Var26;
  long lVar27;
  Vector *pVVar28;
  DispatchClass *pDVar29;
  DispatchClass *pDVar30;
  AiCommand AVar31;
  int iVar32;
  _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
  unaff_ESI;
  int *piVar33;
  float *pfVar34;
  _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
  _Var35;
  undefined4 *puVar36;
  Vector *unaff_EDI;
  BZ1Helper *pBVar37;
  _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
  *p_Var38;
  vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_> *pvVar39;
  float fVar40;
  float fVar41;
  char *pcVar42;
  Vector *__return_storage_ptr__;
  undefined1 auStack_758 [3];
  char cStack_755;
  undefined8 uStack_754;
  vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_> *pvStack_74c;
  _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
  _Stack_748;
  float *local_744;
  int iStack_740;
  _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
  _Stack_73c;
  _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
  _Stack_738;
  _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
  _Stack_734;
  int iStack_730;
  BZ1Helper *local_72c;
  undefined4 local_728;
  DispatchHelper *pDStack_724;
  _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
  local_720;
  Vector VStack_71c;
  int iStack_710;
  int local_70c;
  _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
  _Stack_708;
  int local_704;
  _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
  _Stack_700;
  _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
  _Stack_6fc;
  Vector *pVStack_6f8;
  float fStack_6f4;
  float fStack_6f0;
  undefined1 auStack_6ec [8];
  float fStack_6e4;
  _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
  _Stack_6e0;
  _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
  _Stack_6dc;
  _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
  _Stack_6d8;
  _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
  _Stack_6d4;
  _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
  _Stack_6d0;
  _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
  _Stack_6cc;
  _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
  _Stack_6c8;
  _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
  _Stack_6c4;
  _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
  a_Stack_6c0 [2];
  double dStack_6b8;
  undefined4 uStack_6b0;
  undefined4 uStack_6ac;
  Vector VStack_6a8;
  undefined4 uStack_69c;
  undefined4 uStack_698;
  undefined4 uStack_694;
  float fStack_690;
  float fStack_68c;
  float fStack_688;
  undefined4 uStack_684;
  undefined4 uStack_680;
  undefined4 uStack_67c;
  undefined4 uStack_678;
  undefined4 uStack_674;
  float fStack_670;
  undefined4 uStack_66c;
  undefined4 uStack_668;
  undefined4 uStack_664;
  undefined4 uStack_660;
  undefined4 uStack_65c;
  undefined4 uStack_658;
  Vector VStack_654;
  Vector aVStack_648 [2];
  Vector VStack_630;
  Vector *pVStack_624;
  float fStack_620;
  float fStack_61c;
  float afStack_618 [3];
  Vector VStack_60c;
  Vector VStack_600;
  float afStack_5f4 [3];
  Vector VStack_5e8;
  Vector VStack_5dc;
  Vector VStack_5d0;
  Vector VStack_5c4;
  Vector VStack_5b8;
  Vector VStack_5ac;
  Vector VStack_5a0;
  Vector VStack_594;
  Vector VStack_588;
  Vector VStack_57c;
  Vector VStack_570;
  Vector aVStack_564 [2];
  Vector VStack_54c;
  Vector VStack_540;
  Vector aVStack_534 [2];
  Vector VStack_51c;
  Vector aVStack_510 [3];
  _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
  a_Stack_4ec [142];
  char cStack_2b4;
  float *pfStack_264;
  int iStack_25c;
  char acStack_94 [4];
  char local_90 [60];
  char acStack_54 [72];
  uint local_c;
  
  local_c = __security_cookie ^ (uint)auStack_758;
  local_728 = param_1;
  uStack_754._0_4_ = (DispatchClass *)CONCAT13(BZ1Helper::Logging,(undefined3)uStack_754);
  local_720._Ptr = (DispatchClass *)this;
  local_70c = ObjectHelper::GetNumHandles(param_1->m_ObjectHelper);
  local_704 = BuildingHelper::GetNumBuildingObjects(BuildingHelper::m_BuildingHelper);
  local_744 = &param_1->teamInfo[0].m_CPUBuildPodMaxDelay;
  local_72c = (BZ1Helper *)0x0;
  do {
    pBVar37 = local_72c;
    pfVar34 = local_744;
    if (*local_744 != ___real_00000000) {
      if (*(char *)((int)local_744 + 0xc5) != '\0') {
        if (local_744[-0x45] != 0.0) {
          iVar24 = SecondsToTurns(((Vector *)(local_744 + 1))->x);
          if (BZ1Helper::m_TurnCounter % iVar24 == 0) {
            fVar40 = GetRandomFloat(1.0);
            uStack_754 = (double)CONCAT44(fVar40,uStack_754._0_4_);
            if (fVar40 < *pfVar34) {
              memset(local_90,0,0x40);
              bVar23 = GetBuildItem(0,(char *)0x4,(int *)"daywrecker",0,(char *)0x0,
                                    (char *)unaff_EDI,(char *)unaff_ESI._Ptr);
              if (bVar23) {
                iVar24 = (*misnImport.GetScrap)((int)pBVar37);
                if (-1 < iVar24) {
                  bVar23 = DoesODFExist(local_90);
                  if (bVar23) {
                    iVar24 = BuildingHelper::GetNumBuildings
                                       (BuildingHelper::m_BuildingHelper,(int)pBVar37,4,false,true,
                                        false,0,(char *)0x0,(char *)0x0);
                    pBVar22 = local_72c;
                    if (0 < iVar24) {
                      fStack_6f4 = 0.0;
                      fStack_6f0 = 0.0;
                      auStack_6ec._0_4_ = 0.0;
                      iVar24 = BuildingHelper::GetRandomBuilding
                                         (BuildingHelper::m_BuildingHelper,(int)local_72c,4,true,
                                          true,true,0,(char *)0x0,(char *)0x0,0.0,(Vector)ZEXT812(0)
                                         );
                      GetPosition(iVar24,(Vector *)(auStack_6ec + 4));
                      VStack_71c.x = 0.0;
                      if (0 < local_70c) {
                        iVar24 = 0;
                        do {
                          iVar32 = *(int *)&local_728->m_ObjectHelper->HandleList + iVar24;
                          if (*(BZ1Helper **)(iVar32 + 0x1c) == pBVar22) {
                            fVar40 = *(float *)(iVar32 + 0x24);
                            uStack_754 = (double)CONCAT44(fVar40,uStack_754._0_4_);
                            dStack_6b8 = (double)fVar40;
                            fVar41 = GetDistance3DSquared(unaff_EDI,(Vector *)unaff_ESI._Ptr);
                            pfVar34 = local_744;
                            fVar40 = (float)((float10)dStack_6b8 * (float10)dStack_6b8);
                            uStack_754 = (double)CONCAT44(fVar40,uStack_754._0_4_);
                            if (fVar41 < fVar40) {
                              VVar18.y = fStack_6e4;
                              VVar18.x = (float)auStack_6ec._4_4_;
                              VVar18.z = (float)_Stack_6e0._Ptr;
                              BZ1Helper::BuildAt(local_728,(int)local_744[-0x45],local_90,VVar18,1);
                              pBVar37 = local_72c;
                              goto LAB_4fc20094;
                            }
                          }
                          VStack_71c.x = (float)((int)&((Vector *)VStack_71c.x)->x + 1);
                          iVar24 = iVar24 + 0x5c;
                        } while ((int)VStack_71c.x < local_70c);
                      }
                      pfVar34 = local_744;
                      pBVar37 = pBVar22;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
LAB_4fc20094:
    _Var26._Ptr = local_720._Ptr;
    local_72c = (BZ1Helper *)((int)&pBVar37->_padding_ + 1);
    local_744 = pfVar34 + 0x285;
  } while ((int)local_72c < 0x10);
  pvVar39 = (vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_> *)
            &(local_720._Ptr)->DispatchTarget;
  _Stack_748._Ptr = (DispatchClass *)pvVar39;
  std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
  ::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
            ((_Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
              *)((int)&uStack_754 + 4),(DispatchClass *)(local_720._Ptr)->FleeTarget,
             (_Container_base0 *)pvVar39);
  __return_storage_ptr__ = uStack_754._4_4_;
  std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
  ::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
            (&_Stack_734,(DispatchClass *)(_Var26._Ptr)->FleeTarget,(_Container_base0 *)pvVar39);
  std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
  ::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
            (&_Stack_708,*(DispatchClass **)&pvVar39->field_0x0,(_Container_base0 *)pvVar39);
  _Var25 = std::
           remove_if<std::_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>,bool_(__cdecl*)(DispatchHelper::DispatchClass_const_&)>
                     ((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                       )_Stack_708._Ptr,
                      (_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                       )_Stack_734._Ptr,(_func___cdecl_bool_DispatchClass_ptr *)unaff_EDI);
  std::vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>::erase
            (pvVar39,(DispatchClass *)&_Stack_6fc,*(DispatchClass **)_Var25);
  std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
  ::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
            ((_Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
              *)(auStack_758 + -4),*(DispatchClass **)&pvVar39->field_0x0,
             (_Container_base0 *)pvVar39);
  std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
  ::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
            (&local_720,(DispatchClass *)(_Var26._Ptr)->FleeTarget,(_Container_base0 *)pvVar39);
  if (unaff_ESI._Ptr != local_720._Ptr) {
    do {
      std::
      _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
      ::
      _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                (&_Stack_6e0,*(DispatchClass **)&pvVar39->field_0x0,(_Container_base0 *)pvVar39);
      _Var26._Ptr = (DispatchClass *)(((int)unaff_ESI._Ptr - (int)_Stack_6e0._Ptr) / 0x148);
      _Stack_748._Ptr = _Var26._Ptr;
      local_744 = (float *)GetTeamNum((unaff_ESI._Ptr)->DispatchObject);
      iStack_740 = (int)local_72c->teamInfo + (int)local_744 * 0xa14 + -0x90;
      GetPosition((unaff_ESI._Ptr)->DispatchObject,&VStack_71c);
      bVar23 = IsAround(*(int *)&(unaff_ESI._Ptr)->DispatchTarget);
      local_728 = (BZ1Helper *)CONCAT31(local_728._1_3_,bVar23);
      iVar24 = GetIndependence((unaff_ESI._Ptr)->DispatchObject);
      local_728 = (BZ1Helper *)CONCAT13(iVar24 != 0,(uint3)local_728);
      local_704 = GetCurrentWho((unaff_ESI._Ptr)->DispatchObject);
      if ((float *)(unaff_ESI._Ptr)->CurrTeam != local_744) {
        iVar24 = (unaff_ESI._Ptr)->DispatchType;
        iVar32 = (unaff_ESI._Ptr)->CurrTeam * 0xa14;
        if (iVar24 == 2) {
          piVar33 = (int *)((int)local_72c->teamInfo + iVar32 + 0xac);
          *piVar33 = *piVar33 + -1;
          *(int *)(iStack_740 + 0x13c) = *(int *)(iStack_740 + 0x13c) + 1;
        }
        else if (iVar24 == 4) {
          piVar33 = (int *)((int)local_72c->teamInfo + iVar32 + 0xb0);
          *piVar33 = *piVar33 + -1;
          *(int *)(iStack_740 + 0x140) = *(int *)(iStack_740 + 0x140) + 1;
        }
        else if (iVar24 == 5) {
          piVar33 = (int *)((int)local_72c->teamInfo + iVar32 + 0xb4);
          *piVar33 = *piVar33 + -1;
          *(int *)(iStack_740 + 0x144) = *(int *)(iStack_740 + 0x144) + 1;
        }
        ClearDispatch(pDStack_724,(int)_Var26._Ptr);
        (unaff_ESI._Ptr)->CurrTeam = (int)local_744;
      }
      pfVar34 = local_744;
      bVar23 = IsPlayer((unaff_ESI._Ptr)->DispatchObject);
      if (!bVar23) {
        iVar24 = GetPlayerHandle((int)pfVar34);
        if ((iVar24 != 0) || ((local_728._3_1_ != '\x01' && ((unaff_ESI._Ptr)->DispatchState != 2)))
           ) goto LAB_4fc223b4;
        iVar24 = (unaff_ESI._Ptr)->DispatchState;
        _Var26._Ptr = unaff_ESI._Ptr;
        if (iVar24 == 0) {
          if ((unaff_ESI._Ptr)->IdleTime <= BZ1Helper::m_TurnCounter) {
            bVar23 = IsIdle((unaff_ESI._Ptr)->DispatchObject);
            _Var26._Ptr = unaff_ESI._Ptr;
            if ((bVar23) &&
               (((unaff_ESI._Ptr)->SkipAIPCheck != false || (*(char *)(iStack_740 + 0x1ae) != '\0'))
               )) {
              iVar24 = (unaff_ESI._Ptr)->DispatchType;
              if (iVar24 == 1) {
                iVar24 = (*misnImport.GetNearestEnemy)((unaff_ESI._Ptr)->DispatchObject);
                GetPosition(iVar24,&VStack_5dc);
                uStack_754 = (double)((unaff_ESI._Ptr)->EngageRange +
                                     (float)___real_4049000000000000);
                fVar41 = GetDistance2DSquared<Vector,Vector>(__return_storage_ptr__,unaff_EDI);
                fVar40 = (float)((float10)uStack_754 * (float10)uStack_754);
                uStack_754 = (double)CONCAT44(uStack_754._4_4_,fVar40);
                _Var26._Ptr = unaff_ESI._Ptr;
                if (fVar40 < fVar41) {
                  _Stack_738._Ptr =
                       (DispatchClass *)GetRandomInt((int)__return_storage_ptr__,(int)unaff_EDI);
                  iStack_730 = GetRandomInt((int)__return_storage_ptr__,(int)unaff_EDI);
                  _Var35._Ptr = (DispatchClass *)0x0;
                  *(undefined4 *)&(unaff_ESI._Ptr)->DispatchTarget = 0;
                  _Stack_73c._Ptr = (DispatchClass *)0x0;
                  _Var26._Ptr = (DispatchClass *)
                                GetRandomTeam(1,1,SUB41(__return_storage_ptr__,0),SUB41(unaff_EDI,0)
                                             );
                  if ((int)_Var26._Ptr < 0) {
                    _Var26._Ptr = (DispatchClass *)
                                  GetRandomTeam(0,1,SUB41(__return_storage_ptr__,0),
                                                SUB41(unaff_EDI,0));
                  }
                  _Stack_734._Ptr = (DispatchClass *)0x0;
                  if (-1 < (int)_Var26._Ptr) {
                    _Stack_734._Ptr = _Var26._Ptr;
                  }
                  _Stack_748._Ptr = (DispatchClass *)0x0;
                  pVStack_6f8 = (Vector *)0x0;
                  fStack_6f4 = 0.0;
                  fStack_6f0 = 0.0;
                  if (cStack_755 != '\0') {
                    std::
                    _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                    ::
                    _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                              (&_Stack_6d0,*(DispatchClass **)&pvVar39->field_0x0,
                               (_Container_base0 *)pvVar39);
                    FormatLogMessage(
                                    "Index is: %d, DispatchMode is: %d, DispatchMethod is: %d, RandomTargetTeam: %d"
                                    );
                  }
                  iVar24 = (int)_Stack_734._Ptr * 0xa14;
                  _Var26._Ptr = *(DispatchClass **)((int)local_72c->teamInfo + iVar24 + 0xc);
                  if ((((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                         )_Var26._Ptr ==
                        (_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                         )0x0) &&
                      (_Var26._Ptr = *(DispatchClass **)((int)local_72c->teamInfo + iVar24 + 0x10),
                      (_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                       )_Var26._Ptr ==
                      (_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                       )0x0)) &&
                     (_Var26._Ptr = *(DispatchClass **)((int)local_72c->teamInfo + iVar24 + 0x18),
                     (_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                      )_Var26._Ptr ==
                     (_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                      )0x0)) {
                    _Var26._Ptr = *(DispatchClass **)((int)local_72c->teamInfo + iVar24 + 0x14);
                    if ((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                         )_Var26._Ptr !=
                        (_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                         )0x0) goto LAB_4fc2151a;
                  }
                  else {
LAB_4fc2151a:
                    _Stack_748._Ptr = _Var26._Ptr;
                    if ((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                         )_Var26._Ptr !=
                        (_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                         )0x0) {
                      GetPosition((int)_Var26._Ptr,&VStack_5d0);
                      pVStack_6f8 = (Vector *)VStack_5d0.x;
                      fStack_6f4 = VStack_5d0.y;
                      fStack_6f0 = VStack_5d0.z;
                      _Var35._Ptr = _Stack_73c._Ptr;
                    }
                  }
                  _Var21._Ptr = _Stack_748._Ptr;
                  if ((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                       )_Stack_738._Ptr ==
                      (_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                       )0x0) {
                    _Stack_748._Ptr = (DispatchClass *)0x0;
                    if (iStack_730 == 0) {
                      if (0 < (int)_Stack_708._Ptr) {
                        _Stack_738._Ptr = _Stack_708._Ptr;
                        _Stack_734._Ptr = (DispatchClass *)0x0;
                        do {
                          if ((int)_Stack_708._Ptr < 2) {
LAB_4fc21d85:
                            puVar36 = (undefined4 *)
                                      ((int)(_Stack_734._Ptr)->CloakChance +
                                      *(int *)&BuildingHelper::m_BuildingHelper->BuildingList +
                                      -0x4c);
                            p_Var38 = a_Stack_4ec;
                            for (iVar24 = 0x116; _Var35._Ptr = a_Stack_4ec[0]._Ptr, iVar24 != 0;
                                iVar24 = iVar24 + -1) {
                              p_Var38->_Ptr = (DispatchClass *)*puVar36;
                              puVar36 = puVar36 + 1;
                              p_Var38 = p_Var38 + 1;
                            }
                            if (((pfStack_264 == local_744) && (cStack_2b4 != '\0')) &&
                               (0 < iStack_25c)) {
                              _Var26._Ptr = (DispatchClass *)
                                            GetDistance2DSquared<Vector,Vector>
                                                      (__return_storage_ptr__,unaff_EDI);
                              uStack_754 = (double)CONCAT44(uStack_754._4_4_,_Var26._Ptr);
                              if ((float)_Stack_748._Ptr < (float)_Var26._Ptr) {
                                _Stack_73c._Ptr = _Var35._Ptr;
                                _Stack_748._Ptr = _Var26._Ptr;
                                goto LAB_4fc21dfc;
                              }
                            }
                            _Var35._Ptr = _Stack_73c._Ptr;
                          }
                          else {
                            fVar40 = GetRandomFloat(1.0);
                            if (fVar40 < __real_3f000000) goto LAB_4fc21d85;
                          }
LAB_4fc21dfc:
                          _Stack_734._Ptr = (DispatchClass *)(_Stack_734._Ptr[3].CloakChance + 0xd);
                          _Stack_738._Ptr =
                               (DispatchClass *)((int)&_Stack_738._Ptr[-1].CloakPriority + 3);
                        } while ((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                  )_Stack_738._Ptr !=
                                 (_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                  )0x0);
                        goto LAB_4fc21e19;
                      }
LAB_4fc21f4d:
                      _Var26._Ptr = unaff_ESI._Ptr;
                      iVar24 = SecondsToTurns(___real_40a00000);
                      (unaff_ESI._Ptr)->IdleTime = iVar24 + BZ1Helper::m_TurnCounter;
                      if (cStack_755 == '\0') goto LAB_4fc21fae;
                      std::
                      _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                      ::
                      _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                (&_Stack_6fc,*(DispatchClass **)&pvStack_74c->field_0x0,
                                 (_Container_base0 *)pvStack_74c);
LAB_4fc21f94:
                      FormatLogMessage(
                                      "Index is: %d Mode is: %d Method is: %d No Valid Target, IdleTime: %d"
                                      );
                    }
                    else {
                      if (iStack_730 == 1) {
                        auStack_6ec._0_4_ = 0.0;
                        pVVar28 = (Vector *)auStack_6ec;
                        auStack_6ec._4_4_ = 0.0;
                        fStack_6e4 = 0.0;
LAB_4fc21cfe:
                        _Var35._Ptr = (DispatchClass *)
                                      BuildingHelper::GetRandomBuilding
                                                (BuildingHelper::m_BuildingHelper,(int)local_744,1,
                                                 true,true,true,0,(char *)0x0,(char *)0x0,0.0,
                                                 *pVVar28);
                        _Stack_73c._Ptr = _Var35._Ptr;
LAB_4fc21e19:
                        if ((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                             )_Var35._Ptr ==
                            (_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                             )0x0) goto LAB_4fc21f4d;
                      }
                      else {
                        if (iStack_730 != 2) goto LAB_4fc21f4d;
                        _Var35._Ptr = *(DispatchClass **)(iStack_740 + 0x9c);
                        _Stack_73c._Ptr = _Var35._Ptr;
                        if ((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                             )_Var35._Ptr ==
                            (_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                             )0x0) {
                          _Var35._Ptr = *(DispatchClass **)(iStack_740 + 0xa0);
                          _Stack_73c._Ptr = _Var35._Ptr;
                          if ((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                               )_Var35._Ptr ==
                              (_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                               )0x0) {
                            _Var35._Ptr = *(DispatchClass **)(iStack_740 + 0xa8);
                            _Stack_73c._Ptr = _Var35._Ptr;
                            if ((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                 )_Var35._Ptr ==
                                (_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                 )0x0) {
                              _Var35._Ptr = *(DispatchClass **)(iStack_740 + 0xa4);
                              _Stack_73c._Ptr = _Var35._Ptr;
                              if ((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                   )_Var35._Ptr ==
                                  (_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                   )0x0) {
                                VStack_6a8.x = 0.0;
                                VStack_6a8.y = 0.0;
                                VStack_6a8.z = 0.0;
                                pVVar28 = &VStack_6a8;
                                _Stack_73c._Ptr = (DispatchClass *)0x0;
                                goto LAB_4fc21cfe;
                              }
                            }
                          }
                        }
                      }
                      if (*(int *)&(unaff_ESI._Ptr)->DispatchTarget == 0) {
                        *(DispatchClass **)&(unaff_ESI._Ptr)->DispatchTarget = _Var35._Ptr;
                      }
                      GetPosition(*(int *)&(unaff_ESI._Ptr)->DispatchTarget,&VStack_57c);
                      uStack_754 = (double)CONCAT44(uStack_754._4_4_,unaff_ESI._Ptr);
                      VVar6.y = fStack_6f0;
                      VVar6.x = fStack_6f4;
                      VVar6.z = VStack_57c.x;
                      VVar15.y = VStack_57c.z;
                      VVar15.x = VStack_57c.y;
                      VVar15.z = ___real_42480000;
                      pVVar28 = GetPositionNearOrFar
                                          (pVStack_6f8,VVar6,VVar15,___real_437a0000,
                                           (float)__return_storage_ptr__,SUB41(unaff_EDI,0));
                      *(float *)((int)uStack_754._0_4_ + 0xc) = pVVar28->x;
                      *(float *)((int)uStack_754._0_4_ + 0x10) = pVVar28->y;
                      *(float *)((int)uStack_754._0_4_ + 0x14) = pVVar28->z;
                      Goto((unaff_ESI._Ptr)->DispatchObject,&(unaff_ESI._Ptr)->DispatchSpot,0);
                      _Var26._Ptr = unaff_ESI._Ptr;
                      fVar40 = GetRandomFloat(__real_41200000);
                      (unaff_ESI._Ptr)->RandomDist = fVar40 + (float)___real_4024000000000000;
                      (_Var26._Ptr)->IdleTime = 0;
                      (_Var26._Ptr)->DispatchState = 1;
                      if (cStack_755 == '\0') goto LAB_4fc21fae;
                      memset(TempGetODFName,0,0x40);
                      GetODFName((int)__return_storage_ptr__,(char *)unaff_EDI);
                      std::
                      _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                      ::
                      _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                (&_Stack_700,*(DispatchClass **)&pvStack_74c->field_0x0,
                                 (_Container_base0 *)pvStack_74c);
LAB_4fc2185f:
                      FormatLogMessage(
                                      "Index is: %d Mode is: %d Method is: %d Spot is: %f %f %f Target Is: \'%s\'"
                                      );
                    }
                  }
                  else if ((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                            )_Stack_738._Ptr ==
                           (_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                            )0x1) {
                    _Stack_748._Ptr = (DispatchClass *)0x7f7fffff;
                    iVar24 = ScrapHelper::GetNumScrapObjects(ScrapHelper::m_ScrapHelper);
                    if (iStack_730 == 0) {
                      iVar32 = 0;
                      if (0 < iVar24) {
                        do {
                          if (iVar24 < 2) {
LAB_4fc219e6:
                            _Stack_738._Ptr =
                                 *(DispatchClass **)
                                  (*(int *)&ScrapHelper::m_ScrapHelper->ScrapList + iVar32 * 4);
                            GetPosition((int)_Stack_738._Ptr,&VStack_5a0);
                            _Var26._Ptr = (DispatchClass *)
                                          GetDistance2DSquared<Vector,Vector>
                                                    (__return_storage_ptr__,unaff_EDI);
                            uStack_754 = (double)CONCAT44(uStack_754._4_4_,_Var26._Ptr);
                            if ((float)_Var26._Ptr < (float)_Stack_748._Ptr) {
                              *(DispatchClass **)&(unaff_ESI._Ptr)->DispatchTarget = _Stack_738._Ptr
                              ;
                              _Stack_748._Ptr = _Var26._Ptr;
                            }
                          }
                          else {
                            fVar40 = GetRandomFloat(1.0);
                            if (fVar40 < __real_3f000000) goto LAB_4fc219e6;
                          }
                          iVar32 = iVar32 + 1;
                        } while (iVar32 < iVar24);
                      }
                    }
                    else if (iStack_730 == 1) {
                      if (0 < iVar24) {
                        iVar24 = GetRandomInt((int)__return_storage_ptr__,(int)unaff_EDI);
                        *(undefined4 *)&(unaff_ESI._Ptr)->DispatchTarget =
                             *(undefined4 *)
                              (*(int *)&ScrapHelper::m_ScrapHelper->ScrapList + iVar24 * 4);
                      }
                    }
                    else if (iStack_730 == 2) {
                      _Stack_748._Ptr = (DispatchClass *)0x0;
                      iVar32 = 0;
                      if (0 < iVar24) {
                        do {
                          if (iVar24 < 2) {
LAB_4fc21935:
                            _Stack_738._Ptr =
                                 *(DispatchClass **)
                                  (*(int *)&ScrapHelper::m_ScrapHelper->ScrapList + iVar32 * 4);
                            GetPosition((int)_Stack_738._Ptr,&VStack_5ac);
                            _Var26._Ptr = (DispatchClass *)
                                          GetDistance2DSquared<Vector,Vector>
                                                    (__return_storage_ptr__,unaff_EDI);
                            uStack_754 = (double)CONCAT44(uStack_754._4_4_,_Var26._Ptr);
                            if ((float)_Stack_748._Ptr < (float)_Var26._Ptr) {
                              *(DispatchClass **)&(unaff_ESI._Ptr)->DispatchTarget = _Stack_738._Ptr
                              ;
                              _Stack_748._Ptr = _Var26._Ptr;
                            }
                          }
                          else {
                            fVar40 = GetRandomFloat(1.0);
                            if (fVar40 < __real_3f000000) goto LAB_4fc21935;
                          }
                          iVar32 = iVar32 + 1;
                        } while (iVar32 < iVar24);
                      }
                    }
                    GetPosition(*(int *)&(unaff_ESI._Ptr)->DispatchTarget,&VStack_594);
                    uStack_754 = (double)CONCAT44(uStack_754._4_4_,unaff_ESI._Ptr);
                    VVar10.y = VStack_594.y;
                    VVar10.x = VStack_594.x;
                    VVar10.z = VStack_594.z;
                    pVVar28 = GetPositionNear(&VStack_51c,VVar10,__real_41200000,___real_42480000);
                    *(float *)((int)uStack_754._0_4_ + 0xc) = pVVar28->x;
                    *(float *)((int)uStack_754._0_4_ + 0x10) = pVVar28->y;
                    *(float *)((int)uStack_754._0_4_ + 0x14) = pVVar28->z;
                    if (cStack_755 != '\0') {
                      std::
                      _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                      ::
                      _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                (&_Stack_6c4,*(DispatchClass **)&pvStack_74c->field_0x0,
                                 (_Container_base0 *)pvStack_74c);
                      FormatLogMessage("Index is: %d Mode is: %d Method is: %d Spot is: %f %f %f");
                    }
                    bVar23 = IsNullVector((unaff_ESI._Ptr)->DispatchSpot);
                    if (bVar23) {
                      dStack_6b8 = (double)((ulonglong)dStack_6b8 & 0xffffffff);
                      uStack_6b0 = 0;
                      uStack_6ac = 0;
                      uStack_754._0_4_ = unaff_ESI._Ptr;
                      iVar24 = BZ1Helper::GetRandomObject
                                         (local_72c,-1,0,false,0,false,true,true,0,(char *)0x0,
                                          (char *)0x0,0.0,(Vector)ZEXT812(0));
                      *(int *)&(uStack_754._0_4_)->DispatchTarget = iVar24;
                      GetPosition(*(int *)&(unaff_ESI._Ptr)->DispatchTarget,&VStack_588);
                      uStack_754 = (double)CONCAT44(uStack_754._4_4_,unaff_ESI._Ptr);
                      VVar11.y = VStack_588.y;
                      VVar11.x = VStack_588.x;
                      VVar11.z = VStack_588.z;
                      pVVar28 = GetPositionNear(aVStack_510,VVar11,__real_41200000,___real_42480000)
                      ;
                      *(float *)((int)uStack_754._0_4_ + 0xc) = pVVar28->x;
                      *(float *)((int)uStack_754._0_4_ + 0x10) = pVVar28->y;
                      *(float *)((int)uStack_754._0_4_ + 0x14) = pVVar28->z;
                      if (cStack_755 != '\0') {
                        std::
                        _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                        ::
                        _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                  (a_Stack_6c0,*(DispatchClass **)&pvStack_74c->field_0x0,
                                   (_Container_base0 *)pvStack_74c);
                        FormatLogMessage(
                                        "Pathing Failed, using random object. Index is: %d Mode is: %d Method is: %d Spot is: %f %f %f."
                                        );
                      }
                    }
                    Goto((unaff_ESI._Ptr)->DispatchObject,&(unaff_ESI._Ptr)->DispatchSpot,0);
                    _Var26._Ptr = unaff_ESI._Ptr;
                    fVar40 = GetRandomFloat(___real_42480000);
                    (unaff_ESI._Ptr)->RandomDist = fVar40 + (float)___real_4024000000000000;
                    (_Var26._Ptr)->IdleTime = 0;
                    (_Var26._Ptr)->DispatchState = 1;
                  }
                  else {
                    _Var26._Ptr = unaff_ESI._Ptr;
                    if ((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                         )_Stack_738._Ptr ==
                        (_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                         )0x2) {
                      _Stack_748._Ptr = (DispatchClass *)0x7f7fffff;
                      if (iStack_730 == 0) {
                        if (0 < (int)_Stack_708._Ptr) {
                          uStack_754 = (double)CONCAT44(uStack_754._4_4_,_Stack_708._Ptr);
                          _Stack_734._Ptr = (DispatchClass *)0x0;
                          do {
                            _Var26._Ptr = _Stack_734._Ptr;
                            if ((int)_Stack_708._Ptr < 2) {
LAB_4fc21642:
                              puVar36 = (undefined4 *)
                                        ((int)(_Var26._Ptr)->CloakChance +
                                        *(int *)&BuildingHelper::m_BuildingHelper->BuildingList +
                                        -0x4c);
                              p_Var38 = a_Stack_4ec;
                              for (iVar24 = 0x116; _Var35._Ptr = a_Stack_4ec[0]._Ptr, iVar24 != 0;
                                  iVar24 = iVar24 + -1) {
                                p_Var38->_Ptr = (DispatchClass *)*puVar36;
                                puVar36 = puVar36 + 1;
                                p_Var38 = p_Var38 + 1;
                              }
                              bVar23 = IsTeamAllied((int)local_744,(int)pfStack_264);
                              if (((bVar23) || (cStack_2b4 == '\0')) ||
                                 ((iStack_25c < 1 ||
                                  (_Stack_738._Ptr =
                                        (DispatchClass *)
                                        GetDistance2DSquared<Vector,Vector>
                                                  (__return_storage_ptr__,unaff_EDI),
                                  (float)_Stack_748._Ptr <= (float)_Stack_738._Ptr)))) {
                                _Var35._Ptr = _Stack_73c._Ptr;
                              }
                              else {
                                _Stack_73c._Ptr = _Var35._Ptr;
                                _Stack_748._Ptr = _Stack_738._Ptr;
                              }
                            }
                            else {
                              fVar40 = GetRandomFloat(1.0);
                              if (fVar40 < __real_3f000000) goto LAB_4fc21642;
                            }
                            _Stack_734._Ptr =
                                 (DispatchClass *)(_Stack_734._Ptr[3].CloakChance + 0xd);
                            iVar24 = (int)uStack_754._0_4_ + -1;
                            uStack_754 = (double)CONCAT44(uStack_754._4_4_,iVar24);
                          } while (iVar24 != 0);
                          goto LAB_4fc216dd;
                        }
                      }
                      else {
                        if (iStack_730 == 1) {
                          aVStack_648[0].x = 0.0;
                          pVVar28 = aVStack_648;
                          aVStack_648[0].y = 0.0;
                          aVStack_648[0].z = 0.0;
LAB_4fc215b2:
                          _Var35._Ptr = (DispatchClass *)
                                        BuildingHelper::GetRandomBuilding
                                                  (BuildingHelper::m_BuildingHelper,(int)local_744,4
                                                   ,true,true,true,0,(char *)0x0,(char *)0x0,0.0,
                                                   *pVVar28);
                        }
                        else {
                          if (iStack_730 != 2) goto LAB_4fc2187a;
                          if ((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                               )_Var21._Ptr ==
                              (_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                               )0x0) {
                            VStack_654.x = 0.0;
                            pVVar28 = &VStack_654;
                            VStack_654.y = 0.0;
                            VStack_654.z = 0.0;
                            goto LAB_4fc215b2;
                          }
                          _Var35._Ptr = _Var21._Ptr;
                        }
                        _Stack_73c._Ptr = _Var35._Ptr;
LAB_4fc216dd:
                        if ((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                             )_Var35._Ptr !=
                            (_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                             )0x0) {
                          GetPosition((int)_Var35._Ptr,&VStack_5c4);
                          VVar20.y = VStack_5c4.y;
                          VVar20.x = VStack_5c4.x;
                          VVar20.z = VStack_5c4.z;
                          uStack_754._0_4_ = unaff_ESI._Ptr;
                          iVar24 = BuildingHelper::GetRandomBuilding
                                             (BuildingHelper::m_BuildingHelper,(int)local_744,4,true
                                              ,true,true,0,(char *)0x0,(char *)0x0,___real_43480000,
                                              VVar20);
                          *(int *)&(uStack_754._0_4_)->DispatchTarget = iVar24;
                          if (*(int *)&(unaff_ESI._Ptr)->DispatchTarget == 0) {
                            *(DispatchClass **)&(unaff_ESI._Ptr)->DispatchTarget = _Stack_73c._Ptr;
                          }
                          GetPosition(*(int *)&(unaff_ESI._Ptr)->DispatchTarget,&VStack_5b8);
                          uStack_754 = (double)CONCAT44(uStack_754._4_4_,unaff_ESI._Ptr);
                          VVar5.y = VStack_71c.z;
                          VVar5.x = VStack_71c.y;
                          VVar5.z = VStack_5b8.x;
                          VVar14.y = VStack_5b8.z;
                          VVar14.x = VStack_5b8.y;
                          VVar14.z = ___real_42480000;
                          pVVar28 = GetPositionNearOrFar
                                              ((Vector *)VStack_71c.x,VVar5,VVar14,___real_437a0000,
                                               (float)__return_storage_ptr__,SUB41(unaff_EDI,0));
                          *(float *)((int)uStack_754._0_4_ + 0xc) = pVVar28->x;
                          *(float *)((int)uStack_754._0_4_ + 0x10) = pVVar28->y;
                          *(float *)((int)uStack_754._0_4_ + 0x14) = pVVar28->z;
                          Goto((unaff_ESI._Ptr)->DispatchObject,&(unaff_ESI._Ptr)->DispatchSpot,0);
                          _Var26._Ptr = unaff_ESI._Ptr;
                          fVar40 = GetRandomFloat((unaff_ESI._Ptr)->EngageRange);
                          (unaff_ESI._Ptr)->RandomDist = fVar40 + (float)___real_4059000000000000;
                          (_Var26._Ptr)->IdleTime = 0;
                          (_Var26._Ptr)->DispatchState = 1;
                          if (cStack_755 != '\0') {
                            memset(TempGetODFName,0,0x40);
                            GetODFName((int)__return_storage_ptr__,(char *)unaff_EDI);
                            std::
                            _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                            ::
                            _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                      (&_Stack_6cc,*(DispatchClass **)&pvStack_74c->field_0x0,
                                       (_Container_base0 *)pvStack_74c);
                            goto LAB_4fc2185f;
                          }
                          goto LAB_4fc21fae;
                        }
                      }
LAB_4fc2187a:
                      _Var26._Ptr = unaff_ESI._Ptr;
                      iVar24 = SecondsToTurns(___real_40a00000);
                      (unaff_ESI._Ptr)->IdleTime = iVar24 + BZ1Helper::m_TurnCounter;
                      if (cStack_755 != '\0') {
                        std::
                        _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                        ::
                        _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                  (&_Stack_6c8,*(DispatchClass **)&pvStack_74c->field_0x0,
                                   (_Container_base0 *)pvStack_74c);
                        goto LAB_4fc21f94;
                      }
                    }
                  }
                }
              }
              else if (iVar24 == 2) {
                if ((0 < *(int *)(iStack_740 + 0x130)) &&
                   (*(int *)(iStack_740 + 0x13c) < *(int *)(iStack_740 + 0x130))) {
                  *(int *)(iStack_740 + 0x13c) = *(int *)(iStack_740 + 0x13c) + 1;
                  iVar24 = (int)local_744 * 0xc;
                  if (*(int *)(local_72c[1].teamInfo[0].BaseSlotName[1] + iVar24 + 0x23) -
                      *(int *)(local_72c[1].teamInfo[0].BaseSlotName[1] + iVar24 + 0x1f) >> 2 < 1) {
                    fVar40 = GetRandomFloat(1.0);
                    uStack_754 = (double)fVar40;
                    if ((float)___real_3fc99999a0000000 <= fVar40) {
                      uStack_660 = 0;
                      uStack_65c = 0;
                      uStack_658 = 0;
                      iVar24 = 1;
                    }
                    else {
                      uStack_66c = 0;
                      uStack_668 = 0;
                      uStack_664 = 0;
                      iVar24 = 3;
                    }
                    iVar24 = BuildingHelper::GetRandomBuilding
                                       (BuildingHelper::m_BuildingHelper,(int)local_744,iVar24,true,
                                        true,true,0,(char *)0x0,(char *)0x0,0.0,(Vector)ZEXT812(0));
                    if ((uStack_754 < ___real_3fb99999a0000000) || (iVar24 == 0)) {
                      fVar40 = (unaff_ESI._Ptr)->EngageRange * (float)___real_4014000000000000;
                      uStack_754 = (double)CONCAT44(uStack_754._4_4_,fVar40);
                      VVar9.y = VStack_71c.y;
                      VVar9.x = VStack_71c.x;
                      VVar9.z = VStack_71c.z;
                      _Stack_738._Ptr = unaff_ESI._Ptr;
                      pVVar28 = GetPositionNear(aVStack_534,VVar9,___real_42c80000,fVar40);
                      _Var26._Ptr = _Stack_738._Ptr;
                    }
                    else {
                      GetPosition(iVar24,&VStack_5e8);
                      uStack_754 = (double)CONCAT44(uStack_754._4_4_,unaff_ESI._Ptr);
                      VVar8.y = VStack_5e8.y;
                      VVar8.x = VStack_5e8.x;
                      VVar8.z = VStack_5e8.z;
                      pVVar28 = GetPositionNear(&VStack_540,VVar8,___real_42480000,___real_42c80000)
                      ;
                      _Var26._Ptr = uStack_754._0_4_;
                    }
                    ((_Var26._Ptr)->DispatchSpot).x = pVVar28->x;
                    ((_Var26._Ptr)->DispatchSpot).y = pVVar28->y;
                    ((_Var26._Ptr)->DispatchSpot).z = pVVar28->z;
                    Goto((unaff_ESI._Ptr)->DispatchObject,&(unaff_ESI._Ptr)->DispatchSpot,0);
                    (unaff_ESI._Ptr)->DispatchState = 1;
                    (unaff_ESI._Ptr)->IdleTime = 0;
                    _Var26._Ptr = unaff_ESI._Ptr;
                    if (cStack_755 != '\0') {
                      memset(TempGetODFName,0,0x40);
                      GetODFName((int)__return_storage_ptr__,(char *)unaff_EDI);
                      std::
                      _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                      ::
                      _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                (&_Stack_6d4,*(DispatchClass **)&pvStack_74c->field_0x0,
                                 (_Container_base0 *)pvStack_74c);
                      FormatLogMessage(
                                      "Index: %d sent to Dynamic Patrol Near Handle: %08x, ODF: \'%s\', Position: %f %f %f"
                                      );
                      _Var26._Ptr = unaff_ESI._Ptr;
                    }
                  }
                  else {
                    iVar32 = GetRandomInt((int)__return_storage_ptr__,(int)unaff_EDI);
                    _Stack_734._Ptr = (DispatchClass *)0x0;
                    pcVar42 = *(char **)(*(int *)(local_72c[1].teamInfo[0].BaseSlotName[1] +
                                                 iVar24 + 0x1f) + iVar32 * 4);
                    _Var26._Ptr = unaff_ESI._Ptr;
                    if (pcVar42 != (char *)0x0) {
                      GetPathPoints(pcVar42,(uint *)&_Stack_734,(float *)0x0);
                      _Var26._Ptr = unaff_ESI._Ptr;
                      if ((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                           )_Stack_734._Ptr !=
                          (_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                           )0x0) {
                        Patrol((unaff_ESI._Ptr)->DispatchObject,pcVar42,0);
                        (unaff_ESI._Ptr)->DispatchState = 1;
                        (unaff_ESI._Ptr)->IdleTime = 0;
                        _Var26._Ptr = unaff_ESI._Ptr;
                        if (cStack_755 != '\0') {
                          std::
                          _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                          ::
                          _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                    (&_Stack_6d8,*(DispatchClass **)&pvVar39->field_0x0,
                                     (_Container_base0 *)pvVar39);
                          pcVar42 = "Index: %d sent to Patrol path: \'%s\', TurnCount: %d";
                          goto LAB_4fc204ce;
                        }
                      }
                    }
                  }
                }
              }
              else if (iVar24 == 3) {
                iVar24 = (int)local_744 * 0xc;
                if (*(int *)(local_72c[1].teamInfo[0].PlayerPilotODF + iVar24 + 0x23) -
                    *(int *)(local_72c[1].teamInfo[0].PlayerPilotODF + iVar24 + 0x1f) >> 2 < 1) {
                  _Stack_748._Ptr =
                       (DispatchClass *)GetRandomInt((int)__return_storage_ptr__,(int)unaff_EDI);
                  if ((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                       )_Stack_748._Ptr ==
                      (_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                       )0x0) {
                    uStack_684 = 0;
                    uStack_680 = 0;
                    uStack_67c = 0;
                    uStack_678 = 0;
                    uStack_674 = 0;
                    fStack_670 = 0.0;
                    uStack_754 = (double)CONCAT44(uStack_754._4_4_,BuildingHelper::m_BuildingHelper)
                    ;
                    _Stack_738._Ptr =
                         (DispatchClass *)
                         BuildingHelper::GetRandomBuilding
                                   (BuildingHelper::m_BuildingHelper,(int)local_744,4,true,true,true
                                    ,0,(char *)0x0,(char *)0x0,0.0,(Vector)ZEXT812(0));
                    VVar19.y = (float)uStack_674;
                    VVar19.x = (float)uStack_678;
                    VVar19.z = fStack_670;
                    iVar24 = BuildingHelper::GetRandomBuilding
                                       ((BuildingHelper *)uStack_754._0_4_,(int)local_744,1,true,
                                        true,true,0,(char *)0x0,(char *)0x0,0.0,VVar19);
                    GetPosition(iVar24,&VStack_60c);
                    GetPosition((int)_Stack_738._Ptr,&VStack_600);
                    VVar4.y = VStack_600.z;
                    VVar4.x = VStack_600.y;
                    VVar4.z = VStack_60c.x;
                    VVar13.y = VStack_60c.z;
                    VVar13.x = VStack_60c.y;
                    VVar13.z = ___real_42c80000;
                    GetPositionNearOrFar
                              ((Vector *)VStack_600.x,VVar4,VVar13,___real_43480000,
                               (float)__return_storage_ptr__,SUB41(unaff_EDI,0));
                    pfVar34 = afStack_5f4;
LAB_4fc21010:
                    ((unaff_ESI._Ptr)->DispatchSpot).x = *pfVar34;
                    ((unaff_ESI._Ptr)->DispatchSpot).y = pfVar34[1];
                    ((unaff_ESI._Ptr)->DispatchSpot).z = pfVar34[2];
                  }
                  else if ((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                            )_Stack_748._Ptr ==
                           (_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                            )0x1) {
                    fVar40 = (local_72c->mapInfo).MapDepth;
                    _Stack_734._Ptr = (DispatchClass *)(local_72c->mapInfo).MapWidth;
                    uStack_754 = (double)CONCAT44(uStack_754._4_4_,fVar40);
                    fStack_690 = GetRandomFloat((float)((uint)fVar40 ^
                                                       __xmm_80000000800000008000000080000000),
                                                fVar40);
                    fStack_68c = 0.0;
                    fStack_688 = GetRandomFloat((float)((uint)_Stack_734._Ptr ^
                                                       __xmm_80000000800000008000000080000000),
                                                (float)_Stack_734._Ptr);
                    ((unaff_ESI._Ptr)->DispatchSpot).x = fStack_690;
                    ((unaff_ESI._Ptr)->DispatchSpot).y = fStack_68c;
                    ((unaff_ESI._Ptr)->DispatchSpot).z = fStack_688;
                    _Var26._Ptr = unaff_ESI._Ptr;
                    fVar40 = TerrainFindFloor(((unaff_ESI._Ptr)->DispatchSpot).x,
                                              ((unaff_ESI._Ptr)->DispatchSpot).z);
                    ((unaff_ESI._Ptr)->DispatchSpot).y = fVar40;
                    unaff_ESI._Ptr = _Var26._Ptr;
                  }
                  else if ((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                            )_Stack_748._Ptr ==
                           (_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                            )0x2) {
                    uStack_69c = 0;
                    uStack_698 = 0;
                    uStack_694 = 0;
                    pVStack_624 = (Vector *)VStack_71c.x;
                    fStack_620 = VStack_71c.y;
                    fStack_61c = VStack_71c.z;
                    iVar24 = BuildingHelper::GetRandomBuilding
                                       (BuildingHelper::m_BuildingHelper,(int)local_744,4,true,true,
                                        true,0,(char *)0x0,(char *)0x0,0.0,(Vector)ZEXT812(0));
                    GetPosition(iVar24,&VStack_630);
                    VVar3.y = fStack_61c;
                    VVar3.x = fStack_620;
                    VVar3.z = VStack_630.x;
                    VVar12.y = VStack_630.z;
                    VVar12.x = VStack_630.y;
                    VVar12.z = ___real_42c80000;
                    GetPositionNearOrFar
                              (pVStack_624,VVar3,VVar12,___real_43480000,
                               (float)__return_storage_ptr__,SUB41(unaff_EDI,0));
                    pfVar34 = afStack_618;
                    goto LAB_4fc21010;
                  }
                  if (cStack_755 != '\0') {
                    FormatLogMessage(
                                    "Index: %d sent to Dynamic Minelaying, DispatchState: %d, Position: %f %f %f"
                                    );
                  }
                }
                else {
                  iVar32 = GetRandomInt((int)__return_storage_ptr__,(int)unaff_EDI);
                  _Stack_734._Ptr = (DispatchClass *)0x0;
                  _Stack_738._Ptr =
                       *(DispatchClass **)
                        (*(int *)(local_72c[1].teamInfo[0].PlayerPilotODF + iVar24 + 0x1f) +
                        iVar32 * 4);
                  if (((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                        )_Stack_738._Ptr !=
                       (_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                        )0x0) &&
                     (GetPathPoints((char *)_Stack_738._Ptr,(uint *)&_Stack_734,(float *)0x0),
                     (_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                      )_Stack_734._Ptr !=
                     (_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                      )0x0)) {
                    uStack_754 = (double)CONCAT44(uStack_754._4_4_,unaff_ESI._Ptr);
                    pVVar28 = GetVectorFromPath((Vector *)0x0,(char *)__return_storage_ptr__,
                                                (int)unaff_EDI);
                    pVVar28 = GetPositionNear(&VStack_54c,*pVVar28,___real_41c80000,___real_42480000
                                             );
                    *(float *)((int)uStack_754._0_4_ + 0xc) = pVVar28->x;
                    *(float *)((int)uStack_754._0_4_ + 0x10) = pVVar28->y;
                    *(float *)((int)uStack_754._0_4_ + 0x14) = pVVar28->z;
                    if (cStack_755 != '\0') {
                      std::
                      _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                      ::
                      _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                (&_Stack_6dc,*(DispatchClass **)&pvStack_74c->field_0x0,
                                 (_Container_base0 *)pvStack_74c);
                      FormatLogMessage("Index: %d sent to Lay Mines at path: \'%s\'");
                    }
                  }
                }
                bVar23 = IsNullVector((unaff_ESI._Ptr)->DispatchSpot);
                _Var26._Ptr = unaff_ESI._Ptr;
                if (!bVar23) {
                  Goto((unaff_ESI._Ptr)->DispatchObject,&(unaff_ESI._Ptr)->DispatchSpot,0);
                  fVar40 = ___real_43960000;
                  (unaff_ESI._Ptr)->DispatchState = 1;
                  _Var26._Ptr = unaff_ESI._Ptr;
                  iVar24 = SecondsToTurns(fVar40);
                  (unaff_ESI._Ptr)->IdleTime = iVar24 + BZ1Helper::m_TurnCounter;
                  if (cStack_755 != '\0') {
                    pcVar42 = "Index is: %d Minelayer No Valid Target, IdleTime: %d";
                    goto LAB_4fc203ec;
                  }
                }
              }
              else if (iVar24 == 4) {
                if ((0 < *(int *)(iStack_740 + 0x134)) &&
                   (*(int *)(iStack_740 + 0x140) < *(int *)(iStack_740 + 0x134))) {
                  *(int *)(iStack_740 + 0x140) = *(int *)(iStack_740 + 0x140) + 1;
                  SetCommand((unaff_ESI._Ptr)->DispatchObject,0x15,0,0,(char *)0x0,0);
                  fVar40 = ___real_43960000;
                  (unaff_ESI._Ptr)->DispatchState = 1;
                  _Var26._Ptr = unaff_ESI._Ptr;
                  iVar24 = SecondsToTurns(fVar40);
                  (unaff_ESI._Ptr)->IdleTime = iVar24 + BZ1Helper::m_TurnCounter;
                  if (cStack_755 != '\0') {
                    pcVar42 = "Index: %d Hunt Task Starting, Hunt Command issued. IdleTime: %d";
                    goto LAB_4fc203ec;
                  }
                }
              }
              else if (((iVar24 == 5) && (0 < *(int *)(iStack_740 + 0x138))) &&
                      (*(int *)(iStack_740 + 0x144) < *(int *)(iStack_740 + 0x138))) {
                iVar24 = UtilityShipHelper::GetEscortTarget
                                   (UtilityShipHelper::m_UtilityShipHelper,(int)local_744,3);
                *(int *)&(unaff_ESI._Ptr)->DispatchTarget = iVar24;
                if (*(int *)&(_Var26._Ptr)->DispatchTarget != 0) {
                  Defend2((_Var26._Ptr)->DispatchObject,*(int *)&(_Var26._Ptr)->DispatchTarget,0);
                  (_Var26._Ptr)->DispatchState = 1;
                  (_Var26._Ptr)->IdleTime = 0;
                  if (cStack_755 != '\0') {
                    memset(TempGetODFName,0,0x40);
                    GetODFName((int)__return_storage_ptr__,(char *)unaff_EDI);
                    FormatLogMessage("Index: %d Escort Task Starting, Target: \'%s\'");
                  }
                  *(int *)(iStack_740 + 0x144) = *(int *)(iStack_740 + 0x144) + 1;
                }
              }
            }
          }
          goto LAB_4fc21fae;
        }
        if (iVar24 == 1) {
          _Var35._Ptr = unaff_ESI._Ptr;
          if ((unaff_ESI._Ptr)->DispatchType == 1) {
            if ((unaff_ESI._Ptr)->IdleTime == 0) {
              bVar23 = IsDeployed((unaff_ESI._Ptr)->DispatchObject);
              _Var35._Ptr = unaff_ESI._Ptr;
              if (bVar23) {
                if ((unaff_ESI._Ptr)->IdleTime != 0) goto LAB_4fc20519;
              }
              else {
                iVar24 = SecondsToTurns(___real_43960000);
                (unaff_ESI._Ptr)->IdleTime = iVar24 + BZ1Helper::m_TurnCounter;
              }
            }
            else {
LAB_4fc20519:
              bVar23 = IsDeployed((_Var35._Ptr)->DispatchObject);
              if (bVar23) {
                (_Var35._Ptr)->DispatchState = 0;
              }
            }
          }
          if (((_Var35._Ptr)->SkipAIPCheck == false) &&
             (_Var26._Ptr = _Var35._Ptr, *(char *)(iStack_740 + 0x1ae) == '\0')) goto LAB_4fc21fae;
          if ((0 < (_Var35._Ptr)->IdleTime) && ((_Var35._Ptr)->IdleTime <= BZ1Helper::m_TurnCounter)
             ) {
            ClearDispatch(pDStack_724,(int)_Stack_748._Ptr);
          }
          iVar24 = (_Var35._Ptr)->DispatchType;
          if (iVar24 == 1) {
            bVar23 = IsDeployed((_Var35._Ptr)->DispatchObject);
            _Var26._Ptr = _Var35._Ptr;
            if (bVar23) goto LAB_4fc21fae;
            _Stack_734._Ptr = (DispatchClass *)0x0;
            local_728._0_3_ = (uint3)(byte)local_728;
            if (0 < iStack_710) {
              iStack_730 = 0;
              do {
                piVar33 = (int *)(*(int *)&local_72c->m_ObjectHelper->HandleList + iStack_730);
                local_70c = *piVar33;
                bVar23 = IsTeamAllied((int)local_744,piVar33[7]);
                if ((!bVar23) &&
                   ((piVar33[4] == 2 ||
                    ((piVar33[2] == 0x4a7aef92 && (bVar23 = IsDeployed(local_70c), bVar23)))))) {
                  uStack_754 = (double)((float)piVar33[9] + (float)___real_4049000000000000);
                  fVar41 = GetDistance2DSquared<Vector,Vector>(__return_storage_ptr__,unaff_EDI);
                  fVar40 = (float)((float10)uStack_754 * (float10)uStack_754);
                  uStack_754 = (double)CONCAT44(uStack_754._4_4_,fVar40);
                  if (fVar41 < fVar40) {
                    local_728._0_2_ = CONCAT11(1,(byte)local_728);
                    fVar40 = GetRandomFloat(1.0);
                    if (fVar40 < __real_3f000000) {
                      local_728._0_3_ = CONCAT12(1,(undefined2)local_728);
                    }
                    if (cStack_755 != '\0') {
                      fVar40 = (*misnImport.GetDistanceObject)
                                         (&(_Var35._Ptr)->DispatchObject,&local_70c);
                      uStack_754 = (double)CONCAT44(uStack_754._4_4_,fVar40);
                      FormatLogMessage(
                                      "Index: %d Turret Encountered an Enemy on Team: %d Distance Is: %f, Return is: %d"
                                      );
                    }
                    break;
                  }
                }
                _Stack_734._Ptr = (DispatchClass *)((int)&(_Stack_734._Ptr)->DispatchObject + 1);
                iStack_730 = iStack_730 + 0x5c;
              } while ((int)_Stack_734._Ptr < iStack_710);
            }
            if ((byte)local_728 == '\0') {
LAB_4fc209d8:
              _Var26._Ptr = _Var35._Ptr;
              if (local_728._1_1_ == '\0') goto LAB_4fc21fae;
            }
            else {
              uStack_754 = (double)((_Var35._Ptr)->RandomDist + (float)___real_4014000000000000);
              fVar41 = GetDistance2DSquared<Vector,Vector>(__return_storage_ptr__,unaff_EDI);
              fVar40 = (float)((float10)uStack_754 * (float10)uStack_754);
              uStack_754 = (double)CONCAT44(uStack_754._4_4_,fVar40);
              if (fVar40 < fVar41) goto LAB_4fc209d8;
            }
            if (local_728._2_1_ == '\0') {
              if (local_728._1_1_ == '\0') {
                Defend((_Var35._Ptr)->DispatchObject,0);
              }
              else {
                uStack_754 = (double)CONCAT44(uStack_754._4_4_,_Var35._Ptr);
                VVar7.y = VStack_71c.y;
                VVar7.x = VStack_71c.x;
                VVar7.z = VStack_71c.z;
                pVVar28 = GetPositionNear(aVStack_564,VVar7,__real_41200000,___real_41f00000);
                *(float *)((int)uStack_754._0_4_ + 0xc) = pVVar28->x;
                *(float *)((int)uStack_754._0_4_ + 0x10) = pVVar28->y;
                *(float *)((int)uStack_754._0_4_ + 0x14) = pVVar28->z;
                Goto((_Var35._Ptr)->DispatchObject,&(_Var35._Ptr)->DispatchSpot,0);
                if (cStack_755 != '\0') {
                  FormatLogMessage("Index is: %d Spot is: %f %f %f");
                }
              }
              fVar40 = ___real_43960000;
              (_Var35._Ptr)->DispatchState = 0;
              _Var26._Ptr = _Var35._Ptr;
              iVar24 = SecondsToTurns(fVar40);
              (_Var35._Ptr)->IdleTime = iVar24 + BZ1Helper::m_TurnCounter;
              if (cStack_755 != '\0') {
                pcVar42 = "Index is: %d Turret Encountered an Enemy, IdleTime: %d";
                goto LAB_4fc203ec;
              }
            }
            else {
              ClearDispatch(pDStack_724,(int)_Stack_748._Ptr);
              _Var26._Ptr = _Var35._Ptr;
            }
          }
          else if (iVar24 == 2) {
            bVar23 = IsIdle((_Var35._Ptr)->DispatchObject);
            _Var26._Ptr = _Var35._Ptr;
            if (bVar23) {
              pcVar42 = local_72c[1].teamInfo[0].BaseSlotName[1] + (int)local_744 * 0xc + 0x1f;
              if ((*(int *)(pcVar42 + 4) - *(int *)pcVar42 & 0xfffffffcU) == 0) {
                (_Var35._Ptr)->IdleTime = 0;
                if (cStack_755 != '\0') {
                  FormatLogMessage("Index: %d sent to Dynamic Patrol Reset, Cmd == CMD_NONE");
                }
              }
              else {
                iVar24 = SecondsToTurns(___real_41700000);
                (_Var35._Ptr)->IdleTime = iVar24 + BZ1Helper::m_TurnCounter;
                _Var35._Ptr = _Var26._Ptr;
                if (cStack_755 != '\0') {
                  FormatLogMessage(
                                  "Patrol Unit %d interrupted, resetting idle timer. TurnCount: %d, IdleTime: %d"
                                  );
                  _Var35._Ptr = _Var26._Ptr;
                }
              }
              (_Var35._Ptr)->DispatchState = 0;
              _Var26._Ptr = _Var35._Ptr;
            }
          }
          else if (iVar24 == 3) {
            fVar40 = GetDistance2DSquared<Vector,Vector>(__return_storage_ptr__,unaff_EDI);
            _Var26._Ptr = _Var35._Ptr;
            if (fVar40 < (float)___real_4059000000000000) {
              SetCommand((_Var35._Ptr)->DispatchObject,0x1b,0,0,(char *)0x0,0);
              fVar40 = ___real_43960000;
              (_Var35._Ptr)->DispatchState = 0;
              _Var26._Ptr = _Var35._Ptr;
              iVar24 = SecondsToTurns(fVar40);
              (_Var35._Ptr)->IdleTime = iVar24 + BZ1Helper::m_TurnCounter;
              if (cStack_755 != '\0') {
                FormatLogMessage(
                                "Index: %d Minelayer reached Spot: %f %f %f, laying mines..., IdleTime: %d"
                                );
              }
            }
          }
          else {
            if (iVar24 == 4) {
              bVar23 = IsIdle((_Var35._Ptr)->DispatchObject);
              _Var26._Ptr = _Var35._Ptr;
              if (!bVar23) goto LAB_4fc21fae;
              SetCommand((_Var35._Ptr)->DispatchObject,0x15,0,0,(char *)0x0,0);
              _Var26._Ptr = _Var35._Ptr;
              iVar24 = SecondsToTurns(___real_43960000);
              (_Var35._Ptr)->IdleTime = iVar24 + BZ1Helper::m_TurnCounter;
              if (cStack_755 == '\0') goto LAB_4fc21fae;
              pcVar42 = "Index: %d Hunt Task Continuing, Re-Issueing Hunt Command. IdleTime: %d";
              goto LAB_4fc203ec;
            }
            _Var26._Ptr = _Var35._Ptr;
            if ((iVar24 == 5) && ((byte)local_728 == '\0')) {
              fVar40 = GetRandomFloat(1.0);
              if (__real_3f000000 <= fVar40) {
                (_Var35._Ptr)->DispatchType = 0;
                ClearDispatch(pDStack_724,(int)_Stack_748._Ptr);
                fVar40 = ___real_43e10000;
                iVar32 = 0;
                *(int *)(iStack_740 + 0x144) = *(int *)(iStack_740 + 0x144) + -1;
                _Var26._Ptr = _Var35._Ptr;
                iVar24 = GetNearestEnemy((_Var35._Ptr)->DispatchObject,true,false,fVar40);
                Attack((_Var35._Ptr)->DispatchObject,iVar24,iVar32);
                if (cStack_755 != '\0') {
                  FormatLogMessage("Index: %d Escort Target lost, Going Bezerk!");
                }
              }
              else {
                _Var26._Ptr = _Var35._Ptr;
                iVar24 = UtilityShipHelper::GetEscortTarget
                                   (UtilityShipHelper::m_UtilityShipHelper,(int)local_744,3);
                *(int *)&(_Var35._Ptr)->DispatchTarget = iVar24;
                Defend2((_Var26._Ptr)->DispatchObject,*(int *)&(_Var26._Ptr)->DispatchTarget,0);
                if (cStack_755 != '\0') {
                  memset(TempGetODFName,0,0x40);
                  GetODFName((int)__return_storage_ptr__,(char *)unaff_EDI);
                  pcVar42 = "Index: %d Escort Target lost, picking new Target: \'%s\'";
                  goto LAB_4fc203ec;
                }
              }
            }
          }
        }
        else if (iVar24 == 2) {
          if ((unaff_ESI._Ptr)->IdleTime <= BZ1Helper::m_TurnCounter) {
            SetIndependence((unaff_ESI._Ptr)->DispatchObject,1);
            _Var26._Ptr = unaff_ESI._Ptr;
            lVar27 = GetCurHealth((unaff_ESI._Ptr)->DispatchObject);
            (unaff_ESI._Ptr)->FleeHealthValue = lVar27;
            ClearDispatch(pDStack_724,(int)_Stack_748._Ptr);
            unaff_ESI._Ptr = _Var26._Ptr;
            iVar24 = SecondsToTurns(___real_41700000);
            (_Var26._Ptr)->IdleTime = iVar24 + BZ1Helper::m_TurnCounter;
            bVar23 = IsAround((unaff_ESI._Ptr)->FleeTarget);
            if (bVar23) {
              Attack((unaff_ESI._Ptr)->DispatchObject,(unaff_ESI._Ptr)->FleeTarget,0);
            }
            _Var26._Ptr = unaff_ESI._Ptr;
            if (cStack_755 != '\0') {
              memset(TempGetODFName,0,0x40);
              GetODFName((int)__return_storage_ptr__,(char *)unaff_EDI);
              pcVar42 = "Index: %d Flee State Ending. Last Target: \'%s\', IdleTime: %d";
LAB_4fc204ce:
              FormatLogMessage(pcVar42);
              _Var26._Ptr = unaff_ESI._Ptr;
            }
          }
        }
        else if (iVar24 - 3U < 2) {
          if (iVar24 == 4) {
            _Var35._Ptr = unaff_ESI._Ptr;
            fVar40 = GetHealth((unaff_ESI._Ptr)->DispatchObject);
            _Var26._Ptr = _Var35._Ptr;
            if (fVar40 <= (unaff_ESI._Ptr)->GetRepairRatio) goto LAB_4fc20300;
          }
          else {
LAB_4fc20300:
            _Var35._Ptr = _Var26._Ptr;
            if (((((_Var26._Ptr)->DispatchState != 3) ||
                 (lVar27 = GetCurAmmo((_Var26._Ptr)->DispatchObject),
                 lVar27 <= (_Var26._Ptr)->MinFireAmmo)) &&
                (BZ1Helper::m_TurnCounter < (_Var35._Ptr)->IdleTime)) &&
               (((_Var26._Ptr = _Var35._Ptr, (_Var35._Ptr)->DispatchType == 1 ||
                 ((_Var35._Ptr)->DispatchType == 6)) || ((byte)local_728 != '\0'))))
            goto LAB_4fc21fae;
          }
          if (cStack_755 != '\0') {
            memset(TempGetODFName,0,0x40);
            GetODFName((int)__return_storage_ptr__,(char *)unaff_EDI);
            FormatLogMessage("Index: %d Unit: \'%s\' Rearmed/Repaired, resuming duties");
          }
          SetIndependence((_Var35._Ptr)->DispatchObject,1);
          ClearDispatch(pDStack_724,(int)_Stack_748._Ptr);
          _Var26._Ptr = _Var35._Ptr;
          iVar24 = SecondsToTurns(___real_41700000);
          (_Var35._Ptr)->IdleTime = iVar24 + BZ1Helper::m_TurnCounter;
          if (cStack_755 != '\0') {
            pcVar42 = "Index is: %d Repair/Repaid finished, IdleTime: %d";
LAB_4fc203ec:
            FormatLogMessage(pcVar42);
          }
        }
LAB_4fc21fae:
        (_Var26._Ptr)->ServiceTimer = (_Var26._Ptr)->ServiceTimer + -1;
        _Var35._Ptr = _Var26._Ptr;
        if ((_Var26._Ptr)->ServiceTimer < 0) {
          iVar24 = SecondsToTurns(__real_41200000);
          (_Var26._Ptr)->ServiceTimer = iVar24;
        }
        unaff_ESI._Ptr = _Var35._Ptr;
        if (((*(char *)(iStack_740 + 0x1ad) == '\0') || (0 < (_Var35._Ptr)->ServiceTimer)) ||
           (((_Var35._Ptr)->DispatchState == 4 || ((_Var35._Ptr)->DispatchState == 3)))) {
LAB_4fc22578:
          pvVar39 = pvStack_74c;
        }
        else {
          if ((_Var35._Ptr)->CanGetRepair == false) {
LAB_4fc2225f:
            iVar24 = iStack_740;
          }
          else {
            fVar40 = GetHealth((_Var35._Ptr)->DispatchObject);
            if ((_Var35._Ptr)->GetRepairRatio <= fVar40) goto LAB_4fc2225f;
            if ((((unaff_ESI._Ptr)->DispatchType != 1) && ((unaff_ESI._Ptr)->DispatchType != 6)) ||
               (bVar23 = IsDeployed((unaff_ESI._Ptr)->DispatchObject), !bVar23)) {
              _Var26._Ptr = unaff_ESI._Ptr;
              fVar40 = GetRandomFloat(1.0);
              pfVar34 = &(unaff_ESI._Ptr)->ServiceChance;
              unaff_ESI._Ptr = _Var26._Ptr;
              if (fVar40 < *pfVar34) {
                VVar1.y = VStack_71c.y;
                VVar1.x = VStack_71c.x;
                VVar1.z = VStack_71c.z;
                iVar24 = BuildingHelper::GetNearestServiceObject
                                   (BuildingHelper::m_BuildingHelper,1,VVar1,0.0,-1,0,true,true,true
                                    ,0,0,(char *)0x0,(char *)0x0);
                uStack_754 = (double)CONCAT44(uStack_754._4_4_,iVar24);
                unaff_ESI._Ptr = _Var26._Ptr;
                if (iVar24 != 0) {
                  if (cStack_755 != '\0') {
                    memset(TempGetODFName,0,0x40);
                    GetODFName((int)__return_storage_ptr__,(char *)unaff_EDI);
                    FormatLogMessage("Index: %d Unit: \'%s\' going to get Repair");
                  }
                  *(DispatchClass **)&(_Var26._Ptr)->DispatchTarget = uStack_754._0_4_;
                  Goto((_Var26._Ptr)->DispatchObject,*(int *)&(_Var26._Ptr)->DispatchTarget,0);
                  SetIndependence((_Var26._Ptr)->DispatchObject,0);
                  fVar40 = ___real_43960000;
                  (_Var26._Ptr)->DispatchState = 4;
                  unaff_ESI._Ptr = _Var26._Ptr;
                  iVar24 = SecondsToTurns(fVar40);
                  (_Var26._Ptr)->IdleTime = iVar24 + BZ1Helper::m_TurnCounter;
                  if (cStack_755 != '\0') {
                    FormatLogMessage("Index is: %d Unit going to Repair Service, IdleTime: %d");
                  }
                }
              }
              goto LAB_4fc2225f;
            }
            if (*(int *)(iStack_740 + 0xa4) == 0) goto LAB_4fc2225f;
            memset(acStack_94,0,0x40);
            bVar23 = GetBuildItem(0,(char *)0x1,(int *)0x0,0,(char *)0x0,
                                  (char *)__return_storage_ptr__,(char *)unaff_EDI);
            if (!bVar23) goto LAB_4fc2225f;
            iVar32 = (*misnImport.GetScrap)((int)local_744);
            iVar24 = iStack_740;
            if (iVar32 < 0) goto LAB_4fc2225f;
            VVar16.y = VStack_71c.y;
            VVar16.x = VStack_71c.x;
            VVar16.z = VStack_71c.z;
            BZ1Helper::BuildAt(local_72c,*(int *)(iStack_740 + 0xa4),acStack_94,VVar16,1);
            fVar40 = ___real_42700000;
            (unaff_ESI._Ptr)->DispatchState = 4;
            iVar32 = SecondsToTurns(fVar40);
            if ((unaff_ESI._Ptr)->IdleTime < iVar32 + BZ1Helper::m_TurnCounter) {
              (unaff_ESI._Ptr)->IdleTime = iVar32 + BZ1Helper::m_TurnCounter;
            }
            if (cStack_755 != '\0') {
              FormatLogMessage(
                              "Index is: %d Deployable Waiting for Repair Powerup to land, IdleTime: %d"
                              );
            }
          }
          if ((unaff_ESI._Ptr)->CanGetReload == false) goto LAB_4fc22578;
          fVar40 = GetAmmo((unaff_ESI._Ptr)->DispatchObject);
          if (1.0 <= fVar40) {
LAB_4fc223b4:
            pvVar39 = pvStack_74c;
          }
          else {
            _Var26._Ptr = unaff_ESI._Ptr;
            lVar27 = GetMinFireAmmo((int)__return_storage_ptr__);
            (unaff_ESI._Ptr)->MinFireAmmo = lVar27;
            unaff_ESI._Ptr = _Var26._Ptr;
            lVar27 = GetCurAmmo((_Var26._Ptr)->DispatchObject);
            if ((_Var26._Ptr)->MinFireAmmo <= lVar27) goto LAB_4fc223b4;
            if (((unaff_ESI._Ptr)->DispatchType != 1) &&
               (_Var26._Ptr = unaff_ESI._Ptr, (unaff_ESI._Ptr)->DispatchType != 6)) {
LAB_4fc2246c:
              VVar2.y = VStack_71c.y;
              VVar2.x = VStack_71c.x;
              VVar2.z = VStack_71c.z;
              iVar24 = BuildingHelper::GetNearestServiceObject
                                 (BuildingHelper::m_BuildingHelper,2,VVar2,0.0,-1,0,true,true,true,0
                                  ,0,(char *)0x0,(char *)0x0);
              uStack_754 = (double)CONCAT44(uStack_754._4_4_,iVar24);
              unaff_ESI._Ptr = _Var26._Ptr;
              if (iVar24 != 0) {
                if (cStack_755 == '\0') {
                  pvVar39 = pvStack_74c;
                }
                else {
                  memset(TempGetODFName,0,0x40);
                  GetODFName((int)__return_storage_ptr__,(char *)unaff_EDI);
                  pvVar39 = pvStack_74c;
                  FormatLogMessage("Index: %d Unit: \'%s\' going to get Reload");
                }
                *(DispatchClass **)&(_Var26._Ptr)->DispatchTarget = uStack_754._0_4_;
                Goto((_Var26._Ptr)->DispatchObject,*(int *)&(_Var26._Ptr)->DispatchTarget,0);
                SetIndependence((_Var26._Ptr)->DispatchObject,0);
                fVar40 = ___real_41f00000;
                (_Var26._Ptr)->DispatchState = 3;
                unaff_ESI._Ptr = _Var26._Ptr;
                iVar24 = SecondsToTurns(fVar40);
                (_Var26._Ptr)->IdleTime = iVar24 + BZ1Helper::m_TurnCounter;
                if (cStack_755 != '\0') {
                  pcVar42 = "Index is: %d Unit going to Reload Service, IdleTime: %d";
LAB_4fc223a2:
                  FormatLogMessage(pcVar42);
                  goto LAB_4fc223b8;
                }
              }
              goto LAB_4fc223b4;
            }
            bVar23 = IsDeployed((unaff_ESI._Ptr)->DispatchObject);
            _Var26._Ptr = unaff_ESI._Ptr;
            if (!bVar23) goto LAB_4fc2246c;
            if (*(int *)(iVar24 + 0xa4) == 0) goto LAB_4fc223b4;
            memset(acStack_54,0,0x40);
            bVar23 = GetBuildItem(0,(char *)0x2,(int *)0x0,0,(char *)0x0,
                                  (char *)__return_storage_ptr__,(char *)unaff_EDI);
            if (!bVar23) goto LAB_4fc223b4;
            iVar24 = (*misnImport.GetScrap)((int)local_744);
            if (iVar24 < 0) goto LAB_4fc223b4;
            VVar17.y = VStack_71c.y;
            VVar17.x = VStack_71c.x;
            VVar17.z = VStack_71c.z;
            BZ1Helper::BuildAt(local_72c,*(int *)(iStack_740 + 0xa4),acStack_54,VVar17,1);
            fVar40 = ___real_42700000;
            (unaff_ESI._Ptr)->DispatchState = 3;
            iVar24 = SecondsToTurns(fVar40);
            if ((unaff_ESI._Ptr)->IdleTime < iVar24 + BZ1Helper::m_TurnCounter) {
              (unaff_ESI._Ptr)->IdleTime = iVar24 + BZ1Helper::m_TurnCounter;
            }
            pvVar39 = pvStack_74c;
            if (cStack_755 != '\0') {
              pcVar42 = "Index is: %d Deployable Waiting for Reload Powerup to land, IdleTime: %d";
              goto LAB_4fc223a2;
            }
          }
LAB_4fc223b8:
        }
        if ((unaff_ESI._Ptr)->IsCloaker != false) {
          if ((unaff_ESI._Ptr)->IsCloaked == false) {
            if ((unaff_ESI._Ptr)->CloakNextTick == false) {
              if (((unaff_ESI._Ptr)->SkipAIPCheck != false) ||
                 (*(char *)(iStack_740 + 0x1ae) != '\0')) {
                if (BZ1Helper::m_TurnCounter < (unaff_ESI._Ptr)->CloakIdleTime) {
                  _Var26._Ptr = unaff_ESI._Ptr;
                  AVar31 = GetCurrentCommand((unaff_ESI._Ptr)->DispatchObject);
                  piVar33 = &(unaff_ESI._Ptr)->Command;
                  unaff_ESI._Ptr = _Var26._Ptr;
                  if (AVar31 == *piVar33) goto LAB_4fc22a40;
                }
                iVar24 = GetPlayerHandle((int)local_744);
                if (((iVar24 == 0) && (local_728._3_1_ == '\x01')) &&
                   ((unaff_ESI._Ptr)->CloakPriority == 0)) {
                  _Stack_738._Ptr = (DispatchClass *)GetRandomFloat(1.0);
                  iVar24 = (*misnImport.GetNearestEnemy)((unaff_ESI._Ptr)->DispatchObject);
                  uStack_754 = (double)CONCAT44(uStack_754._4_4_,iVar24);
                  bVar23 = IsDeployed((unaff_ESI._Ptr)->DispatchObject);
                  if ((!bVar23) || ((unaff_ESI._Ptr)->IsMorpher != false)) {
                    if (uStack_754._0_4_ != (DispatchClass *)0x0) {
                      GetPosition((int)uStack_754._0_4_,&VStack_570);
                      uStack_754 = (double)(unaff_ESI._Ptr)->EngageRange;
                      fVar41 = GetDistance3DSquared(__return_storage_ptr__,unaff_EDI);
                      fVar40 = (float)((float10)uStack_754 * (float10)uStack_754);
                      uStack_754 = (double)CONCAT44(uStack_754._4_4_,fVar40);
                      if (fVar41 <= fVar40) goto LAB_4fc22a40;
                    }
                    uStack_754 = (double)(float)_Stack_738._Ptr;
                    if (cStack_755 != '\0') {
                      FormatLogMessage(
                                      "Index: %d AI Attempting to Cloak unit, Chance: %f, CloakCommand: %d Chance: %f"
                                      );
                    }
                    _Var26._Ptr = unaff_ESI._Ptr;
                    AVar31 = GetCurrentCommand((unaff_ESI._Ptr)->DispatchObject);
                    if (uStack_754 < (double)(unaff_ESI._Ptr)->CloakChance[AVar31]) {
                      if (cStack_755 != '\0') {
                        FormatLogMessage("Index: %d AI Cloak Successful");
                      }
                      Cloak(pDStack_724,(_Var26._Ptr)->DispatchObject,(_Var26._Ptr)->CloakPriority);
                    }
                    unaff_ESI._Ptr = _Var26._Ptr;
                    iVar24 = SecondsToTurns(___real_41700000);
                    (_Var26._Ptr)->CloakIdleTime = iVar24 + BZ1Helper::m_TurnCounter;
                  }
                }
              }
            }
            else {
              bVar23 = IsDeployed((unaff_ESI._Ptr)->DispatchObject);
              _Var26._Ptr = unaff_ESI._Ptr;
              if (!bVar23) {
                SetCommand((unaff_ESI._Ptr)->DispatchObject,0x2f,0,0,(char *)0x0,0);
                _Var26._Ptr = unaff_ESI._Ptr;
                iVar24 = SecondsToTurns((unaff_ESI._Ptr)->TimeDeploy);
                (unaff_ESI._Ptr)->DeployTimer = iVar24 + 1 + BZ1Helper::m_TurnCounter;
                (_Var26._Ptr)->CloakLocked = true;
                if (cStack_755 != '\0') {
                  FormatLogMessage(
                                  "Index: %d Cloaking Activating, Time: %d, DeployTimer: %d, DeployTime: %f"
                                  );
                }
              }
              (_Var26._Ptr)->IsCloaked = true;
              (_Var26._Ptr)->CloakNextTick = false;
              unaff_ESI._Ptr = _Var26._Ptr;
            }
          }
          else {
            bVar23 = IsDeployed((unaff_ESI._Ptr)->DispatchObject);
            if (bVar23) {
              if ((unaff_ESI._Ptr)->DecloakNextTick == false) {
                if (((local_728._3_1_ == '\x01') && ((unaff_ESI._Ptr)->CloakPriority == 0)) &&
                   ((*misnImport.GetNearestEnemy)((unaff_ESI._Ptr)->DispatchObject),
                   (unaff_ESI._Ptr)->CloakLocked != false)) {
                  uStack_754 = (double)(unaff_ESI._Ptr)->EngageRange;
                  fVar41 = GetDistance3DSquared((int)__return_storage_ptr__,(int)unaff_EDI);
                  fVar40 = (float)((float10)uStack_754 * (float10)uStack_754);
                  uStack_754 = (double)CONCAT44(uStack_754._4_4_,fVar40);
                  if (fVar41 < fVar40) {
                    if (cStack_755 != '\0') {
                      FormatLogMessage("Index: %d Unit is Cloaked, Enemy detected, Unlocking Cloak")
                      ;
                    }
                    pDVar29 = std::
                              _Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                              ::operator->((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                            *)(auStack_758 + -4));
                    SetCommand(pDVar29->DispatchObject,0x31,0,0,(char *)0x0,0);
                    pDVar29 = std::
                              _Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                              ::operator->((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                            *)(auStack_758 + -4));
                    pDVar29->CloakLocked = false;
                  }
                }
                pDVar29 = std::
                          _Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                          ::operator->((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                        *)(auStack_758 + -4));
                AVar31 = GetCurrentCommand(pDVar29->DispatchObject);
                if (AVar31 == CMD_ATTACK) {
                  GetPosition(__return_storage_ptr__,(int)unaff_EDI);
                  fVar40 = GetDistance3DSquared(__return_storage_ptr__,unaff_EDI);
                  uStack_754 = (double)fVar40;
                  pDVar29 = std::
                            _Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                            ::operator->((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                          *)(auStack_758 + -4));
                  fVar40 = Squared<float>(pDVar29->EngageRange);
                  if ((float)uStack_754 < fVar40) {
                    if (cStack_755 != '\0') {
                      _Var25 = std::
                               vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
                               ::begin(pvVar39);
                      std::
                      _Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                      ::operator-((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                   *)(auStack_758 + -8),
                                  (_Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                   *)_Var25);
                      FormatLogMessage("Index: %d Unit is Cloaked, Target In Range, Decloaking");
                    }
                    std::
                    _Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                    ::operator->((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                  *)(auStack_758 + -4));
                    pDVar29 = std::
                              _Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                              ::operator->((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                            *)(auStack_758 + -4));
                    iVar24 = pDVar29->DispatchObject;
                    bVar23 = IsAround(iVar24);
                    if (bVar23) {
                      Decloak(pDStack_724,iVar24,(int)__return_storage_ptr__);
                    }
                    pDVar29 = std::
                              _Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                              ::operator->((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                            *)(auStack_758 + -4));
                    pDVar29->CloakLocked = false;
                  }
                }
              }
              else {
                SetCommand((unaff_ESI._Ptr)->DispatchObject,0x30,0,0,(char *)0x0,0);
                (unaff_ESI._Ptr)->DecloakNextTick = false;
              }
            }
            else {
              pDVar29 = std::
                        _Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                        ::operator->((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                      *)(auStack_758 + -4));
              if (pDVar29->DeployTimer < BZ1Helper::m_TurnCounter) {
                pDVar29 = std::
                          _Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                          ::operator->((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                        *)(auStack_758 + -4));
                if (((pDVar29->SkipAIPCheck != false) || (*(char *)(iStack_740 + 0x1ae) != '\0')) &&
                   (iVar24 = GetPlayerHandle((int)local_744), iVar24 == 0)) {
                  pDVar29 = std::
                            _Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                            ::operator->((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                          *)(auStack_758 + -4));
                  pDVar30 = std::
                            _Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                            ::operator->((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                          *)(auStack_758 + -4));
                  AVar31 = GetCurrentCommand(pDVar29->DispatchObject);
                  if (AVar31 == pDVar30->Command) {
                    if (cStack_755 != '\0') {
                      _Var25 = std::
                               vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
                               ::begin(pvStack_74c);
                      std::
                      _Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                      ::operator-((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                   *)(auStack_758 + -8),
                                  (_Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                   *)_Var25);
                      FormatLogMessage(
                                      "Index: %d Command Identicle, setting CloakIdle time for 15 seconds."
                                      );
                    }
                    iVar24 = SecondsToTurns(___real_41700000);
                    iVar24 = BZ1Helper::m_TurnCounter + iVar24;
                    pDVar29 = std::
                              _Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                              ::operator->((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                            *)(auStack_758 + -4));
                    pDVar29->CloakIdleTime = iVar24;
                  }
                  else {
                    if (cStack_755 != '\0') {
                      _Var25 = std::
                               vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
                               ::begin(pvStack_74c);
                      std::
                      _Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                      ::operator-((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                   *)(auStack_758 + -8),
                                  (_Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                   *)_Var25);
                      FormatLogMessage(
                                      "Index: %d Command Different, Setting CloakIdle time for NOW."
                                      );
                    }
                    pDVar29 = std::
                              _Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                              ::operator->((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                            *)(auStack_758 + -4));
                    pDVar29->CloakIdleTime = BZ1Helper::m_TurnCounter;
                  }
                }
                pDVar29 = std::
                          _Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                          ::operator->((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                        *)(auStack_758 + -4));
                pDVar29->IsCloaked = false;
                if (cStack_755 != '\0') {
                  std::
                  _Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                  ::operator->((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                *)(auStack_758 + -4));
                  std::
                  _Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                  ::operator->((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                *)(auStack_758 + -4));
                  _Var25 = std::
                           vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
                           ::begin(pvStack_74c);
                  std::
                  _Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                  ::operator-((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                               *)(auStack_758 + -8),
                              (_Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                               *)_Var25);
                  FormatLogMessage(
                                  "Index: %d Unit was not cloaked! DeployTimer: %d, Time: %d, DeployTime: %f, Time: %d"
                                  );
                }
              }
            }
          }
        }
LAB_4fc22a40:
        pDVar29 = std::
                  _Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                  ::operator->((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                *)(auStack_758 + -4));
        pDVar30 = std::
                  _Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                  ::operator->((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                *)(auStack_758 + -4));
        AVar31 = GetCurrentCommand(pDVar29->DispatchObject);
        if (AVar31 != pDVar30->Command) {
          pDVar29 = std::
                    _Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                    ::operator->((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                  *)(auStack_758 + -4));
          AVar31 = GetCurrentCommand(pDVar29->DispatchObject);
          pDVar29 = std::
                    _Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                    ::operator->((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                  *)(auStack_758 + -4));
          pDVar29->Command = AVar31;
        }
        pvVar39 = pvStack_74c;
      }
      unaff_ESI._Ptr = unaff_ESI._Ptr + 1;
      std::
      _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
      ::
      _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                (&local_720,*(DispatchClass **)&pvVar39->field_0x4,(_Container_base0 *)pvVar39);
    } while (unaff_ESI._Ptr != local_720._Ptr);
  }
  return;
}


// ---------------------------------------------------------------------
// DispatchHelper::PreOrdnanceHit  @ 4fc22ac6  lines 1860-1939


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
DispatchHelper::PreOrdnanceHit
          (DispatchHelper *this,int param_1,int param_2,int param_3,char *param_4)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  long lVar4;
  float unaff_EBX;
  undefined1 unaff_BP;
  int *piVar5;
  float fVar6;
  char *pcVar7;
  bool *pbVar8;
  undefined1 uVar9;
  Vector local_c;
  
  iVar3 = GetIndependence(param_2);
  bVar1 = BZ1Helper::Logging;
  if ((iVar3 != 0) &&
     (piVar5 = *(int **)&this->DispatchList, piVar5 != *(int **)&(this->DispatchList).field_0x4)) {
    do {
      if (param_2 == *piVar5) {
        if ((piVar5[7] != 1) || (bVar2 = IsDeployed(*piVar5), bVar2)) {
          if ((piVar5[7] == 3) && ((piVar5[8] == 1 || (piVar5[8] == 0)))) {
            SetCommand(*piVar5,0x1b,0,0,(char *)0x0,0);
            fVar6 = ___real_41f00000;
            piVar5[8] = 0;
            iVar3 = SecondsToTurns(fVar6);
            piVar5[0xc] = iVar3 + BZ1Helper::m_TurnCounter;
            if (bVar1 == false) {
              return;
            }
            pcVar7 = "Index is: %d Minelayer Shot, Mining, IdleTime: %d";
          }
          else {
            if (*(char *)((int)piVar5 + 0x27) == '\0') {
              return;
            }
            if (piVar5[8] == 2) {
              return;
            }
            if (BZ1Helper::m_TurnCounter <= piVar5[0xc]) {
              return;
            }
            if (piVar5[8] == 4) {
              return;
            }
            if (piVar5[8] == 3) {
              return;
            }
            fVar6 = GetHealth(*piVar5);
            if ((float)piVar5[0x49] <= fVar6) {
              return;
            }
            pcVar7 = (char *)*piVar5;
            lVar4 = GetCurHealth((int)pcVar7);
            param_2 = GetOrdnanceDamageDealt(1,pcVar7,SUB41(unaff_EBX,0));
            if (piVar5[0x50] - lVar4 < piVar5[0x4d] / 10) {
              return;
            }
            iVar3 = param_2 * 4;
            if (param_2 * 4 < lVar4) {
              iVar3 = lVar4;
            }
            fVar6 = GetRandomFloat((float)iVar3);
            param_4 = (char *)(float)param_2;
            if ((float)param_4 <= fVar6) {
              return;
            }
            fVar6 = GetRandomFloat(__real_40000000);
            param_4 = (char *)(fVar6 + (float)___real_4008000000000000);
            pcVar7 = param_4;
            iVar3 = SecondsToTurns((float)param_4);
            uVar9 = SUB41(pcVar7,0);
            pbVar8 = (bool *)*piVar5;
            piVar5[0xc] = iVar3 + BZ1Helper::m_TurnCounter;
            iVar3 = GetTarget((int)pbVar8);
            piVar5[2] = iVar3;
            param_2 = param_2 & 0xffffff00;
            GetODFBool(0x4fc5d8dc,(char *)&param_2,(char *)0x0,pbVar8,(bool)uVar9);
            if ((piVar5[2] == 0) && ((char)param_2 != '\0')) {
              piVar5[2] = param_1;
            }
            SetIndependence(*piVar5,0);
            GetPositionNearOrFar
                      ((Vector *)param_1,___real_42200000,___real_42960000,0.0,unaff_EBX,
                       (bool)unaff_BP);
            Goto(*piVar5,&local_c,0);
            if ((*(char *)((int)piVar5 + 0x25) != '\0') &&
               (fVar6 = GetRandomFloat(1.0), fVar6 < __real_3f000000)) {
              Deploy(*piVar5);
            }
            piVar5[8] = 2;
            if (bVar1 == false) {
              return;
            }
            GetODFName(piVar5[0xc]);
            pcVar7 = "Flee Target Shot, Target is: \'%s\', IdleTime: %d";
          }
        }
        else {
          Defend(*piVar5,0);
          fVar6 = ___real_41f00000;
          piVar5[8] = 0;
          iVar3 = SecondsToTurns(fVar6);
          piVar5[0xc] = iVar3 + BZ1Helper::m_TurnCounter;
          if (bVar1 == false) {
            return;
          }
          pcVar7 = "Index is: %d Turret Shot, Deploying, IdleTime: %d";
        }
        FormatLogMessage(pcVar7);
        return;
      }
      piVar5 = piVar5 + 0x52;
    } while (piVar5 != *(int **)&(this->DispatchList).field_0x4);
  }
  return;
}


// ---------------------------------------------------------------------
// DispatchHelper::ReadChanceValues  @ 4fc22d85  lines 1942-1948


void __thiscall
DispatchHelper::ReadChanceValues
          (DispatchHelper *this,char *param_1,char *param_2,float *param_3,float param_4)

{
  bool bVar1;
  char *unaff_EBP;
  char **ppcVar2;
  
  bVar1 = OpenODF2(unaff_EBP);
  if (bVar1) {
    ppcVar2 = CommandList;
    do {
      GetODFFloat(param_1,param_2,*ppcVar2,(float *)((int)(param_3 + -0x13f1a818) + (int)ppcVar2),
                  param_4);
      ppcVar2 = ppcVar2 + 1;
    } while ((int)ppcVar2 < 0x4fc6a138);
  }
  return;
}


// ---------------------------------------------------------------------
// DispatchHelper::Cloak  @ 4fc22dd2  lines 1952-2027


void __thiscall DispatchHelper::Cloak(DispatchHelper *this,int param_1,int param_2)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  
  bVar2 = BZ1Helper::Logging;
  bVar1 = IsAround(param_1);
  if (bVar1) {
    piVar4 = *(int **)&MorphObjectHelper::m_MorphObjectHelper->MorphObjectList;
    iVar3 = (*(int *)&(MorphObjectHelper::m_MorphObjectHelper->MorphObjectList).field_0x4 -
            (int)piVar4) / 0x148;
    iVar5 = 0;
    if (0 < iVar3) {
      do {
        if ((*piVar4 == param_1) && (*(char *)((int)piVar4 + 0xb) != '\0')) {
          SetCommand(param_1,0x15,0,0,(char *)0x0,0);
          return;
        }
        iVar5 = iVar5 + 1;
        piVar4 = piVar4 + 0x52;
      } while (iVar5 < iVar3);
    }
    for (piVar4 = *(int **)&this->DispatchList; piVar4 != *(int **)&(this->DispatchList).field_0x4;
        piVar4 = piVar4 + 0x52) {
      if (*piVar4 == param_1) {
        bVar1 = IsPlayer(param_1);
        if (!bVar1) {
          piVar4[0x51] = param_2;
          *(undefined1 *)((int)piVar4 + 0x2d) = 1;
          if (bVar2) {
            FormatLogMessage("Cloak Command Given, Time: %d");
            return;
          }
          return;
        }
        bVar2 = IsDeployed(param_1);
        if (bVar2) {
          return;
        }
        Deploy(param_1);
        return;
      }
    }
    AddToDispatch(this,param_1,0.0,true,param_2,true,true,false,false);
  }
  return;
}


// ---------------------------------------------------------------------
// DispatchHelper::Decloak  @ 4fc22eb7  lines 2029-2076


void __thiscall DispatchHelper::Decloak(DispatchHelper *this,int param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  piVar4 = *(int **)&MorphObjectHelper::m_MorphObjectHelper->MorphObjectList;
  iVar3 = 0;
  iVar2 = (*(int *)&(MorphObjectHelper::m_MorphObjectHelper->MorphObjectList).field_0x4 -
          (int)piVar4) / 0x148;
  if (0 < iVar2) {
    do {
      if ((*piVar4 == param_1) && (*(char *)((int)piVar4 + 0xb) != '\0')) {
        SetCommand(param_1,0x15,0,0,(char *)0x0,0);
        return;
      }
      iVar3 = iVar3 + 1;
      piVar4 = piVar4 + 0x52;
    } while (iVar3 < iVar2);
  }
  piVar4 = *(int **)&this->DispatchList;
  while( true ) {
    if (piVar4 == *(int **)&(this->DispatchList).field_0x4) {
      return;
    }
    if (*piVar4 == param_1) break;
    piVar4 = piVar4 + 0x52;
  }
  bVar1 = IsPlayer(param_1);
  if (bVar1) {
    bVar1 = IsDeployed(param_1);
    if (bVar1) {
      Deploy(param_1);
      return;
    }
    return;
  }
  *(undefined1 *)((int)piVar4 + 0x2e) = 1;
  return;
}


// ---------------------------------------------------------------------
// DispatchHelper::ClearDispatch  @ 4fc22f48  lines 2174-2183


void __thiscall DispatchHelper::ClearDispatch(DispatchHelper *this,int param_1)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int local_14c [82];
  
  piVar3 = (int *)(param_1 * 0x148 + *(int *)&this->DispatchList);
  piVar4 = local_14c;
  for (iVar2 = 0x52; iVar2 != 0; iVar2 = iVar2 + -1) {
    *piVar4 = *piVar3;
    piVar3 = piVar3 + 1;
    piVar4 = piVar4 + 1;
  }
  bVar1 = IsPlayer(local_14c[0]);
  if (!bVar1) {
    SetCommand(local_14c[0],0,0,0,(char *)0x0,0);
  }
  return;
}

