// Reconstructed by Ghidra from Strategy02.dll + Strategy02.pdb
// Original source file: /e:/github/vsr_dll_source/missions/vsrcore/objecthelper.h
// Functions are ordered by original source line. This is decompiler
// output, not the author's source: names/types come from the PDB,
// local variable names and control flow are reconstructed.

// ---------------------------------------------------------------------
// operator==  @ 4fc24c01  lines 55-174

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool __cdecl operator==(ObjectClass *a,ObjectClass *b)

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
  char ODFNameA [64];
  char ODFNameB [68];
  uint local_8;
  
  local_8 = __security_cookie ^ (uint)&stack0xfffffffc;
  iVar8 = a->ObjectHandle;
  if (iVar8 == b->ObjectHandle) {
    if (a->ODFNameHash == b->ODFNameHash) {
      if (a->ObjClassHash == b->ObjClassHash) {
        if (a->BZCClassHash == b->BZCClassHash) {
          if (a->CategoryID == b->CategoryID) {
            if (a->CanObjectify == b->CanObjectify) {
              if (a->CanObjectifyDeployed == b->CanObjectifyDeployed) {
                if (a->CanTeleport == b->CanTeleport) {
                  if (a->CanBeIdleVictim == b->CanBeIdleVictim) {
                    if (a->OriginalTeam == b->OriginalTeam) {
                      if (a->CurTeamNum == b->CurTeamNum) {
                        if (a->PTeam == b->PTeam) {
                          if (a->EngageRange != b->EngageRange) {
                            pcVar9 = "OBJECTLIST MISMATCH: EngageRange: %f and %f";
                            goto LAB_4fc24c6f;
                          }
                          iVar8 = 0;
                          do {
                            if (a->IsObjectified[iVar8] !=
                                (a->IsObjectified + iVar8)[(int)b - (int)a]) {
                              pcVar9 = "OBJECTLIST MISMATCH: IsObjectified%d: %d and %d";
LAB_4fc24e8a:
                              FormatLogMessage(pcVar9);
                              return false;
                            }
                            if (a->IsBeingJammed[iVar8] != b->IsBeingJammed[iVar8]) {
                              pcVar9 = "OBJECTLIST MISMATCH: IsBeingJammed%d: %d and %d";
                              goto LAB_4fc24e8a;
                            }
                            iVar8 = iVar8 + 1;
                          } while (iVar8 < 0x10);
                          fVar1 = (b->Position).x;
                          fVar2 = (a->Position).x;
                          if (((fVar2 != fVar1) || ((a->Position).y != (b->Position).y)) ||
                             ((a->Position).z != (b->Position).z)) {
                            dVar3 = (double)(b->Position).z;
                            dVar4 = (double)(b->Position).y;
                            dVar5 = (double)fVar1;
                            dVar6 = (double)(a->Position).z;
                            dVar7 = (double)(a->Position).y;
                            FormatLogMessage("OBJECTLIST MISMATCH: Position: %f %f %f and %f %f %f",
                                             (double)CONCAT44(SUB84(dVar7,0),
                                                              (int)((ulonglong)(double)fVar2 >> 0x20
                                                                   )),
                                             (double)CONCAT44(SUB84(dVar6,0),
                                                              (int)((ulonglong)dVar7 >> 0x20)),
                                             (double)CONCAT44(SUB84(dVar5,0),
                                                              (int)((ulonglong)dVar6 >> 0x20)),
                                             (double)CONCAT44(SUB84(dVar4,0),
                                                              (int)((ulonglong)dVar5 >> 0x20)),
                                             (double)CONCAT44(SUB84(dVar3,0),
                                                              (int)((ulonglong)dVar4 >> 0x20)),
                                             (double)CONCAT44(unaff_EDI,
                                                              (int)((ulonglong)dVar3 >> 0x20)));
                            return false;
                          }
                          if (a->MaxHealth == b->MaxHealth) {
                            if (a->MaxAmmo == b->MaxAmmo) {
                              return true;
                            }
                            pcVar9 = "OBJECTLIST MISMATCH: MaxAmmo: %d and %d";
                          }
                          else {
                            pcVar9 = "OBJECTLIST MISMATCH: MaxHealth: %d and %d";
                          }
                        }
                        else {
                          pcVar9 = "OBJECTLIST MISMATCH: PTeam: %d and %d";
                        }
                      }
                      else {
                        pcVar9 = "OBJECTLIST MISMATCH: CurTeamNum: %d and %d";
                      }
                    }
                    else {
                      pcVar9 = "OBJECTLIST MISMATCH: OriginalTeam: %d and %d";
                    }
                  }
                  else {
                    pcVar9 = "OBJECTLIST MISMATCH: CanBeIdleVictim: %d and %d";
                  }
                }
                else {
                  pcVar9 = "OBJECTLIST MISMATCH: CanTeleport: %d and %d";
                }
              }
              else {
                pcVar9 = "OBJECTLIST MISMATCH: CanObjectifyDeployed: %d and %d";
              }
            }
            else {
              pcVar9 = "OBJECTLIST MISMATCH: CanObjectify: %d and %d";
            }
          }
          else {
            pcVar9 = "OBJECTLIST MISMATCH: CategoryID: %d and %d";
          }
        }
        else {
          pcVar9 = "OBJECTLIST MISMATCH: BZCClassHash: %d and %d";
        }
      }
      else {
        pcVar9 = "OBJECTLIST MISMATCH: ObjClassHash: %d and %d";
      }
    }
    else {
      pcVar9 = "OBJECTLIST MISMATCH: ODFNameHash: %d and %d";
    }
    FormatLogMessage(pcVar9);
  }
  else {
    memset(ODFNameA,0,0x40);
    memset(ODFNameB,0,0x40);
    GetODFName(iVar8,ODFNameA);
    GetODFName(b->ObjectHandle,ODFNameB);
    pcVar9 = "OBJECTLIST MISMATCH: ObjectHandle: %08x \'%s\' and %08x \'%s\'";
LAB_4fc24c6f:
    FormatLogMessage(pcVar9);
  }
  return false;
}


// ---------------------------------------------------------------------
// ObjectHelper::GetNumHandles  @ 4fc09787  lines 188-188

int __thiscall ObjectHelper::GetNumHandles(ObjectHelper *this)

{
  return (*(int *)&(this->HandleList).field_0x4 - *(int *)&this->HandleList) / 0x5c;
}


