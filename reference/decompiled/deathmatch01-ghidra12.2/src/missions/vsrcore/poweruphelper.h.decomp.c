// Reconstructed by Ghidra from deathmatch01.dll + deathmatch01.pdb
// Original source file: /e:/github/vsr_dll_source/missions/vsrcore/poweruphelper.h
// Functions are ordered by original source line. This is decompiler
// output, not the author's source: names/types come from the PDB,
// local variable names and control flow are reconstructed.


// ---------------------------------------------------------------------
// operator==  @ 4fc24840  lines 32-90


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool __cdecl operator==(PowerupClass *param_1,PowerupClass *param_2)

{
  int iVar1;
  int *in_ECX;
  int *in_EDX;
  char *unaff_ESI;
  int unaff_EDI;
  char *pcVar2;
  undefined1 auStack_94 [4];
  int *local_90;
  undefined1 local_8c [64];
  undefined1 local_4c [68];
  uint local_8;
  
  local_8 = __security_cookie ^ (uint)auStack_94;
  if (*in_ECX == *in_EDX) {
    if (in_ECX[1] == in_EDX[1]) {
      if (in_ECX[2] == in_EDX[2]) {
        if (in_ECX[3] == in_EDX[3]) {
          if (in_ECX[4] == in_EDX[4]) {
            local_90 = in_ECX + 5;
            iVar1 = _stricmp((char *)local_90,(char *)(in_EDX + 5));
            if (iVar1 == 0) {
              local_90 = in_ECX + 0x15;
              iVar1 = _stricmp((char *)local_90,(char *)(in_EDX + 0x15));
              if (iVar1 == 0) {
                local_90 = in_ECX + 0x25;
                iVar1 = _stricmp((char *)local_90,(char *)(in_EDX + 0x25));
                if (iVar1 == 0) {
                  if (in_ECX[0x35] == in_EDX[0x35]) {
                    return true;
                  }
                  pcVar2 = "POWERUPCLASS MISMATCH: DelayTime: %d and %d";
                }
                else {
                  pcVar2 = "POWERUPCLASS MISMATCH: SoundReject: \'%s\' and \'%s\'";
                }
              }
              else {
                pcVar2 = "POWERUPCLASS MISMATCH: SoundPickup: \'%s\' and \'%s\'";
              }
            }
            else {
              pcVar2 = "POWERUPCLASS MISMATCH: WeaponUp: \'%s\' and \'%s\'";
            }
          }
          else {
            pcVar2 = "POWERUPCLASS MISMATCH: LocalAmmoUp: %d and %d";
          }
        }
        else {
          pcVar2 = "POWERUPCLASS MISMATCH: AmmoUp: %d and %d";
        }
      }
      else {
        pcVar2 = "POWERUPCLASS MISMATCH: HealthUp: %d and %d";
      }
    }
    else {
      pcVar2 = "POWERUPCLASS MISMATCH: ObjClassHash: %d and %d";
    }
    FormatLogMessage(pcVar2);
  }
  else {
    memset(local_4c,0,0x40);
    memset(local_8c,0,0x40);
    GetODFName(unaff_EDI,unaff_ESI);
    GetODFName(unaff_EDI,unaff_ESI);
    FormatLogMessage("POWERUPCLASS MISMATCH: RepairPowerupObject: %08x \'%s\' and %08x \'%s\'");
  }
  return false;
}

