// Reconstructed by Ghidra from LuaMission.dll + LuaMission.pdb
// Original source file: /e:/github/vsr_dll_source/missions/vsrcore/poweruphelper.cpp
// Functions are ordered by original source line. This is decompiler
// output, not the author's source: names/types come from the PDB,
// local variable names and control flow are reconstructed.


// ---------------------------------------------------------------------
// `dynamic_initializer_for_'TempPowerupBuffer''  @ 4fc019d5  lines 7-7


void __cdecl _dynamic_initializer_for__TempPowerupBuffer__(void)

{
  atexit(_dynamic_atexit_destructor_for__TempPowerupBuffer__);
  return;
}


// ---------------------------------------------------------------------
// PowerupHelper::PostLoad  @ 4fc3940c  lines 42-73


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
// PowerupHelper::AddPowerupObject  @ 4fc394da  lines 91-140


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
// PowerupHelper::Execute  @ 4fc396e0  lines 143-192


void __thiscall PowerupHelper::Execute(PowerupHelper *this,BZ1Helper *param_1)

{
  AlignTerrainReplaceClass *pAVar1;
  undefined1 auVar2 [12];
  undefined1 auVar3 [12];
  bool bVar4;
  bool bVar5;
  AiCommand AVar6;
  Vector *pVVar7;
  int iVar8;
  AlignTerrainReplaceClass *pAVar9;
  undefined4 unaff_ESI;
  AlignTerrainReplaceClass *pAVar10;
  int *piVar11;
  undefined4 unaff_EDI;
  AlignTerrainReplaceClass *pAVar12;
  int *piVar13;
  float fVar14;
  float fVar15;
  float fVar16;
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
  
  bVar4 = BZ1Helper::Logging;
  pAVar1 = *(AlignTerrainReplaceClass **)&(this->PowerupList).field_0x4;
  pAVar9 = *(AlignTerrainReplaceClass **)&this->PowerupList;
  while ((pAVar9 != pAVar1 && (bVar5 = BZ1Helper::ShouldRemoveAlignTerrainReplace(pAVar9), !bVar5)))
  {
    pAVar9 = (AlignTerrainReplaceClass *)&pAVar9[0x10].NormalVec;
  }
  pAVar10 = pAVar9;
  if (pAVar9 != pAVar1) {
    while (pAVar10 = (AlignTerrainReplaceClass *)&pAVar10[0x10].NormalVec, pAVar10 != pAVar1) {
      bVar5 = BZ1Helper::ShouldRemoveAlignTerrainReplace(pAVar10);
      if (!bVar5) {
        pVVar7 = (Vector *)pAVar10;
        pAVar12 = pAVar9;
        for (iVar8 = 0x41; iVar8 != 0; iVar8 = iVar8 + -1) {
          pAVar12->AlignHandle = (int)pVVar7->x;
          pVVar7 = (Vector *)&pVVar7->y;
          pAVar12 = (AlignTerrainReplaceClass *)&pAVar12->NormalVec;
        }
        pAVar9 = (AlignTerrainReplaceClass *)&pAVar9[0x10].NormalVec;
      }
    }
  }
  piVar13 = *(int **)&(this->PowerupList).field_0x4;
  if (pAVar9 != pAVar1) {
    memmove(pAVar9,pAVar1,(int)piVar13 - (int)pAVar1);
    piVar13 = (int *)(((int)piVar13 - (int)pAVar1) + (int)pAVar9);
    *(int **)&(this->PowerupList).field_0x4 = piVar13;
  }
  piVar11 = *(int **)&this->PowerupList;
  if (piVar11 != piVar13) {
    do {
      GetPosition(*piVar11,&local_64);
      piVar11[0x37] = (int)local_64.x;
      piVar11[0x38] = (int)local_64.y;
      piVar11[0x39] = (int)local_64.z;
      AVar6 = GetCurrentCommand(*piVar11);
      piVar11[0x3a] = AVar6;
      if (((AVar6 == CMD_GO) || (AVar6 == CMD_DEPLOY)) || (AVar6 - CMD_GET_IN < 2)) {
        pVVar7 = GetCurrentCommandWhere(&local_18,*piVar11);
        piVar11[0x3b] = (int)pVVar7->x;
        piVar11[0x3c] = (int)pVVar7->y;
        piVar11[0x3d] = (int)pVVar7->z;
      }
      pVVar7 = GetVelocity(&local_c,*piVar11);
      piVar11[0x3e] = (int)pVVar7->x;
      piVar11[0x3f] = (int)pVVar7->y;
      piVar11[0x40] = (int)pVVar7->z;
      if (0 < piVar11[0x35]) {
        iVar8 = SecondsToTurns(1.0);
        if (piVar11[0x35] == iVar8) {
          local_88 = 0;
          local_84 = 0;
          local_80 = 0;
          local_b8 = 0.0;
          local_b4 = 0.0;
          local_b0 = 0.0;
          auVar2._4_4_ = unaff_ESI;
          auVar2._0_4_ = unaff_EDI;
          auVar2._8_4_ = 0;
          iVar8 = GetODFVector(0x4fc5e384,(char *)&local_b8,(char *)0x0,(Vector *)0x0,
                               (Vector)(auVar2 << 0x20));
          if ((iVar8 != 0) &&
             (__real_3dcccccd <= local_b8 * local_b8 + local_b4 * local_b4 + local_b0 * local_b0)) {
            local_7c = 0;
            local_78 = 0;
            local_74 = 0;
            local_a4 = 0.0;
            local_ac = 0.0;
            local_a8 = 0.0;
            auVar3._4_4_ = unaff_ESI;
            auVar3._0_4_ = unaff_EDI;
            auVar3._8_4_ = 0;
            GetODFVector(0x4fc5e398,(char *)&local_ac,(char *)0x0,(Vector *)0x0,
                         (Vector)(auVar3 << 0x20));
            GetPosition(*piVar11,&local_58);
            GetVelocity(&local_94,*piVar11);
            fVar14 = GetRandomFloat(local_ac,local_b8);
            fVar15 = GetRandomFloat(local_a8,local_b4);
            fVar16 = GetRandomFloat(local_a4,local_b0);
            local_70 = (double)fVar14;
            local_a0.x = local_58.right.x * fVar14 + local_94.x + local_58.up.x * fVar15 +
                         local_58.front.x * fVar16;
            local_a0.y = local_58.right.y * fVar14 + local_94.y + local_58.up.y * fVar15 +
                         local_58.front.y * fVar16;
            local_a0.z = fVar14 * local_58.right.z + local_94.z + local_58.up.z * fVar15 +
                         local_58.front.z * fVar16;
            SetVelocity(*piVar11,&local_a0);
            if (bVar4) {
              FormatLogMessage("Powerup Vel: %f %f %f, OffSet: %f %f %f, NewVel: %f %f %f");
            }
          }
        }
        piVar11[0x35] = piVar11[0x35] + -1;
      }
      piVar11 = piVar11 + 0x41;
    } while (piVar11 != *(int **)&(this->PowerupList).field_0x4);
  }
  return;
}

