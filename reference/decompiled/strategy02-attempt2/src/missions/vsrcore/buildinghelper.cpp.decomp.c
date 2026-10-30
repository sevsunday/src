// Reconstructed by Ghidra from Strategy02.dll + Strategy02.pdb
// Original source file: /e:/github/vsr_dll_source/missions/vsrcore/buildinghelper.cpp
// Functions are ordered by original source line. This is decompiler
// output, not the author's source: names/types come from the PDB,
// local variable names and control flow are reconstructed.

// ---------------------------------------------------------------------
// `dynamic_initializer_for_'TempBuildingBuffer''  @ 4fc01772  lines 10-10

void __cdecl _dynamic_initializer_for__TempBuildingBuffer__(void)

{
  atexit(_dynamic_atexit_destructor_for__TempBuildingBuffer__);
  return;
}


// ---------------------------------------------------------------------
// BuildingHelper::PostLoad  @ 4fc1db31  lines 45-70

bool __thiscall BuildingHelper::PostLoad(BuildingHelper *this,bool param_1)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  
  piVar5 = *(int **)&this->BuildingList;
  piVar2 = *(int **)&(this->BuildingList).field_0x4;
  if (piVar5 != piVar2) {
    do {
      ConvertHandles(piVar5,1);
      iVar4 = 8;
      piVar2 = piVar5;
      do {
        piVar2 = piVar2 + 1;
        ConvertHandles(piVar2,1);
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
      piVar2 = *(int **)&(this->BuildingList).field_0x4;
      piVar5 = piVar5 + 0x116;
    } while (piVar5 != piVar2);
    piVar5 = *(int **)&this->BuildingList;
  }
  iVar4 = ((int)piVar2 - (int)piVar5) / 0x458;
  iVar3 = (int)(TempBuildingBuffer._4_4_ - TempBuildingBuffer._0_4_) / 0x458;
  if (iVar3 == iVar4) {
    iVar3 = 0;
    if (0 < iVar4) {
      iVar4 = 0;
      do {
        bVar1 = ::operator==((BuildingClass *)(TempBuildingBuffer._0_4_ + iVar4),
                             (BuildingClass *)((int)piVar5 + iVar4));
        if (!bVar1) {
          FormatLogMessage("BuildingList Index Mismatch: %d",iVar3);
          return true;
        }
        piVar5 = *(int **)&this->BuildingList;
        iVar3 = iVar3 + 1;
        iVar4 = iVar4 + 0x458;
      } while (iVar3 < (*(int *)&(this->BuildingList).field_0x4 - (int)piVar5) / 0x458);
    }
  }
  else {
    FormatLogMessage("BuildingList Size Mismatch! Old: %d New: %d",iVar3,iVar4);
  }
  return true;
}


// ---------------------------------------------------------------------
// BuildingHelper::AddBuildingObject  @ 4fc1dbee  lines 88-321

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall
BuildingHelper::AddBuildingObject
          (BuildingHelper *this,int param_1,char *param_2,char *param_3,int param_4,int param_5,
          int param_6,int param_7,bool param_8,int param_9,bool param_10)

{
  bool bVar1;
  int iVar2;
  long lVar3;
  int iVar4;
  Matrix *pMVar5;
  Matrix *__return_storage_ptr__;
  uint uVar6;
  uint unaff_ESI;
  int *piVar7;
  int *piVar8;
  int fmtarg1;
  char *unaff_EDI;
  vector<BuildingHelper::BuildingClass,std::allocator<BuildingHelper::BuildingClass>_> *pvVar9;
  Matrix *pMVar10;
  int *local_274;
  uint local_270;
  bool local_26c;
  char local_26b;
  bool local_26a;
  bool local_269;
  char *local_268;
  int local_264;
  vector<BuildingHelper::BuildingClass,std::allocator<BuildingHelper::BuildingClass>_> *local_260;
  code *local_25c;
  Vector local_258;
  Matrix local_24c [2];
  Matrix local_1cc [2];
  char local_14c [64];
  char local_10c [64];
  char local_cc [64];
  char local_8c [64];
  char local_4c [68];
  uint local_8;
  
  local_8 = __security_cookie ^ (uint)&local_274;
  piVar8 = *(int **)&this->BuildingList;
  local_274 = (int *)param_3;
  iVar2 = -1;
  local_264 = param_1;
  local_268 = param_2;
  local_25c = GetTap_exref;
  piVar7 = piVar8;
  local_260 = &this->BuildingList;
  if (piVar8 != *(int **)&(this->BuildingList).field_0x4) {
LAB_4fc1dc41:
    if (*piVar7 != param_1) goto code_r0x4fc1dc49;
    uVar6 = 0;
    iVar2 = 0;
    do {
      iVar4 = (*local_25c)(*piVar7,iVar2);
      memset(local_14c,0,0x40);
      GetObjInfo(iVar4,Get_ODF,local_14c);
      iVar4 = local_264;
      param_2 = local_268;
      if (local_14c[0] != '\0') {
        uVar6 = uVar6 + 1;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < 8);
    if (piVar7[0x9c] != uVar6) {
      piVar7[0x9c] = uVar6;
    }
    local_270 = uVar6;
    if (piVar7[0x90] == -0x20925446) {
      if (piVar7 == (int *)0xfffffd54) {
        uVar6 = 0;
      }
      else {
        uVar6 = Hash(unaff_EDI,unaff_ESI);
      }
      if (param_5 == uVar6) {
        ReplaceWeapons(iVar4,(char (*) [64])(piVar7 + 0xbb),(float *)0x0,(char *)0x0);
      }
    }
    piVar8 = *(int **)local_260;
    iVar2 = ((int)piVar7 - (int)piVar8) / 0x458;
  }
LAB_4fc1dc5b:
  if (iVar2 < 0) {
    std::vector<BuildingHelper::BuildingClass,std::allocator<BuildingHelper::BuildingClass>_>::
    _Resize<<lambda_ec97c231cece026f40cdadd6cbe85fc1>_>
              (local_260,(*(int *)&local_260->field_0x4 - (int)piVar8) / 0x458 + 1,
               (<lambda_ec97c231cece026f40cdadd6cbe85fc1>)local_260);
    piVar8 = *(int **)local_260;
    iVar2 = (*(int *)&local_260->field_0x4 - (int)piVar8) / 0x458 + -1;
  }
  piVar8 = piVar8 + iVar2 * 0x116;
  memset(piVar8,0,0x458);
  piVar7 = local_274;
  GetODFInt(param_2,(char *)local_274,"GameObjectClass","RequirePowerMask",piVar8 + 0x92,0);
  if (param_6 == -0x20925446) {
    GetODFBool(param_2,(char *)piVar7,"TurretCraftClass","PoweredByTaps",
               (bool *)((int)piVar8 + 0x23d),true);
    GetODFBool(param_2,(char *)piVar7,"TurretCraftClass","autoBuildTaps",
               (bool *)((int)piVar8 + 0x23e),true);
    GetODFBool(param_2,(char *)piVar7,"TurretCraftClass","canDemolish",(bool *)(piVar8 + 0x8f),true)
    ;
    piVar8[0xa6] = param_9;
  }
  else {
    GetODFBool(param_2,(char *)piVar7,"PoweredBuildingClass","PoweredByTaps",
               (bool *)((int)piVar8 + 0x23d),true);
    GetODFBool(param_2,(char *)piVar7,"PoweredBuildingClass","autoBuildTaps",
               (bool *)((int)piVar8 + 0x23e),true);
    GetODFBool(param_2,(char *)piVar7,"BuildingClass","canDemolish",(bool *)(piVar8 + 0x8f),true);
  }
  GetODFInt(param_2,(char *)piVar7,"GameObjectClass","GameObjectClassPowerMask",piVar8 + 0x9e,0);
  GetODFInt(param_2,(char *)piVar7,"GameObjectClass","GameObjectClassPowerMatch",piVar8 + 0x9f,0);
  GetODFInt(param_2,(char *)piVar7,"GameObjectClass","GameObjectClassPowerProvides",piVar8 + 0xa0,0)
  ;
  local_274 = (int *)0x0;
  GetODFFloat(param_2,(char *)piVar7,"GameObjectClass","CollisionRadius",(float *)(piVar8 + 0xaa),
              0.0);
  GetODFBool(param_2,(char *)piVar7,"GameObjectClass","CanCollide",(bool *)((int)piVar8 + 0x237),
             false);
  GetODFBool(param_2,(char *)piVar7,"GameObjectClass","ownsTerrain",(bool *)((int)piVar8 + 0x23f),
             true);
  local_26c = false;
  GetODFBool(param_2,(char *)piVar7,"GameObjectClass","CanAcceptPowerups",&local_26c,false);
  iVar2 = (local_26c == false) - 1;
  piVar8[0xa1] = iVar2;
  GetODFInt(param_2,(char *)piVar7,"GameObjectClass","AcceptPowerupMask",piVar8 + 0xa1,iVar2);
  GetODFInt(param_2,(char *)piVar7,"BuildingClass","SizeRatioX",piVar8 + 0xa7,1);
  GetODFInt(param_2,(char *)piVar7,"BuildingClass","SizeRatioZ",piVar8 + 0xa8,1);
  local_26b = '\0';
  GetODFChar(param_2,(char *)piVar7,"GameObjectClass","buildSupport",&local_26b,'A');
  iVar2 = toupper((int)local_26b);
  piVar8[0xa9] = iVar2;
  GetODFString(param_2,(char *)piVar7,"GameObjectClass","upgradeName",0x40,(char *)(piVar8 + 0xab),
               (char *)0x0);
  piVar8[0xa2] = param_4;
  if ((param_7 == -0x221bc770) || (local_270 = local_270 & 0xffffff00, param_6 == -0x4e710e3d)) {
    local_270 = CONCAT31(local_270._1_3_,1);
  }
  GetODFBool(param_2,(char *)piVar7,"GameObjectClass","APCRefillPoint",(bool *)((int)piVar8 + 0x239)
             ,SUB41(local_270,0));
  iVar2 = local_264;
  if ((((param_7 == -0x221bc770) && (bVar1 = IsBuilding(local_264), bVar1)) ||
      (param_6 == -0x7f06008f)) || (local_270 = local_270 & 0xffffff00, param_6 == 0x490dd218)) {
    local_270 = CONCAT31(local_270._1_3_,1);
  }
  GetODFBool(param_2,(char *)piVar7,"GameObjectClass","RecyclePoint",(bool *)((int)piVar8 + 0x23a),
             SUB41(local_270,0));
  if (piVar8[0x90] == -0x25234de5) {
    GetODFFloat(param_2,(char *)piVar7,"SupplyDepotClass","healthRate",(float *)(piVar8 + 0x111),
                (float)local_274);
    GetODFFloat(param_2,(char *)piVar7,"SupplyDepotClass","ammoRate",(float *)(piVar8 + 0x112),
                (float)local_274);
    GetODFFloat(param_2,(char *)piVar7,"SupplyDepotClass","localAmmoRate",(float *)(piVar8 + 0x113),
                (float)local_274);
    GetODFFloat(param_2,(char *)piVar7,"SupplyDepotClass","supplyRate",(float *)(piVar8 + 0x114),
                (float)local_274);
    GetODFBool(param_2,(char *)piVar7,"SupplyDepotClass","serviceCraft",(bool *)(piVar8 + 0x115),
               true);
  }
  lVar3 = GetMaxHealth(iVar2);
  piVar8[0xa4] = lVar3;
  lVar3 = GetMaxAmmo(iVar2);
  piVar8[0xa5] = lVar3;
  *(bool *)(piVar8 + 0x8e) = param_8;
  local_26a = true;
  GetODFBool(param_2,(char *)piVar7,"GameObjectClass","IsAnimated",&local_26a,true);
  if (local_26a != false) {
    memset(local_10c,0,0x40);
    local_268 = (char *)0x0;
    GetODFInt(param_2,(char *)piVar7,"GameObjectClass","animCount",(int *)&local_268,0);
    local_274 = (int *)0x1;
    if (1 < (int)(local_268 + 1)) {
      do {
        memset(local_14c,0,0x40);
        sprintf_s<64>(&local_14c,"animName%d",(int)local_274);
        iVar4 = GetODFString(param_2,(char *)piVar7,"GameObjectClass",local_14c,0x40,local_10c,
                             (char *)0x0);
        if ((iVar4 != 0) && (iVar4 = _stricmp(local_10c,"BZCloop"), iVar4 == 0)) {
          *(undefined1 *)((int)piVar8 + 0x235) = 1;
          break;
        }
        local_274 = (int *)((int)local_274 + 1);
      } while ((int)local_274 < (int)(local_268 + 1));
    }
  }
  GetPosition(iVar2,local_24c);
  iVar4 = 0;
  local_270 = 0;
  local_260 = (vector<BuildingHelper::BuildingClass,std::allocator<BuildingHelper::BuildingClass>_>
               *)(piVar8 + 0xd);
  local_274 = piVar8 + 1;
  do {
    pMVar5 = (Matrix *)(*local_25c)(iVar2,iVar4);
    if (pMVar5 != (Matrix *)0x0) {
      memset(local_10c,0,0x40);
      memset(local_cc,0,0x40);
      memset(local_14c,0,0x40);
      GetAndOpenODFNames((int)pMVar5,local_cc,local_14c,local_10c);
      if (local_10c[0] != '\0') {
        local_270 = local_270 + 1;
        *local_274 = (int)pMVar5;
        pMVar10 = local_1cc;
        GetPosition((int)pMVar5,pMVar10);
        Matrix_Inverse(pMVar5,pMVar10);
        pMVar5 = Matrix_Multiply(__return_storage_ptr__,pMVar5,pMVar10);
        pvVar9 = local_260;
        for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
          *(float *)pvVar9 = (pMVar5->right).x;
          pMVar5 = (Matrix *)&(pMVar5->right).y;
          pvVar9 = (vector<BuildingHelper::BuildingClass,std::allocator<BuildingHelper::BuildingClass>_>
                    *)((int)pvVar9 + 4);
        }
        local_269 = true;
        GetODFBool(local_cc,local_14c,"GameObjectClass","IsAnimated",&local_269,true);
        iVar2 = local_264;
        if (local_269 != false) {
          memset(local_4c,0,0x40);
          local_268 = (char *)0x0;
          GetODFInt(local_cc,local_14c,"GameObjectClass","animCount",(int *)&local_268,0);
          fmtarg1 = 1;
          iVar2 = local_264;
          if (1 < (int)(local_268 + 1)) {
            do {
              memset(local_8c,0,0x40);
              sprintf_s<64>(&local_8c,"animName%d",fmtarg1);
              iVar2 = GetODFString(local_cc,local_14c,"GameObjectClass",local_8c,0x40,local_4c,
                                   (char *)0x0);
              if ((iVar2 != 0) && (iVar2 = _stricmp(local_4c,"BZCloop"), iVar2 == 0)) {
                *(undefined1 *)((int)piVar8 + iVar4 + 0x24) = 1;
                iVar2 = local_264;
                break;
              }
              fmtarg1 = fmtarg1 + 1;
              iVar2 = local_264;
            } while (fmtarg1 < (int)(local_268 + 1));
          }
        }
      }
    }
    local_274 = local_274 + 1;
    iVar4 = iVar4 + 1;
    local_260 = (vector<BuildingHelper::BuildingClass,std::allocator<BuildingHelper::BuildingClass>_>
                 *)((int)local_260 + 0x40);
    if (7 < iVar4) {
      piVar8[0x9d] = -1;
      piVar8[0x9c] = local_270;
      piVar8[0x90] = param_6;
      piVar8[0x91] = param_5;
      *piVar8 = iVar2;
      GetPosition(iVar2,&local_258);
      piVar8[0x10b] = (int)local_258.x;
      piVar8[0x10c] = (int)local_258.y;
      piVar8[0x10d] = (int)local_258.z;
      piVar8[0x10e] = (int)local_24c[0].front.x;
      piVar8[0x10f] = (int)local_24c[0].front.y;
      piVar8[0x110] = (int)local_24c[0].front.z;
      return;
    }
  } while( true );
code_r0x4fc1dc49:
  piVar7 = piVar7 + 0x116;
  if (piVar7 == *(int **)&(this->BuildingList).field_0x4) goto LAB_4fc1dc5b;
  goto LAB_4fc1dc41;
}


// ---------------------------------------------------------------------
// BuildingHelper::Execute  @ 4fc1e4a1  lines 324-765

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall BuildingHelper::Execute(BuildingHelper *this,BZ1Helper *bz1Helper)

{
  UtilityShipHelper *this_00;
  BZ1Helper *pBVar1;
  code *pcVar2;
  bool bVar3;
  char cVar4;
  bool bVar5;
  uint *puVar6;
  uint uVar7;
  undefined4 uVar8;
  Vector *pVVar9;
  Matrix *pMVar10;
  char *pcVar11;
  int extraout_EAX;
  int iVar12;
  int iVar13;
  undefined4 extraout_ECX;
  Matrix *__return_storage_ptr__;
  AlignTerrainReplaceClass *entry;
  PowerHelper *pPVar14;
  code *pcVar15;
  uint *puVar16;
  AlignTerrainReplaceClass *entry_00;
  Vector *pVVar17;
  Matrix *unaff_ESI;
  AlignTerrainReplaceClass *pAVar18;
  float *pfVar19;
  int *piVar20;
  uint *puVar21;
  Matrix *unaff_EDI;
  size_t sVar22;
  float *pfVar23;
  code *pcVar24;
  int *piVar25;
  float fVar26;
  float fVar27;
  double dVar28;
  double fmtarg8;
  Matrix *__return_storage_ptr___00;
  double fmtarg9;
  char *pcVar29;
  uint uVar30;
  undefined1 auStack_4a0 [7];
  bool local_499;
  uint *local_498;
  Vector *local_494;
  Vector *local_490;
  char local_489;
  float local_488;
  code *local_484;
  code *local_480;
  AlignTerrainReplaceClass *local_47c;
  BZ1Helper *local_478;
  BuildingHelper *local_474;
  code *local_470;
  uint *local_46c;
  double local_468;
  code *local_45c;
  code *local_458;
  Matrix *local_454;
  double local_450;
  code *local_448;
  code *local_444;
  code *local_440;
  code *local_43c;
  code *local_438;
  code *local_434;
  code *local_430;
  code *local_42c;
  code *local_428;
  code *local_424;
  code *local_420;
  float local_41c;
  int local_418;
  code *local_414;
  code *local_410;
  code *local_40c;
  code *local_408;
  code *local_404;
  code *local_400;
  code *local_3fc;
  float local_3f8;
  float local_3f4;
  code *local_3f0;
  AlignTerrainReplaceClass *local_3ec;
  AlignTerrainReplaceClass *local_3e8;
  uint *local_3e4;
  float local_3e0 [4];
  uint local_3d0;
  uint local_3cc;
  uint local_3c8;
  Vector local_3c4;
  Matrix local_3b8;
  undefined1 local_368 [48];
  Vector local_338 [12];
  Matrix local_2a8 [2];
  int local_228 [4];
  int local_218;
  char local_214 [64];
  undefined1 local_1d4 [128];
  int local_154;
  byte local_150;
  float local_14c;
  float local_148;
  float local_144;
  float local_12c;
  undefined1 local_120 [4];
  undefined4 local_11c;
  undefined1 local_10c;
  char local_108 [64];
  char local_c8 [64];
  char local_88 [64];
  char local_48 [68];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)auStack_4a0;
  local_499 = BZ1Helper::Logging;
  pAVar18 = *(AlignTerrainReplaceClass **)&(this->BuildingList).field_0x4;
  entry = *(AlignTerrainReplaceClass **)&this->BuildingList;
  local_478 = bz1Helper;
  local_47c = pAVar18;
  local_474 = this;
  local_3ec = pAVar18;
  local_3e8 = entry;
  while ((entry != pAVar18 && (bVar3 = BZ1Helper::ShouldRemoveAlignTerrainReplace(entry), !bVar3)))
  {
    entry = (AlignTerrainReplaceClass *)&entry[0x45].NormalVec.y;
  }
  entry_00 = entry;
  if (entry != pAVar18) {
    while (this = local_474, entry_00 = (AlignTerrainReplaceClass *)&entry_00[0x45].NormalVec.y,
          entry_00 != pAVar18) {
      bVar3 = BZ1Helper::ShouldRemoveAlignTerrainReplace(entry_00);
      if (!bVar3) {
        pfVar19 = (float *)entry_00;
        pAVar18 = entry;
        for (iVar12 = 0x116; iVar12 != 0; iVar12 = iVar12 + -1) {
          pAVar18->AlignHandle = (int)*pfVar19;
          pfVar19 = pfVar19 + 1;
          pAVar18 = (AlignTerrainReplaceClass *)&pAVar18->NormalVec;
        }
        entry = (AlignTerrainReplaceClass *)&entry[0x45].NormalVec.y;
        pAVar18 = local_47c;
      }
    }
    if (entry != pAVar18) {
      sVar22 = *(int *)&(local_474->BuildingList).field_0x4 - (int)pAVar18;
      memmove(entry,pAVar18,sVar22);
      puVar6 = (uint *)(sVar22 + (int)entry);
      *(uint **)&(this->BuildingList).field_0x4 = puVar6;
      goto LAB_4fc1e559;
    }
  }
  puVar6 = *(uint **)&(this->BuildingList).field_0x4;
LAB_4fc1e559:
  puVar21 = *(uint **)&this->BuildingList;
  if (puVar21 != puVar6) {
    local_45c = GetPerceivedTeam_exref;
    local_414 = IsTeamAllied_exref;
    local_448 = GetPower_exref;
    local_458 = ResumeAnimation_exref;
    local_444 = IsAround_exref;
    local_440 = SetTeamNum_exref;
    local_43c = SetPerceivedTeam_exref;
    local_438 = SetPosition_exref;
    local_434 = GetObjInfo_exref;
    local_430 = AddPilotByHandle_exref;
    local_42c = SetControls_exref;
    local_428 = RemovePilotAI_exref;
    local_424 = GetCurHealth_exref;
    local_420 = GetCurAmmo_exref;
    local_454 = (Matrix *)0x3c23d70a;
    local_410 = StartAudio3D_exref;
    local_40c = AddHealth_exref;
    local_3f4 = 0.0;
    local_408 = AddAmmo_exref;
    local_404 = AddLocalAmmo_exref;
    local_41c = 0.5;
    local_400 = RemoveObject_exref;
    local_3fc = GetPlayerHandle_exref;
    local_3f8 = 1.0;
    local_47c = (AlignTerrainReplaceClass *)GetTeamNum_exref;
    local_484 = GetAnimationDirection_exref;
    local_480 = PauseAnimation_exref;
    local_3f0 = Service_exref;
    local_470 = GetPosition_exref;
    do {
      pcVar2 = local_470;
      pcVar24 = local_480;
      pcVar15 = local_484;
      local_498 = puVar21;
      local_46c = puVar21;
      uVar7 = (*(code *)local_47c)(*puVar21);
      puVar21[0xa2] = uVar7;
      (*pcVar2)(*puVar21,&local_3b8);
      uVar8 = (*local_45c)(*puVar21);
      local_468 = (double)CONCAT44(local_468._4_4_,uVar8);
      local_490 = (Vector *)0x0;
      uVar7 = 0;
      if (puVar21[0x9c] != 0) {
        local_490 = (Vector *)GetTapCount(puVar21[0x9c],SUB41(unaff_EDI,0),SUB41(unaff_ESI,0));
        uVar7 = puVar21[0x9c];
      }
      if ((*(char *)((int)puVar21 + 0x23e) == '\0') && ((int)uVar7 < (int)local_490)) {
        puVar21[0x9c] = (uint)local_490;
      }
      bVar3 = puVar21[0x9d] != 0;
      if ((int)puVar21[0x9d] < 0) {
        local_489 = '\0';
        cVar4 = '\0';
        if (((puVar21[0x92] & 1) != 0) &&
           (local_488 = 0.0, pcVar15 = local_484,
           0 < (*(int *)&(PowerHelper::m_PowerHelper->PowerList).field_0x4 -
               *(int *)&PowerHelper::m_PowerHelper->PowerList) / 0x28)) {
          iVar12 = 0;
          pPVar14 = PowerHelper::m_PowerHelper;
          do {
            puVar21 = local_498;
            pfVar19 = (float *)(*(int *)&pPVar14->PowerList + iVar12);
            pfVar23 = local_3e0;
            for (iVar13 = 10; iVar13 != 0; iVar13 = iVar13 + -1) {
              *pfVar23 = *pfVar19;
              pfVar19 = pfVar19 + 1;
              pfVar23 = pfVar23 + 1;
            }
            if (((((char)((uint)local_3e0[1] >> 0x10) != '\0') &&
                 (cVar4 = (*local_414)(local_498[0xa2],local_3e0[2]),
                 pPVar14 = PowerHelper::m_PowerHelper, cVar4 != '\0')) &&
                ((puVar21[0x9e] & local_3c8) == puVar21[0x9f])) &&
               ((puVar21[0xa0] & local_3d0) == local_3cc)) {
              local_450 = (double)local_3e0[3];
              fVar26 = GetDistance3DSquared((Vector *)(puVar21 + 0x10b),&local_3c4);
              local_494 = (Vector *)(float)((float10)local_450 * (float10)local_450);
              pPVar14 = PowerHelper::m_PowerHelper;
              if (fVar26 < (float)local_494) {
                pcVar15 = local_484;
                pcVar24 = local_480;
                cVar4 = '\x01';
                break;
              }
            }
            iVar12 = iVar12 + 0x28;
            local_488 = (float)((int)local_488 + 1);
            pcVar15 = local_484;
            pcVar24 = local_480;
            cVar4 = local_489;
          } while ((int)local_488 <
                   (*(int *)&(pPVar14->PowerList).field_0x4 - *(int *)&pPVar14->PowerList) / 0x28);
        }
        uVar7 = puVar21[0x92];
        if ((((uVar7 == 0) || (((uVar7 & 1) != 0 && (cVar4 != '\0')))) ||
            (((uVar7 & 2) != 0 && (iVar12 = (*local_448)(puVar21[0xa2]), -1 < iVar12)))) ||
           (((puVar21[0x92] & 4) != 0 &&
            ((*(char *)((int)puVar21 + 0x23d) == '\0' || (local_490 == (Vector *)puVar21[0x9c]))))))
        {
          bVar3 = true;
        }
        else {
          bVar3 = false;
        }
      }
      *(bool *)(puVar21 + 0x8d) = bVar3;
      if (*(char *)((int)puVar21 + 0x235) != '\0') {
        iVar12 = (*pcVar15)(*puVar21);
        bVar3 = iVar12 != 0;
        *(bool *)((int)puVar21 + 0x236) = bVar3;
        if ((char)puVar21[0x8d] == '\0') {
          if (bVar3) {
            uVar7 = (*pcVar24)(*puVar21);
LAB_4fc1e8a6:
            puVar21[0x93] = uVar7;
          }
        }
        else if (!bVar3) {
          if (puVar21[0x93] == 0) {
            uVar7 = (*pcVar15)(*puVar21);
            goto LAB_4fc1e8a6;
          }
          (*local_458)(*puVar21,puVar21[0x93]);
        }
      }
      iVar12 = 0;
      if (0 < (int)puVar21[0x9c]) {
        pVVar17 = (Vector *)(puVar21 + 0x19);
        puVar6 = puVar21;
        do {
          puVar16 = puVar6 + 1;
          local_490 = pVVar17;
          cVar4 = (*local_444)(*puVar16);
          if (cVar4 != '\0') {
            (*local_470)(*puVar16,local_368);
            local_494 = (Vector *)puVar21[0xa2];
            pVVar9 = (Vector *)(*(code *)local_47c)(*puVar16);
            if (local_494 != pVVar9) {
              (*local_440)(*puVar16,local_494);
            }
            iVar13 = (*local_45c)(*puVar16);
            if (iVar13 != local_468._0_4_) {
              (*local_43c)(*puVar16,local_468._0_4_);
            }
            if (*(char *)((int)puVar21 + iVar12 + 0x24) != '\0') {
              iVar13 = (*local_484)(*puVar16);
              bVar3 = iVar13 != 0;
              *(bool *)((int)puVar21 + iVar12 + 0x2c) = bVar3;
              if ((char)puVar21[0x8d] == '\0') {
                if (bVar3) {
                  uVar7 = (*local_480)(*puVar16);
                  puVar6[0x94] = uVar7;
                  *(undefined1 *)((int)puVar21 + iVar12 + 0x2c) = 0;
                }
              }
              else if (!bVar3) {
                if (puVar6[0x94] == 0) {
                  uVar7 = (*local_484)(*puVar16);
                  puVar6[0x94] = uVar7;
                }
                else {
                  (*local_458)(*puVar16,puVar6[0x94]);
                  *(undefined1 *)((int)puVar21 + iVar12 + 0x2c) = 1;
                }
              }
            }
            pMVar10 = local_454;
            pVVar9 = Vector_TransformInv(local_338,local_454,&unaff_EDI->right);
            bVar3 = close_enough(pVVar17,pVVar9,(float)pMVar10);
            if ((!bVar3) ||
               (bVar3 = close_enough((Vector *)(puVar21 + 0x10e),&local_3b8.front,(float)local_454),
               !bVar3)) {
              local_494 = pVVar17 + -4;
              Matrix_Multiply(&local_3b8,unaff_EDI,unaff_ESI);
              (*local_438)(*puVar16,extraout_ECX);
              if (local_499 != false) {
                memset(local_48,0,0x40);
                memset(local_108,0,0x40);
                GetODFName(*puVar21,local_48);
                GetODFName(*puVar16,local_108);
                FormatLogMessage("Tap Not Matching Host: %08x %s! Current Tap: %08x \'%s\' Old Offset: %f %f %f New Offset: %f %f %f, Old Building Front: %f %f %f New Building Front: %f %f %f"
                                 ,*puVar21,local_48,*puVar16,local_108,
                                 (double)CONCAT44(SUB84((double)pVVar17->y,0),
                                                  (int)((ulonglong)(double)pVVar17->x >> 0x20)),
                                 (double)CONCAT44(SUB84((double)pVVar17->z,0),
                                                  (int)((ulonglong)(double)pVVar17->y >> 0x20)),
                                 (double)CONCAT44(SUB84((double)(local_338[0].x - local_3b8.posit.x)
                                                        ,0),
                                                  (int)((ulonglong)(double)pVVar17->z >> 0x20)),
                                 (double)CONCAT44(SUB84((double)(local_338[0].y - local_3b8.posit.y)
                                                        ,0),
                                                  (int)((ulonglong)
                                                        (double)(local_338[0].x - local_3b8.posit.x)
                                                       >> 0x20)),
                                 (double)CONCAT44(SUB84((double)(local_338[0].z - local_3b8.posit.z)
                                                        ,0),
                                                  (int)((ulonglong)
                                                        (double)(local_338[0].y - local_3b8.posit.y)
                                                       >> 0x20)),
                                 (double)CONCAT44(SUB84((double)(float)puVar21[0x10e],0),
                                                  (int)((ulonglong)
                                                        (double)(local_338[0].z - local_3b8.posit.z)
                                                       >> 0x20)),
                                 (double)CONCAT44(SUB84((double)(float)puVar21[0x10f],0),
                                                  (int)((ulonglong)(double)(float)puVar21[0x10e] >>
                                                       0x20)),
                                 (double)CONCAT44(SUB84((double)(float)puVar21[0x110],0),
                                                  (int)((ulonglong)(double)(float)puVar21[0x10f] >>
                                                       0x20)),
                                 (double)CONCAT44(SUB84((double)local_3b8.front.x,0),
                                                  (int)((ulonglong)(double)(float)puVar21[0x110] >>
                                                       0x20)),
                                 (double)CONCAT44(SUB84((double)local_3b8.front.y,0),
                                                  (int)((ulonglong)(double)local_3b8.front.x >> 0x20
                                                       )),
                                 (double)CONCAT44(SUB84((double)local_3b8.front.z,0),
                                                  (int)((ulonglong)(double)local_3b8.front.y >> 0x20
                                                       )),
                                 (double)CONCAT44(unaff_EDI,
                                                  (int)((ulonglong)(double)local_3b8.front.z >> 0x20
                                                       )));
              }
              pMVar10 = local_2a8;
              __return_storage_ptr___00 = (Matrix *)*puVar16;
              (*local_470)();
              Matrix_Inverse(__return_storage_ptr___00,pMVar10);
              pMVar10 = Matrix_Multiply(__return_storage_ptr__,__return_storage_ptr___00,pMVar10);
              pVVar17 = local_494;
              for (iVar13 = 0x10; iVar13 != 0; iVar13 = iVar13 + -1) {
                pVVar17->x = (pMVar10->right).x;
                pMVar10 = (Matrix *)&(pMVar10->right).y;
                pVVar17 = (Vector *)&pVVar17->y;
              }
              local_498[0x10e] = (uint)local_3b8.front.x;
              local_498[0x10f] = (uint)local_3b8.front.y;
              local_498[0x110] = (uint)local_3b8.front.z;
              puVar21 = local_498;
              pVVar17 = local_490;
            }
          }
          iVar12 = iVar12 + 1;
          pVVar17 = (Vector *)&pVVar17[5].y;
          puVar6 = puVar16;
          local_490 = pVVar17;
        } while (iVar12 < (int)puVar21[0x9c]);
      }
      if (puVar21[0x90] == 0xdf6dabba) {
        if (puVar21[0xa6] != 0) {
          iVar12 = 0;
          puVar6 = puVar21 + 0xbb;
          do {
            (*local_434)(*puVar21,iVar12 + 5,puVar6);
            puVar6 = puVar6 + 0x10;
            iVar12 = iVar12 + 1;
          } while (iVar12 < 5);
        }
        cVar4 = *(char *)((int)puVar21 + 0x23b);
        if (cVar4 != '\0') {
          if ((char)puVar21[0x8d] != '\0') {
            *(undefined1 *)((int)puVar21 + 0x23b) = 0;
            (*local_430)(*puVar21);
            cVar4 = *(char *)((int)puVar21 + 0x23b);
          }
          if (cVar4 != '\0') goto LAB_4fc1ec22;
        }
        if ((char)puVar21[0x8d] == '\0') {
          *(undefined1 *)((int)puVar21 + 0x23b) = 1;
          local_11c = 0;
          local_10c = 0;
          (*local_42c)(*puVar21,local_120,0x102);
          (*local_428)(*puVar21);
        }
      }
LAB_4fc1ec22:
      if ((*(char *)((int)puVar21 + 0x237) == '\0') && (puVar21[0xa1] != 0)) {
        iVar12 = (*local_424)(*puVar21);
        local_418 = iVar12;
        iVar13 = (*local_420)(*puVar21);
        local_450 = (double)CONCAT44(local_450._4_4_,iVar13);
        if ((((puVar21[0xa4] != 0) || (puVar21[0xa5] != 0)) &&
            ((iVar12 < (int)puVar21[0xa4] || (iVar13 < (int)puVar21[0xa5])))) ||
           ((puVar21[0x90] == 0xdf6dabba && (0 < (int)puVar21[0xa6])))) {
          local_490 = (Vector *)0x0;
          local_488 = (float)puVar21[0xaa] * (float)puVar21[0xaa];
          if (0 < (*(int *)&(PowerupHelper::m_PowerupHelper->PowerupList).field_0x4 -
                  *(int *)&PowerupHelper::m_PowerupHelper->PowerupList) / 0x104) {
            local_494 = (Vector *)0x0;
            do {
              pVVar17 = local_494;
              puVar21 = local_498;
              piVar20 = (int *)((int)local_494 +
                               *(int *)&PowerupHelper::m_PowerupHelper->PowerupList);
              piVar25 = local_228;
              for (iVar12 = 0x41; iVar12 != 0; iVar12 = iVar12 + -1) {
                *piVar25 = *piVar20;
                piVar20 = piVar20 + 1;
                piVar25 = piVar25 + 1;
              }
              if (local_154 < 1) {
                local_468 = (double)CONCAT44(local_468._4_4_,ABS(local_12c));
                if (ABS(local_12c) < local_41c) {
                  bVar3 = false;
                  if ((local_498[0x90] == 0xdf6dabba) && (local_218 != 0)) {
                    iVar12 = 0;
                    do {
                      fVar26 = GetCurLocalAmmo(*puVar21,iVar12);
                      local_468 = (double)fVar26;
                      fVar26 = GetMaxLocalAmmo(*puVar21,iVar12);
                      if ((float)local_468 < fVar26) {
                        bVar3 = true;
                        break;
                      }
                      iVar12 = iVar12 + 1;
                      bVar3 = false;
                    } while (iVar12 < 5);
                  }
                  if (((((local_418 < (int)puVar21[0xa4]) && (local_228[2] != 0)) ||
                       ((local_450._0_4_ < (int)puVar21[0xa5] && (local_228[3] != 0)))) ||
                      (((puVar21[0x90] == 0xdf6dabba && (local_228[1] == 0x16164674)) || (bVar3))))
                     && (((((puVar21[0xa1] & 0x20) != 0 &&
                           (((local_228[1] == -0x599d55a0 || (local_228[1] == 0x4b970310)) ||
                            (local_228[1] == 0x33fe0a68)))) ||
                          (((puVar21[0xa1] & 0x40) != 0 && (local_228[1] == 0x16164674)))) &&
                         ((local_150 & 4) != 0)))) {
                    fVar26 = (local_144 - (float)puVar21[0x10d]) *
                             (local_144 - (float)puVar21[0x10d]) +
                             (local_14c - (float)puVar21[0x10b]) *
                             (local_14c - (float)puVar21[0x10b]);
                    local_468 = (double)CONCAT44(local_468._4_4_,fVar26);
                    if (fVar26 < local_488) {
                      if (local_228[1] == 0x16164674) {
                        iVar12 = 0;
                        do {
                          bVar5 = GiveWeapon(*puVar21,local_214,iVar12);
                          if (bVar5) goto LAB_4fc1ee57;
                          iVar12 = iVar12 + 1;
                        } while (iVar12 < 5);
                      }
                      else {
LAB_4fc1ee57:
                        (*local_410)(local_1d4,*puVar21,4,0,0);
                        (*local_40c)(*puVar21,local_228[2]);
                        (*local_408)(*puVar21,local_228[3]);
                        if (local_499 != false) {
                          memset(local_c8,0,0x40);
                          GetODFName(*puVar21,local_c8);
                          fmtarg9 = (double)local_144;
                          fmtarg8 = (double)local_148;
                          dVar28 = (double)local_14c;
                          pcVar11 = GetODFName(local_228[0]);
                          FormatLogMessage("POWERUP ACCEPTED: \'%s\' on Team %d at: %f %f %f w/ ColRad: %f Accepted Powerup: \'%s\' at: %f %f %f"
                                           ,local_c8,puVar21[0xa2],
                                           (double)CONCAT44(SUB84((double)(float)puVar21[0x10c],0),
                                                            (int)((ulonglong)
                                                                  (double)(float)puVar21[0x10b] >>
                                                                 0x20)),
                                           (double)CONCAT44(SUB84((double)(float)puVar21[0x10d],0),
                                                            (int)((ulonglong)
                                                                  (double)(float)puVar21[0x10c] >>
                                                                 0x20)),
                                           (double)CONCAT44(SUB84((double)(float)puVar21[0xaa],0),
                                                            (int)((ulonglong)
                                                                  (double)(float)puVar21[0x10d] >>
                                                                 0x20)),
                                           (double)CONCAT44(pcVar11,(int)((ulonglong)
                                                                          (double)(float)puVar21[
                                                  0xaa] >> 0x20)),SUB84(dVar28,0),fmtarg8,fmtarg9,
                                           (double)CONCAT44(unaff_ESI,unaff_EDI));
                        }
                        pcVar15 = local_404;
                        if (bVar3) {
                          iVar12 = 0;
                          do {
                            (*pcVar15)(*puVar21,(float)local_218,iVar12);
                            iVar12 = iVar12 + 1;
                            pVVar17 = local_494;
                          } while (iVar12 < 5);
                        }
                        (*local_400)(local_228[0]);
                      }
                    }
                  }
                }
              }
              local_494 = (Vector *)((int)pVVar17 + 0x104);
              local_490 = (Vector *)((int)local_490 + 1);
            } while ((int)local_490 <
                     (*(int *)&(PowerupHelper::m_PowerupHelper->PowerupList).field_0x4 -
                     *(int *)&PowerupHelper::m_PowerupHelper->PowerupList) / 0x104);
          }
        }
      }
      puVar6 = puVar21 + 0xa2;
      uVar7 = *puVar6;
      iVar12 = (*local_3fc)(uVar7);
      pBVar1 = local_478;
      if (((iVar12 == 0) && (local_478->teamInfo[uVar7].m_CPUUnitsCanService != false)) &&
         (fVar26 = GetHealth(*puVar21),
         fVar26 < pBVar1->teamInfo[uVar7].m_CPUBuildingRepairHealthRatio)) {
        local_450 = (double)CONCAT44(local_450._4_4_,(float)BZ1Helper::m_GameTPS);
        _ftol2_sse();
        puVar21 = local_46c;
        if (((BZ1Helper::m_TurnCounter % extraout_EAX == 0) &&
            (fVar26 = local_3f8, fVar27 = GetRandomFloat(local_3f8), puVar21 = local_46c,
            this_00 = UtilityShipHelper::m_UtilityShipHelper,
            fVar27 < pBVar1->teamInfo[uVar7].m_CPUBuildingRepairChance)) &&
           (local_498 = local_46c, (local_46c[0xa1] & 0x20) != 0)) {
          fVar27 = local_3f4;
          bVar3 = IsProducer(*local_46c);
          iVar12 = UtilityShipHelper::FindServiceTruck
                             (this_00,*puVar21,*puVar6,bVar3,fVar27,(int)fVar26);
          if (iVar12 == 0) {
            if (local_478->teamInfo[uVar7].Armory != 0) {
              pcVar29 = (char *)0x40;
              pcVar11 = local_88;
              iVar12 = 0;
              memset(pcVar11,0,0x40);
              bVar3 = GetBuildItem((int)pcVar11,(char *)0x1,(int *)0x0,iVar12,pcVar29,
                                   (char *)unaff_EDI,(char *)unaff_ESI);
              if (bVar3) {
                uVar30 = *puVar6;
                iVar12 = (*misnImport.GetScrap)(uVar30);
                if (-1 < iVar12) {
                  BZ1Helper::BuildAt(local_478,local_478->teamInfo[uVar7].Armory,local_88,
                                     *(Vector *)(puVar21 + 0x10b),uVar30);
                  puVar21 = local_498;
                }
              }
            }
          }
          else {
            (*local_3f0)(iVar12,*puVar21,0);
          }
        }
      }
      puVar21 = puVar21 + 0x116;
      local_3e4 = *(uint **)&(local_474->BuildingList).field_0x4;
    } while (puVar21 != local_3e4);
  }
  return;
}


// ---------------------------------------------------------------------
// BuildingHelper::IsBuildingPowered  @ 4fc1f163  lines 768-779

bool __thiscall BuildingHelper::IsBuildingPowered(BuildingHelper *this,int h)

{
  bool bVar1;
  bool bVar2;
  int *piVar3;
  
  bVar1 = IsAround(h);
  bVar2 = false;
  if (bVar1) {
    for (piVar3 = *(int **)&this->BuildingList; piVar3 != *(int **)&(this->BuildingList).field_0x4;
        piVar3 = piVar3 + 0x116) {
      if (*piVar3 == h) {
        return (bool)(char)piVar3[0x8d];
      }
    }
    bVar2 = true;
  }
  return bVar2;
}


// ---------------------------------------------------------------------
// BuildingHelper::GetRandomBuilding  @ 4fc1f198  lines 798-841

int __thiscall
BuildingHelper::GetRandomBuilding
          (BuildingHelper *this,int param_1,int param_2,bool param_3,bool param_4,bool param_5,
          int param_6,char *param_7,char *param_8,float param_9,Vector param_10)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  int Max;
  int iVar4;
  int iVar5;
  int iVar6;
  float fVar7;
  
  Max = (*(int *)&(this->BuildingList).field_0x4 - *(int *)&this->BuildingList) / 0x458 + -1;
  if (Max < 0) {
    Max = 0;
  }
  iVar4 = GetRandomInt(0,Max);
  iVar6 = iVar4;
  do {
    iVar5 = iVar6 * 0x458;
    iVar1 = *(int *)(iVar5 + *(int *)&this->BuildingList);
    if ((((param_1 < 0) ||
         (bVar3 = TeamFilterCheck(param_2,param_1,
                                  *(int *)(iVar5 + 0x28c + *(int *)&this->BuildingList)), bVar3)) &&
        (iVar2 = *(int *)&this->BuildingList, 0 < *(int *)(iVar5 + 0x290 + iVar2))) &&
       (*(char *)(iVar5 + 0x238 + iVar2) != '\0')) {
      if (param_9 <= 0.0) {
        return iVar1;
      }
      fVar7 = GetDistance3DSquared((Vector *)(iVar2 + 0x42c + iVar5),&param_10);
      if (fVar7 < param_9 * param_9) {
        return iVar1;
      }
    }
    iVar1 = iVar6 + 1;
    iVar6 = 0;
    if (iVar1 <= Max) {
      iVar6 = iVar1;
    }
    if (iVar6 == iVar4) {
      return 0;
    }
  } while( true );
}


// ---------------------------------------------------------------------
// BuildingHelper::GetNumBuildings  @ 4fc1f268  lines 845-878

int __thiscall
BuildingHelper::GetNumBuildings
          (BuildingHelper *this,int param_1,int param_2,bool param_3,bool param_4,bool param_5,
          int param_6,char *param_7,char *param_8)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_8;
  
  iVar4 = 0;
  iVar3 = *(int *)&this->BuildingList;
  local_8 = 0;
  if (0 < (*(int *)&(this->BuildingList).field_0x4 - iVar3) / 0x458) {
    iVar2 = 0;
    do {
      if (param_1 < 0) {
LAB_4fc1f2b8:
        if (0 < *(int *)(iVar2 + 0x290 + iVar3)) {
          iVar4 = iVar4 + 1;
        }
      }
      else {
        bVar1 = TeamFilterCheck(4,param_1,*(int *)(iVar2 + 0x288 + iVar3));
        if (bVar1) {
          iVar3 = *(int *)&this->BuildingList;
          goto LAB_4fc1f2b8;
        }
      }
      iVar3 = *(int *)&this->BuildingList;
      iVar2 = iVar2 + 0x458;
      local_8 = local_8 + 1;
    } while (local_8 < (*(int *)&(this->BuildingList).field_0x4 - iVar3) / 0x458);
  }
  return iVar4;
}


// ---------------------------------------------------------------------
// BuildingHelper::GetNearestServiceObject  @ 4fc1f2eb  lines 946-1020

int __thiscall
BuildingHelper::GetNearestServiceObject
          (BuildingHelper *this,int param_1,Vector param_2,float param_3,int param_4,int param_5,
          bool param_6,bool param_7,bool param_8,int param_9,int param_10,char *param_11,
          char *param_12)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  float fVar8;
  float local_118;
  int local_104 [4];
  int local_f4;
  float local_28;
  float local_24;
  float local_20;
  
  iVar4 = 0;
  if (0.0 < param_3) {
    local_118 = param_3 * param_3;
  }
  else {
    local_118 = 3.4028235e+38;
  }
  iVar5 = 0;
  iVar1 = (*(int *)&(PowerupHelper::m_PowerupHelper->PowerupList).field_0x4 -
          *(int *)&PowerupHelper::m_PowerupHelper->PowerupList) / 0x104;
  if (0 < iVar1) {
    piVar3 = *(int **)&PowerupHelper::m_PowerupHelper->PowerupList;
    do {
      piVar6 = piVar3;
      piVar7 = local_104;
      for (iVar2 = 0x41; iVar2 != 0; iVar2 = iVar2 + -1) {
        *piVar7 = *piVar6;
        piVar6 = piVar6 + 1;
        piVar7 = piVar7 + 1;
      }
      if ((((((param_1 & 1U) != 0) && (local_104[2] != 0)) ||
           (((param_1 & 2U) != 0 && (local_104[3] != 0)))) ||
          (((param_1 & 4U) != 0 && (local_f4 != 0)))) &&
         (fVar8 = (param_2.z - local_20) * (param_2.z - local_20) +
                  (param_2.y - local_24) * (param_2.y - local_24) +
                  (param_2.x - local_28) * (param_2.x - local_28), fVar8 < local_118)) {
        iVar4 = local_104[0];
        local_118 = fVar8;
      }
      iVar5 = iVar5 + 1;
      piVar3 = piVar3 + 0x41;
    } while (iVar5 < iVar1);
  }
  for (piVar3 = *(int **)&this->BuildingList; piVar3 != *(int **)&(this->BuildingList).field_0x4;
      piVar3 = piVar3 + 0x116) {
    fVar8 = GetDistance3DSquared((Vector *)(piVar3 + 0x10b),&param_2);
    if (fVar8 < local_118) {
      iVar4 = *piVar3;
      local_118 = fVar8;
    }
  }
  return iVar4;
}


