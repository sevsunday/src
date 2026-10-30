// Reconstructed by Ghidra from Instant.dll + Instant.pdb
// Original source file: /e:/github/vsr_dll_source/missions/vsrcore/carrierhelper.cpp
// Functions are ordered by original source line. This is decompiler
// output, not the author's source: names/types come from the PDB,
// local variable names and control flow are reconstructed.


// ---------------------------------------------------------------------
// `dynamic_initializer_for_'TempCarrierBuffer''  @ 4fc0157c  lines 8-8


void __cdecl _dynamic_initializer_for__TempCarrierBuffer__(void)

{
  atexit(_dynamic_atexit_destructor_for__TempCarrierBuffer__);
  return;
}


// ---------------------------------------------------------------------
// `dynamic_initializer_for_'TempDroneBuffer''  @ 4fc01588  lines 9-9


void __cdecl _dynamic_initializer_for__TempDroneBuffer__(void)

{
  atexit(_dynamic_atexit_destructor_for__TempDroneBuffer__);
  return;
}


// ---------------------------------------------------------------------
// CarrierHelper::~CarrierHelper  @ 4fc17431  lines 16-17


void __thiscall CarrierHelper::~CarrierHelper(CarrierHelper *this)

{
  this->_padding_ = (int)_vftable_;
  std::
  vector<UtilityShipHelper::UtilityShipClass,std::allocator<UtilityShipHelper::UtilityShipClass>_>::
  _Tidy((vector<UtilityShipHelper::UtilityShipClass,std::allocator<UtilityShipHelper::UtilityShipClass>_>
         *)&this->DroneList);
  std::vector<CarrierHelper::CarrierClass,std::allocator<CarrierHelper::CarrierClass>_>::_Tidy
            (&this->CarrierList);
  return;
}


// ---------------------------------------------------------------------
// CarrierHelper::Load  @ 4fc1744b  lines 20-44


bool __thiscall CarrierHelper::Load(CarrierHelper *this,bool param_1)

{
  vector<CarrierHelper::CarrierClass,std::allocator<CarrierHelper::CarrierClass>_> *this_00;
  bool bVar1;
  CarrierHelper *extraout_ECX;
  CarrierHelper *this_01;
  vector<CarrierHelper::DroneClass,std::allocator<CarrierHelper::DroneClass>_> *this_02;
  CarrierHelper *local_8;
  
  this_00 = &this->CarrierList;
  this_01 = this;
  local_8 = this;
  if (this_00 != &TempCarrierBuffer) {
    std::vector<CarrierHelper::CarrierClass,std::allocator<CarrierHelper::CarrierClass>_>::
    _Assign_range<CarrierHelper::CarrierClass_*>
              ((vector<CarrierHelper::CarrierClass,std::allocator<CarrierHelper::CarrierClass>_> *)
               this,*(CarrierClass **)this_00,*(CarrierClass **)&(this->CarrierList).field_0x4,
               SUB41(this,0));
    this_01 = extraout_ECX;
  }
  this_02 = &this->DroneList;
  if (this_02 != &TempDroneBuffer) {
    std::vector<CarrierHelper::DroneClass,std::allocator<CarrierHelper::DroneClass>_>::
    _Assign_range<CarrierHelper::DroneClass_*>
              ((vector<CarrierHelper::DroneClass,std::allocator<CarrierHelper::DroneClass>_> *)
               this_01,*(DroneClass **)this_02,*(DroneClass **)&(this->DroneList).field_0x4,
               SUB41(local_8,0));
  }
  local_8 = (CarrierHelper *)0x0;
  bVar1 = Read((int *)&local_8,1);
  std::vector<CarrierHelper::CarrierClass,std::allocator<CarrierHelper::CarrierClass>_>::
  _Resize<<lambda_87c6343aa49b10f10e6fc064335a8cab>_>
            (this_00,(uint)local_8,(<lambda_87c6343aa49b10f10e6fc064335a8cab>)this_00);
  if (local_8 == (CarrierHelper *)0x0) {
LAB_4fc174cb:
    local_8 = (CarrierHelper *)0x0;
    if (bVar1) goto LAB_4fc174d3;
  }
  else {
    if ((!bVar1) || (bVar1 = Read(*(void **)this_00,(int)local_8 * 0x30), !bVar1)) {
      bVar1 = false;
      goto LAB_4fc174cb;
    }
LAB_4fc174d3:
    local_8 = (CarrierHelper *)0x0;
    bVar1 = Read((int *)&local_8,1);
    if (bVar1) {
      bVar1 = true;
      goto LAB_4fc174eb;
    }
  }
  bVar1 = false;
LAB_4fc174eb:
  std::
  vector<UtilityShipHelper::UtilityShipClass,std::allocator<UtilityShipHelper::UtilityShipClass>_>::
  _Resize<<lambda_c8a4f4cad98f6de524d7658fab4f9ded>_>
            ((vector<UtilityShipHelper::UtilityShipClass,std::allocator<UtilityShipHelper::UtilityShipClass>_>
              *)this_02,(uint)local_8,(<lambda_c8a4f4cad98f6de524d7658fab4f9ded>)this_02);
  if (local_8 != (CarrierHelper *)0x0) {
    if ((bVar1) && (bVar1 = Read(*(void **)this_02,(int)local_8 * 0x2c), bVar1)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
  }
  return bVar1;
}


// ---------------------------------------------------------------------
// CarrierHelper::PostLoad  @ 4fc17520  lines 47-86


bool __thiscall CarrierHelper::PostLoad(CarrierHelper *this,bool param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  CarrierClass *unaff_ESI;
  int *piVar4;
  int iVar5;
  CarrierClass *unaff_EDI;
  
  for (piVar4 = *(int **)&this->CarrierList; piVar4 != *(int **)&(this->CarrierList).field_0x4;
      piVar4 = piVar4 + 0xc) {
    ConvertHandles(piVar4,1);
  }
  for (piVar4 = *(int **)&this->DroneList; piVar4 != *(int **)&(this->DroneList).field_0x4;
      piVar4 = piVar4 + 0xb) {
    ConvertHandles(piVar4,1);
    ConvertHandles(piVar4 + 1,1);
  }
  iVar5 = 0;
  iVar2 = (*(int *)&(this->CarrierList).field_0x4 - *(int *)&this->CarrierList) / 0x30;
  if ((int)(TempCarrierBuffer._4_4_ - TempCarrierBuffer._0_4_) / 0x30 == iVar2) {
    iVar3 = 0;
    if (0 < iVar2) {
      do {
        bVar1 = ::operator==(unaff_EDI,unaff_ESI);
        if (!bVar1) {
          FormatLogMessage("CarrierList Index Mismatch: %d");
          break;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < (*(int *)&(this->CarrierList).field_0x4 - *(int *)&this->CarrierList) / 0x30)
      ;
    }
  }
  else {
    FormatLogMessage("CarrierList Size Mismatch! Old: %d New: %d");
  }
  iVar2 = (*(int *)&(this->DroneList).field_0x4 - *(int *)&this->DroneList) / 0x2c;
  if ((int)(TempDroneBuffer._4_4_ - TempDroneBuffer._0_4_) / 0x2c == iVar2) {
    if (0 < iVar2) {
      do {
        bVar1 = ::operator==((DroneClass *)unaff_EDI,(DroneClass *)unaff_ESI);
        if (!bVar1) {
          FormatLogMessage("DroneList Index Mismatch: %d");
          return true;
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < (*(int *)&(this->DroneList).field_0x4 - *(int *)&this->DroneList) / 0x2c);
    }
  }
  else {
    FormatLogMessage("DroneList Size Mismatch! Old: %d New: %d");
  }
  return true;
}


// ---------------------------------------------------------------------
// CarrierHelper::Save  @ 4fc1764c  lines 89-106


bool __thiscall CarrierHelper::Save(CarrierHelper *this,bool param_1)

{
  bool bVar1;
  int local_8;
  
  local_8 = (*(int *)&(this->CarrierList).field_0x4 - *(int *)&this->CarrierList) / 0x30;
  bVar1 = Write(&local_8,1);
  if (local_8 != 0) {
    if ((bVar1) && (bVar1 = Write(*(void **)&this->CarrierList,local_8 * 0x30), bVar1)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
  }
  local_8 = (*(int *)&(this->DroneList).field_0x4 - *(int *)&this->DroneList) / 0x2c;
  if ((bVar1) && (bVar1 = Write(&local_8,1), bVar1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (local_8 != 0) {
    if ((bVar1 != false) && (bVar1 = Write(*(void **)&this->DroneList,local_8 * 0x2c), bVar1)) {
      return true;
    }
    bVar1 = false;
  }
  return bVar1;
}


// ---------------------------------------------------------------------
// CarrierHelper::AddCarrierDroneObject  @ 4fc176ef  lines 109-185


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CarrierHelper::AddCarrierDroneObject
          (CarrierHelper *this,int param_1,int param_2,char *param_3,char *param_4,char *param_5)

{
  vector<CarrierHelper::DroneClass,std::allocator<CarrierHelper::DroneClass>_> *this_00;
  int iVar1;
  bool bVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  float *unaff_EBP;
  int *piVar6;
  char *unaff_EDI;
  char *pcVar7;
  undefined1 uVar8;
  int local_bc;
  char *local_b8;
  int local_b4;
  float local_b0;
  int *local_ac;
  float local_a8;
  char *local_a4;
  char *local_a0;
  Vector local_9c;
  Vector local_90;
  char local_84 [64];
  char local_44 [64];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)&local_bc;
  local_a0 = param_3;
  local_a4 = param_4;
  this_00 = &this->DroneList;
  local_b8 = param_5;
  piVar3 = *(int **)this_00;
  local_b4 = param_1;
  for (; piVar3 != *(int **)&(this->DroneList).field_0x4; piVar3 = piVar3 + 0xb) {
    if (*piVar3 == param_1) {
      return;
    }
  }
  std::
  vector<UtilityShipHelper::UtilityShipClass,std::allocator<UtilityShipHelper::UtilityShipClass>_>::
  _Resize<<lambda_c8a4f4cad98f6de524d7658fab4f9ded>_>
            ((vector<UtilityShipHelper::UtilityShipClass,std::allocator<UtilityShipHelper::UtilityShipClass>_>
              *)this_00,(*(int *)&(this->DroneList).field_0x4 - *(int *)this_00) / 0x2c + 1,
             (<lambda_c8a4f4cad98f6de524d7658fab4f9ded>)this_00);
  piVar6 = (int *)(*(int *)this_00 + -0x2c +
                  ((*(int *)&(this->DroneList).field_0x4 - *(int *)this_00) / 0x2c) * 0x2c);
  local_ac = piVar6;
  memset(piVar6,0,0x2c);
  iVar1 = local_b4;
  piVar3 = *(int **)&this->CarrierList;
  local_b0 = 3.4028235e+38;
  local_bc = -1;
  if (piVar3 != *(int **)&(this->CarrierList).field_0x4) {
    do {
      GetPosition(*piVar3,&local_9c);
      GetPosition(iVar1,&local_90);
      local_a8 = (local_9c.z - local_90.z) * (local_9c.z - local_90.z) +
                 (local_9c.x - local_90.x) * (local_9c.x - local_90.x) +
                 (local_9c.y - local_90.y) * (local_9c.y - local_90.y);
      if (((local_a8 < local_b0) && (iVar1 != *piVar3)) &&
         (iVar4 = GetTeamNum(*piVar3), iVar4 == param_2)) {
        local_bc = ((int)piVar3 - *(int *)&this->CarrierList) / 0x30;
        local_b0 = local_a8;
      }
      piVar3 = piVar3 + 0xc;
    } while (piVar3 != *(int **)&(this->CarrierList).field_0x4);
    piVar6 = local_ac;
  }
  *piVar6 = local_b4;
  if (-1 < local_bc) {
    iVar1 = *(int *)&this->CarrierList;
    local_b4 = local_bc * 0x30;
    local_ac = *(int **)(local_b4 + 4 + iVar1);
    if ((((float)local_ac == ___real_00000000) || (local_b0 < (float)local_ac)) &&
       ((iVar4 = *(int *)(local_b4 + 0x18 + iVar1), iVar4 == 0 ||
        (*(int *)(local_b4 + 0x1c + iVar1) < iVar4)))) {
      DroneActivate(this,(*(int *)&(this->DroneList).field_0x4 - *(int *)&this->DroneList) / 0x2c +
                         -1,local_bc);
      iVar1 = local_b4;
      if (local_b8 != (char *)0x0) {
        iVar4 = 0;
        do {
          memset(local_84,0,0x40);
          GetObjInfo(*(int *)(iVar1 + *(int *)&this->CarrierList),iVar4 + Get_Weapon0ODF,local_84);
          memset(local_44,0,0x40);
          bVar2 = OpenODF2((char *)unaff_EBP);
          if (((bVar2) &&
              (iVar5 = GetODFString("DispenserClass","objectClass",(char *)0x40,local_44,0,
                                    (char *)unaff_EBP,unaff_EDI), iVar5 != 0)) &&
             (iVar5 = _stricmp(local_b8,local_44), iVar5 == 0)) {
            local_b8 = (char *)0x0;
            piVar6[5] = iVar4;
            GetODFInt("WeaponClass","localAmmo",(char *)&local_b8,(char *)0x0,(int *)unaff_EBP,
                      (int)unaff_EDI);
            if (0 < (int)local_b8) {
              *(undefined1 *)(piVar6 + 6) = 1;
            }
            break;
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 < 5);
      }
      goto LAB_4fc17999;
    }
  }
  DroneDeactivate(this,(*(int *)&(this->DroneList).field_0x4 - *(int *)&this->DroneList) / 0x2c + -1
                  ,false);
LAB_4fc17999:
  uVar8 = 0xdc;
  pcVar7 = "DroneClass";
  GetODFFloat("DroneClass","RandomTargetRange",(char *)(piVar6 + 7),(char *)0x0,unaff_EBP,
              (float)unaff_EDI);
  GetODFBool("DroneClass","canSwitchCarrier",(char *)((int)piVar6 + 0x19),(char *)0x1,(bool *)pcVar7
             ,(bool)uVar8);
  return;
}


// ---------------------------------------------------------------------
// CarrierHelper::AddCarrierObject  @ 4fc179f2  lines 188-223


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CarrierHelper::AddCarrierObject(CarrierHelper *this,int param_1,char *param_2,char *param_3)

{
  vector<CarrierHelper::CarrierClass,std::allocator<CarrierHelper::CarrierClass>_> *this_00;
  int *piVar1;
  int iVar2;
  float unaff_EBP;
  float *unaff_EDI;
  int *piVar3;
  undefined1 uVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  char *pcVar8;
  
  this_00 = &this->CarrierList;
  piVar1 = *(int **)this_00;
  while( true ) {
    if (piVar1 == *(int **)&(this->CarrierList).field_0x4) {
      std::vector<CarrierHelper::CarrierClass,std::allocator<CarrierHelper::CarrierClass>_>::
      _Resize<<lambda_87c6343aa49b10f10e6fc064335a8cab>_>
                (this_00,(*(int *)&(this->CarrierList).field_0x4 - *(int *)this_00) / 0x30 + 1,
                 (<lambda_87c6343aa49b10f10e6fc064335a8cab>)this_00);
      piVar3 = (int *)(*(int *)this_00 + -0x30 +
                      ((*(int *)&(this->CarrierList).field_0x4 - *(int *)this_00) / 0x30) * 0x30);
      memset(piVar3,0,0x30);
      GetODFFloat("CarrierClass","controlRange",(char *)(piVar3 + 1),(char *)0x0,unaff_EDI,unaff_EBP
                 );
      GetODFFloat("CarrierClass","defendRange",(char *)(piVar3 + 3),(char *)piVar3[1],unaff_EDI,
                  unaff_EBP);
      GetODFFloat("CarrierClass","recallRange",(char *)(piVar3 + 4),___real_42480000,unaff_EDI,
                  unaff_EBP);
      pcVar8 = "droneIdleTime";
      pcVar7 = "CarrierClass";
      GetODFFloat("CarrierClass","droneIdleTime",(char *)(piVar3 + 5),___real_42f00000,unaff_EDI,
                  unaff_EBP);
      piVar1 = piVar3 + 6;
      pcVar6 = "maxDrones";
      pcVar5 = "CarrierClass";
      GetODFInt("CarrierClass","maxDrones",(char *)piVar1,(char *)0x0,(int *)pcVar7,(int)pcVar8);
      GetODFInt("CarrierClass","minAttackForce",(char *)(piVar3 + 8),(char *)0x0,(int *)pcVar5,
                (int)pcVar6);
      iVar2 = piVar3[8];
      if (*piVar1 == 0) {
        if (iVar2 < 0) {
          piVar3[8] = 0;
        }
      }
      else {
        if (iVar2 < 0) {
          iVar2 = 0;
        }
        else if (*piVar1 < iVar2) {
          iVar2 = *piVar1;
        }
        piVar3[8] = iVar2;
      }
      pcVar8 = "repairRange";
      pcVar5 = "CarrierClass";
      GetODFFloat("CarrierClass","repairRange",(char *)(piVar3 + 2),___real_42c80000,unaff_EDI,
                  unaff_EBP);
      pcVar7 = "healthRepairAmount";
      pcVar6 = "CarrierClass";
      GetODFLong("CarrierClass","healthRepairAmount",(char *)(piVar3 + 9),(char *)0x0,(long *)pcVar5
                 ,(long)pcVar8);
      uVar4 = 0x94;
      pcVar5 = "CarrierClass";
      GetODFLong("CarrierClass","ammoRepairAmount",(char *)(piVar3 + 10),(char *)0x0,(long *)pcVar6,
                 (long)pcVar7);
      GetODFBool("CarrierClass","serviceAllies",(char *)(piVar3 + 0xb),(char *)0x0,(bool *)pcVar5,
                 (bool)uVar4);
      *piVar3 = param_1;
      return;
    }
    if (*piVar1 == param_1) break;
    piVar1 = piVar1 + 0xc;
  }
  return;
}


// ---------------------------------------------------------------------
// CarrierHelper::Execute  @ 4fc17b91  lines 226-475


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall CarrierHelper::Execute(CarrierHelper *this,BZ1Helper *param_1)

{
  float fVar1;
  CarrierHelper *pCVar2;
  BZ1Helper *this_00;
  bool bVar3;
  int *piVar4;
  long lVar5;
  long lVar6;
  CarrierHelper *pCVar7;
  int iVar8;
  int extraout_ECX;
  int iVar9;
  AlignTerrainReplaceClass *pAVar10;
  AlignTerrainReplaceClass *pAVar11;
  int iVar12;
  Vector *unaff_ESI;
  size_t sVar13;
  AlignTerrainReplaceClass *pAVar14;
  int *piVar15;
  Vector *unaff_EDI;
  AlignTerrainReplaceClass *pAVar16;
  float fVar17;
  char *pcVar18;
  undefined1 auStack_458 [7];
  bool local_451;
  AlignTerrainReplaceClass *local_450;
  CarrierHelper *local_44c;
  double local_448;
  BZ1Helper *local_43c;
  Vector local_438;
  Vector local_42c;
  Vector local_420;
  Vector local_414;
  undefined1 local_408 [64];
  undefined1 local_3c8 [64];
  undefined1 local_388 [64];
  undefined1 local_348 [64];
  undefined1 local_308 [64];
  undefined1 local_2c8 [64];
  undefined1 local_288 [64];
  undefined1 local_248 [64];
  undefined1 local_208 [64];
  undefined1 local_1c8 [64];
  undefined1 local_188 [64];
  undefined1 local_148 [64];
  undefined1 local_108 [64];
  undefined1 local_c8 [64];
  undefined1 local_88 [64];
  undefined1 local_48 [68];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)auStack_458;
  local_43c = param_1;
  pAVar14 = *(AlignTerrainReplaceClass **)&(this->CarrierList).field_0x4;
  pAVar11 = *(AlignTerrainReplaceClass **)&this->CarrierList;
  local_451 = BZ1Helper::Logging;
  local_448 = (double)CONCAT44(local_448._4_4_,pAVar14);
  local_44c = this;
  while ((pAVar11 != pAVar14 &&
         (bVar3 = BZ1Helper::ShouldRemoveAlignTerrainReplace(pAVar11), !bVar3))) {
    pAVar11 = pAVar11 + 3;
  }
  if (pAVar11 != pAVar14) {
    pAVar10 = pAVar11 + 3;
    local_450 = pAVar10;
    if (pAVar10 != pAVar14) {
      do {
        bVar3 = BZ1Helper::ShouldRemoveAlignTerrainReplace(pAVar10);
        if (!bVar3) {
          pAVar14 = pAVar10;
          pAVar16 = pAVar11;
          for (iVar8 = 0xc; iVar8 != 0; iVar8 = iVar8 + -1) {
            pAVar16->AlignHandle = pAVar14->AlignHandle;
            pAVar14 = (AlignTerrainReplaceClass *)&pAVar14->NormalVec;
            pAVar16 = (AlignTerrainReplaceClass *)&pAVar16->NormalVec;
          }
          pAVar11 = pAVar11 + 3;
          pAVar14 = local_448._0_4_;
        }
        pAVar10 = pAVar10 + 3;
      } while (pAVar10 != pAVar14);
      this = local_44c;
    }
    if (pAVar11 != pAVar14) {
      sVar13 = *(int *)&(this->CarrierList).field_0x4 - (int)pAVar14;
      memmove(pAVar11,pAVar14,sVar13);
      *(size_t *)&(this->CarrierList).field_0x4 = sVar13 + (int)pAVar11;
    }
  }
  pAVar14 = *(AlignTerrainReplaceClass **)&(this->DroneList).field_0x4;
  pAVar11 = *(AlignTerrainReplaceClass **)&this->DroneList;
  local_450 = pAVar14;
  while ((pAVar11 != pAVar14 &&
         (bVar3 = BZ1Helper::ShouldRemoveAlignTerrainReplace(pAVar11), !bVar3))) {
    pAVar11 = (AlignTerrainReplaceClass *)&pAVar11[2].NormalVec.z;
  }
  if (pAVar11 != pAVar14) {
    pAVar10 = (AlignTerrainReplaceClass *)&pAVar11[2].NormalVec.z;
    local_448 = (double)CONCAT44(local_448._4_4_,pAVar10);
    if (pAVar10 != pAVar14) {
      do {
        bVar3 = BZ1Helper::ShouldRemoveAlignTerrainReplace(pAVar10);
        if (!bVar3) {
          pAVar14 = pAVar10;
          pAVar16 = pAVar11;
          for (iVar8 = 0xb; iVar8 != 0; iVar8 = iVar8 + -1) {
            pAVar16->AlignHandle = pAVar14->AlignHandle;
            pAVar14 = (AlignTerrainReplaceClass *)&pAVar14->NormalVec;
            pAVar16 = (AlignTerrainReplaceClass *)&pAVar16->NormalVec;
          }
          pAVar11 = (AlignTerrainReplaceClass *)&pAVar11[2].NormalVec.z;
          pAVar14 = local_450;
        }
        pAVar10 = (AlignTerrainReplaceClass *)&pAVar10[2].NormalVec.z;
      } while (pAVar10 != pAVar14);
      this = local_44c;
    }
    if (pAVar11 != pAVar14) {
      sVar13 = *(int *)&(this->DroneList).field_0x4 - (int)pAVar14;
      memmove(pAVar11,pAVar14,sVar13);
      piVar4 = (int *)(sVar13 + (int)pAVar11);
      *(int **)&(this->DroneList).field_0x4 = piVar4;
      goto LAB_4fc17cac;
    }
  }
  piVar4 = *(int **)&(this->DroneList).field_0x4;
LAB_4fc17cac:
  piVar15 = *(int **)&this->DroneList;
  bVar3 = piVar15 == piVar4;
  do {
    if (bVar3) {
      return;
    }
    local_450 = (AlignTerrainReplaceClass *)piVar15;
    local_44c = (CarrierHelper *)GetTeamNum(*piVar15);
    GetPosition(*piVar15,&local_438);
    pAVar14 = local_450;
    piVar15[8] = (int)local_438.x;
    piVar15[9] = (int)local_438.y;
    piVar15[10] = (int)local_438.z;
    iVar8 = local_450->AlignHandle;
    local_450 = (AlignTerrainReplaceClass *)(((int)local_450 - *(int *)&this->DroneList) / 0x2c);
    lVar5 = GetCurHealth(iVar8);
    if ((lVar5 == -0x4d2) || (lVar6 = GetMaxHealth(iVar8), lVar6 <= lVar5)) {
      iVar8 = pAVar14->AlignHandle;
      lVar5 = GetCurAmmo(iVar8);
      if ((lVar5 != -0x4d2) && (lVar6 = GetMaxAmmo(iVar8), lVar5 < lVar6)) goto LAB_4fc17d37;
    }
    else {
LAB_4fc17d37:
      for (piVar4 = *(int **)&this->CarrierList; piVar4 != *(int **)&(this->CarrierList).field_0x4;
          piVar4 = piVar4 + 0xc) {
        if ((((char)piVar4[0xb] != '\0') ||
            (((int)piVar4 - *(int *)&this->CarrierList) / 0x30 == *(int *)((int)pAVar14 + 8))) &&
           ((float)piVar4[2] != ___real_00000000)) {
          GetPosition(*piVar4,&local_42c);
          local_448 = (double)(float)piVar4[2];
          fVar17 = GetDistance3DSquared(unaff_EDI,unaff_ESI);
          fVar1 = (float)((float10)local_448 * (float10)local_448);
          local_448 = (double)CONCAT44(local_448._4_4_,fVar1);
          if (fVar17 < fVar1) {
            if (piVar4[9] != 0) {
              AddHealth(pAVar14->AlignHandle,piVar4[9] / BZ1Helper::m_GameTPS);
            }
            if (piVar4[10] != 0) {
              AddAmmo(pAVar14->AlignHandle,piVar4[10] / BZ1Helper::m_GameTPS);
            }
          }
        }
      }
    }
    bVar3 = IsPlayer(pAVar14->AlignHandle);
    if (!bVar3) {
      iVar8 = 0;
      iVar12 = 0;
      if (*(int *)((int)pAVar14 + 0xc) != 0) {
        iVar9 = *(int *)(*(int *)((int)pAVar14 + 8) * 0x30 + *(int *)&this->CarrierList);
        bVar3 = IsAround(iVar9);
        if (bVar3) {
LAB_4fc17e9e:
          this_00 = local_43c;
          iVar8 = DroneFindTarget(this,local_43c,(int)local_450,iVar9);
          pcVar18 = *(char **)&this->CarrierList;
          iVar12 = BZ1Helper::GetNearestObject
                             (this_00,*(int *)(pcVar18 + *(int *)((int)pAVar14 + 8) * 0x30),
                              *(float *)(pcVar18 + *(int *)((int)pAVar14 + 8) * 0x30 + 0xc),
                              (int)local_44c,4,true,0,SUB41(pcVar18,0),SUB41(pcVar18,0),0,
                              (char *)0x0,pcVar18);
        }
        else {
          if (*(float *)(*(int *)((int)pAVar14 + 8) * 0x30 + 4 + *(int *)&this->CarrierList) !=
              ___real_00000000) {
            GetPosition(*(int *)(*(int *)((int)pAVar14 + 8) * 0x30 + *(int *)&this->CarrierList),
                        &local_420);
            local_448 = (double)*(float *)(*(int *)((int)pAVar14 + 8) * 0x30 + 4 +
                                          *(int *)&this->CarrierList);
            fVar17 = GetDistance3DSquared(unaff_EDI,unaff_ESI);
            fVar1 = (float)((float10)local_448 * (float10)local_448);
            local_448 = (double)CONCAT44(local_448._4_4_,fVar1);
            iVar9 = extraout_ECX;
            if (fVar17 <= fVar1) goto LAB_4fc17e9e;
          }
          DroneDeactivate(this,(int)local_450,true);
          if (local_451 != false) {
            GetODFName(*(int *)((int)pAVar14 + 0xc));
            FormatLogMessage(
                            "Drone %08x \'%s\' Set to DroneState: %d, Carrier Dead or Outside of Range"
                            );
          }
        }
      }
      iVar9 = *(int *)((int)pAVar14 + 0xc);
      if (iVar9 == 0) {
        if ((*(char *)((int)pAVar14 + 0x19) != '\0') ||
           (bVar3 = IsAround(*(int *)(*(int *)((int)pAVar14 + 8) * 0x30 + *(int *)&this->CarrierList
                                     )), bVar3)) {
          pCVar2 = local_44c;
          piVar4 = *(int **)&this->CarrierList;
          if (piVar4 != *(int **)&(this->CarrierList).field_0x4) {
            do {
              pCVar7 = (CarrierHelper *)GetTeamNum(*piVar4);
              if (pCVar7 == pCVar2) {
                if ((float)piVar4[1] != ___real_00000000) {
                  GetPosition(*piVar4,&local_414);
                  local_448 = (double)(float)piVar4[1];
                  fVar17 = GetDistance3DSquared(unaff_EDI,unaff_ESI);
                  fVar1 = (float)((float10)local_448 * (float10)local_448);
                  local_448 = (double)CONCAT44(local_448._4_4_,fVar1);
                  if (fVar1 <= fVar17) goto LAB_4fc183c5;
                }
                if ((piVar4[6] == 0) || (piVar4[7] < piVar4[6])) {
                  DroneActivate(this,(int)local_450,
                                ((int)piVar4 - *(int *)&this->CarrierList) / 0x30);
                  if (local_451 != false) {
                    memset(local_48,0,0x40);
                    memset(local_88,0,0x40);
                    GetODFName((int)unaff_EDI,(char *)unaff_ESI);
                    GetODFName((int)unaff_EDI,(char *)unaff_ESI);
                    pcVar18 = 
                    "Drone %08x \'%s\' INACTIVE: Set to DroneState: %d, Reassigned to Carrier: %08x \'%s\'"
                    ;
                    goto LAB_4fc18452;
                  }
                  break;
                }
              }
LAB_4fc183c5:
              piVar4 = piVar4 + 0xc;
            } while (piVar4 != *(int **)&(this->CarrierList).field_0x4);
          }
        }
      }
      else if (iVar9 == 1) {
        if (iVar8 == 0) {
          if (iVar12 == 0) {
            if (*(int *)((int)pAVar14 + 0x10) < 1) {
              bVar3 = DroneRecall(this,(int)local_450);
              if ((bVar3) && (local_451 != false)) {
                memset(local_c8,0,0x40);
                memset(local_108,0,0x40);
                GetODFName((int)unaff_EDI,(char *)unaff_ESI);
                GetODFName((int)unaff_EDI,(char *)unaff_ESI);
                FormatLogMessage("Drone %08x \'%s\' IDLE: Drone Recalled, Carrier: %08x \'%s\'");
              }
            }
            else {
              *(int *)((int)pAVar14 + 0x10) = *(int *)((int)pAVar14 + 0x10) + -1;
            }
          }
          else {
            iVar8 = (int)local_450 * 0x2c;
            SetIndependence(*(int *)(iVar8 + *(int *)&this->DroneList),1);
            Defend2(*(int *)(iVar8 + *(int *)&this->DroneList),
                    *(int *)(*(int *)(iVar8 + 8 + *(int *)&this->DroneList) * 0x30 +
                            *(int *)&this->CarrierList),1);
            *(undefined4 *)(iVar8 + 0xc + *(int *)&this->DroneList) = 3;
            if (local_451 != false) {
              memset(local_148,0,0x40);
              memset(local_188,0,0x40);
              GetODFName((int)unaff_EDI,(char *)unaff_ESI);
              GetODFName((int)unaff_EDI,(char *)unaff_ESI);
              pcVar18 = "Drone %08x \'%s\' IDLE: Set to DroneState %d, Carrier: %08x \'%s\'";
              goto LAB_4fc18452;
            }
          }
        }
        else {
          DroneAttack(this,(int)local_450,iVar8,(int)local_44c);
          if (local_451 != false) {
            memset(local_1c8,0,0x40);
            memset(local_248,0,0x40);
            memset(local_208,0,0x40);
            GetODFName((int)unaff_EDI,(char *)unaff_ESI);
            GetODFName((int)unaff_EDI,(char *)unaff_ESI);
            GetODFName((int)unaff_EDI,(char *)unaff_ESI);
            pcVar18 = 
            "Drone %08x \'%s\' IDLE: Set to DroneState %d, Target: %08x \'%s\', Carrier: %08x \'%s\'"
            ;
LAB_4fc181bb:
            FormatLogMessage(pcVar18);
          }
        }
      }
      else if (iVar9 == 2) {
        bVar3 = IsAlive((int *)((int)pAVar14 + 4));
        if ((!bVar3) && (DroneIdle(this,(int)local_450), local_451 != false)) {
          memset(local_288,0,0x40);
          memset(local_2c8,0,0x40);
          GetODFName((int)unaff_EDI,(char *)unaff_ESI);
          GetODFName((int)unaff_EDI,(char *)unaff_ESI);
          pcVar18 = "Drone %08x \'%s\' ATTACKING: Set to DroneState %d, Carrier: %08x \'%s\'";
LAB_4fc18452:
          FormatLogMessage(pcVar18);
        }
      }
      else if ((iVar9 == 3) && (bVar3 = IsAlive((int *)((int)pAVar14 + 4)), !bVar3)) {
        if (iVar8 == 0) {
          if ((iVar12 == 0) && (DroneIdle(this,(int)local_450), local_451 != false)) {
            memset(local_308,0,0x40);
            memset(local_348,0,0x40);
            GetODFName((int)unaff_EDI,(char *)unaff_ESI);
            GetODFName((int)unaff_EDI,(char *)unaff_ESI);
            pcVar18 = "Drone %08x \'%s\' DEFENDING: Set to DroneState %d, Carrier: %08x \'%s\'";
            goto LAB_4fc18452;
          }
        }
        else {
          DroneAttack(this,(int)local_450,iVar8,(int)local_44c);
          if (local_451 != false) {
            memset(local_388,0,0x40);
            memset(local_408,0,0x40);
            memset(local_3c8,0,0x40);
            GetODFName((int)unaff_EDI,(char *)unaff_ESI);
            GetODFName((int)unaff_EDI,(char *)unaff_ESI);
            GetODFName((int)unaff_EDI,(char *)unaff_ESI);
            pcVar18 = 
            "Drone %08x \'%s\' DEFENDING: Set to DroneState %d, Target: %08x \'%s\', Carrier: %08x \'%s\'"
            ;
            goto LAB_4fc181bb;
          }
        }
      }
    }
    piVar15 = (int *)((int)pAVar14 + 0x2c);
    bVar3 = piVar15 == *(int **)&(this->DroneList).field_0x4;
  } while( true );
}


// ---------------------------------------------------------------------
// CarrierHelper::PreOrdnanceHit  @ 4fc18487  lines 478-505


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall
CarrierHelper::PreOrdnanceHit(CarrierHelper *this,int param_1,int param_2,int param_3,char *param_4)

{
  int *piVar1;
  undefined1 *puVar2;
  char *pcVar3;
  undefined1 auStack_88 [3];
  bool local_85;
  undefined1 local_84 [64];
  undefined1 local_44 [64];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)auStack_88;
  local_85 = BZ1Helper::Logging;
  if (((*(int *)&(this->CarrierList).field_0x4 - *(int *)&this->CarrierList) / 0x30 != 0) &&
     (piVar1 = *(int **)&this->DroneList, piVar1 != *(int **)&(this->DroneList).field_0x4)) {
    do {
      if ((param_2 == *(int *)(piVar1[2] * 0x30 + *(int *)&this->CarrierList)) &&
         ((piVar1[3] != 3 && (piVar1[1] != param_1)))) {
        Attack(*piVar1,param_1,1);
        piVar1[3] = 3;
        piVar1[1] = param_1;
        if (local_85 != false) {
          memset(local_44,0,0x40);
          puVar2 = local_84;
          pcVar3 = (char *)0x0;
          memset(puVar2,0,0x40);
          GetODFName((int)puVar2,pcVar3);
          GetODFName((int)puVar2,pcVar3);
          FormatLogMessage(
                          "Drone %08x \'%s\' PREORDNANCEHIT: Set to DroneState: %d, Carrier: %08x \'%s\'"
                          );
        }
      }
      piVar1 = piVar1 + 0xb;
    } while (piVar1 != *(int **)&(this->DroneList).field_0x4);
  }
  return;
}


// ---------------------------------------------------------------------
// CarrierHelper::DroneFindTarget  @ 4fc1859d  lines 511-562


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall
CarrierHelper::DroneFindTarget(CarrierHelper *this,BZ1Helper *param_1,int param_2,int param_3)

{
  Vector VVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int in_stack_ffffffa8;
  undefined1 in_stack_ffffffac;
  undefined1 in_stack_ffffffb0;
  bool bVar5;
  int in_stack_ffffffb8;
  char *in_stack_ffffffbc;
  char *in_stack_ffffffc0;
  float fVar6;
  int local_1c;
  BZ1Helper *local_18;
  int local_14;
  Vector local_10;
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)&local_1c;
  iVar4 = param_2 * 0x2c;
  local_18 = param_1;
  iVar3 = 0;
  if (*(int *)(iVar4 + 0xc + *(int *)&this->DroneList) != 0) {
    local_14 = iVar4;
    bVar2 = IsAlive((int *)(*(int *)&this->DroneList + 4 + iVar4));
    iVar3 = param_2 * 0x2c;
    if (bVar2) {
      iVar3 = *(int *)(*(int *)&this->DroneList + 4 + iVar3);
    }
    else {
      bVar2 = IsPlayer(*(int *)(*(int *)(*(int *)&this->DroneList + 8 + iVar3) * 0x30 +
                               *(int *)&this->CarrierList));
      iVar3 = *(int *)(*(int *)(*(int *)&this->DroneList + 8 + iVar3) * 0x30 +
                      *(int *)&this->CarrierList);
      if (bVar2) {
        iVar3 = GetTeamNum(iVar3);
        local_1c = GetUserTarget(iVar3);
      }
      else {
        local_1c = GetTarget(iVar3);
      }
      iVar3 = *(int *)&this->DroneList;
      if ((*(float *)(iVar3 + 0x1c + iVar4) != ___real_00000000) && (local_1c != 0)) {
        GetPosition(local_1c,&local_10);
        fVar6 = *(float *)(*(int *)&this->DroneList + iVar4 + 0x1c);
        bVar5 = false;
        bVar2 = true;
        iVar4 = 4;
        iVar3 = GetTeamNum(local_1c);
        VVar1.y = local_10.y;
        VVar1.x = local_10.x;
        VVar1.z = local_10.z;
        local_1c = BZ1Helper::GetRandomObject
                             (local_18,iVar3,iVar4,bVar2,in_stack_ffffffa8,(bool)in_stack_ffffffac,
                              (bool)in_stack_ffffffb0,bVar5,in_stack_ffffffb8,in_stack_ffffffbc,
                              in_stack_ffffffc0,fVar6,VVar1);
        iVar3 = *(int *)&this->DroneList;
        iVar4 = local_14;
      }
      iVar4 = *(int *)(iVar4 + 8 + iVar3) * 0x30;
      iVar3 = 0;
      if (*(int *)(iVar4 + 0x20 + *(int *)&this->CarrierList) <=
          *(int *)(iVar4 + 0x1c + *(int *)&this->CarrierList)) {
        iVar3 = local_1c;
      }
    }
  }
  return iVar3;
}


// ---------------------------------------------------------------------
// CarrierHelper::DroneRecall  @ 4fc186cd  lines 566-591


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool __thiscall CarrierHelper::DroneRecall(CarrierHelper *this,int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  int *piVar5;
  int *piVar6;
  int iVar7;
  undefined1 *puVar8;
  char *pcVar9;
  int iVar10;
  undefined1 auStack_90 [3];
  bool local_8d;
  float fStack_8c;
  int iStack_88;
  undefined1 auStack_84 [64];
  undefined1 auStack_44 [64];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)auStack_90;
  iVar7 = param_1 * 0x2c;
  local_8d = BZ1Helper::Logging;
  piVar6 = (int *)(*(int *)&this->DroneList + iVar7);
  piVar5 = (int *)(piVar6[2] * 0x30 + *(int *)&this->CarrierList);
  if ((float)piVar5[4] != ___real_00000000) {
    fStack_8c = (*misnImport.GetDistanceObject)(piVar6,piVar5);
    iVar1 = *(int *)&this->CarrierList;
    iVar2 = *(int *)&this->DroneList;
    iVar10 = *(int *)(iVar2 + 8 + iVar7);
    iStack_88 = iVar10 * 0x30;
    if (fStack_8c < *(float *)(iStack_88 + 0x10 + iVar1)) {
      iVar3 = param_1 * 0x2c;
      if (*(char *)(iVar2 + 0x18 + iVar7) == '\0') {
        lVar4 = GetMaxHealth(*(int *)(iVar3 + iVar2));
        AddAmmo(*(int *)(iVar10 * 0x30 + iVar1),lVar4);
      }
      else {
        iVar10 = *(int *)(iVar3 + 0x14 + iVar2);
        lVar4 = GetMaxHealth(*(int *)(iVar3 + iVar2));
        AddLocalAmmo(*(int *)(iStack_88 + iVar1),(float)lVar4,iVar10);
      }
      if (local_8d != false) {
        memset(auStack_44,0,0x40);
        puVar8 = auStack_84;
        pcVar9 = (char *)0x0;
        memset(puVar8,0,0x40);
        GetODFName((int)puVar8,pcVar9);
        GetODFName((int)puVar8,pcVar9);
        FormatLogMessage("Drone %08x \'%s\' PACKUP: Set to Recall to Carrier: %08x \'%s\'");
      }
      piVar5 = (int *)(*(int *)(iVar7 + 8 + *(int *)&this->DroneList) * 0x30 + 0x1c +
                      *(int *)&this->CarrierList);
      *piVar5 = *piVar5 + -1;
      RemoveObject(*(int *)(iVar7 + *(int *)&this->DroneList));
      return true;
    }
  }
  return false;
}


// ---------------------------------------------------------------------
// CarrierHelper::DroneActivate  @ 4fc18845  lines 595-600


void __thiscall CarrierHelper::DroneActivate(CarrierHelper *this,int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = param_1 * 0x2c;
  SetIndependence(*(int *)(*(int *)&this->DroneList + iVar2),1);
  *(int *)(*(int *)&this->DroneList + 8 + iVar2) = param_2;
  DroneIdle(this,param_1);
  piVar1 = (int *)(*(int *)(*(int *)&this->DroneList + 8 + iVar2) * 0x30 + 0x1c +
                  *(int *)&this->CarrierList);
  *piVar1 = *piVar1 + 1;
  return;
}


// ---------------------------------------------------------------------
// CarrierHelper::DroneDeactivate  @ 4fc18889  lines 604-612


void __thiscall CarrierHelper::DroneDeactivate(CarrierHelper *this,int param_1,bool param_2)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = param_1 * 0x2c;
  SetIndependence(*(int *)(*(int *)&this->DroneList + iVar2),0);
  Stop(*(int *)(*(int *)&this->DroneList + iVar2),1);
  *(undefined4 *)(*(int *)&this->DroneList + 0xc + iVar2) = 0;
  if (param_2) {
    piVar1 = (int *)(*(int *)(*(int *)&this->DroneList + 8 + iVar2) * 0x30 + 0x1c +
                    *(int *)&this->CarrierList);
    *piVar1 = *piVar1 + -1;
  }
  return;
}


// ---------------------------------------------------------------------
// CarrierHelper::DroneIdle  @ 4fc188d4  lines 616-622


void __thiscall CarrierHelper::DroneIdle(CarrierHelper *this,int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = param_1 * 0x2c;
  SetIndependence(*(int *)(*(int *)&this->DroneList + iVar3),0);
  Follow(*(int *)(*(int *)&this->DroneList + iVar3),
         *(int *)(*(int *)(*(int *)&this->DroneList + 8 + iVar3) * 0x30 + *(int *)&this->CarrierList
                 ),1);
  iVar1 = *(int *)&this->DroneList;
  iVar2 = SecondsToTurns(*(float *)(*(int *)(iVar1 + 8 + iVar3) * 0x30 + *(int *)&this->CarrierList
                                   + 0x14));
  *(int *)(iVar1 + 0x10 + iVar3) = iVar2;
  *(undefined4 *)(*(int *)&this->DroneList + 0xc + iVar3) = 1;
  return;
}


// ---------------------------------------------------------------------
// CarrierHelper::DroneAttack  @ 4fc18935  lines 626-637


void __thiscall CarrierHelper::DroneAttack(CarrierHelper *this,int param_1,int param_2,int param_3)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = param_1 * 0x2c;
  SetIndependence(*(int *)(*(int *)&this->DroneList + iVar3),1);
  iVar2 = GetTeamNum(param_2);
  bVar1 = IsTeamAllied(param_3,iVar2);
  iVar2 = *(int *)(iVar3 + *(int *)&this->DroneList);
  if (bVar1) {
    Defend2(iVar2,param_2,1);
  }
  else {
    Attack(iVar2,param_2,1);
  }
  *(int *)(*(int *)&this->DroneList + 4 + iVar3) = param_2;
  *(undefined4 *)(*(int *)&this->DroneList + 0xc + iVar3) = 2;
  return;
}

