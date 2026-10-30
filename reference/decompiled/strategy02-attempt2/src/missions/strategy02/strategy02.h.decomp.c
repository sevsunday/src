// Reconstructed by Ghidra from Strategy02.dll + Strategy02.pdb
// Original source file: /e:/github/vsr_dll_source/missions/strategy02/strategy02.h
// Functions are ordered by original source line. This is decompiler
// output, not the author's source: names/types come from the PDB,
// local variable names and control flow are reconstructed.

// ---------------------------------------------------------------------
// Strategy02::ShouldRemoveThugScavengerObject  @ 4fc01cdf  lines 29-32

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool __cdecl Strategy02::ShouldRemoveThugScavengerObject(ThugScavengerClass *entry)

{
  bool bVar1;
  int iVar2;
  char ObjClass [64];
  uint local_8;
  
  local_8 = __security_cookie ^ (uint)&stack0xfffffffc;
  memset(ObjClass,0,0x40);
  GetObjInfo(entry->ThugScavengerObject,Get_GOClass,ObjClass);
  bVar1 = IsAround(entry->ThugScavengerObject);
  if (((bVar1) && (iVar2 = _stricmp(ObjClass,"CLASS_EXTRACTOR"), iVar2 != 0)) &&
     (iVar2 = _stricmp(ObjClass,"CLASS_SILO"), iVar2 != 0)) {
    return false;
  }
  return true;
}


// ---------------------------------------------------------------------
// Strategy02::ShouldRemoveThugPilotObject  @ 4fc01d59  lines 40-40

bool __cdecl Strategy02::ShouldRemoveThugPilotObject(ThugPilotClass *entry)

{
  bool bVar1;
  
  bVar1 = IsAround(entry->ThugPilotObject);
  if (((bVar1) && (-1 < entry->SwitchTickTimer)) &&
     (bVar1 = IsPlayer(entry->ThugPilotObject), !bVar1)) {
    return false;
  }
  return true;
}


// ---------------------------------------------------------------------
// Strategy02::ShouldRemoveEmptyShipObject  @ 4fc01d8a  lines 50-50

bool __cdecl Strategy02::ShouldRemoveEmptyShipObject(EmptyShipClass *entry)

{
  bool bVar1;
  long lVar2;
  
  bVar1 = IsAround(entry->EmptyShipObject);
  if ((bVar1) && (lVar2 = GetMaxHealth(entry->EmptyShipObject), lVar2 < 1)) {
    return false;
  }
  return true;
}


// ---------------------------------------------------------------------
// Strategy02::ShouldRemoveMorphTankObject  @ 4fc01db4  lines 58-58

bool __cdecl Strategy02::ShouldRemoveMorphTankObject(MorphTankClass *entry)

{
  bool bVar1;
  
  bVar1 = IsAround(entry->MorphTankObject);
  if ((bVar1) && (entry->CmdSet == false)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  return bVar1;
}


