// Reconstructed by Ghidra from deathmatch01.dll + deathmatch01.pdb
// Original source file: /e:/github/vsr_dll_source/missions/vsrcore/poweruphelper.cpp
// Functions are ordered by original source line. This is decompiler
// output, not the author's source: names/types come from the PDB,
// local variable names and control flow are reconstructed.


// ---------------------------------------------------------------------
// `dynamic_initializer_for_'TempPowerupBuffer''  @ 4fc01964  lines 7-7


void __cdecl _dynamic_initializer_for__TempPowerupBuffer__(void)

{
  atexit(_dynamic_atexit_destructor_for__TempPowerupBuffer__);
  return;
}


// ---------------------------------------------------------------------
// PowerupHelper::PostLoad  @ 4fc249b9  lines 42-73


bool __thiscall PowerupHelper::PostLoad(PowerupHelper *this,bool param_1)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  PowerupClass *unaff_ESI;
  int *piVar4;
  PowerupClass *unaff_EDI;
  int iVar5;
  
  iVar5 = 0;
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
  if ((int)(TempPowerupBuffer._4_4_ - TempPowerupBuffer._0_4_) / 0x104 == iVar3) {
    if (0 < iVar3) {
      do {
        bVar1 = ::operator==(unaff_EDI,unaff_ESI);
        if (!bVar1) {
          FormatLogMessage("PowerupList Index Mismatch: %d");
          return true;
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < (*(int *)&(this->PowerupList).field_0x4 - *(int *)&this->PowerupList) / 0x104
              );
    }
  }
  else {
    FormatLogMessage("PowerupList Size Mismatch! Old: %d New: %d");
  }
  return true;
}


// ---------------------------------------------------------------------
// PowerupHelper::AddPowerupObject  @ 4fc24a87  lines 91-140


void __thiscall
PowerupHelper::AddPowerupObject
          (PowerupHelper *this,int param_1,char *param_2,char *param_3,int param_4,long param_5)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  long *unaff_EBX;
  int iVar5;
  char *unaff_EDI;
  char *pcVar6;
  char *pcVar7;
  char *pcVar8;
  char *pcVar9;
  
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
         (iVar3 = GetODFLong("HealthPowerupClass","healthUp",(char *)(iVar2 + -0xfc + iVar5),
                             (char *)0x0,unaff_EBX,(long)unaff_EDI), iVar3 == 0)) {
        GetODFLong("ServicePowerupClass","serviceUp",(char *)(iVar2 + -0xfc + iVar5),(char *)0x0,
                   unaff_EBX,(long)unaff_EDI);
      }
      if ((param_5 == -0x599d55a0) || (param_5 == 0x33fe0a68)) {
        iVar3 = GetODFLong("AmmoPowerupClass","healthUp",(char *)(iVar2 + -0xf8 + iVar5),(char *)0x0
                           ,unaff_EBX,(long)unaff_EDI);
        if (iVar3 == 0) {
          GetODFLong("ServicePowerupClass","serviceUp",(char *)(iVar2 + -0xf8 + iVar5),(char *)0x0,
                     unaff_EBX,(long)unaff_EDI);
        }
        iVar3 = GetODFLong("AmmoPowerupClass","localAmmoUp",(char *)(iVar2 + -0xf4 + iVar5),
                           (char *)0x0,unaff_EBX,(long)unaff_EDI);
        if (iVar3 == 0) {
          GetODFLong("ServicePowerupClass","localAmmoUp",(char *)(iVar2 + -0xf4 + iVar5),(char *)0x0
                     ,unaff_EBX,(long)unaff_EDI);
        }
      }
      if (param_5 == 0x16164674) {
        GetODFString("WeaponPowerupClass","weaponName",(char *)0x40,(char *)(iVar2 + -0xf0 + iVar5),
                     0,(char *)unaff_EBX,unaff_EDI);
      }
      pcVar9 = "soundPickup";
      pcVar8 = "PowerUpClass";
      GetODFString("PowerUpClass","soundPickup",(char *)0x40,(char *)(iVar2 + -0xb0 + iVar5),0,
                   (char *)unaff_EBX,unaff_EDI);
      pcVar7 = "soundReject";
      pcVar6 = "PowerUpClass";
      GetODFString("PowerUpClass","soundReject",(char *)0x40,(char *)(iVar2 + -0x70 + iVar5),0,
                   pcVar8,pcVar9);
      GetODFInt("PowerUpClass","HitMask",(char *)(iVar2 + -0x2c + iVar5),(char *)0xffffffff,
                (int *)pcVar6,(int)pcVar7);
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
// PowerupHelper::Execute  @ 4fc24c8d  lines 143-192


void __thiscall PowerupHelper::Execute(PowerupHelper *this,BZ1Helper *param_1)

{
  AlignTerrainReplaceClass *pAVar1;
  Vector VVar2;
  undefined1 auVar3 [12];
  undefined1 auVar4 [12];
  bool bVar5;
  bool bVar6;
  AiCommand AVar7;
  Vector *pVVar8;
  int iVar9;
  AlignTerrainReplaceClass *pAVar10;
  undefined4 unaff_ESI;
  AlignTerrainReplaceClass *pAVar11;
  int *piVar12;
  undefined4 unaff_EDI;
  AlignTerrainReplaceClass *pAVar13;
  int *piVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float local_b8;
  float local_b4;
  float local_b0;
  float local_ac;
  float local_a8;
  float local_a4;
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
  
  bVar5 = BZ1Helper::Logging;
  pAVar1 = *(AlignTerrainReplaceClass **)&(this->PowerupList).field_0x4;
  pAVar10 = *(AlignTerrainReplaceClass **)&this->PowerupList;
  while ((pAVar10 != pAVar1 && (bVar6 = BZ1Helper::ShouldRemoveAlignTerrainReplace(pAVar10), !bVar6)
         )) {
    pAVar10 = (AlignTerrainReplaceClass *)&pAVar10[0x10].NormalVec;
  }
  pAVar11 = pAVar10;
  if (pAVar10 != pAVar1) {
    while (pAVar11 = (AlignTerrainReplaceClass *)&pAVar11[0x10].NormalVec, pAVar11 != pAVar1) {
      bVar6 = BZ1Helper::ShouldRemoveAlignTerrainReplace(pAVar11);
      if (!bVar6) {
        pVVar8 = (Vector *)pAVar11;
        pAVar13 = pAVar10;
        for (iVar9 = 0x41; iVar9 != 0; iVar9 = iVar9 + -1) {
          pAVar13->AlignHandle = (int)pVVar8->x;
          pVVar8 = (Vector *)&pVVar8->y;
          pAVar13 = (AlignTerrainReplaceClass *)&pAVar13->NormalVec;
        }
        pAVar10 = (AlignTerrainReplaceClass *)&pAVar10[0x10].NormalVec;
      }
    }
  }
  piVar14 = *(int **)&(this->PowerupList).field_0x4;
  if (pAVar10 != pAVar1) {
    memmove(pAVar10,pAVar1,(int)piVar14 - (int)pAVar1);
    piVar14 = (int *)(((int)piVar14 - (int)pAVar1) + (int)pAVar10);
    *(int **)&(this->PowerupList).field_0x4 = piVar14;
  }
  piVar12 = *(int **)&this->PowerupList;
  if (piVar12 != piVar14) {
    do {
      GetPosition(*piVar12,&local_64);
      piVar12[0x37] = (int)local_64.x;
      piVar12[0x38] = (int)local_64.y;
      piVar12[0x39] = (int)local_64.z;
      AVar7 = GetCurrentCommand(*piVar12);
      piVar12[0x3a] = AVar7;
      if (((AVar7 == CMD_GO) || (AVar7 == CMD_DEPLOY)) || (AVar7 - CMD_GET_IN < 2)) {
        pVVar8 = GetCurrentCommandWhere(&local_18,*piVar12);
        piVar12[0x3b] = (int)pVVar8->x;
        piVar12[0x3c] = (int)pVVar8->y;
        piVar12[0x3d] = (int)pVVar8->z;
      }
      pVVar8 = GetVelocity(&local_c,*piVar12);
      piVar12[0x3e] = (int)pVVar8->x;
      piVar12[0x3f] = (int)pVVar8->y;
      piVar12[0x40] = (int)pVVar8->z;
      if (0 < piVar12[0x35]) {
        iVar9 = SecondsToTurns(1.0);
        if (piVar12[0x35] == iVar9) {
          local_88 = 0;
          local_84 = 0;
          local_80 = 0;
          local_b8 = 0.0;
          local_b4 = 0.0;
          local_b0 = 0.0;
          auVar3._4_4_ = unaff_ESI;
          auVar3._0_4_ = unaff_EDI;
          auVar3._8_4_ = 0;
          iVar9 = GetODFVector(0x4fc5e3bc,(char *)&local_b8,(char *)0x0,(Vector *)0x0,
                               (Vector)(auVar3 << 0x20));
          if ((iVar9 != 0) &&
             (VVar2.y = local_b4, VVar2.x = local_b8, VVar2.z = local_b0,
             bVar6 = IsNullVector(VVar2), !bVar6)) {
            local_7c = 0;
            local_78 = 0;
            local_74 = 0;
            local_a4 = 0.0;
            local_ac = 0.0;
            local_a8 = 0.0;
            auVar4._4_4_ = unaff_ESI;
            auVar4._0_4_ = unaff_EDI;
            auVar4._8_4_ = 0;
            GetODFVector(0x4fc5e3d0,(char *)&local_ac,(char *)0x0,(Vector *)0x0,
                         (Vector)(auVar4 << 0x20));
            GetPosition(*piVar12,&local_58);
            GetVelocity(&local_94,*piVar12);
            fVar15 = GetRandomFloat(local_ac,local_b8);
            fVar16 = GetRandomFloat(local_a8,local_b4);
            fVar17 = GetRandomFloat(local_a4,local_b0);
            local_70 = (double)fVar15;
            local_a0.x = local_58.right.x * fVar15 + local_94.x + local_58.up.x * fVar16 +
                         local_58.front.x * fVar17;
            local_a0.y = local_58.right.y * fVar15 + local_94.y + local_58.up.y * fVar16 +
                         local_58.front.y * fVar17;
            local_a0.z = fVar15 * local_58.right.z + local_94.z + local_58.up.z * fVar16 +
                         local_58.front.z * fVar17;
            SetVelocity(*piVar12,&local_a0);
            if (bVar5) {
              FormatLogMessage("Powerup Vel: %f %f %f, OffSet: %f %f %f, NewVel: %f %f %f");
            }
          }
        }
        piVar12[0x35] = piVar12[0x35] + -1;
      }
      piVar12 = piVar12 + 0x41;
    } while (piVar12 != *(int **)&(this->PowerupList).field_0x4);
  }
  return;
}

