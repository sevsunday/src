// Reconstructed by Ghidra from Strategy02.dll + Strategy02.pdb
// Original source file: /e:/github/vsr_dll_source/missions/vsrcore/powerhelper.cpp
// Functions are ordered by original source line. This is decompiler
// output, not the author's source: names/types come from the PDB,
// local variable names and control flow are reconstructed.

// ---------------------------------------------------------------------
// `dynamic_initializer_for_'TempPowerBuffer''  @ 4fc01381  lines 7-7

void __cdecl _dynamic_initializer_for__TempPowerBuffer__(void)

{
  atexit(_dynamic_atexit_destructor_for__TempPowerBuffer__);
  return;
}


// ---------------------------------------------------------------------
// PowerHelper::PostLoad  @ 4fc147c3  lines 42-65

bool __thiscall PowerHelper::PostLoad(PowerHelper *this,bool param_1)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  
  piVar5 = *(int **)&this->PowerList;
  piVar2 = *(int **)&(this->PowerList).field_0x4;
  if (piVar5 != piVar2) {
    do {
      ConvertHandles(piVar5,1);
      piVar2 = *(int **)&(this->PowerList).field_0x4;
      piVar5 = piVar5 + 10;
    } while (piVar5 != piVar2);
    piVar5 = *(int **)&this->PowerList;
  }
  iVar3 = ((int)piVar2 - (int)piVar5) / 0x28;
  iVar4 = (int)(TempPowerBuffer._4_4_ - TempPowerBuffer._0_4_) / 0x28;
  if (iVar4 == iVar3) {
    iVar4 = 0;
    if (0 < iVar3) {
      iVar3 = 0;
      do {
        bVar1 = ::operator==((PowerClass *)(TempPowerBuffer._0_4_ + iVar3),
                             (PowerClass *)((int)piVar5 + iVar3));
        if (!bVar1) {
          FormatLogMessage("PowerList Index Mismatch: %d",iVar4);
          return true;
        }
        iVar4 = iVar4 + 1;
        piVar5 = *(int **)&this->PowerList;
        iVar3 = iVar3 + 0x28;
      } while (iVar4 < (*(int *)&(this->PowerList).field_0x4 - (int)piVar5) / 0x28);
    }
  }
  else {
    FormatLogMessage("PowerList Size Mismatch! Old: %d New: %d",iVar4,iVar3);
  }
  return true;
}


// ---------------------------------------------------------------------
// PowerHelper::AddPowerObject  @ 4fc1485e  lines 83-115

void __thiscall PowerHelper::AddPowerObject(PowerHelper *this,int h,char *TempODF1,char *TempODF2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  Vector local_c;
  
  iVar3 = -1;
  piVar2 = *(int **)&this->PowerList;
  piVar4 = *(int **)&(this->PowerList).field_0x4;
  piVar1 = piVar2;
  do {
    if (piVar1 == piVar4) {
LAB_4fc1488f:
      if (iVar3 < 0) {
        std::vector<PowerHelper::PowerClass,std::allocator<PowerHelper::PowerClass>_>::
        _Resize<<lambda_4736c2bbb992635efbfd8efd81bfd98e>_>
                  (&this->PowerList,((int)piVar4 - (int)piVar2) / 0x28 + 1,
                   (<lambda_4736c2bbb992635efbfd8efd81bfd98e>)this);
        piVar2 = *(int **)&this->PowerList;
        iVar3 = (*(int *)&(this->PowerList).field_0x4 - (int)piVar2) / 0x28 + -1;
      }
      piVar2 = piVar2 + iVar3 * 10;
      piVar4 = piVar2;
      for (iVar3 = 10; iVar3 != 0; iVar3 = iVar3 + -1) {
        *piVar4 = 0;
        piVar4 = piVar4 + 1;
      }
      GetODFBool(TempODF1,TempODF2,"BuildingClass","DoBettyLost",(bool *)((int)piVar2 + 5),true);
      iVar3 = GetODFFloat(TempODF1,TempODF2,"PowerPlantClass","powerRadius",(float *)(piVar2 + 3),
                          80.0);
      if (iVar3 == 0) {
        GetODFFloat(TempODF1,TempODF2,"PowerPlantClass","powerRange",(float *)(piVar2 + 3),80.0);
      }
      GetODFInt(TempODF1,TempODF2,"PowerPlantClass","PowerClassMask",piVar2 + 4,0);
      GetODFInt(TempODF1,TempODF2,"PowerPlantClass","PowerClassMatch",piVar2 + 5,0);
      GetODFInt(TempODF1,TempODF2,"PowerPlantClass","PowerClassProvides",piVar2 + 6,0);
      *piVar2 = h;
      GetPosition(h,&local_c);
      piVar2[7] = (int)local_c.x;
      piVar2[8] = (int)local_c.y;
      piVar2[9] = (int)local_c.z;
      return;
    }
    if (*piVar1 == h) {
      iVar3 = ((int)piVar1 - (int)piVar2) / 0x28;
      goto LAB_4fc1488f;
    }
    piVar1 = piVar1 + 10;
  } while( true );
}


// ---------------------------------------------------------------------
// PowerHelper::Execute  @ 4fc1499e  lines 132-165

void __thiscall PowerHelper::Execute(PowerHelper *this,BZ1Helper *bz1Helper)

{
  int *piVar1;
  BuildingHelper *this_00;
  bool bVar2;
  float fVar3;
  float fVar4;
  int *piVar5;
  int iVar6;
  int unaff_EBX;
  undefined4 unaff_EBP;
  float *pfVar7;
  int *piVar8;
  int unaff_EDI;
  int *piVar9;
  int *local_1c;
  Vector local_c;
  
  piVar5 = *(int **)&(this->PowerList).field_0x4;
  piVar1 = *(int **)&this->PowerList;
  piVar8 = piVar1;
  if (piVar1 != piVar5) {
    pfVar7 = (float *)(piVar1 + 7);
    piVar9 = piVar1;
    local_1c = piVar1;
    do {
      bVar2 = IsAround(*piVar9);
      if (bVar2) {
        fVar3 = (float)GetTeamNum(*piVar9);
        this_00 = BuildingHelper::m_BuildingHelper;
        pfVar7[-5] = fVar3;
        bVar2 = BuildingHelper::IsBuildingPowered(this_00,*piVar9);
        *(bool *)((int)pfVar7 + -0x16) = bVar2;
        GetPosition(*piVar9,&local_c);
        *pfVar7 = local_c.x;
        pfVar7[1] = local_c.y;
        pfVar7[2] = local_c.z;
        if (piVar1 != piVar9) {
          piVar5 = piVar9;
          piVar8 = local_1c;
          for (iVar6 = 10; iVar6 != 0; iVar6 = iVar6 + -1) {
            *piVar8 = *piVar5;
            piVar5 = piVar5 + 1;
            piVar8 = piVar8 + 1;
          }
        }
        piVar8 = local_1c + 10;
        local_1c = piVar8;
      }
      else if (((*(char *)(pfVar7 + -6) == '\0') && (*(char *)((int)pfVar7 + -0x17) == '\0')) &&
              (fVar3 = pfVar7[-5], fVar4 = (float)GetLocalPlayerTeamNumber(), fVar3 == fVar4)) {
        PlayEventVO((char)unaff_EBP,unaff_EBX,unaff_EDI);
      }
      piVar9 = piVar9 + 10;
      pfVar7 = pfVar7 + 10;
      piVar5 = *(int **)&(this->PowerList).field_0x4;
    } while (piVar9 != piVar5);
  }
  if (piVar8 != piVar5) {
    *(int **)&(this->PowerList).field_0x4 = piVar8;
  }
  return;
}


