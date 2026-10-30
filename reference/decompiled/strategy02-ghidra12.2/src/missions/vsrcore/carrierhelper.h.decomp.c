// Reconstructed by Ghidra from Strategy02.dll + Strategy02.pdb
// Original source file: /e:/github/vsr_dll_source/missions/vsrcore/carrierhelper.h
// Functions are ordered by original source line. This is decompiler
// output, not the author's source: names/types come from the PDB,
// local variable names and control flow are reconstructed.


// ---------------------------------------------------------------------
// operator==  @ 4fc17a45  lines 43-107


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool __cdecl operator==(CarrierClass *param_1,CarrierClass *param_2)

{
  int *in_ECX;
  int *in_EDX;
  char *unaff_ESI;
  int unaff_EDI;
  char *pcVar1;
  undefined1 local_8c [64];
  undefined1 local_4c [68];
  undefined4 local_8;
  
  local_8 = __security_cookie ^ (uint)(local_4c + 0x48);
  if (*in_ECX == *in_EDX) {
    if ((float)in_ECX[1] == (float)in_EDX[1]) {
      if ((float)in_ECX[2] == (float)in_EDX[2]) {
        if ((float)in_ECX[3] == (float)in_EDX[3]) {
          if ((float)in_ECX[4] == (float)in_EDX[4]) {
            if (in_ECX[6] == in_EDX[6]) {
              if (in_ECX[7] == in_EDX[7]) {
                if (in_ECX[9] == in_EDX[9]) {
                  if (in_ECX[10] == in_EDX[10]) {
                    if ((char)in_ECX[0xb] == (char)in_EDX[0xb]) {
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
    memset(local_8c,0,0x40);
    memset(local_4c,0,0x40);
    GetODFName(unaff_EDI,unaff_ESI);
    GetODFName(unaff_EDI,unaff_ESI);
    pcVar1 = "CARRIERCLASS MISMATCH: CarrierObject: %08x \'%s\' and %08x \'%s\'";
  }
  FormatLogMessage(pcVar1);
  return false;
}


// ---------------------------------------------------------------------
// operator==  @ 4fc17bda  lines 127-187


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool __cdecl operator==(DroneClass *param_1,DroneClass *param_2)

{
  int *in_ECX;
  int *in_EDX;
  char *unaff_ESI;
  int unaff_EDI;
  char *pcVar1;
  undefined1 local_8c [64];
  undefined1 local_4c [68];
  undefined4 local_8;
  
  local_8 = __security_cookie ^ (uint)(local_4c + 0x48);
  if (*in_ECX == *in_EDX) {
    if (in_ECX[1] == in_EDX[1]) {
      if ((char)in_ECX[6] == (char)in_EDX[6]) {
        if (in_ECX[3] == in_EDX[3]) {
          if (in_ECX[2] == in_EDX[2]) {
            if (in_ECX[5] == in_EDX[5]) {
              if ((float)in_ECX[7] == (float)in_EDX[7]) {
                if ((((float)in_ECX[8] == (float)in_EDX[8]) &&
                    ((float)in_ECX[9] == (float)in_EDX[9])) &&
                   ((float)in_ECX[10] == (float)in_EDX[10])) {
                  return true;
                }
                FormatLogMessage("DRONECLASS MISMATCH: Position: %f %f %f and %f %f %f");
                return false;
              }
              pcVar1 = "DRONECLASS MISMATCH: RandomTargetDist: %f and %f";
              goto LAB_4fc17c48;
            }
            pcVar1 = "DRONECLASS MISMATCH: CarrierWeaponSlot: %d and %d";
          }
          else {
            pcVar1 = "DRONECLASS MISMATCH: CarrierIndex: %d and %d";
          }
        }
        else {
          pcVar1 = "DRONECLASS MISMATCH: DroneState: %d and %d";
        }
      }
      else {
        pcVar1 = "DRONECLASS MISMATCH: UseLocalAmmo: %d and %d";
      }
      FormatLogMessage(pcVar1);
      return false;
    }
    memset(local_4c,0,0x40);
    memset(local_8c,0,0x40);
    GetODFName(unaff_EDI,unaff_ESI);
    GetODFName(unaff_EDI,unaff_ESI);
    pcVar1 = "DRONECLASS MISMATCH: DroneTarget: %08x \'%s\' and %08x \'%s\'";
  }
  else {
    memset(local_8c,0,0x40);
    memset(local_4c,0,0x40);
    GetODFName(unaff_EDI,unaff_ESI);
    GetODFName(unaff_EDI,unaff_ESI);
    pcVar1 = "DRONECLASS MISMATCH: DroneObject: %08x \'%s\' and %08x \'%s\'";
  }
LAB_4fc17c48:
  FormatLogMessage(pcVar1);
  return false;
}

