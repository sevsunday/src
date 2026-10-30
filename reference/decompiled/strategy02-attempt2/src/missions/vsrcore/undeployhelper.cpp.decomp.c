// Reconstructed by Ghidra from Strategy02.dll + Strategy02.pdb
// Original source file: /e:/github/vsr_dll_source/missions/vsrcore/undeployhelper.cpp
// Functions are ordered by original source line. This is decompiler
// output, not the author's source: names/types come from the PDB,
// local variable names and control flow are reconstructed.

// ---------------------------------------------------------------------
// `dynamic_initializer_for_'TempUndeployBuffer''  @ 4fc016f5  lines 7-7

void __cdecl _dynamic_initializer_for__TempUndeployBuffer__(void)

{
  atexit(_dynamic_atexit_destructor_for__TempUndeployBuffer__);
  return;
}


// ---------------------------------------------------------------------
// UndeployHelper::PostLoad  @ 4fc1c850  lines 42-65

bool __thiscall UndeployHelper::PostLoad(UndeployHelper *this,bool param_1)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  
  piVar5 = *(int **)&this->UndeployList;
  piVar2 = *(int **)&(this->UndeployList).field_0x4;
  if (piVar5 != piVar2) {
    do {
      ConvertHandles(piVar5,1);
      piVar2 = *(int **)&(this->UndeployList).field_0x4;
      piVar5 = piVar5 + 4;
    } while (piVar5 != piVar2);
    piVar5 = *(int **)&this->UndeployList;
  }
  iVar3 = (int)piVar2 - (int)piVar5 >> 4;
  iVar4 = (int)(TempUndeployBuffer._4_4_ - TempUndeployBuffer._0_4_) >> 4;
  if (iVar4 == iVar3) {
    iVar4 = 0;
    if (0 < iVar3) {
      iVar3 = 0;
      do {
        bVar1 = ::operator==((UndeployClass *)(TempUndeployBuffer._0_4_ + iVar3),
                             (UndeployClass *)((int)piVar5 + iVar3));
        if (!bVar1) {
          FormatLogMessage("UndeployList Index Mismatch: %d",iVar4);
          return true;
        }
        iVar4 = iVar4 + 1;
        piVar5 = *(int **)&this->UndeployList;
        iVar3 = iVar3 + 0x10;
      } while (iVar4 < *(int *)&(this->UndeployList).field_0x4 - (int)piVar5 >> 4);
    }
  }
  else {
    FormatLogMessage("UndeployList Size Mismatch! Old: %d New: %d",iVar4,iVar3);
  }
  return true;
}


// ---------------------------------------------------------------------
// UndeployHelper::AddUndeployObject  @ 4fc1c8e8  lines 83-175

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall
UndeployHelper::AddUndeployObject(UndeployHelper *this,int param_1,int param_2,char *param_3)

{
  char cVar1;
  int *piVar2;
  bool bVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  char *pcVar7;
  int iVar8;
  int iVar9;
  float fVar10;
  undefined1 auStack_19c [7];
  char local_195;
  float local_194;
  int local_190;
  char local_18c [64];
  byte local_14c [64];
  char local_10c [64];
  char local_cc [64];
  char local_8c [64];
  char local_4c [68];
  uint local_8;
  
  local_8 = __security_cookie ^ (uint)auStack_19c;
  pcVar7 = (char *)param_2;
  do {
    cVar1 = *pcVar7;
    pcVar7 = pcVar7 + 1;
  } while (cVar1 != '\0');
  if (7 < (uint)((int)pcVar7 - (param_2 + 1))) {
    iVar4 = atoi((char *)(param_2 + 8));
    iVar4 = GetObjectByBaseSlot(param_1,iVar4);
    if (iVar4 != 0) {
      SetCommand(iVar4,0x23,0,0,(char *)0x0,0);
      bVar3 = IsSelected(iVar4);
      if (bVar3) {
        IFace_ConsoleCmd("control.command.cancel",true);
      }
      piVar2 = *(int **)&(this->UndeployList).field_0x4;
      for (piVar5 = *(int **)&this->UndeployList; piVar5 != piVar2; piVar5 = piVar5 + 4) {
        if (*piVar5 == iVar4) {
          return;
        }
      }
      std::
      vector<BZ1Helper::AlignTerrainReplaceClass,std::allocator<BZ1Helper::AlignTerrainReplaceClass>_>
      ::_Resize<<lambda_1855a80fc533c550b5607d8bf997ad95>_>
                ((vector<BZ1Helper::AlignTerrainReplaceClass,std::allocator<BZ1Helper::AlignTerrainReplaceClass>_>
                  *)this,((int)piVar2 - *(int *)&this->UndeployList >> 4) + 1,
                 (<lambda_1855a80fc533c550b5607d8bf997ad95>)this);
      iVar8 = (*(int *)&(this->UndeployList).field_0x4 - *(int *)&this->UndeployList & 0xfffffff0U)
              + *(int *)&this->UndeployList;
      *(undefined4 *)(iVar8 + -0x10) = 0;
      *(undefined4 *)(iVar8 + -0xc) = 0;
      *(undefined4 *)(iVar8 + -8) = 0;
      *(undefined4 *)(iVar8 + -4) = 0;
      memset(local_cc,0,0x40);
      memset(local_8c,0,0x40);
      GetAndOpenODFNames(iVar4,local_cc,local_8c,(char *)0x0);
      local_195 = '\0';
      local_194 = 5.0;
      memset(local_4c,0,0x40);
      local_190 = 0;
      GetODFInt(local_cc,local_8c,"GameObjectClass","animCount",&local_190,0);
      iVar9 = 1;
      if (1 < local_190 + 1) {
        do {
          memset(local_10c,0,0x40);
          sprintf_s<64>(&local_10c,"animName%d",iVar9);
          iVar6 = GetODFString(local_cc,local_8c,"GameObjectClass",local_10c,0x40,local_4c,
                               (char *)0x0);
          if ((iVar6 != 0) &&
             (((iVar6 = _stricmp(local_4c,"deploy"), iVar6 == 0 && (local_190 == 1)) ||
              (iVar6 = _stricmp(local_4c,"undeploy"), iVar6 == 0)))) {
            local_195 = '\x01';
            break;
          }
          iVar9 = iVar9 + 1;
        } while (iVar9 < local_190 + 1);
      }
      memset(local_18c,0,0x40);
      memset(local_14c,0,0x40);
      GetObjInfo(iVar4,Get_ODF,local_18c);
      local_18c[1] = 0x76;
      bVar3 = OpenODF2(local_18c);
      if (bVar3) {
        memset(local_10c,0,0x40);
        iVar9 = GetODFString(local_18c,"GameObjectClass","classlabel",0x40,local_10c,(char *)0x0);
        if (iVar9 != 0) {
          CombineStrings((char *)local_14c,local_10c,".odf",0x40);
          bVar3 = OpenODF2((char *)local_14c);
          local_14c[0] = local_14c[0] & -bVar3;
        }
        iVar9 = GetODFFloat(local_18c,(char *)local_14c,"DeployableClass","timeUndeploy",&local_194,
                            5.0);
        if (((iVar9 != 0) ||
            (iVar9 = GetODFFloat(local_18c,(char *)local_14c,"TrackedDeployableClass","timeUndeploy"
                                 ,&local_194,5.0), iVar9 != 0)) && (local_194 < 0.0)) {
          local_194 = 0.0;
        }
      }
      *(int *)(iVar8 + -0x10) = iVar4;
      iVar4 = SecondsToTurns(local_194);
      *(int *)(iVar8 + -8) = iVar4;
      if (local_195 != '\0') {
        fVar10 = SetAnimation(*(int *)(iVar8 + -0x10),"undeploy",1);
        *(float *)(iVar8 + -4) = fVar10;
        StartAnimation(*(int *)(iVar8 + -0x10));
        *(undefined1 *)(iVar8 + -0xc) = 1;
      }
      FormatLogMessage("Adding UndeployObject: \'%s\', Class: \'%s\', Time: %d, Frames: %f",local_cc
                       ,local_18c,*(int *)(iVar8 + -8),(double)*(float *)(iVar8 + -4));
    }
  }
  return;
}


// ---------------------------------------------------------------------
// UndeployHelper::Execute  @ 4fc1cc7b  lines 178-301

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall UndeployHelper::Execute(UndeployHelper *this,BZ1Helper *bz1Helper)

{
  AlignTerrainReplaceClass *pAVar1;
  bool bVar2;
  int *piVar3;
  char *pcVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  AlignTerrainReplaceClass *entry;
  AlignTerrainReplaceClass *entry_00;
  AlignTerrainReplaceClass *pAVar8;
  UndeployHelper *pUVar9;
  undefined4 unaff_EDI;
  size_t sVar10;
  float fVar11;
  double dVar12;
  double dVar13;
  ulong uVar14;
  undefined1 auStack_f0 [3];
  bool bStack_ed;
  UndeployHelper *local_ec;
  AlignTerrainReplaceClass *local_e8;
  BZ1Helper *local_e4;
  int iStack_e0;
  int iStack_dc;
  int iStack_d8;
  undefined4 uStack_d4;
  undefined4 uStack_d0;
  undefined4 uStack_cc;
  char acStack_c8 [64];
  char acStack_88 [64];
  char acStack_48 [68];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)auStack_f0;
  local_e4 = bz1Helper;
  pAVar8 = *(AlignTerrainReplaceClass **)&(this->UndeployList).field_0x4;
  entry = *(AlignTerrainReplaceClass **)&this->UndeployList;
  local_ec = this;
  local_e8 = pAVar8;
  while ((entry != pAVar8 && (bVar2 = BZ1Helper::ShouldRemoveAlignTerrainReplace(entry), !bVar2))) {
    entry = entry + 1;
  }
  entry_00 = entry;
  if (entry != pAVar8) {
    while (pAVar1 = entry_00, this = local_ec, entry_00 = pAVar1 + 1, entry_00 != pAVar8) {
      bVar2 = BZ1Helper::ShouldRemoveAlignTerrainReplace(entry_00);
      if (!bVar2) {
        entry->AlignHandle = entry_00->AlignHandle;
        (entry->NormalVec).x = pAVar1[1].NormalVec.x;
        (entry->NormalVec).y = pAVar1[1].NormalVec.y;
        (entry->NormalVec).z = pAVar1[1].NormalVec.z;
        entry = entry + 1;
        pAVar8 = local_e8;
      }
    }
    if (entry != pAVar8) {
      sVar10 = *(int *)&(local_ec->UndeployList).field_0x4 - (int)pAVar8;
      memmove(entry,pAVar8,sVar10);
      piVar3 = (int *)(sVar10 + (int)entry);
      *(int **)&(this->UndeployList).field_0x4 = piVar3;
      goto LAB_4fc1cd0f;
    }
  }
  piVar3 = *(int **)&(this->UndeployList).field_0x4;
LAB_4fc1cd0f:
  pUVar9 = *(UndeployHelper **)&this->UndeployList;
  bVar2 = pUVar9 == (UndeployHelper *)piVar3;
  while (!bVar2) {
    *(int *)((int)pUVar9 + 8) = *(int *)((int)pUVar9 + 8) + -1;
    local_ec = pUVar9;
    SetCommand(*(int *)pUVar9,0x23,0,0,(char *)0x0,0);
    if (BZ1Helper::Logging != false) {
      local_e8 = (AlignTerrainReplaceClass *)GetAnimationFrame(*(int *)pUVar9,"undeploy");
      dVar13 = (double)(float)local_e8;
      dVar12 = (double)*(float *)((int)pUVar9 + 0xc);
      pcVar4 = GetODFName(*(int *)pUVar9);
      FormatLogMessage("UnbdeployObject %08d \'%s\' UndeployFrames: %f, CurrFrame: %f",
                       *(int *)pUVar9,pcVar4,
                       (double)CONCAT44(SUB84(dVar13,0),(int)((ulonglong)dVar12 >> 0x20)),
                       (double)CONCAT44(unaff_EDI,(int)((ulonglong)dVar13 >> 0x20)));
    }
    if (((char)*(int *)((int)pUVar9 + 4) != '\0') &&
       (fVar11 = GetAnimationFrame(*(int *)pUVar9,"undeploy"),
       *(float *)((int)pUVar9 + 0xc) - 1.0 <= fVar11)) {
      PauseAnimation(*(int *)pUVar9);
      *(undefined1 *)((int)pUVar9 + 4) = 0;
    }
    if ((*(int *)((int)pUVar9 + 8) < 0) &&
       (((char)*(int *)((int)pUVar9 + 4) == '\0' ||
        (fVar11 = GetAnimationFrame(*(int *)pUVar9,"undeploy"),
        *(float *)((int)pUVar9 + 0xc) - 1.0 <= fVar11)))) {
      iVar5 = GetTeamNum(*(int *)pUVar9);
      iStack_e0 = (*misnImport.GetScrap)(iVar5);
      iStack_dc = iVar5 * 0xa14;
      iStack_d8 = local_e4->teamInfo[iVar5].CurrPilots;
      memset(acStack_c8,0,0x40);
      iVar6 = GetODFString(*(int *)pUVar9,"GameObjectClass","UndeployClass",0x40,acStack_c8,
                           (char *)0x0);
      if ((iVar6 == 0) || (acStack_c8[0] == '\0')) {
        memset(acStack_48,0,0x40);
        GetODFName(*(int *)pUVar9,acStack_48);
        strcpy_s(acStack_c8,0x40,acStack_48);
        acStack_c8[1] = 0x76;
      }
      iVar6 = GetCategoryTypeOverride(*(int *)pUVar9);
      bStack_ed = false;
      pAVar8 = (AlignTerrainReplaceClass *)(iVar6 - 1);
      local_e8 = pAVar8;
      if (((acStack_c8[0] == '\0') || (bVar2 = DoesODFExist(acStack_c8), !bVar2)) ||
         (((AlignTerrainReplaceClass *)0x8 < pAVar8 &&
          (iVar6 = GetFirstEmptyGroup(iVar5), iVar6 < 0)))) {
        bVar2 = DoesODFExist(acStack_c8);
        if (bVar2) {
          FormatLogMessage("ERROR: No Free Group! Cannot Undeploy!");
          iVar6 = GetLocalPlayerTeamNumber();
          if ((iVar6 == iVar5) && (bVar2 = IsNetworkOn(), bVar2)) {
            uVar14 = 0xffff0000;
            pcVar4 = GetBZCCLocalizedString("mission","-- Can\'t Undeploy, No Free Groups.");
            AddToMessagesBox2(pcVar4,uVar14);
          }
        }
        else {
          FormatLogMessage("ERROR: ODF \'%s\' Doesn\'t Exist! Cannot Undeploy!",acStack_c8);
        }
      }
      else {
        pUVar9 = local_ec;
        uStack_d4 = 0;
        uStack_d0 = 0;
        uStack_cc = 0;
        iVar6 = BZ1Helper::ReplaceObject
                          (local_e4,*(int *)local_ec,acStack_c8,-1,0.0,-1,true,-1,-1,true,-1,0,-1,
                           (Vector)ZEXT812(0));
        if ((AlignTerrainReplaceClass *)0x8 < local_e8) {
          SetBestGroup(iVar6);
        }
        memset(acStack_88,0,0x40);
        GetObjInfo(iVar6,Get_GOClass,acStack_88);
        iVar7 = GetODFBool(iVar6,"ScavengerClass","AddScrapHoldToTotal",&bStack_ed,false);
        if (((iVar7 != 0) ||
            (iVar6 = GetODFBool(iVar6,"ScavengerHClass","AddScrapHoldToTotal",&bStack_ed,false),
            iVar6 != 0)) &&
           ((bStack_ed != false ||
            ((iVar6 = _stricmp(acStack_88,"CLASS_RECYCLERVEHICLE"), iVar6 == 0 ||
             (iVar6 = _stricmp(acStack_88,"CLASS_RECYCLERVEHICLEH"), iVar6 == 0)))))) {
          (*misnImport.SetScrap)(iVar5,iStack_e0);
        }
        *(int *)((int)local_e4->teamInfo[0].LimiterObject + iStack_dc + 0x14) = iStack_d8;
      }
    }
    pUVar9 = (UndeployHelper *)((int)pUVar9 + 0x10);
    bVar2 = pUVar9 == (UndeployHelper *)*(int **)&(this->UndeployList).field_0x4;
  }
  return;
}


