// Reconstructed by Ghidra from Strategy02.dll + Strategy02.pdb
// Original source file: /e:/github/vsr_dll_source/missions/vsrcore/aiweaponhelper.cpp
// Functions are ordered by original source line. This is decompiler
// output, not the author's source: names/types come from the PDB,
// local variable names and control flow are reconstructed.


// ---------------------------------------------------------------------
// AIWeaponHelper::AIGiveWeapons  @ 4fc26132  lines 10-201


/* WARNING: Function: _chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
AIWeaponHelper::AIGiveWeapons(AIWeaponHelper *this,int param_1,int param_2,int param_3,bool param_4)

{
  bool bVar1;
  char *pcVar2;
  int iVar3;
  int extraout_ECX;
  int iVar4;
  int iVar5;
  char *unaff_ESI;
  uint *puVar6;
  int *unaff_EDI;
  int *piVar7;
  char *pcVar8;
  uint uVar9;
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
    param_3 = GetNumWeapons((int)unaff_EDI);
  }
  if (param_3 != 0) {
    local_1565 = BZ1Helper::Logging;
    pcVar2 = GetConfigODF((int)unaff_EDI);
    if (local_1565 != '\0') {
      GetODFName(param_2);
      FormatConsoleMessage("AIWeaponHelper: ODF: \'%s\', Team: %d, Config ODF: \'%s\'");
    }
    if ((pcVar2 != (char *)0x0) && (bVar1 = OpenODF2((char *)unaff_EDI), bVar1)) {
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
      piVar7 = &local_1520;
      local_1558 = 5;
LAB_4fc2626d:
      local_1550 = piVar7;
      memset(local_14cc,0,0x40);
      if (local_1538 == 1) {
        pcVar8 = "EasyWeaponSlot%d";
LAB_4fc262b7:
        sprintf_s<64>(&local_14cc,pcVar8);
      }
      else {
        if (local_1538 == 2) {
          pcVar8 = "MediumWeaponSlot%d";
          goto LAB_4fc262b7;
        }
        if (local_1538 == 3) {
          pcVar8 = "HardWeaponSlot%d";
          goto LAB_4fc262b7;
        }
        if (local_1538 == 4) {
          pcVar8 = "ExtremeWeaponSlot%d";
          goto LAB_4fc262b7;
        }
      }
      if (local_1565 != '\0') {
        FormatConsoleMessage("AIWeaponHelper: HardPoint %d Choosing Slot: \'%s\'");
      }
      iVar4 = *piVar7;
      local_1560 = 0x10;
      puVar6 = local_151c + (int)local_1564;
      do {
        memset(local_144c,0,0x40);
        sprintf_s<64>(&local_144c,"WeaponName%d");
        iVar3 = GetODFString(pcVar2,local_14cc,local_144c,0x40,
                             local_140c + (local_1554 + iVar4) * 0x40,(char *)0x0);
        if (iVar3 != 0) {
          iVar4 = iVar4 + 1;
        }
        sprintf_s<64>(&local_144c,"WeaponMask%d");
        iVar3 = GetODFInt(pcVar2,local_14cc,local_144c,(int *)puVar6,0);
        if (iVar3 != 0) {
          local_1564 = (float)((int)local_1564 + 1);
          puVar6 = puVar6 + 1;
        }
        local_1560 = local_1560 + -1;
      } while (local_1560 != 0);
      bVar1 = (char)local_1548 == '\0';
      uVar9 = 1;
      *local_1550 = iVar4;
      if (bVar1) {
        iVar3 = GetODFInt(pcVar2,local_14cc,"MinWeaponMask",(int *)&local_1544,1);
        local_1548 = local_1548 & 0xff;
        if (iVar3 != 0) {
          local_1548 = uVar9;
        }
      }
      iVar3 = local_1558;
      local_1540 = abStack_14dd + local_1558;
      GetODFBool(pcVar2,local_14cc,"SkipRequirements",local_1540,false);
      local_1534 = abStack_14d5 + iVar3;
      GetODFBool(pcVar2,local_14cc,"HardpointOverride",local_1534,false);
      iVar3 = local_155c;
      if (iVar4 != 0) {
        local_1560 = 0;
        do {
          local_154c = GetRandomInt((int)unaff_EDI,(int)unaff_ESI);
          iVar4 = local_1554 + local_154c;
          iVar3 = local_1554;
          if (local_1565 != '\0') {
            FormatLogMessage(
                            "AIWeaponHelper: Number Of Weapons for HardPoint %d is: %d, Choice: %d WeaponName: \'%s\'"
                            );
            iVar3 = extraout_ECX;
          }
          bVar1 = BZ1Helper::CheckBuildRequirements
                            (BZ1Helper::m_BZ1Helper,local_140c + iVar4 * 0x40,local_153c,false,
                             SUB41(iVar3,0),SUB41(iVar3,0));
          iVar4 = local_154c;
          iVar3 = local_155c;
          if ((bVar1) || (*local_1540 != false)) {
            if (-1 < local_154c) {
              memset(local_148c,0,0x40);
              local_1560 = 0;
              if (local_140c[(local_1554 + iVar4) * 0x40] != '\0') {
                bVar1 = DoesODFExist(local_140c + (local_1554 + iVar4) * 0x40);
                if (bVar1) {
                  CombineStrings(".odf",(char *)0x40,(char *)unaff_EDI,(uint)unaff_ESI);
                  bVar1 = OpenODF2((char *)unaff_EDI);
                  if (bVar1) {
                    GetODFString("WeaponPowerupClass","weaponName",(char *)0x40,local_148c,0,
                                 (char *)unaff_EDI,unaff_ESI);
                    GetODFInt("GameObjectClass","scrapCost",(char *)&local_1560,(char *)0x0,
                              unaff_EDI,(int)unaff_ESI);
                  }
                }
                else {
                  FormatLogMessage("ERROR: \'%s\' Weapon \'%s\' does not exist. Fix ODFs!");
                }
              }
              iVar5 = 0;
              iVar4 = local_1558 + -1;
              iVar3 = local_155c;
              local_154c = iVar4;
              if (-1 < iVar4) goto LAB_4fc265d9;
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
        if ((iVar5 == 0) && (*local_1540 == false)) {
          (*misnImport.AddScrap)(local_153c,-local_1560);
        }
        iVar3 = local_155c;
        if (*local_1534 != false) {
          GiveWeapon(local_155c,iVar5,local_148c);
          break;
        }
        GiveWeapon(local_155c,local_148c);
        iVar4 = local_154c;
      }
      else {
        FormatLogMessage("ERROR: \'%s\' Weapon \'%s\' does not exist. Fix ODFs!");
        iVar4 = local_154c;
      }
    }
    iVar5 = iVar5 + 1;
    iVar3 = local_155c;
  } while (iVar5 <= iVar4);
LAB_4fc264c4:
  piVar7 = local_1550 + -1;
  iVar5 = local_1558 + -1;
  local_1554 = local_1554 + -0x10;
  iVar4 = local_1558 + -2;
  local_1558 = iVar5;
  if (iVar4 < 0) {
    local_1550 = piVar7;
    if ((int)local_1564 < 1) {
      local_1564 = GetRandomFloat(___real_40a00000);
      if (1.0 < local_1564) {
        if (__real_40000000 < local_1564) {
          if (__real_40400000 < local_1564) {
            if (local_1564 <= __real_40800000) {
              uVar9 = 3;
            }
          }
          else {
            uVar9 = 7;
          }
        }
        else {
          uVar9 = 0xf;
        }
      }
      else {
        uVar9 = 0x1f;
      }
    }
    else {
      iVar4 = GetRandomInt((int)unaff_EDI,(int)unaff_ESI);
      uVar9 = local_151c[iVar4];
    }
    if ((int)uVar9 < (int)local_1544) {
      uVar9 = local_1544;
    }
    SetWeaponMask(iVar3,uVar9);
    return;
  }
  goto LAB_4fc2626d;
}

