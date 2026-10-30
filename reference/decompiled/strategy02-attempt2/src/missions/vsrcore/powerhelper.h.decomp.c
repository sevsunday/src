// Reconstructed by Ghidra from Strategy02.dll + Strategy02.pdb
// Original source file: /e:/github/vsr_dll_source/missions/vsrcore/powerhelper.h
// Functions are ordered by original source line. This is decompiler
// output, not the author's source: names/types come from the PDB,
// local variable names and control flow are reconstructed.

// ---------------------------------------------------------------------
// operator==  @ 4fc145f9  lines 28-96

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool __cdecl operator==(PowerClass *a,PowerClass *b)

{
  float fVar1;
  float fVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  int h;
  undefined4 unaff_EDI;
  char *pcVar8;
  char ODFNameA [64];
  char ODFNameB [68];
  uint local_8;
  
  local_8 = __security_cookie ^ (uint)&stack0xfffffffc;
  h = a->PowerObject;
  if (h == b->PowerObject) {
    if (a->WasDemolished == b->WasDemolished) {
      if (a->DoBettyLost == b->DoBettyLost) {
        if (a->IsPowered == b->IsPowered) {
          if (a->PowerTeam == b->PowerTeam) {
            if (a->PowerRange != b->PowerRange) {
              pcVar8 = "POWERCLASS MISMATCH: PowerRange: %f and %f";
              goto LAB_4fc14667;
            }
            if (a->PowerMask == b->PowerMask) {
              if (a->PowerMatch == b->PowerMatch) {
                if (a->PowerProvide == b->PowerProvide) {
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
                  FormatLogMessage("POWERCLASS MISMATCH: Position: %f %f %f and %f %f %f",
                                   (double)CONCAT44(SUB84(dVar7,0),
                                                    (int)((ulonglong)(double)fVar2 >> 0x20)),
                                   (double)CONCAT44(SUB84(dVar6,0),(int)((ulonglong)dVar7 >> 0x20)),
                                   (double)CONCAT44(SUB84(dVar5,0),(int)((ulonglong)dVar6 >> 0x20)),
                                   (double)CONCAT44(SUB84(dVar4,0),(int)((ulonglong)dVar5 >> 0x20)),
                                   (double)CONCAT44(SUB84(dVar3,0),(int)((ulonglong)dVar4 >> 0x20)),
                                   (double)CONCAT44(unaff_EDI,(int)((ulonglong)dVar3 >> 0x20)));
                  return false;
                }
                pcVar8 = "POWERCLASS MISMATCH: PowerProvide: %d and %d";
              }
              else {
                pcVar8 = "POWERCLASS MISMATCH: PowerMatch: %d and %d";
              }
            }
            else {
              pcVar8 = "POWERCLASS MISMATCH: PowerMask: %d and %d";
            }
          }
          else {
            pcVar8 = "POWERCLASS MISMATCH: PowerTeam: %d and %d";
          }
        }
        else {
          pcVar8 = "POWERCLASS MISMATCH: IsPowered: %d and %d";
        }
      }
      else {
        pcVar8 = "POWERCLASS MISMATCH: DoBettyLost: %d and %d";
      }
    }
    else {
      pcVar8 = "POWERCLASS MISMATCH: WasDemolished: %d and %d";
    }
    FormatLogMessage(pcVar8);
  }
  else {
    memset(ODFNameA,0,0x40);
    memset(ODFNameB,0,0x40);
    GetODFName(h,ODFNameA);
    GetODFName(b->PowerObject,ODFNameB);
    pcVar8 = "POWERCLASS MISMATCH: ObjectHandle: %08x \'%s\' and %08x \'%s\'";
LAB_4fc14667:
    FormatLogMessage(pcVar8);
  }
  return false;
}


