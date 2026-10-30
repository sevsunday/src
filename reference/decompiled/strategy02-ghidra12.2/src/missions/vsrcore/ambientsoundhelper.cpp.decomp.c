// Reconstructed by Ghidra from Strategy02.dll + Strategy02.pdb
// Original source file: /e:/github/vsr_dll_source/missions/vsrcore/ambientsoundhelper.cpp
// Functions are ordered by original source line. This is decompiler
// output, not the author's source: names/types come from the PDB,
// local variable names and control flow are reconstructed.


// ---------------------------------------------------------------------
// `dynamic_initializer_for_'TempAmbientSoundBuffer''  @ 4fc012fb  lines 7-7


void __cdecl _dynamic_initializer_for__TempAmbientSoundBuffer__(void)

{
  memset(TempAmbientSoundBuffer,0,0xe00);
  return;
}


// ---------------------------------------------------------------------
// AmbientSoundHelper::Load  @ 4fc14017  lines 17-39


bool __thiscall AmbientSoundHelper::Load(AmbientSoundHelper *this,bool param_1)

{
  bool bVar1;
  bool bVar2;
  AmbientAudioInfo *pAVar3;
  AmbientAudioInfo *pAVar4;
  int iVar5;
  AmbientAudioInfo *unaff_ESI;
  char *pcVar6;
  AmbientAudioInfo *unaff_EDI;
  AmbientAudioInfo *local_c;
  
  if (param_1) {
    bVar1 = true;
  }
  else {
    local_c = TempAmbientSoundBuffer;
    pAVar3 = TempAmbientSoundBuffer;
    do {
      pAVar4 = pAVar3 + 1;
      pcVar6 = this[-0x5b2d6].ambientAudioInfo[0x1e].AudioFile + 0x1c + (int)pAVar3;
      for (iVar5 = 0x1c; iVar5 != 0; iVar5 = iVar5 + -1) {
        pAVar3->AudioHandle = *(int *)pcVar6;
        pcVar6 = pcVar6 + 4;
        pAVar3 = (AmbientAudioInfo *)pAVar3->AudioFile;
      }
      pAVar3 = pAVar4;
    } while ((int)pAVar4 < 0x4fc7b4c0);
    bVar1 = true;
    iVar5 = 0x20;
    do {
      if ((bVar1 == false) || (bVar1 = Read(this,0x70), !bVar1)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      this = (AmbientSoundHelper *)((int)this + 0x70);
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    do {
      bVar2 = ::operator==(unaff_EDI,unaff_ESI);
      if (!bVar2) {
        FormatLogMessage("AmbientAudioInfo Load Mismatch Index: %d");
        break;
      }
      local_c = local_c + 1;
    } while ((int)local_c < 0x4fc7b4c0);
  }
  return bVar1;
}


// ---------------------------------------------------------------------
// AmbientSoundHelper::LoadAmbientSoundInfo  @ 4fc140d9  lines 55-94


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall AmbientSoundHelper::LoadAmbientSoundInfo(AmbientSoundHelper *this,char *param_1)

{
  float *pfVar1;
  Vector *pVVar2;
  Vector VVar3;
  bool bVar4;
  float fVar5;
  Vector *pVVar6;
  char *unaff_EDI;
  float fVar7;
  float local_60;
  float local_5c;
  int local_58;
  char *local_54;
  undefined4 local_50;
  undefined4 local_4c;
  float local_48;
  char local_44 [64];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)&local_60;
  local_54 = param_1;
  bVar4 = OpenODF2(unaff_EDI);
  if (bVar4) {
    local_50 = 0;
    local_4c = 0;
    local_48 = 0.0;
    pVVar6 = &this->ambientAudioInfo[0].Position;
    local_58 = 0x20;
    do {
      memset(local_44,0,0x40);
      sprintf_s<64>(&local_44,"AmbientSound%d");
      GetODFString(param_1,"Audio",local_44,0x40,(char *)(pVVar6 + -8),(char *)0x0);
      sprintf_s<64>(&local_44,"Position%d");
      param_1 = local_54;
      VVar3.y = (float)local_4c;
      VVar3.x = (float)local_50;
      VVar3.z = local_48;
      GetODFVector(local_54,"Audio",local_44,pVVar6,VVar3);
      sprintf_s<64>(&local_44,"IsMusic%d");
      GetODFBool(param_1,"Audio",local_44,(bool *)(pVVar6 + -2),false);
      sprintf_s<64>(&local_44,"MinDelay%d");
      local_60 = 0.0;
      GetODFFloat(param_1,"Audio",local_44,&local_60,0.0);
      fVar5 = (float)SecondsToTurns(local_60);
      pVVar6[-3].y = fVar5;
      sprintf_s<64>(&local_44,"MaxDelay%d");
      local_5c = 0.0;
      GetODFFloat(param_1,"Audio",local_44,&local_5c,0.0);
      fVar5 = (float)SecondsToTurns(local_5c);
      pVVar6[-3].z = fVar5;
      sprintf_s<64>(&local_44,"BasePan%d");
      GetODFFloat(param_1,"Audio",local_44,&pVVar6[-2].y,0.0);
      fVar5 = pVVar6[-2].y;
      fVar7 = __real_bf800000;
      if ((fVar5 < __real_bf800000) || (fVar7 = __real_3f800000, __real_3f800000 < fVar5)) {
        fVar5 = fVar7;
      }
      pVVar6[-2].y = fVar5;
      sprintf_s<64>(&local_44,"PanVariance%d");
      pfVar1 = &pVVar6[-2].z;
      GetODFFloat(param_1,"Audio",local_44,pfVar1,0.0);
      fVar5 = *pfVar1;
      fVar7 = 0.0;
      if ((fVar5 < 0.0) || (fVar7 = __real_3f800000, __real_3f800000 < fVar5)) {
        fVar5 = fVar7;
      }
      *pfVar1 = fVar5;
      sprintf_s<64>(&local_44,"Rate%d");
      pVVar2 = pVVar6 + -1;
      GetODFFloat(param_1,"Audio",local_44,&pVVar2->x,__real_472c4400);
      fVar5 = pVVar2->x;
      fVar7 = 0.0;
      if ((fVar5 < 0.0) || (fVar7 = __real_472c4400, __real_472c4400 < fVar5)) {
        fVar5 = fVar7;
      }
      pVVar2->x = fVar5;
      pVVar6 = (Vector *)&pVVar6[9].y;
      local_58 = local_58 + -1;
    } while (local_58 != 0);
  }
  return;
}


// ---------------------------------------------------------------------
// AmbientSoundHelper::Execute  @ 4fc1434e  lines 97-184


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall AmbientSoundHelper::Execute(AmbientSoundHelper *this,BZ1Helper *param_1)

{
  Vector VVar1;
  Vector VVar2;
  char cVar3;
  bool bVar4;
  int iVar5;
  undefined4 *extraout_ECX;
  code *pcVar6;
  undefined4 *extraout_ECX_00;
  undefined4 extraout_EDX;
  char *pcVar7;
  int unaff_ESI;
  DLLAudioCategory unaff_EDI;
  code *pcVar8;
  float fVar9;
  int local_28;
  code *local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  code *local_10;
  int local_c;
  float local_8;
  code *local_4;
  
  local_18 = 1.0;
  pcVar7 = this->ambientAudioInfo[0].AudioFile;
  local_1c = __real_3f000000;
  local_24 = StartAudio2D_exref;
  local_20 = __real_bf800000;
  local_c = 0x20;
  local_4 = DoesFileExist_exref;
  local_10 = IsAudioPlaying_exref;
  pcVar6 = DoesFileExist_exref;
  pcVar8 = IsAudioPlaying_exref;
  do {
    iVar5 = local_c;
    if (*pcVar7 != '\0') {
      cVar3 = (*pcVar6)(pcVar7);
      if ((cVar3 != '\0') && (*(int *)(pcVar7 + 0x58) <= BZ1Helper::m_TurnCounter)) {
        local_28 = ((AmbientAudioInfo *)(pcVar7 + -4))->AudioHandle;
        cVar3 = (*pcVar8)(&local_28);
        if (cVar3 == '\0') {
          if (*(int *)(pcVar7 + 0x44) < 1) {
            bVar4 = IsNullVector(*(Vector *)(pcVar7 + 0x60));
            if (bVar4) {
              iVar5 = (*local_24)(pcVar7,local_20,*(float *)(pcVar7 + 0x4c),
                                  *(float *)(pcVar7 + 0x54),1,extraout_EDX);
            }
            else {
              VVar2.z = 1.4013e-45;
              VVar2._0_8_ = *(undefined8 *)(extraout_ECX_00 + 1);
              iVar5 = StartAudio3D((char *)*extraout_ECX_00,VVar2,unaff_EDI,SUB41(unaff_ESI,0));
            }
            ((AmbientAudioInfo *)(pcVar7 + -4))->AudioHandle = iVar5;
          }
          else {
            bVar4 = IsNullVector(*(Vector *)(pcVar7 + 0x60));
            if (bVar4) {
              local_8 = *(float *)(pcVar7 + 0x4c);
              local_14 = *(float *)(pcVar7 + 0x50);
              if (___real_00000000 < local_14) {
                local_14 = GetRandomFloat(0.0,local_14);
                fVar9 = GetRandomFloat(local_18);
                if (local_1c < fVar9) {
                  local_14 = (float)((uint)local_14 ^ __xmm_80000000800000008000000080000000);
                }
                local_8 = local_14 + local_8;
                fVar9 = GetRandomFloat(local_18);
                if (local_1c < fVar9) {
                  local_8 = (float)((uint)local_8 ^ __xmm_80000000800000008000000080000000);
                }
                if (__real_bf800000 <= local_8) {
                  if (__real_3f800000 < local_8) {
                    local_8 = 1.0;
                  }
                }
                else {
                  local_8 = -1.0;
                }
              }
              iVar5 = (*local_24)(pcVar7,local_20,local_8,*(float *)(pcVar7 + 0x54),1,pcVar7[0x48]);
            }
            else {
              VVar1.z = 0.0;
              VVar1._0_8_ = *(ulonglong *)(extraout_ECX + 1);
              iVar5 = StartAudio3D((char *)*extraout_ECX,VVar1,unaff_EDI,SUB41(unaff_ESI,0));
            }
            ((AmbientAudioInfo *)(pcVar7 + -4))->AudioHandle = iVar5;
            fVar9 = GetAudioFileDuration(iVar5);
            iVar5 = SecondsToTurns(fVar9);
            *(int *)(pcVar7 + 0x5c) = iVar5;
            iVar5 = GetRandomInt(unaff_EDI,unaff_ESI);
            *(int *)(pcVar7 + 0x58) = iVar5 + BZ1Helper::m_TurnCounter + *(int *)(pcVar7 + 0x5c);
          }
          iVar5 = local_c;
          pcVar8 = local_10;
        }
        else if (0 < *(int *)(pcVar7 + 0x44)) {
          pcVar6 = local_4;
          if (*(int *)(pcVar7 + 0x58) - *(int *)(pcVar7 + 0x5c) <= BZ1Helper::m_TurnCounter) {
            ((AmbientAudioInfo *)(pcVar7 + -4))->AudioHandle = 0;
          }
          goto LAB_4fc14563;
        }
      }
      pcVar6 = local_4;
    }
LAB_4fc14563:
    pcVar7 = pcVar7 + 0x70;
    local_c = iVar5 + -1;
    if (local_c == 0) {
      return;
    }
  } while( true );
}

