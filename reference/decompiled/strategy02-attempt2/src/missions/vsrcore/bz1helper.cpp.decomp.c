// Reconstructed by Ghidra from Strategy02.dll + Strategy02.pdb
// Original source file: /e:/github/vsr_dll_source/missions/vsrcore/bz1helper.cpp
// Functions are ordered by original source line. This is decompiler
// output, not the author's source: names/types come from the PDB,
// local variable names and control flow are reconstructed.

// ---------------------------------------------------------------------
// `dynamic_initializer_for_'TempAlignBuffer''  @ 4fc01245  lines 100-100

void __cdecl _dynamic_initializer_for__TempAlignBuffer__(void)

{
  atexit(_dynamic_atexit_destructor_for__TempAlignBuffer__);
  return;
}


// ---------------------------------------------------------------------
// `dynamic_initializer_for_'TempDeleteBuffer''  @ 4fc01251  lines 101-101

void __cdecl _dynamic_initializer_for__TempDeleteBuffer__(void)

{
  atexit(_dynamic_atexit_destructor_for__TempDeleteBuffer__);
  return;
}


// ---------------------------------------------------------------------
// `dynamic_initializer_for_'TempDeploySoundBuffer''  @ 4fc0125d  lines 102-102

void __cdecl _dynamic_initializer_for__TempDeploySoundBuffer__(void)

{
  atexit(_dynamic_atexit_destructor_for__TempDeploySoundBuffer__);
  return;
}


// ---------------------------------------------------------------------
// `dynamic_initializer_for_'TempBuiltAtBuffer''  @ 4fc01269  lines 103-103

void __cdecl _dynamic_initializer_for__TempBuiltAtBuffer__(void)

{
  atexit(_dynamic_atexit_destructor_for__TempBuiltAtBuffer__);
  return;
}


// ---------------------------------------------------------------------
// `dynamic_initializer_for_'TempTeamInfoBuffer''  @ 4fc01275  lines 104-104

void __cdecl _dynamic_initializer_for__TempTeamInfoBuffer__(void)

{
  memset(&TempTeamInfoBuffer,0,0xa140);
  return;
}


// ---------------------------------------------------------------------
// BZ1Helper::BZ1Helper  @ 4fc0b0c0  lines 109-109

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

BZ1Helper * __thiscall BZ1Helper::BZ1Helper(BZ1Helper *this)

{
  int *piVar1;
  bool bVar2;
  vector<char_const_*,std::allocator<char_const_*>_> *pvVar3;
  ObjectHelper *pOVar4;
  VehicleHelper *pVVar5;
  ProductionClassHelper *pPVar6;
  PowerHelper *pPVar7;
  PowerupHelper *pPVar8;
  BuildingHelper *pBVar9;
  PortalHelper *pPVar10;
  AttacherHelper *pAVar11;
  UtilityShipHelper *pUVar12;
  ScrapHelper *pSVar13;
  UndeployHelper *pUVar14;
  AIWeaponHelper *pAVar15;
  MorphObjectHelper *pMVar16;
  CarrierHelper *pCVar17;
  GravityHelper *pGVar18;
  AmbientSoundHelper *pAVar19;
  char *pcVar20;
  int iVar21;
  int iVar22;
  float *pfVar23;
  float fVar24;
  float local_114 [4];
  char local_104 [64];
  char local_c4 [64];
  char local_84 [128];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)local_114;
  this->super_DLLBase = (DLLBase)vftable;
  memset(&this->mapInfo,0,0x48);
  memset(this->teamInfo,0,0xa140);
  pvVar3 = this->MLayPathList;
  *(undefined4 *)&this->AlignTerrainReplaceList = 0;
  *(undefined4 *)&(this->AlignTerrainReplaceList).field_0x4 = 0;
  *(undefined4 *)&(this->AlignTerrainReplaceList).field_0x8 = 0;
  *(undefined4 *)&this->DeleteAfterDelayList = 0;
  *(undefined4 *)&(this->DeleteAfterDelayList).field_0x4 = 0;
  *(undefined4 *)&(this->DeleteAfterDelayList).field_0x8 = 0;
  iVar22 = 0x10;
  *(undefined4 *)&this->DeploySoundList = 0;
  *(undefined4 *)&(this->DeploySoundList).field_0x4 = 0;
  *(undefined4 *)&(this->DeploySoundList).field_0x8 = 0;
  *(undefined4 *)&this->BuildAtList = 0;
  *(undefined4 *)&(this->BuildAtList).field_0x4 = 0;
  *(undefined4 *)&(this->BuildAtList).field_0x8 = 0;
  iVar21 = iVar22;
  do {
    *(undefined4 *)pvVar3 = 0;
    *(undefined4 *)&pvVar3->field_0x4 = 0;
    *(undefined4 *)&pvVar3->field_0x8 = 0;
    pvVar3 = pvVar3 + 1;
    iVar21 = iVar21 + -1;
  } while (iVar21 != 0);
  pvVar3 = this->PatrolPathList;
  do {
    *(undefined4 *)pvVar3 = 0;
    *(undefined4 *)&pvVar3->field_0x4 = 0;
    *(undefined4 *)&pvVar3->field_0x8 = 0;
    pvVar3 = pvVar3 + 1;
    iVar22 = iVar22 + -1;
  } while (iVar22 != 0);
  pOVar4 = operator_new(0xc);
  *(undefined4 *)&pOVar4->HandleList = 0;
  *(undefined4 *)&(pOVar4->HandleList).field_0x4 = 0;
  *(undefined4 *)&(pOVar4->HandleList).field_0x8 = 0;
  this->m_ObjectHelper = pOVar4;
  pVVar5 = operator_new(0xc);
  *(undefined4 *)&pVVar5->VehicleList = 0;
  *(undefined4 *)&(pVVar5->VehicleList).field_0x4 = 0;
  *(undefined4 *)&(pVVar5->VehicleList).field_0x8 = 0;
  this->m_VehicleHelper = pVVar5;
  pPVar6 = operator_new(1);
  this->m_ProductionClassHelper = pPVar6;
  pPVar7 = operator_new(0xc);
  PowerHelper::m_PowerHelper = pPVar7;
  *(undefined4 *)&pPVar7->PowerList = 0;
  *(undefined4 *)&(pPVar7->PowerList).field_0x4 = 0;
  *(undefined4 *)&(pPVar7->PowerList).field_0x8 = 0;
  this->m_PowerHelper = pPVar7;
  pPVar8 = operator_new(0xc);
  PowerupHelper::m_PowerupHelper = pPVar8;
  *(undefined4 *)&pPVar8->PowerupList = 0;
  *(undefined4 *)&(pPVar8->PowerupList).field_0x4 = 0;
  *(undefined4 *)&(pPVar8->PowerupList).field_0x8 = 0;
  this->m_PowerupHelper = pPVar8;
  pBVar9 = operator_new(0xc);
  BuildingHelper::m_BuildingHelper = pBVar9;
  *(undefined4 *)&pBVar9->BuildingList = 0;
  *(undefined4 *)&(pBVar9->BuildingList).field_0x4 = 0;
  *(undefined4 *)&(pBVar9->BuildingList).field_0x8 = 0;
  this->m_BuildingHelper = pBVar9;
  pPVar10 = operator_new(0x18);
  *(undefined4 *)&pPVar10->PortalList = 0;
  *(undefined4 *)&(pPVar10->PortalList).field_0x4 = 0;
  *(undefined4 *)&(pPVar10->PortalList).field_0x8 = 0;
  *(undefined4 *)&pPVar10->TeleportTargetList = 0;
  *(undefined4 *)&(pPVar10->TeleportTargetList).field_0x4 = 0;
  *(undefined4 *)&(pPVar10->TeleportTargetList).field_0x8 = 0;
  this->m_PortalHelper = pPVar10;
  pAVar11 = operator_new(0xc);
  *(undefined4 *)&pAVar11->AttacherList = 0;
  *(undefined4 *)&(pAVar11->AttacherList).field_0x4 = 0;
  *(undefined4 *)&(pAVar11->AttacherList).field_0x8 = 0;
  this->m_AttacherHelper = pAVar11;
  pUVar12 = operator_new(0xc);
  UtilityShipHelper::m_UtilityShipHelper = pUVar12;
  *(undefined4 *)&pUVar12->UtilityShipList = 0;
  *(undefined4 *)&(pUVar12->UtilityShipList).field_0x4 = 0;
  *(undefined4 *)&(pUVar12->UtilityShipList).field_0x8 = 0;
  this->m_UtilityShipHelper = pUVar12;
  pSVar13 = operator_new(0xc);
  ScrapHelper::m_ScrapHelper = pSVar13;
  *(undefined4 *)&pSVar13->ScrapList = 0;
  *(undefined4 *)&(pSVar13->ScrapList).field_0x4 = 0;
  *(undefined4 *)&(pSVar13->ScrapList).field_0x8 = 0;
  this->m_ScrapHelper = pSVar13;
  DispatchHelper::m_DispatchHelper = operator_new(0x10);
  DispatchHelper::m_DispatchHelper->vfptr = (int)DispatchHelper::vftable;
  *(undefined4 *)&DispatchHelper::m_DispatchHelper->DispatchList = 0;
  *(undefined4 *)&(DispatchHelper::m_DispatchHelper->DispatchList).field_0x4 = 0;
  *(undefined4 *)&(DispatchHelper::m_DispatchHelper->DispatchList).field_0x8 = 0;
  this->m_DispatchHelper = DispatchHelper::m_DispatchHelper;
  pUVar14 = operator_new(0xc);
  UndeployHelper::m_UndeployHelper = pUVar14;
  *(undefined4 *)&pUVar14->UndeployList = 0;
  *(undefined4 *)&(pUVar14->UndeployList).field_0x4 = 0;
  *(undefined4 *)&(pUVar14->UndeployList).field_0x8 = 0;
  this->m_UndeployHelper = pUVar14;
  pAVar15 = operator_new(1);
  this->m_AIWeaponHelper = pAVar15;
  pMVar16 = operator_new(0x10);
  MorphObjectHelper::m_MorphObjectHelper = pMVar16;
  pMVar16->vfptr = (int)MorphObjectHelper::vftable;
  *(undefined4 *)&pMVar16->MorphObjectList = 0;
  *(undefined4 *)&(pMVar16->MorphObjectList).field_0x4 = 0;
  *(undefined4 *)&(pMVar16->MorphObjectList).field_0x8 = 0;
  this->m_MorphObjectHelper = pMVar16;
  pCVar17 = operator_new(0x1c);
  pCVar17->vfptr = (int)CarrierHelper::vftable;
  *(undefined4 *)&pCVar17->CarrierList = 0;
  *(undefined4 *)&(pCVar17->CarrierList).field_0x4 = 0;
  *(undefined4 *)&(pCVar17->CarrierList).field_0x8 = 0;
  *(undefined4 *)&pCVar17->DroneList = 0;
  *(undefined4 *)&(pCVar17->DroneList).field_0x4 = 0;
  *(undefined4 *)&(pCVar17->DroneList).field_0x8 = 0;
  this->m_CarrierHelper = pCVar17;
  pGVar18 = operator_new(0x140);
  memset(pGVar18,0,0x140);
  this->m_GravityHelper = pGVar18;
  pAVar19 = operator_new(0xe00);
  memset(pAVar19,0,0xe00);
  this->m_AmbientSoundHelper = pAVar19;
  EnableHighTPS(&m_GameTPS);
  pcVar20 = GetMapTRNFilename();
  TRNAllies::SetupTRNAllies(pcVar20);
  this->b_count = 0xb;
  this->b_array = &this->m_DidInit;
  pfVar23 = &this->m_DamageMultiplier;
  piVar1 = &this->m_ScrapMultiplier;
  this->f_count = 4;
  this->f_array = pfVar23;
  this->i_count = 0x16;
  this->i_array = piVar1;
  if (piVar1 != (int *)0x0) {
    memset(piVar1,0,0x58);
    pfVar23 = this->f_array;
  }
  if (pfVar23 != (float *)0x0) {
    memset(pfVar23,0,this->f_count << 2);
  }
  if (this->b_array != (bool *)0x0) {
    memset(this->b_array,0,this->b_count);
  }
  local_114[1] = -4000.0;
  local_114[2] = 0.0;
  HullGauge2 = 0.0;
  AmmoGauge2 = 0.0;
  AuxGauge = 0.0;
  m_TurnCounter = 0;
  TotalMapObjects = 0;
  WorldSetting = '\0';
  this->AIpathCount = 0;
  this->AIpathNames = (char **)0x0;
  local_114[3] = -4000.0;
  OffMapPos.x = -4000.0;
  HullGaugeSet = false;
  AmmoGaugeSet = false;
  AuxGaugeSet = false;
  OffMapPos.y = 0.0;
  OffMapPos.z = -4000.0;
  memset(local_84,0,0x80);
  pcVar20 = GetMapTRNFilename();
  strcpy_s(local_84,0x80,pcVar20);
  bVar2 = OpenODF2(local_84);
  if (bVar2) {
    GetODFChar(local_84,"World","WorldLetter",&WorldSetting,'\0');
    bVar2 = IsNetworkOn();
    if (bVar2) {
      iVar22 = GetVarItemInt("network.session.ivar53");
      if (iVar22 != 2) {
        iVar22 = GetVarItemInt("network.session.ivar12");
        if (iVar22 != 1) goto LAB_4fc0b4a4;
      }
    }
    else {
LAB_4fc0b4a4:
      iVar22 = IFace_GetInteger("options.instant.awarev13");
      if (iVar22 == 0) goto LAB_4fc0b560;
    }
    fVar24 = 0.0;
    do {
      memset(local_104,0,0x40);
      memset(local_c4,0,0x40);
      local_114[0] = (float)((int)fVar24 + 1);
      sprintf_s<64>(&local_c4,"MPISwitchTeams%d",(int)local_114[0]);
      iVar22 = GetODFString(local_84,"DLL",local_c4,0x40,local_104,(char *)0x0);
      if ((iVar22 == 0) || (local_104[0] == '\0')) break;
      iVar22 = atoi(local_104);
      m_SwitchTeamA[(int)fVar24] = iVar22;
      pcVar20 = strchr(local_104,0x5f);
      if (pcVar20 != (char *)0x0) {
        iVar22 = atoi(pcVar20 + 1);
        m_SwitchTeamB[(int)fVar24] = iVar22;
      }
      fVar24 = local_114[0];
    } while ((int)local_114[0] < 0x10);
  }
LAB_4fc0b560:
  iVar22 = GetVarItemInt("network.session.ivar115");
  if (iVar22 == 0) {
    iVar22 = GetVarItemInt("network.session.civar5");
    if (iVar22 == 0) {
      Logging = false;
      goto LAB_4fc0b580;
    }
  }
  Logging = true;
LAB_4fc0b580:
  memset(&this->mapInfo,0,0x48);
  memset(this->teamInfo,0,0xa140);
  local_114[0] = 0.0;
  m_GameVersion = 0x4ed9;
  bVar2 = OpenODF2("PatchData.txt");
  if (bVar2) {
    GetODFFloat("PatchData.txt","VersionInfo","Version",local_114,0.0);
  }
  m_ModVersion = local_114[0];
  sprintf_s<64>(&LogFileName,"VSR");
  m_BZ1Helper = this;
  PrintConsoleMessage("VSR BZCC DLL Created by General BlackDragon");
  bVar2 = DoesFileExist("vsrbasesetup.cfg");
  if (bVar2) {
    IFace_Exec("vsrbasesetup.cfg");
  }
  return this;
}


// ---------------------------------------------------------------------
// BZ1Helper::~BZ1Helper  @ 4fc0b66b  lines 262-327

void __thiscall BZ1Helper::~BZ1Helper(BZ1Helper *this)

{
  BZ1Helper *pBVar1;
  vector<char_const_*,std::allocator<char_const_*>_> *pvVar2;
  vector<ObjectHelper::ObjectClass,std::allocator<ObjectHelper::ObjectClass>_> *this_00;
  vector<VehicleHelper::VehicleClass,std::allocator<VehicleHelper::VehicleClass>_> *this_01;
  vector<PowerHelper::PowerClass,std::allocator<PowerHelper::PowerClass>_> *this_02;
  vector<PowerupHelper::PowerupClass,std::allocator<PowerupHelper::PowerupClass>_> *this_03;
  vector<BuildingHelper::BuildingClass,std::allocator<BuildingHelper::BuildingClass>_> *this_04;
  PortalHelper *this_05;
  vector<AttacherHelper::AttacherClass,std::allocator<AttacherHelper::AttacherClass>_> *this_06;
  vector<UtilityShipHelper::UtilityShipClass,std::allocator<UtilityShipHelper::UtilityShipClass>_>
  *this_07;
  ScrapHelper *block;
  void *pvVar3;
  UndeployHelper *block_00;
  DLLBase _Ptr;
  bool bVar4;
  BZ1Helper *this_08;
  int iVar5;
  int iVar6;
  BZ1Helper *pBVar7;
  vector<char_const_*,std::allocator<char_const_*>_> *pvVar8;
  
  bVar4 = Logging;
  this->super_DLLBase = (DLLBase)vftable;
  if (bVar4) {
    FormatLogMessage("Game Ended.\n");
  }
  CloseOpenODFs();
  if (LogFile != (_iobuf *)0x0) {
    fclose((FILE *)LogFile);
  }
  CloseOpenFiles();
  CleanupTaunts();
  if ((DeathCameraOn != false) && (bVar4 = IsNetworkOn(), bVar4)) {
    ClearDeathCamera(this_08);
  }
  this_00 = &this->m_ObjectHelper->HandleList;
  if (this_00 != (vector<ObjectHelper::ObjectClass,std::allocator<ObjectHelper::ObjectClass>_> *)0x0
     ) {
    std::vector<ObjectHelper::ObjectClass,std::allocator<ObjectHelper::ObjectClass>_>::_Tidy
              (this_00);
    operator_delete(this_00,0xc);
  }
  this_01 = &this->m_VehicleHelper->VehicleList;
  if (this_01 !=
      (vector<VehicleHelper::VehicleClass,std::allocator<VehicleHelper::VehicleClass>_> *)0x0) {
    std::vector<VehicleHelper::VehicleClass,std::allocator<VehicleHelper::VehicleClass>_>::_Tidy
              (this_01);
    operator_delete(this_01,0xc);
  }
  if (this->m_ProductionClassHelper != (ProductionClassHelper *)0x0) {
    operator_delete(this->m_ProductionClassHelper,1);
  }
  this_02 = &this->m_PowerHelper->PowerList;
  if (this_02 != (vector<PowerHelper::PowerClass,std::allocator<PowerHelper::PowerClass>_> *)0x0) {
    PowerHelper::m_PowerHelper = (PowerHelper *)0x0;
    std::vector<PowerHelper::PowerClass,std::allocator<PowerHelper::PowerClass>_>::_Tidy(this_02);
    operator_delete(this_02,0xc);
  }
  this_03 = &this->m_PowerupHelper->PowerupList;
  if (this_03 !=
      (vector<PowerupHelper::PowerupClass,std::allocator<PowerupHelper::PowerupClass>_> *)0x0) {
    PowerupHelper::m_PowerupHelper = (PowerupHelper *)0x0;
    std::vector<PowerupHelper::PowerupClass,std::allocator<PowerupHelper::PowerupClass>_>::_Tidy
              (this_03);
    operator_delete(this_03,0xc);
  }
  this_04 = &this->m_BuildingHelper->BuildingList;
  if (this_04 !=
      (vector<BuildingHelper::BuildingClass,std::allocator<BuildingHelper::BuildingClass>_> *)0x0) {
    BuildingHelper::m_BuildingHelper = (BuildingHelper *)0x0;
    std::vector<BuildingHelper::BuildingClass,std::allocator<BuildingHelper::BuildingClass>_>::_Tidy
              (this_04);
    operator_delete(this_04,0xc);
  }
  this_05 = this->m_PortalHelper;
  if (this_05 != (PortalHelper *)0x0) {
    std::
    vector<PortalHelper::TeleportTargetClass,std::allocator<PortalHelper::TeleportTargetClass>_>::
    _Tidy(&this_05->TeleportTargetList);
    std::vector<PortalHelper::PortalClass,std::allocator<PortalHelper::PortalClass>_>::_Tidy
              (&this_05->PortalList);
    operator_delete(this_05,0x18);
  }
  this_06 = &this->m_AttacherHelper->AttacherList;
  if (this_06 !=
      (vector<AttacherHelper::AttacherClass,std::allocator<AttacherHelper::AttacherClass>_> *)0x0) {
    std::vector<AttacherHelper::AttacherClass,std::allocator<AttacherHelper::AttacherClass>_>::_Tidy
              (this_06);
    operator_delete(this_06,0xc);
  }
  this_07 = &this->m_UtilityShipHelper->UtilityShipList;
  if (this_07 !=
      (vector<UtilityShipHelper::UtilityShipClass,std::allocator<UtilityShipHelper::UtilityShipClass>_>
       *)0x0) {
    UtilityShipHelper::m_UtilityShipHelper = (UtilityShipHelper *)0x0;
    std::
    vector<UtilityShipHelper::UtilityShipClass,std::allocator<UtilityShipHelper::UtilityShipClass>_>
    ::_Tidy(this_07);
    operator_delete(this_07,0xc);
  }
  block = this->m_ScrapHelper;
  if (block != (ScrapHelper *)0x0) {
    pvVar3 = *(void **)&block->ScrapList;
    ScrapHelper::m_ScrapHelper = (ScrapHelper *)0x0;
    if (pvVar3 != (void *)0x0) {
      std::_Deallocate<8,0>(pvVar3,*(int *)&(block->ScrapList).field_0x8 - (int)pvVar3 & 0xfffffffc)
      ;
      *(undefined4 *)&block->ScrapList = 0;
      *(undefined4 *)&(block->ScrapList).field_0x4 = 0;
      *(undefined4 *)&(block->ScrapList).field_0x8 = 0;
    }
    operator_delete(block,0xc);
  }
  if (this->m_DispatchHelper != (DispatchHelper *)0x0) {
    (**(code **)this->m_DispatchHelper->vfptr)(1);
  }
  block_00 = this->m_UndeployHelper;
  if (block_00 != (UndeployHelper *)0x0) {
    pvVar3 = *(void **)&block_00->UndeployList;
    UndeployHelper::m_UndeployHelper = (UndeployHelper *)0x0;
    if (pvVar3 != (void *)0x0) {
      std::_Deallocate<8,0>
                (pvVar3,*(int *)&(block_00->UndeployList).field_0x8 - (int)pvVar3 & 0xfffffff0);
      *(undefined4 *)&block_00->UndeployList = 0;
      *(undefined4 *)&(block_00->UndeployList).field_0x4 = 0;
      *(undefined4 *)&(block_00->UndeployList).field_0x8 = 0;
    }
    operator_delete(block_00,0xc);
  }
  operator_delete(this->m_AIWeaponHelper,1);
  if (this->m_MorphObjectHelper != (MorphObjectHelper *)0x0) {
    (**(code **)this->m_MorphObjectHelper->vfptr)(1);
  }
  if (this->m_CarrierHelper != (CarrierHelper *)0x0) {
    (**(code **)this->m_CarrierHelper->vfptr)(1);
  }
  operator_delete(this->m_GravityHelper,0x140);
  operator_delete(this->m_AmbientSoundHelper,0xe00);
  m_BZ1Helper = (BZ1Helper *)0x0;
  iVar5 = 0x10;
  iVar6 = iVar5;
  pBVar7 = this + 1;
  do {
    pBVar1 = (BZ1Helper *)(pBVar7[-1].PatrolPathList + 0xf);
    iVar6 = iVar6 + -1;
    _Ptr = pBVar1->super_DLLBase;
    if (_Ptr != (DLLBase)0x0) {
      std::_Deallocate<8,0>
                ((void *)_Ptr,
                 *(int *)&pBVar7[-1].PatrolPathList[0xf].field_0x8 - (int)_Ptr & 0xfffffffc);
      pBVar1->super_DLLBase = (DLLBase)0x0;
      *(undefined4 *)&pBVar7[-1].PatrolPathList[0xf].field_0x4 = 0;
      *(undefined4 *)&pBVar7[-1].PatrolPathList[0xf].field_0x8 = 0;
    }
    pBVar7 = pBVar1;
  } while (iVar6 != 0);
  pvVar8 = this->PatrolPathList;
  do {
    pvVar2 = pvVar8 + -1;
    iVar5 = iVar5 + -1;
    pvVar3 = *(void **)pvVar2;
    if (pvVar3 != (void *)0x0) {
      std::_Deallocate<8,0>(pvVar3,*(int *)&pvVar8[-1].field_0x8 - (int)pvVar3 & 0xfffffffc);
      *(undefined4 *)pvVar2 = 0;
      *(undefined4 *)&pvVar8[-1].field_0x4 = 0;
      *(undefined4 *)&pvVar8[-1].field_0x8 = 0;
    }
    pvVar8 = pvVar2;
  } while (iVar5 != 0);
  std::vector<BZ1Helper::BuildAtClass,std::allocator<BZ1Helper::BuildAtClass>_>::_Tidy
            (&this->BuildAtList);
  std::vector<BZ1Helper::DeploySoundClass,std::allocator<BZ1Helper::DeploySoundClass>_>::_Tidy
            (&this->DeploySoundList);
  pvVar3 = *(void **)&this->DeleteAfterDelayList;
  if (pvVar3 != (void *)0x0) {
    std::_Deallocate<8,0>
              (pvVar3,*(int *)&(this->DeleteAfterDelayList).field_0x8 - (int)pvVar3 & 0xfffffff8);
    *(undefined4 *)&this->DeleteAfterDelayList = 0;
    *(undefined4 *)&(this->DeleteAfterDelayList).field_0x4 = 0;
    *(undefined4 *)&(this->DeleteAfterDelayList).field_0x8 = 0;
  }
  pvVar3 = *(void **)&this->AlignTerrainReplaceList;
  if (pvVar3 != (void *)0x0) {
    std::_Deallocate<8,0>
              (pvVar3,*(int *)&(this->AlignTerrainReplaceList).field_0x8 - (int)pvVar3 & 0xfffffff0)
    ;
    *(undefined4 *)&this->AlignTerrainReplaceList = 0;
    *(undefined4 *)&(this->AlignTerrainReplaceList).field_0x4 = 0;
    *(undefined4 *)&(this->AlignTerrainReplaceList).field_0x8 = 0;
  }
  this->super_DLLBase = (DLLBase)DLLBase::vftable;
  return;
}


// ---------------------------------------------------------------------
// BZ1Helper::Load  @ 4fc0b943  lines 331-545

bool __thiscall BZ1Helper::Load(BZ1Helper *this,bool missionSave)

{
  vector<BZ1Helper::DeploySoundClass,std::allocator<BZ1Helper::DeploySoundClass>_>
  *_Udefault_or_fill;
  vector<BZ1Helper::BuildAtClass,std::allocator<BZ1Helper::BuildAtClass>_> *_Udefault_or_fill_00;
  vector<ObjectHelper::ObjectClass,std::allocator<ObjectHelper::ObjectClass>_> *_Udefault_or_fill_01
  ;
  vector<PowerHelper::PowerClass,std::allocator<PowerHelper::PowerClass>_> *pvVar1;
  vector<PowerupHelper::PowerupClass,std::allocator<PowerupHelper::PowerupClass>_>
  *_Udefault_or_fill_02;
  vector<BuildingHelper::BuildingClass,std::allocator<BuildingHelper::BuildingClass>_>
  *_Udefault_or_fill_03;
  vector<AttacherHelper::AttacherClass,std::allocator<AttacherHelper::AttacherClass>_>
  *_Udefault_or_fill_04;
  vector<UtilityShipHelper::UtilityShipClass,std::allocator<UtilityShipHelper::UtilityShipClass>_>
  *_Udefault_or_fill_05;
  vector<ScrapHelper::ScrapClass,std::allocator<ScrapHelper::ScrapClass>_> *_Udefault_or_fill_06;
  vector<BZ1Helper::AlignTerrainReplaceClass,std::allocator<BZ1Helper::AlignTerrainReplaceClass>_>
  *pvVar2;
  BZ1Helper *this_00;
  bool bVar3;
  forward_iterator_tag fVar4;
  forward_iterator_tag fVar5;
  bool bVar6;
  TeamInfo **ppTVar7;
  vector<VehicleHelper::VehicleClass,std::allocator<VehicleHelper::VehicleClass>_> *this_01;
  vector<PowerupHelper::PowerupClass,std::allocator<PowerupHelper::PowerupClass>_> *this_02;
  vector<BuildingHelper::BuildingClass,std::allocator<BuildingHelper::BuildingClass>_> *this_03;
  vector<UtilityShipHelper::UtilityShipClass,std::allocator<UtilityShipHelper::UtilityShipClass>_>
  *this_04;
  vector<ScrapHelper::ScrapClass,std::allocator<ScrapHelper::ScrapClass>_> *this_05;
  vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_> *this_06;
  vector<UndeployHelper::UndeployClass,std::allocator<UndeployHelper::UndeployClass>_> *this_07;
  vector<MorphObjectHelper::MorphObjectClass,std::allocator<MorphObjectHelper::MorphObjectClass>_>
  *this_08;
  int iVar8;
  vector<BZ1Helper::DeleteAfterDelayClass,std::allocator<BZ1Helper::DeleteAfterDelayClass>_>
  *extraout_ECX;
  vector<BZ1Helper::DeploySoundClass,std::allocator<BZ1Helper::DeploySoundClass>_> *extraout_ECX_00;
  vector<BZ1Helper::BuildAtClass,std::allocator<BZ1Helper::BuildAtClass>_> *extraout_ECX_01;
  vector<BZ1Helper::DeleteAfterDelayClass,std::allocator<BZ1Helper::DeleteAfterDelayClass>_> *pvVar9
  ;
  vector<VehicleHelper::VehicleClass,std::allocator<VehicleHelper::VehicleClass>_> *extraout_ECX_02;
  vector<PowerHelper::PowerClass,std::allocator<PowerHelper::PowerClass>_> *this_09;
  vector<PowerupHelper::PowerupClass,std::allocator<PowerupHelper::PowerupClass>_> *extraout_ECX_03;
  vector<BuildingHelper::BuildingClass,std::allocator<BuildingHelper::BuildingClass>_>
  *extraout_ECX_04;
  vector<AttacherHelper::AttacherClass,std::allocator<AttacherHelper::AttacherClass>_> *this_10;
  vector<UtilityShipHelper::UtilityShipClass,std::allocator<UtilityShipHelper::UtilityShipClass>_>
  *extraout_ECX_05;
  vector<ScrapHelper::ScrapClass,std::allocator<ScrapHelper::ScrapClass>_> *extraout_ECX_06;
  vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
  *extraout_ECX_07;
  vector<UndeployHelper::UndeployClass,std::allocator<UndeployHelper::UndeployClass>_>
  *extraout_ECX_08;
  vector<MorphObjectHelper::MorphObjectClass,std::allocator<MorphObjectHelper::MorphObjectClass>_>
  *extraout_ECX_09;
  TeamInfo *pTVar10;
  undefined4 unaff_ESI;
  MapInfo *pMVar11;
  TeamInfo *pTVar12;
  vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
  *_Udefault_or_fill_07;
  vector<MorphObjectHelper::MorphObjectClass,std::allocator<MorphObjectHelper::MorphObjectClass>_>
  *_Udefault_or_fill_08;
  undefined4 unaff_EDI;
  MapInfo *pMVar13;
  TeamInfo **ppTVar14;
  forward_iterator_tag in_stack_00000008;
  undefined1 uVar15;
  undefined1 uVar16;
  uint local_18;
  uint local_14;
  vector<VehicleHelper::VehicleClass,std::allocator<VehicleHelper::VehicleClass>_> *local_10;
  undefined4 local_c;
  TeamInfo *local_8;
  BZ1Helper *local_4;
  
  if (missionSave) {
    return true;
  }
  pMVar11 = &this->mapInfo;
  pMVar13 = &TempMapInfoBuffer;
  for (iVar8 = 0x12; iVar8 != 0; iVar8 = iVar8 + -1) {
    pMVar13->Height = pMVar11->Height;
    pMVar11 = (MapInfo *)&pMVar11->MapWidth;
    pMVar13 = (MapInfo *)&pMVar13->MapWidth;
  }
  pvVar9 = (vector<BZ1Helper::DeleteAfterDelayClass,std::allocator<BZ1Helper::DeleteAfterDelayClass>_>
            *)0x0;
  local_4 = this;
  if (&this->AlignTerrainReplaceList != &TempAlignBuffer) {
    std::
    vector<BZ1Helper::AlignTerrainReplaceClass,std::allocator<BZ1Helper::AlignTerrainReplaceClass>_>
    ::_Assign_range<BZ1Helper::AlignTerrainReplaceClass_*>
              ((vector<BZ1Helper::AlignTerrainReplaceClass,std::allocator<BZ1Helper::AlignTerrainReplaceClass>_>
                *)0x0,*(AlignTerrainReplaceClass **)&this->AlignTerrainReplaceList,
               *(AlignTerrainReplaceClass **)&(this->AlignTerrainReplaceList).field_0x4,
               (forward_iterator_tag)0x0);
    pvVar9 = extraout_ECX;
  }
  if (&this->DeleteAfterDelayList != &TempDeleteBuffer) {
    std::vector<BZ1Helper::DeleteAfterDelayClass,std::allocator<BZ1Helper::DeleteAfterDelayClass>_>
    ::_Assign_range<BZ1Helper::DeleteAfterDelayClass_*>
              (pvVar9,*(DeleteAfterDelayClass **)&this->DeleteAfterDelayList,
               *(DeleteAfterDelayClass **)&(this->DeleteAfterDelayList).field_0x4,
               (forward_iterator_tag)0x0);
    pvVar9 = (vector<BZ1Helper::DeleteAfterDelayClass,std::allocator<BZ1Helper::DeleteAfterDelayClass>_>
              *)extraout_ECX_00;
  }
  if (&this->DeploySoundList != &TempDeploySoundBuffer) {
    std::vector<BZ1Helper::DeploySoundClass,std::allocator<BZ1Helper::DeploySoundClass>_>::
    _Assign_range<BZ1Helper::DeploySoundClass_*>
              ((vector<BZ1Helper::DeploySoundClass,std::allocator<BZ1Helper::DeploySoundClass>_> *)
               pvVar9,*(DeploySoundClass **)&this->DeploySoundList,
               *(DeploySoundClass **)&(this->DeploySoundList).field_0x4,(forward_iterator_tag)0x0);
    pvVar9 = (vector<BZ1Helper::DeleteAfterDelayClass,std::allocator<BZ1Helper::DeleteAfterDelayClass>_>
              *)extraout_ECX_01;
  }
  if (&this->BuildAtList != &TempBuiltAtBuffer) {
    std::vector<BZ1Helper::BuildAtClass,std::allocator<BZ1Helper::BuildAtClass>_>::
    _Assign_range<BZ1Helper::BuildAtClass_*>
              ((vector<BZ1Helper::BuildAtClass,std::allocator<BZ1Helper::BuildAtClass>_> *)pvVar9,
               *(BuildAtClass **)&this->BuildAtList,*(BuildAtClass **)&(this->BuildAtList).field_0x4
               ,(forward_iterator_tag)0x0);
  }
  local_8 = this->teamInfo;
  ppTVar7 = &TempTeamInfoBuffer;
  pTVar10 = local_8;
  do {
    pTVar12 = pTVar10;
    ppTVar14 = ppTVar7;
    for (iVar8 = 0x285; iVar8 != 0; iVar8 = iVar8 + -1) {
      *ppTVar14 = (TeamInfo *)pTVar12->RealPlayer;
      pTVar12 = (TeamInfo *)&pTVar12->Player;
      ppTVar14 = ppTVar14 + 1;
    }
    ppTVar7 = ppTVar7 + 0x285;
    pTVar10 = pTVar10 + 1;
  } while ((int)ppTVar7 < 0x4fc7a6b0);
  bVar3 = Read(&this->mapInfo,0x48);
  local_c = 1;
  if (bVar3) {
    _Udefault_or_fill_01 = &this->m_ObjectHelper->HandleList;
    if (_Udefault_or_fill_01 != &TempHandleBuffer) {
      std::vector<ObjectHelper::ObjectClass,std::allocator<ObjectHelper::ObjectClass>_>::
      _Assign_range<ObjectHelper::ObjectClass_*>
                ((vector<ObjectHelper::ObjectClass,std::allocator<ObjectHelper::ObjectClass>_> *)0x1
                 ,*(ObjectClass **)_Udefault_or_fill_01,
                 *(ObjectClass **)&_Udefault_or_fill_01->field_0x4,(forward_iterator_tag)0x0);
    }
    local_14 = 0;
    fVar4 = (forward_iterator_tag)Read((int *)&local_14,1);
    std::vector<ObjectHelper::ObjectClass,std::allocator<ObjectHelper::ObjectClass>_>::
    _Resize<<lambda_d4eb94d7f5b88ac3e14105a7a949c756>_>
              (_Udefault_or_fill_01,local_14,
               (<lambda_d4eb94d7f5b88ac3e14105a7a949c756>)_Udefault_or_fill_01);
    this_01 = extraout_ECX_02;
    fVar5 = fVar4;
    if (local_14 == 0) {
LAB_4fc0ba8a:
      if (fVar5 == (forward_iterator_tag)0x0) goto LAB_4fc0bb1e;
    }
    else {
      if (!(bool)fVar4) {
LAB_4fc0ba82:
        fVar5 = (forward_iterator_tag)0x0;
        goto LAB_4fc0ba8a;
      }
      this_01 = (vector<VehicleHelper::VehicleClass,std::allocator<VehicleHelper::VehicleClass>_> *)
                (local_14 * 0x5c);
      bVar3 = Read(*(void **)_Udefault_or_fill_01,(int)this_01);
      if (!bVar3) goto LAB_4fc0ba82;
    }
    local_10 = &this->m_VehicleHelper->VehicleList;
    if (local_10 != &TempVehicleBuffer) {
      std::vector<VehicleHelper::VehicleClass,std::allocator<VehicleHelper::VehicleClass>_>::
      _Assign_range<VehicleHelper::VehicleClass_*>
                (this_01,*(VehicleClass **)local_10,*(VehicleClass **)&local_10->field_0x4,fVar4);
    }
    local_14 = 0;
    bVar3 = Read((int *)&local_14,1);
    std::vector<VehicleHelper::VehicleClass,std::allocator<VehicleHelper::VehicleClass>_>::
    _Resize<<lambda_211499e44519ac16b68a02000ccfed01>_>
              (local_10,local_14,(<lambda_211499e44519ac16b68a02000ccfed01>)local_10);
    if (local_14 == 0) {
LAB_4fc0bb00:
      if (bVar3 == false) goto LAB_4fc0bb1e;
    }
    else if ((!bVar3) || (bVar3 = Read(*(void **)local_10,local_14 * 0x54), !bVar3)) {
      bVar3 = false;
      goto LAB_4fc0bb00;
    }
    local_18 = 0;
    bVar3 = Read((int *)&local_18,1);
    if (!bVar3) goto LAB_4fc0bb23;
    bVar3 = true;
  }
  else {
LAB_4fc0bb1e:
    local_18 = 0;
LAB_4fc0bb23:
    bVar3 = false;
  }
  pvVar2 = &this->AlignTerrainReplaceList;
  std::
  vector<BZ1Helper::AlignTerrainReplaceClass,std::allocator<BZ1Helper::AlignTerrainReplaceClass>_>::
  _Resize<<lambda_1855a80fc533c550b5607d8bf997ad95>_>
            (pvVar2,local_18,(<lambda_1855a80fc533c550b5607d8bf997ad95>)pvVar2);
  if (local_18 == 0) {
LAB_4fc0bb66:
    local_18 = 0;
    if (bVar3) goto LAB_4fc0bb6f;
LAB_4fc0bb83:
    bVar3 = false;
  }
  else {
    if ((!bVar3) || (bVar3 = Read(*(void **)pvVar2,local_18 << 4), !bVar3)) {
      bVar3 = false;
      goto LAB_4fc0bb66;
    }
LAB_4fc0bb6f:
    local_18 = 0;
    bVar6 = Read((int *)&local_18,1);
    bVar3 = true;
    if (!bVar6) goto LAB_4fc0bb83;
  }
  pvVar9 = &this->DeleteAfterDelayList;
  std::vector<BZ1Helper::DeleteAfterDelayClass,std::allocator<BZ1Helper::DeleteAfterDelayClass>_>::
  _Resize<<lambda_4cef8f5d2e224a10ec5594e33bb09482>_>
            (pvVar9,local_18,(<lambda_4cef8f5d2e224a10ec5594e33bb09482>)pvVar9);
  if (local_18 == 0) {
LAB_4fc0bbc6:
    local_18 = 0;
    if (bVar3) goto LAB_4fc0bbcf;
LAB_4fc0bbe3:
    bVar3 = false;
  }
  else {
    if ((!bVar3) || (bVar3 = Read(*(void **)pvVar9,local_18 << 3), !bVar3)) {
      bVar3 = false;
      goto LAB_4fc0bbc6;
    }
LAB_4fc0bbcf:
    local_18 = 0;
    bVar6 = Read((int *)&local_18,1);
    bVar3 = true;
    if (!bVar6) goto LAB_4fc0bbe3;
  }
  _Udefault_or_fill = &this->DeploySoundList;
  std::vector<BZ1Helper::DeploySoundClass,std::allocator<BZ1Helper::DeploySoundClass>_>::
  _Resize<<lambda_4d52942989f528cd785dbeae06193644>_>
            (_Udefault_or_fill,local_18,(<lambda_4d52942989f528cd785dbeae06193644>)_Udefault_or_fill
            );
  if (local_18 == 0) {
LAB_4fc0bc26:
    local_18 = 0;
    if (bVar3) goto LAB_4fc0bc2f;
LAB_4fc0bc43:
    missionSave = false;
  }
  else {
    if ((!bVar3) || (bVar3 = Read(*(void **)_Udefault_or_fill,local_18 * 0x58), !bVar3)) {
      bVar3 = false;
      goto LAB_4fc0bc26;
    }
LAB_4fc0bc2f:
    local_18 = 0;
    bVar3 = Read((int *)&local_18,1);
    missionSave = true;
    if (!bVar3) goto LAB_4fc0bc43;
  }
  _Udefault_or_fill_00 = &this->BuildAtList;
  std::vector<BZ1Helper::BuildAtClass,std::allocator<BZ1Helper::BuildAtClass>_>::
  _Resize<<lambda_dee307eb94beae9268b6d89c62f4c357>_>
            (_Udefault_or_fill_00,local_18,
             (<lambda_dee307eb94beae9268b6d89c62f4c357>)_Udefault_or_fill_00);
  if (local_18 != 0) {
    if ((missionSave == false) ||
       (bVar3 = Read(*(void **)_Udefault_or_fill_00,local_18 * 0x1c), !bVar3)) {
      missionSave = false;
    }
    else {
      missionSave = true;
    }
  }
  iVar8 = 0x10;
  pTVar10 = local_8;
  do {
    if ((missionSave == false) || (bVar3 = Read(pTVar10,0xa14), !bVar3)) {
      missionSave = false;
    }
    else {
      missionSave = true;
    }
    this_00 = local_4;
    uVar16 = (undefined1)unaff_ESI;
    uVar15 = (undefined1)unaff_EDI;
    pTVar10 = pTVar10 + 1;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  if (local_4->b_array != (bool *)0x0) {
    if ((missionSave == false) || (bVar3 = Read(local_4->b_array,local_4->b_count), !bVar3)) {
      missionSave = false;
    }
    else {
      missionSave = true;
    }
  }
  bVar3 = missionSave;
  if (this_00->f_array != (float *)0x0) {
    if ((missionSave == false) || (bVar3 = Read(this_00->f_array,this_00->f_count), !bVar3)) {
      bVar3 = false;
    }
    else {
      bVar3 = true;
    }
  }
  this_09 = (vector<PowerHelper::PowerClass,std::allocator<PowerHelper::PowerClass>_> *)
            this_00->i_array;
  if (this_09 == (vector<PowerHelper::PowerClass,std::allocator<PowerHelper::PowerClass>_> *)0x0) {
LAB_4fc0bd32:
    if (bVar3 != false) goto LAB_4fc0bd3a;
  }
  else {
    if (bVar3 == false) {
LAB_4fc0bd30:
      bVar3 = false;
      goto LAB_4fc0bd32;
    }
    pvVar1 = (vector<PowerHelper::PowerClass,std::allocator<PowerHelper::PowerClass>_> *)
             this_00->i_count;
    bVar3 = Read((int *)this_09,this_00->i_count);
    this_09 = pvVar1;
    if (!bVar3) goto LAB_4fc0bd30;
LAB_4fc0bd3a:
    pvVar1 = &this_00->m_PowerHelper->PowerList;
    if (pvVar1 != &TempPowerBuffer) {
      std::vector<PowerHelper::PowerClass,std::allocator<PowerHelper::PowerClass>_>::
      _Assign_range<PowerHelper::PowerClass_*>
                (this_09,*(PowerClass **)pvVar1,*(PowerClass **)&pvVar1->field_0x4,
                 (forward_iterator_tag)missionSave);
    }
    local_14 = 0;
    fVar4 = (forward_iterator_tag)Read((int *)&local_14,1);
    std::vector<PowerHelper::PowerClass,std::allocator<PowerHelper::PowerClass>_>::
    _Resize<<lambda_4736c2bbb992635efbfd8efd81bfd98e>_>
              (pvVar1,local_14,(<lambda_4736c2bbb992635efbfd8efd81bfd98e>)pvVar1);
    this_02 = extraout_ECX_03;
    fVar5 = fVar4;
    if (local_14 == 0) {
LAB_4fc0bd9b:
      if (fVar5 == (forward_iterator_tag)0x0) goto LAB_4fc0c195;
    }
    else {
      if (!(bool)fVar4) {
LAB_4fc0bd93:
        fVar5 = (forward_iterator_tag)0x0;
        goto LAB_4fc0bd9b;
      }
      this_02 = (vector<PowerupHelper::PowerupClass,std::allocator<PowerupHelper::PowerupClass>_> *)
                (local_14 * 0x28);
      bVar3 = Read(*(void **)pvVar1,(int)this_02);
      if (!bVar3) goto LAB_4fc0bd93;
    }
    _Udefault_or_fill_02 = &this_00->m_PowerupHelper->PowerupList;
    if (_Udefault_or_fill_02 != &TempPowerupBuffer) {
      std::vector<PowerupHelper::PowerupClass,std::allocator<PowerupHelper::PowerupClass>_>::
      _Assign_range<PowerupHelper::PowerupClass_*>
                (this_02,*(PowerupClass **)_Udefault_or_fill_02,
                 *(PowerupClass **)&_Udefault_or_fill_02->field_0x4,fVar4);
    }
    local_14 = 0;
    fVar4 = (forward_iterator_tag)Read((int *)&local_14,1);
    std::vector<PowerupHelper::PowerupClass,std::allocator<PowerupHelper::PowerupClass>_>::
    _Resize<<lambda_dcc549f59dec1aad2202dcbd5a8823fa>_>
              (_Udefault_or_fill_02,local_14,
               (<lambda_dcc549f59dec1aad2202dcbd5a8823fa>)_Udefault_or_fill_02);
    this_03 = extraout_ECX_04;
    fVar5 = fVar4;
    if (local_14 == 0) {
LAB_4fc0be07:
      if (fVar5 == (forward_iterator_tag)0x0) goto LAB_4fc0c195;
    }
    else {
      if (!(bool)fVar4) {
LAB_4fc0bdff:
        fVar5 = (forward_iterator_tag)0x0;
        goto LAB_4fc0be07;
      }
      this_03 = (vector<BuildingHelper::BuildingClass,std::allocator<BuildingHelper::BuildingClass>_>
                 *)(local_14 * 0x104);
      bVar3 = Read(*(void **)_Udefault_or_fill_02,(int)this_03);
      if (!bVar3) goto LAB_4fc0bdff;
    }
    _Udefault_or_fill_03 = &this_00->m_BuildingHelper->BuildingList;
    if (_Udefault_or_fill_03 != &TempBuildingBuffer) {
      std::vector<BuildingHelper::BuildingClass,std::allocator<BuildingHelper::BuildingClass>_>::
      _Assign_range<BuildingHelper::BuildingClass_*>
                (this_03,*(BuildingClass **)_Udefault_or_fill_03,
                 *(BuildingClass **)&_Udefault_or_fill_03->field_0x4,fVar4);
    }
    local_14 = 0;
    bVar3 = Read((int *)&local_14,1);
    std::vector<BuildingHelper::BuildingClass,std::allocator<BuildingHelper::BuildingClass>_>::
    _Resize<<lambda_ec97c231cece026f40cdadd6cbe85fc1>_>
              (_Udefault_or_fill_03,local_14,
               (<lambda_ec97c231cece026f40cdadd6cbe85fc1>)_Udefault_or_fill_03);
    if (local_14 == 0) {
LAB_4fc0be73:
      if (bVar3 == false) goto LAB_4fc0c195;
    }
    else if ((!bVar3) || (bVar3 = Read(*(void **)_Udefault_or_fill_03,local_14 * 0x458), !bVar3)) {
      bVar3 = false;
      goto LAB_4fc0be73;
    }
    bVar3 = PortalHelper::Load(this_00->m_PortalHelper,(bool)uVar15);
    if (bVar3) {
      _Udefault_or_fill_04 = &this_00->m_AttacherHelper->AttacherList;
      if (_Udefault_or_fill_04 != &TempAttacherBuffer) {
        std::vector<AttacherHelper::AttacherClass,std::allocator<AttacherHelper::AttacherClass>_>::
        _Assign_range<AttacherHelper::AttacherClass_*>
                  (this_10,*(AttacherClass **)_Udefault_or_fill_04,
                   *(AttacherClass **)&_Udefault_or_fill_04->field_0x4,in_stack_00000008);
      }
      local_10 = (vector<VehicleHelper::VehicleClass,std::allocator<VehicleHelper::VehicleClass>_> *
                 )0x0;
      fVar4 = (forward_iterator_tag)Read((int *)&local_10,1);
      std::vector<AttacherHelper::AttacherClass,std::allocator<AttacherHelper::AttacherClass>_>::
      _Resize<<lambda_7ba5f03559cb281997e133de678b9134>_>
                (_Udefault_or_fill_04,(uint)local_10,
                 (<lambda_7ba5f03559cb281997e133de678b9134>)_Udefault_or_fill_04);
      this_04 = extraout_ECX_05;
      fVar5 = fVar4;
      if (local_10 ==
          (vector<VehicleHelper::VehicleClass,std::allocator<VehicleHelper::VehicleClass>_> *)0x0) {
LAB_4fc0beef:
        if (fVar5 == (forward_iterator_tag)0x0) goto LAB_4fc0c195;
      }
      else {
        if (!(bool)fVar4) {
LAB_4fc0bee7:
          fVar5 = (forward_iterator_tag)0x0;
          goto LAB_4fc0beef;
        }
        this_04 = (vector<UtilityShipHelper::UtilityShipClass,std::allocator<UtilityShipHelper::UtilityShipClass>_>
                   *)((int)local_10 * 0x40c);
        bVar3 = Read(*(void **)_Udefault_or_fill_04,(int)this_04);
        if (!bVar3) goto LAB_4fc0bee7;
      }
      _Udefault_or_fill_05 = &this_00->m_UtilityShipHelper->UtilityShipList;
      if (_Udefault_or_fill_05 != &TempUtilityShipBuffer) {
        std::
        vector<UtilityShipHelper::UtilityShipClass,std::allocator<UtilityShipHelper::UtilityShipClass>_>
        ::_Assign_range<UtilityShipHelper::UtilityShipClass_*>
                  (this_04,*(UtilityShipClass **)_Udefault_or_fill_05,
                   *(UtilityShipClass **)&_Udefault_or_fill_05->field_0x4,fVar4);
      }
      local_10 = (vector<VehicleHelper::VehicleClass,std::allocator<VehicleHelper::VehicleClass>_> *
                 )0x0;
      fVar4 = (forward_iterator_tag)Read((int *)&local_10,1);
      std::
      vector<UtilityShipHelper::UtilityShipClass,std::allocator<UtilityShipHelper::UtilityShipClass>_>
      ::_Resize<<lambda_c8a4f4cad98f6de524d7658fab4f9ded>_>
                (_Udefault_or_fill_05,(uint)local_10,
                 (<lambda_c8a4f4cad98f6de524d7658fab4f9ded>)_Udefault_or_fill_05);
      this_05 = extraout_ECX_06;
      fVar5 = fVar4;
      if (local_10 ==
          (vector<VehicleHelper::VehicleClass,std::allocator<VehicleHelper::VehicleClass>_> *)0x0) {
LAB_4fc0bf58:
        if (fVar5 == (forward_iterator_tag)0x0) goto LAB_4fc0c195;
      }
      else {
        if (!(bool)fVar4) {
LAB_4fc0bf50:
          fVar5 = (forward_iterator_tag)0x0;
          goto LAB_4fc0bf58;
        }
        this_05 = (vector<ScrapHelper::ScrapClass,std::allocator<ScrapHelper::ScrapClass>_> *)
                  ((int)local_10 * 0x2c);
        bVar3 = Read(*(void **)_Udefault_or_fill_05,(int)this_05);
        if (!bVar3) goto LAB_4fc0bf50;
      }
      _Udefault_or_fill_06 = &this_00->m_ScrapHelper->ScrapList;
      if (_Udefault_or_fill_06 != &TempScrapBuffer) {
        std::vector<ScrapHelper::ScrapClass,std::allocator<ScrapHelper::ScrapClass>_>::
        _Assign_range<ScrapHelper::ScrapClass_*>
                  (this_05,*(ScrapClass **)_Udefault_or_fill_06,
                   *(ScrapClass **)&_Udefault_or_fill_06->field_0x4,fVar4);
      }
      local_10 = (vector<VehicleHelper::VehicleClass,std::allocator<VehicleHelper::VehicleClass>_> *
                 )0x0;
      fVar4 = (forward_iterator_tag)Read((int *)&local_10,1);
      std::vector<ScrapHelper::ScrapClass,std::allocator<ScrapHelper::ScrapClass>_>::
      _Resize<<lambda_5fdf7784746bcf490d41dbfe20fcbd69>_>
                (_Udefault_or_fill_06,(uint)local_10,
                 (<lambda_5fdf7784746bcf490d41dbfe20fcbd69>)_Udefault_or_fill_06);
      this_06 = extraout_ECX_07;
      fVar5 = fVar4;
      if (local_10 ==
          (vector<VehicleHelper::VehicleClass,std::allocator<VehicleHelper::VehicleClass>_> *)0x0) {
LAB_4fc0bfc1:
        if (fVar5 == (forward_iterator_tag)0x0) goto LAB_4fc0c195;
      }
      else {
        if (!(bool)fVar4) {
LAB_4fc0bfb9:
          fVar5 = (forward_iterator_tag)0x0;
          goto LAB_4fc0bfc1;
        }
        this_06 = (vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
                   *)((int)local_10 << 2);
        bVar3 = Read(*(void **)_Udefault_or_fill_06,(int)this_06);
        if (!bVar3) goto LAB_4fc0bfb9;
      }
      _Udefault_or_fill_07 = &this_00->m_DispatchHelper->DispatchList;
      if (_Udefault_or_fill_07 != &TempDispatchBuffer) {
        std::vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>::
        _Assign_range<DispatchHelper::DispatchClass_*>
                  (this_06,*(DispatchClass **)_Udefault_or_fill_07,
                   *(DispatchClass **)&(this_00->m_DispatchHelper->DispatchList).field_0x4,fVar4);
      }
      local_10 = (vector<VehicleHelper::VehicleClass,std::allocator<VehicleHelper::VehicleClass>_> *
                 )0x0;
      fVar4 = (forward_iterator_tag)Read((int *)&local_10,1);
      std::
      vector<MorphObjectHelper::MorphObjectClass,std::allocator<MorphObjectHelper::MorphObjectClass>_>
      ::_Resize<<lambda_6e1c0ab678e9364d699d8dd7ba7d9fb6>_>
                ((vector<MorphObjectHelper::MorphObjectClass,std::allocator<MorphObjectHelper::MorphObjectClass>_>
                  *)_Udefault_or_fill_07,(uint)local_10,
                 (<lambda_6e1c0ab678e9364d699d8dd7ba7d9fb6>)_Udefault_or_fill_07);
      this_07 = extraout_ECX_08;
      fVar5 = fVar4;
      if (local_10 ==
          (vector<VehicleHelper::VehicleClass,std::allocator<VehicleHelper::VehicleClass>_> *)0x0) {
LAB_4fc0c030:
        if (fVar5 == (forward_iterator_tag)0x0) goto LAB_4fc0c195;
      }
      else {
        if (!(bool)fVar4) {
LAB_4fc0c028:
          fVar5 = (forward_iterator_tag)0x0;
          goto LAB_4fc0c030;
        }
        this_07 = (vector<UndeployHelper::UndeployClass,std::allocator<UndeployHelper::UndeployClass>_>
                   *)((int)local_10 * 0x148);
        bVar3 = Read(*(void **)_Udefault_or_fill_07,(int)this_07);
        if (!bVar3) goto LAB_4fc0c028;
      }
      pvVar2 = (vector<BZ1Helper::AlignTerrainReplaceClass,std::allocator<BZ1Helper::AlignTerrainReplaceClass>_>
                *)this_00->m_UndeployHelper;
      if (pvVar2 != (vector<BZ1Helper::AlignTerrainReplaceClass,std::allocator<BZ1Helper::AlignTerrainReplaceClass>_>
                     *)&TempUndeployBuffer) {
        std::vector<UndeployHelper::UndeployClass,std::allocator<UndeployHelper::UndeployClass>_>::
        _Assign_range<UndeployHelper::UndeployClass_*>
                  (this_07,*(UndeployClass **)pvVar2,*(UndeployClass **)&pvVar2->field_0x4,fVar4);
      }
      local_10 = (vector<VehicleHelper::VehicleClass,std::allocator<VehicleHelper::VehicleClass>_> *
                 )0x0;
      fVar4 = (forward_iterator_tag)Read((int *)&local_10,1);
      std::
      vector<BZ1Helper::AlignTerrainReplaceClass,std::allocator<BZ1Helper::AlignTerrainReplaceClass>_>
      ::_Resize<<lambda_1855a80fc533c550b5607d8bf997ad95>_>
                (pvVar2,(uint)local_10,(<lambda_1855a80fc533c550b5607d8bf997ad95>)pvVar2);
      this_08 = extraout_ECX_09;
      fVar5 = fVar4;
      if (local_10 ==
          (vector<VehicleHelper::VehicleClass,std::allocator<VehicleHelper::VehicleClass>_> *)0x0) {
LAB_4fc0c099:
        if (fVar5 == (forward_iterator_tag)0x0) goto LAB_4fc0c195;
      }
      else {
        if (!(bool)fVar4) {
LAB_4fc0c091:
          fVar5 = (forward_iterator_tag)0x0;
          goto LAB_4fc0c099;
        }
        this_08 = (vector<MorphObjectHelper::MorphObjectClass,std::allocator<MorphObjectHelper::MorphObjectClass>_>
                   *)((int)local_10 << 4);
        bVar3 = Read(*(void **)pvVar2,(int)this_08);
        if (!bVar3) goto LAB_4fc0c091;
      }
      _Udefault_or_fill_08 = &this_00->m_MorphObjectHelper->MorphObjectList;
      if (_Udefault_or_fill_08 != &TempMorphObjectBuffer) {
        std::
        vector<MorphObjectHelper::MorphObjectClass,std::allocator<MorphObjectHelper::MorphObjectClass>_>
        ::_Assign_range<MorphObjectHelper::MorphObjectClass_*>
                  (this_08,*(MorphObjectClass **)_Udefault_or_fill_08,
                   *(MorphObjectClass **)&(this_00->m_MorphObjectHelper->MorphObjectList).field_0x4,
                   fVar4);
      }
      local_10 = (vector<VehicleHelper::VehicleClass,std::allocator<VehicleHelper::VehicleClass>_> *
                 )0x0;
      bVar3 = Read((int *)&local_10,1);
      std::
      vector<MorphObjectHelper::MorphObjectClass,std::allocator<MorphObjectHelper::MorphObjectClass>_>
      ::_Resize<<lambda_6e1c0ab678e9364d699d8dd7ba7d9fb6>_>
                (_Udefault_or_fill_08,(uint)local_10,
                 (<lambda_6e1c0ab678e9364d699d8dd7ba7d9fb6>)_Udefault_or_fill_08);
      if ((local_10 !=
           (vector<VehicleHelper::VehicleClass,std::allocator<VehicleHelper::VehicleClass>_> *)0x0)
         && (bVar3)) {
        Read(*(void **)_Udefault_or_fill_08,(int)local_10 * 0x148);
      }
      bVar3 = CarrierHelper::Load(this_00->m_CarrierHelper,(bool)uVar16);
      if ((((((bVar3) && (bVar3 = GravityHelper::Load(this_00->m_GravityHelper,false), bVar3)) &&
            (bVar3 = AmbientSoundHelper::Load(this_00->m_AmbientSoundHelper,false), bVar3)) &&
           ((bVar3 = Read(&m_TurnCounter,1), bVar3 && (bVar3 = Read(&TotalMapObjects,1), bVar3))))
          && ((bVar3 = Read(&OffMapPos,0xc), bVar3 &&
              ((bVar3 = Read(&WorldSetting,1), bVar3 && (bVar3 = Read(&m_GameType,1), bVar3)))))) &&
         ((bVar3 = Read(&m_GameVersion,1), bVar3 && (bVar3 = Read(&m_ModVersion,1), bVar3))))
      goto LAB_4fc0c19a;
    }
  }
LAB_4fc0c195:
  local_4 = (BZ1Helper *)((uint)local_4 & 0xffffff00);
LAB_4fc0c19a:
  SetGravity((this_00->mapInfo).Gravity);
  Setup(this_00);
  return (bool)local_4._0_1_;
}


// ---------------------------------------------------------------------
// BZ1Helper::PostLoad  @ 4fc0c1bd  lines 549-697

bool __thiscall BZ1Helper::PostLoad(BZ1Helper *this,bool missionSave)

{
  bool bVar1;
  int iVar2;
  TeamInfo *pTVar3;
  int iVar4;
  undefined4 unaff_EBX;
  undefined4 unaff_EBP;
  MapInfo *unaff_ESI;
  int *piVar5;
  TeamInfo **a;
  MapInfo *unaff_EDI;
  int iVar6;
  undefined1 uVar7;
  undefined4 unaff_retaddr;
  bool in_stack_00000008;
  undefined1 uVar8;
  undefined1 uVar9;
  undefined1 uVar10;
  uint uStack_14;
  char cStack_11;
  undefined1 uVar11;
  TeamInfo *pTVar12;
  undefined1 uVar13;
  BZ1Helper *pBVar14;
  BZ1Helper *pBVar15;
  undefined1 uVar16;
  undefined4 in_stack_fffffff8;
  undefined1 uVar17;
  
  if (missionSave) {
    return true;
  }
  pBVar14 = this;
  bVar1 = ObjectHelper::PostLoad(this->m_ObjectHelper,SUB41(this,0));
  if (bVar1) {
    bVar1 = VehicleHelper::PostLoad(this->m_VehicleHelper,true);
    uStack_14 = CONCAT13(1,(undefined3)uStack_14);
    if (bVar1) goto LAB_4fc0c205;
  }
  uStack_14 = uStack_14 & 0xffffff;
LAB_4fc0c205:
  piVar5 = *(int **)&this->AlignTerrainReplaceList;
  if (piVar5 != *(int **)&(this->AlignTerrainReplaceList).field_0x4) {
    do {
      ConvertHandles(piVar5,1);
      piVar5 = piVar5 + 4;
    } while (piVar5 != *(int **)&(this->AlignTerrainReplaceList).field_0x4);
  }
  for (piVar5 = *(int **)&this->DeleteAfterDelayList;
      piVar5 != *(int **)&(this->DeleteAfterDelayList).field_0x4; piVar5 = piVar5 + 2) {
    ConvertHandles(piVar5,1);
  }
  for (piVar5 = *(int **)&this->DeploySoundList;
      piVar5 != *(int **)&(this->DeploySoundList).field_0x4; piVar5 = piVar5 + 0x16) {
    ConvertHandles(piVar5,1);
  }
  for (piVar5 = *(int **)&this->BuildAtList; piVar5 != *(int **)&(this->BuildAtList).field_0x4;
      piVar5 = piVar5 + 7) {
    ConvertHandles(piVar5,1);
  }
  pTVar3 = this->teamInfo;
  iVar6 = 0x10;
  pTVar12 = pTVar3;
  do {
    ConvertHandles(&pTVar3->RealPlayer,0x24);
    pTVar3 = pTVar3 + 1;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  pBVar15 = pBVar14;
  bVar1 = ::operator==(unaff_EDI,unaff_ESI);
  if (!bVar1) {
    FormatLogMessage("MapInfo Load Mismatch");
  }
  iVar6 = *(int *)&pBVar14->AlignTerrainReplaceList;
  iVar2 = *(int *)&(pBVar14->AlignTerrainReplaceList).field_0x4 - iVar6 >> 4;
  iVar4 = (int)(TempAlignBuffer._4_4_ - TempAlignBuffer._0_4_) >> 4;
  if (iVar4 == iVar2) {
    iVar4 = 0;
    if (0 < iVar2) {
      iVar2 = 0;
      do {
        bVar1 = ::operator==((AlignTerrainReplaceClass *)(TempAlignBuffer._0_4_ + iVar2),
                             (AlignTerrainReplaceClass *)(iVar6 + iVar2));
        if (!bVar1) {
          FormatLogMessage("AlignTerrainReplaceList Index Mismatch: %d",iVar4);
          break;
        }
        iVar4 = iVar4 + 1;
        iVar6 = *(int *)&pBVar14->AlignTerrainReplaceList;
        iVar2 = iVar2 + 0x10;
      } while (iVar4 < *(int *)&(pBVar14->AlignTerrainReplaceList).field_0x4 - iVar6 >> 4);
    }
  }
  else {
    FormatLogMessage("AlignTerrainReplaceList Size Mismatch! Old: %d New: %d",iVar4,iVar2);
  }
  iVar6 = *(int *)&pBVar14->DeleteAfterDelayList;
  iVar2 = *(int *)&(pBVar14->DeleteAfterDelayList).field_0x4 - iVar6 >> 3;
  iVar4 = (int)(TempDeleteBuffer._4_4_ - TempDeleteBuffer._0_4_) >> 3;
  if (iVar4 == iVar2) {
    iVar4 = 0;
    if (0 < iVar2) {
      do {
        bVar1 = ::operator==((DeleteAfterDelayClass *)(TempDeleteBuffer._0_4_ + iVar4 * 8),
                             (DeleteAfterDelayClass *)(iVar6 + iVar4 * 8));
        if (!bVar1) {
          FormatLogMessage("DeleteAfterDelayList Index Mismatch: %d",iVar4);
          break;
        }
        iVar4 = iVar4 + 1;
        iVar6 = *(int *)&pBVar14->DeleteAfterDelayList;
      } while (iVar4 < *(int *)&(pBVar14->DeleteAfterDelayList).field_0x4 - iVar6 >> 3);
    }
  }
  else {
    FormatLogMessage("DeleteAfterDelayList Size Mismatch! Old: %d New: %d",iVar4,iVar2);
  }
  iVar6 = (*(int *)&(pBVar14->DeploySoundList).field_0x4 - *(int *)&pBVar14->DeploySoundList) / 0x58
  ;
  iVar2 = (int)(TempDeploySoundBuffer._4_4_ - TempDeploySoundBuffer._0_4_) / 0x58;
  if (iVar2 == iVar6) {
    iVar2 = 0;
    if (0 < iVar6) {
      iVar6 = 0;
      do {
        bVar1 = ::operator==((DeploySoundClass *)(TempDeploySoundBuffer._0_4_ + iVar6),
                             (DeploySoundClass *)(*(int *)&pBVar14->DeploySoundList + iVar6));
        if (!bVar1) {
          FormatLogMessage("DeploySoundList Index Mismatch: %d",iVar2);
          break;
        }
        iVar2 = iVar2 + 1;
        iVar6 = iVar6 + 0x58;
      } while (iVar2 < (*(int *)&(pBVar14->DeploySoundList).field_0x4 -
                       *(int *)&pBVar14->DeploySoundList) / 0x58);
    }
  }
  else {
    FormatLogMessage("DeploySoundList Size Mismatch! Old: %d New: %d",iVar2,iVar6);
  }
  iVar6 = (*(int *)&(pBVar14->BuildAtList).field_0x4 - *(int *)&pBVar14->BuildAtList) / 0x1c;
  iVar2 = (int)(TempBuiltAtBuffer._4_4_ - TempBuiltAtBuffer._0_4_) / 0x1c;
  if (iVar2 == iVar6) {
    iVar2 = 0;
    if (0 < iVar6) {
      iVar6 = 0;
      do {
        bVar1 = ::operator==((BuildAtClass *)(TempBuiltAtBuffer._0_4_ + iVar6),
                             (BuildAtClass *)(*(int *)&pBVar14->BuildAtList + iVar6));
        if (!bVar1) {
          FormatLogMessage("BuildAtList Index Mismatch: %d",iVar2);
          break;
        }
        iVar2 = iVar2 + 1;
        iVar6 = iVar6 + 0x1c;
      } while (iVar2 < (*(int *)&(pBVar14->BuildAtList).field_0x4 - *(int *)&pBVar14->BuildAtList) /
                       0x1c);
    }
  }
  else {
    FormatLogMessage("BuildAtList Size Mismatch! Old: %d New: %d",iVar2,iVar6);
  }
  iVar6 = 0;
  pTVar3 = pBVar14->teamInfo;
  a = &TempTeamInfoBuffer;
  do {
    bVar1 = ::operator==((TeamInfo *)a,pTVar3);
    uVar13 = SUB41(pBVar15,0);
    uVar7 = (undefined1)unaff_retaddr;
    uVar17 = (undefined1)unaff_EBP;
    uVar16 = (undefined1)in_stack_fffffff8;
    uVar10 = (undefined1)unaff_EBX;
    uVar9 = SUB41(unaff_ESI,0);
    uVar8 = SUB41(unaff_EDI,0);
    if (!bVar1) {
      FormatLogMessage("TeamInfo Load Mismatch Team: %d",iVar6);
      pTVar3 = pTVar12;
      break;
    }
    pTVar3 = pTVar12 + 1;
    a = (TeamInfo **)((int)a + 0xa14);
    iVar6 = iVar6 + 1;
    pTVar12 = pTVar3;
  } while ((int)a < 0x4fc7a6b0);
  uVar11 = SUB41(pTVar3,0);
  if (((((cStack_11 == '\0') ||
        (bVar1 = PowerHelper::PostLoad(pBVar14->m_PowerHelper,(bool)uVar8), !bVar1)) ||
       (bVar1 = PowerupHelper::PostLoad(pBVar14->m_PowerupHelper,(bool)uVar9), !bVar1)) ||
      ((((bVar1 = BuildingHelper::PostLoad(pBVar14->m_BuildingHelper,(bool)uVar10), !bVar1 ||
         (bVar1 = PortalHelper::PostLoad(pBVar14->m_PortalHelper,SUB41(uStack_14,0)), !bVar1)) ||
        ((bVar1 = AttacherHelper::PostLoad(pBVar14->m_AttacherHelper,(bool)uVar11), !bVar1 ||
         ((bVar1 = UtilityShipHelper::PostLoad(pBVar14->m_UtilityShipHelper,(bool)uVar13), !bVar1 ||
          (bVar1 = ScrapHelper::PostLoad(pBVar14->m_ScrapHelper,(bool)uVar16), !bVar1)))))) ||
       (bVar1 = DispatchHelper::PostLoad(pBVar14->m_DispatchHelper,(bool)uVar17), !bVar1)))) ||
     (((bVar1 = UndeployHelper::PostLoad(pBVar14->m_UndeployHelper,(bool)uVar7), !bVar1 ||
       (bVar1 = MorphObjectHelper::PostLoad(pBVar14->m_MorphObjectHelper,false), !bVar1)) ||
      (bVar1 = CarrierHelper::PostLoad(pBVar14->m_CarrierHelper,in_stack_00000008), !bVar1)))) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  return bVar1;
}


// ---------------------------------------------------------------------
// BZ1Helper::Save  @ 4fc0c58f  lines 701-811

bool __thiscall BZ1Helper::Save(BZ1Helper *this,bool missionSave)

{
  AttacherHelper *pAVar1;
  UtilityShipHelper *pUVar2;
  ScrapHelper *pSVar3;
  DispatchHelper *pDVar4;
  UndeployHelper *pUVar5;
  bool bVar6;
  bool extraout_CL;
  undefined4 unaff_EBP;
  TeamInfo *pTVar7;
  GravityInfo *pGVar8;
  AmbientAudioInfo *pAVar9;
  undefined4 unaff_EDI;
  MorphObjectHelper *pMVar10;
  undefined3 in_stack_00000005;
  undefined1 uVar11;
  undefined1 uVar12;
  int local_c;
  int local_8;
  BuildingHelper *local_4;
  
  if (missionSave) {
    return true;
  }
  uVar11 = 0x48;
  bVar6 = Write(&this->mapInfo,0x48);
  if (((bVar6) && (bVar6 = ObjectHelper::Save(this->m_ObjectHelper,(bool)uVar11), bVar6)) &&
     (bVar6 = VehicleHelper::Save(this->m_VehicleHelper,extraout_CL), bVar6)) {
    bVar6 = true;
  }
  else {
    bVar6 = false;
  }
  _missionSave = *(int *)&(this->AlignTerrainReplaceList).field_0x4 -
                 *(int *)&this->AlignTerrainReplaceList >> 4;
  if ((bVar6) && (bVar6 = Write((int *)&missionSave,1), bVar6)) {
    bVar6 = true;
  }
  else {
    bVar6 = false;
  }
  if (_missionSave != 0) {
    if ((bVar6) &&
       (bVar6 = Write(*(void **)&this->AlignTerrainReplaceList,_missionSave << 4), bVar6)) {
      bVar6 = true;
    }
    else {
      bVar6 = false;
    }
  }
  _missionSave = *(int *)&(this->DeleteAfterDelayList).field_0x4 -
                 *(int *)&this->DeleteAfterDelayList >> 3;
  if ((bVar6) && (bVar6 = Write((int *)&missionSave,1), bVar6)) {
    bVar6 = true;
  }
  else {
    bVar6 = false;
  }
  if (_missionSave != 0) {
    if ((bVar6) && (bVar6 = Write(*(void **)&this->DeleteAfterDelayList,_missionSave << 3), bVar6))
    {
      bVar6 = true;
    }
    else {
      bVar6 = false;
    }
  }
  _missionSave = (*(int *)&(this->DeploySoundList).field_0x4 - *(int *)&this->DeploySoundList) /
                 0x58;
  if ((bVar6) && (bVar6 = Write((int *)&missionSave,1), bVar6)) {
    bVar6 = true;
  }
  else {
    bVar6 = false;
  }
  if (_missionSave != 0) {
    if ((bVar6) && (bVar6 = Write(*(void **)&this->DeploySoundList,_missionSave * 0x58), bVar6)) {
      bVar6 = true;
    }
    else {
      bVar6 = false;
    }
  }
  _missionSave = (*(int *)&(this->BuildAtList).field_0x4 - *(int *)&this->BuildAtList) / 0x1c;
  if ((bVar6) && (bVar6 = Write((int *)&missionSave,1), bVar6)) {
    bVar6 = true;
  }
  else {
    bVar6 = false;
  }
  if (_missionSave != 0) {
    if ((bVar6) && (bVar6 = Write(*(void **)&this->BuildAtList,_missionSave * 0x1c), bVar6)) {
      bVar6 = true;
    }
    else {
      bVar6 = false;
    }
  }
  pTVar7 = this->teamInfo;
  local_8 = 0x10;
  local_c = 0x10;
  do {
    if ((bVar6) && (bVar6 = Write(pTVar7,0xa14), bVar6)) {
      bVar6 = true;
    }
    else {
      bVar6 = false;
    }
    uVar12 = (undefined1)unaff_EBP;
    uVar11 = (undefined1)unaff_EDI;
    pTVar7 = pTVar7 + 1;
    local_c = local_c + -1;
  } while (local_c != 0);
  if (this->b_array != (bool *)0x0) {
    if ((bVar6) && (bVar6 = Write(this->b_array,this->b_count), bVar6)) {
      bVar6 = true;
    }
    else {
      bVar6 = false;
    }
  }
  if (this->f_array != (float *)0x0) {
    if ((bVar6) && (bVar6 = Write(this->f_array,this->f_count), bVar6)) {
      bVar6 = true;
    }
    else {
      bVar6 = false;
    }
  }
  if (this->i_array == (int *)0x0) {
LAB_4fc0c7e4:
    if (!bVar6) {
      return false;
    }
  }
  else if ((!bVar6) || (bVar6 = Write(this->i_array,this->i_count), !bVar6)) {
    bVar6 = false;
    goto LAB_4fc0c7e4;
  }
  local_4 = (BuildingHelper *)this->m_PowerHelper;
  local_c = (*(int *)&(((PowerHelper *)local_4)->PowerList).field_0x4 -
            *(int *)&((PowerHelper *)local_4)->PowerList) / 0x28;
  bVar6 = Write(&local_c,1);
  if (local_c == 0) {
LAB_4fc0c831:
    if (bVar6 == false) {
      return false;
    }
  }
  else if ((!bVar6) || (bVar6 = Write(*(void **)&local_4->BuildingList,local_c * 0x28), !bVar6)) {
    bVar6 = false;
    goto LAB_4fc0c831;
  }
  local_4 = (BuildingHelper *)this->m_PowerupHelper;
  local_c = (*(int *)&(((PowerupHelper *)local_4)->PowerupList).field_0x4 -
            *(int *)&((PowerupHelper *)local_4)->PowerupList) / 0x104;
  bVar6 = Write(&local_c,1);
  if (local_c == 0) {
LAB_4fc0c883:
    if (bVar6 == false) {
      return false;
    }
  }
  else if ((!bVar6) || (bVar6 = Write(*(void **)&local_4->BuildingList,local_c * 0x104), !bVar6)) {
    bVar6 = false;
    goto LAB_4fc0c883;
  }
  local_4 = this->m_BuildingHelper;
  local_c = (*(int *)&(local_4->BuildingList).field_0x4 - *(int *)&local_4->BuildingList) / 0x458;
  bVar6 = Write(&local_c,1);
  if (local_c == 0) {
LAB_4fc0c8d5:
    if (bVar6 == false) {
      return false;
    }
  }
  else if ((!bVar6) || (bVar6 = Write(*(void **)&local_4->BuildingList,local_c * 0x458), !bVar6)) {
    bVar6 = false;
    goto LAB_4fc0c8d5;
  }
  bVar6 = PortalHelper::Save(this->m_PortalHelper,(bool)uVar11);
  if (!bVar6) {
    return false;
  }
  pAVar1 = this->m_AttacherHelper;
  local_8 = (*(int *)&(pAVar1->AttacherList).field_0x4 - *(int *)&pAVar1->AttacherList) / 0x40c;
  bVar6 = Write(&local_8,1);
  if (local_8 == 0) {
LAB_4fc0c937:
    if (bVar6 == false) {
      return false;
    }
  }
  else if ((!bVar6) || (bVar6 = Write(*(void **)&pAVar1->AttacherList,local_8 * 0x40c), !bVar6)) {
    bVar6 = false;
    goto LAB_4fc0c937;
  }
  pUVar2 = this->m_UtilityShipHelper;
  local_8 = (*(int *)&(pUVar2->UtilityShipList).field_0x4 - *(int *)&pUVar2->UtilityShipList) / 0x2c
  ;
  bVar6 = Write(&local_8,1);
  if (local_8 == 0) {
LAB_4fc0c984:
    if (bVar6 == false) {
      return false;
    }
  }
  else if ((!bVar6) || (bVar6 = Write(*(void **)&pUVar2->UtilityShipList,local_8 * 0x2c), !bVar6)) {
    bVar6 = false;
    goto LAB_4fc0c984;
  }
  pSVar3 = this->m_ScrapHelper;
  local_8 = *(int *)&(pSVar3->ScrapList).field_0x4 - *(int *)&pSVar3->ScrapList >> 2;
  bVar6 = Write(&local_8,1);
  if (local_8 == 0) {
LAB_4fc0c9d0:
    if (bVar6 == false) {
      return false;
    }
  }
  else if ((!bVar6) || (bVar6 = Write(*(void **)&pSVar3->ScrapList,local_8 << 2), !bVar6)) {
    bVar6 = false;
    goto LAB_4fc0c9d0;
  }
  pDVar4 = this->m_DispatchHelper;
  local_8 = (*(int *)&(pDVar4->DispatchList).field_0x4 - *(int *)&pDVar4->DispatchList) / 0x148;
  bVar6 = Write(&local_8,1);
  if (local_8 == 0) {
LAB_4fc0ca24:
    if (bVar6 == false) {
      return false;
    }
  }
  else if ((!bVar6) || (bVar6 = Write(*(void **)&pDVar4->DispatchList,local_8 * 0x148), !bVar6)) {
    bVar6 = false;
    goto LAB_4fc0ca24;
  }
  pUVar5 = this->m_UndeployHelper;
  local_8 = *(int *)&(pUVar5->UndeployList).field_0x4 - *(int *)&pUVar5->UndeployList >> 4;
  bVar6 = Write(&local_8,1);
  if (local_8 == 0) {
LAB_4fc0ca6e:
    if (bVar6 == false) {
      return false;
    }
  }
  else if ((!bVar6) || (bVar6 = Write(*(void **)&pUVar5->UndeployList,local_8 << 4), !bVar6)) {
    bVar6 = false;
    goto LAB_4fc0ca6e;
  }
  pMVar10 = this->m_MorphObjectHelper;
  local_8 = (*(int *)&(pMVar10->MorphObjectList).field_0x4 - *(int *)&pMVar10->MorphObjectList) /
            0x148;
  bVar6 = Write(&local_8,1);
  if (local_8 != 0) {
    if ((bVar6) && (bVar6 = Write(*(void **)&pMVar10->MorphObjectList,local_8 * 0x148), bVar6))
    goto LAB_4fc0caca;
    bVar6 = false;
  }
  if (bVar6 == false) {
    return false;
  }
LAB_4fc0caca:
  bVar6 = CarrierHelper::Save(this->m_CarrierHelper,(bool)uVar12);
  if (bVar6) {
    pGVar8 = this->m_GravityHelper->gravityInfo;
    bVar6 = true;
    do {
      if ((bVar6) && (bVar6 = Write(pGVar8,0x14), bVar6)) {
        bVar6 = true;
      }
      else {
        bVar6 = false;
      }
      pGVar8 = pGVar8 + 1;
      pMVar10 = (MorphObjectHelper *)&pMVar10[-1].MorphObjectList.field_0xb;
    } while (pMVar10 != (MorphObjectHelper *)0x0);
    if (bVar6) {
      pAVar9 = this->m_AmbientSoundHelper->ambientAudioInfo;
      bVar6 = true;
      local_4 = (BuildingHelper *)0x20;
      do {
        if ((bVar6) && (bVar6 = Write(pAVar9,0x70), bVar6)) {
          bVar6 = true;
        }
        else {
          bVar6 = false;
        }
        pAVar9 = pAVar9 + 1;
        local_4 = (BuildingHelper *)((int)local_4 + -1);
      } while (local_4 != (BuildingHelper *)0x0);
      if (((((bVar6) && (bVar6 = Write(&m_TurnCounter,1), bVar6)) &&
           (bVar6 = Write(&TotalMapObjects,1), bVar6)) &&
          ((bVar6 = Write(&OffMapPos,0xc), bVar6 && (bVar6 = Write(&WorldSetting,1), bVar6)))) &&
         ((bVar6 = Write(&m_GameType,1), bVar6 &&
          ((bVar6 = Write(&m_GameVersion,1), bVar6 && (bVar6 = Write(&m_ModVersion,1), bVar6)))))) {
        return true;
      }
    }
  }
  return false;
}


// ---------------------------------------------------------------------
// BZ1Helper::AddObject  @ 4fc0cbb6  lines 817-1524

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall BZ1Helper::AddObject(BZ1Helper *this,int h)

{
  undefined1 *puVar1;
  vector<BZ1Helper::DeploySoundClass,std::allocator<BZ1Helper::DeploySoundClass>_>
  *_Udefault_or_fill;
  Vector Position;
  Vector VVar2;
  uint uVar3;
  BZ1Helper *pBVar4;
  bool bVar5;
  undefined1 uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  void *pvVar10;
  vector<ObjectHelper::ObjectClass,std::allocator<ObjectHelper::ObjectClass>_> *pvVar11;
  uint *puVar12;
  int *piVar13;
  int *piVar14;
  uint unaff_ESI;
  vector<ObjectHelper::ObjectClass,std::allocator<ObjectHelper::ObjectClass>_> *fmtarg4;
  float *pfVar15;
  int *piVar16;
  long *value;
  vector<VehicleHelper::VehicleClass,std::allocator<VehicleHelper::VehicleClass>_> *pvVar17;
  char *unaff_EDI;
  BZ1Helper *pBVar18;
  char cVar19;
  float fVar20;
  char *block;
  Vector *pVVar21;
  Matrix *pMVar22;
  size_t sVar23;
  AIWeaponHelper *this_00;
  undefined1 auStack_254 [6];
  bool local_24e [2];
  undefined4 local_24c;
  vector<VehicleHelper::VehicleClass,std::allocator<VehicleHelper::VehicleClass>_> *local_248;
  bool bStack_242;
  char cStack_241;
  undefined4 local_240;
  BZ1Helper *local_23c;
  vector<ObjectHelper::ObjectClass,std::allocator<ObjectHelper::ObjectClass>_> *local_238;
  uint DefaultTeleport__Cloaker;
  undefined4 local_230;
  float local_22c;
  uint StartDelay;
  char *local_224;
  bool *RepeatDelay;
  int Height;
  uint TempEscortPriority;
  int local_214;
  int TempPerceivedTeam;
  int ScanTeamLimit;
  long local_208;
  float local_204;
  Vector HeightOffset;
  Vector local_1f4;
  int local_1e8;
  float *local_1e4;
  int local_1e0;
  Matrix local_1dc;
  char local_190 [4];
  char TempODF1 [60];
  Matrix local_150;
  char local_110 [4];
  char acStack_10c [60];
  char local_d0 [64];
  char local_90 [64];
  char local_50 [68];
  uint local_c;
  
  local_c = __security_cookie ^ (uint)auStack_254;
  local_23c = this;
  PetWatchdogThread();
  TotalMapObjects = TotalMapObjects + 1;
  if (this->StopAddObject != false) {
    return;
  }
  memset(local_90,0,0x40);
  bVar5 = GetObjInfo(h,Get_GOClass,local_90);
  if (!bVar5) {
    return;
  }
  uVar7 = Hash(unaff_EDI,unaff_ESI);
  StartDelay = uVar7;
  cStack_241 = IsNetworkOn();
  memset(local_110,0,0x40);
  GetODFName(h,local_110);
  TempEscortPriority = Hash(unaff_EDI,unaff_ESI);
  local_24c = GetTeamNum(h);
  local_238 = (vector<ObjectHelper::ObjectClass,std::allocator<ObjectHelper::ObjectClass>_> *)
              0xffffffff;
  TempPerceivedTeam = 0x5c;
  pvVar11 = local_238;
  if (uVar7 == 0x6ee4c53d) {
    if (cStack_241 != '\0') {
      SetRandomHeadingAngle2(h);
      pvVar11 = local_238;
    }
  }
  else {
    fmtarg4 = (vector<ObjectHelper::ObjectClass,std::allocator<ObjectHelper::ObjectClass>_> *)0x0;
    puVar12 = *(uint **)&this->m_ObjectHelper->HandleList;
    iVar8 = (*(int *)&(this->m_ObjectHelper->HandleList).field_0x4 - (int)puVar12) / 0x5c;
    if (0 < iVar8) {
      do {
        if (*puVar12 == h) {
          pvVar11 = fmtarg4;
          if (puVar12[1] == TempEscortPriority) {
            FormatLogMessage("FIXME: AddObject Skipping Duplicate: %08x, ODF: \'%s\', Team is: %d, Index is: %d"
                             ,*puVar12,local_110,local_24c,(int)fmtarg4);
            return;
          }
          break;
        }
        fmtarg4 = (vector<ObjectHelper::ObjectClass,std::allocator<ObjectHelper::ObjectClass>_> *)
                  &fmtarg4->field_0x1;
        puVar12 = puVar12 + 0x17;
      } while ((int)fmtarg4 < iVar8);
    }
  }
  local_238 = pvVar11;
  OffMapPos.x = -4000.0;
  OffMapPos.z = -4000.0;
  OffMapPos.y = TerrainFindFloor(-4000.0,-4000.0);
  memset(local_190,0,0x40);
  memset(&local_1dc.rightw,0,0x40);
  GetAndOpenODFNames(h,local_190,(char *)&local_1dc.rightw,(char *)0x0);
  GetPosition(h,&HeightOffset);
  memset(local_50,0,0x40);
  GetODFString(local_190,(char *)&local_1dc.rightw,"GameObjectClass","BZCClasslabel",0x40,local_50,
               (char *)0x0);
  DefaultTeleport__Cloaker = Hash(unaff_EDI,unaff_ESI);
  local_224 = GetLabel(h);
  local_208 = GetMaxHealth(h);
  local_22c = (float)GetMaxAmmo(h);
  local_1e0 = GetCategoryTypeOverride(h);
  if (local_1e0 == -1) {
    local_1e0 = GetCategoryType(h);
  }
  if (8 < local_1e0 - 1U) {
    local_1e0 = 0;
  }
  iVar8 = local_24c;
  if ((((this->m_DidInit == false) && (0 < local_24c)) &&
      (bVar5 = IsPlayer(h), iVar8 = local_24c, !bVar5)) &&
     (((cStack_241 != '\0' &&
       ((iVar8 = GetVarItemInt("network.session.ivar53"), iVar8 == 2 ||
        (iVar8 = GetVarItemInt("network.session.ivar12"), iVar8 == 1)))) ||
      (iVar9 = IFace_GetInteger("options.instant.awarev13"), iVar8 = local_24c, iVar9 != 0)))) {
    iVar9 = 0;
    iVar8 = local_24c;
    do {
      if ((*(int *)((int)m_SwitchTeamA + iVar9) == iVar8) &&
         (*(int *)((int)m_SwitchTeamA + iVar9) != *(int *)((int)m_SwitchTeamB + iVar9))) {
        SetTeamNum(h,*(int *)((int)m_SwitchTeamB + iVar9));
        iVar8 = *(int *)((int)m_SwitchTeamB + iVar9);
      }
      iVar9 = iVar9 + 4;
    } while (iVar9 < 0x40);
  }
  local_24c = iVar8;
  if (0 < local_208) {
    piVar16 = &this->teamInfo[local_24c].NumTeamObjects;
    *piVar16 = *piVar16 + 1;
  }
  memset(local_d0,0,0x40);
  GetODFString(local_190,(char *)&local_1dc.rightw,"GameObjectClass","unitName2",0x40,local_d0,
               (char *)0x0);
  if (local_d0[0] != '\0') {
    SetObjectiveName(h,local_d0);
  }
  local_204 = 0.0;
  iVar8 = GetODFFloat(local_190,(char *)&local_1dc.rightw,"GameObjectClass","HeightOffset",
                      &local_204,0.0);
  if ((iVar8 != 0) && (local_204 != 0.0)) {
    HeightOffset.x = HeightOffset.x + 0.0;
    HeightOffset.y = HeightOffset.y + local_204;
    HeightOffset.z = HeightOffset.z + 0.0;
    this = local_23c;
    local_1f4.x = HeightOffset.x;
    local_1f4.y = HeightOffset.y;
    local_1f4.z = HeightOffset.z;
  }
  bStack_242 = false;
  if (m_TurnCounter < 1) {
LAB_4fc0d085:
    if (local_204 != 0.0) goto LAB_4fc0d092;
  }
  else {
    iVar8 = GetODFBool(local_190,(char *)&local_1dc.rightw,"GameObjectClass","AlignToTerrain",
                       &bStack_242,false);
    if (iVar8 != 0) {
      if (bStack_242 == false) goto LAB_4fc0d085;
      local_1f4.x = 0.0;
      local_1f4.y = 0.0;
      local_1f4.z = 0.0;
      piVar16 = *(int **)&this->AlignTerrainReplaceList;
      RepeatDelay = (bool *)0x0;
      piVar14 = *(int **)&(this->AlignTerrainReplaceList).field_0x4;
      for (piVar13 = piVar16; piVar13 != piVar14; piVar13 = piVar13 + 4) {
        if (*piVar13 == h) {
          iVar8 = (int)piVar13 - (int)piVar16 >> 4;
          if (-1 < iVar8) {
            pfVar15 = (float *)(piVar16 + iVar8 * 4 + 1);
            piVar16 = piVar16 + iVar8 * 4;
            local_1f4.x = *pfVar15;
            local_1f4.y = pfVar15[1];
            local_1f4.z = pfVar15[2];
            memmove(piVar16,piVar16 + 4,(int)piVar14 - (int)(piVar16 + 4));
            puVar1 = &(local_23c->AlignTerrainReplaceList).field_0x4;
            *(int *)puVar1 = *(int *)puVar1 + -0x10;
            goto LAB_4fc0d03a;
          }
          break;
        }
      }
      TerrainGetHeightAndNormal(&HeightOffset,(float *)&RepeatDelay,&local_1f4,false);
LAB_4fc0d03a:
      pMVar22 = &local_1dc;
      pVVar21 = (Vector *)h;
      GetFront(h,&pMVar22->right);
      Build_Orthogonal_Matrix(&local_1dc,&HeightOffset,pVVar21,&pMVar22->right);
      SetPosition(h,&local_150);
    }
    if (bStack_242 == false) goto LAB_4fc0d085;
LAB_4fc0d092:
    VVar2.y = HeightOffset.y;
    VVar2.x = HeightOffset.x;
    VVar2.z = HeightOffset.z;
    SetVectorPosition(h,VVar2);
  }
  Height = 0;
  ScanTeamLimit = GetNumWeapons(h);
  uVar7 = StartDelay;
  pBVar18 = local_23c;
  if (StartDelay == 0x6ee4c53d) {
    ScrapHelper::AddScrapObject
              (local_23c->m_ScrapHelper,h,local_190,(char *)&local_1dc.rightw,
               (local_23c->mapInfo).RestrictAllScrap);
    goto LAB_4fc0e04a;
  }
  pvVar11 = local_238;
  if ((int)local_238 < 0) {
    local_238 = &local_23c->m_ObjectHelper->HandleList;
    if (*(ObjectClass **)&local_238->field_0x8 == *(ObjectClass **)&local_238->field_0x4) {
      std::vector<ObjectHelper::ObjectClass,std::allocator<ObjectHelper::ObjectClass>_>::
      _Emplace_reallocate<>(local_238,*(ObjectClass **)&local_238->field_0x4);
    }
    else {
      sVar23 = 0x5c;
      iVar8 = 0;
      pvVar10 = operator_new(0,(void *)0x5c);
      memset(pvVar10,iVar8,sVar23);
      *(int *)&local_238->field_0x4 = *(int *)&local_238->field_0x4 + 0x5c;
    }
    pvVar11 = (vector<ObjectHelper::ObjectClass,std::allocator<ObjectHelper::ObjectClass>_> *)
              ((*(int *)&local_238->field_0x4 - *(int *)local_238) / 0x5c + -1);
  }
  piVar16 = (int *)((int)pvVar11 * 0x5c + *(int *)&pBVar18->m_ObjectHelper->HandleList);
  local_240 = piVar16;
  memset(piVar16,0,0x5c);
  piVar16[1] = TempEscortPriority;
  piVar16[3] = DefaultTeleport__Cloaker;
  piVar16[0x15] = local_208;
  piVar16[2] = uVar7;
  piVar16[0x16] = (int)local_22c;
  bVar5 = IsCraft(h,uVar7);
  if (bVar5) {
    piVar16[4] = 1;
  }
  else {
    bVar5 = IsBuildingOrGunTower(h,uVar7);
    if (bVar5) {
      piVar16[4] = 2;
    }
    else {
      bVar5 = IsPerson(h);
      if (bVar5) {
        piVar16[4] = 4;
      }
      else {
        bVar5 = IsPowerup(h);
        if (bVar5) {
          piVar16[4] = 8;
        }
        else {
          bVar5 = IsWeapon(h,uVar7);
          if (bVar5) {
            piVar16[4] = 0x10;
          }
          else {
            if (uVar7 == 0) {
              memset(&local_150,0,0x40);
              bVar5 = GetObjInfo(h,Get_GOClass,(char *)&local_150);
              if ((bVar5) && (iVar8 = _stricmp((char *)&local_150,"CLASS_SCRAP"), iVar8 == 0)) {
                piVar16[4] = 0x20;
                goto LAB_4fc0d27a;
              }
            }
            bVar5 = IsMisc(h,uVar7);
            if (bVar5) {
              piVar16[4] = 0x40;
            }
          }
        }
      }
    }
  }
LAB_4fc0d27a:
  if ((piVar16[4] == 0x40) || (piVar16[4] == 0x20)) {
    local_248 = (vector<VehicleHelper::VehicleClass,std::allocator<VehicleHelper::VehicleClass>_> *)
                ((uint)local_248._1_3_ << 8);
  }
  else {
    local_248 = (vector<VehicleHelper::VehicleClass,std::allocator<VehicleHelper::VehicleClass>_> *)
                CONCAT31(local_248._1_3_,1);
  }
  TempPerceivedTeam = 0;
  local_230._0_3_ = CONCAT12(1,(undefined2)local_230);
  GetODFBool(local_190,(char *)&local_1dc.rightw,"GameObjectClass","canDetect",
             (bool *)((int)&local_230 + 2),SUB41(local_248,0));
  GetODFInt(local_190,(char *)&local_1dc.rightw,"GameObjectClass","scanTeamLimit",&TempPerceivedTeam
            ,0);
  if (local_230._2_1_ != '\0') {
    uVar6 = local_248._0_1_;
    if (TempPerceivedTeam == 3) {
      uVar6 = 0;
    }
    local_248 = (vector<VehicleHelper::VehicleClass,std::allocator<VehicleHelper::VehicleClass>_> *)
                CONCAT31(local_248._1_3_,uVar6);
  }
  GetODFBool(local_190,(char *)&local_1dc.rightw,"GameObjectClass","CanHQCPObjectify",
             (bool *)(piVar16 + 5),SUB41(local_248,0));
  piVar14 = local_240;
  if (*(bool *)(piVar16 + 5) != false) {
    GetODFBool(local_190,(char *)&local_1dc.rightw,"GameObjectClass","CanHQCPObjectifyDeployed",
               (bool *)((int)local_240 + 0x15),true);
  }
  uVar3 = (uint)local_238 >> 8;
  local_238 = (vector<ObjectHelper::ObjectClass,std::allocator<ObjectHelper::ObjectClass>_> *)
              ((uint)local_238 & 0xffffff00);
  if ((((((piVar14[4] == 1) || (piVar14[4] == 8)) || (piVar14[4] == 4)) ||
       ((uVar7 == 0xcd066db7 || (uVar7 == 0xd888605f)))) ||
      ((uVar7 == 0x3eb9e3b2 || ((uVar7 == 0xa9238ce6 || (uVar7 == 0xf2ecd752)))))) &&
     ((uVar7 != 0x8d7c8912 && ((uVar7 != 0x33e33cd9 && (DefaultTeleport__Cloaker != 0x150c5d8b))))))
  {
    local_238 = (vector<ObjectHelper::ObjectClass,std::allocator<ObjectHelper::ObjectClass>_> *)
                CONCAT31((int3)uVar3,DefaultTeleport__Cloaker != 0xb472c1ee);
  }
  GetODFBool(local_190,(char *)&local_1dc.rightw,"GameObjectClass","CanTeleport",
             (bool *)((int)piVar14 + 0x16),SUB41(local_238,0));
  RepeatDelay = (bool *)((int)piVar14 + 0x17);
  GetODFBool(local_190,(char *)&local_1dc.rightw,"GameObjectClass","CanBeIdleVictim",RepeatDelay,
             true);
  bVar5 = IsCraftOrPerson(h);
  if (bVar5) {
    if (local_22c != 0.0) {
      fVar20 = GetEngageRange(h);
      piVar14[9] = (int)fVar20;
    }
    local_24e[0] = false;
    iVar8 = GetODFBool(local_190,(char *)&local_1dc.rightw,"GameObjectClass","AutoSetGroup",
                       local_24e,false);
    if ((iVar8 != 0) && (local_24e[0] != false)) {
      SetBestGroup(h);
    }
  }
  uVar7 = StartDelay;
  pBVar18 = local_23c;
  piVar16 = local_240;
  local_1e4 = (float *)(piVar14 + 0x12);
  *piVar14 = h;
  piVar14[6] = local_24c;
  piVar14[7] = local_24c;
  *local_1e4 = HeightOffset.x;
  piVar14[0x13] = (int)HeightOffset.y;
  piVar14[0x14] = (int)HeightOffset.z;
  iVar8 = local_240[4];
  if ((iVar8 == 1) || (iVar8 == 4)) {
    local_238 = (vector<ObjectHelper::ObjectClass,std::allocator<ObjectHelper::ObjectClass>_> *)0x0;
    local_240 = (int *)0x54;
    local_248 = &local_23c->m_VehicleHelper->VehicleList;
    local_1e8 = (*(int *)&local_248->field_0x4 - *(int *)local_248) / 0x54;
    if (0 < local_1e8) {
      iVar8 = 0;
      piVar14 = *(int **)local_248;
      do {
        if (*piVar14 == h) {
          if (-1 < iVar8) goto LAB_4fc0d91e;
          break;
        }
        iVar8 = iVar8 + 1;
        piVar14 = piVar14 + 0x15;
      } while (iVar8 < local_1e8);
    }
    if (*(VehicleClass **)&local_248->field_0x8 == *(VehicleClass **)&local_248->field_0x4) {
      std::vector<VehicleHelper::VehicleClass,std::allocator<VehicleHelper::VehicleClass>_>::
      _Emplace_reallocate<>(local_248,*(VehicleClass **)&local_248->field_0x4);
    }
    else {
      sVar23 = 0x54;
      iVar8 = 0;
      pvVar10 = operator_new(0,(void *)0x54);
      memset(pvVar10,iVar8,sVar23);
      *(int *)&local_248->field_0x4 = *(int *)&local_248->field_0x4 + (int)local_240;
    }
    iVar8 = (*(int *)&local_248->field_0x4 - *(int *)local_248) / (int)local_240 + -1;
LAB_4fc0d91e:
    local_248 = (vector<VehicleHelper::VehicleClass,std::allocator<VehicleHelper::VehicleClass>_> *)
                (iVar8 * 0x54 + *(int *)&pBVar18->m_VehicleHelper->VehicleList);
    memset(local_248,0,(size_t)local_240);
    *(uint *)((int)local_248 + 4) = TempEscortPriority;
    *(uint *)((int)local_248 + 8) = StartDelay;
    *(uint *)((int)local_248 + 0xc) = DefaultTeleport__Cloaker;
    local_238 = (vector<ObjectHelper::ObjectClass,std::allocator<ObjectHelper::ObjectClass>_> *)
                ((uint)local_238 & 0xffffff00);
    local_24e[0] = false;
    if (StartDelay == 0x1c628d2e) {
      iVar8 = GetODFBool(local_190,(char *)&local_1dc.rightw,"MorphTankClass","HiddenWhenMorphed",
                         (bool *)&local_238,false);
      pvVar17 = local_248;
      if ((iVar8 != 0) && (local_238._0_1_ != false)) {
        GetODFBool(local_190,(char *)&local_1dc.rightw,"CraftClass","CanAICloak",local_24e,
                   local_238._0_1_);
        value = (long *)((int)local_248 + 0x30);
        GetODFLong(local_190,(char *)&local_1dc.rightw,"GameObjectClass","MaxCloakEnergy",value,0);
        pvVar17 = local_248;
        *(long *)((int)local_248 + 0x34) = *value;
        GetODFLong(local_190,(char *)&local_1dc.rightw,"GameObjectClass","CloakEnergyCost",
                   (long *)((int)local_248 + 0x38),0);
        GetODFLong(local_190,(char *)&local_1dc.rightw,"GameObjectClass","AddCloakEnergy",
                   (long *)((int)pvVar17 + 0x3c),0);
      }
    }
    else {
      pvVar17 = local_248;
      if (DefaultTeleport__Cloaker == 0x2411d97a) {
        GetODFBool(local_190,(char *)&local_1dc.rightw,"CraftClass","CanAICloak",local_24e,false);
        pvVar17 = local_248;
      }
    }
    GetODFBool(local_190,(char *)&local_1dc.rightw,"GameObjectClass","ShowSkill",
               (bool *)((int)pvVar17 + 0x18),0 < (int)local_22c);
    GetODFInt(local_190,(char *)&local_1dc.rightw,"GameObjectClass","ShowSkillTeamFilter",
              (int *)((int)pvVar17 + 0x20),3);
    if (*(int *)((int)pvVar17 + 0x20) == 0) {
      *(int *)((int)pvVar17 + 0x20) = -1;
    }
    GetODFBool(local_190,(char *)&local_1dc.rightw,"CraftClass","CanRemoteControl",
               (bool *)((int)pvVar17 + 0x1a),false);
    GetODFBool(local_190,(char *)&local_1dc.rightw,"CraftClass","HuntIsResupply",
               (bool *)((int)pvVar17 + 0x1b),false);
    GetODFInt(local_190,(char *)&local_1dc.rightw,"CraftClass","AIEscortPriority",&Height,0);
    if (Height < 0) {
      Height = 0;
    }
    else if (3 < Height) {
      Height = 3;
    }
    if (local_22c != 0.0) {
      *(int *)((int)pvVar17 + 0x44) = piVar16[9];
    }
    *(int *)((int)pvVar17 + 0x28) = local_24c;
    *(long *)((int)pvVar17 + 0x14) = local_208;
    *(int *)pvVar17 = h;
    *(float *)((int)pvVar17 + 0x48) = *local_1e4;
    *(float *)((int)pvVar17 + 0x4c) = local_1e4[1];
    *(float *)((int)pvVar17 + 0x50) = local_1e4[2];
    *(bool *)((int)local_248 + 0x1c) = *RepeatDelay;
    if ((((local_24e[0] != false) || (DefaultTeleport__Cloaker == 0x53179125)) ||
        ((local_224 != (char *)0x0 && (iVar8 = _strnicmp(local_224,"escort",6), iVar8 == 0)))) ||
       ((DefaultTeleport__Cloaker == 0x6f5ff9ab ||
        ((((local_224 != (char *)0x0 && (iVar8 = _strnicmp(local_224,"patrol",6), iVar8 == 0)) ||
          (DefaultTeleport__Cloaker == 0x44ad0c90)) ||
         ((pBVar18 = local_23c, local_224 != (char *)0x0 &&
          (iVar8 = _strnicmp(local_224,"hunter",6), pBVar18 = local_23c, iVar8 == 0)))))))) {
      pBVar18 = local_23c;
      DispatchHelper::AddToDispatch
                (local_23c->m_DispatchHelper,h,5.0,false,0,true,false,false,false);
    }
    pBVar4 = local_23c;
    if ((((((StartDelay == 0x33a01170) || (StartDelay == 0x5cfae8c8)) ||
          ((StartDelay == 0x32493554 ||
           (((StartDelay == 0x4e12224 || (StartDelay == 0x77f02e21)) || (StartDelay == 0x2418efcf)))
           ))) || ((DefaultTeleport__Cloaker == 0x326aa115 || (StartDelay == 0xda4acce)))) ||
        (StartDelay == 0x28e4d573)) ||
       ((StartDelay == 0x7b3b7981 || (uVar7 = StartDelay, Height != 0)))) {
      Position.y = HeightOffset.y;
      Position.x = HeightOffset.x;
      Position.z = HeightOffset.z;
      UtilityShipHelper::AddUtilityShipObject
                (local_23c->m_UtilityShipHelper,h,local_24c,Position,StartDelay,
                 DefaultTeleport__Cloaker,local_190,(char *)&local_1dc.rightw,Height);
      uVar7 = StartDelay;
      pBVar18 = pBVar4;
    }
  }
  else {
    if (iVar8 != 2) {
      if (StartDelay == 0) {
        memset(&local_150,0,0x40);
        bVar5 = GetObjInfo(h,Get_GOClass,(char *)&local_150);
        pBVar18 = local_23c;
        if (!bVar5) goto LAB_4fc0d6d2;
        iVar8 = _stricmp((char *)&local_150,"CLASS_DEPOSIT");
        cVar19 = '\x01' - (iVar8 != 0);
      }
      else {
        cVar19 = StartDelay == 0xdc5f98c6;
      }
      pBVar18 = local_23c;
      if (cVar19 == '\0') goto LAB_4fc0d6d2;
    }
    pBVar18 = local_23c;
    BuildingHelper::AddBuildingObject
              (local_23c->m_BuildingHelper,h,local_190,(char *)&local_1dc.rightw,local_24c,
               TempEscortPriority,uVar7,DefaultTeleport__Cloaker,*RepeatDelay,ScanTeamLimit,
               SUB41(local_24c,0));
    memset(&local_150,0,0x40);
    iVar8 = GetODFString(local_190,(char *)&local_1dc.rightw,"BuildingClass","DeploySound",0x40,
                         (char *)&local_150,(char *)0x0);
    if (iVar8 != 0) {
      local_22c = 0.0;
      local_24e[0] = false;
      GetODFFloat(local_190,(char *)&local_1dc.rightw,"BuildingClass","DeploySoundStartDelay",
                  &local_22c,0.0);
      GetODFBool(local_190,(char *)&local_1dc.rightw,"BuildingClass","DeploySoundLoop",local_24e,
                 false);
      if ((0.0 < local_22c) || (local_24e[0] != false)) {
        _Udefault_or_fill = &pBVar18->DeploySoundList;
        std::vector<BZ1Helper::DeploySoundClass,std::allocator<BZ1Helper::DeploySoundClass>_>::
        _Resize<<lambda_4d52942989f528cd785dbeae06193644>_>
                  (_Udefault_or_fill,
                   (*(int *)&(pBVar18->DeploySoundList).field_0x4 - *(int *)_Udefault_or_fill) /
                   0x58 + 1,(<lambda_4d52942989f528cd785dbeae06193644>)_Udefault_or_fill);
        piVar16 = (int *)(*(int *)_Udefault_or_fill + -0x58 +
                         ((*(int *)&(pBVar18->DeploySoundList).field_0x4 - *(int *)_Udefault_or_fill
                          ) / 0x58) * 0x58);
        memset(piVar16,0,0x58);
        local_224 = (char *)0x0;
        GetODFFloat(local_190,(char *)&local_1dc.rightw,"BuildingClass","DeploySoundRepeatDelay",
                    (float *)&local_224,0.0);
        *piVar16 = h;
        strcpy_s((char *)(piVar16 + 6),0x40,(char *)&local_150);
        *(bool *)(piVar16 + 1) = local_24e[0];
        iVar8 = SecondsToTurns(local_22c);
        piVar16[3] = iVar8;
        iVar8 = SecondsToTurns((float)local_224);
        piVar16[4] = iVar8;
        uVar7 = StartDelay;
        pBVar18 = local_23c;
      }
      else {
        StartAudio3D((char *)&local_150,h,AUDIO_CAT_AMBIENT,false,false);
      }
    }
  }
LAB_4fc0d6d2:
  local_214 = -1;
  iVar8 = GetODFInt(local_190,(char *)&local_1dc.rightw,"GameObjectClass","PerceivedTeam",&local_214
                    ,-1);
  if (((iVar8 != 0) && (-1 < local_214)) && (iVar8 = GetPerceivedTeam(h), iVar8 != local_214)) {
    SetPerceivedTeam(h,local_214);
  }
  local_230 = (float)((uint)local_230 & 0xffffff);
  iVar8 = GetODFBool(local_190,(char *)&local_1dc.rightw,"GameObjectClass","DeleteOnLoad",
                     (bool *)((int)&local_230 + 3),false);
  if ((iVar8 != 0) && (local_230._3_1_ != '\0')) {
    DeleteAfterDelay(pBVar18,h,0.0);
  }
  local_240 = (int *)(local_24c * 0xa14);
  if ((pBVar18->teamInfo[local_24c].m_CPUAIDifficulty != 0) && (ScanTeamLimit != 0)) {
    this_00 = (AIWeaponHelper *)0x3;
    iVar8 = GetObjectByTeamSlot(local_24c,3);
    if (iVar8 != 0) {
      AIWeaponHelper::AIGiveWeapons(this_00,h,local_24c,ScanTeamLimit,SUB41(this_00,0));
    }
  }
  AttacherHelper::AddAttacherObject
            (pBVar18->m_AttacherHelper,h,local_190,(char *)&local_1dc.rightw,
             DefaultTeleport__Cloaker,local_110);
  iVar8 = _strnicmp(local_110,"BZCundep",8);
  if (iVar8 == 0) {
    UndeployHelper::AddUndeployObject(pBVar18->m_UndeployHelper,local_24c,(int)local_110,unaff_EDI);
  }
  if ((((local_1dc.right.x != 0.0) || (local_230 == -2.0556315e+18)) ||
      (local_230 == -3.0636873e+20)) ||
     ((local_230 == -11796.035 || (fVar20 = local_230, local_230 == 2.6288888e+26)))) {
    ProductionClassHelper::AddProductionClassObject
              ((ProductionClassHelper *)h,(int)TempODF1,(char *)&local_1dc.up,(char *)local_248,
               uVar7,(int)local_230,(int)local_1dc.right.x,unaff_ESI);
    fVar20 = local_22c;
  }
  if ((uint)fVar20 < 0xd7241cf8) {
    if (fVar20 == -1.8044431e+14) {
      CarrierHelper::AddCarrierObject(pBVar18->m_CarrierHelper,h,TempODF1,(char *)&local_1dc.up);
    }
    else {
      if (fVar20 == 2.8346567e-26) goto LAB_4fc0dd89;
      if (fVar20 == 3.1626073e-17) {
        MorphObjectHelper::AddMorphObjectHostObject
                  (pBVar18->m_MorphObjectHelper,h,TempODF1,(char *)&local_1dc.up);
      }
      else if (fVar20 == -2.2608558e-07) {
        PortalHelper::AddPortalSwitchObject
                  (pBVar18->m_PortalHelper,h,TempODF1,(char *)&local_1dc.up);
      }
      else if (fVar20 == -6.3148924e-05) {
        MorphObjectHelper::AddMorphObjectToggleObject(pBVar18->m_MorphObjectHelper,h);
      }
    }
  }
  else if (fVar20 == -3.3459833e+29) {
LAB_4fc0dd89:
    PortalHelper::AddPortalObject
              (pBVar18->m_PortalHelper,h,TempODF1,(char *)&local_1dc.up,(int)fVar20);
  }
  else if (fVar20 == -2.6257834e+32) {
    PowerHelper::AddPowerObject(pBVar18->m_PowerHelper,h,TempODF1,(char *)&local_1dc.up);
  }
  else if (fVar20 == -8.827889e+36) {
    CarrierHelper::AddCarrierDroneObject
              (pBVar18->m_CarrierHelper,h,(int)local_248,TempODF1,(char *)&local_1dc.up,acStack_10c)
    ;
  }
  pBVar4 = local_23c;
  local_24c = CONCAT13(1,(undefined3)local_24c);
  if (uVar7 < 0x80f9ff72) {
    if (uVar7 == 0x80f9ff71) {
      GetODFBool(TempODF1,(char *)&local_1dc.up,"SiloClass","ScrapDropPoint",
                 (bool *)((int)&local_24c + 3),true);
      if (local_24c._3_1_ != '\0') {
        piVar16 = (int *)((int)&local_23c->teamInfo[0].DropoffSilos + (int)pBVar18);
        *piVar16 = *piVar16 + 1;
      }
      goto LAB_4fc0e04a;
    }
    if (uVar7 != 0x16164674) {
      if (uVar7 == 0x33a01170) {
        memset(&local_150.right.y,0,0x40);
        block = "ScavengerClass";
LAB_4fc0de31:
        GetODFString(TempODF1,(char *)&local_1dc.up,block,"deployClass",0x40,
                     (char *)&local_150.right.y,(char *)0x0);
        if ((local_150.right.y._0_1_ != '\0') &&
           (bVar5 = DoesODFExist((char *)&local_150.right.y), bVar5)) {
          PetWatchdogThread();
          PreloadODF((char *)&local_150.right.y);
          PetWatchdogThread();
        }
        goto LAB_4fc0e04a;
      }
      if (uVar7 != 0x33fe0a68) {
        if (uVar7 == 0x490dd218) {
          GetODFBool(TempODF1,(char *)&local_1dc.up,"ExtractorClass","ScrapDropPoint",
                     (bool *)((int)&local_24c + 3),true);
          if (local_24c._3_1_ != '\0') {
            piVar16 = (int *)((int)&local_23c->teamInfo[0].DropoffExtractors + (int)pBVar18);
            *piVar16 = *piVar16 + 1;
          }
          goto LAB_4fc0e04a;
        }
        if (uVar7 != 0x4b970310) {
          if (uVar7 != 0x5cfae8c8) goto LAB_4fc0e04a;
          memset(&local_150.right.y,0,0x40);
          block = "ScavengerHClass";
          goto LAB_4fc0de31;
        }
      }
    }
  }
  else {
    if (uVar7 == 0x8a0a1ead) {
      GetODFBool(TempODF1,(char *)&local_1dc.up,"RecyclerClass","ScrapDropPoint",
                 (bool *)((int)&local_24c + 3),true);
      if (local_24c._3_1_ != '\0') {
        piVar16 = (int *)((int)&local_23c->teamInfo[0].DropoffRecylcers + (int)pBVar18);
        *piVar16 = *piVar16 + 1;
      }
      goto LAB_4fc0e04a;
    }
    if (uVar7 != 0xa662aa60) {
      if (uVar7 == 0xb18ef1c3) {
        piVar16 = (int *)((int)&local_23c->teamInfo[0].NumBarracks + (int)pBVar18);
        *piVar16 = *piVar16 + 1;
      }
      else if ((uVar7 == 0xc9cd7077) || (uVar7 == 0xcd6780cd)) {
        if ((&local_23c->teamInfo[0].TeamRace)[(int)pBVar18] == '\0') {
          cVar19 = GetRace(h);
          (&pBVar4->teamInfo[0].TeamRace)[(int)pBVar18] = cVar19;
        }
        if (pBVar18->m_BuildPools == false) {
          GetODFBool(TempODF1,(char *)&local_1dc.up,"GameObjectClass","UseBZ2Pools",
                     &pBVar18->m_BuildPools,false);
        }
      }
      goto LAB_4fc0e04a;
    }
  }
  PowerupHelper::AddPowerupObject(pBVar18->m_PowerupHelper,h,TempODF1,(char *)&local_1dc.up,1,uVar7)
  ;
LAB_4fc0e04a:
  pvVar17 = local_248;
  if ((local_240._3_1_ != '\0') && (pBVar18->teamInfo[(int)local_248].TeamIsDead != false)) {
    bVar5 = IsTeamplayOn();
    if (bVar5) {
      iVar8 = GetCommanderTeam((int)pvVar17);
      SetTeamNum(h,iVar8);
    }
    else {
      Stop(h,1);
      SetTeamNum(h,0xf);
    }
  }
  return;
}


// ---------------------------------------------------------------------
// BZ1Helper::DeleteObject  @ 4fc0e0b1  lines 1528-1695

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall BZ1Helper::DeleteObject(BZ1Helper *this,int h)

{
  vector<BZ1Helper::AlignTerrainReplaceClass,std::allocator<BZ1Helper::AlignTerrainReplaceClass>_>
  *_Udefault_or_fill;
  bool bVar1;
  uint ObjClassHash;
  long lVar2;
  int iVar3;
  int *piVar4;
  uint unaff_EBP;
  char *unaff_ESI;
  char *block;
  char *name;
  undefined1 auStack_1a8 [2];
  bool local_1a6;
  bool local_1a5;
  int local_1a4;
  float local_1a0;
  Vector local_19c;
  Vector local_190;
  char local_184 [64];
  char local_144 [64];
  char local_104 [64];
  char local_c4 [64];
  char local_84 [64];
  char local_44 [64];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)auStack_1a8;
  TotalMapObjects = TotalMapObjects + -1;
  this->m_LastObjectListCount = this->m_LastObjectListCount + -1;
  if (this->StopDeleteObject != false) {
    return;
  }
  memset(local_c4,0,0x40);
  GetObjInfo(h,Get_GOClass,local_c4);
  ObjClassHash = Hash(unaff_ESI,unaff_EBP);
  if (ObjClassHash == 0x6ee4c53d) {
    return;
  }
  memset(local_44,0,0x40);
  memset(local_144,0,0x40);
  memset(local_184,0,0x40);
  GetAndOpenODFNames(h,local_144,local_184,local_44);
  local_1a4 = GetTeamNum(h);
  lVar2 = GetMaxHealth(h);
  local_19c.x = 0.0;
  local_19c.y = 0.0;
  local_19c.z = 0.0;
  GetPosition2(h,&local_19c);
  memset(local_84,0,0x40);
  GetODFString(local_144,local_184,"GameObjectClass","BZCClasslabel",0x40,local_84,(char *)0x0);
  local_1a0 = (float)Hash(unaff_ESI,unaff_EBP);
  iVar3 = local_1a4;
  if (0 < lVar2) {
    piVar4 = &this->teamInfo[local_1a4].NumTeamObjects;
    *piVar4 = *piVar4 + -1;
  }
  bVar1 = IsCraft(h,ObjClassHash);
  if ((bVar1) || (bVar1 = IsPerson(h), bVar1)) {
    DispatchHelper::DeleteDispatchObject(this->m_DispatchHelper,h,iVar3);
  }
  if (local_1a0 == -2.6257834e+32) {
    for (piVar4 = *(int **)&this->m_PowerHelper->PowerList;
        piVar4 != *(int **)&(this->m_PowerHelper->PowerList).field_0x4; piVar4 = piVar4 + 10) {
      if (*piVar4 == h) {
        bVar1 = IsAround(*piVar4);
        if (bVar1) {
          *(undefined1 *)(piVar4 + 1) = 1;
        }
        break;
      }
    }
  }
  local_1a6 = true;
  if (ObjClassHash < 0x8a0a1eae) {
    if (ObjClassHash == 0x8a0a1ead) {
      iVar3 = GetODFBool(local_144,local_184,"RecyclerClass","ScrapDropPoint",&local_1a6,true);
      if (iVar3 == 0) {
        return;
      }
      if (local_1a6 == false) {
        return;
      }
      piVar4 = &this->teamInfo[local_1a4].DropoffRecylcers;
      *piVar4 = *piVar4 + -1;
      return;
    }
    if ((ObjClassHash != 0x219650cd) && (ObjClassHash != 0x33a01170)) {
      if (ObjClassHash == 0x490dd218) {
        iVar3 = GetODFBool(local_144,local_184,"ExtractorClass","ScrapDropPoint",&local_1a6,true);
        if (iVar3 == 0) {
          return;
        }
        if (local_1a6 == false) {
          return;
        }
        piVar4 = &this->teamInfo[local_1a4].DropoffExtractors;
        *piVar4 = *piVar4 + -1;
        return;
      }
      if (ObjClassHash != 0x5cfae8c8) {
        if (ObjClassHash != 0x80f9ff71) {
          return;
        }
        iVar3 = GetODFBool(local_144,local_184,"SiloClass","ScrapDropPoint",&local_1a6,true);
        if (iVar3 == 0) {
          return;
        }
        if (local_1a6 == false) {
          return;
        }
        piVar4 = &this->teamInfo[local_1a4].DropoffSilos;
        *piVar4 = *piVar4 + -1;
        return;
      }
    }
  }
  else {
    if (ObjClassHash == 0xb18ef1c3) {
      piVar4 = &this->teamInfo[local_1a4].NumBarracks;
      *piVar4 = *piVar4 + -1;
      return;
    }
    if (((ObjClassHash != 0xc9cd7077) && (ObjClassHash != 0xcd6780cd)) &&
       (ObjClassHash != 0xf1656077)) {
      return;
    }
  }
  bVar1 = IsDeployed(h);
  if (!bVar1) {
    return;
  }
  memset(local_104,0,0x40);
  if (((ObjClassHash == 0xc9cd7077) || (ObjClassHash == 0xcd6780cd)) ||
     ((ObjClassHash == 0xf1656077 || (ObjClassHash == 0x219650cd)))) {
    name = "deployName";
    block = "DeployBuildingClass";
  }
  else {
    iVar3 = GetODFString(local_144,local_184,"ScavengerClass","deployClass",0x40,local_104,
                         (char *)0x0);
    if (iVar3 != 0) goto LAB_4fc0e45f;
    name = "deployClass";
    block = "ScavengerHClass";
  }
  GetODFString(local_144,local_184,block,name,0x40,local_104,(char *)0x0);
LAB_4fc0e45f:
  if (local_104[0] != '\0') {
    local_1a5 = false;
    CombineStrings(local_104,local_104,".odf",0x40);
    iVar3 = GetODFBool(local_104,(char *)0x0,"GameObjectClass","AlignToTerrain",&local_1a5,false);
    if ((iVar3 != 0) && (local_1a5 != false)) {
      _Udefault_or_fill = &this->AlignTerrainReplaceList;
      for (piVar4 = *(int **)_Udefault_or_fill;
          piVar4 != *(int **)&(this->AlignTerrainReplaceList).field_0x4; piVar4 = piVar4 + 4) {
        if (*piVar4 == h) {
          return;
        }
      }
      std::
      vector<BZ1Helper::AlignTerrainReplaceClass,std::allocator<BZ1Helper::AlignTerrainReplaceClass>_>
      ::_Resize<<lambda_1855a80fc533c550b5607d8bf997ad95>_>
                (_Udefault_or_fill,
                 (*(int *)&(this->AlignTerrainReplaceList).field_0x4 - *(int *)_Udefault_or_fill >>
                 4) + 1,(<lambda_1855a80fc533c550b5607d8bf997ad95>)_Udefault_or_fill);
      iVar3 = (*(int *)&(this->AlignTerrainReplaceList).field_0x4 - *(int *)_Udefault_or_fill &
              0xfffffff0U) + *(int *)_Udefault_or_fill;
      *(undefined4 *)(iVar3 + -0x10) = 0;
      *(undefined4 *)(iVar3 + -0xc) = 0;
      *(undefined4 *)(iVar3 + -8) = 0;
      *(undefined4 *)(iVar3 + -4) = 0;
      local_190.x = 0.0;
      local_190.y = 0.0;
      local_190.z = 0.0;
      local_1a0 = 0.0;
      TerrainGetHeightAndNormal(&local_19c,&local_1a0,&local_190,false);
      *(float *)(iVar3 + -0xc) = local_190.x;
      *(float *)(iVar3 + -8) = local_190.y;
      *(float *)(iVar3 + -4) = local_190.z;
      *(int *)(iVar3 + -0x10) = h;
    }
  }
  return;
}


// ---------------------------------------------------------------------
// BZ1Helper::Init  @ 4fc0e560  lines 1699-1988

/* WARNING: Function: _alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Unable to track spacebase fully for stack */

void __thiscall BZ1Helper::Init(BZ1Helper *this)

{
  float *pfVar1;
  float fVar2;
  bool bVar3;
  char *pcVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  float fVar8;
  undefined1 *puVar9;
  float EdgePoints;
  undefined1 *local_134;
  float local_130;
  undefined1 *local_12c;
  float maxVal;
  undefined1 *local_124;
  float minVal;
  undefined1 *local_11c;
  uint bufSize;
  char local_112;
  char local_111;
  undefined1 *TempGrav;
  char MapName [128];
  char mapTrnFile [132];
  uint local_8;
  
  local_8 = __security_cookie ^ (uint)&stack0xfffffffc;
  local_112 = IsNetworkOn();
  memset(mapTrnFile,0,0x80);
  pcVar4 = GetMapTRNFilename();
  strcpy_s(mapTrnFile,0x80,pcVar4);
  bVar3 = OpenODF2(mapTrnFile);
  if (!bVar3) goto LAB_4fc0ea9d;
  GetODFFloat(mapTrnFile,"Size","Height",&(this->mapInfo).Height,0.0);
  GetODFFloat(mapTrnFile,"Size","MetersPerGrid",&(this->mapInfo).MPG,0.0);
  GetODFFloat(mapTrnFile,"Size","HeightGranularity",&(this->mapInfo).HeightGranularity,0.0);
  pfVar1 = &(this->mapInfo).MapWidth;
  iVar5 = GetODFFloat(mapTrnFile,"Size","Width",pfVar1,0.0);
  if (((iVar5 == 0) ||
      (iVar5 = GetODFFloat(mapTrnFile,"Size","Depth",&(this->mapInfo).MapDepth,0.0), iVar5 == 0)) ||
     (iVar5 = GetODFFloat(mapTrnFile,"Size","MinX",&(this->mapInfo).MinX,0.0), iVar5 == 0)) {
LAB_4fc0e6b9:
    local_111 = '\0';
  }
  else {
    iVar5 = GetODFFloat(mapTrnFile,"Size","MinZ",&(this->mapInfo).MinZ,0.0);
    local_111 = '\x01';
    if (iVar5 == 0) goto LAB_4fc0e6b9;
  }
  GetODFFloat(mapTrnFile,"World","Gravity",&(this->mapInfo).Gravity,12.5);
  if (local_111 == '\0') {
    FormatConsoleMessage
              ("ERROR! \'%s\' missing [Size] section! Out of bounds area not calibrated! FIXME!",
               mapTrnFile);
    *pfVar1 = 4096.0;
    (this->mapInfo).MapDepth = 4096.0;
    (this->mapInfo).MinX = -2048.0;
    (this->mapInfo).MinZ = -2048.0;
  }
  GetODFFloat(mapTrnFile,"DLL","ReinforcementMinRadius",&this->m_ReinforcementMinRadius,150.0);
  GetODFFloat(mapTrnFile,"DLL","ReinforcementMaxRadius",&this->m_ReinforcementMaxRadius,250.0);
  GetODFFloat(mapTrnFile,"DLL","ReinforcementCliffTolerance",&this->m_ReinforcementMaxCliff,100.0);
  GetODFFloat(mapTrnFile,"DLL","MinScrapHeight",&(this->mapInfo).MinScrapHeight,-1e+06);
  GetODFFloat(mapTrnFile,"DLL","MaxScrapHeight",&(this->mapInfo).MaxScrapHeight,1e+06);
  GetODFBool(mapTrnFile,"DLL","RestrictAllScrap",&(this->mapInfo).RestrictAllScrap,false);
  GetODFBool(mapTrnFile,"DLL","RespawnAtLowAltitude",&(this->mapInfo).RespawnAtLowAltitude,false);
  GetODFFloat(mapTrnFile,"DLL","SpawnMinRadius",&(this->mapInfo).SpawnMinRadius,20.0);
  GetODFFloat(mapTrnFile,"DLL","SpawnMaxRadius",&(this->mapInfo).SpawnMaxRadius,50.0);
  GravityHelper::LoadGravityInfo(this->m_GravityHelper,mapTrnFile);
  AmbientSoundHelper::LoadAmbientSoundInfo(this->m_AmbientSoundHelper,mapTrnFile);
  bufSize = 0;
  GetPathPoints("edge_path",&bufSize,(float *)0x0);
  iVar5 = bufSize * -8;
  EdgePoints = 0.0;
  *(undefined1 **)(&stack0xfffffeb8 + iVar5) = &stack0xfffffebc;
  TempGrav = &stack0xfffffebc;
  local_134 = (undefined1 *)0x0;
  local_130 = 0.0;
  local_12c = (undefined1 *)0x0;
  *(uint **)(&stack0xfffffeb4 + iVar5) = &bufSize;
  *(char **)(&stack0xfffffeb0 + iVar5) = "edge_path";
  *(undefined4 *)(&stack0xfffffeac + iVar5) = 0x4fc0e8c0;
  bVar3 = GetPathPoints(*(char **)(&stack0xfffffeb0 + iVar5),*(uint **)(&stack0xfffffeb4 + iVar5),
                        *(float **)(&stack0xfffffeb8 + iVar5));
  if ((bVar3) && (1 < bufSize)) {
    uVar7 = 0;
    minVal = 3.4028235e+38;
    local_11c = (undefined1 *)0x7f7fffff;
    maxVal = -3.4028235e+38;
    local_124 = (undefined1 *)0xff7fffff;
    puVar9 = TempGrav;
    if (bufSize != 0) {
      do {
        fVar8 = *(float *)(TempGrav + uVar7 * 8);
        if (fVar8 < minVal) {
          minVal = fVar8;
        }
        puVar9 = *(undefined1 **)(TempGrav + uVar7 * 8 + 4);
        if ((float)puVar9 < (float)local_11c) {
          local_11c = puVar9;
        }
        if (maxVal < fVar8) {
          maxVal = fVar8;
        }
        if ((float)local_124 < (float)puVar9) {
          local_124 = puVar9;
        }
        uVar7 = uVar7 + 1;
      } while (uVar7 < bufSize);
    }
    TempGrav = puVar9;
    EdgePoints = minVal;
    local_134 = local_11c;
    local_130 = maxVal;
    local_12c = local_124;
  }
  if ((float)local_12c + local_130 + (float)local_134 + EdgePoints == 0.0) {
    fVar8 = (this->mapInfo).MapWidth * 0.5;
    (this->mapInfo).MaxWidth = fVar8;
    fVar2 = (this->mapInfo).MapDepth * 0.5;
    (this->mapInfo).MaxDepth = fVar2;
    (this->mapInfo).MinWidth = -fVar8;
    (this->mapInfo).MinDepth = -fVar2;
  }
  else {
    fVar8 = EdgePoints;
    if (EdgePoints < local_130) {
      fVar8 = local_130;
    }
    (this->mapInfo).MaxWidth = fVar8;
    puVar9 = local_134;
    if ((float)local_134 < (float)local_12c) {
      puVar9 = local_12c;
    }
    (this->mapInfo).MaxDepth = (float)puVar9;
    if (local_130 <= EdgePoints) {
      EdgePoints = local_130;
    }
    (this->mapInfo).MinWidth = EdgePoints;
    if ((float)local_12c <= (float)local_134) {
      local_134 = local_12c;
    }
    (this->mapInfo).MinDepth = (float)local_134;
  }
LAB_4fc0ea9d:
  if (local_112 == '\0') {
    iVar5 = IFace_GetInteger("options.instant.bool2");
    this->m_CPUUseDayWreckers = iVar5 != 0;
    iVar5 = IFace_GetInteger("options.instant.bool4");
    this->m_DamageMultiplier = 1.0;
    this->m_ScrapMultiplier = 1;
    this->m_UseSkillLevels = iVar5 != 0;
  }
  else {
    iVar5 = GetVarItemInt("network.session.ivar32");
    this->m_IsFriendlyFireOn = iVar5 != 0;
    iVar5 = GetVarItemInt("network.session.ivar60");
    this->m_MaxLives = iVar5;
    iVar5 = GetVarItemInt("network.session.ivar81");
    this->m_ScrapMultiplier = iVar5;
    m_GameType = GetVarItemInt("network.session.ivar5");
    iVar5 = GetVarItemInt("network.session.ivar26");
    TempGrav = (undefined1 *)(float)iVar5;
    if (10.0 <= (float)TempGrav) {
      if (100.0 < (float)TempGrav) {
        TempGrav = (undefined1 *)0x42c80000;
      }
    }
    else {
      TempGrav = (undefined1 *)0x41200000;
    }
    this->m_DamageMultiplier = (float)TempGrav / 10.0;
    iVar5 = GetVarItemInt("network.session.ivar89");
    this->m_CPUUseDayWreckers = iVar5 != 0;
    iVar5 = GetVarItemInt("network.session.ivar90");
    this->m_EnableSiteCamMP = iVar5 != 0;
    iVar5 = GetVarItemInt("network.session.ivar91");
    this->m_UseSkillLevels = iVar5 != 0;
    iVar5 = GetVarItemInt("network.session.ivar31");
    TempGrav = (undefined1 *)((float)iVar5 * 0.5);
    if (0.0 < (float)TempGrav) {
      (this->mapInfo).Gravity = (float)TempGrav;
      SetGravity((float)TempGrav);
    }
  }
  OffMapPos.x = -4000.0;
  OffMapPos.z = -4000.0;
  OffMapPos.y = TerrainFindFloor(-4000.0,-4000.0);
  SetupClouds(this,mapTrnFile);
  memset(MapName,0,0x80);
  if (local_112 == '\0') {
    pcVar4 = mapTrnFile;
  }
  else {
    pcVar4 = GetVarItemStr("network.session.svar0");
  }
  strcpy_s(MapName,0x80,pcVar4);
  pcVar4 = strrchr(MapName,0x2e);
  if (pcVar4 != (char *)0x0) {
    *pcVar4 = '\0';
  }
  if (Logging != false) {
    iVar5 = m_GameVersion;
    iVar6 = GetPlayerHandle();
    pcVar4 = GetPlayerName(iVar6);
    FormatLogMessage("Game Started on map: \'%s\' by %s. Version: %d\n",MapName,pcVar4,iVar5);
  }
  bVar3 = DoesFileExist("MPIVSRCheck.odf");
  if (((((((!bVar3) || (bVar3 = DoesFileExist("STvsrcheck.odf"), !bVar3)) ||
         ((bVar3 = DoesFileExist("aip_VSR.autoreg"), !bVar3 ||
          (((bVar3 = DoesFileExist("vsrbasesetup.cfg"), !bVar3 ||
            (bVar3 = DoesFileExist("vsra.txt"), !bVar3)) ||
           (bVar3 = DoesFileExist("evlegs_vsr.odf"), !bVar3)))))) ||
        ((bVar3 = DoesFileExist("BZCundep1.odf"), !bVar3 ||
         (bVar3 = DoesFileExist("BZCundep2.odf"), !bVar3)))) ||
       ((bVar3 = DoesFileExist("ivcamr_vsr.odf"), !bVar3 ||
        (((bVar3 = DoesFileExist("hbport_vsr.odf"), !bVar3 ||
          (bVar3 = DoesFileExist("evmine_vsr.odf"), !bVar3)) ||
         ((bVar3 = DoesFileExist("BZCNullCube.msh"), !bVar3 ||
          ((((bVar3 = DoesFileExist("apserv_vsr.odf"), !bVar3 ||
             (bVar3 = DoesFileExist("ivrbomb_vsr.inf"), !bVar3)) ||
            (bVar3 = DoesFileExist("vsr_bh_e_new_e6_0.aip"), !bVar3)) ||
           ((bVar3 = DoesFileExist("apvsrbldg.odf"), !bVar3 ||
            (bVar3 = DoesFileExist("iweapon_12svsr.odf"), !bVar3)))))))))))) ||
      (bVar3 = DoesFileExist("fweapon_12xvsr.odf"), !bVar3)) ||
     (((bVar3 = DoesFileExist("aplmg.inf"), !bVar3 ||
       (bVar3 = DoesFileExist("racename_e.txt"), !bVar3)) ||
      ((bVar3 = DoesFileExist("evscout00_s.dds"), !bVar3 ||
       (((bVar3 = DoesFileExist("evscav00_s.dds"), !bVar3 ||
         (bVar3 = DoesFileExist("evcons00_s.dds"), !bVar3)) ||
        (bVar3 = DoesFileExist("ivscout12smartvsr.odf"), !bVar3)))))))) {
    AddToMessagesBox2("-- Aborting!",0xffff0000);
    bVar3 = IsNetworkOn();
    if (bVar3) {
      NoteGameoverByNoBases();
      DoGameover(10.0);
    }
    else {
      TempGrav = (undefined1 *)(misnImport.time + 10.0);
      (*misnImport.FailMission)((float)TempGrav,"instantl.txt");
    }
  }
  this->m_DidInit = true;
  return;
}


// ---------------------------------------------------------------------
// BZ1Helper::Setup  @ 4fc0eec7  lines 1992-2025

void __thiscall BZ1Helper::Setup(BZ1Helper *this)

{
  Vector VVar1;
  Vector VVar2;
  Vector VVar3;
  Vector VVar4;
  Vector VVar5;
  Vector VVar6;
  bool bVar7;
  int *piVar8;
  int *piVar9;
  int *piVar10;
  int local_10;
  int local_8;
  
  this->m_DidSetup = true;
  OffMapPos.y = TerrainFindFloor(OffMapPos.x,OffMapPos.z);
  piVar9 = &this->teamInfo[0].ImaPilot;
  local_8 = 0x10;
  do {
    piVar10 = piVar9 + 2;
    piVar8 = piVar9 + -0xe;
    local_10 = 9;
    do {
      bVar7 = IsAround(*piVar8);
      if (bVar7) {
        VVar1.y = OffMapPos.y;
        VVar1.x = OffMapPos.x;
        VVar1.z = OffMapPos.z;
        SetVectorPosition(*piVar8,VVar1);
      }
      piVar8 = piVar8 + 1;
      local_10 = local_10 + -1;
    } while (local_10 != 0);
    local_10 = 3;
    do {
      bVar7 = IsAround(*piVar10);
      if (bVar7) {
        VVar2.y = OffMapPos.y;
        VVar2.x = OffMapPos.x;
        VVar2.z = OffMapPos.z;
        SetVectorPosition(*piVar10,VVar2);
      }
      piVar10 = piVar10 + 1;
      local_10 = local_10 + -1;
    } while (local_10 != 0);
    bVar7 = IsAround(*piVar9);
    if (bVar7) {
      VVar3.y = OffMapPos.y;
      VVar3.x = OffMapPos.x;
      VVar3.z = OffMapPos.z;
      SetVectorPosition(*piVar9,VVar3);
    }
    bVar7 = IsAround(piVar9[-4]);
    if (bVar7) {
      VVar4.y = OffMapPos.y;
      VVar4.x = OffMapPos.x;
      VVar4.z = OffMapPos.z;
      SetVectorPosition(piVar9[-4],VVar4);
    }
    bVar7 = IsAround(piVar9[-3]);
    if (bVar7) {
      VVar5.y = OffMapPos.y;
      VVar5.x = OffMapPos.x;
      VVar5.z = OffMapPos.z;
      SetVectorPosition(piVar9[-3],VVar5);
    }
    bVar7 = IsAround(piVar9[-2]);
    if (bVar7) {
      VVar6.y = OffMapPos.y;
      VVar6.x = OffMapPos.x;
      VVar6.z = OffMapPos.z;
      SetVectorPosition(piVar9[-2],VVar6);
    }
    piVar9 = piVar9 + 0x285;
    local_8 = local_8 + -1;
  } while (local_8 != 0);
  return;
}


// ---------------------------------------------------------------------
// BZ1Helper::Execute  @ 4fc0f04b  lines 2029-2432

void __thiscall BZ1Helper::Execute(BZ1Helper *this)

{
  int *piVar1;
  int iVar2;
  _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
  _Last;
  float fVar3;
  AlignTerrainReplaceClass *pAVar4;
  bool bVar5;
  bool bVar6;
  int iVar7;
  char *_Str1;
  BZ1Helper *extraout_ECX;
  BZ1Helper *extraout_ECX_00;
  BZ1Helper *extraout_ECX_01;
  ProductionClassHelper *this_00;
  BZ1Helper *extraout_ECX_02;
  AlignTerrainReplaceClass *pAVar8;
  DeploySoundClass *pDVar9;
  AlignTerrainReplaceClass *entry;
  DeploySoundClass *pDVar10;
  Vector *pVVar11;
  DispatchClass *entry_00;
  int iVar12;
  DeploySoundClass *pDVar13;
  int *piVar14;
  TeamInfo *pTVar15;
  size_t sVar16;
  AlignTerrainReplaceClass *entry_01;
  DeploySoundClass *pDVar17;
  _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
  _First;
  float10 fVar18;
  float fVar19;
  int local_24;
  BZ1Helper *teamNum;
  DeploySoundClass *local_1c;
  DeploySoundClass *pathNum;
  Vector label__TempH;
  
  teamNum = this;
  if (!GotPaths) {
    piVar14 = &this->AIpathCount;
    GetAiPaths(piVar14,&this->AIpathNames);
    iVar12 = 0;
    GotPaths = true;
    if (0 < *piVar14) {
      do {
        pDVar13 = (DeploySoundClass *)this->AIpathNames[iVar12];
        local_24 = 0;
        local_1c = (DeploySoundClass *)0x0;
        pathNum = pDVar13;
        iVar7 = sscanf_s((char *)pDVar13,"%dMLay%d",(int)&local_24,(int)&local_1c);
        if (iVar7 == 2) {
          iVar7 = local_24 + 0xd8e;
LAB_4fc0f0fe:
          std::vector<char_*,std::allocator<char_*>_>::push_back
                    ((vector<char_*,std::allocator<char_*>_> *)(&this->super_DLLBase + iVar7 * 3),
                     (char **)&pathNum);
        }
        else {
          iVar7 = sscanf_s((char *)pDVar13,"%dPatrol%d",(int)&local_24,(int)&local_1c);
          if (iVar7 == 2) {
            iVar7 = local_24 + 0xd9e;
            goto LAB_4fc0f0fe;
          }
        }
        iVar12 = iVar12 + 1;
      } while (iVar12 < *piVar14);
    }
  }
  if (this->m_DidInit == false) {
    Init(this);
  }
  if (this->m_DidSetup == false) {
    Setup(this);
  }
  m_TurnCounter = m_TurnCounter + 1;
  iVar12 = SecondsToTurns(60.0);
  if (m_TurnCounter < iVar12) {
    PetWatchdogThread();
  }
  pDVar13 = *(DeploySoundClass **)&(this->AlignTerrainReplaceList).field_0x4;
  pDVar10 = *(DeploySoundClass **)&this->AlignTerrainReplaceList;
  local_1c = pDVar13;
  while ((pDVar10 != pDVar13 &&
         (bVar5 = ShouldRemoveAlignTerrainReplace((AlignTerrainReplaceClass *)pDVar10), !bVar5))) {
    pDVar10 = (DeploySoundClass *)&pDVar10->RepeatDelay;
  }
  if (pDVar10 != pDVar13) {
    pAVar8 = (AlignTerrainReplaceClass *)&pDVar10->RepeatDelay;
    pDVar9 = pDVar10;
    pathNum = (DeploySoundClass *)pAVar8;
    if ((DeploySoundClass *)pAVar8 != pDVar13) {
      do {
        bVar5 = ShouldRemoveAlignTerrainReplace(pAVar8);
        pDVar9 = pDVar10;
        if (!bVar5) {
          pDVar9 = (DeploySoundClass *)&pDVar10->RepeatDelay;
          pDVar10->ObjectHandle = pAVar8->AlignHandle;
          ((Vector *)&pDVar10->DoesLoop)->x = (pAVar8->NormalVec).x;
          pDVar10->AudioHandle = (int)(pAVar8->NormalVec).y;
          pDVar10->StartDelay = (int)(pAVar8->NormalVec).z;
          pDVar13 = local_1c;
        }
        pAVar8 = pAVar8 + 1;
        this = teamNum;
        pDVar10 = pDVar9;
      } while ((DeploySoundClass *)pAVar8 != pDVar13);
    }
    if (pDVar9 != pDVar13) {
      sVar16 = *(int *)&(this->AlignTerrainReplaceList).field_0x4 - (int)pDVar13;
      memmove(pDVar9,pDVar13,sVar16);
      *(size_t *)&(this->AlignTerrainReplaceList).field_0x4 = sVar16 + (int)pDVar9;
    }
  }
  pAVar8 = *(AlignTerrainReplaceClass **)&(this->DeleteAfterDelayList).field_0x4;
  entry = *(AlignTerrainReplaceClass **)&this->DeleteAfterDelayList;
  while ((entry != pAVar8 && (bVar5 = ShouldRemoveAlignTerrainReplace(entry), !bVar5))) {
    entry = (AlignTerrainReplaceClass *)&(entry->NormalVec).y;
  }
  entry_01 = entry;
  if (entry != pAVar8) {
    while (pAVar4 = entry_01, entry_01 = (AlignTerrainReplaceClass *)&(pAVar4->NormalVec).y,
          entry_01 != pAVar8) {
      bVar5 = ShouldRemoveAlignTerrainReplace(entry_01);
      if (!bVar5) {
        entry->AlignHandle = (int)*(float *)entry_01;
        (entry->NormalVec).x = (pAVar4->NormalVec).z;
        entry = (AlignTerrainReplaceClass *)&(entry->NormalVec).y;
      }
    }
    if (entry != pAVar8) {
      sVar16 = *(int *)&(this->DeleteAfterDelayList).field_0x4 - (int)pAVar8;
      memmove(entry,pAVar8,sVar16);
      *(size_t *)&(this->DeleteAfterDelayList).field_0x4 = sVar16 + (int)entry;
    }
  }
  pDVar13 = *(DeploySoundClass **)&(this->DeploySoundList).field_0x4;
  pDVar10 = *(DeploySoundClass **)&this->DeploySoundList;
  local_1c = pDVar13;
  while ((pDVar10 != pDVar13 && (bVar5 = ShouldRemoveDeploySound(pDVar10), !bVar5))) {
    pDVar10 = pDVar10 + 1;
  }
  if (pDVar10 != pDVar13) {
    pDVar9 = pDVar10 + 1;
    pathNum = pDVar9;
    if (pDVar9 != pDVar13) {
      do {
        bVar5 = ShouldRemoveDeploySound(pDVar9);
        if (!bVar5) {
          pDVar13 = pDVar9;
          pDVar17 = pDVar10;
          for (iVar12 = 0x16; iVar12 != 0; iVar12 = iVar12 + -1) {
            pDVar17->ObjectHandle = pDVar13->ObjectHandle;
            pDVar13 = (DeploySoundClass *)&pDVar13->DoesLoop;
            pDVar17 = (DeploySoundClass *)&pDVar17->DoesLoop;
          }
          pDVar10 = pDVar10 + 1;
          pDVar13 = local_1c;
        }
        pDVar9 = pDVar9 + 1;
        this = teamNum;
      } while (pDVar9 != pDVar13);
    }
    if (pDVar10 != pDVar13) {
      sVar16 = *(int *)&(this->DeploySoundList).field_0x4 - (int)pDVar13;
      memmove(pDVar10,pDVar13,sVar16);
      *(char **)&(this->DeploySoundList).field_0x4 = (char *)(sVar16 + (int)pDVar10);
    }
  }
  pDVar13 = *(DeploySoundClass **)&(this->BuildAtList).field_0x4;
  pDVar10 = *(DeploySoundClass **)&this->BuildAtList;
  local_1c = pDVar13;
  while ((pDVar10 != pDVar13 && (bVar5 = ShouldRemoveBuildAt((BuildAtClass *)pDVar10), !bVar5))) {
    pDVar10 = (DeploySoundClass *)(pDVar10->DeploySound + 4);
  }
  if (pDVar10 != pDVar13) {
    pDVar9 = (DeploySoundClass *)(pDVar10->DeploySound + 4);
    pathNum = pDVar9;
    if (pDVar9 != pDVar13) {
      do {
        bVar5 = ShouldRemoveBuildAt((BuildAtClass *)pDVar9);
        if (!bVar5) {
          pDVar13 = pDVar9;
          pDVar17 = pDVar10;
          for (iVar12 = 7; iVar12 != 0; iVar12 = iVar12 + -1) {
            pDVar17->ObjectHandle = pDVar13->ObjectHandle;
            pDVar13 = (DeploySoundClass *)&pDVar13->DoesLoop;
            pDVar17 = (DeploySoundClass *)&pDVar17->DoesLoop;
          }
          pDVar10 = (DeploySoundClass *)(pDVar10->DeploySound + 4);
          pDVar13 = local_1c;
        }
        pDVar9 = (DeploySoundClass *)(pDVar9->DeploySound + 4);
        this = teamNum;
      } while (pDVar9 != pDVar13);
    }
    if (pDVar10 != pDVar13) {
      sVar16 = *(int *)&(this->BuildAtList).field_0x4 - (int)pDVar13;
      memmove(pDVar10,pDVar13,sVar16);
      *(char **)&(this->BuildAtList).field_0x4 = (char *)(sVar16 + (int)pDVar10);
    }
  }
  for (piVar14 = *(int **)&this->DeleteAfterDelayList;
      piVar14 != *(int **)&(this->DeleteAfterDelayList).field_0x4; piVar14 = piVar14 + 2) {
    piVar1 = piVar14 + 1;
    *piVar1 = *piVar1 + -1;
    if (*piVar1 < 0) {
      RemoveObject(*piVar14);
    }
  }
  piVar14 = *(int **)&this->DeploySoundList;
  if (piVar14 != *(int **)&(this->DeploySoundList).field_0x4) {
    do {
      if (piVar14[3] < 1) {
        if ((char)piVar14[1] == '\0') {
          StartAudio3D((char *)(piVar14 + 6),*piVar14,AUDIO_CAT_AMBIENT,false,false);
        }
        else {
          pathNum = (DeploySoundClass *)piVar14[2];
          bVar5 = IsAudioPlaying((int *)&pathNum);
          bVar6 = BuildingHelper::IsBuildingPowered(this->m_BuildingHelper,*piVar14);
          if (bVar6) {
            if (!bVar5) {
              if (piVar14[4] < 1) {
                iVar12 = StartAudio3D((char *)(piVar14 + 6),*piVar14,AUDIO_CAT_AMBIENT,true,false);
                piVar14[2] = iVar12;
                fVar19 = GetAudioFileDuration(iVar12);
                iVar12 = SecondsToTurns(fVar19);
                piVar14[5] = iVar12;
              }
              else {
                iVar12 = StartAudio3D((char *)(piVar14 + 6),*piVar14,AUDIO_CAT_AMBIENT,false,false);
                piVar14[2] = iVar12;
                fVar19 = GetAudioFileDuration(iVar12);
                iVar12 = SecondsToTurns(fVar19);
                piVar14[5] = iVar12;
                piVar14[3] = piVar14[4] + iVar12;
              }
            }
          }
          else if (bVar5) {
            StopAudio(piVar14[2]);
            piVar14[2] = 0;
          }
        }
      }
      else {
        piVar14[3] = piVar14[3] + -1;
      }
      piVar14 = piVar14 + 0x16;
    } while (piVar14 != *(int **)&(this->DeploySoundList).field_0x4);
  }
  piVar14 = *(int **)&this->BuildAtList;
  if (piVar14 != *(int **)&(this->BuildAtList).field_0x4) {
    pVVar11 = (Vector *)(piVar14 + 1);
    do {
      if (pVVar11[1].x == (float)m_TurnCounter) {
        fVar19 = pVVar11[1].z;
        if (fVar19 == 0.0) {
          fVar19 = pVVar11[1].y;
          iVar12 = 10;
        }
        else if (fVar19 == 1.4013e-45) {
          fVar19 = pVVar11[1].y;
          iVar12 = 0x22;
        }
        else {
          if (fVar19 != 2.8026e-45) goto LAB_4fc0f4a3;
          fVar19 = pVVar11[1].y;
          iVar12 = 8;
        }
        SetCommand(*piVar14,iVar12,(int)fVar19,0,pVVar11,0);
      }
LAB_4fc0f4a3:
      piVar14 = piVar14 + 7;
      pVVar11 = (Vector *)&pVVar11[2].y;
    } while (piVar14 != *(int **)&(this->BuildAtList).field_0x4);
  }
  iVar12 = 0;
  pTVar15 = this->teamInfo;
  do {
    bVar5 = IsPlayer(pTVar15->RealPlayer);
    if (((bVar5) && (iVar7 = GetTeamNum(pTVar15->RealPlayer), iVar7 != iVar12)) && (0 < iVar7)) {
      if (Logging != false) {
        FormatLogMessage("Switching Player TeamInfo from Team: %d to Team: %d",iVar12,iVar7);
      }
      iVar2 = this->teamInfo[iVar7].RealPlayer;
      this->teamInfo[iVar7].RealPlayer = pTVar15->RealPlayer;
      pTVar15->RealPlayer = iVar2;
      iVar2 = this->teamInfo[iVar7].PlayerLives;
      this->teamInfo[iVar7].PlayerLives = pTVar15->PlayerLives;
      pTVar15->PlayerLives = iVar2;
      bVar5 = this->teamInfo[iVar7].TeamIsDead;
      this->teamInfo[iVar7].TeamIsDead = pTVar15->TeamIsDead;
      pTVar15->TeamIsDead = bVar5;
    }
    iVar12 = iVar12 + 1;
    pTVar15 = pTVar15 + 1;
  } while (iVar12 < 0x10);
  pVVar11 = &this->teamInfo[0].PlayerSpawnPos;
  local_24 = 0;
  do {
    iVar12 = local_24;
    bVar5 = IsPlayer((int)pVVar11[-0x1c].z);
    if (!bVar5) {
      fVar19 = (float)GetPlayerHandle(iVar12);
      pVVar11[-0x1c].z = fVar19;
    }
    _Str1 = GetPlan(iVar12);
    if ((*_Str1 != '\0') && (iVar7 = _stricmp(_Str1,(char *)((int)&pVVar11[0xd].z + 1)), iVar7 != 0)
       ) {
      UpdateTeamAIP(this,_Str1,iVar12);
    }
    if (((*(char *)((int)&pVVar11[-5].y + 2) != '\0') &&
        (bVar5 = IsPerson((int)pVVar11[-0x1c].z), bVar5)) &&
       (bVar5 = IsNullVector(*pVVar11), iVar12 = local_24, !bVar5)) {
      GetPosition((int)pVVar11[-0x1c].z,&label__TempH);
      fVar19 = pVVar11->z - label__TempH.z;
      fVar3 = pVVar11->x - label__TempH.x;
      pathNum = (DeploySoundClass *)(fVar3 * fVar3 + fVar19 * fVar19);
      fVar18 = (float10)__CIsqrt();
      pathNum = (DeploySoundClass *)(float)fVar18;
      iVar12 = local_24;
      if (5.0 < (float)pathNum) {
        SetVectorPosition((int)pVVar11[-0x1c].z,*pVVar11);
        iVar12 = local_24;
      }
    }
    local_24 = iVar12 + 1;
    *(undefined1 *)((int)&pVVar11[-5].y + 3) = 0;
    pVVar11 = pVVar11 + 0xd7;
  } while (local_24 < 0x10);
  BZ1Interface(this);
  BZ1Lives(this);
  GravityHelper::Execute(this->m_GravityHelper,this);
  AmbientSoundHelper::Execute(this->m_AmbientSoundHelper,extraout_ECX);
  ObjectHelper::Execute(this->m_ObjectHelper,extraout_ECX_00,this->m_PortalHelper);
  VehicleHelper::Execute(this->m_VehicleHelper,this);
  PowerHelper::Execute(this->m_PowerHelper,this);
  PowerupHelper::Execute(this->m_PowerupHelper,extraout_ECX_01);
  BuildingHelper::Execute(this->m_BuildingHelper,this);
  ProductionClassHelper::Execute(this_00,this);
  UndeployHelper::Execute(this->m_UndeployHelper,this);
  UtilityShipHelper::Execute(this->m_UtilityShipHelper,this);
  PortalHelper::Execute(this->m_PortalHelper,extraout_ECX_02);
  AttacherHelper::Execute(this->m_AttacherHelper,this);
  pathNum = (DeploySoundClass *)this->m_ScrapHelper;
  _Last._Ptr = *(DispatchClass **)&pathNum->DoesLoop;
  _First._Ptr = *(DispatchClass **)&pathNum->ObjectHandle;
  while ((_First._Ptr != _Last._Ptr &&
         (bVar5 = ShouldRemoveAlignTerrainReplace((AlignTerrainReplaceClass *)_First._Ptr), !bVar5))
        ) {
    _First._Ptr = (DispatchClass *)&(_First._Ptr)->DispatchTarget;
  }
  entry_00 = _First._Ptr;
  if (_First._Ptr != _Last._Ptr) {
    while (entry_00 = (DispatchClass *)&entry_00->DispatchTarget, entry_00 != _Last._Ptr) {
      bVar5 = ShouldRemoveAlignTerrainReplace((AlignTerrainReplaceClass *)entry_00);
      if (!bVar5) {
        (_First._Ptr)->DispatchObject = *(int *)entry_00;
        _First._Ptr = (DispatchClass *)&(_First._Ptr)->DispatchTarget;
      }
    }
  }
  std::vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>::erase
            ((vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_> *
             )pathNum,_First,_Last);
  DispatchHelper::Execute(this->m_DispatchHelper,this);
  MorphObjectHelper::Execute(this->m_MorphObjectHelper,this);
  CarrierHelper::Execute(this->m_CarrierHelper,this);
  this->m_LastObjectListCount =
       (*(int *)&(this->m_ObjectHelper->HandleList).field_0x4 -
       *(int *)&this->m_ObjectHelper->HandleList) / 0x5c;
  return;
}


// ---------------------------------------------------------------------
// BZ1Helper::PreSnipe  @ 4fc0f75a  lines 2443-2525

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

PreSnipeReturnCodes __thiscall
BZ1Helper::PreSnipe(BZ1Helper *this,int curWorld,int shooterHandle,int victimHandle,int ordnanceTeam
                   ,char *pOrdnanceODF)

{
  bool bVar1;
  PreSnipeReturnCodes PVar2;
  int Team1;
  int iVar3;
  TEAMRELATIONSHIP TVar4;
  int local_cc;
  char *local_c8;
  byte local_c4 [64];
  char local_84 [64];
  char local_44 [64];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)&local_cc;
  local_c8 = pOrdnanceODF;
  if (curWorld == 0) {
    PVar2 = PRESNIPE_KILLPILOT;
    local_cc = 0;
    Team1 = GetTeamNum(victimHandle);
    if (ordnanceTeam == 0) {
      ordnanceTeam = GetTeamNum(shooterHandle);
    }
    memset(local_84,0,0x40);
    memset(local_c4,0,0x40);
    strcpy_s(local_84,0x40,local_c8);
    memset(local_44,0,0x40);
    bVar1 = OpenODF2(local_84);
    if ((bVar1) &&
       (iVar3 = GetODFString(local_84,"OrdnanceClass","classlabel",0x40,local_44,(char *)0x0),
       iVar3 != 0)) {
      CombineStrings((char *)local_c4,local_44,".odf",0x40);
      bVar1 = OpenODF2((char *)local_c4);
      local_c4[0] = local_c4[0] & -bVar1;
    }
    GetODFInt(local_84,(char *)local_c4,"SniperShellClass","TeamFilter",&local_cc,0);
    if ((ordnanceTeam == 0) || (local_cc == 0)) {
      local_cc = 7;
    }
    bVar1 = IsNetworkOn();
    if (((((bVar1) && (this->m_IsFriendlyFireOn == false)) &&
         (TVar4 = GetTeamRelationship(shooterHandle,victimHandle),
         TVar4 == TEAMRELATIONSHIP_ALLIEDTEAM)) &&
        ((bVar1 = IsPlayer(victimHandle), bVar1 || (Team1 != 0)))) ||
       (bVar1 = TeamFilterCheck(local_cc,Team1,ordnanceTeam), !bVar1)) {
      PVar2 = PRESNIPE_ONLYBULLETHIT;
    }
    else {
      SetPerceivedTeam(victimHandle,0);
      if ((victimHandle == this->teamInfo[Team1].Player) &&
         (iVar3 = GetPlayerHandle(Team1), iVar3 == this->teamInfo[Team1].SatellitePlayer)) {
        SetAsUser(this->teamInfo[Team1].Player,Team1);
      }
    }
  }
  else {
    PVar2 = PRESNIPE_ONLYBULLETHIT;
  }
  return PVar2;
}


// ---------------------------------------------------------------------
// BZ1Helper::PreOrdnanceHit  @ 4fc0f94b  lines 2533-2673

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall
BZ1Helper::PreOrdnanceHit
          (BZ1Helper *this,int shooterHandle,int victimHandle,int ordnanceTeam,char *pOrdnanceODF)

{
  bool bVar1;
  int iVar2;
  long lVar3;
  int extraout_EAX;
  uint uVar4;
  undefined1 auStack_d8 [3];
  bool local_d5;
  uint local_d4;
  float local_d0;
  int local_cc;
  char *local_c8;
  byte local_c4 [64];
  char local_84 [64];
  char local_44 [64];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)auStack_d8;
  local_c8 = pOrdnanceODF;
  if (victimHandle == 0) {
    return;
  }
  memset(local_84,0,0x40);
  memset(local_c4,0,0x40);
  strcpy_s(local_84,0x40,pOrdnanceODF);
  memset(local_44,0,0x40);
  bVar1 = OpenODF2(local_84);
  if ((bVar1) &&
     (iVar2 = GetODFString(local_84,"OrdnanceClass","classlabel",0x40,local_44,(char *)0x0),
     iVar2 != 0)) {
    CombineStrings((char *)local_c4,local_44,".odf",0x40);
    bVar1 = OpenODF2((char *)local_c4);
    local_c4[0] = local_c4[0] & -bVar1;
  }
  bVar1 = IsNetworkOn();
  if (((bVar1) && (m_GameType == 2)) && (1.0 < this->m_DamageMultiplier)) {
    iVar2 = _stricmp(local_44,"bouncebomb");
    if (iVar2 == 0) {
      local_cc = -1;
      GetODFInt(victimHandle,"GameObjectClass","allowMDMCollisionDetonation",&local_cc,-1);
      if ((local_cc == 0) || ((local_cc == -1 && (bVar1 = IsBuilding(victimHandle), bVar1))))
      goto LAB_4fc0fbb4;
    }
    else {
      iVar2 = _stricmp(local_44,"spraybomb");
      if (iVar2 == 0) {
        local_d5 = false;
        GetODFBool(local_84,(char *)local_c4,"SprayBombClass","ExplodeOnHit",&local_d5,false);
        if (local_d5 == false) goto LAB_4fc0fbb4;
        local_d4 = 0;
        GetODFInt(local_84,(char *)local_c4,"SprayBombClass","HitExplodeTypes",(int *)&local_d4,0);
        if (local_d4 != 0) {
          bVar1 = IsBuilding(victimHandle);
          uVar4 = (uint)bVar1;
          bVar1 = IsCraftButNotPerson(victimHandle);
          if (bVar1) {
            uVar4 = uVar4 | 2;
          }
          bVar1 = IsPerson(victimHandle);
          if (bVar1) {
            uVar4 = uVar4 | 4;
          }
          if (uVar4 == 0) {
            uVar4 = 8;
          }
          if ((local_d4 & uVar4) == 0) goto LAB_4fc0fbb4;
        }
      }
    }
    lVar3 = GetOrdnanceDamageDealt(victimHandle,local_c8,false);
    local_d0 = (float)lVar3;
    _ftol2_sse();
    local_d0 = (float)(extraout_EAX - lVar3);
    iVar2 = GetCurWorld();
    if (iVar2 == 0) {
      Damage(victimHandle,shooterHandle,(long)local_d0);
    }
  }
LAB_4fc0fbb4:
  local_d4 = GetTeamNum(victimHandle);
  iVar2 = ordnanceTeam;
  if (ordnanceTeam == 0) {
    iVar2 = GetTeamNum(shooterHandle);
  }
  bVar1 = IsTeamAllied(local_d4,iVar2);
  if (!bVar1) {
    iVar2 = GetPlayerHandle(local_d4);
    if (iVar2 == 0) {
      (**(code **)(this->m_DispatchHelper->vfptr + 4))
                (shooterHandle,victimHandle,ordnanceTeam,local_c8);
    }
    (**(code **)(this->m_CarrierHelper->vfptr + 4))
              (shooterHandle,victimHandle,ordnanceTeam,local_c8);
  }
  return;
}


// ---------------------------------------------------------------------
// BZ1Helper::PreGetIn  @ 4fc0fc31  lines 2677-2705

PreGetInReturnCodes __thiscall
BZ1Helper::PreGetIn(BZ1Helper *this,int curWorld,int pilotHandle,int emptyCraftHandle)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  if (curWorld == 0) {
    iVar1 = GetTeamNum(pilotHandle);
    iVar2 = GetTeamNum(emptyCraftHandle);
    if (iVar2 != iVar1) {
      iVar4 = 0;
      piVar3 = *(int **)&this->m_ObjectHelper->HandleList;
      iVar2 = (*(int *)&(this->m_ObjectHelper->HandleList).field_0x4 - (int)piVar3) / 0x5c;
      if (0 < iVar2) {
        do {
          if (*piVar3 == emptyCraftHandle) {
            piVar3[6] = iVar1;
            break;
          }
          iVar4 = iVar4 + 1;
          piVar3 = piVar3 + 0x17;
        } while (iVar4 < iVar2);
      }
    }
    iVar1 = GetPlayerHandle(iVar1);
    if (iVar1 != 0) {
      SetCommand(emptyCraftHandle,0,0,0,(char *)0x0,0);
    }
  }
  return PREGETIN_ALLOW;
}


// ---------------------------------------------------------------------
// BZ1Helper::PrePickupPowerup  @ 4fc0fca9  lines 2709-2951

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

PrePickupPowerupReturnCodes __thiscall
BZ1Helper::PrePickupPowerup(BZ1Helper *this,int curWorld,int me,int powerupHandle)

{
  bool bVar1;
  uint uVar2;
  PrePickupPowerupReturnCodes PVar3;
  uint unaff_ESI;
  char *unaff_EDI;
  char local_c4 [64];
  char local_84 [64];
  char local_44 [64];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)local_c4;
  if (curWorld == 0) {
    memset(local_44,0,0x40);
    bVar1 = GetObjInfo(powerupHandle,Get_ODF,local_44);
    if (bVar1) {
      memset(local_84,0,0x40);
      bVar1 = GetObjInfo(me,Get_ODF,local_84);
      if (bVar1) {
        memset(local_c4,0,0x40);
        bVar1 = GetObjInfo(powerupHandle,Get_GOClass,local_c4);
        if ((bVar1) &&
           ((uVar2 = Hash(unaff_EDI,unaff_ESI), uVar2 == 0xa662aa60 || (uVar2 == 0x33fe0a68)))) {
          PVar3 = (**(code **)(this->m_MorphObjectHelper->vfptr + 4))
                            (0,me,powerupHandle,uVar2,local_84);
          return PVar3;
        }
      }
    }
  }
  return PREPICKUPPOWERUP_ALLOW;
}


// ---------------------------------------------------------------------
// BZ1Helper::PostTeleport  @ 4fc0fda5  lines 2955-2965

PostTeleportReturnCodes __thiscall
BZ1Helper::PostTeleport(BZ1Helper *this,int portalHandle,int shipHandle)

{
  return PostTeleport_DEFAULT;
}


// ---------------------------------------------------------------------
// BZ1Helper::DeadObject  @ 4fc0fdaa  lines 2969-2971

void __thiscall BZ1Helper::DeadObject(BZ1Helper *this,int DeadObjectHandle)

{
  PortalHelper *pPVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  
  pPVar1 = this->m_PortalHelper;
  piVar5 = *(int **)&pPVar1->PortalList;
  if (piVar5 != *(int **)&(pPVar1->PortalList).field_0x4) {
    do {
      if (*piVar5 == DeadObjectHandle) {
        iVar3 = GetTeamNum(*piVar5);
        iVar4 = GetLocalPlayerTeamNumber();
        bVar2 = IsTeamAllied(iVar4,iVar3);
        if (!bVar2) {
          return;
        }
        SetObjectiveName(*piVar5,(char *)(piVar5 + 0x43));
        return;
      }
      piVar5 = piVar5 + 0xe4;
    } while (piVar5 != *(int **)&(pPVar1->PortalList).field_0x4);
  }
  return;
}


// ---------------------------------------------------------------------
// BZ1Helper::BZ1Interface  @ 4fc0fdfc  lines 2975-3144

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall BZ1Helper::BZ1Interface(BZ1Helper *this)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  code *pcVar5;
  int iVar6;
  float fVar7;
  char *_Format;
  int local_70;
  int local_6c;
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  DLLBase *local_58;
  int local_54;
  char local_50 [64];
  char local_10 [12];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)&local_70;
  iVar3 = GetPlayerHandle();
  if (iVar3 != 0) {
    iVar3 = GetTeamNum(iVar3);
    local_60 = GetCommanderTeam(iVar3);
    iVar3 = IFace_GetInteger("script.dll.escape.active");
    iVar4 = IFace_GetInteger("script.dll.repeataudio");
    if (iVar4 != 0) {
      if (((iVar3 == 0) && (bVar2 = IsAudioMessageDone(this->MissionAudioHandle), bVar2)) &&
         (this->MissionAudioFile[0] != 0)) {
        iVar4 = AudioMessage((char *)this->MissionAudioFile,false);
        this->MissionAudioHandle = iVar4;
      }
      IFace_SetInteger("script.dll.repeataudio",0);
    }
    if (((0 < this->m_MaxLives) && (iVar3 == 0)) &&
       ((iVar3 = GetLocalPlayerTeamNumber(), this->teamInfo[iVar3].TeamIsDead != false &&
        (iVar3 = GetLocalPlayerTeamNumber(), this->teamInfo[iVar3].RespawnPlayer == false)))) {
      IFace_ConsoleCmd("mission.escape",true);
    }
    memset(local_50,0,0x40);
    iVar3 = 0;
    do {
      iVar3 = iVar3 + 1;
      sprintf_s<64>(&local_50,"script.dll.pilotcost%d",iVar3);
      IFace_SetString(local_50,"");
    } while (iVar3 < 10);
    local_64 = 0;
    local_68 = 1;
    local_6c = 0x23a;
    pcVar5 = IFace_SetFloat_exref;
    iVar3 = local_60;
    do {
      iVar4 = local_68;
      local_70 = GetObjectByBaseSlot(iVar3,local_68);
      if (local_70 != 0) {
        sprintf_s<64>(&local_50,"script.dll.base%dhull",iVar4);
        fVar7 = GetHealth(local_70);
        (*pcVar5)(local_50,fVar7);
        sprintf_s<64>(&local_50,"script.dll.basename%d",iVar4);
        IFace_SetString(local_50,this->teamInfo[iVar3].BaseSlotName[0] + local_64);
        iVar4 = local_68;
        local_58 = &this->super_DLLBase + iVar3 * 0x285;
        if (((*(char *)((int)(local_58 + 0x293) + local_68 + 3) != '\0') &&
            (bVar2 = IsBuilding(local_70), bVar2)) &&
           (bVar2 = IsSelected(local_70), iVar1 = local_70, bVar2)) {
          local_54 = iVar3 * 0x285;
          local_5c = local_6c + -0x5a + local_54;
          iVar6 = 0;
          do {
            local_70 = iVar6 + 1;
            sprintf_s<64>(&local_50,"script.dll.pilotcost%d",local_70);
            if ((&this->super_DLLBase)[local_5c + iVar6] == (DLLBase)0x1) {
              IFace_SetString(local_50,"P");
            }
            else if (1 < (int)(&this->super_DLLBase)[local_5c + iVar6]) {
              local_10[0] = '\0';
              local_10[1] = '\0';
              local_10[2] = '\0';
              local_10[3] = '\0';
              local_10[4] = '\0';
              local_10[5] = '\0';
              local_10[6] = '\0';
              local_10[7] = '\0';
              local_10[8] = '\0';
              local_10[9] = '\0';
              _snprintf_s<10>((char (*) [10])local_10,0xffffffff,"%d",
                              (int)(&this->super_DLLBase)[local_5c + iVar6]);
              IFace_SetString(local_50,local_10);
              iVar3 = local_60;
            }
            if (((*(int *)(local_58 + 0x49) < (int)(&this->super_DLLBase)[local_5c + iVar6]) ||
                (iVar4 = (*misnImport.GetScrap)(iVar3),
                iVar4 < (int)(&this->super_DLLBase)[local_6c + local_54 + iVar6])) ||
               (bVar2 = IsBusy(iVar1), bVar2)) {
              sprintf_s<64>(&local_50,"CommandPanel.Command%d.Item.Cost.PilotCost",local_70);
              if (iVar6 == 9) {
                sprintf_s<64>(&local_50,"CommandPanel.Command0.Item.Cost.PilotCost");
              }
              IFace_Deactivate(local_50);
              sprintf_s<64>(&local_50,"CommandPanel.Command%d.Item.Cost.PilotCostDisabled",local_70)
              ;
              if (iVar6 == 9) {
                _Format = "CommandPanel.Command0.Item.Cost.PilotCostDisabled";
                goto LAB_4fc10153;
              }
            }
            else {
              sprintf_s<64>(&local_50,"CommandPanel.Command%d.Item.Cost.PilotCostDisabled",local_70)
              ;
              if (iVar6 == 9) {
                sprintf_s<64>(&local_50,"CommandPanel.Command0.Item.Cost.PilotCostDisabled");
              }
              IFace_Deactivate(local_50);
              sprintf_s<64>(&local_50,"CommandPanel.Command%d.Item.Cost.PilotCost",local_70);
              if (iVar6 == 9) {
                _Format = "CommandPanel.Command0.Item.Cost.PilotCost";
LAB_4fc10153:
                sprintf_s<64>(&local_50,_Format);
              }
            }
            IFace_Activate(local_50);
            pcVar5 = IFace_SetFloat_exref;
            iVar4 = local_68;
            iVar6 = local_70;
          } while (local_70 < 10);
        }
      }
      local_64 = local_64 + 0x40;
      local_68 = iVar4 + 1;
      local_6c = local_6c + 10;
    } while (local_68 < 10);
    if (this->teamInfo[iVar3].m_UsePilots == false) {
      iVar3 = GetPower(iVar3);
      IFace_SetInteger("script.dll.currpilots",iVar3);
      iVar3 = GetMaxPower(local_60);
      IFace_SetInteger("script.dll.maxpilots",iVar3);
      IFace_SetString("script.dll.pilotname","Power");
    }
    else {
      IFace_SetInteger("script.dll.currpilots",this->teamInfo[iVar3].CurrPilots);
      IFace_SetInteger("script.dll.maxpilots",this->teamInfo[iVar3].MaxPilots);
      IFace_SetString("script.dll.pilotname","Pilot");
    }
    if (HullGaugeSet == false) {
      (*pcVar5)("script.dll.hull2",0);
    }
    else {
      (*pcVar5)("script.dll.hull2",HullGauge2);
      HullGaugeSet = false;
    }
    if (AmmoGaugeSet == false) {
      (*pcVar5)("script.dll.ammo2",0);
    }
    else {
      (*pcVar5)("script.dll.ammo2",AmmoGauge2);
      AmmoGaugeSet = false;
    }
    if (AuxGaugeSet == false) {
      (*pcVar5)("script.dll.gauge",0);
    }
    else {
      (*pcVar5)("script.dll.gauge",AuxGauge);
      AuxGaugeSet = false;
    }
    if (CloakGaugeSet == false) {
      (*pcVar5)("script.dll.cloak",0);
    }
    else {
      (*pcVar5)("script.dll.cloak",CloakGauge);
      CloakGaugeSet = false;
    }
  }
  return;
}


// ---------------------------------------------------------------------
// BZ1Helper::BZ1Lives  @ 4fc102f5  lines 3148-3222

void __thiscall BZ1Helper::BZ1Lives(BZ1Helper *this)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int local_18;
  
  PlayDeathCamera(this);
  piVar5 = &this->teamInfo[0].PlayerLives;
  iVar4 = 0;
  do {
    if (*(bool *)((int)piVar5 + 0x39) != false) {
      iVar6 = *(int *)&this->m_ObjectHelper->HandleList;
      iVar2 = (*(int *)&(this->m_ObjectHelper->HandleList).field_0x4 - iVar6) / 0x5c;
      if (*piVar5 < 1) {
        local_18 = 0;
        if (0 < iVar2) {
          iVar2 = 0;
          do {
            if ((*(int *)(iVar2 + 0x1c + iVar6) == iVar4) &&
               (bVar1 = IsPlayer(*(int *)(iVar2 + iVar6)), !bVar1)) {
              bVar1 = IsTeamplayOn();
              if (bVar1) {
                iVar3 = GetCommanderTeam(iVar4);
                if (iVar4 == iVar3) {
                  iVar3 = 0xf;
                }
                SetTeamNum(*(int *)(iVar2 + iVar6),iVar3);
              }
              else {
                iVar3 = 0xf;
                SetTeamNum(*(int *)(iVar2 + iVar6),0xf);
              }
              *(int *)(iVar2 + 0x1c + iVar6) = iVar3;
              Stop(*(int *)(iVar2 + iVar6),0);
              SetBestGroup(*(int *)(iVar2 + iVar6));
            }
            local_18 = local_18 + 1;
            iVar2 = iVar2 + 0x5c;
            iVar6 = *(int *)&this->m_ObjectHelper->HandleList;
          } while (local_18 < (*(int *)&(this->m_ObjectHelper->HandleList).field_0x4 - iVar6) / 0x5c
                  );
        }
      }
      else {
        local_18 = 0;
        if (0 < iVar2) {
          iVar2 = 0;
          do {
            if (((*(int *)(iVar2 + 0x1c + iVar6) == 0xf) &&
                (*(int *)(iVar2 + 0x18 + iVar6) == iVar4)) &&
               (bVar1 = IsPlayer(*(int *)(iVar2 + iVar6)), !bVar1)) {
              SetTeamNum(*(int *)(iVar2 + iVar6),iVar4);
              *(int *)(iVar2 + 0x1c + iVar6) = iVar4;
            }
            Stop(*(int *)(iVar2 + iVar6),0);
            iVar2 = iVar2 + 0x5c;
            local_18 = local_18 + 1;
            iVar6 = *(int *)&this->m_ObjectHelper->HandleList;
          } while (local_18 < (*(int *)&(this->m_ObjectHelper->HandleList).field_0x4 - iVar6) / 0x5c
                  );
        }
      }
    }
    iVar4 = iVar4 + 1;
    piVar5 = piVar5 + 0x285;
  } while (iVar4 < 0x10);
  return;
}


// ---------------------------------------------------------------------
// BZ1Helper::ClearDeathCamera  @ 4fc104a0  lines 3252-3263

void __thiscall BZ1Helper::ClearDeathCamera(BZ1Helper *this)

{
  if (DeathCameraOn) {
    DeathCameraTime = 0;
    DeathCameraTeam = -1;
    DeathCameraOn = false;
                    /* WARNING: Could not recover jumptable at 0x4fc104be. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    CameraFinish();
    return;
  }
  return;
}


// ---------------------------------------------------------------------
// BZ1Helper::PlayDeathCamera  @ 4fc104c5  lines 3267-3291

bool __thiscall BZ1Helper::PlayDeathCamera(BZ1Helper *this)

{
  Vector Offset;
  bool bVar1;
  int me;
  BZ1Helper *this_00;
  Vector local_18;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  bVar1 = IsNetworkOn();
  if ((((bVar1) && (0 < DeathCameraTeam)) &&
      (me = GetPlayerHandle(DeathCameraTeam), DeathCameraOn != false)) &&
     ((bVar1 = IsAround(me), bVar1 && (0 < DeathCameraTeam)))) {
    local_18.x = 0.0;
    local_18.y = 0.0;
    local_18.z = 0.0;
    SetVelocity(me,&local_18);
    local_18.x = 0.0;
    local_18.y = 0.0;
    local_18.z = 0.0;
    SetOmega(me,&local_18);
    local_18.y = 0.0;
    local_18.z = 0.0;
    local_c = 0x41200000;
    local_8 = 0x41200000;
    local_4 = 0x41200000;
    local_18.x = 10.0;
    Offset.z = 10.0;
    Offset.x = 10.0;
    Offset.y = 10.0;
    bVar1 = CameraCircle(me,Offset,me,&local_18);
    if ((bVar1) || (DeathCameraTime < m_TurnCounter)) {
      bVar1 = IsNetworkOn();
      if (bVar1) {
        ClearDeathCamera(this_00);
      }
      return true;
    }
  }
  return false;
}


// ---------------------------------------------------------------------
// BZ1Helper::SetupClouds  @ 4fc105c7  lines 3392-3586

/* WARNING: Function: _chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall BZ1Helper::SetupClouds(BZ1Helper *this,char *mapTrnFile)

{
  int iVar1;
  char *pcVar2;
  float extraout_EAX;
  int fmtarg3;
  int iVar3;
  float *pfVar4;
  Matrix *pMVar5;
  float unaff_EDI;
  int iVar6;
  Matrix *pMVar7;
  float10 fVar8;
  float fVar9;
  float fVar10;
  float local_42c0;
  char local_42b9;
  char *local_42b8;
  char *local_42b4;
  double local_42b0;
  undefined4 local_42a8;
  undefined8 local_42a0;
  undefined4 local_4298;
  double local_4290;
  undefined4 local_4288;
  double local_4280;
  undefined4 local_4278;
  int local_4270;
  int local_426c;
  Matrix local_4268;
  int local_4228;
  int local_4224;
  int local_4220;
  int local_421c;
  float local_4218 [16];
  float local_41d8;
  float local_41d4;
  char *local_41d0;
  float local_41cc;
  float local_41c8 [16];
  float local_4188 [16];
  char local_4148 [16384];
  Matrix local_148 [4];
  char local_48 [68];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)&local_42c0;
  local_42b0 = (double)CONCAT44(local_42b0._4_4_,this);
  memset(&local_4228,0,0x40e0);
  GetODFInt(mapTrnFile,"Clouds","Type",&local_4228,0);
  GetODFInt(mapTrnFile,"Clouds","Count",&local_4220,0);
  if (local_4220 < 0) {
    local_4220 = 0;
  }
  else if (0x40 < local_4220) {
    local_4220 = 0x40;
  }
  GetODFInt(mapTrnFile,"Clouds","TileSize",&local_421c,0);
  memset(local_48,0,0x40);
  pcVar2 = local_4148;
  iVar6 = 1;
  pfVar4 = local_4218;
  do {
    local_42c0 = 0.0;
    local_42b9 = '\0';
    local_42b8 = pcVar2;
    local_42b4 = pcVar2;
    do {
      local_42c0 = (float)((int)local_42c0 + 1);
      sprintf_s<64>((char (*) [64])local_48,"Name%d_%d",iVar6,(int)local_42c0);
      iVar1 = GetODFString(mapTrnFile,"Clouds",local_48,0x40,local_42b8,(char *)0x0);
      if (iVar1 == 0) {
        sprintf_s<64>((char (*) [64])local_48,"Name%d",iVar6);
        iVar1 = GetODFString(mapTrnFile,"Clouds",local_48,0x40,pcVar2,pcVar2);
        if (iVar1 == 0) break;
      }
      else {
        *pfVar4 = (float)((int)*pfVar4 + 1);
      }
      local_42b8 = local_42b8 + 0x40;
      local_42b9 = '\x01';
    } while ((int)local_42c0 < 0x10);
    if (local_42b9 == '\0') break;
    local_4224 = local_4224 + 1;
    sprintf_s<64>((char (*) [64])local_48,"Height%d",iVar6);
    GetODFFloat(mapTrnFile,"Clouds",local_48,pfVar4 + 0x24,100.0);
    sprintf_s<64>((char (*) [64])local_48,"Team%d",iVar6);
    GetODFInt(mapTrnFile,"Clouds",local_48,(int *)(pfVar4 + 0x14),0);
    pcVar2 = local_42b4 + 0x400;
    pfVar4 = pfVar4 + 1;
    iVar6 = iVar6 + 1;
    local_42b4 = pcVar2;
  } while (iVar6 < 0x11);
  iVar6 = (int)local_42b0._0_4_;
  local_42a0 = (double)local_421c;
  fVar9 = *(float *)((int)local_42b0._0_4_ + 0x68) / (float)local_421c;
  local_42c0 = fVar9;
  floor(unaff_EDI);
  fVar10 = *(float *)(iVar6 + 0x70) / (float)local_42a0;
  local_42c0 = fVar10;
  local_42b0._0_4_ = fVar9;
  floor(unaff_EDI);
  local_42c0 = fVar10;
  _ftol2_sse();
  fVar9 = *(float *)(iVar6 + 100) / (float)local_42a0;
  local_42c0 = fVar9;
  local_42b8 = (char *)extraout_EAX;
  floor(unaff_EDI);
  fVar10 = *(float *)(iVar6 + 0x6c) / (float)local_42a0;
  local_42c0 = fVar10;
  local_42b0._0_4_ = fVar9;
  floor(unaff_EDI);
  local_42c0 = fVar10;
  _ftol2_sse();
  iVar1 = fmtarg3 * (int)extraout_EAX * local_4224 * local_4220;
  if (0x400 < iVar1) {
    iVar3 = (iVar1 + -0x400) / (int)local_42b8;
    local_42b0 = (double)CONCAT44(local_42b0._4_4_,iVar3);
    local_42c0 = (float)(iVar3 / fmtarg3);
    local_426c = (int)local_42c0 / local_4224;
    if (Logging != false) {
      FormatLogMessage("Total Clouds: %d, TileCountX: %d, TileCountZ: %d, Difference: %d, DiffX: %d DiffZ: %d, DiffType: %d"
                       ,iVar1,(int)local_42b8,fmtarg3,iVar1 + -0x400,iVar3,(int)local_42c0,
                       local_426c);
    }
    local_4220 = local_4220 - local_426c;
    FormatLogMessage("ERROR: Too many Clouds: (%d > %d), Count Per Tile: %d. Correcting to: %d, %d Per Tile."
                     ,iVar1,0x400,local_4224,local_4220 * fmtarg3 * (int)extraout_EAX * local_4224,
                     local_4220);
  }
  local_42b0 = (double)*(float *)(iVar6 + 0x68);
  local_4290 = (double)*(float *)(iVar6 + 0x70);
  local_4280 = (double)((*(float *)(iVar6 + 0x6c) + *(float *)(iVar6 + 100)) * 0.5);
  local_42a0 = (double)local_421c;
  local_42c0 = (*(float *)(iVar6 + 100) - *(float *)(iVar6 + 0x6c)) / (float)local_421c;
  fVar8 = floor((double)local_42c0);
  fVar8 = (float10)(float)((float10)(float)fVar8 * (float10)local_42a0) * (float10)0.5;
  local_41d0 = (char *)(float)((float10)local_4280 - fVar8);
  local_41d8 = (float)((float10)local_4280 + fVar8);
  local_4280 = (double)(float)(((float10)local_4290 + (float10)local_42b0) * (float10)0.5);
  local_42c0 = (float)(((float10)local_42b0 - (float10)local_4290) / (float10)local_42a0);
  fVar8 = floor((double)local_42c0);
  local_42c0 = (float)fVar8 * (float)local_42a0;
  local_4278 = 0;
  local_42a0 = 0.0;
  local_4288 = 0;
  local_41d4 = (float)local_4280;
  local_4280 = 0.0;
  local_41cc = local_41d4 - local_42c0 * 0.5;
  local_42a8 = 0;
  local_4298 = 0x3f800000;
  local_4290 = 0.0078125;
  local_42b0 = 5.26354424712089e-315;
  local_41d4 = local_41d4 + local_42c0 * 0.5;
  Matrix::Matrix(local_148,(Vector)ZEXT812(0x3f800000),(Vector)ZEXT812(0x3f80000000000000),
                 (Vector)(ZEXT412(0x3f800000) << 0x40),(Vector)ZEXT412(0));
  local_4280 = 0.0;
  local_4278 = 0;
  local_4298 = 0;
  local_4288 = 0;
  local_42a0 = 1.58735232019473e-314;
  local_42b0 = 0.0;
  local_4290 = 0.0078125;
  local_42a8 = 0x3f800000;
  Matrix::Matrix(local_148 + 1,(Vector)(ZEXT412(0x3f800000) << 0x40),
                 (Vector)ZEXT812(0x3f80000000000000),(Vector)ZEXT812(0xbf800000),(Vector)ZEXT412(0))
  ;
  local_4280 = 0.0;
  local_4278 = 0;
  local_42a0 = 0.0;
  local_4288 = 0;
  local_42a8 = 0;
  local_4298 = 0xbf800000;
  local_4290 = 0.0078125;
  local_42b0 = 1.58735232019473e-314;
  Matrix::Matrix(local_148 + 2,(Vector)ZEXT812(0xbf800000),(Vector)ZEXT812(0x3f80000000000000),
                 (Vector)(ZEXT412(0xbf800000) << 0x40),(Vector)ZEXT412(0));
  local_4280 = 0.0;
  local_4278 = 0;
  local_4298 = 0;
  local_4288 = 0;
  local_42a0._4_4_ = 0;
  local_42a0._0_4_ = 1.0;
  local_42b0 = 0.0;
  local_4290 = 0.0078125;
  local_42a8 = 0xbf800000;
  Matrix::Matrix(local_148 + 3,(Vector)(ZEXT412(0xbf800000) << 0x40),
                 (Vector)ZEXT812(0x3f80000000000000),(Vector)ZEXT812(0x3f800000),(Vector)ZEXT412(0))
  ;
  iVar1 = 0;
  local_4270 = 0;
  local_42b0 = (double)((ulonglong)local_42b0 & 0xffffffff00000000);
  if (0 < local_4224) {
    pfVar4 = local_4188;
    local_42c0 = 0.0;
    iVar3 = local_4224;
    fVar9 = local_41d8;
    do {
      local_42b4 = local_41d0;
      fVar10 = local_42c0;
      if ((float)local_41d0 <= fVar9) {
        do {
          local_42b8 = (char *)local_41cc;
          if (local_41cc <= local_41d4) {
            do {
              local_426c = 0;
              if (0 < local_4220) {
                do {
                  local_42a0._0_4_ = (float)GetRandomInt(0,(int)pfVar4[-0x24] + -1);
                  if (Logging != false) {
                    FormatLogMessage("Placing Cloud: Random is: %d Cloud ODF is: \'%s\'",
                                     (int)(float)local_42a0,
                                     local_4148 + ((int)fVar10 + (int)(float)local_42a0) * 0x40);
                  }
                  iVar3 = GetRandomInt(0,3);
                  fVar9 = (float)local_421c;
                  pMVar5 = local_148 + iVar3;
                  pMVar7 = &local_4268;
                  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
                    (pMVar7->right).x = (pMVar5->right).x;
                    pMVar5 = (Matrix *)&(pMVar5->right).y;
                    pMVar7 = (Matrix *)&(pMVar7->right).y;
                  }
                  fVar10 = GetRandomFloat(fVar9);
                  fVar9 = (float)local_421c;
                  local_4268.posit.x = (fVar10 + (float)local_42b4) - fVar9 * 0.5;
                  local_4280 = (double)(float)local_42b8;
                  local_4290._0_4_ = fVar9;
                  fVar9 = GetRandomFloat(fVar9);
                  local_4290 = (double)CONCAT44(local_4290._4_4_,(float)local_421c);
                  local_4268.posit.z = (fVar9 + (float)local_4280) - (float)local_421c * 0.5;
                  if (local_4228 == 0) {
                    local_4268.posit.y = *pfVar4;
                  }
                  else {
                    local_4268.posit.y = TerrainFindFloor(local_4268.posit.x,local_4268.posit.z);
                    local_4268.posit.y = local_4268.posit.y + *pfVar4;
                  }
                  fVar10 = local_42c0;
                  fVar9 = pfVar4[-0x10];
                  *(undefined1 *)(iVar6 + 0xa269) = 1;
                  BuildObject(local_4148 + ((int)(float)local_42a0 + (int)local_42c0) * 0x40,
                              (int)fVar9,&local_4268);
                  local_4270 = local_4270 + 1;
                  local_426c = local_426c + 1;
                  *(undefined1 *)(iVar6 + 0xa269) = 0;
                } while (local_426c < local_4220);
                local_42b8 = (char *)(float)local_4280;
              }
              local_42a0._0_4_ = (float)local_421c;
              local_42b8 = (char *)((float)local_42b8 + (float)local_42a0);
            } while ((float)local_42b8 <= local_41d4);
          }
          local_42a0._0_4_ = (float)local_421c;
          local_42b4 = (char *)((float)local_42b4 + (float)local_42a0);
        } while ((float)local_42b4 <= local_41d8);
        iVar1 = (int)local_42b0._0_4_;
        iVar3 = local_4224;
        fVar9 = local_41d8;
      }
      iVar1 = iVar1 + 1;
      local_42c0 = (float)((int)fVar10 + 0x10);
      pfVar4 = pfVar4 + 1;
      local_42b0 = (double)CONCAT44(local_42b0._4_4_,iVar1);
    } while (iVar1 < iVar3);
  }
  iVar1 = local_4270;
  if (Logging != false) {
    FormatLogMessage("Map Width Is: %f",
                     (double)CONCAT44(unaff_EDI,
                                      (int)((ulonglong)(double)*(float *)(iVar6 + 0x4c) >> 0x20)));
    FormatLogMessage("Map Depth Is: %f",
                     (double)CONCAT44(unaff_EDI,
                                      (int)((ulonglong)(double)*(float *)(iVar6 + 0x50) >> 0x20)));
    FormatLogMessage("Clouds Specified Are: %d",local_4224);
    FormatLogMessage("Cloud Count Per Type is: %d",local_4220);
    FormatLogMessage("Cloud Type Count is: %d",local_4224);
    FormatLogMessage("Total Clouds are: %d",iVar1);
  }
  return;
}


// ---------------------------------------------------------------------
// BZ1Helper::SetAIPFile  @ 4fc10f10  lines 3698-3712

bool __thiscall BZ1Helper::SetAIPFile(BZ1Helper *this,char *Value,int Team)

{
  bool bVar1;
  int Team_00;
  
  if ((uint)Team < 0x10) {
    Team_00 = 2;
    if (Team != -1) {
      Team_00 = Team;
    }
    SetPlan(Value,Team_00);
    bVar1 = UpdateTeamAIP(this,Value,Team_00);
  }
  else {
    bVar1 = false;
  }
  return bVar1;
}


// ---------------------------------------------------------------------
// BZ1Helper::UpdateTeamAIP  @ 4fc10f49  lines 3714-3749

bool __thiscall BZ1Helper::UpdateTeamAIP(BZ1Helper *this,char *AIPFile,int Team)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  float *pfVar4;
  
  bVar1 = OpenODF2(AIPFile);
  if (bVar1) {
    strcpy_s(this->teamInfo[Team].TeamAIPFile,0x100,AIPFile);
    GetODFInt(AIPFile,"Cheat","pilotAmount",&this->teamInfo[Team].m_CPUPilotCheatAmount,0);
    GetODFFloat(AIPFile,"Cheat","pilotDelay",&this->teamInfo[Team].m_CPUPilotCheatDelay,15.0);
    GetODFInt(AIPFile,"Start","Difficulty",&this->teamInfo[Team].m_CPUAIDifficulty,0);
    piVar3 = &this->teamInfo[Team].m_CPUAIDifficulty;
    iVar2 = *piVar3;
    if (iVar2 < 0) {
      iVar2 = 0;
    }
    else if (4 < iVar2) {
      iVar2 = 4;
    }
    *piVar3 = iVar2;
    GetODFBool(AIPFile,"Start","UnitsService",&this->teamInfo[Team].m_CPUUnitsCanService,false);
    GetODFBool(AIPFile,"IdleDispatcher","DoDLLDispatch",&this->teamInfo[Team].m_CPUDoDispatch,true);
    GetODFInt(AIPFile,"IdleDispatcher","MaxPatrolUnits",&this->teamInfo[Team].m_CPUMaxPatrolUnits,0)
    ;
    GetODFInt(AIPFile,"IdleDispatcher","MaxHuntUnits",&this->teamInfo[Team].m_CPUMaxHuntUnits,0);
    GetODFInt(AIPFile,"IdleDispatcher","MaxEscortUnits",&this->teamInfo[Team].m_CPUMaxEscortUnits,0)
    ;
    GetODFFloat(AIPFile,"Start","BuildingRepairChance",
                &this->teamInfo[Team].m_CPUBuildingRepairChance,0.8);
    GetODFFloat(AIPFile,"Start","BuildingRepairInterval",
                &this->teamInfo[Team].m_CPUBuildingRepairInterval,30.0);
    GetODFFloat(AIPFile,"Start","BuildingRepairHealthRatio",
                &this->teamInfo[Team].m_CPUBuildingRepairHealthRatio,0.5);
    GetODFFloat(AIPFile,"Start","BuildPodMinDelay",&this->teamInfo[Team].m_CPUBuildPodMinDelay,5.0);
    GetODFFloat(AIPFile,"Start","BuildPodMaxDelay",&this->teamInfo[Team].m_CPUBuildPodMaxDelay,60.0)
    ;
    if (this->m_CPUUseDayWreckers != false) {
      GetODFFloat(AIPFile,"Start","DayWreckerChance",&this->teamInfo[Team].m_CPUDayWreckerChance,0.0
                 );
      pfVar4 = &this->teamInfo[Team].m_CPUDayWreckerInterval;
      GetODFFloat(AIPFile,"Start","DayWreckerInterval",pfVar4,30.0);
      if (*pfVar4 <= 0.0) {
        *pfVar4 = 1.0;
      }
    }
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  return bVar1;
}


// ---------------------------------------------------------------------
// BZ1Helper::AddToDispatch  @ 4fc11199  lines 3752-3754

bool __thiscall
BZ1Helper::AddToDispatch
          (BZ1Helper *this,int h,float IdleTime,bool SkipAIPCheck,int CloakPriority,bool CanFlee,
          bool CloakNow,bool Hunt,bool CanGetService)

{
  bool bVar1;
  
  bVar1 = DispatchHelper::AddToDispatch
                    (this->m_DispatchHelper,h,IdleTime,SkipAIPCheck,CloakPriority,CanFlee,CloakNow,
                     Hunt,CanGetService);
  return bVar1;
}


// ---------------------------------------------------------------------
// BZ1Helper::DeleteAfterDelay  @ 4fc111c4  lines 4019-4035

void __thiscall BZ1Helper::DeleteAfterDelay(BZ1Helper *this,int h,float Delay)

{
  vector<BZ1Helper::DeleteAfterDelayClass,std::allocator<BZ1Helper::DeleteAfterDelayClass>_>
  *_Udefault_or_fill;
  int iVar1;
  bool bVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  
  bVar2 = IsAround(h);
  if (bVar2) {
    _Udefault_or_fill = &this->DeleteAfterDelayList;
    for (piVar3 = *(int **)_Udefault_or_fill;
        piVar3 != *(int **)&(this->DeleteAfterDelayList).field_0x4; piVar3 = piVar3 + 2) {
      if (*piVar3 == h) {
        return;
      }
    }
    std::vector<BZ1Helper::DeleteAfterDelayClass,std::allocator<BZ1Helper::DeleteAfterDelayClass>_>
    ::_Resize<<lambda_4cef8f5d2e224a10ec5594e33bb09482>_>
              (_Udefault_or_fill,
               (*(int *)&(this->DeleteAfterDelayList).field_0x4 - *(int *)_Udefault_or_fill >> 3) +
               1,(<lambda_4cef8f5d2e224a10ec5594e33bb09482>)_Udefault_or_fill);
    iVar1 = *(int *)_Udefault_or_fill;
    iVar5 = *(int *)&(this->DeleteAfterDelayList).field_0x4 - iVar1 >> 3;
    *(undefined4 *)(iVar1 + -8 + iVar5 * 8) = 0;
    *(undefined4 *)(iVar1 + -4 + iVar5 * 8) = 0;
    *(int *)(iVar1 + -8 + iVar5 * 8) = h;
    iVar4 = SecondsToTurns(Delay);
    *(int *)(iVar1 + -4 + iVar5 * 8) = iVar4;
  }
  return;
}


// ---------------------------------------------------------------------
// BZ1Helper::GetRandomObject  @ 4fc11237  lines 4039-4102

int __thiscall
BZ1Helper::GetRandomObject
          (BZ1Helper *this,int param_1,int param_2,bool param_3,int param_4,bool param_5,
          bool param_6,bool param_7,int param_8,char *param_9,char *param_10,float param_11,
          Vector param_12)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int Team2;
  int TeamFilter;
  int *piVar5;
  int Max;
  float fVar6;
  
  TeamFilter = -1;
  if (param_2 != 0) {
    TeamFilter = param_2;
  }
  Max = this->m_LastObjectListCount + -1;
  if (Max < 0) {
    Max = 0;
  }
  else {
    iVar3 = (*(int *)&(this->m_ObjectHelper->HandleList).field_0x4 -
            *(int *)&this->m_ObjectHelper->HandleList) / 0x5c + -1;
    if (iVar3 < Max) {
      Max = iVar3;
    }
  }
  iVar4 = GetRandomInt(0,Max);
  iVar3 = iVar4;
  do {
    piVar5 = (int *)(iVar3 * 0x5c + *(int *)&this->m_ObjectHelper->HandleList);
    iVar1 = *piVar5;
    if (param_1 < 0) {
LAB_4fc112cc:
      if ((((0 < piVar5[0x15]) && ((!param_7 || (*(char *)((int)piVar5 + 0x17) != '\0')))) &&
          ((param_11 <= 0.0 ||
           (fVar6 = GetDistance3DSquared((Vector *)(piVar5 + 0x12),&param_12),
           fVar6 < param_11 * param_11)))) && (piVar5[4] != 0)) {
        return iVar1;
      }
    }
    else {
      if (param_3) {
        Team2 = piVar5[8];
      }
      else {
        Team2 = piVar5[7];
      }
      bVar2 = TeamFilterCheck(TeamFilter,param_1,Team2);
      if (bVar2) goto LAB_4fc112cc;
    }
    iVar1 = iVar3 + 1;
    iVar3 = 0;
    if (iVar1 <= Max) {
      iVar3 = iVar1;
    }
    if (iVar3 == iVar4) {
      return 0;
    }
  } while( true );
}


// ---------------------------------------------------------------------
// BZ1Helper::GetNearestObject  @ 4fc11323  lines 4163-4221

int __thiscall
BZ1Helper::GetNearestObject
          (BZ1Helper *this,Vector param_1,float param_2,int param_3,int param_4,bool param_5,
          int param_6,bool param_7,bool param_8,int param_9,int param_10,char *param_11,
          char *param_12)

{
  bool bVar1;
  uint uVar2;
  int TeamFilter;
  int Team2;
  int iVar3;
  uint uVar4;
  uint unaff_ESI;
  int iVar5;
  char *unaff_EDI;
  int iVar6;
  float fVar7;
  uint local_10;
  
  uVar2 = 0xffffffff;
  if (param_6 != 0) {
    uVar2 = param_6;
  }
  TeamFilter = -1;
  if (param_4 != 0) {
    TeamFilter = param_4;
  }
  uVar4 = 0xffffffff;
  if (param_10 != 0) {
    uVar4 = param_10;
  }
  local_10 = 0;
  param_6 = 0;
  if (param_11 != (char *)0x0) {
    local_10 = Hash(unaff_EDI,unaff_ESI);
  }
  iVar3 = 0;
  if (0.0 < param_2) {
    param_4 = (int)(param_2 * param_2);
  }
  else {
    param_4 = 0x7f7fffff;
  }
  param_10 = 0;
  iVar5 = *(int *)&this->m_ObjectHelper->HandleList;
  if (0 < (*(int *)&(this->m_ObjectHelper->HandleList).field_0x4 - iVar5) / 0x5c) {
    iVar6 = 0;
    do {
      if ((param_9 == 0) || (param_9 != *(int *)(iVar6 + iVar5))) {
        iVar3 = param_6;
        if (-1 < param_3) {
          if (param_5) {
            Team2 = *(int *)(iVar6 + 0x20 + iVar5);
          }
          else {
            Team2 = *(int *)(iVar6 + 0x1c + iVar5);
          }
          bVar1 = TeamFilterCheck(TeamFilter,param_3,Team2);
          if (!bVar1) goto LAB_4fc1145e;
        }
        if (((0 < *(int *)(iVar6 + 0x54 + iVar5)) &&
            ((((uVar4 & 1) != 0 && ((*(uint *)(iVar6 + 0x10 + iVar5) & uVar2) != 0)) ||
             (((uVar4 & 2) != 0 &&
              ((param_11 != (char *)0x0 && (*(uint *)(iVar6 + 8 + iVar5) == local_10)))))))) &&
           (fVar7 = GetDistance3DSquared((Vector *)(iVar5 + 0x48 + iVar6),&param_1),
           fVar7 < (float)param_4)) {
          param_6 = *(int *)(iVar6 + iVar5);
          iVar3 = param_6;
          param_4 = (int)fVar7;
        }
      }
LAB_4fc1145e:
      iVar6 = iVar6 + 0x5c;
      param_10 = param_10 + 1;
      iVar5 = *(int *)&this->m_ObjectHelper->HandleList;
    } while (param_10 < (*(int *)&(this->m_ObjectHelper->HandleList).field_0x4 - iVar5) / 0x5c);
  }
  return iVar3;
}


// ---------------------------------------------------------------------
// BZ1Helper::GetNearestObject  @ 4fc11490  lines 4232-4237

int __thiscall
BZ1Helper::GetNearestObject
          (BZ1Helper *this,int param_1,float param_2,int param_3,int param_4,bool param_5,
          int param_6,bool param_7,bool param_8,int param_9,char *param_10,char *param_11)

{
  Vector VVar1;
  bool bVar2;
  int iVar3;
  Vector *pVVar4;
  Vector local_10;
  
  bVar2 = IsAround(param_1);
  if (bVar2) {
    pVVar4 = &local_10;
    iVar3 = param_1;
    GetPosition(param_1,pVVar4);
    VVar1.y = local_10.y;
    VVar1.x = local_10.x;
    VVar1.z = local_10.z;
    iVar3 = GetNearestObject(this,VVar1,param_2,param_3,param_4,param_5,param_6,SUB41(iVar3,0),
                             SUB41(iVar3,0),param_1,param_9,param_10,(char *)pVVar4);
  }
  else {
    iVar3 = 0;
  }
  return iVar3;
}


// ---------------------------------------------------------------------
// BZ1Helper::BuildAt  @ 4fc114f2  lines 4734-4767

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall
BZ1Helper::BuildAt(BZ1Helper *this,int param_1,char *param_2,Vector param_3,int param_4)

{
  vector<BZ1Helper::BuildAtClass,std::allocator<BZ1Helper::BuildAtClass>_> *_Udefault_or_fill;
  int iVar1;
  bool bVar2;
  int *piVar3;
  uint uVar4;
  uint unaff_ESI;
  char *unaff_EDI;
  float *pfVar5;
  int local_4c;
  char *local_48;
  char local_44 [64];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)&local_4c;
  local_48 = param_2;
  bVar2 = IsAround(param_1);
  if ((bVar2) && (bVar2 = DoesODFExist(param_2), bVar2)) {
    _Udefault_or_fill = &this->BuildAtList;
    for (piVar3 = *(int **)_Udefault_or_fill; piVar3 != *(int **)&(this->BuildAtList).field_0x4;
        piVar3 = piVar3 + 7) {
      if (*piVar3 == param_1) {
        return;
      }
    }
    std::vector<BZ1Helper::BuildAtClass,std::allocator<BZ1Helper::BuildAtClass>_>::
    _Resize<<lambda_dee307eb94beae9268b6d89c62f4c357>_>
              (_Udefault_or_fill,
               (*(int *)&(this->BuildAtList).field_0x4 - *(int *)_Udefault_or_fill) / 0x1c + 1,
               (<lambda_dee307eb94beae9268b6d89c62f4c357>)_Udefault_or_fill);
    iVar1 = *(int *)_Udefault_or_fill;
    local_4c = ((*(int *)&(this->BuildAtList).field_0x4 - iVar1) / 0x1c) * 0x1c;
    pfVar5 = (float *)(iVar1 + -0x18 + local_4c);
    *(undefined4 *)(local_4c + -0x18 + iVar1) = 0;
    *(undefined4 *)(local_4c + -0x14 + iVar1) = 0;
    *(undefined4 *)(local_4c + -0x10 + iVar1) = 0;
    *(undefined4 *)(local_4c + -0xc + iVar1) = 0;
    *(undefined4 *)(local_4c + -8 + iVar1) = 0;
    *(undefined4 *)(local_4c + -4 + iVar1) = 0;
    *(int *)(local_4c + -0x1c + iVar1) = param_1;
    *(int *)(local_4c + -0xc + iVar1) = m_TurnCounter + 1;
    *pfVar5 = param_3.x;
    pfVar5[1] = param_3.y;
    pfVar5[2] = param_3.z;
    *(undefined4 *)(local_4c + -8 + iVar1) = 1;
    memset(local_44,0,0x40);
    GetObjInfo(param_1,Get_GOClass,local_44);
    uVar4 = Hash(unaff_EDI,unaff_ESI);
    if ((uVar4 == 0x8a0a1ead) || (uVar4 == 0xe39ee1ae)) {
      *(undefined4 *)(local_4c + -4 + iVar1) = 1;
    }
    else if (uVar4 == 0x63ae241a) {
      *(undefined4 *)(local_4c + -4 + iVar1) = 2;
    }
    Build(param_1,local_48,1);
  }
  return;
}


// ---------------------------------------------------------------------
// BZ1Helper::CheckBuildRequirements  @ 4fc11627  lines 4770-4972

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool __thiscall
BZ1Helper::CheckBuildRequirements
          (BZ1Helper *this,char *param_1,int param_2,bool param_3,bool param_4,bool param_5)

{
  bool bVar1;
  int iVar2;
  char *pcVar3;
  char **extraout_ECX;
  char *pcVar4;
  int local_c8;
  byte local_c4 [64];
  char local_84 [64];
  char local_44 [64];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)&local_c8;
  if (param_1 != (char *)0x0) {
    memset(local_84,0,0x40);
    memset(local_c4,0,0x40);
    pcVar4 = param_1;
    do {
      pcVar3 = pcVar4;
      pcVar4 = pcVar3 + 1;
    } while (*pcVar3 != '\0');
    iVar2 = _stricmp(pcVar3 + -4,".odf");
    if (iVar2 == 0) {
      pcVar4 = "";
    }
    else {
      pcVar4 = param_1;
      param_1 = ".odf";
    }
    CombineStrings(local_84,pcVar4,param_1,0x40);
    bVar1 = OpenODF2(local_84);
    if (bVar1) {
      memset(local_44,0,0x40);
      iVar2 = GetODFString(local_84,"GameObjectClass","classlabel",0x40,local_44,(char *)0x0);
      if (iVar2 != 0) {
        CombineStrings((char *)local_c4,local_44,".odf",0x40);
        bVar1 = OpenODF2((char *)local_c4);
        local_c4[0] = local_c4[0] & -bVar1;
      }
      if (!param_3) {
        local_c8 = 0;
        GetODFInt(local_84,(char *)local_c4,"GameObjectClass","scrapCost",&local_c8,0);
        iVar2 = (*misnImport.GetScrap)(param_2);
        if (iVar2 - local_c8 < 0) {
          return false;
        }
      }
      iVar2 = CheckBuildRequirements_PowerCost(param_2,local_84,(char *)local_c4);
      if (-1 < iVar2) {
        local_c8 = 0;
        GetODFInt(local_84,(char *)local_c4,"GameObjectClass","pilotCost",&local_c8,0);
        if ((local_c8 <= this->teamInfo[param_2].CurrPilots) &&
           (iVar2 = CheckBuildRequirements_RequireCount
                              (this,extraout_ECX,param_2,local_84,(char *)local_c4), iVar2 < 1)) {
          return true;
        }
      }
    }
  }
  return false;
}


// ---------------------------------------------------------------------
// BZ1Helper::CheckBuildRequirements_RequireCount  @ 4fc117e4  lines 4976-5067

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __thiscall
BZ1Helper::CheckBuildRequirements_RequireCount
          (BZ1Helper *this,char **param_1,int param_2,char *param_3,char *param_4)

{
  int iVar1;
  int iVar2;
  char *_Str2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_120;
  int local_11c;
  int local_118;
  int local_114;
  BZ1Helper *local_110;
  char *local_10c;
  char *local_108;
  char local_104 [64];
  char local_c4 [64];
  char local_84 [64];
  char local_44 [64];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)&local_120;
  iVar5 = 0;
  local_114 = 0;
  local_10c = param_3;
  local_108 = param_4;
  local_110 = this;
  iVar1 = GetODFInt(param_3,param_4,"GameObjectClass","requireCount",&local_114,0);
  if ((iVar1 != 0) && (iVar1 = 0, 0 < local_114)) {
    do {
      memset(local_c4,0,0x40);
      memset(local_84,0,0x40);
      iVar1 = iVar1 + 1;
      sprintf_s<64>(&local_84,"requireName%d",iVar1);
      iVar2 = GetODFString(param_3,param_4,"GameObjectClass",local_84,0x40,local_c4,(char *)0x0);
      if (iVar2 != 0) {
        local_118 = 0;
        iVar2 = *(int *)&local_110->m_ObjectHelper->HandleList;
        if (0 < (*(int *)&(local_110->m_ObjectHelper->HandleList).field_0x4 - iVar2) / 0x5c) {
          local_11c = 0;
          do {
            iVar4 = local_11c;
            if (*(int *)(local_11c + 0x1c + iVar2) == param_2) {
              iVar2 = *(int *)(local_11c + iVar2);
              _Str2 = GetODFName(iVar2);
              if ((_Str2 != (char *)0x0) && (iVar3 = _stricmp(local_c4,_Str2), iVar3 == 0))
              goto LAB_4fc11a14;
              memset(local_104,0,0x40);
              GetODFString(iVar2,"GameObjectClass","baseName",0x40,local_104,(char *)0x0);
              if (local_104[0] == '\0') {
                local_120 = 0;
                GetODFInt(iVar2,"GameObjectClass","provideCount",&local_120,0);
                iVar3 = 0;
                iVar4 = local_11c;
                if (0 < local_120) {
                  do {
                    memset(local_44,0,0x40);
                    iVar3 = iVar3 + 1;
                    sprintf_s<64>(&local_44,"provideName%d",iVar3);
                    GetODFString(iVar2,"GameObjectClass",local_44,0x40,local_104,(char *)0x0);
                    iVar4 = _stricmp(local_c4,local_104);
                    if (iVar4 == 0) goto LAB_4fc11a14;
                    iVar4 = local_11c;
                  } while (iVar3 < local_120);
                }
              }
              else {
                iVar2 = _stricmp(local_c4,local_104);
                if (iVar2 == 0) goto LAB_4fc11a14;
              }
            }
            local_11c = iVar4 + 0x5c;
            local_118 = local_118 + 1;
            iVar2 = *(int *)&local_110->m_ObjectHelper->HandleList;
          } while (local_118 <
                   (*(int *)&(local_110->m_ObjectHelper->HandleList).field_0x4 - iVar2) / 0x5c);
        }
      }
      iVar5 = iVar5 + 1;
LAB_4fc11a14:
      param_3 = local_10c;
      param_4 = local_108;
    } while (iVar1 < local_114);
  }
  return iVar5;
}


// ---------------------------------------------------------------------
// BZ1Helper::ReplaceObject  @ 4fc11a43  lines 5071-5248

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __thiscall
BZ1Helper::ReplaceObject
          (BZ1Helper *this,int H,char *ODF,int Team,float HeightOffset,int Empty,bool RestoreWeapons
          ,int Group,int CanSnipe,bool KeepCommand,int NewCommand,int Priority,int NewWho,
          Vector NewWhere)

{
  int *piVar1;
  bool bVar2;
  int iVar3;
  char *pcVar4;
  Vector *pVVar5;
  long extraout_EAX;
  int extraout_EAX_00;
  int extraout_ECX;
  undefined4 unaff_ESI;
  int iVar6;
  Matrix *pMVar7;
  undefined4 unaff_EDI;
  Matrix *pMVar8;
  float fVar9;
  undefined1 uVar10;
  undefined1 uVar11;
  undefined1 auStack_550 [7];
  bool bStack_549;
  BZ1Helper *local_548;
  float fStack_544;
  float fStack_540;
  Vector VStack_53c;
  Vector VStack_530;
  Vector VStack_524;
  Matrix MStack_518;
  int local_4d8;
  int iStack_4d4;
  int iStack_4d0;
  int aiStack_4cc [8];
  char local_4ac [64];
  char acStack_46c [256];
  char acStack_36c [256];
  char acStack_26c [64];
  int iStack_22c;
  int iStack_228;
  float fStack_214;
  float fStack_210;
  char acStack_20c [320];
  float afStack_cc [5];
  long lStack_b8;
  Matrix MStack_ac;
  Vector VStack_6c;
  Vector VStack_60;
  char cStack_54;
  float fStack_4c;
  int iStack_48;
  int iStack_44;
  int iStack_40;
  byte bStack_3c;
  AiCommand AStack_38;
  Vector VStack_34;
  char cStack_28;
  float fStack_24;
  float fStack_20;
  char cStack_1c;
  int iStack_18;
  int iStack_14;
  int iStack_10;
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)auStack_550;
  local_548 = this;
  bVar2 = IsAround(H);
  if (!bVar2) {
    return 0;
  }
  memset(&local_4d8,0,0x4d0);
  if (ODF == (char *)0x0) {
    GetODFName(H,local_4ac);
  }
  else {
    CombineStrings(local_4ac,"",ODF,0x40);
    GetWorldVariantODF(local_4ac);
  }
  local_4d8 = (*misnImport.GetTug)(H);
  iStack_4d4 = GetTarget(H);
  iStack_4d0 = GetCurrentWho(H);
  iVar6 = 0;
  do {
    iVar3 = GetTap(H,iVar6);
    aiStack_4cc[iVar6] = iVar3;
    iVar6 = iVar6 + 1;
  } while (iVar6 < 8);
  pcVar4 = GetLabel(H);
  CombineStrings(acStack_46c,"",pcVar4,0x100);
  pcVar4 = GetObjectiveName(H);
  CombineStrings(acStack_36c,"",pcVar4,0x100);
  pcVar4 = GetPilotConfig(H);
  if (pcVar4 != (char *)0x0) {
    CombineStrings(acStack_26c,"",pcVar4,0x40);
  }
  if (Team < 0) {
    Team = GetTeamNum(H);
  }
  iStack_22c = Team;
  iStack_228 = GetPerceivedTeam(H);
  fStack_214 = GetHealth(H);
  fStack_210 = GetAmmo(H);
  iVar6 = 0;
  pcVar4 = acStack_20c;
  do {
    fVar9 = GetCurLocalAmmo(H,iVar6);
    afStack_cc[iVar6] = fVar9;
    GetObjInfo(H,iVar6 + Get_Weapon0Config,pcVar4);
    uVar11 = (undefined1)unaff_ESI;
    uVar10 = (undefined1)unaff_EDI;
    pcVar4 = pcVar4 + 0x40;
    iVar6 = iVar6 + 1;
  } while (iVar6 < 5);
  lStack_b8 = GetWeaponMask(H);
  iVar6 = GetScavengerMaxScrap(H);
  if (iVar6 < 1) {
    fStack_20 = -1.0;
  }
  else {
    iVar3 = GetScavengerCurScrap(H);
    fStack_20 = (float)(iVar3 / iVar6);
  }
  GetPosition(H,&MStack_518);
  pMVar7 = &MStack_518;
  pMVar8 = &MStack_ac;
  for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
    (pMVar8->right).x = (pMVar7->right).x;
    pMVar7 = (Matrix *)&(pMVar7->right).y;
    pMVar8 = (Matrix *)&(pMVar8->right).y;
  }
  pVVar5 = GetVelocity(&VStack_53c,H);
  VStack_6c.x = pVVar5->x;
  VStack_6c.y = pVVar5->y;
  VStack_6c.z = pVVar5->z;
  pVVar5 = GetOmega(&VStack_530,H);
  VStack_60.x = pVVar5->x;
  VStack_60.y = pVVar5->y;
  VStack_60.z = pVVar5->z;
  cStack_54 = IsDeployed(H);
  fStack_4c = GetRemainingLifespan(H);
  iStack_48 = GetIndependence(H);
  iStack_44 = GetSkill(H);
  if (Group < 0) {
    iStack_40 = GetGroup(H);
  }
  else {
    iStack_40 = Group;
  }
  if (CanSnipe < 0) {
    bVar2 = GetCanSnipe(H);
    CanSnipe = (int)bVar2;
  }
  bStack_3c = CanSnipe != 0;
  AStack_38 = GetCurrentCommand(H);
  if (((AStack_38 == CMD_GO) || (AStack_38 == CMD_DEPLOY)) || (AStack_38 - CMD_GET_IN < 2)) {
    pVVar5 = GetCurrentCommandWhere(&VStack_524,H);
    VStack_34.x = pVVar5->x;
    VStack_34.y = pVVar5->y;
    VStack_34.z = pVVar5->z;
  }
  cStack_28 = IsPlayer(H);
  fStack_24 = GetEjectRatio(H);
  pcVar4 = GetODFName(H);
  iStack_18 = GetScrapValue(pcVar4);
  iStack_14 = GetPilotCost(local_4ac);
  iStack_10 = GetTapCount(extraout_ECX,(bool)uVar10,(bool)uVar11);
  if (Empty < 0) {
    bVar2 = IsEmpty(H);
    Empty = (int)bVar2;
  }
  cStack_1c = Empty != 0;
  if (HeightOffset != 0.0) {
    MStack_ac.posit.y = MStack_ac.posit.y + HeightOffset;
  }
  bVar2 = DoesODFExist(local_4ac);
  if (!bVar2) {
    FormatLogMessage("ERROR: ReplaceODF \'%s\' doesn\'t exist! Fix DLLs!",local_4ac);
    return H;
  }
  if ((cStack_1c == '\0') && (1 < m_TurnCounter)) {
    piVar1 = &local_548->teamInfo[iStack_22c].CurrPilots;
    *piVar1 = *piVar1 + iStack_14;
  }
  bStack_549 = true;
  iVar6 = GetODFBool(H,"PoweredBuildingClass","DestroyTapsWithParent",&bStack_549,true);
  if (iVar6 == 0) {
    GetODFBool(H,"TurretCraftClass","DestroyTapsWithParent",&bStack_549,true);
  }
  RemoveObject(H);
  iVar6 = BuildObject(local_4ac,iStack_22c,&MStack_ac);
  if (local_4d8 != 0) {
    Pickup(local_4d8,iVar6,1);
  }
  if (iStack_4d4 != 0) {
    SetTarget(iVar6,iStack_4d4);
  }
  if ((bStack_549 == false) && (iVar3 = 0, 0 < iStack_10)) {
    do {
      SetTap(iVar6,iVar3,aiStack_4cc[iVar3]);
      iVar3 = iVar3 + 1;
    } while (iVar3 < iStack_10);
  }
  SetLabel(iVar6,acStack_46c);
  if ((acStack_26c[0] != '\0') && (bVar2 = DoesODFExist(acStack_26c), bVar2)) {
    SetPilotClass(iVar6,acStack_26c);
  }
  SetObjectiveName(iVar6,acStack_36c);
  SetPerceivedTeam(iVar6,iStack_228);
  local_548 = (BZ1Helper *)fStack_214;
  fStack_544 = (float)GetMaxHealth(iVar6);
  if (fStack_544 != -NAN) {
    if (0.0 <= (float)local_548) {
      if (1.0 < (float)local_548) {
        local_548 = (BZ1Helper *)0x3f800000;
      }
    }
    else {
      local_548 = (BZ1Helper *)0x0;
    }
    fStack_544 = (float)(int)fStack_544;
    _ftol2_sse();
    SetCurHealth(iVar6,extraout_EAX);
  }
  SetAmmo(iVar6,fStack_210);
  if (RestoreWeapons) {
    ReplaceWeapons(iVar6,(char (*) [64])acStack_20c,afStack_cc,local_4ac);
  }
  SetWeaponMask(iVar6,lStack_b8);
  fStack_544 = fStack_20;
  fStack_540 = (float)GetScavengerMaxScrap(iVar6);
  if (0 < (int)fStack_540) {
    if (0.0 <= fStack_544) {
      if (fStack_544 <= 1.0) {
        local_548 = (BZ1Helper *)fStack_544;
      }
      else {
        local_548 = (BZ1Helper *)0x3f800000;
      }
    }
    else {
      local_548 = (BZ1Helper *)0x0;
    }
    fStack_540 = (float)(int)fStack_540;
    _ftol2_sse();
    SetScavengerCurScrap(iVar6,extraout_EAX_00);
  }
  SetVelocity(iVar6,&VStack_6c);
  SetOmega(iVar6,&VStack_60);
  if (cStack_54 != '\0') {
    Deploy(iVar6);
  }
  if (0.0 <= fStack_4c) {
    SetLifespan(iVar6,fStack_4c);
  }
  if (-1 < iStack_48) {
    SetIndependence(iVar6,iStack_48);
  }
  SetSkill(iVar6,iStack_44);
  if (Group < -1) {
    if (Group < 0) goto LAB_4fc12112;
  }
  else if (Group < 0) {
    SetBestGroup(iVar6);
    goto LAB_4fc12112;
  }
  if (Group < 10) {
    SetGroup(iVar6,iStack_40);
  }
LAB_4fc12112:
  SetCanSnipe(iVar6,(uint)bStack_3c);
  SetEjectRatio(iVar6,fStack_24);
  if (cStack_28 == '\0') {
    if (cStack_1c == '\0') {
      if (NewCommand < 0) {
        if (!KeepCommand) {
          return iVar6;
        }
        pVVar5 = &VStack_34;
        NewCommand = AStack_38;
        NewWho = iStack_4d0;
      }
      else {
        pVVar5 = &NewWhere;
      }
      SetCommand(iVar6,NewCommand,Priority,NewWho,pVVar5,0);
    }
    else {
      RemovePilotAI(iVar6);
    }
  }
  else {
    SetAsUser(iVar6,iStack_22c);
  }
  return iVar6;
}


