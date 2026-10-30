// Reconstructed by Ghidra from Strategy02.dll + Strategy02.pdb
// Original source file: /e:/github/vsr_dll_source/missions/vsrcore/carrierhelper.h
// Functions are ordered by original source line. This is decompiler
// output, not the author's source: names/types come from the PDB,
// local variable names and control flow are reconstructed.

// ---------------------------------------------------------------------
// operator==  @ 4fc17a45  lines 43-107

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool __cdecl operator==(CarrierClass *a,CarrierClass *b)

{
  int h;
  char *pcVar1;
  char ODFNameA [64];
  char ODFNameB [68];
  uint local_8;
  
  local_8 = __security_cookie ^ (uint)&stack0xfffffffc;
  h = a->CarrierObject;
  if (h == b->CarrierObject) {
    if (a->DroneControlRange == b->DroneControlRange) {
      if (a->DroneRepairRange == b->DroneRepairRange) {
        if (a->DroneDefendRange == b->DroneDefendRange) {
          if (a->DroneRecallRange == b->DroneRecallRange) {
            if (a->MaxDrones == b->MaxDrones) {
              if (a->CurDrones == b->CurDrones) {
                if (a->HealthRepairAmount == b->HealthRepairAmount) {
                  if (a->AmmoRepairAmount == b->AmmoRepairAmount) {
                    if (a->ServiceAllies == b->ServiceAllies) {
                      return true;
                    }
                    pcVar1 = "CARRIERCLASS MISMATCH: ServiceAllies: %d and %d";
                  }
                  else {
                    pcVar1 = "CARRIERCLASS MISMATCH: AmmoRepairAmount: %d and %d";
                  }
                }
                else {
                  pcVar1 = "CARRIERCLASS MISMATCH: HealthRepairAmount: %d and %d";
                }
              }
              else {
                pcVar1 = "CARRIERCLASS MISMATCH: CurDrones: %d and %d";
              }
            }
            else {
              pcVar1 = "CARRIERCLASS MISMATCH: MaxDrones: %d and %d";
            }
            FormatLogMessage(pcVar1);
            return false;
          }
          pcVar1 = "CARRIERCLASS MISMATCH: DroneRecallRange: %f and %f";
        }
        else {
          pcVar1 = "CARRIERCLASS MISMATCH: DroneDefendRange: %f and %f";
        }
      }
      else {
        pcVar1 = "CARRIERCLASS MISMATCH: DroneRepairRange: %f and %f";
      }
    }
    else {
      pcVar1 = "CARRIERCLASS MISMATCH: DroneControlRange: %f and %f";
    }
  }
  else {
    memset(ODFNameA,0,0x40);
    memset(ODFNameB,0,0x40);
    GetODFName(h,ODFNameA);
    GetODFName(b->CarrierObject,ODFNameB);
    pcVar1 = "CARRIERCLASS MISMATCH: CarrierObject: %08x \'%s\' and %08x \'%s\'";
  }
  FormatLogMessage(pcVar1);
  return false;
}


// ---------------------------------------------------------------------
// operator==  @ 4fc17bda  lines 127-187

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool __cdecl operator==(DroneClass *a,DroneClass *b)

{
  float fVar1;
  float fVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  int iVar8;
  undefined4 unaff_EDI;
  char *pcVar9;
  char ODFNameA__ODFNameB [64];
  char ODFNameB__ODFNameA [68];
  uint local_8;
  
  local_8 = __security_cookie ^ (uint)&stack0xfffffffc;
  iVar8 = a->DroneObject;
  if (iVar8 == b->DroneObject) {
    iVar8 = a->DroneTarget;
    if (iVar8 == b->DroneTarget) {
      if (a->UseLocalAmmo == b->UseLocalAmmo) {
        if (a->DroneState == b->DroneState) {
          if (a->CarrierIndex == b->CarrierIndex) {
            if (a->CarrierWeaponSlot == b->CarrierWeaponSlot) {
              if (a->RandomTargetDist == b->RandomTargetDist) {
                fVar1 = (b->Position).x;
                fVar2 = (a->Position).x;
                if (((fVar2 == fVar1) && ((a->Position).y == (b->Position).y)) &&
                   ((a->Position).z == (b->Position).z)) {
                  return true;
                }
                dVar3 = (double)(b->Position).z;
                dVar4 = (double)(b->Position).y;
                dVar5 = (double)fVar1;
                dVar6 = (double)(a->Position).z;
                dVar7 = (double)(a->Position).y;
                FormatLogMessage("DRONECLASS MISMATCH: Position: %f %f %f and %f %f %f",
                                 (double)CONCAT44(SUB84(dVar7,0),
                                                  (int)((ulonglong)(double)fVar2 >> 0x20)),
                                 (double)CONCAT44(SUB84(dVar6,0),(int)((ulonglong)dVar7 >> 0x20)),
                                 (double)CONCAT44(SUB84(dVar5,0),(int)((ulonglong)dVar6 >> 0x20)),
                                 (double)CONCAT44(SUB84(dVar4,0),(int)((ulonglong)dVar5 >> 0x20)),
                                 (double)CONCAT44(SUB84(dVar3,0),(int)((ulonglong)dVar4 >> 0x20)),
                                 (double)CONCAT44(unaff_EDI,(int)((ulonglong)dVar3 >> 0x20)));
                return false;
              }
              pcVar9 = "DRONECLASS MISMATCH: RandomTargetDist: %f and %f";
              goto LAB_4fc17c48;
            }
            pcVar9 = "DRONECLASS MISMATCH: CarrierWeaponSlot: %d and %d";
          }
          else {
            pcVar9 = "DRONECLASS MISMATCH: CarrierIndex: %d and %d";
          }
        }
        else {
          pcVar9 = "DRONECLASS MISMATCH: DroneState: %d and %d";
        }
      }
      else {
        pcVar9 = "DRONECLASS MISMATCH: UseLocalAmmo: %d and %d";
      }
      FormatLogMessage(pcVar9);
      return false;
    }
    memset(ODFNameB__ODFNameA,0,0x40);
    memset(ODFNameA__ODFNameB,0,0x40);
    GetODFName(iVar8,ODFNameB__ODFNameA);
    GetODFName(b->DroneTarget,ODFNameA__ODFNameB);
    pcVar9 = "DRONECLASS MISMATCH: DroneTarget: %08x \'%s\' and %08x \'%s\'";
  }
  else {
    memset(ODFNameA__ODFNameB,0,0x40);
    memset(ODFNameB__ODFNameA,0,0x40);
    GetODFName(iVar8,ODFNameA__ODFNameB);
    GetODFName(b->DroneObject,ODFNameB__ODFNameA);
    pcVar9 = "DRONECLASS MISMATCH: DroneObject: %08x \'%s\' and %08x \'%s\'";
  }
LAB_4fc17c48:
  FormatLogMessage(pcVar9);
  return false;
}


