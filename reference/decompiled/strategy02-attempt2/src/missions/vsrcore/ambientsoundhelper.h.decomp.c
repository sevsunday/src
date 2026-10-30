// Reconstructed by Ghidra from Strategy02.dll + Strategy02.pdb
// Original source file: /e:/github/vsr_dll_source/missions/vsrcore/ambientsoundhelper.h
// Functions are ordered by original source line. This is decompiler
// output, not the author's source: names/types come from the PDB,
// local variable names and control flow are reconstructed.

// ---------------------------------------------------------------------
// operator==  @ 4fc13e7d  lines 30-101

bool __cdecl operator==(AmbientAudioInfo *a,AmbientAudioInfo *b)

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
  
  if (a->AudioHandle == b->AudioHandle) {
    iVar8 = _stricmp(a->AudioFile,b->AudioFile);
    if (iVar8 == 0) {
      if (a->MinDelay == b->MinDelay) {
        if (a->MaxDelay == b->MaxDelay) {
          if (a->IsMusic == b->IsMusic) {
            if (a->BasePan == b->BasePan) {
              if (a->PanVariance == b->PanVariance) {
                if (a->Rate == b->Rate) {
                  if (a->TriggerTurn == b->TriggerTurn) {
                    if (a->AudioLength == b->AudioLength) {
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
                      FormatLogMessage("AMBIENTAUDIOCLASS MISMATCH: Position: %f %f %f and %f %f %f"
                                       ,(double)CONCAT44(SUB84(dVar7,0),
                                                         (int)((ulonglong)(double)fVar2 >> 0x20)),
                                       (double)CONCAT44(SUB84(dVar6,0),
                                                        (int)((ulonglong)dVar7 >> 0x20)),
                                       (double)CONCAT44(SUB84(dVar5,0),
                                                        (int)((ulonglong)dVar6 >> 0x20)),
                                       (double)CONCAT44(SUB84(dVar4,0),
                                                        (int)((ulonglong)dVar5 >> 0x20)),
                                       (double)CONCAT44(SUB84(dVar3,0),
                                                        (int)((ulonglong)dVar4 >> 0x20)),
                                       (double)CONCAT44(unaff_EDI,(int)((ulonglong)dVar3 >> 0x20)));
                      return false;
                    }
                    pcVar9 = "AMBIENTAUDIOCLASS MISMATCH: AudioLength: %d and %d";
                  }
                  else {
                    pcVar9 = "AMBIENTAUDIOCLASS MISMATCH: TriggerTurn: %d and %d";
                  }
                  goto LAB_4fc13e95;
                }
                pcVar9 = "AMBIENTAUDIOCLASS MISMATCH: Rate: %f and %f";
              }
              else {
                pcVar9 = "AMBIENTAUDIOCLASS MISMATCH: PanVariance: %f and %f";
              }
            }
            else {
              pcVar9 = "AMBIENTAUDIOCLASS MISMATCH: BasePan: %f and %f";
            }
            FormatLogMessage(pcVar9);
            return false;
          }
          pcVar9 = "AMBIENTAUDIOCLASS MISMATCH: IsMusic: %d and %d";
        }
        else {
          pcVar9 = "AMBIENTAUDIOCLASS MISMATCH: MaxDelay: %d and %d";
        }
      }
      else {
        pcVar9 = "AMBIENTAUDIOCLASS MISMATCH: MinDelay: %d and %d";
      }
    }
    else {
      pcVar9 = "AMBIENTAUDIOCLASS MISMATCH: AudioFile: \'%s\' and \'%s\'";
    }
  }
  else {
    pcVar9 = "AMBIENTAUDIOCLASS MISMATCH: AudioHandle: %d and %d";
  }
LAB_4fc13e95:
  FormatLogMessage(pcVar9);
  return false;
}


