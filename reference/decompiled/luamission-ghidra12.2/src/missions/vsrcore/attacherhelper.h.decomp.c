// Reconstructed by Ghidra from LuaMission.dll + LuaMission.pdb
// Original source file: /e:/github/vsr_dll_source/missions/vsrcore/attacherhelper.h
// Functions are ordered by original source line. This is decompiler
// output, not the author's source: names/types come from the PDB,
// local variable names and control flow are reconstructed.


// ---------------------------------------------------------------------
// operator==  @ 4fc2d6eb  lines 50-206


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool __cdecl operator==(AttacherClass *param_1,AttacherClass *param_2)

{
  int iVar1;
  int *in_ECX;
  int *in_EDX;
  char *unaff_ESI;
  int iVar2;
  int unaff_EDI;
  char *pcVar3;
  undefined1 auStack_9c [4];
  char *local_98;
  int local_94;
  char *local_90;
  undefined1 local_8c [64];
  undefined1 local_4c [68];
  uint local_8;
  
  local_8 = __security_cookie ^ (uint)auStack_9c;
  if (*in_ECX == *in_EDX) {
    if (in_ECX[1] == in_EDX[1]) {
      if ((char)in_ECX[2] == (char)in_EDX[2]) {
        iVar2 = 0;
        local_94 = (int)in_EDX - (int)in_ECX;
        while( true ) {
          local_98 = *(char **)((int)in_ECX + iVar2 + 0xc);
          if (local_98 != *(char **)((int)in_ECX + local_94 + iVar2 + 0xc)) {
            memset(local_8c,0,0x40);
            memset(local_4c,0,0x40);
            GetODFName(unaff_EDI,unaff_ESI);
            GetODFName(unaff_EDI,unaff_ESI);
            pcVar3 = "ATTACHERTAPCLASS MISMATCH: Tap%d TapObject: %08x \'%s\' and %08x \'%s\'";
            goto LAB_4fc2dd45;
          }
          if (*(char *)(iVar2 + 0x10 + (int)in_ECX) != *(char *)(iVar2 + 0x10 + (int)in_EDX)) break;
          if (*(char *)(iVar2 + 0x11 + (int)in_ECX) != *(char *)(iVar2 + 0x11 + (int)in_EDX)) {
            pcVar3 = "ATTACHERTAPCLASS MISMATCH: Tap%d TapIsAttacking: %d and %d";
            goto LAB_4fc2db8e;
          }
          if (*(char *)(iVar2 + 0x12 + (int)in_ECX) != *(char *)(iVar2 + 0x12 + (int)in_EDX)) {
            pcVar3 = "ATTACHERTAPCLASS MISMATCH: Tap%d BuiltAttacherTap: %d and %d";
            goto LAB_4fc2db8e;
          }
          if (*(char *)(iVar2 + 0x13 + (int)in_ECX) != *(char *)(iVar2 + 0x13 + (int)in_EDX)) {
            pcVar3 = "ATTACHERTAPCLASS MISMATCH: Tap%d TapShutOff: %d and %d";
            goto LAB_4fc2db8e;
          }
          if (*(char *)(iVar2 + 0x14 + (int)in_ECX) != *(char *)(iVar2 + 0x14 + (int)in_EDX)) {
            pcVar3 = "ATTACHERTAPCLASS MISMATCH: Tap%d TapCoordinateFire: %d and %d";
            goto LAB_4fc2db8e;
          }
          if (*(char *)(iVar2 + 0x15 + (int)in_ECX) != *(char *)(iVar2 + 0x15 + (int)in_EDX)) {
            pcVar3 = "ATTACHERTAPCLASS MISMATCH: Tap%d PDSMode: %d and %d";
            goto LAB_4fc2db8e;
          }
          if (*(char *)(iVar2 + 0x16 + (int)in_ECX) != *(char *)(iVar2 + 0x16 + (int)in_EDX)) {
            pcVar3 = "ATTACHERTAPCLASS MISMATCH: Tap%d IsHostDeployed: %d and %d";
            goto LAB_4fc2db8e;
          }
          if (*(int *)(iVar2 + 0x18 + (int)in_ECX) != *(int *)(iVar2 + 0x18 + (int)in_EDX)) {
            pcVar3 = "ATTACHERTAPCLASS MISMATCH: Tap%d TapDeployBehavior: %d and %d";
            goto LAB_4fc2db8e;
          }
          if (*(float *)(iVar2 + 0x1c + (int)in_ECX) != *(float *)(iVar2 + 0x1c + (int)in_EDX)) {
            pcVar3 = "ATTACHERTAPCLASS MISMATCH: Tap%d TapEngageRange: %f and %f";
            goto LAB_4fc2dd45;
          }
          if (((*(float *)(iVar2 + 0x20 + (int)in_ECX) != *(float *)(iVar2 + 0x20 + (int)in_EDX)) ||
              (*(float *)((int)in_ECX + iVar2 + 0x24) != *(float *)(iVar2 + 0x24 + (int)in_EDX))) ||
             (*(float *)((int)in_ECX + iVar2 + 0x28) != *(float *)(iVar2 + 0x28 + (int)in_EDX))) {
            pcVar3 = "ATTACHERTAPCLASS MISMATCH: Tap%d TapOffset: %f %f %f and %f %f %f";
LAB_4fc2dc02:
            FormatLogMessage(pcVar3);
            return false;
          }
          if (((*(float *)((int)in_ECX + iVar2 + 0x2c) != *(float *)(iVar2 + 0x2c + (int)in_EDX)) ||
              (*(float *)((int)in_ECX + iVar2 + 0x30) != *(float *)(iVar2 + 0x30 + (int)in_EDX))) ||
             (*(float *)((int)in_ECX + iVar2 + 0x34) != *(float *)(iVar2 + 0x34 + (int)in_EDX))) {
            pcVar3 = "ATTACHERTAPCLASS MISMATCH: Tap%d TapRotation: %f %f %f and %f %f %f";
            goto LAB_4fc2dc02;
          }
          local_98 = (char *)((int)in_ECX + iVar2 + 0x38);
          local_90 = (char *)((int)in_EDX + iVar2 + 0x38);
          iVar1 = _stricmp(local_98,local_90);
          if (iVar1 != 0) {
            pcVar3 = "ATTACHERTAPCLASS MISMATCH: Tap%d TapWeaponSymmetryMask: \'%s\' and \'%s\'";
            goto LAB_4fc2db8e;
          }
          if (*(char *)(iVar2 + 0x3e + (int)in_ECX) != *(char *)(iVar2 + 0x3e + (int)in_EDX)) {
            pcVar3 = "ATTACHERTAPCLASS MISMATCH: Tap%d IsCerberusTail: %d and %d";
            goto LAB_4fc2db8e;
          }
          if (*(char *)(iVar2 + 0x3f + (int)in_ECX) != *(char *)(iVar2 + 0x3f + (int)in_EDX)) {
            pcVar3 = "ATTACHERTAPCLASS MISMATCH: Tap%d IsCerberusTailAnimated: %d and %d";
            goto LAB_4fc2db8e;
          }
          if (*(int *)(iVar2 + 0x40 + (int)in_ECX) != *(int *)(iVar2 + 0x40 + (int)in_EDX)) {
            pcVar3 = "ATTACHERTAPCLASS MISMATCH: Tap%d CerbTailSwinging: %d and %d";
            goto LAB_4fc2db8e;
          }
          if (*(float *)(iVar2 + 0x44 + (int)in_ECX) != *(float *)(iVar2 + 0x44 + (int)in_EDX)) {
            pcVar3 = "ATTACHERTAPCLASS MISMATCH: Tap%d CerbTailConeAngle: %f and %f";
LAB_4fc2dd45:
            FormatLogMessage(pcVar3);
            return false;
          }
          if (*(float *)(iVar2 + 0x48 + (int)in_ECX) != *(float *)(iVar2 + 0x48 + (int)in_EDX)) {
            pcVar3 = "ATTACHERTAPCLASS MISMATCH: Tap%d CerbAnimLength: %f and %f";
            goto LAB_4fc2dd45;
          }
          if (((((*(float *)(iVar2 + 0x6c + (int)in_ECX) != *(float *)(iVar2 + 0x6c + (int)in_EDX))
                || (*(float *)((int)in_ECX + iVar2 + 0x70) != *(float *)(iVar2 + 0x70 + (int)in_EDX)
                   )) || (((*(float *)((int)in_ECX + iVar2 + 0x74) !=
                            *(float *)(iVar2 + 0x74 + (int)in_EDX) ||
                           ((((*(float *)((int)in_ECX + iVar2 + 0x4c) !=
                               *(float *)(iVar2 + 0x4c + (int)in_EDX) ||
                              (*(float *)((int)in_ECX + iVar2 + 0x50) !=
                               *(float *)(iVar2 + 0x50 + (int)in_EDX))) ||
                             (*(float *)((int)in_ECX + iVar2 + 0x54) !=
                              *(float *)(iVar2 + 0x54 + (int)in_EDX))) ||
                            ((*(float *)((int)in_ECX + iVar2 + 0x5c) !=
                              *(float *)(iVar2 + 0x5c + (int)in_EDX) ||
                             (*(float *)((int)in_ECX + iVar2 + 0x60) !=
                              *(float *)(iVar2 + 0x60 + (int)in_EDX))))))) ||
                          (*(float *)((int)in_ECX + iVar2 + 100) !=
                           *(float *)(iVar2 + 100 + (int)in_EDX))))) ||
              ((*(float *)((int)in_ECX + iVar2 + 0x7c) != *(float *)(iVar2 + 0x7c + (int)in_EDX) ||
               (*(float *)((int)in_ECX + iVar2 + 0x80) != *(float *)(iVar2 + 0x80 + (int)in_EDX)))))
             || (*(float *)((int)in_ECX + iVar2 + 0x84) != *(float *)(iVar2 + 0x84 + (int)in_EDX)))
          {
            FormatLogMessage(
                            "REPLACEONDEATHCLASS MISMATCH: Tap%d TapPosition Front: %f %f %f and %f %f %f, Tap%d TapPosition Right: %f %f %f and %f %f %f, Tap%d TapPosition Up: %f %f %f and %f %f %f, Tap%d TapPosition Posit: %f %f %f and %f %f %f"
                            );
            return false;
          }
          iVar2 = iVar2 + 0x80;
          if (0x3ff < iVar2) {
            return true;
          }
        }
        pcVar3 = "ATTACHERTAPCLASS MISMATCH: Tap%d TapIndependance: %d and %d";
LAB_4fc2db8e:
        FormatLogMessage(pcVar3);
        return false;
      }
      pcVar3 = "ATTACHERCLASS MISMATCH: IsCerberus: %d and %d";
    }
    else {
      pcVar3 = "ATTACHERCLASS MISMATCH: NumberOfTaps: %d and %d";
    }
    FormatLogMessage(pcVar3);
  }
  else {
    memset(local_4c,0,0x40);
    memset(local_8c,0,0x40);
    GetODFName(unaff_EDI,unaff_ESI);
    GetODFName(unaff_EDI,unaff_ESI);
    FormatLogMessage("ATTACHERCLASS MISMATCH: AttacherObject: %08x \'%s\' and %08x \'%s\'");
  }
  return false;
}

