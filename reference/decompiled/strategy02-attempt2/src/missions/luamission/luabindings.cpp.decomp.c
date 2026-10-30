// Reconstructed by Ghidra from Strategy02.dll + Strategy02.pdb
// Original source file: /e:/github/vsr_dll_source/missions/luamission/luabindings.cpp
// Functions are ordered by original source line. This is decompiler
// output, not the author's source: names/types come from the PDB,
// local variable names and control flow are reconstructed.

// ---------------------------------------------------------------------
// LuaPrint  @ 4fc54bc7  lines 8-33

/* WARNING: Function: _chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl LuaPrint(lua_State *L)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 extraout_ECX;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint len2;
  int local_1014;
  char buffer [4100];
  uint local_c;
  undefined4 uStack_8;
  
  uStack_8 = 0x4fc54bd4;
  local_c = __security_cookie ^ (uint)&stack0xfffffffc;
  uVar5 = 0;
  iVar3 = (*(int *)(L + 8) - **(int **)(L + 0x10)) + -8 >> 3;
  lua_getglobal();
  local_1014 = 1;
  if (0 < iVar3) {
    do {
      puVar1 = *(undefined4 **)(L + 8);
      *puVar1 = puVar1[-2];
      puVar1[1] = puVar1[-1];
      *(int *)(L + 8) = *(int *)(L + 8) + 8;
      lua_pushvalue();
      lua_callk(1,extraout_ECX,0);
      pvVar2 = (void *)lua_tolstring(&len2);
      if (pvVar2 == (void *)0x0) {
                    /* WARNING: Subroutine does not return */
        luaL_error();
      }
      if ((1 < local_1014) && (uVar5 < 0xfff)) {
        buffer[uVar5] = '\t';
        uVar5 = uVar5 + 1;
      }
      uVar4 = len2;
      if (0xfff - uVar5 < len2) {
        uVar4 = 0xfff - uVar5;
      }
      len2 = uVar4;
      memcpy(buffer + uVar5,pvVar2,uVar4);
      uVar5 = uVar5 + uVar4;
      lua_settop();
      local_1014 = local_1014 + 1;
    } while (local_1014 <= iVar3);
    if (0xfff < uVar5) {
                    /* WARNING: Subroutine does not return */
      __report_rangecheckfailure();
    }
  }
  buffer[uVar5] = '\0';
  PrintConsoleMessage(buffer);
  return 0;
}


// ---------------------------------------------------------------------
// LuaPanic  @ 4fc54b8f  lines 37-45

int __cdecl LuaPanic(lua_State *L)

{
  char *fmtarg1;
  
  fmtarg1 = (char *)lua_tolstring((undefined4 *)0x0);
  FormatConsoleMessage("Lua panic: %s",fmtarg1);
  FormatToMessagesBox("Lua panic: %s",0xffff0000);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::LuaCheckStatus  @ 4fc53318  lines 49-62

bool __cdecl LuaBindings::LuaCheckStatus(int param_1,lua_State *param_2,char *param_3)

{
  char *in_EDX;
  
  lua_tolstring((undefined4 *)0x0);
  FormatConsoleMessage(in_EDX);
  FormatToMessagesBox(in_EDX,0xffff0000);
  return false;
}


// ---------------------------------------------------------------------
// LuaBindings::PushHandle  @ 4fc54b71  lines 66-71

void __cdecl LuaBindings::PushHandle(lua_State *L,int h)

{
  int *piVar1;
  
  piVar1 = *(int **)(L + 8);
  if (h == 0) {
    piVar1[1] = 0x7ff7a500;
  }
  else {
    *piVar1 = h;
    piVar1[1] = 0x7ff7a502;
  }
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return;
}


// ---------------------------------------------------------------------
// LuaBindings::GetHandle  @ 4fc4e560  lines 76-88

int __cdecl LuaBindings::GetHandle(lua_State *L)

{
  int iVar1;
  char *pcVar2;
  
  iVar1 = lua_isnumber();
  if (iVar1 == 0) {
    pcVar2 = (char *)luaL_checklstring((undefined4 *)0x0);
    iVar1 = ::GetHandle(pcVar2);
  }
  else {
    iVar1 = lua_tointegerx((undefined4 *)0x0);
    iVar1 = ::GetHandle(iVar1);
  }
  PushHandle(L,iVar1);
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetHandle  @ 4fc48e30  lines 92-94

int __cdecl LuaBindings::GetHandle(lua_State *L,int n)

{
  uint uVar1;
  
  uVar1 = luaL_testudata();
  return uVar1;
}


// ---------------------------------------------------------------------
// LuaBindings::RequireHandle  @ 4fc48e0d  lines 98-103

int __cdecl LuaBindings::RequireHandle(lua_State *L,int n)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = lua_type();
  iVar2 = 0;
  if (uVar1 != 0) {
    iVar2 = luaL_checkudata();
  }
  return iVar2;
}


// ---------------------------------------------------------------------
// LuaBindings::Handle_ToString  @ 4fc4f33a  lines 107-113

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl LuaBindings::Handle_ToString(lua_State *L)

{
  uint fmtarg1;
  char buf [68];
  uint local_c;
  
  local_c = __security_cookie ^ (uint)&stack0xfffffffc;
  fmtarg1 = RequireHandle(L,1);
  sprintf_s<64>((char (*) [64])buf,"%08x",fmtarg1);
  lua_pushstring();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::Handle_ToInteger  @ 4fc4d60d  lines 117-122

int __cdecl LuaBindings::Handle_ToInteger(lua_State *L)

{
  char *_Str;
  int h;
  
  _Str = (char *)luaL_checklstring((undefined4 *)0x0);
  h = atoi(_Str);
  PushHandle(L,h);
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetVector  @ 4fc48dff  lines 127-129

Vector * __cdecl LuaBindings::GetVector(lua_State *L,int n)

{
  Vector *pVVar1;
  
  pVVar1 = (Vector *)luaL_testudata();
  return pVVar1;
}


// ---------------------------------------------------------------------
// LuaBindings::RequireVector  @ 4fc48df1  lines 133-135

Vector * __cdecl LuaBindings::RequireVector(lua_State *L,int n)

{
  Vector *pVVar1;
  
  pVVar1 = (Vector *)luaL_checkudata();
  return pVVar1;
}


// ---------------------------------------------------------------------
// LuaBindings::NewVector  @ 4fc48dc0  lines 139-144

Vector * __cdecl LuaBindings::NewVector(lua_State *L)

{
  Vector *pVVar1;
  
  pVVar1 = (Vector *)lua_newuserdata();
  lua_getfield();
  lua_setmetatable();
  return pVVar1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetMatrix  @ 4fc48db2  lines 149-151

Matrix * __cdecl LuaBindings::GetMatrix(lua_State *L,int n)

{
  Matrix *pMVar1;
  
  pMVar1 = (Matrix *)luaL_testudata();
  return pMVar1;
}


// ---------------------------------------------------------------------
// LuaBindings::RequireMatrix  @ 4fc48da4  lines 155-157

Matrix * __cdecl LuaBindings::RequireMatrix(lua_State *L,int n)

{
  Matrix *pMVar1;
  
  pMVar1 = (Matrix *)luaL_checkudata();
  return pMVar1;
}


// ---------------------------------------------------------------------
// LuaBindings::NewMatrix  @ 4fc49a28  lines 161-166

Matrix * __cdecl LuaBindings::NewMatrix(lua_State *L)

{
  Matrix *pMVar1;
  
  pMVar1 = (Matrix *)lua_newuserdata();
  lua_getfield();
  lua_setmetatable();
  return pMVar1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetQuaternion  @ 4fc48d96  lines 171-173

Quaternion * __cdecl LuaBindings::GetQuaternion(lua_State *L,int n)

{
  Quaternion *pQVar1;
  
  pQVar1 = (Quaternion *)luaL_testudata();
  return pQVar1;
}


// ---------------------------------------------------------------------
// LuaBindings::RequireQuaternion  @ 4fc48d88  lines 177-179

Quaternion * __cdecl LuaBindings::RequireQuaternion(lua_State *L,int n)

{
  Quaternion *pQVar1;
  
  pQVar1 = (Quaternion *)luaL_checkudata();
  return pQVar1;
}


// ---------------------------------------------------------------------
// LuaBindings::NewQuaternion  @ 4fc48d57  lines 183-188

Quaternion * __cdecl LuaBindings::NewQuaternion(lua_State *L)

{
  Quaternion *pQVar1;
  
  pQVar1 = (Quaternion *)lua_newuserdata();
  lua_getfield();
  lua_setmetatable();
  return pQVar1;
}


// ---------------------------------------------------------------------
// LuaBindings::SetQuaternion  @ 4fc54017  lines 192-199

int __cdecl LuaBindings::SetQuaternion(lua_State *L)

{
  uint uVar1;
  Quaternion *pQVar2;
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
    in_XMM0_Qa = 1.0;
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
  pQVar2 = NewQuaternion(L);
  pQVar2->s = (float)in_XMM0_Qa;
  (pQVar2->v).x = (float)(double)CONCAT44(uVar8,uVar5);
  (pQVar2->v).y = fVar7;
  (pQVar2->v).z = (float)dVar4;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::luaL_optboolean  @ 4fc4d602  lines 203-205

bool __cdecl LuaBindings::luaL_optboolean(lua_State *param_1,int param_2,int param_3)

{
  int iVar1;
  
  iVar1 = lua_toboolean();
  return iVar1 != 0;
}


// ---------------------------------------------------------------------
// LuaBindings::Vector_Index  @ 4fc54afa  lines 210-229

int __cdecl LuaBindings::Vector_Index(lua_State *L)

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
// LuaBindings::Vector_NewIndex  @ 4fc4e70c  lines 234-253

int __cdecl LuaBindings::Vector_NewIndex(lua_State *L)

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
// LuaBindings::Vector_Neg  @ 4fc49c3c  lines 257-261

int __cdecl LuaBindings::Vector_Neg(lua_State *L)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float *pfVar4;
  Vector *pVVar5;
  
  pfVar4 = (float *)luaL_checkudata();
  fVar1 = *pfVar4;
  fVar2 = pfVar4[1];
  fVar3 = pfVar4[2];
  pVVar5 = NewVector(L);
  pVVar5->x = -fVar1;
  pVVar5->y = -fVar2;
  pVVar5->z = -fVar3;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::Vector_Add  @ 4fc4c18f  lines 265-270

int __cdecl LuaBindings::Vector_Add(lua_State *L)

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
  
  pfVar7 = (float *)luaL_checkudata();
  pfVar8 = (float *)luaL_checkudata();
  fVar1 = *pfVar8;
  fVar2 = *pfVar7;
  fVar3 = pfVar8[1];
  fVar4 = pfVar7[1];
  fVar5 = pfVar8[2];
  fVar6 = pfVar7[2];
  pVVar9 = NewVector(L);
  pVVar9->x = fVar1 + fVar2;
  pVVar9->y = fVar3 + fVar4;
  pVVar9->z = fVar5 + fVar6;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::Vector_Sub  @ 4fc4c810  lines 274-279

int __cdecl LuaBindings::Vector_Sub(lua_State *L)

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
  
  pfVar7 = (float *)luaL_checkudata();
  pfVar8 = (float *)luaL_checkudata();
  fVar1 = *pfVar7;
  fVar2 = *pfVar8;
  fVar3 = pfVar7[1];
  fVar4 = pfVar8[1];
  fVar5 = pfVar7[2];
  fVar6 = pfVar8[2];
  pVVar9 = NewVector(L);
  pVVar9->x = fVar1 - fVar2;
  pVVar9->y = fVar3 - fVar4;
  pVVar9->z = fVar5 - fVar6;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::Vector_Mul  @ 4fc5389d  lines 283-305

int __cdecl LuaBindings::Vector_Mul(lua_State *L)

{
  int iVar1;
  float *pfVar2;
  Vector *pVVar3;
  float *pfVar4;
  undefined4 in_XMM0_Da;
  undefined4 in_XMM0_Db;
  float local_14;
  float local_10;
  float local_c;
  
  iVar1 = lua_isnumber();
  if (iVar1 == 0) {
    iVar1 = lua_isnumber();
    pfVar2 = (float *)luaL_checkudata();
    if (iVar1 == 0) {
      pfVar4 = (float *)luaL_checkudata();
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
    pVVar3 = NewVector(L);
  }
  else {
    lua_tonumberx((undefined4 *)0x0);
    local_c = (float)(double)CONCAT44(in_XMM0_Db,in_XMM0_Da);
    pfVar2 = (float *)luaL_checkudata();
    local_14 = *pfVar2 * local_c;
    local_10 = pfVar2[1] * local_c;
    local_c = pfVar2[2] * local_c;
    pVVar3 = NewVector(L);
  }
  pVVar3->x = local_14;
  pVVar3->y = local_10;
  pVVar3->z = local_c;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::Vector_Div  @ 4fc4c45d  lines 309-331

int __cdecl LuaBindings::Vector_Div(lua_State *L)

{
  int iVar1;
  float *pfVar2;
  Vector *pVVar3;
  float *pfVar4;
  undefined4 in_XMM0_Da;
  undefined4 in_XMM0_Db;
  float local_14;
  float local_10;
  float local_c;
  
  iVar1 = lua_isnumber();
  if (iVar1 == 0) {
    iVar1 = lua_isnumber();
    pfVar2 = (float *)luaL_checkudata();
    if (iVar1 == 0) {
      pfVar4 = (float *)luaL_checkudata();
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
    pVVar3 = NewVector(L);
  }
  else {
    lua_tonumberx((undefined4 *)0x0);
    local_c = (float)(double)CONCAT44(in_XMM0_Db,in_XMM0_Da);
    pfVar2 = (float *)luaL_checkudata();
    local_14 = local_c / *pfVar2;
    local_10 = local_c / pfVar2[1];
    local_c = local_c / pfVar2[2];
    pVVar3 = NewVector(L);
  }
  pVVar3->x = local_14;
  pVVar3->y = local_10;
  pVVar3->z = local_c;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::Vector_Eq  @ 4fc53a86  lines 335-340

int __cdecl LuaBindings::Vector_Eq(lua_State *L)

{
  undefined4 *puVar1;
  float *pfVar2;
  float *pfVar3;
  undefined4 uVar4;
  
  pfVar2 = (float *)luaL_checkudata();
  pfVar3 = (float *)luaL_checkudata();
  if (((*pfVar2 == *pfVar3) && (pfVar2[1] == pfVar3[1])) && (pfVar2[2] == pfVar3[2])) {
    uVar4 = 1;
  }
  else {
    uVar4 = 0;
  }
  puVar1 = *(undefined4 **)(L + 8);
  *puVar1 = uVar4;
  puVar1[1] = 0x7ff7a501;
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::Vector_ToString  @ 4fc4fbea  lines 344-350

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl LuaBindings::Vector_ToString(lua_State *L)

{
  float *pfVar1;
  char local_50 [68];
  uint local_c;
  
  local_c = __security_cookie ^ (uint)local_50;
  pfVar1 = (float *)luaL_checkudata();
  memset(local_50,0,0x40);
  sprintf_s<64>((char (*) [64])local_50,"{x=%f, y=%f, z=%f}",(double)*pfVar1,(double)pfVar1[1],
                (double)pfVar1[2]);
  lua_pushstring();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::Matrix_Index  @ 4fc53b90  lines 355-411

int __cdecl LuaBindings::Matrix_Index(lua_State *L)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float *pfVar4;
  int iVar5;
  uint uVar6;
  Vector *pVVar7;
  uint unaff_ESI;
  char *unaff_EDI;
  
  pfVar4 = (float *)luaL_testudata();
  iVar5 = luaL_checklstring((undefined4 *)0x0);
  if (iVar5 == 0) {
    return 0;
  }
  uVar6 = Hash(unaff_EDI,unaff_ESI);
  if (uVar6 < 0xb96c4116) {
    if (uVar6 != 0xb96c4115) {
      if (uVar6 < 0x44e771bd) {
        if (uVar6 == 0x44e771bc) {
          pfVar4 = pfVar4 + 0xc;
        }
        else {
          if (((uVar6 == 0x21f7b0fc) || (uVar6 == 0x22f7b28f)) || (uVar6 == 0x24f7b5b5))
          goto LAB_4fc53c66;
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
        goto LAB_4fc53c66;
      }
LAB_4fc53c10:
      fVar1 = *pfVar4;
      fVar2 = pfVar4[1];
      fVar3 = pfVar4[2];
      pVVar7 = NewVector(L);
      pVVar7->x = fVar1;
      pVVar7->y = fVar2;
      pVVar7->z = fVar3;
      return 1;
    }
  }
  else if (((uVar6 != 0xc5a81bb4) && (uVar6 != 0xc6a81d47)) && (uVar6 != 0xc8a8206d)) {
    if (uVar6 == 0xe179dbd8) {
      pfVar4 = pfVar4 + 8;
      goto LAB_4fc53c10;
    }
    if (((uVar6 != 0xebf98a60) && (uVar6 != 0xecf98bf3)) && (uVar6 != 0xeef98f19)) {
      return 0;
    }
  }
LAB_4fc53c66:
  lua_pushnumber();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::Matrix_NewIndex  @ 4fc521ce  lines 416-478

int __cdecl LuaBindings::Matrix_NewIndex(lua_State *L)

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
        if (uVar3 != 0xb86c3f82) {
          return 0;
        }
        luaL_checknumber();
        *pfVar1 = (float)(double)CONCAT44(in_XMM0_Db,in_XMM0_Da);
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
      if (uVar3 != 0xecf98bf3) {
        if (uVar3 != 0xeef98f19) {
          return 0;
        }
        luaL_checknumber();
        pfVar1[0xe] = (float)(double)CONCAT44(in_XMM0_Db,in_XMM0_Da);
        return 0;
      }
      luaL_checknumber();
      pfVar1[0xc] = (float)(double)CONCAT44(in_XMM0_Db,in_XMM0_Da);
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
// LuaBindings::Matrix_Mul  @ 4fc48e94  lines 482-500

int __cdecl LuaBindings::Matrix_Mul(lua_State *L)

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
LAB_4fc48f3c:
    iVar7 = 0;
  }
  else {
    pMVar5 = (Matrix *)luaL_testudata();
    if (pMVar5 == (Matrix *)0x0) {
      pVVar6 = (Vector *)luaL_testudata();
      if (pVVar6 == (Vector *)0x0) goto LAB_4fc48f3c;
      pVVar6 = ::Vector_Transform(pVVar6,unaff_EDI,&unaff_ESI->right);
      fVar1 = pVVar6->x;
      fVar2 = pVVar6->y;
      fVar3 = pVVar6->z;
      pVVar6 = NewVector(L);
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
      pMVar5 = NewMatrix(L);
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
// LuaBindings::Matrix_ToString  @ 4fc4ed19  lines 504-517

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl LuaBindings::Matrix_ToString(lua_State *L)

{
  float *pfVar1;
  undefined1 auStack_114 [4];
  char local_110 [260];
  uint local_c;
  
  local_c = __security_cookie ^ (uint)auStack_114;
  pfVar1 = (float *)luaL_testudata();
  if (pfVar1 != (float *)0x0) {
    sprintf_s<256>((char (*) [256])local_110,
                   "{right_x=%f, right_y=%f, right_z=%f, up_x=%f, up_y=%f, up_z=%f, front_x=%f, front_y=%f, front_z=%f, posit_x=%f, posit_y=%f, posit_z=%f}"
                   ,(double)*pfVar1,(double)pfVar1[1],(double)pfVar1[2],(double)pfVar1[4],
                   (double)pfVar1[5],(double)pfVar1[6],(double)pfVar1[8],(double)pfVar1[9],
                   (double)pfVar1[10],(double)pfVar1[0xc],(double)pfVar1[0xd],(double)pfVar1[0xe]);
    lua_pushstring();
  }
  return (uint)(pfVar1 != (float *)0x0);
}


// ---------------------------------------------------------------------
// LuaBindings::Quaternion_Index  @ 4fc4d933  lines 522-544

int __cdecl LuaBindings::Quaternion_Index(lua_State *L)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint unaff_ESI;
  char *unaff_EDI;
  
  iVar3 = 1;
  uVar1 = luaL_testudata();
  if (((uVar1 == 0) || (iVar2 = luaL_checklstring((undefined4 *)0x0), iVar2 == 0)) ||
     ((uVar1 = Hash(unaff_EDI,unaff_ESI), uVar1 != 0xf60c4582 &&
      (((uVar1 != 0xfc0c4ef4 && (uVar1 != 0xfd0c5087)) && (uVar1 != 0xff0c53ad)))))) {
    iVar3 = 0;
  }
  else {
    lua_pushnumber();
  }
  return iVar3;
}


// ---------------------------------------------------------------------
// LuaBindings::Quaternion_NewIndex  @ 4fc53749  lines 549-571

int __cdecl LuaBindings::Quaternion_NewIndex(lua_State *L)

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
// LuaBindings::Quaternion_Mul  @ 4fc5433c  lines 575-588

int __cdecl LuaBindings::Quaternion_Mul(lua_State *L)

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
  float fVar10;
  float fVar11;
  float fVar12;
  float *pfVar13;
  float *pfVar14;
  Quaternion *pQVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  
  pfVar13 = (float *)luaL_testudata();
  if ((pfVar13 != (float *)0x0) && (pfVar14 = (float *)luaL_testudata(), pfVar14 != (float *)0x0)) {
    fVar1 = pfVar13[1];
    fVar2 = pfVar14[1];
    fVar3 = *pfVar13;
    fVar17 = (fVar1 + pfVar13[3]) * (fVar2 + pfVar14[2]);
    fVar4 = *pfVar14;
    fVar18 = (fVar1 - pfVar13[3]) * (fVar2 - pfVar14[2]);
    fVar19 = fVar18 + fVar17;
    fVar16 = (fVar3 + pfVar13[2]) * (fVar4 - pfVar14[3]);
    fVar20 = (fVar3 - pfVar13[2]) * (pfVar14[3] + fVar4);
    fVar5 = pfVar14[1];
    fVar17 = fVar17 - fVar18;
    fVar18 = pfVar14[3];
    fVar6 = pfVar14[2];
    fVar7 = *pfVar14;
    fVar8 = pfVar13[2];
    fVar9 = pfVar13[3];
    fVar10 = pfVar13[2];
    fVar11 = pfVar14[2];
    fVar12 = pfVar14[3];
    pQVar15 = NewQuaternion(L);
    pQVar15->s = (fVar9 - fVar10) * (fVar11 - fVar12) - ((fVar19 - fVar16) - fVar20) * 0.5;
    (pQVar15->v).x = (fVar3 + fVar1) * (fVar4 + fVar5) - (fVar19 + fVar16 + fVar20) * 0.5;
    (pQVar15->v).y = (fVar3 - fVar1) * (fVar18 + fVar6) + ((fVar17 + fVar16) - fVar20) * 0.5;
    (pQVar15->v).z = (fVar8 + fVar9) * (fVar7 - fVar2) + ((fVar17 - fVar16) + fVar20) * 0.5;
    return 1;
  }
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::Quaternion_ToString  @ 4fc52d3e  lines 592-598

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl LuaBindings::Quaternion_ToString(lua_State *L)

{
  float *pfVar1;
  char local_50 [68];
  uint local_c;
  
  local_c = __security_cookie ^ (uint)local_50;
  pfVar1 = (float *)luaL_checkudata();
  memset(local_50,0,0x40);
  sprintf_s<64>((char (*) [64])local_50,"{s=%f, x=%f, y=%f, z=%f}",(double)*pfVar1,(double)pfVar1[1]
                ,(double)pfVar1[2],(double)pfVar1[3]);
  lua_pushstring();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::SetVector  @ 4fc49cb1  lines 602-608

int __cdecl LuaBindings::SetVector(lua_State *L)

{
  uint uVar1;
  Vector *pVVar2;
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
  pVVar2 = NewVector(L);
  pVVar2->x = (float)(double)CONCAT44(uVar6,uVar3);
  pVVar2->y = fVar9;
  pVVar2->z = (float)(double)CONCAT44(uVar8,uVar5);
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::DotProduct  @ 4fc4ca26  lines 612-617

int __cdecl LuaBindings::DotProduct(lua_State *L)

{
  luaL_checkudata();
  luaL_checkudata();
  lua_pushnumber();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::CrossProduct  @ 4fc4f2e6  lines 621-626

int __cdecl LuaBindings::CrossProduct(lua_State *L)

{
  float fVar1;
  float fVar2;
  float fVar3;
  Vector *pVVar4;
  char *pcVar5;
  char *pcVar6;
  
  pcVar6 = "Vector";
  luaL_checkudata();
  pcVar5 = "Vector";
  pVVar4 = (Vector *)luaL_checkudata();
  pVVar4 = Cross_Product(pVVar4,(Vector *)pcVar5,(Vector *)pcVar6);
  fVar1 = pVVar4->x;
  fVar2 = pVVar4->y;
  fVar3 = pVVar4->z;
  pVVar4 = NewVector(L);
  pVVar4->x = fVar1;
  pVVar4->y = fVar2;
  pVVar4->z = fVar3;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::Normalize  @ 4fc51dd1  lines 630-634

int __cdecl LuaBindings::Normalize(lua_State *L)

{
  float fVar1;
  float fVar2;
  float fVar3;
  Vector *pVVar4;
  Vector *unaff_ESI;
  Vector *unaff_EDI;
  
  luaL_checkudata();
  pVVar4 = Normalize_Vector(unaff_EDI,unaff_ESI);
  fVar1 = pVVar4->x;
  fVar2 = pVVar4->y;
  fVar3 = pVVar4->z;
  pVVar4 = NewVector(L);
  pVVar4->x = fVar1;
  pVVar4->y = fVar2;
  pVVar4->z = fVar3;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::Length  @ 4fc536ba  lines 638-642

int __cdecl LuaBindings::Length(lua_State *L)

{
  Vector *pVVar1;
  
  pVVar1 = (Vector *)luaL_checkudata();
  GetLength3D(*pVVar1);
  lua_pushnumber();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::LengthSquared  @ 4fc54201  lines 646-650

int __cdecl LuaBindings::LengthSquared(lua_State *L)

{
  luaL_checkudata();
  lua_pushnumber();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::Distance2D  @ 4fc4fcf1  lines 654-659

int __cdecl LuaBindings::Distance2D(lua_State *L)

{
  luaL_checkudata();
  luaL_checkudata();
  libm_sse2_sqrt_precise();
  lua_pushnumber();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::Distance2DSquared  @ 4fc50ae3  lines 663-668

int __cdecl LuaBindings::Distance2DSquared(lua_State *L)

{
  luaL_checkudata();
  luaL_checkudata();
  lua_pushnumber();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::Distance3D  @ 4fc51b87  lines 672-686

int __cdecl LuaBindings::Distance3D(lua_State *L)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  Vector local_20;
  Vector local_14;
  
  uVar2 = luaL_testudata();
  if (uVar2 == 0) {
    iVar3 = RequireHandle(L,1);
    iVar4 = RequireHandle(L,2);
    bVar1 = ::IsAround(iVar3);
    if ((!bVar1) || (bVar1 = ::IsAround(iVar4), !bVar1)) goto LAB_4fc51c7a;
    ::GetPosition(iVar4,&local_20);
    ::GetPosition(iVar3,&local_14);
  }
  else {
    luaL_checkudata();
    luaL_checkudata();
  }
  libm_sse2_sqrt_precise();
LAB_4fc51c7a:
  lua_pushnumber();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::Distance3DSquared  @ 4fc52b48  lines 690-704

int __cdecl LuaBindings::Distance3DSquared(lua_State *L)

{
  uint uVar1;
  Vector *v1;
  Vector *v2;
  int h1;
  int h2;
  
  uVar1 = luaL_testudata();
  if (uVar1 == 0) {
    h1 = RequireHandle(L,1);
    h2 = RequireHandle(L,2);
    GetDistance3DSquared(h1,h2);
  }
  else {
    v1 = (Vector *)luaL_checkudata();
    v2 = (Vector *)luaL_checkudata();
    GetDistance3DSquared(v1,v2);
  }
  lua_pushnumber();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::SetMatrix  @ 4fc54756  lines 708-737

int __cdecl LuaBindings::SetMatrix(lua_State *L)

{
  Vector vr;
  Vector vu;
  Vector vf;
  Vector vp;
  Vector *pVVar1;
  Vector *pVVar2;
  Vector *pVVar3;
  Vector *pVVar4;
  Matrix *pMVar5;
  uint uVar6;
  int iVar7;
  float *pfVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
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
  float fVar33;
  float local_88 [16];
  Matrix local_48;
  
  pVVar1 = (Vector *)luaL_testudata();
  if (pVVar1 == (Vector *)0x0) {
    uVar6 = lua_type();
    uVar9 = 0;
    uVar21 = 0;
    if ((int)uVar6 < 1) {
      uVar9 = 0;
      uVar21 = 0;
    }
    else {
      luaL_checknumber();
    }
    uVar22 = 0;
    uVar10 = 0;
    uVar6 = lua_type();
    if ((int)uVar6 < 1) {
      uVar11 = uVar10;
      uVar23 = uVar22;
      uVar10 = 0;
      uVar22 = 0;
    }
    else {
      luaL_checknumber();
      uVar11 = 0;
      uVar23 = 0;
    }
    uVar6 = lua_type();
    if ((int)uVar6 < 1) {
      uVar12 = uVar11;
      uVar24 = uVar23;
      uVar11 = 0;
      uVar23 = 0;
    }
    else {
      luaL_checknumber();
      uVar12 = 0;
      uVar24 = 0;
    }
    uVar6 = lua_type();
    if ((int)uVar6 < 1) {
      uVar13 = uVar12;
      uVar25 = uVar24;
      uVar12 = 0;
      uVar24 = 0;
    }
    else {
      luaL_checknumber();
      uVar13 = 0;
      uVar25 = 0;
    }
    uVar6 = lua_type();
    if ((int)uVar6 < 1) {
      uVar14 = uVar13;
      uVar26 = uVar25;
      uVar13 = 0;
      uVar25 = 0;
    }
    else {
      luaL_checknumber();
      uVar14 = 0;
      uVar26 = 0;
    }
    uVar6 = lua_type();
    if ((int)uVar6 < 1) {
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
    uVar6 = lua_type();
    if ((int)uVar6 < 1) {
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
    uVar6 = lua_type();
    if ((int)uVar6 < 1) {
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
    uVar6 = lua_type();
    if ((int)uVar6 < 1) {
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
    uVar6 = lua_type();
    if ((int)uVar6 < 1) {
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
    uVar6 = lua_type();
    if ((int)uVar6 < 1) {
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
    fVar33 = (float)(double)CONCAT44(uVar31,uVar19);
    uVar6 = lua_type();
    if (0 < (int)uVar6) {
      luaL_checknumber();
      fVar33 = (float)(double)CONCAT44(uVar31,uVar19);
    }
    vr.y = (float)(double)CONCAT44(uVar22,uVar10);
    vr.x = (float)(double)CONCAT44(uVar21,uVar9);
    vr.z = (float)(double)CONCAT44(uVar23,uVar11);
    vu.y = (float)(double)CONCAT44(uVar25,uVar13);
    vu.x = (float)(double)CONCAT44(uVar24,uVar12);
    vu.z = (float)(double)CONCAT44(uVar26,uVar14);
    vf.y = (float)(double)CONCAT44(uVar28,uVar16);
    vf.x = (float)(double)CONCAT44(uVar27,uVar15);
    vf.z = (float)(double)CONCAT44(uVar29,uVar17);
    vp.y = fVar33;
    vp.x = (float)(double)CONCAT44(uVar30,uVar18);
    vp.z = (float)(double)CONCAT44(uVar32,uVar20);
    pMVar5 = Matrix::Matrix(&local_48,vr,vu,vf,vp);
    pfVar8 = local_88;
    for (iVar7 = 0x10; iVar7 != 0; iVar7 = iVar7 + -1) {
      *pfVar8 = (pMVar5->right).x;
      pMVar5 = (Matrix *)&(pMVar5->right).y;
      pfVar8 = pfVar8 + 1;
    }
  }
  else {
    pVVar2 = (Vector *)luaL_checkudata();
    pVVar3 = (Vector *)luaL_checkudata();
    pVVar4 = (Vector *)luaL_checkudata();
    pMVar5 = Matrix::Matrix(&local_48,*pVVar1,*pVVar2,*pVVar3,*pVVar4);
    pfVar8 = local_88;
    for (iVar7 = 0x10; iVar7 != 0; iVar7 = iVar7 + -1) {
      *pfVar8 = (pMVar5->right).x;
      pMVar5 = (Matrix *)&(pMVar5->right).y;
      pfVar8 = pfVar8 + 1;
    }
  }
  pMVar5 = NewMatrix(L);
  pfVar8 = local_88;
  for (iVar7 = 0x10; iVar7 != 0; iVar7 = iVar7 + -1) {
    (pMVar5->right).x = *pfVar8;
    pfVar8 = pfVar8 + 1;
    pMVar5 = (Matrix *)&(pMVar5->right).y;
  }
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::BuildAxisRotationMatrix  @ 4fc504c5  lines 740-757

int __cdecl LuaBindings::BuildAxisRotationMatrix(lua_State *L)

{
  uint uVar1;
  float *pfVar2;
  Matrix *pMVar3;
  int iVar4;
  Matrix *pMVar5;
  float fVar6;
  double in_XMM0_Qa;
  double dVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  float local_74;
  float local_70;
  undefined8 local_68;
  float fStack_60;
  float fStack_5c;
  Vector local_54;
  Matrix local_48;
  
  uVar1 = lua_type();
  if ((int)uVar1 < 1) {
    in_XMM0_Qa = 0.0;
  }
  else {
    luaL_checknumber();
  }
  uVar8 = (undefined4)((ulonglong)in_XMM0_Qa >> 0x20);
  fVar6 = (float)in_XMM0_Qa;
  local_68._0_4_ = fVar6;
  pfVar2 = (float *)luaL_testudata();
  if (pfVar2 == (float *)0x0) {
    uVar1 = lua_type();
    if ((int)uVar1 < 1) {
      fVar6 = 0.0;
      uVar8 = 0;
    }
    else {
      luaL_checknumber();
    }
    local_74 = (float)(double)CONCAT44(uVar8,fVar6);
    dVar7 = 0.0;
    uVar1 = lua_type();
    if ((int)uVar1 < 1) {
      uVar8 = 0;
      uVar9 = 0;
    }
    else {
      luaL_checknumber();
      uVar8 = SUB84(dVar7,0);
      uVar9 = (undefined4)((ulonglong)dVar7 >> 0x20);
      dVar7 = 0.0;
    }
    local_70 = (float)(double)CONCAT44(uVar9,uVar8);
    uVar1 = lua_type();
    if (0 < (int)uVar1) {
      luaL_checknumber();
    }
    fVar6 = (float)dVar7;
  }
  else {
    local_74 = *pfVar2;
    local_70 = pfVar2[1];
    fVar6 = pfVar2[2];
  }
  dVar7 = (double)((float)local_68 * 0.5);
  local_68 = dVar7;
  libm_sse2_sin_precise();
  local_54.z = (float)dVar7;
  local_54.x = local_54.z * local_74;
  local_54.y = local_54.z * local_70;
  local_54.z = local_54.z * fVar6;
  libm_sse2_cos_precise();
  local_68._0_4_ = (float)local_68;
  local_68._4_4_ = local_54.x;
  fStack_60 = local_54.y;
  fStack_5c = local_54.z;
  local_54.x = 0.0;
  local_54.y = 0.0;
  local_54.z = 0.0;
  ::QuatPos_to_Matrix((Quaternion *)&local_68,&local_54,&local_48);
  pMVar3 = NewMatrix(L);
  pMVar5 = &local_48;
  for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
    (pMVar3->right).x = (pMVar5->right).x;
    pMVar5 = (Matrix *)&(pMVar5->right).y;
    pMVar3 = (Matrix *)&(pMVar3->right).y;
  }
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::BuildPositionRotationMatrix  @ 4fc50b56  lines 760-779

int __cdecl LuaBindings::BuildPositionRotationMatrix(lua_State *L)

{
  uint uVar1;
  Matrix *pMVar2;
  int iVar3;
  Vector *unaff_ESI;
  float *pfVar4;
  float unaff_EDI;
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
                      unaff_EDI,unaff_ESI);
  pfVar4 = local_88;
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pfVar4 = (pMVar2->right).x;
    pMVar2 = (Matrix *)&(pMVar2->right).y;
    pfVar4 = pfVar4 + 1;
  }
  pMVar2 = NewMatrix(L);
  pfVar4 = local_88;
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    (pMVar2->right).x = *pfVar4;
    pfVar4 = pfVar4 + 1;
    pMVar2 = (Matrix *)&(pMVar2->right).y;
  }
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::BuildOrthogonalMatrix  @ 4fc4944d  lines 787-796

int __cdecl LuaBindings::BuildOrthogonalMatrix(lua_State *L)

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
  pMVar2 = NewMatrix(L);
  pfVar4 = local_88;
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    (pMVar2->right).x = *pfVar4;
    pfVar4 = pfVar4 + 1;
    pMVar2 = (Matrix *)&(pMVar2->right).y;
  }
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::BuildDirectionalMatrix  @ 4fc4cd05  lines 799-808

int __cdecl LuaBindings::BuildDirectionalMatrix(lua_State *L)

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
  pMVar2 = NewMatrix(L);
  pfVar4 = local_88;
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    (pMVar2->right).x = *pfVar4;
    pfVar4 = pfVar4 + 1;
    pMVar2 = (Matrix *)&(pMVar2->right).y;
  }
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::Interpolate_Matrix  @ 4fc4e691  lines 812-818

int __cdecl LuaBindings::Interpolate_Matrix(lua_State *L)

{
  Matrix *pMVar1;
  int iVar2;
  float unaff_ESI;
  float *pfVar3;
  Matrix *unaff_EDI;
  undefined4 in_XMM0_Da;
  undefined4 in_XMM0_Db;
  float local_88 [33];
  
  luaL_checkudata();
  pMVar1 = (Matrix *)luaL_checkudata();
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
  pMVar1 = NewMatrix(L);
  pfVar3 = local_88;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    (pMVar1->right).x = *pfVar3;
    pfVar3 = pfVar3 + 1;
    pMVar1 = (Matrix *)&(pMVar1->right).y;
  }
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::Interpolate_Quaternion  @ 4fc4b906  lines 823-829

int __cdecl LuaBindings::Interpolate_Quaternion(lua_State *L)

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
  
  luaL_checkudata();
  pQVar5 = (Quaternion *)luaL_checkudata();
  luaL_checknumber();
  pQVar5 = ::Interpolate_Quaternion
                     (pQVar5,(Quaternion *)(float)(double)CONCAT44(in_XMM0_Db,in_XMM0_Da),unaff_EDI,
                      unaff_ESI);
  fVar1 = pQVar5->s;
  fVar2 = (pQVar5->v).x;
  fVar3 = (pQVar5->v).y;
  fVar4 = (pQVar5->v).z;
  pQVar5 = NewQuaternion(L);
  pQVar5->s = fVar1;
  (pQVar5->v).x = fVar2;
  (pQVar5->v).y = fVar3;
  (pQVar5->v).z = fVar4;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::Normalize_Quaternion  @ 4fc53da1  lines 833-837

int __cdecl LuaBindings::Normalize_Quaternion(lua_State *L)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  Quaternion *pQVar5;
  Quaternion *unaff_ESI;
  Quaternion *unaff_EDI;
  
  luaL_checkudata();
  pQVar5 = ::Normalize_Quaternion(unaff_EDI,unaff_ESI);
  fVar1 = pQVar5->s;
  fVar2 = (pQVar5->v).x;
  fVar3 = (pQVar5->v).y;
  fVar4 = (pQVar5->v).z;
  pQVar5 = NewQuaternion(L);
  pQVar5->s = fVar1;
  (pQVar5->v).x = fVar2;
  (pQVar5->v).y = fVar3;
  (pQVar5->v).z = fVar4;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::Matrix_to_QuatPos  @ 4fc4b63d  lines 841-849

int __cdecl LuaBindings::Matrix_to_QuatPos(lua_State *L)

{
  Matrix *M;
  Quaternion *pQVar1;
  Vector *pVVar2;
  Quaternion q;
  Vector v;
  
  M = (Matrix *)luaL_checkudata();
  ::Matrix_to_QuatPos(M,&q,&v);
  pQVar1 = NewQuaternion(L);
  pQVar1->s = q.s;
  (pQVar1->v).x = q.v.x;
  (pQVar1->v).y = q.v.y;
  (pQVar1->v).z = q.v.z;
  pVVar2 = NewVector(L);
  pVVar2->x = v.x;
  pVVar2->y = v.y;
  pVVar2->z = v.z;
  return 2;
}


// ---------------------------------------------------------------------
// LuaBindings::Matrix_to_Quaternion  @ 4fc51e91  lines 852-859

int __cdecl LuaBindings::Matrix_to_Quaternion(lua_State *L)

{
  Matrix *M;
  Quaternion *pQVar1;
  Quaternion q;
  Vector v;
  
  M = (Matrix *)luaL_checkudata();
  ::Matrix_to_QuatPos(M,&q,&v);
  pQVar1 = NewQuaternion(L);
  pQVar1->s = q.s;
  (pQVar1->v).x = q.v.x;
  (pQVar1->v).y = q.v.y;
  (pQVar1->v).z = q.v.z;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::QuatPos_to_Matrix  @ 4fc4d352  lines 863-881

int __cdecl LuaBindings::QuatPos_to_Matrix(lua_State *L)

{
  Quaternion *Q;
  float *pfVar1;
  uint uVar2;
  Matrix *pMVar3;
  int iVar4;
  Matrix *pMVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  float fVar10;
  float local_5c;
  Vector local_54;
  Matrix local_48;
  
  Q = (Quaternion *)luaL_checkudata();
  pfVar1 = (float *)luaL_testudata();
  if (pfVar1 == (float *)0x0) {
    uVar2 = lua_type();
    uVar6 = 0;
    uVar8 = 0;
    if ((int)uVar2 < 1) {
      uVar6 = 0;
      uVar8 = 0;
    }
    else {
      luaL_checknumber();
    }
    uVar9 = 0;
    uVar7 = 0;
    local_5c = (float)(double)CONCAT44(uVar8,uVar6);
    uVar2 = lua_type();
    if ((int)uVar2 < 1) {
      uVar6 = uVar7;
      uVar8 = uVar9;
      uVar7 = 0;
      uVar9 = 0;
    }
    else {
      luaL_checknumber();
      uVar6 = 0;
      uVar8 = 0;
    }
    fVar10 = (float)(double)CONCAT44(uVar9,uVar7);
    uVar2 = lua_type();
    local_54.y = fVar10;
    if (0 < (int)uVar2) {
      luaL_checknumber();
      local_54.y = (float)(double)CONCAT44(uVar9,uVar7);
    }
    local_54.z = (float)(double)CONCAT44(uVar8,uVar6);
  }
  else {
    local_5c = *pfVar1;
    local_54.y = pfVar1[1];
    local_54.z = pfVar1[2];
  }
  local_54.x = local_5c;
  ::QuatPos_to_Matrix(Q,&local_54,&local_48);
  pMVar3 = NewMatrix(L);
  pMVar5 = &local_48;
  for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
    (pMVar3->right).x = (pMVar5->right).x;
    pMVar5 = (Matrix *)&(pMVar5->right).y;
    pMVar3 = (Matrix *)&(pMVar3->right).y;
  }
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::Vector_Transform  @ 4fc4990f  lines 885-902

int __cdecl LuaBindings::Vector_Transform(lua_State *L)

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
  
  luaL_checkudata();
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
  pVVar3 = NewVector(L);
  pVVar3->x = local_28[0].x;
  pVVar3->y = local_28[0].y;
  pVVar3->z = local_28[0].z;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::Vector_TransformInv  @ 4fc4fad1  lines 906-923

int __cdecl LuaBindings::Vector_TransformInv(lua_State *L)

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
  
  luaL_checkudata();
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
  pVVar3 = NewVector(L);
  pVVar3->x = local_28[0].x;
  pVVar3->y = local_28[0].y;
  pVVar3->z = local_28[0].z;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::Vector_Rotate  @ 4fc4b072  lines 927-944

int __cdecl LuaBindings::Vector_Rotate(lua_State *L)

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
  
  luaL_checkudata();
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
  pVVar3 = NewVector(L);
  pVVar3->x = local_28[0].x;
  pVVar3->y = local_28[0].y;
  pVVar3->z = local_28[0].z;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::Vector_RotateInv  @ 4fc4ae6c  lines 948-965

int __cdecl LuaBindings::Vector_RotateInv(lua_State *L)

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
  float fVar14;
  double dVar15;
  double dVar16;
  float fVar17;
  float local_1c;
  
  pfVar10 = (float *)luaL_checkudata();
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
  pVVar13 = NewVector(L);
  pVVar13->x = fVar1 * fVar17 + fVar2 * local_1c + fVar3 * fVar14;
  pVVar13->y = fVar4 * local_1c + fVar5 * fVar17 + fVar6 * fVar14;
  pVVar13->z = fVar7 * local_1c + fVar8 * fVar17 + fVar9 * fVar14;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::Matrix_Inverse  @ 4fc542eb  lines 969-973

int __cdecl LuaBindings::Matrix_Inverse(lua_State *L)

{
  Matrix *pMVar1;
  int iVar2;
  Matrix *unaff_ESI;
  float *pfVar3;
  Matrix *unaff_EDI;
  float local_88 [33];
  
  luaL_checkudata();
  pMVar1 = ::Matrix_Inverse(unaff_EDI,unaff_ESI);
  pfVar3 = local_88;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *pfVar3 = (pMVar1->right).x;
    pMVar1 = (Matrix *)&(pMVar1->right).y;
    pfVar3 = pfVar3 + 1;
  }
  pMVar1 = NewMatrix(L);
  pfVar3 = local_88;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    (pMVar1->right).x = *pfVar3;
    pfVar3 = pfVar3 + 1;
    pMVar1 = (Matrix *)&(pMVar1->right).y;
  }
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::Build_Yaw_Matrix  @ 4fc514e0  lines 977-994

int __cdecl LuaBindings::Build_Yaw_Matrix(lua_State *L)

{
  uint uVar1;
  Matrix *pMVar2;
  int iVar3;
  Vector *unaff_ESI;
  float *pfVar4;
  float unaff_EDI;
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
  pMVar2 = ::Build_Yaw_Matrix((Matrix *)(float)(double)CONCAT44(in_XMM0_Db,in_XMM0_Da),unaff_EDI,
                              unaff_ESI);
  pfVar4 = local_88;
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pfVar4 = (pMVar2->right).x;
    pMVar2 = (Matrix *)&(pMVar2->right).y;
    pfVar4 = pfVar4 + 1;
  }
  pMVar2 = NewMatrix(L);
  pfVar4 = local_88;
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    (pMVar2->right).x = *pfVar4;
    pfVar4 = pfVar4 + 1;
    pMVar2 = (Matrix *)&(pMVar2->right).y;
  }
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::Add_Mult_Vectors  @ 4fc4a69f  lines 998-1004

int __cdecl LuaBindings::Add_Mult_Vectors(lua_State *L)

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
  float fVar10;
  double in_XMM0_Qa;
  
  pfVar7 = (float *)luaL_checkudata();
  pfVar8 = (float *)luaL_checkudata();
  luaL_checknumber();
  fVar1 = *pfVar8;
  fVar10 = (float)in_XMM0_Qa;
  fVar2 = *pfVar7;
  fVar3 = pfVar8[1];
  fVar4 = pfVar7[1];
  fVar5 = pfVar8[2];
  fVar6 = pfVar7[2];
  pVVar9 = NewVector(L);
  pVVar9->x = fVar1 * fVar10 + fVar2;
  pVVar9->y = fVar3 * fVar10 + fVar4;
  pVVar9->z = fVar5 * fVar10 + fVar6;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::IsNullVector  @ 4fc51135  lines 1008-1012

int __cdecl LuaBindings::IsNullVector(lua_State *L)

{
  bool bVar1;
  Vector *pVVar2;
  uint *extraout_EDX;
  
  pVVar2 = (Vector *)luaL_checkudata();
  bVar1 = ::IsNullVector(*pVVar2);
  *extraout_EDX = (uint)bVar1;
  extraout_EDX[1] = 0x7ff7a501;
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::FrontToRadian  @ 4fc50268  lines 1016-1020

int __cdecl LuaBindings::FrontToRadian(lua_State *L)

{
  Vector *pVVar1;
  
  pVVar1 = (Vector *)luaL_checkudata();
  ::FrontToRadian(*pVVar1);
  lua_pushnumber();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::FrontToDegrees  @ 4fc52de1  lines 1024-1028

int __cdecl LuaBindings::FrontToDegrees(lua_State *L)

{
  Vector *pVVar1;
  
  pVVar1 = (Vector *)luaL_checkudata();
  ::FrontToRadian(*pVVar1);
  lua_pushnumber();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetFacingDirection  @ 4fc53010  lines 1032-1037

int __cdecl LuaBindings::GetFacingDirection(lua_State *L)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float *pfVar4;
  Vector *pVVar5;
  Vector *unaff_ESI;
  Vector *unaff_EDI;
  
  pfVar4 = (float *)luaL_checkudata();
  luaL_checkudata();
  fVar1 = *pfVar4;
  fVar2 = pfVar4[1];
  fVar3 = pfVar4[2];
  Normalize_Vector(unaff_EDI,unaff_ESI);
  pVVar5 = NewVector(L);
  pVVar5->x = fVar1;
  pVVar5->y = fVar2;
  pVVar5->z = fVar3;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetFacingDrection2D  @ 4fc4f985  lines 1041-1046

int __cdecl LuaBindings::GetFacingDrection2D(lua_State *L)

{
  float *pfVar1;
  float *pfVar2;
  Vector *pVVar3;
  float fVar4;
  double dVar5;
  float fVar6;
  
  pfVar1 = (float *)luaL_checkudata();
  pfVar2 = (float *)luaL_checkudata();
  fVar4 = *pfVar2 - *pfVar1;
  fVar6 = pfVar2[2] - pfVar1[2];
  dVar5 = (double)(fVar4 * fVar4 + fVar6 * fVar6);
  libm_sse2_sqrt_precise();
  pVVar3 = NewVector(L);
  pVVar3->x = fVar4 / (float)dVar5;
  pVVar3->y = 0.0;
  pVVar3->z = fVar6 / (float)dVar5;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::Make_RGB  @ 4fc4f5a5  lines 1053-1059

int __cdecl LuaBindings::Make_RGB(lua_State *L)

{
  lua_State *plVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  plVar1 = L;
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
    L = (lua_State *)0x0;
  }
  else {
    L = (lua_State *)luaL_checkinteger();
  }
  uVar3 = lua_type();
  if (0 < (int)uVar3) {
    uVar4 = luaL_checkinteger();
  }
  **(double **)(plVar1 + 8) = (double)(int)(((uVar2 | 0xffffff00) << 8 | (uint)L) << 8 | uVar4);
  plVar1 = plVar1 + 8;
  *(int *)plVar1 = *(int *)plVar1 + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::Make_RGBA  @ 4fc4b738  lines 1061-1068

int __cdecl LuaBindings::Make_RGBA(lua_State *L)

{
  lua_State *plVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint local_8;
  
  plVar1 = L;
  uVar2 = lua_type();
  iVar4 = 0;
  if ((int)uVar2 < 1) {
    L = (lua_State *)0x0;
  }
  else {
    L = (lua_State *)luaL_checkinteger();
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
  **(double **)(plVar1 + 8) = (double)(int)(((iVar4 << 8 | (uint)L) << 8 | local_8) << 8 | uVar2);
  plVar1 = plVar1 + 8;
  *(int *)plVar1 = *(int *)plVar1 + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::FailMission  @ 4fc507d9  lines 1072-1077

int __cdecl LuaBindings::FailMission(lua_State *L)

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
// LuaBindings::SucceedMission  @ 4fc4e28a  lines 1081-1086

int __cdecl LuaBindings::SucceedMission(lua_State *L)

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
// LuaBindings::ChangeSide  @ 4fc4c454  lines 1090-1093

int __cdecl LuaBindings::ChangeSide(lua_State *__formal)

{
  (*misnImport.ChangeSide)();
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::AddScrap  @ 4fc4fc7f  lines 1097-1102

int __cdecl LuaBindings::AddScrap(lua_State *L)

{
  int iVar1;
  int iVar2;
  
  iVar1 = luaL_checkinteger();
  iVar2 = luaL_checkinteger();
  iVar1 = (*misnImport.AddScrap)(iVar1,iVar2);
  **(double **)(L + 8) = (double)iVar1;
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::SetScrap  @ 4fc5081a  lines 1106-1111

int __cdecl LuaBindings::SetScrap(lua_State *L)

{
  int iVar1;
  int iVar2;
  
  iVar1 = luaL_checkinteger();
  iVar2 = luaL_checkinteger();
  iVar1 = (*misnImport.SetScrap)(iVar1,iVar2);
  **(double **)(L + 8) = (double)iVar1;
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetScrap  @ 4fc4acd8  lines 1115-1119

int __cdecl LuaBindings::GetScrap(lua_State *L)

{
  int iVar1;
  
  iVar1 = luaL_checkinteger();
  iVar1 = (*misnImport.GetScrap)(iVar1);
  **(double **)(L + 8) = (double)iVar1;
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::AddMaxScrap  @ 4fc4e2cb  lines 1123-1129

int __cdecl LuaBindings::AddMaxScrap(lua_State *L)

{
  int iVar1;
  int iVar2;
  
  iVar1 = luaL_checkinteger();
  iVar2 = luaL_checkinteger();
  ::AddMaxScrap(iVar1,iVar2);
  iVar1 = (*misnImport.GetMaxScrap)(iVar1);
  **(double **)(L + 8) = (double)iVar1;
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::SetMaxScrap  @ 4fc500c3  lines 1133-1139

int __cdecl LuaBindings::SetMaxScrap(lua_State *L)

{
  int iVar1;
  int iVar2;
  
  iVar1 = luaL_checkinteger();
  iVar2 = luaL_checkinteger();
  ::SetMaxScrap(iVar1,iVar2);
  iVar1 = (*misnImport.GetMaxScrap)(iVar1);
  **(double **)(L + 8) = (double)iVar1;
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetMaxScrap  @ 4fc4e5a5  lines 1143-1147

int __cdecl LuaBindings::GetMaxScrap(lua_State *L)

{
  int iVar1;
  
  iVar1 = luaL_checkinteger();
  iVar1 = (*misnImport.GetMaxScrap)(iVar1);
  **(double **)(L + 8) = (double)iVar1;
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetTime  @ 4fc4fd8e  lines 1151-1154

int __cdecl LuaBindings::GetTime(lua_State *L)

{
  lua_pushnumber();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetTug  @ 4fc5013d  lines 1158-1163

int __cdecl LuaBindings::GetTug(lua_State *L)

{
  int iVar1;
  
  iVar1 = RequireHandle(L,1);
  iVar1 = (*misnImport.GetTug)(iVar1);
  PushHandle(L,iVar1);
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::HasCargo  @ 4fc4e1b7  lines 1167-1171

int __cdecl LuaBindings::HasCargo(lua_State *L)

{
  uint *puVar1;
  bool bVar2;
  int iVar3;
  
  iVar3 = RequireHandle(L,1);
  bVar2 = (*misnImport.HasCargo)(iVar3);
  puVar1 = *(uint **)(L + 8);
  puVar1[1] = 0x7ff7a501;
  *puVar1 = (uint)bVar2;
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetDistance  @ 4fc51f2f  lines 1179-1203

int __cdecl LuaBindings::GetDistance(lua_State *L)

{
  uint uVar1;
  Vector *pVVar2;
  int iVar3;
  char *pcVar4;
  float10 fVar5;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float fVar6;
  int local_10;
  float h1 [2];
  
  local_10 = RequireHandle(L,1);
  uVar1 = luaL_testudata();
  if (uVar1 == 0) {
    pVVar2 = (Vector *)luaL_testudata();
    if (pVVar2 == (Vector *)0x0) {
      iVar3 = lua_isstring();
      if (iVar3 == 0) {
        h1[0] = (float)RequireHandle(L,2);
        (*misnImport.GetDistanceObject)(&local_10,(int *)h1);
        fVar5 = extraout_ST0_00;
      }
      else {
        iVar3 = 0;
        pcVar4 = (char *)lua_tolstring((undefined4 *)0x0);
        uVar1 = lua_type();
        if (0 < (int)uVar1) {
          iVar3 = luaL_checkinteger();
        }
        (*misnImport.GetDistancePath)(&local_10,pcVar4,iVar3);
        fVar5 = extraout_ST0;
      }
      goto LAB_4fc51ff2;
    }
  }
  else {
    pVVar2 = (Vector *)(uVar1 + 0x30);
  }
  fVar6 = ::GetDistance(local_10,*pVVar2);
  fVar5 = (float10)fVar6;
LAB_4fc51ff2:
  h1[0] = (float)fVar5;
  lua_pushnumber();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetNearestObject  @ 4fc4c8a5  lines 1207-1232

int __cdecl LuaBindings::GetNearestObject(lua_State *L)

{
  int iVar1;
  
  iVar1 = RequireHandle(L,1);
  iVar1 = (*misnImport.GetNearestObject)(iVar1);
  PushHandle(L,iVar1);
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetNearestVehicle  @ 4fc4cb2a  lines 1237-1263

int __cdecl LuaBindings::GetNearestVehicle(lua_State *L)

{
  int iVar1;
  char *pcVar2;
  uint uVar3;
  
  iVar1 = lua_isstring();
  if (iVar1 == 0) {
    iVar1 = RequireHandle(L,1);
    iVar1 = (*misnImport.GetNearestVehicleObject)(iVar1);
  }
  else {
    iVar1 = 0;
    pcVar2 = (char *)lua_tolstring((undefined4 *)0x0);
    uVar3 = lua_type();
    if (0 < (int)uVar3) {
      iVar1 = luaL_checkinteger();
    }
    iVar1 = (*misnImport.GetNearestVehiclePath)(pcVar2,iVar1);
  }
  PushHandle(L,iVar1);
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetNearestBuilding  @ 4fc4a46a  lines 1267-1292

int __cdecl LuaBindings::GetNearestBuilding(lua_State *L)

{
  int iVar1;
  
  iVar1 = RequireHandle(L,1);
  iVar1 = (*misnImport.GetNearestBuilding)(iVar1);
  PushHandle(L,iVar1);
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetNearestEnemy  @ 4fc4b802  lines 1297-1331

int __cdecl LuaBindings::GetNearestEnemy(lua_State *L)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  double in_XMM0_Qa;
  
  uVar1 = lua_type();
  iVar2 = RequireHandle(L,1);
  if (uVar1 == 1) {
    iVar3 = lua_toboolean();
    iVar4 = lua_toboolean();
    uVar1 = lua_type();
    if ((int)uVar1 < 1) {
      in_XMM0_Qa = 450.0;
    }
    else {
      luaL_checknumber();
    }
    iVar2 = ::GetNearestEnemy(iVar2,iVar3 != 0,iVar4 != 0,(float)in_XMM0_Qa);
  }
  else {
    iVar2 = (*misnImport.GetNearestEnemy)(iVar2);
  }
  PushHandle(L,iVar2);
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::BuildObject  @ 4fc4e94a  lines 1338-1370

int __cdecl LuaBindings::BuildObject(lua_State *L)

{
  char *pcVar1;
  int iVar2;
  Matrix *pMVar3;
  Vector *pVVar4;
  int iVar5;
  uint uVar6;
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
        iVar5 = RequireHandle(L,3);
        iVar2 = ::BuildObject(pcVar1,iVar2,iVar5);
      }
      else {
        local_8 = (char *)lua_tolstring((undefined4 *)0x0);
        uVar6 = lua_type();
        if (((int)uVar6 < 1) || (iVar5 = luaL_checkinteger(), iVar5 == 0)) {
          iVar2 = ::BuildObject(pcVar1,iVar2,local_8);
        }
        else {
          ::GetPosition(local_8,iVar5,&local_14);
          iVar2 = ::BuildObject(pcVar1,iVar2,&local_14);
        }
      }
    }
    else {
      iVar2 = ::BuildObject(pcVar1,iVar2,pVVar4);
    }
  }
  else {
    iVar2 = ::BuildObject(pcVar1,iVar2,pMVar3);
  }
  PushHandle(L,iVar2);
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::RemoveObject  @ 4fc4d6d4  lines 1374-1378

int __cdecl LuaBindings::RemoveObject(lua_State *L)

{
  int iVar1;
  
  iVar1 = RequireHandle(L,1);
  ::RemoveObject(iVar1);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::GetFirstEmptyGroup  @ 4fc4d9bc  lines 1383-1400

int __cdecl LuaBindings::GetFirstEmptyGroup(lua_State *L)

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
    *(undefined4 *)((int)*(double **)(L + 8) + 4) = 0x7ff7a500;
  }
  else {
    **(double **)(L + 8) = (double)iVar1;
  }
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::SetGroup  @ 4fc50d02  lines 1404-1409

int __cdecl LuaBindings::SetGroup(lua_State *L)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar1 = RequireHandle(L,1);
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
// LuaBindings::Attack  @ 4fc4a2e5  lines 1413-1419

int __cdecl LuaBindings::Attack(lua_State *L)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = 1;
  iVar1 = RequireHandle(L,1);
  iVar2 = RequireHandle(L,2);
  uVar3 = lua_type();
  if (0 < (int)uVar3) {
    iVar4 = luaL_checkinteger();
  }
  ::Attack(iVar1,iVar2,iVar4);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::Service  @ 4fc50a31  lines 1423-1429

int __cdecl LuaBindings::Service(lua_State *L)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = 1;
  iVar1 = RequireHandle(L,1);
  iVar2 = RequireHandle(L,2);
  uVar3 = lua_type();
  if (0 < (int)uVar3) {
    iVar4 = luaL_checkinteger();
  }
  ::Service(iVar1,iVar2,iVar4);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::Goto  @ 4fc4d813  lines 1437-1469

int __cdecl LuaBindings::Goto(lua_State *L)

{
  char *pcVar1;
  char *pcVar2;
  uint uVar3;
  undefined4 *puVar4;
  Vector *pVVar5;
  int iVar6;
  char *pcVar7;
  int unaff_EDI;
  undefined4 *puVar8;
  undefined4 local_54 [12];
  Vector local_24 [2];
  char *local_8;
  
  pcVar7 = (char *)0x1;
  pcVar2 = (char *)RequireHandle(L,1);
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
        iVar6 = RequireHandle(L,2);
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
      pVVar5 = GetVectorFromPath(pVVar5,pcVar7,unaff_EDI);
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
// LuaBindings::Mine  @ 4fc4e3f0  lines 1477-1509

int __cdecl LuaBindings::Mine(lua_State *L)

{
  int iVar1;
  uint uVar2;
  Vector *pVVar3;
  int iVar4;
  int unaff_EDI;
  char *pcVar5;
  Vector local_14;
  char *local_8;
  
  pcVar5 = (char *)0x1;
  iVar1 = RequireHandle(L,1);
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
        iVar4 = RequireHandle(L,2);
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
      pVVar3 = GetVectorFromPath(pVVar3,pcVar5,unaff_EDI);
    }
  }
  else {
    pVVar3 = (Vector *)(uVar2 + 0x30);
  }
  ::Mine(iVar1,pVVar3,(int)pcVar5);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::Follow  @ 4fc4dece  lines 1513-1519

int __cdecl LuaBindings::Follow(lua_State *L)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = 1;
  iVar1 = RequireHandle(L,1);
  iVar2 = RequireHandle(L,2);
  uVar3 = lua_type();
  if (0 < (int)uVar3) {
    iVar4 = luaL_checkinteger();
  }
  ::Follow(iVar1,iVar2,iVar4);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::Defend  @ 4fc52cfe  lines 1523-1528

int __cdecl LuaBindings::Defend(lua_State *L)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = 1;
  iVar1 = RequireHandle(L,1);
  uVar2 = lua_type();
  if (0 < (int)uVar2) {
    iVar3 = luaL_checkinteger();
  }
  ::Defend(iVar1,iVar3);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::Defend2  @ 4fc4eef7  lines 1532-1538

int __cdecl LuaBindings::Defend2(lua_State *L)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = 1;
  iVar1 = RequireHandle(L,1);
  iVar2 = RequireHandle(L,2);
  uVar3 = lua_type();
  if (0 < (int)uVar3) {
    iVar4 = luaL_checkinteger();
  }
  ::Defend2(iVar1,iVar2,iVar4);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::Stop  @ 4fc50036  lines 1542-1547

int __cdecl LuaBindings::Stop(lua_State *L)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = 1;
  iVar1 = RequireHandle(L,1);
  uVar2 = lua_type();
  if (0 < (int)uVar2) {
    iVar3 = luaL_checkinteger();
  }
  ::Stop(iVar1,iVar3);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::Patrol  @ 4fc5411b  lines 1551-1557

int __cdecl LuaBindings::Patrol(lua_State *L)

{
  int iVar1;
  char *pcVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = 1;
  iVar1 = RequireHandle(L,1);
  pcVar2 = (char *)luaL_checklstring((undefined4 *)0x0);
  uVar3 = lua_type();
  if (0 < (int)uVar3) {
    iVar4 = luaL_checkinteger();
  }
  ::Patrol(iVar1,pcVar2,iVar4);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::Retreat  @ 4fc4e79e  lines 1563-1595

int __cdecl LuaBindings::Retreat(lua_State *L)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  float *pfVar4;
  int iVar5;
  int iVar6;
  int unaff_ESI;
  char *unaff_EDI;
  undefined4 *puVar7;
  Vector *pVVar8;
  undefined4 local_64 [12];
  float local_34 [7];
  Vector local_18;
  char *local_c;
  int local_8;
  
  iVar6 = 1;
  iVar1 = RequireHandle(L,1);
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
        iVar5 = RequireHandle(L,2);
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
      pVVar8 = GetVectorFromPath(pVVar8,unaff_EDI,unaff_ESI);
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
// LuaBindings::GetIn  @ 4fc52084  lines 1599-1605

int __cdecl LuaBindings::GetIn(lua_State *L)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = 1;
  iVar1 = RequireHandle(L,1);
  iVar2 = RequireHandle(L,2);
  uVar3 = lua_type();
  if (0 < (int)uVar3) {
    iVar4 = luaL_checkinteger();
  }
  ::GetIn(iVar1,iVar2,iVar4);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::Pickup  @ 4fc4eaa7  lines 1609-1615

int __cdecl LuaBindings::Pickup(lua_State *L)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = 1;
  iVar1 = RequireHandle(L,1);
  iVar2 = RequireHandle(L,2);
  uVar3 = lua_type();
  if (0 < (int)uVar3) {
    iVar4 = luaL_checkinteger();
  }
  ::Pickup(iVar1,iVar2,iVar4);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::Dropoff  @ 4fc4dab9  lines 1623-1656

int __cdecl LuaBindings::Dropoff(lua_State *L)

{
  char *pcVar1;
  uint uVar2;
  undefined4 *puVar3;
  Vector *pVVar4;
  int iVar5;
  char *pcVar6;
  int unaff_EDI;
  undefined4 *puVar7;
  char *pcVar8;
  undefined4 local_54 [12];
  Vector local_24;
  Vector local_14;
  char *local_8;
  
  pcVar6 = (char *)0x1;
  pcVar1 = (char *)RequireHandle(L,1);
  local_8 = pcVar1;
  uVar2 = lua_type();
  if (0 < (int)uVar2) {
    pcVar6 = (char *)luaL_checkinteger();
  }
  puVar3 = (undefined4 *)luaL_testudata();
  pcVar8 = local_8;
  if (puVar3 == (undefined4 *)0x0) {
    pVVar4 = (Vector *)luaL_testudata();
    pcVar8 = pcVar1;
    if (pVVar4 == (Vector *)0x0) {
      iVar5 = lua_isstring();
      if (iVar5 == 0) {
        iVar5 = RequireHandle(L,2);
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
      pVVar4 = GetVectorFromPath(pVVar4,pcVar6,unaff_EDI);
    }
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
// LuaBindings::Build  @ 4fc48e3e  lines 1660-1666

int __cdecl LuaBindings::Build(lua_State *L)

{
  int iVar1;
  char *pcVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = 1;
  iVar1 = RequireHandle(L,1);
  pcVar2 = (char *)luaL_checklstring((undefined4 *)0x0);
  uVar3 = lua_type();
  if (0 < (int)uVar3) {
    iVar4 = luaL_checkinteger();
  }
  ::Build(iVar1,pcVar2,iVar4);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::LookAt  @ 4fc53d45  lines 1670-1676

int __cdecl LuaBindings::LookAt(lua_State *L)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = 1;
  iVar1 = RequireHandle(L,1);
  iVar2 = RequireHandle(L,2);
  uVar3 = lua_type();
  if (0 < (int)uVar3) {
    iVar4 = luaL_checkinteger();
  }
  ::LookAt(iVar1,iVar2,iVar4);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::AllLookAt  @ 4fc4971a  lines 1680-1686

int __cdecl LuaBindings::AllLookAt(lua_State *L)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  double in_XMM0_Qa;
  
  iVar3 = 1;
  luaL_checknumber();
  iVar1 = RequireHandle(L,2);
  uVar2 = lua_type();
  if (0 < (int)uVar2) {
    iVar3 = luaL_checkinteger();
  }
  ::AllLookAt((int)in_XMM0_Qa,iVar1,iVar3);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::IsOdf  @ 4fc4f129  lines 1690-1695

int __cdecl LuaBindings::IsOdf(lua_State *L)

{
  uint *puVar1;
  bool bVar2;
  int iVar3;
  char *pcVar4;
  
  iVar3 = RequireHandle(L,1);
  pcVar4 = (char *)luaL_checklstring((undefined4 *)0x0);
  bVar2 = ::IsOdf(iVar3,pcVar4);
  puVar1 = *(uint **)(L + 8);
  *puVar1 = (uint)bVar2;
  puVar1[1] = 0x7ff7a501;
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetRace  @ 4fc4950d  lines 1699-1707

int __cdecl LuaBindings::GetRace(lua_State *L)

{
  char cVar1;
  int iVar2;
  
  iVar2 = RequireHandle(L,1);
  cVar1 = ::GetRace(iVar2);
  if (cVar1 == '\0') {
    *(undefined4 *)(*(int *)(L + 8) + 4) = 0x7ff7a500;
    *(int *)(L + 8) = *(int *)(L + 8) + 8;
  }
  else {
    lua_pushlstring(1);
  }
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetPlayerHandle  @ 4fc502ae  lines 1712-1725

int __cdecl LuaBindings::GetPlayerHandle(lua_State *L)

{
  int iVar1;
  
  iVar1 = lua_isnumber();
  if (iVar1 == 0) {
    iVar1 = ::GetPlayerHandle();
  }
  else {
    iVar1 = lua_tointegerx((undefined4 *)0x0);
    iVar1 = ::GetPlayerHandle(iVar1);
  }
  PushHandle(L,iVar1);
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::IsAlive  @ 4fc4c042  lines 1729-1733

int __cdecl LuaBindings::IsAlive(lua_State *L)

{
  uint *puVar1;
  bool bVar2;
  int iVar3;
  
  iVar3 = RequireHandle(L,1);
  bVar2 = IsAlive2(iVar3);
  puVar1 = *(uint **)(L + 8);
  *puVar1 = (uint)bVar2;
  puVar1[1] = 0x7ff7a501;
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::IsFlying  @ 4fc4eb46  lines 1737-1741

int __cdecl LuaBindings::IsFlying(lua_State *L)

{
  uint *puVar1;
  bool bVar2;
  int iVar3;
  
  iVar3 = RequireHandle(L,1);
  bVar2 = IsFlying2(iVar3);
  puVar1 = *(uint **)(L + 8);
  *puVar1 = (uint)bVar2;
  puVar1[1] = 0x7ff7a501;
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::IsAliveAndPilot  @ 4fc53e10  lines 1745-1749

int __cdecl LuaBindings::IsAliveAndPilot(lua_State *L)

{
  uint *puVar1;
  bool bVar2;
  int iVar3;
  
  iVar3 = RequireHandle(L,1);
  bVar2 = IsAliveAndPilot2(iVar3);
  puVar1 = *(uint **)(L + 8);
  *puVar1 = (uint)bVar2;
  puVar1[1] = 0x7ff7a501;
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::IsAround  @ 4fc4dc7e  lines 1753-1757

int __cdecl LuaBindings::IsAround(lua_State *L)

{
  uint *puVar1;
  bool bVar2;
  int iVar3;
  
  iVar3 = RequireHandle(L,1);
  bVar2 = ::IsAround(iVar3);
  puVar1 = *(uint **)(L + 8);
  *puVar1 = (uint)bVar2;
  puVar1[1] = 0x7ff7a501;
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::InBuilding  @ 4fc4cefb  lines 1761-1773

int __cdecl LuaBindings::InBuilding(lua_State *L)

{
  int iVar1;
  int iVar2;
  undefined4 in_XMM0_Da;
  undefined4 in_XMM0_Db;
  
  iVar1 = RequireHandle(L,1);
  iVar2 = lua_isnumber();
  if (iVar2 == 0) {
    iVar1 = ::InBuilding(iVar1);
  }
  else {
    lua_tonumberx((undefined4 *)0x0);
    iVar1 = InBuildingHeight(iVar1,(float)(double)CONCAT44(in_XMM0_Db,in_XMM0_Da));
  }
  PushHandle(L,iVar1);
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::AtTerminal  @ 4fc53f2e  lines 1777-1781

int __cdecl LuaBindings::AtTerminal(lua_State *L)

{
  int iVar1;
  
  iVar1 = RequireHandle(L,1);
  iVar1 = ::AtTerminal(iVar1);
  PushHandle(L,iVar1);
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetPosition  @ 4fc4ee2b  lines 1786-1799

int __cdecl LuaBindings::GetPosition(lua_State *L)

{
  int iVar1;
  char *pcVar2;
  uint uVar3;
  Vector *pVVar4;
  Vector *pVVar5;
  Vector local_1c;
  Vector local_10;
  
  iVar1 = lua_isstring();
  if (iVar1 == 0) {
    iVar1 = RequireHandle(L,1);
    ::GetPosition(iVar1,&local_1c);
    local_10.x = local_1c.x;
    local_10.y = local_1c.y;
    local_10.z = local_1c.z;
    pVVar4 = NewVector(L);
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
    pVVar4 = NewVector(L);
    pVVar5 = &local_1c;
  }
  pVVar4->x = pVVar5->x;
  pVVar4->y = pVVar5->y;
  pVVar4->z = pVVar5->z;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetPosition2  @ 4fc51193  lines 1803-1807

int __cdecl LuaBindings::GetPosition2(lua_State *L)

{
  int iVar1;
  Vector *pVVar2;
  
  iVar1 = RequireHandle(L,1);
  pVVar2 = NewVector(L);
  ::GetPosition2(iVar1,pVVar2);
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetFront  @ 4fc53afa  lines 1811-1815

int __cdecl LuaBindings::GetFront(lua_State *L)

{
  int iVar1;
  Vector *pVVar2;
  Vector local_10;
  
  iVar1 = RequireHandle(L,1);
  ::GetFront(iVar1,&local_10);
  pVVar2 = NewVector(L);
  pVVar2->x = local_10.x;
  pVVar2->y = local_10.y;
  pVVar2->z = local_10.z;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::SetPosition  @ 4fc4f4f3  lines 1822-1849

int __cdecl LuaBindings::SetPosition(lua_State *L)

{
  int iVar1;
  Vector *pVVar2;
  int iVar3;
  char *pcVar4;
  uint uVar5;
  int unaff_ESI;
  char *unaff_EDI;
  Vector local_10;
  
  iVar1 = RequireHandle(L,1);
  pVVar2 = (Vector *)luaL_testudata();
  if (pVVar2 == (Vector *)0x0) {
    iVar3 = lua_isstring();
    if (iVar3 == 0) {
      iVar3 = RequireHandle(L,2);
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
      pVVar2 = GetVectorFromPath(pVVar2,unaff_EDI,unaff_ESI);
    }
  }
  SetVectorPosition(iVar1,*pVVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::Damage  @ 4fc4aacb  lines 1855-1873

int __cdecl LuaBindings::Damage(lua_State *L)

{
  int iVar1;
  int iVar2;
  long lVar3;
  double in_XMM0_Qa;
  
  iVar1 = RequireHandle(L,1);
  iVar2 = lua_isnumber();
  if (iVar2 == 0) {
    luaL_checknumber();
    if (ABS((float)in_XMM0_Qa) <= 2.1474836e+09) {
      ::Damage(iVar1,(int)in_XMM0_Qa);
    }
    else {
      DamageF(iVar1,(float)in_XMM0_Qa);
    }
  }
  else {
    iVar2 = RequireHandle(L,2);
    lVar3 = luaL_checkinteger();
    ::Damage(iVar1,iVar2,lVar3);
  }
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::GetHealth  @ 4fc4f177  lines 1877-1881

int __cdecl LuaBindings::GetHealth(lua_State *L)

{
  int iVar1;
  
  iVar1 = RequireHandle(L,1);
  ::GetHealth(iVar1);
  lua_pushnumber();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetCurHealth  @ 4fc49e83  lines 1885-1893

int __cdecl LuaBindings::GetCurHealth(lua_State *L)

{
  int iVar1;
  long lVar2;
  
  iVar1 = RequireHandle(L,1);
  lVar2 = ::GetCurHealth(iVar1);
  if (lVar2 == -0x4d2) {
    *(undefined4 *)((int)*(double **)(L + 8) + 4) = 0x7ff7a500;
  }
  else {
    **(double **)(L + 8) = (double)lVar2;
  }
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetMaxHealth  @ 4fc509ef  lines 1897-1905

int __cdecl LuaBindings::GetMaxHealth(lua_State *L)

{
  int iVar1;
  long lVar2;
  
  iVar1 = RequireHandle(L,1);
  lVar2 = ::GetMaxHealth(iVar1);
  if (lVar2 == -0x4d2) {
    *(undefined4 *)((int)*(double **)(L + 8) + 4) = 0x7ff7a500;
  }
  else {
    **(double **)(L + 8) = (double)lVar2;
  }
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::SetCurHealth  @ 4fc4ad8e  lines 1909-1914

int __cdecl LuaBindings::SetCurHealth(lua_State *L)

{
  int iVar1;
  long lVar2;
  
  iVar1 = RequireHandle(L,1);
  lVar2 = luaL_checkinteger();
  ::SetCurHealth(iVar1,lVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::SetMaxHealth  @ 4fc50162  lines 1918-1923

int __cdecl LuaBindings::SetMaxHealth(lua_State *L)

{
  int iVar1;
  long lVar2;
  
  iVar1 = RequireHandle(L,1);
  lVar2 = luaL_checkinteger();
  ::SetMaxHealth(iVar1,lVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::AddHealth  @ 4fc4f859  lines 1927-1932

int __cdecl LuaBindings::AddHealth(lua_State *L)

{
  int iVar1;
  long lVar2;
  
  iVar1 = RequireHandle(L,1);
  lVar2 = luaL_checkinteger();
  ::AddHealth(iVar1,lVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::GetAmmo  @ 4fc4fa46  lines 1936-1940

int __cdecl LuaBindings::GetAmmo(lua_State *L)

{
  int iVar1;
  
  iVar1 = RequireHandle(L,1);
  ::GetAmmo(iVar1);
  lua_pushnumber();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetCurAmmo  @ 4fc4f7e0  lines 1944-1952

int __cdecl LuaBindings::GetCurAmmo(lua_State *L)

{
  int iVar1;
  long lVar2;
  
  iVar1 = RequireHandle(L,1);
  lVar2 = ::GetCurAmmo(iVar1);
  if (lVar2 == -0x4d2) {
    *(undefined4 *)((int)*(double **)(L + 8) + 4) = 0x7ff7a500;
  }
  else {
    **(double **)(L + 8) = (double)lVar2;
  }
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetMaxAmmo  @ 4fc5218c  lines 1956-1964

int __cdecl LuaBindings::GetMaxAmmo(lua_State *L)

{
  int iVar1;
  long lVar2;
  
  iVar1 = RequireHandle(L,1);
  lVar2 = ::GetMaxAmmo(iVar1);
  if (lVar2 == -0x4d2) {
    *(undefined4 *)((int)*(double **)(L + 8) + 4) = 0x7ff7a500;
  }
  else {
    **(double **)(L + 8) = (double)lVar2;
  }
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::SetCurAmmo  @ 4fc4c074  lines 1968-1973

int __cdecl LuaBindings::SetCurAmmo(lua_State *L)

{
  int iVar1;
  long lVar2;
  
  iVar1 = RequireHandle(L,1);
  lVar2 = luaL_checkinteger();
  ::SetCurAmmo(iVar1,lVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::SetMaxAmmo  @ 4fc541b1  lines 1977-1982

int __cdecl LuaBindings::SetMaxAmmo(lua_State *L)

{
  int iVar1;
  long lVar2;
  
  iVar1 = RequireHandle(L,1);
  lVar2 = luaL_checkinteger();
  ::SetMaxAmmo(iVar1,lVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::AddAmmo  @ 4fc539c5  lines 1986-1991

int __cdecl LuaBindings::AddAmmo(lua_State *L)

{
  int iVar1;
  long lVar2;
  
  iVar1 = RequireHandle(L,1);
  lVar2 = luaL_checkinteger();
  ::AddAmmo(iVar1,lVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::GetTeamNum  @ 4fc4976f  lines 1995-1999

int __cdecl LuaBindings::GetTeamNum(lua_State *L)

{
  int iVar1;
  
  iVar1 = RequireHandle(L,1);
  iVar1 = ::GetTeamNum(iVar1);
  **(double **)(L + 8) = (double)iVar1;
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::SetTeamNum  @ 4fc52e2d  lines 2003-2008

int __cdecl LuaBindings::SetTeamNum(lua_State *L)

{
  int iVar1;
  int iVar2;
  
  iVar1 = RequireHandle(L,1);
  iVar2 = luaL_checkinteger();
  ::SetTeamNum(iVar1,iVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::SetVelocity  @ 4fc52a09  lines 2012-2018

int __cdecl LuaBindings::SetVelocity(lua_State *L)

{
  int iVar1;
  Vector *pVVar2;
  
  iVar1 = RequireHandle(L,1);
  pVVar2 = (Vector *)luaL_checkudata();
  ::SetVelocity(iVar1,pVVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::SetControls  @ 4fc51618  lines 2022-2121

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl LuaBindings::SetControls(lua_State *L)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  ulong uVar5;
  float in_XMM0_Da;
  undefined4 in_XMM0_Db;
  VehicleControls local_24;
  uint local_c;
  
  local_c = __security_cookie ^ (uint)&local_24;
  iVar1 = RequireHandle(L,1);
  uVar5 = 0;
  uVar2 = lua_type();
  if (uVar2 != 5) goto LAB_4fc51912;
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
LAB_4fc5179c:
    uVar5 = uVar5 | 0x10;
  }
  else {
    iVar3 = lua_isnumber();
    if (iVar3 != 0) {
      lua_tonumberx((undefined4 *)0x0);
      local_24.jump = (char)(int)(double)CONCAT44(in_XMM0_Db,in_XMM0_Da);
      goto LAB_4fc5179c;
    }
  }
  lua_settop();
  lua_getfield();
  uVar2 = lua_type();
  if (uVar2 == 1) {
    uVar4 = lua_toboolean();
    local_24.deploy = (char)uVar4;
LAB_4fc517f3:
    uVar5 = uVar5 | 0x20;
  }
  else {
    iVar3 = lua_isnumber();
    if (iVar3 != 0) {
      lua_tonumberx((undefined4 *)0x0);
      local_24.deploy = (char)(int)(double)CONCAT44(in_XMM0_Db,in_XMM0_Da);
      goto LAB_4fc517f3;
    }
  }
  lua_settop();
  lua_getfield();
  uVar2 = lua_type();
  if (uVar2 == 1) {
    uVar4 = lua_toboolean();
    local_24.eject = (char)uVar4;
LAB_4fc5184a:
    uVar5 = uVar5 | 0x40;
  }
  else {
    iVar3 = lua_isnumber();
    if (iVar3 != 0) {
      lua_tonumberx((undefined4 *)0x0);
      local_24.eject = (char)(int)(double)CONCAT44(in_XMM0_Db,in_XMM0_Da);
      goto LAB_4fc5184a;
    }
  }
  lua_settop();
  lua_getfield();
  uVar2 = lua_type();
  if (uVar2 == 1) {
    uVar4 = lua_toboolean();
    local_24.abandon = (char)uVar4;
LAB_4fc518a7:
    uVar5 = uVar5 | 0x80;
  }
  else {
    iVar3 = lua_isnumber();
    if (iVar3 != 0) {
      lua_tonumberx((undefined4 *)0x0);
      local_24.abandon = (char)(int)(double)CONCAT44(in_XMM0_Db,in_XMM0_Da);
      goto LAB_4fc518a7;
    }
  }
  lua_settop();
  lua_getfield();
  uVar2 = lua_type();
  if (uVar2 == 1) {
    uVar4 = lua_toboolean();
    local_24.fire = (char)uVar4;
LAB_4fc51904:
    uVar5 = uVar5 | 0x100;
  }
  else {
    iVar3 = lua_isnumber();
    if (iVar3 != 0) {
      lua_tonumberx((undefined4 *)0x0);
      local_24.fire = (char)(int)(double)CONCAT44(in_XMM0_Db,in_XMM0_Da);
      goto LAB_4fc51904;
    }
  }
  lua_settop();
LAB_4fc51912:
  ::SetControls(iVar1,&local_24,uVar5);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::GetWhoShotMe  @ 4fc541dc  lines 2125-2129

int __cdecl LuaBindings::GetWhoShotMe(lua_State *L)

{
  int iVar1;
  
  iVar1 = RequireHandle(L,1);
  iVar1 = ::GetWhoShotMe(iVar1);
  PushHandle(L,iVar1);
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetLastEnemyShot  @ 4fc49ac5  lines 2133-2137

int __cdecl LuaBindings::GetLastEnemyShot(lua_State *L)

{
  int iVar1;
  
  iVar1 = RequireHandle(L,1);
  ::GetLastEnemyShot(iVar1);
  lua_pushnumber();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetLastFriendShot  @ 4fc4b2af  lines 2141-2145

int __cdecl LuaBindings::GetLastFriendShot(lua_State *L)

{
  int iVar1;
  
  iVar1 = RequireHandle(L,1);
  ::GetLastFriendShot(iVar1);
  lua_pushnumber();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::DefaultAllies  @ 4fc51995  lines 2149-2152

int __cdecl LuaBindings::DefaultAllies(lua_State *__formal)

{
  ::DefaultAllies();
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::TeamplayAllies  @ 4fc4a3e3  lines 2156-2159

int __cdecl LuaBindings::TeamplayAllies(lua_State *__formal)

{
  ::TeamplayAllies();
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::Ally  @ 4fc4b007  lines 2163-2168

int __cdecl LuaBindings::Ally(lua_State *L)

{
  int iVar1;
  int iVar2;
  
  iVar1 = luaL_checkinteger();
  iVar2 = luaL_checkinteger();
  ::Ally(iVar1,iVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::UnAlly  @ 4fc51936  lines 2172-2177

int __cdecl LuaBindings::UnAlly(lua_State *L)

{
  int iVar1;
  int iVar2;
  
  iVar1 = luaL_checkinteger();
  iVar2 = luaL_checkinteger();
  ::UnAlly(iVar1,iVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::IsTeamAllied  @ 4fc511e2  lines 2181-2186

int __cdecl LuaBindings::IsTeamAllied(lua_State *L)

{
  uint *puVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = luaL_checkinteger();
  iVar4 = luaL_checkinteger();
  bVar2 = ::IsTeamAllied(iVar3,iVar4);
  puVar1 = *(uint **)(L + 8);
  *puVar1 = (uint)bVar2;
  puVar1[1] = 0x7ff7a501;
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::IsAlly  @ 4fc50734  lines 2190-2195

int __cdecl LuaBindings::IsAlly(lua_State *L)

{
  uint *puVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = RequireHandle(L,1);
  iVar4 = RequireHandle(L,2);
  bVar2 = ::IsAlly(iVar3,iVar4);
  puVar1 = *(uint **)(L + 8);
  *puVar1 = (uint)bVar2;
  puVar1[1] = 0x7ff7a501;
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::AudioMessage  @ 4fc4b8ce  lines 2199-2203

int __cdecl LuaBindings::AudioMessage(lua_State *L)

{
  char *pcVar1;
  int iVar2;
  
  pcVar1 = (char *)luaL_checklstring((undefined4 *)0x0);
  iVar2 = ::AudioMessage(pcVar1,false);
  **(double **)(L + 8) = (double)iVar2;
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::IsAudioMessageDone  @ 4fc49bc4  lines 2207-2211

int __cdecl LuaBindings::IsAudioMessageDone(lua_State *L)

{
  uint *puVar1;
  bool bVar2;
  int iVar3;
  
  iVar3 = luaL_checkinteger();
  bVar2 = ::IsAudioMessageDone(iVar3);
  puVar1 = *(uint **)(L + 8);
  *puVar1 = (uint)bVar2;
  puVar1[1] = 0x7ff7a501;
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::StopAudioMessage  @ 4fc4f884  lines 2215-2219

int __cdecl LuaBindings::StopAudioMessage(lua_State *L)

{
  int iVar1;
  
  iVar1 = luaL_checkinteger();
  ::StopAudioMessage(iVar1);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::PreloadAudioMessage  @ 4fc524f9  lines 2223-2227

int __cdecl LuaBindings::PreloadAudioMessage(lua_State *L)

{
  char *pcVar1;
  
  pcVar1 = (char *)luaL_checklstring((undefined4 *)0x0);
  ::PreloadAudioMessage(pcVar1);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::PurgeAudioMessage  @ 4fc4a901  lines 2231-2235

int __cdecl LuaBindings::PurgeAudioMessage(lua_State *L)

{
  char *pcVar1;
  
  pcVar1 = (char *)luaL_checklstring((undefined4 *)0x0);
  ::PurgeAudioMessage(pcVar1);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::PreloadMusicMessage  @ 4fc500a6  lines 2239-2243

int __cdecl LuaBindings::PreloadMusicMessage(lua_State *L)

{
  char *pcVar1;
  
  pcVar1 = (char *)luaL_checklstring((undefined4 *)0x0);
  ::PreloadMusicMessage(pcVar1);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::PurgeMusicMessage  @ 4fc4bc3f  lines 2247-2251

int __cdecl LuaBindings::PurgeMusicMessage(lua_State *L)

{
  char *pcVar1;
  
  pcVar1 = (char *)luaL_checklstring((undefined4 *)0x0);
  ::PurgeMusicMessage(pcVar1);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::LoadJukeFile  @ 4fc54260  lines 2255-2259

int __cdecl LuaBindings::LoadJukeFile(lua_State *L)

{
  char *pcVar1;
  
  pcVar1 = (char *)luaL_checklstring((undefined4 *)0x0);
  ::LoadJukeFile(pcVar1);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::SetMusicIntensity  @ 4fc4f794  lines 2263-2267

int __cdecl LuaBindings::SetMusicIntensity(lua_State *L)

{
  int iVar1;
  
  iVar1 = luaL_checkinteger();
  ::SetMusicIntensity(iVar1);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::GetAiPaths  @ 4fc53346  lines 2310-2322

int __cdecl LuaBindings::GetAiPaths(lua_State *L)

{
  int iVar1;
  char **paths;
  int count;
  
  ::GetAiPaths(&count,&paths);
  iVar1 = 0;
  lua_createtable(0);
  if (0 < count) {
    do {
      lua_pushstring();
      iVar1 = iVar1 + 1;
      lua_rawseti(iVar1);
    } while (iVar1 < count);
  }
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::SetPathType  @ 4fc54532  lines 2326-2331

int __cdecl LuaBindings::SetPathType(lua_State *L)

{
  char *pcVar1;
  PathType PVar2;
  
  pcVar1 = (char *)luaL_checklstring((undefined4 *)0x0);
  PVar2 = luaL_checkinteger();
  ::SetPathType(pcVar1,PVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::SetPathOneWay  @ 4fc4e119  lines 2335-2339

int __cdecl LuaBindings::SetPathOneWay(lua_State *L)

{
  char *pcVar1;
  
  pcVar1 = (char *)luaL_checklstring((undefined4 *)0x0);
  ::SetPathType(pcVar1,ONE_WAY_PATH);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::SetPathRoundTrip  @ 4fc4e004  lines 2341-2345

int __cdecl LuaBindings::SetPathRoundTrip(lua_State *L)

{
  char *pcVar1;
  
  pcVar1 = (char *)luaL_checklstring((undefined4 *)0x0);
  ::SetPathType(pcVar1,ROUND_TRIP_PATH);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::SetPathLoop  @ 4fc4e213  lines 2347-2351

int __cdecl LuaBindings::SetPathLoop(lua_State *L)

{
  char *pcVar1;
  
  pcVar1 = (char *)luaL_checklstring((undefined4 *)0x0);
  ::SetPathType(pcVar1,LOOP_PATH);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::SetIndependence  @ 4fc53de5  lines 2355-2360

int __cdecl LuaBindings::SetIndependence(lua_State *L)

{
  int iVar1;
  int iVar2;
  
  iVar1 = RequireHandle(L,1);
  iVar2 = luaL_checkinteger();
  ::SetIndependence(iVar1,iVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::IsInfo  @ 4fc4cc0d  lines 2365-2377

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl LuaBindings::IsInfo(lua_State *L)

{
  uint *puVar1;
  bool bVar2;
  int iVar3;
  char *pcVar4;
  uint uVar5;
  char local_48 [64];
  uint local_8;
  
  local_8 = __security_cookie ^ (uint)&stack0xfffffffc;
  iVar3 = lua_isstring();
  if (iVar3 == 0) {
    iVar3 = RequireHandle(L,1);
    uVar5 = 0;
    memset(local_48,0,0x40);
    bVar2 = GetODFName(iVar3,local_48);
    if (bVar2) {
      bVar2 = ::IsInfo(local_48);
      uVar5 = (uint)bVar2;
    }
    puVar1 = *(uint **)(L + 8);
    *puVar1 = uVar5;
    puVar1[1] = 0x7ff7a501;
  }
  else {
    pcVar4 = (char *)lua_tolstring((undefined4 *)0x0);
    bVar2 = ::IsInfo(pcVar4);
    puVar1 = *(uint **)(L + 8);
    *puVar1 = (uint)bVar2;
    puVar1[1] = 0x7ff7a501;
  }
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::StartCockpitTimer  @ 4fc4b377  lines 2381-2387

int __cdecl LuaBindings::StartCockpitTimer(lua_State *L)

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
// LuaBindings::StartCockpitTimerUp  @ 4fc4ea3e  lines 2391-2397

int __cdecl LuaBindings::StartCockpitTimerUp(lua_State *L)

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
// LuaBindings::StopCockpitTimer  @ 4fc53894  lines 2401-2404

int __cdecl LuaBindings::StopCockpitTimer(lua_State *__formal)

{
  ::StopCockpitTimer();
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::HideCockpitTimer  @ 4fc4a5b8  lines 2408-2411

int __cdecl LuaBindings::HideCockpitTimer(lua_State *__formal)

{
  ::HideCockpitTimer();
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::GetCockpitTimer  @ 4fc4c9f7  lines 2415-2419

int __cdecl LuaBindings::GetCockpitTimer(lua_State *L)

{
  double *pdVar1;
  long lVar2;
  
  lVar2 = ::GetCockpitTimer();
  pdVar1 = *(double **)(L + 8);
  *pdVar1 = (double)lVar2;
  *(double **)(L + 8) = pdVar1 + 1;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::StartEarthQuake  @ 4fc52bc8  lines 2423-2427

int __cdecl LuaBindings::StartEarthQuake(lua_State *L)

{
  undefined4 in_XMM0_Da;
  undefined4 in_XMM0_Db;
  
  luaL_checknumber();
  ::StartEarthQuake((float)(double)CONCAT44(in_XMM0_Db,in_XMM0_Da));
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::UpdateEarthQuake  @ 4fc4d5df  lines 2431-2435

int __cdecl LuaBindings::UpdateEarthQuake(lua_State *L)

{
  undefined4 in_XMM0_Da;
  undefined4 in_XMM0_Db;
  
  luaL_checknumber();
  ::UpdateEarthQuake((float)(double)CONCAT44(in_XMM0_Db,in_XMM0_Da));
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::StopEarthQuake  @ 4fc53d98  lines 2439-2442

int __cdecl LuaBindings::StopEarthQuake(lua_State *__formal)

{
  ::StopEarthQuake();
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::IsPerson  @ 4fc496e8  lines 2446-2450

int __cdecl LuaBindings::IsPerson(lua_State *L)

{
  uint *puVar1;
  bool bVar2;
  int iVar3;
  
  iVar3 = RequireHandle(L,1);
  bVar2 = ::IsPerson(iVar3);
  puVar1 = *(uint **)(L + 8);
  *puVar1 = (uint)bVar2;
  puVar1[1] = 0x7ff7a501;
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetCurWorld  @ 4fc4b04f  lines 2454-2457

int __cdecl LuaBindings::GetCurWorld(lua_State *L)

{
  ::GetCurWorld();
  lua_pushnumber();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetVarItemStr  @ 4fc5079a  lines 2461-2469

int __cdecl LuaBindings::GetVarItemStr(lua_State *L)

{
  char *pcVar1;
  
  pcVar1 = (char *)luaL_checklstring((undefined4 *)0x0);
  pcVar1 = ::GetVarItemStr(pcVar1);
  if (pcVar1 == (char *)0x0) {
    *(undefined4 *)(*(int *)(L + 8) + 4) = 0x7ff7a500;
    *(int *)(L + 8) = *(int *)(L + 8) + 8;
  }
  else {
    lua_pushstring();
  }
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetVarItemInt  @ 4fc4ad0a  lines 2473-2477

int __cdecl LuaBindings::GetVarItemInt(lua_State *L)

{
  char *pcVar1;
  
  pcVar1 = (char *)luaL_checklstring((undefined4 *)0x0);
  ::GetVarItemInt(pcVar1);
  lua_pushnumber();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetCVarItemInt  @ 4fc51431  lines 2481-2486

int __cdecl LuaBindings::GetCVarItemInt(lua_State *L)

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
// LuaBindings::GetCVarItemStr  @ 4fc4e914  lines 2490-2495

int __cdecl LuaBindings::GetCVarItemStr(lua_State *L)

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
// LuaBindings::PreloadODF  @ 4fc4983b  lines 2499-2503

int __cdecl LuaBindings::PreloadODF(lua_State *L)

{
  char *pcVar1;
  
  pcVar1 = (char *)luaL_checklstring((undefined4 *)0x0);
  ::PreloadODF(pcVar1);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::TerrainFindFloor  @ 4fc4dcf9  lines 2512-2541

int __cdecl LuaBindings::TerrainFindFloor(lua_State *L)

{
  double dVar1;
  Vector pos;
  undefined4 *puVar2;
  Vector *pVVar3;
  uint uVar4;
  int iVar5;
  int unaff_ESI;
  char *unaff_EDI;
  undefined4 *puVar6;
  undefined4 in_XMM0_Da;
  float fVar7;
  undefined4 in_XMM0_Db;
  float local_68;
  float local_60;
  Vector local_54;
  undefined4 local_48 [12];
  float local_18;
  float local_10;
  
  puVar2 = (undefined4 *)luaL_testudata();
  if (puVar2 == (undefined4 *)0x0) {
    pVVar3 = (Vector *)luaL_testudata();
    if (pVVar3 == (Vector *)0x0) {
      uVar4 = luaL_testudata();
      if (uVar4 == 0) {
        iVar5 = lua_isnumber();
        if (iVar5 == 0) {
          iVar5 = lua_isstring();
          if (iVar5 == 0) {
            return 1;
          }
          pVVar3 = (Vector *)0x0;
          lua_tolstring((undefined4 *)0x0);
          uVar4 = lua_type();
          if (0 < (int)uVar4) {
            pVVar3 = (Vector *)luaL_checkinteger();
          }
          GetVectorFromPath(pVVar3,unaff_EDI,unaff_ESI);
          ::TerrainFindFloor(local_68,local_60);
        }
        else {
          lua_tonumberx((undefined4 *)0x0);
          dVar1 = (double)CONCAT44(in_XMM0_Db,in_XMM0_Da);
          fVar7 = (float)dVar1;
          luaL_checknumber();
          ::TerrainFindFloor((float)dVar1,(float)(double)CONCAT44(in_XMM0_Db,fVar7));
        }
      }
      else {
        ::GetPosition(uVar4,&local_54);
        pos.y = local_54.y;
        pos.x = local_54.x;
        pos.z = local_54.z;
        ::TerrainFindFloor(pos);
      }
    }
    else {
      ::TerrainFindFloor(*pVVar3);
    }
  }
  else {
    puVar6 = local_48;
    for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar6 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar6 = puVar6 + 1;
    }
    ::TerrainFindFloor(local_18,local_10);
  }
  lua_pushnumber();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::AddPilotByHandle  @ 4fc4dc64  lines 2545-2549

int __cdecl LuaBindings::AddPilotByHandle(lua_State *L)

{
  int iVar1;
  
  iVar1 = RequireHandle(L,1);
  ::AddPilotByHandle(iVar1);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::PrintConsoleMessage  @ 4fc52010  lines 2553-2557

int __cdecl LuaBindings::PrintConsoleMessage(lua_State *L)

{
  char *pcVar1;
  
  pcVar1 = (char *)luaL_checklstring((undefined4 *)0x0);
  ::PrintConsoleMessage(pcVar1);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::GetRandomFloat  @ 4fc5315c  lines 2562-2574

int __cdecl LuaBindings::GetRandomFloat(lua_State *L)

{
  int iVar1;
  undefined4 in_XMM0_Da;
  float Min;
  float fVar2;
  undefined4 in_XMM0_Db;
  
  luaL_checknumber();
  Min = (float)(double)CONCAT44(in_XMM0_Db,in_XMM0_Da);
  fVar2 = Min;
  iVar1 = lua_isnumber();
  if (iVar1 == 0) {
    ::GetRandomFloat(Min);
  }
  else {
    lua_tonumberx((undefined4 *)0x0);
    ::GetRandomFloat(Min,(float)(double)CONCAT44(in_XMM0_Db,fVar2));
  }
  lua_pushnumber();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::IsDeployed  @ 4fc502ed  lines 2578-2582

int __cdecl LuaBindings::IsDeployed(lua_State *L)

{
  uint *puVar1;
  bool bVar2;
  int iVar3;
  
  iVar3 = RequireHandle(L,1);
  bVar2 = ::IsDeployed(iVar3);
  puVar1 = *(uint **)(L + 8);
  *puVar1 = (uint)bVar2;
  puVar1[1] = 0x7ff7a501;
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::Deploy  @ 4fc4ba99  lines 2586-2590

int __cdecl LuaBindings::Deploy(lua_State *L)

{
  int iVar1;
  
  iVar1 = RequireHandle(L,1);
  ::Deploy(iVar1);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::IsSelected  @ 4fc537fb  lines 2594-2598

int __cdecl LuaBindings::IsSelected(lua_State *L)

{
  uint *puVar1;
  bool bVar2;
  int iVar3;
  
  iVar3 = RequireHandle(L,1);
  bVar2 = ::IsSelected(iVar3);
  puVar1 = *(uint **)(L + 8);
  *puVar1 = (uint)bVar2;
  puVar1[1] = 0x7ff7a501;
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::SetWeaponMask  @ 4fc4fdae  lines 2602-2607

int __cdecl LuaBindings::SetWeaponMask(lua_State *L)

{
  int iVar1;
  long lVar2;
  
  iVar1 = RequireHandle(L,1);
  lVar2 = luaL_checkinteger();
  ::SetWeaponMask(iVar1,lVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::GiveWeapon  @ 4fc5031f  lines 2612-2621

int __cdecl LuaBindings::GiveWeapon(lua_State *L)

{
  int iVar1;
  char *pcVar2;
  uint uVar3;
  int iVar4;
  
  iVar1 = RequireHandle(L,1);
  pcVar2 = (char *)luaL_checklstring((undefined4 *)0x0);
  uVar3 = lua_type();
  if ((0 < (int)uVar3) && (iVar4 = luaL_checkinteger(), -1 < iVar4)) {
    ::GiveWeapon(iVar1,iVar4,pcVar2);
    return 0;
  }
  ::GiveWeapon(iVar1,pcVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::FireAt  @ 4fc4e024  lines 2625-2631

int __cdecl LuaBindings::FireAt(lua_State *L)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  iVar1 = RequireHandle(L,1);
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
// LuaBindings::IsFollowing  @ 4fc4abbe  lines 2636-2643

int __cdecl LuaBindings::IsFollowing(lua_State *L)

{
  uint *puVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  iVar3 = RequireHandle(L,1);
  uVar4 = luaL_testudata();
  if (uVar4 == 0) {
    bVar2 = ::IsFollowing(iVar3);
    puVar1 = *(uint **)(L + 8);
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
    puVar1 = *(uint **)(L + 8);
    *puVar1 = uVar4;
    puVar1[1] = 0x7ff7a501;
  }
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::WhoFollowing  @ 4fc51dac  lines 2647-2651

int __cdecl LuaBindings::WhoFollowing(lua_State *L)

{
  int iVar1;
  
  iVar1 = RequireHandle(L,1);
  iVar1 = ::WhoFollowing(iVar1);
  PushHandle(L,iVar1);
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::SetUserTarget  @ 4fc4a420  lines 2655-2668

int __cdecl LuaBindings::SetUserTarget(lua_State *L)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = lua_type();
  if (uVar1 == 0xffffffff) {
    iVar2 = RequireHandle(L,1);
    ::SetUserTarget(iVar2);
  }
  else {
    iVar2 = luaL_checkinteger();
    iVar3 = RequireHandle(L,2);
    ::SetUserTarget(iVar2,iVar3);
  }
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::GetUserTarget  @ 4fc51eef  lines 2673-2682

int __cdecl LuaBindings::GetUserTarget(lua_State *L)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = lua_type();
  if (0 < (int)uVar1) {
    iVar2 = luaL_checkinteger();
    if (-1 < iVar2) {
      iVar2 = ::GetUserTarget(iVar2);
      goto LAB_4fc51f20;
    }
  }
  iVar2 = ::GetUserTarget();
LAB_4fc51f20:
  PushHandle(L,iVar2);
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::SetPerceivedTeam  @ 4fc5067e  lines 2686-2691

int __cdecl LuaBindings::SetPerceivedTeam(lua_State *L)

{
  int iVar1;
  int iVar2;
  
  iVar1 = RequireHandle(L,1);
  iVar2 = luaL_checkinteger();
  ::SetPerceivedTeam(iVar1,iVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::GetCurrentCommand  @ 4fc4bab3  lines 2695-2699

int __cdecl LuaBindings::GetCurrentCommand(lua_State *L)

{
  int iVar1;
  AiCommand AVar2;
  
  iVar1 = RequireHandle(L,1);
  AVar2 = ::GetCurrentCommand(iVar1);
  **(double **)(L + 8) = (double)(int)AVar2;
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetCurrentWho  @ 4fc4d6ee  lines 2703-2707

int __cdecl LuaBindings::GetCurrentWho(lua_State *L)

{
  int iVar1;
  
  iVar1 = RequireHandle(L,1);
  iVar1 = ::GetCurrentWho(iVar1);
  PushHandle(L,iVar1);
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::EjectPilot  @ 4fc4a685  lines 2711-2715

int __cdecl LuaBindings::EjectPilot(lua_State *L)

{
  int iVar1;
  
  iVar1 = RequireHandle(L,1);
  ::EjectPilot(iVar1);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::HopOut  @ 4fc4c7f6  lines 2719-2723

int __cdecl LuaBindings::HopOut(lua_State *L)

{
  int iVar1;
  
  iVar1 = RequireHandle(L,1);
  ::HopOut(iVar1);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::KillPilot  @ 4fc4b7e8  lines 2727-2731

int __cdecl LuaBindings::KillPilot(lua_State *L)

{
  int iVar1;
  
  iVar1 = RequireHandle(L,1);
  ::KillPilot(iVar1);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::RemovePilot  @ 4fc4ff7d  lines 2735-2739

int __cdecl LuaBindings::RemovePilot(lua_State *L)

{
  int iVar1;
  
  iVar1 = RequireHandle(L,1);
  RemovePilotAI(iVar1);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::HoppedOutOf  @ 4fc4e265  lines 2743-2747

int __cdecl LuaBindings::HoppedOutOf(lua_State *L)

{
  int iVar1;
  
  iVar1 = RequireHandle(L,1);
  iVar1 = ::HoppedOutOf(iVar1);
  PushHandle(L,iVar1);
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetCameraPosition  @ 4fc4c708  lines 2751-2758

int __cdecl LuaBindings::GetCameraPosition(lua_State *L)

{
  Vector *pVVar1;
  Vector dir;
  Vector pos;
  
  pos.x = 0.0;
  pos.y = 0.0;
  pos.z = 0.0;
  dir.x = 0.0;
  dir.y = 0.0;
  dir.z = 0.0;
  ::GetCameraPosition(&pos,&dir);
  pVVar1 = NewVector(L);
  pVVar1->x = pos.x;
  pVVar1->y = pos.y;
  pVVar1->z = pos.z;
  pVVar1 = NewVector(L);
  pVVar1->x = dir.x;
  pVVar1->y = dir.y;
  pVVar1->z = dir.z;
  return 2;
}


// ---------------------------------------------------------------------
// LuaBindings::SetCameraPosition  @ 4fc53f53  lines 2762-2767

int __cdecl LuaBindings::SetCameraPosition(lua_State *L)

{
  Vector *pVVar1;
  Vector *pVVar2;
  
  pVVar1 = (Vector *)luaL_checkudata();
  pVVar2 = (Vector *)luaL_checkudata();
  ::SetCameraPosition(pVVar1,pVVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::ResetCameraPosition  @ 4fc4f1d9  lines 2771-2774

int __cdecl LuaBindings::ResetCameraPosition(lua_State *__formal)

{
  ::ResetCameraPosition();
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::CalcCRC  @ 4fc4a338  lines 2778-2782

int __cdecl LuaBindings::CalcCRC(lua_State *L)

{
  char *pcVar1;
  ulong uVar2;
  
  pcVar1 = (char *)luaL_checklstring((undefined4 *)0x0);
  uVar2 = ::CalcCRC(pcVar1);
  **(double **)(L + 8) = (double)(int)uVar2;
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::IFace_Exec  @ 4fc4b5c0  lines 2787-2799

int __cdecl LuaBindings::IFace_Exec(lua_State *L)

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
// LuaBindings::IFace_Activate  @ 4fc4b032  lines 2802-2806

int __cdecl LuaBindings::IFace_Activate(lua_State *L)

{
  char *pcVar1;
  
  pcVar1 = (char *)luaL_checklstring((undefined4 *)0x0);
  ::IFace_Activate(pcVar1);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::IFace_Deactivate  @ 4fc49b55  lines 2809-2813

int __cdecl LuaBindings::IFace_Deactivate(lua_State *L)

{
  char *pcVar1;
  
  pcVar1 = (char *)luaL_checklstring((undefined4 *)0x0);
  ::IFace_Deactivate(pcVar1);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::IFace_CreateCommand  @ 4fc4fd71  lines 2816-2820

int __cdecl LuaBindings::IFace_CreateCommand(lua_State *L)

{
  char *pcVar1;
  
  pcVar1 = (char *)luaL_checklstring((undefined4 *)0x0);
  ::IFace_CreateCommand(pcVar1);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::IFace_CreateString  @ 4fc4f1a9  lines 2824-2829

int __cdecl LuaBindings::IFace_CreateString(lua_State *L)

{
  char *pcVar1;
  char *pcVar2;
  
  pcVar1 = (char *)luaL_checklstring((undefined4 *)0x0);
  pcVar2 = (char *)luaL_checklstring((undefined4 *)0x0);
  ::IFace_CreateString(pcVar1,pcVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::IFace_SetString  @ 4fc4b590  lines 2833-2838

int __cdecl LuaBindings::IFace_SetString(lua_State *L)

{
  char *pcVar1;
  char *pcVar2;
  
  pcVar1 = (char *)luaL_checklstring((undefined4 *)0x0);
  pcVar2 = (char *)luaL_checklstring((undefined4 *)0x0);
  ::IFace_SetString(pcVar1,pcVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::IFace_GetString  @ 4fc4cf53  lines 2842-2850

/* WARNING: Function: _alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl LuaBindings::IFace_GetString(lua_State *L)

{
  char *pcVar1;
  char acStack_814 [2044];
  undefined4 uStack_18;
  
  uStack_18 = 0x4fc4cf70;
  pcVar1 = (char *)luaL_checklstring((undefined4 *)0x0);
  ::IFace_GetString(pcVar1,acStack_814,0x800);
  lua_pushstring();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::IFace_CreateInteger  @ 4fc5018d  lines 2854-2859

int __cdecl LuaBindings::IFace_CreateInteger(lua_State *L)

{
  char *pcVar1;
  int iVar2;
  
  pcVar1 = (char *)luaL_checklstring((undefined4 *)0x0);
  iVar2 = luaL_checkinteger();
  ::IFace_CreateInteger(pcVar1,iVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::IFace_SetInteger  @ 4fc4bcd8  lines 2863-2868

int __cdecl LuaBindings::IFace_SetInteger(lua_State *L)

{
  char *pcVar1;
  int iVar2;
  
  pcVar1 = (char *)luaL_checklstring((undefined4 *)0x0);
  iVar2 = luaL_checkinteger();
  ::IFace_SetInteger(pcVar1,iVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::IFace_GetInteger  @ 4fc4c791  lines 2872-2876

int __cdecl LuaBindings::IFace_GetInteger(lua_State *L)

{
  char *pcVar1;
  
  pcVar1 = (char *)luaL_checklstring((undefined4 *)0x0);
  ::IFace_GetInteger(pcVar1);
  lua_pushnumber();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::IFace_SetIntegerRange  @ 4fc4e081  lines 2880-2886

int __cdecl LuaBindings::IFace_SetIntegerRange(lua_State *L)

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
// LuaBindings::IFace_CreateFloat  @ 4fc526a2  lines 2890-2895

int __cdecl LuaBindings::IFace_CreateFloat(lua_State *L)

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
// LuaBindings::IFace_SetFloat  @ 4fc54560  lines 2899-2904

int __cdecl LuaBindings::IFace_SetFloat(lua_State *L)

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
// LuaBindings::IFace_GetFloat  @ 4fc5427d  lines 2908-2912

int __cdecl LuaBindings::IFace_GetFloat(lua_State *L)

{
  char *pcVar1;
  
  pcVar1 = (char *)luaL_checklstring((undefined4 *)0x0);
  ::IFace_GetFloat(pcVar1);
  lua_pushnumber();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::IFace_ClearListBox  @ 4fc4a59b  lines 2916-2920

int __cdecl LuaBindings::IFace_ClearListBox(lua_State *L)

{
  char *pcVar1;
  
  pcVar1 = (char *)luaL_checklstring((undefined4 *)0x0);
  ::IFace_ClearListBox(pcVar1);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::IFace_AddTextItem  @ 4fc5010d  lines 2924-2929

int __cdecl LuaBindings::IFace_AddTextItem(lua_State *L)

{
  char *pcVar1;
  char *pcVar2;
  
  pcVar1 = (char *)luaL_checklstring((undefined4 *)0x0);
  pcVar2 = (char *)luaL_checklstring((undefined4 *)0x0);
  ::IFace_AddTextItem(pcVar1,pcVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::IFace_GetSelectedItem  @ 4fc4ab5d  lines 2933-2941

/* WARNING: Function: _alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl LuaBindings::IFace_GetSelectedItem(lua_State *L)

{
  char *pcVar1;
  char acStack_814 [2044];
  undefined4 uStack_18;
  
  uStack_18 = 0x4fc4ab7a;
  pcVar1 = (char *)luaL_checklstring((undefined4 *)0x0);
  ::IFace_GetSelectedItem(pcVar1,acStack_814,0x800);
  lua_pushstring();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::SetSkill  @ 4fc510c7  lines 2945-2950

int __cdecl LuaBindings::SetSkill(lua_State *L)

{
  int iVar1;
  int iVar2;
  
  iVar1 = RequireHandle(L,1);
  iVar2 = luaL_checkinteger();
  ::SetSkill(iVar1,iVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::SetAIP  @ 4fc53700  lines 2954-2959

int __cdecl LuaBindings::SetAIP(lua_State *L)

{
  char *Value;
  uint uVar1;
  int Team;
  
  Value = (char *)luaL_checklstring((undefined4 *)0x0);
  Team = 2;
  uVar1 = lua_type();
  if (0 < (int)uVar1) {
    Team = luaL_checkinteger();
  }
  if (Value != (char *)0x0) {
    BZ1Helper::SetAIPFile(BZ1Helper::m_BZ1Helper,Value,Team);
  }
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::LogFloat  @ 4fc4d32f  lines 2963-2967

int __cdecl LuaBindings::LogFloat(lua_State *L)

{
  undefined4 in_XMM0_Da;
  undefined4 in_XMM0_Db;
  
  luaL_checknumber();
  ::LogFloat((float)(double)CONCAT44(in_XMM0_Db,in_XMM0_Da));
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::GetInstantMyForce  @ 4fc4b8ab  lines 2971-2974

int __cdecl LuaBindings::GetInstantMyForce(lua_State *L)

{
  ::GetInstantMyForce();
  lua_pushnumber();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetInstantCompForce  @ 4fc4dcd6  lines 2977-2980

int __cdecl LuaBindings::GetInstantCompForce(lua_State *L)

{
  ::GetInstantCompForce();
  lua_pushnumber();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetInstantDifficulty  @ 4fc4b715  lines 2983-2986

int __cdecl LuaBindings::GetInstantDifficulty(lua_State *L)

{
  ::GetInstantDifficulty();
  lua_pushnumber();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetInstantGoal  @ 4fc5065b  lines 2989-2992

int __cdecl LuaBindings::GetInstantGoal(lua_State *L)

{
  ::GetInstantGoal();
  lua_pushnumber();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetInstantType  @ 4fc53567  lines 2995-2998

int __cdecl LuaBindings::GetInstantType(lua_State *L)

{
  ::GetInstantType();
  lua_pushnumber();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetInstantFlag  @ 4fc4e512  lines 3001-3004

int __cdecl LuaBindings::GetInstantFlag(lua_State *L)

{
  ::GetInstantFlag();
  lua_pushnumber();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetInstantMySide  @ 4fc53fa6  lines 3007-3010

int __cdecl LuaBindings::GetInstantMySide(lua_State *L)

{
  ::GetInstantMySide();
  lua_pushnumber();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::CameraReady  @ 4fc4f09d  lines 3023-3026

int __cdecl LuaBindings::CameraReady(lua_State *L)

{
  uint *puVar1;
  bool bVar2;
  
  bVar2 = ::CameraReady();
  puVar1 = *(uint **)(L + 8);
  *puVar1 = (uint)bVar2;
  puVar1[1] = 0x7ff7a501;
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::CameraPath  @ 4fc51304  lines 3030-3037

int __cdecl LuaBindings::CameraPath(lua_State *L)

{
  uint *puVar1;
  bool bVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  pcVar3 = (char *)luaL_checklstring((undefined4 *)0x0);
  iVar4 = luaL_checkinteger();
  iVar5 = luaL_checkinteger();
  iVar6 = RequireHandle(L,4);
  bVar2 = ::CameraPath(pcVar3,iVar4,iVar5,iVar6);
  puVar1 = *(uint **)(L + 8);
  *puVar1 = (uint)bVar2;
  puVar1[1] = 0x7ff7a501;
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::CameraPathDir  @ 4fc4b323  lines 3041-3047

int __cdecl LuaBindings::CameraPathDir(lua_State *L)

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
  puVar1 = *(uint **)(L + 8);
  *puVar1 = (uint)bVar2;
  puVar1[1] = 0x7ff7a501;
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::PanDone  @ 4fc4e1ef  lines 3051-3054

int __cdecl LuaBindings::PanDone(lua_State *L)

{
  uint *puVar1;
  bool bVar2;
  
  bVar2 = ::PanDone();
  puVar1 = *(uint **)(L + 8);
  *puVar1 = (uint)bVar2;
  puVar1[1] = 0x7ff7a501;
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::CameraObject  @ 4fc54595  lines 3059-3075

int __cdecl LuaBindings::CameraObject(lua_State *L)

{
  uint *puVar1;
  double dVar2;
  double dVar3;
  bool bVar4;
  int object_handle;
  Vector *pVVar5;
  int iVar6;
  undefined4 in_XMM0_Da;
  float fVar7;
  undefined4 in_XMM0_Db;
  
  object_handle = RequireHandle(L,1);
  pVVar5 = (Vector *)luaL_testudata();
  if (pVVar5 == (Vector *)0x0) {
    luaL_checknumber();
    dVar2 = (double)CONCAT44(in_XMM0_Db,in_XMM0_Da);
    fVar7 = (float)dVar2;
    luaL_checknumber();
    dVar3 = (double)CONCAT44(in_XMM0_Db,fVar7);
    fVar7 = (float)dVar3;
    luaL_checknumber();
    iVar6 = RequireHandle(L,5);
    bVar4 = ::CameraObject(object_handle,(float)dVar2,(float)dVar3,
                           (float)(double)CONCAT44(in_XMM0_Db,fVar7),iVar6);
    puVar1 = *(uint **)(L + 8);
    *puVar1 = (uint)bVar4;
    puVar1[1] = 0x7ff7a501;
  }
  else {
    iVar6 = RequireHandle(L,3);
    bVar4 = ::CameraObject(object_handle,*pVVar5,iVar6);
    puVar1 = *(uint **)(L + 8);
    *puVar1 = (uint)bVar4;
    puVar1[1] = 0x7ff7a501;
  }
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::CameraFinish  @ 4fc50776  lines 3079-3082

int __cdecl LuaBindings::CameraFinish(lua_State *L)

{
  uint *puVar1;
  bool bVar2;
  
  bVar2 = ::CameraFinish();
  puVar1 = *(uint **)(L + 8);
  *puVar1 = (uint)bVar2;
  puVar1[1] = 0x7ff7a501;
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::CameraCancelled  @ 4fc4f426  lines 3086-3089

int __cdecl LuaBindings::CameraCancelled(lua_State *L)

{
  uint *puVar1;
  bool bVar2;
  
  bVar2 = ::CameraCancelled();
  puVar1 = *(uint **)(L + 8);
  *puVar1 = (uint)bVar2;
  puVar1[1] = 0x7ff7a501;
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::FreeCamera  @ 4fc4bc1b  lines 3093-3096

int __cdecl LuaBindings::FreeCamera(lua_State *L)

{
  uint *puVar1;
  bool bVar2;
  
  bVar2 = ::FreeCamera();
  puVar1 = *(uint **)(L + 8);
  *puVar1 = (uint)bVar2;
  puVar1[1] = 0x7ff7a501;
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::FreeFinish  @ 4fc53a62  lines 3100-3103

int __cdecl LuaBindings::FreeFinish(lua_State *L)

{
  uint *puVar1;
  bool bVar2;
  
  bVar2 = ::FreeFinish();
  puVar1 = *(uint **)(L + 8);
  *puVar1 = (uint)bVar2;
  puVar1[1] = 0x7ff7a501;
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::PlayMovie  @ 4fc4e0bf  lines 3107-3111

int __cdecl LuaBindings::PlayMovie(lua_State *L)

{
  uint *puVar1;
  bool bVar2;
  char *pcVar3;
  
  pcVar3 = (char *)luaL_checklstring((undefined4 *)0x0);
  bVar2 = ::PlayMovie(pcVar3);
  puVar1 = *(uint **)(L + 8);
  *puVar1 = (uint)bVar2;
  puVar1[1] = 0x7ff7a501;
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::StopMovie  @ 4fc4cdb0  lines 3115-3118

int __cdecl LuaBindings::StopMovie(lua_State *__formal)

{
  ::StopMovie();
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::PlayMove  @ 4fc52e58  lines 3122-3125

int __cdecl LuaBindings::PlayMove(lua_State *L)

{
  uint *puVar1;
  bool bVar2;
  
  bVar2 = ::PlayMove();
  puVar1 = *(uint **)(L + 8);
  *puVar1 = (uint)bVar2;
  puVar1[1] = 0x7ff7a501;
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::PlayRecording  @ 4fc530e7  lines 3130-3137

int __cdecl LuaBindings::PlayRecording(lua_State *L)

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
    puVar1 = *(uint **)(L + 8);
    *puVar1 = (uint)bVar2;
    puVar1[1] = 0x7ff7a501;
  }
  else {
    bVar2 = ::PlayRecording(pcVar3);
    puVar1 = *(uint **)(L + 8);
    *puVar1 = (uint)bVar2;
    puVar1[1] = 0x7ff7a501;
  }
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::PlaybackVehicle  @ 4fc4d2fa  lines 3141-3145

int __cdecl LuaBindings::PlaybackVehicle(lua_State *L)

{
  uint *puVar1;
  bool bVar2;
  char *pcVar3;
  
  pcVar3 = (char *)luaL_checklstring((undefined4 *)0x0);
  bVar2 = ::PlaybackVehicle(pcVar3);
  puVar1 = *(uint **)(L + 8);
  *puVar1 = (uint)bVar2;
  puVar1[1] = 0x7ff7a501;
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::SetAnimation  @ 4fc4a1fd  lines 3149-3155

int __cdecl LuaBindings::SetAnimation(lua_State *L)

{
  int iVar1;
  char *pcVar2;
  uint uVar3;
  int iVar4;
  
  iVar1 = RequireHandle(L,1);
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
// LuaBindings::GetAnimationFrame  @ 4fc4e5d7  lines 3159-3164

int __cdecl LuaBindings::GetAnimationFrame(lua_State *L)

{
  int iVar1;
  char *pcVar2;
  
  iVar1 = RequireHandle(L,1);
  pcVar2 = (char *)luaL_checklstring((undefined4 *)0x0);
  ::GetAnimationFrame(iVar1,pcVar2);
  lua_pushnumber();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::StartAnimation  @ 4fc4f674  lines 3168-3172

int __cdecl LuaBindings::StartAnimation(lua_State *L)

{
  int iVar1;
  
  iVar1 = RequireHandle(L,1);
  ::StartAnimation(iVar1);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::MaskEmitter  @ 4fc49367  lines 3176-3181

int __cdecl LuaBindings::MaskEmitter(lua_State *L)

{
  int iVar1;
  ulong uVar2;
  
  iVar1 = RequireHandle(L,1);
  uVar2 = luaL_checkinteger();
  ::MaskEmitter(iVar1,uVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::StartEmitter  @ 4fc4a61e  lines 3185-3190

int __cdecl LuaBindings::StartEmitter(lua_State *L)

{
  int iVar1;
  int iVar2;
  
  iVar1 = RequireHandle(L,1);
  iVar2 = luaL_checkinteger();
  ::StartEmitter(iVar1,iVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::StopEmitter  @ 4fc5110a  lines 3194-3199

int __cdecl LuaBindings::StopEmitter(lua_State *L)

{
  int iVar1;
  int iVar2;
  
  iVar1 = RequireHandle(L,1);
  iVar2 = luaL_checkinteger();
  ::StopEmitter(iVar1,iVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::SetObjectiveOn  @ 4fc4e8fa  lines 3232-3236

int __cdecl LuaBindings::SetObjectiveOn(lua_State *L)

{
  int iVar1;
  
  iVar1 = RequireHandle(L,1);
  ::SetObjectiveOn(iVar1);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::SetObjectiveOff  @ 4fc4bd8c  lines 3240-3244

int __cdecl LuaBindings::SetObjectiveOff(lua_State *L)

{
  int iVar1;
  
  iVar1 = RequireHandle(L,1);
  ::SetObjectiveOff(iVar1);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::SetObjectiveName  @ 4fc54690  lines 3248-3253

int __cdecl LuaBindings::SetObjectiveName(lua_State *L)

{
  int iVar1;
  char *pcVar2;
  
  iVar1 = RequireHandle(L,1);
  pcVar2 = (char *)luaL_checklstring((undefined4 *)0x0);
  ::SetObjectiveName(iVar1,pcVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::ClearObjectives  @ 4fc4f822  lines 3257-3260

int __cdecl LuaBindings::ClearObjectives(lua_State *__formal)

{
  ::ClearObjectives();
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::GetColor  @ 4fc48c7b  lines 3264-3286

long __cdecl LuaBindings::GetColor(char *colorname)

{
  uint uVar1;
  char *unaff_retaddr;
  uint in_stack_00000004;
  
  if (colorname != (char *)0x0) {
    uVar1 = Hash(unaff_retaddr,in_stack_00000004);
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
// LuaBindings::AddObjective  @ 4fc4fdd9  lines 3290-3305

int __cdecl LuaBindings::AddObjective(lua_State *L)

{
  char *pcVar1;
  int iVar2;
  char *colorname;
  uint uVar3;
  long lVar4;
  double in_XMM0_Qa;
  
  pcVar1 = (char *)luaL_checklstring((undefined4 *)0x0);
  lVar4 = -1;
  iVar2 = lua_isnumber();
  if (iVar2 == 0) {
    iVar2 = lua_isstring();
    if (iVar2 != 0) {
      colorname = luaL_optlstring("WHITE",(int *)0x0);
      lVar4 = GetColor(colorname);
    }
  }
  else {
    lVar4 = luaL_checkinteger();
  }
  uVar3 = lua_type();
  if ((int)uVar3 < 1) {
    in_XMM0_Qa = 8.0;
  }
  else {
    luaL_checknumber();
  }
  ::AddObjective(pcVar1,lVar4,(float)in_XMM0_Qa);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::IsWithin  @ 4fc4b1ed  lines 3309-3315

int __cdecl LuaBindings::IsWithin(lua_State *L)

{
  uint *puVar1;
  lua_State *L_00;
  bool bVar2;
  undefined4 in_XMM0_Da;
  undefined4 in_XMM0_Db;
  int h1;
  
  L_00 = L;
  h1 = RequireHandle(L,1);
  L = (lua_State *)RequireHandle(L_00,2);
  luaL_checknumber();
  bVar2 = ::IsWithin(&h1,(int *)&L,(float)(double)CONCAT44(in_XMM0_Db,in_XMM0_Da));
  puVar1 = *(uint **)(L_00 + 8);
  *puVar1 = (uint)bVar2;
  puVar1[1] = 0x7ff7a501;
  *(int *)(L_00 + 8) = *(int *)(L_00 + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::CountUnitsNearObject  @ 4fc49deb  lines 3319-3330

int __cdecl LuaBindings::CountUnitsNearObject(lua_State *L)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  double in_XMM0_Qa;
  
  pcVar4 = (char *)0x0;
  iVar3 = 0;
  uVar1 = lua_type();
  if (uVar1 != 0) {
    iVar3 = RequireHandle(L,1);
  }
  luaL_checknumber();
  iVar2 = luaL_checkinteger();
  uVar1 = lua_type();
  if (uVar1 != 0) {
    pcVar4 = (char *)luaL_checklstring((undefined4 *)0x0);
  }
  iVar3 = ::CountUnitsNearObject(iVar3,(float)in_XMM0_Qa,iVar2,pcVar4);
  **(double **)(L + 8) = (double)iVar3;
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::SetAvoidType  @ 4fc4e357  lines 3334-3339

int __cdecl LuaBindings::SetAvoidType(lua_State *L)

{
  int iVar1;
  int iVar2;
  
  iVar1 = RequireHandle(L,1);
  iVar2 = luaL_checkinteger();
  ::SetAvoidType(iVar1,iVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::Annoy  @ 4fc4b6ea  lines 3343-3348

int __cdecl LuaBindings::Annoy(lua_State *L)

{
  int iVar1;
  int iVar2;
  
  iVar1 = RequireHandle(L,1);
  iVar2 = RequireHandle(L,2);
  ::Annoy(iVar1,iVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::ClearThrust  @ 4fc4a26e  lines 3352-3356

int __cdecl LuaBindings::ClearThrust(lua_State *L)

{
  int iVar1;
  
  iVar1 = RequireHandle(L,1);
  ::ClearThrust(iVar1);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::SetVerbose  @ 4fc4fa78  lines 3360-3365

int __cdecl LuaBindings::SetVerbose(lua_State *L)

{
  int iVar1;
  int iVar2;
  
  iVar1 = RequireHandle(L,1);
  iVar2 = lua_toboolean();
  ::SetVerbose(iVar1,iVar2 != 0);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::ClearIdleAnims  @ 4fc530cd  lines 3369-3373

int __cdecl LuaBindings::ClearIdleAnims(lua_State *L)

{
  int iVar1;
  
  iVar1 = RequireHandle(L,1);
  ::ClearIdleAnims(iVar1);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::AddIdleAnim  @ 4fc4c57f  lines 3377-3382

int __cdecl LuaBindings::AddIdleAnim(lua_State *L)

{
  int iVar1;
  char *pcVar2;
  
  iVar1 = RequireHandle(L,1);
  pcVar2 = (char *)luaL_checklstring((undefined4 *)0x0);
  ::AddIdleAnim(iVar1,pcVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::IsIdle  @ 4fc4d4ad  lines 3386-3390

int __cdecl LuaBindings::IsIdle(lua_State *L)

{
  uint *puVar1;
  bool bVar2;
  int iVar3;
  
  iVar3 = RequireHandle(L,1);
  bVar2 = ::IsIdle(iVar3);
  puVar1 = *(uint **)(L + 8);
  *puVar1 = (uint)bVar2;
  puVar1[1] = 0x7ff7a501;
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::CountThreats  @ 4fc4dbed  lines 3394-3401

int __cdecl LuaBindings::CountThreats(lua_State *L)

{
  lua_State *plVar1;
  int iVar2;
  int coming;
  
  plVar1 = L;
  iVar2 = RequireHandle(L,1);
  L = (lua_State *)0x0;
  coming = 0;
  ::CountThreats(iVar2,(int *)&L,&coming);
  **(double **)(plVar1 + 8) = (double)(int)L;
  *(int *)(plVar1 + 8) = *(int *)(plVar1 + 8) + 8;
  **(double **)(plVar1 + 8) = (double)coming;
  *(int *)(plVar1 + 8) = *(int *)(plVar1 + 8) + 8;
  return 2;
}


// ---------------------------------------------------------------------
// LuaBindings::SpawnBirds  @ 4fc4ff97  lines 3406-3423

int __cdecl LuaBindings::SpawnBirds(lua_State *L)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  int iVar7;
  
  iVar1 = luaL_checkinteger();
  iVar2 = luaL_checkinteger();
  pcVar3 = (char *)luaL_checklstring((undefined4 *)0x0);
  iVar4 = luaL_checkinteger();
  iVar5 = lua_isstring();
  if (iVar5 == 0) {
    iVar5 = RequireHandle(L,5);
    iVar7 = RequireHandle(L,6);
    ::SpawnBirds(iVar1,iVar2,pcVar3,iVar4,iVar5,iVar7);
  }
  else {
    pcVar6 = (char *)lua_tolstring((undefined4 *)0x0);
    ::SpawnBirds(iVar1,iVar2,pcVar3,iVar4,pcVar6);
  }
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::RemoveBirds  @ 4fc4aab1  lines 3427-3431

int __cdecl LuaBindings::RemoveBirds(lua_State *L)

{
  int iVar1;
  
  iVar1 = luaL_checkinteger();
  ::RemoveBirds(iVar1);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::SetColorFade  @ 4fc4df60  lines 3435-3445

int __cdecl LuaBindings::SetColorFade(lua_State *L)

{
  double dVar1;
  int iVar2;
  char *colorname;
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
      colorname = luaL_optlstring("LAVACOLOR",(int *)0x0);
      uVar3 = GetColor(colorname);
    }
  }
  else {
    uVar3 = luaL_checkinteger();
  }
  ::SetColorFade((float)dVar1,(float)(double)CONCAT44(in_XMM0_Db,fVar4),uVar3);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::StopCheats  @ 4fc50ab6  lines 3449-3452

int __cdecl LuaBindings::StopCheats(lua_State *__formal)

{
  ::StopCheats();
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::CalcCliffs  @ 4fc4c8ca  lines 3457-3471

int __cdecl LuaBindings::CalcCliffs(lua_State *L)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  undefined4 in_XMM0_Da;
  undefined4 in_XMM0_Db;
  
  iVar1 = lua_isstring();
  if (iVar1 == 0) {
    iVar1 = RequireHandle(L,1);
    iVar3 = RequireHandle(L,2);
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
// LuaBindings::StartSoundEffect  @ 4fc52463  lines 3475-3480

int __cdecl LuaBindings::StartSoundEffect(lua_State *L)

{
  char *pcVar1;
  uint uVar2;
  int iVar3;
  
  pcVar1 = (char *)luaL_checklstring((undefined4 *)0x0);
  uVar2 = luaL_testudata();
  iVar3 = ::StartSoundEffect(pcVar1,uVar2);
  **(double **)(L + 8) = (double)iVar3;
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::FindSoundEffect  @ 4fc512b8  lines 3484-3489

int __cdecl LuaBindings::FindSoundEffect(lua_State *L)

{
  char *pcVar1;
  uint uVar2;
  int iVar3;
  
  pcVar1 = (char *)luaL_checklstring((undefined4 *)0x0);
  uVar2 = luaL_testudata();
  iVar3 = ::FindSoundEffect(pcVar1,uVar2);
  **(double **)(L + 8) = (double)iVar3;
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::StopSoundEffect  @ 4fc4adb9  lines 3493-3497

int __cdecl LuaBindings::StopSoundEffect(lua_State *L)

{
  int iVar1;
  
  iVar1 = luaL_checkinteger();
  ::StopSoundEffect(iVar1);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::GetObjectByTeamSlot  @ 4fc50d70  lines 3502-3517

int __cdecl LuaBindings::GetObjectByTeamSlot(lua_State *L)

{
  int iVar1;
  int iVar2;
  
  iVar1 = lua_isnumber();
  iVar2 = luaL_checkinteger();
  if (iVar1 == 0) {
    iVar1 = iVar2;
    iVar2 = ::GetLocalPlayerTeamNumber();
  }
  else {
    iVar1 = luaL_checkinteger();
  }
  iVar1 = ::GetObjectByTeamSlot(iVar2,iVar1);
  PushHandle(L,iVar1);
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::IsNetworkOn  @ 4fc4a056  lines 3521-3524

int __cdecl LuaBindings::IsNetworkOn(lua_State *L)

{
  uint *puVar1;
  bool bVar2;
  
  bVar2 = ::IsNetworkOn();
  puVar1 = *(uint **)(L + 8);
  *puVar1 = (uint)bVar2;
  puVar1[1] = 0x7ff7a501;
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::ImServer  @ 4fc50abf  lines 3528-3531

int __cdecl LuaBindings::ImServer(lua_State *L)

{
  uint *puVar1;
  bool bVar2;
  
  bVar2 = ::ImServer();
  puVar1 = *(uint **)(L + 8);
  *puVar1 = (uint)bVar2;
  puVar1[1] = 0x7ff7a501;
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::ImDedicatedServer  @ 4fc49551  lines 3535-3538

int __cdecl LuaBindings::ImDedicatedServer(lua_State *L)

{
  uint *puVar1;
  bool bVar2;
  
  bVar2 = ::ImDedicatedServer();
  puVar1 = *(uint **)(L + 8);
  *puVar1 = (uint)bVar2;
  puVar1[1] = 0x7ff7a501;
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::IsTeamplayOn  @ 4fc4ff13  lines 3542-3545

int __cdecl LuaBindings::IsTeamplayOn(lua_State *L)

{
  uint *puVar1;
  bool bVar2;
  
  bVar2 = ::IsTeamplayOn();
  puVar1 = *(uint **)(L + 8);
  *puVar1 = (uint)bVar2;
  puVar1[1] = 0x7ff7a501;
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::CountPlayers  @ 4fc4dcb0  lines 3549-3552

int __cdecl LuaBindings::CountPlayers(lua_State *L)

{
  double *pdVar1;
  int iVar2;
  
  iVar2 = ::CountPlayers();
  pdVar1 = *(double **)(L + 8);
  *pdVar1 = (double)iVar2;
  *(double **)(L + 8) = pdVar1 + 1;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetRaceOfTeam  @ 4fc4f214  lines 3556-3564

int __cdecl LuaBindings::GetRaceOfTeam(lua_State *L)

{
  char cVar1;
  int iVar2;
  
  iVar2 = luaL_checkinteger();
  cVar1 = ::GetRaceOfTeam(iVar2);
  if (cVar1 == '\0') {
    *(undefined4 *)(*(int *)(L + 8) + 4) = 0x7ff7a500;
    *(int *)(L + 8) = *(int *)(L + 8) + 8;
  }
  else {
    lua_pushlstring(1);
  }
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::IsPlayer  @ 4fc4e233  lines 3568-3572

int __cdecl LuaBindings::IsPlayer(lua_State *L)

{
  uint *puVar1;
  bool bVar2;
  int iVar3;
  
  iVar3 = RequireHandle(L,1);
  bVar2 = ::IsPlayer(iVar3);
  puVar1 = *(uint **)(L + 8);
  *puVar1 = (uint)bVar2;
  puVar1[1] = 0x7ff7a501;
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetPlayerName  @ 4fc4faac  lines 3576-3581

int __cdecl LuaBindings::GetPlayerName(lua_State *L)

{
  int iVar1;
  
  iVar1 = RequireHandle(L,1);
  ::GetPlayerName(iVar1);
  lua_pushstring();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::WhichTeamGroup  @ 4fc53efc  lines 3585-3589

int __cdecl LuaBindings::WhichTeamGroup(lua_State *L)

{
  int iVar1;
  
  iVar1 = luaL_checkinteger();
  iVar1 = ::WhichTeamGroup(iVar1);
  **(double **)(L + 8) = (double)iVar1;
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::CountAllies  @ 4fc4f062  lines 3593-3597

int __cdecl LuaBindings::CountAllies(lua_State *L)

{
  int iVar1;
  
  iVar1 = luaL_checkinteger();
  iVar1 = ::CountAllies(iVar1);
  **(double **)(L + 8) = (double)iVar1;
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetCommanderTeam  @ 4fc5085c  lines 3601-3605

int __cdecl LuaBindings::GetCommanderTeam(lua_State *L)

{
  int iVar1;
  
  iVar1 = luaL_checkinteger();
  iVar1 = ::GetCommanderTeam(iVar1);
  **(double **)(L + 8) = (double)iVar1;
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetFirstAlliedTeam  @ 4fc529d7  lines 3609-3613

int __cdecl LuaBindings::GetFirstAlliedTeam(lua_State *L)

{
  int iVar1;
  
  iVar1 = luaL_checkinteger();
  iVar1 = ::GetFirstAlliedTeam(iVar1);
  **(double **)(L + 8) = (double)iVar1;
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetLastAlliedTeam  @ 4fc4e65f  lines 3617-3621

int __cdecl LuaBindings::GetLastAlliedTeam(lua_State *L)

{
  int iVar1;
  
  iVar1 = luaL_checkinteger();
  iVar1 = ::GetLastAlliedTeam(iVar1);
  **(double **)(L + 8) = (double)iVar1;
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetTeamplayRanges  @ 4fc4cb95  lines 3625-3633

int __cdecl LuaBindings::GetTeamplayRanges(lua_State *L)

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
// LuaBindings::SetRandomHeadingAngle  @ 4fc54722  lines 3637-3641

int __cdecl LuaBindings::SetRandomHeadingAngle(lua_State *L)

{
  int iVar1;
  
  iVar1 = RequireHandle(L,1);
  ::SetRandomHeadingAngle(iVar1);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::ClearTeamColors  @ 4fc4df21  lines 3645-3648

int __cdecl LuaBindings::ClearTeamColors(lua_State *__formal)

{
  ::ClearTeamColors();
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::DefaultTeamColors  @ 4fc524af  lines 3652-3655

int __cdecl LuaBindings::DefaultTeamColors(lua_State *__formal)

{
  ::DefaultTeamColors();
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::TeamplayTeamColors  @ 4fc530c4  lines 3659-3662

int __cdecl LuaBindings::TeamplayTeamColors(lua_State *__formal)

{
  ::TeamplayTeamColors();
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::SetTeamColor  @ 4fc5210b  lines 3666-3681

int __cdecl LuaBindings::SetTeamColor(lua_State *L)

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
// LuaBindings::ClearTeamColor  @ 4fc4efe2  lines 3685-3689

int __cdecl LuaBindings::ClearTeamColor(lua_State *L)

{
  int iVar1;
  
  iVar1 = luaL_checkinteger();
  ::ClearTeamColor(iVar1);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::MakeInert  @ 4fc4a1e3  lines 3693-3697

int __cdecl LuaBindings::MakeInert(lua_State *L)

{
  int iVar1;
  
  iVar1 = RequireHandle(L,1);
  ::MakeInert(iVar1);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::GetPositionNear  @ 4fc4bda6  lines 3704-3742

int __cdecl LuaBindings::GetPositionNear(lua_State *L)

{
  Vector VVar1;
  Vector VVar2;
  uint uVar3;
  undefined4 *puVar4;
  Vector *pVVar5;
  Vector *pVVar6;
  int iVar7;
  int unaff_ESI;
  char *unaff_EDI;
  undefined4 *puVar8;
  float fVar9;
  undefined8 uVar10;
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
  double dVar11;
  
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
        iVar7 = RequireHandle(L,1);
        ::GetPosition(iVar7,&local_68);
        VVar2.y = local_68.y;
        VVar2.x = local_68.x;
        VVar2.z = local_68.z;
        ::GetPositionNear(&local_78,VVar2,fVar13,fVar9);
        local_58.x = local_78.x;
        local_58.y = local_78.y;
        local_58.z = local_78.z;
        pVVar5 = NewVector(L);
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
        pVVar6 = GetVectorFromPath(pVVar6,unaff_EDI,unaff_ESI);
        ::GetPositionNear(&local_68,*pVVar6,fVar13,(float)(double)local_78._0_8_);
        local_78.z = local_68.z;
        pVVar5 = NewVector(L);
        pVVar6 = &local_78;
      }
      goto LAB_4fc4c033;
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
  pVVar5 = NewVector(L);
  pVVar6 = &local_68;
LAB_4fc4c033:
  pVVar5->x = pVVar6->x;
  pVVar5->y = pVVar6->y;
  pVVar5->z = pVVar6->z;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetPlayerODF  @ 4fc49149  lines 3746-3752

int __cdecl LuaBindings::GetPlayerODF(lua_State *L)

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
// LuaBindings::BuildEmptyCraftNear  @ 4fc4921c  lines 3756-3764

int __cdecl LuaBindings::BuildEmptyCraftNear(lua_State *L)

{
  double dVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  undefined4 in_XMM0_Da;
  float fVar5;
  undefined4 in_XMM0_Db;
  
  iVar2 = RequireHandle(L,1);
  pcVar3 = (char *)luaL_checklstring((undefined4 *)0x0);
  iVar4 = luaL_checkinteger();
  luaL_checknumber();
  dVar1 = (double)CONCAT44(in_XMM0_Db,in_XMM0_Da);
  fVar5 = (float)dVar1;
  luaL_checknumber();
  iVar2 = ::BuildEmptyCraftNear
                    (iVar2,pcVar3,iVar4,(float)dVar1,(float)(double)CONCAT44(in_XMM0_Db,fVar5));
  PushHandle(L,iVar2);
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetCircularPos  @ 4fc508e1  lines 3768-3777

int __cdecl LuaBindings::GetCircularPos(lua_State *L)

{
  double dVar1;
  Vector *pVVar2;
  uint uVar3;
  int iVar4;
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
    pVVar2 = NewVector(L);
    iVar4 = 1;
    pVVar2->x = local_18;
    pVVar2->y = fStack_14;
    pVVar2->z = fStack_10;
  }
  return iVar4;
}


// ---------------------------------------------------------------------
// LuaBindings::GetSafestSpawnpoint  @ 4fc49335  lines 3781-3784

int __cdecl LuaBindings::GetSafestSpawnpoint(lua_State *L)

{
  Vector *pVVar1;
  Vector local_1c;
  float local_10;
  float fStack_c;
  float fStack_8;
  
  pVVar1 = ::GetSafestSpawnpoint(&local_1c);
  local_10 = pVVar1->x;
  fStack_c = pVVar1->y;
  fStack_8 = pVVar1->z;
  pVVar1 = NewVector(L);
  pVVar1->x = local_10;
  pVVar1->y = fStack_c;
  pVVar1->z = fStack_8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetSpawnpoint  @ 4fc506f5  lines 3788-3792

int __cdecl LuaBindings::GetSpawnpoint(lua_State *L)

{
  int iVar1;
  Vector *pVVar2;
  Vector local_1c;
  float local_10;
  float fStack_c;
  float fStack_8;
  
  iVar1 = luaL_checkinteger();
  pVVar2 = ::GetSpawnpoint(&local_1c,iVar1);
  local_10 = pVVar2->x;
  fStack_c = pVVar2->y;
  fStack_8 = pVVar2->z;
  pVVar2 = NewVector(L);
  pVVar2->x = local_10;
  pVVar2->y = fStack_c;
  pVVar2->z = fStack_8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetSpawnpointHandle  @ 4fc53cee  lines 3796-3800

int __cdecl LuaBindings::GetSpawnpointHandle(lua_State *L)

{
  int iVar1;
  
  iVar1 = luaL_checkinteger();
  iVar1 = ::GetSpawnpointHandle(iVar1);
  PushHandle(L,iVar1);
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetRandomSpawnpoint  @ 4fc5088e  lines 3804-3808

int __cdecl LuaBindings::GetRandomSpawnpoint(lua_State *L)

{
  uint uVar1;
  int iVar2;
  Vector *pVVar3;
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
  pVVar3 = NewVector(L);
  pVVar3->x = local_10;
  pVVar3->y = fStack_c;
  pVVar3->z = fStack_8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::SetTimerBox  @ 4fc4dc47  lines 3812-3816

int __cdecl LuaBindings::SetTimerBox(lua_State *L)

{
  char *pcVar1;
  
  pcVar1 = (char *)luaL_checklstring((undefined4 *)0x0);
  ::SetTimerBox(pcVar1);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::AddToMessagesBox  @ 4fc51473  lines 3821-3838

int __cdecl LuaBindings::AddToMessagesBox(lua_State *L)

{
  char *pcVar1;
  int iVar2;
  ulong uVar3;
  char *colorname;
  
  pcVar1 = (char *)luaL_checklstring((undefined4 *)0x0);
  iVar2 = lua_isnumber();
  if (iVar2 == 0) {
    iVar2 = lua_isstring();
    if (iVar2 == 0) {
      ::AddToMessagesBox(pcVar1);
      return 0;
    }
    colorname = (char *)lua_tolstring((undefined4 *)0x0);
    uVar3 = GetColor(colorname);
  }
  else {
    uVar3 = lua_tointegerx((undefined4 *)0x0);
  }
  AddToMessagesBox2(pcVar1,uVar3);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::GetDeaths  @ 4fc50a84  lines 3842-3846

int __cdecl LuaBindings::GetDeaths(lua_State *L)

{
  int iVar1;
  
  iVar1 = RequireHandle(L,1);
  iVar1 = ::GetDeaths(iVar1);
  **(double **)(L + 8) = (double)iVar1;
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetKills  @ 4fc4b6b8  lines 3850-3854

int __cdecl LuaBindings::GetKills(lua_State *L)

{
  int iVar1;
  
  iVar1 = RequireHandle(L,1);
  iVar1 = ::GetKills(iVar1);
  **(double **)(L + 8) = (double)iVar1;
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetScore  @ 4fc4de9c  lines 3858-3862

int __cdecl LuaBindings::GetScore(lua_State *L)

{
  int iVar1;
  
  iVar1 = RequireHandle(L,1);
  iVar1 = ::GetScore(iVar1);
  **(double **)(L + 8) = (double)iVar1;
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::SetDeaths  @ 4fc4f28d  lines 3866-3871

int __cdecl LuaBindings::SetDeaths(lua_State *L)

{
  int iVar1;
  int iVar2;
  
  iVar1 = RequireHandle(L,1);
  iVar2 = luaL_checkinteger();
  ::SetDeaths(iVar1,iVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::SetKills  @ 4fc4a570  lines 3875-3880

int __cdecl LuaBindings::SetKills(lua_State *L)

{
  int iVar1;
  int iVar2;
  
  iVar1 = RequireHandle(L,1);
  iVar2 = luaL_checkinteger();
  ::SetKills(iVar1,iVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::SetScore  @ 4fc520d7  lines 3884-3889

int __cdecl LuaBindings::SetScore(lua_State *L)

{
  int iVar1;
  int iVar2;
  
  iVar1 = RequireHandle(L,1);
  iVar2 = luaL_checkinteger();
  ::SetScore(iVar1,iVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::AddDeaths  @ 4fc53869  lines 3893-3898

int __cdecl LuaBindings::AddDeaths(lua_State *L)

{
  int iVar1;
  int iVar2;
  
  iVar1 = RequireHandle(L,1);
  iVar2 = luaL_checkinteger();
  ::AddDeaths(iVar1,iVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::AddKills  @ 4fc53b3a  lines 3902-3907

int __cdecl LuaBindings::AddKills(lua_State *L)

{
  int iVar1;
  int iVar2;
  
  iVar1 = RequireHandle(L,1);
  iVar2 = luaL_checkinteger();
  ::AddKills(iVar1,iVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::AddScore  @ 4fc4a288  lines 3911-3916

int __cdecl LuaBindings::AddScore(lua_State *L)

{
  int iVar1;
  int iVar2;
  
  iVar1 = RequireHandle(L,1);
  iVar2 = luaL_checkinteger();
  ::AddScore(iVar1,iVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::SetAsUser  @ 4fc4e535  lines 3920-3925

int __cdecl LuaBindings::SetAsUser(lua_State *L)

{
  int iVar1;
  int iVar2;
  
  iVar1 = RequireHandle(L,1);
  iVar2 = luaL_checkinteger();
  ::SetAsUser(iVar1,iVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::SetNoScrapFlagByHandle  @ 4fc51224  lines 3929-3933

int __cdecl LuaBindings::SetNoScrapFlagByHandle(lua_State *L)

{
  int iVar1;
  
  iVar1 = RequireHandle(L,1);
  ::SetNoScrapFlagByHandle(iVar1);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::ClearNoScrapFlagByHandle  @ 4fc48fe9  lines 3937-3941

int __cdecl LuaBindings::ClearNoScrapFlagByHandle(lua_State *L)

{
  int iVar1;
  
  iVar1 = RequireHandle(L,1);
  ::ClearNoScrapFlagByHandle(iVar1);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::GetLocalPlayerTeamNumber  @ 4fc511bc  lines 3945-3948

int __cdecl LuaBindings::GetLocalPlayerTeamNumber(lua_State *L)

{
  double *pdVar1;
  int iVar2;
  
  iVar2 = ::GetLocalPlayerTeamNumber();
  pdVar1 = *(double **)(L + 8);
  *pdVar1 = (double)iVar2;
  *(double **)(L + 8) = pdVar1 + 1;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetLocalPlayerDPID  @ 4fc5205e  lines 3952-3955

int __cdecl LuaBindings::GetLocalPlayerDPID(lua_State *L)

{
  double *pdVar1;
  ulong uVar2;
  
  uVar2 = ::GetLocalPlayerDPID();
  pdVar1 = *(double **)(L + 8);
  *pdVar1 = (double)(int)uVar2;
  *(double **)(L + 8) = pdVar1 + 1;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::FlagSteal  @ 4fc51961  lines 3959-3964

int __cdecl LuaBindings::FlagSteal(lua_State *L)

{
  int iVar1;
  int iVar2;
  
  iVar1 = RequireHandle(L,1);
  iVar2 = RequireHandle(L,2);
  ::FlagSteal(iVar1,iVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::FlagRecover  @ 4fc4a5c1  lines 3968-3973

int __cdecl LuaBindings::FlagRecover(lua_State *L)

{
  int iVar1;
  int iVar2;
  
  iVar1 = RequireHandle(L,1);
  iVar2 = RequireHandle(L,2);
  ::FlagRecover(iVar1,iVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::FlagScore  @ 4fc4ac3b  lines 3977-3982

int __cdecl LuaBindings::FlagScore(lua_State *L)

{
  int iVar1;
  int iVar2;
  
  iVar1 = RequireHandle(L,1);
  iVar2 = RequireHandle(L,2);
  ::FlagScore(iVar1,iVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::MoneyScore  @ 4fc53b65  lines 3986-3991

int __cdecl LuaBindings::MoneyScore(lua_State *L)

{
  int iVar1;
  int iVar2;
  
  iVar1 = luaL_checkinteger();
  iVar2 = RequireHandle(L,2);
  ::MoneyScore(iVar1,iVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::NoteGameoverByTimelimit  @ 4fc5198c  lines 3995-3998

int __cdecl LuaBindings::NoteGameoverByTimelimit(lua_State *__formal)

{
  ::NoteGameoverByTimelimit();
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::NoteGameoverByKillLimit  @ 4fc5473c  lines 4002-4006

int __cdecl LuaBindings::NoteGameoverByKillLimit(lua_State *L)

{
  int iVar1;
  
  iVar1 = RequireHandle(L,1);
  ::NoteGameoverByKillLimit(iVar1);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::NoteGameoverByScore  @ 4fc4d713  lines 4010-4014

int __cdecl LuaBindings::NoteGameoverByScore(lua_State *L)

{
  int iVar1;
  
  iVar1 = RequireHandle(L,1);
  ::NoteGameoverByScore(iVar1);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::NoteGameoverByLastWithBase  @ 4fc504ab  lines 4018-4022

int __cdecl LuaBindings::NoteGameoverByLastWithBase(lua_State *L)

{
  int iVar1;
  
  iVar1 = RequireHandle(L,1);
  ::NoteGameoverByLastWithBase(iVar1);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::NoteGameoverByLastTeamWithBase  @ 4fc52ce4  lines 4026-4030

int __cdecl LuaBindings::NoteGameoverByLastTeamWithBase(lua_State *L)

{
  int iVar1;
  
  iVar1 = luaL_checkinteger();
  ::NoteGameoverByLastTeamWithBase(iVar1);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::NoteGameoverByNoBases  @ 4fc4f16e  lines 4034-4037

int __cdecl LuaBindings::NoteGameoverByNoBases(lua_State *__formal)

{
  ::NoteGameoverByNoBases();
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::DoGameover  @ 4fc49ba1  lines 4041-4045

int __cdecl LuaBindings::DoGameover(lua_State *L)

{
  undefined4 in_XMM0_Da;
  undefined4 in_XMM0_Db;
  
  luaL_checknumber();
  ::DoGameover((float)(double)CONCAT44(in_XMM0_Db,in_XMM0_Da));
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::SetMPTeamRace  @ 4fc4f258  lines 4049-4056

int __cdecl LuaBindings::SetMPTeamRace(lua_State *L)

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
// LuaBindings::GetTarget  @ 4fc4e0f4  lines 4060-4065

int __cdecl LuaBindings::GetTarget(lua_State *L)

{
  int iVar1;
  
  iVar1 = RequireHandle(L,1);
  iVar1 = ::GetTarget(iVar1);
  PushHandle(L,iVar1);
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::IFace_ConsoleCmd  @ 4fc4d462  lines 4069-4074

int __cdecl LuaBindings::IFace_ConsoleCmd(lua_State *L)

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
// LuaBindings::Network_SetString  @ 4fc4aa81  lines 4078-4083

int __cdecl LuaBindings::Network_SetString(lua_State *L)

{
  char *pcVar1;
  char *pcVar2;
  
  pcVar1 = (char *)luaL_checklstring((undefined4 *)0x0);
  pcVar2 = (char *)luaL_checklstring((undefined4 *)0x0);
  ::Network_SetString(pcVar1,pcVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::Network_SetInteger  @ 4fc4f82b  lines 4087-4092

int __cdecl LuaBindings::Network_SetInteger(lua_State *L)

{
  char *pcVar1;
  int iVar2;
  
  pcVar1 = (char *)luaL_checklstring((undefined4 *)0x0);
  iVar2 = luaL_checkinteger();
  ::Network_SetInteger(pcVar1,iVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::GetVelocity  @ 4fc546be  lines 4096-4100

int __cdecl LuaBindings::GetVelocity(lua_State *L)

{
  int iVar1;
  Vector *pVVar2;
  Vector local_1c;
  float local_10;
  float fStack_c;
  float fStack_8;
  
  iVar1 = RequireHandle(L,1);
  pVVar2 = ::GetVelocity(&local_1c,iVar1);
  local_10 = pVVar2->x;
  fStack_c = pVVar2->y;
  fStack_8 = pVVar2->z;
  pVVar2 = NewVector(L);
  pVVar2->x = local_10;
  pVVar2->y = fStack_c;
  pVVar2->z = fStack_8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetObjInfo_CFG  @ 4fc4d637  lines 4130-4138

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl LuaBindings::GetObjInfo_CFG(lua_State *L)

{
  bool bVar1;
  uint uVar2;
  char buffer [64];
  uint local_8;
  
  local_8 = __security_cookie ^ (uint)&stack0xfffffffc;
  uVar2 = luaL_testudata();
  memset(buffer,0,0x40);
  bVar1 = GetObjInfo(uVar2,Get_CFG,buffer);
  if (bVar1) {
    lua_pushstring();
  }
  else {
    *(undefined4 *)(*(int *)(L + 8) + 4) = 0x7ff7a500;
    *(int *)(L + 8) = *(int *)(L + 8) + 8;
  }
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetObjInfo_ODF  @ 4fc539f0  lines 4142-4150

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl LuaBindings::GetObjInfo_ODF(lua_State *L)

{
  bool bVar1;
  uint uVar2;
  char buffer [64];
  uint local_8;
  
  local_8 = __security_cookie ^ (uint)&stack0xfffffffc;
  uVar2 = luaL_testudata();
  memset(buffer,0,0x40);
  bVar1 = GetObjInfo(uVar2,Get_ODF,buffer);
  if (bVar1) {
    lua_pushstring();
  }
  else {
    *(undefined4 *)(*(int *)(L + 8) + 4) = 0x7ff7a500;
    *(int *)(L + 8) = *(int *)(L + 8) + 8;
  }
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetObjInfo_GOClass_gCfg  @ 4fc534f5  lines 4154-4162

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl LuaBindings::GetObjInfo_GOClass_gCfg(lua_State *L)

{
  bool bVar1;
  uint uVar2;
  char buffer [64];
  uint local_8;
  
  local_8 = __security_cookie ^ (uint)&stack0xfffffffc;
  uVar2 = luaL_testudata();
  memset(buffer,0,0x40);
  bVar1 = GetObjInfo(uVar2,Get_GOClass_gCfg,buffer);
  if (bVar1) {
    lua_pushstring();
  }
  else {
    *(undefined4 *)(*(int *)(L + 8) + 4) = 0x7ff7a500;
    *(int *)(L + 8) = *(int *)(L + 8) + 8;
  }
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetObjInfo_EntityType  @ 4fc4ac66  lines 4166-4174

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl LuaBindings::GetObjInfo_EntityType(lua_State *L)

{
  bool bVar1;
  uint uVar2;
  char buffer [64];
  uint local_8;
  
  local_8 = __security_cookie ^ (uint)&stack0xfffffffc;
  uVar2 = luaL_testudata();
  memset(buffer,0,0x40);
  bVar1 = GetObjInfo(uVar2,Get_EntityType,buffer);
  if (bVar1) {
    lua_pushstring();
  }
  else {
    *(undefined4 *)(*(int *)(L + 8) + 4) = 0x7ff7a500;
    *(int *)(L + 8) = *(int *)(L + 8) + 8;
  }
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetObjInfo_GOClass  @ 4fc4f3b4  lines 4178-4186

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl LuaBindings::GetObjInfo_GOClass(lua_State *L)

{
  bool bVar1;
  uint uVar2;
  char buffer [64];
  uint local_8;
  
  local_8 = __security_cookie ^ (uint)&stack0xfffffffc;
  uVar2 = luaL_testudata();
  memset(buffer,0,0x40);
  bVar1 = GetObjInfo(uVar2,Get_GOClass,buffer);
  if (bVar1) {
    lua_pushstring();
  }
  else {
    *(undefined4 *)(*(int *)(L + 8) + 4) = 0x7ff7a500;
    *(int *)(L + 8) = *(int *)(L + 8) + 8;
  }
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::Get_WeaponConfig  @ 4fc4da15  lines 4190-4205

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl LuaBindings::Get_WeaponConfig(lua_State *L)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  char buffer [64];
  uint local_8;
  
  local_8 = __security_cookie ^ (uint)&stack0xfffffffc;
  uVar1 = luaL_testudata();
  if (uVar1 == 0) {
    *(undefined4 *)(*(int *)(L + 8) + 4) = 0x7ff7a500;
    *(int *)(L + 8) = *(int *)(L + 8) + 8;
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
      goto LAB_4fc4da6e;
    }
    iVar4 = 4;
    if (4 < iVar3) goto LAB_4fc4da6e;
  }
  iVar4 = iVar3;
LAB_4fc4da6e:
  memset(buffer,0,0x40);
  GetObjInfo(uVar1,iVar4 + Get_Weapon0Config,buffer);
  lua_pushstring();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::Get_WeaponODF  @ 4fc4c5ad  lines 4209-4224

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl LuaBindings::Get_WeaponODF(lua_State *L)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  char buffer [64];
  uint local_8;
  
  local_8 = __security_cookie ^ (uint)&stack0xfffffffc;
  uVar1 = luaL_testudata();
  if (uVar1 == 0) {
    *(undefined4 *)(*(int *)(L + 8) + 4) = 0x7ff7a500;
    *(int *)(L + 8) = *(int *)(L + 8) + 8;
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
      goto LAB_4fc4c606;
    }
    iVar4 = 4;
    if (4 < iVar3) goto LAB_4fc4c606;
  }
  iVar4 = iVar3;
LAB_4fc4c606:
  memset(buffer,0,0x40);
  GetObjInfo(uVar1,iVar4 + Get_Weapon0ODF,buffer);
  lua_pushstring();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::Get_WeaponGOClass  @ 4fc48f45  lines 4228-4243

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl LuaBindings::Get_WeaponGOClass(lua_State *L)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  char buffer [64];
  uint local_8;
  
  local_8 = __security_cookie ^ (uint)&stack0xfffffffc;
  uVar1 = luaL_testudata();
  if (uVar1 == 0) {
    *(undefined4 *)(*(int *)(L + 8) + 4) = 0x7ff7a500;
    *(int *)(L + 8) = *(int *)(L + 8) + 8;
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
      goto LAB_4fc48f9e;
    }
    iVar4 = 4;
    if (4 < iVar3) goto LAB_4fc48f9e;
  }
  iVar4 = iVar3;
LAB_4fc48f9e:
  memset(buffer,0,0x40);
  GetObjInfo(uVar1,iVar4 + Get_Weapon0GOClass,buffer);
  lua_pushstring();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::DoesODFExist  @ 4fc4f6f4  lines 4247-4251

int __cdecl LuaBindings::DoesODFExist(lua_State *L)

{
  uint *puVar1;
  bool bVar2;
  char *pcVar3;
  
  pcVar3 = (char *)luaL_checklstring((undefined4 *)0x0);
  bVar2 = ::DoesODFExist(pcVar3);
  puVar1 = *(uint **)(L + 8);
  *puVar1 = (uint)bVar2;
  puVar1[1] = 0x7ff7a501;
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::TranslateString  @ 4fc4bd06  lines 4255-4280

int __cdecl LuaBindings::TranslateString(lua_State *L)

{
  char *pcVar1;
  int iVar2;
  char *pcVar3;
  
  iVar2 = (*(int *)(L + 8) - **(int **)(L + 0x10)) + -8 >> 3;
  if (iVar2 < 1) {
    *(undefined4 *)(*(int *)(L + 8) + 4) = 0x7ff7a500;
    *(int *)(L + 8) = *(int *)(L + 8) + 8;
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
      *(undefined4 *)(*(int *)(L + 8) + 4) = 0x7ff7a500;
      *(int *)(L + 8) = *(int *)(L + 8) + 8;
    }
    else {
      lua_pushstring();
    }
  }
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetScavengerCurScrap  @ 4fc49575  lines 4284-4292

int __cdecl LuaBindings::GetScavengerCurScrap(lua_State *L)

{
  int iVar1;
  
  iVar1 = RequireHandle(L,1);
  iVar1 = ::GetScavengerCurScrap(iVar1);
  if (iVar1 == -1) {
    *(undefined4 *)((int)*(double **)(L + 8) + 4) = 0x7ff7a500;
  }
  else {
    **(double **)(L + 8) = (double)iVar1;
  }
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetScavengerMaxScrap  @ 4fc4ba59  lines 4296-4304

int __cdecl LuaBindings::GetScavengerMaxScrap(lua_State *L)

{
  int iVar1;
  
  iVar1 = RequireHandle(L,1);
  iVar1 = ::GetScavengerMaxScrap(iVar1);
  if (iVar1 == -1) {
    *(undefined4 *)((int)*(double **)(L + 8) + 4) = 0x7ff7a500;
  }
  else {
    **(double **)(L + 8) = (double)iVar1;
  }
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::SetScavengerCurScrap  @ 4fc4b68d  lines 4308-4313

int __cdecl LuaBindings::SetScavengerCurScrap(lua_State *L)

{
  int iVar1;
  int iVar2;
  
  iVar1 = RequireHandle(L,1);
  iVar2 = luaL_checkinteger();
  ::SetScavengerCurScrap(iVar1,iVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::SetScavengerMaxScrap  @ 4fc4b414  lines 4317-4322

int __cdecl LuaBindings::SetScavengerMaxScrap(lua_State *L)

{
  int iVar1;
  int iVar2;
  
  iVar1 = RequireHandle(L,1);
  iVar2 = luaL_checkinteger();
  ::SetScavengerMaxScrap(iVar1,iVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::SelfDamage  @ 4fc4b3e0  lines 4326-4331

int __cdecl LuaBindings::SelfDamage(lua_State *L)

{
  int iVar1;
  undefined4 in_XMM0_Da;
  undefined4 in_XMM0_Db;
  
  iVar1 = RequireHandle(L,1);
  luaL_checknumber();
  ::SelfDamage(iVar1,(float)(double)CONCAT44(in_XMM0_Db,in_XMM0_Da));
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::WantBotKillMessages  @ 4fc4ad3d  lines 4335-4338

int __cdecl LuaBindings::WantBotKillMessages(lua_State *__formal)

{
  ::WantBotKillMessages();
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::EnableHighTPS  @ 4fc4b610  lines 4342-4347

int __cdecl LuaBindings::EnableHighTPS(lua_State *L)

{
  double *pdVar1;
  int tpsrate;
  
  ::EnableHighTPS(&tpsrate);
  pdVar1 = *(double **)(L + 8);
  *pdVar1 = (double)tpsrate;
  *(double **)(L + 8) = pdVar1 + 1;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetLocalUserInspectHandle  @ 4fc497a1  lines 4351-4354

int __cdecl LuaBindings::GetLocalUserInspectHandle(lua_State *L)

{
  int h;
  
  h = ::GetLocalUserInspectHandle();
  PushHandle(L,h);
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetLocalUserSelectHandle  @ 4fc53fc9  lines 4358-4361

int __cdecl LuaBindings::GetLocalUserSelectHandle(lua_State *L)

{
  int h;
  
  h = ::GetLocalUserSelectHandle();
  PushHandle(L,h);
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::ResetTeamSlot  @ 4fc4caa9  lines 4365-4369

int __cdecl LuaBindings::ResetTeamSlot(lua_State *L)

{
  int iVar1;
  
  iVar1 = RequireHandle(L,1);
  ::ResetTeamSlot(iVar1);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::GetCategoryTypeOverride  @ 4fc4f1e2  lines 4373-4377

int __cdecl LuaBindings::GetCategoryTypeOverride(lua_State *L)

{
  int iVar1;
  
  iVar1 = RequireHandle(L,1);
  iVar1 = ::GetCategoryTypeOverride(iVar1);
  **(double **)(L + 8) = (double)iVar1;
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetCategoryType  @ 4fc4caf8  lines 4381-4385

int __cdecl LuaBindings::GetCategoryType(lua_State *L)

{
  int iVar1;
  
  iVar1 = RequireHandle(L,1);
  iVar1 = ::GetCategoryType(iVar1);
  **(double **)(L + 8) = (double)iVar1;
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetODFHexInt  @ 4fc5358a  lines 4392-4414

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl LuaBindings::GetODFHexInt(lua_State *L)

{
  uint *puVar1;
  bool bVar2;
  char *pcVar3;
  char *pcVar4;
  uint uVar5;
  int iVar6;
  char *pcVar7;
  uint uVar8;
  int unaff_ESI;
  int *unaff_EDI;
  char *value;
  char local_48 [64];
  uint local_8;
  
  local_8 = __security_cookie ^ (uint)&stack0xfffffffc;
  uVar8 = 0;
  pcVar3 = (char *)luaL_checklstring((undefined4 *)0x0);
  pcVar4 = (char *)luaL_checklstring((undefined4 *)0x0);
  uVar5 = lua_type();
  if ((int)uVar5 < 1) {
    value = (char *)0x0;
  }
  else {
    value = (char *)luaL_checkinteger();
  }
  iVar6 = lua_isstring();
  if (iVar6 == 0) {
    iVar6 = RequireHandle(L,1);
    pcVar7 = value;
    memset(local_48,0,0x40);
    bVar2 = GetObjInfo(iVar6,Get_ODF,local_48);
    if (((bVar2) && (pcVar3 != (char *)0x0)) && (pcVar4 != (char *)0x0)) {
      iVar6 = ::GetODFHexInt(pcVar3,pcVar4,(char *)&value,pcVar7,unaff_EDI,unaff_ESI);
    }
    else {
      iVar6 = 0;
    }
    uVar8 = (uint)(iVar6 != 0);
  }
  else {
    pcVar7 = (char *)lua_tolstring((undefined4 *)0x0);
    bVar2 = OpenODF2(pcVar7);
    if (bVar2) {
      iVar6 = ::GetODFHexInt(pcVar3,pcVar4,(char *)&value,value,unaff_EDI,unaff_ESI);
      uVar8 = (uint)(iVar6 != 0);
    }
  }
  **(double **)(L + 8) = (double)(int)value;
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  puVar1 = *(uint **)(L + 8);
  *puVar1 = uVar8;
  puVar1[1] = 0x7ff7a501;
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 2;
}


// ---------------------------------------------------------------------
// LuaBindings::GetODFInt  @ 4fc4b97c  lines 4419-4441

int __cdecl LuaBindings::GetODFInt(lua_State *L)

{
  uint *puVar1;
  lua_State *L_00;
  bool bVar2;
  char *block;
  char *name;
  uint uVar3;
  int iVar4;
  char *name_00;
  uint uVar5;
  
  L_00 = L;
  uVar5 = 0;
  block = (char *)luaL_checklstring((undefined4 *)0x0);
  name = (char *)luaL_checklstring((undefined4 *)0x0);
  uVar3 = lua_type();
  if ((int)uVar3 < 1) {
    L = (lua_State *)0x0;
  }
  else {
    L = (lua_State *)luaL_checkinteger();
  }
  iVar4 = lua_isstring();
  if (iVar4 == 0) {
    iVar4 = RequireHandle(L_00,1);
    iVar4 = ::GetODFInt(iVar4,block,name,(int *)&L,(int)L);
  }
  else {
    name_00 = (char *)lua_tolstring((undefined4 *)0x0);
    bVar2 = OpenODF2(name_00);
    if (!bVar2) goto LAB_4fc4ba2d;
    iVar4 = ::GetODFInt(name_00,(char *)0x0,block,name,(int *)&L,(int)L);
  }
  uVar5 = (uint)(iVar4 != 0);
LAB_4fc4ba2d:
  **(double **)(L_00 + 8) = (double)(int)L;
  *(int *)(L_00 + 8) = *(int *)(L_00 + 8) + 8;
  puVar1 = *(uint **)(L_00 + 8);
  *puVar1 = uVar5;
  puVar1[1] = 0x7ff7a501;
  *(int *)(L_00 + 8) = *(int *)(L_00 + 8) + 8;
  return 2;
}


// ---------------------------------------------------------------------
// LuaBindings::GetODFLong  @ 4fc52516  lines 4446-4468

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl LuaBindings::GetODFLong(lua_State *L)

{
  uint *puVar1;
  bool bVar2;
  char *block;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined1 auStack_64 [4];
  long local_60;
  char *value;
  char *local_58;
  long local_54;
  char local_50 [68];
  uint local_c;
  
  local_c = __security_cookie ^ (uint)auStack_64;
  uVar5 = 0;
  block = (char *)luaL_checklstring((undefined4 *)0x0);
  value = block;
  local_58 = (char *)luaL_checklstring((undefined4 *)0x0);
  uVar3 = lua_type();
  if ((int)uVar3 < 1) {
    local_60 = 0;
  }
  else {
    local_60 = luaL_checkinteger();
  }
  iVar4 = lua_isstring();
  if (iVar4 == 0) {
    iVar4 = RequireHandle(L,1);
    local_54 = local_60;
    memset(local_50,0,0x40);
    bVar2 = GetObjInfo(iVar4,Get_ODF,local_50);
    if (((bVar2) && (value != (char *)0x0)) && (local_58 != (char *)0x0)) {
      iVar4 = ::GetODFLong(local_50,(char *)0x0,value,local_58,&local_60,local_54);
    }
    else {
      iVar4 = 0;
    }
    uVar5 = (uint)(iVar4 != 0);
  }
  else {
    value = (char *)lua_tolstring((undefined4 *)0x0);
    bVar2 = OpenODF2(value);
    if (bVar2) {
      iVar4 = ::GetODFLong(value,(char *)0x0,block,local_58,&local_60,local_60);
      uVar5 = (uint)(iVar4 != 0);
    }
  }
  lua_pushnumber();
  puVar1 = *(uint **)(L + 8);
  *puVar1 = uVar5;
  puVar1[1] = 0x7ff7a501;
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 2;
}


// ---------------------------------------------------------------------
// LuaBindings::GetODFFloat  @ 4fc4d4df  lines 4473-4495

int __cdecl LuaBindings::GetODFFloat(lua_State *L)

{
  uint *puVar1;
  bool bVar2;
  char *pcVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  undefined4 in_XMM0_Da;
  undefined4 in_XMM0_Db;
  float local_14;
  char *value;
  char *local_c;
  
  uVar6 = 0;
  pcVar3 = (char *)luaL_checklstring((undefined4 *)0x0);
  local_c = pcVar3;
  value = (char *)luaL_checklstring((undefined4 *)0x0);
  uVar4 = lua_type();
  if ((int)uVar4 < 1) {
    in_XMM0_Da = 0;
    in_XMM0_Db = 0;
  }
  else {
    luaL_checknumber();
  }
  local_14 = (float)(double)CONCAT44(in_XMM0_Db,in_XMM0_Da);
  iVar5 = lua_isstring();
  if (iVar5 == 0) {
    iVar5 = RequireHandle(L,1);
    iVar5 = ::GetODFFloat(iVar5,pcVar3,value,&local_14,local_14);
  }
  else {
    pcVar3 = (char *)lua_tolstring((undefined4 *)0x0);
    bVar2 = OpenODF2(pcVar3);
    if (!bVar2) goto LAB_4fc4d5b5;
    iVar5 = ::GetODFFloat(pcVar3,(char *)0x0,local_c,value,&local_14,local_14);
  }
  uVar6 = (uint)(iVar5 != 0);
LAB_4fc4d5b5:
  lua_pushnumber();
  puVar1 = *(uint **)(L + 8);
  *puVar1 = uVar6;
  puVar1[1] = 0x7ff7a501;
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 2;
}


// ---------------------------------------------------------------------
// LuaBindings::GetODFDouble  @ 4fc52beb  lines 4500-4522

int __cdecl LuaBindings::GetODFDouble(lua_State *L)

{
  uint *puVar1;
  bool bVar2;
  char *block;
  char *name;
  uint uVar3;
  int iVar4;
  char *name_00;
  undefined4 unaff_EBX;
  undefined4 unaff_ESI;
  uint uVar5;
  double in_XMM0_Qa;
  double local_10;
  
  uVar5 = 0;
  block = (char *)luaL_checklstring((undefined4 *)0x0);
  name = (char *)luaL_checklstring((undefined4 *)0x0);
  uVar3 = lua_type();
  if ((int)uVar3 < 1) {
    in_XMM0_Qa = 0.0;
  }
  else {
    luaL_checknumber();
  }
  local_10 = in_XMM0_Qa;
  iVar4 = lua_isstring();
  if (iVar4 == 0) {
    iVar4 = RequireHandle(L,1);
    iVar4 = ::GetODFDouble(iVar4,block,name,&local_10,local_10);
  }
  else {
    name_00 = (char *)lua_tolstring((undefined4 *)0x0);
    bVar2 = OpenODF2(name_00);
    if (!bVar2) goto LAB_4fc52cbd;
    iVar4 = ::GetODFDouble(block,name,(char *)&local_10,SUB84(local_10,0),
                           (double *)((ulonglong)local_10 >> 0x20),
                           (double)CONCAT44(unaff_EBX,unaff_ESI));
  }
  uVar5 = (uint)(iVar4 != 0);
LAB_4fc52cbd:
  lua_pushnumber();
  puVar1 = *(uint **)(L + 8);
  *puVar1 = uVar5;
  puVar1[1] = 0x7ff7a501;
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 2;
}


// ---------------------------------------------------------------------
// LuaBindings::GetODFChar  @ 4fc4f89e  lines 4527-4552

int __cdecl LuaBindings::GetODFChar(lua_State *L)

{
  uint *puVar1;
  lua_State *L_00;
  bool bVar2;
  char *block;
  char *name;
  char *pcVar3;
  int iVar4;
  bool bVar5;
  
  L_00 = L;
  bVar5 = false;
  block = (char *)luaL_checklstring((undefined4 *)0x0);
  name = (char *)luaL_checklstring((undefined4 *)0x0);
  pcVar3 = luaL_optlstring("",(int *)0x0);
  L = (lua_State *)CONCAT31(L._1_3_,*pcVar3);
  iVar4 = lua_isstring();
  if (iVar4 == 0) {
    iVar4 = RequireHandle(L_00,1);
    iVar4 = ::GetODFChar(iVar4,block,name,(char *)&L,(char)L);
LAB_4fc4f93e:
    bVar5 = iVar4 != 0;
    if (!bVar5) goto LAB_4fc4f947;
  }
  else {
    pcVar3 = (char *)lua_tolstring((undefined4 *)0x0);
    bVar2 = OpenODF2(pcVar3);
    if (bVar2) {
      iVar4 = ::GetODFChar(pcVar3,(char *)0x0,block,name,(char *)&L,(char)L);
      goto LAB_4fc4f93e;
    }
LAB_4fc4f947:
    if ((char)L == '\0') {
      *(undefined4 *)(*(int *)(L_00 + 8) + 4) = 0x7ff7a500;
      *(int *)(L_00 + 8) = *(int *)(L_00 + 8) + 8;
      goto LAB_4fc4f96a;
    }
  }
  lua_pushlstring(1);
LAB_4fc4f96a:
  puVar1 = *(uint **)(L_00 + 8);
  *puVar1 = (uint)bVar5;
  puVar1[1] = 0x7ff7a501;
  *(int *)(L_00 + 8) = *(int *)(L_00 + 8) + 8;
  return 2;
}


// ---------------------------------------------------------------------
// LuaBindings::GetODFBool  @ 4fc4a48f  lines 4557-4579

int __cdecl LuaBindings::GetODFBool(lua_State *L)

{
  uint *puVar1;
  lua_State *L_00;
  bool bVar2;
  char *block;
  char *name;
  uint uVar3;
  int iVar4;
  char *name_00;
  uint uVar5;
  
  L_00 = L;
  uVar5 = 0;
  block = (char *)luaL_checklstring((undefined4 *)0x0);
  name = (char *)luaL_checklstring((undefined4 *)0x0);
  uVar3 = lua_type();
  if ((int)uVar3 < 1) {
    iVar4 = 0;
  }
  else {
    iVar4 = lua_toboolean();
  }
  L = (lua_State *)CONCAT31(L._1_3_,iVar4 != 0);
  iVar4 = lua_isstring();
  if (iVar4 == 0) {
    iVar4 = RequireHandle(L_00,1);
    iVar4 = ::GetODFBool(iVar4,block,name,(bool *)&L,SUB41(L,0));
  }
  else {
    name_00 = (char *)lua_tolstring((undefined4 *)0x0);
    bVar2 = OpenODF2(name_00);
    if (!bVar2) goto LAB_4fc4a543;
    iVar4 = ::GetODFBool(name_00,(char *)0x0,block,name,(bool *)&L,SUB41(L,0));
  }
  uVar5 = (uint)(iVar4 != 0);
LAB_4fc4a543:
  puVar1 = *(uint **)(L_00 + 8);
  *puVar1 = (uint)((char)L != '\0');
  puVar1[1] = 0x7ff7a501;
  *(int *)(L_00 + 8) = *(int *)(L_00 + 8) + 8;
  puVar1 = *(uint **)(L_00 + 8);
  *puVar1 = uVar5;
  puVar1[1] = 0x7ff7a501;
  *(int *)(L_00 + 8) = *(int *)(L_00 + 8) + 8;
  return 2;
}


// ---------------------------------------------------------------------
// LuaBindings::GetODFString  @ 4fc4cdb9  lines 4584-4612

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl LuaBindings::GetODFString(lua_State *L)

{
  uint *puVar1;
  bool bVar2;
  char *block;
  char *name;
  char *defval;
  int iVar3;
  char *name_00;
  bool bVar4;
  char value [64];
  uint local_8;
  
  local_8 = __security_cookie ^ (uint)&stack0xfffffffc;
  bVar4 = false;
  block = (char *)luaL_checklstring((undefined4 *)0x0);
  name = (char *)luaL_checklstring((undefined4 *)0x0);
  defval = luaL_optlstring((char *)0x0,(int *)0x0);
  memset(value,0,0x40);
  iVar3 = lua_isstring();
  if (iVar3 == 0) {
    iVar3 = RequireHandle(L,1);
    iVar3 = ::GetODFString(iVar3,block,name,0x40,value,defval);
LAB_4fc4ce6a:
    bVar4 = iVar3 != 0;
    if (!bVar4) goto LAB_4fc4ce78;
  }
  else {
    name_00 = (char *)lua_tolstring((undefined4 *)0x0);
    bVar2 = OpenODF2(name_00);
    if (bVar2) {
      iVar3 = ::GetODFString(name_00,(char *)0x0,block,name,0x40,value,defval);
      goto LAB_4fc4ce6a;
    }
LAB_4fc4ce78:
    if ((defval == (char *)0x0) || (*defval == '\0')) {
      *(undefined4 *)(*(int *)(L + 8) + 4) = 0x7ff7a500;
      *(int *)(L + 8) = *(int *)(L + 8) + 8;
      goto LAB_4fc4ce9a;
    }
  }
  lua_pushstring();
LAB_4fc4ce9a:
  puVar1 = *(uint **)(L + 8);
  *puVar1 = (uint)bVar4;
  puVar1[1] = 0x7ff7a501;
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 2;
}


// ---------------------------------------------------------------------
// LuaBindings::GetODFColor  @ 4fc53397  lines 4617-4639

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl LuaBindings::GetODFColor(lua_State *L)

{
  uint *puVar1;
  bool bVar2;
  char *block;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined1 auStack_64 [4];
  ulong local_60;
  char *value;
  char *local_58;
  ulong local_54;
  char local_50 [68];
  uint local_c;
  
  local_c = __security_cookie ^ (uint)auStack_64;
  uVar5 = 0;
  block = (char *)luaL_checklstring((undefined4 *)0x0);
  value = block;
  local_58 = (char *)luaL_checklstring((undefined4 *)0x0);
  uVar3 = lua_type();
  if ((int)uVar3 < 1) {
    local_60 = 0;
  }
  else {
    local_60 = luaL_checkinteger();
  }
  iVar4 = lua_isstring();
  if (iVar4 == 0) {
    iVar4 = RequireHandle(L,1);
    local_54 = local_60;
    memset(local_50,0,0x40);
    bVar2 = GetObjInfo(iVar4,Get_ODF,local_50);
    if (((bVar2) && (value != (char *)0x0)) && (local_58 != (char *)0x0)) {
      iVar4 = ::GetODFColor(local_50,(char *)0x0,value,local_58,&local_60,local_54);
    }
    else {
      iVar4 = 0;
    }
    uVar5 = (uint)(iVar4 != 0);
  }
  else {
    value = (char *)lua_tolstring((undefined4 *)0x0);
    bVar2 = OpenODF2(value);
    if (bVar2) {
      iVar4 = ::GetODFColor(value,(char *)0x0,block,local_58,&local_60,local_60);
      uVar5 = (uint)(iVar4 != 0);
    }
  }
  lua_pushnumber();
  puVar1 = *(uint **)(L + 8);
  *puVar1 = uVar5;
  puVar1[1] = 0x7ff7a501;
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 2;
}


// ---------------------------------------------------------------------
// LuaBindings::GetODFVector  @ 4fc53216  lines 4644-4668

int __cdecl LuaBindings::GetODFVector(lua_State *L)

{
  uint *puVar1;
  Vector defval;
  Vector defval_00;
  bool bVar2;
  float *pfVar3;
  int iVar4;
  Vector *pVVar5;
  uint uVar6;
  float local_28;
  float local_24;
  float local_20;
  Vector value;
  char *local_10;
  char *local_c;
  char *local_8;
  
  uVar6 = 0;
  local_c = (char *)luaL_checklstring((undefined4 *)0x0);
  local_8 = (char *)luaL_checklstring((undefined4 *)0x0);
  pfVar3 = (float *)luaL_testudata();
  if (pfVar3 == (float *)0x0) {
    local_28 = 0.0;
    local_24 = 0.0;
    local_20 = 0.0;
  }
  else {
    local_28 = *pfVar3;
    local_24 = pfVar3[1];
    local_20 = pfVar3[2];
  }
  value.x = local_28;
  value.y = local_24;
  value.z = local_20;
  iVar4 = lua_isstring();
  if (iVar4 == 0) {
    iVar4 = RequireHandle(L,1);
    defval_00.y = value.y;
    defval_00.x = value.x;
    defval_00.z = value.z;
    iVar4 = ::GetODFVector(iVar4,local_c,local_8,&value,defval_00);
  }
  else {
    local_10 = (char *)lua_tolstring((undefined4 *)0x0);
    bVar2 = OpenODF2(local_10);
    if (!bVar2) goto LAB_4fc532ed;
    defval.y = value.y;
    defval.x = value.x;
    defval.z = value.z;
    iVar4 = ::GetODFVector(local_10,(char *)0x0,local_c,local_8,&value,defval);
  }
  uVar6 = (uint)(iVar4 != 0);
LAB_4fc532ed:
  pVVar5 = NewVector(L);
  pVVar5->x = value.x;
  pVVar5->y = value.y;
  pVVar5->z = value.z;
  puVar1 = *(uint **)(L + 8);
  *puVar1 = uVar6;
  puVar1[1] = 0x7ff7a501;
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 2;
}


// ---------------------------------------------------------------------
// LuaBindings::NoteGameoverWithCustomMessage  @ 4fc4a98e  lines 4690-4694

int __cdecl LuaBindings::NoteGameoverWithCustomMessage(lua_State *L)

{
  char *pcVar1;
  
  pcVar1 = (char *)luaL_checklstring((undefined4 *)0x0);
  ::NoteGameoverWithCustomMessage(pcVar1);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::SetBestGroup  @ 4fc4e382  lines 4698-4706

int __cdecl LuaBindings::SetBestGroup(lua_State *L)

{
  int iVar1;
  
  iVar1 = RequireHandle(L,1);
  iVar1 = ::SetBestGroup(iVar1);
  if (iVar1 == -1) {
    *(undefined4 *)((int)*(double **)(L + 8) + 4) = 0x7ff7a500;
  }
  else {
    **(double **)(L + 8) = (double)iVar1;
  }
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetGroup  @ 4fc49858  lines 4711-4735

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl LuaBindings::GetGroup(lua_State *L)

{
  int iVar1;
  int iVar2;
  ObjectInfoType OVar3;
  char pBuffer [64];
  uint local_8;
  
  local_8 = __security_cookie ^ (uint)&stack0xfffffffc;
  iVar1 = lua_isnumber();
  if (iVar1 == 0) {
    iVar1 = RequireHandle(L,1);
    iVar1 = ::GetGroup(iVar1);
    if (iVar1 == -1) {
      *(undefined4 *)((int)*(double **)(L + 8) + 4) = 0x7ff7a500;
    }
    else {
      **(double **)(L + 8) = (double)iVar1;
    }
    *(int *)(L + 8) = *(int *)(L + 8) + 8;
  }
  else {
    iVar1 = luaL_checkinteger();
    iVar2 = lua_tointegerx((undefined4 *)0x0);
    OVar3 = luaL_checkinteger();
    memset(pBuffer,0,0x40);
    ::GetGroup(iVar1,iVar2,OVar3,pBuffer);
    lua_pushstring();
  }
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetGroupCount  @ 4fc4e315  lines 4739-4744

int __cdecl LuaBindings::GetGroupCount(lua_State *L)

{
  int iVar1;
  int iVar2;
  
  iVar1 = luaL_checkinteger();
  iVar2 = luaL_checkinteger();
  iVar1 = ::GetGroupCount(iVar1,iVar2);
  **(double **)(L + 8) = (double)iVar1;
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::SetLifespan  @ 4fc491ce  lines 4748-4753

int __cdecl LuaBindings::SetLifespan(lua_State *L)

{
  int iVar1;
  undefined4 in_XMM0_Da;
  undefined4 in_XMM0_Db;
  
  iVar1 = RequireHandle(L,1);
  luaL_checknumber();
  ::SetLifespan(iVar1,(float)(double)CONCAT44(in_XMM0_Db,in_XMM0_Da));
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::DoesFileExist  @ 4fc4cac3  lines 4757-4761

int __cdecl LuaBindings::DoesFileExist(lua_State *L)

{
  uint *puVar1;
  bool bVar2;
  char *pcVar3;
  
  pcVar3 = (char *)luaL_checklstring((undefined4 *)0x0);
  bVar2 = ::DoesFileExist(pcVar3);
  puVar1 = *(uint **)(L + 8);
  *puVar1 = (uint)bVar2;
  puVar1[1] = 0x7ff7a501;
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::LoadFile  @ 4fc497b9  lines 4765-4785

int __cdecl LuaBindings::LoadFile(lua_State *L)

{
  void *_Memory;
  bool bVar1;
  char *pcVar2;
  void *size;
  uint bufSize;
  
  pcVar2 = (char *)luaL_checklstring(&size);
  bufSize = 0;
  ::LoadFile(pcVar2,(void *)0x0,&bufSize);
  size = malloc(bufSize + 1);
  bVar1 = ::LoadFile(pcVar2,size,&bufSize);
  _Memory = size;
  if (bVar1) {
    *(undefined1 *)((int)size + bufSize) = 0;
    lua_pushlstring(bufSize);
  }
  else {
    *(undefined4 *)(*(int *)(L + 8) + 4) = 0x7ff7a500;
    *(int *)(L + 8) = *(int *)(L + 8) + 8;
  }
  free(_Memory);
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::StartAudio3D  @ 4fc4c1fa  lines 4792-4825

int __cdecl LuaBindings::StartAudio3D(lua_State *L)

{
  char *name;
  int iVar1;
  uint uVar2;
  uint uVar3;
  Vector *pVVar4;
  int iVar5;
  int iVar6;
  DLLAudioCategory DVar7;
  float fVar8;
  undefined1 in_XMM0 [16];
  undefined1 auVar9 [16];
  undefined1 auVar10 [16];
  undefined1 auVar11 [16];
  undefined1 auVar12 [16];
  undefined4 local_14;
  
  iVar6 = 0;
  name = (char *)luaL_checklstring((undefined4 *)0x0);
  iVar1 = lua_isnumber();
  if (iVar1 == 0) {
    uVar2 = luaL_testudata();
    if (uVar2 == 0) {
      pVVar4 = (Vector *)luaL_testudata();
      if (pVVar4 == (Vector *)0x0) {
        iVar1 = RequireHandle(L,2);
        uVar2 = lua_type();
        if ((int)uVar2 < 1) {
          DVar7 = AUDIO_CAT_UNKNOWN;
        }
        else {
          DVar7 = luaL_checkinteger();
        }
        uVar2 = lua_type();
        if ((int)uVar2 < 1) {
          iVar5 = 0;
        }
        else {
          iVar5 = lua_toboolean();
        }
        uVar2 = lua_type();
        if (0 < (int)uVar2) {
          iVar6 = lua_toboolean();
        }
        ::StartAudio3D(name,iVar1,DVar7,iVar5 != 0,iVar6 != 0);
        goto LAB_4fc4c438;
      }
      uVar2 = lua_type();
      if ((int)uVar2 < 1) {
        local_14 = AUDIO_CAT_UNKNOWN;
      }
      else {
        local_14 = luaL_checkinteger();
      }
      uVar2 = lua_type();
      if (0 < (int)uVar2) {
        iVar6 = lua_toboolean();
      }
    }
    else {
      uVar3 = lua_type();
      if ((int)uVar3 < 1) {
        local_14 = AUDIO_CAT_UNKNOWN;
      }
      else {
        local_14 = luaL_checkinteger();
      }
      uVar3 = lua_type();
      if (0 < (int)uVar3) {
        iVar6 = lua_toboolean();
      }
      pVVar4 = (Vector *)(uVar2 + 0x30);
    }
    ::StartAudio3D(name,*pVVar4,local_14,iVar6 != 0);
  }
  else {
    luaL_checknumber();
    auVar9._4_12_ = in_XMM0._4_12_;
    auVar9._0_4_ = (float)in_XMM0._0_8_;
    auVar12 = auVar9;
    luaL_checknumber();
    auVar10._4_12_ = auVar12._4_12_;
    auVar10._0_4_ = (float)auVar12._0_8_;
    auVar12 = auVar10;
    luaL_checknumber();
    auVar11._4_12_ = auVar12._4_12_;
    auVar11._0_4_ = (float)auVar12._0_8_;
    auVar12 = auVar11;
    uVar2 = lua_type();
    if ((int)uVar2 < 1) {
      DVar7 = AUDIO_CAT_UNKNOWN;
    }
    else {
      DVar7 = luaL_checkinteger();
      auVar12 = ZEXT416((uint)auVar11._0_4_);
    }
    uVar2 = lua_type();
    fVar8 = auVar12._0_4_;
    if (0 < (int)uVar2) {
      iVar6 = lua_toboolean();
      fVar8 = auVar12._0_4_;
    }
    ::StartAudio3D(name,auVar9._0_4_,auVar10._0_4_,fVar8,DVar7,iVar6 != 0);
  }
LAB_4fc4c438:
  lua_pushnumber();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::StartAudio2D  @ 4fc503c9  lines 4830-4839

int __cdecl LuaBindings::StartAudio2D(lua_State *L)

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
// LuaBindings::IsAudioPlaying  @ 4fc531da  lines 4843-4847

int __cdecl LuaBindings::IsAudioPlaying(lua_State *L)

{
  lua_State *plVar1;
  uint *puVar2;
  bool bVar3;
  double in_XMM0_Qa;
  
  plVar1 = L;
  luaL_checknumber();
  L = (lua_State *)(int)in_XMM0_Qa;
  bVar3 = ::IsAudioPlaying((int *)&L);
  puVar2 = *(uint **)(plVar1 + 8);
  *puVar2 = (uint)bVar3;
  puVar2[1] = 0x7ff7a501;
  plVar1 = plVar1 + 8;
  *(int *)plVar1 = *(int *)plVar1 + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::StopAudio  @ 4fc506a9  lines 4851-4855

int __cdecl LuaBindings::StopAudio(lua_State *L)

{
  double in_XMM0_Qa;
  
  luaL_checknumber();
  ::StopAudio((int)in_XMM0_Qa);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::PauseAudio  @ 4fc51ed1  lines 4859-4863

int __cdecl LuaBindings::PauseAudio(lua_State *L)

{
  double in_XMM0_Qa;
  
  luaL_checknumber();
  ::PauseAudio((int)in_XMM0_Qa);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::ResumeAudio  @ 4fc53f88  lines 4867-4871

int __cdecl LuaBindings::ResumeAudio(lua_State *L)

{
  double in_XMM0_Qa;
  
  luaL_checknumber();
  ::ResumeAudio((int)in_XMM0_Qa);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::SetVolume  @ 4fc4c992  lines 4875-4881

int __cdecl LuaBindings::SetVolume(lua_State *L)

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
// LuaBindings::SetPan  @ 4fc52666  lines 4885-4890

int __cdecl LuaBindings::SetPan(lua_State *L)

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
// LuaBindings::SetRate  @ 4fc49192  lines 4894-4899

int __cdecl LuaBindings::SetRate(lua_State *L)

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
// LuaBindings::GetAudioFileDuration  @ 4fc4cd7a  lines 4903-4907

int __cdecl LuaBindings::GetAudioFileDuration(lua_State *L)

{
  double in_XMM0_Qa;
  
  luaL_checknumber();
  ::GetAudioFileDuration((int)in_XMM0_Qa);
  lua_pushnumber();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::IsPlayingLooped  @ 4fc4df2a  lines 4911-4915

int __cdecl LuaBindings::IsPlayingLooped(lua_State *L)

{
  uint *puVar1;
  bool bVar2;
  double in_XMM0_Qa;
  
  luaL_checknumber();
  bVar2 = ::IsPlayingLooped((int)in_XMM0_Qa);
  puVar1 = *(uint **)(L + 8);
  *puVar1 = (uint)bVar2;
  puVar1[1] = 0x7ff7a501;
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetNearestPowerup  @ 4fc4c09f  lines 4919-4925

int __cdecl LuaBindings::GetNearestPowerup(lua_State *L)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  double in_XMM0_Qa;
  
  iVar1 = RequireHandle(L,1);
  iVar2 = lua_toboolean();
  uVar3 = lua_type();
  if ((int)uVar3 < 1) {
    in_XMM0_Qa = 450.0;
  }
  else {
    luaL_checknumber();
  }
  iVar1 = ::GetNearestPowerup(iVar1,iVar2 != 0,(float)in_XMM0_Qa);
  PushHandle(L,iVar1);
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetNearestPerson  @ 4fc4a36d  lines 4929-4935

int __cdecl LuaBindings::GetNearestPerson(lua_State *L)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  double in_XMM0_Qa;
  
  iVar1 = RequireHandle(L,1);
  iVar2 = lua_toboolean();
  uVar3 = lua_type();
  if ((int)uVar3 < 1) {
    in_XMM0_Qa = 450.0;
  }
  else {
    luaL_checknumber();
  }
  iVar1 = ::GetNearestPerson(iVar1,iVar2 != 0,(float)in_XMM0_Qa);
  PushHandle(L,iVar1);
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::SetCommand  @ 4fc495b5  lines 4944-4983

int __cdecl LuaBindings::SetCommand(lua_State *L)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  uint uVar6;
  Vector *pVVar7;
  ulong uVar8;
  int iVar9;
  
  iVar9 = 1;
  iVar1 = RequireHandle(L,1);
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
// LuaBindings::SetGravity  @ 4fc524b8  lines 4987-4991

int __cdecl LuaBindings::SetGravity(lua_State *L)

{
  uint uVar1;
  double in_XMM0_Qa;
  
  uVar1 = lua_type();
  if ((int)uVar1 < 1) {
    in_XMM0_Qa = 12.5;
  }
  else {
    luaL_checknumber();
  }
  ::SetGravity((float)in_XMM0_Qa);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::SetAutoGroupUnits  @ 4fc4f0f3  lines 4995-4999

int __cdecl LuaBindings::SetAutoGroupUnits(lua_State *L)

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
// LuaBindings::KickPlayer  @ 4fc4a186  lines 5003-5009

int __cdecl LuaBindings::KickPlayer(lua_State *L)

{
  int iVar1;
  char *pcVar2;
  uint uVar3;
  int iVar4;
  
  iVar1 = RequireHandle(L,1);
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
// LuaBindings::TerrainIsWater  @ 4fc49003  lines 5017-5043

int __cdecl LuaBindings::TerrainIsWater(lua_State *L)

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
    if (pVVar5 != (Vector *)0x0) goto LAB_4fc49035;
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
        puVar1 = *(uint **)(L + 8);
        *puVar1 = (uint)bVar3;
        puVar1[1] = 0x7ff7a501;
        goto LAB_4fc4913b;
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
LAB_4fc49035:
    bVar3 = ::TerrainIsWater(pVVar5);
  }
  puVar1 = *(uint **)(L + 8);
  *puVar1 = (uint)bVar3;
  puVar1[1] = 0x7ff7a501;
LAB_4fc4913b:
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetTerrainHeightAndNormal  @ 4fc4b43f  lines 5047-5079

int __cdecl LuaBindings::GetTerrainHeightAndNormal(lua_State *L)

{
  int iVar1;
  uint uVar2;
  Vector *pVVar3;
  Vector *pVVar4;
  undefined1 uVar5;
  float *pfVar6;
  Vector *pVVar7;
  float usewater;
  Vector height;
  Vector local_14;
  
  iVar1 = lua_isstring();
  if (iVar1 == 0) {
    uVar2 = lua_type();
    if (0 < (int)uVar2) goto LAB_4fc4b486;
LAB_4fc4b480:
    iVar1 = 0;
  }
  else {
    uVar2 = lua_type();
    if ((int)uVar2 < 1) goto LAB_4fc4b480;
LAB_4fc4b486:
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
        iVar1 = RequireHandle(L,1);
        ::GetPosition(iVar1,&local_14);
        TerrainGetHeightAndNormal(&local_14,&usewater,&height,(bool)uVar5);
        goto LAB_4fc4b566;
      }
      lua_tolstring((undefined4 *)0x0);
      uVar2 = lua_type();
      if (0 < (int)uVar2) {
        pVVar4 = (Vector *)luaL_checkinteger();
      }
      pVVar7 = &height;
      pfVar6 = &usewater;
      pVVar3 = GetVectorFromPath(pVVar4,(char *)pfVar6,(int)pVVar7);
    }
    else {
      pVVar7 = &height;
      pfVar6 = &usewater;
    }
  }
  else {
    pVVar7 = &height;
    pVVar3 = (Vector *)(uVar2 + 0x30);
    pfVar6 = &usewater;
  }
  TerrainGetHeightAndNormal(pVVar3,pfVar6,pVVar7,(bool)uVar5);
LAB_4fc4b566:
  lua_pushnumber();
  pVVar4 = NewVector(L);
  pVVar4->x = height.x;
  pVVar4->y = height.y;
  pVVar4->z = height.z;
  return 2;
}


// ---------------------------------------------------------------------
// LuaBindings::WriteToFile  @ 4fc49d6f  lines 5087-5098

int __cdecl LuaBindings::WriteToFile(lua_State *L)

{
  lua_State *plVar1;
  uint *puVar2;
  bool bVar3;
  char *Filename;
  char *fmtarg1;
  uint uVar4;
  int iVar5;
  undefined4 fileNameSize;
  
  plVar1 = L;
  Filename = (char *)luaL_checklstring(&fileNameSize);
  fmtarg1 = (char *)luaL_checklstring(&L);
  uVar4 = lua_type();
  if ((int)uVar4 < 1) {
    iVar5 = 1;
  }
  else {
    iVar5 = lua_toboolean();
  }
  bVar3 = FormatFileMessage(Filename,iVar5 != 0,"%s",fmtarg1);
  puVar2 = *(uint **)(plVar1 + 8);
  *puVar2 = (uint)bVar3;
  puVar2[1] = 0x7ff7a501;
  plVar1 = plVar1 + 8;
  *(int *)plVar1 = *(int *)plVar1 + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetPathPoints  @ 4fc51cce  lines 5102-5121

/* WARNING: Function: _alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Unable to track spacebase fully for stack */

int __cdecl LuaBindings::GetPathPoints(lua_State *L)

{
  float fVar1;
  float fVar2;
  bool bVar3;
  char *pcVar4;
  Vector *pVVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 extraout_ECX;
  uint uVar8;
  float fVar9;
  uint bufSize;
  uint local_8;
  
  local_8 = __security_cookie ^ (uint)&stack0xfffffffc;
  uVar8 = 0;
  pcVar4 = (char *)luaL_checklstring((undefined4 *)0x0);
  bufSize = 0;
  ::GetPathPoints(pcVar4,&bufSize,(float *)0x0);
  iVar6 = bufSize * -8;
  *(undefined1 **)(&stack0xffffffd0 + iVar6) = &stack0xffffffd4 + iVar6;
  *(uint **)(&stack0xffffffcc + iVar6) = &bufSize;
  *(char **)(&stack0xffffffc8 + iVar6) = pcVar4;
  *(undefined4 *)(&stack0xffffffc4 + iVar6) = 0x4fc51d1d;
  bVar3 = ::GetPathPoints(*(char **)(&stack0xffffffc8 + iVar6),*(uint **)(&stack0xffffffcc + iVar6),
                          *(float **)(&stack0xffffffd0 + iVar6));
  if (bVar3) {
    *(undefined4 *)(&stack0xffffffd0 + iVar6) = 0;
    *(undefined4 *)(&stack0xffffffcc + iVar6) = 0x4fc51d30;
    lua_createtable(*(int *)(&stack0xffffffd0 + iVar6));
    uVar7 = *(undefined4 *)(&stack0xffffffd0 + iVar6);
    if (bufSize != 0) {
      do {
        *(undefined4 *)(&stack0xffffffd0 + iVar6) = uVar7;
        *(undefined4 *)(&stack0xffffffcc + iVar6) = uVar7;
        fVar1 = *(float *)(&stack0xffffffd8 + uVar8 * 8 + iVar6);
        fVar2 = *(float *)(&stack0xffffffd4 + uVar8 * 8 + iVar6);
        *(float *)(&stack0xffffffd0 + iVar6) = fVar1;
        *(float *)(&stack0xffffffcc + iVar6) = fVar2;
        *(undefined4 *)(&stack0xffffffc8 + iVar6) = 0x4fc51d61;
        fVar9 = ::TerrainFindFloor(*(float *)(&stack0xffffffcc + iVar6),
                                   *(float *)(&stack0xffffffd0 + iVar6));
        *(undefined4 *)(&stack0xffffffc8 + iVar6) = 0x4fc51d76;
        pVVar5 = NewVector(L);
        uVar8 = uVar8 + 1;
        *(uint *)(&stack0xffffffc8 + iVar6) = uVar8;
        *(undefined4 *)(&stack0xffffffc4 + iVar6) = 0xfffffffe;
        pVVar5->x = fVar2;
        pVVar5->y = fVar9;
        pVVar5->z = fVar1;
        *(undefined4 *)(&stack0xffffffc4 + iVar6) = 0x4fc51d8b;
        lua_rawseti(*(int *)(&stack0xffffffc8 + iVar6));
        uVar7 = extraout_ECX;
      } while (uVar8 < bufSize);
    }
    iVar6 = 1;
  }
  else {
    iVar6 = 0;
  }
  return iVar6;
}


// ---------------------------------------------------------------------
// LuaBindings::GetOwner  @ 4fc546fd  lines 5125-5130

int __cdecl LuaBindings::GetOwner(lua_State *L)

{
  int iVar1;
  
  iVar1 = RequireHandle(L,1);
  iVar1 = ::GetOwner(iVar1);
  PushHandle(L,iVar1);
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::SetTarget  @ 4fc49ec5  lines 5134-5143

int __cdecl LuaBindings::SetTarget(lua_State *L)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar1 = RequireHandle(L,1);
  iVar3 = 0;
  uVar2 = lua_type();
  if (uVar2 != 0) {
    iVar3 = RequireHandle(L,2);
  }
  ::SetTarget(iVar1,iVar3);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::SetOwner  @ 4fc4a07a  lines 5148-5157

int __cdecl LuaBindings::SetOwner(lua_State *L)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar1 = RequireHandle(L,1);
  iVar3 = 0;
  uVar2 = lua_type();
  if (uVar2 != 0) {
    iVar3 = RequireHandle(L,2);
  }
  ::SetOwner(iVar1,iVar3);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::SetPilotClass  @ 4fc506c7  lines 5161-5166

int __cdecl LuaBindings::SetPilotClass(lua_State *L)

{
  int iVar1;
  char *pcVar2;
  
  iVar1 = RequireHandle(L,1);
  pcVar2 = (char *)luaL_checklstring((undefined4 *)0x0);
  ::SetPilotClass(iVar1,pcVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::AllowRandomTracks  @ 4fc494d7  lines 5170-5174

int __cdecl LuaBindings::AllowRandomTracks(lua_State *L)

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
// LuaBindings::SetFFATeamColors  @ 4fc5037d  lines 5178-5182

int __cdecl LuaBindings::SetFFATeamColors(lua_State *L)

{
  TEAMCOLOR_TYPE TVar1;
  
  TVar1 = luaL_checkinteger();
  ::SetFFATeamColors(TVar1);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::SetTeamStratColors  @ 4fc49202  lines 5186-5190

int __cdecl LuaBindings::SetTeamStratColors(lua_State *L)

{
  TEAMCOLOR_TYPE TVar1;
  
  TVar1 = luaL_checkinteger();
  ::SetTeamStratColors(TVar1);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::GetFFATeamColor  @ 4fc526d7  lines 5194-5203

int __cdecl LuaBindings::GetFFATeamColor(lua_State *L)

{
  lua_State *plVar1;
  TEAMCOLOR_TYPE TVar2;
  int iVar3;
  int b;
  int g;
  
  plVar1 = L;
  TVar2 = luaL_checkinteger();
  iVar3 = luaL_checkinteger();
  ::GetFFATeamColor(TVar2,iVar3,(int *)&L,&g,&b);
  **(double **)(plVar1 + 8) = (double)(int)L;
  *(int *)(plVar1 + 8) = *(int *)(plVar1 + 8) + 8;
  **(double **)(plVar1 + 8) = (double)g;
  *(int *)(plVar1 + 8) = *(int *)(plVar1 + 8) + 8;
  **(double **)(plVar1 + 8) = (double)b;
  *(int *)(plVar1 + 8) = *(int *)(plVar1 + 8) + 8;
  return 3;
}


// ---------------------------------------------------------------------
// LuaBindings::GetFFATeamColorVector  @ 4fc4ef4a  lines 5206-5211

int __cdecl LuaBindings::GetFFATeamColorVector(lua_State *L)

{
  TEAMCOLOR_TYPE TVar1;
  int iVar2;
  Vector *pVVar3;
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
  pVVar3 = NewVector(L);
  pVVar3->x = fVar4;
  pVVar3->y = fVar5;
  pVVar3->z = fVar6;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetTeamStratColor  @ 4fc5123e  lines 5215-5224

int __cdecl LuaBindings::GetTeamStratColor(lua_State *L)

{
  lua_State *plVar1;
  TEAMCOLOR_TYPE TVar2;
  int iVar3;
  int b;
  int g;
  
  plVar1 = L;
  TVar2 = luaL_checkinteger();
  iVar3 = luaL_checkinteger();
  ::GetTeamStratColor(TVar2,iVar3,(int *)&L,&g,&b);
  **(double **)(plVar1 + 8) = (double)(int)L;
  *(int *)(plVar1 + 8) = *(int *)(plVar1 + 8) + 8;
  **(double **)(plVar1 + 8) = (double)g;
  *(int *)(plVar1 + 8) = *(int *)(plVar1 + 8) + 8;
  **(double **)(plVar1 + 8) = (double)b;
  *(int *)(plVar1 + 8) = *(int *)(plVar1 + 8) + 8;
  return 3;
}


// ---------------------------------------------------------------------
// LuaBindings::GetTeamStratColorVector  @ 4fc4a0ba  lines 5227-5232

int __cdecl LuaBindings::GetTeamStratColorVector(lua_State *L)

{
  TEAMCOLOR_TYPE TVar1;
  int iVar2;
  Vector *pVVar3;
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
  pVVar3 = NewVector(L);
  pVVar3->x = fVar4;
  pVVar3->y = fVar5;
  pVVar3->z = fVar6;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::SwapTeamStratColors  @ 4fc52102  lines 5236-5239

int __cdecl LuaBindings::SwapTeamStratColors(lua_State *__formal)

{
  ::SwapTeamStratColors();
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::GetTeamColorsAreFFA  @ 4fc5140d  lines 5243-5246

int __cdecl LuaBindings::GetTeamColorsAreFFA(lua_State *L)

{
  uint *puVar1;
  bool bVar2;
  
  bVar2 = ::GetTeamColorsAreFFA();
  puVar1 = *(uint **)(L + 8);
  *puVar1 = (uint)bVar2;
  puVar1[1] = 0x7ff7a501;
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::SetTeamColors  @ 4fc51179  lines 5250-5254

int __cdecl LuaBindings::SetTeamColors(lua_State *L)

{
  TEAMCOLOR_TYPE TVar1;
  
  TVar1 = luaL_checkinteger();
  ::SetTeamColors(TVar1);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::AddPower  @ 4fc51085  lines 5258-5263

int __cdecl LuaBindings::AddPower(lua_State *L)

{
  int iVar1;
  int iVar2;
  
  iVar1 = luaL_checkinteger();
  iVar2 = luaL_checkinteger();
  iVar1 = ::AddPower(iVar1,iVar2);
  **(double **)(L + 8) = (double)iVar1;
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::SetPower  @ 4fc51369  lines 5267-5272

int __cdecl LuaBindings::SetPower(lua_State *L)

{
  int iVar1;
  int iVar2;
  
  iVar1 = luaL_checkinteger();
  iVar2 = luaL_checkinteger();
  iVar1 = ::SetPower(iVar1,iVar2);
  **(double **)(L + 8) = (double)iVar1;
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetPower  @ 4fc4eec5  lines 5276-5280

int __cdecl LuaBindings::GetPower(lua_State *L)

{
  int iVar1;
  
  iVar1 = luaL_checkinteger();
  iVar1 = ::GetPower(iVar1);
  **(double **)(L + 8) = (double)iVar1;
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetMaxPower  @ 4fc4bbe9  lines 5284-5288

int __cdecl LuaBindings::GetMaxPower(lua_State *L)

{
  int iVar1;
  
  iVar1 = luaL_checkinteger();
  iVar1 = ::GetMaxPower(iVar1);
  **(double **)(L + 8) = (double)iVar1;
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::AddMaxPower  @ 4fc51b3d  lines 5292-5298

int __cdecl LuaBindings::AddMaxPower(lua_State *L)

{
  int iVar1;
  int iVar2;
  
  iVar1 = luaL_checkinteger();
  iVar2 = luaL_checkinteger();
  ::AddMaxPower(iVar1,iVar2);
  iVar1 = ::GetMaxPower(iVar1);
  **(double **)(L + 8) = (double)iVar1;
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::SetMaxPower  @ 4fc4bc5c  lines 5302-5308

int __cdecl LuaBindings::SetMaxPower(lua_State *L)

{
  int iVar1;
  int iVar2;
  
  iVar1 = luaL_checkinteger();
  iVar2 = luaL_checkinteger();
  ::SetMaxPower(iVar1,iVar2);
  iVar1 = ::GetMaxPower(iVar1);
  **(double **)(L + 8) = (double)iVar1;
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetTeamStratIndividualColor  @ 4fc4c115  lines 5312-5321

int __cdecl LuaBindings::GetTeamStratIndividualColor(lua_State *L)

{
  lua_State *plVar1;
  TEAMCOLOR_TYPE TVar2;
  int iVar3;
  int b;
  int g;
  
  plVar1 = L;
  TVar2 = luaL_checkinteger();
  iVar3 = luaL_checkinteger();
  ::GetTeamStratIndividualColor(TVar2,iVar3,(int *)&L,&g,&b);
  **(double **)(plVar1 + 8) = (double)(int)L;
  *(int *)(plVar1 + 8) = *(int *)(plVar1 + 8) + 8;
  **(double **)(plVar1 + 8) = (double)g;
  *(int *)(plVar1 + 8) = *(int *)(plVar1 + 8) + 8;
  **(double **)(plVar1 + 8) = (double)b;
  *(int *)(plVar1 + 8) = *(int *)(plVar1 + 8) + 8;
  return 3;
}


// ---------------------------------------------------------------------
// LuaBindings::GetTeamStratIndividualColorVector  @ 4fc4a9ab  lines 5324-5329

int __cdecl LuaBindings::GetTeamStratIndividualColorVector(lua_State *L)

{
  TEAMCOLOR_TYPE TVar1;
  int iVar2;
  Vector *pVVar3;
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
  pVVar3 = NewVector(L);
  pVVar3->x = fVar4;
  pVVar3->y = fVar5;
  pVVar3->z = fVar6;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetMapTRNFilename  @ 4fc510f2  lines 5333-5336

int __cdecl LuaBindings::GetMapTRNFilename(lua_State *L)

{
  ::GetMapTRNFilename();
  lua_pushstring();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::IsNotDeadAndPilot  @ 4fc4c7c4  lines 5340-5344

int __cdecl LuaBindings::IsNotDeadAndPilot(lua_State *L)

{
  uint *puVar1;
  bool bVar2;
  int iVar3;
  
  iVar3 = RequireHandle(L,1);
  bVar2 = IsNotDeadAndPilot2(iVar3);
  puVar1 = *(uint **)(L + 8);
  *puVar1 = (uint)bVar2;
  puVar1[1] = 0x7ff7a501;
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetLabel  @ 4fc509b3  lines 5348-5357

int __cdecl LuaBindings::GetLabel(lua_State *L)

{
  int iVar1;
  char *pcVar2;
  
  iVar1 = RequireHandle(L,1);
  pcVar2 = ::GetLabel(iVar1);
  if (pcVar2 == (char *)0x0) {
    *(undefined4 *)(*(int *)(L + 8) + 4) = 0x7ff7a500;
    *(int *)(L + 8) = *(int *)(L + 8) + 8;
  }
  else {
    lua_pushstring();
  }
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::SetLabel  @ 4fc4f2b8  lines 5361-5366

int __cdecl LuaBindings::SetLabel(lua_State *L)

{
  int iVar1;
  char *pcVar2;
  
  iVar1 = RequireHandle(L,1);
  pcVar2 = (char *)luaL_checklstring((undefined4 *)0x0);
  ::SetLabel(iVar1,pcVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::GetTap  @ 4fc53fe1  lines 5370-5376

int __cdecl LuaBindings::GetTap(lua_State *L)

{
  int iVar1;
  int iVar2;
  
  iVar1 = RequireHandle(L,1);
  iVar2 = luaL_checkinteger();
  iVar1 = ::GetTap(iVar1,iVar2);
  PushHandle(L,iVar1);
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::SetTap  @ 4fc50227  lines 5380-5386

int __cdecl LuaBindings::SetTap(lua_State *L)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar1 = RequireHandle(L,1);
  iVar2 = luaL_checkinteger();
  uVar3 = luaL_testudata();
  ::SetTap(iVar1,iVar2,uVar3);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::GetCurLocalAmmo  @ 4fc4ff37  lines 5390-5395

int __cdecl LuaBindings::GetCurLocalAmmo(lua_State *L)

{
  int iVar1;
  int iVar2;
  
  iVar1 = RequireHandle(L,1);
  iVar2 = luaL_checkinteger();
  ::GetCurLocalAmmo(iVar1,iVar2);
  lua_pushnumber();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::AddLocalAmmo  @ 4fc4fec7  lines 5399-5405

int __cdecl LuaBindings::AddLocalAmmo(lua_State *L)

{
  int iVar1;
  int iVar2;
  undefined4 in_XMM0_Da;
  undefined4 in_XMM0_Db;
  
  iVar1 = RequireHandle(L,1);
  luaL_checknumber();
  iVar2 = luaL_checkinteger();
  ::AddLocalAmmo(iVar1,(float)(double)CONCAT44(in_XMM0_Db,in_XMM0_Da),iVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::GetMaxLocalAmmo  @ 4fc49bf6  lines 5409-5414

int __cdecl LuaBindings::GetMaxLocalAmmo(lua_State *L)

{
  int iVar1;
  int iVar2;
  
  iVar1 = RequireHandle(L,1);
  iVar2 = luaL_checkinteger();
  ::GetMaxLocalAmmo(iVar1,iVar2);
  lua_pushnumber();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::SetCurLocalAmmo  @ 4fc4a13a  lines 5418-5424

int __cdecl LuaBindings::SetCurLocalAmmo(lua_State *L)

{
  int iVar1;
  int iVar2;
  undefined4 in_XMM0_Da;
  undefined4 in_XMM0_Db;
  
  iVar1 = RequireHandle(L,1);
  luaL_checknumber();
  iVar2 = luaL_checkinteger();
  ::SetCurLocalAmmo(iVar1,(float)(double)CONCAT44(in_XMM0_Db,in_XMM0_Da),iVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::GetNetworkListItem  @ 4fc4eafa  lines 5428-5439

int __cdecl LuaBindings::GetNetworkListItem(lua_State *L)

{
  NETWORK_LIST_TYPE NVar1;
  uint uVar2;
  char *pcVar3;
  
  NVar1 = luaL_checkinteger();
  uVar2 = luaL_checkinteger();
  pcVar3 = ::GetNetworkListItem(NVar1,uVar2);
  if (pcVar3 == (char *)0x0) {
    *(undefined4 *)(*(int *)(L + 8) + 4) = 0x7ff7a500;
    *(int *)(L + 8) = *(int *)(L + 8) + 8;
  }
  else {
    lua_pushstring();
  }
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetNetworkListCount  @ 4fc4f7ae  lines 5443-5447

int __cdecl LuaBindings::GetNetworkListCount(lua_State *L)

{
  NETWORK_LIST_TYPE NVar1;
  uint uVar2;
  
  NVar1 = luaL_checkinteger();
  uVar2 = ::GetNetworkListCount(NVar1);
  **(double **)(L + 8) = (double)(int)uVar2;
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetTeamRelationship  @ 4fc51e4f  lines 5451-5456

int __cdecl LuaBindings::GetTeamRelationship(lua_State *L)

{
  int iVar1;
  int iVar2;
  
  iVar1 = RequireHandle(L,1);
  iVar2 = RequireHandle(L,2);
  ::GetTeamRelationship(iVar1,iVar2);
  lua_pushnumber();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::HasPilot  @ 4fc513ab  lines 5460-5464

int __cdecl LuaBindings::HasPilot(lua_State *L)

{
  uint *puVar1;
  bool bVar2;
  int iVar3;
  
  iVar3 = RequireHandle(L,1);
  bVar2 = ::HasPilot(iVar3);
  puVar1 = *(uint **)(L + 8);
  *puVar1 = (uint)bVar2;
  puVar1[1] = 0x7ff7a501;
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetPilotClass  @ 4fc4a649  lines 5468-5477

int __cdecl LuaBindings::GetPilotClass(lua_State *L)

{
  int iVar1;
  char *pcVar2;
  
  iVar1 = RequireHandle(L,1);
  pcVar2 = ::GetPilotClass(iVar1);
  if (pcVar2 == (char *)0x0) {
    *(undefined4 *)(*(int *)(L + 8) + 4) = 0x7ff7a500;
    *(int *)(L + 8) = *(int *)(L + 8) + 8;
  }
  else {
    lua_pushstring();
  }
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetBaseScrapCost  @ 4fc53eca  lines 5481-5485

int __cdecl LuaBindings::GetBaseScrapCost(lua_State *L)

{
  int iVar1;
  
  iVar1 = RequireHandle(L,1);
  iVar1 = ::GetBaseScrapCost(iVar1);
  **(double **)(L + 8) = (double)iVar1;
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetActualScrapCost  @ 4fc4a2b3  lines 5489-5493

int __cdecl LuaBindings::GetActualScrapCost(lua_State *L)

{
  int iVar1;
  
  iVar1 = RequireHandle(L,1);
  iVar1 = ::GetActualScrapCost(iVar1);
  **(double **)(L + 8) = (double)iVar1;
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::PetWatchdogThread  @ 4fc4f094  lines 5497-5500

int __cdecl LuaBindings::PetWatchdogThread(lua_State *__formal)

{
  ::PetWatchdogThread();
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::GetPerceivedTeam  @ 4fc492a7  lines 5504-5508

int __cdecl LuaBindings::GetPerceivedTeam(lua_State *L)

{
  int iVar1;
  
  iVar1 = RequireHandle(L,1);
  iVar1 = ::GetPerceivedTeam(iVar1);
  **(double **)(L + 8) = (double)iVar1;
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::SetLastCurrentPosition  @ 4fc4e139  lines 5512-5530

int __cdecl LuaBindings::SetLastCurrentPosition(lua_State *L)

{
  int iVar1;
  Matrix *pMVar2;
  int iVar3;
  Matrix *pMVar4;
  Matrix local_88;
  Matrix local_48;
  
  iVar1 = RequireHandle(L,1);
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
// LuaBindings::GetRemainingLifespan  @ 4fc4ccaf  lines 5534-5542

int __cdecl LuaBindings::GetRemainingLifespan(lua_State *L)

{
  int iVar1;
  float fVar2;
  
  iVar1 = RequireHandle(L,1);
  fVar2 = ::GetRemainingLifespan(iVar1);
  if (fVar2 == -1.0) {
    *(undefined4 *)(*(int *)(L + 8) + 4) = 0x7ff7a500;
    *(int *)(L + 8) = *(int *)(L + 8) + 8;
  }
  else {
    lua_pushnumber();
  }
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetAllSpawnpoints  @ 4fc5199e  lines 5546-5574

int __cdecl LuaBindings::GetAllSpawnpoints(lua_State *L)

{
  float *pfVar1;
  uint uVar2;
  int iVar3;
  Vector *pVVar4;
  SpawnpointInfo *local_28;
  uint info;
  int local_20;
  uint local_1c;
  float local_18;
  float fStack_14;
  float fStack_10;
  
  uVar2 = lua_type();
  info = 0;
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
      pVVar4 = NewVector(L);
      pVVar4->x = local_18;
      pVVar4->y = fStack_14;
      pVVar4->z = fStack_10;
      lua_setfield();
      iVar3 = local_20;
      **(double **)(L + 8) = (double)*(int *)((int)&local_28->m_Team + local_20);
      *(int *)(L + 8) = *(int *)(L + 8) + 8;
      lua_setfield();
      PushHandle(L,*(int *)((int)&local_28->m_Handle + iVar3));
      lua_setfield();
      lua_pushnumber();
      lua_setfield();
      lua_pushnumber();
      lua_setfield();
      lua_pushnumber();
      lua_setfield();
      lua_pushnumber();
      lua_setfield();
      uVar2 = info + 1;
      info = uVar2;
      lua_rawseti(uVar2);
      local_20 = iVar3 + 0x24;
    } while (uVar2 < local_1c);
  }
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetPlan  @ 4fc5382d  lines 5578-5587

int __cdecl LuaBindings::GetPlan(lua_State *L)

{
  int iVar1;
  char *pcVar2;
  
  iVar1 = luaL_checkinteger();
  pcVar2 = ::GetPlan(iVar1);
  if (pcVar2 == (char *)0x0) {
    *(undefined4 *)(*(int *)(L + 8) + 4) = 0x7ff7a500;
    *(int *)(L + 8) = *(int *)(L + 8) + 8;
  }
  else {
    lua_pushstring();
  }
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetIndependence  @ 4fc4b24d  lines 5591-5599

int __cdecl LuaBindings::GetIndependence(lua_State *L)

{
  int iVar1;
  
  iVar1 = RequireHandle(L,1);
  iVar1 = ::GetIndependence(iVar1);
  if (iVar1 == -1) {
    *(undefined4 *)((int)*(double **)(L + 8) + 4) = 0x7ff7a500;
  }
  else {
    **(double **)(L + 8) = (double)iVar1;
  }
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetSkill  @ 4fc4a016  lines 5603-5611

int __cdecl LuaBindings::GetSkill(lua_State *L)

{
  int iVar1;
  
  iVar1 = RequireHandle(L,1);
  iVar1 = ::GetSkill(iVar1);
  if (iVar1 == -1) {
    *(undefined4 *)((int)*(double **)(L + 8) + 4) = 0x7ff7a500;
  }
  else {
    **(double **)(L + 8) = (double)iVar1;
  }
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetObjectiveName  @ 4fc51e13  lines 5615-5624

int __cdecl LuaBindings::GetObjectiveName(lua_State *L)

{
  int iVar1;
  char *pcVar2;
  
  iVar1 = RequireHandle(L,1);
  pcVar2 = ::GetObjectiveName(iVar1);
  if (pcVar2 == (char *)0x0) {
    *(undefined4 *)(*(int *)(L + 8) + 4) = 0x7ff7a500;
    *(int *)(L + 8) = *(int *)(L + 8) + 8;
  }
  else {
    lua_pushstring();
  }
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetWeaponMask  @ 4fc4f384  lines 5628-5632

int __cdecl LuaBindings::GetWeaponMask(lua_State *L)

{
  int iVar1;
  
  iVar1 = RequireHandle(L,1);
  ::GetWeaponMask(iVar1);
  lua_pushnumber();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::SetInterpolablePosition  @ 4fc4c651  lines 5637-5659

int __cdecl LuaBindings::SetInterpolablePosition(lua_State *L)

{
  int iVar1;
  Matrix *pMVar2;
  uint uVar3;
  int iVar4;
  Matrix *pMVar5;
  Vector *pVVar6;
  Vector *pVVar7;
  
  iVar1 = RequireHandle(L,1);
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
// LuaBindings::SecondsToTurns  @ 4fc542b2  lines 5663-5667

int __cdecl LuaBindings::SecondsToTurns(lua_State *L)

{
  double in_XMM0_Qa;
  
  luaL_checknumber();
  ::SecondsToTurns((float)in_XMM0_Qa);
  lua_pushnumber();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::TurnsToSeconds  @ 4fc4f0c1  lines 5670-5674

int __cdecl LuaBindings::TurnsToSeconds(lua_State *L)

{
  int iVar1;
  
  iVar1 = luaL_checkinteger();
  ::TurnsToSeconds(iVar1);
  lua_pushnumber();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetLifeSpan  @ 4fc4aa2b  lines 5678-5686

int __cdecl LuaBindings::GetLifeSpan(lua_State *L)

{
  int iVar1;
  float fVar2;
  
  iVar1 = RequireHandle(L,1);
  fVar2 = ::GetLifeSpan(iVar1);
  if (fVar2 == -1.0) {
    *(undefined4 *)(*(int *)(L + 8) + 4) = 0x7ff7a500;
    *(int *)(L + 8) = *(int *)(L + 8) + 8;
  }
  else {
    lua_pushnumber();
  }
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetCurrentCommandWhere  @ 4fc51c8f  lines 5690-5694

int __cdecl LuaBindings::GetCurrentCommandWhere(lua_State *L)

{
  int iVar1;
  Vector *pVVar2;
  Vector local_1c;
  float local_10;
  float fStack_c;
  float fStack_8;
  
  iVar1 = RequireHandle(L,1);
  pVVar2 = ::GetCurrentCommandWhere(&local_1c,iVar1);
  local_10 = pVVar2->x;
  fStack_c = pVVar2->y;
  fStack_8 = pVVar2->z;
  pVVar2 = NewVector(L);
  pVVar2->x = local_10;
  pVVar2->y = fStack_c;
  pVVar2->z = fStack_8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetAllGameObjectHandles  @ 4fc52751  lines 5698-5713

/* WARNING: Function: _alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Unable to track spacebase fully for stack */

int __cdecl LuaBindings::GetAllGameObjectHandles(lua_State *L)

{
  int h;
  uint uVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  undefined4 uStackY_20;
  uint bufSize;
  uint local_8;
  
  local_8 = __security_cookie ^ (uint)&stack0xfffffffc;
  uVar4 = 0;
  bufSize = 0;
  uStackY_20 = 0x4fc52772;
  ::GetAllGameObjectHandles(&bufSize,(int *)0x0);
  uVar1 = bufSize;
  iVar3 = bufSize * -4;
  *(undefined1 **)(&stack0xffffffe8 + iVar3) = &stack0xffffffec + iVar3;
  *(uint **)(&stack0xffffffe4 + iVar3) = &bufSize;
  (&uStackY_20)[-uVar1] = 0x4fc5278c;
  bVar2 = ::GetAllGameObjectHandles
                    (*(uint **)(&stack0xffffffe4 + iVar3),*(int **)(&stack0xffffffe8 + iVar3));
  if (bVar2) {
    *(undefined4 *)(&stack0xffffffe8 + iVar3) = 0;
    *(undefined4 *)(&stack0xffffffe4 + iVar3) = 0x4fc5279e;
    lua_createtable(*(int *)(&stack0xffffffe8 + iVar3));
    if (bufSize != 0) {
      do {
        h = *(int *)(&stack0xffffffec + uVar4 * 4 + iVar3);
        *(undefined4 *)(&stack0xffffffe8 + iVar3) = 0x4fc527af;
        PushHandle(L,h);
        uVar4 = uVar4 + 1;
        *(uint *)(&stack0xffffffe8 + iVar3) = uVar4;
        *(undefined4 *)(&stack0xffffffe4 + iVar3) = 0xfffffffe;
        *(undefined4 *)(&stack0xffffffe4 + iVar3) = 0x4fc527b9;
        lua_rawseti(*(int *)(&stack0xffffffe8 + iVar3));
      } while (uVar4 < bufSize);
    }
    iVar3 = 1;
  }
  else {
    iVar3 = 0;
  }
  return iVar3;
}


// ---------------------------------------------------------------------
// LuaBindings::GetOmega  @ 4fc4e620  lines 5717-5721

int __cdecl LuaBindings::GetOmega(lua_State *L)

{
  int iVar1;
  Vector *pVVar2;
  Vector local_1c;
  float local_10;
  float fStack_c;
  float fStack_8;
  
  iVar1 = RequireHandle(L,1);
  pVVar2 = ::GetOmega(&local_1c,iVar1);
  local_10 = pVVar2->x;
  fStack_c = pVVar2->y;
  fStack_8 = pVVar2->z;
  pVVar2 = NewVector(L);
  pVVar2->x = local_10;
  pVVar2->y = fStack_c;
  pVVar2->z = fStack_8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::SetOmega  @ 4fc5202d  lines 5725-5731

int __cdecl LuaBindings::SetOmega(lua_State *L)

{
  int iVar1;
  Vector *pVVar2;
  
  iVar1 = RequireHandle(L,1);
  pVVar2 = (Vector *)luaL_checkudata();
  ::SetOmega(iVar1,pVVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::IsCraftButNotPerson  @ 4fc4ece7  lines 5735-5739

int __cdecl LuaBindings::IsCraftButNotPerson(lua_State *L)

{
  uint *puVar1;
  bool bVar2;
  int iVar3;
  
  iVar3 = RequireHandle(L,1);
  bVar2 = ::IsCraftButNotPerson(iVar3);
  puVar1 = *(uint **)(L + 8);
  *puVar1 = (uint)bVar2;
  puVar1[1] = 0x7ff7a501;
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::IsCraftOrPerson  @ 4fc4b18b  lines 5743-5747

int __cdecl LuaBindings::IsCraftOrPerson(lua_State *L)

{
  uint *puVar1;
  bool bVar2;
  int iVar3;
  
  iVar3 = RequireHandle(L,1);
  bVar2 = ::IsCraftOrPerson(iVar3);
  puVar1 = *(uint **)(L + 8);
  *puVar1 = (uint)bVar2;
  puVar1[1] = 0x7ff7a501;
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::IsBuilding  @ 4fc50397  lines 5751-5755

int __cdecl LuaBindings::IsBuilding(lua_State *L)

{
  uint *puVar1;
  bool bVar2;
  int iVar3;
  
  iVar3 = RequireHandle(L,1);
  bVar2 = ::IsBuilding(iVar3);
  puVar1 = *(uint **)(L + 8);
  *puVar1 = (uint)bVar2;
  puVar1[1] = 0x7ff7a501;
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::IsPowerup  @ 4fc4f729  lines 5759-5763

int __cdecl LuaBindings::IsPowerup(lua_State *L)

{
  uint *puVar1;
  bool bVar2;
  int iVar3;
  
  iVar3 = RequireHandle(L,1);
  bVar2 = ::IsPowerup(iVar3);
  puVar1 = *(uint **)(L + 8);
  *puVar1 = (uint)bVar2;
  puVar1[1] = 0x7ff7a501;
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::SetCanSnipe  @ 4fc4d6a9  lines 5767-5772

int __cdecl LuaBindings::SetCanSnipe(lua_State *L)

{
  int iVar1;
  int iVar2;
  
  iVar1 = RequireHandle(L,1);
  iVar2 = luaL_checkinteger();
  ::SetCanSnipe(iVar1,iVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::GetCanSnipe  @ 4fc4bca6  lines 5776-5780

int __cdecl LuaBindings::GetCanSnipe(lua_State *L)

{
  uint *puVar1;
  bool bVar2;
  int iVar3;
  
  iVar3 = RequireHandle(L,1);
  bVar2 = ::GetCanSnipe(iVar3);
  puVar1 = *(uint **)(L + 8);
  *puVar1 = (uint)bVar2;
  puVar1[1] = 0x7ff7a501;
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::WhoIsTargeting  @ 4fc52939  lines 5784-5800

/* WARNING: Function: _alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Unable to track spacebase fully for stack */

int __cdecl LuaBindings::WhoIsTargeting(lua_State *L)

{
  uint uVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 uStackY_2c;
  uint bufSize;
  uint local_8;
  
  local_8 = __security_cookie ^ (uint)&stack0xfffffffc;
  iVar3 = RequireHandle(L,1);
  uVar5 = 0;
  bufSize = 0;
  uStackY_2c = 0x4fc5296c;
  ::WhoIsTargeting(&bufSize,(int *)0x0,iVar3);
  uVar1 = bufSize;
  iVar4 = bufSize * -4;
  *(int *)(&stack0xffffffe0 + iVar4) = iVar3;
  *(undefined1 **)(&stack0xffffffdc + iVar4) = &stack0xffffffe4 + iVar4;
  *(uint **)(&stack0xffffffd8 + iVar4) = &bufSize;
  (&uStackY_2c)[-uVar1] = 0x4fc52987;
  bVar2 = ::WhoIsTargeting(*(uint **)(&stack0xffffffd8 + iVar4),*(int **)(&stack0xffffffdc + iVar4),
                           *(int *)(&stack0xffffffe0 + iVar4));
  if (bVar2) {
    *(undefined4 *)(&stack0xffffffe0 + iVar4) = 0;
    *(undefined4 *)(&stack0xffffffdc + iVar4) = 0x4fc5299a;
    lua_createtable(*(int *)(&stack0xffffffe0 + iVar4));
    if (bufSize != 0) {
      do {
        iVar3 = *(int *)(&stack0xffffffe4 + uVar5 * 4 + iVar4);
        *(undefined4 *)(&stack0xffffffe0 + iVar4) = 0x4fc529ae;
        PushHandle(L,iVar3);
        uVar5 = uVar5 + 1;
        *(uint *)(&stack0xffffffe0 + iVar4) = uVar5;
        *(undefined4 *)(&stack0xffffffdc + iVar4) = 0xfffffffe;
        *(undefined4 *)(&stack0xffffffdc + iVar4) = 0x4fc529b8;
        lua_rawseti(*(int *)(&stack0xffffffe0 + iVar4));
      } while (uVar5 < bufSize);
    }
    iVar4 = 1;
  }
  else {
    iVar4 = 0;
  }
  return iVar4;
}


// ---------------------------------------------------------------------
// LuaBindings::GetPilotOdf  @ 4fc4bbad  lines 5804-5813

int __cdecl LuaBindings::GetPilotOdf(lua_State *L)

{
  int iVar1;
  char *pcVar2;
  
  iVar1 = RequireHandle(L,1);
  pcVar2 = ::GetPilotOdf(iVar1);
  if (pcVar2 == (char *)0x0) {
    *(undefined4 *)(*(int *)(L + 8) + 4) = 0x7ff7a500;
    *(int *)(L + 8) = *(int *)(L + 8) + 8;
  }
  else {
    lua_pushstring();
  }
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::SetTeamNameForStat  @ 4fc4e3c2  lines 5817-5822

int __cdecl LuaBindings::SetTeamNameForStat(lua_State *L)

{
  int iVar1;
  char *pcVar2;
  
  iVar1 = luaL_checkinteger();
  pcVar2 = (char *)luaL_checklstring((undefined4 *)0x0);
  ::SetTeamNameForStat(iVar1,pcVar2);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::CanBuild  @ 4fc53d13  lines 5826-5830

int __cdecl LuaBindings::CanBuild(lua_State *L)

{
  uint *puVar1;
  bool bVar2;
  int iVar3;
  
  iVar3 = RequireHandle(L,1);
  bVar2 = ::CanBuild(iVar3);
  puVar1 = *(uint **)(L + 8);
  *puVar1 = (uint)bVar2;
  puVar1[1] = 0x7ff7a501;
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::IsBusy  @ 4fc4a5ec  lines 5834-5838

int __cdecl LuaBindings::IsBusy(lua_State *L)

{
  uint *puVar1;
  bool bVar2;
  int iVar3;
  
  iVar3 = RequireHandle(L,1);
  bVar2 = ::IsBusy(iVar3);
  puVar1 = *(uint **)(L + 8);
  *puVar1 = (uint)bVar2;
  puVar1[1] = 0x7ff7a501;
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetBuildClass  @ 4fc4cebf  lines 5843-5852

int __cdecl LuaBindings::GetBuildClass(lua_State *L)

{
  int iVar1;
  char *pcVar2;
  
  iVar1 = RequireHandle(L,1);
  pcVar2 = ::GetBuildClass(iVar1);
  if (pcVar2 == (char *)0x0) {
    *(undefined4 *)(*(int *)(L + 8) + 4) = 0x7ff7a500;
    *(int *)(L + 8) = *(int *)(L + 8) + 8;
  }
  else {
    lua_pushstring();
  }
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetQueuedItem  @ 4fc49af7  lines 5856-5866

int __cdecl LuaBindings::GetQueuedItem(lua_State *L)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  
  iVar1 = RequireHandle(L,1);
  uVar2 = lua_type();
  if ((int)uVar2 < 1) {
    iVar3 = 0;
  }
  else {
    iVar3 = luaL_checkinteger();
  }
  pcVar4 = ::GetQueuedItem(iVar1,iVar3);
  if (pcVar4 == (char *)0x0) {
    *(undefined4 *)(*(int *)(L + 8) + 4) = 0x7ff7a500;
    *(int *)(L + 8) = *(int *)(L + 8) + 8;
  }
  else {
    lua_pushstring();
  }
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetMissionFilename  @ 4fc4efca  lines 5870-5873

int __cdecl LuaBindings::GetMissionFilename(lua_State *L)

{
  ::GetMissionFilename();
  lua_pushstring();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetEjectRatio  @ 4fc49fc0  lines 5877-5885

int __cdecl LuaBindings::GetEjectRatio(lua_State *L)

{
  int iVar1;
  float fVar2;
  
  iVar1 = RequireHandle(L,1);
  fVar2 = ::GetEjectRatio(iVar1);
  if (fVar2 == -1.0) {
    *(undefined4 *)(*(int *)(L + 8) + 4) = 0x7ff7a500;
    *(int *)(L + 8) = *(int *)(L + 8) + 8;
  }
  else {
    lua_pushnumber();
  }
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::SetEjectRatio  @ 4fc4a3ec  lines 5889-5894

int __cdecl LuaBindings::SetEjectRatio(lua_State *L)

{
  int iVar1;
  undefined4 in_XMM0_Da;
  undefined4 in_XMM0_Db;
  
  iVar1 = RequireHandle(L,1);
  luaL_checknumber();
  ::SetEjectRatio(iVar1,(float)(double)CONCAT44(in_XMM0_Db,in_XMM0_Da));
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::GetLookFront  @ 4fc4f634  lines 5898-5902

int __cdecl LuaBindings::GetLookFront(lua_State *L)

{
  int iVar1;
  Vector *pVVar2;
  Vector local_10;
  
  iVar1 = RequireHandle(L,1);
  ::GetLookFront(iVar1,&local_10);
  pVVar2 = NewVector(L);
  pVVar2->x = local_10.x;
  pVVar2->y = local_10.y;
  pVVar2->z = local_10.z;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::PauseAnimation  @ 4fc50d40  lines 5906-5910

int __cdecl LuaBindings::PauseAnimation(lua_State *L)

{
  int iVar1;
  
  iVar1 = RequireHandle(L,1);
  ::PauseAnimation(iVar1);
  lua_pushnumber();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::ResumeAnimation  @ 4fc54171  lines 5914-5919

int __cdecl LuaBindings::ResumeAnimation(lua_State *L)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = 1;
  iVar1 = RequireHandle(L,1);
  uVar2 = lua_type();
  if (0 < (int)uVar2) {
    iVar3 = luaL_checkinteger();
  }
  ::ResumeAnimation(iVar1,iVar3);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::GetAnimationDirection  @ 4fc4b1bd  lines 5923-5927

int __cdecl LuaBindings::GetAnimationDirection(lua_State *L)

{
  int iVar1;
  
  iVar1 = RequireHandle(L,1);
  ::GetAnimationDirection(iVar1);
  lua_pushnumber();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::IsPowered  @ 4fc4c75f  lines 5931-5935

int __cdecl LuaBindings::IsPowered(lua_State *L)

{
  uint *puVar1;
  bool bVar2;
  int iVar3;
  
  iVar3 = RequireHandle(L,1);
  bVar2 = ::IsPowered(iVar3);
  puVar1 = *(uint **)(L + 8);
  *puVar1 = (uint)bVar2;
  puVar1[1] = 0x7ff7a501;
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetEmitterMask  @ 4fc4fcc1  lines 5939-5943

int __cdecl LuaBindings::GetEmitterMask(lua_State *L)

{
  int iVar1;
  
  iVar1 = RequireHandle(L,1);
  ::GetEmitterMask(iVar1);
  lua_pushnumber();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::IsEmitterOn  @ 4fc4b2e1  lines 5947-5952

int __cdecl LuaBindings::IsEmitterOn(lua_State *L)

{
  uint *puVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = RequireHandle(L,1);
  iVar4 = luaL_checkinteger();
  bVar2 = ::IsEmitterOn(iVar3,iVar4);
  puVar1 = *(uint **)(L + 8);
  *puVar1 = (uint)bVar2;
  puVar1[1] = 0x7ff7a501;
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::IFace_EnterMenuMode  @ 4fc4ca1d  lines 5956-5959

int __cdecl LuaBindings::IFace_EnterMenuMode(lua_State *__formal)

{
  ::IFace_EnterMenuMode();
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::IFace_ExitMenuMode  @ 4fc4a985  lines 5963-5966

int __cdecl LuaBindings::IFace_ExitMenuMode(lua_State *__formal)

{
  ::IFace_ExitMenuMode();
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::DoTaunt  @ 4fc4bae5  lines 5973-5977

int __cdecl LuaBindings::DoTaunt(lua_State *L)

{
  int Taunt;
  
  Taunt = luaL_checkinteger();
  ::DoTaunt(Taunt);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::SetTauntCPUName  @ 4fc4b28d  lines 5981-5985

int __cdecl LuaBindings::SetTauntCPUName(lua_State *L)

{
  char *_Format;
  
  _Format = (char *)luaL_checklstring((undefined4 *)0x0);
  sprintf_s<256>(&CPUTeamName,_Format);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::SetAngle  @ 4fc4f75b  lines 5994-5999

int __cdecl LuaBindings::SetAngle(lua_State *L)

{
  int h;
  undefined4 in_XMM0_Da;
  undefined4 in_XMM0_Db;
  
  h = RequireHandle(L,1);
  luaL_checknumber();
  ::SetAngle(h,(float)(double)CONCAT44(in_XMM0_Db,in_XMM0_Da));
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::CameraPos  @ 4fc53e42  lines 6003-6011

int __cdecl LuaBindings::CameraPos(lua_State *L)

{
  uint *puVar1;
  bool bVar2;
  int me;
  int him;
  Vector *PosA;
  Vector *PosB;
  undefined4 in_XMM0_Da;
  undefined4 in_XMM0_Db;
  
  me = RequireHandle(L,1);
  him = RequireHandle(L,2);
  PosA = (Vector *)luaL_checkudata();
  PosB = (Vector *)luaL_checkudata();
  luaL_checknumber();
  bVar2 = ::CameraPos(me,him,PosA,PosB,(float)(double)CONCAT44(in_XMM0_Db,in_XMM0_Da));
  puVar1 = *(uint **)(L + 8);
  *puVar1 = (uint)bVar2;
  puVar1[1] = 0x7ff7a501;
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::CameraOf  @ 4fc4c931  lines 6015-6027

int __cdecl LuaBindings::CameraOf(lua_State *L)

{
  int me;
  Vector *Offset;
  undefined4 in_XMM0_Da;
  undefined4 in_XMM0_Db;
  Vector local_14;
  
  me = RequireHandle(L,1);
  Offset = (Vector *)luaL_testudata();
  if (Offset == (Vector *)0x0) {
    local_14.x = 0.0;
    local_14.y = 0.0;
    luaL_checknumber();
    local_14.z = (float)(double)CONCAT44(in_XMM0_Db,in_XMM0_Da);
    Offset = &local_14;
  }
  ::CameraOf(me,Offset);
  return 0;
}


// ---------------------------------------------------------------------
// LuaBindings::Move  @ 4fc49392  lines 6032-6047

int __cdecl LuaBindings::Move(lua_State *L)

{
  uint *puVar1;
  bool bVar2;
  uint uVar3;
  undefined1 unaff_SI;
  float unaff_EDI;
  undefined4 in_XMM0_Da;
  float fVar4;
  float fVar5;
  undefined4 in_XMM0_Db;
  float fVar6;
  Vector *pVVar7;
  
  RequireHandle(L,1);
  luaL_checknumber();
  fVar4 = (float)(double)CONCAT44(in_XMM0_Db,in_XMM0_Da);
  fVar6 = 6.5960417e+09;
  fVar5 = fVar4;
  uVar3 = luaL_testudata();
  pVVar7 = (Vector *)0x4fc493db;
  luaL_checknumber();
  if (uVar3 == 0) {
    bVar2 = ::Move((int)fVar4,(float)(double)CONCAT44(in_XMM0_Db,fVar5),unaff_EDI,(bool)unaff_SI);
    puVar1 = *(uint **)(L + 8);
    *puVar1 = (uint)bVar2;
    puVar1[1] = 0x7ff7a501;
  }
  else {
    bVar2 = ::Move((int)fVar4,(float)(double)CONCAT44(in_XMM0_Db,fVar5),fVar6,pVVar7,
                   SUB41(unaff_EDI,0),(bool)unaff_SI);
    puVar1 = *(uint **)(L + 8);
    *puVar1 = (uint)bVar2;
    puVar1[1] = 0x7ff7a501;
  }
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::ReplaceObject  @ 4fc52e7c  lines 6051-6070

int __cdecl LuaBindings::ReplaceObject(lua_State *L)

{
  Vector NewWhere;
  int iVar1;
  char *ODF;
  int Team;
  int Empty;
  uint uVar2;
  int iVar3;
  int Group;
  int CanSnipe;
  int iVar4;
  int NewCommand;
  int Priority;
  undefined4 *puVar5;
  undefined4 in_XMM0_Da;
  undefined4 in_XMM0_Db;
  undefined4 local_14;
  undefined4 newwhere;
  float local_c;
  
  iVar1 = RequireHandle(L,1);
  ODF = luaL_optlstring((char *)0x0,(int *)0x0);
  Team = luaL_optinteger(0xffffffff);
  luaL_optnumber();
  Empty = luaL_optinteger(0xffffffff);
  uVar2 = lua_type();
  if ((int)uVar2 < 1) {
    iVar3 = 1;
  }
  else {
    iVar3 = lua_toboolean();
  }
  Group = luaL_optinteger(0xffffffff);
  CanSnipe = luaL_optinteger(0xffffffff);
  uVar2 = lua_type();
  if ((int)uVar2 < 1) {
    iVar4 = 1;
  }
  else {
    iVar4 = lua_toboolean();
  }
  NewCommand = luaL_optinteger(0xffffffff);
  Priority = luaL_optinteger(0);
  uVar2 = luaL_testudata();
  local_14 = 0;
  newwhere = 0;
  local_c = 0.0;
  puVar5 = (undefined4 *)luaL_testudata();
  if (puVar5 != (undefined4 *)0x0) {
    local_14 = *puVar5;
    newwhere = puVar5[1];
    local_c = (float)puVar5[2];
  }
  NewWhere.y = (float)newwhere;
  NewWhere.x = (float)local_14;
  NewWhere.z = local_c;
  iVar1 = BZ1Helper::ReplaceObject
                    (BZ1Helper::m_BZ1Helper,iVar1,ODF,Team,
                     (float)(double)CONCAT44(in_XMM0_Db,in_XMM0_Da),Empty,iVar3 != 0,Group,CanSnipe,
                     iVar4 != 0,NewCommand,Priority,uVar2,NewWhere);
  PushHandle(L,iVar1);
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::CanCommand  @ 4fc52a3a  lines 6078-6082

int __cdecl LuaBindings::CanCommand(lua_State *L)

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
            goto LAB_4fc52a98;
          }
        }
      }
    }
  }
  uVar5 = 0;
LAB_4fc52a98:
  puVar1 = *(undefined4 **)(L + 8);
  *puVar1 = uVar5;
  puVar1[1] = 0x7ff7a501;
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetTransform  @ 4fc4fe77  lines 6086-6090

int __cdecl LuaBindings::GetTransform(lua_State *L)

{
  int iVar1;
  Matrix *pMVar2;
  float *pfVar3;
  Matrix local_88;
  float local_48 [17];
  
  iVar1 = RequireHandle(L,1);
  ::GetPosition(iVar1,&local_88);
  pMVar2 = &local_88;
  pfVar3 = local_48;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *pfVar3 = (pMVar2->right).x;
    pMVar2 = (Matrix *)&(pMVar2->right).y;
    pfVar3 = pfVar3 + 1;
  }
  pMVar2 = NewMatrix(L);
  pfVar3 = local_48;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    (pMVar2->right).x = *pfVar3;
    pfVar3 = pfVar3 + 1;
    pMVar2 = (Matrix *)&(pMVar2->right).y;
  }
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetTransform2  @ 4fc544e2  lines 6094-6098

int __cdecl LuaBindings::GetTransform2(lua_State *L)

{
  int iVar1;
  Matrix *pMVar2;
  float *pfVar3;
  Matrix local_88;
  float local_48 [17];
  
  iVar1 = RequireHandle(L,1);
  ::GetPosition2(iVar1,&local_88);
  pMVar2 = &local_88;
  pfVar3 = local_48;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *pfVar3 = (pMVar2->right).x;
    pMVar2 = (Matrix *)&(pMVar2->right).y;
    pfVar3 = pfVar3 + 1;
  }
  pMVar2 = NewMatrix(L);
  pfVar3 = local_48;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    (pMVar2->right).x = *pfVar3;
    pfVar3 = pfVar3 + 1;
    pMVar2 = (Matrix *)&(pMVar2->right).y;
  }
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::SetTransform  @ 4fc4ebc7  lines 6104-6123

int __cdecl LuaBindings::SetTransform(lua_State *L)

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
  
  iVar1 = RequireHandle(L,1);
  pMVar2 = (Matrix *)luaL_testudata();
  if (pMVar2 == (Matrix *)0x0) {
    iVar3 = lua_isstring();
    if (iVar3 == 0) {
      iVar3 = RequireHandle(L,2);
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
// LuaBindings::GetRecyclerHandle  @ 4fc50076  lines 6128-6132

int __cdecl LuaBindings::GetRecyclerHandle(lua_State *L)

{
  int iVar1;
  
  iVar1 = ::GetLocalPlayerTeamNumber();
  iVar1 = luaL_optinteger(iVar1);
  iVar1 = ::GetObjectByTeamSlot(iVar1,1);
  PushHandle(L,iVar1);
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetFactoryHandle  @ 4fc513dd  lines 6136-6140

int __cdecl LuaBindings::GetFactoryHandle(lua_State *L)

{
  int iVar1;
  
  iVar1 = ::GetLocalPlayerTeamNumber();
  iVar1 = luaL_optinteger(iVar1);
  iVar1 = ::GetObjectByTeamSlot(iVar1,2);
  PushHandle(L,iVar1);
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetArmoryHandle  @ 4fc49f2d  lines 6144-6148

int __cdecl LuaBindings::GetArmoryHandle(lua_State *L)

{
  int iVar1;
  
  iVar1 = ::GetLocalPlayerTeamNumber();
  iVar1 = luaL_optinteger(iVar1);
  iVar1 = ::GetObjectByTeamSlot(iVar1,3);
  PushHandle(L,iVar1);
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetTimeStep  @ 4fc49f05  lines 6152-6155

int __cdecl LuaBindings::GetTimeStep(lua_State *L)

{
  ::TurnsToSeconds(1);
  lua_pushnumber();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::IsInsideArea  @ 4fc4f44a  lines 6162-6180

int __cdecl LuaBindings::IsInsideArea(lua_State *L)

{
  uint *puVar1;
  char *path;
  undefined4 *puVar2;
  Vector *pVVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 local_50 [12];
  Vector local_20;
  Vector local_10;
  
  path = (char *)luaL_checklstring((undefined4 *)0x0);
  puVar2 = (undefined4 *)luaL_testudata();
  if (puVar2 == (undefined4 *)0x0) {
    pVVar3 = (Vector *)luaL_testudata();
    if (pVVar3 == (Vector *)0x0) {
      uVar4 = luaL_testudata();
      ::GetPosition(uVar4,&local_10);
      pVVar3 = &local_10;
    }
  }
  else {
    puVar6 = local_50;
    for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar6 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar6 = puVar6 + 1;
    }
    pVVar3 = &local_20;
  }
  iVar5 = ::GetWindingNumber(path,*pVVar3);
  puVar1 = *(uint **)(L + 8);
  puVar1[1] = 0x7ff7a501;
  *puVar1 = (uint)(iVar5 != 0);
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetWindingNumber  @ 4fc4bafe  lines 6187-6205

int __cdecl LuaBindings::GetWindingNumber(lua_State *L)

{
  char *path;
  undefined4 *puVar1;
  Vector *pVVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  Vector local_54;
  undefined4 local_48 [12];
  Vector local_18;
  
  path = (char *)luaL_checklstring((undefined4 *)0x0);
  puVar1 = (undefined4 *)luaL_testudata();
  if (puVar1 == (undefined4 *)0x0) {
    pVVar2 = (Vector *)luaL_testudata();
    if (pVVar2 == (Vector *)0x0) {
      uVar3 = luaL_testudata();
      ::GetPosition(uVar3,&local_54);
      pVVar2 = &local_54;
    }
  }
  else {
    puVar5 = local_48;
    for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar5 = *puVar1;
      puVar1 = puVar1 + 1;
      puVar5 = puVar5 + 1;
    }
    pVVar2 = &local_18;
  }
  ::GetWindingNumber(path,*pVVar2);
  lua_pushnumber();
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::GetTPS  @ 4fc49b72  lines 6213-6216

int __cdecl LuaBindings::GetTPS(lua_State *L)

{
  double *pdVar1;
  int iVar2;
  
  iVar2 = ::SecondsToTurns(1.0);
  pdVar1 = *(double **)(L + 8);
  *pdVar1 = (double)iVar2;
  *(double **)(L + 8) = pdVar1 + 1;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::DoesPathExist  @ 4fc4eb78  lines 6220-6229

int __cdecl LuaBindings::DoesPathExist(lua_State *L)

{
  char *path;
  int iVar1;
  
  path = (char *)luaL_checklstring((undefined4 *)0x0);
  iVar1 = ::DoesPathExist(path);
  if (iVar1 < 1) {
    *(undefined4 *)(*(int *)(L + 8) + 4) = 0x7ff7a500;
  }
  else {
    iVar1 = ::DoesPathExist(path);
    **(double **)(L + 8) = (double)iVar1;
  }
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::AddToDispatch  @ 4fc527d7  lines 6239-6251

int __cdecl LuaBindings::AddToDispatch(lua_State *L)

{
  uint *puVar1;
  bool bVar2;
  int h;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int CloakPriority;
  int iVar8;
  float IdleTime;
  float fVar9;
  double in_XMM0_Qa;
  
  h = RequireHandle(L,1);
  uVar3 = lua_type();
  if ((int)uVar3 < 1) {
    in_XMM0_Qa = 15.0;
  }
  else {
    luaL_checknumber();
  }
  IdleTime = (float)in_XMM0_Qa;
  fVar9 = IdleTime;
  uVar3 = lua_type();
  iVar8 = 0;
  if ((int)uVar3 < 1) {
    iVar4 = 0;
  }
  else {
    iVar4 = lua_toboolean();
  }
  uVar3 = lua_type();
  if ((int)uVar3 < 1) {
    CloakPriority = 0;
    IdleTime = fVar9;
  }
  else {
    CloakPriority = luaL_checkinteger();
  }
  uVar3 = lua_type();
  if ((int)uVar3 < 1) {
    iVar5 = 1;
  }
  else {
    iVar5 = lua_toboolean();
  }
  uVar3 = lua_type();
  if ((int)uVar3 < 1) {
    iVar6 = 0;
  }
  else {
    iVar6 = lua_toboolean();
  }
  uVar3 = lua_type();
  if ((int)uVar3 < 1) {
    iVar7 = 0;
  }
  else {
    iVar7 = lua_toboolean();
  }
  uVar3 = lua_type();
  if (0 < (int)uVar3) {
    iVar8 = lua_toboolean();
  }
  bVar2 = BZ1Helper::AddToDispatch
                    (BZ1Helper::m_BZ1Helper,h,IdleTime,iVar4 != 0,CloakPriority,iVar5 != 0,
                     iVar6 != 0,iVar7 != 0,iVar8 != 0);
  puVar1 = *(uint **)(L + 8);
  *puVar1 = (uint)bVar2;
  puVar1[1] = 0x7ff7a501;
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::ReplaceWeapons  @ 4fc4a758  lines 6255-6310

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl LuaBindings::ReplaceWeapons(lua_State *L)

{
  int iVar1;
  uint *puVar2;
  bool bVar3;
  int h;
  uint uVar4;
  char *pcVar5;
  int iVar6;
  float *PreviousLocalAmmo;
  float in_XMM0_Da;
  undefined4 in_XMM0_Db;
  char *local_160;
  float Ammo [5];
  char Weapons [320];
  uint local_8;
  
  local_8 = __security_cookie ^ (uint)&stack0xfffffffc;
  h = RequireHandle(L,1);
  memset(Weapons,0,0x140);
  uVar4 = lua_type();
  if (uVar4 == 5) {
    uVar4 = lua_rawlen();
    iVar6 = 0;
    local_160 = Weapons;
    do {
      if ((int)uVar4 <= iVar6) break;
      iVar6 = iVar6 + 1;
      lua_rawgeti();
      pcVar5 = (char *)lua_tolstring((undefined4 *)0x0);
      if (pcVar5 != (char *)0x0) {
        strcpy_s(local_160,0x40,pcVar5);
      }
      lua_settop();
      local_160 = local_160 + 0x40;
    } while (iVar6 < 5);
  }
  Ammo[0] = 0.0;
  Ammo[1] = 0.0;
  Ammo[2] = 0.0;
  Ammo[3] = 0.0;
  Ammo[4] = 0.0;
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
      Ammo[iVar6] = in_XMM0_Da;
      lua_settop();
      iVar6 = iVar1;
    } while (iVar1 < 5);
    PreviousLocalAmmo = Ammo;
  }
  else {
    uVar4 = lua_type();
    PreviousLocalAmmo = (float *)((uint)Ammo & -(uint)(uVar4 != 0));
  }
  pcVar5 = (char *)0x0;
  uVar4 = lua_type();
  if (uVar4 != 0) {
    pcVar5 = (char *)lua_tolstring((undefined4 *)0x0);
  }
  bVar3 = ::ReplaceWeapons(h,(char (*) [64])Weapons,PreviousLocalAmmo,pcVar5);
  puVar2 = *(uint **)(L + 8);
  puVar2[1] = 0x7ff7a501;
  *puVar2 = (uint)bVar3;
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::SetPortalChannel  @ 4fc4d7bf  lines 6314-6319

int __cdecl LuaBindings::SetPortalChannel(lua_State *L)

{
  PortalHelper *pPVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  
  iVar3 = RequireHandle(L,1);
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
// LuaBindings::GetPortalChannel  @ 4fc492d9  lines 6323-6327

int __cdecl LuaBindings::GetPortalChannel(lua_State *L)

{
  PortalHelper *pPVar1;
  bool bVar2;
  int iVar3;
  int *piVar4;
  
  iVar3 = RequireHandle(L,1);
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
// LuaBindings::SetPortalEffectStart  @ 4fc52aaf  lines 6331-6337

int __cdecl LuaBindings::SetPortalEffectStart(lua_State *L)

{
  PortalHelper *this;
  bool bVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  int local_8;
  
  iVar2 = RequireHandle(L,1);
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
// LuaBindings::SetPortalEffectOn  @ 4fc4add3  lines 6341-6347

int __cdecl LuaBindings::SetPortalEffectOn(lua_State *L)

{
  PortalHelper *this;
  bool bVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  int local_8;
  
  iVar2 = RequireHandle(L,1);
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
// LuaBindings::SetPortalEffectEnd  @ 4fc49a59  lines 6351-6357

int __cdecl LuaBindings::SetPortalEffectEnd(lua_State *L)

{
  int iVar1;
  uint uVar2;
  undefined1 extraout_CL;
  undefined1 extraout_CL_00;
  undefined1 uVar3;
  int iVar4;
  int iVar5;
  
  iVar1 = RequireHandle(L,1);
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
// LuaBindings::IsPortalEffectActive  @ 4fc4a91e  lines 6361-6365

int __cdecl LuaBindings::IsPortalEffectActive(lua_State *L)

{
  PortalHelper *pPVar1;
  uint *puVar2;
  bool bVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  
  iVar4 = RequireHandle(L,1);
  pPVar1 = BZ1Helper::m_BZ1Helper->m_PortalHelper;
  bVar3 = ::IsAround(iVar4);
  if (bVar3) {
    for (piVar5 = *(int **)&pPVar1->PortalList; piVar5 != *(int **)&(pPVar1->PortalList).field_0x4;
        piVar5 = piVar5 + 0xe4) {
      if (*piVar5 == iVar4) {
        bVar3 = ::IsEmitterOn(*piVar5,piVar5[2]);
        uVar6 = (uint)bVar3;
        goto LAB_4fc4a95b;
      }
    }
  }
  uVar6 = 0;
LAB_4fc4a95b:
  puVar2 = *(uint **)(L + 8);
  *puVar2 = uVar6;
  puVar2[1] = 0x7ff7a501;
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::SwapPortalIndex  @ 4fc501bb  lines 6369-6374

int __cdecl LuaBindings::SwapPortalIndex(lua_State *L)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  
  iVar2 = RequireHandle(L,1);
  iVar3 = RequireHandle(L,2);
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
// LuaBindings::ShufflePortalUp  @ 4fc4f68e  lines 6378-6382

int __cdecl LuaBindings::ShufflePortalUp(lua_State *L)

{
  PortalHelper *this;
  int iVar1;
  int *piVar2;
  
  iVar1 = RequireHandle(L,1);
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
// LuaBindings::ShufflePortalDown  @ 4fc4effc  lines 6386-6390

int __cdecl LuaBindings::ShufflePortalDown(lua_State *L)

{
  PortalHelper *this;
  int iVar1;
  int *piVar2;
  
  iVar1 = RequireHandle(L,1);
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
// LuaBindings::GetPortalDest  @ 4fc49f5d  lines 6394-6398

int __cdecl LuaBindings::GetPortalDest(lua_State *L)

{
  PortalHelper *pPVar1;
  bool bVar2;
  int iVar3;
  int *piVar4;
  
  iVar3 = RequireHandle(L,1);
  pPVar1 = BZ1Helper::m_BZ1Helper->m_PortalHelper;
  bVar2 = ::IsAround(iVar3);
  if (bVar2) {
    for (piVar4 = *(int **)&pPVar1->PortalList; piVar4 != *(int **)&(pPVar1->PortalList).field_0x4;
        piVar4 = piVar4 + 0xe4) {
      if (*piVar4 == iVar3) {
        bVar2 = ::IsAround(piVar4[1]);
        if (bVar2) {
          iVar3 = piVar4[1];
          goto LAB_4fc49f9e;
        }
        break;
      }
    }
    iVar3 = 0;
  }
  else {
    iVar3 = 0;
  }
LAB_4fc49f9e:
  PushHandle(L,iVar3);
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::SetPortalDest  @ 4fc4ad46  lines 6402-6407

int __cdecl LuaBindings::SetPortalDest(lua_State *L)

{
  uint *puVar1;
  bool bVar2;
  int me;
  int him;
  
  me = RequireHandle(L,1);
  him = RequireHandle(L,2);
  bVar2 = PortalHelper::SetPortalDest(BZ1Helper::m_BZ1Helper->m_PortalHelper,me,him);
  puVar1 = *(uint **)(L + 8);
  *puVar1 = (uint)bVar2;
  puVar1[1] = 0x7ff7a501;
  *(int *)(L + 8) = *(int *)(L + 8) + 8;
  return 1;
}


// ---------------------------------------------------------------------
// LuaBindings::ClearPortalDest  @ 4fc4d72d  lines 6411-6416

int __cdecl LuaBindings::ClearPortalDest(lua_State *L)

{
  PortalHelper *this;
  int *piVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  
  iVar3 = RequireHandle(L,1);
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
// LuaBindings::LoadValue  @ 4fc4cfb4  lines 6426-6547

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

bool __cdecl LuaBindings::LoadValue(lua_State *L,bool push)

{
  uint *puVar1;
  bool bVar2;
  Quaternion *pQVar3;
  Vector *pVVar4;
  Matrix *pMVar5;
  lua_State *in_ECX;
  int iVar6;
  char in_DL;
  undefined1 *puVar7;
  undefined4 unaff_ESI;
  float *pfVar8;
  lua_State *unaff_EDI;
  undefined4 uStackY_a0;
  float m [17];
  float q;
  float local_3c [6];
  undefined8 value__v;
  lua_State *local_1c;
  bool value;
  char type;
  int value__len__count;
  uint local_8;
  
  local_8 = __security_cookie ^ (uint)&stack0xfffffffc;
  type = '0';
  uStackY_a0 = 0x4fc4cfe3;
  local_1c = in_ECX;
  bVar2 = Read(&type,1);
  type = type + -0x30;
  if (type != '\x01') {
    if (type == '\x02') {
      value__len__count = 0;
      if (bVar2) {
        uStackY_a0 = 0x4fc4d27d;
        bVar2 = Read(&value__len__count,1);
        if (bVar2) {
          bVar2 = true;
          goto LAB_4fc4d289;
        }
      }
      bVar2 = false;
LAB_4fc4d289:
      uStackY_a0 = 0x4fc4d295;
      ConvertHandles(&value__len__count,1);
      if (in_DL == '\0') {
        return bVar2;
      }
      PushHandle(in_ECX,value__len__count);
      return bVar2;
    }
    if (type == '\x03') {
      value__v = 0;
      if (bVar2) {
        uStackY_a0 = 0x4fc4d247;
        bVar2 = Read(&value__v,8);
        if (bVar2) {
          bVar2 = true;
          goto LAB_4fc4d253;
        }
      }
      bVar2 = false;
LAB_4fc4d253:
      if (in_DL == '\0') {
        return bVar2;
      }
      lua_pushnumber();
      return bVar2;
    }
    if (type != '\x04') {
      if (type == '\x05') {
        value__len__count = 0;
        if (bVar2) {
          uStackY_a0 = 0x4fc4d168;
          bVar2 = Read(&value__len__count,1);
          if (bVar2) {
            bVar2 = true;
            goto LAB_4fc4d174;
          }
        }
        bVar2 = false;
LAB_4fc4d174:
        lua_createtable(0);
        iVar6 = 0;
        if (value__len__count < 1) {
          return bVar2;
        }
        do {
          if (((bVar2 == false) || (bVar2 = LoadValue(unaff_EDI,SUB41(unaff_ESI,0)), !bVar2)) ||
             (bVar2 = LoadValue(unaff_EDI,SUB41(unaff_ESI,0)), !bVar2)) {
            bVar2 = false;
          }
          else {
            bVar2 = true;
          }
          if (in_DL != '\0') {
            uStackY_a0 = 0x4fc4d1c8;
            luaV_settable((double *)(*(int *)(in_ECX + 8) + -0x10),
                          (int *)(*(int *)(in_ECX + 8) + -8));
            *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + -0x10;
          }
          iVar6 = iVar6 + 1;
        } while (iVar6 < value__len__count);
        return bVar2;
      }
      if (type != '\a') {
        if (in_DL == '\0') {
          return bVar2;
        }
        *(undefined4 *)(*(int *)(in_ECX + 8) + 4) = 0x7ff7a500;
        goto LAB_4fc4d2df;
      }
      value__len__count = 0;
      if (bVar2) {
        uStackY_a0 = 0x4fc4d050;
        bVar2 = Read(&value__len__count,4);
        if (!bVar2) goto LAB_4fc4d05d;
        bVar2 = true;
      }
      else {
LAB_4fc4d05d:
        bVar2 = false;
      }
      if (value__len__count == 0x15c2f8ec) {
        pMVar5 = &::Identity_Matrix;
        pfVar8 = m;
        for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
          *pfVar8 = (pMVar5->right).x;
          pMVar5 = (Matrix *)&(pMVar5->right).y;
          pfVar8 = pfVar8 + 1;
        }
        if (bVar2 != false) {
          uStackY_a0 = 0x4fc4d129;
          bVar2 = Read(m,0x40);
          if (bVar2) {
            bVar2 = true;
            goto LAB_4fc4d135;
          }
        }
        bVar2 = false;
LAB_4fc4d135:
        if (in_DL == '\0') {
          return bVar2;
        }
        pMVar5 = NewMatrix(local_1c);
        pfVar8 = m;
        for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
          (pMVar5->right).x = *pfVar8;
          pfVar8 = pfVar8 + 1;
          pMVar5 = (Matrix *)&(pMVar5->right).y;
        }
        return bVar2;
      }
      if (value__len__count == -0x707617fe) {
        value__v = 0;
        local_1c = (lua_State *)0x0;
        if (bVar2 == false) {
LAB_4fc4d0ee:
          bVar2 = false;
        }
        else {
          uStackY_a0 = 0x4fc4d0e4;
          bVar2 = Read(&value__v,0xc);
          if (!bVar2) goto LAB_4fc4d0ee;
          bVar2 = true;
        }
        if (in_DL == '\0') {
          return bVar2;
        }
        pVVar4 = NewVector(in_ECX);
        pfVar8 = (float *)&value__v;
        goto LAB_4fc4d104;
      }
      if (value__len__count != -0xc19b973) {
        return bVar2;
      }
      local_3c[3] = 0.0;
      local_3c[4] = 0.0;
      local_3c[5] = 0.0;
      q = 1.0;
      local_3c[0] = 0.0;
      local_3c[1] = 0.0;
      local_3c[2] = 0.0;
      if (bVar2 == false) {
LAB_4fc4d0b2:
        bVar2 = false;
      }
      else {
        uStackY_a0 = 0x4fc4d0a8;
        bVar2 = Read(&q,0x10);
        if (!bVar2) goto LAB_4fc4d0b2;
        bVar2 = true;
      }
      if (in_DL == '\0') {
        return bVar2;
      }
      pQVar3 = NewQuaternion(local_1c);
      pVVar4 = &pQVar3->v;
      pfVar8 = local_3c;
      pQVar3->s = q;
LAB_4fc4d104:
      pVVar4->x = *pfVar8;
      pVVar4->y = pfVar8[1];
      pVVar4->z = pfVar8[2];
      return bVar2;
    }
    value__len__count = 0;
    if (bVar2) {
      uStackY_a0 = 0x4fc4d1e9;
      bVar2 = Read(&value__len__count,4);
      if (!bVar2) goto LAB_4fc4d1f3;
      bVar2 = true;
    }
    else {
LAB_4fc4d1f3:
      bVar2 = false;
    }
    iVar6 = -value__len__count;
    local_1c = (lua_State *)((int)m + iVar6 + -0x10);
    if (bVar2) {
      *(int *)((int)m + iVar6 + -0x14) = value__len__count;
      *(int *)((int)m + iVar6 + -0x18) = (int)m + iVar6 + -0x10;
      *(undefined4 *)((int)&uStackY_a0 + iVar6) = 0x4fc4d20c;
      bVar2 = Read(*(void **)((int)m + iVar6 + -0x18),*(int *)((int)m + iVar6 + -0x14));
      puVar7 = (undefined1 *)((int)m + iVar6 + -0x10);
      if (bVar2) {
        bVar2 = true;
        goto LAB_4fc4d218;
      }
    }
    puVar7 = (undefined1 *)((int)m + iVar6 + -0x10);
    bVar2 = false;
LAB_4fc4d218:
    if (in_DL == '\0') {
      return bVar2;
    }
    *(int *)(puVar7 + -4) = value__len__count;
    *(undefined4 *)(puVar7 + -8) = 0x4fc4d22d;
    lua_pushlstring(*(uint *)(puVar7 + -4));
    return bVar2;
  }
  value = false;
  if (bVar2) {
    uStackY_a0 = 0x4fc4d2bb;
    bVar2 = Read(&value,1);
    if (!bVar2) goto LAB_4fc4d2c5;
    bVar2 = true;
  }
  else {
LAB_4fc4d2c5:
    bVar2 = false;
  }
  if (in_DL == '\0') {
    return bVar2;
  }
  puVar1 = *(uint **)(in_ECX + 8);
  *puVar1 = (uint)(value != false);
  puVar1[1] = 0x7ff7a501;
LAB_4fc4d2df:
  *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + 8;
  return bVar2;
}


// ---------------------------------------------------------------------
// LuaBindings::SaveValue  @ 4fc50dc3  lines 6551-6656

bool __cdecl LuaBindings::SaveValue(lua_State *L,int i)

{
  bool bVar1;
  bool bVar2;
  uint uVar3;
  undefined3 extraout_var;
  int iVar4;
  ulonglong *puVar5;
  void *pvVar6;
  uint unaff_ESI;
  char *unaff_EDI;
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
        goto LAB_4fc51070;
      }
      if (local_12 == '\x05') {
        local_10 = local_10 & 0xffffffff00000000;
        *(undefined4 *)(*(int *)(L + 8) + 4) = 0x7ff7a500;
        *(int *)(L + 8) = *(int *)(L + 8) + 8;
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
        *(undefined4 *)(*(int *)(L + 8) + 4) = 0x7ff7a500;
        *(int *)(L + 8) = *(int *)(L + 8) + 8;
        while (iVar4 = lua_next(), iVar4 != 0) {
          if (((bVar1 == false) || (bVar1 = SaveValue(L,-2), !bVar1)) ||
             (bVar1 = SaveValue(L,-1), !bVar1)) {
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
        uVar3 = Hash(unaff_EDI,unaff_ESI);
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
LAB_4fc51070:
  if (bVar1 == false) {
    return false;
  }
  return true;
}


