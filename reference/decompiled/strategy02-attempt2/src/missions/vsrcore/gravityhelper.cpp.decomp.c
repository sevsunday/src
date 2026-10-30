// Reconstructed by Ghidra from Strategy02.dll + Strategy02.pdb
// Original source file: /e:/github/vsr_dll_source/missions/vsrcore/gravityhelper.cpp
// Functions are ordered by original source line. This is decompiler
// output, not the author's source: names/types come from the PDB,
// local variable names and control flow are reconstructed.

// ---------------------------------------------------------------------
// `dynamic_initializer_for_'TempGravityBuffer''  @ 4fc0147b  lines 7-7

void __cdecl _dynamic_initializer_for__TempGravityBuffer__(void)

{
  memset(TempGravityBuffer,0,0x140);
  return;
}


// ---------------------------------------------------------------------
// GravityHelper::Load  @ 4fc15d1a  lines 17-40

bool __thiscall GravityHelper::Load(GravityHelper *this,bool missionSave)

{
  bool bVar1;
  bool bVar2;
  GravityInfo *pGVar3;
  GravityInfo *pGVar4;
  float *pfVar5;
  int iVar6;
  float *pfVar7;
  int local_18;
  GravityInfo *local_c;
  
  if (missionSave) {
    bVar1 = true;
  }
  else {
    pfVar5 = &this[-0x3fd2f8].gravityInfo[0xe].Gravitation;
    local_c = TempGravityBuffer;
    pGVar3 = TempGravityBuffer;
    do {
      pGVar4 = pGVar3 + 1;
      pfVar7 = (float *)((int)pfVar5 + (int)pGVar3);
      for (iVar6 = 5; iVar6 != 0; iVar6 = iVar6 + -1) {
        pGVar3->TranPeriod = *pfVar7;
        pfVar7 = pfVar7 + 1;
        pGVar3 = (GravityInfo *)&pGVar3->OnPeriod;
      }
      pGVar3 = pGVar4;
    } while ((int)pGVar4 < 0x4fc7b620);
    bVar1 = true;
    local_18 = 0;
    iVar6 = 0x10;
    do {
      if ((bVar1 == false) || (bVar1 = Read(this,0x14), !bVar1)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      this = (GravityHelper *)((int)this + 0x14);
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
    do {
      bVar2 = ::operator==(local_c,(GravityInfo *)((int)pfVar5 + (int)(local_c + 0xe + -0xe)));
      if (!bVar2) {
        FormatLogMessage("GravityHelper Load Mismatch Index: %d",local_18);
        return bVar1;
      }
      local_18 = local_18 + 1;
      local_c = local_c + 1;
    } while ((int)local_c < 0x4fc7b620);
  }
  return bVar1;
}


// ---------------------------------------------------------------------
// GravityHelper::LoadGravityInfo  @ 4fc15ddc  lines 56-73

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall GravityHelper::LoadGravityInfo(GravityHelper *this,char *mapTrnFile)

{
  bool bVar1;
  int fmtarg1;
  float *pfVar2;
  int local_48;
  char local_44 [64];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)&local_48;
  bVar1 = OpenODF2(mapTrnFile);
  if (bVar1) {
    local_48 = 0x10;
    fmtarg1 = 1;
    pfVar2 = &this->gravityInfo[0].OnPeriod;
    do {
      memset(local_44,0,0x40);
      sprintf_s<64>(&local_44,"Gravity%d",fmtarg1);
      GetODFFloat(mapTrnFile,"Gravity",local_44,pfVar2 + 2,12.5);
      sprintf_s<64>(&local_44,"OnPeriod%d",fmtarg1);
      GetODFFloat(mapTrnFile,"Gravity",local_44,pfVar2,0.0);
      sprintf_s<64>(&local_44,"TranPeriod%d",fmtarg1);
      GetODFFloat(mapTrnFile,"Gravity",local_44,(float *)(pfVar2 + -1),0.0);
      pfVar2 = pfVar2 + 5;
      fmtarg1 = fmtarg1 + 1;
      local_48 = local_48 + -1;
    } while (local_48 != 0);
  }
  return;
}


// ---------------------------------------------------------------------
// GravityHelper::Execute  @ 4fc15ec8  lines 76-163

void __thiscall GravityHelper::Execute(GravityHelper *this,BZ1Helper *bz1Helper)

{
  uint uVar1;
  int *piVar2;
  float fVar3;
  double dVar4;
  double dVar5;
  int fmtarg1;
  float fVar6;
  bool bVar7;
  int iVar8;
  int iVar9;
  uint fmtarg2;
  uint uVar10;
  undefined4 unaff_EDI;
  
  bVar7 = BZ1Helper::Logging;
  fmtarg1 = (bz1Helper->mapInfo).GravityState;
  iVar8 = SecondsToTurns(this->gravityInfo[fmtarg1].OnPeriod);
  uVar10 = (bz1Helper->mapInfo).GravityState + 1U & 0x8000000f;
  if ((int)uVar10 < 0) {
    uVar10 = (uVar10 - 1 | 0xfffffff0) + 1;
  }
  fmtarg2 = uVar10;
  if (this->gravityInfo[uVar10].OnPeriod <= 0.0) {
    do {
      if (0.0 < this->gravityInfo[fmtarg2].OnPeriod) break;
      uVar1 = fmtarg2 + 1;
      fmtarg2 = 0;
      if ((int)uVar1 < 0x10) {
        fmtarg2 = uVar1;
      }
    } while (fmtarg2 != uVar10);
  }
  if (iVar8 < 1) {
    (bz1Helper->mapInfo).GravityState = uVar10;
  }
  else {
    iVar9 = SecondsToTurns(this->gravityInfo[fmtarg2].TranPeriod);
    if (BZ1Helper::m_TurnCounter == 1) {
      fVar3 = this->gravityInfo[fmtarg1].Gravity;
      (bz1Helper->mapInfo).Gravity = fVar3;
      SetGravity(fVar3);
    }
    piVar2 = &this->gravityInfo[fmtarg1].OnCounter;
    *piVar2 = *piVar2 + 1;
    if (iVar8 <= this->gravityInfo[fmtarg1].OnCounter) {
      if (this->gravityInfo[fmtarg2].Gravitation == 0.0) {
        fVar3 = this->gravityInfo[fmtarg2].Gravity;
        fVar6 = fVar3 - (bz1Helper->mapInfo).Gravity;
        if (0 < iVar9) {
          fVar6 = fVar6 / (float)iVar9;
        }
        this->gravityInfo[fmtarg2].Gravitation = fVar6;
        if (bVar7) {
          dVar4 = (double)this->gravityInfo[fmtarg2].TranPeriod;
          dVar5 = (double)fVar3;
          FormatLogMessage("Gravity: %d NextGravity: %d, CurGravity: %f, NextGravity: %f, Gravitation is: %f, TranPeriod is: %f"
                           ,fmtarg1,fmtarg2,
                           (double)CONCAT44(SUB84(dVar5,0),
                                            (int)((ulonglong)(double)(bz1Helper->mapInfo).Gravity >>
                                                 0x20)),
                           (double)CONCAT44(SUB84((double)fVar6,0),(int)((ulonglong)dVar5 >> 0x20)),
                           (double)CONCAT44(SUB84(dVar4,0),(int)((ulonglong)(double)fVar6 >> 0x20)),
                           (double)CONCAT44(unaff_EDI,(int)((ulonglong)dVar4 >> 0x20)));
        }
      }
      fVar3 = (bz1Helper->mapInfo).Gravity;
      if (ABS(fVar3 - this->gravityInfo[fmtarg2].Gravity) <= 0.001) {
        this->gravityInfo[fmtarg1].OnCounter = 0;
        this->gravityInfo[fmtarg1].Gravitation = 0.0;
        uVar10 = (bz1Helper->mapInfo).GravityState + 1U & 0x8000000f;
        if ((int)uVar10 < 0) {
          uVar10 = (uVar10 - 1 | 0xfffffff0) + 1;
        }
        (bz1Helper->mapInfo).GravityState = uVar10;
        if (bVar7) {
          FormatLogMessage("Gravity State over, next Gravity State: %d",uVar10);
        }
      }
      else {
        fVar3 = fVar3 + this->gravityInfo[fmtarg2].Gravitation;
        (bz1Helper->mapInfo).Gravity = fVar3;
        SetGravity(fVar3);
      }
    }
  }
  return;
}


