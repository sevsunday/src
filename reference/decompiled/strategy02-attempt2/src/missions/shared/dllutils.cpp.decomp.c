// Reconstructed by Ghidra from Strategy02.dll + Strategy02.pdb
// Original source file: /e:/github/vsr_dll_source/missions/shared/dllutils.cpp
// Functions are ordered by original source line. This is decompiler
// output, not the author's source: names/types come from the PDB,
// local variable names and control flow are reconstructed.

// ---------------------------------------------------------------------
// DLLUtils::IsRecycler  @ 4fc40876  lines 9-17

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool __cdecl DLLUtils::IsRecycler(int h)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  char ObjClass [64];
  uint local_8;
  
  local_8 = __security_cookie ^ (uint)&stack0xfffffffc;
  bVar1 = GetObjInfo(h,Get_GOClass,ObjClass);
  bVar2 = false;
  if (bVar1) {
    iVar3 = _stricmp(ObjClass,"CLASS_RECYCLERVEHICLE");
    if (((iVar3 == 0) || (iVar3 = _stricmp(ObjClass,"CLASS_RECYCLER"), iVar3 == 0)) ||
       (iVar3 = _stricmp(ObjClass,"CLASS_RECYCLERVEHICLEH"), iVar3 == 0)) {
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

int __cdecl DLLUtils::CountAlliedPlayers(int team)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  iVar3 = 1;
  do {
    bVar1 = IsTeamAllied(iVar3,team);
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

char * __cdecl DLLUtils::GetCheckedNetworkSvar(uint listType,NETWORK_LIST_TYPE pContents)

{
  uint uVar1;
  char *_Str2;
  int iVar2;
  uint uVar3;
  
  uVar1 = GetNetworkListCount(listType);
  uVar3 = 0;
  if (uVar1 != 0) {
    do {
      _Str2 = GetNetworkListItem(listType,uVar3);
      if ((_Str2 != (char *)0x0) && (iVar2 = _stricmp((char *)pContents,_Str2), iVar2 == 0)) {
        return (char *)pContents;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar1);
  }
  return (char *)0x0;
}


