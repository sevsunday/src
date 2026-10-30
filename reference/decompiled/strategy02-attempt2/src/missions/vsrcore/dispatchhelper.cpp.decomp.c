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
  this->vfptr = (int)vftable;
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
  int iVar3;
  int iVar4;
  int *piVar5;
  
  piVar5 = *(int **)&this->DispatchList;
  if (piVar5 != *(int **)&(this->DispatchList).field_0x4) {
    do {
      ConvertHandles(piVar5,1);
      ConvertHandles(piVar5 + 1,1);
      ConvertHandles(piVar5 + 2,1);
      piVar5 = piVar5 + 0x52;
    } while (piVar5 != *(int **)&(this->DispatchList).field_0x4);
  }
  iVar4 = *(int *)&this->DispatchList;
  iVar2 = (*(int *)&(this->DispatchList).field_0x4 - iVar4) / 0x148;
  iVar3 = (int)(TempDispatchBuffer._4_4_ - TempDispatchBuffer._0_4_) / 0x148;
  if (iVar3 == iVar2) {
    iVar3 = 0;
    if (0 < iVar2) {
      iVar2 = 0;
      do {
        bVar1 = ::operator==((DispatchClass *)(iVar2 + TempDispatchBuffer._0_4_),
                             (DispatchClass *)(iVar2 + iVar4));
        if (!bVar1) {
          FormatLogMessage("DispatchList Index Mismatch: %d",iVar3);
          return true;
        }
        iVar4 = *(int *)&this->DispatchList;
        iVar3 = iVar3 + 1;
        iVar2 = iVar2 + 0x148;
      } while (iVar3 < (*(int *)&(this->DispatchList).field_0x4 - iVar4) / 0x148);
    }
  }
  else {
    FormatLogMessage("DispatchList Size Mismatch! Old: %d New: %d",iVar3,iVar2);
  }
  return true;
}


// ---------------------------------------------------------------------
// DispatchHelper::AddToDispatch  @ 4fc1fef3  lines 91-368

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool __thiscall
DispatchHelper::AddToDispatch
          (DispatchHelper *this,int h,float IdleTime,bool SkipAIPCheck,int CloakPriority,
          bool CanFlee,bool CloakNow,bool Hunt,bool CanGetService)

{
  vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
  *_Udefault_or_fill;
  bool *value;
  DispatchHelper *pDVar1;
  bool bVar2;
  char cVar3;
  uint uVar4;
  char *pcVar5;
  int iVar6;
  long lVar7;
  DispatchHelper *this_00;
  uint unaff_ESI;
  char *unaff_EDI;
  int *piVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  char *_Format;
  undefined1 auStack_180 [2];
  bool local_17e;
  bool local_17d;
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
  char local_104 [64];
  char local_c4 [64];
  char local_84 [64];
  char local_44 [64];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)auStack_180;
  local_154 = h;
  local_15c = this;
  memset(local_44,0,0x40);
  bVar2 = GetObjInfo(h,Get_GOClass,local_44);
  if (!bVar2) {
    return false;
  }
  uVar4 = Hash(unaff_EDI,unaff_ESI);
  local_158 = uVar4;
  memset(local_c4,0,0x40);
  memset(local_104,0,0x40);
  GetAndOpenODFNames(h,local_c4,local_104,(char *)0x0);
  local_17e = true;
  GetODFBool(local_c4,local_104,"CraftClass","DoDLLDispatch",&local_17e,true);
  if (local_17e == false) {
    return false;
  }
  pcVar5 = GetLabel(h);
  local_150 = pcVar5;
  if ((pcVar5 != (char *)0x0) && (iVar6 = _strnicmp(pcVar5,"nodispatch",10), iVar6 == 0)) {
    return false;
  }
  memset(local_84,0,0x40);
  GetODFString(local_c4,local_104,"GameObjectClass","BZCClasslabel",0x40,local_84,(char *)0x0);
  local_14c = Hash(unaff_EDI,unaff_ESI);
  pDVar1 = local_15c;
  if ((((((uVar4 != 0x4de8a34) && (uVar4 != 0x1c628d2e)) && (uVar4 != 0x83416d25)) &&
       ((uVar4 != 0xc864a6ef && (uVar4 != 0x1aefd513)))) &&
      ((uVar4 != 0xa7275daa && ((uVar4 != 0x4a7aef92 && (uVar4 != 0x32493554)))))) &&
     ((uVar4 != 0xedb121ba && ((uVar4 != 0xf9df4e76 && (uVar4 != 0x25fd9ee0)))))) {
    return false;
  }
  if (local_14c == 0x326aa115) {
    return false;
  }
  _Udefault_or_fill = &local_15c->DispatchList;
  for (piVar8 = *(int **)_Udefault_or_fill; piVar8 != *(int **)&(local_15c->DispatchList).field_0x4;
      piVar8 = piVar8 + 0x52) {
    if (*piVar8 == h) {
      return false;
    }
  }
  std::
  vector<MorphObjectHelper::MorphObjectClass,std::allocator<MorphObjectHelper::MorphObjectClass>_>::
  _Resize<<lambda_6e1c0ab678e9364d699d8dd7ba7d9fb6>_>
            ((vector<MorphObjectHelper::MorphObjectClass,std::allocator<MorphObjectHelper::MorphObjectClass>_>
              *)_Udefault_or_fill,
             (*(int *)&(local_15c->DispatchList).field_0x4 - *(int *)_Udefault_or_fill) / 0x148 + 1,
             (<lambda_6e1c0ab678e9364d699d8dd7ba7d9fb6>)_Udefault_or_fill);
  piVar8 = (int *)(*(int *)_Udefault_or_fill + -0x148 +
                  ((*(int *)&(pDVar1->DispatchList).field_0x4 - *(int *)_Udefault_or_fill) / 0x148)
                  * 0x148);
  memset(piVar8,0,0x148);
  local_16c = GetConfigODF(h);
  *(bool *)(piVar8 + 9) = SkipAIPCheck;
  lVar7 = GetMaxHealth(h);
  piVar8[0x4d] = lVar7;
  lVar7 = GetMaxAmmo(h);
  piVar8[0x4e] = lVar7;
  local_148 = GetTeamNum(h);
  local_164 = local_148 * 0xa14;
  local_17d = true;
  local_174 = 0.0;
  local_17c = 0.0;
  local_170 = 0.0;
  local_160 = BZ1Helper::m_BZ1Helper;
  local_178 = 0.0;
  fVar9 = 0.0;
  fVar10 = 0.0;
  fVar11 = 0.0;
  fVar12 = 0.0;
  if (local_16c != (char *)0x0) {
    bVar2 = OpenODF2(local_16c);
    if (bVar2) {
      memset(local_144,0,0x40);
      pcVar5 = local_16c;
      local_168 = 5;
      do {
        iVar6 = *(int *)((int)local_160->teamInfo[0].LimiterObject + local_164 + 0x18);
        if (iVar6 == 1) {
          _Format = "EasyWeaponSlot%d";
LAB_4fc20205:
          sprintf_s<64>(&local_144,_Format);
        }
        else {
          if (iVar6 == 2) {
            _Format = "MediumWeaponSlot%d";
            goto LAB_4fc20205;
          }
          if (iVar6 == 3) {
            _Format = "HardWeaponSlot%d";
            goto LAB_4fc20205;
          }
          if (iVar6 == 4) {
            _Format = "ExtremeWeaponSlot%d";
            goto LAB_4fc20205;
          }
        }
        GetODFFloat(pcVar5,local_144,"AIHuntChance",&local_174,0.0);
        GetODFFloat(pcVar5,local_144,"AIPatrolChance",&local_17c,0.0);
        GetODFFloat(pcVar5,local_144,"AISniperChance",&local_170,0.0);
        GetODFFloat(pcVar5,local_144,"AIEscortChance",&local_178,0.0);
        GetODFFloat(pcVar5,local_144,"AIRepairHealthRatio",(float *)(piVar8 + 0x4a),0.15);
        GetODFFloat(pcVar5,local_144,"AIServiceChance",(float *)(piVar8 + 0x4b),0.0);
        local_168 = local_168 + -1;
      } while (local_168 != 0);
      ReadChanceValues(this_00,local_16c,"CloakChances",(float *)(piVar8 + 0x13),0.0);
      h = local_154;
      pcVar5 = local_150;
      uVar4 = local_158;
    }
    fVar9 = local_17c;
    fVar10 = local_170;
    fVar11 = local_178;
    if (0.0 <= local_174) {
      fVar12 = local_174;
      if (1.0 < local_174) {
        fVar12 = 1.0;
      }
    }
    else {
      fVar12 = 0.0;
    }
  }
  if (0.0 <= fVar9) {
    if (1.0 < fVar9) {
      fVar9 = 1.0;
    }
  }
  else {
    fVar9 = 0.0;
  }
  if (0.0 <= fVar10) {
    if (1.0 < fVar10) {
      fVar10 = 1.0;
    }
  }
  else {
    fVar10 = 0.0;
  }
  if (0.0 <= fVar11) {
    if (1.0 < fVar11) {
      fVar11 = 1.0;
    }
  }
  else {
    fVar11 = 0.0;
  }
  local_17c = fVar9;
  local_178 = fVar11;
  local_174 = fVar12;
  local_170 = fVar10;
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
  if (!Hunt) {
    if (pcVar5 == (char *)0x0) {
LAB_4fc2042d:
      iVar6 = GetRandomInt(0,2);
      if (iVar6 == 0) {
        fVar9 = GetRandomFloat(1.0);
        if (fVar9 < local_174) goto LAB_4fc204db;
        fVar9 = GetRandomFloat(1.0);
        if (local_17c <= fVar9) {
LAB_4fc20512:
          fVar9 = GetRandomFloat(1.0);
          if (local_178 <= fVar9) goto LAB_4fc20535;
          goto LAB_4fc20467;
        }
      }
      else if (iVar6 == 1) {
        fVar9 = GetRandomFloat(1.0);
        if (local_17c <= fVar9) {
          fVar9 = GetRandomFloat(1.0);
          if (local_174 <= fVar9) goto LAB_4fc20512;
          goto LAB_4fc204db;
        }
      }
      else {
        if (iVar6 != 2) goto LAB_4fc20535;
        fVar9 = GetRandomFloat(1.0);
        if (fVar9 < local_178) goto LAB_4fc20467;
        fVar9 = GetRandomFloat(1.0);
        if (fVar9 < local_174) goto LAB_4fc204db;
        fVar9 = GetRandomFloat(1.0);
        if (local_17c <= fVar9) goto LAB_4fc20535;
      }
      piVar8[7] = 2;
      goto LAB_4fc20535;
    }
    iVar6 = _strnicmp(pcVar5,"hunter",6);
    if (iVar6 != 0) {
      iVar6 = _strnicmp(pcVar5,"patrol",6);
      if (iVar6 == 0) {
        piVar8[7] = 2;
        goto LAB_4fc20535;
      }
      iVar6 = _strnicmp(pcVar5,"escort",6);
      if (iVar6 != 0) goto LAB_4fc2042d;
LAB_4fc20467:
      piVar8[7] = 5;
      goto LAB_4fc20535;
    }
  }
LAB_4fc204db:
  piVar8[7] = 4;
LAB_4fc20535:
  fVar9 = GetRandomFloat(1.0);
  if (fVar9 < local_170) {
    memset(local_144,0,0x40);
    cVar3 = GetRace(h);
    sprintf_s<64>(&local_144,"%csuser",(int)cVar3);
    SetPilotClass(h,local_144);
  }
  value = (bool *)((int)piVar8 + 0x25);
  GetODFBool(local_c4,local_104,"MorphTankClass","HiddenWhenMorphed",value,false);
  GetODFBool(local_c4,local_104,"CraftClass","CanAICloak",&local_17d,*value);
  if (local_17d == false) {
    *value = false;
  }
  GetODFFloat(local_c4,local_104,"DeployableClass","timeDeploy",(float *)(piVar8 + 0x12),5.0);
  if ((((uVar4 == 0x83416d25) || (uVar4 == 0x1c628d2e)) || (uVar4 == 0xc864a6ef)) ||
     (uVar4 == 0x4de8a34)) {
    GetODFBool(local_c4,local_104,"CraftClass","CanAIFlee",(bool *)((int)piVar8 + 0x27),CanFlee);
    if (*(bool *)((int)piVar8 + 0x27) != false) {
      GetODFFloat(local_c4,local_104,"CraftClass","AIFleeHealthRatio",(float *)(piVar8 + 0x49),0.75)
      ;
    }
  }
  else {
    *(undefined1 *)((int)piVar8 + 0x27) = 0;
  }
  if ((local_160->teamInfo[0].BaseSlotUseScrapHold[local_164 + 9] != false) || (CanGetService)) {
    GetODFBool(local_c4,local_104,"CraftClass","CanAIRepair",(bool *)((int)piVar8 + 0x29),
               piVar8[0x4d] != 0);
    GetODFBool(local_c4,local_104,"CraftClass","CanAIReload",(bool *)(piVar8 + 10),piVar8[0x4e] != 0
              );
  }
  iVar6 = _stricmp(local_84,"morphobject");
  if (iVar6 == 0) {
    *(undefined1 *)((int)piVar8 + 0x26) = 1;
    GetODFBool(local_c4,local_104,"MorphObjectClass","MorphIsAssault",(bool *)((int)piVar8 + 0x2a),
               true);
  }
  fVar9 = (float)piVar8[0x4a];
  if (0.0 <= fVar9) {
    if (1.0 < fVar9) {
      fVar9 = 1.0;
    }
  }
  else {
    fVar9 = 0.0;
  }
  piVar8[0x4a] = (int)fVar9;
  fVar9 = (float)piVar8[0x4b];
  fVar10 = 0.0;
  if ((0.0 <= fVar9) && (fVar10 = fVar9, 1.0 < fVar9)) {
    fVar10 = 1.0;
  }
  piVar8[0x4b] = (int)fVar10;
  *piVar8 = h;
  lVar7 = GetCurHealth(h);
  piVar8[0x50] = lVar7;
  fVar9 = GetEngageRange(h);
  piVar8[0x11] = (int)fVar9;
  iVar6 = SecondsToTurns(IdleTime);
  piVar8[0xc] = iVar6 + BZ1Helper::m_TurnCounter;
  iVar6 = SecondsToTurns(10.0);
  piVar8[0xf] = iVar6;
  piVar8[0x51] = CloakPriority;
  piVar8[6] = local_148;
  if (*value != false) {
    if (CloakNow) {
      Cloak(local_15c,h,CloakPriority);
    }
    else {
      iVar6 = SecondsToTurns(IdleTime);
      piVar8[0xd] = iVar6 + BZ1Helper::m_TurnCounter;
    }
  }
  return true;
}


// ---------------------------------------------------------------------
// DispatchHelper::DeleteDispatchObject  @ 4fc2084b  lines 371-394

void __thiscall DispatchHelper::DeleteDispatchObject(DispatchHelper *this,int h,int Team)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = *(int **)&this->DispatchList;
  if (piVar2 != *(int **)&(this->DispatchList).field_0x4) {
    do {
      if (*piVar2 == h) {
        iVar1 = piVar2[7];
        if (iVar1 == 2) {
          piVar2 = &BZ1Helper::m_BZ1Helper->teamInfo[Team].m_CPUNumPatrolUnits;
          *piVar2 = *piVar2 + -1;
          return;
        }
        if (iVar1 != 4) {
          if (iVar1 != 5) {
            return;
          }
          piVar2 = &BZ1Helper::m_BZ1Helper->teamInfo[Team].m_CPUNumEscortUnits;
          *piVar2 = *piVar2 + -1;
          return;
        }
        piVar2 = &BZ1Helper::m_BZ1Helper->teamInfo[Team].m_CPUNumHuntUnits;
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

void __thiscall DispatchHelper::Execute(DispatchHelper *this,BZ1Helper *bz1Helper)

{
  float fVar1;
  double dVar2;
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
  Vector VVar22;
  _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
  _Var23;
  _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
  _Var24;
  BZ1Helper *pBVar25;
  bool bVar26;
  int iVar27;
  _Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_> _Var28;
  vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_> *pvVar29;
  long lVar30;
  Vector *pVVar31;
  vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_> *pvVar32;
  int iVar33;
  DispatchClass *pDVar34;
  DispatchClass *pDVar35;
  AiCommand AVar36;
  int iVar37;
  _Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_> unaff_ESI;
  int *piVar38;
  float *pfVar39;
  undefined4 *puVar40;
  _func___cdecl_bool_DispatchClass_ptr *unaff_EDI;
  BZ1Helper *pBVar41;
  vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_> **ppvVar42;
  DLLBase *pDVar43;
  float10 extraout_ST0;
  float fVar44;
  vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_> *pvVar45;
  float fVar46;
  undefined1 *fmtarg2;
  char *pcVar47;
  int fmtarg2_00;
  double dVar48;
  _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
  _Last;
  _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
  _Stack_780;
  char cStack_779;
  undefined4 uStack_778;
  undefined8 uStack_774;
  vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_> *pvStack_76c;
  vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_> *pvStack_768;
  float *local_764;
  DLLBase *pDStack_760;
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
  int iStack_718;
  int iStack_714;
  undefined4 uStack_710;
  int iStack_70c;
  int iStack_708;
  int iStack_704;
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
  _Stack_6c0;
  undefined1 auStack_6bc [4];
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
  Vector aVStack_c0 [3];
  char acStack_94 [4];
  char local_90 [60];
  char acStack_54 [72];
  uint local_c;
  
  local_c = __security_cookie ^ (uint)&_Stack_780;
  local_750 = bz1Helper;
  uStack_778 = (float)CONCAT13(BZ1Helper::Logging,(undefined3)uStack_778);
  local_738._Ptr = (DispatchClass *)this;
  local_724 = ObjectHelper::GetNumHandles(bz1Helper->m_ObjectHelper);
  local_720 = BuildingHelper::GetNumBuildingObjects(BuildingHelper::m_BuildingHelper);
  pfVar39 = &bz1Helper->teamInfo[0].m_CPUDayWreckerChance;
  local_754 = (BZ1Helper *)0x0;
  do {
    pBVar41 = local_754;
    if ((((*pfVar39 != 0.0) && (*(char *)((int)pfVar39 + 0xc5) != '\0')) && (pfVar39[-0x45] != 0.0))
       && ((local_764 = pfVar39, iVar27 = SecondsToTurns(pfVar39[1]),
           BZ1Helper::m_TurnCounter % iVar27 == 0 &&
           (local_73c._Ptr = (DispatchClass *)GetRandomFloat(1.0), (float)local_73c._Ptr < *pfVar39)
           ))) {
      memset(local_90,0,0x40);
      bVar26 = GetBuildItem(0,(char *)0x4,(int *)"daywrecker",0,(char *)0x0,(char *)unaff_EDI,
                            (char *)unaff_ESI);
      if (((bVar26) &&
          ((iVar27 = (*misnImport.GetScrap)((int)pBVar41), -1 < iVar27 &&
           (bVar26 = DoesODFExist(local_90), bVar26)))) &&
         (iVar27 = BuildingHelper::GetNumBuildings
                             (BuildingHelper::m_BuildingHelper,(int)pBVar41,4,false,true,false,0,
                              (char *)0x0,(char *)0x0), pBVar25 = local_754, 0 < iVar27)) {
        fStack_6f4 = 0.0;
        fStack_6f0 = 0.0;
        auStack_6ec._0_4_ = 0.0;
        iVar27 = BuildingHelper::GetRandomBuilding
                           (BuildingHelper::m_BuildingHelper,(int)local_754,4,true,true,true,0,
                            (char *)0x0,(char *)0x0,0.0,(Vector)ZEXT812(0));
        GetPosition(iVar27,(Vector *)(auStack_6ec + 4));
        VStack_734.x = 0.0;
        pfVar39 = local_764;
        pBVar41 = pBVar25;
        if (0 < local_724) {
          iVar27 = 0;
          do {
            iVar37 = *(int *)&local_750->m_ObjectHelper->HandleList + iVar27;
            if ((BZ1Helper *)*(int *)(iVar37 + 0x1c) == pBVar25) {
              local_73c._Ptr = *(DispatchClass **)(iVar37 + 0x24);
              uStack_6b8 = (double)(float)local_73c._Ptr;
              fVar44 = GetDistance3DSquared((Vector *)(iVar37 + 0x48),(Vector *)(auStack_6ec + 4));
              pfVar39 = local_764;
              local_73c._Ptr = (DispatchClass *)(float)((float10)uStack_6b8 * (float10)uStack_6b8);
              if (fVar44 < (float)local_73c._Ptr) {
                VVar20.y = fStack_6e4;
                VVar20.x = (float)auStack_6ec._4_4_;
                VVar20.z = (float)_Stack_6e0._Ptr;
                BZ1Helper::BuildAt(local_750,(int)local_764[-0x45],local_90,VVar20,1);
                pBVar41 = local_754;
                break;
              }
            }
            VStack_734.x = (float)((int)&((Vector *)VStack_734.x)->x + 1);
            iVar27 = iVar27 + 0x5c;
            pfVar39 = local_764;
          } while ((int)VStack_734.x < local_724);
        }
      }
    }
    _Var23._Ptr = local_738._Ptr;
    local_754 = (BZ1Helper *)((int)pBVar41 + 1);
    pfVar39 = pfVar39 + 0x285;
  } while ((int)local_754 < 0x10);
  pvVar32 = (vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_> *)
            &(local_738._Ptr)->DispatchTarget;
  pvStack_768 = pvVar32;
  local_764 = pfVar39;
  std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
  ::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
            (&local_73c,(DispatchClass *)(local_738._Ptr)->FleeTarget,(_Container_base0 *)pvVar32);
  _Last._Ptr = local_73c._Ptr;
  std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
  ::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
            (&_Stack_71c,(DispatchClass *)(_Var23._Ptr)->FleeTarget,(_Container_base0 *)pvVar32);
  std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
  ::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
            ((_Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
              *)((int)&uStack_774 + 4),*(DispatchClass **)pvVar32,(_Container_base0 *)pvVar32);
  _Var28 = std::
           remove_if<std::_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>,bool_(__cdecl*)(DispatchHelper::DispatchClass_const_&)>
                     (uStack_774._4_4_,
                      (_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                       )_Stack_71c._Ptr,unaff_EDI);
  std::vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>::erase
            (pvVar32,*(DispatchClass **)_Var28,_Last);
  std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
  ::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
            (&_Stack_780,*(DispatchClass **)pvVar32,(_Container_base0 *)pvVar32);
  std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
  ::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
            (&local_738,(DispatchClass *)(_Var23._Ptr)->FleeTarget,(_Container_base0 *)pvVar32);
  if (_Stack_780._Ptr != local_738._Ptr) {
    do {
      std::
      _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
      ::
      _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                (&_Stack_6c4,*(DispatchClass **)pvVar32,(_Container_base0 *)pvVar32);
      pvVar29 = (vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
                 *)(((int)_Stack_780._Ptr - (int)_Stack_6c4._Ptr) / 0x148);
      pvStack_768 = pvVar29;
      local_764 = (float *)GetTeamNum((_Stack_780._Ptr)->DispatchObject);
      pDStack_760 = &local_754->super_DLLBase + (int)local_764 * 0x285;
      GetPosition((_Stack_780._Ptr)->DispatchObject,&VStack_734);
      bVar26 = IsAround(*(int *)&(_Stack_780._Ptr)->DispatchTarget);
      local_750 = (BZ1Helper *)CONCAT31(local_750._1_3_,bVar26);
      iVar27 = GetIndependence((_Stack_780._Ptr)->DispatchObject);
      local_750 = (BZ1Helper *)CONCAT13(iVar27 != 0,(uint3)local_750);
      _Stack_71c._Ptr = (DispatchClass *)GetCurrentWho((_Stack_780._Ptr)->DispatchObject);
      pfVar39 = (float *)(_Stack_780._Ptr)->CurrTeam;
      if (pfVar39 != local_764) {
        iVar27 = (_Stack_780._Ptr)->DispatchType;
        if (iVar27 == 2) {
          piVar38 = &local_754->teamInfo[(int)pfVar39].m_CPUNumPatrolUnits;
          *piVar38 = *piVar38 + -1;
          pDStack_760[0x4f] = (DLLBase)(*(int *)(pDStack_760 + 0x4f) + 1);
        }
        else if (iVar27 == 4) {
          piVar38 = &local_754->teamInfo[(int)pfVar39].m_CPUNumHuntUnits;
          *piVar38 = *piVar38 + -1;
          pDStack_760[0x50] = (DLLBase)(*(int *)(pDStack_760 + 0x50) + 1);
        }
        else if (iVar27 == 5) {
          piVar38 = &local_754->teamInfo[(int)pfVar39].m_CPUNumEscortUnits;
          *piVar38 = *piVar38 + -1;
          pDStack_760[0x51] = (DLLBase)(*(int *)(pDStack_760 + 0x51) + 1);
        }
        ClearDispatch((DispatchHelper *)local_73c._Ptr,(int)pvVar29);
        (_Stack_780._Ptr)->CurrTeam = (int)local_764;
      }
      pfVar39 = local_764;
      bVar26 = IsPlayer((_Stack_780._Ptr)->DispatchObject);
      if (!bVar26) {
        iVar27 = GetPlayerHandle((int)pfVar39);
        _Var23._Ptr = _Stack_780._Ptr;
        pvVar29 = pvStack_76c;
        if ((iVar27 == 0) &&
           ((local_750._3_1_ == '\x01' || ((_Stack_780._Ptr)->DispatchState == 2)))) {
          iVar27 = (_Stack_780._Ptr)->DispatchState;
          if (iVar27 == 0) {
            if ((((_Stack_780._Ptr)->IdleTime <= BZ1Helper::m_TurnCounter) &&
                (bVar26 = IsIdle((_Stack_780._Ptr)->DispatchObject), pfVar39 = local_764,
                _Var23._Ptr = _Stack_780._Ptr, bVar26)) &&
               (((_Stack_780._Ptr)->SkipAIPCheck != false ||
                (*(bool *)((int)(pDStack_760 + 0x6b) + 2) != false)))) {
              iVar27 = (_Stack_780._Ptr)->DispatchType;
              if (iVar27 == 1) {
                iVar27 = (*misnImport.GetNearestEnemy)((_Stack_780._Ptr)->DispatchObject);
                GetPosition(iVar27,&VStack_5dc);
                uStack_774 = (double)((_Stack_780._Ptr)->EngageRange + 50.0);
                fVar46 = GetDistance2DSquared<Vector,Vector>(&VStack_734,&VStack_5dc);
                fVar44 = (float)((float10)uStack_774 * (float10)uStack_774);
                uStack_774 = (double)CONCAT44(uStack_774._4_4_,fVar44);
                if (fVar44 < fVar46) {
                  iVar27 = GetRandomInt(0,2);
                  dStack_74c = (double)CONCAT44(dStack_74c._4_4_,iVar27);
                  iStack_758 = GetRandomInt(0,2);
                  *(undefined4 *)&(_Stack_780._Ptr)->DispatchTarget = 0;
                  pvStack_75c = (vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
                                 *)0x0;
                  fVar44 = (float)GetRandomTeam(1,1,SUB41(_Last._Ptr,0),SUB41(unaff_EDI,0));
                  if ((int)fVar44 < 0) {
                    fVar44 = (float)GetRandomTeam(0,1,SUB41(_Last._Ptr,0),SUB41(unaff_EDI,0));
                  }
                  uStack_778 = 0.0;
                  if (-1 < (int)fVar44) {
                    uStack_778 = fVar44;
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
                              (&_Stack_6e0,*(DispatchClass **)pvVar32,(_Container_base0 *)pvVar32);
                    FormatLogMessage("Index is: %d, DispatchMode is: %d, DispatchMethod is: %d, RandomTargetTeam: %d"
                                     ,((int)_Stack_780._Ptr - (int)_Stack_6e0._Ptr) / 0x148,
                                     (int)dStack_74c._0_4_,iStack_758,(int)uStack_778);
                  }
                  pvVar32 = (vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
                             *)local_754->teamInfo[(int)uStack_778].Recycler;
                  pvVar29 = (vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
                             *)0x0;
                  if ((((pvVar32 !=
                         (vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
                          *)0x0) ||
                       (pvVar32 = (vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
                                   *)local_754->teamInfo[(int)uStack_778].Factory,
                       pvVar32 !=
                       (vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
                        *)0x0)) ||
                      ((pvVar32 = (vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
                                   *)local_754->teamInfo[(int)uStack_778].Constructor,
                       pvVar32 !=
                       (vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
                        *)0x0 || (pvVar32 = (vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
                                             *)local_754->teamInfo[(int)uStack_778].Armory,
                                 pvVar32 !=
                                 (vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
                                  *)0x0)))) &&
                     (pvStack_768 = pvVar32,
                     pvVar32 !=
                     (vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
                      *)0x0)) {
                    GetPosition((int)pvVar32,&VStack_5d0);
                    pVStack_6f8 = (Vector *)VStack_5d0.x;
                    fStack_6f4 = VStack_5d0.y;
                    fStack_6f0 = VStack_5d0.z;
                    pvVar29 = pvStack_75c;
                  }
                  pvVar32 = pvStack_768;
                  if (dStack_74c._0_4_ == (char *)0x0) {
                    pvStack_768 = (vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
                                   *)0x0;
                    if (iStack_758 == 0) {
                      if (0 < local_724) {
                        dStack_74c = (double)CONCAT44(dStack_74c._4_4_,local_724);
                        uStack_778 = 0.0;
                        do {
                          if ((local_724 < 2) || (fVar44 = GetRandomFloat(1.0), fVar44 < 0.5)) {
                            puVar40 = (undefined4 *)
                                      (*(int *)&BuildingHelper::m_BuildingHelper->BuildingList +
                                      (int)uStack_778);
                            ppvVar42 = apvStack_4ec;
                            for (iVar27 = 0x116; pvVar32 = apvStack_4ec[0], iVar27 != 0;
                                iVar27 = iVar27 + -1) {
                              *ppvVar42 = (vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
                                           *)*puVar40;
                              puVar40 = puVar40 + 1;
                              ppvVar42 = ppvVar42 + 1;
                            }
                            pvVar29 = pvStack_75c;
                            if (((pfStack_264 == local_764) && (cStack_2b4 != '\0')) &&
                               (0 < iStack_25c)) {
                              pvVar45 = (vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
                                         *)GetDistance2DSquared<Vector,Vector>
                                                     (&VStack_734,aVStack_c0);
                              uStack_774 = (double)CONCAT44(uStack_774._4_4_,pvVar45);
                              pvVar29 = pvStack_75c;
                              if ((float)pvStack_768 < (float)pvVar45) {
                                pvStack_75c = pvVar32;
                                pvVar29 = pvVar32;
                                pvStack_768 = pvVar45;
                              }
                            }
                          }
                          uStack_778 = (float)((int)uStack_778 + 0x458);
                          iVar27 = (int)dStack_74c._0_4_ + -1;
                          dStack_74c = (double)CONCAT44(dStack_74c._4_4_,iVar27);
                        } while (iVar27 != 0);
                        goto LAB_4fc229cb;
                      }
LAB_4fc22b02:
                      iVar27 = iStack_758;
                      _Var23._Ptr = _Stack_780._Ptr;
                      iVar37 = SecondsToTurns(5.0);
                      _Var24._Ptr = _Stack_780._Ptr;
                      (_Var23._Ptr)->IdleTime = iVar37 + BZ1Helper::m_TurnCounter;
                      if (cStack_779 == '\0') goto LAB_4fc22b69;
                      std::
                      _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                      ::
                      _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                (&_Stack_6fc,*(DispatchClass **)pvStack_76c,
                                 (_Container_base0 *)pvStack_76c);
                      iVar37 = (_Var24._Ptr)->IdleTime;
                      iVar33 = (int)_Stack_780._Ptr - (int)_Stack_6fc._Ptr;
                      fmtarg2_00 = 0;
LAB_4fc22b4f:
                      FormatLogMessage("Index is: %d Mode is: %d Method is: %d No Valid Target, IdleTime: %d"
                                       ,iVar33 / 0x148,fmtarg2_00,iVar27,iVar37);
                    }
                    else {
                      if (iStack_758 == 1) {
                        auStack_6ec._0_4_ = 0.0;
                        pVVar31 = (Vector *)auStack_6ec;
                        auStack_6ec._4_4_ = 0.0;
                        fStack_6e4 = 0.0;
LAB_4fc228a7:
                        pvVar29 = (vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
                                   *)BuildingHelper::GetRandomBuilding
                                               (BuildingHelper::m_BuildingHelper,(int)local_764,1,
                                                true,true,true,0,(char *)0x0,(char *)0x0,0.0,
                                                *pVVar31);
                        pvStack_75c = pvVar29;
LAB_4fc229cb:
                        if (pvVar29 ==
                            (vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
                             *)0x0) goto LAB_4fc22b02;
                      }
                      else {
                        if (iStack_758 != 2) goto LAB_4fc22b02;
                        pvVar29 = *(vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
                                    **)(pDStack_760 + 0x27);
                        pvStack_75c = pvVar29;
                        if (((pvVar29 ==
                              (vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
                               *)0x0) &&
                            (pvVar29 = *(vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
                                         **)(pDStack_760 + 0x28), pvStack_75c = pvVar29,
                            pvVar29 ==
                            (vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
                             *)0x0)) &&
                           ((pvVar29 = *(vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
                                         **)(pDStack_760 + 0x2a), pvStack_75c = pvVar29,
                            pvVar29 ==
                            (vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
                             *)0x0 && (pvVar29 = *(
                                                  vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
                                                  **)(pDStack_760 + 0x29), pvStack_75c = pvVar29,
                                      pvVar29 ==
                                      (vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
                                       *)0x0)))) {
                          VStack_648.x = 0.0;
                          VStack_648.y = 0.0;
                          VStack_648.z = 0.0;
                          pVVar31 = &VStack_648;
                          pvStack_75c = (vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
                                         *)0x0;
                          goto LAB_4fc228a7;
                        }
                      }
                      if (*(int *)&(_Stack_780._Ptr)->DispatchTarget == 0) {
                        *(vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
                          **)&(_Stack_780._Ptr)->DispatchTarget = pvVar29;
                      }
                      GetPosition(*(int *)&(_Stack_780._Ptr)->DispatchTarget,&VStack_57c);
                      uStack_774 = (double)CONCAT44(uStack_774._4_4_,_Stack_780._Ptr);
                      VVar8.y = fStack_6f0;
                      VVar8.x = fStack_6f4;
                      VVar8.z = VStack_57c.x;
                      VVar17.y = VStack_57c.z;
                      VVar17.x = VStack_57c.y;
                      VVar17.z = 50.0;
                      pVVar31 = GetPositionNearOrFar
                                          (pVStack_6f8,VVar8,VVar17,250.0,(float)_Last._Ptr,
                                           SUB41(unaff_EDI,0));
                      *(float *)((int)(DispatchClass *)uStack_774 + 0xc) = pVVar31->x;
                      *(float *)((int)(DispatchClass *)uStack_774 + 0x10) = pVVar31->y;
                      *(float *)((int)(DispatchClass *)uStack_774 + 0x14) = pVVar31->z;
                      Goto((_Stack_780._Ptr)->DispatchObject,&(_Stack_780._Ptr)->DispatchSpot,0);
                      _Var23._Ptr = _Stack_780._Ptr;
                      fVar44 = GetRandomFloat(10.0);
                      (_Var23._Ptr)->RandomDist = fVar44 + 10.0;
                      (_Stack_780._Ptr)->IdleTime = 0;
                      (_Stack_780._Ptr)->DispatchState = 1;
                      if (cStack_779 == '\0') goto LAB_4fc22b69;
                      memset(TempGetODFName,0,0x40);
                      GetODFName((int)pvStack_75c,TempGetODFName);
                      _Var23._Ptr = _Stack_780._Ptr;
                      std::
                      _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                      ::
                      _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                (&_Stack_700,*(DispatchClass **)pvStack_76c,
                                 (_Container_base0 *)pvStack_76c);
                      fVar44 = ((_Var23._Ptr)->DispatchSpot).z;
                      iVar27 = (int)_Stack_780._Ptr - (int)_Stack_700._Ptr;
                      fVar46 = ((_Var23._Ptr)->DispatchSpot).y;
                      fVar1 = ((_Var23._Ptr)->DispatchSpot).x;
                      iVar37 = 0;
LAB_4fc22408:
                      FormatLogMessage("Index is: %d Mode is: %d Method is: %d Spot is: %f %f %f Target Is: \'%s\'"
                                       ,iVar27 / 0x148,iVar37,iStack_758,(double)fVar1,
                                       (double)fVar46,(double)fVar44,TempGetODFName);
                    }
                  }
                  else if (dStack_74c._0_4_ == (char *)0x1) {
                    pvStack_768 = (vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
                                   *)0x7f7fffff;
                    iVar27 = ScrapHelper::GetNumScrapObjects(ScrapHelper::m_ScrapHelper);
                    if (iStack_758 == 0) {
                      iVar37 = 0;
                      if (0 < iVar27) {
                        do {
                          if ((iVar27 < 2) || (fVar44 = GetRandomFloat(1.0), fVar44 < 0.5)) {
                            iVar33 = *(int *)(*(int *)&ScrapHelper::m_ScrapHelper->ScrapList +
                                             iVar37 * 4);
                            dStack_74c = (double)CONCAT44(dStack_74c._4_4_,iVar33);
                            GetPosition(iVar33,&VStack_5a0);
                            pvVar32 = (vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
                                       *)GetDistance2DSquared<Vector,Vector>
                                                   (&VStack_734,&VStack_5a0);
                            uStack_774 = (double)CONCAT44(uStack_774._4_4_,pvVar32);
                            if ((float)pvVar32 < (float)pvStack_768) {
                              *(char **)&(_Stack_780._Ptr)->DispatchTarget = dStack_74c._0_4_;
                              pvStack_768 = pvVar32;
                            }
                          }
                          iVar37 = iVar37 + 1;
                        } while (iVar37 < iVar27);
                      }
                    }
                    else if (iStack_758 == 1) {
                      if (0 < iVar27) {
                        iVar27 = GetRandomInt(0,iVar27 + -1);
                        *(undefined4 *)&(_Stack_780._Ptr)->DispatchTarget =
                             *(undefined4 *)
                              (*(int *)&ScrapHelper::m_ScrapHelper->ScrapList + iVar27 * 4);
                      }
                    }
                    else if (iStack_758 == 2) {
                      pvStack_768 = (vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
                                     *)0x0;
                      iVar37 = 0;
                      if (0 < iVar27) {
                        do {
                          if ((iVar27 < 2) || (fVar44 = GetRandomFloat(1.0), fVar44 < 0.5)) {
                            iVar33 = *(int *)(*(int *)&ScrapHelper::m_ScrapHelper->ScrapList +
                                             iVar37 * 4);
                            dStack_74c = (double)CONCAT44(dStack_74c._4_4_,iVar33);
                            GetPosition(iVar33,&VStack_5ac);
                            pvVar32 = (vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
                                       *)GetDistance2DSquared<Vector,Vector>
                                                   (&VStack_734,&VStack_5ac);
                            uStack_774 = (double)CONCAT44(uStack_774._4_4_,pvVar32);
                            if ((float)pvStack_768 < (float)pvVar32) {
                              *(char **)&(_Stack_780._Ptr)->DispatchTarget = dStack_74c._0_4_;
                              pvStack_768 = pvVar32;
                            }
                          }
                          iVar37 = iVar37 + 1;
                        } while (iVar37 < iVar27);
                      }
                    }
                    GetPosition(*(int *)&(_Stack_780._Ptr)->DispatchTarget,&VStack_594);
                    uStack_774 = (double)CONCAT44(uStack_774._4_4_,_Stack_780._Ptr);
                    VVar12.y = VStack_594.y;
                    VVar12.x = VStack_594.x;
                    VVar12.z = VStack_594.z;
                    pVVar31 = GetPositionNear(&VStack_510,VVar12,10.0,50.0);
                    _Var23._Ptr = _Stack_780._Ptr;
                    *(float *)((int)(DispatchClass *)uStack_774 + 0xc) = pVVar31->x;
                    *(float *)((int)(DispatchClass *)uStack_774 + 0x10) = pVVar31->y;
                    *(float *)((int)(DispatchClass *)uStack_774 + 0x14) = pVVar31->z;
                    if (cStack_779 != '\0') {
                      std::
                      _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                      ::
                      _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                (&_Stack_6d4,*(DispatchClass **)pvStack_76c,
                                 (_Container_base0 *)pvStack_76c);
                      FormatLogMessage("Index is: %d Mode is: %d Method is: %d Spot is: %f %f %f",
                                       ((int)_Stack_780._Ptr - (int)_Stack_6d4._Ptr) / 0x148,1,
                                       iStack_758,(double)((_Var23._Ptr)->DispatchSpot).x,
                                       (double)((_Var23._Ptr)->DispatchSpot).y,
                                       (double)((_Var23._Ptr)->DispatchSpot).z);
                    }
                    bVar26 = IsNullVector((_Stack_780._Ptr)->DispatchSpot);
                    if (bVar26) {
                      uStack_684 = 0;
                      uStack_680 = 0;
                      uStack_67c = 0;
                      uStack_774._0_4_ = _Stack_780._Ptr;
                      iVar27 = BZ1Helper::GetRandomObject
                                         (local_754,-1,0,false,0,false,true,true,0,(char *)0x0,
                                          (char *)0x0,0.0,(Vector)ZEXT812(0));
                      *(int *)&((DispatchClass *)uStack_774)->DispatchTarget = iVar27;
                      GetPosition(*(int *)&(_Stack_780._Ptr)->DispatchTarget,&VStack_588);
                      uStack_774 = (double)CONCAT44(uStack_774._4_4_,_Stack_780._Ptr);
                      VVar13.y = VStack_588.y;
                      VVar13.x = VStack_588.x;
                      VVar13.z = VStack_588.z;
                      pVVar31 = GetPositionNear(aVStack_504,VVar13,10.0,50.0);
                      _Var23._Ptr = _Stack_780._Ptr;
                      *(float *)((int)(DispatchClass *)uStack_774 + 0xc) = pVVar31->x;
                      *(float *)((int)(DispatchClass *)uStack_774 + 0x10) = pVVar31->y;
                      *(float *)((int)(DispatchClass *)uStack_774 + 0x14) = pVVar31->z;
                      if (cStack_779 != '\0') {
                        std::
                        _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                        ::
                        _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                  (&_Stack_6c0,*(DispatchClass **)pvStack_76c,
                                   (_Container_base0 *)pvStack_76c);
                        FormatLogMessage("Pathing Failed, using random object. Index is: %d Mode is: %d Method is: %d Spot is: %f %f %f."
                                         ,((int)_Stack_780._Ptr - (int)_Stack_6c0._Ptr) / 0x148,1,
                                         iStack_758,(double)((_Var23._Ptr)->DispatchSpot).x,
                                         (double)((_Var23._Ptr)->DispatchSpot).y,
                                         (double)((_Var23._Ptr)->DispatchSpot).z);
                      }
                    }
                    Goto((_Stack_780._Ptr)->DispatchObject,&(_Stack_780._Ptr)->DispatchSpot,0);
                    _Var23._Ptr = _Stack_780._Ptr;
                    fVar44 = GetRandomFloat(50.0);
                    (_Var23._Ptr)->RandomDist = fVar44 + 10.0;
                    (_Stack_780._Ptr)->IdleTime = 0;
                    (_Stack_780._Ptr)->DispatchState = 1;
                  }
                  else if (dStack_74c._0_4_ == (char *)0x2) {
                    pvStack_768 = (vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
                                   *)0x7f7fffff;
                    if (iStack_758 == 0) {
                      if (0 < local_724) {
                        uStack_774 = (double)CONCAT44(uStack_774._4_4_,local_724);
                        uStack_778 = 0.0;
                        pvVar32 = pvVar29;
                        do {
                          fVar44 = uStack_778;
                          if ((local_724 < 2) || (fVar46 = GetRandomFloat(1.0), fVar46 < 0.5)) {
                            puVar40 = (undefined4 *)
                                      (*(int *)&BuildingHelper::m_BuildingHelper->BuildingList +
                                      (int)fVar44);
                            ppvVar42 = apvStack_4ec;
                            for (iVar27 = 0x116; pvVar29 = apvStack_4ec[0], iVar27 != 0;
                                iVar27 = iVar27 + -1) {
                              *ppvVar42 = (vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
                                           *)*puVar40;
                              puVar40 = puVar40 + 1;
                              ppvVar42 = ppvVar42 + 1;
                            }
                            bVar26 = IsTeamAllied((int)local_764,(int)pfStack_264);
                            pvVar32 = pvStack_75c;
                            if (((!bVar26) && (cStack_2b4 != '\0')) && (0 < iStack_25c)) {
                              pvVar45 = (vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
                                         *)GetDistance2DSquared<Vector,Vector>
                                                     (&VStack_734,aVStack_c0);
                              dStack_74c = (double)CONCAT44(dStack_74c._4_4_,pvVar45);
                              pvVar32 = pvStack_75c;
                              if ((float)pvVar45 < (float)pvStack_768) {
                                pvStack_75c = pvVar29;
                                pvVar32 = pvVar29;
                                pvStack_768 = pvVar45;
                              }
                            }
                          }
                          uStack_778 = (float)((int)uStack_778 + 0x458);
                          iVar27 = (int)(DispatchClass *)uStack_774 + -1;
                          uStack_774 = (double)CONCAT44(uStack_774._4_4_,iVar27);
                          pvVar29 = pvStack_75c;
                        } while (iVar27 != 0);
                        goto LAB_4fc22286;
                      }
                    }
                    else {
                      if (iStack_758 == 1) {
                        VStack_654.x = 0.0;
                        pVVar31 = &VStack_654;
                        VStack_654.y = 0.0;
                        VStack_654.z = 0.0;
                      }
                      else {
                        if (iStack_758 != 2) goto LAB_4fc22423;
                        pvVar29 = pvVar32;
                        if (pvVar32 !=
                            (vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
                             *)0x0) goto LAB_4fc22286;
                        VStack_660.x = 0.0;
                        pVVar31 = &VStack_660;
                        VStack_660.y = 0.0;
                        VStack_660.z = 0.0;
                      }
                      pvVar32 = (vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
                                 *)BuildingHelper::GetRandomBuilding
                                             (BuildingHelper::m_BuildingHelper,(int)local_764,4,true
                                              ,true,true,0,(char *)0x0,(char *)0x0,0.0,*pVVar31);
                      pvVar29 = pvVar32;
LAB_4fc22286:
                      pvStack_75c = pvVar29;
                      if (pvVar32 !=
                          (vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
                           *)0x0) {
                        GetPosition((int)pvVar32,&VStack_5c4);
                        uStack_774._0_4_ = _Stack_780._Ptr;
                        VVar22.y = VStack_5c4.y;
                        VVar22.x = VStack_5c4.x;
                        VVar22.z = VStack_5c4.z;
                        iVar27 = BuildingHelper::GetRandomBuilding
                                           (BuildingHelper::m_BuildingHelper,(int)local_764,4,true,
                                            true,true,0,(char *)0x0,(char *)0x0,200.0,VVar22);
                        *(int *)&((DispatchClass *)uStack_774)->DispatchTarget = iVar27;
                        if (*(int *)&(_Stack_780._Ptr)->DispatchTarget == 0) {
                          *(vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
                            **)&(_Stack_780._Ptr)->DispatchTarget = pvStack_75c;
                        }
                        GetPosition(*(int *)&(_Stack_780._Ptr)->DispatchTarget,&VStack_5b8);
                        uStack_774 = (double)CONCAT44(uStack_774._4_4_,_Stack_780._Ptr);
                        VVar7.y = VStack_734.z;
                        VVar7.x = VStack_734.y;
                        VVar7.z = VStack_5b8.x;
                        VVar16.y = VStack_5b8.z;
                        VVar16.x = VStack_5b8.y;
                        VVar16.z = 50.0;
                        pVVar31 = GetPositionNearOrFar
                                            ((Vector *)VStack_734.x,VVar7,VVar16,250.0,
                                             (float)_Last._Ptr,SUB41(unaff_EDI,0));
                        *(float *)((int)(DispatchClass *)uStack_774 + 0xc) = pVVar31->x;
                        *(float *)((int)(DispatchClass *)uStack_774 + 0x10) = pVVar31->y;
                        *(float *)((int)(DispatchClass *)uStack_774 + 0x14) = pVVar31->z;
                        Goto((_Stack_780._Ptr)->DispatchObject,&(_Stack_780._Ptr)->DispatchSpot,0);
                        _Var23._Ptr = _Stack_780._Ptr;
                        fVar44 = GetRandomFloat((_Stack_780._Ptr)->EngageRange);
                        (_Var23._Ptr)->RandomDist = fVar44 + 100.0;
                        (_Stack_780._Ptr)->IdleTime = 0;
                        (_Stack_780._Ptr)->DispatchState = 1;
                        if (cStack_779 != '\0') {
                          iVar27 = *(int *)&(_Stack_780._Ptr)->DispatchTarget;
                          memset(TempGetODFName,0,0x40);
                          GetODFName(iVar27,TempGetODFName);
                          _Var23._Ptr = _Stack_780._Ptr;
                          std::
                          _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                          ::
                          _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                    (&_Stack_6dc,*(DispatchClass **)pvStack_76c,
                                     (_Container_base0 *)pvStack_76c);
                          fVar44 = ((_Var23._Ptr)->DispatchSpot).z;
                          iVar27 = (int)_Stack_780._Ptr - (int)_Stack_6dc._Ptr;
                          fVar46 = ((_Var23._Ptr)->DispatchSpot).y;
                          fVar1 = ((_Var23._Ptr)->DispatchSpot).x;
                          iVar37 = 2;
                          goto LAB_4fc22408;
                        }
                        goto LAB_4fc22b69;
                      }
                    }
LAB_4fc22423:
                    _Var23._Ptr = _Stack_780._Ptr;
                    iVar27 = SecondsToTurns(5.0);
                    _Var24._Ptr = _Stack_780._Ptr;
                    (_Var23._Ptr)->IdleTime = iVar27 + BZ1Helper::m_TurnCounter;
                    if (cStack_779 != '\0') {
                      std::
                      _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                      ::
                      _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                (&_Stack_6d8,*(DispatchClass **)pvStack_76c,
                                 (_Container_base0 *)pvStack_76c);
                      iVar37 = (_Var24._Ptr)->IdleTime;
                      iVar33 = (int)_Stack_780._Ptr - (int)_Stack_6d8._Ptr;
                      fmtarg2_00 = 2;
                      iVar27 = iStack_758;
                      goto LAB_4fc22b4f;
                    }
                  }
                }
              }
              else if (iVar27 == 2) {
                if ((0 < *(int *)(pDStack_760 + 0x4c)) &&
                   (*(int *)(pDStack_760 + 0x4f) < *(int *)(pDStack_760 + 0x4c))) {
                  pDStack_760[0x4f] = (DLLBase)(*(int *)(pDStack_760 + 0x4f) + 1);
                  iVar27 = *(int *)&local_754->PatrolPathList[(int)local_764].field_0x4 -
                           *(int *)(local_754->PatrolPathList + (int)local_764) >> 2;
                  if (iVar27 < 1) {
                    fVar44 = GetRandomFloat(1.0);
                    uStack_774 = (double)fVar44;
                    if (0.2 <= fVar44) {
                      uStack_66c = 0;
                      uStack_668 = 0;
                      uStack_664 = 0;
                      iVar27 = 1;
                    }
                    else {
                      uStack_678 = 0;
                      uStack_674 = 0;
                      uStack_670 = 0;
                      iVar27 = 3;
                    }
                    iVar27 = BuildingHelper::GetRandomBuilding
                                       (BuildingHelper::m_BuildingHelper,(int)local_764,iVar27,true,
                                        true,true,0,(char *)0x0,(char *)0x0,0.0,(Vector)ZEXT812(0));
                    if ((uStack_774 < 0.10000000149011612) || (iVar27 == 0)) {
                      dStack_74c = (double)CONCAT44(dStack_74c._4_4_,_Stack_780._Ptr);
                      fVar44 = (_Stack_780._Ptr)->EngageRange * 5.0;
                      uStack_774 = (double)CONCAT44(uStack_774._4_4_,fVar44);
                      VVar11.y = VStack_734.y;
                      VVar11.x = VStack_734.x;
                      VVar11.z = VStack_734.z;
                      pVVar31 = GetPositionNear(aVStack_528,VVar11,100.0,fVar44);
                      iVar27 = (int)dStack_74c._0_4_;
                    }
                    else {
                      GetPosition(iVar27,&VStack_5e8);
                      uStack_774 = (double)CONCAT44(uStack_774._4_4_,_Stack_780._Ptr);
                      VVar10.y = VStack_5e8.y;
                      VVar10.x = VStack_5e8.x;
                      VVar10.z = VStack_5e8.z;
                      pVVar31 = GetPositionNear(&VStack_534,VVar10,50.0,100.0);
                      iVar27 = (int)(DispatchClass *)uStack_774;
                    }
                    *(float *)(iVar27 + 0xc) = pVVar31->x;
                    *(float *)(iVar27 + 0x10) = pVVar31->y;
                    *(float *)(iVar27 + 0x14) = pVVar31->z;
                    Goto((_Stack_780._Ptr)->DispatchObject,&(_Stack_780._Ptr)->DispatchSpot,0);
                    _Var23._Ptr = _Stack_780._Ptr;
                    (_Stack_780._Ptr)->DispatchState = 1;
                    (_Stack_780._Ptr)->IdleTime = 0;
                    if (cStack_779 != '\0') {
                      memset(TempGetODFName,0,0x40);
                      GetODFName((int)_Stack_71c._Ptr,TempGetODFName);
                      std::
                      _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                      ::
                      _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                (&_Stack_6d0,*(DispatchClass **)pvStack_76c,
                                 (_Container_base0 *)pvStack_76c);
                      FormatLogMessage("Index: %d sent to Dynamic Patrol Near Handle: %08x, ODF: \'%s\', Position: %f %f %f"
                                       ,((int)_Stack_780._Ptr - (int)_Stack_6d0._Ptr) / 0x148,
                                       (uint)_Stack_71c._Ptr,TempGetODFName,
                                       (double)((_Var23._Ptr)->DispatchSpot).x,
                                       (double)((_Var23._Ptr)->DispatchSpot).y,
                                       (double)((_Var23._Ptr)->DispatchSpot).z);
                    }
                  }
                  else {
                    iVar27 = GetRandomInt(0,iVar27 + -1);
                    uStack_778 = 0.0;
                    pcVar47 = *(char **)(*(int *)(local_754->PatrolPathList + (int)pfVar39) +
                                        iVar27 * 4);
                    if ((pcVar47 != (char *)0x0) &&
                       (GetPathPoints(pcVar47,&uStack_778,(float *)0x0), uStack_778 != 0.0)) {
                      Patrol((_Stack_780._Ptr)->DispatchObject,pcVar47,0);
                      (_Stack_780._Ptr)->DispatchState = 1;
                      (_Stack_780._Ptr)->IdleTime = 0;
                      if (cStack_779 != '\0') {
                        std::
                        _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                        ::
                        _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                  (&_Stack_6c8,*(DispatchClass **)pvVar32,
                                   (_Container_base0 *)pvVar32);
                        pcVar47 = "Index: %d sent to Patrol path: \'%s\', TurnCount: %d";
                        goto LAB_4fc20f48;
                      }
                    }
                  }
                }
              }
              else if (iVar27 == 3) {
                iVar27 = *(int *)&local_754->MLayPathList[(int)local_764].field_0x4 -
                         *(int *)(local_754->MLayPathList + (int)local_764) >> 2;
                if (iVar27 < 1) {
                  pvStack_768 = (vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
                                 *)GetRandomInt(0,2);
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
                    iVar27 = BuildingHelper::GetRandomBuilding
                                       (BuildingHelper::m_BuildingHelper,(int)local_764,4,true,true,
                                        true,0,(char *)0x0,(char *)0x0,0.0,(Vector)ZEXT812(0));
                    dStack_74c = (double)CONCAT44(dStack_74c._4_4_,iVar27);
                    VVar21.y = (float)uStack_6b0;
                    VVar21.x = (float)uStack_6b8._4_4_;
                    VVar21.z = fStack_6ac;
                    iVar27 = BuildingHelper::GetRandomBuilding
                                       ((BuildingHelper *)(DispatchClass *)uStack_774,(int)local_764
                                        ,1,true,true,true,0,(char *)0x0,(char *)0x0,0.0,VVar21);
                    GetPosition(iVar27,&VStack_60c);
                    GetPosition((int)dStack_74c._0_4_,&VStack_600);
                    VVar6.y = VStack_600.z;
                    VVar6.x = VStack_600.y;
                    VVar6.z = VStack_60c.x;
                    VVar15.y = VStack_60c.z;
                    VVar15.x = VStack_60c.y;
                    VVar15.z = 100.0;
                    GetPositionNearOrFar
                              ((Vector *)VStack_600.x,VVar6,VVar15,200.0,(float)_Last._Ptr,
                               SUB41(unaff_EDI,0));
                    pfVar39 = afStack_5f4;
LAB_4fc21b7f:
                    ((_Stack_780._Ptr)->DispatchSpot).x = *pfVar39;
                    ((_Stack_780._Ptr)->DispatchSpot).y = pfVar39[1];
                    ((_Stack_780._Ptr)->DispatchSpot).z = pfVar39[2];
                    pvVar32 = pvStack_76c;
                  }
                  else if (pvStack_768 ==
                           (vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
                            *)0x1) {
                    fVar44 = (local_754->mapInfo).MapDepth;
                    uStack_778 = (local_754->mapInfo).MapWidth;
                    uStack_774 = (double)CONCAT44(uStack_774._4_4_,fVar44);
                    fStack_69c = GetRandomFloat(-fVar44,fVar44);
                    fStack_698 = 0.0;
                    fStack_694 = GetRandomFloat(-uStack_778,uStack_778);
                    _Var23._Ptr = _Stack_780._Ptr;
                    ((_Stack_780._Ptr)->DispatchSpot).x = fStack_69c;
                    ((_Stack_780._Ptr)->DispatchSpot).y = fStack_698;
                    ((_Stack_780._Ptr)->DispatchSpot).z = fStack_694;
                    fVar44 = TerrainFindFloor(((_Stack_780._Ptr)->DispatchSpot).x,
                                              ((_Stack_780._Ptr)->DispatchSpot).z);
                    ((_Var23._Ptr)->DispatchSpot).y = fVar44;
                    pvVar32 = pvStack_76c;
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
                    iVar27 = BuildingHelper::GetRandomBuilding
                                       (BuildingHelper::m_BuildingHelper,(int)local_764,4,true,true,
                                        true,0,(char *)0x0,(char *)0x0,0.0,(Vector)ZEXT812(0));
                    GetPosition(iVar27,(Vector *)(auStack_634 + 4));
                    VVar5.y = fStack_61c;
                    VVar5.x = fStack_620;
                    VVar5.z = (float)auStack_634._4_4_;
                    VVar14.y = fStack_628;
                    VVar14.x = fStack_62c;
                    VVar14.z = 100.0;
                    GetPositionNearOrFar
                              (pVStack_624,VVar5,VVar14,200.0,(float)_Last._Ptr,SUB41(unaff_EDI,0));
                    pfVar39 = afStack_618;
                    goto LAB_4fc21b7f;
                  }
                  _Var23._Ptr = _Stack_780._Ptr;
                  if (cStack_779 != '\0') {
                    uStack_778 = *(float *)pvVar32;
                    std::_Iterator_base0::_Adopt((_Iterator_base0 *)&uStack_778,pvVar32);
                    dVar48 = (double)((_Var23._Ptr)->DispatchSpot).z;
                    dVar2 = (double)((_Var23._Ptr)->DispatchSpot).y;
                    FormatLogMessage("Index: %d sent to Dynamic Minelaying, DispatchState: %d, Position: %f %f %f"
                                     ,((int)_Stack_780._Ptr - (int)uStack_778) / 0x148,
                                     (int)pvStack_768,
                                     (double)CONCAT44(SUB84(dVar2,0),
                                                      (int)((ulonglong)
                                                            (double)((_Var23._Ptr)->DispatchSpot).x
                                                           >> 0x20)),
                                     (double)CONCAT44(SUB84(dVar48,0),
                                                      (int)((ulonglong)dVar2 >> 0x20)),
                                     (double)CONCAT44(_Last._Ptr,(int)((ulonglong)dVar48 >> 0x20)));
                  }
                }
                else {
                  iVar27 = GetRandomInt(0,iVar27 + -1);
                  uStack_778 = 0.0;
                  pcVar47 = *(char **)(*(int *)(local_754->MLayPathList + (int)pfVar39) + iVar27 * 4
                                      );
                  dStack_74c = (double)CONCAT44(dStack_74c._4_4_,pcVar47);
                  if ((pcVar47 != (char *)0x0) &&
                     (GetPathPoints(pcVar47,&uStack_778,(float *)0x0), uStack_778 != 0.0)) {
                    uStack_774 = (double)CONCAT44(uStack_774._4_4_,_Stack_780._Ptr);
                    pVVar31 = GetVectorFromPath((Vector *)0x0,(char *)_Last._Ptr,(int)unaff_EDI);
                    pVVar31 = GetPositionNear(&VStack_540,*pVVar31,25.0,50.0);
                    *(float *)((int)(DispatchClass *)uStack_774 + 0xc) = pVVar31->x;
                    *(float *)((int)(DispatchClass *)uStack_774 + 0x10) = pVVar31->y;
                    *(float *)((int)(DispatchClass *)uStack_774 + 0x14) = pVVar31->z;
                    if (cStack_779 != '\0') {
                      std::
                      _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                      ::
                      _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                (&_Stack_6cc,*(DispatchClass **)pvStack_76c,
                                 (_Container_base0 *)pvStack_76c);
                      FormatLogMessage("Index: %d sent to Lay Mines at path: \'%s\'",
                                       ((int)_Stack_780._Ptr - (int)_Stack_6cc._Ptr) / 0x148,
                                       dStack_74c._0_4_);
                    }
                  }
                }
                bVar26 = IsNullVector((_Stack_780._Ptr)->DispatchSpot);
                if (!bVar26) {
                  Goto((_Stack_780._Ptr)->DispatchObject,&(_Stack_780._Ptr)->DispatchSpot,0);
                  _Var23._Ptr = _Stack_780._Ptr;
                  (_Stack_780._Ptr)->DispatchState = 1;
                  iVar27 = SecondsToTurns(300.0);
                  (_Var23._Ptr)->IdleTime = iVar27 + BZ1Helper::m_TurnCounter;
                  if (cStack_779 != '\0') {
                    uStack_778 = *(float *)pvStack_76c;
                    std::_Iterator_base0::_Adopt((_Iterator_base0 *)&uStack_778,pvStack_76c);
                    pcVar47 = "Index is: %d Minelayer No Valid Target, IdleTime: %d";
                    goto LAB_4fc20e4b;
                  }
                }
              }
              else if (iVar27 == 4) {
                if ((0 < *(int *)(pDStack_760 + 0x4d)) &&
                   (*(int *)(pDStack_760 + 0x50) < *(int *)(pDStack_760 + 0x4d))) {
                  pDStack_760[0x50] = (DLLBase)(*(int *)(pDStack_760 + 0x50) + 1);
                  SetCommand((_Stack_780._Ptr)->DispatchObject,0x15,0,0,(char *)0x0,0);
                  _Var23._Ptr = _Stack_780._Ptr;
                  (_Stack_780._Ptr)->DispatchState = 1;
                  iVar27 = SecondsToTurns(300.0);
                  (_Var23._Ptr)->IdleTime = iVar27 + BZ1Helper::m_TurnCounter;
                  if (cStack_779 != '\0') {
                    uStack_778 = *(float *)pvVar32;
                    std::_Iterator_base0::_Adopt((_Iterator_base0 *)&uStack_778,pvVar32);
                    pcVar47 = "Index: %d Hunt Task Starting, Hunt Command issued. IdleTime: %d";
                    goto LAB_4fc20e4b;
                  }
                }
              }
              else if (((iVar27 == 5) && (0 < *(int *)(pDStack_760 + 0x4e))) &&
                      (*(int *)(pDStack_760 + 0x51) < *(int *)(pDStack_760 + 0x4e))) {
                iVar27 = UtilityShipHelper::GetEscortTarget
                                   (UtilityShipHelper::m_UtilityShipHelper,(int)local_764,3);
                *(int *)&(_Var23._Ptr)->DispatchTarget = iVar27;
                if (*(int *)&(_Stack_780._Ptr)->DispatchTarget != 0) {
                  Defend2((_Stack_780._Ptr)->DispatchObject,
                          *(int *)&(_Stack_780._Ptr)->DispatchTarget,0);
                  (_Stack_780._Ptr)->DispatchState = 1;
                  (_Stack_780._Ptr)->IdleTime = 0;
                  if (cStack_779 != '\0') {
                    iVar27 = *(int *)&(_Stack_780._Ptr)->DispatchTarget;
                    memset(TempGetODFName,0,0x40);
                    GetODFName(iVar27,TempGetODFName);
                    iStack_718 = *(int *)pvVar32;
                    std::_Iterator_base0::_Adopt((_Iterator_base0 *)&iStack_718,pvVar32);
                    FormatLogMessage("Index: %d Escort Task Starting, Target: \'%s\'",
                                     ((int)_Stack_780._Ptr - iStack_718) / 0x148,TempGetODFName);
                  }
                  pDStack_760[0x51] = (DLLBase)(*(int *)(pDStack_760 + 0x51) + 1);
                }
              }
            }
          }
          else if (iVar27 == 1) {
            if ((_Stack_780._Ptr)->DispatchType == 1) {
              if ((_Stack_780._Ptr)->IdleTime == 0) {
                bVar26 = IsDeployed((_Stack_780._Ptr)->DispatchObject);
                _Var23._Ptr = _Stack_780._Ptr;
                if (bVar26) {
                  if ((_Stack_780._Ptr)->IdleTime != 0) goto LAB_4fc20f93;
                }
                else {
                  iVar27 = SecondsToTurns(300.0);
                  (_Var23._Ptr)->IdleTime = iVar27 + BZ1Helper::m_TurnCounter;
                }
              }
              else {
LAB_4fc20f93:
                bVar26 = IsDeployed((_Stack_780._Ptr)->DispatchObject);
                if (bVar26) {
                  (_Stack_780._Ptr)->DispatchState = 0;
                }
              }
            }
            if (((_Stack_780._Ptr)->SkipAIPCheck != false) ||
               (*(bool *)((int)(pDStack_760 + 0x6b) + 2) != false)) {
              if ((0 < (_Stack_780._Ptr)->IdleTime) &&
                 ((_Stack_780._Ptr)->IdleTime <= BZ1Helper::m_TurnCounter)) {
                ClearDispatch((DispatchHelper *)local_73c._Ptr,(int)pvStack_768);
              }
              iVar27 = (_Stack_780._Ptr)->DispatchType;
              if (iVar27 == 1) {
                bVar26 = IsDeployed((_Stack_780._Ptr)->DispatchObject);
                if (bVar26) goto LAB_4fc22b69;
                uStack_778 = 0.0;
                local_750._0_3_ = (uint3)(byte)local_750;
                if (0 < iStack_728) {
                  iStack_758 = 0;
                  do {
                    piVar38 = (int *)(*(int *)&local_754->m_ObjectHelper->HandleList + iStack_758);
                    iStack_708 = *piVar38;
                    bVar26 = IsTeamAllied((int)local_764,piVar38[7]);
                    if ((!bVar26) &&
                       ((piVar38[4] == 2 ||
                        ((piVar38[2] == 0x4a7aef92 && (bVar26 = IsDeployed(iStack_708), bVar26))))))
                    {
                      uStack_774 = (double)((float)piVar38[9] + 50.0);
                      fVar46 = GetDistance2DSquared<Vector,Vector>
                                         (&VStack_734,(Vector *)(piVar38 + 0x12));
                      fVar44 = (float)((float10)uStack_774 * (float10)uStack_774);
                      uStack_774 = (double)CONCAT44(uStack_774._4_4_,fVar44);
                      if (fVar46 < fVar44) {
                        local_750._0_2_ = CONCAT11(1,(byte)local_750);
                        fVar44 = GetRandomFloat(1.0);
                        if (fVar44 < 0.5) {
                          local_750._0_3_ = CONCAT12(1,(undefined2)local_750);
                        }
                        if (cStack_779 != '\0') {
                          (*misnImport.GetDistanceObject)
                                    (&(_Stack_780._Ptr)->DispatchObject,&iStack_708);
                          iStack_704 = *(int *)pvVar32;
                          uStack_774 = (double)CONCAT44(uStack_774._4_4_,(float)extraout_ST0);
                          std::_Iterator_base0::_Adopt((_Iterator_base0 *)&iStack_704,pvVar32);
                          FormatLogMessage("Index: %d Turret Encountered an Enemy on Team: %d Distance Is: %f, Return is: %d"
                                           ,((int)_Stack_780._Ptr - iStack_704) / 0x148,piVar38[7],
                                           (double)(ulonglong)
                                                   CONCAT14(local_750._2_1_,
                                                            (int)((ulonglong)
                                                                  (double)(float)(DispatchClass *)
                                                                                 uStack_774 >> 0x20)
                                                           ),(int)_Last._Ptr);
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
                  uStack_774 = (double)((_Stack_780._Ptr)->RandomDist + 5.0);
                  fVar46 = GetDistance2DSquared<Vector,Vector>
                                     (&VStack_734,&(_Stack_780._Ptr)->DispatchSpot);
                  fVar44 = (float)((float10)uStack_774 * (float10)uStack_774);
                  uStack_774 = (double)CONCAT44(uStack_774._4_4_,fVar44);
                  if (fVar44 < fVar46) goto LAB_4fc214fa;
                }
                if (local_750._2_1_ == '\0') {
                  if (local_750._1_1_ == '\0') {
                    Defend((_Stack_780._Ptr)->DispatchObject,0);
                  }
                  else {
                    uStack_774 = (double)CONCAT44(uStack_774._4_4_,_Stack_780._Ptr);
                    VVar9.y = VStack_734.y;
                    VVar9.x = VStack_734.x;
                    VVar9.z = VStack_734.z;
                    pVVar31 = GetPositionNear(aVStack_558,VVar9,10.0,30.0);
                    *(float *)((int)(DispatchClass *)uStack_774 + 0xc) = pVVar31->x;
                    *(float *)((int)(DispatchClass *)uStack_774 + 0x10) = pVVar31->y;
                    *(float *)((int)(DispatchClass *)uStack_774 + 0x14) = pVVar31->z;
                    Goto((_Stack_780._Ptr)->DispatchObject,&(_Stack_780._Ptr)->DispatchSpot,0);
                    pvVar32 = pvStack_76c;
                    _Var23._Ptr = _Stack_780._Ptr;
                    if (cStack_779 != '\0') {
                      uStack_778 = *(float *)pvStack_76c;
                      std::_Iterator_base0::_Adopt((_Iterator_base0 *)&uStack_778,pvStack_76c);
                      FormatLogMessage("Index is: %d Spot is: %f %f %f",
                                       ((int)_Stack_780._Ptr - (int)uStack_778) / 0x148,
                                       (double)((_Var23._Ptr)->DispatchSpot).x,
                                       (double)((_Var23._Ptr)->DispatchSpot).y,
                                       (double)((_Var23._Ptr)->DispatchSpot).z);
                    }
                  }
                  _Var23._Ptr = _Stack_780._Ptr;
                  (_Stack_780._Ptr)->DispatchState = 0;
                  iVar27 = SecondsToTurns(300.0);
                  (_Var23._Ptr)->IdleTime = iVar27 + BZ1Helper::m_TurnCounter;
                  if (cStack_779 != '\0') {
                    uStack_778 = *(float *)pvVar32;
                    std::_Iterator_base0::_Adopt((_Iterator_base0 *)&uStack_778,pvVar32);
                    pcVar47 = "Index is: %d Turret Encountered an Enemy, IdleTime: %d";
LAB_4fc20e4b:
                    FormatLogMessage(pcVar47);
                  }
                }
                else {
                  ClearDispatch((DispatchHelper *)local_73c._Ptr,(int)pvStack_768);
                }
              }
              else if (iVar27 == 2) {
                bVar26 = IsIdle((_Stack_780._Ptr)->DispatchObject);
                _Var23._Ptr = _Stack_780._Ptr;
                if (bVar26) {
                  if ((*(int *)&local_754->PatrolPathList[(int)local_764].field_0x4 -
                       *(int *)(local_754->PatrolPathList + (int)local_764) & 0xfffffffcU) == 0) {
                    (_Stack_780._Ptr)->IdleTime = 0;
                    if (cStack_779 != '\0') {
                      uStack_778 = *(float *)pvVar32;
                      std::_Iterator_base0::_Adopt((_Iterator_base0 *)&uStack_778,pvVar32);
                      FormatLogMessage("Index: %d sent to Dynamic Patrol Reset, Cmd == CMD_NONE",
                                       ((int)_Stack_780._Ptr - (int)uStack_778) / 0x148);
                    }
                  }
                  else {
                    iVar27 = SecondsToTurns(15.0);
                    _Var24._Ptr = _Stack_780._Ptr;
                    (_Var23._Ptr)->IdleTime = iVar27 + BZ1Helper::m_TurnCounter;
                    if (cStack_779 != '\0') {
                      uStack_778 = *(float *)pvVar32;
                      std::_Iterator_base0::_Adopt((_Iterator_base0 *)&uStack_778,pvVar32);
                      FormatLogMessage("Patrol Unit %d interrupted, resetting idle timer. TurnCount: %d, IdleTime: %d"
                                       ,((int)_Stack_780._Ptr - (int)uStack_778) / 0x148,
                                       BZ1Helper::m_TurnCounter,(_Var24._Ptr)->IdleTime);
                    }
                  }
                  (_Stack_780._Ptr)->DispatchState = 0;
                }
              }
              else if (iVar27 == 3) {
                fVar44 = GetDistance2DSquared<Vector,Vector>
                                   (&VStack_734,&(_Stack_780._Ptr)->DispatchSpot);
                if (fVar44 < 100.0) {
                  SetCommand((_Stack_780._Ptr)->DispatchObject,0x1b,0,0,(char *)0x0,0);
                  _Var23._Ptr = _Stack_780._Ptr;
                  (_Stack_780._Ptr)->DispatchState = 0;
                  iVar27 = SecondsToTurns(300.0);
                  _Var24._Ptr = _Stack_780._Ptr;
                  (_Var23._Ptr)->IdleTime = iVar27 + BZ1Helper::m_TurnCounter;
                  if (cStack_779 != '\0') {
                    uStack_778 = *(float *)pvVar32;
                    std::_Iterator_base0::_Adopt((_Iterator_base0 *)&uStack_778,pvVar32);
                    FormatLogMessage("Index: %d Minelayer reached Spot: %f %f %f, laying mines..., IdleTime: %d"
                                     ,((int)_Stack_780._Ptr - (int)uStack_778) / 0x148,
                                     (double)((_Var24._Ptr)->DispatchSpot).x,
                                     (double)((_Var24._Ptr)->DispatchSpot).y,
                                     (double)((_Var24._Ptr)->DispatchSpot).z,(_Var24._Ptr)->IdleTime
                                    );
                  }
                }
              }
              else {
                if (iVar27 == 4) {
                  bVar26 = IsIdle((_Stack_780._Ptr)->DispatchObject);
                  if (!bVar26) goto LAB_4fc22b69;
                  SetCommand((_Stack_780._Ptr)->DispatchObject,0x15,0,0,(char *)0x0,0);
                  _Var23._Ptr = _Stack_780._Ptr;
                  iVar27 = SecondsToTurns(300.0);
                  (_Var23._Ptr)->IdleTime = iVar27 + BZ1Helper::m_TurnCounter;
                  if (cStack_779 == '\0') goto LAB_4fc22b69;
                  uStack_778 = *(float *)pvVar32;
                  std::_Iterator_base0::_Adopt((_Iterator_base0 *)&uStack_778,pvVar32);
                  pcVar47 = "Index: %d Hunt Task Continuing, Re-Issueing Hunt Command. IdleTime: %d"
                  ;
                  goto LAB_4fc20e4b;
                }
                if ((iVar27 == 5) && ((byte)local_750 == '\0')) {
                  fVar44 = GetRandomFloat(1.0);
                  _Var23._Ptr = _Stack_780._Ptr;
                  if (0.5 <= fVar44) {
                    (_Stack_780._Ptr)->DispatchType = 0;
                    ClearDispatch((DispatchHelper *)local_73c._Ptr,(int)pvStack_768);
                    _Var23._Ptr = _Stack_780._Ptr;
                    iVar37 = 0;
                    pDStack_760[0x51] = (DLLBase)(*(int *)(pDStack_760 + 0x51) + -1);
                    iVar27 = GetNearestEnemy((_Stack_780._Ptr)->DispatchObject,true,false,450.0);
                    Attack((_Var23._Ptr)->DispatchObject,iVar27,iVar37);
                    if (cStack_779 != '\0') {
                      uStack_778 = *(float *)pvVar32;
                      std::_Iterator_base0::_Adopt((_Iterator_base0 *)&uStack_778,pvVar32);
                      FormatLogMessage("Index: %d Escort Target lost, Going Bezerk!",
                                       ((int)_Stack_780._Ptr - (int)uStack_778) / 0x148);
                    }
                  }
                  else {
                    iVar27 = UtilityShipHelper::GetEscortTarget
                                       (UtilityShipHelper::m_UtilityShipHelper,(int)local_764,3);
                    *(int *)&(_Var23._Ptr)->DispatchTarget = iVar27;
                    Defend2((_Stack_780._Ptr)->DispatchObject,
                            *(int *)&(_Stack_780._Ptr)->DispatchTarget,0);
                    if (cStack_779 != '\0') {
                      iVar27 = *(int *)&(_Stack_780._Ptr)->DispatchTarget;
                      memset(TempGetODFName,0,0x40);
                      GetODFName(iVar27,TempGetODFName);
                      uStack_710 = *(undefined4 *)pvVar32;
                      std::_Iterator_base0::_Adopt((_Iterator_base0 *)&uStack_710,pvVar32);
                      pcVar47 = "Index: %d Escort Target lost, picking new Target: \'%s\'";
                      goto LAB_4fc20e4b;
                    }
                  }
                }
              }
            }
          }
          else if (iVar27 == 2) {
            if ((_Stack_780._Ptr)->IdleTime <= BZ1Helper::m_TurnCounter) {
              SetIndependence((_Stack_780._Ptr)->DispatchObject,1);
              _Var23._Ptr = _Stack_780._Ptr;
              lVar30 = GetCurHealth((_Stack_780._Ptr)->DispatchObject);
              (_Var23._Ptr)->FleeHealthValue = lVar30;
              ClearDispatch((DispatchHelper *)local_73c._Ptr,(int)pvStack_768);
              _Var23._Ptr = _Stack_780._Ptr;
              iVar27 = SecondsToTurns(15.0);
              (_Var23._Ptr)->IdleTime = iVar27 + BZ1Helper::m_TurnCounter;
              bVar26 = IsAround((_Stack_780._Ptr)->FleeTarget);
              if (bVar26) {
                Attack((_Stack_780._Ptr)->DispatchObject,(_Stack_780._Ptr)->FleeTarget,0);
              }
              if (cStack_779 != '\0') {
                iVar27 = (_Stack_780._Ptr)->FleeTarget;
                memset(TempGetODFName,0,0x40);
                GetODFName(iVar27,TempGetODFName);
                iStack_70c = *(int *)pvStack_76c;
                std::_Iterator_base0::_Adopt((_Iterator_base0 *)&iStack_70c,pvStack_76c);
                pcVar47 = "Index: %d Flee State Ending. Last Target: \'%s\', IdleTime: %d";
LAB_4fc20f48:
                FormatLogMessage(pcVar47);
              }
            }
          }
          else if ((iVar27 - 3U < 2) &&
                  (((((iVar27 == 4 &&
                      (fVar44 = GetHealth((_Stack_780._Ptr)->DispatchObject),
                      (_Var23._Ptr)->GetRepairRatio < fVar44)) ||
                     ((_Var23._Ptr = _Stack_780._Ptr, (_Stack_780._Ptr)->DispatchState == 3 &&
                      (lVar30 = GetCurAmmo((_Stack_780._Ptr)->DispatchObject),
                      (_Var23._Ptr)->MinFireAmmo < lVar30)))) ||
                    ((_Stack_780._Ptr)->IdleTime <= BZ1Helper::m_TurnCounter)) ||
                   ((((_Stack_780._Ptr)->DispatchType != 1 && ((_Stack_780._Ptr)->DispatchType != 6)
                     ) && ((byte)local_750 == '\0')))))) {
            if (cStack_779 != '\0') {
              iVar27 = (_Stack_780._Ptr)->DispatchObject;
              memset(TempGetODFName,0,0x40);
              GetODFName(iVar27,TempGetODFName);
              iStack_714 = *(int *)pvVar32;
              std::_Iterator_base0::_Adopt((_Iterator_base0 *)&iStack_714,pvVar32);
              FormatLogMessage("Index: %d Unit: \'%s\' Rearmed/Repaired, resuming duties",
                               ((int)_Stack_780._Ptr - iStack_714) / 0x148,TempGetODFName);
            }
            SetIndependence((_Stack_780._Ptr)->DispatchObject,1);
            ClearDispatch((DispatchHelper *)local_73c._Ptr,(int)pvStack_768);
            _Var23._Ptr = _Stack_780._Ptr;
            iVar27 = SecondsToTurns(15.0);
            (_Var23._Ptr)->IdleTime = iVar27 + BZ1Helper::m_TurnCounter;
            if (cStack_779 != '\0') {
              uStack_778 = *(float *)pvVar32;
              std::_Iterator_base0::_Adopt((_Iterator_base0 *)&uStack_778,pvVar32);
              pcVar47 = "Index is: %d Repair/Repaid finished, IdleTime: %d";
              goto LAB_4fc20e4b;
            }
          }
LAB_4fc22b69:
          _Var23._Ptr = _Stack_780._Ptr;
          (_Stack_780._Ptr)->ServiceTimer = (_Stack_780._Ptr)->ServiceTimer + -1;
          if ((_Stack_780._Ptr)->ServiceTimer < 0) {
            iVar27 = SecondsToTurns(10.0);
            (_Var23._Ptr)->ServiceTimer = iVar27;
          }
          _Var23._Ptr = _Stack_780._Ptr;
          pvVar29 = pvStack_76c;
          if (((*(bool *)((int)(pDStack_760 + 0x6b) + 1) != false) &&
              ((_Stack_780._Ptr)->ServiceTimer < 1)) &&
             (((_Stack_780._Ptr)->DispatchState != 4 && ((_Stack_780._Ptr)->DispatchState != 3)))) {
            pDVar43 = pDStack_760;
            if (((_Stack_780._Ptr)->CanGetRepair != false) &&
               (fVar44 = GetHealth((_Stack_780._Ptr)->DispatchObject), pDVar43 = pDStack_760,
               fVar44 < (_Var23._Ptr)->GetRepairRatio)) {
              if ((((_Stack_780._Ptr)->DispatchType == 1) || ((_Stack_780._Ptr)->DispatchType == 6))
                 && (bVar26 = IsDeployed((_Stack_780._Ptr)->DispatchObject), bVar26)) {
                pDVar43 = pDStack_760;
                if (*(int *)(pDStack_760 + 0x29) != 0) {
                  memset(acStack_94,0,0x40);
                  bVar26 = GetBuildItem(0,(char *)0x1,(int *)0x0,0,(char *)0x0,(char *)_Last._Ptr,
                                        (char *)unaff_EDI);
                  pDVar43 = pDStack_760;
                  if ((bVar26) &&
                     (iVar27 = (*misnImport.GetScrap)((int)local_764), pDVar43 = pDStack_760,
                     -1 < iVar27)) {
                    VVar18.y = VStack_734.y;
                    VVar18.x = VStack_734.x;
                    VVar18.z = VStack_734.z;
                    BZ1Helper::BuildAt(local_754,*(int *)(pDStack_760 + 0x29),acStack_94,VVar18,1);
                    (_Stack_780._Ptr)->DispatchState = 4;
                    iVar27 = SecondsToTurns(60.0);
                    _Var23._Ptr = _Stack_780._Ptr;
                    if ((_Stack_780._Ptr)->IdleTime < iVar27 + BZ1Helper::m_TurnCounter) {
                      (_Stack_780._Ptr)->IdleTime = iVar27 + BZ1Helper::m_TurnCounter;
                    }
                    if (cStack_779 != '\0') {
                      uStack_774 = (double)CONCAT44(uStack_774._4_4_,*(int *)pvStack_76c);
                      std::_Iterator_base0::_Adopt((_Iterator_base0 *)&uStack_774,pvStack_76c);
                      FormatLogMessage("Index is: %d Deployable Waiting for Repair Powerup to land, IdleTime: %d"
                                       ,((int)_Stack_780._Ptr - (int)(DispatchClass *)uStack_774) /
                                        0x148,(_Var23._Ptr)->IdleTime);
                    }
                  }
                }
              }
              else {
                _Var23._Ptr = _Stack_780._Ptr;
                fVar44 = GetRandomFloat(1.0);
                pDVar43 = pDStack_760;
                if (fVar44 < (_Var23._Ptr)->ServiceChance) {
                  VVar3.y = VStack_734.y;
                  VVar3.x = VStack_734.x;
                  VVar3.z = VStack_734.z;
                  iVar27 = BuildingHelper::GetNearestServiceObject
                                     (BuildingHelper::m_BuildingHelper,1,VVar3,0.0,-1,0,true,true,
                                      true,0,0,(char *)0x0,(char *)0x0);
                  uStack_774 = (double)CONCAT44(uStack_774._4_4_,iVar27);
                  pDVar43 = pDStack_760;
                  if (iVar27 != 0) {
                    pvVar32 = pvStack_76c;
                    if (cStack_779 != '\0') {
                      iVar27 = (_Stack_780._Ptr)->DispatchObject;
                      memset(TempGetODFName,0,0x40);
                      GetODFName(iVar27,TempGetODFName);
                      pvVar32 = pvStack_76c;
                      local_720 = *(int *)pvStack_76c;
                      std::_Iterator_base0::_Adopt((_Iterator_base0 *)&local_720,pvStack_76c);
                      FormatLogMessage("Index: %d Unit: \'%s\' going to get Repair",
                                       ((int)_Stack_780._Ptr - local_720) / 0x148,TempGetODFName);
                    }
                    *(DispatchClass **)&(_Stack_780._Ptr)->DispatchTarget =
                         (DispatchClass *)uStack_774;
                    Goto((_Stack_780._Ptr)->DispatchObject,
                         *(int *)&(_Stack_780._Ptr)->DispatchTarget,0);
                    SetIndependence((_Stack_780._Ptr)->DispatchObject,0);
                    _Var23._Ptr = _Stack_780._Ptr;
                    (_Stack_780._Ptr)->DispatchState = 4;
                    iVar27 = SecondsToTurns(300.0);
                    _Var24._Ptr = _Stack_780._Ptr;
                    (_Var23._Ptr)->IdleTime = iVar27 + BZ1Helper::m_TurnCounter;
                    pDVar43 = pDStack_760;
                    if (cStack_779 != '\0') {
                      uStack_774 = (double)CONCAT44(uStack_774._4_4_,*(int *)pvVar32);
                      std::_Iterator_base0::_Adopt((_Iterator_base0 *)&uStack_774,pvVar32);
                      FormatLogMessage("Index is: %d Unit going to Repair Service, IdleTime: %d",
                                       ((int)_Stack_780._Ptr - (int)(DispatchClass *)uStack_774) /
                                       0x148,(_Var24._Ptr)->IdleTime);
                      pDVar43 = pDStack_760;
                    }
                  }
                }
              }
            }
            pvVar29 = pvStack_76c;
            if (((_Stack_780._Ptr)->CanGetReload != false) &&
               (fVar44 = GetAmmo((_Stack_780._Ptr)->DispatchObject), _Var23._Ptr = _Stack_780._Ptr,
               pvVar29 = pvStack_76c, fVar44 < 1.0)) {
              lVar30 = GetMinFireAmmo((_Stack_780._Ptr)->DispatchObject);
              _Var24._Ptr = _Stack_780._Ptr;
              (_Var23._Ptr)->MinFireAmmo = lVar30;
              lVar30 = GetCurAmmo((_Stack_780._Ptr)->DispatchObject);
              pvVar29 = pvStack_76c;
              if (lVar30 < (_Var24._Ptr)->MinFireAmmo) {
                if ((((_Stack_780._Ptr)->DispatchType == 1) ||
                    ((_Stack_780._Ptr)->DispatchType == 6)) &&
                   (bVar26 = IsDeployed((_Stack_780._Ptr)->DispatchObject), bVar26)) {
                  pvVar29 = pvStack_76c;
                  if (*(int *)(pDVar43 + 0x29) != 0) {
                    memset(acStack_54,0,0x40);
                    bVar26 = GetBuildItem(0,(char *)0x2,(int *)0x0,0,(char *)0x0,(char *)_Last._Ptr,
                                          (char *)unaff_EDI);
                    pvVar29 = pvStack_76c;
                    if ((bVar26) &&
                       (iVar27 = (*misnImport.GetScrap)((int)local_764), pvVar29 = pvStack_76c,
                       -1 < iVar27)) {
                      VVar19.y = VStack_734.y;
                      VVar19.x = VStack_734.x;
                      VVar19.z = VStack_734.z;
                      BZ1Helper::BuildAt(local_754,*(int *)(pDStack_760 + 0x29),acStack_54,VVar19,1)
                      ;
                      (_Stack_780._Ptr)->DispatchState = 3;
                      iVar27 = SecondsToTurns(60.0);
                      pvVar32 = pvStack_76c;
                      if ((_Stack_780._Ptr)->IdleTime < iVar27 + BZ1Helper::m_TurnCounter) {
                        (_Stack_780._Ptr)->IdleTime = iVar27 + BZ1Helper::m_TurnCounter;
                      }
                      pvVar29 = pvStack_76c;
                      if (cStack_779 != '\0') {
                        uStack_774 = (double)CONCAT44(uStack_774._4_4_,*(int *)pvStack_76c);
                        std::_Iterator_base0::_Adopt((_Iterator_base0 *)&uStack_774,pvStack_76c);
                        pcVar47 = 
                        "Index is: %d Deployable Waiting for Reload Powerup to land, IdleTime: %d";
                        goto LAB_4fc22fb1;
                      }
                    }
                  }
                }
                else {
                  VVar4.y = VStack_734.y;
                  VVar4.x = VStack_734.x;
                  VVar4.z = VStack_734.z;
                  iVar27 = BuildingHelper::GetNearestServiceObject
                                     (BuildingHelper::m_BuildingHelper,2,VVar4,0.0,-1,0,true,true,
                                      true,0,0,(char *)0x0,(char *)0x0);
                  uStack_774 = (double)CONCAT44(uStack_774._4_4_,iVar27);
                  pvVar29 = pvStack_76c;
                  if (iVar27 != 0) {
                    pvVar32 = pvStack_76c;
                    if (cStack_779 != '\0') {
                      iVar27 = (_Stack_780._Ptr)->DispatchObject;
                      memset(TempGetODFName,0,0x40);
                      GetODFName(iVar27,TempGetODFName);
                      pvVar32 = pvStack_76c;
                      iStack_740 = *(int *)pvStack_76c;
                      std::_Iterator_base0::_Adopt((_Iterator_base0 *)&iStack_740,pvStack_76c);
                      FormatLogMessage("Index: %d Unit: \'%s\' going to get Reload",
                                       ((int)_Stack_780._Ptr - iStack_740) / 0x148,TempGetODFName);
                    }
                    *(DispatchClass **)&(_Stack_780._Ptr)->DispatchTarget =
                         (DispatchClass *)uStack_774;
                    Goto((_Stack_780._Ptr)->DispatchObject,
                         *(int *)&(_Stack_780._Ptr)->DispatchTarget,0);
                    SetIndependence((_Stack_780._Ptr)->DispatchObject,0);
                    _Var23._Ptr = _Stack_780._Ptr;
                    (_Stack_780._Ptr)->DispatchState = 3;
                    iVar27 = SecondsToTurns(30.0);
                    (_Var23._Ptr)->IdleTime = iVar27 + BZ1Helper::m_TurnCounter;
                    pvVar29 = pvStack_76c;
                    if (cStack_779 != '\0') {
                      uStack_774 = (double)CONCAT44(uStack_774._4_4_,*(int *)pvVar32);
                      std::_Iterator_base0::_Adopt((_Iterator_base0 *)&uStack_774,pvVar32);
                      pcVar47 = "Index is: %d Unit going to Reload Service, IdleTime: %d";
LAB_4fc22fb1:
                      FormatLogMessage(pcVar47);
                      pvVar29 = pvVar32;
                    }
                  }
                }
              }
            }
          }
        }
        _Var23._Ptr = _Stack_780._Ptr;
        if ((_Stack_780._Ptr)->IsCloaker != false) {
          if ((_Stack_780._Ptr)->IsCloaked == false) {
            if ((_Stack_780._Ptr)->CloakNextTick == false) {
              if ((((_Stack_780._Ptr)->SkipAIPCheck != false) ||
                  (*(bool *)((int)(pDStack_760 + 0x6b) + 2) != false)) &&
                 (((((_Stack_780._Ptr)->CloakIdleTime <= BZ1Helper::m_TurnCounter ||
                    (AVar36 = GetCurrentCommand((_Stack_780._Ptr)->DispatchObject),
                    AVar36 != (_Var23._Ptr)->Command)) &&
                   ((iVar27 = GetPlayerHandle((int)local_764), iVar27 == 0 &&
                    (local_750._3_1_ == '\x01')))) && ((_Stack_780._Ptr)->CloakPriority == 0)))) {
                fVar44 = GetRandomFloat(1.0);
                dStack_74c = (double)CONCAT44(dStack_74c._4_4_,fVar44);
                iVar27 = (*misnImport.GetNearestEnemy)((_Stack_780._Ptr)->DispatchObject);
                uStack_774 = (double)CONCAT44(uStack_774._4_4_,iVar27);
                bVar26 = IsDeployed((_Stack_780._Ptr)->DispatchObject);
                if ((!bVar26) || ((_Stack_780._Ptr)->IsMorpher != false)) {
                  if ((DispatchClass *)uStack_774 != (DispatchClass *)0x0) {
                    GetPosition((int)(DispatchClass *)uStack_774,&VStack_570);
                    uStack_774 = (double)(_Stack_780._Ptr)->EngageRange;
                    fVar46 = GetDistance3DSquared(&VStack_734,&VStack_570);
                    fVar44 = (float)((float10)uStack_774 * (float10)uStack_774);
                    uStack_774 = (double)CONCAT44(uStack_774._4_4_,fVar44);
                    if (fVar46 <= fVar44) goto LAB_4fc236d5;
                  }
                  _Var23._Ptr = _Stack_780._Ptr;
                  if (cStack_779 == '\0') {
                    dStack_74c = (double)(float)dStack_74c._0_4_;
                  }
                  else {
                    uStack_774 = (double)CONCAT44(uStack_774._4_4_,*(undefined4 *)pvVar29);
                    std::_Iterator_base0::_Adopt((_Iterator_base0 *)&uStack_774,pvVar29);
                    iVar27 = (_Var23._Ptr)->Command;
                    dVar48 = (double)(float)dStack_74c._0_4_;
                    dStack_74c = (double)(float)dStack_74c._0_4_;
                    FormatLogMessage("Index: %d AI Attempting to Cloak unit, Chance: %f, CloakCommand: %d Chance: %f"
                                     ,((int)_Stack_780._Ptr - (int)(DispatchClass *)uStack_774) /
                                      0x148,dVar48,iVar27,
                                     (double)CONCAT44(_Last._Ptr,
                                                      (int)((ulonglong)
                                                            (double)(_Var23._Ptr)->CloakChance
                                                                    [iVar27] >> 0x20)));
                  }
                  _Var23._Ptr = _Stack_780._Ptr;
                  AVar36 = GetCurrentCommand((_Stack_780._Ptr)->DispatchObject);
                  if (dStack_74c < (double)(_Var23._Ptr)->CloakChance[AVar36]) {
                    if (cStack_779 != '\0') {
                      uStack_774 = (double)CONCAT44(uStack_774._4_4_,*(undefined4 *)pvVar29);
                      std::_Iterator_base0::_Adopt((_Iterator_base0 *)&uStack_774,pvVar29);
                      FormatLogMessage("Index: %d AI Cloak Successful",
                                       ((int)_Stack_780._Ptr - (int)(DispatchClass *)uStack_774) /
                                       0x148);
                    }
                    Cloak((DispatchHelper *)local_73c._Ptr,(_Stack_780._Ptr)->DispatchObject,
                          (_Stack_780._Ptr)->CloakPriority);
                  }
                  _Var23._Ptr = _Stack_780._Ptr;
                  iVar27 = SecondsToTurns(15.0);
                  (_Var23._Ptr)->CloakIdleTime = iVar27 + BZ1Helper::m_TurnCounter;
                }
              }
            }
            else {
              bVar26 = IsDeployed((_Stack_780._Ptr)->DispatchObject);
              if (!bVar26) {
                SetCommand((_Stack_780._Ptr)->DispatchObject,0x2f,0,0,(char *)0x0,0);
                _Var23._Ptr = _Stack_780._Ptr;
                iVar27 = SecondsToTurns((_Stack_780._Ptr)->TimeDeploy);
                _Var24._Ptr = _Stack_780._Ptr;
                (_Var23._Ptr)->DeployTimer = iVar27 + BZ1Helper::m_TurnCounter + 1;
                (_Stack_780._Ptr)->CloakLocked = true;
                if (cStack_779 != '\0') {
                  uStack_774 = (double)CONCAT44(uStack_774._4_4_,*(undefined4 *)pvVar29);
                  std::_Iterator_base0::_Adopt((_Iterator_base0 *)&uStack_774,pvVar29);
                  FormatLogMessage("Index: %d Cloaking Activating, Time: %d, DeployTimer: %d, DeployTime: %f"
                                   ,((int)_Stack_780._Ptr - (int)(DispatchClass *)uStack_774) /
                                    0x148,BZ1Helper::m_TurnCounter,(_Var24._Ptr)->DeployTimer,
                                   (double)(_Var24._Ptr)->TimeDeploy);
                }
              }
              (_Stack_780._Ptr)->IsCloaked = true;
              (_Stack_780._Ptr)->CloakNextTick = false;
            }
          }
          else {
            bVar26 = IsDeployed((_Stack_780._Ptr)->DispatchObject);
            if (bVar26) {
              if ((_Stack_780._Ptr)->DecloakNextTick == false) {
                if (((local_750._3_1_ == '\x01') && ((_Stack_780._Ptr)->CloakPriority == 0)) &&
                   (iVar27 = (*misnImport.GetNearestEnemy)((_Stack_780._Ptr)->DispatchObject),
                   (_Stack_780._Ptr)->CloakLocked != false)) {
                  uStack_774 = (double)(_Stack_780._Ptr)->EngageRange;
                  fVar46 = GetDistance3DSquared((_Stack_780._Ptr)->DispatchObject,iVar27);
                  fVar44 = (float)((float10)uStack_774 * (float10)uStack_774);
                  uStack_774 = (double)CONCAT44(uStack_774._4_4_,fVar44);
                  if (fVar46 < fVar44) {
                    if (cStack_779 != '\0') {
                      uStack_774 = (double)CONCAT44(uStack_774._4_4_,*(undefined4 *)pvVar29);
                      std::_Iterator_base0::_Adopt((_Iterator_base0 *)&uStack_774,pvVar29);
                      FormatLogMessage("Index: %d Unit is Cloaked, Enemy detected, Unlocking Cloak",
                                       ((int)_Stack_780._Ptr - (int)(DispatchClass *)uStack_774) /
                                       0x148);
                    }
                    SetCommand((_Stack_780._Ptr)->DispatchObject,0x31,0,0,(char *)0x0,0);
                    (_Stack_780._Ptr)->CloakLocked = false;
                  }
                }
                AVar36 = GetCurrentCommand((_Stack_780._Ptr)->DispatchObject);
                if (AVar36 == CMD_ATTACK) {
                  GetPosition((int)_Stack_71c._Ptr,&VStack_564);
                  fVar44 = GetDistance3DSquared(&VStack_734,&VStack_564);
                  uStack_774 = (double)fVar44;
                  pDVar34 = std::
                            _Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                            ::operator->((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                          *)&_Stack_780);
                  fVar44 = Squared<float>(pDVar34->EngageRange);
                  if ((float)uStack_774 < fVar44) {
                    if (cStack_779 != '\0') {
                      _Last._Ptr = (DispatchClass *)auStack_634;
                      _Var28 = std::
                               vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
                               ::begin(pvVar29);
                      iVar27 = std::
                               _Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                               ::operator-((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                            *)&stack0xfffff87c,
                                           (_Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                            *)_Var28);
                      FormatLogMessage("Index: %d Unit is Cloaked, Target In Range, Decloaking",
                                       iVar27);
                    }
                    std::
                    _Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                    ::operator->((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                  *)&_Stack_780);
                    pDVar34 = std::
                              _Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                              ::operator->((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                            *)&_Stack_780);
                    iVar27 = pDVar34->DispatchObject;
                    bVar26 = IsAround(iVar27);
                    if (bVar26) {
                      Decloak((DispatchHelper *)local_73c._Ptr,iVar27,(int)_Last._Ptr);
                    }
                    pDVar34 = std::
                              _Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                              ::operator->((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                            *)&_Stack_780);
                    pDVar34->CloakLocked = false;
                  }
                }
              }
              else {
                SetCommand(0x4fc233e0,0x30,0,0,(char *)0x0,0);
                (_Stack_780._Ptr)->DecloakNextTick = false;
              }
            }
            else {
              pDVar34 = std::
                        _Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                        ::operator->((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                      *)&_Stack_780);
              if (pDVar34->DeployTimer < BZ1Helper::m_TurnCounter) {
                pDVar34 = std::
                          _Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                          ::operator->((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                        *)&_Stack_780);
                if (((pDVar34->SkipAIPCheck != false) ||
                    (pvVar32 = pvStack_76c, *(bool *)((int)(pDStack_760 + 0x6b) + 2) != false)) &&
                   (iVar27 = GetPlayerHandle((int)local_764), pvVar32 = pvStack_76c, iVar27 == 0)) {
                  pDVar34 = std::
                            _Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                            ::operator->((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                          *)&_Stack_780);
                  pDVar35 = std::
                            _Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                            ::operator->((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                          *)&_Stack_780);
                  AVar36 = GetCurrentCommand(pDVar34->DispatchObject);
                  pvVar32 = pvStack_76c;
                  if (AVar36 == pDVar35->Command) {
                    if (cStack_779 != '\0') {
                      _Last._Ptr = (DispatchClass *)auStack_63c;
                      _Var28 = std::
                               vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
                               ::begin(pvStack_76c);
                      iVar27 = std::
                               _Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                               ::operator-((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                            *)&stack0xfffff87c,
                                           (_Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                            *)_Var28);
                      FormatLogMessage("Index: %d Command Identicle, setting CloakIdle time for 15 seconds."
                                       ,iVar27);
                    }
                    iVar27 = SecondsToTurns(15.0);
                    iVar27 = BZ1Helper::m_TurnCounter + iVar27;
                    pDVar34 = std::
                              _Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                              ::operator->((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                            *)&_Stack_780);
                    pDVar34->CloakIdleTime = iVar27;
                  }
                  else {
                    if (cStack_779 != '\0') {
                      _Last._Ptr = (DispatchClass *)(auStack_63c + 4);
                      _Var28 = std::
                               vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
                               ::begin(pvStack_76c);
                      iVar27 = std::
                               _Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                               ::operator-((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                            *)&stack0xfffff87c,
                                           (_Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                            *)_Var28);
                      FormatLogMessage("Index: %d Command Different, Setting CloakIdle time for NOW."
                                       ,iVar27);
                    }
                    pDVar34 = std::
                              _Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                              ::operator->((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                            *)&_Stack_780);
                    pDVar34->CloakIdleTime = BZ1Helper::m_TurnCounter;
                  }
                }
                pDVar34 = std::
                          _Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                          ::operator->((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                        *)&_Stack_780);
                pDVar34->IsCloaked = false;
                if (cStack_779 != '\0') {
                  pDVar34 = std::
                            _Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                            ::operator->((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                          *)&_Stack_780);
                  dVar48 = (double)pDVar34->TimeDeploy;
                  iVar37 = BZ1Helper::m_TurnCounter;
                  pDVar34 = std::
                            _Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                            ::operator->((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                          *)&_Stack_780);
                  iVar27 = pDVar34->DeployTimer;
                  fmtarg2 = auStack_6bc;
                  _Var28 = std::
                           vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
                           ::begin(pvVar32);
                  iVar33 = std::
                           _Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                           ::operator-((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                        *)&stack0xfffff87c,
                                       (_Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                        *)_Var28);
                  FormatLogMessage("Index: %d Unit was not cloaked! DeployTimer: %d, Time: %d, DeployTime: %f, Time: %d"
                                   ,iVar33,(int)fmtarg2,iVar27,
                                   (double)CONCAT44(SUB84(dVar48,0),iVar37),
                                   (int)((ulonglong)dVar48 >> 0x20));
                }
              }
            }
          }
        }
LAB_4fc236d5:
        pDVar34 = std::
                  _Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                  ::operator->((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                *)&_Stack_780);
        pDVar35 = std::
                  _Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                  ::operator->((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                *)&_Stack_780);
        AVar36 = GetCurrentCommand(pDVar34->DispatchObject);
        pvVar32 = pvStack_76c;
        if (AVar36 != pDVar35->Command) {
          pDVar34 = std::
                    _Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                    ::operator->((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                  *)&_Stack_780);
          AVar36 = GetCurrentCommand(pDVar34->DispatchObject);
          pDVar34 = std::
                    _Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                    ::operator->((_Vector_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                                  *)&_Stack_780);
          pDVar34->Command = AVar36;
          pvVar32 = pvStack_76c;
        }
      }
      _Stack_780._Ptr = _Stack_780._Ptr + 1;
      std::
      _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
      ::
      _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
                (&local_738,*(DispatchClass **)&pvVar32->field_0x4,(_Container_base0 *)pvVar32);
    } while (_Stack_780._Ptr != local_738._Ptr);
  }
  return;
}


// ---------------------------------------------------------------------
// DispatchHelper::PreOrdnanceHit  @ 4fc2375b  lines 1860-1939

void __thiscall
DispatchHelper::PreOrdnanceHit
          (DispatchHelper *this,int shooterHandle,int victimHandle,int ordnanceTeam,
          char *pOrdnanceODF)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  long lVar4;
  float unaff_EBX;
  undefined1 unaff_BP;
  int *piVar5;
  float fVar6;
  char *format;
  Vector local_c;
  
  iVar3 = GetIndependence(victimHandle);
  bVar1 = BZ1Helper::Logging;
  if (iVar3 != 0) {
    for (piVar5 = *(int **)&this->DispatchList; piVar5 != *(int **)&(this->DispatchList).field_0x4;
        piVar5 = piVar5 + 0x52) {
      if (victimHandle == *piVar5) {
        if ((piVar5[7] != 1) || (bVar2 = IsDeployed(*piVar5), bVar2)) {
          if ((piVar5[7] == 3) && ((piVar5[8] == 1 || (piVar5[8] == 0)))) {
            SetCommand(*piVar5,0x1b,0,0,(char *)0x0,0);
            piVar5[8] = 0;
            iVar3 = SecondsToTurns(30.0);
            piVar5[0xc] = iVar3 + BZ1Helper::m_TurnCounter;
            if (bVar1 == false) {
              return;
            }
            format = "Index is: %d Minelayer Shot, Mining, IdleTime: %d";
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
            lVar4 = GetCurHealth(*piVar5);
            victimHandle = GetOrdnanceDamageDealt(*piVar5,pOrdnanceODF,true);
            if (piVar5[0x50] - lVar4 < piVar5[0x4d] / 10) {
              return;
            }
            iVar3 = victimHandle * 4;
            if (victimHandle * 4 < lVar4) {
              iVar3 = lVar4;
            }
            fVar6 = GetRandomFloat((float)iVar3);
            pOrdnanceODF = (char *)(float)victimHandle;
            if ((float)pOrdnanceODF <= fVar6) {
              return;
            }
            fVar6 = GetRandomFloat(2.0);
            pOrdnanceODF = (char *)(fVar6 + 3.0);
            iVar3 = SecondsToTurns((float)pOrdnanceODF);
            piVar5[0xc] = iVar3 + BZ1Helper::m_TurnCounter;
            iVar3 = GetTarget(*piVar5);
            piVar5[2] = iVar3;
            victimHandle = victimHandle & 0xffffff00;
            GetODFBool(*piVar5,"CraftClass","RetargetOnStrafe",(bool *)&victimHandle,false);
            if ((piVar5[2] == 0) && ((char)victimHandle != '\0')) {
              piVar5[2] = shooterHandle;
            }
            SetIndependence(*piVar5,0);
            GetPositionNearOrFar
                      ((Vector *)shooterHandle,0x42200000,0x42960000,0.0,unaff_EBX,(bool)unaff_BP);
            Goto(*piVar5,&local_c,0);
            if ((*(char *)((int)piVar5 + 0x25) != '\0') &&
               (fVar6 = GetRandomFloat(1.0), fVar6 < 0.5)) {
              Deploy(*piVar5);
            }
            piVar5[8] = 2;
            if (bVar1 == false) {
              return;
            }
            GetODFName(*piVar5);
            format = "Flee Target Shot, Target is: \'%s\', IdleTime: %d";
          }
        }
        else {
          Defend(*piVar5,0);
          piVar5[8] = 0;
          iVar3 = SecondsToTurns(30.0);
          piVar5[0xc] = iVar3 + BZ1Helper::m_TurnCounter;
          if (bVar1 == false) {
            return;
          }
          format = "Index is: %d Turret Shot, Deploying, IdleTime: %d";
        }
        FormatLogMessage(format);
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
  char **ppcVar2;
  
  bVar1 = OpenODF2(param_1);
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

void __thiscall DispatchHelper::Cloak(DispatchHelper *this,int h,int Priority)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  
  bVar2 = BZ1Helper::Logging;
  bVar1 = IsAround(h);
  if (bVar1) {
    piVar4 = *(int **)&MorphObjectHelper::m_MorphObjectHelper->MorphObjectList;
    iVar3 = (*(int *)&(MorphObjectHelper::m_MorphObjectHelper->MorphObjectList).field_0x4 -
            (int)piVar4) / 0x148;
    iVar5 = 0;
    if (0 < iVar3) {
      do {
        if ((*piVar4 == h) && (*(char *)((int)piVar4 + 0xb) != '\0')) {
          SetCommand(h,0x15,0,0,(char *)0x0,0);
          return;
        }
        iVar5 = iVar5 + 1;
        piVar4 = piVar4 + 0x52;
      } while (iVar5 < iVar3);
    }
    for (piVar4 = *(int **)&this->DispatchList; piVar4 != *(int **)&(this->DispatchList).field_0x4;
        piVar4 = piVar4 + 0x52) {
      if (*piVar4 == h) {
        bVar1 = IsPlayer(h);
        if (!bVar1) {
          piVar4[0x51] = Priority;
          *(undefined1 *)((int)piVar4 + 0x2d) = 1;
          if (!bVar2) {
            return;
          }
          FormatLogMessage("Cloak Command Given, Time: %d",BZ1Helper::m_TurnCounter);
          return;
        }
        bVar2 = IsDeployed(h);
        if (bVar2) {
          return;
        }
        Deploy(h);
        return;
      }
    }
    AddToDispatch(this,h,0.0,true,Priority,true,true,false,false);
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

void __thiscall DispatchHelper::ClearDispatch(DispatchHelper *this,int Index)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int Object [82];
  
  piVar3 = (int *)(Index * 0x148 + *(int *)&this->DispatchList);
  piVar4 = Object;
  for (iVar2 = 0x52; iVar2 != 0; iVar2 = iVar2 + -1) {
    *piVar4 = *piVar3;
    piVar3 = piVar3 + 1;
    piVar4 = piVar4 + 1;
  }
  bVar1 = IsPlayer(Object[0]);
  if (!bVar1) {
    SetCommand(Object[0],0,0,0,(char *)0x0,0);
  }
  return;
}


