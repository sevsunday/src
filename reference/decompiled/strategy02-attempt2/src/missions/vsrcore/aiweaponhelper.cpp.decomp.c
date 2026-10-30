// Reconstructed by Ghidra from Strategy02.dll + Strategy02.pdb
// Original source file: /e:/github/vsr_dll_source/missions/vsrcore/aiweaponhelper.cpp
// Functions are ordered by original source line. This is decompiler
// output, not the author's source: names/types come from the PDB,
// local variable names and control flow are reconstructed.

// ---------------------------------------------------------------------
// AIWeaponHelper::AIGiveWeapons  @ 4fc26132  lines 10-201

/* WARNING: Function: _chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall
AIWeaponHelper::AIGiveWeapons(AIWeaponHelper *this,int param_1,int param_2,int param_3,bool param_4)

{
  bool bVar1;
  char *name;
  char *fmtarg1;
  int iVar2;
  int extraout_ECX;
  int iVar3;
  uint *puVar4;
  int *piVar5;
  int iVar6;
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
  
  uStack_4 = 0x4fc2613c;
  local_8 = __security_cookie ^ (uint)auStack_156c;
  local_155c = param_1;
  local_153c = param_2;
  if (param_3 == -1) {
    param_3 = GetNumWeapons(param_1);
  }
  if (param_3 != 0) {
    local_1565 = BZ1Helper::Logging;
    name = GetConfigODF(param_1);
    if (local_1565 != '\0') {
      iVar3 = param_2;
      pcVar7 = name;
      fmtarg1 = GetODFName(param_1);
      FormatConsoleMessage
                ("AIWeaponHelper: ODF: \'%s\', Team: %d, Config ODF: \'%s\'",fmtarg1,iVar3,pcVar7);
    }
    if ((name != (char *)0x0) && (bVar1 = OpenODF2(name), bVar1)) {
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
      local_1538 = BZ1Helper::m_BZ1Helper->teamInfo[param_2].m_CPUAIDifficulty;
      if (local_1565 != '\0') {
        FormatConsoleMessage("AIWeaponHelper: Opened ODF: \'%s\', Difficulty: %d",name,local_1538);
      }
      local_1554 = 0x40;
      piVar5 = &local_1520;
      local_1558 = 5;
LAB_4fc2626d:
      iVar3 = local_1558;
      iVar6 = 1;
      local_1550 = piVar5;
      memset(local_14cc,0,0x40);
      if (local_1538 == 1) {
        pcVar7 = "EasyWeaponSlot%d";
LAB_4fc262b7:
        sprintf_s<64>(&local_14cc,pcVar7);
      }
      else {
        if (local_1538 == 2) {
          pcVar7 = "MediumWeaponSlot%d";
          goto LAB_4fc262b7;
        }
        if (local_1538 == 3) {
          pcVar7 = "HardWeaponSlot%d";
          goto LAB_4fc262b7;
        }
        if (local_1538 == 4) {
          pcVar7 = "ExtremeWeaponSlot%d";
          goto LAB_4fc262b7;
        }
      }
      if (local_1565 != '\0') {
        FormatConsoleMessage
                  ("AIWeaponHelper: HardPoint %d Choosing Slot: \'%s\'",iVar3 + -1,local_14cc);
      }
      iVar3 = *piVar5;
      local_1560 = 0x10;
      puVar4 = local_151c + (int)local_1564;
      do {
        memset(local_144c,0,0x40);
        sprintf_s<64>(&local_144c,"WeaponName%d",iVar6);
        iVar2 = GetODFString(name,local_14cc,local_144c,0x40,
                             local_140c + (local_1554 + iVar3) * 0x40,(char *)0x0);
        if (iVar2 != 0) {
          iVar3 = iVar3 + 1;
        }
        sprintf_s<64>(&local_144c,"WeaponMask%d",iVar6);
        iVar2 = GetODFInt(name,local_14cc,local_144c,(int *)puVar4,0);
        if (iVar2 != 0) {
          local_1564 = (float)((int)local_1564 + 1);
          puVar4 = puVar4 + 1;
        }
        iVar6 = iVar6 + 1;
        local_1560 = local_1560 + -1;
      } while (local_1560 != 0);
      bVar1 = (char)local_1548 == '\0';
      uVar8 = 1;
      *local_1550 = iVar3;
      if (bVar1) {
        iVar6 = GetODFInt(name,local_14cc,"MinWeaponMask",(int *)&local_1544,1);
        local_1548 = local_1548 & 0xff;
        if (iVar6 != 0) {
          local_1548 = uVar8;
        }
      }
      iVar6 = local_1558;
      local_1540 = abStack_14dd + local_1558;
      GetODFBool(name,local_14cc,"SkipRequirements",local_1540,false);
      local_1534 = abStack_14d5 + iVar6;
      GetODFBool(name,local_14cc,"HardpointOverride",local_1534,false);
      iVar6 = local_155c;
      if (iVar3 != 0) {
        local_1560 = 0;
        do {
          local_154c = GetRandomInt(0,iVar3 + -1);
          iVar6 = local_1554 + local_154c;
          iVar2 = local_1554;
          if (local_1565 != '\0') {
            FormatLogMessage("AIWeaponHelper: Number Of Weapons for HardPoint %d is: %d, Choice: %d WeaponName: \'%s\'"
                             ,local_1558 + -1,iVar3,local_154c,local_140c + iVar6 * 0x40);
            iVar2 = extraout_ECX;
          }
          bVar1 = BZ1Helper::CheckBuildRequirements
                            (BZ1Helper::m_BZ1Helper,local_140c + iVar6 * 0x40,local_153c,false,
                             SUB41(iVar2,0),SUB41(iVar2,0));
          iVar2 = local_154c;
          iVar6 = local_155c;
          if ((bVar1) || (*local_1540 != false)) {
            if (-1 < local_154c) {
              memset(local_148c,0,0x40);
              local_1560 = 0;
              pcVar7 = local_140c + (local_1554 + iVar2) * 0x40;
              if (*pcVar7 != '\0') {
                bVar1 = DoesODFExist(pcVar7);
                if (bVar1) {
                  CombineStrings(local_148c,pcVar7,".odf",0x40);
                  bVar1 = OpenODF2(local_148c);
                  if (bVar1) {
                    GetODFString(local_148c,(char *)0x0,"WeaponPowerupClass","weaponName",0x40,
                                 local_148c,(char *)0x0);
                    GetODFInt(local_148c,(char *)0x0,"GameObjectClass","scrapCost",&local_1560,0);
                  }
                }
                else {
                  FormatLogMessage("ERROR: \'%s\' Weapon \'%s\' does not exist. Fix ODFs!",name,
                                   pcVar7);
                }
              }
              iVar2 = 0;
              iVar3 = local_1558 + -1;
              iVar6 = local_155c;
              local_154c = iVar3;
              if (-1 < iVar3) goto LAB_4fc265d9;
            }
            break;
          }
          local_1560 = local_1560 + 1;
        } while (local_1560 < 0x10);
      }
      goto LAB_4fc264c4;
    }
  }
  return;
LAB_4fc265d9:
  do {
    if (local_148c[0] != '\0') {
      bVar1 = DoesODFExist(local_148c);
      if (bVar1) {
        if ((iVar2 == 0) && (*local_1540 == false)) {
          (*misnImport.AddScrap)(local_153c,-local_1560);
        }
        iVar6 = local_155c;
        if (*local_1534 != false) {
          GiveWeapon(local_155c,iVar2,local_148c);
          break;
        }
        GiveWeapon(local_155c,local_148c);
        iVar3 = local_154c;
      }
      else {
        FormatLogMessage("ERROR: \'%s\' Weapon \'%s\' does not exist. Fix ODFs!",pcVar7,local_148c);
        iVar3 = local_154c;
      }
    }
    iVar2 = iVar2 + 1;
    iVar6 = local_155c;
  } while (iVar2 <= iVar3);
LAB_4fc264c4:
  piVar5 = local_1550 + -1;
  iVar2 = local_1558 + -1;
  local_1554 = local_1554 + -0x10;
  iVar3 = local_1558 + -2;
  local_1558 = iVar2;
  if (iVar3 < 0) {
    local_1550 = piVar5;
    if ((int)local_1564 < 1) {
      local_1564 = GetRandomFloat(5.0);
      if (1.0 < local_1564) {
        if (2.0 < local_1564) {
          if (3.0 < local_1564) {
            if (local_1564 <= 4.0) {
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
      iVar3 = GetRandomInt(0,(int)local_1564 + -1);
      uVar8 = local_151c[iVar3];
    }
    if ((int)uVar8 < (int)local_1544) {
      uVar8 = local_1544;
    }
    SetWeaponMask(iVar6,uVar8);
    return;
  }
  goto LAB_4fc2626d;
}


