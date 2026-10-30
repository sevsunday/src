// Reconstructed by Ghidra from Strategy02.dll + Strategy02.pdb
// Original source file: /e:/github/vsr_dll_source/missions/vsrcore/poweruphelper.cpp
// Functions are ordered by original source line. This is decompiler
// output, not the author's source: names/types come from the PDB,
// local variable names and control flow are reconstructed.

// ---------------------------------------------------------------------
// `dynamic_initializer_for_'TempPowerupBuffer''  @ 4fc01966  lines 7-7

void __cdecl _dynamic_initializer_for__TempPowerupBuffer__(void)

{
  atexit(_dynamic_atexit_destructor_for__TempPowerupBuffer__);
  return;
}


// ---------------------------------------------------------------------
// PowerupHelper::PostLoad  @ 4fc25698  lines 42-73

bool __thiscall PowerupHelper::PostLoad(PowerupHelper *this,bool param_1)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  int fmtarg1;
  int *piVar4;
  int fmtarg1_00;
  
  fmtarg1_00 = 0;
  piVar4 = *(int **)&this->PowerupList;
  piVar2 = *(int **)&(this->PowerupList).field_0x4;
  if (piVar4 != piVar2) {
    do {
      ConvertHandles(piVar4,1);
      if (piVar4[0x3a] == 3) {
        SetCommand(*piVar4,3,0,0,(Vector *)(piVar4 + 0x3b),0);
        SetVelocity(*piVar4,(Vector *)(piVar4 + 0x3e));
      }
      piVar2 = *(int **)&(this->PowerupList).field_0x4;
      piVar4 = piVar4 + 0x41;
    } while (piVar4 != piVar2);
    piVar4 = *(int **)&this->PowerupList;
  }
  iVar3 = ((int)piVar2 - (int)piVar4) / 0x104;
  fmtarg1 = (int)(TempPowerupBuffer._4_4_ - TempPowerupBuffer._0_4_) / 0x104;
  if (fmtarg1 == iVar3) {
    if (0 < iVar3) {
      iVar3 = 0;
      do {
        bVar1 = ::operator==((PowerupClass *)(TempPowerupBuffer._0_4_ + iVar3),
                             (PowerupClass *)((int)piVar4 + iVar3));
        if (!bVar1) {
          FormatLogMessage("PowerupList Index Mismatch: %d",fmtarg1_00);
          return true;
        }
        piVar4 = *(int **)&this->PowerupList;
        fmtarg1_00 = fmtarg1_00 + 1;
        iVar3 = iVar3 + 0x104;
      } while (fmtarg1_00 < (*(int *)&(this->PowerupList).field_0x4 - (int)piVar4) / 0x104);
    }
  }
  else {
    FormatLogMessage("PowerupList Size Mismatch! Old: %d New: %d",fmtarg1,iVar3);
  }
  return true;
}


// ---------------------------------------------------------------------
// PowerupHelper::AddPowerupObject  @ 4fc25766  lines 91-140

void __thiscall
PowerupHelper::AddPowerupObject
          (PowerupHelper *this,int param_1,char *param_2,char *param_3,int param_4,long param_5)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  
  piVar4 = *(int **)&this->PowerupList;
  piVar1 = *(int **)&(this->PowerupList).field_0x4;
  while( true ) {
    if (piVar4 == piVar1) {
      std::vector<PowerupHelper::PowerupClass,std::allocator<PowerupHelper::PowerupClass>_>::
      _Resize<<lambda_dcc549f59dec1aad2202dcbd5a8823fa>_>
                (&this->PowerupList,((int)piVar1 - *(int *)&this->PowerupList) / 0x104 + 1,
                 (<lambda_dcc549f59dec1aad2202dcbd5a8823fa>)this);
      iVar2 = *(int *)&this->PowerupList;
      iVar5 = ((*(int *)&(this->PowerupList).field_0x4 - iVar2) / 0x104) * 0x104;
      memset((void *)(iVar2 + -0x100 + iVar5),0,0x100);
      *(int *)(iVar2 + -0x104 + iVar5) = param_1;
      *(long *)(iVar2 + -0x100 + iVar5) = param_5;
      if (((param_5 == 0x4b970310) || (param_5 == 0x33fe0a68)) &&
         (iVar3 = GetODFLong(param_2,param_3,"HealthPowerupClass","healthUp",
                             (long *)(iVar2 + -0xfc + iVar5),0), iVar3 == 0)) {
        GetODFLong(param_2,param_3,"ServicePowerupClass","serviceUp",(long *)(iVar2 + -0xfc + iVar5)
                   ,0);
      }
      if ((param_5 == -0x599d55a0) || (param_5 == 0x33fe0a68)) {
        iVar3 = GetODFLong(param_2,param_3,"AmmoPowerupClass","healthUp",
                           (long *)(iVar2 + -0xf8 + iVar5),0);
        if (iVar3 == 0) {
          GetODFLong(param_2,param_3,"ServicePowerupClass","serviceUp",
                     (long *)(iVar2 + -0xf8 + iVar5),0);
        }
        iVar3 = GetODFLong(param_2,param_3,"AmmoPowerupClass","localAmmoUp",
                           (long *)(iVar2 + -0xf4 + iVar5),0);
        if (iVar3 == 0) {
          GetODFLong(param_2,param_3,"ServicePowerupClass","localAmmoUp",
                     (long *)(iVar2 + -0xf4 + iVar5),0);
        }
      }
      if (param_5 == 0x16164674) {
        GetODFString(param_2,param_3,"WeaponPowerupClass","weaponName",0x40,
                     (char *)(iVar2 + -0xf0 + iVar5),(char *)0x0);
      }
      GetODFString(param_2,param_3,"PowerUpClass","soundPickup",0x40,(char *)(iVar2 + -0xb0 + iVar5)
                   ,(char *)0x0);
      GetODFString(param_2,param_3,"PowerUpClass","soundReject",0x40,(char *)(iVar2 + -0x70 + iVar5)
                   ,(char *)0x0);
      GetODFInt(param_2,param_3,"PowerUpClass","HitMask",(int *)(iVar2 + -0x2c + iVar5),-1);
      iVar3 = SecondsToTurns(1.0);
      *(int *)(iVar2 + -0x30 + iVar5) = iVar3;
      return;
    }
    if (*piVar4 == param_1) break;
    piVar4 = piVar4 + 0x41;
  }
  return;
}


// ---------------------------------------------------------------------
// PowerupHelper::Execute  @ 4fc2596c  lines 143-192

void __thiscall PowerupHelper::Execute(PowerupHelper *this,BZ1Helper *param_1)

{
  AlignTerrainReplaceClass *pAVar1;
  Vector v;
  AlignTerrainReplaceClass *entry;
  bool bVar2;
  bool bVar3;
  int *piVar4;
  AiCommand AVar5;
  Vector *pVVar6;
  int iVar7;
  AlignTerrainReplaceClass *entry_00;
  int *piVar8;
  undefined4 unaff_EDI;
  AlignTerrainReplaceClass *pAVar9;
  size_t sVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  Vector local_b8;
  Vector local_ac;
  Vector local_a0;
  Vector local_94;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  double local_70;
  Vector local_64;
  Matrix local_58;
  Vector local_18;
  Vector local_c;
  
  bVar2 = BZ1Helper::Logging;
  pAVar1 = *(AlignTerrainReplaceClass **)&(this->PowerupList).field_0x4;
  entry_00 = *(AlignTerrainReplaceClass **)&this->PowerupList;
  while ((entry_00 != pAVar1 &&
         (bVar3 = BZ1Helper::ShouldRemoveAlignTerrainReplace(entry_00), !bVar3))) {
    entry_00 = (AlignTerrainReplaceClass *)&entry_00[0x10].NormalVec;
  }
  entry = entry_00;
  if (entry_00 != pAVar1) {
    while (entry = (AlignTerrainReplaceClass *)&entry[0x10].NormalVec, entry != pAVar1) {
      bVar3 = BZ1Helper::ShouldRemoveAlignTerrainReplace(entry);
      if (!bVar3) {
        pVVar6 = (Vector *)entry;
        pAVar9 = entry_00;
        for (iVar7 = 0x41; iVar7 != 0; iVar7 = iVar7 + -1) {
          pAVar9->AlignHandle = (int)pVVar6->x;
          pVVar6 = (Vector *)&pVVar6->y;
          pAVar9 = (AlignTerrainReplaceClass *)&pAVar9->NormalVec;
        }
        entry_00 = (AlignTerrainReplaceClass *)&entry_00[0x10].NormalVec;
      }
    }
    if (entry_00 != pAVar1) {
      sVar10 = *(int *)&(this->PowerupList).field_0x4 - (int)pAVar1;
      memmove(entry_00,pAVar1,sVar10);
      piVar4 = (int *)(sVar10 + (int)entry_00);
      *(int **)&(this->PowerupList).field_0x4 = piVar4;
      goto LAB_4fc25a03;
    }
  }
  piVar4 = *(int **)&(this->PowerupList).field_0x4;
LAB_4fc25a03:
  piVar8 = *(int **)&this->PowerupList;
  if (piVar8 != piVar4) {
    do {
      GetPosition(*piVar8,&local_64);
      piVar8[0x37] = (int)local_64.x;
      piVar8[0x38] = (int)local_64.y;
      piVar8[0x39] = (int)local_64.z;
      AVar5 = GetCurrentCommand(*piVar8);
      piVar8[0x3a] = AVar5;
      if (((AVar5 == CMD_GO) || (AVar5 == CMD_DEPLOY)) || (AVar5 - CMD_GET_IN < 2)) {
        pVVar6 = GetCurrentCommandWhere(&local_18,*piVar8);
        piVar8[0x3b] = (int)pVVar6->x;
        piVar8[0x3c] = (int)pVVar6->y;
        piVar8[0x3d] = (int)pVVar6->z;
      }
      pVVar6 = GetVelocity(&local_c,*piVar8);
      piVar8[0x3e] = (int)pVVar6->x;
      piVar8[0x3f] = (int)pVVar6->y;
      piVar8[0x40] = (int)pVVar6->z;
      if (0 < piVar8[0x35]) {
        iVar7 = SecondsToTurns(1.0);
        if (piVar8[0x35] == iVar7) {
          local_88 = 0;
          local_84 = 0;
          local_80 = 0;
          local_b8.x = 0.0;
          local_b8.y = 0.0;
          local_b8.z = 0.0;
          iVar7 = GetODFVector(*piVar8,"PowerUpClass","MaxVelocityOffset",&local_b8,
                               (Vector)ZEXT812(0));
          if ((iVar7 != 0) &&
             (v.y = local_b8.y, v.x = local_b8.x, v.z = local_b8.z, bVar3 = IsNullVector(v), !bVar3)
             ) {
            local_7c = 0;
            local_78 = 0;
            local_74 = 0;
            local_ac.z = 0.0;
            local_ac.x = 0.0;
            local_ac.y = 0.0;
            GetODFVector(*piVar8,"PowerUpClass","MinVelocityOffset",&local_ac,(Vector)ZEXT812(0));
            GetPosition(*piVar8,&local_58);
            GetVelocity(&local_94,*piVar8);
            fVar11 = GetRandomFloat(local_ac.x,local_b8.x);
            fVar12 = GetRandomFloat(local_ac.y,local_b8.y);
            fVar13 = GetRandomFloat(local_ac.z,local_b8.z);
            local_70 = (double)fVar13;
            local_a0.x = local_58.right.x * fVar11 + local_94.x + local_58.up.x * fVar12 +
                         local_58.front.x * fVar13;
            local_a0.y = local_58.right.y * fVar11 + local_94.y + local_58.up.y * fVar12 +
                         local_58.front.y * fVar13;
            local_a0.z = fVar11 * local_58.right.z + local_94.z + local_58.up.z * fVar12 +
                         local_58.front.z * fVar13;
            SetVelocity(*piVar8,&local_a0);
            if (bVar2) {
              FormatLogMessage("Powerup Vel: %f %f %f, OffSet: %f %f %f, NewVel: %f %f %f",
                               (double)CONCAT44(SUB84((double)local_94.y,0),
                                                (int)((ulonglong)(double)local_94.x >> 0x20)),
                               (double)CONCAT44(SUB84((double)local_94.z,0),
                                                (int)((ulonglong)(double)local_94.y >> 0x20)),
                               (double)CONCAT44(SUB84((double)fVar11,0),
                                                (int)((ulonglong)(double)local_94.z >> 0x20)),
                               (double)CONCAT44(SUB84((double)fVar12,0),
                                                (int)((ulonglong)(double)fVar11 >> 0x20)),
                               (double)CONCAT44(SUB84(local_70,0),
                                                (int)((ulonglong)(double)fVar12 >> 0x20)),
                               (double)CONCAT44(SUB84((double)local_a0.x,0),
                                                (int)((ulonglong)local_70 >> 0x20)),
                               (double)CONCAT44(SUB84((double)local_a0.y,0),
                                                (int)((ulonglong)(double)local_a0.x >> 0x20)),
                               (double)CONCAT44(SUB84((double)local_a0.z,0),
                                                (int)((ulonglong)(double)local_a0.y >> 0x20)),
                               (double)CONCAT44(unaff_EDI,
                                                (int)((ulonglong)(double)local_a0.z >> 0x20)));
            }
          }
        }
        piVar8[0x35] = piVar8[0x35] + -1;
      }
      piVar8 = piVar8 + 0x41;
    } while (piVar8 != *(int **)&(this->PowerupList).field_0x4);
  }
  return;
}


