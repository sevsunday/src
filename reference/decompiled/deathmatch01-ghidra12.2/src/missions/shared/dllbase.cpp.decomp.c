// Reconstructed by Ghidra from deathmatch01.dll + deathmatch01.pdb
// Original source file: /e:/github/vsr_dll_source/missions/shared/dllbase.cpp
// Functions are ordered by original source line. This is decompiler
// output, not the author's source: names/types come from the PDB,
// local variable names and control flow are reconstructed.


// ---------------------------------------------------------------------
// DLLBase::InitialSetup  @ 4fc43046  lines 12-13


void __thiscall DLLBase::InitialSetup(DLLBase *this)

{
  return;
}


// ---------------------------------------------------------------------
// DLLBase::Save  @ 4fc43041  lines 16-18


bool __thiscall DLLBase::Save(DLLBase *this,bool param_1)

{
  return true;
}


// ---------------------------------------------------------------------
// DLLBase::Load  @ 4fc4303c  lines 21-23


bool __thiscall DLLBase::Load(DLLBase *this,bool param_1)

{
  return true;
}


// ---------------------------------------------------------------------
// DLLBase::PostLoad  @ 4fc43037  lines 26-28


bool __thiscall DLLBase::PostLoad(DLLBase *this,bool param_1)

{
  return true;
}


// ---------------------------------------------------------------------
// DLLBase::AddObject  @ 4fc43034  lines 31-32


void __thiscall DLLBase::AddObject(DLLBase *this,int param_1)

{
  return;
}


// ---------------------------------------------------------------------
// DLLBase::DeleteObject  @ 4fc43031  lines 35-36


void __thiscall DLLBase::DeleteObject(DLLBase *this,int param_1)

{
  return;
}


// ---------------------------------------------------------------------
// DLLBase::Execute  @ 4fc43030  lines 39-40


void __thiscall DLLBase::Execute(DLLBase *this)

{
  return;
}


// ---------------------------------------------------------------------
// DLLBase::PostRun  @ 4fc4302f  lines 43-44


void __thiscall DLLBase::PostRun(DLLBase *this)

{
  return;
}


// ---------------------------------------------------------------------
// DLLBase::DeletePlayer  @ 4fc4302c  lines 47-48


void __thiscall DLLBase::DeletePlayer(DLLBase *this,ulong param_1)

{
  return;
}


// ---------------------------------------------------------------------
// DLLBase::SetWorld  @ 4fc43047  lines 51-52


void __thiscall DLLBase::SetWorld(DLLBase *this,int param_1)

{
  return;
}


// ---------------------------------------------------------------------
// DLLBase::ProcessCommand  @ 4fc43029  lines 55-56


void __thiscall DLLBase::ProcessCommand(DLLBase *this,ulong param_1)

{
  return;
}


// ---------------------------------------------------------------------
// DLLBase::SetRandomSeed  @ 4fc43026  lines 59-60


void __thiscall DLLBase::SetRandomSeed(DLLBase *this,ulong param_1)

{
  return;
}


// ---------------------------------------------------------------------
// DLLBase::AddPlayer  @ 4fc43021  lines 63-66


bool __thiscall DLLBase::AddPlayer(DLLBase *this,ulong param_1,int param_2,bool param_3)

{
  return false;
}


// ---------------------------------------------------------------------
// DLLBase::PlayerEjected  @ 4fc4301c  lines 69-71


EjectKillRetCodes __thiscall DLLBase::PlayerEjected(DLLBase *this,int param_1)

{
  return DoEjectPilot;
}


// ---------------------------------------------------------------------
// DLLBase::ObjectKilled  @ 4fc42fff  lines 74-79


EjectKillRetCodes __thiscall DLLBase::ObjectKilled(DLLBase *this,int param_1,int param_2)

{
  bool bVar1;
  EjectKillRetCodes EVar2;
  
  bVar1 = IsPlayer(param_1);
  EVar2 = DoEjectPilot;
  if (!bVar1) {
    EVar2 = DLLHandled;
  }
  return EVar2;
}


// ---------------------------------------------------------------------
// DLLBase::ObjectSniped  @ 4fc42fe4  lines 82-87


EjectKillRetCodes __thiscall DLLBase::ObjectSniped(DLLBase *this,int param_1,int param_2)

{
  bool bVar1;
  
  bVar1 = IsPlayer(param_1);
  return !bVar1 + DoRespawnSafest;
}


// ---------------------------------------------------------------------
// DLLBase::GetNextRandomVehicleODF  @ 4fc42fdc  lines 90-93


char * __thiscall DLLBase::GetNextRandomVehicleODF(DLLBase *this,int param_1)

{
  return "player";
}


// ---------------------------------------------------------------------
// DLLBase::PreSnipe  @ 4fc42fd7  lines 106-111


PreSnipeReturnCodes __thiscall
DLLBase::PreSnipe(DLLBase *this,int param_1,int param_2,int param_3,int param_4,char *param_5)

{
  return PRESNIPE_KILLPILOT;
}


// ---------------------------------------------------------------------
// DLLBase::PreOrdnanceHit  @ 4fc42fd4  lines 130-133


void __thiscall
DLLBase::PreOrdnanceHit(DLLBase *this,int param_1,int param_2,int param_3,char *param_4)

{
  return;
}


// ---------------------------------------------------------------------
// DLLBase::PreGetIn  @ 4fc42fce  lines 146-151


PreGetInReturnCodes __thiscall DLLBase::PreGetIn(DLLBase *this,int param_1,int param_2,int param_3)

{
  return PREGETIN_ALLOW;
}


// ---------------------------------------------------------------------
// DLLBase::PrePickupPowerup  @ 4fc42fc8  lines 163-168


PrePickupPowerupReturnCodes __thiscall
DLLBase::PrePickupPowerup(DLLBase *this,int param_1,int param_2,int param_3)

{
  return PREPICKUPPOWERUP_ALLOW;
}


// ---------------------------------------------------------------------
// DLLBase::PostTargetChangedCallback  @ 4fc42fc5  lines 172-175


void __thiscall
DLLBase::PostTargetChangedCallback(DLLBase *this,int param_1,int param_2,int param_3)

{
  return;
}


// ---------------------------------------------------------------------
// DLLBasePreSnipeCallback  @ 4fc42f9e  lines 181-193


PreSnipeReturnCodes __cdecl
DLLBasePreSnipeCallback(int param_1,int param_2,int param_3,int param_4,char *param_5)

{
  PreSnipeReturnCodes PVar1;
  
  if (Mission == (DLLBase *)0x0) {
    return PRESNIPE_KILLPILOT;
  }
  PVar1 = (**(code **)((int)*Mission + 0x48))(param_1,param_2,param_3,param_4,param_5);
  return PVar1;
}


// ---------------------------------------------------------------------
// DLLBasePreOrdnanceHitCallback  @ 4fc42f7e  lines 199-210


void __cdecl DLLBasePreOrdnanceHitCallback(int param_1,int param_2,int param_3,char *param_4)

{
  if (Mission != (DLLBase *)0x0) {
    (**(code **)((int)*Mission + 0x4c))(param_1,param_2,param_3,param_4);
  }
  return;
}


// ---------------------------------------------------------------------
// DLLBasePreGetInCallback  @ 4fc42f5c  lines 215-227


PreGetInReturnCodes __cdecl DLLBasePreGetInCallback(int param_1,int param_2,int param_3)

{
  PreGetInReturnCodes PVar1;
  
  if (Mission == (DLLBase *)0x0) {
    return PREGETIN_ALLOW;
  }
  PVar1 = (**(code **)((int)*Mission + 0x50))(param_1,param_2,param_3);
  return PVar1;
}


// ---------------------------------------------------------------------
// DLLBasePrePickupPowerupCallback  @ 4fc42f3a  lines 232-244


PrePickupPowerupReturnCodes __cdecl
DLLBasePrePickupPowerupCallback(int param_1,int param_2,int param_3)

{
  PrePickupPowerupReturnCodes PVar1;
  
  if (Mission == (DLLBase *)0x0) {
    return PREPICKUPPOWERUP_ALLOW;
  }
  PVar1 = (**(code **)((int)*Mission + 0x54))(param_1,param_2,param_3);
  return PVar1;
}


// ---------------------------------------------------------------------
// DLLBasePostTargetChangedCallback  @ 4fc42f1d  lines 249-260


void __cdecl DLLBasePostTargetChangedCallback(int param_1,int param_2,int param_3)

{
  if (Mission != (DLLBase *)0x0) {
    (**(code **)((int)*Mission + 0x58))(param_1,param_2,param_3);
  }
  return;
}


// ---------------------------------------------------------------------
// InitialSetup  @ 4fc42ec2  lines 266-278


void __cdecl InitialSetup(void)

{
  if (Mission == (DLLBase *)0x0) {
    Mission = BuildMission();
  }
  (**(code **)((int)*Mission + 4))();
  SetPreSnipeCallback(DLLBasePreSnipeCallback);
  SetPreOrdnanceHitCallback(DLLBasePreOrdnanceHitCallback);
  SetPreGetInCallback(DLLBasePreGetInCallback);
  SetPrePickupPowerupCallback(DLLBasePrePickupPowerupCallback);
  SetPostTargetChangedCallback(DLLBasePostTargetChangedCallback);
  return;
}


// ---------------------------------------------------------------------
// Save  @ 4fc42eaf  lines 281-283


bool __cdecl Save(bool param_1)

{
  undefined1 uVar1;
  undefined3 in_stack_00000005;
  
  uVar1 = (**(code **)((int)*Mission + 8))(_param_1);
  return (bool)uVar1;
}


// ---------------------------------------------------------------------
// Load  @ 4fc42e8d  lines 286-290


bool __cdecl Load(bool param_1)

{
  undefined1 uVar1;
  undefined3 in_stack_00000005;
  
  if (Mission == (DLLBase *)0x0) {
    Mission = BuildMission();
  }
  uVar1 = (**(code **)((int)*Mission + 0xc))(_param_1);
  return (bool)uVar1;
}


// ---------------------------------------------------------------------
// PostLoad  @ 4fc42e7a  lines 293-295


bool __cdecl PostLoad(bool param_1)

{
  undefined1 uVar1;
  undefined3 in_stack_00000005;
  
  uVar1 = (**(code **)((int)*Mission + 0x10))(_param_1);
  return (bool)uVar1;
}


// ---------------------------------------------------------------------
// AddObject  @ 4fc42e67  lines 298-300


void __cdecl AddObject(int param_1)

{
  (**(code **)((int)*Mission + 0x14))(param_1);
  return;
}


// ---------------------------------------------------------------------
// DeleteObject  @ 4fc42e54  lines 303-305


void __cdecl DeleteObject(int param_1)

{
  (**(code **)((int)*Mission + 0x18))(param_1);
  return;
}


// ---------------------------------------------------------------------
// Update  @ 4fc42e49  lines 308-309


void __cdecl Update(void)

{
                    /* WARNING: Could not recover jumptable at 0x4fc42e51. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)((int)*Mission + 0x1c))();
  return;
}


// ---------------------------------------------------------------------
// PostRun  @ 4fc42e2d  lines 313-316


void __cdecl PostRun(void)

{
  (**(code **)((int)*Mission + 0x20))();
  if (Mission != (DLLBase *)0x0) {
    (**(code **)*Mission)(1);
  }
  return;
}


// ---------------------------------------------------------------------
// AddPlayer  @ 4fc42e14  lines 319-321


bool __cdecl AddPlayer(ulong param_1,int param_2,bool param_3)

{
  undefined1 uVar1;
  undefined3 in_stack_0000000d;
  
  uVar1 = (**(code **)((int)*Mission + 0x24))(param_1,param_2,_param_3);
  return (bool)uVar1;
}


// ---------------------------------------------------------------------
// DeletePlayer  @ 4fc42e01  lines 324-326


void __cdecl DeletePlayer(ulong param_1)

{
  (**(code **)((int)*Mission + 0x28))(param_1);
  return;
}


// ---------------------------------------------------------------------
// PlayerEjected  @ 4fc42dee  lines 329-331


EjectKillRetCodes __cdecl PlayerEjected(int param_1)

{
  EjectKillRetCodes EVar1;
  
  EVar1 = (**(code **)((int)*Mission + 0x2c))(param_1);
  return EVar1;
}


// ---------------------------------------------------------------------
// ObjectKilled  @ 4fc42dd8  lines 334-336


EjectKillRetCodes __cdecl ObjectKilled(int param_1,int param_2)

{
  EjectKillRetCodes EVar1;
  
  EVar1 = (**(code **)((int)*Mission + 0x30))(param_1,param_2);
  return EVar1;
}


// ---------------------------------------------------------------------
// ObjectSniped  @ 4fc42dc2  lines 339-341


EjectKillRetCodes __cdecl ObjectSniped(int param_1,int param_2)

{
  EjectKillRetCodes EVar1;
  
  EVar1 = (**(code **)((int)*Mission + 0x34))(param_1,param_2);
  return EVar1;
}


// ---------------------------------------------------------------------
// GetNextRandomVehicleODF  @ 4fc42daf  lines 344-346


char * __cdecl GetNextRandomVehicleODF(int param_1)

{
  char *pcVar1;
  
  pcVar1 = (char *)(**(code **)((int)*Mission + 0x38))(param_1);
  return pcVar1;
}


// ---------------------------------------------------------------------
// SetWorld  @ 4fc42d67  lines 349-361


void __cdecl SetWorld(int param_1)

{
  if (-1 < CurrentWorld) {
    Missions[CurrentWorld] = Mission;
  }
  CurrentWorld = param_1;
  Mission = Missions[param_1];
  if (Mission == (DLLBase *)0x0) {
    Mission = BuildMission();
  }
  (**(code **)((int)*Mission + 0x3c))(param_1);
  return;
}


// ---------------------------------------------------------------------
// ProcessCommand  @ 4fc42d54  lines 364-366


void __cdecl ProcessCommand(ulong param_1)

{
  (**(code **)((int)*Mission + 0x40))(param_1);
  return;
}


// ---------------------------------------------------------------------
// SetRandomSeed  @ 4fc42d41  lines 369-371


void __cdecl SetRandomSeed(ulong param_1)

{
  (**(code **)((int)*Mission + 0x44))(param_1);
  return;
}


// ---------------------------------------------------------------------
// GetMisnAPI  @ 4fc42c5a  lines 377-402


MisnExport * __cdecl GetMisnAPI(MisnImport *param_1)

{
  int iVar1;
  MisnImport *pMVar2;
  
                    /* 0x42c5a  1  GetMisnAPI */
  CurrentWorld = 0;
  pMVar2 = &misnImport;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    pMVar2->time = param_1->time;
    param_1 = (MisnImport *)&param_1->FailMission;
    pMVar2 = (MisnImport *)&pMVar2->FailMission;
  }
  misnExport.misnImport = &misnImport;
  misnExport.version = 0x4c89322e;
  misnExport.VersionModifier = 0x42414c31;
  misnExport.InitialSetup = InitialSetup;
  misnExport.Save = Save;
  misnExport.Load = Load;
  misnExport.PostLoad = PostLoad;
  misnExport.AddObject = AddObject;
  misnExport.DeleteObject = DeleteObject;
  misnExport.Update = Update;
  misnExport.PostRun = PostRun;
  misnExport.AddPlayer = AddPlayer;
  misnExport.DeletePlayer = DeletePlayer;
  misnExport.PlayerEjected = PlayerEjected;
  misnExport.ObjectKilled = ObjectKilled;
  misnExport.ObjectSniped = ObjectSniped;
  misnExport.GetNextRandomVehicleODF = GetNextRandomVehicleODF;
  misnExport.SetWorld = SetWorld;
  misnExport.ProcessCommand = ProcessCommand;
  misnExport.SetRandomSeed = SetRandomSeed;
  return &misnExport;
}

