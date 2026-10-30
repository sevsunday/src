// Reconstructed by Ghidra from Strategy02.dll + Strategy02.pdb
// Original source file: /e:/github/vsr_dll_source/missions/vsrcore/dispatchhelper.cpp
// Functions are ordered by original source line. This is decompiler
// output, not the author's source: names/types come from the PDB,
// local variable names and control flow are reconstructed.


// ---------------------------------------------------------------------
// `dynamic_initializer_for_'TempDispatchBuffer''  @ 4fc017ef  lines 13-13


void __cdecl _dynamic_initializer_for__TempDispatchBuffer__(void)

{
  atexit(_dynamic_atexit_destructor_for__TempDispatchBuffer__);
  return;
}


// ---------------------------------------------------------------------
// DispatchHelper::~DispatchHelper  @ 4fc1fe21  lines 23-25


void __thiscall DispatchHelper::~DispatchHelper(DispatchHelper *this)

{
  m_DispatchHelper = (DispatchHelper *)0x0;
  this->_padding_ = (int)vftable;
  std::
  vector<MorphObjectHelper::MorphObjectClass,std::allocator<MorphObjectHelper::MorphObjectClass>_>::
  _Tidy((vector<MorphObjectHelper::MorphObjectClass,std::allocator<MorphObjectHelper::MorphObjectClass>_>
         *)&this->DispatchList);
  return;
}


// ---------------------------------------------------------------------
// DispatchHelper::PostLoad  @ 4fc1fe36  lines 48-73


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
// DispatchHelper::AddToDispatch  @ 4fc1fef3  lines 91-368


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
       ((uVar4 != 0xc864a6ef && (uVar4 != 0x1aefd513)))) &&
      ((uVar4 != 0xa7275daa && ((uVar4 != 0x4a7aef92 && (uVar4 != 0x32493554)))))) &&
     ((uVar4 != 0xedb121ba && ((uVar4 != 0xf9df4e76 && (uVar4 != 0x25fd9ee0)))))) {
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
LAB_4fc20205:
          sprintf_s<64>(&local_144,pcVar18);
        }
        else {
          if (iVar5 == 2) {
            pcVar18 = "MediumWeaponSlot%d";
            goto LAB_4fc20205;
          }
          if (iVar5 == 3) {
            pcVar18 = "HardWeaponSlot%d";
            goto LAB_4fc20205;
          }
          if (iVar5 == 4) {
            pcVar18 = "ExtremeWeaponSlot%d";
            goto LAB_4fc20205;
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
    fVar12 = local_17c;
    fVar10 = local_170;
    fVar9 = local_178;
    if (0.0 <= local_174) {
      fVar11 = local_174;
      if (__real_3f800000 < local_174) {
        fVar11 = __real_3f800000;
      }
    }
    else {
      fVar11 = 0.0;
    }
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
    goto LAB_4fc20535;
  }
  if (local_14c == 0x53179125) {
    piVar8[7] = 3;
    goto LAB_4fc20535;
  }
  if ((uVar4 == 0xf9df4e76) || (uVar4 == 0x25fd9ee0)) {
    piVar8[7] = 6;
    goto LAB_4fc20535;
  }
  if (!param_7) {
    if (pcVar15 == (char *)0x0) {
LAB_4fc2042d:
      iVar5 = GetRandomInt((int)unaff_EDI,(int)unaff_ESI);
      if (iVar5 == 0) {
        fVar12 = GetRandomFloat(1.0);
        if (fVar12 < local_174) goto LAB_4fc204db;
        fVar12 = GetRandomFloat(1.0);
        if (local_17c <= fVar12) {
LAB_4fc20512:
          fVar12 = GetRandomFloat(1.0);
          if (local_178 <= fVar12) goto LAB_4fc20535;
          goto LAB_4fc20467;
        }
      }
      else if (iVar5 == 1) {
        fVar12 = GetRandomFloat(1.0);
        if (local_17c <= fVar12) {
          fVar12 = GetRandomFloat(1.0);
          if (local_174 <= fVar12) goto LAB_4fc20512;
          goto LAB_4fc204db;
        }
      }
      else {
        if (iVar5 != 2) goto LAB_4fc20535;
        fVar12 = GetRandomFloat(1.0);
        if (fVar12 < local_178) goto LAB_4fc20467;
        fVar12 = GetRandomFloat(1.0);
        if (fVar12 < local_174) goto LAB_4fc204db;
        fVar12 = GetRandomFloat(1.0);
        if (local_17c <= fVar12) goto LAB_4fc20535;
      }
      piVar8[7] = 2;
      goto LAB_4fc20535;
    }
    iVar5 = _strnicmp(pcVar15,"hunter",6);
    if (iVar5 != 0) {
      iVar5 = _strnicmp(pcVar15,"patrol",6);
      if (iVar5 == 0) {
        piVar8[7] = 2;
        goto LAB_4fc20535;
      }
      iVar5 = _strnicmp(pcVar15,"escort",6);
      if (iVar5 != 0) goto LAB_4fc2042d;
LAB_4fc20467:
      piVar8[7] = 5;
      goto LAB_4fc20535;
    }
  }
LAB_4fc204db:
  piVar8[7] = 4;
LAB_4fc20535:
  fVar12 = GetRandomFloat(1.0);
  if (fVar12 < local_170) {
    memset(local_144,0,0x40);
    GetRace(param_1);
    sprintf_s<64>(&local_144,"%csuser");
    SetPilotClass(param_1,local_144);
  }
  pbVar1 = (byte *)((int)piVar8 + 0x25);
  uVar19 = 0x74;
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
    uVar16 = 8;
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
  if ((0.0 <= fVar12) && (fVar9 = fVar12, fVar10 < fVar12)) {
    fVar9 = fVar10;
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
// DispatchHelper::DeleteDispatchObject  @ 4fc2084b  lines 371-394


void __thiscall DispatchHelper::DeleteDispatchObject(DispatchHelper *this,int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = param_2 * 0xa14;
  piVar2 = *(int **)&this->DispatchList;
  if (piVar2 != *(int **)&(this->DispatchList).field_0x4) {
    do {
      if (*piVar2 == param_1) {
        iVar1 = piVar2[7];
        if (iVar1 == 2) {
          piVar2 = (int *)((int)BZ1Helper::m_BZ1Helper->teamInfo + iVar3 + 0xac);
          *piVar2 = *piVar2 + -1;
          return;
        }
        if (iVar1 != 4) {
          if (iVar1 != 5) {
            return;
          }
          piVar2 = (int *)((int)BZ1Helper::m_BZ1Helper->teamInfo + iVar3 + 0xb4);
          *piVar2 = *piVar2 + -1;
          return;
        }
        piVar2 = (int *)((int)BZ1Helper::m_BZ1Helper->teamInfo + iVar3 + 0xb0);
        *piVar2 = *piVar2 + -1;
        return;
      }
      piVar2 = piVar2 + 0x52;
    } while (piVar2 != *(int **)&(this->DispatchList).field_0x4);
  }
  return;
}


// ---------------------------------------------------------------------
// DispatchHelper::Execute  @ 4fc208a9  lines 397-1857


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
  vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_> *pvVar28;
  long lVar29;
  Vector *pVVar30;
  vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_> *pvVar31;
  DispatchClass *pDVar32;
  DispatchClass *pDVar33;
  AiCommand AVar34;
  int iVar35;
  _Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_> unaff_ESI;
  int *piVar36;
  float *pfVar37;
  undefined4 *puVar38;
  Vector *unaff_EDI;
  BZ1Helper *pBVar39;
  vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_> **ppvVar40;
  float10 extraout_ST0;
  float fVar41;
  vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_> *pvVar42;
  float fVar43;
  char *pcVar44;
  _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
  _Var45;
  _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
  _Stack_780;
  char cStack_779;
  undefined4 uStack_778;
  undefined8 uStack_774;
  vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_> *pvStack_76c;
  vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_> *pvStack_768;
  float *local_764;
  int *piStack_760;
  vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_> *pvStack_75c;
  int iStack_758;
  BZ1Helper *local_754;
  undefined4 local_750;
  double dStack_74c;
  int iStack_740;
  _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
  local_73c;
  _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
  local_738;
  Vector VStack_734;
  int iStack_728;
  int local_724;
  int local_720;
  _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
  _Stack_71c;
  undefined4 uStack_718;
  undefined4 uStack_714;
  undefined4 uStack_710;
  int iStack_70c;
  int iStack_708;
  undefined4 uStack_704;
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
  undefined8 uStack_6b8;
  undefined4 uStack_6b0;
  float fStack_6ac;
  undefined4 uStack_6a8;
  undefined4 uStack_6a4;
  undefined4 uStack_6a0;
  float fStack_69c;
  float fStack_698;
  float fStack_694;
  undefined4 uStack_690;
  undefined4 uStack_68c;
  undefined4 uStack_688;
  undefined4 uStack_684;
  undefined4 uStack_680;
  undefined4 uStack_67c;
  undefined4 uStack_678;
  undefined4 uStack_674;
  undefined4 uStack_670;
  undefined4 uStack_66c;
  undefined4 uStack_668;
  undefined4 uStack_664;
  Vector VStack_660;
  Vector VStack_654;
  Vector VStack_648;
  undefined1 auStack_63c [8];
  undefined1 auStack_634 [8];
  float fStack_62c;
  float fStack_628;
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
  Vector VStack_564;
  Vector aVStack_558 [2];
  Vector VStack_540;
  Vector VStack_534;
  Vector aVStack_528 [2];
  Vector VStack_510;
  Vector aVStack_504 [2];
  vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
  *apvStack_4ec [142];
  char cStack_2b4;
  float *pfStack_264;
  int iStack_25c;
  char acStack_94 [4];
  char local_90 [60];
  char acStack_54 [72];
  uint local_c;
  
  local_c = __security_cookie ^ (uint)&_Stack_780;
  local_750 = param_1;
  uStack_778 = (float)CONCAT13(BZ1Helper::Logging,(undefined3)uStack_778);
  local_738._Ptr = (DispatchClass *)this;
  local_724 = ObjectHelper::GetNumHandles(param_1->m_ObjectHelper);
  local_720 = BuildingHelper::GetNumBuildingObjects(BuildingHelper::m_BuildingHelper);
  pfVar37 = &param_1->teamInfo[0].m_CPUBuildPodMaxDelay;
  local_754 = (BZ1Helper *)0x0;
  do {
    pBVar39 = local_754;
    if ((((*pfVar37 != ___real_00000000) && (*(char *)((int)pfVar37 + 0xc5) != '\0')) &&
        (pfVar37[-0x45] != 0.0)) &&
       ((local_764 = pfVar37, iVar26 = SecondsToTurns(((Vector *)(pfVar37 + 1))->x),
        BZ1Helper::m_TurnCounter % iVar26 == 0 &&
        (local_73c._Ptr = (DispatchClass *)GetRandomFloat(1.0), (float)local_73c._Ptr < *pfVar37))))
    {
      memset(local_90,0,0x40);
      bVar25 = GetBuildItem(0,(char *)0x4,(int *)"daywrecker",0,(char *)0x0,(char *)unaff_EDI,
                            (char *)unaff_ESI);
      if (((bVar25) &&
          ((iVar26 = (*misnImport.GetScrap)((int)pBVar39), -1 < iVar26 &&
           (bVar25 = DoesODFExist(local_90), bVar25)))) &&
         (iVar26 = BuildingHelper::GetNumBuildings
                             (BuildingHelper::m_BuildingHelper,(int)pBVar39,4,false,true,false,0,
                              (char *)0x0,(char *)0x0), pBVar24 = local_754, 0 < iVar26)) {
        fStack_6f4 = 0.0;
        fStack_6f0 = 0.0;
        auStack_6ec._0_4_ = 0.0;
        iVar26 = BuildingHelper::GetRandomBuilding
                           (BuildingHelper::m_BuildingHelper,(int)local_754,4,true,true,true,0,
                            (char *)0x0,(char *)0x0,0.0,(Vector)ZEXT812(0));
        GetPosition(iVar26,(Vector *)(auStack_6ec + 4));
        VStack_734.x = 0.0;
        pfVar37 = local_764;
        pBVar39 = pBVar24;
        if (0 < local_724) {
          iVar26 = 0;
          do {
            iVar35 = *(int *)&local_750->m_ObjectHelper->HandleList + iVar26;
            if (*(BZ1Helper **)(iVar35 + 0x1c) == pBVar24) {
              local_73c._Ptr = *(DispatchClass **)(iVar35 + 0x24);
              uStack_6b8 = (double)(float)local_73c._Ptr;
              fVar41 = GetDistance3DSquared(unaff_EDI,(Vector *)unaff_ESI);
              pfVar37 = local_764;
              local_73c._Ptr = (DispatchClass *)(float)((float10)uStack_6b8 * (float10)uStack_6b8);
              if (fVar41 < (float)local_73c._Ptr) {
                VVar19.y = fStack_6e4;
                VVar19.x = (float)auStack_6ec._4_4_;
                VVar19.z = (float)_Stack_6e0._Ptr;
                BZ1Helper::BuildAt(local_750,(int)local_764[-0x45],local_90,VVar19,1);
                pBVar39 = local_754;
                break;
              }
            }
            VStack_734.x = (float)((int)&((Vector *)VStack_734.x)->x + 1);
            iVar26 = iVar26 + 0x5c;
            pfVar37 = local_764;
          } while ((int)VStack_734.x < local_724);
        }
      }
    }
    _Var22._Ptr = local_738._Ptr;
    local_754 = (BZ1Helper *)((int)&pBVar39->_padding_ + 1);
    pfVar37 = pfVar37 + 0x285;
  } while ((int)local_754 < 0x10);
  pvVar31 = (vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_> *)
            &(local_738._Ptr)->DispatchTarget;
  pvStack_768 = pvVar31;
  local_764 = pfVar37;
  std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
  ::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
            (&local_73c,(DispatchClass *)(local_738._Ptr)->FleeTarget,(_Container_base0 *)pvVar31);
  _Var45._Ptr = local_73c._Ptr;
  std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
  ::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
            (&_Stack_71c,(DispatchClass *)(_Var22._Ptr)->FleeTarget,(_Container_base0 *)pvVar31);
  std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
  ::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
            ((_Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
              *)((int)&uStack_774 + 4),*(DispatchClass **)pvVar31,(_Container_base0 *)pvVar31);
  _Var27 = std::
           remove_if<std::_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>,bool_(__cdecl*)(DispatchHelper::DispatchClass_const_&)>
                     (uStack_774._4_4_,
                      (_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                       )_Stack_71c._Ptr,(_func___cdecl_bool_DispatchClass_ptr *)unaff_EDI);
  std::vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>::erase
            (pvVar31,(DispatchClass *)&_Stack_6fc,*(DispatchClass **)_Var27);
  std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
  ::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
            (&_Stack_780,*(DispatchClass **)pvVar31,(_Container_base0 *)pvVar31);
  std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
  ::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
            (&local_738,(DispatchClass *)(_Var22._Ptr)->FleeTarget,(_Container_base0 *)pvVar31);
  if (_Stack_780._Ptr != local_738._Ptr) {
    do {
      std::
      _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
      ::
      _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                (&_Stack_6c4,*(DispatchClass **)pvVar31,(_Container_base0 *)pvVar31);
      pvVar28 = (vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
                 *)(((int)_Stack_780._Ptr - (int)_Stack_6c4._Ptr) / 0x148);
      pvStack_768 = pvVar28;
      local_764 = (float *)GetTeamNum((_Stack_780._Ptr)->DispatchObject);
      piStack_760 = &local_754->_padding_ + (int)local_764 * 0x285;
      GetPosition((_Stack_780._Ptr)->DispatchObject,&VStack_734);
      bVar25 = IsAround(*(int *)&(_Stack_780._Ptr)->DispatchTarget);
      local_750 = (BZ1Helper *)CONCAT31(local_750._1_3_,bVar25);
      iVar26 = GetIndependence((_Stack_780._Ptr)->DispatchObject);
      local_750 = (BZ1Helper *)CONCAT13(iVar26 != 0,(uint3)local_750);
      _Stack_71c._Ptr = (DispatchClass *)GetCurrentWho((_Stack_780._Ptr)->DispatchObject);
      if ((float *)(_Stack_780._Ptr)->CurrTeam != local_764) {
        iVar26 = (_Stack_780._Ptr)->DispatchType;
        iVar35 = (_Stack_780._Ptr)->CurrTeam * 0xa14;
        if (iVar26 == 2) {
          piVar36 = (int *)((int)local_754->teamInfo + iVar35 + 0xac);
          *piVar36 = *piVar36 + -1;
          piStack_760[0x4f] = piStack_760[0x4f] + 1;
        }
        else if (iVar26 == 4) {
          piVar36 = (int *)((int)local_754->teamInfo + iVar35 + 0xb0);
          *piVar36 = *piVar36 + -1;
          piStack_760[0x50] = piStack_760[0x50] + 1;
        }
        else if (iVar26 == 5) {
          piVar36 = (int *)((int)local_754->teamInfo + iVar35 + 0xb4);
          *piVar36 = *piVar36 + -1;
          piStack_760[0x51] = piStack_760[0x51] + 1;
        }
        ClearDispatch((DispatchHelper *)local_73c._Ptr,(int)pvVar28);
        (_Stack_780._Ptr)->CurrTeam = (int)local_764;
      }
      pfVar37 = local_764;
      bVar25 = IsPlayer((_Stack_780._Ptr)->DispatchObject);
      if (!bVar25) {
        iVar26 = GetPlayerHandle((int)pfVar37);
        _Var22._Ptr = _Stack_780._Ptr;
        pvVar28 = pvStack_76c;
        if ((iVar26 == 0) &&
           ((local_750._3_1_ == '\x01' || ((_Stack_780._Ptr)->DispatchState == 2)))) {
          iVar26 = (_Stack_780._Ptr)->DispatchState;
          if (iVar26 == 0) {
            if ((((_Stack_780._Ptr)->IdleTime <= BZ1Helper::m_TurnCounter) &&
                (bVar25 = IsIdle((_Stack_780._Ptr)->DispatchObject), _Var22._Ptr = _Stack_780._Ptr,
                bVar25)) &&
               (((_Stack_780._Ptr)->SkipAIPCheck != false ||
                (*(char *)((int)piStack_760 + 0x1ae) != '\0')))) {
              iVar26 = (_Stack_780._Ptr)->DispatchType;
              if (iVar26 == 1) {
                iVar26 = (*misnImport.GetNearestEnemy)((_Stack_780._Ptr)->DispatchObject);
                GetPosition(iVar26,&VStack_5dc);
                uStack_774 = (double)((_Stack_780._Ptr)->EngageRange +
                                     (float)___real_4049000000000000);
                fVar43 = GetDistance2DSquared<Vector,Vector>((Vector *)_Var45._Ptr,unaff_EDI);
                fVar41 = (float)((float10)uStack_774 * (float10)uStack_774);
                uStack_774 = (double)CONCAT44(uStack_774._4_4_,fVar41);
                if (fVar41 < fVar43) {
                  iVar26 = GetRandomInt((int)_Var45._Ptr,(int)unaff_EDI);
                  dStack_74c = (double)CONCAT44(dStack_74c._4_4_,iVar26);
                  iStack_758 = GetRandomInt((int)_Var45._Ptr,(int)unaff_EDI);
                  *(undefined4 *)&(_Stack_780._Ptr)->DispatchTarget = 0;
                  pvStack_75c = (vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
                                 *)0x0;
                  fVar41 = (float)GetRandomTeam(1,1,SUB41(_Var45._Ptr,0),SUB41(unaff_EDI,0));
                  if ((int)fVar41 < 0) {
                    fVar41 = (float)GetRandomTeam(0,1,SUB41(_Var45._Ptr,0),SUB41(unaff_EDI,0));
                  }
                  uStack_778 = 0.0;
                  if (-1 < (int)fVar41) {
                    uStack_778 = fVar41;
                  }
                  pvStack_768 = (vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
                                 *)0x0;
                  pVStack_6f8 = (Vector *)0x0;
                  fStack_6f4 = 0.0;
                  fStack_6f0 = 0.0;
                  if (cStack_779 != '\0') {
                    std::
                    _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                    ::
                    _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                              (&_Stack_6e0,*(DispatchClass **)pvVar31,(_Container_base0 *)pvVar31);
                    FormatLogMessage(
                                    "Index is: %d, DispatchMode is: %d, DispatchMethod is: %d, RandomTargetTeam: %d"
                                    );
                  }
                  iVar26 = (int)uStack_778 * 0xa14;
                  pvVar31 = *(vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
                              **)((int)local_754->teamInfo + iVar26 + 0xc);
                  pvVar28 = (vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
                             *)0x0;
                  if ((((pvVar31 !=
                         (vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
                          *)0x0) ||
                       (pvVar31 = *(vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
                                    **)((int)local_754->teamInfo + iVar26 + 0x10),
                       pvVar31 !=
                       (vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
                        *)0x0)) ||
                      ((pvVar31 = *(vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
                                    **)((int)local_754->teamInfo + iVar26 + 0x18),
                       pvVar31 !=
                       (vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
                        *)0x0 || (pvVar31 = *(vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
                                              **)((int)local_754->teamInfo + iVar26 + 0x14),
                                 pvVar31 !=
                                 (vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
                                  *)0x0)))) &&
                     (pvStack_768 = pvVar31,
                     pvVar31 !=
                     (vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
                      *)0x0)) {
                    GetPosition((int)pvVar31,&VStack_5d0);
                    pVStack_6f8 = (Vector *)VStack_5d0.x;
                    fStack_6f4 = VStack_5d0.y;
                    fStack_6f0 = VStack_5d0.z;
                    pvVar28 = pvStack_75c;
                  }
                  pvVar31 = pvStack_768;
                  if (dStack_74c._0_4_ == 0.0) {
                    pvStack_768 = (vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
                                   *)0x0;
                    if (iStack_758 == 0) {
                      if (0 < local_724) {
                        dStack_74c = (double)CONCAT44(dStack_74c._4_4_,local_724);
                        uStack_778 = 0.0;
                        do {
                          if ((local_724 < 2) ||
                             (fVar41 = GetRandomFloat(1.0), fVar41 < __real_3f000000)) {
                            puVar38 = (undefined4 *)
                                      (*(int *)&BuildingHelper::m_BuildingHelper->BuildingList +
                                      (int)uStack_778);
                            ppvVar40 = apvStack_4ec;
                            for (iVar26 = 0x116; pvVar31 = apvStack_4ec[0], iVar26 != 0;
                                iVar26 = iVar26 + -1) {
                              *ppvVar40 = (vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
                                           *)*puVar38;
                              puVar38 = puVar38 + 1;
                              ppvVar40 = ppvVar40 + 1;
                            }
                            pvVar28 = pvStack_75c;
                            if (((pfStack_264 == local_764) && (cStack_2b4 != '\0')) &&
                               (0 < iStack_25c)) {
                              pvVar42 = (vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
                                         *)GetDistance2DSquared<Vector,Vector>
                                                     ((Vector *)_Var45._Ptr,unaff_EDI);
                              uStack_774 = (double)CONCAT44(uStack_774._4_4_,pvVar42);
                              pvVar28 = pvStack_75c;
                              if ((float)pvStack_768 < (float)pvVar42) {
                                pvStack_75c = pvVar31;
                                pvVar28 = pvVar31;
                                pvStack_768 = pvVar42;
                              }
                            }
                          }
                          uStack_778 = (float)((int)uStack_778 + 0x458);
                          iVar26 = (int)dStack_74c._0_4_ + -1;
                          dStack_74c = (double)CONCAT44(dStack_74c._4_4_,iVar26);
                        } while (iVar26 != 0);
                        goto LAB_4fc229cb;
                      }
LAB_4fc22b02:
                      _Var22._Ptr = _Stack_780._Ptr;
                      iVar26 = SecondsToTurns(___real_40a00000);
                      (_Var22._Ptr)->IdleTime = iVar26 + BZ1Helper::m_TurnCounter;
                      if (cStack_779 == '\0') goto LAB_4fc22b69;
                      std::
                      _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                      ::
                      _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                (&_Stack_6fc,*(DispatchClass **)pvStack_76c,
                                 (_Container_base0 *)pvStack_76c);
LAB_4fc22b4f:
                      FormatLogMessage(
                                      "Index is: %d Mode is: %d Method is: %d No Valid Target, IdleTime: %d"
                                      );
                    }
                    else {
                      if (iStack_758 == 1) {
                        auStack_6ec._0_4_ = 0.0;
                        pVVar30 = (Vector *)auStack_6ec;
                        auStack_6ec._4_4_ = 0.0;
                        fStack_6e4 = 0.0;
LAB_4fc228a7:
                        pvVar28 = (vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
                                   *)BuildingHelper::GetRandomBuilding
                                               (BuildingHelper::m_BuildingHelper,(int)local_764,1,
                                                true,true,true,0,(char *)0x0,(char *)0x0,0.0,
                                                *pVVar30);
                        pvStack_75c = pvVar28;
LAB_4fc229cb:
                        if (pvVar28 ==
                            (vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
                             *)0x0) goto LAB_4fc22b02;
                      }
                      else {
                        if (iStack_758 != 2) goto LAB_4fc22b02;
                        pvVar28 = (vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
                                   *)piStack_760[0x27];
                        pvStack_75c = pvVar28;
                        if (((pvVar28 ==
                              (vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
                               *)0x0) &&
                            (pvVar28 = (vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
                                        *)piStack_760[0x28], pvStack_75c = pvVar28,
                            pvVar28 ==
                            (vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
                             *)0x0)) &&
                           ((pvVar28 = (vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
                                        *)piStack_760[0x2a], pvStack_75c = pvVar28,
                            pvVar28 ==
                            (vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
                             *)0x0 && (pvVar28 = (vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
                                                  *)piStack_760[0x29], pvStack_75c = pvVar28,
                                      pvVar28 ==
                                      (vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
                                       *)0x0)))) {
                          VStack_648.x = 0.0;
                          VStack_648.y = 0.0;
                          VStack_648.z = 0.0;
                          pVVar30 = &VStack_648;
                          pvStack_75c = (vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
                                         *)0x0;
                          goto LAB_4fc228a7;
                        }
                      }
                      if (*(int *)&(_Stack_780._Ptr)->DispatchTarget == 0) {
                        *(vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
                          **)&(_Stack_780._Ptr)->DispatchTarget = pvVar28;
                      }
                      GetPosition(*(int *)&(_Stack_780._Ptr)->DispatchTarget,&VStack_57c);
                      uStack_774 = (double)CONCAT44(uStack_774._4_4_,_Stack_780._Ptr);
                      VVar7.y = fStack_6f0;
                      VVar7.x = fStack_6f4;
                      VVar7.z = VStack_57c.x;
                      VVar16.y = VStack_57c.z;
                      VVar16.x = VStack_57c.y;
                      VVar16.z = __real_42480000;
                      pVVar30 = GetPositionNearOrFar
                                          (pVStack_6f8,VVar7,VVar16,___real_437a0000,
                                           (float)_Var45._Ptr,SUB41(unaff_EDI,0));
                      *(float *)((int)(DispatchClass *)uStack_774 + 0xc) = pVVar30->x;
                      *(float *)((int)(DispatchClass *)uStack_774 + 0x10) = pVVar30->y;
                      *(float *)((int)(DispatchClass *)uStack_774 + 0x14) = pVVar30->z;
                      Goto((_Stack_780._Ptr)->DispatchObject,&(_Stack_780._Ptr)->DispatchSpot,0);
                      _Var22._Ptr = _Stack_780._Ptr;
                      fVar41 = GetRandomFloat(__real_41200000);
                      (_Var22._Ptr)->RandomDist = fVar41 + (float)___real_4024000000000000;
                      (_Stack_780._Ptr)->IdleTime = 0;
                      (_Stack_780._Ptr)->DispatchState = 1;
                      if (cStack_779 == '\0') goto LAB_4fc22b69;
                      memset(TempGetODFName,0,0x40);
                      GetODFName((int)_Var45._Ptr,(char *)unaff_EDI);
                      std::
                      _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                      ::
                      _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                (&_Stack_700,*(DispatchClass **)pvStack_76c,
                                 (_Container_base0 *)pvStack_76c);
LAB_4fc22408:
                      FormatLogMessage(
                                      "Index is: %d Mode is: %d Method is: %d Spot is: %f %f %f Target Is: \'%s\'"
                                      );
                    }
                  }
                  else if (dStack_74c._0_4_ == 1.4013e-45) {
                    pvStack_768 = (vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
                                   *)0x7f7fffff;
                    iVar26 = ScrapHelper::GetNumScrapObjects(ScrapHelper::m_ScrapHelper);
                    if (iStack_758 == 0) {
                      iVar35 = 0;
                      if (0 < iVar26) {
                        do {
                          if ((iVar26 < 2) ||
                             (fVar41 = GetRandomFloat(1.0), fVar41 < __real_3f000000)) {
                            iVar1 = *(int *)(*(int *)&ScrapHelper::m_ScrapHelper->ScrapList +
                                            iVar35 * 4);
                            dStack_74c = (double)CONCAT44(dStack_74c._4_4_,iVar1);
                            GetPosition(iVar1,&VStack_5a0);
                            pvVar31 = (vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
                                       *)GetDistance2DSquared<Vector,Vector>
                                                   ((Vector *)_Var45._Ptr,unaff_EDI);
                            uStack_774 = (double)CONCAT44(uStack_774._4_4_,pvVar31);
                            if ((float)pvVar31 < (float)pvStack_768) {
                              *(float *)&(_Stack_780._Ptr)->DispatchTarget = dStack_74c._0_4_;
                              pvStack_768 = pvVar31;
                            }
                          }
                          iVar35 = iVar35 + 1;
                        } while (iVar35 < iVar26);
                      }
                    }
                    else if (iStack_758 == 1) {
                      if (0 < iVar26) {
                        iVar26 = GetRandomInt((int)_Var45._Ptr,(int)unaff_EDI);
                        *(undefined4 *)&(_Stack_780._Ptr)->DispatchTarget =
                             *(undefined4 *)
                              (*(int *)&ScrapHelper::m_ScrapHelper->ScrapList + iVar26 * 4);
                      }
                    }
                    else if (iStack_758 == 2) {
                      pvStack_768 = (vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
                                     *)0x0;
                      iVar35 = 0;
                      if (0 < iVar26) {
                        do {
                          if ((iVar26 < 2) ||
                             (fVar41 = GetRandomFloat(1.0), fVar41 < __real_3f000000)) {
                            iVar1 = *(int *)(*(int *)&ScrapHelper::m_ScrapHelper->ScrapList +
                                            iVar35 * 4);
                            dStack_74c = (double)CONCAT44(dStack_74c._4_4_,iVar1);
                            GetPosition(iVar1,&VStack_5ac);
                            pvVar31 = (vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
                                       *)GetDistance2DSquared<Vector,Vector>
                                                   ((Vector *)_Var45._Ptr,unaff_EDI);
                            uStack_774 = (double)CONCAT44(uStack_774._4_4_,pvVar31);
                            if ((float)pvStack_768 < (float)pvVar31) {
                              *(float *)&(_Stack_780._Ptr)->DispatchTarget = dStack_74c._0_4_;
                              pvStack_768 = pvVar31;
                            }
                          }
                          iVar35 = iVar35 + 1;
                        } while (iVar35 < iVar26);
                      }
                    }
                    GetPosition(*(int *)&(_Stack_780._Ptr)->DispatchTarget,&VStack_594);
                    uStack_774 = (double)CONCAT44(uStack_774._4_4_,_Stack_780._Ptr);
                    VVar11.y = VStack_594.y;
                    VVar11.x = VStack_594.x;
                    VVar11.z = VStack_594.z;
                    pVVar30 = GetPositionNear(&VStack_510,VVar11,__real_41200000,__real_42480000);
                    *(float *)((int)(DispatchClass *)uStack_774 + 0xc) = pVVar30->x;
                    *(float *)((int)(DispatchClass *)uStack_774 + 0x10) = pVVar30->y;
                    *(float *)((int)(DispatchClass *)uStack_774 + 0x14) = pVVar30->z;
                    if (cStack_779 != '\0') {
                      std::
                      _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                      ::
                      _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                (&_Stack_6d4,*(DispatchClass **)pvStack_76c,
                                 (_Container_base0 *)pvStack_76c);
                      FormatLogMessage("Index is: %d Mode is: %d Method is: %d Spot is: %f %f %f");
                    }
                    bVar25 = IsNullVector((_Stack_780._Ptr)->DispatchSpot);
                    if (bVar25) {
                      uStack_684 = 0;
                      uStack_680 = 0;
                      uStack_67c = 0;
                      uStack_774._0_4_ = _Stack_780._Ptr;
                      iVar26 = BZ1Helper::GetRandomObject
                                         (local_754,-1,0,false,0,false,true,true,0,(char *)0x0,
                                          (char *)0x0,0.0,(Vector)ZEXT812(0));
                      *(int *)&((DispatchClass *)uStack_774)->DispatchTarget = iVar26;
                      GetPosition(*(int *)&(_Stack_780._Ptr)->DispatchTarget,&VStack_588);
                      uStack_774 = (double)CONCAT44(uStack_774._4_4_,_Stack_780._Ptr);
                      VVar12.y = VStack_588.y;
                      VVar12.x = VStack_588.x;
                      VVar12.z = VStack_588.z;
                      pVVar30 = GetPositionNear(aVStack_504,VVar12,__real_41200000,__real_42480000);
                      *(float *)((int)(DispatchClass *)uStack_774 + 0xc) = pVVar30->x;
                      *(float *)((int)(DispatchClass *)uStack_774 + 0x10) = pVVar30->y;
                      *(float *)((int)(DispatchClass *)uStack_774 + 0x14) = pVVar30->z;
                      if (cStack_779 != '\0') {
                        std::
                        _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                        ::
                        _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                  (a_Stack_6c0,*(DispatchClass **)pvStack_76c,
                                   (_Container_base0 *)pvStack_76c);
                        FormatLogMessage(
                                        "Pathing Failed, using random object. Index is: %d Mode is: %d Method is: %d Spot is: %f %f %f."
                                        );
                      }
                    }
                    Goto((_Stack_780._Ptr)->DispatchObject,&(_Stack_780._Ptr)->DispatchSpot,0);
                    _Var22._Ptr = _Stack_780._Ptr;
                    fVar41 = GetRandomFloat(__real_42480000);
                    (_Var22._Ptr)->RandomDist = fVar41 + (float)___real_4024000000000000;
                    (_Stack_780._Ptr)->IdleTime = 0;
                    (_Stack_780._Ptr)->DispatchState = 1;
                  }
                  else if (dStack_74c._0_4_ == 2.8026e-45) {
                    pvStack_768 = (vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
                                   *)0x7f7fffff;
                    if (iStack_758 == 0) {
                      if (0 < local_724) {
                        uStack_774 = (double)CONCAT44(uStack_774._4_4_,local_724);
                        uStack_778 = 0.0;
                        pvVar31 = pvVar28;
                        do {
                          fVar41 = uStack_778;
                          if ((local_724 < 2) ||
                             (fVar43 = GetRandomFloat(1.0), fVar43 < __real_3f000000)) {
                            puVar38 = (undefined4 *)
                                      (*(int *)&BuildingHelper::m_BuildingHelper->BuildingList +
                                      (int)fVar41);
                            ppvVar40 = apvStack_4ec;
                            for (iVar26 = 0x116; pvVar28 = apvStack_4ec[0], iVar26 != 0;
                                iVar26 = iVar26 + -1) {
                              *ppvVar40 = (vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
                                           *)*puVar38;
                              puVar38 = puVar38 + 1;
                              ppvVar40 = ppvVar40 + 1;
                            }
                            bVar25 = IsTeamAllied((int)local_764,(int)pfStack_264);
                            pvVar31 = pvStack_75c;
                            if (((!bVar25) && (cStack_2b4 != '\0')) && (0 < iStack_25c)) {
                              pvVar42 = (vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
                                         *)GetDistance2DSquared<Vector,Vector>
                                                     ((Vector *)_Var45._Ptr,unaff_EDI);
                              dStack_74c = (double)CONCAT44(dStack_74c._4_4_,pvVar42);
                              pvVar31 = pvStack_75c;
                              if ((float)pvVar42 < (float)pvStack_768) {
                                pvStack_75c = pvVar28;
                                pvVar31 = pvVar28;
                                pvStack_768 = pvVar42;
                              }
                            }
                          }
                          uStack_778 = (float)((int)uStack_778 + 0x458);
                          iVar26 = (int)(DispatchClass *)uStack_774 + -1;
                          uStack_774 = (double)CONCAT44(uStack_774._4_4_,iVar26);
                          pvVar28 = pvStack_75c;
                        } while (iVar26 != 0);
                        goto LAB_4fc22286;
                      }
                    }
                    else {
                      if (iStack_758 == 1) {
                        VStack_654.x = 0.0;
                        pVVar30 = &VStack_654;
                        VStack_654.y = 0.0;
                        VStack_654.z = 0.0;
                      }
                      else {
                        if (iStack_758 != 2) goto LAB_4fc22423;
                        pvVar28 = pvVar31;
                        if (pvVar31 !=
                            (vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
                             *)0x0) goto LAB_4fc22286;
                        VStack_660.x = 0.0;
                        pVVar30 = &VStack_660;
                        VStack_660.y = 0.0;
                        VStack_660.z = 0.0;
                      }
                      pvVar31 = (vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
                                 *)BuildingHelper::GetRandomBuilding
                                             (BuildingHelper::m_BuildingHelper,(int)local_764,4,true
                                              ,true,true,0,(char *)0x0,(char *)0x0,0.0,*pVVar30);
                      pvVar28 = pvVar31;
LAB_4fc22286:
                      pvStack_75c = pvVar28;
                      if (pvVar31 !=
                          (vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
                           *)0x0) {
                        GetPosition((int)pvVar31,&VStack_5c4);
                        uStack_774._0_4_ = _Stack_780._Ptr;
                        VVar21.y = VStack_5c4.y;
                        VVar21.x = VStack_5c4.x;
                        VVar21.z = VStack_5c4.z;
                        iVar26 = BuildingHelper::GetRandomBuilding
                                           (BuildingHelper::m_BuildingHelper,(int)local_764,4,true,
                                            true,true,0,(char *)0x0,(char *)0x0,__real_43480000,
                                            VVar21);
                        *(int *)&((DispatchClass *)uStack_774)->DispatchTarget = iVar26;
                        if (*(int *)&(_Stack_780._Ptr)->DispatchTarget == 0) {
                          *(vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
                            **)&(_Stack_780._Ptr)->DispatchTarget = pvStack_75c;
                        }
                        GetPosition(*(int *)&(_Stack_780._Ptr)->DispatchTarget,&VStack_5b8);
                        uStack_774 = (double)CONCAT44(uStack_774._4_4_,_Stack_780._Ptr);
                        VVar6.y = VStack_734.z;
                        VVar6.x = VStack_734.y;
                        VVar6.z = VStack_5b8.x;
                        VVar15.y = VStack_5b8.z;
                        VVar15.x = VStack_5b8.y;
                        VVar15.z = __real_42480000;
                        pVVar30 = GetPositionNearOrFar
                                            ((Vector *)VStack_734.x,VVar6,VVar15,___real_437a0000,
                                             (float)_Var45._Ptr,SUB41(unaff_EDI,0));
                        *(float *)((int)(DispatchClass *)uStack_774 + 0xc) = pVVar30->x;
                        *(float *)((int)(DispatchClass *)uStack_774 + 0x10) = pVVar30->y;
                        *(float *)((int)(DispatchClass *)uStack_774 + 0x14) = pVVar30->z;
                        Goto((_Stack_780._Ptr)->DispatchObject,&(_Stack_780._Ptr)->DispatchSpot,0);
                        _Var22._Ptr = _Stack_780._Ptr;
                        fVar41 = GetRandomFloat((_Stack_780._Ptr)->EngageRange);
                        (_Var22._Ptr)->RandomDist = fVar41 + (float)___real_4059000000000000;
                        (_Stack_780._Ptr)->IdleTime = 0;
                        (_Stack_780._Ptr)->DispatchState = 1;
                        if (cStack_779 != '\0') {
                          memset(TempGetODFName,0,0x40);
                          GetODFName((int)_Var45._Ptr,(char *)unaff_EDI);
                          std::
                          _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                          ::
                          _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                    (&_Stack_6dc,*(DispatchClass **)pvStack_76c,
                                     (_Container_base0 *)pvStack_76c);
                          goto LAB_4fc22408;
                        }
                        goto LAB_4fc22b69;
                      }
                    }
LAB_4fc22423:
                    _Var22._Ptr = _Stack_780._Ptr;
                    iVar26 = SecondsToTurns(___real_40a00000);
                    (_Var22._Ptr)->IdleTime = iVar26 + BZ1Helper::m_TurnCounter;
                    if (cStack_779 != '\0') {
                      std::
                      _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                      ::
                      _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                (&_Stack_6d8,*(DispatchClass **)pvStack_76c,
                                 (_Container_base0 *)pvStack_76c);
                      goto LAB_4fc22b4f;
                    }
                  }
                }
              }
              else if (iVar26 == 2) {
                if ((0 < piStack_760[0x4c]) && (piStack_760[0x4f] < piStack_760[0x4c])) {
                  piStack_760[0x4f] = piStack_760[0x4f] + 1;
                  iVar26 = (int)local_764 * 0xc;
                  if (*(int *)(local_754[1].teamInfo[0].BaseSlotName[1] + iVar26 + 0x23) -
                      *(int *)(local_754[1].teamInfo[0].BaseSlotName[1] + iVar26 + 0x1f) >> 2 < 1) {
                    fVar41 = GetRandomFloat(1.0);
                    uStack_774 = (double)fVar41;
                    if ((float)___real_3fc99999a0000000 <= fVar41) {
                      uStack_66c = 0;
                      uStack_668 = 0;
                      uStack_664 = 0;
                      iVar26 = 1;
                    }
                    else {
                      uStack_678 = 0;
                      uStack_674 = 0;
                      uStack_670 = 0;
                      iVar26 = 3;
                    }
                    iVar26 = BuildingHelper::GetRandomBuilding
                                       (BuildingHelper::m_BuildingHelper,(int)local_764,iVar26,true,
                                        true,true,0,(char *)0x0,(char *)0x0,0.0,(Vector)ZEXT812(0));
                    if ((uStack_774 < ___real_3fb99999a0000000) || (iVar26 == 0)) {
                      dStack_74c = (double)CONCAT44(dStack_74c._4_4_,_Stack_780._Ptr);
                      fVar41 = (_Stack_780._Ptr)->EngageRange * (float)___real_4014000000000000;
                      uStack_774 = (double)CONCAT44(uStack_774._4_4_,fVar41);
                      VVar10.y = VStack_734.y;
                      VVar10.x = VStack_734.x;
                      VVar10.z = VStack_734.z;
                      pVVar30 = GetPositionNear(aVStack_528,VVar10,__real_42c80000,fVar41);
                      iVar26 = (int)dStack_74c._0_4_;
                    }
                    else {
                      GetPosition(iVar26,&VStack_5e8);
                      uStack_774 = (double)CONCAT44(uStack_774._4_4_,_Stack_780._Ptr);
                      VVar9.y = VStack_5e8.y;
                      VVar9.x = VStack_5e8.x;
                      VVar9.z = VStack_5e8.z;
                      pVVar30 = GetPositionNear(&VStack_534,VVar9,__real_42480000,__real_42c80000);
                      iVar26 = (int)(DispatchClass *)uStack_774;
                    }
                    *(float *)(iVar26 + 0xc) = pVVar30->x;
                    *(float *)(iVar26 + 0x10) = pVVar30->y;
                    *(float *)(iVar26 + 0x14) = pVVar30->z;
                    Goto((_Stack_780._Ptr)->DispatchObject,&(_Stack_780._Ptr)->DispatchSpot,0);
                    (_Stack_780._Ptr)->DispatchState = 1;
                    (_Stack_780._Ptr)->IdleTime = 0;
                    if (cStack_779 != '\0') {
                      memset(TempGetODFName,0,0x40);
                      GetODFName((int)_Var45._Ptr,(char *)unaff_EDI);
                      std::
                      _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                      ::
                      _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                (&_Stack_6d0,*(DispatchClass **)pvStack_76c,
                                 (_Container_base0 *)pvStack_76c);
                      FormatLogMessage(
                                      "Index: %d sent to Dynamic Patrol Near Handle: %08x, ODF: \'%s\', Position: %f %f %f"
                                      );
                    }
                  }
                  else {
                    iVar35 = GetRandomInt((int)_Var45._Ptr,(int)unaff_EDI);
                    uStack_778 = 0.0;
                    pcVar44 = *(char **)(*(int *)(local_754[1].teamInfo[0].BaseSlotName[1] +
                                                 iVar26 + 0x1f) + iVar35 * 4);
                    if ((pcVar44 != (char *)0x0) &&
                       (GetPathPoints(pcVar44,&uStack_778,(float *)0x0), uStack_778 != 0.0)) {
                      Patrol((_Stack_780._Ptr)->DispatchObject,pcVar44,0);
                      (_Stack_780._Ptr)->DispatchState = 1;
                      (_Stack_780._Ptr)->IdleTime = 0;
                      if (cStack_779 != '\0') {
                        std::
                        _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                        ::
                        _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                  (&_Stack_6c8,*(DispatchClass **)pvVar31,
                                   (_Container_base0 *)pvVar31);
                        pcVar44 = "Index: %d sent to Patrol path: \'%s\', TurnCount: %d";
                        goto LAB_4fc20f48;
                      }
                    }
                  }
                }
              }
              else if (iVar26 == 3) {
                iVar26 = (int)local_764 * 0xc;
                if (*(int *)(local_754[1].teamInfo[0].PlayerPilotODF + iVar26 + 0x23) -
                    *(int *)(local_754[1].teamInfo[0].PlayerPilotODF + iVar26 + 0x1f) >> 2 < 1) {
                  pvStack_768 = (vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
                                 *)GetRandomInt((int)_Var45._Ptr,(int)unaff_EDI);
                  if (pvStack_768 ==
                      (vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
                       *)0x0) {
                    uStack_690 = 0;
                    uStack_68c = 0;
                    uStack_688 = 0;
                    uStack_6b8 = (double)((ulonglong)uStack_6b8 & 0xffffffff);
                    uStack_6b0 = 0;
                    fStack_6ac = 0.0;
                    uStack_774 = (double)CONCAT44(uStack_774._4_4_,BuildingHelper::m_BuildingHelper)
                    ;
                    iVar26 = BuildingHelper::GetRandomBuilding
                                       (BuildingHelper::m_BuildingHelper,(int)local_764,4,true,true,
                                        true,0,(char *)0x0,(char *)0x0,0.0,(Vector)ZEXT812(0));
                    dStack_74c = (double)CONCAT44(dStack_74c._4_4_,iVar26);
                    VVar20.y = (float)uStack_6b0;
                    VVar20.x = (float)uStack_6b8._4_4_;
                    VVar20.z = fStack_6ac;
                    iVar26 = BuildingHelper::GetRandomBuilding
                                       ((BuildingHelper *)(DispatchClass *)uStack_774,(int)local_764
                                        ,1,true,true,true,0,(char *)0x0,(char *)0x0,0.0,VVar20);
                    GetPosition(iVar26,&VStack_60c);
                    GetPosition((int)dStack_74c._0_4_,&VStack_600);
                    VVar5.y = VStack_600.z;
                    VVar5.x = VStack_600.y;
                    VVar5.z = VStack_60c.x;
                    VVar14.y = VStack_60c.z;
                    VVar14.x = VStack_60c.y;
                    VVar14.z = __real_42c80000;
                    GetPositionNearOrFar
                              ((Vector *)VStack_600.x,VVar5,VVar14,__real_43480000,
                               (float)_Var45._Ptr,SUB41(unaff_EDI,0));
                    pfVar37 = afStack_5f4;
LAB_4fc21b7f:
                    ((_Stack_780._Ptr)->DispatchSpot).x = *pfVar37;
                    ((_Stack_780._Ptr)->DispatchSpot).y = pfVar37[1];
                    ((_Stack_780._Ptr)->DispatchSpot).z = pfVar37[2];
                    pvVar31 = pvStack_76c;
                  }
                  else if (pvStack_768 ==
                           (vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
                            *)0x1) {
                    fVar41 = (local_754->mapInfo).MapDepth;
                    uStack_778 = (local_754->mapInfo).MapWidth;
                    uStack_774 = (double)CONCAT44(uStack_774._4_4_,fVar41);
                    fStack_69c = GetRandomFloat((float)((uint)fVar41 ^
                                                       __xmm_80000000800000008000000080000000),
                                                fVar41);
                    fStack_698 = 0.0;
                    fStack_694 = GetRandomFloat((float)((uint)uStack_778 ^
                                                       __xmm_80000000800000008000000080000000),
                                                uStack_778);
                    _Var22._Ptr = _Stack_780._Ptr;
                    ((_Stack_780._Ptr)->DispatchSpot).x = fStack_69c;
                    ((_Stack_780._Ptr)->DispatchSpot).y = fStack_698;
                    ((_Stack_780._Ptr)->DispatchSpot).z = fStack_694;
                    fVar41 = TerrainFindFloor(((_Stack_780._Ptr)->DispatchSpot).x,
                                              ((_Stack_780._Ptr)->DispatchSpot).z);
                    ((_Var22._Ptr)->DispatchSpot).y = fVar41;
                    pvVar31 = pvStack_76c;
                  }
                  else if (pvStack_768 ==
                           (vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
                            *)0x2) {
                    uStack_6a8 = 0;
                    uStack_6a4 = 0;
                    uStack_6a0 = 0;
                    pVStack_624 = (Vector *)VStack_734.x;
                    fStack_620 = VStack_734.y;
                    fStack_61c = VStack_734.z;
                    iVar26 = BuildingHelper::GetRandomBuilding
                                       (BuildingHelper::m_BuildingHelper,(int)local_764,4,true,true,
                                        true,0,(char *)0x0,(char *)0x0,0.0,(Vector)ZEXT812(0));
                    GetPosition(iVar26,(Vector *)(auStack_634 + 4));
                    VVar4.y = fStack_61c;
                    VVar4.x = fStack_620;
                    VVar4.z = (float)auStack_634._4_4_;
                    VVar13.y = fStack_628;
                    VVar13.x = fStack_62c;
                    VVar13.z = __real_42c80000;
                    GetPositionNearOrFar
                              (pVStack_624,VVar4,VVar13,__real_43480000,(float)_Var45._Ptr,
                               SUB41(unaff_EDI,0));
                    pfVar37 = afStack_618;
                    goto LAB_4fc21b7f;
                  }
                  if (cStack_779 != '\0') {
                    uStack_778 = *(float *)pvVar31;
                    std::_Iterator_base0::_Adopt((_Iterator_base0 *)&uStack_778,pvVar31);
                    FormatLogMessage(
                                    "Index: %d sent to Dynamic Minelaying, DispatchState: %d, Position: %f %f %f"
                                    );
                  }
                }
                else {
                  iVar35 = GetRandomInt((int)_Var45._Ptr,(int)unaff_EDI);
                  uStack_778 = 0.0;
                  pcVar44 = *(char **)(*(int *)(local_754[1].teamInfo[0].PlayerPilotODF +
                                               iVar26 + 0x1f) + iVar35 * 4);
                  dStack_74c = (double)CONCAT44(dStack_74c._4_4_,pcVar44);
                  if ((pcVar44 != (char *)0x0) &&
                     (GetPathPoints(pcVar44,&uStack_778,(float *)0x0), uStack_778 != 0.0)) {
                    uStack_774 = (double)CONCAT44(uStack_774._4_4_,_Stack_780._Ptr);
                    pVVar30 = GetVectorFromPath((Vector *)0x0,(char *)_Var45._Ptr,(int)unaff_EDI);
                    pVVar30 = GetPositionNear(&VStack_540,*pVVar30,___real_41c80000,__real_42480000)
                    ;
                    *(float *)((int)(DispatchClass *)uStack_774 + 0xc) = pVVar30->x;
                    *(float *)((int)(DispatchClass *)uStack_774 + 0x10) = pVVar30->y;
                    *(float *)((int)(DispatchClass *)uStack_774 + 0x14) = pVVar30->z;
                    if (cStack_779 != '\0') {
                      std::
                      _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                      ::
                      _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                (&_Stack_6cc,*(DispatchClass **)pvStack_76c,
                                 (_Container_base0 *)pvStack_76c);
                      FormatLogMessage("Index: %d sent to Lay Mines at path: \'%s\'");
                    }
                  }
                }
                bVar25 = IsNullVector((_Stack_780._Ptr)->DispatchSpot);
                if (!bVar25) {
                  Goto((_Stack_780._Ptr)->DispatchObject,&(_Stack_780._Ptr)->DispatchSpot,0);
                  _Var22._Ptr = _Stack_780._Ptr;
                  fVar41 = ___real_43960000;
                  (_Stack_780._Ptr)->DispatchState = 1;
                  iVar26 = SecondsToTurns(fVar41);
                  (_Var22._Ptr)->IdleTime = iVar26 + BZ1Helper::m_TurnCounter;
                  if (cStack_779 != '\0') {
                    uStack_778 = *(float *)pvStack_76c;
                    std::_Iterator_base0::_Adopt((_Iterator_base0 *)&uStack_778,pvStack_76c);
                    pcVar44 = "Index is: %d Minelayer No Valid Target, IdleTime: %d";
                    goto LAB_4fc20e4b;
                  }
                }
              }
              else if (iVar26 == 4) {
                if ((0 < piStack_760[0x4d]) && (piStack_760[0x50] < piStack_760[0x4d])) {
                  piStack_760[0x50] = piStack_760[0x50] + 1;
                  SetCommand((_Stack_780._Ptr)->DispatchObject,0x15,0,0,(char *)0x0,0);
                  _Var22._Ptr = _Stack_780._Ptr;
                  fVar41 = ___real_43960000;
                  (_Stack_780._Ptr)->DispatchState = 1;
                  iVar26 = SecondsToTurns(fVar41);
                  (_Var22._Ptr)->IdleTime = iVar26 + BZ1Helper::m_TurnCounter;
                  if (cStack_779 != '\0') {
                    uStack_778 = *(float *)pvVar31;
                    std::_Iterator_base0::_Adopt((_Iterator_base0 *)&uStack_778,pvVar31);
                    pcVar44 = "Index: %d Hunt Task Starting, Hunt Command issued. IdleTime: %d";
                    goto LAB_4fc20e4b;
                  }
                }
              }
              else if (((iVar26 == 5) && (0 < piStack_760[0x4e])) &&
                      (piStack_760[0x51] < piStack_760[0x4e])) {
                iVar26 = UtilityShipHelper::GetEscortTarget
                                   (UtilityShipHelper::m_UtilityShipHelper,(int)local_764,3);
                *(int *)&(_Var22._Ptr)->DispatchTarget = iVar26;
                if (*(int *)&(_Stack_780._Ptr)->DispatchTarget != 0) {
                  Defend2((_Stack_780._Ptr)->DispatchObject,
                          *(int *)&(_Stack_780._Ptr)->DispatchTarget,0);
                  (_Stack_780._Ptr)->DispatchState = 1;
                  (_Stack_780._Ptr)->IdleTime = 0;
                  if (cStack_779 != '\0') {
                    memset(TempGetODFName,0,0x40);
                    GetODFName((int)_Var45._Ptr,(char *)unaff_EDI);
                    uStack_718 = *(undefined4 *)pvVar31;
                    std::_Iterator_base0::_Adopt((_Iterator_base0 *)&uStack_718,pvVar31);
                    FormatLogMessage("Index: %d Escort Task Starting, Target: \'%s\'");
                  }
                  piStack_760[0x51] = piStack_760[0x51] + 1;
                }
              }
            }
          }
          else if (iVar26 == 1) {
            if ((_Stack_780._Ptr)->DispatchType == 1) {
              if ((_Stack_780._Ptr)->IdleTime == 0) {
                bVar25 = IsDeployed((_Stack_780._Ptr)->DispatchObject);
                _Var22._Ptr = _Stack_780._Ptr;
                if (bVar25) {
                  if ((_Stack_780._Ptr)->IdleTime != 0) goto LAB_4fc20f93;
                }
                else {
                  iVar26 = SecondsToTurns(___real_43960000);
                  (_Var22._Ptr)->IdleTime = iVar26 + BZ1Helper::m_TurnCounter;
                }
              }
              else {
LAB_4fc20f93:
                bVar25 = IsDeployed((_Stack_780._Ptr)->DispatchObject);
                if (bVar25) {
                  (_Stack_780._Ptr)->DispatchState = 0;
                }
              }
            }
            if (((_Stack_780._Ptr)->SkipAIPCheck != false) ||
               (*(char *)((int)piStack_760 + 0x1ae) != '\0')) {
              if ((0 < (_Stack_780._Ptr)->IdleTime) &&
                 ((_Stack_780._Ptr)->IdleTime <= BZ1Helper::m_TurnCounter)) {
                ClearDispatch((DispatchHelper *)local_73c._Ptr,(int)pvStack_768);
              }
              iVar26 = (_Stack_780._Ptr)->DispatchType;
              if (iVar26 == 1) {
                bVar25 = IsDeployed((_Stack_780._Ptr)->DispatchObject);
                if (bVar25) goto LAB_4fc22b69;
                uStack_778 = 0.0;
                local_750._0_3_ = (uint3)(byte)local_750;
                if (0 < iStack_728) {
                  iStack_758 = 0;
                  do {
                    piVar36 = (int *)(*(int *)&local_754->m_ObjectHelper->HandleList + iStack_758);
                    iStack_708 = *piVar36;
                    bVar25 = IsTeamAllied((int)local_764,piVar36[7]);
                    if ((!bVar25) &&
                       ((piVar36[4] == 2 ||
                        ((piVar36[2] == 0x4a7aef92 && (bVar25 = IsDeployed(iStack_708), bVar25))))))
                    {
                      uStack_774 = (double)((float)piVar36[9] + (float)___real_4049000000000000);
                      fVar43 = GetDistance2DSquared<Vector,Vector>((Vector *)_Var45._Ptr,unaff_EDI);
                      fVar41 = (float)((float10)uStack_774 * (float10)uStack_774);
                      uStack_774 = (double)CONCAT44(uStack_774._4_4_,fVar41);
                      if (fVar43 < fVar41) {
                        local_750._0_2_ = CONCAT11(1,(byte)local_750);
                        fVar41 = GetRandomFloat(1.0);
                        if (fVar41 < __real_3f000000) {
                          local_750._0_3_ = CONCAT12(1,(undefined2)local_750);
                        }
                        if (cStack_779 != '\0') {
                          (*misnImport.GetDistanceObject)
                                    (&(_Stack_780._Ptr)->DispatchObject,&iStack_708);
                          uStack_704 = *(undefined4 *)pvVar31;
                          uStack_774 = (double)CONCAT44(uStack_774._4_4_,(float)extraout_ST0);
                          std::_Iterator_base0::_Adopt((_Iterator_base0 *)&uStack_704,pvVar31);
                          FormatLogMessage(
                                          "Index: %d Turret Encountered an Enemy on Team: %d Distance Is: %f, Return is: %d"
                                          );
                        }
                        break;
                      }
                    }
                    uStack_778 = (float)((int)uStack_778 + 1);
                    iStack_758 = iStack_758 + 0x5c;
                  } while ((int)uStack_778 < iStack_728);
                }
                if ((byte)local_750 == '\0') {
LAB_4fc214fa:
                  if (local_750._1_1_ == '\0') goto LAB_4fc22b69;
                }
                else {
                  uStack_774 = (double)((_Stack_780._Ptr)->RandomDist +
                                       (float)___real_4014000000000000);
                  fVar43 = GetDistance2DSquared<Vector,Vector>((Vector *)_Var45._Ptr,unaff_EDI);
                  fVar41 = (float)((float10)uStack_774 * (float10)uStack_774);
                  uStack_774 = (double)CONCAT44(uStack_774._4_4_,fVar41);
                  if (fVar41 < fVar43) goto LAB_4fc214fa;
                }
                if (local_750._2_1_ == '\0') {
                  if (local_750._1_1_ == '\0') {
                    Defend((_Stack_780._Ptr)->DispatchObject,0);
                  }
                  else {
                    uStack_774 = (double)CONCAT44(uStack_774._4_4_,_Stack_780._Ptr);
                    VVar8.y = VStack_734.y;
                    VVar8.x = VStack_734.x;
                    VVar8.z = VStack_734.z;
                    pVVar30 = GetPositionNear(aVStack_558,VVar8,__real_41200000,___real_41f00000);
                    *(float *)((int)(DispatchClass *)uStack_774 + 0xc) = pVVar30->x;
                    *(float *)((int)(DispatchClass *)uStack_774 + 0x10) = pVVar30->y;
                    *(float *)((int)(DispatchClass *)uStack_774 + 0x14) = pVVar30->z;
                    Goto((_Stack_780._Ptr)->DispatchObject,&(_Stack_780._Ptr)->DispatchSpot,0);
                    pvVar31 = pvStack_76c;
                    if (cStack_779 != '\0') {
                      uStack_778 = *(float *)pvStack_76c;
                      std::_Iterator_base0::_Adopt((_Iterator_base0 *)&uStack_778,pvStack_76c);
                      FormatLogMessage("Index is: %d Spot is: %f %f %f");
                    }
                  }
                  _Var22._Ptr = _Stack_780._Ptr;
                  fVar41 = ___real_43960000;
                  (_Stack_780._Ptr)->DispatchState = 0;
                  iVar26 = SecondsToTurns(fVar41);
                  (_Var22._Ptr)->IdleTime = iVar26 + BZ1Helper::m_TurnCounter;
                  if (cStack_779 != '\0') {
                    uStack_778 = *(float *)pvVar31;
                    std::_Iterator_base0::_Adopt((_Iterator_base0 *)&uStack_778,pvVar31);
                    pcVar44 = "Index is: %d Turret Encountered an Enemy, IdleTime: %d";
LAB_4fc20e4b:
                    FormatLogMessage(pcVar44);
                  }
                }
                else {
                  ClearDispatch((DispatchHelper *)local_73c._Ptr,(int)pvStack_768);
                }
              }
              else if (iVar26 == 2) {
                bVar25 = IsIdle((_Stack_780._Ptr)->DispatchObject);
                _Var22._Ptr = _Stack_780._Ptr;
                if (bVar25) {
                  pcVar44 = local_754[1].teamInfo[0].BaseSlotName[1] + (int)local_764 * 0xc + 0x1f;
                  if ((*(int *)(pcVar44 + 4) - *(int *)pcVar44 & 0xfffffffcU) == 0) {
                    (_Stack_780._Ptr)->IdleTime = 0;
                    if (cStack_779 != '\0') {
                      uStack_778 = *(float *)pvVar31;
                      std::_Iterator_base0::_Adopt((_Iterator_base0 *)&uStack_778,pvVar31);
                      FormatLogMessage("Index: %d sent to Dynamic Patrol Reset, Cmd == CMD_NONE");
                    }
                  }
                  else {
                    iVar26 = SecondsToTurns(___real_41700000);
                    (_Var22._Ptr)->IdleTime = iVar26 + BZ1Helper::m_TurnCounter;
                    if (cStack_779 != '\0') {
                      uStack_778 = *(float *)pvVar31;
                      std::_Iterator_base0::_Adopt((_Iterator_base0 *)&uStack_778,pvVar31);
                      FormatLogMessage(
                                      "Patrol Unit %d interrupted, resetting idle timer. TurnCount: %d, IdleTime: %d"
                                      );
                    }
                  }
                  (_Stack_780._Ptr)->DispatchState = 0;
                }
              }
              else if (iVar26 == 3) {
                fVar41 = GetDistance2DSquared<Vector,Vector>((Vector *)_Var45._Ptr,unaff_EDI);
                if (fVar41 < (float)___real_4059000000000000) {
                  SetCommand((_Stack_780._Ptr)->DispatchObject,0x1b,0,0,(char *)0x0,0);
                  _Var22._Ptr = _Stack_780._Ptr;
                  fVar41 = ___real_43960000;
                  (_Stack_780._Ptr)->DispatchState = 0;
                  iVar26 = SecondsToTurns(fVar41);
                  (_Var22._Ptr)->IdleTime = iVar26 + BZ1Helper::m_TurnCounter;
                  if (cStack_779 != '\0') {
                    uStack_778 = *(float *)pvVar31;
                    std::_Iterator_base0::_Adopt((_Iterator_base0 *)&uStack_778,pvVar31);
                    FormatLogMessage(
                                    "Index: %d Minelayer reached Spot: %f %f %f, laying mines..., IdleTime: %d"
                                    );
                  }
                }
              }
              else {
                if (iVar26 == 4) {
                  bVar25 = IsIdle((_Stack_780._Ptr)->DispatchObject);
                  if (!bVar25) goto LAB_4fc22b69;
                  SetCommand((_Stack_780._Ptr)->DispatchObject,0x15,0,0,(char *)0x0,0);
                  _Var22._Ptr = _Stack_780._Ptr;
                  iVar26 = SecondsToTurns(___real_43960000);
                  (_Var22._Ptr)->IdleTime = iVar26 + BZ1Helper::m_TurnCounter;
                  if (cStack_779 == '\0') goto LAB_4fc22b69;
                  uStack_778 = *(float *)pvVar31;
                  std::_Iterator_base0::_Adopt((_Iterator_base0 *)&uStack_778,pvVar31);
                  pcVar44 = "Index: %d Hunt Task Continuing, Re-Issueing Hunt Command. IdleTime: %d"
                  ;
                  goto LAB_4fc20e4b;
                }
                if ((iVar26 == 5) && ((byte)local_750 == '\0')) {
                  fVar41 = GetRandomFloat(1.0);
                  _Var22._Ptr = _Stack_780._Ptr;
                  if (__real_3f000000 <= fVar41) {
                    (_Stack_780._Ptr)->DispatchType = 0;
                    ClearDispatch((DispatchHelper *)local_73c._Ptr,(int)pvStack_768);
                    _Var22._Ptr = _Stack_780._Ptr;
                    fVar41 = ___real_43e10000;
                    iVar35 = 0;
                    piStack_760[0x51] = piStack_760[0x51] + -1;
                    iVar26 = GetNearestEnemy((_Stack_780._Ptr)->DispatchObject,true,false,fVar41);
                    Attack((_Var22._Ptr)->DispatchObject,iVar26,iVar35);
                    if (cStack_779 != '\0') {
                      uStack_778 = *(float *)pvVar31;
                      std::_Iterator_base0::_Adopt((_Iterator_base0 *)&uStack_778,pvVar31);
                      FormatLogMessage("Index: %d Escort Target lost, Going Bezerk!");
                    }
                  }
                  else {
                    iVar26 = UtilityShipHelper::GetEscortTarget
                                       (UtilityShipHelper::m_UtilityShipHelper,(int)local_764,3);
                    *(int *)&(_Var22._Ptr)->DispatchTarget = iVar26;
                    Defend2((_Stack_780._Ptr)->DispatchObject,
                            *(int *)&(_Stack_780._Ptr)->DispatchTarget,0);
                    if (cStack_779 != '\0') {
                      memset(TempGetODFName,0,0x40);
                      GetODFName((int)_Var45._Ptr,(char *)unaff_EDI);
                      uStack_710 = *(undefined4 *)pvVar31;
                      std::_Iterator_base0::_Adopt((_Iterator_base0 *)&uStack_710,pvVar31);
                      pcVar44 = "Index: %d Escort Target lost, picking new Target: \'%s\'";
                      goto LAB_4fc20e4b;
                    }
                  }
                }
              }
            }
          }
          else if (iVar26 == 2) {
            if ((_Stack_780._Ptr)->IdleTime <= BZ1Helper::m_TurnCounter) {
              SetIndependence((_Stack_780._Ptr)->DispatchObject,1);
              _Var22._Ptr = _Stack_780._Ptr;
              lVar29 = GetCurHealth((_Stack_780._Ptr)->DispatchObject);
              (_Var22._Ptr)->FleeHealthValue = lVar29;
              ClearDispatch((DispatchHelper *)local_73c._Ptr,(int)pvStack_768);
              _Var22._Ptr = _Stack_780._Ptr;
              iVar26 = SecondsToTurns(___real_41700000);
              (_Var22._Ptr)->IdleTime = iVar26 + BZ1Helper::m_TurnCounter;
              bVar25 = IsAround((_Stack_780._Ptr)->FleeTarget);
              if (bVar25) {
                Attack((_Stack_780._Ptr)->DispatchObject,(_Stack_780._Ptr)->FleeTarget,0);
              }
              if (cStack_779 != '\0') {
                memset(TempGetODFName,0,0x40);
                GetODFName((int)_Var45._Ptr,(char *)unaff_EDI);
                iStack_70c = *(int *)pvStack_76c;
                std::_Iterator_base0::_Adopt((_Iterator_base0 *)&iStack_70c,pvStack_76c);
                pcVar44 = "Index: %d Flee State Ending. Last Target: \'%s\', IdleTime: %d";
LAB_4fc20f48:
                FormatLogMessage(pcVar44);
              }
            }
          }
          else if ((iVar26 - 3U < 2) &&
                  (((((iVar26 == 4 &&
                      (fVar41 = GetHealth((_Stack_780._Ptr)->DispatchObject),
                      (_Var22._Ptr)->GetRepairRatio < fVar41)) ||
                     ((_Var22._Ptr = _Stack_780._Ptr, (_Stack_780._Ptr)->DispatchState == 3 &&
                      (lVar29 = GetCurAmmo((_Stack_780._Ptr)->DispatchObject),
                      (_Var22._Ptr)->MinFireAmmo < lVar29)))) ||
                    ((_Stack_780._Ptr)->IdleTime <= BZ1Helper::m_TurnCounter)) ||
                   ((((_Stack_780._Ptr)->DispatchType != 1 && ((_Stack_780._Ptr)->DispatchType != 6)
                     ) && ((byte)local_750 == '\0')))))) {
            if (cStack_779 != '\0') {
              memset(TempGetODFName,0,0x40);
              GetODFName((int)_Var45._Ptr,(char *)unaff_EDI);
              uStack_714 = *(undefined4 *)pvVar31;
              std::_Iterator_base0::_Adopt((_Iterator_base0 *)&uStack_714,pvVar31);
              FormatLogMessage("Index: %d Unit: \'%s\' Rearmed/Repaired, resuming duties");
            }
            SetIndependence((_Stack_780._Ptr)->DispatchObject,1);
            ClearDispatch((DispatchHelper *)local_73c._Ptr,(int)pvStack_768);
            _Var22._Ptr = _Stack_780._Ptr;
            iVar26 = SecondsToTurns(___real_41700000);
            (_Var22._Ptr)->IdleTime = iVar26 + BZ1Helper::m_TurnCounter;
            if (cStack_779 != '\0') {
              uStack_778 = *(float *)pvVar31;
              std::_Iterator_base0::_Adopt((_Iterator_base0 *)&uStack_778,pvVar31);
              pcVar44 = "Index is: %d Repair/Repaid finished, IdleTime: %d";
              goto LAB_4fc20e4b;
            }
          }
LAB_4fc22b69:
          _Var22._Ptr = _Stack_780._Ptr;
          (_Stack_780._Ptr)->ServiceTimer = (_Stack_780._Ptr)->ServiceTimer + -1;
          if ((_Stack_780._Ptr)->ServiceTimer < 0) {
            iVar26 = SecondsToTurns(__real_41200000);
            (_Var22._Ptr)->ServiceTimer = iVar26;
          }
          _Var22._Ptr = _Stack_780._Ptr;
          pvVar28 = pvStack_76c;
          if (((*(char *)((int)piStack_760 + 0x1ad) != '\0') &&
              ((_Stack_780._Ptr)->ServiceTimer < 1)) &&
             (((_Stack_780._Ptr)->DispatchState != 4 && ((_Stack_780._Ptr)->DispatchState != 3)))) {
            piVar36 = piStack_760;
            if (((_Stack_780._Ptr)->CanGetRepair != false) &&
               (fVar41 = GetHealth((_Stack_780._Ptr)->DispatchObject), piVar36 = piStack_760,
               fVar41 < (_Var22._Ptr)->GetRepairRatio)) {
              if ((((_Stack_780._Ptr)->DispatchType == 1) || ((_Stack_780._Ptr)->DispatchType == 6))
                 && (bVar25 = IsDeployed((_Stack_780._Ptr)->DispatchObject), bVar25)) {
                piVar36 = piStack_760;
                if (piStack_760[0x29] != 0) {
                  memset(acStack_94,0,0x40);
                  bVar25 = GetBuildItem(0,(char *)0x1,(int *)0x0,0,(char *)0x0,(char *)_Var45._Ptr,
                                        (char *)unaff_EDI);
                  piVar36 = piStack_760;
                  if ((bVar25) &&
                     (iVar26 = (*misnImport.GetScrap)((int)local_764), piVar36 = piStack_760,
                     -1 < iVar26)) {
                    VVar17.y = VStack_734.y;
                    VVar17.x = VStack_734.x;
                    VVar17.z = VStack_734.z;
                    BZ1Helper::BuildAt(local_754,piStack_760[0x29],acStack_94,VVar17,1);
                    fVar41 = ___real_42700000;
                    (_Stack_780._Ptr)->DispatchState = 4;
                    iVar26 = SecondsToTurns(fVar41);
                    if ((_Stack_780._Ptr)->IdleTime < iVar26 + BZ1Helper::m_TurnCounter) {
                      (_Stack_780._Ptr)->IdleTime = iVar26 + BZ1Helper::m_TurnCounter;
                    }
                    if (cStack_779 != '\0') {
                      uStack_774 = (double)CONCAT44(uStack_774._4_4_,*(int *)pvStack_76c);
                      std::_Iterator_base0::_Adopt((_Iterator_base0 *)&uStack_774,pvStack_76c);
                      FormatLogMessage(
                                      "Index is: %d Deployable Waiting for Repair Powerup to land, IdleTime: %d"
                                      );
                    }
                  }
                }
              }
              else {
                _Var22._Ptr = _Stack_780._Ptr;
                fVar41 = GetRandomFloat(1.0);
                piVar36 = piStack_760;
                if (fVar41 < (_Var22._Ptr)->ServiceChance) {
                  VVar2.y = VStack_734.y;
                  VVar2.x = VStack_734.x;
                  VVar2.z = VStack_734.z;
                  iVar26 = BuildingHelper::GetNearestServiceObject
                                     (BuildingHelper::m_BuildingHelper,1,VVar2,0.0,-1,0,true,true,
                                      true,0,0,(char *)0x0,(char *)0x0);
                  uStack_774 = (double)CONCAT44(uStack_774._4_4_,iVar26);
                  piVar36 = piStack_760;
                  if (iVar26 != 0) {
                    pvVar31 = pvStack_76c;
                    if (cStack_779 != '\0') {
                      memset(TempGetODFName,0,0x40);
                      GetODFName((int)_Var45._Ptr,(char *)unaff_EDI);
                      pvVar31 = pvStack_76c;
                      local_720 = *(int *)pvStack_76c;
                      std::_Iterator_base0::_Adopt((_Iterator_base0 *)&local_720,pvStack_76c);
                      FormatLogMessage("Index: %d Unit: \'%s\' going to get Repair");
                    }
                    *(DispatchClass **)&(_Stack_780._Ptr)->DispatchTarget =
                         (DispatchClass *)uStack_774;
                    Goto((_Stack_780._Ptr)->DispatchObject,
                         *(int *)&(_Stack_780._Ptr)->DispatchTarget,0);
                    SetIndependence((_Stack_780._Ptr)->DispatchObject,0);
                    _Var22._Ptr = _Stack_780._Ptr;
                    fVar41 = ___real_43960000;
                    (_Stack_780._Ptr)->DispatchState = 4;
                    iVar26 = SecondsToTurns(fVar41);
                    (_Var22._Ptr)->IdleTime = iVar26 + BZ1Helper::m_TurnCounter;
                    piVar36 = piStack_760;
                    if (cStack_779 != '\0') {
                      uStack_774 = (double)CONCAT44(uStack_774._4_4_,*(int *)pvVar31);
                      std::_Iterator_base0::_Adopt((_Iterator_base0 *)&uStack_774,pvVar31);
                      FormatLogMessage("Index is: %d Unit going to Repair Service, IdleTime: %d");
                      piVar36 = piStack_760;
                    }
                  }
                }
              }
            }
            pvVar28 = pvStack_76c;
            if (((_Stack_780._Ptr)->CanGetReload != false) &&
               (fVar41 = GetAmmo((_Stack_780._Ptr)->DispatchObject), _Var22._Ptr = _Stack_780._Ptr,
               pvVar28 = pvStack_76c, fVar41 < 1.0)) {
              lVar29 = GetMinFireAmmo((int)_Var45._Ptr);
              _Var23._Ptr = _Stack_780._Ptr;
              (_Var22._Ptr)->MinFireAmmo = lVar29;
              lVar29 = GetCurAmmo((_Stack_780._Ptr)->DispatchObject);
              pvVar28 = pvStack_76c;
              if (lVar29 < (_Var23._Ptr)->MinFireAmmo) {
                if ((((_Stack_780._Ptr)->DispatchType == 1) ||
                    ((_Stack_780._Ptr)->DispatchType == 6)) &&
                   (bVar25 = IsDeployed((_Stack_780._Ptr)->DispatchObject), bVar25)) {
                  pvVar28 = pvStack_76c;
                  if (piVar36[0x29] != 0) {
                    memset(acStack_54,0,0x40);
                    bVar25 = GetBuildItem(0,(char *)0x2,(int *)0x0,0,(char *)0x0,(char *)_Var45._Ptr
                                          ,(char *)unaff_EDI);
                    pvVar28 = pvStack_76c;
                    if ((bVar25) &&
                       (iVar26 = (*misnImport.GetScrap)((int)local_764), pvVar28 = pvStack_76c,
                       -1 < iVar26)) {
                      VVar18.y = VStack_734.y;
                      VVar18.x = VStack_734.x;
                      VVar18.z = VStack_734.z;
                      BZ1Helper::BuildAt(local_754,piStack_760[0x29],acStack_54,VVar18,1);
                      fVar41 = ___real_42700000;
                      (_Stack_780._Ptr)->DispatchState = 3;
                      iVar26 = SecondsToTurns(fVar41);
                      pvVar31 = pvStack_76c;
                      if ((_Stack_780._Ptr)->IdleTime < iVar26 + BZ1Helper::m_TurnCounter) {
                        (_Stack_780._Ptr)->IdleTime = iVar26 + BZ1Helper::m_TurnCounter;
                      }
                      pvVar28 = pvStack_76c;
                      if (cStack_779 != '\0') {
                        uStack_774 = (double)CONCAT44(uStack_774._4_4_,*(int *)pvStack_76c);
                        std::_Iterator_base0::_Adopt((_Iterator_base0 *)&uStack_774,pvStack_76c);
                        pcVar44 = 
                        "Index is: %d Deployable Waiting for Reload Powerup to land, IdleTime: %d";
                        goto LAB_4fc22fb1;
                      }
                    }
                  }
                }
                else {
                  VVar3.y = VStack_734.y;
                  VVar3.x = VStack_734.x;
                  VVar3.z = VStack_734.z;
                  iVar26 = BuildingHelper::GetNearestServiceObject
                                     (BuildingHelper::m_BuildingHelper,2,VVar3,0.0,-1,0,true,true,
                                      true,0,0,(char *)0x0,(char *)0x0);
                  uStack_774 = (double)CONCAT44(uStack_774._4_4_,iVar26);
                  pvVar28 = pvStack_76c;
                  if (iVar26 != 0) {
                    pvVar31 = pvStack_76c;
                    if (cStack_779 != '\0') {
                      memset(TempGetODFName,0,0x40);
                      GetODFName((int)_Var45._Ptr,(char *)unaff_EDI);
                      pvVar31 = pvStack_76c;
                      iStack_740 = *(int *)pvStack_76c;
                      std::_Iterator_base0::_Adopt((_Iterator_base0 *)&iStack_740,pvStack_76c);
                      FormatLogMessage("Index: %d Unit: \'%s\' going to get Reload");
                    }
                    *(DispatchClass **)&(_Stack_780._Ptr)->DispatchTarget =
                         (DispatchClass *)uStack_774;
                    Goto((_Stack_780._Ptr)->DispatchObject,
                         *(int *)&(_Stack_780._Ptr)->DispatchTarget,0);
                    SetIndependence((_Stack_780._Ptr)->DispatchObject,0);
                    _Var22._Ptr = _Stack_780._Ptr;
                    fVar41 = ___real_41f00000;
                    (_Stack_780._Ptr)->DispatchState = 3;
                    iVar26 = SecondsToTurns(fVar41);
                    (_Var22._Ptr)->IdleTime = iVar26 + BZ1Helper::m_TurnCounter;
                    pvVar28 = pvStack_76c;
                    if (cStack_779 != '\0') {
                      uStack_774 = (double)CONCAT44(uStack_774._4_4_,*(int *)pvVar31);
                      std::_Iterator_base0::_Adopt((_Iterator_base0 *)&uStack_774,pvVar31);
                      pcVar44 = "Index is: %d Unit going to Reload Service, IdleTime: %d";
LAB_4fc22fb1:
                      FormatLogMessage(pcVar44);
                      pvVar28 = pvVar31;
                    }
                  }
                }
              }
            }
          }
        }
        _Var22._Ptr = _Stack_780._Ptr;
        if ((_Stack_780._Ptr)->IsCloaker != false) {
          if ((_Stack_780._Ptr)->IsCloaked == false) {
            if ((_Stack_780._Ptr)->CloakNextTick == false) {
              if ((((_Stack_780._Ptr)->SkipAIPCheck != false) ||
                  (*(char *)((int)piStack_760 + 0x1ae) != '\0')) &&
                 (((((_Stack_780._Ptr)->CloakIdleTime <= BZ1Helper::m_TurnCounter ||
                    (AVar34 = GetCurrentCommand((_Stack_780._Ptr)->DispatchObject),
                    AVar34 != (_Var22._Ptr)->Command)) &&
                   ((iVar26 = GetPlayerHandle((int)local_764), iVar26 == 0 &&
                    (local_750._3_1_ == '\x01')))) && ((_Stack_780._Ptr)->CloakPriority == 0)))) {
                fVar41 = GetRandomFloat(1.0);
                dStack_74c = (double)CONCAT44(dStack_74c._4_4_,fVar41);
                iVar26 = (*misnImport.GetNearestEnemy)((_Stack_780._Ptr)->DispatchObject);
                uStack_774 = (double)CONCAT44(uStack_774._4_4_,iVar26);
                bVar25 = IsDeployed((_Stack_780._Ptr)->DispatchObject);
                if ((!bVar25) || ((_Stack_780._Ptr)->IsMorpher != false)) {
                  if ((DispatchClass *)uStack_774 != (DispatchClass *)0x0) {
                    GetPosition((int)(DispatchClass *)uStack_774,&VStack_570);
                    uStack_774 = (double)(_Stack_780._Ptr)->EngageRange;
                    fVar43 = GetDistance3DSquared((Vector *)_Var45._Ptr,unaff_EDI);
                    fVar41 = (float)((float10)uStack_774 * (float10)uStack_774);
                    uStack_774 = (double)CONCAT44(uStack_774._4_4_,fVar41);
                    if (fVar43 <= fVar41) goto LAB_4fc236d5;
                  }
                  if (cStack_779 == '\0') {
                    dStack_74c = (double)dStack_74c._0_4_;
                  }
                  else {
                    uStack_774 = (double)CONCAT44(uStack_774._4_4_,*(undefined4 *)pvVar28);
                    std::_Iterator_base0::_Adopt((_Iterator_base0 *)&uStack_774,pvVar28);
                    dStack_74c = (double)dStack_74c._0_4_;
                    FormatLogMessage(
                                    "Index: %d AI Attempting to Cloak unit, Chance: %f, CloakCommand: %d Chance: %f"
                                    );
                  }
                  _Var22._Ptr = _Stack_780._Ptr;
                  AVar34 = GetCurrentCommand((_Stack_780._Ptr)->DispatchObject);
                  if (dStack_74c < (double)(_Var22._Ptr)->CloakChance[AVar34]) {
                    if (cStack_779 != '\0') {
                      uStack_774 = (double)CONCAT44(uStack_774._4_4_,*(undefined4 *)pvVar28);
                      std::_Iterator_base0::_Adopt((_Iterator_base0 *)&uStack_774,pvVar28);
                      FormatLogMessage("Index: %d AI Cloak Successful");
                    }
                    Cloak((DispatchHelper *)local_73c._Ptr,(_Stack_780._Ptr)->DispatchObject,
                          (_Stack_780._Ptr)->CloakPriority);
                  }
                  _Var22._Ptr = _Stack_780._Ptr;
                  iVar26 = SecondsToTurns(___real_41700000);
                  (_Var22._Ptr)->CloakIdleTime = iVar26 + BZ1Helper::m_TurnCounter;
                }
              }
            }
            else {
              bVar25 = IsDeployed((_Stack_780._Ptr)->DispatchObject);
              if (!bVar25) {
                SetCommand((_Stack_780._Ptr)->DispatchObject,0x2f,0,0,(char *)0x0,0);
                _Var22._Ptr = _Stack_780._Ptr;
                iVar26 = SecondsToTurns((_Stack_780._Ptr)->TimeDeploy);
                (_Var22._Ptr)->DeployTimer = iVar26 + BZ1Helper::m_TurnCounter + 1;
                (_Stack_780._Ptr)->CloakLocked = true;
                if (cStack_779 != '\0') {
                  uStack_774 = (double)CONCAT44(uStack_774._4_4_,*(undefined4 *)pvVar28);
                  std::_Iterator_base0::_Adopt((_Iterator_base0 *)&uStack_774,pvVar28);
                  FormatLogMessage(
                                  "Index: %d Cloaking Activating, Time: %d, DeployTimer: %d, DeployTime: %f"
                                  );
                }
              }
              (_Stack_780._Ptr)->IsCloaked = true;
              (_Stack_780._Ptr)->CloakNextTick = false;
            }
          }
          else {
            bVar25 = IsDeployed((_Stack_780._Ptr)->DispatchObject);
            if (bVar25) {
              if ((_Stack_780._Ptr)->DecloakNextTick == false) {
                if (((local_750._3_1_ == '\x01') && ((_Stack_780._Ptr)->CloakPriority == 0)) &&
                   ((*misnImport.GetNearestEnemy)((_Stack_780._Ptr)->DispatchObject),
                   (_Stack_780._Ptr)->CloakLocked != false)) {
                  uStack_774 = (double)(_Stack_780._Ptr)->EngageRange;
                  fVar43 = GetDistance3DSquared((int)_Var45._Ptr,(int)unaff_EDI);
                  fVar41 = (float)((float10)uStack_774 * (float10)uStack_774);
                  uStack_774 = (double)CONCAT44(uStack_774._4_4_,fVar41);
                  if (fVar43 < fVar41) {
                    if (cStack_779 != '\0') {
                      uStack_774 = (double)CONCAT44(uStack_774._4_4_,*(undefined4 *)pvVar28);
                      std::_Iterator_base0::_Adopt((_Iterator_base0 *)&uStack_774,pvVar28);
                      FormatLogMessage("Index: %d Unit is Cloaked, Enemy detected, Unlocking Cloak")
                      ;
                    }
                    SetCommand((_Stack_780._Ptr)->DispatchObject,0x31,0,0,(char *)0x0,0);
                    (_Stack_780._Ptr)->CloakLocked = false;
                  }
                }
                AVar34 = GetCurrentCommand((_Stack_780._Ptr)->DispatchObject);
                if (AVar34 == CMD_ATTACK) {
                  GetPosition((int)_Stack_71c._Ptr,&VStack_564);
                  fVar41 = GetDistance3DSquared((Vector *)_Var45._Ptr,unaff_EDI);
                  uStack_774 = (double)fVar41;
                  pDVar32 = std::
                            _Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                            ::operator->((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                          *)&_Stack_780);
                  fVar41 = Squared<float>(pDVar32->EngageRange);
                  if ((float)uStack_774 < fVar41) {
                    if (cStack_779 != '\0') {
                      _Var45._Ptr = (DispatchClass *)auStack_634;
                      _Var27 = std::
                               vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
                               ::begin(pvVar28);
                      std::
                      _Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                      ::operator-((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                   *)&stack0xfffff87c,
                                  (_Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                   *)_Var27);
                      FormatLogMessage("Index: %d Unit is Cloaked, Target In Range, Decloaking");
                    }
                    std::
                    _Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                    ::operator->((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                  *)&_Stack_780);
                    pDVar32 = std::
                              _Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                              ::operator->((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                            *)&_Stack_780);
                    iVar26 = pDVar32->DispatchObject;
                    bVar25 = IsAround(iVar26);
                    if (bVar25) {
                      Decloak((DispatchHelper *)local_73c._Ptr,iVar26,(int)_Var45._Ptr);
                    }
                    pDVar32 = std::
                              _Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                              ::operator->((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                            *)&_Stack_780);
                    pDVar32->CloakLocked = false;
                  }
                }
              }
              else {
                SetCommand(0x4fc233e0,0x30,0,0,(char *)0x0,0);
                (_Stack_780._Ptr)->DecloakNextTick = false;
              }
            }
            else {
              pDVar32 = std::
                        _Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                        ::operator->((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                      *)&_Stack_780);
              if (pDVar32->DeployTimer < BZ1Helper::m_TurnCounter) {
                pDVar32 = std::
                          _Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                          ::operator->((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                        *)&_Stack_780);
                if (((pDVar32->SkipAIPCheck != false) ||
                    (pvVar31 = pvStack_76c, *(char *)((int)piStack_760 + 0x1ae) != '\0')) &&
                   (iVar26 = GetPlayerHandle((int)local_764), pvVar31 = pvStack_76c, iVar26 == 0)) {
                  pDVar32 = std::
                            _Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                            ::operator->((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                          *)&_Stack_780);
                  pDVar33 = std::
                            _Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                            ::operator->((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                          *)&_Stack_780);
                  AVar34 = GetCurrentCommand(pDVar32->DispatchObject);
                  pvVar31 = pvStack_76c;
                  if (AVar34 == pDVar33->Command) {
                    if (cStack_779 != '\0') {
                      _Var45._Ptr = (DispatchClass *)auStack_63c;
                      _Var27 = std::
                               vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
                               ::begin(pvStack_76c);
                      std::
                      _Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                      ::operator-((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                   *)&stack0xfffff87c,
                                  (_Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                   *)_Var27);
                      FormatLogMessage(
                                      "Index: %d Command Identicle, setting CloakIdle time for 15 seconds."
                                      );
                    }
                    iVar26 = SecondsToTurns(___real_41700000);
                    iVar26 = BZ1Helper::m_TurnCounter + iVar26;
                    pDVar32 = std::
                              _Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                              ::operator->((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                            *)&_Stack_780);
                    pDVar32->CloakIdleTime = iVar26;
                  }
                  else {
                    if (cStack_779 != '\0') {
                      _Var45._Ptr = (DispatchClass *)(auStack_63c + 4);
                      _Var27 = std::
                               vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
                               ::begin(pvStack_76c);
                      std::
                      _Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                      ::operator-((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                   *)&stack0xfffff87c,
                                  (_Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                   *)_Var27);
                      FormatLogMessage(
                                      "Index: %d Command Different, Setting CloakIdle time for NOW."
                                      );
                    }
                    pDVar32 = std::
                              _Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                              ::operator->((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                            *)&_Stack_780);
                    pDVar32->CloakIdleTime = BZ1Helper::m_TurnCounter;
                  }
                }
                pDVar32 = std::
                          _Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                          ::operator->((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                        *)&_Stack_780);
                pDVar32->IsCloaked = false;
                if (cStack_779 != '\0') {
                  std::
                  _Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                  ::operator->((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                *)&_Stack_780);
                  std::
                  _Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                  ::operator->((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                *)&_Stack_780);
                  _Var27 = std::
                           vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
                           ::begin(pvVar31);
                  std::
                  _Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                  ::operator-((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                               *)&stack0xfffff87c,
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
LAB_4fc236d5:
        pDVar32 = std::
                  _Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                  ::operator->((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                *)&_Stack_780);
        pDVar33 = std::
                  _Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                  ::operator->((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                *)&_Stack_780);
        AVar34 = GetCurrentCommand(pDVar32->DispatchObject);
        pvVar31 = pvStack_76c;
        if (AVar34 != pDVar33->Command) {
          pDVar32 = std::
                    _Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                    ::operator->((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                  *)&_Stack_780);
          AVar34 = GetCurrentCommand(pDVar32->DispatchObject);
          pDVar32 = std::
                    _Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                    ::operator->((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                  *)&_Stack_780);
          pDVar32->Command = AVar34;
          pvVar31 = pvStack_76c;
        }
      }
      _Stack_780._Ptr = _Stack_780._Ptr + 1;
      std::
      _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
      ::
      _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                (&local_738,*(DispatchClass **)&pvVar31->field_0x4,(_Container_base0 *)pvVar31);
    } while (_Stack_780._Ptr != local_738._Ptr);
  }
  return;
}


// ---------------------------------------------------------------------
// DispatchHelper::PreOrdnanceHit  @ 4fc2375b  lines 1860-1939


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
  if (iVar3 != 0) {
    for (piVar5 = *(int **)&this->DispatchList; piVar5 != *(int **)&(this->DispatchList).field_0x4;
        piVar5 = piVar5 + 0x52) {
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
            piVar5[0xc] = iVar3 + BZ1Helper::m_TurnCounter;
            pbVar8 = (bool *)*piVar5;
            iVar3 = GetTarget((int)pbVar8);
            piVar5[2] = iVar3;
            param_2 = param_2 & 0xffffff00;
            GetODFBool(0x4fc60d24,(char *)&param_2,(char *)0x0,pbVar8,(bool)uVar9);
            if ((piVar5[2] == 0) && ((char)param_2 != '\0')) {
              piVar5[2] = param_1;
            }
            SetIndependence(*piVar5,0);
            GetPositionNearOrFar
                      ((Vector *)param_1,__real_42200000,___real_42960000,0.0,unaff_EBX,
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
    }
  }
  return;
}


// ---------------------------------------------------------------------
// DispatchHelper::ReadChanceValues  @ 4fc23a2b  lines 1942-1948


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
      GetODFFloat(param_1,param_2,*ppcVar2,(float *)((int)(param_3 + -0x13f1b808) + (int)ppcVar2),
                  param_4);
      ppcVar2 = ppcVar2 + 1;
    } while ((int)ppcVar2 < 0x4fc6e0f8);
  }
  return;
}


// ---------------------------------------------------------------------
// DispatchHelper::Cloak  @ 4fc23a78  lines 1952-2027


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
          if (!bVar2) {
            return;
          }
          FormatLogMessage("Cloak Command Given, Time: %d");
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
// DispatchHelper::Decloak  @ 4fc23b5d  lines 2029-2076


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
    if (!bVar1) {
      return;
    }
    Deploy(param_1);
    return;
  }
  *(undefined1 *)((int)piVar4 + 0x2e) = 1;
  return;
}


// ---------------------------------------------------------------------
// DispatchHelper::ClearDispatch  @ 4fc23bee  lines 2174-2183


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

