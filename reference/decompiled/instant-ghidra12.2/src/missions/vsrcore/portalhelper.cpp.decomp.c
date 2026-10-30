// Reconstructed by Ghidra from Instant.dll + Instant.pdb
// Original source file: /e:/github/vsr_dll_source/missions/vsrcore/portalhelper.cpp
// Functions are ordered by original source line. This is decompiler
// output, not the author's source: names/types come from the PDB,
// local variable names and control flow are reconstructed.


// ---------------------------------------------------------------------
// `dynamic_initializer_for_'TempPortalBuffer''  @ 4fc01acf  lines 10-10


void __cdecl _dynamic_initializer_for__TempPortalBuffer__(void)

{
  atexit(_dynamic_atexit_destructor_for__TempPortalBuffer__);
  return;
}


// ---------------------------------------------------------------------
// `dynamic_initializer_for_'TempTeleportTargetBuffer''  @ 4fc01adb  lines 11-11


void __cdecl _dynamic_initializer_for__TempTeleportTargetBuffer__(void)

{
  atexit(_dynamic_atexit_destructor_for__TempTeleportTargetBuffer__);
  return;
}


// ---------------------------------------------------------------------
// PortalHelper::Load  @ 4fc26bb0  lines 26-50


bool __thiscall PortalHelper::Load(PortalHelper *this,bool param_1)

{
  vector<PortalHelper::TeleportTargetClass,std::allocator<PortalHelper::TeleportTargetClass>_>
  *this_00;
  bool bVar1;
  PortalHelper *extraout_ECX;
  PortalHelper *this_01;
  PortalHelper *local_8;
  
  this_01 = this;
  local_8 = this;
  if (this != (PortalHelper *)&TempPortalBuffer) {
    std::vector<PortalHelper::PortalClass,std::allocator<PortalHelper::PortalClass>_>::
    _Assign_range<PortalHelper::PortalClass_*>
              (&this->PortalList,*(PortalClass **)&this->PortalList,
               *(PortalClass **)&(this->PortalList).field_0x4,SUB41(this,0));
    this_01 = extraout_ECX;
  }
  this_00 = &this->TeleportTargetList;
  if (this_00 != &TempTeleportTargetBuffer) {
    std::
    vector<PortalHelper::TeleportTargetClass,std::allocator<PortalHelper::TeleportTargetClass>_>::
    _Assign_range<PortalHelper::TeleportTargetClass_*>
              ((vector<PortalHelper::TeleportTargetClass,std::allocator<PortalHelper::TeleportTargetClass>_>
                *)this_01,*(TeleportTargetClass **)this_00,
               *(TeleportTargetClass **)&(this->TeleportTargetList).field_0x4,SUB41(local_8,0));
  }
  local_8 = (PortalHelper *)0x0;
  bVar1 = Read((int *)&local_8,1);
  std::vector<PortalHelper::PortalClass,std::allocator<PortalHelper::PortalClass>_>::
  _Resize<<lambda_f1b37303f98cb6f7ff8a0c469c587af2>_>
            (&this->PortalList,(uint)local_8,(<lambda_f1b37303f98cb6f7ff8a0c469c587af2>)this);
  if (local_8 == (PortalHelper *)0x0) {
LAB_4fc26c30:
    local_8 = (PortalHelper *)0x0;
    if (bVar1) goto LAB_4fc26c38;
  }
  else {
    if ((!bVar1) || (bVar1 = Read(*(void **)&this->PortalList,(int)local_8 * 0x390), !bVar1)) {
      bVar1 = false;
      goto LAB_4fc26c30;
    }
LAB_4fc26c38:
    local_8 = (PortalHelper *)0x0;
    bVar1 = Read((int *)&local_8,1);
    if (bVar1) {
      bVar1 = true;
      goto LAB_4fc26c50;
    }
  }
  bVar1 = false;
LAB_4fc26c50:
  std::vector<PortalHelper::TeleportTargetClass,std::allocator<PortalHelper::TeleportTargetClass>_>
  ::_Resize<<lambda_f2c0a61063d8731356913bf41ed3079e>_>
            (this_00,(uint)local_8,(<lambda_f2c0a61063d8731356913bf41ed3079e>)this_00);
  if (local_8 != (PortalHelper *)0x0) {
    if ((bVar1) && (bVar1 = Read(*(void **)this_00,(int)local_8 * 0x14), bVar1)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
  }
  return bVar1;
}


// ---------------------------------------------------------------------
// PortalHelper::PostLoad  @ 4fc26c85  lines 53-101


bool __thiscall PortalHelper::PostLoad(PortalHelper *this,bool param_1)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  PortalClass *unaff_ESI;
  int *piVar4;
  int iVar5;
  PortalClass *unaff_EDI;
  int iVar6;
  
  for (piVar4 = *(int **)&this->PortalList; piVar2 = *(int **)&(this->PortalList).field_0x4,
      piVar4 != piVar2; piVar4 = piVar4 + 0xe4) {
    ConvertHandles(piVar4,1);
    ConvertHandles(piVar4 + 1,1);
    ConvertHandles(piVar4 + 3,1);
    iVar3 = piVar4[3];
    if (iVar3 != 0) {
      piVar4[9] = iVar3;
    }
  }
  piVar4 = *(int **)&this->TeleportTargetList;
  if (piVar4 != *(int **)&(this->TeleportTargetList).field_0x4) {
    do {
      ConvertHandles(piVar4,1);
      ConvertHandles(piVar4 + 1,1);
      piVar4 = piVar4 + 5;
    } while (piVar4 != *(int **)&(this->TeleportTargetList).field_0x4);
    piVar2 = *(int **)&(this->PortalList).field_0x4;
  }
  iVar5 = 0;
  iVar3 = ((int)piVar2 - *(int *)&this->PortalList) / 0x390;
  if ((int)(TempPortalBuffer._4_4_ - TempPortalBuffer._0_4_) / 0x390 == iVar3) {
    iVar6 = 0;
    if (0 < iVar3) {
      do {
        bVar1 = ::operator==(unaff_EDI,unaff_ESI);
        if (!bVar1) {
          FormatLogMessage("PortalList Index Mismatch: %d");
          break;
        }
        iVar6 = iVar6 + 1;
      } while (iVar6 < (*(int *)&(this->PortalList).field_0x4 - *(int *)&this->PortalList) / 0x390);
    }
  }
  else {
    FormatLogMessage("PortalList Size Mismatch! Old: %d New: %d");
  }
  iVar3 = (*(int *)&(this->TeleportTargetList).field_0x4 - *(int *)&this->TeleportTargetList) / 0x14
  ;
  if ((int)(TempTeleportTargetBuffer._4_4_ - TempTeleportTargetBuffer._0_4_) / 0x14 == iVar3) {
    if (0 < iVar3) {
      do {
        bVar1 = ::operator==((TeleportTargetClass *)unaff_EDI,(TeleportTargetClass *)unaff_ESI);
        if (!bVar1) {
          FormatLogMessage("TeleportTargetList Index Mismatch: %d");
          return true;
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < (*(int *)&(this->TeleportTargetList).field_0x4 -
                       *(int *)&this->TeleportTargetList) / 0x14);
    }
  }
  else {
    FormatLogMessage("TeleportTargetList Size Mismatch! Old: %d New: %d");
  }
  return true;
}


// ---------------------------------------------------------------------
// PortalHelper::Save  @ 4fc26dd5  lines 104-121


bool __thiscall PortalHelper::Save(PortalHelper *this,bool param_1)

{
  bool bVar1;
  int local_8;
  
  local_8 = (*(int *)&(this->PortalList).field_0x4 - *(int *)&this->PortalList) / 0x390;
  bVar1 = Write(&local_8,1);
  if (local_8 != 0) {
    if ((bVar1) && (bVar1 = Write(*(void **)&this->PortalList,local_8 * 0x390), bVar1)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
  }
  local_8 = (*(int *)&(this->TeleportTargetList).field_0x4 - *(int *)&this->TeleportTargetList) /
            0x14;
  if ((bVar1) && (bVar1 = Write(&local_8,1), bVar1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (local_8 != 0) {
    if ((bVar1 != false) &&
       (bVar1 = Write(*(void **)&this->TeleportTargetList,local_8 * 0x14), bVar1)) {
      return true;
    }
    bVar1 = false;
  }
  return bVar1;
}


// ---------------------------------------------------------------------
// PortalHelper::AddPortalSwitchObject  @ 4fc26e7b  lines 124-148


void __thiscall
PortalHelper::AddPortalSwitchObject(PortalHelper *this,int param_1,char *param_2,char *param_3)

{
  int unaff_EBX;
  int iVar1;
  int unaff_EBP;
  int unaff_ESI;
  int iVar2;
  int *unaff_EDI;
  char *pcVar3;
  int local_4;
  
  iVar1 = -1;
  local_4 = -1;
  GetODFInt("TeleportalSwitchClass","PortalChannel",(char *)&local_4,(char *)0xffffffff,unaff_EDI,
            unaff_EBX);
  if (-1 < local_4) {
    iVar2 = *(int *)&this->PortalList;
    param_2 = (char *)0x7f7fffff;
    if (iVar2 != *(int *)&(this->PortalList).field_0x4) {
      do {
        pcVar3 = (char *)GetDistance3DSquared(unaff_EBP,unaff_ESI);
        if ((float)pcVar3 < (float)param_2) {
          iVar1 = (iVar2 - *(int *)&this->PortalList) / 0x390;
          param_2 = pcVar3;
        }
        iVar2 = iVar2 + 0x390;
      } while (iVar2 != *(int *)&(this->PortalList).field_0x4);
      if (-1 < iVar1) {
        *(int *)(iVar1 * 0x390 + 0x24 + *(int *)&this->PortalList) = local_4;
      }
    }
  }
  BZ1Helper::DeleteAfterDelay(BZ1Helper::m_BZ1Helper,param_1,0.0);
  return;
}


// ---------------------------------------------------------------------
// PortalHelper::AddPortalObject  @ 4fc26f2d  lines 151-359


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall
PortalHelper::AddPortalObject
          (PortalHelper *this,int param_1,char *param_2,char *param_3,int param_4)

{
  undefined1 auVar1 [12];
  undefined1 auVar2 [12];
  bool bVar3;
  int *piVar4;
  long lVar5;
  int iVar6;
  Matrix *pMVar7;
  bool extraout_CL;
  char cVar8;
  int iVar9;
  int *piVar10;
  char *unaff_ESI;
  float *unaff_EDI;
  float *pfVar11;
  PortalHelper *this_00;
  char *pcVar12;
  undefined1 uVar13;
  char *pcVar14;
  char *pcVar15;
  char *pcVar16;
  uint uVar17;
  undefined1 uVar18;
  undefined1 auStack_14c [7];
  char cStack_145;
  char *local_144;
  int local_140;
  char local_139;
  int *local_138;
  int *local_134;
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
  iVar9 = -1;
  local_138 = *(int **)&this->PortalList;
  local_140 = param_1;
  local_144 = param_3;
  for (piVar4 = local_138; piVar10 = local_138, piVar4 != *(int **)&(this->PortalList).field_0x4;
      piVar4 = piVar4 + 0xe4) {
    if (*piVar4 == param_1) {
      iVar9 = ((int)piVar4 - (int)local_138) / 0x390;
      piVar10 = *(int **)&this->PortalList;
      break;
    }
  }
  local_11c = this;
  if (iVar9 < 0) {
    std::vector<PortalHelper::PortalClass,std::allocator<PortalHelper::PortalClass>_>::
    _Resize<<lambda_f1b37303f98cb6f7ff8a0c469c587af2>_>
              (&this->PortalList,(*(int *)&(this->PortalList).field_0x4 - (int)piVar10) / 0x390 + 1,
               (<lambda_f1b37303f98cb6f7ff8a0c469c587af2>)this);
    local_138 = *(int **)&this->PortalList;
    iVar9 = (*(int *)&(this->PortalList).field_0x4 - (int)local_138) / 0x390 + -1;
  }
  piVar4 = local_138 + iVar9 * 0xe4;
  local_130 = piVar4;
  memset(piVar4,0,0x390);
  pcVar16 = "CollisionRadius";
  pcVar15 = "GameObjectClass";
  GetODFFloat("GameObjectClass","CollisionRadius",(char *)(piVar4 + 0x24),(char *)0x0,unaff_EDI,
              (float)unaff_ESI);
  GetODFString("TeleportalClass","PortalEffect",(char *)0x40,(char *)(piVar4 + 0x83),0,pcVar15,
               pcVar16);
  pcVar16 = "InEffect";
  pcVar15 = "TeleportalClass";
  GetODFInt("TeleportalClass","InEffect",(char *)(piVar4 + 0x3c),(char *)0x0,(int *)unaff_EDI,
            (int)unaff_ESI);
  pcVar14 = "OutEffect";
  pcVar12 = "TeleportalClass";
  GetODFInt("TeleportalClass","OutEffect",(char *)(piVar4 + 0x3d),(char *)0x0,(int *)pcVar15,
            (int)pcVar16);
  pcVar16 = "OnEffect";
  pcVar15 = "TeleportalClass";
  GetODFInt("TeleportalClass","OnEffect",(char *)(piVar4 + 0x3e),(char *)0x0,(int *)pcVar12,
            (int)pcVar14);
  GetODFInt("TeleportalClass","VehInEffect",(char *)(piVar4 + 0x3f),(char *)0x0,(int *)pcVar15,
            (int)pcVar16);
  uVar18 = 0x7c;
  pcVar12 = "TeleportalClass";
  GetODFInt("TeleportalClass","VehOutEffect",(char *)(piVar4 + 0x40),(char *)0x0,(int *)unaff_EDI,
            (int)unaff_ESI);
  pcVar16 = "FxOnVehicle";
  pcVar15 = "TeleportalClass";
  GetODFBool("TeleportalClass","FxOnVehicle",(char *)((int)piVar4 + 0x1b),(char *)0x0,
             (bool *)pcVar12,(bool)uVar18);
  GetODFString("TeleportalClass","soundActivate",(char *)0x40,(char *)(piVar4 + 0xc3),0,pcVar15,
               pcVar16);
  GetODFString("TeleportalClass","soundDeactivate",(char *)0x40,(char *)(piVar4 + 0xd3),0,
               (char *)unaff_EDI,unaff_ESI);
  local_120 = 0xffff;
  iVar9 = GetODFInt("GameObjectClass","effectsMask",(char *)&local_120,(char *)0x0,(int *)unaff_EDI,
                    (int)unaff_ESI);
  if ((iVar9 != 0) && (lVar5 = GetEmitterMask(param_1), lVar5 == 0xffff)) {
    MaskEmitter(param_1,local_120);
  }
  local_134 = (int *)0x0;
  piVar4 = piVar4 + 0x93;
  iVar9 = 0;
  do {
    memset(local_4c,0,0x40);
    iVar9 = iVar9 + 1;
    sprintf_s<64>((char (*) [64])local_4c,"EffectName%d");
    memset(local_8c,0,0x40);
    iVar6 = GetODFString("GameObjectClass",local_4c,(char *)0x40,local_8c,0,(char *)unaff_EDI,
                         unaff_ESI);
    if (iVar6 != 0) {
      local_134 = (int *)strrchr(local_8c,0x2e);
      memset(local_10c,0,0x40);
      memset(local_cc,0,0x40);
      local_138 = (int *)0x0;
      if (local_134 == (int *)0x0) {
        sprintf_s<64>(&local_10c,"%s.odf");
        bVar3 = OpenODF2((char *)unaff_EDI);
        if (bVar3) {
          pcVar15 = local_8c;
          goto LAB_4fc272b9;
        }
      }
      else {
        strcpy_s(local_cc,0x40,(char *)((int)local_134 + 1));
        *(char *)local_134 = '\0';
        strncpy_s(local_10c,0x40,local_8c,0xffffffff);
        sprintf_s<64>(&local_10c,"%s.odf");
        bVar3 = OpenODF2((char *)unaff_EDI);
        if (bVar3) {
          pcVar15 = local_cc;
LAB_4fc272b9:
          iVar6 = GetODFFloat(pcVar15,"lifeTime",(char *)&local_138,(char *)0x0,unaff_EDI,
                              (float)unaff_ESI);
          if (iVar6 != 0) {
            iVar6 = SecondsToTurns((float)local_138);
            *piVar4 = iVar6;
          }
        }
      }
    }
    piVar4 = piVar4 + 1;
    if (0xf < iVar9) {
      pcVar15 = GetObjectiveName(local_140);
      piVar10 = local_130;
      strcpy_s((char *)(local_130 + 0x43),0x100,pcVar15);
      local_134 = piVar10 + 9;
      uVar18 = 0xe8;
      pcVar15 = "TeleportalClass";
      GetODFInt("TeleportalClass","TeleporterChannel",(char *)local_134,(char *)0x0,(int *)unaff_EDI
                ,(int)unaff_ESI);
      uVar13 = 0xfc;
      pcVar16 = "TeleportalClass";
      GetODFBool("TeleportalClass","ShowChannel",(char *)(piVar10 + 5),(char *)0x1,(bool *)pcVar15,
                 (bool)uVar18);
      uVar18 = 8;
      pcVar15 = "TeleportalClass";
      GetODFBool("TeleportalClass","CanEnter",(char *)(piVar10 + 4),(char *)0x1,(bool *)pcVar16,
                 (bool)uVar13);
      GetODFBool("TeleportalClass","CanExit",(char *)((int)piVar10 + 0x11),(char *)0x1,
                 (bool *)pcVar15,(bool)uVar18);
      local_130 = piVar10 + 7;
      uVar13 = 0x1c;
      pcVar16 = "TeleportalClass";
      GetODFInt("TeleportalClass","MatchType",(char *)local_130,(char *)0x0,(int *)unaff_EDI,
                (int)unaff_ESI);
      uVar18 = 0x28;
      pcVar15 = "TeleportalClass";
      GetODFBool("TeleportalClass","MatchTypeUsesChannels",(char *)((int)piVar10 + 0x12),(char *)0x1
                 ,(bool *)pcVar16,(bool)uVar13);
      GetODFBool("TeleportalClass","ContinuousFx",(char *)(piVar10 + 6),(char *)0x0,(bool *)pcVar15,
                 (bool)uVar18);
      pcVar14 = "ContinuousFxRange";
      pcVar12 = "TeleportalClass";
      GetODFFloat("TeleportalClass","ContinuousFxRange",(char *)(piVar10 + 0x41),(char *)0x0,
                  unaff_EDI,(float)unaff_ESI);
      pcVar16 = "TeleportColorFade";
      pcVar15 = "TeleportalClass";
      GetODFColor("TeleportalClass","TeleportColorFade",(char *)(piVar10 + 0x42),(char *)0x0,
                  (ulong *)pcVar12,(ulong)pcVar14);
      piVar4 = piVar10 + 0xc;
      GetODFInt("TeleportalClass","TeleportFilter",(char *)piVar4,(char *)0xf,(int *)pcVar15,
                (int)pcVar16);
      if (*piVar4 == 0) {
        *piVar4 = 0x1f;
      }
      uVar18 = 0x88;
      pcVar15 = "TeleportalClass";
      GetODFFloat("TeleportalClass","ExitVelocity",(char *)(piVar10 + 0x21),(char *)0x0,unaff_EDI,
                  (float)unaff_ESI);
      uVar13 = 0x98;
      pcVar16 = "TeleportalClass";
      GetODFBool("TeleportalClass","ExitForwardOnly",(char *)((int)piVar10 + 0x13),(char *)0x0,
                 (bool *)pcVar15,(bool)uVar18);
      uVar18 = 0xa8;
      pcVar15 = "TeleportalClass";
      GetODFBool("TeleportalClass","ExitKickAI",(char *)((int)piVar10 + 0x17),(char *)0x0,
                 (bool *)pcVar16,(bool)uVar13);
      GetODFBool("TeleportalClass","ExitUsesCenter",(char *)((int)piVar10 + 0x16),(char *)0x1,
                 (bool *)pcVar15,(bool)uVar18);
      GetODFBool("TeleportalClass","EnterGotoIsExit",(char *)((int)piVar10 + 0x19),(char *)0x0,
                 (bool *)unaff_EDI,SUB41(unaff_ESI,0));
      GetODFFloat("TeleportalClass","EnterRange",(char *)(piVar10 + 0x20),__real_41200000,unaff_EDI,
                  (float)unaff_ESI);
      GetODFFloat("TeleportalClass","DestinationMinRange",(char *)(piVar10 + 0x22),(char *)0x0,
                  unaff_EDI,(float)unaff_ESI);
      pcVar16 = "DestinationMaxRange";
      pcVar15 = "TeleportalClass";
      GetODFFloat("TeleportalClass","DestinationMaxRange",(char *)(piVar10 + 0x23),(char *)0x0,
                  unaff_EDI,(float)unaff_ESI);
      piVar4 = piVar10 + 0xb;
      GetODFInt("TeleportalClass","TeleportTeamFilter",(char *)piVar4,(char *)0x7,(int *)pcVar15,
                (int)pcVar16);
      if (*piVar4 == 0) {
        *piVar4 = 7;
      }
      piVar4 = piVar10 + 10;
      GetODFInt("TeleportalClass","DestinationTeamFilter",(char *)piVar4,(char *)0x3,
                (int *)unaff_EDI,(int)unaff_ESI);
      if (*piVar4 == 0) {
        *piVar4 = 7;
      }
      local_118 = 0;
      local_114 = 0;
      local_110 = 0;
      local_12c.x = 0.0;
      local_12c.y = 0.0;
      local_12c.z = 0.0;
      auVar1._4_4_ = unaff_ESI;
      auVar1._0_4_ = unaff_EDI;
      auVar1._8_4_ = 0;
      pMVar7 = GetODFPositionOffset((Matrix *)0x0,0,0,(Vector)ZEXT812(0),(Vector)(auVar1 << 0x20));
      local_12c.x = 0.0;
      local_12c.y = 0.0;
      local_12c.z = 0.0;
      local_118 = 0;
      local_114 = 0;
      local_110 = 0;
      pfVar11 = (float *)(piVar10 + 0x2b);
      for (iVar9 = 0x10; iVar9 != 0; iVar9 = iVar9 + -1) {
        *pfVar11 = (pMVar7->right).x;
        pMVar7 = (Matrix *)&(pMVar7->right).y;
        pfVar11 = pfVar11 + 1;
      }
      auVar2._4_4_ = unaff_ESI;
      auVar2._0_4_ = unaff_EDI;
      auVar2._8_4_ = 0;
      pMVar7 = GetODFPositionOffset((Matrix *)0x1,0,0,(Vector)ZEXT812(0),(Vector)(auVar2 << 0x20));
      piVar10[0x28] = (int)(pMVar7->posit).x;
      piVar10[0x29] = (int)(pMVar7->posit).y;
      piVar10[0x2a] = (int)(pMVar7->posit).z;
      GetPosition(local_140,&local_12c);
      piVar10[8] = -1;
      piVar10[0x25] = (int)local_12c.x;
      piVar10[0x26] = (int)local_12c.y;
      piVar10[0x27] = (int)local_12c.z;
      if (param_4 == -0xf78db58) {
        iVar9 = (*misnImport.GetNearestVehicleObject)(local_140);
        piVar10[3] = iVar9;
        piVar10[9] = iVar9;
        GetODFString("TeleportalMineClass","TooFarSound",(char *)0x40,(char *)(piVar10 + 0xa3),0,
                     (char *)unaff_EDI,unaff_ESI);
        GetODFString("TeleportalMineClass","TooCloseSound",(char *)0x40,(char *)(piVar10 + 0xb3),0,
                     (char *)unaff_EDI,unaff_ESI);
        uVar18 = SUB41(unaff_ESI,0);
      }
      else {
        pcVar15 = GetLabel(local_140);
        uVar18 = SUB41(unaff_ESI,0);
        if (pcVar15 != (char *)0x0) {
          iVar9 = _strnicmp(pcVar15,"channel_",8);
          if (iVar9 == 0) {
            memset(local_cc,0,0x40);
            uVar17 = 0x5f;
            pcVar16 = strchr(pcVar15,0x5f);
            CombineStrings(pcVar16 + 1,(char *)0x40,pcVar15,uVar17);
            iVar9 = atoi(local_cc);
            piVar10[9] = iVar9;
          }
          else {
            iVar9 = _strnicmp(pcVar15,"Portal",6);
            if ((((iVar9 == 0) && (iVar9 = isalpha((int)pcVar15[6]), iVar9 != 0)) &&
                (iVar9 = isdigit((int)pcVar15[7]), iVar9 != 0)) &&
               (piVar10[9] = (int)pcVar15[6], piVar10[7] == 1)) {
              piVar10[8] = pcVar15[7] + -0x30;
            }
          }
        }
      }
      *piVar10 = local_140;
      local_139 = '\0';
      iVar6 = GetODFBool("TeleportalClass","AllowOnlyTwo",&local_139,(char *)0x0,(bool *)unaff_EDI,
                         (bool)uVar18);
      iVar9 = local_140;
      if (iVar6 == 0) {
        piVar4 = local_134;
        this_00 = local_11c;
      }
      else {
        iVar6 = GetTeamNum(local_140);
        this_00 = local_11c;
        piVar4 = local_134;
        *local_134 = *local_134 + iVar6;
        cVar8 = '\0';
        iVar6 = *(int *)&(local_11c->PortalList).field_0x4;
        cStack_145 = '\0';
        for (; iVar6 != *(int *)&this_00->PortalList; iVar6 = iVar6 + -0x390) {
          if (*(int *)(iVar6 + -0x36c) == *piVar4) {
            if (*(int *)(iVar6 + -0x390) != iVar9) {
              if (cVar8 == '\0') {
                cStack_145 = '\x01';
                cVar8 = '\x01';
              }
              else {
                BZ1Helper::DeleteAfterDelay(BZ1Helper::m_BZ1Helper,*(int *)(iVar6 + -0x390),0.0);
                SetPortalEffectEnd(this_00,*(int *)(iVar6 + -0x390),0,0,extraout_CL);
                cVar8 = cStack_145;
              }
            }
          }
        }
      }
      if (*local_130 == 1) {
        SortCycleList(this_00,*piVar4);
      }
      return;
    }
  } while( true );
}


// ---------------------------------------------------------------------
// PortalHelper::Execute  @ 4fc27801  lines 362-839


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

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
  PortalHelper *pPVar10;
  TeleportTargetClass *pTVar11;
  float fVar12;
  TeleportTargetClass *pTVar13;
  float *pfVar14;
  Vector *unaff_ESI;
  TeleportTargetClass *pTVar15;
  size_t sVar16;
  float *pfVar17;
  int *piVar18;
  Vector *unaff_EDI;
  TeleportTargetClass *pTVar19;
  float fVar20;
  undefined1 uVar21;
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
  fVar12 = -NAN;
  local_1f0 = 1.27798e-42;
  local_218 = pTVar15;
  local_210 = pTVar15;
  local_200 = pTVar15;
  local_1fc = this;
  while( true ) {
    pTVar11 = local_210;
    pTVar13 = *(TeleportTargetClass **)&(this->PortalList).field_0x4;
    if (local_210 == pTVar13) break;
    bVar4 = IsAround(local_210->TeleportTarget);
    if (bVar4) {
      if (local_218 != pTVar11) {
        for (iVar9 = 0xe4; iVar9 != 0; iVar9 = iVar9 + -1) {
          pTVar15->TeleportTarget = pTVar11->TeleportTarget;
          pTVar11 = (TeleportTargetClass *)&pTVar11->TeleportTargetDestination;
          pTVar15 = (TeleportTargetClass *)&pTVar15->TeleportTargetDestination;
        }
        pTVar11 = local_210;
        pTVar15 = local_200;
      }
      pTVar15 = (TeleportTargetClass *)&pTVar15[0x2d].DestEnterRange;
      local_200 = pTVar15;
    }
    else if (pTVar11[1].DestinationIndex == 1) {
      fVar12 = pTVar11[1].DistanceFromDestination;
    }
    local_210 = (TeleportTargetClass *)&pTVar11[0x2d].DestEnterRange;
  }
  if (pTVar15 != pTVar13) {
    *(TeleportTargetClass **)&(this->PortalList).field_0x4 = pTVar15;
  }
  if (-1 < (int)fVar12) {
    SortCycleList(this,(int)fVar12);
  }
  pTVar15 = *(TeleportTargetClass **)&(this->TeleportTargetList).field_0x4;
  pTVar13 = *(TeleportTargetClass **)&this->TeleportTargetList;
  local_204 = pTVar15;
  while ((pTVar13 != pTVar15 && (bVar4 = ShouldRemoveTeleportTarget(pTVar13), !bVar4))) {
    pTVar13 = pTVar13 + 1;
  }
  if (pTVar13 != pTVar15) {
    pTVar11 = pTVar13 + 1;
    local_218 = pTVar11;
    if (pTVar11 != pTVar15) {
      do {
        bVar4 = ShouldRemoveTeleportTarget(pTVar11);
        if (!bVar4) {
          pTVar15 = pTVar11;
          pTVar19 = pTVar13;
          for (iVar9 = 5; iVar9 != 0; iVar9 = iVar9 + -1) {
            pTVar19->TeleportTarget = pTVar15->TeleportTarget;
            pTVar15 = (TeleportTargetClass *)&pTVar15->TeleportTargetDestination;
            pTVar19 = (TeleportTargetClass *)&pTVar19->TeleportTargetDestination;
          }
          pTVar13 = pTVar13 + 1;
          pTVar15 = local_204;
        }
        pTVar11 = pTVar11 + 1;
      } while (pTVar11 != pTVar15);
      this = local_1fc;
    }
    if (pTVar13 != pTVar15) {
      sVar16 = *(int *)&(this->TeleportTargetList).field_0x4 - (int)pTVar15;
      memmove(pTVar13,pTVar15,sVar16);
      *(size_t *)&(this->TeleportTargetList).field_0x4 = sVar16 + (int)pTVar13;
    }
  }
  pfVar17 = *(float **)&this->PortalList;
  do {
    local_20c = pfVar17;
    if (pfVar17 == *(float **)&(this->PortalList).field_0x4) {
      piVar18 = *(int **)&this->TeleportTargetList;
      if (piVar18 != *(int **)&(this->TeleportTargetList).field_0x4) {
        do {
          bVar4 = IsAround(piVar18[1]);
          if (bVar4) {
            GetPosition(*piVar18,&local_1ac);
            local_1f0 = GetDistance3DSquared(unaff_EDI,unaff_ESI);
            piVar18[4] = (int)local_1f0;
            if (local_211 != false) {
              FormatLogMessage("Teleporter Target Index: %d Just Teleported, Distnace is: %f");
            }
          }
          piVar18 = piVar18 + 5;
        } while (piVar18 != *(int **)&(this->TeleportTargetList).field_0x4);
      }
      return;
    }
    pfVar5 = (float *)GetTeamNum((int)*pfVar17);
    local_218 = (TeleportTargetClass *)(pfVar17 + 0x25);
    local_1e8 = (float)local_218->TeleportTarget;
    local_1e4 = pfVar17[0x26];
    fStack_1e0 = pfVar17[0x27];
    local_208 = pfVar5;
    GetPosition((int)*local_20c,&local_1a0);
    pfVar17 = local_20c;
    local_200 = (TeleportTargetClass *)0x0;
    local_218->TeleportTarget = (int)local_1a0.x;
    local_218->TeleportTargetDestination = (int)local_1a0.y;
    local_218->DestinationIndex = (int)local_1a0.z;
    if ((*(char *)(local_20c + 6) != '\0') && (local_20c[0x41] != ___real_00000000)) {
      local_200 = (TeleportTargetClass *)(*misnImport.GetNearestVehicleObject)((int)*local_20c);
      local_218 = (TeleportTargetClass *)(pfVar17 + 0x25);
    }
    local_218 = (TeleportTargetClass *)ABS((float)local_218->TeleportTarget - local_1e8);
    fVar12 = (float)___real_3f847ae147ae147b;
    if (((float)local_218 < fVar12) &&
       (local_218 = (TeleportTargetClass *)ABS(pfVar17[0x26] - local_1e4), (float)local_218 < fVar12
       )) {
      local_218 = (TeleportTargetClass *)ABS(pfVar17[0x27] - fStack_1e0);
      if ((float)local_218 < fVar12) {
        uStack_1dc = 0;
        uStack_1d8 = 0;
        uStack_1d4 = 0;
        uStack_1d0 = 0;
        uStack_1cc = 0;
        uStack_1c8 = 0;
        auVar2._4_4_ = unaff_ESI;
        auVar2._0_4_ = unaff_EDI;
        auVar2._8_4_ = 0;
        pMVar6 = GetODFPositionOffset((Matrix *)0x0,0,0,(Vector)ZEXT812(0),(Vector)(auVar2 << 0x20))
        ;
        uStack_1c4 = 0;
        uStack_1c0 = 0;
        uStack_1bc = 0;
        uStack_1b8 = 0;
        uStack_1b4 = 0;
        uStack_1b0 = 0;
        pfVar17 = local_20c + 0x2b;
        for (iVar9 = 0x10; iVar9 != 0; iVar9 = iVar9 + -1) {
          *pfVar17 = (pMVar6->right).x;
          pMVar6 = (Matrix *)&(pMVar6->right).y;
          pfVar17 = pfVar17 + 1;
        }
        auVar3._4_4_ = unaff_ESI;
        auVar3._0_4_ = unaff_EDI;
        auVar3._8_4_ = 0;
        pMVar6 = GetODFPositionOffset((Matrix *)0x1,0,0,(Vector)ZEXT812(0),(Vector)(auVar3 << 0x20))
        ;
        local_20c[0x28] = (pMVar6->posit).x;
        local_20c[0x29] = (pMVar6->posit).y;
        local_20c[0x2a] = (pMVar6->posit).z;
        pfVar17 = local_20c;
      }
    }
    if (*(char *)(pfVar17 + 5) != '\0') {
      iVar9 = SecondsToTurns(1.0);
      if ((BZ1Helper::m_TurnCounter % iVar9 == 0) && (*(char *)((int)pfVar17 + 0x15) == '\0')) {
        pfVar14 = pfVar5;
        iVar9 = GetLocalPlayerTeamNumber();
        bVar4 = IsTeamAllied(iVar9,(int)pfVar14);
        if (bVar4) {
          SetObjectiveName((int)*pfVar17,(char *)(pfVar17 + 0x43));
        }
        *(undefined1 *)((int)pfVar17 + 0x15) = 1;
      }
      iVar9 = SecondsToTurns(__real_40400000);
      if ((BZ1Helper::m_TurnCounter % iVar9 == 0) && (*(char *)((int)pfVar17 + 0x15) != '\0')) {
        iVar9 = GetLocalPlayerTeamNumber();
        bVar4 = IsTeamAllied(iVar9,(int)pfVar5);
        if (bVar4) {
          memset(acStack_108,0,0x100);
          pcVar7 = GetBZCCLocalizedString("cfg","Channel %d");
          sprintf_s<256>((char (*) [256])acStack_108,pcVar7);
          SetObjectiveName((int)*pfVar17,acStack_108);
        }
        *(undefined1 *)((int)pfVar17 + 0x15) = 0;
      }
    }
    if ((*(char *)(pfVar17 + 4) != '\0') &&
       ((pfVar17[3] != 0.0 ||
        (bVar4 = BuildingHelper::IsBuildingPowered(BuildingHelper::m_BuildingHelper,(int)*pfVar17),
        bVar4)))) {
      if (*(char *)((int)pfVar17 + 0x1a) == '\0') {
        fVar12 = pfVar17[1];
        pPVar10 = (PortalHelper *)pfVar17[0x3b];
        fVar20 = pfVar17[7];
        pfVar17[1] = 0.0;
        pfVar17[0x3b] = 0.0;
        if (fVar20 == 0.0) {
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
              if (*(char *)((int)pfVar17 + 0x12) == '\0') {
LAB_4fc27f43:
                if (*(char *)((int)pfVar5 + 0x11) != '\0') {
                  bVar4 = TeamFilterCheck((int)local_208,(int)unaff_EDI,(int)unaff_ESI);
                  if (bVar4) {
                    if (pfVar5[3] == 0.0) {
                      bVar4 = BuildingHelper::IsBuildingPowered
                                        (BuildingHelper::m_BuildingHelper,(int)*pfVar5);
                      if (!bVar4) goto LAB_4fc28057;
                    }
                    pTVar15 = (TeleportTargetClass *)*pfVar5;
                    if (((((TeleportTargetClass *)*pfVar17 == pTVar15) ||
                         (pPStack_1ec = (PortalHelper *)GetDistance3DSquared(unaff_EDI,unaff_ESI),
                         (float)local_1fc <= (float)pPStack_1ec)) ||
                        ((fVar12 = pfVar17[0x22], fVar12 != 0.0 &&
                         (local_210 = (TeleportTargetClass *)(fVar12 * fVar12),
                         (float)pPStack_1ec <= (float)local_210)))) ||
                       ((local_210 = (TeleportTargetClass *)pfVar17[0x23], (float)local_210 != 0.0
                        && (local_210 = (TeleportTargetClass *)((float)local_210 * (float)local_210)
                           , (float)local_210 <= (float)pPStack_1ec)))) {
                      pfVar14 = local_20c;
                    }
                    else {
                      if (dStack_1f8._0_4_ == local_208) {
                        local_218 = (TeleportTargetClass *)
                                    (((int)pfVar5 - *(int *)&this->PortalList) / (int)local_1f0);
                        local_204 = pTVar15;
                      }
                      pfVar17[1] = (float)pTVar15;
                      pfVar17[0x3b] = (float)(((int)pfVar5 - *(int *)&this->PortalList) / 0x390);
                      local_20c = dStack_1f8._0_4_;
                      pfVar14 = dStack_1f8._0_4_;
                      local_1fc = pPStack_1ec;
                    }
                  }
                }
              }
              else if (pfVar17[9] == pfVar5[9]) goto LAB_4fc27f43;
LAB_4fc28057:
              pfVar5 = pfVar5 + 0xe4;
            } while (pfVar5 != *(float **)&(this->PortalList).field_0x4);
          }
          if (((pfVar14 != local_208) && (((uint)pfVar17[10] & 1) != 0)) &&
             (local_204 != (TeleportTargetClass *)0x0)) {
            pfVar17[1] = (float)local_204;
            pfVar17[0x3b] = (float)local_218;
          }
        }
        else if (fVar20 == 1.4013e-45) {
          bVar4 = IsAround((int)fVar12);
          if (bVar4) {
            pfVar17[1] = fVar12;
LAB_4fc27ee8:
            pfVar17[0x3b] = (float)pPVar10;
          }
          else {
            local_204 = (TeleportTargetClass *)
                        ((*(int *)&(this->PortalList).field_0x4 - *(int *)&this->PortalList) / 0x390
                        + -1);
            if ((-1 < (int)local_204) && (0 < (int)local_204)) {
              pPVar8 = (PortalHelper *)(((int)pfVar17 - *(int *)&this->PortalList) / 0x390);
              pPVar10 = (PortalHelper *)0x0;
              if ((int)pPVar8 <= (int)local_204) {
                pPVar10 = pPVar8;
              }
              local_1fc = pPVar10;
              do {
                iVar9 = (int)pPVar10 * 0x390;
                local_218 = (TeleportTargetClass *)
                            GetTeamNum(*(int *)(*(int *)&this->PortalList + iVar9));
                if ((((*(char *)((int)pfVar17 + 0x12) == '\0') ||
                     (pfVar17[9] == *(float *)(iVar9 + 0x24 + *(int *)&this->PortalList))) &&
                    ((*(char *)(iVar9 + 0x11 + *(int *)&this->PortalList) != '\0' &&
                     (bVar4 = TeamFilterCheck((int)local_208,(int)unaff_EDI,(int)unaff_ESI), bVar4))
                    )) && (((*(int *)(iVar9 + 0xc + *(int *)&this->PortalList) != 0 ||
                            (bVar4 = BuildingHelper::IsBuildingPowered
                                               (BuildingHelper::m_BuildingHelper,
                                                *(int *)(iVar9 + *(int *)&this->PortalList)), bVar4)
                            ) && (fVar12 = *(float *)(iVar9 + *(int *)&this->PortalList),
                                 *pfVar17 != fVar12)))) {
                  pfVar17[1] = fVar12;
                  goto LAB_4fc27ee8;
                }
                puVar1 = &(pPVar10->PortalList).field_0x1;
                pPVar10 = (PortalHelper *)0x0;
                if ((int)puVar1 <= (int)local_204) {
                  pPVar10 = (PortalHelper *)puVar1;
                }
              } while (pPVar10 != local_1fc);
            }
          }
        }
        else if (fVar20 == 2.8026e-45) {
          bVar4 = IsAround((int)fVar12);
          if (bVar4) {
            pfVar17[1] = fVar12;
            pfVar17[0x3b] = (float)pPVar10;
          }
          local_204 = (TeleportTargetClass *)GetRandomInt((int)unaff_EDI,(int)unaff_ESI);
          iVar9 = (int)local_204 * 0x390;
          GetTeamNum(*(int *)(*(int *)&this->PortalList + iVar9));
          if (((*(char *)((int)pfVar17 + 0x12) == '\0') ||
              (pfVar17[9] == *(float *)(iVar9 + 0x24 + *(int *)&this->PortalList))) &&
             (((*(char *)(iVar9 + 0x11 + *(int *)&this->PortalList) != '\0' &&
               (bVar4 = TeamFilterCheck((int)local_208,(int)unaff_EDI,(int)unaff_ESI), bVar4)) &&
              (((*(int *)(iVar9 + 0xc + *(int *)&this->PortalList) != 0 ||
                (bVar4 = BuildingHelper::IsBuildingPowered
                                   (BuildingHelper::m_BuildingHelper,
                                    *(int *)(iVar9 + *(int *)&this->PortalList)), bVar4)) &&
               (fVar12 = *(float *)(iVar9 + *(int *)&this->PortalList), *pfVar17 != fVar12)))))) {
            local_208 = (float *)GetDistance3DSquared(unaff_EDI,unaff_ESI);
            local_210 = (TeleportTargetClass *)pfVar17[0x22];
            if ((((float)local_210 == 0.0) ||
                (local_218 = (TeleportTargetClass *)((float)local_210 * (float)local_210),
                (float)local_218 < (float)local_208)) &&
               ((local_210 = (TeleportTargetClass *)pfVar17[0x23], (float)local_210 == 0.0 ||
                (local_218 = (TeleportTargetClass *)((float)local_210 * (float)local_210),
                (float)local_208 < (float)local_218)))) {
              pfVar17[1] = fVar12;
              pfVar17[0x3b] = (float)local_204;
            }
          }
        }
      }
      if ((pfVar17[1] != 0.0) && (*(char *)(pfVar17 + 6) != '\0')) {
        fVar12 = pfVar17[2];
        bVar4 = IsEmitterOn((int)*pfVar17,(int)fVar12);
        uVar21 = SUB41(fVar12,0);
        if (!bVar4) {
          if (pfVar17[0x41] == ___real_00000000) {
LAB_4fc27da3:
            SetPortalEffectStart_Internal
                      (this,((int)pfVar17 - *(int *)&this->PortalList) / 0x390,(int)pfVar17[0x3e],1,
                       (bool)uVar21);
          }
          else if (local_200 != (TeleportTargetClass *)0x0) {
            GetPosition((int)local_200,aVStack_194);
            dStack_1f8 = (double)pfVar17[0x41];
            fVar20 = GetDistance3DSquared(unaff_EDI,unaff_ESI);
            fVar12 = (float)((float10)dStack_1f8 * (float10)dStack_1f8);
            dStack_1f8 = (double)CONCAT44(dStack_1f8._4_4_,fVar12);
            uVar21 = extraout_CL;
            if (fVar20 < fVar12) goto LAB_4fc27da3;
          }
        }
      }
    }
    iVar9 = 0;
    pfVar5 = pfVar17 + 0x10;
    do {
      fVar12 = *pfVar5;
      if ((int)fVar12 < 2) {
        if ((0 < (int)fVar12) && (iVar9 != (int)pfVar17[2] + -1)) {
          StopEmitter((int)*pfVar17,iVar9 + 1);
        }
      }
      else {
        *pfVar5 = (float)((int)fVar12 + -1);
      }
      iVar9 = iVar9 + 1;
      pfVar5 = pfVar5 + 1;
    } while (iVar9 < 0x10);
    fVar12 = pfVar17[2];
    if ((fVar12 == 0.0) || (1 < (int)pfVar17[(int)fVar12 + 0xf])) {
      bVar4 = false;
    }
    else {
      bVar4 = true;
    }
    fVar20 = pfVar17[0xf];
    if (fVar20 == 1.4013e-45) {
      fVar20 = pfVar17[0xd];
      if (fVar20 == 0.0) {
        if (bVar4 != false) {
          StopEmitter((int)*pfVar17,(int)fVar12);
          if (local_211 != false) {
            GetEmitterMask((int)*pfVar17);
            pcVar7 = "Clearing Portal FX: Mode PortalType_NONE Slot: %d, EmitterMask: %d";
LAB_4fc28249:
            FormatConsoleMessage(pcVar7);
          }
LAB_4fc28251:
          pfVar17[2] = 0.0;
          goto LAB_4fc28255;
        }
      }
      else if (fVar20 == 1.4013e-45) {
        if (bVar4 != false) {
          SetPortalEffectOn_Internal
                    (this,((int)pfVar17 - *(int *)&this->PortalList) / 0x390,(int)pfVar17[0xe],1,
                     bVar4);
        }
      }
      else if ((fVar20 == 2.8026e-45) && (bVar4 != false)) {
        fVar12 = 2.8026e-45;
        goto LAB_4fc281e8;
      }
    }
    else if (fVar20 == 2.8026e-45) {
      if (*(char *)(pfVar17 + 6) != '\0') {
        if (pfVar17[1] == 0.0) {
LAB_4fc281c7:
          fVar12 = pfVar17[0xd];
LAB_4fc281e8:
          SetPortalEffectEnd_Internal
                    (this,((int)pfVar17 - *(int *)&this->PortalList) / 0x390,(int)pfVar17[0xe],
                     (int)fVar12,true);
        }
        else if ((pfVar17[0x41] != ___real_00000000) && (local_200 != (TeleportTargetClass *)0x0)) {
          GetPosition((int)local_200,&local_1ac);
          dStack_1f8 = (double)pfVar17[0x41];
          fVar20 = GetDistance3DSquared(unaff_EDI,unaff_ESI);
          fVar12 = (float)((float10)dStack_1f8 * (float10)dStack_1f8);
          dStack_1f8 = (double)CONCAT44(dStack_1f8._4_4_,fVar12);
          if (fVar12 < fVar20) goto LAB_4fc281c7;
        }
      }
    }
    else if ((fVar20 == 4.2039e-45) && (bVar4 != false)) {
      bVar4 = IsEmitterOn((int)*pfVar17,(int)fVar12);
      if (bVar4) {
        StopEmitter((int)*pfVar17,(int)pfVar17[2]);
        if (local_211 != false) {
          GetEmitterMask((int)*pfVar17);
          pcVar7 = "Clearing Portal FX: Mode PortalType_Closing, Slot: %d, EffectMask: %d";
          goto LAB_4fc28249;
        }
        goto LAB_4fc28251;
      }
LAB_4fc28255:
      pfVar17[0xf] = 0.0;
    }
    pfVar17 = pfVar17 + 0xe4;
  } while( true );
}


// ---------------------------------------------------------------------
// PortalHelper::ExecuteObject  @ 4fc28300  lines 842-1187


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall PortalHelper::ExecuteObject(PortalHelper *this,ObjectClass *param_1)

{
  float fVar1;
  Matrix MVar2;
  Matrix MVar3;
  Vector VVar4;
  Vector VVar5;
  Vector VVar6;
  Vector VVar7;
  vector<PortalHelper::TeleportTargetClass,std::allocator<PortalHelper::TeleportTargetClass>_>
  *pvVar8;
  bool bVar9;
  Matrix *pMVar10;
  float fVar11;
  int *piVar12;
  int iVar13;
  Matrix *pMVar14;
  Vector *pVVar15;
  Matrix *pMVar16;
  Matrix *pMVar17;
  AiCommand AVar18;
  Vector *__return_storage_ptr__;
  int extraout_ECX;
  int iVar19;
  int extraout_EDX;
  Matrix *unaff_ESI;
  float *pfVar20;
  Matrix *unaff_EDI;
  float10 fVar21;
  float afStackY_43c [128];
  undefined1 in_stack_fffffdd0 [20];
  undefined4 in_stack_fffffde4;
  undefined4 in_stack_fffffde8;
  undefined4 in_stack_fffffdec;
  undefined4 in_stack_fffffdf0;
  char *in_stack_fffffdf4;
  float *in_stack_fffffdf8;
  double dVar22;
  Vector *pVVar23;
  Matrix *pMVar24;
  uint uVar25;
  int *piStack_1e8;
  char cStack_1e1;
  float *local_1e0;
  undefined1 auStack_1dc [4];
  code *local_1d8;
  Vector VStack_1d4;
  undefined4 uStack_1c8;
  Matrix *local_1c4;
  Matrix *local_1c0;
  float *local_1bc;
  Matrix *local_1b8;
  int local_1b4;
  Matrix *local_1b0;
  code *local_1ac;
  Vector local_1a8;
  float local_19c;
  float local_198;
  vector<PortalHelper::TeleportTargetClass,std::allocator<PortalHelper::TeleportTargetClass>_>
  *local_194;
  Vector *local_190;
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
  local_1a8.x = 0.0;
  local_1a8.y = 0.0;
  local_1a8.z = 0.0;
  local_1bc = (float *)0x0;
  auStack_1dc[3] = BZ1Helper::Logging;
  pMVar14 = (Matrix *)param_1->ObjectHandle;
  local_194 = &this->TeleportTargetList;
  for (pfVar20 = *(float **)local_194; pfVar20 != *(float **)&(this->TeleportTargetList).field_0x4;
      pfVar20 = pfVar20 + 5) {
    if ((Matrix *)*pfVar20 == pMVar14) {
      return;
    }
  }
  local_1e0 = *(float **)&this->PortalList;
  if (local_1e0 == *(float **)&(this->PortalList).field_0x4) {
    return;
  }
  local_1c0 = (Matrix *)0x0;
  local_178 = Goto_exref;
  local_17c = GetPlayerHandle_exref;
  local_190 = (Vector *)__real_bf800000;
  local_1b4 = 0x390;
  local_18c = StartAudio2D_exref;
  local_1c4 = pMVar14;
  do {
    if ((Matrix *)*local_1e0 == pMVar14) {
      return;
    }
    local_1d8 = (code *)0x0;
    do {
      pMVar10 = (Matrix *)GetTap((int)*local_1e0,(int)local_1d8);
      if (pMVar14 == pMVar10) {
        return;
      }
      local_1d8 = (code *)((int)local_1d8 + 1);
    } while ((int)local_1d8 < 8);
    if ((local_1e0[3] != 0.0) && (pMVar14 == (Matrix *)local_1e0[3])) {
      local_1bc = (float *)((int)local_1bc + 1);
    }
    local_198 = *local_1e0;
    fVar11 = (float)WhoFollowing((int)pMVar14);
    if (fVar11 == local_198) {
      if (*(char *)((int)local_1e0 + 0x19) == '\0') {
        Goto((int)pMVar14,(int)local_198,0);
      }
      else {
        (*local_178)();
      }
    }
    if (local_1e0[1] == 0.0) {
      if (((local_1e0[3] != 0.0) && (pMVar14 == (Matrix *)local_1e0[3])) && (1 < (int)local_1bc)) {
        local_1d8 = (code *)0x0;
        for (piVar12 = *(int **)&this->PortalList; piVar12 != *(int **)&(this->PortalList).field_0x4
            ; piVar12 = piVar12 + 0xe4) {
          if (pMVar14 == (Matrix *)piVar12[3]) {
            local_1d8 = (code *)(*misnImport.GetDistanceObject)((int *)local_1e0,piVar12);
            break;
          }
        }
        pMVar10 = (Matrix *)(*local_17c)();
        if (pMVar14 == pMVar10) {
          if ((float)local_1d8 <= local_1e0[0x23]) {
            if (local_1e0[0x22] <= (float)local_1d8) goto LAB_4fc284c4;
            in_stack_fffffdf8 = local_1e0 + 0xb3;
          }
          else {
            in_stack_fffffdf8 = local_1e0 + 0xa3;
          }
          in_stack_fffffdf4 = (char *)0x4fc284c1;
          (*local_18c)();
        }
LAB_4fc284c4:
        BZ1Helper::DeleteAfterDelay(BZ1Helper::m_BZ1Helper,(int)*local_1e0,(float)local_1c0);
        BZ1Helper::DeleteAfterDelay
                  (BZ1Helper::m_BZ1Helper,
                   *(int *)((int)local_1e0[0x3b] * 0x390 + *(int *)&this->PortalList),
                   (float)local_1c0);
      }
    }
    else {
      local_1b8 = (Matrix *)GetCurAmmo((int)*local_1e0);
      local_1ac = (code *)GetMaxAmmo((int)*local_1e0);
      local_198 = (float)GetTeamNum((int)*local_1e0);
      local_174 = param_1->CurTeamNum;
      if (local_1e0[3] == 0.0) {
        local_1d8 = (code *)GetDistance3DSquared(&unaff_EDI->right,&unaff_ESI->right);
      }
      else {
        fVar11 = local_1e0[0x39] - (param_1->Position).z;
        fVar1 = local_1e0[0x37] - (param_1->Position).x;
        local_1d8 = (code *)(fVar11 * fVar11 + fVar1 * fVar1);
      }
      local_188 = (double)(float)local_1d8;
      local_19c = local_1e0[0x20] * local_1e0[0x20];
      local_180 = local_1d8;
      if ((float)local_1d8 < local_19c) {
        iVar13 = (**(code **)(BZ1Helper::m_BZ1Helper->_padding_ + 0x5c))();
        if (iVar13 == 1) {
LAB_4fc28677:
          if (auStack_1dc[3] != '\0') {
            fVar21 = (float10)__CIsqrt();
            local_1b8 = (Matrix *)(float)fVar21;
            GetODFName(SUB84((double)(float)local_1b8,0));
            in_stack_fffffdf8 = (float *)0x4fc286a7;
            FormatLogMessage("Locking onto Object: %08x, ODF: \'%s\', Distance is: %f");
          }
          pfVar20 = *(float **)local_194;
          break;
        }
        if ((iVar13 == 0) && (local_1b8 == (Matrix *)local_1ac)) {
          bVar9 = TeamFilterCheck((int)local_198,(int)unaff_EDI,(int)unaff_ESI);
          if ((bVar9) &&
             ((((((fVar11 = local_1e0[0xc], ((uint)fVar11 & 1) != 0 && (param_1->CategoryID == 1))
                 || ((((uint)fVar11 & 2) != 0 && (param_1->CategoryID == 4)))) ||
                ((((uint)fVar11 & 4) != 0 && (param_1->CategoryID == 8)))) ||
               ((((uint)fVar11 & 8) != 0 && (param_1->CategoryID == 0x10)))) ||
              ((((uint)fVar11 & 0x10) != 0 && (param_1->CategoryID == 0x40)))))) {
            iVar13 = (*misnImport.GetTug)((int)pMVar14);
            if ((iVar13 == 0) && ((local_1e0[3] == 0.0 || (pMVar14 == (Matrix *)local_1e0[3])))) {
              bVar9 = IsNullVector(*(Vector *)
                                    (*(int *)&this->PortalList + 0xdc + (int)local_1e0[0x3b] * 0x390
                                    ));
              pMVar14 = local_1c4;
              if (!bVar9) goto LAB_4fc28677;
            }
          }
        }
      }
    }
    local_1e0 = local_1e0 + 0xe4;
    if (local_1e0 == *(float **)&(this->PortalList).field_0x4) {
      return;
    }
  } while( true );
LAB_4fc286c6:
  if (pfVar20 == *(float **)&(this->TeleportTargetList).field_0x4) goto LAB_4fc286d7;
  pMVar14 = (Matrix *)(*misnImport.GetTug)((int)*pfVar20);
  if (pMVar14 == local_1c4) {
    local_1b0 = (Matrix *)*pfVar20;
    goto LAB_4fc286d7;
  }
  pfVar20 = pfVar20 + 5;
  goto LAB_4fc286c6;
LAB_4fc286d7:
  pvVar8 = local_194;
  std::vector<PortalHelper::TeleportTargetClass,std::allocator<PortalHelper::TeleportTargetClass>_>
  ::_Resize<<lambda_f2c0a61063d8731356913bf41ed3079e>_>
            (local_194,(*(int *)&local_194->field_0x4 - *(int *)local_194) / 0x14 + 1,
             (<lambda_f2c0a61063d8731356913bf41ed3079e>)local_194);
  pMVar14 = local_1c4;
  local_19c = *(float *)pvVar8;
  iVar13 = ((*(int *)&pvVar8->field_0x4 - (int)local_19c) / 0x14) * 0x14;
  local_188 = (double)CONCAT44(local_188._4_4_,iVar13);
  *(undefined4 *)(iVar13 + -0x10 + (int)local_19c) = 0;
  *(undefined4 *)(iVar13 + -0xc + (int)local_19c) = 0;
  *(undefined4 *)(iVar13 + -8 + (int)local_19c) = 0;
  *(undefined4 *)(iVar13 + -4 + (int)local_19c) = 0;
  *(Matrix **)(iVar13 + -0x14 + (int)local_19c) = local_1c4;
  *(undefined4 *)(iVar13 + -8 + (int)local_19c) =
       *(undefined4 *)((int)local_1e0[0x3b] * 0x390 + 0x80 + *(int *)&this->PortalList);
  *(float *)(iVar13 + -0x10 + (int)local_19c) = local_1e0[1];
  *(float *)(iVar13 + -0xc + (int)local_19c) = local_1e0[0x3b];
  local_1bc = local_1e0 + 0x2b;
  GetPosition((int)local_1c4,&MStack_108);
  GetVelocity(&VStack_12c,(int)pMVar14);
  local_1ac = (code *)((int)local_1e0[0x3b] * 0x390);
  local_1d8 = *(code **)&this->PortalList;
  local_1b8 = (Matrix *)((int)local_1d8 + 0xac + (int)local_1ac);
  pMVar14 = local_1b8;
  pMVar10 = &MStack_170;
  for (iVar13 = 0x10; iVar13 != 0; iVar13 = iVar13 + -1) {
    (pMVar10->right).x = (pMVar14->right).x;
    pMVar14 = (Matrix *)&(pMVar14->right).y;
    pMVar10 = (Matrix *)&(pMVar10->right).y;
  }
  if (*(char *)((int)local_1ac + 0x13 + (int)local_1d8) == '\0') {
    MStack_170.right.x = (float)((uint)MStack_170.right.x ^ __xmm_80000000800000008000000080000000);
    MStack_170.right.y = (float)((uint)MStack_170.right.y ^ __xmm_80000000800000008000000080000000);
    MStack_170.right.z = (float)((uint)MStack_170.right.z ^ __xmm_80000000800000008000000080000000);
    VStack_1d4.x = (float)((uint)MStack_170.front.x ^ __xmm_80000000800000008000000080000000);
    VStack_1d4.y = (float)((uint)MStack_170.front.y ^ __xmm_80000000800000008000000080000000);
    VStack_1d4.z = (float)((uint)MStack_170.front.z ^ __xmm_80000000800000008000000080000000);
    MStack_170.front.x = VStack_1d4.x;
    MStack_170.front.y = VStack_1d4.y;
    MStack_170.front.z = VStack_1d4.z;
    Matrix_Inverse(unaff_EDI,unaff_ESI);
    pMVar14 = Matrix_Multiply(&MStack_170,unaff_EDI,unaff_ESI);
    pMVar10 = aMStack_88;
    for (iVar13 = 0x10; iVar13 != 0; iVar13 = iVar13 + -1) {
      (pMVar10->right).x = (pMVar14->right).x;
      pMVar14 = (Matrix *)&(pMVar14->right).y;
      pMVar10 = (Matrix *)&(pMVar10->right).y;
    }
    pMVar14 = Matrix_Multiply(aMStack_88,unaff_EDI,unaff_ESI);
    pMVar10 = &MStack_170;
    for (iVar13 = 0x10; iVar13 != 0; iVar13 = iVar13 + -1) {
      (pMVar10->right).x = (pMVar14->right).x;
      pMVar14 = (Matrix *)&(pMVar14->right).y;
      pMVar10 = (Matrix *)&(pMVar10->right).y;
    }
    pVVar15 = Vector_Rotate(&VStack_12c,unaff_EDI,&unaff_ESI->right);
  }
  else {
    Matrix_Inverse(unaff_EDI,unaff_ESI);
    pMVar14 = Matrix_Multiply(local_1b8,unaff_EDI,unaff_ESI);
    pMVar10 = aMStack_88;
    for (iVar13 = 0x10; iVar13 != 0; iVar13 = iVar13 + -1) {
      (pMVar10->right).x = (pMVar14->right).x;
      pMVar14 = (Matrix *)&(pMVar14->right).y;
      pMVar10 = (Matrix *)&(pMVar10->right).y;
    }
    Vector_TransformInv((Vector *)(local_1bc + 0xc),unaff_EDI,&unaff_ESI->right);
    pVVar15 = Vector_Transform(__return_storage_ptr__,unaff_EDI,&unaff_ESI->right);
    MStack_170.posit.x = pVVar15->x;
    MStack_170.posit.y = pVVar15->y;
    MStack_170.posit.z = pVVar15->z;
    VVar6.y = VStack_12c.y;
    VVar6.x = VStack_12c.x;
    VVar6.z = VStack_12c.z;
    fVar11 = GetLength3D(VVar6);
    pVVar15 = &VStack_1d4;
    VStack_1d4.x = *(float *)((int)local_1ac + 0xcc + (int)local_1d8) * fVar11;
    VStack_1d4.y = *(float *)((int)local_1ac + 0xd0 + (int)local_1d8) * fVar11;
    VStack_1d4.z = (float)(fVar11 * *(float *)((int)local_1ac + 0xd4 + (int)local_1d8));
  }
  dVar22 = (double)ZEXT48(in_stack_fffffdf8);
  local_1a8.x = pVVar15->x;
  local_1a8.y = pVVar15->y;
  local_1a8.z = pVVar15->z;
  fVar11 = local_1e0[0x3b];
  if (*(char *)((int)fVar11 * 0x390 + 0x16 + (int)local_1d8) != '\0') {
    pfVar20 = (float *)((int)fVar11 * 0x390 + 0xdc + (int)local_1d8);
    MStack_170.posit.x = *pfVar20;
    MStack_170.posit.y = pfVar20[1];
    MStack_170.posit.z = pfVar20[2];
  }
  if (auStack_1dc[3] != '\0') {
    FormatLogMessage("Entrance Front Vector Is %f %f %f");
    FormatLogMessage("Exit Front Vector Is %f %f %f");
    FormatLogMessage("Player Front Vector Is %f %f %f");
    FormatLogMessage("Player Up Vector Is %f %f %f");
    FormatLogMessage("Player Right Vector Is %f %f %f");
    FormatLogMessage("Player Velocity Vector Is %f %f %f");
    FormatLogMessage("New Front Vector Is %f %f %f");
    FormatLogMessage("New Up Vector Is %f %f %f");
    FormatLogMessage("New Right Vector Is %f %f %f");
    dVar22 = (double)local_1a8.x;
    in_stack_fffffdf4 = "New Velocity Vector Is %f %f %f";
    in_stack_fffffdf0 = 0x4fc28b87;
    FormatLogMessage("New Velocity Vector Is %f %f %f");
    fVar11 = local_1e0[0x3b];
    local_1d8 = *(code **)&this->PortalList;
  }
  iVar13 = (int)fVar11 * 0x390;
  fVar11 = *(float *)(iVar13 + 0x84 + (int)local_1d8);
  if (fVar11 != ___real_00000000) {
    if (*(char *)(iVar13 + 0x13 + (int)local_1d8) != '\0') {
      local_1a8.x = *(float *)(iVar13 + 0xcc + (int)local_1d8);
      local_1a8.y = *(float *)(iVar13 + 0xd0 + (int)local_1d8);
      local_1a8.z = *(float *)(iVar13 + 0xd4 + (int)local_1d8);
    }
    VStack_1d4.y = local_1a8.y * fVar11;
    VStack_1d4.x = local_1a8.x * fVar11;
    VStack_1d4.z = fVar11 * local_1a8.z;
    local_1a8.x = VStack_1d4.x;
    local_1a8.y = VStack_1d4.y;
    local_1a8.z = VStack_1d4.z;
  }
  local_1d8 = (code *)fVar11;
  bVar9 = IsPlayer((int)local_1c4);
  uStack_1c8 = (float)CONCAT13(bVar9,(undefined3)uStack_1c8);
  VVar7.y = local_1a8.y;
  VVar7.x = local_1a8.x;
  VVar7.z = local_1a8.z;
  bVar9 = IsNullVector(VVar7);
  if ((bVar9) ||
     ((*(char *)(extraout_EDX * 0x390 + 0x17 + extraout_ECX) != '\0' && (uStack_1c8._3_1_ == '\0')))
     ) {
    iVar13 = extraout_EDX * 0x390;
    fVar11 = (float)___real_4034000000000000;
    VStack_1d4.x = *(float *)(iVar13 + 0xcc + extraout_ECX) * fVar11;
    VStack_1d4.y = *(float *)(iVar13 + 0xd0 + extraout_ECX) * fVar11;
    VStack_1d4.z = fVar11 * *(float *)(iVar13 + 0xd4 + extraout_ECX);
    local_1a8.x = VStack_1d4.x;
    local_1a8.y = VStack_1d4.y;
    local_1a8.z = VStack_1d4.z;
  }
  SetCurAmmo((int)*local_1e0,0);
  pMVar10 = local_1c4;
  pMVar14 = SUB84(dVar22,0);
  if (local_1b0 != (Matrix *)0x0) {
    Deploy((int)local_1c4);
    pMVar14 = SUB84(dVar22,0);
  }
  local_1b8 = (Matrix *)SetPosition_exref;
  pMVar24 = pMVar10;
  SetPosition((int)pMVar10,&MStack_170);
  pVVar15 = &local_1a8;
  local_1ac = SetVelocity_exref;
  pVVar23 = (Vector *)0x4fc28cd8;
  pMVar17 = pMVar10;
  SetVelocity((int)pMVar10,pVVar15);
  if (local_1b0 != (Matrix *)0x0) {
    pMVar14 = &MStack_c8;
    pMVar10 = local_1b0;
    GetPosition((int)local_1b0,pMVar14);
    Vector_TransformInv(&MStack_c8.posit,pMVar10,&pMVar14->right);
    fStack_114 = MStack_170.posit.x;
    fStack_110 = MStack_170.posit.y;
    fStack_10c = MStack_170.posit.z;
    pMVar14 = Matrix_Multiply(aMStack_88,unaff_EDI,unaff_ESI);
    iVar13 = *(int *)&this->PortalList;
    pMVar10 = &MStack_170;
    for (iVar19 = 0x10; iVar19 != 0; iVar19 = iVar19 + -1) {
      (pMVar10->right).x = (pMVar14->right).x;
      pMVar14 = (Matrix *)&(pMVar14->right).y;
      pMVar10 = (Matrix *)&(pMVar10->right).y;
    }
    if (*(char *)((int)local_1e0[0x3b] * 0x390 + 0x13 + iVar13) == '\0') {
      MStack_170.right.x =
           (float)((uint)MStack_170.right.x ^ __xmm_80000000800000008000000080000000);
      MStack_170.right.y =
           (float)((uint)MStack_170.right.y ^ __xmm_80000000800000008000000080000000);
      MStack_170.right.z =
           (float)((uint)MStack_170.right.z ^ __xmm_80000000800000008000000080000000);
      VStack_1d4.x = (float)((uint)MStack_170.front.x ^ __xmm_80000000800000008000000080000000);
      VStack_1d4.y = (float)((uint)MStack_170.front.y ^ __xmm_80000000800000008000000080000000);
      VStack_1d4.z = (float)((uint)MStack_170.front.z ^ __xmm_80000000800000008000000080000000);
      MStack_170.front.x = VStack_1d4.x;
      MStack_170.front.y = VStack_1d4.y;
      MStack_170.front.z = VStack_1d4.z;
    }
    MStack_170.posit.x = fStack_114;
    MStack_170.posit.y = fStack_110;
    MStack_170.posit.z = fStack_10c;
    pVVar15 = Vector_Transform(&VStack_120,unaff_EDI,&unaff_ESI->right);
    pvVar8 = local_194;
    MStack_170.posit.x = pVVar15->x;
    MStack_170.posit.y = pVVar15->y;
    MStack_170.posit.z = pVVar15->z;
    std::
    vector<PortalHelper::TeleportTargetClass,std::allocator<PortalHelper::TeleportTargetClass>_>::
    _Resize<<lambda_f2c0a61063d8731356913bf41ed3079e>_>
              (local_194,(*(int *)&local_194->field_0x4 - *(int *)local_194) / 0x14 + 1,
               (<lambda_f2c0a61063d8731356913bf41ed3079e>)local_194);
    pMVar14 = local_1b0;
    iVar13 = *(int *)pvVar8;
    iVar19 = ((*(int *)&pvVar8->field_0x4 - iVar13) / 0x14) * 0x14;
    *(undefined4 *)(iVar19 + -0x10 + iVar13) = 0;
    *(undefined4 *)(iVar19 + -0xc + iVar13) = 0;
    *(undefined4 *)(iVar19 + -8 + iVar13) = 0;
    *(undefined4 *)(iVar19 + -4 + iVar13) = 0;
    *(Matrix **)(iVar19 + -0x14 + iVar13) = local_1b0;
    *(undefined4 *)(iVar19 + -8 + iVar13) =
         *(undefined4 *)((int)local_1e0[0x3b] * 0x390 + 0x80 + *(int *)&this->PortalList);
    *(float *)(iVar19 + -0x10 + iVar13) = local_1e0[1];
    pMVar24 = local_1b0;
    (*(code *)local_1b8)();
    pVVar15 = &local_1a8;
    pMVar17 = pMVar14;
    (*local_1ac)();
    pMVar10 = local_1c4;
    pVVar23 = (Vector *)0x1;
    in_stack_fffffdf0 = 0x4fc28ecd;
    in_stack_fffffdf4 = (char *)local_1c4;
    Pickup((int)local_1c4,(int)pMVar14,1);
  }
  uVar25 = 0x4fc28ed4;
  pMVar16 = (Matrix *)(*local_17c)();
  if ((pMVar10 == pMVar16) && (local_1e0[0x42] != 0.0)) {
    SetColorFade(1.0,___real_40a00000,(ulong)local_1e0[0x42]);
    pMVar14 = (Matrix *)(local_1e0 + 0xc3);
    uVar25 = 0;
    pMVar24 = (Matrix *)0x0;
    in_stack_fffffdf4 = (char *)0x4fc28f22;
    pVVar23 = local_190;
    pMVar17 = local_1c0;
    pVVar15 = local_190;
    (*local_18c)();
  }
  BZ1Helper::m_BZ1Helper[1].teamInfo[0].PilotWeapon[4][0x20] = '\x01';
  if (*(char *)((int)local_1e0 + 0x1b) == '\0') {
    pVVar15 = (Vector *)local_1e0[0x3c];
    pMVar17 = (Matrix *)(((int)local_1e0 - *(int *)&this->PortalList) / local_1b4);
    uVar25 = (uint)(*(char *)(local_1e0 + 6) == '\0');
    pMVar24 = (Matrix *)0x0;
    pVVar23 = (Vector *)0x4fc28f97;
    SetPortalEffectEnd_Internal(this,(int)pMVar17,(int)pVVar15,0,*(char *)(local_1e0 + 6) == '\0');
  }
  else {
    pMVar10 = &MStack_108;
    pfVar20 = afStackY_43c + 0x83;
    for (iVar13 = 0x10; iVar13 != 0; iVar13 = iVar13 + -1) {
      *pfVar20 = (pMVar10->right).x;
      pMVar10 = (Matrix *)&(pMVar10->right).y;
      pfVar20 = pfVar20 + 1;
    }
    MVar2.right.y = 0.0;
    MVar2.right.x = local_1e0[0x3f];
    MVar2.right.z = (float)in_stack_fffffdd0._0_4_;
    MVar2.rightw = (float)in_stack_fffffdd0._4_4_;
    MVar2.up.x = (float)in_stack_fffffdd0._8_4_;
    MVar2.up.y = (float)in_stack_fffffdd0._12_4_;
    MVar2.up.z = (float)in_stack_fffffdd0._16_4_;
    MVar2.upw = (float)in_stack_fffffde4;
    MVar2.front.x = (float)in_stack_fffffde8;
    MVar2.front.y = (float)in_stack_fffffdec;
    MVar2.front.z = (float)in_stack_fffffdf0;
    MVar2.frontw = (float)in_stack_fffffdf4;
    MVar2.posit.x = (float)pMVar14;
    MVar2.posit.y = (float)pVVar23;
    MVar2.posit.z = (float)pMVar17;
    MVar2.positw = (float)pVVar15;
    SetPortalEffectVeh_Internal
              (this,((int)local_1e0 - *(int *)&this->PortalList) / 0x390,MVar2,(int)pMVar24,uVar25);
  }
  fVar11 = local_1e0[0x3b];
  iVar13 = *(int *)&this->PortalList;
  iVar19 = (int)fVar11 * 0x390;
  local_1b4 = iVar13;
  if (*(char *)(iVar19 + 0x1b + iVar13) == '\0') {
    local_1b4 = *(int *)(iVar19 + 0xf4 + iVar13);
    SetPortalEffectEnd_Internal
              (this,(int)fVar11,local_1b4,0,*(char *)(iVar19 + 0x18 + iVar13) == '\0');
  }
  else {
    pMVar10 = &MStack_170;
    pfVar20 = afStackY_43c + 0x83;
    for (iVar13 = 0x10; iVar13 != 0; iVar13 = iVar13 + -1) {
      *pfVar20 = (pMVar10->right).x;
      pMVar10 = (Matrix *)&(pMVar10->right).y;
      pfVar20 = pfVar20 + 1;
    }
    MVar3.right.y = 0.0;
    MVar3.right.x = (float)*(uint *)(iVar19 + 0x100 + local_1b4);
    MVar3.right.z = (float)in_stack_fffffdd0._0_4_;
    MVar3.rightw = (float)in_stack_fffffdd0._4_4_;
    MVar3.up.x = (float)in_stack_fffffdd0._8_4_;
    MVar3.up.y = (float)in_stack_fffffdd0._12_4_;
    MVar3.up.z = (float)in_stack_fffffdd0._16_4_;
    MVar3.upw = (float)in_stack_fffffde4;
    MVar3.front.x = (float)in_stack_fffffde8;
    MVar3.front.y = (float)in_stack_fffffdec;
    MVar3.front.z = (float)in_stack_fffffdf0;
    MVar3.frontw = (float)in_stack_fffffdf4;
    MVar3.posit.x = (float)pMVar14;
    MVar3.posit.y = (float)pVVar23;
    MVar3.posit.z = (float)pMVar17;
    MVar3.positw = (float)pVVar15;
    SetPortalEffectVeh_Internal(this,(int)fVar11,MVar3,(int)pMVar24,uVar25);
  }
  pMVar14 = local_1c4;
  iVar13 = BZ1Helper::m_BZ1Helper->_padding_;
  BZ1Helper::m_BZ1Helper[1].teamInfo[0].PilotWeapon[4][0x20] = '\0';
  fVar11 = *(float *)(local_188._0_4_ + -0x10 + (int)local_19c);
  iVar13 = (**(code **)(iVar13 + 0x60))();
  if ((((local_1b8 != (Matrix *)0x0) || (VStack_1d4.y._3_1_ != '\0')) || (iVar13 != 0)) ||
     (AVar18 = GetCurrentCommand((int)pMVar14), AVar18 != CMD_GO)) goto LAB_4fc29146;
  GetCurrentCommandWhere((Vector *)auStack_1dc,(int)pMVar14);
  pfVar20 = (float *)GetCurrentWho((int)pMVar14);
  local_1bc = (float *)*piStack_1e8;
  if (pfVar20 != local_1bc) {
    VVar4.y = (float)local_1d8;
    VVar4.x = (float)auStack_1dc;
    VVar4.z = VStack_1d4.x;
    bVar9 = IsNullVector(VVar4);
    if (bVar9) goto LAB_4fc29146;
    local_190 = (Vector *)
                (((float)piStack_1e8[0x39] - VStack_1d4.x) *
                 ((float)piStack_1e8[0x39] - VStack_1d4.x) +
                ((float)piStack_1e8[0x37] - (float)auStack_1dc) *
                ((float)piStack_1e8[0x37] - (float)auStack_1dc));
    fVar21 = (float10)__CIsqrt();
    local_190 = (Vector *)(float)fVar21;
    if (((float)___real_3fb99999a0000000 <= (float)local_190) &&
       (VVar5.y = VStack_1d4.x, VVar5.x = (float)local_1d8, VVar5.z = fVar11,
       fVar11 = GetDistance((int)auStack_1dc,VVar5),
       (float)piStack_1e8[0x20] + (float)___real_4039000000000000 <= fVar11)) goto LAB_4fc29146;
    pMVar14 = (Matrix *)VStack_1d4.z;
  }
  (*local_180)();
  SetCommand((int)pMVar14,0,0,0,(char *)0x0,0);
LAB_4fc29146:
  cStack_1e1 = (char)((uint)this >> 0x18);
  if (cStack_1e1 != '\0') {
    fVar21 = (float10)__CIsqrt();
    local_188 = (double)CONCAT44(local_188._4_4_,(float)fVar21);
    GetLabel(param_1->ObjectHandle);
    FormatLogMessage(
                    "Teleporter on Team: %d Index: %d Aquired Target on Team: %d Handle: %08x Label: %s Distance is: %f"
                    );
  }
  if (piStack_1e8[3] != 0) {
    BZ1Helper::DeleteAfterDelay(BZ1Helper::m_BZ1Helper,*piStack_1e8,uStack_1c8);
    BZ1Helper::DeleteAfterDelay
              (BZ1Helper::m_BZ1Helper,
               *(int *)(piStack_1e8[0x3b] * 0x390 + (int)(unaff_ESI->right).x),uStack_1c8);
  }
  return;
}


// ---------------------------------------------------------------------
// PortalHelper::SetPortalEffectStart_Internal  @ 4fc291ed  lines 1234-1333


void __thiscall
PortalHelper::SetPortalEffectStart_Internal
          (PortalHelper *this,int param_1,int param_2,int param_3,bool param_4)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  undefined1 uVar5;
  int iVar6;
  
  bVar1 = BZ1Helper::Logging;
  iVar4 = param_1 * 0x390;
  iVar3 = *(int *)(iVar4 + 8 + *(int *)&this->PortalList);
  bVar2 = IsEmitterOn(*(int *)(iVar4 + *(int *)&this->PortalList),iVar3);
  if (bVar2) {
    if (param_3 != 2) {
      if (param_3 == 1) {
        SetPortalEffectOn_Internal(this,param_1,param_2,1,SUB41(iVar3,0));
        return;
      }
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
      if (bVar1) {
        GetEmitterMask(*(int *)(*(int *)&this->PortalList + iVar4));
        FormatConsoleMessage
                  ("PortalFx_Start FxNum: %d, Type: %d, EffectHard%d, LifeTime: %d, EffectMask: %d")
        ;
        return;
      }
      return;
    }
    iVar3 = 0;
  }
  SetPortalEffectEnd_Internal(this,param_1,param_2,iVar3,true);
  return;
}


// ---------------------------------------------------------------------
// PortalHelper::SetPortalEffectOn_Internal  @ 4fc29317  lines 1351-1409


void __thiscall
PortalHelper::SetPortalEffectOn_Internal
          (PortalHelper *this,int param_1,int param_2,int param_3,bool param_4)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  
  bVar1 = BZ1Helper::Logging;
  iVar3 = param_1 * 0x390;
  bVar2 = IsEmitterOn(*(int *)(iVar3 + *(int *)&this->PortalList),
                      *(int *)(iVar3 + 8 + *(int *)&this->PortalList));
  if (bVar2) {
    StopEmitter(*(int *)(iVar3 + *(int *)&this->PortalList),
                *(int *)(iVar3 + 8 + *(int *)&this->PortalList));
  }
  StartEmitter(*(int *)(iVar3 + *(int *)&this->PortalList),param_2 + 1);
  *(int *)(iVar3 + 8 + *(int *)&this->PortalList) = param_2 + 1;
  *(int *)(iVar3 + 0x34 + *(int *)&this->PortalList) = param_3;
  *(undefined4 *)(iVar3 + 0x3c + *(int *)&this->PortalList) = 2;
  *(int *)(iVar3 + 0x38 + *(int *)&this->PortalList) = param_2;
  if (bVar1) {
    GetEmitterMask(*(int *)(*(int *)&this->PortalList + iVar3));
    FormatConsoleMessage
              ("PortalFx_On FxNum: %d, Type: %d, EffectHard%d, LifeTime: %d, EffectMask: %d");
  }
  return;
}


// ---------------------------------------------------------------------
// PortalHelper::SetPortalEffectEnd  @ 4fc293d2  lines 1413-1425


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
// PortalHelper::SetPortalEffectEnd_Internal  @ 4fc2941b  lines 1427-1514


void __thiscall
PortalHelper::SetPortalEffectEnd_Internal
          (PortalHelper *this,int param_1,int param_2,int param_3,bool param_4)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  
  bVar2 = BZ1Helper::Logging;
  iVar3 = param_1 * 0xe4 + param_2 + 2;
  if (*(int *)(*(int *)&this->PortalList + 0x248 + iVar3 * 4) < 1) {
    return;
  }
  iVar4 = param_1 * 0x390;
  StartEmitter(*(int *)(iVar4 + *(int *)&this->PortalList),param_2 + 2);
  if (param_4) {
    StopEmitter(*(int *)(iVar4 + *(int *)&this->PortalList),
                *(int *)(iVar4 + 8 + *(int *)&this->PortalList));
    *(int *)(iVar4 + 8 + *(int *)&this->PortalList) = param_2 + 2;
    *(int *)(iVar4 + 0x34 + *(int *)&this->PortalList) = param_3;
    *(undefined4 *)(iVar4 + 0x3c + *(int *)&this->PortalList) = 3;
    *(int *)(iVar4 + 0x38 + *(int *)&this->PortalList) = param_2;
  }
  iVar1 = *(int *)&this->PortalList;
  *(int *)(iVar1 + 0x3c + iVar3 * 4) = *(int *)(iVar1 + 0x248 + iVar3 * 4) + 1;
  if (*(char *)(iVar4 + 0x18 + *(int *)&this->PortalList) == '\0') {
    iVar3 = 1;
  }
  else {
    if (param_4) goto LAB_4fc294cf;
    iVar3 = 0;
  }
  PlayPortalSoundFx(this,param_1,iVar3,SUB41(iVar1,0));
LAB_4fc294cf:
  if (bVar2) {
    GetEmitterMask(*(int *)(*(int *)&this->PortalList + iVar4));
    FormatConsoleMessage
              ("PortalFx_End FxNum: %d, Type: %d, EffectHard%d, LifeTime: %d, EffectMask: %d");
  }
  return;
}


// ---------------------------------------------------------------------
// PortalHelper::SetPortalEffectVeh_Internal  @ 4fc2950b  lines 1536-1562


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
  float unaff_ESI;
  float *unaff_EDI;
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
  if ((uint)((int)pcVar5 - (int)pcVar6) < 0x39U - (int)param_2.right.x) {
    memset(local_48,0,0x40);
    sprintf_s<64>((char (*) [64])local_48,"%s%dEnd");
    bVar2 = DoesODFExist(local_48);
    if (bVar2) {
      BZ1Helper::m_BZ1Helper[1].teamInfo[0].PilotWeapon[4][0x20] = '\x01';
      iVar3 = BuildObject(local_48,0,(Matrix *)&param_2.right.z);
      BZ1Helper::m_BZ1Helper[1].teamInfo[0].PilotWeapon[4][0x20] = '\0';
      CombineStrings(".odf",(char *)0x40,(char *)unaff_EDI,(uint)unaff_ESI);
      local_4c = 0.0;
      bVar2 = OpenODF2((char *)unaff_EDI);
      if (!bVar2) {
        return;
      }
      iVar4 = GetODFFloat("Render","lifeTime",(char *)&local_4c,(char *)0x0,unaff_EDI,unaff_ESI);
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
    if (*(char *)(*(int *)&this->PortalList + param_1 * 0x390 + 0x20c) == '\0') {
      return;
    }
    pcVar6 = "Teleport Effect ODF \'%s\' is too long. Fix ODFs!";
  }
  FormatLogMessage(pcVar6);
  return;
}


// ---------------------------------------------------------------------
// PortalHelper::SetPortalDest  @ 4fc29663  lines 1603-1643


bool __thiscall PortalHelper::SetPortalDest(PortalHelper *this,int param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  bool bVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  
  bVar4 = IsAround(param_1);
  if ((!bVar4) || (bVar4 = IsAround(param_2), !bVar4)) {
    return false;
  }
  iVar7 = -1;
  piVar2 = *(int **)&(this->PortalList).field_0x4;
  piVar1 = *(int **)&this->PortalList;
  for (piVar5 = piVar1; piVar3 = piVar1, piVar5 != piVar2; piVar5 = piVar5 + 0xe4) {
    if (*piVar5 == param_1) {
      iVar6 = ((int)piVar5 - (int)piVar1) / 0x390;
      goto joined_r0x4fc296b7;
    }
  }
  iVar6 = -1;
joined_r0x4fc296b7:
  do {
    if (piVar3 == piVar2) {
LAB_4fc296e6:
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
    if (*piVar3 == param_2) {
      iVar7 = ((int)piVar3 - (int)piVar1) / 0x390;
      goto LAB_4fc296e6;
    }
    piVar3 = piVar3 + 0xe4;
  } while( true );
}


// ---------------------------------------------------------------------
// PortalHelper::ShufflePortalDownInternal  @ 4fc29722  lines 1754-1821


void __thiscall PortalHelper::ShufflePortalDownInternal(PortalHelper *this,int param_1)

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
  
  if (-1 < param_1) {
    iVar1 = *(int *)&this->PortalList;
    iVar4 = (*(int *)&(this->PortalList).field_0x4 - iVar1) / 0x390 + -1;
    if ((-1 < iVar4) && (0 < iVar4)) {
      iVar6 = 0;
      if (param_1 <= iVar4) {
        iVar6 = param_1;
      }
      iVar5 = param_1 * 0x390;
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
// PortalHelper::ShufflePortalUpInternal  @ 4fc297d7  lines 1851-1897


void __thiscall PortalHelper::ShufflePortalUpInternal(PortalHelper *this,int param_1)

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
  
  if (-1 < param_1) {
    iVar1 = *(int *)&this->PortalList;
    iVar2 = (*(int *)&(this->PortalList).field_0x4 - iVar1) / 0x390;
    iVar4 = iVar2 + -1;
    if ((-1 < iVar4) && (0 < iVar4)) {
      iVar6 = 0;
      if (param_1 <= iVar4) {
        iVar6 = param_1;
      }
      iVar8 = param_1 * 0x390;
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
// PortalHelper::ResetPortalDestinations  @ 4fc29897  lines 1901-1914


void __thiscall PortalHelper::ResetPortalDestinations(PortalHelper *this,int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)&this->PortalList;
  if (iVar1 != *(int *)&(this->PortalList).field_0x4) {
    do {
      if ((*(char *)(iVar1 + 0x1a) == '\0') &&
         ((*(char *)(iVar1 + 0x12) == '\0' || (*(int *)(iVar1 + 0x24) == param_1)))) {
        *(undefined4 *)(iVar1 + 4) = 0;
        *(undefined4 *)(iVar1 + 0xec) = 0;
      }
      iVar1 = iVar1 + 0x390;
    } while (iVar1 != *(int *)&(this->PortalList).field_0x4);
  }
  return;
}


// ---------------------------------------------------------------------
// PortalHelper::SortCycleList  @ 4fc298cb  lines 1918-1935


void __thiscall PortalHelper::SortCycleList(PortalHelper *this,int param_1)

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
         (((*(char *)(iVar3 + 0x12) == '\0' || (*(int *)(iVar3 + 0x24) == param_1)) &&
          (iVar2 = *(int *)(iVar3 + 0x20), iVar2 < iVar1)))) {
        ShufflePortalDownInternal(this,(iVar3 - *(int *)&this->PortalList) / 0x390);
        iVar2 = *(int *)(iVar3 + 0x20);
      }
      iVar3 = iVar3 + 0x390;
      iVar1 = iVar2;
    } while (iVar3 != *(int *)&(this->PortalList).field_0x4);
  }
  ResetPortalDestinations(this,param_1);
  return;
}


// ---------------------------------------------------------------------
// PortalHelper::PlayPortalSoundFx  @ 4fc29926  lines 1939-1985


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

