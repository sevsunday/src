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

bool __thiscall AmbientSoundHelper::Load(AmbientSoundHelper *this,bool missionSave)

{
  bool bVar1;
  bool bVar2;
  AmbientAudioInfo *pAVar3;
  AmbientAudioInfo *pAVar4;
  char *pcVar5;
  int iVar6;
  char *pcVar7;
  int local_18;
  AmbientAudioInfo *local_c;
  
  if (missionSave) {
    bVar1 = true;
  }
  else {
    pcVar5 = this[-0x5b2d6].ambientAudioInfo[0x1e].AudioFile + 0x1c;
    local_c = TempAmbientSoundBuffer;
    pAVar3 = TempAmbientSoundBuffer;
    do {
      pAVar4 = pAVar3 + 1;
      pcVar7 = pcVar5 + (int)pAVar3;
      for (iVar6 = 0x1c; iVar6 != 0; iVar6 = iVar6 + -1) {
        pAVar3->AudioHandle = *(int *)pcVar7;
        pcVar7 = pcVar7 + 4;
        pAVar3 = (AmbientAudioInfo *)pAVar3->AudioFile;
      }
      pAVar3 = pAVar4;
    } while ((int)pAVar4 < 0x4fc7b4c0);
    bVar1 = true;
    local_18 = 0;
    iVar6 = 0x20;
    do {
      if ((bVar1 == false) || (bVar1 = Read(this,0x70), !bVar1)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      this = (AmbientSoundHelper *)((int)this + 0x70);
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
    do {
      bVar2 = ::operator==(local_c,(AmbientAudioInfo *)
                                   (pcVar5 + (int)local_c[0x1e].AudioFile + -0xd24));
      if (!bVar2) {
        FormatLogMessage("AmbientAudioInfo Load Mismatch Index: %d",local_18);
        return bVar1;
      }
      local_18 = local_18 + 1;
      local_c = local_c + 1;
    } while ((int)local_c < 0x4fc7b4c0);
  }
  return bVar1;
}


// ---------------------------------------------------------------------
// AmbientSoundHelper::LoadAmbientSoundInfo  @ 4fc140d9  lines 55-94

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall AmbientSoundHelper::LoadAmbientSoundInfo(AmbientSoundHelper *this,char *mapTrnFile)

{
  float *pfVar1;
  Vector *pVVar2;
  Vector VVar3;
  bool bVar4;
  float fVar5;
  int fmtarg1;
  Vector *pVVar6;
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
  local_54 = mapTrnFile;
  bVar4 = OpenODF2(mapTrnFile);
  if (bVar4) {
    local_50 = 0;
    local_4c = 0;
    fmtarg1 = 1;
    local_48 = 0.0;
    pVVar6 = &this->ambientAudioInfo[0].Position;
    local_58 = 0x20;
    do {
      memset(local_44,0,0x40);
      sprintf_s<64>(&local_44,"AmbientSound%d",fmtarg1);
      GetODFString(mapTrnFile,"Audio",local_44,0x40,(char *)(pVVar6 + -8),(char *)0x0);
      sprintf_s<64>(&local_44,"Position%d",fmtarg1);
      mapTrnFile = local_54;
      VVar3.y = (float)local_4c;
      VVar3.x = (float)local_50;
      VVar3.z = local_48;
      GetODFVector(local_54,"Audio",local_44,pVVar6,VVar3);
      sprintf_s<64>(&local_44,"IsMusic%d",fmtarg1);
      GetODFBool(mapTrnFile,"Audio",local_44,(bool *)(pVVar6 + -2),false);
      sprintf_s<64>(&local_44,"MinDelay%d",fmtarg1);
      local_60 = 0.0;
      GetODFFloat(mapTrnFile,"Audio",local_44,&local_60,0.0);
      fVar5 = (float)SecondsToTurns(local_60);
      pVVar6[-3].y = fVar5;
      sprintf_s<64>(&local_44,"MaxDelay%d",fmtarg1);
      local_5c = 0.0;
      GetODFFloat(mapTrnFile,"Audio",local_44,&local_5c,0.0);
      fVar5 = (float)SecondsToTurns(local_5c);
      pVVar6[-3].z = fVar5;
      sprintf_s<64>(&local_44,"BasePan%d",fmtarg1);
      GetODFFloat(mapTrnFile,"Audio",local_44,&pVVar6[-2].y,0.0);
      fVar5 = pVVar6[-2].y;
      fVar7 = -1.0;
      if ((fVar5 < -1.0) || (fVar7 = 1.0, 1.0 < fVar5)) {
        fVar5 = fVar7;
      }
      pVVar6[-2].y = fVar5;
      sprintf_s<64>(&local_44,"PanVariance%d",fmtarg1);
      pfVar1 = &pVVar6[-2].z;
      GetODFFloat(mapTrnFile,"Audio",local_44,pfVar1,0.0);
      fVar5 = *pfVar1;
      fVar7 = 0.0;
      if ((fVar5 < 0.0) || (fVar7 = 1.0, 1.0 < fVar5)) {
        fVar5 = fVar7;
      }
      *pfVar1 = fVar5;
      sprintf_s<64>(&local_44,"Rate%d",fmtarg1);
      pVVar2 = pVVar6 + -1;
      GetODFFloat(mapTrnFile,"Audio",local_44,&pVVar2->x,44100.0);
      fVar5 = pVVar2->x;
      fVar7 = 0.0;
      if ((fVar5 < 0.0) || (fVar7 = 44100.0, 44100.0 < fVar5)) {
        fVar5 = fVar7;
      }
      fmtarg1 = fmtarg1 + 1;
      pVVar2->x = fVar5;
      pVVar6 = (Vector *)&pVVar6[9].y;
      local_58 = local_58 + -1;
    } while (local_58 != 0);
  }
  return;
}


// ---------------------------------------------------------------------
// AmbientSoundHelper::Execute  @ 4fc1434e  lines 97-184

void __thiscall AmbientSoundHelper::Execute(AmbientSoundHelper *this,BZ1Helper *param_1)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  Vector *extraout_ECX;
  code *pcVar4;
  Vector *extraout_ECX_00;
  undefined4 extraout_EDX;
  char *name;
  code *pcVar5;
  float fVar6;
  DLLAudioCategory DVar7;
  int local_28;
  code *local_24;
  undefined4 local_20;
  float local_1c;
  float local_18;
  float local_14;
  code *local_10;
  int local_c;
  float local_8;
  code *local_4;
  
  local_18 = 1.0;
  name = this->ambientAudioInfo[0].AudioFile;
  local_1c = 0.5;
  local_24 = StartAudio2D_exref;
  local_20 = 0xbf800000;
  local_c = 0x20;
  local_4 = DoesFileExist_exref;
  local_10 = IsAudioPlaying_exref;
  pcVar4 = DoesFileExist_exref;
  pcVar5 = IsAudioPlaying_exref;
  do {
    iVar3 = local_c;
    if (((*name != '\0') && (cVar1 = (*pcVar4)(name), pcVar4 = local_4, cVar1 != '\0')) &&
       (*(int *)(name + 0x58) <= BZ1Helper::m_TurnCounter)) {
      local_28 = ((AmbientAudioInfo *)(name + -4))->AudioHandle;
      cVar1 = (*pcVar5)(&local_28);
      if (cVar1 == '\0') {
        if (*(int *)(name + 0x44) < 1) {
          bVar2 = IsNullVector(*(Vector *)(name + 0x60));
          if (bVar2) {
            iVar3 = (*local_24)(name,local_20,*(float *)(name + 0x4c),*(float *)(name + 0x54),1,
                                extraout_EDX);
          }
          else {
            if ((char)extraout_EDX == '\0') {
              DVar7 = AUDIO_CAT_AMBIENT;
            }
            else {
              DVar7 = AUDIO_CAT_MUSIC;
            }
            iVar3 = StartAudio3D(name,*extraout_ECX_00,DVar7,true);
          }
          ((AmbientAudioInfo *)(name + -4))->AudioHandle = iVar3;
          pcVar4 = local_4;
          iVar3 = local_c;
          pcVar5 = local_10;
        }
        else {
          bVar2 = IsNullVector(*(Vector *)(name + 0x60));
          if (bVar2) {
            local_8 = *(float *)(name + 0x4c);
            local_14 = *(float *)(name + 0x50);
            if (0.0 < local_14) {
              local_14 = GetRandomFloat(0.0,local_14);
              fVar6 = GetRandomFloat(local_18);
              if (local_1c < fVar6) {
                local_14 = -local_14;
              }
              local_8 = local_14 + local_8;
              fVar6 = GetRandomFloat(local_18);
              if (local_1c < fVar6) {
                local_8 = -local_8;
              }
              if (-1.0 <= local_8) {
                if (1.0 < local_8) {
                  local_8 = 1.0;
                }
              }
              else {
                local_8 = -1.0;
              }
            }
            iVar3 = (*local_24)(name,local_20,local_8,*(float *)(name + 0x54),1,name[0x48]);
          }
          else {
            if ((bool)name[0x48] == false) {
              DVar7 = AUDIO_CAT_AMBIENT;
            }
            else {
              DVar7 = AUDIO_CAT_MUSIC;
            }
            iVar3 = StartAudio3D(name,*extraout_ECX,DVar7,false);
          }
          ((AmbientAudioInfo *)(name + -4))->AudioHandle = iVar3;
          fVar6 = GetAudioFileDuration(iVar3);
          iVar3 = SecondsToTurns(fVar6);
          *(int *)(name + 0x5c) = iVar3;
          iVar3 = GetRandomInt(*(int *)(name + 0x40),*(int *)(name + 0x44));
          *(int *)(name + 0x58) = iVar3 + BZ1Helper::m_TurnCounter + *(int *)(name + 0x5c);
          pcVar4 = local_4;
          iVar3 = local_c;
          pcVar5 = local_10;
        }
      }
      else {
        pcVar4 = local_4;
        if ((0 < *(int *)(name + 0x44)) &&
           (*(int *)(name + 0x58) - *(int *)(name + 0x5c) <= BZ1Helper::m_TurnCounter)) {
          ((AmbientAudioInfo *)(name + -4))->AudioHandle = 0;
        }
      }
    }
    name = name + 0x70;
    local_c = iVar3 + -1;
  } while (local_c != 0);
  return;
}


