// Reconstructed by Ghidra from Strategy02.dll + Strategy02.pdb
// Original source file: /e:/github/vsr_dll_source/missions/vsrcore/attacherhelper.h
// Functions are ordered by original source line. This is decompiler
// output, not the author's source: names/types come from the PDB,
// local variable names and control flow are reconstructed.

// ---------------------------------------------------------------------
// operator==  @ 4fc19842  lines 50-206

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool __cdecl operator==(AttacherClass *a,AttacherClass *b)

{
  float fVar1;
  float fVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  double dVar10;
  double dVar11;
  double dVar12;
  int iVar13;
  undefined4 unaff_EBP;
  int iVar14;
  undefined4 unaff_ESI;
  int iVar15;
  undefined4 unaff_EDI;
  char *pcVar16;
  undefined1 auStack_9c [4];
  char *local_98;
  int local_94;
  char *local_90;
  char local_8c [64];
  char local_4c [68];
  uint local_8;
  
  local_8 = __security_cookie ^ (uint)auStack_9c;
  iVar14 = a->AttacherObject;
  if (iVar14 == b->AttacherObject) {
    if (a->NumberOfTaps == b->NumberOfTaps) {
      if (a->IsCerberus == b->IsCerberus) {
        iVar14 = 0;
        iVar15 = 0;
        local_94 = (int)b - (int)a;
        while( true ) {
          local_98 = *(char **)(a->Tap[0].TapWeaponSymmetryMask + iVar15 + -0x2c);
          if (local_98 !=
              *(undefined1 **)(a->Tap[0].TapWeaponSymmetryMask + local_94 + iVar15 + -0x2c)) {
            memset(local_8c,0,0x40);
            memset(local_4c,0,0x40);
            GetODFName((int)local_98,local_8c);
            GetODFName(*(int *)(b->Tap[0].TapWeaponSymmetryMask + iVar15 + -0x2c),local_4c);
            pcVar16 = "ATTACHERTAPCLASS MISMATCH: Tap%d TapObject: %08x \'%s\' and %08x \'%s\'";
            goto LAB_4fc19e9c;
          }
          if (a->Tap[0].TapWeaponSymmetryMask[iVar15 + -0x28] !=
              b->Tap[0].TapWeaponSymmetryMask[iVar15 + -0x28]) break;
          if (a->Tap[0].TapWeaponSymmetryMask[iVar15 + -0x27] !=
              b->Tap[0].TapWeaponSymmetryMask[iVar15 + -0x27]) {
            pcVar16 = "ATTACHERTAPCLASS MISMATCH: Tap%d TapIsAttacking: %d and %d";
            goto LAB_4fc19ce5;
          }
          if (a->Tap[0].TapWeaponSymmetryMask[iVar15 + -0x26] !=
              b->Tap[0].TapWeaponSymmetryMask[iVar15 + -0x26]) {
            pcVar16 = "ATTACHERTAPCLASS MISMATCH: Tap%d BuiltAttacherTap: %d and %d";
            goto LAB_4fc19ce5;
          }
          if (a->Tap[0].TapWeaponSymmetryMask[iVar15 + -0x25] !=
              b->Tap[0].TapWeaponSymmetryMask[iVar15 + -0x25]) {
            pcVar16 = "ATTACHERTAPCLASS MISMATCH: Tap%d TapShutOff: %d and %d";
            goto LAB_4fc19ce5;
          }
          if (a->Tap[0].TapWeaponSymmetryMask[iVar15 + -0x24] !=
              b->Tap[0].TapWeaponSymmetryMask[iVar15 + -0x24]) {
            pcVar16 = "ATTACHERTAPCLASS MISMATCH: Tap%d TapCoordinateFire: %d and %d";
            goto LAB_4fc19ce5;
          }
          if (a->Tap[0].TapWeaponSymmetryMask[iVar15 + -0x23] !=
              b->Tap[0].TapWeaponSymmetryMask[iVar15 + -0x23]) {
            pcVar16 = "ATTACHERTAPCLASS MISMATCH: Tap%d PDSMode: %d and %d";
            goto LAB_4fc19ce5;
          }
          if (a->Tap[0].TapWeaponSymmetryMask[iVar15 + -0x22] !=
              b->Tap[0].TapWeaponSymmetryMask[iVar15 + -0x22]) {
            pcVar16 = "ATTACHERTAPCLASS MISMATCH: Tap%d IsHostDeployed: %d and %d";
            goto LAB_4fc19ce5;
          }
          if (*(int *)(a->Tap[0].TapWeaponSymmetryMask + iVar15 + -0x20) !=
              *(int *)(b->Tap[0].TapWeaponSymmetryMask + iVar15 + -0x20)) {
            pcVar16 = "ATTACHERTAPCLASS MISMATCH: Tap%d TapDeployBehavior: %d and %d";
            goto LAB_4fc19ce5;
          }
          if (*(float *)(a->Tap[0].TapWeaponSymmetryMask + iVar15 + -0x1c) !=
              *(float *)(b->Tap[0].TapWeaponSymmetryMask + iVar15 + -0x1c)) {
            pcVar16 = "ATTACHERTAPCLASS MISMATCH: Tap%d TapEngageRange: %f and %f";
            goto LAB_4fc19e9c;
          }
          if (((*(float *)(a->Tap[0].TapWeaponSymmetryMask + iVar15 + -0x18) !=
                *(float *)(b->Tap[0].TapWeaponSymmetryMask + iVar15 + -0x18)) ||
              (*(float *)(a->Tap[0].TapWeaponSymmetryMask + iVar15 + -0x14) !=
               *(float *)(b->Tap[0].TapWeaponSymmetryMask + iVar15 + -0x14))) ||
             (*(float *)(a->Tap[0].TapWeaponSymmetryMask + iVar15 + -0x10) !=
              *(float *)(b->Tap[0].TapWeaponSymmetryMask + iVar15 + -0x10))) {
            pcVar16 = "ATTACHERTAPCLASS MISMATCH: Tap%d TapOffset: %f %f %f and %f %f %f";
LAB_4fc19d59:
            FormatLogMessage(pcVar16);
            return false;
          }
          if (((*(float *)(a->Tap[0].TapWeaponSymmetryMask + iVar15 + -0xc) !=
                *(float *)(b->Tap[0].TapWeaponSymmetryMask + iVar15 + -0xc)) ||
              (*(float *)(a->Tap[0].TapWeaponSymmetryMask + iVar15 + -8) !=
               *(float *)(b->Tap[0].TapWeaponSymmetryMask + iVar15 + -8))) ||
             (*(float *)(a->Tap[0].TapWeaponSymmetryMask + iVar15 + -4) !=
              *(float *)(b->Tap[0].TapWeaponSymmetryMask + iVar15 + -4))) {
            pcVar16 = "ATTACHERTAPCLASS MISMATCH: Tap%d TapRotation: %f %f %f and %f %f %f";
            goto LAB_4fc19d59;
          }
          local_98 = a->Tap[0].TapWeaponSymmetryMask + iVar15;
          local_90 = b->Tap[0].TapWeaponSymmetryMask + iVar15;
          iVar13 = _stricmp(local_98,local_90);
          if (iVar13 != 0) {
            pcVar16 = "ATTACHERTAPCLASS MISMATCH: Tap%d TapWeaponSymmetryMask: \'%s\' and \'%s\'";
            goto LAB_4fc19ce5;
          }
          if (a->Tap[0].TapWeaponSymmetryMask[iVar15 + 6] !=
              b->Tap[0].TapWeaponSymmetryMask[iVar15 + 6]) {
            pcVar16 = "ATTACHERTAPCLASS MISMATCH: Tap%d IsCerberusTail: %d and %d";
            goto LAB_4fc19ce5;
          }
          if (a->Tap[0].TapWeaponSymmetryMask[iVar15 + 7] !=
              b->Tap[0].TapWeaponSymmetryMask[iVar15 + 7]) {
            pcVar16 = "ATTACHERTAPCLASS MISMATCH: Tap%d IsCerberusTailAnimated: %d and %d";
            goto LAB_4fc19ce5;
          }
          if (*(int *)(a->Tap[0].TapWeaponSymmetryMask + iVar15 + 8) !=
              *(int *)(b->Tap[0].TapWeaponSymmetryMask + iVar15 + 8)) {
            pcVar16 = "ATTACHERTAPCLASS MISMATCH: Tap%d CerbTailSwinging: %d and %d";
            goto LAB_4fc19ce5;
          }
          if (*(float *)(a->Tap[0].TapWeaponSymmetryMask + iVar15 + 0xc) !=
              *(float *)(b->Tap[0].TapWeaponSymmetryMask + iVar15 + 0xc)) {
            pcVar16 = "ATTACHERTAPCLASS MISMATCH: Tap%d CerbTailConeAngle: %f and %f";
LAB_4fc19e9c:
            FormatLogMessage(pcVar16);
            return false;
          }
          if (*(float *)(a->Tap[0].TapWeaponSymmetryMask + iVar15 + 0x10) !=
              *(float *)(b->Tap[0].TapWeaponSymmetryMask + iVar15 + 0x10)) {
            pcVar16 = "ATTACHERTAPCLASS MISMATCH: Tap%d CerbAnimLength: %f and %f";
            goto LAB_4fc19e9c;
          }
          fVar1 = *(float *)(b->Tap[0].TapWeaponSymmetryMask + iVar15 + 0x34);
          fVar2 = *(float *)(a->Tap[0].TapWeaponSymmetryMask + iVar15 + 0x34);
          if (((((fVar2 != fVar1) ||
                (*(float *)(a->Tap[0].TapWeaponSymmetryMask + iVar15 + 0x38) !=
                 *(float *)(b->Tap[0].TapWeaponSymmetryMask + iVar15 + 0x38))) ||
               (((*(float *)(a->Tap[0].TapWeaponSymmetryMask + iVar15 + 0x3c) !=
                  *(float *)(b->Tap[0].TapWeaponSymmetryMask + iVar15 + 0x3c) ||
                 ((((*(float *)(a->Tap[0].TapWeaponSymmetryMask + iVar15 + 0x14) !=
                     *(float *)(b->Tap[0].TapWeaponSymmetryMask + iVar15 + 0x14) ||
                    (*(float *)(a->Tap[0].TapWeaponSymmetryMask + iVar15 + 0x18) !=
                     *(float *)(b->Tap[0].TapWeaponSymmetryMask + iVar15 + 0x18))) ||
                   (*(float *)(a->Tap[0].TapWeaponSymmetryMask + iVar15 + 0x1c) !=
                    *(float *)(b->Tap[0].TapWeaponSymmetryMask + iVar15 + 0x1c))) ||
                  ((*(float *)(a->Tap[0].TapWeaponSymmetryMask + iVar15 + 0x24) !=
                    *(float *)(b->Tap[0].TapWeaponSymmetryMask + iVar15 + 0x24) ||
                   (*(float *)(a->Tap[0].TapWeaponSymmetryMask + iVar15 + 0x28) !=
                    *(float *)(b->Tap[0].TapWeaponSymmetryMask + iVar15 + 0x28))))))) ||
                (*(float *)(a->Tap[0].TapWeaponSymmetryMask + iVar15 + 0x2c) !=
                 *(float *)(b->Tap[0].TapWeaponSymmetryMask + iVar15 + 0x2c))))) ||
              ((*(float *)(a->Tap[0].TapWeaponSymmetryMask + iVar15 + 0x44) !=
                *(float *)(b->Tap[0].TapWeaponSymmetryMask + iVar15 + 0x44) ||
               (*(float *)(a->Tap[0].TapWeaponSymmetryMask + iVar15 + 0x48) !=
                *(float *)(b->Tap[0].TapWeaponSymmetryMask + iVar15 + 0x48))))) ||
             (*(float *)(a->Tap[0].TapWeaponSymmetryMask + iVar15 + 0x4c) !=
              *(float *)(b->Tap[0].TapWeaponSymmetryMask + iVar15 + 0x4c))) {
            dVar3 = (double)b->Tap[iVar14].TapPosition.posit.z;
            dVar4 = (double)b->Tap[iVar14].TapPosition.posit.y;
            dVar5 = (double)b->Tap[iVar14].TapPosition.posit.x;
            dVar6 = (double)a->Tap[iVar14].TapPosition.posit.z;
            dVar7 = (double)a->Tap[iVar14].TapPosition.posit.x;
            dVar8 = (double)b->Tap[iVar14].TapPosition.right.z;
            dVar9 = (double)b->Tap[iVar14].TapPosition.right.y;
            dVar10 = (double)b->Tap[iVar14].TapPosition.right.x;
            dVar11 = (double)a->Tap[iVar14].TapPosition.right.z;
            dVar12 = (double)a->Tap[iVar14].TapPosition.right.y;
            FormatLogMessage("REPLACEONDEATHCLASS MISMATCH: Tap%d TapPosition Front: %f %f %f and %f %f %f, Tap%d TapPosition Right: %f %f %f and %f %f %f, Tap%d TapPosition Up: %f %f %f and %f %f %f, Tap%d TapPosition Posit: %f %f %f and %f %f %f"
                             ,iVar14,(double)fVar2,(double)a->Tap[iVar14].TapPosition.front.y,
                             (double)a->Tap[iVar14].TapPosition.front.z,(double)fVar1,
                             (double)b->Tap[iVar14].TapPosition.front.y,
                             (double)b->Tap[iVar14].TapPosition.front.z,iVar14,
                             (double)CONCAT44(SUB84(dVar12,0),
                                              (int)((ulonglong)
                                                    (double)a->Tap[iVar14].TapPosition.right.x >>
                                                   0x20)),
                             (double)CONCAT44(SUB84(dVar11,0),(int)((ulonglong)dVar12 >> 0x20)),
                             (double)CONCAT44(SUB84(dVar10,0),(int)((ulonglong)dVar11 >> 0x20)),
                             (double)CONCAT44(SUB84(dVar9,0),(int)((ulonglong)dVar10 >> 0x20)),
                             (double)CONCAT44(SUB84(dVar8,0),(int)((ulonglong)dVar9 >> 0x20)),
                             (double)CONCAT44(iVar14,(int)((ulonglong)dVar8 >> 0x20)),
                             SUB84((double)a->Tap[iVar14].TapPosition.up.x,0),
                             (double)a->Tap[iVar14].TapPosition.up.y,
                             (double)a->Tap[iVar14].TapPosition.up.z,
                             (double)b->Tap[iVar14].TapPosition.up.x,
                             (double)b->Tap[iVar14].TapPosition.up.y,
                             (double)b->Tap[iVar14].TapPosition.up.z,
                             (double)CONCAT44(SUB84(dVar7,0),iVar14),(int)((ulonglong)dVar7 >> 0x20)
                             ,(double)CONCAT44(SUB84(dVar6,0),
                                               (int)((ulonglong)
                                                     (double)a->Tap[iVar14].TapPosition.posit.y >>
                                                    0x20)),
                             (double)CONCAT44(SUB84(dVar5,0),(int)((ulonglong)dVar6 >> 0x20)),
                             (double)CONCAT44(SUB84(dVar4,0),(int)((ulonglong)dVar5 >> 0x20)),
                             (double)CONCAT44(SUB84(dVar3,0),(int)((ulonglong)dVar4 >> 0x20)),
                             (double)CONCAT44(unaff_EDI,(int)((ulonglong)dVar3 >> 0x20)),
                             (double)CONCAT44(unaff_EBP,unaff_ESI));
            return false;
          }
          iVar15 = iVar15 + 0x80;
          iVar14 = iVar14 + 1;
          if (0x3ff < iVar15) {
            return true;
          }
        }
        pcVar16 = "ATTACHERTAPCLASS MISMATCH: Tap%d TapIndependance: %d and %d";
LAB_4fc19ce5:
        FormatLogMessage(pcVar16);
        return false;
      }
      pcVar16 = "ATTACHERCLASS MISMATCH: IsCerberus: %d and %d";
    }
    else {
      pcVar16 = "ATTACHERCLASS MISMATCH: NumberOfTaps: %d and %d";
    }
    FormatLogMessage(pcVar16);
  }
  else {
    memset(local_4c,0,0x40);
    memset(local_8c,0,0x40);
    GetODFName(iVar14,local_4c);
    GetODFName(b->AttacherObject,local_8c);
    FormatLogMessage("ATTACHERCLASS MISMATCH: AttacherObject: %08x \'%s\' and %08x \'%s\'",
                     a->AttacherObject,local_4c,b->AttacherObject,local_8c);
  }
  return false;
}


