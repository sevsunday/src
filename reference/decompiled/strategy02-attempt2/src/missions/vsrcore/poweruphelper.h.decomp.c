// Reconstructed by Ghidra from Strategy02.dll + Strategy02.pdb
// Original source file: /e:/github/vsr_dll_source/missions/vsrcore/poweruphelper.h
// Functions are ordered by original source line. This is decompiler
// output, not the author's source: names/types come from the PDB,
// local variable names and control flow are reconstructed.

// ---------------------------------------------------------------------
// operator==  @ 4fc2551f  lines 32-90

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool __cdecl operator==(PowerupClass *a,PowerupClass *b)

{
  int iVar1;
  char *format;
  undefined1 auStack_94 [4];
  char *local_90;
  char local_8c [64];
  char local_4c [68];
  uint local_8;
  
  local_8 = __security_cookie ^ (uint)auStack_94;
  iVar1 = a->PowerupObject;
  if (iVar1 == b->PowerupObject) {
    if (a->ObjClassHash == b->ObjClassHash) {
      if (a->HealthUp == b->HealthUp) {
        if (a->AmmoUp == b->AmmoUp) {
          if (a->LocalAmmoUp == b->LocalAmmoUp) {
            local_90 = a->WeaponUp;
            iVar1 = _stricmp(local_90,b->WeaponUp);
            if (iVar1 == 0) {
              local_90 = a->SoundPickup;
              iVar1 = _stricmp(local_90,b->SoundPickup);
              if (iVar1 == 0) {
                local_90 = a->SoundReject;
                iVar1 = _stricmp(local_90,b->SoundReject);
                if (iVar1 == 0) {
                  if (a->DelayTime == b->DelayTime) {
                    return true;
                  }
                  format = "POWERUPCLASS MISMATCH: DelayTime: %d and %d";
                }
                else {
                  format = "POWERUPCLASS MISMATCH: SoundReject: \'%s\' and \'%s\'";
                }
              }
              else {
                format = "POWERUPCLASS MISMATCH: SoundPickup: \'%s\' and \'%s\'";
              }
            }
            else {
              format = "POWERUPCLASS MISMATCH: WeaponUp: \'%s\' and \'%s\'";
            }
          }
          else {
            format = "POWERUPCLASS MISMATCH: LocalAmmoUp: %d and %d";
          }
        }
        else {
          format = "POWERUPCLASS MISMATCH: AmmoUp: %d and %d";
        }
      }
      else {
        format = "POWERUPCLASS MISMATCH: HealthUp: %d and %d";
      }
    }
    else {
      format = "POWERUPCLASS MISMATCH: ObjClassHash: %d and %d";
    }
    FormatLogMessage(format);
  }
  else {
    memset(local_4c,0,0x40);
    memset(local_8c,0,0x40);
    GetODFName(iVar1,local_4c);
    GetODFName(b->PowerupObject,local_8c);
    FormatLogMessage("POWERUPCLASS MISMATCH: RepairPowerupObject: %08x \'%s\' and %08x \'%s\'",
                     a->PowerupObject,local_4c,b->PowerupObject,local_8c);
  }
  return false;
}


