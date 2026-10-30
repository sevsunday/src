// Reconstructed by Ghidra from Instant.dll + Instant.pdb
// Original source file: /e:/github/vsr_dll_source/missions/vsrcore/objecthelper.cpp
// Functions are ordered by original source line. This is decompiler
// output, not the author's source: names/types come from the PDB,
// local variable names and control flow are reconstructed.


// ---------------------------------------------------------------------
// `dynamic_initializer_for_'TempHandleBuffer''  @ 4fc018e7  lines 10-10


void __cdecl _dynamic_initializer_for__TempHandleBuffer__(void)

{
  atexit(_dynamic_atexit_destructor_for__TempHandleBuffer__);
  return;
}


// ---------------------------------------------------------------------
// ObjectHelper::PostLoad  @ 4fc241c6  lines 31-52


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
// ObjectHelper::Save  @ 4fc24261  lines 55-64


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
// ObjectHelper::Execute  @ 4fc242b1  lines 77-119


void __thiscall ObjectHelper::Execute(ObjectHelper *this,BZ1Helper *param_1,PortalHelper *param_2)

{
  AlignTerrainReplaceClass *pAVar1;
  AlignTerrainReplaceClass *pAVar2;
  bool bVar3;
  int iVar4;
  AlignTerrainReplaceClass *pAVar5;
  Vector *pVVar6;
  AlignTerrainReplaceClass *pAVar7;
  float *pfVar8;
  AlignTerrainReplaceClass *pAVar9;
  ObjectClass *pOVar10;
  ObjectClass *local_10;
  Vector local_c;
  
  pAVar1 = *(AlignTerrainReplaceClass **)&(this->HandleList).field_0x4;
  pAVar5 = *(AlignTerrainReplaceClass **)&this->HandleList;
  while ((pAVar5 != pAVar1 && (bVar3 = BZ1Helper::ShouldRemoveAlignTerrainReplace(pAVar5), !bVar3)))
  {
    pAVar5 = (AlignTerrainReplaceClass *)&pAVar5[5].NormalVec.z;
  }
  pAVar7 = pAVar5;
  if (pAVar5 != pAVar1) {
    while (pAVar7 = (AlignTerrainReplaceClass *)&pAVar7[5].NormalVec.z, pAVar7 != pAVar1) {
      bVar3 = BZ1Helper::ShouldRemoveAlignTerrainReplace(pAVar7);
      if (!bVar3) {
        pAVar2 = pAVar5 + 5;
        pfVar8 = (float *)pAVar7;
        pAVar9 = pAVar5;
        for (iVar4 = 0x17; pAVar5 = (AlignTerrainReplaceClass *)&(pAVar2->NormalVec).z, iVar4 != 0;
            iVar4 = iVar4 + -1) {
          pAVar9->AlignHandle = (int)*pfVar8;
          pfVar8 = pfVar8 + 1;
          pAVar9 = (AlignTerrainReplaceClass *)&pAVar9->NormalVec;
        }
      }
    }
  }
  pOVar10 = *(ObjectClass **)&(this->HandleList).field_0x4;
  if (pAVar5 != pAVar1) {
    memmove(pAVar5,pAVar1,(int)pOVar10 - (int)pAVar1);
    pOVar10 = (ObjectClass *)(((int)pOVar10 - (int)pAVar1) + (int)pAVar5);
    *(ObjectClass **)&(this->HandleList).field_0x4 = pOVar10;
  }
  local_10 = *(ObjectClass **)&this->HandleList;
  if (local_10 != pOVar10) {
    pVVar6 = &local_10->Position;
    do {
      iVar4 = GetTeamNum(local_10->ObjectHandle);
      *(int *)((int)(pVVar6 + -4) + 4) = iVar4;
      GetPosition(local_10->ObjectHandle,&local_c);
      pVVar6->x = local_c.x;
      pVVar6->y = local_c.y;
      pVVar6->z = local_c.z;
      iVar4 = GetPerceivedTeam(local_10->ObjectHandle);
      *(int *)((int)(pVVar6 + -4) + 8) = iVar4;
      if (*(bool *)((int)(pVVar6 + -5) + 10) != false) {
        PortalHelper::ExecuteObject(param_2,local_10);
      }
      local_10 = local_10 + 1;
      pVVar6 = (Vector *)((int)(pVVar6 + 7) + 8);
    } while (local_10 != *(ObjectClass **)&(this->HandleList).field_0x4);
  }
  return;
}

