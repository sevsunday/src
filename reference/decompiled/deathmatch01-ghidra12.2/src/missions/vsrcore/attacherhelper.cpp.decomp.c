// Reconstructed by Ghidra from deathmatch01.dll + deathmatch01.pdb
// Original source file: /e:/github/vsr_dll_source/missions/vsrcore/attacherhelper.cpp
// Functions are ordered by original source line. This is decompiler
// output, not the author's source: names/types come from the PDB,
// local variable names and control flow are reconstructed.


// ---------------------------------------------------------------------
// `dynamic_initializer_for_'TempAttacherBuffer''  @ 4fc01605  lines 7-7


void __cdecl _dynamic_initializer_for__TempAttacherBuffer__(void)

{
  atexit(_dynamic_atexit_destructor_for__TempAttacherBuffer__);
  return;
}


// ---------------------------------------------------------------------
// AttacherHelper::PostLoad  @ 4fc1952d  lines 35-60


bool __thiscall AttacherHelper::PostLoad(AttacherHelper *this,bool param_1)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  AttacherClass *unaff_ESI;
  int *piVar5;
  AttacherClass *unaff_EDI;
  
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
  if ((int)(TempAttacherBuffer._4_4_ - TempAttacherBuffer._0_4_) / 0x40c == iVar4) {
    iVar3 = 0;
    if (0 < iVar4) {
      do {
        bVar1 = ::operator==(unaff_EDI,unaff_ESI);
        if (!bVar1) {
          FormatLogMessage("AttacherList Index Mismatch: %d");
          return true;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < (*(int *)&(this->AttacherList).field_0x4 - *(int *)&this->AttacherList) /
                       0x40c);
    }
  }
  else {
    FormatLogMessage("AttacherList Size Mismatch! Old: %d New: %d");
  }
  return true;
}


// ---------------------------------------------------------------------
// AttacherHelper::AddAttacherObject  @ 4fc195ea  lines 79-194


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

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
          uVar12 = 0x14;
          sprintf_s<64>(pacVar10,"AttachedIndependent%d");
          GetODFBool("GameObjectClass",local_304,(char *)(pfVar7 + -9),(char *)0x1,(bool *)pacVar10,
                     (bool)uVar12);
          pacVar10 = &local_304;
          uVar12 = 0x2c;
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
          uVar12 = 0x60;
          sprintf_s<64>(pacVar10,"AttachedPDSMode%d");
          GetODFBool("GameObjectClass",local_304,(char *)((int)pfVar7 + -0x1f),(char *)0x0,
                     (bool *)pacVar10,(bool)uVar12);
          pacVar10 = &local_304;
          pcVar9 = "AttachedWeaponSymmetryMask%d";
          sprintf_s<64>(pacVar10,"AttachedWeaponSymmetryMask%d");
          GetODFString("GameObjectClass",local_304,(char *)0x6,(char *)(pfVar7 + 1),0x4fc5b494,
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
          local_308 = (float)___real_3f91df46a0000000;
          local_310 = *pfVar6 * local_308;
          local_30c = local_334[-1] * local_308;
          local_308 = local_308 * *local_334;
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
// AttacherHelper::Execute  @ 4fc19adf  lines 197-686


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall AttacherHelper::Execute(AttacherHelper *this,BZ1Helper *param_1)

{
  Vector VVar1;
  char *pcVar2;
  code *pcVar3;
  code *pcVar4;
  char cVar5;
  bool bVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  Matrix *pMVar11;
  uint uVar12;
  Vector *pVVar13;
  int iVar14;
  int iVar15;
  char *extraout_ECX;
  char *extraout_ECX_00;
  int *piVar16;
  int *piVar17;
  Matrix *unaff_ESI;
  code *pcVar18;
  Matrix *unaff_EDI;
  float *pfVar19;
  char *pcVar20;
  float fVar21;
  char *pcVar22;
  undefined1 uStack_580;
  bool local_57f;
  char local_57e;
  char local_57d;
  int *local_57c;
  int *local_578;
  char local_571;
  char *local_570;
  char local_569;
  code *local_568;
  int *local_564;
  BZ1Helper *local_560;
  code *local_55c;
  code *local_558;
  int local_554;
  code *local_550;
  int *local_54c;
  int local_548;
  code *local_544;
  code *local_540;
  uint local_53c;
  int local_538;
  code *local_534;
  code *local_530;
  code *local_52c;
  float local_528;
  code *local_524;
  code *local_520;
  code *local_51c;
  code *local_518;
  code *local_514;
  AttacherHelper *local_510;
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
  int local_148 [81];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)&uStack_580;
  local_560 = param_1;
  piVar16 = *(int **)&this->AttacherList;
  local_57f = BZ1Helper::Logging;
  local_550 = IsAround_exref;
  local_520 = RemoveObject_exref;
  local_578 = piVar16;
  local_55c = (code *)piVar16;
  local_540 = (code *)piVar16;
  local_510 = this;
  while( true ) {
    pcVar18 = local_55c;
    piVar7 = *(int **)&(local_510->AttacherList).field_0x4;
    if (local_55c == (code *)piVar7) break;
    cVar5 = (*local_550)(*(int *)local_55c);
    pcVar3 = local_520;
    if (cVar5 == '\0') {
      iVar8 = 0;
      if (0 < *(int *)((int)pcVar18 + 4)) {
        piVar16 = (int *)((int)pcVar18 + 0xc);
        do {
          (*pcVar3)(*piVar16);
          iVar8 = iVar8 + 1;
          piVar16 = piVar16 + 0x20;
        } while (iVar8 < *(int *)((int)pcVar18 + 4));
        piVar16 = local_578;
      }
    }
    else {
      if (local_540 != pcVar18) {
        for (iVar8 = 0x103; iVar8 != 0; iVar8 = iVar8 + -1) {
          *piVar16 = *(int *)pcVar18;
          pcVar18 = (code *)((int)pcVar18 + 4);
          piVar16 = piVar16 + 1;
        }
        pcVar18 = local_55c;
        piVar16 = local_578;
      }
      local_578 = piVar16 + 0x103;
      piVar16 = local_578;
    }
    local_55c = (code *)((int)pcVar18 + 0x40c);
  }
  if (piVar16 != piVar7) {
    *(int **)&(local_510->AttacherList).field_0x4 = piVar16;
    piVar7 = piVar16;
  }
  local_54c = *(int **)&local_510->AttacherList;
  if (local_54c != piVar7) {
    local_508 = GetOmega_exref;
    local_524 = GetTeamNum_exref;
    local_504 = IsDeployed_exref;
    local_4e4 = DoesODFExist_exref;
    local_500 = BuildObject_exref;
    local_4fc = SetIndependence_exref;
    local_558 = _stricmp_exref;
    local_568 = StartAnimation_exref;
    local_50c = IsPerson_exref;
    local_51c = SetLastCurrentPosition_exref;
    local_4f4 = SetInterpolablePosition_exref;
    local_4f0 = SetVelocity_exref;
    local_534 = GetObjInfo_exref;
    local_518 = IsPlayer_exref;
    local_544 = Attack_exref;
    local_4f8 = ___real_3f19999a;
    local_530 = SetCommand_exref;
    local_4e8 = GetMaxHealth_exref;
    local_4e0 = ___real_40490fdb;
    local_4dc = IsAliveAndPilot2_exref;
    local_514 = Deploy_exref;
    local_4b0 = 0.0;
    local_4d8 = GetVelocity_exref;
    local_540 = GetTarget_exref;
    local_55c = IsTeamAllied_exref;
    local_52c = GetPosition_exref;
    local_4ec = strcpy_s_exref;
    do {
      pcVar4 = local_52c;
      pcVar3 = local_540;
      piVar16 = local_54c;
      pcVar18 = local_55c;
      (*local_4d8)(local_4d4 + 0xc,*local_54c);
      (*local_508)(&local_4a4,*piVar16);
      iVar8 = (*pcVar3)(*piVar16);
      local_548 = iVar8;
      (*pcVar4)(*piVar16,&local_458);
      iVar9 = (*local_524)(*piVar16);
      local_571 = '\0';
      local_554 = iVar9;
      if (iVar8 != 0) {
        uVar10 = (*local_524)(iVar8);
        local_571 = (*pcVar18)(iVar9,uVar10);
      }
      iVar8 = *piVar16;
      piVar7 = local_3fc;
      for (iVar9 = 8; iVar9 != 0; iVar9 = iVar9 + -1) {
        *piVar7 = 0;
        piVar7 = piVar7 + 1;
      }
      local_57d = (*local_504)(iVar8);
      local_570 = (char *)0x0;
      if (0 < piVar16[1]) {
LAB_4fc19d6a:
        pcVar2 = local_570;
        iVar8 = (int)local_570 * 0x80;
        if (*(char *)(iVar8 + 0x12 + (int)piVar16) != '\0') goto LAB_4fc1a0bc;
        if (piVar16[(int)local_570 * 0x20 + 6] < 0) {
LAB_4fc19d95:
          memset(local_348,0,0x40);
          memset(local_2c8,0,0x40);
          sprintf_s<64>(&local_2c8,"AttachedObject%d");
          iVar9 = GetODFString((int)local_2c8,(char *)0x40,local_348,0,(char *)unaff_EDI,
                               (char *)unaff_ESI);
          if (iVar9 != 0) {
            if (local_348[0] != '\0') {
              cVar5 = (*local_4e4)(local_348);
              if (cVar5 == '\0') {
                FormatLogMessage("ERROR: Attacher ODF \'%s\' Doesn\'t Exist!");
              }
              else {
                (*local_52c)(*piVar16,&local_498);
                Build_Position_Rotation_Matrix
                          ((Matrix *)piVar16[(int)pcVar2 * 0x20 + 0xb],
                           (float)piVar16[(int)pcVar2 * 0x20 + 0xc],
                           (float)piVar16[(int)pcVar2 * 0x20 + 0xd],(float)unaff_EDI,
                           &unaff_ESI->right);
                pMVar11 = Matrix_Multiply(&local_498,unaff_EDI,unaff_ESI);
                pfVar19 = (float *)(piVar16 + (int)pcVar2 * 0x20 + 0x13);
                for (iVar9 = 0x10; iVar9 != 0; iVar9 = iVar9 + -1) {
                  *pfVar19 = (pMVar11->right).x;
                  pMVar11 = (Matrix *)&(pMVar11->right).y;
                  pfVar19 = pfVar19 + 1;
                }
                iVar9 = (*local_500)(local_348,local_554,piVar16 + (int)pcVar2 * 0x20 + 0x13);
                piVar16 = local_54c;
                local_54c[(int)pcVar2 * 0x20 + 3] = iVar9;
                (*local_4fc)(iVar9,0);
                memset(local_288,0,0x40);
                GetODFString(0x4fc56358,(char *)0x40,local_288,0,(char *)unaff_EDI,(char *)unaff_ESI
                            );
                uVar12 = Hash((char *)unaff_EDI,(uint)unaff_ESI);
                if (uVar12 == 0xc17ac6e3) {
                  *(undefined1 *)(iVar8 + 0x3e + (int)piVar16) = 1;
                  GetODFFloat(0x4fc5b4c4,(char *)(piVar16 + (int)pcVar2 * 0x20 + 0x11),local_4f8,
                              (float *)unaff_EDI,(float)unaff_ESI);
                  local_569 = '\0';
                  local_57e = '\0';
                  local_53c = local_53c & 0xffffff00;
                  memset(local_3c8,0,0x40);
                  local_538 = 0;
                  GetODFInt(0x4fc5b4d8,(char *)&local_538,(char *)0x0,(int *)unaff_EDI,
                            (int)unaff_ESI);
                  iVar9 = 1;
                  if (1 < local_538 + 1) {
                    do {
                      memset(local_248,0,0x40);
                      sprintf_s<64>(&local_248,"animName%d");
                      iVar14 = GetODFString((int)local_248,(char *)0x40,(char *)local_3c8,0,
                                            (char *)unaff_EDI,(char *)unaff_ESI);
                      if (iVar14 != 0) {
                        iVar14 = (*local_558)(local_3c8,"CerbTailIdle");
                        if (iVar14 == 0) {
                          local_569 = '\x01';
                        }
                        else {
                          iVar14 = (*local_558)(local_3c8,"CerbTailLeft");
                          if (iVar14 == 0) {
                            local_57e = '\x01';
                          }
                          else {
                            iVar14 = (*local_558)(local_3c8,"CerbTailRight");
                            local_53c = local_53c & 0xff;
                            if (iVar14 == 0) {
                              local_53c = 1;
                            }
                          }
                          if (local_569 == '\0') goto LAB_4fc1a052;
                        }
                        if ((local_57e != '\0') && ((char)local_53c != '\0')) {
                          *(undefined1 *)(iVar8 + 0x3f + (int)piVar16) = 1;
                          break;
                        }
                      }
LAB_4fc1a052:
                      iVar9 = iVar9 + 1;
                    } while (iVar9 < local_538 + 1);
                  }
                  if (*(char *)(iVar8 + 0x3f + (int)piVar16) != '\0') {
                    fVar21 = SetAnimation(piVar16[(int)pcVar2 * 0x20 + 3],"CerbTailIdle",0);
                    piVar16[(int)pcVar2 * 0x20 + 0x12] = (int)fVar21;
                    (*local_568)(piVar16[(int)pcVar2 * 0x20 + 3]);
                    if (local_57f != false) {
                      FormatLogMessage("Playing Tail Loop Anim");
                    }
                  }
                }
              }
            }
            *(undefined1 *)(iVar8 + 0x12 + (int)piVar16) = 1;
          }
        }
        else if (piVar16[(int)local_570 * 0x20 + 6] == 0) {
          if (local_57d == '\0') goto LAB_4fc19d95;
        }
        else if (local_57d != '\0') goto LAB_4fc19d95;
LAB_4fc1a0bc:
        cVar5 = (*local_550)(piVar16[(int)pcVar2 * 0x20 + 3]);
        pcVar22 = pcVar2;
        if (cVar5 != '\0') {
          if ((-1 < piVar16[(int)pcVar2 * 0x20 + 6]) &&
             ((piVar16[(int)pcVar2 * 0x20 + 6] != 0) == (bool)local_57d)) {
            (*local_520)(piVar16[(int)pcVar2 * 0x20 + 3]);
            *(undefined1 *)(iVar8 + 0x16 + (int)piVar16) = 0;
            *(undefined1 *)(iVar8 + 0x11 + (int)piVar16) = 0;
            *(undefined1 *)(iVar8 + 0x13 + (int)piVar16) = 0;
            goto LAB_4fc1ab6c;
          }
          Build_Position_Rotation_Matrix
                    ((Matrix *)piVar16[(int)pcVar2 * 0x20 + 0xb],
                     (float)piVar16[(int)pcVar2 * 0x20 + 0xc],
                     (float)piVar16[(int)pcVar2 * 0x20 + 0xd],(float)unaff_EDI,&unaff_ESI->right);
          Matrix_Multiply(&local_458,unaff_EDI,unaff_ESI);
          bVar6 = IsCraft((int)unaff_EDI,(int)unaff_ESI);
          if ((bVar6) || (cVar5 = (*local_50c)(piVar16[(int)pcVar2 * 0x20 + 3]), cVar5 != '\0')) {
            piVar7 = piVar16 + (int)pcVar2 * 0x20 + 0x13;
            (*local_51c)(piVar16[(int)pcVar2 * 0x20 + 3],piVar7,local_3c8);
          }
          else {
            piVar7 = piVar16 + (int)pcVar2 * 0x20 + 0x13;
            (*local_51c)(piVar16[(int)pcVar2 * 0x20 + 3],piVar7,local_3c8);
            (*local_4f4)(piVar16[(int)pcVar2 * 0x20 + 3],local_3c8,piVar7,1);
          }
          pMVar11 = (Matrix *)local_4d4;
          local_4d4._0_4_ = local_458.posit.x - local_398;
          local_4d4._4_4_ = local_458.posit.y - local_394;
          local_4d4._8_4_ = local_458.posit.z - local_390;
          Vector_Rotate(&local_4a4,pMVar11,&unaff_EDI->right);
          pVVar13 = Cross_Product(&pMVar11->right,&unaff_EDI->right,&unaff_ESI->right);
          local_564 = (int *)(pVVar13->y + (float)local_4d4._16_4_);
          local_578 = (int *)(pVVar13->z + (float)local_4d4._20_4_);
          local_4d4._24_4_ = (float)local_4d4._12_4_ + pVVar13->x;
          local_4d4._28_4_ = local_564;
          local_4d4._32_4_ = local_578;
          (*local_4f0)(piVar16[(int)pcVar2 * 0x20 + 3],local_4d4 + 0x18);
          local_57e = '\0';
          piVar16 = local_3c8;
          for (iVar9 = 0x10; iVar9 != 0; iVar9 = iVar9 + -1) {
            *piVar7 = *piVar16;
            piVar16 = piVar16 + 1;
            piVar7 = piVar7 + 1;
          }
          memset(local_148,0,0x140);
          piVar16 = local_54c;
          local_3dc[0] = 0.0;
          local_3dc[1] = 0.0;
          local_3dc[2] = 0.0;
          local_3dc[3] = 0.0;
          local_3dc[4] = 0.0;
          local_578 = local_148;
          iVar9 = 0;
          local_57c = local_54c + (int)pcVar2 * 0x20 + 0xf;
          do {
            if (((char)*local_57c != '\0') && ((char)*local_57c != '0')) {
              memset(local_308,0,0x40);
              memset(local_208,0,0x40);
              cVar5 = (*local_534)(*piVar16,iVar9 + 5,local_308);
              if ((cVar5 != '\0') &&
                 (cVar5 = (*local_534)(piVar16[(int)pcVar2 * 0x20 + 3],iVar9 + 5,local_208),
                 cVar5 != '\0')) {
                fVar21 = GetCurLocalAmmo(*piVar16,iVar9);
                local_3dc[iVar9] = fVar21;
                iVar14 = (*local_558)(local_308,local_208);
                piVar7 = local_578;
                if (iVar14 != 0) {
                  local_57e = '\x01';
                  (*local_4ec)(local_578,0x40,local_308);
                  local_578 = piVar7 + 0x10;
                }
              }
            }
            iVar9 = iVar9 + 1;
            local_57c = (int *)((int)local_57c + -1);
          } while (iVar9 < 5);
          if (local_57e != '\0') {
            ReplaceWeapons((int)local_3dc,(char (*) [64])0x0,(float *)unaff_EDI,(char *)unaff_ESI);
          }
          pcVar22 = local_570;
          if (local_3fc[(int)local_570] == 0) {
            iVar9 = (*local_540)(piVar16[(int)pcVar2 * 0x20 + 3]);
            local_3fc[(int)pcVar22] = iVar9;
          }
          pcVar20 = (char *)piVar16[(int)pcVar2 * 0x20 + 3];
          cVar5 = (*local_518)();
          iVar9 = local_548;
          if (cVar5 != '\0') goto LAB_4fc1ab13;
          piVar7 = (int *)piVar16[(int)pcVar2 * 0x20 + 7];
          if (*(char *)(iVar8 + 0x3e + (int)piVar16) == '\0') {
            local_57c = piVar7;
            if ((float)piVar7 == ___real_00000000) goto LAB_4fc1ab13;
            if ((local_548 == 0) || (local_571 != '\0')) {
LAB_4fc1a497:
              if (*(char *)(iVar8 + 0x11 + (int)piVar16) != '\0') {
                (*local_530)(piVar16[(int)pcVar2 * 0x20 + 3],2,1,0,0,0);
                *(undefined1 *)(iVar8 + 0x11 + (int)piVar16) = 0;
                pcVar20 = extraout_ECX_00;
                if (local_57f != false) {
                  pcVar20 = pcVar22;
                  FormatLogMessage("Tap %x Switching to own AI control");
                }
              }
              if (((char)piVar16[(int)pcVar2 * 0x20 + 4] != '\0') && (local_3fc[(int)pcVar22] == 0))
              {
                local_57c = (int *)piVar16[(int)pcVar2 * 0x20 + 7];
                if (*(char *)(iVar8 + 0x15 + (int)piVar16) == '\0') {
                  iVar9 = 0x17;
                }
                else {
                  iVar9 = 0x14;
                }
                VVar1.y = local_394;
                VVar1.x = local_398;
                VVar1.z = local_390;
                iVar9 = BZ1Helper::GetNearestObject
                                  (local_560,VVar1,(float)local_57c,local_554,4,true,iVar9,
                                   SUB41(pcVar20,0),SUB41(pcVar20,0),0,0,(char *)0x0,pcVar20);
                piVar16 = local_54c;
                local_3fc[(int)pcVar22] = iVar9;
                if ((iVar9 != 0) &&
                   ((*local_544)(local_54c[(int)pcVar2 * 0x20 + 3],iVar9,1), local_57f != false)) {
                  GetODFName((int)unaff_EDI);
                  FormatLogMessage("Tap %x Set to Attack %08x \'%s\'");
                }
                iVar9 = local_548;
              }
            }
            else {
              if ((*(char *)(iVar8 + 0x15 + (int)piVar16) != '\0') &&
                 (cVar5 = (*local_50c)(local_548), cVar5 == '\0')) {
                bVar6 = IsWeapon((int)unaff_EDI,(int)unaff_ESI);
                pcVar20 = extraout_ECX;
                if (!bVar6) goto LAB_4fc1a497;
              }
              (*local_544)(piVar16[(int)pcVar2 * 0x20 + 3],iVar9,1);
              *(undefined1 *)(iVar8 + 0x11 + (int)piVar16) = 1;
              if (local_57f != false) {
                GetODFName((int)unaff_EDI);
                FormatLogMessage("Tap %x Attacking Host Target: %08x \'%s\'");
              }
            }
            if (((char)piVar16[(int)pcVar2 * 0x20 + 5] == '\0') &&
               ((iVar9 == 0 || (local_571 != '\0')))) {
              piVar7 = local_3fc + (int)pcVar22;
              if (*piVar7 != 0) {
                pcVar20 = (char *)0x0;
                if (0 < piVar16[1]) {
                  piVar17 = piVar16 + 3;
                  do {
                    if (pcVar20 != pcVar22) {
                      if (((*piVar7 == local_3fc[(int)pcVar20]) && (*piVar17 != 0)) &&
                         (local_3fc[(int)pcVar20] != 0)) {
                        if (local_57f != false) {
                          GetODFName((int)unaff_EDI);
                          FormatLogMessage("Tap %d Target: %08x \'%s\', picking new target...");
                        }
                        local_564 = (int *)0x0;
                        local_528 = (float)piVar16[(int)pcVar2 * 0x20 + 7] *
                                    (float)piVar16[(int)pcVar2 * 0x20 + 7];
                        iVar9 = *(int *)&local_560->m_ObjectHelper->HandleList;
                        if ((*(int *)&(local_560->m_ObjectHelper->HandleList).field_0x4 - iVar9) /
                            0x5c < 1) goto LAB_4fc1a820;
                        local_57c = (int *)0x0;
                        goto LAB_4fc1a628;
                      }
                      pcVar22 = local_570;
                    }
                    pcVar20 = pcVar20 + 1;
                    piVar17 = piVar17 + 0x20;
                  } while ((int)pcVar20 < piVar16[1]);
                }
              }
            }
            goto LAB_4fc1a824;
          }
          piVar17 = (int *)0x0;
          local_57c = (int *)0x0;
          local_528 = (float)piVar7 * (float)piVar7;
          local_578 = (int *)0x0;
          iVar9 = *(int *)&local_560->m_ObjectHelper->HandleList;
          piVar7 = piVar17;
          if (0 < (*(int *)&(local_560->m_ObjectHelper->HandleList).field_0x4 - iVar9) / 0x5c) {
            do {
              local_564 = *(int **)(iVar9 + (int)piVar17);
              if ((*(int *)(iVar9 + 0x10 + (int)piVar17) == 1) &&
                 (cVar5 = (*local_55c)(local_554,*(undefined4 *)(iVar9 + 0x1c + (int)piVar17)),
                 cVar5 == '\0')) {
                fVar21 = GetDistance3DSquared(&unaff_EDI->right,&unaff_ESI->right);
                piVar7 = local_564;
                if ((fVar21 < local_528) &&
                   (bVar6 = IsObjectFacingObject
                                      (piVar16[(int)pcVar2 * 0x20 + 0x11],(int)unaff_EDI,
                                       (float)unaff_ESI), bVar6)) {
                  iVar9 = piVar16[(int)pcVar2 * 0x20 + 0x10];
                  local_57c = (int *)0x0;
                  local_578 = piVar7;
                  if (iVar9 == 0) {
                    pcVar22 = "CerbTailIdle";
LAB_4fc1a962:
                    local_57c = (int *)GetAnimationFrame(piVar16[(int)pcVar2 * 0x20 + 3],pcVar22);
                  }
                  else {
                    if (iVar9 == 1) {
                      pcVar22 = "CerbTailLeft";
                      goto LAB_4fc1a962;
                    }
                    if (iVar9 == 2) {
                      pcVar22 = "CerbTailRight";
                      goto LAB_4fc1a962;
                    }
                  }
                  if ((float)local_57c != (float)piVar16[(int)pcVar2 * 0x20 + 0x12])
                  goto LAB_4fc1aa6e;
                  iVar9 = piVar16[(int)pcVar2 * 0x20 + 3];
                  cVar5 = (*local_550)(iVar9);
                  if (cVar5 == '\0') {
LAB_4fc1a9ff:
                    bVar6 = false;
                  }
                  else {
                    cVar5 = (*local_550)(piVar7);
                    pcVar18 = local_52c;
                    if (cVar5 == '\0') goto LAB_4fc1a9ff;
                    (*local_52c)(iVar9,local_388);
                    (*pcVar18)(piVar7,&local_498);
                    if ((local_498.posit.z - local_350) * local_380 +
                        (local_498.posit.x - local_358) * local_388[0] <= (float)local_4b0)
                    goto LAB_4fc1a9ff;
                    bVar6 = true;
                  }
                  if (bVar6) {
                    piVar16[(int)pcVar2 * 0x20 + 0x10] = 2;
                    pcVar22 = "CerbTailRight";
                  }
                  else {
                    piVar16[(int)pcVar2 * 0x20 + 0x10] = 1;
                    pcVar22 = "CerbTailLeft";
                  }
                  local_564 = (int *)SetAnimation(piVar16[(int)pcVar2 * 0x20 + 3],pcVar22,0);
                  piVar16[(int)pcVar2 * 0x20 + 0x12] = (int)local_564;
                  (*local_568)(piVar16[(int)pcVar2 * 0x20 + 3]);
                  (*local_544)(piVar16[(int)pcVar2 * 0x20 + 3],piVar7,1);
                  if (local_57f != false) {
                    FormatLogMessage("Playing Tail Swing Anim");
                  }
                  break;
                }
              }
              piVar17 = piVar17 + 0x17;
              local_57c = (int *)((int)local_57c + 1);
              iVar9 = *(int *)&local_560->m_ObjectHelper->HandleList;
            } while ((int)local_57c <
                     (*(int *)&(local_560->m_ObjectHelper->HandleList).field_0x4 - iVar9) / 0x5c);
            piVar7 = local_578;
          }
LAB_4fc1aa6e:
          iVar9 = piVar16[(int)pcVar2 * 0x20 + 0x10];
          if ((iVar9 == 0) || (piVar7 != (int *)0x0)) {
LAB_4fc1ab0f:
            pcVar22 = local_570;
            goto LAB_4fc1ab13;
          }
          local_578 = (int *)0x0;
          if (iVar9 == 1) {
            pcVar22 = "CerbTailLeft";
LAB_4fc1aa9c:
            local_578 = (int *)GetAnimationFrame(piVar16[(int)pcVar2 * 0x20 + 3],pcVar22);
          }
          else if (iVar9 == 2) {
            pcVar22 = "CerbTailRight";
            goto LAB_4fc1aa9c;
          }
          if ((float)local_578 != (float)piVar16[(int)pcVar2 * 0x20 + 0x12]) goto LAB_4fc1ab0f;
          (*local_530)(piVar16[(int)pcVar2 * 0x20 + 3],2,1,0,0,0);
          piVar16[(int)pcVar2 * 0x20 + 0x10] = 0;
          fVar21 = SetAnimation(piVar16[(int)pcVar2 * 0x20 + 3],"CerbTailIdle",0);
          pcVar18 = local_568;
          piVar16[(int)pcVar2 * 0x20 + 0x12] = (int)fVar21;
          (*local_568)(piVar16[(int)pcVar2 * 0x20 + 3]);
          if (local_57f != false) {
            FormatLogMessage("Playing Tail Idle Anim");
          }
          pcVar22 = local_570;
          goto LAB_4fc1ab17;
        }
        goto LAB_4fc1ab6c;
      }
LAB_4fc1ab7a:
      local_54c = piVar16 + 0x103;
    } while (local_54c != *(int **)&(local_510->AttacherList).field_0x4);
  }
  return;
LAB_4fc1a628:
  do {
    iVar14 = *(int *)((int)local_57c + iVar9);
    cVar5 = (*local_55c)(local_554,*(undefined4 *)((int)local_57c + iVar9 + 0x1c));
    if ((((cVar5 == '\0') && (iVar15 = (*local_4e8)(iVar14), 0 < iVar15)) &&
        (fVar21 = GetDistance3DSquared(&unaff_EDI->right,&unaff_ESI->right), fVar21 <= local_528))
       && (((*(char *)(iVar8 + 0x15 + (int)piVar16) == '\0' ||
            (*(int *)((int)local_57c + iVar9 + 0x10) == 4)) ||
           (*(int *)((int)local_57c + iVar9 + 0x10) == 0x10)))) {
      iVar9 = 0;
      if (0 < piVar16[1]) {
        local_578 = piVar16 + 3;
        do {
          cVar5 = (*local_550)(*local_578);
          if (((cVar5 != '\0') && (local_3fc[iVar9] != 0)) && (iVar14 == local_3fc[iVar9])) {
            if (local_57f != false) {
              memset(local_188,0,0x40);
              memset(local_1c8,0,0x40);
              GetODFName((int)unaff_EDI,(char *)unaff_ESI);
              GetODFName((int)unaff_EDI,(char *)unaff_ESI);
              FormatLogMessage(
                              "Tap: %d Target %08x \'%s\' matches existing Target, Tap %d Target: %08x \'%s\'"
                              );
            }
            goto LAB_4fc1a734;
          }
          iVar9 = iVar9 + 1;
          local_578 = local_578 + 0x20;
        } while (iVar9 < piVar16[1]);
      }
      memset(local_388,0,0x40);
      (*local_534)(piVar16[(int)pcVar2 * 0x20 + 3],4,local_388);
      iVar9 = (*local_558)(local_388,"CLASS_WALKER");
      if ((iVar9 != 0) ||
         (bVar6 = IsObjectFacingObject(local_4e0,(int)unaff_EDI,(float)unaff_ESI), bVar6)) {
        pcVar22 = local_570;
        iVar9 = piVar16[(int)pcVar2 * 0x20 + 3];
        local_3fc[(int)local_570] = iVar14;
        (*local_544)(iVar9,iVar14,1);
        if (local_57f != false) {
          GetODFName((int)unaff_EDI);
          FormatLogMessage("Tap %d Targeting New Target: %08x \'%s\'");
        }
        goto LAB_4fc1a824;
      }
    }
LAB_4fc1a734:
    local_564 = (int *)((int)local_564 + 1);
    local_57c = local_57c + 0x17;
    iVar9 = *(int *)&local_560->m_ObjectHelper->HandleList;
  } while ((int)local_564 <
           (*(int *)&(local_560->m_ObjectHelper->HandleList).field_0x4 - iVar9) / 0x5c);
LAB_4fc1a820:
  pcVar22 = local_570;
LAB_4fc1a824:
  cVar5 = (*local_4dc)(*piVar16);
  if ((cVar5 == '\0') && (cVar5 = (*local_518)(*piVar16), cVar5 == '\0')) {
    local_57e = '\x01';
  }
  else {
    local_57e = '\0';
  }
  if (local_57e != *(char *)(iVar8 + 0x13 + (int)piVar16)) {
    if (local_57e != '\0') {
      (*local_530)(piVar16[(int)pcVar2 * 0x20 + 3],2,1,0,0,0);
    }
    *(char *)(iVar8 + 0x13 + (int)piVar16) = local_57e;
  }
LAB_4fc1ab13:
  pcVar18 = local_568;
LAB_4fc1ab17:
  if (*(char *)(iVar8 + 0x16 + (int)piVar16) == '\0') {
    if (local_57d == '\0') goto LAB_4fc1ab6c;
    *(undefined1 *)(iVar8 + 0x16 + (int)piVar16) = 1;
    pcVar20 = "deploy";
  }
  else {
    if (local_57d != '\0') goto LAB_4fc1ab6c;
    *(undefined1 *)(iVar8 + 0x16 + (int)piVar16) = 0;
    pcVar20 = "undeploy";
  }
  SetAnimation(piVar16[(int)pcVar2 * 0x20 + 3],pcVar20,1);
  (*pcVar18)(piVar16[(int)pcVar2 * 0x20 + 3]);
  (*local_514)(piVar16[(int)pcVar2 * 0x20 + 3]);
LAB_4fc1ab6c:
  local_570 = pcVar22 + 1;
  if (piVar16[1] <= (int)local_570) goto LAB_4fc1ab7a;
  goto LAB_4fc19d6a;
}

