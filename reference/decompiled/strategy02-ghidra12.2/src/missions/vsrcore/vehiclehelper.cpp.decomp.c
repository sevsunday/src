// Reconstructed by Ghidra from Strategy02.dll + Strategy02.pdb
// Original source file: /e:/github/vsr_dll_source/missions/vsrcore/vehiclehelper.cpp
// Functions are ordered by original source line. This is decompiler
// output, not the author's source: names/types come from the PDB,
// local variable names and control flow are reconstructed.


// ---------------------------------------------------------------------
// `dynamic_initializer_for_'TempVehicleBuffer''  @ 4fc0186c  lines 5-5


void __cdecl _dynamic_initializer_for__TempVehicleBuffer__(void)

{
  atexit(_dynamic_atexit_destructor_for__TempVehicleBuffer__);
  return;
}


// ---------------------------------------------------------------------
// VehicleHelper::PostLoad  @ 4fc24158  lines 26-47


bool __thiscall VehicleHelper::PostLoad(VehicleHelper *this,bool param_1)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  VehicleClass *unaff_ESI;
  int *piVar5;
  VehicleClass *unaff_EDI;
  
  piVar5 = *(int **)&this->VehicleList;
  piVar2 = *(int **)&(this->VehicleList).field_0x4;
  if (piVar5 != piVar2) {
    do {
      ConvertHandles(piVar5,1);
      piVar2 = *(int **)&(this->VehicleList).field_0x4;
      piVar5 = piVar5 + 0x15;
    } while (piVar5 != piVar2);
    piVar5 = *(int **)&this->VehicleList;
  }
  iVar3 = ((int)piVar2 - (int)piVar5) / 0x54;
  if ((int)(TempVehicleBuffer._4_4_ - TempVehicleBuffer._0_4_) / 0x54 == iVar3) {
    iVar4 = 0;
    if (0 < iVar3) {
      do {
        bVar1 = ::operator==(unaff_EDI,unaff_ESI);
        if (!bVar1) {
          FormatLogMessage("VehicleList Index Mismatch: %d");
          return true;
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < (*(int *)&(this->VehicleList).field_0x4 - *(int *)&this->VehicleList) / 0x54)
      ;
    }
  }
  else {
    FormatLogMessage("VehicleList Size Mismatch! Old: %d New: %d");
  }
  return true;
}


// ---------------------------------------------------------------------
// VehicleHelper::Save  @ 4fc241f3  lines 50-59


bool __thiscall VehicleHelper::Save(VehicleHelper *this,bool param_1)

{
  bool bVar1;
  int local_8;
  
  local_8 = (*(int *)&(this->VehicleList).field_0x4 - *(int *)&this->VehicleList) / 0x54;
  bVar1 = Write(&local_8,1);
  if (local_8 != 0) {
    if ((bVar1) && (bVar1 = Write(*(void **)&this->VehicleList,local_8 * 0x54), bVar1)) {
      return true;
    }
    bVar1 = false;
  }
  return bVar1;
}


// ---------------------------------------------------------------------
// VehicleHelper::Execute  @ 4fc24243  lines 68-310


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall VehicleHelper::Execute(VehicleHelper *this,BZ1Helper *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  bool bVar4;
  float fVar5;
  AiCommand AVar6;
  char *pcVar7;
  float fVar8;
  AlignTerrainReplaceClass *pAVar9;
  int iVar10;
  int iVar11;
  AlignTerrainReplaceClass *pAVar12;
  int unaff_ESI;
  Vector *pVVar13;
  AlignTerrainReplaceClass *pAVar14;
  int unaff_EDI;
  size_t sVar15;
  int iVar16;
  char *pcVar17;
  AlignTerrainReplaceClass *local_7c;
  double local_78;
  Vector *local_70;
  AlignTerrainReplaceClass *local_6c;
  BZ1Helper *local_68;
  float local_64;
  AiCommand local_60;
  AlignTerrainReplaceClass *local_5c;
  AlignTerrainReplaceClass *local_58;
  AlignTerrainReplaceClass *local_54;
  Vector local_50;
  char local_44 [64];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)&local_7c;
  local_68 = param_1;
  pAVar14 = *(AlignTerrainReplaceClass **)&(this->VehicleList).field_0x4;
  pAVar9 = *(AlignTerrainReplaceClass **)&this->VehicleList;
  local_7c = pAVar14;
  local_6c = (AlignTerrainReplaceClass *)this;
  local_5c = pAVar14;
  local_58 = pAVar9;
  while ((pAVar9 != pAVar14 && (bVar4 = BZ1Helper::ShouldRemoveAlignTerrainReplace(pAVar9), !bVar4))
        ) {
    pAVar9 = (AlignTerrainReplaceClass *)&pAVar9[5].NormalVec;
  }
  pAVar12 = pAVar9;
  if (pAVar9 != pAVar14) {
    while( true ) {
      this = (VehicleHelper *)local_6c;
      pAVar12 = (AlignTerrainReplaceClass *)&pAVar12[5].NormalVec;
      if (pAVar12 == pAVar14) break;
      bVar4 = BZ1Helper::ShouldRemoveAlignTerrainReplace(pAVar12);
      if (!bVar4) {
        pVVar13 = (Vector *)pAVar12;
        pAVar14 = pAVar9;
        for (iVar10 = 0x15; iVar10 != 0; iVar10 = iVar10 + -1) {
          pAVar14->AlignHandle = (int)pVVar13->x;
          pVVar13 = (Vector *)&pVVar13->y;
          pAVar14 = (AlignTerrainReplaceClass *)&pAVar14->NormalVec;
        }
        pAVar9 = (AlignTerrainReplaceClass *)&pAVar9[5].NormalVec;
        pAVar14 = local_7c;
      }
    }
    if (pAVar9 != pAVar14) {
      sVar15 = *(int *)&((vector<VehicleHelper::VehicleClass,std::allocator<VehicleHelper::VehicleClass>_>
                          *)&local_6c->AlignHandle)->field_0x4 - (int)pAVar14;
      memmove(pAVar9,pAVar14,sVar15);
      pAVar9 = (AlignTerrainReplaceClass *)(sVar15 + (int)pAVar9);
      *(AlignTerrainReplaceClass **)
       &((vector<VehicleHelper::VehicleClass,std::allocator<VehicleHelper::VehicleClass>_> *)
        &((AlignTerrainReplaceClass *)this)->AlignHandle)->field_0x4 = pAVar9;
      goto LAB_4fc242da;
    }
  }
  pAVar9 = *(AlignTerrainReplaceClass **)&(this->VehicleList).field_0x4;
LAB_4fc242da:
  pAVar14 = *(AlignTerrainReplaceClass **)&this->VehicleList;
  do {
    if (pAVar14 == pAVar9) {
      return;
    }
    local_7c = pAVar14;
    local_6c = pAVar14;
    fVar5 = (float)GetTeamNum(pAVar14->AlignHandle);
    pAVar14[2].NormalVec.y = fVar5;
    GetPosition(pAVar14->AlignHandle,&local_50);
    pAVar9 = local_7c;
    pAVar14[4].NormalVec.y = local_50.x;
    pAVar14[4].NormalVec.z = local_50.y;
    pAVar14[5].AlignHandle = (int)local_50.z;
    AVar6 = GetCurrentCommand(local_7c->AlignHandle);
    local_60 = AVar6;
    fVar5 = (float)GetPerceivedTeam(pAVar9->AlignHandle);
    pAVar9[2].NormalVec.z = fVar5;
    if (AVar6 == CMD_HUNT) {
      iVar10 = GetPlayerHandle((int)pAVar9[2].NormalVec.y);
      fVar5 = pAVar9[2].NormalVec.y;
      iVar11 = (int)fVar5 * 0xa14;
      if (((*(char *)((int)&pAVar9[1].NormalVec.y + 2) == '\0') || (iVar10 == 0)) ||
         (*(char *)((int)local_68->teamInfo + iVar11 + 0x113) != '\0')) {
        if (iVar10 != pAVar9->AlignHandle) {
          if (*(char *)((int)&pAVar9[1].NormalVec.y + 3) == '\0') {
            fVar5 = (pAVar9->NormalVec).y;
            if ((uint)fVar5 < 0x77f02e22) {
              if (fVar5 == 9.742866e+33) {
LAB_4fc24522:
                iVar10 = 0;
                iVar11 = 2;
                goto LAB_4fc24559;
              }
              if (fVar5 == 5.29286e-36) {
                iVar10 = BZ1Helper::GetNearestObject
                                   (local_68,pAVar9->AlignHandle,__real_42c80000,-1,0,false,1,
                                    SUB41(local_68,0),SUB41(local_68,0),3,"CLASS_ARTIFACT",
                                    (char *)local_68);
                if (iVar10 != 0) {
                  iVar11 = 7;
                  goto LAB_4fc24559;
                }
                iVar10 = 0xb;
                pcVar7 = (char *)pAVar9->AlignHandle;
                SetCommand((int)pcVar7,0xb,0,0,(char *)0x0,0);
                PlayVOMsg((int)pAVar9[2].NormalVec.y,pcVar7,iVar10);
              }
              else {
                if ((fVar5 == 1.2450273e-34) || (fVar5 == 1.0185783e-18)) goto LAB_4fc245a5;
                if (fVar5 == 3.3162872e-17) goto LAB_4fc24522;
              }
            }
            else if (((fVar5 == -1682958.9) || (fVar5 == -2.4274862e+08)) ||
                    (fVar5 == -1.135819e+30)) {
LAB_4fc245a5:
              iVar10 = 0;
              iVar11 = 10;
              goto LAB_4fc24559;
            }
          }
          else {
            fVar5 = GetHealth(pAVar9->AlignHandle);
            local_78 = (double)fVar5;
            fVar5 = GetAmmo(pAVar9->AlignHandle);
            if (fVar5 < (float)local_78) {
              iVar10 = 0;
              iVar11 = 0xd;
            }
            else {
              iVar10 = 0;
              iVar11 = 0xc;
            }
LAB_4fc24559:
            SetCommand(pAVar9->AlignHandle,iVar11,0,iVar10,(char *)0x0,0);
          }
        }
      }
      else {
        if ((iVar10 == *(int *)((int)local_68->teamInfo + iVar11 + 8)) ||
           (iVar10 == pAVar9->AlignHandle)) {
          iVar10 = 0;
          iVar11 = 0;
          goto LAB_4fc24559;
        }
        iVar16 = pAVar9->AlignHandle;
        SetAsUser(iVar16,(int)fVar5);
        pcVar7 = GetPilotConfig(iVar16);
        SetPilotClass(pAVar9->AlignHandle,pcVar7);
        *(undefined1 *)((int)local_68->teamInfo + iVar11 + 0x113) = 1;
        bVar4 = IsPerson(iVar10);
        if (bVar4) {
          RemoveObject(iVar10);
        }
        else {
          AddPilotByHandle(iVar10);
          SetBestGroup(iVar10);
        }
      }
    }
    if (local_68[1].teamInfo[0].PilotWeapon[4][0x1c] != '\0') {
      if ((*(char *)&pAVar9[1].NormalVec.y != '\0') && ((int)pAVar9[2].NormalVec.x < 1)) {
        fVar5 = pAVar9[2].NormalVec.y;
        GetLocalPlayerTeamNumber();
        bVar4 = TeamFilterCheck((int)fVar5,unaff_EDI,unaff_ESI);
        if (bVar4) {
          pAVar9[2].NormalVec.x = (float)BZ1Helper::m_GameTPS;
        }
      }
      pAVar9[2].NormalVec.x = (float)((int)pAVar9[2].NormalVec.x + -1);
    }
    pAVar14 = pAVar9 + 3;
    if (0 < pAVar14->AlignHandle) {
      bVar4 = IsDeployed(pAVar9->AlignHandle);
      fVar8 = (float)GetPlayerHandle();
      local_70 = &pAVar9[3].NormalVec;
      fVar5 = local_70->x;
      local_64 = fVar8;
      if (bVar4) {
        if (0 < (int)fVar5) {
          local_7c = (AlignTerrainReplaceClass *)
                     ((float)(int)pAVar9[3].NormalVec.y / (float)BZ1Helper::m_GameTPS +
                     (float)pAVar9[4].AlignHandle);
          fVar5 = (float)((int)fVar5 - (int)(float)local_7c);
          fVar1 = (float)(int)(float)local_7c;
          local_78 = (double)CONCAT44(local_78._4_4_,fVar1);
          pAVar9[4].AlignHandle = (int)((float)local_7c - fVar1);
          if ((int)fVar5 < 0) {
            fVar5 = 0.0;
          }
          else if (pAVar14->AlignHandle < (int)fVar5) {
            fVar5 = (float)pAVar14->AlignHandle;
          }
          local_70->x = fVar5;
          pAVar9 = local_6c;
        }
        if ((*(char *)((int)&pAVar9[1].NormalVec.y + 1) != '\0') || (fVar5 == 0.0)) {
          bVar4 = IsPlayer(pAVar9->AlignHandle);
          if (bVar4) {
            Deploy(pAVar9->AlignHandle);
          }
          else {
            SetCommand(pAVar9->AlignHandle,0x30,0,0,(char *)0x0,0);
          }
          fVar8 = local_64;
          if ((float)pAVar9->AlignHandle != local_64) goto LAB_4fc24723;
          pcVar7 = local_44;
          pcVar17 = (char *)0x0;
          memset(pcVar7,0,0x40);
          GetODFString(0x4fc5c7e8,(char *)0x40,local_44,0,pcVar7,pcVar17);
          if ((local_44[0] != '\0') && (bVar4 = DoesFileExist(local_44), bVar4)) {
            StartAudio2D(local_44,__real_bf800000,0.0,___real_462c4400,false,false);
          }
        }
      }
      else {
        fVar1 = (float)pAVar14->AlignHandle;
        if ((int)fVar5 < (int)fVar1) {
          fVar2 = (float)(int)pAVar9[3].NormalVec.z / (float)BZ1Helper::m_GameTPS +
                  (float)pAVar9[4].AlignHandle;
          iVar10 = (int)fVar2;
          fVar5 = (float)((int)fVar5 + iVar10);
          fVar3 = (float)iVar10;
          local_78 = (double)CONCAT44(local_78._4_4_,fVar3);
          pAVar9[4].AlignHandle = (int)(fVar2 - fVar3);
          if ((int)fVar5 < 0) {
            fVar5 = 0.0;
          }
          else if ((int)fVar1 < (int)fVar5) {
            fVar5 = fVar1;
          }
          local_70->x = fVar5;
          pAVar9 = local_6c;
        }
        if (*(char *)((int)&pAVar9[1].NormalVec.y + 1) == '\0') {
          if ((int)fVar1 <= (int)fVar5) goto LAB_4fc246ee;
          *(undefined1 *)((int)&pAVar9[1].NormalVec.y + 1) = 1;
        }
        else if ((int)fVar1 <= (int)fVar5) {
LAB_4fc246ee:
          *(undefined1 *)((int)&pAVar9[1].NormalVec.y + 1) = 0;
        }
      }
      if ((float)pAVar9->AlignHandle == fVar8) {
        local_78 = (double)CONCAT44(local_78._4_4_,(float)pAVar14->AlignHandle);
        BZ1Helper::CloakGauge = (float)(int)local_70->x / (float)pAVar14->AlignHandle;
        BZ1Helper::CloakGaugeSet = true;
        pAVar9 = local_6c;
      }
    }
LAB_4fc24723:
    pAVar9[1].AlignHandle = local_60;
    pAVar14 = (AlignTerrainReplaceClass *)&pAVar9[5].NormalVec;
    pAVar9 = *(AlignTerrainReplaceClass **)&(this->VehicleList).field_0x4;
    local_54 = pAVar9;
  } while( true );
}

