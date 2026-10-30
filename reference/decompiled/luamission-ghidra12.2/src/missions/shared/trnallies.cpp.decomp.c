// Reconstructed by Ghidra from LuaMission.dll + LuaMission.pdb
// Original source file: /e:/github/vsr_dll_source/missions/shared/trnallies.cpp
// Functions are ordered by original source line. This is decompiler
// output, not the author's source: names/types come from the PDB,
// local variable names and control flow are reconstructed.


// ---------------------------------------------------------------------
// TRNAllies::SetupTRNAllies  @ 4fc4e393  lines 9-53


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __cdecl TRNAllies::SetupTRNAllies(char *param_1)

{
  bool bVar1;
  int iVar2;
  char *pcVar3;
  char *in_ECX;
  int local_20c;
  char local_208 [256];
  char local_108 [256];
  undefined4 local_8;
  
  local_8 = __security_cookie ^ (uint)(local_108 + 0x104);
  if ((in_ECX != (char *)0x0) && (*in_ECX != '\0')) {
    OpenODF(in_ECX);
    bVar1 = true;
    do {
      sprintf_s<256>(&local_208,"Entry%d");
      iVar2 = GetODFString(in_ECX,"DefaultAllies",local_208,0x100,local_108,"");
      if (iVar2 == 0) {
        bVar1 = false;
      }
      else {
        local_20c = 0;
        iVar2 = atoi(local_108);
        pcVar3 = strchr(local_108,0x5f);
        if (pcVar3 != (char *)0x0) {
          local_20c = atoi(pcVar3 + 1);
        }
        if ((iVar2 - 1U < 0xf) && (local_20c - 1U < 0xf)) {
          Ally(iVar2,local_20c);
        }
      }
    } while (bVar1);
    CloseODF(in_ECX);
  }
  return;
}

