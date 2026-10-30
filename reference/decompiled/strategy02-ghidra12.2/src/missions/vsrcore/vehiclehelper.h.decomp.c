// Reconstructed by Ghidra from Strategy02.dll + Strategy02.pdb
// Original source file: /e:/github/vsr_dll_source/missions/vsrcore/vehiclehelper.h
// Functions are ordered by original source line. This is decompiler
// output, not the author's source: names/types come from the PDB,
// local variable names and control flow are reconstructed.


// ---------------------------------------------------------------------
// operator==  @ 4fc23eb2  lines 46-164


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool __cdecl operator==(VehicleClass *param_1,VehicleClass *param_2)

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
      if (in_ECX[2] == in_EDX[2]) {
        if (in_ECX[3] == in_EDX[3]) {
          if (in_ECX[4] == in_EDX[4]) {
            if (in_ECX[5] == in_EDX[5]) {
              if ((char)in_ECX[6] == (char)in_EDX[6]) {
                if (*(char *)((int)in_ECX + 0x19) == *(char *)((int)in_EDX + 0x19)) {
                  if (*(char *)((int)in_ECX + 0x1a) == *(char *)((int)in_EDX + 0x1a)) {
                    if ((char)in_ECX[7] == (char)in_EDX[7]) {
                      if (in_ECX[8] == in_EDX[8]) {
                        if (in_ECX[9] == in_EDX[9]) {
                          if (in_ECX[10] == in_EDX[10]) {
                            if (in_ECX[0xb] == in_EDX[0xb]) {
                              if (in_ECX[0xc] == in_EDX[0xc]) {
                                if (in_ECX[0xd] == in_EDX[0xd]) {
                                  if (in_ECX[0xe] == in_EDX[0xe]) {
                                    if (in_ECX[0xf] == in_EDX[0xf]) {
                                      if ((float)in_ECX[0x11] == (float)in_EDX[0x11]) {
                                        if ((((float)in_ECX[0x12] == (float)in_EDX[0x12]) &&
                                            ((float)in_ECX[0x13] == (float)in_EDX[0x13])) &&
                                           ((float)in_ECX[0x14] == (float)in_EDX[0x14])) {
                                          return true;
                                        }
                                        FormatLogMessage(
                                                  "VEHICLELIST MISMATCH: Position: %f %f %f and %f %f %f"
                                                  );
                                        return false;
                                      }
                                      pcVar1 = "VEHICLELIST MISMATCH: EngageRange: %f and %f";
                                      goto LAB_4fc23f20;
                                    }
                                    pcVar1 = "VEHICLELIST MISMATCH: CloakAddEnergy: %d and %d";
                                  }
                                  else {
                                    pcVar1 = "VEHICLELIST MISMATCH: CloakCostEnergy: %d and %d";
                                  }
                                }
                                else {
                                  pcVar1 = "VEHICLELIST MISMATCH: CloakCurEnergy: %d and %d";
                                }
                              }
                              else {
                                pcVar1 = "VEHICLELIST MISMATCH: CloakMaxEnergy: %d and %d";
                              }
                            }
                            else {
                              pcVar1 = "VEHICLELIST MISMATCH: PTeam: %d and %d";
                            }
                          }
                          else {
                            pcVar1 = "VEHICLELIST MISMATCH: CurTeamNum: %d and %d";
                          }
                        }
                        else {
                          pcVar1 = "VEHICLELIST MISMATCH: ShowSkillTimer: %d and %d";
                        }
                      }
                      else {
                        pcVar1 = "VEHICLELIST MISMATCH: ShowSkillTeamFilter: %d and %d";
                      }
                    }
                    else {
                      pcVar1 = "VEHICLELIST MISMATCH: CanBeIdleVictim: %d and %d";
                    }
                  }
                  else {
                    pcVar1 = "VEHICLELIST MISMATCH: AllowRemoteControl: %d and %d";
                  }
                }
                else {
                  pcVar1 = "VEHICLELIST MISMATCH: BlockDeploy: %d and %d";
                }
              }
              else {
                pcVar1 = "VEHICLELIST MISMATCH: ShowSkill: %d and %d";
              }
            }
            else {
              pcVar1 = "VEHICLELIST MISMATCH: MaxHealth: %d and %d";
            }
          }
          else {
            pcVar1 = "VEHICLELIST MISMATCH: LastCommand: %d and %d";
          }
        }
        else {
          pcVar1 = "VEHICLELIST MISMATCH: BZCClassHash: %d and %d";
        }
      }
      else {
        pcVar1 = "VEHICLELIST MISMATCH: ObjClassHash: %d and %d";
      }
    }
    else {
      pcVar1 = "VEHICLELIST MISMATCH: ODFNameHash: %d and %d";
    }
    FormatLogMessage(pcVar1);
  }
  else {
    memset(local_8c,0,0x40);
    memset(local_4c,0,0x40);
    GetODFName(unaff_EDI,unaff_ESI);
    GetODFName(unaff_EDI,unaff_ESI);
    pcVar1 = "VEHICLELIST MISMATCH: ObjectHandle: %08x \'%s\' and %08x \'%s\'";
LAB_4fc23f20:
    FormatLogMessage(pcVar1);
  }
  return false;
}

