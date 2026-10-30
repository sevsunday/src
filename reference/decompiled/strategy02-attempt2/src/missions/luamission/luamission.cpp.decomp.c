// Reconstructed by Ghidra from Strategy02.dll + Strategy02.pdb
// Original source file: /e:/github/vsr_dll_source/missions/luamission/luamission.cpp
// Functions are ordered by original source line. This is decompiler
// output, not the author's source: names/types come from the PDB,
// local variable names and control flow are reconstructed.

// ---------------------------------------------------------------------
// LuaMission::LuaMission  @ 4fc48bbe  lines 13-32

/* WARNING: Function: _EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: _EH_epilog3 replaced with injection: EH_epilog3 */

LuaMission * __thiscall LuaMission::LuaMission(LuaMission *this)

{
  char *pTRNName;
  
  BZ1Helper::BZ1Helper(&this->super_BZ1Helper);
  (this->super_BZ1Helper).super_DLLBase = (DLLBase)vftable;
  this->m_GameTPS = 0x14;
  EnableHighTPS(&this->m_GameTPS);
  AllowRandomTracks(true);
  this->b_count = 2;
  this->b_array = &this->DidSetup;
  this->i_count = 3;
  this->i_array = &this->m_ElapsedGameTime;
  pTRNName = GetMapTRNFilename();
  TRNAllies::SetupTRNAllies(pTRNName);
  if (this->i_array != (int *)0x0) {
    memset(this->i_array,0,this->i_count << 2);
  }
  if (this->b_array != (bool *)0x0) {
    memset(this->b_array,0,this->b_count);
  }
  this->L = (lua_State *)0x0;
  return this;
}


// ---------------------------------------------------------------------
// LuaMission::~LuaMission  @ 4fc48b57  lines 35-42

void __thiscall LuaMission::~LuaMission(LuaMission *this)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 uStack_8;
  
  uStack_8 = 0xffffffff;
  puStack_c = &__ehhandler___1LuaMission__UAE_XZ;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  (this->super_BZ1Helper).super_DLLBase = (DLLBase)vftable;
  CloseOpenODFs();
  CloseOpenFiles();
  CleanupTaunts();
  if (this->L != (lua_State *)0x0) {
    FUN_4fc2d3b2(*(int *)(*(int *)(this->L + 0xc) + 0x9c));
  }
  BZ1Helper::~BZ1Helper(&this->super_BZ1Helper);
  ExceptionList = local_10;
  return;
}


// ---------------------------------------------------------------------
// LuaMission::Setup  @ 4fc47280  lines 53-73

void __thiscall LuaMission::Setup(LuaMission *this)

{
  uint uVar1;
  int iVar2;
  undefined4 extraout_ECX;
  int *unaff_ESI;
  char *unaff_retaddr;
  int in_stack_00000004;
  lua_State *in_stack_00000008;
  char *in_stack_0000000c;
  
  this->DidSetup = true;
  InitTaunts(&this->m_GameTPS,(int *)this,unaff_ESI,unaff_retaddr);
  if (this->L != (lua_State *)0x0) {
    lua_getglobal();
    uVar1 = lua_type();
    if (uVar1 != 6) {
      lua_settop();
      return;
    }
    iVar2 = lua_pcallk(0,0,extraout_ECX,0);
    if (iVar2 != 0) {
      LuaBindings::LuaCheckStatus(in_stack_00000004,in_stack_00000008,in_stack_0000000c);
      return;
    }
  }
  return;
}


// ---------------------------------------------------------------------
// LuaMission::InitialSetup  @ 4fc4832f  lines 76-285

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall LuaMission::InitialSetup(LuaMission *this)

{
  undefined4 *puVar1;
  undefined8 *puVar2;
  bool bVar3;
  char *pcVar4;
  lua_State *plVar5;
  Matrix *pMVar6;
  void *_Memory;
  uint uVar7;
  int iVar8;
  LuaMission *this_00;
  LuaMission *this_01;
  LuaMission *this_02;
  LuaMission *this_03;
  LuaMission *this_04;
  LuaMission *this_05;
  LuaMission *this_06;
  LuaMission *this_07;
  LuaMission *this_08;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 uVar9;
  undefined4 extraout_ECX_01;
  char *unaff_EBX;
  lua_State *unaff_ESI;
  Matrix *pMVar10;
  int unaff_EDI;
  uint local_94;
  char bufSize [132];
  uint local_c;
  
  local_c = __security_cookie ^ (uint)&local_94;
  EnableHighTPS(&this->m_GameTPS);
  SetAutoGroupUnits(false);
  memset(bufSize,0,0x80);
  pcVar4 = GetMissionFilename();
  strcpy_s(bufSize,0x80,pcVar4);
  pcVar4 = strchr(bufSize,0x2e);
  if (pcVar4 != (char *)0x0) {
    *pcVar4 = '\0';
  }
  strcat_s(bufSize,0x80,".lua");
  bVar3 = DoesFileExist(bufSize);
  if (bVar3) {
    plVar5 = (lua_State *)lua_newstate(&LAB_4fc2d0b6,0);
    if (plVar5 != (lua_State *)0x0) {
      *(undefined1 **)(*(int *)(plVar5 + 0xc) + 0x98) = &LAB_4fc2d0dc;
    }
    this->L = plVar5;
    if (plVar5 != (lua_State *)0x0) {
      luaL_openlibs();
      plVar5 = this->L;
      *(undefined4 *)(*(int *)(plVar5 + 8) + 4) = 0x7ff7a500;
      plVar5 = plVar5 + 8;
      *(int *)plVar5 = *(int *)plVar5 + 8;
      lua_setglobal();
      plVar5 = this->L;
      *(undefined4 *)(*(int *)(plVar5 + 8) + 4) = 0x7ff7a500;
      plVar5 = plVar5 + 8;
      *(int *)plVar5 = *(int *)plVar5 + 8;
      lua_setglobal();
      *(code **)(*(int *)(this->L + 0xc) + 0x98) = LuaPanic;
      plVar5 = this->L;
      puVar1 = *(undefined4 **)(plVar5 + 8);
      *puVar1 = LuaPrint;
      puVar1[1] = 0x7ff7a516;
      plVar5 = plVar5 + 8;
      *(int *)plVar5 = *(int *)plVar5 + 8;
      lua_setglobal();
      lua_rawgeti();
      luaL_setfuncs(0);
      plVar5 = this->L;
      puVar1 = *(undefined4 **)(plVar5 + 8);
      *puVar1 = 0;
      puVar1[1] = 0x7ff7a502;
      plVar5 = plVar5 + 8;
      *(int *)plVar5 = *(int *)plVar5 + 8;
      luaL_newmetatable();
      lua_pushstring();
      lua_setfield();
      plVar5 = this->L;
      puVar1 = *(undefined4 **)(plVar5 + 8);
      *puVar1 = LuaBindings::Handle_ToString;
      puVar1[1] = 0x7ff7a516;
      plVar5 = plVar5 + 8;
      *(int *)plVar5 = *(int *)plVar5 + 8;
      lua_setfield();
      plVar5 = this->L;
      puVar1 = *(undefined4 **)(plVar5 + 8);
      *puVar1 = LuaBindings::Handle_ToInteger;
      puVar1[1] = 0x7ff7a516;
      plVar5 = plVar5 + 8;
      *(int *)plVar5 = *(int *)plVar5 + 8;
      lua_setfield();
      lua_setmetatable();
      luaL_newmetatable();
      lua_pushstring();
      lua_setfield();
      plVar5 = this->L;
      puVar1 = *(undefined4 **)(plVar5 + 8);
      *puVar1 = LuaBindings::Vector_Index;
      puVar1[1] = 0x7ff7a516;
      plVar5 = plVar5 + 8;
      *(int *)plVar5 = *(int *)plVar5 + 8;
      lua_setfield();
      plVar5 = this->L;
      puVar1 = *(undefined4 **)(plVar5 + 8);
      *puVar1 = LuaBindings::Vector_NewIndex;
      puVar1[1] = 0x7ff7a516;
      plVar5 = plVar5 + 8;
      *(int *)plVar5 = *(int *)plVar5 + 8;
      lua_setfield();
      plVar5 = this->L;
      puVar1 = *(undefined4 **)(plVar5 + 8);
      *puVar1 = LuaBindings::Vector_Neg;
      puVar1[1] = 0x7ff7a516;
      plVar5 = plVar5 + 8;
      *(int *)plVar5 = *(int *)plVar5 + 8;
      lua_setfield();
      plVar5 = this->L;
      puVar1 = *(undefined4 **)(plVar5 + 8);
      *puVar1 = LuaBindings::Vector_Add;
      puVar1[1] = 0x7ff7a516;
      plVar5 = plVar5 + 8;
      *(int *)plVar5 = *(int *)plVar5 + 8;
      lua_setfield();
      plVar5 = this->L;
      puVar1 = *(undefined4 **)(plVar5 + 8);
      *puVar1 = LuaBindings::Vector_Sub;
      puVar1[1] = 0x7ff7a516;
      plVar5 = plVar5 + 8;
      *(int *)plVar5 = *(int *)plVar5 + 8;
      lua_setfield();
      plVar5 = this->L;
      puVar1 = *(undefined4 **)(plVar5 + 8);
      *puVar1 = LuaBindings::Vector_Mul;
      puVar1[1] = 0x7ff7a516;
      plVar5 = plVar5 + 8;
      *(int *)plVar5 = *(int *)plVar5 + 8;
      lua_setfield();
      plVar5 = this->L;
      puVar1 = *(undefined4 **)(plVar5 + 8);
      *puVar1 = LuaBindings::Vector_Div;
      puVar1[1] = 0x7ff7a516;
      plVar5 = plVar5 + 8;
      *(int *)plVar5 = *(int *)plVar5 + 8;
      lua_setfield();
      plVar5 = this->L;
      puVar1 = *(undefined4 **)(plVar5 + 8);
      *puVar1 = LuaBindings::Vector_Eq;
      puVar1[1] = 0x7ff7a516;
      plVar5 = plVar5 + 8;
      *(int *)plVar5 = *(int *)plVar5 + 8;
      lua_setfield();
      plVar5 = this->L;
      puVar1 = *(undefined4 **)(plVar5 + 8);
      *puVar1 = LuaBindings::Vector_ToString;
      puVar1[1] = 0x7ff7a516;
      plVar5 = plVar5 + 8;
      *(int *)plVar5 = *(int *)plVar5 + 8;
      lua_setfield();
      lua_settop();
      luaL_newmetatable();
      lua_pushstring();
      lua_setfield();
      plVar5 = this->L;
      puVar1 = *(undefined4 **)(plVar5 + 8);
      *puVar1 = LuaBindings::Matrix_Index;
      puVar1[1] = 0x7ff7a516;
      plVar5 = plVar5 + 8;
      *(int *)plVar5 = *(int *)plVar5 + 8;
      lua_setfield();
      plVar5 = this->L;
      puVar1 = *(undefined4 **)(plVar5 + 8);
      *puVar1 = LuaBindings::Matrix_NewIndex;
      puVar1[1] = 0x7ff7a516;
      plVar5 = plVar5 + 8;
      *(int *)plVar5 = *(int *)plVar5 + 8;
      lua_setfield();
      plVar5 = this->L;
      puVar1 = *(undefined4 **)(plVar5 + 8);
      *puVar1 = LuaBindings::Matrix_Mul;
      puVar1[1] = 0x7ff7a516;
      plVar5 = plVar5 + 8;
      *(int *)plVar5 = *(int *)plVar5 + 8;
      lua_setfield();
      plVar5 = this->L;
      puVar1 = *(undefined4 **)(plVar5 + 8);
      *puVar1 = LuaBindings::Matrix_ToString;
      puVar1[1] = 0x7ff7a516;
      plVar5 = plVar5 + 8;
      *(int *)plVar5 = *(int *)plVar5 + 8;
      lua_setfield();
      lua_settop();
      luaL_newmetatable();
      lua_pushstring();
      lua_setfield();
      plVar5 = this->L;
      puVar1 = *(undefined4 **)(plVar5 + 8);
      *puVar1 = LuaBindings::Quaternion_Index;
      puVar1[1] = 0x7ff7a516;
      plVar5 = plVar5 + 8;
      *(int *)plVar5 = *(int *)plVar5 + 8;
      lua_setfield();
      plVar5 = this->L;
      puVar1 = *(undefined4 **)(plVar5 + 8);
      *puVar1 = LuaBindings::Quaternion_NewIndex;
      puVar1[1] = 0x7ff7a516;
      plVar5 = plVar5 + 8;
      *(int *)plVar5 = *(int *)plVar5 + 8;
      lua_setfield();
      plVar5 = this->L;
      puVar1 = *(undefined4 **)(plVar5 + 8);
      *puVar1 = LuaBindings::Quaternion_Mul;
      puVar1[1] = 0x7ff7a516;
      plVar5 = plVar5 + 8;
      *(int *)plVar5 = *(int *)plVar5 + 8;
      lua_setfield();
      plVar5 = this->L;
      puVar1 = *(undefined4 **)(plVar5 + 8);
      *puVar1 = LuaBindings::Quaternion_ToString;
      puVar1[1] = 0x7ff7a516;
      plVar5 = plVar5 + 8;
      *(int *)plVar5 = *(int *)plVar5 + 8;
      lua_setfield();
      lua_settop();
      pMVar6 = LuaBindings::NewMatrix(this->L);
      pMVar10 = &::Identity_Matrix;
      for (iVar8 = 0x10; iVar8 != 0; iVar8 = iVar8 + -1) {
        (pMVar6->right).x = (pMVar10->right).x;
        pMVar10 = (Matrix *)&(pMVar10->right).y;
        pMVar6 = (Matrix *)&(pMVar6->right).y;
      }
      lua_setglobal();
      CreateLuaStringTable(this_00,this->L,CommandList,0x36,"AiCommand");
      CreateLuaStringTable(this_01,this->L,TauntTypesList,0x10,"TauntTypes");
      CreateLuaStringTable(this_02,this->L,DeathmatchGameSubtypesList,8,"DMSubGameTypes");
      CreateLuaStringTable(this_03,this->L,PreSnipeReturnCodesList,2,"PreSnipeReturnValues");
      CreateLuaStringTable(this_04,this->L,PreGetInReturnCodesList,2,"PreGetInReturnValues");
      CreateLuaStringTable
                (this_05,this->L,PrePickupPowerupReturnCodesList,2,"PrePickupPowerupReturnValues");
      CreateLuaStringTable(this_06,this->L,RandomizeTypeList,3,"RandomizeTypes");
      CreateLuaStringTable(this_07,this->L,TeamRelationshipList,4,"TeamRelationshipTypes");
      CreateLuaStringTable(this_08,this->L,EjectKillRetCodeList,4,"EjectKillRetCodes");
      plVar5 = this->L;
      puVar2 = *(undefined8 **)(plVar5 + 8);
      *puVar2 = 0x4067400000000000;
      *(undefined8 **)(plVar5 + 8) = puVar2 + 1;
      lua_setglobal();
      local_94 = 0;
      LoadFile(bufSize,(void *)0x0,&local_94);
      _Memory = malloc(local_94 + 1);
      LoadFile(bufSize,_Memory,&local_94);
      *(undefined1 *)((int)_Memory + local_94) = 0;
      iVar8 = luaL_loadbufferx(local_94,bufSize,0);
      if (iVar8 == 0) {
        bVar3 = true;
        uVar9 = extraout_ECX;
      }
      else {
        bVar3 = LuaBindings::LuaCheckStatus(unaff_EDI,unaff_ESI,unaff_EBX);
        uVar9 = extraout_ECX_00;
      }
      if (bVar3 != false) {
        iVar8 = lua_pcallk(-1,0,uVar9,0);
        if (iVar8 != 0) {
          LuaBindings::LuaCheckStatus(unaff_EDI,unaff_ESI,unaff_EBX);
        }
      }
      free(_Memory);
      if (this->L != (lua_State *)0x0) {
        FormatConsoleMessage("Lua script: \'%s\' loaded",bufSize);
        lua_getglobal();
        uVar7 = lua_type();
        if (uVar7 == 6) {
          iVar8 = lua_pcallk(0,0,extraout_ECX_01,0);
          if (iVar8 != 0) {
            LuaBindings::LuaCheckStatus(unaff_EDI,unaff_ESI,unaff_EBX);
          }
        }
        else {
          lua_settop();
        }
      }
    }
  }
  else {
    FormatConsoleMessage("No Lua script: \'%s\'",bufSize);
  }
  return;
}


// ---------------------------------------------------------------------
// LuaMission::Load  @ 4fc47f3d  lines 288-350

bool __thiscall LuaMission::Load(LuaMission *this,bool missionSave)

{
  bool bVar1;
  uint uVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  int iVar3;
  int iVar4;
  char *unaff_EBX;
  lua_State *unaff_ESI;
  lua_State *unaff_EDI;
  undefined4 uVar5;
  LuaMission *local_c [2];
  
  local_c[0] = this;
  bVar1 = BZ1Helper::Load(&this->super_BZ1Helper,missionSave);
  iVar4 = this->b_count;
  if (missionSave) {
    iVar3 = 0;
    if (0 < iVar4) {
      do {
        this->b_array[iVar3] = false;
        iVar3 = iVar3 + 1;
      } while (iVar3 < this->b_count);
    }
    iVar4 = 0;
    if (0 < this->i_count) {
      do {
        this->i_array[iVar4] = 0;
        iVar4 = iVar4 + 1;
      } while (iVar4 < this->i_count);
    }
    return true;
  }
  if (iVar4 != 0) {
    if ((bVar1) && (bVar1 = Read(this->b_array,iVar4), bVar1)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
  }
  if (this->i_count != 0) {
    if ((bVar1 == false) || (bVar1 = Read(this->i_array,this->i_count), !bVar1)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
  }
  if (this->L == (lua_State *)0x0) {
    return bVar1;
  }
  lua_getglobal();
  uVar2 = lua_type();
  local_c[0] = (LuaMission *)0x0;
  if (uVar2 != 6) {
    if ((bVar1 == false) || (bVar1 = Read((int *)local_c,1), !bVar1)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    iVar4 = 0;
    if (0 < (int)local_c[0]) {
      do {
        if ((bVar1 == false) ||
           (bVar1 = LuaBindings::LoadValue(unaff_EDI,SUB41(unaff_ESI,0)), !bVar1)) {
          bVar1 = false;
        }
        else {
          bVar1 = true;
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < (int)local_c[0]);
    }
    lua_settop();
    return bVar1;
  }
  uVar5 = extraout_ECX;
  if (bVar1 != false) {
    uVar5 = 1;
    bVar1 = Read((int *)local_c,1);
    if (bVar1) {
      bVar1 = true;
      goto LAB_4fc48032;
    }
  }
  bVar1 = false;
LAB_4fc48032:
  iVar4 = 0;
  if (0 < (int)local_c[0]) {
    do {
      if ((bVar1 == false) ||
         (bVar1 = LuaBindings::LoadValue(unaff_EDI,SUB41(unaff_ESI,0)), uVar5 = extraout_ECX_00,
         !bVar1)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < (int)local_c[0]);
  }
  iVar4 = lua_pcallk(0,0,uVar5,0);
  if (iVar4 != 0) {
    LuaBindings::LuaCheckStatus((int)unaff_EDI,unaff_ESI,unaff_EBX);
  }
  return bVar1;
}


// ---------------------------------------------------------------------
// LuaMission::PostLoad  @ 4fc47f1c  lines 353-363

bool __thiscall LuaMission::PostLoad(LuaMission *this,bool missionSave)

{
  bool bVar1;
  
  bVar1 = BZ1Helper::PostLoad(&this->super_BZ1Helper,missionSave);
  if (missionSave) {
    bVar1 = true;
  }
  return bVar1;
}


// ---------------------------------------------------------------------
// LuaMission::Save  @ 4fc47d92  lines 366-413

bool __thiscall LuaMission::Save(LuaMission *this,bool missionSave)

{
  bool bVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  char *unaff_EBX;
  lua_State *unaff_ESI;
  int unaff_EDI;
  int iVar5;
  undefined3 in_stack_00000005;
  LuaMission *count;
  
  count = this;
  bVar1 = BZ1Helper::Save(&this->super_BZ1Helper,missionSave);
  if (missionSave == false) {
    if (this->b_count != 0) {
      if ((bVar1) && (bVar1 = Write(this->b_array,this->b_count), bVar1)) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
    }
    if (this->i_count != 0) {
      if ((bVar1 == false) || (bVar1 = Write(this->i_array,this->i_count), !bVar1)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
    }
    if (this->L != (lua_State *)0x0) {
      lua_getglobal();
      _missionSave = this->L;
      uVar3 = lua_type();
      if (uVar3 == 6) {
        iVar5 = (*(int *)(_missionSave + 8) - **(int **)(_missionSave + 0x10)) + -8 >> 3;
        iVar4 = lua_pcallk(-1,0,_missionSave,0);
        if (iVar4 == 0) {
          bVar2 = true;
        }
        else {
          bVar2 = LuaBindings::LuaCheckStatus(unaff_EDI,unaff_ESI,unaff_EBX);
        }
        if (bVar2 != false) {
          count = (LuaMission *)
                  ((((*(int *)(this->L + 8) - **(int **)(this->L + 0x10)) + -8 >> 3) - iVar5) + 1);
          if ((bVar1 == false) || (bVar1 = Write((int *)&count,1), !bVar1)) {
            bVar1 = false;
          }
          else {
            bVar1 = true;
          }
          _missionSave = (lua_State *)iVar5;
          if (iVar5 < (int)(&(count->super_BZ1Helper).super_DLLBase.field_0x0 + iVar5)) {
            do {
              if ((bVar1 == false) ||
                 (bVar1 = LuaBindings::SaveValue(this->L,(int)_missionSave), !bVar1)) {
                bVar1 = false;
              }
              else {
                bVar1 = true;
              }
              _missionSave = (lua_State *)((int)_missionSave + 1);
            } while ((int)_missionSave <
                     (int)(&(count->super_BZ1Helper).super_DLLBase.field_0x0 + iVar5));
          }
        }
      }
      else {
        _missionSave = (lua_State *)0x0;
        if ((bVar1 == false) || (bVar1 = Write((int *)&missionSave,1), !bVar1)) {
          bVar1 = false;
        }
        else {
          bVar1 = true;
        }
        lua_settop();
      }
    }
  }
  else {
    bVar1 = true;
  }
  return bVar1;
}


// ---------------------------------------------------------------------
// LuaMission::PreOrdnanceHit  @ 4fc477a0  lines 416-439

void __thiscall
LuaMission::PreOrdnanceHit
          (LuaMission *this,int shooterHandle,int victimHandle,int ordnanceTeam,char *pOrdnanceODF)

{
  lua_State *plVar1;
  double *pdVar2;
  uint uVar3;
  int iVar4;
  undefined4 extraout_ECX;
  char *unaff_EBP;
  lua_State *unaff_ESI;
  int unaff_EDI;
  
  if (this->StopScript == false) {
    BZ1Helper::PreOrdnanceHit
              (&this->super_BZ1Helper,shooterHandle,victimHandle,ordnanceTeam,pOrdnanceODF);
  }
  if (this->L != (lua_State *)0x0) {
    lua_getglobal();
    plVar1 = this->L;
    uVar3 = lua_type();
    if (uVar3 == 6) {
      LuaBindings::PushHandle(plVar1,shooterHandle);
      LuaBindings::PushHandle(this->L,victimHandle);
      plVar1 = this->L;
      pdVar2 = *(double **)(plVar1 + 8);
      *pdVar2 = (double)ordnanceTeam;
      *(double **)(plVar1 + 8) = pdVar2 + 1;
      lua_pushstring();
      iVar4 = lua_pcallk(0,0,extraout_ECX,0);
      if (iVar4 != 0) {
        LuaBindings::LuaCheckStatus(unaff_EDI,unaff_ESI,unaff_EBP);
      }
    }
    else {
      lua_settop();
    }
  }
  return;
}


// ---------------------------------------------------------------------
// LuaMission::PreGetIn  @ 4fc47565  lines 442-482

PreGetInReturnCodes __thiscall
LuaMission::PreGetIn(LuaMission *this,int curWorld,int pilotHandle,int emptyCraftHandle)

{
  uint uVar1;
  int iVar2;
  undefined4 extraout_ECX;
  char *unaff_EBX;
  lua_State *unaff_ESI;
  int unaff_EDI;
  PreGetInReturnCodes PVar3;
  
  PVar3 = PREGETIN_ALLOW;
  if (this->StopScript == false) {
    PVar3 = BZ1Helper::PreGetIn(&this->super_BZ1Helper,curWorld,pilotHandle,emptyCraftHandle);
  }
  if (this->L != (lua_State *)0x0) {
    lua_getglobal();
    uVar1 = lua_type();
    if (uVar1 == 6) {
      lua_pushnumber();
      LuaBindings::PushHandle(this->L,pilotHandle);
      LuaBindings::PushHandle(this->L,emptyCraftHandle);
      iVar2 = lua_pcallk(1,0,extraout_ECX,0);
      if (iVar2 != 0) {
        LuaBindings::LuaCheckStatus(unaff_EDI,unaff_ESI,unaff_EBX);
      }
      iVar2 = lua_isnumber();
      if (iVar2 == 0) {
        uVar1 = lua_type();
        if (uVar1 != 0xffffffff) {
          PrintConsoleMessage("Lua script PreGetIn error: invalid return param.");
        }
      }
      else {
        PVar3 = lua_tointegerx((undefined4 *)0x0);
      }
    }
    lua_settop();
  }
  return PVar3;
}


// ---------------------------------------------------------------------
// LuaMission::PreSnipe  @ 4fc4766b  lines 484-525

PreSnipeReturnCodes __thiscall
LuaMission::PreSnipe
          (LuaMission *this,int curWorld,int shooterHandle,int victimHandle,int ordnanceTeam,
          char *pOrdnanceODF)

{
  lua_State *plVar1;
  double *pdVar2;
  uint uVar3;
  int iVar4;
  undefined4 extraout_ECX;
  int unaff_EBX;
  char *unaff_ESI;
  lua_State *unaff_EDI;
  PreSnipeReturnCodes PVar5;
  
  PVar5 = PRESNIPE_KILLPILOT;
  if (this->StopScript == false) {
    PVar5 = BZ1Helper::PreSnipe(&this->super_BZ1Helper,curWorld,shooterHandle,victimHandle,
                                ordnanceTeam,pOrdnanceODF);
  }
  if (this->L != (lua_State *)0x0) {
    lua_getglobal();
    plVar1 = this->L;
    uVar3 = lua_type();
    if (uVar3 == 6) {
      pdVar2 = *(double **)(plVar1 + 8);
      *pdVar2 = (double)curWorld;
      *(double **)(plVar1 + 8) = pdVar2 + 1;
      LuaBindings::PushHandle(this->L,shooterHandle);
      LuaBindings::PushHandle(this->L,victimHandle);
      plVar1 = this->L;
      pdVar2 = *(double **)(plVar1 + 8);
      *pdVar2 = (double)ordnanceTeam;
      *(double **)(plVar1 + 8) = pdVar2 + 1;
      lua_pushstring();
      iVar4 = lua_pcallk(1,0,extraout_ECX,0);
      if (iVar4 != 0) {
        LuaBindings::LuaCheckStatus(unaff_EBX,unaff_EDI,unaff_ESI);
      }
      iVar4 = lua_isnumber();
      if (iVar4 == 0) {
        uVar3 = lua_type();
        if (uVar3 != 0xffffffff) {
          PrintConsoleMessage("Lua script PreSnipe error: invalid return param.");
        }
      }
      else {
        PVar5 = lua_tointegerx((undefined4 *)0x0);
      }
    }
    lua_settop();
  }
  return PVar5;
}


// ---------------------------------------------------------------------
// LuaMission::PrePickupPowerup  @ 4fc4745f  lines 528-567

PrePickupPowerupReturnCodes __thiscall
LuaMission::PrePickupPowerup(LuaMission *this,int curWorld,int me,int powerupHandle)

{
  lua_State *plVar1;
  double *pdVar2;
  uint uVar3;
  int iVar4;
  undefined4 extraout_ECX;
  int unaff_EBX;
  char *unaff_ESI;
  lua_State *unaff_EDI;
  PrePickupPowerupReturnCodes PVar5;
  
  PVar5 = PREPICKUPPOWERUP_ALLOW;
  if (this->StopScript == false) {
    PVar5 = BZ1Helper::PrePickupPowerup(&this->super_BZ1Helper,curWorld,me,powerupHandle);
  }
  if (this->L != (lua_State *)0x0) {
    lua_getglobal();
    plVar1 = this->L;
    uVar3 = lua_type();
    if (uVar3 == 6) {
      pdVar2 = *(double **)(plVar1 + 8);
      *pdVar2 = (double)curWorld;
      *(double **)(plVar1 + 8) = pdVar2 + 1;
      LuaBindings::PushHandle(this->L,me);
      LuaBindings::PushHandle(this->L,powerupHandle);
      iVar4 = lua_pcallk(1,0,extraout_ECX,0);
      if (iVar4 != 0) {
        LuaBindings::LuaCheckStatus(unaff_EBX,unaff_EDI,unaff_ESI);
      }
      iVar4 = lua_isnumber();
      if (iVar4 == 0) {
        uVar3 = lua_type();
        if (uVar3 != 0xffffffff) {
          PrintConsoleMessage("Lua script PrePickupPowerup error: invalid return param.");
        }
      }
      else {
        PVar5 = lua_tointegerx((undefined4 *)0x0);
      }
    }
    lua_settop();
  }
  return PVar5;
}


// ---------------------------------------------------------------------
// LuaMission::PostTargetChangedCallback  @ 4fc473d0  lines 571-591

void __thiscall
LuaMission::PostTargetChangedCallback
          (LuaMission *this,int craft,int previousTarget,int currentTarget)

{
  lua_State *L;
  uint uVar1;
  int iVar2;
  undefined4 extraout_ECX;
  char *unaff_EBP;
  lua_State *unaff_ESI;
  int unaff_EDI;
  
  if (this->L != (lua_State *)0x0) {
    lua_getglobal();
    L = this->L;
    uVar1 = lua_type();
    if (uVar1 == 6) {
      LuaBindings::PushHandle(L,craft);
      LuaBindings::PushHandle(this->L,previousTarget);
      LuaBindings::PushHandle(this->L,currentTarget);
      iVar2 = lua_pcallk(0,0,extraout_ECX,0);
      if (iVar2 != 0) {
        LuaBindings::LuaCheckStatus(unaff_EDI,unaff_ESI,unaff_EBP);
      }
    }
    else {
      lua_settop();
    }
  }
  return;
}


// ---------------------------------------------------------------------
// LuaMission::AddObject  @ 4fc48245  lines 594-627

void __thiscall LuaMission::AddObject(LuaMission *this,int h)

{
  lua_State *plVar1;
  uint uVar2;
  int iVar3;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  lua_State *unaff_EBX;
  char *unaff_ESI;
  int unaff_EDI;
  
  if (this->StopScript == false) {
    BZ1Helper::AddObject(&this->super_BZ1Helper,h);
  }
  if (this->L != (lua_State *)0x0) {
    lua_getglobal();
    plVar1 = this->L;
    uVar2 = lua_type();
    if (uVar2 == 6) {
      LuaBindings::PushHandle(plVar1,h);
      iVar3 = lua_pcallk(0,0,extraout_ECX,0);
      if (iVar3 != 0) {
        LuaBindings::LuaCheckStatus(unaff_EDI,unaff_EBX,unaff_ESI);
      }
    }
    else {
      lua_settop();
    }
    lua_getglobal();
    plVar1 = this->L;
    uVar2 = lua_type();
    if (uVar2 == 6) {
      LuaBindings::PushHandle(plVar1,h);
      iVar3 = lua_pcallk(0,0,extraout_ECX_00,0);
      if (iVar3 != 0) {
        LuaBindings::LuaCheckStatus(unaff_EDI,unaff_EBX,unaff_ESI);
      }
    }
    else {
      lua_settop();
    }
  }
  return;
}


// ---------------------------------------------------------------------
// LuaMission::DeleteObject  @ 4fc481c1  lines 630-650

void __thiscall LuaMission::DeleteObject(LuaMission *this,int h)

{
  lua_State *L;
  uint uVar1;
  int iVar2;
  undefined4 extraout_ECX;
  char *unaff_EBP;
  lua_State *unaff_ESI;
  int unaff_EDI;
  
  if (this->StopScript == false) {
    BZ1Helper::DeleteObject(&this->super_BZ1Helper,h);
  }
  if (this->L != (lua_State *)0x0) {
    lua_getglobal();
    L = this->L;
    uVar1 = lua_type();
    if (uVar1 == 6) {
      LuaBindings::PushHandle(L,h);
      iVar2 = lua_pcallk(0,0,extraout_ECX,0);
      if (iVar2 != 0) {
        LuaBindings::LuaCheckStatus(unaff_EDI,unaff_ESI,unaff_EBP);
      }
    }
    else {
      lua_settop();
    }
  }
  return;
}


// ---------------------------------------------------------------------
// LuaMission::AddPlayer  @ 4fc47cc2  lines 653-680

bool __thiscall LuaMission::AddPlayer(LuaMission *this,ulong id,int Team,bool IsNewPlayer)

{
  lua_State *plVar1;
  double *pdVar2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  char *unaff_EBP;
  lua_State *unaff_ESI;
  int unaff_EDI;
  
  if (this->DidSetup == false) {
    Setup(this);
  }
  if (this->L != (lua_State *)0x0) {
    lua_getglobal();
    plVar1 = this->L;
    uVar4 = lua_type();
    if (uVar4 == 6) {
      pdVar2 = *(double **)(plVar1 + 8);
      *pdVar2 = (double)(int)id;
      *(double **)(plVar1 + 8) = pdVar2 + 1;
      plVar1 = this->L;
      pdVar2 = *(double **)(plVar1 + 8);
      *pdVar2 = (double)Team;
      *(double **)(plVar1 + 8) = pdVar2 + 1;
      plVar1 = this->L;
      puVar3 = *(uint **)(plVar1 + 8);
      *puVar3 = (uint)IsNewPlayer;
      puVar3[1] = 0x7ff7a501;
      plVar1 = plVar1 + 8;
      *(int *)plVar1 = *(int *)plVar1 + 8;
      iVar5 = lua_pcallk(1,0,puVar3,0);
      if (iVar5 != 0) {
        LuaBindings::LuaCheckStatus(unaff_EDI,unaff_ESI,unaff_EBP);
      }
    }
    lua_settop();
  }
  return true;
}


// ---------------------------------------------------------------------
// LuaMission::DeletePlayer  @ 4fc47c41  lines 683-699

void __thiscall LuaMission::DeletePlayer(LuaMission *this,ulong id)

{
  lua_State *plVar1;
  double *pdVar2;
  uint uVar3;
  int iVar4;
  undefined4 extraout_ECX;
  char *unaff_EBP;
  int unaff_ESI;
  lua_State *unaff_EDI;
  
  if (this->L != (lua_State *)0x0) {
    lua_getglobal();
    plVar1 = this->L;
    uVar3 = lua_type();
    if (uVar3 == 6) {
      pdVar2 = *(double **)(plVar1 + 8);
      *pdVar2 = (double)(int)id;
      *(double **)(plVar1 + 8) = pdVar2 + 1;
      iVar4 = lua_pcallk(0,0,extraout_ECX,0);
      if (iVar4 != 0) {
        LuaBindings::LuaCheckStatus(unaff_ESI,unaff_EDI,unaff_EBP);
      }
    }
    else {
      lua_settop();
    }
  }
  return;
}


// ---------------------------------------------------------------------
// LuaMission::PlayerEjected  @ 4fc47b82  lines 702-734

EjectKillRetCodes __thiscall LuaMission::PlayerEjected(LuaMission *this,int DeadObjectHandle)

{
  lua_State *L;
  EjectKillRetCodes EVar1;
  uint uVar2;
  int iVar3;
  undefined4 extraout_ECX;
  lua_State *unaff_EBX;
  char *unaff_ESI;
  int unaff_EDI;
  
  if (this->L == (lua_State *)0x0) {
    EVar1 = DoEjectPilot;
  }
  else {
    EVar1 = DoEjectPilot;
    lua_getglobal();
    L = this->L;
    uVar2 = lua_type();
    if (uVar2 == 6) {
      LuaBindings::PushHandle(L,DeadObjectHandle);
      iVar3 = lua_pcallk(1,0,extraout_ECX,0);
      if (iVar3 != 0) {
        LuaBindings::LuaCheckStatus(unaff_EDI,unaff_EBX,unaff_ESI);
      }
      iVar3 = lua_isnumber();
      if (iVar3 == 0) {
        uVar2 = lua_type();
        if (uVar2 != 0xffffffff) {
          PrintConsoleMessage("Lua script PlayerEjected error: invalid return param.");
        }
      }
      else {
        EVar1 = lua_tointegerx((undefined4 *)0x0);
      }
    }
    lua_settop();
  }
  return EVar1;
}


// ---------------------------------------------------------------------
// LuaMission::ObjectKilled  @ 4fc47a69  lines 737-779

EjectKillRetCodes __thiscall
LuaMission::ObjectKilled(LuaMission *this,int DeadObjectHandle,int KillersHandle)

{
  lua_State *L;
  bool bVar1;
  uint uVar2;
  int iVar3;
  EjectKillRetCodes EVar4;
  undefined4 extraout_ECX;
  int unaff_EBX;
  char *unaff_ESI;
  lua_State *unaff_EDI;
  
  if (this->StopScript == false) {
    BZ1Helper::DeadObject(&this->super_BZ1Helper,DeadObjectHandle);
  }
  if (this->L == (lua_State *)0x0) {
    bVar1 = IsPlayer(DeadObjectHandle);
    EVar4 = DoEjectPilot;
    if (!bVar1) {
      EVar4 = DLLHandled;
    }
  }
  else {
    bVar1 = IsPlayer(DeadObjectHandle);
    EVar4 = DLLHandled;
    if (bVar1) {
      EVar4 = DoEjectPilot;
    }
    lua_getglobal();
    L = this->L;
    uVar2 = lua_type();
    if (uVar2 == 6) {
      LuaBindings::PushHandle(L,DeadObjectHandle);
      LuaBindings::PushHandle(this->L,KillersHandle);
      iVar3 = lua_pcallk(1,0,extraout_ECX,0);
      if (iVar3 != 0) {
        LuaBindings::LuaCheckStatus(unaff_EBX,unaff_EDI,unaff_ESI);
      }
      iVar3 = lua_isnumber();
      if (iVar3 == 0) {
        uVar2 = lua_type();
        if (uVar2 != 0xffffffff) {
          PrintConsoleMessage("Lua script ObjectKilled error: invalid return param.");
        }
      }
      else {
        EVar4 = lua_tointegerx((undefined4 *)0x0);
      }
    }
    lua_settop();
  }
  return EVar4;
}


// ---------------------------------------------------------------------
// LuaMission::ObjectSniped  @ 4fc4796b  lines 782-820

EjectKillRetCodes __thiscall
LuaMission::ObjectSniped(LuaMission *this,int DeadObjectHandle,int KillersHandle)

{
  lua_State *L;
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined4 extraout_ECX;
  lua_State *unaff_EBX;
  EjectKillRetCodes EVar4;
  char *unaff_ESI;
  int unaff_EDI;
  
  if (this->L == (lua_State *)0x0) {
    bVar1 = IsPlayer(DeadObjectHandle);
    EVar4 = bVar1 + DLLHandled;
  }
  else {
    bVar1 = IsPlayer(DeadObjectHandle);
    EVar4 = bVar1 + DLLHandled;
    lua_getglobal();
    L = this->L;
    uVar2 = lua_type();
    if (uVar2 == 6) {
      LuaBindings::PushHandle(L,DeadObjectHandle);
      LuaBindings::PushHandle(this->L,KillersHandle);
      iVar3 = lua_pcallk(1,0,extraout_ECX,0);
      if (iVar3 != 0) {
        LuaBindings::LuaCheckStatus(unaff_EDI,unaff_EBX,unaff_ESI);
      }
      iVar3 = lua_isnumber();
      if (iVar3 == 0) {
        uVar2 = lua_type();
        if (uVar2 != 0xffffffff) {
          PrintConsoleMessage("Lua script ObjectSniped error: invalid return param.");
        }
      }
      else {
        EVar4 = lua_tointegerx((undefined4 *)0x0);
      }
    }
    lua_settop();
  }
  return EVar4;
}


// ---------------------------------------------------------------------
// LuaMission::GetNextRandomVehicleODF  @ 4fc471e4  lines 823-841

char * __thiscall LuaMission::GetNextRandomVehicleODF(LuaMission *this,int Team)

{
  lua_State *plVar1;
  double *pdVar2;
  char *pcVar3;
  uint uVar4;
  int iVar5;
  undefined4 extraout_ECX;
  char *unaff_EBP;
  lua_State *unaff_ESI;
  int unaff_EDI;
  
  if (this->L == (lua_State *)0x0) {
    pcVar3 = GetPlayerODF(Team,Randomize_None);
  }
  else {
    lua_getglobal();
    plVar1 = this->L;
    uVar4 = lua_type();
    if (uVar4 == 6) {
      pdVar2 = *(double **)(plVar1 + 8);
      *pdVar2 = (double)Team;
      *(double **)(plVar1 + 8) = pdVar2 + 1;
      iVar5 = lua_pcallk(1,0,extraout_ECX,0);
      if (iVar5 != 0) {
        LuaBindings::LuaCheckStatus(unaff_EDI,unaff_ESI,unaff_EBP);
      }
    }
    else {
      lua_settop();
    }
    pcVar3 = GetPlayerODF(Team,Randomize_None);
  }
  return pcVar3;
}


// ---------------------------------------------------------------------
// LuaMission::Execute  @ 4fc48141  lines 845-872

void __thiscall LuaMission::Execute(LuaMission *this)

{
  uint uVar1;
  int iVar2;
  undefined4 extraout_ECX;
  int in_stack_00000004;
  lua_State *in_stack_00000008;
  char *in_stack_0000000c;
  
  if (this->StopScript == false) {
    BZ1Helper::Execute(&this->super_BZ1Helper);
  }
  if (this->DidSetup == false) {
    Setup(this);
  }
  this->m_ElapsedGameTime = this->m_ElapsedGameTime + 1;
  if (this->L != (lua_State *)0x0) {
    lua_getglobal();
    uVar1 = lua_type();
    if (uVar1 != 6) {
      lua_settop();
      return;
    }
    iVar2 = lua_pcallk(0,0,extraout_ECX,0);
    if (iVar2 != 0) {
      LuaBindings::LuaCheckStatus(in_stack_00000004,in_stack_00000008,in_stack_0000000c);
      return;
    }
  }
  return;
}


// ---------------------------------------------------------------------
// LuaMission::PostRun  @ 4fc480e5  lines 875-890

void __thiscall LuaMission::PostRun(LuaMission *this)

{
  uint uVar1;
  int iVar2;
  undefined4 extraout_ECX;
  int in_stack_00000004;
  lua_State *in_stack_00000008;
  char *in_stack_0000000c;
  
  if (this->L != (lua_State *)0x0) {
    lua_getglobal();
    uVar1 = lua_type();
    if (uVar1 != 6) {
      lua_settop();
      return;
    }
    iVar2 = lua_pcallk(0,0,extraout_ECX,0);
    if (iVar2 != 0) {
      LuaBindings::LuaCheckStatus(in_stack_00000004,in_stack_00000008,in_stack_0000000c);
      return;
    }
  }
  return;
}


// ---------------------------------------------------------------------
// LuaMission::ProcessCommand  @ 4fc478ea  lines 893-909

void __thiscall LuaMission::ProcessCommand(LuaMission *this,ulong crc)

{
  lua_State *plVar1;
  double *pdVar2;
  uint uVar3;
  int iVar4;
  undefined4 extraout_ECX;
  char *unaff_EBP;
  int unaff_ESI;
  lua_State *unaff_EDI;
  
  if (this->L != (lua_State *)0x0) {
    lua_getglobal();
    plVar1 = this->L;
    uVar3 = lua_type();
    if (uVar3 == 6) {
      pdVar2 = *(double **)(plVar1 + 8);
      *pdVar2 = (double)(int)crc;
      *(double **)(plVar1 + 8) = pdVar2 + 1;
      iVar4 = lua_pcallk(0,0,extraout_ECX,0);
      if (iVar4 != 0) {
        LuaBindings::LuaCheckStatus(unaff_ESI,unaff_EDI,unaff_EBP);
      }
    }
    else {
      lua_settop();
    }
  }
  return;
}


// ---------------------------------------------------------------------
// LuaMission::SetRandomSeed  @ 4fc47869  lines 912-928

void __thiscall LuaMission::SetRandomSeed(LuaMission *this,ulong seed)

{
  lua_State *plVar1;
  double *pdVar2;
  uint uVar3;
  int iVar4;
  undefined4 extraout_ECX;
  char *unaff_EBP;
  int unaff_ESI;
  lua_State *unaff_EDI;
  
  if (this->L != (lua_State *)0x0) {
    lua_getglobal();
    plVar1 = this->L;
    uVar3 = lua_type();
    if (uVar3 == 6) {
      pdVar2 = *(double **)(plVar1 + 8);
      *pdVar2 = (double)(int)seed;
      *(double **)(plVar1 + 8) = pdVar2 + 1;
      iVar4 = lua_pcallk(0,0,extraout_ECX,0);
      if (iVar4 != 0) {
        LuaBindings::LuaCheckStatus(unaff_ESI,unaff_EDI,unaff_EBP);
      }
    }
    else {
      lua_settop();
    }
  }
  return;
}


// ---------------------------------------------------------------------
// LuaMission::CreateLuaStringTable  @ 4fc47159  lines 931-943

void __thiscall
LuaMission::CreateLuaStringTable
          (LuaMission *this,lua_State *param_1,char **param_2,int param_3,char *param_4)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  
  lua_createtable(param_3);
  iVar3 = 0;
  if (0 < param_3) {
    do {
      lua_pushnumber();
      lua_pushstring();
      puVar1 = *(undefined4 **)(param_1 + 8);
      *puVar1 = puVar1[-2];
      puVar1[1] = puVar1[-1];
      iVar2 = *(int *)(param_1 + 8);
      *(undefined4 **)(param_1 + 8) = (undefined4 *)(iVar2 + 8);
      *(undefined4 *)(iVar2 + 8) = *(undefined4 *)(iVar2 + -0x10);
      *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(iVar2 + -0xc);
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
      lua_rawset();
      lua_rawset();
      iVar3 = iVar3 + 1;
    } while (iVar3 < param_3);
  }
  lua_setglobal();
  return;
}


// ---------------------------------------------------------------------
// LuaMission::PreTeleport  @ 4fc472fe  lines 947-985

PreTeleportReturnCodes __thiscall
LuaMission::PreTeleport(LuaMission *this,int portalHandle,int shipHandle)

{
  lua_State *L;
  uint uVar1;
  int iVar2;
  undefined4 extraout_ECX;
  int unaff_EBX;
  char *unaff_ESI;
  lua_State *unaff_EDI;
  PreTeleportReturnCodes PVar3;
  
  PVar3 = PreTeleport_DEFAULT;
  if (this->L == (lua_State *)0x0) {
    PVar3 = PreTeleport_DEFAULT;
  }
  else {
    lua_getglobal();
    L = this->L;
    uVar1 = lua_type();
    if (uVar1 == 6) {
      LuaBindings::PushHandle(L,portalHandle);
      LuaBindings::PushHandle(this->L,shipHandle);
      iVar2 = lua_pcallk(1,0,extraout_ECX,0);
      if (iVar2 != 0) {
        LuaBindings::LuaCheckStatus(unaff_EBX,unaff_EDI,unaff_ESI);
      }
      iVar2 = lua_isnumber();
      if (iVar2 == 0) {
        uVar1 = lua_type();
        if (uVar1 != 0xffffffff) {
          PrintConsoleMessage("Lua script PreTeleport error: invalid return param.");
        }
      }
      else {
        PVar3 = lua_tointegerx((undefined4 *)0x0);
      }
    }
    lua_settop();
  }
  return PVar3;
}


