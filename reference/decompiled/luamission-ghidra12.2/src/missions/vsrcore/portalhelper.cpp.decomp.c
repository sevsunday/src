// Reconstructed by Ghidra from LuaMission.dll + LuaMission.pdb
// Original source file: /e:/github/vsr_dll_source/missions/vsrcore/portalhelper.cpp
// Functions are ordered by original source line. This is decompiler
// output, not the author's source: names/types come from the PDB,
// local variable names and control flow are reconstructed.


// ---------------------------------------------------------------------
// `dynamic_initializer_for_'TempPortalBuffer''  @ 4fc01b40  lines 10-10


void __cdecl _dynamic_initializer_for__TempPortalBuffer__(void)

{
  atexit(_dynamic_atexit_destructor_for__TempPortalBuffer__);
  return;
}


// ---------------------------------------------------------------------
// `dynamic_initializer_for_'TempTeleportTargetBuffer''  @ 4fc01b4c  lines 11-11


void __cdecl _dynamic_initializer_for__TempTeleportTargetBuffer__(void)

{
  atexit(_dynamic_atexit_destructor_for__TempTeleportTargetBuffer__);
  return;
}


// ---------------------------------------------------------------------
// PortalHelper::Load  @ 4fc3b5ea  lines 26-50


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
LAB_4fc3b66a:
    local_8 = (PortalHelper *)0x0;
    if (bVar1) goto LAB_4fc3b672;
  }
  else {
    if ((!bVar1) || (bVar1 = Read(*(void **)&this->PortalList,(int)local_8 * 0x390), !bVar1)) {
      bVar1 = false;
      goto LAB_4fc3b66a;
    }
LAB_4fc3b672:
    local_8 = (PortalHelper *)0x0;
    bVar1 = Read((int *)&local_8,1);
    if (bVar1) {
      bVar1 = true;
      goto LAB_4fc3b68a;
    }
  }
  bVar1 = false;
LAB_4fc3b68a:
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
// PortalHelper::PostLoad  @ 4fc3b6bf  lines 53-101


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
// PortalHelper::Save  @ 4fc3b80f  lines 104-121


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
// PortalHelper::AddPortalSwitchObject  @ 4fc3b8b5  lines 124-148


void __thiscall
PortalHelper::AddPortalSwitchObject(PortalHelper *this,int param_1,char *param_2,char *param_3)

{
  int unaff_EBX;
  int iVar1;
  int unaff_EBP;
  int unaff_ESI;
  int iVar2;
  int *unaff_EDI;
  char *in_XMM0_Da;
  int local_4;
  
  iVar1 = -1;
  local_4 = -1;
  GetODFInt("TeleportalSwitchClass","PortalChannel",(char *)&local_4,(char *)0xffffffff,unaff_EDI,
            unaff_EBX);
  if (-1 < local_4) {
    iVar2 = *(int *)&this->PortalList;
    param_3 = (char *)0x7f7fffff;
    if (iVar2 != *(int *)&(this->PortalList).field_0x4) {
      do {
        GetDistance3DSquared(unaff_EBP,unaff_ESI);
        if ((float)in_XMM0_Da < (float)param_3) {
          iVar1 = (iVar2 - *(int *)&this->PortalList) / 0x390;
          param_3 = in_XMM0_Da;
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
// PortalHelper::AddPortalObject  @ 4fc3b963  lines 151-359


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
  uVar18 = 0xf4;
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
          goto LAB_4fc3bcef;
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
LAB_4fc3bcef:
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
      uVar18 = 0x60;
      pcVar15 = "TeleportalClass";
      GetODFInt("TeleportalClass","TeleporterChannel",(char *)local_134,(char *)0x0,(int *)unaff_EDI
                ,(int)unaff_ESI);
      uVar13 = 0x74;
      pcVar16 = "TeleportalClass";
      GetODFBool("TeleportalClass","ShowChannel",(char *)(piVar10 + 5),(char *)0x1,(bool *)pcVar15,
                 (bool)uVar18);
      uVar18 = 0x80;
      pcVar15 = "TeleportalClass";
      GetODFBool("TeleportalClass","CanEnter",(char *)(piVar10 + 4),(char *)0x1,(bool *)pcVar16,
                 (bool)uVar13);
      GetODFBool("TeleportalClass","CanExit",(char *)((int)piVar10 + 0x11),(char *)0x1,
                 (bool *)pcVar15,(bool)uVar18);
      local_130 = piVar10 + 7;
      uVar13 = 0x94;
      pcVar16 = "TeleportalClass";
      GetODFInt("TeleportalClass","MatchType",(char *)local_130,(char *)0x0,(int *)unaff_EDI,
                (int)unaff_ESI);
      uVar18 = 0xa0;
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
      bVar3 = false;
      pcVar15 = "TeleportalClass";
      GetODFFloat("TeleportalClass","ExitVelocity",(char *)(piVar10 + 0x21),(char *)0x0,unaff_EDI,
                  (float)unaff_ESI);
      uVar13 = 0x10;
      pcVar16 = "TeleportalClass";
      GetODFBool("TeleportalClass","ExitForwardOnly",(char *)((int)piVar10 + 0x13),(char *)0x0,
                 (bool *)pcVar15,bVar3);
      uVar18 = 0x20;
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
// PortalHelper::Execute  @ 4fc3c237  lines 362-839


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall PortalHelper::Execute(PortalHelper *this,BZ1Helper *param_1)

{
  undefined1 *puVar1;
  int iVar2;
  undefined1 auVar3 [12];
  undefined1 auVar4 [12];
  bool bVar5;
  PortalHelper *pPVar6;
  Matrix *pMVar7;
  char *pcVar8;
  PortalHelper *pPVar9;
  int iVar10;
  TeleportTargetClass *pTVar11;
  float fVar12;
  int *piVar13;
  float *pfVar14;
  int unaff_ESI;
  TeleportTargetClass *pTVar15;
  size_t sVar16;
  PortalHelper *pPVar17;
  int unaff_EDI;
  TeleportTargetClass *pTVar18;
  float *pfVar19;
  float fVar20;
  TeleportTargetClass *pTVar21;
  float fVar22;
  undefined1 uVar23;
  Vector *pVVar24;
  TeleportTargetClass *local_210;
  PortalHelper *local_20c;
  TeleportTargetClass *local_208;
  bool local_201;
  TeleportTargetClass *local_200;
  PortalHelper *local_1fc;
  PortalHelper *local_1f8;
  TeleportTargetClass *local_1f4;
  float local_1f0;
  TeleportTargetClass *pTStack_1ec;
  Vector local_1e8;
  float local_1dc;
  float local_1d8;
  float fStack_1d4;
  undefined4 uStack_1d0;
  undefined4 uStack_1cc;
  undefined4 uStack_1c8;
  undefined4 uStack_1c4;
  undefined4 uStack_1c0;
  undefined4 uStack_1bc;
  undefined4 uStack_1b8;
  undefined4 uStack_1b4;
  undefined4 uStack_1b0;
  undefined4 uStack_1ac;
  undefined4 uStack_1a8;
  undefined4 uStack_1a4;
  Vector VStack_1a0;
  Vector local_194 [11];
  char acStack_108 [260];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)&local_210;
  local_201 = BZ1Helper::Logging;
  pTVar15 = *(TeleportTargetClass **)&this->PortalList;
  fVar12 = -NAN;
  local_1f0 = 1.27798e-42;
  local_210 = pTVar15;
  local_208 = pTVar15;
  local_1fc = this;
  local_1f4 = pTVar15;
  while( true ) {
    pTVar11 = local_208;
    pTVar21 = *(TeleportTargetClass **)&(this->PortalList).field_0x4;
    if (local_208 == pTVar21) break;
    bVar5 = IsAround(local_208->TeleportTarget);
    if (bVar5) {
      if (local_210 != pTVar11) {
        for (iVar10 = 0xe4; iVar10 != 0; iVar10 = iVar10 + -1) {
          pTVar15->TeleportTarget = pTVar11->TeleportTarget;
          pTVar11 = (TeleportTargetClass *)&pTVar11->TeleportTargetDestination;
          pTVar15 = (TeleportTargetClass *)&pTVar15->TeleportTargetDestination;
        }
        pTVar11 = local_208;
        pTVar15 = local_1f4;
      }
      pTVar15 = (TeleportTargetClass *)&pTVar15[0x2d].DestEnterRange;
      local_1f4 = pTVar15;
    }
    else if (pTVar11[1].DestinationIndex == 1) {
      fVar12 = pTVar11[1].DistanceFromDestination;
    }
    local_208 = (TeleportTargetClass *)&pTVar11[0x2d].DestEnterRange;
  }
  if (pTVar15 != pTVar21) {
    *(TeleportTargetClass **)&(this->PortalList).field_0x4 = pTVar15;
  }
  if (-1 < (int)fVar12) {
    SortCycleList(this,(int)fVar12);
  }
  pTVar15 = *(TeleportTargetClass **)&(this->TeleportTargetList).field_0x4;
  pTVar21 = *(TeleportTargetClass **)&this->TeleportTargetList;
  local_200 = pTVar15;
  while ((pTVar21 != pTVar15 && (bVar5 = ShouldRemoveTeleportTarget(pTVar21), !bVar5))) {
    pTVar21 = pTVar21 + 1;
  }
  if (pTVar21 != pTVar15) {
    pTVar11 = pTVar21 + 1;
    local_210 = pTVar11;
    if (pTVar11 != pTVar15) {
      do {
        bVar5 = ShouldRemoveTeleportTarget(pTVar11);
        if (!bVar5) {
          pTVar15 = pTVar11;
          pTVar18 = pTVar21;
          for (iVar10 = 5; iVar10 != 0; iVar10 = iVar10 + -1) {
            pTVar18->TeleportTarget = pTVar15->TeleportTarget;
            pTVar15 = (TeleportTargetClass *)&pTVar15->TeleportTargetDestination;
            pTVar18 = (TeleportTargetClass *)&pTVar18->TeleportTargetDestination;
          }
          pTVar21 = pTVar21 + 1;
          pTVar15 = local_200;
        }
        pTVar11 = pTVar11 + 1;
      } while (pTVar11 != pTVar15);
      this = local_1fc;
    }
    if (pTVar21 != pTVar15) {
      sVar16 = *(int *)&(this->TeleportTargetList).field_0x4 - (int)pTVar15;
      memmove(pTVar21,pTVar15,sVar16);
      *(size_t *)&(this->TeleportTargetList).field_0x4 = sVar16 + (int)pTVar21;
    }
  }
  pPVar17 = *(PortalHelper **)&this->PortalList;
  do {
    local_20c = pPVar17;
    if (pPVar17 == *(PortalHelper **)&(this->PortalList).field_0x4) {
      piVar13 = *(int **)&this->TeleportTargetList;
      if (piVar13 != *(int **)&(this->TeleportTargetList).field_0x4) {
        do {
          bVar5 = IsAround(piVar13[1]);
          if (bVar5) {
            iVar10 = piVar13[2] * 0x390 + *(int *)&this->PortalList;
            GetPosition(*piVar13,&local_1e8);
            fVar22 = *(float *)(iVar10 + 0x94) - local_1e8.x;
            fVar20 = *(float *)(iVar10 + 0x98) - local_1e8.y;
            fVar12 = *(float *)(iVar10 + 0x9c) - local_1e8.z;
            local_1f0 = fVar22 * fVar22 + fVar20 * fVar20 + fVar12 * fVar12;
            piVar13[4] = (int)local_1f0;
            if (local_201 != false) {
              FormatLogMessage("Teleporter Target Index: %d Just Teleported, Distnace is: %f");
            }
          }
          piVar13 = piVar13 + 5;
        } while (piVar13 != *(int **)&(this->TeleportTargetList).field_0x4);
      }
      return;
    }
    pPVar6 = (PortalHelper *)GetTeamNum(*(int *)&pPVar17->PortalList);
    local_210 = (TeleportTargetClass *)&pPVar17[6].PortalList.field_0x4;
    local_1dc = *(float *)local_210;
    local_1d8 = *(float *)&pPVar17[6].PortalList.field_0x8;
    fStack_1d4 = *(float *)&pPVar17[6].TeleportTargetList;
    local_1f8 = pPVar6;
    GetPosition(*(int *)&local_20c->PortalList,local_194);
    pPVar17 = local_20c;
    local_1f4 = (TeleportTargetClass *)0x0;
    local_210->TeleportTarget = (int)local_194[0].x;
    local_210->TeleportTargetDestination = (int)local_194[0].y;
    local_210->DestinationIndex = (int)local_194[0].z;
    if ((*(char *)&local_20c[1].PortalList != '\0') &&
       (*(float *)&local_20c[10].TeleportTargetList.field_0x8 != ___real_00000000)) {
      local_1f4 = (TeleportTargetClass *)
                  (*misnImport.GetNearestVehicleObject)(*(int *)&local_20c->PortalList);
      local_210 = (TeleportTargetClass *)&pPVar17[6].PortalList.field_0x4;
    }
    local_210 = (TeleportTargetClass *)ABS((float)local_210->TeleportTarget - local_1dc);
    fVar12 = (float)___real_3f847ae147ae147b;
    if (((float)local_210 < fVar12) &&
       (local_210 = (TeleportTargetClass *)
                    ABS(*(float *)&pPVar17[6].PortalList.field_0x8 - local_1d8),
       (float)local_210 < fVar12)) {
      local_210 = (TeleportTargetClass *)ABS(*(float *)&pPVar17[6].TeleportTargetList - fStack_1d4);
      if ((float)local_210 < fVar12) {
        uStack_1d0 = 0;
        uStack_1cc = 0;
        uStack_1c8 = 0;
        uStack_1c4 = 0;
        uStack_1c0 = 0;
        uStack_1bc = 0;
        auVar3._4_4_ = unaff_ESI;
        auVar3._0_4_ = unaff_EDI;
        auVar3._8_4_ = 0;
        pMVar7 = GetODFPositionOffset((Matrix *)0x0,0,0,(Vector)ZEXT812(0),(Vector)(auVar3 << 0x20))
        ;
        uStack_1b8 = 0;
        uStack_1b4 = 0;
        uStack_1b0 = 0;
        uStack_1ac = 0;
        uStack_1a8 = 0;
        uStack_1a4 = 0;
        pfVar19 = (float *)&local_20c[7].PortalList.field_0x4;
        for (iVar10 = 0x10; iVar10 != 0; iVar10 = iVar10 + -1) {
          *pfVar19 = (pMVar7->right).x;
          pMVar7 = (Matrix *)&(pMVar7->right).y;
          pfVar19 = pfVar19 + 1;
        }
        auVar4._4_4_ = unaff_ESI;
        auVar4._0_4_ = unaff_EDI;
        auVar4._8_4_ = 0;
        pMVar7 = GetODFPositionOffset((Matrix *)0x1,0,0,(Vector)ZEXT812(0),(Vector)(auVar4 << 0x20))
        ;
        *(float *)&local_20c[6].TeleportTargetList.field_0x4 = (pMVar7->posit).x;
        *(float *)&local_20c[6].TeleportTargetList.field_0x8 = (pMVar7->posit).y;
        *(float *)&local_20c[7].PortalList = (pMVar7->posit).z;
        pPVar17 = local_20c;
      }
    }
    if ((pPVar17->TeleportTargetList).field_0x8 != '\0') {
      iVar10 = SecondsToTurns(1.0);
      if ((BZ1Helper::m_TurnCounter % iVar10 == 0) &&
         ((pPVar17->TeleportTargetList).field_0x9 == '\0')) {
        pPVar9 = pPVar6;
        iVar10 = GetLocalPlayerTeamNumber();
        bVar5 = IsTeamAllied(iVar10,(int)pPVar9);
        if (bVar5) {
          SetObjectiveName(*(int *)&pPVar17->PortalList,&pPVar17[0xb].PortalList.field_0x4);
        }
        (pPVar17->TeleportTargetList).field_0x9 = 1;
      }
      iVar10 = SecondsToTurns(__real_40400000);
      if ((BZ1Helper::m_TurnCounter % iVar10 == 0) &&
         ((pPVar17->TeleportTargetList).field_0x9 != '\0')) {
        iVar10 = GetLocalPlayerTeamNumber();
        bVar5 = IsTeamAllied(iVar10,(int)pPVar6);
        if (bVar5) {
          memset(acStack_108,0,0x100);
          pcVar8 = GetBZCCLocalizedString("cfg","Channel %d");
          sprintf_s<256>((char (*) [256])acStack_108,pcVar8);
          SetObjectiveName(*(int *)&pPVar17->PortalList,acStack_108);
        }
        (pPVar17->TeleportTargetList).field_0x9 = 0;
      }
    }
    if (((pPVar17->TeleportTargetList).field_0x4 != '\0') &&
       ((*(int *)&pPVar17->TeleportTargetList != 0 ||
        (bVar5 = BuildingHelper::IsBuildingPowered
                           (BuildingHelper::m_BuildingHelper,*(int *)&pPVar17->PortalList), bVar5)))
       ) {
      if (pPVar17[1].PortalList.field_0x2 == '\0') {
        iVar10 = *(int *)&(pPVar17->PortalList).field_0x4;
        pPVar6 = *(PortalHelper **)&pPVar17[9].TeleportTargetList.field_0x8;
        iVar2 = *(int *)&pPVar17[1].PortalList.field_0x4;
        *(undefined4 *)&(pPVar17->PortalList).field_0x4 = 0;
        *(undefined4 *)&pPVar17[9].TeleportTargetList.field_0x8 = 0;
        if (iVar2 == 0) {
          pfVar19 = *(float **)&this->PortalList;
          pTStack_1ec = (TeleportTargetClass *)0x7f7fffff;
          local_200 = (TeleportTargetClass *)0x0;
          local_210 = (TeleportTargetClass *)0xffffffff;
          local_20c = (PortalHelper *)0xffffffff;
          if (pfVar19 != *(float **)&(this->PortalList).field_0x4) {
            pfVar14 = pfVar19 + 0x27;
            do {
              local_1fc = (PortalHelper *)GetTeamNum((int)*pfVar19);
              if ((((pPVar17->TeleportTargetList).field_0x6 == '\0') ||
                  (*(float *)&pPVar17[1].TeleportTargetList == pfVar14[-0x1e])) &&
                 (*(char *)((int)pfVar14 + -0x8b) != '\0')) {
                bVar5 = TeamFilterCheck((int)local_1f8,unaff_EDI,unaff_ESI);
                if (bVar5) {
                  if (pfVar14[-0x24] == 0.0) {
                    bVar5 = BuildingHelper::IsBuildingPowered
                                      (BuildingHelper::m_BuildingHelper,(int)*pfVar19);
                    if (!bVar5) goto LAB_4fc3cb22;
                  }
                  pTVar15 = (TeleportTargetClass *)*pfVar19;
                  if (*(TeleportTargetClass **)&pPVar17->PortalList != pTVar15) {
                    fVar22 = pfVar14[-2] - *(float *)&pPVar17[6].PortalList.field_0x4;
                    fVar20 = pfVar14[-1] - *(float *)&pPVar17[6].PortalList.field_0x8;
                    fVar12 = *pfVar14 - *(float *)&pPVar17[6].TeleportTargetList;
                    pTVar21 = (TeleportTargetClass *)
                              (fVar22 * fVar22 + fVar20 * fVar20 + fVar12 * fVar12);
                    local_208 = pTVar21;
                    if (((float)pTVar21 < (float)pTStack_1ec) &&
                       ((fVar12 = *(float *)&pPVar17[5].TeleportTargetList.field_0x4, fVar12 == 0.0
                        || (local_208 = (TeleportTargetClass *)(fVar12 * fVar12),
                           (float)local_208 < (float)pTVar21)))) {
                      local_208 = *(TeleportTargetClass **)&pPVar17[5].TeleportTargetList.field_0x8;
                      if ((float)local_208 != 0.0) {
                        local_208 = (TeleportTargetClass *)((float)local_208 * (float)local_208);
                        if ((float)local_208 <= (float)pTVar21) goto LAB_4fc3cb22;
                      }
                      if (local_1fc == local_1f8) {
                        local_210 = (TeleportTargetClass *)
                                    (((int)pfVar19 - *(int *)&this->PortalList) / (int)local_1f0);
                        local_200 = pTVar15;
                      }
                      *(TeleportTargetClass **)&(pPVar17->PortalList).field_0x4 = pTVar15;
                      *(int *)&pPVar17[9].TeleportTargetList.field_0x8 =
                           ((int)pfVar19 - *(int *)&this->PortalList) / 0x390;
                      local_20c = local_1fc;
                      pTStack_1ec = pTVar21;
                    }
                  }
                }
              }
LAB_4fc3cb22:
              pfVar19 = pfVar19 + 0xe4;
              pfVar14 = pfVar14 + 0xe4;
            } while (pfVar19 != *(float **)&(this->PortalList).field_0x4);
          }
          if (((local_20c != local_1f8) && ((pPVar17[1].TeleportTargetList.field_0x4 & 1) != 0)) &&
             (local_200 != (TeleportTargetClass *)0x0)) {
            *(TeleportTargetClass **)&(pPVar17->PortalList).field_0x4 = local_200;
            *(TeleportTargetClass **)&pPVar17[9].TeleportTargetList.field_0x8 = local_210;
          }
        }
        else if (iVar2 == 1) {
          bVar5 = IsAround(iVar10);
          if (bVar5) {
            *(int *)&(pPVar17->PortalList).field_0x4 = iVar10;
LAB_4fc3c983:
            *(PortalHelper **)&pPVar17[9].TeleportTargetList.field_0x8 = pPVar6;
          }
          else {
            local_200 = (TeleportTargetClass *)
                        ((*(int *)&(this->PortalList).field_0x4 - *(int *)&this->PortalList) / 0x390
                        + -1);
            if ((-1 < (int)local_200) && (0 < (int)local_200)) {
              pPVar9 = (PortalHelper *)(((int)pPVar17 - *(int *)&this->PortalList) / 0x390);
              pPVar6 = (PortalHelper *)0x0;
              if ((int)pPVar9 <= (int)local_200) {
                pPVar6 = pPVar9;
              }
              local_1fc = pPVar6;
              do {
                iVar10 = (int)pPVar6 * 0x390;
                local_210 = (TeleportTargetClass *)
                            GetTeamNum(*(int *)(*(int *)&this->PortalList + iVar10));
                if (((((((pPVar17->TeleportTargetList).field_0x6 == '\0') ||
                       (*(int *)&pPVar17[1].TeleportTargetList ==
                        *(int *)(*(int *)&this->PortalList + 0x24 + iVar10))) &&
                      (*(char *)(*(int *)&this->PortalList + 0x11 + iVar10) != '\0')) &&
                     (bVar5 = TeamFilterCheck((int)local_1f8,unaff_EDI,unaff_ESI), bVar5)) &&
                    ((*(int *)(*(int *)&this->PortalList + 0xc + iVar10) != 0 ||
                     (bVar5 = BuildingHelper::IsBuildingPowered
                                        (BuildingHelper::m_BuildingHelper,
                                         *(int *)(*(int *)&this->PortalList + iVar10)), bVar5)))) &&
                   (iVar10 = *(int *)(iVar10 + *(int *)&this->PortalList),
                   *(int *)&pPVar17->PortalList != iVar10)) {
                  *(int *)&(pPVar17->PortalList).field_0x4 = iVar10;
                  goto LAB_4fc3c983;
                }
                puVar1 = &(pPVar6->PortalList).field_0x1;
                pPVar6 = (PortalHelper *)0x0;
                if ((int)puVar1 <= (int)local_200) {
                  pPVar6 = (PortalHelper *)puVar1;
                }
              } while (pPVar6 != local_1fc);
            }
          }
        }
        else if (iVar2 == 2) {
          bVar5 = IsAround(iVar10);
          if (bVar5) {
            *(int *)&(pPVar17->PortalList).field_0x4 = iVar10;
            *(PortalHelper **)&pPVar17[9].TeleportTargetList.field_0x8 = pPVar6;
          }
          local_200 = (TeleportTargetClass *)GetRandomInt(unaff_EDI,unaff_ESI);
          iVar10 = (int)local_200 * 0x390;
          GetTeamNum(*(int *)(*(int *)&this->PortalList + iVar10));
          if (((((pPVar17->TeleportTargetList).field_0x6 == '\0') ||
               (*(int *)&pPVar17[1].TeleportTargetList ==
                *(int *)(*(int *)&this->PortalList + 0x24 + iVar10))) &&
              ((*(char *)(*(int *)&this->PortalList + 0x11 + iVar10) != '\0' &&
               (bVar5 = TeamFilterCheck((int)local_1f8,unaff_EDI,unaff_ESI), bVar5)))) &&
             ((*(int *)(*(int *)&this->PortalList + 0xc + iVar10) != 0 ||
              (bVar5 = BuildingHelper::IsBuildingPowered
                                 (BuildingHelper::m_BuildingHelper,
                                  *(int *)(*(int *)&this->PortalList + iVar10)), bVar5)))) {
            iVar2 = *(int *)&this->PortalList;
            if (*(int *)&pPVar17->PortalList != *(int *)(iVar2 + iVar10)) {
              fVar22 = *(float *)(iVar2 + 0x94 + iVar10) -
                       *(float *)&pPVar17[6].PortalList.field_0x4;
              fVar20 = *(float *)(iVar2 + 0x98 + iVar10) -
                       *(float *)&pPVar17[6].PortalList.field_0x8;
              fVar12 = *(float *)(iVar2 + 0x9c + iVar10) - *(float *)&pPVar17[6].TeleportTargetList;
              local_1f8 = (PortalHelper *)(fVar22 * fVar22 + fVar20 * fVar20 + fVar12 * fVar12);
              local_208 = *(TeleportTargetClass **)&pPVar17[5].TeleportTargetList.field_0x4;
              if ((((float)local_208 == 0.0) ||
                  (local_210 = (TeleportTargetClass *)((float)local_208 * (float)local_208),
                  (float)local_210 < (float)local_1f8)) &&
                 ((local_208 = *(TeleportTargetClass **)&pPVar17[5].TeleportTargetList.field_0x8,
                  (float)local_208 == 0.0 ||
                  (local_210 = (TeleportTargetClass *)((float)local_208 * (float)local_208),
                  (float)local_1f8 < (float)local_210)))) {
                *(int *)&(pPVar17->PortalList).field_0x4 = *(int *)(iVar2 + iVar10);
                *(TeleportTargetClass **)&pPVar17[9].TeleportTargetList.field_0x8 = local_200;
              }
            }
          }
        }
      }
      if ((*(int *)&(pPVar17->PortalList).field_0x4 != 0) &&
         (*(char *)&pPVar17[1].PortalList != '\0')) {
        iVar10 = *(int *)&(pPVar17->PortalList).field_0x8;
        bVar5 = IsEmitterOn(*(int *)&pPVar17->PortalList,iVar10);
        uVar23 = (undefined1)iVar10;
        if (!bVar5) {
          if (*(float *)&pPVar17[10].TeleportTargetList.field_0x8 == ___real_00000000) {
LAB_4fc3c83e:
            SetPortalEffectStart_Internal
                      (this,((int)pPVar17 - *(int *)&this->PortalList) / 0x390,
                       *(int *)&pPVar17[10].PortalList.field_0x8,1,(bool)uVar23);
          }
          else if (local_1f4 != (TeleportTargetClass *)0x0) {
            pVVar24 = &VStack_1a0;
            GetPosition((int)local_1f4,pVVar24);
            uVar23 = SUB41(pVVar24,0);
            local_200 = (TeleportTargetClass *)
                        (VStack_1a0.y - *(float *)&pPVar17[6].PortalList.field_0x8);
            fVar20 = VStack_1a0.x - *(float *)&pPVar17[6].PortalList.field_0x4;
            local_1fc = (PortalHelper *)(VStack_1a0.z - *(float *)&pPVar17[6].TeleportTargetList);
            fVar12 = *(float *)&pPVar17[10].TeleportTargetList.field_0x8;
            local_210 = (TeleportTargetClass *)(fVar12 * fVar12);
            if ((float)local_1fc * (float)local_1fc +
                (float)local_200 * (float)local_200 + fVar20 * fVar20 < (float)local_210)
            goto LAB_4fc3c83e;
          }
        }
      }
    }
    iVar10 = 0;
    piVar13 = (int *)&pPVar17[2].TeleportTargetList.field_0x4;
    do {
      iVar2 = *piVar13;
      if (iVar2 < 2) {
        if ((0 < iVar2) && (iVar10 != *(int *)&(pPVar17->PortalList).field_0x8 + -1)) {
          StopEmitter(*(int *)&pPVar17->PortalList,iVar10 + 1);
        }
      }
      else {
        *piVar13 = iVar2 + -1;
      }
      iVar10 = iVar10 + 1;
      piVar13 = piVar13 + 1;
    } while (iVar10 < 0x10);
    iVar10 = *(int *)&(pPVar17->PortalList).field_0x8;
    if ((iVar10 == 0) || (1 < *(int *)(&pPVar17[2].TeleportTargetList.field_0x0 + iVar10 * 4))) {
      bVar5 = false;
    }
    else {
      bVar5 = true;
    }
    iVar2 = *(int *)&pPVar17[2].TeleportTargetList;
    if (iVar2 == 1) {
      iVar2 = *(int *)&pPVar17[2].PortalList.field_0x4;
      if (iVar2 == 0) {
        if (bVar5 != false) {
          StopEmitter(*(int *)&pPVar17->PortalList,iVar10);
          if (local_201 != false) {
            GetEmitterMask(*(int *)&pPVar17->PortalList);
            pcVar8 = "Clearing Portal FX: Mode PortalType_NONE Slot: %d, EmitterMask: %d";
LAB_4fc3cd3e:
            FormatConsoleMessage(pcVar8);
          }
LAB_4fc3cd46:
          *(undefined4 *)&(pPVar17->PortalList).field_0x8 = 0;
          goto LAB_4fc3cd4a;
        }
      }
      else if (iVar2 == 1) {
        if (bVar5 != false) {
          SetPortalEffectOn_Internal
                    (this,((int)pPVar17 - *(int *)&this->PortalList) / 0x390,
                     *(int *)&pPVar17[2].PortalList.field_0x8,1,bVar5);
        }
      }
      else if ((iVar2 == 2) && (bVar5 != false)) {
        iVar10 = 2;
        goto LAB_4fc3ccdd;
      }
    }
    else if (iVar2 == 2) {
      if (*(char *)&pPVar17[1].PortalList != '\0') {
        if (*(int *)&(pPVar17->PortalList).field_0x4 == 0) {
LAB_4fc3ccbc:
          iVar10 = *(int *)&pPVar17[2].PortalList.field_0x4;
LAB_4fc3ccdd:
          SetPortalEffectEnd_Internal
                    (this,((int)pPVar17 - *(int *)&this->PortalList) / 0x390,
                     *(int *)&pPVar17[2].PortalList.field_0x8,iVar10,true);
        }
        else if ((*(float *)&pPVar17[10].TeleportTargetList.field_0x8 != ___real_00000000) &&
                (local_1f4 != (TeleportTargetClass *)0x0)) {
          GetPosition((int)local_1f4,&local_1e8);
          local_200 = (TeleportTargetClass *)
                      (local_1e8.y - *(float *)&pPVar17[6].PortalList.field_0x8);
          fVar20 = local_1e8.x - *(float *)&pPVar17[6].PortalList.field_0x4;
          local_1fc = (PortalHelper *)(local_1e8.z - *(float *)&pPVar17[6].TeleportTargetList);
          fVar12 = *(float *)&pPVar17[10].TeleportTargetList.field_0x8;
          local_210 = (TeleportTargetClass *)(fVar12 * fVar12);
          if ((float)local_210 <
              (float)local_1fc * (float)local_1fc +
              (float)local_200 * (float)local_200 + fVar20 * fVar20) goto LAB_4fc3ccbc;
        }
      }
    }
    else if ((iVar2 == 3) && (bVar5 != false)) {
      bVar5 = IsEmitterOn(*(int *)&pPVar17->PortalList,iVar10);
      if (bVar5) {
        StopEmitter(*(int *)&pPVar17->PortalList,*(int *)&(pPVar17->PortalList).field_0x8);
        if (local_201 != false) {
          GetEmitterMask(*(int *)&pPVar17->PortalList);
          pcVar8 = "Clearing Portal FX: Mode PortalType_Closing, Slot: %d, EffectMask: %d";
          goto LAB_4fc3cd3e;
        }
        goto LAB_4fc3cd46;
      }
LAB_4fc3cd4a:
      *(undefined4 *)&pPVar17[2].TeleportTargetList = 0;
    }
    pPVar17 = pPVar17 + 0x26;
  } while( true );
}


// ---------------------------------------------------------------------
// PortalHelper::ExecuteObject  @ 4fc3ce30  lines 842-1187


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall PortalHelper::ExecuteObject(PortalHelper *this,ObjectClass *param_1)

{
  Matrix MVar1;
  Matrix MVar2;
  vector<PortalHelper::TeleportTargetClass,std::allocator<PortalHelper::TeleportTargetClass>_>
  *pvVar3;
  bool bVar4;
  Matrix *pMVar5;
  float fVar6;
  int iVar7;
  Matrix *pMVar8;
  Vector *pVVar9;
  Matrix *pMVar10;
  Matrix *pMVar11;
  AiCommand AVar12;
  Vector *__return_storage_ptr__;
  int iVar13;
  Matrix *unaff_ESI;
  float *pfVar14;
  float *pfVar15;
  int *piVar16;
  Matrix *unaff_EDI;
  float10 fVar17;
  float fVar18;
  float fVar19;
  float afStackY_444 [128];
  undefined1 in_stack_fffffdc8 [20];
  undefined4 in_stack_fffffddc;
  undefined4 in_stack_fffffde0;
  undefined4 in_stack_fffffde4;
  undefined4 in_stack_fffffde8;
  char *in_stack_fffffdec;
  float *in_stack_fffffdf0;
  double dVar20;
  Vector *pVVar21;
  longlong lVar22;
  float *local_1f0;
  char cStack_1e9;
  undefined1 local_1e8 [8];
  Vector VStack_1e0;
  float *local_1d4;
  undefined4 uStack_1d0;
  Matrix *local_1cc;
  Matrix *local_1c8;
  int local_1c4;
  Matrix *local_1c0;
  float *local_1bc;
  Matrix *local_1b8;
  Vector local_1b4;
  code *local_1a8;
  float local_1a4;
  double local_1a0;
  vector<PortalHelper::TeleportTargetClass,std::allocator<PortalHelper::TeleportTargetClass>_>
  *local_18c;
  Vector *local_188;
  code *local_184;
  code *local_180;
  code *local_17c;
  code *local_178;
  int local_174;
  undefined1 auStack_170 [12];
  float fStack_164;
  float fStack_160;
  float fStack_15c;
  Matrix MStack_158;
  Vector VStack_114;
  Matrix MStack_108;
  Matrix MStack_c8;
  Matrix aMStack_88 [2];
  
  local_1b8 = (Matrix *)0x0;
  local_1b4.x = 0.0;
  local_1b4.y = 0.0;
  local_1b4.z = 0.0;
  local_1bc = (float *)0x0;
  local_1e8[7] = BZ1Helper::Logging;
  pMVar8 = (Matrix *)param_1->ObjectHandle;
  local_18c = &this->TeleportTargetList;
  for (pfVar14 = *(float **)local_18c; pfVar14 != *(float **)&(this->TeleportTargetList).field_0x4;
      pfVar14 = pfVar14 + 5) {
    if ((Matrix *)*pfVar14 == pMVar8) {
      return;
    }
  }
  local_1d4 = *(float **)&this->PortalList;
  if (local_1d4 == *(float **)&(this->PortalList).field_0x4) {
    return;
  }
  local_1f0 = local_1d4 + 0x39;
  local_1c0 = (Matrix *)0x0;
  local_178 = Goto_exref;
  local_17c = GetPlayerHandle_exref;
  local_188 = (Vector *)__real_bf800000;
  local_1c4 = 0x390;
  local_184 = StartAudio2D_exref;
  local_1c8 = pMVar8;
  do {
    pfVar14 = local_1d4;
    if ((Matrix *)*local_1d4 == pMVar8) {
      return;
    }
    local_1e8._0_4_ = 0.0;
    do {
      pMVar5 = (Matrix *)GetTap((int)*pfVar14,local_1e8._0_4_);
      if (pMVar8 == pMVar5) {
        return;
      }
      local_1e8._0_4_ = local_1e8._0_4_ + 1;
    } while ((int)local_1e8._0_4_ < 8);
    if (((Matrix *)local_1f0[-0x36] != (Matrix *)0x0) && (pMVar8 == (Matrix *)local_1f0[-0x36])) {
      local_1bc = (float *)((int)local_1bc + 1);
    }
    local_1a4 = *pfVar14;
    fVar6 = (float)WhoFollowing((int)pMVar8);
    if (fVar6 == local_1a4) {
      if (*(char *)((int)local_1f0 + -0xcb) == '\0') {
        Goto((int)pMVar8,(int)local_1a4,0);
      }
      else {
        (*local_178)();
      }
    }
    if (local_1f0[-0x38] == 0.0) {
      if ((Matrix *)local_1f0[-0x36] != (Matrix *)0x0) {
        if (pMVar8 == (Matrix *)local_1f0[-0x36]) {
          if (1 < (int)local_1bc) {
            local_1e8._0_4_ = 0.0;
            for (piVar16 = *(int **)&this->PortalList;
                piVar16 != *(int **)&(this->PortalList).field_0x4; piVar16 = piVar16 + 0xe4) {
              if (pMVar8 == (Matrix *)piVar16[3]) {
                local_1e8._0_4_ = (*misnImport.GetDistanceObject)((int *)pfVar14,piVar16);
                break;
              }
            }
            pMVar5 = (Matrix *)(*local_17c)();
            if (pMVar8 == pMVar5) {
              if ((float)local_1e8._0_4_ <= local_1f0[-0x16]) {
                if (local_1f0[-0x17] <= (float)local_1e8._0_4_) goto LAB_4fc3d019;
                in_stack_fffffdf0 = local_1f0 + 0x7a;
              }
              else {
                in_stack_fffffdf0 = local_1f0 + 0x6a;
              }
              in_stack_fffffdec = (char *)0x4fc3d016;
              (*local_184)();
            }
LAB_4fc3d019:
            BZ1Helper::DeleteAfterDelay(BZ1Helper::m_BZ1Helper,(int)*pfVar14,(float)local_1c0);
            BZ1Helper::DeleteAfterDelay
                      (BZ1Helper::m_BZ1Helper,
                       *(int *)((int)local_1f0[2] * 0x390 + *(int *)&this->PortalList),
                       (float)local_1c0);
          }
        }
      }
    }
    else {
      local_1cc = (Matrix *)GetCurAmmo((int)*pfVar14);
      local_1a8 = (code *)GetMaxAmmo((int)*pfVar14);
      local_1a4 = (float)GetTeamNum((int)*pfVar14);
      local_174 = param_1->CurTeamNum;
      if (local_1f0[-0x36] == 0.0) {
        fVar19 = local_1f0[-2] - (param_1->Position).x;
        fVar18 = local_1f0[-1] - (param_1->Position).y;
        fVar6 = *local_1f0 - (param_1->Position).z;
        local_1e8._0_4_ = fVar19 * fVar19 + fVar18 * fVar18 + fVar6 * fVar6;
      }
      else {
        fVar6 = local_1f0[-2] - (param_1->Position).x;
        fVar18 = *local_1f0 - (param_1->Position).z;
        local_1e8._0_4_ = fVar6 * fVar6 + fVar18 * fVar18;
      }
      local_180 = (code *)local_1e8._0_4_;
      local_1a0 = (double)(float)local_1e8._0_4_;
      fVar6 = local_1f0[-0x19] * local_1f0[-0x19];
      if ((float)local_1e8._0_4_ < fVar6) {
        local_1e8._0_4_ = fVar6;
        iVar7 = (**(code **)(BZ1Helper::m_BZ1Helper->_padding_ + 0x5c))();
        if (iVar7 == 1) {
LAB_4fc3d254:
          if (local_1e8[7] != '\0') {
            fVar17 = (float10)__CIsqrt();
            local_1cc = (Matrix *)(float)fVar17;
            GetODFName(SUB84((double)(float)local_1cc,0));
            in_stack_fffffdf0 = (float *)0x4fc3d284;
            FormatLogMessage("Locking onto Object: %08x, ODF: \'%s\', Distance is: %f");
          }
          pfVar15 = *(float **)local_18c;
          break;
        }
        if (iVar7 == 0) {
          if (local_1cc == (Matrix *)local_1a8) {
            bVar4 = TeamFilterCheck((int)local_1a4,(int)unaff_EDI,(int)unaff_ESI);
            if (bVar4) {
              fVar6 = local_1f0[-0x2d];
              if (((((((uint)fVar6 & 1) == 0) || (param_1->CategoryID != 1)) &&
                   ((((uint)fVar6 & 2) == 0 || (param_1->CategoryID != 4)))) &&
                  ((((uint)fVar6 & 4) == 0 || (param_1->CategoryID != 8)))) &&
                 ((((uint)fVar6 & 8) == 0 || (param_1->CategoryID != 0x10)))) {
                if (((uint)fVar6 & 0x10) != 0) {
                  if (param_1->CategoryID == 0x40) goto LAB_4fc3d1b4;
                }
              }
              else {
LAB_4fc3d1b4:
                iVar7 = (*misnImport.GetTug)((int)pMVar8);
                if (iVar7 == 0) {
                  if ((Matrix *)local_1f0[-0x36] != (Matrix *)0x0) {
                    if (pMVar8 != (Matrix *)local_1f0[-0x36]) goto LAB_4fc3d231;
                  }
                  pfVar14 = (float *)(*(int *)&this->PortalList + 0xdc + (int)local_1f0[2] * 0x390);
                  VStack_1e0.x = *pfVar14;
                  VStack_1e0.y = pfVar14[1];
                  VStack_1e0.z = pfVar14[2];
                  pfVar14 = local_1d4;
                  pMVar8 = local_1c8;
                  if (__real_3dcccccd <=
                      VStack_1e0.y * VStack_1e0.y + VStack_1e0.x * VStack_1e0.x +
                      VStack_1e0.z * VStack_1e0.z) goto LAB_4fc3d254;
                }
              }
            }
          }
        }
      }
    }
LAB_4fc3d231:
    local_1f0 = local_1f0 + 0xe4;
    local_1d4 = pfVar14 + 0xe4;
    if (local_1d4 == *(float **)&(this->PortalList).field_0x4) {
      return;
    }
  } while( true );
LAB_4fc3d2a3:
  if (pfVar15 == *(float **)&(this->TeleportTargetList).field_0x4) goto LAB_4fc3d2b4;
  pMVar8 = (Matrix *)(*misnImport.GetTug)((int)*pfVar15);
  if (pMVar8 == local_1c8) {
    local_1b8 = (Matrix *)*pfVar15;
    goto LAB_4fc3d2b4;
  }
  pfVar15 = pfVar15 + 5;
  goto LAB_4fc3d2a3;
LAB_4fc3d2b4:
  pvVar3 = local_18c;
  std::vector<PortalHelper::TeleportTargetClass,std::allocator<PortalHelper::TeleportTargetClass>_>
  ::_Resize<<lambda_f2c0a61063d8731356913bf41ed3079e>_>
            (local_18c,(*(int *)&local_18c->field_0x4 - *(int *)local_18c) / 0x14 + 1,
             (<lambda_f2c0a61063d8731356913bf41ed3079e>)local_18c);
  pMVar8 = local_1c8;
  iVar7 = *(int *)pvVar3;
  iVar13 = ((*(int *)&pvVar3->field_0x4 - iVar7) / 0x14) * 0x14;
  local_1a0 = (double)CONCAT44(local_1a0._4_4_,iVar13);
  *(undefined4 *)(iVar13 + -0x10 + iVar7) = 0;
  *(undefined4 *)(iVar13 + -0xc + iVar7) = 0;
  *(undefined4 *)(iVar13 + -8 + iVar7) = 0;
  *(undefined4 *)(iVar13 + -4 + iVar7) = 0;
  *(Matrix **)(iVar13 + -0x14 + iVar7) = local_1c8;
  *(undefined4 *)(iVar13 + -8 + iVar7) =
       *(undefined4 *)((int)pfVar14[0x3b] * 0x390 + 0x80 + *(int *)&this->PortalList);
  *(float *)(iVar13 + -0x10 + iVar7) = pfVar14[1];
  *(float *)(iVar13 + -0xc + iVar7) = pfVar14[0x3b];
  local_1bc = pfVar14 + 0x2b;
  GetPosition((int)local_1c8,&MStack_108);
  GetVelocity((Vector *)auStack_170,(int)pMVar8);
  local_1a8 = (code *)((int)pfVar14[0x3b] * 0x390);
  local_1e8._0_4_ = *(undefined4 *)&this->PortalList;
  local_1cc = (Matrix *)(local_1e8._0_4_ + 0xac + (int)local_1a8);
  pMVar8 = local_1cc;
  pMVar5 = &MStack_158;
  for (iVar7 = 0x10; iVar7 != 0; iVar7 = iVar7 + -1) {
    (pMVar5->right).x = (pMVar8->right).x;
    pMVar8 = (Matrix *)&(pMVar8->right).y;
    pMVar5 = (Matrix *)&(pMVar5->right).y;
  }
  if (*(char *)((int)local_1a8 + 0x13 + local_1e8._0_4_) == '\0') {
    MStack_158.right.x = (float)((uint)MStack_158.right.x ^ __xmm_80000000800000008000000080000000);
    MStack_158.right.y = (float)((uint)MStack_158.right.y ^ __xmm_80000000800000008000000080000000);
    MStack_158.right.z = (float)((uint)MStack_158.right.z ^ __xmm_80000000800000008000000080000000);
    VStack_1e0.x = (float)((uint)MStack_158.front.x ^ __xmm_80000000800000008000000080000000);
    VStack_1e0.y = (float)((uint)MStack_158.front.y ^ __xmm_80000000800000008000000080000000);
    VStack_1e0.z = (float)((uint)MStack_158.front.z ^ __xmm_80000000800000008000000080000000);
    MStack_158.front.x = VStack_1e0.x;
    MStack_158.front.y = VStack_1e0.y;
    MStack_158.front.z = VStack_1e0.z;
    Matrix_Inverse(unaff_EDI,unaff_ESI);
    pMVar8 = Matrix_Multiply(&MStack_158,unaff_EDI,unaff_ESI);
    pMVar5 = aMStack_88;
    for (iVar7 = 0x10; iVar7 != 0; iVar7 = iVar7 + -1) {
      (pMVar5->right).x = (pMVar8->right).x;
      pMVar8 = (Matrix *)&(pMVar8->right).y;
      pMVar5 = (Matrix *)&(pMVar5->right).y;
    }
    pMVar8 = Matrix_Multiply(aMStack_88,unaff_EDI,unaff_ESI);
    pMVar5 = &MStack_158;
    for (iVar7 = 0x10; iVar7 != 0; iVar7 = iVar7 + -1) {
      (pMVar5->right).x = (pMVar8->right).x;
      pMVar8 = (Matrix *)&(pMVar8->right).y;
      pMVar5 = (Matrix *)&(pMVar5->right).y;
    }
    pVVar9 = Vector_Rotate((Vector *)auStack_170,unaff_EDI,&unaff_ESI->right);
  }
  else {
    Matrix_Inverse(unaff_EDI,unaff_ESI);
    pMVar8 = Matrix_Multiply(local_1cc,unaff_EDI,unaff_ESI);
    pMVar5 = aMStack_88;
    for (iVar7 = 0x10; iVar7 != 0; iVar7 = iVar7 + -1) {
      (pMVar5->right).x = (pMVar8->right).x;
      pMVar8 = (Matrix *)&(pMVar8->right).y;
      pMVar5 = (Matrix *)&(pMVar5->right).y;
    }
    Vector_TransformInv((Vector *)(local_1bc + 0xc),unaff_EDI,&unaff_ESI->right);
    pVVar9 = Vector_Transform(__return_storage_ptr__,unaff_EDI,&unaff_ESI->right);
    MStack_158.posit.x = pVVar9->x;
    MStack_158.posit.y = pVVar9->y;
    MStack_158.posit.z = pVVar9->z;
    fVar17 = (float10)__CIsqrt();
    pVVar9 = &VStack_1e0;
    local_1cc = (Matrix *)(float)fVar17;
    VStack_1e0.x = *(float *)((int)local_1a8 + 0xcc + local_1e8._0_4_) * (float)local_1cc;
    VStack_1e0.y = (float)(*(float *)((int)local_1a8 + 0xd0 + local_1e8._0_4_) * (float)local_1cc);
    VStack_1e0.z = (float)local_1cc * *(float *)((int)local_1a8 + 0xd4 + local_1e8._0_4_);
  }
  pfVar14 = local_1d4;
  dVar20 = (double)ZEXT48(in_stack_fffffdf0);
  local_1b4.x = pVVar9->x;
  local_1b4.y = (float)pVVar9->y;
  local_1b4.z = pVVar9->z;
  fVar6 = local_1d4[0x3b];
  if (*(char *)((int)fVar6 * 0x390 + 0x16 + local_1e8._0_4_) != '\0') {
    pfVar15 = (float *)((int)fVar6 * 0x390 + 0xdc + local_1e8._0_4_);
    MStack_158.posit.x = *pfVar15;
    MStack_158.posit.y = pfVar15[1];
    MStack_158.posit.z = pfVar15[2];
  }
  if (local_1e8[7] != '\0') {
    FormatLogMessage("Entrance Front Vector Is %f %f %f");
    FormatLogMessage("Exit Front Vector Is %f %f %f");
    FormatLogMessage("Player Front Vector Is %f %f %f");
    FormatLogMessage("Player Up Vector Is %f %f %f");
    FormatLogMessage("Player Right Vector Is %f %f %f");
    FormatLogMessage("Player Velocity Vector Is %f %f %f");
    FormatLogMessage("New Front Vector Is %f %f %f");
    FormatLogMessage("New Up Vector Is %f %f %f");
    FormatLogMessage("New Right Vector Is %f %f %f");
    dVar20 = (double)local_1b4.x;
    in_stack_fffffdec = "New Velocity Vector Is %f %f %f";
    in_stack_fffffde8 = 0x4fc3d780;
    FormatLogMessage("New Velocity Vector Is %f %f %f");
    fVar6 = pfVar14[0x3b];
    local_1e8._0_4_ = *(undefined4 *)&this->PortalList;
  }
  pMVar8 = local_1c8;
  iVar7 = (int)fVar6 * 0x390;
  fVar6 = *(float *)(iVar7 + 0x84 + local_1e8._0_4_);
  if (fVar6 != ___real_00000000) {
    if (*(char *)(iVar7 + 0x13 + local_1e8._0_4_) != '\0') {
      local_1b4.x = *(float *)(iVar7 + 0xcc + local_1e8._0_4_);
      local_1b4.y = *(float *)(iVar7 + 0xd0 + local_1e8._0_4_);
      local_1b4.z = *(float *)(iVar7 + 0xd4 + local_1e8._0_4_);
    }
    VStack_1e0.y = local_1b4.y * fVar6;
    VStack_1e0.x = local_1b4.x * fVar6;
    VStack_1e0.z = fVar6 * local_1b4.z;
    local_1b4.x = VStack_1e0.x;
    local_1b4.y = VStack_1e0.y;
    local_1b4.z = VStack_1e0.z;
  }
  local_1e8._0_4_ = fVar6;
  bVar4 = IsPlayer((int)local_1c8);
  pfVar14 = local_1d4;
  uStack_1d0 = (Matrix *)CONCAT13(bVar4,(undefined3)uStack_1d0);
  iVar7 = *(int *)&this->PortalList;
  if ((local_1b4.x * local_1b4.x + local_1b4.y * local_1b4.y + local_1b4.z * local_1b4.z <
       __real_3dcccccd) ||
     ((*(char *)((int)local_1d4[0x3b] * 0x390 + 0x17 + iVar7) != '\0' && (!bVar4)))) {
    iVar13 = (int)local_1d4[0x3b] * 0x390;
    VStack_1e0.z = (float)___real_4034000000000000;
    VStack_1e0.x = *(float *)(iVar13 + 0xcc + iVar7) * VStack_1e0.z;
    VStack_1e0.y = *(float *)(iVar13 + 0xd0 + iVar7) * VStack_1e0.z;
    VStack_1e0.z = VStack_1e0.z * *(float *)(iVar13 + 0xd4 + iVar7);
    pMVar8 = local_1c8;
    local_1b4.x = VStack_1e0.x;
    local_1b4.y = VStack_1e0.y;
    local_1b4.z = VStack_1e0.z;
  }
  SetCurAmmo((int)*local_1d4,0);
  pMVar5 = SUB84(dVar20,0);
  if (local_1b8 != (Matrix *)0x0) {
    Deploy((int)pMVar8);
    pMVar5 = SUB84(dVar20,0);
  }
  local_1cc = (Matrix *)SetPosition_exref;
  pMVar10 = pMVar8;
  SetPosition((int)pMVar8,&MStack_158);
  pVVar9 = &local_1b4;
  local_1a8 = SetVelocity_exref;
  pVVar21 = (Vector *)0x4fc3d8ef;
  pMVar11 = pMVar8;
  SetVelocity((int)pMVar8,pVVar9);
  if (local_1b8 != (Matrix *)0x0) {
    pMVar8 = &MStack_c8;
    pMVar5 = local_1b8;
    GetPosition((int)local_1b8,pMVar8);
    Vector_TransformInv(&MStack_c8.posit,pMVar5,&pMVar8->right);
    fStack_164 = MStack_158.posit.x;
    fStack_160 = MStack_158.posit.y;
    fStack_15c = MStack_158.posit.z;
    pMVar8 = Matrix_Multiply(aMStack_88,unaff_EDI,unaff_ESI);
    pMVar5 = &MStack_158;
    for (iVar7 = 0x10; iVar7 != 0; iVar7 = iVar7 + -1) {
      (pMVar5->right).x = (pMVar8->right).x;
      pMVar8 = (Matrix *)&(pMVar8->right).y;
      pMVar5 = (Matrix *)&(pMVar5->right).y;
    }
    if (*(char *)((int)local_1d4[0x3b] * 0x390 + 0x13 + *(int *)&this->PortalList) == '\0') {
      MStack_158.right.x =
           (float)((uint)MStack_158.right.x ^ __xmm_80000000800000008000000080000000);
      MStack_158.right.y =
           (float)((uint)MStack_158.right.y ^ __xmm_80000000800000008000000080000000);
      MStack_158.right.z =
           (float)((uint)MStack_158.right.z ^ __xmm_80000000800000008000000080000000);
      VStack_1e0.x = (float)((uint)MStack_158.front.x ^ __xmm_80000000800000008000000080000000);
      VStack_1e0.y = (float)((uint)MStack_158.front.y ^ __xmm_80000000800000008000000080000000);
      VStack_1e0.z = (float)((uint)MStack_158.front.z ^ __xmm_80000000800000008000000080000000);
      MStack_158.front.x = VStack_1e0.x;
      MStack_158.front.y = VStack_1e0.y;
      MStack_158.front.z = VStack_1e0.z;
    }
    MStack_158.posit.x = fStack_164;
    MStack_158.posit.y = fStack_160;
    MStack_158.posit.z = fStack_15c;
    pVVar9 = Vector_Transform(&VStack_114,unaff_EDI,&unaff_ESI->right);
    pvVar3 = local_18c;
    MStack_158.posit.x = pVVar9->x;
    MStack_158.posit.y = pVVar9->y;
    MStack_158.posit.z = pVVar9->z;
    std::
    vector<PortalHelper::TeleportTargetClass,std::allocator<PortalHelper::TeleportTargetClass>_>::
    _Resize<<lambda_f2c0a61063d8731356913bf41ed3079e>_>
              (local_18c,(*(int *)&local_18c->field_0x4 - *(int *)local_18c) / 0x14 + 1,
               (<lambda_f2c0a61063d8731356913bf41ed3079e>)local_18c);
    pMVar5 = local_1b8;
    pfVar14 = local_1d4;
    iVar7 = *(int *)pvVar3;
    iVar13 = ((*(int *)&pvVar3->field_0x4 - iVar7) / 0x14) * 0x14;
    *(undefined4 *)(iVar13 + -0x10 + iVar7) = 0;
    *(undefined4 *)(iVar13 + -0xc + iVar7) = 0;
    *(undefined4 *)(iVar13 + -8 + iVar7) = 0;
    *(undefined4 *)(iVar13 + -4 + iVar7) = 0;
    *(Matrix **)(iVar13 + -0x14 + iVar7) = local_1b8;
    *(undefined4 *)(iVar13 + -8 + iVar7) =
         *(undefined4 *)((int)local_1d4[0x3b] * 0x390 + 0x80 + *(int *)&this->PortalList);
    *(float *)(iVar13 + -0x10 + iVar7) = local_1d4[1];
    pMVar10 = local_1b8;
    (*(code *)local_1cc)();
    pVVar9 = &local_1b4;
    pMVar11 = pMVar5;
    (*local_1a8)();
    pMVar8 = local_1c8;
    pVVar21 = (Vector *)0x1;
    in_stack_fffffde8 = 0x4fc3dae4;
    in_stack_fffffdec = (char *)local_1c8;
    Pickup((int)local_1c8,(int)pMVar5,1);
  }
  lVar22 = CONCAT44(0x4fc3daeb,pMVar10);
  pMVar10 = (Matrix *)(*local_17c)();
  if ((pMVar8 == pMVar10) && (pfVar14[0x42] != 0.0)) {
    SetColorFade(1.0,___real_40a00000,(ulong)pfVar14[0x42]);
    pMVar5 = (Matrix *)(pfVar14 + 0xc3);
    lVar22 = 0;
    in_stack_fffffdec = (char *)0x4fc3db3c;
    pVVar21 = local_188;
    pMVar11 = local_1c0;
    pVVar9 = local_188;
    (*local_184)();
  }
  BZ1Helper::m_BZ1Helper[1].teamInfo[0].PilotWeapon[4][0x20] = '\x01';
  if (*(char *)((int)pfVar14 + 0x1b) == '\0') {
    pVVar9 = (Vector *)pfVar14[0x3c];
    pMVar11 = (Matrix *)(((int)pfVar14 - *(int *)&this->PortalList) / local_1c4);
    lVar22 = (ulonglong)(*(char *)(pfVar14 + 6) == '\0') << 0x20;
    pVVar21 = (Vector *)0x4fc3dbb1;
    SetPortalEffectEnd_Internal(this,(int)pMVar11,(int)pVVar9,0,*(char *)(pfVar14 + 6) == '\0');
  }
  else {
    pMVar8 = &MStack_108;
    pfVar15 = afStackY_444 + 0x83;
    for (iVar7 = 0x10; pfVar14 = local_1d4, iVar7 != 0; iVar7 = iVar7 + -1) {
      *pfVar15 = (pMVar8->right).x;
      pMVar8 = (Matrix *)&(pMVar8->right).y;
      pfVar15 = pfVar15 + 1;
    }
    MVar1.right.y = 0.0;
    MVar1.right.x = local_1d4[0x3f];
    MVar1.right.z = (float)in_stack_fffffdc8._0_4_;
    MVar1.rightw = (float)in_stack_fffffdc8._4_4_;
    MVar1.up.x = (float)in_stack_fffffdc8._8_4_;
    MVar1.up.y = (float)in_stack_fffffdc8._12_4_;
    MVar1.up.z = (float)in_stack_fffffdc8._16_4_;
    MVar1.upw = (float)in_stack_fffffddc;
    MVar1.front.x = (float)in_stack_fffffde0;
    MVar1.front.y = (float)in_stack_fffffde4;
    MVar1.front.z = (float)in_stack_fffffde8;
    MVar1.frontw = (float)in_stack_fffffdec;
    MVar1.posit.x = (float)pMVar5;
    MVar1.posit.y = (float)pVVar21;
    MVar1.posit.z = (float)pMVar11;
    MVar1.positw = (float)pVVar9;
    SetPortalEffectVeh_Internal
              (this,((int)local_1d4 - *(int *)&this->PortalList) / 0x390,MVar1,(int)lVar22,
               (int)((ulonglong)lVar22 >> 0x20));
  }
  fVar6 = pfVar14[0x3b];
  iVar7 = *(int *)&this->PortalList;
  iVar13 = (int)fVar6 * 0x390;
  local_1c4 = iVar7;
  if (*(char *)(iVar13 + 0x1b + iVar7) == '\0') {
    local_1c4 = *(int *)(iVar13 + 0xf4 + iVar7);
    SetPortalEffectEnd_Internal
              (this,(int)fVar6,local_1c4,0,*(char *)(iVar13 + 0x18 + iVar7) == '\0');
  }
  else {
    pMVar8 = &MStack_158;
    pfVar14 = afStackY_444 + 0x83;
    for (iVar7 = 0x10; iVar7 != 0; iVar7 = iVar7 + -1) {
      *pfVar14 = (pMVar8->right).x;
      pMVar8 = (Matrix *)&(pMVar8->right).y;
      pfVar14 = pfVar14 + 1;
    }
    MVar2.right.y = 0.0;
    MVar2.right.x = (float)*(uint *)(iVar13 + 0x100 + local_1c4);
    MVar2.right.z = (float)in_stack_fffffdc8._0_4_;
    MVar2.rightw = (float)in_stack_fffffdc8._4_4_;
    MVar2.up.x = (float)in_stack_fffffdc8._8_4_;
    MVar2.up.y = (float)in_stack_fffffdc8._12_4_;
    MVar2.up.z = (float)in_stack_fffffdc8._16_4_;
    MVar2.upw = (float)in_stack_fffffddc;
    MVar2.front.x = (float)in_stack_fffffde0;
    MVar2.front.y = (float)in_stack_fffffde4;
    MVar2.front.z = (float)in_stack_fffffde8;
    MVar2.frontw = (float)in_stack_fffffdec;
    MVar2.posit.x = (float)pMVar5;
    MVar2.posit.y = (float)pVVar21;
    MVar2.posit.z = (float)pMVar11;
    MVar2.positw = (float)pVVar9;
    SetPortalEffectVeh_Internal(this,(int)fVar6,MVar2,(int)lVar22,(int)((ulonglong)lVar22 >> 0x20));
  }
  pMVar8 = local_1c8;
  iVar7 = BZ1Helper::m_BZ1Helper->_padding_;
  BZ1Helper::m_BZ1Helper[1].teamInfo[0].PilotWeapon[4][0x20] = '\0';
  iVar7 = (**(code **)(iVar7 + 0x60))();
  piVar16 = (int *)VStack_1e0.y;
  if (local_1c0 == (Matrix *)0x0) {
    if ((VStack_1e0.z._3_1_ == '\0') && (iVar7 == 0)) {
      AVar12 = GetCurrentCommand((int)pMVar8);
      if (AVar12 == CMD_GO) {
        GetCurrentCommandWhere((Vector *)local_1e8,(int)pMVar8);
        pfVar14 = (float *)GetCurrentWho((int)pMVar8);
        local_1d4 = (float *)*piVar16;
        if (pfVar14 != local_1d4) {
          if ((float)local_1e8._4_4_ * (float)local_1e8._4_4_ +
              (float)local_1e8._0_4_ * (float)local_1e8._0_4_ + VStack_1e0.x * VStack_1e0.x <
              __real_3dcccccd) goto LAB_4fc3ddba;
          local_1cc = (Matrix *)(*(float *)((float)piVar16 + 0x39) - VStack_1e0.x);
          local_1a8 = (code *)(*(float *)((float)piVar16 + 0x37) - (float)local_1e8._0_4_);
          fVar17 = (float10)__CIsqrt();
          local_1a8 = (code *)(float)fVar17;
          if ((float)___real_3fb99999a0000000 <= (float)local_1a8) {
            local_1a8 = (code *)local_1e8._0_4_;
            local_1a4 = (float)local_1e8._4_4_;
            local_1a0 = (double)CONCAT44(local_1a0._4_4_,VStack_1e0.x);
            GetPosition((int)local_1d4,(Vector *)(auStack_170 + 4));
            local_1cc = (Matrix *)((float)local_1a8 - (float)auStack_170._4_4_);
            local_1a8 = (code *)(local_1a0._0_4_ - fStack_164);
            fVar17 = (float10)__CIsqrt();
            local_1a8 = (code *)(float)fVar17;
            piVar16 = (int *)VStack_1e0.y;
            if (*(float *)((int)VStack_1e0.y + 0x80) + (float)___real_4039000000000000 <=
                (float)local_1a8) goto LAB_4fc3ddba;
            pMVar8 = uStack_1d0;
          }
        }
        (*local_180)();
        SetCommand((int)pMVar8,0,0,0,(char *)0x0,0);
      }
    }
  }
LAB_4fc3ddba:
  cStack_1e9 = (char)((uint)this >> 0x18);
  if (cStack_1e9 != '\0') {
    fVar17 = (float10)__CIsqrt();
    local_188 = (Vector *)(float)fVar17;
    GetLabel(param_1->ObjectHandle);
    FormatLogMessage(
                    "Teleporter on Team: %d Index: %d Aquired Target on Team: %d Handle: %08x Label: %s Distance is: %f"
                    );
  }
  if (piVar16[3] != 0) {
    BZ1Helper::DeleteAfterDelay(BZ1Helper::m_BZ1Helper,*piVar16,(float)local_1c8);
    BZ1Helper::DeleteAfterDelay
              (BZ1Helper::m_BZ1Helper,*(int *)(piVar16[0x3b] * 0x390 + (int)(unaff_ESI->right).x),
               (float)local_1c8);
  }
  return;
}


// ---------------------------------------------------------------------
// PortalHelper::SetPortalEffectStart_Internal  @ 4fc3de5d  lines 1234-1333


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
// PortalHelper::SetPortalEffectOn_Internal  @ 4fc3df87  lines 1351-1409


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
// PortalHelper::SetPortalEffectEnd  @ 4fc3e042  lines 1413-1425


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
// PortalHelper::SetPortalEffectEnd_Internal  @ 4fc3e08b  lines 1427-1514


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
    if (param_4) goto LAB_4fc3e13f;
    iVar3 = 0;
  }
  PlayPortalSoundFx(this,param_1,iVar3,SUB41(iVar1,0));
LAB_4fc3e13f:
  if (bVar2) {
    GetEmitterMask(*(int *)(*(int *)&this->PortalList + iVar4));
    FormatConsoleMessage
              ("PortalFx_End FxNum: %d, Type: %d, EffectHard%d, LifeTime: %d, EffectMask: %d");
  }
  return;
}


// ---------------------------------------------------------------------
// PortalHelper::SetPortalEffectVeh_Internal  @ 4fc3e17b  lines 1536-1562


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
// PortalHelper::SetPortalDest  @ 4fc3e2d3  lines 1603-1643


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
      goto joined_r0x4fc3e327;
    }
  }
  iVar6 = -1;
joined_r0x4fc3e327:
  do {
    if (piVar3 == piVar2) {
LAB_4fc3e356:
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
      goto LAB_4fc3e356;
    }
    piVar3 = piVar3 + 0xe4;
  } while( true );
}


// ---------------------------------------------------------------------
// PortalHelper::ShufflePortalDownInternal  @ 4fc3e392  lines 1754-1821


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
// PortalHelper::ShufflePortalUpInternal  @ 4fc3e447  lines 1851-1897


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
// PortalHelper::ResetPortalDestinations  @ 4fc3e507  lines 1901-1914


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
// PortalHelper::SortCycleList  @ 4fc3e53b  lines 1918-1935


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
// PortalHelper::PlayPortalSoundFx  @ 4fc3e596  lines 1939-1985


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

