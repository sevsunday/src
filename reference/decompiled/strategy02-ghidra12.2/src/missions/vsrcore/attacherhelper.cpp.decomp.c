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
  AttacherClass *unaff_ESI;
  int *piVar4;
  AttacherClass *unaff_EDI;
  int iVar5;
  
  piVar4 = *(int **)&this->AttacherList;
  piVar2 = *(int **)&(this->AttacherList).field_0x4;
  if (piVar4 != piVar2) {
    do {
      ConvertHandles(piVar4,1);
      piVar2 = piVar4 + 3;
      iVar3 = 8;
      do {
        ConvertHandles(piVar2,1);
        piVar2 = piVar2 + 0x20;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
      piVar2 = *(int **)&(this->AttacherList).field_0x4;
      piVar4 = piVar4 + 0x103;
    } while (piVar4 != piVar2);
    piVar4 = *(int **)&this->AttacherList;
  }
  iVar3 = ((int)piVar2 - (int)piVar4) / 0x40c;
  if ((int)(TempAttacherBuffer._4_4_ - TempAttacherBuffer._0_4_) / 0x40c == iVar3) {
    iVar5 = 0;
    if (0 < iVar3) {
      do {
        bVar1 = ::operator==(unaff_EDI,unaff_ESI);
        if (!bVar1) {
          FormatLogMessage("AttacherList Index Mismatch: %d");
          return true;
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < (*(int *)&(this->AttacherList).field_0x4 - *(int *)&this->AttacherList) /
                       0x40c);
    }
  }
  else {
    FormatLogMessage("AttacherList Size Mismatch! Old: %d New: %d");
  }
  return true;
}


// ---------------------------------------------------------------------
// AttacherHelper::AddAttacherObject  @ 4fc19f7c  lines 79-194


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall
AttacherHelper::AddAttacherObject
          (AttacherHelper *this,int param_1,char *param_2,char *param_3,int param_4,char *param_5)

{
  Vector VVar1;
  Vector VVar2;
  bool bVar3;
  int iVar4;
  int *piVar5;
  float *pfVar6;
  float *pfVar7;
  int iVar8;
  char *unaff_ESI;
  float *unaff_EDI;
  char *pcVar9;
  char (*pacVar10) [64];
  char *pcVar11;
  undefined1 uVar12;
  char *pcVar13;
  char *local_340;
  int local_33c;
  char *local_338;
  float *local_334;
  char *local_330;
  int *local_32c;
  char *local_328;
  Vector *local_324;
  undefined4 local_320;
  char *local_31c;
  Vector *local_318;
  undefined4 local_314;
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
  local_330 = param_5;
  pcVar9 = local_284;
  local_338 = param_2;
  pcVar13 = (char *)0x0;
  local_340 = param_3;
  memset(pcVar9,0,0x40);
  iVar4 = GetODFString("GameObjectClass","AttachedObject1",(char *)0x40,local_284,0,pcVar9,pcVar13);
  if ((iVar4 != 0) && (local_284[0] != '\0')) {
    piVar5 = *(int **)&this->AttacherList;
    if (piVar5 != *(int **)&(this->AttacherList).field_0x4) {
      do {
        if (*piVar5 == param_1) {
          return;
        }
        piVar5 = piVar5 + 0x103;
      } while (piVar5 != *(int **)&(this->AttacherList).field_0x4);
    }
    memset(local_204,0,0x200);
    strcpy_s(local_204,0x40,local_284);
    iVar8 = 1;
    pcVar9 = local_204;
    iVar4 = 0;
    do {
      memset(local_2c4,0,0x40);
      local_33c = iVar4 + 1;
      sprintf_s<64>((char (*) [64])local_2c4,"AttachedObject%d");
      if (0 < iVar4) {
        iVar4 = GetODFString("GameObjectClass",(char *)local_2c4,(char *)0x40,pcVar9,0,
                             (char *)unaff_EDI,unaff_ESI);
        if ((iVar4 == 0) || (*pcVar9 == '\0')) break;
        iVar8 = iVar8 + 1;
      }
      iVar4 = _stricmp(pcVar9,local_330);
      if (iVar4 == 0) {
        FormatConsoleMessage
                  ("ERROR: ODF \'%s\', \'%s\' attempted to attach itself, preventing infinite loop."
                  );
        return;
      }
      pcVar9 = pcVar9 + 0x40;
      iVar4 = local_33c;
    } while (local_33c < 8);
    if (iVar8 != 0) {
      std::vector<AttacherHelper::AttacherClass,std::allocator<AttacherHelper::AttacherClass>_>::
      _Resize<<lambda_7ba5f03559cb281997e133de678b9134>_>
                (&this->AttacherList,
                 (*(int *)&(this->AttacherList).field_0x4 - *(int *)&this->AttacherList) / 0x40c + 1
                 ,(<lambda_7ba5f03559cb281997e133de678b9134>)this);
      piVar5 = (int *)(*(int *)&this->AttacherList + -0x40c +
                      ((*(int *)&(this->AttacherList).field_0x4 - *(int *)&this->AttacherList) /
                      0x40c) * 0x40c);
      local_32c = piVar5;
      memset(piVar5,0,0x40c);
      if (param_4 == -0x4568e22) {
        *(undefined1 *)(piVar5 + 2) = 1;
      }
      piVar5[1] = iVar8;
      if (0 < iVar8) {
        local_328 = (char *)0x0;
        local_330 = local_204;
        local_324 = (Vector *)0x0;
        local_320 = 0;
        local_31c = (char *)0x0;
        local_318 = (Vector *)0x0;
        local_314 = 0;
        local_334 = (float *)(piVar5 + 0xd);
        local_33c = 1;
        do {
          pfVar7 = local_334;
          memset(local_304,0,0x40);
          pacVar10 = &local_304;
          uVar12 = 100;
          sprintf_s<64>(pacVar10,"AttachedIndependent%d");
          GetODFBool("GameObjectClass",local_304,(char *)(pfVar7 + -9),(char *)0x1,(bool *)pacVar10,
                     (bool)uVar12);
          pacVar10 = &local_304;
          uVar12 = 0x7c;
          sprintf_s<64>(pacVar10,"AttachedCoordinateFire%d");
          GetODFBool("GameObjectClass",local_304,(char *)(pfVar7 + -8),(char *)0x0,(bool *)pacVar10,
                     (bool)uVar12);
          pacVar10 = &local_304;
          pcVar9 = "AttachedDeployState%d";
          sprintf_s<64>(pacVar10,"AttachedDeployState%d");
          GetODFInt("GameObjectClass",local_304,(char *)(pfVar7 + -7),(char *)0xffffffff,
                    (int *)pacVar10,(int)pcVar9);
          if (((int)pfVar7[-7] < -1) || (1 < (int)pfVar7[-7])) {
            pfVar7[-7] = -NAN;
          }
          pacVar10 = &local_304;
          uVar12 = 0xb0;
          sprintf_s<64>(pacVar10,"AttachedPDSMode%d");
          GetODFBool("GameObjectClass",local_304,(char *)((int)pfVar7 + -0x1f),(char *)0x0,
                     (bool *)pacVar10,(bool)uVar12);
          pacVar10 = &local_304;
          pcVar9 = "AttachedWeaponSymmetryMask%d";
          sprintf_s<64>(pacVar10,"AttachedWeaponSymmetryMask%d");
          GetODFString("GameObjectClass",local_304,(char *)0x6,(char *)(pfVar7 + 1),0x4fc5e8e4,
                       *pacVar10,pcVar9);
          sprintf_s<64>(&local_304,"AttachedOffset%d");
          VVar1.y = (float)unaff_EDI;
          VVar1.x = (float)local_320;
          VVar1.z = (float)unaff_ESI;
          GetODFVector("GameObjectClass",local_304,(char *)(pfVar7 + -5),local_328,local_324,VVar1);
          sprintf_s<64>(&local_304,"AttachedRotation%d");
          pcVar9 = local_304;
          pfVar6 = pfVar7 + -2;
          pcVar11 = "GameObjectClass";
          VVar2.y = (float)unaff_EDI;
          VVar2.x = (float)local_314;
          VVar2.z = (float)unaff_ESI;
          GetODFVector("GameObjectClass",pcVar9,(char *)pfVar6,local_31c,local_318,VVar2);
          pcVar13 = local_330;
          local_310 = *pfVar6 * __real_3c8efa35;
          local_30c = local_334[-1] * __real_3c8efa35;
          local_308 = *local_334 * __real_3c8efa35;
          *pfVar6 = local_310;
          pfVar7[-1] = local_30c;
          *pfVar7 = local_308;
          CombineStrings(".odf",(char *)0x40,pcVar11,(uint)pcVar9);
          bVar3 = OpenODF2((char *)unaff_EDI);
          if (bVar3) {
            memset(local_2c4,0,0x40);
            memset(local_244,0,0x40);
            iVar4 = GetODFString(pcVar13,"GameObjectClass","classlabel",0x40,local_244,(char *)0x0);
            if (iVar4 != 0) {
              CombineStrings(".odf",(char *)0x40,(char *)unaff_EDI,(uint)unaff_ESI);
              bVar3 = OpenODF2((char *)unaff_EDI);
              local_2c4[0] = local_2c4[0] & -bVar3;
            }
            pfVar7 = local_334;
            pfVar6 = local_334 + -6;
            iVar4 = GetODFFloat("CraftClass","EngageRange",(char *)pfVar6,(char *)0x0,unaff_EDI,
                                (float)unaff_ESI);
            if (iVar4 == 0) {
              GetODFFloat("CraftClass","RangeScan",(char *)pfVar6,(char *)0x0,unaff_EDI,
                          (float)unaff_ESI);
            }
          }
          else {
            pfVar7 = local_334;
          }
          local_334 = pfVar7 + 0x20;
          local_33c = local_33c + 1;
          local_330 = pcVar13 + 0x40;
          iVar8 = iVar8 + -1;
        } while (iVar8 != 0);
        piVar5 = local_32c;
      }
      *piVar5 = param_1;
    }
  }
  return;
}


// ---------------------------------------------------------------------
// AttacherHelper::Execute  @ 4fc1a485  lines 197-686


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall AttacherHelper::Execute(AttacherHelper *this,BZ1Helper *param_1)

{
  Vector VVar1;
  code *pcVar2;
  char cVar3;
  bool bVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  Matrix *pMVar9;
  uint uVar10;
  Vector *pVVar11;
  int *piVar12;
  int *piVar13;
  Matrix *unaff_ESI;
  code *pcVar14;
  Matrix *unaff_EDI;
  code *pcVar15;
  float *pfVar16;
  int *piVar17;
  float fVar18;
  char *pcVar19;
  undefined1 auStack_590 [5];
  bool local_58b;
  char local_58a;
  char local_589;
  undefined1 *local_588;
  int local_584;
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
  int local_554;
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
  char *local_4f8;
  code *local_4f4;
  code *local_4f0;
  code *local_4ec;
  code *local_4e8;
  code *local_4e4;
  int local_4e0;
  code *local_4dc;
  code *local_4d8;
  undefined1 local_4d4 [36];
  double local_4b0;
  Vector local_4a4;
  Matrix local_498;
  Matrix local_458;
  int local_3fc [8];
  float local_3dc [5];
  int local_3c8 [12];
  float local_398;
  float local_394;
  float local_390;
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
  undefined1 local_1c8 [64];
  undefined1 local_188 [64];
  undefined1 local_148 [324];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)auStack_590;
  local_564 = param_1;
  pcVar14 = *(code **)&this->AttacherList;
  local_58b = BZ1Helper::Logging;
  local_550 = IsAround_exref;
  local_524 = RemoveObject_exref;
  pcVar15 = pcVar14;
  local_568 = pcVar14;
  local_548 = pcVar14;
  local_514 = this;
  for (; piVar5 = *(int **)&(local_514->AttacherList).field_0x4, pcVar14 != (code *)piVar5;
      pcVar14 = (code *)((int)pcVar14 + 0x40c)) {
    local_560 = pcVar14;
    cVar3 = (*local_550)(*(int *)pcVar14);
    pcVar2 = local_524;
    if (cVar3 == '\0') {
      iVar6 = 0;
      if (0 < *(int *)((int)pcVar14 + 4)) {
        piVar5 = (int *)((int)pcVar14 + 0xc);
        do {
          (*pcVar2)(*piVar5);
          iVar6 = iVar6 + 1;
          piVar5 = piVar5 + 0x20;
        } while (iVar6 < *(int *)((int)pcVar14 + 4));
        pcVar15 = local_568;
      }
    }
    else {
      if (local_548 != pcVar14) {
        for (iVar6 = 0x103; iVar6 != 0; iVar6 = iVar6 + -1) {
          *(int *)pcVar15 = *(int *)pcVar14;
          pcVar14 = (code *)((int)pcVar14 + 4);
          pcVar15 = (code *)((int)pcVar15 + 4);
        }
        pcVar14 = local_560;
        pcVar15 = local_568;
      }
      local_568 = (code *)((int)pcVar15 + 0x40c);
      pcVar15 = local_568;
    }
  }
  if (pcVar15 != (code *)piVar5) {
    *(code **)&(local_514->AttacherList).field_0x4 = pcVar15;
    piVar5 = (int *)pcVar15;
  }
  local_578 = *(int **)&local_514->AttacherList;
  if (local_578 != piVar5) {
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
    local_4f8 = ___real_3f19999a;
    local_544 = SetCommand_exref;
    local_4e8 = GetMaxHealth_exref;
    local_4e0 = ___real_40490fdb;
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
      pcVar15 = local_548;
      pcVar14 = local_560;
      piVar5 = local_578;
      (*local_4d8)(local_4d4 + 0xc,*local_578);
      (*local_4e4)(&local_4a4,*piVar5);
      iVar6 = (*pcVar15)(*piVar5);
      local_554 = iVar6;
      (*pcVar2)(*piVar5,&local_458);
      iVar7 = (*local_50c)(*piVar5);
      local_579 = '\0';
      local_558 = iVar7;
      if (iVar6 != 0) {
        uVar8 = (*local_50c)(iVar6);
        local_579 = (*pcVar14)(iVar7,uVar8);
      }
      iVar6 = *piVar5;
      piVar12 = local_3fc;
      for (iVar7 = 8; iVar7 != 0; iVar7 = iVar7 + -1) {
        *piVar12 = 0;
        piVar12 = piVar12 + 1;
      }
      local_589 = (*local_508)(iVar6);
      local_584 = 0;
      if (0 < piVar5[1]) {
LAB_4fc1a726:
        local_54c = (int *)(local_584 * 0x80);
        piVar12 = (int *)((int)local_54c + (int)piVar5);
        local_55c = piVar12;
        if (*(char *)((int)piVar12 + 0x12) != '\0') goto LAB_4fc1aa57;
        if (piVar12[6] < 0) {
LAB_4fc1a75a:
          memset(local_348,0,0x40);
          memset(local_2c8,0,0x40);
          sprintf_s<64>(&local_2c8,"AttachedObject%d");
          iVar6 = GetODFString((int)local_2c8,(char *)0x40,local_348,0,(char *)unaff_EDI,
                               (char *)unaff_ESI);
          if (iVar6 != 0) {
            if (local_348[0] != '\0') {
              cVar3 = (*local_504)(local_348);
              if (cVar3 == '\0') {
                FormatLogMessage("ERROR: Attacher ODF \'%s\' Doesn\'t Exist!");
              }
              else {
                (*local_540)(*piVar5,&local_498);
                Build_Position_Rotation_Matrix
                          ((Matrix *)piVar12[0xb],(float)piVar12[0xc],(float)piVar12[0xd],
                           (float)unaff_EDI,&unaff_ESI->right);
                pMVar9 = Matrix_Multiply(&local_498,unaff_EDI,unaff_ESI);
                pfVar16 = (float *)(piVar12 + 0x13);
                for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
                  *pfVar16 = (pMVar9->right).x;
                  pMVar9 = (Matrix *)&(pMVar9->right).y;
                  pfVar16 = pfVar16 + 1;
                }
                iVar6 = (*local_500)(local_348,local_558,piVar12 + 0x13);
                piVar12[3] = iVar6;
                (*local_4fc)(iVar6,0);
                memset(local_288,0,0x40);
                GetODFString(0x4fc57d90,(char *)0x40,local_288,0,(char *)unaff_EDI,(char *)unaff_ESI
                            );
                uVar10 = Hash((char *)unaff_EDI,(uint)unaff_ESI);
                if (uVar10 == 0xc17ac6e3) {
                  *(undefined1 *)((int)piVar12 + 0x3e) = 1;
                  GetODFFloat(0x4fc5e914,(char *)(piVar12 + 0x11),local_4f8,(float *)unaff_EDI,
                              (float)unaff_ESI);
                  local_571 = '\0';
                  local_58a = '\0';
                  local_53c = local_53c & 0xffffff00;
                  memset(local_3c8,0,0x40);
                  local_538 = 0;
                  GetODFInt(0x4fc5e928,(char *)&local_538,(char *)0x0,(int *)unaff_EDI,
                            (int)unaff_ESI);
                  iVar6 = 1;
                  if (1 < local_538 + 1) {
                    do {
                      memset(local_248,0,0x40);
                      sprintf_s<64>(&local_248,"animName%d");
                      iVar7 = GetODFString((int)local_248,(char *)0x40,(char *)local_3c8,0,
                                           (char *)unaff_EDI,(char *)unaff_ESI);
                      pcVar14 = local_530;
                      if (iVar7 != 0) {
                        iVar7 = (*local_530)(local_3c8,"CerbTailIdle");
                        if (iVar7 == 0) {
                          local_571 = '\x01';
                        }
                        else {
                          iVar7 = (*pcVar14)(local_3c8,"CerbTailLeft");
                          if (iVar7 == 0) {
                            local_58a = '\x01';
                          }
                          else {
                            iVar7 = (*pcVar14)(local_3c8,"CerbTailRight");
                            local_53c = local_53c & 0xff;
                            if (iVar7 == 0) {
                              local_53c = 1;
                            }
                          }
                          if (local_571 == '\0') goto LAB_4fc1aa04;
                        }
                        if ((local_58a != '\0') && ((char)local_53c != '\0')) {
                          *(undefined1 *)((int)piVar12 + 0x3f) = 1;
                          break;
                        }
                      }
LAB_4fc1aa04:
                      iVar6 = iVar6 + 1;
                    } while (iVar6 < local_538 + 1);
                  }
                  if (*(char *)((int)piVar12 + 0x3f) != '\0') {
                    fVar18 = SetAnimation(piVar12[3],"CerbTailIdle",0);
                    piVar12[0x12] = (int)fVar18;
                    (*local_570)(piVar12[3]);
                    if (local_58b != false) {
                      FormatLogMessage("Playing Tail Loop Anim");
                    }
                  }
                }
                piVar5 = local_578;
              }
            }
            *(undefined1 *)((int)piVar12 + 0x12) = 1;
          }
        }
        else if (piVar12[6] == 0) {
          if (local_589 == '\0') goto LAB_4fc1a75a;
        }
        else if (local_589 != '\0') goto LAB_4fc1a75a;
LAB_4fc1aa57:
        piVar13 = piVar12 + 3;
        cVar3 = (*local_550)(*piVar13);
        if (cVar3 != '\0') {
          if ((-1 < piVar12[6]) && ((piVar12[6] != 0) == (bool)local_589)) {
            (*local_524)(*piVar13);
            *(undefined1 *)((int)piVar12 + 0x16) = 0;
            *(undefined1 *)((int)piVar12 + 0x11) = 0;
            *(undefined1 *)((int)piVar12 + 0x13) = 0;
            goto LAB_4fc1aa9c;
          }
          Build_Position_Rotation_Matrix
                    ((Matrix *)piVar12[0xb],(float)piVar12[0xc],(float)piVar12[0xd],(float)unaff_EDI
                     ,&unaff_ESI->right);
          Matrix_Multiply(&local_458,unaff_EDI,unaff_ESI);
          bVar4 = IsCraft((int)unaff_EDI,(int)unaff_ESI);
          if ((bVar4) || (cVar3 = (*local_510)(*piVar13), cVar3 != '\0')) {
            (*local_520)(*piVar13,piVar12 + 0x13,local_3c8);
          }
          else {
            (*local_520)(*piVar13,piVar12 + 0x13,local_3c8);
            (*local_4f4)(*piVar13,local_3c8,piVar12 + 0x13,1);
          }
          pMVar9 = (Matrix *)local_4d4;
          local_4d4._0_4_ = local_458.posit.x - local_398;
          local_4d4._4_4_ = local_458.posit.y - local_394;
          local_4d4._8_4_ = local_458.posit.z - local_390;
          Vector_Rotate(&local_4a4,pMVar9,&unaff_EDI->right);
          pVVar11 = Cross_Product(&pMVar9->right,&unaff_EDI->right,&unaff_ESI->right);
          local_4d4._24_4_ = (float)local_4d4._12_4_ + pVVar11->x;
          local_4d4._28_4_ = pVVar11->y + (float)local_4d4._16_4_;
          local_4d4._32_4_ = pVVar11->z + (float)local_4d4._20_4_;
          (*local_4f0)(*piVar13,local_4d4 + 0x18);
          local_58a = '\0';
          piVar5 = local_3c8;
          piVar17 = piVar12 + 0x13;
          for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
            *piVar17 = *piVar5;
            piVar5 = piVar5 + 1;
            piVar17 = piVar17 + 1;
          }
          memset(local_148,0,0x140);
          local_3dc[0] = 0.0;
          local_3dc[1] = 0.0;
          local_3dc[2] = 0.0;
          local_3dc[3] = 0.0;
          local_3dc[4] = 0.0;
          local_588 = local_148;
          iVar6 = 0;
          piVar12 = piVar12 + 0xf;
          local_56c = piVar12;
          do {
            if (((char)*piVar12 == '\0') || ((char)*piVar12 == '0')) {
              piVar5 = local_578;
            }
            else {
              memset(local_308,0,0x40);
              memset(local_208,0,0x40);
              piVar5 = local_578;
              cVar3 = (*local_534)(*local_578,iVar6 + 5,local_308);
              if (cVar3 != '\0') {
                cVar3 = (*local_534)(*piVar13,iVar6 + 5,local_208);
                if (cVar3 != '\0') {
                  fVar18 = GetCurLocalAmmo(*piVar5,iVar6);
                  local_3dc[iVar6] = fVar18;
                  iVar7 = (*local_530)(local_308,local_208);
                  if (iVar7 != 0) {
                    local_58a = '\x01';
                    (*local_4ec)(local_588,0x40,local_308);
                    local_588 = local_588 + 0x40;
                  }
                }
              }
            }
            piVar17 = local_55c;
            iVar6 = iVar6 + 1;
            piVar12 = (int *)((int)piVar12 + -1);
          } while (iVar6 < 5);
          if (local_58a != '\0') {
            ReplaceWeapons((int)local_3dc,(char (*) [64])0x0,(float *)unaff_EDI,(char *)unaff_ESI);
          }
          iVar6 = local_584;
          if (local_3fc[local_584] == 0) {
            iVar7 = (*local_548)(*piVar13);
            local_3fc[iVar6] = iVar7;
          }
          cVar3 = (*local_51c)(*piVar13);
          if (cVar3 != '\0') goto LAB_4fc1b2a7;
          piVar12 = (int *)((int)local_54c + (int)piVar5);
          local_588 = (undefined1 *)piVar12[7];
          if (*(char *)((int)piVar17 + 0x3e) == '\0') {
            if ((float)local_588 == ___real_00000000) goto LAB_4fc1b2a7;
            if (((local_554 == 0) || (local_579 != '\0')) ||
               ((*(char *)((int)piVar17 + 0x15) != '\0' &&
                ((cVar3 = (*local_510)(local_554), cVar3 == '\0' &&
                 (bVar4 = IsWeapon((int)unaff_EDI,(int)unaff_ESI), !bVar4)))))) {
              if (*(char *)((int)piVar17 + 0x11) != '\0') {
                (*local_544)(*piVar13,2,1,0,0,0);
                *(undefined1 *)((int)piVar17 + 0x11) = 0;
                if (local_58b != false) {
                  FormatLogMessage("Tap %x Switching to own AI control");
                }
              }
              if (((char)piVar17[4] == '\0') || (local_3fc[local_584] != 0)) goto LAB_4fc1af84;
              local_588 = (undefined1 *)piVar12[7];
              if (*(char *)((int)piVar17 + 0x15) == '\0') {
                iVar6 = 0x17;
              }
              else {
                iVar6 = 0x14;
              }
              VVar1.y = local_394;
              VVar1.x = local_398;
              VVar1.z = local_390;
              iVar7 = BZ1Helper::GetNearestObject
                                (local_564,VVar1,(float)local_588,local_558,4,true,iVar6,false,false
                                 ,0,0,(char *)0x0,(char *)0x0);
              iVar6 = local_584;
              local_3fc[local_584] = iVar7;
              if ((iVar7 != 0) && ((*local_568)(*piVar13,iVar7,1), local_58b != false)) {
                GetODFName((int)unaff_EDI);
                FormatLogMessage("Tap %x Set to Attack %08x \'%s\'");
              }
              piVar5 = local_578;
            }
            else {
              (*local_568)(*piVar13,local_554,1);
              *(undefined1 *)((int)piVar17 + 0x11) = 1;
              if (local_58b == false) {
LAB_4fc1af84:
                iVar6 = local_584;
              }
              else {
                GetODFName((int)unaff_EDI);
                iVar6 = local_584;
                FormatLogMessage("Tap %x Attacking Host Target: %08x \'%s\'");
              }
            }
            if (((char)piVar17[5] == '\0') &&
               ((((local_554 == 0 || (local_579 != '\0')) && (local_3fc[iVar6] != 0)) &&
                (iVar7 = 0, 0 < piVar5[1])))) {
              piVar12 = piVar5 + 3;
              do {
                if (((iVar7 != local_584) && (local_3fc[iVar6] == local_3fc[iVar7])) &&
                   ((*piVar12 != 0 && (local_3fc[iVar7] != 0)))) {
                  if (local_58b != false) {
                    GetODFName((int)unaff_EDI);
                    FormatLogMessage("Tap %d Target: %08x \'%s\', picking new target...");
                  }
                  local_56c = (int *)0x0;
                  local_528 = (float)piVar17[7] * (float)piVar17[7];
                  local_580 = *(int **)&local_564->m_ObjectHelper->HandleList;
                  if (0 < (*(int *)&(local_564->m_ObjectHelper->HandleList).field_0x4 -
                          (int)local_580) / 0x5c) {
                    local_588 = (undefined1 *)0x0;
                    goto LAB_4fc1b047;
                  }
                  break;
                }
                iVar7 = iVar7 + 1;
                piVar12 = piVar12 + 0x20;
              } while (iVar7 < piVar5[1]);
            }
            goto LAB_4fc1b258;
          }
          local_56c = (int *)0x0;
          local_528 = (float)local_588 * (float)local_588;
          local_580 = (int *)0x0;
          iVar6 = *(int *)&local_564->m_ObjectHelper->HandleList;
          if (0 < (*(int *)&(local_564->m_ObjectHelper->HandleList).field_0x4 - iVar6) / local_52c)
          {
            local_588 = (undefined1 *)0x0;
            do {
              local_55c = *(int **)(local_588 + iVar6);
              if ((*(int *)(local_588 + iVar6 + 0x10) == 1) &&
                 (cVar3 = (*local_560)(local_558,*(undefined4 *)(local_588 + iVar6 + 0x1c)),
                 cVar3 == '\0')) {
                fVar18 = GetDistance3DSquared(&unaff_EDI->right,&unaff_ESI->right);
                piVar5 = local_55c;
                if ((fVar18 < local_528) &&
                   (bVar4 = IsObjectFacingObject(piVar17[0x11],(int)unaff_EDI,(float)unaff_ESI),
                   bVar4)) {
                  iVar6 = piVar17[0x10];
                  local_588 = (undefined1 *)0x0;
                  local_580 = piVar5;
                  if (iVar6 == 0) {
                    pcVar19 = "CerbTailIdle";
LAB_4fc1b3ed:
                    local_588 = (undefined1 *)GetAnimationFrame(*piVar13,pcVar19);
                  }
                  else {
                    if (iVar6 == 1) {
                      pcVar19 = "CerbTailLeft";
                      goto LAB_4fc1b3ed;
                    }
                    if (iVar6 == 2) {
                      pcVar19 = "CerbTailRight";
                      goto LAB_4fc1b3ed;
                    }
                  }
                  pcVar14 = local_550;
                  if ((float)local_588 == (float)piVar17[0x12]) {
                    iVar6 = *piVar13;
                    cVar3 = (*local_550)(iVar6);
                    if (cVar3 == '\0') {
LAB_4fc1b48b:
                      bVar4 = false;
                    }
                    else {
                      cVar3 = (*pcVar14)(piVar5);
                      pcVar14 = local_540;
                      if (cVar3 == '\0') goto LAB_4fc1b48b;
                      (*local_540)(iVar6,local_388);
                      (*pcVar14)(piVar5,&local_498);
                      if ((local_498.posit.x - local_358) * local_388[0] +
                          (local_498.posit.z - local_350) * local_380 <= (float)local_4b0)
                      goto LAB_4fc1b48b;
                      bVar4 = true;
                    }
                    piVar13 = piVar12 + 3;
                    if (bVar4) {
                      piVar12[0x10] = 2;
                      pcVar19 = "CerbTailRight";
                    }
                    else {
                      piVar12[0x10] = 1;
                      pcVar19 = "CerbTailLeft";
                    }
                    local_56c = (int *)SetAnimation(*piVar13,pcVar19,0);
                    piVar12[0x12] = (int)local_56c;
                    (*local_570)(*piVar13);
                    (*local_568)(*piVar13,piVar5,1);
                    if (local_58b != false) {
                      FormatLogMessage("Playing Tail Swing Anim");
                    }
                  }
                  break;
                }
              }
              local_588 = local_588 + 0x5c;
              local_56c = (int *)((int)local_56c + 1);
              iVar6 = *(int *)&local_564->m_ObjectHelper->HandleList;
            } while ((int)local_56c <
                     (*(int *)&(local_564->m_ObjectHelper->HandleList).field_0x4 - iVar6) /
                     local_52c);
          }
          iVar6 = piVar12[0x10];
          piVar17 = piVar12;
          if ((iVar6 == 0) || (local_580 != (int *)0x0)) goto LAB_4fc1b2a7;
          local_588 = (undefined1 *)0x0;
          if (iVar6 == 1) {
            pcVar19 = "CerbTailLeft";
LAB_4fc1b523:
            local_588 = (undefined1 *)GetAnimationFrame(*piVar13,pcVar19);
          }
          else if (iVar6 == 2) {
            pcVar19 = "CerbTailRight";
            goto LAB_4fc1b523;
          }
          if ((float)local_588 != (float)piVar12[0x12]) goto LAB_4fc1b2a7;
          (*local_544)(*piVar13,2,1,0,0,0);
          piVar12[0x10] = 0;
          fVar18 = SetAnimation(*piVar13,"CerbTailIdle",0);
          pcVar14 = local_570;
          piVar12[0x12] = (int)fVar18;
          (*local_570)(*piVar13);
          if (local_58b != false) {
            FormatLogMessage("Playing Tail Idle Anim");
          }
          goto LAB_4fc1b2ab;
        }
        goto LAB_4fc1aa9c;
      }
LAB_4fc1aab2:
      local_578 = piVar5 + 0x103;
    } while (local_578 != *(int **)&(local_514->AttacherList).field_0x4);
  }
  return;
LAB_4fc1b047:
  do {
    piVar12 = *(int **)((int)local_580 + (int)local_588);
    cVar3 = (*local_560)(local_558,*(undefined4 *)((int)(local_580 + 7) + (int)local_588));
    if (((cVar3 == '\0') && (iVar6 = (*local_4e8)(piVar12), 0 < iVar6)) &&
       ((fVar18 = GetDistance3DSquared(&unaff_EDI->right,&unaff_ESI->right), fVar18 <= local_528 &&
        (((*(char *)((int)piVar17 + 0x15) == '\0' ||
          (*(int *)((int)(local_580 + 4) + (int)local_588) == 4)) ||
         (*(int *)((int)(local_580 + 4) + (int)local_588) == 0x10)))))) {
      local_580 = (int *)0x0;
      if (0 < piVar5[1]) {
        local_54c = piVar5 + 3;
        do {
          cVar3 = (*local_550)(*local_54c);
          if (((cVar3 != '\0') &&
              (local_55c = (int *)local_3fc[(int)local_580], local_55c != (int *)0x0)) &&
             (piVar12 == local_55c)) {
            if (local_58b != false) {
              memset(local_188,0,0x40);
              memset(local_1c8,0,0x40);
              GetODFName((int)unaff_EDI,(char *)unaff_ESI);
              GetODFName((int)unaff_EDI,(char *)unaff_ESI);
              FormatLogMessage(
                              "Tap: %d Target %08x \'%s\' matches existing Target, Tap %d Target: %08x \'%s\'"
                              );
            }
            goto LAB_4fc1b168;
          }
          local_580 = (int *)((int)local_580 + 1);
          local_54c = local_54c + 0x20;
        } while ((int)local_580 < piVar5[1]);
      }
      memset(local_388,0,0x40);
      (*local_534)(*piVar13,4,local_388);
      iVar6 = (*local_530)(local_388,"CLASS_WALKER");
      if ((iVar6 != 0) ||
         (bVar4 = IsObjectFacingObject(local_4e0,(int)unaff_EDI,(float)unaff_ESI), bVar4)) {
        local_3fc[local_584] = (int)piVar12;
        (*local_568)(*piVar13,piVar12,1);
        if (local_58b != false) {
          GetODFName((int)unaff_EDI);
          FormatLogMessage("Tap %d Targeting New Target: %08x \'%s\'");
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
  cVar3 = (*local_4dc)(*piVar5);
  if ((cVar3 == '\0') && (cVar3 = (*local_51c)(*piVar5), cVar3 == '\0')) {
    local_58a = '\x01';
  }
  else {
    local_58a = '\0';
  }
  if (local_58a != *(char *)((int)piVar17 + 0x13)) {
    if (local_58a != '\0') {
      (*local_544)(*piVar13,2,1,0,0,0);
    }
    *(char *)((int)piVar17 + 0x13) = local_58a;
  }
LAB_4fc1b2a7:
  piVar12 = piVar17;
  pcVar14 = local_570;
LAB_4fc1b2ab:
  if (*(char *)((int)piVar12 + 0x16) == '\0') {
    if (local_589 != '\0') {
      *(undefined1 *)((int)piVar12 + 0x16) = 1;
      pcVar19 = "deploy";
      goto LAB_4fc1b2cd;
    }
  }
  else if (local_589 == '\0') {
    *(undefined1 *)((int)piVar12 + 0x16) = 0;
    pcVar19 = "undeploy";
LAB_4fc1b2cd:
    SetAnimation(*piVar13,pcVar19,1);
    (*pcVar14)(*piVar13);
    (*local_518)(*piVar13);
    piVar5 = local_578;
LAB_4fc1aa9c:
    goto LAB_4fc1aaa0;
  }
  piVar5 = local_578;
LAB_4fc1aaa0:
  local_584 = local_584 + 1;
  if (piVar5[1] <= local_584) goto LAB_4fc1aab2;
  goto LAB_4fc1a726;
}

