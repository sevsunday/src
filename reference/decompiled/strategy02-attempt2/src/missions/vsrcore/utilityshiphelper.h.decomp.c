// Reconstructed by Ghidra from Strategy02.dll + Strategy02.pdb
// Original source file: /e:/github/vsr_dll_source/missions/vsrcore/utilityshiphelper.h
// Functions are ordered by original source line. This is decompiler
// output, not the author's source: names/types come from the PDB,
// local variable names and control flow are reconstructed.

// ---------------------------------------------------------------------
// operator==  @ 4fc14e5a  lines 32-96

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool __cdecl operator==(UtilityShipClass *a,UtilityShipClass *b)

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
  char *format;
  char ODFNameA [64];
  char ODFNameB [68];
  uint local_8;
  
  local_8 = __security_cookie ^ (uint)&stack0xfffffffc;
  h = a->UtilityShipObject;
  if (h == b->UtilityShipObject) {
    if (a->DoDrop == b->DoDrop) {
      if (a->ServiceAllies == b->ServiceAllies) {
        if (a->DoDLLDispatch == b->DoDLLDispatch) {
          if (a->ObjClassHash == b->ObjClassHash) {
            if (a->CurTeamNum == b->CurTeamNum) {
              if (a->ScrapAmount == b->ScrapAmount) {
                if (a->EscortPriority == b->EscortPriority) {
                  if (a->DropClassMask == b->DropClassMask) {
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
                    FormatLogMessage("BUILDINGCLASS MISMATCH: Position: %f %f %f and %f %f %f",
                                     (double)CONCAT44(SUB84(dVar7,0),
                                                      (int)((ulonglong)(double)fVar2 >> 0x20)),
                                     (double)CONCAT44(SUB84(dVar6,0),(int)((ulonglong)dVar7 >> 0x20)
                                                     ),
                                     (double)CONCAT44(SUB84(dVar5,0),(int)((ulonglong)dVar6 >> 0x20)
                                                     ),
                                     (double)CONCAT44(SUB84(dVar4,0),(int)((ulonglong)dVar5 >> 0x20)
                                                     ),
                                     (double)CONCAT44(SUB84(dVar3,0),(int)((ulonglong)dVar4 >> 0x20)
                                                     ),
                                     (double)CONCAT44(unaff_EDI,(int)((ulonglong)dVar3 >> 0x20)));
                    return false;
                  }
                  format = "UTILITYSHIPCLASS MISMATCH: DropClassMask: %d and %d";
                }
                else {
                  format = "UTILITYSHIPCLASS MISMATCH: EscortPriority: %d and %d";
                }
              }
              else {
                format = "UTILITYSHIPCLASS MISMATCH: ScrapAmount: %d and %d";
              }
            }
            else {
              format = "UTILITYSHIPCLASS MISMATCH: CurTeamNum: %d and %d";
            }
          }
          else {
            format = "UTILITYSHIPCLASS MISMATCH: ObjClassHash: %d and %d";
          }
        }
        else {
          format = "UTILITYSHIPCLASS MISMATCH: DoDLLDispatch: %d and %d";
        }
      }
      else {
        format = "UTILITYSHIPCLASS MISMATCH: ServiceAllies: %d and %d";
      }
    }
    else {
      format = "UTILITYSHIPCLASS MISMATCH: DoDrop: %d and %d";
    }
    FormatLogMessage(format);
  }
  else {
    memset(ODFNameA,0,0x40);
    memset(ODFNameB,0,0x40);
    GetODFName(h,ODFNameA);
    GetODFName(b->UtilityShipObject,ODFNameB);
    FormatLogMessage("UTILITYSHIPCLASS MISMATCH: UtilityShipObject: %08x \'%s\' and %08x \'%s\'",
                     a->UtilityShipObject,ODFNameA,b->UtilityShipObject,ODFNameB);
  }
  return false;
}


