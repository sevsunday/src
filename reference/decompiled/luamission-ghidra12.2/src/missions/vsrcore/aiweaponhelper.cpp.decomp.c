// Reconstructed by Ghidra from LuaMission.dll + LuaMission.pdb
// Original source file: /e:/github/vsr_dll_source/missions/vsrcore/aiweaponhelper.cpp
// Functions are ordered by original source line. This is decompiler
// output, not the author's source: names/types come from the PDB,
// local variable names and control flow are reconstructed.


// ---------------------------------------------------------------------
// AIWeaponHelper::AIGiveWeapons  @ 4fc39ead  lines 10-201


/* WARNING: Function: _chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
AIWeaponHelper::AIGiveWeapons(AIWeaponHelper *this,int param_1,int param_2,int param_3,bool param_4)

{
  int *piVar1;
  bool bVar2;
  char *pcVar3;
  int iVar4;
  int extraout_ECX;
  int iVar5;
  char *unaff_ESI;
  uint *puVar6;
  int *unaff_EDI;
  char *pcVar7;
  uint uVar8;
  undefined1 auStack_156c [7];
  char local_1565;
  float local_1564;
  int local_1560;
  int local_155c;
  int local_1558;
  int local_1554;
  int *local_1550;
  int local_154c;
  uint local_1548;
  uint local_1544;
  bool *local_1540;
  int local_153c;
  int local_1538;
  bool *local_1534;
  undefined4 local_1530;
  undefined4 uStack_152c;
  undefined4 uStack_1528;
  undefined4 uStack_1524;
  int local_1520;
  uint local_151c [15];
  bool abStack_14dd [8];
  bool abStack_14d5 [9];
  char local_14cc [64];
  char local_148c [64];
  char local_144c [64];
  char local_140c [5124];
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x4fc39eb7;
  local_8 = __security_cookie ^ (uint)auStack_156c;
  local_155c = param_1;
  local_153c = param_2;
  if (param_3 == -1) {
    param_3 = GetNumWeapons((int)unaff_EDI);
  }
  if (param_3 == 0) {
    return;
  }
  local_1565 = BZ1Helper::Logging;
  pcVar3 = GetConfigODF((int)unaff_EDI);
  if (local_1565 != '\0') {
    GetODFName(param_2);
    FormatConsoleMessage("AIWeaponHelper: ODF: \'%s\', Team: %d, Config ODF: \'%s\'");
  }
  if (pcVar3 == (char *)0x0) {
    return;
  }
  bVar2 = OpenODF2((char *)unaff_EDI);
  if (!bVar2) {
    return;
  }
  local_1530 = 0;
  uStack_152c = 0;
  uStack_1528 = 0;
  uStack_1524 = 0;
  local_1520 = 0;
  memset(local_140c,0,0x1400);
  local_1544 = 0;
  local_1548 = local_1548 & 0xffffff00;
  abStack_14dd[1] = false;
  abStack_14dd[2] = false;
  abStack_14dd[3] = false;
  abStack_14dd[4] = false;
  abStack_14dd[5] = false;
  abStack_14d5[1] = false;
  abStack_14d5[2] = false;
  abStack_14d5[3] = false;
  abStack_14d5[4] = false;
  abStack_14d5[5] = false;
  memset(local_151c,0,0x40);
  local_1564 = 0.0;
  local_1538 = *(int *)((int)BZ1Helper::m_BZ1Helper->teamInfo + param_2 * 0xa14 + 0x98);
  if (local_1565 != '\0') {
    FormatConsoleMessage("AIWeaponHelper: Opened ODF: \'%s\', Difficulty: %d");
  }
  local_1554 = 0x40;
  local_1550 = &local_1520;
  local_1558 = 5;
LAB_4fc39fe8:
  piVar1 = local_1550;
  memset(local_14cc,0,0x40);
  if (local_1538 == 1) {
    pcVar7 = "EasyWeaponSlot%d";
LAB_4fc3a032:
    sprintf_s<64>(&local_14cc,pcVar7);
  }
  else {
    if (local_1538 == 2) {
      pcVar7 = "MediumWeaponSlot%d";
      goto LAB_4fc3a032;
    }
    if (local_1538 == 3) {
      pcVar7 = "HardWeaponSlot%d";
      goto LAB_4fc3a032;
    }
    if (local_1538 == 4) {
      pcVar7 = "ExtremeWeaponSlot%d";
      goto LAB_4fc3a032;
    }
  }
  if (local_1565 != '\0') {
    FormatConsoleMessage("AIWeaponHelper: HardPoint %d Choosing Slot: \'%s\'");
  }
  iVar5 = *piVar1;
  local_1560 = 0x10;
  puVar6 = local_151c + (int)local_1564;
  do {
    memset(local_144c,0,0x40);
    sprintf_s<64>(&local_144c,"WeaponName%d");
    iVar4 = GetODFString(pcVar3,local_14cc,local_144c,0x40,local_140c + (local_1554 + iVar5) * 0x40,
                         (char *)0x0);
    if (iVar4 != 0) {
      iVar5 = iVar5 + 1;
    }
    sprintf_s<64>(&local_144c,"WeaponMask%d");
    iVar4 = GetODFInt(pcVar3,local_14cc,local_144c,(int *)puVar6,0);
    if (iVar4 != 0) {
      local_1564 = (float)((int)local_1564 + 1);
      puVar6 = puVar6 + 1;
    }
    local_1560 = local_1560 + -1;
  } while (local_1560 != 0);
  uVar8 = 1;
  *local_1550 = iVar5;
  if ((char)local_1548 == '\0') {
    iVar4 = GetODFInt(pcVar3,local_14cc,"MinWeaponMask",(int *)&local_1544,1);
    local_1548 = local_1548 & 0xff;
    if (iVar4 != 0) {
      local_1548 = uVar8;
    }
  }
  iVar4 = local_1558;
  local_1540 = abStack_14dd + local_1558;
  GetODFBool(pcVar3,local_14cc,"SkipRequirements",local_1540,false);
  local_1534 = abStack_14d5 + iVar4;
  GetODFBool(pcVar3,local_14cc,"HardpointOverride",local_1534,false);
  if (iVar5 != 0) {
    local_1560 = 0;
    do {
      local_154c = GetRandomInt((int)unaff_EDI,(int)unaff_ESI);
      iVar5 = local_1554 + local_154c;
      iVar4 = local_1554;
      if (local_1565 != '\0') {
        FormatLogMessage(
                        "AIWeaponHelper: Number Of Weapons for HardPoint %d is: %d, Choice: %d WeaponName: \'%s\'"
                        );
        iVar4 = extraout_ECX;
      }
      bVar2 = BZ1Helper::CheckBuildRequirements
                        (BZ1Helper::m_BZ1Helper,local_140c + iVar5 * 0x40,local_153c,false,
                         SUB41(iVar4,0),SUB41(iVar4,0));
      iVar5 = local_154c;
      if ((bVar2) || (*local_1540 != false)) {
        if (-1 < local_154c) {
          memset(local_148c,0,0x40);
          local_1560 = 0;
          if (local_140c[(local_1554 + iVar5) * 0x40] != '\0') {
            bVar2 = DoesODFExist(local_140c + (local_1554 + iVar5) * 0x40);
            if (bVar2) {
              CombineStrings(".odf",(char *)0x40,(char *)unaff_EDI,(uint)unaff_ESI);
              bVar2 = OpenODF2((char *)unaff_EDI);
              if (bVar2) {
                GetODFString("WeaponPowerupClass","weaponName",(char *)0x40,local_148c,0,
                             (char *)unaff_EDI,unaff_ESI);
                GetODFInt("GameObjectClass","scrapCost",(char *)&local_1560,(char *)0x0,unaff_EDI,
                          (int)unaff_ESI);
              }
            }
            else {
              FormatLogMessage("ERROR: \'%s\' Weapon \'%s\' does not exist. Fix ODFs!");
            }
          }
          iVar4 = 0;
          iVar5 = local_1558 + -1;
          local_154c = iVar5;
          if (-1 < iVar5) goto LAB_4fc3a354;
        }
        break;
      }
      local_1560 = local_1560 + 1;
    } while (local_1560 < 0x10);
  }
  goto LAB_4fc3a23b;
LAB_4fc3a354:
  do {
    if (local_148c[0] != '\0') {
      bVar2 = DoesODFExist(local_148c);
      if (bVar2) {
        if ((iVar4 == 0) && (*local_1540 == false)) {
          (*misnImport.AddScrap)(local_153c,-local_1560);
        }
        iVar5 = local_155c;
        if (*local_1534 != false) {
          GiveWeapon(local_155c,iVar4,local_148c);
          goto LAB_4fc3a23f;
        }
        GiveWeapon(local_155c,local_148c);
      }
      else {
        FormatLogMessage("ERROR: \'%s\' Weapon \'%s\' does not exist. Fix ODFs!");
      }
      iVar5 = local_154c;
    }
    iVar4 = iVar4 + 1;
  } while (iVar4 <= iVar5);
LAB_4fc3a23b:
  iVar5 = local_155c;
LAB_4fc3a23f:
  local_1550 = local_1550 + -1;
  iVar4 = local_1558 + -1;
  local_1554 = local_1554 + -0x10;
  if (local_1558 + -2 < 0) {
    if ((int)local_1564 < 1) {
      local_1558 = iVar4;
      local_1564 = GetRandomFloat(___real_40a00000);
      if (1.0 < local_1564) {
        if (__real_40000000 < local_1564) {
          if (__real_40400000 < local_1564) {
            if (local_1564 <= __real_40800000) {
              uVar8 = 3;
            }
          }
          else {
            uVar8 = 7;
          }
        }
        else {
          uVar8 = 0xf;
        }
      }
      else {
        uVar8 = 0x1f;
      }
    }
    else {
      local_1558 = iVar4;
      iVar4 = GetRandomInt((int)unaff_EDI,(int)unaff_ESI);
      uVar8 = local_151c[iVar4];
    }
    if ((int)uVar8 < (int)local_1544) {
      uVar8 = local_1544;
    }
    SetWeaponMask(iVar5,uVar8);
    return;
  }
  local_1558 = iVar4;
  goto LAB_4fc39fe8;
}

