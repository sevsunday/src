// Reconstructed by Ghidra from Strategy02.dll + Strategy02.pdb
// Original source file: /e:/github/vsr_dll_source/missions/vsrcore/utilityshiphelper.cpp
// Functions are ordered by original source line. This is decompiler
// output, not the author's source: names/types come from the PDB,
// local variable names and control flow are reconstructed.


// ---------------------------------------------------------------------
// `dynamic_initializer_for_'TempUtilityShipBuffer''  @ 4fc013fe  lines 7-7


void __cdecl _dynamic_initializer_for__TempUtilityShipBuffer__(void)

{
  atexit(_dynamic_atexit_destructor_for__TempUtilityShipBuffer__);
  return;
}


// ---------------------------------------------------------------------
// UtilityShipHelper::PostLoad  @ 4fc1500c  lines 43-66


bool __thiscall UtilityShipHelper::PostLoad(UtilityShipHelper *this,bool param_1)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  UtilityShipClass *unaff_ESI;
  int *piVar5;
  UtilityShipClass *unaff_EDI;
  
  piVar5 = *(int **)&this->UtilityShipList;
  piVar2 = *(int **)&(this->UtilityShipList).field_0x4;
  if (piVar5 != piVar2) {
    do {
      ConvertHandles(piVar5,1);
      piVar2 = *(int **)&(this->UtilityShipList).field_0x4;
      piVar5 = piVar5 + 0xb;
    } while (piVar5 != piVar2);
    piVar5 = *(int **)&this->UtilityShipList;
  }
  iVar3 = ((int)piVar2 - (int)piVar5) / 0x2c;
  if ((int)(TempUtilityShipBuffer._4_4_ - TempUtilityShipBuffer._0_4_) / 0x2c == iVar3) {
    iVar4 = 0;
    if (0 < iVar3) {
      do {
        bVar1 = ::operator==(unaff_EDI,unaff_ESI);
        if (!bVar1) {
          FormatLogMessage("UtilityShipList Index Mismatch: %d");
          return true;
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < (*(int *)&(this->UtilityShipList).field_0x4 - *(int *)&this->UtilityShipList)
                       / 0x2c);
    }
  }
  else {
    FormatLogMessage("UtilityShipList Size Mismatch! Old: %d New: %d");
  }
  return true;
}


// ---------------------------------------------------------------------
// UtilityShipHelper::AddUtilityShipObject  @ 4fc150a7  lines 84-200


void __thiscall
UtilityShipHelper::AddUtilityShipObject
          (UtilityShipHelper *this,int param_1,int param_2,Vector param_3,int param_4,int param_5,
          char *param_6,char *param_7,int param_8)

{
  int *piVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  bool *unaff_EBX;
  bool *pbVar6;
  undefined1 unaff_DI;
  char *pcVar7;
  undefined1 uVar8;
  char *pcVar9;
  undefined1 uVar10;
  bool *pbVar11;
  undefined4 local_8;
  undefined4 local_4;
  
  piVar1 = *(int **)&(this->UtilityShipList).field_0x4;
  for (piVar5 = *(int **)&this->UtilityShipList; piVar5 != piVar1; piVar5 = piVar5 + 0xb) {
    if (*piVar5 == param_1) {
      return;
    }
  }
  local_8 = this;
  local_4 = this;
  std::
  vector<UtilityShipHelper::UtilityShipClass,std::allocator<UtilityShipHelper::UtilityShipClass>_>::
  _Resize<<lambda_c8a4f4cad98f6de524d7658fab4f9ded>_>
            (&this->UtilityShipList,((int)piVar1 - *(int *)&this->UtilityShipList) / 0x2c + 1,
             (<lambda_c8a4f4cad98f6de524d7658fab4f9ded>)this);
  bVar2 = false;
  pbVar6 = (bool *)(*(int *)&this->UtilityShipList + -0x2c +
                   ((*(int *)&(this->UtilityShipList).field_0x4 - *(int *)&this->UtilityShipList) /
                   0x2c) * 0x2c);
  pbVar11 = pbVar6;
  memset(pbVar6,0,0x2c);
  *(int *)pbVar6 = param_1;
  *(int *)(pbVar6 + 0xc) = param_2;
  *(int *)(pbVar6 + 8) = param_4;
  *(float *)(pbVar6 + 0x20) = param_3.x;
  *(float *)(pbVar6 + 0x24) = param_3.y;
  *(float *)(pbVar6 + 0x28) = param_3.z;
  GetODFBool("CraftClass","DoDLLDispatch",pbVar6 + 6,(char *)0x1,pbVar11,bVar2);
  local_8 = (UtilityShipHelper *)0x10101;
  local_4 = (UtilityShipHelper *)0x101;
  if (param_4 == 0x28e4d573) {
    uVar10 = 0x58;
    pcVar9 = "ServiceTruck";
    GetODFBool("ServiceTruck","ServiceAllies",pbVar6 + 5,(char *)0x0,unaff_EBX,(bool)unaff_DI);
    uVar8 = 0x78;
    pcVar7 = "ServiceTruck";
    GetODFBool("ServiceTruck","ServiceSTs",(char *)((int)&local_8 + 3),(char *)0x0,(bool *)pcVar9,
               (bool)uVar10);
    uVar10 = 0x84;
    pcVar9 = "ServiceTruck";
    GetODFBool("ServiceTruck","serviceCraft",(char *)&local_4,(char *)0x1,(bool *)pcVar7,(bool)uVar8
              );
    GetODFBool("ServiceTruck","serviceBuildings",(char *)((int)&local_4 + 1),(char *)0x1,
               (bool *)pcVar9,(bool)uVar10);
    uVar10 = 0xa8;
    pcVar7 = "ServiceTruck";
    GetODFBool("ServiceTruck","servicePilots",(char *)((int)&local_4 + 2),(char *)0x0,unaff_EBX,
               (bool)unaff_DI);
    pcVar9 = "ServiceTruck";
LAB_4fc15398:
    GetODFBool(pcVar9,"serviceOther",(char *)((int)&local_4 + 3),(char *)0x0,(bool *)pcVar7,
               (bool)uVar10);
LAB_4fc153a4:
    if ((char)local_8 == '\0') goto LAB_4fc153af;
  }
  else {
    if (param_4 == 0x33a01170) {
      iVar3 = GetODFBool("ScavengerClass","doDrop",pbVar6 + 4,(char *)0x0,unaff_EBX,(bool)unaff_DI);
      if (iVar3 != 0) {
        uVar8 = 0x2c;
        pcVar9 = "ScavengerClass";
        GetODFBool("ScavengerClass","doDropRecycler",(char *)&local_8,(char *)0x1,unaff_EBX,
                   (bool)unaff_DI);
        uVar10 = 0x3c;
        pcVar7 = "ScavengerClass";
        GetODFBool("ScavengerClass","doDropExtractor",(char *)((int)&local_8 + 1),(char *)0x1,
                   (bool *)pcVar9,(bool)uVar8);
        pcVar9 = "ScavengerClass";
LAB_4fc152f3:
        GetODFBool(pcVar9,"doDropSilo",(char *)((int)&local_8 + 2),(char *)0x1,(bool *)pcVar7,
                   (bool)uVar10);
      }
      goto LAB_4fc153a4;
    }
    if (param_4 == 0x5cfae8c8) {
      iVar3 = GetODFBool("ScavengerHClass","doDrop",pbVar6 + 4,(char *)0x0,unaff_EBX,(bool)unaff_DI)
      ;
      if (iVar3 != 0) {
        uVar8 = 0x2c;
        pcVar9 = "ScavengerHClass";
        GetODFBool("ScavengerHClass","doDropRecycler",(char *)&local_8,(char *)0x1,unaff_EBX,
                   (bool)unaff_DI);
        uVar10 = 0x3c;
        pcVar7 = "ScavengerHClass";
        GetODFBool("ScavengerHClass","doDropExtractor",(char *)((int)&local_8 + 1),(char *)0x1,
                   (bool *)pcVar9,(bool)uVar8);
        pcVar9 = "ScavengerHClass";
        goto LAB_4fc152f3;
      }
      goto LAB_4fc153a4;
    }
    if (param_4 == 0x7b3b7981) {
      uVar10 = 0x58;
      pcVar9 = "ServiceTruckH";
      GetODFBool("ServiceTruckH","ServiceAllies",pbVar6 + 5,(char *)0x0,unaff_EBX,(bool)unaff_DI);
      uVar8 = 0x78;
      pcVar7 = "ServiceTruckH";
      GetODFBool("ServiceTruckH","ServiceSTs",(char *)((int)&local_8 + 3),(char *)0x0,(bool *)pcVar9
                 ,(bool)uVar10);
      uVar10 = 0x84;
      pcVar9 = "ServiceTruckH";
      GetODFBool("ServiceTruckH","serviceCraft",(char *)&local_4,(char *)0x1,(bool *)pcVar7,
                 (bool)uVar8);
      GetODFBool("ServiceTruckH","serviceBuildings",(char *)((int)&local_4 + 1),(char *)0x1,
                 (bool *)pcVar9,(bool)uVar10);
      uVar10 = 0xa8;
      pcVar7 = "ServiceTruckH";
      GetODFBool("ServiceTruckH","servicePilots",(char *)((int)&local_4 + 2),(char *)0x0,unaff_EBX,
                 (bool)unaff_DI);
      pcVar9 = "ServiceTruckH";
      goto LAB_4fc15398;
    }
  }
  *(uint *)(pbVar6 + 0x18) = *(uint *)(pbVar6 + 0x18) | 1;
LAB_4fc153af:
  if (local_8._1_1_ != '\0') {
    *(uint *)(pbVar6 + 0x18) = *(uint *)(pbVar6 + 0x18) | 2;
  }
  if (local_8._2_1_ != '\0') {
    *(uint *)(pbVar6 + 0x18) = *(uint *)(pbVar6 + 0x18) | 4;
  }
  pbVar6[0x1c] = false;
  pbVar6[0x1d] = false;
  pbVar6[0x1e] = false;
  pbVar6[0x1f] = false;
  uVar4 = 0;
  if (local_8._3_1_ != '\0') {
    pbVar6[0x1c] = true;
    pbVar6[0x1d] = false;
    pbVar6[0x1e] = false;
    pbVar6[0x1f] = false;
    uVar4 = 2;
  }
  if ((char)local_4 != '\0') {
    uVar4 = uVar4 | 4;
    *(uint *)(pbVar6 + 0x1c) = uVar4;
  }
  if (local_4._1_1_ != '\0') {
    uVar4 = uVar4 | 0x10;
    *(uint *)(pbVar6 + 0x1c) = uVar4;
  }
  if (local_4._2_1_ != '\0') {
    uVar4 = uVar4 | 0x100;
    *(uint *)(pbVar6 + 0x1c) = uVar4;
  }
  if (local_4._3_1_ != '\0') {
    *(uint *)(pbVar6 + 0x1c) = uVar4 | 0x10000;
  }
  if (param_8 == 0) {
    bVar2 = IsProducer((int)unaff_EBX);
    if (bVar2) {
      pbVar6[0x14] = true;
      pbVar6[0x15] = false;
      pbVar6[0x16] = false;
      pbVar6[0x17] = false;
    }
    else if ((param_4 == 0x5cfae8c8) || (param_4 == 0x33a01170)) {
      pbVar6[0x14] = true;
      pbVar6[0x15] = false;
      pbVar6[0x16] = false;
      pbVar6[0x17] = false;
    }
    else if ((((param_4 == 0x32493554) || (param_4 == 0x4e12224)) || (param_5 == 0x326aa115)) ||
            (((param_4 == 0xda4acce || (param_4 == 0x7b3b7981)) || (param_4 == 0x28e4d573)))) {
      pbVar6[0x14] = true;
      pbVar6[0x15] = false;
      pbVar6[0x16] = false;
      pbVar6[0x17] = false;
    }
    else {
      pbVar6[0x14] = false;
      pbVar6[0x15] = false;
      pbVar6[0x16] = false;
      pbVar6[0x17] = false;
    }
  }
  else {
    *(int *)(pbVar6 + 0x14) = param_8;
  }
  return;
}


// ---------------------------------------------------------------------
// UtilityShipHelper::Execute  @ 4fc15490  lines 203-270


void __thiscall UtilityShipHelper::Execute(UtilityShipHelper *this,BZ1Helper *param_1)

{
  AlignTerrainReplaceClass *pAVar1;
  bool bVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  long lVar6;
  AiCommand AVar7;
  int iVar8;
  int iVar9;
  AlignTerrainReplaceClass *pAVar10;
  AlignTerrainReplaceClass *pAVar11;
  int unaff_ESI;
  float *pfVar12;
  char *unaff_EDI;
  AlignTerrainReplaceClass *pAVar13;
  size_t sVar14;
  int *local_1c;
  
  pAVar1 = *(AlignTerrainReplaceClass **)&(this->UtilityShipList).field_0x4;
  pAVar10 = *(AlignTerrainReplaceClass **)&this->UtilityShipList;
  while ((pAVar10 != pAVar1 && (bVar2 = BZ1Helper::ShouldRemoveAlignTerrainReplace(pAVar10), !bVar2)
         )) {
    pAVar10 = (AlignTerrainReplaceClass *)&pAVar10[2].NormalVec.z;
  }
  pAVar11 = pAVar10;
  if (pAVar10 != pAVar1) {
    while (pAVar11 = (AlignTerrainReplaceClass *)&pAVar11[2].NormalVec.z, pAVar11 != pAVar1) {
      bVar2 = BZ1Helper::ShouldRemoveAlignTerrainReplace(pAVar11);
      if (!bVar2) {
        pfVar12 = (float *)pAVar11;
        pAVar13 = pAVar10;
        for (iVar9 = 0xb; iVar9 != 0; iVar9 = iVar9 + -1) {
          pAVar13->AlignHandle = (int)*pfVar12;
          pfVar12 = pfVar12 + 1;
          pAVar13 = (AlignTerrainReplaceClass *)&pAVar13->NormalVec;
        }
        pAVar10 = (AlignTerrainReplaceClass *)&pAVar10[2].NormalVec.z;
      }
    }
    if (pAVar10 != pAVar1) {
      sVar14 = *(int *)&(this->UtilityShipList).field_0x4 - (int)pAVar1;
      memmove(pAVar10,pAVar1,sVar14);
      piVar3 = (int *)(sVar14 + (int)pAVar10);
      *(int **)&(this->UtilityShipList).field_0x4 = piVar3;
      goto LAB_4fc15511;
    }
  }
  piVar3 = *(int **)&(this->UtilityShipList).field_0x4;
LAB_4fc15511:
  local_1c = *(int **)&this->UtilityShipList;
  if (local_1c != piVar3) {
    do {
      iVar9 = GetTeamNum(*local_1c);
      piVar3 = local_1c + 3;
      *piVar3 = iVar9;
      iVar9 = iVar9 * 0xa14;
      if ((local_1c[2] == 0x5cfae8c8) || (local_1c[2] == 0x33a01170)) {
        iVar4 = GetScavengerCurScrap(*local_1c);
        if ((char)local_1c[1] != '\0') {
          iVar5 = GetScavengerMaxScrap(*local_1c);
          if ((iVar5 != 0) && (lVar6 = GetMaxAmmo(*local_1c), lVar6 == iVar5)) {
            SetAmmo((int)((float)iVar4 / (float)iVar5),(float)unaff_EDI);
          }
          AVar7 = GetCurrentCommand(*local_1c);
          if ((AVar7 == CMD_SCAVENGE) && (iVar5 == iVar4)) {
            iVar5 = GetCommanderTeam(*piVar3);
            iVar5 = iVar5 * 0xa14;
            if (((((*(byte *)(local_1c + 6) & 1) == 0) ||
                 (*(int *)((int)param_1->teamInfo + iVar5 + 0xdc) < 1)) &&
                (((*(byte *)(local_1c + 6) & 2) == 0 ||
                 (*(int *)((int)param_1->teamInfo + iVar5 + 0xe0) < 1)))) &&
               (((*(byte *)(local_1c + 6) & 4) == 0 ||
                (*(int *)((int)param_1->teamInfo + iVar5 + 0xe4) < 1)))) {
              bVar2 = false;
            }
            else {
              bVar2 = true;
            }
            if (*(char *)((int)param_1->teamInfo + iVar9 + 0x10c) == '\0') {
              if (!bVar2) {
                PlayVOMsg(*piVar3,unaff_EDI,unaff_ESI);
                *(undefined1 *)((int)param_1->teamInfo + iVar9 + 0x10c) = 1;
              }
            }
            else if (bVar2) {
              *(undefined1 *)((int)param_1->teamInfo + iVar9 + 0x10c) = 0;
            }
          }
        }
        bVar2 = IsNetworkOn();
        if (bVar2) {
          iVar9 = local_1c[4];
          if (iVar4 < iVar9) {
            iVar5 = *(int *)(param_1[1].teamInfo[0].PilotWeapon[2] + 0x3b);
            iVar8 = GetCommanderTeam(*piVar3);
            (*misnImport.AddScrap)(iVar8,(iVar9 - iVar4) * iVar5);
          }
          local_1c[4] = iVar4;
        }
      }
      local_1c = local_1c + 0xb;
    } while (local_1c != *(int **)&(this->UtilityShipList).field_0x4);
  }
  return;
}


// ---------------------------------------------------------------------
// UtilityShipHelper::GetEscortTarget  @ 4fc156ca  lines 273-299


int __thiscall UtilityShipHelper::GetEscortTarget(UtilityShipHelper *this,int param_1,int param_2)

{
  int iVar1;
  bool bVar2;
  int unaff_ESI;
  int iVar3;
  int unaff_EDI;
  int *local_10;
  float local_8;
  
  iVar1 = param_1;
  local_8 = 0.0;
  for (iVar3 = *(int *)&this->UtilityShipList; iVar3 != *(int *)&(this->UtilityShipList).field_0x4;
      iVar3 = iVar3 + 0x2c) {
    if ((param_1 < 0) || (bVar2 = TeamFilterCheck(param_1,unaff_EDI,unaff_ESI), bVar2)) {
      local_8 = (float)*(int *)(iVar3 + 0x14) + local_8;
    }
  }
  param_1 = (int)GetRandomFloat(0.0,local_8);
  local_10 = *(int **)&this->UtilityShipList;
  if (local_10 != *(int **)&(this->UtilityShipList).field_0x4) {
    do {
      if (((iVar1 < 0) || (bVar2 = TeamFilterCheck(iVar1,unaff_EDI,unaff_ESI), bVar2)) &&
         ((param_1 = (int)((float)param_1 - (float)local_10[5]), (float)param_1 <= 0.0 ||
          (local_10 == *(int **)&(this->UtilityShipList).field_0x4)))) {
        return *local_10;
      }
      local_10 = local_10 + 0xb;
    } while (local_10 != *(int **)&(this->UtilityShipList).field_0x4);
  }
  return 0;
}


// ---------------------------------------------------------------------
// UtilityShipHelper::FindServiceTruck  @ 4fc1579e  lines 302-366


int __thiscall
UtilityShipHelper::FindServiceTruck
          (UtilityShipHelper *this,int param_1,int param_2,bool param_3,float param_4,int param_5)

{
  bool bVar1;
  int iVar2;
  Vector *unaff_ESI;
  int *piVar3;
  Vector *unaff_EDI;
  float fVar4;
  int local_10;
  Vector local_c;
  
  iVar2 = param_2;
  if (param_2 == -1) {
    iVar2 = GetTeamNum(param_1);
  }
  local_10 = 0;
  GetPosition(param_1,&local_c);
  if (0.0 < param_4) {
    param_4 = param_4 * param_4;
  }
  else {
    param_4 = 3.4028235e+38;
  }
  piVar3 = *(int **)&this->UtilityShipList;
  do {
    if (piVar3 == *(int **)&(this->UtilityShipList).field_0x4) {
      return local_10;
    }
    bVar1 = IsServiceTruck((int)unaff_EDI,(int)unaff_ESI);
    if (bVar1) {
      bVar1 = IsTeamAllied(iVar2,piVar3[3]);
      if ((bVar1) && ((*(char *)((int)piVar3 + 5) != '\0' || (iVar2 == param_2)))) {
        if (!param_3) {
          bVar1 = IsIdle(*piVar3);
          if (!bVar1) goto LAB_4fc158c4;
        }
        if (*(char *)((int)piVar3 + 6) != '\0') {
          bVar1 = IsServiceTruck((int)unaff_EDI,(int)unaff_ESI);
          if (bVar1) {
            bVar1 = (*(byte *)(piVar3 + 7) & 1) == 0;
          }
          else {
            bVar1 = IsCraftButNotPerson(param_1);
            if (bVar1) {
              bVar1 = (*(byte *)(piVar3 + 7) & 2) == 0;
            }
            else {
              bVar1 = IsBuilding(param_1);
              if (bVar1) {
                bVar1 = (*(byte *)(piVar3 + 7) & 4) == 0;
              }
              else {
                bVar1 = IsPerson(param_1);
                if (bVar1) {
                  bVar1 = (*(byte *)(piVar3 + 7) & 8) == 0;
                }
                else {
                  bVar1 = (*(byte *)(piVar3 + 7) & 0x10) == 0;
                }
              }
            }
          }
          if (!bVar1) {
            fVar4 = GetDistance3DSquared(unaff_EDI,unaff_ESI);
            if (fVar4 < param_4) {
              local_10 = *piVar3;
              param_4 = fVar4;
            }
          }
        }
      }
    }
LAB_4fc158c4:
    piVar3 = piVar3 + 0xb;
  } while( true );
}

