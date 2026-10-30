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
  BuildingClass *unaff_ESI;
  int *piVar4;
  BuildingClass *unaff_EDI;
  int iVar5;
  
  piVar4 = *(int **)&this->BuildingList;
  piVar2 = *(int **)&(this->BuildingList).field_0x4;
  if (piVar4 != piVar2) {
    do {
      ConvertHandles(piVar4,1);
      iVar3 = 8;
      piVar2 = piVar4;
      do {
        piVar2 = piVar2 + 1;
        ConvertHandles(piVar2,1);
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
      piVar2 = *(int **)&(this->BuildingList).field_0x4;
      piVar4 = piVar4 + 0x116;
    } while (piVar4 != piVar2);
    piVar4 = *(int **)&this->BuildingList;
  }
  iVar3 = ((int)piVar2 - (int)piVar4) / 0x458;
  if ((int)(TempBuildingBuffer._4_4_ - TempBuildingBuffer._0_4_) / 0x458 == iVar3) {
    iVar5 = 0;
    if (0 < iVar3) {
      do {
        bVar1 = ::operator==(unaff_EDI,unaff_ESI);
        if (!bVar1) {
          FormatLogMessage("BuildingList Index Mismatch: %d");
          return true;
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < (*(int *)&(this->BuildingList).field_0x4 - *(int *)&this->BuildingList) /
                       0x458);
    }
  }
  else {
    FormatLogMessage("BuildingList Size Mismatch! Old: %d New: %d");
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
  uint uVar3;
  long lVar4;
  Matrix *__return_storage_ptr__;
  Matrix *pMVar5;
  int iVar6;
  Matrix *__return_storage_ptr___00;
  char *unaff_ESI;
  int *piVar7;
  int *piVar8;
  float *unaff_EDI;
  vector<BuildingHelper::BuildingClass,std::allocator<BuildingHelper::BuildingClass>_> *pvVar9;
  bool *pbVar10;
  char cVar11;
  char *pcVar12;
  undefined1 uVar13;
  char (*pacVar14) [64];
  char *pcVar15;
  char *pcVar16;
  undefined1 uVar17;
  char *pcVar18;
  char *pcVar19;
  Matrix *pMVar20;
  int iVar21;
  bool *pbVar22;
  int *local_274;
  char *local_270;
  char local_26c;
  char local_26b;
  char local_26a;
  char local_269;
  char *local_268;
  bool *local_264;
  vector<BuildingHelper::BuildingClass,std::allocator<BuildingHelper::BuildingClass>_> *local_260;
  code *local_25c;
  Vector local_258;
  Matrix local_24c [2];
  Matrix local_1cc [2];
  char local_14c [64];
  char local_10c [64];
  undefined1 local_cc [64];
  char local_8c [64];
  int local_4c [17];
  uint local_8;
  
  local_8 = __security_cookie ^ (uint)&local_274;
  piVar8 = *(int **)&this->BuildingList;
  local_274 = (int *)param_3;
  iVar2 = -1;
  local_264 = (bool *)param_1;
  local_268 = param_2;
  local_25c = GetTap_exref;
  piVar7 = piVar8;
  local_260 = &this->BuildingList;
  if (piVar8 != *(int **)&(this->BuildingList).field_0x4) {
LAB_4fc1dc41:
    if (*piVar7 != param_1) goto code_r0x4fc1dc49;
    pcVar12 = (char *)0x0;
    iVar2 = 0;
    do {
      iVar21 = (*local_25c)(*piVar7,iVar2);
      memset(local_14c,0,0x40);
      GetObjInfo(iVar21,Get_ODF,local_14c);
      if (local_14c[0] != '\0') {
        pcVar12 = pcVar12 + 1;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < 8);
    if ((char *)piVar7[0x9c] != pcVar12) {
      piVar7[0x9c] = (int)pcVar12;
    }
    local_270 = pcVar12;
    if (piVar7[0x90] == -0x20925446) {
      if (piVar7 == (int *)0xfffffd54) {
        uVar3 = 0;
      }
      else {
        uVar3 = Hash((char *)unaff_EDI,(uint)unaff_ESI);
      }
      if (param_5 == uVar3) {
        ReplaceWeapons(0,(char (*) [64])0x0,unaff_EDI,unaff_ESI);
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
  iVar21 = 0;
  piVar8 = piVar8 + iVar2 * 0x116;
  piVar7 = piVar8;
  memset(piVar8,0,0x458);
  GetODFInt("GameObjectClass","RequirePowerMask",(char *)(piVar8 + 0x92),(char *)0x0,piVar7,iVar21);
  uVar17 = 0xd4;
  if (param_6 == -0x20925446) {
    pcVar15 = "TurretCraftClass";
    GetODFBool("TurretCraftClass","PoweredByTaps",(char *)((int)piVar8 + 0x23d),(char *)0x1,
               (bool *)unaff_EDI,SUB41(unaff_ESI,0));
    uVar13 = 100;
    pcVar12 = "TurretCraftClass";
    GetODFBool("TurretCraftClass","autoBuildTaps",(char *)((int)piVar8 + 0x23e),(char *)0x1,
               (bool *)pcVar15,(bool)uVar17);
    GetODFBool("TurretCraftClass","canDemolish",(char *)(piVar8 + 0x8f),(char *)0x1,(bool *)pcVar12,
               (bool)uVar13);
    piVar8[0xa6] = param_9;
  }
  else {
    pcVar15 = "PoweredBuildingClass";
    GetODFBool("PoweredBuildingClass","PoweredByTaps",(char *)((int)piVar8 + 0x23d),(char *)0x1,
               (bool *)unaff_EDI,SUB41(unaff_ESI,0));
    uVar13 = 100;
    pcVar12 = "PoweredBuildingClass";
    GetODFBool("PoweredBuildingClass","autoBuildTaps",(char *)((int)piVar8 + 0x23e),(char *)0x1,
               (bool *)pcVar15,(bool)uVar17);
    GetODFBool("BuildingClass","canDemolish",(char *)(piVar8 + 0x8f),(char *)0x1,(bool *)pcVar12,
               (bool)uVar13);
  }
  pcVar18 = "GameObjectClassPowerMask";
  pcVar16 = "GameObjectClass";
  GetODFInt("GameObjectClass","GameObjectClassPowerMask",(char *)(piVar8 + 0x9e),(char *)0x0,
            (int *)unaff_EDI,(int)unaff_ESI);
  pcVar15 = "GameObjectClassPowerMatch";
  pcVar12 = "GameObjectClass";
  GetODFInt("GameObjectClass","GameObjectClassPowerMatch",(char *)(piVar8 + 0x9f),(char *)0x0,
            (int *)pcVar16,(int)pcVar18);
  GetODFInt("GameObjectClass","GameObjectClassPowerProvides",(char *)(piVar8 + 0xa0),(char *)0x0,
            (int *)pcVar12,(int)pcVar15);
  local_274 = (int *)0x0;
  uVar17 = 0xd8;
  pcVar12 = "GameObjectClass";
  GetODFFloat("GameObjectClass","CollisionRadius",(char *)(piVar8 + 0xaa),(char *)0x0,unaff_EDI,
              (float)unaff_ESI);
  uVar13 = 0xe8;
  pcVar15 = "GameObjectClass";
  GetODFBool("GameObjectClass","CanCollide",(char *)((int)piVar8 + 0x237),(char *)0x0,
             (bool *)pcVar12,(bool)uVar17);
  uVar17 = 0xf4;
  pcVar12 = "GameObjectClass";
  GetODFBool("GameObjectClass","ownsTerrain",(char *)((int)piVar8 + 0x23f),(char *)0x1,
             (bool *)pcVar15,(bool)uVar13);
  local_26c = '\0';
  GetODFBool("GameObjectClass","CanAcceptPowerups",&local_26c,(char *)0x0,(bool *)pcVar12,
             (bool)uVar17);
  pcVar12 = (char *)((local_26c == '\0') - 1);
  piVar8[0xa1] = (int)pcVar12;
  pcVar19 = "AcceptPowerupMask";
  pcVar18 = "GameObjectClass";
  GetODFInt("GameObjectClass","AcceptPowerupMask",(char *)(piVar8 + 0xa1),pcVar12,(int *)unaff_EDI,
            (int)unaff_ESI);
  pcVar16 = "SizeRatioX";
  pcVar15 = "BuildingClass";
  GetODFInt("BuildingClass","SizeRatioX",(char *)(piVar8 + 0xa7),(char *)0x1,(int *)pcVar18,
            (int)pcVar19);
  cVar11 = '4';
  pcVar12 = "BuildingClass";
  GetODFInt("BuildingClass","SizeRatioZ",(char *)(piVar8 + 0xa8),(char *)0x1,(int *)pcVar15,
            (int)pcVar16);
  local_26b = '\0';
  GetODFChar("GameObjectClass","buildSupport",&local_26b,(char *)0x41,pcVar12,cVar11);
  pcVar12 = (char *)(int)local_26b;
  iVar2 = toupper((int)pcVar12);
  piVar8[0xa9] = iVar2;
  GetODFString("GameObjectClass","upgradeName",(char *)0x40,(char *)(piVar8 + 0xab),0,pcVar12,
               (char *)unaff_EDI);
  piVar8[0xa2] = param_4;
  if ((param_7 == -0x221bc770) ||
     (local_270 = (char *)((uint)local_270 & 0xffffff00), param_6 == -0x4e710e3d)) {
    local_270 = (char *)CONCAT31(local_270._1_3_,1);
  }
  GetODFBool("GameObjectClass","APCRefillPoint",(char *)((int)piVar8 + 0x239),local_270,
             (bool *)unaff_EDI,SUB41(unaff_ESI,0));
  pbVar10 = local_264;
  if ((((param_7 == -0x221bc770) && (bVar1 = IsBuilding((int)local_264), bVar1)) ||
      (param_6 == -0x7f06008f)) ||
     (local_270 = (char *)((uint)local_270 & 0xffffff00), param_6 == 0x490dd218)) {
    local_270 = (char *)CONCAT31(local_270._1_3_,1);
  }
  GetODFBool("GameObjectClass","RecyclePoint",(char *)((int)piVar8 + 0x23a),local_270,
             (bool *)unaff_EDI,SUB41(unaff_ESI,0));
  if (piVar8[0x90] == -0x25234de5) {
    GetODFFloat("SupplyDepotClass","healthRate",(char *)(piVar8 + 0x111),(char *)local_274,unaff_EDI
                ,(float)unaff_ESI);
    GetODFFloat("SupplyDepotClass","ammoRate",(char *)(piVar8 + 0x112),(char *)local_274,unaff_EDI,
                (float)unaff_ESI);
    GetODFFloat("SupplyDepotClass","localAmmoRate",(char *)(piVar8 + 0x113),(char *)local_274,
                unaff_EDI,(float)unaff_ESI);
    uVar17 = 0xb8;
    pcVar12 = "SupplyDepotClass";
    GetODFFloat("SupplyDepotClass","supplyRate",(char *)(piVar8 + 0x114),(char *)local_274,unaff_EDI
                ,(float)unaff_ESI);
    GetODFBool("SupplyDepotClass","serviceCraft",(char *)(piVar8 + 0x115),(char *)0x1,
               (bool *)pcVar12,(bool)uVar17);
  }
  pbVar22 = pbVar10;
  lVar4 = GetMaxHealth((int)pbVar10);
  uVar17 = SUB41(pbVar22,0);
  piVar8[0xa4] = lVar4;
  pbVar22 = pbVar10;
  lVar4 = GetMaxAmmo((int)pbVar10);
  piVar8[0xa5] = lVar4;
  *(bool *)(piVar8 + 0x8e) = param_8;
  local_26a = '\x01';
  GetODFBool("GameObjectClass","IsAnimated",&local_26a,(char *)0x1,pbVar22,(bool)uVar17);
  if (local_26a != '\0') {
    piVar7 = (int *)local_10c;
    iVar2 = 0;
    memset(piVar7,0,0x40);
    local_268 = (char *)0x0;
    GetODFInt("GameObjectClass","animCount",(char *)&local_268,(char *)0x0,piVar7,iVar2);
    local_274 = (int *)0x1;
    if (1 < (int)(local_268 + 1)) {
      do {
        memset(local_14c,0,0x40);
        pacVar14 = &local_14c;
        pcVar12 = "animName%d";
        sprintf_s<64>(pacVar14,"animName%d");
        iVar2 = GetODFString("GameObjectClass",local_14c,(char *)0x40,local_10c,0,*pacVar14,pcVar12)
        ;
        if ((iVar2 != 0) && (iVar2 = _stricmp(local_10c,"BZCloop"), iVar2 == 0)) {
          *(undefined1 *)((int)piVar8 + 0x235) = 1;
          break;
        }
        local_274 = (int *)((int)local_274 + 1);
      } while ((int)local_274 < (int)(local_268 + 1));
    }
  }
  GetPosition((int)pbVar10,local_24c);
  iVar2 = 0;
  local_270 = (char *)0x0;
  local_260 = (vector<BuildingHelper::BuildingClass,std::allocator<BuildingHelper::BuildingClass>_>
               *)(piVar8 + 0xd);
  local_274 = piVar8 + 1;
  do {
    __return_storage_ptr__ = (Matrix *)(*local_25c)(pbVar10,iVar2);
    if (__return_storage_ptr__ != (Matrix *)0x0) {
      memset(local_10c,0,0x40);
      memset(local_cc,0,0x40);
      pcVar12 = local_14c;
      pcVar15 = (char *)0x0;
      memset(pcVar12,0,0x40);
      GetAndOpenODFNames((int)local_14c,local_10c,pcVar12,pcVar15);
      if (local_10c[0] != '\0') {
        local_270 = (char *)((int)local_270 + 1);
        *local_274 = (int)__return_storage_ptr__;
        pMVar5 = local_1cc;
        GetPosition((int)__return_storage_ptr__,pMVar5);
        Matrix_Inverse(__return_storage_ptr__,pMVar5);
        pMVar20 = __return_storage_ptr___00;
        pMVar5 = Matrix_Multiply(__return_storage_ptr___00,__return_storage_ptr__,pMVar5);
        pvVar9 = local_260;
        for (iVar21 = 0x10; iVar21 != 0; iVar21 = iVar21 + -1) {
          *(float *)pvVar9 = (pMVar5->right).x;
          pMVar5 = (Matrix *)&(pMVar5->right).y;
          pvVar9 = (vector<BuildingHelper::BuildingClass,std::allocator<BuildingHelper::BuildingClass>_>
                    *)((int)pvVar9 + 4);
        }
        local_269 = '\x01';
        GetODFBool("GameObjectClass","IsAnimated",&local_269,(char *)0x1,(bool *)pMVar20,
                   SUB41(__return_storage_ptr__,0));
        if (local_269 != '\0') {
          piVar7 = local_4c;
          iVar21 = 0;
          memset(piVar7,0,0x40);
          local_268 = (char *)0x0;
          GetODFInt("GameObjectClass","animCount",(char *)&local_268,(char *)0x0,piVar7,iVar21);
          iVar21 = 1;
          if (1 < (int)(local_268 + 1)) {
            do {
              memset(local_8c,0,0x40);
              pacVar14 = &local_8c;
              pcVar12 = "animName%d";
              sprintf_s<64>(pacVar14,"animName%d");
              iVar6 = GetODFString("GameObjectClass",local_8c,(char *)0x40,(char *)local_4c,0,
                                   *pacVar14,pcVar12);
              if ((iVar6 != 0) && (iVar6 = _stricmp((char *)local_4c,"BZCloop"), iVar6 == 0)) {
                *(undefined1 *)((int)piVar8 + iVar2 + 0x24) = 1;
                break;
              }
              iVar21 = iVar21 + 1;
            } while (iVar21 < (int)(local_268 + 1));
          }
        }
        pbVar10 = local_264;
      }
    }
    local_274 = local_274 + 1;
    iVar2 = iVar2 + 1;
    local_260 = (vector<BuildingHelper::BuildingClass,std::allocator<BuildingHelper::BuildingClass>_>
                 *)((int)local_260 + 0x40);
    if (7 < iVar2) {
      piVar8[0x9d] = -1;
      piVar8[0x9c] = (int)local_270;
      piVar8[0x90] = param_6;
      piVar8[0x91] = param_5;
      *piVar8 = (int)pbVar10;
      GetPosition((int)pbVar10,&local_258);
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

void __thiscall BuildingHelper::Execute(BuildingHelper *this,BZ1Helper *param_1)

{
  uint uVar1;
  UtilityShipHelper *this_00;
  BZ1Helper *pBVar2;
  code *pcVar3;
  bool bVar4;
  char cVar5;
  bool bVar6;
  int *piVar7;
  undefined4 uVar8;
  float *pfVar9;
  Matrix *pMVar10;
  int extraout_EAX;
  int iVar11;
  int iVar12;
  int iVar13;
  undefined4 extraout_ECX;
  Matrix *__return_storage_ptr__;
  AlignTerrainReplaceClass *pAVar14;
  PowerHelper *pPVar15;
  code *pcVar16;
  int *piVar17;
  int *piVar18;
  AlignTerrainReplaceClass *pAVar19;
  Matrix *unaff_ESI;
  AlignTerrainReplaceClass *pAVar20;
  Matrix *unaff_EDI;
  size_t sVar21;
  float *pfVar22;
  code *pcVar23;
  int *piVar24;
  float fVar25;
  float fVar26;
  char *pcVar27;
  Matrix *__return_storage_ptr___00;
  char *pcVar28;
  undefined1 auStack_4a0 [7];
  bool local_499;
  int *local_498;
  float *local_494;
  int *local_490;
  char local_489;
  float local_488;
  code *local_484;
  code *local_480;
  AlignTerrainReplaceClass *local_47c;
  BZ1Helper *local_478;
  BuildingHelper *local_474;
  code *local_470;
  int *local_46c;
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
  int *local_3e4;
  float local_3e0 [4];
  uint local_3d0;
  uint local_3cc;
  uint local_3c8;
  Matrix local_3b8;
  undefined1 local_368 [48];
  Vector local_338 [12];
  Matrix local_2a8 [2];
  int local_228 [4];
  int local_218;
  int local_154;
  byte local_150;
  float local_14c;
  float local_144;
  float local_12c;
  undefined1 local_120 [4];
  undefined4 local_11c;
  undefined1 local_10c;
  undefined1 local_108 [64];
  undefined1 local_c8 [64];
  char local_88 [64];
  undefined1 local_48 [68];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)auStack_4a0;
  local_499 = BZ1Helper::Logging;
  pAVar20 = *(AlignTerrainReplaceClass **)&(this->BuildingList).field_0x4;
  pAVar14 = *(AlignTerrainReplaceClass **)&this->BuildingList;
  local_478 = param_1;
  local_47c = pAVar20;
  local_474 = this;
  local_3ec = pAVar20;
  local_3e8 = pAVar14;
  while ((pAVar14 != pAVar20 &&
         (bVar4 = BZ1Helper::ShouldRemoveAlignTerrainReplace(pAVar14), !bVar4))) {
    pAVar14 = (AlignTerrainReplaceClass *)&pAVar14[0x45].NormalVec.y;
  }
  pAVar19 = pAVar14;
  if (pAVar14 != pAVar20) {
    while( true ) {
      this = local_474;
      pAVar19 = (AlignTerrainReplaceClass *)&pAVar19[0x45].NormalVec.y;
      if (pAVar19 == pAVar20) break;
      bVar4 = BZ1Helper::ShouldRemoveAlignTerrainReplace(pAVar19);
      if (!bVar4) {
        pfVar9 = (float *)pAVar19;
        pAVar20 = pAVar14;
        for (iVar12 = 0x116; iVar12 != 0; iVar12 = iVar12 + -1) {
          pAVar20->AlignHandle = (int)*pfVar9;
          pfVar9 = pfVar9 + 1;
          pAVar20 = (AlignTerrainReplaceClass *)&pAVar20->NormalVec;
        }
        pAVar14 = (AlignTerrainReplaceClass *)&pAVar14[0x45].NormalVec.y;
        pAVar20 = local_47c;
      }
    }
    if (pAVar14 != pAVar20) {
      sVar21 = *(int *)&(local_474->BuildingList).field_0x4 - (int)pAVar20;
      memmove(pAVar14,pAVar20,sVar21);
      piVar7 = (int *)(sVar21 + (int)pAVar14);
      *(int **)&(this->BuildingList).field_0x4 = piVar7;
      goto LAB_4fc1e559;
    }
  }
  piVar7 = *(int **)&(this->BuildingList).field_0x4;
LAB_4fc1e559:
  local_46c = *(int **)&this->BuildingList;
  if (local_46c != piVar7) {
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
    local_454 = __real_3c23d70a;
    local_410 = StartAudio3D_exref;
    local_40c = AddHealth_exref;
    local_3f4 = 0.0;
    local_408 = AddAmmo_exref;
    local_404 = AddLocalAmmo_exref;
    local_41c = __real_3f000000;
    local_400 = RemoveObject_exref;
    local_3fc = GetPlayerHandle_exref;
    local_3f8 = 1.0;
    local_47c = (AlignTerrainReplaceClass *)GetTeamNum_exref;
    local_484 = GetAnimationDirection_exref;
    local_480 = PauseAnimation_exref;
    local_3f0 = Service_exref;
    local_470 = GetPosition_exref;
    do {
      piVar7 = local_46c;
      pcVar3 = local_470;
      pcVar23 = local_480;
      pcVar16 = local_484;
      local_498 = local_46c;
      iVar12 = (*(code *)local_47c)(*local_46c);
      piVar7[0xa2] = iVar12;
      (*pcVar3)(*piVar7,&local_3b8);
      uVar8 = (*local_45c)(*piVar7);
      local_468 = (double)CONCAT44(local_468._4_4_,uVar8);
      local_490 = (int *)0x0;
      iVar12 = 0;
      if (piVar7[0x9c] != 0) {
        local_490 = (int *)GetTapCount(piVar7[0x9c],SUB41(unaff_EDI,0),SUB41(unaff_ESI,0));
        iVar12 = piVar7[0x9c];
      }
      if ((*(char *)((int)piVar7 + 0x23e) == '\0') && (iVar12 < (int)local_490)) {
        piVar7[0x9c] = (int)local_490;
      }
      bVar4 = piVar7[0x9d] != 0;
      if (piVar7[0x9d] < 0) {
        cVar5 = '\0';
        local_489 = '\0';
        if ((*(byte *)(piVar7 + 0x92) & 1) != 0) {
          local_488 = 0.0;
          if (0 < (*(int *)&(PowerHelper::m_PowerHelper->PowerList).field_0x4 -
                  *(int *)&PowerHelper::m_PowerHelper->PowerList) / 0x28) {
            iVar12 = 0;
            pPVar15 = PowerHelper::m_PowerHelper;
            do {
              piVar7 = local_498;
              pfVar9 = (float *)(*(int *)&pPVar15->PowerList + iVar12);
              pfVar22 = local_3e0;
              for (iVar13 = 10; iVar13 != 0; iVar13 = iVar13 + -1) {
                *pfVar22 = *pfVar9;
                pfVar9 = pfVar9 + 1;
                pfVar22 = pfVar22 + 1;
              }
              if ((char)((uint)local_3e0[1] >> 0x10) != '\0') {
                cVar5 = (*local_414)(local_498[0xa2],local_3e0[2]);
                if (((cVar5 != '\0') && ((piVar7[0x9e] & local_3c8) == piVar7[0x9f])) &&
                   ((piVar7[0xa0] & local_3d0) == local_3cc)) {
                  local_450 = (double)local_3e0[3];
                  fVar25 = GetDistance3DSquared(&unaff_EDI->right,&unaff_ESI->right);
                  local_494 = (float *)(float)((float10)local_450 * (float10)local_450);
                  if (fVar25 < (float)local_494) {
                    cVar5 = '\x01';
                    goto LAB_4fc1e7fe;
                  }
                }
                pPVar15 = PowerHelper::m_PowerHelper;
              }
              iVar12 = iVar12 + 0x28;
              local_488 = (float)((int)local_488 + 1);
            } while ((int)local_488 <
                     (*(int *)&(pPVar15->PowerList).field_0x4 - *(int *)&pPVar15->PowerList) / 0x28)
            ;
            cVar5 = local_489;
LAB_4fc1e7fe:
            pcVar23 = local_480;
          }
          pcVar16 = local_484;
        }
        uVar1 = piVar7[0x92];
        if ((((uVar1 == 0) || (((uVar1 & 1) != 0 && (cVar5 != '\0')))) ||
            (((uVar1 & 2) != 0 && (iVar12 = (*local_448)(piVar7[0xa2]), -1 < iVar12)))) ||
           (((*(byte *)(piVar7 + 0x92) & 4) != 0 &&
            ((*(char *)((int)piVar7 + 0x23d) == '\0' || (local_490 == (int *)piVar7[0x9c])))))) {
          bVar4 = true;
        }
        else {
          bVar4 = false;
        }
      }
      *(bool *)(piVar7 + 0x8d) = bVar4;
      if (*(char *)((int)piVar7 + 0x235) != '\0') {
        iVar12 = (*pcVar16)(*piVar7);
        bVar4 = iVar12 != 0;
        *(bool *)((int)piVar7 + 0x236) = bVar4;
        if ((char)piVar7[0x8d] == '\0') {
          if (bVar4) {
            iVar12 = (*pcVar23)(*piVar7);
LAB_4fc1e8a6:
            piVar7[0x93] = iVar12;
          }
        }
        else if (!bVar4) {
          if (piVar7[0x93] == 0) {
            iVar12 = (*pcVar16)(*piVar7);
            goto LAB_4fc1e8a6;
          }
          (*local_458)(*piVar7,piVar7[0x93]);
        }
      }
      iVar12 = 0;
      if (0 < piVar7[0x9c]) {
        local_490 = piVar7 + 0x19;
        piVar18 = piVar7;
        do {
          piVar24 = local_490;
          piVar17 = piVar18 + 1;
          cVar5 = (*local_444)(*piVar17);
          if (cVar5 != '\0') {
            (*local_470)(*piVar17,local_368);
            local_494 = (float *)piVar7[0xa2];
            pfVar9 = (float *)(*(code *)local_47c)(*piVar17);
            if (local_494 != pfVar9) {
              (*local_440)(*piVar17,local_494);
            }
            iVar13 = (*local_45c)(*piVar17);
            if (iVar13 != local_468._0_4_) {
              (*local_43c)(*piVar17,local_468._0_4_);
            }
            if (*(char *)((int)piVar7 + iVar12 + 0x24) != '\0') {
              iVar13 = (*local_484)(*piVar17);
              bVar4 = iVar13 != 0;
              *(bool *)((int)piVar7 + iVar12 + 0x2c) = bVar4;
              if ((char)piVar7[0x8d] == '\0') {
                if (bVar4) {
                  iVar13 = (*local_480)(*piVar17);
                  piVar18[0x94] = iVar13;
                  *(undefined1 *)((int)piVar7 + iVar12 + 0x2c) = 0;
                }
              }
              else if (!bVar4) {
                if (piVar18[0x94] == 0) {
                  iVar13 = (*local_484)(*piVar17);
                  piVar18[0x94] = iVar13;
                }
                else {
                  (*local_458)(*piVar17,piVar18[0x94]);
                  *(undefined1 *)((int)piVar7 + iVar12 + 0x2c) = 1;
                }
              }
            }
            pMVar10 = local_454;
            Vector_TransformInv(local_338,local_454,&unaff_EDI->right);
            bVar4 = close_enough(&pMVar10->right,&unaff_EDI->right,(float)unaff_ESI);
            if (bVar4) {
              bVar4 = close_enough(&local_454->right,&unaff_EDI->right,(float)unaff_ESI);
              if (bVar4) goto LAB_4fc1eb5e;
            }
            local_494 = (float *)(piVar24 + -0xc);
            Matrix_Multiply(&local_3b8,unaff_EDI,unaff_ESI);
            (*local_438)(*piVar17,extraout_ECX);
            if (local_499 != false) {
              memset(local_48,0,0x40);
              memset(local_108,0,0x40);
              GetODFName((int)unaff_EDI,(char *)unaff_ESI);
              GetODFName((int)unaff_EDI,(char *)unaff_ESI);
              FormatLogMessage(
                              "Tap Not Matching Host: %08x %s! Current Tap: %08x \'%s\' Old Offset: %f %f %f New Offset: %f %f %f, Old Building Front: %f %f %f New Building Front: %f %f %f"
                              );
            }
            pMVar10 = local_2a8;
            __return_storage_ptr___00 = (Matrix *)*piVar17;
            (*local_470)();
            Matrix_Inverse(__return_storage_ptr___00,pMVar10);
            pMVar10 = Matrix_Multiply(__return_storage_ptr__,__return_storage_ptr___00,pMVar10);
            pfVar9 = local_494;
            for (iVar13 = 0x10; iVar13 != 0; iVar13 = iVar13 + -1) {
              *pfVar9 = (pMVar10->right).x;
              pMVar10 = (Matrix *)&(pMVar10->right).y;
              pfVar9 = pfVar9 + 1;
            }
            local_498[0x10e] = (int)local_3b8.front.x;
            local_498[0x10f] = (int)local_3b8.front.y;
            local_498[0x110] = (int)local_3b8.front.z;
            piVar7 = local_498;
            piVar24 = local_490;
          }
LAB_4fc1eb5e:
          iVar12 = iVar12 + 1;
          local_490 = piVar24 + 0x10;
          piVar18 = piVar17;
        } while (iVar12 < piVar7[0x9c]);
      }
      if (piVar7[0x90] == -0x20925446) {
        if (piVar7[0xa6] != 0) {
          iVar12 = 0;
          piVar18 = piVar7 + 0xbb;
          do {
            (*local_434)(*piVar7,iVar12 + 5,piVar18);
            piVar18 = piVar18 + 0x10;
            iVar12 = iVar12 + 1;
          } while (iVar12 < 5);
        }
        cVar5 = *(char *)((int)piVar7 + 0x23b);
        if (cVar5 != '\0') {
          if ((char)piVar7[0x8d] != '\0') {
            *(undefined1 *)((int)piVar7 + 0x23b) = 0;
            (*local_430)(*piVar7);
            cVar5 = *(char *)((int)piVar7 + 0x23b);
          }
          if (cVar5 != '\0') goto LAB_4fc1ec22;
        }
        if ((char)piVar7[0x8d] == '\0') {
          *(undefined1 *)((int)piVar7 + 0x23b) = 1;
          local_11c = 0;
          local_10c = 0;
          (*local_42c)(*piVar7,local_120,0x102);
          (*local_428)(*piVar7);
        }
      }
LAB_4fc1ec22:
      if ((*(char *)((int)piVar7 + 0x237) == '\0') && (piVar7[0xa1] != 0)) {
        iVar12 = (*local_424)(*piVar7);
        local_418 = iVar12;
        iVar13 = (*local_420)(*piVar7);
        local_450 = (double)CONCAT44(local_450._4_4_,iVar13);
        if ((((piVar7[0xa4] != 0) || (piVar7[0xa5] != 0)) &&
            ((iVar12 < piVar7[0xa4] || (iVar13 < piVar7[0xa5])))) ||
           ((piVar7[0x90] == -0x20925446 && (0 < piVar7[0xa6])))) {
          local_490 = (int *)0x0;
          local_488 = (float)piVar7[0xaa] * (float)piVar7[0xaa];
          if (0 < (*(int *)&(PowerupHelper::m_PowerupHelper->PowerupList).field_0x4 -
                  *(int *)&PowerupHelper::m_PowerupHelper->PowerupList) / 0x104) {
            local_494 = (float *)0x0;
            do {
              pfVar9 = local_494;
              piVar7 = local_498;
              piVar18 = (int *)(*(int *)&PowerupHelper::m_PowerupHelper->PowerupList +
                               (int)local_494);
              piVar24 = local_228;
              for (iVar12 = 0x41; iVar12 != 0; iVar12 = iVar12 + -1) {
                *piVar24 = *piVar18;
                piVar18 = piVar18 + 1;
                piVar24 = piVar24 + 1;
              }
              if (local_154 < 1) {
                local_468 = (double)CONCAT44(local_468._4_4_,ABS(local_12c));
                if (ABS(local_12c) < local_41c) {
                  bVar4 = false;
                  if ((local_498[0x90] == -0x20925446) && (local_218 != 0)) {
                    iVar12 = 0;
                    do {
                      fVar25 = GetCurLocalAmmo(*piVar7,iVar12);
                      local_468 = (double)fVar25;
                      fVar25 = GetMaxLocalAmmo(*piVar7,iVar12);
                      if ((float)local_468 < fVar25) {
                        bVar4 = true;
                        break;
                      }
                      iVar12 = iVar12 + 1;
                      bVar4 = false;
                    } while (iVar12 < 5);
                  }
                  if ((((((local_418 < piVar7[0xa4]) && (local_228[2] != 0)) ||
                        ((local_450._0_4_ < piVar7[0xa5] && (local_228[3] != 0)))) ||
                       (((piVar7[0x90] == -0x20925446 && (local_228[1] == 0x16164674)) || (bVar4))))
                      && ((((piVar7[0xa1] & 0x20U) != 0 &&
                           (((local_228[1] == -0x599d55a0 || (local_228[1] == 0x4b970310)) ||
                            (local_228[1] == 0x33fe0a68)))) ||
                          (((piVar7[0xa1] & 0x40U) != 0 && (local_228[1] == 0x16164674)))))) &&
                     ((local_150 & 4) != 0)) {
                    fVar25 = (local_144 - (float)piVar7[0x10d]) * (local_144 - (float)piVar7[0x10d])
                             + (local_14c - (float)piVar7[0x10b]) *
                               (local_14c - (float)piVar7[0x10b]);
                    local_468 = (double)CONCAT44(local_468._4_4_,fVar25);
                    if (fVar25 < local_488) {
                      if (local_228[1] == 0x16164674) {
                        iVar12 = 0;
                        do {
                          bVar6 = GiveWeapon(iVar12,(char *)unaff_EDI,(int)unaff_ESI);
                          if (bVar6) goto LAB_4fc1ee57;
                          iVar12 = iVar12 + 1;
                        } while (iVar12 < 5);
                      }
                      else {
LAB_4fc1ee57:
                        (*local_410)();
                        (*local_40c)(*piVar7,local_228[2]);
                        (*local_408)(*piVar7,local_228[3]);
                        if (local_499 != false) {
                          memset(local_c8,0,0x40);
                          GetODFName((int)unaff_EDI,(char *)unaff_ESI);
                          GetODFName(SUB84((double)local_14c,0));
                          FormatLogMessage(
                                          "POWERUP ACCEPTED: \'%s\' on Team %d at: %f %f %f w/ ColRad: %f Accepted Powerup: \'%s\' at: %f %f %f"
                                          );
                        }
                        pcVar16 = local_404;
                        if (bVar4) {
                          iVar12 = 0;
                          do {
                            (*pcVar16)(*piVar7,(float)local_218,iVar12);
                            iVar12 = iVar12 + 1;
                          } while (iVar12 < 5);
                          pfVar9 = local_494;
                        }
                        (*local_400)(local_228[0]);
                      }
                    }
                  }
                }
              }
              local_494 = pfVar9 + 0x41;
              local_490 = (int *)((int)local_490 + 1);
            } while ((int)local_490 <
                     (*(int *)&(PowerupHelper::m_PowerupHelper->PowerupList).field_0x4 -
                     *(int *)&PowerupHelper::m_PowerupHelper->PowerupList) / 0x104);
          }
        }
      }
      piVar18 = piVar7 + 0xa2;
      iVar13 = *piVar18 * 0xa14;
      iVar12 = (*local_3fc)(*piVar18);
      pBVar2 = local_478;
      if ((iVar12 == 0) && (*(char *)((int)local_478->teamInfo + iVar13 + 0x11d) != '\0')) {
        fVar25 = GetHealth(*piVar7);
        if (fVar25 < *(float *)((int)pBVar2->teamInfo + iVar13 + 0x13c)) {
          local_450 = (double)CONCAT44(local_450._4_4_,(float)BZ1Helper::m_GameTPS);
          _ftol2_sse();
          if (BZ1Helper::m_TurnCounter % extraout_EAX == 0) {
            fVar25 = local_3f8;
            fVar26 = GetRandomFloat(local_3f8);
            piVar7 = local_46c;
            this_00 = UtilityShipHelper::m_UtilityShipHelper;
            if (fVar26 < *(float *)((int)pBVar2->teamInfo + iVar13 + 0x134)) {
              local_498 = local_46c;
              if ((*(byte *)(local_46c + 0xa1) & 0x20) != 0) {
                fVar26 = local_3f4;
                bVar4 = IsProducer((int)local_3f4);
                iVar12 = UtilityShipHelper::FindServiceTruck
                                   (this_00,*piVar7,*piVar18,bVar4,fVar26,(int)fVar25);
                if (iVar12 == 0) {
                  if (*(int *)((int)local_478->teamInfo + iVar13 + 0x14) != 0) {
                    pcVar28 = (char *)0x40;
                    pcVar27 = local_88;
                    iVar12 = 0;
                    memset(pcVar27,0,0x40);
                    bVar4 = GetBuildItem((int)pcVar27,(char *)0x1,(int *)0x0,iVar12,pcVar28,
                                         (char *)unaff_EDI,(char *)unaff_ESI);
                    if (bVar4) {
                      iVar12 = *piVar18;
                      iVar11 = (*misnImport.GetScrap)(iVar12);
                      if (-1 < iVar11) {
                        BZ1Helper::BuildAt(local_478,
                                           *(int *)((int)local_478->teamInfo + iVar13 + 0x14),
                                           local_88,*(Vector *)(piVar7 + 0x10b),iVar12);
                        piVar7 = local_498;
                      }
                    }
                  }
                }
                else {
                  (*local_3f0)(iVar12,*piVar7,0);
                }
              }
              goto LAB_4fc1f114;
            }
          }
          piVar7 = local_46c;
        }
      }
LAB_4fc1f114:
      local_46c = piVar7 + 0x116;
      local_3e4 = *(int **)&(local_474->BuildingList).field_0x4;
    } while (local_46c != local_3e4);
  }
  return;
}


// ---------------------------------------------------------------------
// BuildingHelper::IsBuildingPowered  @ 4fc1f163  lines 768-779


bool __thiscall BuildingHelper::IsBuildingPowered(BuildingHelper *this,int param_1)

{
  bool bVar1;
  bool bVar2;
  int *piVar3;
  
  bVar1 = IsAround(param_1);
  bVar2 = false;
  if (bVar1) {
    for (piVar3 = *(int **)&this->BuildingList; piVar3 != *(int **)&(this->BuildingList).field_0x4;
        piVar3 = piVar3 + 0x116) {
      if (*piVar3 == param_1) {
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
  bool bVar2;
  int iVar3;
  int iVar4;
  Vector *unaff_ESI;
  int iVar5;
  Vector *unaff_EDI;
  int iVar6;
  float fVar7;
  
  iVar3 = (*(int *)&(this->BuildingList).field_0x4 - *(int *)&this->BuildingList) / 0x458 + -1;
  if (iVar3 < 0) {
    iVar3 = 0;
  }
  iVar4 = GetRandomInt((int)unaff_EDI,(int)unaff_ESI);
  iVar6 = iVar4;
  do {
    iVar5 = iVar6 * 0x458;
    iVar1 = *(int *)(iVar5 + *(int *)&this->BuildingList);
    if ((((param_1 < 0) ||
         (bVar2 = TeamFilterCheck(*(int *)(iVar5 + 0x28c + *(int *)&this->BuildingList),
                                  (int)unaff_EDI,(int)unaff_ESI), bVar2)) &&
        (0 < *(int *)(iVar5 + 0x290 + *(int *)&this->BuildingList))) &&
       ((*(char *)(iVar5 + 0x238 + *(int *)&this->BuildingList) != '\0' &&
        ((param_9 <= 0.0 ||
         (fVar7 = GetDistance3DSquared(unaff_EDI,unaff_ESI), fVar7 < param_9 * param_9)))))) {
      return iVar1;
    }
    iVar1 = iVar6 + 1;
    iVar6 = 0;
    if (iVar1 <= iVar3) {
      iVar6 = iVar1;
    }
  } while (iVar6 != iVar4);
  return 0;
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
  int unaff_ESI;
  int iVar3;
  int unaff_EDI;
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
        bVar1 = TeamFilterCheck(*(int *)(iVar2 + 0x288 + iVar3),unaff_EDI,unaff_ESI);
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
  Vector *unaff_ESI;
  int *piVar6;
  Vector *unaff_EDI;
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
    fVar8 = GetDistance3DSquared(unaff_EDI,unaff_ESI);
    if (fVar8 < local_118) {
      iVar4 = *piVar3;
      local_118 = fVar8;
    }
  }
  return iVar4;
}

