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
  UndeployClass *unaff_ESI;
  int *piVar4;
  UndeployClass *unaff_EDI;
  int iVar5;
  
  piVar4 = *(int **)&this->UndeployList;
  piVar2 = *(int **)&(this->UndeployList).field_0x4;
  if (piVar4 != piVar2) {
    do {
      ConvertHandles(piVar4,1);
      piVar2 = *(int **)&(this->UndeployList).field_0x4;
      piVar4 = piVar4 + 4;
    } while (piVar4 != piVar2);
    piVar4 = *(int **)&this->UndeployList;
  }
  iVar3 = (int)piVar2 - (int)piVar4 >> 4;
  if ((int)(TempUndeployBuffer._4_4_ - TempUndeployBuffer._0_4_) >> 4 == iVar3) {
    iVar5 = 0;
    if (0 < iVar3) {
      do {
        bVar1 = ::operator==(unaff_EDI,unaff_ESI);
        if (!bVar1) {
          FormatLogMessage("UndeployList Index Mismatch: %d");
          return true;
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < *(int *)&(this->UndeployList).field_0x4 - *(int *)&this->UndeployList >> 4);
    }
  }
  else {
    FormatLogMessage("UndeployList Size Mismatch! Old: %d New: %d");
  }
  return true;
}


// ---------------------------------------------------------------------
// UndeployHelper::AddUndeployObject  @ 4fc1c8e8  lines 83-175


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

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
  char *unaff_ESI;
  int iVar8;
  float *unaff_EDI;
  int iVar9;
  float fVar10;
  undefined1 auStack_19c [7];
  char local_195;
  float local_194;
  int local_190;
  char local_18c [64];
  byte local_14c [64];
  char local_10c [64];
  undefined1 local_cc [64];
  undefined1 local_8c [64];
  char local_4c [68];
  uint local_8;
  
  local_8 = __security_cookie ^ (uint)auStack_19c;
  pcVar7 = (char *)param_2;
  do {
    cVar1 = *pcVar7;
    pcVar7 = pcVar7 + 1;
  } while (cVar1 != '\0');
  if (7 < (uint)((int)pcVar7 - (param_2 + 1))) {
    atoi((char *)(param_2 + 8));
    iVar4 = GetObjectByBaseSlot((int)unaff_EDI,(int)unaff_ESI);
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
      GetAndOpenODFNames((int)local_8c,(char *)0x0,(char *)unaff_EDI,unaff_ESI);
      local_195 = '\0';
      local_194 = 5.0;
      memset(local_4c,0,0x40);
      local_190 = 0;
      GetODFInt("GameObjectClass","animCount",(char *)&local_190,(char *)0x0,(int *)unaff_EDI,
                (int)unaff_ESI);
      iVar9 = 1;
      if (1 < local_190 + 1) {
        do {
          memset(local_10c,0,0x40);
          sprintf_s<64>(&local_10c,"animName%d");
          iVar6 = GetODFString("GameObjectClass",local_10c,(char *)0x40,local_4c,0,(char *)unaff_EDI
                               ,unaff_ESI);
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
      bVar3 = OpenODF2((char *)unaff_EDI);
      if (bVar3) {
        memset(local_10c,0,0x40);
        iVar9 = GetODFString(local_18c,"GameObjectClass","classlabel",0x40,local_10c,(char *)0x0);
        if (iVar9 != 0) {
          CombineStrings(".odf",(char *)0x40,(char *)unaff_EDI,(uint)unaff_ESI);
          bVar3 = OpenODF2((char *)unaff_EDI);
          local_14c[0] = local_14c[0] & -bVar3;
        }
        iVar9 = GetODFFloat("DeployableClass","timeUndeploy",(char *)&local_194,___real_40a00000,
                            unaff_EDI,(float)unaff_ESI);
        if (((iVar9 != 0) ||
            (iVar9 = GetODFFloat("TrackedDeployableClass","timeUndeploy",(char *)&local_194,
                                 ___real_40a00000,unaff_EDI,(float)unaff_ESI), iVar9 != 0)) &&
           (local_194 < 0.0)) {
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
      FormatLogMessage("Adding UndeployObject: \'%s\', Class: \'%s\', Time: %d, Frames: %f");
    }
  }
  return;
}


// ---------------------------------------------------------------------
// UndeployHelper::Execute  @ 4fc1cc7b  lines 178-301


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall UndeployHelper::Execute(UndeployHelper *this,BZ1Helper *param_1)

{
  AlignTerrainReplaceClass *pAVar1;
  bool bVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  AlignTerrainReplaceClass *pAVar7;
  AlignTerrainReplaceClass *pAVar8;
  char *unaff_ESI;
  AlignTerrainReplaceClass *pAVar9;
  UndeployHelper *pUVar10;
  bool *unaff_EDI;
  size_t sVar11;
  float fVar12;
  ulong uVar13;
  undefined1 auStack_f0 [3];
  char cStack_ed;
  UndeployHelper *local_ec;
  AlignTerrainReplaceClass *local_e8;
  BZ1Helper *local_e4;
  int iStack_e0;
  int iStack_dc;
  undefined4 uStack_d8;
  undefined4 uStack_d4;
  undefined4 uStack_d0;
  undefined4 uStack_cc;
  char acStack_c8 [64];
  char acStack_88 [64];
  char acStack_48 [68];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)auStack_f0;
  local_e4 = param_1;
  pAVar9 = *(AlignTerrainReplaceClass **)&(this->UndeployList).field_0x4;
  pAVar7 = *(AlignTerrainReplaceClass **)&this->UndeployList;
  local_ec = this;
  local_e8 = pAVar9;
  while ((pAVar7 != pAVar9 && (bVar2 = BZ1Helper::ShouldRemoveAlignTerrainReplace(pAVar7), !bVar2)))
  {
    pAVar7 = pAVar7 + 1;
  }
  pAVar8 = pAVar7;
  if (pAVar7 != pAVar9) {
    while (pAVar1 = pAVar8, this = local_ec, pAVar8 = pAVar1 + 1, pAVar8 != pAVar9) {
      bVar2 = BZ1Helper::ShouldRemoveAlignTerrainReplace(pAVar8);
      if (!bVar2) {
        pAVar7->AlignHandle = pAVar8->AlignHandle;
        (pAVar7->NormalVec).x = pAVar1[1].NormalVec.x;
        (pAVar7->NormalVec).y = pAVar1[1].NormalVec.y;
        (pAVar7->NormalVec).z = pAVar1[1].NormalVec.z;
        pAVar7 = pAVar7 + 1;
        pAVar9 = local_e8;
      }
    }
    if (pAVar7 != pAVar9) {
      sVar11 = *(int *)&(local_ec->UndeployList).field_0x4 - (int)pAVar9;
      memmove(pAVar7,pAVar9,sVar11);
      piVar3 = (int *)(sVar11 + (int)pAVar7);
      *(int **)&(this->UndeployList).field_0x4 = piVar3;
      goto LAB_4fc1cd0f;
    }
  }
  piVar3 = *(int **)&(this->UndeployList).field_0x4;
LAB_4fc1cd0f:
  pUVar10 = *(UndeployHelper **)&this->UndeployList;
  bVar2 = pUVar10 == (UndeployHelper *)piVar3;
  while (!bVar2) {
    *(int *)((int)pUVar10 + 8) = *(int *)((int)pUVar10 + 8) + -1;
    local_ec = pUVar10;
    SetCommand(*(int *)pUVar10,0x23,0,0,(char *)0x0,0);
    if (BZ1Helper::Logging != false) {
      local_e8 = (AlignTerrainReplaceClass *)GetAnimationFrame(*(int *)pUVar10,"undeploy");
      GetODFName(SUB84((double)*(float *)((int)pUVar10 + 0xc),0));
      FormatLogMessage("UnbdeployObject %08d \'%s\' UndeployFrames: %f, CurrFrame: %f");
    }
    if (((char)*(int *)((int)pUVar10 + 4) != '\0') &&
       (fVar12 = GetAnimationFrame(*(int *)pUVar10,"undeploy"),
       *(float *)((int)pUVar10 + 0xc) - 1.0 <= fVar12)) {
      PauseAnimation(*(int *)pUVar10);
      *(undefined1 *)((int)pUVar10 + 4) = 0;
    }
    if ((*(int *)((int)pUVar10 + 8) < 0) &&
       (((char)*(int *)((int)pUVar10 + 4) == '\0' ||
        (fVar12 = GetAnimationFrame(*(int *)pUVar10,"undeploy"),
        *(float *)((int)pUVar10 + 0xc) - 1.0 <= fVar12)))) {
      iVar4 = GetTeamNum(*(int *)pUVar10);
      iStack_e0 = (*misnImport.GetScrap)(iVar4);
      iStack_dc = iVar4 * 0xa14;
      uStack_d8 = *(undefined4 *)((int)local_e4->teamInfo + iStack_dc + 0x94);
      memset(acStack_c8,0,0x40);
      iVar5 = GetODFString(0x4fc5ebb0,(char *)0x40,acStack_c8,0,unaff_EDI,unaff_ESI);
      if ((iVar5 == 0) || (acStack_c8[0] == '\0')) {
        memset(acStack_48,0,0x40);
        GetODFName((int)unaff_EDI,unaff_ESI);
        strcpy_s(acStack_c8,0x40,acStack_48);
        acStack_c8[1] = 0x76;
      }
      iVar5 = GetCategoryTypeOverride(*(int *)pUVar10);
      cStack_ed = '\0';
      pAVar9 = (AlignTerrainReplaceClass *)(iVar5 - 1);
      local_e8 = pAVar9;
      if (((acStack_c8[0] == '\0') || (bVar2 = DoesODFExist(acStack_c8), !bVar2)) ||
         (((AlignTerrainReplaceClass *)0x8 < pAVar9 &&
          (iVar5 = GetFirstEmptyGroup(iVar4), iVar5 < 0)))) {
        bVar2 = DoesODFExist(acStack_c8);
        if (bVar2) {
          FormatLogMessage("ERROR: No Free Group! Cannot Undeploy!");
          iVar5 = GetLocalPlayerTeamNumber();
          if ((iVar5 == iVar4) && (bVar2 = IsNetworkOn(), bVar2)) {
            uVar13 = 0xffff0000;
            pcVar6 = GetBZCCLocalizedString("mission","-- Can\'t Undeploy, No Free Groups.");
            AddToMessagesBox2(pcVar6,uVar13);
          }
        }
        else {
          FormatLogMessage("ERROR: ODF \'%s\' Doesn\'t Exist! Cannot Undeploy!");
        }
      }
      else {
        pUVar10 = local_ec;
        uStack_d4 = 0;
        uStack_d0 = 0;
        uStack_cc = 0;
        iVar5 = BZ1Helper::ReplaceObject
                          (local_e4,*(int *)local_ec,acStack_c8,-1,0.0,-1,true,-1,-1,true,-1,0,-1,
                           (Vector)ZEXT812(0));
        if ((AlignTerrainReplaceClass *)0x8 < local_e8) {
          SetBestGroup(iVar5);
        }
        memset(acStack_88,0,0x40);
        GetObjInfo(iVar5,Get_GOClass,acStack_88);
        iVar5 = GetODFBool(0x4fc5eed8,&cStack_ed,(char *)0x0,unaff_EDI,SUB41(unaff_ESI,0));
        if (((iVar5 != 0) ||
            (iVar5 = GetODFBool(0x4fc5eed8,&cStack_ed,(char *)0x0,unaff_EDI,SUB41(unaff_ESI,0)),
            iVar5 != 0)) &&
           ((cStack_ed != '\0' ||
            ((iVar5 = _stricmp(acStack_88,"CLASS_RECYCLERVEHICLE"), iVar5 == 0 ||
             (iVar5 = _stricmp(acStack_88,"CLASS_RECYCLERVEHICLEH"), iVar5 == 0)))))) {
          (*misnImport.SetScrap)(iVar4,iStack_e0);
        }
        *(undefined4 *)((int)local_e4->teamInfo[0].LimiterObject + iStack_dc + 0x14) = uStack_d8;
      }
    }
    pUVar10 = (UndeployHelper *)((int)pUVar10 + 0x10);
    bVar2 = pUVar10 == (UndeployHelper *)*(int **)&(this->UndeployList).field_0x4;
  }
  return;
}

