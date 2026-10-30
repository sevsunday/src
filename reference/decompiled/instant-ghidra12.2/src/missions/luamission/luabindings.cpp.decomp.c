// Reconstructed by Ghidra from Instant.dll + Instant.pdb
// Original source file: /e:/github/vsr_dll_source/missions/luamission/luabindings.cpp
// Functions are ordered by original source line. This is decompiler
// output, not the author's source: names/types come from the PDB,
// local variable names and control flow are reconstructed.


// ---------------------------------------------------------------------
// LuaPrint  @ 4fc509f2  lines 8-33


/* WARNING: Function: _chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl LuaPrint(lua_State *param_1)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 extraout_ECX;
  int iVar3;
  undefined4 unaff_ESI;
  uint uVar4;
  undefined4 unaff_EDI;
  uint uVar5;
  uint local_1018;
  int local_1014;
  char local_1010 [4100];
  uint local_c;
  undefined4 uStack_8;
  
  uStack_8 = 0x4fc509ff;
  local_c = __security_cookie ^ (uint)(local_1010 + 0x100c);
  uVar5 = 0;
  iVar3 = (*(int *)(param_1 + 8) - **(int **)(param_1 + 0x10)) + -8 >> 3;
  lua_getglobal();
  local_1014 = 1;
  if (0 < iVar3) {
    do {
      puVar1 = *(undefined4 **)(param_1 + 8);
      *puVar1 = puVar1[-2];
      puVar1[1] = puVar1[-1];
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
      lua_pushvalue();
      lua_callk(1,extraout_ECX,0);
      pvVar2 = (void *)lua_tolstring(&local_1018);
      if (pvVar2 == (void *)0x0) {
                    /* WARNING: Subroutine does not return */
        luaL_error(param_1,"\'tostring\' must return a string to \'print\'",
                   (double)CONCAT44(unaff_ESI,unaff_EDI));
      }
      if ((1 < local_1014) && (uVar5 < 0xfff)) {
        local_1010[uVar5] = '\t';
        uVar5 = uVar5 + 1;
      }
      uVar4 = local_1018;
      if (0xfff - uVar5 < local_1018) {
        uVar4 = 0xfff - uVar5;
      }
      local_1018 = uVar4;
      memcpy(local_1010 + uVar5,pvVar2,uVar4);
      uVar5 = uVar5 + uVar4;
      lua_settop();
      local_1014 = local_1014 + 1;
    } while (local_1014 <= iVar3);
    if (0xfff < uVar5) {
                    /* WARNING: Subroutine does not return */
      __report_rangecheckfailure();
    }
  }
  local_1010[uVar5] = '\0';
  PrintConsoleMessage(local_1010);
  return 0;
}


// ---------------------------------------------------------------------
// LuaPanic  @ 4fc509ba  lines 37-45


int __cdecl LuaPanic(lua_State *param_1)

{
  lua_tolstring((undefined4 *)0x0);
  FormatConsoleMessage("Lua panic: %s");
  FormatToMessagesBox("Lua panic: %s",0xffff0000);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::LuaCheckStatus  @ 4fc4f143  lines 49-62


bool __cdecl LuaBindings::LuaCheckStatus(int param_1,lua_State *param_2,char *param_3)

{
  char *in_EDX;
  
  lua_tolstring((undefined4 *)0x0);
  FormatConsoleMessage(in_EDX);
  FormatToMessagesBox(in_EDX,0xffff0000);
  return false;
}


// ---------------------------------------------------------------------
// LuaBindings::PushHandle  @ 4fc5099c  lines 66-71


void __cdecl LuaBindings::PushHandle(lua_State *param_1,int param_2)

{
  int *piVar1;
  int in_ECX;
  int in_EDX;
  
  piVar1 = *(int **)(in_ECX + 8);
  if (in_EDX == 0) {
    piVar1[1] = 0x7ff7a500;
  }
  else {
    *piVar1 = in_EDX;
    piVar1[1] = 0x7ff7a502;
  }
  *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + 8;
  return;
}


// ---------------------------------------------------------------------
// LuaBindings::GetHandle  @ 4fc4a36c  lines 76-88


int __cdecl LuaBindings::GetHandle(lua_State *param_1)

{
  int iVar1;
  char *pcVar2;
  lua_State *unaff_EBP;
  int unaff_retaddr;
  
  iVar1 = lua_isnumber();
  if (iVar1 == 0) {
    pcVar2 = (char *)luaL_checklstring((undefined4 *)0x0);
    ::GetHandle(pcVar2);
  }
  else {
    iVar1 = lua_tointegerx((undefined4 *)0x0);
    ::GetHandle(iVar1);
  }
  PushHandle(unaff_EBP,unaff_retaddr);
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetHandle  @ 4fc44c12  lines 92-94


int __cdecl LuaBindings::GetHandle(lua_State *param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = luaL_testudata();
  return uVar1;
}


// ---------------------------------------------------------------------
// LuaBindings::RequireHandle  @ 4fc44bef  lines 98-103


int __cdecl LuaBindings::RequireHandle(lua_State *param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = lua_type();
  iVar2 = 0;
  if (uVar1 != 0) {
    iVar2 = luaL_checkudata("Handle");
  }
  return iVar2;
}


// ---------------------------------------------------------------------
// LuaBindings::Handle_ToString  @ 4fc4b146  lines 107-113


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl LuaBindings::Handle_ToString(lua_State *param_1)

{
  lua_State *unaff_ESI;
  int in_stack_ffffffac;
  char local_50 [68];
  uint local_c;
  undefined1 auStack_8 [4];
  
  local_c = __security_cookie ^ (uint)(auStack_8 + 4);
  RequireHandle(unaff_ESI,in_stack_ffffffac);
  sprintf_s<64>((char (*) [64])local_50,"%08x");
  lua_pushstring();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::Handle_ToInteger  @ 4fc49419  lines 117-122


int __cdecl LuaBindings::Handle_ToInteger(lua_State *param_1)

{
  char *_Str;
  int unaff_EBP;
  lua_State *extraout_var;
  lua_State *plVar1;
  
  _Str = (char *)luaL_checklstring((undefined4 *)0x0);
  plVar1 = extraout_var;
  atoi(_Str);
  PushHandle(plVar1,unaff_EBP);
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetVector  @ 4fc44be1  lines 127-129


Vector * __cdecl LuaBindings::GetVector(lua_State *param_1,int param_2)

{
  Vector *pVVar1;
  
  pVVar1 = (Vector *)luaL_testudata();
  return pVVar1;
}


// ---------------------------------------------------------------------
// LuaBindings::RequireVector  @ 4fc44bd3  lines 133-135


Vector * __cdecl LuaBindings::RequireVector(lua_State *param_1,int param_2)

{
  Vector *pVVar1;
  
  pVVar1 = (Vector *)luaL_checkudata("Vector");
  return pVVar1;
}


// ---------------------------------------------------------------------
// LuaBindings::NewVector  @ 4fc44ba2  lines 139-144


Vector * __cdecl LuaBindings::NewVector(lua_State *param_1)

{
  Vector *pVVar1;
  
  pVVar1 = (Vector *)lua_newuserdata();
  lua_getfield();
  lua_setmetatable();
  return pVVar1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetMatrix  @ 4fc44b94  lines 149-151


Matrix * __cdecl LuaBindings::GetMatrix(lua_State *param_1,int param_2)

{
  Matrix *pMVar1;
  
  pMVar1 = (Matrix *)luaL_testudata();
  return pMVar1;
}


// ---------------------------------------------------------------------
// LuaBindings::RequireMatrix  @ 4fc44b86  lines 155-157


Matrix * __cdecl LuaBindings::RequireMatrix(lua_State *param_1,int param_2)

{
  Matrix *pMVar1;
  
  pMVar1 = (Matrix *)luaL_checkudata("Matrix");
  return pMVar1;
}


// ---------------------------------------------------------------------
// LuaBindings::NewMatrix  @ 4fc4580a  lines 161-166


Matrix * __cdecl LuaBindings::NewMatrix(lua_State *param_1)

{
  Matrix *pMVar1;
  
  pMVar1 = (Matrix *)lua_newuserdata();
  lua_getfield();
  lua_setmetatable();
  return pMVar1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetQuaternion  @ 4fc44b78  lines 171-173


Quaternion * __cdecl LuaBindings::GetQuaternion(lua_State *param_1,int param_2)

{
  Quaternion *pQVar1;
  
  pQVar1 = (Quaternion *)luaL_testudata();
  return pQVar1;
}


// ---------------------------------------------------------------------
// LuaBindings::RequireQuaternion  @ 4fc44b6a  lines 177-179


Quaternion * __cdecl LuaBindings::RequireQuaternion(lua_State *param_1,int param_2)

{
  Quaternion *pQVar1;
  
  pQVar1 = (Quaternion *)luaL_checkudata("Quaternion");
  return pQVar1;
}


// ---------------------------------------------------------------------
// LuaBindings::NewQuaternion  @ 4fc44b39  lines 183-188


Quaternion * __cdecl LuaBindings::NewQuaternion(lua_State *param_1)

{
  Quaternion *pQVar1;
  
  pQVar1 = (Quaternion *)lua_newuserdata();
  lua_getfield();
  lua_setmetatable();
  return pQVar1;
}


// ---------------------------------------------------------------------
// LuaBindings::SetQuaternion  @ 4fc4fe42  lines 192-199


int __cdecl LuaBindings::SetQuaternion(lua_State *param_1)

{
  uint uVar1;
  Quaternion *pQVar2;
  lua_State *unaff_EDI;
  double in_XMM0_Qa;
  undefined8 uVar3;
  double dVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  float fVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  
  uVar1 = lua_type();
  if ((int)uVar1 < 1) {
    in_XMM0_Qa = __real_3ff0000000000000;
  }
  else {
    luaL_checknumber();
  }
  uVar1 = lua_type();
  uVar3 = 0;
  if ((int)uVar1 < 1) {
    uVar5 = 0;
    uVar8 = 0;
  }
  else {
    luaL_checknumber();
    uVar5 = (undefined4)uVar3;
    uVar8 = (undefined4)((ulonglong)uVar3 >> 0x20);
  }
  dVar4 = 0.0;
  uVar1 = lua_type();
  if ((int)uVar1 < 1) {
    uVar6 = 0;
    uVar9 = 0;
  }
  else {
    luaL_checknumber();
    uVar6 = SUB84(dVar4,0);
    uVar9 = (undefined4)((ulonglong)dVar4 >> 0x20);
    dVar4 = 0.0;
  }
  fVar7 = (float)(double)CONCAT44(uVar9,uVar6);
  uVar1 = lua_type();
  if (0 < (int)uVar1) {
    luaL_checknumber();
    fVar7 = (float)(double)CONCAT44(uVar9,uVar6);
  }
  pQVar2 = NewQuaternion(unaff_EDI);
  pQVar2->s = (float)in_XMM0_Qa;
  (pQVar2->v).x = (float)(double)CONCAT44(uVar8,uVar5);
  (pQVar2->v).y = fVar7;
  (pQVar2->v).z = (float)dVar4;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::luaL_optboolean  @ 4fc4940e  lines 203-205


bool __cdecl LuaBindings::luaL_optboolean(lua_State *param_1,int param_2,int param_3)

{
  int iVar1;
  
  iVar1 = lua_toboolean();
  return iVar1 != 0;
}


// ---------------------------------------------------------------------
// LuaBindings::Vector_Index  @ 4fc50925  lines 210-229


int __cdecl LuaBindings::Vector_Index(lua_State *param_1)

{
  uint uVar1;
  int iVar2;
  uint unaff_ESI;
  char *unaff_EDI;
  
  uVar1 = luaL_testudata();
  if (((uVar1 == 0) || (iVar2 = luaL_checklstring((undefined4 *)0x0), iVar2 == 0)) ||
     ((uVar1 = Hash(unaff_EDI,unaff_ESI), uVar1 != 0xfc0c4ef4 &&
      ((uVar1 != 0xfd0c5087 && (uVar1 != 0xff0c53ad)))))) {
    iVar2 = 0;
  }
  else {
    lua_pushnumber();
    iVar2 = 1;
  }
  return iVar2;
}


// ---------------------------------------------------------------------
// LuaBindings::Vector_NewIndex  @ 4fc4a518  lines 234-253


int __cdecl LuaBindings::Vector_NewIndex(lua_State *param_1)

{
  float *pfVar1;
  int iVar2;
  uint uVar3;
  uint unaff_ESI;
  char *unaff_EDI;
  undefined4 in_XMM0_Da;
  undefined4 in_XMM0_Db;
  
  pfVar1 = (float *)luaL_testudata();
  if (pfVar1 != (float *)0x0) {
    iVar2 = luaL_checklstring((undefined4 *)0x0);
    if (iVar2 != 0) {
      uVar3 = Hash(unaff_EDI,unaff_ESI);
      if (uVar3 == 0xfc0c4ef4) {
        luaL_checknumber();
        pfVar1[1] = (float)(double)CONCAT44(in_XMM0_Db,in_XMM0_Da);
      }
      else if (uVar3 == 0xfd0c5087) {
        luaL_checknumber();
        *pfVar1 = (float)(double)CONCAT44(in_XMM0_Db,in_XMM0_Da);
      }
      else if (uVar3 == 0xff0c53ad) {
        luaL_checknumber();
        pfVar1[2] = (float)(double)CONCAT44(in_XMM0_Db,in_XMM0_Da);
      }
    }
  }
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::Vector_Neg  @ 4fc45a1e  lines 257-261


int __cdecl LuaBindings::Vector_Neg(lua_State *param_1)

{
  uint *puVar1;
  Vector *pVVar2;
  lua_State *unaff_EDI;
  float fVar3;
  float fVar4;
  float fVar5;
  
  puVar1 = (uint *)luaL_checkudata("Vector");
  fVar3 = (float)(*puVar1 ^ __xmm_80000000800000008000000080000000);
  fVar4 = (float)(puVar1[1] ^ __xmm_80000000800000008000000080000000);
  fVar5 = (float)(puVar1[2] ^ __xmm_80000000800000008000000080000000);
  pVVar2 = NewVector(unaff_EDI);
  pVVar2->x = fVar3;
  pVVar2->y = fVar4;
  pVVar2->z = fVar5;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::Vector_Add  @ 4fc47f71  lines 265-270


int __cdecl LuaBindings::Vector_Add(lua_State *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float *pfVar7;
  float *pfVar8;
  Vector *pVVar9;
  lua_State *unaff_EDI;
  
  pfVar7 = (float *)luaL_checkudata("Vector");
  pfVar8 = (float *)luaL_checkudata("Vector");
  fVar1 = *pfVar7;
  fVar2 = *pfVar8;
  fVar3 = pfVar8[1];
  fVar4 = pfVar7[1];
  fVar5 = pfVar8[2];
  fVar6 = pfVar7[2];
  pVVar9 = NewVector(unaff_EDI);
  pVVar9->x = fVar2 + fVar1;
  pVVar9->y = fVar3 + fVar4;
  pVVar9->z = fVar5 + fVar6;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::Vector_Sub  @ 4fc4861c  lines 274-279


int __cdecl LuaBindings::Vector_Sub(lua_State *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float *pfVar7;
  float *pfVar8;
  Vector *pVVar9;
  lua_State *unaff_EDI;
  
  pfVar7 = (float *)luaL_checkudata("Vector");
  pfVar8 = (float *)luaL_checkudata("Vector");
  fVar1 = *pfVar7;
  fVar2 = *pfVar8;
  fVar3 = pfVar7[1];
  fVar4 = pfVar8[1];
  fVar5 = pfVar7[2];
  fVar6 = pfVar8[2];
  pVVar9 = NewVector(unaff_EDI);
  pVVar9->x = fVar1 - fVar2;
  pVVar9->y = fVar3 - fVar4;
  pVVar9->z = fVar5 - fVar6;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::Vector_Mul  @ 4fc4f6c8  lines 283-305


int __cdecl LuaBindings::Vector_Mul(lua_State *param_1)

{
  int iVar1;
  float *pfVar2;
  Vector *pVVar3;
  float *pfVar4;
  lua_State *unaff_EDI;
  undefined4 in_XMM0_Da;
  undefined4 in_XMM0_Db;
  float local_14;
  float local_10;
  float local_c;
  
  iVar1 = lua_isnumber();
  if (iVar1 == 0) {
    iVar1 = lua_isnumber();
    pfVar2 = (float *)luaL_checkudata("Vector");
    if (iVar1 == 0) {
      pfVar4 = (float *)luaL_checkudata("Vector");
      local_14 = *pfVar4 * *pfVar2;
      local_10 = pfVar4[1] * pfVar2[1];
      local_c = pfVar4[2] * pfVar2[2];
    }
    else {
      lua_tonumberx((undefined4 *)0x0);
      local_c = (float)(double)CONCAT44(in_XMM0_Db,in_XMM0_Da);
      local_14 = *pfVar2 * local_c;
      local_10 = pfVar2[1] * local_c;
      local_c = pfVar2[2] * local_c;
    }
    pVVar3 = NewVector(unaff_EDI);
  }
  else {
    lua_tonumberx((undefined4 *)0x0);
    local_c = (float)(double)CONCAT44(in_XMM0_Db,in_XMM0_Da);
    pfVar2 = (float *)luaL_checkudata("Vector");
    local_14 = *pfVar2 * local_c;
    local_10 = pfVar2[1] * local_c;
    local_c = pfVar2[2] * local_c;
    pVVar3 = NewVector(unaff_EDI);
  }
  pVVar3->x = local_14;
  pVVar3->y = local_10;
  pVVar3->z = local_c;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::Vector_Div  @ 4fc48269  lines 309-331


int __cdecl LuaBindings::Vector_Div(lua_State *param_1)

{
  int iVar1;
  float *pfVar2;
  Vector *pVVar3;
  float *pfVar4;
  lua_State *unaff_EDI;
  undefined4 in_XMM0_Da;
  undefined4 in_XMM0_Db;
  float local_14;
  float local_10;
  float local_c;
  
  iVar1 = lua_isnumber();
  if (iVar1 == 0) {
    iVar1 = lua_isnumber();
    pfVar2 = (float *)luaL_checkudata("Vector");
    if (iVar1 == 0) {
      pfVar4 = (float *)luaL_checkudata("Vector");
      local_14 = *pfVar2 / *pfVar4;
      local_10 = pfVar2[1] / pfVar4[1];
      local_c = pfVar2[2] / pfVar4[2];
    }
    else {
      lua_tonumberx((undefined4 *)0x0);
      local_c = (float)(double)CONCAT44(in_XMM0_Db,in_XMM0_Da);
      local_14 = *pfVar2 / local_c;
      local_10 = pfVar2[1] / local_c;
      local_c = pfVar2[2] / local_c;
    }
    pVVar3 = NewVector(unaff_EDI);
  }
  else {
    lua_tonumberx((undefined4 *)0x0);
    local_c = (float)(double)CONCAT44(in_XMM0_Db,in_XMM0_Da);
    pfVar2 = (float *)luaL_checkudata("Vector");
    local_14 = local_c / *pfVar2;
    local_10 = local_c / pfVar2[1];
    local_c = local_c / pfVar2[2];
    pVVar3 = NewVector(unaff_EDI);
  }
  pVVar3->x = local_14;
  pVVar3->y = local_10;
  pVVar3->z = local_c;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::Vector_Eq  @ 4fc4f8b1  lines 335-340


int __cdecl LuaBindings::Vector_Eq(lua_State *param_1)

{
  undefined4 *puVar1;
  float *pfVar2;
  float *pfVar3;
  undefined4 uVar4;
  
  pfVar2 = (float *)luaL_checkudata("Vector");
  pfVar3 = (float *)luaL_checkudata("Vector");
  if (((*pfVar2 == *pfVar3) && (pfVar2[1] == pfVar3[1])) && (pfVar2[2] == pfVar3[2])) {
    uVar4 = 1;
  }
  else {
    uVar4 = 0;
  }
  puVar1 = *(undefined4 **)(param_1 + 8);
  *puVar1 = uVar4;
  puVar1[1] = 0x7ff7a501;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::Vector_ToString  @ 4fc4b9f6  lines 344-350


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl LuaBindings::Vector_ToString(lua_State *param_1)

{
  char local_50 [68];
  uint local_c;
  
  local_c = __security_cookie ^ (uint)local_50;
  luaL_checkudata("Vector");
  memset(local_50,0,0x40);
  sprintf_s<64>((char (*) [64])local_50,"{x=%f, y=%f, z=%f}");
  lua_pushstring();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::Matrix_Index  @ 4fc4f9bb  lines 355-411


int __cdecl LuaBindings::Matrix_Index(lua_State *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float *pfVar4;
  int iVar5;
  uint uVar6;
  Vector *pVVar7;
  uint unaff_ESI;
  lua_State *unaff_EDI;
  
  pfVar4 = (float *)luaL_testudata();
  iVar5 = luaL_checklstring((undefined4 *)0x0);
  if (iVar5 == 0) {
    return 0;
  }
  uVar6 = Hash((char *)unaff_EDI,unaff_ESI);
  if (uVar6 < 0xb96c4116) {
    if (uVar6 != 0xb96c4115) {
      if (uVar6 < 0x44e771bd) {
        if (uVar6 == 0x44e771bc) {
          pfVar4 = pfVar4 + 0xc;
        }
        else {
          if (((uVar6 == 0x21f7b0fc) || (uVar6 == 0x22f7b28f)) || (uVar6 == 0x24f7b5b5))
          goto LAB_4fc4fa91;
          if (uVar6 != 0x43430b20) {
            return 0;
          }
          pfVar4 = pfVar4 + 4;
        }
      }
      else if (uVar6 != 0x78e32de5) {
        if ((uVar6 != 0xb66c3c5c) && (uVar6 != 0xb86c3f82)) {
          return 0;
        }
        goto LAB_4fc4fa91;
      }
LAB_4fc4fa3b:
      fVar1 = *pfVar4;
      fVar2 = pfVar4[1];
      fVar3 = pfVar4[2];
      pVVar7 = NewVector(unaff_EDI);
      pVVar7->x = fVar1;
      pVVar7->y = fVar2;
      pVVar7->z = fVar3;
      return 1;
    }
  }
  else if (((uVar6 != 0xc5a81bb4) && (uVar6 != 0xc6a81d47)) && (uVar6 != 0xc8a8206d)) {
    if (uVar6 == 0xe179dbd8) {
      pfVar4 = pfVar4 + 8;
      goto LAB_4fc4fa3b;
    }
    if (((uVar6 != 0xebf98a60) && (uVar6 != 0xecf98bf3)) && (uVar6 != 0xeef98f19)) {
      return 0;
    }
  }
LAB_4fc4fa91:
  lua_pushnumber();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::Matrix_NewIndex  @ 4fc4dff9  lines 416-478


int __cdecl LuaBindings::Matrix_NewIndex(lua_State *param_1)

{
  float *pfVar1;
  int iVar2;
  uint uVar3;
  float *pfVar4;
  float *pfVar5;
  uint unaff_ESI;
  char *unaff_EDI;
  undefined4 in_XMM0_Da;
  undefined4 in_XMM0_Db;
  float local_14;
  float local_10;
  float local_c;
  
  pfVar1 = (float *)luaL_testudata();
  if (pfVar1 == (float *)0x0) {
    return 0;
  }
  iVar2 = luaL_checklstring((undefined4 *)0x0);
  if (iVar2 == 0) {
    return 0;
  }
  uVar3 = Hash(unaff_EDI,unaff_ESI);
  if (uVar3 < 0xb96c4116) {
    if (uVar3 == 0xb96c4115) {
      luaL_checknumber();
      pfVar1[1] = (float)(double)CONCAT44(in_XMM0_Db,in_XMM0_Da);
      return 0;
    }
    if (uVar3 < 0x44e771bd) {
      if (uVar3 == 0x44e771bc) {
        pfVar5 = (float *)luaL_testudata();
        if (pfVar5 == (float *)0x0) {
          return 0;
        }
        pfVar4 = &local_14;
        local_14 = *pfVar5;
        pfVar1 = pfVar1 + 0xc;
        local_10 = pfVar5[1];
        local_c = pfVar5[2];
      }
      else {
        if (uVar3 == 0x21f7b0fc) {
          luaL_checknumber();
          pfVar1[5] = (float)(double)CONCAT44(in_XMM0_Db,in_XMM0_Da);
          return 0;
        }
        if (uVar3 == 0x22f7b28f) {
          luaL_checknumber();
          pfVar1[4] = (float)(double)CONCAT44(in_XMM0_Db,in_XMM0_Da);
          return 0;
        }
        if (uVar3 == 0x24f7b5b5) {
          luaL_checknumber();
          pfVar1[6] = (float)(double)CONCAT44(in_XMM0_Db,in_XMM0_Da);
          return 0;
        }
        if (uVar3 != 0x43430b20) {
          return 0;
        }
        pfVar4 = (float *)luaL_testudata();
        if (pfVar4 == (float *)0x0) {
          return 0;
        }
        pfVar1 = pfVar1 + 4;
      }
    }
    else {
      if (uVar3 != 0x78e32de5) {
        if (uVar3 == 0xb66c3c5c) {
          luaL_checknumber();
          pfVar1[2] = (float)(double)CONCAT44(in_XMM0_Db,in_XMM0_Da);
          return 0;
        }
        if (uVar3 == 0xb86c3f82) {
          luaL_checknumber();
          *pfVar1 = (float)(double)CONCAT44(in_XMM0_Db,in_XMM0_Da);
          return 0;
        }
        return 0;
      }
      pfVar4 = (float *)luaL_testudata();
      if (pfVar4 == (float *)0x0) {
        return 0;
      }
    }
  }
  else {
    if (uVar3 == 0xc5a81bb4) {
      luaL_checknumber();
      pfVar1[9] = (float)(double)CONCAT44(in_XMM0_Db,in_XMM0_Da);
      return 0;
    }
    if (uVar3 == 0xc6a81d47) {
      luaL_checknumber();
      pfVar1[8] = (float)(double)CONCAT44(in_XMM0_Db,in_XMM0_Da);
      return 0;
    }
    if (uVar3 == 0xc8a8206d) {
      luaL_checknumber();
      pfVar1[10] = (float)(double)CONCAT44(in_XMM0_Db,in_XMM0_Da);
      return 0;
    }
    if (uVar3 != 0xe179dbd8) {
      if (uVar3 == 0xebf98a60) {
        luaL_checknumber();
        pfVar1[0xd] = (float)(double)CONCAT44(in_XMM0_Db,in_XMM0_Da);
        return 0;
      }
      if (uVar3 == 0xecf98bf3) {
        luaL_checknumber();
        pfVar1[0xc] = (float)(double)CONCAT44(in_XMM0_Db,in_XMM0_Da);
        return 0;
      }
      if (uVar3 == 0xeef98f19) {
        luaL_checknumber();
        pfVar1[0xe] = (float)(double)CONCAT44(in_XMM0_Db,in_XMM0_Da);
        return 0;
      }
      return 0;
    }
    pfVar4 = (float *)luaL_testudata();
    if (pfVar4 == (float *)0x0) {
      return 0;
    }
    pfVar1 = pfVar1 + 8;
  }
  *pfVar1 = *pfVar4;
  pfVar1[1] = pfVar4[1];
  pfVar1[2] = pfVar4[2];
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::Matrix_Mul  @ 4fc44c76  lines 482-500


int __cdecl LuaBindings::Matrix_Mul(lua_State *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  uint uVar4;
  Matrix *pMVar5;
  Vector *pVVar6;
  int iVar7;
  Matrix *unaff_ESI;
  float *pfVar8;
  Matrix *unaff_EDI;
  float local_88 [33];
  
  uVar4 = luaL_testudata();
  if (uVar4 == 0) {
LAB_4fc44d1e:
    iVar7 = 0;
  }
  else {
    pMVar5 = (Matrix *)luaL_testudata();
    if (pMVar5 == (Matrix *)0x0) {
      pVVar6 = (Vector *)luaL_testudata();
      if (pVVar6 == (Vector *)0x0) goto LAB_4fc44d1e;
      pVVar6 = ::Vector_Transform(pVVar6,unaff_EDI,&unaff_ESI->right);
      fVar1 = pVVar6->x;
      fVar2 = pVVar6->y;
      fVar3 = pVVar6->z;
      pVVar6 = NewVector((lua_State *)unaff_EDI);
      pVVar6->x = fVar1;
      pVVar6->y = fVar2;
      pVVar6->z = fVar3;
    }
    else {
      pMVar5 = Matrix_Multiply(pMVar5,unaff_EDI,unaff_ESI);
      pfVar8 = local_88;
      for (iVar7 = 0x10; iVar7 != 0; iVar7 = iVar7 + -1) {
        *pfVar8 = (pMVar5->right).x;
        pMVar5 = (Matrix *)&(pMVar5->right).y;
        pfVar8 = pfVar8 + 1;
      }
      pMVar5 = NewMatrix((lua_State *)unaff_EDI);
      pfVar8 = local_88;
      for (iVar7 = 0x10; iVar7 != 0; iVar7 = iVar7 + -1) {
        (pMVar5->right).x = *pfVar8;
        pfVar8 = pfVar8 + 1;
        pMVar5 = (Matrix *)&(pMVar5->right).y;
      }
    }
    iVar7 = 1;
  }
  return iVar7;
}


// ---------------------------------------------------------------------
// LuaBindings::Matrix_ToString  @ 4fc4ab25  lines 504-517


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl LuaBindings::Matrix_ToString(lua_State *param_1)

{
  uint uVar1;
  undefined1 auStack_114 [4];
  char local_110 [260];
  uint local_c;
  
  local_c = __security_cookie ^ (uint)auStack_114;
  uVar1 = luaL_testudata();
  if (uVar1 != 0) {
    sprintf_s<256>((char (*) [256])local_110,
                   "{right_x=%f, right_y=%f, right_z=%f, up_x=%f, up_y=%f, up_z=%f, front_x=%f, front_y=%f, front_z=%f, posit_x=%f, posit_y=%f, posit_z=%f}"
                  );
    lua_pushstring();
  }
  return (uint)(uVar1 != 0);
}


// ---------------------------------------------------------------------
// LuaBindings::Quaternion_Index  @ 4fc4973f  lines 522-544


int __cdecl LuaBindings::Quaternion_Index(lua_State *param_1)

{
  uint uVar1;
  int iVar2;
  uint unaff_ESI;
  char *unaff_EDI;
  
  uVar1 = luaL_testudata();
  if (((uVar1 == 0) || (iVar2 = luaL_checklstring((undefined4 *)0x0), iVar2 == 0)) ||
     ((uVar1 = Hash(unaff_EDI,unaff_ESI), uVar1 != 0xf60c4582 &&
      (((uVar1 != 0xfc0c4ef4 && (uVar1 != 0xfd0c5087)) && (uVar1 != 0xff0c53ad)))))) {
    iVar2 = 0;
  }
  else {
    lua_pushnumber();
    iVar2 = 1;
  }
  return iVar2;
}


// ---------------------------------------------------------------------
// LuaBindings::Quaternion_NewIndex  @ 4fc4f574  lines 549-571


int __cdecl LuaBindings::Quaternion_NewIndex(lua_State *param_1)

{
  float *pfVar1;
  int iVar2;
  uint uVar3;
  uint unaff_ESI;
  char *unaff_EDI;
  undefined4 in_XMM0_Da;
  undefined4 in_XMM0_Db;
  
  pfVar1 = (float *)luaL_testudata();
  if (pfVar1 != (float *)0x0) {
    iVar2 = luaL_checklstring((undefined4 *)0x0);
    if (iVar2 != 0) {
      uVar3 = Hash(unaff_EDI,unaff_ESI);
      if (uVar3 == 0xf60c4582) {
        luaL_checknumber();
        *pfVar1 = (float)(double)CONCAT44(in_XMM0_Db,in_XMM0_Da);
      }
      else if (uVar3 == 0xfc0c4ef4) {
        luaL_checknumber();
        pfVar1[2] = (float)(double)CONCAT44(in_XMM0_Db,in_XMM0_Da);
      }
      else if (uVar3 == 0xfd0c5087) {
        luaL_checknumber();
        pfVar1[1] = (float)(double)CONCAT44(in_XMM0_Db,in_XMM0_Da);
      }
      else if (uVar3 == 0xff0c53ad) {
        luaL_checknumber();
        pfVar1[3] = (float)(double)CONCAT44(in_XMM0_Db,in_XMM0_Da);
      }
    }
  }
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::Quaternion_Mul  @ 4fc50167  lines 575-588


int __cdecl LuaBindings::Quaternion_Mul(lua_State *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float *pfVar9;
  float *pfVar10;
  Quaternion *pQVar11;
  lua_State *unaff_EDI;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  
  pfVar9 = (float *)luaL_testudata();
  if ((pfVar9 == (float *)0x0) || (pfVar10 = (float *)luaL_testudata(), pfVar10 == (float *)0x0)) {
    return 0;
  }
  fVar1 = pfVar9[1];
  fVar2 = pfVar10[1];
  fVar3 = *pfVar9;
  fVar15 = (fVar1 + pfVar9[3]) * (fVar2 + pfVar10[2]);
  fVar4 = *pfVar10;
  fVar16 = (fVar1 - pfVar9[3]) * (fVar2 - pfVar10[2]);
  fVar17 = fVar16 + fVar15;
  fVar14 = (fVar3 + pfVar9[2]) * (fVar4 - pfVar10[3]);
  fVar20 = (fVar3 - pfVar9[2]) * (pfVar10[3] + fVar4);
  fVar5 = pfVar10[1];
  fVar12 = (fVar17 + fVar14 + fVar20) * __real_3f000000;
  fVar15 = fVar15 - fVar16;
  fVar16 = pfVar10[3];
  fVar6 = pfVar10[2];
  fVar7 = *pfVar10;
  fVar18 = ((fVar17 - fVar14) - fVar20) * __real_3f000000;
  fVar13 = ((fVar15 + fVar14) - fVar20) * __real_3f000000;
  fVar19 = ((fVar15 - fVar14) + fVar20) * __real_3f000000;
  fVar15 = pfVar9[2];
  fVar14 = pfVar9[3];
  fVar17 = pfVar9[2];
  fVar20 = pfVar10[2];
  fVar8 = pfVar10[3];
  pQVar11 = NewQuaternion(unaff_EDI);
  pQVar11->s = (fVar14 - fVar17) * (fVar20 - fVar8) - fVar18;
  (pQVar11->v).x = (fVar3 + fVar1) * (fVar4 + fVar5) - fVar12;
  (pQVar11->v).y = (fVar3 - fVar1) * (fVar16 + fVar6) + fVar13;
  (pQVar11->v).z = (fVar15 + fVar14) * (fVar7 - fVar2) + fVar19;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::Quaternion_ToString  @ 4fc4eb69  lines 592-598


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl LuaBindings::Quaternion_ToString(lua_State *param_1)

{
  char local_50 [68];
  uint local_c;
  
  local_c = __security_cookie ^ (uint)local_50;
  luaL_checkudata("Quaternion");
  memset(local_50,0,0x40);
  sprintf_s<64>((char (*) [64])local_50,"{s=%f, x=%f, y=%f, z=%f}");
  lua_pushstring();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::SetVector  @ 4fc45a93  lines 602-608


int __cdecl LuaBindings::SetVector(lua_State *param_1)

{
  uint uVar1;
  Vector *pVVar2;
  lua_State *unaff_EDI;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  float fVar9;
  
  uVar1 = lua_type();
  uVar3 = 0;
  uVar6 = 0;
  if ((int)uVar1 < 1) {
    uVar3 = 0;
    uVar6 = 0;
  }
  else {
    luaL_checknumber();
  }
  uVar7 = 0;
  uVar4 = 0;
  uVar1 = lua_type();
  if ((int)uVar1 < 1) {
    uVar5 = uVar4;
    uVar8 = uVar7;
    uVar4 = 0;
    uVar7 = 0;
  }
  else {
    luaL_checknumber();
    uVar5 = 0;
    uVar8 = 0;
  }
  fVar9 = (float)(double)CONCAT44(uVar7,uVar4);
  uVar1 = lua_type();
  if (0 < (int)uVar1) {
    luaL_checknumber();
    fVar9 = (float)(double)CONCAT44(uVar7,uVar4);
  }
  pVVar2 = NewVector(unaff_EDI);
  pVVar2->x = (float)(double)CONCAT44(uVar6,uVar3);
  pVVar2->y = fVar9;
  pVVar2->z = (float)(double)CONCAT44(uVar8,uVar5);
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::DotProduct  @ 4fc48832  lines 612-617


int __cdecl LuaBindings::DotProduct(lua_State *param_1)

{
  luaL_checkudata("Vector");
  luaL_checkudata("Vector");
  lua_pushnumber();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::CrossProduct  @ 4fc4b0f2  lines 621-626


int __cdecl LuaBindings::CrossProduct(lua_State *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  Vector *pVVar4;
  lua_State *unaff_EDI;
  char *pcVar5;
  char *pcVar6;
  
  pcVar6 = "Vector";
  luaL_checkudata("Vector");
  pcVar5 = "Vector";
  pVVar4 = (Vector *)luaL_checkudata("Vector");
  pVVar4 = Cross_Product(pVVar4,(Vector *)pcVar5,(Vector *)pcVar6);
  fVar1 = pVVar4->x;
  fVar2 = pVVar4->y;
  fVar3 = pVVar4->z;
  pVVar4 = NewVector(unaff_EDI);
  pVVar4->x = fVar1;
  pVVar4->y = fVar2;
  pVVar4->z = fVar3;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::Normalize  @ 4fc4dbfc  lines 630-634


int __cdecl LuaBindings::Normalize(lua_State *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  Vector *pVVar4;
  Vector *unaff_ESI;
  Vector *unaff_EDI;
  
  luaL_checkudata("Vector");
  pVVar4 = Normalize_Vector(unaff_EDI,unaff_ESI);
  fVar1 = pVVar4->x;
  fVar2 = pVVar4->y;
  fVar3 = pVVar4->z;
  pVVar4 = NewVector((lua_State *)unaff_EDI);
  pVVar4->x = fVar1;
  pVVar4->y = fVar2;
  pVVar4->z = fVar3;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::Length  @ 4fc4f4e5  lines 638-642


int __cdecl LuaBindings::Length(lua_State *param_1)

{
  Vector *pVVar1;
  
  pVVar1 = (Vector *)luaL_checkudata("Vector");
  GetLength3D(*pVVar1);
  lua_pushnumber();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::LengthSquared  @ 4fc5002c  lines 646-650


int __cdecl LuaBindings::LengthSquared(lua_State *param_1)

{
  luaL_checkudata("Vector");
  lua_pushnumber();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::Distance2D  @ 4fc4bafd  lines 654-659


int __cdecl LuaBindings::Distance2D(lua_State *param_1)

{
  luaL_checkudata("Vector");
  luaL_checkudata("Vector");
  __libm_sse2_sqrt_precise();
  lua_pushnumber();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::Distance2DSquared  @ 4fc4c90e  lines 663-668


int __cdecl LuaBindings::Distance2DSquared(lua_State *param_1)

{
  luaL_checkudata("Vector");
  luaL_checkudata("Vector");
  lua_pushnumber();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::Distance3D  @ 4fc4d9b2  lines 672-686


int __cdecl LuaBindings::Distance3D(lua_State *param_1)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int unaff_ESI;
  lua_State *unaff_EDI;
  Vector local_20;
  Vector local_14;
  
  uVar2 = luaL_testudata();
  if (uVar2 == 0) {
    iVar3 = RequireHandle(unaff_EDI,unaff_ESI);
    iVar4 = RequireHandle(unaff_EDI,unaff_ESI);
    bVar1 = ::IsAround(iVar3);
    if ((!bVar1) || (bVar1 = ::IsAround(iVar4), !bVar1)) goto LAB_4fc4daa5;
    ::GetPosition(iVar4,&local_20);
    ::GetPosition(iVar3,&local_14);
  }
  else {
    luaL_checkudata("Vector");
    luaL_checkudata("Vector");
  }
  __libm_sse2_sqrt_precise();
LAB_4fc4daa5:
  lua_pushnumber();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::Distance3DSquared  @ 4fc4e973  lines 690-704


int __cdecl LuaBindings::Distance3DSquared(lua_State *param_1)

{
  uint uVar1;
  Vector *unaff_ESI;
  Vector *unaff_EDI;
  
  uVar1 = luaL_testudata();
  if (uVar1 == 0) {
    RequireHandle((lua_State *)unaff_EDI,(int)unaff_ESI);
    RequireHandle((lua_State *)unaff_EDI,(int)unaff_ESI);
    GetDistance3DSquared((int)unaff_EDI,(int)unaff_ESI);
  }
  else {
    luaL_checkudata("Vector");
    luaL_checkudata("Vector");
    GetDistance3DSquared(unaff_EDI,unaff_ESI);
  }
  lua_pushnumber();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::SetMatrix  @ 4fc50581  lines 708-737


int __cdecl LuaBindings::SetMatrix(lua_State *param_1)

{
  Vector VVar1;
  Vector VVar2;
  Vector VVar3;
  Vector VVar4;
  Vector *pVVar5;
  Vector *pVVar6;
  Vector *pVVar7;
  Vector *pVVar8;
  Matrix *pMVar9;
  uint uVar10;
  int iVar11;
  float *pfVar12;
  lua_State *unaff_EDI;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  undefined4 uVar19;
  undefined4 uVar20;
  undefined4 uVar21;
  undefined4 uVar22;
  undefined4 uVar23;
  undefined4 uVar24;
  undefined4 uVar25;
  undefined4 uVar26;
  undefined4 uVar27;
  undefined4 uVar28;
  undefined4 uVar29;
  undefined4 uVar30;
  undefined4 uVar31;
  undefined4 uVar32;
  undefined4 uVar33;
  undefined4 uVar34;
  undefined4 uVar35;
  undefined4 uVar36;
  float fVar37;
  float local_88 [16];
  Matrix local_48;
  
  pVVar5 = (Vector *)luaL_testudata();
  if (pVVar5 == (Vector *)0x0) {
    uVar10 = lua_type();
    uVar13 = 0;
    uVar25 = 0;
    if ((int)uVar10 < 1) {
      uVar13 = 0;
      uVar25 = 0;
    }
    else {
      luaL_checknumber();
    }
    uVar26 = 0;
    uVar14 = 0;
    uVar10 = lua_type();
    if ((int)uVar10 < 1) {
      uVar15 = uVar14;
      uVar27 = uVar26;
      uVar14 = 0;
      uVar26 = 0;
    }
    else {
      luaL_checknumber();
      uVar15 = 0;
      uVar27 = 0;
    }
    uVar10 = lua_type();
    if ((int)uVar10 < 1) {
      uVar16 = uVar15;
      uVar28 = uVar27;
      uVar15 = 0;
      uVar27 = 0;
    }
    else {
      luaL_checknumber();
      uVar16 = 0;
      uVar28 = 0;
    }
    uVar10 = lua_type();
    if ((int)uVar10 < 1) {
      uVar17 = uVar16;
      uVar29 = uVar28;
      uVar16 = 0;
      uVar28 = 0;
    }
    else {
      luaL_checknumber();
      uVar17 = 0;
      uVar29 = 0;
    }
    uVar10 = lua_type();
    if ((int)uVar10 < 1) {
      uVar18 = uVar17;
      uVar30 = uVar29;
      uVar17 = 0;
      uVar29 = 0;
    }
    else {
      luaL_checknumber();
      uVar18 = 0;
      uVar30 = 0;
    }
    uVar10 = lua_type();
    if ((int)uVar10 < 1) {
      uVar19 = uVar18;
      uVar31 = uVar30;
      uVar18 = 0;
      uVar30 = 0;
    }
    else {
      luaL_checknumber();
      uVar19 = 0;
      uVar31 = 0;
    }
    uVar10 = lua_type();
    if ((int)uVar10 < 1) {
      uVar20 = uVar19;
      uVar32 = uVar31;
      uVar19 = 0;
      uVar31 = 0;
    }
    else {
      luaL_checknumber();
      uVar20 = 0;
      uVar32 = 0;
    }
    uVar10 = lua_type();
    if ((int)uVar10 < 1) {
      uVar21 = uVar20;
      uVar33 = uVar32;
      uVar20 = 0;
      uVar32 = 0;
    }
    else {
      luaL_checknumber();
      uVar21 = 0;
      uVar33 = 0;
    }
    uVar10 = lua_type();
    if ((int)uVar10 < 1) {
      uVar22 = uVar21;
      uVar34 = uVar33;
      uVar21 = 0;
      uVar33 = 0;
    }
    else {
      luaL_checknumber();
      uVar22 = 0;
      uVar34 = 0;
    }
    uVar10 = lua_type();
    if ((int)uVar10 < 1) {
      uVar23 = uVar22;
      uVar35 = uVar34;
      uVar22 = 0;
      uVar34 = 0;
    }
    else {
      luaL_checknumber();
      uVar23 = 0;
      uVar35 = 0;
    }
    uVar10 = lua_type();
    if ((int)uVar10 < 1) {
      uVar24 = uVar23;
      uVar36 = uVar35;
      uVar23 = 0;
      uVar35 = 0;
    }
    else {
      luaL_checknumber();
      uVar24 = 0;
      uVar36 = 0;
    }
    fVar37 = (float)(double)CONCAT44(uVar35,uVar23);
    uVar10 = lua_type();
    if (0 < (int)uVar10) {
      luaL_checknumber();
      fVar37 = (float)(double)CONCAT44(uVar35,uVar23);
    }
    VVar1.y = (float)(double)CONCAT44(uVar26,uVar14);
    VVar1.x = (float)(double)CONCAT44(uVar25,uVar13);
    VVar1.z = (float)(double)CONCAT44(uVar27,uVar15);
    VVar2.y = (float)(double)CONCAT44(uVar29,uVar17);
    VVar2.x = (float)(double)CONCAT44(uVar28,uVar16);
    VVar2.z = (float)(double)CONCAT44(uVar30,uVar18);
    VVar3.y = (float)(double)CONCAT44(uVar32,uVar20);
    VVar3.x = (float)(double)CONCAT44(uVar31,uVar19);
    VVar3.z = (float)(double)CONCAT44(uVar33,uVar21);
    VVar4.y = fVar37;
    VVar4.x = (float)(double)CONCAT44(uVar34,uVar22);
    VVar4.z = (float)(double)CONCAT44(uVar36,uVar24);
    pMVar9 = Matrix::Matrix(&local_48,VVar1,VVar2,VVar3,VVar4);
    pfVar12 = local_88;
    for (iVar11 = 0x10; iVar11 != 0; iVar11 = iVar11 + -1) {
      *pfVar12 = (pMVar9->right).x;
      pMVar9 = (Matrix *)&(pMVar9->right).y;
      pfVar12 = pfVar12 + 1;
    }
  }
  else {
    pVVar6 = (Vector *)luaL_checkudata("Vector");
    pVVar7 = (Vector *)luaL_checkudata("Vector");
    pVVar8 = (Vector *)luaL_checkudata("Vector");
    pMVar9 = Matrix::Matrix(&local_48,*pVVar5,*pVVar6,*pVVar7,*pVVar8);
    pfVar12 = local_88;
    for (iVar11 = 0x10; iVar11 != 0; iVar11 = iVar11 + -1) {
      *pfVar12 = (pMVar9->right).x;
      pMVar9 = (Matrix *)&(pMVar9->right).y;
      pfVar12 = pfVar12 + 1;
    }
  }
  pMVar9 = NewMatrix(unaff_EDI);
  pfVar12 = local_88;
  for (iVar11 = 0x10; iVar11 != 0; iVar11 = iVar11 + -1) {
    (pMVar9->right).x = *pfVar12;
    pfVar12 = pfVar12 + 1;
    pMVar9 = (Matrix *)&(pMVar9->right).y;
  }
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::BuildAxisRotationMatrix  @ 4fc4c2d1  lines 740-757


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __cdecl LuaBindings::BuildAxisRotationMatrix(lua_State *param_1)

{
  uint uVar1;
  Matrix *pMVar2;
  int iVar3;
  Matrix *unaff_ESI;
  Quaternion *pQVar4;
  Vector *unaff_EDI;
  Quaternion local_48 [4];
  
  uVar1 = lua_type();
  if (0 < (int)uVar1) {
    luaL_checknumber();
  }
  uVar1 = luaL_testudata();
  if (uVar1 == 0) {
    uVar1 = lua_type();
    if (0 < (int)uVar1) {
      luaL_checknumber();
    }
    uVar1 = lua_type();
    if (0 < (int)uVar1) {
      luaL_checknumber();
    }
    uVar1 = lua_type();
    if (0 < (int)uVar1) {
      luaL_checknumber();
    }
  }
  __libm_sse2_sin_precise();
  __libm_sse2_cos_precise();
  ::QuatPos_to_Matrix(local_48,unaff_EDI,unaff_ESI);
  pMVar2 = NewMatrix((lua_State *)unaff_EDI);
  pQVar4 = local_48;
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    (pMVar2->right).x = pQVar4->s;
    pQVar4 = (Quaternion *)&pQVar4->v;
    pMVar2 = (Matrix *)&(pMVar2->right).y;
  }
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::BuildPositionRotationMatrix  @ 4fc4c981  lines 760-779


int __cdecl LuaBindings::BuildPositionRotationMatrix(lua_State *param_1)

{
  uint uVar1;
  Matrix *pMVar2;
  int iVar3;
  Vector *unaff_ESI;
  float *pfVar4;
  lua_State *unaff_EDI;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  float local_88 [33];
  
  uVar1 = lua_type();
  uVar5 = 0;
  uVar8 = 0;
  if ((int)uVar1 < 1) {
    uVar5 = 0;
    uVar8 = 0;
  }
  else {
    luaL_checknumber();
  }
  uVar9 = 0;
  uVar6 = 0;
  uVar1 = lua_type();
  if ((int)uVar1 < 1) {
    uVar7 = uVar6;
    uVar10 = uVar9;
    uVar6 = 0;
    uVar9 = 0;
  }
  else {
    luaL_checknumber();
    uVar7 = 0;
    uVar10 = 0;
  }
  uVar1 = lua_type();
  if (0 < (int)uVar1) {
    luaL_checknumber();
  }
  uVar1 = luaL_testudata();
  if (uVar1 == 0) {
    uVar1 = lua_type();
    if (0 < (int)uVar1) {
      luaL_checknumber();
    }
    uVar1 = lua_type();
    if (0 < (int)uVar1) {
      luaL_checknumber();
    }
    uVar1 = lua_type();
    if (0 < (int)uVar1) {
      luaL_checknumber();
    }
  }
  pMVar2 = Build_Position_Rotation_Matrix
                     ((Matrix *)(float)(double)CONCAT44(uVar8,uVar5),
                      (float)(double)CONCAT44(uVar9,uVar6),(float)(double)CONCAT44(uVar10,uVar7),
                      (float)unaff_EDI,unaff_ESI);
  pfVar4 = local_88;
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pfVar4 = (pMVar2->right).x;
    pMVar2 = (Matrix *)&(pMVar2->right).y;
    pfVar4 = pfVar4 + 1;
  }
  pMVar2 = NewMatrix(unaff_EDI);
  pfVar4 = local_88;
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    (pMVar2->right).x = *pfVar4;
    pfVar4 = pfVar4 + 1;
    pMVar2 = (Matrix *)&(pMVar2->right).y;
  }
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::BuildOrthogonalMatrix  @ 4fc4522f  lines 787-796


int __cdecl LuaBindings::BuildOrthogonalMatrix(lua_State *param_1)

{
  Matrix *pMVar1;
  Matrix *pMVar2;
  int iVar3;
  Vector *unaff_ESI;
  float *pfVar4;
  Vector *unaff_EDI;
  Vector local_94;
  float local_88 [33];
  
  luaL_testudata();
  pMVar1 = (Matrix *)luaL_testudata();
  pMVar2 = (Matrix *)&z_axis;
  if (pMVar1 != (Matrix *)0x0) {
    pMVar2 = pMVar1;
  }
  local_94.x = 0.0;
  local_94.y = 0.0;
  local_94.z = 0.0;
  pMVar2 = Build_Orthogonal_Matrix(pMVar2,&local_94,unaff_EDI,unaff_ESI);
  pfVar4 = local_88;
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pfVar4 = (pMVar2->right).x;
    pMVar2 = (Matrix *)&(pMVar2->right).y;
    pfVar4 = pfVar4 + 1;
  }
  pMVar2 = NewMatrix((lua_State *)unaff_EDI);
  pfVar4 = local_88;
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    (pMVar2->right).x = *pfVar4;
    pfVar4 = pfVar4 + 1;
    pMVar2 = (Matrix *)&(pMVar2->right).y;
  }
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::BuildDirectionalMatrix  @ 4fc48b11  lines 799-808


int __cdecl LuaBindings::BuildDirectionalMatrix(lua_State *param_1)

{
  Matrix *pMVar1;
  Matrix *pMVar2;
  int iVar3;
  Vector *unaff_ESI;
  float *pfVar4;
  Vector *unaff_EDI;
  float local_88 [33];
  
  luaL_testudata();
  pMVar1 = (Matrix *)luaL_testudata();
  pMVar2 = (Matrix *)&z_axis;
  if (pMVar1 != (Matrix *)0x0) {
    pMVar2 = pMVar1;
  }
  pMVar2 = Build_Directinal_Matrix(pMVar2,unaff_EDI,unaff_ESI);
  pfVar4 = local_88;
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pfVar4 = (pMVar2->right).x;
    pMVar2 = (Matrix *)&(pMVar2->right).y;
    pfVar4 = pfVar4 + 1;
  }
  pMVar2 = NewMatrix((lua_State *)unaff_EDI);
  pfVar4 = local_88;
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    (pMVar2->right).x = *pfVar4;
    pfVar4 = pfVar4 + 1;
    pMVar2 = (Matrix *)&(pMVar2->right).y;
  }
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::Interpolate_Matrix  @ 4fc4a49d  lines 812-818


int __cdecl LuaBindings::Interpolate_Matrix(lua_State *param_1)

{
  Matrix *pMVar1;
  int iVar2;
  float unaff_ESI;
  float *pfVar3;
  Matrix *unaff_EDI;
  undefined4 in_XMM0_Da;
  undefined4 in_XMM0_Db;
  float local_88 [33];
  
  luaL_checkudata("Matrix");
  pMVar1 = (Matrix *)luaL_checkudata("Matrix");
  luaL_checknumber();
  pMVar1 = ::Interpolate_Matrix
                     (pMVar1,(Matrix *)(float)(double)CONCAT44(in_XMM0_Db,in_XMM0_Da),unaff_EDI,
                      unaff_ESI);
  pfVar3 = local_88;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *pfVar3 = (pMVar1->right).x;
    pMVar1 = (Matrix *)&(pMVar1->right).y;
    pfVar3 = pfVar3 + 1;
  }
  pMVar1 = NewMatrix((lua_State *)unaff_EDI);
  pfVar3 = local_88;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    (pMVar1->right).x = *pfVar3;
    pfVar3 = pfVar3 + 1;
    pMVar1 = (Matrix *)&(pMVar1->right).y;
  }
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::Interpolate_Quaternion  @ 4fc476e8  lines 823-829


int __cdecl LuaBindings::Interpolate_Quaternion(lua_State *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  Quaternion *pQVar5;
  float unaff_ESI;
  Quaternion *unaff_EDI;
  undefined4 in_XMM0_Da;
  undefined4 in_XMM0_Db;
  
  luaL_checkudata("Quaternion");
  pQVar5 = (Quaternion *)luaL_checkudata("Quaternion");
  luaL_checknumber();
  pQVar5 = ::Interpolate_Quaternion
                     (pQVar5,(Quaternion *)(float)(double)CONCAT44(in_XMM0_Db,in_XMM0_Da),unaff_EDI,
                      unaff_ESI);
  fVar1 = pQVar5->s;
  fVar2 = (pQVar5->v).x;
  fVar3 = (pQVar5->v).y;
  fVar4 = (pQVar5->v).z;
  pQVar5 = NewQuaternion((lua_State *)unaff_EDI);
  pQVar5->s = fVar1;
  (pQVar5->v).x = fVar2;
  (pQVar5->v).y = fVar3;
  (pQVar5->v).z = fVar4;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::Normalize_Quaternion  @ 4fc4fbcc  lines 833-837


int __cdecl LuaBindings::Normalize_Quaternion(lua_State *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  Quaternion *pQVar5;
  Quaternion *unaff_ESI;
  Quaternion *unaff_EDI;
  
  luaL_checkudata("Quaternion");
  pQVar5 = ::Normalize_Quaternion(unaff_EDI,unaff_ESI);
  fVar1 = pQVar5->s;
  fVar2 = (pQVar5->v).x;
  fVar3 = (pQVar5->v).y;
  fVar4 = (pQVar5->v).z;
  pQVar5 = NewQuaternion((lua_State *)unaff_EDI);
  pQVar5->s = fVar1;
  (pQVar5->v).x = fVar2;
  (pQVar5->v).y = fVar3;
  (pQVar5->v).z = fVar4;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::Matrix_to_QuatPos  @ 4fc4741f  lines 841-849


int __cdecl LuaBindings::Matrix_to_QuatPos(lua_State *param_1)

{
  Quaternion *pQVar1;
  Vector *pVVar2;
  Vector *unaff_EDI;
  char *pcVar3;
  float local_20;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  float local_10;
  float fStack_c;
  float fStack_8;
  
  pcVar3 = "Matrix";
  luaL_checkudata("Matrix");
  ::Matrix_to_QuatPos((Matrix *)&local_10,(Quaternion *)pcVar3,unaff_EDI);
  pQVar1 = NewQuaternion((lua_State *)unaff_EDI);
  pQVar1->s = local_20;
  (pQVar1->v).x = fStack_1c;
  (pQVar1->v).y = fStack_18;
  (pQVar1->v).z = fStack_14;
  pVVar2 = NewVector((lua_State *)unaff_EDI);
  pVVar2->x = local_10;
  pVVar2->y = fStack_c;
  pVVar2->z = fStack_8;
  return 2;
}


// ---------------------------------------------------------------------
// LuaBindings::Matrix_to_Quaternion  @ 4fc4dcbc  lines 852-859


int __cdecl LuaBindings::Matrix_to_Quaternion(lua_State *param_1)

{
  Quaternion *pQVar1;
  Vector *unaff_EDI;
  char *pcVar2;
  float local_20;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  undefined1 local_10 [12];
  
  pcVar2 = "Matrix";
  luaL_checkudata("Matrix");
  ::Matrix_to_QuatPos((Matrix *)local_10,(Quaternion *)pcVar2,unaff_EDI);
  pQVar1 = NewQuaternion((lua_State *)unaff_EDI);
  pQVar1->s = local_20;
  (pQVar1->v).x = fStack_1c;
  (pQVar1->v).y = fStack_18;
  (pQVar1->v).z = fStack_14;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::QuatPos_to_Matrix  @ 4fc4915e  lines 863-881


int __cdecl LuaBindings::QuatPos_to_Matrix(lua_State *param_1)

{
  uint uVar1;
  Matrix *pMVar2;
  int iVar3;
  Matrix *unaff_ESI;
  Quaternion *pQVar4;
  Vector *unaff_EDI;
  Quaternion local_48 [4];
  
  luaL_checkudata("Quaternion");
  uVar1 = luaL_testudata();
  if (uVar1 == 0) {
    uVar1 = lua_type();
    if (0 < (int)uVar1) {
      luaL_checknumber();
    }
    uVar1 = lua_type();
    if (0 < (int)uVar1) {
      luaL_checknumber();
    }
    uVar1 = lua_type();
    if (0 < (int)uVar1) {
      luaL_checknumber();
    }
  }
  ::QuatPos_to_Matrix(local_48,unaff_EDI,unaff_ESI);
  pMVar2 = NewMatrix((lua_State *)unaff_EDI);
  pQVar4 = local_48;
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    (pMVar2->right).x = pQVar4->s;
    pQVar4 = (Quaternion *)&pQVar4->v;
    pMVar2 = (Matrix *)&(pMVar2->right).y;
  }
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::Vector_Transform  @ 4fc456f1  lines 885-902


int __cdecl LuaBindings::Vector_Transform(lua_State *param_1)

{
  float *pfVar1;
  uint uVar2;
  Vector *pVVar3;
  Vector *unaff_ESI;
  Matrix *unaff_EDI;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  float fVar8;
  float local_30;
  Vector local_28 [3];
  
  luaL_checkudata("Matrix");
  pfVar1 = (float *)luaL_testudata();
  if (pfVar1 == (float *)0x0) {
    uVar2 = lua_type();
    uVar4 = 0;
    uVar6 = 0;
    if ((int)uVar2 < 1) {
      uVar4 = 0;
      uVar6 = 0;
    }
    else {
      luaL_checknumber();
    }
    uVar7 = 0;
    uVar5 = 0;
    local_30 = (float)(double)CONCAT44(uVar6,uVar4);
    uVar2 = lua_type();
    if ((int)uVar2 < 1) {
      uVar4 = uVar5;
      uVar6 = uVar7;
      uVar5 = 0;
      uVar7 = 0;
    }
    else {
      luaL_checknumber();
      uVar4 = 0;
      uVar6 = 0;
    }
    fVar8 = (float)(double)CONCAT44(uVar7,uVar5);
    uVar2 = lua_type();
    local_28[0].y = fVar8;
    if (0 < (int)uVar2) {
      luaL_checknumber();
      local_28[0].y = (float)(double)CONCAT44(uVar7,uVar5);
    }
    local_28[0].z = (float)(double)CONCAT44(uVar6,uVar4);
  }
  else {
    local_30 = *pfVar1;
    local_28[0].y = pfVar1[1];
    local_28[0].z = pfVar1[2];
  }
  local_28[0].x = local_30;
  pVVar3 = ::Vector_Transform(local_28,unaff_EDI,unaff_ESI);
  local_28[0].x = pVVar3->x;
  local_28[0].y = pVVar3->y;
  local_28[0].z = pVVar3->z;
  pVVar3 = NewVector((lua_State *)unaff_EDI);
  pVVar3->x = local_28[0].x;
  pVVar3->y = local_28[0].y;
  pVVar3->z = local_28[0].z;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::Vector_TransformInv  @ 4fc4b8dd  lines 906-923


int __cdecl LuaBindings::Vector_TransformInv(lua_State *param_1)

{
  float *pfVar1;
  uint uVar2;
  Vector *pVVar3;
  Vector *unaff_ESI;
  Matrix *unaff_EDI;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  float fVar8;
  float local_30;
  Vector local_28 [3];
  
  luaL_checkudata("Matrix");
  pfVar1 = (float *)luaL_testudata();
  if (pfVar1 == (float *)0x0) {
    uVar2 = lua_type();
    uVar4 = 0;
    uVar6 = 0;
    if ((int)uVar2 < 1) {
      uVar4 = 0;
      uVar6 = 0;
    }
    else {
      luaL_checknumber();
    }
    uVar7 = 0;
    uVar5 = 0;
    local_30 = (float)(double)CONCAT44(uVar6,uVar4);
    uVar2 = lua_type();
    if ((int)uVar2 < 1) {
      uVar4 = uVar5;
      uVar6 = uVar7;
      uVar5 = 0;
      uVar7 = 0;
    }
    else {
      luaL_checknumber();
      uVar4 = 0;
      uVar6 = 0;
    }
    fVar8 = (float)(double)CONCAT44(uVar7,uVar5);
    uVar2 = lua_type();
    local_28[0].y = fVar8;
    if (0 < (int)uVar2) {
      luaL_checknumber();
      local_28[0].y = (float)(double)CONCAT44(uVar7,uVar5);
    }
    local_28[0].z = (float)(double)CONCAT44(uVar6,uVar4);
  }
  else {
    local_30 = *pfVar1;
    local_28[0].y = pfVar1[1];
    local_28[0].z = pfVar1[2];
  }
  local_28[0].x = local_30;
  pVVar3 = ::Vector_TransformInv(local_28,unaff_EDI,unaff_ESI);
  local_28[0].x = pVVar3->x;
  local_28[0].y = pVVar3->y;
  local_28[0].z = pVVar3->z;
  pVVar3 = NewVector((lua_State *)unaff_EDI);
  pVVar3->x = local_28[0].x;
  pVVar3->y = local_28[0].y;
  pVVar3->z = local_28[0].z;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::Vector_Rotate  @ 4fc46e54  lines 927-944


int __cdecl LuaBindings::Vector_Rotate(lua_State *param_1)

{
  float *pfVar1;
  uint uVar2;
  Vector *pVVar3;
  Vector *unaff_ESI;
  Matrix *unaff_EDI;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  float fVar8;
  float local_30;
  Vector local_28 [3];
  
  luaL_checkudata("Matrix");
  pfVar1 = (float *)luaL_testudata();
  if (pfVar1 == (float *)0x0) {
    uVar2 = lua_type();
    uVar4 = 0;
    uVar6 = 0;
    if ((int)uVar2 < 1) {
      uVar4 = 0;
      uVar6 = 0;
    }
    else {
      luaL_checknumber();
    }
    uVar7 = 0;
    uVar5 = 0;
    local_30 = (float)(double)CONCAT44(uVar6,uVar4);
    uVar2 = lua_type();
    if ((int)uVar2 < 1) {
      uVar4 = uVar5;
      uVar6 = uVar7;
      uVar5 = 0;
      uVar7 = 0;
    }
    else {
      luaL_checknumber();
      uVar4 = 0;
      uVar6 = 0;
    }
    fVar8 = (float)(double)CONCAT44(uVar7,uVar5);
    uVar2 = lua_type();
    local_28[0].y = fVar8;
    if (0 < (int)uVar2) {
      luaL_checknumber();
      local_28[0].y = (float)(double)CONCAT44(uVar7,uVar5);
    }
    local_28[0].z = (float)(double)CONCAT44(uVar6,uVar4);
  }
  else {
    local_30 = *pfVar1;
    local_28[0].y = pfVar1[1];
    local_28[0].z = pfVar1[2];
  }
  local_28[0].x = local_30;
  pVVar3 = ::Vector_Rotate(local_28,unaff_EDI,unaff_ESI);
  local_28[0].x = pVVar3->x;
  local_28[0].y = pVVar3->y;
  local_28[0].z = pVVar3->z;
  pVVar3 = NewVector((lua_State *)unaff_EDI);
  pVVar3->x = local_28[0].x;
  pVVar3->y = local_28[0].y;
  pVVar3->z = local_28[0].z;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::Vector_RotateInv  @ 4fc46c4e  lines 948-965


int __cdecl LuaBindings::Vector_RotateInv(lua_State *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float *pfVar10;
  float *pfVar11;
  uint uVar12;
  Vector *pVVar13;
  lua_State *unaff_EDI;
  float fVar14;
  double dVar15;
  double dVar16;
  float fVar17;
  float local_1c;
  
  pfVar10 = (float *)luaL_checkudata("Matrix");
  pfVar11 = (float *)luaL_testudata();
  if (pfVar11 == (float *)0x0) {
    uVar12 = lua_type();
    dVar15 = 0.0;
    if ((int)uVar12 < 1) {
      dVar15 = 0.0;
    }
    else {
      luaL_checknumber();
    }
    dVar16 = 0.0;
    local_1c = (float)dVar15;
    uVar12 = lua_type();
    if ((int)uVar12 < 1) {
      dVar15 = dVar16;
      dVar16 = 0.0;
    }
    else {
      luaL_checknumber();
      dVar15 = 0.0;
    }
    fVar17 = (float)dVar16;
    uVar12 = lua_type();
    if (0 < (int)uVar12) {
      luaL_checknumber();
      fVar17 = (float)dVar16;
    }
    fVar14 = (float)dVar15;
  }
  else {
    local_1c = *pfVar11;
    fVar17 = pfVar11[1];
    fVar14 = pfVar11[2];
  }
  fVar1 = pfVar10[1];
  fVar2 = *pfVar10;
  fVar3 = pfVar10[2];
  fVar4 = pfVar10[4];
  fVar5 = pfVar10[5];
  fVar6 = pfVar10[6];
  fVar7 = pfVar10[8];
  fVar8 = pfVar10[9];
  fVar9 = pfVar10[10];
  pVVar13 = NewVector(unaff_EDI);
  pVVar13->x = fVar1 * fVar17 + fVar2 * local_1c + fVar3 * fVar14;
  pVVar13->y = fVar4 * local_1c + fVar5 * fVar17 + fVar6 * fVar14;
  pVVar13->z = fVar7 * local_1c + fVar8 * fVar17 + fVar9 * fVar14;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::Matrix_Inverse  @ 4fc50116  lines 969-973


int __cdecl LuaBindings::Matrix_Inverse(lua_State *param_1)

{
  Matrix *pMVar1;
  int iVar2;
  Matrix *unaff_ESI;
  float *pfVar3;
  Matrix *unaff_EDI;
  float local_88 [33];
  
  luaL_checkudata("Matrix");
  pMVar1 = ::Matrix_Inverse(unaff_EDI,unaff_ESI);
  pfVar3 = local_88;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *pfVar3 = (pMVar1->right).x;
    pMVar1 = (Matrix *)&(pMVar1->right).y;
    pfVar3 = pfVar3 + 1;
  }
  pMVar1 = NewMatrix((lua_State *)unaff_EDI);
  pfVar3 = local_88;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    (pMVar1->right).x = *pfVar3;
    pfVar3 = pfVar3 + 1;
    pMVar1 = (Matrix *)&(pMVar1->right).y;
  }
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::Build_Yaw_Matrix  @ 4fc4d30b  lines 977-994


int __cdecl LuaBindings::Build_Yaw_Matrix(lua_State *param_1)

{
  uint uVar1;
  Matrix *pMVar2;
  int iVar3;
  Vector *unaff_ESI;
  float *pfVar4;
  lua_State *unaff_EDI;
  undefined4 in_XMM0_Da;
  undefined4 in_XMM0_Db;
  float local_88 [33];
  
  uVar1 = lua_type();
  if ((int)uVar1 < 1) {
    in_XMM0_Da = 0;
    in_XMM0_Db = 0;
  }
  else {
    luaL_checknumber();
  }
  uVar1 = luaL_testudata();
  if (uVar1 == 0) {
    uVar1 = lua_type();
    if (0 < (int)uVar1) {
      luaL_checknumber();
    }
    uVar1 = lua_type();
    if (0 < (int)uVar1) {
      luaL_checknumber();
    }
    uVar1 = lua_type();
    if (0 < (int)uVar1) {
      luaL_checknumber();
    }
  }
  pMVar2 = ::Build_Yaw_Matrix((Matrix *)(float)(double)CONCAT44(in_XMM0_Db,in_XMM0_Da),
                              (float)unaff_EDI,unaff_ESI);
  pfVar4 = local_88;
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pfVar4 = (pMVar2->right).x;
    pMVar2 = (Matrix *)&(pMVar2->right).y;
    pfVar4 = pfVar4 + 1;
  }
  pMVar2 = NewMatrix(unaff_EDI);
  pfVar4 = local_88;
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    (pMVar2->right).x = *pfVar4;
    pfVar4 = pfVar4 + 1;
    pMVar2 = (Matrix *)&(pMVar2->right).y;
  }
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::Add_Mult_Vectors  @ 4fc46481  lines 998-1004


int __cdecl LuaBindings::Add_Mult_Vectors(lua_State *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float *pfVar7;
  float *pfVar8;
  Vector *pVVar9;
  lua_State *unaff_EDI;
  float fVar10;
  double in_XMM0_Qa;
  
  pfVar7 = (float *)luaL_checkudata("Vector");
  pfVar8 = (float *)luaL_checkudata("Vector");
  luaL_checknumber();
  fVar1 = *pfVar8;
  fVar10 = (float)in_XMM0_Qa;
  fVar2 = *pfVar7;
  fVar3 = pfVar8[1];
  fVar4 = pfVar7[1];
  fVar5 = pfVar8[2];
  fVar6 = pfVar7[2];
  pVVar9 = NewVector(unaff_EDI);
  pVVar9->x = fVar1 * fVar10 + fVar2;
  pVVar9->y = fVar3 * fVar10 + fVar4;
  pVVar9->z = fVar5 * fVar10 + fVar6;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::IsNullVector  @ 4fc4cf60  lines 1008-1012


int __cdecl LuaBindings::IsNullVector(lua_State *param_1)

{
  bool bVar1;
  Vector *pVVar2;
  uint *extraout_EDX;
  
  pVVar2 = (Vector *)luaL_checkudata("Vector");
  bVar1 = ::IsNullVector(*pVVar2);
  *extraout_EDX = (uint)bVar1;
  extraout_EDX[1] = 0x7ff7a501;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::FrontToRadian  @ 4fc4c074  lines 1016-1020


int __cdecl LuaBindings::FrontToRadian(lua_State *param_1)

{
  Vector *pVVar1;
  
  pVVar1 = (Vector *)luaL_checkudata("Vector");
  ::FrontToRadian(*pVVar1);
  lua_pushnumber();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::FrontToDegrees  @ 4fc4ec0c  lines 1024-1028


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __cdecl LuaBindings::FrontToDegrees(lua_State *param_1)

{
  Vector *pVVar1;
  
  pVVar1 = (Vector *)luaL_checkudata("Vector");
  ::FrontToRadian(*pVVar1);
  lua_pushnumber();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetFacingDirection  @ 4fc4ee3b  lines 1032-1037


int __cdecl LuaBindings::GetFacingDirection(lua_State *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float *pfVar4;
  Vector *pVVar5;
  Vector *unaff_ESI;
  Vector *unaff_EDI;
  
  pfVar4 = (float *)luaL_checkudata("Vector");
  luaL_checkudata("Vector");
  fVar1 = *pfVar4;
  fVar2 = pfVar4[1];
  fVar3 = pfVar4[2];
  Normalize_Vector(unaff_EDI,unaff_ESI);
  pVVar5 = NewVector((lua_State *)unaff_EDI);
  pVVar5->x = fVar1;
  pVVar5->y = fVar2;
  pVVar5->z = fVar3;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetFacingDrection2D  @ 4fc4b791  lines 1041-1046


int __cdecl LuaBindings::GetFacingDrection2D(lua_State *param_1)

{
  float *pfVar1;
  float *pfVar2;
  Vector *pVVar3;
  lua_State *unaff_EDI;
  float fVar4;
  double dVar5;
  float fVar6;
  
  pfVar1 = (float *)luaL_checkudata("Vector");
  pfVar2 = (float *)luaL_checkudata("Vector");
  fVar4 = *pfVar2 - *pfVar1;
  fVar6 = pfVar2[2] - pfVar1[2];
  dVar5 = (double)(fVar4 * fVar4 + fVar6 * fVar6);
  __libm_sse2_sqrt_precise();
  pVVar3 = NewVector(unaff_EDI);
  pVVar3->x = fVar4 / (float)dVar5;
  pVVar3->y = 0.0;
  pVVar3->z = fVar6 / (float)dVar5;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::Make_RGB  @ 4fc4b3b1  lines 1053-1059


int __cdecl LuaBindings::Make_RGB(lua_State *param_1)

{
  lua_State *plVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  plVar1 = param_1;
  uVar2 = lua_type();
  uVar4 = 0;
  if ((int)uVar2 < 1) {
    uVar2 = 0;
  }
  else {
    uVar2 = luaL_checkinteger();
  }
  uVar3 = lua_type();
  if ((int)uVar3 < 1) {
    param_1 = (lua_State *)0x0;
  }
  else {
    param_1 = (lua_State *)luaL_checkinteger();
  }
  uVar3 = lua_type();
  if (0 < (int)uVar3) {
    uVar4 = luaL_checkinteger();
  }
  **(double **)(plVar1 + 8) =
       (double)(int)(((uVar2 | 0xffffff00) << 8 | (uint)param_1) << 8 | uVar4);
  plVar1 = plVar1 + 8;
  *(int *)plVar1 = *(int *)plVar1 + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::Make_RGBA  @ 4fc4751a  lines 1061-1068


int __cdecl LuaBindings::Make_RGBA(lua_State *param_1)

{
  lua_State *plVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint local_8;
  
  plVar1 = param_1;
  uVar2 = lua_type();
  iVar4 = 0;
  if ((int)uVar2 < 1) {
    param_1 = (lua_State *)0x0;
  }
  else {
    param_1 = (lua_State *)luaL_checkinteger();
  }
  uVar2 = lua_type();
  if ((int)uVar2 < 1) {
    local_8 = 0;
  }
  else {
    local_8 = luaL_checkinteger();
  }
  uVar2 = lua_type();
  if ((int)uVar2 < 1) {
    uVar2 = 0;
  }
  else {
    uVar2 = luaL_checkinteger();
  }
  uVar3 = lua_type();
  if (0 < (int)uVar3) {
    iVar4 = luaL_checkinteger();
  }
  **(double **)(plVar1 + 8) =
       (double)(int)(((iVar4 << 8 | (uint)param_1) << 8 | local_8) << 8 | uVar2);
  plVar1 = plVar1 + 8;
  *(int *)plVar1 = *(int *)plVar1 + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::FailMission  @ 4fc4c604  lines 1072-1077


int __cdecl LuaBindings::FailMission(lua_State *param_1)

{
  char *pcVar1;
  undefined4 in_XMM0_Da;
  undefined4 in_XMM0_Db;
  
  luaL_checknumber();
  pcVar1 = luaL_optlstring((char *)0x0,(int *)0x0);
  (*misnImport.FailMission)((float)(double)CONCAT44(in_XMM0_Db,in_XMM0_Da),pcVar1);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::SucceedMission  @ 4fc4a096  lines 1081-1086


int __cdecl LuaBindings::SucceedMission(lua_State *param_1)

{
  char *pcVar1;
  undefined4 in_XMM0_Da;
  undefined4 in_XMM0_Db;
  
  luaL_checknumber();
  pcVar1 = luaL_optlstring((char *)0x0,(int *)0x0);
  (*misnImport.SucceedMission)((float)(double)CONCAT44(in_XMM0_Db,in_XMM0_Da),pcVar1);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::ChangeSide  @ 4fc48260  lines 1090-1093


int __cdecl LuaBindings::ChangeSide(lua_State *param_1)

{
  (*misnImport.ChangeSide)();
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::AddScrap  @ 4fc4ba8b  lines 1097-1102


int __cdecl LuaBindings::AddScrap(lua_State *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = luaL_checkinteger();
  iVar2 = luaL_checkinteger();
  iVar1 = (*misnImport.AddScrap)(iVar1,iVar2);
  **(double **)(param_1 + 8) = (double)iVar1;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::SetScrap  @ 4fc4c645  lines 1106-1111


int __cdecl LuaBindings::SetScrap(lua_State *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = luaL_checkinteger();
  iVar2 = luaL_checkinteger();
  iVar1 = (*misnImport.SetScrap)(iVar1,iVar2);
  **(double **)(param_1 + 8) = (double)iVar1;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetScrap  @ 4fc46aba  lines 1115-1119


int __cdecl LuaBindings::GetScrap(lua_State *param_1)

{
  int iVar1;
  
  iVar1 = luaL_checkinteger();
  iVar1 = (*misnImport.GetScrap)(iVar1);
  **(double **)(param_1 + 8) = (double)iVar1;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::AddMaxScrap  @ 4fc4a0d7  lines 1123-1129


int __cdecl LuaBindings::AddMaxScrap(lua_State *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = luaL_checkinteger();
  iVar2 = luaL_checkinteger();
  ::AddMaxScrap(iVar1,iVar2);
  iVar1 = (*misnImport.GetMaxScrap)(iVar1);
  **(double **)(param_1 + 8) = (double)iVar1;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::SetMaxScrap  @ 4fc4becf  lines 1133-1139


int __cdecl LuaBindings::SetMaxScrap(lua_State *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = luaL_checkinteger();
  iVar2 = luaL_checkinteger();
  ::SetMaxScrap(iVar1,iVar2);
  iVar1 = (*misnImport.GetMaxScrap)(iVar1);
  **(double **)(param_1 + 8) = (double)iVar1;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetMaxScrap  @ 4fc4a3b1  lines 1143-1147


int __cdecl LuaBindings::GetMaxScrap(lua_State *param_1)

{
  int iVar1;
  
  iVar1 = luaL_checkinteger();
  iVar1 = (*misnImport.GetMaxScrap)(iVar1);
  **(double **)(param_1 + 8) = (double)iVar1;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetTime  @ 4fc4bb9a  lines 1151-1154


int __cdecl LuaBindings::GetTime(lua_State *param_1)

{
  lua_pushnumber();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetTug  @ 4fc4bf49  lines 1158-1163


int __cdecl LuaBindings::GetTug(lua_State *param_1)

{
  int iVar1;
  lua_State *unaff_EBP;
  int unaff_retaddr;
  
  iVar1 = RequireHandle(unaff_EBP,unaff_retaddr);
  (*misnImport.GetTug)(iVar1);
  PushHandle(unaff_EBP,unaff_retaddr);
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::HasCargo  @ 4fc49fc3  lines 1167-1171


int __cdecl LuaBindings::HasCargo(lua_State *param_1)

{
  uint *puVar1;
  bool bVar2;
  int iVar3;
  int unaff_ESI;
  lua_State *unaff_EDI;
  
  iVar3 = RequireHandle(unaff_EDI,unaff_ESI);
  bVar2 = (*misnImport.HasCargo)(iVar3);
  puVar1 = *(uint **)(param_1 + 8);
  puVar1[1] = 0x7ff7a501;
  *puVar1 = (uint)bVar2;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetDistance  @ 4fc4dd5a  lines 1179-1203


int __cdecl LuaBindings::GetDistance(lua_State *param_1)

{
  Vector VVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  char *pcVar5;
  int unaff_ESI;
  lua_State *unaff_EDI;
  int local_10;
  float local_c [2];
  
  local_10 = RequireHandle(unaff_EDI,unaff_ESI);
  uVar2 = luaL_testudata();
  if (uVar2 == 0) {
    piVar3 = (int *)luaL_testudata();
    if (piVar3 == (int *)0x0) {
      iVar4 = lua_isstring();
      if (iVar4 == 0) {
        local_c[0] = (float)RequireHandle(unaff_EDI,unaff_ESI);
        local_c[0] = (*misnImport.GetDistanceObject)(&local_10,(int *)local_c);
      }
      else {
        iVar4 = 0;
        pcVar5 = (char *)lua_tolstring((undefined4 *)0x0);
        uVar2 = lua_type();
        if (0 < (int)uVar2) {
          iVar4 = luaL_checkinteger();
        }
        local_c[0] = (*misnImport.GetDistancePath)(&local_10,pcVar5,iVar4);
      }
      goto LAB_4fc4de1d;
    }
  }
  else {
    piVar3 = (int *)(uVar2 + 0x30);
  }
  VVar1.z = (float)unaff_EDI;
  VVar1.x = (float)piVar3[1];
  VVar1.y = (float)piVar3[2];
  local_c[0] = ::GetDistance(*piVar3,VVar1);
LAB_4fc4de1d:
  lua_pushnumber();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetNearestObject  @ 4fc486b1  lines 1207-1232


int __cdecl LuaBindings::GetNearestObject(lua_State *param_1)

{
  int iVar1;
  lua_State *unaff_EBP;
  int unaff_retaddr;
  
  iVar1 = RequireHandle(unaff_EBP,unaff_retaddr);
  (*misnImport.GetNearestObject)(iVar1);
  PushHandle(unaff_EBP,unaff_retaddr);
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetNearestVehicle  @ 4fc48936  lines 1237-1263


int __cdecl LuaBindings::GetNearestVehicle(lua_State *param_1)

{
  int iVar1;
  char *pcVar2;
  uint uVar3;
  int unaff_EBP;
  lua_State *unaff_ESI;
  
  iVar1 = lua_isstring();
  if (iVar1 == 0) {
    iVar1 = RequireHandle(unaff_ESI,unaff_EBP);
    (*misnImport.GetNearestVehicleObject)(iVar1);
  }
  else {
    iVar1 = 0;
    pcVar2 = (char *)lua_tolstring((undefined4 *)0x0);
    uVar3 = lua_type();
    if (0 < (int)uVar3) {
      iVar1 = luaL_checkinteger();
    }
    (*misnImport.GetNearestVehiclePath)(pcVar2,iVar1);
  }
  PushHandle(unaff_ESI,unaff_EBP);
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetNearestBuilding  @ 4fc4624c  lines 1267-1292


int __cdecl LuaBindings::GetNearestBuilding(lua_State *param_1)

{
  int iVar1;
  lua_State *unaff_EBP;
  int unaff_retaddr;
  
  iVar1 = RequireHandle(unaff_EBP,unaff_retaddr);
  (*misnImport.GetNearestBuilding)(iVar1);
  PushHandle(unaff_EBP,unaff_retaddr);
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetNearestEnemy  @ 4fc475e4  lines 1297-1331


int __cdecl LuaBindings::GetNearestEnemy(lua_State *param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int unaff_ESI;
  lua_State *unaff_EDI;
  double in_XMM0_Qa;
  
  uVar1 = lua_type();
  iVar2 = RequireHandle(unaff_EDI,unaff_ESI);
  if (uVar1 == 1) {
    iVar3 = lua_toboolean();
    iVar4 = lua_toboolean();
    uVar1 = lua_type();
    if ((int)uVar1 < 1) {
      in_XMM0_Qa = __real_407c200000000000;
    }
    else {
      luaL_checknumber();
    }
    ::GetNearestEnemy(iVar2,iVar3 != 0,iVar4 != 0,(float)in_XMM0_Qa);
  }
  else {
    (*misnImport.GetNearestEnemy)(iVar2);
  }
  PushHandle(unaff_EDI,unaff_ESI);
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::BuildObject  @ 4fc4a756  lines 1338-1370


int __cdecl LuaBindings::BuildObject(lua_State *param_1)

{
  char *pcVar1;
  int iVar2;
  Matrix *pMVar3;
  Vector *pVVar4;
  int iVar5;
  uint uVar6;
  int unaff_ESI;
  lua_State *unaff_EDI;
  Vector local_14;
  char *local_8;
  
  pcVar1 = (char *)luaL_checklstring((undefined4 *)0x0);
  iVar2 = luaL_checkinteger();
  pMVar3 = (Matrix *)luaL_testudata();
  if (pMVar3 == (Matrix *)0x0) {
    pVVar4 = (Vector *)luaL_testudata();
    if (pVVar4 == (Vector *)0x0) {
      iVar5 = lua_isstring();
      if (iVar5 == 0) {
        iVar5 = RequireHandle(unaff_EDI,unaff_ESI);
        ::BuildObject(pcVar1,iVar2,iVar5);
      }
      else {
        local_8 = (char *)lua_tolstring((undefined4 *)0x0);
        uVar6 = lua_type();
        if (((int)uVar6 < 1) || (iVar5 = luaL_checkinteger(), iVar5 == 0)) {
          ::BuildObject(pcVar1,iVar2,local_8);
        }
        else {
          ::GetPosition(local_8,iVar5,&local_14);
          ::BuildObject(pcVar1,iVar2,&local_14);
        }
      }
    }
    else {
      ::BuildObject(pcVar1,iVar2,pVVar4);
    }
  }
  else {
    ::BuildObject(pcVar1,iVar2,pMVar3);
  }
  PushHandle(unaff_EDI,unaff_ESI);
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::RemoveObject  @ 4fc494e0  lines 1374-1378


int __cdecl LuaBindings::RemoveObject(lua_State *param_1)

{
  int iVar1;
  lua_State *unaff_EBP;
  int unaff_retaddr;
  
  iVar1 = RequireHandle(unaff_EBP,unaff_retaddr);
  ::RemoveObject(iVar1);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::GetFirstEmptyGroup  @ 4fc497c8  lines 1383-1400


int __cdecl LuaBindings::GetFirstEmptyGroup(lua_State *param_1)

{
  int iVar1;
  
  iVar1 = lua_isnumber();
  if (iVar1 == 0) {
    iVar1 = ::GetFirstEmptyGroup();
  }
  else {
    iVar1 = lua_tointegerx((undefined4 *)0x0);
    iVar1 = ::GetFirstEmptyGroup(iVar1);
  }
  if (iVar1 == -1) {
    *(undefined4 *)((int)*(double **)(param_1 + 8) + 4) = 0x7ff7a500;
  }
  else {
    **(double **)(param_1 + 8) = (double)iVar1;
  }
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::SetGroup  @ 4fc4cb2d  lines 1404-1409


int __cdecl LuaBindings::SetGroup(lua_State *param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int unaff_EBP;
  lua_State *unaff_ESI;
  
  iVar1 = RequireHandle(unaff_ESI,unaff_EBP);
  uVar2 = lua_type();
  if ((int)uVar2 < 1) {
    iVar3 = 0;
  }
  else {
    iVar3 = luaL_checkinteger();
  }
  ::SetGroup(iVar1,iVar3);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::Attack  @ 4fc460c7  lines 1413-1419


int __cdecl LuaBindings::Attack(lua_State *param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int unaff_EBX;
  lua_State *unaff_ESI;
  int iVar4;
  
  iVar4 = 1;
  iVar1 = RequireHandle(unaff_ESI,unaff_EBX);
  iVar2 = RequireHandle(unaff_ESI,unaff_EBX);
  uVar3 = lua_type();
  if (0 < (int)uVar3) {
    iVar4 = luaL_checkinteger();
  }
  ::Attack(iVar1,iVar2,iVar4);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::Service  @ 4fc4c85c  lines 1423-1429


int __cdecl LuaBindings::Service(lua_State *param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int unaff_EBX;
  lua_State *unaff_ESI;
  int iVar4;
  
  iVar4 = 1;
  iVar1 = RequireHandle(unaff_ESI,unaff_EBX);
  iVar2 = RequireHandle(unaff_ESI,unaff_EBX);
  uVar3 = lua_type();
  if (0 < (int)uVar3) {
    iVar4 = luaL_checkinteger();
  }
  ::Service(iVar1,iVar2,iVar4);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::Goto  @ 4fc4961f  lines 1437-1469


int __cdecl LuaBindings::Goto(lua_State *param_1)

{
  char *pcVar1;
  char *pcVar2;
  uint uVar3;
  undefined4 *puVar4;
  Vector *pVVar5;
  int iVar6;
  char *pcVar7;
  int unaff_ESI;
  lua_State *unaff_EDI;
  undefined4 *puVar8;
  undefined4 local_54 [12];
  Vector local_24 [2];
  char *local_8;
  
  pcVar7 = (char *)0x1;
  pcVar2 = (char *)RequireHandle(unaff_EDI,unaff_ESI);
  local_8 = pcVar2;
  uVar3 = lua_type();
  if (0 < (int)uVar3) {
    pcVar7 = (char *)luaL_checkinteger();
  }
  puVar4 = (undefined4 *)luaL_testudata();
  pcVar1 = local_8;
  if (puVar4 == (undefined4 *)0x0) {
    pVVar5 = (Vector *)luaL_testudata();
    if (pVVar5 == (Vector *)0x0) {
      iVar6 = lua_isstring();
      if (iVar6 == 0) {
        iVar6 = RequireHandle(unaff_EDI,unaff_ESI);
        ::Goto((int)pcVar2,iVar6,(int)pcVar7);
        return 0;
      }
      local_8 = (char *)lua_tolstring((undefined4 *)0x0);
      iVar6 = lua_isnumber();
      if (iVar6 == 0) {
        ::Goto((int)pcVar2,local_8,(int)pcVar7);
        return 0;
      }
      uVar3 = lua_type();
      if ((int)uVar3 < 1) {
        pVVar5 = (Vector *)0x0;
      }
      else {
        pVVar5 = (Vector *)luaL_checkinteger();
      }
      uVar3 = lua_type();
      if ((int)uVar3 < 1) {
        pcVar7 = (char *)0x1;
      }
      else {
        pcVar7 = (char *)luaL_checkinteger();
      }
      pVVar5 = GetVectorFromPath(pVVar5,pcVar7,(int)unaff_EDI);
    }
  }
  else {
    pVVar5 = local_24;
    puVar8 = local_54;
    for (iVar6 = 0x10; pcVar2 = pcVar1, iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar8 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar8 = puVar8 + 1;
    }
  }
  ::Goto((int)pcVar2,pVVar5,(int)pcVar7);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::Mine  @ 4fc4a1fc  lines 1477-1509


int __cdecl LuaBindings::Mine(lua_State *param_1)

{
  int iVar1;
  uint uVar2;
  Vector *pVVar3;
  int iVar4;
  int unaff_ESI;
  lua_State *unaff_EDI;
  char *pcVar5;
  Vector local_14;
  char *local_8;
  
  pcVar5 = (char *)0x1;
  iVar1 = RequireHandle(unaff_EDI,unaff_ESI);
  uVar2 = lua_type();
  if (0 < (int)uVar2) {
    pcVar5 = (char *)luaL_checkinteger();
  }
  uVar2 = luaL_testudata();
  if (uVar2 == 0) {
    pVVar3 = (Vector *)luaL_testudata();
    if (pVVar3 == (Vector *)0x0) {
      iVar4 = lua_isstring();
      if (iVar4 == 0) {
        iVar4 = RequireHandle(unaff_EDI,unaff_ESI);
        ::GetPosition(iVar4,&local_14);
        ::Mine(iVar1,&local_14,(int)pcVar5);
        return 0;
      }
      local_8 = (char *)lua_tolstring((undefined4 *)0x0);
      iVar4 = lua_isnumber();
      if (iVar4 == 0) {
        ::Mine(iVar1,local_8,(int)pcVar5);
        return 0;
      }
      uVar2 = lua_type();
      if ((int)uVar2 < 1) {
        pVVar3 = (Vector *)0x0;
      }
      else {
        pVVar3 = (Vector *)luaL_checkinteger();
      }
      uVar2 = lua_type();
      if ((int)uVar2 < 1) {
        pcVar5 = (char *)0x1;
      }
      else {
        pcVar5 = (char *)luaL_checkinteger();
      }
      pVVar3 = GetVectorFromPath(pVVar3,pcVar5,(int)unaff_EDI);
    }
  }
  else {
    pVVar3 = (Vector *)(uVar2 + 0x30);
  }
  ::Mine(iVar1,pVVar3,(int)pcVar5);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::Follow  @ 4fc49cda  lines 1513-1519


int __cdecl LuaBindings::Follow(lua_State *param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int unaff_EBX;
  lua_State *unaff_ESI;
  int iVar4;
  
  iVar4 = 1;
  iVar1 = RequireHandle(unaff_ESI,unaff_EBX);
  iVar2 = RequireHandle(unaff_ESI,unaff_EBX);
  uVar3 = lua_type();
  if (0 < (int)uVar3) {
    iVar4 = luaL_checkinteger();
  }
  ::Follow(iVar1,iVar2,iVar4);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::Defend  @ 4fc4eb29  lines 1523-1528


int __cdecl LuaBindings::Defend(lua_State *param_1)

{
  int iVar1;
  uint uVar2;
  int unaff_ESI;
  int iVar3;
  lua_State *unaff_EDI;
  
  iVar3 = 1;
  iVar1 = RequireHandle(unaff_EDI,unaff_ESI);
  uVar2 = lua_type();
  if (0 < (int)uVar2) {
    iVar3 = luaL_checkinteger();
  }
  ::Defend(iVar1,iVar3);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::Defend2  @ 4fc4ad03  lines 1532-1538


int __cdecl LuaBindings::Defend2(lua_State *param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int unaff_EBX;
  lua_State *unaff_ESI;
  int iVar4;
  
  iVar4 = 1;
  iVar1 = RequireHandle(unaff_ESI,unaff_EBX);
  iVar2 = RequireHandle(unaff_ESI,unaff_EBX);
  uVar3 = lua_type();
  if (0 < (int)uVar3) {
    iVar4 = luaL_checkinteger();
  }
  ::Defend2(iVar1,iVar2,iVar4);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::Stop  @ 4fc4be42  lines 1542-1547


int __cdecl LuaBindings::Stop(lua_State *param_1)

{
  int iVar1;
  uint uVar2;
  int unaff_ESI;
  int iVar3;
  lua_State *unaff_EDI;
  
  iVar3 = 1;
  iVar1 = RequireHandle(unaff_EDI,unaff_ESI);
  uVar2 = lua_type();
  if (0 < (int)uVar2) {
    iVar3 = luaL_checkinteger();
  }
  ::Stop(iVar1,iVar3);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::Patrol  @ 4fc4ff46  lines 1551-1557


int __cdecl LuaBindings::Patrol(lua_State *param_1)

{
  int iVar1;
  char *pcVar2;
  uint uVar3;
  int unaff_EBX;
  lua_State *unaff_ESI;
  int iVar4;
  
  iVar4 = 1;
  iVar1 = RequireHandle(unaff_ESI,unaff_EBX);
  pcVar2 = (char *)luaL_checklstring((undefined4 *)0x0);
  uVar3 = lua_type();
  if (0 < (int)uVar3) {
    iVar4 = luaL_checkinteger();
  }
  ::Patrol(iVar1,pcVar2,iVar4);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::Retreat  @ 4fc4a5aa  lines 1563-1595


int __cdecl LuaBindings::Retreat(lua_State *param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  float *pfVar4;
  int iVar5;
  int iVar6;
  int unaff_ESI;
  lua_State *unaff_EDI;
  undefined4 *puVar7;
  Vector *pVVar8;
  undefined4 local_64 [12];
  float local_34 [7];
  Vector local_18;
  char *local_c;
  int local_8;
  
  iVar6 = 1;
  iVar1 = RequireHandle(unaff_EDI,unaff_ESI);
  local_8 = iVar1;
  uVar2 = lua_type();
  if (0 < (int)uVar2) {
    iVar6 = luaL_checkinteger();
  }
  puVar3 = (undefined4 *)luaL_testudata();
  if (puVar3 == (undefined4 *)0x0) {
    pfVar4 = (float *)luaL_testudata();
    if (pfVar4 == (float *)0x0) {
      iVar5 = lua_isstring();
      if (iVar5 == 0) {
        iVar5 = RequireHandle(unaff_EDI,unaff_ESI);
        ::Retreat(iVar1,iVar5,iVar6);
        return 0;
      }
      local_c = (char *)lua_tolstring((undefined4 *)0x0);
      iVar5 = lua_isnumber();
      if (iVar5 == 0) {
        ::Retreat(iVar1,local_c,iVar6);
        return 0;
      }
      uVar2 = lua_type();
      if ((int)uVar2 < 1) {
        pVVar8 = (Vector *)0x0;
      }
      else {
        pVVar8 = (Vector *)luaL_checkinteger();
      }
      uVar2 = lua_type();
      if ((int)uVar2 < 1) {
        iVar1 = 1;
      }
      else {
        iVar1 = luaL_checkinteger();
      }
      pVVar8 = GetVectorFromPath(pVVar8,(char *)unaff_EDI,unaff_ESI);
      iVar6 = local_8;
      local_18.x = pVVar8->x;
      local_18.y = pVVar8->y;
      local_18.z = pVVar8->z;
      ::SetIndependence(local_8,0);
      ::Goto(iVar6,&local_18,iVar1);
      return 0;
    }
  }
  else {
    puVar7 = local_64;
    for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar7 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar7 = puVar7 + 1;
    }
    pfVar4 = local_34;
  }
  iVar1 = local_8;
  local_18.x = *pfVar4;
  local_18.y = pfVar4[1];
  local_18.z = pfVar4[2];
  ::SetIndependence(local_8,0);
  ::Goto(iVar1,&local_18,iVar6);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::GetIn  @ 4fc4deaf  lines 1599-1605


int __cdecl LuaBindings::GetIn(lua_State *param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int unaff_EBX;
  lua_State *unaff_ESI;
  int iVar4;
  
  iVar4 = 1;
  iVar1 = RequireHandle(unaff_ESI,unaff_EBX);
  iVar2 = RequireHandle(unaff_ESI,unaff_EBX);
  uVar3 = lua_type();
  if (0 < (int)uVar3) {
    iVar4 = luaL_checkinteger();
  }
  ::GetIn(iVar1,iVar2,iVar4);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::Pickup  @ 4fc4a8b3  lines 1609-1615


int __cdecl LuaBindings::Pickup(lua_State *param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int unaff_EBX;
  lua_State *unaff_ESI;
  int iVar4;
  
  iVar4 = 1;
  iVar1 = RequireHandle(unaff_ESI,unaff_EBX);
  iVar2 = RequireHandle(unaff_ESI,unaff_EBX);
  uVar3 = lua_type();
  if (0 < (int)uVar3) {
    iVar4 = luaL_checkinteger();
  }
  ::Pickup(iVar1,iVar2,iVar4);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::Dropoff  @ 4fc498c5  lines 1623-1656


int __cdecl LuaBindings::Dropoff(lua_State *param_1)

{
  char *pcVar1;
  uint uVar2;
  undefined4 *puVar3;
  Vector *pVVar4;
  int iVar5;
  char *pcVar6;
  int unaff_ESI;
  lua_State *unaff_EDI;
  undefined4 *puVar7;
  char *pcVar8;
  undefined4 local_54 [12];
  Vector local_24;
  Vector local_14;
  char *local_8;
  
  pcVar6 = (char *)0x1;
  pcVar1 = (char *)RequireHandle(unaff_EDI,unaff_ESI);
  local_8 = pcVar1;
  uVar2 = lua_type();
  if (0 < (int)uVar2) {
    pcVar6 = (char *)luaL_checkinteger();
  }
  puVar3 = (undefined4 *)luaL_testudata();
  pcVar8 = local_8;
  if (puVar3 == (undefined4 *)0x0) {
    pVVar4 = (Vector *)luaL_testudata();
    if (pVVar4 == (Vector *)0x0) {
      iVar5 = lua_isstring();
      if (iVar5 == 0) {
        iVar5 = RequireHandle(unaff_EDI,unaff_ESI);
        ::GetPosition(iVar5,&local_14);
        ::Dropoff((int)pcVar1,&local_14,(int)pcVar6);
        return 0;
      }
      local_8 = (char *)lua_tolstring((undefined4 *)0x0);
      iVar5 = lua_isnumber();
      if (iVar5 == 0) {
        ::Dropoff((int)pcVar1,local_8,(int)pcVar6);
        return 0;
      }
      uVar2 = lua_type();
      if ((int)uVar2 < 1) {
        pVVar4 = (Vector *)0x0;
      }
      else {
        pVVar4 = (Vector *)luaL_checkinteger();
      }
      uVar2 = lua_type();
      if ((int)uVar2 < 1) {
        pcVar6 = (char *)0x1;
      }
      else {
        pcVar6 = (char *)luaL_checkinteger();
      }
      pVVar4 = GetVectorFromPath(pVVar4,pcVar6,(int)unaff_EDI);
    }
    pcVar8 = pcVar1;
  }
  else {
    pVVar4 = &local_24;
    puVar7 = local_54;
    for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar7 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar7 = puVar7 + 1;
    }
  }
  ::Dropoff((int)pcVar8,pVVar4,(int)pcVar6);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::Build  @ 4fc44c20  lines 1660-1666


int __cdecl LuaBindings::Build(lua_State *param_1)

{
  int iVar1;
  char *pcVar2;
  uint uVar3;
  int unaff_EBX;
  lua_State *unaff_ESI;
  int iVar4;
  
  iVar4 = 1;
  iVar1 = RequireHandle(unaff_ESI,unaff_EBX);
  pcVar2 = (char *)luaL_checklstring((undefined4 *)0x0);
  uVar3 = lua_type();
  if (0 < (int)uVar3) {
    iVar4 = luaL_checkinteger();
  }
  ::Build(iVar1,pcVar2,iVar4);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::LookAt  @ 4fc4fb70  lines 1670-1676


int __cdecl LuaBindings::LookAt(lua_State *param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int unaff_EBX;
  lua_State *unaff_ESI;
  int iVar4;
  
  iVar4 = 1;
  iVar1 = RequireHandle(unaff_ESI,unaff_EBX);
  iVar2 = RequireHandle(unaff_ESI,unaff_EBX);
  uVar3 = lua_type();
  if (0 < (int)uVar3) {
    iVar4 = luaL_checkinteger();
  }
  ::LookAt(iVar1,iVar2,iVar4);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::AllLookAt  @ 4fc454fc  lines 1680-1686


int __cdecl LuaBindings::AllLookAt(lua_State *param_1)

{
  int iVar1;
  uint uVar2;
  int unaff_EBX;
  lua_State *unaff_ESI;
  int iVar3;
  double in_XMM0_Qa;
  
  iVar3 = 1;
  luaL_checknumber();
  iVar1 = RequireHandle(unaff_ESI,unaff_EBX);
  uVar2 = lua_type();
  if (0 < (int)uVar2) {
    iVar3 = luaL_checkinteger();
  }
  ::AllLookAt((int)in_XMM0_Qa,iVar1,iVar3);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::IsOdf  @ 4fc4af35  lines 1690-1695


int __cdecl LuaBindings::IsOdf(lua_State *param_1)

{
  uint *puVar1;
  bool bVar2;
  int iVar3;
  char *pcVar4;
  int unaff_ESI;
  lua_State *unaff_EDI;
  
  iVar3 = RequireHandle(unaff_EDI,unaff_ESI);
  pcVar4 = (char *)luaL_checklstring((undefined4 *)0x0);
  bVar2 = ::IsOdf(iVar3,pcVar4);
  puVar1 = *(uint **)(param_1 + 8);
  *puVar1 = (uint)bVar2;
  puVar1[1] = 0x7ff7a501;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetRace  @ 4fc452ef  lines 1699-1707


int __cdecl LuaBindings::GetRace(lua_State *param_1)

{
  char cVar1;
  int iVar2;
  int in_ECX;
  lua_State *unaff_ESI;
  
  iVar2 = RequireHandle(unaff_ESI,in_ECX);
  cVar1 = ::GetRace(iVar2);
  if (cVar1 == '\0') {
    *(undefined4 *)(*(int *)(param_1 + 8) + 4) = 0x7ff7a500;
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  }
  else {
    lua_pushlstring(1);
  }
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetPlayerHandle  @ 4fc4c0ba  lines 1712-1725


int __cdecl LuaBindings::GetPlayerHandle(lua_State *param_1)

{
  int iVar1;
  lua_State *unaff_EBP;
  int unaff_retaddr;
  
  iVar1 = lua_isnumber();
  if (iVar1 == 0) {
    ::GetPlayerHandle();
  }
  else {
    iVar1 = lua_tointegerx((undefined4 *)0x0);
    ::GetPlayerHandle(iVar1);
  }
  PushHandle(unaff_EBP,unaff_retaddr);
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::IsAlive  @ 4fc47e24  lines 1729-1733


int __cdecl LuaBindings::IsAlive(lua_State *param_1)

{
  uint *puVar1;
  bool bVar2;
  int iVar3;
  int unaff_EBP;
  lua_State *unaff_ESI;
  
  iVar3 = RequireHandle(unaff_ESI,unaff_EBP);
  bVar2 = IsAlive2(iVar3);
  puVar1 = *(uint **)(param_1 + 8);
  *puVar1 = (uint)bVar2;
  puVar1[1] = 0x7ff7a501;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::IsFlying  @ 4fc4a952  lines 1737-1741


int __cdecl LuaBindings::IsFlying(lua_State *param_1)

{
  uint *puVar1;
  bool bVar2;
  int iVar3;
  int unaff_EBP;
  lua_State *unaff_ESI;
  
  iVar3 = RequireHandle(unaff_ESI,unaff_EBP);
  bVar2 = IsFlying2(iVar3);
  puVar1 = *(uint **)(param_1 + 8);
  *puVar1 = (uint)bVar2;
  puVar1[1] = 0x7ff7a501;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::IsAliveAndPilot  @ 4fc4fc3b  lines 1745-1749


int __cdecl LuaBindings::IsAliveAndPilot(lua_State *param_1)

{
  uint *puVar1;
  bool bVar2;
  int iVar3;
  int unaff_EBP;
  lua_State *unaff_ESI;
  
  iVar3 = RequireHandle(unaff_ESI,unaff_EBP);
  bVar2 = IsAliveAndPilot2(iVar3);
  puVar1 = *(uint **)(param_1 + 8);
  *puVar1 = (uint)bVar2;
  puVar1[1] = 0x7ff7a501;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::IsAround  @ 4fc49a8a  lines 1753-1757


int __cdecl LuaBindings::IsAround(lua_State *param_1)

{
  uint *puVar1;
  bool bVar2;
  int iVar3;
  int unaff_EBP;
  lua_State *unaff_ESI;
  
  iVar3 = RequireHandle(unaff_ESI,unaff_EBP);
  bVar2 = ::IsAround(iVar3);
  puVar1 = *(uint **)(param_1 + 8);
  *puVar1 = (uint)bVar2;
  puVar1[1] = 0x7ff7a501;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::InBuilding  @ 4fc48d07  lines 1761-1773


int __cdecl LuaBindings::InBuilding(lua_State *param_1)

{
  int iVar1;
  int iVar2;
  int unaff_EBP;
  lua_State *unaff_EDI;
  undefined4 in_XMM0_Da;
  undefined4 in_XMM0_Db;
  
  iVar1 = RequireHandle(unaff_EDI,unaff_EBP);
  iVar2 = lua_isnumber();
  if (iVar2 == 0) {
    ::InBuilding(iVar1);
  }
  else {
    lua_tonumberx((undefined4 *)0x0);
    InBuildingHeight(iVar1,(float)(double)CONCAT44(in_XMM0_Db,in_XMM0_Da));
  }
  PushHandle(unaff_EDI,unaff_EBP);
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::AtTerminal  @ 4fc4fd59  lines 1777-1781


int __cdecl LuaBindings::AtTerminal(lua_State *param_1)

{
  int iVar1;
  lua_State *unaff_EBP;
  int unaff_retaddr;
  
  iVar1 = RequireHandle(unaff_EBP,unaff_retaddr);
  ::AtTerminal(iVar1);
  PushHandle(unaff_EBP,unaff_retaddr);
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetPosition  @ 4fc4ac37  lines 1786-1799


int __cdecl LuaBindings::GetPosition(lua_State *param_1)

{
  int iVar1;
  char *pcVar2;
  uint uVar3;
  Vector *pVVar4;
  int unaff_ESI;
  Vector *pVVar5;
  lua_State *unaff_EDI;
  Vector local_1c;
  Vector local_10;
  
  iVar1 = lua_isstring();
  if (iVar1 == 0) {
    iVar1 = RequireHandle(unaff_EDI,unaff_ESI);
    ::GetPosition(iVar1,&local_1c);
    local_10.x = local_1c.x;
    local_10.y = local_1c.y;
    local_10.z = local_1c.z;
    pVVar4 = NewVector(unaff_EDI);
    pVVar5 = &local_10;
  }
  else {
    iVar1 = 0;
    pcVar2 = (char *)lua_tolstring((undefined4 *)0x0);
    uVar3 = lua_type();
    if (0 < (int)uVar3) {
      iVar1 = luaL_checkinteger();
    }
    ::GetPosition(pcVar2,iVar1,&local_10);
    local_1c.x = local_10.x;
    local_1c.y = local_10.y;
    local_1c.z = local_10.z;
    pVVar4 = NewVector(unaff_EDI);
    pVVar5 = &local_1c;
  }
  pVVar4->x = pVVar5->x;
  pVVar4->y = pVVar5->y;
  pVVar4->z = pVVar5->z;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetPosition2  @ 4fc4cfbe  lines 1803-1807


int __cdecl LuaBindings::GetPosition2(lua_State *param_1)

{
  int iVar1;
  Vector *pVVar2;
  int unaff_EBP;
  lua_State *unaff_ESI;
  
  iVar1 = RequireHandle(unaff_ESI,unaff_EBP);
  pVVar2 = NewVector(unaff_ESI);
  ::GetPosition2(iVar1,pVVar2);
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetFront  @ 4fc4f925  lines 1811-1815


int __cdecl LuaBindings::GetFront(lua_State *param_1)

{
  int iVar1;
  Vector *pVVar2;
  int unaff_ESI;
  lua_State *unaff_EDI;
  Vector local_10;
  
  iVar1 = RequireHandle(unaff_EDI,unaff_ESI);
  ::GetFront(iVar1,&local_10);
  pVVar2 = NewVector(unaff_EDI);
  pVVar2->x = local_10.x;
  pVVar2->y = local_10.y;
  pVVar2->z = local_10.z;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::SetPosition  @ 4fc4b2ff  lines 1822-1849


int __cdecl LuaBindings::SetPosition(lua_State *param_1)

{
  int iVar1;
  Vector *pVVar2;
  int iVar3;
  char *pcVar4;
  uint uVar5;
  int unaff_ESI;
  lua_State *unaff_EDI;
  Vector local_10;
  
  iVar1 = RequireHandle(unaff_EDI,unaff_ESI);
  pVVar2 = (Vector *)luaL_testudata();
  if (pVVar2 == (Vector *)0x0) {
    iVar3 = lua_isstring();
    if (iVar3 == 0) {
      iVar3 = RequireHandle(unaff_EDI,unaff_ESI);
      ::GetPosition(iVar3,&local_10);
      pVVar2 = &local_10;
    }
    else {
      pcVar4 = (char *)lua_tolstring((undefined4 *)0x0);
      uVar5 = lua_type();
      if (((int)uVar5 < 1) || (pVVar2 = (Vector *)luaL_checkinteger(), pVVar2 == (Vector *)0x0)) {
        ::SetPosition(iVar1,pcVar4);
        return 0;
      }
      pVVar2 = GetVectorFromPath(pVVar2,(char *)unaff_EDI,unaff_ESI);
    }
  }
  SetVectorPosition(iVar1,*pVVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::Damage  @ 4fc468ad  lines 1855-1873


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __cdecl LuaBindings::Damage(lua_State *param_1)

{
  int iVar1;
  int iVar2;
  long lVar3;
  int unaff_ESI;
  lua_State *unaff_EDI;
  double in_XMM0_Qa;
  double dVar4;
  
  iVar1 = RequireHandle(unaff_EDI,unaff_ESI);
  iVar2 = lua_isnumber();
  if (iVar2 == 0) {
    luaL_checknumber();
    dVar4 = (double)(float)in_XMM0_Qa;
    if ((float)(double)CONCAT44((uint)((ulonglong)dVar4 >> 0x20) & _UNK_4fc63074,
                                SUB84(dVar4,0) & ___xmm_7fffffffffffffff7fffffffffffffff) <=
        ___real_4f000000) {
      ::Damage(iVar1,(int)in_XMM0_Qa);
    }
    else {
      DamageF(iVar1,(float)in_XMM0_Qa);
    }
  }
  else {
    iVar2 = RequireHandle(unaff_EDI,unaff_ESI);
    lVar3 = luaL_checkinteger();
    ::Damage(iVar1,iVar2,lVar3);
  }
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::GetHealth  @ 4fc4af83  lines 1877-1881


int __cdecl LuaBindings::GetHealth(lua_State *param_1)

{
  int iVar1;
  lua_State *in_ECX;
  
  iVar1 = RequireHandle(in_ECX,(int)in_ECX);
  ::GetHealth(iVar1);
  lua_pushnumber();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetCurHealth  @ 4fc45c65  lines 1885-1893


int __cdecl LuaBindings::GetCurHealth(lua_State *param_1)

{
  int iVar1;
  long lVar2;
  int unaff_EBP;
  lua_State *unaff_ESI;
  
  iVar1 = RequireHandle(unaff_ESI,unaff_EBP);
  lVar2 = ::GetCurHealth(iVar1);
  if (lVar2 == -0x4d2) {
    *(undefined4 *)((int)*(double **)(param_1 + 8) + 4) = 0x7ff7a500;
  }
  else {
    **(double **)(param_1 + 8) = (double)lVar2;
  }
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetMaxHealth  @ 4fc4c81a  lines 1897-1905


int __cdecl LuaBindings::GetMaxHealth(lua_State *param_1)

{
  int iVar1;
  long lVar2;
  int unaff_EBP;
  lua_State *unaff_ESI;
  
  iVar1 = RequireHandle(unaff_ESI,unaff_EBP);
  lVar2 = ::GetMaxHealth(iVar1);
  if (lVar2 == -0x4d2) {
    *(undefined4 *)((int)*(double **)(param_1 + 8) + 4) = 0x7ff7a500;
  }
  else {
    **(double **)(param_1 + 8) = (double)lVar2;
  }
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::SetCurHealth  @ 4fc46b70  lines 1909-1914


int __cdecl LuaBindings::SetCurHealth(lua_State *param_1)

{
  int iVar1;
  long lVar2;
  int unaff_EBP;
  lua_State *unaff_ESI;
  
  iVar1 = RequireHandle(unaff_ESI,unaff_EBP);
  lVar2 = luaL_checkinteger();
  ::SetCurHealth(iVar1,lVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::SetMaxHealth  @ 4fc4bf6e  lines 1918-1923


int __cdecl LuaBindings::SetMaxHealth(lua_State *param_1)

{
  int iVar1;
  long lVar2;
  int unaff_EBP;
  lua_State *unaff_ESI;
  
  iVar1 = RequireHandle(unaff_ESI,unaff_EBP);
  lVar2 = luaL_checkinteger();
  ::SetMaxHealth(iVar1,lVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::AddHealth  @ 4fc4b665  lines 1927-1932


int __cdecl LuaBindings::AddHealth(lua_State *param_1)

{
  int iVar1;
  long lVar2;
  int unaff_EBP;
  lua_State *unaff_ESI;
  
  iVar1 = RequireHandle(unaff_ESI,unaff_EBP);
  lVar2 = luaL_checkinteger();
  ::AddHealth(iVar1,lVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::GetAmmo  @ 4fc4b852  lines 1936-1940


int __cdecl LuaBindings::GetAmmo(lua_State *param_1)

{
  int iVar1;
  lua_State *in_ECX;
  
  iVar1 = RequireHandle(in_ECX,(int)in_ECX);
  ::GetAmmo(iVar1);
  lua_pushnumber();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetCurAmmo  @ 4fc4b5ec  lines 1944-1952


int __cdecl LuaBindings::GetCurAmmo(lua_State *param_1)

{
  int iVar1;
  long lVar2;
  int unaff_EBP;
  lua_State *unaff_ESI;
  
  iVar1 = RequireHandle(unaff_ESI,unaff_EBP);
  lVar2 = ::GetCurAmmo(iVar1);
  if (lVar2 == -0x4d2) {
    *(undefined4 *)((int)*(double **)(param_1 + 8) + 4) = 0x7ff7a500;
  }
  else {
    **(double **)(param_1 + 8) = (double)lVar2;
  }
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetMaxAmmo  @ 4fc4dfb7  lines 1956-1964


int __cdecl LuaBindings::GetMaxAmmo(lua_State *param_1)

{
  int iVar1;
  long lVar2;
  int unaff_EBP;
  lua_State *unaff_ESI;
  
  iVar1 = RequireHandle(unaff_ESI,unaff_EBP);
  lVar2 = ::GetMaxAmmo(iVar1);
  if (lVar2 == -0x4d2) {
    *(undefined4 *)((int)*(double **)(param_1 + 8) + 4) = 0x7ff7a500;
  }
  else {
    **(double **)(param_1 + 8) = (double)lVar2;
  }
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::SetCurAmmo  @ 4fc47e56  lines 1968-1973


int __cdecl LuaBindings::SetCurAmmo(lua_State *param_1)

{
  int iVar1;
  long lVar2;
  int unaff_EBP;
  lua_State *unaff_ESI;
  
  iVar1 = RequireHandle(unaff_ESI,unaff_EBP);
  lVar2 = luaL_checkinteger();
  ::SetCurAmmo(iVar1,lVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::SetMaxAmmo  @ 4fc4ffdc  lines 1977-1982


int __cdecl LuaBindings::SetMaxAmmo(lua_State *param_1)

{
  int iVar1;
  long lVar2;
  int unaff_EBP;
  lua_State *unaff_ESI;
  
  iVar1 = RequireHandle(unaff_ESI,unaff_EBP);
  lVar2 = luaL_checkinteger();
  ::SetMaxAmmo(iVar1,lVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::AddAmmo  @ 4fc4f7f0  lines 1986-1991


int __cdecl LuaBindings::AddAmmo(lua_State *param_1)

{
  int iVar1;
  long lVar2;
  int unaff_EBP;
  lua_State *unaff_ESI;
  
  iVar1 = RequireHandle(unaff_ESI,unaff_EBP);
  lVar2 = luaL_checkinteger();
  ::AddAmmo(iVar1,lVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::GetTeamNum  @ 4fc45551  lines 1995-1999


int __cdecl LuaBindings::GetTeamNum(lua_State *param_1)

{
  int iVar1;
  int unaff_EBP;
  lua_State *unaff_ESI;
  
  iVar1 = RequireHandle(unaff_ESI,unaff_EBP);
  iVar1 = ::GetTeamNum(iVar1);
  **(double **)(param_1 + 8) = (double)iVar1;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::SetTeamNum  @ 4fc4ec58  lines 2003-2008


int __cdecl LuaBindings::SetTeamNum(lua_State *param_1)

{
  int iVar1;
  int iVar2;
  int unaff_EBP;
  lua_State *unaff_ESI;
  
  iVar1 = RequireHandle(unaff_ESI,unaff_EBP);
  iVar2 = luaL_checkinteger();
  ::SetTeamNum(iVar1,iVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::SetVelocity  @ 4fc4e834  lines 2012-2018


int __cdecl LuaBindings::SetVelocity(lua_State *param_1)

{
  int iVar1;
  Vector *pVVar2;
  int unaff_EBP;
  lua_State *unaff_ESI;
  
  iVar1 = RequireHandle(unaff_ESI,unaff_EBP);
  pVVar2 = (Vector *)luaL_checkudata("Vector");
  ::SetVelocity(iVar1,pVVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::SetControls  @ 4fc4d443  lines 2022-2121


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl LuaBindings::SetControls(lua_State *param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int unaff_ESI;
  lua_State *unaff_EDI;
  ulong uVar5;
  float in_XMM0_Da;
  undefined4 in_XMM0_Db;
  VehicleControls local_24;
  uint local_c;
  
  local_c = __security_cookie ^ (uint)&local_24;
  iVar1 = RequireHandle(unaff_EDI,unaff_ESI);
  uVar5 = 0;
  uVar2 = lua_type();
  if (uVar2 != 5) goto LAB_4fc4d73d;
  lua_getfield();
  iVar3 = lua_isnumber();
  if (iVar3 != 0) {
    lua_tonumberx((undefined4 *)0x0);
    in_XMM0_Da = (float)(double)CONCAT44(in_XMM0_Db,in_XMM0_Da);
    local_24.braccel = in_XMM0_Da;
  }
  uVar5 = (ulong)(iVar3 != 0);
  lua_settop();
  lua_getfield();
  iVar3 = lua_isnumber();
  if (iVar3 != 0) {
    uVar5 = uVar5 | 2;
    lua_tonumberx((undefined4 *)0x0);
    in_XMM0_Da = (float)(double)CONCAT44(in_XMM0_Db,in_XMM0_Da);
    local_24.steer = in_XMM0_Da;
  }
  lua_settop();
  lua_getfield();
  iVar3 = lua_isnumber();
  if (iVar3 != 0) {
    uVar5 = uVar5 | 4;
    lua_tonumberx((undefined4 *)0x0);
    in_XMM0_Da = (float)(double)CONCAT44(in_XMM0_Db,in_XMM0_Da);
    local_24.pitch = in_XMM0_Da;
  }
  lua_settop();
  lua_getfield();
  iVar3 = lua_isnumber();
  if (iVar3 != 0) {
    uVar5 = uVar5 | 8;
    lua_tonumberx((undefined4 *)0x0);
    in_XMM0_Da = (float)(double)CONCAT44(in_XMM0_Db,in_XMM0_Da);
    local_24.strafe = in_XMM0_Da;
  }
  lua_settop();
  lua_getfield();
  uVar2 = lua_type();
  if (uVar2 == 1) {
    uVar4 = lua_toboolean();
    local_24.jump = (char)uVar4;
LAB_4fc4d5c7:
    uVar5 = uVar5 | 0x10;
  }
  else {
    iVar3 = lua_isnumber();
    if (iVar3 != 0) {
      lua_tonumberx((undefined4 *)0x0);
      local_24.jump = (char)(int)(double)CONCAT44(in_XMM0_Db,in_XMM0_Da);
      goto LAB_4fc4d5c7;
    }
  }
  lua_settop();
  lua_getfield();
  uVar2 = lua_type();
  if (uVar2 == 1) {
    uVar4 = lua_toboolean();
    local_24.deploy = (char)uVar4;
LAB_4fc4d61e:
    uVar5 = uVar5 | 0x20;
  }
  else {
    iVar3 = lua_isnumber();
    if (iVar3 != 0) {
      lua_tonumberx((undefined4 *)0x0);
      local_24.deploy = (char)(int)(double)CONCAT44(in_XMM0_Db,in_XMM0_Da);
      goto LAB_4fc4d61e;
    }
  }
  lua_settop();
  lua_getfield();
  uVar2 = lua_type();
  if (uVar2 == 1) {
    uVar4 = lua_toboolean();
    local_24.eject = (char)uVar4;
LAB_4fc4d675:
    uVar5 = uVar5 | 0x40;
  }
  else {
    iVar3 = lua_isnumber();
    if (iVar3 != 0) {
      lua_tonumberx((undefined4 *)0x0);
      local_24.eject = (char)(int)(double)CONCAT44(in_XMM0_Db,in_XMM0_Da);
      goto LAB_4fc4d675;
    }
  }
  lua_settop();
  lua_getfield();
  uVar2 = lua_type();
  if (uVar2 == 1) {
    uVar4 = lua_toboolean();
    local_24.abandon = (char)uVar4;
LAB_4fc4d6d2:
    uVar5 = uVar5 | 0x80;
  }
  else {
    iVar3 = lua_isnumber();
    if (iVar3 != 0) {
      lua_tonumberx((undefined4 *)0x0);
      local_24.abandon = (char)(int)(double)CONCAT44(in_XMM0_Db,in_XMM0_Da);
      goto LAB_4fc4d6d2;
    }
  }
  lua_settop();
  lua_getfield();
  uVar2 = lua_type();
  if (uVar2 == 1) {
    uVar4 = lua_toboolean();
    local_24.fire = (char)uVar4;
LAB_4fc4d72f:
    uVar5 = uVar5 | 0x100;
  }
  else {
    iVar3 = lua_isnumber();
    if (iVar3 != 0) {
      lua_tonumberx((undefined4 *)0x0);
      local_24.fire = (char)(int)(double)CONCAT44(in_XMM0_Db,in_XMM0_Da);
      goto LAB_4fc4d72f;
    }
  }
  lua_settop();
LAB_4fc4d73d:
  ::SetControls(iVar1,&local_24,uVar5);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::GetWhoShotMe  @ 4fc50007  lines 2125-2129


int __cdecl LuaBindings::GetWhoShotMe(lua_State *param_1)

{
  int iVar1;
  lua_State *unaff_EBP;
  int unaff_retaddr;
  
  iVar1 = RequireHandle(unaff_EBP,unaff_retaddr);
  ::GetWhoShotMe(iVar1);
  PushHandle(unaff_EBP,unaff_retaddr);
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetLastEnemyShot  @ 4fc458a7  lines 2133-2137


int __cdecl LuaBindings::GetLastEnemyShot(lua_State *param_1)

{
  int iVar1;
  lua_State *in_ECX;
  
  iVar1 = RequireHandle(in_ECX,(int)in_ECX);
  ::GetLastEnemyShot(iVar1);
  lua_pushnumber();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetLastFriendShot  @ 4fc47091  lines 2141-2145


int __cdecl LuaBindings::GetLastFriendShot(lua_State *param_1)

{
  int iVar1;
  lua_State *in_ECX;
  
  iVar1 = RequireHandle(in_ECX,(int)in_ECX);
  ::GetLastFriendShot(iVar1);
  lua_pushnumber();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::DefaultAllies  @ 4fc4d7c0  lines 2149-2152


int __cdecl LuaBindings::DefaultAllies(lua_State *param_1)

{
  ::DefaultAllies();
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::TeamplayAllies  @ 4fc461c5  lines 2156-2159


int __cdecl LuaBindings::TeamplayAllies(lua_State *param_1)

{
  ::TeamplayAllies();
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::Ally  @ 4fc46de9  lines 2163-2168


int __cdecl LuaBindings::Ally(lua_State *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = luaL_checkinteger();
  iVar2 = luaL_checkinteger();
  ::Ally(iVar1,iVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::UnAlly  @ 4fc4d761  lines 2172-2177


int __cdecl LuaBindings::UnAlly(lua_State *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = luaL_checkinteger();
  iVar2 = luaL_checkinteger();
  ::UnAlly(iVar1,iVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::IsTeamAllied  @ 4fc4d00d  lines 2181-2186


int __cdecl LuaBindings::IsTeamAllied(lua_State *param_1)

{
  uint *puVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = luaL_checkinteger();
  iVar4 = luaL_checkinteger();
  bVar2 = ::IsTeamAllied(iVar3,iVar4);
  puVar1 = *(uint **)(param_1 + 8);
  *puVar1 = (uint)bVar2;
  puVar1[1] = 0x7ff7a501;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::IsAlly  @ 4fc4c55f  lines 2190-2195


int __cdecl LuaBindings::IsAlly(lua_State *param_1)

{
  uint *puVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int unaff_ESI;
  lua_State *unaff_EDI;
  
  iVar3 = RequireHandle(unaff_EDI,unaff_ESI);
  iVar4 = RequireHandle(unaff_EDI,unaff_ESI);
  bVar2 = ::IsAlly(iVar3,iVar4);
  puVar1 = *(uint **)(param_1 + 8);
  *puVar1 = (uint)bVar2;
  puVar1[1] = 0x7ff7a501;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::AudioMessage  @ 4fc476b0  lines 2199-2203


int __cdecl LuaBindings::AudioMessage(lua_State *param_1)

{
  char *pcVar1;
  int iVar2;
  
  pcVar1 = (char *)luaL_checklstring((undefined4 *)0x0);
  iVar2 = ::AudioMessage(pcVar1,false);
  **(double **)(param_1 + 8) = (double)iVar2;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::IsAudioMessageDone  @ 4fc459a6  lines 2207-2211


int __cdecl LuaBindings::IsAudioMessageDone(lua_State *param_1)

{
  uint *puVar1;
  bool bVar2;
  int iVar3;
  
  iVar3 = luaL_checkinteger();
  bVar2 = ::IsAudioMessageDone(iVar3);
  puVar1 = *(uint **)(param_1 + 8);
  *puVar1 = (uint)bVar2;
  puVar1[1] = 0x7ff7a501;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::StopAudioMessage  @ 4fc4b690  lines 2215-2219


int __cdecl LuaBindings::StopAudioMessage(lua_State *param_1)

{
  int iVar1;
  
  iVar1 = luaL_checkinteger();
  ::StopAudioMessage(iVar1);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::PreloadAudioMessage  @ 4fc4e324  lines 2223-2227


int __cdecl LuaBindings::PreloadAudioMessage(lua_State *param_1)

{
  char *pcVar1;
  
  pcVar1 = (char *)luaL_checklstring((undefined4 *)0x0);
  ::PreloadAudioMessage(pcVar1);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::PurgeAudioMessage  @ 4fc466e3  lines 2231-2235


int __cdecl LuaBindings::PurgeAudioMessage(lua_State *param_1)

{
  char *pcVar1;
  
  pcVar1 = (char *)luaL_checklstring((undefined4 *)0x0);
  ::PurgeAudioMessage(pcVar1);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::PreloadMusicMessage  @ 4fc4beb2  lines 2239-2243


int __cdecl LuaBindings::PreloadMusicMessage(lua_State *param_1)

{
  char *pcVar1;
  
  pcVar1 = (char *)luaL_checklstring((undefined4 *)0x0);
  ::PreloadMusicMessage(pcVar1);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::PurgeMusicMessage  @ 4fc47a21  lines 2247-2251


int __cdecl LuaBindings::PurgeMusicMessage(lua_State *param_1)

{
  char *pcVar1;
  
  pcVar1 = (char *)luaL_checklstring((undefined4 *)0x0);
  ::PurgeMusicMessage(pcVar1);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::LoadJukeFile  @ 4fc5008b  lines 2255-2259


int __cdecl LuaBindings::LoadJukeFile(lua_State *param_1)

{
  char *pcVar1;
  
  pcVar1 = (char *)luaL_checklstring((undefined4 *)0x0);
  ::LoadJukeFile(pcVar1);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::SetMusicIntensity  @ 4fc4b5a0  lines 2263-2267


int __cdecl LuaBindings::SetMusicIntensity(lua_State *param_1)

{
  int iVar1;
  
  iVar1 = luaL_checkinteger();
  ::SetMusicIntensity(iVar1);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::GetAiPaths  @ 4fc4f171  lines 2310-2322


int __cdecl LuaBindings::GetAiPaths(lua_State *param_1)

{
  int iVar1;
  char **local_c;
  int local_8;
  
  ::GetAiPaths(&local_8,&local_c);
  iVar1 = 0;
  lua_createtable(0);
  if (0 < local_8) {
    do {
      lua_pushstring();
      iVar1 = iVar1 + 1;
      lua_rawseti(iVar1);
    } while (iVar1 < local_8);
  }
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::SetPathType  @ 4fc5035d  lines 2326-2331


int __cdecl LuaBindings::SetPathType(lua_State *param_1)

{
  char *pcVar1;
  PathType PVar2;
  
  pcVar1 = (char *)luaL_checklstring((undefined4 *)0x0);
  PVar2 = luaL_checkinteger();
  ::SetPathType(pcVar1,PVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::SetPathOneWay  @ 4fc49f25  lines 2335-2339


int __cdecl LuaBindings::SetPathOneWay(lua_State *param_1)

{
  char *pcVar1;
  
  pcVar1 = (char *)luaL_checklstring((undefined4 *)0x0);
  ::SetPathType(pcVar1,ONE_WAY_PATH);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::SetPathRoundTrip  @ 4fc49e10  lines 2341-2345


int __cdecl LuaBindings::SetPathRoundTrip(lua_State *param_1)

{
  char *pcVar1;
  
  pcVar1 = (char *)luaL_checklstring((undefined4 *)0x0);
  ::SetPathType(pcVar1,ROUND_TRIP_PATH);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::SetPathLoop  @ 4fc4a01f  lines 2347-2351


int __cdecl LuaBindings::SetPathLoop(lua_State *param_1)

{
  char *pcVar1;
  
  pcVar1 = (char *)luaL_checklstring((undefined4 *)0x0);
  ::SetPathType(pcVar1,LOOP_PATH);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::SetIndependence  @ 4fc4fc10  lines 2355-2360


int __cdecl LuaBindings::SetIndependence(lua_State *param_1)

{
  int iVar1;
  int iVar2;
  int unaff_EBP;
  lua_State *unaff_ESI;
  
  iVar1 = RequireHandle(unaff_ESI,unaff_EBP);
  iVar2 = luaL_checkinteger();
  ::SetIndependence(iVar1,iVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::IsInfo  @ 4fc48a19  lines 2365-2377


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl LuaBindings::IsInfo(lua_State *param_1)

{
  uint *puVar1;
  bool bVar2;
  int iVar3;
  char *pcVar4;
  char *unaff_EBX;
  uint uVar5;
  lua_State *unaff_ESI;
  char local_48 [64];
  undefined4 local_8;
  
  local_8 = __security_cookie ^ (uint)(local_48 + 0x44);
  iVar3 = lua_isstring();
  if (iVar3 == 0) {
    RequireHandle(unaff_ESI,(int)unaff_EBX);
    uVar5 = 0;
    memset(local_48,0,0x40);
    bVar2 = GetODFName((int)unaff_ESI,unaff_EBX);
    if (bVar2) {
      bVar2 = ::IsInfo(local_48);
      uVar5 = (uint)bVar2;
    }
    puVar1 = *(uint **)(param_1 + 8);
    *puVar1 = uVar5;
    puVar1[1] = 0x7ff7a501;
  }
  else {
    pcVar4 = (char *)lua_tolstring((undefined4 *)0x0);
    bVar2 = ::IsInfo(pcVar4);
    puVar1 = *(uint **)(param_1 + 8);
    *puVar1 = (uint)bVar2;
    puVar1[1] = 0x7ff7a501;
  }
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::StartCockpitTimer  @ 4fc47159  lines 2381-2387


int __cdecl LuaBindings::StartCockpitTimer(lua_State *param_1)

{
  long lVar1;
  uint uVar2;
  long lVar3;
  long lVar4;
  
  lVar1 = luaL_checkinteger();
  uVar2 = lua_type();
  lVar4 = -0x80000000;
  if ((int)uVar2 < 1) {
    lVar3 = -0x80000000;
  }
  else {
    lVar3 = luaL_checkinteger();
  }
  uVar2 = lua_type();
  if (0 < (int)uVar2) {
    lVar4 = luaL_checkinteger();
  }
  ::StartCockpitTimer(lVar1,lVar3,lVar4);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::StartCockpitTimerUp  @ 4fc4a84a  lines 2391-2397


int __cdecl LuaBindings::StartCockpitTimerUp(lua_State *param_1)

{
  long lVar1;
  uint uVar2;
  long lVar3;
  long lVar4;
  
  lVar1 = luaL_checkinteger();
  uVar2 = lua_type();
  lVar4 = 0x7fffffff;
  if ((int)uVar2 < 1) {
    lVar3 = 0x7fffffff;
  }
  else {
    lVar3 = luaL_checkinteger();
  }
  uVar2 = lua_type();
  if (0 < (int)uVar2) {
    lVar4 = luaL_checkinteger();
  }
  ::StartCockpitTimerUp(lVar1,lVar3,lVar4);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::StopCockpitTimer  @ 4fc4f6bf  lines 2401-2404


int __cdecl LuaBindings::StopCockpitTimer(lua_State *param_1)

{
  ::StopCockpitTimer();
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::HideCockpitTimer  @ 4fc4639a  lines 2408-2411


int __cdecl LuaBindings::HideCockpitTimer(lua_State *param_1)

{
  ::HideCockpitTimer();
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::GetCockpitTimer  @ 4fc48803  lines 2415-2419


int __cdecl LuaBindings::GetCockpitTimer(lua_State *param_1)

{
  double *pdVar1;
  long lVar2;
  
  lVar2 = ::GetCockpitTimer();
  pdVar1 = *(double **)(param_1 + 8);
  *pdVar1 = (double)lVar2;
  *(double **)(param_1 + 8) = pdVar1 + 1;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::StartEarthQuake  @ 4fc4e9f3  lines 2423-2427


int __cdecl LuaBindings::StartEarthQuake(lua_State *param_1)

{
  undefined4 in_XMM0_Da;
  undefined4 in_XMM0_Db;
  
  luaL_checknumber();
  ::StartEarthQuake((float)(double)CONCAT44(in_XMM0_Db,in_XMM0_Da));
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::UpdateEarthQuake  @ 4fc493eb  lines 2431-2435


int __cdecl LuaBindings::UpdateEarthQuake(lua_State *param_1)

{
  undefined4 in_XMM0_Da;
  undefined4 in_XMM0_Db;
  
  luaL_checknumber();
  ::UpdateEarthQuake((float)(double)CONCAT44(in_XMM0_Db,in_XMM0_Da));
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::StopEarthQuake  @ 4fc4fbc3  lines 2439-2442


int __cdecl LuaBindings::StopEarthQuake(lua_State *param_1)

{
  ::StopEarthQuake();
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::IsPerson  @ 4fc454ca  lines 2446-2450


int __cdecl LuaBindings::IsPerson(lua_State *param_1)

{
  uint *puVar1;
  bool bVar2;
  int iVar3;
  int unaff_EBP;
  lua_State *unaff_ESI;
  
  iVar3 = RequireHandle(unaff_ESI,unaff_EBP);
  bVar2 = ::IsPerson(iVar3);
  puVar1 = *(uint **)(param_1 + 8);
  *puVar1 = (uint)bVar2;
  puVar1[1] = 0x7ff7a501;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetCurWorld  @ 4fc46e31  lines 2454-2457


int __cdecl LuaBindings::GetCurWorld(lua_State *param_1)

{
  ::GetCurWorld();
  lua_pushnumber();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetVarItemStr  @ 4fc4c5c5  lines 2461-2469


int __cdecl LuaBindings::GetVarItemStr(lua_State *param_1)

{
  char *pcVar1;
  
  pcVar1 = (char *)luaL_checklstring((undefined4 *)0x0);
  pcVar1 = ::GetVarItemStr(pcVar1);
  if (pcVar1 == (char *)0x0) {
    *(undefined4 *)(*(int *)(param_1 + 8) + 4) = 0x7ff7a500;
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  }
  else {
    lua_pushstring();
  }
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetVarItemInt  @ 4fc46aec  lines 2473-2477


int __cdecl LuaBindings::GetVarItemInt(lua_State *param_1)

{
  char *pcVar1;
  
  pcVar1 = (char *)luaL_checklstring((undefined4 *)0x0);
  ::GetVarItemInt(pcVar1);
  lua_pushnumber();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetCVarItemInt  @ 4fc4d25c  lines 2481-2486


int __cdecl LuaBindings::GetCVarItemInt(lua_State *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = luaL_checkinteger();
  iVar2 = luaL_checkinteger();
  ::GetCVarItemInt(iVar1,iVar2);
  lua_pushnumber();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetCVarItemStr  @ 4fc4a720  lines 2490-2495


int __cdecl LuaBindings::GetCVarItemStr(lua_State *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = luaL_checkinteger();
  iVar2 = luaL_checkinteger();
  ::GetCVarItemStr(iVar1,iVar2);
  lua_pushstring();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::PreloadODF  @ 4fc4561d  lines 2499-2503


int __cdecl LuaBindings::PreloadODF(lua_State *param_1)

{
  char *pcVar1;
  
  pcVar1 = (char *)luaL_checklstring((undefined4 *)0x0);
  ::PreloadODF(pcVar1);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::TerrainFindFloor  @ 4fc49b05  lines 2512-2541


int __cdecl LuaBindings::TerrainFindFloor(lua_State *param_1)

{
  double dVar1;
  Vector VVar2;
  undefined4 *puVar3;
  Vector *pVVar4;
  uint uVar5;
  int iVar6;
  int unaff_ESI;
  char *unaff_EDI;
  undefined4 *puVar7;
  undefined4 in_XMM0_Da;
  float fVar8;
  undefined4 in_XMM0_Db;
  float local_68;
  float local_60;
  Vector local_54;
  undefined4 local_48 [12];
  float local_18;
  float local_10;
  
  puVar3 = (undefined4 *)luaL_testudata();
  if (puVar3 == (undefined4 *)0x0) {
    pVVar4 = (Vector *)luaL_testudata();
    if (pVVar4 == (Vector *)0x0) {
      uVar5 = luaL_testudata();
      if (uVar5 == 0) {
        iVar6 = lua_isnumber();
        if (iVar6 == 0) {
          iVar6 = lua_isstring();
          if (iVar6 == 0) {
            return 1;
          }
          pVVar4 = (Vector *)0x0;
          lua_tolstring((undefined4 *)0x0);
          uVar5 = lua_type();
          if (0 < (int)uVar5) {
            pVVar4 = (Vector *)luaL_checkinteger();
          }
          GetVectorFromPath(pVVar4,unaff_EDI,unaff_ESI);
          ::TerrainFindFloor(local_68,local_60);
        }
        else {
          lua_tonumberx((undefined4 *)0x0);
          dVar1 = (double)CONCAT44(in_XMM0_Db,in_XMM0_Da);
          fVar8 = (float)dVar1;
          luaL_checknumber();
          ::TerrainFindFloor((float)dVar1,(float)(double)CONCAT44(in_XMM0_Db,fVar8));
        }
      }
      else {
        ::GetPosition(uVar5,&local_54);
        VVar2.y = local_54.y;
        VVar2.x = local_54.x;
        VVar2.z = local_54.z;
        ::TerrainFindFloor(VVar2);
      }
    }
    else {
      ::TerrainFindFloor(*pVVar4);
    }
  }
  else {
    puVar7 = local_48;
    for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar7 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar7 = puVar7 + 1;
    }
    ::TerrainFindFloor(local_18,local_10);
  }
  lua_pushnumber();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::AddPilotByHandle  @ 4fc49a70  lines 2545-2549


int __cdecl LuaBindings::AddPilotByHandle(lua_State *param_1)

{
  int iVar1;
  lua_State *unaff_EBP;
  int unaff_retaddr;
  
  iVar1 = RequireHandle(unaff_EBP,unaff_retaddr);
  ::AddPilotByHandle(iVar1);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::PrintConsoleMessage  @ 4fc4de3b  lines 2553-2557


int __cdecl LuaBindings::PrintConsoleMessage(lua_State *param_1)

{
  char *pcVar1;
  
  pcVar1 = (char *)luaL_checklstring((undefined4 *)0x0);
  ::PrintConsoleMessage(pcVar1);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::GetRandomFloat  @ 4fc4ef87  lines 2562-2574


int __cdecl LuaBindings::GetRandomFloat(lua_State *param_1)

{
  int iVar1;
  undefined4 in_XMM0_Da;
  float fVar2;
  float fVar3;
  undefined4 in_XMM0_Db;
  
  luaL_checknumber();
  fVar2 = (float)(double)CONCAT44(in_XMM0_Db,in_XMM0_Da);
  fVar3 = fVar2;
  iVar1 = lua_isnumber();
  if (iVar1 == 0) {
    ::GetRandomFloat(fVar2);
  }
  else {
    lua_tonumberx((undefined4 *)0x0);
    ::GetRandomFloat(fVar2,(float)(double)CONCAT44(in_XMM0_Db,fVar3));
  }
  lua_pushnumber();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::IsDeployed  @ 4fc4c0f9  lines 2578-2582


int __cdecl LuaBindings::IsDeployed(lua_State *param_1)

{
  uint *puVar1;
  bool bVar2;
  int iVar3;
  int unaff_EBP;
  lua_State *unaff_ESI;
  
  iVar3 = RequireHandle(unaff_ESI,unaff_EBP);
  bVar2 = ::IsDeployed(iVar3);
  puVar1 = *(uint **)(param_1 + 8);
  *puVar1 = (uint)bVar2;
  puVar1[1] = 0x7ff7a501;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::Deploy  @ 4fc4787b  lines 2586-2590


int __cdecl LuaBindings::Deploy(lua_State *param_1)

{
  int iVar1;
  lua_State *unaff_EBP;
  int unaff_retaddr;
  
  iVar1 = RequireHandle(unaff_EBP,unaff_retaddr);
  ::Deploy(iVar1);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::IsSelected  @ 4fc4f626  lines 2594-2598


int __cdecl LuaBindings::IsSelected(lua_State *param_1)

{
  uint *puVar1;
  bool bVar2;
  int iVar3;
  int unaff_EBP;
  lua_State *unaff_ESI;
  
  iVar3 = RequireHandle(unaff_ESI,unaff_EBP);
  bVar2 = ::IsSelected(iVar3);
  puVar1 = *(uint **)(param_1 + 8);
  *puVar1 = (uint)bVar2;
  puVar1[1] = 0x7ff7a501;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::SetWeaponMask  @ 4fc4bbba  lines 2602-2607


int __cdecl LuaBindings::SetWeaponMask(lua_State *param_1)

{
  int iVar1;
  long lVar2;
  int unaff_EBP;
  lua_State *unaff_ESI;
  
  iVar1 = RequireHandle(unaff_ESI,unaff_EBP);
  lVar2 = luaL_checkinteger();
  ::SetWeaponMask(iVar1,lVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::GiveWeapon  @ 4fc4c12b  lines 2612-2621


int __cdecl LuaBindings::GiveWeapon(lua_State *param_1)

{
  int iVar1;
  char *pcVar2;
  uint uVar3;
  int iVar4;
  int unaff_ESI;
  lua_State *unaff_EDI;
  
  iVar1 = RequireHandle(unaff_EDI,unaff_ESI);
  pcVar2 = (char *)luaL_checklstring((undefined4 *)0x0);
  uVar3 = lua_type();
  if (((int)uVar3 < 1) || (iVar4 = luaL_checkinteger(), iVar4 < 0)) {
    ::GiveWeapon(iVar1,pcVar2);
    return 0;
  }
  ::GiveWeapon(iVar1,iVar4,pcVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::FireAt  @ 4fc49e30  lines 2625-2631


int __cdecl LuaBindings::FireAt(lua_State *param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int unaff_EBX;
  lua_State *unaff_EDI;
  
  iVar1 = RequireHandle(unaff_EDI,unaff_EBX);
  uVar2 = luaL_testudata();
  uVar3 = lua_type();
  if ((int)uVar3 < 1) {
    iVar4 = 0;
  }
  else {
    iVar4 = lua_toboolean();
  }
  ::FireAt(iVar1,uVar2,iVar4 != 0);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::IsFollowing  @ 4fc469a0  lines 2636-2643


int __cdecl LuaBindings::IsFollowing(lua_State *param_1)

{
  uint *puVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int unaff_ESI;
  lua_State *unaff_EDI;
  
  iVar3 = RequireHandle(unaff_EDI,unaff_ESI);
  uVar4 = luaL_testudata();
  if (uVar4 == 0) {
    bVar2 = ::IsFollowing(iVar3);
    puVar1 = *(uint **)(param_1 + 8);
    *puVar1 = (uint)bVar2;
    puVar1[1] = 0x7ff7a501;
  }
  else {
    bVar2 = ::IsAround(uVar4);
    if (bVar2) {
      uVar5 = ::WhoFollowing(iVar3);
      uVar4 = (uint)(uVar5 == uVar4);
    }
    else {
      uVar4 = 0;
    }
    puVar1 = *(uint **)(param_1 + 8);
    *puVar1 = uVar4;
    puVar1[1] = 0x7ff7a501;
  }
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::WhoFollowing  @ 4fc4dbd7  lines 2647-2651


int __cdecl LuaBindings::WhoFollowing(lua_State *param_1)

{
  int iVar1;
  lua_State *unaff_EBP;
  int unaff_retaddr;
  
  iVar1 = RequireHandle(unaff_EBP,unaff_retaddr);
  ::WhoFollowing(iVar1);
  PushHandle(unaff_EBP,unaff_retaddr);
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::SetUserTarget  @ 4fc46202  lines 2655-2668


int __cdecl LuaBindings::SetUserTarget(lua_State *param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  lua_State *unaff_EBP;
  lua_State *unaff_ESI;
  int unaff_retaddr;
  
  uVar1 = lua_type();
  if (uVar1 == 0xffffffff) {
    iVar2 = RequireHandle(unaff_EBP,unaff_retaddr);
    ::SetUserTarget(iVar2);
  }
  else {
    iVar2 = luaL_checkinteger();
    iVar3 = RequireHandle(unaff_ESI,(int)unaff_EBP);
    ::SetUserTarget(iVar2,iVar3);
  }
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::GetUserTarget  @ 4fc4dd1a  lines 2673-2682


int __cdecl LuaBindings::GetUserTarget(lua_State *param_1)

{
  uint uVar1;
  int iVar2;
  lua_State *unaff_EBP;
  int unaff_retaddr;
  
  uVar1 = lua_type();
  if (0 < (int)uVar1) {
    iVar2 = luaL_checkinteger();
    if (-1 < iVar2) {
      ::GetUserTarget(iVar2);
      goto LAB_4fc4dd4b;
    }
  }
  ::GetUserTarget();
LAB_4fc4dd4b:
  PushHandle(unaff_EBP,unaff_retaddr);
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::SetPerceivedTeam  @ 4fc4c4a9  lines 2686-2691


int __cdecl LuaBindings::SetPerceivedTeam(lua_State *param_1)

{
  int iVar1;
  int iVar2;
  int unaff_EBP;
  lua_State *unaff_ESI;
  
  iVar1 = RequireHandle(unaff_ESI,unaff_EBP);
  iVar2 = luaL_checkinteger();
  ::SetPerceivedTeam(iVar1,iVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::GetCurrentCommand  @ 4fc47895  lines 2695-2699


int __cdecl LuaBindings::GetCurrentCommand(lua_State *param_1)

{
  int iVar1;
  AiCommand AVar2;
  int unaff_EBP;
  lua_State *unaff_ESI;
  
  iVar1 = RequireHandle(unaff_ESI,unaff_EBP);
  AVar2 = ::GetCurrentCommand(iVar1);
  **(double **)(param_1 + 8) = (double)(int)AVar2;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetCurrentWho  @ 4fc494fa  lines 2703-2707


int __cdecl LuaBindings::GetCurrentWho(lua_State *param_1)

{
  int iVar1;
  lua_State *unaff_EBP;
  int unaff_retaddr;
  
  iVar1 = RequireHandle(unaff_EBP,unaff_retaddr);
  ::GetCurrentWho(iVar1);
  PushHandle(unaff_EBP,unaff_retaddr);
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::EjectPilot  @ 4fc46467  lines 2711-2715


int __cdecl LuaBindings::EjectPilot(lua_State *param_1)

{
  int iVar1;
  lua_State *unaff_EBP;
  int unaff_retaddr;
  
  iVar1 = RequireHandle(unaff_EBP,unaff_retaddr);
  ::EjectPilot(iVar1);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::HopOut  @ 4fc48602  lines 2719-2723


int __cdecl LuaBindings::HopOut(lua_State *param_1)

{
  int iVar1;
  lua_State *unaff_EBP;
  int unaff_retaddr;
  
  iVar1 = RequireHandle(unaff_EBP,unaff_retaddr);
  ::HopOut(iVar1);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::KillPilot  @ 4fc475ca  lines 2727-2731


int __cdecl LuaBindings::KillPilot(lua_State *param_1)

{
  int iVar1;
  lua_State *unaff_EBP;
  int unaff_retaddr;
  
  iVar1 = RequireHandle(unaff_EBP,unaff_retaddr);
  ::KillPilot(iVar1);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::RemovePilot  @ 4fc4bd89  lines 2735-2739


int __cdecl LuaBindings::RemovePilot(lua_State *param_1)

{
  int iVar1;
  lua_State *unaff_EBP;
  int unaff_retaddr;
  
  iVar1 = RequireHandle(unaff_EBP,unaff_retaddr);
  RemovePilotAI(iVar1);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::HoppedOutOf  @ 4fc4a071  lines 2743-2747


int __cdecl LuaBindings::HoppedOutOf(lua_State *param_1)

{
  int iVar1;
  lua_State *unaff_EBP;
  int unaff_retaddr;
  
  iVar1 = RequireHandle(unaff_EBP,unaff_retaddr);
  ::HoppedOutOf(iVar1);
  PushHandle(unaff_EBP,unaff_retaddr);
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetCameraPosition  @ 4fc48514  lines 2751-2758


int __cdecl LuaBindings::GetCameraPosition(lua_State *param_1)

{
  Vector *pVVar1;
  lua_State *unaff_EDI;
  Vector local_1c;
  Vector local_10;
  
  local_10.x = 0.0;
  local_10.y = 0.0;
  local_10.z = 0.0;
  local_1c.x = 0.0;
  local_1c.y = 0.0;
  local_1c.z = 0.0;
  ::GetCameraPosition(&local_10,&local_1c);
  pVVar1 = NewVector(unaff_EDI);
  pVVar1->x = local_10.x;
  pVVar1->y = local_10.y;
  pVVar1->z = local_10.z;
  pVVar1 = NewVector(unaff_EDI);
  pVVar1->x = local_1c.x;
  pVVar1->y = local_1c.y;
  pVVar1->z = local_1c.z;
  return 2;
}


// ---------------------------------------------------------------------
// LuaBindings::SetCameraPosition  @ 4fc4fd7e  lines 2762-2767


int __cdecl LuaBindings::SetCameraPosition(lua_State *param_1)

{
  Vector *pVVar1;
  Vector *pVVar2;
  
  pVVar1 = (Vector *)luaL_checkudata("Vector");
  pVVar2 = (Vector *)luaL_checkudata("Vector");
  ::SetCameraPosition(pVVar1,pVVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::ResetCameraPosition  @ 4fc4afe5  lines 2771-2774


int __cdecl LuaBindings::ResetCameraPosition(lua_State *param_1)

{
  ::ResetCameraPosition();
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::CalcCRC  @ 4fc4611a  lines 2778-2782


int __cdecl LuaBindings::CalcCRC(lua_State *param_1)

{
  char *pcVar1;
  ulong uVar2;
  
  pcVar1 = (char *)luaL_checklstring((undefined4 *)0x0);
  uVar2 = ::CalcCRC(pcVar1);
  **(double **)(param_1 + 8) = (double)(int)uVar2;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::IFace_Exec  @ 4fc473a2  lines 2787-2799


int __cdecl LuaBindings::IFace_Exec(lua_State *param_1)

{
  char *pcVar1;
  uint uVar2;
  int iVar3;
  
  pcVar1 = (char *)luaL_checklstring((undefined4 *)0x0);
  uVar2 = lua_type();
  if (uVar2 == 1) {
    iVar3 = lua_toboolean();
    IFace_ExecScaled(pcVar1,iVar3 != 0);
  }
  else {
    ::IFace_Exec(pcVar1);
  }
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::IFace_Activate  @ 4fc46e14  lines 2802-2806


int __cdecl LuaBindings::IFace_Activate(lua_State *param_1)

{
  char *pcVar1;
  
  pcVar1 = (char *)luaL_checklstring((undefined4 *)0x0);
  ::IFace_Activate(pcVar1);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::IFace_Deactivate  @ 4fc45937  lines 2809-2813


int __cdecl LuaBindings::IFace_Deactivate(lua_State *param_1)

{
  char *pcVar1;
  
  pcVar1 = (char *)luaL_checklstring((undefined4 *)0x0);
  ::IFace_Deactivate(pcVar1);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::IFace_CreateCommand  @ 4fc4bb7d  lines 2816-2820


int __cdecl LuaBindings::IFace_CreateCommand(lua_State *param_1)

{
  char *pcVar1;
  
  pcVar1 = (char *)luaL_checklstring((undefined4 *)0x0);
  ::IFace_CreateCommand(pcVar1);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::IFace_CreateString  @ 4fc4afb5  lines 2824-2829


int __cdecl LuaBindings::IFace_CreateString(lua_State *param_1)

{
  char *pcVar1;
  char *pcVar2;
  
  pcVar1 = (char *)luaL_checklstring((undefined4 *)0x0);
  pcVar2 = (char *)luaL_checklstring((undefined4 *)0x0);
  ::IFace_CreateString(pcVar1,pcVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::IFace_SetString  @ 4fc47372  lines 2833-2838


int __cdecl LuaBindings::IFace_SetString(lua_State *param_1)

{
  char *pcVar1;
  char *pcVar2;
  
  pcVar1 = (char *)luaL_checklstring((undefined4 *)0x0);
  pcVar2 = (char *)luaL_checklstring((undefined4 *)0x0);
  ::IFace_SetString(pcVar1,pcVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::IFace_GetString  @ 4fc48d5f  lines 2842-2850


/* WARNING: Function: _alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl LuaBindings::IFace_GetString(lua_State *param_1)

{
  char *pcVar1;
  char acStack_814 [2044];
  undefined4 uStack_18;
  
  uStack_18 = 0x4fc48d7c;
  pcVar1 = (char *)luaL_checklstring((undefined4 *)0x0);
  ::IFace_GetString(pcVar1,acStack_814,0x800);
  lua_pushstring();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::IFace_CreateInteger  @ 4fc4bf99  lines 2854-2859


int __cdecl LuaBindings::IFace_CreateInteger(lua_State *param_1)

{
  char *pcVar1;
  int iVar2;
  
  pcVar1 = (char *)luaL_checklstring((undefined4 *)0x0);
  iVar2 = luaL_checkinteger();
  ::IFace_CreateInteger(pcVar1,iVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::IFace_SetInteger  @ 4fc47aba  lines 2863-2868


int __cdecl LuaBindings::IFace_SetInteger(lua_State *param_1)

{
  char *pcVar1;
  int iVar2;
  
  pcVar1 = (char *)luaL_checklstring((undefined4 *)0x0);
  iVar2 = luaL_checkinteger();
  ::IFace_SetInteger(pcVar1,iVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::IFace_GetInteger  @ 4fc4859d  lines 2872-2876


int __cdecl LuaBindings::IFace_GetInteger(lua_State *param_1)

{
  char *pcVar1;
  
  pcVar1 = (char *)luaL_checklstring((undefined4 *)0x0);
  ::IFace_GetInteger(pcVar1);
  lua_pushnumber();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::IFace_SetIntegerRange  @ 4fc49e8d  lines 2880-2886


int __cdecl LuaBindings::IFace_SetIntegerRange(lua_State *param_1)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  
  pcVar1 = (char *)luaL_checklstring((undefined4 *)0x0);
  iVar2 = luaL_checkinteger();
  iVar3 = luaL_checkinteger();
  ::IFace_SetIntegerRange(pcVar1,iVar2,iVar3);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::IFace_CreateFloat  @ 4fc4e4cd  lines 2890-2895


int __cdecl LuaBindings::IFace_CreateFloat(lua_State *param_1)

{
  char *pcVar1;
  undefined4 in_XMM0_Da;
  undefined4 in_XMM0_Db;
  
  pcVar1 = (char *)luaL_checklstring((undefined4 *)0x0);
  luaL_checknumber();
  ::IFace_CreateFloat(pcVar1,(float)(double)CONCAT44(in_XMM0_Db,in_XMM0_Da));
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::IFace_SetFloat  @ 4fc5038b  lines 2899-2904


int __cdecl LuaBindings::IFace_SetFloat(lua_State *param_1)

{
  char *pcVar1;
  undefined4 in_XMM0_Da;
  undefined4 in_XMM0_Db;
  
  pcVar1 = (char *)luaL_checklstring((undefined4 *)0x0);
  luaL_checknumber();
  ::IFace_SetFloat(pcVar1,(float)(double)CONCAT44(in_XMM0_Db,in_XMM0_Da));
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::IFace_GetFloat  @ 4fc500a8  lines 2908-2912


int __cdecl LuaBindings::IFace_GetFloat(lua_State *param_1)

{
  char *pcVar1;
  
  pcVar1 = (char *)luaL_checklstring((undefined4 *)0x0);
  ::IFace_GetFloat(pcVar1);
  lua_pushnumber();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::IFace_ClearListBox  @ 4fc4637d  lines 2916-2920


int __cdecl LuaBindings::IFace_ClearListBox(lua_State *param_1)

{
  char *pcVar1;
  
  pcVar1 = (char *)luaL_checklstring((undefined4 *)0x0);
  ::IFace_ClearListBox(pcVar1);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::IFace_AddTextItem  @ 4fc4bf19  lines 2924-2929


int __cdecl LuaBindings::IFace_AddTextItem(lua_State *param_1)

{
  char *pcVar1;
  char *pcVar2;
  
  pcVar1 = (char *)luaL_checklstring((undefined4 *)0x0);
  pcVar2 = (char *)luaL_checklstring((undefined4 *)0x0);
  ::IFace_AddTextItem(pcVar1,pcVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::IFace_GetSelectedItem  @ 4fc4693f  lines 2933-2941


/* WARNING: Function: _alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl LuaBindings::IFace_GetSelectedItem(lua_State *param_1)

{
  char *pcVar1;
  char acStack_814 [2044];
  undefined4 uStack_18;
  
  uStack_18 = 0x4fc4695c;
  pcVar1 = (char *)luaL_checklstring((undefined4 *)0x0);
  ::IFace_GetSelectedItem(pcVar1,acStack_814,0x800);
  lua_pushstring();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::SetSkill  @ 4fc4cef2  lines 2945-2950


int __cdecl LuaBindings::SetSkill(lua_State *param_1)

{
  int iVar1;
  int iVar2;
  int unaff_EBP;
  lua_State *unaff_ESI;
  
  iVar1 = RequireHandle(unaff_ESI,unaff_EBP);
  iVar2 = luaL_checkinteger();
  ::SetSkill(iVar1,iVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::SetAIP  @ 4fc4f52b  lines 2954-2959


int __cdecl LuaBindings::SetAIP(lua_State *param_1)

{
  char *pcVar1;
  uint uVar2;
  int iVar3;
  
  pcVar1 = (char *)luaL_checklstring((undefined4 *)0x0);
  iVar3 = 2;
  uVar2 = lua_type();
  if (0 < (int)uVar2) {
    iVar3 = luaL_checkinteger();
  }
  if (pcVar1 != (char *)0x0) {
    BZ1Helper::SetAIPFile(BZ1Helper::m_BZ1Helper,pcVar1,iVar3);
  }
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::LogFloat  @ 4fc4913b  lines 2963-2967


int __cdecl LuaBindings::LogFloat(lua_State *param_1)

{
  undefined4 in_XMM0_Da;
  undefined4 in_XMM0_Db;
  
  luaL_checknumber();
  ::LogFloat((float)(double)CONCAT44(in_XMM0_Db,in_XMM0_Da));
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::GetInstantMyForce  @ 4fc4768d  lines 2971-2974


int __cdecl LuaBindings::GetInstantMyForce(lua_State *param_1)

{
  ::GetInstantMyForce();
  lua_pushnumber();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetInstantCompForce  @ 4fc49ae2  lines 2977-2980


int __cdecl LuaBindings::GetInstantCompForce(lua_State *param_1)

{
  ::GetInstantCompForce();
  lua_pushnumber();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetInstantDifficulty  @ 4fc474f7  lines 2983-2986


int __cdecl LuaBindings::GetInstantDifficulty(lua_State *param_1)

{
  ::GetInstantDifficulty();
  lua_pushnumber();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetInstantGoal  @ 4fc4c486  lines 2989-2992


int __cdecl LuaBindings::GetInstantGoal(lua_State *param_1)

{
  ::GetInstantGoal();
  lua_pushnumber();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetInstantType  @ 4fc4f392  lines 2995-2998


int __cdecl LuaBindings::GetInstantType(lua_State *param_1)

{
  ::GetInstantType();
  lua_pushnumber();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetInstantFlag  @ 4fc4a31e  lines 3001-3004


int __cdecl LuaBindings::GetInstantFlag(lua_State *param_1)

{
  ::GetInstantFlag();
  lua_pushnumber();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetInstantMySide  @ 4fc4fdd1  lines 3007-3010


int __cdecl LuaBindings::GetInstantMySide(lua_State *param_1)

{
  ::GetInstantMySide();
  lua_pushnumber();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::CameraReady  @ 4fc4aea9  lines 3023-3026


int __cdecl LuaBindings::CameraReady(lua_State *param_1)

{
  uint *puVar1;
  bool bVar2;
  
  bVar2 = ::CameraReady();
  puVar1 = *(uint **)(param_1 + 8);
  *puVar1 = (uint)bVar2;
  puVar1[1] = 0x7ff7a501;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::CameraPath  @ 4fc4d12f  lines 3030-3037


int __cdecl LuaBindings::CameraPath(lua_State *param_1)

{
  uint *puVar1;
  bool bVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int unaff_EDI;
  lua_State *plVar7;
  
  plVar7 = (lua_State *)0x0;
  pcVar3 = (char *)luaL_checklstring((undefined4 *)0x0);
  iVar4 = luaL_checkinteger();
  iVar5 = luaL_checkinteger();
  iVar6 = RequireHandle(plVar7,unaff_EDI);
  bVar2 = ::CameraPath(pcVar3,iVar4,iVar5,iVar6);
  puVar1 = *(uint **)(param_1 + 8);
  *puVar1 = (uint)bVar2;
  puVar1[1] = 0x7ff7a501;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::CameraPathDir  @ 4fc47105  lines 3041-3047


int __cdecl LuaBindings::CameraPathDir(lua_State *param_1)

{
  uint *puVar1;
  bool bVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  
  pcVar3 = (char *)luaL_checklstring((undefined4 *)0x0);
  iVar4 = luaL_checkinteger();
  iVar5 = luaL_checkinteger();
  bVar2 = ::CameraPathDir(pcVar3,iVar4,iVar5);
  puVar1 = *(uint **)(param_1 + 8);
  *puVar1 = (uint)bVar2;
  puVar1[1] = 0x7ff7a501;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::PanDone  @ 4fc49ffb  lines 3051-3054


int __cdecl LuaBindings::PanDone(lua_State *param_1)

{
  uint *puVar1;
  bool bVar2;
  
  bVar2 = ::PanDone();
  puVar1 = *(uint **)(param_1 + 8);
  *puVar1 = (uint)bVar2;
  puVar1[1] = 0x7ff7a501;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::CameraObject  @ 4fc503c0  lines 3059-3075


int __cdecl LuaBindings::CameraObject(lua_State *param_1)

{
  uint *puVar1;
  double dVar2;
  double dVar3;
  Vector VVar4;
  bool bVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int unaff_ESI;
  lua_State *unaff_EDI;
  undefined4 in_XMM0_Da;
  float fVar9;
  undefined4 in_XMM0_Db;
  
  iVar6 = RequireHandle(unaff_EDI,unaff_ESI);
  piVar7 = (int *)luaL_testudata();
  if (piVar7 == (int *)0x0) {
    luaL_checknumber();
    dVar2 = (double)CONCAT44(in_XMM0_Db,in_XMM0_Da);
    fVar9 = (float)dVar2;
    luaL_checknumber();
    dVar3 = (double)CONCAT44(in_XMM0_Db,fVar9);
    fVar9 = (float)dVar3;
    luaL_checknumber();
    iVar8 = RequireHandle(unaff_EDI,unaff_ESI);
    bVar5 = ::CameraObject(iVar6,(float)dVar2,(float)dVar3,(float)(double)CONCAT44(in_XMM0_Db,fVar9)
                           ,iVar8);
    puVar1 = *(uint **)(param_1 + 8);
    *puVar1 = (uint)bVar5;
    puVar1[1] = 0x7ff7a501;
  }
  else {
    RequireHandle(unaff_EDI,unaff_ESI);
    VVar4.z = (float)unaff_EDI;
    VVar4.x = (float)piVar7[1];
    VVar4.y = (float)piVar7[2];
    bVar5 = ::CameraObject(*piVar7,VVar4,unaff_ESI);
    puVar1 = *(uint **)(param_1 + 8);
    *puVar1 = (uint)bVar5;
    puVar1[1] = 0x7ff7a501;
  }
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::CameraFinish  @ 4fc4c5a1  lines 3079-3082


int __cdecl LuaBindings::CameraFinish(lua_State *param_1)

{
  uint *puVar1;
  bool bVar2;
  
  bVar2 = ::CameraFinish();
  puVar1 = *(uint **)(param_1 + 8);
  *puVar1 = (uint)bVar2;
  puVar1[1] = 0x7ff7a501;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::CameraCancelled  @ 4fc4b232  lines 3086-3089


int __cdecl LuaBindings::CameraCancelled(lua_State *param_1)

{
  uint *puVar1;
  bool bVar2;
  
  bVar2 = ::CameraCancelled();
  puVar1 = *(uint **)(param_1 + 8);
  *puVar1 = (uint)bVar2;
  puVar1[1] = 0x7ff7a501;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::FreeCamera  @ 4fc479fd  lines 3093-3096


int __cdecl LuaBindings::FreeCamera(lua_State *param_1)

{
  uint *puVar1;
  bool bVar2;
  
  bVar2 = ::FreeCamera();
  puVar1 = *(uint **)(param_1 + 8);
  *puVar1 = (uint)bVar2;
  puVar1[1] = 0x7ff7a501;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::FreeFinish  @ 4fc4f88d  lines 3100-3103


int __cdecl LuaBindings::FreeFinish(lua_State *param_1)

{
  uint *puVar1;
  bool bVar2;
  
  bVar2 = ::FreeFinish();
  puVar1 = *(uint **)(param_1 + 8);
  *puVar1 = (uint)bVar2;
  puVar1[1] = 0x7ff7a501;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::PlayMovie  @ 4fc49ecb  lines 3107-3111


int __cdecl LuaBindings::PlayMovie(lua_State *param_1)

{
  uint *puVar1;
  bool bVar2;
  char *pcVar3;
  
  pcVar3 = (char *)luaL_checklstring((undefined4 *)0x0);
  bVar2 = ::PlayMovie(pcVar3);
  puVar1 = *(uint **)(param_1 + 8);
  *puVar1 = (uint)bVar2;
  puVar1[1] = 0x7ff7a501;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::StopMovie  @ 4fc48bbc  lines 3115-3118


int __cdecl LuaBindings::StopMovie(lua_State *param_1)

{
  ::StopMovie();
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::PlayMove  @ 4fc4ec83  lines 3122-3125


int __cdecl LuaBindings::PlayMove(lua_State *param_1)

{
  uint *puVar1;
  bool bVar2;
  
  bVar2 = ::PlayMove();
  puVar1 = *(uint **)(param_1 + 8);
  *puVar1 = (uint)bVar2;
  puVar1[1] = 0x7ff7a501;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::PlayRecording  @ 4fc4ef12  lines 3130-3137


int __cdecl LuaBindings::PlayRecording(lua_State *param_1)

{
  uint *puVar1;
  bool bVar2;
  char *pcVar3;
  uint uVar4;
  int iVar5;
  
  pcVar3 = (char *)luaL_checklstring((undefined4 *)0x0);
  uVar4 = lua_type();
  if (uVar4 == 1) {
    iVar5 = lua_toboolean();
    bVar2 = ::PlayRecording(pcVar3,iVar5 != 0);
    puVar1 = *(uint **)(param_1 + 8);
    *puVar1 = (uint)bVar2;
    puVar1[1] = 0x7ff7a501;
  }
  else {
    bVar2 = ::PlayRecording(pcVar3);
    puVar1 = *(uint **)(param_1 + 8);
    *puVar1 = (uint)bVar2;
    puVar1[1] = 0x7ff7a501;
  }
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::PlaybackVehicle  @ 4fc49106  lines 3141-3145


int __cdecl LuaBindings::PlaybackVehicle(lua_State *param_1)

{
  uint *puVar1;
  bool bVar2;
  char *pcVar3;
  
  pcVar3 = (char *)luaL_checklstring((undefined4 *)0x0);
  bVar2 = ::PlaybackVehicle(pcVar3);
  puVar1 = *(uint **)(param_1 + 8);
  *puVar1 = (uint)bVar2;
  puVar1[1] = 0x7ff7a501;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::SetAnimation  @ 4fc45fdf  lines 3149-3155


int __cdecl LuaBindings::SetAnimation(lua_State *param_1)

{
  int iVar1;
  char *pcVar2;
  uint uVar3;
  int unaff_ESI;
  lua_State *unaff_EDI;
  int iVar4;
  
  iVar1 = RequireHandle(unaff_EDI,unaff_ESI);
  iVar4 = 0;
  pcVar2 = (char *)luaL_checklstring((undefined4 *)0x0);
  uVar3 = lua_type();
  if (0 < (int)uVar3) {
    iVar4 = luaL_checkinteger();
  }
  ::SetAnimation(iVar1,pcVar2,iVar4);
  lua_pushnumber();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetAnimationFrame  @ 4fc4a3e3  lines 3159-3164


int __cdecl LuaBindings::GetAnimationFrame(lua_State *param_1)

{
  int iVar1;
  char *pcVar2;
  lua_State *unaff_ESI;
  int in_stack_ffffffec;
  
  iVar1 = RequireHandle(unaff_ESI,in_stack_ffffffec);
  pcVar2 = (char *)luaL_checklstring((undefined4 *)0x0);
  ::GetAnimationFrame(iVar1,pcVar2);
  lua_pushnumber();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::StartAnimation  @ 4fc4b480  lines 3168-3172


int __cdecl LuaBindings::StartAnimation(lua_State *param_1)

{
  int iVar1;
  lua_State *unaff_EBP;
  int unaff_retaddr;
  
  iVar1 = RequireHandle(unaff_EBP,unaff_retaddr);
  ::StartAnimation(iVar1);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::MaskEmitter  @ 4fc45149  lines 3176-3181


int __cdecl LuaBindings::MaskEmitter(lua_State *param_1)

{
  int iVar1;
  ulong uVar2;
  int unaff_EBP;
  lua_State *unaff_ESI;
  
  iVar1 = RequireHandle(unaff_ESI,unaff_EBP);
  uVar2 = luaL_checkinteger();
  ::MaskEmitter(iVar1,uVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::StartEmitter  @ 4fc46400  lines 3185-3190


int __cdecl LuaBindings::StartEmitter(lua_State *param_1)

{
  int iVar1;
  int iVar2;
  int unaff_EBP;
  lua_State *unaff_ESI;
  
  iVar1 = RequireHandle(unaff_ESI,unaff_EBP);
  iVar2 = luaL_checkinteger();
  ::StartEmitter(iVar1,iVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::StopEmitter  @ 4fc4cf35  lines 3194-3199


int __cdecl LuaBindings::StopEmitter(lua_State *param_1)

{
  int iVar1;
  int iVar2;
  int unaff_EBP;
  lua_State *unaff_ESI;
  
  iVar1 = RequireHandle(unaff_ESI,unaff_EBP);
  iVar2 = luaL_checkinteger();
  ::StopEmitter(iVar1,iVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::SetObjectiveOn  @ 4fc4a706  lines 3232-3236


int __cdecl LuaBindings::SetObjectiveOn(lua_State *param_1)

{
  int iVar1;
  lua_State *unaff_EBP;
  int unaff_retaddr;
  
  iVar1 = RequireHandle(unaff_EBP,unaff_retaddr);
  ::SetObjectiveOn(iVar1);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::SetObjectiveOff  @ 4fc47b6e  lines 3240-3244


int __cdecl LuaBindings::SetObjectiveOff(lua_State *param_1)

{
  int iVar1;
  lua_State *unaff_EBP;
  int unaff_retaddr;
  
  iVar1 = RequireHandle(unaff_EBP,unaff_retaddr);
  ::SetObjectiveOff(iVar1);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::SetObjectiveName  @ 4fc504bb  lines 3248-3253


int __cdecl LuaBindings::SetObjectiveName(lua_State *param_1)

{
  int iVar1;
  char *pcVar2;
  int unaff_EBP;
  lua_State *unaff_ESI;
  
  iVar1 = RequireHandle(unaff_ESI,unaff_EBP);
  pcVar2 = (char *)luaL_checklstring((undefined4 *)0x0);
  ::SetObjectiveName(iVar1,pcVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::ClearObjectives  @ 4fc4b62e  lines 3257-3260


int __cdecl LuaBindings::ClearObjectives(lua_State *param_1)

{
  ::ClearObjectives();
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::GetColor  @ 4fc44a5d  lines 3264-3286


long __cdecl LuaBindings::GetColor(char *param_1)

{
  uint uVar1;
  int in_ECX;
  char *unaff_retaddr;
  
  if (in_ECX != 0) {
    uVar1 = Hash(unaff_retaddr,(uint)param_1);
    if (uVar1 < 0x4961533b) {
      if (uVar1 == 0x4961533a) {
        return -0xff0001;
      }
      if (uVar1 == 0x11decbc) {
        return -0xff0100;
      }
      if (uVar1 == 0x5bf6449) {
        return -0x100;
      }
      if (uVar1 == 0x23dbfbcf) {
        return -0x810000;
      }
      if (uVar1 == 0x32475d3a) {
        return -0xc000;
      }
      if (uVar1 == 0x3450d0d4) {
        return -0xffff81;
      }
      if (uVar1 == 0x3657edc3) {
        return -0x9b9b9c;
      }
      if (uVar1 == 0x40f480dc) {
        return -0x10000;
      }
    }
    else {
      if (uVar1 == 0x568f4ba4) {
        return -0x1000000;
      }
      if (uVar1 == 0x5960cc5b) {
        return -0xff8100;
      }
      if (uVar1 == 0x7de4f740) {
        return -0x808100;
      }
      if (uVar1 == 0x82fbf5cd) {
        return -0xffff01;
      }
      if (uVar1 == 0x9a6e02ff) {
        return -0xff01;
      }
      if (uVar1 == 0xb29019a6) {
        return -0x808081;
      }
      if (uVar1 == 0xd8e26163) {
        return -0xff8001;
      }
    }
  }
  return -1;
}


// ---------------------------------------------------------------------
// LuaBindings::AddObjective  @ 4fc4bbe5  lines 3290-3305


int __cdecl LuaBindings::AddObjective(lua_State *param_1)

{
  char *pcVar1;
  int iVar2;
  uint uVar3;
  char *unaff_EDI;
  long lVar4;
  double in_XMM0_Qa;
  
  pcVar1 = (char *)luaL_checklstring((undefined4 *)0x0);
  lVar4 = -1;
  iVar2 = lua_isnumber();
  if (iVar2 == 0) {
    iVar2 = lua_isstring();
    if (iVar2 != 0) {
      luaL_optlstring("WHITE",(int *)0x0);
      lVar4 = GetColor(unaff_EDI);
    }
  }
  else {
    lVar4 = luaL_checkinteger();
  }
  uVar3 = lua_type();
  if ((int)uVar3 < 1) {
    in_XMM0_Qa = __real_4020000000000000;
  }
  else {
    luaL_checknumber();
  }
  ::AddObjective(pcVar1,lVar4,(float)in_XMM0_Qa);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::IsWithin  @ 4fc46fcf  lines 3309-3315


int __cdecl LuaBindings::IsWithin(lua_State *param_1)

{
  lua_State *plVar1;
  uint *puVar2;
  bool bVar3;
  int iVar4;
  int in_ECX;
  lua_State *unaff_ESI;
  undefined4 in_XMM0_Da;
  undefined4 in_XMM0_Db;
  int aiStackY_218 [128];
  
  plVar1 = param_1;
  iVar4 = RequireHandle(unaff_ESI,in_ECX);
  param_1 = (lua_State *)RequireHandle(unaff_ESI,iVar4);
  luaL_checknumber();
  bVar3 = ::IsWithin(aiStackY_218 + 0x84,(int *)&param_1,
                     (float)(double)CONCAT44(in_XMM0_Db,in_XMM0_Da));
  puVar2 = *(uint **)(plVar1 + 8);
  *puVar2 = (uint)bVar3;
  puVar2[1] = 0x7ff7a501;
  plVar1 = plVar1 + 8;
  *(int *)plVar1 = *(int *)plVar1 + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::CountUnitsNearObject  @ 4fc45bcd  lines 3319-3330


int __cdecl LuaBindings::CountUnitsNearObject(lua_State *param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int unaff_ESI;
  lua_State *unaff_EDI;
  char *pcVar4;
  double in_XMM0_Qa;
  
  pcVar4 = (char *)0x0;
  iVar3 = 0;
  uVar1 = lua_type();
  if (uVar1 != 0) {
    iVar3 = RequireHandle(unaff_EDI,unaff_ESI);
  }
  luaL_checknumber();
  iVar2 = luaL_checkinteger();
  uVar1 = lua_type();
  if (uVar1 != 0) {
    pcVar4 = (char *)luaL_checklstring((undefined4 *)0x0);
  }
  iVar3 = ::CountUnitsNearObject(iVar3,(float)in_XMM0_Qa,iVar2,pcVar4);
  **(double **)(param_1 + 8) = (double)iVar3;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::SetAvoidType  @ 4fc4a163  lines 3334-3339


int __cdecl LuaBindings::SetAvoidType(lua_State *param_1)

{
  int iVar1;
  int iVar2;
  int unaff_EBP;
  lua_State *unaff_ESI;
  
  iVar1 = RequireHandle(unaff_ESI,unaff_EBP);
  iVar2 = luaL_checkinteger();
  ::SetAvoidType(iVar1,iVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::Annoy  @ 4fc474cc  lines 3343-3348


int __cdecl LuaBindings::Annoy(lua_State *param_1)

{
  int iVar1;
  int iVar2;
  int unaff_EBP;
  lua_State *unaff_ESI;
  
  iVar1 = RequireHandle(unaff_ESI,unaff_EBP);
  iVar2 = RequireHandle(unaff_ESI,unaff_EBP);
  ::Annoy(iVar1,iVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::ClearThrust  @ 4fc46050  lines 3352-3356


int __cdecl LuaBindings::ClearThrust(lua_State *param_1)

{
  int iVar1;
  lua_State *unaff_EBP;
  int unaff_retaddr;
  
  iVar1 = RequireHandle(unaff_EBP,unaff_retaddr);
  ::ClearThrust(iVar1);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::SetVerbose  @ 4fc4b884  lines 3360-3365


int __cdecl LuaBindings::SetVerbose(lua_State *param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  lua_State *unaff_ESI;
  
  iVar1 = RequireHandle(unaff_ESI,in_ECX);
  iVar2 = lua_toboolean();
  ::SetVerbose(iVar1,iVar2 != 0);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::ClearIdleAnims  @ 4fc4eef8  lines 3369-3373


int __cdecl LuaBindings::ClearIdleAnims(lua_State *param_1)

{
  int iVar1;
  lua_State *unaff_EBP;
  int unaff_retaddr;
  
  iVar1 = RequireHandle(unaff_EBP,unaff_retaddr);
  ::ClearIdleAnims(iVar1);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::AddIdleAnim  @ 4fc4838b  lines 3377-3382


int __cdecl LuaBindings::AddIdleAnim(lua_State *param_1)

{
  int iVar1;
  char *pcVar2;
  int unaff_EBP;
  lua_State *unaff_ESI;
  
  iVar1 = RequireHandle(unaff_ESI,unaff_EBP);
  pcVar2 = (char *)luaL_checklstring((undefined4 *)0x0);
  ::AddIdleAnim(iVar1,pcVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::IsIdle  @ 4fc492b9  lines 3386-3390


int __cdecl LuaBindings::IsIdle(lua_State *param_1)

{
  uint *puVar1;
  bool bVar2;
  int iVar3;
  int unaff_EBP;
  lua_State *unaff_ESI;
  
  iVar3 = RequireHandle(unaff_ESI,unaff_EBP);
  bVar2 = ::IsIdle(iVar3);
  puVar1 = *(uint **)(param_1 + 8);
  *puVar1 = (uint)bVar2;
  puVar1[1] = 0x7ff7a501;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::CountThreats  @ 4fc499f9  lines 3394-3401


int __cdecl LuaBindings::CountThreats(lua_State *param_1)

{
  lua_State *plVar1;
  int iVar2;
  int in_ECX;
  lua_State *unaff_ESI;
  int aiStackY_218 [128];
  int iVar3;
  
  plVar1 = param_1;
  iVar2 = RequireHandle(unaff_ESI,in_ECX);
  param_1 = (lua_State *)0x0;
  iVar3 = 0;
  ::CountThreats(iVar2,(int *)&param_1,aiStackY_218 + 0x84);
  **(double **)(plVar1 + 8) = (double)(int)param_1;
  *(int *)(plVar1 + 8) = *(int *)(plVar1 + 8) + 8;
  **(double **)(plVar1 + 8) = (double)iVar3;
  *(int *)(plVar1 + 8) = *(int *)(plVar1 + 8) + 8;
  return 2;
}


// ---------------------------------------------------------------------
// LuaBindings::SpawnBirds  @ 4fc4bda3  lines 3406-3423


int __cdecl LuaBindings::SpawnBirds(lua_State *param_1)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  int iVar7;
  int unaff_ESI;
  lua_State *unaff_EDI;
  
  iVar1 = luaL_checkinteger();
  iVar2 = luaL_checkinteger();
  pcVar3 = (char *)luaL_checklstring((undefined4 *)0x0);
  iVar4 = luaL_checkinteger();
  iVar5 = lua_isstring();
  if (iVar5 == 0) {
    iVar5 = RequireHandle(unaff_EDI,unaff_ESI);
    iVar7 = RequireHandle(unaff_EDI,unaff_ESI);
    ::SpawnBirds(iVar1,iVar2,pcVar3,iVar4,iVar5,iVar7);
  }
  else {
    pcVar6 = (char *)lua_tolstring((undefined4 *)0x0);
    ::SpawnBirds(iVar1,iVar2,pcVar3,iVar4,pcVar6);
  }
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::RemoveBirds  @ 4fc46893  lines 3427-3431


int __cdecl LuaBindings::RemoveBirds(lua_State *param_1)

{
  int iVar1;
  
  iVar1 = luaL_checkinteger();
  ::RemoveBirds(iVar1);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::SetColorFade  @ 4fc49d6c  lines 3435-3445


int __cdecl LuaBindings::SetColorFade(lua_State *param_1)

{
  double dVar1;
  int iVar2;
  char *unaff_EDI;
  ulong uVar3;
  undefined4 in_XMM0_Da;
  float fVar4;
  undefined4 in_XMM0_Db;
  
  luaL_checknumber();
  dVar1 = (double)CONCAT44(in_XMM0_Db,in_XMM0_Da);
  fVar4 = (float)dVar1;
  luaL_checknumber();
  uVar3 = 0xffff4000;
  iVar2 = lua_isnumber();
  if (iVar2 == 0) {
    iVar2 = lua_isstring();
    if (iVar2 != 0) {
      luaL_optlstring("LAVACOLOR",(int *)0x0);
      uVar3 = GetColor(unaff_EDI);
    }
  }
  else {
    uVar3 = luaL_checkinteger();
  }
  ::SetColorFade((float)dVar1,(float)(double)CONCAT44(in_XMM0_Db,fVar4),uVar3);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::StopCheats  @ 4fc4c8e1  lines 3449-3452


int __cdecl LuaBindings::StopCheats(lua_State *param_1)

{
  ::StopCheats();
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::CalcCliffs  @ 4fc486d6  lines 3457-3471


int __cdecl LuaBindings::CalcCliffs(lua_State *param_1)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  int unaff_ESI;
  lua_State *unaff_EDI;
  undefined4 in_XMM0_Da;
  undefined4 in_XMM0_Db;
  
  iVar1 = lua_isstring();
  if (iVar1 == 0) {
    iVar1 = RequireHandle(unaff_EDI,unaff_ESI);
    iVar3 = RequireHandle(unaff_EDI,unaff_ESI);
    luaL_checknumber();
    ::CalcCliffs(iVar1,iVar3,(float)(double)CONCAT44(in_XMM0_Db,in_XMM0_Da));
  }
  else {
    pcVar2 = (char *)lua_tolstring((undefined4 *)0x0);
    ::CalcCliffs(pcVar2);
  }
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::StartSoundEffect  @ 4fc4e28e  lines 3475-3480


int __cdecl LuaBindings::StartSoundEffect(lua_State *param_1)

{
  char *pcVar1;
  uint uVar2;
  int iVar3;
  
  pcVar1 = (char *)luaL_checklstring((undefined4 *)0x0);
  uVar2 = luaL_testudata();
  iVar3 = ::StartSoundEffect(pcVar1,uVar2);
  **(double **)(param_1 + 8) = (double)iVar3;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::FindSoundEffect  @ 4fc4d0e3  lines 3484-3489


int __cdecl LuaBindings::FindSoundEffect(lua_State *param_1)

{
  char *pcVar1;
  uint uVar2;
  int iVar3;
  
  pcVar1 = (char *)luaL_checklstring((undefined4 *)0x0);
  uVar2 = luaL_testudata();
  iVar3 = ::FindSoundEffect(pcVar1,uVar2);
  **(double **)(param_1 + 8) = (double)iVar3;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::StopSoundEffect  @ 4fc46b9b  lines 3493-3497


int __cdecl LuaBindings::StopSoundEffect(lua_State *param_1)

{
  int iVar1;
  
  iVar1 = luaL_checkinteger();
  ::StopSoundEffect(iVar1);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::GetObjectByTeamSlot  @ 4fc4cb9b  lines 3502-3517


int __cdecl LuaBindings::GetObjectByTeamSlot(lua_State *param_1)

{
  int iVar1;
  int iVar2;
  int unaff_EBX;
  lua_State *unaff_ESI;
  
  iVar1 = lua_isnumber();
  iVar2 = luaL_checkinteger();
  if (iVar1 == 0) {
    iVar1 = iVar2;
    iVar2 = ::GetLocalPlayerTeamNumber();
  }
  else {
    iVar1 = luaL_checkinteger();
  }
  ::GetObjectByTeamSlot(iVar2,iVar1);
  PushHandle(unaff_ESI,unaff_EBX);
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::IsNetworkOn  @ 4fc45e38  lines 3521-3524


int __cdecl LuaBindings::IsNetworkOn(lua_State *param_1)

{
  uint *puVar1;
  bool bVar2;
  
  bVar2 = ::IsNetworkOn();
  puVar1 = *(uint **)(param_1 + 8);
  *puVar1 = (uint)bVar2;
  puVar1[1] = 0x7ff7a501;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::ImServer  @ 4fc4c8ea  lines 3528-3531


int __cdecl LuaBindings::ImServer(lua_State *param_1)

{
  uint *puVar1;
  bool bVar2;
  
  bVar2 = ::ImServer();
  puVar1 = *(uint **)(param_1 + 8);
  *puVar1 = (uint)bVar2;
  puVar1[1] = 0x7ff7a501;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::ImDedicatedServer  @ 4fc45333  lines 3535-3538


int __cdecl LuaBindings::ImDedicatedServer(lua_State *param_1)

{
  uint *puVar1;
  bool bVar2;
  
  bVar2 = ::ImDedicatedServer();
  puVar1 = *(uint **)(param_1 + 8);
  *puVar1 = (uint)bVar2;
  puVar1[1] = 0x7ff7a501;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::IsTeamplayOn  @ 4fc4bd1f  lines 3542-3545


int __cdecl LuaBindings::IsTeamplayOn(lua_State *param_1)

{
  uint *puVar1;
  bool bVar2;
  
  bVar2 = ::IsTeamplayOn();
  puVar1 = *(uint **)(param_1 + 8);
  *puVar1 = (uint)bVar2;
  puVar1[1] = 0x7ff7a501;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::CountPlayers  @ 4fc49abc  lines 3549-3552


int __cdecl LuaBindings::CountPlayers(lua_State *param_1)

{
  double *pdVar1;
  int iVar2;
  
  iVar2 = ::CountPlayers();
  pdVar1 = *(double **)(param_1 + 8);
  *pdVar1 = (double)iVar2;
  *(double **)(param_1 + 8) = pdVar1 + 1;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetRaceOfTeam  @ 4fc4b020  lines 3556-3564


int __cdecl LuaBindings::GetRaceOfTeam(lua_State *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = luaL_checkinteger();
  cVar1 = ::GetRaceOfTeam(iVar2);
  if (cVar1 == '\0') {
    *(undefined4 *)(*(int *)(param_1 + 8) + 4) = 0x7ff7a500;
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  }
  else {
    lua_pushlstring(1);
  }
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::IsPlayer  @ 4fc4a03f  lines 3568-3572


int __cdecl LuaBindings::IsPlayer(lua_State *param_1)

{
  uint *puVar1;
  bool bVar2;
  int iVar3;
  int unaff_EBP;
  lua_State *unaff_ESI;
  
  iVar3 = RequireHandle(unaff_ESI,unaff_EBP);
  bVar2 = ::IsPlayer(iVar3);
  puVar1 = *(uint **)(param_1 + 8);
  *puVar1 = (uint)bVar2;
  puVar1[1] = 0x7ff7a501;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetPlayerName  @ 4fc4b8b8  lines 3576-3581


int __cdecl LuaBindings::GetPlayerName(lua_State *param_1)

{
  int iVar1;
  lua_State *unaff_EBP;
  int unaff_retaddr;
  
  iVar1 = RequireHandle(unaff_EBP,unaff_retaddr);
  ::GetPlayerName(iVar1);
  lua_pushstring();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::WhichTeamGroup  @ 4fc4fd27  lines 3585-3589


int __cdecl LuaBindings::WhichTeamGroup(lua_State *param_1)

{
  int iVar1;
  
  iVar1 = luaL_checkinteger();
  iVar1 = ::WhichTeamGroup(iVar1);
  **(double **)(param_1 + 8) = (double)iVar1;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::CountAllies  @ 4fc4ae6e  lines 3593-3597


int __cdecl LuaBindings::CountAllies(lua_State *param_1)

{
  int iVar1;
  
  iVar1 = luaL_checkinteger();
  iVar1 = ::CountAllies(iVar1);
  **(double **)(param_1 + 8) = (double)iVar1;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetCommanderTeam  @ 4fc4c687  lines 3601-3605


int __cdecl LuaBindings::GetCommanderTeam(lua_State *param_1)

{
  int iVar1;
  
  iVar1 = luaL_checkinteger();
  iVar1 = ::GetCommanderTeam(iVar1);
  **(double **)(param_1 + 8) = (double)iVar1;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetFirstAlliedTeam  @ 4fc4e802  lines 3609-3613


int __cdecl LuaBindings::GetFirstAlliedTeam(lua_State *param_1)

{
  int iVar1;
  
  iVar1 = luaL_checkinteger();
  iVar1 = ::GetFirstAlliedTeam(iVar1);
  **(double **)(param_1 + 8) = (double)iVar1;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetLastAlliedTeam  @ 4fc4a46b  lines 3617-3621


int __cdecl LuaBindings::GetLastAlliedTeam(lua_State *param_1)

{
  int iVar1;
  
  iVar1 = luaL_checkinteger();
  iVar1 = ::GetLastAlliedTeam(iVar1);
  **(double **)(param_1 + 8) = (double)iVar1;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetTeamplayRanges  @ 4fc489a1  lines 3625-3633


int __cdecl LuaBindings::GetTeamplayRanges(lua_State *param_1)

{
  int iVar1;
  int local_14 [4];
  
  iVar1 = luaL_checkinteger();
  local_14[0] = 0;
  local_14[1] = 0;
  local_14[2] = 0;
  ::GetTeamplayRanges(iVar1,local_14,local_14 + 1,local_14 + 2);
  lua_pushnumber();
  lua_pushnumber();
  lua_pushnumber();
  return 3;
}


// ---------------------------------------------------------------------
// LuaBindings::SetRandomHeadingAngle  @ 4fc5054d  lines 3637-3641


int __cdecl LuaBindings::SetRandomHeadingAngle(lua_State *param_1)

{
  int iVar1;
  lua_State *unaff_EBP;
  int unaff_retaddr;
  
  iVar1 = RequireHandle(unaff_EBP,unaff_retaddr);
  ::SetRandomHeadingAngle(iVar1);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::ClearTeamColors  @ 4fc49d2d  lines 3645-3648


int __cdecl LuaBindings::ClearTeamColors(lua_State *param_1)

{
  ::ClearTeamColors();
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::DefaultTeamColors  @ 4fc4e2da  lines 3652-3655


int __cdecl LuaBindings::DefaultTeamColors(lua_State *param_1)

{
  ::DefaultTeamColors();
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::TeamplayTeamColors  @ 4fc4eeef  lines 3659-3662


int __cdecl LuaBindings::TeamplayTeamColors(lua_State *param_1)

{
  ::TeamplayTeamColors();
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::SetTeamColor  @ 4fc4df36  lines 3666-3681


int __cdecl LuaBindings::SetTeamColor(lua_State *param_1)

{
  int iVar1;
  float *pfVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar1 = luaL_checkinteger();
  pfVar2 = (float *)luaL_testudata();
  if (pfVar2 == (float *)0x0) {
    iVar5 = luaL_checkinteger();
    iVar4 = luaL_checkinteger();
    iVar3 = luaL_checkinteger();
  }
  else {
    iVar3 = (int)pfVar2[2];
    iVar4 = (int)pfVar2[1];
    iVar5 = (int)*pfVar2;
  }
  ::SetTeamColor(iVar1,iVar5,iVar4,iVar3);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::ClearTeamColor  @ 4fc4adee  lines 3685-3689


int __cdecl LuaBindings::ClearTeamColor(lua_State *param_1)

{
  int iVar1;
  
  iVar1 = luaL_checkinteger();
  ::ClearTeamColor(iVar1);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::MakeInert  @ 4fc45fc5  lines 3693-3697


int __cdecl LuaBindings::MakeInert(lua_State *param_1)

{
  int iVar1;
  lua_State *unaff_EBP;
  int unaff_retaddr;
  
  iVar1 = RequireHandle(unaff_EBP,unaff_retaddr);
  ::MakeInert(iVar1);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::GetPositionNear  @ 4fc47b88  lines 3704-3742


int __cdecl LuaBindings::GetPositionNear(lua_State *param_1)

{
  Vector VVar1;
  Vector VVar2;
  uint uVar3;
  undefined4 *puVar4;
  Vector *pVVar5;
  Vector *pVVar6;
  int iVar7;
  int unaff_ESI;
  lua_State *unaff_EDI;
  undefined4 *puVar8;
  float fVar9;
  undefined8 uVar10;
  double dVar11;
  undefined4 uVar12;
  float fVar13;
  undefined4 uVar14;
  Vector local_78;
  Vector local_68;
  Vector local_58;
  undefined4 local_48 [12];
  undefined4 local_18;
  undefined4 uStack_14;
  float fStack_10;
  
  uVar3 = lua_type();
  uVar10 = 0;
  local_78._0_8_ = 0.0;
  if ((int)uVar3 < 1) {
    uVar12 = 0;
    uVar14 = 0;
  }
  else {
    luaL_checknumber();
    uVar12 = (undefined4)uVar10;
    uVar14 = (undefined4)((ulonglong)uVar10 >> 0x20);
  }
  dVar11 = 0.0;
  fVar13 = (float)(double)CONCAT44(uVar14,uVar12);
  uVar3 = lua_type();
  if (0 < (int)uVar3) {
    luaL_checknumber();
  }
  fVar9 = (float)dVar11;
  dVar11 = (double)CONCAT44((int)((ulonglong)dVar11 >> 0x20),fVar9);
  puVar4 = (undefined4 *)luaL_testudata();
  if (puVar4 == (undefined4 *)0x0) {
    pVVar6 = (Vector *)luaL_testudata();
    if (pVVar6 == (Vector *)0x0) {
      iVar7 = lua_isstring();
      if (iVar7 == 0) {
        iVar7 = RequireHandle(unaff_EDI,unaff_ESI);
        ::GetPosition(iVar7,&local_68);
        VVar2.y = local_68.y;
        VVar2.x = local_68.x;
        VVar2.z = local_68.z;
        ::GetPositionNear(&local_78,VVar2,fVar13,fVar9);
        local_58.x = local_78.x;
        local_58.y = local_78.y;
        local_58.z = local_78.z;
        pVVar5 = NewVector(unaff_EDI);
        pVVar6 = &local_58;
      }
      else {
        pVVar6 = (Vector *)0x0;
        lua_tolstring((undefined4 *)0x0);
        iVar7 = lua_isnumber();
        uVar3 = lua_type();
        if (iVar7 == 0) {
          if ((int)uVar3 < 1) {
            dVar11 = 0.0;
          }
          else {
            luaL_checknumber();
          }
          fVar13 = (float)dVar11;
          dVar11 = (double)CONCAT44((int)((ulonglong)dVar11 >> 0x20),fVar13);
          uVar3 = lua_type();
        }
        else {
          if (0 < (int)uVar3) {
            pVVar6 = (Vector *)luaL_checkinteger();
          }
          uVar3 = lua_type();
          if ((int)uVar3 < 1) {
            dVar11 = 0.0;
          }
          else {
            luaL_checknumber();
          }
          fVar13 = (float)dVar11;
          dVar11 = (double)CONCAT44((int)((ulonglong)dVar11 >> 0x20),fVar13);
          uVar3 = lua_type();
        }
        if (0 < (int)uVar3) {
          luaL_checknumber();
          local_78._0_8_ = dVar11;
        }
        pVVar6 = GetVectorFromPath(pVVar6,(char *)unaff_EDI,unaff_ESI);
        ::GetPositionNear(&local_68,*pVVar6,fVar13,(float)(double)local_78._0_8_);
        local_78.z = local_68.z;
        pVVar5 = NewVector(unaff_EDI);
        pVVar6 = &local_78;
      }
      goto LAB_4fc47e15;
    }
    pVVar6 = ::GetPositionNear(&local_58,*pVVar6,fVar13,fVar9);
  }
  else {
    puVar8 = local_48;
    for (iVar7 = 0x10; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar8 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar8 = puVar8 + 1;
    }
    VVar1.y = (float)uStack_14;
    VVar1.x = (float)local_18;
    VVar1.z = fStack_10;
    ::GetPositionNear(&local_78,VVar1,fVar13,fVar9);
    pVVar6 = &local_78;
  }
  local_68.x = pVVar6->x;
  local_68.y = pVVar6->y;
  local_68.z = pVVar6->z;
  pVVar5 = NewVector(unaff_EDI);
  pVVar6 = &local_68;
LAB_4fc47e15:
  pVVar5->x = pVVar6->x;
  pVVar5->y = pVVar6->y;
  pVVar5->z = pVVar6->z;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetPlayerODF  @ 4fc44f2b  lines 3746-3752


int __cdecl LuaBindings::GetPlayerODF(lua_State *param_1)

{
  int iVar1;
  uint uVar2;
  RandomizeType RVar3;
  
  iVar1 = luaL_checkinteger();
  uVar2 = lua_type();
  if ((int)uVar2 < 1) {
    RVar3 = Randomize_None;
  }
  else {
    RVar3 = luaL_checkinteger();
  }
  ::GetPlayerODF(iVar1,RVar3);
  lua_pushstring();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::BuildEmptyCraftNear  @ 4fc44ffe  lines 3756-3764


int __cdecl LuaBindings::BuildEmptyCraftNear(lua_State *param_1)

{
  double dVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  int unaff_ESI;
  lua_State *unaff_EDI;
  undefined4 in_XMM0_Da;
  float fVar5;
  undefined4 in_XMM0_Db;
  
  iVar2 = RequireHandle(unaff_EDI,unaff_ESI);
  pcVar3 = (char *)luaL_checklstring((undefined4 *)0x0);
  iVar4 = luaL_checkinteger();
  luaL_checknumber();
  dVar1 = (double)CONCAT44(in_XMM0_Db,in_XMM0_Da);
  fVar5 = (float)dVar1;
  luaL_checknumber();
  ::BuildEmptyCraftNear(iVar2,pcVar3,iVar4,(float)dVar1,(float)(double)CONCAT44(in_XMM0_Db,fVar5));
  PushHandle(unaff_EDI,unaff_ESI);
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetCircularPos  @ 4fc4c70c  lines 3768-3777


int __cdecl LuaBindings::GetCircularPos(lua_State *param_1)

{
  double dVar1;
  Vector *pVVar2;
  uint uVar3;
  int iVar4;
  lua_State *unaff_EDI;
  undefined4 in_XMM0_Da;
  float fVar5;
  undefined4 in_XMM0_Db;
  float fVar6;
  undefined4 uVar7;
  Vector local_24;
  float local_18;
  float fStack_14;
  float fStack_10;
  
  pVVar2 = (Vector *)luaL_testudata();
  if (pVVar2 == (Vector *)0x0) {
    iVar4 = 0;
  }
  else {
    uVar3 = lua_type();
    if ((int)uVar3 < 1) {
      in_XMM0_Da = 0;
      in_XMM0_Db = 0;
    }
    else {
      luaL_checknumber();
    }
    uVar7 = 0;
    fVar6 = 0.0;
    dVar1 = (double)CONCAT44(in_XMM0_Db,in_XMM0_Da);
    fVar5 = (float)dVar1;
    uVar3 = lua_type();
    if (0 < (int)uVar3) {
      luaL_checknumber();
      fVar6 = fVar5;
      uVar7 = in_XMM0_Db;
    }
    local_24.x = 0.0;
    local_24.y = 0.0;
    local_24.z = 0.0;
    SetCircularPos(pVVar2,(float)dVar1,(float)(double)CONCAT44(uVar7,fVar6),&local_24);
    local_18 = local_24.x;
    fStack_14 = local_24.y;
    fStack_10 = local_24.z;
    pVVar2 = NewVector(unaff_EDI);
    iVar4 = 1;
    pVVar2->x = local_18;
    pVVar2->y = fStack_14;
    pVVar2->z = fStack_10;
  }
  return iVar4;
}


// ---------------------------------------------------------------------
// LuaBindings::GetSafestSpawnpoint  @ 4fc45117  lines 3781-3784


int __cdecl LuaBindings::GetSafestSpawnpoint(lua_State *param_1)

{
  Vector *pVVar1;
  lua_State *unaff_EDI;
  Vector local_1c;
  float local_10;
  float fStack_c;
  float fStack_8;
  
  pVVar1 = ::GetSafestSpawnpoint(&local_1c);
  local_10 = pVVar1->x;
  fStack_c = pVVar1->y;
  fStack_8 = pVVar1->z;
  pVVar1 = NewVector(unaff_EDI);
  pVVar1->x = local_10;
  pVVar1->y = fStack_c;
  pVVar1->z = fStack_8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetSpawnpoint  @ 4fc4c520  lines 3788-3792


int __cdecl LuaBindings::GetSpawnpoint(lua_State *param_1)

{
  int iVar1;
  Vector *pVVar2;
  lua_State *unaff_EDI;
  Vector local_1c;
  float local_10;
  float fStack_c;
  float fStack_8;
  
  iVar1 = luaL_checkinteger();
  pVVar2 = ::GetSpawnpoint(&local_1c,iVar1);
  local_10 = pVVar2->x;
  fStack_c = pVVar2->y;
  fStack_8 = pVVar2->z;
  pVVar2 = NewVector(unaff_EDI);
  pVVar2->x = local_10;
  pVVar2->y = fStack_c;
  pVVar2->z = fStack_8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetSpawnpointHandle  @ 4fc4fb19  lines 3796-3800


int __cdecl LuaBindings::GetSpawnpointHandle(lua_State *param_1)

{
  int iVar1;
  lua_State *unaff_EBP;
  int unaff_retaddr;
  
  iVar1 = luaL_checkinteger();
  ::GetSpawnpointHandle(iVar1);
  PushHandle(unaff_EBP,unaff_retaddr);
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetRandomSpawnpoint  @ 4fc4c6b9  lines 3804-3808


int __cdecl LuaBindings::GetRandomSpawnpoint(lua_State *param_1)

{
  uint uVar1;
  int iVar2;
  Vector *pVVar3;
  lua_State *unaff_EDI;
  Vector local_1c;
  float local_10;
  float fStack_c;
  float fStack_8;
  
  uVar1 = lua_type();
  if ((int)uVar1 < 1) {
    iVar2 = -1;
  }
  else {
    iVar2 = luaL_checkinteger();
  }
  pVVar3 = ::GetRandomSpawnpoint(&local_1c,iVar2);
  local_10 = pVVar3->x;
  fStack_c = pVVar3->y;
  fStack_8 = pVVar3->z;
  pVVar3 = NewVector(unaff_EDI);
  pVVar3->x = local_10;
  pVVar3->y = fStack_c;
  pVVar3->z = fStack_8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::SetTimerBox  @ 4fc49a53  lines 3812-3816


int __cdecl LuaBindings::SetTimerBox(lua_State *param_1)

{
  char *pcVar1;
  
  pcVar1 = (char *)luaL_checklstring((undefined4 *)0x0);
  ::SetTimerBox(pcVar1);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::AddToMessagesBox  @ 4fc4d29e  lines 3821-3838


int __cdecl LuaBindings::AddToMessagesBox(lua_State *param_1)

{
  char *pcVar1;
  int iVar2;
  ulong uVar3;
  char *pcVar4;
  
  pcVar1 = (char *)luaL_checklstring((undefined4 *)0x0);
  iVar2 = lua_isnumber();
  if (iVar2 == 0) {
    iVar2 = lua_isstring();
    if (iVar2 == 0) {
      ::AddToMessagesBox(pcVar1);
      return 0;
    }
    pcVar4 = (char *)0x0;
    lua_tolstring((undefined4 *)0x0);
    uVar3 = GetColor(pcVar4);
  }
  else {
    uVar3 = lua_tointegerx((undefined4 *)0x0);
  }
  AddToMessagesBox2(pcVar1,uVar3);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::GetDeaths  @ 4fc4c8af  lines 3842-3846


int __cdecl LuaBindings::GetDeaths(lua_State *param_1)

{
  int iVar1;
  int unaff_EBP;
  lua_State *unaff_ESI;
  
  iVar1 = RequireHandle(unaff_ESI,unaff_EBP);
  iVar1 = ::GetDeaths(iVar1);
  **(double **)(param_1 + 8) = (double)iVar1;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetKills  @ 4fc4749a  lines 3850-3854


int __cdecl LuaBindings::GetKills(lua_State *param_1)

{
  int iVar1;
  int unaff_EBP;
  lua_State *unaff_ESI;
  
  iVar1 = RequireHandle(unaff_ESI,unaff_EBP);
  iVar1 = ::GetKills(iVar1);
  **(double **)(param_1 + 8) = (double)iVar1;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetScore  @ 4fc49ca8  lines 3858-3862


int __cdecl LuaBindings::GetScore(lua_State *param_1)

{
  int iVar1;
  int unaff_EBP;
  lua_State *unaff_ESI;
  
  iVar1 = RequireHandle(unaff_ESI,unaff_EBP);
  iVar1 = ::GetScore(iVar1);
  **(double **)(param_1 + 8) = (double)iVar1;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::SetDeaths  @ 4fc4b099  lines 3866-3871


int __cdecl LuaBindings::SetDeaths(lua_State *param_1)

{
  int iVar1;
  int iVar2;
  int unaff_EBP;
  lua_State *unaff_ESI;
  
  iVar1 = RequireHandle(unaff_ESI,unaff_EBP);
  iVar2 = luaL_checkinteger();
  ::SetDeaths(iVar1,iVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::SetKills  @ 4fc46352  lines 3875-3880


int __cdecl LuaBindings::SetKills(lua_State *param_1)

{
  int iVar1;
  int iVar2;
  int unaff_EBP;
  lua_State *unaff_ESI;
  
  iVar1 = RequireHandle(unaff_ESI,unaff_EBP);
  iVar2 = luaL_checkinteger();
  ::SetKills(iVar1,iVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::SetScore  @ 4fc4df02  lines 3884-3889


int __cdecl LuaBindings::SetScore(lua_State *param_1)

{
  int iVar1;
  int iVar2;
  int unaff_EBP;
  lua_State *unaff_ESI;
  
  iVar1 = RequireHandle(unaff_ESI,unaff_EBP);
  iVar2 = luaL_checkinteger();
  ::SetScore(iVar1,iVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::AddDeaths  @ 4fc4f694  lines 3893-3898


int __cdecl LuaBindings::AddDeaths(lua_State *param_1)

{
  int iVar1;
  int iVar2;
  int unaff_EBP;
  lua_State *unaff_ESI;
  
  iVar1 = RequireHandle(unaff_ESI,unaff_EBP);
  iVar2 = luaL_checkinteger();
  ::AddDeaths(iVar1,iVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::AddKills  @ 4fc4f965  lines 3902-3907


int __cdecl LuaBindings::AddKills(lua_State *param_1)

{
  int iVar1;
  int iVar2;
  int unaff_EBP;
  lua_State *unaff_ESI;
  
  iVar1 = RequireHandle(unaff_ESI,unaff_EBP);
  iVar2 = luaL_checkinteger();
  ::AddKills(iVar1,iVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::AddScore  @ 4fc4606a  lines 3911-3916


int __cdecl LuaBindings::AddScore(lua_State *param_1)

{
  int iVar1;
  int iVar2;
  int unaff_EBP;
  lua_State *unaff_ESI;
  
  iVar1 = RequireHandle(unaff_ESI,unaff_EBP);
  iVar2 = luaL_checkinteger();
  ::AddScore(iVar1,iVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::SetAsUser  @ 4fc4a341  lines 3920-3925


int __cdecl LuaBindings::SetAsUser(lua_State *param_1)

{
  int iVar1;
  int iVar2;
  int unaff_EBP;
  lua_State *unaff_ESI;
  
  iVar1 = RequireHandle(unaff_ESI,unaff_EBP);
  iVar2 = luaL_checkinteger();
  ::SetAsUser(iVar1,iVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::SetNoScrapFlagByHandle  @ 4fc4d04f  lines 3929-3933


int __cdecl LuaBindings::SetNoScrapFlagByHandle(lua_State *param_1)

{
  int iVar1;
  lua_State *unaff_EBP;
  int unaff_retaddr;
  
  iVar1 = RequireHandle(unaff_EBP,unaff_retaddr);
  ::SetNoScrapFlagByHandle(iVar1);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::ClearNoScrapFlagByHandle  @ 4fc44dcb  lines 3937-3941


int __cdecl LuaBindings::ClearNoScrapFlagByHandle(lua_State *param_1)

{
  int iVar1;
  lua_State *unaff_EBP;
  int unaff_retaddr;
  
  iVar1 = RequireHandle(unaff_EBP,unaff_retaddr);
  ::ClearNoScrapFlagByHandle(iVar1);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::GetLocalPlayerTeamNumber  @ 4fc4cfe7  lines 3945-3948


int __cdecl LuaBindings::GetLocalPlayerTeamNumber(lua_State *param_1)

{
  double *pdVar1;
  int iVar2;
  
  iVar2 = ::GetLocalPlayerTeamNumber();
  pdVar1 = *(double **)(param_1 + 8);
  *pdVar1 = (double)iVar2;
  *(double **)(param_1 + 8) = pdVar1 + 1;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetLocalPlayerDPID  @ 4fc4de89  lines 3952-3955


int __cdecl LuaBindings::GetLocalPlayerDPID(lua_State *param_1)

{
  double *pdVar1;
  ulong uVar2;
  
  uVar2 = ::GetLocalPlayerDPID();
  pdVar1 = *(double **)(param_1 + 8);
  *pdVar1 = (double)(int)uVar2;
  *(double **)(param_1 + 8) = pdVar1 + 1;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::FlagSteal  @ 4fc4d78c  lines 3959-3964


int __cdecl LuaBindings::FlagSteal(lua_State *param_1)

{
  int iVar1;
  int iVar2;
  int unaff_EBP;
  lua_State *unaff_ESI;
  
  iVar1 = RequireHandle(unaff_ESI,unaff_EBP);
  iVar2 = RequireHandle(unaff_ESI,unaff_EBP);
  ::FlagSteal(iVar1,iVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::FlagRecover  @ 4fc463a3  lines 3968-3973


int __cdecl LuaBindings::FlagRecover(lua_State *param_1)

{
  int iVar1;
  int iVar2;
  int unaff_EBP;
  lua_State *unaff_ESI;
  
  iVar1 = RequireHandle(unaff_ESI,unaff_EBP);
  iVar2 = RequireHandle(unaff_ESI,unaff_EBP);
  ::FlagRecover(iVar1,iVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::FlagScore  @ 4fc46a1d  lines 3977-3982


int __cdecl LuaBindings::FlagScore(lua_State *param_1)

{
  int iVar1;
  int iVar2;
  int unaff_EBP;
  lua_State *unaff_ESI;
  
  iVar1 = RequireHandle(unaff_ESI,unaff_EBP);
  iVar2 = RequireHandle(unaff_ESI,unaff_EBP);
  ::FlagScore(iVar1,iVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::MoneyScore  @ 4fc4f990  lines 3986-3991


int __cdecl LuaBindings::MoneyScore(lua_State *param_1)

{
  int iVar1;
  int iVar2;
  int unaff_EBP;
  lua_State *unaff_ESI;
  
  iVar1 = luaL_checkinteger();
  iVar2 = RequireHandle(unaff_ESI,unaff_EBP);
  ::MoneyScore(iVar1,iVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::NoteGameoverByTimelimit  @ 4fc4d7b7  lines 3995-3998


int __cdecl LuaBindings::NoteGameoverByTimelimit(lua_State *param_1)

{
  ::NoteGameoverByTimelimit();
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::NoteGameoverByKillLimit  @ 4fc50567  lines 4002-4006


int __cdecl LuaBindings::NoteGameoverByKillLimit(lua_State *param_1)

{
  int iVar1;
  lua_State *unaff_EBP;
  int unaff_retaddr;
  
  iVar1 = RequireHandle(unaff_EBP,unaff_retaddr);
  ::NoteGameoverByKillLimit(iVar1);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::NoteGameoverByScore  @ 4fc4951f  lines 4010-4014


int __cdecl LuaBindings::NoteGameoverByScore(lua_State *param_1)

{
  int iVar1;
  lua_State *unaff_EBP;
  int unaff_retaddr;
  
  iVar1 = RequireHandle(unaff_EBP,unaff_retaddr);
  ::NoteGameoverByScore(iVar1);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::NoteGameoverByLastWithBase  @ 4fc4c2b7  lines 4018-4022


int __cdecl LuaBindings::NoteGameoverByLastWithBase(lua_State *param_1)

{
  int iVar1;
  lua_State *unaff_EBP;
  int unaff_retaddr;
  
  iVar1 = RequireHandle(unaff_EBP,unaff_retaddr);
  ::NoteGameoverByLastWithBase(iVar1);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::NoteGameoverByLastTeamWithBase  @ 4fc4eb0f  lines 4026-4030


int __cdecl LuaBindings::NoteGameoverByLastTeamWithBase(lua_State *param_1)

{
  int iVar1;
  
  iVar1 = luaL_checkinteger();
  ::NoteGameoverByLastTeamWithBase(iVar1);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::NoteGameoverByNoBases  @ 4fc4af7a  lines 4034-4037


int __cdecl LuaBindings::NoteGameoverByNoBases(lua_State *param_1)

{
  ::NoteGameoverByNoBases();
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::DoGameover  @ 4fc45983  lines 4041-4045


int __cdecl LuaBindings::DoGameover(lua_State *param_1)

{
  undefined4 in_XMM0_Da;
  undefined4 in_XMM0_Db;
  
  luaL_checknumber();
  ::DoGameover((float)(double)CONCAT44(in_XMM0_Db,in_XMM0_Da));
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::SetMPTeamRace  @ 4fc4b064  lines 4049-4056


int __cdecl LuaBindings::SetMPTeamRace(lua_State *param_1)

{
  int iVar1;
  char *pcVar2;
  
  iVar1 = luaL_checkinteger();
  pcVar2 = (char *)luaL_checklstring((undefined4 *)0x0);
  if (pcVar2 != (char *)0x0) {
    ::SetMPTeamRace(iVar1,*pcVar2);
  }
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::GetTarget  @ 4fc49f00  lines 4060-4065


int __cdecl LuaBindings::GetTarget(lua_State *param_1)

{
  int iVar1;
  lua_State *unaff_EBP;
  int unaff_retaddr;
  
  iVar1 = RequireHandle(unaff_EBP,unaff_retaddr);
  ::GetTarget(iVar1);
  PushHandle(unaff_EBP,unaff_retaddr);
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::IFace_ConsoleCmd  @ 4fc4926e  lines 4069-4074


int __cdecl LuaBindings::IFace_ConsoleCmd(lua_State *param_1)

{
  char *pcVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = 1;
  pcVar1 = (char *)luaL_checklstring((undefined4 *)0x0);
  uVar2 = lua_type();
  if (0 < (int)uVar2) {
    iVar3 = lua_toboolean();
  }
  ::IFace_ConsoleCmd(pcVar1,iVar3 != 0);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::Network_SetString  @ 4fc46863  lines 4078-4083


int __cdecl LuaBindings::Network_SetString(lua_State *param_1)

{
  char *pcVar1;
  char *pcVar2;
  
  pcVar1 = (char *)luaL_checklstring((undefined4 *)0x0);
  pcVar2 = (char *)luaL_checklstring((undefined4 *)0x0);
  ::Network_SetString(pcVar1,pcVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::Network_SetInteger  @ 4fc4b637  lines 4087-4092


int __cdecl LuaBindings::Network_SetInteger(lua_State *param_1)

{
  char *pcVar1;
  int iVar2;
  
  pcVar1 = (char *)luaL_checklstring((undefined4 *)0x0);
  iVar2 = luaL_checkinteger();
  ::Network_SetInteger(pcVar1,iVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::GetVelocity  @ 4fc504e9  lines 4096-4100


int __cdecl LuaBindings::GetVelocity(lua_State *param_1)

{
  int iVar1;
  Vector *pVVar2;
  int unaff_ESI;
  lua_State *unaff_EDI;
  Vector local_1c;
  float local_10;
  float fStack_c;
  float fStack_8;
  
  iVar1 = RequireHandle(unaff_EDI,unaff_ESI);
  pVVar2 = ::GetVelocity(&local_1c,iVar1);
  local_10 = pVVar2->x;
  fStack_c = pVVar2->y;
  fStack_8 = pVVar2->z;
  pVVar2 = NewVector(unaff_EDI);
  pVVar2->x = local_10;
  pVVar2->y = fStack_c;
  pVVar2->z = fStack_8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetObjInfo_CFG  @ 4fc49443  lines 4130-4138


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl LuaBindings::GetObjInfo_CFG(lua_State *param_1)

{
  bool bVar1;
  uint uVar2;
  char local_48 [64];
  undefined4 local_8;
  
  local_8 = __security_cookie ^ (uint)(local_48 + 0x44);
  uVar2 = luaL_testudata();
  memset(local_48,0,0x40);
  bVar1 = GetObjInfo(uVar2,Get_CFG,local_48);
  if (bVar1) {
    lua_pushstring();
  }
  else {
    *(undefined4 *)(*(int *)(param_1 + 8) + 4) = 0x7ff7a500;
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  }
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetObjInfo_ODF  @ 4fc4f81b  lines 4142-4150


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl LuaBindings::GetObjInfo_ODF(lua_State *param_1)

{
  bool bVar1;
  uint uVar2;
  char local_48 [64];
  undefined4 local_8;
  
  local_8 = __security_cookie ^ (uint)(local_48 + 0x44);
  uVar2 = luaL_testudata();
  memset(local_48,0,0x40);
  bVar1 = GetObjInfo(uVar2,Get_ODF,local_48);
  if (bVar1) {
    lua_pushstring();
  }
  else {
    *(undefined4 *)(*(int *)(param_1 + 8) + 4) = 0x7ff7a500;
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  }
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetObjInfo_GOClass_gCfg  @ 4fc4f320  lines 4154-4162


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl LuaBindings::GetObjInfo_GOClass_gCfg(lua_State *param_1)

{
  bool bVar1;
  uint uVar2;
  char local_48 [64];
  undefined4 local_8;
  
  local_8 = __security_cookie ^ (uint)(local_48 + 0x44);
  uVar2 = luaL_testudata();
  memset(local_48,0,0x40);
  bVar1 = GetObjInfo(uVar2,Get_GOClass_gCfg,local_48);
  if (bVar1) {
    lua_pushstring();
  }
  else {
    *(undefined4 *)(*(int *)(param_1 + 8) + 4) = 0x7ff7a500;
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  }
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetObjInfo_EntityType  @ 4fc46a48  lines 4166-4174


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl LuaBindings::GetObjInfo_EntityType(lua_State *param_1)

{
  bool bVar1;
  uint uVar2;
  char local_48 [64];
  undefined4 local_8;
  
  local_8 = __security_cookie ^ (uint)(local_48 + 0x44);
  uVar2 = luaL_testudata();
  memset(local_48,0,0x40);
  bVar1 = GetObjInfo(uVar2,Get_EntityType,local_48);
  if (bVar1) {
    lua_pushstring();
  }
  else {
    *(undefined4 *)(*(int *)(param_1 + 8) + 4) = 0x7ff7a500;
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  }
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetObjInfo_GOClass  @ 4fc4b1c0  lines 4178-4186


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl LuaBindings::GetObjInfo_GOClass(lua_State *param_1)

{
  bool bVar1;
  uint uVar2;
  char local_48 [64];
  undefined4 local_8;
  
  local_8 = __security_cookie ^ (uint)(local_48 + 0x44);
  uVar2 = luaL_testudata();
  memset(local_48,0,0x40);
  bVar1 = GetObjInfo(uVar2,Get_GOClass,local_48);
  if (bVar1) {
    lua_pushstring();
  }
  else {
    *(undefined4 *)(*(int *)(param_1 + 8) + 4) = 0x7ff7a500;
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  }
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::Get_WeaponConfig  @ 4fc49821  lines 4190-4205


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl LuaBindings::Get_WeaponConfig(lua_State *param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  char local_48 [64];
  undefined4 local_8;
  
  local_8 = __security_cookie ^ (uint)(local_48 + 0x44);
  uVar1 = luaL_testudata();
  if (uVar1 == 0) {
    *(undefined4 *)(*(int *)(param_1 + 8) + 4) = 0x7ff7a500;
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
    return 1;
  }
  uVar2 = lua_type();
  if ((int)uVar2 < 1) {
    iVar3 = 0;
  }
  else {
    iVar3 = luaL_checkinteger();
    if (iVar3 < 0) {
      iVar4 = 0;
      goto LAB_4fc4987a;
    }
    iVar4 = 4;
    if (4 < iVar3) goto LAB_4fc4987a;
  }
  iVar4 = iVar3;
LAB_4fc4987a:
  memset(local_48,0,0x40);
  GetObjInfo(uVar1,iVar4 + Get_Weapon0Config,local_48);
  lua_pushstring();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::Get_WeaponODF  @ 4fc483b9  lines 4209-4224


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl LuaBindings::Get_WeaponODF(lua_State *param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  char local_48 [64];
  undefined4 local_8;
  
  local_8 = __security_cookie ^ (uint)(local_48 + 0x44);
  uVar1 = luaL_testudata();
  if (uVar1 == 0) {
    *(undefined4 *)(*(int *)(param_1 + 8) + 4) = 0x7ff7a500;
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
    return 1;
  }
  uVar2 = lua_type();
  if ((int)uVar2 < 1) {
    iVar3 = 0;
  }
  else {
    iVar3 = luaL_checkinteger();
    if (iVar3 < 0) {
      iVar4 = 0;
      goto LAB_4fc48412;
    }
    iVar4 = 4;
    if (4 < iVar3) goto LAB_4fc48412;
  }
  iVar4 = iVar3;
LAB_4fc48412:
  memset(local_48,0,0x40);
  GetObjInfo(uVar1,iVar4 + Get_Weapon0ODF,local_48);
  lua_pushstring();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::Get_WeaponGOClass  @ 4fc44d27  lines 4228-4243


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl LuaBindings::Get_WeaponGOClass(lua_State *param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  char local_48 [64];
  undefined4 local_8;
  
  local_8 = __security_cookie ^ (uint)(local_48 + 0x44);
  uVar1 = luaL_testudata();
  if (uVar1 == 0) {
    *(undefined4 *)(*(int *)(param_1 + 8) + 4) = 0x7ff7a500;
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
    return 1;
  }
  uVar2 = lua_type();
  if ((int)uVar2 < 1) {
    iVar3 = 0;
  }
  else {
    iVar3 = luaL_checkinteger();
    if (iVar3 < 0) {
      iVar4 = 0;
      goto LAB_4fc44d80;
    }
    iVar4 = 4;
    if (4 < iVar3) goto LAB_4fc44d80;
  }
  iVar4 = iVar3;
LAB_4fc44d80:
  memset(local_48,0,0x40);
  GetObjInfo(uVar1,iVar4 + Get_Weapon0GOClass,local_48);
  lua_pushstring();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::DoesODFExist  @ 4fc4b500  lines 4247-4251


int __cdecl LuaBindings::DoesODFExist(lua_State *param_1)

{
  uint *puVar1;
  bool bVar2;
  char *pcVar3;
  
  pcVar3 = (char *)luaL_checklstring((undefined4 *)0x0);
  bVar2 = ::DoesODFExist(pcVar3);
  puVar1 = *(uint **)(param_1 + 8);
  *puVar1 = (uint)bVar2;
  puVar1[1] = 0x7ff7a501;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::TranslateString  @ 4fc47ae8  lines 4255-4280


int __cdecl LuaBindings::TranslateString(lua_State *param_1)

{
  char *pcVar1;
  int iVar2;
  char *pcVar3;
  
  iVar2 = (*(int *)(param_1 + 8) - **(int **)(param_1 + 0x10)) + -8 >> 3;
  if (iVar2 < 1) {
    *(undefined4 *)(*(int *)(param_1 + 8) + 4) = 0x7ff7a500;
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  }
  else {
    if (iVar2 < 2) {
      pcVar3 = "ScriptUtils";
    }
    else {
      pcVar3 = (char *)luaL_checklstring((undefined4 *)0x0);
    }
    pcVar1 = (char *)luaL_checklstring((undefined4 *)0x0);
    pcVar3 = GetBZCCLocalizedString(pcVar3,pcVar1);
    if (pcVar3 == (char *)0x0) {
      *(undefined4 *)(*(int *)(param_1 + 8) + 4) = 0x7ff7a500;
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
    }
    else {
      lua_pushstring();
    }
  }
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetScavengerCurScrap  @ 4fc45357  lines 4284-4292


int __cdecl LuaBindings::GetScavengerCurScrap(lua_State *param_1)

{
  int iVar1;
  int unaff_EBP;
  lua_State *unaff_ESI;
  
  iVar1 = RequireHandle(unaff_ESI,unaff_EBP);
  iVar1 = ::GetScavengerCurScrap(iVar1);
  if (iVar1 == -1) {
    *(undefined4 *)((int)*(double **)(param_1 + 8) + 4) = 0x7ff7a500;
  }
  else {
    **(double **)(param_1 + 8) = (double)iVar1;
  }
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetScavengerMaxScrap  @ 4fc4783b  lines 4296-4304


int __cdecl LuaBindings::GetScavengerMaxScrap(lua_State *param_1)

{
  int iVar1;
  int unaff_EBP;
  lua_State *unaff_ESI;
  
  iVar1 = RequireHandle(unaff_ESI,unaff_EBP);
  iVar1 = ::GetScavengerMaxScrap(iVar1);
  if (iVar1 == -1) {
    *(undefined4 *)((int)*(double **)(param_1 + 8) + 4) = 0x7ff7a500;
  }
  else {
    **(double **)(param_1 + 8) = (double)iVar1;
  }
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::SetScavengerCurScrap  @ 4fc4746f  lines 4308-4313


int __cdecl LuaBindings::SetScavengerCurScrap(lua_State *param_1)

{
  int iVar1;
  int iVar2;
  int unaff_EBP;
  lua_State *unaff_ESI;
  
  iVar1 = RequireHandle(unaff_ESI,unaff_EBP);
  iVar2 = luaL_checkinteger();
  ::SetScavengerCurScrap(iVar1,iVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::SetScavengerMaxScrap  @ 4fc471f6  lines 4317-4322


int __cdecl LuaBindings::SetScavengerMaxScrap(lua_State *param_1)

{
  int iVar1;
  int iVar2;
  int unaff_EBP;
  lua_State *unaff_ESI;
  
  iVar1 = RequireHandle(unaff_ESI,unaff_EBP);
  iVar2 = luaL_checkinteger();
  ::SetScavengerMaxScrap(iVar1,iVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::SelfDamage  @ 4fc471c2  lines 4326-4331


int __cdecl LuaBindings::SelfDamage(lua_State *param_1)

{
  int iVar1;
  int unaff_EBP;
  lua_State *unaff_ESI;
  undefined4 in_XMM0_Da;
  undefined4 in_XMM0_Db;
  
  iVar1 = RequireHandle(unaff_ESI,unaff_EBP);
  luaL_checknumber();
  ::SelfDamage(iVar1,(float)(double)CONCAT44(in_XMM0_Db,in_XMM0_Da));
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::WantBotKillMessages  @ 4fc46b1f  lines 4335-4338


int __cdecl LuaBindings::WantBotKillMessages(lua_State *param_1)

{
  ::WantBotKillMessages();
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::EnableHighTPS  @ 4fc473f2  lines 4342-4347


int __cdecl LuaBindings::EnableHighTPS(lua_State *param_1)

{
  double *pdVar1;
  int local_8;
  
  ::EnableHighTPS(&local_8);
  pdVar1 = *(double **)(param_1 + 8);
  *pdVar1 = (double)local_8;
  *(double **)(param_1 + 8) = pdVar1 + 1;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetLocalUserInspectHandle  @ 4fc45583  lines 4351-4354


int __cdecl LuaBindings::GetLocalUserInspectHandle(lua_State *param_1)

{
  lua_State *unaff_EBP;
  int unaff_retaddr;
  
  ::GetLocalUserInspectHandle();
  PushHandle(unaff_EBP,unaff_retaddr);
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetLocalUserSelectHandle  @ 4fc4fdf4  lines 4358-4361


int __cdecl LuaBindings::GetLocalUserSelectHandle(lua_State *param_1)

{
  lua_State *unaff_EBP;
  int unaff_retaddr;
  
  ::GetLocalUserSelectHandle();
  PushHandle(unaff_EBP,unaff_retaddr);
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::ResetTeamSlot  @ 4fc488b5  lines 4365-4369


int __cdecl LuaBindings::ResetTeamSlot(lua_State *param_1)

{
  int iVar1;
  lua_State *unaff_EBP;
  int unaff_retaddr;
  
  iVar1 = RequireHandle(unaff_EBP,unaff_retaddr);
  ::ResetTeamSlot(iVar1);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::GetCategoryTypeOverride  @ 4fc4afee  lines 4373-4377


int __cdecl LuaBindings::GetCategoryTypeOverride(lua_State *param_1)

{
  int iVar1;
  int unaff_EBP;
  lua_State *unaff_ESI;
  
  iVar1 = RequireHandle(unaff_ESI,unaff_EBP);
  iVar1 = ::GetCategoryTypeOverride(iVar1);
  **(double **)(param_1 + 8) = (double)iVar1;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetCategoryType  @ 4fc48904  lines 4381-4385


int __cdecl LuaBindings::GetCategoryType(lua_State *param_1)

{
  int iVar1;
  int unaff_EBP;
  lua_State *unaff_ESI;
  
  iVar1 = RequireHandle(unaff_ESI,unaff_EBP);
  iVar1 = ::GetCategoryType(iVar1);
  **(double **)(param_1 + 8) = (double)iVar1;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetODFHexInt  @ 4fc4f3b5  lines 4392-4414


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl LuaBindings::GetODFHexInt(lua_State *param_1)

{
  uint *puVar1;
  char *pcVar2;
  bool bVar3;
  char *pcVar4;
  char *pcVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int unaff_ESI;
  lua_State *unaff_EDI;
  char *local_4c;
  char local_48 [64];
  undefined4 local_8;
  
  local_8 = __security_cookie ^ (uint)(local_48 + 0x44);
  uVar8 = 0;
  pcVar4 = (char *)luaL_checklstring((undefined4 *)0x0);
  pcVar5 = (char *)luaL_checklstring((undefined4 *)0x0);
  uVar6 = lua_type();
  if ((int)uVar6 < 1) {
    local_4c = (char *)0x0;
  }
  else {
    local_4c = (char *)luaL_checkinteger();
  }
  iVar7 = lua_isstring();
  if (iVar7 == 0) {
    iVar7 = RequireHandle(unaff_EDI,unaff_ESI);
    pcVar2 = local_4c;
    memset(local_48,0,0x40);
    bVar3 = GetObjInfo(iVar7,Get_ODF,local_48);
    if (((bVar3) && (pcVar4 != (char *)0x0)) && (pcVar5 != (char *)0x0)) {
      iVar7 = ::GetODFHexInt(pcVar4,pcVar5,(char *)&local_4c,pcVar2,(int *)unaff_EDI,unaff_ESI);
    }
    else {
      iVar7 = 0;
    }
    uVar8 = (uint)(iVar7 != 0);
  }
  else {
    lua_tolstring((undefined4 *)0x0);
    bVar3 = OpenODF2((char *)unaff_EDI);
    if (bVar3) {
      iVar7 = ::GetODFHexInt(pcVar4,pcVar5,(char *)&local_4c,local_4c,(int *)unaff_EDI,unaff_ESI);
      uVar8 = (uint)(iVar7 != 0);
    }
  }
  **(double **)(param_1 + 8) = (double)(int)local_4c;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  puVar1 = *(uint **)(param_1 + 8);
  *puVar1 = uVar8;
  puVar1[1] = 0x7ff7a501;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 2;
}


// ---------------------------------------------------------------------
// LuaBindings::GetODFInt  @ 4fc4775e  lines 4419-4441


int __cdecl LuaBindings::GetODFInt(lua_State *param_1)

{
  uint *puVar1;
  lua_State *plVar2;
  bool bVar3;
  char *pcVar4;
  char *pcVar5;
  uint uVar6;
  int iVar7;
  int unaff_ESI;
  uint uVar8;
  lua_State *unaff_EDI;
  
  plVar2 = param_1;
  uVar8 = 0;
  pcVar4 = (char *)luaL_checklstring((undefined4 *)0x0);
  pcVar5 = (char *)luaL_checklstring((undefined4 *)0x0);
  uVar6 = lua_type();
  if ((int)uVar6 < 1) {
    param_1 = (lua_State *)0x0;
  }
  else {
    param_1 = (lua_State *)luaL_checkinteger();
  }
  iVar7 = lua_isstring();
  if (iVar7 == 0) {
    RequireHandle(unaff_EDI,unaff_ESI);
    iVar7 = ::GetODFInt((int)pcVar5,(char *)&param_1,(char *)param_1,(int *)unaff_EDI,unaff_ESI);
  }
  else {
    lua_tolstring((undefined4 *)0x0);
    bVar3 = OpenODF2((char *)unaff_EDI);
    if (!bVar3) goto LAB_4fc4780f;
    iVar7 = ::GetODFInt(pcVar4,pcVar5,(char *)&param_1,(char *)param_1,(int *)unaff_EDI,unaff_ESI);
  }
  uVar8 = (uint)(iVar7 != 0);
LAB_4fc4780f:
  **(double **)(plVar2 + 8) = (double)(int)param_1;
  *(int *)(plVar2 + 8) = *(int *)(plVar2 + 8) + 8;
  puVar1 = *(uint **)(plVar2 + 8);
  *puVar1 = uVar8;
  puVar1[1] = 0x7ff7a501;
  *(int *)(plVar2 + 8) = *(int *)(plVar2 + 8) + 8;
  return 2;
}


// ---------------------------------------------------------------------
// LuaBindings::GetODFLong  @ 4fc4e341  lines 4446-4468


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl LuaBindings::GetODFLong(lua_State *param_1)

{
  uint *puVar1;
  bool bVar2;
  char *pcVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int unaff_ESI;
  lua_State *unaff_EDI;
  undefined1 auStack_64 [4];
  char *local_60;
  char *local_5c;
  char *local_58;
  char *local_54;
  char local_50 [68];
  uint local_c;
  
  local_c = __security_cookie ^ (uint)auStack_64;
  uVar6 = 0;
  pcVar3 = (char *)luaL_checklstring((undefined4 *)0x0);
  local_5c = pcVar3;
  local_58 = (char *)luaL_checklstring((undefined4 *)0x0);
  uVar4 = lua_type();
  if ((int)uVar4 < 1) {
    local_60 = (char *)0x0;
  }
  else {
    local_60 = (char *)luaL_checkinteger();
  }
  iVar5 = lua_isstring();
  if (iVar5 == 0) {
    iVar5 = RequireHandle(unaff_EDI,unaff_ESI);
    local_54 = local_60;
    memset(local_50,0,0x40);
    bVar2 = GetObjInfo(iVar5,Get_ODF,local_50);
    if (((bVar2) && (local_5c != (char *)0x0)) && (local_58 != (char *)0x0)) {
      iVar5 = ::GetODFLong(local_5c,local_58,(char *)&local_60,local_54,(long *)unaff_EDI,unaff_ESI)
      ;
    }
    else {
      iVar5 = 0;
    }
    uVar6 = (uint)(iVar5 != 0);
  }
  else {
    local_5c = (char *)lua_tolstring((undefined4 *)0x0);
    bVar2 = OpenODF2((char *)unaff_EDI);
    if (bVar2) {
      iVar5 = ::GetODFLong(pcVar3,local_58,(char *)&local_60,local_60,(long *)unaff_EDI,unaff_ESI);
      uVar6 = (uint)(iVar5 != 0);
    }
  }
  lua_pushnumber();
  puVar1 = *(uint **)(param_1 + 8);
  *puVar1 = uVar6;
  puVar1[1] = 0x7ff7a501;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 2;
}


// ---------------------------------------------------------------------
// LuaBindings::GetODFFloat  @ 4fc492eb  lines 4473-4495


int __cdecl LuaBindings::GetODFFloat(lua_State *param_1)

{
  uint *puVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  float unaff_ESI;
  uint uVar5;
  lua_State *unaff_EDI;
  undefined4 in_XMM0_Da;
  undefined4 in_XMM0_Db;
  char *local_14;
  char *local_10;
  char *local_c;
  
  uVar5 = 0;
  local_c = (char *)luaL_checklstring((undefined4 *)0x0);
  local_10 = (char *)luaL_checklstring((undefined4 *)0x0);
  uVar3 = lua_type();
  if ((int)uVar3 < 1) {
    in_XMM0_Da = 0;
    in_XMM0_Db = 0;
  }
  else {
    luaL_checknumber();
  }
  local_14 = (char *)(float)(double)CONCAT44(in_XMM0_Db,in_XMM0_Da);
  iVar4 = lua_isstring();
  if (iVar4 == 0) {
    RequireHandle(unaff_EDI,(int)unaff_ESI);
    iVar4 = ::GetODFFloat((int)local_10,(char *)&local_14,local_14,(float *)unaff_EDI,unaff_ESI);
  }
  else {
    lua_tolstring((undefined4 *)0x0);
    bVar2 = OpenODF2((char *)unaff_EDI);
    if (!bVar2) goto LAB_4fc493c1;
    iVar4 = ::GetODFFloat(local_c,local_10,(char *)&local_14,local_14,(float *)unaff_EDI,unaff_ESI);
  }
  uVar5 = (uint)(iVar4 != 0);
LAB_4fc493c1:
  lua_pushnumber();
  puVar1 = *(uint **)(param_1 + 8);
  *puVar1 = uVar5;
  puVar1[1] = 0x7ff7a501;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 2;
}


// ---------------------------------------------------------------------
// LuaBindings::GetODFDouble  @ 4fc4ea16  lines 4500-4522


int __cdecl LuaBindings::GetODFDouble(lua_State *param_1)

{
  uint *puVar1;
  bool bVar2;
  char *pcVar3;
  char *pcVar4;
  uint uVar5;
  int iVar6;
  undefined4 unaff_EBX;
  int unaff_ESI;
  uint uVar7;
  lua_State *unaff_EDI;
  undefined8 in_XMM0_Qa;
  undefined8 local_10;
  
  uVar7 = 0;
  pcVar3 = (char *)luaL_checklstring((undefined4 *)0x0);
  pcVar4 = (char *)luaL_checklstring((undefined4 *)0x0);
  uVar5 = lua_type();
  if ((int)uVar5 < 1) {
    in_XMM0_Qa = 0;
  }
  else {
    luaL_checknumber();
  }
  local_10 = in_XMM0_Qa;
  iVar6 = lua_isstring();
  if (iVar6 == 0) {
    RequireHandle(unaff_EDI,unaff_ESI);
    iVar6 = ::GetODFDouble((int)pcVar4,(char *)&local_10,(char *)local_10,
                           (double *)((ulonglong)local_10 >> 0x20),
                           (double)CONCAT44(unaff_ESI,unaff_EDI));
  }
  else {
    lua_tolstring((undefined4 *)0x0);
    bVar2 = OpenODF2((char *)unaff_EDI);
    if (!bVar2) goto LAB_4fc4eae8;
    iVar6 = ::GetODFDouble(pcVar3,pcVar4,(char *)&local_10,(char *)local_10,
                           (double *)((ulonglong)local_10 >> 0x20),
                           (double)CONCAT44(unaff_EBX,unaff_ESI));
  }
  uVar7 = (uint)(iVar6 != 0);
LAB_4fc4eae8:
  lua_pushnumber();
  puVar1 = *(uint **)(param_1 + 8);
  *puVar1 = uVar7;
  puVar1[1] = 0x7ff7a501;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 2;
}


// ---------------------------------------------------------------------
// LuaBindings::GetODFChar  @ 4fc4b6aa  lines 4527-4552


int __cdecl LuaBindings::GetODFChar(lua_State *param_1)

{
  uint *puVar1;
  lua_State *plVar2;
  bool bVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  int iVar7;
  int unaff_ESI;
  lua_State *unaff_EDI;
  bool bVar8;
  char cVar9;
  
  plVar2 = param_1;
  bVar8 = false;
  pcVar4 = (char *)luaL_checklstring((undefined4 *)0x0);
  pcVar5 = (char *)luaL_checklstring((undefined4 *)0x0);
  pcVar6 = luaL_optlstring("",(int *)0x0);
  param_1 = (lua_State *)CONCAT31(param_1._1_3_,*pcVar6);
  iVar7 = lua_isstring();
  if (iVar7 == 0) {
    RequireHandle(unaff_EDI,unaff_ESI);
    iVar7 = ::GetODFChar((int)pcVar5,(char *)&param_1,(char *)param_1,(char *)unaff_EDI,
                         (char)unaff_ESI);
LAB_4fc4b74a:
    bVar8 = iVar7 != 0;
    if (!bVar8) goto LAB_4fc4b753;
  }
  else {
    lua_tolstring((undefined4 *)0x0);
    cVar9 = (char)unaff_ESI;
    bVar3 = OpenODF2((char *)unaff_EDI);
    if (bVar3) {
      iVar7 = ::GetODFChar(pcVar4,pcVar5,(char *)&param_1,(char *)param_1,(char *)unaff_EDI,cVar9);
      goto LAB_4fc4b74a;
    }
LAB_4fc4b753:
    if ((char)param_1 == '\0') {
      *(undefined4 *)(*(int *)(plVar2 + 8) + 4) = 0x7ff7a500;
      *(int *)(plVar2 + 8) = *(int *)(plVar2 + 8) + 8;
      goto LAB_4fc4b776;
    }
  }
  lua_pushlstring(1);
LAB_4fc4b776:
  puVar1 = *(uint **)(plVar2 + 8);
  *puVar1 = (uint)bVar8;
  puVar1[1] = 0x7ff7a501;
  *(int *)(plVar2 + 8) = *(int *)(plVar2 + 8) + 8;
  return 2;
}


// ---------------------------------------------------------------------
// LuaBindings::GetODFBool  @ 4fc46271  lines 4557-4579


int __cdecl LuaBindings::GetODFBool(lua_State *param_1)

{
  uint *puVar1;
  lua_State *plVar2;
  bool bVar3;
  char *pcVar4;
  char *pcVar5;
  uint uVar6;
  int iVar7;
  int unaff_ESI;
  uint uVar8;
  lua_State *unaff_EDI;
  undefined1 uVar9;
  
  plVar2 = param_1;
  uVar8 = 0;
  pcVar4 = (char *)luaL_checklstring((undefined4 *)0x0);
  pcVar5 = (char *)luaL_checklstring((undefined4 *)0x0);
  uVar6 = lua_type();
  if ((int)uVar6 < 1) {
    iVar7 = 0;
  }
  else {
    iVar7 = lua_toboolean();
  }
  param_1 = (lua_State *)CONCAT31(param_1._1_3_,iVar7 != 0);
  iVar7 = lua_isstring();
  if (iVar7 == 0) {
    RequireHandle(unaff_EDI,unaff_ESI);
    iVar7 = ::GetODFBool((int)pcVar5,(char *)&param_1,(char *)param_1,(bool *)unaff_EDI,
                         SUB41(unaff_ESI,0));
  }
  else {
    lua_tolstring((undefined4 *)0x0);
    uVar9 = (undefined1)unaff_ESI;
    bVar3 = OpenODF2((char *)unaff_EDI);
    if (!bVar3) goto LAB_4fc46325;
    iVar7 = ::GetODFBool(pcVar4,pcVar5,(char *)&param_1,(char *)param_1,(bool *)unaff_EDI,
                         (bool)uVar9);
  }
  uVar8 = (uint)(iVar7 != 0);
LAB_4fc46325:
  puVar1 = *(uint **)(plVar2 + 8);
  *puVar1 = (uint)((char)param_1 != '\0');
  puVar1[1] = 0x7ff7a501;
  *(int *)(plVar2 + 8) = *(int *)(plVar2 + 8) + 8;
  puVar1 = *(uint **)(plVar2 + 8);
  *puVar1 = uVar8;
  puVar1[1] = 0x7ff7a501;
  *(int *)(plVar2 + 8) = *(int *)(plVar2 + 8) + 8;
  return 2;
}


// ---------------------------------------------------------------------
// LuaBindings::GetODFString  @ 4fc48bc5  lines 4584-4612


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl LuaBindings::GetODFString(lua_State *param_1)

{
  uint *puVar1;
  bool bVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  int iVar6;
  char *unaff_ESI;
  lua_State *unaff_EDI;
  bool bVar7;
  char local_48 [64];
  undefined4 local_8;
  
  local_8 = __security_cookie ^ (uint)(local_48 + 0x44);
  bVar7 = false;
  pcVar3 = (char *)luaL_checklstring((undefined4 *)0x0);
  pcVar4 = (char *)luaL_checklstring((undefined4 *)0x0);
  pcVar5 = luaL_optlstring((char *)0x0,(int *)0x0);
  memset(local_48,0,0x40);
  iVar6 = lua_isstring();
  if (iVar6 == 0) {
    RequireHandle(unaff_EDI,(int)unaff_ESI);
    iVar6 = ::GetODFString((int)pcVar4,(char *)0x40,local_48,(uint)pcVar5,(char *)unaff_EDI,
                           unaff_ESI);
LAB_4fc48c76:
    bVar7 = iVar6 != 0;
    if (!bVar7) goto LAB_4fc48c84;
  }
  else {
    lua_tolstring((undefined4 *)0x0);
    bVar2 = OpenODF2((char *)unaff_EDI);
    if (bVar2) {
      iVar6 = ::GetODFString(pcVar3,pcVar4,(char *)0x40,local_48,(uint)pcVar5,(char *)unaff_EDI,
                             unaff_ESI);
      goto LAB_4fc48c76;
    }
LAB_4fc48c84:
    if ((pcVar5 == (char *)0x0) || (*pcVar5 == '\0')) {
      *(undefined4 *)(*(int *)(param_1 + 8) + 4) = 0x7ff7a500;
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
      goto LAB_4fc48ca6;
    }
  }
  lua_pushstring();
LAB_4fc48ca6:
  puVar1 = *(uint **)(param_1 + 8);
  *puVar1 = (uint)bVar7;
  puVar1[1] = 0x7ff7a501;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 2;
}


// ---------------------------------------------------------------------
// LuaBindings::GetODFColor  @ 4fc4f1c2  lines 4617-4639


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl LuaBindings::GetODFColor(lua_State *param_1)

{
  uint *puVar1;
  bool bVar2;
  char *pcVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  ulong unaff_ESI;
  lua_State *unaff_EDI;
  undefined1 auStack_64 [4];
  char *local_60;
  char *local_5c;
  char *local_58;
  char *local_54;
  char local_50 [68];
  uint local_c;
  
  local_c = __security_cookie ^ (uint)auStack_64;
  uVar6 = 0;
  pcVar3 = (char *)luaL_checklstring((undefined4 *)0x0);
  local_5c = pcVar3;
  local_58 = (char *)luaL_checklstring((undefined4 *)0x0);
  uVar4 = lua_type();
  if ((int)uVar4 < 1) {
    local_60 = (char *)0x0;
  }
  else {
    local_60 = (char *)luaL_checkinteger();
  }
  iVar5 = lua_isstring();
  if (iVar5 == 0) {
    iVar5 = RequireHandle(unaff_EDI,unaff_ESI);
    local_54 = local_60;
    memset(local_50,0,0x40);
    bVar2 = GetObjInfo(iVar5,Get_ODF,local_50);
    if (((bVar2) && (local_5c != (char *)0x0)) && (local_58 != (char *)0x0)) {
      iVar5 = ::GetODFColor(local_5c,local_58,(char *)&local_60,local_54,(ulong *)unaff_EDI,
                            unaff_ESI);
    }
    else {
      iVar5 = 0;
    }
    uVar6 = (uint)(iVar5 != 0);
  }
  else {
    local_5c = (char *)lua_tolstring((undefined4 *)0x0);
    bVar2 = OpenODF2((char *)unaff_EDI);
    if (bVar2) {
      iVar5 = ::GetODFColor(pcVar3,local_58,(char *)&local_60,local_60,(ulong *)unaff_EDI,unaff_ESI)
      ;
      uVar6 = (uint)(iVar5 != 0);
    }
  }
  lua_pushnumber();
  puVar1 = *(uint **)(param_1 + 8);
  *puVar1 = uVar6;
  puVar1[1] = 0x7ff7a501;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 2;
}


// ---------------------------------------------------------------------
// LuaBindings::GetODFVector  @ 4fc4f041  lines 4644-4668


int __cdecl LuaBindings::GetODFVector(lua_State *param_1)

{
  uint *puVar1;
  Vector VVar2;
  Vector VVar3;
  bool bVar4;
  undefined4 *puVar5;
  int iVar6;
  Vector *pVVar7;
  uint uVar8;
  float unaff_ESI;
  lua_State *unaff_EDI;
  char *local_28;
  Vector *local_24;
  float local_20;
  char *local_1c;
  Vector *pVStack_18;
  float fStack_14;
  int local_10;
  char *local_c;
  char *local_8;
  
  uVar8 = 0;
  local_c = (char *)luaL_checklstring((undefined4 *)0x0);
  local_8 = (char *)luaL_checklstring((undefined4 *)0x0);
  puVar5 = (undefined4 *)luaL_testudata();
  if (puVar5 == (undefined4 *)0x0) {
    local_28 = (char *)0x0;
    local_24 = (Vector *)0x0;
    local_20 = 0.0;
  }
  else {
    local_28 = (char *)*puVar5;
    local_24 = (Vector *)puVar5[1];
    local_20 = (float)puVar5[2];
  }
  local_1c = local_28;
  pVStack_18 = local_24;
  fStack_14 = local_20;
  iVar6 = lua_isstring();
  if (iVar6 == 0) {
    RequireHandle(unaff_EDI,(int)unaff_ESI);
    VVar3.y = (float)unaff_EDI;
    VVar3.x = fStack_14;
    VVar3.z = unaff_ESI;
    iVar6 = ::GetODFVector((int)local_8,(char *)&local_1c,local_1c,pVStack_18,VVar3);
  }
  else {
    local_10 = lua_tolstring((undefined4 *)0x0);
    bVar4 = OpenODF2((char *)unaff_EDI);
    if (!bVar4) goto LAB_4fc4f118;
    VVar2.y = (float)unaff_EDI;
    VVar2.x = fStack_14;
    VVar2.z = unaff_ESI;
    iVar6 = ::GetODFVector(local_c,local_8,(char *)&local_1c,local_1c,pVStack_18,VVar2);
  }
  uVar8 = (uint)(iVar6 != 0);
LAB_4fc4f118:
  pVVar7 = NewVector(unaff_EDI);
  pVVar7->x = (float)local_1c;
  pVVar7->y = (float)pVStack_18;
  pVVar7->z = fStack_14;
  puVar1 = *(uint **)(param_1 + 8);
  *puVar1 = uVar8;
  puVar1[1] = 0x7ff7a501;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 2;
}


// ---------------------------------------------------------------------
// LuaBindings::NoteGameoverWithCustomMessage  @ 4fc46770  lines 4690-4694


int __cdecl LuaBindings::NoteGameoverWithCustomMessage(lua_State *param_1)

{
  char *pcVar1;
  
  pcVar1 = (char *)luaL_checklstring((undefined4 *)0x0);
  ::NoteGameoverWithCustomMessage(pcVar1);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::SetBestGroup  @ 4fc4a18e  lines 4698-4706


int __cdecl LuaBindings::SetBestGroup(lua_State *param_1)

{
  int iVar1;
  int unaff_EBP;
  lua_State *unaff_ESI;
  
  iVar1 = RequireHandle(unaff_ESI,unaff_EBP);
  iVar1 = ::SetBestGroup(iVar1);
  if (iVar1 == -1) {
    *(undefined4 *)((int)*(double **)(param_1 + 8) + 4) = 0x7ff7a500;
  }
  else {
    **(double **)(param_1 + 8) = (double)iVar1;
  }
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetGroup  @ 4fc4563a  lines 4711-4735


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl LuaBindings::GetGroup(lua_State *param_1)

{
  int iVar1;
  int iVar2;
  ObjectInfoType OVar3;
  lua_State *unaff_ESI;
  lua_State *plVar4;
  char local_48 [64];
  undefined4 local_8;
  
  local_8 = __security_cookie ^ (uint)(local_48 + 0x44);
  plVar4 = param_1;
  iVar1 = lua_isnumber();
  if (iVar1 == 0) {
    iVar1 = RequireHandle(unaff_ESI,(int)plVar4);
    iVar1 = ::GetGroup(iVar1);
    if (iVar1 == -1) {
      *(undefined4 *)((int)*(double **)(param_1 + 8) + 4) = 0x7ff7a500;
    }
    else {
      **(double **)(param_1 + 8) = (double)iVar1;
    }
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  }
  else {
    iVar1 = luaL_checkinteger();
    iVar2 = lua_tointegerx((undefined4 *)0x0);
    OVar3 = luaL_checkinteger();
    memset(local_48,0,0x40);
    ::GetGroup(iVar1,iVar2,OVar3,local_48);
    lua_pushstring();
  }
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetGroupCount  @ 4fc4a121  lines 4739-4744


int __cdecl LuaBindings::GetGroupCount(lua_State *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = luaL_checkinteger();
  iVar2 = luaL_checkinteger();
  iVar1 = ::GetGroupCount(iVar1,iVar2);
  **(double **)(param_1 + 8) = (double)iVar1;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::SetLifespan  @ 4fc44fb0  lines 4748-4753


int __cdecl LuaBindings::SetLifespan(lua_State *param_1)

{
  int iVar1;
  int unaff_EBP;
  lua_State *unaff_ESI;
  undefined4 in_XMM0_Da;
  undefined4 in_XMM0_Db;
  
  iVar1 = RequireHandle(unaff_ESI,unaff_EBP);
  luaL_checknumber();
  ::SetLifespan(iVar1,(float)(double)CONCAT44(in_XMM0_Db,in_XMM0_Da));
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::DoesFileExist  @ 4fc488cf  lines 4757-4761


int __cdecl LuaBindings::DoesFileExist(lua_State *param_1)

{
  uint *puVar1;
  bool bVar2;
  char *pcVar3;
  
  pcVar3 = (char *)luaL_checklstring((undefined4 *)0x0);
  bVar2 = ::DoesFileExist(pcVar3);
  puVar1 = *(uint **)(param_1 + 8);
  *puVar1 = (uint)bVar2;
  puVar1[1] = 0x7ff7a501;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::LoadFile  @ 4fc4559b  lines 4765-4785


int __cdecl LuaBindings::LoadFile(lua_State *param_1)

{
  void *_Memory;
  bool bVar1;
  char *pcVar2;
  void *local_c;
  uint local_8;
  
  pcVar2 = (char *)luaL_checklstring(&local_c);
  local_8 = 0;
  ::LoadFile(pcVar2,(void *)0x0,&local_8);
  local_c = malloc(local_8 + 1);
  bVar1 = ::LoadFile(pcVar2,local_c,&local_8);
  _Memory = local_c;
  if (bVar1) {
    *(undefined1 *)((int)local_c + local_8) = 0;
    lua_pushlstring(local_8);
  }
  else {
    *(undefined4 *)(*(int *)(param_1 + 8) + 4) = 0x7ff7a500;
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  }
  free(_Memory);
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::StartAudio3D  @ 4fc48006  lines 4792-4825


int __cdecl LuaBindings::StartAudio3D(lua_State *param_1)

{
  Vector VVar1;
  char *pcVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar6;
  int iVar7;
  int unaff_ESI;
  int iVar8;
  lua_State *unaff_EDI;
  DLLAudioCategory DVar9;
  float fVar10;
  undefined1 in_XMM0 [16];
  undefined1 auVar11 [16];
  undefined1 auVar12 [16];
  undefined1 auVar13 [16];
  undefined1 auVar14 [16];
  undefined1 uVar15;
  
  iVar8 = 0;
  pcVar2 = (char *)luaL_checklstring((undefined4 *)0x0);
  iVar3 = lua_isnumber();
  if (iVar3 == 0) {
    uVar4 = luaL_testudata();
    if (uVar4 == 0) {
      puVar6 = (undefined4 *)luaL_testudata();
      if (puVar6 == (undefined4 *)0x0) {
        iVar3 = RequireHandle(unaff_EDI,unaff_ESI);
        uVar4 = lua_type();
        if ((int)uVar4 < 1) {
          DVar9 = AUDIO_CAT_UNKNOWN;
        }
        else {
          DVar9 = luaL_checkinteger();
        }
        uVar4 = lua_type();
        if ((int)uVar4 < 1) {
          iVar7 = 0;
        }
        else {
          iVar7 = lua_toboolean();
        }
        uVar4 = lua_type();
        if (0 < (int)uVar4) {
          iVar8 = lua_toboolean();
        }
        ::StartAudio3D(pcVar2,iVar3,DVar9,iVar7 != 0,iVar8 != 0);
        goto LAB_4fc48244;
      }
      uVar4 = lua_type();
      uVar15 = (undefined1)unaff_ESI;
      if (0 < (int)uVar4) {
        luaL_checkinteger();
      }
      uVar4 = lua_type();
      if (0 < (int)uVar4) {
        iVar8 = lua_toboolean();
      }
    }
    else {
      uVar5 = lua_type();
      uVar15 = (undefined1)unaff_ESI;
      if (0 < (int)uVar5) {
        luaL_checkinteger();
      }
      uVar5 = lua_type();
      if (0 < (int)uVar5) {
        iVar8 = lua_toboolean();
      }
      puVar6 = (undefined4 *)(uVar4 + 0x30);
    }
    VVar1.z._0_1_ = iVar8 != 0;
    VVar1._0_8_ = *(undefined8 *)(puVar6 + 1);
    VVar1.z._1_3_ = 0;
    ::StartAudio3D((char *)*puVar6,VVar1,(DLLAudioCategory)unaff_EDI,(bool)uVar15);
  }
  else {
    luaL_checknumber();
    auVar11._4_12_ = in_XMM0._4_12_;
    auVar11._0_4_ = (float)in_XMM0._0_8_;
    auVar14 = auVar11;
    luaL_checknumber();
    auVar12._4_12_ = auVar14._4_12_;
    auVar12._0_4_ = (float)auVar14._0_8_;
    auVar14 = auVar12;
    luaL_checknumber();
    auVar13._4_12_ = auVar14._4_12_;
    auVar13._0_4_ = (float)auVar14._0_8_;
    auVar14 = auVar13;
    uVar4 = lua_type();
    if ((int)uVar4 < 1) {
      DVar9 = AUDIO_CAT_UNKNOWN;
    }
    else {
      DVar9 = luaL_checkinteger();
      auVar14 = ZEXT416((uint)auVar13._0_4_);
    }
    uVar4 = lua_type();
    fVar10 = auVar14._0_4_;
    if (0 < (int)uVar4) {
      iVar8 = lua_toboolean();
      fVar10 = auVar14._0_4_;
    }
    ::StartAudio3D(pcVar2,auVar11._0_4_,auVar12._0_4_,fVar10,DVar9,iVar8 != 0);
  }
LAB_4fc48244:
  lua_pushnumber();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::StartAudio2D  @ 4fc4c1d5  lines 4830-4839


int __cdecl LuaBindings::StartAudio2D(lua_State *param_1)

{
  char *pcVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  float fVar5;
  undefined1 in_XMM0 [16];
  undefined1 auVar6 [16];
  undefined1 auVar7 [16];
  undefined1 auVar8 [16];
  
  iVar4 = 0;
  pcVar1 = (char *)luaL_checklstring((undefined4 *)0x0);
  luaL_checknumber();
  auVar6._4_12_ = in_XMM0._4_12_;
  auVar6._0_4_ = (float)in_XMM0._0_8_;
  auVar8 = auVar6;
  luaL_checknumber();
  auVar7._4_12_ = auVar8._4_12_;
  auVar7._0_4_ = (float)auVar8._0_8_;
  auVar8 = auVar7;
  luaL_checknumber();
  auVar8._0_4_ = (float)auVar8._0_8_;
  uVar2 = lua_type();
  if ((int)uVar2 < 1) {
    iVar3 = 0;
  }
  else {
    iVar3 = lua_toboolean();
  }
  uVar2 = lua_type();
  fVar5 = auVar8._0_4_;
  if (0 < (int)uVar2) {
    iVar4 = lua_toboolean();
    fVar5 = auVar8._0_4_;
  }
  ::StartAudio2D(pcVar1,auVar6._0_4_,auVar7._0_4_,fVar5,iVar3 != 0,iVar4 != 0);
  lua_pushnumber();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::IsAudioPlaying  @ 4fc4f005  lines 4843-4847


int __cdecl LuaBindings::IsAudioPlaying(lua_State *param_1)

{
  lua_State *plVar1;
  uint *puVar2;
  bool bVar3;
  double in_XMM0_Qa;
  
  plVar1 = param_1;
  luaL_checknumber();
  param_1 = (lua_State *)(int)in_XMM0_Qa;
  bVar3 = ::IsAudioPlaying((int *)&param_1);
  puVar2 = *(uint **)(plVar1 + 8);
  *puVar2 = (uint)bVar3;
  puVar2[1] = 0x7ff7a501;
  plVar1 = plVar1 + 8;
  *(int *)plVar1 = *(int *)plVar1 + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::StopAudio  @ 4fc4c4d4  lines 4851-4855


int __cdecl LuaBindings::StopAudio(lua_State *param_1)

{
  double in_XMM0_Qa;
  
  luaL_checknumber();
  ::StopAudio((int)in_XMM0_Qa);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::PauseAudio  @ 4fc4dcfc  lines 4859-4863


int __cdecl LuaBindings::PauseAudio(lua_State *param_1)

{
  double in_XMM0_Qa;
  
  luaL_checknumber();
  ::PauseAudio((int)in_XMM0_Qa);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::ResumeAudio  @ 4fc4fdb3  lines 4867-4871


int __cdecl LuaBindings::ResumeAudio(lua_State *param_1)

{
  double in_XMM0_Qa;
  
  luaL_checknumber();
  ::ResumeAudio((int)in_XMM0_Qa);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::SetVolume  @ 4fc4879e  lines 4875-4881


int __cdecl LuaBindings::SetVolume(lua_State *param_1)

{
  double dVar1;
  uint uVar2;
  int iVar3;
  undefined4 in_XMM0_Da;
  float fVar4;
  undefined4 in_XMM0_Db;
  
  iVar3 = 1;
  luaL_checknumber();
  dVar1 = (double)CONCAT44(in_XMM0_Db,in_XMM0_Da);
  luaL_checknumber();
  fVar4 = (float)(double)CONCAT44(in_XMM0_Db,in_XMM0_Da);
  uVar2 = lua_type();
  if (0 < (int)uVar2) {
    iVar3 = lua_toboolean();
  }
  ::SetVolume((int)dVar1,fVar4,iVar3 != 0);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::SetPan  @ 4fc4e491  lines 4885-4890


int __cdecl LuaBindings::SetPan(lua_State *param_1)

{
  double dVar1;
  undefined4 in_XMM0_Da;
  undefined4 in_XMM0_Db;
  
  luaL_checknumber();
  dVar1 = (double)CONCAT44(in_XMM0_Db,in_XMM0_Da);
  luaL_checknumber();
  ::SetPan((int)dVar1,(float)(double)CONCAT44(in_XMM0_Db,in_XMM0_Da));
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::SetRate  @ 4fc44f74  lines 4894-4899


int __cdecl LuaBindings::SetRate(lua_State *param_1)

{
  double dVar1;
  undefined4 in_XMM0_Da;
  undefined4 in_XMM0_Db;
  
  luaL_checknumber();
  dVar1 = (double)CONCAT44(in_XMM0_Db,in_XMM0_Da);
  luaL_checknumber();
  ::SetRate((int)dVar1,(float)(double)CONCAT44(in_XMM0_Db,in_XMM0_Da));
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::GetAudioFileDuration  @ 4fc48b86  lines 4903-4907


int __cdecl LuaBindings::GetAudioFileDuration(lua_State *param_1)

{
  double in_XMM0_Qa;
  
  luaL_checknumber();
  ::GetAudioFileDuration((int)in_XMM0_Qa);
  lua_pushnumber();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::IsPlayingLooped  @ 4fc49d36  lines 4911-4915


int __cdecl LuaBindings::IsPlayingLooped(lua_State *param_1)

{
  uint *puVar1;
  bool bVar2;
  double in_XMM0_Qa;
  
  luaL_checknumber();
  bVar2 = ::IsPlayingLooped((int)in_XMM0_Qa);
  puVar1 = *(uint **)(param_1 + 8);
  *puVar1 = (uint)bVar2;
  puVar1[1] = 0x7ff7a501;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetNearestPowerup  @ 4fc47e81  lines 4919-4925


int __cdecl LuaBindings::GetNearestPowerup(lua_State *param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int unaff_ESI;
  lua_State *unaff_EDI;
  double in_XMM0_Qa;
  
  iVar1 = RequireHandle(unaff_EDI,unaff_ESI);
  iVar2 = lua_toboolean();
  uVar3 = lua_type();
  if ((int)uVar3 < 1) {
    in_XMM0_Qa = __real_407c200000000000;
  }
  else {
    luaL_checknumber();
  }
  ::GetNearestPowerup(iVar1,iVar2 != 0,(float)in_XMM0_Qa);
  PushHandle(unaff_EDI,unaff_ESI);
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetNearestPerson  @ 4fc4614f  lines 4929-4935


int __cdecl LuaBindings::GetNearestPerson(lua_State *param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int unaff_ESI;
  lua_State *unaff_EDI;
  double in_XMM0_Qa;
  
  iVar1 = RequireHandle(unaff_EDI,unaff_ESI);
  iVar2 = lua_toboolean();
  uVar3 = lua_type();
  if ((int)uVar3 < 1) {
    in_XMM0_Qa = __real_407c200000000000;
  }
  else {
    luaL_checknumber();
  }
  ::GetNearestPerson(iVar1,iVar2 != 0,(float)in_XMM0_Qa);
  PushHandle(unaff_EDI,unaff_ESI);
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::SetCommand  @ 4fc45397  lines 4944-4983


int __cdecl LuaBindings::SetCommand(lua_State *param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  uint uVar6;
  Vector *pVVar7;
  ulong uVar8;
  int unaff_ESI;
  lua_State *unaff_EDI;
  int iVar9;
  
  iVar9 = 1;
  iVar1 = RequireHandle(unaff_EDI,unaff_ESI);
  iVar2 = luaL_checkinteger();
  uVar3 = lua_type();
  if (0 < (int)uVar3) {
    iVar9 = luaL_checkinteger();
  }
  uVar3 = luaL_testudata();
  uVar8 = 0;
  iVar4 = lua_isstring();
  if (iVar4 == 0) {
    uVar6 = lua_type();
    if (0 < (int)uVar6) {
      luaL_checkinteger();
    }
  }
  else {
    pcVar5 = (char *)lua_tolstring((undefined4 *)0x0);
    uVar8 = ::CalcCRC(pcVar5);
    if (iVar2 == 0x16) {
      ::PreloadODF(pcVar5);
    }
  }
  uVar6 = luaL_testudata();
  if (uVar6 == 0) {
    pVVar7 = (Vector *)luaL_testudata();
    if (pVVar7 == (Vector *)0x0) {
      iVar4 = lua_isstring();
      if (iVar4 == 0) {
        ::SetCommand(iVar1,iVar2,iVar9,uVar3,(char *)0x0,uVar8);
        return 0;
      }
      pcVar5 = (char *)lua_tolstring((undefined4 *)0x0);
      ::SetCommand(iVar1,iVar2,iVar9,uVar3,pcVar5,uVar8);
      return 0;
    }
  }
  else {
    pVVar7 = (Vector *)(uVar6 + 0x30);
  }
  ::SetCommand(iVar1,iVar2,iVar9,uVar3,pVVar7,uVar8);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::SetGravity  @ 4fc4e2e3  lines 4987-4991


int __cdecl LuaBindings::SetGravity(lua_State *param_1)

{
  uint uVar1;
  double in_XMM0_Qa;
  
  uVar1 = lua_type();
  if ((int)uVar1 < 1) {
    in_XMM0_Qa = __real_4029000000000000;
  }
  else {
    luaL_checknumber();
  }
  ::SetGravity((float)in_XMM0_Qa);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::SetAutoGroupUnits  @ 4fc4aeff  lines 4995-4999


int __cdecl LuaBindings::SetAutoGroupUnits(lua_State *param_1)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = lua_type();
  if ((int)uVar1 < 1) {
    iVar2 = 1;
  }
  else {
    iVar2 = lua_toboolean();
  }
  ::SetAutoGroupUnits(iVar2 != 0);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::KickPlayer  @ 4fc45f68  lines 5003-5009


int __cdecl LuaBindings::KickPlayer(lua_State *param_1)

{
  int iVar1;
  char *pcVar2;
  uint uVar3;
  int unaff_EBX;
  lua_State *unaff_ESI;
  int iVar4;
  
  iVar1 = RequireHandle(unaff_ESI,unaff_EBX);
  iVar4 = 0;
  pcVar2 = (char *)luaL_checklstring((undefined4 *)0x0);
  uVar3 = lua_type();
  if (0 < (int)uVar3) {
    iVar4 = lua_toboolean();
  }
  ::KickPlayer(iVar1,pcVar2,iVar4 != 0);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::TerrainIsWater  @ 4fc44de5  lines 5017-5043


int __cdecl LuaBindings::TerrainIsWater(lua_State *param_1)

{
  uint *puVar1;
  double dVar2;
  bool bVar3;
  undefined4 *puVar4;
  Vector *pVVar5;
  uint uVar6;
  int iVar7;
  int unaff_ESI;
  char *unaff_EDI;
  undefined4 *puVar8;
  undefined4 in_XMM0_Da;
  float fVar9;
  undefined4 in_XMM0_Db;
  Vector local_54;
  undefined4 local_48 [12];
  Vector local_18;
  
  puVar4 = (undefined4 *)luaL_testudata();
  if (puVar4 == (undefined4 *)0x0) {
    pVVar5 = (Vector *)luaL_testudata();
    if (pVVar5 != (Vector *)0x0) goto LAB_4fc44e17;
    uVar6 = luaL_testudata();
    if (uVar6 == 0) {
      iVar7 = lua_isnumber();
      if (iVar7 == 0) {
        iVar7 = lua_isstring();
        if (iVar7 == 0) {
          return 1;
        }
        pVVar5 = (Vector *)0x0;
        lua_tolstring((undefined4 *)0x0);
        uVar6 = lua_type();
        if (0 < (int)uVar6) {
          pVVar5 = (Vector *)luaL_checkinteger();
        }
        pVVar5 = GetVectorFromPath(pVVar5,unaff_EDI,unaff_ESI);
        bVar3 = ::TerrainIsWater(pVVar5);
        puVar1 = *(uint **)(param_1 + 8);
        *puVar1 = (uint)bVar3;
        puVar1[1] = 0x7ff7a501;
        goto LAB_4fc44f1d;
      }
      luaL_checknumber();
      dVar2 = (double)CONCAT44(in_XMM0_Db,in_XMM0_Da);
      fVar9 = (float)dVar2;
      luaL_checknumber();
      bVar3 = ::TerrainIsWater((float)dVar2,(float)(double)CONCAT44(in_XMM0_Db,fVar9));
    }
    else {
      ::GetPosition(uVar6,&local_54);
      bVar3 = ::TerrainIsWater(&local_54);
    }
  }
  else {
    puVar8 = local_48;
    for (iVar7 = 0x10; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar8 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar8 = puVar8 + 1;
    }
    pVVar5 = &local_18;
LAB_4fc44e17:
    bVar3 = ::TerrainIsWater(pVVar5);
  }
  puVar1 = *(uint **)(param_1 + 8);
  *puVar1 = (uint)bVar3;
  puVar1[1] = 0x7ff7a501;
LAB_4fc44f1d:
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetTerrainHeightAndNormal  @ 4fc47221  lines 5047-5079


int __cdecl LuaBindings::GetTerrainHeightAndNormal(lua_State *param_1)

{
  int iVar1;
  uint uVar2;
  Vector *pVVar3;
  Vector *pVVar4;
  int unaff_ESI;
  lua_State *unaff_EDI;
  undefined1 uVar5;
  float *pfVar6;
  Vector *pVVar7;
  float local_24;
  Vector local_20;
  Vector local_14;
  
  iVar1 = lua_isstring();
  if (iVar1 == 0) {
    uVar2 = lua_type();
    if (0 < (int)uVar2) goto LAB_4fc47268;
LAB_4fc47262:
    iVar1 = 0;
  }
  else {
    uVar2 = lua_type();
    if ((int)uVar2 < 1) goto LAB_4fc47262;
LAB_4fc47268:
    iVar1 = lua_toboolean();
  }
  pVVar4 = (Vector *)0x0;
  uVar5 = iVar1 != 0;
  uVar2 = luaL_testudata();
  if (uVar2 == 0) {
    pVVar3 = (Vector *)luaL_testudata();
    if (pVVar3 == (Vector *)0x0) {
      iVar1 = lua_isstring();
      if (iVar1 == 0) {
        iVar1 = RequireHandle(unaff_EDI,unaff_ESI);
        ::GetPosition(iVar1,&local_14);
        TerrainGetHeightAndNormal(&local_14,&local_24,&local_20,(bool)uVar5);
        goto LAB_4fc47348;
      }
      lua_tolstring((undefined4 *)0x0);
      uVar2 = lua_type();
      if (0 < (int)uVar2) {
        pVVar4 = (Vector *)luaL_checkinteger();
      }
      pVVar7 = &local_20;
      pfVar6 = &local_24;
      pVVar3 = GetVectorFromPath(pVVar4,(char *)pfVar6,(int)pVVar7);
    }
    else {
      pVVar7 = &local_20;
      pfVar6 = &local_24;
    }
  }
  else {
    pVVar7 = &local_20;
    pVVar3 = (Vector *)(uVar2 + 0x30);
    pfVar6 = &local_24;
  }
  TerrainGetHeightAndNormal(pVVar3,pfVar6,pVVar7,(bool)uVar5);
LAB_4fc47348:
  lua_pushnumber();
  pVVar4 = NewVector(unaff_EDI);
  pVVar4->x = local_20.x;
  pVVar4->y = local_20.y;
  pVVar4->z = local_20.z;
  return 2;
}


// ---------------------------------------------------------------------
// LuaBindings::WriteToFile  @ 4fc45b51  lines 5087-5098


int __cdecl LuaBindings::WriteToFile(lua_State *param_1)

{
  lua_State *plVar1;
  uint *puVar2;
  bool bVar3;
  char *pcVar4;
  uint uVar5;
  int iVar6;
  undefined4 local_8;
  
  plVar1 = param_1;
  pcVar4 = (char *)luaL_checklstring(&local_8);
  luaL_checklstring(&param_1);
  uVar5 = lua_type();
  if ((int)uVar5 < 1) {
    iVar6 = 1;
  }
  else {
    iVar6 = lua_toboolean();
  }
  bVar3 = FormatFileMessage(pcVar4,iVar6 != 0,"%s");
  puVar2 = *(uint **)(plVar1 + 8);
  *puVar2 = (uint)bVar3;
  puVar2[1] = 0x7ff7a501;
  plVar1 = plVar1 + 8;
  *(int *)plVar1 = *(int *)plVar1 + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetPathPoints  @ 4fc4daf9  lines 5102-5121


/* WARNING: Function: _alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Unable to track spacebase fully for stack */

int __cdecl LuaBindings::GetPathPoints(lua_State *param_1)

{
  float fVar1;
  float fVar2;
  uint uVar3;
  bool bVar4;
  char *pcVar5;
  Vector *pVVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 extraout_ECX;
  uint uVar9;
  float fVar10;
  float afStackY_23c [128];
  undefined1 auStack_1e [2];
  float local_1c [4];
  uint local_c;
  float local_8;
  
  local_8 = (float)(__security_cookie ^ (uint)(local_1c + 6));
  uVar9 = 0;
  pcVar5 = (char *)luaL_checklstring((undefined4 *)0x0);
  local_c = 0;
  ::GetPathPoints(pcVar5,&local_c,(float *)0x0);
  uVar3 = local_c;
  iVar7 = local_c * -8;
  afStackY_23c[local_c * -2 + 0x83] = (float)(auStack_1e + iVar7 + -0xe);
  afStackY_23c[uVar3 * -2 + 0x82] = (float)&local_c;
  afStackY_23c[uVar3 * -2 + 0x81] = (float)pcVar5;
  afStackY_23c[uVar3 * -2 + 0x80] = 6.6054103e+09;
  bVar4 = ::GetPathPoints((char *)afStackY_23c[uVar3 * -2 + 0x81],
                          (uint *)afStackY_23c[uVar3 * -2 + 0x82],
                          (float *)afStackY_23c[uVar3 * -2 + 0x83]);
  if (bVar4) {
    afStackY_23c[uVar3 * -2 + 0x83] = 0.0;
    afStackY_23c[uVar3 * -2 + 0x82] = 6.60542e+09;
    lua_createtable((int)afStackY_23c[uVar3 * -2 + 0x83]);
    uVar8 = afStackY_23c[uVar3 * -2 + 0x83];
    if (local_c != 0) {
      do {
        afStackY_23c[uVar3 * -2 + 0x83] = (float)uVar8;
        afStackY_23c[uVar3 * -2 + 0x82] = (float)uVar8;
        fVar1 = *(float *)(auStack_1e + uVar9 * 8 + iVar7 + -10);
        fVar2 = *(float *)(auStack_1e + uVar9 * 8 + iVar7 + -0xe);
        afStackY_23c[uVar3 * -2 + 0x83] = fVar1;
        afStackY_23c[uVar3 * -2 + 0x82] = fVar2;
        afStackY_23c[uVar3 * -2 + 0x81] = 6.605445e+09;
        fVar10 = ::TerrainFindFloor(afStackY_23c[uVar3 * -2 + 0x82],afStackY_23c[uVar3 * -2 + 0x83])
        ;
        afStackY_23c[uVar3 * -2 + 0x81] = 6.605456e+09;
        pVVar6 = NewVector((lua_State *)afStackY_23c[uVar3 * -2 + 0x82]);
        uVar9 = uVar9 + 1;
        afStackY_23c[uVar3 * -2 + 0x81] = (float)uVar9;
        afStackY_23c[uVar3 * -2 + 0x80] = -NAN;
        pVVar6->x = fVar2;
        pVVar6->y = fVar10;
        pVVar6->z = fVar1;
        afStackY_23c[uVar3 * -2 + 0x80] = 6.6054666e+09;
        lua_rawseti((int)afStackY_23c[uVar3 * -2 + 0x81]);
        uVar8 = extraout_ECX;
      } while (uVar9 < local_c);
    }
    iVar7 = 1;
  }
  else {
    iVar7 = 0;
  }
  return iVar7;
}


// ---------------------------------------------------------------------
// LuaBindings::GetOwner  @ 4fc50528  lines 5125-5130


int __cdecl LuaBindings::GetOwner(lua_State *param_1)

{
  int iVar1;
  lua_State *unaff_EBP;
  int unaff_retaddr;
  
  iVar1 = RequireHandle(unaff_EBP,unaff_retaddr);
  ::GetOwner(iVar1);
  PushHandle(unaff_EBP,unaff_retaddr);
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::SetTarget  @ 4fc45ca7  lines 5134-5143


int __cdecl LuaBindings::SetTarget(lua_State *param_1)

{
  int iVar1;
  uint uVar2;
  int unaff_ESI;
  int iVar3;
  lua_State *unaff_EDI;
  
  iVar1 = RequireHandle(unaff_EDI,unaff_ESI);
  iVar3 = 0;
  uVar2 = lua_type();
  if (uVar2 != 0) {
    iVar3 = RequireHandle(unaff_EDI,unaff_ESI);
  }
  ::SetTarget(iVar1,iVar3);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::SetOwner  @ 4fc45e5c  lines 5148-5157


int __cdecl LuaBindings::SetOwner(lua_State *param_1)

{
  int iVar1;
  uint uVar2;
  int unaff_ESI;
  int iVar3;
  lua_State *unaff_EDI;
  
  iVar1 = RequireHandle(unaff_EDI,unaff_ESI);
  iVar3 = 0;
  uVar2 = lua_type();
  if (uVar2 != 0) {
    iVar3 = RequireHandle(unaff_EDI,unaff_ESI);
  }
  ::SetOwner(iVar1,iVar3);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::SetPilotClass  @ 4fc4c4f2  lines 5161-5166


int __cdecl LuaBindings::SetPilotClass(lua_State *param_1)

{
  int iVar1;
  char *pcVar2;
  int unaff_EBP;
  lua_State *unaff_ESI;
  
  iVar1 = RequireHandle(unaff_ESI,unaff_EBP);
  pcVar2 = (char *)luaL_checklstring((undefined4 *)0x0);
  ::SetPilotClass(iVar1,pcVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::AllowRandomTracks  @ 4fc452b9  lines 5170-5174


int __cdecl LuaBindings::AllowRandomTracks(lua_State *param_1)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = 1;
  uVar1 = lua_type();
  if (0 < (int)uVar1) {
    iVar2 = lua_toboolean();
  }
  ::AllowRandomTracks(iVar2 != 0);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::SetFFATeamColors  @ 4fc4c189  lines 5178-5182


int __cdecl LuaBindings::SetFFATeamColors(lua_State *param_1)

{
  TEAMCOLOR_TYPE TVar1;
  
  TVar1 = luaL_checkinteger();
  ::SetFFATeamColors(TVar1);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::SetTeamStratColors  @ 4fc44fe4  lines 5186-5190


int __cdecl LuaBindings::SetTeamStratColors(lua_State *param_1)

{
  TEAMCOLOR_TYPE TVar1;
  
  TVar1 = luaL_checkinteger();
  ::SetTeamStratColors(TVar1);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::GetFFATeamColor  @ 4fc4e502  lines 5194-5203


int __cdecl LuaBindings::GetFFATeamColor(lua_State *param_1)

{
  lua_State *plVar1;
  TEAMCOLOR_TYPE TVar2;
  int iVar3;
  int local_c;
  int local_8;
  
  plVar1 = param_1;
  TVar2 = luaL_checkinteger();
  iVar3 = luaL_checkinteger();
  ::GetFFATeamColor(TVar2,iVar3,(int *)&param_1,&local_8,&local_c);
  **(double **)(plVar1 + 8) = (double)(int)param_1;
  *(int *)(plVar1 + 8) = *(int *)(plVar1 + 8) + 8;
  **(double **)(plVar1 + 8) = (double)local_8;
  *(int *)(plVar1 + 8) = *(int *)(plVar1 + 8) + 8;
  **(double **)(plVar1 + 8) = (double)local_c;
  *(int *)(plVar1 + 8) = *(int *)(plVar1 + 8) + 8;
  return 3;
}


// ---------------------------------------------------------------------
// LuaBindings::GetFFATeamColorVector  @ 4fc4ad56  lines 5206-5211


int __cdecl LuaBindings::GetFFATeamColorVector(lua_State *param_1)

{
  TEAMCOLOR_TYPE TVar1;
  int iVar2;
  Vector *pVVar3;
  lua_State *unaff_EDI;
  float fVar4;
  float fVar5;
  float fVar6;
  int local_10;
  int local_c;
  int local_8;
  
  TVar1 = luaL_checkinteger();
  iVar2 = luaL_checkinteger();
  local_8 = 0;
  local_c = 0;
  local_10 = 0;
  ::GetFFATeamColor(TVar1,iVar2,&local_8,&local_c,&local_10);
  fVar4 = (float)local_8;
  fVar5 = (float)local_c;
  fVar6 = (float)local_10;
  pVVar3 = NewVector(unaff_EDI);
  pVVar3->x = fVar4;
  pVVar3->y = fVar5;
  pVVar3->z = fVar6;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetTeamStratColor  @ 4fc4d069  lines 5215-5224


int __cdecl LuaBindings::GetTeamStratColor(lua_State *param_1)

{
  lua_State *plVar1;
  TEAMCOLOR_TYPE TVar2;
  int iVar3;
  int local_c;
  int local_8;
  
  plVar1 = param_1;
  TVar2 = luaL_checkinteger();
  iVar3 = luaL_checkinteger();
  ::GetTeamStratColor(TVar2,iVar3,(int *)&param_1,&local_8,&local_c);
  **(double **)(plVar1 + 8) = (double)(int)param_1;
  *(int *)(plVar1 + 8) = *(int *)(plVar1 + 8) + 8;
  **(double **)(plVar1 + 8) = (double)local_8;
  *(int *)(plVar1 + 8) = *(int *)(plVar1 + 8) + 8;
  **(double **)(plVar1 + 8) = (double)local_c;
  *(int *)(plVar1 + 8) = *(int *)(plVar1 + 8) + 8;
  return 3;
}


// ---------------------------------------------------------------------
// LuaBindings::GetTeamStratColorVector  @ 4fc45e9c  lines 5227-5232


int __cdecl LuaBindings::GetTeamStratColorVector(lua_State *param_1)

{
  TEAMCOLOR_TYPE TVar1;
  int iVar2;
  Vector *pVVar3;
  lua_State *unaff_EDI;
  float fVar4;
  float fVar5;
  float fVar6;
  int local_10;
  int local_c;
  int local_8;
  
  TVar1 = luaL_checkinteger();
  iVar2 = luaL_checkinteger();
  local_8 = 0;
  local_c = 0;
  local_10 = 0;
  ::GetTeamStratColor(TVar1,iVar2,&local_8,&local_c,&local_10);
  fVar4 = (float)local_8;
  fVar5 = (float)local_c;
  fVar6 = (float)local_10;
  pVVar3 = NewVector(unaff_EDI);
  pVVar3->x = fVar4;
  pVVar3->y = fVar5;
  pVVar3->z = fVar6;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::SwapTeamStratColors  @ 4fc4df2d  lines 5236-5239


int __cdecl LuaBindings::SwapTeamStratColors(lua_State *param_1)

{
  ::SwapTeamStratColors();
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::GetTeamColorsAreFFA  @ 4fc4d238  lines 5243-5246


int __cdecl LuaBindings::GetTeamColorsAreFFA(lua_State *param_1)

{
  uint *puVar1;
  bool bVar2;
  
  bVar2 = ::GetTeamColorsAreFFA();
  puVar1 = *(uint **)(param_1 + 8);
  *puVar1 = (uint)bVar2;
  puVar1[1] = 0x7ff7a501;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::SetTeamColors  @ 4fc4cfa4  lines 5250-5254


int __cdecl LuaBindings::SetTeamColors(lua_State *param_1)

{
  TEAMCOLOR_TYPE TVar1;
  
  TVar1 = luaL_checkinteger();
  ::SetTeamColors(TVar1);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::AddPower  @ 4fc4ceb0  lines 5258-5263


int __cdecl LuaBindings::AddPower(lua_State *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = luaL_checkinteger();
  iVar2 = luaL_checkinteger();
  iVar1 = ::AddPower(iVar1,iVar2);
  **(double **)(param_1 + 8) = (double)iVar1;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::SetPower  @ 4fc4d194  lines 5267-5272


int __cdecl LuaBindings::SetPower(lua_State *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = luaL_checkinteger();
  iVar2 = luaL_checkinteger();
  iVar1 = ::SetPower(iVar1,iVar2);
  **(double **)(param_1 + 8) = (double)iVar1;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetPower  @ 4fc4acd1  lines 5276-5280


int __cdecl LuaBindings::GetPower(lua_State *param_1)

{
  int iVar1;
  
  iVar1 = luaL_checkinteger();
  iVar1 = ::GetPower(iVar1);
  **(double **)(param_1 + 8) = (double)iVar1;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetMaxPower  @ 4fc479cb  lines 5284-5288


int __cdecl LuaBindings::GetMaxPower(lua_State *param_1)

{
  int iVar1;
  
  iVar1 = luaL_checkinteger();
  iVar1 = ::GetMaxPower(iVar1);
  **(double **)(param_1 + 8) = (double)iVar1;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::AddMaxPower  @ 4fc4d968  lines 5292-5298


int __cdecl LuaBindings::AddMaxPower(lua_State *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = luaL_checkinteger();
  iVar2 = luaL_checkinteger();
  ::AddMaxPower(iVar1,iVar2);
  iVar1 = ::GetMaxPower(iVar1);
  **(double **)(param_1 + 8) = (double)iVar1;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::SetMaxPower  @ 4fc47a3e  lines 5302-5308


int __cdecl LuaBindings::SetMaxPower(lua_State *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = luaL_checkinteger();
  iVar2 = luaL_checkinteger();
  ::SetMaxPower(iVar1,iVar2);
  iVar1 = ::GetMaxPower(iVar1);
  **(double **)(param_1 + 8) = (double)iVar1;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetTeamStratIndividualColor  @ 4fc47ef7  lines 5312-5321


int __cdecl LuaBindings::GetTeamStratIndividualColor(lua_State *param_1)

{
  lua_State *plVar1;
  TEAMCOLOR_TYPE TVar2;
  int iVar3;
  int local_c;
  int local_8;
  
  plVar1 = param_1;
  TVar2 = luaL_checkinteger();
  iVar3 = luaL_checkinteger();
  ::GetTeamStratIndividualColor(TVar2,iVar3,(int *)&param_1,&local_8,&local_c);
  **(double **)(plVar1 + 8) = (double)(int)param_1;
  *(int *)(plVar1 + 8) = *(int *)(plVar1 + 8) + 8;
  **(double **)(plVar1 + 8) = (double)local_8;
  *(int *)(plVar1 + 8) = *(int *)(plVar1 + 8) + 8;
  **(double **)(plVar1 + 8) = (double)local_c;
  *(int *)(plVar1 + 8) = *(int *)(plVar1 + 8) + 8;
  return 3;
}


// ---------------------------------------------------------------------
// LuaBindings::GetTeamStratIndividualColorVector  @ 4fc4678d  lines 5324-5329


int __cdecl LuaBindings::GetTeamStratIndividualColorVector(lua_State *param_1)

{
  TEAMCOLOR_TYPE TVar1;
  int iVar2;
  Vector *pVVar3;
  lua_State *unaff_EDI;
  float fVar4;
  float fVar5;
  float fVar6;
  int local_10;
  int local_c;
  int local_8;
  
  TVar1 = luaL_checkinteger();
  iVar2 = luaL_checkinteger();
  local_8 = 0;
  local_c = 0;
  local_10 = 0;
  ::GetTeamStratIndividualColor(TVar1,iVar2,&local_8,&local_c,&local_10);
  fVar4 = (float)local_8;
  fVar5 = (float)local_c;
  fVar6 = (float)local_10;
  pVVar3 = NewVector(unaff_EDI);
  pVVar3->x = fVar4;
  pVVar3->y = fVar5;
  pVVar3->z = fVar6;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetMapTRNFilename  @ 4fc4cf1d  lines 5333-5336


int __cdecl LuaBindings::GetMapTRNFilename(lua_State *param_1)

{
  ::GetMapTRNFilename();
  lua_pushstring();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::IsNotDeadAndPilot  @ 4fc485d0  lines 5340-5344


int __cdecl LuaBindings::IsNotDeadAndPilot(lua_State *param_1)

{
  uint *puVar1;
  bool bVar2;
  int iVar3;
  int unaff_EBP;
  lua_State *unaff_ESI;
  
  iVar3 = RequireHandle(unaff_ESI,unaff_EBP);
  bVar2 = IsNotDeadAndPilot2(iVar3);
  puVar1 = *(uint **)(param_1 + 8);
  *puVar1 = (uint)bVar2;
  puVar1[1] = 0x7ff7a501;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetLabel  @ 4fc4c7de  lines 5348-5357


int __cdecl LuaBindings::GetLabel(lua_State *param_1)

{
  int iVar1;
  char *pcVar2;
  int unaff_EBP;
  lua_State *unaff_ESI;
  
  iVar1 = RequireHandle(unaff_ESI,unaff_EBP);
  pcVar2 = ::GetLabel(iVar1);
  if (pcVar2 == (char *)0x0) {
    *(undefined4 *)(*(int *)(param_1 + 8) + 4) = 0x7ff7a500;
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  }
  else {
    lua_pushstring();
  }
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::SetLabel  @ 4fc4b0c4  lines 5361-5366


int __cdecl LuaBindings::SetLabel(lua_State *param_1)

{
  int iVar1;
  char *pcVar2;
  int unaff_EBP;
  lua_State *unaff_ESI;
  
  iVar1 = RequireHandle(unaff_ESI,unaff_EBP);
  pcVar2 = (char *)luaL_checklstring((undefined4 *)0x0);
  ::SetLabel(iVar1,pcVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::GetTap  @ 4fc4fe0c  lines 5370-5376


int __cdecl LuaBindings::GetTap(lua_State *param_1)

{
  int iVar1;
  int iVar2;
  int unaff_EBP;
  lua_State *unaff_ESI;
  
  iVar1 = RequireHandle(unaff_ESI,unaff_EBP);
  iVar2 = luaL_checkinteger();
  ::GetTap(iVar1,iVar2);
  PushHandle(unaff_ESI,unaff_EBP);
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::SetTap  @ 4fc4c033  lines 5380-5386


int __cdecl LuaBindings::SetTap(lua_State *param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int unaff_ESI;
  lua_State *unaff_EDI;
  
  iVar1 = RequireHandle(unaff_EDI,unaff_ESI);
  iVar2 = luaL_checkinteger();
  uVar3 = luaL_testudata();
  ::SetTap(iVar1,iVar2,uVar3);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::GetCurLocalAmmo  @ 4fc4bd43  lines 5390-5395


int __cdecl LuaBindings::GetCurLocalAmmo(lua_State *param_1)

{
  int iVar1;
  int iVar2;
  lua_State *unaff_ESI;
  int in_stack_ffffffec;
  
  iVar1 = RequireHandle(unaff_ESI,in_stack_ffffffec);
  iVar2 = luaL_checkinteger();
  ::GetCurLocalAmmo(iVar1,iVar2);
  lua_pushnumber();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::AddLocalAmmo  @ 4fc4bcd3  lines 5399-5405


int __cdecl LuaBindings::AddLocalAmmo(lua_State *param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  lua_State *unaff_ESI;
  undefined4 in_XMM0_Da;
  float fVar3;
  undefined4 in_XMM0_Db;
  
  iVar1 = RequireHandle(unaff_ESI,in_ECX);
  luaL_checknumber();
  fVar3 = (float)(double)CONCAT44(in_XMM0_Db,in_XMM0_Da);
  iVar2 = luaL_checkinteger();
  ::AddLocalAmmo(iVar1,fVar3,iVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::GetMaxLocalAmmo  @ 4fc459d8  lines 5409-5414


int __cdecl LuaBindings::GetMaxLocalAmmo(lua_State *param_1)

{
  int iVar1;
  int iVar2;
  lua_State *unaff_ESI;
  int in_stack_ffffffec;
  
  iVar1 = RequireHandle(unaff_ESI,in_stack_ffffffec);
  iVar2 = luaL_checkinteger();
  ::GetMaxLocalAmmo(iVar1,iVar2);
  lua_pushnumber();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::SetCurLocalAmmo  @ 4fc45f1c  lines 5418-5424


int __cdecl LuaBindings::SetCurLocalAmmo(lua_State *param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  lua_State *unaff_ESI;
  undefined4 in_XMM0_Da;
  float fVar3;
  undefined4 in_XMM0_Db;
  
  iVar1 = RequireHandle(unaff_ESI,in_ECX);
  luaL_checknumber();
  fVar3 = (float)(double)CONCAT44(in_XMM0_Db,in_XMM0_Da);
  iVar2 = luaL_checkinteger();
  ::SetCurLocalAmmo(iVar1,fVar3,iVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::GetNetworkListItem  @ 4fc4a906  lines 5428-5439


int __cdecl LuaBindings::GetNetworkListItem(lua_State *param_1)

{
  NETWORK_LIST_TYPE NVar1;
  uint uVar2;
  char *pcVar3;
  
  NVar1 = luaL_checkinteger();
  uVar2 = luaL_checkinteger();
  pcVar3 = ::GetNetworkListItem(NVar1,uVar2);
  if (pcVar3 == (char *)0x0) {
    *(undefined4 *)(*(int *)(param_1 + 8) + 4) = 0x7ff7a500;
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  }
  else {
    lua_pushstring();
  }
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetNetworkListCount  @ 4fc4b5ba  lines 5443-5447


int __cdecl LuaBindings::GetNetworkListCount(lua_State *param_1)

{
  NETWORK_LIST_TYPE NVar1;
  uint uVar2;
  
  NVar1 = luaL_checkinteger();
  uVar2 = ::GetNetworkListCount(NVar1);
  **(double **)(param_1 + 8) = (double)(int)uVar2;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetTeamRelationship  @ 4fc4dc7a  lines 5451-5456


int __cdecl LuaBindings::GetTeamRelationship(lua_State *param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  lua_State *unaff_ESI;
  
  iVar1 = RequireHandle(unaff_ESI,in_ECX);
  iVar2 = RequireHandle(unaff_ESI,in_ECX);
  ::GetTeamRelationship(iVar1,iVar2);
  lua_pushnumber();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::HasPilot  @ 4fc4d1d6  lines 5460-5464


int __cdecl LuaBindings::HasPilot(lua_State *param_1)

{
  uint *puVar1;
  bool bVar2;
  int iVar3;
  int unaff_EBP;
  lua_State *unaff_ESI;
  
  iVar3 = RequireHandle(unaff_ESI,unaff_EBP);
  bVar2 = ::HasPilot(iVar3);
  puVar1 = *(uint **)(param_1 + 8);
  *puVar1 = (uint)bVar2;
  puVar1[1] = 0x7ff7a501;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetPilotClass  @ 4fc4642b  lines 5468-5477


int __cdecl LuaBindings::GetPilotClass(lua_State *param_1)

{
  int iVar1;
  char *pcVar2;
  int unaff_EBP;
  lua_State *unaff_ESI;
  
  iVar1 = RequireHandle(unaff_ESI,unaff_EBP);
  pcVar2 = ::GetPilotClass(iVar1);
  if (pcVar2 == (char *)0x0) {
    *(undefined4 *)(*(int *)(param_1 + 8) + 4) = 0x7ff7a500;
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  }
  else {
    lua_pushstring();
  }
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetBaseScrapCost  @ 4fc4fcf5  lines 5481-5485


int __cdecl LuaBindings::GetBaseScrapCost(lua_State *param_1)

{
  int iVar1;
  int unaff_EBP;
  lua_State *unaff_ESI;
  
  iVar1 = RequireHandle(unaff_ESI,unaff_EBP);
  iVar1 = ::GetBaseScrapCost(iVar1);
  **(double **)(param_1 + 8) = (double)iVar1;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetActualScrapCost  @ 4fc46095  lines 5489-5493


int __cdecl LuaBindings::GetActualScrapCost(lua_State *param_1)

{
  int iVar1;
  int unaff_EBP;
  lua_State *unaff_ESI;
  
  iVar1 = RequireHandle(unaff_ESI,unaff_EBP);
  iVar1 = ::GetActualScrapCost(iVar1);
  **(double **)(param_1 + 8) = (double)iVar1;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::PetWatchdogThread  @ 4fc4aea0  lines 5497-5500


int __cdecl LuaBindings::PetWatchdogThread(lua_State *param_1)

{
  ::PetWatchdogThread();
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::GetPerceivedTeam  @ 4fc45089  lines 5504-5508


int __cdecl LuaBindings::GetPerceivedTeam(lua_State *param_1)

{
  int iVar1;
  int unaff_EBP;
  lua_State *unaff_ESI;
  
  iVar1 = RequireHandle(unaff_ESI,unaff_EBP);
  iVar1 = ::GetPerceivedTeam(iVar1);
  **(double **)(param_1 + 8) = (double)iVar1;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::SetLastCurrentPosition  @ 4fc49f45  lines 5512-5530


int __cdecl LuaBindings::SetLastCurrentPosition(lua_State *param_1)

{
  int iVar1;
  Matrix *pMVar2;
  int iVar3;
  int unaff_ESI;
  lua_State *unaff_EDI;
  Matrix *pMVar4;
  Matrix local_88;
  Matrix local_48;
  
  iVar1 = RequireHandle(unaff_EDI,unaff_ESI);
  pMVar2 = (Matrix *)luaL_testudata();
  if (pMVar2 == (Matrix *)0x0) {
    ::GetPosition(iVar1,&local_48);
    pMVar2 = &local_48;
  }
  pMVar4 = &local_88;
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    (pMVar4->right).x = (pMVar2->right).x;
    pMVar2 = (Matrix *)&(pMVar2->right).y;
    pMVar4 = (Matrix *)&(pMVar4->right).y;
  }
  pMVar2 = (Matrix *)luaL_testudata();
  if (pMVar2 != (Matrix *)0x0) {
    ::SetLastCurrentPosition(iVar1,pMVar2,&local_88);
  }
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::GetRemainingLifespan  @ 4fc48abb  lines 5534-5542


int __cdecl LuaBindings::GetRemainingLifespan(lua_State *param_1)

{
  int iVar1;
  int in_ECX;
  lua_State *unaff_ESI;
  float fVar2;
  
  iVar1 = RequireHandle(unaff_ESI,in_ECX);
  fVar2 = ::GetRemainingLifespan(iVar1);
  if (fVar2 == __real_bf800000) {
    *(undefined4 *)(*(int *)(param_1 + 8) + 4) = 0x7ff7a500;
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  }
  else {
    lua_pushnumber();
  }
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetAllSpawnpoints  @ 4fc4d7c9  lines 5546-5574


int __cdecl LuaBindings::GetAllSpawnpoints(lua_State *param_1)

{
  float *pfVar1;
  uint uVar2;
  int iVar3;
  Vector *pVVar4;
  int unaff_ESI;
  lua_State *unaff_EDI;
  SpawnpointInfo *local_28;
  uint local_24;
  int local_20;
  uint local_1c;
  float local_18;
  float fStack_14;
  float fStack_10;
  
  uVar2 = lua_type();
  local_24 = 0;
  if ((int)uVar2 < 1) {
    iVar3 = 0;
  }
  else {
    iVar3 = luaL_checkinteger();
  }
  uVar2 = ::GetAllSpawnpoints(&local_28,iVar3);
  local_1c = uVar2;
  lua_createtable(0);
  if (uVar2 != 0) {
    local_20 = 0;
    do {
      iVar3 = local_20;
      lua_createtable(7);
      pfVar1 = (float *)((int)&(local_28->m_Position).x + iVar3);
      local_18 = *pfVar1;
      fStack_14 = pfVar1[1];
      fStack_10 = pfVar1[2];
      pVVar4 = NewVector(unaff_EDI);
      pVVar4->x = local_18;
      pVVar4->y = fStack_14;
      pVVar4->z = fStack_10;
      lua_setfield();
      iVar3 = local_20;
      **(double **)(param_1 + 8) = (double)*(int *)((int)&local_28->m_Team + local_20);
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
      lua_setfield();
      PushHandle(unaff_EDI,unaff_ESI);
      lua_setfield();
      lua_pushnumber();
      lua_setfield();
      lua_pushnumber();
      lua_setfield();
      lua_pushnumber();
      lua_setfield();
      lua_pushnumber();
      lua_setfield();
      uVar2 = local_24 + 1;
      local_24 = uVar2;
      lua_rawseti(uVar2);
      local_20 = iVar3 + 0x24;
    } while (uVar2 < local_1c);
  }
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetPlan  @ 4fc4f658  lines 5578-5587


int __cdecl LuaBindings::GetPlan(lua_State *param_1)

{
  int iVar1;
  char *pcVar2;
  
  iVar1 = luaL_checkinteger();
  pcVar2 = ::GetPlan(iVar1);
  if (pcVar2 == (char *)0x0) {
    *(undefined4 *)(*(int *)(param_1 + 8) + 4) = 0x7ff7a500;
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  }
  else {
    lua_pushstring();
  }
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetIndependence  @ 4fc4702f  lines 5591-5599


int __cdecl LuaBindings::GetIndependence(lua_State *param_1)

{
  int iVar1;
  int unaff_EBP;
  lua_State *unaff_ESI;
  
  iVar1 = RequireHandle(unaff_ESI,unaff_EBP);
  iVar1 = ::GetIndependence(iVar1);
  if (iVar1 == -1) {
    *(undefined4 *)((int)*(double **)(param_1 + 8) + 4) = 0x7ff7a500;
  }
  else {
    **(double **)(param_1 + 8) = (double)iVar1;
  }
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetSkill  @ 4fc45df8  lines 5603-5611


int __cdecl LuaBindings::GetSkill(lua_State *param_1)

{
  int iVar1;
  int unaff_EBP;
  lua_State *unaff_ESI;
  
  iVar1 = RequireHandle(unaff_ESI,unaff_EBP);
  iVar1 = ::GetSkill(iVar1);
  if (iVar1 == -1) {
    *(undefined4 *)((int)*(double **)(param_1 + 8) + 4) = 0x7ff7a500;
  }
  else {
    **(double **)(param_1 + 8) = (double)iVar1;
  }
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetObjectiveName  @ 4fc4dc3e  lines 5615-5624


int __cdecl LuaBindings::GetObjectiveName(lua_State *param_1)

{
  int iVar1;
  char *pcVar2;
  int unaff_EBP;
  lua_State *unaff_ESI;
  
  iVar1 = RequireHandle(unaff_ESI,unaff_EBP);
  pcVar2 = ::GetObjectiveName(iVar1);
  if (pcVar2 == (char *)0x0) {
    *(undefined4 *)(*(int *)(param_1 + 8) + 4) = 0x7ff7a500;
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  }
  else {
    lua_pushstring();
  }
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetWeaponMask  @ 4fc4b190  lines 5628-5632


int __cdecl LuaBindings::GetWeaponMask(lua_State *param_1)

{
  int iVar1;
  int unaff_EBP;
  lua_State *in_stack_fffffff8;
  
  iVar1 = RequireHandle(in_stack_fffffff8,unaff_EBP);
  ::GetWeaponMask(iVar1);
  lua_pushnumber();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::SetInterpolablePosition  @ 4fc4845d  lines 5637-5659


int __cdecl LuaBindings::SetInterpolablePosition(lua_State *param_1)

{
  int iVar1;
  Matrix *pMVar2;
  uint uVar3;
  int iVar4;
  Matrix *pMVar5;
  Vector *pVVar6;
  Vector *pVVar7;
  int unaff_ESI;
  lua_State *unaff_EDI;
  
  iVar1 = RequireHandle(unaff_EDI,unaff_ESI);
  pMVar2 = (Matrix *)luaL_testudata();
  if (pMVar2 == (Matrix *)0x0) {
    pVVar6 = (Vector *)luaL_testudata();
    if (pVVar6 != (Vector *)0x0) {
      pVVar7 = (Vector *)luaL_testudata();
      if (pVVar7 == (Vector *)0x0) {
        pVVar7 = (Vector *)0x0;
      }
      ::SetInterpolablePosition(iVar1,pVVar6,pVVar7);
    }
  }
  else {
    uVar3 = lua_type();
    if ((int)uVar3 < 1) {
      iVar4 = 1;
    }
    else {
      iVar4 = lua_toboolean();
    }
    pMVar5 = (Matrix *)luaL_testudata();
    if (pMVar5 == (Matrix *)0x0) {
      pMVar5 = (Matrix *)0x0;
    }
    ::SetInterpolablePosition(iVar1,pMVar2,pMVar5,iVar4 != 0);
  }
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::SecondsToTurns  @ 4fc500dd  lines 5663-5667


int __cdecl LuaBindings::SecondsToTurns(lua_State *param_1)

{
  double in_XMM0_Qa;
  
  luaL_checknumber();
  ::SecondsToTurns((float)in_XMM0_Qa);
  lua_pushnumber();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::TurnsToSeconds  @ 4fc4aecd  lines 5670-5674


int __cdecl LuaBindings::TurnsToSeconds(lua_State *param_1)

{
  int iVar1;
  
  iVar1 = luaL_checkinteger();
  ::TurnsToSeconds(iVar1);
  lua_pushnumber();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetLifeSpan  @ 4fc4680d  lines 5678-5686


int __cdecl LuaBindings::GetLifeSpan(lua_State *param_1)

{
  int iVar1;
  int in_ECX;
  lua_State *unaff_ESI;
  float fVar2;
  
  iVar1 = RequireHandle(unaff_ESI,in_ECX);
  fVar2 = ::GetLifeSpan(iVar1);
  if (fVar2 == __real_bf800000) {
    *(undefined4 *)(*(int *)(param_1 + 8) + 4) = 0x7ff7a500;
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  }
  else {
    lua_pushnumber();
  }
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetCurrentCommandWhere  @ 4fc4daba  lines 5690-5694


int __cdecl LuaBindings::GetCurrentCommandWhere(lua_State *param_1)

{
  int iVar1;
  Vector *pVVar2;
  int unaff_ESI;
  lua_State *unaff_EDI;
  Vector local_1c;
  float local_10;
  float fStack_c;
  float fStack_8;
  
  iVar1 = RequireHandle(unaff_EDI,unaff_ESI);
  pVVar2 = ::GetCurrentCommandWhere(&local_1c,iVar1);
  local_10 = pVVar2->x;
  fStack_c = pVVar2->y;
  fStack_8 = pVVar2->z;
  pVVar2 = NewVector(unaff_EDI);
  pVVar2->x = local_10;
  pVVar2->y = fStack_c;
  pVVar2->z = fStack_8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetAllGameObjectHandles  @ 4fc4e57c  lines 5698-5713


/* WARNING: Function: _alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Unable to track spacebase fully for stack */

int __cdecl LuaBindings::GetAllGameObjectHandles(lua_State *param_1)

{
  uint uVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  undefined4 uStackY_20;
  undefined4 local_c;
  undefined4 local_8;
  
  local_8 = __security_cookie ^ (int)register0x00000010 - 4U;
  uVar4 = 0;
  local_c = 0;
  uStackY_20 = 0x4fc4e59d;
  ::GetAllGameObjectHandles(&local_c,(int *)0x0);
  uVar1 = local_c;
  iVar3 = local_c * -4;
  *(int *)((int)register0x00000010 + iVar3 + -0x18) = (int)register0x00000010 + iVar3 + -0x14;
  *(undefined4 **)((int)register0x00000010 + iVar3 + -0x1c) = &local_c;
  (&uStackY_20)[-uVar1] = 0x4fc4e5b7;
  bVar2 = ::GetAllGameObjectHandles
                    (*(uint **)((int)register0x00000010 + iVar3 + -0x1c),
                     *(int **)((int)register0x00000010 + iVar3 + -0x18));
  if (bVar2) {
    *(undefined4 *)((int)register0x00000010 + iVar3 + -0x18) = 0;
    *(undefined4 *)((int)register0x00000010 + iVar3 + -0x1c) = 0x4fc4e5c9;
    lua_createtable(*(int *)((int)register0x00000010 + iVar3 + -0x18));
    if (local_c != 0) {
      do {
        *(undefined4 *)((int)register0x00000010 + iVar3 + -0x18) = 0x4fc4e5da;
        PushHandle(*(lua_State **)((int)register0x00000010 + iVar3 + -0x14),
                   *(int *)((int)register0x00000010 + iVar3 + -0x10));
        uVar4 = uVar4 + 1;
        *(uint *)((int)register0x00000010 + iVar3 + -0x18) = uVar4;
        *(undefined4 *)((int)register0x00000010 + iVar3 + -0x1c) = 0xfffffffe;
        *(undefined4 *)((int)register0x00000010 + iVar3 + -0x1c) = 0x4fc4e5e4;
        lua_rawseti(*(int *)((int)register0x00000010 + iVar3 + -0x18));
      } while (uVar4 < local_c);
    }
    iVar3 = 1;
  }
  else {
    iVar3 = 0;
  }
  return iVar3;
}


// ---------------------------------------------------------------------
// LuaBindings::GetOmega  @ 4fc4a42c  lines 5717-5721


int __cdecl LuaBindings::GetOmega(lua_State *param_1)

{
  int iVar1;
  Vector *pVVar2;
  int unaff_ESI;
  lua_State *unaff_EDI;
  Vector local_1c;
  float local_10;
  float fStack_c;
  float fStack_8;
  
  iVar1 = RequireHandle(unaff_EDI,unaff_ESI);
  pVVar2 = ::GetOmega(&local_1c,iVar1);
  local_10 = pVVar2->x;
  fStack_c = pVVar2->y;
  fStack_8 = pVVar2->z;
  pVVar2 = NewVector(unaff_EDI);
  pVVar2->x = local_10;
  pVVar2->y = fStack_c;
  pVVar2->z = fStack_8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::SetOmega  @ 4fc4de58  lines 5725-5731


int __cdecl LuaBindings::SetOmega(lua_State *param_1)

{
  int iVar1;
  Vector *pVVar2;
  int unaff_EBP;
  lua_State *unaff_ESI;
  
  iVar1 = RequireHandle(unaff_ESI,unaff_EBP);
  pVVar2 = (Vector *)luaL_checkudata("Vector");
  ::SetOmega(iVar1,pVVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::IsCraftButNotPerson  @ 4fc4aaf3  lines 5735-5739


int __cdecl LuaBindings::IsCraftButNotPerson(lua_State *param_1)

{
  uint *puVar1;
  bool bVar2;
  int iVar3;
  int unaff_EBP;
  lua_State *unaff_ESI;
  
  iVar3 = RequireHandle(unaff_ESI,unaff_EBP);
  bVar2 = ::IsCraftButNotPerson(iVar3);
  puVar1 = *(uint **)(param_1 + 8);
  *puVar1 = (uint)bVar2;
  puVar1[1] = 0x7ff7a501;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::IsCraftOrPerson  @ 4fc46f6d  lines 5743-5747


int __cdecl LuaBindings::IsCraftOrPerson(lua_State *param_1)

{
  uint *puVar1;
  bool bVar2;
  int iVar3;
  int unaff_EBP;
  lua_State *unaff_ESI;
  
  iVar3 = RequireHandle(unaff_ESI,unaff_EBP);
  bVar2 = ::IsCraftOrPerson(iVar3);
  puVar1 = *(uint **)(param_1 + 8);
  *puVar1 = (uint)bVar2;
  puVar1[1] = 0x7ff7a501;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::IsBuilding  @ 4fc4c1a3  lines 5751-5755


int __cdecl LuaBindings::IsBuilding(lua_State *param_1)

{
  uint *puVar1;
  bool bVar2;
  int iVar3;
  int unaff_EBP;
  lua_State *unaff_ESI;
  
  iVar3 = RequireHandle(unaff_ESI,unaff_EBP);
  bVar2 = ::IsBuilding(iVar3);
  puVar1 = *(uint **)(param_1 + 8);
  *puVar1 = (uint)bVar2;
  puVar1[1] = 0x7ff7a501;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::IsPowerup  @ 4fc4b535  lines 5759-5763


int __cdecl LuaBindings::IsPowerup(lua_State *param_1)

{
  uint *puVar1;
  bool bVar2;
  int iVar3;
  int unaff_EBP;
  lua_State *unaff_ESI;
  
  iVar3 = RequireHandle(unaff_ESI,unaff_EBP);
  bVar2 = ::IsPowerup(iVar3);
  puVar1 = *(uint **)(param_1 + 8);
  *puVar1 = (uint)bVar2;
  puVar1[1] = 0x7ff7a501;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::SetCanSnipe  @ 4fc494b5  lines 5767-5772


int __cdecl LuaBindings::SetCanSnipe(lua_State *param_1)

{
  int iVar1;
  int iVar2;
  int unaff_EBP;
  lua_State *unaff_ESI;
  
  iVar1 = RequireHandle(unaff_ESI,unaff_EBP);
  iVar2 = luaL_checkinteger();
  ::SetCanSnipe(iVar1,iVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::GetCanSnipe  @ 4fc47a88  lines 5776-5780


int __cdecl LuaBindings::GetCanSnipe(lua_State *param_1)

{
  uint *puVar1;
  bool bVar2;
  int iVar3;
  int unaff_EBP;
  lua_State *unaff_ESI;
  
  iVar3 = RequireHandle(unaff_ESI,unaff_EBP);
  bVar2 = ::GetCanSnipe(iVar3);
  puVar1 = *(uint **)(param_1 + 8);
  *puVar1 = (uint)bVar2;
  puVar1[1] = 0x7ff7a501;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::WhoIsTargeting  @ 4fc4e764  lines 5784-5800


/* WARNING: Function: _alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Unable to track spacebase fully for stack */

int __cdecl LuaBindings::WhoIsTargeting(lua_State *param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int unaff_ESI;
  lua_State *unaff_EDI;
  undefined4 uStackY_2c;
  undefined1 auStack_e [2];
  uint local_c [2];
  
  local_c[1] = __security_cookie ^ (uint)(local_c + 2);
  iVar2 = RequireHandle(unaff_EDI,unaff_ESI);
  uVar4 = 0;
  local_c[0] = 0;
  uStackY_2c = 0x4fc4e797;
  ::WhoIsTargeting(local_c,(int *)0x0,iVar2);
  iVar3 = local_c[0] * -4;
  *(int *)(auStack_e + iVar3 + -0x12) = iVar2;
  *(undefined1 **)(auStack_e + iVar3 + -0x16) = auStack_e + iVar3 + -0xe;
  *(uint **)(auStack_e + iVar3 + -0x1a) = local_c;
  *(undefined4 *)(auStack_e + iVar3 + -0x1e) = 0x4fc4e7b2;
  bVar1 = ::WhoIsTargeting(*(uint **)(auStack_e + iVar3 + -0x1a),
                           *(int **)(auStack_e + iVar3 + -0x16),*(int *)(auStack_e + iVar3 + -0x12))
  ;
  if (bVar1) {
    *(undefined4 *)(auStack_e + iVar3 + -0x12) = 0;
    *(undefined4 *)(auStack_e + iVar3 + -0x16) = 0x4fc4e7c5;
    lua_createtable(*(int *)(auStack_e + iVar3 + -0x12));
    if (local_c[0] != 0) {
      do {
        *(undefined4 *)(auStack_e + iVar3 + -0x12) = 0x4fc4e7d9;
        PushHandle(*(lua_State **)(auStack_e + iVar3 + -0xe),*(int *)(auStack_e + iVar3 + -10));
        uVar4 = uVar4 + 1;
        *(uint *)(auStack_e + iVar3 + -0x12) = uVar4;
        *(undefined4 *)(auStack_e + iVar3 + -0x16) = 0xfffffffe;
        *(undefined4 *)(auStack_e + iVar3 + -0x16) = 0x4fc4e7e3;
        lua_rawseti(*(int *)(auStack_e + iVar3 + -0x12));
      } while (uVar4 < local_c[0]);
    }
    iVar3 = 1;
  }
  else {
    iVar3 = 0;
  }
  return iVar3;
}


// ---------------------------------------------------------------------
// LuaBindings::GetPilotOdf  @ 4fc4798f  lines 5804-5813


int __cdecl LuaBindings::GetPilotOdf(lua_State *param_1)

{
  int iVar1;
  char *pcVar2;
  int unaff_EBP;
  lua_State *unaff_ESI;
  
  iVar1 = RequireHandle(unaff_ESI,unaff_EBP);
  pcVar2 = ::GetPilotOdf(iVar1);
  if (pcVar2 == (char *)0x0) {
    *(undefined4 *)(*(int *)(param_1 + 8) + 4) = 0x7ff7a500;
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  }
  else {
    lua_pushstring();
  }
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::SetTeamNameForStat  @ 4fc4a1ce  lines 5817-5822


int __cdecl LuaBindings::SetTeamNameForStat(lua_State *param_1)

{
  int iVar1;
  char *pcVar2;
  
  iVar1 = luaL_checkinteger();
  pcVar2 = (char *)luaL_checklstring((undefined4 *)0x0);
  ::SetTeamNameForStat(iVar1,pcVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::CanBuild  @ 4fc4fb3e  lines 5826-5830


int __cdecl LuaBindings::CanBuild(lua_State *param_1)

{
  uint *puVar1;
  bool bVar2;
  int iVar3;
  int unaff_EBP;
  lua_State *unaff_ESI;
  
  iVar3 = RequireHandle(unaff_ESI,unaff_EBP);
  bVar2 = ::CanBuild(iVar3);
  puVar1 = *(uint **)(param_1 + 8);
  *puVar1 = (uint)bVar2;
  puVar1[1] = 0x7ff7a501;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::IsBusy  @ 4fc463ce  lines 5834-5838


int __cdecl LuaBindings::IsBusy(lua_State *param_1)

{
  uint *puVar1;
  bool bVar2;
  int iVar3;
  int unaff_EBP;
  lua_State *unaff_ESI;
  
  iVar3 = RequireHandle(unaff_ESI,unaff_EBP);
  bVar2 = ::IsBusy(iVar3);
  puVar1 = *(uint **)(param_1 + 8);
  *puVar1 = (uint)bVar2;
  puVar1[1] = 0x7ff7a501;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetBuildClass  @ 4fc48ccb  lines 5843-5852


int __cdecl LuaBindings::GetBuildClass(lua_State *param_1)

{
  int iVar1;
  char *pcVar2;
  int unaff_EBP;
  lua_State *unaff_ESI;
  
  iVar1 = RequireHandle(unaff_ESI,unaff_EBP);
  pcVar2 = ::GetBuildClass(iVar1);
  if (pcVar2 == (char *)0x0) {
    *(undefined4 *)(*(int *)(param_1 + 8) + 4) = 0x7ff7a500;
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  }
  else {
    lua_pushstring();
  }
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetQueuedItem  @ 4fc458d9  lines 5856-5866


int __cdecl LuaBindings::GetQueuedItem(lua_State *param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  int unaff_ESI;
  lua_State *unaff_EDI;
  
  iVar1 = RequireHandle(unaff_EDI,unaff_ESI);
  uVar2 = lua_type();
  if ((int)uVar2 < 1) {
    iVar3 = 0;
  }
  else {
    iVar3 = luaL_checkinteger();
  }
  pcVar4 = ::GetQueuedItem(iVar1,iVar3);
  if (pcVar4 == (char *)0x0) {
    *(undefined4 *)(*(int *)(param_1 + 8) + 4) = 0x7ff7a500;
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  }
  else {
    lua_pushstring();
  }
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetMissionFilename  @ 4fc4add6  lines 5870-5873


int __cdecl LuaBindings::GetMissionFilename(lua_State *param_1)

{
  ::GetMissionFilename();
  lua_pushstring();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetEjectRatio  @ 4fc45da2  lines 5877-5885


int __cdecl LuaBindings::GetEjectRatio(lua_State *param_1)

{
  int iVar1;
  int in_ECX;
  lua_State *unaff_ESI;
  float fVar2;
  
  iVar1 = RequireHandle(unaff_ESI,in_ECX);
  fVar2 = ::GetEjectRatio(iVar1);
  if (fVar2 == __real_bf800000) {
    *(undefined4 *)(*(int *)(param_1 + 8) + 4) = 0x7ff7a500;
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  }
  else {
    lua_pushnumber();
  }
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::SetEjectRatio  @ 4fc461ce  lines 5889-5894


int __cdecl LuaBindings::SetEjectRatio(lua_State *param_1)

{
  int iVar1;
  int unaff_EBP;
  lua_State *unaff_ESI;
  undefined4 in_XMM0_Da;
  undefined4 in_XMM0_Db;
  
  iVar1 = RequireHandle(unaff_ESI,unaff_EBP);
  luaL_checknumber();
  ::SetEjectRatio(iVar1,(float)(double)CONCAT44(in_XMM0_Db,in_XMM0_Da));
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::GetLookFront  @ 4fc4b440  lines 5898-5902


int __cdecl LuaBindings::GetLookFront(lua_State *param_1)

{
  int iVar1;
  Vector *pVVar2;
  int unaff_ESI;
  lua_State *unaff_EDI;
  Vector local_10;
  
  iVar1 = RequireHandle(unaff_EDI,unaff_ESI);
  ::GetLookFront(iVar1,&local_10);
  pVVar2 = NewVector(unaff_EDI);
  pVVar2->x = local_10.x;
  pVVar2->y = local_10.y;
  pVVar2->z = local_10.z;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::PauseAnimation  @ 4fc4cb6b  lines 5906-5910


int __cdecl LuaBindings::PauseAnimation(lua_State *param_1)

{
  int iVar1;
  int unaff_EBP;
  lua_State *in_stack_fffffff8;
  
  iVar1 = RequireHandle(in_stack_fffffff8,unaff_EBP);
  ::PauseAnimation(iVar1);
  lua_pushnumber();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::ResumeAnimation  @ 4fc4ff9c  lines 5914-5919


int __cdecl LuaBindings::ResumeAnimation(lua_State *param_1)

{
  int iVar1;
  uint uVar2;
  int unaff_ESI;
  int iVar3;
  lua_State *unaff_EDI;
  
  iVar3 = 1;
  iVar1 = RequireHandle(unaff_EDI,unaff_ESI);
  uVar2 = lua_type();
  if (0 < (int)uVar2) {
    iVar3 = luaL_checkinteger();
  }
  ::ResumeAnimation(iVar1,iVar3);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::GetAnimationDirection  @ 4fc46f9f  lines 5923-5927


int __cdecl LuaBindings::GetAnimationDirection(lua_State *param_1)

{
  int iVar1;
  int unaff_EBP;
  lua_State *in_stack_fffffff8;
  
  iVar1 = RequireHandle(in_stack_fffffff8,unaff_EBP);
  ::GetAnimationDirection(iVar1);
  lua_pushnumber();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::IsPowered  @ 4fc4856b  lines 5931-5935


int __cdecl LuaBindings::IsPowered(lua_State *param_1)

{
  uint *puVar1;
  bool bVar2;
  int iVar3;
  int unaff_EBP;
  lua_State *unaff_ESI;
  
  iVar3 = RequireHandle(unaff_ESI,unaff_EBP);
  bVar2 = ::IsPowered(iVar3);
  puVar1 = *(uint **)(param_1 + 8);
  *puVar1 = (uint)bVar2;
  puVar1[1] = 0x7ff7a501;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetEmitterMask  @ 4fc4bacd  lines 5939-5943


int __cdecl LuaBindings::GetEmitterMask(lua_State *param_1)

{
  int iVar1;
  int unaff_EBP;
  lua_State *in_stack_fffffff8;
  
  iVar1 = RequireHandle(in_stack_fffffff8,unaff_EBP);
  ::GetEmitterMask(iVar1);
  lua_pushnumber();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::IsEmitterOn  @ 4fc470c3  lines 5947-5952


int __cdecl LuaBindings::IsEmitterOn(lua_State *param_1)

{
  uint *puVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int unaff_ESI;
  lua_State *unaff_EDI;
  
  iVar3 = RequireHandle(unaff_EDI,unaff_ESI);
  iVar4 = luaL_checkinteger();
  bVar2 = ::IsEmitterOn(iVar3,iVar4);
  puVar1 = *(uint **)(param_1 + 8);
  *puVar1 = (uint)bVar2;
  puVar1[1] = 0x7ff7a501;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::IFace_EnterMenuMode  @ 4fc48829  lines 5956-5959


int __cdecl LuaBindings::IFace_EnterMenuMode(lua_State *param_1)

{
  ::IFace_EnterMenuMode();
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::IFace_ExitMenuMode  @ 4fc46767  lines 5963-5966


int __cdecl LuaBindings::IFace_ExitMenuMode(lua_State *param_1)

{
  ::IFace_ExitMenuMode();
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::DoTaunt  @ 4fc478c7  lines 5973-5977


int __cdecl LuaBindings::DoTaunt(lua_State *param_1)

{
  int unaff_EBP;
  
  luaL_checkinteger();
  ::DoTaunt(unaff_EBP);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::SetTauntCPUName  @ 4fc4706f  lines 5981-5985


int __cdecl LuaBindings::SetTauntCPUName(lua_State *param_1)

{
  char *pcVar1;
  
  pcVar1 = (char *)luaL_checklstring((undefined4 *)0x0);
  sprintf_s<256>(&CPUTeamName,pcVar1);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::SetAngle  @ 4fc4b567  lines 5994-5999


int __cdecl LuaBindings::SetAngle(lua_State *param_1)

{
  int in_ECX;
  lua_State *unaff_ESI;
  undefined4 in_XMM0_Da;
  undefined4 in_XMM0_Db;
  
  RequireHandle(unaff_ESI,in_ECX);
  luaL_checknumber();
  ::SetAngle((int)(float)(double)CONCAT44(in_XMM0_Db,in_XMM0_Da),(float)unaff_ESI);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::CameraPos  @ 4fc4fc6d  lines 6003-6011


int __cdecl LuaBindings::CameraPos(lua_State *param_1)

{
  uint *puVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  float unaff_ESI;
  Vector *unaff_EDI;
  undefined4 in_XMM0_Da;
  undefined4 in_XMM0_Db;
  
  RequireHandle((lua_State *)unaff_EDI,(int)unaff_ESI);
  RequireHandle((lua_State *)unaff_EDI,(int)unaff_ESI);
  iVar3 = luaL_checkudata("Vector");
  iVar4 = luaL_checkudata("Vector");
  luaL_checknumber();
  bVar2 = ::CameraPos(iVar3,iVar4,(Vector *)(float)(double)CONCAT44(in_XMM0_Db,in_XMM0_Da),unaff_EDI
                      ,unaff_ESI);
  puVar1 = *(uint **)(param_1 + 8);
  *puVar1 = (uint)bVar2;
  puVar1[1] = 0x7ff7a501;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::CameraOf  @ 4fc4873d  lines 6015-6027


int __cdecl LuaBindings::CameraOf(lua_State *param_1)

{
  uint uVar1;
  lua_State *unaff_ESI;
  Vector *in_stack_ffffffec;
  
  RequireHandle(unaff_ESI,(int)in_stack_ffffffec);
  uVar1 = luaL_testudata();
  if (uVar1 == 0) {
    in_stack_ffffffec = (Vector *)0x0;
    luaL_checknumber();
  }
  ::CameraOf((int)unaff_ESI,in_stack_ffffffec);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::Move  @ 4fc45174  lines 6032-6047


int __cdecl LuaBindings::Move(lua_State *param_1)

{
  uint *puVar1;
  bool bVar2;
  uint uVar3;
  int unaff_ESI;
  lua_State *unaff_EDI;
  undefined4 in_XMM0_Da;
  float fVar4;
  float fVar5;
  undefined4 in_XMM0_Db;
  float fVar6;
  Vector *pVVar7;
  undefined1 uVar8;
  
  RequireHandle(unaff_EDI,unaff_ESI);
  uVar8 = (undefined1)unaff_ESI;
  luaL_checknumber();
  fVar4 = (float)(double)CONCAT44(in_XMM0_Db,in_XMM0_Da);
  fVar6 = 6.5873756e+09;
  fVar5 = fVar4;
  uVar3 = luaL_testudata();
  pVVar7 = (Vector *)0x4fc451bd;
  luaL_checknumber();
  if (uVar3 == 0) {
    bVar2 = ::Move((int)fVar4,(float)(double)CONCAT44(in_XMM0_Db,fVar5),(float)unaff_EDI,(bool)uVar8
                  );
    puVar1 = *(uint **)(param_1 + 8);
    *puVar1 = (uint)bVar2;
    puVar1[1] = 0x7ff7a501;
  }
  else {
    bVar2 = ::Move((int)fVar4,(float)(double)CONCAT44(in_XMM0_Db,fVar5),fVar6,pVVar7,
                   SUB41(unaff_EDI,0),(bool)uVar8);
    puVar1 = *(uint **)(param_1 + 8);
    *puVar1 = (uint)bVar2;
    puVar1[1] = 0x7ff7a501;
  }
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::ReplaceObject  @ 4fc4eca7  lines 6051-6070


int __cdecl LuaBindings::ReplaceObject(lua_State *param_1)

{
  Vector VVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  undefined4 *puVar13;
  int unaff_ESI;
  lua_State *unaff_EDI;
  undefined4 in_XMM0_Da;
  undefined4 in_XMM0_Db;
  undefined4 local_14;
  undefined4 local_10;
  float local_c;
  
  iVar2 = RequireHandle(unaff_EDI,unaff_ESI);
  pcVar3 = luaL_optlstring((char *)0x0,(int *)0x0);
  iVar4 = luaL_optinteger(0xffffffff);
  luaL_optnumber();
  iVar5 = luaL_optinteger(0xffffffff);
  uVar6 = lua_type();
  if ((int)uVar6 < 1) {
    iVar7 = 1;
  }
  else {
    iVar7 = lua_toboolean();
  }
  iVar8 = luaL_optinteger(0xffffffff);
  iVar9 = luaL_optinteger(0xffffffff);
  uVar6 = lua_type();
  if ((int)uVar6 < 1) {
    iVar10 = 1;
  }
  else {
    iVar10 = lua_toboolean();
  }
  iVar11 = luaL_optinteger(0xffffffff);
  iVar12 = luaL_optinteger(0);
  uVar6 = luaL_testudata();
  local_14 = 0;
  local_10 = 0;
  local_c = 0.0;
  puVar13 = (undefined4 *)luaL_testudata();
  if (puVar13 != (undefined4 *)0x0) {
    local_14 = *puVar13;
    local_10 = puVar13[1];
    local_c = (float)puVar13[2];
  }
  VVar1.y = (float)local_10;
  VVar1.x = (float)local_14;
  VVar1.z = local_c;
  BZ1Helper::ReplaceObject
            (BZ1Helper::m_BZ1Helper,iVar2,pcVar3,iVar4,
             (float)(double)CONCAT44(in_XMM0_Db,in_XMM0_Da),iVar5,iVar7 != 0,iVar8,iVar9,iVar10 != 0
             ,iVar11,iVar12,uVar6,VVar1);
  PushHandle(unaff_EDI,unaff_ESI);
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::CanCommand  @ 4fc4e865  lines 6078-6082


int __cdecl LuaBindings::CanCommand(lua_State *param_1)

{
  undefined4 *puVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  
  uVar3 = luaL_testudata();
  bVar2 = ::IsAround(uVar3);
  if (bVar2) {
    bVar2 = ::IsPlayer(uVar3);
    if (!bVar2) {
      bVar2 = IsAliveAndPilot2(uVar3);
      if (bVar2) {
        bVar2 = ::IsAround(uVar3);
        if (bVar2) {
          iVar4 = ::GetGroup(uVar3);
          if (iVar4 != -1) {
            uVar5 = 1;
            goto LAB_4fc4e8c3;
          }
        }
      }
    }
  }
  uVar5 = 0;
LAB_4fc4e8c3:
  puVar1 = *(undefined4 **)(param_1 + 8);
  *puVar1 = uVar5;
  puVar1[1] = 0x7ff7a501;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetTransform  @ 4fc4bc83  lines 6086-6090


int __cdecl LuaBindings::GetTransform(lua_State *param_1)

{
  int iVar1;
  Matrix *pMVar2;
  int unaff_ESI;
  float *pfVar3;
  lua_State *unaff_EDI;
  Matrix local_88;
  float local_48 [17];
  
  iVar1 = RequireHandle(unaff_EDI,unaff_ESI);
  ::GetPosition(iVar1,&local_88);
  pMVar2 = &local_88;
  pfVar3 = local_48;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *pfVar3 = (pMVar2->right).x;
    pMVar2 = (Matrix *)&(pMVar2->right).y;
    pfVar3 = pfVar3 + 1;
  }
  pMVar2 = NewMatrix(unaff_EDI);
  pfVar3 = local_48;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    (pMVar2->right).x = *pfVar3;
    pfVar3 = pfVar3 + 1;
    pMVar2 = (Matrix *)&(pMVar2->right).y;
  }
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetTransform2  @ 4fc5030d  lines 6094-6098


int __cdecl LuaBindings::GetTransform2(lua_State *param_1)

{
  int iVar1;
  Matrix *pMVar2;
  int unaff_ESI;
  float *pfVar3;
  lua_State *unaff_EDI;
  Matrix local_88;
  float local_48 [17];
  
  iVar1 = RequireHandle(unaff_EDI,unaff_ESI);
  ::GetPosition2(iVar1,&local_88);
  pMVar2 = &local_88;
  pfVar3 = local_48;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *pfVar3 = (pMVar2->right).x;
    pMVar2 = (Matrix *)&(pMVar2->right).y;
    pfVar3 = pfVar3 + 1;
  }
  pMVar2 = NewMatrix(unaff_EDI);
  pfVar3 = local_48;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    (pMVar2->right).x = *pfVar3;
    pfVar3 = pfVar3 + 1;
    pMVar2 = (Matrix *)&(pMVar2->right).y;
  }
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::SetTransform  @ 4fc4a9d3  lines 6104-6123


int __cdecl LuaBindings::SetTransform(lua_State *param_1)

{
  int iVar1;
  Matrix *pMVar2;
  int iVar3;
  char *pcVar4;
  Vector *unaff_ESI;
  Vector *unaff_EDI;
  Vector local_6c;
  Vector local_60;
  undefined1 local_54 [80];
  
  iVar1 = RequireHandle((lua_State *)unaff_EDI,(int)unaff_ESI);
  pMVar2 = (Matrix *)luaL_testudata();
  if (pMVar2 == (Matrix *)0x0) {
    iVar3 = lua_isstring();
    if (iVar3 == 0) {
      iVar3 = RequireHandle((lua_State *)unaff_EDI,(int)unaff_ESI);
      ::GetPosition(iVar3,(Matrix *)(local_54 + 0xc));
      ::SetPosition(iVar1,(Matrix *)(local_54 + 0xc));
      return 0;
    }
    pcVar4 = (char *)lua_tolstring((undefined4 *)0x0);
    ::GetPosition(pcVar4,0,&local_6c);
    ::GetPosition(pcVar4,1,&local_60);
    local_54._0_4_ = local_60.x - local_6c.x;
    local_54._4_4_ = local_60.y - local_6c.y;
    local_54._8_4_ = local_60.z - local_6c.z;
    Build_Directinal_Matrix((Matrix *)local_54,unaff_EDI,unaff_ESI);
    pMVar2 = (Matrix *)(local_54 + 0xc);
  }
  ::SetPosition(iVar1,pMVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::GetRecyclerHandle  @ 4fc4be82  lines 6128-6132


int __cdecl LuaBindings::GetRecyclerHandle(lua_State *param_1)

{
  int iVar1;
  lua_State *unaff_EBP;
  int unaff_retaddr;
  
  iVar1 = ::GetLocalPlayerTeamNumber();
  iVar1 = luaL_optinteger(iVar1);
  ::GetObjectByTeamSlot(iVar1,1);
  PushHandle(unaff_EBP,unaff_retaddr);
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetFactoryHandle  @ 4fc4d208  lines 6136-6140


int __cdecl LuaBindings::GetFactoryHandle(lua_State *param_1)

{
  int iVar1;
  lua_State *unaff_EBP;
  int unaff_retaddr;
  
  iVar1 = ::GetLocalPlayerTeamNumber();
  iVar1 = luaL_optinteger(iVar1);
  ::GetObjectByTeamSlot(iVar1,2);
  PushHandle(unaff_EBP,unaff_retaddr);
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetArmoryHandle  @ 4fc45d0f  lines 6144-6148


int __cdecl LuaBindings::GetArmoryHandle(lua_State *param_1)

{
  int iVar1;
  lua_State *unaff_EBP;
  int unaff_retaddr;
  
  iVar1 = ::GetLocalPlayerTeamNumber();
  iVar1 = luaL_optinteger(iVar1);
  ::GetObjectByTeamSlot(iVar1,3);
  PushHandle(unaff_EBP,unaff_retaddr);
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetTimeStep  @ 4fc45ce7  lines 6152-6155


int __cdecl LuaBindings::GetTimeStep(lua_State *param_1)

{
  ::TurnsToSeconds(1);
  lua_pushnumber();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::IsInsideArea  @ 4fc4b256  lines 6162-6180


int __cdecl LuaBindings::IsInsideArea(lua_State *param_1)

{
  uint *puVar1;
  Vector VVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  Vector *pVVar6;
  uint uVar7;
  int iVar8;
  float unaff_EDI;
  undefined4 *puVar9;
  undefined4 local_50 [12];
  Vector local_20;
  Vector local_10;
  
  luaL_checklstring((undefined4 *)0x0);
  puVar5 = (undefined4 *)luaL_testudata();
  if (puVar5 == (undefined4 *)0x0) {
    pVVar6 = (Vector *)luaL_testudata();
    if (pVVar6 == (Vector *)0x0) {
      uVar7 = luaL_testudata();
      ::GetPosition(uVar7,&local_10);
      pVVar6 = &local_10;
    }
  }
  else {
    puVar9 = local_50;
    for (iVar8 = 0x10; iVar8 != 0; iVar8 = iVar8 + -1) {
      *puVar9 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar9 = puVar9 + 1;
    }
    pVVar6 = &local_20;
  }
  uVar3 = pVVar6->y;
  uVar4 = pVVar6->z;
  VVar2.y = (float)uVar4;
  VVar2.x = (float)uVar3;
  VVar2.z = unaff_EDI;
  iVar8 = ::GetWindingNumber((char *)pVVar6->x,VVar2);
  puVar1 = *(uint **)(param_1 + 8);
  puVar1[1] = 0x7ff7a501;
  *puVar1 = (uint)(iVar8 != 0);
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetWindingNumber  @ 4fc478e0  lines 6187-6205


int __cdecl LuaBindings::GetWindingNumber(lua_State *param_1)

{
  Vector VVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  Vector *pVVar5;
  uint uVar6;
  int iVar7;
  float unaff_EDI;
  undefined4 *puVar8;
  Vector local_54;
  undefined4 local_48 [12];
  Vector local_18;
  
  luaL_checklstring((undefined4 *)0x0);
  puVar4 = (undefined4 *)luaL_testudata();
  if (puVar4 == (undefined4 *)0x0) {
    pVVar5 = (Vector *)luaL_testudata();
    if (pVVar5 == (Vector *)0x0) {
      uVar6 = luaL_testudata();
      ::GetPosition(uVar6,&local_54);
      pVVar5 = &local_54;
    }
  }
  else {
    puVar8 = local_48;
    for (iVar7 = 0x10; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar8 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar8 = puVar8 + 1;
    }
    pVVar5 = &local_18;
  }
  uVar2 = pVVar5->y;
  uVar3 = pVVar5->z;
  VVar1.y = (float)uVar3;
  VVar1.x = (float)uVar2;
  VVar1.z = unaff_EDI;
  ::GetWindingNumber((char *)pVVar5->x,VVar1);
  lua_pushnumber();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetTPS  @ 4fc45954  lines 6213-6216


int __cdecl LuaBindings::GetTPS(lua_State *param_1)

{
  double *pdVar1;
  int iVar2;
  
  iVar2 = ::SecondsToTurns(1.0);
  pdVar1 = *(double **)(param_1 + 8);
  *pdVar1 = (double)iVar2;
  *(double **)(param_1 + 8) = pdVar1 + 1;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::DoesPathExist  @ 4fc4a984  lines 6220-6229


int __cdecl LuaBindings::DoesPathExist(lua_State *param_1)

{
  int iVar1;
  char *unaff_EDI;
  
  luaL_checklstring((undefined4 *)0x0);
  iVar1 = ::DoesPathExist(unaff_EDI);
  if (iVar1 < 1) {
    *(undefined4 *)(*(int *)(param_1 + 8) + 4) = 0x7ff7a500;
  }
  else {
    iVar1 = ::DoesPathExist(unaff_EDI);
    **(double **)(param_1 + 8) = (double)iVar1;
  }
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::AddToDispatch  @ 4fc4e602  lines 6239-6251


int __cdecl LuaBindings::AddToDispatch(lua_State *param_1)

{
  uint *puVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int unaff_ESI;
  lua_State *unaff_EDI;
  int iVar10;
  float fVar11;
  float fVar12;
  double in_XMM0_Qa;
  
  iVar3 = RequireHandle(unaff_EDI,unaff_ESI);
  uVar4 = lua_type();
  if ((int)uVar4 < 1) {
    in_XMM0_Qa = __real_402e000000000000;
  }
  else {
    luaL_checknumber();
  }
  fVar11 = (float)in_XMM0_Qa;
  fVar12 = fVar11;
  uVar4 = lua_type();
  iVar10 = 0;
  if ((int)uVar4 < 1) {
    iVar5 = 0;
  }
  else {
    iVar5 = lua_toboolean();
  }
  uVar4 = lua_type();
  if ((int)uVar4 < 1) {
    iVar9 = 0;
    fVar11 = fVar12;
  }
  else {
    iVar9 = luaL_checkinteger();
  }
  uVar4 = lua_type();
  if ((int)uVar4 < 1) {
    iVar6 = 1;
  }
  else {
    iVar6 = lua_toboolean();
  }
  uVar4 = lua_type();
  if ((int)uVar4 < 1) {
    iVar7 = 0;
  }
  else {
    iVar7 = lua_toboolean();
  }
  uVar4 = lua_type();
  if ((int)uVar4 < 1) {
    iVar8 = 0;
  }
  else {
    iVar8 = lua_toboolean();
  }
  uVar4 = lua_type();
  if (0 < (int)uVar4) {
    iVar10 = lua_toboolean();
  }
  bVar2 = BZ1Helper::AddToDispatch
                    (BZ1Helper::m_BZ1Helper,iVar3,fVar11,iVar5 != 0,iVar9,iVar6 != 0,iVar7 != 0,
                     iVar8 != 0,iVar10 != 0);
  puVar1 = *(uint **)(param_1 + 8);
  *puVar1 = (uint)bVar2;
  puVar1[1] = 0x7ff7a501;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::ReplaceWeapons  @ 4fc4653a  lines 6255-6310


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl LuaBindings::ReplaceWeapons(lua_State *param_1)

{
  int iVar1;
  uint *puVar2;
  bool bVar3;
  uint uVar4;
  char *_Src;
  char (*pacVar5) [64];
  char *unaff_ESI;
  lua_State *unaff_EDI;
  int iVar6;
  float *pfVar7;
  float in_XMM0_Da;
  undefined4 in_XMM0_Db;
  char *local_160;
  float local_15c [5];
  char local_148 [320];
  undefined4 local_8;
  
  local_8 = __security_cookie ^ (uint)(local_148 + 0x144);
  RequireHandle(unaff_EDI,(int)unaff_ESI);
  memset(local_148,0,0x140);
  uVar4 = lua_type();
  if (uVar4 == 5) {
    uVar4 = lua_rawlen();
    iVar6 = 0;
    local_160 = local_148;
    do {
      if ((int)uVar4 <= iVar6) break;
      iVar6 = iVar6 + 1;
      lua_rawgeti();
      _Src = (char *)lua_tolstring((undefined4 *)0x0);
      if (_Src != (char *)0x0) {
        strcpy_s(local_160,0x40,_Src);
      }
      lua_settop();
      local_160 = local_160 + 0x40;
    } while (iVar6 < 5);
  }
  local_15c[0] = 0.0;
  local_15c[1] = 0.0;
  local_15c[2] = 0.0;
  local_15c[3] = 0.0;
  local_15c[4] = 0.0;
  uVar4 = lua_type();
  if (uVar4 == 5) {
    uVar4 = lua_rawlen();
    iVar6 = 0;
    do {
      if ((int)uVar4 <= iVar6) break;
      iVar1 = iVar6 + 1;
      lua_rawgeti();
      lua_tonumberx((undefined4 *)0x0);
      in_XMM0_Da = (float)(double)CONCAT44(in_XMM0_Db,in_XMM0_Da);
      local_15c[iVar6] = in_XMM0_Da;
      lua_settop();
      iVar6 = iVar1;
    } while (iVar1 < 5);
    pfVar7 = local_15c;
  }
  else {
    uVar4 = lua_type();
    pfVar7 = (float *)((uint)local_15c & -(uint)(uVar4 != 0));
  }
  pacVar5 = (char (*) [64])0x0;
  uVar4 = lua_type();
  if (uVar4 != 0) {
    pacVar5 = (char (*) [64])lua_tolstring((undefined4 *)0x0);
  }
  bVar3 = ::ReplaceWeapons((int)pfVar7,pacVar5,(float *)unaff_EDI,unaff_ESI);
  puVar2 = *(uint **)(param_1 + 8);
  puVar2[1] = 0x7ff7a501;
  *puVar2 = (uint)bVar3;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::SetPortalChannel  @ 4fc495cb  lines 6314-6319


int __cdecl LuaBindings::SetPortalChannel(lua_State *param_1)

{
  PortalHelper *pPVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int unaff_ESI;
  lua_State *unaff_EDI;
  
  iVar3 = RequireHandle(unaff_EDI,unaff_ESI);
  iVar4 = luaL_checkinteger();
  pPVar1 = BZ1Helper::m_BZ1Helper->m_PortalHelper;
  bVar2 = ::IsAround(iVar3);
  if (bVar2) {
    for (piVar5 = *(int **)&pPVar1->PortalList; piVar5 != *(int **)&(pPVar1->PortalList).field_0x4;
        piVar5 = piVar5 + 0xe4) {
      if (*piVar5 == iVar3) {
        piVar5[9] = iVar4;
        return 0;
      }
    }
  }
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::GetPortalChannel  @ 4fc450bb  lines 6323-6327


int __cdecl LuaBindings::GetPortalChannel(lua_State *param_1)

{
  PortalHelper *pPVar1;
  bool bVar2;
  int iVar3;
  int *piVar4;
  int unaff_ESI;
  lua_State *unaff_EDI;
  
  iVar3 = RequireHandle(unaff_EDI,unaff_ESI);
  pPVar1 = BZ1Helper::m_BZ1Helper->m_PortalHelper;
  bVar2 = ::IsAround(iVar3);
  if (bVar2) {
    for (piVar4 = *(int **)&pPVar1->PortalList;
        (piVar4 != *(int **)&(pPVar1->PortalList).field_0x4 && (*piVar4 != iVar3));
        piVar4 = piVar4 + 0xe4) {
    }
  }
  lua_pushnumber();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::SetPortalEffectStart  @ 4fc4e8da  lines 6331-6337


int __cdecl LuaBindings::SetPortalEffectStart(lua_State *param_1)

{
  PortalHelper *this;
  bool bVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int unaff_ESI;
  lua_State *unaff_EDI;
  int iVar5;
  int local_8;
  
  iVar2 = RequireHandle(unaff_EDI,unaff_ESI);
  uVar3 = lua_type();
  iVar5 = 0;
  if ((int)uVar3 < 1) {
    local_8 = 0;
  }
  else {
    local_8 = luaL_checkinteger();
  }
  uVar3 = lua_type();
  if (0 < (int)uVar3) {
    iVar5 = luaL_checkinteger();
  }
  this = BZ1Helper::m_BZ1Helper->m_PortalHelper;
  bVar1 = ::IsAround(iVar2);
  if ((bVar1) &&
     (piVar4 = *(int **)&this->PortalList, piVar4 != *(int **)&(this->PortalList).field_0x4)) {
    do {
      if (*piVar4 == iVar2) {
        PortalHelper::SetPortalEffectStart_Internal
                  (this,((int)piVar4 - *(int *)&this->PortalList) / 0x390,local_8,iVar5,true);
        return 0;
      }
      piVar4 = piVar4 + 0xe4;
    } while (piVar4 != *(int **)&(this->PortalList).field_0x4);
  }
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::SetPortalEffectOn  @ 4fc46bb5  lines 6341-6347


int __cdecl LuaBindings::SetPortalEffectOn(lua_State *param_1)

{
  PortalHelper *this;
  bool bVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int unaff_ESI;
  lua_State *unaff_EDI;
  int iVar5;
  int local_8;
  
  iVar2 = RequireHandle(unaff_EDI,unaff_ESI);
  uVar3 = lua_type();
  iVar5 = 0;
  if ((int)uVar3 < 1) {
    local_8 = 0;
  }
  else {
    local_8 = luaL_checkinteger();
  }
  uVar3 = lua_type();
  if (0 < (int)uVar3) {
    iVar5 = luaL_checkinteger();
  }
  this = BZ1Helper::m_BZ1Helper->m_PortalHelper;
  bVar1 = ::IsAround(iVar2);
  if ((bVar1) &&
     (piVar4 = *(int **)&this->PortalList, piVar4 != *(int **)&(this->PortalList).field_0x4)) {
    do {
      if (*piVar4 == iVar2) {
        PortalHelper::SetPortalEffectOn_Internal
                  (this,((int)piVar4 - *(int *)&this->PortalList) / 0x390,local_8,iVar5,true);
        return 0;
      }
      piVar4 = piVar4 + 0xe4;
    } while (piVar4 != *(int **)&(this->PortalList).field_0x4);
  }
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::SetPortalEffectEnd  @ 4fc4583b  lines 6351-6357


int __cdecl LuaBindings::SetPortalEffectEnd(lua_State *param_1)

{
  int iVar1;
  uint uVar2;
  undefined1 extraout_CL;
  undefined1 extraout_CL_00;
  undefined1 uVar3;
  int iVar4;
  int unaff_ESI;
  lua_State *unaff_EDI;
  int iVar5;
  
  iVar1 = RequireHandle(unaff_EDI,unaff_ESI);
  uVar2 = lua_type();
  iVar5 = 0;
  if ((int)uVar2 < 1) {
    iVar4 = 0;
  }
  else {
    iVar4 = luaL_checkinteger();
  }
  uVar2 = lua_type();
  uVar3 = extraout_CL;
  if (0 < (int)uVar2) {
    iVar5 = luaL_checkinteger();
    uVar3 = extraout_CL_00;
  }
  PortalHelper::SetPortalEffectEnd
            (BZ1Helper::m_BZ1Helper->m_PortalHelper,iVar1,iVar4,iVar5,(bool)uVar3);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::IsPortalEffectActive  @ 4fc46700  lines 6361-6365


int __cdecl LuaBindings::IsPortalEffectActive(lua_State *param_1)

{
  PortalHelper *pPVar1;
  uint *puVar2;
  bool bVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  int unaff_ESI;
  lua_State *unaff_EDI;
  
  iVar4 = RequireHandle(unaff_EDI,unaff_ESI);
  pPVar1 = BZ1Helper::m_BZ1Helper->m_PortalHelper;
  bVar3 = ::IsAround(iVar4);
  if (bVar3) {
    for (piVar5 = *(int **)&pPVar1->PortalList; piVar5 != *(int **)&(pPVar1->PortalList).field_0x4;
        piVar5 = piVar5 + 0xe4) {
      if (*piVar5 == iVar4) {
        bVar3 = ::IsEmitterOn(*piVar5,piVar5[2]);
        uVar6 = (uint)bVar3;
        goto LAB_4fc4673d;
      }
    }
  }
  uVar6 = 0;
LAB_4fc4673d:
  puVar2 = *(uint **)(param_1 + 8);
  *puVar2 = uVar6;
  puVar2[1] = 0x7ff7a501;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::SwapPortalIndex  @ 4fc4bfc7  lines 6369-6374


int __cdecl LuaBindings::SwapPortalIndex(lua_State *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int unaff_ESI;
  lua_State *unaff_EDI;
  
  iVar2 = RequireHandle(unaff_EDI,unaff_ESI);
  iVar3 = RequireHandle(unaff_EDI,unaff_ESI);
  piVar5 = *(int **)&BZ1Helper::m_BZ1Helper->m_PortalHelper->PortalList;
  piVar1 = *(int **)&(BZ1Helper::m_BZ1Helper->m_PortalHelper->PortalList).field_0x4;
  piVar4 = piVar5;
  while( true ) {
    if (piVar4 == piVar1) {
      return 0;
    }
    if (iVar2 == *piVar4) break;
    piVar4 = piVar4 + 0xe4;
  }
  if (piVar4[7] != 1) {
    return 0;
  }
  if (((int)piVar4 - (int)piVar5) / 0x390 < 0) {
    return 0;
  }
  while( true ) {
    if (piVar5 == piVar1) {
      return 0;
    }
    if (iVar3 == *piVar5) break;
    piVar5 = piVar5 + 0xe4;
  }
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::ShufflePortalUp  @ 4fc4b49a  lines 6378-6382


int __cdecl LuaBindings::ShufflePortalUp(lua_State *param_1)

{
  PortalHelper *this;
  int iVar1;
  int *piVar2;
  int unaff_EBP;
  lua_State *unaff_ESI;
  
  iVar1 = RequireHandle(unaff_ESI,unaff_EBP);
  this = BZ1Helper::m_BZ1Helper->m_PortalHelper;
  piVar2 = *(int **)&this->PortalList;
  if (piVar2 != *(int **)&(this->PortalList).field_0x4) {
    do {
      if (iVar1 == *piVar2) {
        if (piVar2[7] != 1) {
          return 0;
        }
        iVar1 = ((int)piVar2 - *(int *)&this->PortalList) / 0x390;
        if (iVar1 < 0) {
          return 0;
        }
        PortalHelper::ShufflePortalUpInternal(this,iVar1);
        PortalHelper::ResetPortalDestinations
                  (this,*(int *)(iVar1 * 0x390 + 0x24 + *(int *)&this->PortalList));
        return 0;
      }
      piVar2 = piVar2 + 0xe4;
    } while (piVar2 != *(int **)&(this->PortalList).field_0x4);
  }
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::ShufflePortalDown  @ 4fc4ae08  lines 6386-6390


int __cdecl LuaBindings::ShufflePortalDown(lua_State *param_1)

{
  PortalHelper *this;
  int iVar1;
  int *piVar2;
  int unaff_EBP;
  lua_State *unaff_ESI;
  
  iVar1 = RequireHandle(unaff_ESI,unaff_EBP);
  this = BZ1Helper::m_BZ1Helper->m_PortalHelper;
  piVar2 = *(int **)&this->PortalList;
  if (piVar2 != *(int **)&(this->PortalList).field_0x4) {
    do {
      if (iVar1 == *piVar2) {
        if (piVar2[7] != 1) {
          return 0;
        }
        iVar1 = ((int)piVar2 - *(int *)&this->PortalList) / 0x390;
        if (iVar1 < 0) {
          return 0;
        }
        PortalHelper::ShufflePortalDownInternal(this,iVar1);
        PortalHelper::ResetPortalDestinations
                  (this,*(int *)(iVar1 * 0x390 + 0x24 + *(int *)&this->PortalList));
        return 0;
      }
      piVar2 = piVar2 + 0xe4;
    } while (piVar2 != *(int **)&(this->PortalList).field_0x4);
  }
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::GetPortalDest  @ 4fc45d3f  lines 6394-6398


int __cdecl LuaBindings::GetPortalDest(lua_State *param_1)

{
  PortalHelper *pPVar1;
  bool bVar2;
  int iVar3;
  int unaff_EBX;
  int *piVar4;
  lua_State *unaff_EDI;
  
  iVar3 = RequireHandle(unaff_EDI,unaff_EBX);
  pPVar1 = BZ1Helper::m_BZ1Helper->m_PortalHelper;
  bVar2 = ::IsAround(iVar3);
  if (bVar2) {
    for (piVar4 = *(int **)&pPVar1->PortalList; piVar4 != *(int **)&(pPVar1->PortalList).field_0x4;
        piVar4 = piVar4 + 0xe4) {
      if (*piVar4 == iVar3) {
        ::IsAround(piVar4[1]);
        break;
      }
    }
  }
  PushHandle(unaff_EDI,unaff_EBX);
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::SetPortalDest  @ 4fc46b28  lines 6402-6407


int __cdecl LuaBindings::SetPortalDest(lua_State *param_1)

{
  uint *puVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int unaff_ESI;
  lua_State *unaff_EDI;
  
  iVar3 = RequireHandle(unaff_EDI,unaff_ESI);
  iVar4 = RequireHandle(unaff_EDI,unaff_ESI);
  bVar2 = PortalHelper::SetPortalDest(BZ1Helper::m_BZ1Helper->m_PortalHelper,iVar3,iVar4);
  puVar1 = *(uint **)(param_1 + 8);
  *puVar1 = (uint)bVar2;
  puVar1[1] = 0x7ff7a501;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::ClearPortalDest  @ 4fc49539  lines 6411-6416


int __cdecl LuaBindings::ClearPortalDest(lua_State *param_1)

{
  PortalHelper *this;
  int *piVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  int unaff_ESI;
  lua_State *unaff_EDI;
  
  iVar3 = RequireHandle(unaff_EDI,unaff_ESI);
  uVar4 = lua_type();
  if ((int)uVar4 < 1) {
    iVar5 = 0;
  }
  else {
    iVar5 = lua_toboolean();
  }
  this = BZ1Helper::m_BZ1Helper->m_PortalHelper;
  bVar2 = ::IsAround(iVar3);
  if ((bVar2) &&
     (piVar1 = *(int **)&this->PortalList, piVar6 = piVar1,
     piVar1 != *(int **)&(this->PortalList).field_0x4)) {
    do {
      if (*piVar6 == iVar3) {
        iVar3 = ((int)piVar6 - (int)piVar1) / 0x390;
        if (iVar3 == -1) {
          return 0;
        }
        PortalHelper::ResetPortalDestinations(this,piVar1[iVar3 * 0xe4 + 9]);
        *(bool *)(*(int *)&this->PortalList + 0x1a + iVar3 * 0x390) = iVar5 != 0;
        return 0;
      }
      piVar6 = piVar6 + 0xe4;
    } while (piVar6 != *(int **)&(this->PortalList).field_0x4);
  }
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::LoadValue  @ 4fc48dc0  lines 6426-6547


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

bool __cdecl LuaBindings::LoadValue(lua_State *param_1,bool param_2)

{
  uint *puVar1;
  bool bVar2;
  Quaternion *pQVar3;
  Vector *pVVar4;
  Matrix *pMVar5;
  int in_ECX;
  int iVar6;
  char in_DL;
  undefined1 *puVar7;
  int unaff_ESI;
  float *pfVar8;
  lua_State *unaff_EDI;
  undefined4 uStackY_a0;
  float local_84 [17];
  float local_40;
  float local_3c [6];
  undefined8 local_24;
  undefined1 *local_1c;
  bool local_e;
  char local_d;
  int local_c;
  float local_8;
  
  local_8 = (float)(__security_cookie ^ (uint)(local_84 + 0x20));
  local_d = '0';
  uStackY_a0 = 0x4fc48def;
  bVar2 = Read(&local_d,1);
  local_d = local_d + -0x30;
  if (local_d != '\x01') {
    if (local_d == '\x02') {
      local_c = 0;
      if (bVar2) {
        uStackY_a0 = 0x4fc49089;
        bVar2 = Read(&local_c,1);
        if (bVar2) {
          bVar2 = true;
          goto LAB_4fc49095;
        }
      }
      bVar2 = false;
LAB_4fc49095:
      uStackY_a0 = 0x4fc490a1;
      ConvertHandles(&local_c,1);
      if (in_DL == '\0') {
        return bVar2;
      }
      PushHandle(unaff_EDI,unaff_ESI);
      return bVar2;
    }
    if (local_d == '\x03') {
      local_24 = 0;
      if (bVar2) {
        uStackY_a0 = 0x4fc49053;
        bVar2 = Read(&local_24,8);
        if (bVar2) {
          bVar2 = true;
          goto LAB_4fc4905f;
        }
      }
      bVar2 = false;
LAB_4fc4905f:
      if (in_DL == '\0') {
        return bVar2;
      }
      lua_pushnumber();
      return bVar2;
    }
    if (local_d != '\x04') {
      if (local_d == '\x05') {
        local_c = 0;
        if (bVar2) {
          uStackY_a0 = 0x4fc48f74;
          bVar2 = Read(&local_c,1);
          if (bVar2) {
            bVar2 = true;
            goto LAB_4fc48f80;
          }
        }
        bVar2 = false;
LAB_4fc48f80:
        lua_createtable(0);
        iVar6 = 0;
        if (local_c < 1) {
          return bVar2;
        }
        do {
          if (((bVar2) && (bVar2 = LoadValue(unaff_EDI,SUB41(unaff_ESI,0)), bVar2)) &&
             (bVar2 = LoadValue(unaff_EDI,SUB41(unaff_ESI,0)), bVar2)) {
            bVar2 = true;
          }
          else {
            bVar2 = false;
          }
          if (in_DL != '\0') {
            uStackY_a0 = 0x4fc48fd4;
            luaV_settable((double *)(*(int *)(in_ECX + 8) + -0x10),
                          (int *)(*(int *)(in_ECX + 8) + -8));
            *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + -0x10;
          }
          iVar6 = iVar6 + 1;
        } while (iVar6 < local_c);
        return bVar2;
      }
      if (local_d != '\a') {
        if (in_DL == '\0') {
          return bVar2;
        }
        *(undefined4 *)(*(int *)(in_ECX + 8) + 4) = 0x7ff7a500;
        goto LAB_4fc490eb;
      }
      local_c = 0;
      if (bVar2) {
        uStackY_a0 = 0x4fc48e5c;
        bVar2 = Read(&local_c,4);
        if (!bVar2) goto LAB_4fc48e69;
        bVar2 = true;
      }
      else {
LAB_4fc48e69:
        bVar2 = false;
      }
      if (local_c == 0x15c2f8ec) {
        pMVar5 = &::Identity_Matrix;
        pfVar8 = local_84;
        for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
          *pfVar8 = (pMVar5->right).x;
          pMVar5 = (Matrix *)&(pMVar5->right).y;
          pfVar8 = pfVar8 + 1;
        }
        if (bVar2) {
          uStackY_a0 = 0x4fc48f35;
          bVar2 = Read(local_84,0x40);
          if (bVar2) {
            bVar2 = true;
            goto LAB_4fc48f41;
          }
        }
        bVar2 = false;
LAB_4fc48f41:
        if (in_DL == '\0') {
          return bVar2;
        }
        pMVar5 = NewMatrix(unaff_EDI);
        pfVar8 = local_84;
        for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
          (pMVar5->right).x = *pfVar8;
          pfVar8 = pfVar8 + 1;
          pMVar5 = (Matrix *)&(pMVar5->right).y;
        }
        return bVar2;
      }
      if (local_c == -0x707617fe) {
        local_24 = 0;
        local_1c = (undefined1 *)0x0;
        if (bVar2) {
          uStackY_a0 = 0x4fc48ef0;
          bVar2 = Read(&local_24,0xc);
          if (!bVar2) goto LAB_4fc48efa;
          bVar2 = true;
        }
        else {
LAB_4fc48efa:
          bVar2 = false;
        }
        if (in_DL == '\0') {
          return bVar2;
        }
        pVVar4 = NewVector(unaff_EDI);
        pfVar8 = (float *)&local_24;
        goto LAB_4fc48f10;
      }
      if (local_c != -0xc19b973) {
        return bVar2;
      }
      local_3c[3] = 0.0;
      local_3c[4] = 0.0;
      local_3c[5] = 0.0;
      local_40 = 1.0;
      local_3c[0] = 0.0;
      local_3c[1] = 0.0;
      local_3c[2] = 0.0;
      if (bVar2) {
        uStackY_a0 = 0x4fc48eb4;
        bVar2 = Read(&local_40,0x10);
        if (!bVar2) goto LAB_4fc48ebe;
        bVar2 = true;
      }
      else {
LAB_4fc48ebe:
        bVar2 = false;
      }
      if (in_DL == '\0') {
        return bVar2;
      }
      pQVar3 = NewQuaternion(unaff_EDI);
      pVVar4 = &pQVar3->v;
      pfVar8 = local_3c;
      pQVar3->s = local_40;
LAB_4fc48f10:
      pVVar4->x = *pfVar8;
      pVVar4->y = pfVar8[1];
      pVVar4->z = pfVar8[2];
      return bVar2;
    }
    local_c = 0;
    if (bVar2) {
      uStackY_a0 = 0x4fc48ff5;
      bVar2 = Read(&local_c,4);
      if (!bVar2) goto LAB_4fc48fff;
      bVar2 = true;
    }
    else {
LAB_4fc48fff:
      bVar2 = false;
    }
    iVar6 = -local_c;
    local_1c = (undefined1 *)((int)local_84 + iVar6 + -0x10);
    if (bVar2) {
      *(int *)((int)local_84 + iVar6 + -0x14) = local_c;
      *(int *)((int)local_84 + iVar6 + -0x18) = (int)local_84 + iVar6 + -0x10;
      *(undefined4 *)((int)local_84 + iVar6 + -0x1c) = 0x4fc49018;
      bVar2 = Read(*(void **)((int)local_84 + iVar6 + -0x18),*(int *)((int)local_84 + iVar6 + -0x14)
                  );
      puVar7 = (undefined1 *)((int)local_84 + iVar6 + -0x10);
      if (bVar2) {
        bVar2 = true;
        goto LAB_4fc49024;
      }
    }
    puVar7 = (undefined1 *)((int)local_84 + iVar6 + -0x10);
    bVar2 = false;
LAB_4fc49024:
    if (in_DL == '\0') {
      return bVar2;
    }
    *(int *)(puVar7 + -4) = local_c;
    *(undefined4 *)(puVar7 + -8) = 0x4fc49039;
    lua_pushlstring(*(uint *)(puVar7 + -4));
    return bVar2;
  }
  local_e = false;
  if (bVar2) {
    uStackY_a0 = 0x4fc490c7;
    bVar2 = Read(&local_e,1);
    if (!bVar2) goto LAB_4fc490d1;
    bVar2 = true;
  }
  else {
LAB_4fc490d1:
    bVar2 = false;
  }
  if (in_DL == '\0') {
    return bVar2;
  }
  puVar1 = *(uint **)(in_ECX + 8);
  *puVar1 = (uint)(local_e != false);
  puVar1[1] = 0x7ff7a501;
LAB_4fc490eb:
  *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + 8;
  return bVar2;
}


// ---------------------------------------------------------------------
// LuaBindings::SaveValue  @ 4fc4cbee  lines 6551-6656


bool __cdecl LuaBindings::SaveValue(lua_State *param_1,int param_2)

{
  bool bVar1;
  bool bVar2;
  uint uVar3;
  undefined3 extraout_var;
  int iVar4;
  ulonglong *puVar5;
  void *pvVar6;
  int in_ECX;
  uint unaff_ESI;
  lua_State *unaff_EDI;
  ulonglong in_XMM0_Qa;
  char local_12;
  bool local_11;
  ulonglong local_10;
  
  uVar3 = lua_type();
  local_12 = (char)uVar3 + '0';
  bVar1 = Write(&local_12,1);
  local_12 = local_12 + -0x30;
  if (local_12 == '\x01') {
    iVar4 = lua_toboolean();
    local_11 = iVar4 != 0;
    if (!bVar1) {
      return false;
    }
    bVar1 = Write(&local_11,1);
  }
  else if (local_12 == '\x02') {
    uVar3 = luaL_testudata();
    local_10 = CONCAT44(local_10._4_4_,uVar3);
    if (!bVar1) {
      return false;
    }
    bVar1 = Write((int *)&local_10,1);
  }
  else {
    if (local_12 == '\x03') {
      lua_tonumberx((undefined4 *)0x0);
      if (!bVar1) {
        return false;
      }
      iVar4 = 8;
      puVar5 = &local_10;
      local_10 = in_XMM0_Qa;
    }
    else {
      if (local_12 == '\x04') {
        pvVar6 = (void *)lua_tolstring((undefined4 *)&local_10);
        if (!bVar1) {
          return false;
        }
        bVar1 = Write(&local_10,4);
        if (!bVar1) {
          return false;
        }
        bVar1 = Write(pvVar6,(int)local_10);
        goto LAB_4fc4ce9b;
      }
      if (local_12 == '\x05') {
        local_10 = local_10 & 0xffffffff00000000;
        *(undefined4 *)(*(int *)(in_ECX + 8) + 4) = 0x7ff7a500;
        *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + 8;
        local_12 = '\x05';
        while (iVar4 = lua_next(), iVar4 != 0) {
          local_10 = CONCAT44(local_10._4_4_,(int)local_10 + 1);
          lua_settop();
        }
        if ((bVar1) && (bVar1 = Write((int *)&local_10,1), bVar1)) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
        *(undefined4 *)(*(int *)(in_ECX + 8) + 4) = 0x7ff7a500;
        *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + 8;
        while (iVar4 = lua_next(), iVar4 != 0) {
          if (((bVar1 == false) || (bVar1 = SaveValue(unaff_EDI,unaff_ESI), !bVar1)) ||
             (bVar1 = SaveValue(unaff_EDI,unaff_ESI), !bVar1)) {
            bVar1 = false;
          }
          else {
            bVar1 = true;
          }
          lua_settop();
        }
        return bVar1;
      }
      if (local_12 != '\a') {
        return bVar1;
      }
      bVar2 = lua_getmetatable();
      if (CONCAT31(extraout_var,bVar2) == 0) {
        return bVar1;
      }
      lua_getfield();
      iVar4 = luaL_checklstring((undefined4 *)0x0);
      uVar3 = 0;
      if (iVar4 != 0) {
        uVar3 = Hash((char *)unaff_EDI,unaff_ESI);
      }
      local_10 = CONCAT44(local_10._4_4_,uVar3);
      lua_settop();
      if ((bVar1) && (bVar1 = Write(&local_10,4), bVar1)) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if ((int)local_10 == 0x15c2f8ec) {
        if (bVar1 == false) {
          return false;
        }
        puVar5 = (ulonglong *)luaL_testudata();
        iVar4 = 0x40;
      }
      else if ((int)local_10 == -0x707617fe) {
        if (bVar1 == false) {
          return false;
        }
        puVar5 = (ulonglong *)luaL_testudata();
        iVar4 = 0xc;
      }
      else {
        if ((int)local_10 != -0xc19b973) {
          return bVar1;
        }
        if (bVar1 == false) {
          return false;
        }
        puVar5 = (ulonglong *)luaL_testudata();
        iVar4 = 0x10;
      }
    }
    bVar1 = Write(puVar5,iVar4);
  }
LAB_4fc4ce9b:
  if (bVar1 == false) {
    return false;
  }
  return true;
}

