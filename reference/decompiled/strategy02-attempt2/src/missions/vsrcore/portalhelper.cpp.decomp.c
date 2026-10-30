// Reconstructed by Ghidra from Strategy02.dll + Strategy02.pdb
// Original source file: /e:/github/vsr_dll_source/missions/vsrcore/portalhelper.cpp
// Functions are ordered by original source line. This is decompiler
// output, not the author's source: names/types come from the PDB,
// local variable names and control flow are reconstructed.

// ---------------------------------------------------------------------
// `dynamic_initializer_for_'TempPortalBuffer''  @ 4fc01ad1  lines 10-10

void __cdecl _dynamic_initializer_for__TempPortalBuffer__(void)

{
  atexit(_dynamic_atexit_destructor_for__TempPortalBuffer__);
  return;
}


// ---------------------------------------------------------------------
// `dynamic_initializer_for_'TempTeleportTargetBuffer''  @ 4fc01add  lines 11-11

void __cdecl _dynamic_initializer_for__TempTeleportTargetBuffer__(void)

{
  atexit(_dynamic_atexit_destructor_for__TempTeleportTargetBuffer__);
  return;
}


// ---------------------------------------------------------------------
// PortalHelper::Load  @ 4fc278a9  lines 26-50

bool __thiscall PortalHelper::Load(PortalHelper *this,bool param_1)

{
  vector<PortalHelper::TeleportTargetClass,std::allocator<PortalHelper::TeleportTargetClass>_>
  *_Udefault_or_fill;
  bool bVar1;
  PortalHelper *extraout_ECX;
  PortalHelper *this_00;
  PortalHelper *size;
  
  this_00 = this;
  size = this;
  if (this != (PortalHelper *)&TempPortalBuffer) {
    std::vector<PortalHelper::PortalClass,std::allocator<PortalHelper::PortalClass>_>::
    _Assign_range<PortalHelper::PortalClass_*>
              (&this->PortalList,*(PortalClass **)&this->PortalList,
               *(PortalClass **)&(this->PortalList).field_0x4,SUB41(this,0));
    this_00 = extraout_ECX;
  }
  _Udefault_or_fill = &this->TeleportTargetList;
  if (_Udefault_or_fill != &TempTeleportTargetBuffer) {
    std::
    vector<PortalHelper::TeleportTargetClass,std::allocator<PortalHelper::TeleportTargetClass>_>::
    _Assign_range<PortalHelper::TeleportTargetClass_*>
              ((vector<PortalHelper::TeleportTargetClass,std::allocator<PortalHelper::TeleportTargetClass>_>
                *)this_00,*(TeleportTargetClass **)_Udefault_or_fill,
               *(TeleportTargetClass **)&(this->TeleportTargetList).field_0x4,SUB41(size,0));
  }
  size = (PortalHelper *)0x0;
  bVar1 = Read((int *)&size,1);
  std::vector<PortalHelper::PortalClass,std::allocator<PortalHelper::PortalClass>_>::
  _Resize<<lambda_f1b37303f98cb6f7ff8a0c469c587af2>_>
            (&this->PortalList,(uint)size,(<lambda_f1b37303f98cb6f7ff8a0c469c587af2>)this);
  if (size == (PortalHelper *)0x0) {
LAB_4fc27929:
    size = (PortalHelper *)0x0;
    if (bVar1 != false) goto LAB_4fc27931;
  }
  else {
    if ((!bVar1) || (bVar1 = Read(*(void **)&this->PortalList,(int)size * 0x390), !bVar1)) {
      bVar1 = false;
      goto LAB_4fc27929;
    }
LAB_4fc27931:
    size = (PortalHelper *)0x0;
    bVar1 = Read((int *)&size,1);
    if (bVar1) {
      bVar1 = true;
      goto LAB_4fc27949;
    }
  }
  bVar1 = false;
LAB_4fc27949:
  std::vector<PortalHelper::TeleportTargetClass,std::allocator<PortalHelper::TeleportTargetClass>_>
  ::_Resize<<lambda_f2c0a61063d8731356913bf41ed3079e>_>
            (_Udefault_or_fill,(uint)size,
             (<lambda_f2c0a61063d8731356913bf41ed3079e>)_Udefault_or_fill);
  if (size != (PortalHelper *)0x0) {
    if ((bVar1 == false) || (bVar1 = Read(*(void **)_Udefault_or_fill,(int)size * 0x14), !bVar1)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
  }
  return bVar1;
}


// ---------------------------------------------------------------------
// PortalHelper::PostLoad  @ 4fc2797e  lines 53-101

bool __thiscall PortalHelper::PostLoad(PortalHelper *this,bool param_1)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int fmtarg1;
  int *piVar5;
  int fmtarg1_00;
  
  for (piVar5 = *(int **)&this->PortalList; piVar2 = *(int **)&(this->PortalList).field_0x4,
      piVar5 != piVar2; piVar5 = piVar5 + 0xe4) {
    ConvertHandles(piVar5,1);
    ConvertHandles(piVar5 + 1,1);
    ConvertHandles(piVar5 + 3,1);
    iVar3 = piVar5[3];
    if (iVar3 != 0) {
      piVar5[9] = iVar3;
    }
  }
  piVar5 = *(int **)&this->TeleportTargetList;
  if (piVar5 != *(int **)&(this->TeleportTargetList).field_0x4) {
    do {
      ConvertHandles(piVar5,1);
      ConvertHandles(piVar5 + 1,1);
      piVar5 = piVar5 + 5;
    } while (piVar5 != *(int **)&(this->TeleportTargetList).field_0x4);
    piVar2 = *(int **)&(this->PortalList).field_0x4;
  }
  fmtarg1_00 = 0;
  iVar3 = ((int)piVar2 - *(int *)&this->PortalList) / 0x390;
  iVar4 = (int)(TempPortalBuffer._4_4_ - TempPortalBuffer._0_4_) / 0x390;
  if (iVar4 == iVar3) {
    iVar4 = 0;
    if (0 < iVar3) {
      iVar3 = 0;
      do {
        bVar1 = ::operator==((PortalClass *)(TempPortalBuffer._0_4_ + iVar3),
                             (PortalClass *)(*(int *)&this->PortalList + iVar3));
        if (!bVar1) {
          FormatLogMessage("PortalList Index Mismatch: %d",iVar4);
          break;
        }
        iVar4 = iVar4 + 1;
        iVar3 = iVar3 + 0x390;
      } while (iVar4 < (*(int *)&(this->PortalList).field_0x4 - *(int *)&this->PortalList) / 0x390);
    }
  }
  else {
    FormatLogMessage("PortalList Size Mismatch! Old: %d New: %d",iVar4,iVar3);
  }
  iVar3 = *(int *)&this->TeleportTargetList;
  iVar4 = (*(int *)&(this->TeleportTargetList).field_0x4 - iVar3) / 0x14;
  fmtarg1 = (int)(TempTeleportTargetBuffer._4_4_ - TempTeleportTargetBuffer._0_4_) / 0x14;
  if (fmtarg1 == iVar4) {
    if (0 < iVar4) {
      iVar4 = 0;
      do {
        bVar1 = ::operator==((TeleportTargetClass *)(iVar4 + TempTeleportTargetBuffer._0_4_),
                             (TeleportTargetClass *)(iVar4 + iVar3));
        if (!bVar1) {
          FormatLogMessage("TeleportTargetList Index Mismatch: %d",fmtarg1_00);
          return true;
        }
        fmtarg1_00 = fmtarg1_00 + 1;
        iVar3 = *(int *)&this->TeleportTargetList;
        iVar4 = iVar4 + 0x14;
      } while (fmtarg1_00 < (*(int *)&(this->TeleportTargetList).field_0x4 - iVar3) / 0x14);
    }
  }
  else {
    FormatLogMessage("TeleportTargetList Size Mismatch! Old: %d New: %d",fmtarg1,iVar4);
  }
  return true;
}


// ---------------------------------------------------------------------
// PortalHelper::Save  @ 4fc27ace  lines 104-121

bool __thiscall PortalHelper::Save(PortalHelper *this,bool param_1)

{
  bool bVar1;
  int size;
  
  size = (*(int *)&(this->PortalList).field_0x4 - *(int *)&this->PortalList) / 0x390;
  bVar1 = Write(&size,1);
  if (size != 0) {
    if ((bVar1) && (bVar1 = Write(*(void **)&this->PortalList,size * 0x390), bVar1)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
  }
  size = (*(int *)&(this->TeleportTargetList).field_0x4 - *(int *)&this->TeleportTargetList) / 0x14;
  if ((bVar1 == false) || (bVar1 = Write(&size,1), !bVar1)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (size != 0) {
    if ((bVar1 != false) && (bVar1 = Write(*(void **)&this->TeleportTargetList,size * 0x14), bVar1))
    {
      return true;
    }
    bVar1 = false;
  }
  return bVar1;
}


// ---------------------------------------------------------------------
// PortalHelper::AddPortalSwitchObject  @ 4fc27b74  lines 124-148

void __thiscall
PortalHelper::AddPortalSwitchObject(PortalHelper *this,int h,char *TempODF1,char *TempODF2)

{
  int *piVar1;
  int iVar2;
  char *pcVar3;
  int local_4;
  
  iVar2 = -1;
  local_4 = -1;
  GetODFInt(TempODF1,TempODF2,"TeleportalSwitchClass","PortalChannel",&local_4,-1);
  if (-1 < local_4) {
    piVar1 = *(int **)&this->PortalList;
    TempODF1 = (char *)0x7f7fffff;
    if (piVar1 != *(int **)&(this->PortalList).field_0x4) {
      do {
        pcVar3 = (char *)GetDistance3DSquared(h,*piVar1);
        if ((float)pcVar3 < (float)TempODF1) {
          iVar2 = ((int)piVar1 - *(int *)&this->PortalList) / 0x390;
          TempODF1 = pcVar3;
        }
        piVar1 = piVar1 + 0xe4;
      } while (piVar1 != *(int **)&(this->PortalList).field_0x4);
      if (-1 < iVar2) {
        *(int *)(iVar2 * 0x390 + 0x24 + *(int *)&this->PortalList) = local_4;
      }
    }
  }
  BZ1Helper::DeleteAfterDelay(BZ1Helper::m_BZ1Helper,h,0.0);
  return;
}


// ---------------------------------------------------------------------
// PortalHelper::AddPortalObject  @ 4fc27c26  lines 151-359

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall
PortalHelper::AddPortalObject
          (PortalHelper *this,int h,char *TempODF1,char *TempODF2,int BZCClassHash)

{
  int *piVar1;
  undefined1 auVar2 [12];
  undefined1 auVar3 [12];
  bool bVar4;
  int *piVar5;
  long lVar6;
  int iVar7;
  char *pcVar8;
  Matrix *pMVar9;
  char *_Str1;
  bool extraout_CL;
  char cVar10;
  int *piVar11;
  int iVar12;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  float *pfVar13;
  PortalHelper *this_00;
  undefined1 auStack_14c [3];
  char cStack_149;
  int *local_148;
  char *local_144;
  int local_140;
  bool local_139;
  size_t local_138;
  float local_134;
  int *local_130;
  Vector local_12c;
  ulong local_120;
  PortalHelper *local_11c;
  undefined4 local_118;
  undefined4 local_114;
  undefined4 local_110;
  char local_10c [64];
  char local_cc [64];
  char local_8c [64];
  char local_4c [68];
  uint local_8;
  
  local_8 = __security_cookie ^ (uint)auStack_14c;
  iVar12 = -1;
  piVar11 = *(int **)&this->PortalList;
  piVar1 = *(int **)&(this->PortalList).field_0x4;
  local_140 = h;
  local_144 = TempODF2;
  local_138 = 0x390;
  for (piVar5 = piVar11; piVar5 != piVar1; piVar5 = piVar5 + 0xe4) {
    if (*piVar5 == h) {
      iVar12 = ((int)piVar5 - *(int *)&this->PortalList) / 0x390;
      break;
    }
  }
  local_148 = piVar11;
  local_11c = this;
  if (iVar12 < 0) {
    std::vector<PortalHelper::PortalClass,std::allocator<PortalHelper::PortalClass>_>::
    _Resize<<lambda_f1b37303f98cb6f7ff8a0c469c587af2>_>
              (&this->PortalList,((int)piVar1 - *(int *)&this->PortalList) / 0x390 + 1,
               (<lambda_f1b37303f98cb6f7ff8a0c469c587af2>)this);
    piVar11 = *(int **)&this->PortalList;
    iVar12 = (*(int *)&(this->PortalList).field_0x4 - (int)piVar11) / (int)local_138 + -1;
  }
  piVar11 = piVar11 + iVar12 * 0xe4;
  local_130 = piVar11;
  memset(piVar11,0,local_138);
  GetODFFloat(TempODF1,TempODF2,"GameObjectClass","CollisionRadius",(float *)(piVar11 + 0x24),0.0);
  GetODFString(TempODF1,TempODF2,"TeleportalClass","PortalEffect",0x40,(char *)(piVar11 + 0x83),
               (char *)0x0);
  GetODFInt(TempODF1,TempODF2,"TeleportalClass","InEffect",piVar11 + 0x3c,0);
  GetODFInt(TempODF1,TempODF2,"TeleportalClass","OutEffect",piVar11 + 0x3d,0);
  GetODFInt(TempODF1,TempODF2,"TeleportalClass","OnEffect",piVar11 + 0x3e,0);
  GetODFInt(TempODF1,TempODF2,"TeleportalClass","VehInEffect",piVar11 + 0x3f,0);
  GetODFInt(TempODF1,TempODF2,"TeleportalClass","VehOutEffect",piVar11 + 0x40,0);
  GetODFBool(TempODF1,TempODF2,"TeleportalClass","FxOnVehicle",(bool *)((int)piVar11 + 0x1b),false);
  GetODFString(TempODF1,TempODF2,"TeleportalClass","soundActivate",0x40,(char *)(piVar11 + 0xc3),
               (char *)0x0);
  GetODFString(TempODF1,TempODF2,"TeleportalClass","soundDeactivate",0x40,(char *)(piVar11 + 0xd3),
               (char *)0x0);
  local_120 = 0xffff;
  iVar12 = GetODFInt(TempODF1,TempODF2,"GameObjectClass","effectsMask",(int *)&local_120,0);
  if ((iVar12 != 0) && (lVar6 = GetEmitterMask(h), lVar6 == 0xffff)) {
    MaskEmitter(h,local_120);
  }
  local_148 = (int *)0x0;
  piVar11 = piVar11 + 0x93;
  iVar12 = 0;
  do {
    memset(local_4c,0,0x40);
    iVar12 = iVar12 + 1;
    sprintf_s<64>((char (*) [64])local_4c,"EffectName%d",iVar12);
    memset(local_8c,0,0x40);
    iVar7 = GetODFString(TempODF1,TempODF2,"GameObjectClass",local_4c,0x40,local_8c,(char *)0x0);
    if (iVar7 != 0) {
      local_148 = (int *)strrchr(local_8c,0x2e);
      memset(local_10c,0,0x40);
      memset(local_cc,0,0x40);
      local_134 = 0.0;
      if (local_148 == (int *)0x0) {
        sprintf_s<64>(&local_10c,"%s.odf",local_8c);
        bVar4 = OpenODF2(local_10c);
        if (bVar4) {
          pcVar8 = local_8c;
          goto LAB_4fc27fac;
        }
      }
      else {
        strcpy_s(local_cc,0x40,(char *)((int)local_148 + 1));
        *(char *)local_148 = '\0';
        strncpy_s(local_10c,0x40,local_8c,0xffffffff);
        sprintf_s<64>(&local_10c,"%s.odf",local_8c);
        bVar4 = OpenODF2(local_10c);
        if (bVar4) {
          pcVar8 = local_cc;
LAB_4fc27fac:
          iVar7 = GetODFFloat(local_10c,(char *)0x0,pcVar8,"lifeTime",&local_134,0.0);
          if (iVar7 != 0) {
            iVar7 = SecondsToTurns(local_134);
            *piVar11 = iVar7;
          }
        }
      }
    }
    piVar11 = piVar11 + 1;
    if (0xf < iVar12) {
      pcVar8 = GetObjectiveName(local_140);
      piVar1 = local_130;
      strcpy_s((char *)(local_130 + 0x43),0x100,pcVar8);
      local_148 = piVar1 + 9;
      GetODFInt(TempODF1,TempODF2,"TeleportalClass","TeleporterChannel",local_148,0);
      GetODFBool(TempODF1,TempODF2,"TeleportalClass","ShowChannel",(bool *)(piVar1 + 5),true);
      GetODFBool(TempODF1,TempODF2,"TeleportalClass","CanEnter",(bool *)(piVar1 + 4),true);
      GetODFBool(TempODF1,TempODF2,"TeleportalClass","CanExit",(bool *)((int)piVar1 + 0x11),true);
      local_130 = piVar1 + 7;
      GetODFInt(TempODF1,TempODF2,"TeleportalClass","MatchType",local_130,0);
      GetODFBool(TempODF1,TempODF2,"TeleportalClass","MatchTypeUsesChannels",
                 (bool *)((int)piVar1 + 0x12),true);
      GetODFBool(TempODF1,TempODF2,"TeleportalClass","ContinuousFx",(bool *)(piVar1 + 6),false);
      GetODFFloat(TempODF1,TempODF2,"TeleportalClass","ContinuousFxRange",(float *)(piVar1 + 0x41),
                  0.0);
      GetODFColor(TempODF1,TempODF2,"TeleportalClass","TeleportColorFade",(ulong *)(piVar1 + 0x42),0
                 );
      piVar11 = piVar1 + 0xc;
      GetODFInt(TempODF1,TempODF2,"TeleportalClass","TeleportFilter",piVar11,0xf);
      if (*piVar11 == 0) {
        *piVar11 = 0x1f;
      }
      GetODFFloat(TempODF1,TempODF2,"TeleportalClass","ExitVelocity",(float *)(piVar1 + 0x21),0.0);
      GetODFBool(TempODF1,TempODF2,"TeleportalClass","ExitForwardOnly",(bool *)((int)piVar1 + 0x13),
                 false);
      GetODFBool(TempODF1,TempODF2,"TeleportalClass","ExitKickAI",(bool *)((int)piVar1 + 0x17),false
                );
      GetODFBool(TempODF1,TempODF2,"TeleportalClass","ExitUsesCenter",(bool *)((int)piVar1 + 0x16),
                 true);
      GetODFBool(TempODF1,TempODF2,"TeleportalClass","EnterGotoIsExit",(bool *)((int)piVar1 + 0x19),
                 false);
      GetODFFloat(TempODF1,TempODF2,"TeleportalClass","EnterRange",(float *)(piVar1 + 0x20),10.0);
      GetODFFloat(TempODF1,TempODF2,"TeleportalClass","DestinationMinRange",(float *)(piVar1 + 0x22)
                  ,0.0);
      GetODFFloat(TempODF1,TempODF2,"TeleportalClass","DestinationMaxRange",(float *)(piVar1 + 0x23)
                  ,0.0);
      piVar11 = piVar1 + 0xb;
      GetODFInt(TempODF1,TempODF2,"TeleportalClass","TeleportTeamFilter",piVar11,7);
      if (*piVar11 == 0) {
        *piVar11 = 7;
      }
      piVar11 = piVar1 + 10;
      GetODFInt(TempODF1,TempODF2,"TeleportalClass","DestinationTeamFilter",piVar11,3);
      if (*piVar11 == 0) {
        *piVar11 = 7;
      }
      local_118 = 0;
      local_114 = 0;
      local_110 = 0;
      local_12c.x = 0.0;
      local_12c.y = 0.0;
      local_12c.z = 0.0;
      auVar2._4_4_ = unaff_ESI;
      auVar2._0_4_ = unaff_EDI;
      auVar2._8_4_ = 0;
      pMVar9 = GetODFPositionOffset((Matrix *)0x0,0,0,(Vector)ZEXT812(0),(Vector)(auVar2 << 0x20));
      local_12c.x = 0.0;
      local_12c.y = 0.0;
      local_12c.z = 0.0;
      local_118 = 0;
      local_114 = 0;
      local_110 = 0;
      pfVar13 = (float *)(piVar1 + 0x2b);
      for (iVar12 = 0x10; iVar12 != 0; iVar12 = iVar12 + -1) {
        *pfVar13 = (pMVar9->right).x;
        pMVar9 = (Matrix *)&(pMVar9->right).y;
        pfVar13 = pfVar13 + 1;
      }
      auVar3._4_4_ = unaff_ESI;
      auVar3._0_4_ = unaff_EDI;
      auVar3._8_4_ = 0;
      pMVar9 = GetODFPositionOffset((Matrix *)0x1,0,0,(Vector)ZEXT812(0),(Vector)(auVar3 << 0x20));
      piVar1[0x28] = (int)(pMVar9->posit).x;
      piVar1[0x29] = (int)(pMVar9->posit).y;
      piVar1[0x2a] = (int)(pMVar9->posit).z;
      GetPosition(local_140,&local_12c);
      piVar1[8] = -1;
      piVar1[0x25] = (int)local_12c.x;
      piVar1[0x26] = (int)local_12c.y;
      piVar1[0x27] = (int)local_12c.z;
      if (BZCClassHash == -0xf78db58) {
        iVar12 = (*misnImport.GetNearestVehicleObject)(local_140);
        pcVar8 = local_144;
        piVar1[3] = iVar12;
        piVar1[9] = iVar12;
        GetODFString(TempODF1,local_144,"TeleportalMineClass","TooFarSound",0x40,
                     (char *)(piVar1 + 0xa3),(char *)0x0);
        GetODFString(TempODF1,pcVar8,"TeleportalMineClass","TooCloseSound",0x40,
                     (char *)(piVar1 + 0xb3),(char *)0x0);
      }
      else {
        _Str1 = GetLabel(local_140);
        pcVar8 = local_144;
        if (_Str1 != (char *)0x0) {
          iVar12 = _strnicmp(_Str1,"channel_",8);
          if (iVar12 == 0) {
            memset(local_cc,0,0x40);
            pcVar8 = strchr(_Str1,0x5f);
            CombineStrings(local_cc,"",pcVar8 + 1,0x40);
            iVar12 = atoi(local_cc);
            piVar1[9] = iVar12;
            pcVar8 = local_144;
          }
          else {
            iVar12 = _strnicmp(_Str1,"Portal",6);
            pcVar8 = local_144;
            if ((((iVar12 == 0) &&
                 (iVar12 = isalpha((int)_Str1[6]), pcVar8 = local_144, iVar12 != 0)) &&
                (iVar12 = isdigit((int)_Str1[7]), pcVar8 = local_144, iVar12 != 0)) &&
               (piVar1[9] = (int)_Str1[6], piVar1[7] == 1)) {
              piVar1[8] = _Str1[7] + -0x30;
            }
          }
        }
      }
      *piVar1 = local_140;
      local_139 = false;
      iVar7 = GetODFBool(TempODF1,pcVar8,"TeleportalClass","AllowOnlyTwo",&local_139,false);
      iVar12 = local_140;
      piVar11 = local_148;
      this_00 = local_11c;
      if (iVar7 != 0) {
        iVar7 = GetTeamNum(local_140);
        this_00 = local_11c;
        piVar11 = local_148;
        *local_148 = *local_148 + iVar7;
        cVar10 = '\0';
        iVar7 = *(int *)&(local_11c->PortalList).field_0x4;
        cStack_149 = '\0';
        for (; iVar7 != *(int *)&this_00->PortalList; iVar7 = iVar7 - local_138) {
          if ((*(int *)(iVar7 + -0x36c) == *piVar11) && (*(int *)(iVar7 + -0x390) != iVar12)) {
            if (cVar10 == '\0') {
              cStack_149 = '\x01';
              cVar10 = '\x01';
            }
            else {
              BZ1Helper::DeleteAfterDelay(BZ1Helper::m_BZ1Helper,*(int *)(iVar7 + -0x390),0.0);
              SetPortalEffectEnd(this_00,*(int *)(iVar7 + -0x390),0,0,extraout_CL);
              cVar10 = cStack_149;
            }
          }
        }
      }
      if (*local_130 == 1) {
        SortCycleList(this_00,*piVar11);
      }
      return;
    }
  } while( true );
}


// ---------------------------------------------------------------------
// PortalHelper::Execute  @ 4fc284f1  lines 362-839

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall PortalHelper::Execute(PortalHelper *this,BZ1Helper *param_1)

{
  undefined1 *puVar1;
  undefined1 auVar2 [12];
  undefined1 auVar3 [12];
  bool bVar4;
  float *pfVar5;
  Matrix *pMVar6;
  char *pcVar7;
  PortalHelper *pPVar8;
  undefined1 extraout_CL;
  int iVar9;
  TeleportTargetClass *pTVar10;
  float fVar11;
  TeleportTargetClass *pTVar12;
  PortalHelper *pPVar13;
  float *pfVar14;
  undefined4 unaff_ESI;
  TeleportTargetClass *pTVar15;
  float *pfVar16;
  int *piVar17;
  undefined4 unaff_EDI;
  TeleportTargetClass *pTVar18;
  size_t sVar19;
  int iVar20;
  float fVar21;
  undefined1 uVar22;
  TeleportTargetClass *local_218;
  bool local_211;
  TeleportTargetClass *local_210;
  float *local_20c;
  float *local_208;
  TeleportTargetClass *local_204;
  TeleportTargetClass *local_200;
  PortalHelper *local_1fc;
  double dStack_1f8;
  float local_1f0;
  PortalHelper *pPStack_1ec;
  float local_1e8;
  float local_1e4;
  float fStack_1e0;
  undefined4 uStack_1dc;
  undefined4 uStack_1d8;
  undefined4 uStack_1d4;
  undefined4 uStack_1d0;
  undefined4 uStack_1cc;
  undefined4 uStack_1c8;
  undefined4 uStack_1c4;
  undefined4 uStack_1c0;
  undefined4 uStack_1bc;
  undefined4 uStack_1b8;
  undefined4 uStack_1b4;
  undefined4 uStack_1b0;
  Vector local_1ac;
  Vector local_1a0;
  Vector aVStack_194 [11];
  char acStack_108 [260];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)&local_218;
  local_211 = BZ1Helper::Logging;
  pTVar15 = *(TeleportTargetClass **)&this->PortalList;
  fVar11 = -NAN;
  local_1f0 = 1.27798e-42;
  pTVar12 = pTVar15;
  local_218 = pTVar15;
  local_200 = pTVar15;
  local_1fc = this;
  for (; pTVar10 = *(TeleportTargetClass **)&(this->PortalList).field_0x4, local_210 = pTVar15,
      pTVar15 != pTVar10; pTVar15 = (TeleportTargetClass *)&pTVar15[0x2d].DestEnterRange) {
    bVar4 = IsAround(pTVar15->TeleportTarget);
    if (bVar4) {
      if (local_218 != pTVar15) {
        pTVar10 = pTVar15;
        pTVar18 = pTVar12;
        for (iVar9 = 0xe4; pTVar15 = local_210, pTVar12 = local_200, iVar9 != 0; iVar9 = iVar9 + -1)
        {
          pTVar18->TeleportTarget = pTVar10->TeleportTarget;
          pTVar10 = (TeleportTargetClass *)&pTVar10->TeleportTargetDestination;
          pTVar18 = (TeleportTargetClass *)&pTVar18->TeleportTargetDestination;
        }
      }
      pTVar12 = (TeleportTargetClass *)&pTVar12[0x2d].DestEnterRange;
      local_200 = pTVar12;
    }
    else if (pTVar15[1].DestinationIndex == 1) {
      fVar11 = pTVar15[1].DistanceFromDestination;
    }
  }
  if (pTVar12 != pTVar10) {
    *(TeleportTargetClass **)&(this->PortalList).field_0x4 = pTVar12;
  }
  if (-1 < (int)fVar11) {
    SortCycleList(this,(int)fVar11);
  }
  pTVar15 = *(TeleportTargetClass **)&(this->TeleportTargetList).field_0x4;
  pTVar12 = *(TeleportTargetClass **)&this->TeleportTargetList;
  local_204 = pTVar15;
  while ((pTVar12 != pTVar15 && (bVar4 = ShouldRemoveTeleportTarget(pTVar12), !bVar4))) {
    pTVar12 = pTVar12 + 1;
  }
  if (pTVar12 != pTVar15) {
    pTVar10 = pTVar12 + 1;
    local_218 = pTVar10;
    if (pTVar10 != pTVar15) {
      do {
        bVar4 = ShouldRemoveTeleportTarget(pTVar10);
        if (!bVar4) {
          pTVar15 = pTVar10;
          pTVar18 = pTVar12;
          for (iVar9 = 5; iVar9 != 0; iVar9 = iVar9 + -1) {
            pTVar18->TeleportTarget = pTVar15->TeleportTarget;
            pTVar15 = (TeleportTargetClass *)&pTVar15->TeleportTargetDestination;
            pTVar18 = (TeleportTargetClass *)&pTVar18->TeleportTargetDestination;
          }
          pTVar12 = pTVar12 + 1;
          pTVar15 = local_204;
        }
        pTVar10 = pTVar10 + 1;
        this = local_1fc;
      } while (pTVar10 != pTVar15);
    }
    if (pTVar12 != pTVar15) {
      sVar19 = *(int *)&(this->TeleportTargetList).field_0x4 - (int)pTVar15;
      memmove(pTVar12,pTVar15,sVar19);
      *(size_t *)&(this->TeleportTargetList).field_0x4 = sVar19 + (int)pTVar12;
    }
  }
  pfVar16 = *(float **)&this->PortalList;
  do {
    local_20c = pfVar16;
    if (pfVar16 == *(float **)&(this->PortalList).field_0x4) {
      piVar17 = *(int **)&this->TeleportTargetList;
      if (piVar17 != *(int **)&(this->TeleportTargetList).field_0x4) {
        do {
          bVar4 = IsAround(piVar17[1]);
          if (bVar4) {
            iVar9 = piVar17[2];
            iVar20 = *(int *)&this->PortalList;
            GetPosition(*piVar17,&local_1ac);
            local_1f0 = GetDistance3DSquared(&local_1ac,(Vector *)(iVar9 * 0x390 + iVar20 + 0x94));
            piVar17[4] = (int)local_1f0;
            if (local_211 != false) {
              FormatLogMessage("Teleporter Target Index: %d Just Teleported, Distnace is: %f",
                               ((int)piVar17 - *(int *)&this->TeleportTargetList) / 0x14,
                               (double)local_1f0);
            }
          }
          piVar17 = piVar17 + 5;
        } while (piVar17 != *(int **)&(this->TeleportTargetList).field_0x4);
      }
      return;
    }
    pfVar5 = (float *)GetTeamNum((int)*pfVar16);
    local_218 = (TeleportTargetClass *)(pfVar16 + 0x25);
    local_1e8 = (float)local_218->TeleportTarget;
    local_1e4 = pfVar16[0x26];
    fStack_1e0 = pfVar16[0x27];
    local_208 = pfVar5;
    GetPosition((int)*local_20c,&local_1a0);
    pfVar16 = local_20c;
    local_200 = (TeleportTargetClass *)0x0;
    local_218->TeleportTarget = (int)local_1a0.x;
    local_218->TeleportTargetDestination = (int)local_1a0.y;
    local_218->DestinationIndex = (int)local_1a0.z;
    if ((*(char *)(local_20c + 6) != '\0') && (local_20c[0x41] != 0.0)) {
      local_200 = (TeleportTargetClass *)(*misnImport.GetNearestVehicleObject)((int)*local_20c);
      local_218 = (TeleportTargetClass *)(pfVar16 + 0x25);
    }
    local_218 = (TeleportTargetClass *)ABS((float)local_218->TeleportTarget - local_1e8);
    if ((((float)local_218 < 0.01) &&
        (local_218 = (TeleportTargetClass *)ABS(pfVar16[0x26] - local_1e4), (float)local_218 < 0.01)
        ) && (local_218 = (TeleportTargetClass *)ABS(pfVar16[0x27] - fStack_1e0),
             (float)local_218 < 0.01)) {
      uStack_1dc = 0;
      uStack_1d8 = 0;
      uStack_1d4 = 0;
      uStack_1d0 = 0;
      uStack_1cc = 0;
      uStack_1c8 = 0;
      auVar2._4_4_ = unaff_ESI;
      auVar2._0_4_ = unaff_EDI;
      auVar2._8_4_ = 0;
      pMVar6 = GetODFPositionOffset((Matrix *)0x0,0,0,(Vector)ZEXT812(0),(Vector)(auVar2 << 0x20));
      uStack_1c4 = 0;
      uStack_1c0 = 0;
      uStack_1bc = 0;
      uStack_1b8 = 0;
      uStack_1b4 = 0;
      uStack_1b0 = 0;
      pfVar16 = local_20c + 0x2b;
      for (iVar9 = 0x10; iVar9 != 0; iVar9 = iVar9 + -1) {
        *pfVar16 = (pMVar6->right).x;
        pMVar6 = (Matrix *)&(pMVar6->right).y;
        pfVar16 = pfVar16 + 1;
      }
      auVar3._4_4_ = unaff_ESI;
      auVar3._0_4_ = unaff_EDI;
      auVar3._8_4_ = 0;
      pMVar6 = GetODFPositionOffset((Matrix *)0x1,0,0,(Vector)ZEXT812(0),(Vector)(auVar3 << 0x20));
      local_20c[0x28] = (pMVar6->posit).x;
      local_20c[0x29] = (pMVar6->posit).y;
      local_20c[0x2a] = (pMVar6->posit).z;
      pfVar16 = local_20c;
    }
    if (*(char *)(pfVar16 + 5) != '\0') {
      iVar9 = SecondsToTurns(1.0);
      if ((BZ1Helper::m_TurnCounter % iVar9 == 0) && (*(char *)((int)pfVar16 + 0x15) == '\0')) {
        pfVar14 = pfVar5;
        iVar9 = GetLocalPlayerTeamNumber();
        bVar4 = IsTeamAllied(iVar9,(int)pfVar14);
        if (bVar4) {
          SetObjectiveName((int)*pfVar16,(char *)(pfVar16 + 0x43));
        }
        *(undefined1 *)((int)pfVar16 + 0x15) = 1;
      }
      iVar9 = SecondsToTurns(3.0);
      if ((BZ1Helper::m_TurnCounter % iVar9 == 0) && (*(char *)((int)pfVar16 + 0x15) != '\0')) {
        iVar9 = GetLocalPlayerTeamNumber();
        bVar4 = IsTeamAllied(iVar9,(int)pfVar5);
        if (bVar4) {
          memset(acStack_108,0,0x100);
          pcVar7 = GetBZCCLocalizedString("cfg","Channel %d");
          sprintf_s<256>((char (*) [256])acStack_108,pcVar7);
          SetObjectiveName((int)*pfVar16,acStack_108);
        }
        *(undefined1 *)((int)pfVar16 + 0x15) = 0;
      }
    }
    if ((*(char *)(pfVar16 + 4) != '\0') &&
       ((pfVar16[3] != 0.0 ||
        (bVar4 = BuildingHelper::IsBuildingPowered(BuildingHelper::m_BuildingHelper,(int)*pfVar16),
        bVar4)))) {
      if (*(char *)((int)pfVar16 + 0x1a) == '\0') {
        fVar11 = pfVar16[1];
        pPVar13 = (PortalHelper *)pfVar16[0x3b];
        pfVar16[1] = 0.0;
        pfVar16[0x3b] = 0.0;
        fVar21 = pfVar16[7];
        if (fVar21 == 0.0) {
          pfVar5 = *(float **)&this->PortalList;
          local_1fc = (PortalHelper *)0x7f7fffff;
          pfVar14 = (float *)0xffffffff;
          local_204 = (TeleportTargetClass *)0x0;
          local_218 = (TeleportTargetClass *)0xffffffff;
          local_20c = (float *)0xffffffff;
          if (pfVar5 != *(float **)&(this->PortalList).field_0x4) {
            do {
              iVar9 = GetTeamNum((int)*pfVar5);
              dStack_1f8 = (double)CONCAT44(dStack_1f8._4_4_,iVar9);
              if ((((((((*(char *)((int)pfVar16 + 0x12) == '\0') || (pfVar16[9] == pfVar5[9])) &&
                      (*(char *)((int)pfVar5 + 0x11) != '\0')) &&
                     (bVar4 = TeamFilterCheck((int)pfVar16[10],iVar9,(int)local_208), bVar4)) &&
                    ((pfVar5[3] != 0.0 ||
                     (bVar4 = BuildingHelper::IsBuildingPowered
                                        (BuildingHelper::m_BuildingHelper,(int)*pfVar5), bVar4))))
                   && ((pTVar15 = (TeleportTargetClass *)*pfVar5, pfVar14 = local_20c,
                       (TeleportTargetClass *)*pfVar16 != pTVar15 &&
                       (pPStack_1ec = (PortalHelper *)
                                      GetDistance3DSquared
                                                ((Vector *)(pfVar16 + 0x25),
                                                 (Vector *)(pfVar5 + 0x25)), pfVar14 = local_20c,
                       (float)pPStack_1ec < (float)local_1fc)))) &&
                  ((fVar11 = pfVar16[0x22], fVar11 == 0.0 ||
                   (local_210 = (TeleportTargetClass *)(fVar11 * fVar11),
                   (float)local_210 < (float)pPStack_1ec)))) &&
                 ((local_210 = (TeleportTargetClass *)pfVar16[0x23], (float)local_210 == 0.0 ||
                  (local_210 = (TeleportTargetClass *)((float)local_210 * (float)local_210),
                  (float)pPStack_1ec < (float)local_210)))) {
                if (dStack_1f8._0_4_ == local_208) {
                  local_218 = (TeleportTargetClass *)
                              (((int)pfVar5 - *(int *)&this->PortalList) / (int)local_1f0);
                  local_204 = pTVar15;
                }
                pfVar16[1] = (float)pTVar15;
                pfVar16[0x3b] = (float)(((int)pfVar5 - *(int *)&this->PortalList) / 0x390);
                local_20c = dStack_1f8._0_4_;
                pfVar14 = dStack_1f8._0_4_;
                local_1fc = pPStack_1ec;
              }
              pfVar5 = pfVar5 + 0xe4;
            } while (pfVar5 != *(float **)&(this->PortalList).field_0x4);
          }
          if (((pfVar14 != local_208) && (((uint)pfVar16[10] & 1) != 0)) &&
             (local_204 != (TeleportTargetClass *)0x0)) {
            pfVar16[1] = (float)local_204;
            pfVar16[0x3b] = (float)local_218;
          }
        }
        else if (fVar21 == 1.4013e-45) {
          bVar4 = IsAround((int)fVar11);
          if (bVar4) {
            pfVar16[1] = fVar11;
LAB_4fc28bd4:
            pfVar16[0x3b] = (float)pPVar13;
          }
          else {
            local_204 = (TeleportTargetClass *)
                        ((*(int *)&(this->PortalList).field_0x4 - *(int *)&this->PortalList) / 0x390
                        + -1);
            if ((-1 < (int)local_204) && (0 < (int)local_204)) {
              pPVar8 = (PortalHelper *)(((int)pfVar16 - *(int *)&this->PortalList) / 0x390);
              pPVar13 = (PortalHelper *)0x0;
              local_1fc = (PortalHelper *)0x0;
              if ((int)pPVar8 <= (int)local_204) {
                pPVar13 = pPVar8;
                local_1fc = pPVar8;
              }
              do {
                iVar9 = (int)pPVar13 * 0x390;
                local_218 = (TeleportTargetClass *)
                            GetTeamNum(*(int *)(*(int *)&this->PortalList + iVar9));
                if ((((*(char *)((int)pfVar16 + 0x12) == '\0') ||
                     (pfVar16[9] == *(float *)(*(int *)&this->PortalList + 0x24 + iVar9))) &&
                    ((*(char *)(*(int *)&this->PortalList + 0x11 + iVar9) != '\0' &&
                     (bVar4 = TeamFilterCheck((int)pfVar16[10],(int)local_218,(int)local_208), bVar4
                     )))) && (((*(int *)(*(int *)&this->PortalList + 0xc + iVar9) != 0 ||
                               (bVar4 = BuildingHelper::IsBuildingPowered
                                                  (BuildingHelper::m_BuildingHelper,
                                                   *(int *)(*(int *)&this->PortalList + iVar9)),
                               bVar4)) &&
                              (fVar11 = *(float *)(iVar9 + *(int *)&this->PortalList),
                              *pfVar16 != fVar11)))) {
                  pfVar16[1] = fVar11;
                  goto LAB_4fc28bd4;
                }
                puVar1 = &(pPVar13->PortalList).field_0x1;
                pPVar13 = (PortalHelper *)0x0;
                if ((int)puVar1 <= (int)local_204) {
                  pPVar13 = (PortalHelper *)puVar1;
                }
              } while (pPVar13 != local_1fc);
            }
          }
        }
        else if (fVar21 == 2.8026e-45) {
          bVar4 = IsAround((int)fVar11);
          if (bVar4) {
            pfVar16[1] = fVar11;
            pfVar16[0x3b] = (float)pPVar13;
          }
          local_204 = (TeleportTargetClass *)
                      GetRandomInt(0,(*(int *)&(this->PortalList).field_0x4 -
                                     *(int *)&this->PortalList) / 0x390 + -1);
          iVar20 = (int)local_204 * 0x390;
          iVar9 = GetTeamNum(*(int *)(*(int *)&this->PortalList + iVar20));
          if (((*(char *)((int)pfVar16 + 0x12) == '\0') ||
              (pfVar16[9] == *(float *)(iVar20 + 0x24 + *(int *)&this->PortalList))) &&
             (((*(char *)(iVar20 + 0x11 + *(int *)&this->PortalList) != '\0' &&
               (bVar4 = TeamFilterCheck((int)pfVar16[10],iVar9,(int)local_208), bVar4)) &&
              ((*(int *)(iVar20 + 0xc + *(int *)&this->PortalList) != 0 ||
               (bVar4 = BuildingHelper::IsBuildingPowered
                                  (BuildingHelper::m_BuildingHelper,
                                   *(int *)(iVar20 + *(int *)&this->PortalList)), bVar4)))))) {
            fVar11 = *(float *)(iVar20 + *(int *)&this->PortalList);
            if (*pfVar16 != fVar11) {
              local_208 = (float *)GetDistance3DSquared
                                             ((Vector *)(pfVar16 + 0x25),
                                              (Vector *)(iVar20 + 0x94 + *(int *)&this->PortalList))
              ;
              local_210 = (TeleportTargetClass *)pfVar16[0x22];
              if ((((float)local_210 == 0.0) ||
                  (local_218 = (TeleportTargetClass *)((float)local_210 * (float)local_210),
                  (float)local_218 < (float)local_208)) &&
                 ((local_210 = (TeleportTargetClass *)pfVar16[0x23], (float)local_210 == 0.0 ||
                  (local_218 = (TeleportTargetClass *)((float)local_210 * (float)local_210),
                  (float)local_208 < (float)local_218)))) {
                pfVar16[1] = fVar11;
                pfVar16[0x3b] = (float)local_204;
              }
            }
          }
        }
      }
      if ((pfVar16[1] != 0.0) && (*(char *)(pfVar16 + 6) != '\0')) {
        fVar11 = pfVar16[2];
        bVar4 = IsEmitterOn((int)*pfVar16,(int)fVar11);
        uVar22 = SUB41(fVar11,0);
        if (!bVar4) {
          if (pfVar16[0x41] == 0.0) {
LAB_4fc28a8f:
            SetPortalEffectStart_Internal
                      (this,((int)pfVar16 - *(int *)&this->PortalList) / 0x390,(int)pfVar16[0x3e],1,
                       (bool)uVar22);
          }
          else if (local_200 != (TeleportTargetClass *)0x0) {
            GetPosition((int)local_200,aVStack_194);
            dStack_1f8 = (double)pfVar16[0x41];
            fVar21 = GetDistance3DSquared((Vector *)(pfVar16 + 0x25),aVStack_194);
            fVar11 = (float)((float10)dStack_1f8 * (float10)dStack_1f8);
            dStack_1f8 = (double)CONCAT44(dStack_1f8._4_4_,fVar11);
            uVar22 = extraout_CL;
            if (fVar21 < fVar11) goto LAB_4fc28a8f;
          }
        }
      }
    }
    iVar9 = 0;
    pfVar5 = pfVar16 + 0x10;
    do {
      fVar11 = *pfVar5;
      if ((int)fVar11 < 2) {
        if ((0 < (int)fVar11) && (iVar9 != (int)pfVar16[2] + -1)) {
          StopEmitter((int)*pfVar16,iVar9 + 1);
        }
      }
      else {
        *pfVar5 = (float)((int)fVar11 + -1);
      }
      iVar9 = iVar9 + 1;
      pfVar5 = pfVar5 + 1;
    } while (iVar9 < 0x10);
    fVar11 = pfVar16[2];
    if ((fVar11 == 0.0) || (1 < (int)pfVar16[(int)fVar11 + 0xf])) {
      bVar4 = false;
    }
    else {
      bVar4 = true;
    }
    fVar21 = pfVar16[0xf];
    if (fVar21 == 1.4013e-45) {
      fVar21 = pfVar16[0xd];
      if (fVar21 == 0.0) {
        if (bVar4) {
          StopEmitter((int)*pfVar16,(int)fVar11);
          if (local_211 != false) {
            GetEmitterMask((int)*pfVar16);
            pcVar7 = "Clearing Portal FX: Mode PortalType_NONE Slot: %d, EmitterMask: %d";
LAB_4fc28f35:
            FormatConsoleMessage(pcVar7);
          }
LAB_4fc28f3d:
          pfVar16[2] = 0.0;
          goto LAB_4fc28f41;
        }
      }
      else if (fVar21 == 1.4013e-45) {
        if (bVar4) {
          SetPortalEffectOn_Internal
                    (this,((int)pfVar16 - *(int *)&this->PortalList) / 0x390,(int)pfVar16[0xe],1,
                     true);
        }
      }
      else if ((fVar21 == 2.8026e-45) && (bVar4)) {
        fVar11 = 2.8026e-45;
        goto LAB_4fc28ed4;
      }
    }
    else if (fVar21 == 2.8026e-45) {
      if (*(char *)(pfVar16 + 6) != '\0') {
        if (pfVar16[1] == 0.0) {
LAB_4fc28eb3:
          fVar11 = pfVar16[0xd];
LAB_4fc28ed4:
          SetPortalEffectEnd_Internal
                    (this,((int)pfVar16 - *(int *)&this->PortalList) / 0x390,(int)pfVar16[0xe],
                     (int)fVar11,true);
        }
        else if ((pfVar16[0x41] != 0.0) && (local_200 != (TeleportTargetClass *)0x0)) {
          GetPosition((int)local_200,&local_1ac);
          dStack_1f8 = (double)pfVar16[0x41];
          fVar21 = GetDistance3DSquared((Vector *)(pfVar16 + 0x25),&local_1ac);
          fVar11 = (float)((float10)dStack_1f8 * (float10)dStack_1f8);
          dStack_1f8 = (double)CONCAT44(dStack_1f8._4_4_,fVar11);
          if (fVar11 < fVar21) goto LAB_4fc28eb3;
        }
      }
    }
    else if ((fVar21 == 4.2039e-45) && (bVar4)) {
      bVar4 = IsEmitterOn((int)*pfVar16,(int)fVar11);
      if (bVar4) {
        StopEmitter((int)*pfVar16,(int)pfVar16[2]);
        if (local_211 != false) {
          GetEmitterMask((int)*pfVar16);
          pcVar7 = "Clearing Portal FX: Mode PortalType_Closing, Slot: %d, EffectMask: %d";
          goto LAB_4fc28f35;
        }
        goto LAB_4fc28f3d;
      }
LAB_4fc28f41:
      pfVar16[0xf] = 0.0;
    }
    pfVar16 = pfVar16 + 0xe4;
  } while( true );
}


// ---------------------------------------------------------------------
// PortalHelper::ExecuteObject  @ 4fc28fec  lines 842-1187

void __thiscall PortalHelper::ExecuteObject(PortalHelper *this,ObjectClass *objectInfo)

{
  double dVar1;
  float fVar2;
  Matrix MVar3;
  Matrix MVar4;
  Vector v;
  Vector v_00;
  Vector v_01;
  Vector v_02;
  DLLBase *pDVar5;
  vector<PortalHelper::TeleportTargetClass,std::allocator<PortalHelper::TeleportTargetClass>_>
  *pvVar6;
  bool bVar7;
  float *pfVar8;
  Matrix *pMVar9;
  float fVar10;
  int *piVar11;
  int iVar12;
  char *pcVar13;
  Matrix *pMVar14;
  Vector *pVVar15;
  Matrix *pMVar16;
  Matrix *pMVar17;
  AiCommand AVar18;
  float fVar19;
  Vector *__return_storage_ptr__;
  int iVar20;
  code *pcVar21;
  int extraout_ECX;
  int extraout_EDX;
  Matrix *unaff_ESI;
  float *pfVar22;
  Matrix *unaff_EDI;
  float10 extraout_ST0;
  float10 fVar23;
  undefined1 in_stack_fffffdd8 [20];
  undefined1 auVar24 [12];
  undefined4 in_stack_fffffdec;
  undefined4 in_stack_fffffdf0;
  undefined4 in_stack_fffffdf4;
  undefined4 in_stack_fffffdf8;
  char *in_stack_fffffdfc;
  float *in_stack_fffffe00;
  Vector *pVVar25;
  Matrix *pMVar26;
  double dVar27;
  uint uVar28;
  char cStack_1dd;
  undefined1 auStack_1d8 [4];
  Matrix *local_1d4;
  Vector VStack_1d0;
  char cStack_1c1;
  Matrix *local_1c0;
  code *local_1bc;
  Matrix *local_1b8;
  float *local_1b4;
  Matrix *local_1b0;
  Vector local_1ac;
  float local_1a0;
  float local_19c;
  vector<PortalHelper::TeleportTargetClass,std::allocator<PortalHelper::TeleportTargetClass>_>
  *local_198;
  Vector *local_194;
  code *local_190;
  code *local_18c;
  double local_188;
  code *local_180;
  code *local_17c;
  code *local_178;
  int local_174;
  Matrix MStack_170;
  Vector VStack_12c;
  Vector VStack_120;
  float fStack_114;
  float fStack_110;
  float fStack_10c;
  Matrix MStack_108;
  Matrix MStack_c8;
  Matrix aMStack_88 [2];
  
  local_1b0 = (Matrix *)0x0;
  local_1ac.x = 0.0;
  local_1ac.y = 0.0;
  local_1ac.z = 0.0;
  local_1b4 = (float *)0x0;
  auStack_1d8[3] = BZ1Helper::Logging;
  pMVar14 = (Matrix *)objectInfo->ObjectHandle;
  local_198 = &this->TeleportTargetList;
  for (pfVar8 = *(float **)local_198; pfVar8 != *(float **)&(this->TeleportTargetList).field_0x4;
      pfVar8 = pfVar8 + 5) {
    if ((Matrix *)*pfVar8 == pMVar14) {
      return;
    }
  }
  pfVar8 = *(float **)&this->PortalList;
  if (pfVar8 == *(float **)&(this->PortalList).field_0x4) {
    return;
  }
  local_1b8 = (Matrix *)0x0;
  local_178 = Goto_exref;
  local_17c = GetPlayerHandle_exref;
  local_194 = (Vector *)0xbf800000;
  local_190 = StartAudio2D_exref;
  local_1c0 = pMVar14;
  do {
    if ((Matrix *)*pfVar8 == pMVar14) {
      return;
    }
    local_1bc = (code *)0x0;
    do {
      pMVar9 = (Matrix *)GetTap((int)*pfVar8,(int)local_1bc);
      if (pMVar14 == pMVar9) {
        return;
      }
      local_1bc = (code *)((int)local_1bc + 1);
    } while ((int)local_1bc < 8);
    if ((pfVar8[3] != 0.0) && (pMVar14 == (Matrix *)pfVar8[3])) {
      local_1b4 = (float *)((int)local_1b4 + 1);
    }
    local_19c = *pfVar8;
    fVar10 = (float)WhoFollowing((int)pMVar14);
    if (fVar10 == local_19c) {
      if (*(char *)((int)pfVar8 + 0x19) == '\0') {
        Goto((int)pMVar14,(int)local_19c,0);
      }
      else {
        (*local_178)();
      }
    }
    if (pfVar8[1] == 0.0) {
      if (((pfVar8[3] != 0.0) && (pMVar14 == (Matrix *)pfVar8[3])) && (1 < (int)local_1b4)) {
        local_1bc = (code *)0x0;
        for (piVar11 = *(int **)&this->PortalList; piVar11 != *(int **)&(this->PortalList).field_0x4
            ; piVar11 = piVar11 + 0xe4) {
          if (pMVar14 == (Matrix *)piVar11[3]) {
            (*misnImport.GetDistanceObject)((int *)pfVar8,piVar11);
            local_1bc = (code *)(float)extraout_ST0;
            break;
          }
        }
        pMVar9 = (Matrix *)(*local_17c)();
        if (pMVar14 == pMVar9) {
          if ((float)local_1bc <= pfVar8[0x23]) {
            if (pfVar8[0x22] <= (float)local_1bc) goto LAB_4fc2919f;
            in_stack_fffffe00 = pfVar8 + 0xb3;
          }
          else {
            in_stack_fffffe00 = pfVar8 + 0xa3;
          }
          in_stack_fffffdfc = (char *)0x4fc2919c;
          (*local_190)();
        }
LAB_4fc2919f:
        BZ1Helper::DeleteAfterDelay(BZ1Helper::m_BZ1Helper,(int)*pfVar8,(float)local_1b8);
        BZ1Helper::DeleteAfterDelay
                  (BZ1Helper::m_BZ1Helper,
                   *(int *)((int)pfVar8[0x3b] * 0x390 + *(int *)&this->PortalList),(float)local_1b8)
        ;
      }
    }
    else {
      local_1d4 = (Matrix *)GetCurAmmo((int)*pfVar8);
      local_18c = (code *)GetMaxAmmo((int)*pfVar8);
      local_19c = (float)GetTeamNum((int)*pfVar8);
      local_174 = objectInfo->CurTeamNum;
      if (pfVar8[3] == 0.0) {
        local_1bc = (code *)GetDistance3DSquared(&objectInfo->Position,(Vector *)(pfVar8 + 0x37));
      }
      else {
        fVar10 = pfVar8[0x39] - (objectInfo->Position).z;
        fVar19 = ((Vector *)(pfVar8 + 0x37))->x - (objectInfo->Position).x;
        local_1bc = (code *)(fVar10 * fVar10 + fVar19 * fVar19);
      }
      local_188 = (double)(float)local_1bc;
      local_1a0 = pfVar8[0x20] * pfVar8[0x20];
      local_180 = local_1bc;
      if (((float)local_1bc < local_1a0) &&
         ((iVar12 = (**(code **)((int)BZ1Helper::m_BZ1Helper->super_DLLBase + 0x5c))(), iVar12 == 1
          || (((((iVar12 == 0 && (local_1d4 == (Matrix *)local_18c)) &&
                (bVar7 = TeamFilterCheck((int)pfVar8[0xb],local_174,(int)local_19c), bVar7)) &&
               ((((((fVar10 = pfVar8[0xc], ((uint)fVar10 & 1) != 0 && (objectInfo->CategoryID == 1))
                   || ((((uint)fVar10 & 2) != 0 && (objectInfo->CategoryID == 4)))) ||
                  ((((uint)fVar10 & 4) != 0 && (objectInfo->CategoryID == 8)))) ||
                 ((((uint)fVar10 & 8) != 0 && (objectInfo->CategoryID == 0x10)))) ||
                ((((uint)fVar10 & 0x10) != 0 && (objectInfo->CategoryID == 0x40)))))) &&
              ((iVar12 = (*misnImport.GetTug)((int)pMVar14), iVar12 == 0 &&
               (((pfVar8[3] == 0.0 || (pMVar14 == (Matrix *)pfVar8[3])) &&
                (bVar7 = IsNullVector(*(Vector *)
                                       (*(int *)&this->PortalList + 0xdc + (int)pfVar8[0x3b] * 0x390
                                       )), pMVar14 = local_1c0, !bVar7)))))))))) {
        if (auStack_1d8[3] != '\0') {
          fVar23 = (float10)__CIsqrt();
          local_1d4 = (Matrix *)(float)fVar23;
          dVar27 = (double)(float)local_1d4;
          pcVar13 = GetODFName((int)pMVar14);
          in_stack_fffffe00 = (float *)0x4fc2937f;
          FormatLogMessage("Locking onto Object: %08x, ODF: \'%s\', Distance is: %f",(uint)pMVar14,
                           pcVar13,(double)CONCAT44(unaff_EDI,(int)((ulonglong)dVar27 >> 0x20)));
        }
        pfVar22 = *(float **)local_198;
        break;
      }
    }
    pfVar8 = pfVar8 + 0xe4;
    if (pfVar8 == *(float **)&(this->PortalList).field_0x4) {
      return;
    }
  } while( true );
LAB_4fc2939e:
  if (pfVar22 == *(float **)&(this->TeleportTargetList).field_0x4) goto LAB_4fc293af;
  pMVar14 = (Matrix *)(*misnImport.GetTug)((int)*pfVar22);
  if (pMVar14 == local_1c0) {
    local_1b0 = (Matrix *)*pfVar22;
    goto LAB_4fc293af;
  }
  pfVar22 = pfVar22 + 5;
  goto LAB_4fc2939e;
LAB_4fc293af:
  pvVar6 = local_198;
  std::vector<PortalHelper::TeleportTargetClass,std::allocator<PortalHelper::TeleportTargetClass>_>
  ::_Resize<<lambda_f2c0a61063d8731356913bf41ed3079e>_>
            (local_198,(*(int *)&local_198->field_0x4 - *(int *)local_198) / 0x14 + 1,
             (<lambda_f2c0a61063d8731356913bf41ed3079e>)local_198);
  pMVar14 = local_1c0;
  local_1a0 = *(float *)pvVar6;
  iVar12 = ((*(int *)&pvVar6->field_0x4 - (int)local_1a0) / 0x14) * 0x14;
  local_188 = (double)CONCAT44(local_188._4_4_,iVar12);
  *(undefined4 *)(iVar12 + -0x10 + (int)local_1a0) = 0;
  *(undefined4 *)(iVar12 + -0xc + (int)local_1a0) = 0;
  *(undefined4 *)(iVar12 + -8 + (int)local_1a0) = 0;
  *(undefined4 *)(iVar12 + -4 + (int)local_1a0) = 0;
  *(Matrix **)(iVar12 + -0x14 + (int)local_1a0) = local_1c0;
  *(undefined4 *)(iVar12 + -8 + (int)local_1a0) =
       *(undefined4 *)((int)pfVar8[0x3b] * 0x390 + 0x80 + *(int *)&this->PortalList);
  *(float *)(iVar12 + -0x10 + (int)local_1a0) = pfVar8[1];
  *(float *)(iVar12 + -0xc + (int)local_1a0) = pfVar8[0x3b];
  local_1b4 = pfVar8 + 0x2b;
  GetPosition((int)local_1c0,&MStack_108);
  GetVelocity(&VStack_12c,(int)pMVar14);
  local_1bc = *(code **)&this->PortalList;
  local_1d4 = (Matrix *)((int)pfVar8[0x3b] * 0x390 + 0xac + (int)local_1bc);
  pMVar14 = local_1d4;
  pMVar9 = &MStack_170;
  for (iVar12 = 0x10; iVar12 != 0; iVar12 = iVar12 + -1) {
    (pMVar9->right).x = (pMVar14->right).x;
    pMVar14 = (Matrix *)&(pMVar14->right).y;
    pMVar9 = (Matrix *)&(pMVar9->right).y;
  }
  if (*(char *)((int)pfVar8[0x3b] * 0x390 + 0x13 + (int)local_1bc) == '\0') {
    MStack_170.right.x = -MStack_170.right.x;
    MStack_170.right.y = -MStack_170.right.y;
    MStack_170.right.z = -MStack_170.right.z;
    VStack_1d0.x = -MStack_170.front.x;
    VStack_1d0.y = -MStack_170.front.y;
    VStack_1d0.z = (float)((uint)MStack_170.front.z ^ 0x80000000);
    MStack_170.front.x = VStack_1d0.x;
    MStack_170.front.y = VStack_1d0.y;
    MStack_170.front.z = VStack_1d0.z;
    Matrix_Inverse(unaff_EDI,unaff_ESI);
    pMVar14 = Matrix_Multiply(&MStack_170,unaff_EDI,unaff_ESI);
    pMVar9 = aMStack_88;
    for (iVar12 = 0x10; iVar12 != 0; iVar12 = iVar12 + -1) {
      (pMVar9->right).x = (pMVar14->right).x;
      pMVar14 = (Matrix *)&(pMVar14->right).y;
      pMVar9 = (Matrix *)&(pMVar9->right).y;
    }
    pMVar14 = Matrix_Multiply(aMStack_88,unaff_EDI,unaff_ESI);
    pMVar9 = &MStack_170;
    for (iVar12 = 0x10; iVar12 != 0; iVar12 = iVar12 + -1) {
      (pMVar9->right).x = (pMVar14->right).x;
      pMVar14 = (Matrix *)&(pMVar14->right).y;
      pMVar9 = (Matrix *)&(pMVar9->right).y;
    }
    pVVar15 = Vector_Rotate(&VStack_12c,unaff_EDI,&unaff_ESI->right);
  }
  else {
    Matrix_Inverse(unaff_EDI,unaff_ESI);
    pMVar14 = Matrix_Multiply(local_1d4,unaff_EDI,unaff_ESI);
    pMVar9 = aMStack_88;
    for (iVar12 = 0x10; iVar12 != 0; iVar12 = iVar12 + -1) {
      (pMVar9->right).x = (pMVar14->right).x;
      pMVar14 = (Matrix *)&(pMVar14->right).y;
      pMVar9 = (Matrix *)&(pMVar9->right).y;
    }
    Vector_TransformInv((Vector *)(local_1b4 + 0xc),unaff_EDI,&unaff_ESI->right);
    pVVar15 = Vector_Transform(__return_storage_ptr__,unaff_EDI,&unaff_ESI->right);
    MStack_170.posit.x = pVVar15->x;
    MStack_170.posit.y = pVVar15->y;
    MStack_170.posit.z = pVVar15->z;
    v_01.y = VStack_12c.y;
    v_01.x = VStack_12c.x;
    v_01.z = VStack_12c.z;
    local_1d4 = (Matrix *)GetLength3D(v_01);
    pVVar15 = &VStack_1d0;
    iVar12 = (int)pfVar8[0x3b] * 0x390;
    VStack_1d0.x = (float)local_1d4 * *(float *)(iVar12 + 0xcc + (int)local_1bc);
    VStack_1d0.y = *(float *)(iVar12 + 0xd0 + (int)local_1bc) * (float)local_1d4;
    VStack_1d0.z = (float)((float)local_1d4 * *(float *)(iVar12 + 0xd4 + (int)local_1bc));
  }
  dVar27 = (double)ZEXT48(in_stack_fffffe00);
  local_1ac.x = pVVar15->x;
  local_1ac.y = pVVar15->y;
  local_1ac.z = pVVar15->z;
  fVar10 = pfVar8[0x3b];
  if (*(char *)((int)fVar10 * 0x390 + 0x16 + (int)local_1bc) != '\0') {
    pfVar22 = (float *)((int)fVar10 * 0x390 + 0xdc + (int)local_1bc);
    MStack_170.posit.x = *pfVar22;
    MStack_170.posit.y = pfVar22[1];
    MStack_170.posit.z = pfVar22[2];
    fVar10 = pfVar8[0x3b];
  }
  pcVar21 = local_1bc;
  if (auStack_1d8[3] != '\0') {
    FormatLogMessage("Entrance Front Vector Is %f %f %f",
                     (double)CONCAT44(SUB84((double)pfVar8[0x34],0),
                                      (int)((ulonglong)(double)pfVar8[0x33] >> 0x20)),
                     (double)CONCAT44(SUB84((double)pfVar8[0x35],0),
                                      (int)((ulonglong)(double)pfVar8[0x34] >> 0x20)),
                     (double)CONCAT44(unaff_EDI,(int)((ulonglong)(double)pfVar8[0x35] >> 0x20)));
    iVar20 = (int)pfVar8[0x3b] * 0x390;
    iVar12 = *(int *)&this->PortalList;
    dVar27 = (double)*(float *)(iVar20 + 0xd4 + iVar12);
    dVar1 = (double)*(float *)(iVar20 + 0xd0 + iVar12);
    FormatLogMessage("Exit Front Vector Is %f %f %f",
                     (double)CONCAT44(SUB84(dVar1,0),
                                      (int)((ulonglong)(double)*(float *)(iVar20 + 0xcc + iVar12) >>
                                           0x20)),
                     (double)CONCAT44(SUB84(dVar27,0),(int)((ulonglong)dVar1 >> 0x20)),
                     (double)CONCAT44(unaff_EDI,(int)((ulonglong)dVar27 >> 0x20)));
    FormatLogMessage("Player Front Vector Is %f %f %f",
                     (double)CONCAT44(SUB84((double)MStack_108.front.y,0),
                                      (int)((ulonglong)(double)MStack_108.front.x >> 0x20)),
                     (double)CONCAT44(SUB84((double)MStack_108.front.z,0),
                                      (int)((ulonglong)(double)MStack_108.front.y >> 0x20)),
                     (double)CONCAT44(unaff_EDI,(int)((ulonglong)(double)MStack_108.front.z >> 0x20)
                                     ));
    FormatLogMessage("Player Up Vector Is %f %f %f",
                     (double)CONCAT44(SUB84((double)MStack_108.up.y,0),
                                      (int)((ulonglong)(double)MStack_108.up.x >> 0x20)),
                     (double)CONCAT44(SUB84((double)MStack_108.up.z,0),
                                      (int)((ulonglong)(double)MStack_108.up.y >> 0x20)),
                     (double)CONCAT44(unaff_EDI,(int)((ulonglong)(double)MStack_108.up.z >> 0x20)));
    FormatLogMessage("Player Right Vector Is %f %f %f",
                     (double)CONCAT44(SUB84((double)MStack_108.right.y,0),
                                      (int)((ulonglong)(double)MStack_108.right.x >> 0x20)),
                     (double)CONCAT44(SUB84((double)MStack_108.right.z,0),
                                      (int)((ulonglong)(double)MStack_108.right.y >> 0x20)),
                     (double)CONCAT44(unaff_EDI,(int)((ulonglong)(double)MStack_108.right.z >> 0x20)
                                     ));
    FormatLogMessage("Player Velocity Vector Is %f %f %f",
                     (double)CONCAT44(SUB84((double)VStack_12c.y,0),
                                      (int)((ulonglong)(double)VStack_12c.x >> 0x20)),
                     (double)CONCAT44(SUB84((double)VStack_12c.z,0),
                                      (int)((ulonglong)(double)VStack_12c.y >> 0x20)),
                     (double)CONCAT44(unaff_EDI,(int)((ulonglong)(double)VStack_12c.z >> 0x20)));
    FormatLogMessage("New Front Vector Is %f %f %f",
                     (double)CONCAT44(SUB84((double)MStack_170.front.y,0),
                                      (int)((ulonglong)(double)MStack_170.front.x >> 0x20)),
                     (double)CONCAT44(SUB84((double)MStack_170.front.z,0),
                                      (int)((ulonglong)(double)MStack_170.front.y >> 0x20)),
                     (double)CONCAT44(unaff_EDI,(int)((ulonglong)(double)MStack_170.front.z >> 0x20)
                                     ));
    FormatLogMessage("New Up Vector Is %f %f %f",
                     (double)CONCAT44(SUB84((double)MStack_170.up.y,0),
                                      (int)((ulonglong)(double)MStack_170.up.x >> 0x20)),
                     (double)CONCAT44(SUB84((double)MStack_170.up.z,0),
                                      (int)((ulonglong)(double)MStack_170.up.y >> 0x20)),
                     (double)CONCAT44(unaff_EDI,(int)((ulonglong)(double)MStack_170.up.z >> 0x20)));
    FormatLogMessage("New Right Vector Is %f %f %f",
                     (double)CONCAT44(SUB84((double)MStack_170.right.y,0),
                                      (int)((ulonglong)(double)MStack_170.right.x >> 0x20)),
                     (double)CONCAT44(SUB84((double)MStack_170.right.z,0),
                                      (int)((ulonglong)(double)MStack_170.right.y >> 0x20)),
                     (double)CONCAT44(unaff_EDI,(int)((ulonglong)(double)MStack_170.right.z >> 0x20)
                                     ));
    dVar27 = (double)local_1ac.x;
    in_stack_fffffdfc = "New Velocity Vector Is %f %f %f";
    in_stack_fffffdf8 = 0x4fc29870;
    FormatLogMessage("New Velocity Vector Is %f %f %f",
                     (double)CONCAT44(SUB84((double)local_1ac.y,0),(int)((ulonglong)dVar27 >> 0x20))
                     ,(double)CONCAT44(SUB84((double)local_1ac.z,0),
                                       (int)((ulonglong)(double)local_1ac.y >> 0x20)),
                     (double)CONCAT44(unaff_EDI,(int)((ulonglong)(double)local_1ac.z >> 0x20)));
    fVar10 = pfVar8[0x3b];
    pcVar21 = *(code **)&this->PortalList;
  }
  iVar12 = (int)fVar10 * 0x390;
  fVar10 = *(float *)(iVar12 + 0x84 + (int)pcVar21);
  if (fVar10 != 0.0) {
    if (*(char *)(iVar12 + 0x13 + (int)pcVar21) != '\0') {
      local_1ac.x = *(float *)(iVar12 + 0xcc + (int)pcVar21);
      local_1ac.y = *(float *)(iVar12 + 0xd0 + (int)pcVar21);
      local_1ac.z = *(float *)(iVar12 + 0xd4 + (int)pcVar21);
    }
    VStack_1d0.y = local_1ac.y * fVar10;
    VStack_1d0.x = local_1ac.x * fVar10;
    VStack_1d0.z = local_1ac.z * fVar10;
    local_1ac.x = VStack_1d0.x;
    local_1ac.y = VStack_1d0.y;
    local_1ac.z = VStack_1d0.z;
  }
  cStack_1c1 = IsPlayer((int)local_1c0);
  v_02.y = local_1ac.y;
  v_02.x = local_1ac.x;
  v_02.z = local_1ac.z;
  bVar7 = IsNullVector(v_02);
  if ((bVar7) ||
     ((*(char *)(extraout_EDX * 0x390 + 0x17 + extraout_ECX) != '\0' && (cStack_1c1 == '\0')))) {
    iVar12 = extraout_EDX * 0x390;
    VStack_1d0.x = *(float *)(iVar12 + 0xcc + extraout_ECX) * 20.0;
    VStack_1d0.y = *(float *)(iVar12 + 0xd0 + extraout_ECX) * 20.0;
    VStack_1d0.z = *(float *)(iVar12 + 0xd4 + extraout_ECX) * 20.0;
    local_1ac.x = VStack_1d0.x;
    local_1ac.y = VStack_1d0.y;
    local_1ac.z = VStack_1d0.z;
  }
  SetCurAmmo((int)*pfVar8,0);
  pMVar9 = local_1c0;
  pMVar14 = SUB84(dVar27,0);
  if (local_1b0 != (Matrix *)0x0) {
    Deploy((int)local_1c0);
    pMVar14 = SUB84(dVar27,0);
  }
  local_1d4 = (Matrix *)SetPosition_exref;
  pMVar26 = pMVar9;
  SetPosition((int)pMVar9,&MStack_170);
  pVVar15 = &local_1ac;
  local_18c = SetVelocity_exref;
  pVVar25 = (Vector *)0x4fc299ea;
  pMVar17 = pMVar9;
  SetVelocity((int)pMVar9,pVVar15);
  if (local_1b0 != (Matrix *)0x0) {
    pMVar14 = &MStack_c8;
    pMVar9 = local_1b0;
    GetPosition((int)local_1b0,pMVar14);
    Vector_TransformInv(&MStack_c8.posit,pMVar9,&pMVar14->right);
    fStack_114 = MStack_170.posit.x;
    fStack_110 = MStack_170.posit.y;
    fStack_10c = MStack_170.posit.z;
    pMVar14 = Matrix_Multiply(aMStack_88,unaff_EDI,unaff_ESI);
    pMVar9 = &MStack_170;
    for (iVar12 = 0x10; iVar12 != 0; iVar12 = iVar12 + -1) {
      (pMVar9->right).x = (pMVar14->right).x;
      pMVar14 = (Matrix *)&(pMVar14->right).y;
      pMVar9 = (Matrix *)&(pMVar9->right).y;
    }
    if (*(char *)((int)pfVar8[0x3b] * 0x390 + 0x13 + *(int *)&this->PortalList) == '\0') {
      MStack_170.right.x = -MStack_170.right.x;
      MStack_170.right.y = -MStack_170.right.y;
      MStack_170.right.z = -MStack_170.right.z;
      VStack_1d0.x = -MStack_170.front.x;
      VStack_1d0.y = -MStack_170.front.y;
      VStack_1d0.z = (float)((uint)MStack_170.front.z ^ 0x80000000);
      MStack_170.front.x = VStack_1d0.x;
      MStack_170.front.y = VStack_1d0.y;
      MStack_170.front.z = VStack_1d0.z;
    }
    MStack_170.posit.x = fStack_114;
    MStack_170.posit.y = fStack_110;
    MStack_170.posit.z = fStack_10c;
    pVVar15 = Vector_Transform(&VStack_120,unaff_EDI,&unaff_ESI->right);
    pvVar6 = local_198;
    MStack_170.posit.x = pVVar15->x;
    MStack_170.posit.y = pVVar15->y;
    MStack_170.posit.z = pVVar15->z;
    std::
    vector<PortalHelper::TeleportTargetClass,std::allocator<PortalHelper::TeleportTargetClass>_>::
    _Resize<<lambda_f2c0a61063d8731356913bf41ed3079e>_>
              (local_198,(*(int *)&local_198->field_0x4 - *(int *)local_198) / 0x14 + 1,
               (<lambda_f2c0a61063d8731356913bf41ed3079e>)local_198);
    pMVar14 = local_1b0;
    iVar12 = *(int *)pvVar6;
    iVar20 = ((*(int *)&pvVar6->field_0x4 - iVar12) / 0x14) * 0x14;
    *(undefined4 *)(iVar20 + -0x10 + iVar12) = 0;
    *(undefined4 *)(iVar20 + -0xc + iVar12) = 0;
    *(undefined4 *)(iVar20 + -8 + iVar12) = 0;
    *(undefined4 *)(iVar20 + -4 + iVar12) = 0;
    *(Matrix **)(iVar20 + -0x14 + iVar12) = local_1b0;
    *(undefined4 *)(iVar20 + -8 + iVar12) =
         *(undefined4 *)((int)pfVar8[0x3b] * 0x390 + 0x80 + *(int *)&this->PortalList);
    *(float *)(iVar20 + -0x10 + iVar12) = pfVar8[1];
    pMVar26 = local_1b0;
    SetPosition((int)local_1b0,&MStack_170);
    pVVar15 = &local_1ac;
    pMVar17 = pMVar14;
    (*local_18c)();
    pMVar9 = local_1c0;
    pVVar25 = (Vector *)0x1;
    in_stack_fffffdf8 = 0x4fc29bcd;
    in_stack_fffffdfc = (char *)local_1c0;
    Pickup((int)local_1c0,(int)pMVar14,1);
  }
  uVar28 = 0x4fc29bd4;
  pMVar16 = (Matrix *)(*local_17c)();
  if ((pMVar9 == pMVar16) && (pfVar8[0x42] != 0.0)) {
    SetColorFade(1.0,5.0,(ulong)pfVar8[0x42]);
    pMVar14 = (Matrix *)(pfVar8 + 0xc3);
    uVar28 = 0;
    pMVar26 = (Matrix *)0x0;
    in_stack_fffffdfc = (char *)0x4fc29c22;
    pVVar25 = local_194;
    pMVar17 = local_1b8;
    pVVar15 = local_194;
    (*local_190)();
  }
  BZ1Helper::m_BZ1Helper->StopAddObject = true;
  if (*(char *)((int)pfVar8 + 0x1b) == '\0') {
    pVVar15 = (Vector *)pfVar8[0x3c];
    uVar28 = (uint)(*(char *)(pfVar8 + 6) == '\0');
    pMVar26 = (Matrix *)0x0;
    pMVar17 = (Matrix *)(((int)pfVar8 - *(int *)&this->PortalList) / 0x390);
    pVVar25 = (Vector *)0x4fc29c9a;
    SetPortalEffectEnd_Internal(this,(int)pMVar17,(int)pVVar15,0,*(char *)(pfVar8 + 6) == '\0');
  }
  else {
    pMVar9 = &MStack_108;
    pfVar22 = (float *)&stack0xfffffdd8;
    for (iVar12 = 0x10; iVar12 != 0; iVar12 = iVar12 + -1) {
      *pfVar22 = (pMVar9->right).x;
      pMVar9 = (Matrix *)&(pMVar9->right).y;
      pfVar22 = pfVar22 + 1;
    }
    MVar3.right.y = 0.0;
    MVar3.right.x = pfVar8[0x3f];
    auVar24 = in_stack_fffffdd8._8_12_;
    MVar3.right.z = (float)in_stack_fffffdd8._0_4_;
    MVar3.rightw = (float)in_stack_fffffdd8._4_4_;
    MVar3.up.x = (float)auVar24._0_4_;
    MVar3.up.y = (float)auVar24._4_4_;
    MVar3.up.z = (float)auVar24._8_4_;
    MVar3.upw = (float)in_stack_fffffdec;
    MVar3.front.x = (float)in_stack_fffffdf0;
    MVar3.front.y = (float)in_stack_fffffdf4;
    MVar3.front.z = (float)in_stack_fffffdf8;
    MVar3.frontw = (float)in_stack_fffffdfc;
    MVar3.posit.x = (float)pMVar14;
    MVar3.posit.y = (float)pVVar25;
    MVar3.posit.z = (float)pMVar17;
    MVar3.positw = (float)pVVar15;
    SetPortalEffectVeh_Internal
              (this,((int)pfVar8 - *(int *)&this->PortalList) / 0x390,MVar3,(int)pMVar26,uVar28);
  }
  fVar10 = pfVar8[0x3b];
  fVar19 = *(float *)&this->PortalList;
  iVar12 = (int)fVar10 * 0x390;
  if (*(char *)(iVar12 + 0x1b + (int)fVar19) == '\0') {
    local_1d4 = *(Matrix **)(iVar12 + 0xf4 + (int)fVar19);
    SetPortalEffectEnd_Internal
              (this,(int)fVar10,(int)local_1d4,0,*(char *)(iVar12 + 0x18 + (int)fVar19) == '\0');
  }
  else {
    pMVar9 = &MStack_170;
    pfVar8 = (float *)&stack0xfffffdd8;
    local_1d4 = (Matrix *)fVar19;
    for (iVar20 = 0x10; iVar20 != 0; iVar20 = iVar20 + -1) {
      *pfVar8 = (pMVar9->right).x;
      pMVar9 = (Matrix *)&(pMVar9->right).y;
      pfVar8 = pfVar8 + 1;
    }
    MVar4.right.y = 0.0;
    MVar4.right.x = (float)*(uint *)(iVar12 + 0x100 + (int)local_1d4);
    auVar24 = in_stack_fffffdd8._8_12_;
    MVar4.right.z = (float)in_stack_fffffdd8._0_4_;
    MVar4.rightw = (float)in_stack_fffffdd8._4_4_;
    MVar4.up.x = (float)auVar24._0_4_;
    MVar4.up.y = (float)auVar24._4_4_;
    MVar4.up.z = (float)auVar24._8_4_;
    MVar4.upw = (float)in_stack_fffffdec;
    MVar4.front.x = (float)in_stack_fffffdf0;
    MVar4.front.y = (float)in_stack_fffffdf4;
    MVar4.front.z = (float)in_stack_fffffdf8;
    MVar4.frontw = (float)in_stack_fffffdfc;
    MVar4.posit.x = (float)pMVar14;
    MVar4.posit.y = (float)pVVar25;
    MVar4.posit.z = (float)pMVar17;
    MVar4.positw = (float)pVVar15;
    SetPortalEffectVeh_Internal(this,(int)fVar10,MVar4,(int)pMVar26,uVar28);
  }
  pMVar14 = local_1c0;
  pDVar5 = &BZ1Helper::m_BZ1Helper->super_DLLBase;
  BZ1Helper::m_BZ1Helper->StopAddObject = false;
  iVar12 = (**(code **)((int)*pDVar5 + 0x60))();
  pMVar9 = unaff_EDI;
  pMVar17 = unaff_ESI;
  if ((((local_1b8 != (Matrix *)0x0) || (VStack_1d0.y._3_1_ != '\0')) || (iVar12 != 0)) ||
     (AVar18 = GetCurrentCommand((int)pMVar14), pMVar9 = unaff_EDI, AVar18 != CMD_GO))
  goto LAB_4fc29e49;
  GetCurrentCommandWhere((Vector *)auStack_1d8,(int)pMVar14);
  fVar19 = (float)GetCurrentWho((int)pMVar14);
  fVar10 = (unaff_ESI->right).x;
  if (fVar19 != fVar10) {
    v.y = (float)local_1d4;
    v.x = (float)auStack_1d8;
    v.z = VStack_1d0.x;
    bVar7 = IsNullVector(v);
    pMVar9 = unaff_EDI;
    if (bVar7) goto LAB_4fc29e49;
    fVar19 = pMVar17[3].front.y - VStack_1d0.x;
    fVar2 = pMVar17[3].upw - (float)auStack_1d8;
    local_190 = (code *)(fVar19 * fVar19 + fVar2 * fVar2);
    fVar23 = (float10)__CIsqrt();
    local_190 = (code *)(float)fVar23;
    pMVar14 = (Matrix *)VStack_1d0.z;
    if ((0.1 <= (float)local_190) &&
       (v_00.y = (float)local_1d4, v_00.x = (float)auStack_1d8, v_00.z = VStack_1d0.x,
       fVar10 = GetDistance((int)fVar10,v_00), pMVar14 = (Matrix *)VStack_1d0.z, pMVar9 = unaff_EDI,
       pMVar17[2].right.x + 25.0 <= fVar10)) goto LAB_4fc29e49;
  }
  pMVar9 = unaff_EDI;
  (*local_180)();
  SetCommand((int)pMVar14,0,0,0,(char *)0x0,0);
LAB_4fc29e49:
  cStack_1dd = (char)((uint)this >> 0x18);
  if (cStack_1dd != '\0') {
    fVar10 = (unaff_EDI->right).x;
    fVar23 = (float10)__CIsqrt();
    local_188 = (double)CONCAT44(local_188._4_4_,(float)fVar23);
    dVar27 = (double)(float)fVar23;
    pcVar13 = GetLabel(objectInfo->ObjectHandle);
    FormatLogMessage("Teleporter on Team: %d Index: %d Aquired Target on Team: %d Handle: %08x Label: %s Distance is: %f"
                     ,(int)local_1ac.z,((int)pMVar17 - (int)fVar10) / 0x390,(int)local_17c,
                     objectInfo->ObjectHandle,pcVar13,dVar27);
  }
  if (pMVar17->rightw != 0.0) {
    BZ1Helper::DeleteAfterDelay(BZ1Helper::m_BZ1Helper,(int)(pMVar17->right).x,(float)local_1c0);
    BZ1Helper::DeleteAfterDelay
              (BZ1Helper::m_BZ1Helper,
               *(int *)((int)pMVar17[3].frontw * 0x390 + (int)(pMVar9->right).x),(float)local_1c0);
  }
  return;
}


// ---------------------------------------------------------------------
// PortalHelper::SetPortalEffectStart_Internal  @ 4fc29eeb  lines 1234-1333

void __thiscall
PortalHelper::SetPortalEffectStart_Internal
          (PortalHelper *this,int param_1,int param_2,int param_3,bool param_4)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  long fmtarg5;
  int iVar4;
  undefined1 uVar5;
  int iVar6;
  
  bVar1 = BZ1Helper::Logging;
  iVar4 = param_1 * 0x390;
  iVar3 = *(int *)(iVar4 + 8 + *(int *)&this->PortalList);
  bVar2 = IsEmitterOn(*(int *)(iVar4 + *(int *)&this->PortalList),iVar3);
  if (bVar2) {
    if (param_3 != 2) {
      if (param_3 != 1) {
        return;
      }
      SetPortalEffectOn_Internal(this,param_1,param_2,1,SUB41(iVar3,0));
      return;
    }
    iVar3 = 2;
  }
  else {
    if (param_3 != 0) {
      iVar3 = param_1 * 0xe4 + param_2;
      if (*(int *)(*(int *)&this->PortalList + 0x248 + iVar3 * 4) < 1) {
        return;
      }
      iVar6 = param_2;
      StartEmitter(*(int *)(*(int *)&this->PortalList + iVar4),param_2);
      uVar5 = (undefined1)iVar6;
      StopEmitter(*(int *)(iVar4 + *(int *)&this->PortalList),
                  *(int *)(iVar4 + 8 + *(int *)&this->PortalList));
      *(int *)(iVar4 + 8 + *(int *)&this->PortalList) = param_2;
      *(int *)(iVar4 + 0x34 + *(int *)&this->PortalList) = param_3;
      *(undefined4 *)(iVar4 + 0x3c + *(int *)&this->PortalList) = 1;
      *(int *)(iVar4 + 0x38 + *(int *)&this->PortalList) = param_2;
      *(int *)(*(int *)&this->PortalList + 0x3c + iVar3 * 4) =
           *(int *)(*(int *)&this->PortalList + 0x248 + iVar3 * 4) + 1;
      PlayPortalSoundFx(this,param_1,0,(bool)uVar5);
      if (!bVar1) {
        return;
      }
      iVar6 = *(int *)&this->PortalList;
      fmtarg5 = GetEmitterMask(*(int *)(iVar6 + iVar4));
      FormatConsoleMessage
                ("PortalFx_Start FxNum: %d, Type: %d, EffectHard%d, LifeTime: %d, EffectMask: %d",
                 param_2,param_3,*(int *)(iVar6 + 8 + iVar4),*(int *)(iVar6 + 0x248 + iVar3 * 4),
                 fmtarg5);
      return;
    }
    iVar3 = 0;
  }
  SetPortalEffectEnd_Internal(this,param_1,param_2,iVar3,true);
  return;
}


// ---------------------------------------------------------------------
// PortalHelper::SetPortalEffectOn_Internal  @ 4fc2a015  lines 1351-1409

void __thiscall
PortalHelper::SetPortalEffectOn_Internal
          (PortalHelper *this,int param_1,int param_2,int param_3,bool param_4)

{
  int iVar1;
  bool bVar2;
  bool bVar3;
  long fmtarg5;
  int iVar4;
  
  bVar2 = BZ1Helper::Logging;
  iVar4 = param_1 * 0x390;
  bVar3 = IsEmitterOn(*(int *)(iVar4 + *(int *)&this->PortalList),
                      *(int *)(iVar4 + 8 + *(int *)&this->PortalList));
  if (bVar3) {
    StopEmitter(*(int *)(iVar4 + *(int *)&this->PortalList),
                *(int *)(iVar4 + 8 + *(int *)&this->PortalList));
  }
  StartEmitter(*(int *)(iVar4 + *(int *)&this->PortalList),param_2 + 1);
  *(int *)(iVar4 + 8 + *(int *)&this->PortalList) = param_2 + 1;
  *(int *)(iVar4 + 0x34 + *(int *)&this->PortalList) = param_3;
  *(undefined4 *)(iVar4 + 0x3c + *(int *)&this->PortalList) = 2;
  *(int *)(iVar4 + 0x38 + *(int *)&this->PortalList) = param_2;
  if (bVar2) {
    iVar1 = *(int *)&this->PortalList;
    fmtarg5 = GetEmitterMask(*(int *)(iVar1 + iVar4));
    FormatConsoleMessage
              ("PortalFx_On FxNum: %d, Type: %d, EffectHard%d, LifeTime: %d, EffectMask: %d",param_2
               ,param_3,*(int *)(iVar1 + 8 + iVar4),
               *(int *)(iVar1 + 0x248 + (param_1 * 0xe4 + param_2 + 1) * 4),fmtarg5);
  }
  return;
}


// ---------------------------------------------------------------------
// PortalHelper::SetPortalEffectEnd  @ 4fc2a0d0  lines 1413-1425

void __thiscall
PortalHelper::SetPortalEffectEnd
          (PortalHelper *this,int param_1,int param_2,int param_3,bool param_4)

{
  bool bVar1;
  int *piVar2;
  
  bVar1 = IsAround(param_1);
  if ((bVar1) &&
     (piVar2 = *(int **)&this->PortalList, piVar2 != *(int **)&(this->PortalList).field_0x4)) {
    do {
      if (*piVar2 == param_1) {
        SetPortalEffectEnd_Internal
                  (this,((int)piVar2 - *(int *)&this->PortalList) / 0x390,param_2,param_3,true);
        return;
      }
      piVar2 = piVar2 + 0xe4;
    } while (piVar2 != *(int **)&(this->PortalList).field_0x4);
  }
  return;
}


// ---------------------------------------------------------------------
// PortalHelper::SetPortalEffectEnd_Internal  @ 4fc2a119  lines 1427-1514

void __thiscall
PortalHelper::SetPortalEffectEnd_Internal
          (PortalHelper *this,int Index,int FxNumber,int Type,bool ReplaceEffect)

{
  int iVar1;
  bool bVar2;
  long fmtarg5;
  int iVar3;
  int iVar4;
  int iVar5;
  
  bVar2 = BZ1Helper::Logging;
  iVar3 = Index * 0xe4 + FxNumber + 2;
  if (*(int *)(*(int *)&this->PortalList + 0x248 + iVar3 * 4) < 1) {
    return;
  }
  iVar4 = Index * 0x390;
  StartEmitter(*(int *)(iVar4 + *(int *)&this->PortalList),FxNumber + 2);
  if (ReplaceEffect) {
    StopEmitter(*(int *)(iVar4 + *(int *)&this->PortalList),
                *(int *)(iVar4 + 8 + *(int *)&this->PortalList));
    *(int *)(iVar4 + 8 + *(int *)&this->PortalList) = FxNumber + 2;
    *(int *)(iVar4 + 0x34 + *(int *)&this->PortalList) = Type;
    *(undefined4 *)(iVar4 + 0x3c + *(int *)&this->PortalList) = 3;
    *(int *)(iVar4 + 0x38 + *(int *)&this->PortalList) = FxNumber;
  }
  iVar1 = *(int *)&this->PortalList;
  *(int *)(iVar1 + 0x3c + iVar3 * 4) = *(int *)(iVar1 + 0x248 + iVar3 * 4) + 1;
  if (*(char *)(iVar4 + 0x18 + *(int *)&this->PortalList) == '\0') {
    iVar5 = 1;
  }
  else {
    if (ReplaceEffect) goto LAB_4fc2a1cd;
    iVar5 = 0;
  }
  PlayPortalSoundFx(this,Index,iVar5,SUB41(iVar1,0));
LAB_4fc2a1cd:
  if (bVar2) {
    iVar1 = *(int *)&this->PortalList;
    fmtarg5 = GetEmitterMask(*(int *)(iVar1 + iVar4));
    FormatConsoleMessage
              ("PortalFx_End FxNum: %d, Type: %d, EffectHard%d, LifeTime: %d, EffectMask: %d",
               FxNumber,Type,*(int *)(iVar1 + 8 + iVar4),*(int *)(iVar1 + 0x248 + iVar3 * 4),fmtarg5
              );
  }
  return;
}


// ---------------------------------------------------------------------
// PortalHelper::SetPortalEffectVeh_Internal  @ 4fc2a209  lines 1536-1562

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall
PortalHelper::SetPortalEffectVeh_Internal
          (PortalHelper *this,int param_1,Matrix param_2,int param_3,int param_4)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  char *fmtarg1;
  char *pcVar6;
  undefined1 auStack_50 [4];
  float local_4c;
  char local_48 [68];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)auStack_50;
  pcVar5 = (char *)(param_1 * 0x390 + 0x20c + *(int *)&this->PortalList);
  pcVar6 = pcVar5 + 1;
  do {
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  fmtarg1 = (char *)(*(int *)&this->PortalList + param_1 * 0x390 + 0x20c);
  if ((uint)((int)pcVar5 - (int)pcVar6) < 0x39U - (int)param_2.right.x) {
    memset(local_48,0,0x40);
    sprintf_s<64>((char (*) [64])local_48,"%s%dEnd",fmtarg1,(int)param_2.right.x);
    bVar2 = DoesODFExist(local_48);
    if (bVar2) {
      BZ1Helper::m_BZ1Helper->StopAddObject = true;
      iVar3 = BuildObject(local_48,0,(Matrix *)&param_2.right.z);
      BZ1Helper::m_BZ1Helper->StopAddObject = false;
      CombineStrings(local_48,local_48,".odf",0x40);
      local_4c = 0.0;
      bVar2 = OpenODF2(local_48);
      if (!bVar2) {
        return;
      }
      iVar4 = GetODFFloat(local_48,(char *)0x0,"Render","lifeTime",&local_4c,0.0);
      if (iVar4 == 0) {
        return;
      }
      SetLifespan(iVar3,local_4c);
      return;
    }
    if (*(char *)(*(int *)&this->PortalList + 0x20c + param_1 * 0x390) == '\0') {
      return;
    }
    pcVar6 = "Teleport Effect \'%s\' does not exist. Fix ODFs!";
  }
  else {
    if (*fmtarg1 == '\0') {
      return;
    }
    pcVar6 = "Teleport Effect ODF \'%s\' is too long. Fix ODFs!";
  }
  FormatLogMessage(pcVar6);
  return;
}


// ---------------------------------------------------------------------
// PortalHelper::SetPortalDest  @ 4fc2a361  lines 1603-1643

/* WARNING: Type propagation algorithm not settling */

bool __thiscall PortalHelper::SetPortalDest(PortalHelper *this,int me,int him)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  bool bVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  
  bVar4 = IsAround(me);
  if ((!bVar4) || (bVar4 = IsAround(him), !bVar4)) {
    return false;
  }
  iVar7 = -1;
  piVar2 = *(int **)&(this->PortalList).field_0x4;
  piVar1 = *(int **)&this->PortalList;
  for (piVar5 = piVar1; piVar3 = piVar1, piVar5 != piVar2; piVar5 = piVar5 + 0xe4) {
    if (*piVar5 == me) {
      iVar6 = ((int)piVar5 - (int)piVar1) / 0x390;
      goto joined_r0x4fc2a3b4;
    }
  }
  iVar6 = -1;
joined_r0x4fc2a3b4:
  do {
    if (piVar3 == piVar2) {
LAB_4fc2a3e3:
      if (iVar6 == -1) {
        return false;
      }
      if (iVar7 == -1) {
        return false;
      }
      piVar1[iVar6 * 0xe4 + 1] = piVar1[iVar7 * 0xe4];
      *(int *)(iVar6 * 0x390 + 0xec + *(int *)&this->PortalList) = iVar7;
      *(undefined1 *)(iVar6 * 0x390 + 0x1a + *(int *)&this->PortalList) = 1;
      return true;
    }
    if (*piVar3 == him) {
      iVar7 = ((int)piVar3 - (int)piVar1) / 0x390;
      goto LAB_4fc2a3e3;
    }
    piVar3 = piVar3 + 0xe4;
  } while( true );
}


// ---------------------------------------------------------------------
// PortalHelper::ShufflePortalDownInternal  @ 4fc2a41d  lines 1754-1821

void __thiscall PortalHelper::ShufflePortalDownInternal(PortalHelper *this,int Index)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined4 local_390 [228];
  
  if (-1 < Index) {
    iVar1 = *(int *)&this->PortalList;
    iVar4 = (*(int *)&(this->PortalList).field_0x4 - iVar1) / 0x390 + -1;
    if ((-1 < iVar4) && (0 < iVar4)) {
      iVar6 = 0;
      if (Index <= iVar4) {
        iVar6 = Index;
      }
      iVar5 = Index * 0x390;
      iVar3 = iVar6;
      do {
        iVar8 = iVar3 * 0x390;
        if ((*(int *)(iVar8 + 0x1c + iVar1) == 1) &&
           (((*(char *)(iVar5 + 0x12 + iVar1) == '\0' ||
             (*(int *)(iVar5 + 0x24 + iVar1) == *(int *)(iVar8 + 0x24 + iVar1))) &&
            (*(int *)(iVar5 + iVar1) != *(int *)(iVar8 + iVar1))))) {
          if (iVar3 < 0) {
            return;
          }
          puVar2 = (undefined4 *)(iVar3 * 0x390 + iVar1);
          puVar7 = puVar2;
          puVar9 = local_390;
          for (iVar4 = 0xe4; iVar4 != 0; iVar4 = iVar4 + -1) {
            *puVar9 = *puVar7;
            puVar7 = puVar7 + 1;
            puVar9 = puVar9 + 1;
          }
          puVar7 = (undefined4 *)(iVar5 + iVar1);
          for (iVar4 = 0xe4; iVar4 != 0; iVar4 = iVar4 + -1) {
            *puVar2 = *puVar7;
            puVar7 = puVar7 + 1;
            puVar2 = puVar2 + 1;
          }
          puVar7 = local_390;
          puVar2 = (undefined4 *)(iVar5 + iVar1);
          for (iVar4 = 0xe4; iVar4 != 0; iVar4 = iVar4 + -1) {
            *puVar2 = *puVar7;
            puVar7 = puVar7 + 1;
            puVar2 = puVar2 + 1;
          }
          return;
        }
        iVar8 = iVar3 + 1;
        iVar3 = 0;
        if (iVar8 <= iVar4) {
          iVar3 = iVar8;
        }
      } while (iVar3 != iVar6);
    }
  }
  return;
}


// ---------------------------------------------------------------------
// PortalHelper::ShufflePortalUpInternal  @ 4fc2a4d2  lines 1851-1897

void __thiscall PortalHelper::ShufflePortalUpInternal(PortalHelper *this,int Index)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined4 local_390 [228];
  
  if (-1 < Index) {
    iVar1 = *(int *)&this->PortalList;
    iVar2 = (*(int *)&(this->PortalList).field_0x4 - iVar1) / 0x390;
    iVar4 = iVar2 + -1;
    if ((-1 < iVar4) && (0 < iVar4)) {
      iVar6 = 0;
      if (Index <= iVar4) {
        iVar6 = Index;
      }
      iVar8 = Index * 0x390;
      iVar4 = iVar6;
      do {
        iVar5 = iVar4 * 0x390;
        if ((*(int *)(iVar5 + 0x1c + iVar1) == 1) &&
           (((*(char *)(iVar8 + 0x12 + iVar1) == '\0' ||
             (*(int *)(iVar8 + 0x24 + iVar1) == *(int *)(iVar5 + 0x24 + iVar1))) &&
            (*(int *)(iVar8 + iVar1) != *(int *)(iVar5 + iVar1))))) {
          if (iVar4 < 0) {
            return;
          }
          puVar3 = (undefined4 *)(iVar4 * 0x390 + iVar1);
          puVar7 = puVar3;
          puVar9 = local_390;
          for (iVar4 = 0xe4; iVar4 != 0; iVar4 = iVar4 + -1) {
            *puVar9 = *puVar7;
            puVar7 = puVar7 + 1;
            puVar9 = puVar9 + 1;
          }
          puVar7 = (undefined4 *)(iVar8 + iVar1);
          for (iVar4 = 0xe4; iVar4 != 0; iVar4 = iVar4 + -1) {
            *puVar3 = *puVar7;
            puVar7 = puVar7 + 1;
            puVar3 = puVar3 + 1;
          }
          puVar7 = local_390;
          puVar3 = (undefined4 *)(iVar8 + iVar1);
          for (iVar4 = 0xe4; iVar4 != 0; iVar4 = iVar4 + -1) {
            *puVar3 = *puVar7;
            puVar7 = puVar7 + 1;
            puVar3 = puVar3 + 1;
          }
          return;
        }
        iVar5 = iVar2;
        if (-1 < iVar4 + -1) {
          iVar5 = iVar4;
        }
        iVar4 = iVar5 + -1;
      } while (iVar4 != iVar6);
    }
  }
  return;
}


// ---------------------------------------------------------------------
// PortalHelper::ResetPortalDestinations  @ 4fc2a592  lines 1901-1914

void __thiscall PortalHelper::ResetPortalDestinations(PortalHelper *this,int Channel)

{
  int iVar1;
  
  iVar1 = *(int *)&this->PortalList;
  if (iVar1 != *(int *)&(this->PortalList).field_0x4) {
    do {
      if ((*(char *)(iVar1 + 0x1a) == '\0') &&
         ((*(char *)(iVar1 + 0x12) == '\0' || (*(int *)(iVar1 + 0x24) == Channel)))) {
        *(undefined4 *)(iVar1 + 4) = 0;
        *(undefined4 *)(iVar1 + 0xec) = 0;
      }
      iVar1 = iVar1 + 0x390;
    } while (iVar1 != *(int *)&(this->PortalList).field_0x4);
  }
  return;
}


// ---------------------------------------------------------------------
// PortalHelper::SortCycleList  @ 4fc2a5c6  lines 1918-1935

void __thiscall PortalHelper::SortCycleList(PortalHelper *this,int Channel)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = -1;
  iVar3 = *(int *)&this->PortalList;
  if (iVar3 != *(int *)&(this->PortalList).field_0x4) {
    do {
      iVar2 = iVar1;
      if ((*(int *)(iVar3 + 0x1c) == 1) &&
         (((*(char *)(iVar3 + 0x12) == '\0' || (*(int *)(iVar3 + 0x24) == Channel)) &&
          (iVar2 = *(int *)(iVar3 + 0x20), iVar2 < iVar1)))) {
        ShufflePortalDownInternal(this,(iVar3 - *(int *)&this->PortalList) / 0x390);
        iVar2 = *(int *)(iVar3 + 0x20);
      }
      iVar3 = iVar3 + 0x390;
      iVar1 = iVar2;
    } while (iVar3 != *(int *)&(this->PortalList).field_0x4);
  }
  ResetPortalDestinations(this,Channel);
  return;
}


// ---------------------------------------------------------------------
// PortalHelper::PlayPortalSoundFx  @ 4fc2a621  lines 1939-1985

bool __thiscall
PortalHelper::PlayPortalSoundFx(PortalHelper *this,int param_1,int param_2,bool param_3)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  int *piVar5;
  int iVar6;
  
  iVar6 = param_1 * 0x390;
  iVar2 = *(int *)&this->PortalList + iVar6;
  if (param_2 == 0) {
    bVar1 = DoesFileExist((char *)(iVar2 + 0x30c));
    iVar2 = *(int *)&this->PortalList;
    pcVar4 = (char *)(iVar6 + 0x30c + iVar2);
    if (bVar1) {
      iVar3 = StartAudio3D(pcVar4,*(int *)(iVar2 + iVar6),AUDIO_CAT_EXPLOSION,false,false);
      *(int *)(iVar2 + 0x38c + iVar6) = iVar3;
      return true;
    }
    if (*pcVar4 == '\0') {
      return false;
    }
    pcVar4 = "ERROR: Portal SoundActivate \'%s\' Doesn\'t Exist! FIX ODFs!";
  }
  else {
    bVar1 = DoesFileExist((char *)(iVar2 + 0x34c));
    piVar5 = (int *)(*(int *)&this->PortalList + iVar6);
    if (bVar1) {
      iVar2 = piVar5[3];
      if (piVar5[3] == 0) {
        iVar2 = *piVar5;
      }
      iVar2 = StartAudio3D((char *)(piVar5 + 0xd3),iVar2,AUDIO_CAT_EXPLOSION,false,false);
      piVar5[0xe3] = iVar2;
      return true;
    }
    if ((char)piVar5[0xd3] == '\0') {
      return false;
    }
    pcVar4 = "ERROR: Portal SoundDeactivate \'%s\' Doesn\'t Exist! FIX ODFs!";
  }
  FormatLogMessage(pcVar4);
  return false;
}


