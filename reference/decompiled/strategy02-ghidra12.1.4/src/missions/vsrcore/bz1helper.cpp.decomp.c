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
  char *pcVar1;
  void *pvVar2;
  BZ1Helper *pBVar3;
  char (*pacVar4) [64];
  bool bVar5;
  char *pcVar6;
  ObjectHelper *pOVar7;
  VehicleHelper *pVVar8;
  ProductionClassHelper *pPVar9;
  PowerHelper *pPVar10;
  PowerupHelper *pPVar11;
  BuildingHelper *pBVar12;
  PortalHelper *pPVar13;
  AttacherHelper *pAVar14;
  UtilityShipHelper *pUVar15;
  ScrapHelper *pSVar16;
  UndeployHelper *pUVar17;
  AIWeaponHelper *pAVar18;
  MorphObjectHelper *pMVar19;
  CarrierHelper *pCVar20;
  GravityHelper *pGVar21;
  AmbientSoundHelper *pAVar22;
  int iVar23;
  int iVar24;
  char *unaff_EBP;
  float fVar25;
  char *unaff_EDI;
  float local_114 [4];
  char local_104 [64];
  char local_c4 [64];
  char local_84 [128];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)local_114;
  this->_padding_ = (int)vftable;
  memset(&this->mapInfo,0,0x48);
  memset(this->teamInfo,0,0xa140);
  pcVar6 = this[1].teamInfo[0].PlayerPilotODF + 0x1f;
  pacVar4 = this[1].teamInfo[0].PilotWeapon;
  *(char *)((int)(pacVar4 + 2) + 7) = '\0';
  *(char *)((int)(pacVar4 + 2) + 8) = '\0';
  *(char *)((int)(pacVar4 + 2) + 9) = '\0';
  *(char *)((int)(pacVar4 + 2) + 10) = '\0';
  pacVar4 = this[1].teamInfo[0].PilotWeapon;
  *(char *)((int)(pacVar4 + 2) + 0xb) = '\0';
  *(char *)((int)(pacVar4 + 2) + 0xc) = '\0';
  *(char *)((int)(pacVar4 + 2) + 0xd) = '\0';
  *(char *)((int)(pacVar4 + 2) + 0xe) = '\0';
  pacVar4 = this[1].teamInfo[0].PilotWeapon;
  *(char *)((int)(pacVar4 + 2) + 0xf) = '\0';
  *(char *)((int)(pacVar4 + 2) + 0x10) = '\0';
  *(char *)((int)(pacVar4 + 2) + 0x11) = '\0';
  *(char *)((int)(pacVar4 + 2) + 0x12) = '\0';
  pacVar4 = this[1].teamInfo[0].PilotWeapon;
  *(char *)((int)(pacVar4 + 2) + 0x13) = '\0';
  *(char *)((int)(pacVar4 + 2) + 0x14) = '\0';
  *(char *)((int)(pacVar4 + 2) + 0x15) = '\0';
  *(char *)((int)(pacVar4 + 2) + 0x16) = '\0';
  pacVar4 = this[1].teamInfo[0].PilotWeapon;
  *(char *)((int)(pacVar4 + 2) + 0x17) = '\0';
  *(char *)((int)(pacVar4 + 2) + 0x18) = '\0';
  *(char *)((int)(pacVar4 + 2) + 0x19) = '\0';
  *(char *)((int)(pacVar4 + 2) + 0x1a) = '\0';
  pacVar4 = this[1].teamInfo[0].PilotWeapon;
  *(char *)((int)(pacVar4 + 2) + 0x1b) = '\0';
  *(char *)((int)(pacVar4 + 2) + 0x1c) = '\0';
  *(char *)((int)(pacVar4 + 2) + 0x1d) = '\0';
  *(char *)((int)(pacVar4 + 2) + 0x1e) = '\0';
  iVar24 = 0x10;
  pacVar4 = this[1].teamInfo[0].PilotWeapon;
  *(char *)((int)(pacVar4 + 2) + 0x1f) = '\0';
  *(char *)((int)(pacVar4 + 2) + 0x20) = '\0';
  *(char *)((int)(pacVar4 + 2) + 0x21) = '\0';
  *(char *)((int)(pacVar4 + 2) + 0x22) = '\0';
  pacVar4 = this[1].teamInfo[0].PilotWeapon;
  *(char *)((int)(pacVar4 + 2) + 0x23) = '\0';
  *(char *)((int)(pacVar4 + 2) + 0x24) = '\0';
  *(char *)((int)(pacVar4 + 2) + 0x25) = '\0';
  *(char *)((int)(pacVar4 + 2) + 0x26) = '\0';
  pacVar4 = this[1].teamInfo[0].PilotWeapon;
  *(char *)((int)(pacVar4 + 2) + 0x27) = '\0';
  *(char *)((int)(pacVar4 + 2) + 0x28) = '\0';
  *(char *)((int)(pacVar4 + 2) + 0x29) = '\0';
  *(char *)((int)(pacVar4 + 2) + 0x2a) = '\0';
  pacVar4 = this[1].teamInfo[0].PilotWeapon;
  *(char *)((int)(pacVar4 + 2) + 0x2b) = '\0';
  *(char *)((int)(pacVar4 + 2) + 0x2c) = '\0';
  *(char *)((int)(pacVar4 + 2) + 0x2d) = '\0';
  *(char *)((int)(pacVar4 + 2) + 0x2e) = '\0';
  pacVar4 = this[1].teamInfo[0].PilotWeapon;
  *(char *)((int)(pacVar4 + 2) + 0x2f) = '\0';
  *(char *)((int)(pacVar4 + 2) + 0x30) = '\0';
  *(char *)((int)(pacVar4 + 2) + 0x31) = '\0';
  *(char *)((int)(pacVar4 + 2) + 0x32) = '\0';
  pacVar4 = this[1].teamInfo[0].PilotWeapon;
  *(char *)((int)(pacVar4 + 2) + 0x33) = '\0';
  *(char *)((int)(pacVar4 + 2) + 0x34) = '\0';
  *(char *)((int)(pacVar4 + 2) + 0x35) = '\0';
  *(char *)((int)(pacVar4 + 2) + 0x36) = '\0';
  iVar23 = iVar24;
  do {
    pcVar6[0] = '\0';
    pcVar6[1] = '\0';
    pcVar6[2] = '\0';
    pcVar6[3] = '\0';
    pcVar6[4] = '\0';
    pcVar6[5] = '\0';
    pcVar6[6] = '\0';
    pcVar6[7] = '\0';
    pcVar6[8] = '\0';
    pcVar6[9] = '\0';
    pcVar6[10] = '\0';
    pcVar6[0xb] = '\0';
    pcVar6 = pcVar6 + 0xc;
    iVar23 = iVar23 + -1;
  } while (iVar23 != 0);
  pcVar6 = this[1].teamInfo[0].BaseSlotName[1] + 0x1f;
  do {
    pcVar6[0] = '\0';
    pcVar6[1] = '\0';
    pcVar6[2] = '\0';
    pcVar6[3] = '\0';
    pcVar6[4] = '\0';
    pcVar6[5] = '\0';
    pcVar6[6] = '\0';
    pcVar6[7] = '\0';
    pcVar6[8] = '\0';
    pcVar6[9] = '\0';
    pcVar6[10] = '\0';
    pcVar6[0xb] = '\0';
    pcVar6 = pcVar6 + 0xc;
    iVar24 = iVar24 + -1;
  } while (iVar24 != 0);
  pOVar7 = operator_new(0xc);
  *(undefined4 *)&pOVar7->HandleList = 0;
  *(undefined4 *)&(pOVar7->HandleList).field_0x4 = 0;
  *(undefined4 *)&(pOVar7->HandleList).field_0x8 = 0;
  this->m_ObjectHelper = pOVar7;
  pVVar8 = operator_new(0xc);
  *(undefined4 *)&pVVar8->VehicleList = 0;
  *(undefined4 *)&(pVVar8->VehicleList).field_0x4 = 0;
  *(undefined4 *)&(pVVar8->VehicleList).field_0x8 = 0;
  this->m_VehicleHelper = pVVar8;
  pPVar9 = operator_new(1);
  this->m_ProductionClassHelper = pPVar9;
  pPVar10 = operator_new(0xc);
  PowerHelper::m_PowerHelper = pPVar10;
  *(undefined4 *)&pPVar10->PowerList = 0;
  *(undefined4 *)&(pPVar10->PowerList).field_0x4 = 0;
  *(undefined4 *)&(pPVar10->PowerList).field_0x8 = 0;
  this->m_PowerHelper = pPVar10;
  pPVar11 = operator_new(0xc);
  PowerupHelper::m_PowerupHelper = pPVar11;
  *(undefined4 *)&pPVar11->PowerupList = 0;
  *(undefined4 *)&(pPVar11->PowerupList).field_0x4 = 0;
  *(undefined4 *)&(pPVar11->PowerupList).field_0x8 = 0;
  this->m_PowerupHelper = pPVar11;
  pBVar12 = operator_new(0xc);
  BuildingHelper::m_BuildingHelper = pBVar12;
  *(undefined4 *)&pBVar12->BuildingList = 0;
  *(undefined4 *)&(pBVar12->BuildingList).field_0x4 = 0;
  *(undefined4 *)&(pBVar12->BuildingList).field_0x8 = 0;
  this->m_BuildingHelper = pBVar12;
  pPVar13 = operator_new(0x18);
  *(undefined4 *)&pPVar13->PortalList = 0;
  *(undefined4 *)&(pPVar13->PortalList).field_0x4 = 0;
  *(undefined4 *)&(pPVar13->PortalList).field_0x8 = 0;
  *(undefined4 *)&pPVar13->TeleportTargetList = 0;
  *(undefined4 *)&(pPVar13->TeleportTargetList).field_0x4 = 0;
  *(undefined4 *)&(pPVar13->TeleportTargetList).field_0x8 = 0;
  this->m_PortalHelper = pPVar13;
  pAVar14 = operator_new(0xc);
  *(undefined4 *)&pAVar14->AttacherList = 0;
  *(undefined4 *)&(pAVar14->AttacherList).field_0x4 = 0;
  *(undefined4 *)&(pAVar14->AttacherList).field_0x8 = 0;
  this->m_AttacherHelper = pAVar14;
  pUVar15 = operator_new(0xc);
  UtilityShipHelper::m_UtilityShipHelper = pUVar15;
  *(undefined4 *)&pUVar15->UtilityShipList = 0;
  *(undefined4 *)&(pUVar15->UtilityShipList).field_0x4 = 0;
  *(undefined4 *)&(pUVar15->UtilityShipList).field_0x8 = 0;
  this->m_UtilityShipHelper = pUVar15;
  pSVar16 = operator_new(0xc);
  ScrapHelper::m_ScrapHelper = pSVar16;
  *(undefined4 *)&pSVar16->ScrapList = 0;
  *(undefined4 *)&(pSVar16->ScrapList).field_0x4 = 0;
  *(undefined4 *)&(pSVar16->ScrapList).field_0x8 = 0;
  this->m_ScrapHelper = pSVar16;
  DispatchHelper::m_DispatchHelper = operator_new(0x10);
  DispatchHelper::m_DispatchHelper->_padding_ = (int)DispatchHelper::vftable;
  *(undefined4 *)&DispatchHelper::m_DispatchHelper->DispatchList = 0;
  *(undefined4 *)&(DispatchHelper::m_DispatchHelper->DispatchList).field_0x4 = 0;
  *(undefined4 *)&(DispatchHelper::m_DispatchHelper->DispatchList).field_0x8 = 0;
  this->m_DispatchHelper = DispatchHelper::m_DispatchHelper;
  pUVar17 = operator_new(0xc);
  UndeployHelper::m_UndeployHelper = pUVar17;
  *(undefined4 *)&pUVar17->UndeployList = 0;
  *(undefined4 *)&(pUVar17->UndeployList).field_0x4 = 0;
  *(undefined4 *)&(pUVar17->UndeployList).field_0x8 = 0;
  this->m_UndeployHelper = pUVar17;
  pAVar18 = operator_new(1);
  this->m_AIWeaponHelper = pAVar18;
  pMVar19 = operator_new(0x10);
  MorphObjectHelper::m_MorphObjectHelper = pMVar19;
  pMVar19->_padding_ = (int)MorphObjectHelper::vftable;
  *(undefined4 *)&pMVar19->MorphObjectList = 0;
  *(undefined4 *)&(pMVar19->MorphObjectList).field_0x4 = 0;
  *(undefined4 *)&(pMVar19->MorphObjectList).field_0x8 = 0;
  this->m_MorphObjectHelper = pMVar19;
  pCVar20 = operator_new(0x1c);
  pCVar20->_padding_ = (int)CarrierHelper::vftable;
  *(undefined4 *)&pCVar20->CarrierList = 0;
  *(undefined4 *)&(pCVar20->CarrierList).field_0x4 = 0;
  *(undefined4 *)&(pCVar20->CarrierList).field_0x8 = 0;
  *(undefined4 *)&pCVar20->DroneList = 0;
  *(undefined4 *)&(pCVar20->DroneList).field_0x4 = 0;
  *(undefined4 *)&(pCVar20->DroneList).field_0x8 = 0;
  this->m_CarrierHelper = pCVar20;
  pGVar21 = operator_new(0x140);
  memset(pGVar21,0,0x140);
  this->m_GravityHelper = pGVar21;
  pAVar22 = operator_new(0xe00);
  memset(pAVar22,0,0xe00);
  this->m_AmbientSoundHelper = pAVar22;
  EnableHighTPS(&m_GameTPS);
  GetMapTRNFilename();
  TRNAllies::SetupTRNAllies(unaff_EBP);
  pBVar3 = this + 1;
  pBVar3->teamInfo[0].PlayerPilotODF[3] = '\v';
  pBVar3->teamInfo[0].PlayerPilotODF[4] = '\0';
  pBVar3->teamInfo[0].PlayerPilotODF[5] = '\0';
  pBVar3->teamInfo[0].PlayerPilotODF[6] = '\0';
  *(char **)(this[1].teamInfo[0].PilotWeapon[4] + 0x3f) = this[1].teamInfo[0].PilotWeapon[4] + 0x18;
  pcVar6 = this[1].teamInfo[0].PilotWeapon[4] + 0x2b;
  pcVar1 = this[1].teamInfo[0].PilotWeapon[2] + 0x3b;
  pBVar3 = this + 1;
  pBVar3->teamInfo[0].PlayerPilotODF[0xb] = '\x04';
  pBVar3->teamInfo[0].PlayerPilotODF[0xc] = '\0';
  pBVar3->teamInfo[0].PlayerPilotODF[0xd] = '\0';
  pBVar3->teamInfo[0].PlayerPilotODF[0xe] = '\0';
  *(char **)(this[1].teamInfo[0].PlayerPilotODF + 7) = pcVar6;
  pBVar3 = this + 1;
  pBVar3->teamInfo[0].PlayerPilotODF[0x13] = '\x16';
  pBVar3->teamInfo[0].PlayerPilotODF[0x14] = '\0';
  pBVar3->teamInfo[0].PlayerPilotODF[0x15] = '\0';
  pBVar3->teamInfo[0].PlayerPilotODF[0x16] = '\0';
  *(char **)(this[1].teamInfo[0].PlayerPilotODF + 0xf) = pcVar1;
  if (pcVar1 != (char *)0x0) {
    memset(pcVar1,0,0x58);
    pcVar6 = *(char **)(this[1].teamInfo[0].PlayerPilotODF + 7);
  }
  if (pcVar6 != (char *)0x0) {
    memset(pcVar6,0,*(int *)(this[1].teamInfo[0].PlayerPilotODF + 0xb) << 2);
  }
  pvVar2 = *(void **)(this[1].teamInfo[0].PilotWeapon[4] + 0x3f);
  if (pvVar2 != (void *)0x0) {
    memset(pvVar2,0,*(size_t *)(this[1].teamInfo[0].PlayerPilotODF + 3));
  }
  local_114[1] = -4000.0;
  local_114[2] = 0.0;
  HullGauge2 = 0.0;
  AmmoGauge2 = 0.0;
  AuxGauge = 0.0;
  m_TurnCounter = 0;
  TotalMapObjects = 0;
  WorldSetting = '\0';
  pBVar3 = this + 1;
  pBVar3->teamInfo[0].PlayerPilotODF[0x17] = '\0';
  pBVar3->teamInfo[0].PlayerPilotODF[0x18] = '\0';
  pBVar3->teamInfo[0].PlayerPilotODF[0x19] = '\0';
  pBVar3->teamInfo[0].PlayerPilotODF[0x1a] = '\0';
  pBVar3 = this + 1;
  pBVar3->teamInfo[0].PlayerPilotODF[0x1b] = '\0';
  pBVar3->teamInfo[0].PlayerPilotODF[0x1c] = '\0';
  pBVar3->teamInfo[0].PlayerPilotODF[0x1d] = '\0';
  pBVar3->teamInfo[0].PlayerPilotODF[0x1e] = '\0';
  local_114[3] = -4000.0;
  OffMapPos.x = -4000.0;
  HullGaugeSet = false;
  AmmoGaugeSet = false;
  AuxGaugeSet = false;
  OffMapPos.y = 0.0;
  OffMapPos.z = -4000.0;
  memset(local_84,0,0x80);
  pcVar6 = GetMapTRNFilename();
  strcpy_s(local_84,0x80,pcVar6);
  bVar5 = OpenODF2(unaff_EBP);
  if (bVar5) {
    GetODFChar(local_84,"World","WorldLetter",&WorldSetting,'\0');
    bVar5 = IsNetworkOn();
    if (bVar5) {
      iVar24 = GetVarItemInt("network.session.ivar53");
      if (iVar24 != 2) {
        iVar24 = GetVarItemInt("network.session.ivar12");
        if (iVar24 != 1) goto LAB_4fc0b4a4;
      }
    }
    else {
LAB_4fc0b4a4:
      iVar24 = IFace_GetInteger("options.instant.awarev13");
      if (iVar24 == 0) goto LAB_4fc0b560;
    }
    fVar25 = 0.0;
    do {
      memset(local_104,0,0x40);
      memset(local_c4,0,0x40);
      local_114[0] = (float)((int)fVar25 + 1);
      sprintf_s<64>(&local_c4,"MPISwitchTeams%d");
      iVar24 = GetODFString(local_84,"DLL",local_c4,0x40,local_104,(char *)0x0);
      if ((iVar24 == 0) || (local_104[0] == '\0')) break;
      iVar24 = atoi(local_104);
      m_SwitchTeamA[(int)fVar25] = iVar24;
      pcVar6 = strchr(local_104,0x5f);
      if (pcVar6 != (char *)0x0) {
        iVar24 = atoi(pcVar6 + 1);
        m_SwitchTeamB[(int)fVar25] = iVar24;
      }
      fVar25 = local_114[0];
    } while ((int)local_114[0] < 0x10);
  }
LAB_4fc0b560:
  iVar24 = GetVarItemInt("network.session.ivar115");
  if (iVar24 == 0) {
    iVar24 = GetVarItemInt("network.session.civar5");
    if (iVar24 == 0) {
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
  bVar5 = OpenODF2(unaff_EDI);
  if (bVar5) {
    GetODFFloat("PatchData.txt","VersionInfo","Version",local_114,0.0);
  }
  m_ModVersion = local_114[0];
  sprintf_s<64>(&LogFileName,"VSR");
  m_BZ1Helper = this;
  PrintConsoleMessage("VSR BZCC DLL Created by General BlackDragon");
  bVar5 = DoesFileExist("vsrbasesetup.cfg");
  if (bVar5) {
    IFace_Exec("vsrbasesetup.cfg");
  }
  return this;
}


// ---------------------------------------------------------------------
// BZ1Helper::~BZ1Helper  @ 4fc0b66b  lines 262-327


void __thiscall BZ1Helper::~BZ1Helper(BZ1Helper *this)

{
  char *pcVar1;
  vector<ObjectHelper::ObjectClass,std::allocator<ObjectHelper::ObjectClass>_> *this_00;
  vector<VehicleHelper::VehicleClass,std::allocator<VehicleHelper::VehicleClass>_> *this_01;
  vector<PowerHelper::PowerClass,std::allocator<PowerHelper::PowerClass>_> *this_02;
  vector<PowerupHelper::PowerupClass,std::allocator<PowerupHelper::PowerupClass>_> *this_03;
  vector<BuildingHelper::BuildingClass,std::allocator<BuildingHelper::BuildingClass>_> *this_04;
  PortalHelper *this_05;
  vector<AttacherHelper::AttacherClass,std::allocator<AttacherHelper::AttacherClass>_> *this_06;
  vector<UtilityShipHelper::UtilityShipClass,std::allocator<UtilityShipHelper::UtilityShipClass>_>
  *this_07;
  ScrapHelper *pSVar2;
  UndeployHelper *pUVar3;
  char (*pacVar4) [64];
  bool bVar5;
  BZ1Helper *this_08;
  void *unaff_EBX;
  int iVar6;
  int iVar7;
  uint unaff_ESI;
  void *unaff_EDI;
  char *pcVar8;
  
  bVar5 = Logging;
  this->_padding_ = (int)vftable;
  if (bVar5) {
    FormatLogMessage("Game Ended.\n");
  }
  CloseOpenODFs();
  if (LogFile != (_iobuf *)0x0) {
    fclose((FILE *)LogFile);
  }
  CloseOpenFiles();
  CleanupTaunts();
  if ((DeathCameraOn != false) && (bVar5 = IsNetworkOn(), bVar5)) {
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
  pSVar2 = this->m_ScrapHelper;
  if (pSVar2 != (ScrapHelper *)0x0) {
    ScrapHelper::m_ScrapHelper = (ScrapHelper *)0x0;
    if (*(int *)&pSVar2->ScrapList != 0) {
      std::_Deallocate<8,0>(unaff_EBX,(uint)unaff_EDI);
      *(undefined4 *)&pSVar2->ScrapList = 0;
      *(undefined4 *)&(pSVar2->ScrapList).field_0x4 = 0;
      *(undefined4 *)&(pSVar2->ScrapList).field_0x8 = 0;
    }
    operator_delete(pSVar2,0xc);
  }
  if (this->m_DispatchHelper != (DispatchHelper *)0x0) {
    (**(code **)this->m_DispatchHelper->_padding_)(1);
  }
  pUVar3 = this->m_UndeployHelper;
  if (pUVar3 != (UndeployHelper *)0x0) {
    UndeployHelper::m_UndeployHelper = (UndeployHelper *)0x0;
    if (*(int *)&pUVar3->UndeployList != 0) {
      std::_Deallocate<8,0>(unaff_EBX,(uint)unaff_EDI);
      *(undefined4 *)&pUVar3->UndeployList = 0;
      *(undefined4 *)&(pUVar3->UndeployList).field_0x4 = 0;
      *(undefined4 *)&(pUVar3->UndeployList).field_0x8 = 0;
    }
    operator_delete(pUVar3,0xc);
  }
  operator_delete(this->m_AIWeaponHelper,1);
  if (this->m_MorphObjectHelper != (MorphObjectHelper *)0x0) {
    (**(code **)this->m_MorphObjectHelper->_padding_)(1);
  }
  if (this->m_CarrierHelper != (CarrierHelper *)0x0) {
    (**(code **)this->m_CarrierHelper->_padding_)(1);
  }
  operator_delete(this->m_GravityHelper,0x140);
  operator_delete(this->m_AmbientSoundHelper,0xe00);
  m_BZ1Helper = (BZ1Helper *)0x0;
  iVar6 = 0x10;
  iVar7 = iVar6;
  pcVar8 = this[1].teamInfo[0].BaseSlotName[4] + 0x1f;
  do {
    pcVar1 = pcVar8 + -0xc;
    iVar7 = iVar7 + -1;
    if (*(int *)pcVar1 != 0) {
      std::_Deallocate<8,0>(unaff_EBX,(uint)unaff_EDI);
      pcVar1[0] = '\0';
      pcVar1[1] = '\0';
      pcVar1[2] = '\0';
      pcVar1[3] = '\0';
      pcVar8[-0xffffffff00000008] = '\0';
      pcVar8[-0xffffffff00000007] = '\0';
      pcVar8[-0xffffffff00000006] = '\0';
      pcVar8[-0xffffffff00000005] = '\0';
      pcVar8[-0xffffffff00000004] = '\0';
      pcVar8[-0xffffffff00000003] = '\0';
      pcVar8[-0xffffffff00000002] = '\0';
      pcVar8[-0xffffffff00000001] = '\0';
    }
    pcVar8 = pcVar1;
  } while (iVar7 != 0);
  pcVar8 = this[1].teamInfo[0].BaseSlotName[1] + 0x1f;
  do {
    pcVar1 = pcVar8 + -0xc;
    iVar6 = iVar6 + -1;
    if (*(int *)pcVar1 != 0) {
      std::_Deallocate<8,0>(unaff_EBX,(uint)unaff_EDI);
      pcVar1[0] = '\0';
      pcVar1[1] = '\0';
      pcVar1[2] = '\0';
      pcVar1[3] = '\0';
      pcVar8[-0xffffffff00000008] = '\0';
      pcVar8[-0xffffffff00000007] = '\0';
      pcVar8[-0xffffffff00000006] = '\0';
      pcVar8[-0xffffffff00000005] = '\0';
      pcVar8[-0xffffffff00000004] = '\0';
      pcVar8[-0xffffffff00000003] = '\0';
      pcVar8[-0xffffffff00000002] = '\0';
      pcVar8[-0xffffffff00000001] = '\0';
    }
    pcVar8 = pcVar1;
  } while (iVar6 != 0);
  std::vector<BZ1Helper::BuildAtClass,std::allocator<BZ1Helper::BuildAtClass>_>::_Tidy
            ((vector<BZ1Helper::BuildAtClass,std::allocator<BZ1Helper::BuildAtClass>_> *)
             (this[1].teamInfo[0].PilotWeapon[2] + 0x2b));
  std::vector<BZ1Helper::DeploySoundClass,std::allocator<BZ1Helper::DeploySoundClass>_>::_Tidy
            ((vector<BZ1Helper::DeploySoundClass,std::allocator<BZ1Helper::DeploySoundClass>_> *)
             (this[1].teamInfo[0].PilotWeapon[2] + 0x1f));
  if (*(int *)(this[1].teamInfo[0].PilotWeapon[2] + 0x13) != 0) {
    std::_Deallocate<8,0>(unaff_EDI,unaff_ESI);
    pacVar4 = this[1].teamInfo[0].PilotWeapon;
    *(char *)((int)(pacVar4 + 2) + 0x13) = '\0';
    *(char *)((int)(pacVar4 + 2) + 0x14) = '\0';
    *(char *)((int)(pacVar4 + 2) + 0x15) = '\0';
    *(char *)((int)(pacVar4 + 2) + 0x16) = '\0';
    pacVar4 = this[1].teamInfo[0].PilotWeapon;
    *(char *)((int)(pacVar4 + 2) + 0x17) = '\0';
    *(char *)((int)(pacVar4 + 2) + 0x18) = '\0';
    *(char *)((int)(pacVar4 + 2) + 0x19) = '\0';
    *(char *)((int)(pacVar4 + 2) + 0x1a) = '\0';
    pacVar4 = this[1].teamInfo[0].PilotWeapon;
    *(char *)((int)(pacVar4 + 2) + 0x1b) = '\0';
    *(char *)((int)(pacVar4 + 2) + 0x1c) = '\0';
    *(char *)((int)(pacVar4 + 2) + 0x1d) = '\0';
    *(char *)((int)(pacVar4 + 2) + 0x1e) = '\0';
  }
  if (*(int *)(this[1].teamInfo[0].PilotWeapon[2] + 7) != 0) {
    std::_Deallocate<8,0>(unaff_EDI,unaff_ESI);
    pacVar4 = this[1].teamInfo[0].PilotWeapon;
    *(char *)((int)(pacVar4 + 2) + 7) = '\0';
    *(char *)((int)(pacVar4 + 2) + 8) = '\0';
    *(char *)((int)(pacVar4 + 2) + 9) = '\0';
    *(char *)((int)(pacVar4 + 2) + 10) = '\0';
    pacVar4 = this[1].teamInfo[0].PilotWeapon;
    *(char *)((int)(pacVar4 + 2) + 0xb) = '\0';
    *(char *)((int)(pacVar4 + 2) + 0xc) = '\0';
    *(char *)((int)(pacVar4 + 2) + 0xd) = '\0';
    *(char *)((int)(pacVar4 + 2) + 0xe) = '\0';
    pacVar4 = this[1].teamInfo[0].PilotWeapon;
    *(char *)((int)(pacVar4 + 2) + 0xf) = '\0';
    *(char *)((int)(pacVar4 + 2) + 0x10) = '\0';
    *(char *)((int)(pacVar4 + 2) + 0x11) = '\0';
    *(char *)((int)(pacVar4 + 2) + 0x12) = '\0';
  }
  this->_padding_ = (int)DLLBase::vftable;
  return;
}


// ---------------------------------------------------------------------
// BZ1Helper::Load  @ 4fc0b943  lines 331-545


bool __thiscall BZ1Helper::Load(BZ1Helper *this,bool param_1)

{
  vector<BZ1Helper::DeleteAfterDelayClass,std::allocator<BZ1Helper::DeleteAfterDelayClass>_> *pvVar1
  ;
  vector<BZ1Helper::DeploySoundClass,std::allocator<BZ1Helper::DeploySoundClass>_> *pvVar2;
  vector<BZ1Helper::BuildAtClass,std::allocator<BZ1Helper::BuildAtClass>_> *pvVar3;
  vector<ObjectHelper::ObjectClass,std::allocator<ObjectHelper::ObjectClass>_> *this_00;
  bool *pbVar4;
  float *pfVar5;
  vector<PowerHelper::PowerClass,std::allocator<PowerHelper::PowerClass>_> *pvVar6;
  vector<PowerupHelper::PowerupClass,std::allocator<PowerupHelper::PowerupClass>_> *this_01;
  vector<BuildingHelper::BuildingClass,std::allocator<BuildingHelper::BuildingClass>_> *this_02;
  vector<AttacherHelper::AttacherClass,std::allocator<AttacherHelper::AttacherClass>_> *this_03;
  vector<UtilityShipHelper::UtilityShipClass,std::allocator<UtilityShipHelper::UtilityShipClass>_>
  *this_04;
  vector<ScrapHelper::ScrapClass,std::allocator<ScrapHelper::ScrapClass>_> *this_05;
  vector<BZ1Helper::AlignTerrainReplaceClass,std::allocator<BZ1Helper::AlignTerrainReplaceClass>_>
  *pvVar7;
  BZ1Helper *this_06;
  bool bVar8;
  forward_iterator_tag fVar9;
  forward_iterator_tag fVar10;
  bool bVar11;
  TeamInfo **ppTVar12;
  vector<VehicleHelper::VehicleClass,std::allocator<VehicleHelper::VehicleClass>_> *this_07;
  vector<PowerupHelper::PowerupClass,std::allocator<PowerupHelper::PowerupClass>_> *this_08;
  vector<BuildingHelper::BuildingClass,std::allocator<BuildingHelper::BuildingClass>_> *this_09;
  vector<UtilityShipHelper::UtilityShipClass,std::allocator<UtilityShipHelper::UtilityShipClass>_>
  *this_10;
  vector<ScrapHelper::ScrapClass,std::allocator<ScrapHelper::ScrapClass>_> *this_11;
  vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_> *this_12;
  vector<UndeployHelper::UndeployClass,std::allocator<UndeployHelper::UndeployClass>_> *this_13;
  vector<MorphObjectHelper::MorphObjectClass,std::allocator<MorphObjectHelper::MorphObjectClass>_>
  *this_14;
  int iVar13;
  vector<BZ1Helper::DeleteAfterDelayClass,std::allocator<BZ1Helper::DeleteAfterDelayClass>_>
  *extraout_ECX;
  vector<BZ1Helper::DeploySoundClass,std::allocator<BZ1Helper::DeploySoundClass>_> *extraout_ECX_00;
  vector<BZ1Helper::BuildAtClass,std::allocator<BZ1Helper::BuildAtClass>_> *extraout_ECX_01;
  vector<BZ1Helper::DeleteAfterDelayClass,std::allocator<BZ1Helper::DeleteAfterDelayClass>_>
  *pvVar14;
  vector<VehicleHelper::VehicleClass,std::allocator<VehicleHelper::VehicleClass>_> *extraout_ECX_02;
  vector<PowerHelper::PowerClass,std::allocator<PowerHelper::PowerClass>_> *this_15;
  vector<PowerupHelper::PowerupClass,std::allocator<PowerupHelper::PowerupClass>_> *extraout_ECX_03;
  vector<BuildingHelper::BuildingClass,std::allocator<BuildingHelper::BuildingClass>_>
  *extraout_ECX_04;
  vector<AttacherHelper::AttacherClass,std::allocator<AttacherHelper::AttacherClass>_> *this_16;
  vector<UtilityShipHelper::UtilityShipClass,std::allocator<UtilityShipHelper::UtilityShipClass>_>
  *extraout_ECX_05;
  vector<ScrapHelper::ScrapClass,std::allocator<ScrapHelper::ScrapClass>_> *extraout_ECX_06;
  vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
  *extraout_ECX_07;
  vector<UndeployHelper::UndeployClass,std::allocator<UndeployHelper::UndeployClass>_>
  *extraout_ECX_08;
  vector<MorphObjectHelper::MorphObjectClass,std::allocator<MorphObjectHelper::MorphObjectClass>_>
  *extraout_ECX_09;
  TeamInfo *pTVar15;
  undefined4 unaff_ESI;
  MapInfo *pMVar16;
  TeamInfo *pTVar17;
  vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_> *this_17;
  vector<MorphObjectHelper::MorphObjectClass,std::allocator<MorphObjectHelper::MorphObjectClass>_>
  *this_18;
  undefined4 unaff_EDI;
  MapInfo *pMVar18;
  TeamInfo **ppTVar19;
  forward_iterator_tag in_stack_00000008;
  undefined1 uVar20;
  undefined1 uVar21;
  uint local_18;
  uint local_14;
  vector<VehicleHelper::VehicleClass,std::allocator<VehicleHelper::VehicleClass>_> *local_10;
  undefined4 local_c;
  TeamInfo *local_8;
  BZ1Helper *local_4;
  
  if (param_1) {
    return true;
  }
  pvVar7 = (vector<BZ1Helper::AlignTerrainReplaceClass,std::allocator<BZ1Helper::AlignTerrainReplaceClass>_>
            *)(this[1].teamInfo[0].PilotWeapon[2] + 7);
  pMVar16 = &this->mapInfo;
  pMVar18 = &TempMapInfoBuffer;
  for (iVar13 = 0x12; iVar13 != 0; iVar13 = iVar13 + -1) {
    pMVar18->Height = pMVar16->Height;
    pMVar16 = (MapInfo *)&pMVar16->MapWidth;
    pMVar18 = (MapInfo *)&pMVar18->MapWidth;
  }
  pvVar14 = (vector<BZ1Helper::DeleteAfterDelayClass,std::allocator<BZ1Helper::DeleteAfterDelayClass>_>
             *)0x0;
  local_4 = this;
  if (pvVar7 != &TempAlignBuffer) {
    std::
    vector<BZ1Helper::AlignTerrainReplaceClass,std::allocator<BZ1Helper::AlignTerrainReplaceClass>_>
    ::_Assign_range<BZ1Helper::AlignTerrainReplaceClass_*>
              ((vector<BZ1Helper::AlignTerrainReplaceClass,std::allocator<BZ1Helper::AlignTerrainReplaceClass>_>
                *)0x0,*(AlignTerrainReplaceClass **)pvVar7,
               *(AlignTerrainReplaceClass **)(this[1].teamInfo[0].PilotWeapon[2] + 0xb),
               (forward_iterator_tag)0x0);
    pvVar14 = extraout_ECX;
  }
  pvVar1 = (vector<BZ1Helper::DeleteAfterDelayClass,std::allocator<BZ1Helper::DeleteAfterDelayClass>_>
            *)(this[1].teamInfo[0].PilotWeapon[2] + 0x13);
  if (pvVar1 != &TempDeleteBuffer) {
    std::vector<BZ1Helper::DeleteAfterDelayClass,std::allocator<BZ1Helper::DeleteAfterDelayClass>_>
    ::_Assign_range<BZ1Helper::DeleteAfterDelayClass_*>
              (pvVar14,*(DeleteAfterDelayClass **)pvVar1,
               *(DeleteAfterDelayClass **)(this[1].teamInfo[0].PilotWeapon[2] + 0x17),
               (forward_iterator_tag)0x0);
    pvVar14 = (vector<BZ1Helper::DeleteAfterDelayClass,std::allocator<BZ1Helper::DeleteAfterDelayClass>_>
               *)extraout_ECX_00;
  }
  pvVar2 = (vector<BZ1Helper::DeploySoundClass,std::allocator<BZ1Helper::DeploySoundClass>_> *)
           (this[1].teamInfo[0].PilotWeapon[2] + 0x1f);
  if (pvVar2 != &TempDeploySoundBuffer) {
    std::vector<BZ1Helper::DeploySoundClass,std::allocator<BZ1Helper::DeploySoundClass>_>::
    _Assign_range<BZ1Helper::DeploySoundClass_*>
              ((vector<BZ1Helper::DeploySoundClass,std::allocator<BZ1Helper::DeploySoundClass>_> *)
               pvVar14,*(DeploySoundClass **)pvVar2,
               *(DeploySoundClass **)(this[1].teamInfo[0].PilotWeapon[2] + 0x23),
               (forward_iterator_tag)0x0);
    pvVar14 = (vector<BZ1Helper::DeleteAfterDelayClass,std::allocator<BZ1Helper::DeleteAfterDelayClass>_>
               *)extraout_ECX_01;
  }
  pvVar3 = (vector<BZ1Helper::BuildAtClass,std::allocator<BZ1Helper::BuildAtClass>_> *)
           (this[1].teamInfo[0].PilotWeapon[2] + 0x2b);
  if (pvVar3 != &TempBuiltAtBuffer) {
    std::vector<BZ1Helper::BuildAtClass,std::allocator<BZ1Helper::BuildAtClass>_>::
    _Assign_range<BZ1Helper::BuildAtClass_*>
              ((vector<BZ1Helper::BuildAtClass,std::allocator<BZ1Helper::BuildAtClass>_> *)pvVar14,
               *(BuildAtClass **)pvVar3,
               *(BuildAtClass **)(this[1].teamInfo[0].PilotWeapon[2] + 0x2f),
               (forward_iterator_tag)0x0);
  }
  local_8 = this->teamInfo;
  ppTVar12 = &TempTeamInfoBuffer;
  pTVar15 = local_8;
  do {
    pTVar17 = pTVar15;
    ppTVar19 = ppTVar12;
    for (iVar13 = 0x285; iVar13 != 0; iVar13 = iVar13 + -1) {
      *ppTVar19 = (TeamInfo *)pTVar17->RealPlayer;
      pTVar17 = (TeamInfo *)&pTVar17->Player;
      ppTVar19 = ppTVar19 + 1;
    }
    ppTVar12 = ppTVar12 + 0x285;
    pTVar15 = (TeamInfo *)&pTVar15[1].CommTower;
  } while ((int)ppTVar12 < 0x4fc7a6b0);
  bVar8 = Read(&this->mapInfo,0x48);
  local_c = 1;
  if (bVar8) {
    this_00 = &this->m_ObjectHelper->HandleList;
    if (this_00 != &TempHandleBuffer) {
      std::vector<ObjectHelper::ObjectClass,std::allocator<ObjectHelper::ObjectClass>_>::
      _Assign_range<ObjectHelper::ObjectClass_*>
                ((vector<ObjectHelper::ObjectClass,std::allocator<ObjectHelper::ObjectClass>_> *)0x1
                 ,*(ObjectClass **)this_00,*(ObjectClass **)&this_00->field_0x4,
                 (forward_iterator_tag)0x0);
    }
    local_14 = 0;
    fVar9 = (forward_iterator_tag)Read((int *)&local_14,1);
    std::vector<ObjectHelper::ObjectClass,std::allocator<ObjectHelper::ObjectClass>_>::
    _Resize<<lambda_d4eb94d7f5b88ac3e14105a7a949c756>_>
              (this_00,local_14,(<lambda_d4eb94d7f5b88ac3e14105a7a949c756>)this_00);
    this_07 = extraout_ECX_02;
    fVar10 = fVar9;
    if (local_14 == 0) {
LAB_4fc0ba8a:
      if (fVar10 == (forward_iterator_tag)0x0) goto LAB_4fc0bb1e;
    }
    else {
      if (!(bool)fVar9) {
LAB_4fc0ba82:
        fVar10 = (forward_iterator_tag)0x0;
        goto LAB_4fc0ba8a;
      }
      this_07 = (vector<VehicleHelper::VehicleClass,std::allocator<VehicleHelper::VehicleClass>_> *)
                (local_14 * 0x5c);
      bVar8 = Read(*(void **)this_00,(int)this_07);
      if (!bVar8) goto LAB_4fc0ba82;
    }
    local_10 = &this->m_VehicleHelper->VehicleList;
    if (local_10 != &TempVehicleBuffer) {
      std::vector<VehicleHelper::VehicleClass,std::allocator<VehicleHelper::VehicleClass>_>::
      _Assign_range<VehicleHelper::VehicleClass_*>
                (this_07,*(VehicleClass **)local_10,*(VehicleClass **)&local_10->field_0x4,fVar9);
    }
    local_14 = 0;
    bVar8 = Read((int *)&local_14,1);
    std::vector<VehicleHelper::VehicleClass,std::allocator<VehicleHelper::VehicleClass>_>::
    _Resize<<lambda_211499e44519ac16b68a02000ccfed01>_>
              (local_10,local_14,(<lambda_211499e44519ac16b68a02000ccfed01>)local_10);
    if (local_14 == 0) {
LAB_4fc0bb00:
      if (bVar8 == false) goto LAB_4fc0bb1e;
    }
    else if ((!bVar8) || (bVar8 = Read(*(void **)local_10,local_14 * 0x54), !bVar8)) {
      bVar8 = false;
      goto LAB_4fc0bb00;
    }
    local_18 = 0;
    bVar8 = Read((int *)&local_18,1);
    if (!bVar8) goto LAB_4fc0bb23;
    bVar8 = true;
  }
  else {
LAB_4fc0bb1e:
    local_18 = 0;
LAB_4fc0bb23:
    bVar8 = false;
  }
  pvVar7 = (vector<BZ1Helper::AlignTerrainReplaceClass,std::allocator<BZ1Helper::AlignTerrainReplaceClass>_>
            *)(this[1].teamInfo[0].PilotWeapon[2] + 7);
  std::
  vector<BZ1Helper::AlignTerrainReplaceClass,std::allocator<BZ1Helper::AlignTerrainReplaceClass>_>::
  _Resize<<lambda_1855a80fc533c550b5607d8bf997ad95>_>
            (pvVar7,local_18,(<lambda_1855a80fc533c550b5607d8bf997ad95>)pvVar7);
  if (local_18 == 0) {
LAB_4fc0bb66:
    local_18 = 0;
    if (bVar8) goto LAB_4fc0bb6f;
LAB_4fc0bb83:
    bVar8 = false;
  }
  else {
    if ((!bVar8) || (bVar8 = Read(*(void **)pvVar7,local_18 << 4), !bVar8)) {
      bVar8 = false;
      goto LAB_4fc0bb66;
    }
LAB_4fc0bb6f:
    local_18 = 0;
    bVar11 = Read((int *)&local_18,1);
    bVar8 = true;
    if (!bVar11) goto LAB_4fc0bb83;
  }
  pvVar14 = (vector<BZ1Helper::DeleteAfterDelayClass,std::allocator<BZ1Helper::DeleteAfterDelayClass>_>
             *)(this[1].teamInfo[0].PilotWeapon[2] + 0x13);
  std::vector<BZ1Helper::DeleteAfterDelayClass,std::allocator<BZ1Helper::DeleteAfterDelayClass>_>::
  _Resize<<lambda_4cef8f5d2e224a10ec5594e33bb09482>_>
            (pvVar14,local_18,(<lambda_4cef8f5d2e224a10ec5594e33bb09482>)pvVar14);
  if (local_18 == 0) {
LAB_4fc0bbc6:
    local_18 = 0;
    if (bVar8) goto LAB_4fc0bbcf;
LAB_4fc0bbe3:
    bVar8 = false;
  }
  else {
    if ((!bVar8) || (bVar8 = Read(*(void **)pvVar14,local_18 << 3), !bVar8)) {
      bVar8 = false;
      goto LAB_4fc0bbc6;
    }
LAB_4fc0bbcf:
    local_18 = 0;
    bVar11 = Read((int *)&local_18,1);
    bVar8 = true;
    if (!bVar11) goto LAB_4fc0bbe3;
  }
  pvVar2 = (vector<BZ1Helper::DeploySoundClass,std::allocator<BZ1Helper::DeploySoundClass>_> *)
           (this[1].teamInfo[0].PilotWeapon[2] + 0x1f);
  std::vector<BZ1Helper::DeploySoundClass,std::allocator<BZ1Helper::DeploySoundClass>_>::
  _Resize<<lambda_4d52942989f528cd785dbeae06193644>_>
            (pvVar2,local_18,(<lambda_4d52942989f528cd785dbeae06193644>)pvVar2);
  if (local_18 == 0) {
LAB_4fc0bc26:
    local_18 = 0;
    if (bVar8) goto LAB_4fc0bc2f;
LAB_4fc0bc43:
    param_1 = false;
  }
  else {
    if ((!bVar8) || (bVar8 = Read(*(void **)pvVar2,local_18 * 0x58), !bVar8)) {
      bVar8 = false;
      goto LAB_4fc0bc26;
    }
LAB_4fc0bc2f:
    local_18 = 0;
    bVar8 = Read((int *)&local_18,1);
    param_1 = true;
    if (!bVar8) goto LAB_4fc0bc43;
  }
  pvVar3 = (vector<BZ1Helper::BuildAtClass,std::allocator<BZ1Helper::BuildAtClass>_> *)
           (this[1].teamInfo[0].PilotWeapon[2] + 0x2b);
  std::vector<BZ1Helper::BuildAtClass,std::allocator<BZ1Helper::BuildAtClass>_>::
  _Resize<<lambda_dee307eb94beae9268b6d89c62f4c357>_>
            (pvVar3,local_18,(<lambda_dee307eb94beae9268b6d89c62f4c357>)pvVar3);
  if (local_18 != 0) {
    if ((param_1 == false) || (bVar8 = Read(*(void **)pvVar3,local_18 * 0x1c), !bVar8)) {
      param_1 = false;
    }
    else {
      param_1 = true;
    }
  }
  iVar13 = 0x10;
  pTVar15 = local_8;
  do {
    if ((param_1 == false) || (bVar8 = Read(pTVar15,0xa14), !bVar8)) {
      param_1 = false;
    }
    else {
      param_1 = true;
    }
    this_06 = local_4;
    uVar21 = (undefined1)unaff_ESI;
    uVar20 = (undefined1)unaff_EDI;
    pTVar15 = (TeamInfo *)&pTVar15[1].CommTower;
    iVar13 = iVar13 + -1;
  } while (iVar13 != 0);
  pbVar4 = *(bool **)(local_4[1].teamInfo[0].PilotWeapon[4] + 0x3f);
  if (pbVar4 != (bool *)0x0) {
    if ((param_1 == false) ||
       (bVar8 = Read(pbVar4,*(int *)(local_4[1].teamInfo[0].PlayerPilotODF + 3)), !bVar8)) {
      param_1 = false;
    }
    else {
      param_1 = true;
    }
  }
  pfVar5 = *(float **)(this_06[1].teamInfo[0].PlayerPilotODF + 7);
  bVar8 = param_1;
  if (pfVar5 != (float *)0x0) {
    if ((param_1 == false) ||
       (bVar8 = Read(pfVar5,*(int *)(this_06[1].teamInfo[0].PlayerPilotODF + 0xb)), !bVar8)) {
      bVar8 = false;
    }
    else {
      bVar8 = true;
    }
  }
  this_15 = *(vector<PowerHelper::PowerClass,std::allocator<PowerHelper::PowerClass>_> **)
             (this_06[1].teamInfo[0].PlayerPilotODF + 0xf);
  if (this_15 == (vector<PowerHelper::PowerClass,std::allocator<PowerHelper::PowerClass>_> *)0x0) {
LAB_4fc0bd32:
    if (bVar8 != false) goto LAB_4fc0bd3a;
  }
  else {
    if (bVar8 == false) {
LAB_4fc0bd30:
      bVar8 = false;
      goto LAB_4fc0bd32;
    }
    pvVar6 = *(vector<PowerHelper::PowerClass,std::allocator<PowerHelper::PowerClass>_> **)
              (this_06[1].teamInfo[0].PlayerPilotODF + 0x13);
    bVar8 = Read((int *)this_15,(int)pvVar6);
    this_15 = pvVar6;
    if (!bVar8) goto LAB_4fc0bd30;
LAB_4fc0bd3a:
    pvVar6 = &this_06->m_PowerHelper->PowerList;
    if (pvVar6 != &TempPowerBuffer) {
      std::vector<PowerHelper::PowerClass,std::allocator<PowerHelper::PowerClass>_>::
      _Assign_range<PowerHelper::PowerClass_*>
                (this_15,*(PowerClass **)pvVar6,*(PowerClass **)&pvVar6->field_0x4,
                 (forward_iterator_tag)param_1);
    }
    local_14 = 0;
    fVar9 = (forward_iterator_tag)Read((int *)&local_14,1);
    std::vector<PowerHelper::PowerClass,std::allocator<PowerHelper::PowerClass>_>::
    _Resize<<lambda_4736c2bbb992635efbfd8efd81bfd98e>_>
              (pvVar6,local_14,(<lambda_4736c2bbb992635efbfd8efd81bfd98e>)pvVar6);
    this_08 = extraout_ECX_03;
    fVar10 = fVar9;
    if (local_14 == 0) {
LAB_4fc0bd9b:
      if (fVar10 == (forward_iterator_tag)0x0) goto LAB_4fc0c195;
    }
    else {
      if (!(bool)fVar9) {
LAB_4fc0bd93:
        fVar10 = (forward_iterator_tag)0x0;
        goto LAB_4fc0bd9b;
      }
      this_08 = (vector<PowerupHelper::PowerupClass,std::allocator<PowerupHelper::PowerupClass>_> *)
                (local_14 * 0x28);
      bVar8 = Read(*(void **)pvVar6,(int)this_08);
      if (!bVar8) goto LAB_4fc0bd93;
    }
    this_01 = &this_06->m_PowerupHelper->PowerupList;
    if (this_01 != &TempPowerupBuffer) {
      std::vector<PowerupHelper::PowerupClass,std::allocator<PowerupHelper::PowerupClass>_>::
      _Assign_range<PowerupHelper::PowerupClass_*>
                (this_08,*(PowerupClass **)this_01,*(PowerupClass **)&this_01->field_0x4,fVar9);
    }
    local_14 = 0;
    fVar9 = (forward_iterator_tag)Read((int *)&local_14,1);
    std::vector<PowerupHelper::PowerupClass,std::allocator<PowerupHelper::PowerupClass>_>::
    _Resize<<lambda_dcc549f59dec1aad2202dcbd5a8823fa>_>
              (this_01,local_14,(<lambda_dcc549f59dec1aad2202dcbd5a8823fa>)this_01);
    this_09 = extraout_ECX_04;
    fVar10 = fVar9;
    if (local_14 == 0) {
LAB_4fc0be07:
      if (fVar10 == (forward_iterator_tag)0x0) goto LAB_4fc0c195;
    }
    else {
      if (!(bool)fVar9) {
LAB_4fc0bdff:
        fVar10 = (forward_iterator_tag)0x0;
        goto LAB_4fc0be07;
      }
      this_09 = (vector<BuildingHelper::BuildingClass,std::allocator<BuildingHelper::BuildingClass>_>
                 *)(local_14 * 0x104);
      bVar8 = Read(*(void **)this_01,(int)this_09);
      if (!bVar8) goto LAB_4fc0bdff;
    }
    this_02 = &this_06->m_BuildingHelper->BuildingList;
    if (this_02 != &TempBuildingBuffer) {
      std::vector<BuildingHelper::BuildingClass,std::allocator<BuildingHelper::BuildingClass>_>::
      _Assign_range<BuildingHelper::BuildingClass_*>
                (this_09,*(BuildingClass **)this_02,*(BuildingClass **)&this_02->field_0x4,fVar9);
    }
    local_14 = 0;
    bVar8 = Read((int *)&local_14,1);
    std::vector<BuildingHelper::BuildingClass,std::allocator<BuildingHelper::BuildingClass>_>::
    _Resize<<lambda_ec97c231cece026f40cdadd6cbe85fc1>_>
              (this_02,local_14,(<lambda_ec97c231cece026f40cdadd6cbe85fc1>)this_02);
    if (local_14 == 0) {
LAB_4fc0be73:
      if (bVar8 == false) goto LAB_4fc0c195;
    }
    else if ((!bVar8) || (bVar8 = Read(*(void **)this_02,local_14 * 0x458), !bVar8)) {
      bVar8 = false;
      goto LAB_4fc0be73;
    }
    bVar8 = PortalHelper::Load(this_06->m_PortalHelper,(bool)uVar20);
    if (bVar8) {
      this_03 = &this_06->m_AttacherHelper->AttacherList;
      if (this_03 != &TempAttacherBuffer) {
        std::vector<AttacherHelper::AttacherClass,std::allocator<AttacherHelper::AttacherClass>_>::
        _Assign_range<AttacherHelper::AttacherClass_*>
                  (this_16,*(AttacherClass **)this_03,*(AttacherClass **)&this_03->field_0x4,
                   in_stack_00000008);
      }
      local_10 = (vector<VehicleHelper::VehicleClass,std::allocator<VehicleHelper::VehicleClass>_> *
                 )0x0;
      fVar9 = (forward_iterator_tag)Read((int *)&local_10,1);
      std::vector<AttacherHelper::AttacherClass,std::allocator<AttacherHelper::AttacherClass>_>::
      _Resize<<lambda_7ba5f03559cb281997e133de678b9134>_>
                (this_03,(uint)local_10,(<lambda_7ba5f03559cb281997e133de678b9134>)this_03);
      this_10 = extraout_ECX_05;
      fVar10 = fVar9;
      if (local_10 ==
          (vector<VehicleHelper::VehicleClass,std::allocator<VehicleHelper::VehicleClass>_> *)0x0) {
LAB_4fc0beef:
        if (fVar10 == (forward_iterator_tag)0x0) goto LAB_4fc0c195;
      }
      else {
        if (!(bool)fVar9) {
LAB_4fc0bee7:
          fVar10 = (forward_iterator_tag)0x0;
          goto LAB_4fc0beef;
        }
        this_10 = (vector<UtilityShipHelper::UtilityShipClass,std::allocator<UtilityShipHelper::UtilityShipClass>_>
                   *)((int)local_10 * 0x40c);
        bVar8 = Read(*(void **)this_03,(int)this_10);
        if (!bVar8) goto LAB_4fc0bee7;
      }
      this_04 = &this_06->m_UtilityShipHelper->UtilityShipList;
      if (this_04 != &TempUtilityShipBuffer) {
        std::
        vector<UtilityShipHelper::UtilityShipClass,std::allocator<UtilityShipHelper::UtilityShipClass>_>
        ::_Assign_range<UtilityShipHelper::UtilityShipClass_*>
                  (this_10,*(UtilityShipClass **)this_04,*(UtilityShipClass **)&this_04->field_0x4,
                   fVar9);
      }
      local_10 = (vector<VehicleHelper::VehicleClass,std::allocator<VehicleHelper::VehicleClass>_> *
                 )0x0;
      fVar9 = (forward_iterator_tag)Read((int *)&local_10,1);
      std::
      vector<UtilityShipHelper::UtilityShipClass,std::allocator<UtilityShipHelper::UtilityShipClass>_>
      ::_Resize<<lambda_c8a4f4cad98f6de524d7658fab4f9ded>_>
                (this_04,(uint)local_10,(<lambda_c8a4f4cad98f6de524d7658fab4f9ded>)this_04);
      this_11 = extraout_ECX_06;
      fVar10 = fVar9;
      if (local_10 ==
          (vector<VehicleHelper::VehicleClass,std::allocator<VehicleHelper::VehicleClass>_> *)0x0) {
LAB_4fc0bf58:
        if (fVar10 == (forward_iterator_tag)0x0) goto LAB_4fc0c195;
      }
      else {
        if (!(bool)fVar9) {
LAB_4fc0bf50:
          fVar10 = (forward_iterator_tag)0x0;
          goto LAB_4fc0bf58;
        }
        this_11 = (vector<ScrapHelper::ScrapClass,std::allocator<ScrapHelper::ScrapClass>_> *)
                  ((int)local_10 * 0x2c);
        bVar8 = Read(*(void **)this_04,(int)this_11);
        if (!bVar8) goto LAB_4fc0bf50;
      }
      this_05 = &this_06->m_ScrapHelper->ScrapList;
      if (this_05 != &TempScrapBuffer) {
        std::vector<ScrapHelper::ScrapClass,std::allocator<ScrapHelper::ScrapClass>_>::
        _Assign_range<ScrapHelper::ScrapClass_*>
                  (this_11,*(ScrapClass **)this_05,*(ScrapClass **)&this_05->field_0x4,fVar9);
      }
      local_10 = (vector<VehicleHelper::VehicleClass,std::allocator<VehicleHelper::VehicleClass>_> *
                 )0x0;
      fVar9 = (forward_iterator_tag)Read((int *)&local_10,1);
      std::vector<ScrapHelper::ScrapClass,std::allocator<ScrapHelper::ScrapClass>_>::
      _Resize<<lambda_5fdf7784746bcf490d41dbfe20fcbd69>_>
                (this_05,(uint)local_10,(<lambda_5fdf7784746bcf490d41dbfe20fcbd69>)this_05);
      this_12 = extraout_ECX_07;
      fVar10 = fVar9;
      if (local_10 ==
          (vector<VehicleHelper::VehicleClass,std::allocator<VehicleHelper::VehicleClass>_> *)0x0) {
LAB_4fc0bfc1:
        if (fVar10 == (forward_iterator_tag)0x0) goto LAB_4fc0c195;
      }
      else {
        if (!(bool)fVar9) {
LAB_4fc0bfb9:
          fVar10 = (forward_iterator_tag)0x0;
          goto LAB_4fc0bfc1;
        }
        this_12 = (vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>
                   *)((int)local_10 << 2);
        bVar8 = Read(*(void **)this_05,(int)this_12);
        if (!bVar8) goto LAB_4fc0bfb9;
      }
      this_17 = &this_06->m_DispatchHelper->DispatchList;
      if (this_17 != &TempDispatchBuffer) {
        std::vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>::
        _Assign_range<DispatchHelper::DispatchClass_*>
                  (this_12,*(DispatchClass **)this_17,
                   *(DispatchClass **)&(this_06->m_DispatchHelper->DispatchList).field_0x4,fVar9);
      }
      local_10 = (vector<VehicleHelper::VehicleClass,std::allocator<VehicleHelper::VehicleClass>_> *
                 )0x0;
      fVar9 = (forward_iterator_tag)Read((int *)&local_10,1);
      std::
      vector<MorphObjectHelper::MorphObjectClass,std::allocator<MorphObjectHelper::MorphObjectClass>_>
      ::_Resize<<lambda_6e1c0ab678e9364d699d8dd7ba7d9fb6>_>
                ((vector<MorphObjectHelper::MorphObjectClass,std::allocator<MorphObjectHelper::MorphObjectClass>_>
                  *)this_17,(uint)local_10,(<lambda_6e1c0ab678e9364d699d8dd7ba7d9fb6>)this_17);
      this_13 = extraout_ECX_08;
      fVar10 = fVar9;
      if (local_10 ==
          (vector<VehicleHelper::VehicleClass,std::allocator<VehicleHelper::VehicleClass>_> *)0x0) {
LAB_4fc0c030:
        if (fVar10 == (forward_iterator_tag)0x0) goto LAB_4fc0c195;
      }
      else {
        if (!(bool)fVar9) {
LAB_4fc0c028:
          fVar10 = (forward_iterator_tag)0x0;
          goto LAB_4fc0c030;
        }
        this_13 = (vector<UndeployHelper::UndeployClass,std::allocator<UndeployHelper::UndeployClass>_>
                   *)((int)local_10 * 0x148);
        bVar8 = Read(*(void **)this_17,(int)this_13);
        if (!bVar8) goto LAB_4fc0c028;
      }
      pvVar7 = (vector<BZ1Helper::AlignTerrainReplaceClass,std::allocator<BZ1Helper::AlignTerrainReplaceClass>_>
                *)this_06->m_UndeployHelper;
      if (pvVar7 != (vector<BZ1Helper::AlignTerrainReplaceClass,std::allocator<BZ1Helper::AlignTerrainReplaceClass>_>
                     *)&TempUndeployBuffer) {
        std::vector<UndeployHelper::UndeployClass,std::allocator<UndeployHelper::UndeployClass>_>::
        _Assign_range<UndeployHelper::UndeployClass_*>
                  (this_13,*(UndeployClass **)pvVar7,*(UndeployClass **)&pvVar7->field_0x4,fVar9);
      }
      local_10 = (vector<VehicleHelper::VehicleClass,std::allocator<VehicleHelper::VehicleClass>_> *
                 )0x0;
      fVar9 = (forward_iterator_tag)Read((int *)&local_10,1);
      std::
      vector<BZ1Helper::AlignTerrainReplaceClass,std::allocator<BZ1Helper::AlignTerrainReplaceClass>_>
      ::_Resize<<lambda_1855a80fc533c550b5607d8bf997ad95>_>
                (pvVar7,(uint)local_10,(<lambda_1855a80fc533c550b5607d8bf997ad95>)pvVar7);
      this_14 = extraout_ECX_09;
      fVar10 = fVar9;
      if (local_10 ==
          (vector<VehicleHelper::VehicleClass,std::allocator<VehicleHelper::VehicleClass>_> *)0x0) {
LAB_4fc0c099:
        if (fVar10 == (forward_iterator_tag)0x0) goto LAB_4fc0c195;
      }
      else {
        if (!(bool)fVar9) {
LAB_4fc0c091:
          fVar10 = (forward_iterator_tag)0x0;
          goto LAB_4fc0c099;
        }
        this_14 = (vector<MorphObjectHelper::MorphObjectClass,std::allocator<MorphObjectHelper::MorphObjectClass>_>
                   *)((int)local_10 << 4);
        bVar8 = Read(*(void **)pvVar7,(int)this_14);
        if (!bVar8) goto LAB_4fc0c091;
      }
      this_18 = &this_06->m_MorphObjectHelper->MorphObjectList;
      if (this_18 != &TempMorphObjectBuffer) {
        std::
        vector<MorphObjectHelper::MorphObjectClass,std::allocator<MorphObjectHelper::MorphObjectClass>_>
        ::_Assign_range<MorphObjectHelper::MorphObjectClass_*>
                  (this_14,*(MorphObjectClass **)this_18,
                   *(MorphObjectClass **)&(this_06->m_MorphObjectHelper->MorphObjectList).field_0x4,
                   fVar9);
      }
      local_10 = (vector<VehicleHelper::VehicleClass,std::allocator<VehicleHelper::VehicleClass>_> *
                 )0x0;
      bVar8 = Read((int *)&local_10,1);
      std::
      vector<MorphObjectHelper::MorphObjectClass,std::allocator<MorphObjectHelper::MorphObjectClass>_>
      ::_Resize<<lambda_6e1c0ab678e9364d699d8dd7ba7d9fb6>_>
                (this_18,(uint)local_10,(<lambda_6e1c0ab678e9364d699d8dd7ba7d9fb6>)this_18);
      if ((local_10 !=
           (vector<VehicleHelper::VehicleClass,std::allocator<VehicleHelper::VehicleClass>_> *)0x0)
         && (bVar8)) {
        Read(*(void **)this_18,(int)local_10 * 0x148);
      }
      bVar8 = CarrierHelper::Load(this_06->m_CarrierHelper,(bool)uVar21);
      if ((((((bVar8) && (bVar8 = GravityHelper::Load(this_06->m_GravityHelper,false), bVar8)) &&
            (bVar8 = AmbientSoundHelper::Load(this_06->m_AmbientSoundHelper,false), bVar8)) &&
           ((bVar8 = Read(&m_TurnCounter,1), bVar8 && (bVar8 = Read(&TotalMapObjects,1), bVar8))))
          && ((bVar8 = Read(&OffMapPos,0xc), bVar8 &&
              ((bVar8 = Read(&WorldSetting,1), bVar8 && (bVar8 = Read(&m_GameType,1), bVar8)))))) &&
         ((bVar8 = Read(&m_GameVersion,1), bVar8 && (bVar8 = Read(&m_ModVersion,1), bVar8))))
      goto LAB_4fc0c19a;
    }
  }
LAB_4fc0c195:
  local_4 = (BZ1Helper *)((uint)local_4 & 0xffffff00);
LAB_4fc0c19a:
  SetGravity((this_06->mapInfo).Gravity);
  Setup(this_06);
  return (bool)local_4._0_1_;
}


// ---------------------------------------------------------------------
// BZ1Helper::PostLoad  @ 4fc0c1bd  lines 549-697


bool __thiscall BZ1Helper::PostLoad(BZ1Helper *this,bool param_1)

{
  bool bVar1;
  undefined4 unaff_EBX;
  undefined4 unaff_EBP;
  TeamInfo *unaff_ESI;
  int *piVar2;
  TeamInfo *pTVar3;
  int iVar4;
  TeamInfo **ppTVar5;
  TeamInfo *unaff_EDI;
  int iVar6;
  undefined1 uVar7;
  undefined4 unaff_retaddr;
  bool in_stack_00000008;
  undefined1 uVar8;
  undefined1 uVar9;
  uint uStack_14;
  char cStack_11;
  undefined1 uVar10;
  TeamInfo *pTVar11;
  undefined1 uVar12;
  BZ1Helper *pBVar13;
  BZ1Helper *pBVar14;
  undefined1 uVar15;
  undefined4 in_stack_fffffff8;
  undefined1 uVar16;
  
  if (param_1) {
    return true;
  }
  pBVar13 = this;
  bVar1 = ObjectHelper::PostLoad(this->m_ObjectHelper,SUB41(this,0));
  if (bVar1) {
    bVar1 = VehicleHelper::PostLoad(this->m_VehicleHelper,true);
    uStack_14 = CONCAT13(1,(undefined3)uStack_14);
    if (bVar1) goto LAB_4fc0c205;
  }
  uStack_14 = uStack_14 & 0xffffff;
LAB_4fc0c205:
  piVar2 = *(int **)(this[1].teamInfo[0].PilotWeapon[2] + 7);
  if (piVar2 != *(int **)(this[1].teamInfo[0].PilotWeapon[2] + 0xb)) {
    do {
      ConvertHandles(piVar2,1);
      piVar2 = piVar2 + 4;
    } while (piVar2 != *(int **)(this[1].teamInfo[0].PilotWeapon[2] + 0xb));
  }
  for (piVar2 = *(int **)(this[1].teamInfo[0].PilotWeapon[2] + 0x13);
      piVar2 != *(int **)(this[1].teamInfo[0].PilotWeapon[2] + 0x17); piVar2 = piVar2 + 2) {
    ConvertHandles(piVar2,1);
  }
  for (piVar2 = *(int **)(this[1].teamInfo[0].PilotWeapon[2] + 0x1f);
      piVar2 != *(int **)(this[1].teamInfo[0].PilotWeapon[2] + 0x23); piVar2 = piVar2 + 0x16) {
    ConvertHandles(piVar2,1);
  }
  for (piVar2 = *(int **)(this[1].teamInfo[0].PilotWeapon[2] + 0x2b);
      piVar2 != *(int **)(this[1].teamInfo[0].PilotWeapon[2] + 0x2f); piVar2 = piVar2 + 7) {
    ConvertHandles(piVar2,1);
  }
  pTVar3 = this->teamInfo;
  iVar6 = 0x10;
  pTVar11 = pTVar3;
  do {
    ConvertHandles(&pTVar3->RealPlayer,0x24);
    pTVar3 = (TeamInfo *)&pTVar3[1].CommTower;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  pBVar14 = pBVar13;
  bVar1 = ::operator==((MapInfo *)unaff_EDI,(MapInfo *)unaff_ESI);
  if (!bVar1) {
    FormatLogMessage("MapInfo Load Mismatch");
  }
  iVar6 = *(int *)(pBVar13[1].teamInfo[0].PilotWeapon[2] + 0xb) -
          *(int *)(pBVar13[1].teamInfo[0].PilotWeapon[2] + 7) >> 4;
  if ((int)(TempAlignBuffer._4_4_ - TempAlignBuffer._0_4_) >> 4 == iVar6) {
    iVar4 = 0;
    if (0 < iVar6) {
      do {
        bVar1 = ::operator==((AlignTerrainReplaceClass *)unaff_EDI,
                             (AlignTerrainReplaceClass *)unaff_ESI);
        if (!bVar1) {
          FormatLogMessage("AlignTerrainReplaceList Index Mismatch: %d");
          break;
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < *(int *)(pBVar13[1].teamInfo[0].PilotWeapon[2] + 0xb) -
                       *(int *)(pBVar13[1].teamInfo[0].PilotWeapon[2] + 7) >> 4);
    }
  }
  else {
    FormatLogMessage("AlignTerrainReplaceList Size Mismatch! Old: %d New: %d");
  }
  iVar6 = *(int *)(pBVar13[1].teamInfo[0].PilotWeapon[2] + 0x17) -
          *(int *)(pBVar13[1].teamInfo[0].PilotWeapon[2] + 0x13) >> 3;
  if ((int)(TempDeleteBuffer._4_4_ - TempDeleteBuffer._0_4_) >> 3 == iVar6) {
    iVar4 = 0;
    if (0 < iVar6) {
      do {
        bVar1 = ::operator==((DeleteAfterDelayClass *)unaff_EDI,(DeleteAfterDelayClass *)unaff_ESI);
        if (!bVar1) {
          FormatLogMessage("DeleteAfterDelayList Index Mismatch: %d");
          break;
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < *(int *)(pBVar13[1].teamInfo[0].PilotWeapon[2] + 0x17) -
                       *(int *)(pBVar13[1].teamInfo[0].PilotWeapon[2] + 0x13) >> 3);
    }
  }
  else {
    FormatLogMessage("DeleteAfterDelayList Size Mismatch! Old: %d New: %d");
  }
  iVar6 = (*(int *)(pBVar13[1].teamInfo[0].PilotWeapon[2] + 0x23) -
          *(int *)(pBVar13[1].teamInfo[0].PilotWeapon[2] + 0x1f)) / 0x58;
  if ((int)(TempDeploySoundBuffer._4_4_ - TempDeploySoundBuffer._0_4_) / 0x58 == iVar6) {
    iVar4 = 0;
    if (0 < iVar6) {
      do {
        bVar1 = ::operator==((DeploySoundClass *)unaff_EDI,(DeploySoundClass *)unaff_ESI);
        if (!bVar1) {
          FormatLogMessage("DeploySoundList Index Mismatch: %d");
          break;
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < (*(int *)(pBVar13[1].teamInfo[0].PilotWeapon[2] + 0x23) -
                       *(int *)(pBVar13[1].teamInfo[0].PilotWeapon[2] + 0x1f)) / 0x58);
    }
  }
  else {
    FormatLogMessage("DeploySoundList Size Mismatch! Old: %d New: %d");
  }
  iVar6 = (*(int *)(pBVar13[1].teamInfo[0].PilotWeapon[2] + 0x2f) -
          *(int *)(pBVar13[1].teamInfo[0].PilotWeapon[2] + 0x2b)) / 0x1c;
  if ((int)(TempBuiltAtBuffer._4_4_ - TempBuiltAtBuffer._0_4_) / 0x1c == iVar6) {
    iVar4 = 0;
    if (0 < iVar6) {
      do {
        bVar1 = ::operator==((BuildAtClass *)unaff_EDI,(BuildAtClass *)unaff_ESI);
        if (!bVar1) {
          FormatLogMessage("BuildAtList Index Mismatch: %d");
          break;
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < (*(int *)(pBVar13[1].teamInfo[0].PilotWeapon[2] + 0x2f) -
                       *(int *)(pBVar13[1].teamInfo[0].PilotWeapon[2] + 0x2b)) / 0x1c);
    }
  }
  else {
    FormatLogMessage("BuildAtList Size Mismatch! Old: %d New: %d");
  }
  ppTVar5 = &TempTeamInfoBuffer;
  do {
    bVar1 = ::operator==(unaff_EDI,unaff_ESI);
    uVar12 = SUB41(pBVar14,0);
    uVar10 = SUB41(pTVar11,0);
    uVar7 = (undefined1)unaff_retaddr;
    uVar16 = (undefined1)unaff_EBP;
    uVar15 = (undefined1)in_stack_fffffff8;
    uVar9 = (undefined1)unaff_EBX;
    if (!bVar1) {
      FormatLogMessage("TeamInfo Load Mismatch Team: %d");
      break;
    }
    pTVar11 = (TeamInfo *)&pTVar11[1].CommTower;
    uVar10 = SUB41(pTVar11,0);
    ppTVar5 = ppTVar5 + 0x285;
  } while ((int)ppTVar5 < 0x4fc7a6b0);
  uVar8 = SUB41(unaff_ESI,0);
  if (((((cStack_11 == '\0') ||
        (bVar1 = PowerHelper::PostLoad(pBVar13->m_PowerHelper,SUB41(unaff_EDI,0)), !bVar1)) ||
       (bVar1 = PowerupHelper::PostLoad(pBVar13->m_PowerupHelper,(bool)uVar8), !bVar1)) ||
      ((((bVar1 = BuildingHelper::PostLoad(pBVar13->m_BuildingHelper,(bool)uVar9), !bVar1 ||
         (bVar1 = PortalHelper::PostLoad(pBVar13->m_PortalHelper,SUB41(uStack_14,0)), !bVar1)) ||
        ((bVar1 = AttacherHelper::PostLoad(pBVar13->m_AttacherHelper,(bool)uVar10), !bVar1 ||
         ((bVar1 = UtilityShipHelper::PostLoad(pBVar13->m_UtilityShipHelper,(bool)uVar12), !bVar1 ||
          (bVar1 = ScrapHelper::PostLoad(pBVar13->m_ScrapHelper,(bool)uVar15), !bVar1)))))) ||
       (bVar1 = DispatchHelper::PostLoad(pBVar13->m_DispatchHelper,(bool)uVar16), !bVar1)))) ||
     (((bVar1 = UndeployHelper::PostLoad(pBVar13->m_UndeployHelper,(bool)uVar7), !bVar1 ||
       (bVar1 = MorphObjectHelper::PostLoad(pBVar13->m_MorphObjectHelper,false), !bVar1)) ||
      (bVar1 = CarrierHelper::PostLoad(pBVar13->m_CarrierHelper,in_stack_00000008), !bVar1)))) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  return bVar1;
}


// ---------------------------------------------------------------------
// BZ1Helper::Save  @ 4fc0c58f  lines 701-811


bool __thiscall BZ1Helper::Save(BZ1Helper *this,bool param_1)

{
  bool *pbVar1;
  float *pfVar2;
  int *piVar3;
  AttacherHelper *pAVar4;
  UtilityShipHelper *pUVar5;
  ScrapHelper *pSVar6;
  DispatchHelper *pDVar7;
  UndeployHelper *pUVar8;
  bool bVar9;
  bool extraout_CL;
  undefined4 unaff_EBP;
  TeamInfo *pTVar10;
  GravityInfo *pGVar11;
  AmbientAudioInfo *pAVar12;
  undefined4 unaff_EDI;
  MorphObjectHelper *pMVar13;
  undefined3 in_stack_00000005;
  undefined1 uVar14;
  undefined1 uVar15;
  int local_c;
  int local_8;
  BuildingHelper *local_4;
  
  if (param_1) {
    return true;
  }
  uVar14 = 0x48;
  bVar9 = Write(&this->mapInfo,0x48);
  if (((bVar9) && (bVar9 = ObjectHelper::Save(this->m_ObjectHelper,(bool)uVar14), bVar9)) &&
     (bVar9 = VehicleHelper::Save(this->m_VehicleHelper,extraout_CL), bVar9)) {
    bVar9 = true;
  }
  else {
    bVar9 = false;
  }
  _param_1 = *(int *)(this[1].teamInfo[0].PilotWeapon[2] + 0xb) -
             *(int *)(this[1].teamInfo[0].PilotWeapon[2] + 7) >> 4;
  if ((bVar9) && (bVar9 = Write((int *)&param_1,1), bVar9)) {
    bVar9 = true;
  }
  else {
    bVar9 = false;
  }
  if (_param_1 != 0) {
    if ((bVar9) &&
       (bVar9 = Write(*(void **)(this[1].teamInfo[0].PilotWeapon[2] + 7),_param_1 << 4), bVar9)) {
      bVar9 = true;
    }
    else {
      bVar9 = false;
    }
  }
  _param_1 = *(int *)(this[1].teamInfo[0].PilotWeapon[2] + 0x17) -
             *(int *)(this[1].teamInfo[0].PilotWeapon[2] + 0x13) >> 3;
  if ((bVar9) && (bVar9 = Write((int *)&param_1,1), bVar9)) {
    bVar9 = true;
  }
  else {
    bVar9 = false;
  }
  if (_param_1 != 0) {
    if ((bVar9) &&
       (bVar9 = Write(*(void **)(this[1].teamInfo[0].PilotWeapon[2] + 0x13),_param_1 << 3), bVar9))
    {
      bVar9 = true;
    }
    else {
      bVar9 = false;
    }
  }
  _param_1 = (*(int *)(this[1].teamInfo[0].PilotWeapon[2] + 0x23) -
             *(int *)(this[1].teamInfo[0].PilotWeapon[2] + 0x1f)) / 0x58;
  if ((bVar9) && (bVar9 = Write((int *)&param_1,1), bVar9)) {
    bVar9 = true;
  }
  else {
    bVar9 = false;
  }
  if (_param_1 != 0) {
    if ((bVar9) &&
       (bVar9 = Write(*(void **)(this[1].teamInfo[0].PilotWeapon[2] + 0x1f),_param_1 * 0x58), bVar9)
       ) {
      bVar9 = true;
    }
    else {
      bVar9 = false;
    }
  }
  _param_1 = (*(int *)(this[1].teamInfo[0].PilotWeapon[2] + 0x2f) -
             *(int *)(this[1].teamInfo[0].PilotWeapon[2] + 0x2b)) / 0x1c;
  if ((bVar9) && (bVar9 = Write((int *)&param_1,1), bVar9)) {
    bVar9 = true;
  }
  else {
    bVar9 = false;
  }
  if (_param_1 != 0) {
    if ((bVar9) &&
       (bVar9 = Write(*(void **)(this[1].teamInfo[0].PilotWeapon[2] + 0x2b),_param_1 * 0x1c), bVar9)
       ) {
      bVar9 = true;
    }
    else {
      bVar9 = false;
    }
  }
  pTVar10 = this->teamInfo;
  local_8 = 0x10;
  local_c = 0x10;
  do {
    if ((bVar9) && (bVar9 = Write(pTVar10,0xa14), bVar9)) {
      bVar9 = true;
    }
    else {
      bVar9 = false;
    }
    uVar15 = (undefined1)unaff_EBP;
    uVar14 = (undefined1)unaff_EDI;
    pTVar10 = (TeamInfo *)&pTVar10[1].CommTower;
    local_c = local_c + -1;
  } while (local_c != 0);
  pbVar1 = *(bool **)(this[1].teamInfo[0].PilotWeapon[4] + 0x3f);
  if (pbVar1 != (bool *)0x0) {
    if ((bVar9) && (bVar9 = Write(pbVar1,*(int *)(this[1].teamInfo[0].PlayerPilotODF + 3)), bVar9))
    {
      bVar9 = true;
    }
    else {
      bVar9 = false;
    }
  }
  pfVar2 = *(float **)(this[1].teamInfo[0].PlayerPilotODF + 7);
  if (pfVar2 != (float *)0x0) {
    if ((bVar9) && (bVar9 = Write(pfVar2,*(int *)(this[1].teamInfo[0].PlayerPilotODF + 0xb)), bVar9)
       ) {
      bVar9 = true;
    }
    else {
      bVar9 = false;
    }
  }
  piVar3 = *(int **)(this[1].teamInfo[0].PlayerPilotODF + 0xf);
  if (piVar3 == (int *)0x0) {
LAB_4fc0c7e4:
    if (!bVar9) {
      return false;
    }
  }
  else if ((!bVar9) ||
          (bVar9 = Write(piVar3,*(int *)(this[1].teamInfo[0].PlayerPilotODF + 0x13)), !bVar9)) {
    bVar9 = false;
    goto LAB_4fc0c7e4;
  }
  local_4 = (BuildingHelper *)this->m_PowerHelper;
  local_c = (*(int *)&(((PowerHelper *)local_4)->PowerList).field_0x4 -
            *(int *)&((PowerHelper *)local_4)->PowerList) / 0x28;
  bVar9 = Write(&local_c,1);
  if (local_c == 0) {
LAB_4fc0c831:
    if (bVar9 == false) {
      return false;
    }
  }
  else if ((!bVar9) || (bVar9 = Write(*(void **)&local_4->BuildingList,local_c * 0x28), !bVar9)) {
    bVar9 = false;
    goto LAB_4fc0c831;
  }
  local_4 = (BuildingHelper *)this->m_PowerupHelper;
  local_c = (*(int *)&(((PowerupHelper *)local_4)->PowerupList).field_0x4 -
            *(int *)&((PowerupHelper *)local_4)->PowerupList) / 0x104;
  bVar9 = Write(&local_c,1);
  if (local_c == 0) {
LAB_4fc0c883:
    if (bVar9 == false) {
      return false;
    }
  }
  else if ((!bVar9) || (bVar9 = Write(*(void **)&local_4->BuildingList,local_c * 0x104), !bVar9)) {
    bVar9 = false;
    goto LAB_4fc0c883;
  }
  local_4 = this->m_BuildingHelper;
  local_c = (*(int *)&(local_4->BuildingList).field_0x4 - *(int *)&local_4->BuildingList) / 0x458;
  bVar9 = Write(&local_c,1);
  if (local_c == 0) {
LAB_4fc0c8d5:
    if (bVar9 == false) {
      return false;
    }
  }
  else if ((!bVar9) || (bVar9 = Write(*(void **)&local_4->BuildingList,local_c * 0x458), !bVar9)) {
    bVar9 = false;
    goto LAB_4fc0c8d5;
  }
  bVar9 = PortalHelper::Save(this->m_PortalHelper,(bool)uVar14);
  if (!bVar9) {
    return false;
  }
  pAVar4 = this->m_AttacherHelper;
  local_8 = (*(int *)&(pAVar4->AttacherList).field_0x4 - *(int *)&pAVar4->AttacherList) / 0x40c;
  bVar9 = Write(&local_8,1);
  if (local_8 == 0) {
LAB_4fc0c937:
    if (bVar9 == false) {
      return false;
    }
  }
  else if ((!bVar9) || (bVar9 = Write(*(void **)&pAVar4->AttacherList,local_8 * 0x40c), !bVar9)) {
    bVar9 = false;
    goto LAB_4fc0c937;
  }
  pUVar5 = this->m_UtilityShipHelper;
  local_8 = (*(int *)&(pUVar5->UtilityShipList).field_0x4 - *(int *)&pUVar5->UtilityShipList) / 0x2c
  ;
  bVar9 = Write(&local_8,1);
  if (local_8 == 0) {
LAB_4fc0c984:
    if (bVar9 == false) {
      return false;
    }
  }
  else if ((!bVar9) || (bVar9 = Write(*(void **)&pUVar5->UtilityShipList,local_8 * 0x2c), !bVar9)) {
    bVar9 = false;
    goto LAB_4fc0c984;
  }
  pSVar6 = this->m_ScrapHelper;
  local_8 = *(int *)&(pSVar6->ScrapList).field_0x4 - *(int *)&pSVar6->ScrapList >> 2;
  bVar9 = Write(&local_8,1);
  if (local_8 == 0) {
LAB_4fc0c9d0:
    if (bVar9 == false) {
      return false;
    }
  }
  else if ((!bVar9) || (bVar9 = Write(*(void **)&pSVar6->ScrapList,local_8 << 2), !bVar9)) {
    bVar9 = false;
    goto LAB_4fc0c9d0;
  }
  pDVar7 = this->m_DispatchHelper;
  local_8 = (*(int *)&(pDVar7->DispatchList).field_0x4 - *(int *)&pDVar7->DispatchList) / 0x148;
  bVar9 = Write(&local_8,1);
  if (local_8 == 0) {
LAB_4fc0ca24:
    if (bVar9 == false) {
      return false;
    }
  }
  else if ((!bVar9) || (bVar9 = Write(*(void **)&pDVar7->DispatchList,local_8 * 0x148), !bVar9)) {
    bVar9 = false;
    goto LAB_4fc0ca24;
  }
  pUVar8 = this->m_UndeployHelper;
  local_8 = *(int *)&(pUVar8->UndeployList).field_0x4 - *(int *)&pUVar8->UndeployList >> 4;
  bVar9 = Write(&local_8,1);
  if (local_8 == 0) {
LAB_4fc0ca6e:
    if (bVar9 == false) {
      return false;
    }
  }
  else if ((!bVar9) || (bVar9 = Write(*(void **)&pUVar8->UndeployList,local_8 << 4), !bVar9)) {
    bVar9 = false;
    goto LAB_4fc0ca6e;
  }
  pMVar13 = this->m_MorphObjectHelper;
  local_8 = (*(int *)&(pMVar13->MorphObjectList).field_0x4 - *(int *)&pMVar13->MorphObjectList) /
            0x148;
  bVar9 = Write(&local_8,1);
  if (local_8 != 0) {
    if ((bVar9) && (bVar9 = Write(*(void **)&pMVar13->MorphObjectList,local_8 * 0x148), bVar9))
    goto LAB_4fc0caca;
    bVar9 = false;
  }
  if (bVar9 == false) {
    return false;
  }
LAB_4fc0caca:
  bVar9 = CarrierHelper::Save(this->m_CarrierHelper,(bool)uVar15);
  if (bVar9) {
    pGVar11 = this->m_GravityHelper->gravityInfo;
    bVar9 = true;
    do {
      if ((bVar9) && (bVar9 = Write(pGVar11,0x14), bVar9)) {
        bVar9 = true;
      }
      else {
        bVar9 = false;
      }
      pGVar11 = pGVar11 + 1;
      pMVar13 = (MorphObjectHelper *)&pMVar13[-1].MorphObjectList.field_0xb;
    } while (pMVar13 != (MorphObjectHelper *)0x0);
    if (bVar9) {
      pAVar12 = this->m_AmbientSoundHelper->ambientAudioInfo;
      bVar9 = true;
      local_4 = (BuildingHelper *)0x20;
      do {
        if ((bVar9) && (bVar9 = Write(pAVar12,0x70), bVar9)) {
          bVar9 = true;
        }
        else {
          bVar9 = false;
        }
        pAVar12 = pAVar12 + 1;
        local_4 = (BuildingHelper *)((int)local_4 + -1);
      } while (local_4 != (BuildingHelper *)0x0);
      if (((((bVar9) && (bVar9 = Write(&m_TurnCounter,1), bVar9)) &&
           (bVar9 = Write(&TotalMapObjects,1), bVar9)) &&
          ((bVar9 = Write(&OffMapPos,0xc), bVar9 && (bVar9 = Write(&WorldSetting,1), bVar9)))) &&
         ((bVar9 = Write(&m_GameType,1), bVar9 &&
          ((bVar9 = Write(&m_GameVersion,1), bVar9 && (bVar9 = Write(&m_ModVersion,1), bVar9)))))) {
        return true;
      }
    }
  }
  return false;
}


// ---------------------------------------------------------------------
// BZ1Helper::AddObject  @ 4fc0cbb6  lines 817-1524


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall BZ1Helper::AddObject(BZ1Helper *this,int param_1)

{
  vector<BZ1Helper::DeploySoundClass,std::allocator<BZ1Helper::DeploySoundClass>_> *this_00;
  Vector VVar1;
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
  int *piVar12;
  int *piVar13;
  char *unaff_EBX;
  bool *unaff_ESI;
  vector<ObjectHelper::ObjectClass,std::allocator<ObjectHelper::ObjectClass>_> *pvVar14;
  float *pfVar15;
  int *piVar16;
  vector<VehicleHelper::VehicleClass,std::allocator<VehicleHelper::VehicleClass>_> *pvVar17;
  float *unaff_EDI;
  BZ1Helper *pBVar18;
  char cVar19;
  float fVar20;
  char *pcVar21;
  char *pcVar22;
  char *pcVar23;
  char *pcVar24;
  Vector *pVVar25;
  Matrix *pMVar26;
  size_t sVar27;
  AIWeaponHelper *this_01;
  undefined1 auStack_254 [6];
  char local_24e [2];
  undefined4 local_24c;
  vector<VehicleHelper::VehicleClass,std::allocator<VehicleHelper::VehicleClass>_> *local_248;
  char cStack_242;
  char cStack_241;
  undefined4 local_240;
  BZ1Helper *local_23c;
  vector<ObjectHelper::ObjectClass,std::allocator<ObjectHelper::ObjectClass>_> *local_238;
  uint local_234;
  undefined4 local_230;
  float local_22c;
  uint local_228;
  char *local_224;
  char *local_220;
  int local_21c;
  uint local_218;
  int local_214;
  int local_210;
  int local_20c;
  long local_208;
  float local_204;
  Vector local_200;
  Vector local_1f4;
  int local_1e8;
  float *local_1e4;
  int local_1e0;
  Matrix local_1dc;
  char local_190 [4];
  char local_18c [60];
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
  if (this[1].teamInfo[0].PilotWeapon[4][0x20] != '\0') {
    return;
  }
  memset(local_90,0,0x40);
  bVar5 = GetObjInfo(param_1,Get_GOClass,local_90);
  if (!bVar5) {
    return;
  }
  uVar7 = Hash((char *)unaff_EDI,(uint)unaff_ESI);
  local_228 = uVar7;
  cStack_241 = IsNetworkOn();
  memset(local_110,0,0x40);
  GetODFName((int)unaff_EDI,unaff_ESI);
  local_218 = Hash((char *)unaff_EDI,(uint)unaff_ESI);
  local_24c = GetTeamNum(param_1);
  local_238 = (vector<ObjectHelper::ObjectClass,std::allocator<ObjectHelper::ObjectClass>_> *)
              0xffffffff;
  local_210 = 0x5c;
  pvVar11 = local_238;
  if (uVar7 == 0x6ee4c53d) {
    if (cStack_241 != '\0') {
      SetRandomHeadingAngle2((int)unaff_EDI);
      pvVar11 = local_238;
    }
  }
  else {
    pvVar14 = (vector<ObjectHelper::ObjectClass,std::allocator<ObjectHelper::ObjectClass>_> *)0x0;
    piVar16 = *(int **)&this->m_ObjectHelper->HandleList;
    iVar8 = (*(int *)&(this->m_ObjectHelper->HandleList).field_0x4 - (int)piVar16) / 0x5c;
    if (0 < iVar8) {
      do {
        if (*piVar16 == param_1) {
          pvVar11 = pvVar14;
          if (piVar16[1] == local_218) {
            FormatLogMessage(
                            "FIXME: AddObject Skipping Duplicate: %08x, ODF: \'%s\', Team is: %d, Index is: %d"
                            );
            return;
          }
          break;
        }
        pvVar14 = (vector<ObjectHelper::ObjectClass,std::allocator<ObjectHelper::ObjectClass>_> *)
                  &pvVar14->field_0x1;
        piVar16 = piVar16 + 0x17;
      } while ((int)pvVar14 < iVar8);
    }
  }
  local_238 = pvVar11;
  OffMapPos.x = -4000.0;
  OffMapPos.z = -4000.0;
  OffMapPos.y = TerrainFindFloor(___real_c57a0000,___real_c57a0000);
  memset(local_190,0,0x40);
  memset(&local_1dc.rightw,0,0x40);
  GetAndOpenODFNames((int)&local_1dc.rightw,(char *)0x0,(char *)unaff_EDI,unaff_ESI);
  GetPosition(param_1,&local_200);
  memset(local_50,0,0x40);
  GetODFString("GameObjectClass","BZCClasslabel",(char *)0x40,local_50,0,(char *)unaff_EDI,unaff_ESI
              );
  local_234 = Hash((char *)unaff_EDI,(uint)unaff_ESI);
  local_224 = GetLabel(param_1);
  local_208 = GetMaxHealth(param_1);
  local_22c = (float)GetMaxAmmo(param_1);
  local_1e0 = GetCategoryTypeOverride(param_1);
  if (local_1e0 == -1) {
    local_1e0 = GetCategoryType(param_1);
  }
  if (8 < local_1e0 - 1U) {
    local_1e0 = 0;
  }
  iVar8 = local_24c;
  if ((((this[1].teamInfo[0].PilotWeapon[4][0x18] == '\0') && (0 < local_24c)) &&
      (bVar5 = IsPlayer(param_1), iVar8 = local_24c, !bVar5)) &&
     (((cStack_241 != '\0' &&
       ((iVar8 = GetVarItemInt("network.session.ivar53"), iVar8 == 2 ||
        (iVar8 = GetVarItemInt("network.session.ivar12"), iVar8 == 1)))) ||
      (iVar9 = IFace_GetInteger("options.instant.awarev13"), iVar8 = local_24c, iVar9 != 0)))) {
    iVar9 = 0;
    iVar8 = local_24c;
    do {
      if ((*(int *)((int)m_SwitchTeamA + iVar9) == iVar8) &&
         (*(int *)((int)m_SwitchTeamA + iVar9) != *(int *)((int)m_SwitchTeamB + iVar9))) {
        SetTeamNum(param_1,*(int *)((int)m_SwitchTeamB + iVar9));
        iVar8 = *(int *)((int)m_SwitchTeamB + iVar9);
      }
      iVar9 = iVar9 + 4;
    } while (iVar9 < 0x40);
  }
  local_24c = iVar8;
  if (0 < local_208) {
    piVar16 = (int *)((int)this->teamInfo + local_24c * 0xa14 + 0xc0);
    *piVar16 = *piVar16 + 1;
  }
  memset(local_d0,0,0x40);
  GetODFString("GameObjectClass","unitName2",(char *)0x40,local_d0,0,(char *)unaff_EDI,unaff_ESI);
  if (local_d0[0] != '\0') {
    SetObjectiveName(param_1,local_d0);
  }
  local_204 = 0.0;
  iVar8 = GetODFFloat("GameObjectClass","HeightOffset",(char *)&local_204,(char *)0x0,unaff_EDI,
                      (float)unaff_ESI);
  if ((iVar8 != 0) && (local_204 != 0.0)) {
    local_200.x = local_200.x + 0.0;
    local_200.y = local_200.y + local_204;
    local_200.z = local_200.z + 0.0;
    this = local_23c;
    local_1f4.x = local_200.x;
    local_1f4.y = local_200.y;
    local_1f4.z = local_200.z;
  }
  cStack_242 = '\0';
  if (m_TurnCounter < 1) {
LAB_4fc0d085:
    if (local_204 != ___real_00000000) goto LAB_4fc0d092;
  }
  else {
    iVar8 = GetODFBool("GameObjectClass","AlignToTerrain",&cStack_242,(char *)0x0,(bool *)unaff_EDI,
                       SUB41(unaff_ESI,0));
    if (iVar8 != 0) {
      if (cStack_242 == '\0') goto LAB_4fc0d085;
      local_1f4.x = 0.0;
      local_1f4.y = 0.0;
      local_1f4.z = 0.0;
      piVar16 = *(int **)(this[1].teamInfo[0].PilotWeapon[2] + 7);
      local_220 = (char *)0x0;
      piVar13 = *(int **)(this[1].teamInfo[0].PilotWeapon[2] + 0xb);
      for (piVar12 = piVar16; piVar12 != piVar13; piVar12 = piVar12 + 4) {
        if (*piVar12 == param_1) {
          iVar8 = (int)piVar12 - (int)piVar16 >> 4;
          if (-1 < iVar8) {
            pfVar15 = (float *)(piVar16 + iVar8 * 4 + 1);
            piVar16 = piVar16 + iVar8 * 4;
            local_1f4.x = *pfVar15;
            local_1f4.y = pfVar15[1];
            local_1f4.z = pfVar15[2];
            memmove(piVar16,piVar16 + 4,(int)piVar13 - (int)(piVar16 + 4));
            pcVar23 = local_23c[1].teamInfo[0].PilotWeapon[2] + 0xb;
            *(int *)pcVar23 = *(int *)pcVar23 + -0x10;
            goto LAB_4fc0d03a;
          }
          break;
        }
      }
      TerrainGetHeightAndNormal(&local_200,(float *)&local_220,&local_1f4,false);
LAB_4fc0d03a:
      pMVar26 = &local_1dc;
      pVVar25 = (Vector *)param_1;
      GetFront(param_1,&pMVar26->right);
      Build_Orthogonal_Matrix(&local_1dc,&local_200,pVVar25,&pMVar26->right);
      SetPosition(param_1,&local_150);
    }
    if (cStack_242 == '\0') goto LAB_4fc0d085;
LAB_4fc0d092:
    VVar2.y = local_200.y;
    VVar2.x = local_200.x;
    VVar2.z = local_200.z;
    SetVectorPosition(param_1,VVar2);
  }
  local_21c = 0;
  local_20c = GetNumWeapons((int)unaff_EDI);
  uVar7 = local_228;
  pBVar18 = local_23c;
  if (local_228 == 0x6ee4c53d) {
    ScrapHelper::AddScrapObject
              (local_23c->m_ScrapHelper,param_1,local_190,(char *)&local_1dc.rightw,
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
      sVar27 = 0x5c;
      iVar8 = 0;
      pvVar10 = operator_new(0,(void *)0x5c);
      memset(pvVar10,iVar8,sVar27);
      *(int *)&local_238->field_0x4 = *(int *)&local_238->field_0x4 + 0x5c;
    }
    pvVar11 = (vector<ObjectHelper::ObjectClass,std::allocator<ObjectHelper::ObjectClass>_> *)
              ((*(int *)&local_238->field_0x4 - *(int *)local_238) / 0x5c + -1);
  }
  piVar16 = (int *)((int)pvVar11 * 0x5c + *(int *)&pBVar18->m_ObjectHelper->HandleList);
  local_240 = piVar16;
  memset(piVar16,0,0x5c);
  piVar16[1] = local_218;
  piVar16[3] = local_234;
  piVar16[0x15] = local_208;
  piVar16[2] = uVar7;
  piVar16[0x16] = (int)local_22c;
  bVar5 = IsCraft((int)unaff_EDI,(int)unaff_ESI);
  if (bVar5) {
    piVar16[4] = 1;
  }
  else {
    bVar5 = IsBuildingOrGunTower((int)unaff_EDI,(int)unaff_ESI);
    if (bVar5) {
      piVar16[4] = 2;
    }
    else {
      bVar5 = IsPerson(param_1);
      if (bVar5) {
        piVar16[4] = 4;
      }
      else {
        bVar5 = IsPowerup(param_1);
        if (bVar5) {
          piVar16[4] = 8;
        }
        else {
          bVar5 = IsWeapon((int)unaff_EDI,(int)unaff_ESI);
          if (bVar5) {
            piVar16[4] = 0x10;
          }
          else {
            if (uVar7 == 0) {
              memset(&local_150,0,0x40);
              bVar5 = GetObjInfo(param_1,Get_GOClass,(char *)&local_150);
              if ((bVar5) && (iVar8 = _stricmp((char *)&local_150,"CLASS_SCRAP"), iVar8 == 0)) {
                piVar16[4] = 0x20;
                goto LAB_4fc0d27a;
              }
            }
            bVar5 = IsMisc((int)unaff_EDI,(int)unaff_ESI);
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
  local_210 = 0;
  local_230._0_3_ = CONCAT12(1,(undefined2)local_230);
  pcVar24 = "canDetect";
  pcVar23 = "GameObjectClass";
  GetODFBool("GameObjectClass","canDetect",(char *)((int)&local_230 + 2),(char *)local_248,
             (bool *)unaff_EDI,SUB41(unaff_ESI,0));
  GetODFInt("GameObjectClass","scanTeamLimit",(char *)&local_210,(char *)0x0,(int *)pcVar23,
            (int)pcVar24);
  if (local_230._2_1_ != '\0') {
    uVar6 = local_248._0_1_;
    if (local_210 == 3) {
      uVar6 = 0;
    }
    local_248 = (vector<VehicleHelper::VehicleClass,std::allocator<VehicleHelper::VehicleClass>_> *)
                CONCAT31(local_248._1_3_,uVar6);
  }
  GetODFBool("GameObjectClass","CanHQCPObjectify",(char *)(piVar16 + 5),(char *)local_248,
             (bool *)unaff_EDI,SUB41(unaff_ESI,0));
  piVar13 = local_240;
  if ((char)piVar16[5] != '\0') {
    GetODFBool("GameObjectClass","CanHQCPObjectifyDeployed",(char *)((int)local_240 + 0x15),
               (char *)0x1,(bool *)unaff_EDI,SUB41(unaff_ESI,0));
  }
  uVar3 = (uint)local_238 >> 8;
  local_238 = (vector<ObjectHelper::ObjectClass,std::allocator<ObjectHelper::ObjectClass>_> *)
              ((uint)local_238 & 0xffffff00);
  if ((((((piVar13[4] == 1) || (piVar13[4] == 8)) || (piVar13[4] == 4)) ||
       ((uVar7 == 0xcd066db7 || (uVar7 == 0xd888605f)))) ||
      ((uVar7 == 0x3eb9e3b2 || ((uVar7 == 0xa9238ce6 || (uVar7 == 0xf2ecd752)))))) &&
     ((uVar7 != 0x8d7c8912 && ((uVar7 != 0x33e33cd9 && (local_234 != 0x150c5d8b)))))) {
    local_238 = (vector<ObjectHelper::ObjectClass,std::allocator<ObjectHelper::ObjectClass>_> *)
                CONCAT31((int3)uVar3,local_234 != 0xb472c1ee);
  }
  uVar6 = 0x48;
  pcVar23 = "GameObjectClass";
  GetODFBool("GameObjectClass","CanTeleport",(char *)((int)piVar13 + 0x16),(char *)local_238,
             (bool *)unaff_EDI,SUB41(unaff_ESI,0));
  local_220 = (char *)((int)piVar13 + 0x17);
  GetODFBool("GameObjectClass","CanBeIdleVictim",local_220,(char *)0x1,(bool *)pcVar23,(bool)uVar6);
  bVar5 = IsCraftOrPerson(param_1);
  if (bVar5) {
    if (local_22c != 0.0) {
      fVar20 = GetEngageRange((int)unaff_EDI);
      piVar13[9] = (int)fVar20;
    }
    local_24e[0] = '\0';
    iVar8 = GetODFBool("GameObjectClass","AutoSetGroup",local_24e,(char *)0x0,(bool *)unaff_EDI,
                       SUB41(unaff_ESI,0));
    if ((iVar8 != 0) && (local_24e[0] != '\0')) {
      SetBestGroup(param_1);
    }
  }
  uVar7 = local_228;
  pBVar18 = local_23c;
  piVar16 = local_240;
  local_1e4 = (float *)(piVar13 + 0x12);
  *piVar13 = param_1;
  piVar13[6] = local_24c;
  piVar13[7] = local_24c;
  *local_1e4 = local_200.x;
  piVar13[0x13] = (int)local_200.y;
  piVar13[0x14] = (int)local_200.z;
  iVar8 = local_240[4];
  if ((iVar8 == 1) || (iVar8 == 4)) {
    local_238 = (vector<ObjectHelper::ObjectClass,std::allocator<ObjectHelper::ObjectClass>_> *)0x0;
    local_240 = (int *)0x54;
    local_248 = &local_23c->m_VehicleHelper->VehicleList;
    local_1e8 = (*(int *)&local_248->field_0x4 - *(int *)local_248) / 0x54;
    if (0 < local_1e8) {
      iVar8 = 0;
      piVar13 = *(int **)local_248;
      do {
        if (*piVar13 == param_1) {
          if (-1 < iVar8) goto LAB_4fc0d91e;
          break;
        }
        iVar8 = iVar8 + 1;
        piVar13 = piVar13 + 0x15;
      } while (iVar8 < local_1e8);
    }
    if (*(VehicleClass **)&local_248->field_0x8 == *(VehicleClass **)&local_248->field_0x4) {
      std::vector<VehicleHelper::VehicleClass,std::allocator<VehicleHelper::VehicleClass>_>::
      _Emplace_reallocate<>(local_248,*(VehicleClass **)&local_248->field_0x4);
    }
    else {
      sVar27 = 0x54;
      iVar8 = 0;
      pvVar10 = operator_new(0,(void *)0x54);
      memset(pvVar10,iVar8,sVar27);
      *(int *)&local_248->field_0x4 = *(int *)&local_248->field_0x4 + (int)local_240;
    }
    iVar8 = (*(int *)&local_248->field_0x4 - *(int *)local_248) / (int)local_240 + -1;
LAB_4fc0d91e:
    local_248 = (vector<VehicleHelper::VehicleClass,std::allocator<VehicleHelper::VehicleClass>_> *)
                (iVar8 * 0x54 + *(int *)&pBVar18->m_VehicleHelper->VehicleList);
    memset(local_248,0,(size_t)local_240);
    *(uint *)((int)local_248 + 4) = local_218;
    *(uint *)((int)local_248 + 8) = local_228;
    *(uint *)((int)local_248 + 0xc) = local_234;
    local_238 = (vector<ObjectHelper::ObjectClass,std::allocator<ObjectHelper::ObjectClass>_> *)
                ((uint)local_238 & 0xffffff00);
    local_24e[0] = '\0';
    if (local_228 == 0x1c628d2e) {
      iVar8 = GetODFBool("MorphTankClass","HiddenWhenMorphed",(char *)&local_238,(char *)0x0,
                         (bool *)unaff_EDI,SUB41(unaff_ESI,0));
      pvVar17 = local_248;
      if ((iVar8 != 0) && ((char)local_238 != '\0')) {
        pcVar24 = "CanAICloak";
        pcVar23 = "CraftClass";
        GetODFBool("CraftClass","CanAICloak",local_24e,(char *)local_238,(bool *)unaff_EDI,
                   SUB41(unaff_ESI,0));
        piVar13 = (int *)((int)local_248 + 0x30);
        pcVar22 = "MaxCloakEnergy";
        pcVar21 = "GameObjectClass";
        GetODFLong("GameObjectClass","MaxCloakEnergy",(char *)piVar13,(char *)0x0,(long *)pcVar23,
                   (long)pcVar24);
        pvVar17 = local_248;
        *(int *)((int)local_248 + 0x34) = *piVar13;
        pcVar24 = "CloakEnergyCost";
        pcVar23 = "GameObjectClass";
        GetODFLong("GameObjectClass","CloakEnergyCost",(char *)((int)local_248 + 0x38),(char *)0x0,
                   (long *)pcVar21,(long)pcVar22);
        GetODFLong("GameObjectClass","AddCloakEnergy",(char *)((int)pvVar17 + 0x3c),(char *)0x0,
                   (long *)pcVar23,(long)pcVar24);
      }
    }
    else {
      pvVar17 = local_248;
      if (local_234 == 0x2411d97a) {
        GetODFBool("CraftClass","CanAICloak",local_24e,(char *)0x0,(bool *)unaff_EDI,
                   SUB41(unaff_ESI,0));
        pvVar17 = local_248;
      }
    }
    pcVar24 = "ShowSkill";
    pcVar23 = "GameObjectClass";
    GetODFBool("GameObjectClass","ShowSkill",(char *)((int)pvVar17 + 0x18),
               (char *)(uint)(0 < (int)local_22c),(bool *)unaff_EDI,SUB41(unaff_ESI,0));
    GetODFInt("GameObjectClass","ShowSkillTeamFilter",(char *)((int)pvVar17 + 0x20),(char *)0x3,
              (int *)pcVar23,(int)pcVar24);
    if (*(int *)((int)pvVar17 + 0x20) == 0) {
      *(int *)((int)pvVar17 + 0x20) = -1;
    }
    uVar6 = 0xf4;
    pcVar21 = "CraftClass";
    GetODFBool("CraftClass","CanRemoteControl",(char *)((int)pvVar17 + 0x1a),(char *)0x0,
               (bool *)unaff_EDI,SUB41(unaff_ESI,0));
    pcVar24 = "HuntIsResupply";
    pcVar23 = "CraftClass";
    GetODFBool("CraftClass","HuntIsResupply",(char *)((int)pvVar17 + 0x1b),(char *)0x0,
               (bool *)pcVar21,(bool)uVar6);
    GetODFInt("CraftClass","AIEscortPriority",(char *)&local_21c,(char *)0x0,(int *)pcVar23,
              (int)pcVar24);
    if (local_21c < 0) {
      local_21c = 0;
    }
    else if (3 < local_21c) {
      local_21c = 3;
    }
    if (local_22c != 0.0) {
      *(int *)((int)pvVar17 + 0x44) = piVar16[9];
    }
    *(int *)((int)pvVar17 + 0x28) = local_24c;
    *(long *)((int)pvVar17 + 0x14) = local_208;
    *(int *)pvVar17 = param_1;
    *(float *)((int)pvVar17 + 0x48) = *local_1e4;
    *(float *)((int)pvVar17 + 0x4c) = local_1e4[1];
    *(float *)((int)pvVar17 + 0x50) = local_1e4[2];
    *(char *)((int)local_248 + 0x1c) = *local_220;
    if ((((local_24e[0] != '\0') || (local_234 == 0x53179125)) ||
        ((local_224 != (char *)0x0 && (iVar8 = _strnicmp(local_224,"escort",6), iVar8 == 0)))) ||
       ((local_234 == 0x6f5ff9ab ||
        ((((local_224 != (char *)0x0 && (iVar8 = _strnicmp(local_224,"patrol",6), iVar8 == 0)) ||
          (local_234 == 0x44ad0c90)) ||
         ((pBVar18 = local_23c, local_224 != (char *)0x0 &&
          (iVar8 = _strnicmp(local_224,"hunter",6), pBVar18 = local_23c, iVar8 == 0)))))))) {
      pBVar18 = local_23c;
      DispatchHelper::AddToDispatch
                (local_23c->m_DispatchHelper,param_1,___real_40a00000,false,0,true,false,false,false
                );
    }
    pBVar4 = local_23c;
    if ((((((local_228 == 0x33a01170) || (local_228 == 0x5cfae8c8)) ||
          ((local_228 == 0x32493554 ||
           (((local_228 == 0x4e12224 || (local_228 == 0x77f02e21)) || (local_228 == 0x2418efcf))))))
         || ((local_234 == 0x326aa115 || (local_228 == 0xda4acce)))) || (local_228 == 0x28e4d573))
       || ((local_228 == 0x7b3b7981 || (uVar7 = local_228, local_21c != 0)))) {
      VVar1.y = local_200.y;
      VVar1.x = local_200.x;
      VVar1.z = local_200.z;
      UtilityShipHelper::AddUtilityShipObject
                (local_23c->m_UtilityShipHelper,param_1,local_24c,VVar1,local_228,local_234,
                 local_190,(char *)&local_1dc.rightw,local_21c);
      uVar7 = local_228;
      pBVar18 = pBVar4;
    }
  }
  else {
    if (iVar8 != 2) {
      if (local_228 == 0) {
        memset(&local_150,0,0x40);
        bVar5 = GetObjInfo(param_1,Get_GOClass,(char *)&local_150);
        pBVar18 = local_23c;
        if (!bVar5) goto LAB_4fc0d6d2;
        iVar8 = _stricmp((char *)&local_150,"CLASS_DEPOSIT");
        cVar19 = '\x01' - (iVar8 != 0);
      }
      else {
        cVar19 = local_228 == 0xdc5f98c6;
      }
      pBVar18 = local_23c;
      if (cVar19 == '\0') goto LAB_4fc0d6d2;
    }
    pBVar18 = local_23c;
    BuildingHelper::AddBuildingObject
              (local_23c->m_BuildingHelper,param_1,local_190,(char *)&local_1dc.rightw,local_24c,
               local_218,uVar7,local_234,(bool)*local_220,local_20c,SUB41(local_24c,0));
    memset(&local_150,0,0x40);
    iVar8 = GetODFString("BuildingClass","DeploySound",(char *)0x40,(char *)&local_150,0,
                         (char *)unaff_EDI,unaff_ESI);
    if (iVar8 != 0) {
      local_22c = 0.0;
      local_24e[0] = '\0';
      uVar6 = 0x60;
      pcVar23 = "BuildingClass";
      GetODFFloat("BuildingClass","DeploySoundStartDelay",(char *)&local_22c,(char *)0x0,unaff_EDI,
                  (float)unaff_ESI);
      GetODFBool("BuildingClass","DeploySoundLoop",local_24e,(char *)0x0,(bool *)pcVar23,(bool)uVar6
                );
      if ((___real_00000000 < local_22c) || (local_24e[0] != '\0')) {
        this_00 = (vector<BZ1Helper::DeploySoundClass,std::allocator<BZ1Helper::DeploySoundClass>_>
                   *)(pBVar18[1].teamInfo[0].PilotWeapon[2] + 0x1f);
        std::vector<BZ1Helper::DeploySoundClass,std::allocator<BZ1Helper::DeploySoundClass>_>::
        _Resize<<lambda_4d52942989f528cd785dbeae06193644>_>
                  (this_00,(*(int *)(pBVar18[1].teamInfo[0].PilotWeapon[2] + 0x23) - *(int *)this_00
                           ) / 0x58 + 1,(<lambda_4d52942989f528cd785dbeae06193644>)this_00);
        piVar16 = (int *)(*(int *)this_00 + -0x58 +
                         ((*(int *)(pBVar18[1].teamInfo[0].PilotWeapon[2] + 0x23) - *(int *)this_00)
                         / 0x58) * 0x58);
        memset(piVar16,0,0x58);
        local_224 = (char *)0x0;
        GetODFFloat("BuildingClass","DeploySoundRepeatDelay",(char *)&local_224,(char *)0x0,
                    unaff_EDI,(float)unaff_ESI);
        *piVar16 = param_1;
        strcpy_s((char *)(piVar16 + 6),0x40,(char *)&local_150);
        *(char *)(piVar16 + 1) = local_24e[0];
        iVar8 = SecondsToTurns(local_22c);
        piVar16[3] = iVar8;
        iVar8 = SecondsToTurns((float)local_224);
        piVar16[4] = iVar8;
        uVar7 = local_228;
        pBVar18 = local_23c;
      }
      else {
        StartAudio3D((char *)&local_150,param_1,AUDIO_CAT_AMBIENT,false,false);
      }
    }
  }
LAB_4fc0d6d2:
  local_214 = -1;
  iVar8 = GetODFInt("GameObjectClass","PerceivedTeam",(char *)&local_214,(char *)0xffffffff,
                    (int *)unaff_EDI,(int)unaff_ESI);
  if (((iVar8 != 0) && (-1 < local_214)) && (iVar8 = GetPerceivedTeam(param_1), iVar8 != local_214))
  {
    SetPerceivedTeam(param_1,local_214);
  }
  local_230 = (float)((uint)local_230 & 0xffffff);
  iVar8 = GetODFBool("GameObjectClass","DeleteOnLoad",(char *)((int)&local_230 + 3),(char *)0x0,
                     (bool *)unaff_EDI,SUB41(unaff_ESI,0));
  if ((iVar8 != 0) && (local_230._3_1_ != '\0')) {
    DeleteAfterDelay(pBVar18,param_1,0.0);
  }
  local_240 = (int *)(local_24c * 0xa14);
  if ((*(int *)((int)pBVar18->teamInfo + (int)local_240 + 0x98) != 0) && (local_20c != 0)) {
    this_01 = (AIWeaponHelper *)0x3;
    iVar8 = GetObjectByTeamSlot(local_24c,3);
    if (iVar8 != 0) {
      AIWeaponHelper::AIGiveWeapons(this_01,param_1,local_24c,local_20c,SUB41(this_01,0));
    }
  }
  AttacherHelper::AddAttacherObject
            (pBVar18->m_AttacherHelper,param_1,local_190,(char *)&local_1dc.rightw,local_234,
             local_110);
  iVar8 = _strnicmp(local_110,"BZCundep",8);
  if (iVar8 == 0) {
    UndeployHelper::AddUndeployObject
              (pBVar18->m_UndeployHelper,local_24c,(int)local_110,(char *)unaff_EDI);
  }
  if ((((local_1dc.right.x != 0.0) || (local_230 == -2.0556315e+18)) ||
      (local_230 == -3.0636873e+20)) ||
     ((local_230 == -11796.035 || (fVar20 = local_230, local_230 == 2.6288888e+26)))) {
    ProductionClassHelper::AddProductionClassObject
              ((ProductionClassHelper *)param_1,(int)local_18c,(char *)&local_1dc.up,
               (char *)local_248,uVar7,(int)local_230,(int)local_1dc.right.x,(int)unaff_ESI);
    fVar20 = local_22c;
  }
  if ((uint)fVar20 < 0xd7241cf8) {
    if (fVar20 == -1.8044431e+14) {
      CarrierHelper::AddCarrierObject
                (pBVar18->m_CarrierHelper,param_1,local_18c,(char *)&local_1dc.up);
    }
    else {
      if (fVar20 == 2.8346567e-26) goto LAB_4fc0dd89;
      if (fVar20 == 3.1626073e-17) {
        MorphObjectHelper::AddMorphObjectHostObject
                  (pBVar18->m_MorphObjectHelper,param_1,local_18c,(char *)&local_1dc.up);
      }
      else if (fVar20 == -2.2608558e-07) {
        PortalHelper::AddPortalSwitchObject
                  (pBVar18->m_PortalHelper,param_1,local_18c,(char *)&local_1dc.up);
      }
      else if (fVar20 == -6.3148924e-05) {
        MorphObjectHelper::AddMorphObjectToggleObject(pBVar18->m_MorphObjectHelper,param_1);
      }
    }
  }
  else if (fVar20 == -3.3459833e+29) {
LAB_4fc0dd89:
    PortalHelper::AddPortalObject
              (pBVar18->m_PortalHelper,param_1,local_18c,(char *)&local_1dc.up,(int)fVar20);
  }
  else if (fVar20 == -2.6257834e+32) {
    PowerHelper::AddPowerObject(pBVar18->m_PowerHelper,param_1,local_18c,(char *)&local_1dc.up);
  }
  else if (fVar20 == -8.827889e+36) {
    CarrierHelper::AddCarrierDroneObject
              (pBVar18->m_CarrierHelper,param_1,(int)local_248,local_18c,(char *)&local_1dc.up,
               acStack_10c);
  }
  pBVar4 = local_23c;
  local_24c = CONCAT13(1,(undefined3)local_24c);
  bVar5 = SUB41(unaff_EBX,0);
  if (uVar7 < 0x80f9ff72) {
    if (uVar7 == 0x80f9ff71) {
      GetODFBool("SiloClass","ScrapDropPoint",(char *)((int)&local_24c + 3),(char *)0x1,unaff_ESI,
                 bVar5);
      if (local_24c._3_1_ != '\0') {
        piVar16 = (int *)((int)&local_23c->teamInfo[0].DropoffSilos + (int)pBVar18);
        *piVar16 = *piVar16 + 1;
      }
      goto LAB_4fc0e04a;
    }
    if (uVar7 != 0x16164674) {
      if (uVar7 == 0x33a01170) {
        memset(&local_150.right.y,0,0x40);
        pcVar23 = "ScavengerClass";
LAB_4fc0de31:
        GetODFString(pcVar23,"deployClass",(char *)0x40,(char *)&local_150.right.y,0,unaff_ESI,
                     unaff_EBX);
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
          GetODFBool("ExtractorClass","ScrapDropPoint",(char *)((int)&local_24c + 3),(char *)0x1,
                     unaff_ESI,bVar5);
          if (local_24c._3_1_ != '\0') {
            piVar16 = (int *)((int)&local_23c->teamInfo[0].DropoffExtractors + (int)pBVar18);
            *piVar16 = *piVar16 + 1;
          }
          goto LAB_4fc0e04a;
        }
        if (uVar7 != 0x4b970310) {
          if (uVar7 != 0x5cfae8c8) goto LAB_4fc0e04a;
          memset(&local_150.right.y,0,0x40);
          pcVar23 = "ScavengerHClass";
          goto LAB_4fc0de31;
        }
      }
    }
  }
  else {
    if (uVar7 == 0x8a0a1ead) {
      GetODFBool("RecyclerClass","ScrapDropPoint",(char *)((int)&local_24c + 3),(char *)0x1,
                 unaff_ESI,bVar5);
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
        if ((local_23c->teamInfo[0].ArmoryBuildClass + 0x1b)[(int)pBVar18] == '\0') {
          cVar19 = GetRace(param_1);
          (pBVar4->teamInfo[0].ArmoryBuildClass + 0x1b)[(int)pBVar18] = cVar19;
        }
        pcVar23 = pBVar18[1].teamInfo[0].PilotWeapon[4] + 0x1d;
        if (*pcVar23 == '\0') {
          GetODFBool("GameObjectClass","UseBZ2Pools",pcVar23,(char *)0x0,unaff_ESI,
                     SUB41(unaff_EBX,0));
        }
      }
      goto LAB_4fc0e04a;
    }
  }
  PowerupHelper::AddPowerupObject
            (pBVar18->m_PowerupHelper,param_1,local_18c,(char *)&local_1dc.up,1,uVar7);
LAB_4fc0e04a:
  pvVar17 = local_248;
  if ((local_240._3_1_ != '\0') &&
     (*(char *)((int)pBVar18->teamInfo + (int)local_248 * 0xa14 + 0x10d) != '\0')) {
    bVar5 = IsTeamplayOn();
    if (bVar5) {
      iVar8 = GetCommanderTeam((int)pvVar17);
      SetTeamNum(param_1,iVar8);
    }
    else {
      Stop(param_1,1);
      SetTeamNum(param_1,0xf);
    }
  }
  return;
}


// ---------------------------------------------------------------------
// BZ1Helper::DeleteObject  @ 4fc0e0b1  lines 1528-1695


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall BZ1Helper::DeleteObject(BZ1Helper *this,int param_1)

{
  vector<BZ1Helper::AlignTerrainReplaceClass,std::allocator<BZ1Helper::AlignTerrainReplaceClass>_>
  *this_00;
  bool bVar1;
  uint uVar2;
  long lVar3;
  int iVar4;
  int *piVar5;
  char *unaff_EBP;
  bool *unaff_ESI;
  char *pcVar6;
  char *pcVar7;
  undefined1 uVar8;
  undefined1 auStack_1a8 [2];
  char local_1a6;
  char local_1a5;
  int local_1a4;
  float local_1a0;
  Vector local_19c;
  Vector local_190;
  char local_184 [64];
  undefined1 local_144 [64];
  char local_104 [64];
  char local_c4 [64];
  char local_84 [64];
  char local_44 [64];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)auStack_1a8;
  TotalMapObjects = TotalMapObjects + -1;
  pcVar7 = this[1].teamInfo[0].PilotWeapon[3] + 3;
  *(int *)pcVar7 = *(int *)pcVar7 + -1;
  if (this[1].teamInfo[0].PilotWeapon[4][0x21] != '\0') {
    return;
  }
  memset(local_c4,0,0x40);
  GetObjInfo(param_1,Get_GOClass,local_c4);
  uVar2 = Hash(unaff_ESI,(uint)unaff_EBP);
  if (uVar2 == 0x6ee4c53d) {
    return;
  }
  memset(local_44,0,0x40);
  memset(local_144,0,0x40);
  pcVar7 = local_184;
  pcVar6 = (char *)0x0;
  memset(pcVar7,0,0x40);
  GetAndOpenODFNames((int)local_184,local_44,pcVar7,pcVar6);
  local_1a4 = GetTeamNum(param_1);
  lVar3 = GetMaxHealth(param_1);
  local_19c.x = 0.0;
  local_19c.y = 0.0;
  local_19c.z = 0.0;
  GetPosition2(param_1,&local_19c);
  memset(local_84,0,0x40);
  GetODFString("GameObjectClass","BZCClasslabel",(char *)0x40,local_84,0,unaff_ESI,unaff_EBP);
  local_1a0 = (float)Hash(unaff_ESI,(uint)unaff_EBP);
  iVar4 = local_1a4;
  if (0 < lVar3) {
    piVar5 = (int *)((int)this->teamInfo + local_1a4 * 0xa14 + 0xc0);
    *piVar5 = *piVar5 + -1;
  }
  bVar1 = IsCraft((int)unaff_ESI,(int)unaff_EBP);
  if ((bVar1) || (bVar1 = IsPerson(param_1), bVar1)) {
    DispatchHelper::DeleteDispatchObject(this->m_DispatchHelper,param_1,iVar4);
  }
  if (local_1a0 == -2.6257834e+32) {
    for (piVar5 = *(int **)&this->m_PowerHelper->PowerList;
        piVar5 != *(int **)&(this->m_PowerHelper->PowerList).field_0x4; piVar5 = piVar5 + 10) {
      if (*piVar5 == param_1) {
        bVar1 = IsAround(*piVar5);
        if (bVar1) {
          *(undefined1 *)(piVar5 + 1) = 1;
        }
        break;
      }
    }
  }
  local_1a6 = '\x01';
  if (uVar2 < 0x8a0a1eae) {
    bVar1 = SUB41(unaff_EBP,0);
    if (uVar2 == 0x8a0a1ead) {
      iVar4 = GetODFBool("RecyclerClass","ScrapDropPoint",&local_1a6,(char *)0x1,unaff_ESI,bVar1);
      if (iVar4 == 0) {
        return;
      }
      if (local_1a6 == '\0') {
        return;
      }
      piVar5 = (int *)((int)this->teamInfo + local_1a4 * 0xa14 + 0xdc);
      *piVar5 = *piVar5 + -1;
      return;
    }
    if ((uVar2 != 0x219650cd) && (uVar2 != 0x33a01170)) {
      if (uVar2 == 0x490dd218) {
        iVar4 = GetODFBool("ExtractorClass","ScrapDropPoint",&local_1a6,(char *)0x1,unaff_ESI,bVar1)
        ;
        if (iVar4 == 0) {
          return;
        }
        if (local_1a6 == '\0') {
          return;
        }
        piVar5 = (int *)((int)this->teamInfo + local_1a4 * 0xa14 + 0xe0);
        *piVar5 = *piVar5 + -1;
        return;
      }
      if (uVar2 != 0x5cfae8c8) {
        if (uVar2 != 0x80f9ff71) {
          return;
        }
        iVar4 = GetODFBool("SiloClass","ScrapDropPoint",&local_1a6,(char *)0x1,unaff_ESI,bVar1);
        if (iVar4 == 0) {
          return;
        }
        if (local_1a6 == '\0') {
          return;
        }
        piVar5 = (int *)((int)this->teamInfo + local_1a4 * 0xa14 + 0xe4);
        *piVar5 = *piVar5 + -1;
        return;
      }
    }
  }
  else {
    if (uVar2 == 0xb18ef1c3) {
      piVar5 = (int *)((int)this->teamInfo + local_1a4 * 0xa14 + 0xbc);
      *piVar5 = *piVar5 + -1;
      return;
    }
    if (((uVar2 != 0xc9cd7077) && (uVar2 != 0xcd6780cd)) && (uVar2 != 0xf1656077)) {
      return;
    }
  }
  bVar1 = IsDeployed(param_1);
  if (!bVar1) {
    return;
  }
  memset(local_104,0,0x40);
  if (((uVar2 == 0xc9cd7077) || (uVar2 == 0xcd6780cd)) ||
     ((uVar2 == 0xf1656077 || (uVar2 == 0x219650cd)))) {
    pcVar6 = "deployName";
    pcVar7 = "DeployBuildingClass";
  }
  else {
    iVar4 = GetODFString("ScavengerClass","deployClass",(char *)0x40,local_104,0,unaff_ESI,unaff_EBP
                        );
    if (iVar4 != 0) goto LAB_4fc0e45f;
    pcVar6 = "deployClass";
    pcVar7 = "ScavengerHClass";
  }
  GetODFString(pcVar7,pcVar6,(char *)0x40,local_104,0,unaff_ESI,unaff_EBP);
LAB_4fc0e45f:
  if (local_104[0] != '\0') {
    local_1a5 = '\0';
    uVar8 = 0x40;
    pcVar7 = ".odf";
    CombineStrings(".odf",(char *)0x40,unaff_ESI,(uint)unaff_EBP);
    iVar4 = GetODFBool("GameObjectClass","AlignToTerrain",&local_1a5,(char *)0x0,(bool *)pcVar7,
                       (bool)uVar8);
    if ((iVar4 != 0) && (local_1a5 != '\0')) {
      this_00 = (vector<BZ1Helper::AlignTerrainReplaceClass,std::allocator<BZ1Helper::AlignTerrainReplaceClass>_>
                 *)(this[1].teamInfo[0].PilotWeapon[2] + 7);
      for (piVar5 = *(int **)this_00; piVar5 != *(int **)(this[1].teamInfo[0].PilotWeapon[2] + 0xb);
          piVar5 = piVar5 + 4) {
        if (*piVar5 == param_1) {
          return;
        }
      }
      std::
      vector<BZ1Helper::AlignTerrainReplaceClass,std::allocator<BZ1Helper::AlignTerrainReplaceClass>_>
      ::_Resize<<lambda_1855a80fc533c550b5607d8bf997ad95>_>
                (this_00,(*(int *)(this[1].teamInfo[0].PilotWeapon[2] + 0xb) - *(int *)this_00 >> 4)
                         + 1,(<lambda_1855a80fc533c550b5607d8bf997ad95>)this_00);
      iVar4 = (*(int *)(this[1].teamInfo[0].PilotWeapon[2] + 0xb) - *(int *)this_00 & 0xfffffff0U) +
              *(int *)this_00;
      *(undefined4 *)(iVar4 + -0x10) = 0;
      *(undefined4 *)(iVar4 + -0xc) = 0;
      *(undefined4 *)(iVar4 + -8) = 0;
      *(undefined4 *)(iVar4 + -4) = 0;
      local_190.x = 0.0;
      local_190.y = 0.0;
      local_190.z = 0.0;
      local_1a0 = 0.0;
      TerrainGetHeightAndNormal(&local_19c,&local_1a0,&local_190,false);
      *(float *)(iVar4 + -0xc) = local_190.x;
      *(float *)(iVar4 + -8) = local_190.y;
      *(float *)(iVar4 + -4) = local_190.z;
      *(int *)(iVar4 + -0x10) = param_1;
    }
  }
  return;
}


// ---------------------------------------------------------------------
// BZ1Helper::Init  @ 4fc0e560  lines 1699-1988


/* WARNING: Function: _alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall BZ1Helper::Init(BZ1Helper *this)

{
  float *pfVar1;
  float fVar2;
  char (*pacVar3) [64];
  bool bVar4;
  char *pcVar5;
  int iVar6;
  uint uVar7;
  char *unaff_EDI;
  float fVar8;
  undefined1 *puVar9;
  float local_138;
  undefined1 *local_134;
  float local_130;
  undefined1 *local_12c;
  float local_128;
  undefined1 *local_124;
  float local_120;
  undefined1 *local_11c;
  uint local_118;
  char local_112;
  char local_111;
  undefined1 *local_110;
  char local_10c [128];
  char local_8c [132];
  uint local_8;
  
  local_8 = __security_cookie ^ (uint)&stack0xfffffffc;
  local_112 = IsNetworkOn();
  memset(local_8c,0,0x80);
  pcVar5 = GetMapTRNFilename();
  strcpy_s(local_8c,0x80,pcVar5);
  bVar4 = OpenODF2(unaff_EDI);
  if (!bVar4) goto LAB_4fc0ea9d;
  GetODFFloat(local_8c,"Size","Height",&(this->mapInfo).Height,0.0);
  GetODFFloat(local_8c,"Size","MetersPerGrid",&(this->mapInfo).MPG,0.0);
  GetODFFloat(local_8c,"Size","HeightGranularity",&(this->mapInfo).HeightGranularity,0.0);
  pfVar1 = &(this->mapInfo).MapWidth;
  iVar6 = GetODFFloat(local_8c,"Size","Width",pfVar1,0.0);
  if (((iVar6 == 0) ||
      (iVar6 = GetODFFloat(local_8c,"Size","Depth",&(this->mapInfo).MapDepth,0.0), iVar6 == 0)) ||
     (iVar6 = GetODFFloat(local_8c,"Size","MinX",&(this->mapInfo).MinX,0.0), iVar6 == 0)) {
LAB_4fc0e6b9:
    local_111 = '\0';
  }
  else {
    iVar6 = GetODFFloat(local_8c,"Size","MinZ",&(this->mapInfo).MinZ,0.0);
    local_111 = '\x01';
    if (iVar6 == 0) goto LAB_4fc0e6b9;
  }
  GetODFFloat(local_8c,"World","Gravity",&(this->mapInfo).Gravity,___real_41480000);
  if (local_111 == '\0') {
    FormatConsoleMessage
              ("ERROR! \'%s\' missing [Size] section! Out of bounds area not calibrated! FIXME!");
    *pfVar1 = 4096.0;
    (this->mapInfo).MapDepth = 4096.0;
    (this->mapInfo).MinX = -2048.0;
    (this->mapInfo).MinZ = -2048.0;
  }
  GetODFFloat(local_8c,"DLL","ReinforcementMinRadius",
              (float *)(this[1].teamInfo[0].PilotWeapon[4] + 0x2f),___real_43160000);
  GetODFFloat(local_8c,"DLL","ReinforcementMaxRadius",
              (float *)(this[1].teamInfo[0].PilotWeapon[4] + 0x33),___real_437a0000);
  GetODFFloat(local_8c,"DLL","ReinforcementCliffTolerance",
              (float *)(this[1].teamInfo[0].PilotWeapon[4] + 0x37),__real_42c80000);
  GetODFFloat(local_8c,"DLL","MinScrapHeight",&(this->mapInfo).MinScrapHeight,___real_c9742400);
  GetODFFloat(local_8c,"DLL","MaxScrapHeight",&(this->mapInfo).MaxScrapHeight,__real_49742400);
  GetODFBool(local_8c,"DLL","RestrictAllScrap",&(this->mapInfo).RestrictAllScrap,false);
  GetODFBool(local_8c,"DLL","RespawnAtLowAltitude",&(this->mapInfo).RespawnAtLowAltitude,false);
  GetODFFloat(local_8c,"DLL","SpawnMinRadius",&(this->mapInfo).SpawnMinRadius,__real_41a00000);
  GetODFFloat(local_8c,"DLL","SpawnMaxRadius",&(this->mapInfo).SpawnMaxRadius,__real_42480000);
  GravityHelper::LoadGravityInfo(this->m_GravityHelper,local_8c);
  AmbientSoundHelper::LoadAmbientSoundInfo(this->m_AmbientSoundHelper,local_8c);
  local_118 = 0;
  GetPathPoints("edge_path",&local_118,(float *)0x0);
  iVar6 = local_118 * -8;
  local_138 = 0.0;
  *(undefined1 **)(&stack0xfffffeb8 + iVar6) = &stack0xfffffebc;
  local_110 = &stack0xfffffebc;
  local_134 = (undefined1 *)0x0;
  local_130 = 0.0;
  local_12c = (undefined1 *)0x0;
  *(uint **)(&stack0xfffffeb4 + iVar6) = &local_118;
  *(char **)(&stack0xfffffeb0 + iVar6) = "edge_path";
  *(undefined4 *)(&stack0xfffffeac + iVar6) = 0x4fc0e8c0;
  bVar4 = GetPathPoints(*(char **)(&stack0xfffffeb0 + iVar6),*(uint **)(&stack0xfffffeb4 + iVar6),
                        *(float **)(&stack0xfffffeb8 + iVar6));
  if ((bVar4) && (1 < local_118)) {
    uVar7 = 0;
    local_120 = 3.4028235e+38;
    local_11c = (undefined1 *)0x7f7fffff;
    local_128 = -3.4028235e+38;
    local_124 = (undefined1 *)0xff7fffff;
    puVar9 = local_110;
    if (local_118 != 0) {
      do {
        fVar8 = *(float *)(local_110 + uVar7 * 8);
        if (fVar8 < local_120) {
          local_120 = fVar8;
        }
        puVar9 = *(undefined1 **)(local_110 + uVar7 * 8 + 4);
        if ((float)puVar9 < (float)local_11c) {
          local_11c = puVar9;
        }
        if (local_128 < fVar8) {
          local_128 = fVar8;
        }
        if ((float)local_124 < (float)puVar9) {
          local_124 = puVar9;
        }
        uVar7 = uVar7 + 1;
      } while (uVar7 < local_118);
    }
    local_110 = puVar9;
    local_138 = local_120;
    local_134 = local_11c;
    local_130 = local_128;
    local_12c = local_124;
  }
  if ((float)local_12c + local_130 + (float)local_134 + local_138 == 0.0) {
    fVar2 = (float)___real_3fe0000000000000;
    fVar8 = (this->mapInfo).MapWidth * fVar2;
    (this->mapInfo).MaxWidth = fVar8;
    fVar2 = (this->mapInfo).MapDepth * fVar2;
    (this->mapInfo).MaxDepth = fVar2;
    (this->mapInfo).MinWidth = -fVar8;
    (this->mapInfo).MinDepth = -fVar2;
  }
  else {
    fVar8 = local_138;
    if (local_138 < local_130) {
      fVar8 = local_130;
    }
    (this->mapInfo).MaxWidth = fVar8;
    puVar9 = local_134;
    if ((float)local_134 < (float)local_12c) {
      puVar9 = local_12c;
    }
    (this->mapInfo).MaxDepth = (float)puVar9;
    if (local_130 <= local_138) {
      local_138 = local_130;
    }
    (this->mapInfo).MinWidth = local_138;
    if ((float)local_12c <= (float)local_134) {
      local_134 = local_12c;
    }
    (this->mapInfo).MinDepth = (float)local_134;
  }
LAB_4fc0ea9d:
  if (local_112 == '\0') {
    iVar6 = IFace_GetInteger("options.instant.bool2");
    this[1].teamInfo[0].PilotWeapon[4][0x1f] = iVar6 != 0;
    iVar6 = IFace_GetInteger("options.instant.bool4");
    pacVar3 = this[1].teamInfo[0].PilotWeapon;
    *(char *)((int)(pacVar3 + 4) + 0x2b) = '\0';
    *(char *)((int)(pacVar3 + 4) + 0x2c) = '\0';
    *(char *)((int)(pacVar3 + 4) + 0x2d) = -0x80;
    *(char *)((int)(pacVar3 + 4) + 0x2e) = '?';
    pacVar3 = this[1].teamInfo[0].PilotWeapon;
    *(char *)((int)(pacVar3 + 2) + 0x3b) = '\x01';
    *(char *)((int)(pacVar3 + 2) + 0x3c) = '\0';
    *(char *)((int)(pacVar3 + 2) + 0x3d) = '\0';
    *(char *)((int)(pacVar3 + 2) + 0x3e) = '\0';
    this[1].teamInfo[0].PilotWeapon[4][0x1c] = iVar6 != 0;
  }
  else {
    iVar6 = GetVarItemInt("network.session.ivar32");
    this[1].teamInfo[0].PilotWeapon[4][0x1a] = iVar6 != 0;
    iVar6 = GetVarItemInt("network.session.ivar60");
    *(int *)(this[1].teamInfo[0].PilotWeapon[2] + 0x3f) = iVar6;
    iVar6 = GetVarItemInt("network.session.ivar81");
    *(int *)(this[1].teamInfo[0].PilotWeapon[2] + 0x3b) = iVar6;
    m_GameType = GetVarItemInt("network.session.ivar5");
    iVar6 = GetVarItemInt("network.session.ivar26");
    local_110 = (undefined1 *)(float)iVar6;
    if (__real_41200000 <= (float)local_110) {
      if (___real_4059000000000000 < (double)iVar6) {
        local_110 = (undefined1 *)0x42c80000;
      }
    }
    else {
      local_110 = (undefined1 *)0x41200000;
    }
    *(float *)(this[1].teamInfo[0].PilotWeapon[4] + 0x2b) =
         (float)local_110 / (float)___real_4024000000000000;
    iVar6 = GetVarItemInt("network.session.ivar89");
    this[1].teamInfo[0].PilotWeapon[4][0x1f] = iVar6 != 0;
    iVar6 = GetVarItemInt("network.session.ivar90");
    this[1].teamInfo[0].PilotWeapon[4][0x1b] = iVar6 != 0;
    iVar6 = GetVarItemInt("network.session.ivar91");
    this[1].teamInfo[0].PilotWeapon[4][0x1c] = iVar6 != 0;
    iVar6 = GetVarItemInt("network.session.ivar31");
    local_110 = (undefined1 *)((float)iVar6 * (float)___real_3fe0000000000000);
    if (0.0 < (float)local_110) {
      (this->mapInfo).Gravity = (float)local_110;
      SetGravity((float)local_110);
    }
  }
  OffMapPos.x = -4000.0;
  OffMapPos.z = -4000.0;
  OffMapPos.y = TerrainFindFloor(___real_c57a0000,___real_c57a0000);
  SetupClouds(this,local_8c);
  memset(local_10c,0,0x80);
  if (local_112 == '\0') {
    pcVar5 = local_8c;
  }
  else {
    pcVar5 = GetVarItemStr("network.session.svar0");
  }
  strcpy_s(local_10c,0x80,pcVar5);
  pcVar5 = strrchr(local_10c,0x2e);
  if (pcVar5 != (char *)0x0) {
    *pcVar5 = '\0';
  }
  if (Logging != false) {
    iVar6 = GetPlayerHandle();
    GetPlayerName(iVar6);
    FormatLogMessage("Game Started on map: \'%s\' by %s. Version: %d\n");
  }
  bVar4 = DoesFileExist("MPIVSRCheck.odf");
  if (((((((!bVar4) || (bVar4 = DoesFileExist("STvsrcheck.odf"), !bVar4)) ||
         ((bVar4 = DoesFileExist("aip_VSR.autoreg"), !bVar4 ||
          (((bVar4 = DoesFileExist("vsrbasesetup.cfg"), !bVar4 ||
            (bVar4 = DoesFileExist("vsra.txt"), !bVar4)) ||
           (bVar4 = DoesFileExist("evlegs_vsr.odf"), !bVar4)))))) ||
        ((bVar4 = DoesFileExist("BZCundep1.odf"), !bVar4 ||
         (bVar4 = DoesFileExist("BZCundep2.odf"), !bVar4)))) ||
       ((bVar4 = DoesFileExist("ivcamr_vsr.odf"), !bVar4 ||
        (((bVar4 = DoesFileExist("hbport_vsr.odf"), !bVar4 ||
          (bVar4 = DoesFileExist("evmine_vsr.odf"), !bVar4)) ||
         ((bVar4 = DoesFileExist("BZCNullCube.msh"), !bVar4 ||
          ((((bVar4 = DoesFileExist("apserv_vsr.odf"), !bVar4 ||
             (bVar4 = DoesFileExist("ivrbomb_vsr.inf"), !bVar4)) ||
            (bVar4 = DoesFileExist("vsr_bh_e_new_e6_0.aip"), !bVar4)) ||
           ((bVar4 = DoesFileExist("apvsrbldg.odf"), !bVar4 ||
            (bVar4 = DoesFileExist("iweapon_12svsr.odf"), !bVar4)))))))))))) ||
      (bVar4 = DoesFileExist("fweapon_12xvsr.odf"), !bVar4)) ||
     (((bVar4 = DoesFileExist("aplmg.inf"), !bVar4 ||
       (bVar4 = DoesFileExist("racename_e.txt"), !bVar4)) ||
      ((bVar4 = DoesFileExist("evscout00_s.dds"), !bVar4 ||
       (((bVar4 = DoesFileExist("evscav00_s.dds"), !bVar4 ||
         (bVar4 = DoesFileExist("evcons00_s.dds"), !bVar4)) ||
        (bVar4 = DoesFileExist("ivscout12smartvsr.odf"), !bVar4)))))))) {
    AddToMessagesBox2("-- Aborting!",0xffff0000);
    bVar4 = IsNetworkOn();
    if (bVar4) {
      NoteGameoverByNoBases();
      DoGameover(__real_41200000);
    }
    else {
      local_110 = (undefined1 *)(misnImport.time + (float)___real_4024000000000000);
      (*misnImport.FailMission)((float)local_110,"instantl.txt");
    }
  }
  this[1].teamInfo[0].PilotWeapon[4][0x18] = '\x01';
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
  
  this[1].teamInfo[0].PilotWeapon[4][0x19] = '\x01';
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


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall BZ1Helper::Execute(BZ1Helper *this)

{
  int *piVar1;
  undefined1 uVar2;
  int iVar3;
  DispatchClass *pDVar4;
  float fVar5;
  AlignTerrainReplaceClass *pAVar6;
  bool bVar7;
  bool bVar8;
  int iVar9;
  char *pcVar10;
  BZ1Helper *extraout_ECX;
  BZ1Helper *extraout_ECX_00;
  BZ1Helper *extraout_ECX_01;
  ProductionClassHelper *this_00;
  BZ1Helper *extraout_ECX_02;
  AlignTerrainReplaceClass *pAVar11;
  DeploySoundClass *pDVar12;
  AlignTerrainReplaceClass *pAVar13;
  AlignTerrainReplaceClass *pAVar14;
  DeploySoundClass *pDVar15;
  Vector *pVVar16;
  DispatchClass *pDVar17;
  int iVar18;
  DeploySoundClass *pDVar19;
  int *piVar20;
  TeamInfo *pTVar21;
  size_t sVar22;
  DeploySoundClass *pDVar23;
  _Vector_const_iterator<std::_Vector_val<std::_Simple_types<DispatchHelper::DispatchClass>_>_>
  _Var24;
  float10 fVar25;
  float fVar26;
  int local_24;
  DeploySoundClass *local_1c;
  DeploySoundClass *local_18;
  Vector local_14;
  
  if (!GotPaths) {
    pcVar10 = this[1].teamInfo[0].PlayerPilotODF + 0x17;
    GetAiPaths((int *)pcVar10,(char ***)(this[1].teamInfo[0].PlayerPilotODF + 0x1b));
    iVar18 = 0;
    GotPaths = true;
    if (0 < *(int *)pcVar10) {
      do {
        pDVar19 = *(DeploySoundClass **)
                   (*(int *)(this[1].teamInfo[0].PlayerPilotODF + 0x1b) + iVar18 * 4);
        local_1c = (DeploySoundClass *)0x0;
        local_18 = pDVar19;
        iVar9 = sscanf_s((char *)pDVar19,"%dMLay%d");
        if (iVar9 == 2) {
          iVar9 = 0xd8e;
LAB_4fc0f0fe:
          std::vector<char_*,std::allocator<char_*>_>::push_back
                    ((vector<char_*,std::allocator<char_*>_> *)(&this->_padding_ + iVar9 * 3),
                     (char **)&local_18);
        }
        else {
          iVar9 = sscanf_s((char *)pDVar19,"%dPatrol%d");
          if (iVar9 == 2) {
            iVar9 = 0xd9e;
            goto LAB_4fc0f0fe;
          }
        }
        iVar18 = iVar18 + 1;
      } while (iVar18 < *(int *)pcVar10);
    }
  }
  if (this[1].teamInfo[0].PilotWeapon[4][0x18] == '\0') {
    Init(this);
  }
  if (this[1].teamInfo[0].PilotWeapon[4][0x19] == '\0') {
    Setup(this);
  }
  m_TurnCounter = m_TurnCounter + 1;
  iVar18 = SecondsToTurns(___real_42700000);
  if (m_TurnCounter < iVar18) {
    PetWatchdogThread();
  }
  pDVar19 = *(DeploySoundClass **)(this[1].teamInfo[0].PilotWeapon[2] + 0xb);
  pAVar13 = *(AlignTerrainReplaceClass **)(this[1].teamInfo[0].PilotWeapon[2] + 7);
  local_1c = pDVar19;
  while (((DeploySoundClass *)pAVar13 != pDVar19 &&
         (bVar7 = ShouldRemoveAlignTerrainReplace(pAVar13), !bVar7))) {
    pAVar13 = pAVar13 + 1;
  }
  if ((DeploySoundClass *)pAVar13 != pDVar19) {
    pAVar11 = pAVar13 + 1;
    pAVar14 = pAVar13;
    local_18 = (DeploySoundClass *)pAVar11;
    if ((DeploySoundClass *)pAVar11 != pDVar19) {
      do {
        bVar7 = ShouldRemoveAlignTerrainReplace(pAVar11);
        pAVar14 = pAVar13;
        if (!bVar7) {
          pAVar14 = pAVar13 + 1;
          pAVar13->AlignHandle = pAVar11->AlignHandle;
          (pAVar13->NormalVec).x = (pAVar11->NormalVec).x;
          (pAVar13->NormalVec).y = (pAVar11->NormalVec).y;
          (pAVar13->NormalVec).z = (pAVar11->NormalVec).z;
          pDVar19 = local_1c;
        }
        pAVar11 = pAVar11 + 1;
        pAVar13 = pAVar14;
      } while ((DeploySoundClass *)pAVar11 != pDVar19);
    }
    if ((DeploySoundClass *)pAVar14 != pDVar19) {
      sVar22 = *(int *)(this[1].teamInfo[0].PilotWeapon[2] + 0xb) - (int)pDVar19;
      memmove(pAVar14,pDVar19,sVar22);
      *(size_t *)(this[1].teamInfo[0].PilotWeapon[2] + 0xb) = sVar22 + (int)pAVar14;
    }
  }
  pAVar13 = *(AlignTerrainReplaceClass **)(this[1].teamInfo[0].PilotWeapon[2] + 0x17);
  pAVar11 = *(AlignTerrainReplaceClass **)(this[1].teamInfo[0].PilotWeapon[2] + 0x13);
  while ((pAVar11 != pAVar13 && (bVar7 = ShouldRemoveAlignTerrainReplace(pAVar11), !bVar7))) {
    pAVar11 = (AlignTerrainReplaceClass *)&(pAVar11->NormalVec).y;
  }
  pAVar14 = pAVar11;
  if (pAVar11 != pAVar13) {
    while (pAVar6 = pAVar14, pAVar14 = (AlignTerrainReplaceClass *)&(pAVar6->NormalVec).y,
          pAVar14 != pAVar13) {
      bVar7 = ShouldRemoveAlignTerrainReplace(pAVar14);
      if (!bVar7) {
        pAVar11->AlignHandle = (int)*(float *)pAVar14;
        (pAVar11->NormalVec).x = (pAVar6->NormalVec).z;
        pAVar11 = (AlignTerrainReplaceClass *)&(pAVar11->NormalVec).y;
      }
    }
    if (pAVar11 != pAVar13) {
      sVar22 = *(int *)(this[1].teamInfo[0].PilotWeapon[2] + 0x17) - (int)pAVar13;
      memmove(pAVar11,pAVar13,sVar22);
      *(size_t *)(this[1].teamInfo[0].PilotWeapon[2] + 0x17) = sVar22 + (int)pAVar11;
    }
  }
  pDVar19 = *(DeploySoundClass **)(this[1].teamInfo[0].PilotWeapon[2] + 0x23);
  pDVar15 = *(DeploySoundClass **)(this[1].teamInfo[0].PilotWeapon[2] + 0x1f);
  local_1c = pDVar19;
  while ((pDVar15 != pDVar19 && (bVar7 = ShouldRemoveDeploySound(pDVar15), !bVar7))) {
    pDVar15 = pDVar15 + 1;
  }
  if (pDVar15 != pDVar19) {
    pDVar12 = pDVar15 + 1;
    local_18 = pDVar12;
    if (pDVar12 != pDVar19) {
      do {
        bVar7 = ShouldRemoveDeploySound(pDVar12);
        if (!bVar7) {
          pDVar19 = pDVar12;
          pDVar23 = pDVar15;
          for (iVar18 = 0x16; iVar18 != 0; iVar18 = iVar18 + -1) {
            pDVar23->ObjectHandle = pDVar19->ObjectHandle;
            pDVar19 = (DeploySoundClass *)&pDVar19->DoesLoop;
            pDVar23 = (DeploySoundClass *)&pDVar23->DoesLoop;
          }
          pDVar15 = pDVar15 + 1;
          pDVar19 = local_1c;
        }
        pDVar12 = pDVar12 + 1;
      } while (pDVar12 != pDVar19);
    }
    if (pDVar15 != pDVar19) {
      sVar22 = *(int *)(this[1].teamInfo[0].PilotWeapon[2] + 0x23) - (int)pDVar19;
      memmove(pDVar15,pDVar19,sVar22);
      *(char **)(this[1].teamInfo[0].PilotWeapon[2] + 0x23) = (char *)(sVar22 + (int)pDVar15);
    }
  }
  pDVar19 = *(DeploySoundClass **)(this[1].teamInfo[0].PilotWeapon[2] + 0x2f);
  pDVar15 = *(DeploySoundClass **)(this[1].teamInfo[0].PilotWeapon[2] + 0x2b);
  local_1c = pDVar19;
  while ((pDVar15 != pDVar19 && (bVar7 = ShouldRemoveBuildAt((BuildAtClass *)pDVar15), !bVar7))) {
    pDVar15 = (DeploySoundClass *)(pDVar15->DeploySound + 4);
  }
  if (pDVar15 != pDVar19) {
    pDVar12 = (DeploySoundClass *)(pDVar15->DeploySound + 4);
    local_18 = pDVar12;
    if (pDVar12 != pDVar19) {
      do {
        bVar7 = ShouldRemoveBuildAt((BuildAtClass *)pDVar12);
        if (!bVar7) {
          pDVar19 = pDVar12;
          pDVar23 = pDVar15;
          for (iVar18 = 7; iVar18 != 0; iVar18 = iVar18 + -1) {
            pDVar23->ObjectHandle = pDVar19->ObjectHandle;
            pDVar19 = (DeploySoundClass *)&pDVar19->DoesLoop;
            pDVar23 = (DeploySoundClass *)&pDVar23->DoesLoop;
          }
          pDVar15 = (DeploySoundClass *)(pDVar15->DeploySound + 4);
          pDVar19 = local_1c;
        }
        pDVar12 = (DeploySoundClass *)(pDVar12->DeploySound + 4);
      } while (pDVar12 != pDVar19);
    }
    if (pDVar15 != pDVar19) {
      sVar22 = *(int *)(this[1].teamInfo[0].PilotWeapon[2] + 0x2f) - (int)pDVar19;
      memmove(pDVar15,pDVar19,sVar22);
      *(char **)(this[1].teamInfo[0].PilotWeapon[2] + 0x2f) = (char *)(sVar22 + (int)pDVar15);
    }
  }
  for (piVar20 = *(int **)(this[1].teamInfo[0].PilotWeapon[2] + 0x13);
      piVar20 != *(int **)(this[1].teamInfo[0].PilotWeapon[2] + 0x17); piVar20 = piVar20 + 2) {
    piVar1 = piVar20 + 1;
    *piVar1 = *piVar1 + -1;
    if (*piVar1 < 0) {
      RemoveObject(*piVar20);
    }
  }
  piVar20 = *(int **)(this[1].teamInfo[0].PilotWeapon[2] + 0x1f);
  if (piVar20 != *(int **)(this[1].teamInfo[0].PilotWeapon[2] + 0x23)) {
    do {
      if (piVar20[3] < 1) {
        if ((char)piVar20[1] == '\0') {
          StartAudio3D((char *)(piVar20 + 6),*piVar20,AUDIO_CAT_AMBIENT,false,false);
        }
        else {
          local_18 = (DeploySoundClass *)piVar20[2];
          bVar7 = IsAudioPlaying((int *)&local_18);
          bVar8 = BuildingHelper::IsBuildingPowered(this->m_BuildingHelper,*piVar20);
          if (bVar8) {
            if (!bVar7) {
              if (piVar20[4] < 1) {
                iVar18 = StartAudio3D((char *)(piVar20 + 6),*piVar20,AUDIO_CAT_AMBIENT,true,false);
                piVar20[2] = iVar18;
                fVar26 = GetAudioFileDuration(iVar18);
                iVar18 = SecondsToTurns(fVar26);
                piVar20[5] = iVar18;
              }
              else {
                iVar18 = StartAudio3D((char *)(piVar20 + 6),*piVar20,AUDIO_CAT_AMBIENT,false,false);
                piVar20[2] = iVar18;
                fVar26 = GetAudioFileDuration(iVar18);
                iVar18 = SecondsToTurns(fVar26);
                piVar20[5] = iVar18;
                piVar20[3] = piVar20[4] + iVar18;
              }
            }
          }
          else if (bVar7) {
            StopAudio(piVar20[2]);
            piVar20[2] = 0;
          }
        }
      }
      else {
        piVar20[3] = piVar20[3] + -1;
      }
      piVar20 = piVar20 + 0x16;
    } while (piVar20 != *(int **)(this[1].teamInfo[0].PilotWeapon[2] + 0x23));
  }
  piVar20 = *(int **)(this[1].teamInfo[0].PilotWeapon[2] + 0x2b);
  if (piVar20 != *(int **)(this[1].teamInfo[0].PilotWeapon[2] + 0x2f)) {
    pVVar16 = (Vector *)(piVar20 + 1);
    do {
      if (pVVar16[1].x == (float)m_TurnCounter) {
        fVar26 = pVVar16[1].z;
        if (fVar26 == 0.0) {
          fVar26 = pVVar16[1].y;
          iVar18 = 10;
        }
        else if (fVar26 == 1.4013e-45) {
          fVar26 = pVVar16[1].y;
          iVar18 = 0x22;
        }
        else {
          if (fVar26 != 2.8026e-45) goto LAB_4fc0f4a3;
          fVar26 = pVVar16[1].y;
          iVar18 = 8;
        }
        SetCommand(*piVar20,iVar18,(int)fVar26,0,pVVar16,0);
      }
LAB_4fc0f4a3:
      piVar20 = piVar20 + 7;
      pVVar16 = (Vector *)&pVVar16[2].y;
    } while (piVar20 != *(int **)(this[1].teamInfo[0].PilotWeapon[2] + 0x2f));
  }
  iVar18 = 0;
  pTVar21 = this->teamInfo;
  do {
    bVar7 = IsPlayer(pTVar21->RealPlayer);
    if (((bVar7) && (iVar9 = GetTeamNum(pTVar21->RealPlayer), iVar9 != iVar18)) && (0 < iVar9)) {
      if (Logging != false) {
        FormatLogMessage("Switching Player TeamInfo from Team: %d to Team: %d");
      }
      iVar9 = iVar9 * 0xa14;
      iVar3 = *(int *)((int)this->teamInfo + iVar9);
      *(int *)((int)this->teamInfo + iVar9) = pTVar21->RealPlayer;
      pTVar21->RealPlayer = iVar3;
      iVar3 = *(int *)((int)this->teamInfo + iVar9 + 0xd4);
      *(int *)((int)this->teamInfo + iVar9 + 0xd4) = pTVar21->PlayerLives;
      pTVar21->PlayerLives = iVar3;
      uVar2 = *(undefined1 *)((int)this->teamInfo + iVar9 + 0x10d);
      *(undefined1 *)((int)this->teamInfo + iVar9 + 0x10d) =
           *(undefined1 *)((int)&pTVar21->m_CPUDayWreckerChance + 1);
      *(undefined1 *)((int)&pTVar21->m_CPUDayWreckerChance + 1) = uVar2;
    }
    iVar18 = iVar18 + 1;
    pTVar21 = (TeamInfo *)&pTVar21[1].CommTower;
  } while (iVar18 < 0x10);
  pVVar16 = (Vector *)&this->teamInfo[0].GoalPos.y;
  local_24 = 0;
  do {
    bVar7 = IsPlayer((int)pVVar16[-0x1c].z);
    if (!bVar7) {
      fVar26 = (float)GetPlayerHandle(local_24);
      pVVar16[-0x1c].z = fVar26;
    }
    pcVar10 = GetPlan(local_24);
    if ((*pcVar10 != '\0') &&
       (iVar18 = _stricmp(pcVar10,(char *)((int)&pVVar16[0xd].z + 1)), iVar18 != 0)) {
      UpdateTeamAIP(this,pcVar10,local_24);
    }
    if (((*(char *)((int)&pVVar16[-5].y + 2) != '\0') &&
        (bVar7 = IsPerson((int)pVVar16[-0x1c].z), bVar7)) &&
       (bVar7 = IsNullVector(*pVVar16), !bVar7)) {
      GetPosition((int)pVVar16[-0x1c].z,&local_14);
      fVar26 = pVVar16->z - local_14.z;
      fVar5 = pVVar16->x - local_14.x;
      local_18 = (DeploySoundClass *)(fVar5 * fVar5 + fVar26 * fVar26);
      fVar25 = (float10)__CIsqrt();
      local_18 = (DeploySoundClass *)(float)fVar25;
      if (___real_40a00000 < (float)local_18) {
        SetVectorPosition((int)pVVar16[-0x1c].z,*pVVar16);
      }
    }
    local_24 = local_24 + 1;
    *(undefined1 *)((int)&pVVar16[-5].y + 3) = 0;
    pVVar16 = pVVar16 + 0xd7;
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
  local_18 = (DeploySoundClass *)this->m_ScrapHelper;
  pDVar4 = *(DispatchClass **)&local_18->DoesLoop;
  _Var24._Ptr = *(DispatchClass **)&local_18->ObjectHandle;
  while ((_Var24._Ptr != pDVar4 &&
         (bVar7 = ShouldRemoveAlignTerrainReplace((AlignTerrainReplaceClass *)_Var24._Ptr), !bVar7))
        ) {
    _Var24._Ptr = (DispatchClass *)&(_Var24._Ptr)->DispatchTarget;
  }
  pDVar17 = _Var24._Ptr;
  if (_Var24._Ptr != pDVar4) {
    while (pDVar17 = (DispatchClass *)&pDVar17->DispatchTarget, pDVar17 != pDVar4) {
      bVar7 = ShouldRemoveAlignTerrainReplace((AlignTerrainReplaceClass *)pDVar17);
      if (!bVar7) {
        (_Var24._Ptr)->DispatchObject = (int)((Vector *)pDVar17)->x;
        _Var24._Ptr = (DispatchClass *)&(_Var24._Ptr)->DispatchTarget;
      }
    }
  }
  std::vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>::erase
            ((vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_> *
             )local_18,(DispatchClass *)&local_1c,_Var24);
  DispatchHelper::Execute(this->m_DispatchHelper,this);
  MorphObjectHelper::Execute(this->m_MorphObjectHelper,this);
  CarrierHelper::Execute(this->m_CarrierHelper,this);
  *(int *)(this[1].teamInfo[0].PilotWeapon[3] + 3) =
       (*(int *)&(this->m_ObjectHelper->HandleList).field_0x4 -
       *(int *)&this->m_ObjectHelper->HandleList) / 0x5c;
  return;
}


// ---------------------------------------------------------------------
// BZ1Helper::PreSnipe  @ 4fc0f75a  lines 2443-2525


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

PreSnipeReturnCodes __thiscall
BZ1Helper::PreSnipe(BZ1Helper *this,int param_1,int param_2,int param_3,int param_4,char *param_5)

{
  bool bVar1;
  PreSnipeReturnCodes PVar2;
  int iVar3;
  int iVar4;
  TEAMRELATIONSHIP TVar5;
  int iVar6;
  uint unaff_ESI;
  int *unaff_EDI;
  int local_cc;
  char *local_c8;
  byte local_c4 [64];
  char local_84 [64];
  char local_44 [64];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)&local_cc;
  local_c8 = param_5;
  if (param_1 == 0) {
    PVar2 = PRESNIPE_KILLPILOT;
    local_cc = 0;
    iVar3 = GetTeamNum(param_3);
    if (param_4 == 0) {
      param_4 = GetTeamNum(param_2);
    }
    memset(local_84,0,0x40);
    memset(local_c4,0,0x40);
    strcpy_s(local_84,0x40,local_c8);
    memset(local_44,0,0x40);
    bVar1 = OpenODF2((char *)unaff_EDI);
    if ((bVar1) &&
       (iVar4 = GetODFString(local_84,"OrdnanceClass","classlabel",0x40,local_44,(char *)0x0),
       iVar4 != 0)) {
      CombineStrings(".odf",(char *)0x40,(char *)unaff_EDI,unaff_ESI);
      bVar1 = OpenODF2((char *)unaff_EDI);
      local_c4[0] = local_c4[0] & -bVar1;
    }
    GetODFInt("SniperShellClass","TeamFilter",(char *)&local_cc,(char *)0x0,unaff_EDI,unaff_ESI);
    if ((param_4 == 0) || (local_cc == 0)) {
      local_cc = 7;
    }
    bVar1 = IsNetworkOn();
    if (((((bVar1) && (this[1].teamInfo[0].PilotWeapon[4][0x1a] == '\0')) &&
         (TVar5 = GetTeamRelationship(param_2,param_3), TVar5 == TEAMRELATIONSHIP_ALLIEDTEAM)) &&
        ((bVar1 = IsPlayer(param_3), bVar1 || (iVar3 != 0)))) ||
       (bVar1 = TeamFilterCheck(param_4,(int)unaff_EDI,unaff_ESI), !bVar1)) {
      PVar2 = PRESNIPE_ONLYBULLETHIT;
    }
    else {
      SetPerceivedTeam(param_3,0);
      iVar4 = iVar3 * 0xa14;
      if ((param_3 == *(int *)((int)this->teamInfo + iVar4 + 4)) &&
         (iVar6 = GetPlayerHandle(iVar3), iVar6 == *(int *)((int)this->teamInfo + iVar4 + 8))) {
        SetAsUser(*(int *)((int)this->teamInfo + iVar4 + 4),iVar3);
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
BZ1Helper::PreOrdnanceHit(BZ1Helper *this,int param_1,int param_2,int param_3,char *param_4)

{
  bool bVar1;
  int iVar2;
  long lVar3;
  int extraout_EAX;
  bool *unaff_ESI;
  uint uVar4;
  uint unaff_EDI;
  undefined1 auStack_d8 [3];
  char local_d5;
  uint local_d4;
  float local_d0;
  int local_cc;
  char *local_c8;
  byte local_c4 [64];
  char local_84 [64];
  char local_44 [64];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)auStack_d8;
  local_c8 = param_4;
  if (param_2 == 0) {
    return;
  }
  memset(local_84,0,0x40);
  memset(local_c4,0,0x40);
  strcpy_s(local_84,0x40,param_4);
  memset(local_44,0,0x40);
  bVar1 = OpenODF2(unaff_ESI);
  if ((bVar1) &&
     (iVar2 = GetODFString(local_84,"OrdnanceClass","classlabel",0x40,local_44,(char *)0x0),
     iVar2 != 0)) {
    CombineStrings(".odf",(char *)0x40,unaff_ESI,unaff_EDI);
    bVar1 = OpenODF2(unaff_ESI);
    local_c4[0] = local_c4[0] & -bVar1;
  }
  bVar1 = IsNetworkOn();
  if (((bVar1) && (m_GameType == 2)) &&
     (__real_3f800000 < *(float *)(this[1].teamInfo[0].PilotWeapon[4] + 0x2b))) {
    iVar2 = _stricmp(local_44,"bouncebomb");
    if (iVar2 == 0) {
      local_cc = -1;
      GetODFInt(0x4fc5c2c0,(char *)&local_cc,(char *)0xffffffff,(int *)unaff_ESI,unaff_EDI);
      if ((local_cc == 0) || ((local_cc == -1 && (bVar1 = IsBuilding(param_2), bVar1))))
      goto LAB_4fc0fbb4;
    }
    else {
      iVar2 = _stricmp(local_44,"spraybomb");
      if (iVar2 == 0) {
        local_d5 = '\0';
        GetODFBool("SprayBombClass","ExplodeOnHit",&local_d5,(char *)0x0,unaff_ESI,
                   SUB41(unaff_EDI,0));
        if (local_d5 == '\0') goto LAB_4fc0fbb4;
        local_d4 = 0;
        GetODFInt("SprayBombClass","HitExplodeTypes",(char *)&local_d4,(char *)0x0,(int *)unaff_ESI,
                  unaff_EDI);
        if (local_d4 != 0) {
          bVar1 = IsBuilding(param_2);
          uVar4 = (uint)bVar1;
          bVar1 = IsCraftButNotPerson(param_2);
          if (bVar1) {
            uVar4 = uVar4 | 2;
          }
          bVar1 = IsPerson(param_2);
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
    lVar3 = GetOrdnanceDamageDealt(0,unaff_ESI,SUB41(unaff_EDI,0));
    local_d0 = (float)lVar3;
    _ftol2_sse();
    local_d0 = (float)(extraout_EAX - lVar3);
    iVar2 = GetCurWorld();
    if (iVar2 == 0) {
      Damage(param_2,param_1,(long)local_d0);
    }
  }
LAB_4fc0fbb4:
  local_d4 = GetTeamNum(param_2);
  iVar2 = param_3;
  if (param_3 == 0) {
    iVar2 = GetTeamNum(param_1);
  }
  bVar1 = IsTeamAllied(local_d4,iVar2);
  if (!bVar1) {
    iVar2 = GetPlayerHandle(local_d4);
    if (iVar2 == 0) {
      (**(code **)(this->m_DispatchHelper->_padding_ + 4))(param_1,param_2,param_3,local_c8);
    }
    (**(code **)(this->m_CarrierHelper->_padding_ + 4))(param_1,param_2,param_3,local_c8);
  }
  return;
}


// ---------------------------------------------------------------------
// BZ1Helper::PreGetIn  @ 4fc0fc31  lines 2677-2705


PreGetInReturnCodes __thiscall
BZ1Helper::PreGetIn(BZ1Helper *this,int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  if (param_1 == 0) {
    iVar1 = GetTeamNum(param_2);
    iVar2 = GetTeamNum(param_3);
    if (iVar2 != iVar1) {
      iVar4 = 0;
      piVar3 = *(int **)&this->m_ObjectHelper->HandleList;
      iVar2 = (*(int *)&(this->m_ObjectHelper->HandleList).field_0x4 - (int)piVar3) / 0x5c;
      if (0 < iVar2) {
        do {
          if (*piVar3 == param_3) {
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
      SetCommand(param_3,0,0,0,(char *)0x0,0);
    }
  }
  return PREGETIN_ALLOW;
}


// ---------------------------------------------------------------------
// BZ1Helper::PrePickupPowerup  @ 4fc0fca9  lines 2709-2951


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

PrePickupPowerupReturnCodes __thiscall
BZ1Helper::PrePickupPowerup(BZ1Helper *this,int param_1,int param_2,int param_3)

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
  if (param_1 == 0) {
    memset(local_44,0,0x40);
    bVar1 = GetObjInfo(param_3,Get_ODF,local_44);
    if (bVar1) {
      memset(local_84,0,0x40);
      bVar1 = GetObjInfo(param_2,Get_ODF,local_84);
      if (bVar1) {
        memset(local_c4,0,0x40);
        bVar1 = GetObjInfo(param_3,Get_GOClass,local_c4);
        if ((bVar1) &&
           ((uVar2 = Hash(unaff_EDI,unaff_ESI), uVar2 == 0xa662aa60 || (uVar2 == 0x33fe0a68)))) {
          PVar3 = (**(code **)(this->m_MorphObjectHelper->_padding_ + 4))
                            (0,param_2,param_3,uVar2,local_84);
          return PVar3;
        }
      }
    }
  }
  return PREPICKUPPOWERUP_ALLOW;
}


// ---------------------------------------------------------------------
// BZ1Helper::PostTeleport  @ 4fc0fda5  lines 2955-2965


PostTeleportReturnCodes __thiscall BZ1Helper::PostTeleport(BZ1Helper *this,int param_1,int param_2)

{
  return PostTeleport_DEFAULT;
}


// ---------------------------------------------------------------------
// BZ1Helper::DeadObject  @ 4fc0fdaa  lines 2969-2971


void __thiscall BZ1Helper::DeadObject(BZ1Helper *this,int param_1)

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
      if (*piVar5 == param_1) {
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
  int unaff_ESI;
  int iVar6;
  int unaff_EDI;
  float fVar7;
  char *pcVar8;
  int local_70;
  int local_6c;
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  int *local_58;
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
      if (((iVar3 == 0) &&
          (bVar2 = IsAudioMessageDone(*(int *)(this[1].teamInfo[0].PilotWeapon[3] + 0xf)), bVar2))
         && (pcVar8 = this[1].teamInfo[0].PilotWeapon[3] + 0x13, *(int *)pcVar8 != 0)) {
        iVar4 = AudioMessage(pcVar8,false);
        *(int *)(this[1].teamInfo[0].PilotWeapon[3] + 0xf) = iVar4;
      }
      IFace_SetInteger("script.dll.repeataudio",0);
    }
    if (((0 < *(int *)(this[1].teamInfo[0].PilotWeapon[2] + 0x3f)) && (iVar3 == 0)) &&
       ((iVar3 = GetLocalPlayerTeamNumber(),
        *(char *)((int)this->teamInfo + iVar3 * 0xa14 + 0x10d) != '\0' &&
        (iVar3 = GetLocalPlayerTeamNumber(),
        *(char *)((int)this->teamInfo + iVar3 * 0xa14 + 0x10e) == '\0')))) {
      IFace_ConsoleCmd("mission.escape",true);
    }
    memset(local_50,0,0x40);
    iVar3 = 0;
    do {
      iVar3 = iVar3 + 1;
      sprintf_s<64>(&local_50,"script.dll.pilotcost%d");
      IFace_SetString(local_50,"");
    } while (iVar3 < 10);
    local_64 = 0;
    local_68 = 1;
    local_6c = 0x23a;
    pcVar5 = IFace_SetFloat_exref;
    iVar3 = local_60;
    do {
      iVar4 = local_68;
      local_70 = GetObjectByBaseSlot(unaff_EDI,unaff_ESI);
      if (local_70 != 0) {
        sprintf_s<64>(&local_50,"script.dll.base%dhull");
        fVar7 = GetHealth(local_70);
        (*pcVar5)(local_50,fVar7);
        sprintf_s<64>(&local_50,"script.dll.basename%d");
        IFace_SetString(local_50,(char *)((int)this->teamInfo + local_64 + iVar3 * 0xa14 + 0x4ad));
        iVar4 = local_68;
        local_58 = &this->_padding_ + iVar3 * 0x285;
        if (((*(char *)((int)local_58 + local_68 + 0xa4f) != '\0') &&
            (bVar2 = IsBuilding(local_70), bVar2)) &&
           (bVar2 = IsSelected(local_70), iVar1 = local_70, bVar2)) {
          local_54 = iVar3 * 0x285;
          local_5c = local_6c + -0x5a + local_54;
          iVar6 = 0;
          do {
            local_70 = iVar6 + 1;
            sprintf_s<64>(&local_50,"script.dll.pilotcost%d");
            if ((&this->_padding_)[local_5c + iVar6] == 1) {
              IFace_SetString(local_50,"P");
            }
            else if (1 < (&this->_padding_)[local_5c + iVar6]) {
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
              _snprintf_s<10>((char (*) [10])local_10,0xffffffff,"%d");
              IFace_SetString(local_50,local_10);
              iVar3 = local_60;
            }
            if (((local_58[0x49] < (&this->_padding_)[local_5c + iVar6]) ||
                (iVar4 = (*misnImport.GetScrap)(iVar3),
                iVar4 < (&this->_padding_)[local_6c + local_54 + iVar6])) ||
               (bVar2 = IsBusy(iVar1), bVar2)) {
              sprintf_s<64>(&local_50,"CommandPanel.Command%d.Item.Cost.PilotCost");
              if (iVar6 == 9) {
                sprintf_s<64>(&local_50,"CommandPanel.Command0.Item.Cost.PilotCost");
              }
              IFace_Deactivate(local_50);
              sprintf_s<64>(&local_50,"CommandPanel.Command%d.Item.Cost.PilotCostDisabled");
              if (iVar6 == 9) {
                pcVar8 = "CommandPanel.Command0.Item.Cost.PilotCostDisabled";
                goto LAB_4fc10153;
              }
            }
            else {
              sprintf_s<64>(&local_50,"CommandPanel.Command%d.Item.Cost.PilotCostDisabled");
              if (iVar6 == 9) {
                sprintf_s<64>(&local_50,"CommandPanel.Command0.Item.Cost.PilotCostDisabled");
              }
              IFace_Deactivate(local_50);
              sprintf_s<64>(&local_50,"CommandPanel.Command%d.Item.Cost.PilotCost");
              if (iVar6 == 9) {
                pcVar8 = "CommandPanel.Command0.Item.Cost.PilotCost";
LAB_4fc10153:
                sprintf_s<64>(&local_50,pcVar8);
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
    iVar4 = iVar3 * 0xa14;
    if (*(char *)((int)this->teamInfo + iVar4 + 0x10f) == '\0') {
      iVar3 = GetPower(iVar3);
      IFace_SetInteger("script.dll.currpilots",iVar3);
      iVar3 = GetMaxPower(local_60);
      IFace_SetInteger("script.dll.maxpilots",iVar3);
      IFace_SetString("script.dll.pilotname","Power");
    }
    else {
      IFace_SetInteger("script.dll.currpilots",*(int *)((int)this->teamInfo + iVar4 + 0x94));
      IFace_SetInteger("script.dll.maxpilots",*(int *)((int)this->teamInfo + iVar4 + 0x90));
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
    if (*(char *)((int)piVar5 + 0x39) != '\0') {
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
  Vector VVar1;
  bool bVar2;
  int iVar3;
  BZ1Helper *this_00;
  Vector *unaff_ESI;
  int unaff_EDI;
  Vector local_18;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  bVar2 = IsNetworkOn();
  if ((((bVar2) && (0 < DeathCameraTeam)) &&
      (iVar3 = GetPlayerHandle(DeathCameraTeam), DeathCameraOn != false)) &&
     ((bVar2 = IsAround(iVar3), bVar2 && (0 < DeathCameraTeam)))) {
    local_18.x = 0.0;
    local_18.y = 0.0;
    local_18.z = 0.0;
    SetVelocity(iVar3,&local_18);
    local_18.x = 0.0;
    local_18.y = 0.0;
    local_18.z = 0.0;
    SetOmega(iVar3,&local_18);
    local_18.y = 0.0;
    local_18.z = 0.0;
    local_c = 0x41200000;
    local_8 = 0x41200000;
    local_4 = 0x41200000;
    local_18.x = 10.0;
    VVar1.z = (float)&local_18;
    VVar1.x = 10.0;
    VVar1.y = 10.0;
    bVar2 = CameraCircle(0x41200000,VVar1,unaff_EDI,unaff_ESI);
    if ((bVar2) || (DeathCameraTime < m_TurnCounter)) {
      bVar2 = IsNetworkOn();
      if (bVar2) {
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
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall BZ1Helper::SetupClouds(BZ1Helper *this,char *param_1)

{
  int iVar1;
  char *pcVar2;
  float extraout_EAX;
  int extraout_EAX_00;
  int iVar3;
  int *piVar4;
  float *pfVar5;
  int unaff_ESI;
  Matrix *pMVar6;
  float unaff_EDI;
  int iVar7;
  Matrix *pMVar8;
  float10 fVar9;
  float fVar10;
  float fVar11;
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
  int local_4218 [16];
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
  GetODFInt(param_1,"Clouds","Type",&local_4228,0);
  GetODFInt(param_1,"Clouds","Count",&local_4220,0);
  if (local_4220 < 0) {
    local_4220 = 0;
  }
  else if (0x40 < local_4220) {
    local_4220 = 0x40;
  }
  GetODFInt(param_1,"Clouds","TileSize",&local_421c,0);
  memset(local_48,0,0x40);
  pcVar2 = local_4148;
  iVar7 = 1;
  piVar4 = local_4218;
  do {
    local_42c0 = 0.0;
    local_42b9 = '\0';
    local_42b8 = pcVar2;
    local_42b4 = pcVar2;
    do {
      local_42c0 = (float)((int)local_42c0 + 1);
      sprintf_s<64>((char (*) [64])local_48,"Name%d_%d");
      iVar1 = GetODFString(param_1,"Clouds",local_48,0x40,local_42b8,(char *)0x0);
      if (iVar1 == 0) {
        sprintf_s<64>((char (*) [64])local_48,"Name%d");
        iVar1 = GetODFString(param_1,"Clouds",local_48,0x40,pcVar2,pcVar2);
        if (iVar1 == 0) break;
      }
      else {
        *piVar4 = *piVar4 + 1;
      }
      local_42b8 = local_42b8 + 0x40;
      local_42b9 = '\x01';
    } while ((int)local_42c0 < 0x10);
    if (local_42b9 == '\0') break;
    local_4224 = local_4224 + 1;
    sprintf_s<64>((char (*) [64])local_48,"Height%d");
    GetODFFloat(param_1,"Clouds",local_48,(float *)(piVar4 + 0x24),__real_42c80000);
    sprintf_s<64>((char (*) [64])local_48,"Team%d");
    GetODFInt(param_1,"Clouds",local_48,piVar4 + 0x14,0);
    pcVar2 = local_42b4 + 0x400;
    piVar4 = piVar4 + 1;
    iVar7 = iVar7 + 1;
    local_42b4 = pcVar2;
  } while (iVar7 < 0x11);
  iVar7 = (int)local_42b0._0_4_;
  local_42a0 = (double)local_421c;
  fVar10 = *(float *)((int)local_42b0._0_4_ + 0x68) / (float)local_421c;
  local_42c0 = fVar10;
  floor(unaff_EDI);
  fVar11 = *(float *)(iVar7 + 0x70) / (float)local_42a0;
  local_42c0 = fVar11;
  local_42b0._0_4_ = fVar10;
  floor(unaff_EDI);
  local_42c0 = fVar11;
  _ftol2_sse();
  fVar10 = *(float *)(iVar7 + 100) / (float)local_42a0;
  local_42c0 = fVar10;
  local_42b8 = (char *)extraout_EAX;
  floor(unaff_EDI);
  fVar11 = *(float *)(iVar7 + 0x6c) / (float)local_42a0;
  local_42c0 = fVar11;
  local_42b0._0_4_ = fVar10;
  floor(unaff_EDI);
  local_42c0 = fVar11;
  _ftol2_sse();
  iVar1 = extraout_EAX_00 * (int)extraout_EAX * local_4224 * local_4220;
  if (0x400 < iVar1) {
    iVar1 = (iVar1 + -0x400) / (int)local_42b8;
    local_42b0 = (double)CONCAT44(local_42b0._4_4_,iVar1);
    local_42c0 = (float)(iVar1 / extraout_EAX_00);
    local_426c = (int)local_42c0 / local_4224;
    if (Logging != false) {
      FormatLogMessage(
                      "Total Clouds: %d, TileCountX: %d, TileCountZ: %d, Difference: %d, DiffX: %d DiffZ: %d, DiffType: %d"
                      );
    }
    local_4220 = local_4220 - local_426c;
    FormatLogMessage(
                    "ERROR: Too many Clouds: (%d > %d), Count Per Tile: %d. Correcting to: %d, %d Per Tile."
                    );
  }
  local_42b0 = (double)*(float *)(iVar7 + 0x68);
  local_4290 = (double)*(float *)(iVar7 + 0x70);
  local_4280 = (double)((*(float *)(iVar7 + 0x6c) + *(float *)(iVar7 + 100)) *
                       (float)___real_3fe0000000000000);
  local_42a0 = (double)local_421c;
  local_42c0 = (*(float *)(iVar7 + 100) - *(float *)(iVar7 + 0x6c)) / (float)local_421c;
  fVar9 = floor((double)local_42c0);
  fVar9 = (float10)(float)((float10)(float)fVar9 * (float10)local_42a0) *
          (float10)___real_3fe0000000000000;
  local_41d0 = (char *)(float)((float10)local_4280 - fVar9);
  local_41d8 = (float)((float10)local_4280 + fVar9);
  local_4280 = (double)(float)(((float10)local_4290 + (float10)local_42b0) *
                              (float10)___real_3fe0000000000000);
  local_42c0 = (float)(((float10)local_42b0 - (float10)local_4290) / (float10)local_42a0);
  fVar9 = floor((double)local_42c0);
  local_42c0 = (float)fVar9 * (float)local_42a0;
  local_4278 = 0;
  local_42a0 = 0.0;
  local_4288 = 0;
  local_41d4 = (float)local_4280;
  local_4280 = 0.0;
  local_41cc = local_41d4 - local_42c0 * (float)___real_3fe0000000000000;
  local_42a8 = 0;
  local_4298 = 0x3f800000;
  local_4290 = 0.0078125;
  local_42b0 = 5.26354424712089e-315;
  local_41d4 = local_41d4 + local_42c0 * (float)___real_3fe0000000000000;
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
    pfVar5 = local_4188;
    local_42c0 = 0.0;
    iVar3 = local_4224;
    fVar10 = local_41d8;
    do {
      local_42b4 = local_41d0;
      fVar11 = local_42c0;
      if ((float)local_41d0 <= fVar10) {
        do {
          local_42b8 = (char *)local_41cc;
          if (local_41cc <= local_41d4) {
            do {
              local_426c = 0;
              if (0 < local_4220) {
                do {
                  local_42a0._0_4_ = (float)GetRandomInt((int)unaff_EDI,unaff_ESI);
                  if (Logging != false) {
                    FormatLogMessage("Placing Cloud: Random is: %d Cloud ODF is: \'%s\'");
                  }
                  iVar3 = GetRandomInt((int)unaff_EDI,unaff_ESI);
                  fVar10 = (float)local_421c;
                  pMVar6 = local_148 + iVar3;
                  pMVar8 = &local_4268;
                  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
                    (pMVar8->right).x = (pMVar6->right).x;
                    pMVar6 = (Matrix *)&(pMVar6->right).y;
                    pMVar8 = (Matrix *)&(pMVar8->right).y;
                  }
                  fVar11 = GetRandomFloat(fVar10);
                  fVar10 = (float)local_421c;
                  local_4268.posit.x =
                       (fVar11 + (float)local_42b4) - fVar10 * (float)___real_3fe0000000000000;
                  local_4280 = (double)(float)local_42b8;
                  local_4290._0_4_ = fVar10;
                  fVar10 = GetRandomFloat(fVar10);
                  local_4290 = (double)CONCAT44(local_4290._4_4_,(float)local_421c);
                  local_4268.posit.z =
                       (fVar10 + (float)local_4280) -
                       (float)local_421c * (float)___real_3fe0000000000000;
                  if (local_4228 == 0) {
                    local_4268.posit.y = *pfVar5;
                  }
                  else {
                    local_4268.posit.y = TerrainFindFloor(local_4268.posit.x,local_4268.posit.z);
                    local_4268.posit.y = local_4268.posit.y + *pfVar5;
                  }
                  fVar11 = local_42c0;
                  fVar10 = pfVar5[-0x10];
                  *(undefined1 *)(iVar7 + 0xa269) = 1;
                  BuildObject(local_4148 + ((int)(float)local_42a0 + (int)local_42c0) * 0x40,
                              (int)fVar10,&local_4268);
                  local_4270 = local_4270 + 1;
                  local_426c = local_426c + 1;
                  *(undefined1 *)(iVar7 + 0xa269) = 0;
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
        fVar10 = local_41d8;
      }
      iVar1 = iVar1 + 1;
      local_42c0 = (float)((int)fVar11 + 0x10);
      pfVar5 = pfVar5 + 1;
      local_42b0 = (double)CONCAT44(local_42b0._4_4_,iVar1);
    } while (iVar1 < iVar3);
  }
  if (Logging != false) {
    FormatLogMessage("Map Width Is: %f");
    FormatLogMessage("Map Depth Is: %f");
    FormatLogMessage("Clouds Specified Are: %d");
    FormatLogMessage("Cloud Count Per Type is: %d");
    FormatLogMessage("Cloud Type Count is: %d");
    FormatLogMessage("Total Clouds are: %d");
  }
  return;
}


// ---------------------------------------------------------------------
// BZ1Helper::SetAIPFile  @ 4fc10f10  lines 3698-3712


bool __thiscall BZ1Helper::SetAIPFile(BZ1Helper *this,char *param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  
  if ((uint)param_2 < 0x10) {
    iVar2 = 2;
    if (param_2 != -1) {
      iVar2 = param_2;
    }
    SetPlan(param_1,iVar2);
    bVar1 = UpdateTeamAIP(this,param_1,iVar2);
  }
  else {
    bVar1 = false;
  }
  return bVar1;
}


// ---------------------------------------------------------------------
// BZ1Helper::UpdateTeamAIP  @ 4fc10f49  lines 3714-3749


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool __thiscall BZ1Helper::UpdateTeamAIP(BZ1Helper *this,char *param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  float *pfVar4;
  int iVar5;
  char *unaff_EDI;
  
  bVar1 = OpenODF2(unaff_EDI);
  if (bVar1) {
    iVar5 = param_2 * 0xa14;
    strcpy_s((char *)((int)this->teamInfo + iVar5 + 0x1ed),0x100,param_1);
    GetODFInt(param_1,"Cheat","pilotAmount",(int *)((int)this->teamInfo + iVar5 + 0x9c),0);
    GetODFFloat(param_1,"Cheat","pilotDelay",(float *)((int)this->teamInfo + iVar5 + 0x130),
                ___real_41700000);
    GetODFInt(param_1,"Start","Difficulty",(int *)((int)this->teamInfo + iVar5 + 0x98),0);
    piVar3 = (int *)((int)this->teamInfo + iVar5 + 0x98);
    iVar2 = *piVar3;
    if (iVar2 < 0) {
      iVar2 = 0;
    }
    else if (4 < iVar2) {
      iVar2 = 4;
    }
    *piVar3 = iVar2;
    GetODFBool(param_1,"Start","UnitsService",(bool *)((int)this->teamInfo + iVar5 + 0x11d),false);
    GetODFBool(param_1,"IdleDispatcher","DoDLLDispatch",
               (bool *)((int)this->teamInfo + iVar5 + 0x11e),true);
    GetODFInt(param_1,"IdleDispatcher","MaxPatrolUnits",(int *)((int)this->teamInfo + iVar5 + 0xa0),
              0);
    GetODFInt(param_1,"IdleDispatcher","MaxHuntUnits",(int *)((int)this->teamInfo + iVar5 + 0xa4),0)
    ;
    GetODFInt(param_1,"IdleDispatcher","MaxEscortUnits",(int *)((int)this->teamInfo + iVar5 + 0xa8),
              0);
    GetODFFloat(param_1,"Start","BuildingRepairChance",
                (float *)((int)this->teamInfo + iVar5 + 0x134),___real_3f4ccccd);
    GetODFFloat(param_1,"Start","BuildingRepairInterval",
                (float *)((int)this->teamInfo + iVar5 + 0x138),___real_41f00000);
    GetODFFloat(param_1,"Start","BuildingRepairHealthRatio",
                (float *)((int)this->teamInfo + iVar5 + 0x13c),__real_3f000000);
    GetODFFloat(param_1,"Start","BuildPodMinDelay",(float *)((int)this->teamInfo + iVar5 + 0x140),
                ___real_40a00000);
    GetODFFloat(param_1,"Start","BuildPodMaxDelay",(float *)((int)this->teamInfo + iVar5 + 0x144),
                ___real_42700000);
    if (this[1].teamInfo[0].PilotWeapon[4][0x1f] != '\0') {
      GetODFFloat(param_1,"Start","DayWreckerChance",(float *)((int)this->teamInfo + iVar5 + 0x128),
                  0.0);
      pfVar4 = (float *)((int)this->teamInfo + iVar5 + 300);
      GetODFFloat(param_1,"Start","DayWreckerInterval",pfVar4,___real_41f00000);
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
          (BZ1Helper *this,int param_1,float param_2,bool param_3,int param_4,bool param_5,
          bool param_6,bool param_7,bool param_8)

{
  bool bVar1;
  
  bVar1 = DispatchHelper::AddToDispatch
                    (this->m_DispatchHelper,param_1,param_2,param_3,param_4,param_5,param_6,param_7,
                     param_8);
  return bVar1;
}


// ---------------------------------------------------------------------
// BZ1Helper::DeleteAfterDelay  @ 4fc111c4  lines 4019-4035


void __thiscall BZ1Helper::DeleteAfterDelay(BZ1Helper *this,int param_1,float param_2)

{
  vector<BZ1Helper::DeleteAfterDelayClass,std::allocator<BZ1Helper::DeleteAfterDelayClass>_>
  *this_00;
  int iVar1;
  bool bVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  
  bVar2 = IsAround(param_1);
  if (bVar2) {
    this_00 = (vector<BZ1Helper::DeleteAfterDelayClass,std::allocator<BZ1Helper::DeleteAfterDelayClass>_>
               *)(this[1].teamInfo[0].PilotWeapon[2] + 0x13);
    for (piVar3 = *(int **)this_00; piVar3 != *(int **)(this[1].teamInfo[0].PilotWeapon[2] + 0x17);
        piVar3 = piVar3 + 2) {
      if (*piVar3 == param_1) {
        return;
      }
    }
    std::vector<BZ1Helper::DeleteAfterDelayClass,std::allocator<BZ1Helper::DeleteAfterDelayClass>_>
    ::_Resize<<lambda_4cef8f5d2e224a10ec5594e33bb09482>_>
              (this_00,(*(int *)(this[1].teamInfo[0].PilotWeapon[2] + 0x17) - *(int *)this_00 >> 3)
                       + 1,(<lambda_4cef8f5d2e224a10ec5594e33bb09482>)this_00);
    iVar1 = *(int *)this_00;
    iVar5 = *(int *)(this[1].teamInfo[0].PilotWeapon[2] + 0x17) - iVar1 >> 3;
    *(undefined4 *)(iVar1 + -8 + iVar5 * 8) = 0;
    *(undefined4 *)(iVar1 + -4 + iVar5 * 8) = 0;
    *(int *)(iVar1 + -8 + iVar5 * 8) = param_1;
    iVar4 = SecondsToTurns(param_2);
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
  int iVar5;
  Vector *unaff_ESI;
  int *piVar6;
  Vector *unaff_EDI;
  int iVar7;
  float fVar8;
  
  iVar7 = *(int *)(this[1].teamInfo[0].PilotWeapon[3] + 3) + -1;
  if (iVar7 < 0) {
    iVar7 = 0;
  }
  else {
    iVar3 = (*(int *)&(this->m_ObjectHelper->HandleList).field_0x4 -
            *(int *)&this->m_ObjectHelper->HandleList) / 0x5c + -1;
    if (iVar3 < iVar7) {
      iVar7 = iVar3;
    }
  }
  iVar4 = GetRandomInt((int)unaff_EDI,(int)unaff_ESI);
  iVar3 = iVar4;
  do {
    piVar6 = (int *)(iVar3 * 0x5c + *(int *)&this->m_ObjectHelper->HandleList);
    iVar1 = *piVar6;
    if (param_1 < 0) {
LAB_4fc112cc:
      if ((((0 < piVar6[0x15]) && ((!param_7 || (*(char *)((int)piVar6 + 0x17) != '\0')))) &&
          ((param_11 <= 0.0 ||
           (fVar8 = GetDistance3DSquared(unaff_EDI,unaff_ESI), fVar8 < param_11 * param_11)))) &&
         (piVar6[4] != 0)) {
        return iVar1;
      }
    }
    else {
      if (param_3) {
        iVar5 = piVar6[8];
      }
      else {
        iVar5 = piVar6[7];
      }
      bVar2 = TeamFilterCheck(iVar5,(int)unaff_EDI,(int)unaff_ESI);
      if (bVar2) goto LAB_4fc112cc;
    }
    iVar1 = iVar3 + 1;
    iVar3 = 0;
    if (iVar1 <= iVar7) {
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
  int iVar3;
  int iVar4;
  uint uVar5;
  Vector *unaff_ESI;
  int iVar6;
  Vector *unaff_EDI;
  int iVar7;
  float fVar8;
  uint local_10;
  
  uVar2 = 0xffffffff;
  if (param_6 != 0) {
    uVar2 = param_6;
  }
  uVar5 = 0xffffffff;
  if (param_10 != 0) {
    uVar5 = param_10;
  }
  local_10 = 0;
  param_6 = 0;
  if (param_11 != (char *)0x0) {
    local_10 = Hash((char *)unaff_EDI,(uint)unaff_ESI);
  }
  iVar4 = 0;
  if (0.0 < param_2) {
    param_4 = (int)(param_2 * param_2);
  }
  else {
    param_4 = 0x7f7fffff;
  }
  param_10 = 0;
  iVar6 = *(int *)&this->m_ObjectHelper->HandleList;
  if (0 < (*(int *)&(this->m_ObjectHelper->HandleList).field_0x4 - iVar6) / 0x5c) {
    iVar7 = 0;
    do {
      if ((param_9 == 0) || (param_9 != *(int *)(iVar7 + iVar6))) {
        iVar4 = param_6;
        if (-1 < param_3) {
          if (param_5) {
            iVar3 = *(int *)(iVar7 + 0x20 + iVar6);
          }
          else {
            iVar3 = *(int *)(iVar7 + 0x1c + iVar6);
          }
          bVar1 = TeamFilterCheck(iVar3,(int)unaff_EDI,(int)unaff_ESI);
          if (!bVar1) goto LAB_4fc1145e;
        }
        if (((0 < *(int *)(iVar7 + 0x54 + iVar6)) &&
            ((((uVar5 & 1) != 0 && ((*(uint *)(iVar7 + 0x10 + iVar6) & uVar2) != 0)) ||
             (((uVar5 & 2) != 0 &&
              ((param_11 != (char *)0x0 && (*(uint *)(iVar7 + 8 + iVar6) == local_10)))))))) &&
           (fVar8 = GetDistance3DSquared(unaff_EDI,unaff_ESI), fVar8 < (float)param_4)) {
          param_6 = *(int *)(iVar7 + iVar6);
          iVar4 = param_6;
          param_4 = (int)fVar8;
        }
      }
LAB_4fc1145e:
      iVar7 = iVar7 + 0x5c;
      param_10 = param_10 + 1;
      iVar6 = *(int *)&this->m_ObjectHelper->HandleList;
    } while (param_10 < (*(int *)&(this->m_ObjectHelper->HandleList).field_0x4 - iVar6) / 0x5c);
  }
  return iVar4;
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
  vector<BZ1Helper::BuildAtClass,std::allocator<BZ1Helper::BuildAtClass>_> *this_00;
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
    this_00 = (vector<BZ1Helper::BuildAtClass,std::allocator<BZ1Helper::BuildAtClass>_> *)
              (this[1].teamInfo[0].PilotWeapon[2] + 0x2b);
    for (piVar3 = *(int **)this_00; piVar3 != *(int **)(this[1].teamInfo[0].PilotWeapon[2] + 0x2f);
        piVar3 = piVar3 + 7) {
      if (*piVar3 == param_1) {
        return;
      }
    }
    std::vector<BZ1Helper::BuildAtClass,std::allocator<BZ1Helper::BuildAtClass>_>::
    _Resize<<lambda_dee307eb94beae9268b6d89c62f4c357>_>
              (this_00,(*(int *)(this[1].teamInfo[0].PilotWeapon[2] + 0x2f) - *(int *)this_00) /
                       0x1c + 1,(<lambda_dee307eb94beae9268b6d89c62f4c357>)this_00);
    iVar1 = *(int *)this_00;
    local_4c = ((*(int *)(this[1].teamInfo[0].PilotWeapon[2] + 0x2f) - iVar1) / 0x1c) * 0x1c;
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
  char *pcVar1;
  bool bVar2;
  int iVar3;
  char *pcVar4;
  char **extraout_ECX;
  char *unaff_ESI;
  int *unaff_EDI;
  int local_c8;
  byte local_c4 [64];
  char local_84 [64];
  char local_44 [64];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)&local_c8;
  if (param_1 != (char *)0x0) {
    memset(local_84,0,0x40);
    memset(local_c4,0,0x40);
    pcVar1 = param_1;
    do {
      pcVar4 = pcVar1;
      pcVar1 = pcVar4 + 1;
    } while (*pcVar4 != '\0');
    iVar3 = _stricmp(pcVar4 + -4,".odf");
    if (iVar3 != 0) {
      param_1 = ".odf";
    }
    CombineStrings(param_1,(char *)0x40,(char *)unaff_EDI,(uint)unaff_ESI);
    bVar2 = OpenODF2((char *)unaff_EDI);
    if (bVar2) {
      memset(local_44,0,0x40);
      iVar3 = GetODFString(local_84,"GameObjectClass","classlabel",0x40,local_44,(char *)0x0);
      if (iVar3 != 0) {
        CombineStrings(".odf",(char *)0x40,(char *)unaff_EDI,(uint)unaff_ESI);
        bVar2 = OpenODF2((char *)unaff_EDI);
        local_c4[0] = local_c4[0] & -bVar2;
      }
      if (!param_3) {
        local_c8 = 0;
        GetODFInt("GameObjectClass","scrapCost",(char *)&local_c8,(char *)0x0,unaff_EDI,
                  (int)unaff_ESI);
        iVar3 = (*misnImport.GetScrap)(param_2);
        if (iVar3 - local_c8 < 0) {
          return false;
        }
      }
      iVar3 = CheckBuildRequirements_PowerCost((int)local_c4,(char *)unaff_EDI,unaff_ESI);
      if (-1 < iVar3) {
        local_c8 = 0;
        GetODFInt("GameObjectClass","pilotCost",(char *)&local_c8,(char *)0x0,unaff_EDI,
                  (int)unaff_ESI);
        if ((local_c8 <= *(int *)((int)this->teamInfo + param_2 * 0xa14 + 0x94)) &&
           (iVar3 = CheckBuildRequirements_RequireCount
                              (this,extraout_ECX,param_2,local_84,(char *)local_c4), iVar3 < 1)) {
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
  int iVar3;
  int *unaff_EBP;
  int unaff_ESI;
  int iVar4;
  int *unaff_EDI;
  char (*pacVar5) [64];
  char *pcVar6;
  char *pcVar7;
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
  iVar4 = 0;
  local_114 = 0;
  local_10c = param_3;
  local_108 = param_4;
  local_110 = this;
  iVar1 = GetODFInt("GameObjectClass","requireCount",(char *)&local_114,(char *)0x0,unaff_EDI,
                    unaff_ESI);
  if ((iVar1 != 0) && (iVar1 = 0, 0 < local_114)) {
    do {
      memset(local_c4,0,0x40);
      memset(local_84,0,0x40);
      iVar1 = iVar1 + 1;
      pacVar5 = &local_84;
      pcVar6 = "requireName%d";
      sprintf_s<64>(pacVar5,"requireName%d");
      iVar2 = GetODFString("GameObjectClass",local_84,(char *)0x40,local_c4,0,*pacVar5,pcVar6);
      if (iVar2 != 0) {
        local_118 = 0;
        iVar2 = *(int *)&local_110->m_ObjectHelper->HandleList;
        if (0 < (*(int *)&(local_110->m_ObjectHelper->HandleList).field_0x4 - iVar2) / 0x5c) {
          local_11c = 0;
          do {
            iVar3 = local_11c;
            if (*(int *)(local_11c + 0x1c + iVar2) == param_2) {
              pcVar6 = GetODFName((int)unaff_EBP);
              if ((pcVar6 != (char *)0x0) && (iVar2 = _stricmp(local_c4,pcVar6), iVar2 == 0))
              goto LAB_4fc11a14;
              pcVar6 = local_104;
              pcVar7 = (char *)0x0;
              memset(pcVar6,0,0x40);
              GetODFString(0x4fc582f8,(char *)0x40,local_104,0,pcVar6,pcVar7);
              if (local_104[0] == '\0') {
                local_120 = 0;
                GetODFInt(0x4fc5c818,(char *)&local_120,(char *)0x0,unaff_EBP,(int)unaff_EDI);
                iVar2 = 0;
                iVar3 = local_11c;
                if (0 < local_120) {
                  do {
                    memset(local_44,0,0x40);
                    iVar2 = iVar2 + 1;
                    pacVar5 = &local_44;
                    pcVar6 = "provideName%d";
                    sprintf_s<64>(pacVar5,"provideName%d");
                    GetODFString((int)local_44,(char *)0x40,local_104,0,*pacVar5,pcVar6);
                    iVar3 = _stricmp(local_c4,local_104);
                    if (iVar3 == 0) goto LAB_4fc11a14;
                    iVar3 = local_11c;
                  } while (iVar2 < local_120);
                }
              }
              else {
                iVar2 = _stricmp(local_c4,local_104);
                if (iVar2 == 0) goto LAB_4fc11a14;
              }
            }
            local_11c = iVar3 + 0x5c;
            local_118 = local_118 + 1;
            iVar2 = *(int *)&local_110->m_ObjectHelper->HandleList;
          } while (local_118 <
                   (*(int *)&(local_110->m_ObjectHelper->HandleList).field_0x4 - iVar2) / 0x5c);
        }
      }
      iVar4 = iVar4 + 1;
LAB_4fc11a14:
    } while (iVar1 < local_114);
  }
  return iVar4;
}


// ---------------------------------------------------------------------
// BZ1Helper::ReplaceObject  @ 4fc11a43  lines 5071-5248


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall
BZ1Helper::ReplaceObject
          (BZ1Helper *this,int param_1,char *param_2,int param_3,float param_4,int param_5,
          bool param_6,int param_7,int param_8,bool param_9,int param_10,int param_11,int param_12,
          Vector param_13)

{
  int *piVar1;
  bool bVar2;
  int iVar3;
  char *pcVar4;
  Vector *pVVar5;
  long extraout_EAX;
  int extraout_EAX_00;
  int extraout_ECX;
  char *unaff_ESI;
  int iVar6;
  Matrix *pMVar7;
  float *unaff_EDI;
  Matrix *pMVar8;
  float fVar9;
  undefined1 auStack_550 [7];
  char cStack_549;
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
  bVar2 = IsAround(param_1);
  if (!bVar2) {
    return 0;
  }
  memset(&local_4d8,0,0x4d0);
  if (param_2 == (char *)0x0) {
    GetODFName((int)unaff_EDI,unaff_ESI);
  }
  else {
    CombineStrings(param_2,(char *)0x40,(char *)unaff_EDI,(uint)unaff_ESI);
    GetWorldVariantODF((char *)unaff_EDI);
  }
  local_4d8 = (*misnImport.GetTug)(param_1);
  iStack_4d4 = GetTarget(param_1);
  iStack_4d0 = GetCurrentWho(param_1);
  iVar6 = 0;
  do {
    iVar3 = GetTap(param_1,iVar6);
    aiStack_4cc[iVar6] = iVar3;
    iVar6 = iVar6 + 1;
  } while (iVar6 < 8);
  pcVar4 = GetLabel(param_1);
  CombineStrings(pcVar4,(char *)0x100,(char *)unaff_EDI,(uint)unaff_ESI);
  pcVar4 = GetObjectiveName(param_1);
  CombineStrings(pcVar4,(char *)0x100,(char *)unaff_EDI,(uint)unaff_ESI);
  pcVar4 = GetPilotConfig((int)unaff_EDI);
  if (pcVar4 != (char *)0x0) {
    CombineStrings(pcVar4,(char *)0x40,(char *)unaff_EDI,(uint)unaff_ESI);
  }
  if (param_3 < 0) {
    param_3 = GetTeamNum(param_1);
  }
  iStack_22c = param_3;
  iStack_228 = GetPerceivedTeam(param_1);
  fStack_214 = GetHealth(param_1);
  fStack_210 = GetAmmo(param_1);
  iVar6 = 0;
  pcVar4 = acStack_20c;
  do {
    fVar9 = GetCurLocalAmmo(param_1,iVar6);
    afStack_cc[iVar6] = fVar9;
    GetObjInfo(param_1,iVar6 + Get_Weapon0Config,pcVar4);
    pcVar4 = pcVar4 + 0x40;
    iVar6 = iVar6 + 1;
  } while (iVar6 < 5);
  lStack_b8 = GetWeaponMask(param_1);
  iVar6 = GetScavengerMaxScrap(param_1);
  fStack_20 = __real_bf800000;
  if (0 < iVar6) {
    iVar3 = GetScavengerCurScrap(param_1);
    fStack_20 = (float)(iVar3 / iVar6);
  }
  GetPosition(param_1,&MStack_518);
  pMVar7 = &MStack_518;
  pMVar8 = &MStack_ac;
  for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
    (pMVar8->right).x = (pMVar7->right).x;
    pMVar7 = (Matrix *)&(pMVar7->right).y;
    pMVar8 = (Matrix *)&(pMVar8->right).y;
  }
  pVVar5 = GetVelocity(&VStack_53c,param_1);
  VStack_6c.x = pVVar5->x;
  VStack_6c.y = pVVar5->y;
  VStack_6c.z = pVVar5->z;
  pVVar5 = GetOmega(&VStack_530,param_1);
  VStack_60.x = pVVar5->x;
  VStack_60.y = pVVar5->y;
  VStack_60.z = pVVar5->z;
  cStack_54 = IsDeployed(param_1);
  fStack_4c = GetRemainingLifespan(param_1);
  iStack_48 = GetIndependence(param_1);
  iStack_44 = GetSkill(param_1);
  if (param_7 < 0) {
    iStack_40 = GetGroup(param_1);
  }
  else {
    iStack_40 = param_7;
  }
  if (param_8 < 0) {
    bVar2 = GetCanSnipe(param_1);
    param_8 = (int)bVar2;
  }
  bStack_3c = param_8 != 0;
  AStack_38 = GetCurrentCommand(param_1);
  if (((AStack_38 == CMD_GO) || (AStack_38 == CMD_DEPLOY)) || (AStack_38 - CMD_GET_IN < 2)) {
    pVVar5 = GetCurrentCommandWhere(&VStack_524,param_1);
    VStack_34.x = pVVar5->x;
    VStack_34.y = pVVar5->y;
    VStack_34.z = pVVar5->z;
  }
  cStack_28 = IsPlayer(param_1);
  fStack_24 = GetEjectRatio(param_1);
  GetODFName((int)unaff_EDI);
  iStack_18 = GetScrapValue((char *)unaff_EDI);
  iStack_14 = GetPilotCost((char *)unaff_EDI);
  iStack_10 = GetTapCount(extraout_ECX,SUB41(unaff_EDI,0),SUB41(unaff_ESI,0));
  if (param_5 < 0) {
    bVar2 = IsEmpty((int)unaff_EDI);
    param_5 = (int)bVar2;
  }
  cStack_1c = param_5 != 0;
  if (param_4 != ___real_00000000) {
    MStack_ac.posit.y = MStack_ac.posit.y + param_4;
  }
  bVar2 = DoesODFExist(local_4ac);
  if (!bVar2) {
    FormatLogMessage("ERROR: ReplaceODF \'%s\' doesn\'t exist! Fix DLLs!");
    return param_1;
  }
  if ((cStack_1c == '\0') && (1 < m_TurnCounter)) {
    piVar1 = (int *)((int)local_548->teamInfo + iStack_22c * 0xa14 + 0x94);
    *piVar1 = *piVar1 + iStack_14;
  }
  cStack_549 = '\x01';
  iVar6 = GetODFBool(0x4fc5c838,&cStack_549,(char *)0x1,(bool *)unaff_EDI,SUB41(unaff_ESI,0));
  if (iVar6 == 0) {
    GetODFBool(0x4fc5c838,&cStack_549,(char *)0x1,(bool *)unaff_EDI,SUB41(unaff_ESI,0));
  }
  RemoveObject(param_1);
  iVar6 = BuildObject(local_4ac,iStack_22c,&MStack_ac);
  if (local_4d8 != 0) {
    Pickup(local_4d8,iVar6,1);
  }
  if (iStack_4d4 != 0) {
    SetTarget(iVar6,iStack_4d4);
  }
  if ((cStack_549 == '\0') && (iVar3 = 0, 0 < iStack_10)) {
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
      if (__real_3f800000 < (float)local_548) {
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
  SetAmmo((int)fStack_210,(float)unaff_EDI);
  if (param_6) {
    ReplaceWeapons((int)afStack_cc,&local_4ac,unaff_EDI,unaff_ESI);
  }
  SetWeaponMask(iVar6,lStack_b8);
  fStack_544 = fStack_20;
  fStack_540 = (float)GetScavengerMaxScrap(iVar6);
  if (0 < (int)fStack_540) {
    if (0.0 <= fStack_544) {
      if (fStack_544 <= __real_3f800000) {
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
  if (___real_00000000 <= fStack_4c) {
    SetLifespan(iVar6,fStack_4c);
  }
  if (-1 < iStack_48) {
    SetIndependence(iVar6,iStack_48);
  }
  SetSkill(iVar6,iStack_44);
  if (param_7 < -1) {
    if (param_7 < 0) goto LAB_4fc12112;
  }
  else if (param_7 < 0) {
    SetBestGroup(iVar6);
    goto LAB_4fc12112;
  }
  if (param_7 < 10) {
    SetGroup(iVar6,iStack_40);
  }
LAB_4fc12112:
  SetCanSnipe(iVar6,(uint)bStack_3c);
  SetEjectRatio(iVar6,fStack_24);
  if (cStack_28 == '\0') {
    if (cStack_1c == '\0') {
      if (param_10 < 0) {
        if (!param_9) {
          return iVar6;
        }
        pVVar5 = &VStack_34;
        param_10 = AStack_38;
        param_12 = iStack_4d0;
      }
      else {
        pVVar5 = &param_13;
      }
      SetCommand(iVar6,param_10,param_11,param_12,pVVar5,0);
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

