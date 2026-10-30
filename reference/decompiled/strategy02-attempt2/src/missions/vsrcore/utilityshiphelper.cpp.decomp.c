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
  int *piVar5;
  
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
  iVar4 = (int)(TempUtilityShipBuffer._4_4_ - TempUtilityShipBuffer._0_4_) / 0x2c;
  if (iVar4 == iVar3) {
    iVar4 = 0;
    if (0 < iVar3) {
      iVar3 = 0;
      do {
        bVar1 = ::operator==((UtilityShipClass *)(TempUtilityShipBuffer._0_4_ + iVar3),
                             (UtilityShipClass *)((int)piVar5 + iVar3));
        if (!bVar1) {
          FormatLogMessage("UtilityShipList Index Mismatch: %d",iVar4);
          return true;
        }
        iVar4 = iVar4 + 1;
        piVar5 = *(int **)&this->UtilityShipList;
        iVar3 = iVar3 + 0x2c;
      } while (iVar4 < (*(int *)&(this->UtilityShipList).field_0x4 - (int)piVar5) / 0x2c);
    }
  }
  else {
    FormatLogMessage("UtilityShipList Size Mismatch! Old: %d New: %d",iVar4,iVar3);
  }
  return true;
}


// ---------------------------------------------------------------------
// UtilityShipHelper::AddUtilityShipObject  @ 4fc150a7  lines 84-200

void __thiscall
UtilityShipHelper::AddUtilityShipObject
          (UtilityShipHelper *this,int h,int Team,Vector Position,int ObjClassHash,int BZCClassHash,
          char *TempODF1,char *TempODF2,int TempEscortPriority)

{
  int *piVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  char *pcVar6;
  undefined4 local_8;
  undefined4 local_4;
  
  piVar1 = *(int **)&(this->UtilityShipList).field_0x4;
  for (piVar5 = *(int **)&this->UtilityShipList; piVar5 != piVar1; piVar5 = piVar5 + 0xb) {
    if (*piVar5 == h) {
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
  piVar5 = (int *)(*(int *)&this->UtilityShipList + -0x2c +
                  ((*(int *)&(this->UtilityShipList).field_0x4 - *(int *)&this->UtilityShipList) /
                  0x2c) * 0x2c);
  memset(piVar5,0,0x2c);
  *piVar5 = h;
  piVar5[3] = Team;
  piVar5[2] = ObjClassHash;
  piVar5[8] = (int)Position.x;
  piVar5[9] = (int)Position.y;
  piVar5[10] = (int)Position.z;
  GetODFBool(TempODF1,TempODF2,"CraftClass","DoDLLDispatch",(bool *)((int)piVar5 + 6),true);
  local_8 = (UtilityShipHelper *)0x10101;
  local_4 = (UtilityShipHelper *)0x101;
  if (ObjClassHash == 0x28e4d573) {
    GetODFBool(TempODF1,TempODF2,"ServiceTruck","ServiceAllies",(bool *)((int)piVar5 + 5),false);
    GetODFBool(TempODF1,TempODF2,"ServiceTruck","ServiceSTs",(bool *)((int)&local_8 + 3),false);
    GetODFBool(TempODF1,TempODF2,"ServiceTruck","serviceCraft",(bool *)&local_4,true);
    GetODFBool(TempODF1,TempODF2,"ServiceTruck","serviceBuildings",(bool *)((int)&local_4 + 1),true)
    ;
    GetODFBool(TempODF1,TempODF2,"ServiceTruck","servicePilots",(bool *)((int)&local_4 + 2),false);
    pcVar6 = "ServiceTruck";
LAB_4fc15398:
    GetODFBool(TempODF1,TempODF2,pcVar6,"serviceOther",(bool *)((int)&local_4 + 3),false);
LAB_4fc153a4:
    if (local_8._0_1_ == false) goto LAB_4fc153af;
  }
  else {
    if (ObjClassHash == 0x33a01170) {
      iVar3 = GetODFBool(TempODF1,TempODF2,"ScavengerClass","doDrop",(bool *)(piVar5 + 1),false);
      if (iVar3 != 0) {
        GetODFBool(TempODF1,TempODF2,"ScavengerClass","doDropRecycler",(bool *)&local_8,true);
        GetODFBool(TempODF1,TempODF2,"ScavengerClass","doDropExtractor",(bool *)((int)&local_8 + 1),
                   true);
        pcVar6 = "ScavengerClass";
LAB_4fc152f3:
        GetODFBool(TempODF1,TempODF2,pcVar6,"doDropSilo",(bool *)((int)&local_8 + 2),true);
      }
      goto LAB_4fc153a4;
    }
    if (ObjClassHash == 0x5cfae8c8) {
      iVar3 = GetODFBool(TempODF1,TempODF2,"ScavengerHClass","doDrop",(bool *)(piVar5 + 1),false);
      if (iVar3 != 0) {
        GetODFBool(TempODF1,TempODF2,"ScavengerHClass","doDropRecycler",(bool *)&local_8,true);
        GetODFBool(TempODF1,TempODF2,"ScavengerHClass","doDropExtractor",(bool *)((int)&local_8 + 1)
                   ,true);
        pcVar6 = "ScavengerHClass";
        goto LAB_4fc152f3;
      }
      goto LAB_4fc153a4;
    }
    if (ObjClassHash == 0x7b3b7981) {
      GetODFBool(TempODF1,TempODF2,"ServiceTruckH","ServiceAllies",(bool *)((int)piVar5 + 5),false);
      GetODFBool(TempODF1,TempODF2,"ServiceTruckH","ServiceSTs",(bool *)((int)&local_8 + 3),false);
      GetODFBool(TempODF1,TempODF2,"ServiceTruckH","serviceCraft",(bool *)&local_4,true);
      GetODFBool(TempODF1,TempODF2,"ServiceTruckH","serviceBuildings",(bool *)((int)&local_4 + 1),
                 true);
      GetODFBool(TempODF1,TempODF2,"ServiceTruckH","servicePilots",(bool *)((int)&local_4 + 2),false
                );
      pcVar6 = "ServiceTruckH";
      goto LAB_4fc15398;
    }
  }
  piVar5[6] = piVar5[6] | 1;
LAB_4fc153af:
  if (local_8._1_1_ != '\0') {
    piVar5[6] = piVar5[6] | 2;
  }
  if (local_8._2_1_ != '\0') {
    piVar5[6] = piVar5[6] | 4;
  }
  piVar5[7] = 0;
  uVar4 = 0;
  if (local_8._3_1_ != '\0') {
    piVar5[7] = 2;
    uVar4 = 2;
  }
  if (local_4._0_1_ != false) {
    uVar4 = uVar4 | 4;
    piVar5[7] = uVar4;
  }
  if (local_4._1_1_ != '\0') {
    uVar4 = uVar4 | 0x10;
    piVar5[7] = uVar4;
  }
  if (local_4._2_1_ != '\0') {
    uVar4 = uVar4 | 0x100;
    piVar5[7] = uVar4;
  }
  if (local_4._3_1_ != '\0') {
    piVar5[7] = uVar4 | 0x10000;
  }
  if (TempEscortPriority == 0) {
    bVar2 = IsProducer(h);
    if (bVar2) {
      piVar5[5] = 3;
    }
    else if ((ObjClassHash == 0x5cfae8c8) || (ObjClassHash == 0x33a01170)) {
      piVar5[5] = 2;
    }
    else if ((((ObjClassHash == 0x32493554) || (ObjClassHash == 0x4e12224)) ||
             (BZCClassHash == 0x326aa115)) ||
            (((ObjClassHash == 0xda4acce || (ObjClassHash == 0x7b3b7981)) ||
             (ObjClassHash == 0x28e4d573)))) {
      piVar5[5] = 1;
    }
    else {
      piVar5[5] = 0;
    }
  }
  else {
    piVar5[5] = TempEscortPriority;
  }
  return;
}


// ---------------------------------------------------------------------
// UtilityShipHelper::Execute  @ 4fc15490  lines 203-270

void __thiscall UtilityShipHelper::Execute(UtilityShipHelper *this,BZ1Helper *bz1Helper)

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
  AlignTerrainReplaceClass *entry;
  AlignTerrainReplaceClass *entry_00;
  float *pfVar10;
  int *piVar11;
  AlignTerrainReplaceClass *pAVar12;
  size_t sVar13;
  
  pAVar1 = *(AlignTerrainReplaceClass **)&(this->UtilityShipList).field_0x4;
  entry = *(AlignTerrainReplaceClass **)&this->UtilityShipList;
  while ((entry != pAVar1 && (bVar2 = BZ1Helper::ShouldRemoveAlignTerrainReplace(entry), !bVar2))) {
    entry = (AlignTerrainReplaceClass *)&entry[2].NormalVec.z;
  }
  entry_00 = entry;
  if (entry != pAVar1) {
    while (entry_00 = (AlignTerrainReplaceClass *)&entry_00[2].NormalVec.z, entry_00 != pAVar1) {
      bVar2 = BZ1Helper::ShouldRemoveAlignTerrainReplace(entry_00);
      if (!bVar2) {
        pfVar10 = (float *)entry_00;
        pAVar12 = entry;
        for (iVar9 = 0xb; iVar9 != 0; iVar9 = iVar9 + -1) {
          pAVar12->AlignHandle = (int)*pfVar10;
          pfVar10 = pfVar10 + 1;
          pAVar12 = (AlignTerrainReplaceClass *)&pAVar12->NormalVec;
        }
        entry = (AlignTerrainReplaceClass *)&entry[2].NormalVec.z;
      }
    }
    if (entry != pAVar1) {
      sVar13 = *(int *)&(this->UtilityShipList).field_0x4 - (int)pAVar1;
      memmove(entry,pAVar1,sVar13);
      piVar3 = (int *)(sVar13 + (int)entry);
      *(int **)&(this->UtilityShipList).field_0x4 = piVar3;
      goto LAB_4fc15511;
    }
  }
  piVar3 = *(int **)&(this->UtilityShipList).field_0x4;
LAB_4fc15511:
  piVar11 = *(int **)&this->UtilityShipList;
  if (piVar11 != piVar3) {
    do {
      iVar9 = GetTeamNum(*piVar11);
      piVar3 = piVar11 + 3;
      *piVar3 = iVar9;
      if ((piVar11[2] == 0x5cfae8c8) || (piVar11[2] == 0x33a01170)) {
        iVar4 = GetScavengerCurScrap(*piVar11);
        if ((char)piVar11[1] != '\0') {
          iVar5 = GetScavengerMaxScrap(*piVar11);
          if ((iVar5 != 0) && (lVar6 = GetMaxAmmo(*piVar11), lVar6 == iVar5)) {
            SetAmmo(*piVar11,(float)iVar4 / (float)iVar5);
          }
          AVar7 = GetCurrentCommand(*piVar11);
          if ((AVar7 == CMD_SCAVENGE) && (iVar5 == iVar4)) {
            iVar5 = GetCommanderTeam(*piVar3);
            if (((((*(byte *)(piVar11 + 6) & 1) == 0) ||
                 (bz1Helper->teamInfo[iVar5].DropoffRecylcers < 1)) &&
                (((*(byte *)(piVar11 + 6) & 2) == 0 ||
                 (bz1Helper->teamInfo[iVar5].DropoffExtractors < 1)))) &&
               (((*(byte *)(piVar11 + 6) & 4) == 0 || (bz1Helper->teamInfo[iVar5].DropoffSilos < 1))
               )) {
              bVar2 = false;
            }
            else {
              bVar2 = true;
            }
            if (bz1Helper->teamInfo[iVar9].PlayedScrapDropVO == false) {
              if (!bVar2) {
                PlayVOMsg(*piVar11,"user3Msg",*piVar3);
                bz1Helper->teamInfo[iVar9].PlayedScrapDropVO = true;
              }
            }
            else if (bVar2) {
              bz1Helper->teamInfo[iVar9].PlayedScrapDropVO = false;
            }
          }
        }
        bVar2 = IsNetworkOn();
        if (bVar2) {
          iVar9 = piVar11[4];
          if (iVar4 < iVar9) {
            iVar5 = bz1Helper->m_ScrapMultiplier;
            iVar8 = GetCommanderTeam(*piVar3);
            (*misnImport.AddScrap)(iVar8,(iVar9 - iVar4) * iVar5);
          }
          piVar11[4] = iVar4;
        }
      }
      piVar11 = piVar11 + 0xb;
    } while (piVar11 != *(int **)&(this->UtilityShipList).field_0x4);
  }
  return;
}


// ---------------------------------------------------------------------
// UtilityShipHelper::GetEscortTarget  @ 4fc156ca  lines 273-299

int __thiscall UtilityShipHelper::GetEscortTarget(UtilityShipHelper *this,int param_1,int param_2)

{
  int Team2;
  bool bVar1;
  int iVar2;
  int *piVar3;
  float TotalPriorities;
  
  Team2 = param_1;
  TotalPriorities = 0.0;
  for (iVar2 = *(int *)&this->UtilityShipList; iVar2 != *(int *)&(this->UtilityShipList).field_0x4;
      iVar2 = iVar2 + 0x2c) {
    if ((param_1 < 0) || (bVar1 = TeamFilterCheck(3,*(int *)(iVar2 + 0xc),param_1), bVar1)) {
      TotalPriorities = (float)*(int *)(iVar2 + 0x14) + TotalPriorities;
    }
  }
  param_1 = (int)GetRandomFloat(0.0,TotalPriorities);
  piVar3 = *(int **)&this->UtilityShipList;
  if (piVar3 != *(int **)&(this->UtilityShipList).field_0x4) {
    do {
      if (((Team2 < 0) || (bVar1 = TeamFilterCheck(3,piVar3[3],Team2), bVar1)) &&
         ((param_1 = (int)((float)param_1 - (float)piVar3[5]), (float)param_1 <= 0.0 ||
          (piVar3 == *(int **)&(this->UtilityShipList).field_0x4)))) {
        return *piVar3;
      }
      piVar3 = piVar3 + 0xb;
    } while (piVar3 != *(int **)&(this->UtilityShipList).field_0x4);
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
  int unaff_ESI;
  int *piVar3;
  int unaff_EDI;
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
    bVar1 = IsServiceTruck(unaff_EDI,unaff_ESI);
    if (bVar1) {
      bVar1 = IsTeamAllied(iVar2,piVar3[3]);
      if ((bVar1) && ((*(char *)((int)piVar3 + 5) != '\0' || (iVar2 == param_2)))) {
        if (!param_3) {
          bVar1 = IsIdle(*piVar3);
          if (!bVar1) goto LAB_4fc158c4;
        }
        if (*(char *)((int)piVar3 + 6) != '\0') {
          bVar1 = IsServiceTruck(unaff_EDI,unaff_ESI);
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
            fVar4 = GetDistance3DSquared((Vector *)(piVar3 + 8),&local_c);
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


