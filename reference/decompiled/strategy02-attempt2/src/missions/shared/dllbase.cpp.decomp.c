// Reconstructed by Ghidra from Strategy02.dll + Strategy02.pdb
// Original source file: /e:/github/vsr_dll_source/missions/shared/dllbase.cpp
// Functions are ordered by original source line. This is decompiler
// output, not the author's source: names/types come from the PDB,
// local variable names and control flow are reconstructed.

// ---------------------------------------------------------------------
// DLLBase::InitialSetup  @ 4fc407f8  lines 12-13

void __thiscall DLLBase::InitialSetup(DLLBase *this)

{
  return;
}


// ---------------------------------------------------------------------
// DLLBase::Save  @ 4fc407f3  lines 16-18

bool __thiscall DLLBase::Save(DLLBase *this,bool missionSave)

{
  return true;
}


// ---------------------------------------------------------------------
// DLLBase::Load  @ 4fc407ee  lines 21-23

bool __thiscall DLLBase::Load(DLLBase *this,bool missionSave)

{
  return true;
}


// ---------------------------------------------------------------------
// DLLBase::PostLoad  @ 4fc407e9  lines 26-28

bool __thiscall DLLBase::PostLoad(DLLBase *this,bool missionSave)

{
  return true;
}


// ---------------------------------------------------------------------
// DLLBase::AddObject  @ 4fc407e6  lines 31-32

void __thiscall DLLBase::AddObject(DLLBase *this,int h)

{
  return;
}


// ---------------------------------------------------------------------
// DLLBase::DeleteObject  @ 4fc407e3  lines 35-36

void __thiscall DLLBase::DeleteObject(DLLBase *this,int h)

{
  return;
}


// ---------------------------------------------------------------------
// DLLBase::Execute  @ 4fc407e2  lines 39-40

void __thiscall DLLBase::Execute(DLLBase *this)

{
  return;
}


// ---------------------------------------------------------------------
// DLLBase::PostRun  @ 4fc407e1  lines 43-44

void __thiscall DLLBase::PostRun(DLLBase *this)

{
  return;
}


// ---------------------------------------------------------------------
// DLLBase::DeletePlayer  @ 4fc407de  lines 47-48

void __thiscall DLLBase::DeletePlayer(DLLBase *this,ulong id)

{
  return;
}


// ---------------------------------------------------------------------
// DLLBase::SetWorld  @ 4fc407db  lines 51-52

void __thiscall DLLBase::SetWorld(DLLBase *this,int nextWorld)

{
  return;
}


// ---------------------------------------------------------------------
// DLLBase::ProcessCommand  @ 4fc407d8  lines 55-56

void __thiscall DLLBase::ProcessCommand(DLLBase *this,ulong crc)

{
  return;
}


// ---------------------------------------------------------------------
// DLLBase::SetRandomSeed  @ 4fc407d5  lines 59-60

void __thiscall DLLBase::SetRandomSeed(DLLBase *this,ulong seed)

{
  return;
}


// ---------------------------------------------------------------------
// DLLBase::AddPlayer  @ 4fc407d0  lines 63-66

bool __thiscall DLLBase::AddPlayer(DLLBase *this,ulong id,int Team,bool ShouldCreateThem)

{
  return false;
}


// ---------------------------------------------------------------------
// DLLBase::PlayerEjected  @ 4fc407cb  lines 69-71

EjectKillRetCodes __thiscall DLLBase::PlayerEjected(DLLBase *this,int DeadObjectHandle)

{
  return DoEjectPilot;
}


// ---------------------------------------------------------------------
// DLLBase::ObjectKilled  @ 4fc407ae  lines 74-79

EjectKillRetCodes __thiscall
DLLBase::ObjectKilled(DLLBase *this,int DeadObjectHandle,int KillersHandle)

{
  bool bVar1;
  EjectKillRetCodes EVar2;
  
  bVar1 = IsPlayer(DeadObjectHandle);
  EVar2 = DoEjectPilot;
  if (!bVar1) {
    EVar2 = DLLHandled;
  }
  return EVar2;
}


// ---------------------------------------------------------------------
// DLLBase::ObjectSniped  @ 4fc40793  lines 82-87

EjectKillRetCodes __thiscall
DLLBase::ObjectSniped(DLLBase *this,int DeadObjectHandle,int KillersHandle)

{
  bool bVar1;
  
  bVar1 = IsPlayer(DeadObjectHandle);
  return !bVar1 + DoRespawnSafest;
}


// ---------------------------------------------------------------------
// DLLBase::GetNextRandomVehicleODF  @ 4fc4078b  lines 90-93

char * __thiscall DLLBase::GetNextRandomVehicleODF(DLLBase *this,int Team)

{
  return "player";
}


// ---------------------------------------------------------------------
// DLLBase::PreSnipe  @ 4fc40786  lines 106-111

PreSnipeReturnCodes __thiscall
DLLBase::PreSnipe(DLLBase *this,int curWorld,int shooterHandle,int victimHandle,int ordnanceTeam,
                 char *pOrdnanceODF)

{
  return PRESNIPE_KILLPILOT;
}


// ---------------------------------------------------------------------
// DLLBase::PreOrdnanceHit  @ 4fc40783  lines 130-133

void __thiscall
DLLBase::PreOrdnanceHit
          (DLLBase *this,int shooterHandle,int victimHandle,int ordnanceTeam,char *pOrdnanceODF)

{
  return;
}


// ---------------------------------------------------------------------
// DLLBase::PreGetIn  @ 4fc4077d  lines 146-151

PreGetInReturnCodes __thiscall
DLLBase::PreGetIn(DLLBase *this,int curWorld,int pilotHandle,int emptyCraftHandle)

{
  return PREGETIN_ALLOW;
}


// ---------------------------------------------------------------------
// DLLBase::PrePickupPowerup  @ 4fc40777  lines 163-168

PrePickupPowerupReturnCodes __thiscall
DLLBase::PrePickupPowerup(DLLBase *this,int curWorld,int me,int powerupHandle)

{
  return PREPICKUPPOWERUP_ALLOW;
}


// ---------------------------------------------------------------------
// DLLBase::PostTargetChangedCallback  @ 4fc40774  lines 172-175

void __thiscall
DLLBase::PostTargetChangedCallback(DLLBase *this,int craft,int previousTarget,int currentTarget)

{
  return;
}


// ---------------------------------------------------------------------
// DLLBasePreSnipeCallback  @ 4fc4074d  lines 181-193

PreSnipeReturnCodes __cdecl
DLLBasePreSnipeCallback
          (int curWorld,int shooterHandle,int victimHandle,int ordnanceTeam,char *pOrdnanceODF)

{
  PreSnipeReturnCodes PVar1;
  
  if (Mission != (DLLBase *)0x0) {
    PVar1 = (**(code **)((int)*Mission + 0x48))
                      (curWorld,shooterHandle,victimHandle,ordnanceTeam,pOrdnanceODF);
    return PVar1;
  }
  return PRESNIPE_KILLPILOT;
}


// ---------------------------------------------------------------------
// DLLBasePreOrdnanceHitCallback  @ 4fc4072d  lines 199-210

void __cdecl
DLLBasePreOrdnanceHitCallback
          (int shooterHandle,int victimHandle,int ordnanceTeam,char *pOrdnanceODF)

{
  if (Mission != (DLLBase *)0x0) {
    (**(code **)((int)*Mission + 0x4c))(shooterHandle,victimHandle,ordnanceTeam,pOrdnanceODF);
  }
  return;
}


// ---------------------------------------------------------------------
// DLLBasePreGetInCallback  @ 4fc4070b  lines 215-227

PreGetInReturnCodes __cdecl
DLLBasePreGetInCallback(int curWorld,int pilotHandle,int emptyCraftHandle)

{
  PreGetInReturnCodes PVar1;
  
  if (Mission != (DLLBase *)0x0) {
    PVar1 = (**(code **)((int)*Mission + 0x50))(curWorld,pilotHandle,emptyCraftHandle);
    return PVar1;
  }
  return PREGETIN_ALLOW;
}


// ---------------------------------------------------------------------
// DLLBasePrePickupPowerupCallback  @ 4fc406e9  lines 232-244

PrePickupPowerupReturnCodes __cdecl
DLLBasePrePickupPowerupCallback(int curWorld,int me,int powerupHandle)

{
  PrePickupPowerupReturnCodes PVar1;
  
  if (Mission != (DLLBase *)0x0) {
    PVar1 = (**(code **)((int)*Mission + 0x54))(curWorld,me,powerupHandle);
    return PVar1;
  }
  return PREPICKUPPOWERUP_ALLOW;
}


// ---------------------------------------------------------------------
// DLLBasePostTargetChangedCallback  @ 4fc406cc  lines 249-260

void __cdecl DLLBasePostTargetChangedCallback(int craft,int previousTarget,int currentTarget)

{
  if (Mission != (DLLBase *)0x0) {
    (**(code **)((int)*Mission + 0x58))(craft,previousTarget,currentTarget);
  }
  return;
}


// ---------------------------------------------------------------------
// InitialSetup  @ 4fc40671  lines 266-278

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
// Save  @ 4fc4065e  lines 281-283

bool __cdecl Save(bool misnSave)

{
  undefined1 uVar1;
  undefined3 in_stack_00000005;
  
  uVar1 = (**(code **)((int)*Mission + 8))(_misnSave);
  return (bool)uVar1;
}


// ---------------------------------------------------------------------
// Load  @ 4fc4063c  lines 286-290

bool __cdecl Load(bool misnSave)

{
  undefined1 uVar1;
  undefined3 in_stack_00000005;
  
  if (Mission == (DLLBase *)0x0) {
    Mission = BuildMission();
  }
  uVar1 = (**(code **)((int)*Mission + 0xc))(_misnSave);
  return (bool)uVar1;
}


// ---------------------------------------------------------------------
// PostLoad  @ 4fc40629  lines 293-295

bool __cdecl PostLoad(bool misnSave)

{
  undefined1 uVar1;
  undefined3 in_stack_00000005;
  
  uVar1 = (**(code **)((int)*Mission + 0x10))(_misnSave);
  return (bool)uVar1;
}


// ---------------------------------------------------------------------
// AddObject  @ 4fc40616  lines 298-300

void __cdecl AddObject(int h)

{
  (**(code **)((int)*Mission + 0x14))(h);
  return;
}


// ---------------------------------------------------------------------
// DeleteObject  @ 4fc40603  lines 303-305

void __cdecl DeleteObject(int h)

{
  (**(code **)((int)*Mission + 0x18))(h);
  return;
}


// ---------------------------------------------------------------------
// Update  @ 4fc405f8  lines 308-309

void __cdecl Update(void)

{
                    /* WARNING: Could not recover jumptable at 0x4fc40600. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)((int)*Mission + 0x1c))();
  return;
}


// ---------------------------------------------------------------------
// PostRun  @ 4fc405dc  lines 313-316

void __cdecl PostRun(void)

{
  (**(code **)((int)*Mission + 0x20))();
  if (Mission != (DLLBase *)0x0) {
    (**(code **)*Mission)(1);
  }
  return;
}


// ---------------------------------------------------------------------
// AddPlayer  @ 4fc405c3  lines 319-321

bool __cdecl AddPlayer(ulong id,int Team,bool ShouldCreateThem)

{
  undefined1 uVar1;
  undefined3 in_stack_0000000d;
  
  uVar1 = (**(code **)((int)*Mission + 0x24))(id,Team,_ShouldCreateThem);
  return (bool)uVar1;
}


// ---------------------------------------------------------------------
// DeletePlayer  @ 4fc405b0  lines 324-326

void __cdecl DeletePlayer(ulong id)

{
  (**(code **)((int)*Mission + 0x28))(id);
  return;
}


// ---------------------------------------------------------------------
// PlayerEjected  @ 4fc4059d  lines 329-331

EjectKillRetCodes __cdecl PlayerEjected(int DeadObjectHandle)

{
  EjectKillRetCodes EVar1;
  
  EVar1 = (**(code **)((int)*Mission + 0x2c))(DeadObjectHandle);
  return EVar1;
}


// ---------------------------------------------------------------------
// ObjectKilled  @ 4fc40587  lines 334-336

EjectKillRetCodes __cdecl ObjectKilled(int DeadObjectHandle,int KillersHandle)

{
  EjectKillRetCodes EVar1;
  
  EVar1 = (**(code **)((int)*Mission + 0x30))(DeadObjectHandle,KillersHandle);
  return EVar1;
}


// ---------------------------------------------------------------------
// ObjectSniped  @ 4fc40571  lines 339-341

EjectKillRetCodes __cdecl ObjectSniped(int DeadObjectHandle,int KillersHandle)

{
  EjectKillRetCodes EVar1;
  
  EVar1 = (**(code **)((int)*Mission + 0x34))(DeadObjectHandle,KillersHandle);
  return EVar1;
}


// ---------------------------------------------------------------------
// GetNextRandomVehicleODF  @ 4fc4055e  lines 344-346

char * __cdecl GetNextRandomVehicleODF(int Team)

{
  char *pcVar1;
  
  pcVar1 = (char *)(**(code **)((int)*Mission + 0x38))(Team);
  return pcVar1;
}


// ---------------------------------------------------------------------
// SetWorld  @ 4fc40516  lines 349-361

void __cdecl SetWorld(int nextWorld)

{
  if (-1 < CurrentWorld) {
    Missions[CurrentWorld] = Mission;
  }
  CurrentWorld = nextWorld;
  Mission = Missions[nextWorld];
  if (Mission == (DLLBase *)0x0) {
    Mission = BuildMission();
  }
  (**(code **)((int)*Mission + 0x3c))(nextWorld);
  return;
}


// ---------------------------------------------------------------------
// ProcessCommand  @ 4fc40503  lines 364-366

void __cdecl ProcessCommand(ulong crc)

{
  (**(code **)((int)*Mission + 0x40))(crc);
  return;
}


// ---------------------------------------------------------------------
// SetRandomSeed  @ 4fc404f0  lines 369-371

void __cdecl SetRandomSeed(ulong seed)

{
  (**(code **)((int)*Mission + 0x44))(seed);
  return;
}


// ---------------------------------------------------------------------
// GetMisnAPI  @ 4fc40409  lines 377-402

MisnExport * __cdecl GetMisnAPI(MisnImport *import)

{
  int iVar1;
  MisnImport *pMVar2;
  
                    /* 0x40409  1  GetMisnAPI */
  CurrentWorld = 0;
  pMVar2 = &misnImport;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    pMVar2->time = import->time;
    import = (MisnImport *)&import->FailMission;
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


