// Reconstructed by Ghidra from Strategy02.dll + Strategy02.pdb
// Original source file: /e:/github/vsr_dll_source/missions/vsrcore/attacherhelper.cpp
// Functions are ordered by original source line. This is decompiler
// output, not the author's source: names/types come from the PDB,
// local variable names and control flow are reconstructed.

// ---------------------------------------------------------------------
// `dynamic_initializer_for_'TempAttacherBuffer''  @ 4fc01607  lines 7-7

void __cdecl _dynamic_initializer_for__TempAttacherBuffer__(void)

{
  atexit(_dynamic_atexit_destructor_for__TempAttacherBuffer__);
  return;
}


// ---------------------------------------------------------------------
// AttacherHelper::PostLoad  @ 4fc19ebf  lines 35-60

bool __thiscall AttacherHelper::PostLoad(AttacherHelper *this,bool param_1)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  
  piVar5 = *(int **)&this->AttacherList;
  piVar2 = *(int **)&(this->AttacherList).field_0x4;
  if (piVar5 != piVar2) {
    do {
      ConvertHandles(piVar5,1);
      piVar2 = piVar5 + 3;
      iVar4 = 8;
      do {
        ConvertHandles(piVar2,1);
        piVar2 = piVar2 + 0x20;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
      piVar2 = *(int **)&(this->AttacherList).field_0x4;
      piVar5 = piVar5 + 0x103;
    } while (piVar5 != piVar2);
    piVar5 = *(int **)&this->AttacherList;
  }
  iVar4 = ((int)piVar2 - (int)piVar5) / 0x40c;
  iVar3 = (int)(TempAttacherBuffer._4_4_ - TempAttacherBuffer._0_4_) / 0x40c;
  if (iVar3 == iVar4) {
    iVar3 = 0;
    if (0 < iVar4) {
      iVar4 = 0;
      do {
        bVar1 = ::operator==((AttacherClass *)(TempAttacherBuffer._0_4_ + iVar4),
                             (AttacherClass *)((int)piVar5 + iVar4));
        if (!bVar1) {
          FormatLogMessage("AttacherList Index Mismatch: %d",iVar3);
          return true;
        }
        piVar5 = *(int **)&this->AttacherList;
        iVar3 = iVar3 + 1;
        iVar4 = iVar4 + 0x40c;
      } while (iVar3 < (*(int *)&(this->AttacherList).field_0x4 - (int)piVar5) / 0x40c);
    }
  }
  else {
    FormatLogMessage("AttacherList Size Mismatch! Old: %d New: %d",iVar3,iVar4);
  }
  return true;
}


// ---------------------------------------------------------------------
// AttacherHelper::AddAttacherObject  @ 4fc19f7c  lines 79-194

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall
AttacherHelper::AddAttacherObject
          (AttacherHelper *this,int h,char *TempODF1,char *TempODF2,int BZCClassHash,char *ODFName)

{
  float *value;
  Vector defval;
  Vector defval_00;
  char *fmtarg1;
  bool bVar1;
  int iVar2;
  int *piVar3;
  Vector *value_00;
  float *pfVar4;
  int iVar5;
  char *pcVar6;
  char *local_340;
  int local_33c;
  char *local_338;
  float *local_334;
  char *local_330;
  int *local_32c;
  undefined4 local_328;
  undefined4 local_324;
  float local_320;
  undefined4 local_31c;
  undefined4 local_318;
  float local_314;
  float local_310;
  float local_30c;
  float local_308;
  char local_304 [64];
  byte local_2c4 [64];
  char local_284 [64];
  char local_244 [64];
  char local_204 [512];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)&local_340;
  local_330 = ODFName;
  local_338 = TempODF1;
  local_340 = TempODF2;
  memset(local_284,0,0x40);
  iVar2 = GetODFString(TempODF1,TempODF2,"GameObjectClass","AttachedObject1",0x40,local_284,
                       (char *)0x0);
  if ((iVar2 != 0) && (local_284[0] != '\0')) {
    piVar3 = *(int **)&this->AttacherList;
    if (piVar3 != *(int **)&(this->AttacherList).field_0x4) {
      do {
        if (*piVar3 == h) {
          return;
        }
        piVar3 = piVar3 + 0x103;
      } while (piVar3 != *(int **)&(this->AttacherList).field_0x4);
    }
    memset(local_204,0,0x200);
    strcpy_s(local_204,0x40,local_284);
    iVar5 = 1;
    pcVar6 = local_204;
    iVar2 = 0;
    do {
      memset(local_2c4,0,0x40);
      local_33c = iVar2 + 1;
      sprintf_s<64>((char (*) [64])local_2c4,"AttachedObject%d",local_33c);
      if (0 < iVar2) {
        iVar2 = GetODFString(local_338,local_340,"GameObjectClass",(char *)local_2c4,0x40,pcVar6,
                             (char *)0x0);
        if ((iVar2 == 0) || (*pcVar6 == '\0')) break;
        iVar5 = iVar5 + 1;
      }
      fmtarg1 = local_330;
      iVar2 = _stricmp(pcVar6,local_330);
      if (iVar2 == 0) {
        FormatConsoleMessage
                  ("ERROR: ODF \'%s\', \'%s\' attempted to attach itself, preventing infinite loop."
                   ,fmtarg1,(char *)local_2c4);
        return;
      }
      pcVar6 = pcVar6 + 0x40;
      iVar2 = local_33c;
    } while (local_33c < 8);
    if (iVar5 != 0) {
      std::vector<AttacherHelper::AttacherClass,std::allocator<AttacherHelper::AttacherClass>_>::
      _Resize<<lambda_7ba5f03559cb281997e133de678b9134>_>
                (&this->AttacherList,
                 (*(int *)&(this->AttacherList).field_0x4 - *(int *)&this->AttacherList) / 0x40c + 1
                 ,(<lambda_7ba5f03559cb281997e133de678b9134>)this);
      piVar3 = (int *)(*(int *)&this->AttacherList + -0x40c +
                      ((*(int *)&(this->AttacherList).field_0x4 - *(int *)&this->AttacherList) /
                      0x40c) * 0x40c);
      local_32c = piVar3;
      memset(piVar3,0,0x40c);
      if (BZCClassHash == -0x4568e22) {
        *(undefined1 *)(piVar3 + 2) = 1;
      }
      piVar3[1] = iVar5;
      if (0 < iVar5) {
        local_328 = 0;
        local_330 = local_204;
        local_324 = 0;
        local_320 = 0.0;
        local_31c = 0;
        local_318 = 0;
        local_314 = 0.0;
        pfVar4 = (float *)(piVar3 + 0xd);
        local_33c = 1;
        do {
          iVar2 = local_33c;
          local_334 = pfVar4;
          memset(local_304,0,0x40);
          sprintf_s<64>(&local_304,"AttachedIndependent%d",iVar2);
          pcVar6 = local_338;
          GetODFBool(local_338,local_340,"GameObjectClass",local_304,(bool *)(pfVar4 + -9),true);
          sprintf_s<64>(&local_304,"AttachedCoordinateFire%d",iVar2);
          GetODFBool(pcVar6,local_340,"GameObjectClass",local_304,(bool *)(pfVar4 + -8),false);
          sprintf_s<64>(&local_304,"AttachedDeployState%d",iVar2);
          GetODFInt(pcVar6,local_340,"GameObjectClass",local_304,(int *)(pfVar4 + -7),-1);
          if (((int)pfVar4[-7] < -1) || (1 < (int)pfVar4[-7])) {
            pfVar4[-7] = -NAN;
          }
          sprintf_s<64>(&local_304,"AttachedPDSMode%d",iVar2);
          GetODFBool(pcVar6,local_340,"GameObjectClass",local_304,(bool *)((int)pfVar4 + -0x1f),
                     false);
          sprintf_s<64>(&local_304,"AttachedWeaponSymmetryMask%d",iVar2);
          GetODFString(pcVar6,local_340,"GameObjectClass",local_304,6,(char *)(pfVar4 + 1),"00000");
          sprintf_s<64>(&local_304,"AttachedOffset%d",iVar2);
          defval.y = (float)local_324;
          defval.x = (float)local_328;
          defval.z = local_320;
          GetODFVector(local_338,local_340,"GameObjectClass",local_304,(Vector *)(pfVar4 + -5),
                       defval);
          sprintf_s<64>(&local_304,"AttachedRotation%d",local_33c);
          value_00 = (Vector *)(pfVar4 + -2);
          defval_00.y = (float)local_318;
          defval_00.x = (float)local_31c;
          defval_00.z = local_314;
          GetODFVector(local_338,local_340,"GameObjectClass",local_304,value_00,defval_00);
          pcVar6 = local_330;
          local_310 = value_00->x * 0.017453292;
          local_30c = local_334[-1] * 0.017453292;
          local_308 = *local_334 * 0.017453292;
          value_00->x = local_310;
          pfVar4[-1] = local_30c;
          *pfVar4 = local_308;
          CombineStrings(local_330,local_330,".odf",0x40);
          bVar1 = OpenODF2(pcVar6);
          pfVar4 = local_334;
          if (bVar1) {
            memset(local_2c4,0,0x40);
            memset(local_244,0,0x40);
            iVar2 = GetODFString(pcVar6,"GameObjectClass","classlabel",0x40,local_244,(char *)0x0);
            if (iVar2 != 0) {
              CombineStrings((char *)local_2c4,local_244,".odf",0x40);
              bVar1 = OpenODF2((char *)local_2c4);
              local_2c4[0] = local_2c4[0] & -bVar1;
            }
            pfVar4 = local_334;
            value = local_334 + -6;
            iVar2 = GetODFFloat(pcVar6,(char *)local_2c4,"CraftClass","EngageRange",value,0.0);
            if (iVar2 == 0) {
              GetODFFloat(pcVar6,(char *)local_2c4,"CraftClass","RangeScan",value,0.0);
            }
          }
          pfVar4 = pfVar4 + 0x20;
          local_33c = local_33c + 1;
          local_330 = pcVar6 + 0x40;
          iVar5 = iVar5 + -1;
          piVar3 = local_32c;
        } while (iVar5 != 0);
      }
      *piVar3 = h;
    }
  }
  return;
}


// ---------------------------------------------------------------------
// AttacherHelper::Execute  @ 4fc1a485  lines 197-686

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall AttacherHelper::Execute(AttacherHelper *this,BZ1Helper *bz1Helper)

{
  uint h;
  Vector VVar1;
  code *pcVar2;
  char cVar3;
  bool bVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  Matrix *pMVar8;
  Vector *pVVar9;
  uint uVar10;
  char *pcVar11;
  int iVar12;
  int *piVar13;
  int *piVar14;
  int *piVar15;
  Matrix *unaff_ESI;
  int *piVar16;
  code *pcVar17;
  Matrix *unaff_EDI;
  code *pcVar18;
  uint *puVar19;
  float *pfVar20;
  float fVar21;
  undefined1 auStack_590 [5];
  bool local_58b;
  char local_58a;
  char local_589;
  char *local_588;
  uint local_584;
  int *local_580;
  char local_579;
  int *local_578;
  char local_571;
  code *local_570;
  int *local_56c;
  code *local_568;
  BZ1Helper *local_564;
  code *local_560;
  int *local_55c;
  int local_558;
  uint local_554;
  code *local_550;
  int *local_54c;
  code *local_548;
  code *local_544;
  code *local_540;
  uint local_53c;
  int local_538;
  code *local_534;
  code *local_530;
  int local_52c;
  float local_528;
  code *local_524;
  code *local_520;
  code *local_51c;
  code *local_518;
  AttacherHelper *local_514;
  code *local_510;
  code *local_50c;
  code *local_508;
  code *local_504;
  code *local_500;
  code *local_4fc;
  float local_4f8;
  code *local_4f4;
  code *local_4f0;
  code *local_4ec;
  code *local_4e8;
  code *local_4e4;
  float local_4e0;
  code *local_4dc;
  code *local_4d8;
  undefined1 local_4d4 [36];
  double local_4b0;
  Vector local_4a4;
  Matrix local_498;
  Matrix local_458;
  uint local_3fc [8];
  float local_3dc [5];
  int local_3c8 [12];
  Vector local_398;
  float local_388 [2];
  float local_380;
  float local_358;
  float local_350;
  char local_348 [64];
  undefined1 local_308 [64];
  char local_2c8 [64];
  char local_288 [64];
  char local_248 [64];
  undefined1 local_208 [64];
  char local_1c8 [64];
  char local_188 [64];
  char local_148 [324];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)auStack_590;
  local_564 = bz1Helper;
  pcVar17 = *(code **)&this->AttacherList;
  local_58b = BZ1Helper::Logging;
  local_550 = IsAround_exref;
  local_524 = RemoveObject_exref;
  pcVar18 = pcVar17;
  local_568 = pcVar17;
  local_548 = pcVar17;
  local_514 = this;
  for (; piVar13 = *(int **)&(local_514->AttacherList).field_0x4, pcVar17 != (code *)piVar13;
      pcVar17 = (code *)((int)pcVar17 + 0x40c)) {
    local_560 = pcVar17;
    cVar3 = (*local_550)(*(int *)pcVar17);
    pcVar2 = local_524;
    if (cVar3 == '\0') {
      iVar6 = 0;
      if (0 < *(int *)((int)pcVar17 + 4)) {
        piVar13 = (int *)((int)pcVar17 + 0xc);
        do {
          (*pcVar2)(*piVar13);
          iVar6 = iVar6 + 1;
          piVar13 = piVar13 + 0x20;
          pcVar18 = local_568;
        } while (iVar6 < *(int *)((int)pcVar17 + 4));
      }
    }
    else {
      if (local_548 != pcVar17) {
        piVar13 = (int *)pcVar17;
        piVar16 = (int *)pcVar18;
        for (iVar6 = 0x103; pcVar17 = local_560, pcVar18 = local_568, iVar6 != 0; iVar6 = iVar6 + -1
            ) {
          *piVar16 = *piVar13;
          piVar13 = piVar13 + 1;
          piVar16 = piVar16 + 1;
        }
      }
      local_568 = (code *)((int)pcVar18 + 0x40c);
      pcVar18 = local_568;
    }
  }
  if (pcVar18 != (code *)piVar13) {
    *(code **)&(local_514->AttacherList).field_0x4 = pcVar18;
    piVar13 = (int *)pcVar18;
  }
  piVar16 = *(int **)&local_514->AttacherList;
  if (piVar16 != piVar13) {
    local_4e4 = GetOmega_exref;
    local_50c = GetTeamNum_exref;
    local_508 = IsDeployed_exref;
    local_504 = DoesODFExist_exref;
    local_500 = BuildObject_exref;
    local_4fc = SetIndependence_exref;
    local_530 = _stricmp_exref;
    local_570 = StartAnimation_exref;
    local_510 = IsPerson_exref;
    local_520 = SetLastCurrentPosition_exref;
    local_4f4 = SetInterpolablePosition_exref;
    local_4f0 = SetVelocity_exref;
    local_534 = GetObjInfo_exref;
    local_51c = IsPlayer_exref;
    local_568 = Attack_exref;
    local_4f8 = 0.6;
    local_544 = SetCommand_exref;
    local_4e8 = GetMaxHealth_exref;
    local_4e0 = 3.1415927;
    local_4dc = IsAliveAndPilot2_exref;
    local_518 = Deploy_exref;
    local_4b0 = 0.0;
    local_52c = 0x5c;
    local_4d8 = GetVelocity_exref;
    local_548 = GetTarget_exref;
    local_560 = IsTeamAllied_exref;
    local_540 = GetPosition_exref;
    local_4ec = strcpy_s_exref;
    do {
      pcVar2 = local_540;
      pcVar18 = local_548;
      pcVar17 = local_560;
      local_578 = piVar16;
      (*local_4d8)(local_4d4 + 0xc,*piVar16);
      (*local_4e4)(&local_4a4,*piVar16);
      uVar5 = (*pcVar18)(*piVar16);
      local_554 = uVar5;
      (*pcVar2)(*piVar16,&local_458);
      iVar6 = (*local_50c)(*piVar16);
      local_579 = '\0';
      local_558 = iVar6;
      if (uVar5 != 0) {
        uVar7 = (*local_50c)(uVar5);
        local_579 = (*pcVar17)(iVar6,uVar7);
      }
      iVar6 = *piVar16;
      puVar19 = local_3fc;
      for (iVar12 = 8; iVar12 != 0; iVar12 = iVar12 + -1) {
        *puVar19 = 0;
        puVar19 = puVar19 + 1;
      }
      local_589 = (*local_508)(iVar6);
      local_584 = 0;
      if (0 < piVar16[1]) {
LAB_4fc1a726:
        uVar5 = local_584;
        local_54c = (int *)(local_584 * 0x80);
        piVar13 = (int *)((int)local_54c + (int)piVar16);
        local_55c = piVar13;
        if (*(char *)((int)piVar13 + 0x12) != '\0') goto LAB_4fc1aa57;
        if (piVar13[6] < 0) {
LAB_4fc1a75a:
          memset(local_348,0,0x40);
          memset(local_2c8,0,0x40);
          sprintf_s<64>(&local_2c8,"AttachedObject%d",uVar5 + 1);
          iVar6 = GetODFString(*piVar16,"GameObjectClass",local_2c8,0x40,local_348,(char *)0x0);
          if (iVar6 != 0) {
            if (local_348[0] != '\0') {
              cVar3 = (*local_504)(local_348);
              if (cVar3 == '\0') {
                FormatLogMessage("ERROR: Attacher ODF \'%s\' Doesn\'t Exist!",local_348);
              }
              else {
                (*local_540)(*piVar16,&local_498);
                Build_Position_Rotation_Matrix
                          ((Matrix *)piVar13[0xb],(float)piVar13[0xc],(float)piVar13[0xd],
                           (float)unaff_EDI,&unaff_ESI->right);
                pMVar8 = Matrix_Multiply(&local_498,unaff_EDI,unaff_ESI);
                pfVar20 = (float *)(piVar13 + 0x13);
                for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
                  *pfVar20 = (pMVar8->right).x;
                  pMVar8 = (Matrix *)&(pMVar8->right).y;
                  pfVar20 = pfVar20 + 1;
                }
                iVar6 = (*local_500)(local_348,local_558,piVar13 + 0x13);
                piVar13[3] = iVar6;
                (*local_4fc)(iVar6,0);
                memset(local_288,0,0x40);
                GetODFString(piVar13[3],"GameObjectClass","BZCClasslabel",0x40,local_288,(char *)0x0
                            );
                uVar5 = Hash((char *)unaff_EDI,(uint)unaff_ESI);
                piVar16 = local_578;
                if (uVar5 == 0xc17ac6e3) {
                  *(undefined1 *)((int)piVar13 + 0x3e) = 1;
                  GetODFFloat(piVar13[3],"GameObjectClass","CerbTailFireAngle",
                              (float *)(piVar13 + 0x11),local_4f8);
                  local_571 = '\0';
                  local_58a = '\0';
                  local_53c = local_53c & 0xffffff00;
                  memset(local_3c8,0,0x40);
                  local_538 = 0;
                  GetODFInt(piVar13[3],"GameObjectClass","animCount",&local_538,0);
                  iVar6 = 1;
                  if (1 < local_538 + 1) {
                    do {
                      memset(local_248,0,0x40);
                      sprintf_s<64>(&local_248,"animName%d",iVar6);
                      iVar12 = GetODFString(piVar13[3],"GameObjectClass",local_248,0x40,
                                            (char *)local_3c8,(char *)0x0);
                      pcVar17 = local_530;
                      if (iVar12 != 0) {
                        iVar12 = (*local_530)(local_3c8,"CerbTailIdle");
                        if (iVar12 == 0) {
                          local_571 = '\x01';
                        }
                        else {
                          iVar12 = (*pcVar17)(local_3c8,"CerbTailLeft");
                          if (iVar12 == 0) {
                            local_58a = '\x01';
                          }
                          else {
                            iVar12 = (*pcVar17)(local_3c8,"CerbTailRight");
                            local_53c = local_53c & 0xff;
                            if (iVar12 == 0) {
                              local_53c = 1;
                            }
                          }
                          if (local_571 == '\0') goto LAB_4fc1aa04;
                        }
                        if ((local_58a != '\0') && ((char)local_53c != '\0')) {
                          *(undefined1 *)((int)piVar13 + 0x3f) = 1;
                          break;
                        }
                      }
LAB_4fc1aa04:
                      iVar6 = iVar6 + 1;
                    } while (iVar6 < local_538 + 1);
                  }
                  piVar16 = local_578;
                  if (*(char *)((int)piVar13 + 0x3f) != '\0') {
                    fVar21 = SetAnimation(piVar13[3],"CerbTailIdle",0);
                    piVar13[0x12] = (int)fVar21;
                    (*local_570)(piVar13[3]);
                    piVar16 = local_578;
                    if (local_58b != false) {
                      FormatLogMessage("Playing Tail Loop Anim");
                      piVar16 = local_578;
                    }
                  }
                }
              }
            }
            *(undefined1 *)((int)piVar13 + 0x12) = 1;
          }
        }
        else if (piVar13[6] == 0) {
          if (local_589 == '\0') goto LAB_4fc1a75a;
        }
        else if (local_589 != '\0') goto LAB_4fc1a75a;
LAB_4fc1aa57:
        piVar15 = piVar13 + 3;
        cVar3 = (*local_550)(*piVar15);
        if (cVar3 != '\0') {
          if ((-1 < piVar13[6]) && ((piVar13[6] != 0) == (bool)local_589)) {
            (*local_524)(*piVar15);
            *(undefined1 *)((int)piVar13 + 0x16) = 0;
            *(undefined1 *)((int)piVar13 + 0x11) = 0;
            *(undefined1 *)((int)piVar13 + 0x13) = 0;
            goto LAB_4fc1aaa0;
          }
          Build_Position_Rotation_Matrix
                    ((Matrix *)piVar13[0xb],(float)piVar13[0xc],(float)piVar13[0xd],(float)unaff_EDI
                     ,&unaff_ESI->right);
          Matrix_Multiply(&local_458,unaff_EDI,unaff_ESI);
          bVar4 = IsCraft(*piVar15,0);
          if ((bVar4) || (cVar3 = (*local_510)(*piVar15), cVar3 != '\0')) {
            (*local_520)(*piVar15,piVar13 + 0x13,local_3c8);
          }
          else {
            (*local_520)(*piVar15,piVar13 + 0x13,local_3c8);
            (*local_4f4)(*piVar15,local_3c8,piVar13 + 0x13,1);
          }
          pMVar8 = (Matrix *)local_4d4;
          local_4d4._0_4_ = local_458.posit.x - local_398.x;
          local_4d4._4_4_ = local_458.posit.y - local_398.y;
          local_4d4._8_4_ = local_458.posit.z - local_398.z;
          Vector_Rotate(&local_4a4,pMVar8,&unaff_EDI->right);
          pVVar9 = Cross_Product(&pMVar8->right,&unaff_EDI->right,&unaff_ESI->right);
          local_4d4._24_4_ = (float)local_4d4._12_4_ + pVVar9->x;
          local_4d4._28_4_ = pVVar9->y + (float)local_4d4._16_4_;
          local_4d4._32_4_ = pVVar9->z + (float)local_4d4._20_4_;
          (*local_4f0)(*piVar15,local_4d4 + 0x18);
          local_58a = '\0';
          piVar16 = local_3c8;
          piVar14 = piVar13 + 0x13;
          for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
            *piVar14 = *piVar16;
            piVar16 = piVar16 + 1;
            piVar14 = piVar14 + 1;
          }
          memset(local_148,0,0x140);
          local_3dc[0] = 0.0;
          local_3dc[1] = 0.0;
          local_3dc[2] = 0.0;
          local_3dc[3] = 0.0;
          local_3dc[4] = 0.0;
          local_588 = local_148;
          iVar6 = 0;
          piVar13 = piVar13 + 0xf;
          local_56c = piVar13;
          do {
            piVar16 = local_578;
            if (((char)*piVar13 != '\0') && ((char)*piVar13 != '0')) {
              memset(local_308,0,0x40);
              memset(local_208,0,0x40);
              piVar16 = local_578;
              cVar3 = (*local_534)(*local_578,iVar6 + 5,local_308);
              if ((cVar3 != '\0') &&
                 (cVar3 = (*local_534)(*piVar15,iVar6 + 5,local_208), cVar3 != '\0')) {
                fVar21 = GetCurLocalAmmo(*piVar16,iVar6);
                local_3dc[iVar6] = fVar21;
                iVar12 = (*local_530)(local_308,local_208);
                if (iVar12 != 0) {
                  local_58a = '\x01';
                  (*local_4ec)(local_588,0x40,local_308);
                  local_588 = local_588 + 0x40;
                }
              }
            }
            piVar14 = local_55c;
            iVar6 = iVar6 + 1;
            piVar13 = (int *)((int)piVar13 + -1);
          } while (iVar6 < 5);
          if (local_58a != '\0') {
            ReplaceWeapons(*piVar15,(char (*) [64])local_148,local_3dc,(char *)0x0);
          }
          uVar5 = local_584;
          if (local_3fc[local_584] == 0) {
            uVar10 = (*local_548)(*piVar15);
            local_3fc[uVar5] = uVar10;
          }
          cVar3 = (*local_51c)(*piVar15);
          pcVar17 = local_570;
          if (cVar3 == '\0') {
            piVar13 = (int *)((int)local_54c + (int)piVar16);
            local_588 = (char *)piVar13[7];
            if (*(char *)((int)piVar14 + 0x3e) != '\0') {
              local_56c = (int *)0x0;
              local_528 = (float)local_588 * (float)local_588;
              local_580 = (int *)0x0;
              iVar6 = *(int *)&local_564->m_ObjectHelper->HandleList;
              if (0 < (*(int *)&(local_564->m_ObjectHelper->HandleList).field_0x4 - iVar6) /
                      local_52c) {
                local_588 = (char *)0x0;
                do {
                  local_55c = *(int **)(local_588 + iVar6);
                  if ((((*(int *)(local_588 + iVar6 + 0x10) == 1) &&
                       (cVar3 = (*local_560)(local_558,*(undefined4 *)(local_588 + iVar6 + 0x1c)),
                       cVar3 == '\0')) &&
                      (fVar21 = GetDistance3DSquared
                                          (&local_398,(Vector *)(local_588 + iVar6 + 0x48)),
                      piVar16 = local_55c, fVar21 < local_528)) &&
                     (bVar4 = IsObjectFacingObject(*piVar15,(int)local_55c,(float)piVar14[0x11]),
                     bVar4)) {
                    iVar6 = piVar14[0x10];
                    local_588 = (char *)0x0;
                    local_580 = piVar16;
                    if (iVar6 == 0) {
                      pcVar11 = "CerbTailIdle";
LAB_4fc1b3ed:
                      local_588 = (char *)GetAnimationFrame(*piVar15,pcVar11);
                    }
                    else {
                      if (iVar6 == 1) {
                        pcVar11 = "CerbTailLeft";
                        goto LAB_4fc1b3ed;
                      }
                      if (iVar6 == 2) {
                        pcVar11 = "CerbTailRight";
                        goto LAB_4fc1b3ed;
                      }
                    }
                    pcVar17 = local_550;
                    if ((float)local_588 == (float)piVar14[0x12]) {
                      iVar6 = *piVar15;
                      cVar3 = (*local_550)(iVar6);
                      if ((cVar3 == '\0') ||
                         (cVar3 = (*pcVar17)(piVar16), pcVar17 = local_540, cVar3 == '\0')) {
LAB_4fc1b48b:
                        bVar4 = false;
                      }
                      else {
                        (*local_540)(iVar6,local_388);
                        (*pcVar17)(piVar16,&local_498);
                        if ((local_498.posit.x - local_358) * local_388[0] +
                            (local_498.posit.z - local_350) * local_380 <= (float)local_4b0)
                        goto LAB_4fc1b48b;
                        bVar4 = true;
                      }
                      piVar15 = piVar13 + 3;
                      if (bVar4) {
                        piVar13[0x10] = 2;
                        pcVar11 = "CerbTailRight";
                      }
                      else {
                        piVar13[0x10] = 1;
                        pcVar11 = "CerbTailLeft";
                      }
                      local_56c = (int *)SetAnimation(*piVar15,pcVar11,0);
                      piVar13[0x12] = (int)local_56c;
                      (*local_570)(*piVar15);
                      (*local_568)(*piVar15,piVar16,1);
                      if (local_58b != false) {
                        FormatLogMessage("Playing Tail Swing Anim");
                      }
                    }
                    break;
                  }
                  local_588 = local_588 + 0x5c;
                  local_56c = (int *)((int)local_56c + 1);
                  iVar6 = *(int *)&local_564->m_ObjectHelper->HandleList;
                } while ((int)local_56c <
                         (*(int *)&(local_564->m_ObjectHelper->HandleList).field_0x4 - iVar6) /
                         local_52c);
              }
              iVar6 = piVar13[0x10];
              piVar14 = piVar13;
              pcVar17 = local_570;
              if ((iVar6 == 0) || (local_580 != (int *)0x0)) goto LAB_4fc1b2ab;
              local_588 = (char *)0x0;
              if (iVar6 == 1) {
                pcVar11 = "CerbTailLeft";
LAB_4fc1b523:
                local_588 = (char *)GetAnimationFrame(*piVar15,pcVar11);
              }
              else if (iVar6 == 2) {
                pcVar11 = "CerbTailRight";
                goto LAB_4fc1b523;
              }
              pcVar17 = local_570;
              if ((float)local_588 == (float)piVar13[0x12]) {
                (*local_544)(*piVar15,2,1,0,0,0);
                piVar13[0x10] = 0;
                fVar21 = SetAnimation(*piVar15,"CerbTailIdle",0);
                pcVar17 = local_570;
                piVar13[0x12] = (int)fVar21;
                (*local_570)(*piVar15);
                if (local_58b != false) {
                  FormatLogMessage("Playing Tail Idle Anim");
                }
              }
              goto LAB_4fc1b2ab;
            }
            if ((float)local_588 == 0.0) goto LAB_4fc1b2ab;
            if (((local_554 == 0) || (local_579 != '\0')) ||
               ((*(char *)((int)piVar14 + 0x15) != '\0' &&
                ((cVar3 = (*local_510)(local_554), cVar3 == '\0' &&
                 (bVar4 = IsWeapon(local_554,0), !bVar4)))))) {
              if (*(char *)((int)piVar14 + 0x11) != '\0') {
                (*local_544)(*piVar15,2,1,0,0,0);
                *(undefined1 *)((int)piVar14 + 0x11) = 0;
                if (local_58b != false) {
                  FormatLogMessage("Tap %x Switching to own AI control",local_584);
                }
              }
              uVar5 = local_584;
              if (((char)piVar14[4] != '\0') && (local_3fc[local_584] == 0)) {
                local_588 = (char *)piVar13[7];
                if (*(char *)((int)piVar14 + 0x15) == '\0') {
                  iVar6 = 0x17;
                }
                else {
                  iVar6 = 0x14;
                }
                VVar1.y = local_398.y;
                VVar1.x = local_398.x;
                VVar1.z = local_398.z;
                uVar10 = BZ1Helper::GetNearestObject
                                   (local_564,VVar1,(float)local_588,local_558,4,true,iVar6,false,
                                    false,0,0,(char *)0x0,(char *)0x0);
                uVar5 = local_584;
                local_3fc[local_584] = uVar10;
                piVar16 = local_578;
                if ((uVar10 != 0) &&
                   ((*local_568)(*piVar15,uVar10,1), piVar16 = local_578, local_58b != false)) {
                  pcVar11 = GetODFName(uVar10);
                  FormatLogMessage("Tap %x Set to Attack %08x \'%s\'",uVar5,uVar10,pcVar11);
                  piVar16 = local_578;
                }
              }
            }
            else {
              uVar10 = local_554;
              (*local_568)(*piVar15,local_554,1);
              *(undefined1 *)((int)piVar14 + 0x11) = 1;
              uVar5 = local_584;
              if (local_58b != false) {
                pcVar11 = GetODFName(uVar10);
                uVar5 = local_584;
                FormatLogMessage("Tap %x Attacking Host Target: %08x \'%s\'",local_584,uVar10,
                                 pcVar11);
              }
            }
            if (((char)piVar14[5] == '\0') &&
               ((((local_554 == 0 || (local_579 != '\0')) && (local_3fc[uVar5] != 0)) &&
                (uVar10 = 0, 0 < piVar16[1])))) {
              piVar13 = piVar16 + 3;
              do {
                if (((uVar10 != local_584) && (h = local_3fc[uVar10], local_3fc[uVar5] == h)) &&
                   ((*piVar13 != 0 && (h != 0)))) {
                  if (local_58b != false) {
                    pcVar11 = GetODFName(h);
                    FormatLogMessage("Tap %d Target: %08x \'%s\', picking new target...",uVar10,
                                     local_3fc[uVar10],pcVar11);
                  }
                  local_56c = (int *)0x0;
                  local_528 = (float)piVar14[7] * (float)piVar14[7];
                  local_580 = *(int **)&local_564->m_ObjectHelper->HandleList;
                  if (0 < (*(int *)&(local_564->m_ObjectHelper->HandleList).field_0x4 -
                          (int)local_580) / 0x5c) {
                    local_588 = (char *)0x0;
                    goto LAB_4fc1b047;
                  }
                  break;
                }
                uVar10 = uVar10 + 1;
                piVar13 = piVar13 + 0x20;
              } while ((int)uVar10 < piVar16[1]);
            }
            goto LAB_4fc1b258;
          }
          goto LAB_4fc1b2ab;
        }
        goto LAB_4fc1aaa0;
      }
LAB_4fc1aab2:
      piVar16 = piVar16 + 0x103;
    } while (piVar16 != *(int **)&(local_514->AttacherList).field_0x4);
  }
  return;
LAB_4fc1b047:
  do {
    piVar13 = *(int **)((int)local_580 + (int)local_588);
    cVar3 = (*local_560)(local_558,*(undefined4 *)((int)(local_580 + 7) + (int)local_588));
    if (((cVar3 == '\0') && (iVar6 = (*local_4e8)(piVar13), 0 < iVar6)) &&
       ((fVar21 = GetDistance3DSquared(&local_398,(Vector *)(local_588 + 0x48 + (int)local_580)),
        fVar21 <= local_528 &&
        (((*(char *)((int)piVar14 + 0x15) == '\0' ||
          (*(int *)((int)(local_580 + 4) + (int)local_588) == 4)) ||
         (*(int *)((int)(local_580 + 4) + (int)local_588) == 0x10)))))) {
      local_580 = (int *)0x0;
      if (0 < piVar16[1]) {
        local_54c = piVar16 + 3;
        do {
          cVar3 = (*local_550)(*local_54c);
          if (((cVar3 != '\0') &&
              (local_55c = (int *)local_3fc[(int)local_580], local_55c != (int *)0x0)) &&
             (piVar13 == local_55c)) {
            if (local_58b != false) {
              memset(local_188,0,0x40);
              memset(local_1c8,0,0x40);
              GetODFName((int)piVar13,local_188);
              GetODFName((int)local_55c,local_1c8);
              FormatLogMessage("Tap: %d Target %08x \'%s\' matches existing Target, Tap %d Target: %08x \'%s\'"
                               ,local_584,(uint)piVar13,local_188,(int)local_580,(uint)local_55c,
                               local_1c8);
            }
            goto LAB_4fc1b168;
          }
          local_580 = (int *)((int)local_580 + 1);
          local_54c = local_54c + 0x20;
        } while ((int)local_580 < piVar16[1]);
      }
      memset(local_388,0,0x40);
      (*local_534)(*piVar15,4,local_388);
      iVar6 = (*local_530)(local_388,"CLASS_WALKER");
      if ((iVar6 != 0) || (bVar4 = IsObjectFacingObject(*piVar15,(int)piVar13,local_4e0), bVar4)) {
        local_3fc[local_584] = (uint)piVar13;
        (*local_568)(*piVar15,piVar13,1);
        if (local_58b != false) {
          pcVar11 = GetODFName((int)piVar13);
          FormatLogMessage("Tap %d Targeting New Target: %08x \'%s\'",local_584,(uint)piVar13,
                           pcVar11);
        }
        break;
      }
    }
LAB_4fc1b168:
    local_588 = local_588 + 0x5c;
    local_56c = (int *)((int)local_56c + 1);
    local_580 = *(int **)&local_564->m_ObjectHelper->HandleList;
  } while ((int)local_56c <
           (*(int *)&(local_564->m_ObjectHelper->HandleList).field_0x4 - (int)local_580) / local_52c
          );
LAB_4fc1b258:
  cVar3 = (*local_4dc)(*piVar16);
  if ((cVar3 == '\0') && (cVar3 = (*local_51c)(*piVar16), cVar3 == '\0')) {
    local_58a = '\x01';
  }
  else {
    local_58a = '\0';
  }
  pcVar17 = local_570;
  if (local_58a != *(char *)((int)piVar14 + 0x13)) {
    if (local_58a != '\0') {
      (*local_544)(*piVar15,2,1,0,0,0);
    }
    *(char *)((int)piVar14 + 0x13) = local_58a;
    pcVar17 = local_570;
  }
LAB_4fc1b2ab:
  piVar16 = local_578;
  if (*(char *)((int)piVar14 + 0x16) == '\0') {
    if (local_589 == '\0') goto LAB_4fc1aaa0;
    *(undefined1 *)((int)piVar14 + 0x16) = 1;
    pcVar11 = "deploy";
  }
  else {
    if (local_589 != '\0') goto LAB_4fc1aaa0;
    *(undefined1 *)((int)piVar14 + 0x16) = 0;
    pcVar11 = "undeploy";
  }
  SetAnimation(*piVar15,pcVar11,1);
  (*pcVar17)(*piVar15);
  (*local_518)(*piVar15);
  piVar16 = local_578;
LAB_4fc1aaa0:
  local_584 = local_584 + 1;
  if (piVar16[1] <= (int)local_584) goto LAB_4fc1aab2;
  goto LAB_4fc1a726;
}


