// Reconstructed by Ghidra from Strategy02.dll + Strategy02.pdb
// Original source file: /e:/github/vsr_dll_source/missions/shared/dllutils.cpp
// Functions are ordered by original source line. This is decompiler
// output, not the author's source: names/types come from the PDB,
// local variable names and control flow are reconstructed.


// ---------------------------------------------------------------------
// DLLUtils::IsRecycler  @ 4fc40876  lines 9-17


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool __cdecl DLLUtils::IsRecycler(int param_1)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  int in_ECX;
  char local_48 [64];
  undefined4 local_8;
  
  local_8 = __security_cookie ^ (uint)(local_48 + 0x44);
  bVar1 = GetObjInfo(in_ECX,Get_GOClass,local_48);
  bVar2 = false;
  if (bVar1) {
    iVar3 = _stricmp(local_48,"CLASS_RECYCLERVEHICLE");
    if (((iVar3 == 0) || (iVar3 = _stricmp(local_48,"CLASS_RECYCLER"), iVar3 == 0)) ||
       (iVar3 = _stricmp(local_48,"CLASS_RECYCLERVEHICLEH"), iVar3 == 0)) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
  }
  return bVar2;
}


// ---------------------------------------------------------------------
// DLLUtils::CountAlliedPlayers  @ 4fc40845  lines 26-43


int __cdecl DLLUtils::CountAlliedPlayers(int param_1)

{
  bool bVar1;
  int iVar2;
  int in_ECX;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  iVar3 = 1;
  do {
    bVar1 = IsTeamAllied(iVar3,in_ECX);
    if (bVar1) {
      iVar2 = GetPlayerHandle(iVar3);
      if (iVar2 != 0) {
        iVar4 = iVar4 + 1;
      }
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0x10);
  return iVar4;
}


// ---------------------------------------------------------------------
// DLLUtils::GetCheckedNetworkSvar  @ 4fc407f9  lines 49-77


char * __cdecl DLLUtils::GetCheckedNetworkSvar(uint param_1,NETWORK_LIST_TYPE param_2)

{
  uint uVar1;
  char *_Str2;
  int iVar2;
  NETWORK_LIST_TYPE in_ECX;
  char *in_EDX;
  uint uVar3;
  
  uVar1 = GetNetworkListCount(in_ECX);
  uVar3 = 0;
  if (uVar1 != 0) {
    do {
      _Str2 = GetNetworkListItem(in_ECX,uVar3);
      if ((_Str2 != (char *)0x0) && (iVar2 = _stricmp(in_EDX,_Str2), iVar2 == 0)) {
        return in_EDX;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar1);
  }
  return (char *)0x0;
}

