// Reconstructed by Ghidra from Strategy02.dll + Strategy02.pdb
// Original source file: /e:/github/vsr_dll_source/missions/vsrcore/carrierhelper.cpp
// Functions are ordered by original source line. This is decompiler
// output, not the author's source: names/types come from the PDB,
// local variable names and control flow are reconstructed.

// ---------------------------------------------------------------------
// `dynamic_initializer_for_'TempCarrierBuffer''  @ 4fc0157e  lines 8-8

void __cdecl _dynamic_initializer_for__TempCarrierBuffer__(void)

{
  atexit(_dynamic_atexit_destructor_for__TempCarrierBuffer__);
  return;
}


// ---------------------------------------------------------------------
// `dynamic_initializer_for_'TempDroneBuffer''  @ 4fc0158a  lines 9-9

void __cdecl _dynamic_initializer_for__TempDroneBuffer__(void)

{
  atexit(_dynamic_atexit_destructor_for__TempDroneBuffer__);
  return;
}


// ---------------------------------------------------------------------
// CarrierHelper::~CarrierHelper  @ 4fc17dd0  lines 16-17

void __thiscall CarrierHelper::~CarrierHelper(CarrierHelper *this)

{
  this->vfptr = (int)vftable;
  std::
  vector<UtilityShipHelper::UtilityShipClass,std::allocator<UtilityShipHelper::UtilityShipClass>_>::
  _Tidy((vector<UtilityShipHelper::UtilityShipClass,std::allocator<UtilityShipHelper::UtilityShipClass>_>
         *)&this->DroneList);
  std::vector<CarrierHelper::CarrierClass,std::allocator<CarrierHelper::CarrierClass>_>::_Tidy
            (&this->CarrierList);
  return;
}


// ---------------------------------------------------------------------
// CarrierHelper::Load  @ 4fc17dea  lines 20-44

bool __thiscall CarrierHelper::Load(CarrierHelper *this,bool param_1)

{
  vector<CarrierHelper::CarrierClass,std::allocator<CarrierHelper::CarrierClass>_>
  *_Udefault_or_fill;
  bool bVar1;
  CarrierHelper *extraout_ECX;
  CarrierHelper *this_00;
  vector<CarrierHelper::DroneClass,std::allocator<CarrierHelper::DroneClass>_> *_Udefault_or_fill_00
  ;
  CarrierHelper *size;
  
  _Udefault_or_fill = &this->CarrierList;
  this_00 = this;
  size = this;
  if (_Udefault_or_fill != &TempCarrierBuffer) {
    std::vector<CarrierHelper::CarrierClass,std::allocator<CarrierHelper::CarrierClass>_>::
    _Assign_range<CarrierHelper::CarrierClass_*>
              ((vector<CarrierHelper::CarrierClass,std::allocator<CarrierHelper::CarrierClass>_> *)
               this,*(CarrierClass **)_Udefault_or_fill,
               *(CarrierClass **)&(this->CarrierList).field_0x4,SUB41(this,0));
    this_00 = extraout_ECX;
  }
  _Udefault_or_fill_00 = &this->DroneList;
  if (_Udefault_or_fill_00 != &TempDroneBuffer) {
    std::vector<CarrierHelper::DroneClass,std::allocator<CarrierHelper::DroneClass>_>::
    _Assign_range<CarrierHelper::DroneClass_*>
              ((vector<CarrierHelper::DroneClass,std::allocator<CarrierHelper::DroneClass>_> *)
               this_00,*(DroneClass **)_Udefault_or_fill_00,
               *(DroneClass **)&(this->DroneList).field_0x4,SUB41(size,0));
  }
  size = (CarrierHelper *)0x0;
  bVar1 = Read((int *)&size,1);
  std::vector<CarrierHelper::CarrierClass,std::allocator<CarrierHelper::CarrierClass>_>::
  _Resize<<lambda_87c6343aa49b10f10e6fc064335a8cab>_>
            (_Udefault_or_fill,(uint)size,
             (<lambda_87c6343aa49b10f10e6fc064335a8cab>)_Udefault_or_fill);
  if (size == (CarrierHelper *)0x0) {
LAB_4fc17e6a:
    size = (CarrierHelper *)0x0;
    if (bVar1 != false) goto LAB_4fc17e72;
  }
  else {
    if ((!bVar1) || (bVar1 = Read(*(void **)_Udefault_or_fill,(int)size * 0x30), !bVar1)) {
      bVar1 = false;
      goto LAB_4fc17e6a;
    }
LAB_4fc17e72:
    size = (CarrierHelper *)0x0;
    bVar1 = Read((int *)&size,1);
    if (bVar1) {
      bVar1 = true;
      goto LAB_4fc17e8a;
    }
  }
  bVar1 = false;
LAB_4fc17e8a:
  std::
  vector<UtilityShipHelper::UtilityShipClass,std::allocator<UtilityShipHelper::UtilityShipClass>_>::
  _Resize<<lambda_c8a4f4cad98f6de524d7658fab4f9ded>_>
            ((vector<UtilityShipHelper::UtilityShipClass,std::allocator<UtilityShipHelper::UtilityShipClass>_>
              *)_Udefault_or_fill_00,(uint)size,
             (<lambda_c8a4f4cad98f6de524d7658fab4f9ded>)_Udefault_or_fill_00);
  if (size != (CarrierHelper *)0x0) {
    if ((bVar1 == false) || (bVar1 = Read(*(void **)_Udefault_or_fill_00,(int)size * 0x2c), !bVar1))
    {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
  }
  return bVar1;
}


// ---------------------------------------------------------------------
// CarrierHelper::PostLoad  @ 4fc17ebf  lines 47-86

bool __thiscall CarrierHelper::PostLoad(CarrierHelper *this,bool param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int fmtarg1;
  int *piVar4;
  int fmtarg1_00;
  
  for (piVar4 = *(int **)&this->CarrierList; piVar4 != *(int **)&(this->CarrierList).field_0x4;
      piVar4 = piVar4 + 0xc) {
    ConvertHandles(piVar4,1);
  }
  for (piVar4 = *(int **)&this->DroneList; piVar4 != *(int **)&(this->DroneList).field_0x4;
      piVar4 = piVar4 + 0xb) {
    ConvertHandles(piVar4,1);
    ConvertHandles(piVar4 + 1,1);
  }
  fmtarg1_00 = 0;
  iVar2 = (*(int *)&(this->CarrierList).field_0x4 - *(int *)&this->CarrierList) / 0x30;
  iVar3 = (int)(TempCarrierBuffer._4_4_ - TempCarrierBuffer._0_4_) / 0x30;
  if (iVar3 == iVar2) {
    iVar3 = 0;
    if (0 < iVar2) {
      iVar2 = 0;
      do {
        bVar1 = ::operator==((CarrierClass *)(TempCarrierBuffer._0_4_ + iVar2),
                             (CarrierClass *)(*(int *)&this->CarrierList + iVar2));
        if (!bVar1) {
          FormatLogMessage("CarrierList Index Mismatch: %d",iVar3);
          break;
        }
        iVar3 = iVar3 + 1;
        iVar2 = iVar2 + 0x30;
      } while (iVar3 < (*(int *)&(this->CarrierList).field_0x4 - *(int *)&this->CarrierList) / 0x30)
      ;
    }
  }
  else {
    FormatLogMessage("CarrierList Size Mismatch! Old: %d New: %d",iVar3,iVar2);
  }
  iVar2 = *(int *)&this->DroneList;
  iVar3 = (*(int *)&(this->DroneList).field_0x4 - iVar2) / 0x2c;
  fmtarg1 = (int)(TempDroneBuffer._4_4_ - TempDroneBuffer._0_4_) / 0x2c;
  if (fmtarg1 == iVar3) {
    if (0 < iVar3) {
      iVar3 = 0;
      do {
        bVar1 = ::operator==((DroneClass *)(iVar3 + TempDroneBuffer._0_4_),
                             (DroneClass *)(iVar3 + iVar2));
        if (!bVar1) {
          FormatLogMessage("DroneList Index Mismatch: %d",fmtarg1_00);
          return true;
        }
        fmtarg1_00 = fmtarg1_00 + 1;
        iVar2 = *(int *)&this->DroneList;
        iVar3 = iVar3 + 0x2c;
      } while (fmtarg1_00 < (*(int *)&(this->DroneList).field_0x4 - iVar2) / 0x2c);
    }
  }
  else {
    FormatLogMessage("DroneList Size Mismatch! Old: %d New: %d",fmtarg1,iVar3);
  }
  return true;
}


// ---------------------------------------------------------------------
// CarrierHelper::Save  @ 4fc17feb  lines 89-106

bool __thiscall CarrierHelper::Save(CarrierHelper *this,bool param_1)

{
  bool bVar1;
  int size;
  
  size = (*(int *)&(this->CarrierList).field_0x4 - *(int *)&this->CarrierList) / 0x30;
  bVar1 = Write(&size,1);
  if (size != 0) {
    if ((bVar1) && (bVar1 = Write(*(void **)&this->CarrierList,size * 0x30), bVar1)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
  }
  size = (*(int *)&(this->DroneList).field_0x4 - *(int *)&this->DroneList) / 0x2c;
  if ((bVar1 == false) || (bVar1 = Write(&size,1), !bVar1)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (size != 0) {
    if ((bVar1 != false) && (bVar1 = Write(*(void **)&this->DroneList,size * 0x2c), bVar1)) {
      return true;
    }
    bVar1 = false;
  }
  return bVar1;
}


// ---------------------------------------------------------------------
// CarrierHelper::AddCarrierDroneObject  @ 4fc1808e  lines 109-185

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall
CarrierHelper::AddCarrierDroneObject
          (CarrierHelper *this,int h,int Team,char *TempODF1,char *TempODF2,char *ODFName)

{
  vector<CarrierHelper::DroneClass,std::allocator<CarrierHelper::DroneClass>_> *_Udefault_or_fill;
  int iVar1;
  bool bVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
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
  local_a0 = TempODF1;
  local_a4 = TempODF2;
  _Udefault_or_fill = &this->DroneList;
  local_b8 = ODFName;
  piVar3 = *(int **)_Udefault_or_fill;
  local_b4 = h;
  for (; piVar3 != *(int **)&(this->DroneList).field_0x4; piVar3 = piVar3 + 0xb) {
    if (*piVar3 == h) {
      return;
    }
  }
  std::
  vector<UtilityShipHelper::UtilityShipClass,std::allocator<UtilityShipHelper::UtilityShipClass>_>::
  _Resize<<lambda_c8a4f4cad98f6de524d7658fab4f9ded>_>
            ((vector<UtilityShipHelper::UtilityShipClass,std::allocator<UtilityShipHelper::UtilityShipClass>_>
              *)_Udefault_or_fill,
             (*(int *)&(this->DroneList).field_0x4 - *(int *)_Udefault_or_fill) / 0x2c + 1,
             (<lambda_c8a4f4cad98f6de524d7658fab4f9ded>)_Udefault_or_fill);
  piVar6 = (int *)(*(int *)_Udefault_or_fill + -0x2c +
                  ((*(int *)&(this->DroneList).field_0x4 - *(int *)_Udefault_or_fill) / 0x2c) * 0x2c
                  );
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
         (iVar4 = GetTeamNum(*piVar3), iVar4 == Team)) {
        local_bc = ((int)piVar3 - *(int *)&this->CarrierList) / 0x30;
        local_b0 = local_a8;
      }
      piVar3 = piVar3 + 0xc;
      piVar6 = local_ac;
    } while (piVar3 != *(int **)&(this->CarrierList).field_0x4);
  }
  *piVar6 = local_b4;
  if (-1 < local_bc) {
    iVar1 = *(int *)&this->CarrierList;
    local_b4 = local_bc * 0x30;
    local_ac = *(int **)(local_b4 + 4 + iVar1);
    if ((((float)local_ac == 0.0) || (local_b0 < (float)local_ac)) &&
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
          bVar2 = OpenODF2(local_84);
          if (((bVar2) &&
              (iVar5 = GetODFString(local_84,(char *)0x0,"DispenserClass","objectClass",0x40,
                                    local_44,(char *)0x0), iVar5 != 0)) &&
             (iVar5 = _stricmp(local_b8,local_44), iVar5 == 0)) {
            local_b8 = (char *)0x0;
            piVar6[5] = iVar4;
            GetODFInt(local_84,(char *)0x0,"WeaponClass","localAmmo",(int *)&local_b8,0);
            if (0 < (int)local_b8) {
              *(undefined1 *)(piVar6 + 6) = 1;
            }
            break;
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 < 5);
      }
      goto LAB_4fc18338;
    }
  }
  DroneDeactivate(this,(*(int *)&(this->DroneList).field_0x4 - *(int *)&this->DroneList) / 0x2c + -1
                  ,false);
LAB_4fc18338:
  GetODFFloat(local_a0,local_a4,"DroneClass","RandomTargetRange",(float *)(piVar6 + 7),0.0);
  GetODFBool(local_a0,local_a4,"DroneClass","canSwitchCarrier",(bool *)((int)piVar6 + 0x19),true);
  return;
}


// ---------------------------------------------------------------------
// CarrierHelper::AddCarrierObject  @ 4fc18391  lines 188-223

void __thiscall
CarrierHelper::AddCarrierObject(CarrierHelper *this,int h,char *TempODF1,char *TempODF2)

{
  vector<CarrierHelper::CarrierClass,std::allocator<CarrierHelper::CarrierClass>_>
  *_Udefault_or_fill;
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  _Udefault_or_fill = &this->CarrierList;
  piVar1 = *(int **)_Udefault_or_fill;
  if (piVar1 != *(int **)&(this->CarrierList).field_0x4) {
    do {
      if (*piVar1 == h) {
        return;
      }
      piVar1 = piVar1 + 0xc;
    } while (piVar1 != *(int **)&(this->CarrierList).field_0x4);
  }
  std::vector<CarrierHelper::CarrierClass,std::allocator<CarrierHelper::CarrierClass>_>::
  _Resize<<lambda_87c6343aa49b10f10e6fc064335a8cab>_>
            (_Udefault_or_fill,
             (*(int *)&(this->CarrierList).field_0x4 - *(int *)_Udefault_or_fill) / 0x30 + 1,
             (<lambda_87c6343aa49b10f10e6fc064335a8cab>)_Udefault_or_fill);
  piVar3 = (int *)(*(int *)_Udefault_or_fill + -0x30 +
                  ((*(int *)&(this->CarrierList).field_0x4 - *(int *)_Udefault_or_fill) / 0x30) *
                  0x30);
  memset(piVar3,0,0x30);
  GetODFFloat(TempODF1,TempODF2,"CarrierClass","controlRange",(float *)(piVar3 + 1),0.0);
  GetODFFloat(TempODF1,TempODF2,"CarrierClass","defendRange",(float *)(piVar3 + 3),(float)piVar3[1])
  ;
  GetODFFloat(TempODF1,TempODF2,"CarrierClass","recallRange",(float *)(piVar3 + 4),50.0);
  GetODFFloat(TempODF1,TempODF2,"CarrierClass","droneIdleTime",(float *)(piVar3 + 5),120.0);
  piVar1 = piVar3 + 6;
  GetODFInt(TempODF1,TempODF2,"CarrierClass","maxDrones",piVar1,0);
  GetODFInt(TempODF1,TempODF2,"CarrierClass","minAttackForce",piVar3 + 8,0);
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
  GetODFFloat(TempODF1,TempODF2,"CarrierClass","repairRange",(float *)(piVar3 + 2),100.0);
  GetODFLong(TempODF1,TempODF2,"CarrierClass","healthRepairAmount",piVar3 + 9,0);
  GetODFLong(TempODF1,TempODF2,"CarrierClass","ammoRepairAmount",piVar3 + 10,0);
  GetODFBool(TempODF1,TempODF2,"CarrierClass","serviceAllies",(bool *)(piVar3 + 0xb),false);
  *piVar3 = h;
  return;
}


// ---------------------------------------------------------------------
// CarrierHelper::Execute  @ 4fc1852f  lines 226-475

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall CarrierHelper::Execute(CarrierHelper *this,BZ1Helper *bz1Helper)

{
  float fVar1;
  CarrierHelper *pCVar2;
  BZ1Helper *this_00;
  bool bVar3;
  uint *puVar4;
  long lVar5;
  long lVar6;
  char *pcVar7;
  CarrierHelper *pCVar8;
  int iVar9;
  int extraout_ECX;
  int iVar10;
  AlignTerrainReplaceClass *pAVar11;
  AlignTerrainReplaceClass *pAVar12;
  int iVar13;
  AlignTerrainReplaceClass *pAVar14;
  uint *puVar15;
  size_t sVar16;
  AlignTerrainReplaceClass *pAVar17;
  int *piVar18;
  float fVar19;
  uint uVar20;
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
  char local_408 [64];
  char local_3c8 [64];
  char local_388 [64];
  char local_348 [64];
  char local_308 [64];
  char local_2c8 [64];
  char local_288 [64];
  char local_248 [64];
  char local_208 [64];
  char local_1c8 [64];
  char local_188 [64];
  char local_148 [64];
  char local_108 [64];
  char local_c8 [64];
  char local_88 [64];
  char local_48 [68];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)auStack_458;
  local_43c = bz1Helper;
  pAVar14 = *(AlignTerrainReplaceClass **)&(this->CarrierList).field_0x4;
  pAVar12 = *(AlignTerrainReplaceClass **)&this->CarrierList;
  local_451 = BZ1Helper::Logging;
  local_448 = (double)CONCAT44(local_448._4_4_,pAVar14);
  local_44c = this;
  while ((pAVar12 != pAVar14 &&
         (bVar3 = BZ1Helper::ShouldRemoveAlignTerrainReplace(pAVar12), !bVar3))) {
    pAVar12 = pAVar12 + 3;
  }
  if (pAVar12 != pAVar14) {
    pAVar11 = pAVar12 + 3;
    local_450 = pAVar11;
    if (pAVar11 != pAVar14) {
      do {
        bVar3 = BZ1Helper::ShouldRemoveAlignTerrainReplace(pAVar11);
        if (!bVar3) {
          pAVar14 = pAVar11;
          pAVar17 = pAVar12;
          for (iVar9 = 0xc; iVar9 != 0; iVar9 = iVar9 + -1) {
            pAVar17->AlignHandle = pAVar14->AlignHandle;
            pAVar14 = (AlignTerrainReplaceClass *)&pAVar14->NormalVec;
            pAVar17 = (AlignTerrainReplaceClass *)&pAVar17->NormalVec;
          }
          pAVar12 = pAVar12 + 3;
          pAVar14 = local_448._0_4_;
        }
        pAVar11 = pAVar11 + 3;
        this = local_44c;
      } while (pAVar11 != pAVar14);
    }
    if (pAVar12 != pAVar14) {
      sVar16 = *(int *)&(this->CarrierList).field_0x4 - (int)pAVar14;
      memmove(pAVar12,pAVar14,sVar16);
      *(size_t *)&(this->CarrierList).field_0x4 = sVar16 + (int)pAVar12;
    }
  }
  pAVar14 = *(AlignTerrainReplaceClass **)&(this->DroneList).field_0x4;
  pAVar12 = *(AlignTerrainReplaceClass **)&this->DroneList;
  local_450 = pAVar14;
  while ((pAVar12 != pAVar14 &&
         (bVar3 = BZ1Helper::ShouldRemoveAlignTerrainReplace(pAVar12), !bVar3))) {
    pAVar12 = (AlignTerrainReplaceClass *)&pAVar12[2].NormalVec.z;
  }
  if (pAVar12 != pAVar14) {
    pAVar11 = (AlignTerrainReplaceClass *)&pAVar12[2].NormalVec.z;
    local_448 = (double)CONCAT44(local_448._4_4_,pAVar11);
    if (pAVar11 != pAVar14) {
      do {
        bVar3 = BZ1Helper::ShouldRemoveAlignTerrainReplace(pAVar11);
        if (!bVar3) {
          pAVar14 = pAVar11;
          pAVar17 = pAVar12;
          for (iVar9 = 0xb; iVar9 != 0; iVar9 = iVar9 + -1) {
            pAVar17->AlignHandle = pAVar14->AlignHandle;
            pAVar14 = (AlignTerrainReplaceClass *)&pAVar14->NormalVec;
            pAVar17 = (AlignTerrainReplaceClass *)&pAVar17->NormalVec;
          }
          pAVar12 = (AlignTerrainReplaceClass *)&pAVar12[2].NormalVec.z;
          pAVar14 = local_450;
        }
        pAVar11 = (AlignTerrainReplaceClass *)&pAVar11[2].NormalVec.z;
        this = local_44c;
      } while (pAVar11 != pAVar14);
    }
    if (pAVar12 != pAVar14) {
      sVar16 = *(int *)&(this->DroneList).field_0x4 - (int)pAVar14;
      memmove(pAVar12,pAVar14,sVar16);
      puVar4 = (uint *)(sVar16 + (int)pAVar12);
      *(uint **)&(this->DroneList).field_0x4 = puVar4;
      goto LAB_4fc1864a;
    }
  }
  puVar4 = *(uint **)&(this->DroneList).field_0x4;
LAB_4fc1864a:
  puVar15 = *(uint **)&this->DroneList;
  bVar3 = puVar15 == puVar4;
  do {
    if (bVar3) {
      return;
    }
    local_450 = (AlignTerrainReplaceClass *)puVar15;
    local_44c = (CarrierHelper *)GetTeamNum(*puVar15);
    GetPosition(*puVar15,&local_438);
    pAVar14 = local_450;
    puVar15[8] = (uint)local_438.x;
    puVar15[9] = (uint)local_438.y;
    puVar15[10] = (uint)local_438.z;
    uVar20 = *(uint *)local_450;
    local_450 = (AlignTerrainReplaceClass *)(((int)local_450 - *(int *)&this->DroneList) / 0x2c);
    lVar5 = GetCurHealth(uVar20);
    if ((lVar5 == -0x4d2) || (lVar6 = GetMaxHealth(uVar20), lVar6 <= lVar5)) {
      uVar20 = *(uint *)pAVar14;
      lVar5 = GetCurAmmo(uVar20);
      if ((lVar5 != -0x4d2) && (lVar6 = GetMaxAmmo(uVar20), lVar5 < lVar6)) goto LAB_4fc186d5;
    }
    else {
LAB_4fc186d5:
      for (piVar18 = *(int **)&this->CarrierList; piVar18 != *(int **)&(this->CarrierList).field_0x4
          ; piVar18 = piVar18 + 0xc) {
        if ((((char)piVar18[0xb] != '\0') ||
            (((int)piVar18 - *(int *)&this->CarrierList) / 0x30 == *(uint *)((int)pAVar14 + 8))) &&
           ((float)piVar18[2] != 0.0)) {
          GetPosition(*piVar18,&local_42c);
          local_448 = (double)(float)piVar18[2];
          fVar19 = GetDistance3DSquared((Vector *)((int)pAVar14 + 0x20),&local_42c);
          fVar1 = (float)((float10)local_448 * (float10)local_448);
          local_448 = (double)CONCAT44(local_448._4_4_,fVar1);
          if (fVar19 < fVar1) {
            if (piVar18[9] != 0) {
              AddHealth(*(uint *)pAVar14,piVar18[9] / BZ1Helper::m_GameTPS);
            }
            if (piVar18[10] != 0) {
              AddAmmo(*(uint *)pAVar14,piVar18[10] / BZ1Helper::m_GameTPS);
            }
          }
        }
      }
    }
    bVar3 = IsPlayer(*(uint *)pAVar14);
    if (!bVar3) {
      iVar9 = 0;
      iVar13 = 0;
      if (*(uint *)((int)pAVar14 + 0xc) != 0) {
        iVar10 = *(int *)(*(uint *)((int)pAVar14 + 8) * 0x30 + *(int *)&this->CarrierList);
        bVar3 = IsAround(iVar10);
        if (bVar3) {
LAB_4fc1883c:
          this_00 = local_43c;
          iVar9 = DroneFindTarget(this,local_43c,(int)local_450,iVar10);
          pcVar7 = *(char **)&this->CarrierList;
          iVar13 = BZ1Helper::GetNearestObject
                             (this_00,*(int *)(pcVar7 + *(uint *)((int)pAVar14 + 8) * 0x30),
                              *(float *)(pcVar7 + *(uint *)((int)pAVar14 + 8) * 0x30 + 0xc),
                              (int)local_44c,4,true,0,SUB41(pcVar7,0),SUB41(pcVar7,0),0,(char *)0x0,
                              pcVar7);
        }
        else {
          if (*(float *)(*(uint *)((int)pAVar14 + 8) * 0x30 + 4 + *(int *)&this->CarrierList) != 0.0
             ) {
            GetPosition(*(int *)(*(uint *)((int)pAVar14 + 8) * 0x30 + *(int *)&this->CarrierList),
                        &local_420);
            local_448 = (double)*(float *)(*(uint *)((int)pAVar14 + 8) * 0x30 + 4 +
                                          *(int *)&this->CarrierList);
            fVar19 = GetDistance3DSquared((Vector *)((int)pAVar14 + 0x20),&local_420);
            fVar1 = (float)((float10)local_448 * (float10)local_448);
            local_448 = (double)CONCAT44(local_448._4_4_,fVar1);
            iVar10 = extraout_ECX;
            if (fVar19 <= fVar1) goto LAB_4fc1883c;
          }
          DroneDeactivate(this,(int)local_450,true);
          if (local_451 != false) {
            uVar20 = *(uint *)((int)pAVar14 + 0xc);
            pcVar7 = GetODFName(*(uint *)pAVar14);
            FormatLogMessage("Drone %08x \'%s\' Set to DroneState: %d, Carrier Dead or Outside of Range"
                             ,*(uint *)pAVar14,pcVar7,uVar20);
          }
        }
      }
      uVar20 = *(uint *)((int)pAVar14 + 0xc);
      if (uVar20 == 0) {
        if (((*(char *)((int)pAVar14 + 0x19) != '\0') ||
            (bVar3 = IsAround(*(int *)(*(uint *)((int)pAVar14 + 8) * 0x30 +
                                      *(int *)&this->CarrierList)), bVar3)) &&
           (pCVar2 = local_44c, piVar18 = *(int **)&this->CarrierList,
           piVar18 != *(int **)&(this->CarrierList).field_0x4)) {
          do {
            pCVar8 = (CarrierHelper *)GetTeamNum(*piVar18);
            if (pCVar8 == pCVar2) {
              if ((float)piVar18[1] != 0.0) {
                GetPosition(*piVar18,&local_414);
                local_448 = (double)(float)piVar18[1];
                fVar19 = GetDistance3DSquared((Vector *)((int)pAVar14 + 0x20),&local_414);
                fVar1 = (float)((float10)local_448 * (float10)local_448);
                local_448 = (double)CONCAT44(local_448._4_4_,fVar1);
                if (fVar1 <= fVar19) goto LAB_4fc18d63;
              }
              if ((piVar18[6] == 0) || (piVar18[7] < piVar18[6])) {
                DroneActivate(this,(int)local_450,((int)piVar18 - *(int *)&this->CarrierList) / 0x30
                             );
                if (local_451 != false) {
                  memset(local_48,0,0x40);
                  memset(local_88,0,0x40);
                  GetODFName(*(uint *)pAVar14,local_48);
                  GetODFName(*piVar18,local_88);
                  pcVar7 = 
                  "Drone %08x \'%s\' INACTIVE: Set to DroneState: %d, Reassigned to Carrier: %08x \'%s\'"
                  ;
                  goto LAB_4fc18df0;
                }
                break;
              }
            }
LAB_4fc18d63:
            piVar18 = piVar18 + 0xc;
          } while (piVar18 != *(int **)&(this->CarrierList).field_0x4);
        }
      }
      else if (uVar20 == 1) {
        if (iVar9 == 0) {
          if (iVar13 == 0) {
            if ((int)*(uint *)((int)pAVar14 + 0x10) < 1) {
              bVar3 = DroneRecall(this,(int)local_450);
              if ((bVar3) && (local_451 != false)) {
                memset(local_c8,0,0x40);
                memset(local_108,0,0x40);
                GetODFName(*(uint *)pAVar14,local_c8);
                GetODFName(*(int *)(*(uint *)((int)pAVar14 + 8) * 0x30 + *(int *)&this->CarrierList)
                           ,local_108);
                FormatLogMessage("Drone %08x \'%s\' IDLE: Drone Recalled, Carrier: %08x \'%s\'",
                                 *(uint *)pAVar14,local_c8,
                                 *(uint *)(*(uint *)((int)pAVar14 + 8) * 0x30 +
                                          *(int *)&this->CarrierList),local_108);
              }
            }
            else {
              *(uint *)((int)pAVar14 + 0x10) = *(uint *)((int)pAVar14 + 0x10) - 1;
            }
          }
          else {
            iVar9 = (int)local_450 * 0x2c;
            SetIndependence(*(int *)(iVar9 + *(int *)&this->DroneList),1);
            Defend2(*(int *)(iVar9 + *(int *)&this->DroneList),
                    *(int *)(*(int *)(iVar9 + 8 + *(int *)&this->DroneList) * 0x30 +
                            *(int *)&this->CarrierList),1);
            *(undefined4 *)(iVar9 + 0xc + *(int *)&this->DroneList) = 3;
            if (local_451 != false) {
              memset(local_148,0,0x40);
              memset(local_188,0,0x40);
              GetODFName(*(uint *)pAVar14,local_148);
              GetODFName(*(int *)(*(uint *)((int)pAVar14 + 8) * 0x30 + *(int *)&this->CarrierList),
                         local_188);
              pcVar7 = "Drone %08x \'%s\' IDLE: Set to DroneState %d, Carrier: %08x \'%s\'";
              goto LAB_4fc18df0;
            }
          }
        }
        else {
          DroneAttack(this,(int)local_450,iVar9,(int)local_44c);
          if (local_451 != false) {
            memset(local_1c8,0,0x40);
            memset(local_248,0,0x40);
            memset(local_208,0,0x40);
            GetODFName(*(uint *)pAVar14,local_1c8);
            GetODFName(*(int *)(*(uint *)((int)pAVar14 + 8) * 0x30 + *(int *)&this->CarrierList),
                       local_248);
            GetODFName(iVar9,local_208);
            pcVar7 = 
            "Drone %08x \'%s\' IDLE: Set to DroneState %d, Target: %08x \'%s\', Carrier: %08x \'%s\'"
            ;
LAB_4fc18b59:
            FormatLogMessage(pcVar7);
          }
        }
      }
      else if (uVar20 == 2) {
        bVar3 = IsAlive((int *)((int)pAVar14 + 4));
        if ((!bVar3) && (DroneIdle(this,(int)local_450), local_451 != false)) {
          memset(local_288,0,0x40);
          memset(local_2c8,0,0x40);
          GetODFName(*(uint *)pAVar14,local_288);
          GetODFName(*(int *)(*(uint *)((int)pAVar14 + 8) * 0x30 + *(int *)&this->CarrierList),
                     local_2c8);
          pcVar7 = "Drone %08x \'%s\' ATTACKING: Set to DroneState %d, Carrier: %08x \'%s\'";
LAB_4fc18df0:
          FormatLogMessage(pcVar7);
        }
      }
      else if ((uVar20 == 3) && (bVar3 = IsAlive((int *)((int)pAVar14 + 4)), !bVar3)) {
        if (iVar9 == 0) {
          if ((iVar13 == 0) && (DroneIdle(this,(int)local_450), local_451 != false)) {
            memset(local_308,0,0x40);
            memset(local_348,0,0x40);
            GetODFName(*(uint *)pAVar14,local_308);
            GetODFName(*(int *)(*(uint *)((int)pAVar14 + 8) * 0x30 + *(int *)&this->CarrierList),
                       local_348);
            pcVar7 = "Drone %08x \'%s\' DEFENDING: Set to DroneState %d, Carrier: %08x \'%s\'";
            goto LAB_4fc18df0;
          }
        }
        else {
          DroneAttack(this,(int)local_450,iVar9,(int)local_44c);
          if (local_451 != false) {
            memset(local_388,0,0x40);
            memset(local_408,0,0x40);
            memset(local_3c8,0,0x40);
            GetODFName(*(uint *)pAVar14,local_388);
            GetODFName(*(int *)(*(uint *)((int)pAVar14 + 8) * 0x30 + *(int *)&this->CarrierList),
                       local_408);
            GetODFName(iVar9,local_3c8);
            pcVar7 = 
            "Drone %08x \'%s\' DEFENDING: Set to DroneState %d, Target: %08x \'%s\', Carrier: %08x \'%s\'"
            ;
            goto LAB_4fc18b59;
          }
        }
      }
    }
    puVar15 = (uint *)((int)pAVar14 + 0x2c);
    bVar3 = puVar15 == *(uint **)&(this->DroneList).field_0x4;
  } while( true );
}


// ---------------------------------------------------------------------
// CarrierHelper::PreOrdnanceHit  @ 4fc18e25  lines 478-505

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall
CarrierHelper::PreOrdnanceHit
          (CarrierHelper *this,int shooterHandle,int victimHandle,int ordnanceTeam,
          char *pOrdnanceODF)

{
  uint *puVar1;
  undefined1 auStack_88 [3];
  bool local_85;
  char local_84 [64];
  char local_44 [64];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)auStack_88;
  local_85 = BZ1Helper::Logging;
  if (((*(int *)&(this->CarrierList).field_0x4 - *(int *)&this->CarrierList) / 0x30 != 0) &&
     (puVar1 = *(uint **)&this->DroneList, puVar1 != *(uint **)&(this->DroneList).field_0x4)) {
    do {
      if ((victimHandle == *(int *)(puVar1[2] * 0x30 + *(int *)&this->CarrierList)) &&
         ((puVar1[3] != 3 && (puVar1[1] != shooterHandle)))) {
        Attack(*puVar1,shooterHandle,1);
        puVar1[3] = 3;
        puVar1[1] = shooterHandle;
        if (local_85 != false) {
          memset(local_44,0,0x40);
          memset(local_84,0,0x40);
          GetODFName(*puVar1,local_44);
          GetODFName(*(int *)(puVar1[2] * 0x30 + *(int *)&this->CarrierList),local_84);
          FormatLogMessage("Drone %08x \'%s\' PREORDNANCEHIT: Set to DroneState: %d, Carrier: %08x \'%s\'"
                           ,*puVar1,local_44,puVar1[3],
                           *(uint *)(puVar1[2] * 0x30 + *(int *)&this->CarrierList),local_84);
        }
      }
      puVar1 = puVar1 + 0xb;
    } while (puVar1 != *(uint **)&(this->DroneList).field_0x4);
  }
  return;
}


// ---------------------------------------------------------------------
// CarrierHelper::DroneFindTarget  @ 4fc18f3b  lines 511-562

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

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
      if ((*(float *)(iVar3 + 0x1c + iVar4) != 0.0) && (local_1c != 0)) {
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
// CarrierHelper::DroneRecall  @ 4fc1906b  lines 566-591

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool __thiscall CarrierHelper::DroneRecall(CarrierHelper *this,int index)

{
  int iVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  int *piVar5;
  int *piVar6;
  int iVar7;
  float10 extraout_ST0;
  int iVar8;
  undefined1 auStack_90 [3];
  bool local_8d;
  float fStack_8c;
  int iStack_88;
  char acStack_84 [64];
  char acStack_44 [64];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)auStack_90;
  iVar7 = index * 0x2c;
  local_8d = BZ1Helper::Logging;
  piVar6 = (int *)(*(int *)&this->DroneList + iVar7);
  piVar5 = (int *)(piVar6[2] * 0x30 + *(int *)&this->CarrierList);
  if ((float)piVar5[4] != 0.0) {
    (*misnImport.GetDistanceObject)(piVar6,piVar5);
    iVar1 = *(int *)&this->CarrierList;
    iVar2 = *(int *)&this->DroneList;
    fStack_8c = (float)extraout_ST0;
    iVar8 = *(int *)(iVar2 + 8 + iVar7);
    iStack_88 = iVar8 * 0x30;
    if (fStack_8c < *(float *)(iStack_88 + 0x10 + iVar1)) {
      iVar3 = index * 0x2c;
      if (*(char *)(iVar2 + 0x18 + iVar7) == '\0') {
        lVar4 = GetMaxHealth(*(int *)(iVar3 + iVar2));
        AddAmmo(*(int *)(iVar8 * 0x30 + iVar1),lVar4);
      }
      else {
        iVar8 = *(int *)(iVar3 + 0x14 + iVar2);
        lVar4 = GetMaxHealth(*(int *)(iVar3 + iVar2));
        AddLocalAmmo(*(int *)(iStack_88 + iVar1),(float)lVar4,iVar8);
      }
      if (local_8d != false) {
        memset(acStack_44,0,0x40);
        memset(acStack_84,0,0x40);
        GetODFName(*(int *)(iVar7 + *(int *)&this->DroneList),acStack_44);
        GetODFName(*(int *)(*(int *)(iVar7 + 8 + *(int *)&this->DroneList) * 0x30 +
                           *(int *)&this->CarrierList),acStack_84);
        FormatLogMessage("Drone %08x \'%s\' PACKUP: Set to Recall to Carrier: %08x \'%s\'",
                         *(uint *)(iVar7 + *(int *)&this->DroneList),acStack_44,
                         *(uint *)(*(int *)(iVar7 + 8 + *(int *)&this->DroneList) * 0x30 +
                                  *(int *)&this->CarrierList),acStack_84);
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
// CarrierHelper::DroneActivate  @ 4fc191e3  lines 595-600

void __thiscall CarrierHelper::DroneActivate(CarrierHelper *this,int index,int carrierindex)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = index * 0x2c;
  SetIndependence(*(int *)(*(int *)&this->DroneList + iVar2),1);
  *(int *)(*(int *)&this->DroneList + 8 + iVar2) = carrierindex;
  DroneIdle(this,index);
  piVar1 = (int *)(*(int *)(*(int *)&this->DroneList + 8 + iVar2) * 0x30 + 0x1c +
                  *(int *)&this->CarrierList);
  *piVar1 = *piVar1 + 1;
  return;
}


// ---------------------------------------------------------------------
// CarrierHelper::DroneDeactivate  @ 4fc19227  lines 604-612

void __thiscall CarrierHelper::DroneDeactivate(CarrierHelper *this,int index,bool resize)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = index * 0x2c;
  SetIndependence(*(int *)(*(int *)&this->DroneList + iVar2),0);
  Stop(*(int *)(*(int *)&this->DroneList + iVar2),1);
  *(undefined4 *)(*(int *)&this->DroneList + 0xc + iVar2) = 0;
  if (resize) {
    piVar1 = (int *)(*(int *)(*(int *)&this->DroneList + 8 + iVar2) * 0x30 + 0x1c +
                    *(int *)&this->CarrierList);
    *piVar1 = *piVar1 + -1;
  }
  return;
}


// ---------------------------------------------------------------------
// CarrierHelper::DroneIdle  @ 4fc19272  lines 616-622

void __thiscall CarrierHelper::DroneIdle(CarrierHelper *this,int index)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = index * 0x2c;
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
// CarrierHelper::DroneAttack  @ 4fc192d3  lines 626-637

void __thiscall CarrierHelper::DroneAttack(CarrierHelper *this,int index,int target,int team)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = index * 0x2c;
  SetIndependence(*(int *)(*(int *)&this->DroneList + iVar3),1);
  iVar2 = GetTeamNum(target);
  bVar1 = IsTeamAllied(team,iVar2);
  iVar2 = *(int *)(iVar3 + *(int *)&this->DroneList);
  if (bVar1) {
    Defend2(iVar2,target,1);
  }
  else {
    Attack(iVar2,target,1);
  }
  *(int *)(*(int *)&this->DroneList + 4 + iVar3) = target;
  *(undefined4 *)(*(int *)&this->DroneList + 0xc + iVar3) = 2;
  return;
}


