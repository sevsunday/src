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


bool __thiscall GravityHelper::Load(GravityHelper *this,bool param_1)

{
  bool bVar1;
  bool bVar2;
  GravityInfo *pGVar3;
  GravityInfo *pGVar4;
  int iVar5;
  GravityInfo *unaff_ESI;
  float *pfVar6;
  GravityInfo *unaff_EDI;
  GravityInfo *local_c;
  
  if (param_1) {
    bVar1 = true;
  }
  else {
    local_c = TempGravityBuffer;
    pGVar3 = TempGravityBuffer;
    do {
      pGVar4 = pGVar3 + 1;
      pfVar6 = (float *)((int)&this[-0x3fd2f8].gravityInfo[0xe].Gravitation + (int)pGVar3);
      for (iVar5 = 5; iVar5 != 0; iVar5 = iVar5 + -1) {
        pGVar3->TranPeriod = *pfVar6;
        pfVar6 = pfVar6 + 1;
        pGVar3 = (GravityInfo *)&pGVar3->OnPeriod;
      }
      pGVar3 = pGVar4;
    } while ((int)pGVar4 < 0x4fc7b620);
    bVar1 = true;
    iVar5 = 0x10;
    do {
      if ((bVar1 == false) || (bVar1 = Read(this,0x14), !bVar1)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      this = (GravityHelper *)((int)this + 0x14);
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    do {
      bVar2 = ::operator==(unaff_EDI,unaff_ESI);
      if (!bVar2) {
        FormatLogMessage("GravityHelper Load Mismatch Index: %d");
        break;
      }
      local_c = local_c + 1;
    } while ((int)local_c < 0x4fc7b620);
  }
  return bVar1;
}


// ---------------------------------------------------------------------
// GravityHelper::LoadGravityInfo  @ 4fc15ddc  lines 56-73


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall GravityHelper::LoadGravityInfo(GravityHelper *this,char *param_1)

{
  bool bVar1;
  char *unaff_EDI;
  float *pfVar2;
  int local_48;
  char local_44 [64];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)&local_48;
  bVar1 = OpenODF2(unaff_EDI);
  if (bVar1) {
    local_48 = 0x10;
    pfVar2 = &this->gravityInfo[0].OnPeriod;
    do {
      memset(local_44,0,0x40);
      sprintf_s<64>(&local_44,"Gravity%d");
      GetODFFloat(param_1,"Gravity",local_44,pfVar2 + 2,___real_41480000);
      sprintf_s<64>(&local_44,"OnPeriod%d");
      GetODFFloat(param_1,"Gravity",local_44,pfVar2,0.0);
      sprintf_s<64>(&local_44,"TranPeriod%d");
      GetODFFloat(param_1,"Gravity",local_44,(float *)(pfVar2 + -1),0.0);
      pfVar2 = pfVar2 + 5;
      local_48 = local_48 + -1;
    } while (local_48 != 0);
  }
  return;
}


// ---------------------------------------------------------------------
// GravityHelper::Execute  @ 4fc15ec8  lines 76-163


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall GravityHelper::Execute(GravityHelper *this,BZ1Helper *param_1)

{
  uint uVar1;
  int *piVar2;
  float fVar3;
  int iVar4;
  bool bVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  
  bVar5 = BZ1Helper::Logging;
  iVar4 = (param_1->mapInfo).GravityState;
  iVar6 = SecondsToTurns(this->gravityInfo[iVar4].OnPeriod);
  uVar9 = (param_1->mapInfo).GravityState + 1U & 0x8000000f;
  if ((int)uVar9 < 0) {
    uVar9 = (uVar9 - 1 | 0xfffffff0) + 1;
  }
  uVar8 = uVar9;
  if (this->gravityInfo[uVar9].OnPeriod <= 0.0) {
    do {
      if (0.0 < this->gravityInfo[uVar8].OnPeriod) break;
      uVar1 = uVar8 + 1;
      uVar8 = 0;
      if ((int)uVar1 < 0x10) {
        uVar8 = uVar1;
      }
    } while (uVar8 != uVar9);
  }
  if (iVar6 < 1) {
    (param_1->mapInfo).GravityState = uVar9;
  }
  else {
    iVar7 = SecondsToTurns(this->gravityInfo[uVar8].TranPeriod);
    if (BZ1Helper::m_TurnCounter == 1) {
      fVar3 = this->gravityInfo[iVar4].Gravity;
      (param_1->mapInfo).Gravity = fVar3;
      SetGravity(fVar3);
    }
    piVar2 = &this->gravityInfo[iVar4].OnCounter;
    *piVar2 = *piVar2 + 1;
    if (iVar6 <= this->gravityInfo[iVar4].OnCounter) {
      if (this->gravityInfo[uVar8].Gravitation == ___real_00000000) {
        fVar3 = this->gravityInfo[uVar8].Gravity - (param_1->mapInfo).Gravity;
        if (0 < iVar7) {
          fVar3 = fVar3 / (float)iVar7;
        }
        this->gravityInfo[uVar8].Gravitation = fVar3;
        if (bVar5) {
          FormatLogMessage(
                          "Gravity: %d NextGravity: %d, CurGravity: %f, NextGravity: %f, Gravitation is: %f, TranPeriod is: %f"
                          );
        }
      }
      fVar3 = (param_1->mapInfo).Gravity;
      if (ABS(fVar3 - this->gravityInfo[uVar8].Gravity) <= ___real_3a83126f) {
        this->gravityInfo[iVar4].OnCounter = 0;
        this->gravityInfo[iVar4].Gravitation = 0.0;
        uVar9 = (param_1->mapInfo).GravityState + 1U & 0x8000000f;
        if ((int)uVar9 < 0) {
          uVar9 = (uVar9 - 1 | 0xfffffff0) + 1;
        }
        (param_1->mapInfo).GravityState = uVar9;
        if (bVar5) {
          FormatLogMessage("Gravity State over, next Gravity State: %d");
        }
      }
      else {
        fVar3 = fVar3 + this->gravityInfo[uVar8].Gravitation;
        (param_1->mapInfo).Gravity = fVar3;
        SetGravity(fVar3);
      }
    }
  }
  return;
}

