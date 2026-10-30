// Reconstructed by Ghidra from Strategy02.dll + Strategy02.pdb
// Original source file: /e:/github/vsr_dll_source/missions/vsrcore/morphobjecthelper.cpp
// Functions are ordered by original source line. This is decompiler
// output, not the author's source: names/types come from the PDB,
// local variable names and control flow are reconstructed.

// ---------------------------------------------------------------------
// `dynamic_initializer_for_'TempMorphObjectBuffer''  @ 4fc01501  lines 8-8

void __cdecl _dynamic_initializer_for__TempMorphObjectBuffer__(void)

{
  atexit(_dynamic_atexit_destructor_for__TempMorphObjectBuffer__);
  return;
}


// ---------------------------------------------------------------------
// MorphObjectHelper::~MorphObjectHelper  @ 4fc164e8  lines 18-20

void __thiscall MorphObjectHelper::~MorphObjectHelper(MorphObjectHelper *this)

{
  m_MorphObjectHelper = (MorphObjectHelper *)0x0;
  this->vfptr = (int)vftable;
  std::
  vector<MorphObjectHelper::MorphObjectClass,std::allocator<MorphObjectHelper::MorphObjectClass>_>::
  _Tidy(&this->MorphObjectList);
  return;
}


// ---------------------------------------------------------------------
// MorphObjectHelper::PostLoad  @ 4fc164fd  lines 43-67

bool __thiscall MorphObjectHelper::PostLoad(MorphObjectHelper *this,bool param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  
  piVar5 = *(int **)&this->MorphObjectList;
  if (piVar5 != *(int **)&(this->MorphObjectList).field_0x4) {
    do {
      ConvertHandles(piVar5,1);
      ConvertHandles(piVar5 + 1,1);
      piVar5 = piVar5 + 0x52;
    } while (piVar5 != *(int **)&(this->MorphObjectList).field_0x4);
  }
  iVar4 = *(int *)&this->MorphObjectList;
  iVar2 = (*(int *)&(this->MorphObjectList).field_0x4 - iVar4) / 0x148;
  iVar3 = (int)(TempMorphObjectBuffer._4_4_ - TempMorphObjectBuffer._0_4_) / 0x148;
  if (iVar3 == iVar2) {
    iVar3 = 0;
    if (0 < iVar2) {
      iVar2 = 0;
      do {
        bVar1 = ::operator==((MorphObjectClass *)(iVar2 + TempMorphObjectBuffer._0_4_),
                             (MorphObjectClass *)(iVar2 + iVar4));
        if (!bVar1) {
          FormatLogMessage("MorphObjectList Index Mismatch: %d",iVar3);
          return true;
        }
        iVar4 = *(int *)&this->MorphObjectList;
        iVar3 = iVar3 + 1;
        iVar2 = iVar2 + 0x148;
      } while (iVar3 < (*(int *)&(this->MorphObjectList).field_0x4 - iVar4) / 0x148);
    }
  }
  else {
    FormatLogMessage("MorphObjectList Size Mismatch! Old: %d New: %d",iVar3,iVar2);
  }
  return true;
}


// ---------------------------------------------------------------------
// MorphObjectHelper::AddMorphObjectHostObject  @ 4fc165b2  lines 86-133

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall
MorphObjectHelper::AddMorphObjectHostObject
          (MorphObjectHelper *this,int h,char *TempODF1,char *TempODF2)

{
  vector<MorphObjectHelper::MorphObjectClass,std::allocator<MorphObjectHelper::MorphObjectClass>_>
  *_Udefault_or_fill;
  bool bVar1;
  char *pcVar2;
  long lVar3;
  int iVar4;
  DispatchHelper *this_00;
  int iVar5;
  int *piVar6;
  float *pfVar7;
  float fVar8;
  char *local_4c;
  char *local_48;
  char local_44 [64];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)&local_4c;
  local_48 = TempODF1;
  local_4c = TempODF2;
  if (BZ1Helper::m_BZ1Helper->StopAddMorphObject == false) {
    _Udefault_or_fill = &this->MorphObjectList;
    for (piVar6 = *(int **)_Udefault_or_fill; piVar6 != *(int **)&(this->MorphObjectList).field_0x4;
        piVar6 = piVar6 + 0x52) {
      if (*piVar6 == h) {
        return;
      }
    }
    std::
    vector<MorphObjectHelper::MorphObjectClass,std::allocator<MorphObjectHelper::MorphObjectClass>_>
    ::_Resize<<lambda_6e1c0ab678e9364d699d8dd7ba7d9fb6>_>
              (_Udefault_or_fill,
               (*(int *)&(this->MorphObjectList).field_0x4 - *(int *)_Udefault_or_fill) / 0x148 + 1,
               (<lambda_6e1c0ab678e9364d699d8dd7ba7d9fb6>)_Udefault_or_fill);
    iVar5 = 0;
    piVar6 = (int *)(*(int *)_Udefault_or_fill + -0x148 +
                    ((*(int *)&(this->MorphObjectList).field_0x4 - *(int *)_Udefault_or_fill) /
                    0x148) * 0x148);
    memset(piVar6,0,0x148);
    pcVar2 = GetConfigODF(h);
    bVar1 = DoesFileExist(pcVar2);
    if (bVar1) {
      DispatchHelper::ReadChanceValues(this_00,pcVar2,"CloakChance",(float *)(piVar6 + 0x13),0.0);
    }
    GetODFBool(local_48,local_4c,"CraftClass","CanAICloak",(bool *)((int)piVar6 + 0xb),false);
    pcVar2 = local_48;
    if (*(bool *)((int)piVar6 + 0xb) != false) {
      GetODFLong(local_48,local_4c,"GameObjectClass","MaxCloakEnergy",piVar6 + 0x4d,0);
      pcVar2 = local_48;
      piVar6[0x4e] = piVar6[0x4d];
      GetODFLong(local_48,local_4c,"GameObjectClass","CloakEnergyCost",piVar6 + 0x4f,0);
      GetODFLong(pcVar2,local_4c,"GameObjectClass","AddCloakEnergy",piVar6 + 0x50,0);
    }
    fVar8 = GetEngageRange(h);
    piVar6[0x12] = (int)fVar8;
    memset(local_44,0,0x40);
    GetODFString(pcVar2,local_4c,"MorphObjectClass","SwitchODF",0x40,local_44,(char *)0x0);
    if ((local_44[0] != '\0') && (bVar1 = DoesODFExist(local_44), bVar1)) {
      PreloadODF(local_44);
    }
    *piVar6 = h;
    lVar3 = GetMaxAmmo(h);
    piVar6[5] = lVar3;
    iVar4 = SecondsToTurns(30.0);
    piVar6[3] = iVar4 + BZ1Helper::m_TurnCounter;
    pfVar7 = (float *)(piVar6 + 0xd);
    do {
      fVar8 = GetMaxLocalAmmo(h,iVar5);
      *pfVar7 = fVar8;
      iVar5 = iVar5 + 1;
      pfVar7 = pfVar7 + 1;
    } while (iVar5 < 5);
  }
  return;
}


// ---------------------------------------------------------------------
// MorphObjectHelper::AddMorphObjectToggleObject  @ 4fc167a0  lines 137-177

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall MorphObjectHelper::AddMorphObjectToggleObject(MorphObjectHelper *this,int h)

{
  int h_00;
  bool bVar1;
  int iVar2;
  int *piVar3;
  float fVar4;
  float BestDistanceSquared;
  char SoundFile [64];
  uint local_8;
  
  local_8 = __security_cookie ^ (uint)&stack0xfffffffc;
  BestDistanceSquared = 3.4028235e+38;
  piVar3 = *(int **)&this->MorphObjectList;
  if (piVar3 != *(int **)&(this->MorphObjectList).field_0x4) {
    do {
      fVar4 = GetDistance3DSquared(h,*piVar3);
      if (((fVar4 < BestDistanceSquared) && (h != *piVar3)) &&
         (BestDistanceSquared = fVar4, fVar4 < 25.0)) {
        if ((char)piVar3[2] == '\0') {
          if ((*(char *)((int)piVar3 + 0xb) == '\0') || ((char)piVar3[0x4c] == '\0')) {
            *(undefined2 *)(piVar3 + 2) = 0x101;
          }
          else {
            h_00 = *piVar3;
            iVar2 = GetPlayerHandle();
            if (h_00 == iVar2) {
              memset(SoundFile,0,0x40);
              GetODFString(h_00,"GameObjectClass","CloakFailSound",0x40,SoundFile,(char *)0x0);
              bVar1 = DoesFileExist(SoundFile);
              if (bVar1) {
                StartAudio2D(SoundFile,-1.0,0.0,11025.0,false,false);
              }
            }
          }
        }
        else {
          *(undefined2 *)(piVar3 + 2) = 0x100;
        }
        break;
      }
      piVar3 = piVar3 + 0x52;
    } while (piVar3 != *(int **)&(this->MorphObjectList).field_0x4);
  }
  BZ1Helper::DeleteAfterDelay(BZ1Helper::m_BZ1Helper,h,0.0);
  return;
}


// ---------------------------------------------------------------------
// MorphObjectHelper::Execute  @ 4fc168ca  lines 180-514

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall MorphObjectHelper::Execute(MorphObjectHelper *this,BZ1Helper *bz1Helper)

{
  Vector NewWhere;
  BZ1Helper *this_00;
  code *pcVar1;
  bool bVar2;
  char cVar3;
  undefined4 uVar4;
  float fVar5;
  int iVar6;
  float *pfVar7;
  int iVar8;
  MorphObjectHelper *this_01;
  AlignTerrainReplaceClass *entry;
  AlignTerrainReplaceClass *entry_00;
  char *pcVar9;
  code *pcVar10;
  AlignTerrainReplaceClass *pAVar11;
  float *pfVar12;
  size_t sVar13;
  float *pfVar14;
  float *pfVar15;
  float NewCommand;
  float NewWho;
  float fVar16;
  float fVar17;
  float fVar18;
  double dStack_3e0;
  float *local_3d8;
  bool bStack_3d1;
  float *local_3d0;
  float *local_3cc;
  float *pfStack_3c8;
  code *local_3c4;
  uint uStack_3c0;
  float local_3bc;
  code *local_3b8;
  AlignTerrainReplaceClass *local_3b4;
  code *local_3b0;
  float *local_3ac;
  code *local_3a8;
  undefined4 local_3a4;
  MorphObjectHelper *local_3a0;
  code *local_39c;
  code *local_398;
  code *local_394;
  code *local_390;
  code *local_38c;
  code *local_388;
  BZ1Helper *local_384;
  code *local_380;
  code *local_37c;
  code *local_378;
  code *local_374;
  undefined4 local_370;
  float local_36c;
  undefined4 local_368;
  undefined4 local_364;
  undefined4 local_360;
  code *local_35c;
  code *local_358;
  code *local_354;
  code *local_350;
  float *local_34c;
  code *local_348;
  code *local_344;
  undefined4 uStack_340;
  undefined4 uStack_33c;
  undefined4 uStack_338;
  undefined4 uStack_334;
  undefined4 uStack_330;
  undefined4 uStack_32c;
  AlignTerrainReplaceClass *local_328;
  AlignTerrainReplaceClass *local_324;
  double local_320;
  undefined1 auStack_314 [12];
  char acStack_308 [64];
  char acStack_2c8 [64];
  char acStack_288 [64];
  char acStack_248 [64];
  char acStack_208 [64];
  char acStack_1c8 [64];
  char acStack_188 [64];
  char acStack_148 [324];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)&dStack_3e0;
  local_384 = bz1Helper;
  pAVar11 = *(AlignTerrainReplaceClass **)&(this->MorphObjectList).field_0x4;
  entry = *(AlignTerrainReplaceClass **)&this->MorphObjectList;
  local_3b4 = pAVar11;
  local_3a0 = this;
  local_328 = pAVar11;
  local_324 = entry;
  while ((entry != pAVar11 && (bVar2 = BZ1Helper::ShouldRemoveAlignTerrainReplace(entry), !bVar2)))
  {
    entry = (AlignTerrainReplaceClass *)&entry[0x14].NormalVec.y;
  }
  entry_00 = entry;
  if (entry != pAVar11) {
    while (this = local_3a0, entry_00 = (AlignTerrainReplaceClass *)&entry_00[0x14].NormalVec.y,
          entry_00 != pAVar11) {
      bVar2 = BZ1Helper::ShouldRemoveAlignTerrainReplace(entry_00);
      if (!bVar2) {
        pfVar12 = (float *)entry_00;
        pAVar11 = entry;
        for (iVar8 = 0x52; iVar8 != 0; iVar8 = iVar8 + -1) {
          pAVar11->AlignHandle = (int)*pfVar12;
          pfVar12 = pfVar12 + 1;
          pAVar11 = (AlignTerrainReplaceClass *)&pAVar11->NormalVec;
        }
        entry = (AlignTerrainReplaceClass *)&entry[0x14].NormalVec.y;
        pAVar11 = local_3b4;
      }
    }
    if (entry != pAVar11) {
      sVar13 = *(int *)&(local_3a0->MorphObjectList).field_0x4 - (int)pAVar11;
      memmove(entry,pAVar11,sVar13);
      local_34c = (float *)(sVar13 + (int)entry);
      *(float **)&(this->MorphObjectList).field_0x4 = local_34c;
      goto LAB_4fc16977;
    }
  }
  local_34c = *(float **)&(this->MorphObjectList).field_0x4;
LAB_4fc16977:
  pfVar12 = *(float **)&this->MorphObjectList;
  if (pfVar12 != local_34c) {
    local_394 = GetCurAmmo_exref;
    local_398 = GetObjInfo_exref;
    local_38c = _stricmp_exref;
    local_388 = DoesODFExist_exref;
    local_3b8 = GetCurrentCommand_exref;
    local_3bc = 0.0;
    local_3b4 = (AlignTerrainReplaceClass *)DoesFileExist_exref;
    local_380 = StartAudio3D_exref;
    local_370 = 0x41700000;
    local_3b0 = SetPerceivedTeam_exref;
    local_3a8 = GetPlayerHandle_exref;
    local_36c = 1.0;
    local_37c = SetCurLocalAmmo_exref;
    local_378 = IsPlayer_exref;
    local_320 = 50.0;
    local_374 = GetPlayerHandle_exref;
    local_3c4 = SetCommand_exref;
    local_368 = 0x41f00000;
    local_390 = SecondsToTurns_exref;
    local_35c = StartAudio2D_exref;
    local_364 = 0x462c4400;
    local_358 = BuildObject_exref;
    local_354 = GetCurrentWho_exref;
    local_360 = 0xbf800000;
    local_348 = GetTeamNum_exref;
    local_344 = GetPerceivedTeam_exref;
    local_39c = SetCurAmmo_exref;
    local_350 = GetCurrentCommandWhere_exref;
    do {
      pcVar1 = local_344;
      pcVar10 = local_39c;
      local_3d8 = pfVar12;
      local_3d0 = pfVar12;
      local_3cc = pfVar12;
      local_3ac = pfVar12;
      uVar4 = (*local_348)(*pfVar12);
      local_3a4 = uVar4;
      fVar5 = (float)(*pcVar1)(*pfVar12);
      if (0 < (int)fVar5) {
        pfVar12[7] = fVar5;
      }
      iVar8 = (*misnImport.GetNearestEnemy)((int)*pfVar12);
      dStack_3e0 = (double)CONCAT44(dStack_3e0._4_4_,iVar8);
      if (*(char *)((int)pfVar12 + 9) == '\0') {
        if (*(char *)(pfVar12 + 2) != '\0') {
          fVar5 = (float)(*local_394)(*pfVar12);
          if (*(char *)((int)pfVar12 + 10) == '\0') {
            if (0 < (int)fVar5) {
              fVar16 = pfVar12[5];
              if ((int)pfVar12[4] + (int)fVar5 <= (int)pfVar12[5]) {
                fVar16 = (float)((int)pfVar12[4] + (int)fVar5);
              }
              pfVar12[4] = fVar16;
              (*pcVar10)(*pfVar12,0);
            }
            fVar5 = (float)(*local_3a8)();
            pfVar7 = local_3d8;
            if ((*pfVar12 == fVar5) && (pfStack_3c8 = (float *)pfVar12[5], 0 < (int)pfStack_3c8)) {
              pfStack_3c8 = (float *)(float)(int)pfStack_3c8;
              BZ1Helper::AmmoGauge2 = (float)(int)pfVar12[4] / (float)pfStack_3c8;
              BZ1Helper::AmmoGaugeSet = true;
              local_3d0 = local_3cc;
              pfVar12 = local_3cc;
            }
            iVar6 = 0;
            iVar8 = 0x20;
            do {
              fVar5 = GetMaxLocalAmmo((int)*pfVar12,iVar6);
              *(float *)(iVar8 + 0x14 + (int)pfVar7) = fVar5;
              pfVar15 = (float *)GetCurLocalAmmo((int)*pfVar12,iVar6);
              pfVar14 = (float *)(*(float *)(iVar8 + (int)pfVar12) + (float)pfVar15);
              local_3d8 = *(float **)(iVar8 + 0x14 + (int)pfVar7);
              pfStack_3c8 = pfVar14;
              if ((float)local_3d8 <= (float)pfVar14) {
                pfVar14 = local_3d8;
                pfStack_3c8 = pfVar15;
              }
              *(float **)(iVar8 + (int)local_3ac) = pfVar14;
              (*local_37c)(*pfVar12,local_3bc,iVar6);
              iVar8 = iVar8 + 4;
              iVar6 = iVar6 + 1;
            } while (iVar8 < 0x34);
            iVar8 = dStack_3e0._0_4_;
          }
          else {
            if (pfVar12[4] != fVar5) {
              pfVar12[4] = fVar5;
            }
            iVar6 = 0;
            pfVar7 = pfVar12 + 8;
            do {
              local_3d8 = (float *)GetCurLocalAmmo((int)*pfVar12,iVar6);
              if (*pfVar7 != (float)local_3d8) {
                *pfVar7 = (float)local_3d8;
              }
              iVar6 = iVar6 + 1;
              pfVar7 = pfVar7 + 1;
            } while (iVar6 < 5);
          }
          uVar4 = local_3a4;
          if (*(char *)((int)pfVar12 + 0xb) != '\0') {
            (*local_3b0)(*pfVar12,0);
            uVar4 = local_3a4;
          }
        }
        if (*(char *)((int)pfVar12 + 0xb) != '\0') {
          cVar3 = (*local_378)(*pfVar12);
          pcVar10 = local_3c4;
          if ((cVar3 == '\0') && (iVar6 = (*local_374)(uVar4), pcVar10 = local_3c4, iVar6 == 0)) {
            if (*(char *)(pfVar12 + 2) == '\0') {
              if ((int)pfVar12[3] <= BZ1Helper::m_TurnCounter) {
                iVar6 = (*local_3b8)(*pfVar12);
                pfStack_3c8 = (float *)GetRandomFloat(local_36c);
                if (iVar8 != 0) {
                  dStack_3e0 = (double)(pfVar12[0x12] + (float)local_320);
                  fVar16 = GetDistance3DSquared((int)*pfVar12,iVar8);
                  fVar5 = (float)((float10)dStack_3e0 * (float10)dStack_3e0);
                  dStack_3e0 = (double)CONCAT44(dStack_3e0._4_4_,fVar5);
                  pcVar10 = local_3c4;
                  if (fVar16 <= fVar5) goto LAB_4fc171ed;
                }
                pcVar10 = local_3c4;
                uVar4 = local_368;
                if ((float)pfStack_3c8 < pfVar12[iVar6 + 0x13]) {
                  (*local_3c4)(*pfVar12,0x15,0,0,0,0);
                  uVar4 = local_368;
                }
                goto LAB_4fc17141;
              }
            }
            else {
              dStack_3e0 = (double)pfVar12[0x12];
              fVar16 = GetDistance3DSquared((int)*pfVar12,iVar8);
              pcVar10 = local_3c4;
              fVar5 = (float)((float10)dStack_3e0 * (float10)dStack_3e0);
              dStack_3e0 = (double)CONCAT44(dStack_3e0._4_4_,fVar5);
              if (fVar16 < fVar5) {
                (*local_3c4)(*pfVar12,0x15,0,0,0,0);
                uVar4 = local_370;
LAB_4fc17141:
                iVar8 = (*local_390)(uVar4);
                pfVar12[3] = (float)(iVar8 + BZ1Helper::m_TurnCounter);
              }
            }
          }
LAB_4fc171ed:
          pfVar7 = pfVar12 + 0x4d;
          if (0 < (int)*pfVar7) {
            fVar5 = local_3ac[0x4e];
            if (*(char *)(pfVar12 + 2) == '\0') {
              if ((int)fVar5 < (int)*pfVar7) {
                local_3d8 = (float *)((float)(int)pfVar12[0x50] / (float)BZ1Helper::m_GameTPS +
                                     pfVar12[0x51]);
                fVar5 = (float)(int)(float)local_3d8;
                dStack_3e0 = (double)CONCAT44(dStack_3e0._4_4_,fVar5);
                pfVar12[0x51] = (float)local_3d8 - fVar5;
                local_3d0 = local_3cc;
                pfVar12 = local_3cc + 0x4e;
                *pfVar12 = (float)((int)*pfVar12 + (int)(float)local_3d8);
                if ((int)*pfVar12 < 0) {
                  fVar5 = 0.0;
                }
                else {
                  fVar5 = local_3cc[0x4e];
                  if ((int)*pfVar7 < (int)local_3cc[0x4e]) {
                    fVar5 = *pfVar7;
                  }
                }
                local_3cc[0x4e] = fVar5;
                pfVar12 = local_3cc;
              }
              if (*(char *)(pfVar12 + 0x4c) == '\0') {
                if ((int)fVar5 < (int)*pfVar7) {
                  *(undefined1 *)(pfVar12 + 0x4c) = 1;
                }
                else {
LAB_4fc173cb:
                  *(undefined1 *)(pfVar12 + 0x4c) = 0;
                }
              }
              else if ((int)*pfVar7 <= (int)fVar5) goto LAB_4fc173cb;
            }
            else {
              if (0 < (int)fVar5) {
                local_3d8 = (float *)((float)(int)pfVar12[0x4f] / (float)BZ1Helper::m_GameTPS +
                                     pfVar12[0x51]);
                fVar5 = (float)(int)(float)local_3d8;
                dStack_3e0 = (double)CONCAT44(dStack_3e0._4_4_,fVar5);
                pfVar12[0x51] = (float)local_3d8 - fVar5;
                local_3d0 = local_3cc;
                pfVar12 = local_3cc + 0x4e;
                *pfVar12 = (float)((int)*pfVar12 - (int)(float)local_3d8);
                if ((int)*pfVar12 < 0) {
                  fVar5 = 0.0;
                }
                else {
                  fVar5 = local_3cc[0x4e];
                  if ((int)*pfVar7 < (int)local_3cc[0x4e]) {
                    fVar5 = *pfVar7;
                  }
                }
                local_3cc[0x4e] = fVar5;
                pfVar12 = local_3cc;
              }
              if ((*(char *)(pfVar12 + 0x4c) != '\0') || (fVar5 == 0.0)) {
                (*pcVar10)(*pfVar12,0x15,0,0,0,0);
                fVar5 = *pfVar12;
                fVar16 = (float)(*local_3a8)();
                if (fVar5 == fVar16) {
                  memset(acStack_208,0,0x40);
                  GetODFString((int)fVar5,"GameObjectClass","CloakFailSound",0x40,acStack_208,
                               (char *)0x0);
                  cVar3 = (*(code *)local_3b4)(acStack_208);
                  if (cVar3 != '\0') {
                    (*local_35c)(acStack_208,local_360,local_3bc,local_364,0,0);
                  }
                }
              }
            }
            fVar5 = (float)(*local_3a8)();
            if (*pfVar12 == fVar5) {
              dStack_3e0 = (double)CONCAT44(dStack_3e0._4_4_,(float)(int)*pfVar7);
              BZ1Helper::CloakGauge = (float)(int)pfVar12[0x4e] / (float)(int)*pfVar7;
              BZ1Helper::CloakGaugeSet = true;
              local_3d0 = local_3cc;
              pfVar12 = local_3cc;
            }
          }
        }
        iVar8 = (*local_3b8)(*pfVar12);
        if (iVar8 == 0x15) {
          memset(acStack_188,0,0x40);
          GetSwitchMineODF(this_01,(int)*pfVar12,acStack_188);
          (*local_358)(acStack_188,local_3a4,*pfVar12);
        }
      }
      else {
        iVar8 = 0;
        memset(acStack_308,0,0x40);
        bStack_3d1 = false;
        GetODFString((int)*pfVar12,"MorphObjectClass","SwitchODF",0x40,acStack_308,(char *)0x0);
        GetODFBool((int)*pfVar12,"MorphObjectClass","CanFireWhenSwitched",
                   (bool *)((int)pfVar12 + 10),true);
        GetODFBool((int)*pfVar12,"MorphObjectClass","SwitchAllWeapons",&bStack_3d1,true);
        if (*(char *)(pfVar12 + 2) != '\0') {
          GetODFBool((int)*pfVar12,"MorphObjectClass","CanFireWhenSwitched",
                     (bool *)((int)pfVar12 + 10),true);
          fVar5 = (float)(*local_394)(*pfVar12);
          pfVar12[4] = fVar5;
        }
        memset(acStack_148,0,0x140);
        local_3cc = pfVar12 + 0xd;
        pcVar9 = acStack_148;
        do {
          (*local_398)(*pfVar12,iVar8 + 5,pcVar9);
          uStack_3c0 = uStack_3c0 & 0xffffff00;
          memset(acStack_288,0,0x40);
          (*local_398)(*pfVar12,iVar8 + 10,acStack_288);
          pfVar7 = local_3cc;
          if (*(char *)(pfVar12 + 2) != '\0') {
            fVar5 = GetCurLocalAmmo((int)*pfVar12,iVar8);
            pfVar7 = local_3cc;
            local_3cc[-5] = fVar5;
            fVar5 = GetMaxLocalAmmo((int)*pfVar12,iVar8);
            *pfVar7 = fVar5;
          }
          bVar2 = OpenODF2(acStack_288);
          if (bVar2) {
            memset(acStack_2c8,0,0x40);
            iVar6 = GetODFString(acStack_288,(char *)0x0,"DispenserClass","objectClass",0x40,
                                 acStack_2c8,(char *)0x0);
            if (iVar6 == 0) goto LAB_4fc16ce6;
            memset(acStack_1c8,0,0x40);
            CombineStrings(acStack_2c8,acStack_2c8,".odf",0x40);
            bVar2 = OpenODF2(acStack_2c8);
            if ((!bVar2) ||
               (iVar6 = GetODFString(acStack_2c8,(char *)0x0,"GameObjectClass","BZCClasslabel",0x40,
                                     acStack_1c8,(char *)0x0), iVar6 == 0)) goto LAB_4fc16ce6;
            iVar6 = (*local_38c)(acStack_1c8,"MorphObjecttoggle");
            cVar3 = (char)uStack_3c0;
            if (iVar6 == 0) {
              cVar3 = '\x01';
            }
          }
          else {
LAB_4fc16ce6:
            cVar3 = (char)uStack_3c0;
          }
          if (bStack_3d1 == false) {
            if ((cVar3 != '\0') &&
               (iVar6 = GetODFString(acStack_288,(char *)0x0,"WeaponClass","altName",0x40,pcVar9,
                                     (char *)0x0), iVar6 != 0)) break;
          }
          else {
            GetODFString(acStack_288,(char *)0x0,"WeaponClass","altName",0x40,pcVar9,(char *)0x0);
          }
          iVar8 = iVar8 + 1;
          local_3cc = pfVar7 + 1;
          pcVar9 = pcVar9 + 0x40;
        } while (iVar8 < 5);
        if (acStack_308[0] != '\0') {
          cVar3 = (*local_388)(acStack_308);
          this_00 = local_384;
          pcVar10 = local_3b8;
          if (cVar3 == '\0') {
            FormatLogMessage("ERROR: SwitchODF \'%s\' does not exist. Fix ODFs!",acStack_308);
          }
          else {
            local_384->StopAddMorphObject = true;
            iVar8 = (*local_3b8)(*pfVar12);
            fVar5 = *pfVar12;
            if (iVar8 == 0x15) {
              NewCommand = pfVar12[6];
              fVar5 = (float)(*pcVar10)(fVar5);
              if ((NewCommand == fVar5) || (NewCommand == 2.94273e-44)) {
                uStack_340 = 0;
                uStack_33c = 0;
                uStack_338 = 0;
                fVar16 = 0.0;
                fVar17 = 0.0;
                fVar18 = 0.0;
                NewWho = -NAN;
                NewCommand = -NAN;
                bVar2 = false;
              }
              else {
                NewWho = local_3d0[1];
                bVar2 = true;
                fVar16 = pfVar12[0x49];
                fVar17 = pfVar12[0x4a];
                fVar18 = pfVar12[0x4b];
              }
              fVar5 = *local_3d0;
            }
            else {
              uStack_334 = 0;
              uStack_330 = 0;
              uStack_32c = 0;
              fVar16 = 0.0;
              fVar17 = 0.0;
              fVar18 = 0.0;
              NewWho = -NAN;
              NewCommand = -NAN;
              bVar2 = true;
            }
            NewWhere.y = fVar17;
            NewWhere.x = fVar16;
            NewWhere.z = fVar18;
            fVar5 = (float)BZ1Helper::ReplaceObject
                                     (this_00,(int)fVar5,acStack_308,-1,local_3bc,-1,false,-1,-1,
                                      bVar2,(int)NewCommand,0,(int)NewWho,NewWhere);
            *local_3d8 = fVar5;
            this_00->StopAddMorphObject = false;
            memset(acStack_248,0,0x40);
            pfVar12 = local_3d0;
            pcVar9 = "soundUndeploy";
            if (*(char *)(local_3d0 + 2) != '\0') {
              pcVar9 = "soundDeploy";
            }
            GetODFString((int)*local_3ac,"DeployableClass",pcVar9,0x40,acStack_248,(char *)0x0);
            cVar3 = (*(code *)local_3b4)(acStack_248);
            if (cVar3 == '\0') {
              if (acStack_248[0] != '\0') {
                FormatLogMessage("ERROR: Morph Object SoundDeploy \'%s\' Doesn\'t Exist! FIX ODFs!",
                                 acStack_248);
              }
            }
            else {
              (*local_380)(acStack_248,*pfVar12,7,0,1);
            }
            if (*(char *)((int)pfVar12 + 0xb) != '\0') {
              if (*(char *)(pfVar12 + 2) == '\0') {
                fVar5 = pfVar12[7];
              }
              else {
                fVar5 = 0.0;
              }
              (*local_3b0)(*pfVar12,fVar5);
            }
            if (*(char *)((int)pfVar12 + 10) == '\0') {
              if (*(char *)(pfVar12 + 2) == '\0') {
                fVar5 = pfVar12[4];
              }
              else {
                fVar5 = 0.0;
              }
              (*local_39c)(*pfVar12,fVar5);
            }
            *(undefined1 *)((int)pfVar12 + 9) = 0;
            ReplaceWeapons((int)*pfVar12,(char (*) [64])acStack_148,pfVar12 + 8,(char *)0x0);
          }
        }
      }
      iVar8 = (*local_3b8)(*pfVar12);
      if (iVar8 != 0x15) {
        fVar5 = (float)(*local_3b8)(*pfVar12);
        pfVar12[6] = fVar5;
        fVar5 = (float)(*local_354)(*pfVar12);
        pfVar12[1] = fVar5;
        fVar5 = pfVar12[6];
        if (((fVar5 == 4.2039e-45) || (fVar5 == 1.4013e-44)) || ((int)fVar5 - 0x1aU < 2)) {
          pfVar7 = (float *)(*local_350)(auStack_314,*pfVar12);
          pfVar12[0x49] = *pfVar7;
          pfVar12[0x4a] = pfVar7[1];
          pfVar12[0x4b] = pfVar7[2];
          pfVar12 = local_3d0;
        }
      }
      pfVar12 = pfVar12 + 0x52;
      local_34c = *(float **)&(local_3a0->MorphObjectList).field_0x4;
    } while (pfVar12 != local_34c);
  }
  return;
}


// ---------------------------------------------------------------------
// MorphObjectHelper::GetSwitchMineODF  @ 4fc174fc  lines 518-542

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall
MorphObjectHelper::GetSwitchMineODF(MorphObjectHelper *this,int param_1,char *param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  char local_c4 [64];
  char local_84 [64];
  char local_44 [64];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)local_c4;
  iVar3 = 0;
  do {
    memset(local_c4,0,0x40);
    GetObjInfo(param_1,iVar3 + Get_Weapon0ODF,local_c4);
    bVar1 = OpenODF2(local_c4);
    if (bVar1) {
      memset(local_84,0,0x40);
      iVar2 = GetODFString(local_c4,(char *)0x0,"DispenserClass","objectClass",0x40,MineObject,
                           (char *)0x0);
      if (iVar2 != 0) {
        memset(local_44,0,0x40);
        CombineStrings(local_84,MineObject,".odf",0x40);
        bVar1 = OpenODF2(local_84);
        if (bVar1) {
          iVar2 = GetODFString(local_84,(char *)0x0,"GameObjectClass","BZCClasslabel",0x40,local_44,
                               (char *)0x0);
          if (iVar2 != 0) {
            iVar2 = _stricmp(local_44,"MorphObjectToggle");
            if (iVar2 == 0) break;
          }
        }
      }
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 5);
  strcpy_s(param_2,0x40,MineObject);
  return;
}


// ---------------------------------------------------------------------
// MorphObjectHelper::PrePickupPowerup  @ 4fc1762e  lines 546-577

PrePickupPowerupReturnCodes __thiscall
MorphObjectHelper::PrePickupPowerup
          (MorphObjectHelper *this,int curWorld,int me,int powerupHandle,int ObjClassHash,
          char *PowerupODF)

{
  int *piVar1;
  
  if ((curWorld == 0) &&
     (piVar1 = *(int **)&this->MorphObjectList,
     piVar1 != *(int **)&(this->MorphObjectList).field_0x4)) {
    do {
      if (*piVar1 == me) {
        if ((char)piVar1[2] == '\0') {
          return PREPICKUPPOWERUP_ALLOW;
        }
        if (*(char *)((int)piVar1 + 10) != '\0') {
          return PREPICKUPPOWERUP_ALLOW;
        }
        if (piVar1[4] != piVar1[5]) {
          return PREPICKUPPOWERUP_ALLOW;
        }
        if (ObjClassHash != -0x599d55a0) {
          if (ObjClassHash != 0x33fe0a68) {
            return PREPICKUPPOWERUP_ALLOW;
          }
          GetHealth(me);
          return PREPICKUPPOWERUP_ALLOW;
        }
        return PREPICKUPPOWERUP_DENY;
      }
      piVar1 = piVar1 + 0x52;
    } while (piVar1 != *(int **)&(this->MorphObjectList).field_0x4);
  }
  return PREPICKUPPOWERUP_ALLOW;
}


