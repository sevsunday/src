// Reconstructed by Ghidra from Strategy02.dll + Strategy02.pdb
// Original source file: /e:/github/vsr_dll_source/missions/vsrcore/objecthelper.cpp
// Functions are ordered by original source line. This is decompiler
// output, not the author's source: names/types come from the PDB,
// local variable names and control flow are reconstructed.


// ---------------------------------------------------------------------
// `dynamic_initializer_for_'TempHandleBuffer''  @ 4fc018e9  lines 10-10


void __cdecl _dynamic_initializer_for__TempHandleBuffer__(void)

{
  atexit(_dynamic_atexit_destructor_for__TempHandleBuffer__);
  return;
}


// ---------------------------------------------------------------------
// ObjectHelper::PostLoad  @ 4fc24ea3  lines 31-52


bool __thiscall ObjectHelper::PostLoad(ObjectHelper *this,bool param_1)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  ObjectClass *unaff_ESI;
  int *piVar5;
  ObjectClass *unaff_EDI;
  
  piVar5 = *(int **)&this->HandleList;
  piVar2 = *(int **)&(this->HandleList).field_0x4;
  if (piVar5 != piVar2) {
    do {
      ConvertHandles(piVar5,1);
      piVar2 = *(int **)&(this->HandleList).field_0x4;
      piVar5 = piVar5 + 0x17;
    } while (piVar5 != piVar2);
    piVar5 = *(int **)&this->HandleList;
  }
  iVar3 = ((int)piVar2 - (int)piVar5) / 0x5c;
  if ((int)(TempHandleBuffer._4_4_ - TempHandleBuffer._0_4_) / 0x5c == iVar3) {
    iVar4 = 0;
    if (0 < iVar3) {
      do {
        bVar1 = ::operator==(unaff_EDI,unaff_ESI);
        if (!bVar1) {
          FormatLogMessage("HandleList Index Mismatch: %d");
          return true;
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < (*(int *)&(this->HandleList).field_0x4 - *(int *)&this->HandleList) / 0x5c);
    }
  }
  else {
    FormatLogMessage("HandleList Size Mismatch! Old: %d New: %d");
  }
  return true;
}


// ---------------------------------------------------------------------
// ObjectHelper::Save  @ 4fc24f3e  lines 55-64


bool __thiscall ObjectHelper::Save(ObjectHelper *this,bool param_1)

{
  bool bVar1;
  int local_8;
  
  local_8 = (*(int *)&(this->HandleList).field_0x4 - *(int *)&this->HandleList) / 0x5c;
  bVar1 = Write(&local_8,1);
  if (local_8 != 0) {
    if ((bVar1) && (bVar1 = Write(*(void **)&this->HandleList,local_8 * 0x5c), bVar1)) {
      return true;
    }
    bVar1 = false;
  }
  return bVar1;
}


// ---------------------------------------------------------------------
// ObjectHelper::Execute  @ 4fc24f8e  lines 77-119


void __thiscall ObjectHelper::Execute(ObjectHelper *this,BZ1Helper *param_1,PortalHelper *param_2)

{
  AlignTerrainReplaceClass *pAVar1;
  AlignTerrainReplaceClass *pAVar2;
  bool bVar3;
  ObjectClass *pOVar4;
  int iVar5;
  AlignTerrainReplaceClass *pAVar6;
  Vector *pVVar7;
  float *pfVar8;
  ObjectClass *pOVar9;
  AlignTerrainReplaceClass *pAVar10;
  size_t sVar11;
  Vector local_c;
  
  pAVar1 = *(AlignTerrainReplaceClass **)&(this->HandleList).field_0x4;
  pAVar6 = *(AlignTerrainReplaceClass **)&this->HandleList;
  while ((pAVar6 != pAVar1 && (bVar3 = BZ1Helper::ShouldRemoveAlignTerrainReplace(pAVar6), !bVar3)))
  {
    pAVar6 = (AlignTerrainReplaceClass *)&pAVar6[5].NormalVec.z;
  }
  pAVar2 = pAVar6;
  if (pAVar6 != pAVar1) {
    while (pAVar2 = (AlignTerrainReplaceClass *)&pAVar2[5].NormalVec.z, pAVar2 != pAVar1) {
      bVar3 = BZ1Helper::ShouldRemoveAlignTerrainReplace(pAVar2);
      if (!bVar3) {
        pfVar8 = (float *)pAVar2;
        pAVar10 = pAVar6;
        for (iVar5 = 0x17; iVar5 != 0; iVar5 = iVar5 + -1) {
          pAVar10->AlignHandle = (int)*pfVar8;
          pfVar8 = pfVar8 + 1;
          pAVar10 = (AlignTerrainReplaceClass *)&pAVar10->NormalVec;
        }
        pAVar6 = (AlignTerrainReplaceClass *)&pAVar6[5].NormalVec.z;
      }
    }
    if (pAVar6 != pAVar1) {
      sVar11 = *(int *)&(this->HandleList).field_0x4 - (int)pAVar1;
      memmove(pAVar6,pAVar1,sVar11);
      pOVar4 = (ObjectClass *)(sVar11 + (int)pAVar6);
      *(ObjectClass **)&(this->HandleList).field_0x4 = pOVar4;
      goto LAB_4fc2500f;
    }
  }
  pOVar4 = *(ObjectClass **)&(this->HandleList).field_0x4;
LAB_4fc2500f:
  pOVar9 = *(ObjectClass **)&this->HandleList;
  if (pOVar9 != pOVar4) {
    pVVar7 = &pOVar9->Position;
    do {
      iVar5 = GetTeamNum(pOVar9->ObjectHandle);
      *(int *)((int)(pVVar7 + -4) + 4) = iVar5;
      GetPosition(pOVar9->ObjectHandle,&local_c);
      pVVar7->x = local_c.x;
      pVVar7->y = local_c.y;
      pVVar7->z = local_c.z;
      iVar5 = GetPerceivedTeam(pOVar9->ObjectHandle);
      *(int *)((int)(pVVar7 + -4) + 8) = iVar5;
      if (*(bool *)((int)(pVVar7 + -5) + 10) != false) {
        PortalHelper::ExecuteObject(param_2,pOVar9);
      }
      pOVar9 = pOVar9 + 1;
      pVVar7 = (Vector *)((int)(pVVar7 + 7) + 8);
    } while (pOVar9 != *(ObjectClass **)&(this->HandleList).field_0x4);
  }
  return;
}

