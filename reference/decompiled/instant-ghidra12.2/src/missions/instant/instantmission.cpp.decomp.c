// Reconstructed by Ghidra from Instant.dll + Instant.pdb
// Original source file: /e:/github/vsr_dll_source/missions/instant/instantmission.cpp
// Functions are ordered by original source line. This is decompiler
// output, not the author's source: names/types come from the PDB,
// local variable names and control flow are reconstructed.


// ---------------------------------------------------------------------
// instantMission::instantMission  @ 4fc42842  lines 62-83


/* WARNING: Function: _EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: _EH_epilog3 replaced with injection: EH_epilog3 */

instantMission * __thiscall instantMission::instantMission(instantMission *this)

{
  char *in_stack_ffffffdc;
  
  LuaMission::LuaMission((LuaMission *)this);
  this->_padding_ = (int)_vftable_;
  this[1]._padding_ = 0x14;
  EnableHighTPS(&this[1]._padding_);
  AllowRandomTracks(true);
  this[1]._padding_ = 0x75;
  this[1]._padding_ = (int)((int)this->m_CPUCommBunkerCount + 0x15);
  this[1]._padding_ = (int)(this->m_CustomAIPInts + 4);
  this[1]._padding_ = (int)(this->m_CustomAIPInts + 7);
  this[1]._padding_ = (int)&this[1]._padding_;
  this[1]._padding_ = 1;
  this[1]._padding_ = 0x106;
  this[1]._padding_ = 200;
  this[1]._padding_ = (int)&this[1]._padding_;
  this[1]._padding_ = 0x20;
  GetMapTRNFilename();
  TRNAllies::SetupTRNAllies(in_stack_ffffffdc);
  return this;
}


// ---------------------------------------------------------------------
// instantMission::~instantMission  @ 4fc4282c  lines 86-88


void __thiscall instantMission::~instantMission(instantMission *this)

{
  this->_padding_ = (int)_vftable_;
  CleanupTaunts();
  LuaMission::~LuaMission((LuaMission *)this);
  return;
}


// ---------------------------------------------------------------------
// instantMission::BuildStartingVehicle  @ 4fc427bd  lines 95-102


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall
instantMission::BuildStartingVehicle
          (instantMission *this,int param_1,int param_2,char *param_3,char *param_4,char *param_5,
          int param_6,char *param_7)

{
  Vector VVar1;
  int iVar2;
  int iVar3;
  int unaff_ESI;
  char *unaff_EDI;
  float fVar4;
  instantMission *this_00;
  float local_10;
  instantMission *local_8;
  
  iVar2 = DoesPathExist(unaff_EDI);
  iVar3 = 0;
  if (iVar2 != 0) {
    GetVectorFromPath((Vector *)0x0,unaff_EDI,unaff_ESI);
    this_00 = local_8;
    fVar4 = TerrainFindFloor(local_10,(float)local_8);
    VVar1.y = fVar4 + ___real_3dcccccd;
    VVar1.x = local_10;
    VVar1.z = (float)local_8;
    iVar3 = BuildStartingVehicle(this_00,param_1,param_2,param_3,param_4,VVar1,param_6,param_7);
  }
  return iVar3;
}


// ---------------------------------------------------------------------
// instantMission::BuildStartingVehicle  @ 4fc426ba  lines 106-144


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __thiscall
instantMission::BuildStartingVehicle
          (instantMission *this,int param_1,int param_2,char *param_3,char *param_4,Vector param_5,
          int param_6,char *param_7)

{
  bool bVar1;
  int iVar2;
  char local_48 [64];
  undefined4 local_8;
  
  local_8 = __security_cookie ^ (uint)(local_48 + 0x44);
  strcpy_s(local_48,0x40,param_3);
  local_48[0] = (char)param_2;
  sprintf_s<64>(&local_48,"%s%s");
  bVar1 = DoesODFExist(local_48);
  if (!bVar1) {
    strcpy_s(local_48,0x40,param_3);
    local_48[0] = (char)param_2;
  }
  bVar1 = DoesODFExist(local_48);
  if (!bVar1) {
    strcpy_s(local_48,0x40,param_4);
    local_48[0] = (char)param_2;
    sprintf_s<64>(&local_48,"%s%s");
    bVar1 = DoesODFExist(local_48);
    if (!bVar1) {
      strcpy_s(local_48,0x40,param_4);
      local_48[0] = (char)param_2;
    }
  }
  iVar2 = BuildObject(local_48,param_1,&param_5);
  if (iVar2 != 0) {
    if (param_6 == -2) {
      SetBestGroup(iVar2);
    }
    else if (-1 < param_6) {
      SetGroup(iVar2,param_6);
    }
  }
  return iVar2;
}


// ---------------------------------------------------------------------
// instantMission::SetCPUAIPlan  @ 4fc424ef  lines 149-189


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall instantMission::SetCPUAIPlan(instantMission *this,AIPType param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  char *_Str1;
  int unaff_EDI;
  float fVar3;
  char local_108 [256];
  undefined4 local_8;
  
  local_8 = __security_cookie ^ (uint)(local_108 + 0x104);
  if (((int)param_1 < 0) || (6 < (int)param_1)) {
    param_1 = AIPType3;
  }
  if ((((int)param_1 < 4) || (*(int *)(this[1].m_SiegeOn + param_2 * 4 + -0x99a7) != 0)) ||
     (3 < *(int *)(this[1].m_SiegeOn + param_2 * 4 + -0x9967))) {
    memset(local_108,0,0x100);
    _Str1 = "VSR_";
    if (*(char *)this[1]._padding_ != '\0') {
      _Str1 = (char *)this[1]._padding_;
    }
    iVar2 = _strnicmp(_Str1,"VSR_",4);
    if (iVar2 == 0) {
      fVar3 = GetRandomFloat(3.0);
      floor((double)fVar3);
      sprintf_s<256>(&local_108,"%s%c%d_%d.aip");
      bVar1 = DoesFileExist(local_108);
      if (!bVar1) {
        sprintf_s<256>(&local_108,"%s%c%d_0.aip");
      }
    }
    else {
      sprintf_s<256>(&local_108,"%s%c_%c.aip");
      bVar1 = DoesFileExist(local_108);
      if (!bVar1) {
        sprintf_s<256>(&local_108,"%s%c%c%c.aip");
      }
    }
    BZ1Helper::SetAIPFile((BZ1Helper *)this,local_108,param_2);
    *(AIPType *)(this[1].m_SiegeOn + param_2 * 4 + -0x9967) = param_1;
    if (*(char *)((int)this->m_LastCPUPlan + 0x17) != '\0') {
      DoTaunt(unaff_EDI);
    }
    *(undefined1 *)((int)this->m_LastCPUPlan + 0x17) = 1;
  }
  return;
}


// ---------------------------------------------------------------------
// instantMission::SetupExtraVehicles  @ 4fc4223c  lines 194-304


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall instantMission::SetupExtraVehicles(instantMission *this)

{
  char *_Str;
  char cVar1;
  char *_Str_00;
  char *pcVar2;
  char *pcVar3;
  char *_MaxCount;
  int iVar4;
  int *piVar5;
  code *pcVar6;
  char **local_98;
  int local_94;
  int local_90;
  char local_8a;
  char local_89;
  char local_88 [64];
  char local_48 [64];
  undefined4 local_8;
  
  local_8 = __security_cookie ^ (uint)(local_48 + 0x44);
  GetAiPaths(&local_94,&local_98);
  local_89 = this[1].m_SiegeOn[this[1]._padding_ * 4 + -0x9a7f];
  local_8a = (char)this[1]._padding_;
  piVar5 = &this[1]._padding_;
  for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
    *piVar5 = 0;
    piVar5 = piVar5 + 1;
  }
  local_90 = 0;
  if (0 < local_94) {
    pcVar6 = strncmp_exref;
    do {
      _Str_00 = local_98[local_90];
      iVar4 = (*pcVar6)(_Str_00,"mpi",3);
      if (iVar4 == 0) {
        memset(local_48,0,0x40);
        memset(local_88,0,0x40);
        pcVar2 = strchr(_Str_00,0x5f);
        if (pcVar2 != (char *)0x0) {
          _Str = pcVar2 + 1;
          pcVar3 = strchr(_Str,0x5f);
          if (pcVar3 == (char *)0x0) {
            strcpy_s(local_48,0x40,_Str);
          }
          else {
            _MaxCount = pcVar3 + (-1 - (int)pcVar2);
            if ((char *)0x3f < pcVar3 + (-1 - (int)pcVar2)) {
              _MaxCount = (char *)0x3f;
            }
            strncpy_s(local_48,0x40,_Str,(rsize_t)_MaxCount);
            strcpy_s(local_88,0x40,pcVar3 + 1);
          }
          pcVar6 = strncmp_exref;
          pcVar2 = local_48;
          do {
            cVar1 = *pcVar2;
            pcVar2 = pcVar2 + 1;
          } while (cVar1 != '\0');
          iVar4 = (int)pcVar2 - (int)(local_48 + 1);
          if ((iVar4 != 0) && (local_88[iVar4 + 0x3f] == '_')) {
            if (0x3f < iVar4 - 1U) goto LAB_4fc424e9;
            local_88[iVar4 + 0x3f] = '\0';
          }
          pcVar2 = local_88;
          do {
            cVar1 = *pcVar2;
            pcVar2 = pcVar2 + 1;
          } while (cVar1 != '\0');
          iVar4 = (int)pcVar2 - (int)(local_88 + 1);
          if ((iVar4 != 0) && (local_88[iVar4 + -1] == '_')) {
            if (0x3f < iVar4 - 1U) {
LAB_4fc424e9:
                    /* WARNING: Subroutine does not return */
              __report_rangecheckfailure();
            }
            local_88[iVar4 + -1] = '\0';
          }
          iVar4 = strncmp(_Str_00,"mpic",4);
          if (iVar4 == 0) {
            if (local_48[0] == local_89) {
LAB_4fc423dc:
              pcVar2 = local_48;
            }
            else {
              if (local_88[0] != local_89) goto LAB_4fc424c1;
LAB_4fc42429:
              pcVar2 = local_88;
            }
            BuildObject(pcVar2,this[1]._padding_,_Str_00);
          }
          else {
            iVar4 = strncmp(_Str_00,"mpiC",4);
            if (iVar4 == 0) {
              if (local_48[0] != '\0') {
                local_48[0] = local_89;
                goto LAB_4fc423dc;
              }
              if (local_88[0] != '\0') {
                local_88[0] = local_89;
                goto LAB_4fc42429;
              }
            }
            else {
              iVar4 = strncmp(_Str_00,"mpih",4);
              if (iVar4 == 0) {
                if (local_48[0] == local_8a) {
LAB_4fc4245e:
                  pcVar2 = local_48;
                }
                else {
                  if (local_88[0] != local_8a) goto LAB_4fc424c1;
LAB_4fc424a3:
                  pcVar2 = local_88;
                }
                iVar4 = BuildObject(pcVar2,this[1]._padding_,_Str_00);
                SetBestGroup(iVar4);
              }
              else {
                iVar4 = strncmp(_Str_00,"mpiH",4);
                if (iVar4 == 0) {
                  if (local_48[0] != '\0') {
                    local_48[0] = local_8a;
                    goto LAB_4fc4245e;
                  }
                  if (local_88[0] != '\0') {
                    local_88[0] = local_8a;
                    goto LAB_4fc424a3;
                  }
                }
              }
            }
          }
        }
      }
LAB_4fc424c1:
      local_90 = local_90 + 1;
    } while (local_90 < local_94);
  }
  return;
}


// ---------------------------------------------------------------------
// instantMission::Setup  @ 4fc4216e  lines 308-350


void __thiscall instantMission::Setup(instantMission *this)

{
  undefined1 *puVar1;
  int *piVar2;
  int iVar3;
  int in_stack_00000004;
  
  SetAutoGroupUnits(false);
  *(undefined1 *)((int)this->m_CPUCommBunkerCount + 0x15) = 0;
  this[1]._padding_ = 0x9c4;
  this->m_CustomAIPInts[7] = -1;
  this[1]._padding_ = 1;
  this[1]._padding_ = 1;
  puVar1 = (undefined1 *)((int)this->m_CPUCommBunkerCount + 0x27);
  this[1]._padding_ = 0;
  this[1]._padding_ = 6;
  this[1]._padding_ = 0;
  iVar3 = 0x10;
  piVar2 = &this[1]._padding_;
  do {
    piVar2[0x4d] = 0;
    puVar1[-0x10] = 0;
    *puVar1 = 0;
    *piVar2 = 0;
    puVar1[0x10] = 0;
    piVar2[0x10] = 0;
    puVar1[0x20] = 0;
    puVar1 = puVar1 + 1;
    iVar3 = iVar3 + -1;
    piVar2 = piVar2 + 1;
  } while (iVar3 != 0);
  this->m_CPUMaxPatrolUnits[1] = 0;
  this->m_CPUMaxPatrolUnits[2] = 0;
  this->m_CPUMaxPatrolUnits[3] = 0;
  this->m_CPUMaxPatrolUnits[4] = 0;
  PreloadODF("ivrecy");
  PreloadODF("fvrecy");
  PreloadODF("ivrecycpu");
  PreloadODF("fvrecycpu");
  this[1]._padding_ = -2000;
  DoTaunt(in_stack_00000004);
  return;
}


// ---------------------------------------------------------------------
// instantMission::AddCPUScav  @ 4fc41f1c  lines 358-431


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall instantMission::AddCPUScav(instantMission *this,int param_1,int param_2)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  int *piVar4;
  int unaff_EDI;
  int iVar5;
  int *piVar6;
  int *local_94;
  int local_90;
  int local_8c;
  int local_84 [15];
  char local_48 [64];
  undefined4 local_8;
  
  local_8 = __security_cookie ^ (uint)(local_48 + 0x44);
  if (*(int *)(this[1].m_SiegeOn + param_2 * 4 + -0x99ef) < 0xf) {
    this->m_CPUMaxPatrolUnits
    [param_2 * 0xf + *(int *)(this[1].m_SiegeOn + param_2 * 4 + -0x99ef) + 5] = param_1;
    *(int *)(this[1].m_SiegeOn + param_2 * 4 + -0x99ef) =
         *(int *)(this[1].m_SiegeOn + param_2 * 4 + -0x99ef) + 1;
    if (*(int *)(this[1].m_SiegeOn + param_2 * 4 + -0x99ef) < 0xf) {
      return;
    }
  }
  DoTaunt(unaff_EDI);
  iVar5 = 0;
  local_8c = 0;
  memset(local_84,0,0x3c);
  local_90 = 0;
  if (0 < *(int *)(this[1].m_SiegeOn + param_2 * 4 + -0x99ef)) {
    local_94 = this->m_CPUMaxPatrolUnits + param_2 * 0xf + 5;
    do {
      iVar5 = *local_94;
      bVar1 = false;
      bVar2 = IsAround(iVar5);
      if ((bVar2) && (iVar3 = GetTeamNum(iVar5), iVar3 == this[1]._padding_)) {
        GetObjInfo(iVar5,Get_GOClass,local_48);
        iVar3 = _stricmp(local_48,"CLASS_SCAVENGER");
        if ((iVar3 == 0) || (iVar3 = _stricmp(local_48,"CLASS_SCAVENGERH"), iVar3 == 0)) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
      }
      if (iVar5 == param_1) {
        bVar1 = true;
      }
      if (bVar1) {
        local_84[local_8c] = iVar5;
        local_8c = local_8c + 1;
      }
      local_90 = local_90 + 1;
      local_94 = local_94 + 1;
    } while (local_90 < *(int *)(this[1].m_SiegeOn + param_2 * 4 + -0x99ef));
    iVar5 = local_8c;
  }
  *(int *)(this[1].m_SiegeOn + param_2 * 4 + -0x99ef) = iVar5;
  piVar4 = local_84;
  piVar6 = this->m_CPUMaxPatrolUnits + 5;
  for (iVar5 = 0xf0; iVar5 != 0; iVar5 = iVar5 + -1) {
    *piVar6 = *piVar4;
    piVar4 = piVar4 + 1;
    piVar6 = piVar6 + 1;
  }
  iVar5 = *(int *)(this[1].m_SiegeOn + param_2 * 4 + -0x99ef);
  if (5 < iVar5) {
    do {
      iVar3 = iVar5 + -1;
      if (0 < iVar3) {
        piVar4 = this->m_CPUMaxPatrolUnits + param_2 * 0xf + iVar5 + 4;
        do {
          if (*piVar4 != param_1) break;
          iVar3 = iVar3 + -1;
          piVar4 = piVar4 + -1;
        } while (0 < iVar3);
      }
      iVar5 = param_2 * 0xf + iVar3;
      if (this->m_CPUMaxPatrolUnits[iVar5 + 5] == param_1) {
        return;
      }
      SetNoScrapFlagByHandle(this->m_CPUMaxPatrolUnits[iVar5 + 5]);
      SelfDamage(this->m_CPUMaxPatrolUnits[param_2 * 0xf + iVar3 + 5],1e+28);
      iVar5 = *(int *)(this[1].m_SiegeOn + param_2 * 4 + -0x99ef);
      if (iVar3 < iVar5) {
        piVar4 = this->m_CPUMaxPatrolUnits + iVar3 + param_2 * 0xf + 5;
        do {
          iVar3 = iVar3 + 1;
          *piVar4 = piVar4[1];
          piVar4 = piVar4 + 1;
          iVar5 = *(int *)(this[1].m_SiegeOn + param_2 * 4 + -0x99ef);
        } while (iVar3 < iVar5);
      }
      *(int *)(this[1].m_SiegeOn + param_2 * 4 + -0x99ef) = iVar5 + -1;
      this->m_CPUMaxPatrolUnits[param_2 * 0xf + iVar5 + 4] = 0;
      iVar5 = *(int *)(this[1].m_SiegeOn + param_2 * 4 + -0x99ef);
    } while (5 < iVar5);
  }
  return;
}


// ---------------------------------------------------------------------
// instantMission::AddObject  @ 4fc41b65  lines 438-646


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall instantMission::AddObject(instantMission *this,int param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  AIPType AVar5;
  bool *pbVar6;
  int *piVar7;
  code *pcVar8;
  byte local_88 [64];
  char local_48 [64];
  undefined4 local_8;
  
  local_8 = __security_cookie ^ (uint)(local_48 + 0x44);
  if (*(char *)((int)this->m_CPUCommBunkerCount + 0x16) == '\0') {
    LuaMission::AddObject((LuaMission *)this,param_1);
  }
  bVar1 = GetObjInfo(param_1,Get_CFG,(char *)local_88);
  local_88[0] = local_88[0] & -bVar1;
  GetObjInfo(param_1,Get_GOClass,local_48);
  iVar2 = GetTeamNum(param_1);
  pcVar8 = _stricmp_exref;
  iVar3 = _stricmp(local_48,"CLASS_COMMBUNKER");
  if (((iVar3 == 0) || (iVar3 = _stricmp(local_48,"CLASS_COMMTOWER"), iVar3 == 0)) &&
     (iVar2 == this[1]._padding_)) {
    *(int *)(this[1].m_SiegeOn + iVar2 * 4 + -0x99a7) =
         *(int *)(this[1].m_SiegeOn + iVar2 * 4 + -0x99a7) + 1;
  }
  iVar3 = _stricmp(local_48,"CLASS_RECYCLERVEHICLE");
  if ((((iVar3 == 0) || (iVar3 = _stricmp(local_48,"CLASS_RECYCLERVEHICLEH"), iVar3 == 0)) ||
      (iVar3 = _stricmp(local_48,"CLASS_RECYCLER"), iVar3 == 0)) &&
     (bVar1 = IsAround(this->m_CPUAIDifficultyAddon[iVar2 + 1]), !bVar1)) {
    this->m_CPUAIDifficultyAddon[iVar2 + 1] = param_1;
  }
  if (iVar2 < this[1]._padding_) {
    if (this[1]._padding_ == 0) {
      if (iVar2 != this[1]._padding_) goto LAB_4fc41e8e;
      iVar3 = _stricmp(local_48,"CLASS_ARTILLERY");
      if (iVar3 == 0) {
LAB_4fc41ce7:
        iVar3 = this[1]._padding_;
        if (iVar3 < 0x10) {
          do {
            if ((*(char *)((int)this->m_CPUCommBunkerCount + iVar3 + 0x17) == '\0') &&
               (*(char *)((int)this->m_CPUCommBunkerCount + iVar3 + 0x37) == '\0')) {
              *(undefined1 *)((int)this->m_CPUCommBunkerCount + iVar3 + 0x37) = 1;
              SetCPUAIPlan(this,AIPTypeL,iVar3);
            }
            iVar3 = iVar3 + 1;
          } while (iVar3 < 0x10);
          pcVar8 = _stricmp_exref;
        }
      }
      else {
        iVar3 = _stricmp(local_48,"CLASS_BOMBER");
        if (iVar3 == 0) goto LAB_4fc41ce7;
      }
      iVar3 = (*pcVar8)(local_48,"CLASS_HOVER");
      if (((((iVar3 == 0) || (iVar3 = (*pcVar8)(local_48,"CLASS_WINGMAN"), iVar3 == 0)) ||
           (iVar3 = (*pcVar8)(local_48,"CLASS_MORPHTANK"), iVar3 == 0)) ||
          ((iVar3 = (*pcVar8)(local_48,"CLASS_ASSAULTTANK"), iVar3 == 0 ||
           (iVar3 = (*pcVar8)(local_48,"CLASS_SERVICE"), iVar3 == 0)))) ||
         (iVar3 = (*pcVar8)(local_48,"CLASS_WALKER"), iVar3 == 0)) {
        SetTeamNum(param_1,1);
      }
    }
  }
  else {
    iVar3 = _stricmp(local_48,"CLASS_SCAVENGER");
    if ((iVar3 == 0) || (iVar3 = _stricmp(local_48,"CLASS_SCAVENGERH"), iVar3 == 0)) {
      AddCPUScav(this,param_1,iVar2);
    }
    SetSkill(param_1,this[1]._padding_ + 1);
    DispatchHelper::AddToDispatch
              ((DispatchHelper *)this->_padding_,param_1,15.0,false,0,false,false,false,false);
  }
  if (iVar2 == this[1]._padding_) {
    SetSkill(param_1,3 - this[1]._padding_);
    iVar3 = (*pcVar8)(local_48,"CLASS_RECYCLER");
    if (iVar3 == 0) {
      if ((char)this->m_LastCPUPlan[6] != '\0') {
        return;
      }
      iVar2 = this[1]._padding_;
      *(undefined1 *)(this->m_LastCPUPlan + 6) = 1;
      if (iVar2 < 0x10) {
        pbVar6 = this[1].m_SiegeOn + iVar2 * 4 + -0x9a7f;
        do {
          bVar1 = IsAround(*(int *)(pbVar6 + -0x4c4));
          if (bVar1) {
            uVar4 = this[1]._padding_ & 0x80000001;
            if ((int)uVar4 < 0) {
              uVar4 = (uVar4 - 1 | 0xfffffffe) + 1;
            }
            if (*(int *)pbVar6 == 0x66) {
              if (uVar4 == 1) {
                AVar5 = AIPType3;
              }
              else if (uVar4 == 2) {
                AVar5 = AIPType2;
              }
              else {
                AVar5 = AIPType1;
              }
            }
            else {
              uVar4 = uVar4 & 0x80000001;
              if ((int)uVar4 < 0) {
                uVar4 = (uVar4 - 1 | 0xfffffffe) + 1;
              }
              if (uVar4 == 1) {
                AVar5 = AIPType3;
              }
              else {
                AVar5 = AIPType1;
              }
            }
            SetCPUAIPlan(this,AVar5,iVar2);
          }
          iVar2 = iVar2 + 1;
          pbVar6 = pbVar6 + 4;
        } while (iVar2 < 0x10);
      }
    }
    else {
      iVar3 = (*pcVar8)(local_48,"CLASS_ASSAULTTANK");
      if ((iVar3 == 0) || (iVar3 = (*pcVar8)(local_48,"CLASS_WALKER"), iVar3 == 0)) {
        *(int *)(this[1].m_SiegeOn + iVar2 * 4 + -0x9ae3) =
             *(int *)(this[1].m_SiegeOn + iVar2 * 4 + -0x9ae3) + 1;
      }
    }
  }
LAB_4fc41e8e:
  if (((char)this->m_LastCPUPlan[6] == '\0') && (this[1]._padding_ * 0xb4 < this[1]._padding_)) {
    iVar2 = this[1]._padding_;
    *(undefined1 *)(this->m_LastCPUPlan + 6) = 1;
    if (iVar2 < 0x10) {
      piVar7 = this->m_CPUAIDifficultyAddon + iVar2 + 1;
      do {
        bVar1 = IsAround(*piVar7);
        if (bVar1) {
          uVar4 = this[1]._padding_ & 0x80000001;
          if ((int)uVar4 < 0) {
            uVar4 = (uVar4 - 1 | 0xfffffffe) + 1;
          }
          uVar4 = uVar4 & 0x80000001;
          if ((int)uVar4 < 0) {
            uVar4 = (uVar4 - 1 | 0xfffffffe) + 1;
          }
          if (uVar4 == 1) {
            AVar5 = AIPType3;
          }
          else {
            AVar5 = AIPType1;
          }
          SetCPUAIPlan(this,AVar5,iVar2);
        }
        iVar2 = iVar2 + 1;
        piVar7 = piVar7 + 1;
      } while (iVar2 < 0x10);
    }
  }
  return;
}


// ---------------------------------------------------------------------
// instantMission::DeleteObject  @ 4fc41a88  lines 649-684


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall instantMission::DeleteObject(instantMission *this,int param_1)

{
  bool *pbVar1;
  int iVar2;
  int iVar3;
  char local_48 [64];
  undefined4 local_8;
  
  local_8 = __security_cookie ^ (uint)(local_48 + 0x44);
  if (*(char *)((int)this->m_CPUCommBunkerCount + 0x16) == '\0') {
    LuaMission::DeleteObject((LuaMission *)this,param_1);
  }
  GetObjInfo(param_1,Get_GOClass,local_48);
  iVar2 = GetTeamNum(param_1);
  iVar3 = GetTeamNum(param_1);
  if (iVar3 == this[1]._padding_) {
    iVar3 = _stricmp(local_48,"CLASS_ASSAULTTANK");
    if ((iVar3 != 0) && (iVar3 = _stricmp(local_48,"CLASS_WALKER"), iVar3 != 0)) {
      return;
    }
    pbVar1 = this[1].m_SiegeOn + iVar2 * 4 + -0x9ae3;
    *(int *)pbVar1 = *(int *)pbVar1 + -1;
    if (*(int *)pbVar1 < 0) {
      pbVar1 = this[1].m_SiegeOn + iVar2 * 4 + -0x9ae3;
      pbVar1[0] = false;
      pbVar1[1] = false;
      pbVar1[2] = false;
      pbVar1[3] = false;
      return;
    }
    return;
  }
  iVar3 = _stricmp(local_48,"CLASS_COMMBUNKER");
  if ((iVar3 == 0) || (iVar3 = _stricmp(local_48,"CLASS_COMMTOWER"), iVar3 == 0)) {
    *(int *)(this[1].m_SiegeOn + iVar2 * 4 + -0x99a7) =
         *(int *)(this[1].m_SiegeOn + iVar2 * 4 + -0x99a7) + -1;
  }
  iVar3 = _stricmp(local_48,"CLASS_ARMORY");
  if (iVar3 == 0) {
    *(undefined1 *)((int)this->m_LastCPUPlan + iVar2 + 7) = 0;
  }
  return;
}


// ---------------------------------------------------------------------
// instantMission::CreateObjectives  @ 4fc41955  lines 687-730


void __thiscall instantMission::CreateObjectives(instantMission *this)

{
  int iVar1;
  char *pcVar2;
  
  iVar1 = GetInstantGoal();
  this[1]._padding_ = iVar1;
  if (iVar1 == 0) {
    iVar1 = BuildObject("apcamr",0,"flag");
    this->m_CustomAIPInts[7] = iVar1;
    if (iVar1 == 0) {
      return;
    }
    SetObjectiveOn(iVar1);
    SetObjectiveName(this->m_CustomAIPInts[7],"Capture Target");
    ClearObjectives();
    pcVar2 = "inst0101.otf";
  }
  else if (iVar1 == 1) {
    iVar1 = BuildObject("mbruin01",this[1]._padding_,"objective1");
    this->m_CustomAIPInts[7] = iVar1;
    if (iVar1 == 0) {
      this->m_CustomAIPInts[7] = -1;
      return;
    }
    SetObjectiveOn(iVar1);
    SetObjectiveName(this->m_CustomAIPInts[7],"Destroy Target");
    ClearObjectives();
    pcVar2 = "inst0102.otf";
  }
  else {
    if (iVar1 != 2) {
      return;
    }
    iVar1 = BuildObject("mbruin01",1,"objective2");
    this->m_CustomAIPInts[7] = iVar1;
    if (iVar1 == 0) {
      return;
    }
    SetObjectiveOn(iVar1);
    SetObjectiveName(this->m_CustomAIPInts[7],"Protect Target");
    ClearObjectives();
    pcVar2 = "inst0103.otf";
  }
  AddObjective(pcVar2,-1,8.0);
  return;
}


// ---------------------------------------------------------------------
// instantMission::TestObjectives  @ 4fc417e2  lines 733-879


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall instantMission::TestObjectives(instantMission *this)

{
  bool bVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int unaff_EDI;
  int *local_34;
  int local_30;
  char local_18 [16];
  undefined4 local_8;
  
  local_8 = __security_cookie ^ (uint)(local_18 + 0x14);
  iVar7 = 0;
  if (this[1]._padding_ == 0) {
    local_18[0] = '\0';
    local_18[1] = '\0';
    local_18[2] = '\0';
    local_18[3] = '\0';
    local_34 = this->m_CPUAIDifficultyAddon + 2;
    local_18[4] = '\0';
    local_18[5] = '\0';
    local_18[6] = '\0';
    local_18[7] = '\0';
    local_18[8] = '\0';
    local_18[9] = '\0';
    local_18[10] = '\0';
    local_18[0xb] = '\0';
    local_18[0xc] = '\0';
    local_18[0xd] = '\0';
    local_18[0xe] = '\0';
    local_18[0xf] = '\0';
    local_30 = 1;
    do {
      iVar3 = *local_34;
      if (iVar3 != 0) {
        bVar1 = IsAround(iVar3);
        if (!bVar1) {
          iVar3 = GetObjectByTeamSlot(local_30,1);
        }
        bVar1 = IsAround(iVar3);
        if (bVar1) {
LAB_4fc4185d:
          if (iVar3 != 0) goto LAB_4fc41861;
          bVar1 = false;
          *local_34 = 0;
        }
        else {
          if (iVar3 == 0) {
            iVar3 = GetObjectByTeamSlot(local_30,1);
            goto LAB_4fc4185d;
          }
LAB_4fc41861:
          bVar1 = true;
        }
        if ((local_18[local_34[0x142]] != '\0') || (cVar2 = '\0', bVar1)) {
          cVar2 = '\x01';
        }
        local_18[local_34[0x142]] = cVar2;
      }
      local_30 = local_30 + 1;
      local_34 = local_34 + 1;
    } while (local_30 < 0x10);
    iVar5 = 1;
    iVar3 = 0;
    do {
      iVar4 = iVar3 + 1;
      if (local_18[iVar5] == '\0') {
        iVar4 = iVar3;
      }
      iVar5 = iVar5 + 1;
      iVar3 = iVar4;
    } while (iVar5 < 0x10);
    if (iVar4 == 0) {
      if (this[1]._padding_ * 5 < this[1]._padding_) {
LAB_4fc418c5:
        DoTaunt(unaff_EDI);
        (*misnImport.FailMission)(misnImport.time + ___real_40a00000,"instantl.txt");
LAB_4fc418ed:
        this[1]._padding_ = this[1]._padding_ + 1;
      }
    }
    else if (iVar4 == 1) {
      piVar6 = &this[1]._padding_;
      do {
        if (local_18[*piVar6] != '\0') {
          if (iVar7 != this[1]._padding_) goto LAB_4fc418c5;
          DoTaunt(unaff_EDI);
          (*misnImport.SucceedMission)(misnImport.time + ___real_40a00000,"instantw.txt");
          goto LAB_4fc418ed;
        }
        iVar7 = iVar7 + 1;
        piVar6 = piVar6 + 1;
      } while (iVar7 < 0x10);
    }
  }
  return;
}


// ---------------------------------------------------------------------
// instantMission::Execute  @ 4fc417b1  lines 931-944


void __thiscall instantMission::Execute(instantMission *this)

{
  int iVar1;
  
  if (*(char *)((int)this->m_CPUCommBunkerCount + 0x16) == '\0') {
    LuaMission::Execute((LuaMission *)this);
  }
  this[1]._padding_ = this[1]._padding_ + 1;
  iVar1 = GetPlayerHandle();
  this[1]._padding_ = this[1]._padding_ + 1;
  this->m_CPUAIDifficultyAddon[0] = iVar1;
                    /* WARNING: Could not recover jumptable at 0x4fc417df. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(this->_padding_ + 100))();
  return;
}


// ---------------------------------------------------------------------
// instantMission::Load  @ 4fc41607  lines 949-1003


bool __thiscall instantMission::Load(instantMission *this,bool param_1)

{
  bool *pbVar1;
  bool bVar2;
  int iVar3;
  char *unaff_EBX;
  int *unaff_ESI;
  bool local_5;
  
  local_5 = LuaMission::Load((LuaMission *)this,param_1);
  InitTaunts(&this[1]._padding_,(int *)"Computer Team",unaff_ESI,unaff_EBX);
  pbVar1 = (bool *)this[1]._padding_;
  if (param_1) {
    if (((pbVar1 != (bool *)0x0) && (this[1]._padding_ != 0)) && (iVar3 = 0, 0 < this[1]._padding_))
    {
      do {
        *(undefined1 *)(iVar3 + this[1]._padding_) = 0;
        iVar3 = iVar3 + 1;
      } while (iVar3 < this[1]._padding_);
    }
    if (((this[1]._padding_ != 0) && (this[1]._padding_ != 0)) && (iVar3 = 0, 0 < this[1]._padding_)
       ) {
      do {
        *(undefined4 *)(this[1]._padding_ + iVar3 * 4) = 0;
        iVar3 = iVar3 + 1;
      } while (iVar3 < this[1]._padding_);
    }
    if (((this[1]._padding_ != 0) && (this[1]._padding_ != 0)) && (iVar3 = 0, 0 < this[1]._padding_)
       ) {
      do {
        *(undefined4 *)(this[1]._padding_ + iVar3 * 4) = 0;
        iVar3 = iVar3 + 1;
      } while (iVar3 < this[1]._padding_);
    }
    if (((this[1]._padding_ != 0) && (this[1]._padding_ != 0)) && (iVar3 = 0, 0 < this[1]._padding_)
       ) {
      do {
        *(undefined4 *)(this[1]._padding_ + iVar3 * 4) = 0;
        iVar3 = iVar3 + 1;
      } while (iVar3 < this[1]._padding_);
    }
    (**(code **)(this->_padding_ + 0x68))();
  }
  else {
    if (pbVar1 != (bool *)0x0) {
      if ((!local_5) || (bVar2 = Read(pbVar1,this[1]._padding_), !bVar2)) {
        local_5 = false;
      }
      else {
        local_5 = true;
      }
    }
    if ((float *)this[1]._padding_ != (float *)0x0) {
      if ((local_5 == false) || (bVar2 = Read((float *)this[1]._padding_,this[1]._padding_), !bVar2)
         ) {
        local_5 = false;
      }
      else {
        local_5 = true;
      }
    }
    if ((int *)this[1]._padding_ != (int *)0x0) {
      if ((local_5 == false) || (bVar2 = Read((int *)this[1]._padding_,this[1]._padding_), !bVar2))
      {
        local_5 = false;
      }
      else {
        local_5 = true;
      }
    }
    if ((int *)this[1]._padding_ == (int *)0x0) {
      return local_5;
    }
    if ((local_5 == false) || (bVar2 = Read((int *)this[1]._padding_,this[1]._padding_), !bVar2)) {
      return false;
    }
  }
  return true;
}


// ---------------------------------------------------------------------
// instantMission::Save  @ 4fc41523  lines 1006-1035


bool __thiscall instantMission::Save(instantMission *this,bool param_1)

{
  bool bVar1;
  char *unaff_EBX;
  int *unaff_ESI;
  
  bVar1 = LuaMission::Save((LuaMission *)this,param_1);
  InitTaunts(&this[1]._padding_,(int *)"Computer Team",unaff_ESI,unaff_EBX);
  if (param_1) {
    return true;
  }
  if ((bool *)this[1]._padding_ != (bool *)0x0) {
    if ((bVar1) && (bVar1 = Write((bool *)this[1]._padding_,this[1]._padding_), bVar1)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
  }
  if ((float *)this[1]._padding_ != (float *)0x0) {
    if ((bVar1) && (bVar1 = Write((float *)this[1]._padding_,this[1]._padding_), bVar1)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
  }
  if ((int *)this[1]._padding_ != (int *)0x0) {
    if ((bVar1) && (bVar1 = Write((int *)this[1]._padding_,this[1]._padding_), bVar1)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
  }
  if ((int *)this[1]._padding_ != (int *)0x0) {
    if ((bVar1) && (bVar1 = Write((int *)this[1]._padding_,this[1]._padding_), bVar1)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
  }
  return bVar1;
}


// ---------------------------------------------------------------------
// instantMission::PostLoad  @ 4fc414ef  lines 1038-1051


bool __thiscall instantMission::PostLoad(instantMission *this,bool param_1)

{
  LuaMission::PostLoad((LuaMission *)this,param_1);
  if ((!param_1) && ((int *)this[1]._padding_ != (int *)0x0)) {
    ConvertHandles((int *)this[1]._padding_,this[1]._padding_);
  }
  return true;
}


// ---------------------------------------------------------------------
// instantMission::DoGenericStrategy  @ 4fc3fed9  lines 1059-1637


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall instantMission::DoGenericStrategy(instantMission *this)

{
  bool *pbVar1;
  Vector VVar2;
  char cVar3;
  bool bVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  Vector *pVVar8;
  undefined4 *puVar9;
  int *piVar10;
  instantMission *this_00;
  instantMission *this_01;
  instantMission *extraout_ECX;
  instantMission *piVar11;
  instantMission *this_02;
  code *pcVar12;
  char *unaff_ESI;
  code *pcVar13;
  char *unaff_EDI;
  bool *pbVar14;
  char (*pacVar15) [64];
  char *pcVar16;
  uint uVar17;
  undefined4 uVar18;
  AIPType AVar19;
  float fVar20;
  undefined1 local_3a4 [12];
  undefined1 local_398 [12];
  undefined1 local_38c [12];
  undefined1 local_380 [12];
  undefined1 local_374 [12];
  undefined1 local_368 [12];
  undefined1 local_35c [12];
  undefined1 local_350 [12];
  undefined1 local_344 [12];
  code *local_338;
  code *local_334;
  int local_330;
  code *local_32c;
  code *local_328;
  code *local_324;
  code *local_320;
  int local_31c;
  code *local_318;
  code *local_314;
  Vector local_310;
  undefined4 local_304;
  undefined4 uStack_300;
  undefined4 uStack_2fc;
  undefined1 local_2f8 [12];
  int *local_2ec;
  code *local_2e8;
  int local_2e4;
  int *local_2e0;
  instantMission *local_2dc;
  int *local_2d8;
  int local_2d4;
  bool *local_2d0;
  code *local_2cc;
  char local_2c8 [64];
  undefined1 local_288 [64];
  char local_248 [64];
  char local_208 [64];
  undefined1 local_1c8 [64];
  char local_188 [64];
  char local_148;
  char local_147;
  char local_108 [64];
  char local_c8 [64];
  char local_88 [64];
  char local_48 [64];
  undefined4 local_8;
  
  pcVar13 = BuildObject_exref;
  local_8 = __security_cookie ^ (uint)(local_48 + 0x44);
  local_314 = IsAround_exref;
  this[1]._padding_ = this[1]._padding_ + 1;
  pcVar12 = (code *)this[1]._padding_;
  local_324 = pcVar13;
  local_2dc = this;
  if (*(char *)((int)this->m_CPUCommBunkerCount + 0x15) == '\0') {
    *(undefined1 *)((int)this->m_CPUCommBunkerCount + 0x15) = 1;
    iVar5 = GetInstantGoal();
    this[1]._padding_ = iVar5;
    iVar5 = IFace_GetInteger("options.instant.bool0");
    *(bool *)((int)this->m_LastCPUPlan + 0x19) = iVar5 != 0;
    *(undefined4 *)this[1]._padding_ = 0;
    iVar5 = IFace_GetInteger("options.instant.awarev13");
    this[1]._padding_ = iVar5;
    local_2d0 = (bool *)Ally_exref;
    local_328 = GetPlayerHandle_exref;
    local_2e8 = GetPosition_exref;
    local_32c = IFace_GetString_exref;
    local_320 = DoesODFExist_exref;
    if (iVar5 == 0) {
      iVar5 = GetInstantMySide();
      if (iVar5 == 1) {
        pbVar14 = this[1].m_SiegeOn + this[1]._padding_ * 4 + -0x9a7f;
        pbVar14[0] = true;
        pbVar14[1] = false;
        pbVar14[2] = false;
        pbVar14[3] = false;
        this[1]._padding_ = 0x69;
      }
      else {
        pbVar14 = this[1].m_SiegeOn + this[1]._padding_ * 4 + -0x9a7f;
        pbVar14[0] = true;
        pbVar14[1] = false;
        pbVar14[2] = false;
        pbVar14[3] = false;
        this[1]._padding_ = 0x66;
      }
    }
    else {
      IFace_GetString("options.instant.string0",(char *)this[1]._padding_,this[1]._padding_);
      local_2d8 = (int *)this[1]._padding_;
      if ((int)local_2d8 < 0x10) {
        local_2ec = &this[1]._padding_;
        local_2e4 = (int)local_2d8 * 4 + 0xa9ac;
        piVar10 = local_2e0;
        do {
          local_2e0 = piVar10;
          if (local_2d8 == (int *)this[1]._padding_) {
            iVar5 = IFace_GetInteger("options.instant.hisrace");
          }
          else {
            sprintf_s<64>(&local_208,"options.instant.int%d");
            iVar5 = IFace_GetInteger(local_208);
          }
          *(int *)(this->m_SiegeOn + local_2e4 + -0x9e1b) = iVar5;
          iVar5 = IFace_GetInteger("options.instant.int16");
          this[1]._padding_ = iVar5;
          if (iVar5 < 1) {
            this[1]._padding_ = 1;
          }
          memset(local_108,0,0x40);
          local_2e0 = (int *)0xa;
          iVar5 = 2;
          piVar10 = local_2ec;
          do {
            sprintf_s<64>(&local_108,"options.instant.int%d");
            iVar6 = IFace_GetInteger(local_108);
            *piVar10 = iVar6;
            if (iVar6 < 1) {
              *piVar10 = iVar5;
            }
            piVar10 = piVar10 + 1;
            iVar5 = iVar5 + 1;
            local_2e0 = (int *)((int)local_2e0 + -1);
          } while (local_2e0 != (int *)0x0);
          local_2e4 = local_2e4 + 4;
          local_2d8 = (int *)((int)local_2d8 + 1);
          local_2e0 = (int *)0x0;
          this = local_2dc;
          piVar10 = (int *)0x0;
        } while (local_2e4 < 0xa9ec);
      }
      iVar5 = IFace_GetInteger("options.instant.myrace");
      this[1]._padding_ = iVar5;
      local_2d8 = &this[1]._padding_;
      iVar5 = 1;
      do {
        local_2e0 = &this[1]._padding_;
        iVar6 = 1;
        piVar10 = local_2d8;
        do {
          if (((0 < *piVar10) && (iVar5 != iVar6)) && (*piVar10 == *local_2e0)) {
            (*(code *)local_2d0)(iVar5,iVar6);
            *(undefined1 *)((int)this->m_LastCPUPlan + iVar5 + 0x1a) = 1;
            piVar10 = local_2d8;
          }
          iVar6 = iVar6 + 1;
          local_2e0 = local_2e0 + 1;
        } while (iVar6 < 0x10);
        iVar5 = iVar5 + 1;
        local_2d8 = piVar10 + 1;
      } while (iVar5 < 0x10);
      iVar6 = (*local_328)();
      local_2ec = (int *)GetTeamNum(iVar6);
      (*local_2e8)(iVar6,&local_310);
      iVar5 = this[1]._padding_;
      pacVar15 = &local_c8;
      pcVar16 = "%cvscout_vsr";
      sprintf_s<64>(pacVar15,"%cvscout_vsr");
      cVar3 = (*local_320)(local_c8,pacVar15,pcVar16,iVar5);
      pcVar13 = local_324;
      if (cVar3 == '\0') {
        sprintf_s<64>(&local_c8,"%cvscout");
      }
      bVar4 = GetObjInfo(iVar6,Get_CFG,&local_148);
      if ((bVar4) && (local_147 == 's')) {
        sprintf_s<64>(&local_c8,"%cspilo");
      }
      RemoveObject(iVar6);
      piVar10 = local_2ec;
      iVar5 = BuildObject(local_c8,(int)local_2ec,&local_310);
      SetAsUser(iVar5,(int)piVar10);
    }
    iVar5 = GetInstantMyForce();
    this[1]._padding_ = iVar5;
    iVar5 = GetInstantCompForce();
    this[1]._padding_ = iVar5;
    iVar5 = GetInstantDifficulty();
    pbVar14 = local_2d0;
    this[1]._padding_ = iVar5;
    if (this[1]._padding_ == 0) {
      this[1]._padding_ = 3;
      (*(code *)local_2d0)(3,1);
      (*(code *)pbVar14)(1,3);
      if (*(int *)(this[1].m_SiegeOn + this[1]._padding_ * 4 + -0x9a7f) == 0x66) {
        pcVar16 = "fvsent";
      }
      else {
        pcVar16 = "ivmisl";
      }
      iVar5 = (*pcVar13)(pcVar16,this[1]._padding_,"tankEnemy1");
      Attack(iVar5,this->m_CPUAIDifficultyAddon[0],1);
    }
    else {
      this[1]._padding_ = 1;
    }
    SetupExtraVehicles(this);
    local_2d4 = this[1]._padding_;
    local_334 = GetPathPoints_exref;
    local_2ec = (int *)GetODFString_exref;
    local_2cc = GetPositionNear_exref;
    local_2e0 = (int *)strchr_exref;
    local_2d8 = (int *)strcpy_s_exref;
    if (local_2d4 < 0x10) {
      local_2e4 = local_2d4 * 4 + 0xa9ac;
      local_2d0 = this[1].m_SiegeOn + local_2d4 * 4 + -0x9a7f;
      local_318 = SetTeamNameForStat_exref;
      local_338 = GetBZCCLocalizedString_exref;
      do {
        pbVar14 = local_2d0;
        iVar5 = local_2d4;
        if (*(int *)local_2d0 != 0) {
          pacVar15 = (char (*) [64])&local_148;
          pcVar16 = "Enemy_%d";
          iVar6 = local_2d4;
          sprintf_s<64>(pacVar15,"Enemy_%d");
          local_31c = 0;
          (*local_334)(&local_148,&local_31c,0,pacVar15,pcVar16,iVar6);
          if (local_31c == 0) {
            if (this[1]._padding_ < iVar5) break;
            sprintf_s<64>((char (*) [64])&local_148,"RecyclerEnemy");
          }
          (*local_32c)("options.instant.string2",local_188,0x40);
          cVar3 = (*local_320)(local_188);
          if (cVar3 == '\0') {
            sprintf_s<64>(&local_188,"*vrecycpu");
          }
          if (local_188[0] == '\0') {
            pcVar16 = "*vrecycpu";
            piVar11 = (instantMission *)&local_148;
          }
          else {
            pcVar16 = local_188;
            piVar11 = (instantMission *)pcVar16;
          }
          iVar6 = BuildStartingVehicle
                            (piVar11,iVar5,*(int *)(this->m_SiegeOn + local_2e4 + -0x9e1b),pcVar16,
                             "*vrecy",&local_148,-1,(char *)0x0);
          *(int *)(pbVar14 + -0x4c4) = iVar6;
          memset(local_208,0,0x40);
          pacVar15 = &local_208;
          pcVar16 = "Computer Team %d";
          iVar6 = iVar5;
          sprintf_s<64>(pacVar15,"Computer Team %d");
          uVar7 = (*local_338)("cfg",local_208,pacVar15,pcVar16,iVar6);
          (*local_318)(iVar5,uVar7);
          memset(local_108,0,0x40);
          memset(local_c8,0,0x40);
          pcVar16 = local_48;
          uVar17 = 0;
          memset(pcVar16,0,0x40);
          CombineStrings(".odf",(char *)0x40,pcVar16,uVar17);
          bVar4 = OpenODF2(unaff_EDI);
          if (bVar4) {
            iVar5 = (*(code *)local_2ec)(local_108,"GameObjectClass","classlabel",0x40,local_c8,0);
            if (iVar5 != 0) {
              CombineStrings(".odf",(char *)0x40,unaff_EDI,(uint)unaff_ESI);
              OpenODF2(unaff_EDI);
            }
            iVar5 = GetODFString("GameObjectClass","startingVariant",(char *)0x40,local_48,0,
                                 unaff_EDI,unaff_ESI);
            if ((iVar5 == 0) && (iVar5 = (*(code *)local_2e0)(local_188,0x5f), iVar5 != 0)) {
              iVar5 = iVar5 + 1;
              iVar6 = (*(code *)local_2e0)(iVar5,0x5f);
              if (iVar6 != 0) {
                iVar5 = iVar6 + 1;
              }
              (*(code *)local_2d8)(local_48,0x40,iVar5);
            }
          }
          (*local_2e8)(*(int *)(pbVar14 + -0x4c4),&local_310);
          pVVar8 = (Vector *)
                   (*local_2cc)(local_3a4,local_310.x,local_310.y,local_310.z,0x41f00000,0x42700000)
          ;
          BuildStartingVehicle
                    ((instantMission *)local_48,local_2d4,*(int *)local_2d0,"*vscav","*vscav",
                     *pVVar8,-1,local_48);
          pVVar8 = (Vector *)
                   (*local_2cc)(local_344,local_310.x,local_310.y,local_310.z,0x41f00000,0x42700000)
          ;
          BuildStartingVehicle
                    ((instantMission *)local_48,local_2d4,*(int *)local_2d0,"*vturr","*vturr",
                     *pVVar8,-1,local_48);
          pVVar8 = (Vector *)
                   (*local_2cc)(local_350,local_310.x,local_310.y,local_310.z,0x41f00000,0x42700000)
          ;
          pbVar14 = local_2d0;
          iVar5 = local_2d4;
          BuildStartingVehicle
                    ((instantMission *)local_48,local_2d4,*(int *)local_2d0,"*vturr","*vturr",
                     *pVVar8,-1,local_48);
          piVar11 = this_00;
          if (0 < this[1]._padding_) {
            if (iVar5 == this[1]._padding_) {
              BuildStartingVehicle
                        (this_00,iVar5,*(int *)pbVar14,"*bspir","*vturr","gtow2",-1,local_48);
              BuildStartingVehicle
                        (this_01,iVar5,*(int *)pbVar14,"*bspir","*vturr","gtow3",-1,local_48);
            }
            pVVar8 = (Vector *)
                     (*local_2cc)(local_35c,local_310.x,local_310.y,local_310.z,0x41f00000,
                                  0x42700000);
            BuildStartingVehicle
                      ((instantMission *)local_48,local_2d4,*(int *)local_2d0,"*vsent","*vscout",
                       *pVVar8,-1,local_48);
            pVVar8 = (Vector *)
                     (*local_2cc)(local_368,local_310.x,local_310.y,local_310.z,0x41f00000,
                                  0x42700000);
            pbVar14 = local_2d0;
            iVar5 = local_2d4;
            BuildStartingVehicle
                      ((instantMission *)local_48,local_2d4,*(int *)local_2d0,"*vsent","*vscout",
                       *pVVar8,-1,local_48);
            piVar11 = extraout_ECX;
          }
          if (1 < this[1]._padding_) {
            if (iVar5 == this[1]._padding_) {
              BuildStartingVehicle
                        (piVar11,iVar5,*(int *)pbVar14,"*bspir","*vturr","gtow4",-1,local_48);
              BuildStartingVehicle
                        (this_02,iVar5,*(int *)pbVar14,"*bspir","*vturr","gtow5",-1,local_48);
            }
            pVVar8 = (Vector *)
                     (*local_2cc)(local_374,local_310.x,local_310.y,local_310.z,0x41f00000,
                                  0x42700000);
            BuildStartingVehicle
                      ((instantMission *)local_48,local_2d4,*(int *)local_2d0,"*vtank","*vtank",
                       *pVVar8,-1,local_48);
            pVVar8 = (Vector *)
                     (*local_2cc)(local_380,local_310.x,local_310.y,local_310.z,0x41f00000,
                                  0x42700000);
            BuildStartingVehicle
                      ((instantMission *)local_48,local_2d4,*(int *)local_2d0,"*vtank","*vtank",
                       *pVVar8,-1,local_48);
            pVVar8 = (Vector *)
                     (*local_2cc)(local_38c,local_310.x,local_310.y,local_310.z,0x41f00000,
                                  0x42700000);
            BuildStartingVehicle
                      ((instantMission *)local_48,local_2d4,*(int *)local_2d0,"*vtank","*vtank",
                       *pVVar8,-1,local_48);
            pVVar8 = (Vector *)
                     (*local_2cc)(local_398,local_310.x,local_310.y,local_310.z,0x41f00000,
                                  0x42700000);
            BuildStartingVehicle
                      ((instantMission *)local_48,local_2d4,*(int *)local_2d0,"*vtank","*vtank",
                       *pVVar8,-1,local_48);
            pVVar8 = (Vector *)
                     (*local_2cc)(local_2f8,local_310.x,local_310.y,local_310.z,0x41f00000,
                                  0x42700000);
            pbVar14 = local_2d0;
            iVar5 = local_2d4;
            BuildStartingVehicle
                      ((instantMission *)local_48,local_2d4,*(int *)local_2d0,"*vsent","*vscout",
                       *pVVar8,-1,local_48);
          }
        }
        local_2e4 = local_2e4 + 4;
        local_2d4 = iVar5 + 1;
        local_2d0 = pbVar14 + 4;
      } while (local_2e4 < 0xa9ec);
    }
    piVar10 = local_2e0;
    sprintf_s<64>(&local_2c8,"Player_1");
    local_330 = 0;
    (*local_334)(local_2c8,&local_330,0);
    if (local_330 == 0) {
      sprintf_s<64>(&local_2c8,"Recycler");
    }
    (*local_32c)("options.instant.string1",local_248,0x40);
    if (local_248[0] == '\0') {
      pcVar16 = "*vrecy";
    }
    else {
      pcVar16 = local_248;
    }
    iVar5 = BuildStartingVehicle
                      ((instantMission *)this[1]._padding_,this[1]._padding_,this[1]._padding_,
                       pcVar16,"*vrecy",local_2c8,-2,(char *)0x0);
    this->m_CPUAIDifficultyAddon[this[1]._padding_ + 1] = iVar5;
    memset(local_288,0,0x40);
    memset(local_1c8,0,0x40);
    pcVar16 = local_88;
    uVar17 = 0;
    memset(pcVar16,0,0x40);
    CombineStrings(".odf",(char *)0x40,pcVar16,uVar17);
    bVar4 = OpenODF2(unaff_EDI);
    if (bVar4) {
      iVar5 = (*(code *)local_2ec)(local_288,"GameObjectClass","classlabel",0x40,local_1c8,0);
      if (iVar5 != 0) {
        CombineStrings(".odf",(char *)0x40,unaff_EDI,(uint)unaff_ESI);
        OpenODF2(unaff_EDI);
      }
      iVar5 = GetODFString("GameObjectClass","startingVariant",(char *)0x40,local_88,0,unaff_EDI,
                           unaff_ESI);
      if ((iVar5 == 0) && (iVar5 = (*(code *)piVar10)(local_248,0x5f), iVar5 != 0)) {
        iVar5 = iVar5 + 1;
        iVar6 = (*(code *)piVar10)(iVar5,0x5f);
        if (iVar6 != 0) {
          iVar5 = iVar6 + 1;
        }
        (*(code *)local_2d8)(local_88,0x40,iVar5);
      }
    }
    (*local_2e8)(this->m_CPUAIDifficultyAddon[this[1]._padding_ + 1],&local_304);
    puVar9 = (undefined4 *)
             (*local_2cc)(local_2f8,local_304,uStack_300,uStack_2fc,0x41f00000,0x42700000);
    uVar7 = *puVar9;
    uVar18 = puVar9[1];
    fVar20 = (float)puVar9[2];
    iVar5 = (*local_328)();
    VVar2.y = (float)uVar18;
    VVar2.x = (float)uVar7;
    VVar2.z = fVar20;
    SetVectorPosition(iVar5,VVar2);
    pVVar8 = (Vector *)(*local_2cc)(local_2f8,local_304,uStack_300,uStack_2fc,0x41f00000,0x42700000)
    ;
    BuildStartingVehicle
              ((instantMission *)local_88,this[1]._padding_,this[1]._padding_,"*vscav","*vscav",
               *pVVar8,-2,local_88);
    pVVar8 = (Vector *)(*local_2cc)(local_2f8,local_304,uStack_300,uStack_2fc,0x41f00000,0x42700000)
    ;
    BuildStartingVehicle
              ((instantMission *)local_88,this[1]._padding_,this[1]._padding_,"*vturr","*vturr",
               *pVVar8,-2,local_88);
    pVVar8 = (Vector *)(*local_2cc)(local_2f8,local_304,uStack_300,uStack_2fc,0x41f00000,0x42700000)
    ;
    BuildStartingVehicle
              ((instantMission *)local_88,this[1]._padding_,this[1]._padding_,"*vturr","*vturr",
               *pVVar8,-2,local_88);
    iVar5 = this[1]._padding_;
    if (0 < iVar5) {
      pVVar8 = (Vector *)
               (*local_2cc)(local_2f8,local_304,uStack_300,uStack_2fc,0x41f00000,0x42700000);
      BuildStartingVehicle
                ((instantMission *)local_88,this[1]._padding_,this[1]._padding_,"*vturr","*vturr",
                 *pVVar8,-2,local_88);
      pVVar8 = (Vector *)
               (*local_2cc)(local_2f8,local_304,uStack_300,uStack_2fc,0x41f00000,0x42700000);
      BuildStartingVehicle
                ((instantMission *)local_88,this[1]._padding_,this[1]._padding_,"*vscout","*vscout",
                 *pVVar8,-2,local_88);
      pVVar8 = (Vector *)
               (*local_2cc)(local_2f8,local_304,uStack_300,uStack_2fc,0x41f00000,0x42700000);
      BuildStartingVehicle
                ((instantMission *)local_88,this[1]._padding_,this[1]._padding_,"*vscout","*vscout",
                 *pVVar8,-2,local_88);
      pVVar8 = (Vector *)
               (*local_2cc)(local_2f8,local_304,uStack_300,uStack_2fc,0x41f00000,0x42700000);
      BuildStartingVehicle
                ((instantMission *)local_88,this[1]._padding_,this[1]._padding_,"*vtank","*vtank",
                 *pVVar8,-2,local_88);
      pVVar8 = (Vector *)
               (*local_2cc)(local_2f8,local_304,uStack_300,uStack_2fc,0x41f00000,0x42700000);
      BuildStartingVehicle
                ((instantMission *)local_88,this[1]._padding_,this[1]._padding_,"*vtank","*vtank",
                 *pVVar8,-2,local_88);
      iVar5 = this[1]._padding_;
    }
    if (1 < iVar5) {
      pVVar8 = (Vector *)
               (*local_2cc)(local_2f8,local_304,uStack_300,uStack_2fc,0x41f00000,0x42700000);
      BuildStartingVehicle
                ((instantMission *)local_88,this[1]._padding_,this[1]._padding_,"*vscout","*vscout",
                 *pVVar8,-2,local_88);
      pVVar8 = (Vector *)
               (*local_2cc)(local_2f8,local_304,uStack_300,uStack_2fc,0x41f00000,0x42700000);
      BuildStartingVehicle
                ((instantMission *)local_88,this[1]._padding_,this[1]._padding_,"*vtank","*vtank",
                 *pVVar8,-2,local_88);
      iVar5 = GetFirstEmptyGroup();
      pVVar8 = (Vector *)
               (*local_2cc)(local_2f8,local_304,uStack_300,uStack_2fc,0x41f00000,0x42700000);
      BuildStartingVehicle
                ((instantMission *)local_88,local_2dc[1]._padding_,local_2dc[1]._padding_,"*vtank",
                 "*vtank",*pVVar8,iVar5,local_88);
      pVVar8 = (Vector *)
               (*local_2cc)(local_2f8,local_304,uStack_300,uStack_2fc,0x41f00000,0x42700000);
      BuildStartingVehicle
                ((instantMission *)local_88,local_2dc[1]._padding_,local_2dc[1]._padding_,"*vtank",
                 "*vtank",*pVVar8,iVar5,local_88);
      pVVar8 = (Vector *)
               (*local_2cc)(local_2f8,local_304,uStack_300,uStack_2fc,0x41f00000,0x42700000);
      this = local_2dc;
      BuildStartingVehicle
                ((instantMission *)local_88,local_2dc[1]._padding_,local_2dc[1]._padding_,"*vtank",
                 "*vtank",*pVVar8,iVar5,local_88);
    }
    if ((this[1]._padding_ == 0) && (this[1]._padding_ == 0)) {
      if (this[1]._padding_ == 0x69) {
        pcVar16 = "isdfteam.aip";
      }
      else {
        pcVar16 = "scionteam.aip";
      }
      SetPlan(pcVar16,this[1]._padding_);
    }
    if (((char)this->m_LastCPUPlan[6] == '\0') && (iVar5 = this[1]._padding_, iVar5 < 0x10)) {
      piVar10 = this->m_CPUAIDifficultyAddon + iVar5 + 1;
      do {
        cVar3 = (*local_314)(*piVar10);
        if (cVar3 != '\0') {
          SetCPUAIPlan(this,AIPType0,iVar5);
        }
        iVar5 = iVar5 + 1;
        piVar10 = piVar10 + 1;
      } while (iVar5 < 0x10);
    }
    pcVar13 = local_324;
    (*local_324)("apammo",0,"ammo1");
    (*pcVar13)("apammo",0,"ammo2");
    (*pcVar13)("apammo",0,"ammo3");
    (*pcVar13)("aprepa",0,"repair1");
    (*pcVar13)("aprepa",0,"repair2");
    (*pcVar13)("aprepa",0,"repair3");
    (*misnImport.SetScrap)(this[1]._padding_,0x28);
    (*misnImport.SetScrap)(1,0x28);
    pcVar12 = (code *)this[1]._padding_;
  }
  iVar5 = this[1]._padding_;
  if (iVar5 != 0) {
    if (iVar5 == 0) {
      local_2e8 = (code *)(this[1]._padding_ * 3);
    }
    else if (iVar5 == 1) {
      local_2e8 = (code *)(this[1]._padding_ * 2);
    }
    else {
      if (iVar5 != 2) goto LAB_4fc41218;
      local_2e8 = (code *)this[1]._padding_;
    }
    if (((0 < (int)local_2e8) && ((int)pcVar12 % (int)local_2e8 == 0)) && (this[1]._padding_ < 0x10)
       ) {
      iVar5 = 0x10 - this[1]._padding_;
      do {
        (*misnImport.AddScrap)(this[1]._padding_,1);
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
      pcVar12 = (code *)this[1]._padding_;
    }
  }
LAB_4fc41218:
  iVar5 = this[1]._padding_;
  if (iVar5 != 0) {
    if (iVar5 == 0) {
      iVar5 = this[1]._padding_ * 10;
    }
    else if (iVar5 == 1) {
      iVar5 = this[1]._padding_ << 3;
    }
    else {
      if (iVar5 != 2) goto LAB_4fc41283;
      iVar5 = this[1]._padding_ * 6;
    }
    if ((0 < iVar5) && (local_318 = pcVar12, (int)pcVar12 % iVar5 == 0)) {
      (*misnImport.AddScrap)(this[1]._padding_,1);
      pcVar12 = (code *)this[1]._padding_;
    }
  }
LAB_4fc41283:
  if ((int)pcVar12 % this[1]._padding_ == 0) {
    (*pcVar13)("apammo",0,"ammo1");
    (*pcVar13)("apammo",0,"ammo2");
    (*pcVar13)("apammo",0,"ammo3");
    (*pcVar13)("aprepa",0,"repair1");
    (*pcVar13)("aprepa",0,"repair2");
    (*pcVar13)("aprepa",0,"repair3");
  }
  pcVar12 = local_314;
  if ((this[1]._padding_ == 0) &&
     (this[1]._padding_ = this[1]._padding_ + 1, this[1]._padding_ % (this[1]._padding_ * 0x14) == 0
     )) {
    cVar3 = (*local_314)(this->m_CPUMaxPatrolUnits[1]);
    if (cVar3 == '\0') {
      iVar5 = (*pcVar13)("apshdw",0,"power1");
      this->m_CPUMaxPatrolUnits[1] = iVar5;
    }
    cVar3 = (*pcVar12)(this->m_CPUMaxPatrolUnits[2]);
    if (cVar3 == '\0') {
      iVar5 = (*pcVar13)("apsstb",0,"power2");
      this->m_CPUMaxPatrolUnits[2] = iVar5;
    }
    cVar3 = (*pcVar12)(this->m_CPUMaxPatrolUnits[3]);
    if (cVar3 == '\0') {
      iVar5 = (*pcVar13)("apffld",0,"power3");
      this->m_CPUMaxPatrolUnits[3] = iVar5;
    }
    cVar3 = (*pcVar12)(this->m_CPUMaxPatrolUnits[4]);
    if (cVar3 == '\0') {
      iVar5 = (*pcVar13)("apspln",0,"power4");
      this->m_CPUMaxPatrolUnits[4] = iVar5;
    }
  }
  iVar5 = this[1]._padding_;
  if (iVar5 < 0x10) {
    local_2dc = (instantMission *)(iVar5 * 4 + 0xa908);
    pbVar14 = this[1].m_SiegeOn + iVar5 * 4 + -0x9b23;
    do {
      cVar3 = (*local_314)(*(int *)(pbVar14 + -0x420));
      if (cVar3 != '\0') {
        if (*(char *)((int)this->m_CPUCommBunkerCount + iVar5 + 0x17) == '\0') {
          iVar6 = GetNearestEnemy(*(int *)(pbVar14 + -0x420),true,true,250.0);
          if (iVar6 == 0) {
            iVar6 = 0;
            pbVar1 = this->m_SiegeOn + (int)local_2dc + -0x9e1b;
            pbVar1[0] = false;
            pbVar1[1] = false;
            pbVar1[2] = false;
            pbVar1[3] = false;
          }
          else {
            iVar6 = *(int *)(this->m_SiegeOn + (int)local_2dc + -0x9e1b) + 1;
            *(int *)pbVar14 = iVar6;
          }
          if (this[1]._padding_ * 0x2d < iVar6) {
            *(undefined1 *)((int)this->m_CPUCommBunkerCount + iVar5 + 0x17) = 1;
            SetCPUAIPlan(this,AIPTypeS,iVar5);
          }
        }
        else {
          iVar6 = GetNearestEnemy(*(int *)(pbVar14 + -0x420),true,true,250.0);
          if ((iVar6 == 0) && (SetCPUAIPlan(this,AIPTypeL,iVar5), *(int *)(pbVar14 + 0x1bc) == 5)) {
            *(undefined1 *)((int)this->m_CPUCommBunkerCount + iVar5 + 0x17) = 0;
            pbVar14[0] = false;
            pbVar14[1] = false;
            pbVar14[2] = false;
            pbVar14[3] = false;
          }
        }
        if ((*(char *)((int)this->m_CPUCommBunkerCount + iVar5 + 0x37) == '\0') &&
           (*(char *)((int)this->m_CPUCommBunkerCount + iVar5 + 0x17) == '\0')) {
          if (*(char *)((int)this->m_CPUCommBunkerCount + iVar5 + 0x27) != '\0') goto LAB_4fc41499;
          if (*(int *)(this[1].m_SiegeOn + this[1]._padding_ * 4 + -0x9ae3) < 3) goto LAB_4fc4148f;
          *(undefined1 *)((int)this->m_CPUCommBunkerCount + iVar5 + 0x27) = 1;
          AVar19 = AIPTypeA;
LAB_4fc414b4:
          SetCPUAIPlan(this,AVar19,iVar5);
        }
        else {
LAB_4fc4148f:
          if (*(char *)((int)this->m_CPUCommBunkerCount + iVar5 + 0x27) != '\0') {
LAB_4fc41499:
            if (*(int *)(this[1].m_SiegeOn + this[1]._padding_ * 4 + -0x9ae3) < 3) {
              *(undefined1 *)((int)this->m_CPUCommBunkerCount + iVar5 + 0x27) = 0;
              AVar19 = AIPTypeL;
              goto LAB_4fc414b4;
            }
          }
        }
      }
      iVar5 = iVar5 + 1;
      local_2dc = (instantMission *)((int)local_2dc + 4);
      pbVar14 = pbVar14 + 4;
    } while ((int)local_2dc < 0xa948);
  }
  (**(code **)(this->_padding_ + 0x70))();
  return;
}


// ---------------------------------------------------------------------
// instantMission::PlayerEjected  @ 4fc3fe8d  lines 1640-1647


EjectKillRetCodes __thiscall instantMission::PlayerEjected(instantMission *this,int param_1)

{
  EjectKillRetCodes EVar1;
  float fVar2;
  float fVar3;
  
  if (*(char *)((int)this->m_CPUCommBunkerCount + 0x16) == '\0') {
    LuaMission::PlayerEjected((LuaMission *)this,param_1);
  }
  fVar2 = GetRandomFloat(1.0);
  fVar3 = GetEjectRatio(param_1);
  EVar1 = DoEjectPilot;
  if (fVar3 < fVar2) {
    EVar1 = DLLHandled;
  }
  return EVar1;
}


// ---------------------------------------------------------------------
// instantMission::PlayerDied  @ 4fc3fd67  lines 1657-1694


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

EjectKillRetCodes __thiscall
instantMission::PlayerDied(instantMission *this,int param_1,bool param_2)

{
  Vector VVar1;
  bool bVar2;
  Vector *pVVar3;
  int iVar4;
  int unaff_EDI;
  Vector local_60;
  Vector local_54;
  char local_48 [64];
  undefined4 local_8;
  
  local_8 = __security_cookie ^ (uint)(local_48 + 0x44);
  bVar2 = IsPerson(param_1);
  if ((!bVar2) && (!param_2)) {
    return DoEjectPilot;
  }
  if ((*(char *)((int)this->m_LastCPUPlan + 0x19) == '\0') ||
     (bVar2 = IsAlive(this->m_CPUAIDifficultyAddon + this[1]._padding_ + 1), !bVar2)) {
    (*misnImport.FailMission)(misnImport.time + __real_40400000,(char *)0x0);
  }
  else {
    GetPosition(this->m_CPUAIDifficultyAddon[this[1]._padding_ + 1],&local_54);
    VVar1.y = local_54.y;
    VVar1.x = local_54.x;
    VVar1.z = local_54.z;
    pVVar3 = GetPositionNear(&local_60,VVar1,10.0,50.0);
    local_54.x = pVVar3->x;
    local_54.z = pVVar3->z;
    local_54.y = pVVar3->y + ___real_42480000;
    sprintf_s<64>(&local_48,"%cspilo");
    iVar4 = BuildObject(local_48,1,&local_54);
    SetAsUser(iVar4,1);
    AddPilotByHandle(iVar4);
    DoTaunt(unaff_EDI);
  }
  return DLLHandled;
}


// ---------------------------------------------------------------------
// instantMission::ObjectKilled  @ 4fc3fd18  lines 1697-1715


EjectKillRetCodes __thiscall
instantMission::ObjectKilled(instantMission *this,int param_1,int param_2)

{
  bool bVar1;
  EjectKillRetCodes EVar2;
  
  if (*(char *)((int)this->m_CPUCommBunkerCount + 0x16) == '\0') {
    LuaMission::ObjectKilled((LuaMission *)this,param_1,param_2);
  }
  bVar1 = IsPlayer(param_1);
  if (bVar1) {
    EVar2 = PlayerDied(this,param_1,false);
  }
  else {
    bVar1 = IsPerson(param_1);
    EVar2 = -(uint)bVar1 & DLLHandled;
  }
  return EVar2;
}


// ---------------------------------------------------------------------
// instantMission::ObjectSniped  @ 4fc3fcda  lines 1718-1731


EjectKillRetCodes __thiscall
instantMission::ObjectSniped(instantMission *this,int param_1,int param_2)

{
  bool bVar1;
  EjectKillRetCodes EVar2;
  
  if (*(char *)((int)this->m_CPUCommBunkerCount + 0x16) == '\0') {
    LuaMission::ObjectSniped((LuaMission *)this,param_1,param_2);
  }
  bVar1 = IsPlayer(param_1);
  if (bVar1) {
    EVar2 = PlayerDied(this,param_1,true);
  }
  else {
    EVar2 = DLLHandled;
  }
  return EVar2;
}


// ---------------------------------------------------------------------
// instantMission::PreGetIn  @ 4fc3fc7e  lines 1743-1755


PreGetInReturnCodes __thiscall
instantMission::PreGetIn(instantMission *this,int param_1,int param_2,int param_3)

{
  PreGetInReturnCodes PVar1;
  int iVar2;
  
  if (param_1 == 0) {
    PVar1 = LuaMission::PreGetIn((LuaMission *)this,0,param_2,param_3);
    if ((PVar1 == PREGETIN_ALLOW) && (iVar2 = GetTeamNum(param_3), this[1]._padding_ <= iVar2)) {
      DispatchHelper::AddToDispatch
                ((DispatchHelper *)this->_padding_,param_3,15.0,false,0,false,false,false,false);
    }
  }
  else {
    PVar1 = PREGETIN_ALLOW;
  }
  return PVar1;
}


// ---------------------------------------------------------------------
// BuildMission  @ 4fc42902  lines 1758-1760


/* WARNING: Function: _EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: _EH_epilog3 replaced with injection: EH_epilog3 */

DLLBase * __cdecl BuildMission(void)

{
  instantMission *piVar1;
  
  piVar1 = operator_new(0xac50);
  piVar1 = instantMission::instantMission(piVar1);
  return (DLLBase *)piVar1;
}

