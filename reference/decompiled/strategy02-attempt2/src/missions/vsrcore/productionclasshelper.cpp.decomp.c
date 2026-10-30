// Reconstructed by Ghidra from Strategy02.dll + Strategy02.pdb
// Original source file: /e:/github/vsr_dll_source/missions/vsrcore/productionclasshelper.cpp
// Functions are ordered by original source line. This is decompiler
// output, not the author's source: names/types come from the PDB,
// local variable names and control flow are reconstructed.

// ---------------------------------------------------------------------
// ProductionClassHelper::AddProductionClassObject  @ 4fc1b92e  lines 20-237

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall
ProductionClassHelper::AddProductionClassObject
          (ProductionClassHelper *this,int param_1,char *param_2,char *param_3,int param_4,
          int param_5,int param_6,int param_7)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  int *piVar7;
  char *pcVar8;
  char *pcVar9;
  char *local_1a0;
  char *local_19c;
  char *local_198;
  int *local_194;
  int local_190;
  int local_18c;
  ProductionClassHelper *local_188;
  char local_184 [64];
  char local_144 [64];
  char local_104 [64];
  char local_c4 [64];
  char local_84 [64];
  char local_44 [64];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)&local_1a0;
  local_1a0 = (char *)param_1;
  local_198 = param_2;
  local_19c = param_3;
  if (param_2 == (char *)0x0) {
    return;
  }
  local_190 = param_6 + -1;
  piVar7 = &BZ1Helper::m_BZ1Helper->teamInfo[(int)param_3].RealPlayer;
  local_194 = piVar7;
  local_188 = this;
  SetIndependence((int)this,0);
  piVar7[param_6 + 6] = (int)this;
  pcVar9 = (char *)((int)piVar7 + param_6 * 0x40 + 0x46d);
  iVar3 = GetODFString((int)this,"GameObjectClass","shellName",0x40,pcVar9,(char *)0x0);
  if (iVar3 == 0) {
    if ((param_6 == 1) || (param_6 == 5)) {
      pcVar8 = "Recycler";
    }
    else if ((param_6 == 2) || (param_6 == 6)) {
      pcVar8 = "Factory";
    }
    else if ((param_6 == 3) || (param_6 == 7)) {
      pcVar8 = "Armory";
    }
    else if ((param_6 == 4) || (param_6 == 8)) {
      pcVar8 = "Constructor";
    }
    else {
      if (param_6 != 9) goto LAB_4fc1ba2f;
      pcVar8 = "Satellite";
    }
    strcpy_s(pcVar9,0x40,pcVar8);
  }
LAB_4fc1ba2f:
  if (*(char *)(piVar7 + 0x5b) == '\0') {
    cVar1 = GetRace((int)this);
    *(char *)(piVar7 + 0x5b) = cVar1;
  }
  memset(local_184,0,0x40);
  pcVar9 = local_198;
  iVar3 = GetODFString(local_1a0,local_198,"GameObjectClass","ScrapHold",0x40,local_184,(char *)0x0)
  ;
  if ((iVar3 != 0) && (local_184[0] != '\0')) {
    *(undefined1 *)((int)piVar7 + param_6 + 0x113) = 1;
    bVar2 = IsAround(piVar7[param_6 + 0xf]);
    if ((!bVar2) && (0 < BZ1Helper::m_TurnCounter)) {
      bVar2 = DoesODFExist(local_184);
      if (!bVar2) {
        sprintf_s<64>(&local_184,"base%dshold",param_6);
      }
      iVar3 = BuildObject(local_184,(int)local_19c,&BZ1Helper::OffMapPos);
      piVar7[param_6 + 0xf] = iVar3;
    }
  }
  if (*(bool *)((int)piVar7 + 0x111) == false) {
    GetODFBool(local_1a0,pcVar9,"GameObjectClass","UseBZ1Limits",(bool *)((int)piVar7 + 0x111),false
              );
  }
  if (*(bool *)((int)piVar7 + 0x10f) == false) {
    GetODFBool(local_1a0,pcVar9,"GameObjectClass","UseBZ1Pilots",(bool *)((int)piVar7 + 0x10f),false
              );
  }
  if (*(bool *)((int)piVar7 + 0x112) == false) {
    GetODFBool(local_1a0,pcVar9,"GameObjectClass","NoPlayerPilot",(bool *)((int)piVar7 + 0x112),
               false);
  }
  if (BZ1Helper::m_BZ1Helper->m_BuildPools == false) {
    GetODFBool(local_1a0,pcVar9,"GameObjectClass","UseBZ2Pools",
               &BZ1Helper::m_BZ1Helper->m_BuildPools,false);
  }
  iVar3 = GetODFBool(local_1a0,pcVar9,"GameObjectClass","ShowPilotCosts",
                     (bool *)((int)piVar7 + param_6 + 0x9bf),false);
  if ((iVar3 != 0) && (*(char *)((int)piVar7 + param_6 + 0x9bf) != '\0')) {
    memset(local_144,0,0x40);
    if ((param_4 == -0x75f5e153) || (param_4 == -0x1c611e52)) {
      pcVar9 = "FactoryClass";
    }
    else if (param_4 == 0x77f02e21) {
      pcVar9 = "ConstructionRigClass";
    }
    else if (param_4 == 0x2418efcf) {
      pcVar9 = "ConstructionRigTClass";
    }
    else {
      if (param_4 != 0x63ae241a) goto LAB_4fc1bcdf;
      pcVar9 = "ArmoryClass";
    }
    strcpy_s(local_144,0x40,pcVar9);
    pcVar8 = local_198;
    pcVar9 = local_1a0;
    iVar3 = 0;
    piVar6 = piVar7 + local_190 * 10 + 0x216;
    do {
      memset(local_104,0,0x40);
      iVar3 = iVar3 + 1;
      sprintf_s<64>(&local_104,"buildItem%d",iVar3);
      memset(local_84,0,0x40);
      GetODFString(pcVar9,pcVar8,local_144,local_104,0x40,local_84,(char *)0x0);
      iVar4 = GetPilotCost(local_84);
      piVar6[-0x5a] = iVar4;
      iVar4 = GetScrapCost(local_84);
      *piVar6 = iVar4;
      piVar6 = piVar6 + 1;
      piVar7 = local_194;
      this = local_188;
    } while (iVar3 < 10);
  }
LAB_4fc1bcdf:
  uVar5 = memset(local_44,0,0x40);
  piVar7[param_6 + 0x272] = -1;
  local_194 = (int *)(uVar5 & 0xffffff00);
  local_18c = 0;
  local_19c = (char *)((uint)local_19c & 0xffffff00);
  GetODFInt(local_1a0,local_198,"GameObjectClass","animCount",&local_18c,0);
  local_190 = 1;
  if (1 < local_18c + 1) {
    do {
      memset(local_104,0,0x40);
      sprintf_s<64>(&local_104,"animName%d",local_190);
      iVar3 = GetODFString(local_1a0,local_198,"GameObjectClass",local_104,0x40,local_44,(char *)0x0
                          );
      if (iVar3 == 0) break;
      iVar3 = _stricmp(local_44,"build");
      local_194 = (int *)((uint)local_194 & 0xff);
      if (iVar3 == 0) {
        local_194 = (int *)1;
      }
      iVar3 = _stricmp(local_44,"BZCLoop");
      local_19c = (char *)((uint)local_19c & 0xff);
      if (iVar3 == 0) {
        local_19c = (char *)1;
      }
      if (((char)local_194 != '\0') && ((char)local_19c != '\0')) {
        piVar7[param_6 + 0x272] = 0;
        break;
      }
      local_190 = local_190 + 1;
    } while (local_190 < local_18c + 1);
  }
  memset(local_c4,0,0x40);
  GetODFString(local_1a0,local_198,"GameObjectClass","UndeployClass",0x40,local_c4,(char *)0x0);
  if ((local_c4[0] != '\0') && (bVar2 = DoesODFExist(local_c4), bVar2)) {
    PetWatchdogThread();
    PreloadODF(local_c4);
  }
  if (param_5 == 0) {
    if (3 < param_6) {
      return;
    }
    if (param_4 == -0x75f5e153) {
LAB_4fc1bed6:
      piVar7[3] = (int)this;
      cVar1 = GetRace((int)this);
      *(char *)(piVar7 + 0x5b) = cVar1;
      return;
    }
    if (param_4 == -0x1c611e52) {
LAB_4fc1bed1:
      piVar7[4] = (int)this;
      return;
    }
    if (param_4 == 0x2418efcf) goto LAB_4fc1bec7;
    if (param_4 == 0x63ae241a) goto LAB_4fc1becc;
    bVar2 = param_4 == 0x77f02e21;
  }
  else {
    if (param_5 == -0x39c7afdc) {
LAB_4fc1becc:
      piVar7[5] = (int)this;
      return;
    }
    if (param_5 == -0x221bc770) goto LAB_4fc1bed6;
    if (param_5 == -0x1e7b223d) goto LAB_4fc1bed1;
    bVar2 = param_5 == 0x6b5974e3;
  }
  if (!bVar2) {
    return;
  }
LAB_4fc1bec7:
  piVar7[6] = (int)this;
  return;
}


// ---------------------------------------------------------------------
// ProductionClassHelper::Execute  @ 4fc1bf02  lines 240-758

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall ProductionClassHelper::Execute(ProductionClassHelper *this,BZ1Helper *param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  char *pcVar6;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  uint uVar7;
  uint3 extraout_var_01;
  uint3 extraout_var_02;
  char cVar8;
  DLLBase *pDVar9;
  TeamInfo *pTVar10;
  char (*pacVar11) [64];
  uint uVar12;
  char *unaff_EDI;
  int *piVar13;
  float fVar14;
  undefined1 auStack_248 [6];
  bool local_242;
  char local_241;
  uint local_240;
  char (*local_23c) [64];
  char cStack_235;
  int local_234;
  uint local_230;
  int local_22c;
  BZ1Helper *local_228;
  int local_224;
  int local_220;
  uint local_21c;
  int local_218;
  Vector local_214;
  char acStack_208 [64];
  char local_1c8 [64];
  char acStack_188 [64];
  char local_148 [64];
  char acStack_108 [64];
  char acStack_c8 [64];
  char acStack_88 [64];
  char acStack_48 [68];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)auStack_248;
  uVar7 = CONCAT31((int3)(local_4 >> 8),BZ1Helper::Logging);
  local_228 = param_1;
  local_242 = BZ1Helper::Logging;
  local_240 = 0;
  do {
    local_230 = uVar7 & 0xffffff00;
    local_241 = '\0';
    local_234 = 0;
    pDVar9 = &local_228->super_DLLBase + local_240 * 0x285;
    local_22c = 0x1c;
    local_224 = -0x90 - (int)pDVar9;
    local_220 = -0x6c - (int)pDVar9;
    pacVar11 = (char (*) [64])((int)(pDVar9 + 0x14f) + 1);
    piVar13 = (int *)(pDVar9 + 0x2b);
    do {
      iVar5 = local_234;
      local_23c = pacVar11;
      bVar1 = IsAround(*piVar13);
      if ((bVar1) && (local_21c = GetTeamNum(*piVar13), local_21c != local_240)) {
        pTVar10 = local_228->teamInfo + local_21c;
        if (*piVar13 == *(int *)(pDVar9 + 0x27)) {
          pTVar10->Recycler = *(int *)(pDVar9 + 0x27);
          pDVar9[0x27] = (DLLBase)0x0;
        }
        else if (*piVar13 == *(int *)(pDVar9 + 0x28)) {
          pTVar10->Factory = *(int *)(pDVar9 + 0x28);
          pDVar9[0x28] = (DLLBase)0x0;
        }
        else if (*piVar13 == *(int *)(pDVar9 + 0x29)) {
          pTVar10->Armory = *(int *)(pDVar9 + 0x29);
          pDVar9[0x29] = (DLLBase)0x0;
        }
        else if (*piVar13 == *(int *)(pDVar9 + 0x2a)) {
          pTVar10->Constructor = *(int *)(pDVar9 + 0x2a);
          pDVar9[0x2a] = (DLLBase)0x0;
        }
        *(int *)((int)pTVar10->BaseSlot + local_22c + -0x1c) = *piVar13;
        *piVar13 = 0;
        if (pTVar10->m_UsePilots == false) {
          pTVar10->m_UsePilots = *(bool *)((int)(pDVar9 + 0x67) + 3);
        }
        if (pTVar10->m_UseLimits == false) {
          pTVar10->m_UseLimits = *(bool *)((int)(pDVar9 + 0x68) + 1);
        }
        strcpy_s(*local_23c + (int)pTVar10->BaseSlot + local_224 + -0x1c,0x40,*local_23c);
        memset(local_23c,0,0x40);
        bVar1 = IsAround(piVar13[9]);
        pacVar11 = local_23c;
        if (bVar1) {
          memset(local_148,0,0x40);
          GetODFName(piVar13[9],local_148);
          GetPosition(piVar13[9],&local_214);
          RemoveObject(piVar13[9]);
          iVar5 = local_220;
          local_218 = *(int *)((int)piVar13 + (int)pTVar10->BaseSlot + local_220 + -0x1c);
          iVar2 = BuildObject(local_148,local_21c,&local_214);
          iVar3 = local_218;
          *(int *)((int)piVar13 + (int)pTVar10->BaseSlot + iVar5 + -0x1c) = iVar2;
          bVar1 = IsAround(local_218);
          if (bVar1) {
            RemoveObject(iVar3);
          }
          piVar13[9] = 0;
          pacVar11 = local_23c;
          iVar5 = local_234;
        }
      }
      bVar1 = IsAround(*piVar13);
      if (bVar1) {
        if ((*(bool *)((int)(pDVar9 + 0x69) + iVar5) != false) &&
           (bVar1 = IsAround(piVar13[9]), !bVar1)) {
          memset(local_1c8,0,0x40);
          GetODFString(*piVar13,"GameObjectClass","ScrapHold",0x40,local_1c8,(char *)0x0);
          if ((local_1c8[0] != '\0') && (bVar1 = DoesODFExist(local_1c8), !bVar1)) {
            sprintf_s<64>(&local_1c8,"base%dshold",iVar5);
          }
          iVar3 = BuildObject(local_1c8,local_240,&BZ1Helper::OffMapPos);
          piVar13[9] = iVar3;
        }
        bVar1 = IsBuilding(*piVar13);
        if ((bVar1) && (bVar1 = IsBusy(*piVar13), bVar1)) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
        cStack_235 = '\0';
        if (bVar1) {
          pcVar4 = GetBuildClass(*piVar13);
          if ((pcVar4 != (char *)0x0) && (iVar5 = _strnicmp(pcVar4,"BZCundep",8), iVar5 == 0)) {
            if (local_242 != false) {
              FormatConsoleMessage("Team Slot: %d building Undeploy: %s",local_234 + 1,pcVar4);
            }
            UndeployHelper::AddUndeployObject
                      (UndeployHelper::m_UndeployHelper,local_240,(int)pcVar4,unaff_EDI);
          }
          iVar3 = 0;
          while (pcVar6 = GetQueuedItem(*(int *)(pDVar9 + 0x29),iVar3), pcVar6 != (char *)0x0) {
            iVar3 = iVar3 + 1;
          }
          if ((*piVar13 == *(int *)(pDVar9 + 0x29)) &&
             (iVar5 = _stricmp(pcVar4,(char *)((int)(pDVar9 + 0x7f) + 1)), iVar5 != 0)) {
            strcpy_s((char *)((int)(pDVar9 + 0x7f) + 1),0x40,pcVar4);
          }
          iVar2 = piVar13[0x33];
          iVar5 = local_234;
          cVar8 = cStack_235;
          if (iVar3 != iVar2) {
            if (local_242 != false) {
              FormatLogMessage("BaseSlot Qued Item: BuildClass: \'%s\', Count is: %d",pcVar4,iVar3);
              iVar2 = piVar13[0x33];
            }
            piVar13[0x33] = iVar3;
            iVar5 = local_234;
            cVar8 = iVar3 < iVar2;
            if (*piVar13 == *(int *)(pDVar9 + 0x29)) {
              local_241 = iVar3 == 1;
              local_230 = local_230 & 0xffffff00;
            }
          }
        }
        else {
          iVar3 = piVar13[0x33];
          cVar8 = '\0';
          if (0 < iVar3) {
            if (local_242 != false) {
              FormatLogMessage("BaseSlot Done, ArmoryBuildClass: \'%s\', BaseSlotCount is: %d",
                               (char *)((int)(pDVar9 + 0x7f) + 1),iVar3);
              iVar3 = piVar13[0x33];
            }
            piVar13[0x33] = iVar3 + -1;
            cVar8 = '\x01';
            local_230 = local_230 & 0xff;
            if (*piVar13 == *(int *)(pDVar9 + 0x29)) {
              local_230 = 1;
            }
          }
        }
        iVar3 = piVar13[0x26c];
        bVar1 = false;
        if (iVar3 == 0) {
          if (cVar8 != '\0') {
            fVar14 = SetAnimation(*piVar13,"build",1);
            piVar13[0x275] = (int)fVar14;
            StartAnimation(*piVar13);
            iVar3 = 1;
            piVar13[0x26c] = 1;
          }
          bVar1 = iVar3 == 0;
        }
        pacVar11 = local_23c;
        if ((!bVar1 && -1 < iVar3) &&
           (fVar14 = GetAnimationFrame(*piVar13,"build"), pacVar11 = local_23c,
           (float)piVar13[0x275] - 1.0 <= fVar14)) {
          fVar14 = SetAnimation(*piVar13,"BZCloop",0);
          piVar13[0x275] = (int)fVar14;
          StartAnimation(*piVar13);
          piVar13[0x26c] = 0;
          pacVar11 = local_23c;
        }
      }
      else {
        iVar3 = *piVar13;
        if (iVar3 == *(int *)(pDVar9 + 0x27)) {
          pDVar9[0x27] = (DLLBase)0x0;
        }
        else if (iVar3 == *(int *)(pDVar9 + 0x28)) {
          pDVar9[0x28] = (DLLBase)0x0;
        }
        else if (iVar3 == *(int *)(pDVar9 + 0x29)) {
          pDVar9[0x29] = (DLLBase)0x0;
        }
        else if (iVar3 == *(int *)(pDVar9 + 0x2a)) {
          pDVar9[0x2a] = (DLLBase)0x0;
        }
        *piVar13 = 0;
        bVar1 = IsAround(piVar13[9]);
        if (bVar1) {
          RemoveObject(piVar13[9]);
          piVar13[9] = 0;
        }
      }
      local_234 = iVar5 + 1;
      local_22c = local_22c + 4;
      pacVar11 = pacVar11 + 1;
      piVar13 = piVar13 + 1;
    } while (local_22c < 0x40);
    local_23c = pacVar11;
    bVar1 = IsBuilding(*(int *)(pDVar9 + 0x29));
    uVar7 = CONCAT31(extraout_var,bVar1);
    if (bVar1) {
      uVar7 = local_230;
      uVar12 = local_240;
      if ((char)local_230 != '\0') {
        memset(TempGetClasslabelString,0,0x40);
        if ((char *)((int)(pDVar9 + 0x7f) + 1) == (char *)0x0) {
          pcVar4 = TempGetClasslabelString;
        }
        else {
          pcVar4 = GetClasslabelString((char *)((int)(pDVar9 + 0x7f) + 1));
        }
        iVar3 = 0;
        iVar5 = _stricmp(pcVar4,"ammopack");
        if (iVar5 == 0) {
          iVar3 = -0x599d55a0;
        }
        else {
          iVar5 = _stricmp(pcVar4,"repairkit");
          if ((iVar5 == 0) || (iVar5 = _stricmp(pcVar4,"servicepod"), iVar5 == 0)) {
            iVar3 = 0x4b970310;
          }
          else {
            iVar5 = _stricmp(pcVar4,"wpnpower");
            if (iVar5 == 0) {
              iVar3 = 0x16164674;
            }
            else {
              iVar5 = _stricmp(pcVar4,"camerapod");
              if (iVar5 == 0) {
                iVar3 = -0x728376ee;
              }
              else {
                iVar5 = _stricmp(pcVar4,"daywrecker");
                if (iVar5 == 0) {
                  iVar3 = -0x6675686d;
                }
              }
            }
          }
        }
        memset(acStack_208,0,0x40);
        memset(acStack_c8,0,0x40);
        memset(acStack_108,0,0x40);
        GetAndOpenODFNames(*(int *)(pDVar9 + 0x29),acStack_c8,acStack_108,(char *)0x0);
        if (iVar3 == -0x728376ee) {
          pcVar4 = "navSound";
        }
        else if (iVar3 == -0x6675686d) {
          pcVar4 = "bombSound";
        }
        else if (iVar3 == -0x599d55a0) {
          pcVar4 = "ammoSound";
        }
        else if (iVar3 == 0x16164674) {
          pcVar4 = "weaponSound";
        }
        else {
          pcVar4 = "rescueMsg";
          if (iVar3 == 0x4b970310) {
            pcVar4 = "repaSound";
          }
        }
        iVar5 = GetODFString(acStack_c8,acStack_108,"ArmoryClass",pcVar4,0x40,acStack_208,
                             (char *)0x0);
        uVar7 = CONCAT31((int3)((uint)iVar5 >> 8),acStack_208[0]);
        uVar12 = local_240;
        if (acStack_208[0] != '\0') {
          if (local_242 != false) {
            FormatLogMessage("Sound Is: \'%s\'",acStack_208);
            uVar7 = CONCAT31(extraout_var_00,acStack_208[0]);
          }
          uVar12 = local_240;
          if (((char)uVar7 != '\0') &&
             (uVar7 = GetLocalPlayerTeamNumber(), uVar12 = local_240, uVar7 == local_240)) {
            bVar1 = DoesFileExist(acStack_208);
            if (bVar1) {
              uVar7 = AudioMessage(acStack_208,false);
            }
            else {
              pcVar4 = GetODFName(*(int *)(pDVar9 + 0x29));
              FormatLogMessage("ERROR: Sound file: \'%s\' doesn\'t exist! Fix ODF: \'%s\'",
                               acStack_208,pcVar4);
              uVar7 = (uint)extraout_var_01 << 8;
            }
          }
        }
      }
      uVar7 = CONCAT31((int3)(uVar7 >> 8),local_241);
      if (local_241 != '\0') {
        memset(acStack_188,0,0x40);
        memset(acStack_48,0,0x40);
        memset(acStack_88,0,0x40);
        GetAndOpenODFNames(*(int *)(pDVar9 + 0x29),acStack_48,acStack_88,(char *)0x0);
        uVar7 = GetODFString(acStack_48,acStack_88,"ArmoryClass","reloadMsg",0x40,acStack_188,
                             (char *)0x0);
        if ((acStack_188[0] != '\0') && (uVar7 = GetLocalPlayerTeamNumber(), uVar7 == uVar12)) {
          bVar1 = DoesFileExist(acStack_188);
          if (bVar1) {
            uVar7 = AudioMessage(acStack_188,false);
          }
          else {
            pcVar4 = GetODFName(*(int *)(pDVar9 + 0x29));
            FormatLogMessage("ERROR: Sound file: \'%s\' doesn\'t exist! Fix ODF: \'%s\'",acStack_188
                             ,pcVar4);
            uVar7 = (uint)extraout_var_02 << 8;
          }
        }
      }
    }
    local_240 = local_240 + 1;
  } while ((int)local_240 < 0x10);
  return;
}


