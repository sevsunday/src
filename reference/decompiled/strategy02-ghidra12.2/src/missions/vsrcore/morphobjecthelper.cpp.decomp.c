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
  this->_padding_ = (int)_vftable_;
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
  MorphObjectClass *unaff_ESI;
  int *piVar3;
  int iVar4;
  MorphObjectClass *unaff_EDI;
  
  piVar3 = *(int **)&this->MorphObjectList;
  if (piVar3 != *(int **)&(this->MorphObjectList).field_0x4) {
    do {
      ConvertHandles(piVar3,1);
      ConvertHandles(piVar3 + 1,1);
      piVar3 = piVar3 + 0x52;
    } while (piVar3 != *(int **)&(this->MorphObjectList).field_0x4);
  }
  iVar2 = (*(int *)&(this->MorphObjectList).field_0x4 - *(int *)&this->MorphObjectList) / 0x148;
  if ((int)(TempMorphObjectBuffer._4_4_ - TempMorphObjectBuffer._0_4_) / 0x148 == iVar2) {
    iVar4 = 0;
    if (0 < iVar2) {
      do {
        bVar1 = ::operator==(unaff_EDI,unaff_ESI);
        if (!bVar1) {
          FormatLogMessage("MorphObjectList Index Mismatch: %d");
          return true;
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < (*(int *)&(this->MorphObjectList).field_0x4 - *(int *)&this->MorphObjectList)
                       / 0x148);
    }
  }
  else {
    FormatLogMessage("MorphObjectList Size Mismatch! Old: %d New: %d");
  }
  return true;
}


// ---------------------------------------------------------------------
// MorphObjectHelper::AddMorphObjectHostObject  @ 4fc165b2  lines 86-133


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
MorphObjectHelper::AddMorphObjectHostObject
          (MorphObjectHelper *this,int param_1,char *param_2,char *param_3)

{
  vector<MorphObjectHelper::MorphObjectClass,std::allocator<MorphObjectHelper::MorphObjectClass>_>
  *this_00;
  bool bVar1;
  int *piVar2;
  char *pcVar3;
  long lVar4;
  int iVar5;
  DispatchHelper *this_01;
  int iVar6;
  long unaff_ESI;
  bool *unaff_EDI;
  int *piVar7;
  float *pfVar8;
  float fVar9;
  char *pcVar10;
  char *pcVar11;
  char *pcVar12;
  char *local_4c;
  char *local_48;
  char local_44 [64];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)&local_4c;
  local_48 = param_2;
  local_4c = param_3;
  if (BZ1Helper::m_BZ1Helper[1].teamInfo[0].PilotWeapon[4][0x22] == '\0') {
    this_00 = &this->MorphObjectList;
    for (piVar2 = *(int **)this_00; piVar2 != *(int **)&(this->MorphObjectList).field_0x4;
        piVar2 = piVar2 + 0x52) {
      if (*piVar2 == param_1) {
        return;
      }
    }
    std::
    vector<MorphObjectHelper::MorphObjectClass,std::allocator<MorphObjectHelper::MorphObjectClass>_>
    ::_Resize<<lambda_6e1c0ab678e9364d699d8dd7ba7d9fb6>_>
              (this_00,(*(int *)&(this->MorphObjectList).field_0x4 - *(int *)this_00) / 0x148 + 1,
               (<lambda_6e1c0ab678e9364d699d8dd7ba7d9fb6>)this_00);
    iVar6 = 0;
    piVar7 = (int *)(*(int *)this_00 + -0x148 +
                    ((*(int *)&(this->MorphObjectList).field_0x4 - *(int *)this_00) / 0x148) * 0x148
                    );
    piVar2 = piVar7;
    memset(piVar7,0,0x148);
    pcVar3 = GetConfigODF((int)piVar2);
    bVar1 = DoesFileExist(pcVar3);
    if (bVar1) {
      DispatchHelper::ReadChanceValues(this_01,pcVar3,"CloakChance",(float *)(piVar7 + 0x13),0.0);
    }
    GetODFBool("CraftClass","CanAICloak",(char *)((int)piVar7 + 0xb),(char *)0x0,unaff_EDI,
               SUB41(unaff_ESI,0));
    if (*(char *)((int)piVar7 + 0xb) != '\0') {
      pcVar12 = "MaxCloakEnergy";
      pcVar11 = "GameObjectClass";
      GetODFLong("GameObjectClass","MaxCloakEnergy",(char *)(piVar7 + 0x4d),(char *)0x0,
                 (long *)unaff_EDI,unaff_ESI);
      piVar7[0x4e] = piVar7[0x4d];
      pcVar10 = "CloakEnergyCost";
      pcVar3 = "GameObjectClass";
      GetODFLong("GameObjectClass","CloakEnergyCost",(char *)(piVar7 + 0x4f),(char *)0x0,
                 (long *)pcVar11,(long)pcVar12);
      GetODFLong("GameObjectClass","AddCloakEnergy",(char *)(piVar7 + 0x50),(char *)0x0,
                 (long *)pcVar3,(long)pcVar10);
    }
    fVar9 = GetEngageRange((int)unaff_EDI);
    pcVar3 = local_44;
    pcVar10 = (char *)0x0;
    piVar7[0x12] = (int)fVar9;
    memset(pcVar3,0,0x40);
    GetODFString("MorphObjectClass","SwitchODF",(char *)0x40,local_44,0,pcVar3,pcVar10);
    if ((local_44[0] != '\0') && (bVar1 = DoesODFExist(local_44), bVar1)) {
      PreloadODF(local_44);
    }
    *piVar7 = param_1;
    lVar4 = GetMaxAmmo(param_1);
    fVar9 = ___real_41f00000;
    piVar7[5] = lVar4;
    iVar5 = SecondsToTurns(fVar9);
    piVar7[3] = iVar5 + BZ1Helper::m_TurnCounter;
    pfVar8 = (float *)(piVar7 + 0xd);
    do {
      fVar9 = GetMaxLocalAmmo(param_1,iVar6);
      *pfVar8 = fVar9;
      iVar6 = iVar6 + 1;
      pfVar8 = pfVar8 + 1;
    } while (iVar6 < 5);
  }
  return;
}


// ---------------------------------------------------------------------
// MorphObjectHelper::AddMorphObjectToggleObject  @ 4fc167a0  lines 137-177


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall MorphObjectHelper::AddMorphObjectToggleObject(MorphObjectHelper *this,int param_1)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  int unaff_ESI;
  int *piVar4;
  int unaff_EDI;
  float fVar5;
  char *pcVar6;
  char *pcVar7;
  float local_50;
  char local_48 [64];
  undefined4 local_8;
  
  local_8 = __security_cookie ^ (uint)(local_48 + 0x44);
  local_50 = 3.4028235e+38;
  piVar4 = *(int **)&this->MorphObjectList;
  if (piVar4 != *(int **)&(this->MorphObjectList).field_0x4) {
    do {
      fVar5 = GetDistance3DSquared(unaff_EDI,unaff_ESI);
      if (((fVar5 < local_50) && (param_1 != *piVar4)) &&
         (local_50 = fVar5, fVar5 < (float)___real_4039000000000000)) {
        if ((char)piVar4[2] == '\0') {
          if ((*(char *)((int)piVar4 + 0xb) == '\0') || ((char)piVar4[0x4c] == '\0')) {
            *(undefined2 *)(piVar4 + 2) = 0x101;
          }
          else {
            iVar1 = *piVar4;
            iVar3 = GetPlayerHandle();
            if (iVar1 == iVar3) {
              pcVar6 = local_48;
              pcVar7 = (char *)0x0;
              memset(pcVar6,0,0x40);
              GetODFString(0x4fc5c7e8,(char *)0x40,local_48,0,pcVar6,pcVar7);
              bVar2 = DoesFileExist(local_48);
              if (bVar2) {
                StartAudio2D(local_48,__real_bf800000,0.0,___real_462c4400,false,false);
              }
            }
          }
        }
        else {
          *(undefined2 *)(piVar4 + 2) = 0x100;
        }
        break;
      }
      piVar4 = piVar4 + 0x52;
    } while (piVar4 != *(int **)&(this->MorphObjectList).field_0x4);
  }
  BZ1Helper::DeleteAfterDelay(BZ1Helper::m_BZ1Helper,param_1,0.0);
  return;
}


// ---------------------------------------------------------------------
// MorphObjectHelper::Execute  @ 4fc168ca  lines 180-514


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall MorphObjectHelper::Execute(MorphObjectHelper *this,BZ1Helper *param_1)

{
  Vector VVar1;
  BZ1Helper *this_00;
  code *pcVar2;
  bool bVar3;
  char cVar4;
  undefined4 uVar5;
  float fVar6;
  int iVar7;
  float *pfVar8;
  int iVar9;
  MorphObjectHelper *this_01;
  AlignTerrainReplaceClass *pAVar10;
  AlignTerrainReplaceClass *pAVar11;
  code *pcVar12;
  char *unaff_ESI;
  AlignTerrainReplaceClass *pAVar13;
  float *pfVar14;
  float *unaff_EDI;
  size_t sVar15;
  float *pfVar16;
  float fVar17;
  char *pcVar18;
  float fVar19;
  undefined1 uVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  double dStack_3e0;
  float *local_3d8;
  char cStack_3d1;
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
  undefined1 auStack_288 [64];
  char acStack_248 [64];
  char acStack_208 [64];
  char acStack_1c8 [64];
  char acStack_188 [64];
  char acStack_148 [324];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)&dStack_3e0;
  local_384 = param_1;
  pAVar13 = *(AlignTerrainReplaceClass **)&(this->MorphObjectList).field_0x4;
  pAVar10 = *(AlignTerrainReplaceClass **)&this->MorphObjectList;
  local_3b4 = pAVar13;
  local_3a0 = this;
  local_328 = pAVar13;
  local_324 = pAVar10;
  while ((pAVar10 != pAVar13 &&
         (bVar3 = BZ1Helper::ShouldRemoveAlignTerrainReplace(pAVar10), !bVar3))) {
    pAVar10 = (AlignTerrainReplaceClass *)&pAVar10[0x14].NormalVec.y;
  }
  pAVar11 = pAVar10;
  if (pAVar10 != pAVar13) {
    while( true ) {
      this = local_3a0;
      pAVar11 = (AlignTerrainReplaceClass *)&pAVar11[0x14].NormalVec.y;
      if (pAVar11 == pAVar13) break;
      bVar3 = BZ1Helper::ShouldRemoveAlignTerrainReplace(pAVar11);
      if (!bVar3) {
        pfVar14 = (float *)pAVar11;
        pAVar13 = pAVar10;
        for (iVar9 = 0x52; iVar9 != 0; iVar9 = iVar9 + -1) {
          pAVar13->AlignHandle = (int)*pfVar14;
          pfVar14 = pfVar14 + 1;
          pAVar13 = (AlignTerrainReplaceClass *)&pAVar13->NormalVec;
        }
        pAVar10 = (AlignTerrainReplaceClass *)&pAVar10[0x14].NormalVec.y;
        pAVar13 = local_3b4;
      }
    }
    if (pAVar10 != pAVar13) {
      sVar15 = *(int *)&(local_3a0->MorphObjectList).field_0x4 - (int)pAVar13;
      memmove(pAVar10,pAVar13,sVar15);
      local_34c = (float *)(sVar15 + (int)pAVar10);
      *(float **)&(this->MorphObjectList).field_0x4 = local_34c;
      goto LAB_4fc16977;
    }
  }
  local_34c = *(float **)&(this->MorphObjectList).field_0x4;
LAB_4fc16977:
  local_3cc = *(float **)&this->MorphObjectList;
  if (local_3cc != local_34c) {
    local_394 = GetCurAmmo_exref;
    local_398 = GetObjInfo_exref;
    local_38c = _stricmp_exref;
    local_388 = DoesODFExist_exref;
    local_3b8 = GetCurrentCommand_exref;
    local_3bc = 0.0;
    local_3b4 = (AlignTerrainReplaceClass *)DoesFileExist_exref;
    local_380 = StartAudio3D_exref;
    local_370 = ___real_41700000;
    local_3b0 = SetPerceivedTeam_exref;
    local_3a8 = GetPlayerHandle_exref;
    local_36c = 1.0;
    local_37c = SetCurLocalAmmo_exref;
    local_378 = IsPlayer_exref;
    local_320 = ___real_4049000000000000;
    local_374 = GetPlayerHandle_exref;
    local_3c4 = SetCommand_exref;
    local_368 = ___real_41f00000;
    local_390 = SecondsToTurns_exref;
    local_35c = StartAudio2D_exref;
    local_364 = ___real_462c4400;
    local_358 = BuildObject_exref;
    local_354 = GetCurrentWho_exref;
    local_360 = __real_bf800000;
    local_348 = GetTeamNum_exref;
    local_344 = GetPerceivedTeam_exref;
    local_39c = SetCurAmmo_exref;
    local_350 = GetCurrentCommandWhere_exref;
    do {
      pcVar2 = local_344;
      pcVar12 = local_39c;
      pfVar14 = local_3cc;
      local_3d8 = local_3cc;
      local_3d0 = local_3cc;
      local_3ac = local_3cc;
      uVar5 = (*local_348)(*local_3cc);
      local_3a4 = uVar5;
      fVar6 = (float)(*pcVar2)(*pfVar14);
      if (0 < (int)fVar6) {
        pfVar14[7] = fVar6;
      }
      iVar9 = (*misnImport.GetNearestEnemy)((int)*pfVar14);
      dStack_3e0 = (double)CONCAT44(dStack_3e0._4_4_,iVar9);
      if (*(char *)((int)pfVar14 + 9) == '\0') {
        if (*(char *)(pfVar14 + 2) != '\0') {
          fVar6 = (float)(*local_394)(*pfVar14);
          if (*(char *)((int)pfVar14 + 10) == '\0') {
            if (0 < (int)fVar6) {
              fVar21 = pfVar14[5];
              if ((int)pfVar14[4] + (int)fVar6 <= (int)pfVar14[5]) {
                fVar21 = (float)((int)pfVar14[4] + (int)fVar6);
              }
              pfVar14[4] = fVar21;
              (*pcVar12)(*pfVar14,0);
            }
            fVar6 = (float)(*local_3a8)();
            pfVar8 = local_3d8;
            if (*pfVar14 == fVar6) {
              pfStack_3c8 = (float *)pfVar14[5];
              if (0 < (int)pfStack_3c8) {
                pfStack_3c8 = (float *)(float)(int)pfStack_3c8;
                BZ1Helper::AmmoGauge2 = (float)(int)pfVar14[4] / (float)pfStack_3c8;
                BZ1Helper::AmmoGaugeSet = true;
                local_3d0 = local_3cc;
                pfVar14 = local_3cc;
              }
            }
            iVar7 = 0;
            iVar9 = 0x20;
            do {
              fVar6 = GetMaxLocalAmmo((int)*pfVar14,iVar7);
              *(float *)(iVar9 + 0x14 + (int)pfVar8) = fVar6;
              pfStack_3c8 = (float *)GetCurLocalAmmo((int)*pfVar14,iVar7);
              pfVar16 = (float *)(*(float *)(iVar9 + (int)pfVar14) + (float)pfStack_3c8);
              local_3d8 = *(float **)(iVar9 + 0x14 + (int)pfVar8);
              if ((float)pfVar16 < (float)local_3d8) {
                pfStack_3c8 = pfVar16;
              }
              else {
                pfVar16 = local_3d8;
              }
              *(float **)(iVar9 + (int)local_3ac) = pfVar16;
              (*local_37c)(*pfVar14,local_3bc,iVar7);
              iVar9 = iVar9 + 4;
              iVar7 = iVar7 + 1;
            } while (iVar9 < 0x34);
            iVar9 = dStack_3e0._0_4_;
          }
          else {
            if (pfVar14[4] != fVar6) {
              pfVar14[4] = fVar6;
            }
            iVar7 = 0;
            pfVar8 = pfVar14 + 8;
            do {
              local_3d8 = (float *)GetCurLocalAmmo((int)*pfVar14,iVar7);
              if (*pfVar8 != (float)local_3d8) {
                *pfVar8 = (float)local_3d8;
              }
              iVar7 = iVar7 + 1;
              pfVar8 = pfVar8 + 1;
            } while (iVar7 < 5);
          }
          if (*(char *)((int)pfVar14 + 0xb) != '\0') {
            (*local_3b0)(*pfVar14,0);
          }
          uVar5 = local_3a4;
        }
        if (*(char *)((int)pfVar14 + 0xb) != '\0') {
          cVar4 = (*local_378)(*pfVar14);
          if ((cVar4 == '\0') && (iVar7 = (*local_374)(uVar5), iVar7 == 0)) {
            if (*(char *)(pfVar14 + 2) == '\0') {
              if ((int)pfVar14[3] <= BZ1Helper::m_TurnCounter) {
                iVar7 = (*local_3b8)(*pfVar14);
                pfStack_3c8 = (float *)GetRandomFloat(local_36c);
                if (iVar9 != 0) {
                  dStack_3e0 = (double)(pfVar14[0x12] + (float)local_320);
                  fVar21 = GetDistance3DSquared((int)unaff_EDI,(int)unaff_ESI);
                  fVar6 = (float)((float10)dStack_3e0 * (float10)dStack_3e0);
                  dStack_3e0 = (double)CONCAT44(dStack_3e0._4_4_,fVar6);
                  if (fVar21 <= fVar6) goto LAB_4fc171e9;
                }
                pcVar12 = local_3c4;
                if ((float)pfStack_3c8 < pfVar14[iVar7 + 0x13]) {
                  (*local_3c4)(*pfVar14,0x15,0,0,0,0);
                }
                uVar5 = local_368;
                goto LAB_4fc17141;
              }
              goto LAB_4fc171e9;
            }
            dStack_3e0 = (double)pfVar14[0x12];
            fVar21 = GetDistance3DSquared((int)unaff_EDI,(int)unaff_ESI);
            pcVar12 = local_3c4;
            fVar6 = (float)((float10)dStack_3e0 * (float10)dStack_3e0);
            dStack_3e0 = (double)CONCAT44(dStack_3e0._4_4_,fVar6);
            if (fVar21 < fVar6) {
              (*local_3c4)(*pfVar14,0x15,0,0,0,0);
              uVar5 = local_370;
LAB_4fc17141:
              iVar9 = (*local_390)(uVar5);
              pfVar14[3] = (float)(iVar9 + BZ1Helper::m_TurnCounter);
            }
          }
          else {
LAB_4fc171e9:
            pcVar12 = local_3c4;
          }
          pfVar8 = pfVar14 + 0x4d;
          if (0 < (int)*pfVar8) {
            fVar6 = local_3ac[0x4e];
            if (*(char *)(pfVar14 + 2) == '\0') {
              if ((int)fVar6 < (int)*pfVar8) {
                local_3d8 = (float *)((float)(int)pfVar14[0x50] / (float)BZ1Helper::m_GameTPS +
                                     pfVar14[0x51]);
                fVar6 = (float)(int)(float)local_3d8;
                dStack_3e0 = (double)CONCAT44(dStack_3e0._4_4_,fVar6);
                pfVar14[0x51] = (float)local_3d8 - fVar6;
                local_3d0 = local_3cc;
                pfVar14 = local_3cc + 0x4e;
                *pfVar14 = (float)((int)*pfVar14 + (int)(float)local_3d8);
                if ((int)*pfVar14 < 0) {
                  fVar6 = 0.0;
                }
                else {
                  fVar6 = local_3cc[0x4e];
                  if ((int)*pfVar8 < (int)local_3cc[0x4e]) {
                    fVar6 = *pfVar8;
                  }
                }
                local_3cc[0x4e] = fVar6;
                pfVar14 = local_3cc;
              }
              if (*(char *)(pfVar14 + 0x4c) == '\0') {
                if ((int)*pfVar8 <= (int)fVar6) goto LAB_4fc173cb;
                *(undefined1 *)(pfVar14 + 0x4c) = 1;
              }
              else if ((int)*pfVar8 <= (int)fVar6) {
LAB_4fc173cb:
                *(undefined1 *)(pfVar14 + 0x4c) = 0;
              }
            }
            else {
              if (0 < (int)fVar6) {
                local_3d8 = (float *)((float)(int)pfVar14[0x4f] / (float)BZ1Helper::m_GameTPS +
                                     pfVar14[0x51]);
                fVar6 = (float)(int)(float)local_3d8;
                dStack_3e0 = (double)CONCAT44(dStack_3e0._4_4_,fVar6);
                pfVar14[0x51] = (float)local_3d8 - fVar6;
                local_3d0 = local_3cc;
                pfVar14 = local_3cc + 0x4e;
                *pfVar14 = (float)((int)*pfVar14 - (int)(float)local_3d8);
                if ((int)*pfVar14 < 0) {
                  fVar6 = 0.0;
                }
                else {
                  fVar6 = local_3cc[0x4e];
                  if ((int)*pfVar8 < (int)local_3cc[0x4e]) {
                    fVar6 = *pfVar8;
                  }
                }
                local_3cc[0x4e] = fVar6;
                pfVar14 = local_3cc;
              }
              if ((*(char *)(pfVar14 + 0x4c) != '\0') || (fVar6 == 0.0)) {
                (*pcVar12)(*pfVar14,0x15,0,0,0,0);
                fVar6 = *pfVar14;
                fVar21 = (float)(*local_3a8)();
                if (fVar6 == fVar21) {
                  memset(acStack_208,0,0x40);
                  GetODFString(0x4fc5c7e8,(char *)0x40,acStack_208,0,(char *)unaff_EDI,unaff_ESI);
                  cVar4 = (*(code *)local_3b4)(acStack_208);
                  if (cVar4 != '\0') {
                    (*local_35c)(acStack_208,local_360,local_3bc,local_364,0,0);
                  }
                }
              }
            }
            fVar6 = (float)(*local_3a8)();
            if (*pfVar14 == fVar6) {
              dStack_3e0 = (double)CONCAT44(dStack_3e0._4_4_,(float)(int)*pfVar8);
              BZ1Helper::CloakGauge = (float)(int)pfVar14[0x4e] / (float)(int)*pfVar8;
              BZ1Helper::CloakGaugeSet = true;
              local_3d0 = local_3cc;
              pfVar14 = local_3cc;
            }
          }
        }
        iVar9 = (*local_3b8)(*pfVar14);
        if (iVar9 == 0x15) {
          memset(acStack_188,0,0x40);
          GetSwitchMineODF(this_01,(int)*pfVar14,acStack_188);
          (*local_358)(acStack_188,local_3a4,*pfVar14);
        }
      }
      else {
        iVar9 = 0;
        memset(acStack_308,0,0x40);
        cStack_3d1 = '\0';
        uVar20 = 0x40;
        pcVar18 = "SwitchODF";
        GetODFString(0x4fc5d870,(char *)0x40,acStack_308,0,(char *)unaff_EDI,unaff_ESI);
        GetODFBool(0x4fc5d890,(char *)((int)pfVar14 + 10),(char *)0x1,(bool *)pcVar18,(bool)uVar20);
        GetODFBool(0x4fc5d8a4,&cStack_3d1,(char *)0x1,(bool *)unaff_EDI,SUB41(unaff_ESI,0));
        if (*(char *)(pfVar14 + 2) != '\0') {
          GetODFBool(0x4fc5d890,(char *)((int)pfVar14 + 10),(char *)0x1,(bool *)unaff_EDI,
                     SUB41(unaff_ESI,0));
          fVar6 = (float)(*local_394)(*pfVar14);
          pfVar14[4] = fVar6;
        }
        memset(acStack_148,0,0x140);
        local_3cc = pfVar14 + 0xd;
        pcVar18 = acStack_148;
        do {
          (*local_398)(*pfVar14,iVar9 + 5,pcVar18);
          uStack_3c0 = uStack_3c0 & 0xffffff00;
          memset(auStack_288,0,0x40);
          (*local_398)(*pfVar14,iVar9 + 10,auStack_288);
          if (*(char *)(pfVar14 + 2) == '\0') {
            pfVar8 = local_3cc;
          }
          else {
            fVar6 = GetCurLocalAmmo((int)*pfVar14,iVar9);
            pfVar8 = local_3cc;
            local_3cc[-5] = fVar6;
            fVar6 = GetMaxLocalAmmo((int)*pfVar14,iVar9);
            *pfVar8 = fVar6;
          }
          bVar3 = OpenODF2((char *)unaff_EDI);
          if (bVar3) {
            memset(acStack_2c8,0,0x40);
            iVar7 = GetODFString("DispenserClass","objectClass",(char *)0x40,acStack_2c8,0,
                                 (char *)unaff_EDI,unaff_ESI);
            if (iVar7 == 0) goto LAB_4fc16ce6;
            memset(acStack_1c8,0,0x40);
            CombineStrings(".odf",(char *)0x40,(char *)unaff_EDI,(uint)unaff_ESI);
            bVar3 = OpenODF2((char *)unaff_EDI);
            if ((!bVar3) ||
               (iVar7 = GetODFString("GameObjectClass","BZCClasslabel",(char *)0x40,acStack_1c8,0,
                                     (char *)unaff_EDI,unaff_ESI), iVar7 == 0)) goto LAB_4fc16ce6;
            iVar7 = (*local_38c)(acStack_1c8,"MorphObjecttoggle");
            cVar4 = (char)uStack_3c0;
            if (iVar7 == 0) {
              cVar4 = '\x01';
            }
          }
          else {
LAB_4fc16ce6:
            cVar4 = (char)uStack_3c0;
          }
          if (cStack_3d1 == '\0') {
            if ((cVar4 != '\0') &&
               (iVar7 = GetODFString("WeaponClass","altName",(char *)0x40,pcVar18,0,
                                     (char *)unaff_EDI,unaff_ESI), iVar7 != 0)) break;
          }
          else {
            GetODFString("WeaponClass","altName",(char *)0x40,pcVar18,0,(char *)unaff_EDI,unaff_ESI)
            ;
          }
          iVar9 = iVar9 + 1;
          local_3cc = pfVar8 + 1;
          pcVar18 = pcVar18 + 0x40;
        } while (iVar9 < 5);
        if (acStack_308[0] != '\0') {
          cVar4 = (*local_388)(acStack_308);
          this_00 = local_384;
          pcVar12 = local_3b8;
          if (cVar4 == '\0') {
            FormatLogMessage("ERROR: SwitchODF \'%s\' does not exist. Fix ODFs!");
          }
          else {
            local_384[1].teamInfo[0].PilotWeapon[4][0x22] = '\x01';
            iVar9 = (*local_3b8)(*pfVar14);
            fVar6 = *pfVar14;
            if (iVar9 == 0x15) {
              fVar17 = pfVar14[6];
              fVar6 = (float)(*pcVar12)(fVar6);
              if ((fVar17 == fVar6) || (fVar17 == 2.94273e-44)) {
                uStack_340 = 0;
                uStack_33c = 0;
                uStack_338 = 0;
                fVar21 = 0.0;
                fVar22 = 0.0;
                fVar23 = 0.0;
                fVar19 = -NAN;
                fVar17 = -NAN;
                bVar3 = false;
              }
              else {
                fVar19 = local_3d0[1];
                bVar3 = true;
                fVar21 = pfVar14[0x49];
                fVar22 = pfVar14[0x4a];
                fVar23 = pfVar14[0x4b];
              }
              fVar6 = *local_3d0;
            }
            else {
              uStack_334 = 0;
              uStack_330 = 0;
              uStack_32c = 0;
              fVar21 = 0.0;
              fVar22 = 0.0;
              fVar23 = 0.0;
              fVar19 = -NAN;
              fVar17 = -NAN;
              bVar3 = true;
            }
            VVar1.y = fVar22;
            VVar1.x = fVar21;
            VVar1.z = fVar23;
            fVar6 = (float)BZ1Helper::ReplaceObject
                                     (this_00,(int)fVar6,acStack_308,-1,local_3bc,-1,false,-1,-1,
                                      bVar3,(int)fVar17,0,(int)fVar19,VVar1);
            *local_3d8 = fVar6;
            this_00[1].teamInfo[0].PilotWeapon[4][0x22] = '\0';
            memset(acStack_248,0,0x40);
            pfVar14 = local_3d0;
            pcVar18 = "soundUndeploy";
            if (*(char *)(local_3d0 + 2) != '\0') {
              pcVar18 = "soundDeploy";
            }
            GetODFString((int)pcVar18,(char *)0x40,acStack_248,0,(char *)unaff_EDI,unaff_ESI);
            cVar4 = (*(code *)local_3b4)(acStack_248);
            if (cVar4 == '\0') {
              if (acStack_248[0] != '\0') {
                FormatLogMessage("ERROR: Morph Object SoundDeploy \'%s\' Doesn\'t Exist! FIX ODFs!")
                ;
              }
            }
            else {
              (*local_380)(acStack_248,*pfVar14,7,0,1);
            }
            if (*(char *)((int)pfVar14 + 0xb) != '\0') {
              if (*(char *)(pfVar14 + 2) == '\0') {
                fVar6 = pfVar14[7];
              }
              else {
                fVar6 = 0.0;
              }
              (*local_3b0)(*pfVar14,fVar6);
            }
            if (*(char *)((int)pfVar14 + 10) == '\0') {
              if (*(char *)(pfVar14 + 2) == '\0') {
                fVar6 = pfVar14[4];
              }
              else {
                fVar6 = 0.0;
              }
              (*local_39c)(*pfVar14,fVar6);
            }
            *(undefined1 *)((int)pfVar14 + 9) = 0;
            ReplaceWeapons((int)(pfVar14 + 8),(char (*) [64])0x0,unaff_EDI,unaff_ESI);
          }
        }
      }
      iVar9 = (*local_3b8)(*pfVar14);
      if (iVar9 != 0x15) {
        fVar6 = (float)(*local_3b8)(*pfVar14);
        pfVar14[6] = fVar6;
        fVar6 = (float)(*local_354)(*pfVar14);
        pfVar14[1] = fVar6;
        fVar6 = pfVar14[6];
        if (((fVar6 == 4.2039e-45) || (fVar6 == 1.4013e-44)) || ((int)fVar6 - 0x1aU < 2)) {
          pfVar8 = (float *)(*local_350)(auStack_314,*pfVar14);
          pfVar14[0x49] = *pfVar8;
          pfVar14[0x4a] = pfVar8[1];
          pfVar14[0x4b] = pfVar8[2];
          pfVar14 = local_3d0;
        }
      }
      local_3cc = pfVar14 + 0x52;
      local_34c = *(float **)&(local_3a0->MorphObjectList).field_0x4;
    } while (local_3cc != local_34c);
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
  char *unaff_ESI;
  int iVar3;
  char *unaff_EDI;
  char *pcVar4;
  char *pcVar5;
  uint uVar6;
  char local_c4 [64];
  char local_84 [64];
  char local_44 [64];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)local_c4;
  iVar3 = 0;
  do {
    memset(local_c4,0,0x40);
    GetObjInfo(param_1,iVar3 + Get_Weapon0ODF,local_c4);
    bVar1 = OpenODF2(unaff_EDI);
    if (bVar1) {
      pcVar4 = local_84;
      pcVar5 = (char *)0x0;
      memset(pcVar4,0,0x40);
      iVar2 = GetODFString("DispenserClass","objectClass",(char *)0x40,MineObject,0,pcVar4,pcVar5);
      if (iVar2 != 0) {
        pcVar4 = local_44;
        uVar6 = 0;
        memset(pcVar4,0,0x40);
        CombineStrings(".odf",(char *)0x40,pcVar4,uVar6);
        bVar1 = OpenODF2(unaff_EDI);
        if (bVar1) {
          iVar2 = GetODFString("GameObjectClass","BZCClasslabel",(char *)0x40,local_44,0,unaff_EDI,
                               unaff_ESI);
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
          (MorphObjectHelper *this,int param_1,int param_2,int param_3,int param_4,char *param_5)

{
  int *piVar1;
  
  if ((param_1 == 0) &&
     (piVar1 = *(int **)&this->MorphObjectList,
     piVar1 != *(int **)&(this->MorphObjectList).field_0x4)) {
    do {
      if (*piVar1 == param_2) {
        if ((char)piVar1[2] == '\0') {
          return PREPICKUPPOWERUP_ALLOW;
        }
        if (*(char *)((int)piVar1 + 10) != '\0') {
          return PREPICKUPPOWERUP_ALLOW;
        }
        if (piVar1[4] != piVar1[5]) {
          return PREPICKUPPOWERUP_ALLOW;
        }
        if (param_4 == -0x599d55a0) {
          return PREPICKUPPOWERUP_DENY;
        }
        if (param_4 == 0x33fe0a68) {
          GetHealth(param_2);
          return PREPICKUPPOWERUP_ALLOW;
        }
        return PREPICKUPPOWERUP_ALLOW;
      }
      piVar1 = piVar1 + 0x52;
    } while (piVar1 != *(int **)&(this->MorphObjectList).field_0x4);
  }
  return PREPICKUPPOWERUP_ALLOW;
}

