// Reconstructed by Ghidra from deathmatch01.dll + deathmatch01.pdb
// Original source file: /e:/github/vsr_dll_source/missions/shared/dllutils.cpp
// Functions are ordered by original source line. This is decompiler
// output, not the author's source: names/types come from the PDB,
// local variable names and control flow are reconstructed.


// ---------------------------------------------------------------------
// DLLUtils::GetCheckedNetworkSvar  @ 4fc4304a  lines 49-77


char * __cdecl DLLUtils::GetCheckedNetworkSvar(uint param_1,NETWORK_LIST_TYPE param_2)

{
  uint uVar1;
  char *_Str2;
  int iVar2;
  char *in_ECX;
  uint uVar3;
  
  uVar1 = GetNetworkListCount(NETLIST_Animals);
  uVar3 = 0;
  if (uVar1 != 0) {
    do {
      _Str2 = GetNetworkListItem(NETLIST_Animals,uVar3);
      if ((_Str2 != (char *)0x0) && (iVar2 = _stricmp(in_ECX,_Str2), iVar2 == 0)) {
        return in_ECX;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar1);
  }
  return (char *)0x0;
}

