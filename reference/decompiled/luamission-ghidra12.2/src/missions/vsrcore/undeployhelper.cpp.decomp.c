// Reconstructed by Ghidra from LuaMission.dll + LuaMission.pdb
// Original source file: /e:/github/vsr_dll_source/missions/vsrcore/undeployhelper.cpp
// Functions are ordered by original source line. This is decompiler
// output, not the author's source: names/types come from the PDB,
// local variable names and control flow are reconstructed.


// ---------------------------------------------------------------------
// `dynamic_initializer_for_'TempUndeployBuffer''  @ 4fc01764  lines 7-7


void __cdecl _dynamic_initializer_for__TempUndeployBuffer__(void)

{
  atexit(_dynamic_atexit_destructor_for__TempUndeployBuffer__);
  return;
}


// ---------------------------------------------------------------------
// UndeployHelper::PostLoad  @ 4fc3072a  lines 42-65


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
// UndeployHelper::AddUndeployObject  @ 4fc307c2  lines 83-175


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
// UndeployHelper::Execute  @ 4fc30b55  lines 178-301


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall UndeployHelper::Execute(UndeployHelper *this,BZ1Helper *param_1)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  AlignTerrainReplaceClass *pAVar7;
  AlignTerrainReplaceClass *pAVar8;
  char *unaff_ESI;
  AlignTerrainReplaceClass *pAVar9;
  size_t sVar10;
  AlignTerrainReplaceClass *pAVar11;
  bool *unaff_EDI;
  float fVar12;
  ulong uVar13;
  undefined1 auStack_f0 [3];
  char cStack_ed;
  AlignTerrainReplaceClass *local_ec;
  BZ1Helper *local_e8;
  float local_e4;
  UndeployHelper *local_e0;
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
  local_e8 = param_1;
  pAVar11 = *(AlignTerrainReplaceClass **)&(this->UndeployList).field_0x4;
  pAVar8 = *(AlignTerrainReplaceClass **)&this->UndeployList;
  local_e0 = this;
  while ((pAVar8 != pAVar11 && (bVar1 = BZ1Helper::ShouldRemoveAlignTerrainReplace(pAVar8), !bVar1))
        ) {
    pAVar8 = pAVar8 + 1;
  }
  if (pAVar8 != pAVar11) {
    local_ec = pAVar8 + 1;
    pAVar7 = pAVar8;
    if (local_ec != pAVar11) {
      do {
        pAVar9 = local_ec;
        bVar1 = BZ1Helper::ShouldRemoveAlignTerrainReplace(local_ec);
        pAVar8 = pAVar7;
        if (!bVar1) {
          pAVar8 = pAVar7 + 1;
          pAVar7->AlignHandle = pAVar9->AlignHandle;
          (pAVar7->NormalVec).x = (pAVar9->NormalVec).x;
          (pAVar7->NormalVec).y = (pAVar9->NormalVec).y;
          (pAVar7->NormalVec).z = (pAVar9->NormalVec).z;
          pAVar9 = local_ec;
        }
        local_ec = pAVar9 + 1;
        pAVar7 = pAVar8;
      } while (local_ec != pAVar11);
      this = local_e0;
    }
    if (pAVar8 != pAVar11) {
      sVar10 = *(int *)&(this->UndeployList).field_0x4 - (int)pAVar11;
      memmove(pAVar8,pAVar11,sVar10);
      piVar2 = (int *)(sVar10 + (int)pAVar8);
      *(int **)&(this->UndeployList).field_0x4 = piVar2;
      goto LAB_4fc30bec;
    }
  }
  piVar2 = *(int **)&(this->UndeployList).field_0x4;
LAB_4fc30bec:
  pAVar11 = *(AlignTerrainReplaceClass **)&this->UndeployList;
  bVar1 = pAVar11 == (AlignTerrainReplaceClass *)piVar2;
  do {
    if (bVar1) {
      return;
    }
    *(int *)((int)pAVar11 + 8) = *(int *)((int)pAVar11 + 8) + -1;
    local_ec = pAVar11;
    SetCommand(pAVar11->AlignHandle,0x23,0,0,(char *)0x0,0);
    if (BZ1Helper::Logging != false) {
      local_e4 = GetAnimationFrame(pAVar11->AlignHandle,"undeploy");
      GetODFName(SUB84((double)*(float *)((int)pAVar11 + 0xc),0));
      FormatLogMessage("UnbdeployObject %08d \'%s\' UndeployFrames: %f, CurrFrame: %f");
    }
    if (((char)*(int *)((int)pAVar11 + 4) != '\0') &&
       (fVar12 = GetAnimationFrame(pAVar11->AlignHandle,"undeploy"),
       *(float *)((int)pAVar11 + 0xc) - 1.0 <= fVar12)) {
      PauseAnimation(pAVar11->AlignHandle);
      *(undefined1 *)((int)pAVar11 + 4) = 0;
    }
    if (*(int *)((int)pAVar11 + 8) < 0) {
      if ((char)*(int *)((int)pAVar11 + 4) != '\0') {
        fVar12 = GetAnimationFrame(pAVar11->AlignHandle,"undeploy");
        if (fVar12 < *(float *)((int)pAVar11 + 0xc) - 1.0) goto LAB_4fc30f03;
      }
      iVar3 = GetTeamNum(pAVar11->AlignHandle);
      local_e4 = (float)(*misnImport.GetScrap)(iVar3);
      iStack_dc = iVar3 * 0xa14;
      uStack_d8 = *(undefined4 *)((int)local_e8->teamInfo + iStack_dc + 0x94);
      memset(acStack_c8,0,0x40);
      iVar4 = GetODFString(0x4fc5b728,(char *)0x40,acStack_c8,0,unaff_EDI,unaff_ESI);
      if ((iVar4 == 0) || (acStack_c8[0] == '\0')) {
        memset(acStack_48,0,0x40);
        GetODFName((int)unaff_EDI,unaff_ESI);
        strcpy_s(acStack_c8,0x40,acStack_48);
        acStack_c8[1] = 0x76;
      }
      iVar4 = GetCategoryTypeOverride(pAVar11->AlignHandle);
      cStack_ed = '\0';
      if (((acStack_c8[0] == '\0') || (bVar1 = DoesODFExist(acStack_c8), !bVar1)) ||
         ((8 < iVar4 - 1U && (iVar5 = GetFirstEmptyGroup(iVar3), iVar5 < 0)))) {
        bVar1 = DoesODFExist(acStack_c8);
        if (bVar1) {
          FormatLogMessage("ERROR: No Free Group! Cannot Undeploy!");
          iVar4 = GetLocalPlayerTeamNumber();
          if ((iVar4 == iVar3) && (bVar1 = IsNetworkOn(), bVar1)) {
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
        pAVar11 = local_ec;
        uStack_d4 = 0;
        uStack_d0 = 0;
        uStack_cc = 0;
        iVar5 = BZ1Helper::ReplaceObject
                          (local_e8,local_ec->AlignHandle,acStack_c8,-1,0.0,-1,true,-1,-1,true,-1,0,
                           -1,(Vector)ZEXT812(0));
        if (8 < iVar4 - 1U) {
          SetBestGroup(iVar5);
        }
        memset(acStack_88,0,0x40);
        GetObjInfo(iVar5,Get_GOClass,acStack_88);
        iVar4 = GetODFBool(0x4fc5ba50,&cStack_ed,(char *)0x0,unaff_EDI,SUB41(unaff_ESI,0));
        if (((iVar4 != 0) ||
            (iVar4 = GetODFBool(0x4fc5ba50,&cStack_ed,(char *)0x0,unaff_EDI,SUB41(unaff_ESI,0)),
            iVar4 != 0)) &&
           ((cStack_ed != '\0' ||
            ((iVar4 = _stricmp(acStack_88,"CLASS_RECYCLERVEHICLE"), iVar4 == 0 ||
             (iVar4 = _stricmp(acStack_88,"CLASS_RECYCLERVEHICLEH"), iVar4 == 0)))))) {
          (*misnImport.SetScrap)(iVar3,(int)local_e4);
        }
        *(undefined4 *)((int)local_e8->teamInfo[0].LimiterObject + iStack_dc + 0x14) = uStack_d8;
        this = local_e0;
      }
    }
LAB_4fc30f03:
    pAVar11 = (AlignTerrainReplaceClass *)((int)pAVar11 + 0x10);
    bVar1 = pAVar11 == (AlignTerrainReplaceClass *)*(int **)&(this->UndeployList).field_0x4;
  } while( true );
}

