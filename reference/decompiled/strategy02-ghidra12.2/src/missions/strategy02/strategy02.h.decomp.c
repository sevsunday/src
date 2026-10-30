// Reconstructed by Ghidra from Strategy02.dll + Strategy02.pdb
// Original source file: /e:/github/vsr_dll_source/missions/strategy02/strategy02.h
// Functions are ordered by original source line. This is decompiler
// output, not the author's source: names/types come from the PDB,
// local variable names and control flow are reconstructed.


// ---------------------------------------------------------------------
// Strategy02::ShouldRemoveThugScavengerObject  @ 4fc01cdf  lines 29-32


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool __cdecl Strategy02::ShouldRemoveThugScavengerObject(ThugScavengerClass *param_1)

{
  bool bVar1;
  int iVar2;
  char local_48 [64];
  undefined4 local_8;
  
  local_8 = __security_cookie ^ (uint)(local_48 + 0x44);
  memset(local_48,0,0x40);
  GetObjInfo(param_1->ThugScavengerObject,Get_GOClass,local_48);
  bVar1 = IsAround(param_1->ThugScavengerObject);
  if (((bVar1) && (iVar2 = _stricmp(local_48,"CLASS_EXTRACTOR"), iVar2 != 0)) &&
     (iVar2 = _stricmp(local_48,"CLASS_SILO"), iVar2 != 0)) {
    return false;
  }
  return true;
}


// ---------------------------------------------------------------------
// Strategy02::ShouldRemoveThugPilotObject  @ 4fc01d59  lines 40-40


bool __cdecl Strategy02::ShouldRemoveThugPilotObject(ThugPilotClass *param_1)

{
  bool bVar1;
  
  bVar1 = IsAround(param_1->ThugPilotObject);
  if (((bVar1) && (-1 < param_1->SwitchTickTimer)) &&
     (bVar1 = IsPlayer(param_1->ThugPilotObject), !bVar1)) {
    return false;
  }
  return true;
}


// ---------------------------------------------------------------------
// Strategy02::ShouldRemoveEmptyShipObject  @ 4fc01d8a  lines 50-50


bool __cdecl Strategy02::ShouldRemoveEmptyShipObject(EmptyShipClass *param_1)

{
  bool bVar1;
  long lVar2;
  
  bVar1 = IsAround(param_1->EmptyShipObject);
  if ((bVar1) && (lVar2 = GetMaxHealth(param_1->EmptyShipObject), lVar2 < 1)) {
    return false;
  }
  return true;
}


// ---------------------------------------------------------------------
// Strategy02::ShouldRemoveMorphTankObject  @ 4fc01db4  lines 58-58


bool __cdecl Strategy02::ShouldRemoveMorphTankObject(MorphTankClass *param_1)

{
  bool bVar1;
  
  bVar1 = IsAround(param_1->MorphTankObject);
  if ((bVar1) && (param_1->CmdSet == false)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  return bVar1;
}

