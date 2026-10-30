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
  char *in_stack_ffffffdc;
  
  BZ1Helper::BZ1Helper((BZ1Helper *)this);
  this->_padding_ = (int)vftable;
  this[1]._padding_ = 0x14;
  EnableHighTPS(&this[1]._padding_);
  AllowRandomTracks(true);
  this[1]._padding_ = 2;
  this[1]._padding_ = (int)((int)&this[1]._padding_ + 1);
  this[1]._padding_ = 3;
  this[1]._padding_ = (int)&this[1]._padding_;
  GetMapTRNFilename();
  TRNAllies::SetupTRNAllies(in_stack_ffffffdc);
  if ((void *)this[1]._padding_ != (void *)0x0) {
    memset((void *)this[1]._padding_,0,this[1]._padding_ << 2);
  }
  if ((void *)this[1]._padding_ != (void *)0x0) {
    memset((void *)this[1]._padding_,0,this[1]._padding_);
  }
  this[1]._padding_ = 0;
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
  this->_padding_ = (int)vftable;
  CloseOpenODFs();
  CloseOpenFiles();
  CleanupTaunts();
  if (this[1]._padding_ != 0) {
    FUN_4fc2d3b2(*(int *)(*(int *)(this[1]._padding_ + 0xc) + 0x9c));
  }
  BZ1Helper::~BZ1Helper((BZ1Helper *)this);
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
  
  *(undefined1 *)((int)&this[1]._padding_ + 1) = 1;
  InitTaunts(&this[1]._padding_,&this->_padding_,unaff_ESI,unaff_retaddr);
  if (this[1]._padding_ != 0) {
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
  int *piVar1;
  undefined8 *puVar2;
  bool bVar3;
  char *pcVar4;
  undefined4 *puVar5;
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
  lua_State *unaff_EDI;
  uint local_94;
  char local_90 [132];
  uint local_c;
  
  local_c = __security_cookie ^ (uint)&local_94;
  EnableHighTPS(&this[1]._padding_);
  SetAutoGroupUnits(false);
  memset(local_90,0,0x80);
  pcVar4 = GetMissionFilename();
  strcpy_s(local_90,0x80,pcVar4);
  pcVar4 = strchr(local_90,0x2e);
  if (pcVar4 != (char *)0x0) {
    *pcVar4 = '\0';
  }
  strcat_s(local_90,0x80,".lua");
  bVar3 = DoesFileExist(local_90);
  if (bVar3) {
    puVar5 = lua_newstate(&LAB_4fc2d0b6,0);
    if (puVar5 != (undefined4 *)0x0) {
      *(undefined1 **)(puVar5[3] + 0x98) = &LAB_4fc2d0dc;
    }
    this[1]._padding_ = (int)puVar5;
    if (puVar5 != (undefined4 *)0x0) {
      luaL_openlibs();
      iVar8 = this[1]._padding_;
      *(undefined4 *)(*(int *)(iVar8 + 8) + 4) = 0x7ff7a500;
      piVar1 = (int *)(iVar8 + 8);
      *piVar1 = *piVar1 + 8;
      lua_setglobal();
      iVar8 = this[1]._padding_;
      *(undefined4 *)(*(int *)(iVar8 + 8) + 4) = 0x7ff7a500;
      piVar1 = (int *)(iVar8 + 8);
      *piVar1 = *piVar1 + 8;
      lua_setglobal();
      *(code **)(*(int *)(this[1]._padding_ + 0xc) + 0x98) = LuaPanic;
      iVar8 = this[1]._padding_;
      puVar5 = *(undefined4 **)(iVar8 + 8);
      *puVar5 = LuaPrint;
      puVar5[1] = 0x7ff7a516;
      piVar1 = (int *)(iVar8 + 8);
      *piVar1 = *piVar1 + 8;
      lua_setglobal();
      lua_rawgeti();
      luaL_setfuncs(0);
      iVar8 = this[1]._padding_;
      puVar5 = *(undefined4 **)(iVar8 + 8);
      *puVar5 = 0;
      puVar5[1] = 0x7ff7a502;
      piVar1 = (int *)(iVar8 + 8);
      *piVar1 = *piVar1 + 8;
      luaL_newmetatable();
      lua_pushstring();
      lua_setfield();
      iVar8 = this[1]._padding_;
      puVar5 = *(undefined4 **)(iVar8 + 8);
      *puVar5 = LuaBindings::Handle_ToString;
      puVar5[1] = 0x7ff7a516;
      piVar1 = (int *)(iVar8 + 8);
      *piVar1 = *piVar1 + 8;
      lua_setfield();
      iVar8 = this[1]._padding_;
      puVar5 = *(undefined4 **)(iVar8 + 8);
      *puVar5 = LuaBindings::Handle_ToInteger;
      puVar5[1] = 0x7ff7a516;
      piVar1 = (int *)(iVar8 + 8);
      *piVar1 = *piVar1 + 8;
      lua_setfield();
      lua_setmetatable();
      luaL_newmetatable();
      lua_pushstring();
      lua_setfield();
      iVar8 = this[1]._padding_;
      puVar5 = *(undefined4 **)(iVar8 + 8);
      *puVar5 = LuaBindings::Vector_Index;
      puVar5[1] = 0x7ff7a516;
      piVar1 = (int *)(iVar8 + 8);
      *piVar1 = *piVar1 + 8;
      lua_setfield();
      iVar8 = this[1]._padding_;
      puVar5 = *(undefined4 **)(iVar8 + 8);
      *puVar5 = LuaBindings::Vector_NewIndex;
      puVar5[1] = 0x7ff7a516;
      piVar1 = (int *)(iVar8 + 8);
      *piVar1 = *piVar1 + 8;
      lua_setfield();
      iVar8 = this[1]._padding_;
      puVar5 = *(undefined4 **)(iVar8 + 8);
      *puVar5 = LuaBindings::Vector_Neg;
      puVar5[1] = 0x7ff7a516;
      piVar1 = (int *)(iVar8 + 8);
      *piVar1 = *piVar1 + 8;
      lua_setfield();
      iVar8 = this[1]._padding_;
      puVar5 = *(undefined4 **)(iVar8 + 8);
      *puVar5 = LuaBindings::Vector_Add;
      puVar5[1] = 0x7ff7a516;
      piVar1 = (int *)(iVar8 + 8);
      *piVar1 = *piVar1 + 8;
      lua_setfield();
      iVar8 = this[1]._padding_;
      puVar5 = *(undefined4 **)(iVar8 + 8);
      *puVar5 = LuaBindings::Vector_Sub;
      puVar5[1] = 0x7ff7a516;
      piVar1 = (int *)(iVar8 + 8);
      *piVar1 = *piVar1 + 8;
      lua_setfield();
      iVar8 = this[1]._padding_;
      puVar5 = *(undefined4 **)(iVar8 + 8);
      *puVar5 = LuaBindings::Vector_Mul;
      puVar5[1] = 0x7ff7a516;
      piVar1 = (int *)(iVar8 + 8);
      *piVar1 = *piVar1 + 8;
      lua_setfield();
      iVar8 = this[1]._padding_;
      puVar5 = *(undefined4 **)(iVar8 + 8);
      *puVar5 = LuaBindings::Vector_Div;
      puVar5[1] = 0x7ff7a516;
      piVar1 = (int *)(iVar8 + 8);
      *piVar1 = *piVar1 + 8;
      lua_setfield();
      iVar8 = this[1]._padding_;
      puVar5 = *(undefined4 **)(iVar8 + 8);
      *puVar5 = LuaBindings::Vector_Eq;
      puVar5[1] = 0x7ff7a516;
      piVar1 = (int *)(iVar8 + 8);
      *piVar1 = *piVar1 + 8;
      lua_setfield();
      iVar8 = this[1]._padding_;
      puVar5 = *(undefined4 **)(iVar8 + 8);
      *puVar5 = LuaBindings::Vector_ToString;
      puVar5[1] = 0x7ff7a516;
      piVar1 = (int *)(iVar8 + 8);
      *piVar1 = *piVar1 + 8;
      lua_setfield();
      lua_settop();
      luaL_newmetatable();
      lua_pushstring();
      lua_setfield();
      iVar8 = this[1]._padding_;
      puVar5 = *(undefined4 **)(iVar8 + 8);
      *puVar5 = LuaBindings::Matrix_Index;
      puVar5[1] = 0x7ff7a516;
      piVar1 = (int *)(iVar8 + 8);
      *piVar1 = *piVar1 + 8;
      lua_setfield();
      iVar8 = this[1]._padding_;
      puVar5 = *(undefined4 **)(iVar8 + 8);
      *puVar5 = LuaBindings::Matrix_NewIndex;
      puVar5[1] = 0x7ff7a516;
      piVar1 = (int *)(iVar8 + 8);
      *piVar1 = *piVar1 + 8;
      lua_setfield();
      iVar8 = this[1]._padding_;
      puVar5 = *(undefined4 **)(iVar8 + 8);
      *puVar5 = LuaBindings::Matrix_Mul;
      puVar5[1] = 0x7ff7a516;
      piVar1 = (int *)(iVar8 + 8);
      *piVar1 = *piVar1 + 8;
      lua_setfield();
      iVar8 = this[1]._padding_;
      puVar5 = *(undefined4 **)(iVar8 + 8);
      *puVar5 = LuaBindings::Matrix_ToString;
      puVar5[1] = 0x7ff7a516;
      piVar1 = (int *)(iVar8 + 8);
      *piVar1 = *piVar1 + 8;
      lua_setfield();
      lua_settop();
      luaL_newmetatable();
      lua_pushstring();
      lua_setfield();
      iVar8 = this[1]._padding_;
      puVar5 = *(undefined4 **)(iVar8 + 8);
      *puVar5 = LuaBindings::Quaternion_Index;
      puVar5[1] = 0x7ff7a516;
      piVar1 = (int *)(iVar8 + 8);
      *piVar1 = *piVar1 + 8;
      lua_setfield();
      iVar8 = this[1]._padding_;
      puVar5 = *(undefined4 **)(iVar8 + 8);
      *puVar5 = LuaBindings::Quaternion_NewIndex;
      puVar5[1] = 0x7ff7a516;
      piVar1 = (int *)(iVar8 + 8);
      *piVar1 = *piVar1 + 8;
      lua_setfield();
      iVar8 = this[1]._padding_;
      puVar5 = *(undefined4 **)(iVar8 + 8);
      *puVar5 = LuaBindings::Quaternion_Mul;
      puVar5[1] = 0x7ff7a516;
      piVar1 = (int *)(iVar8 + 8);
      *piVar1 = *piVar1 + 8;
      lua_setfield();
      iVar8 = this[1]._padding_;
      puVar5 = *(undefined4 **)(iVar8 + 8);
      *puVar5 = LuaBindings::Quaternion_ToString;
      puVar5[1] = 0x7ff7a516;
      piVar1 = (int *)(iVar8 + 8);
      *piVar1 = *piVar1 + 8;
      lua_setfield();
      lua_settop();
      pMVar6 = LuaBindings::NewMatrix(unaff_EDI);
      pMVar10 = &::Identity_Matrix;
      for (iVar8 = 0x10; iVar8 != 0; iVar8 = iVar8 + -1) {
        (pMVar6->right).x = (pMVar10->right).x;
        pMVar10 = (Matrix *)&(pMVar10->right).y;
        pMVar6 = (Matrix *)&(pMVar6->right).y;
      }
      lua_setglobal();
      CreateLuaStringTable(this_00,(lua_State *)this[1]._padding_,CommandList,0x36,"AiCommand");
      CreateLuaStringTable(this_01,(lua_State *)this[1]._padding_,TauntTypesList,0x10,"TauntTypes");
      CreateLuaStringTable
                (this_02,(lua_State *)this[1]._padding_,DeathmatchGameSubtypesList,8,
                 "DMSubGameTypes");
      CreateLuaStringTable
                (this_03,(lua_State *)this[1]._padding_,PreSnipeReturnCodesList,2,
                 "PreSnipeReturnValues");
      CreateLuaStringTable
                (this_04,(lua_State *)this[1]._padding_,PreGetInReturnCodesList,2,
                 "PreGetInReturnValues");
      CreateLuaStringTable
                (this_05,(lua_State *)this[1]._padding_,PrePickupPowerupReturnCodesList,2,
                 "PrePickupPowerupReturnValues");
      CreateLuaStringTable
                (this_06,(lua_State *)this[1]._padding_,RandomizeTypeList,3,"RandomizeTypes");
      CreateLuaStringTable
                (this_07,(lua_State *)this[1]._padding_,TeamRelationshipList,4,
                 "TeamRelationshipTypes");
      CreateLuaStringTable
                (this_08,(lua_State *)this[1]._padding_,EjectKillRetCodeList,4,"EjectKillRetCodes");
      iVar8 = this[1]._padding_;
      puVar2 = *(undefined8 **)(iVar8 + 8);
      *puVar2 = __real_4067400000000000;
      *(undefined8 **)(iVar8 + 8) = puVar2 + 1;
      lua_setglobal();
      local_94 = 0;
      LoadFile(local_90,(void *)0x0,&local_94);
      _Memory = malloc(local_94 + 1);
      LoadFile(local_90,_Memory,&local_94);
      *(undefined1 *)((int)_Memory + local_94) = 0;
      iVar8 = luaL_loadbufferx(local_94,local_90,0);
      if (iVar8 == 0) {
        bVar3 = true;
        uVar9 = extraout_ECX;
      }
      else {
        bVar3 = LuaBindings::LuaCheckStatus((int)unaff_EDI,unaff_ESI,unaff_EBX);
        uVar9 = extraout_ECX_00;
      }
      if (bVar3 != false) {
        iVar8 = lua_pcallk(-1,0,uVar9,0);
        if (iVar8 != 0) {
          LuaBindings::LuaCheckStatus((int)unaff_EDI,unaff_ESI,unaff_EBX);
        }
      }
      free(_Memory);
      if (this[1]._padding_ != 0) {
        FormatConsoleMessage("Lua script: \'%s\' loaded");
        lua_getglobal();
        uVar7 = lua_type();
        if (uVar7 == 6) {
          iVar8 = lua_pcallk(0,0,extraout_ECX_01,0);
          if (iVar8 != 0) {
            LuaBindings::LuaCheckStatus((int)unaff_EDI,unaff_ESI,unaff_EBX);
          }
        }
        else {
          lua_settop();
        }
      }
    }
  }
  else {
    FormatConsoleMessage("No Lua script: \'%s\'");
  }
  return;
}


// ---------------------------------------------------------------------
// LuaMission::Load  @ 4fc47f3d  lines 288-350


bool __thiscall LuaMission::Load(LuaMission *this,bool param_1)

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
  bVar1 = BZ1Helper::Load((BZ1Helper *)this,param_1);
  iVar4 = this[1]._padding_;
  if (param_1) {
    iVar3 = 0;
    if (0 < iVar4) {
      do {
        *(undefined1 *)(iVar3 + this[1]._padding_) = 0;
        iVar3 = iVar3 + 1;
      } while (iVar3 < this[1]._padding_);
    }
    iVar4 = 0;
    if (0 < this[1]._padding_) {
      do {
        *(undefined4 *)(this[1]._padding_ + iVar4 * 4) = 0;
        iVar4 = iVar4 + 1;
      } while (iVar4 < this[1]._padding_);
    }
    return true;
  }
  if (iVar4 != 0) {
    if ((bVar1) && (bVar1 = Read((bool *)this[1]._padding_,iVar4), bVar1)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
  }
  if (this[1]._padding_ != 0) {
    if ((bVar1 == false) || (bVar1 = Read((int *)this[1]._padding_,this[1]._padding_), !bVar1)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
  }
  if (this[1]._padding_ == 0) {
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


bool __thiscall LuaMission::PostLoad(LuaMission *this,bool param_1)

{
  bool bVar1;
  
  bVar1 = BZ1Helper::PostLoad((BZ1Helper *)this,param_1);
  if (param_1) {
    bVar1 = true;
  }
  return bVar1;
}


// ---------------------------------------------------------------------
// LuaMission::Save  @ 4fc47d92  lines 366-413


bool __thiscall LuaMission::Save(LuaMission *this,bool param_1)

{
  bool bVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  char *unaff_EBX;
  lua_State *unaff_ESI;
  lua_State *unaff_EDI;
  int iVar5;
  undefined3 in_stack_00000005;
  LuaMission *local_8;
  
  local_8 = this;
  bVar1 = BZ1Helper::Save((BZ1Helper *)this,param_1);
  if (param_1 == false) {
    if (this[1]._padding_ != 0) {
      if ((bVar1) && (bVar1 = Write((bool *)this[1]._padding_,this[1]._padding_), bVar1)) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
    }
    if (this[1]._padding_ != 0) {
      if ((bVar1 == false) || (bVar1 = Write((int *)this[1]._padding_,this[1]._padding_), !bVar1)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
    }
    if (this[1]._padding_ != 0) {
      lua_getglobal();
      _param_1 = this[1]._padding_;
      uVar3 = lua_type();
      if (uVar3 == 6) {
        iVar5 = (*(int *)(_param_1 + 8) - **(int **)(_param_1 + 0x10)) + -8 >> 3;
        iVar4 = lua_pcallk(-1,0,_param_1,0);
        if (iVar4 == 0) {
          bVar2 = true;
        }
        else {
          bVar2 = LuaBindings::LuaCheckStatus((int)unaff_EDI,unaff_ESI,unaff_EBX);
        }
        if (bVar2 != false) {
          local_8 = (LuaMission *)
                    ((((*(int *)(this[1]._padding_ + 8) - **(int **)(this[1]._padding_ + 0x10)) + -8
                      >> 3) - iVar5) + 1);
          if ((bVar1 == false) || (bVar1 = Write((int *)&local_8,1), !bVar1)) {
            bVar1 = false;
          }
          else {
            bVar1 = true;
          }
          _param_1 = iVar5;
          if (iVar5 < (int)&local_8->_padding_ + iVar5) {
            do {
              if ((bVar1 == false) ||
                 (bVar1 = LuaBindings::SaveValue(unaff_EDI,(int)unaff_ESI), !bVar1)) {
                bVar1 = false;
              }
              else {
                bVar1 = true;
              }
              _param_1 = _param_1 + 1;
            } while (_param_1 < (int)&local_8->_padding_ + iVar5);
          }
        }
      }
      else {
        _param_1 = 0;
        if ((bVar1 == false) || (bVar1 = Write((int *)&param_1,1), !bVar1)) {
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
LuaMission::PreOrdnanceHit(LuaMission *this,int param_1,int param_2,int param_3,char *param_4)

{
  double *pdVar1;
  uint uVar2;
  int iVar3;
  undefined4 extraout_ECX;
  char *unaff_EBP;
  lua_State *unaff_ESI;
  lua_State *unaff_EDI;
  
  if (*(char *)((int)&this[1]._padding_ + 2) == '\0') {
    BZ1Helper::PreOrdnanceHit((BZ1Helper *)this,param_1,param_2,param_3,param_4);
  }
  if (this[1]._padding_ != 0) {
    lua_getglobal();
    uVar2 = lua_type();
    if (uVar2 == 6) {
      LuaBindings::PushHandle(unaff_EDI,(int)unaff_ESI);
      LuaBindings::PushHandle(unaff_EDI,(int)unaff_ESI);
      iVar3 = this[1]._padding_;
      pdVar1 = *(double **)(iVar3 + 8);
      *pdVar1 = (double)param_3;
      *(double **)(iVar3 + 8) = pdVar1 + 1;
      lua_pushstring();
      iVar3 = lua_pcallk(0,0,extraout_ECX,0);
      if (iVar3 != 0) {
        LuaBindings::LuaCheckStatus((int)unaff_EDI,unaff_ESI,unaff_EBP);
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
LuaMission::PreGetIn(LuaMission *this,int param_1,int param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 extraout_ECX;
  char *unaff_EBX;
  lua_State *unaff_ESI;
  lua_State *unaff_EDI;
  PreGetInReturnCodes PVar3;
  
  PVar3 = PREGETIN_ALLOW;
  if (*(char *)((int)&this[1]._padding_ + 2) == '\0') {
    PVar3 = BZ1Helper::PreGetIn((BZ1Helper *)this,param_1,param_2,param_3);
  }
  if (this[1]._padding_ != 0) {
    lua_getglobal();
    uVar1 = lua_type();
    if (uVar1 == 6) {
      lua_pushnumber();
      LuaBindings::PushHandle(unaff_EDI,(int)unaff_ESI);
      LuaBindings::PushHandle(unaff_EDI,(int)unaff_ESI);
      iVar2 = lua_pcallk(1,0,extraout_ECX,0);
      if (iVar2 != 0) {
        LuaBindings::LuaCheckStatus((int)unaff_EDI,unaff_ESI,unaff_EBX);
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
LuaMission::PreSnipe(LuaMission *this,int param_1,int param_2,int param_3,int param_4,char *param_5)

{
  double *pdVar1;
  uint uVar2;
  int iVar3;
  undefined4 extraout_ECX;
  lua_State *unaff_EBX;
  char *unaff_ESI;
  lua_State *unaff_EDI;
  PreSnipeReturnCodes PVar4;
  
  PVar4 = PRESNIPE_KILLPILOT;
  if (*(char *)((int)&this[1]._padding_ + 2) == '\0') {
    PVar4 = BZ1Helper::PreSnipe((BZ1Helper *)this,param_1,param_2,param_3,param_4,param_5);
  }
  if (this[1]._padding_ != 0) {
    lua_getglobal();
    iVar3 = this[1]._padding_;
    uVar2 = lua_type();
    if (uVar2 == 6) {
      pdVar1 = *(double **)(iVar3 + 8);
      *pdVar1 = (double)param_1;
      *(double **)(iVar3 + 8) = pdVar1 + 1;
      LuaBindings::PushHandle(unaff_EBX,(int)unaff_EDI);
      LuaBindings::PushHandle(unaff_EBX,(int)unaff_EDI);
      iVar3 = this[1]._padding_;
      pdVar1 = *(double **)(iVar3 + 8);
      *pdVar1 = (double)param_4;
      *(double **)(iVar3 + 8) = pdVar1 + 1;
      lua_pushstring();
      iVar3 = lua_pcallk(1,0,extraout_ECX,0);
      if (iVar3 != 0) {
        LuaBindings::LuaCheckStatus((int)unaff_EBX,unaff_EDI,unaff_ESI);
      }
      iVar3 = lua_isnumber();
      if (iVar3 == 0) {
        uVar2 = lua_type();
        if (uVar2 != 0xffffffff) {
          PrintConsoleMessage("Lua script PreSnipe error: invalid return param.");
        }
      }
      else {
        PVar4 = lua_tointegerx((undefined4 *)0x0);
      }
    }
    lua_settop();
  }
  return PVar4;
}


// ---------------------------------------------------------------------
// LuaMission::PrePickupPowerup  @ 4fc4745f  lines 528-567


PrePickupPowerupReturnCodes __thiscall
LuaMission::PrePickupPowerup(LuaMission *this,int param_1,int param_2,int param_3)

{
  double *pdVar1;
  uint uVar2;
  int iVar3;
  undefined4 extraout_ECX;
  lua_State *unaff_EBX;
  char *unaff_ESI;
  lua_State *unaff_EDI;
  PrePickupPowerupReturnCodes PVar4;
  
  PVar4 = PREPICKUPPOWERUP_ALLOW;
  if (*(char *)((int)&this[1]._padding_ + 2) == '\0') {
    PVar4 = BZ1Helper::PrePickupPowerup((BZ1Helper *)this,param_1,param_2,param_3);
  }
  if (this[1]._padding_ != 0) {
    lua_getglobal();
    iVar3 = this[1]._padding_;
    uVar2 = lua_type();
    if (uVar2 == 6) {
      pdVar1 = *(double **)(iVar3 + 8);
      *pdVar1 = (double)param_1;
      *(double **)(iVar3 + 8) = pdVar1 + 1;
      LuaBindings::PushHandle(unaff_EBX,(int)unaff_EDI);
      LuaBindings::PushHandle(unaff_EBX,(int)unaff_EDI);
      iVar3 = lua_pcallk(1,0,extraout_ECX,0);
      if (iVar3 != 0) {
        LuaBindings::LuaCheckStatus((int)unaff_EBX,unaff_EDI,unaff_ESI);
      }
      iVar3 = lua_isnumber();
      if (iVar3 == 0) {
        uVar2 = lua_type();
        if (uVar2 != 0xffffffff) {
          PrintConsoleMessage("Lua script PrePickupPowerup error: invalid return param.");
        }
      }
      else {
        PVar4 = lua_tointegerx((undefined4 *)0x0);
      }
    }
    lua_settop();
  }
  return PVar4;
}


// ---------------------------------------------------------------------
// LuaMission::PostTargetChangedCallback  @ 4fc473d0  lines 571-591


void __thiscall
LuaMission::PostTargetChangedCallback(LuaMission *this,int param_1,int param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 extraout_ECX;
  char *unaff_EBP;
  lua_State *unaff_ESI;
  lua_State *unaff_EDI;
  
  if (this[1]._padding_ != 0) {
    lua_getglobal();
    uVar1 = lua_type();
    if (uVar1 == 6) {
      LuaBindings::PushHandle(unaff_EDI,(int)unaff_ESI);
      LuaBindings::PushHandle(unaff_EDI,(int)unaff_ESI);
      LuaBindings::PushHandle(unaff_EDI,(int)unaff_ESI);
      iVar2 = lua_pcallk(0,0,extraout_ECX,0);
      if (iVar2 != 0) {
        LuaBindings::LuaCheckStatus((int)unaff_EDI,unaff_ESI,unaff_EBP);
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


void __thiscall LuaMission::AddObject(LuaMission *this,int param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  lua_State *unaff_EBX;
  char *unaff_ESI;
  lua_State *unaff_EDI;
  
  if (*(char *)((int)&this[1]._padding_ + 2) == '\0') {
    BZ1Helper::AddObject((BZ1Helper *)this,param_1);
  }
  if (this[1]._padding_ != 0) {
    lua_getglobal();
    uVar1 = lua_type();
    if (uVar1 == 6) {
      LuaBindings::PushHandle(unaff_EDI,(int)unaff_EBX);
      iVar2 = lua_pcallk(0,0,extraout_ECX,0);
      if (iVar2 != 0) {
        LuaBindings::LuaCheckStatus((int)unaff_EDI,unaff_EBX,unaff_ESI);
      }
    }
    else {
      lua_settop();
    }
    lua_getglobal();
    uVar1 = lua_type();
    if (uVar1 == 6) {
      LuaBindings::PushHandle(unaff_EDI,(int)unaff_EBX);
      iVar2 = lua_pcallk(0,0,extraout_ECX_00,0);
      if (iVar2 != 0) {
        LuaBindings::LuaCheckStatus((int)unaff_EDI,unaff_EBX,unaff_ESI);
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


void __thiscall LuaMission::DeleteObject(LuaMission *this,int param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 extraout_ECX;
  char *unaff_EBP;
  lua_State *unaff_ESI;
  lua_State *unaff_EDI;
  
  if (*(char *)((int)&this[1]._padding_ + 2) == '\0') {
    BZ1Helper::DeleteObject((BZ1Helper *)this,param_1);
  }
  if (this[1]._padding_ != 0) {
    lua_getglobal();
    uVar1 = lua_type();
    if (uVar1 == 6) {
      LuaBindings::PushHandle(unaff_EDI,(int)unaff_ESI);
      iVar2 = lua_pcallk(0,0,extraout_ECX,0);
      if (iVar2 != 0) {
        LuaBindings::LuaCheckStatus((int)unaff_EDI,unaff_ESI,unaff_EBP);
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


bool __thiscall LuaMission::AddPlayer(LuaMission *this,ulong param_1,int param_2,bool param_3)

{
  int *piVar1;
  double *pdVar2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  char *unaff_EBP;
  lua_State *unaff_ESI;
  int unaff_EDI;
  
  if (*(char *)((int)&this[1]._padding_ + 1) == '\0') {
    Setup(this);
  }
  if (this[1]._padding_ != 0) {
    lua_getglobal();
    iVar5 = this[1]._padding_;
    uVar4 = lua_type();
    if (uVar4 == 6) {
      pdVar2 = *(double **)(iVar5 + 8);
      *pdVar2 = (double)(int)param_1;
      *(double **)(iVar5 + 8) = pdVar2 + 1;
      iVar5 = this[1]._padding_;
      pdVar2 = *(double **)(iVar5 + 8);
      *pdVar2 = (double)param_2;
      *(double **)(iVar5 + 8) = pdVar2 + 1;
      iVar5 = this[1]._padding_;
      puVar3 = *(uint **)(iVar5 + 8);
      *puVar3 = (uint)param_3;
      puVar3[1] = 0x7ff7a501;
      piVar1 = (int *)(iVar5 + 8);
      *piVar1 = *piVar1 + 8;
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


void __thiscall LuaMission::DeletePlayer(LuaMission *this,ulong param_1)

{
  double *pdVar1;
  uint uVar2;
  int iVar3;
  undefined4 extraout_ECX;
  char *unaff_EBP;
  int unaff_ESI;
  lua_State *unaff_EDI;
  
  if (this[1]._padding_ != 0) {
    lua_getglobal();
    iVar3 = this[1]._padding_;
    uVar2 = lua_type();
    if (uVar2 == 6) {
      pdVar1 = *(double **)(iVar3 + 8);
      *pdVar1 = (double)(int)param_1;
      *(double **)(iVar3 + 8) = pdVar1 + 1;
      iVar3 = lua_pcallk(0,0,extraout_ECX,0);
      if (iVar3 != 0) {
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


EjectKillRetCodes __thiscall LuaMission::PlayerEjected(LuaMission *this,int param_1)

{
  EjectKillRetCodes EVar1;
  uint uVar2;
  int iVar3;
  undefined4 extraout_ECX;
  lua_State *unaff_EBX;
  char *unaff_ESI;
  lua_State *unaff_EDI;
  
  if (this[1]._padding_ == 0) {
    EVar1 = DoEjectPilot;
  }
  else {
    EVar1 = DoEjectPilot;
    lua_getglobal();
    uVar2 = lua_type();
    if (uVar2 == 6) {
      LuaBindings::PushHandle(unaff_EDI,(int)unaff_EBX);
      iVar3 = lua_pcallk(1,0,extraout_ECX,0);
      if (iVar3 != 0) {
        LuaBindings::LuaCheckStatus((int)unaff_EDI,unaff_EBX,unaff_ESI);
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


EjectKillRetCodes __thiscall LuaMission::ObjectKilled(LuaMission *this,int param_1,int param_2)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  EjectKillRetCodes EVar4;
  undefined4 extraout_ECX;
  lua_State *unaff_EBX;
  char *unaff_ESI;
  lua_State *unaff_EDI;
  
  if (*(char *)((int)&this[1]._padding_ + 2) == '\0') {
    BZ1Helper::DeadObject((BZ1Helper *)this,param_1);
  }
  if (this[1]._padding_ == 0) {
    bVar1 = IsPlayer(param_1);
    EVar4 = DoEjectPilot;
    if (!bVar1) {
      EVar4 = DLLHandled;
    }
  }
  else {
    bVar1 = IsPlayer(param_1);
    EVar4 = DLLHandled;
    if (bVar1) {
      EVar4 = DoEjectPilot;
    }
    lua_getglobal();
    uVar2 = lua_type();
    if (uVar2 == 6) {
      LuaBindings::PushHandle(unaff_EBX,(int)unaff_EDI);
      LuaBindings::PushHandle(unaff_EBX,(int)unaff_EDI);
      iVar3 = lua_pcallk(1,0,extraout_ECX,0);
      if (iVar3 != 0) {
        LuaBindings::LuaCheckStatus((int)unaff_EBX,unaff_EDI,unaff_ESI);
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


EjectKillRetCodes __thiscall LuaMission::ObjectSniped(LuaMission *this,int param_1,int param_2)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined4 extraout_ECX;
  lua_State *unaff_EBX;
  EjectKillRetCodes EVar4;
  char *unaff_ESI;
  lua_State *unaff_EDI;
  
  if (this[1]._padding_ == 0) {
    bVar1 = IsPlayer(param_1);
    EVar4 = bVar1 + DLLHandled;
  }
  else {
    bVar1 = IsPlayer(param_1);
    EVar4 = bVar1 + DLLHandled;
    lua_getglobal();
    uVar2 = lua_type();
    if (uVar2 == 6) {
      LuaBindings::PushHandle(unaff_EDI,(int)unaff_EBX);
      LuaBindings::PushHandle(unaff_EDI,(int)unaff_EBX);
      iVar3 = lua_pcallk(1,0,extraout_ECX,0);
      if (iVar3 != 0) {
        LuaBindings::LuaCheckStatus((int)unaff_EDI,unaff_EBX,unaff_ESI);
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


char * __thiscall LuaMission::GetNextRandomVehicleODF(LuaMission *this,int param_1)

{
  double *pdVar1;
  char *pcVar2;
  uint uVar3;
  int iVar4;
  undefined4 extraout_ECX;
  char *unaff_EBP;
  lua_State *unaff_ESI;
  int unaff_EDI;
  
  if (this[1]._padding_ == 0) {
    pcVar2 = GetPlayerODF(param_1,Randomize_None);
  }
  else {
    lua_getglobal();
    iVar4 = this[1]._padding_;
    uVar3 = lua_type();
    if (uVar3 == 6) {
      pdVar1 = *(double **)(iVar4 + 8);
      *pdVar1 = (double)param_1;
      *(double **)(iVar4 + 8) = pdVar1 + 1;
      iVar4 = lua_pcallk(1,0,extraout_ECX,0);
      if (iVar4 != 0) {
        LuaBindings::LuaCheckStatus(unaff_EDI,unaff_ESI,unaff_EBP);
      }
    }
    else {
      lua_settop();
    }
    pcVar2 = GetPlayerODF(param_1,Randomize_None);
  }
  return pcVar2;
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
  
  if (*(char *)((int)&this[1]._padding_ + 2) == '\0') {
    BZ1Helper::Execute((BZ1Helper *)this);
  }
  if (*(char *)((int)&this[1]._padding_ + 1) == '\0') {
    Setup(this);
  }
  this[1]._padding_ = this[1]._padding_ + 1;
  if (this[1]._padding_ != 0) {
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
  
  if (this[1]._padding_ != 0) {
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


void __thiscall LuaMission::ProcessCommand(LuaMission *this,ulong param_1)

{
  double *pdVar1;
  uint uVar2;
  int iVar3;
  undefined4 extraout_ECX;
  char *unaff_EBP;
  int unaff_ESI;
  lua_State *unaff_EDI;
  
  if (this[1]._padding_ != 0) {
    lua_getglobal();
    iVar3 = this[1]._padding_;
    uVar2 = lua_type();
    if (uVar2 == 6) {
      pdVar1 = *(double **)(iVar3 + 8);
      *pdVar1 = (double)(int)param_1;
      *(double **)(iVar3 + 8) = pdVar1 + 1;
      iVar3 = lua_pcallk(0,0,extraout_ECX,0);
      if (iVar3 != 0) {
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


void __thiscall LuaMission::SetRandomSeed(LuaMission *this,ulong param_1)

{
  double *pdVar1;
  uint uVar2;
  int iVar3;
  undefined4 extraout_ECX;
  char *unaff_EBP;
  int unaff_ESI;
  lua_State *unaff_EDI;
  
  if (this[1]._padding_ != 0) {
    lua_getglobal();
    iVar3 = this[1]._padding_;
    uVar2 = lua_type();
    if (uVar2 == 6) {
      pdVar1 = *(double **)(iVar3 + 8);
      *pdVar1 = (double)(int)param_1;
      *(double **)(iVar3 + 8) = pdVar1 + 1;
      iVar3 = lua_pcallk(0,0,extraout_ECX,0);
      if (iVar3 != 0) {
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


PreTeleportReturnCodes __thiscall LuaMission::PreTeleport(LuaMission *this,int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 extraout_ECX;
  lua_State *unaff_EBX;
  char *unaff_ESI;
  lua_State *unaff_EDI;
  PreTeleportReturnCodes PVar3;
  
  PVar3 = PreTeleport_DEFAULT;
  if (this[1]._padding_ == 0) {
    PVar3 = PreTeleport_DEFAULT;
  }
  else {
    lua_getglobal();
    uVar1 = lua_type();
    if (uVar1 == 6) {
      LuaBindings::PushHandle(unaff_EBX,(int)unaff_EDI);
      LuaBindings::PushHandle(unaff_EBX,(int)unaff_EDI);
      iVar2 = lua_pcallk(1,0,extraout_ECX,0);
      if (iVar2 != 0) {
        LuaBindings::LuaCheckStatus((int)unaff_EBX,unaff_EDI,unaff_ESI);
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

