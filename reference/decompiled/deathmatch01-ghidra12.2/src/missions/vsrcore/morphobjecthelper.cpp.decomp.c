// Reconstructed by Ghidra from deathmatch01.dll + deathmatch01.pdb
// Original source file: /e:/github/vsr_dll_source/missions/vsrcore/morphobjecthelper.cpp
// Functions are ordered by original source line. This is decompiler
// output, not the author's source: names/types come from the PDB,
// local variable names and control flow are reconstructed.


// ---------------------------------------------------------------------
// `dynamic_initializer_for_'TempMorphObjectBuffer''  @ 4fc014ff  lines 8-8


void __cdecl _dynamic_initializer_for__TempMorphObjectBuffer__(void)

{
  atexit(_dynamic_atexit_destructor_for__TempMorphObjectBuffer__);
  return;
}


// ---------------------------------------------------------------------
// MorphObjectHelper::~MorphObjectHelper  @ 4fc15bc3  lines 18-20


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
// MorphObjectHelper::PostLoad  @ 4fc15bd8  lines 43-67


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
// MorphObjectHelper::AddMorphObjectHostObject  @ 4fc15c8d  lines 86-133


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
// MorphObjectHelper::AddMorphObjectToggleObject  @ 4fc15e7d  lines 137-177


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
              GetODFString(0x4fc59398,(char *)0x40,local_48,0,pcVar6,pcVar7);
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
// MorphObjectHelper::Execute  @ 4fc15fa7  lines 180-514


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall MorphObjectHelper::Execute(MorphObjectHelper *this,BZ1Helper *param_1)

{
  AlignTerrainReplaceClass *pAVar1;
  undefined4 uVar2;
  Vector VVar3;
  code *pcVar4;
  bool bVar5;
  bool bVar6;
  char cVar7;
  int *piVar8;
  char *pcVar9;
  int iVar10;
  int *piVar11;
  int iVar12;
  MorphObjectHelper *this_00;
  AlignTerrainReplaceClass *pAVar13;
  AlignTerrainReplaceClass *pAVar14;
  BZ1Helper *this_01;
  float *pfVar15;
  code *pcVar16;
  char *unaff_ESI;
  AlignTerrainReplaceClass *pAVar17;
  size_t sVar18;
  float *unaff_EDI;
  float *pfVar19;
  float fVar20;
  float fVar21;
  int iVar22;
  int iVar23;
  undefined1 uVar24;
  int iVar25;
  double dStack_3c8;
  float *pfStack_3c0;
  char cStack_3b9;
  float *pfStack_3b8;
  code *local_3b4;
  char *local_3b0;
  code *local_3ac;
  AlignTerrainReplaceClass *local_3a8;
  float local_3a4;
  int *local_3a0;
  code *local_39c;
  BZ1Helper *local_398;
  code *local_394;
  code *local_390;
  code *local_38c;
  code *local_388;
  code *local_384;
  MorphObjectHelper *local_380;
  code *local_37c;
  code *local_378;
  code *local_374;
  code *local_370;
  code *local_36c;
  code *local_368;
  undefined4 local_364;
  float local_360;
  undefined4 local_35c;
  undefined4 local_358;
  undefined4 local_354;
  code *local_350;
  code *local_34c;
  code *local_348;
  code *local_344;
  code *local_340;
  code *local_33c;
  undefined4 uStack_338;
  undefined4 uStack_334;
  undefined4 uStack_330;
  undefined4 uStack_32c;
  undefined4 uStack_328;
  undefined4 uStack_324;
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
  
  local_4 = __security_cookie ^ (uint)&dStack_3c8;
  local_398 = param_1;
  pAVar1 = *(AlignTerrainReplaceClass **)&(this->MorphObjectList).field_0x4;
  pAVar14 = *(AlignTerrainReplaceClass **)&this->MorphObjectList;
  local_380 = this;
  while ((pAVar14 != pAVar1 && (bVar5 = BZ1Helper::ShouldRemoveAlignTerrainReplace(pAVar14), !bVar5)
         )) {
    pAVar14 = (AlignTerrainReplaceClass *)&pAVar14[0x14].NormalVec.y;
  }
  if (pAVar14 != pAVar1) {
    local_3a8 = (AlignTerrainReplaceClass *)&pAVar14[0x14].NormalVec.y;
    pAVar13 = pAVar14;
    if (local_3a8 != pAVar1) {
      do {
        pAVar17 = local_3a8;
        bVar5 = BZ1Helper::ShouldRemoveAlignTerrainReplace(local_3a8);
        pAVar14 = pAVar13;
        if (!bVar5) {
          pAVar14 = (AlignTerrainReplaceClass *)&pAVar13[0x14].NormalVec.y;
          for (iVar12 = 0x52; iVar12 != 0; iVar12 = iVar12 + -1) {
            pAVar13->AlignHandle = pAVar17->AlignHandle;
            pAVar17 = (AlignTerrainReplaceClass *)&pAVar17->NormalVec;
            pAVar13 = (AlignTerrainReplaceClass *)&pAVar13->NormalVec;
          }
          pAVar17 = local_3a8;
        }
        local_3a8 = (AlignTerrainReplaceClass *)&pAVar17[0x14].NormalVec.y;
        pAVar13 = pAVar14;
      } while (local_3a8 != pAVar1);
      this = local_380;
    }
    if (pAVar14 != pAVar1) {
      sVar18 = *(int *)&(this->MorphObjectList).field_0x4 - (int)pAVar1;
      memmove(pAVar14,pAVar1,sVar18);
      piVar8 = (int *)(sVar18 + (int)pAVar14);
      *(int **)&(this->MorphObjectList).field_0x4 = piVar8;
      goto LAB_4fc1604c;
    }
  }
  piVar8 = *(int **)&(this->MorphObjectList).field_0x4;
LAB_4fc1604c:
  local_3a0 = *(int **)&this->MorphObjectList;
  if (local_3a0 != piVar8) {
    local_38c = GetCurAmmo_exref;
    local_390 = GetObjInfo_exref;
    local_37c = _stricmp_exref;
    local_378 = DoesODFExist_exref;
    local_39c = GetCurrentCommand_exref;
    local_3a4 = 0.0;
    local_384 = DoesFileExist_exref;
    local_374 = StartAudio3D_exref;
    local_364 = ___real_41700000;
    local_3a8 = (AlignTerrainReplaceClass *)SetPerceivedTeam_exref;
    local_394 = SetCurAmmo_exref;
    local_360 = 1.0;
    local_370 = SetCurLocalAmmo_exref;
    local_36c = IsPlayer_exref;
    local_320 = ___real_4049000000000000;
    local_368 = GetPlayerHandle_exref;
    local_3b4 = SetCommand_exref;
    local_35c = ___real_41f00000;
    local_388 = SecondsToTurns_exref;
    local_350 = StartAudio2D_exref;
    local_358 = ___real_462c4400;
    local_34c = BuildObject_exref;
    local_348 = GetCurrentWho_exref;
    local_354 = __real_bf800000;
    local_340 = GetTeamNum_exref;
    local_33c = GetPerceivedTeam_exref;
    local_3ac = GetPlayerHandle_exref;
    local_344 = GetCurrentCommandWhere_exref;
    do {
      pcVar4 = local_33c;
      piVar8 = local_3a0;
      pcVar16 = local_3ac;
      pcVar9 = (char *)(*local_340)(*local_3a0);
      local_3b0 = pcVar9;
      iVar12 = (*pcVar4)(*piVar8);
      if (0 < iVar12) {
        piVar8[7] = iVar12;
      }
      iVar12 = (*misnImport.GetNearestEnemy)(*piVar8);
      dStack_3c8 = (double)CONCAT44(dStack_3c8._4_4_,iVar12);
      if (*(char *)((int)piVar8 + 9) == '\0') {
        if ((char)piVar8[2] != '\0') {
          iVar10 = (*local_38c)(*piVar8);
          if (*(char *)((int)piVar8 + 10) == '\0') {
            if (0 < iVar10) {
              iVar12 = piVar8[5];
              if (piVar8[4] + iVar10 <= piVar8[5]) {
                iVar12 = piVar8[4] + iVar10;
              }
              piVar8[4] = iVar12;
              (*local_394)(*piVar8,0);
            }
            iVar12 = (*pcVar16)();
            pcVar16 = local_370;
            if ((*piVar8 == iVar12) && (pfStack_3b8 = (float *)piVar8[5], 0 < (int)pfStack_3b8)) {
              pfStack_3c0 = (float *)(float)piVar8[4];
              pfStack_3b8 = (float *)(float)(int)pfStack_3b8;
              BZ1Helper::AmmoGauge2 = (float)pfStack_3c0 / (float)pfStack_3b8;
              BZ1Helper::AmmoGaugeSet = true;
            }
            pfVar15 = (float *)(piVar8 + 8);
            iVar12 = 0;
            do {
              fVar20 = GetMaxLocalAmmo(*piVar8,iVar12);
              pfVar15[5] = fVar20;
              pfStack_3b8 = (float *)GetCurLocalAmmo(*piVar8,iVar12);
              pfVar19 = (float *)(*pfVar15 + (float)pfStack_3b8);
              pfStack_3c0 = (float *)pfVar15[5];
              if ((float)pfVar19 < (float)pfStack_3c0) {
                pfStack_3b8 = pfVar19;
              }
              else {
                pfVar19 = pfStack_3c0;
              }
              *pfVar15 = (float)pfVar19;
              (*pcVar16)(*piVar8,local_3a4,iVar12);
              pfVar15 = pfVar15 + 1;
              iVar12 = iVar12 + 1;
            } while (iVar12 < 5);
            iVar12 = dStack_3c8._0_4_;
          }
          else {
            if (piVar8[4] != iVar10) {
              piVar8[4] = iVar10;
            }
            iVar10 = 0;
            pfVar15 = (float *)(piVar8 + 8);
            do {
              pfStack_3c0 = (float *)GetCurLocalAmmo(*piVar8,iVar10);
              if (*pfVar15 != (float)pfStack_3c0) {
                *pfVar15 = (float)pfStack_3c0;
              }
              iVar10 = iVar10 + 1;
              pfVar15 = pfVar15 + 1;
            } while (iVar10 < 5);
          }
          if (*(char *)((int)piVar8 + 0xb) != '\0') {
            (*(code *)local_3a8)(*piVar8,0);
          }
          pcVar9 = local_3b0;
        }
        if (*(char *)((int)piVar8 + 0xb) != '\0') {
          cVar7 = (*local_36c)(*piVar8);
          if ((cVar7 == '\0') && (iVar10 = (*local_368)(pcVar9), iVar10 == 0)) {
            if ((char)piVar8[2] == '\0') {
              if (BZ1Helper::m_TurnCounter < piVar8[3]) goto LAB_4fc16876;
              iVar10 = (*local_39c)(*piVar8);
              pfStack_3b8 = (float *)GetRandomFloat(local_360);
              if (iVar12 != 0) {
                dStack_3c8 = (double)((float)piVar8[0x12] + (float)local_320);
                fVar21 = GetDistance3DSquared((int)unaff_EDI,(int)unaff_ESI);
                fVar20 = (float)((float10)dStack_3c8 * (float10)dStack_3c8);
                dStack_3c8 = (double)CONCAT44(dStack_3c8._4_4_,fVar20);
                if (fVar21 <= fVar20) goto LAB_4fc16876;
              }
              pcVar16 = local_3b4;
              if ((float)pfStack_3b8 < (float)piVar8[iVar10 + 0x13]) {
                (*local_3b4)(*piVar8,0x15,0,0,0,0);
              }
              uVar2 = local_35c;
            }
            else {
              dStack_3c8 = (double)(float)piVar8[0x12];
              fVar21 = GetDistance3DSquared((int)unaff_EDI,(int)unaff_ESI);
              pcVar16 = local_3b4;
              fVar20 = (float)((float10)dStack_3c8 * (float10)dStack_3c8);
              dStack_3c8 = (double)CONCAT44(dStack_3c8._4_4_,fVar20);
              if (fVar20 <= fVar21) goto LAB_4fc1687a;
              (*local_3b4)(*piVar8,0x15,0,0,0,0);
              uVar2 = local_364;
            }
            iVar12 = (*local_388)(uVar2);
            piVar8[3] = iVar12 + BZ1Helper::m_TurnCounter;
          }
          else {
LAB_4fc16876:
            pcVar16 = local_3b4;
          }
LAB_4fc1687a:
          iVar12 = piVar8[0x4d];
          if (0 < iVar12) {
            iVar10 = piVar8[0x4e];
            if ((char)piVar8[2] == '\0') {
              if (iVar10 < iVar12) {
                pfStack_3c0 = (float *)((float)piVar8[0x50] / (float)BZ1Helper::m_GameTPS +
                                       (float)piVar8[0x51]);
                fVar20 = (float)(int)(float)pfStack_3c0;
                dStack_3c8 = (double)CONCAT44(dStack_3c8._4_4_,fVar20);
                piVar8[0x51] = (int)((float)pfStack_3c0 - fVar20);
                iVar10 = piVar8[0x4e] + (int)(float)pfStack_3c0;
                iVar12 = piVar8[0x4d];
                if (iVar10 < 0) {
                  iVar10 = 0;
                }
                else if (iVar12 < iVar10) {
                  iVar10 = iVar12;
                }
                piVar8[0x4e] = iVar10;
              }
              if ((char)piVar8[0x4c] == '\0') {
                if (iVar10 < iVar12) {
                  *(undefined1 *)(piVar8 + 0x4c) = 1;
                }
                else {
LAB_4fc16a49:
                  *(undefined1 *)(piVar8 + 0x4c) = 0;
                }
              }
              else if (iVar12 <= iVar10) goto LAB_4fc16a49;
LAB_4fc16a50:
              pcVar16 = local_3ac;
            }
            else {
              if (0 < iVar10) {
                pfStack_3c0 = (float *)((float)piVar8[0x4f] / (float)BZ1Helper::m_GameTPS +
                                       (float)piVar8[0x51]);
                fVar20 = (float)(int)(float)pfStack_3c0;
                dStack_3c8 = (double)CONCAT44(dStack_3c8._4_4_,fVar20);
                piVar8[0x51] = (int)((float)pfStack_3c0 - fVar20);
                iVar10 = piVar8[0x4e] - (int)(float)pfStack_3c0;
                if (iVar10 < 0) {
                  iVar10 = 0;
                }
                else if (piVar8[0x4d] < iVar10) {
                  iVar10 = piVar8[0x4d];
                }
                piVar8[0x4e] = iVar10;
              }
              if (((char)piVar8[0x4c] == '\0') && (iVar10 != 0)) goto LAB_4fc16a50;
              (*pcVar16)(*piVar8,0x15,0,0,0,0);
              pcVar16 = local_3ac;
              iVar12 = *piVar8;
              iVar10 = (*local_3ac)();
              if (iVar12 == iVar10) {
                memset(acStack_208,0,0x40);
                GetODFString(0x4fc59398,(char *)0x40,acStack_208,0,(char *)unaff_EDI,unaff_ESI);
                cVar7 = (*local_384)(acStack_208);
                if (cVar7 != '\0') {
                  (*local_350)(acStack_208,local_354,local_3a4,local_358,0,0);
                }
              }
            }
            iVar12 = (*pcVar16)();
            if (*piVar8 == iVar12) {
              dStack_3c8 = (double)CONCAT44(dStack_3c8._4_4_,(float)piVar8[0x4d]);
              BZ1Helper::CloakGauge = (float)piVar8[0x4e] / (float)piVar8[0x4d];
              BZ1Helper::CloakGaugeSet = true;
            }
          }
        }
        iVar12 = (*local_39c)(*piVar8);
        if (iVar12 == 0x15) {
          memset(acStack_188,0,0x40);
          GetSwitchMineODF(this_00,*piVar8,acStack_188);
          (*local_34c)(acStack_188,pcVar9,*piVar8);
        }
      }
      else {
        memset(acStack_308,0,0x40);
        cStack_3b9 = '\0';
        uVar24 = 0x40;
        pcVar9 = "SwitchODF";
        GetODFString(0x4fc5a420,(char *)0x40,acStack_308,0,(char *)unaff_EDI,unaff_ESI);
        GetODFBool(0x4fc5a440,(char *)((int)piVar8 + 10),(char *)0x1,(bool *)pcVar9,(bool)uVar24);
        GetODFBool(0x4fc5a454,&cStack_3b9,(char *)0x1,(bool *)unaff_EDI,SUB41(unaff_ESI,0));
        if ((char)piVar8[2] != '\0') {
          GetODFBool(0x4fc5a440,(char *)((int)piVar8 + 10),(char *)0x1,(bool *)unaff_EDI,
                     SUB41(unaff_ESI,0));
          iVar12 = (*local_38c)(*piVar8);
          piVar8[4] = iVar12;
        }
        memset(acStack_148,0,0x140);
        local_3b0 = acStack_148;
        pfStack_3c0 = (float *)(piVar8 + 0xd);
        iVar12 = 0;
        do {
          (*local_390)(*piVar8,iVar12 + 5,local_3b0);
          bVar5 = false;
          memset(auStack_288,0,0x40);
          (*local_390)(*piVar8,iVar12 + 10,auStack_288);
          if ((char)piVar8[2] == '\0') {
            pfVar15 = pfStack_3c0;
          }
          else {
            fVar20 = GetCurLocalAmmo(*piVar8,iVar12);
            pfVar15 = pfStack_3c0;
            pfStack_3c0[-5] = fVar20;
            fVar20 = GetMaxLocalAmmo(*piVar8,iVar12);
            *pfVar15 = fVar20;
          }
          bVar6 = OpenODF2((char *)unaff_EDI);
          if (bVar6) {
            memset(acStack_2c8,0,0x40);
            iVar10 = GetODFString("DispenserClass","objectClass",(char *)0x40,acStack_2c8,0,
                                  (char *)unaff_EDI,unaff_ESI);
            if (iVar10 != 0) {
              memset(acStack_1c8,0,0x40);
              CombineStrings(".odf",(char *)0x40,(char *)unaff_EDI,(uint)unaff_ESI);
              bVar6 = OpenODF2((char *)unaff_EDI);
              if ((bVar6) &&
                 (iVar10 = GetODFString("GameObjectClass","BZCClasslabel",(char *)0x40,acStack_1c8,0
                                        ,(char *)unaff_EDI,unaff_ESI), iVar10 != 0)) {
                iVar10 = (*local_37c)(acStack_1c8,"MorphObjecttoggle");
                bVar5 = false;
                if (iVar10 == 0) {
                  bVar5 = true;
                }
              }
            }
          }
          if (cStack_3b9 == '\0') {
            if ((bVar5) &&
               (iVar10 = GetODFString("WeaponClass","altName",(char *)0x40,local_3b0,0,
                                      (char *)unaff_EDI,unaff_ESI), iVar10 != 0)) break;
          }
          else {
            GetODFString("WeaponClass","altName",(char *)0x40,local_3b0,0,(char *)unaff_EDI,
                         unaff_ESI);
          }
          iVar12 = iVar12 + 1;
          pfStack_3c0 = pfVar15 + 1;
          local_3b0 = local_3b0 + 0x40;
        } while (iVar12 < 5);
        if (acStack_308[0] != '\0') {
          cVar7 = (*local_378)(acStack_308);
          this_01 = local_398;
          pcVar16 = local_39c;
          if (cVar7 == '\0') {
            FormatLogMessage("ERROR: SwitchODF \'%s\' does not exist. Fix ODFs!");
          }
          else {
            local_398[1].teamInfo[0].PilotWeapon[4][0x22] = '\x01';
            iVar10 = (*local_39c)(*piVar8);
            iVar12 = *piVar8;
            if (iVar10 == 0x15) {
              iVar22 = piVar8[6];
              iVar12 = (*pcVar16)(iVar12);
              if ((iVar22 == iVar12) || (iVar22 == 0x15)) {
                uStack_338 = 0;
                uStack_334 = 0;
                uStack_330 = 0;
                iVar23 = -1;
                iVar22 = -1;
                bVar5 = false;
                iVar10 = 0;
                iVar25 = 0;
                fVar20 = 0.0;
              }
              else {
                iVar23 = local_3a0[1];
                bVar5 = true;
                iVar10 = piVar8[0x49];
                iVar25 = piVar8[0x4a];
                fVar20 = (float)piVar8[0x4b];
              }
              iVar12 = *local_3a0;
              this_01 = local_398;
            }
            else {
              uStack_32c = 0;
              uStack_328 = 0;
              uStack_324 = 0;
              iVar23 = -1;
              iVar22 = -1;
              iVar10 = 0;
              bVar5 = true;
              iVar25 = 0;
              fVar20 = 0.0;
            }
            VVar3.y = (float)iVar25;
            VVar3.x = (float)iVar10;
            VVar3.z = fVar20;
            iVar12 = BZ1Helper::ReplaceObject
                               (this_01,iVar12,acStack_308,-1,local_3a4,-1,false,-1,-1,bVar5,iVar22,
                                0,iVar23,VVar3);
            piVar8 = local_3a0;
            *local_3a0 = iVar12;
            this_01[1].teamInfo[0].PilotWeapon[4][0x22] = '\0';
            memset(acStack_248,0,0x40);
            pcVar9 = "soundUndeploy";
            if ((char)piVar8[2] != '\0') {
              pcVar9 = "soundDeploy";
            }
            GetODFString((int)pcVar9,(char *)0x40,acStack_248,0,(char *)unaff_EDI,unaff_ESI);
            cVar7 = (*local_384)(acStack_248);
            if (cVar7 == '\0') {
              if (acStack_248[0] != '\0') {
                FormatLogMessage("ERROR: Morph Object SoundDeploy \'%s\' Doesn\'t Exist! FIX ODFs!")
                ;
              }
            }
            else {
              (*local_374)(acStack_248,*piVar8,7,0,1);
            }
            if (*(char *)((int)piVar8 + 0xb) != '\0') {
              if ((char)piVar8[2] == '\0') {
                iVar12 = piVar8[7];
              }
              else {
                iVar12 = 0;
              }
              (*(code *)local_3a8)(*piVar8,iVar12);
            }
            if (*(char *)((int)piVar8 + 10) == '\0') {
              if ((char)piVar8[2] == '\0') {
                iVar12 = piVar8[4];
              }
              else {
                iVar12 = 0;
              }
              (*local_394)(*piVar8,iVar12);
            }
            *(undefined1 *)((int)piVar8 + 9) = 0;
            ReplaceWeapons((int)(piVar8 + 8),(char (*) [64])0x0,unaff_EDI,unaff_ESI);
          }
        }
      }
      pcVar16 = local_39c;
      iVar12 = (*local_39c)(*piVar8);
      if (iVar12 != 0x15) {
        iVar12 = (*pcVar16)(*piVar8);
        piVar8[6] = iVar12;
        iVar12 = (*local_348)(*piVar8);
        piVar8[1] = iVar12;
        iVar12 = piVar8[6];
        if (((iVar12 == 3) || (iVar12 == 10)) || (iVar12 - 0x1aU < 2)) {
          piVar11 = (int *)(*local_344)(auStack_314,*piVar8);
          piVar8[0x49] = *piVar11;
          piVar8[0x4a] = piVar11[1];
          piVar8[0x4b] = piVar11[2];
          piVar8 = local_3a0;
        }
      }
      local_3a0 = piVar8 + 0x52;
    } while (local_3a0 != *(int **)&(local_380->MorphObjectList).field_0x4);
  }
  return;
}


// ---------------------------------------------------------------------
// MorphObjectHelper::GetSwitchMineODF  @ 4fc16b68  lines 518-542


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
// MorphObjectHelper::PrePickupPowerup  @ 4fc16c9a  lines 546-577


PrePickupPowerupReturnCodes __thiscall
MorphObjectHelper::PrePickupPowerup
          (MorphObjectHelper *this,int param_1,int param_2,int param_3,int param_4,char *param_5)

{
  int *piVar1;
  
  if (param_1 == 0) {
    for (piVar1 = *(int **)&this->MorphObjectList;
        piVar1 != *(int **)&(this->MorphObjectList).field_0x4; piVar1 = piVar1 + 0x52) {
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
    }
  }
  return PREPICKUPPOWERUP_ALLOW;
}

