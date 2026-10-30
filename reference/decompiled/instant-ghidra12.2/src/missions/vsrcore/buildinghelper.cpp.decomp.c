// Reconstructed by Ghidra from Instant.dll + Instant.pdb
// Original source file: /e:/github/vsr_dll_source/missions/vsrcore/buildinghelper.cpp
// Functions are ordered by original source line. This is decompiler
// output, not the author's source: names/types come from the PDB,
// local variable names and control flow are reconstructed.


// ---------------------------------------------------------------------
// `dynamic_initializer_for_'TempBuildingBuffer''  @ 4fc01770  lines 10-10


void __cdecl _dynamic_initializer_for__TempBuildingBuffer__(void)

{
  atexit(_dynamic_atexit_destructor_for__TempBuildingBuffer__);
  return;
}


// ---------------------------------------------------------------------
// BuildingHelper::PostLoad  @ 4fc1d12c  lines 45-70


bool __thiscall BuildingHelper::PostLoad(BuildingHelper *this,bool param_1)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  BuildingClass *unaff_ESI;
  int *piVar5;
  BuildingClass *unaff_EDI;
  
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
  if ((int)(TempBuildingBuffer._4_4_ - TempBuildingBuffer._0_4_) / 0x458 == iVar4) {
    iVar3 = 0;
    if (0 < iVar4) {
      do {
        bVar1 = ::operator==(unaff_EDI,unaff_ESI);
        if (!bVar1) {
          FormatLogMessage("BuildingList Index Mismatch: %d");
          return true;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < (*(int *)&(this->BuildingList).field_0x4 - *(int *)&this->BuildingList) /
                       0x458);
    }
  }
  else {
    FormatLogMessage("BuildingList Size Mismatch! Old: %d New: %d");
  }
  return true;
}


// ---------------------------------------------------------------------
// BuildingHelper::AddBuildingObject  @ 4fc1d1e9  lines 88-321


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall
BuildingHelper::AddBuildingObject
          (BuildingHelper *this,int param_1,char *param_2,char *param_3,int param_4,int param_5,
          int param_6,int param_7,bool param_8,int param_9,bool param_10)

{
  vector<BuildingHelper::BuildingClass,std::allocator<BuildingHelper::BuildingClass>_> *pvVar1;
  bool bVar2;
  uint uVar3;
  long lVar4;
  Matrix *__return_storage_ptr__;
  Matrix *pMVar5;
  int iVar6;
  int *piVar7;
  Matrix *__return_storage_ptr___00;
  int iVar8;
  char *unaff_ESI;
  int *piVar9;
  bool *pbVar10;
  float *unaff_EDI;
  float *pfVar11;
  char cVar12;
  char *pcVar13;
  undefined1 uVar14;
  char (*pacVar15) [64];
  char *pcVar16;
  char *pcVar17;
  undefined1 uVar18;
  char *pcVar19;
  char *pcVar20;
  Matrix *pMVar21;
  int iVar22;
  bool *pbVar23;
  vector<BuildingHelper::BuildingClass,std::allocator<BuildingHelper::BuildingClass>_> *local_274;
  char *local_270;
  char local_26c;
  char local_26b;
  char local_26a;
  char local_269;
  char *local_268;
  float *local_264;
  bool *local_260;
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
  iVar8 = -1;
  piVar7 = *(int **)&this->BuildingList;
  local_270 = param_2;
  local_25c = GetTap_exref;
  local_260 = (bool *)param_1;
  local_268 = param_3;
  piVar9 = piVar7;
  while( true ) {
    local_274 = &this->BuildingList;
    if (piVar9 == *(int **)&(this->BuildingList).field_0x4) goto LAB_4fc1d257;
    if (*piVar9 == param_1) break;
    piVar9 = piVar9 + 0x116;
  }
  iVar8 = 0;
  iVar22 = 0;
  do {
    iVar6 = (*local_25c)(*piVar9,iVar22);
    memset(local_14c,0,0x40);
    GetObjInfo(iVar6,Get_ODF,local_14c);
    if (local_14c[0] != '\0') {
      iVar8 = iVar8 + 1;
    }
    iVar22 = iVar22 + 1;
  } while (iVar22 < 8);
  if (piVar9[0x9c] != iVar8) {
    piVar9[0x9c] = iVar8;
  }
  local_264 = (float *)iVar8;
  if (piVar9[0x90] == -0x20925446) {
    if (piVar9 == (int *)0xfffffd54) {
      uVar3 = 0;
    }
    else {
      uVar3 = Hash((char *)unaff_EDI,(uint)unaff_ESI);
    }
    if (param_5 == uVar3) {
      ReplaceWeapons(0,(char (*) [64])0x0,unaff_EDI,unaff_ESI);
    }
  }
  piVar7 = *(int **)local_274;
  iVar8 = ((int)piVar9 - (int)piVar7) / 0x458;
LAB_4fc1d257:
  pvVar1 = local_274;
  if (iVar8 < 0) {
    std::vector<BuildingHelper::BuildingClass,std::allocator<BuildingHelper::BuildingClass>_>::
    _Resize<<lambda_ec97c231cece026f40cdadd6cbe85fc1>_>
              (local_274,(*(int *)&local_274->field_0x4 - (int)piVar7) / 0x458 + 1,
               (<lambda_ec97c231cece026f40cdadd6cbe85fc1>)local_274);
    piVar7 = *(int **)pvVar1;
    iVar8 = (*(int *)&pvVar1->field_0x4 - (int)piVar7) / 0x458 + -1;
  }
  iVar22 = 0;
  piVar7 = piVar7 + iVar8 * 0x116;
  piVar9 = piVar7;
  memset(piVar7,0,0x458);
  GetODFInt("GameObjectClass","RequirePowerMask",(char *)(piVar7 + 0x92),(char *)0x0,piVar9,iVar22);
  uVar18 = 0x14;
  if (param_6 == -0x20925446) {
    pcVar16 = "TurretCraftClass";
    GetODFBool("TurretCraftClass","PoweredByTaps",(char *)((int)piVar7 + 0x23d),(char *)0x1,
               (bool *)unaff_EDI,SUB41(unaff_ESI,0));
    uVar14 = 100;
    pcVar13 = "TurretCraftClass";
    GetODFBool("TurretCraftClass","autoBuildTaps",(char *)((int)piVar7 + 0x23e),(char *)0x1,
               (bool *)pcVar16,(bool)uVar18);
    GetODFBool("TurretCraftClass","canDemolish",(char *)(piVar7 + 0x8f),(char *)0x1,(bool *)pcVar13,
               (bool)uVar14);
    piVar7[0xa6] = param_9;
  }
  else {
    pcVar16 = "PoweredBuildingClass";
    GetODFBool("PoweredBuildingClass","PoweredByTaps",(char *)((int)piVar7 + 0x23d),(char *)0x1,
               (bool *)unaff_EDI,SUB41(unaff_ESI,0));
    uVar14 = 100;
    pcVar13 = "PoweredBuildingClass";
    GetODFBool("PoweredBuildingClass","autoBuildTaps",(char *)((int)piVar7 + 0x23e),(char *)0x1,
               (bool *)pcVar16,(bool)uVar18);
    GetODFBool("BuildingClass","canDemolish",(char *)(piVar7 + 0x8f),(char *)0x1,(bool *)pcVar13,
               (bool)uVar14);
  }
  pcVar19 = "GameObjectClassPowerMask";
  pcVar17 = "GameObjectClass";
  GetODFInt("GameObjectClass","GameObjectClassPowerMask",(char *)(piVar7 + 0x9e),(char *)0x0,
            (int *)unaff_EDI,(int)unaff_ESI);
  pcVar16 = "GameObjectClassPowerMatch";
  pcVar13 = "GameObjectClass";
  GetODFInt("GameObjectClass","GameObjectClassPowerMatch",(char *)(piVar7 + 0x9f),(char *)0x0,
            (int *)pcVar17,(int)pcVar19);
  GetODFInt("GameObjectClass","GameObjectClassPowerProvides",(char *)(piVar7 + 0xa0),(char *)0x0,
            (int *)pcVar13,(int)pcVar16);
  local_274 = (vector<BuildingHelper::BuildingClass,std::allocator<BuildingHelper::BuildingClass>_>
               *)0x0;
  uVar18 = 0xd8;
  pcVar13 = "GameObjectClass";
  GetODFFloat("GameObjectClass","CollisionRadius",(char *)(piVar7 + 0xaa),(char *)0x0,unaff_EDI,
              (float)unaff_ESI);
  uVar14 = 0xe8;
  pcVar16 = "GameObjectClass";
  GetODFBool("GameObjectClass","CanCollide",(char *)((int)piVar7 + 0x237),(char *)0x0,
             (bool *)pcVar13,(bool)uVar18);
  uVar18 = 0xf4;
  pcVar13 = "GameObjectClass";
  GetODFBool("GameObjectClass","ownsTerrain",(char *)((int)piVar7 + 0x23f),(char *)0x1,
             (bool *)pcVar16,(bool)uVar14);
  local_26c = '\0';
  GetODFBool("GameObjectClass","CanAcceptPowerups",&local_26c,(char *)0x0,(bool *)pcVar13,
             (bool)uVar18);
  pcVar13 = (char *)((local_26c == '\0') - 1);
  piVar7[0xa1] = (int)pcVar13;
  pcVar20 = "AcceptPowerupMask";
  pcVar19 = "GameObjectClass";
  GetODFInt("GameObjectClass","AcceptPowerupMask",(char *)(piVar7 + 0xa1),pcVar13,(int *)unaff_EDI,
            (int)unaff_ESI);
  pcVar17 = "SizeRatioX";
  pcVar16 = "BuildingClass";
  GetODFInt("BuildingClass","SizeRatioX",(char *)(piVar7 + 0xa7),(char *)0x1,(int *)pcVar19,
            (int)pcVar20);
  cVar12 = '4';
  pcVar13 = "BuildingClass";
  GetODFInt("BuildingClass","SizeRatioZ",(char *)(piVar7 + 0xa8),(char *)0x1,(int *)pcVar16,
            (int)pcVar17);
  local_26b = '\0';
  GetODFChar("GameObjectClass","buildSupport",&local_26b,(char *)0x41,pcVar13,cVar12);
  pcVar13 = (char *)(int)local_26b;
  iVar8 = toupper((int)pcVar13);
  piVar7[0xa9] = iVar8;
  GetODFString("GameObjectClass","upgradeName",(char *)0x40,(char *)(piVar7 + 0xab),0,pcVar13,
               (char *)unaff_EDI);
  piVar7[0xa2] = param_4;
  if ((param_7 == -0x221bc770) ||
     (local_270 = (char *)((uint)local_270 & 0xffffff00), param_6 == -0x4e710e3d)) {
    local_270 = (char *)CONCAT31(local_270._1_3_,1);
  }
  GetODFBool("GameObjectClass","APCRefillPoint",(char *)((int)piVar7 + 0x239),local_270,
             (bool *)unaff_EDI,SUB41(unaff_ESI,0));
  pbVar10 = local_260;
  if ((((param_7 == -0x221bc770) && (bVar2 = IsBuilding((int)local_260), bVar2)) ||
      (param_6 == -0x7f06008f)) ||
     (local_270 = (char *)((uint)local_270 & 0xffffff00), param_6 == 0x490dd218)) {
    local_270 = (char *)CONCAT31(local_270._1_3_,1);
  }
  GetODFBool("GameObjectClass","RecyclePoint",(char *)((int)piVar7 + 0x23a),local_270,
             (bool *)unaff_EDI,SUB41(unaff_ESI,0));
  if (piVar7[0x90] == -0x25234de5) {
    GetODFFloat("SupplyDepotClass","healthRate",(char *)(piVar7 + 0x111),(char *)local_274,unaff_EDI
                ,(float)unaff_ESI);
    GetODFFloat("SupplyDepotClass","ammoRate",(char *)(piVar7 + 0x112),(char *)local_274,unaff_EDI,
                (float)unaff_ESI);
    GetODFFloat("SupplyDepotClass","localAmmoRate",(char *)(piVar7 + 0x113),(char *)local_274,
                unaff_EDI,(float)unaff_ESI);
    uVar18 = 0xb8;
    pcVar13 = "SupplyDepotClass";
    GetODFFloat("SupplyDepotClass","supplyRate",(char *)(piVar7 + 0x114),(char *)local_274,unaff_EDI
                ,(float)unaff_ESI);
    GetODFBool("SupplyDepotClass","serviceCraft",(char *)(piVar7 + 0x115),(char *)0x1,
               (bool *)pcVar13,(bool)uVar18);
  }
  pbVar23 = pbVar10;
  lVar4 = GetMaxHealth((int)pbVar10);
  uVar18 = SUB41(pbVar23,0);
  piVar7[0xa4] = lVar4;
  pbVar23 = pbVar10;
  lVar4 = GetMaxAmmo((int)pbVar10);
  piVar7[0xa5] = lVar4;
  *(bool *)(piVar7 + 0x8e) = param_8;
  local_26a = '\x01';
  GetODFBool("GameObjectClass","IsAnimated",&local_26a,(char *)0x1,pbVar23,(bool)uVar18);
  if (local_26a != '\0') {
    piVar9 = (int *)local_10c;
    iVar8 = 0;
    memset(piVar9,0,0x40);
    local_268 = (char *)0x0;
    GetODFInt("GameObjectClass","animCount",(char *)&local_268,(char *)0x0,piVar9,iVar8);
    local_274 = (vector<BuildingHelper::BuildingClass,std::allocator<BuildingHelper::BuildingClass>_>
                 *)0x1;
    if (1 < (int)(local_268 + 1)) {
      do {
        memset(local_14c,0,0x40);
        pacVar15 = &local_14c;
        pcVar13 = "animName%d";
        sprintf_s<64>(pacVar15,"animName%d");
        iVar8 = GetODFString("GameObjectClass",local_14c,(char *)0x40,local_10c,0,*pacVar15,pcVar13)
        ;
        if ((iVar8 != 0) && (iVar8 = _stricmp(local_10c,"BZCloop"), iVar8 == 0)) {
          *(undefined1 *)((int)piVar7 + 0x235) = 1;
          break;
        }
        local_274 = (vector<BuildingHelper::BuildingClass,std::allocator<BuildingHelper::BuildingClass>_>
                     *)&local_274->field_0x1;
      } while ((int)local_274 < (int)(local_268 + 1));
    }
  }
  GetPosition((int)pbVar10,local_24c);
  iVar8 = 0;
  local_270 = (char *)0x0;
  local_264 = (float *)(piVar7 + 0xd);
  local_274 = (vector<BuildingHelper::BuildingClass,std::allocator<BuildingHelper::BuildingClass>_>
               *)(piVar7 + 1);
  do {
    __return_storage_ptr__ = (Matrix *)(*local_25c)(pbVar10,iVar8);
    if (__return_storage_ptr__ != (Matrix *)0x0) {
      memset(local_10c,0,0x40);
      memset(local_cc,0,0x40);
      pcVar13 = local_14c;
      pcVar16 = (char *)0x0;
      memset(pcVar13,0,0x40);
      GetAndOpenODFNames((int)local_14c,local_10c,pcVar13,pcVar16);
      if (local_10c[0] != '\0') {
        local_270 = (char *)((int)local_270 + 1);
        *(Matrix **)local_274 = __return_storage_ptr__;
        pMVar5 = local_1cc;
        GetPosition((int)__return_storage_ptr__,pMVar5);
        Matrix_Inverse(__return_storage_ptr__,pMVar5);
        pMVar21 = __return_storage_ptr___00;
        pMVar5 = Matrix_Multiply(__return_storage_ptr___00,__return_storage_ptr__,pMVar5);
        pfVar11 = local_264;
        for (iVar22 = 0x10; iVar22 != 0; iVar22 = iVar22 + -1) {
          *pfVar11 = (pMVar5->right).x;
          pMVar5 = (Matrix *)&(pMVar5->right).y;
          pfVar11 = pfVar11 + 1;
        }
        local_269 = '\x01';
        GetODFBool("GameObjectClass","IsAnimated",&local_269,(char *)0x1,(bool *)pMVar21,
                   SUB41(__return_storage_ptr__,0));
        if (local_269 != '\0') {
          piVar9 = local_4c;
          iVar22 = 0;
          memset(piVar9,0,0x40);
          local_268 = (char *)0x0;
          GetODFInt("GameObjectClass","animCount",(char *)&local_268,(char *)0x0,piVar9,iVar22);
          iVar22 = 1;
          if (1 < (int)(local_268 + 1)) {
            do {
              memset(local_8c,0,0x40);
              pacVar15 = &local_8c;
              pcVar13 = "animName%d";
              sprintf_s<64>(pacVar15,"animName%d");
              iVar6 = GetODFString("GameObjectClass",local_8c,(char *)0x40,(char *)local_4c,0,
                                   *pacVar15,pcVar13);
              if ((iVar6 != 0) && (iVar6 = _stricmp((char *)local_4c,"BZCloop"), iVar6 == 0)) {
                *(undefined1 *)((int)piVar7 + iVar8 + 0x24) = 1;
                break;
              }
              iVar22 = iVar22 + 1;
            } while (iVar22 < (int)(local_268 + 1));
          }
        }
        pbVar10 = local_260;
      }
    }
    local_274 = (vector<BuildingHelper::BuildingClass,std::allocator<BuildingHelper::BuildingClass>_>
                 *)&local_274->field_0x4;
    iVar8 = iVar8 + 1;
    local_264 = local_264 + 0x10;
    if (7 < iVar8) {
      piVar7[0x9d] = -1;
      piVar7[0x9c] = (int)local_270;
      piVar7[0x90] = param_6;
      piVar7[0x91] = param_5;
      *piVar7 = (int)pbVar10;
      GetPosition((int)pbVar10,&local_258);
      piVar7[0x10b] = (int)local_258.x;
      piVar7[0x10c] = (int)local_258.y;
      piVar7[0x10d] = (int)local_258.z;
      piVar7[0x10e] = (int)local_24c[0].front.x;
      piVar7[0x10f] = (int)local_24c[0].front.y;
      piVar7[0x110] = (int)local_24c[0].front.z;
      return;
    }
  } while( true );
}


// ---------------------------------------------------------------------
// BuildingHelper::Execute  @ 4fc1daa7  lines 324-765


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall BuildingHelper::Execute(BuildingHelper *this,BZ1Helper *param_1)

{
  AlignTerrainReplaceClass *pAVar1;
  uint uVar2;
  UtilityShipHelper *this_00;
  BZ1Helper *this_01;
  bool bVar3;
  char cVar4;
  bool bVar5;
  int *piVar6;
  undefined4 uVar7;
  float *pfVar8;
  Matrix *pMVar9;
  int extraout_EAX;
  int iVar10;
  int iVar11;
  int iVar12;
  undefined4 extraout_ECX;
  Matrix *__return_storage_ptr__;
  AlignTerrainReplaceClass *pAVar13;
  PowerHelper *pPVar14;
  code *pcVar15;
  int *piVar16;
  int *piVar17;
  Matrix *unaff_ESI;
  AlignTerrainReplaceClass *pAVar18;
  size_t sVar19;
  Matrix *unaff_EDI;
  AlignTerrainReplaceClass *pAVar20;
  float *pfVar21;
  code *pcVar22;
  int *piVar23;
  float fVar24;
  float fVar25;
  char *pcVar26;
  Matrix *__return_storage_ptr___00;
  char *pcVar27;
  undefined1 auStack_490 [7];
  bool local_489;
  int *local_488;
  int *local_484;
  float *local_480;
  char local_479;
  float local_478;
  code *local_474;
  AlignTerrainReplaceClass *local_470;
  code *local_46c;
  double local_468;
  code *local_45c;
  code *local_458;
  Matrix *local_454;
  BuildingHelper *local_450;
  code *local_44c;
  double local_448;
  code *local_440;
  code *local_43c;
  code *local_438;
  code *local_434;
  code *local_430;
  code *local_42c;
  code *local_428;
  code *local_424;
  code *local_420;
  code *local_41c;
  code *local_418;
  float local_414;
  int local_410;
  code *local_40c;
  code *local_408;
  code *local_404;
  code *local_400;
  code *local_3fc;
  code *local_3f8;
  code *local_3f4;
  BZ1Helper *local_3f0;
  float local_3ec;
  float local_3e8;
  code *local_3e4;
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
  
  local_4 = __security_cookie ^ (uint)auStack_490;
  local_3f0 = param_1;
  local_489 = BZ1Helper::Logging;
  pAVar1 = *(AlignTerrainReplaceClass **)&(this->BuildingList).field_0x4;
  pAVar13 = *(AlignTerrainReplaceClass **)&this->BuildingList;
  local_450 = this;
  while ((pAVar13 != pAVar1 && (bVar3 = BZ1Helper::ShouldRemoveAlignTerrainReplace(pAVar13), !bVar3)
         )) {
    pAVar13 = (AlignTerrainReplaceClass *)&pAVar13[0x45].NormalVec.y;
  }
  if (pAVar13 != pAVar1) {
    local_470 = (AlignTerrainReplaceClass *)&pAVar13[0x45].NormalVec.y;
    if (local_470 != pAVar1) {
      do {
        pAVar18 = local_470;
        bVar3 = BZ1Helper::ShouldRemoveAlignTerrainReplace(local_470);
        if (!bVar3) {
          pAVar20 = pAVar13;
          for (iVar11 = 0x116; iVar11 != 0; iVar11 = iVar11 + -1) {
            pAVar20->AlignHandle = pAVar18->AlignHandle;
            pAVar18 = (AlignTerrainReplaceClass *)&pAVar18->NormalVec;
            pAVar20 = (AlignTerrainReplaceClass *)&pAVar20->NormalVec;
          }
          pAVar13 = (AlignTerrainReplaceClass *)&pAVar13[0x45].NormalVec.y;
          pAVar18 = local_470;
        }
        local_470 = (AlignTerrainReplaceClass *)&pAVar18[0x45].NormalVec.y;
      } while (local_470 != pAVar1);
      this = local_450;
    }
    if (pAVar13 != pAVar1) {
      sVar19 = *(int *)&(this->BuildingList).field_0x4 - (int)pAVar1;
      memmove(pAVar13,pAVar1,sVar19);
      piVar6 = (int *)(sVar19 + (int)pAVar13);
      *(int **)&(this->BuildingList).field_0x4 = piVar6;
      goto LAB_4fc1db59;
    }
  }
  piVar6 = *(int **)&(this->BuildingList).field_0x4;
LAB_4fc1db59:
  local_488 = *(int **)&this->BuildingList;
  if (local_488 != piVar6) {
    local_45c = GetPerceivedTeam_exref;
    local_40c = IsTeamAllied_exref;
    local_440 = GetPower_exref;
    local_458 = ResumeAnimation_exref;
    local_43c = IsAround_exref;
    local_438 = SetTeamNum_exref;
    local_434 = SetPerceivedTeam_exref;
    local_430 = SetPosition_exref;
    local_42c = GetObjInfo_exref;
    local_428 = AddPilotByHandle_exref;
    local_424 = SetControls_exref;
    local_420 = RemovePilotAI_exref;
    local_41c = GetCurHealth_exref;
    local_418 = GetCurAmmo_exref;
    local_454 = ___real_3c23d70a;
    local_408 = StartAudio3D_exref;
    local_404 = AddHealth_exref;
    local_3e8 = 0.0;
    local_400 = AddAmmo_exref;
    local_3fc = AddLocalAmmo_exref;
    local_414 = __real_3f000000;
    local_3f8 = RemoveObject_exref;
    local_3f4 = GetPlayerHandle_exref;
    local_3ec = 1.0;
    local_44c = GetTeamNum_exref;
    local_474 = GetAnimationDirection_exref;
    local_46c = PauseAnimation_exref;
    local_3e4 = Service_exref;
    local_470 = (AlignTerrainReplaceClass *)GetPosition_exref;
    do {
      pcVar22 = local_46c;
      pAVar1 = local_470;
      pcVar15 = local_474;
      piVar6 = local_488;
      iVar11 = (*local_44c)(*local_488);
      piVar6[0xa2] = iVar11;
      (*(code *)pAVar1)(*piVar6,&local_3b8);
      uVar7 = (*local_45c)(*piVar6);
      local_468 = (double)CONCAT44(local_468._4_4_,uVar7);
      local_484 = (int *)0x0;
      iVar11 = 0;
      if (piVar6[0x9c] != 0) {
        local_484 = (int *)GetTapCount(piVar6[0x9c],SUB41(unaff_EDI,0),SUB41(unaff_ESI,0));
        iVar11 = piVar6[0x9c];
      }
      if ((*(char *)((int)piVar6 + 0x23e) == '\0') && (iVar11 < (int)local_484)) {
        piVar6[0x9c] = (int)local_484;
      }
      bVar3 = piVar6[0x9d] != 0;
      if (piVar6[0x9d] < 0) {
        cVar4 = '\0';
        local_479 = '\0';
        if ((*(byte *)(piVar6 + 0x92) & 1) != 0) {
          local_478 = 0.0;
          if (0 < (*(int *)&(PowerHelper::m_PowerHelper->PowerList).field_0x4 -
                  *(int *)&PowerHelper::m_PowerHelper->PowerList) / 0x28) {
            iVar11 = 0;
            pPVar14 = PowerHelper::m_PowerHelper;
            do {
              piVar6 = local_488;
              pfVar8 = (float *)(*(int *)&pPVar14->PowerList + iVar11);
              pfVar21 = local_3e0;
              for (iVar12 = 10; iVar12 != 0; iVar12 = iVar12 + -1) {
                *pfVar21 = *pfVar8;
                pfVar8 = pfVar8 + 1;
                pfVar21 = pfVar21 + 1;
              }
              if ((char)((uint)local_3e0[1] >> 0x10) != '\0') {
                cVar4 = (*local_40c)(local_488[0xa2],local_3e0[2]);
                if (((cVar4 != '\0') && ((piVar6[0x9e] & local_3c8) == piVar6[0x9f])) &&
                   ((piVar6[0xa0] & local_3d0) == local_3cc)) {
                  local_448 = (double)local_3e0[3];
                  fVar24 = GetDistance3DSquared(&unaff_EDI->right,&unaff_ESI->right);
                  local_480 = (float *)(float)((float10)local_448 * (float10)local_448);
                  if (fVar24 < (float)local_480) {
                    cVar4 = '\x01';
                    goto LAB_4fc1ddf3;
                  }
                }
                pPVar14 = PowerHelper::m_PowerHelper;
              }
              iVar11 = iVar11 + 0x28;
              local_478 = (float)((int)local_478 + 1);
            } while ((int)local_478 <
                     (*(int *)&(pPVar14->PowerList).field_0x4 - *(int *)&pPVar14->PowerList) / 0x28)
            ;
            cVar4 = local_479;
LAB_4fc1ddf3:
            pcVar22 = local_46c;
          }
          pcVar15 = local_474;
        }
        uVar2 = piVar6[0x92];
        if ((((uVar2 == 0) || (((uVar2 & 1) != 0 && (cVar4 != '\0')))) ||
            (((uVar2 & 2) != 0 && (iVar11 = (*local_440)(piVar6[0xa2]), -1 < iVar11)))) ||
           (((*(byte *)(piVar6 + 0x92) & 4) != 0 &&
            ((*(char *)((int)piVar6 + 0x23d) == '\0' || (local_484 == (int *)piVar6[0x9c])))))) {
          bVar3 = true;
        }
        else {
          bVar3 = false;
        }
      }
      *(bool *)(piVar6 + 0x8d) = bVar3;
      if (*(char *)((int)piVar6 + 0x235) != '\0') {
        iVar11 = (*pcVar15)(*piVar6);
        bVar3 = iVar11 != 0;
        *(bool *)((int)piVar6 + 0x236) = bVar3;
        if ((char)piVar6[0x8d] == '\0') {
          if (bVar3) {
            iVar11 = (*pcVar22)(*piVar6);
LAB_4fc1de9b:
            piVar6[0x93] = iVar11;
          }
        }
        else if (!bVar3) {
          if (piVar6[0x93] == 0) {
            iVar11 = (*pcVar15)(*piVar6);
            goto LAB_4fc1de9b;
          }
          (*local_458)(*piVar6,piVar6[0x93]);
        }
      }
      iVar11 = 0;
      if (0 < piVar6[0x9c]) {
        local_484 = piVar6 + 0x19;
        piVar17 = piVar6;
        do {
          piVar23 = local_484;
          piVar16 = piVar17 + 1;
          cVar4 = (*local_43c)(*piVar16);
          if (cVar4 != '\0') {
            (*(code *)local_470)(*piVar16,local_368);
            local_480 = (float *)piVar6[0xa2];
            pfVar8 = (float *)(*local_44c)(*piVar16);
            if (local_480 != pfVar8) {
              (*local_438)(*piVar16,local_480);
            }
            iVar12 = (*local_45c)(*piVar16);
            if (iVar12 != local_468._0_4_) {
              (*local_434)(*piVar16,local_468._0_4_);
            }
            if (*(char *)((int)piVar6 + iVar11 + 0x24) != '\0') {
              iVar12 = (*local_474)(*piVar16);
              bVar3 = iVar12 != 0;
              *(bool *)((int)piVar6 + iVar11 + 0x2c) = bVar3;
              if ((char)piVar6[0x8d] == '\0') {
                if (bVar3) {
                  iVar12 = (*local_46c)(*piVar16);
                  piVar17[0x94] = iVar12;
                  *(undefined1 *)((int)piVar6 + iVar11 + 0x2c) = 0;
                }
              }
              else if (!bVar3) {
                if (piVar17[0x94] == 0) {
                  iVar12 = (*local_474)(*piVar16);
                  piVar17[0x94] = iVar12;
                }
                else {
                  (*local_458)(*piVar16,piVar17[0x94]);
                  *(undefined1 *)((int)piVar6 + iVar11 + 0x2c) = 1;
                }
              }
            }
            pMVar9 = local_454;
            Vector_TransformInv(local_338,local_454,&unaff_EDI->right);
            bVar3 = close_enough(&pMVar9->right,&unaff_EDI->right,(float)unaff_ESI);
            if (bVar3) {
              bVar3 = close_enough(&local_454->right,&unaff_EDI->right,(float)unaff_ESI);
              if (bVar3) goto LAB_4fc1e150;
            }
            local_480 = (float *)(piVar23 + -0xc);
            Matrix_Multiply(&local_3b8,unaff_EDI,unaff_ESI);
            (*local_430)(*piVar16,extraout_ECX);
            if (local_489 != false) {
              memset(local_c8,0,0x40);
              memset(local_108,0,0x40);
              GetODFName((int)unaff_EDI,(char *)unaff_ESI);
              GetODFName((int)unaff_EDI,(char *)unaff_ESI);
              FormatLogMessage(
                              "Tap Not Matching Host: %08x %s! Current Tap: %08x \'%s\' Old Offset: %f %f %f New Offset: %f %f %f, Old Building Front: %f %f %f New Building Front: %f %f %f"
                              );
            }
            pMVar9 = local_2a8;
            __return_storage_ptr___00 = (Matrix *)*piVar16;
            (*(code *)local_470)();
            Matrix_Inverse(__return_storage_ptr___00,pMVar9);
            pMVar9 = Matrix_Multiply(__return_storage_ptr__,__return_storage_ptr___00,pMVar9);
            pfVar8 = local_480;
            for (iVar12 = 0x10; iVar12 != 0; iVar12 = iVar12 + -1) {
              *pfVar8 = (pMVar9->right).x;
              pMVar9 = (Matrix *)&(pMVar9->right).y;
              pfVar8 = pfVar8 + 1;
            }
            local_488[0x10e] = (int)local_3b8.front.x;
            local_488[0x10f] = (int)local_3b8.front.y;
            local_488[0x110] = (int)local_3b8.front.z;
            piVar6 = local_488;
            piVar23 = local_484;
          }
LAB_4fc1e150:
          iVar11 = iVar11 + 1;
          local_484 = piVar23 + 0x10;
          piVar17 = piVar16;
        } while (iVar11 < piVar6[0x9c]);
      }
      if (piVar6[0x90] == -0x20925446) {
        if (piVar6[0xa6] != 0) {
          iVar11 = 0;
          piVar17 = piVar6 + 0xbb;
          do {
            (*local_42c)(*piVar6,iVar11 + 5,piVar17);
            piVar17 = piVar17 + 0x10;
            iVar11 = iVar11 + 1;
          } while (iVar11 < 5);
        }
        cVar4 = *(char *)((int)piVar6 + 0x23b);
        if (cVar4 != '\0') {
          if ((char)piVar6[0x8d] != '\0') {
            *(undefined1 *)((int)piVar6 + 0x23b) = 0;
            (*local_428)(*piVar6);
            cVar4 = *(char *)((int)piVar6 + 0x23b);
          }
          if (cVar4 != '\0') goto LAB_4fc1e211;
        }
        if ((char)piVar6[0x8d] == '\0') {
          local_11c = 0;
          *(undefined1 *)((int)piVar6 + 0x23b) = 1;
          local_10c = 0;
          (*local_424)(*piVar6,local_120,0x102);
          (*local_420)(*piVar6);
        }
      }
LAB_4fc1e211:
      if ((*(char *)((int)piVar6 + 0x237) == '\0') && (piVar6[0xa1] != 0)) {
        iVar11 = (*local_41c)(*piVar6);
        local_410 = iVar11;
        iVar12 = (*local_418)(*piVar6);
        local_448 = (double)CONCAT44(local_448._4_4_,iVar12);
        if ((((piVar6[0xa4] != 0) || (piVar6[0xa5] != 0)) &&
            ((iVar11 < piVar6[0xa4] || (iVar12 < piVar6[0xa5])))) ||
           ((piVar6[0x90] == -0x20925446 && (0 < piVar6[0xa6])))) {
          local_484 = (int *)0x0;
          local_478 = (float)piVar6[0xaa] * (float)piVar6[0xaa];
          if (0 < (*(int *)&(PowerupHelper::m_PowerupHelper->PowerupList).field_0x4 -
                  *(int *)&PowerupHelper::m_PowerupHelper->PowerupList) / 0x104) {
            local_480 = (float *)0x0;
            do {
              pfVar8 = local_480;
              piVar6 = local_488;
              piVar17 = (int *)(*(int *)&PowerupHelper::m_PowerupHelper->PowerupList +
                               (int)local_480);
              piVar23 = local_228;
              for (iVar11 = 0x41; iVar11 != 0; iVar11 = iVar11 + -1) {
                *piVar23 = *piVar17;
                piVar17 = piVar17 + 1;
                piVar23 = piVar23 + 1;
              }
              if (local_154 < 1) {
                local_468 = (double)CONCAT44(local_468._4_4_,ABS(local_12c));
                if (ABS(local_12c) < local_414) {
                  bVar3 = false;
                  if ((local_488[0x90] == -0x20925446) && (local_218 != 0)) {
                    iVar11 = 0;
                    do {
                      fVar24 = GetCurLocalAmmo(*piVar6,iVar11);
                      local_468 = (double)fVar24;
                      fVar24 = GetMaxLocalAmmo(*piVar6,iVar11);
                      if ((float)local_468 < fVar24) {
                        bVar3 = true;
                        break;
                      }
                      iVar11 = iVar11 + 1;
                      bVar3 = false;
                    } while (iVar11 < 5);
                  }
                  if ((((((local_410 < piVar6[0xa4]) && (local_228[2] != 0)) ||
                        ((local_448._0_4_ < piVar6[0xa5] && (local_228[3] != 0)))) ||
                       (((piVar6[0x90] == -0x20925446 && (local_228[1] == 0x16164674)) || (bVar3))))
                      && ((((piVar6[0xa1] & 0x20U) != 0 &&
                           (((local_228[1] == -0x599d55a0 || (local_228[1] == 0x4b970310)) ||
                            (local_228[1] == 0x33fe0a68)))) ||
                          (((piVar6[0xa1] & 0x40U) != 0 && (local_228[1] == 0x16164674)))))) &&
                     ((local_150 & 4) != 0)) {
                    fVar24 = (local_144 - (float)piVar6[0x10d]) * (local_144 - (float)piVar6[0x10d])
                             + (local_14c - (float)piVar6[0x10b]) *
                               (local_14c - (float)piVar6[0x10b]);
                    local_468 = (double)CONCAT44(local_468._4_4_,fVar24);
                    if (fVar24 < local_478) {
                      if (local_228[1] == 0x16164674) {
                        iVar11 = 0;
                        do {
                          bVar5 = GiveWeapon(iVar11,(char *)unaff_EDI,(int)unaff_ESI);
                          if (bVar5) goto LAB_4fc1e446;
                          iVar11 = iVar11 + 1;
                        } while (iVar11 < 5);
                      }
                      else {
LAB_4fc1e446:
                        (*local_408)();
                        (*local_404)(*piVar6,local_228[2]);
                        (*local_400)(*piVar6,local_228[3]);
                        if (local_489 != false) {
                          memset(local_48,0,0x40);
                          GetODFName((int)unaff_EDI,(char *)unaff_ESI);
                          GetODFName(SUB84((double)local_14c,0));
                          FormatLogMessage(
                                          "POWERUP ACCEPTED: \'%s\' on Team %d at: %f %f %f w/ ColRad: %f Accepted Powerup: \'%s\' at: %f %f %f"
                                          );
                        }
                        pcVar15 = local_3fc;
                        if (bVar3) {
                          iVar11 = 0;
                          do {
                            (*pcVar15)(*piVar6,(float)local_218,iVar11);
                            iVar11 = iVar11 + 1;
                          } while (iVar11 < 5);
                          pfVar8 = local_480;
                        }
                        (*local_3f8)(local_228[0]);
                      }
                    }
                  }
                }
              }
              local_480 = pfVar8 + 0x41;
              local_484 = (int *)((int)local_484 + 1);
            } while ((int)local_484 <
                     (*(int *)&(PowerupHelper::m_PowerupHelper->PowerupList).field_0x4 -
                     *(int *)&PowerupHelper::m_PowerupHelper->PowerupList) / 0x104);
          }
        }
      }
      iVar12 = piVar6[0xa2] * 0xa14;
      iVar11 = (*local_3f4)(piVar6[0xa2]);
      this_01 = local_3f0;
      if ((iVar11 == 0) && (*(char *)((int)local_3f0->teamInfo + iVar12 + 0x11d) != '\0')) {
        fVar24 = GetHealth(*piVar6);
        if (fVar24 < *(float *)((int)this_01->teamInfo + iVar12 + 0x13c)) {
          local_448 = (double)CONCAT44(local_448._4_4_,(float)BZ1Helper::m_GameTPS);
          _ftol2_sse();
          if (BZ1Helper::m_TurnCounter % extraout_EAX == 0) {
            fVar24 = local_3ec;
            fVar25 = GetRandomFloat(local_3ec);
            this_00 = UtilityShipHelper::m_UtilityShipHelper;
            if ((fVar25 < *(float *)((int)this_01->teamInfo + iVar12 + 0x134)) &&
               ((*(byte *)(piVar6 + 0xa1) & 0x20) != 0)) {
              fVar25 = local_3e8;
              bVar3 = IsProducer((int)local_3e8);
              iVar11 = UtilityShipHelper::FindServiceTruck
                                 (this_00,*piVar6,piVar6[0xa2],bVar3,fVar25,(int)fVar24);
              if (iVar11 == 0) {
                if (*(int *)((int)this_01->teamInfo + iVar12 + 0x14) != 0) {
                  pcVar27 = (char *)0x40;
                  pcVar26 = local_88;
                  iVar11 = 0;
                  memset(pcVar26,0,0x40);
                  bVar3 = GetBuildItem((int)pcVar26,(char *)0x1,(int *)0x0,iVar11,pcVar27,
                                       (char *)unaff_EDI,(char *)unaff_ESI);
                  if (bVar3) {
                    iVar11 = piVar6[0xa2];
                    iVar10 = (*misnImport.GetScrap)(iVar11);
                    if (-1 < iVar10) {
                      BZ1Helper::BuildAt(this_01,*(int *)((int)this_01->teamInfo + iVar12 + 0x14),
                                         local_88,*(Vector *)(piVar6 + 0x10b),iVar11);
                      piVar6 = local_488;
                    }
                  }
                }
              }
              else {
                (*local_3e4)(iVar11,*piVar6,0);
              }
            }
          }
        }
      }
      local_488 = piVar6 + 0x116;
    } while (local_488 != *(int **)&(local_450->BuildingList).field_0x4);
  }
  return;
}


// ---------------------------------------------------------------------
// BuildingHelper::IsBuildingPowered  @ 4fc1e735  lines 768-779


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
// BuildingHelper::GetRandomBuilding  @ 4fc1e76a  lines 798-841


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
// BuildingHelper::GetNumBuildings  @ 4fc1e83a  lines 845-878


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
LAB_4fc1e88a:
        if (0 < *(int *)(iVar2 + 0x290 + iVar3)) {
          iVar4 = iVar4 + 1;
        }
      }
      else {
        bVar1 = TeamFilterCheck(*(int *)(iVar2 + 0x288 + iVar3),unaff_EDI,unaff_ESI);
        if (bVar1) {
          iVar3 = *(int *)&this->BuildingList;
          goto LAB_4fc1e88a;
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
// BuildingHelper::GetNearestServiceObject  @ 4fc1e8bd  lines 946-1020


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

