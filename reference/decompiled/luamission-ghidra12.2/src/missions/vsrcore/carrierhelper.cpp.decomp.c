// Reconstructed by Ghidra from LuaMission.dll + LuaMission.pdb
// Original source file: /e:/github/vsr_dll_source/missions/vsrcore/carrierhelper.cpp
// Functions are ordered by original source line. This is decompiler
// output, not the author's source: names/types come from the PDB,
// local variable names and control flow are reconstructed.


// ---------------------------------------------------------------------
// `dynamic_initializer_for_'TempCarrierBuffer''  @ 4fc015ed  lines 8-8


void __cdecl _dynamic_initializer_for__TempCarrierBuffer__(void)

{
  atexit(_dynamic_atexit_destructor_for__TempCarrierBuffer__);
  return;
}


// ---------------------------------------------------------------------
// `dynamic_initializer_for_'TempDroneBuffer''  @ 4fc015f9  lines 9-9


void __cdecl _dynamic_initializer_for__TempDroneBuffer__(void)

{
  atexit(_dynamic_atexit_destructor_for__TempDroneBuffer__);
  return;
}


// ---------------------------------------------------------------------
// CarrierHelper::~CarrierHelper  @ 4fc2bbe2  lines 16-17


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
// CarrierHelper::Load  @ 4fc2bbfc  lines 20-44


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
LAB_4fc2bc7c:
    local_8 = (CarrierHelper *)0x0;
    if (bVar1) goto LAB_4fc2bc84;
  }
  else {
    if ((!bVar1) || (bVar1 = Read(*(void **)this_00,(int)local_8 * 0x30), !bVar1)) {
      bVar1 = false;
      goto LAB_4fc2bc7c;
    }
LAB_4fc2bc84:
    local_8 = (CarrierHelper *)0x0;
    bVar1 = Read((int *)&local_8,1);
    if (bVar1) {
      bVar1 = true;
      goto LAB_4fc2bc9c;
    }
  }
  bVar1 = false;
LAB_4fc2bc9c:
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
// CarrierHelper::PostLoad  @ 4fc2bcd1  lines 47-86


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
// CarrierHelper::Save  @ 4fc2bdfd  lines 89-106


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
// CarrierHelper::AddCarrierDroneObject  @ 4fc2bea0  lines 109-185


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
      local_a8 = (local_9c.y - local_90.y) * (local_9c.y - local_90.y) +
                 (local_9c.x - local_90.x) * (local_9c.x - local_90.x) +
                 (local_9c.z - local_90.z) * (local_9c.z - local_90.z);
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
      goto LAB_4fc2c15e;
    }
  }
  DroneDeactivate(this,(*(int *)&(this->DroneList).field_0x4 - *(int *)&this->DroneList) / 0x2c + -1
                  ,false);
LAB_4fc2c15e:
  uVar8 = 0x70;
  pcVar7 = "DroneClass";
  GetODFFloat("DroneClass","RandomTargetRange",(char *)(piVar6 + 7),(char *)0x0,unaff_EBP,
              (float)unaff_EDI);
  GetODFBool("DroneClass","canSwitchCarrier",(char *)((int)piVar6 + 0x19),(char *)0x1,(bool *)pcVar7
             ,(bool)uVar8);
  return;
}


// ---------------------------------------------------------------------
// CarrierHelper::AddCarrierObject  @ 4fc2c1b7  lines 188-223


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
      uVar4 = 0x28;
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
// CarrierHelper::Execute  @ 4fc2c356  lines 226-475


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall CarrierHelper::Execute(CarrierHelper *this,BZ1Helper *param_1)

{
  CarrierHelper *pCVar1;
  bool bVar2;
  int *piVar3;
  long lVar4;
  long lVar5;
  AlignTerrainReplaceClass *pAVar6;
  int iVar7;
  int iVar8;
  AlignTerrainReplaceClass *pAVar9;
  AlignTerrainReplaceClass *pAVar10;
  CarrierHelper *pCVar11;
  char *unaff_ESI;
  size_t sVar12;
  int *piVar13;
  int unaff_EDI;
  AlignTerrainReplaceClass *pAVar14;
  char *pcVar15;
  undefined1 auStack_458 [3];
  bool local_455;
  AlignTerrainReplaceClass *local_454;
  CarrierHelper *local_450;
  AlignTerrainReplaceClass *local_44c;
  float local_448;
  float local_444;
  float local_440;
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
  pAVar6 = *(AlignTerrainReplaceClass **)&(this->CarrierList).field_0x4;
  pAVar10 = *(AlignTerrainReplaceClass **)&this->CarrierList;
  local_455 = BZ1Helper::Logging;
  local_454 = pAVar6;
  local_450 = this;
  while ((pAVar10 != pAVar6 && (bVar2 = BZ1Helper::ShouldRemoveAlignTerrainReplace(pAVar10), !bVar2)
         )) {
    pAVar10 = pAVar10 + 3;
  }
  if (pAVar10 != pAVar6) {
    pAVar9 = pAVar10 + 3;
    local_44c = pAVar9;
    if (pAVar9 != pAVar6) {
      do {
        bVar2 = BZ1Helper::ShouldRemoveAlignTerrainReplace(pAVar9);
        if (!bVar2) {
          pAVar6 = pAVar9;
          pAVar14 = pAVar10;
          for (iVar7 = 0xc; iVar7 != 0; iVar7 = iVar7 + -1) {
            pAVar14->AlignHandle = pAVar6->AlignHandle;
            pAVar6 = (AlignTerrainReplaceClass *)&pAVar6->NormalVec;
            pAVar14 = (AlignTerrainReplaceClass *)&pAVar14->NormalVec;
          }
          pAVar10 = pAVar10 + 3;
          pAVar6 = local_454;
        }
        pAVar9 = pAVar9 + 3;
      } while (pAVar9 != pAVar6);
      this = local_450;
    }
    if (pAVar10 != pAVar6) {
      sVar12 = *(int *)&(this->CarrierList).field_0x4 - (int)pAVar6;
      memmove(pAVar10,pAVar6,sVar12);
      *(size_t *)&(this->CarrierList).field_0x4 = sVar12 + (int)pAVar10;
    }
  }
  pAVar6 = *(AlignTerrainReplaceClass **)&(this->DroneList).field_0x4;
  pAVar10 = *(AlignTerrainReplaceClass **)&this->DroneList;
  local_454 = pAVar6;
  while ((pAVar10 != pAVar6 && (bVar2 = BZ1Helper::ShouldRemoveAlignTerrainReplace(pAVar10), !bVar2)
         )) {
    pAVar10 = (AlignTerrainReplaceClass *)&pAVar10[2].NormalVec.z;
  }
  if (pAVar10 != pAVar6) {
    pAVar9 = (AlignTerrainReplaceClass *)&pAVar10[2].NormalVec.z;
    local_44c = pAVar9;
    if (pAVar9 != pAVar6) {
      do {
        bVar2 = BZ1Helper::ShouldRemoveAlignTerrainReplace(pAVar9);
        if (!bVar2) {
          pAVar6 = pAVar9;
          pAVar14 = pAVar10;
          for (iVar7 = 0xb; iVar7 != 0; iVar7 = iVar7 + -1) {
            pAVar14->AlignHandle = pAVar6->AlignHandle;
            pAVar6 = (AlignTerrainReplaceClass *)&pAVar6->NormalVec;
            pAVar14 = (AlignTerrainReplaceClass *)&pAVar14->NormalVec;
          }
          pAVar10 = (AlignTerrainReplaceClass *)&pAVar10[2].NormalVec.z;
          pAVar6 = local_454;
        }
        pAVar9 = (AlignTerrainReplaceClass *)&pAVar9[2].NormalVec.z;
      } while (pAVar9 != pAVar6);
      this = local_450;
    }
    if (pAVar10 != pAVar6) {
      sVar12 = *(int *)&(this->DroneList).field_0x4 - (int)pAVar6;
      memmove(pAVar10,pAVar6,sVar12);
      piVar3 = (int *)(sVar12 + (int)pAVar10);
      *(int **)&(this->DroneList).field_0x4 = piVar3;
      goto LAB_4fc2c471;
    }
  }
  piVar3 = *(int **)&(this->DroneList).field_0x4;
LAB_4fc2c471:
  piVar13 = *(int **)&this->DroneList;
  bVar2 = piVar13 == piVar3;
  do {
    if (bVar2) {
      return;
    }
    local_450 = (CarrierHelper *)piVar13;
    local_44c = (AlignTerrainReplaceClass *)GetTeamNum(*piVar13);
    GetPosition(*piVar13,&local_414);
    pCVar1 = local_450;
    piVar13[8] = (int)local_414.x;
    piVar13[9] = (int)local_414.y;
    piVar13[10] = (int)local_414.z;
    iVar7 = local_450->_padding_;
    local_450 = (CarrierHelper *)(((int)local_450 - *(int *)&this->DroneList) / 0x2c);
    lVar4 = GetCurHealth(iVar7);
    if ((lVar4 == -0x4d2) || (lVar5 = GetMaxHealth(iVar7), lVar5 <= lVar4)) {
      iVar7 = pCVar1->_padding_;
      lVar4 = GetCurAmmo(iVar7);
      if ((lVar4 != -0x4d2) && (lVar5 = GetMaxAmmo(iVar7), lVar4 < lVar5)) goto LAB_4fc2c4fc;
    }
    else {
LAB_4fc2c4fc:
      piVar3 = *(int **)&this->CarrierList;
      if (piVar3 != *(int **)&(this->CarrierList).field_0x4) {
        do {
          if ((((char)piVar3[0xb] != '\0') ||
              (((int)piVar3 - *(int *)&this->CarrierList) / 0x30 == *(int *)((int)pCVar1 + 8))) &&
             ((float)piVar3[2] != ___real_00000000)) {
            GetPosition(*piVar3,&local_438);
            local_440 = local_438.y - *(float *)((int)pCVar1 + 0x24);
            local_454 = (AlignTerrainReplaceClass *)(local_438.x - *(float *)((int)pCVar1 + 0x20));
            local_448 = (float)piVar3[2] * (float)piVar3[2];
            if ((local_438.z - *(float *)((int)pCVar1 + 0x28)) *
                (local_438.z - *(float *)((int)pCVar1 + 0x28)) +
                local_440 * local_440 + (float)local_454 * (float)local_454 < local_448) {
              if (piVar3[9] != 0) {
                AddHealth(pCVar1->_padding_,piVar3[9] / BZ1Helper::m_GameTPS);
              }
              if (piVar3[10] != 0) {
                AddAmmo(pCVar1->_padding_,piVar3[10] / BZ1Helper::m_GameTPS);
              }
            }
          }
          piVar3 = piVar3 + 0xc;
        } while (piVar3 != *(int **)&(this->CarrierList).field_0x4);
      }
    }
    bVar2 = IsPlayer(pCVar1->_padding_);
    if (!bVar2) {
      pAVar6 = (AlignTerrainReplaceClass *)0x0;
      iVar7 = 0;
      local_454 = (AlignTerrainReplaceClass *)0x0;
      if (*(int *)((int)pCVar1 + 0xc) == 0) {
        pCVar11 = local_450;
      }
      else {
        iVar8 = *(int *)(*(int *)((int)pCVar1 + 8) * 0x30 + *(int *)&this->CarrierList);
        bVar2 = IsAround(iVar8);
        if (bVar2) {
LAB_4fc2c7af:
          pCVar11 = local_450;
          iVar7 = DroneFindTarget(this,local_43c,(int)local_450,iVar8);
          pcVar15 = *(char **)&this->CarrierList;
          pAVar6 = (AlignTerrainReplaceClass *)
                   BZ1Helper::GetNearestObject
                             (local_43c,*(int *)(pcVar15 + *(int *)((int)pCVar1 + 8) * 0x30),
                              *(float *)(pcVar15 + *(int *)((int)pCVar1 + 8) * 0x30 + 0xc),
                              (int)local_44c,4,true,0,SUB41(pcVar15,0),SUB41(pcVar15,0),0,
                              (char *)0x0,pcVar15);
          local_454 = pAVar6;
        }
        else {
          if (*(float *)(*(int *)((int)pCVar1 + 8) * 0x30 + 4 + *(int *)&this->CarrierList) !=
              ___real_00000000) {
            GetPosition(*(int *)(*(int *)((int)pCVar1 + 8) * 0x30 + *(int *)&this->CarrierList),
                        &local_42c);
            local_448 = local_42c.y - *(float *)((int)pCVar1 + 0x24);
            iVar8 = *(int *)((int)pCVar1 + 8) * 0x30;
            local_440 = local_42c.x - *(float *)((int)pCVar1 + 0x20);
            local_444 = *(float *)(iVar8 + 4 + *(int *)&this->CarrierList);
            local_444 = local_444 * local_444;
            if ((local_42c.z - *(float *)((int)pCVar1 + 0x28)) *
                (local_42c.z - *(float *)((int)pCVar1 + 0x28)) +
                local_440 * local_440 + local_448 * local_448 <= local_444) goto LAB_4fc2c7af;
          }
          pCVar11 = local_450;
          DroneDeactivate(this,(int)local_450,true);
          if (local_455 != false) {
            GetODFName(*(int *)((int)pCVar1 + 0xc));
            FormatLogMessage(
                            "Drone %08x \'%s\' Set to DroneState: %d, Carrier Dead or Outside of Range"
                            );
          }
          pAVar6 = (AlignTerrainReplaceClass *)0x0;
        }
      }
      iVar8 = *(int *)((int)pCVar1 + 0xc);
      if (iVar8 == 0) {
        if ((*(char *)((int)pCVar1 + 0x19) != '\0') ||
           (bVar2 = IsAround(*(int *)(*(int *)((int)pCVar1 + 8) * 0x30 + *(int *)&this->CarrierList)
                            ), bVar2)) {
          for (piVar3 = *(int **)&this->CarrierList;
              piVar3 != *(int **)&(this->CarrierList).field_0x4; piVar3 = piVar3 + 0xc) {
            pAVar6 = (AlignTerrainReplaceClass *)GetTeamNum(*piVar3);
            if (pAVar6 == local_44c) {
              if ((float)piVar3[1] != ___real_00000000) {
                GetPosition(*piVar3,&local_420);
                local_448 = local_420.x - *(float *)((int)pCVar1 + 0x20);
                local_440 = local_420.z - *(float *)((int)pCVar1 + 0x28);
                local_444 = (float)piVar3[1] * (float)piVar3[1];
                if (local_444 <=
                    local_440 * local_440 +
                    local_448 * local_448 +
                    (local_420.y - *(float *)((int)pCVar1 + 0x24)) *
                    (local_420.y - *(float *)((int)pCVar1 + 0x24))) goto LAB_4fc2cc0b;
              }
              if ((piVar3[6] == 0) || (piVar3[7] < piVar3[6])) {
                DroneActivate(this,(int)pCVar11,((int)piVar3 - *(int *)&this->CarrierList) / 0x30);
                if (local_455 != false) {
                  memset(local_48,0,0x40);
                  memset(local_88,0,0x40);
                  GetODFName(unaff_EDI,unaff_ESI);
                  GetODFName(unaff_EDI,unaff_ESI);
                  pcVar15 = 
                  "Drone %08x \'%s\' INACTIVE: Set to DroneState: %d, Reassigned to Carrier: %08x \'%s\'"
                  ;
                  goto LAB_4fc2cc99;
                }
                break;
              }
            }
LAB_4fc2cc0b:
          }
        }
      }
      else if (iVar8 == 1) {
        if (iVar7 == 0) {
          if (pAVar6 == (AlignTerrainReplaceClass *)0x0) {
            if (*(int *)((int)pCVar1 + 0x10) < 1) {
              bVar2 = DroneRecall(this,(int)pCVar11);
              if ((bVar2) && (local_455 != false)) {
                memset(local_c8,0,0x40);
                memset(local_108,0,0x40);
                GetODFName(unaff_EDI,unaff_ESI);
                GetODFName(unaff_EDI,unaff_ESI);
                FormatLogMessage("Drone %08x \'%s\' IDLE: Drone Recalled, Carrier: %08x \'%s\'");
              }
            }
            else {
              *(int *)((int)pCVar1 + 0x10) = *(int *)((int)pCVar1 + 0x10) + -1;
            }
          }
          else {
            iVar7 = (int)pCVar11 * 0x2c;
            SetIndependence(*(int *)(iVar7 + *(int *)&this->DroneList),1);
            Defend2(*(int *)(iVar7 + *(int *)&this->DroneList),
                    *(int *)(*(int *)(iVar7 + 8 + *(int *)&this->DroneList) * 0x30 +
                            *(int *)&this->CarrierList),1);
            *(undefined4 *)(iVar7 + 0xc + *(int *)&this->DroneList) = 3;
            if (local_455 != false) {
              memset(local_148,0,0x40);
              memset(local_188,0,0x40);
              GetODFName(unaff_EDI,unaff_ESI);
              GetODFName(unaff_EDI,unaff_ESI);
              pcVar15 = "Drone %08x \'%s\' IDLE: Set to DroneState %d, Carrier: %08x \'%s\'";
              goto LAB_4fc2cc99;
            }
          }
        }
        else {
          DroneAttack(this,(int)pCVar11,iVar7,(int)local_44c);
          if (local_455 != false) {
            memset(local_1c8,0,0x40);
            memset(local_248,0,0x40);
            memset(local_208,0,0x40);
            GetODFName(unaff_EDI,unaff_ESI);
            GetODFName(unaff_EDI,unaff_ESI);
            GetODFName(unaff_EDI,unaff_ESI);
            pcVar15 = 
            "Drone %08x \'%s\' IDLE: Set to DroneState %d, Target: %08x \'%s\', Carrier: %08x \'%s\'"
            ;
LAB_4fc2c9e7:
            FormatLogMessage(pcVar15);
          }
        }
      }
      else if (iVar8 == 2) {
        bVar2 = IsAlive((int *)((int)pCVar1 + 4));
        if ((!bVar2) && (DroneIdle(this,(int)pCVar11), local_455 != false)) {
          memset(local_288,0,0x40);
          memset(local_2c8,0,0x40);
          GetODFName(unaff_EDI,unaff_ESI);
          GetODFName(unaff_EDI,unaff_ESI);
          pcVar15 = "Drone %08x \'%s\' ATTACKING: Set to DroneState %d, Carrier: %08x \'%s\'";
LAB_4fc2cc99:
          FormatLogMessage(pcVar15);
        }
      }
      else if ((iVar8 == 3) && (bVar2 = IsAlive((int *)((int)pCVar1 + 4)), !bVar2)) {
        if (iVar7 == 0) {
          if ((local_454 == (AlignTerrainReplaceClass *)0x0) &&
             (DroneIdle(this,(int)pCVar11), local_455 != false)) {
            memset(local_308,0,0x40);
            memset(local_348,0,0x40);
            GetODFName(unaff_EDI,unaff_ESI);
            GetODFName(unaff_EDI,unaff_ESI);
            pcVar15 = "Drone %08x \'%s\' DEFENDING: Set to DroneState %d, Carrier: %08x \'%s\'";
            goto LAB_4fc2cc99;
          }
        }
        else {
          DroneAttack(this,(int)pCVar11,iVar7,(int)local_44c);
          if (local_455 != false) {
            memset(local_388,0,0x40);
            memset(local_408,0,0x40);
            memset(local_3c8,0,0x40);
            GetODFName(unaff_EDI,unaff_ESI);
            GetODFName(unaff_EDI,unaff_ESI);
            GetODFName(unaff_EDI,unaff_ESI);
            pcVar15 = 
            "Drone %08x \'%s\' DEFENDING: Set to DroneState %d, Target: %08x \'%s\', Carrier: %08x \'%s\'"
            ;
            goto LAB_4fc2c9e7;
          }
        }
      }
    }
    piVar13 = (int *)((int)pCVar1 + 0x2c);
    bVar2 = piVar13 == *(int **)&(this->DroneList).field_0x4;
  } while( true );
}


// ---------------------------------------------------------------------
// CarrierHelper::PreOrdnanceHit  @ 4fc2ccce  lines 478-505


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
// CarrierHelper::DroneFindTarget  @ 4fc2cde4  lines 511-562


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
// CarrierHelper::DroneRecall  @ 4fc2cf14  lines 566-591


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
// CarrierHelper::DroneActivate  @ 4fc2d08c  lines 595-600


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
// CarrierHelper::DroneDeactivate  @ 4fc2d0d0  lines 604-612


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
// CarrierHelper::DroneIdle  @ 4fc2d11b  lines 616-622


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
// CarrierHelper::DroneAttack  @ 4fc2d17c  lines 626-637


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

