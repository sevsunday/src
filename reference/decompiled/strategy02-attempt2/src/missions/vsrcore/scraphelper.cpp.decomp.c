// Reconstructed by Ghidra from Strategy02.dll + Strategy02.pdb
// Original source file: /e:/github/vsr_dll_source/missions/vsrcore/scraphelper.cpp
// Functions are ordered by original source line. This is decompiler
// output, not the author's source: names/types come from the PDB,
// local variable names and control flow are reconstructed.

// ---------------------------------------------------------------------
// `dynamic_initializer_for_'TempScrapBuffer''  @ 4fc01a54  lines 7-7

void __cdecl _dynamic_initializer_for__TempScrapBuffer__(void)

{
  atexit(_dynamic_atexit_destructor_for__TempScrapBuffer__);
  return;
}


// ---------------------------------------------------------------------
// ScrapHelper::PostLoad  @ 4fc26732  lines 43-66

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool __thiscall ScrapHelper::PostLoad(ScrapHelper *this,bool param_1)

{
  int *piVar1;
  int fmtarg2;
  int iVar2;
  uint *puVar3;
  int *piVar4;
  char local_8c [64];
  char local_4c [68];
  uint local_8;
  
  local_8 = __security_cookie ^ (uint)local_8c;
  piVar4 = *(int **)&this->ScrapList;
  piVar1 = *(int **)&(this->ScrapList).field_0x4;
  if (piVar4 != piVar1) {
    do {
      ConvertHandles(piVar4,1);
      piVar1 = *(int **)&(this->ScrapList).field_0x4;
      piVar4 = piVar4 + 1;
    } while (piVar4 != piVar1);
    piVar4 = *(int **)&this->ScrapList;
  }
  fmtarg2 = (int)piVar1 - (int)piVar4 >> 2;
  iVar2 = (int)(TempScrapBuffer._4_4_ - TempScrapBuffer._0_4_) >> 2;
  if (iVar2 == fmtarg2) {
    iVar2 = 0;
    puVar3 = (uint *)TempScrapBuffer._0_4_;
    if (0 < fmtarg2) {
      do {
        if (*puVar3 != piVar4[iVar2]) {
          memset(local_4c,0,0x40);
          memset(local_8c,0,0x40);
          GetODFName(*puVar3,local_4c);
          GetODFName(piVar4[iVar2],local_8c);
          FormatLogMessage("SCRAPCLASS MISMATCH: ScrapObject: %08x \'%s\' and %08x \'%s\'",*puVar3,
                           local_4c,piVar4[iVar2],local_8c);
          FormatLogMessage("ScrapList Index Mismatch: %d",iVar2);
          return true;
        }
        iVar2 = iVar2 + 1;
        puVar3 = puVar3 + 1;
      } while (iVar2 < *(int *)&(this->ScrapList).field_0x4 - (int)piVar4 >> 2);
    }
  }
  else {
    FormatLogMessage("ScrapList Size Mismatch! Old: %d New: %d",iVar2,fmtarg2);
  }
  return true;
}


// ---------------------------------------------------------------------
// ScrapHelper::AddScrapObject  @ 4fc26838  lines 84-137

void __thiscall
ScrapHelper::AddScrapObject
          (ScrapHelper *this,int h,char *TempODF1,char *TempODF2,bool RestrictAllScrap)

{
  int h_00;
  bool bVar1;
  int *piVar2;
  float fVar3;
  undefined3 in_stack_00000011;
  Vector Pos;
  Vector ANormal;
  float RestrictSlope;
  
  h_00 = h;
  for (piVar2 = *(int **)&this->ScrapList; piVar2 != *(int **)&(this->ScrapList).field_0x4;
      piVar2 = piVar2 + 1) {
    if (*piVar2 == h) {
      return;
    }
  }
  GetPosition(h,&Pos);
  h = h & 0xffffff;
  GetODFBool(TempODF1,TempODF2,"ScrapClass","RestrictHeight",(bool *)((int)&h + 3),false);
  RestrictSlope = 0.0;
  GetODFFloat(TempODF1,TempODF2,"ScrapClass","RestrictSlope",&RestrictSlope,0.0);
  if (0.0 <= RestrictSlope) {
    fVar3 = 1.0;
    if (RestrictSlope <= 1.0) {
      fVar3 = RestrictSlope;
    }
  }
  else {
    fVar3 = 0.0;
  }
  RestrictSlope = fVar3;
  if (((h._3_1_ == '\0') && (RestrictAllScrap == false)) ||
     ((Pos.y <= (BZ1Helper::m_BZ1Helper->mapInfo).MaxScrapHeight &&
      ((BZ1Helper::m_BZ1Helper->mapInfo).MinScrapHeight <= Pos.y)))) {
    if (fVar3 != 0.0) {
      ANormal.x = 0.0;
      ANormal.z = 0.0;
      _RestrictAllScrap = 0.0;
      ANormal.y = 0.0;
      TerrainGetHeightAndNormal(&Pos,(float *)&RestrictAllScrap,&ANormal,false);
      if (ANormal.y < RestrictSlope) goto LAB_4fc269b4;
    }
    std::vector<ScrapHelper::ScrapClass,std::allocator<ScrapHelper::ScrapClass>_>::
    _Resize<<lambda_5fdf7784746bcf490d41dbfe20fcbd69>_>
              (&this->ScrapList,
               (*(int *)&(this->ScrapList).field_0x4 - *(int *)&this->ScrapList >> 2) + 1,
               (<lambda_5fdf7784746bcf490d41dbfe20fcbd69>)this);
    *(int *)(*(int *)&this->ScrapList + -4 +
            (*(int *)&(this->ScrapList).field_0x4 - *(int *)&this->ScrapList >> 2) * 4) = h_00;
    if ((0x3ff < (uint)(*(int *)&(this->ScrapList).field_0x4 - *(int *)&this->ScrapList >> 2)) ||
       (0x800 < BZ1Helper::TotalMapObjects)) {
      FormatLogMessage("WARNING: Too many objects on map! Deleting oldest scrap!");
      bVar1 = IsAround(**(int **)&this->ScrapList);
      if ((bVar1) && (**(int **)&this->ScrapList != h_00)) {
        RemoveObject(**(int **)&this->ScrapList);
      }
    }
  }
  else {
LAB_4fc269b4:
    BZ1Helper::DeleteAfterDelay(BZ1Helper::m_BZ1Helper,h_00,0.0);
  }
  return;
}


