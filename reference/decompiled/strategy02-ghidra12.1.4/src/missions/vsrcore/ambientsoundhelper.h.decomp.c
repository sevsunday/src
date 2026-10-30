// Reconstructed by Ghidra from Strategy02.dll + Strategy02.pdb
// Original source file: /e:/github/vsr_dll_source/missions/vsrcore/ambientsoundhelper.h
// Functions are ordered by original source line. This is decompiler
// output, not the author's source: names/types come from the PDB,
// local variable names and control flow are reconstructed.


// ---------------------------------------------------------------------
// operator==  @ 4fc13e7d  lines 30-101


bool __cdecl operator==(AmbientAudioInfo *param_1,AmbientAudioInfo *param_2)

{
  int iVar1;
  int *in_ECX;
  int *in_EDX;
  char *pcVar2;
  
  if (*in_ECX == *in_EDX) {
    iVar1 = _stricmp((char *)(in_ECX + 1),(char *)(in_EDX + 1));
    if (iVar1 == 0) {
      if (in_ECX[0x11] == in_EDX[0x11]) {
        if (in_ECX[0x12] == in_EDX[0x12]) {
          if ((char)in_ECX[0x13] == (char)in_EDX[0x13]) {
            if ((float)in_ECX[0x14] == (float)in_EDX[0x14]) {
              if ((float)in_ECX[0x15] == (float)in_EDX[0x15]) {
                if ((float)in_ECX[0x16] == (float)in_EDX[0x16]) {
                  if (in_ECX[0x17] == in_EDX[0x17]) {
                    if (in_ECX[0x18] == in_EDX[0x18]) {
                      if ((((float)in_ECX[0x19] == (float)in_EDX[0x19]) &&
                          ((float)in_ECX[0x1a] == (float)in_EDX[0x1a])) &&
                         ((float)in_ECX[0x1b] == (float)in_EDX[0x1b])) {
                        return true;
                      }
                      FormatLogMessage("AMBIENTAUDIOCLASS MISMATCH: Position: %f %f %f and %f %f %f"
                                      );
                      return false;
                    }
                    pcVar2 = "AMBIENTAUDIOCLASS MISMATCH: AudioLength: %d and %d";
                  }
                  else {
                    pcVar2 = "AMBIENTAUDIOCLASS MISMATCH: TriggerTurn: %d and %d";
                  }
                  goto LAB_4fc13e95;
                }
                pcVar2 = "AMBIENTAUDIOCLASS MISMATCH: Rate: %f and %f";
              }
              else {
                pcVar2 = "AMBIENTAUDIOCLASS MISMATCH: PanVariance: %f and %f";
              }
            }
            else {
              pcVar2 = "AMBIENTAUDIOCLASS MISMATCH: BasePan: %f and %f";
            }
            FormatLogMessage(pcVar2);
            return false;
          }
          pcVar2 = "AMBIENTAUDIOCLASS MISMATCH: IsMusic: %d and %d";
        }
        else {
          pcVar2 = "AMBIENTAUDIOCLASS MISMATCH: MaxDelay: %d and %d";
        }
      }
      else {
        pcVar2 = "AMBIENTAUDIOCLASS MISMATCH: MinDelay: %d and %d";
      }
    }
    else {
      pcVar2 = "AMBIENTAUDIOCLASS MISMATCH: AudioFile: \'%s\' and \'%s\'";
    }
  }
  else {
    pcVar2 = "AMBIENTAUDIOCLASS MISMATCH: AudioHandle: %d and %d";
  }
LAB_4fc13e95:
  FormatLogMessage(pcVar2);
  return false;
}

