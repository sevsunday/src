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
  int *piVar5;
  
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
  iVar4 = (int)(TempHandleBuffer._4_4_ - TempHandleBuffer._0_4_) / 0x5c;
  if (iVar4 == iVar3) {
    iVar4 = 0;
    if (0 < iVar3) {
      iVar3 = 0;
      do {
        bVar1 = ::operator==((ObjectClass *)(TempHandleBuffer._0_4_ + iVar3),
                             (ObjectClass *)((int)piVar5 + iVar3));
        if (!bVar1) {
          FormatLogMessage("HandleList Index Mismatch: %d",iVar4);
          return true;
        }
        iVar4 = iVar4 + 1;
        piVar5 = *(int **)&this->HandleList;
        iVar3 = iVar3 + 0x5c;
      } while (iVar4 < (*(int *)&(this->HandleList).field_0x4 - (int)piVar5) / 0x5c);
    }
  }
  else {
    FormatLogMessage("HandleList Size Mismatch! Old: %d New: %d",iVar4,iVar3);
  }
  return true;
}


// ---------------------------------------------------------------------
// ObjectHelper::Save  @ 4fc24f3e  lines 55-64

bool __thiscall ObjectHelper::Save(ObjectHelper *this,bool param_1)

{
  bool bVar1;
  int size;
  
  size = (*(int *)&(this->HandleList).field_0x4 - *(int *)&this->HandleList) / 0x5c;
  bVar1 = Write(&size,1);
  if (size != 0) {
    if ((bVar1) && (bVar1 = Write(*(void **)&this->HandleList,size * 0x5c), bVar1)) {
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
  AlignTerrainReplaceClass *entry;
  bool bVar2;
  ObjectClass *pOVar3;
  int iVar4;
  AlignTerrainReplaceClass *entry_00;
  Vector *pVVar5;
  float *pfVar6;
  ObjectClass *objectInfo;
  AlignTerrainReplaceClass *pAVar7;
  size_t sVar8;
  Vector local_c;
  
  pAVar1 = *(AlignTerrainReplaceClass **)&(this->HandleList).field_0x4;
  entry_00 = *(AlignTerrainReplaceClass **)&this->HandleList;
  while ((entry_00 != pAVar1 &&
         (bVar2 = BZ1Helper::ShouldRemoveAlignTerrainReplace(entry_00), !bVar2))) {
    entry_00 = (AlignTerrainReplaceClass *)&entry_00[5].NormalVec.z;
  }
  entry = entry_00;
  if (entry_00 != pAVar1) {
    while (entry = (AlignTerrainReplaceClass *)&entry[5].NormalVec.z, entry != pAVar1) {
      bVar2 = BZ1Helper::ShouldRemoveAlignTerrainReplace(entry);
      if (!bVar2) {
        pfVar6 = (float *)entry;
        pAVar7 = entry_00;
        for (iVar4 = 0x17; iVar4 != 0; iVar4 = iVar4 + -1) {
          pAVar7->AlignHandle = (int)*pfVar6;
          pfVar6 = pfVar6 + 1;
          pAVar7 = (AlignTerrainReplaceClass *)&pAVar7->NormalVec;
        }
        entry_00 = (AlignTerrainReplaceClass *)&entry_00[5].NormalVec.z;
      }
    }
    if (entry_00 != pAVar1) {
      sVar8 = *(int *)&(this->HandleList).field_0x4 - (int)pAVar1;
      memmove(entry_00,pAVar1,sVar8);
      pOVar3 = (ObjectClass *)(sVar8 + (int)entry_00);
      *(ObjectClass **)&(this->HandleList).field_0x4 = pOVar3;
      goto LAB_4fc2500f;
    }
  }
  pOVar3 = *(ObjectClass **)&(this->HandleList).field_0x4;
LAB_4fc2500f:
  objectInfo = *(ObjectClass **)&this->HandleList;
  if (objectInfo != pOVar3) {
    pVVar5 = &objectInfo->Position;
    do {
      iVar4 = GetTeamNum(objectInfo->ObjectHandle);
      *(int *)((int)(pVVar5 + -4) + 4) = iVar4;
      GetPosition(objectInfo->ObjectHandle,&local_c);
      pVVar5->x = local_c.x;
      pVVar5->y = local_c.y;
      pVVar5->z = local_c.z;
      iVar4 = GetPerceivedTeam(objectInfo->ObjectHandle);
      *(int *)((int)(pVVar5 + -4) + 8) = iVar4;
      if (*(bool *)((int)(pVVar5 + -5) + 10) != false) {
        PortalHelper::ExecuteObject(param_2,objectInfo);
      }
      objectInfo = objectInfo + 1;
      pVVar5 = (Vector *)((int)(pVVar5 + 7) + 8);
    } while (objectInfo != *(ObjectClass **)&(this->HandleList).field_0x4);
  }
  return;
}


