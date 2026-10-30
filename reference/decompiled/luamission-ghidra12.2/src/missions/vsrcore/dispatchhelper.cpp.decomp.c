// Reconstructed by Ghidra from LuaMission.dll + LuaMission.pdb
// Original source file: /e:/github/vsr_dll_source/missions/vsrcore/dispatchhelper.cpp
// Functions are ordered by original source line. This is decompiler
// output, not the author's source: names/types come from the PDB,
// local variable names and control flow are reconstructed.


// ---------------------------------------------------------------------
// `dynamic_initializer_for_'TempDispatchBuffer''  @ 4fc0185e  lines 13-13


void __cdecl _dynamic_initializer_for__TempDispatchBuffer__(void)

{
  atexit(_dynamic_atexit_destructor_for__TempDispatchBuffer__);
  return;
}


// ---------------------------------------------------------------------
// DispatchHelper::~DispatchHelper  @ 4fc33d65  lines 23-25


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
// DispatchHelper::PostLoad  @ 4fc33d7a  lines 48-73


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
// DispatchHelper::AddToDispatch  @ 4fc33e37  lines 91-368


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
LAB_4fc34149:
          sprintf_s<64>(&local_144,pcVar18);
        }
        else {
          if (iVar5 == 2) {
            pcVar18 = "MediumWeaponSlot%d";
            goto LAB_4fc34149;
          }
          if (iVar5 == 3) {
            pcVar18 = "HardWeaponSlot%d";
            goto LAB_4fc34149;
          }
          if (iVar5 == 4) {
            pcVar18 = "ExtremeWeaponSlot%d";
            goto LAB_4fc34149;
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
    goto LAB_4fc34479;
  }
  if (local_14c == 0x53179125) {
    piVar8[7] = 3;
    goto LAB_4fc34479;
  }
  if ((uVar4 == 0xf9df4e76) || (uVar4 == 0x25fd9ee0)) {
    piVar8[7] = 6;
    goto LAB_4fc34479;
  }
  if (!param_7) {
    if (pcVar15 == (char *)0x0) {
LAB_4fc34371:
      iVar5 = GetRandomInt((int)unaff_EDI,(int)unaff_ESI);
      if (iVar5 == 0) {
        fVar12 = GetRandomFloat(1.0);
        if (fVar12 < local_174) goto LAB_4fc3441f;
        fVar12 = GetRandomFloat(1.0);
        if (local_17c <= fVar12) {
LAB_4fc34456:
          fVar12 = GetRandomFloat(1.0);
          if (local_178 <= fVar12) goto LAB_4fc34479;
          goto LAB_4fc343ab;
        }
      }
      else if (iVar5 == 1) {
        fVar12 = GetRandomFloat(1.0);
        if (local_17c <= fVar12) {
          fVar12 = GetRandomFloat(1.0);
          if (local_174 <= fVar12) goto LAB_4fc34456;
          goto LAB_4fc3441f;
        }
      }
      else {
        if (iVar5 != 2) goto LAB_4fc34479;
        fVar12 = GetRandomFloat(1.0);
        if (fVar12 < local_178) goto LAB_4fc343ab;
        fVar12 = GetRandomFloat(1.0);
        if (fVar12 < local_174) goto LAB_4fc3441f;
        fVar12 = GetRandomFloat(1.0);
        if (local_17c <= fVar12) goto LAB_4fc34479;
      }
      piVar8[7] = 2;
      goto LAB_4fc34479;
    }
    iVar5 = _strnicmp(pcVar15,"hunter",6);
    if (iVar5 != 0) {
      iVar5 = _strnicmp(pcVar15,"patrol",6);
      if (iVar5 == 0) {
        piVar8[7] = 2;
        goto LAB_4fc34479;
      }
      iVar5 = _strnicmp(pcVar15,"escort",6);
      if (iVar5 != 0) goto LAB_4fc34371;
LAB_4fc343ab:
      piVar8[7] = 5;
      goto LAB_4fc34479;
    }
  }
LAB_4fc3441f:
  piVar8[7] = 4;
LAB_4fc34479:
  fVar12 = GetRandomFloat(1.0);
  if (fVar12 < local_170) {
    memset(local_144,0,0x40);
    GetRace(param_1);
    sprintf_s<64>(&local_144,"%csuser");
    SetPilotClass(param_1,local_144);
  }
  pbVar1 = (byte *)((int)piVar8 + 0x25);
  uVar19 = 0xc4;
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
    uVar16 = 0x80;
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
// DispatchHelper::DeleteDispatchObject  @ 4fc3478f  lines 371-394


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
// DispatchHelper::Execute  @ 4fc347ee  lines 397-1857


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall DispatchHelper::Execute(DispatchHelper *this,BZ1Helper *param_1)

{
  int iVar1;
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
  Vector VVar21;
  _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
  _Var22;
  _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
  _Var23;
  BZ1Helper *pBVar24;
  bool bVar25;
  int iVar26;
  _Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_> _Var27;
  char *pcVar28;
  long lVar29;
  Vector *pVVar30;
  DispatchClass *pDVar31;
  DispatchClass *pDVar32;
  AiCommand AVar33;
  int iVar34;
  char *pcVar35;
  _Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_> unaff_ESI;
  vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_> *pvVar36;
  int *piVar37;
  float *pfVar38;
  undefined4 *puVar39;
  Vector *unaff_EDI;
  BZ1Helper *pBVar40;
  char **ppcVar41;
  char *pcVar42;
  float fVar43;
  Vector *__return_storage_ptr__;
  _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
  _Stack_788;
  _Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_> _Stack_784
  ;
  undefined4 uStack_780;
  char *pcStack_77c;
  vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_> *local_778;
  undefined8 uStack_774;
  int iStack_768;
  int iStack_764;
  DispatchClass *pDStack_760;
  double dStack_75c;
  int iStack_750;
  BZ1Helper *local_74c;
  undefined4 local_748;
  DispatchHelper *pDStack_744;
  _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
  local_740;
  Vector VStack_73c;
  int iStack_730;
  int local_72c;
  int local_728;
  double dStack_724;
  _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
  _Stack_718;
  _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
  _Stack_714;
  Vector *pVStack_710;
  float fStack_70c;
  float fStack_708;
  undefined1 auStack_704 [8];
  float fStack_6fc;
  _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
  _Stack_6f8;
  _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
  _Stack_6f4;
  _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
  _Stack_6f0;
  _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
  _Stack_6ec;
  _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
  _Stack_6e8;
  _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
  _Stack_6e4;
  _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
  _Stack_6e0;
  _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
  _Stack_6dc;
  _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
  a_Stack_6d8 [2];
  double dStack_6d0;
  undefined4 uStack_6c8;
  undefined4 uStack_6c4;
  float fStack_6c0;
  float fStack_6bc;
  float fStack_6b8;
  undefined4 uStack_6b4;
  undefined4 uStack_6b0;
  float fStack_6ac;
  float fStack_6a8;
  float fStack_6a4;
  float fStack_6a0;
  undefined4 uStack_69c;
  undefined4 uStack_698;
  undefined4 uStack_694;
  undefined4 uStack_690;
  undefined4 uStack_68c;
  undefined4 uStack_688;
  Vector VStack_684;
  Vector VStack_678;
  float fStack_66c;
  float fStack_668;
  float fStack_664;
  undefined4 uStack_660;
  undefined4 uStack_65c;
  undefined4 uStack_658;
  Vector VStack_654;
  undefined4 uStack_648;
  undefined4 uStack_644;
  undefined4 uStack_640;
  Vector VStack_630;
  _Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_> _Stack_624
  ;
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
  char *apcStack_4ec [142];
  char cStack_2b4;
  int iStack_264;
  int iStack_25c;
  char acStack_94 [4];
  char local_90 [60];
  char acStack_54 [72];
  uint local_c;
  
  local_c = __security_cookie ^ (uint)&_Stack_788;
  local_748 = param_1;
  uStack_780._3_1_ = BZ1Helper::Logging;
  local_740._Ptr = (DispatchClass *)this;
  local_72c = ObjectHelper::GetNumHandles(param_1->m_ObjectHelper);
  local_728 = BuildingHelper::GetNumBuildingObjects(BuildingHelper::m_BuildingHelper);
  local_778 = (vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
               *)&param_1->teamInfo[0].m_CPUBuildPodMaxDelay;
  local_74c = (BZ1Helper *)0x0;
  do {
    pBVar40 = local_74c;
    pvVar36 = local_778;
    pcVar42 = *(char **)local_778;
    if ((float)pcVar42 != ___real_00000000) {
      if (local_778[0x10].field_0x5 != '\0') {
        if (*(float *)(local_778 + -0x17) != 0.0) {
          iVar26 = SecondsToTurns(*(float *)&local_778->field_0x4);
          if (BZ1Helper::m_TurnCounter % iVar26 == 0) {
            fVar43 = GetRandomFloat(1.0);
            uStack_774 = (double)CONCAT44(fVar43,(DispatchClass *)uStack_774);
            if (fVar43 < *(float *)pvVar36) {
              memset(local_90,0,0x40);
              bVar25 = GetBuildItem(0,(char *)0x4,(int *)"daywrecker",0,(char *)0x0,
                                    (char *)unaff_EDI,(char *)unaff_ESI);
              if (bVar25) {
                iVar26 = (*misnImport.GetScrap)((int)pBVar40);
                if (-1 < iVar26) {
                  bVar25 = DoesODFExist(local_90);
                  if (bVar25) {
                    iVar26 = BuildingHelper::GetNumBuildings
                                       (BuildingHelper::m_BuildingHelper,(int)pBVar40,4,false,true,
                                        false,0,(char *)0x0,(char *)0x0);
                    pBVar24 = local_74c;
                    if (0 < iVar26) {
                      fStack_70c = 0.0;
                      fStack_708 = 0.0;
                      auStack_704._0_4_ = 0.0;
                      iVar26 = BuildingHelper::GetRandomBuilding
                                         (BuildingHelper::m_BuildingHelper,(int)local_74c,4,true,
                                          true,true,0,(char *)0x0,(char *)0x0,0.0,(Vector)ZEXT812(0)
                                         );
                      GetPosition(iVar26,(Vector *)(auStack_704 + 4));
                      VStack_73c.x = 0.0;
                      if (0 < local_72c) {
                        iVar26 = 0;
                        do {
                          iVar34 = *(int *)&local_748->m_ObjectHelper->HandleList + iVar26;
                          if (*(BZ1Helper **)(iVar34 + 0x1c) == pBVar24) {
                            fVar43 = *(float *)(iVar34 + 0x24);
                            uStack_774 = (double)CONCAT44(fVar43,(DispatchClass *)uStack_774);
                            dStack_6d0 = (double)fVar43;
                            GetDistance3DSquared(unaff_EDI,(Vector *)unaff_ESI);
                            pvVar36 = local_778;
                            fVar43 = (float)((float10)dStack_6d0 * (float10)dStack_6d0);
                            uStack_774 = (double)CONCAT44(fVar43,(DispatchClass *)uStack_774);
                            if ((float)pcVar42 < fVar43) {
                              VVar19.y = fStack_6fc;
                              VVar19.x = (float)auStack_704._4_4_;
                              VVar19.z = (float)_Stack_6f8._Ptr;
                              BZ1Helper::BuildAt(local_748,(int)*(float *)(local_778 + -0x17),
                                                 local_90,VVar19,1);
                              pBVar40 = local_74c;
                              goto LAB_4fc34a11;
                            }
                          }
                          VStack_73c.x = (float)((int)VStack_73c.x + 1);
                          iVar26 = iVar26 + 0x5c;
                        } while ((int)VStack_73c.x < local_72c);
                      }
                      pvVar36 = local_778;
                      pBVar40 = pBVar24;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
LAB_4fc34a11:
    _Var22._Ptr = local_740._Ptr;
    local_74c = (BZ1Helper *)((int)&pBVar40->_padding_ + 1);
    local_778 = pvVar36 + 0xd7;
  } while ((int)local_74c < 0x10);
  pvVar36 = (vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_> *)
            &(local_740._Ptr)->DispatchTarget;
  uStack_774 = (double)CONCAT44(uStack_774._4_4_,pvVar36);
  std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
  ::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
            ((_Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
              *)((int)&uStack_774 + 4),(DispatchClass *)(local_740._Ptr)->FleeTarget,
             (_Container_base0 *)pvVar36);
  __return_storage_ptr__ = uStack_774._4_4_;
  std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
  ::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
            ((_Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
              *)&dStack_724,(DispatchClass *)(_Var22._Ptr)->FleeTarget,(_Container_base0 *)pvVar36);
  std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
  ::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
            ((_Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
              *)&VStack_73c,*(DispatchClass **)pvVar36,(_Container_base0 *)pvVar36);
  _Var27 = std::
           remove_if<std::_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>,bool_(__cdecl*)(DispatchHelper::DispatchClass_const_&)>
                     ((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                       )VStack_73c.x,
                      (_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                       )dStack_724._0_4_,(_func___cdecl_bool_DispatchClass_ptr *)unaff_EDI);
  std::vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>::erase
            (pvVar36,(DispatchClass *)&_Stack_714,*(DispatchClass **)_Var27);
  std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
  ::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
            (&_Stack_788,*(DispatchClass **)pvVar36,(_Container_base0 *)pvVar36);
  std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
  ::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
            (&local_740,(DispatchClass *)(_Var22._Ptr)->FleeTarget,(_Container_base0 *)pvVar36);
  if (_Stack_788._Ptr != local_740._Ptr) {
    do {
      std::
      _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
      ::
      _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                (&_Stack_6f8,*(DispatchClass **)pvVar36,(_Container_base0 *)pvVar36);
      pcVar28 = (char *)(((int)_Stack_788._Ptr - (int)_Stack_6f8._Ptr) / 0x148);
      pcStack_77c = pcVar28;
      iStack_768 = GetTeamNum((_Stack_788._Ptr)->DispatchObject);
      iStack_764 = (int)local_74c->teamInfo + iStack_768 * 0xa14 + -0x90;
      GetPosition((_Stack_788._Ptr)->DispatchObject,&VStack_73c);
      bVar25 = IsAround(*(int *)&(_Stack_788._Ptr)->DispatchTarget);
      local_748 = (BZ1Helper *)CONCAT31(local_748._1_3_,bVar25);
      iVar26 = GetIndependence((_Stack_788._Ptr)->DispatchObject);
      local_748 = (BZ1Helper *)CONCAT13(iVar26 != 0,(uint3)local_748);
      iVar26 = GetCurrentWho((_Stack_788._Ptr)->DispatchObject);
      dStack_724 = (double)CONCAT44(dStack_724._4_4_,iVar26);
      if ((_Stack_788._Ptr)->CurrTeam != iStack_768) {
        iVar26 = (_Stack_788._Ptr)->DispatchType;
        iVar34 = (_Stack_788._Ptr)->CurrTeam * 0xa14;
        if (iVar26 == 2) {
          piVar37 = (int *)((int)local_74c->teamInfo + iVar34 + 0xac);
          *piVar37 = *piVar37 + -1;
          *(int *)(iStack_764 + 0x13c) = *(int *)(iStack_764 + 0x13c) + 1;
        }
        else if (iVar26 == 4) {
          piVar37 = (int *)((int)local_74c->teamInfo + iVar34 + 0xb0);
          *piVar37 = *piVar37 + -1;
          *(int *)(iStack_764 + 0x140) = *(int *)(iStack_764 + 0x140) + 1;
        }
        else if (iVar26 == 5) {
          piVar37 = (int *)((int)local_74c->teamInfo + iVar34 + 0xb4);
          *piVar37 = *piVar37 + -1;
          *(int *)(iStack_764 + 0x144) = *(int *)(iStack_764 + 0x144) + 1;
        }
        ClearDispatch(pDStack_744,(int)pcVar28);
        (_Stack_788._Ptr)->CurrTeam = iStack_768;
      }
      iVar26 = iStack_768;
      bVar25 = IsPlayer((_Stack_788._Ptr)->DispatchObject);
      if (!bVar25) {
        iVar26 = GetPlayerHandle(iVar26);
        _Var22._Ptr = _Stack_788._Ptr;
        if ((iVar26 != 0) ||
           ((local_748._3_1_ != '\x01' && ((_Stack_788._Ptr)->DispatchState != 2))))
        goto LAB_4fc36efa;
        iVar26 = (_Stack_788._Ptr)->DispatchState;
        if (iVar26 == 0) {
          if ((_Stack_788._Ptr)->IdleTime <= BZ1Helper::m_TurnCounter) {
            bVar25 = IsIdle((_Stack_788._Ptr)->DispatchObject);
            _Var22._Ptr = _Stack_788._Ptr;
            if ((bVar25) &&
               (((_Stack_788._Ptr)->SkipAIPCheck != false || (*(char *)(iStack_764 + 0x1ae) != '\0')
                ))) {
              iVar26 = (_Stack_788._Ptr)->DispatchType;
              if (iVar26 == 1) {
                iVar26 = (*misnImport.GetNearestEnemy)((_Stack_788._Ptr)->DispatchObject);
                GetPosition(iVar26,&VStack_5dc);
                fVar43 = (_Stack_788._Ptr)->EngageRange + (float)___real_4049000000000000;
                dStack_75c = (double)fVar43;
                uStack_774._0_4_ = (DispatchClass *)fVar43;
                GetDistance2DSquared<Vector,Vector>(__return_storage_ptr__,unaff_EDI);
                fVar43 = (float)((float10)dStack_75c * (float10)dStack_75c);
                uStack_774 = (double)CONCAT44(uStack_774._4_4_,fVar43);
                if (fVar43 < (float)pcVar42) {
                  iVar26 = GetRandomInt((int)__return_storage_ptr__,(int)unaff_EDI);
                  uStack_774 = (double)CONCAT44(uStack_774._4_4_,iVar26);
                  iStack_750 = GetRandomInt((int)__return_storage_ptr__,(int)unaff_EDI);
                  pcVar28 = (char *)0x0;
                  *(undefined4 *)&(_Stack_788._Ptr)->DispatchTarget = 0;
                  uStack_780 = (DispatchClass *)0x0;
                  pDVar31 = (DispatchClass *)
                            GetRandomTeam(1,1,SUB41(__return_storage_ptr__,0),SUB41(unaff_EDI,0));
                  if ((int)pDVar31 < 0) {
                    pDVar31 = (DispatchClass *)
                              GetRandomTeam(0,1,SUB41(__return_storage_ptr__,0),SUB41(unaff_EDI,0));
                  }
                  pDStack_760 = (DispatchClass *)0x0;
                  if (-1 < (int)pDVar31) {
                    pDStack_760 = pDVar31;
                  }
                  pcStack_77c = (char *)0x0;
                  pVStack_710 = (Vector *)0x0;
                  fStack_70c = 0.0;
                  fStack_708 = 0.0;
                  if (_Stack_784._3_1_ != '\0') {
                    std::
                    _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                    ::
                    _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                              (&_Stack_6e8,*(DispatchClass **)pvVar36,(_Container_base0 *)pvVar36);
                    FormatLogMessage(
                                    "Index is: %d, DispatchMode is: %d, DispatchMethod is: %d, RandomTargetTeam: %d"
                                    );
                  }
                  iVar26 = (int)pDStack_760 * 0xa14;
                  pcVar35 = *(char **)((int)local_74c->teamInfo + iVar26 + 0xc);
                  if (((pcVar35 == (char *)0x0) &&
                      (pcVar35 = *(char **)((int)local_74c->teamInfo + iVar26 + 0x10),
                      pcVar35 == (char *)0x0)) &&
                     (pcVar35 = *(char **)((int)local_74c->teamInfo + iVar26 + 0x18),
                     pcVar35 == (char *)0x0)) {
                    pcVar35 = *(char **)((int)local_74c->teamInfo + iVar26 + 0x14);
                    if (pcVar35 != (char *)0x0) goto LAB_4fc35f01;
                  }
                  else {
LAB_4fc35f01:
                    pcStack_77c = pcVar35;
                    if (pcVar35 != (char *)0x0) {
                      GetPosition((int)pcVar35,&VStack_5d0);
                      pVStack_710 = (Vector *)VStack_5d0.x;
                      fStack_70c = VStack_5d0.y;
                      fStack_708 = VStack_5d0.z;
                      pcVar28 = (char *)uStack_780;
                    }
                  }
                  pcVar35 = pcStack_77c;
                  if ((DispatchClass *)uStack_774 == (DispatchClass *)0x0) {
                    pcStack_77c = (char *)0x0;
                    if (iStack_750 == 0) {
                      if (0 < local_72c) {
                        uStack_774 = (double)CONCAT44(uStack_774._4_4_,local_72c);
                        pDStack_760 = (DispatchClass *)0x0;
                        do {
                          if (local_72c < 2) {
LAB_4fc36793:
                            puVar39 = (undefined4 *)
                                      ((int)pDStack_760->CloakChance +
                                      *(int *)&BuildingHelper::m_BuildingHelper->BuildingList +
                                      -0x4c);
                            ppcVar41 = apcStack_4ec;
                            for (iVar26 = 0x116; pcVar28 = apcStack_4ec[0], iVar26 != 0;
                                iVar26 = iVar26 + -1) {
                              *ppcVar41 = (char *)*puVar39;
                              puVar39 = puVar39 + 1;
                              ppcVar41 = ppcVar41 + 1;
                            }
                            if (((iStack_264 == iStack_768) && (cStack_2b4 != '\0')) &&
                               (0 < iStack_25c)) {
                              GetDistance2DSquared<Vector,Vector>(__return_storage_ptr__,unaff_EDI);
                              dStack_75c = (double)CONCAT44(dStack_75c._4_4_,pcVar42);
                              if ((float)pcStack_77c < (float)pcVar42) {
                                uStack_780 = (DispatchClass *)pcVar28;
                                pcStack_77c = pcVar42;
                                goto LAB_4fc36806;
                              }
                            }
                            pcVar28 = (char *)uStack_780;
                          }
                          else {
                            fVar43 = GetRandomFloat(1.0);
                            if (fVar43 < __real_3f000000) goto LAB_4fc36793;
                          }
LAB_4fc36806:
                          pDStack_760 = (DispatchClass *)(pDStack_760[3].CloakChance + 0xd);
                          iVar26 = (int)(DispatchClass *)uStack_774 + -1;
                          uStack_774 = (double)CONCAT44(uStack_774._4_4_,iVar26);
                        } while (iVar26 != 0);
                        goto LAB_4fc36823;
                      }
LAB_4fc3696a:
                      _Var22._Ptr = _Stack_788._Ptr;
                      iVar26 = SecondsToTurns(___real_40a00000);
                      (_Var22._Ptr)->IdleTime = iVar26 + BZ1Helper::m_TurnCounter;
                      if (_Stack_784._3_1_ == '\0') goto LAB_4fc369be;
                      std::
                      _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                      ::
                      _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                (&_Stack_714,*(DispatchClass **)local_778,
                                 (_Container_base0 *)local_778);
LAB_4fc3629a:
                      FormatLogMessage(
                                      "Index is: %d Mode is: %d Method is: %d No Valid Target, IdleTime: %d"
                                      );
                    }
                    else {
                      if (iStack_750 == 1) {
                        auStack_704._0_4_ = 0.0;
                        pVVar30 = (Vector *)auStack_704;
                        auStack_704._4_4_ = 0.0;
                        fStack_6fc = 0.0;
LAB_4fc36703:
                        pcVar28 = (char *)BuildingHelper::GetRandomBuilding
                                                    (BuildingHelper::m_BuildingHelper,iStack_768,1,
                                                     true,true,true,0,(char *)0x0,(char *)0x0,0.0,
                                                     *pVVar30);
                        uStack_780 = (DispatchClass *)pcVar28;
LAB_4fc36823:
                        if (pcVar28 == (char *)0x0) goto LAB_4fc3696a;
                      }
                      else {
                        if (iStack_750 != 2) goto LAB_4fc3696a;
                        pcVar28 = *(char **)(iStack_764 + 0x9c);
                        uStack_780 = (DispatchClass *)pcVar28;
                        if (pcVar28 == (char *)0x0) {
                          pcVar28 = *(char **)(iStack_764 + 0xa0);
                          uStack_780 = (DispatchClass *)pcVar28;
                          if (pcVar28 == (char *)0x0) {
                            pcVar28 = *(char **)(iStack_764 + 0xa8);
                            uStack_780 = (DispatchClass *)pcVar28;
                            if (pcVar28 == (char *)0x0) {
                              pcVar28 = *(char **)(iStack_764 + 0xa4);
                              uStack_780 = (DispatchClass *)pcVar28;
                              if (pcVar28 == (char *)0x0) {
                                VStack_654.x = 0.0;
                                VStack_654.y = 0.0;
                                VStack_654.z = 0.0;
                                pVVar30 = &VStack_654;
                                uStack_780 = (DispatchClass *)0x0;
                                goto LAB_4fc36703;
                              }
                            }
                          }
                        }
                      }
                      if (*(int *)&(_Stack_788._Ptr)->DispatchTarget == 0) {
                        *(char **)&(_Stack_788._Ptr)->DispatchTarget = pcVar28;
                      }
                      GetPosition(*(int *)&(_Stack_788._Ptr)->DispatchTarget,&VStack_57c);
                      dStack_75c = (double)CONCAT44(dStack_75c._4_4_,_Stack_788._Ptr);
                      VVar7.y = fStack_708;
                      VVar7.x = fStack_70c;
                      VVar7.z = VStack_57c.x;
                      VVar16.y = VStack_57c.z;
                      VVar16.x = VStack_57c.y;
                      VVar16.z = ___real_42480000;
                      pVVar30 = GetPositionNearOrFar
                                          (pVStack_710,VVar7,VVar16,___real_437a0000,
                                           (float)__return_storage_ptr__,SUB41(unaff_EDI,0));
                      *(float *)((int)dStack_75c._0_4_ + 0xc) = pVVar30->x;
                      *(float *)((int)dStack_75c._0_4_ + 0x10) = pVVar30->y;
                      *(float *)((int)dStack_75c._0_4_ + 0x14) = pVVar30->z;
                      Goto((_Stack_788._Ptr)->DispatchObject,&(_Stack_788._Ptr)->DispatchSpot,0);
                      _Var22._Ptr = _Stack_788._Ptr;
                      fVar43 = GetRandomFloat(__real_41200000);
                      (_Var22._Ptr)->RandomDist = fVar43 + (float)___real_4024000000000000;
                      (_Stack_788._Ptr)->IdleTime = 0;
                      (_Stack_788._Ptr)->DispatchState = 1;
                      if (_Stack_784._3_1_ == '\0') goto LAB_4fc369be;
                      memset(TempGetODFName,0,0x40);
                      GetODFName((int)__return_storage_ptr__,(char *)unaff_EDI);
                      std::
                      _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                      ::
                      _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                (&_Stack_718,*(DispatchClass **)local_778,
                                 (_Container_base0 *)local_778);
LAB_4fc3694e:
                      FormatLogMessage(
                                      "Index is: %d Mode is: %d Method is: %d Spot is: %f %f %f Target Is: \'%s\'"
                                      );
                    }
                  }
                  else if ((DispatchClass *)uStack_774 == (DispatchClass *)0x1) {
                    pcStack_77c = (char *)0x7f7fffff;
                    iVar26 = ScrapHelper::GetNumScrapObjects(ScrapHelper::m_ScrapHelper);
                    if (iStack_750 == 0) {
                      iVar34 = 0;
                      if (0 < iVar26) {
                        do {
                          if (iVar26 < 2) {
LAB_4fc363c1:
                            iVar1 = *(int *)(*(int *)&ScrapHelper::m_ScrapHelper->ScrapList +
                                            iVar34 * 4);
                            uStack_774 = (double)CONCAT44(uStack_774._4_4_,iVar1);
                            GetPosition(iVar1,&VStack_5a0);
                            GetDistance2DSquared<Vector,Vector>(__return_storage_ptr__,unaff_EDI);
                            dStack_75c = (double)CONCAT44(dStack_75c._4_4_,pcVar42);
                            if ((float)pcVar42 < (float)pcStack_77c) {
                              *(DispatchClass **)&(_Stack_788._Ptr)->DispatchTarget =
                                   (DispatchClass *)uStack_774;
                              pcStack_77c = pcVar42;
                            }
                          }
                          else {
                            fVar43 = GetRandomFloat(1.0);
                            if (fVar43 < __real_3f000000) goto LAB_4fc363c1;
                          }
                          iVar34 = iVar34 + 1;
                        } while (iVar34 < iVar26);
                      }
                    }
                    else if (iStack_750 == 1) {
                      if (0 < iVar26) {
                        iVar26 = GetRandomInt((int)__return_storage_ptr__,(int)unaff_EDI);
                        *(undefined4 *)&(_Stack_788._Ptr)->DispatchTarget =
                             *(undefined4 *)
                              (*(int *)&ScrapHelper::m_ScrapHelper->ScrapList + iVar26 * 4);
                      }
                    }
                    else if (iStack_750 == 2) {
                      pcStack_77c = (char *)0x0;
                      iVar34 = 0;
                      if (0 < iVar26) {
                        do {
                          if (iVar26 < 2) {
LAB_4fc36317:
                            iVar1 = *(int *)(*(int *)&ScrapHelper::m_ScrapHelper->ScrapList +
                                            iVar34 * 4);
                            uStack_774 = (double)CONCAT44(uStack_774._4_4_,iVar1);
                            GetPosition(iVar1,&VStack_5ac);
                            GetDistance2DSquared<Vector,Vector>(__return_storage_ptr__,unaff_EDI);
                            dStack_75c = (double)CONCAT44(dStack_75c._4_4_,pcVar42);
                            if ((float)pcStack_77c < (float)pcVar42) {
                              *(DispatchClass **)&(_Stack_788._Ptr)->DispatchTarget =
                                   (DispatchClass *)uStack_774;
                              pcStack_77c = pcVar42;
                            }
                          }
                          else {
                            fVar43 = GetRandomFloat(1.0);
                            if (fVar43 < __real_3f000000) goto LAB_4fc36317;
                          }
                          iVar34 = iVar34 + 1;
                        } while (iVar34 < iVar26);
                      }
                    }
                    GetPosition(*(int *)&(_Stack_788._Ptr)->DispatchTarget,&VStack_594);
                    dStack_75c = (double)CONCAT44(dStack_75c._4_4_,_Stack_788._Ptr);
                    VVar11.y = VStack_594.y;
                    VVar11.x = VStack_594.x;
                    VVar11.z = VStack_594.z;
                    pVVar30 = GetPositionNear(&VStack_51c,VVar11,__real_41200000,___real_42480000);
                    *(float *)((int)dStack_75c._0_4_ + 0xc) = pVVar30->x;
                    *(float *)((int)dStack_75c._0_4_ + 0x10) = pVVar30->y;
                    *(float *)((int)dStack_75c._0_4_ + 0x14) = pVVar30->z;
                    if (_Stack_784._3_1_ != '\0') {
                      std::
                      _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                      ::
                      _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                (&_Stack_6dc,*(DispatchClass **)local_778,
                                 (_Container_base0 *)local_778);
                      FormatLogMessage("Index is: %d Mode is: %d Method is: %d Spot is: %f %f %f");
                    }
                    dStack_75c = (double)CONCAT44(dStack_75c._4_4_,_Stack_788._Ptr);
                    fStack_66c = ((_Stack_788._Ptr)->DispatchSpot).x;
                    fStack_668 = ((_Stack_788._Ptr)->DispatchSpot).y;
                    fStack_664 = ((_Stack_788._Ptr)->DispatchSpot).z;
                    pcVar42 = (char *)__real_3dcccccd;
                    if (fStack_668 * fStack_668 + fStack_66c * fStack_66c + fStack_664 * fStack_664
                        < __real_3dcccccd) {
                      uStack_660 = 0;
                      uStack_65c = 0;
                      uStack_658 = 0;
                      iVar26 = BZ1Helper::GetRandomObject
                                         (local_74c,-1,0,false,0,false,true,true,0,(char *)0x0,
                                          (char *)0x0,0.0,(Vector)ZEXT812(0));
                      *(int *)((int)dStack_75c._0_4_ + 4) = iVar26;
                      GetPosition(*(int *)&(_Stack_788._Ptr)->DispatchTarget,&VStack_588);
                      dStack_75c = (double)CONCAT44(dStack_75c._4_4_,_Stack_788._Ptr);
                      VVar12.y = VStack_588.y;
                      VVar12.x = VStack_588.x;
                      VVar12.z = VStack_588.z;
                      pVVar30 = GetPositionNear(aVStack_510,VVar12,__real_41200000,___real_42480000)
                      ;
                      *(float *)((int)dStack_75c._0_4_ + 0xc) = pVVar30->x;
                      *(float *)((int)dStack_75c._0_4_ + 0x10) = pVVar30->y;
                      *(float *)((int)dStack_75c._0_4_ + 0x14) = pVVar30->z;
                      if (_Stack_784._3_1_ != '\0') {
                        std::
                        _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                        ::
                        _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                  (a_Stack_6d8,*(DispatchClass **)local_778,
                                   (_Container_base0 *)local_778);
                        FormatLogMessage(
                                        "Pathing Failed, using random object. Index is: %d Mode is: %d Method is: %d Spot is: %f %f %f."
                                        );
                      }
                    }
                    Goto((_Stack_788._Ptr)->DispatchObject,&(_Stack_788._Ptr)->DispatchSpot,0);
                    _Var22._Ptr = _Stack_788._Ptr;
                    fVar43 = GetRandomFloat(___real_42480000);
                    (_Var22._Ptr)->RandomDist = fVar43 + (float)___real_4024000000000000;
                    (_Stack_788._Ptr)->IdleTime = 0;
                    (_Stack_788._Ptr)->DispatchState = 1;
                  }
                  else if ((DispatchClass *)uStack_774 == (DispatchClass *)0x2) {
                    pcStack_77c = (char *)0x7f7fffff;
                    if (iStack_750 == 0) {
                      if (0 < local_72c) {
                        uStack_774 = (double)CONCAT44(uStack_774._4_4_,local_72c);
                        pDStack_760 = (DispatchClass *)0x0;
                        do {
                          pDVar31 = pDStack_760;
                          if (local_72c < 2) {
LAB_4fc36028:
                            puVar39 = (undefined4 *)
                                      ((int)pDVar31->CloakChance +
                                      *(int *)&BuildingHelper::m_BuildingHelper->BuildingList +
                                      -0x4c);
                            ppcVar41 = apcStack_4ec;
                            for (iVar26 = 0x116; pcVar28 = apcStack_4ec[0], iVar26 != 0;
                                iVar26 = iVar26 + -1) {
                              *ppcVar41 = (char *)*puVar39;
                              puVar39 = puVar39 + 1;
                              ppcVar41 = ppcVar41 + 1;
                            }
                            bVar25 = IsTeamAllied(iStack_768,iStack_264);
                            if (((!bVar25) && (cStack_2b4 != '\0')) && (0 < iStack_25c)) {
                              GetDistance2DSquared<Vector,Vector>(__return_storage_ptr__,unaff_EDI);
                              dStack_75c = (double)CONCAT44(dStack_75c._4_4_,pcVar42);
                              if ((float)pcVar42 < (float)pcStack_77c) {
                                uStack_780 = (DispatchClass *)pcVar28;
                                pcStack_77c = pcVar42;
                                goto LAB_4fc360a4;
                              }
                            }
                            pcVar28 = (char *)uStack_780;
                          }
                          else {
                            fVar43 = GetRandomFloat(1.0);
                            if (fVar43 < __real_3f000000) goto LAB_4fc36028;
                          }
LAB_4fc360a4:
                          pDStack_760 = (DispatchClass *)(pDStack_760[3].CloakChance + 0xd);
                          iVar26 = (int)(DispatchClass *)uStack_774 + -1;
                          uStack_774 = (double)CONCAT44(uStack_774._4_4_,iVar26);
                        } while (iVar26 != 0);
                        goto LAB_4fc360bf;
                      }
                    }
                    else {
                      if (iStack_750 == 1) {
                        VStack_678.x = 0.0;
                        pVVar30 = &VStack_678;
                        VStack_678.y = 0.0;
                        VStack_678.z = 0.0;
LAB_4fc35f9c:
                        pcVar28 = (char *)BuildingHelper::GetRandomBuilding
                                                    (BuildingHelper::m_BuildingHelper,iStack_768,4,
                                                     true,true,true,0,(char *)0x0,(char *)0x0,0.0,
                                                     *pVVar30);
                      }
                      else {
                        if (iStack_750 != 2) goto LAB_4fc36246;
                        if (pcVar35 == (char *)0x0) {
                          VStack_684.x = 0.0;
                          pVVar30 = &VStack_684;
                          VStack_684.y = 0.0;
                          VStack_684.z = 0.0;
                          goto LAB_4fc35f9c;
                        }
                        pcVar28 = pcVar35;
                      }
                      uStack_780 = (DispatchClass *)pcVar28;
LAB_4fc360bf:
                      if (pcVar28 != (char *)0x0) {
                        GetPosition((int)pcVar28,&VStack_5c4);
                        dStack_75c._0_4_ = _Stack_788._Ptr;
                        VVar21.y = VStack_5c4.y;
                        VVar21.x = VStack_5c4.x;
                        VVar21.z = VStack_5c4.z;
                        iVar26 = BuildingHelper::GetRandomBuilding
                                           (BuildingHelper::m_BuildingHelper,iStack_768,4,true,true,
                                            true,0,(char *)0x0,(char *)0x0,___real_43480000,VVar21);
                        *(int *)&(dStack_75c._0_4_)->DispatchTarget = iVar26;
                        if (*(int *)&(_Stack_788._Ptr)->DispatchTarget == 0) {
                          *(DispatchClass **)&(_Stack_788._Ptr)->DispatchTarget = uStack_780;
                        }
                        GetPosition(*(int *)&(_Stack_788._Ptr)->DispatchTarget,&VStack_5b8);
                        dStack_75c = (double)CONCAT44(dStack_75c._4_4_,_Stack_788._Ptr);
                        VVar6.y = VStack_73c.z;
                        VVar6.x = VStack_73c.y;
                        VVar6.z = VStack_5b8.x;
                        VVar15.y = VStack_5b8.z;
                        VVar15.x = VStack_5b8.y;
                        VVar15.z = ___real_42480000;
                        pVVar30 = GetPositionNearOrFar
                                            ((Vector *)VStack_73c.x,VVar6,VVar15,___real_437a0000,
                                             (float)__return_storage_ptr__,SUB41(unaff_EDI,0));
                        *(float *)((int)dStack_75c._0_4_ + 0xc) = pVVar30->x;
                        *(float *)((int)dStack_75c._0_4_ + 0x10) = pVVar30->y;
                        *(float *)((int)dStack_75c._0_4_ + 0x14) = pVVar30->z;
                        Goto((_Stack_788._Ptr)->DispatchObject,&(_Stack_788._Ptr)->DispatchSpot,0);
                        _Var22._Ptr = _Stack_788._Ptr;
                        fVar43 = GetRandomFloat((_Stack_788._Ptr)->EngageRange);
                        (_Var22._Ptr)->RandomDist = fVar43 + (float)___real_4059000000000000;
                        (_Stack_788._Ptr)->IdleTime = 0;
                        (_Stack_788._Ptr)->DispatchState = 1;
                        if (_Stack_784._3_1_ != '\0') {
                          memset(TempGetODFName,0,0x40);
                          GetODFName((int)__return_storage_ptr__,(char *)unaff_EDI);
                          std::
                          _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                          ::
                          _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                    (&_Stack_6e4,*(DispatchClass **)local_778,
                                     (_Container_base0 *)local_778);
                          goto LAB_4fc3694e;
                        }
                        goto LAB_4fc369be;
                      }
                    }
LAB_4fc36246:
                    _Var22._Ptr = _Stack_788._Ptr;
                    iVar26 = SecondsToTurns(___real_40a00000);
                    (_Var22._Ptr)->IdleTime = iVar26 + BZ1Helper::m_TurnCounter;
                    if (_Stack_784._3_1_ != '\0') {
                      std::
                      _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                      ::
                      _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                (&_Stack_6e0,*(DispatchClass **)local_778,
                                 (_Container_base0 *)local_778);
                      goto LAB_4fc3629a;
                    }
                  }
                }
              }
              else if (iVar26 == 2) {
                if (0 < *(int *)(iStack_764 + 0x130)) {
                  if (*(int *)(iStack_764 + 0x13c) < *(int *)(iStack_764 + 0x130)) {
                    *(int *)(iStack_764 + 0x13c) = *(int *)(iStack_764 + 0x13c) + 1;
                    iVar26 = iStack_768 * 0xc;
                    if (*(int *)(local_74c[1].teamInfo[0].BaseSlotName[1] + iVar26 + 0x23) -
                        *(int *)(local_74c[1].teamInfo[0].BaseSlotName[1] + iVar26 + 0x1f) >> 2 < 1)
                    {
                      fVar43 = GetRandomFloat(1.0);
                      dStack_75c = (double)fVar43;
                      if ((float)___real_3fc99999a0000000 <= fVar43) {
                        uStack_690 = 0;
                        uStack_68c = 0;
                        uStack_688 = 0;
                        iVar26 = 1;
                      }
                      else {
                        uStack_69c = 0;
                        uStack_698 = 0;
                        uStack_694 = 0;
                        iVar26 = 3;
                      }
                      iVar26 = BuildingHelper::GetRandomBuilding
                                         (BuildingHelper::m_BuildingHelper,iStack_768,iVar26,true,
                                          true,true,0,(char *)0x0,(char *)0x0,0.0,(Vector)ZEXT812(0)
                                         );
                      if ((dStack_75c < ___real_3fb99999a0000000) || (iVar26 == 0)) {
                        pDStack_760 = _Stack_788._Ptr;
                        fVar43 = (_Stack_788._Ptr)->EngageRange * (float)___real_4014000000000000;
                        uStack_774 = (double)CONCAT44(uStack_774._4_4_,fVar43);
                        VVar10.y = VStack_73c.y;
                        VVar10.x = VStack_73c.x;
                        VVar10.z = VStack_73c.z;
                        pVVar30 = GetPositionNear(aVStack_534,VVar10,___real_42c80000,fVar43);
                        pDVar31 = pDStack_760;
                      }
                      else {
                        GetPosition(iVar26,&VStack_5e8);
                        uStack_774 = (double)CONCAT44(uStack_774._4_4_,_Stack_788._Ptr);
                        VVar9.y = VStack_5e8.y;
                        VVar9.x = VStack_5e8.x;
                        VVar9.z = VStack_5e8.z;
                        pVVar30 = GetPositionNear(&VStack_540,VVar9,___real_42480000,
                                                  ___real_42c80000);
                        pDVar31 = (DispatchClass *)uStack_774;
                      }
                      (pDVar31->DispatchSpot).x = pVVar30->x;
                      (pDVar31->DispatchSpot).y = pVVar30->y;
                      (pDVar31->DispatchSpot).z = pVVar30->z;
                      Goto((_Stack_788._Ptr)->DispatchObject,&(_Stack_788._Ptr)->DispatchSpot,0);
                      (_Stack_788._Ptr)->DispatchState = 1;
                      (_Stack_788._Ptr)->IdleTime = 0;
                      if (_Stack_784._3_1_ != '\0') {
                        memset(TempGetODFName,0,0x40);
                        GetODFName((int)__return_storage_ptr__,(char *)unaff_EDI);
                        std::
                        _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                        ::
                        _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                  (&_Stack_6ec,*(DispatchClass **)local_778,
                                   (_Container_base0 *)local_778);
                        FormatLogMessage(
                                        "Index: %d sent to Dynamic Patrol Near Handle: %08x, ODF: \'%s\', Position: %f %f %f"
                                        );
                      }
                    }
                    else {
                      iVar34 = GetRandomInt((int)__return_storage_ptr__,(int)unaff_EDI);
                      pDStack_760 = (DispatchClass *)0x0;
                      pcVar28 = *(char **)(*(int *)(local_74c[1].teamInfo[0].BaseSlotName[1] +
                                                   iVar26 + 0x1f) + iVar34 * 4);
                      if ((pcVar28 != (char *)0x0) &&
                         (GetPathPoints(pcVar28,(uint *)&pDStack_760,(float *)0x0),
                         pDStack_760 != (DispatchClass *)0x0)) {
                        Patrol((_Stack_788._Ptr)->DispatchObject,pcVar28,0);
                        (_Stack_788._Ptr)->DispatchState = 1;
                        (_Stack_788._Ptr)->IdleTime = 0;
                        if (_Stack_784._3_1_ != '\0') {
                          std::
                          _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                          ::
                          _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                    (&_Stack_6f0,*(DispatchClass **)pvVar36,
                                     (_Container_base0 *)pvVar36);
                          pcVar28 = "Index: %d sent to Patrol path: \'%s\', TurnCount: %d";
                          goto LAB_4fc34e4c;
                        }
                      }
                    }
                  }
                }
              }
              else if (iVar26 == 3) {
                iVar26 = iStack_768 * 0xc;
                if (*(int *)(local_74c[1].teamInfo[0].PlayerPilotODF + iVar26 + 0x23) -
                    *(int *)(local_74c[1].teamInfo[0].PlayerPilotODF + iVar26 + 0x1f) >> 2 < 1) {
                  pcStack_77c = (char *)GetRandomInt((int)__return_storage_ptr__,(int)unaff_EDI);
                  if (pcStack_77c == (char *)0x0) {
                    uStack_648 = 0;
                    uStack_644 = 0;
                    uStack_640 = 0;
                    uStack_6b4 = 0;
                    uStack_6b0 = 0;
                    fStack_6ac = 0.0;
                    uStack_774 = (double)CONCAT44(uStack_774._4_4_,BuildingHelper::m_BuildingHelper)
                    ;
                    pDStack_760 = (DispatchClass *)
                                  BuildingHelper::GetRandomBuilding
                                            (BuildingHelper::m_BuildingHelper,iStack_768,4,true,true
                                             ,true,0,(char *)0x0,(char *)0x0,0.0,(Vector)ZEXT812(0))
                    ;
                    VVar20.y = (float)uStack_6b0;
                    VVar20.x = (float)uStack_6b4;
                    VVar20.z = fStack_6ac;
                    iVar26 = BuildingHelper::GetRandomBuilding
                                       ((BuildingHelper *)(DispatchClass *)uStack_774,iStack_768,1,
                                        true,true,true,0,(char *)0x0,(char *)0x0,0.0,VVar20);
                    GetPosition(iVar26,&VStack_60c);
                    GetPosition((int)pDStack_760,&VStack_600);
                    VVar5.y = VStack_600.z;
                    VVar5.x = VStack_600.y;
                    VVar5.z = VStack_60c.x;
                    VVar14.y = VStack_60c.z;
                    VVar14.x = VStack_60c.y;
                    VVar14.z = ___real_42c80000;
                    GetPositionNearOrFar
                              ((Vector *)VStack_600.x,VVar5,VVar14,___real_43480000,
                               (float)__return_storage_ptr__,SUB41(unaff_EDI,0));
                    pfVar38 = afStack_5f4;
LAB_4fc359ac:
                    ((_Stack_788._Ptr)->DispatchSpot).x = *pfVar38;
                    ((_Stack_788._Ptr)->DispatchSpot).y = pfVar38[1];
                    ((_Stack_788._Ptr)->DispatchSpot).z = pfVar38[2];
                  }
                  else if (pcStack_77c == (char *)0x1) {
                    fVar43 = (local_74c->mapInfo).MapDepth;
                    pDStack_760 = (DispatchClass *)(local_74c->mapInfo).MapWidth;
                    uStack_774 = (double)CONCAT44(uStack_774._4_4_,fVar43);
                    fStack_6c0 = GetRandomFloat((float)((uint)fVar43 ^
                                                       __xmm_80000000800000008000000080000000),
                                                fVar43);
                    fStack_6bc = 0.0;
                    fStack_6b8 = GetRandomFloat((float)((uint)pDStack_760 ^
                                                       __xmm_80000000800000008000000080000000),
                                                (float)pDStack_760);
                    _Var22._Ptr = _Stack_788._Ptr;
                    ((_Stack_788._Ptr)->DispatchSpot).x = fStack_6c0;
                    ((_Stack_788._Ptr)->DispatchSpot).y = fStack_6bc;
                    ((_Stack_788._Ptr)->DispatchSpot).z = fStack_6b8;
                    fVar43 = TerrainFindFloor(((_Stack_788._Ptr)->DispatchSpot).x,
                                              ((_Stack_788._Ptr)->DispatchSpot).z);
                    ((_Var22._Ptr)->DispatchSpot).y = fVar43;
                  }
                  else if (pcStack_77c == (char *)0x2) {
                    dStack_6d0 = (double)((ulonglong)dStack_6d0 & 0xffffffff);
                    uStack_6c8 = 0;
                    uStack_6c4 = 0;
                    _Stack_624 = (_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                  )VStack_73c.x;
                    fStack_620 = VStack_73c.y;
                    fStack_61c = VStack_73c.z;
                    iVar26 = BuildingHelper::GetRandomBuilding
                                       (BuildingHelper::m_BuildingHelper,iStack_768,4,true,true,true
                                        ,0,(char *)0x0,(char *)0x0,0.0,(Vector)ZEXT812(0));
                    GetPosition(iVar26,&VStack_630);
                    VVar4.y = fStack_61c;
                    VVar4.x = fStack_620;
                    VVar4.z = VStack_630.x;
                    VVar13.y = VStack_630.z;
                    VVar13.x = VStack_630.y;
                    VVar13.z = ___real_42c80000;
                    GetPositionNearOrFar
                              ((Vector *)_Stack_624,VVar4,VVar13,___real_43480000,
                               (float)__return_storage_ptr__,SUB41(unaff_EDI,0));
                    pfVar38 = afStack_618;
                    goto LAB_4fc359ac;
                  }
                  if (_Stack_784._3_1_ != '\0') {
                    FormatLogMessage(
                                    "Index: %d sent to Dynamic Minelaying, DispatchState: %d, Position: %f %f %f"
                                    );
                  }
                }
                else {
                  iVar34 = GetRandomInt((int)__return_storage_ptr__,(int)unaff_EDI);
                  pDStack_760 = (DispatchClass *)0x0;
                  pcStack_77c = *(char **)(*(int *)(local_74c[1].teamInfo[0].PlayerPilotODF +
                                                   iVar26 + 0x1f) + iVar34 * 4);
                  if ((pcStack_77c != (char *)0x0) &&
                     (GetPathPoints(pcStack_77c,(uint *)&pDStack_760,(float *)0x0),
                     pDStack_760 != (DispatchClass *)0x0)) {
                    uStack_774 = (double)CONCAT44(uStack_774._4_4_,_Stack_788._Ptr);
                    pVVar30 = GetVectorFromPath((Vector *)0x0,(char *)__return_storage_ptr__,
                                                (int)unaff_EDI);
                    pVVar30 = GetPositionNear(&VStack_54c,*pVVar30,___real_41c80000,___real_42480000
                                             );
                    *(float *)((int)(DispatchClass *)uStack_774 + 0xc) = pVVar30->x;
                    *(float *)((int)(DispatchClass *)uStack_774 + 0x10) = pVVar30->y;
                    *(float *)((int)(DispatchClass *)uStack_774 + 0x14) = pVVar30->z;
                    if (_Stack_784._3_1_ != '\0') {
                      std::
                      _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                      ::
                      _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                (&_Stack_6f4,*(DispatchClass **)local_778,
                                 (_Container_base0 *)local_778);
                      FormatLogMessage("Index: %d sent to Lay Mines at path: \'%s\'");
                    }
                  }
                }
                fStack_6a8 = ((_Stack_788._Ptr)->DispatchSpot).x;
                fStack_6a4 = ((_Stack_788._Ptr)->DispatchSpot).y;
                fStack_6a0 = ((_Stack_788._Ptr)->DispatchSpot).z;
                pcVar42 = (char *)__real_3dcccccd;
                if (__real_3dcccccd <=
                    fStack_6a4 * fStack_6a4 + fStack_6a8 * fStack_6a8 + fStack_6a0 * fStack_6a0) {
                  Goto((_Stack_788._Ptr)->DispatchObject,&(_Stack_788._Ptr)->DispatchSpot,0);
                  _Var22._Ptr = _Stack_788._Ptr;
                  fVar43 = ___real_43960000;
                  (_Stack_788._Ptr)->DispatchState = 1;
                  iVar26 = SecondsToTurns(fVar43);
                  (_Var22._Ptr)->IdleTime = iVar26 + BZ1Helper::m_TurnCounter;
                  if (_Stack_784._3_1_ != '\0') {
                    pcVar28 = "Index is: %d Minelayer No Valid Target, IdleTime: %d";
                    goto LAB_4fc35aab;
                  }
                }
              }
              else if (iVar26 == 4) {
                if (0 < *(int *)(iStack_764 + 0x134)) {
                  if (*(int *)(iStack_764 + 0x140) < *(int *)(iStack_764 + 0x134)) {
                    *(int *)(iStack_764 + 0x140) = *(int *)(iStack_764 + 0x140) + 1;
                    SetCommand((_Stack_788._Ptr)->DispatchObject,0x15,0,0,(char *)0x0,0);
                    _Var22._Ptr = _Stack_788._Ptr;
                    fVar43 = ___real_43960000;
                    (_Stack_788._Ptr)->DispatchState = 1;
                    iVar26 = SecondsToTurns(fVar43);
                    (_Var22._Ptr)->IdleTime = iVar26 + BZ1Helper::m_TurnCounter;
                    if (_Stack_784._3_1_ != '\0') {
                      pcVar28 = "Index: %d Hunt Task Starting, Hunt Command issued. IdleTime: %d";
                      goto LAB_4fc35aab;
                    }
                  }
                }
              }
              else if (iVar26 == 5) {
                if ((0 < *(int *)(iStack_764 + 0x138)) &&
                   (*(int *)(iStack_764 + 0x144) < *(int *)(iStack_764 + 0x138))) {
                  iVar26 = UtilityShipHelper::GetEscortTarget
                                     (UtilityShipHelper::m_UtilityShipHelper,iStack_768,3);
                  *(int *)&(_Var22._Ptr)->DispatchTarget = iVar26;
                  if (*(int *)&(_Stack_788._Ptr)->DispatchTarget != 0) {
                    Defend2((_Stack_788._Ptr)->DispatchObject,
                            *(int *)&(_Stack_788._Ptr)->DispatchTarget,0);
                    (_Stack_788._Ptr)->DispatchState = 1;
                    (_Stack_788._Ptr)->IdleTime = 0;
                    if (_Stack_784._3_1_ != '\0') {
                      memset(TempGetODFName,0,0x40);
                      GetODFName((int)__return_storage_ptr__,(char *)unaff_EDI);
                      FormatLogMessage("Index: %d Escort Task Starting, Target: \'%s\'");
                    }
                    *(int *)(iStack_764 + 0x144) = *(int *)(iStack_764 + 0x144) + 1;
                  }
                }
              }
            }
          }
        }
        else if (iVar26 == 1) {
          if ((_Stack_788._Ptr)->DispatchType == 1) {
            if ((_Stack_788._Ptr)->IdleTime == 0) {
              bVar25 = IsDeployed((_Stack_788._Ptr)->DispatchObject);
              _Var22._Ptr = _Stack_788._Ptr;
              if (bVar25) {
                if ((_Stack_788._Ptr)->IdleTime != 0) goto LAB_4fc34e97;
              }
              else {
                iVar26 = SecondsToTurns(___real_43960000);
                (_Var22._Ptr)->IdleTime = iVar26 + BZ1Helper::m_TurnCounter;
              }
            }
            else {
LAB_4fc34e97:
              bVar25 = IsDeployed((_Stack_788._Ptr)->DispatchObject);
              if (bVar25) {
                (_Stack_788._Ptr)->DispatchState = 0;
              }
            }
          }
          if (((_Stack_788._Ptr)->SkipAIPCheck != false) || (*(char *)(iStack_764 + 0x1ae) != '\0'))
          {
            if ((0 < (_Stack_788._Ptr)->IdleTime) &&
               ((_Stack_788._Ptr)->IdleTime <= BZ1Helper::m_TurnCounter)) {
              ClearDispatch(pDStack_744,(int)pcStack_77c);
            }
            iVar26 = (_Stack_788._Ptr)->DispatchType;
            if (iVar26 == 1) {
              bVar25 = IsDeployed((_Stack_788._Ptr)->DispatchObject);
              if (bVar25) goto LAB_4fc369be;
              pDStack_760 = (DispatchClass *)0x0;
              local_748._0_3_ = (uint3)(byte)local_748;
              if (0 < iStack_730) {
                iStack_750 = 0;
                do {
                  piVar37 = (int *)(*(int *)&local_74c->m_ObjectHelper->HandleList + iStack_750);
                  local_728 = *piVar37;
                  bVar25 = IsTeamAllied(iStack_768,piVar37[7]);
                  if ((!bVar25) &&
                     ((piVar37[4] == 2 ||
                      ((piVar37[2] == 0x4a7aef92 && (bVar25 = IsDeployed(local_728), bVar25)))))) {
                    dStack_75c = (double)((float)piVar37[9] + (float)___real_4049000000000000);
                    uStack_774._0_4_ =
                         (DispatchClass *)((float)piVar37[9] + (float)___real_4049000000000000);
                    GetDistance2DSquared<Vector,Vector>(__return_storage_ptr__,unaff_EDI);
                    fVar43 = (float)((float10)dStack_75c * (float10)dStack_75c);
                    uStack_774 = (double)CONCAT44(uStack_774._4_4_,fVar43);
                    if ((float)pcVar42 < fVar43) {
                      local_748._0_2_ = CONCAT11(1,(byte)local_748);
                      fVar43 = GetRandomFloat(1.0);
                      if (fVar43 < __real_3f000000) {
                        local_748._0_3_ = CONCAT12(1,(undefined2)local_748);
                      }
                      if (_Stack_784._3_1_ != '\0') {
                        fVar43 = (*misnImport.GetDistanceObject)
                                           (&(_Stack_788._Ptr)->DispatchObject,&local_728);
                        uStack_774 = (double)CONCAT44(uStack_774._4_4_,fVar43);
                        FormatLogMessage(
                                        "Index: %d Turret Encountered an Enemy on Team: %d Distance Is: %f, Return is: %d"
                                        );
                      }
                      break;
                    }
                  }
                  pDStack_760 = (DispatchClass *)((int)&pDStack_760->DispatchObject + 1);
                  iStack_750 = iStack_750 + 0x5c;
                } while ((int)pDStack_760 < iStack_730);
              }
              if ((byte)local_748 == '\0') {
LAB_4fc35374:
                if (local_748._1_1_ == '\0') goto LAB_4fc369be;
              }
              else {
                fVar43 = (_Stack_788._Ptr)->RandomDist + (float)___real_4014000000000000;
                dStack_75c = (double)fVar43;
                uStack_774._0_4_ = (DispatchClass *)fVar43;
                GetDistance2DSquared<Vector,Vector>(__return_storage_ptr__,unaff_EDI);
                fVar43 = (float)((float10)dStack_75c * (float10)dStack_75c);
                uStack_774 = (double)CONCAT44(uStack_774._4_4_,fVar43);
                if (fVar43 < (float)pcVar42) goto LAB_4fc35374;
              }
              if (local_748._2_1_ == '\0') {
                if (local_748._1_1_ == '\0') {
                  Defend((_Stack_788._Ptr)->DispatchObject,0);
                }
                else {
                  uStack_774 = (double)CONCAT44(uStack_774._4_4_,_Stack_788._Ptr);
                  VVar8.y = VStack_73c.y;
                  VVar8.x = VStack_73c.x;
                  VVar8.z = VStack_73c.z;
                  pVVar30 = GetPositionNear(aVStack_564,VVar8,__real_41200000,___real_41f00000);
                  *(float *)((int)(DispatchClass *)uStack_774 + 0xc) = pVVar30->x;
                  *(float *)((int)(DispatchClass *)uStack_774 + 0x10) = pVVar30->y;
                  *(float *)((int)(DispatchClass *)uStack_774 + 0x14) = pVVar30->z;
                  Goto((_Stack_788._Ptr)->DispatchObject,&(_Stack_788._Ptr)->DispatchSpot,0);
                  if (_Stack_784._3_1_ != '\0') {
                    FormatLogMessage("Index is: %d Spot is: %f %f %f");
                  }
                }
                _Var22._Ptr = _Stack_788._Ptr;
                fVar43 = ___real_43960000;
                (_Stack_788._Ptr)->DispatchState = 0;
                iVar26 = SecondsToTurns(fVar43);
                (_Var22._Ptr)->IdleTime = iVar26 + BZ1Helper::m_TurnCounter;
                if (_Stack_784._3_1_ != '\0') {
                  pcVar28 = "Index is: %d Turret Encountered an Enemy, IdleTime: %d";
LAB_4fc35aab:
                  FormatLogMessage(pcVar28);
                }
              }
              else {
                ClearDispatch(pDStack_744,(int)pcStack_77c);
              }
            }
            else if (iVar26 == 2) {
              bVar25 = IsIdle((_Stack_788._Ptr)->DispatchObject);
              _Var22._Ptr = _Stack_788._Ptr;
              if (bVar25) {
                pcVar28 = local_74c[1].teamInfo[0].BaseSlotName[1] + iStack_768 * 0xc + 0x1f;
                if ((*(int *)(pcVar28 + 4) - *(int *)pcVar28 & 0xfffffffcU) == 0) {
                  (_Stack_788._Ptr)->IdleTime = 0;
                  if (_Stack_784._3_1_ != '\0') {
                    FormatLogMessage("Index: %d sent to Dynamic Patrol Reset, Cmd == CMD_NONE");
                  }
                }
                else {
                  iVar26 = SecondsToTurns(___real_41700000);
                  (_Var22._Ptr)->IdleTime = iVar26 + BZ1Helper::m_TurnCounter;
                  if (_Stack_784._3_1_ != '\0') {
                    FormatLogMessage(
                                    "Patrol Unit %d interrupted, resetting idle timer. TurnCount: %d, IdleTime: %d"
                                    );
                  }
                }
                (_Stack_788._Ptr)->DispatchState = 0;
              }
            }
            else if (iVar26 == 3) {
              GetDistance2DSquared<Vector,Vector>(__return_storage_ptr__,unaff_EDI);
              uStack_774 = (double)CONCAT44(uStack_774._4_4_,pcVar42);
              if ((float)pcVar42 < (float)___real_4059000000000000) {
                SetCommand((_Stack_788._Ptr)->DispatchObject,0x1b,0,0,(char *)0x0,0);
                _Var22._Ptr = _Stack_788._Ptr;
                fVar43 = ___real_43960000;
                (_Stack_788._Ptr)->DispatchState = 0;
                iVar26 = SecondsToTurns(fVar43);
                (_Var22._Ptr)->IdleTime = iVar26 + BZ1Helper::m_TurnCounter;
                if (_Stack_784._3_1_ != '\0') {
                  FormatLogMessage(
                                  "Index: %d Minelayer reached Spot: %f %f %f, laying mines..., IdleTime: %d"
                                  );
                }
              }
            }
            else {
              if (iVar26 == 4) {
                bVar25 = IsIdle((_Stack_788._Ptr)->DispatchObject);
                if (!bVar25) goto LAB_4fc369be;
                SetCommand((_Stack_788._Ptr)->DispatchObject,0x15,0,0,(char *)0x0,0);
                _Var22._Ptr = _Stack_788._Ptr;
                iVar26 = SecondsToTurns(___real_43960000);
                (_Var22._Ptr)->IdleTime = iVar26 + BZ1Helper::m_TurnCounter;
                if (_Stack_784._3_1_ == '\0') goto LAB_4fc369be;
                pcVar28 = "Index: %d Hunt Task Continuing, Re-Issueing Hunt Command. IdleTime: %d";
                goto LAB_4fc35aab;
              }
              if (iVar26 == 5) {
                if ((byte)local_748 == '\0') {
                  fVar43 = GetRandomFloat(1.0);
                  _Var22._Ptr = _Stack_788._Ptr;
                  if (__real_3f000000 <= fVar43) {
                    (_Stack_788._Ptr)->DispatchType = 0;
                    ClearDispatch(pDStack_744,(int)pcStack_77c);
                    _Var22._Ptr = _Stack_788._Ptr;
                    fVar43 = ___real_43e10000;
                    iVar34 = 0;
                    *(int *)(iStack_764 + 0x144) = *(int *)(iStack_764 + 0x144) + -1;
                    iVar26 = GetNearestEnemy((_Stack_788._Ptr)->DispatchObject,true,false,fVar43);
                    Attack((_Var22._Ptr)->DispatchObject,iVar26,iVar34);
                    if (_Stack_784._3_1_ != '\0') {
                      FormatLogMessage("Index: %d Escort Target lost, Going Bezerk!");
                    }
                  }
                  else {
                    iVar26 = UtilityShipHelper::GetEscortTarget
                                       (UtilityShipHelper::m_UtilityShipHelper,iStack_768,3);
                    *(int *)&(_Var22._Ptr)->DispatchTarget = iVar26;
                    Defend2((_Stack_788._Ptr)->DispatchObject,
                            *(int *)&(_Stack_788._Ptr)->DispatchTarget,0);
                    if (_Stack_784._3_1_ != '\0') {
                      memset(TempGetODFName,0,0x40);
                      GetODFName((int)__return_storage_ptr__,(char *)unaff_EDI);
                      pcVar28 = "Index: %d Escort Target lost, picking new Target: \'%s\'";
                      goto LAB_4fc35aab;
                    }
                  }
                }
              }
            }
          }
        }
        else if (iVar26 == 2) {
          if ((_Stack_788._Ptr)->IdleTime <= BZ1Helper::m_TurnCounter) {
            SetIndependence((_Stack_788._Ptr)->DispatchObject,1);
            _Var22._Ptr = _Stack_788._Ptr;
            lVar29 = GetCurHealth((_Stack_788._Ptr)->DispatchObject);
            (_Var22._Ptr)->FleeHealthValue = lVar29;
            ClearDispatch(pDStack_744,(int)pcStack_77c);
            _Var22._Ptr = _Stack_788._Ptr;
            iVar26 = SecondsToTurns(___real_41700000);
            (_Var22._Ptr)->IdleTime = iVar26 + BZ1Helper::m_TurnCounter;
            bVar25 = IsAround((_Stack_788._Ptr)->FleeTarget);
            if (bVar25) {
              Attack((_Stack_788._Ptr)->DispatchObject,(_Stack_788._Ptr)->FleeTarget,0);
            }
            if (_Stack_784._3_1_ != '\0') {
              memset(TempGetODFName,0,0x40);
              GetODFName((int)__return_storage_ptr__,(char *)unaff_EDI);
              pcVar28 = "Index: %d Flee State Ending. Last Target: \'%s\', IdleTime: %d";
LAB_4fc34e4c:
              FormatLogMessage(pcVar28);
            }
          }
        }
        else if (iVar26 - 3U < 2) {
          if ((((iVar26 == 4) &&
               (fVar43 = GetHealth((_Stack_788._Ptr)->DispatchObject),
               (_Var22._Ptr)->GetRepairRatio < fVar43)) ||
              ((_Var22._Ptr = _Stack_788._Ptr, (_Stack_788._Ptr)->DispatchState == 3 &&
               (lVar29 = GetCurAmmo((_Stack_788._Ptr)->DispatchObject),
               (_Var22._Ptr)->MinFireAmmo < lVar29)))) ||
             ((_Stack_788._Ptr)->IdleTime <= BZ1Helper::m_TurnCounter)) {
LAB_4fc34cce:
            if (_Stack_784._3_1_ != '\0') {
              memset(TempGetODFName,0,0x40);
              GetODFName((int)__return_storage_ptr__,(char *)unaff_EDI);
              FormatLogMessage("Index: %d Unit: \'%s\' Rearmed/Repaired, resuming duties");
            }
            SetIndependence((_Stack_788._Ptr)->DispatchObject,1);
            ClearDispatch(pDStack_744,(int)pcStack_77c);
            _Var22._Ptr = _Stack_788._Ptr;
            iVar26 = SecondsToTurns(___real_41700000);
            (_Var22._Ptr)->IdleTime = iVar26 + BZ1Helper::m_TurnCounter;
            if (_Stack_784._3_1_ != '\0') {
              pcVar28 = "Index is: %d Repair/Repaid finished, IdleTime: %d";
              goto LAB_4fc35aab;
            }
          }
          else if (((_Stack_788._Ptr)->DispatchType != 1) && ((_Stack_788._Ptr)->DispatchType != 6))
          {
            if ((byte)local_748 == '\0') goto LAB_4fc34cce;
          }
        }
LAB_4fc369be:
        _Var22._Ptr = _Stack_788._Ptr;
        (_Stack_788._Ptr)->ServiceTimer = (_Stack_788._Ptr)->ServiceTimer + -1;
        uStack_780 = _Stack_788._Ptr;
        if ((_Stack_788._Ptr)->ServiceTimer < 0) {
          iVar26 = SecondsToTurns(__real_41200000);
          (_Var22._Ptr)->ServiceTimer = iVar26;
        }
        _Var22._Ptr = _Stack_788._Ptr;
        uStack_780 = _Stack_788._Ptr;
        if ((((*(char *)(iStack_764 + 0x1ad) == '\0') || (0 < (_Stack_788._Ptr)->ServiceTimer)) ||
            ((_Stack_788._Ptr)->DispatchState == 4)) || ((_Stack_788._Ptr)->DispatchState == 3)) {
          pvVar36 = local_778;
        }
        else {
          if ((_Stack_788._Ptr)->CanGetRepair == false) {
LAB_4fc36c87:
            iVar26 = iStack_764;
          }
          else {
            fVar43 = GetHealth((_Stack_788._Ptr)->DispatchObject);
            if ((_Var22._Ptr)->GetRepairRatio <= fVar43) {
LAB_4fc36c7f:
              uStack_780 = _Stack_788._Ptr;
              goto LAB_4fc36c87;
            }
            if ((((_Stack_788._Ptr)->DispatchType != 1) && ((_Stack_788._Ptr)->DispatchType != 6))
               || (bVar25 = IsDeployed((_Stack_788._Ptr)->DispatchObject), !bVar25)) {
              _Var22._Ptr = _Stack_788._Ptr;
              fVar43 = GetRandomFloat(1.0);
              if (fVar43 < (_Var22._Ptr)->ServiceChance) {
                VVar2.y = VStack_73c.y;
                VVar2.x = VStack_73c.x;
                VVar2.z = VStack_73c.z;
                iVar26 = BuildingHelper::GetNearestServiceObject
                                   (BuildingHelper::m_BuildingHelper,1,VVar2,0.0,-1,0,true,true,true
                                    ,0,0,(char *)0x0,(char *)0x0);
                dStack_75c = (double)CONCAT44(dStack_75c._4_4_,iVar26);
                if (iVar26 != 0) {
                  if (_Stack_784._3_1_ != '\0') {
                    memset(TempGetODFName,0,0x40);
                    GetODFName((int)__return_storage_ptr__,(char *)unaff_EDI);
                    FormatLogMessage("Index: %d Unit: \'%s\' going to get Repair");
                  }
                  *(DispatchClass **)&(_Stack_788._Ptr)->DispatchTarget = dStack_75c._0_4_;
                  Goto((_Stack_788._Ptr)->DispatchObject,*(int *)&(_Stack_788._Ptr)->DispatchTarget,
                       0);
                  SetIndependence((_Stack_788._Ptr)->DispatchObject,0);
                  _Var22._Ptr = _Stack_788._Ptr;
                  fVar43 = ___real_43960000;
                  (_Stack_788._Ptr)->DispatchState = 4;
                  iVar26 = SecondsToTurns(fVar43);
                  (_Var22._Ptr)->IdleTime = iVar26 + BZ1Helper::m_TurnCounter;
                  if (_Stack_784._3_1_ != '\0') {
                    FormatLogMessage("Index is: %d Unit going to Repair Service, IdleTime: %d");
                  }
                }
              }
              goto LAB_4fc36c7f;
            }
            if (*(int *)(iStack_764 + 0xa4) == 0) goto LAB_4fc36c7f;
            memset(acStack_94,0,0x40);
            bVar25 = GetBuildItem(0,(char *)0x1,(int *)0x0,0,(char *)0x0,
                                  (char *)__return_storage_ptr__,(char *)unaff_EDI);
            if (!bVar25) goto LAB_4fc36c7f;
            iVar34 = (*misnImport.GetScrap)(iStack_768);
            iVar26 = iStack_764;
            if (iVar34 < 0) goto LAB_4fc36c7f;
            VVar17.y = VStack_73c.y;
            VVar17.x = VStack_73c.x;
            VVar17.z = VStack_73c.z;
            BZ1Helper::BuildAt(local_74c,*(int *)(iStack_764 + 0xa4),acStack_94,VVar17,1);
            fVar43 = ___real_42700000;
            (_Stack_788._Ptr)->DispatchState = 4;
            iVar34 = SecondsToTurns(fVar43);
            if ((_Stack_788._Ptr)->IdleTime < iVar34 + BZ1Helper::m_TurnCounter) {
              (_Stack_788._Ptr)->IdleTime = iVar34 + BZ1Helper::m_TurnCounter;
            }
            uStack_780 = _Stack_788._Ptr;
            if (_Stack_784._3_1_ != '\0') {
              FormatLogMessage(
                              "Index is: %d Deployable Waiting for Repair Powerup to land, IdleTime: %d"
                              );
              uStack_780 = _Stack_788._Ptr;
            }
          }
          _Stack_788._Ptr = uStack_780;
          if (uStack_780->CanGetReload == false) {
LAB_4fc36efa:
            pvVar36 = local_778;
          }
          else {
            fVar43 = GetAmmo(uStack_780->DispatchObject);
            _Var22._Ptr = _Stack_788._Ptr;
            if (1.0 <= fVar43) goto LAB_4fc36efa;
            lVar29 = GetMinFireAmmo((int)__return_storage_ptr__);
            _Var23._Ptr = _Stack_788._Ptr;
            (_Var22._Ptr)->MinFireAmmo = lVar29;
            lVar29 = GetCurAmmo((_Stack_788._Ptr)->DispatchObject);
            if ((_Var23._Ptr)->MinFireAmmo <= lVar29) goto LAB_4fc36efa;
            if ((((_Stack_788._Ptr)->DispatchType != 1) && ((_Stack_788._Ptr)->DispatchType != 6))
               || (bVar25 = IsDeployed((_Stack_788._Ptr)->DispatchObject), !bVar25)) {
              VVar3.y = VStack_73c.y;
              VVar3.x = VStack_73c.x;
              VVar3.z = VStack_73c.z;
              iVar26 = BuildingHelper::GetNearestServiceObject
                                 (BuildingHelper::m_BuildingHelper,2,VVar3,0.0,-1,0,true,true,true,0
                                  ,0,(char *)0x0,(char *)0x0);
              dStack_75c = (double)CONCAT44(dStack_75c._4_4_,iVar26);
              if (iVar26 != 0) {
                if (_Stack_784._3_1_ == '\0') {
                  pvVar36 = local_778;
                }
                else {
                  memset(TempGetODFName,0,0x40);
                  GetODFName((int)__return_storage_ptr__,(char *)unaff_EDI);
                  pvVar36 = local_778;
                  FormatLogMessage("Index: %d Unit: \'%s\' going to get Reload");
                }
                *(DispatchClass **)&(_Stack_788._Ptr)->DispatchTarget = dStack_75c._0_4_;
                Goto((_Stack_788._Ptr)->DispatchObject,*(int *)&(_Stack_788._Ptr)->DispatchTarget,0)
                ;
                SetIndependence((_Stack_788._Ptr)->DispatchObject,0);
                _Var22._Ptr = _Stack_788._Ptr;
                fVar43 = ___real_41f00000;
                (_Stack_788._Ptr)->DispatchState = 3;
                iVar26 = SecondsToTurns(fVar43);
                (_Var22._Ptr)->IdleTime = iVar26 + BZ1Helper::m_TurnCounter;
                if (_Stack_784._3_1_ != '\0') {
                  pcVar28 = "Index is: %d Unit going to Reload Service, IdleTime: %d";
LAB_4fc36dce:
                  FormatLogMessage(pcVar28);
                  goto LAB_4fc36efe;
                }
              }
              goto LAB_4fc36efa;
            }
            if (*(int *)(iVar26 + 0xa4) == 0) goto LAB_4fc36efa;
            memset(acStack_54,0,0x40);
            bVar25 = GetBuildItem(0,(char *)0x2,(int *)0x0,0,(char *)0x0,
                                  (char *)__return_storage_ptr__,(char *)unaff_EDI);
            if ((!bVar25) || (iVar26 = (*misnImport.GetScrap)(iStack_768), iVar26 < 0))
            goto LAB_4fc36efa;
            VVar18.y = VStack_73c.y;
            VVar18.x = VStack_73c.x;
            VVar18.z = VStack_73c.z;
            BZ1Helper::BuildAt(local_74c,*(int *)(iStack_764 + 0xa4),acStack_54,VVar18,1);
            fVar43 = ___real_42700000;
            (_Stack_788._Ptr)->DispatchState = 3;
            iVar26 = SecondsToTurns(fVar43);
            if ((_Stack_788._Ptr)->IdleTime < iVar26 + BZ1Helper::m_TurnCounter) {
              (_Stack_788._Ptr)->IdleTime = iVar26 + BZ1Helper::m_TurnCounter;
            }
            pvVar36 = local_778;
            if (_Stack_784._3_1_ != '\0') {
              pcVar28 = "Index is: %d Deployable Waiting for Reload Powerup to land, IdleTime: %d";
              goto LAB_4fc36dce;
            }
          }
LAB_4fc36efe:
        }
        _Var22._Ptr = _Stack_788._Ptr;
        if ((_Stack_788._Ptr)->IsCloaker != false) {
          if ((_Stack_788._Ptr)->IsCloaked == false) {
            if ((_Stack_788._Ptr)->CloakNextTick == false) {
              if (((((_Stack_788._Ptr)->SkipAIPCheck != false) ||
                   (*(char *)(iStack_764 + 0x1ae) != '\0')) &&
                  (((_Stack_788._Ptr)->CloakIdleTime <= BZ1Helper::m_TurnCounter ||
                   (AVar33 = GetCurrentCommand((_Stack_788._Ptr)->DispatchObject),
                   AVar33 != (_Var22._Ptr)->Command)))) &&
                 (((iVar26 = GetPlayerHandle(iStack_768), iVar26 == 0 && (local_748._3_1_ == '\x01')
                   ) && ((_Stack_788._Ptr)->CloakPriority == 0)))) {
                fVar43 = GetRandomFloat(1.0);
                uStack_774 = (double)CONCAT44(uStack_774._4_4_,fVar43);
                iVar26 = (*misnImport.GetNearestEnemy)((_Stack_788._Ptr)->DispatchObject);
                dStack_75c = (double)CONCAT44(dStack_75c._4_4_,iVar26);
                bVar25 = IsDeployed((_Stack_788._Ptr)->DispatchObject);
                if ((!bVar25) || ((_Stack_788._Ptr)->IsMorpher != false)) {
                  if (dStack_75c._0_4_ != (DispatchClass *)0x0) {
                    GetPosition((int)dStack_75c._0_4_,&VStack_570);
                    dStack_724 = (double)(_Stack_788._Ptr)->EngageRange;
                    dStack_75c._0_4_ = (DispatchClass *)(_Stack_788._Ptr)->EngageRange;
                    GetDistance3DSquared(__return_storage_ptr__,unaff_EDI);
                    fVar43 = (float)((float10)dStack_724 * (float10)dStack_724);
                    dStack_75c = (double)CONCAT44(dStack_75c._4_4_,fVar43);
                    if ((float)pcVar42 <= fVar43) goto LAB_4fc37493;
                  }
                  dStack_75c = (double)(float)(DispatchClass *)uStack_774;
                  if (_Stack_784._3_1_ != '\0') {
                    FormatLogMessage(
                                    "Index: %d AI Attempting to Cloak unit, Chance: %f, CloakCommand: %d Chance: %f"
                                    );
                  }
                  _Var22._Ptr = _Stack_788._Ptr;
                  AVar33 = GetCurrentCommand((_Stack_788._Ptr)->DispatchObject);
                  if (dStack_75c < (double)(_Var22._Ptr)->CloakChance[AVar33]) {
                    if (_Stack_784._3_1_ != '\0') {
                      FormatLogMessage("Index: %d AI Cloak Successful");
                    }
                    Cloak(pDStack_744,(_Stack_788._Ptr)->DispatchObject,
                          (_Stack_788._Ptr)->CloakPriority);
                  }
                  _Var22._Ptr = _Stack_788._Ptr;
                  iVar26 = SecondsToTurns(___real_41700000);
                  (_Var22._Ptr)->CloakIdleTime = iVar26 + BZ1Helper::m_TurnCounter;
                }
              }
            }
            else {
              bVar25 = IsDeployed((_Stack_788._Ptr)->DispatchObject);
              if (!bVar25) {
                SetCommand((_Stack_788._Ptr)->DispatchObject,0x2f,0,0,(char *)0x0,0);
                _Var22._Ptr = _Stack_788._Ptr;
                iVar26 = SecondsToTurns((_Stack_788._Ptr)->TimeDeploy);
                (_Var22._Ptr)->DeployTimer = iVar26 + 1 + BZ1Helper::m_TurnCounter;
                (_Stack_788._Ptr)->CloakLocked = true;
                if (_Stack_784._3_1_ != '\0') {
                  FormatLogMessage(
                                  "Index: %d Cloaking Activating, Time: %d, DeployTimer: %d, DeployTime: %f"
                                  );
                }
              }
              (_Stack_788._Ptr)->IsCloaked = true;
              (_Stack_788._Ptr)->CloakNextTick = false;
            }
          }
          else {
            bVar25 = IsDeployed((_Stack_788._Ptr)->DispatchObject);
            if (bVar25) {
              if ((_Stack_788._Ptr)->DecloakNextTick == false) {
                if (((local_748._3_1_ == '\x01') && ((_Stack_788._Ptr)->CloakPriority == 0)) &&
                   ((*misnImport.GetNearestEnemy)((_Stack_788._Ptr)->DispatchObject),
                   (_Stack_788._Ptr)->CloakLocked != false)) {
                  uStack_774 = (double)(_Stack_788._Ptr)->EngageRange;
                  dStack_75c._0_4_ = (DispatchClass *)(_Stack_788._Ptr)->EngageRange;
                  GetDistance3DSquared((int)__return_storage_ptr__,(int)unaff_EDI);
                  fVar43 = (float)((float10)uStack_774 * (float10)uStack_774);
                  dStack_75c = (double)CONCAT44(dStack_75c._4_4_,fVar43);
                  if ((float)pcVar42 < fVar43) {
                    if (_Stack_784._3_1_ != '\0') {
                      FormatLogMessage("Index: %d Unit is Cloaked, Enemy detected, Unlocking Cloak")
                      ;
                    }
                    pDVar31 = std::
                              _Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                              ::operator->((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                            *)&_Stack_788);
                    SetCommand(pDVar31->DispatchObject,0x31,0,0,(char *)0x0,0);
                    pDVar31 = std::
                              _Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                              ::operator->((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                            *)&_Stack_788);
                    pDVar31->CloakLocked = false;
                  }
                }
                pDVar31 = std::
                          _Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                          ::operator->((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                        *)&_Stack_788);
                AVar33 = GetCurrentCommand(pDVar31->DispatchObject);
                if (AVar33 == CMD_ATTACK) {
                  GetPosition(__return_storage_ptr__,(int)unaff_EDI);
                  GetDistance3DSquared(__return_storage_ptr__,unaff_EDI);
                  dStack_75c = (double)(float)pcVar42;
                  pDVar31 = std::
                            _Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                            ::operator->((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                          *)&_Stack_788);
                  fVar43 = Squared<float>(pDVar31->EngageRange);
                  if ((float)dStack_75c < fVar43) {
                    if (_Stack_784._3_1_ != '\0') {
                      _Var27 = std::
                               vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
                               ::begin(pvVar36);
                      std::
                      _Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                      ::operator-((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                   *)((int)register0x00000010 + -0x78c),
                                  (_Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                   *)_Var27);
                      FormatLogMessage("Index: %d Unit is Cloaked, Target In Range, Decloaking");
                    }
                    std::
                    _Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                    ::operator->((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                  *)&_Stack_788);
                    pDVar31 = std::
                              _Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                              ::operator->((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                            *)&_Stack_788);
                    iVar26 = pDVar31->DispatchObject;
                    bVar25 = IsAround(iVar26);
                    if (bVar25) {
                      Decloak(pDStack_744,iVar26,(int)__return_storage_ptr__);
                    }
                    pDVar31 = std::
                              _Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                              ::operator->((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                            *)&_Stack_788);
                    pDVar31->CloakLocked = false;
                  }
                }
              }
              else {
                SetCommand((_Stack_788._Ptr)->DispatchObject,0x30,0,0,(char *)0x0,0);
                (_Stack_788._Ptr)->DecloakNextTick = false;
              }
            }
            else {
              pDVar31 = std::
                        _Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                        ::operator->((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                      *)&_Stack_788);
              if (pDVar31->DeployTimer < BZ1Helper::m_TurnCounter) {
                pDVar31 = std::
                          _Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                          ::operator->((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                        *)&_Stack_788);
                if (((pDVar31->SkipAIPCheck != false) || (*(char *)(iStack_764 + 0x1ae) != '\0')) &&
                   (iVar26 = GetPlayerHandle(iStack_768), iVar26 == 0)) {
                  pDVar31 = std::
                            _Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                            ::operator->((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                          *)&_Stack_788);
                  pDVar32 = std::
                            _Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                            ::operator->((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                          *)&_Stack_788);
                  AVar33 = GetCurrentCommand(pDVar31->DispatchObject);
                  if (AVar33 == pDVar32->Command) {
                    if (_Stack_784._3_1_ != '\0') {
                      _Var27 = std::
                               vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
                               ::begin(local_778);
                      std::
                      _Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                      ::operator-((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                   *)((int)register0x00000010 + -0x78c),
                                  (_Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                   *)_Var27);
                      FormatLogMessage(
                                      "Index: %d Command Identicle, setting CloakIdle time for 15 seconds."
                                      );
                    }
                    iVar26 = SecondsToTurns(___real_41700000);
                    iVar26 = BZ1Helper::m_TurnCounter + iVar26;
                    pDVar31 = std::
                              _Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                              ::operator->((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                            *)&_Stack_788);
                    pDVar31->CloakIdleTime = iVar26;
                  }
                  else {
                    if (_Stack_784._3_1_ != '\0') {
                      _Var27 = std::
                               vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
                               ::begin(local_778);
                      std::
                      _Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                      ::operator-((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                   *)((int)register0x00000010 + -0x78c),
                                  (_Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                   *)_Var27);
                      FormatLogMessage(
                                      "Index: %d Command Different, Setting CloakIdle time for NOW."
                                      );
                    }
                    pDVar31 = std::
                              _Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                              ::operator->((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                            *)&_Stack_788);
                    pDVar31->CloakIdleTime = BZ1Helper::m_TurnCounter;
                  }
                }
                pDVar31 = std::
                          _Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                          ::operator->((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                        *)&_Stack_788);
                pDVar31->IsCloaked = false;
                if (_Stack_784._3_1_ != '\0') {
                  std::
                  _Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                  ::operator->((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                *)&_Stack_788);
                  std::
                  _Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                  ::operator->((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                *)&_Stack_788);
                  _Var27 = std::
                           vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
                           ::begin(local_778);
                  std::
                  _Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                  ::operator-((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                               *)((int)register0x00000010 + -0x78c),
                              (_Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                               *)_Var27);
                  FormatLogMessage(
                                  "Index: %d Unit was not cloaked! DeployTimer: %d, Time: %d, DeployTime: %f, Time: %d"
                                  );
                }
              }
            }
          }
        }
LAB_4fc37493:
        pDVar31 = std::
                  _Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                  ::operator->((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                *)&_Stack_788);
        pDVar32 = std::
                  _Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                  ::operator->((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                *)&_Stack_788);
        AVar33 = GetCurrentCommand(pDVar31->DispatchObject);
        if (AVar33 != pDVar32->Command) {
          pDVar31 = std::
                    _Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                    ::operator->((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                  *)&_Stack_788);
          AVar33 = GetCurrentCommand(pDVar31->DispatchObject);
          pDVar31 = std::
                    _Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                    ::operator->((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                  *)&_Stack_788);
          pDVar31->Command = AVar33;
        }
        pvVar36 = local_778;
      }
      _Stack_788._Ptr = _Stack_788._Ptr + 1;
      std::
      _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
      ::
      _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                (&local_740,*(DispatchClass **)&pvVar36->field_0x4,(_Container_base0 *)pvVar36);
    } while (_Stack_788._Ptr != local_740._Ptr);
  }
  return;
}


// ---------------------------------------------------------------------
// DispatchHelper::PreOrdnanceHit  @ 4fc37519  lines 1860-1939


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
            GetODFBool(0x4fc5d89c,(char *)&param_2,(char *)0x0,pbVar8,(bool)uVar9);
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
// DispatchHelper::ReadChanceValues  @ 4fc377d8  lines 1942-1948


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
      GetODFFloat(param_1,param_2,*ppcVar2,(float *)((int)(param_3 + -0x13f1981c) + (int)ppcVar2),
                  param_4);
      ppcVar2 = ppcVar2 + 1;
    } while ((int)ppcVar2 < 0x4fc66148);
  }
  return;
}


// ---------------------------------------------------------------------
// DispatchHelper::Cloak  @ 4fc37825  lines 1952-2027


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
// DispatchHelper::Decloak  @ 4fc3790a  lines 2029-2076


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
// DispatchHelper::ClearDispatch  @ 4fc3799b  lines 2174-2183


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

