// Reconstructed by Ghidra from Strategy02.dll + Strategy02.pdb
// Original source file: /e:/github/vsr_dll_source/missions/shared/trnallies.cpp
// Functions are ordered by original source line. This is decompiler
// output, not the author's source: names/types come from the PDB,
// local variable names and control flow are reconstructed.

// ---------------------------------------------------------------------
// TRNAllies::SetupTRNAllies  @ 4fc47061  lines 9-53

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __cdecl TRNAllies::SetupTRNAllies(char *pTRNName)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  int fmtarg1;
  char keyName [256];
  char tempStr [256];
  uint local_8;
  
  local_8 = __security_cookie ^ (uint)&stack0xfffffffc;
  if ((pTRNName != (char *)0x0) && (*pTRNName != '\0')) {
    OpenODF(pTRNName);
    iVar4 = 1;
    fmtarg1 = iVar4;
    do {
      sprintf_s<256>(&keyName,"Entry%d",fmtarg1);
      iVar1 = GetODFString(pTRNName,"DefaultAllies",keyName,0x100,tempStr,"");
      if (iVar1 == 0) {
        iVar4 = 0;
      }
      else {
        iVar1 = atoi(tempStr);
        pcVar2 = strchr(tempStr,0x5f);
        if (pcVar2 == (char *)0x0) {
          iVar3 = 0;
        }
        else {
          iVar3 = atoi(pcVar2 + 1);
        }
        if ((iVar1 - 1U < 0xf) && (iVar3 - 1U < 0xf)) {
          Ally(iVar1,iVar3);
        }
        fmtarg1 = fmtarg1 + 1;
      }
    } while ((char)iVar4 != '\0');
    CloseODF(pTRNName);
  }
  return;
}


