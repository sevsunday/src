// Reconstructed by Ghidra from Strategy02.dll + Strategy02.pdb
// Original source file: /e:/github/vsr_dll_source/missions/shared/startingvehicles.cpp
// Functions are ordered by original source line. This is decompiler
// output, not the author's source: names/types come from the PDB,
// local variable names and control flow are reconstructed.


// ---------------------------------------------------------------------
// StartingVehicleManager::Init  @ 4fc40a79  lines 42-77


void __cdecl StartingVehicleManager::Init(void)

{
  char *_Src;
  uint uVar1;
  char (*_Dst) [64];
  char (*local_c) [64];
  
  if (!s_bInitialized) {
    _Dst = s_StartingVehicleList;
    local_c = s_StartingVehicleList;
    memset(s_StartingVehicleList,0,0x800);
    uVar1 = 0;
    do {
      _Src = GetNetworkListItem(NETLIST_StratStarting,uVar1);
      if (_Src != (char *)0x0) {
        strcpy_s(*_Dst,0x40,_Src);
      }
      uVar1 = uVar1 + 1;
      _Dst = _Dst + 1;
    } while (uVar1 < 0x20);
    s_NumStartingVehicleEntries = 0;
    do {
      if ((*local_c)[0] == '\0') break;
      s_NumStartingVehicleEntries = s_NumStartingVehicleEntries + 1;
      local_c = local_c + 1;
    } while ((uint)s_NumStartingVehicleEntries < 0x20);
    s_bInitialized = true;
  }
  return;
}


// ---------------------------------------------------------------------
// StartingVehicleManager::CreateVehicles  @ 4fc4095b  lines 87-124


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __cdecl
StartingVehicleManager::CreateVehicles
          (int param_1,char param_2,char *param_3,int param_4,Vector param_5)

{
  Vector VVar1;
  bool bVar2;
  Vector *pVVar3;
  int iVar4;
  int in_ECX;
  char in_DL;
  int iVar5;
  char (*pacVar6) [64];
  undefined3 in_stack_00000009;
  Vector local_74;
  Vector local_68;
  int local_5c;
  int local_58;
  char (*local_54) [64];
  char local_4d;
  char local_4c [67];
  char local_9;
  uint local_8;
  
  local_8 = __security_cookie ^ (uint)&stack0xfffffffc;
  local_58 = param_1;
  if (s_bInitialized) {
    iVar5 = 0;
    if (0 < s_NumStartingVehicleEntries) {
      local_54 = s_StartingVehicleList;
      iVar4 = s_NumStartingVehicleEntries;
      local_5c = in_ECX;
      local_4d = in_DL;
      do {
        pacVar6 = local_54;
        if ((_param_2 & 1 << ((byte)iVar5 & 0x1f)) != 0) {
          VVar1.y = (float)param_4;
          VVar1.x = (float)param_3;
          VVar1.z = param_5.x;
          pVVar3 = GetPositionNear(&local_74,VVar1,30.0,60.0);
          pacVar6 = local_54;
          local_68.x = pVVar3->x;
          local_68.y = pVVar3->y;
          local_68.z = pVVar3->z;
          strcpy_s(local_4c,0x44,*local_54);
          local_4c[0] = local_4d;
          local_9 = '\0';
          sprintf_s<68>((char (*) [68])local_4c,"%s%s");
          bVar2 = DoesODFExist(local_4c);
          if (!bVar2) {
            sprintf_s<68>((char (*) [68])local_4c,"%s");
            local_4c[0] = local_4d;
          }
          iVar4 = BuildObject(local_4c,local_5c,&local_68);
          SetRandomHeadingAngle(iVar4);
          SetBestGroup(iVar4);
          iVar4 = s_NumStartingVehicleEntries;
        }
        iVar5 = iVar5 + 1;
        local_54 = pacVar6 + 1;
      } while (iVar5 < iVar4);
    }
  }
  return;
}


// ---------------------------------------------------------------------
// StartingVehicleManager::Save  @ 4fc40921  lines 128-142


void __cdecl StartingVehicleManager::Save(bool param_1)

{
  int iVar1;
  char (*pacVar2) [64];
  
  Write(&s_NumStartingVehicleEntries,1);
  iVar1 = 0;
  if (0 < s_NumStartingVehicleEntries) {
    pacVar2 = s_StartingVehicleList;
    do {
      Write(pacVar2,0x40);
      iVar1 = iVar1 + 1;
      pacVar2 = pacVar2 + 1;
    } while (iVar1 < s_NumStartingVehicleEntries);
  }
  return;
}


// ---------------------------------------------------------------------
// StartingVehicleManager::Load  @ 4fc408e7  lines 145-154


void __cdecl StartingVehicleManager::Load(bool param_1)

{
  int iVar1;
  char (*pacVar2) [64];
  
  Read(&s_NumStartingVehicleEntries,1);
  iVar1 = 0;
  if (0 < s_NumStartingVehicleEntries) {
    pacVar2 = s_StartingVehicleList;
    do {
      Read(pacVar2,0x40);
      iVar1 = iVar1 + 1;
      pacVar2 = pacVar2 + 1;
    } while (iVar1 < s_NumStartingVehicleEntries);
  }
  return;
}

