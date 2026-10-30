// Reconstructed by Ghidra from deathmatch01.dll + deathmatch01.pdb
// Original source file: /e:/github/vsr_dll_source/missions/vsrcore/scraphelper.cpp
// Functions are ordered by original source line. This is decompiler
// output, not the author's source: names/types come from the PDB,
// local variable names and control flow are reconstructed.


// ---------------------------------------------------------------------
// `dynamic_initializer_for_'TempScrapBuffer''  @ 4fc01a52  lines 7-7


void __cdecl _dynamic_initializer_for__TempScrapBuffer__(void)

{
  atexit(_dynamic_atexit_destructor_for__TempScrapBuffer__);
  return;
}


// ---------------------------------------------------------------------
// ScrapHelper::PostLoad  @ 4fc25a45  lines 43-66


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool __thiscall ScrapHelper::PostLoad(ScrapHelper *this,bool param_1)

{
  int *piVar1;
  int iVar2;
  char *unaff_ESI;
  int *piVar3;
  int unaff_EDI;
  int iVar4;
  undefined1 local_8c [64];
  undefined1 local_4c [68];
  uint local_8;
  
  local_8 = __security_cookie ^ (uint)local_8c;
  piVar3 = *(int **)&this->ScrapList;
  piVar1 = *(int **)&(this->ScrapList).field_0x4;
  if (piVar3 != piVar1) {
    do {
      ConvertHandles(piVar3,1);
      piVar1 = *(int **)&(this->ScrapList).field_0x4;
      piVar3 = piVar3 + 1;
    } while (piVar3 != piVar1);
    piVar3 = *(int **)&this->ScrapList;
  }
  iVar2 = (int)piVar1 - (int)piVar3 >> 2;
  if ((int)(TempScrapBuffer._4_4_ - TempScrapBuffer._0_4_) >> 2 == iVar2) {
    iVar4 = 0;
    piVar1 = (int *)TempScrapBuffer._0_4_;
    if (0 < iVar2) {
      do {
        if (*piVar1 != piVar3[iVar4]) {
          memset(local_4c,0,0x40);
          memset(local_8c,0,0x40);
          GetODFName(unaff_EDI,unaff_ESI);
          GetODFName(unaff_EDI,unaff_ESI);
          FormatLogMessage("SCRAPCLASS MISMATCH: ScrapObject: %08x \'%s\' and %08x \'%s\'");
          FormatLogMessage("ScrapList Index Mismatch: %d");
          return true;
        }
        iVar4 = iVar4 + 1;
        piVar1 = piVar1 + 1;
      } while (iVar4 < *(int *)&(this->ScrapList).field_0x4 - (int)piVar3 >> 2);
    }
  }
  else {
    FormatLogMessage("ScrapList Size Mismatch! Old: %d New: %d");
  }
  return true;
}


// ---------------------------------------------------------------------
// ScrapHelper::AddScrapObject  @ 4fc25b4c  lines 84-137


void __thiscall
ScrapHelper::AddScrapObject(ScrapHelper *this,int param_1,char *param_2,char *param_3,bool param_4)

{
  int iVar1;
  bool bVar2;
  int *piVar3;
  float *unaff_EBX;
  float unaff_EDI;
  float fVar4;
  undefined3 in_stack_00000011;
  bool *pbVar5;
  Vector *pVVar6;
  Vector local_20;
  Vector local_14;
  float local_8;
  
  iVar1 = param_1;
  for (piVar3 = *(int **)&this->ScrapList; piVar3 != *(int **)&(this->ScrapList).field_0x4;
      piVar3 = piVar3 + 1) {
    if (*piVar3 == param_1) {
      return;
    }
  }
  pVVar6 = &local_20;
  pbVar5 = (bool *)param_1;
  GetPosition(param_1,pVVar6);
  param_1 = param_1 & 0xffffff;
  GetODFBool("ScrapClass","RestrictHeight",(char *)((int)&param_1 + 3),(char *)0x0,pbVar5,
             SUB41(pVVar6,0));
  local_8 = 0.0;
  GetODFFloat("ScrapClass","RestrictSlope",(char *)&local_8,(char *)0x0,unaff_EBX,unaff_EDI);
  if (0.0 <= local_8) {
    fVar4 = __real_3f800000;
    if (local_8 <= __real_3f800000) {
      fVar4 = local_8;
    }
  }
  else {
    fVar4 = 0.0;
  }
  local_8 = fVar4;
  if (((param_1._3_1_ == '\0') && (param_4 == false)) ||
     ((local_20.y <= (BZ1Helper::m_BZ1Helper->mapInfo).MaxScrapHeight &&
      ((BZ1Helper::m_BZ1Helper->mapInfo).MinScrapHeight <= local_20.y)))) {
    if (fVar4 != 0.0) {
      local_14.x = 0.0;
      local_14.z = 0.0;
      _param_4 = 0.0;
      local_14.y = 0.0;
      TerrainGetHeightAndNormal(&local_20,(float *)&param_4,&local_14,false);
      if (local_14.y < local_8) goto LAB_4fc25cc8;
    }
    std::vector<ScrapHelper::ScrapClass,std::allocator<ScrapHelper::ScrapClass>_>::
    _Resize<<lambda_5fdf7784746bcf490d41dbfe20fcbd69>_>
              (&this->ScrapList,
               (*(int *)&(this->ScrapList).field_0x4 - *(int *)&this->ScrapList >> 2) + 1,
               (<lambda_5fdf7784746bcf490d41dbfe20fcbd69>)this);
    *(int *)(*(int *)&this->ScrapList + -4 +
            (*(int *)&(this->ScrapList).field_0x4 - *(int *)&this->ScrapList >> 2) * 4) = iVar1;
    if ((0x3ff < (uint)(*(int *)&(this->ScrapList).field_0x4 - *(int *)&this->ScrapList >> 2)) ||
       (0x800 < BZ1Helper::TotalMapObjects)) {
      FormatLogMessage("WARNING: Too many objects on map! Deleting oldest scrap!");
      bVar2 = IsAround(**(int **)&this->ScrapList);
      if ((bVar2) && (**(int **)&this->ScrapList != iVar1)) {
        RemoveObject(**(int **)&this->ScrapList);
      }
    }
  }
  else {
LAB_4fc25cc8:
    BZ1Helper::DeleteAfterDelay(BZ1Helper::m_BZ1Helper,iVar1,0.0);
  }
  return;
}

