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
  int *piVar5;
  
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
  iVar4 = (int)(TempVehicleBuffer._4_4_ - TempVehicleBuffer._0_4_) / 0x54;
  if (iVar4 == iVar3) {
    iVar4 = 0;
    if (0 < iVar3) {
      iVar3 = 0;
      do {
        bVar1 = ::operator==((VehicleClass *)(TempVehicleBuffer._0_4_ + iVar3),
                             (VehicleClass *)((int)piVar5 + iVar3));
        if (!bVar1) {
          FormatLogMessage("VehicleList Index Mismatch: %d",iVar4);
          return true;
        }
        iVar4 = iVar4 + 1;
        piVar5 = *(int **)&this->VehicleList;
        iVar3 = iVar3 + 0x54;
      } while (iVar4 < (*(int *)&(this->VehicleList).field_0x4 - (int)piVar5) / 0x54);
    }
  }
  else {
    FormatLogMessage("VehicleList Size Mismatch! Old: %d New: %d",iVar4,iVar3);
  }
  return true;
}


// ---------------------------------------------------------------------
// VehicleHelper::Save  @ 4fc241f3  lines 50-59

bool __thiscall VehicleHelper::Save(VehicleHelper *this,bool param_1)

{
  bool bVar1;
  int size;
  
  size = (*(int *)&(this->VehicleList).field_0x4 - *(int *)&this->VehicleList) / 0x54;
  bVar1 = Write(&size,1);
  if (size != 0) {
    if ((bVar1) && (bVar1 = Write(*(void **)&this->VehicleList,size * 0x54), bVar1)) {
      return true;
    }
    bVar1 = false;
  }
  return bVar1;
}


// ---------------------------------------------------------------------
// VehicleHelper::Execute  @ 4fc24243  lines 68-310

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall VehicleHelper::Execute(VehicleHelper *this,BZ1Helper *bz1Helper)

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
  AlignTerrainReplaceClass *entry;
  Vector *pVVar11;
  AlignTerrainReplaceClass *pAVar12;
  size_t sVar13;
  int iVar14;
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
  local_68 = bz1Helper;
  pAVar12 = *(AlignTerrainReplaceClass **)&(this->VehicleList).field_0x4;
  pAVar9 = *(AlignTerrainReplaceClass **)&this->VehicleList;
  local_7c = pAVar12;
  local_6c = (AlignTerrainReplaceClass *)this;
  local_5c = pAVar12;
  local_58 = pAVar9;
  while ((pAVar9 != pAVar12 && (bVar4 = BZ1Helper::ShouldRemoveAlignTerrainReplace(pAVar9), !bVar4))
        ) {
    pAVar9 = (AlignTerrainReplaceClass *)&pAVar9[5].NormalVec;
  }
  entry = pAVar9;
  if (pAVar9 != pAVar12) {
    while (this = (VehicleHelper *)local_6c, entry = (AlignTerrainReplaceClass *)&entry[5].NormalVec
          , entry != pAVar12) {
      bVar4 = BZ1Helper::ShouldRemoveAlignTerrainReplace(entry);
      if (!bVar4) {
        pVVar11 = (Vector *)entry;
        pAVar12 = pAVar9;
        for (iVar10 = 0x15; iVar10 != 0; iVar10 = iVar10 + -1) {
          pAVar12->AlignHandle = (int)pVVar11->x;
          pVVar11 = (Vector *)&pVVar11->y;
          pAVar12 = (AlignTerrainReplaceClass *)&pAVar12->NormalVec;
        }
        pAVar9 = (AlignTerrainReplaceClass *)&pAVar9[5].NormalVec;
        pAVar12 = local_7c;
      }
    }
    if (pAVar9 != pAVar12) {
      sVar13 = *(int *)&((vector<VehicleHelper::VehicleClass,std::allocator<VehicleHelper::VehicleClass>_>
                          *)&local_6c->AlignHandle)->field_0x4 - (int)pAVar12;
      memmove(pAVar9,pAVar12,sVar13);
      pAVar9 = (AlignTerrainReplaceClass *)(sVar13 + (int)pAVar9);
      *(AlignTerrainReplaceClass **)
       &((vector<VehicleHelper::VehicleClass,std::allocator<VehicleHelper::VehicleClass>_> *)
        &((AlignTerrainReplaceClass *)this)->AlignHandle)->field_0x4 = pAVar9;
      goto LAB_4fc242da;
    }
  }
  pAVar9 = *(AlignTerrainReplaceClass **)&(this->VehicleList).field_0x4;
LAB_4fc242da:
  pAVar12 = *(AlignTerrainReplaceClass **)&this->VehicleList;
  do {
    if (pAVar12 == pAVar9) {
      return;
    }
    local_7c = pAVar12;
    local_6c = pAVar12;
    fVar5 = (float)GetTeamNum(pAVar12->AlignHandle);
    pAVar12[2].NormalVec.y = fVar5;
    GetPosition(pAVar12->AlignHandle,&local_50);
    pAVar9 = local_7c;
    pAVar12[4].NormalVec.y = local_50.x;
    pAVar12[4].NormalVec.z = local_50.y;
    pAVar12[5].AlignHandle = (int)local_50.z;
    AVar6 = GetCurrentCommand(local_7c->AlignHandle);
    local_60 = AVar6;
    fVar5 = (float)GetPerceivedTeam(pAVar9->AlignHandle);
    pAVar9[2].NormalVec.z = fVar5;
    if (AVar6 == CMD_HUNT) {
      iVar10 = GetPlayerHandle((int)pAVar9[2].NormalVec.y);
      fVar5 = pAVar9[2].NormalVec.y;
      if (((*(char *)((int)&pAVar9[1].NormalVec.y + 2) == '\0') || (iVar10 == 0)) ||
         (local_68->teamInfo[(int)fVar5].TookControlThisTurn != false)) {
        if (iVar10 != pAVar9->AlignHandle) {
          if (*(char *)((int)&pAVar9[1].NormalVec.y + 3) == '\0') {
            fVar5 = (pAVar9->NormalVec).y;
            if ((uint)fVar5 < 0x77f02e22) {
              if (fVar5 == 9.742866e+33) {
LAB_4fc24522:
                iVar10 = 0;
                iVar14 = 2;
                goto LAB_4fc24559;
              }
              if (fVar5 == 5.29286e-36) {
                iVar10 = BZ1Helper::GetNearestObject
                                   (local_68,pAVar9->AlignHandle,100.0,-1,0,false,1,
                                    SUB41(local_68,0),SUB41(local_68,0),3,"CLASS_ARTIFACT",
                                    (char *)local_68);
                if (iVar10 != 0) {
                  iVar14 = 7;
                  goto LAB_4fc24559;
                }
                SetCommand(pAVar9->AlignHandle,0xb,0,0,(char *)0x0,0);
                PlayVOMsg(pAVar9->AlignHandle,"user2Msg",(int)pAVar9[2].NormalVec.y);
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
              iVar14 = 10;
              goto LAB_4fc24559;
            }
          }
          else {
            fVar5 = GetHealth(pAVar9->AlignHandle);
            local_78 = (double)fVar5;
            fVar5 = GetAmmo(pAVar9->AlignHandle);
            if (fVar5 < (float)local_78) {
              iVar10 = 0;
              iVar14 = 0xd;
            }
            else {
              iVar10 = 0;
              iVar14 = 0xc;
            }
LAB_4fc24559:
            SetCommand(pAVar9->AlignHandle,iVar14,0,iVar10,(char *)0x0,0);
          }
        }
      }
      else {
        if ((iVar10 == local_68->teamInfo[(int)fVar5].SatellitePlayer) ||
           (iVar10 == pAVar9->AlignHandle)) {
          iVar10 = 0;
          iVar14 = 0;
          goto LAB_4fc24559;
        }
        SetAsUser(pAVar9->AlignHandle,(int)fVar5);
        pcVar7 = GetPilotConfig(iVar10);
        SetPilotClass(pAVar9->AlignHandle,pcVar7);
        local_68->teamInfo[(int)fVar5].TookControlThisTurn = true;
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
    if (local_68->m_UseSkillLevels != false) {
      if ((*(char *)&pAVar9[1].NormalVec.y != '\0') && ((int)pAVar9[2].NormalVec.x < 1)) {
        fVar5 = pAVar9[2].NormalVec.y;
        iVar10 = GetLocalPlayerTeamNumber();
        bVar4 = TeamFilterCheck(pAVar9[2].AlignHandle,iVar10,(int)fVar5);
        if (bVar4) {
          pAVar9[2].NormalVec.x = (float)BZ1Helper::m_GameTPS;
        }
      }
      pAVar9[2].NormalVec.x = (float)((int)pAVar9[2].NormalVec.x + -1);
    }
    pAVar12 = pAVar9 + 3;
    if (0 < pAVar12->AlignHandle) {
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
          else if (pAVar12->AlignHandle < (int)fVar5) {
            fVar5 = (float)pAVar12->AlignHandle;
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
          memset(local_44,0,0x40);
          GetODFString(pAVar9->AlignHandle,"GameObjectClass","CloakFailSound",0x40,local_44,
                       (char *)0x0);
          if ((local_44[0] != '\0') && (bVar4 = DoesFileExist(local_44), bVar4)) {
            StartAudio2D(local_44,-1.0,0.0,11025.0,false,false);
          }
        }
      }
      else {
        fVar1 = (float)pAVar12->AlignHandle;
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
          if ((int)fVar5 < (int)fVar1) {
            *(undefined1 *)((int)&pAVar9[1].NormalVec.y + 1) = 1;
          }
          else {
LAB_4fc246ee:
            *(undefined1 *)((int)&pAVar9[1].NormalVec.y + 1) = 0;
          }
        }
        else if ((int)fVar1 <= (int)fVar5) goto LAB_4fc246ee;
      }
      if ((float)pAVar9->AlignHandle == fVar8) {
        local_78 = (double)CONCAT44(local_78._4_4_,(float)pAVar12->AlignHandle);
        BZ1Helper::CloakGauge = (float)(int)local_70->x / (float)pAVar12->AlignHandle;
        BZ1Helper::CloakGaugeSet = true;
        pAVar9 = local_6c;
      }
    }
LAB_4fc24723:
    pAVar9[1].AlignHandle = local_60;
    pAVar12 = (AlignTerrainReplaceClass *)&pAVar9[5].NormalVec;
    pAVar9 = *(AlignTerrainReplaceClass **)&(this->VehicleList).field_0x4;
    local_54 = pAVar9;
  } while( true );
}


