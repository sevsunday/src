// Reconstructed by Ghidra from Instant.dll + Instant.pdb
// Original source file: /e:/github/vsr_dll_source/missions/vsrcore/vehiclehelper.cpp
// Functions are ordered by original source line. This is decompiler
// output, not the author's source: names/types come from the PDB,
// local variable names and control flow are reconstructed.


// ---------------------------------------------------------------------
// `dynamic_initializer_for_'TempVehicleBuffer''  @ 4fc0186a  lines 5-5


void __cdecl _dynamic_initializer_for__TempVehicleBuffer__(void)

{
  atexit(_dynamic_atexit_destructor_for__TempVehicleBuffer__);
  return;
}


// ---------------------------------------------------------------------
// VehicleHelper::PostLoad  @ 4fc234a6  lines 26-47


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
// VehicleHelper::Save  @ 4fc23541  lines 50-59


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
// VehicleHelper::Execute  @ 4fc23591  lines 68-310


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall VehicleHelper::Execute(VehicleHelper *this,BZ1Helper *param_1)

{
  AlignTerrainReplaceClass *pAVar1;
  uint uVar2;
  float fVar3;
  bool bVar4;
  int *piVar5;
  int iVar6;
  AiCommand AVar7;
  char *pcVar8;
  int iVar9;
  int iVar10;
  AlignTerrainReplaceClass *pAVar11;
  AlignTerrainReplaceClass *pAVar12;
  int iVar13;
  int unaff_ESI;
  AlignTerrainReplaceClass *pAVar14;
  size_t sVar15;
  int unaff_EDI;
  float fVar16;
  int iVar17;
  char *pcVar18;
  double local_64;
  AlignTerrainReplaceClass *local_5c;
  BZ1Helper *local_58;
  AiCommand local_54;
  Vector local_50;
  char local_44 [64];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)&local_64;
  local_58 = param_1;
  local_64 = (double)CONCAT44(local_64._4_4_,this);
  pAVar1 = *(AlignTerrainReplaceClass **)&(this->VehicleList).field_0x4;
  pAVar12 = *(AlignTerrainReplaceClass **)&this->VehicleList;
  while ((pAVar12 != pAVar1 && (bVar4 = BZ1Helper::ShouldRemoveAlignTerrainReplace(pAVar12), !bVar4)
         )) {
    pAVar12 = (AlignTerrainReplaceClass *)&pAVar12[5].NormalVec;
  }
  if (pAVar12 != pAVar1) {
    local_5c = (AlignTerrainReplaceClass *)&pAVar12[5].NormalVec;
    pAVar11 = pAVar12;
    if (local_5c != pAVar1) {
      do {
        pAVar14 = local_5c;
        bVar4 = BZ1Helper::ShouldRemoveAlignTerrainReplace(local_5c);
        pAVar12 = pAVar11;
        if (!bVar4) {
          pAVar12 = (AlignTerrainReplaceClass *)&pAVar11[5].NormalVec;
          for (iVar10 = 0x15; iVar10 != 0; iVar10 = iVar10 + -1) {
            pAVar11->AlignHandle = pAVar14->AlignHandle;
            pAVar14 = (AlignTerrainReplaceClass *)&pAVar14->NormalVec;
            pAVar11 = (AlignTerrainReplaceClass *)&pAVar11->NormalVec;
          }
          pAVar14 = local_5c;
        }
        local_5c = (AlignTerrainReplaceClass *)&pAVar14[5].NormalVec;
        pAVar11 = pAVar12;
      } while (local_5c != pAVar1);
      this = local_64._0_4_;
    }
    if (pAVar12 != pAVar1) {
      sVar15 = *(int *)&(this->VehicleList).field_0x4 - (int)pAVar1;
      memmove(pAVar12,pAVar1,sVar15);
      piVar5 = (int *)(sVar15 + (int)pAVar12);
      *(int **)&(this->VehicleList).field_0x4 = piVar5;
      goto LAB_4fc23620;
    }
  }
  piVar5 = *(int **)&(this->VehicleList).field_0x4;
LAB_4fc23620:
  local_5c = *(AlignTerrainReplaceClass **)&this->VehicleList;
  if (local_5c != (AlignTerrainReplaceClass *)piVar5) {
    iVar10 = (int)local_64._0_4_;
    do {
      pAVar1 = local_5c;
      iVar6 = GetTeamNum(local_5c->AlignHandle);
      *(int *)((int)pAVar1 + 0x28) = iVar6;
      GetPosition(pAVar1->AlignHandle,&local_50);
      pAVar12 = local_5c;
      *(float *)((int)pAVar1 + 0x48) = local_50.x;
      *(float *)((int)pAVar1 + 0x4c) = local_50.y;
      *(float *)((int)pAVar1 + 0x50) = local_50.z;
      AVar7 = GetCurrentCommand(local_5c->AlignHandle);
      local_54 = AVar7;
      iVar6 = GetPerceivedTeam(pAVar12->AlignHandle);
      *(int *)((int)pAVar12 + 0x2c) = iVar6;
      if (AVar7 == CMD_HUNT) {
        iVar6 = GetPlayerHandle(*(int *)((int)pAVar12 + 0x28));
        iVar13 = *(int *)((int)pAVar12 + 0x28) * 0xa14;
        if (((*(char *)((int)pAVar12 + 0x1a) == '\0') || (iVar6 == 0)) ||
           (*(char *)((int)local_58->teamInfo + iVar13 + 0x113) != '\0')) {
          if (iVar6 != pAVar12->AlignHandle) {
            if (*(char *)((int)pAVar12 + 0x1b) == '\0') {
              uVar2 = *(uint *)((int)pAVar12 + 8);
              if (uVar2 < 0x77f02e22) {
                if (uVar2 == 0x77f02e21) {
LAB_4fc23868:
                  iVar6 = 0;
                  iVar13 = 2;
                  goto LAB_4fc2389f;
                }
                if (uVar2 == 0x4e12224) {
                  iVar6 = BZ1Helper::GetNearestObject
                                    (local_58,pAVar12->AlignHandle,___real_42c80000,-1,0,false,1,
                                     SUB41(local_58,0),SUB41(local_58,0),3,"CLASS_ARTIFACT",
                                     (char *)local_58);
                  if (iVar6 != 0) {
                    iVar13 = 7;
                    goto LAB_4fc2389f;
                  }
                  iVar6 = 0xb;
                  pcVar8 = *(char **)pAVar12;
                  SetCommand((int)pcVar8,0xb,0,0,(char *)0x0,0);
                  PlayVOMsg(*(int *)((int)pAVar12 + 0x28),pcVar8,iVar6);
                }
                else {
                  if ((uVar2 == 0x7257e15) || (uVar2 == 0x219650cd)) goto LAB_4fc238eb;
                  if (uVar2 == 0x2418efcf) goto LAB_4fc23868;
                }
              }
              else if (((uVar2 == 0xc9cd7077) || (uVar2 == 0xcd6780cd)) || (uVar2 == 0xf1656077)) {
LAB_4fc238eb:
                iVar6 = 0;
                iVar13 = 10;
                goto LAB_4fc2389f;
              }
            }
            else {
              fVar16 = GetHealth(pAVar12->AlignHandle);
              local_64 = (double)fVar16;
              fVar16 = GetAmmo(pAVar12->AlignHandle);
              if (fVar16 < (float)local_64) {
                iVar6 = 0;
                iVar13 = 0xd;
              }
              else {
                iVar6 = 0;
                iVar13 = 0xc;
              }
LAB_4fc2389f:
              SetCommand(pAVar12->AlignHandle,iVar13,0,iVar6,(char *)0x0,0);
            }
          }
        }
        else {
          if ((iVar6 == *(int *)((int)local_58->teamInfo + iVar13 + 8)) ||
             (iVar6 == pAVar12->AlignHandle)) {
            iVar6 = 0;
            iVar13 = 0;
            goto LAB_4fc2389f;
          }
          iVar17 = pAVar12->AlignHandle;
          SetAsUser(iVar17,*(int *)((int)pAVar12 + 0x28));
          pcVar8 = GetPilotConfig(iVar17);
          SetPilotClass(pAVar12->AlignHandle,pcVar8);
          *(undefined1 *)((int)local_58->teamInfo + iVar13 + 0x113) = 1;
          bVar4 = IsPerson(iVar6);
          if (bVar4) {
            RemoveObject(iVar6);
          }
          else {
            AddPilotByHandle(iVar6);
            SetBestGroup(iVar6);
          }
        }
      }
      if (local_58[1].teamInfo[0].PilotWeapon[4][0x1c] != '\0') {
        if (((char)*(int *)((int)pAVar12 + 0x18) != '\0') && (*(int *)((int)pAVar12 + 0x24) < 1)) {
          iVar6 = *(int *)((int)pAVar12 + 0x28);
          GetLocalPlayerTeamNumber();
          bVar4 = TeamFilterCheck(iVar6,unaff_EDI,unaff_ESI);
          if (bVar4) {
            *(int *)((int)pAVar12 + 0x24) = BZ1Helper::m_GameTPS;
          }
        }
        *(int *)((int)pAVar12 + 0x24) = *(int *)((int)pAVar12 + 0x24) + -1;
      }
      if (0 < *(int *)((int)pAVar12 + 0x30)) {
        bVar4 = IsDeployed(pAVar12->AlignHandle);
        iVar13 = GetPlayerHandle();
        iVar6 = *(int *)((int)pAVar12 + 0x34);
        if (bVar4) {
          if (0 < iVar6) {
            fVar16 = (float)*(int *)((int)pAVar12 + 0x38) / (float)BZ1Helper::m_GameTPS +
                     *(float *)((int)pAVar12 + 0x40);
            local_5c = (AlignTerrainReplaceClass *)(int)fVar16;
            iVar6 = iVar6 - (int)local_5c;
            local_64 = (double)CONCAT44(local_64._4_4_,(float)(int)local_5c);
            *(float *)((int)pAVar12 + 0x40) = fVar16 - (float)(int)local_5c;
            if (iVar6 < 0) {
              iVar6 = 0;
            }
            else if (*(int *)((int)pAVar12 + 0x30) < iVar6) {
              iVar6 = *(int *)((int)pAVar12 + 0x30);
            }
            *(int *)((int)pAVar12 + 0x34) = iVar6;
          }
          if ((*(char *)((int)pAVar12 + 0x19) != '\0') || (iVar6 == 0)) {
            bVar4 = IsPlayer(pAVar12->AlignHandle);
            if (bVar4) {
              Deploy(pAVar12->AlignHandle);
            }
            else {
              SetCommand(pAVar12->AlignHandle,0x30,0,0,(char *)0x0,0);
            }
            if (pAVar12->AlignHandle != iVar13) goto LAB_4fc23a53;
            pcVar8 = local_44;
            pcVar18 = (char *)0x0;
            memset(pcVar8,0,0x40);
            GetODFString(0x4fc582f0,(char *)0x40,local_44,0,pcVar8,pcVar18);
            if ((local_44[0] != '\0') && (bVar4 = DoesFileExist(local_44), bVar4)) {
              StartAudio2D(local_44,__real_bf800000,0.0,___real_462c4400,false,false);
            }
          }
        }
        else {
          iVar17 = *(int *)((int)pAVar12 + 0x30);
          if (iVar6 < iVar17) {
            fVar16 = (float)*(int *)((int)pAVar12 + 0x3c) / (float)BZ1Helper::m_GameTPS +
                     *(float *)((int)pAVar12 + 0x40);
            iVar9 = (int)fVar16;
            iVar6 = iVar6 + iVar9;
            fVar3 = (float)iVar9;
            local_64 = (double)CONCAT44(local_64._4_4_,fVar3);
            *(float *)((int)pAVar12 + 0x40) = fVar16 - fVar3;
            if (iVar6 < 0) {
              iVar6 = 0;
            }
            else if (iVar17 < iVar6) {
              iVar6 = iVar17;
            }
            *(int *)((int)pAVar12 + 0x34) = iVar6;
          }
          if (*(char *)((int)pAVar12 + 0x19) == '\0') {
            if (iVar6 < iVar17) {
              *(undefined1 *)((int)pAVar12 + 0x19) = 1;
            }
            else {
LAB_4fc23a28:
              *(undefined1 *)((int)pAVar12 + 0x19) = 0;
            }
          }
          else if (iVar17 <= iVar6) goto LAB_4fc23a28;
        }
        if (pAVar12->AlignHandle == iVar13) {
          local_64 = (double)CONCAT44(local_64._4_4_,(float)*(int *)((int)pAVar12 + 0x30));
          BZ1Helper::CloakGauge =
               (float)*(int *)((int)pAVar12 + 0x34) / (float)*(int *)((int)pAVar12 + 0x30);
          BZ1Helper::CloakGaugeSet = true;
        }
      }
LAB_4fc23a53:
      *(AiCommand *)((int)pAVar12 + 0x10) = local_54;
      local_5c = (AlignTerrainReplaceClass *)((int)pAVar12 + 0x54);
    } while (local_5c != (AlignTerrainReplaceClass *)*(int **)(iVar10 + 4));
  }
  return;
}

