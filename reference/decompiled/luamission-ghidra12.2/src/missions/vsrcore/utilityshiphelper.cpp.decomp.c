// Reconstructed by Ghidra from LuaMission.dll + LuaMission.pdb
// Original source file: /e:/github/vsr_dll_source/missions/vsrcore/utilityshiphelper.cpp
// Functions are ordered by original source line. This is decompiler
// output, not the author's source: names/types come from the PDB,
// local variable names and control flow are reconstructed.


// ---------------------------------------------------------------------
// `dynamic_initializer_for_'TempUtilityShipBuffer''  @ 4fc0146d  lines 7-7


void __cdecl _dynamic_initializer_for__TempUtilityShipBuffer__(void)

{
  atexit(_dynamic_atexit_destructor_for__TempUtilityShipBuffer__);
  return;
}


// ---------------------------------------------------------------------
// UtilityShipHelper::PostLoad  @ 4fc28f0c  lines 43-66


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
// UtilityShipHelper::AddUtilityShipObject  @ 4fc28fa7  lines 84-200


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
    uVar10 = 0xe8;
    pcVar9 = "ServiceTruck";
    GetODFBool("ServiceTruck","ServiceAllies",pbVar6 + 5,(char *)0x0,unaff_EBX,(bool)unaff_DI);
    uVar8 = 8;
    pcVar7 = "ServiceTruck";
    GetODFBool("ServiceTruck","ServiceSTs",(char *)((int)&local_8 + 3),(char *)0x0,(bool *)pcVar9,
               (bool)uVar10);
    uVar10 = 0x14;
    pcVar9 = "ServiceTruck";
    GetODFBool("ServiceTruck","serviceCraft",(char *)&local_4,(char *)0x1,(bool *)pcVar7,(bool)uVar8
              );
    GetODFBool("ServiceTruck","serviceBuildings",(char *)((int)&local_4 + 1),(char *)0x1,
               (bool *)pcVar9,(bool)uVar10);
    uVar10 = 0x38;
    pcVar7 = "ServiceTruck";
    GetODFBool("ServiceTruck","servicePilots",(char *)((int)&local_4 + 2),(char *)0x0,unaff_EBX,
               (bool)unaff_DI);
    pcVar9 = "ServiceTruck";
LAB_4fc29298:
    GetODFBool(pcVar9,"serviceOther",(char *)((int)&local_4 + 3),(char *)0x0,(bool *)pcVar7,
               (bool)uVar10);
LAB_4fc292a4:
    if ((char)local_8 == '\0') goto LAB_4fc292af;
  }
  else {
    if (param_4 == 0x33a01170) {
      iVar3 = GetODFBool("ScavengerClass","doDrop",pbVar6 + 4,(char *)0x0,unaff_EBX,(bool)unaff_DI);
      if (iVar3 != 0) {
        uVar8 = 0xbc;
        pcVar9 = "ScavengerClass";
        GetODFBool("ScavengerClass","doDropRecycler",(char *)&local_8,(char *)0x1,unaff_EBX,
                   (bool)unaff_DI);
        uVar10 = 0xcc;
        pcVar7 = "ScavengerClass";
        GetODFBool("ScavengerClass","doDropExtractor",(char *)((int)&local_8 + 1),(char *)0x1,
                   (bool *)pcVar9,(bool)uVar8);
        pcVar9 = "ScavengerClass";
LAB_4fc291f3:
        GetODFBool(pcVar9,"doDropSilo",(char *)((int)&local_8 + 2),(char *)0x1,(bool *)pcVar7,
                   (bool)uVar10);
      }
      goto LAB_4fc292a4;
    }
    if (param_4 == 0x5cfae8c8) {
      iVar3 = GetODFBool("ScavengerHClass","doDrop",pbVar6 + 4,(char *)0x0,unaff_EBX,(bool)unaff_DI)
      ;
      if (iVar3 != 0) {
        uVar8 = 0xbc;
        pcVar9 = "ScavengerHClass";
        GetODFBool("ScavengerHClass","doDropRecycler",(char *)&local_8,(char *)0x1,unaff_EBX,
                   (bool)unaff_DI);
        uVar10 = 0xcc;
        pcVar7 = "ScavengerHClass";
        GetODFBool("ScavengerHClass","doDropExtractor",(char *)((int)&local_8 + 1),(char *)0x1,
                   (bool *)pcVar9,(bool)uVar8);
        pcVar9 = "ScavengerHClass";
        goto LAB_4fc291f3;
      }
      goto LAB_4fc292a4;
    }
    if (param_4 == 0x7b3b7981) {
      uVar10 = 0xe8;
      pcVar9 = "ServiceTruckH";
      GetODFBool("ServiceTruckH","ServiceAllies",pbVar6 + 5,(char *)0x0,unaff_EBX,(bool)unaff_DI);
      uVar8 = 8;
      pcVar7 = "ServiceTruckH";
      GetODFBool("ServiceTruckH","ServiceSTs",(char *)((int)&local_8 + 3),(char *)0x0,(bool *)pcVar9
                 ,(bool)uVar10);
      uVar10 = 0x14;
      pcVar9 = "ServiceTruckH";
      GetODFBool("ServiceTruckH","serviceCraft",(char *)&local_4,(char *)0x1,(bool *)pcVar7,
                 (bool)uVar8);
      GetODFBool("ServiceTruckH","serviceBuildings",(char *)((int)&local_4 + 1),(char *)0x1,
                 (bool *)pcVar9,(bool)uVar10);
      uVar10 = 0x38;
      pcVar7 = "ServiceTruckH";
      GetODFBool("ServiceTruckH","servicePilots",(char *)((int)&local_4 + 2),(char *)0x0,unaff_EBX,
                 (bool)unaff_DI);
      pcVar9 = "ServiceTruckH";
      goto LAB_4fc29298;
    }
  }
  *(uint *)(pbVar6 + 0x18) = *(uint *)(pbVar6 + 0x18) | 1;
LAB_4fc292af:
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
// UtilityShipHelper::Execute  @ 4fc29390  lines 203-270


void __thiscall UtilityShipHelper::Execute(UtilityShipHelper *this,BZ1Helper *param_1)

{
  AlignTerrainReplaceClass *pAVar1;
  AlignTerrainReplaceClass *pAVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  long lVar6;
  AiCommand AVar7;
  int iVar8;
  int iVar9;
  AlignTerrainReplaceClass *pAVar10;
  int unaff_ESI;
  AlignTerrainReplaceClass *pAVar11;
  float *pfVar12;
  int *piVar13;
  char *unaff_EDI;
  AlignTerrainReplaceClass *pAVar14;
  int *piVar15;
  
  pAVar1 = *(AlignTerrainReplaceClass **)&(this->UtilityShipList).field_0x4;
  pAVar10 = *(AlignTerrainReplaceClass **)&this->UtilityShipList;
  while ((pAVar10 != pAVar1 && (bVar3 = BZ1Helper::ShouldRemoveAlignTerrainReplace(pAVar10), !bVar3)
         )) {
    pAVar10 = (AlignTerrainReplaceClass *)&pAVar10[2].NormalVec.z;
  }
  pAVar11 = pAVar10;
  if (pAVar10 != pAVar1) {
    while (pAVar11 = (AlignTerrainReplaceClass *)&pAVar11[2].NormalVec.z, pAVar11 != pAVar1) {
      bVar3 = BZ1Helper::ShouldRemoveAlignTerrainReplace(pAVar11);
      if (!bVar3) {
        pAVar2 = pAVar10 + 2;
        pfVar12 = (float *)pAVar11;
        pAVar14 = pAVar10;
        for (iVar9 = 0xb; pAVar10 = (AlignTerrainReplaceClass *)&(pAVar2->NormalVec).z, iVar9 != 0;
            iVar9 = iVar9 + -1) {
          pAVar14->AlignHandle = (int)*pfVar12;
          pfVar12 = pfVar12 + 1;
          pAVar14 = (AlignTerrainReplaceClass *)&pAVar14->NormalVec;
        }
      }
    }
  }
  piVar15 = *(int **)&(this->UtilityShipList).field_0x4;
  if (pAVar10 != pAVar1) {
    memmove(pAVar10,pAVar1,(int)piVar15 - (int)pAVar1);
    piVar15 = (int *)(((int)piVar15 - (int)pAVar1) + (int)pAVar10);
    *(int **)&(this->UtilityShipList).field_0x4 = piVar15;
  }
  piVar13 = *(int **)&this->UtilityShipList;
  if (piVar13 != piVar15) {
    do {
      iVar9 = GetTeamNum(*piVar13);
      piVar13[3] = iVar9;
      iVar9 = iVar9 * 0xa14;
      if ((piVar13[2] == 0x5cfae8c8) || (piVar13[2] == 0x33a01170)) {
        iVar4 = GetScavengerCurScrap(*piVar13);
        if ((char)piVar13[1] != '\0') {
          iVar5 = GetScavengerMaxScrap(*piVar13);
          if ((iVar5 != 0) && (lVar6 = GetMaxAmmo(*piVar13), lVar6 == iVar5)) {
            SetAmmo((int)((float)iVar4 / (float)iVar5),(float)unaff_EDI);
          }
          AVar7 = GetCurrentCommand(*piVar13);
          if ((AVar7 == CMD_SCAVENGE) && (iVar5 == iVar4)) {
            bVar3 = false;
            iVar5 = GetCommanderTeam(piVar13[3]);
            iVar5 = iVar5 * 0xa14;
            if (((((*(byte *)(piVar13 + 6) & 1) != 0) &&
                 (0 < *(int *)((int)param_1->teamInfo + iVar5 + 0xdc))) ||
                (((*(byte *)(piVar13 + 6) & 2) != 0 &&
                 (0 < *(int *)((int)param_1->teamInfo + iVar5 + 0xe0))))) ||
               (((*(byte *)(piVar13 + 6) & 4) != 0 &&
                (0 < *(int *)((int)param_1->teamInfo + iVar5 + 0xe4))))) {
              bVar3 = true;
            }
            if (*(char *)((int)param_1->teamInfo + iVar9 + 0x10c) == '\0') {
              if (!bVar3) {
                PlayVOMsg(piVar13[3],unaff_EDI,unaff_ESI);
                *(undefined1 *)((int)param_1->teamInfo + iVar9 + 0x10c) = 1;
              }
            }
            else if (bVar3) {
              *(undefined1 *)((int)param_1->teamInfo + iVar9 + 0x10c) = 0;
            }
          }
        }
        bVar3 = IsNetworkOn();
        if (bVar3) {
          iVar9 = piVar13[4];
          if (iVar4 < iVar9) {
            iVar5 = *(int *)(param_1[1].teamInfo[0].PilotWeapon[2] + 0x3b);
            iVar8 = GetCommanderTeam(piVar13[3]);
            (*misnImport.AddScrap)(iVar8,(iVar9 - iVar4) * iVar5);
          }
          piVar13[4] = iVar4;
        }
      }
      piVar13 = piVar13 + 0xb;
    } while (piVar13 != *(int **)&(this->UtilityShipList).field_0x4);
  }
  return;
}


// ---------------------------------------------------------------------
// UtilityShipHelper::GetEscortTarget  @ 4fc2958c  lines 273-299


int __thiscall UtilityShipHelper::GetEscortTarget(UtilityShipHelper *this,int param_1,int param_2)

{
  int iVar1;
  bool bVar2;
  int unaff_ESI;
  int iVar3;
  int *piVar4;
  int unaff_EDI;
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
  piVar4 = *(int **)&this->UtilityShipList;
  if (piVar4 != *(int **)&(this->UtilityShipList).field_0x4) {
    do {
      if (((iVar1 < 0) || (bVar2 = TeamFilterCheck(iVar1,unaff_EDI,unaff_ESI), bVar2)) &&
         ((param_1 = (int)((float)param_1 - (float)piVar4[5]), (float)param_1 <= 0.0 ||
          (piVar4 == *(int **)&(this->UtilityShipList).field_0x4)))) {
        return *piVar4;
      }
      piVar4 = piVar4 + 0xb;
    } while (piVar4 != *(int **)&(this->UtilityShipList).field_0x4);
  }
  return 0;
}


// ---------------------------------------------------------------------
// UtilityShipHelper::FindServiceTruck  @ 4fc2963b  lines 302-366


int __thiscall
UtilityShipHelper::FindServiceTruck
          (UtilityShipHelper *this,int param_1,int param_2,bool param_3,float param_4,int param_5)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  int unaff_ESI;
  int *piVar4;
  int unaff_EDI;
  float fVar5;
  Vector local_c;
  
  iVar1 = param_1;
  iVar3 = param_2;
  if (param_2 == -1) {
    iVar3 = GetTeamNum(param_1);
  }
  param_1 = 0;
  GetPosition(iVar1,&local_c);
  if (0.0 < param_4) {
    param_4 = param_4 * param_4;
  }
  else {
    param_4 = 3.4028235e+38;
  }
  piVar4 = *(int **)&this->UtilityShipList;
  do {
    if (piVar4 == *(int **)&(this->UtilityShipList).field_0x4) {
      return param_1;
    }
    bVar2 = IsServiceTruck(unaff_EDI,unaff_ESI);
    if (bVar2) {
      bVar2 = IsTeamAllied(iVar3,piVar4[3]);
      if ((bVar2) && ((*(char *)((int)piVar4 + 5) != '\0' || (iVar3 == param_2)))) {
        if (!param_3) {
          bVar2 = IsIdle(*piVar4);
          if (!bVar2) goto LAB_4fc2978a;
        }
        if (*(char *)((int)piVar4 + 6) != '\0') {
          bVar2 = IsServiceTruck(unaff_EDI,unaff_ESI);
          if (bVar2) {
            bVar2 = (*(byte *)(piVar4 + 7) & 1) == 0;
          }
          else {
            bVar2 = IsCraftButNotPerson(iVar1);
            if (bVar2) {
              bVar2 = (*(byte *)(piVar4 + 7) & 2) == 0;
            }
            else {
              bVar2 = IsBuilding(iVar1);
              if (bVar2) {
                bVar2 = (*(byte *)(piVar4 + 7) & 4) == 0;
              }
              else {
                bVar2 = IsPerson(iVar1);
                if (bVar2) {
                  bVar2 = (*(byte *)(piVar4 + 7) & 8) == 0;
                }
                else {
                  bVar2 = (*(byte *)(piVar4 + 7) & 0x10) == 0;
                }
              }
            }
          }
          if (!bVar2) {
            fVar5 = (local_c.x - (float)piVar4[8]) * (local_c.x - (float)piVar4[8]) +
                    (local_c.y - (float)piVar4[9]) * (local_c.y - (float)piVar4[9]) +
                    (local_c.z - (float)piVar4[10]) * (local_c.z - (float)piVar4[10]);
            if (fVar5 < param_4) {
              param_1 = *piVar4;
              param_4 = fVar5;
            }
          }
        }
      }
    }
LAB_4fc2978a:
    piVar4 = piVar4 + 0xb;
  } while( true );
}

