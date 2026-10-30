// Reconstructed by Ghidra from LuaMission.dll + LuaMission.pdb
// Original source file: /e:/github/vsr_dll_source/missions/vsrcore/ambientsoundhelper.cpp
// Functions are ordered by original source line. This is decompiler
// output, not the author's source: names/types come from the PDB,
// local variable names and control flow are reconstructed.


// ---------------------------------------------------------------------
// `dynamic_initializer_for_'TempAmbientSoundBuffer''  @ 4fc0136a  lines 7-7


void __cdecl _dynamic_initializer_for__TempAmbientSoundBuffer__(void)

{
  memset(TempAmbientSoundBuffer,0,0xe00);
  return;
}


// ---------------------------------------------------------------------
// AmbientSoundHelper::Load  @ 4fc27e2c  lines 17-39


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
      pcVar6 = this[-0x5b2cb].ambientAudioInfo[1].AudioFile + 0x2c + (int)pAVar3;
      for (iVar5 = 0x1c; iVar5 != 0; iVar5 = iVar5 + -1) {
        pAVar3->AudioHandle = *(int *)pcVar6;
        pcVar6 = pcVar6 + 4;
        pAVar3 = (AmbientAudioInfo *)pAVar3->AudioFile;
      }
      pAVar3 = pAVar4;
    } while ((int)pAVar4 < 0x4fc72760);
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
    } while ((int)local_c < 0x4fc72760);
  }
  return bVar1;
}


// ---------------------------------------------------------------------
// AmbientSoundHelper::LoadAmbientSoundInfo  @ 4fc27eee  lines 55-94


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
// AmbientSoundHelper::Execute  @ 4fc28163  lines 97-184


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall AmbientSoundHelper::Execute(AmbientSoundHelper *this,BZ1Helper *param_1)

{
  char cVar1;
  int iVar2;
  code *pcVar3;
  char *pcVar4;
  int unaff_ESI;
  int unaff_EDI;
  code *pcVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  undefined4 uVar9;
  int local_2c;
  code *local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  code *local_14;
  code *local_10;
  int local_c;
  float local_8;
  code *local_4;
  
  local_1c = 1.0;
  pcVar4 = this->ambientAudioInfo[0].AudioFile;
  local_20 = __real_3f000000;
  local_28 = StartAudio2D_exref;
  local_24 = __real_bf800000;
  local_c = 0x20;
  local_4 = DoesFileExist_exref;
  local_14 = IsAudioPlaying_exref;
  local_10 = StartAudio3D_exref;
  pcVar3 = DoesFileExist_exref;
  pcVar5 = IsAudioPlaying_exref;
  do {
    iVar2 = local_c;
    if (*pcVar4 != '\0') {
      cVar1 = (*pcVar3)(pcVar4);
      if ((cVar1 != '\0') && (*(int *)(pcVar4 + 0x58) <= BZ1Helper::m_TurnCounter)) {
        local_2c = ((AmbientAudioInfo *)(pcVar4 + -4))->AudioHandle;
        cVar1 = (*pcVar5)(&local_2c);
        if (cVar1 == '\0') {
          if (*(int *)(pcVar4 + 0x44) < 1) {
            fVar6 = ((Vector *)(pcVar4 + 0x60))->x;
            if (__real_3dcccccd <=
                *(float *)(pcVar4 + 100) * *(float *)(pcVar4 + 100) + fVar6 * fVar6 +
                *(float *)(pcVar4 + 0x68) * *(float *)(pcVar4 + 0x68)) {
              if ((bool)pcVar4[0x48] == false) {
                fVar6 = ((Vector *)(pcVar4 + 0x60))->x;
                uVar9 = 8;
                fVar7 = *(float *)(pcVar4 + 100);
                fVar8 = *(float *)(pcVar4 + 0x68);
              }
              else {
                fVar6 = ((Vector *)(pcVar4 + 0x60))->x;
                uVar9 = 9;
                fVar7 = *(float *)(pcVar4 + 100);
                fVar8 = *(float *)(pcVar4 + 0x68);
              }
              iVar2 = (*local_10)(pcVar4,fVar6,fVar7,fVar8,uVar9,1);
            }
            else {
              iVar2 = (*local_28)(pcVar4,local_24,*(float *)(pcVar4 + 0x4c),
                                  *(float *)(pcVar4 + 0x54),1,pcVar4[0x48]);
            }
            ((AmbientAudioInfo *)(pcVar4 + -4))->AudioHandle = iVar2;
          }
          else {
            fVar6 = ((Vector *)(pcVar4 + 0x60))->x;
            if (__real_3dcccccd <=
                *(float *)(pcVar4 + 100) * *(float *)(pcVar4 + 100) + fVar6 * fVar6 +
                *(float *)(pcVar4 + 0x68) * *(float *)(pcVar4 + 0x68)) {
              if ((bool)pcVar4[0x48] == false) {
                fVar6 = ((Vector *)(pcVar4 + 0x60))->x;
                uVar9 = 8;
                fVar7 = *(float *)(pcVar4 + 100);
                fVar8 = *(float *)(pcVar4 + 0x68);
              }
              else {
                fVar6 = ((Vector *)(pcVar4 + 0x60))->x;
                uVar9 = 9;
                fVar7 = *(float *)(pcVar4 + 100);
                fVar8 = *(float *)(pcVar4 + 0x68);
              }
              iVar2 = (*local_10)(pcVar4,fVar6,fVar7,fVar8,uVar9,0);
            }
            else {
              local_8 = *(float *)(pcVar4 + 0x4c);
              local_18 = *(float *)(pcVar4 + 0x50);
              if (___real_00000000 < local_18) {
                local_18 = GetRandomFloat(0.0,local_18);
                fVar6 = GetRandomFloat(local_1c);
                if (local_20 < fVar6) {
                  local_18 = (float)((uint)local_18 ^ __xmm_80000000800000008000000080000000);
                }
                local_8 = local_18 + local_8;
                fVar6 = GetRandomFloat(local_1c);
                if (local_20 < fVar6) {
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
              iVar2 = (*local_28)(pcVar4,local_24,local_8,*(float *)(pcVar4 + 0x54),1,pcVar4[0x48]);
            }
            ((AmbientAudioInfo *)(pcVar4 + -4))->AudioHandle = iVar2;
            fVar6 = GetAudioFileDuration(iVar2);
            iVar2 = SecondsToTurns(fVar6);
            *(int *)(pcVar4 + 0x5c) = iVar2;
            iVar2 = GetRandomInt(unaff_EDI,unaff_ESI);
            *(int *)(pcVar4 + 0x58) = iVar2 + *(int *)(pcVar4 + 0x5c) + BZ1Helper::m_TurnCounter;
          }
          iVar2 = local_c;
          pcVar5 = local_14;
        }
        else if (0 < *(int *)(pcVar4 + 0x44)) {
          pcVar3 = local_4;
          if (*(int *)(pcVar4 + 0x58) - *(int *)(pcVar4 + 0x5c) <= BZ1Helper::m_TurnCounter) {
            ((AmbientAudioInfo *)(pcVar4 + -4))->AudioHandle = 0;
          }
          goto LAB_4fc283f8;
        }
      }
      pcVar3 = local_4;
    }
LAB_4fc283f8:
    pcVar4 = pcVar4 + 0x70;
    local_c = iVar2 + -1;
    if (local_c == 0) {
      return;
    }
  } while( true );
}

