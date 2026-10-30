// Reconstructed by Ghidra from Strategy02.dll + Strategy02.pdb
// Original source file: /e:/github/vsr_dll_source/missions/strategy02/strategy02.cpp
// Functions are ordered by original source line. This is decompiler
// output, not the author's source: names/types come from the PDB,
// local variable names and control flow are reconstructed.

// ---------------------------------------------------------------------
// Strategy02::Strategy02  @ 4fc46ea4  lines 72-113

/* WARNING: Function: _EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: _EH_epilog3 replaced with injection: EH_epilog3 */

Strategy02 * __thiscall Strategy02::Strategy02(Strategy02 *this)

{
  char *pTRNName;
  
  LuaMission::LuaMission(&this->super_LuaMission);
  (this->super_LuaMission).super_BZ1Helper.super_DLLBase = (DLLBase)vftable;
  *(undefined4 *)&this->ThugScavengerList = 0;
  *(undefined4 *)&(this->ThugScavengerList).field_0x4 = 0;
  *(undefined4 *)&(this->ThugScavengerList).field_0x8 = 0;
  *(undefined4 *)&this->ThugPilotList = 0;
  *(undefined4 *)&(this->ThugPilotList).field_0x4 = 0;
  *(undefined4 *)&(this->ThugPilotList).field_0x8 = 0;
  *(undefined4 *)&this->EmptyShipList = 0;
  *(undefined4 *)&(this->EmptyShipList).field_0x4 = 0;
  *(undefined4 *)&(this->EmptyShipList).field_0x8 = 0;
  *(undefined4 *)&this->MorphTankList = 0;
  *(undefined4 *)&(this->MorphTankList).field_0x4 = 0;
  *(undefined4 *)&(this->MorphTankList).field_0x8 = 0;
  *(undefined4 *)&this->CommBunkerList = 0;
  *(undefined4 *)&(this->CommBunkerList).field_0x4 = 0;
  *(undefined4 *)&(this->CommBunkerList).field_0x8 = 0;
  this->m_GameTPS = 0x14;
  EnableHighTPS(&this->m_GameTPS);
  AllowRandomTracks(true);
  this->b_count = 0x1be;
  this->b_array = &this->m_DidInit;
  this->f_array = this->m_TeamPos;
  this->h_array = this->m_RecyclerHandles;
  this->f_count = 0x86;
  this->h_count = 0x40;
  this->i_count = 0xff;
  this->i_array = &this->m_TotalGameTime;
  pTRNName = GetMapTRNFilename();
  TRNAllies::SetupTRNAllies(pTRNName);
  if (this->i_array != (int *)0x0) {
    memset(this->i_array,0,this->i_count << 2);
  }
  if (this->f_array != (float *)0x0) {
    memset(this->f_array,0,this->f_count << 2);
  }
  if (this->h_array != (int *)0x0) {
    memset(this->h_array,0,this->h_count << 2);
  }
  if (this->b_array != (bool *)0x0) {
    memset(this->b_array,0,this->b_count);
  }
  memset(this->PlayerShipODF,0,0x3f00);
  return this;
}


// ---------------------------------------------------------------------
// Strategy02::~Strategy02  @ 4fc46d77  lines 115-117

void __thiscall Strategy02::~Strategy02(Strategy02 *this)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 uStack_8;
  
  uStack_8 = 0xffffffff;
  puStack_c = &__ehhandler___1Strategy02__UAE_XZ;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  (this->super_LuaMission).super_BZ1Helper.super_DLLBase = (DLLBase)vftable;
  CleanupTaunts();
  pvVar1 = *(void **)&this->CommBunkerList;
  if (pvVar1 != (void *)0x0) {
    std::_Deallocate<8,0>
              (pvVar1,*(int *)&(this->CommBunkerList).field_0x8 - (int)pvVar1 & 0xfffffff8);
    *(undefined4 *)&this->CommBunkerList = 0;
    *(undefined4 *)&(this->CommBunkerList).field_0x4 = 0;
    *(undefined4 *)&(this->CommBunkerList).field_0x8 = 0;
  }
  pvVar1 = *(void **)&this->MorphTankList;
  if (pvVar1 != (void *)0x0) {
    std::_Deallocate<8,0>
              (pvVar1,*(int *)&(this->MorphTankList).field_0x8 - (int)pvVar1 & 0xfffffff8);
    *(undefined4 *)&this->MorphTankList = 0;
    *(undefined4 *)&(this->MorphTankList).field_0x4 = 0;
    *(undefined4 *)&(this->MorphTankList).field_0x8 = 0;
  }
  pvVar1 = *(void **)&this->EmptyShipList;
  if (pvVar1 != (void *)0x0) {
    std::_Deallocate<8,0>
              (pvVar1,((*(int *)&(this->EmptyShipList).field_0x8 - (int)pvVar1) / 0xc) * 0xc);
    *(undefined4 *)&this->EmptyShipList = 0;
    *(undefined4 *)&(this->EmptyShipList).field_0x4 = 0;
    *(undefined4 *)&(this->EmptyShipList).field_0x8 = 0;
  }
  pvVar1 = *(void **)&this->ThugPilotList;
  if (pvVar1 != (void *)0x0) {
    std::_Deallocate<8,0>
              (pvVar1,*(int *)&(this->ThugPilotList).field_0x8 - (int)pvVar1 & 0xfffffff8);
    *(undefined4 *)&this->ThugPilotList = 0;
    *(undefined4 *)&(this->ThugPilotList).field_0x4 = 0;
    *(undefined4 *)&(this->ThugPilotList).field_0x8 = 0;
  }
  pvVar1 = *(void **)&this->ThugScavengerList;
  if (pvVar1 != (void *)0x0) {
    std::_Deallocate<8,0>
              (pvVar1,*(int *)&(this->ThugScavengerList).field_0x8 - (int)pvVar1 & 0xfffffff8);
    *(undefined4 *)&this->ThugScavengerList = 0;
    *(undefined4 *)&(this->ThugScavengerList).field_0x4 = 0;
    *(undefined4 *)&(this->ThugScavengerList).field_0x8 = 0;
  }
  LuaMission::~LuaMission(&this->super_LuaMission);
  ExceptionList = local_10;
  return;
}


// ---------------------------------------------------------------------
// Strategy02::Load  @ 4fc46a20  lines 120-222

bool __thiscall Strategy02::Load(Strategy02 *this,bool missionSave)

{
  bool bVar1;
  bool bVar2;
  int *piVar3;
  int iVar4;
  int *extraout_ECX;
  char *unaff_ESI;
  int *unaff_EDI;
  Strategy02 *size;
  
  size = this;
  bVar1 = LuaMission::Load(&this->super_LuaMission,missionSave);
  EnableHighTPS(&this->m_GameTPS);
  SetAutoGroupUnits(false);
  if (!missionSave) {
    StartingVehicleManager::Load(SUB41(unaff_ESI,0));
  }
  WantBotKillMessages();
  if (missionSave) {
    if (((this->b_array != (bool *)0x0) && (this->b_count != 0)) && (iVar4 = 0, 0 < this->b_count))
    {
      do {
        this->b_array[iVar4] = false;
        iVar4 = iVar4 + 1;
      } while (iVar4 < this->b_count);
    }
    if (((this->f_array != (float *)0x0) && (this->f_count != 0)) && (iVar4 = 0, 0 < this->f_count))
    {
      do {
        this->f_array[iVar4] = 0.0;
        iVar4 = iVar4 + 1;
      } while (iVar4 < this->f_count);
    }
    if (((this->h_array != (int *)0x0) && (this->h_count != 0)) && (iVar4 = 0, 0 < this->h_count)) {
      do {
        this->h_array[iVar4] = 0;
        iVar4 = iVar4 + 1;
      } while (iVar4 < this->h_count);
    }
    if (((this->i_array != (int *)0x0) && (this->i_count != 0)) && (iVar4 = 0, 0 < this->i_count)) {
      do {
        this->i_array[iVar4] = 0;
        iVar4 = iVar4 + 1;
      } while (iVar4 < this->i_count);
    }
    return true;
  }
  Read((int *)&size,1);
  std::vector<Strategy02::MorphTankClass,std::allocator<Strategy02::MorphTankClass>_>::
  _Resize<<lambda_426a7d76e79c44efd532c0834072b57e>_>
            ((vector<Strategy02::MorphTankClass,std::allocator<Strategy02::MorphTankClass>_> *)
             &this->ThugScavengerList,(uint)size,
             (<lambda_426a7d76e79c44efd532c0834072b57e>)&this->ThugScavengerList);
  if (size != (Strategy02 *)0x0) {
    Read(*(void **)&this->ThugScavengerList,(int)size << 3);
  }
  Read((int *)&size,1);
  std::vector<Strategy02::MorphTankClass,std::allocator<Strategy02::MorphTankClass>_>::
  _Resize<<lambda_426a7d76e79c44efd532c0834072b57e>_>
            ((vector<Strategy02::MorphTankClass,std::allocator<Strategy02::MorphTankClass>_> *)
             &this->ThugPilotList,(uint)size,
             (<lambda_426a7d76e79c44efd532c0834072b57e>)&this->ThugPilotList);
  if (size != (Strategy02 *)0x0) {
    Read(*(void **)&this->ThugPilotList,(int)size << 3);
  }
  Read((int *)&size,1);
  std::vector<Strategy02::EmptyShipClass,std::allocator<Strategy02::EmptyShipClass>_>::
  _Resize<<lambda_4b06d8c16eefdba86b4662f0678c82d0>_>
            (&this->EmptyShipList,(uint)size,
             (<lambda_4b06d8c16eefdba86b4662f0678c82d0>)&this->EmptyShipList);
  piVar3 = extraout_ECX;
  if (size != (Strategy02 *)0x0) {
    piVar3 = (int *)((int)size * 0xc);
    Read(*(void **)&this->EmptyShipList,(int)piVar3);
  }
  if (this->b_array != (bool *)0x0) {
    piVar3 = (int *)this->b_count;
    Read(this->b_array,(int)piVar3);
  }
  if (this->f_array != (float *)0x0) {
    piVar3 = (int *)this->f_count;
    Read(this->f_array,(int)piVar3);
  }
  if (this->h_array != (int *)0x0) {
    piVar3 = (int *)this->h_count;
    Read(this->h_array,(int)piVar3);
  }
  if (this->i_array != (int *)0x0) {
    piVar3 = (int *)this->i_count;
    Read(this->i_array,(int)piVar3);
  }
  if (bVar1) {
    piVar3 = (int *)0x400;
    bVar1 = Read(this->PlayerShipODF,0x400);
    if (bVar1) {
      piVar3 = (int *)0x400;
      bVar1 = Read(this->SavedPilotODF,0x400);
      if (bVar1) {
        piVar3 = (int *)0x400;
        bVar1 = Read(this->PlayerSavedName,0x400);
        if (bVar1) {
          piVar3 = (int *)0x1400;
          bVar1 = Read(this->PlayerShipWeapons,0x1400);
          if (bVar1) {
            piVar3 = (int *)0x1400;
            bVar1 = Read(this->PlayerPilotWeapons,0x1400);
            if (bVar1) {
              piVar3 = (int *)0x140;
              bVar1 = Read(this->PlayerPilotLocalAmmo,0x140);
              if (bVar1) {
                piVar3 = (int *)0x400;
                bVar1 = Read(this->PlayerMatrix,0x400);
                if (bVar1) {
                  piVar3 = (int *)0xc0;
                  bVar1 = Read(this->PlayerVelocity,0xc0);
                  if (bVar1) {
                    piVar3 = (int *)0xc0;
                    bVar1 = Read(this->PlayerOmega,0xc0);
                    if (bVar1) {
                      piVar3 = (int *)0x40;
                      bVar1 = Read(this->MapAmbientSound,0x40);
                      if (bVar1) {
                        piVar3 = (int *)0x400;
                        bVar1 = Read(this->EmptyShipODF,0x400);
                        if (bVar1) {
                          bVar1 = true;
                          goto LAB_4fc46cf1;
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  bVar1 = false;
LAB_4fc46cf1:
  if (this->m_IsMPI != false) {
    InitTaunts(&this->m_GameTPS,piVar3,unaff_EDI,unaff_ESI);
  }
  if (this->m_DidInit != false) {
    bVar2 = DoesFileExist(this->MapAmbientSound);
    if (bVar2) {
      StopAudio(EasterEggSound);
      EasterEggSound = StartAudio2D(this->MapAmbientSound,-1.0,0.0,44100.0,true,false);
    }
  }
  UpdateObjectives(this);
  return bVar1;
}


// ---------------------------------------------------------------------
// Strategy02::PostLoad  @ 4fc46991  lines 225-255

bool __thiscall Strategy02::PostLoad(Strategy02 *this,bool missionSave)

{
  bool bVar1;
  int *piVar2;
  
  bVar1 = LuaMission::PostLoad(&this->super_LuaMission,missionSave);
  if (missionSave) {
    bVar1 = true;
  }
  else {
    for (piVar2 = *(int **)&this->ThugScavengerList;
        piVar2 != *(int **)&(this->ThugScavengerList).field_0x4; piVar2 = piVar2 + 2) {
      ConvertHandles(piVar2,1);
    }
    for (piVar2 = *(int **)&this->ThugPilotList; piVar2 != *(int **)&(this->ThugPilotList).field_0x4
        ; piVar2 = piVar2 + 2) {
      ConvertHandles(piVar2,1);
    }
    for (piVar2 = *(int **)&this->EmptyShipList; piVar2 != *(int **)&(this->EmptyShipList).field_0x4
        ; piVar2 = piVar2 + 3) {
      ConvertHandles(piVar2,1);
    }
    ConvertHandles(this->h_array,this->h_count);
  }
  return bVar1;
}


// ---------------------------------------------------------------------
// Strategy02::Save  @ 4fc46776  lines 258-315

bool __thiscall Strategy02::Save(Strategy02 *this,bool missionSave)

{
  bool bVar1;
  bool unaff_DI;
  Strategy02 *size;
  undefined4 uStack_8;
  
  size = this;
  uStack_8 = this;
  bVar1 = LuaMission::Save(&this->super_LuaMission,missionSave);
  uStack_8 = (Strategy02 *)CONCAT13(bVar1,(undefined3)uStack_8);
  if (missionSave) {
    bVar1 = true;
  }
  else {
    StartingVehicleManager::Save(unaff_DI);
    size = (Strategy02 *)
           (*(int *)&(this->ThugScavengerList).field_0x4 - *(int *)&this->ThugScavengerList >> 3);
    Write((int *)&size,1);
    if (size != (Strategy02 *)0x0) {
      Write(*(void **)&this->ThugScavengerList,(int)size << 3);
    }
    size = (Strategy02 *)
           (*(int *)&(this->ThugPilotList).field_0x4 - *(int *)&this->ThugPilotList >> 3);
    Write((int *)&size,1);
    if (size != (Strategy02 *)0x0) {
      Write(*(void **)&this->ThugPilotList,(int)size << 3);
    }
    size = (Strategy02 *)
           ((*(int *)&(this->EmptyShipList).field_0x4 - *(int *)&this->EmptyShipList) / 0xc);
    Write((int *)&size,1);
    if (size != (Strategy02 *)0x0) {
      Write(*(void **)&this->EmptyShipList,(int)size * 0xc);
    }
    if (this->b_array != (bool *)0x0) {
      Write(this->b_array,this->b_count);
    }
    if (this->f_array != (float *)0x0) {
      Write(this->f_array,this->f_count);
    }
    if (this->h_array != (int *)0x0) {
      Write(this->h_array,this->h_count);
    }
    if (this->i_array != (int *)0x0) {
      Write(this->i_array,this->i_count);
    }
    if (((((uStack_8._3_1_ == '\0') || (bVar1 = Write(this->PlayerShipODF,0x400), !bVar1)) ||
         (bVar1 = Write(this->SavedPilotODF,0x400), !bVar1)) ||
        ((((bVar1 = Write(this->PlayerSavedName,0x400), !bVar1 ||
           (bVar1 = Write(this->PlayerShipWeapons,0x1400), !bVar1)) ||
          ((bVar1 = Write(this->PlayerPilotWeapons,0x1400), !bVar1 ||
           ((bVar1 = Write(this->PlayerPilotLocalAmmo,0x140), !bVar1 ||
            (bVar1 = Write(this->PlayerMatrix,0x400), !bVar1)))))) ||
         (bVar1 = Write(this->PlayerVelocity,0xc0), !bVar1)))) ||
       (((bVar1 = Write(this->PlayerOmega,0xc0), !bVar1 ||
         (bVar1 = Write(this->MapAmbientSound,0x40), !bVar1)) ||
        (bVar1 = Write(this->EmptyShipODF,0x400), !bVar1)))) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
  }
  return bVar1;
}


// ---------------------------------------------------------------------
// Strategy02::GetNextRandomVehicleODF  @ 4fc46762  lines 318-320

char * __thiscall Strategy02::GetNextRandomVehicleODF(Strategy02 *this,int Team)

{
  char *pcVar1;
  
  pcVar1 = GetPlayerODF(Team,Randomize_None);
  return pcVar1;
}


// ---------------------------------------------------------------------
// Strategy02::UpdateObjectives  @ 4fc4672f  lines 323-329

void __thiscall Strategy02::UpdateObjectives(Strategy02 *this)

{
  char *pcVar1;
  
  ClearObjectives();
  if (this->m_GameType == 4) {
    pcVar1 = "mpobjective_stcap.otf";
  }
  else {
    pcVar1 = "mpobjective_st.otf";
  }
  AddObjective(pcVar1,-1,-1.0);
  return;
}


// ---------------------------------------------------------------------
// Strategy02::AddObject  @ 4fc4616f  lines 332-648

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall Strategy02::AddObject(Strategy02 *this,int h)

{
  float *pfVar1;
  vector<Strategy02::ThugPilotClass,std::allocator<Strategy02::ThugPilotClass>_> *_Udefault_or_fill;
  vector<Strategy02::EmptyShipClass,std::allocator<Strategy02::EmptyShipClass>_>
  *_Udefault_or_fill_00;
  vector<Strategy02::ThugScavengerClass,std::allocator<Strategy02::ThugScavengerClass>_>
  *_Udefault_or_fill_01;
  vector<Strategy02::MorphTankClass,std::allocator<Strategy02::MorphTankClass>_>
  *_Udefault_or_fill_02;
  vector<Strategy02::CommBunkerClass,std::allocator<Strategy02::CommBunkerClass>_>
  *_Udefault_or_fill_03;
  bool bVar2;
  char *pcVar3;
  int iVar4;
  long lVar5;
  int *piVar6;
  int *piVar7;
  int iVar8;
  code *pcVar9;
  Vector Pos;
  code *local_dc;
  int local_d8;
  int *local_d4;
  int *local_d0;
  int local_cc;
  char DesiredValue [64];
  char ODFName [64];
  char ObjClass [64];
  uint local_8;
  
  local_8 = __security_cookie ^ (uint)&stack0xfffffffc;
  if (this->StopScript == false) {
    LuaMission::AddObject(&this->super_LuaMission,h);
  }
  GetObjInfo(h,Get_CFG,ODFName);
  bVar2 = DoesODFExist(ODFName);
  if (!bVar2) {
    pcVar3 = strchr(ODFName,0x3a);
    strncpy_s(ODFName,0x40,ODFName,(int)pcVar3 - (int)ODFName);
  }
  local_d4 = (int *)this->m_TurretAISkill;
  local_d0 = (int *)this->m_NonTurretAISkill;
  GetObjInfo(h,Get_GOClass,ObjClass);
  pcVar9 = _stricmp_exref;
  local_dc = _stricmp_exref;
  iVar4 = _stricmp(ObjClass,"CLASS_TURRETTANK");
  local_d8 = CONCAT31((int3)((uint)-iVar4 >> 8),'\x01' - (iVar4 != 0));
  if (((this->m_ElapsedGameTime == 0) &&
      (iVar4 = GetVarItemInt("network.session.ivar117"), iVar4 != 0)) &&
     (iVar4 = _stricmp(ObjClass,"CLASS_SCRAP"), iVar4 == 0)) {
    RemoveObject(h);
  }
  else {
    local_cc = GetTeamNum(h);
    if ((this->m_IsMPI == false) || (local_cc < 0xb)) {
      iVar4 = _stricmp(ObjClass,"CLASS_NAVBEACON");
      piVar6 = local_d4;
      piVar7 = local_d0;
      if ((iVar4 == 0) &&
         (((GetPosition(h,&Pos), pfVar1 = &(this->super_LuaMission).super_BZ1Helper.mapInfo.MaxWidth
           , *pfVar1 <= Pos.x && Pos.x != *pfVar1 ||
           (Pos.x < (this->super_LuaMission).super_BZ1Helper.mapInfo.MinWidth)) ||
          ((pfVar1 = &(this->super_LuaMission).super_BZ1Helper.mapInfo.MaxDepth,
           *pfVar1 <= Pos.z && Pos.z != *pfVar1 ||
           (piVar6 = local_d4, piVar7 = local_d0,
           Pos.z < (this->super_LuaMission).super_BZ1Helper.mapInfo.MinDepth)))))) {
        RemoveObject(h);
        piVar6 = local_d4;
        piVar7 = local_d0;
      }
    }
    else {
      DispatchHelper::AddToDispatch
                ((this->super_LuaMission).super_BZ1Helper.m_DispatchHelper,h,15.0,false,0,false,
                 false,false,false);
      piVar6 = (int *)this->m_CPUTurretAISkill;
      piVar7 = (int *)this->m_CPUNonTurretAISkill;
    }
    if ((char)local_d8 != '\0') {
      piVar7 = piVar6;
    }
    SetSkill(h,(int)piVar7);
    if ((this->m_ElapsedGameTime < 1) && (iVar4 = _stricmp(ObjClass,"CLASS_SPAWNBUOY"), iVar4 == 0))
    {
      this->m_NumSpawnPoints = this->m_NumSpawnPoints + 1;
    }
    iVar4 = _stricmp(ObjClass,"CLASS_RECYCLERVEHICLE");
    if (((iVar4 == 0) || (iVar4 = _stricmp(ObjClass,"CLASS_RECYCLERVEHICLEH"), iVar4 == 0)) ||
       (iVar4 = _stricmp(ObjClass,"CLASS_RECYCLER"), iVar4 == 0)) {
      if ((this->m_RecyclerHandles[local_cc] == 0) ||
         (bVar2 = IsAround(this->m_RecyclerHandles[local_cc]), !bVar2)) {
        this->m_RecyclerHandles[local_cc] = h;
      }
      local_d0 = this->BuildEmpty + local_cc;
      if ((*local_d0 == 0) && (iVar4 = _stricmp(ObjClass,"CLASS_RECYCLER"), iVar4 == 0)) {
        GetODFInt(h,"FactoryClass","buildEmptyItem",local_d0,0);
        local_d8 = *local_d0;
        if (0 < local_d8) {
          memset(DesiredValue,0,0x40);
          sprintf_s<64>(&DesiredValue,"BuildItem%d",local_d8);
          GetODFString(h,"FactoryClass",DesiredValue,0x40,this->EmptyShipODF[local_cc],(char *)0x0);
        }
      }
    }
    bVar2 = IsTeamplayOn();
    if ((!bVar2) || (this->m_IsMPI != false)) {
      iVar4 = _stricmp(ObjClass,"CLASS_SCAVENGER");
      if ((iVar4 == 0) || (iVar4 = _stricmp(ObjClass,"CLASS_SCAVENGERH"), iVar4 == 0)) {
        _Udefault_or_fill_01 = &this->ThugScavengerList;
        for (piVar6 = *(int **)_Udefault_or_fill_01;
            piVar6 != *(int **)&(this->ThugScavengerList).field_0x4; piVar6 = piVar6 + 2) {
          if (*piVar6 == h) goto LAB_4fc46505;
        }
        std::vector<Strategy02::MorphTankClass,std::allocator<Strategy02::MorphTankClass>_>::
        _Resize<<lambda_426a7d76e79c44efd532c0834072b57e>_>
                  ((vector<Strategy02::MorphTankClass,std::allocator<Strategy02::MorphTankClass>_> *
                   )_Udefault_or_fill_01,
                   (*(int *)&(this->ThugScavengerList).field_0x4 - *(int *)_Udefault_or_fill_01 >> 3
                   ) + 1,(<lambda_426a7d76e79c44efd532c0834072b57e>)_Udefault_or_fill_01);
        iVar4 = *(int *)&this->ThugScavengerList;
        iVar8 = *(int *)&(this->ThugScavengerList).field_0x4 - iVar4 >> 3;
        *(int *)(iVar4 + -8 + iVar8 * 8) = h;
        *(int *)(iVar4 + -4 + iVar8 * 8) = local_cc;
      }
      else {
        iVar4 = _stricmp(ObjClass,"CLASS_PERSON");
        if ((iVar4 == 0) && (bVar2 = IsPlayer(h), !bVar2)) {
          _Udefault_or_fill = &this->ThugPilotList;
          for (piVar6 = *(int **)_Udefault_or_fill;
              piVar6 != *(int **)&(this->ThugPilotList).field_0x4; piVar6 = piVar6 + 2) {
            if (*piVar6 == h) goto LAB_4fc46505;
          }
          std::vector<Strategy02::MorphTankClass,std::allocator<Strategy02::MorphTankClass>_>::
          _Resize<<lambda_426a7d76e79c44efd532c0834072b57e>_>
                    ((vector<Strategy02::MorphTankClass,std::allocator<Strategy02::MorphTankClass>_>
                      *)_Udefault_or_fill,
                     (*(int *)&(this->ThugPilotList).field_0x4 - *(int *)_Udefault_or_fill >> 3) + 1
                     ,(<lambda_426a7d76e79c44efd532c0834072b57e>)_Udefault_or_fill);
          iVar4 = *(int *)&this->ThugPilotList;
          iVar8 = *(int *)&(this->ThugPilotList).field_0x4 - iVar4 >> 3;
          *(undefined4 *)(iVar4 + -8 + iVar8 * 8) = 0;
          *(undefined4 *)(iVar4 + -4 + iVar8 * 8) = 0;
          *(int *)(iVar4 + -8 + iVar8 * 8) = h;
          *(int *)(iVar4 + -4 + iVar8 * 8) = this->m_GameTPS * 0xf;
        }
      }
    }
LAB_4fc46505:
    if ((((0 < this->m_PilotInvunerability) &&
         (bVar2 = IsAround(this->m_RecyclerHandles[local_cc]), bVar2)) &&
        (0 < this->BuildEmpty[local_cc])) &&
       (iVar4 = _stricmp(ODFName,this->EmptyShipODF[local_cc]), iVar4 == 0)) {
      _Udefault_or_fill_00 = &this->EmptyShipList;
      for (piVar6 = *(int **)_Udefault_or_fill_00;
          piVar6 != *(int **)&(this->EmptyShipList).field_0x4; piVar6 = piVar6 + 3) {
        if (*piVar6 == h) goto LAB_4fc4662b;
      }
      std::vector<Strategy02::EmptyShipClass,std::allocator<Strategy02::EmptyShipClass>_>::
      _Resize<<lambda_4b06d8c16eefdba86b4662f0678c82d0>_>
                (&this->EmptyShipList,
                 (*(int *)&(this->EmptyShipList).field_0x4 - *(int *)_Udefault_or_fill_00) / 0xc + 1
                 ,(<lambda_4b06d8c16eefdba86b4662f0678c82d0>)_Udefault_or_fill_00);
      iVar4 = *(int *)&this->EmptyShipList;
      iVar8 = ((*(int *)&(this->EmptyShipList).field_0x4 - iVar4) / 0xc) * 0xc;
      *(undefined4 *)(iVar8 + -8 + iVar4) = 0;
      *(undefined4 *)(iVar8 + -4 + iVar4) = 0;
      *(int *)(iVar8 + -0xc + iVar4) = h;
      *(int *)(iVar8 + -8 + iVar4) = this->m_PilotInvunerability;
      lVar5 = GetMaxHealth(h);
      *(long *)(iVar8 + -4 + iVar4) = lVar5;
      SetMaxHealth(h,0);
      pcVar9 = local_dc;
    }
LAB_4fc4662b:
    if ((0 < this->m_MorphTankAutoDeployType) &&
       (iVar4 = (*pcVar9)(ObjClass,"CLASS_MORPHTANK"), iVar4 == 0)) {
      _Udefault_or_fill_02 = &this->MorphTankList;
      for (piVar6 = *(int **)_Udefault_or_fill_02;
          piVar6 != *(int **)&(this->MorphTankList).field_0x4; piVar6 = piVar6 + 2) {
        if (*piVar6 == h) goto LAB_4fc46690;
      }
      std::vector<Strategy02::MorphTankClass,std::allocator<Strategy02::MorphTankClass>_>::
      _Resize<<lambda_426a7d76e79c44efd532c0834072b57e>_>
                (_Udefault_or_fill_02,
                 (*(int *)&(this->MorphTankList).field_0x4 - *(int *)_Udefault_or_fill_02 >> 3) + 1,
                 (<lambda_426a7d76e79c44efd532c0834072b57e>)_Udefault_or_fill_02);
      iVar4 = *(int *)&this->MorphTankList;
      iVar8 = *(int *)&(this->MorphTankList).field_0x4 - iVar4 >> 3;
      *(undefined4 *)(iVar4 + -8 + iVar8 * 8) = 0;
      *(undefined4 *)(iVar4 + -4 + iVar8 * 8) = 0;
      *(int *)(iVar4 + -8 + iVar8 * 8) = h;
    }
LAB_4fc46690:
    local_d0 = (int *)GetCategoryTypeOverride(h);
    if (local_d0 == (int *)0xffffffff) {
      local_d0 = (int *)GetCategoryType(h);
    }
    if (((int)local_d0 - 1U < 9) &&
       ((iVar4 = (*pcVar9)(ObjClass,"CLASS_COMMBUKNER"), iVar4 == 0 ||
        (iVar4 = (*pcVar9)(ObjClass,"CLASS_COMMTOWER"), iVar4 == 0)))) {
      _Udefault_or_fill_03 = &this->CommBunkerList;
      for (piVar6 = *(int **)_Udefault_or_fill_03;
          piVar6 != *(int **)&(this->CommBunkerList).field_0x4; piVar6 = piVar6 + 2) {
        if (*piVar6 == h) {
          return;
        }
      }
      std::vector<Strategy02::MorphTankClass,std::allocator<Strategy02::MorphTankClass>_>::
      _Resize<<lambda_426a7d76e79c44efd532c0834072b57e>_>
                ((vector<Strategy02::MorphTankClass,std::allocator<Strategy02::MorphTankClass>_> *)
                 _Udefault_or_fill_03,
                 (*(int *)&(this->CommBunkerList).field_0x4 - *(int *)_Udefault_or_fill_03 >> 3) + 1
                 ,(<lambda_426a7d76e79c44efd532c0834072b57e>)_Udefault_or_fill_03);
      iVar4 = *(int *)_Udefault_or_fill_03;
      iVar8 = *(int *)&(this->CommBunkerList).field_0x4 - iVar4 >> 3;
      *(int *)(iVar4 + -8 + iVar8 * 8) = h;
      *(int **)(iVar4 + -4 + iVar8 * 8) = local_d0;
    }
  }
  return;
}


// ---------------------------------------------------------------------
// Strategy02::DeleteObject  @ 4fc460d9  lines 651-741

void __thiscall Strategy02::DeleteObject(Strategy02 *this,int h)

{
  int *piVar1;
  bool bVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  
  if (this->StopScript == false) {
    LuaMission::DeleteObject(&this->super_LuaMission,h);
  }
  iVar3 = GetTeamNum(h);
  iVar6 = 0;
  if (((this->m_RestorePlayers != 0) && (bVar2 = IsPlayer(h), bVar2)) &&
     (iVar3 = GetPlayerHandle(iVar3), iVar3 == 0)) {
    SetNoScrapFlagByHandle(h);
  }
  piVar4 = *(int **)&this->CommBunkerList;
  piVar1 = *(int **)&(this->CommBunkerList).field_0x4;
  piVar5 = piVar4;
  do {
    if (piVar5 == piVar1) {
LAB_4fc4615a:
      while( true ) {
        if (piVar4 == piVar1) {
          return;
        }
        if ((h != *piVar4) && (piVar4[1] == iVar6)) break;
        piVar4 = piVar4 + 2;
      }
      ResetTeamSlot(*piVar4);
      return;
    }
    if (h == *piVar5) {
      iVar6 = piVar5[1];
      goto LAB_4fc4615a;
    }
    piVar5 = piVar5 + 2;
  } while( true );
}


// ---------------------------------------------------------------------
// Strategy02::SetCPUAIPlan  @ 4fc45f69  lines 744-776

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall Strategy02::SetCPUAIPlan(Strategy02 *this,int Team,int NameOverride)

{
  char cVar1;
  bool bVar2;
  char *pcVar3;
  int fmtarg4;
  float10 fVar4;
  float fVar5;
  int fmtarg3;
  char local_188 [128];
  char AIPFile [256];
  uint local_8;
  
  local_8 = __security_cookie ^ (uint)&stack0xfffffffc;
  if (this->CheckedSVar3 == false) {
    this->CheckedSVar3 = true;
    sprintf_s<128>(&local_188,"network.session.svar%d",3);
    pcVar3 = GetVarItemStr(local_188);
    if (((pcVar3 == (char *)0x0) ||
        (pcVar3 = DLLUtils::GetCheckedNetworkSvar(3,(NETWORK_LIST_TYPE)pcVar3),
        pcVar3 == (char *)0x0)) || (*pcVar3 == '\0')) {
      pcVar3 = "VSR_";
    }
    strcpy_s(CustomAIPNameBase,0x100,pcVar3);
  }
  memset(AIPFile,0,0x100);
  fVar5 = GetRandomFloat(3.0);
  fVar4 = floor((double)fVar5);
  fmtarg4 = (int)fVar4;
  if (2 < (int)fVar4) {
    fmtarg4 = 2;
  }
  fmtarg3 = NameOverride;
  cVar1 = GetRace(this->m_RecyclerHandles[Team]);
  sprintf_s<256>(&AIPFile,"%s%c%d_%d.aip",CustomAIPNameBase,(int)cVar1,fmtarg3,fmtarg4);
  bVar2 = DoesFileExist(AIPFile);
  if (!bVar2) {
    cVar1 = GetRace(this->m_RecyclerHandles[Team]);
    sprintf_s<256>(&AIPFile,"%s%c%d_0.aip",CustomAIPNameBase,(int)cVar1,NameOverride);
  }
  BZ1Helper::SetAIPFile((BZ1Helper *)this,AIPFile,Team);
  if (this->m_SetFirstAIP != false) {
    DoTaunt(6);
  }
  this->m_SetFirstAIP = true;
  return;
}


// ---------------------------------------------------------------------
// Strategy02::GetInitialPlayerPilotODF  @ 4fc45dc5  lines 786-830

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

char * __thiscall
Strategy02::GetInitialPlayerPilotODF(Strategy02 *this,char Race,int Team,bool IsRespawning)

{
  bool bVar1;
  int iVar2;
  char *pcVar3;
  char TempODF [64];
  char TempODF2 [64];
  uint local_8;
  
  local_8 = __security_cookie ^ (uint)&stack0xfffffffc;
  if (0 < Team) {
    bVar1 = IsTeamplayOn();
    if (bVar1) {
      Team = GetCommanderTeam(Team);
    }
    memset(TempODF,0,0x40);
    memset(TempODF2,0,0x40);
    GetObjInfo(this->m_RecyclerHandles[Team],Get_ODF,TempODF);
    bVar1 = OpenODF2(TempODF);
    if ((bVar1) &&
       (iVar2 = GetODFString(TempODF,"GameObjectClass","classlabel",0x40,TempODF2,(char *)0x0),
       iVar2 != 0)) {
      CombineStrings(TempODF2,TempODF2,".odf",0x40);
      OpenODF2(TempODF2);
    }
    if (IsRespawning) {
      if (this->m_RespawnWithSniper != 1) goto LAB_4fc45ea0;
LAB_4fc45f36:
      pcVar3 = "PilotRespawnWithSniper";
    }
    else {
      if (this->m_RespawnWithSniper < 2) goto LAB_4fc45f36;
LAB_4fc45ea0:
      pcVar3 = "PilotRespawnWithOutSniper";
    }
    GetODFString(TempODF,TempODF2,"GameObjectClass",pcVar3,0x40,TempODFName,(char *)0x0);
  }
  bVar1 = DoesODFExist(TempODFName);
  if ((bVar1) && (Team != 0)) goto LAB_4fc45f56;
  if (IsRespawning) {
    if (this->m_RespawnWithSniper != 1) goto LAB_4fc45ee3;
LAB_4fc45f4a:
    pcVar3 = "ispilo";
  }
  else {
    if (this->m_RespawnWithSniper < 2) goto LAB_4fc45f4a;
LAB_4fc45ee3:
    pcVar3 = "isuser_m";
  }
  strcpy_s(TempODFName,0x40,pcVar3);
  TempODFName[0] = Race;
  bVar1 = DoesODFExist(TempODFName);
  if (!bVar1) {
    sprintf_s<1024>(&TempMsgString,
                    "ERROR: \'%s\' does not exist. Giving you pilot DEFAULT ISDF! FIX IT!",
                    TempODFName);
    PrintConsoleMessage(TempMsgString);
    TempODFName[0] = 'i';
  }
LAB_4fc45f56:
  return TempODFName;
}


// ---------------------------------------------------------------------
// Strategy02::GetInitialRecyclerODF  @ 4fc45d44  lines 834-844

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

char * __thiscall Strategy02::GetInitialRecyclerODF(Strategy02 *this,char param_1)

{
  char *pcVar1;
  char local_88 [128];
  uint local_8;
  
  local_8 = __security_cookie ^ (uint)&stack0xfffffffc;
  sprintf_s<128>(&local_88,"network.session.svar%d",5);
  pcVar1 = GetVarItemStr(local_88);
  if (((pcVar1 == (char *)0x0) ||
      (pcVar1 = DLLUtils::GetCheckedNetworkSvar(2,(NETWORK_LIST_TYPE)pcVar1), pcVar1 == (char *)0x0)
      ) || (*pcVar1 == '\0')) {
    pcVar1 = "ivrecy_m";
  }
  strcpy_s(TempODFName,0x40,pcVar1);
  TempODFName[0] = param_1;
  return TempODFName;
}


// ---------------------------------------------------------------------
// Strategy02::GetSpawnpointForTeam  @ 4fc45a57  lines 872-1006

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Variable defined which should be unmapped: __return_storage_ptr__ */

Vector * __thiscall
Strategy02::GetSpawnpointForTeam(Strategy02 *this,Vector *__return_storage_ptr__,int param_1)

{
  float *pfVar1;
  float fVar2;
  int iVar3;
  bool bVar4;
  uint uVar5;
  uint extraout_EAX;
  uint extraout_EAX_00;
  uint extraout_EAX_01;
  uint extraout_EAX_02;
  uint uVar6;
  uint extraout_ECX;
  int iVar7;
  uint uVar8;
  SpawnpointInfo *pSVar9;
  uint uVar10;
  undefined4 auStackY_44 [2];
  SpawnpointInfo spawnpointPosition;
  
  spawnpointPosition.m_DistanceToClosestEnemy = (float)(__security_cookie ^ (uint)&stack0xfffffffc);
  spawnpointPosition.m_Position.z = 0.0;
  spawnpointPosition.m_Position.y = 0.0;
  spawnpointPosition.m_Position.x = 0.0;
  auStackY_44[1] = 0x4fc45a86;
  spawnpointPosition.m_DistanceToClosestAlly = (float)this;
  uVar5 = GetAllSpawnpoints((SpawnpointInfo **)&spawnpointPosition.m_DistanceToClosestTeamZero,
                            param_1);
  if (uVar5 == 0) {
    pSVar9 = &spawnpointPosition;
    goto LAB_4fc45a91;
  }
  iVar3 = uVar5 * -4;
  *(uint *)(&stack0xffffffc8 + iVar3) = uVar5 * 4;
  uVar10 = 0;
  spawnpointPosition.m_DistanceToClosestSameTeam = (float)(&stack0xffffffcc + iVar3);
  *(undefined4 *)(&stack0xffffffc4 + iVar3) = 0;
  auStackY_44[1 - uVar5] = &stack0xffffffcc + iVar3;
  auStackY_44[-uVar5] = 0x4fc45ab9;
  memset((void *)auStackY_44[1 - uVar5],*(int *)(&stack0xffffffc4 + iVar3),
         *(size_t *)(&stack0xffffffc8 + iVar3));
  uVar8 = 0;
  uVar6 = 0;
  if (uVar5 == 0) {
LAB_4fc45b3b:
    *(undefined4 *)(&stack0xffffffc8 + iVar3) = 0x4fc45b41;
    bVar4 = IsTeamplayOn();
    if (!bVar4) {
      *(int *)(&stack0xffffffc8 + iVar3) =
           ((int *)((int)spawnpointPosition.m_DistanceToClosestAlly + 0xe404))[param_1];
      *(int **)(&stack0xffffffc4 + iVar3) = &spawnpointPosition.m_Handle;
      auStackY_44[1 - uVar5] = 0x4fc45b60;
      GetAllSpawnpoints(*(SpawnpointInfo ***)(&stack0xffffffc4 + iVar3),
                        *(int *)(&stack0xffffffc8 + iVar3));
      uVar6 = uVar10;
      uVar8 = uVar10;
      if (uVar5 != 0) {
        do {
          fVar2 = *(float *)((int)spawnpointPosition.m_DistanceToClosestAlly + 0xea30);
          if (((fVar2 <= *(float *)(spawnpointPosition.m_Handle + 0x18 + uVar10)) &&
              (fVar2 <= *(float *)((int)spawnpointPosition.m_DistanceToClosestTeamZero + 0x1c +
                                  uVar10))) &&
             (fVar2 <= *(float *)((int)spawnpointPosition.m_DistanceToClosestTeamZero + 0x20 +
                                 uVar10))) {
            *(uint *)((int)spawnpointPosition.m_DistanceToClosestSameTeam + uVar8 * 4) = uVar6;
            uVar8 = uVar8 + 1;
          }
          uVar6 = uVar6 + 1;
          uVar10 = uVar10 + 0x24;
        } while (uVar6 < uVar5);
        *(undefined4 *)(&stack0xffffffc8 + iVar3) = 0;
        uVar10 = *(uint *)(&stack0xffffffc8 + iVar3);
        if (uVar8 != 0) {
          spawnpointPosition.m_Team =
               (int)(float)((double)(int)uVar8 +
                           (double)(&__xmm_41f00000000000000000000000000000)[-((int)uVar8 >> 0x1f)])
          ;
          do {
            iVar7 = spawnpointPosition.m_Team;
            *(uint *)(&stack0xffffffc8 + iVar3) = uVar6;
            *(int *)(&stack0xffffffc8 + iVar3) = iVar7;
            *(undefined4 *)(&stack0xffffffc4 + iVar3) = 0x4fc45beb;
            spawnpointPosition.m_DistanceToClosestAlly =
                 GetRandomFloat(*(float *)(&stack0xffffffc8 + iVar3));
            *(undefined4 *)(&stack0xffffffc8 + iVar3) = 0x4fc45bf9;
            _ftoui3();
            uVar5 = extraout_EAX_00;
            uVar6 = extraout_EAX_00;
          } while (uVar8 <= extraout_EAX_00);
          goto LAB_4fc45b2c;
        }
      }
    }
    uVar6 = uVar10;
    uVar8 = uVar10;
    if (uVar5 != 0) {
      do {
        fVar2 = *(float *)((int)spawnpointPosition.m_DistanceToClosestAlly + 0xea2c);
        pfVar1 = (float *)((int)spawnpointPosition.m_DistanceToClosestTeamZero + 0x18 + uVar10);
        if (((*pfVar1 <= fVar2 && fVar2 != *pfVar1) ||
            (pfVar1 = (float *)((int)spawnpointPosition.m_DistanceToClosestTeamZero + 0x1c + uVar10)
            , *pfVar1 <= fVar2 && fVar2 != *pfVar1)) &&
           (*(float *)((int)spawnpointPosition.m_DistanceToClosestAlly + 0xea30) <=
            *(float *)((int)spawnpointPosition.m_DistanceToClosestTeamZero + 0x20 + uVar10))) {
          *(uint *)((int)spawnpointPosition.m_DistanceToClosestSameTeam + uVar8 * 4) = uVar6;
          uVar8 = uVar8 + 1;
        }
        uVar6 = uVar6 + 1;
        uVar10 = uVar10 + 0x24;
      } while (uVar6 < uVar5);
      *(undefined4 *)(&stack0xffffffc8 + iVar3) = 0;
      uVar10 = *(uint *)(&stack0xffffffc8 + iVar3);
      if (uVar8 != 0) {
        spawnpointPosition.m_Handle =
             (int)(float)((double)(int)uVar8 +
                         (double)(&__xmm_41f00000000000000000000000000000)[-((int)uVar8 >> 0x1f)]);
        do {
          iVar7 = spawnpointPosition.m_Handle;
          *(uint *)(&stack0xffffffc8 + iVar3) = uVar6;
          *(int *)(&stack0xffffffc8 + iVar3) = iVar7;
          *(undefined4 *)(&stack0xffffffc4 + iVar3) = 0x4fc45c86;
          spawnpointPosition.m_Team = (int)GetRandomFloat(*(float *)(&stack0xffffffc8 + iVar3));
          *(undefined4 *)(&stack0xffffffc8 + iVar3) = 0x4fc45c94;
          _ftoui3();
          uVar6 = extraout_EAX_01;
          uVar5 = extraout_EAX_01;
        } while (uVar8 <= extraout_EAX_01);
        goto LAB_4fc45b2c;
      }
    }
    fVar2 = spawnpointPosition.m_DistanceToClosestSameTeam;
    uVar6 = uVar10;
    uVar8 = uVar10;
    if (uVar5 == 0) {
LAB_4fc45d1f:
      *(int *)(&stack0xffffffc8 + iVar3) = param_1;
      *(Vector **)(&stack0xffffffc4 + iVar3) = __return_storage_ptr__;
      auStackY_44[1 - uVar5] = 0x4fc45d2b;
      GetRandomSpawnpoint(*(Vector **)(&stack0xffffffc4 + iVar3),*(int *)(&stack0xffffffc8 + iVar3))
      ;
      return __return_storage_ptr__;
    }
    do {
      if (*(float *)((int)spawnpointPosition.m_DistanceToClosestAlly + 0xea34) <=
          *(float *)((int)spawnpointPosition.m_DistanceToClosestTeamZero + 0x20 + uVar6)) {
        *(uint *)((int)spawnpointPosition.m_DistanceToClosestSameTeam + uVar8 * 4) = uVar10;
        uVar8 = uVar8 + 1;
      }
      uVar10 = uVar10 + 1;
      uVar6 = uVar6 + 0x24;
    } while (uVar10 < uVar5);
    if (uVar8 == 0) goto LAB_4fc45d1f;
    spawnpointPosition.m_Handle =
         (int)(float)((double)(int)uVar8 +
                     (double)(&__xmm_41f00000000000000000000000000000)[-((int)uVar8 >> 0x1f)]);
    do {
      iVar7 = spawnpointPosition.m_Handle;
      *(uint *)(&stack0xffffffc8 + iVar3) = uVar10;
      *(int *)(&stack0xffffffc8 + iVar3) = iVar7;
      *(undefined4 *)(&stack0xffffffc4 + iVar3) = 0x4fc45cff;
      spawnpointPosition.m_Team = (int)GetRandomFloat(*(float *)(&stack0xffffffc8 + iVar3));
      *(undefined4 *)(&stack0xffffffc8 + iVar3) = 0x4fc45d0d;
      _ftoui3();
      uVar10 = extraout_ECX;
    } while (uVar8 <= extraout_EAX_02);
    iVar3 = *(int *)((int)fVar2 + extraout_EAX_02 * 4);
  }
  else {
    iVar7 = 0;
    do {
      if (*(int *)((int)spawnpointPosition.m_DistanceToClosestTeamZero + 0xc + iVar7) == param_1) {
        *(uint *)((int)spawnpointPosition.m_DistanceToClosestSameTeam + uVar8 * 4) = uVar6;
        uVar8 = uVar8 + 1;
      }
      uVar6 = uVar6 + 1;
      iVar7 = iVar7 + 0x24;
    } while (uVar6 < uVar5);
    *(undefined4 *)(&stack0xffffffc8 + iVar3) = 0;
    uVar10 = *(uint *)(&stack0xffffffc8 + iVar3);
    if (uVar8 == 0) goto LAB_4fc45b3b;
    spawnpointPosition.m_Handle =
         (int)(float)((double)(int)uVar8 +
                     (double)(&__xmm_41f00000000000000000000000000000)[-((int)uVar8 >> 0x1f)]);
    do {
      iVar7 = spawnpointPosition.m_Handle;
      *(uint *)(&stack0xffffffc8 + iVar3) = uVar6;
      *(int *)(&stack0xffffffc8 + iVar3) = iVar7;
      *(undefined4 *)(&stack0xffffffc4 + iVar3) = 0x4fc45b13;
      spawnpointPosition.m_DistanceToClosestAlly =
           GetRandomFloat(*(float *)(&stack0xffffffc8 + iVar3));
      *(undefined4 *)(&stack0xffffffc8 + iVar3) = 0x4fc45b21;
      _ftoui3();
      uVar5 = extraout_EAX;
      uVar6 = extraout_EAX;
    } while (uVar8 <= extraout_EAX);
LAB_4fc45b2c:
    iVar3 = *(int *)((int)spawnpointPosition.m_DistanceToClosestSameTeam + uVar5 * 4);
  }
  pSVar9 = (SpawnpointInfo *)((int)spawnpointPosition.m_DistanceToClosestTeamZero + iVar3 * 0x24);
LAB_4fc45a91:
  __return_storage_ptr__->x = (pSVar9->m_Position).x;
  __return_storage_ptr__->y = (pSVar9->m_Position).y;
  __return_storage_ptr__->z = (pSVar9->m_Position).z;
  return __return_storage_ptr__;
}


// ---------------------------------------------------------------------
// IsRecyclerODF  @ 4fc459c5  lines 1011-1027

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl IsRecyclerODF(int h)

{
  int iVar1;
  char ODFName [64];
  char ObjClass [64];
  uint local_8;
  
  local_8 = __security_cookie ^ (uint)&stack0xfffffffc;
  if (h == 0) {
    iVar1 = 0;
  }
  else {
    GetObjInfo(h,Get_GOClass,ObjClass);
    iVar1 = _stricmp(ObjClass,"CLASS_RECYCLERVEHICLE");
    if (((iVar1 == 0) || (iVar1 = _stricmp(ObjClass,"CLASS_RECYCLER"), iVar1 == 0)) ||
       (iVar1 = _stricmp(ObjClass,"CLASS_RECYCLERVEHICLEH"), iVar1 == 0)) {
      GetObjInfo(h,Get_CFG,ODFName);
      iVar1 = (int)ODFName[0];
    }
    else {
      iVar1 = 0;
    }
  }
  return iVar1;
}


// ---------------------------------------------------------------------
// Strategy02::BuildStartingVehicle  @ 4fc4594d  lines 1033-1049

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __thiscall
Strategy02::BuildStartingVehicle
          (Strategy02 *this,int param_1,int param_2,char *param_3,char *param_4,char *param_5,
          int param_6)

{
  bool bVar1;
  int iVar2;
  char TempODF [64];
  uint local_8;
  
  local_8 = __security_cookie ^ (uint)&stack0xfffffffc;
  strcpy_s(TempODF,0x40,param_3);
  TempODF[0] = (char)param_2;
  bVar1 = DoesODFExist(TempODF);
  if (!bVar1) {
    strcpy_s(TempODF,0x40,param_4);
    TempODF[0] = (char)param_2;
  }
  iVar2 = BuildObject(TempODF,param_1,param_5);
  return iVar2;
}


// ---------------------------------------------------------------------
// Strategy02::BuildStartingVehicle  @ 4fc458da  lines 1053-1069

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __thiscall
Strategy02::BuildStartingVehicle
          (Strategy02 *this,int param_1,int param_2,char *param_3,char *param_4,Vector param_5,
          int param_6)

{
  bool bVar1;
  int iVar2;
  char TempODF [64];
  uint local_8;
  
  local_8 = __security_cookie ^ (uint)&stack0xfffffffc;
  strcpy_s(TempODF,0x40,param_3);
  TempODF[0] = (char)param_2;
  bVar1 = DoesODFExist(TempODF);
  if (!bVar1) {
    strcpy_s(TempODF,0x40,param_4);
    TempODF[0] = (char)param_2;
  }
  iVar2 = BuildObject(TempODF,param_1,&param_5);
  return iVar2;
}


// ---------------------------------------------------------------------
// Strategy02::SetupTeam  @ 4fc4512c  lines 1082-1284

/* WARNING: Function: _alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Unable to track spacebase fully for stack */

void __thiscall Strategy02::SetupTeam(Strategy02 *this,int Team)

{
  Vector VVar1;
  Vector VVar2;
  Vector VVar3;
  Vector Where;
  char cVar4;
  bool bVar5;
  int iVar6;
  Vector *pVVar7;
  char *pcVar8;
  Vector *pVVar9;
  char *pcVar10;
  DLLBase *pDVar11;
  undefined4 extraout_ECX;
  Strategy02 *this_00;
  Strategy02 *this_01;
  Strategy02 *this_02;
  Vector *unaff_ESI;
  Vector *unaff_EDI;
  DLLBase DVar12;
  double dVar13;
  PortalHelper *pPVar14;
  Strategy02 *this_03;
  Matrix *pMVar15;
  Vector Front__Center__NewPosition;
  DLLBase *local_128;
  Vector spawnpointPosition;
  PortalHelper *TeamRaceH;
  int *bufSize;
  char VariantName [64];
  Matrix PathName__Pos;
  char TempODF2 [64];
  char TempODF [68];
  uint local_c;
  
  local_c = __security_cookie ^ (uint)&stack0xfffffffc;
  if (0xe < Team - 1U) {
    return;
  }
  if (this->m_TeamIsSetUp[Team] != false) {
    return;
  }
  if ((Team == 1) && (this->m_IsMPI != false)) {
    DoTaunt(0);
  }
  cVar4 = GetRaceOfTeam(Team);
  TeamRaceH = (PortalHelper *)CONCAT31(TeamRaceH._1_3_,cVar4);
  bVar5 = IsTeamplayOn();
  if (bVar5) {
    pPVar14 = TeamRaceH;
    iVar6 = WhichTeamGroup(Team);
    SetMPTeamRace(iVar6,(char)pPVar14);
  }
  spawnpointPosition.x = 0.0;
  spawnpointPosition.y = 0.0;
  spawnpointPosition.z = 0.0;
  if (this->m_IsMPI != false) {
    memset(&PathName__Pos,0,0x40);
    sprintf_s<64>((char (*) [64])&PathName__Pos,"Player_%d",this->m_PlayersSpawned + 1);
    bufSize = (int *)0x0;
    GetPathPoints((char *)&PathName__Pos,(uint *)&bufSize,(float *)0x0);
    iVar6 = (int)bufSize * -8;
    *(undefined1 **)(&stack0xfffffeac + iVar6) = &stack0xfffffeb0;
    local_128 = (DLLBase *)&stack0xfffffeb0;
    *(int ***)(&stack0xfffffea8 + iVar6) = &bufSize;
    *(Matrix **)(&stack0xfffffea4 + iVar6) = &PathName__Pos;
    *(undefined4 *)(&stack0xfffffea0 + iVar6) = 0x4fc45245;
    bVar5 = GetPathPoints(*(char **)(&stack0xfffffea4 + iVar6),*(uint **)(&stack0xfffffea8 + iVar6),
                          *(float **)(&stack0xfffffeac + iVar6));
    pDVar11 = local_128;
    if (bVar5) {
      *(undefined4 *)(&stack0xfffffeac + iVar6) = extraout_ECX;
      *(undefined4 *)(&stack0xfffffea8 + iVar6) = extraout_ECX;
      DVar12 = *pDVar11;
      *(DLLBase *)(&stack0xfffffeac + iVar6) = pDVar11[1];
      Front__Center__NewPosition.x = (float)DVar12;
      *(DLLBase *)(&stack0xfffffea8 + iVar6) = DVar12;
      *(undefined4 *)(&stack0xfffffea4 + iVar6) = 0x4fc45276;
      Front__Center__NewPosition.y =
           TerrainFindFloor(*(float *)(&stack0xfffffea8 + iVar6),
                            *(float *)(&stack0xfffffeac + iVar6));
      Front__Center__NewPosition.z = *(float *)(pDVar11 + 1);
      spawnpointPosition.x = Front__Center__NewPosition.x;
      spawnpointPosition.y = Front__Center__NewPosition.y;
      spawnpointPosition.z = Front__Center__NewPosition.z;
    }
    this->m_PlayersSpawned = this->m_PlayersSpawned + 1;
    if (0.1 <= spawnpointPosition.y * spawnpointPosition.y +
               spawnpointPosition.x * spawnpointPosition.x +
               spawnpointPosition.z * spawnpointPosition.z) goto LAB_4fc4531a;
  }
  pVVar7 = GetSpawnpointForTeam(this,&Front__Center__NewPosition,Team);
  spawnpointPosition.x = pVVar7->x;
  spawnpointPosition.y = pVVar7->y;
  spawnpointPosition.z = pVVar7->z;
LAB_4fc4531a:
  *(float *)(this->m_TeamPos + Team * 3) = spawnpointPosition.x;
  *(float *)(this->m_TeamPos + Team * 3 + 2) = spawnpointPosition.z;
  this->m_TeamPos[Team * 3 + 1] = spawnpointPosition.y;
  iVar6 = GetObjectByTeamSlot(Team,1);
  if (iVar6 == 0) {
    if (this->m_SpawnFacingCenter == false) {
      VVar1.y = spawnpointPosition.y;
      VVar1.x = spawnpointPosition.x;
      VVar1.z = spawnpointPosition.z;
      pVVar9 = GetPositionNear(&Front__Center__NewPosition,VVar1,20.0,40.0);
      pVVar7 = &spawnpointPosition;
      spawnpointPosition.x = pVVar9->x;
      spawnpointPosition.y = pVVar9->y;
      spawnpointPosition.z = pVVar9->z;
      iVar6 = Team;
      pcVar8 = GetInitialRecyclerODF(this_00,(char)TeamRaceH);
      iVar6 = BuildObject(pcVar8,iVar6,pVVar7);
      SetRandomHeadingAngle(iVar6);
    }
    else {
      GetCenterOfMap(unaff_EDI);
      local_128 = (DLLBase *)(Front__Center__NewPosition.x - spawnpointPosition.x);
      bufSize = (int *)(Front__Center__NewPosition.z - spawnpointPosition.z);
      dVar13 = (double)((float)local_128 * (float)local_128 + (float)bufSize * (float)bufSize);
      libm_sse2_sqrt_precise();
      this_03 = (Strategy02 *)&Front__Center__NewPosition;
      Front__Center__NewPosition.y = 0.0;
      Front__Center__NewPosition.x = (float)local_128 / (float)dVar13;
      Front__Center__NewPosition.z = (float)bufSize / (float)dVar13;
      Build_Directinal_Matrix((Matrix *)this_03,unaff_EDI,unaff_ESI);
      pMVar15 = &PathName__Pos;
      iVar6 = Team;
      pcVar8 = GetInitialRecyclerODF(this_03,(char)TeamRaceH);
      iVar6 = BuildObject(pcVar8,iVar6,pMVar15);
    }
    this->m_RecyclerHandles[Team] = iVar6;
    SetGroup(iVar6,0);
  }
  spawnpointPosition.x = this->m_TeamPos[Team * 3];
  spawnpointPosition.y = this->m_TeamPos[Team * 3 + 1];
  spawnpointPosition.z = *(float *)(this->m_TeamPos + Team * 3 + 2);
  memset(TempODF,0,0x40);
  memset(TempODF2,0,0x40);
  memset(VariantName,0,0x40);
  pcVar8 = GetInitialRecyclerODF(this_01,(char)TeamRaceH);
  strcpy_s(TempODF,0x40,pcVar8);
  CombineStrings(TempODF,TempODF,".odf",0x40);
  OpenODF2(TempODF);
  iVar6 = GetODFString(TempODF,"GameObjectClass","classlabel",0x40,TempODF2,(char *)0x0);
  if (iVar6 != 0) {
    CombineStrings(TempODF2,TempODF2,".odf",0x40);
    OpenODF2(TempODF2);
  }
  iVar6 = GetODFString(TempODF,TempODF2,"GameObjectClass","startingVariant",0x40,VariantName,
                       (char *)0x0);
  if (iVar6 == 0) {
    iVar6 = 0x5f;
    pcVar8 = GetInitialRecyclerODF(this_02,(char)TeamRaceH);
    pcVar8 = strchr(pcVar8,iVar6);
    if (pcVar8 != (char *)0x0) {
      pcVar8 = pcVar8 + 1;
      pcVar10 = strchr(pcVar8,0x5f);
      if (pcVar10 != (char *)0x0) {
        pcVar8 = pcVar10 + 1;
      }
      strcpy_s(VariantName,0x40,pcVar8);
    }
  }
  this->m_CreatingStartingVehicles = true;
  Where.y = (float)unaff_EDI;
  Where.x = spawnpointPosition.z;
  Where.z = (float)unaff_ESI;
  StartingVehicleManager::CreateVehicles
            ((int)VariantName,(char)this->m_StartingVehiclesMask,(char *)spawnpointPosition.x,
             (int)spawnpointPosition.y,Where);
  this->m_CreatingStartingVehicles = false;
  (*misnImport.SetScrap)(Team,0x28);
  bVar5 = IsTeamplayOn();
  if (bVar5) {
    pDVar11 = (DLLBase *)GetFirstAlliedTeam(Team);
    local_128 = pDVar11;
    iVar6 = GetLastAlliedTeam(Team);
    if ((int)pDVar11 <= iVar6) {
      bufSize = (int *)((int)pDVar11 * 0xc);
      do {
        pcVar8 = GetInitialPlayerPilotODF(this,(char)TeamRaceH,(int)pDVar11,false);
        iVar6 = GetPlayerHandle((int)pDVar11);
        SetPilotClass(iVar6,pcVar8);
        if (pDVar11 != (DLLBase *)Team) {
          if (this->m_SpawnFacingCenter == false) {
            VVar2.y = spawnpointPosition.y;
            VVar2.x = spawnpointPosition.x;
            VVar2.z = spawnpointPosition.z;
            GetPositionNear(&Front__Center__NewPosition,VVar2,30.0,60.0);
            *(float *)((int)(bufSize + 0x3a58) + (int)this) = Front__Center__NewPosition.x;
            *(float *)((int)(this->m_TeamPos + 1) + (int)bufSize) = Front__Center__NewPosition.y;
            *(float *)((int)(bufSize + 0x3a5a) + (int)this) = Front__Center__NewPosition.z;
            pDVar11 = local_128;
          }
          else {
            *(float *)((int)(bufSize + 0x3a58) + (int)this) = spawnpointPosition.x;
            *(float *)((int)(this->m_TeamPos + 1) + (int)bufSize) = spawnpointPosition.y;
            *(float *)((int)(bufSize + 0x3a5a) + (int)this) = spawnpointPosition.z;
          }
        }
        bufSize = bufSize + 3;
        pDVar11 = (DLLBase *)((int)pDVar11 + 1);
        local_128 = pDVar11;
        iVar6 = GetLastAlliedTeam(Team);
      } while ((int)pDVar11 <= iVar6);
    }
  }
  else {
    bufSize = this->m_AllyTeams + 1;
    local_128 = (DLLBase *)0x1;
    TeamRaceH = (PortalHelper *)0xc;
    do {
      if ((((local_128 != (DLLBase *)Team) && (this->m_AllyTeams[Team] == *bufSize)) &&
          (this->m_ThugFlag[(int)local_128] != false)) && (this->m_ThugFlag[Team] == false)) {
        if (this->m_SpawnFacingCenter == false) {
          VVar3.y = spawnpointPosition.y;
          VVar3.x = spawnpointPosition.x;
          VVar3.z = spawnpointPosition.z;
          GetPositionNear(&Front__Center__NewPosition,VVar3,30.0,60.0);
          *(float *)((int)this->m_TeamPos + (int)TeamRaceH) = Front__Center__NewPosition.x;
          *(float *)((int)(this->m_TeamPos + 1) + (int)TeamRaceH) = Front__Center__NewPosition.y;
          DVar12 = (DLLBase)Front__Center__NewPosition.z;
        }
        else {
          *(float *)((int)this->m_TeamPos + (int)TeamRaceH) = spawnpointPosition.x;
          *(float *)((int)(this->m_TeamPos + 1) + (int)TeamRaceH) = spawnpointPosition.y;
          DVar12 = (DLLBase)spawnpointPosition.z;
        }
        *(DLLBase *)((int)(this->m_TeamPos + 2) + (int)TeamRaceH) = DVar12;
      }
      TeamRaceH = (PortalHelper *)&TeamRaceH->TeleportTargetList;
      local_128 = (DLLBase *)((int)local_128 + 1);
      bufSize = bufSize + 1;
    } while ((int)TeamRaceH < 0xc0);
  }
  iVar6 = GetLocalPlayerTeamNumber();
  if (Team == iVar6) {
    UpdateObjectives(this);
  }
  this->m_TeamIsSetUp[Team] = true;
  return;
}


// ---------------------------------------------------------------------
// Strategy02::SetupPlayer  @ 4fc44583  lines 1290-1630

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __thiscall Strategy02::SetupPlayer(Strategy02 *this,int Team)

{
  Vector VVar1;
  Vector VVar2;
  undefined1 auVar3 [12];
  undefined1 auVar4 [12];
  code *pcVar5;
  bool bVar6;
  char cVar7;
  Vector *pVVar8;
  int iVar9;
  int iVar10;
  Matrix *pMVar11;
  char *pcVar12;
  char (*pacVar13) [64];
  int iVar14;
  Vector *unaff_ESI;
  Vector *unaff_EDI;
  int *piVar15;
  double dVar16;
  undefined1 auStack_b4 [7];
  char local_ad;
  Vector local_ac;
  Vector *local_a0;
  float Center__NewPosition__Front;
  float local_98;
  code *local_94;
  int *local_90;
  int *local_8c;
  code *local_88;
  char *local_84;
  float local_80;
  int *local_7c;
  code *local_78;
  float local_74;
  int local_70;
  int *local_6c;
  char *local_68;
  Matrix local_64;
  undefined4 local_20;
  undefined4 uStack_1c;
  float fStack_18;
  uint local_c;
  
  local_c = __security_cookie ^ (uint)auStack_b4;
  local_ac.x = 0.0;
  local_ac.y = 0.0;
  local_ac.z = 0.0;
  local_7c = (int *)Team;
  local_70 = 0;
  local_80 = 0.0;
  if (0xf < (uint)Team) {
    return 0;
  }
  this->m_SpawnedAtTime[Team] = this->m_ElapsedGameTime;
  local_94 = (code *)WhichTeamGroup(Team);
  local_a0 = (Vector *)local_80;
  local_74 = local_80;
  local_98 = local_80;
  if (this->m_SpawnFacingCenter != false) {
    pVVar8 = GetCenterOfMap(unaff_EDI);
    local_80 = pVVar8->x;
    Center__NewPosition__Front = pVVar8->y;
    local_74 = pVVar8->z;
    Team = (int)local_7c;
  }
  pcVar5 = local_94;
  local_a0 = (Vector *)local_80;
  local_98 = local_74;
  bVar6 = IsTeamplayOn();
  if ((bVar6) && (-1 < (int)pcVar5)) {
    iVar9 = GetCommanderTeam(Team);
    SetupTeam(this,iVar9);
    local_ac.z = this->m_TeamPos[Team * 3 + 2];
    local_ac.x = this->m_TeamPos[Team * 3];
    local_ac.y = TerrainFindFloor(local_ac.x,local_ac.z);
    local_ac.y = local_ac.y + 2.5;
    if (this->m_SpawnFacingCenter != false) {
      local_94 = (code *)(local_80 - local_ac.x);
      local_78 = (code *)(local_74 - local_ac.z);
      dVar16 = (double)((float)local_94 * (float)local_94 + (float)local_78 * (float)local_78);
      libm_sse2_sqrt_precise();
      iVar9 = 1;
      if (5 < Team) {
        iVar9 = 7;
      }
      iVar9 = Team - iVar9;
      local_a0 = (Vector *)((float)local_94 / (float)dVar16);
      local_98 = (float)local_78 / (float)dVar16;
LAB_4fc44b66:
      Center__NewPosition__Front = 0.0;
      auVar4._4_4_ = (float)iVar9 * 15.0 * 0.017453292;
      auVar4._0_4_ = local_98;
      auVar4._8_4_ = 0;
      pVVar8 = HRotateFront(local_a0,(Vector)(auVar4 << 0x20),(float)unaff_EDI);
      local_a0 = (Vector *)pVVar8->x;
      Center__NewPosition__Front = pVVar8->y;
      local_98 = pVVar8->z;
      local_ac.x = (float)local_a0 * 50.0 + local_ac.x;
      local_ac.y = Center__NewPosition__Front * 50.0 + local_ac.y;
      local_ac.z = local_98 * 50.0 + local_ac.z;
      Team = (int)local_7c;
      local_64.right.x = local_ac.x;
      local_64.right.y = local_ac.y;
      local_64.right.z = local_ac.z;
    }
  }
  else {
    if (*(char *)((int)(Team + 0xe7d4) + (int)this) == '\0') {
      if (this->m_NumSpawnPoints <= this->NumCommanders) {
        piVar15 = (int *)0x1;
        do {
          if (piVar15 != (int *)Team) {
            UnAlly(Team,(int)piVar15);
            UnAlly((int)piVar15,Team);
          }
          piVar15 = (int *)((int)piVar15 + 1);
        } while ((int)piVar15 < 0x10);
        *(undefined1 *)((int)(Team + 0xe7d4) + (int)this) = 1;
        piVar15 = this->CommanderTeam;
        iVar9 = 0x10;
        iVar14 = -1;
        do {
          iVar10 = *piVar15;
          piVar15 = piVar15 + 1;
          if (iVar10 <= iVar14) {
            iVar10 = iVar14;
          }
          iVar9 = iVar9 + -1;
          iVar14 = iVar10;
        } while (iVar9 != 0);
        iVar9 = this->NextAutoAssignTeam;
        if (iVar9 < 0x10) {
          piVar15 = this->CommanderTeam + iVar9;
          do {
            iVar14 = iVar9 + 1;
            if (*piVar15 != 0) {
              if (iVar10 < iVar14) {
                iVar14 = 0;
              }
              this->NextAutoAssignTeam = iVar14;
              goto LAB_4fc4481b;
            }
            piVar15 = piVar15 + 1;
            iVar9 = iVar14;
          } while (iVar14 < 0x10);
        }
        iVar9 = 0;
LAB_4fc4481b:
        this->m_AllyTeams[Team] = this->m_AllyTeams[iVar9];
        piVar15 = (int *)0x1;
        local_8c = this->m_AllyTeams + 1;
        do {
          if (((0 < *local_8c) && (piVar15 != (int *)Team)) &&
             (*local_8c == this->m_AllyTeams[Team])) {
            Ally((int)piVar15,Team);
            Ally(Team,(int)piVar15);
            this->m_HasAllies[(int)piVar15] = true;
            *(undefined1 *)((int)(Team + 0xe7c0) + (int)this) = 1;
          }
          piVar15 = (int *)((int)piVar15 + 1);
          local_8c = local_8c + 1;
        } while ((int)piVar15 < 0x10);
        local_ac.x = this->m_TeamPos[this->CommanderTeam[this->m_AllyTeams[Team]] * 3];
        local_ac.z = this->m_TeamPos[this->CommanderTeam[this->m_AllyTeams[Team]] * 3 + 2];
        local_ac.y = TerrainFindFloor(local_ac.x,local_ac.z);
        local_ac.y = local_ac.y + 2.5;
        this->ThugCounter[this->CommanderTeam[this->m_AllyTeams[Team]]] =
             this->ThugCounter[this->CommanderTeam[this->m_AllyTeams[Team]]] + 1;
        if (this->m_SpawnFacingCenter == false) {
          VVar1.y = local_ac.y;
          VVar1.x = local_ac.x;
          VVar1.z = local_ac.z;
          pMVar11 = (Matrix *)GetPositionNear(&local_64.right,VVar1,30.0,60.0);
        }
        else {
          local_94 = (code *)(local_80 - local_ac.x);
          local_78 = (code *)(local_74 - local_ac.z);
          dVar16 = (double)((float)local_94 * (float)local_94 + (float)local_78 * (float)local_78);
          libm_sse2_sqrt_precise();
          Center__NewPosition__Front = 0.0;
          local_a0 = (Vector *)((float)local_94 / (float)dVar16);
          local_98 = (float)local_78 / (float)dVar16;
          auVar3._4_4_ = (float)this->ThugCounter[this->CommanderTeam[this->m_AllyTeams[Team]]] *
                         15.0 * 0.017453292;
          auVar3._0_4_ = local_98;
          auVar3._8_4_ = 0;
          pVVar8 = HRotateFront(local_a0,(Vector)(auVar3 << 0x20),(float)unaff_EDI);
          pMVar11 = &local_64;
          local_64.right.x = pVVar8->x * 50.0 + local_ac.x;
          local_64.right.y = pVVar8->y * 50.0 + local_ac.y;
          local_64.right.z = pVVar8->z * 50.0 + local_ac.z;
        }
        local_a0 = (Vector *)(pMVar11->right).x;
        Center__NewPosition__Front = (pMVar11->right).y;
        local_98 = (pMVar11->right).z;
        this->m_TeamPos[(int)local_7c * 3] = (float)local_a0;
        this->m_TeamPos[(int)local_7c * 3 + 1] = Center__NewPosition__Front;
        this->m_TeamPos[(int)local_7c * 3 + 2] = local_98;
        Team = (int)local_7c;
        goto LAB_4fc44c47;
      }
      if (*(char *)((int)(Team + 0xe7a0) + (int)this) == '\0') {
        this->CommanderTeam[this->m_AllyTeams[Team]] = Team;
        this->NumCommanders = this->NumCommanders + 1;
      }
      SetupTeam(this,Team);
      local_ac.z = this->m_TeamPos[Team * 3 + 2];
      local_ac.x = this->m_TeamPos[Team * 3];
      local_ac.y = TerrainFindFloor(local_ac.x,local_ac.z);
    }
    else {
      this->ThugCounter[this->CommanderTeam[this->m_AllyTeams[Team]]] =
           this->ThugCounter[this->CommanderTeam[this->m_AllyTeams[Team]]] + 1;
      local_ac.x = this->m_TeamPos[this->CommanderTeam[this->m_AllyTeams[Team]] * 3];
      local_ac.z = this->m_TeamPos[this->CommanderTeam[this->m_AllyTeams[Team]] * 3 + 2];
      local_ac.y = TerrainFindFloor(local_ac.x,local_ac.z);
      local_ac.y = local_ac.y + 2.5;
      if (this->m_SpawnFacingCenter != false) {
        local_94 = (code *)(local_80 - local_ac.x);
        local_78 = (code *)(local_74 - local_ac.z);
        dVar16 = (double)((float)local_94 * (float)local_94 + (float)local_78 * (float)local_78);
        libm_sse2_sqrt_precise();
        local_a0 = (Vector *)((float)local_94 / (float)dVar16);
        local_98 = (float)local_78 / (float)dVar16;
        iVar9 = this->ThugCounter[this->CommanderTeam[this->m_AllyTeams[Team]]];
        goto LAB_4fc44b66;
      }
      local_ac.z = this->m_TeamPos[Team * 3 + 2];
      local_ac.x = this->m_TeamPos[Team * 3];
      local_ac.y = TerrainFindFloor(local_ac.x,local_ac.z);
    }
    local_ac.y = local_ac.y + 2.5;
  }
LAB_4fc44c47:
  pcVar12 = GetPlayerODF(Team,Randomize_None);
  local_ad = '\x01';
  local_68 = pcVar12;
  local_84 = GetCVarItemStr(Team,0);
  local_78 = SetPilotClass_exref;
  local_94 = SetPosition_exref;
  local_88 = _stricmp_exref;
  local_64.up.x = (float)_strnicmp_exref;
  cVar7 = local_ad;
  if (this->m_RestorePlayers != 0) {
    iVar9 = _strnicmp(pcVar12 + 1,"vcamr_vsr",9);
    if (iVar9 == 0) {
      cVar7 = '\x01';
    }
    else {
      piVar15 = (int *)0x0;
      local_90 = (int *)0x0;
      if (this->m_RestorePlayers == 1) {
        local_64.rightw = (float)this->PlayerShipODF;
        local_8c = (int *)0x0;
        local_6c = this->m_SavedPlayerTeamGroup;
        do {
          iVar9 = (*local_88)(local_84,(char (*) [64])((int)local_64.rightw + 0x800));
          if ((iVar9 == 0) &&
             ((((bVar6 = IsTeamplayOn(), bVar6 &&
                (iVar9 = WhichTeamGroup(Team), *local_6c == iVar9 + 1)) ||
               ((bVar6 = IsTeamplayOn(), !bVar6 && ((int *)*local_6c == (int *)Team)))) &&
              (bVar6 = DoesODFExist((char *)local_64.rightw), bVar6)))) {
            local_90 = local_8c;
            local_ad = '\0';
            piVar15 = local_8c;
            goto LAB_4fc44e87;
          }
          local_6c = local_6c + 1;
          local_8c = (int *)((int)local_8c + 1);
          local_64.rightw = (float)((int)local_64.rightw + 0x40);
        } while ((int)local_8c < 0x10);
        iVar9 = 0;
        pacVar13 = this->PlayerSavedName;
        do {
          if ((*pacVar13)[0] == '\0') {
            strcpy_s(this->PlayerSavedName[Team],0x40,local_84);
            goto LAB_4fc44e87;
          }
          iVar9 = iVar9 + 1;
          pacVar13 = pacVar13 + 1;
          pcVar12 = local_68;
          cVar7 = local_ad;
        } while (iVar9 < 0x10);
      }
      else {
        pcVar12 = local_68;
        cVar7 = local_ad;
        if (this->m_RestorePlayers == 2) {
          bVar6 = IsTeamplayOn();
          if ((((!bVar6) ||
               (iVar9 = WhichTeamGroup(Team), this->m_SavedPlayerTeamGroup[Team] != iVar9 + 1)) &&
              ((bVar6 = IsTeamplayOn(), bVar6 ||
               ((int *)this->m_SavedPlayerTeamGroup[Team] != (int *)Team)))) ||
             (bVar6 = DoesODFExist(this->PlayerShipODF[Team]), !bVar6)) {
            bVar6 = IsTeamplayOn();
            if (bVar6) {
              iVar9 = WhichTeamGroup(Team);
              this->m_SavedPlayerTeamGroup[Team] = iVar9 + 1;
              pcVar12 = local_68;
              cVar7 = local_ad;
              goto LAB_4fc44d8a;
            }
            this->m_SavedPlayerTeamGroup[Team] = Team;
          }
          else {
            local_ad = '\0';
            piVar15 = (int *)Team;
            local_90 = (int *)Team;
          }
LAB_4fc44e87:
          pcVar12 = local_68;
          cVar7 = local_ad;
          if (piVar15 != (int *)0x0) {
            iVar9 = BuildObject(this->PlayerShipODF[(int)piVar15],(int)local_7c,
                                this->PlayerMatrix + (int)piVar15);
            local_70 = iVar9;
            (*local_78)(iVar9,this->SavedPilotODF + (int)piVar15);
            ReplaceWeapons(iVar9,this->PlayerShipWeapons[(int)local_90],
                           this->m_SavedPlayerLocalAmmo[(int)local_90],(char *)0x0);
            SetCurHealth(iVar9,this->m_SavedPlayerHealth[(int)local_90]);
            SetCurAmmo(iVar9,this->m_SavedPlayerAmmo[(int)local_90]);
            (*local_94)(iVar9,this->PlayerMatrix + (int)piVar15);
            piVar15 = local_90;
            SetVelocity(iVar9,this->PlayerVelocity + (int)local_90);
            SetOmega(iVar9,this->PlayerOmega + (int)piVar15);
            memset(&local_64.up.y,0,0x40);
            GetObjInfo(iVar9,Get_GOClass,(char *)&local_64.up.y);
            pcVar5 = local_88;
            iVar14 = (*local_88)(&local_64.up.y,"CLASS_SCAVENGER");
            if ((iVar14 == 0) ||
               (iVar14 = (*pcVar5)(&local_64.up.y,"CLASS_SCAVENGERH"), iVar14 == 0)) {
              SetScavengerCurScrap(iVar9,this->m_SavedPlayerScrap[(int)local_90]);
            }
            if (this->m_SavedPlayerDeployed[(int)local_90] != false) {
              Deploy(iVar9);
            }
            bVar6 = IsTeamplayOn();
            Team = (int)local_7c;
            piVar15 = local_7c;
            if (bVar6) {
              iVar9 = WhichTeamGroup((int)local_7c);
              piVar15 = (int *)(iVar9 + 1);
            }
            this->m_SavedPlayerTeamGroup[(int)local_90] = (int)piVar15;
            this->m_GiveWeaponsBack[(int)local_90] = true;
            pcVar12 = local_68;
            cVar7 = local_ad;
          }
        }
      }
    }
  }
LAB_4fc44d8a:
  if ((this->m_RestorePlayers == 0) || (iVar9 = local_70, cVar7 != '\0')) {
    iVar9 = (*local_88)(local_84,"Krohonus_Legs");
    if (iVar9 == 0) {
      iVar9 = BuildObject("evlegs_vsr",Team,&local_ac);
    }
    else {
      iVar9 = BuildObject(pcVar12,Team,&local_ac);
    }
    local_70 = iVar9;
    iVar14 = (*(code *)local_64.up.x)(local_68 + 1,"vcamr_vsr",9);
    if (iVar14 == 0) {
      SetPerceivedTeam(iVar9,0);
    }
    bVar6 = false;
    cVar7 = GetRaceOfTeam(Team);
    pcVar12 = GetInitialPlayerPilotODF(this,cVar7,Team,bVar6);
    (*local_78)(iVar9,pcVar12);
    if (this->m_SpawnFacingCenter == false) {
      SetRandomHeadingAngle(iVar9);
    }
    else {
      local_74 = local_74 - local_ac.z;
      local_80 = local_80 - local_ac.x;
      dVar16 = (double)(local_74 * local_74 + local_80 * local_80);
      libm_sse2_sqrt_precise();
      local_64.right.y = 0.0;
      local_64.right.x = local_80 / (float)dVar16;
      local_64.right.z = local_74 / (float)dVar16;
      Build_Directinal_Matrix(&local_64,unaff_EDI,unaff_ESI);
      (*local_94)(iVar9,&local_64.up.y);
      iVar9 = local_70;
      VVar2.y = (float)uStack_1c;
      VVar2.x = (float)local_20;
      VVar2.z = fStack_18;
      SetVectorPosition(local_70,VVar2);
    }
  }
  if (local_7c == (int *)0x0) {
    MakeInert(iVar9);
  }
  return iVar9;
}


// ---------------------------------------------------------------------
// Strategy02::Init  @ 4fc43b41  lines 1634-1999

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall Strategy02::Init(Strategy02 *this)

{
  code *pcVar1;
  bool bVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  char *unaff_ESI;
  int iVar8;
  int *piVar9;
  code *pcVar10;
  int *unaff_EDI;
  float10 fVar11;
  float fVar12;
  int *pathNames;
  undefined4 num;
  char *local_520;
  int local_51c;
  undefined8 local_518;
  int pathCount;
  bool CaptureRandom;
  int *local_508;
  int R [15];
  char CaptureTarget [1024];
  char mapTrnFile [128];
  char DesiredValue__VarName [64];
  uint local_8;
  
  local_8 = __security_cookie ^ (uint)&stack0xfffffffc;
  local_518 = (double)CONCAT44(this,(undefined4)local_518);
  pcVar3 = GetVarItemStr("network.session.svar6");
  if ((pcVar3 != (char *)0x0) && (*pcVar3 != '\0')) {
    StartingVehicleManager::Init();
  }
  memset(CaptureTarget,0,0x400);
  local_51c = 0;
  CaptureRandom = false;
  pcVar3 = GetVarItemStr("network.session.svar0");
  strcpy_s(mapTrnFile,0x80,pcVar3);
  pcVar3 = strrchr(mapTrnFile,0x2e);
  if (pcVar3 != (char *)0x0) {
    *pcVar3 = '\0';
    strcat_s(mapTrnFile,0x80,".trn");
    OpenODF2(mapTrnFile);
    GetODFBool(mapTrnFile,"DLL","RespawnAtLowAltitude",&this->m_RespawnAtLowAltitude,false);
    GetODFFloat(mapTrnFile,"DLL","FriendlySpawnpointMaxAllyRange",
                &this->m_FRIENDLY_SPAWNPOINT_MAX_ALLY,100.0);
    GetODFFloat(mapTrnFile,"DLL","FriendlySpawnpointMinEnemyRange",
                &this->m_FRIENDLY_SPAWNPOINT_MIN_ENEMY,400.0);
    GetODFFloat(mapTrnFile,"DLL","RandomSpawnpointMinEnemyRange",
                &this->m_RANDOM_SPAWNPOINT_MIN_ENEMY,450.0);
    pcVar3 = CaptureTarget;
    iVar8 = 0;
    iVar7 = local_51c;
    do {
      iVar8 = iVar8 + 1;
      sprintf_s<64>(&DesiredValue__VarName,"CaptureTarget%d",iVar8);
      iVar4 = GetODFString(mapTrnFile,"DLL",DesiredValue__VarName,0x40,pcVar3,(char *)0x0);
      if (iVar4 == 0) break;
      iVar7 = iVar7 + 1;
      pcVar3 = pcVar3 + 0x40;
    } while (iVar8 < 0x10);
    local_51c = iVar7;
    GetODFBool(mapTrnFile,"DLL","CaptureIsRandom",&CaptureRandom,false);
    this = local_518._4_4_;
    pcVar3 = (local_518._4_4_)->MapAmbientSound;
    GetODFString(mapTrnFile,"VSR","MapAmbientSound",0x40,pcVar3,(char *)0x0);
    bVar2 = DoesFileExist(pcVar3);
    if (bVar2) {
      EasterEggSound = StartAudio2D(pcVar3,-1.0,0.0,44100.0,true,false);
    }
  }
  pcVar10 = GetVarItemInt_exref;
  this->m_DidInit = true;
  iVar7 = GetVarItemInt("network.session.ivar0");
  this->m_KillLimit = iVar7;
  iVar7 = GetVarItemInt("network.session.ivar1");
  this->m_TotalGameTime = iVar7;
  iVar7 = GetVarItemInt("network.session.ivar7");
  this->m_StartingVehiclesMask = iVar7;
  iVar7 = GetVarItemInt("network.session.ivar12");
  this->m_IsMPI = iVar7 != 0;
  iVar8 = 3;
  if (iVar7 != 0) {
    iVar7 = GetVarItemInt("network.session.ivar13");
    this->m_AIRace[0] = iVar7;
    iVar7 = GetVarItemInt("network.session.ivar96");
    this->m_AIRace[1] = iVar7;
    iVar7 = GetVarItemInt("network.session.ivar97");
    this->m_AIRace[2] = iVar7;
    iVar7 = GetVarItemInt("network.session.ivar98");
    this->m_AIRace[3] = iVar7;
    iVar7 = GetVarItemInt("network.session.ivar99");
    this->m_AIRace[4] = iVar7;
    iVar7 = GetVarItemInt("network.session.ivar21");
    if (iVar7 < 0) {
      iVar7 = 0;
    }
    else if (3 < iVar7) {
      iVar7 = iVar8;
    }
    this->m_CPUTurretAISkill = iVar7;
    iVar7 = GetVarItemInt("network.session.ivar22");
    if (iVar7 < 0) {
      iVar7 = 0;
    }
    else if (3 < iVar7) {
      iVar7 = iVar8;
    }
    this->m_CPUNonTurretAISkill = iVar7;
    iVar7 = GetVarItemInt("network.session.ivar23");
    if (iVar7 < 0) {
      iVar7 = 0;
    }
    else if (3 < iVar7) {
      iVar7 = iVar8;
    }
    this->m_HumanForce = iVar7;
    iVar7 = GetVarItemInt("network.session.ivar24");
    if (iVar7 < 0) {
      iVar7 = 0;
    }
    else if (3 < iVar7) {
      iVar7 = iVar8;
    }
    this->m_CPUForce = iVar7;
  }
  iVar7 = GetVarItemInt("network.session.ivar53");
  this->m_GameType = iVar7;
  iVar8 = GetVarItemInt("network.session.ivar54");
  iVar7 = 0x1e;
  if ((0x1d < iVar8) && (iVar7 = iVar8, 0x78 < iVar8)) {
    iVar7 = 0x78;
  }
  piVar9 = &this->m_GameTPS;
  this->m_CaptureTime = *piVar9 * iVar7;
  iVar7 = GetVarItemInt("network.session.ivar14");
  this->m_PointsForAIKill = (uint)(iVar7 != 0);
  iVar7 = GetVarItemInt("network.session.ivar15");
  this->m_KillForAIKill = (uint)(iVar7 != 0);
  iVar7 = GetVarItemInt("network.session.ivar16");
  this->m_RespawnWithSniper = iVar7;
  iVar7 = GetVarItemInt("network.session.ivar32");
  this->m_bIsFriendlyFireOn = iVar7 != 0;
  iVar7 = GetVarItemInt("network.session.ivar55");
  this->m_SetThugPilotFlag = iVar7 != 0;
  iVar7 = GetVarItemInt("network.session.ivar118");
  this->m_SpawnFacingCenter = iVar7 != 0;
  iVar7 = GetVarItemInt("network.session.ivar119");
  if (iVar7 < 0) {
    iVar7 = 0;
  }
  else if (2 < iVar7) {
    iVar7 = 2;
  }
  this->m_RestorePlayers = iVar7;
  iVar7 = GetVarItemInt("network.session.ivar120");
  if (iVar7 < 0) {
    iVar7 = 0;
  }
  else if (0x78 < iVar7) {
    iVar7 = 0x78;
  }
  this->m_PilotInvunerability = *piVar9 * iVar7;
  iVar7 = GetVarItemInt("network.session.ivar121");
  if (iVar7 < 0) {
    iVar7 = 0;
  }
  else if (3 < iVar7) {
    iVar7 = 3;
  }
  this->m_MorphTankAutoDeployType = iVar7;
  iVar7 = GetVarItemInt("network.session.ivar17");
  if (iVar7 < 0) {
    iVar7 = 0;
  }
  else if (3 < iVar7) {
    iVar7 = 3;
  }
  this->m_TurretAISkill = iVar7;
  iVar7 = GetVarItemInt("network.session.ivar18");
  if (iVar7 < 0) {
    iVar7 = 0;
  }
  else if (3 < iVar7) {
    iVar7 = 3;
  }
  this->m_NonTurretAISkill = iVar7;
  pathNames = this->m_AllyTeams;
  memset(pathNames,0,0x40);
  bVar2 = IsTeamplayOn();
  if ((!bVar2) || (this->m_IsMPI != false)) {
    memset(DesiredValue__VarName,0,0x40);
    local_508 = this->m_AllyTeams + 1;
    iVar7 = 0x51;
    do {
      sprintf_s<64>(&DesiredValue__VarName,"network.session.ivar%d",iVar7 + -0x2e);
      iVar8 = GetVarItemInt(DesiredValue__VarName);
      *local_508 = iVar8;
      if (iVar8 < 1) {
        *local_508 = iVar7 + -0x50;
      }
      sprintf_s<64>(&DesiredValue__VarName,"network.session.ivar%d",iVar7);
      iVar8 = GetVarItemInt(DesiredValue__VarName);
      if (iVar8 < 0) {
        iVar8 = 0;
      }
      else if (1 < iVar8) {
        iVar8 = 1;
      }
      local_508 = local_508 + 1;
      *(bool *)((int)this->BuildEmpty + iVar7 + 0x30) = iVar8 != 0;
      iVar8 = iVar7 + -0x4f;
      iVar7 = iVar7 + 1;
    } while (iVar8 < 0x10);
    bVar2 = IsTeamplayOn();
    if (bVar2) {
      R[0] = 0;
      R[1] = 0;
      R[2] = 0;
      R[3] = 0;
      R[4] = 0;
      R[5] = 0;
      R[6] = 0;
      R[7] = 0;
      R[8] = 0;
      R[9] = 0;
      iVar8 = 1;
      R[10] = 0;
      R[0xb] = 0;
      R[0xc] = 0;
      R[0xd] = 0;
      R[0xe] = 0;
      iVar7 = iVar8;
      do {
        GetTeamStratIndividualColor
                  (TEAMCOLOR_TYPE_GAMEPREFS,iVar7,R + iVar7,R + iVar7 + 5,R + iVar7 + 10);
        iVar7 = iVar7 + 1;
      } while (iVar7 < 6);
      DefaultAllies();
      SetFFATeamColors(TEAMCOLOR_TYPE_GAMEPREFS);
      piVar9 = (int *)((int)local_518._4_4_ + 0xe408);
      do {
        SetTeamColor(iVar8,R[iVar8],R[iVar8 + 5],R[iVar8 + 10]);
        iVar7 = 1;
        local_508 = piVar9;
        do {
          if ((iVar8 != iVar7) && (Ally(iVar8,iVar7), iVar8 == 1)) {
            *local_508 = *piVar9;
          }
          iVar7 = iVar7 + 1;
          local_508 = local_508 + 1;
        } while (iVar7 < 6);
        iVar8 = iVar8 + 1;
        this = local_518._4_4_;
      } while (iVar8 < 6);
    }
    iVar7 = 1;
    do {
      local_508 = this->m_AllyTeams + 1;
      iVar8 = 1;
      pathCount = 1;
      do {
        if (((0 < this->m_AllyTeams[iVar7]) && (iVar7 != iVar8)) &&
           (this->m_AllyTeams[iVar7] == *local_508)) {
          Ally(iVar7,iVar8);
          this->m_HasAllies[iVar7] = true;
          bVar2 = IsTeamplayOn();
          if ((bVar2) && (iVar7 == 1)) {
            pathCount = GetFirstAlliedTeam(1);
            iVar5 = GetLastAlliedTeam(1);
            iVar4 = pathCount;
            if (pathCount < iVar5 + 1) {
              do {
                Ally(iVar4,iVar8);
                iVar4 = iVar4 + 1;
                iVar5 = GetLastAlliedTeam(1);
              } while (iVar4 < iVar5 + 1);
              this = local_518._4_4_;
            }
          }
        }
        iVar8 = iVar8 + 1;
        local_508 = local_508 + 1;
      } while (iVar8 < 0x10);
      iVar7 = iVar7 + 1;
    } while (iVar7 < 0x10);
    iVar7 = -(int)this;
    pathCount = iVar7 + -0xe404;
    iVar8 = 1;
    piVar9 = this->m_AllyTeams;
    pcVar10 = GetVarItemInt_exref;
    do {
      pcVar1 = GetVarItemInt_exref;
      piVar9 = piVar9 + 1;
      if (this->m_TeamHasCommander[*piVar9] == false) {
        iVar4 = 0;
        local_520 = (char *)(iVar7 + (int)this);
        local_508 = this->m_AllyTeams;
        do {
          if ((this->m_ThugFlag[iVar4] == false) &&
             (pcVar10 = GetVarItemInt_exref, *(int *)((int)local_520 + (int)piVar9) == *local_508))
          {
            this->m_TeamHasCommander[*piVar9] = true;
            pcVar10 = pcVar1;
            break;
          }
          iVar4 = iVar4 + 1;
          local_508 = local_508 + 1;
        } while (iVar4 < 0x10);
        if (this->m_TeamHasCommander[*piVar9] == false) {
          iVar4 = 0;
          piVar6 = this->m_AllyTeams;
          do {
            pcVar10 = GetVarItemInt_exref;
            this = local_518._4_4_;
            if (*piVar6 == pathNames[iVar8]) {
              (local_518._4_4_)->m_ThugFlag[iVar4] = false;
              (local_518._4_4_)->m_TeamHasCommander[*piVar9] = true;
              break;
            }
            iVar4 = iVar4 + 1;
            piVar6 = piVar6 + 1;
          } while (iVar4 < 0x10);
        }
      }
      iVar8 = iVar8 + 1;
    } while (iVar8 < 0x10);
    piVar9 = &this->m_GameTPS;
  }
  iVar7 = (*pcVar10)();
  this->m_RecyInvulnerabilityTime = *piVar9 * iVar7 * 0x3c;
  iVar7 = GetPlayerHandle();
  if (iVar7 != 0) {
    RemoveObject(iVar7);
  }
  bVar2 = ImServer();
  if ((bVar2) || (bVar2 = IsNetworkOn(), !bVar2)) {
    this->m_ElapsedGameTime = 0;
    if (this->m_RemainingGameTime == 0) {
      this->m_RemainingGameTime = this->m_TotalGameTime * *piVar9 * 0x3c;
    }
    if (this->m_IsMPI != false) {
      this->m_LastTauntPrintedAt = -2000;
      InitTaunts(piVar9,&this->m_ElapsedGameTime,unaff_EDI,unaff_ESI);
    }
  }
  iVar7 = GetLocalPlayerTeamNumber();
  iVar8 = SetupPlayer(this,iVar7);
  SetAsUser(iVar8,iVar7);
  AddPilotByHandle(iVar8);
  if (this->m_GameType == 4) {
    local_518 = (double)((ulonglong)local_518 & 0xffffffff);
    GetAiPaths(&pathCount,(char ***)&pathNames);
    iVar8 = 0;
    iVar7 = local_51c;
    if (0 < pathCount) {
      do {
        local_520 = (char *)pathNames[iVar8];
        if (iVar7 < 1) {
          PrintConsoleMessage("Error: Map has no Capture ODF\'s set!");
        }
        else {
          num = 0xffffffff;
          iVar4 = sscanf_s(local_520,"capturegoal%d",(int)&num);
          if ((0 < iVar4) && (this->m_NumCaptureGoals < 0x10)) {
            if (CaptureRandom == false) {
              fVar12 = (float)local_518._4_4_;
              if ((float)iVar7 < (float)local_518._4_4_) {
                fVar12 = 0.0;
                goto LAB_4fc444ab;
              }
            }
            else {
              fVar12 = GetRandomFloat((float)iVar7);
              fVar11 = floor((double)fVar12);
              local_518 = (double)fVar11;
              fVar12 = (float)iVar7;
              if ((float)fVar11 <= (float)iVar7) {
                fVar12 = (float)fVar11;
              }
LAB_4fc444ab:
              local_518 = (double)CONCAT44(fVar12,(undefined4)local_518);
            }
            pcVar3 = CaptureTarget + (int)fVar12 * 0x40;
            bVar2 = DoesODFExist(pcVar3);
            if (bVar2) {
              iVar7 = BuildObject(pcVar3,0,local_520);
              this->m_CaptureGoals[this->m_NumCaptureGoals] = iVar7;
              bVar2 = IsAround(this->m_CaptureGoals[this->m_NumCaptureGoals]);
              if (bVar2) {
                SetObjectiveOn(this->m_CaptureGoals[this->m_NumCaptureGoals]);
                this->m_NumCaptureGoals = this->m_NumCaptureGoals + 1;
              }
              local_518 = (double)CONCAT44((float)local_518._4_4_ + 1.0,(undefined4)local_518);
              iVar7 = local_51c;
            }
            else {
              sprintf_s<1024>(&TempMsgString,"Error: ODF \'%s\' doesn\'t exist!",pcVar3);
              PrintConsoleMessage(TempMsgString);
              iVar7 = local_51c;
            }
          }
        }
        iVar8 = iVar8 + 1;
      } while (iVar8 < pathCount);
    }
  }
  return;
}


// ---------------------------------------------------------------------
// Strategy02::UpdateGameTime  @ 4fc439c6  lines 2003-2074

void __thiscall Strategy02::UpdateGameTime(Strategy02 *this)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  
  iVar4 = this->m_ElapsedGameTime + 1;
  iVar2 = this->m_GameTPS;
  this->m_ElapsedGameTime = iVar4;
  if (this->m_RemainingGameTime < 1) {
    if (iVar4 % iVar2 == 0) {
      if ((iVar4 / iVar2) / 0xe10 == 0) {
        pcVar3 = GetBZCCLocalizedString("mission","Mission Time %d:%02d");
        sprintf_s<1024>(&TempMsgString,pcVar3);
      }
      else {
        pcVar3 = GetBZCCLocalizedString("mission","Mission Time %d:%02d:%02d");
        sprintf_s<1024>(&TempMsgString,pcVar3);
      }
      SetTimerBox(TempMsgString);
    }
  }
  else {
    iVar4 = this->m_RemainingGameTime + -1;
    this->m_RemainingGameTime = iVar4;
    if (iVar4 % iVar2 == 0) {
      iVar1 = (iVar4 / iVar2) / 0x3c;
      iVar4 = (iVar4 / iVar2) % 0x3c;
      iVar2 = iVar1 / 0x3c;
      iVar1 = iVar1 % 0x3c;
      if (iVar2 == 0) {
        pcVar3 = GetBZCCLocalizedString("mission","Time Left %d:%02d\n");
        sprintf_s<1024>(&TempMsgString,pcVar3);
      }
      else {
        pcVar3 = GetBZCCLocalizedString("mission","Time Left %d:%02d:%02d\n");
        sprintf_s<1024>(&TempMsgString,pcVar3);
      }
      SetTimerBox(TempMsgString);
      if ((iVar2 == 0) &&
         (((iVar4 == 0 && ((iVar1 < 0xb || (iVar1 % 5 == 0)))) || ((iVar1 == 0 && (iVar4 % 5 == 0)))
          ))) {
        AddToMessagesBox(TempMsgString);
      }
    }
    if (this->m_RemainingGameTime == 0) {
      NoteGameoverByTimelimit();
      DoGameover(10.0);
    }
  }
  return;
}


// ---------------------------------------------------------------------
// Strategy02::ExecuteRecyInvulnerability  @ 4fc43854  lines 2078-2136

void __thiscall Strategy02::ExecuteRecyInvulnerability(Strategy02 *this)

{
  bool bVar1;
  int h;
  long lVar2;
  char *pcVar3;
  int *piVar4;
  int iVar5;
  Strategy02 *TempH;
  int *local_8;
  
  if (this->m_GameOver != false) {
    return;
  }
  iVar5 = 0;
  if (this->m_RecyInvulnerabilityTime == 0) {
    return;
  }
  piVar4 = this->m_RecyclerHandles;
  TempH = this;
  do {
    local_8 = piVar4;
    if (this->m_TeamIsSetUp[iVar5] != false) {
      TempH = (Strategy02 *)*piVar4;
      bVar1 = IsAlive((int *)&TempH);
      if ((bVar1) && (TempH != (Strategy02 *)0x0)) {
        h = *piVar4;
      }
      else {
        h = GetObjectByTeamSlot(iVar5,1);
      }
      if ((h != 0) && (bVar1 = DLLUtils::IsRecycler(h), bVar1)) {
        lVar2 = GetMaxHealth(h);
        SetCurHealth(h,lVar2);
      }
    }
    iVar5 = iVar5 + 1;
    piVar4 = local_8 + 1;
  } while (iVar5 < 0x10);
  iVar5 = this->m_RecyInvulnerabilityTime;
  local_8 = piVar4;
  if (iVar5 == 1) {
    pcVar3 = GetBZCCLocalizedString("strat","recyclersVulnerable");
    sprintf_s<1024>(&TempMsgString,pcVar3);
  }
  else {
    TempH = (Strategy02 *)(this->m_GameTPS * 0x3c);
    if ((iVar5 % (int)TempH != 0) &&
       (((int)TempH <= iVar5 || (iVar5 % (this->m_GameTPS * 0xf) != 0)))) goto LAB_4fc439b8;
    if ((int)TempH < iVar5) {
      pcVar3 = GetBZCCLocalizedString("strat","invulnerableExpiresMin");
    }
    else {
      pcVar3 = GetBZCCLocalizedString("strat","invulnerableExpiresSec");
    }
    sprintf_s<1024>(&TempMsgString,pcVar3);
  }
  AddToMessagesBox2(TempMsgString,0xffff00ff);
  iVar5 = this->m_RecyInvulnerabilityTime;
LAB_4fc439b8:
  this->m_RecyInvulnerabilityTime = iVar5 + -1;
  return;
}


// ---------------------------------------------------------------------
// Strategy02::ExecuteCheckIfGameOver  @ 4fc43263  lines 2139-2426

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall Strategy02::ExecuteCheckIfGameOver(Strategy02 *this)

{
  uint uVar1;
  bool bVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  uint uVar7;
  char *pcVar8;
  char cVar9;
  int iVar10;
  Strategy02 *pSVar11;
  float *pfVar12;
  int iVar13;
  Vector RecyPos;
  Strategy02 *local_8c;
  int local_88;
  int TempH;
  uint local_80;
  int local_7c;
  float *local_78;
  int *local_74;
  int *local_70;
  char local_6a;
  char local_69;
  char TeamName [64];
  char TeamIsFunctioning__AIWon [32];
  uint local_8;
  
  local_8 = __security_cookie ^ (uint)&stack0xfffffffc;
  if ((this->m_GameOver == false) && (this->m_GameTPS <= this->m_ElapsedGameTime)) {
    iVar10 = 0;
    local_80 = this->m_ElapsedGameTime & 0xffffff00;
    local_8c = this;
    local_69 = IsTeamplayOn();
    TeamIsFunctioning__AIWon[0] = '\0';
    TeamIsFunctioning__AIWon[1] = '\0';
    TeamIsFunctioning__AIWon[2] = '\0';
    TeamIsFunctioning__AIWon[3] = '\0';
    TeamIsFunctioning__AIWon[4] = '\0';
    TeamIsFunctioning__AIWon[5] = '\0';
    TeamIsFunctioning__AIWon[6] = '\0';
    TeamIsFunctioning__AIWon[7] = '\0';
    TeamIsFunctioning__AIWon[8] = '\0';
    TeamIsFunctioning__AIWon[9] = '\0';
    TeamIsFunctioning__AIWon[10] = '\0';
    TeamIsFunctioning__AIWon[0xb] = '\0';
    TeamIsFunctioning__AIWon[0xc] = '\0';
    TeamIsFunctioning__AIWon[0xd] = '\0';
    TeamIsFunctioning__AIWon[0xe] = '\0';
    TeamIsFunctioning__AIWon[0xf] = '\0';
    TeamIsFunctioning__AIWon[0x10] = '\0';
    TeamIsFunctioning__AIWon[0x11] = '\0';
    TeamIsFunctioning__AIWon[0x12] = '\0';
    TeamIsFunctioning__AIWon[0x13] = '\0';
    TeamIsFunctioning__AIWon[0x14] = '\0';
    TeamIsFunctioning__AIWon[0x15] = '\0';
    TeamIsFunctioning__AIWon[0x16] = '\0';
    TeamIsFunctioning__AIWon[0x17] = '\0';
    TeamIsFunctioning__AIWon[0x18] = '\0';
    TeamIsFunctioning__AIWon[0x19] = '\0';
    TeamIsFunctioning__AIWon[0x1a] = '\0';
    TeamIsFunctioning__AIWon[0x1b] = '\0';
    TeamIsFunctioning__AIWon[0x1c] = '\0';
    TeamIsFunctioning__AIWon[0x1d] = '\0';
    TeamIsFunctioning__AIWon[0x1e] = '\0';
    TeamIsFunctioning__AIWon[0x1f] = '\0';
    piVar6 = this->m_AllyTeams;
    local_78 = this->m_TeamPos + 1;
    local_70 = piVar6;
    do {
      local_74 = piVar6;
      if (this->m_TeamIsSetUp[iVar10] != false) {
        local_6a = '\0';
        TempH = piVar6[0x1df];
        bVar2 = IsAround(TempH);
        if (!bVar2) {
          TempH = GetObjectByTeamSlot(iVar10,1);
        }
        if ((TempH == 0) || (bVar2 = IsAlive(&TempH), !bVar2)) {
          piVar6[0x1df] = 0;
        }
        else {
          local_6a = '\x01';
        }
        bVar2 = IsAlive(&TempH);
        iVar4 = TempH;
        if (bVar2) {
LAB_4fc43365:
          if ((iVar4 != 0) || (iVar4 = GetObjectByTeamSlot(iVar10,2), cVar9 = local_6a, iVar4 != 0))
          goto LAB_4fc4337a;
        }
        else {
          if (TempH == 0) {
            iVar4 = GetObjectByTeamSlot(iVar10,1);
            goto LAB_4fc43365;
          }
LAB_4fc4337a:
          if (this->m_IsMPI != false) {
            local_80 = local_80 & 0xff;
            if (iVar10 < 0xb) {
              local_80 = 1;
            }
          }
          cVar9 = '\x01';
        }
        iVar5 = *local_74;
        if ((TeamIsFunctioning__AIWon[iVar5 + 0x10] == '\0') && (cVar9 == '\0')) {
          cVar3 = '\0';
        }
        else {
          cVar3 = '\x01';
        }
        bVar2 = this->m_NotedRecyclerLocation[iVar10];
        TeamIsFunctioning__AIWon[iVar5 + 0x10] = cVar3;
        TeamIsFunctioning__AIWon[iVar10] = cVar9;
        if ((bVar2 == false) || ((char)this->m_ElapsedGameTime == '\0')) {
          if (local_69 == '\0') {
            if ((iVar4 == 0) &&
               (iVar4 = GetObjectByTeamSlot(this->CommanderTeam[iVar5],1), iVar4 == 0)) {
              iVar4 = GetObjectByTeamSlot(this->CommanderTeam[*local_74],2);
              goto LAB_4fc43414;
            }
          }
          else {
LAB_4fc43414:
            if (iVar4 == 0) {
              local_7c = 1;
              do {
                if (((iVar10 != local_7c) && (bVar2 = IsTeamAllied(iVar10,local_7c), bVar2)) &&
                   ((iVar4 = GetObjectByTeamSlot(local_7c,1), iVar4 != 0 ||
                    (iVar4 = GetObjectByTeamSlot(local_7c,2), iVar4 != 0)))) goto LAB_4fc4346c;
                local_7c = local_7c + 1;
              } while (local_7c < 0x10);
              if (iVar4 == 0) goto LAB_4fc43526;
            }
          }
LAB_4fc4346c:
          this->m_NotedRecyclerLocation[iVar10] = true;
          GetPosition(iVar4,&RecyPos);
          local_78[-1] = RecyPos.x;
          *local_78 = RecyPos.y;
          local_78[1] = RecyPos.z;
          if (local_69 != '\0') {
            iVar4 = GetFirstAlliedTeam(iVar10);
            local_7c = iVar4;
            iVar5 = GetLastAlliedTeam(iVar10);
            if (iVar4 <= iVar5) {
              iVar5 = local_7c;
              pfVar12 = this->m_TeamPos + iVar4 * 3 + 1;
              do {
                iVar5 = iVar5 + 1;
                pfVar12[-1] = RecyPos.x;
                *pfVar12 = RecyPos.y;
                pfVar12[1] = RecyPos.z;
                iVar4 = GetLastAlliedTeam(iVar10);
                this = local_8c;
                pfVar12 = pfVar12 + 3;
              } while (iVar5 <= iVar4);
            }
          }
        }
      }
LAB_4fc43526:
      pSVar11 = local_8c;
      iVar10 = iVar10 + 1;
      piVar6 = local_74 + 1;
      local_78 = local_78 + 3;
    } while (iVar10 < 0x10);
    iVar4 = 0;
    iVar10 = 0;
    do {
      if ((this->m_IsMPI == false) && (local_69 != '\0')) {
        local_88 = iVar10 + 1;
        if (TeamIsFunctioning__AIWon[iVar4] == '\0') {
          local_88 = iVar10;
        }
      }
      else {
        local_88 = iVar10;
        if (TeamIsFunctioning__AIWon[iVar4 + 0x10] != '\0') {
          local_88 = iVar10 + 1;
        }
      }
      iVar4 = iVar4 + 1;
      iVar10 = local_88;
    } while (iVar4 < 0x10);
    local_74 = piVar6;
    if ((this->m_IsMPI != false) && ((char)local_80 == '\0')) {
      NoteGameoverWithCustomMessage("All Human bases destroyed!");
      DoGameover(10.0);
      pSVar11->m_GameOver = true;
    }
    if (local_88 < 2) {
      if ((local_88 == 0) && (pSVar11->m_GameTPS * 5 < pSVar11->m_ElapsedGameTime)) {
        NoteGameoverByNoBases();
        DoGameover(10.0);
      }
      else {
        if (pSVar11->m_HadMultipleFunctioningTeams == false) {
          return;
        }
        if (local_88 != 1) {
          return;
        }
        if (local_69 == '\0') {
          TeamIsFunctioning__AIWon[0] = '\0';
          TeamIsFunctioning__AIWon[1] = '\0';
          TeamIsFunctioning__AIWon[2] = '\0';
          TeamIsFunctioning__AIWon[3] = '\0';
          TeamIsFunctioning__AIWon[4] = '\0';
          TeamIsFunctioning__AIWon[5] = '\0';
          TeamIsFunctioning__AIWon[6] = '\0';
          TeamIsFunctioning__AIWon[7] = '\0';
          TeamIsFunctioning__AIWon[8] = '\0';
          TeamIsFunctioning__AIWon[9] = '\0';
          TeamIsFunctioning__AIWon[10] = '\0';
          TeamIsFunctioning__AIWon[0xb] = '\0';
          TeamIsFunctioning__AIWon[0xc] = '\0';
          TeamIsFunctioning__AIWon[0xd] = '\0';
          TeamIsFunctioning__AIWon[0xe] = '\0';
          TeamIsFunctioning__AIWon[0xf] = '\0';
          piVar6 = pSVar11->m_AllyTeams;
          iVar10 = 0;
          do {
            if (pSVar11->m_IsMPI != false) {
              if (iVar10 < 0xb) {
                iVar4 = 5;
              }
              else {
                iVar4 = 4;
              }
              DoTaunt(iVar4);
              piVar6 = local_70;
            }
            iVar4 = *piVar6;
            if (TeamIsFunctioning__AIWon[iVar4 + 0x10] != '\0') {
              if ((pSVar11->m_IsMPI == false) || (iVar10 < 0xb)) {
                if (pSVar11->m_HasAllies[iVar10] == false) {
                  iVar4 = GetPlayerHandle(iVar10);
                  NoteGameoverByLastWithBase(iVar4);
                }
                else {
                  pcVar8 = GetBZCCLocalizedString("cfg","Team");
                  sprintf_s<64>(&TeamName,"%s %d",pcVar8,iVar4);
                  pcVar8 = GetBZCCLocalizedString("Network","HitLastWithBaseStr");
                  sprintf_s<1024>(&TempMsgString,pcVar8);
                  iVar4 = 0;
                  do {
                    if ((iVar10 != iVar4) && (bVar2 = IsTeamAllied(iVar10,iVar4), bVar2)) {
                      iVar13 = 100;
                      iVar5 = GetPlayerHandle(iVar4);
                      AddScore(iVar5,iVar13);
                    }
                    iVar4 = iVar4 + 1;
                    pSVar11 = local_8c;
                  } while (iVar4 < 0x10);
                }
              }
              else {
                iVar5 = iVar10;
                if (pSVar11->m_HasAllies[iVar10] != false) {
                  if (TeamIsFunctioning__AIWon[iVar4] != '\0') goto LAB_4fc43804;
                  TeamIsFunctioning__AIWon[iVar4] = '\x01';
                  iVar5 = iVar4;
                }
                sprintf_s<1024>(&TempMsgString,
                                "Computer Team %d has won, destroyed all enemy bases.",iVar5);
                NoteGameoverWithCustomMessage(TempMsgString);
              }
LAB_4fc43804:
              iVar5 = 100;
              iVar4 = GetPlayerHandle(iVar10);
              AddScore(iVar4,iVar5);
            }
            iVar10 = iVar10 + 1;
            piVar6 = local_70 + 1;
            local_70 = piVar6;
          } while (iVar10 < 0x10);
        }
        else {
          local_80 = 0xffffffff;
          TeamIsFunctioning__AIWon[0x10] = '\0';
          TeamIsFunctioning__AIWon[0x11] = '\0';
          TeamIsFunctioning__AIWon[0x12] = '\0';
          TeamIsFunctioning__AIWon[0x13] = '\0';
          TeamIsFunctioning__AIWon[0x14] = '\0';
          TeamIsFunctioning__AIWon[0x15] = '\0';
          TeamIsFunctioning__AIWon[0x16] = '\0';
          TeamIsFunctioning__AIWon[0x17] = '\0';
          TeamIsFunctioning__AIWon[0x18] = '\0';
          TeamIsFunctioning__AIWon[0x19] = '\0';
          TeamIsFunctioning__AIWon[0x1a] = '\0';
          TeamIsFunctioning__AIWon[0x1b] = '\0';
          TeamIsFunctioning__AIWon[0x1c] = '\0';
          TeamIsFunctioning__AIWon[0x1d] = '\0';
          TeamIsFunctioning__AIWon[0x1e] = '\0';
          TeamIsFunctioning__AIWon[0x1f] = '\0';
          piVar6 = pSVar11->m_AllyTeams;
          iVar10 = 0;
          do {
            if (TeamIsFunctioning__AIWon[iVar10] != '\0') {
              if (pSVar11->m_IsMPI != false) {
                if (iVar10 < 0xb) {
                  iVar4 = 5;
                }
                else {
                  iVar4 = 4;
                }
                DoTaunt(iVar4);
              }
              piVar6 = local_70;
              if (local_80 == 0xffffffff) {
                if ((pSVar11->m_IsMPI == false) || (iVar10 < 0xb)) {
                  local_80 = WhichTeamGroup(iVar10);
                  NoteGameoverByLastTeamWithBase(local_80);
                  piVar6 = local_70;
                }
                else {
                  iVar4 = iVar10;
                  if (pSVar11->m_HasAllies[iVar10] != false) {
                    iVar4 = *local_70;
                    if (TeamIsFunctioning__AIWon[iVar4 + 0x10] != '\0') goto LAB_4fc436a8;
                    TeamIsFunctioning__AIWon[iVar4 + 0x10] = '\x01';
                  }
                  sprintf_s<1024>(&TempMsgString,
                                  "Computer Team %d has won, destroyed all enemy bases.",iVar4);
                  NoteGameoverWithCustomMessage(TempMsgString);
                  piVar6 = local_70;
                }
              }
            }
LAB_4fc436a8:
            uVar1 = local_80;
            iVar10 = iVar10 + 1;
            piVar6 = piVar6 + 1;
            local_70 = piVar6;
          } while (iVar10 < 0x10);
          iVar10 = 0;
          do {
            uVar7 = WhichTeamGroup(iVar10);
            if (uVar7 == uVar1) {
              iVar5 = 100;
              iVar4 = GetPlayerHandle(iVar10);
              AddScore(iVar4,iVar5);
            }
            iVar10 = iVar10 + 1;
          } while (iVar10 < 0x10);
        }
        DoGameover(10.0);
      }
      pSVar11->m_GameOver = true;
    }
    else {
      pSVar11->m_HadMultipleFunctioningTeams = true;
    }
  }
  return;
}


// ---------------------------------------------------------------------
// Strategy02::Execute  @ 4fc41f90  lines 2429-3019

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall Strategy02::Execute(Strategy02 *this)

{
  MorphTankClass *pMVar1;
  undefined4 *puVar2;
  Vector VVar3;
  Vector VVar4;
  Vector VVar5;
  Vector VVar6;
  Vector VVar7;
  Vector Where_00;
  undefined3 uVar8;
  int *piVar9;
  char cVar10;
  bool bVar11;
  int iVar12;
  int iVar13;
  undefined1 *puVar14;
  char (*pacVar15) [64];
  float *pfVar16;
  long lVar17;
  code *pcVar18;
  int iVar19;
  char *pcVar20;
  Vector *pVVar21;
  EmptyShipClass *pEVar22;
  Strategy02 *this_00;
  Strategy02 *this_01;
  Strategy02 *this_02;
  Strategy02 *this_03;
  Strategy02 *this_04;
  Strategy02 *this_05;
  Strategy02 *this_06;
  EmptyShipClass *entry;
  MorphTankClass *entry_00;
  undefined4 *puVar23;
  float unaff_ESI;
  float (*pafVar24) [5];
  int *piVar25;
  size_t sVar26;
  code *pcVar27;
  undefined4 unaff_EDI;
  int *piVar28;
  int *piVar29;
  EmptyShipClass *entry_01;
  MorphTankClass *entry_02;
  undefined4 *puVar30;
  Strategy02 *pSVar31;
  float fVar32;
  Vector local_424;
  Vector local_418;
  Vector local_40c;
  Vector local_400;
  Vector local_3f4;
  code *local_3e8;
  code *local_3e4;
  code *local_3e0;
  code *local_3dc;
  code *local_3d8;
  code *local_3d4;
  code *local_3d0;
  code *local_3cc;
  code *local_3c8;
  code *local_3c4;
  code *local_3c0;
  code *local_3bc;
  code *local_3b8;
  code *local_3b4;
  Vector Where;
  code *local_3a4;
  code *local_3a0;
  code *local_39c;
  code *local_398;
  code *local_394;
  float (*local_390) [5];
  code *local_38c;
  code *local_388;
  float (*local_384) [5];
  char (*local_380) [64];
  code *local_37c;
  code *local_378;
  EmptyShipClass *local_374;
  MorphTankClass *local_370;
  EmptyShipClass *local_36c;
  int *local_368;
  code *local_364;
  EmptyShipClass *local_360;
  int local_35c;
  int *local_358;
  int *local_354;
  char local_34d;
  Strategy02 *local_34c;
  char local_348 [64];
  char AITeamName [64];
  char SentODF [64];
  char GTowODF [64];
  char TankODF [64];
  char ScavODF [64];
  char ScoutODF [64];
  char TempODF2 [64];
  char CPURecy [64];
  char PathName [64];
  char PilotODF__TempODF [64];
  char ObjClass__TurretODF [64];
  char PlayerODF__VariantName;
  undefined1 local_47 [63];
  uint local_8;
  
  local_8 = __security_cookie ^ (uint)&stack0xfffffffc;
  local_34c = this;
  if (this->StopScript == false) {
    LuaMission::Execute(&this->super_LuaMission);
  }
  if (this->m_DidInit == false) {
    Init(this);
  }
  ExecuteRecyInvulnerability(this);
  ExecuteCheckIfGameOver(this);
  UpdateGameTime(this);
  if (this->m_GameType == 4) {
    ExecuteST_Capture(this);
  }
  local_34d = IsTeamplayOn();
  piVar28 = this->m_PilotInvTime;
  local_364 = IsAround_exref;
  local_3a4 = GetCurAmmo_exref;
  local_3e8 = GetMaxAmmo_exref;
  local_37c = SetMaxHealth_exref;
  local_360 = (EmptyShipClass *)GetObjInfo_exref;
  local_3e0 = DoesODFExist_exref;
  local_388 = _strnicmp_exref;
  local_3dc = SetPerceivedTeam_exref;
  local_3d8 = UnAlly_exref;
  local_3d4 = GetFirstAlliedTeam_exref;
  local_394 = GetLastAlliedTeam_exref;
  local_398 = Ally_exref;
  local_3d0 = GetCVarItemStr_exref;
  local_3cc = GetPilotClass_exref;
  local_38c = _stricmp_exref;
  local_36c = (EmptyShipClass *)WhichTeamGroup_exref;
  local_3b4 = GetCurHealth_exref;
  local_3b8 = GetPosition_exref;
  local_3bc = GetVelocity_exref;
  local_3c0 = GetOmega_exref;
  local_3c4 = GetScavengerCurScrap_exref;
  local_3c8 = IsDeployed_exref;
  local_39c = strchr_exref;
  local_3a0 = strncpy_s_exref;
  local_378 = strcpy_s_exref;
  local_358 = (int *)0x0;
  local_374 = (EmptyShipClass *)GetPlayerHandle_exref;
  local_3e4 = strrchr_exref;
  do {
    piVar25 = local_358;
    local_354 = piVar28;
    local_35c = (*(code *)local_374)(local_358);
    cVar10 = (*local_364)(local_35c);
    if (cVar10 != '\0') {
      if ((0 < *piVar28) && (piVar28[0x19c] == local_35c)) {
        *piVar28 = *piVar28 + -1;
        iVar12 = (*local_3e8)(piVar28[0x19c]);
        iVar13 = (*local_3a4)(piVar28[0x19c]);
        if (iVar13 < iVar12) {
          *piVar28 = 0;
          iVar12 = 0;
        }
        else {
          iVar12 = *piVar28;
        }
        piVar25 = local_358;
        if ((iVar12 < 1) &&
           (cVar10 = (*local_364)(piVar28[0x19c]), piVar25 = local_358, cVar10 != '\0')) {
          (*local_37c)(piVar28[0x19c],piVar28[0x10]);
          piVar25 = local_358;
        }
      }
      memset(&PlayerODF__VariantName,0,0x40);
      (*(code *)local_360)(local_35c,0,&PlayerODF__VariantName);
      cVar10 = (*local_3e0)(&PlayerODF__VariantName);
      if (cVar10 == '\0') {
        iVar12 = (*local_39c)(&PlayerODF__VariantName,0x3a);
        (*local_3a0)(&PlayerODF__VariantName,0x40,&PlayerODF__VariantName,
                     iVar12 - (int)&PlayerODF__VariantName);
      }
      iVar12 = (*local_388)(local_47,"vcamr_vsr",9);
      piVar29 = local_354;
      if (iVar12 == 0) {
        (*local_3dc)(local_35c,0);
        pcVar18 = local_3d8;
        if (this->IsCameraPod[(int)piVar25] == false) {
          piVar28 = (int *)0x1;
          do {
            if (piVar28 != piVar25) {
              (*pcVar18)(piVar28,piVar25);
            }
            piVar28 = (int *)((int)piVar28 + 1);
          } while ((int)piVar28 < 0x10);
          local_34c->IsCameraPod[(int)piVar25] = true;
          this = local_34c;
          piVar28 = local_354;
        }
      }
      else if (this->IsCameraPod[(int)piVar25] != false) {
        if (local_34d == '\0') {
          local_368 = this->m_AllyTeams + 1;
          piVar28 = (int *)0x1;
          do {
            if (((0 < *local_368) && (piVar28 != piVar25)) && (*local_368 == piVar29[-0x73])) {
              (*local_398)(piVar28,piVar25);
            }
            piVar28 = (int *)((int)piVar28 + 1);
            local_368 = local_368 + 1;
            this = local_34c;
          } while ((int)piVar28 < 0x10);
        }
        else {
          iVar12 = (*local_3d4)(piVar25);
          iVar13 = (*local_394)(piVar25);
          pcVar18 = local_398;
          if (iVar12 <= iVar13) {
            do {
              (*pcVar18)(iVar12,piVar25);
              iVar12 = iVar12 + 1;
              iVar13 = (*local_394)(piVar25);
              this = local_34c;
            } while (iVar12 <= iVar13);
          }
        }
        this->IsCameraPod[(int)piVar25] = false;
        piVar28 = local_354;
      }
      if (((0 < this->m_RestorePlayers) &&
          (iVar12 = (*local_388)(local_47,"vcamr_vsr",9), iVar12 != 0)) &&
         (iVar12 = (*local_388)(local_47,"vsatview_vsr",0xc), iVar12 != 0)) {
        local_384 = (float (*) [5])(*local_3d0)(piVar25,0);
        memset(PilotODF__TempODF,0,0x40);
        memset(ObjClass__TurretODF,0,0x40);
        (*(code *)local_360)(local_35c,4,ObjClass__TurretODF);
        iVar12 = (*local_3cc)(local_35c);
        if (iVar12 != 0) {
          (*local_378)(PilotODF__TempODF,0x40,iVar12);
          puVar14 = (undefined1 *)(*local_3e4)(PilotODF__TempODF,0x2e);
          if (puVar14 != (undefined1 *)0x0) {
            *puVar14 = 0;
          }
        }
        if (this->m_RestorePlayers == 1) {
          local_380 = this->PlayerSavedName;
          local_368 = (int *)0x0;
          do {
            piVar29 = local_368;
            iVar12 = (*local_38c)(local_384,local_380);
            piVar9 = local_368;
            if (iVar12 == 0) goto LAB_4fc42463;
            local_368 = (int *)((int)piVar29 + 1);
            local_380 = (char (*) [64])(*local_380 + 0x40);
            piVar28 = local_354;
          } while ((int)local_368 < 0x10);
        }
        else if (this->m_RestorePlayers == 2) {
          piVar29 = piVar25;
          piVar9 = piVar25;
          if (local_34d == '\0') {
            if ((int *)piVar28[0x40] == piVar25) goto LAB_4fc42463;
          }
          else {
            iVar12 = (*(code *)local_36c)(piVar25);
            if (piVar28[0x40] == iVar12 + 1) {
LAB_4fc42463:
              local_368 = piVar9;
              piVar28 = local_354;
              if (piVar29 != (int *)0x0) {
                local_390 = (float (*) [5])((int)piVar29 * 0x40);
                (*local_378)(this->PlayerShipODF + (int)piVar29,0x40,&PlayerODF__VariantName);
                (*local_378)(this->SavedPilotODF + (int)piVar29,0x40,PilotODF__TempODF);
                (*local_378)((char *)((int)((float (*) [5])((int)piVar29 * 0x40) + 0x8a1) +
                                     (int)this),0x40,local_384);
                iVar12 = 0;
                pafVar24 = this->m_SavedPlayerLocalAmmo + (int)piVar29;
                local_370 = (MorphTankClass *)((int)piVar29 * 0x140);
                pacVar15 = (char (*) [64])((int)local_370 + (int)this->PlayerShipWeapons);
                local_384 = pafVar24;
                local_380 = pacVar15;
                do {
                  (*(code *)local_360)(local_35c,iVar12 + 5,pacVar15);
                  fVar32 = GetCurLocalAmmo(local_35c,iVar12);
                  iVar13 = local_35c;
                  pacVar15 = (char (*) [64])(*pacVar15 + 0x40);
                  (*pafVar24)[0] = fVar32;
                  iVar12 = iVar12 + 1;
                  pafVar24 = (float (*) [5])(*pafVar24 + 1);
                } while (iVar12 < 5);
                iVar12 = (*local_3b4)(local_35c);
                pSVar31 = local_34c;
                piVar28 = local_368;
                local_34c->m_SavedPlayerHealth[(int)local_368] = iVar12;
                iVar12 = (*local_3a4)(iVar13);
                pSVar31->m_SavedPlayerAmmo[(int)piVar28] = iVar12;
                (*local_3b8)(iVar13,(int)&pSVar31->PlayerMatrix[0].right.x + (int)*local_390);
                pfVar16 = (float *)(*local_3bc)(&Where,iVar13);
                pVVar21 = local_34c->PlayerVelocity + (int)piVar28;
                pVVar21->x = *pfVar16;
                pVVar21->y = pfVar16[1];
                pVVar21->z = pfVar16[2];
                pfVar16 = (float *)(*local_3c0)(&local_3f4,local_35c);
                pcVar18 = local_38c;
                pVVar21 = local_34c->PlayerOmega + (int)piVar28;
                pVVar21->x = *pfVar16;
                pVVar21->y = pfVar16[1];
                pVVar21->z = pfVar16[2];
                iVar12 = (*local_38c)(ObjClass__TurretODF,"CLASS_SCAVENGER");
                if ((iVar12 == 0) ||
                   (iVar12 = (*pcVar18)(ObjClass__TurretODF,"CLASS_SCAVENGERH"), iVar12 == 0)) {
                  iVar12 = (*local_3c4)(local_35c);
                  local_34c->m_SavedPlayerScrap[(int)local_368] = iVar12;
                }
                this = local_34c;
                piVar29 = local_368;
                cVar10 = (*local_3c8)(local_35c);
                piVar25 = local_358;
                this->m_SavedPlayerDeployed[(int)piVar29] = cVar10 != '\0';
                piVar28 = local_358;
                if (local_34d != '\0') {
                  iVar12 = (*(code *)local_36c)(local_358);
                  piVar28 = (int *)(iVar12 + 1);
                }
                this->m_SavedPlayerTeamGroup[(int)piVar29] = (int)piVar28;
                iVar12 = (*local_38c)(ObjClass__TurretODF,"CLASS_PERSON");
                piVar28 = local_354;
                if (iVar12 == 0) {
                  pcVar20 = (char *)((int)local_370 + 0xc494) + (int)this;
                  pafVar24 = this->PlayerPilotLocalAmmo + (int)piVar29;
                  local_390 = pafVar24;
                  local_370 = (MorphTankClass *)pcVar20;
                  if (this->m_GiveWeaponsBack[(int)piVar29] == false) {
                    iVar12 = 0;
                    do {
                      (*(code *)local_360)(local_35c,iVar12 + 5,pcVar20);
                      fVar32 = GetCurLocalAmmo(local_35c,iVar12);
                      pcVar20 = (char *)((int)pcVar20 + 0x40);
                      (*pafVar24)[0] = fVar32;
                      iVar12 = iVar12 + 1;
                      pafVar24 = (float (*) [5])(*pafVar24 + 1);
                      this = local_34c;
                      piVar25 = local_358;
                      piVar28 = local_354;
                    } while (iVar12 < 5);
                  }
                  else {
                    ReplaceWeapons(local_35c,(char (*) [64])pcVar20,*pafVar24,(char *)0x0);
                    this->m_GiveWeaponsBack[(int)piVar29] = false;
                    piVar28 = local_354;
                  }
                }
              }
            }
          }
        }
      }
    }
    local_358 = (int *)((int)piVar25 + 1);
    piVar28 = piVar28 + 1;
  } while ((int)local_358 < 0x10);
  local_354 = piVar28;
  if (0 < this->m_PilotInvunerability) {
    pEVar22 = *(EmptyShipClass **)&(this->EmptyShipList).field_0x4;
    entry_01 = *(EmptyShipClass **)&this->EmptyShipList;
    local_36c = pEVar22;
    local_360 = entry_01;
    if (entry_01 == pEVar22) {
LAB_4fc427c8:
      pcVar18 = *(code **)&(this->EmptyShipList).field_0x4;
    }
    else {
      do {
        bVar11 = ShouldRemoveEmptyShipObject(entry_01);
        if (bVar11) break;
        entry_01 = entry_01 + 1;
      } while (entry_01 != pEVar22);
      local_360 = entry_01;
      if (entry_01 == pEVar22) goto LAB_4fc427c8;
      entry = entry_01 + 1;
      local_374 = entry;
      if (entry != pEVar22) {
        do {
          bVar11 = ShouldRemoveEmptyShipObject(entry);
          if (!bVar11) {
            entry_01->EmptyShipObject = entry->EmptyShipObject;
            entry_01->InvulnerabilityTime = entry->InvulnerabilityTime;
            entry_01->SavedHealth = entry->SavedHealth;
            entry_01 = local_360 + 1;
            pEVar22 = local_36c;
            local_360 = entry_01;
          }
          entry = entry + 1;
          this = local_34c;
        } while (entry != pEVar22);
      }
      if (entry_01 == pEVar22) goto LAB_4fc427c8;
      sVar26 = *(int *)&(this->EmptyShipList).field_0x4 - (int)local_36c;
      memmove(entry_01,local_36c,sVar26);
      pcVar18 = (code *)(sVar26 + (int)entry_01);
      *(code **)&(this->EmptyShipList).field_0x4 = pcVar18;
    }
    pcVar27 = *(code **)&this->EmptyShipList;
    if (pcVar27 != pcVar18) {
      do {
        if (((((*(int *)(pcVar27 + 4) < 1) ||
              (iVar12 = *(int *)(pcVar27 + 4) + -1, *(int *)(pcVar27 + 4) = iVar12, iVar12 < 1)) ||
             (bVar11 = IsAliveAndPilot2(*(int *)pcVar27), bVar11)) ||
            (bVar11 = IsPlayer(*(int *)pcVar27), bVar11)) &&
           (lVar17 = GetMaxHealth(*(int *)pcVar27), lVar17 == 0)) {
          (*local_37c)(*(int *)pcVar27,*(int *)(pcVar27 + 8));
        }
        pcVar27 = pcVar27 + 0xc;
      } while (pcVar27 != *(code **)&(this->EmptyShipList).field_0x4);
    }
  }
  if (this->m_MorphTankAutoDeployType < 1) goto LAB_4fc428f3;
  pMVar1 = *(MorphTankClass **)&(this->MorphTankList).field_0x4;
  entry_02 = *(MorphTankClass **)&this->MorphTankList;
  local_370 = pMVar1;
  while ((entry_02 != pMVar1 && (bVar11 = ShouldRemoveMorphTankObject(entry_02), !bVar11))) {
    entry_02 = entry_02 + 1;
  }
  if (entry_02 == pMVar1) {
LAB_4fc428b9:
    piVar28 = *(int **)&(this->MorphTankList).field_0x4;
  }
  else {
    entry_00 = entry_02 + 1;
    local_374 = (EmptyShipClass *)entry_00;
    for (; entry_00 != pMVar1; entry_00 = entry_00 + 1) {
      bVar11 = ShouldRemoveMorphTankObject(entry_00);
      if (!bVar11) {
        entry_02->MorphTankObject = entry_00->MorphTankObject;
        uVar8 = *(undefined3 *)&entry_00->field_0x5;
        entry_02->CmdSet = entry_00->CmdSet;
        *(undefined3 *)&entry_02->field_0x5 = uVar8;
        entry_02 = entry_02 + 1;
      }
      this = local_34c;
    }
    if (entry_02 == pMVar1) goto LAB_4fc428b9;
    sVar26 = *(int *)&(this->MorphTankList).field_0x4 - (int)local_370;
    memmove(entry_02,local_370,sVar26);
    piVar28 = (int *)(sVar26 + (int)entry_02);
    *(int **)&(this->MorphTankList).field_0x4 = piVar28;
  }
  piVar25 = *(int **)&this->MorphTankList;
  if (piVar25 != piVar28) {
    do {
      SetCommand(*piVar25,this->m_MorphTankAutoDeployType + 0x2e,0,0,(char *)0x0,0);
      *(undefined1 *)(piVar25 + 1) = 1;
      piVar25 = piVar25 + 2;
    } while (piVar25 != *(int **)&(this->MorphTankList).field_0x4);
  }
LAB_4fc428f3:
  pcVar18 = local_364;
  puVar2 = *(undefined4 **)&(this->CommBunkerList).field_0x4;
  puVar30 = *(undefined4 **)&this->CommBunkerList;
  local_370 = (MorphTankClass *)puVar2;
  if (puVar30 != puVar2) {
    do {
      cVar10 = (*pcVar18)(*puVar30);
      if (cVar10 == '\0') break;
      puVar30 = puVar30 + 2;
    } while (puVar30 != puVar2);
    this = local_34c;
    if (puVar30 != puVar2) {
      puVar23 = puVar30 + 2;
      local_374 = (EmptyShipClass *)puVar23;
      for (; local_34c = this, puVar23 != puVar2; puVar23 = puVar23 + 2) {
        cVar10 = (*local_364)(*puVar23);
        if (cVar10 != '\0') {
          *puVar30 = *puVar23;
          puVar30[1] = puVar23[1];
          puVar30 = puVar30 + 2;
        }
        this = local_34c;
      }
      if (puVar30 != puVar2) {
        sVar26 = *(int *)&(this->CommBunkerList).field_0x4 - (int)local_370;
        memmove(puVar30,local_370,sVar26);
        *(size_t *)&(this->CommBunkerList).field_0x4 = sVar26 + (int)puVar30;
      }
    }
  }
  if (((local_34d == '\0') || (this->m_IsMPI != false)) &&
     (ScavengerManagementCode(this), this->m_IsMPI != false)) {
    if (this->SpawnAI == false) {
      pcVar18 = (code *)GetVarItemInt("network.session.ivar2");
      local_37c = pcVar18;
      if (local_34d == '\0') {
        iVar12 = 1;
        pcVar27 = pcVar18;
        if (1 < (int)(pcVar18 + 1)) {
          do {
            local_37c = pcVar27 + -1;
            if (this->m_ThugFlag[iVar12] == false) {
              local_37c = pcVar27;
            }
            iVar12 = iVar12 + 1;
            pcVar27 = local_37c;
          } while (iVar12 < (int)(pcVar18 + 1));
        }
        pEVar22 = (EmptyShipClass *)(this->m_NumSpawnPoints - (int)local_37c);
      }
      else {
        pEVar22 = (EmptyShipClass *)(this->m_NumSpawnPoints + -1);
      }
      local_36c = (EmptyShipClass *)(0xf - (int)pcVar18);
      if ((int)pEVar22 <= 0xf - (int)pcVar18) {
        local_36c = pEVar22;
      }
      if ((int)local_36c < 0) {
        local_36c = (EmptyShipClass *)0x0;
      }
      else if (5 < (int)local_36c) {
        local_36c = (EmptyShipClass *)0x5;
      }
      local_34c = (Strategy02 *)this->m_AIRace;
      local_354 = (int *)0xb;
      do {
        piVar28 = local_354;
        pEVar22 = local_36c;
        memset(PathName,0,0x40);
        if (*(int *)local_34c != 0) {
          if ((int)((int)piVar28 + -0xb) < (int)pEVar22) {
            memset(CPURecy,0,0x40);
            sprintf_s<128>((char (*) [128])local_348,"network.session.svar%d",0xc);
            pcVar20 = GetVarItemStr(local_348);
            if (((pcVar20 == (char *)0x0) ||
                (pcVar20 = DLLUtils::GetCheckedNetworkSvar(2,(NETWORK_LIST_TYPE)pcVar20),
                pcVar20 == (char *)0x0)) || (*pcVar20 == '\0')) {
              pSVar31 = local_34c;
              sprintf_s<64>(&CPURecy,"%cvrecycpu_vsr",(int)*(char *)local_34c);
            }
            else {
              (*local_3a0)(CPURecy,0x40,pcVar20,0x3f);
              pSVar31 = local_34c;
            }
            local_364 = (code *)GetObjectByTeamSlot((int)piVar28,1);
            if (local_364 == (code *)0x0) {
              sprintf_s<64>(&PathName,"Enemy_%d",(int)piVar28);
              local_364 = (code *)BuildObject(CPURecy,(int)piVar28,PathName);
            }
            else {
              iVar12 = IsRecyclerODF((int)local_364);
              if (iVar12 != 0) {
                *(int *)pSVar31 = iVar12;
              }
            }
            if (local_364 == (code *)0x0) {
              *(int *)pSVar31 = 0;
              local_34c = pSVar31;
            }
            else {
              (*misnImport.SetScrap)((int)piVar28,0x28);
              SetCPUAIPlan(this,(int)piVar28,(int)((int)piVar28 + -5));
              memset(AITeamName,0,0x40);
              sprintf_s<64>(&AITeamName,"Computer Team %d",(int)piVar28);
              pcVar20 = GetBZCCLocalizedString("cfg",AITeamName);
              SetTeamNameForStat((int)piVar28,pcVar20);
              GetPosition((int)local_364,&Where);
              memset(PilotODF__TempODF,0,0x40);
              memset(TempODF2,0,0x40);
              memset(&PlayerODF__VariantName,0,0x40);
              CombineStrings(PilotODF__TempODF,CPURecy,".odf",0x40);
              bVar11 = OpenODF2(PilotODF__TempODF);
              if (bVar11) {
                iVar12 = GetODFString(PilotODF__TempODF,"GameObjectClass","classlabel",0x40,TempODF2
                                      ,(char *)0x0);
                if (iVar12 != 0) {
                  CombineStrings(TempODF2,TempODF2,".odf",0x40);
                  OpenODF2(TempODF2);
                }
                iVar12 = GetODFString(PilotODF__TempODF,TempODF2,"GameObjectClass","startingVariant"
                                      ,0x40,&PlayerODF__VariantName,(char *)0x0);
                pcVar18 = local_39c;
                if ((iVar12 == 0) && (iVar12 = (*local_39c)(CPURecy,0x5f), iVar12 != 0)) {
                  iVar12 = iVar12 + 1;
                  iVar13 = (*pcVar18)(iVar12,0x5f);
                  if (iVar13 != 0) {
                    iVar12 = iVar13 + 1;
                  }
                  (*local_378)(&PlayerODF__VariantName,0x40,iVar12);
                }
              }
              pSVar31 = local_34c;
              piVar28 = local_354;
              this->m_CreatingStartingVehicles = true;
              Where_00.y = (float)unaff_EDI;
              Where_00.x = Where.z;
              Where_00.z = unaff_ESI;
              StartingVehicleManager::CreateVehicles
                        ((int)&PlayerODF__VariantName,(char)this->m_StartingVehiclesMask,
                         (char *)Where.x,(int)Where.y,Where_00);
              this->m_CreatingStartingVehicles = false;
              memset(ObjClass__TurretODF,0,0x40);
              sprintf_s<64>(&ObjClass__TurretODF,"%cvturr%s",(int)*(char *)pSVar31,
                            &PlayerODF__VariantName);
              memset(GTowODF,0,0x40);
              sprintf_s<64>(&GTowODF,"%cbspir%s",(int)*(char *)pSVar31,&PlayerODF__VariantName);
              memset(ScoutODF,0,0x40);
              sprintf_s<64>(&ScoutODF,"%cvscout%s",(int)*(char *)pSVar31,&PlayerODF__VariantName);
              memset(SentODF,0,0x40);
              sprintf_s<64>(&SentODF,"%cvsent%s",(int)*(char *)pSVar31,&PlayerODF__VariantName);
              memset(TankODF,0,0x40);
              sprintf_s<64>(&TankODF,"%cvtank%s",(int)*(char *)pSVar31,&PlayerODF__VariantName);
              memset(ScavODF,0,0x40);
              sprintf_s<64>(&ScavODF,"%cvscav%s",(int)*(char *)pSVar31,&PlayerODF__VariantName);
              local_358 = (int *)0x0;
              do {
                if ((int)local_358 < 1) {
                  iVar12 = 0x42700000;
                  VVar3.y = Where.y;
                  VVar3.x = Where.x;
                  VVar3.z = Where.z;
                  pVVar21 = GetPositionNear(&local_3f4,VVar3,30.0,60.0);
                  pSVar31 = local_34c;
                  piVar28 = local_354;
                  BuildStartingVehicle
                            (this_00,(int)local_354,*(int *)local_34c,ScavODF,ScavODF,*pVVar21,
                             iVar12);
                }
                if ((int)local_358 < 2) {
                  iVar12 = 0x42700000;
                  VVar4.y = Where.y;
                  VVar4.x = Where.x;
                  VVar4.z = Where.z;
                  pVVar21 = GetPositionNear(&local_400,VVar4,30.0,60.0);
                  pSVar31 = local_34c;
                  piVar28 = local_354;
                  BuildStartingVehicle
                            (this_01,(int)local_354,*(int *)local_34c,ObjClass__TurretODF,
                             ObjClass__TurretODF,*pVVar21,iVar12);
                }
                iVar12 = this->m_CPUForce;
                if (0 < iVar12) {
                  if ((int)local_358 < 2) {
                    puVar14 = (undefined1 *)((int)local_358 + 1);
                    sprintf_s<64>(&PathName,"%dgtow%d",(int)piVar28,(int)puVar14);
                    BuildStartingVehicle
                              (this_02,(int)piVar28,*(int *)pSVar31,GTowODF,ObjClass__TurretODF,
                               PathName,(int)puVar14);
                    iVar12 = 0x42700000;
                    VVar5.y = Where.y;
                    VVar5.x = Where.x;
                    VVar5.z = Where.z;
                    pVVar21 = GetPositionNear(&local_40c,VVar5,30.0,60.0);
                    pSVar31 = local_34c;
                    piVar28 = local_354;
                    BuildStartingVehicle
                              (this_03,(int)local_354,*(int *)local_34c,SentODF,ScoutODF,*pVVar21,
                               iVar12);
                    iVar12 = this->m_CPUForce;
                  }
                  if (1 < iVar12) {
                    if ((int)local_358 < 1) {
                      iVar12 = 0x42700000;
                      VVar6.y = Where.y;
                      VVar6.x = Where.x;
                      VVar6.z = Where.z;
                      pVVar21 = GetPositionNear(&local_418,VVar6,30.0,60.0);
                      pSVar31 = local_34c;
                      piVar28 = local_354;
                      BuildStartingVehicle
                                (this_04,(int)local_354,*(int *)local_34c,SentODF,ScoutODF,*pVVar21,
                                 iVar12);
                    }
                    puVar14 = (undefined1 *)((int)local_358 + 1);
                    if ((undefined1 *)((int)local_358 - 2U) < (undefined1 *)0x2) {
                      sprintf_s<64>(&PathName,"%dgtow%d",(int)piVar28,(int)puVar14);
                      BuildStartingVehicle
                                (this_05,(int)piVar28,*(int *)pSVar31,GTowODF,ObjClass__TurretODF,
                                 PathName,(int)puVar14);
                    }
                    if ((int)local_358 < 3) {
                      iVar12 = 0x42700000;
                      VVar7.y = Where.y;
                      VVar7.x = Where.x;
                      VVar7.z = Where.z;
                      pVVar21 = GetPositionNear(&local_424,VVar7,30.0,60.0);
                      pSVar31 = local_34c;
                      piVar28 = local_354;
                      BuildStartingVehicle
                                (this_06,(int)local_354,*(int *)local_34c,TankODF,TankODF,*pVVar21,
                                 iVar12);
                    }
                  }
                }
                local_358 = (int *)((int)local_358 + 1);
              } while ((int)local_358 < 5);
              *(undefined1 *)((int)(piVar28 + 0x39e8) + (int)this) = 1;
              local_34c = pSVar31;
            }
          }
          else {
            sprintf_s<1024>(&TempMsgString,
                            "ERROR: CPU %d (Team: %d) spawn skipped: Too many possible Humans (%d) for map Spawns (%d). Reduce Player Limit or number of Commanders."
                            ,(int)((int)piVar28 + -10),(int)piVar28,(int)local_37c,
                            this->m_NumSpawnPoints);
            FormatConsoleMessage(TempMsgString);
            AddToMessagesBox2(TempMsgString,0xffff0000);
          }
        }
        local_34c = (Strategy02 *)((int)local_34c + 4);
        local_354 = (int *)((int)piVar28 + 1);
      } while ((int)((int)piVar28 + -10) < 5);
      this->SpawnAI = true;
    }
    iVar12 = CountPlayers();
    iVar13 = 1;
    do {
      if ((iVar13 < 6) || (iVar19 = this->m_CPUForce, iVar19 == 0)) {
        iVar19 = this->m_HumanForce;
        if (iVar19 != 0) {
          if (iVar19 == 0) {
            iVar19 = this->m_GameTPS * 10;
          }
          else if (iVar19 == 1) {
            iVar19 = this->m_GameTPS << 3;
          }
          else if (iVar19 == 2) {
            iVar19 = this->m_GameTPS * 6;
          }
          else {
            if (iVar19 != 3) goto LAB_4fc4324a;
            iVar19 = this->m_GameTPS << 2;
          }
          goto LAB_4fc4322e;
        }
      }
      else {
        if (iVar19 == 0) {
          iVar19 = this->m_GameTPS * 3;
LAB_4fc43179:
          if ((0 < iVar19) && (this->m_ElapsedGameTime % iVar19 == 0)) {
            (*misnImport.AddScrap)(iVar13,1);
          }
        }
        else {
          if (iVar19 == 1) {
            iVar19 = this->m_GameTPS * 2;
            goto LAB_4fc43179;
          }
          if (iVar19 == 2) {
            iVar19 = this->m_GameTPS;
            goto LAB_4fc43179;
          }
          if (iVar19 == 3) {
            iVar19 = this->m_GameTPS / 5;
            goto LAB_4fc43179;
          }
        }
        if (iVar12 == 1) {
          iVar19 = this->m_GameTPS;
        }
        else {
          if (iVar12 == 2) {
            iVar19 = this->m_GameTPS * 9;
          }
          else if (iVar12 == 3) {
            iVar19 = this->m_GameTPS << 3;
          }
          else if (iVar12 == 4) {
            iVar19 = this->m_GameTPS * 7;
          }
          else {
            if (iVar12 != 5) goto LAB_4fc4324a;
            iVar19 = this->m_GameTPS * 6;
          }
          iVar19 = iVar19 / 10;
        }
LAB_4fc4322e:
        if ((0 < iVar19) && (this->m_ElapsedGameTime % iVar19 == 0)) {
          (*misnImport.AddScrap)(iVar13,1);
        }
      }
LAB_4fc4324a:
      iVar13 = iVar13 + 1;
    } while (iVar13 < 0x10);
  }
  return;
}


// ---------------------------------------------------------------------
// Strategy02::AddPlayer  @ 4fc41f1e  lines 3022-3045

bool __thiscall Strategy02::AddPlayer(Strategy02 *this,ulong id,int Team,bool IsNewPlayer)

{
  int iVar1;
  
  if (this->StopScript == false) {
    LuaMission::AddPlayer(&this->super_LuaMission,id,Team,IsNewPlayer);
  }
  if (this->m_DidInit == false) {
    Init(this);
  }
  else {
    if (!IsNewPlayer) {
      return true;
    }
    if (this->m_IsMPI != false) {
      DoTaunt(1);
    }
  }
  if (IsNewPlayer) {
    iVar1 = SetupPlayer(this,Team);
    SetAsUser(iVar1,Team);
    AddPilotByHandle(iVar1);
  }
  return true;
}


// ---------------------------------------------------------------------
// Strategy02::DeletePlayer  @ 4fc41ef1  lines 3048-3054

void __thiscall Strategy02::DeletePlayer(Strategy02 *this,ulong id)

{
  if (this->StopScript == false) {
    LuaMission::DeletePlayer(&this->super_LuaMission,id);
  }
  if (this->m_IsMPI != false) {
    DoTaunt(2);
  }
  return;
}


// ---------------------------------------------------------------------
// Strategy02::RespawnPilot  @ 4fc41be7  lines 3058-3154

EjectKillRetCodes __thiscall
Strategy02::RespawnPilot(Strategy02 *this,int DeadObjectHandle,int Team)

{
  char Race;
  Vector *pVVar1;
  char *pcVar2;
  int iVar3;
  long lVar4;
  double dVar5;
  float fVar6;
  float fVar7;
  bool IsRespawning;
  int iVar8;
  float local_34;
  Vector local_2c;
  Vector local_20;
  Vector local_14;
  
  local_2c.y = 0.0;
  local_2c.z = 0.0;
  if (Team - 1U < 0xf) {
    local_2c.x = this->m_TeamPos[Team * 3];
    local_2c.y = this->m_TeamPos[Team * 3 + 1];
    local_2c.z = this->m_TeamPos[Team * 3 + 2];
    this->m_SpawnedAtTime[Team] = this->m_ElapsedGameTime;
  }
  else {
    pVVar1 = GetSafestSpawnpoint(&local_14);
    local_2c.x = pVVar1->x;
    local_2c.y = pVVar1->y;
    local_2c.z = pVVar1->z;
  }
  GetPosition2(DeadObjectHandle,&local_20);
  local_34 = 200.0;
  if ((0.01 < ABS(local_20.x)) && (0.01 < ABS(local_20.z))) {
    dVar5 = (double)((local_20.z - local_2c.z) * (local_20.z - local_2c.z) +
                    (local_20.x - local_2c.x) * (local_20.x - local_2c.x));
    libm_sse2_sqrt_precise();
    if (100.0 <= (float)dVar5) {
      dVar5 = (double)(float)dVar5;
      libm_sse2_sqrt_precise();
      fVar7 = (float)dVar5 * 1.25 + 30.0;
      iVar3 = DLLUtils::CountAlliedPlayers(Team);
      local_34 = 40.0;
      fVar6 = (float)iVar3 * 15.0 + 70.0;
      if ((40.0 <= fVar7) && (local_34 = fVar6, fVar7 <= fVar6)) {
        local_34 = fVar7;
      }
    }
    else {
      local_34 = 35.0;
    }
  }
  if (this->m_RespawnAtLowAltitude != false) {
    local_34 = 2.0;
  }
  fVar7 = GetRandomFloat(1.0);
  local_2c.x = (fVar7 - 0.5) * 64.0 + local_2c.x;
  fVar7 = GetRandomFloat(1.0);
  local_2c.z = (fVar7 - 0.5) * 64.0 + local_2c.z;
  fVar7 = TerrainFindFloor(local_2c.x,local_2c.z);
  if (local_2c.y < fVar7 + 2.5) {
    local_2c.y = fVar7 + 2.5;
  }
  local_2c.y = local_34 + local_2c.y;
  fVar7 = GetRandomFloat(1.0);
  pVVar1 = &local_2c;
  IsRespawning = true;
  local_2c.y = fVar7 * 8.0 + local_2c.y;
  iVar3 = Team;
  iVar8 = Team;
  Race = GetRaceOfTeam(Team);
  pcVar2 = GetInitialPlayerPilotODF(this,Race,iVar3,IsRespawning);
  iVar3 = BuildObject(pcVar2,iVar8,pVVar1);
  if (0 < this->m_PilotInvunerability) {
    this->m_PilotInvTime[Team] = this->m_PilotInvunerability;
    lVar4 = GetMaxHealth(iVar3);
    this->m_SavedPilotInvHealth[Team] = lVar4;
    this->m_PilotInvUser[Team] = iVar3;
    SetMaxHealth(iVar3,0);
  }
  SetAsUser(iVar3,Team);
  AddPilotByHandle(iVar3);
  SetRandomHeadingAngle(iVar3);
  if (Team == 0) {
    MakeInert(iVar3);
  }
  return DLLHandled;
}


// ---------------------------------------------------------------------
// Strategy02::DeadObject  @ 4fc417e7  lines 3158-3303

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

EjectKillRetCodes __thiscall
Strategy02::DeadObject
          (Strategy02 *this,int DeadObjectHandle,int KillersHandle,bool isDeadPerson,bool isDeadAI)

{
  bool bVar1;
  bool bVar2;
  int Team;
  int iVar3;
  TEAMRELATIONSHIP TVar4;
  char *fmtarg2;
  char *fmtarg1;
  EjectKillRetCodes EVar5;
  float10 fVar6;
  char ObjClass [64];
  uint local_8;
  
  local_8 = __security_cookie ^ (uint)&stack0xfffffffc;
  Team = GetTeamNum(DeadObjectHandle);
  GetObjInfo(DeadObjectHandle,Get_GOClass,ObjClass);
  iVar3 = _stricmp(ObjClass,"CLASS_TORPEDO");
  if (Team == 0) {
    return DoEjectPilot;
  }
  bVar1 = IsPowerup(DeadObjectHandle);
  if (bVar1) {
    return DoEjectPilot;
  }
  if (iVar3 == 0) {
    return DoEjectPilot;
  }
  bVar1 = IsPlayer(DeadObjectHandle);
  bVar2 = IsPlayer(KillersHandle);
  TVar4 = GetTeamRelationship(DeadObjectHandle,KillersHandle);
  iVar3 = GetActualScrapCost(DeadObjectHandle);
  if (bVar1) {
    if (this->m_GameType != 4) {
      fVar6 = floor((double)((float)iVar3 / 20.0));
      AddScore(DeadObjectHandle,-(int)fVar6);
    }
    if (isDeadPerson) {
      AddDeaths(DeadObjectHandle,1);
    }
  }
  else {
    if (this->m_KillForAIKill != 0) {
      AddDeaths(DeadObjectHandle,1);
    }
    if ((this->m_PointsForAIKill != 0) && (this->m_GameType != 4)) {
      fVar6 = floor((double)((float)iVar3 / 20.0));
      AddScore(DeadObjectHandle,-(int)fVar6);
    }
  }
  if (bVar2) {
    if ((TVar4 == TEAMRELATIONSHIP_SAMETEAM) || (TVar4 == TEAMRELATIONSHIP_ALLIEDTEAM)) {
      if (DeadObjectHandle == KillersHandle) goto LAB_4fc41b69;
      AddKills(KillersHandle,-1);
      if (this->m_GameType != 4) {
        fVar6 = floor((double)((float)iVar3 / 10.0));
        goto LAB_4fc41ade;
      }
    }
    else {
      AddKills(KillersHandle,1);
      if (this->m_GameType != 4) {
        fVar6 = floor((double)((float)iVar3 / 10.0));
LAB_4fc419c1:
        iVar3 = (int)fVar6;
LAB_4fc41ae8:
        AddScore(KillersHandle,iVar3);
      }
    }
  }
  else if ((TVar4 == TEAMRELATIONSHIP_SAMETEAM) || (TVar4 == TEAMRELATIONSHIP_ALLIEDTEAM)) {
    if (this->m_KillForAIKill != 0) {
      AddKills(KillersHandle,-1);
    }
    if ((this->m_PointsForAIKill != 0) && (this->m_GameType != 4)) {
      fVar6 = floor((double)((float)iVar3 / 10.0));
LAB_4fc41ade:
      iVar3 = -(int)fVar6;
      goto LAB_4fc41ae8;
    }
  }
  else {
    if (this->m_KillForAIKill != 0) {
      AddKills(KillersHandle,1);
    }
    if ((this->m_PointsForAIKill != 0) && (this->m_GameType != 4)) {
      fVar6 = floor((double)((float)iVar3 / 10.0));
      goto LAB_4fc419c1;
    }
  }
  if ((((DeadObjectHandle != KillersHandle) && (!isDeadAI)) && (Team - 1U < 0xf)) &&
     ((0 < this->m_SpawnedAtTime[Team] &&
      (this->m_ElapsedGameTime - this->m_SpawnedAtTime[Team] < this->m_GameTPS * 0xf)))) {
    fmtarg2 = GetPlayerName(DeadObjectHandle);
    fmtarg1 = GetPlayerName(KillersHandle);
    sprintf_s<1024>(&TempMsgString,"Spawn kill by %s on %s\n",fmtarg1,fmtarg2);
    AddToMessagesBox(TempMsgString);
    AddScore(KillersHandle,-500);
  }
LAB_4fc41b69:
  if ((this->m_KillLimit != 0) && (iVar3 = GetKills(KillersHandle), this->m_KillLimit <= iVar3)) {
    NoteGameoverByKillLimit(KillersHandle);
    DoGameover(10.0);
  }
  if (isDeadAI) {
    if (isDeadPerson) {
      return DLLHandled;
    }
  }
  else {
    if ((this->m_IsMPI != false) && (Team - 1U < 10)) {
      DoTaunt(3);
    }
    if (isDeadPerson) {
      EVar5 = RespawnPilot(this,DeadObjectHandle,Team);
      return EVar5;
    }
  }
  return DoEjectPilot;
}


// ---------------------------------------------------------------------
// Strategy02::PlayerEjected  @ 4fc41798  lines 3306-3323

EjectKillRetCodes __thiscall Strategy02::PlayerEjected(Strategy02 *this,int DeadObjectHandle)

{
  bool bVar1;
  int iVar2;
  EjectKillRetCodes EVar3;
  
  if (this->StopScript == false) {
    LuaMission::PlayerEjected(&this->super_LuaMission,DeadObjectHandle);
  }
  iVar2 = GetTeamNum(DeadObjectHandle);
  if (iVar2 == 0) {
    EVar3 = DLLHandled;
  }
  else {
    bVar1 = IsPlayer(DeadObjectHandle);
    EVar3 = DeadObject(this,DeadObjectHandle,DeadObjectHandle,false,(bool)('\x01' - bVar1));
  }
  return EVar3;
}


// ---------------------------------------------------------------------
// Strategy02::ObjectKilled  @ 4fc41736  lines 3326-3345

EjectKillRetCodes __thiscall
Strategy02::ObjectKilled(Strategy02 *this,int DeadObjectHandle,int KillersHandle)

{
  bool bVar1;
  bool isDeadPerson;
  int iVar2;
  EjectKillRetCodes EVar3;
  
  if (this->StopScript == false) {
    LuaMission::ObjectKilled(&this->super_LuaMission,DeadObjectHandle,KillersHandle);
  }
  bVar1 = IsPlayer(DeadObjectHandle);
  isDeadPerson = IsPerson(DeadObjectHandle);
  iVar2 = GetCurWorld();
  if (iVar2 == 0) {
    EVar3 = DeadObject(this,DeadObjectHandle,KillersHandle,isDeadPerson,(bool)('\x01' - bVar1));
  }
  else {
    EVar3 = DoEjectPilot;
  }
  return EVar3;
}


// ---------------------------------------------------------------------
// Strategy02::ObjectSniped  @ 4fc416e2  lines 3349-3368

EjectKillRetCodes __thiscall
Strategy02::ObjectSniped(Strategy02 *this,int DeadObjectHandle,int KillersHandle)

{
  bool bVar1;
  int iVar2;
  EjectKillRetCodes EVar3;
  
  if (this->StopScript == false) {
    LuaMission::ObjectSniped(&this->super_LuaMission,DeadObjectHandle,KillersHandle);
  }
  bVar1 = IsPlayer(DeadObjectHandle);
  iVar2 = GetCurWorld();
  if (iVar2 == 0) {
    EVar3 = DeadObject(this,DeadObjectHandle,KillersHandle,true,(bool)('\x01' - bVar1));
  }
  else {
    EVar3 = DLLHandled;
  }
  return EVar3;
}


// ---------------------------------------------------------------------
// Strategy02::PreGetIn  @ 4fc41614  lines 3424-3455

PreGetInReturnCodes __thiscall
Strategy02::PreGetIn(Strategy02 *this,int curWorld,int pilotHandle,int emptyCraftHandle)

{
  bool bVar1;
  PreGetInReturnCodes PVar2;
  TEAMRELATIONSHIP TVar3;
  int iVar4;
  
  if (curWorld == 0) {
    PVar2 = LuaMission::PreGetIn(&this->super_LuaMission,0,pilotHandle,emptyCraftHandle);
    TVar3 = GetTeamRelationship(pilotHandle,emptyCraftHandle);
    if (((TVar3 == TEAMRELATIONSHIP_ALLIEDTEAM) && (bVar1 = IsPlayer(pilotHandle), !bVar1)) &&
       (this->m_SetThugPilotFlag == false)) {
      iVar4 = GetTeamNum(emptyCraftHandle);
      SetTeamNum(pilotHandle,iVar4);
    }
    iVar4 = GetTeamNum(pilotHandle);
    if (this->m_PilotInvUser[iVar4] == pilotHandle) {
      iVar4 = GetTeamNum(pilotHandle);
      SetMaxHealth(pilotHandle,this->m_SavedPilotInvHealth[iVar4]);
      iVar4 = GetTeamNum(pilotHandle);
      this->m_PilotInvTime[iVar4] = 0;
    }
    if (((PVar2 == PREGETIN_ALLOW) && (this->m_IsMPI != false)) &&
       (iVar4 = GetTeamNum(emptyCraftHandle), 10 < iVar4)) {
      DispatchHelper::AddToDispatch
                ((this->super_LuaMission).super_BZ1Helper.m_DispatchHelper,emptyCraftHandle,15.0,
                 false,0,false,false,false,false);
    }
  }
  else {
    PVar2 = PREGETIN_ALLOW;
  }
  return PVar2;
}


// ---------------------------------------------------------------------
// BuildMission  @ 4fc47036  lines 3459-3461

/* WARNING: Function: _EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: _EH_epilog3 replaced with injection: EH_epilog3 */

DLLBase * __cdecl BuildMission(void)

{
  Strategy02 *pSVar1;
  
  pSVar1 = operator_new(0xeca4);
  pSVar1 = Strategy02::Strategy02(pSVar1);
  return (DLLBase *)pSVar1;
}


// ---------------------------------------------------------------------
// Strategy02::ScavengerManagementCode  @ 4fc413ca  lines 3465-3604

void __thiscall Strategy02::ScavengerManagementCode(Strategy02 *this)

{
  ThugScavengerClass *pTVar1;
  ThugPilotClass *pTVar2;
  ThugScavengerClass *entry;
  ThugPilotClass *entry_00;
  bool bVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  size_t sVar9;
  int *piVar10;
  ThugScavengerClass *entry_01;
  ThugPilotClass *entry_02;
  
  pTVar1 = *(ThugScavengerClass **)&(this->ThugScavengerList).field_0x4;
  entry_01 = *(ThugScavengerClass **)&this->ThugScavengerList;
  while ((entry_01 != pTVar1 && (bVar3 = ShouldRemoveThugScavengerObject(entry_01), !bVar3))) {
    entry_01 = entry_01 + 1;
  }
  entry = entry_01;
  if (entry_01 == pTVar1) {
LAB_4fc41452:
    piVar6 = *(int **)&(this->ThugScavengerList).field_0x4;
  }
  else {
    while (entry = entry + 1, entry != pTVar1) {
      bVar3 = ShouldRemoveThugScavengerObject(entry);
      if (!bVar3) {
        entry_01->ThugScavengerObject = entry->ThugScavengerObject;
        entry_01->ScavengerTeam = entry->ScavengerTeam;
        entry_01 = entry_01 + 1;
      }
    }
    if (entry_01 == pTVar1) goto LAB_4fc41452;
    sVar9 = *(int *)&(this->ThugScavengerList).field_0x4 - (int)pTVar1;
    memmove(entry_01,pTVar1,sVar9);
    piVar6 = (int *)(sVar9 + (int)entry_01);
    *(int **)&(this->ThugScavengerList).field_0x4 = piVar6;
  }
  piVar10 = *(int **)&this->ThugScavengerList;
  if (piVar10 != piVar6) {
    do {
      iVar4 = GetTeamNum(*piVar10);
      if ((this->m_ThugFlag[iVar4] == false) && (piVar10[1] != iVar4)) {
        piVar10[1] = iVar4;
      }
      else {
        bVar3 = IsTeamplayOn();
        if (!bVar3) {
          iVar7 = GetScavengerCurScrap(*piVar10);
          if (0 < iVar7) {
            iVar8 = (*misnImport.GetScrap)(piVar10[1]);
            iVar5 = (*misnImport.GetMaxScrap)(piVar10[1]);
            if (iVar5 < iVar8 + iVar7) {
              (*misnImport.AddScrap)(piVar10[1],iVar5 - iVar8);
              iVar7 = iVar7 - (iVar5 - iVar8);
            }
            else {
              (*misnImport.AddScrap)(piVar10[1],iVar7);
              iVar7 = 0;
            }
            SetScavengerCurScrap(*piVar10,iVar7);
          }
          if ((iVar4 != piVar10[1]) && (bVar3 = IsDeployed(*piVar10), bVar3)) {
            SetTeamNum(*piVar10,piVar10[1]);
          }
        }
      }
      piVar10 = piVar10 + 2;
    } while (piVar10 != *(int **)&(this->ThugScavengerList).field_0x4);
  }
  pTVar2 = *(ThugPilotClass **)&(this->ThugPilotList).field_0x4;
  entry_02 = *(ThugPilotClass **)&this->ThugPilotList;
  while ((entry_02 != pTVar2 && (bVar3 = ShouldRemoveThugPilotObject(entry_02), !bVar3))) {
    entry_02 = entry_02 + 1;
  }
  entry_00 = entry_02;
  if (entry_02 != pTVar2) {
    while (entry_00 = entry_00 + 1, entry_00 != pTVar2) {
      bVar3 = ShouldRemoveThugPilotObject(entry_00);
      if (!bVar3) {
        entry_02->ThugPilotObject = entry_00->ThugPilotObject;
        entry_02->SwitchTickTimer = entry_00->SwitchTickTimer;
        entry_02 = entry_02 + 1;
      }
    }
    if (entry_02 != pTVar2) {
      sVar9 = *(int *)&(this->ThugPilotList).field_0x4 - (int)pTVar2;
      memmove(entry_02,pTVar2,sVar9);
      piVar6 = (int *)(sVar9 + (int)entry_02);
      *(int **)&(this->ThugPilotList).field_0x4 = piVar6;
      goto LAB_4fc415a0;
    }
  }
  piVar6 = *(int **)&(this->ThugPilotList).field_0x4;
LAB_4fc415a0:
  piVar10 = *(int **)&this->ThugPilotList;
  if (piVar10 != piVar6) {
    do {
      iVar4 = GetTeamNum(*piVar10);
      if ((this->m_ThugFlag[iVar4] != false) && (piVar10[1] < 1)) {
        piVar6 = this->m_AllyTeams;
        iVar7 = 1;
        iVar8 = 1;
        do {
          piVar6 = piVar6 + 1;
          if ((this->m_AllyTeams[iVar4] == *piVar6) && (this->m_ThugFlag[iVar8] == false)) {
            iVar7 = iVar8;
          }
          iVar8 = iVar8 + 1;
        } while (iVar8 < 0x10);
        if (iVar4 != iVar7) {
          SetTeamNum(*piVar10,iVar7);
        }
      }
      piVar10[1] = piVar10[1] + -1;
      piVar10 = piVar10 + 2;
    } while (piVar10 != *(int **)&(this->ThugPilotList).field_0x4);
  }
  return;
}


// ---------------------------------------------------------------------
// Strategy02::ExecuteST_Capture  @ 4fc40af6  lines 3607-3859

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall Strategy02::ExecuteST_Capture(Strategy02 *this)

{
  bool *pbVar1;
  bool *pbVar2;
  DLLBase *pDVar3;
  bool bVar4;
  int iVar5;
  undefined1 *puVar6;
  int iVar7;
  long extraout_EAX;
  long extraout_EAX_00;
  char *fmtarg1;
  undefined1 *puVar8;
  int *piVar9;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 extraout_ST0_01;
  char *pcVar10;
  int iVar11;
  long lVar12;
  undefined1 auStack_8c [3];
  char local_89;
  int *local_88;
  DLLBase *local_84;
  bool *local_80;
  bool *local_7c;
  int *local_78;
  int *local_74;
  double local_70;
  int *local_64;
  bool *local_60;
  undefined1 *local_5c;
  int local_58;
  int TempP;
  char TempP2 [68];
  uint local_c;
  
  local_c = __security_cookie ^ (uint)auStack_8c;
  local_89 = '\0';
  local_5c = (undefined1 *)0x1;
  do {
    puVar8 = local_5c;
    iVar5 = GetUserTarget((int)local_5c);
    this->UserTarget[(int)puVar8] = iVar5;
    if (this->m_NumCaptureGoals < 1) {
      if (this->m_GameOver == false) {
        pcVar10 = "-- No Capture Goals! Game will be over very soon!";
LAB_4fc4138b:
        AddToMessagesBox2(pcVar10,0xffffff00);
        DoGameover(10.0);
        goto LAB_4fc4139f;
      }
    }
    else {
      local_74 = this->m_CaptureGoalTeam;
      iVar5 = 0;
      local_60 = this->m_CaptureGoalObjectify;
      local_78 = this->m_GoalBeingCaptured;
      local_88 = this->m_CaptureGoals;
      local_64 = this->m_CaptureGoalTime;
      local_70 = (double)((ulonglong)local_70 & 0xffffffff00000000);
      do {
        GetObjInfo(*local_88,Get_ODF,TempP2);
        bVar4 = IsAround(*local_88);
        if (bVar4) {
          SetObjectiveOn(*local_88);
        }
        else {
          iVar7 = this->m_NumCaptureGoals;
          if (iVar5 < iVar7 + -1) {
            local_7c = local_60;
            local_84 = (DLLBase *)(-0xe7fa - (int)this);
            piVar9 = local_88;
            local_80 = this->m_CaptureGoalIsSwitching[(int)puVar8] + iVar5;
            do {
              pbVar1 = local_7c + 1;
              *piVar9 = piVar9[1];
              piVar9[-0x1af] = piVar9[-0x1ae];
              piVar9[-0x19f] = piVar9[-0x19e];
              piVar9[-399] = piVar9[-0x18e];
              *local_7c = *pbVar1;
              pbVar2 = local_80 + 1;
              *local_80 = *pbVar2;
              local_7c[0x110] = local_7c[0x111];
              iVar7 = this->m_NumCaptureGoals;
              piVar9 = piVar9 + 1;
              local_80 = pbVar2;
              local_7c = pbVar1;
            } while ((int)(pbVar1 + (int)local_84) < iVar7 + -1);
            puVar8 = local_5c;
            iVar5 = local_70._0_4_;
          }
          local_64 = local_64 + -1;
          iVar5 = iVar5 + -1;
          local_78 = local_78 + -1;
          local_74 = local_74 + -1;
          local_88 = local_88 + -1;
          local_60 = local_60 + -1;
          this->m_NumCaptureGoals = iVar7 + -1;
        }
        bVar4 = IsAround(*local_88);
        if (bVar4) {
          local_58 = GetPlayerHandle((int)puVar8);
          local_80 = (bool *)(this->UserTarget + 1);
          local_7c = (bool *)0x1;
          do {
            TempP = GetPlayerHandle((int)local_7c);
            if ((((local_7c != (bool *)puVar8) &&
                 (bVar4 = IsTeamAllied((int)puVar8,(int)local_7c), !bVar4)) &&
                (this->UserTarget[(int)puVar8] == *local_88)) && (*(int *)local_80 == *local_88)) {
              (*misnImport.GetDistanceObject)(local_88,&local_58);
              local_84 = (DLLBase *)(float)extraout_ST0;
              if ((float)local_84 < 100.0) {
                (*misnImport.GetDistanceObject)(local_88,&TempP);
                local_84 = (DLLBase *)(float)extraout_ST0_00;
                if ((float)local_84 < 100.0) {
                  SetTeamNum(*local_88,*local_74);
                  if (this->m_DualCapture[iVar5] == false) {
                    this->m_DualCapture[iVar5] = true;
                  }
                  goto LAB_4fc40d51;
                }
              }
            }
            local_80 = local_80 + 4;
            local_7c = local_7c + 1;
          } while ((int)local_7c < 0x10);
          this->m_DualCapture[iVar5] = false;
LAB_4fc40d51:
          if ((((this->UserTarget[(int)puVar8] == *local_88) && ((undefined1 *)*local_74 != puVar8))
              && ((*local_74 == 0 || (bVar4 = IsTeamAllied(*local_74,(int)puVar8), !bVar4)))) &&
             ((*local_78 == 0 || ((undefined1 *)*local_78 == puVar8)))) {
            (*misnImport.GetDistanceObject)(local_88,&local_58);
            local_84 = (DLLBase *)(float)extraout_ST0_01;
            if ((float)local_84 < 100.0) {
              if (this->m_GoalBeingCaptured[iVar5] == 0) {
                iVar7 = GetPlayerHandle((int)puVar8);
                pcVar10 = GetPlayerName(iVar7);
                sprintf_s<1024>(&TempMsgString,"-- A Goal is being Captured by %s!",pcVar10);
                AddToMessagesBox2(TempMsgString,0xffffff00);
              }
              local_84 = &(this->super_LuaMission).super_BZ1Helper.super_DLLBase + (int)puVar8 * 4;
              *(undefined1 *)((int)(local_84 + 0x3a02) + 2 + iVar5) = 1;
              if (this->m_DualCapture[iVar5] == false) {
                this->m_CaptureGoalTime[iVar5] = this->m_CaptureGoalTime[iVar5] + 1;
              }
              this->m_GoalBeingCaptured[iVar5] = (int)puVar8;
              this->m_TeamIsCapturing[(int)puVar8] = true;
              local_80 = (bool *)((this->m_CaptureTime - this->m_CaptureGoalTime[iVar5]) /
                                 this->m_GameTPS);
              puVar6 = (undefined1 *)GetLocalPlayerTeamNumber();
              if (puVar6 == puVar8) {
                local_70 = (double)((int)(local_80 + ((int)local_80 >> 0x1f & 3)) >> 2);
                floor(local_70);
                _ftol2_sse();
                local_70 = (double)((int)local_80 / 2);
                lVar12 = extraout_EAX;
                floor(local_70);
                _ftol2_sse();
                StartCockpitTimer((long)local_80,extraout_EAX_00,lVar12);
              }
              if (this->m_CaptureGoalTime[iVar5] % this->m_GameTPS == 0) {
                if (this->m_CaptureGoalObjectify[iVar5] == false) {
                  SetTeamNum(this->m_CaptureGoals[iVar5],(int)puVar8);
                  SetObjectiveOn(this->m_CaptureGoals[iVar5]);
                  this->m_CaptureGoalObjectify[iVar5] = true;
                }
                else {
                  SetTeamNum(this->m_CaptureGoals[iVar5],this->m_CaptureGoalTeam[iVar5]);
                  SetObjectiveOff(this->m_CaptureGoals[iVar5]);
                  this->m_CaptureGoalObjectify[iVar5] = false;
                }
              }
              if (this->m_CaptureGoalTime[iVar5] == this->m_CaptureTime) {
                iVar7 = 0;
                if (this->m_CaptureGoalTeam[iVar5] != 0) {
                  iVar11 = -1;
                  iVar7 = GetPlayerHandle(this->m_CaptureGoalTeam[iVar5]);
                  AddScore(iVar7,iVar11);
                  iVar7 = this->m_CaptureGoalTeam[iVar5];
                }
                local_80 = (bool *)GetPlayerHandle(iVar7);
                this->m_CaptureGoalTeam[iVar5] = (int)puVar8;
                SetTeamNum(this->m_CaptureGoals[iVar5],(int)puVar8);
                iVar7 = 0;
                local_70 = (double)((ulonglong)local_70 & 0xffffffff00000000);
                do {
                  iVar7 = GetTap(this->m_CaptureGoals[iVar5],iVar7);
                  if (iVar7 != 0) {
                    SetTeamNum(iVar7,(int)puVar8);
                  }
                  iVar7 = local_70._0_4_ + 1;
                  local_70 = (double)CONCAT44(local_70._4_4_,iVar7);
                } while (iVar7 < 8);
                iVar11 = 1;
                iVar7 = GetPlayerHandle((int)puVar8);
                AddScore(iVar7,iVar11);
                this->m_GoalBeingCaptured[iVar5] = 0;
                puVar6 = (undefined1 *)GetLocalPlayerTeamNumber();
                if (puVar6 == puVar8) {
                  StopCockpitTimer();
                  HideCockpitTimer();
                }
                SetObjectiveOff(this->m_CaptureGoals[iVar5]);
                this->m_CaptureGoalTime[iVar5] = 0;
                *(undefined1 *)((int)(local_84 + 0x3a02) + 2 + iVar5) = 0;
                this->m_TeamIsCapturing[(int)puVar8] = false;
                if (local_80 == (bool *)0x0) {
                  iVar5 = GetPlayerHandle((int)puVar8);
                  pcVar10 = GetPlayerName(iVar5);
                  sprintf_s<1024>(&TempMsgString,"-- %s Captured a Goal!",pcVar10);
                }
                else {
                  pcVar10 = GetPlayerName((int)local_80);
                  iVar5 = GetPlayerHandle((int)puVar8);
                  fmtarg1 = GetPlayerName(iVar5);
                  sprintf_s<1024>(&TempMsgString,"-- %s Captured a Goal from %s!",fmtarg1,pcVar10);
                }
                AddToMessagesBox2(TempMsgString,0xffffff00);
              }
              break;
            }
          }
          local_84 = &(this->super_LuaMission).super_BZ1Helper.super_DLLBase + (int)puVar8 * 4;
          if (*(char *)((int)(local_84 + 0x3a02) + 2 + iVar5) != '\0') {
            *local_78 = 0;
            *local_64 = 0;
            SetTeamNum(*local_88,*local_74);
            puVar6 = (undefined1 *)GetLocalPlayerTeamNumber();
            if (puVar6 == puVar8) {
              StopCockpitTimer();
              HideCockpitTimer();
            }
            if (this->UserTarget[(int)puVar8] == *local_88) {
              iVar11 = 0;
              iVar7 = GetPlayerHandle((int)puVar8);
              SetTarget(iVar7,iVar11);
            }
            *(undefined1 *)((int)(local_84 + 0x3a02) + 2 + iVar5) = 0;
            this->m_TeamIsCapturing[(int)puVar8] = false;
          }
        }
        iVar5 = iVar5 + 1;
        local_64 = local_64 + 1;
        local_88 = local_88 + 1;
        local_78 = local_78 + 1;
        local_74 = local_74 + 1;
        local_60 = local_60 + 1;
        local_70 = (double)CONCAT44(local_70._4_4_,iVar5);
      } while (iVar5 < this->m_NumCaptureGoals);
      if (this->m_KillLimit == 0) {
        local_70 = (double)((ulonglong)local_70 & 0xffffffff00000000);
        local_89 = '\x01';
        if (0 < this->m_NumCaptureGoals) {
          piVar9 = this->m_CaptureGoalTeam;
          do {
            if ((((piVar9[0x10] != 0) || (*piVar9 == 0)) || ((undefined1 *)*piVar9 != puVar8)) ||
               (bVar4 = IsTeamAllied((int)puVar8,*piVar9), !bVar4)) {
              local_89 = '\0';
              goto LAB_4fc411cc;
            }
            piVar9 = piVar9 + 1;
            iVar5 = local_70._0_4_ + 1;
            local_70 = (double)CONCAT44(local_70._4_4_,iVar5);
          } while (iVar5 < this->m_NumCaptureGoals);
        }
      }
      else {
        iVar5 = GetPlayerHandle((int)puVar8);
        iVar5 = GetScore(iVar5);
        if (this->m_KillLimit <= iVar5) {
          local_89 = '\x01';
        }
LAB_4fc411cc:
        if (local_89 == '\0') goto LAB_4fc413a7;
      }
      if (this->m_GameOver == false) {
        bVar4 = IsTeamplayOn();
        if (!bVar4) {
          iVar5 = this->m_KillLimit;
          if (this->m_HasAllies[(int)puVar8] == false) {
            if (iVar5 == 0) {
              pcVar10 = GetPlayerName(this->m_RecyclerHandles[(int)puVar8]);
              sprintf_s<1024>(&TempMsgString,"-- %s has won! Captured All Goals!",pcVar10);
            }
            else {
              pcVar10 = GetPlayerName(this->m_RecyclerHandles[(int)puVar8]);
              sprintf_s<1024>(&TempMsgString,"-- %s has won! Captured %d Goals!",pcVar10,iVar5);
            }
            iVar7 = 100;
            iVar5 = GetPlayerHandle((int)puVar8);
            AddScore(iVar5,iVar7);
            iVar5 = GetPlayerHandle((int)puVar8);
            NoteGameoverByScore(iVar5);
          }
          else {
            if (iVar5 == 0) {
              sprintf_s<1024>(&TempMsgString,"-- Team %d has won! Captured All Goals!",
                              this->m_AllyTeams[(int)puVar8]);
            }
            else {
              sprintf_s<1024>(&TempMsgString,"-- Team %d has won! Captured %d Goals!",
                              this->m_AllyTeams[(int)puVar8],iVar5);
            }
            iVar7 = 100;
            iVar5 = GetPlayerHandle((int)puVar8);
            AddScore(iVar5,iVar7);
            NoteGameoverWithCustomMessage(TempMsgString);
          }
          pcVar10 = TempMsgString;
          goto LAB_4fc4138b;
        }
        local_84 = (DLLBase *)WhichTeamGroup((int)puVar8);
        if (this->m_KillLimit == 0) {
          sprintf_s<1024>(&TempMsgString,"-- Team %d has won! Captured all Goals!",
                          (int)&local_84->field_0x1);
        }
        else {
          sprintf_s<1024>(&TempMsgString,"-- Team %d has won! Captured %d Goals!",
                          (int)&local_84->field_0x1,this->m_KillLimit);
        }
        iVar7 = 100;
        iVar5 = GetPlayerHandle((int)puVar8);
        AddScore(iVar5,iVar7);
        NoteGameoverWithCustomMessage(TempMsgString);
        pDVar3 = local_84;
        iVar5 = 0;
        do {
          puVar8 = (undefined1 *)WhichTeamGroup(iVar5);
          if ((DLLBase *)puVar8 == pDVar3) {
            iVar11 = 100;
            iVar7 = GetPlayerHandle(iVar5);
            AddScore(iVar7,iVar11);
          }
          iVar5 = iVar5 + 1;
        } while (iVar5 < 0x10);
        AddToMessagesBox2(TempMsgString,0xffffff00);
        DoGameover(10.0);
        puVar8 = local_5c;
LAB_4fc4139f:
        this->m_GameOver = true;
      }
    }
LAB_4fc413a7:
    local_5c = puVar8 + 1;
    if (0xf < (int)local_5c) {
      return;
    }
  } while( true );
}


