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
  int *piVar4;
  int iVar5;
  char *pcVar6;
  undefined1 unaff_BP;
  bool *unaff_ESI;
  uint uVar7;
  char (*pacVar8) [64];
  ProductionClassHelper *pPVar9;
  char *pcVar10;
  int local_1a0;
  char *local_19c;
  char *local_198;
  uint local_194;
  int local_190;
  int local_18c;
  ProductionClassHelper *local_188;
  char local_184 [64];
  char local_144 [64];
  char local_104 [64];
  char local_c4 [64];
  char local_84 [64];
  int local_44 [16];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)&local_1a0;
  local_1a0 = param_1;
  local_198 = param_2;
  local_19c = param_3;
  if (param_2 == (char *)0x0) {
    return;
  }
  pcVar10 = (char *)0x0;
  iVar3 = param_6 + -1;
  uVar7 = (int)BZ1Helper::m_BZ1Helper->teamInfo + (int)param_3 * 0xa14;
  pPVar9 = this;
  local_194 = uVar7;
  local_190 = iVar3;
  local_188 = this;
  SetIndependence((int)this,0);
  *(ProductionClassHelper **)(uVar7 + 0x1c + iVar3 * 4) = this;
  pcVar6 = (char *)(uVar7 + 0x4ad + iVar3 * 0x40);
  iVar3 = GetODFString(0x4fc5eb08,(char *)0x40,pcVar6,0,(char *)pPVar9,pcVar10);
  if (iVar3 == 0) {
    if ((param_6 == 1) || (param_6 == 5)) {
      pcVar10 = "Recycler";
    }
    else if ((param_6 == 2) || (param_6 == 6)) {
      pcVar10 = "Factory";
    }
    else if ((param_6 == 3) || (param_6 == 7)) {
      pcVar10 = "Armory";
    }
    else if ((param_6 == 4) || (param_6 == 8)) {
      pcVar10 = "Constructor";
    }
    else {
      if (param_6 != 9) goto LAB_4fc1ba2f;
      pcVar10 = "Satellite";
    }
    strcpy_s(pcVar6,0x40,pcVar10);
  }
LAB_4fc1ba2f:
  if (*(char *)(uVar7 + 0x16c) == '\0') {
    cVar1 = GetRace((int)this);
    *(char *)(uVar7 + 0x16c) = cVar1;
  }
  pcVar6 = local_184;
  pcVar10 = (char *)0x0;
  memset(pcVar6,0,0x40);
  iVar3 = GetODFString("GameObjectClass","ScrapHold",(char *)0x40,local_184,0,pcVar6,pcVar10);
  if ((iVar3 != 0) && (local_184[0] != '\0')) {
    *(undefined1 *)(uVar7 + 0x113 + param_6) = 1;
    bVar2 = IsAround(*(int *)(uVar7 + 0x3c + param_6 * 4));
    if ((!bVar2) && (0 < BZ1Helper::m_TurnCounter)) {
      bVar2 = DoesODFExist(local_184);
      if (!bVar2) {
        sprintf_s<64>(&local_184,"base%dshold");
      }
      iVar3 = BuildObject(local_184,(int)local_19c,&BZ1Helper::OffMapPos);
      *(int *)(uVar7 + 0x3c + param_6 * 4) = iVar3;
    }
  }
  if (*(char *)(uVar7 + 0x111) == '\0') {
    GetODFBool("GameObjectClass","UseBZ1Limits",(char *)(uVar7 + 0x111),(char *)0x0,unaff_ESI,
               (bool)unaff_BP);
  }
  if (*(char *)(uVar7 + 0x10f) == '\0') {
    GetODFBool("GameObjectClass","UseBZ1Pilots",(char *)(uVar7 + 0x10f),(char *)0x0,unaff_ESI,
               (bool)unaff_BP);
  }
  if (*(char *)(uVar7 + 0x112) == '\0') {
    GetODFBool("GameObjectClass","NoPlayerPilot",(char *)(uVar7 + 0x112),(char *)0x0,unaff_ESI,
               (bool)unaff_BP);
  }
  pcVar6 = BZ1Helper::m_BZ1Helper[1].teamInfo[0].PilotWeapon[4] + 0x1d;
  if (*pcVar6 == '\0') {
    GetODFBool("GameObjectClass","UseBZ2Pools",pcVar6,(char *)0x0,unaff_ESI,(bool)unaff_BP);
  }
  iVar3 = GetODFBool("GameObjectClass","ShowPilotCosts",(char *)(param_6 + 0x9bf + uVar7),
                     (char *)0x0,unaff_ESI,(bool)unaff_BP);
  if ((iVar3 != 0) && (*(char *)(uVar7 + 0x9bf + param_6) != '\0')) {
    memset(local_144,0,0x40);
    if ((param_4 == -0x75f5e153) || (param_4 == -0x1c611e52)) {
      pcVar6 = "FactoryClass";
    }
    else if (param_4 == 0x77f02e21) {
      pcVar6 = "ConstructionRigClass";
    }
    else if (param_4 == 0x2418efcf) {
      pcVar6 = "ConstructionRigTClass";
    }
    else {
      if (param_4 != 0x63ae241a) goto LAB_4fc1bcdf;
      pcVar6 = "ArmoryClass";
    }
    strcpy_s(local_144,0x40,pcVar6);
    iVar3 = 0;
    piVar4 = (int *)(local_190 * 0x28 + 0x858 + uVar7);
    do {
      memset(local_104,0,0x40);
      iVar3 = iVar3 + 1;
      sprintf_s<64>(&local_104,"buildItem%d");
      pcVar6 = local_84;
      pcVar10 = (char *)0x0;
      memset(pcVar6,0,0x40);
      GetODFString(local_144,local_104,(char *)0x40,local_84,0,pcVar6,pcVar10);
      iVar5 = GetPilotCost(unaff_ESI);
      piVar4[-0x5a] = iVar5;
      iVar5 = GetScrapCost(unaff_ESI);
      *piVar4 = iVar5;
      piVar4 = piVar4 + 1;
      uVar7 = local_194;
      this = local_188;
    } while (iVar3 < 10);
  }
LAB_4fc1bcdf:
  piVar4 = local_44;
  iVar3 = 0;
  local_194 = memset(piVar4,0,0x40);
  *(undefined4 *)(uVar7 + 0x9c8 + param_6 * 4) = 0xffffffff;
  local_194 = local_194 & 0xffffff00;
  local_18c = 0;
  local_19c = (char *)((uint)local_19c & 0xffffff00);
  GetODFInt("GameObjectClass","animCount",(char *)&local_18c,(char *)0x0,piVar4,iVar3);
  local_190 = 1;
  if (1 < local_18c + 1) {
    do {
      memset(local_104,0,0x40);
      pacVar8 = &local_104;
      pcVar6 = "animName%d";
      sprintf_s<64>(pacVar8,"animName%d");
      iVar3 = GetODFString("GameObjectClass",local_104,(char *)0x40,(char *)local_44,0,*pacVar8,
                           pcVar6);
      if (iVar3 == 0) break;
      iVar3 = _stricmp((char *)local_44,"build");
      local_194 = local_194 & 0xff;
      if (iVar3 == 0) {
        local_194 = 1;
      }
      iVar3 = _stricmp((char *)local_44,"BZCLoop");
      local_19c = (char *)((uint)local_19c & 0xff);
      if (iVar3 == 0) {
        local_19c = (char *)1;
      }
      if (((char)local_194 != '\0') && ((char)local_19c != '\0')) {
        *(undefined4 *)(uVar7 + 0x9c8 + param_6 * 4) = 0;
        break;
      }
      local_190 = local_190 + 1;
    } while (local_190 < local_18c + 1);
  }
  pcVar6 = local_c4;
  pcVar10 = (char *)0x0;
  memset(pcVar6,0,0x40);
  GetODFString("GameObjectClass","UndeployClass",(char *)0x40,local_c4,0,pcVar6,pcVar10);
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
      *(ProductionClassHelper **)(uVar7 + 0xc) = this;
      cVar1 = GetRace((int)this);
      *(char *)(uVar7 + 0x16c) = cVar1;
      return;
    }
    if (param_4 == -0x1c611e52) {
LAB_4fc1bed1:
      *(ProductionClassHelper **)(uVar7 + 0x10) = this;
      return;
    }
    if (param_4 == 0x2418efcf) goto LAB_4fc1bec7;
    if (param_4 == 0x63ae241a) goto LAB_4fc1becc;
    bVar2 = param_4 == 0x77f02e21;
  }
  else {
    if (param_5 == -0x39c7afdc) {
LAB_4fc1becc:
      *(ProductionClassHelper **)(uVar7 + 0x14) = this;
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
  *(ProductionClassHelper **)(uVar7 + 0x18) = this;
  return;
}


// ---------------------------------------------------------------------
// ProductionClassHelper::Execute  @ 4fc1bf02  lines 240-758


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall ProductionClassHelper::Execute(ProductionClassHelper *this,BZ1Helper *param_1)

{
  TeamInfo *pTVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  int iVar7;
  char *pcVar8;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  uint3 extraout_var_01;
  uint3 extraout_var_02;
  char cVar9;
  int *piVar10;
  uint uVar11;
  char *unaff_ESI;
  char *unaff_EDI;
  int *piVar12;
  float fVar13;
  undefined1 auStack_248 [6];
  bool local_242;
  char local_241;
  uint local_240;
  char *local_23c;
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
  undefined1 auStack_108 [64];
  undefined1 auStack_c8 [64];
  char acStack_88 [64];
  undefined1 auStack_48 [68];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)auStack_248;
  uVar3 = CONCAT31((int3)(local_4 >> 8),BZ1Helper::Logging);
  local_228 = param_1;
  local_242 = BZ1Helper::Logging;
  local_240 = 0;
  do {
    local_230 = uVar3 & 0xffffff00;
    local_241 = '\0';
    local_234 = 0;
    piVar10 = &local_228->_padding_ + local_240 * 0x285;
    local_22c = 0x1c;
    local_224 = -0x90 - (int)piVar10;
    local_220 = -0x6c - (int)piVar10;
    pcVar6 = (char *)((int)piVar10 + 0x53d);
    piVar12 = piVar10 + 0x2b;
    do {
      iVar7 = local_234;
      local_23c = pcVar6;
      bVar2 = IsAround(*piVar12);
      if ((bVar2) && (uVar3 = GetTeamNum(*piVar12), local_21c = uVar3, uVar3 != local_240)) {
        pTVar1 = local_228->teamInfo;
        if (*piVar12 == piVar10[0x27]) {
          *(int *)((int)pTVar1 + uVar3 * 0xa14 + 0xc) = piVar10[0x27];
          piVar10[0x27] = 0;
        }
        else if (*piVar12 == piVar10[0x28]) {
          *(int *)((int)pTVar1 + uVar3 * 0xa14 + 0x10) = piVar10[0x28];
          piVar10[0x28] = 0;
        }
        else if (*piVar12 == piVar10[0x29]) {
          *(int *)((int)pTVar1 + uVar3 * 0xa14 + 0x14) = piVar10[0x29];
          piVar10[0x29] = 0;
        }
        else if (*piVar12 == piVar10[0x2a]) {
          *(int *)((int)pTVar1 + uVar3 * 0xa14 + 0x18) = piVar10[0x2a];
          piVar10[0x2a] = 0;
        }
        *(int *)((int)pTVar1 + local_22c + uVar3 * 0xa14) = *piVar12;
        *piVar12 = 0;
        if (*(char *)((int)pTVar1 + uVar3 * 0xa14 + 0x10f) == '\0') {
          *(undefined1 *)((int)pTVar1 + uVar3 * 0xa14 + 0x10f) =
               *(undefined1 *)((int)piVar10 + 0x19f);
        }
        if (*(char *)((int)pTVar1 + uVar3 * 0xa14 + 0x111) == '\0') {
          *(undefined1 *)((int)pTVar1 + uVar3 * 0xa14 + 0x111) =
               *(undefined1 *)((int)piVar10 + 0x1a1);
        }
        strcpy_s(local_23c + (int)pTVar1 + local_224 + uVar3 * 0xa14,0x40,local_23c);
        memset(local_23c,0,0x40);
        bVar2 = IsAround(piVar12[9]);
        pcVar6 = local_23c;
        if (bVar2) {
          memset(local_148,0,0x40);
          GetODFName((int)unaff_EDI,unaff_ESI);
          GetPosition(piVar12[9],&local_214);
          RemoveObject(piVar12[9]);
          iVar7 = local_220;
          local_218 = *(int *)((int)piVar12 + (int)pTVar1 + local_220 + uVar3 * 0xa14);
          iVar4 = BuildObject(local_148,local_21c,&local_214);
          iVar5 = local_218;
          *(int *)((int)piVar12 + (int)pTVar1 + iVar7 + uVar3 * 0xa14) = iVar4;
          bVar2 = IsAround(local_218);
          if (bVar2) {
            RemoveObject(iVar5);
          }
          piVar12[9] = 0;
          pcVar6 = local_23c;
          iVar7 = local_234;
        }
      }
      bVar2 = IsAround(*piVar12);
      if (bVar2) {
        if ((*(char *)((int)piVar10 + iVar7 + 0x1a4) != '\0') &&
           (bVar2 = IsAround(piVar12[9]), !bVar2)) {
          memset(local_1c8,0,0x40);
          GetODFString(0x4fc5eb48,(char *)0x40,local_1c8,0,unaff_EDI,unaff_ESI);
          if ((local_1c8[0] != '\0') && (bVar2 = DoesODFExist(local_1c8), !bVar2)) {
            sprintf_s<64>(&local_1c8,"base%dshold");
          }
          iVar5 = BuildObject(local_1c8,local_240,&BZ1Helper::OffMapPos);
          piVar12[9] = iVar5;
        }
        bVar2 = IsBuilding(*piVar12);
        if ((bVar2) && (bVar2 = IsBusy(*piVar12), bVar2)) {
          bVar2 = true;
        }
        else {
          bVar2 = false;
        }
        cStack_235 = '\0';
        if (bVar2) {
          pcVar6 = GetBuildClass(*piVar12);
          if ((pcVar6 != (char *)0x0) && (iVar7 = _strnicmp(pcVar6,"BZCundep",8), iVar7 == 0)) {
            if (local_242 != false) {
              FormatConsoleMessage("Team Slot: %d building Undeploy: %s");
            }
            UndeployHelper::AddUndeployObject
                      (UndeployHelper::m_UndeployHelper,local_240,(int)pcVar6,unaff_EDI);
          }
          iVar5 = 0;
          while (pcVar8 = GetQueuedItem(piVar10[0x29],iVar5), pcVar8 != (char *)0x0) {
            iVar5 = iVar5 + 1;
          }
          if ((*piVar12 == piVar10[0x29]) &&
             (iVar7 = _stricmp(pcVar6,(char *)((int)piVar10 + 0x1fd)), iVar7 != 0)) {
            strcpy_s((char *)((int)piVar10 + 0x1fd),0x40,pcVar6);
          }
          iVar4 = piVar12[0x33];
          iVar7 = local_234;
          cVar9 = cStack_235;
          if (iVar5 != iVar4) {
            if (local_242 != false) {
              FormatLogMessage("BaseSlot Qued Item: BuildClass: \'%s\', Count is: %d");
              iVar4 = piVar12[0x33];
            }
            piVar12[0x33] = iVar5;
            iVar7 = local_234;
            cVar9 = iVar5 < iVar4;
            if (*piVar12 == piVar10[0x29]) {
              local_241 = iVar5 == 1;
              local_230 = local_230 & 0xffffff00;
            }
          }
        }
        else {
          iVar5 = piVar12[0x33];
          cVar9 = '\0';
          if (0 < iVar5) {
            if (local_242 != false) {
              FormatLogMessage("BaseSlot Done, ArmoryBuildClass: \'%s\', BaseSlotCount is: %d");
              iVar5 = piVar12[0x33];
            }
            piVar12[0x33] = iVar5 + -1;
            cVar9 = '\x01';
            local_230 = local_230 & 0xff;
            if (*piVar12 == piVar10[0x29]) {
              local_230 = 1;
            }
          }
        }
        iVar5 = piVar12[0x26c];
        bVar2 = false;
        if (iVar5 == 0) {
          if (cVar9 != '\0') {
            fVar13 = SetAnimation(*piVar12,"build",1);
            piVar12[0x275] = (int)fVar13;
            StartAnimation(*piVar12);
            iVar5 = 1;
            piVar12[0x26c] = 1;
          }
          bVar2 = iVar5 == 0;
        }
        pcVar6 = local_23c;
        if ((!bVar2 && -1 < iVar5) &&
           (fVar13 = GetAnimationFrame(*piVar12,"build"), pcVar6 = local_23c,
           (float)piVar12[0x275] - 1.0 <= fVar13)) {
          fVar13 = SetAnimation(*piVar12,"BZCloop",0);
          piVar12[0x275] = (int)fVar13;
          StartAnimation(*piVar12);
          piVar12[0x26c] = 0;
          pcVar6 = local_23c;
        }
      }
      else {
        iVar5 = *piVar12;
        if (iVar5 == piVar10[0x27]) {
          piVar10[0x27] = 0;
        }
        else if (iVar5 == piVar10[0x28]) {
          piVar10[0x28] = 0;
        }
        else if (iVar5 == piVar10[0x29]) {
          piVar10[0x29] = 0;
        }
        else if (iVar5 == piVar10[0x2a]) {
          piVar10[0x2a] = 0;
        }
        *piVar12 = 0;
        bVar2 = IsAround(piVar12[9]);
        if (bVar2) {
          RemoveObject(piVar12[9]);
          piVar12[9] = 0;
        }
      }
      local_234 = iVar7 + 1;
      local_22c = local_22c + 4;
      pcVar6 = pcVar6 + 0x40;
      piVar12 = piVar12 + 1;
    } while (local_22c < 0x40);
    local_23c = pcVar6;
    bVar2 = IsBuilding(piVar10[0x29]);
    uVar3 = CONCAT31(extraout_var,bVar2);
    if (bVar2) {
      uVar3 = local_230;
      uVar11 = local_240;
      if ((char)local_230 != '\0') {
        memset(TempGetClasslabelString,0,0x40);
        if (piVar10 == (int *)0xfffffe03) {
          pcVar6 = TempGetClasslabelString;
        }
        else {
          pcVar6 = GetClasslabelString(unaff_EDI);
        }
        iVar5 = 0;
        iVar7 = _stricmp(pcVar6,"ammopack");
        if (iVar7 == 0) {
          iVar5 = -0x599d55a0;
        }
        else {
          iVar7 = _stricmp(pcVar6,"repairkit");
          if ((iVar7 == 0) || (iVar7 = _stricmp(pcVar6,"servicepod"), iVar7 == 0)) {
            iVar5 = 0x4b970310;
          }
          else {
            iVar7 = _stricmp(pcVar6,"wpnpower");
            if (iVar7 == 0) {
              iVar5 = 0x16164674;
            }
            else {
              iVar7 = _stricmp(pcVar6,"camerapod");
              if (iVar7 == 0) {
                iVar5 = -0x728376ee;
              }
              else {
                iVar7 = _stricmp(pcVar6,"daywrecker");
                if (iVar7 == 0) {
                  iVar5 = -0x6675686d;
                }
              }
            }
          }
        }
        memset(acStack_208,0,0x40);
        memset(auStack_c8,0,0x40);
        memset(auStack_108,0,0x40);
        GetAndOpenODFNames((int)auStack_108,(char *)0x0,unaff_EDI,unaff_ESI);
        if (iVar5 == -0x728376ee) {
          pcVar6 = "navSound";
        }
        else if (iVar5 == -0x6675686d) {
          pcVar6 = "bombSound";
        }
        else if (iVar5 == -0x599d55a0) {
          pcVar6 = "ammoSound";
        }
        else if (iVar5 == 0x16164674) {
          pcVar6 = "weaponSound";
        }
        else {
          pcVar6 = "rescueMsg";
          if (iVar5 == 0x4b970310) {
            pcVar6 = "repaSound";
          }
        }
        iVar7 = GetODFString("ArmoryClass",pcVar6,(char *)0x40,acStack_208,0,unaff_EDI,unaff_ESI);
        uVar3 = CONCAT31((int3)((uint)iVar7 >> 8),acStack_208[0]);
        uVar11 = local_240;
        if (acStack_208[0] != '\0') {
          if (local_242 != false) {
            FormatLogMessage("Sound Is: \'%s\'");
            uVar3 = CONCAT31(extraout_var_00,acStack_208[0]);
          }
          uVar11 = local_240;
          if (((char)uVar3 != '\0') &&
             (uVar3 = GetLocalPlayerTeamNumber(), uVar11 = local_240, uVar3 == local_240)) {
            bVar2 = DoesFileExist(acStack_208);
            if (bVar2) {
              uVar3 = AudioMessage(acStack_208,false);
            }
            else {
              GetODFName((int)unaff_EDI);
              FormatLogMessage("ERROR: Sound file: \'%s\' doesn\'t exist! Fix ODF: \'%s\'");
              uVar3 = (uint)extraout_var_01 << 8;
            }
          }
        }
      }
      uVar3 = CONCAT31((int3)(uVar3 >> 8),local_241);
      if (local_241 != '\0') {
        memset(acStack_188,0,0x40);
        memset(auStack_48,0,0x40);
        memset(acStack_88,0,0x40);
        pcVar6 = acStack_88;
        pcVar8 = (char *)0x0;
        GetAndOpenODFNames((int)pcVar6,(char *)0x0,unaff_EDI,unaff_ESI);
        uVar3 = GetODFString("ArmoryClass","reloadMsg",(char *)0x40,acStack_188,0,pcVar6,pcVar8);
        if ((acStack_188[0] != '\0') && (uVar3 = GetLocalPlayerTeamNumber(), uVar3 == uVar11)) {
          bVar2 = DoesFileExist(acStack_188);
          if (bVar2) {
            uVar3 = AudioMessage(acStack_188,false);
          }
          else {
            GetODFName((int)unaff_EDI);
            FormatLogMessage("ERROR: Sound file: \'%s\' doesn\'t exist! Fix ODF: \'%s\'");
            uVar3 = (uint)extraout_var_02 << 8;
          }
        }
      }
    }
    local_240 = local_240 + 1;
  } while ((int)local_240 < 0x10);
  return;
}

