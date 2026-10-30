// Reconstructed by Ghidra from Instant.dll + Instant.pdb
// Original source file: /e:/github/vsr_dll_source/missions/vsrcore/bzcscriptutils.cpp
// Functions are ordered by original source line. This is decompiler
// output, not the author's source: names/types come from the PDB,
// local variable names and control flow are reconstructed.


// ---------------------------------------------------------------------
// `dynamic_initializer_for_'ODFNameMap''  @ 4fc01106  lines 24-24


void __cdecl _dynamic_initializer_for__ODFNameMap__(void)

{
  _List_alloc<std::_List_base_types<std::pair<unsigned_long_const_,ODFName>,std::allocator<std::pair<unsigned_long_const_,ODFName>_>_>_>
  *in_ECX;
  
  ODFNameMap._4_4_ =
       std::
       _List_alloc<std::_List_base_types<std::pair<unsigned_long_const_,ODFName>,std::allocator<std::pair<unsigned_long_const_,ODFName>_>_>_>
       ::_Buynode0(in_ECX,(_List_node<std::pair<unsigned_long_const_,ODFName>,void_*> *)0x0,
                   (_List_node<std::pair<unsigned_long_const_,ODFName>,void_*> *)0x0);
  ODFNameMap._12_4_ = 0;
  ODFNameMap._16_4_ = 0;
  ODFNameMap._20_4_ = 0;
  ODFNameMap._0_4_ = 0x3f800000;
  std::
  _Hash<std::_Umap_traits<unsigned_long,ODFName,std::_Uhash_compare<unsigned_long,std::hash<unsigned_long>,std::equal_to<unsigned_long>_>,std::allocator<std::pair<unsigned_long_const_,ODFName>_>,0>_>
  ::_Init((_Hash<std::_Umap_traits<unsigned_long,ODFName,std::_Uhash_compare<unsigned_long,std::hash<unsigned_long>,std::equal_to<unsigned_long>_>,std::allocator<std::pair<unsigned_long_const_,ODFName>_>,0>_>
           *)&ODFNameMap,8);
  atexit(_dynamic_atexit_destructor_for__ODFNameMap__);
  return;
}


// ---------------------------------------------------------------------
// `dynamic_initializer_for_'ODFNameBlackListMap''  @ 4fc0114a  lines 26-26


void __cdecl _dynamic_initializer_for__ODFNameBlackListMap__(void)

{
  _List_alloc<std::_List_base_types<unsigned_long,std::allocator<unsigned_long>_>_> *in_ECX;
  
  ODFNameBlackListMap._4_4_ =
       std::_List_alloc<std::_List_base_types<unsigned_long,std::allocator<unsigned_long>_>_>::
       _Buynode0(in_ECX,(_List_node<unsigned_long,void_*> *)0x0,
                 (_List_node<unsigned_long,void_*> *)0x0);
  ODFNameBlackListMap._12_4_ = 0;
  ODFNameBlackListMap._16_4_ = 0;
  ODFNameBlackListMap._20_4_ = 0;
  ODFNameBlackListMap._0_4_ = 0x3f800000;
  std::
  _Hash<std::_Umap_traits<unsigned_long,ODFName,std::_Uhash_compare<unsigned_long,std::hash<unsigned_long>,std::equal_to<unsigned_long>_>,std::allocator<std::pair<unsigned_long_const_,ODFName>_>,0>_>
  ::_Init((_Hash<std::_Umap_traits<unsigned_long,ODFName,std::_Uhash_compare<unsigned_long,std::hash<unsigned_long>,std::equal_to<unsigned_long>_>,std::allocator<std::pair<unsigned_long_const_,ODFName>_>,0>_>
           *)&ODFNameBlackListMap,8);
  atexit(_dynamic_atexit_destructor_for__ODFNameBlackListMap__);
  return;
}


// ---------------------------------------------------------------------
// `dynamic_initializer_for_'FileNameMap''  @ 4fc0118e  lines 28-28


void __cdecl _dynamic_initializer_for__FileNameMap__(void)

{
  _List_alloc<std::_List_base_types<std::pair<char_const_*_const,_iobuf_*>,std::allocator<std::pair<char_const_*_const,_iobuf_*>_>_>_>
  *in_ECX;
  
  FileNameMap._4_4_ =
       std::
       _List_alloc<std::_List_base_types<std::pair<char_const_*_const,_iobuf_*>,std::allocator<std::pair<char_const_*_const,_iobuf_*>_>_>_>
       ::_Buynode0(in_ECX,(_List_node<std::pair<char_const_*_const,_iobuf_*>,void_*> *)0x0,
                   (_List_node<std::pair<char_const_*_const,_iobuf_*>,void_*> *)0x0);
  FileNameMap._12_4_ = 0;
  FileNameMap._16_4_ = 0;
  FileNameMap._20_4_ = 0;
  FileNameMap._0_4_ = 0x3f800000;
  std::
  _Hash<std::_Umap_traits<unsigned_long,ODFName,std::_Uhash_compare<unsigned_long,std::hash<unsigned_long>,std::equal_to<unsigned_long>_>,std::allocator<std::pair<unsigned_long_const_,ODFName>_>,0>_>
  ::_Init((_Hash<std::_Umap_traits<unsigned_long,ODFName,std::_Uhash_compare<unsigned_long,std::hash<unsigned_long>,std::equal_to<unsigned_long>_>,std::allocator<std::pair<unsigned_long_const_,ODFName>_>,0>_>
           *)&FileNameMap,8);
  atexit(_dynamic_atexit_destructor_for__FileNameMap__);
  return;
}


// ---------------------------------------------------------------------
// IsRecycler  @ 4fc02103  lines 298-311


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool __cdecl IsRecycler(int param_1)

{
  bool bVar1;
  int iVar2;
  int in_ECX;
  bool bVar3;
  char *pcVar4;
  char *pcVar5;
  char local_88 [64];
  char local_48 [64];
  undefined4 local_8;
  
  local_8 = __security_cookie ^ (uint)(local_48 + 0x44);
  bVar3 = false;
  memset(local_48,0,0x40);
  bVar1 = GetObjInfo(in_ECX,Get_GOClass,local_48);
  if (bVar1) {
    pcVar4 = local_88;
    pcVar5 = (char *)0x0;
    memset(pcVar4,0,0x40);
    GetODFString(0x4fc552cc,(char *)0x40,local_88,0,pcVar4,pcVar5);
    iVar2 = _stricmp(local_48,"CLASS_RECYCLER");
    if ((((iVar2 == 0) || (iVar2 = _stricmp(local_48,"CLASS_RECYCLERVEHICLE"), iVar2 == 0)) ||
        (iVar2 = _stricmp(local_48,"CLASS_RECYCLERVEHICLEH"), iVar2 == 0)) ||
       (iVar2 = _stricmp(local_88,"recy"), iVar2 == 0)) {
      bVar3 = true;
    }
    return bVar3;
  }
  return false;
}


// ---------------------------------------------------------------------
// HRotateFront  @ 4fc021c6  lines 615-630


Vector * __cdecl HRotateFront(Vector *__return_storage_ptr__,Vector param_1,float param_2)

{
  Vector *in_ECX;
  float10 fVar1;
  float fVar2;
  float fVar3;
  
  in_ECX->x = 0.0;
  in_ECX->y = 0.0;
  in_ECX->z = 0.0;
  fVar1 = (float10)__CIsqrt();
  fVar2 = portable_atan2((float)__return_storage_ptr__,param_1.y);
  fVar3 = portable_sin(fVar2 + param_1.z);
  in_ECX->y = param_1.x;
  in_ECX->x = fVar3 * (float)fVar1;
  fVar2 = portable_cos(fVar2 + param_1.z);
  in_ECX->z = fVar2 * (float)fVar1;
  return in_ECX;
}


// ---------------------------------------------------------------------
// SetAngle  @ 4fc0224d  lines 633-641


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl SetAngle(int param_1,float param_2)

{
  Vector VVar1;
  Vector VVar2;
  bool bVar3;
  Vector *in_ECX;
  float unaff_EDI;
  Vector *pVVar4;
  Vector *pVVar5;
  Matrix local_68;
  Vector local_24;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  
  bVar3 = IsAround((int)in_ECX);
  if (bVar3) {
    local_c = (float)param_1 * (float)___real_3f91df46a0000000;
    local_18 = 0.0;
    local_14 = 0.0;
    local_10 = 1.0;
    VVar1.z = local_c;
    VVar1.x = 0.0;
    VVar1.y = 1.0;
    HRotateFront((Vector *)0x0,VVar1,unaff_EDI);
    pVVar5 = &local_24;
    pVVar4 = in_ECX;
    GetPosition((int)in_ECX,pVVar5);
    Build_Directinal_Matrix((Matrix *)&local_18,pVVar4,pVVar5);
    SetPosition((int)in_ECX,&local_68);
    VVar2.y = local_68.posit.y;
    VVar2.x = local_68.posit.x;
    VVar2.z = local_68.posit.z;
    SetVectorPosition((int)in_ECX,VVar2);
  }
  return;
}


// ---------------------------------------------------------------------
// CameraPos  @ 4fc022d9  lines 647-673


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool __cdecl CameraPos(int param_1,int param_2,Vector *param_3,Vector *param_4,float param_5)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  Vector VVar5;
  Vector VVar6;
  bool bVar7;
  int iVar8;
  int in_EDX;
  int unaff_ESI;
  float unaff_EDI;
  float fVar9;
  undefined8 local_c;
  float local_4;
  
  fVar2 = *(float *)param_2 - *(float *)param_1;
  fVar3 = *(float *)(param_2 + 4) - *(float *)(param_1 + 4);
  local_c = (double)CONCAT44(fVar3,fVar2);
  fVar4 = *(float *)(param_2 + 8) - *(float *)(param_1 + 8);
  VVar5.y = fVar3;
  VVar5.x = fVar2;
  VVar5.z = fVar4;
  local_4 = fVar4;
  fVar9 = GetLength3D(VVar5);
  local_c = (double)(float)param_3;
  if (0.0 <= CameraTime) {
    iVar8 = SecondsToTurns(1.0);
    param_1 = (int)&local_c;
    fVar9 = (float)local_c / (fVar9 * (float)___real_4059000000000000 * (float)iVar8);
    local_c = (double)CONCAT44(fVar3 * fVar9 + CameraPosition.y,fVar2 * fVar9 + CameraPosition.x);
    local_4 = fVar9 * fVar4 + CameraPosition.z;
  }
  else {
    CameraTime = fVar9 / ((float)param_3 * (float)___real_3f847ae140000000) + misnImport.time;
  }
  pfVar1 = (float *)(param_1 + 4);
  CameraPosition.x = *(float *)param_1;
  CameraPosition.y = *pfVar1;
  CameraPosition.z = *(float *)(param_1 + 8);
  VVar6.z = unaff_EDI;
  VVar6.x = pfVar1[0];
  VVar6.y = pfVar1[1];
  bVar7 = CameraObject((int)CameraPosition.x,VVar6,unaff_ESI);
  if (((!bVar7) && (misnImport.time <= CameraTime)) && (bVar7 = IsAround(in_EDX), bVar7)) {
    return false;
  }
  CameraTime = -1.0;
  return true;
}


// ---------------------------------------------------------------------
// CameraOf  @ 4fc02442  lines 677-682


void __cdecl CameraOf(int param_1,Vector *param_2)

{
  bool bVar1;
  Vector *pVVar2;
  int in_ECX;
  Vector *in_EDX;
  Vector *unaff_EDI;
  Matrix *pMVar3;
  Matrix local_5c;
  Vector local_10;
  
  bVar1 = IsAround(in_ECX);
  if (bVar1) {
    GetFront(in_ECX,&local_10);
    GetPosition(in_ECX,&local_5c);
    pMVar3 = (Matrix *)&local_10;
    pVVar2 = Vector_Transform(in_EDX,pMVar3,unaff_EDI);
    SetCameraPosition(pVVar2,&pMVar3->right);
  }
  return;
}


// ---------------------------------------------------------------------
// Move  @ 4fc02493  lines 686-747


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool __cdecl Move(int param_1,float param_2,float param_3,Vector *param_4,bool param_5,bool param_6)

{
  float fVar1;
  Vector VVar2;
  Vector VVar3;
  bool bVar4;
  int iVar5;
  Matrix *pMVar6;
  Vector *pVVar7;
  int in_ECX;
  int iVar8;
  float *in_EDX;
  Vector *unaff_ESI;
  Vector *unaff_EDI;
  Matrix *pMVar9;
  float fVar10;
  Vector local_f8;
  Matrix local_ec;
  Vector local_a8 [3];
  Matrix local_84 [2];
  
  bVar4 = IsAround(in_ECX);
  if (bVar4) {
    iVar5 = SecondsToTurns(1.0);
    GetPosition(in_ECX,&local_ec);
    pMVar6 = &local_ec;
    pMVar9 = local_84;
    for (iVar8 = 0x10; iVar8 != 0; iVar8 = iVar8 + -1) {
      (pMVar9->right).x = (pMVar6->right).x;
      pMVar6 = (Matrix *)&(pMVar6->right).y;
      pMVar9 = (Matrix *)&(pMVar9->right).y;
    }
    if ((float)param_1 != ___real_00000000) {
      GetFront(in_ECX,local_a8);
      VVar2.y = local_a8[0].z;
      VVar2.x = local_a8[0].y;
      VVar2.z = (float)param_1 * (1.0 / (float)iVar5) * (float)___real_3f91df46a0000000;
      pMVar6 = (Matrix *)HRotateFront((Vector *)local_a8[0].x,VVar2,(float)unaff_EDI);
      pMVar6 = Build_Directinal_Matrix(pMVar6,(Vector *)local_a8[0].x,(Vector *)local_a8[0].y);
      pMVar9 = local_84;
      for (iVar8 = 0x10; iVar8 != 0; iVar8 = iVar8 + -1) {
        (pMVar9->right).x = (pMVar6->right).x;
        pMVar6 = (Matrix *)&(pMVar6->right).y;
        pMVar9 = (Matrix *)&(pMVar9->right).y;
      }
    }
    if (param_2 != ___real_00000000) {
      local_f8.x = *in_EDX - local_ec.posit.x;
      local_f8.y = in_EDX[1] - local_ec.posit.y;
      local_f8.z = in_EDX[2] - local_ec.posit.z;
      fVar1 = (1.0 / (float)iVar5) * param_2;
      VVar3.y = local_f8.y;
      VVar3.x = local_f8.x;
      VVar3.z = local_f8.z;
      fVar10 = GetLength3D(VVar3);
      if (fVar1 <= fVar10) {
        pVVar7 = Normalize_Vector(unaff_EDI,unaff_ESI);
        local_84[0].posit.x = local_ec.posit.x + pVVar7->x * fVar1;
        local_84[0].posit.y = pVVar7->y * fVar1 + local_ec.posit.y;
        local_84[0].posit.z = pVVar7->z * fVar1 + local_ec.posit.z;
        fVar1 = fVar1 / (float)___real_4024000000000000;
        local_f8.x = fVar1 * pVVar7->x;
        local_f8.y = pVVar7->y * fVar1;
        local_f8.z = pVVar7->z * fVar1;
        SetVelocity(in_ECX,&local_f8);
        SetLastCurrentPosition(in_ECX,&local_ec,local_84);
        SetInterpolablePosition(in_ECX,local_84,&local_ec,true);
        return false;
      }
    }
  }
  return true;
}


// ---------------------------------------------------------------------
// Move  @ 4fc026cf  lines 750-780


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool __cdecl Move(int param_1,float param_2,float param_3,bool param_4)

{
  Vector VVar1;
  bool bVar2;
  int iVar3;
  Matrix *pMVar4;
  int in_ECX;
  float unaff_EDI;
  Matrix *pMVar5;
  Matrix local_a4;
  Matrix local_64;
  Vector local_14;
  float local_8;
  
  bVar2 = IsAround(in_ECX);
  if ((bVar2) && (misnImport.time < param_2)) {
    iVar3 = SecondsToTurns(1.0);
    local_8 = 1.0 / (float)iVar3;
    GetPosition(in_ECX,&local_a4);
    pMVar4 = &local_a4;
    pMVar5 = &local_64;
    for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
      (pMVar5->right).x = (pMVar4->right).x;
      pMVar4 = (Matrix *)&(pMVar4->right).y;
      pMVar5 = (Matrix *)&(pMVar5->right).y;
    }
    if ((float)param_1 != ___real_00000000) {
      GetFront(in_ECX,&local_14);
      local_8 = local_8 * (float)param_1 * (float)___real_3f91df46a0000000;
      VVar1.y = local_14.z;
      VVar1.x = local_14.y;
      VVar1.z = local_8;
      pMVar4 = (Matrix *)HRotateFront((Vector *)local_14.x,VVar1,unaff_EDI);
      pMVar4 = Build_Directinal_Matrix(pMVar4,(Vector *)local_14.x,(Vector *)local_14.y);
      pMVar5 = &local_64;
      for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
        (pMVar5->right).x = (pMVar4->right).x;
        pMVar4 = (Matrix *)&(pMVar4->right).y;
        pMVar5 = (Matrix *)&(pMVar5->right).y;
      }
      SetLastCurrentPosition(in_ECX,&local_a4,&local_64);
      SetInterpolablePosition(in_ECX,&local_64,&local_a4,false);
      return false;
    }
  }
  return true;
}


// ---------------------------------------------------------------------
// CameraCircle  @ 4fc027d6  lines 789-829


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool __cdecl CameraCircle(int param_1,Vector param_2,int param_3,Vector *param_4)

{
  float fVar1;
  Vector VVar2;
  bool bVar3;
  int iVar4;
  int in_ECX;
  int in_EDX;
  float fVar5;
  float fVar6;
  float local_c;
  float fStack_8;
  
  VVar2.y = param_2.x;
  VVar2.x = (float)param_1;
  VVar2.z = param_2.y;
  fVar5 = GetLength3D(VVar2);
  fVar6 = *(float *)((int)param_2.z + 8);
  if (0.0 <= CameraTime) {
    fStack_8 = (float)((ulonglong)*(undefined8 *)param_2.z >> 0x20);
    local_c = (float)*(undefined8 *)param_2.z;
    iVar4 = SecondsToTurns(1.0);
    fVar1 = 1.0 / (float)iVar4;
    CircleCalculation.x = (local_c + fStack_8) * fVar1 + CircleCalculation.x;
    CircleCalculation.y = (fVar6 + fStack_8) * fVar1 + CircleCalculation.y;
    CircleCalculation.z = CircleCalculation.z + (fVar6 + local_c) * fVar1;
    fVar6 = portable_sin(CircleCalculation.x * (float)___real_3f91df46a0000000);
    CameraPosition.x = fVar6 * fVar5;
    fVar6 = portable_cos(CircleCalculation.y * (float)___real_3f91df46a0000000);
    CameraPosition.y = fVar6 * fVar5;
    fVar6 = portable_cos(CircleCalculation.z * (float)___real_3f91df46a0000000);
    CameraPosition.z = fVar6 * fVar5;
  }
  else {
    CameraTime = 1.0;
    CameraPosition.x = (float)param_1;
    CameraPosition.y = param_2.x;
    CameraPosition.z = param_2.y;
    CircleCalculation.x = 0.0;
    CircleCalculation.y = 0.0;
    CircleCalculation.z = 0.0;
  }
  bVar3 = CameraObject(in_ECX,CameraPosition.x,CameraPosition.y,CameraPosition.z,in_EDX);
  if ((!bVar3) && (bVar3 = IsAround(in_EDX), bVar3)) {
    return false;
  }
  CameraTime = -1.0;
  return true;
}


// ---------------------------------------------------------------------
// FormatConsoleMessage  @ 4fc029c3  lines 833-872


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __cdecl FormatConsoleMessage(char *param_1)

{
  char cVar1;
  char *pcVar2;
  ulong64 *puVar3;
  char *pcVar4;
  char *unaff_EDI;
  char *pcVar5;
  undefined1 uStack00000008;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined1 *puVar9;
  char local_804 [2048];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)local_804;
  pcVar2 = FormatFromFile(unaff_EDI);
  memset(local_804,0,0x800);
  puVar9 = &uStack00000008;
  uVar8 = 0;
  uVar7 = 0xffffffff;
  pcVar4 = local_804;
  uVar6 = 0x800;
  puVar3 = __local_stdio_printf_options();
  __stdio_common_vsnprintf_s
            ((int)*puVar3,*(undefined4 *)((int)puVar3 + 4),pcVar4,uVar6,uVar7,pcVar2,uVar8,puVar9);
  pcVar4 = local_804;
  do {
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  if ((uint)((int)pcVar4 - (int)(local_804 + 1)) < 0x200) {
    PrintConsoleMessage(local_804);
  }
  else {
    pcVar2 = local_804;
    pcVar4 = pcVar2;
    pcVar5 = pcVar2;
    while (local_804[0] != '\0') {
      if (0x1ff < (int)pcVar5 - (int)pcVar4) goto LAB_4fc02a9e;
      if (*pcVar2 == '\n') {
        *pcVar2 = '\0';
        if ((local_804 < pcVar2) && (pcVar2[-1] == '\r')) {
          pcVar2[-1] = '\0';
        }
        PrintConsoleMessage(pcVar4);
        pcVar4 = pcVar2 + 1;
        pcVar5 = pcVar2;
      }
      pcVar2 = pcVar2 + 1;
      local_804[0] = *pcVar2;
    }
    if ((pcVar4 <= pcVar5 + 1) && ((int)pcVar5 - (int)pcVar4 < 0x200)) {
LAB_4fc02a9e:
      PrintConsoleMessage(pcVar4);
    }
  }
  return;
}


// ---------------------------------------------------------------------
// FileOpen  @ 4fc02abb  lines 876-936


/* WARNING: Function: _chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

bool __cdecl FileOpen(char *param_1,bool param_2)

{
  int iVar1;
  bool bVar2;
  _List_iterator<std::_List_val<std::_List_simple_types<std::pair<char_const_*_const,_iobuf_*>_>_>_>
  _Var3;
  char *pcVar4;
  wchar_t *pwVar5;
  FILE *pFVar6;
  _iobuf **pp_Var7;
  _Hash<std::_Umap_traits<char_const_*,_iobuf_*,std::_Uhash_compare<char_const_*,std::hash<char_const_*>,std::equal_to<char_const_*>_>,std::allocator<std::pair<char_const_*_const,_iobuf_*>_>,0>_>
  *in_ECX;
  unordered_map<char_const_*,_iobuf_*,std::hash<char_const_*>,std::equal_to<char_const_*>,std::allocator<std::pair<char_const_*_const,_iobuf_*>_>_>
  *this;
  char in_DL;
  int aiStackY_1050 [6];
  undefined1 auStackY_1038 [4];
  int aiStackY_1034 [2];
  undefined4 uStack_1024;
  char *local_1014;
  uint local_1010;
  _Hash<std::_Umap_traits<char_const_*,_iobuf_*,std::_Uhash_compare<char_const_*,std::hash<char_const_*>,std::equal_to<char_const_*>_>,std::allocator<std::pair<char_const_*_const,_iobuf_*>_>,0>_>
  *local_100c;
  undefined1 local_1008 [116];
  undefined1 local_f94 [3980];
  uint local_8;
  
  local_8 = __security_cookie ^ (uint)local_f94;
  uStack_1024 = &local_100c;
  local_100c = in_ECX;
  _Var3 = std::
          _Hash<std::_Umap_traits<char_const_*,_iobuf_*,std::_Uhash_compare<char_const_*,std::hash<char_const_*>,std::equal_to<char_const_*>_>,std::allocator<std::pair<char_const_*_const,_iobuf_*>_>,0>_>
          ::find(in_ECX,&local_1014);
  if (*(int *)_Var3 != FileNameMap._4_4_) {
    return true;
  }
  aiStackY_1034[1] = 0x4fc02b10;
  pcVar4 = strstr((char *)in_ECX,"..");
  if (pcVar4 == (char *)0x0) {
    aiStackY_1034[1] = 0x4fc02b24;
    pcVar4 = strstr((char *)local_100c,":");
    if (pcVar4 == (char *)0x0) {
      local_1010 = 0;
      aiStackY_1034[1] = 0x4fc02b3e;
      GetOutputPath(&local_1010,(wchar_t *)0x0);
      iVar1 = local_1010 * -2;
      *(int *)((int)aiStackY_1034 + iVar1 + 0xc) = (int)aiStackY_1034 + iVar1 + 0x10;
      *(uint **)((int)aiStackY_1034 + iVar1 + 8) = &local_1010;
      *(undefined4 *)((int)aiStackY_1034 + iVar1 + 4) = 0x4fc02b53;
      bVar2 = GetOutputPath(*(uint **)((int)aiStackY_1034 + iVar1 + 8),
                            *(wchar_t **)((int)aiStackY_1034 + iVar1 + 0xc));
      if (!bVar2) {
        return false;
      }
      *(undefined4 *)((int)aiStackY_1034 + iVar1 + 0xc) = 0x1000;
      *(undefined4 *)((int)aiStackY_1034 + iVar1 + 8) = 0;
      *(undefined1 **)((int)aiStackY_1034 + iVar1 + 4) = local_1008;
      *(undefined4 *)((int)aiStackY_1034 + iVar1) = 0x4fc02b69;
      memset(*(void **)((int)aiStackY_1034 + iVar1 + 4),*(int *)((int)aiStackY_1034 + iVar1 + 8),
             *(size_t *)((int)aiStackY_1034 + iVar1 + 0xc));
      *(_Hash<std::_Umap_traits<char_const_*,_iobuf_*,std::_Uhash_compare<char_const_*,std::hash<char_const_*>,std::equal_to<char_const_*>_>,std::allocator<std::pair<char_const_*_const,_iobuf_*>_>,0>_>
        **)((int)aiStackY_1034 + iVar1) = local_100c;
      *(int *)(auStackY_1038 + iVar1) = (int)aiStackY_1034 + iVar1 + 0x10;
      *(wchar_t **)((int)aiStackY_1050 + iVar1 + 0x14) = L"%slogs\\%S";
      *(undefined1 **)((int)aiStackY_1050 + iVar1 + 0x10) = local_1008;
      *(undefined4 *)((int)aiStackY_1050 + iVar1 + 0xc) = 0x4fc02b7b;
      swprintf_s<2048>(*(wchar_t (**) [2048])((int)aiStackY_1050 + iVar1 + 0x10),
                       *(wchar_t **)((int)aiStackY_1050 + iVar1 + 0x14));
      pwVar5 = L"a+";
      if (in_DL == '\0') {
        pwVar5 = L"w+";
      }
      *(undefined4 *)((int)aiStackY_1050 + iVar1 + 0xc) = 0x20;
      *(wchar_t **)((int)aiStackY_1050 + iVar1 + 8) = pwVar5;
      *(undefined1 **)((int)aiStackY_1050 + iVar1 + 4) = local_1008;
      *(undefined4 *)((int)aiStackY_1050 + iVar1) = 0x4fc02b97;
      pFVar6 = _wfsopen(*(wchar_t **)((int)aiStackY_1050 + iVar1 + 4),
                        *(wchar_t **)((int)aiStackY_1050 + iVar1 + 8),
                        *(int *)((int)aiStackY_1050 + iVar1 + 0xc));
      if (pFVar6 == (FILE *)0x0) {
        *(undefined1 **)((int)aiStackY_1034 + iVar1 + 0xc) = local_1008;
        *(char **)((int)aiStackY_1034 + iVar1 + 8) = "ERROR: Could not open File: \'%s\'";
        *(undefined4 *)((int)aiStackY_1034 + iVar1 + 4) = 0x4fc02bbe;
        FormatLogMessage(*(char **)((int)aiStackY_1034 + iVar1 + 8));
        return false;
      }
      *(_Hash<std::_Umap_traits<char_const_*,_iobuf_*,std::_Uhash_compare<char_const_*,std::hash<char_const_*>,std::equal_to<char_const_*>_>,std::allocator<std::pair<char_const_*_const,_iobuf_*>_>,0>_>
        ***)((int)aiStackY_1034 + iVar1 + 0xc) = &local_100c;
      *(undefined4 *)((int)aiStackY_1034 + iVar1 + 8) = 0x4fc02ba9;
      pp_Var7 = std::
                unordered_map<char_const_*,_iobuf_*,std::hash<char_const_*>,std::equal_to<char_const_*>,std::allocator<std::pair<char_const_*_const,_iobuf_*>_>_>
                ::operator[](this,*(char ***)((int)aiStackY_1034 + iVar1 + 0xc));
      *pp_Var7 = (_iobuf *)pFVar6;
      return true;
    }
  }
  aiStackY_1034[1] = 0x4fc02bcd;
  FormatConsoleMessage("ERROR: Invalid name format for File: \'%s\', \':\' or \'..\' not allowed.");
  return false;
}


// ---------------------------------------------------------------------
// FormatFileMessage  @ 4fc02bef  lines 940-952


bool __cdecl FormatFileMessage(char *param_1,bool param_2,char *param_3)

{
  FILE *_File;
  bool bVar1;
  _iobuf **pp_Var2;
  ulong64 *puVar3;
  unordered_map<char_const_*,_iobuf_*,std::hash<char_const_*>,std::equal_to<char_const_*>,std::allocator<std::pair<char_const_*_const,_iobuf_*>_>_>
  *this;
  char *unaff_EBP;
  bool unaff_retaddr;
  undefined1 uStack00000010;
  FILE *pFVar4;
  char *pcVar5;
  undefined4 uVar6;
  undefined1 *puVar7;
  
  bVar1 = FileOpen(unaff_EBP,unaff_retaddr);
  if (bVar1) {
    pp_Var2 = std::
              unordered_map<char_const_*,_iobuf_*,std::hash<char_const_*>,std::equal_to<char_const_*>,std::allocator<std::pair<char_const_*_const,_iobuf_*>_>_>
              ::operator[](this,&param_1);
    _File = (FILE *)*pp_Var2;
    puVar7 = &uStack00000010;
    uVar6 = 0;
    pFVar4 = _File;
    pcVar5 = param_3;
    puVar3 = __local_stdio_printf_options();
    __stdio_common_vfprintf
              ((int)*puVar3,*(undefined4 *)((int)puVar3 + 4),pFVar4,pcVar5,uVar6,puVar7);
    fputs("\n",_File);
    return true;
  }
  return false;
}


// ---------------------------------------------------------------------
// CloseOpenFiles  @ 4fc02c3f  lines 967-976


void __cdecl CloseOpenFiles(void)

{
  _List_iterator<std::_List_val<std::_List_simple_types<std::pair<char_const_*_const,_iobuf_*>_>_>_>
  _Var1;
  int iVar2;
  undefined1 local_4 [4];
  
  iVar2 = *(int *)FileNameMap._4_4_;
  if (iVar2 != FileNameMap._4_4_) {
    do {
      if (*(int *)(iVar2 + 0xc) != 0) {
        fclose(*(FILE **)(iVar2 + 0xc));
      }
      _Var1 = std::
              _Hash<std::_Umap_traits<char_const_*,_iobuf_*,std::_Uhash_compare<char_const_*,std::hash<char_const_*>,std::equal_to<char_const_*>_>,std::allocator<std::pair<char_const_*_const,_iobuf_*>_>,0>_>
              ::
              erase<std::_List_iterator<std::_List_val<std::_List_simple_types<std::pair<char_const_*_const,_iobuf_*>_>_>_>,void>
                        ((_Hash<std::_Umap_traits<char_const_*,_iobuf_*,std::_Uhash_compare<char_const_*,std::hash<char_const_*>,std::equal_to<char_const_*>_>,std::allocator<std::pair<char_const_*_const,_iobuf_*>_>,0>_>
                          *)&FileNameMap,
                         (_List_iterator<std::_List_val<std::_List_simple_types<std::pair<char_const_*_const,_iobuf_*>_>_>_>
                          )local_4);
      iVar2 = *(int *)_Var1;
    } while (iVar2 != FileNameMap._4_4_);
  }
  return;
}


// ---------------------------------------------------------------------
// OpenLogFile  @ 4fc02c79  lines 987-1012


/* WARNING: Function: _chkstk replaced with injection: alloca_probe */
/* WARNING: Function: _alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Unable to track spacebase fully for stack */

bool __cdecl OpenLogFile(void)

{
  int iVar1;
  bool bVar2;
  int aiStackY_12f4 [128];
  undefined4 local_10b8;
  size_t local_10b4;
  uint local_10b0;
  tm local_10ac;
  undefined1 local_1088 [4096];
  char local_88 [64];
  char local_48 [64];
  undefined4 local_8;
  
  local_8 = __security_cookie ^ (uint)(local_48 + 0x44);
  local_10b8 = 0;
  local_10b4 = 0;
  _time64((__time64_t *)&local_10b8);
  _localtime64_s(&local_10ac,(__time64_t *)&local_10b8);
  memset(local_88,0,0x40);
  memset(local_48,0,0x40);
  strftime(local_48,0x40,"%Y-%m-%d %H.%M.%S %p.log",&local_10ac);
  if (LogFileName[0] == '\0') {
    sprintf_s<64>(&local_88,"BZClassic_%s");
  }
  else {
    sprintf_s<64>(&local_88,"%s_%s");
  }
  local_10b0 = 0;
  GetOutputPath(&local_10b0,(wchar_t *)0x0);
  iVar1 = local_10b0 * -2;
  *(int *)((int)aiStackY_12f4 + iVar1 + 0x230) = (int)aiStackY_12f4 + iVar1 + 0x234;
  *(uint **)((int)aiStackY_12f4 + iVar1 + 0x22c) = &local_10b0;
  *(undefined4 *)((int)aiStackY_12f4 + iVar1 + 0x228) = 0x4fc02d5f;
  bVar2 = GetOutputPath(*(uint **)((int)aiStackY_12f4 + iVar1 + 0x22c),
                        *(wchar_t **)((int)aiStackY_12f4 + iVar1 + 0x230));
  if (bVar2) {
    *(undefined4 *)((int)aiStackY_12f4 + iVar1 + 0x230) = 0x1000;
    *(undefined4 *)((int)aiStackY_12f4 + iVar1 + 0x22c) = 0;
    *(undefined1 **)((int)aiStackY_12f4 + iVar1 + 0x228) = local_1088;
    *(undefined4 *)((int)aiStackY_12f4 + iVar1 + 0x224) = 0x4fc02d77;
    memset(*(void **)((int)aiStackY_12f4 + iVar1 + 0x228),
           *(int *)((int)aiStackY_12f4 + iVar1 + 0x22c),
           *(size_t *)((int)aiStackY_12f4 + iVar1 + 0x230));
    *(char **)((int)aiStackY_12f4 + iVar1 + 0x224) = local_88;
    *(int *)((int)aiStackY_12f4 + iVar1 + 0x220) = (int)aiStackY_12f4 + iVar1 + 0x234;
    *(wchar_t **)((int)aiStackY_12f4 + iVar1 + 0x21c) = L"%slogs/%S";
    *(undefined1 **)((int)aiStackY_12f4 + iVar1 + 0x218) = local_1088;
    *(undefined4 *)((int)aiStackY_12f4 + iVar1 + 0x214) = 0x4fc02d90;
    swprintf_s<2048>(*(wchar_t (**) [2048])((int)aiStackY_12f4 + iVar1 + 0x218),
                     *(wchar_t **)((int)aiStackY_12f4 + iVar1 + 0x21c));
    *(undefined4 *)((int)aiStackY_12f4 + iVar1 + 0x214) = 0x20;
    *(wchar_t **)((int)aiStackY_12f4 + iVar1 + 0x210) = L"a+";
    *(undefined1 **)((int)aiStackY_12f4 + iVar1 + 0x20c) = local_1088;
    *(undefined4 *)((int)aiStackY_12f4 + iVar1 + 0x208) = 0x4fc02da4;
    LogFile = (_iobuf *)
              _wfsopen(*(wchar_t **)((int)aiStackY_12f4 + iVar1 + 0x20c),
                       *(wchar_t **)((int)aiStackY_12f4 + iVar1 + 0x210),
                       *(int *)((int)aiStackY_12f4 + iVar1 + 0x214));
  }
  return bVar2;
}


// ---------------------------------------------------------------------
// FormatLogMessage  @ 4fc02dc6  lines 1015-1049


/* WARNING: Function: _chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool __cdecl FormatLogMessage(char *param_1)

{
  ulong64 *puVar1;
  int iVar2;
  undefined1 uStack00000008;
  char *pcVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  ulonglong uVar6;
  undefined1 *puVar7;
  undefined4 local_1080;
  undefined4 local_107c;
  tm local_1074;
  char local_1050 [2048];
  char local_850 [2048];
  char local_50 [68];
  uint local_c;
  undefined4 uStack_8;
  
  uStack_8 = 0x4fc02dd3;
  local_c = __security_cookie ^ (uint)(local_50 + 0x4c);
  memset(local_850,0,0x800);
  puVar7 = &uStack00000008;
  uVar6 = ZEXT48(param_1);
  pcVar3 = local_850;
  uVar5 = 0xffffffff;
  uVar4 = 0x800;
  puVar1 = __local_stdio_printf_options();
  __stdio_common_vsnprintf_s
            ((int)*puVar1,*(undefined4 *)((int)puVar1 + 4),pcVar3,uVar4,uVar5,uVar6,puVar7);
  local_1080 = 0;
  local_107c = 0;
  _time64((__time64_t *)&local_1080);
  _localtime64_s(&local_1074,(__time64_t *)&local_1080);
  memset(local_50,0,0x40);
  strftime(local_50,0x40,"%H:%M:%S",&local_1074);
  if ((LogFile == (_iobuf *)0x0) && (OpenLogFile(), LogFile == (_iobuf *)0x0)) {
    memset(local_1050,0,0x800);
    sprintf_s<2048>(&local_1050,"ERROR: Unable to open Log File! Reporting: \'%s\'");
    FormatConsoleMessage(local_1050);
    return false;
  }
  fprintf(LogFile,"%s | %f \t| %s\n");
  iVar2 = GetVarItemInt("network.session.ivar115");
  if ((iVar2 != 0) || (iVar2 = GetVarItemInt("network.session.civar5"), iVar2 != 0)) {
    FormatConsoleMessage(local_850);
  }
  return true;
}


// ---------------------------------------------------------------------
// FormatToMessagesBox  @ 4fc02f1b  lines 1080-1088


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __cdecl FormatToMessagesBox(char *param_1,ulong param_2)

{
  char *pcVar1;
  ulong64 *puVar2;
  char *unaff_EDI;
  undefined1 uStack0000000c;
  char *pcVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined1 *puVar7;
  char local_808 [2048];
  undefined4 local_8;
  
  local_8 = __security_cookie ^ (uint)(local_808 + 0x804);
  pcVar1 = FormatFromFile(unaff_EDI);
  memset(local_808,0,0x800);
  puVar7 = &uStack0000000c;
  uVar6 = 0;
  uVar5 = 0xffffffff;
  pcVar3 = local_808;
  uVar4 = 0x800;
  puVar2 = __local_stdio_printf_options();
  __stdio_common_vsnprintf_s
            ((int)*puVar2,*(undefined4 *)((int)puVar2 + 4),pcVar3,uVar4,uVar5,pcVar1,uVar6,puVar7);
  AddToMessagesBox2(local_808,param_2);
  return;
}


// ---------------------------------------------------------------------
// FormatFromFile  @ 4fc02f93  lines 1142-1180


char * __cdecl FormatFromFile(char *param_1)

{
  char cVar1;
  int iVar2;
  char *_Dst;
  char *_Src;
  char *in_ECX;
  char *pcVar3;
  uint local_8;
  
  pcVar3 = in_ECX;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  if ((uint)((int)pcVar3 - (int)(in_ECX + 1)) < 0x41) {
    pcVar3 = in_ECX + (((int)pcVar3 - (int)(in_ECX + 1)) - 4);
    iVar2 = _stricmp(pcVar3,".txt");
    if (iVar2 != 0) {
      iVar2 = _stricmp(pcVar3,".inf");
      if (iVar2 != 0) {
        iVar2 = _stricmp(pcVar3,".des");
        if (iVar2 != 0) {
          iVar2 = _stricmp(pcVar3,".brf");
          if (iVar2 != 0) {
            iVar2 = _stricmp(pcVar3,".otf");
            if (iVar2 != 0) {
              iVar2 = _stricmp(pcVar3,".odf");
              if (iVar2 != 0) goto LAB_4fc03046;
            }
          }
        }
      }
    }
    local_8 = 0;
    LoadFile(in_ECX,(void *)0x0,&local_8);
    _Dst = malloc(local_8 + 1);
    LoadFile(in_ECX,_Dst,&local_8);
    _Dst[local_8] = '\0';
  }
  else {
LAB_4fc03046:
    _Src = GetBZCCLocalizedString("mission",in_ECX);
    pcVar3 = _Src;
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    _Dst = malloc((size_t)(pcVar3 + (1 - (int)(_Src + 1))));
    strcpy_s(_Dst,(rsize_t)(pcVar3 + (1 - (int)(_Src + 1))),_Src);
  }
  return _Dst;
}


// ---------------------------------------------------------------------
// IsObjectFacingObject  @ 4fc03081  lines 1278-1286


bool __cdecl IsObjectFacingObject(int param_1,int param_2,float param_3)

{
  bool bVar1;
  int in_ECX;
  int in_EDX;
  float10 fVar2;
  float fVar3;
  Matrix local_a0;
  Matrix local_60;
  double local_20;
  double local_18;
  float local_c;
  
  bVar1 = IsAround(in_ECX);
  if ((bVar1) && (bVar1 = IsAround(in_EDX), bVar1)) {
    GetPosition(in_ECX,&local_60);
    GetPosition(in_EDX,&local_a0);
    local_c = (local_60.posit.z - local_a0.posit.z) * (local_60.posit.z - local_a0.posit.z) +
              (local_60.posit.x - local_a0.posit.x) * (local_60.posit.x - local_a0.posit.x);
    local_20 = (double)((local_a0.posit.x - local_60.posit.x) * local_60.front.x +
                       local_60.front.z * (local_a0.posit.z - local_60.posit.z));
    fVar3 = portable_cos((float)param_1);
    local_18 = (double)fVar3;
    fVar2 = (float10)__CIsqrt();
    if ((float)fVar2 * (float)local_18 < (float)local_20) {
      return true;
    }
  }
  return false;
}


// ---------------------------------------------------------------------
// GetVectorFromPath  @ 4fc0312e  lines 1379-1399


/* WARNING: Function: _alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Unable to track spacebase fully for stack */

Vector * __cdecl GetVectorFromPath(Vector *__return_storage_ptr__,char *param_1,int param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  bool bVar4;
  Vector *in_ECX;
  undefined4 extraout_ECX;
  char *in_EDX;
  float fVar5;
  undefined4 uStackY_38;
  undefined1 auStack_1a [2];
  float local_18 [3];
  uint local_c;
  float local_8;
  
  local_8 = (float)(__security_cookie ^ (uint)(local_18 + 5));
  local_c = 0;
  in_ECX->x = 0.0;
  in_ECX->y = 0.0;
  in_ECX->z = 0.0;
  if (in_EDX != (char *)0x0) {
    uStackY_38 = 0x4fc03167;
    GetPathPoints(in_EDX,&local_c,(float *)0x0);
    if ((local_c != 0) && ((int)__return_storage_ptr__ < (int)local_c)) {
      iVar3 = local_c * -8;
      *(undefined1 **)(auStack_1a + iVar3 + -0x12) = auStack_1a + iVar3 + -0xe;
      *(uint **)(auStack_1a + iVar3 + -0x16) = &local_c;
      *(char **)(auStack_1a + iVar3 + -0x1a) = in_EDX;
      *(undefined4 *)(auStack_1a + iVar3 + -0x1e) = 0x4fc0318b;
      bVar4 = GetPathPoints(*(char **)(auStack_1a + iVar3 + -0x1a),
                            *(uint **)(auStack_1a + iVar3 + -0x16),
                            *(float **)(auStack_1a + iVar3 + -0x12));
      if (bVar4) {
        *(undefined4 *)(auStack_1a + iVar3 + -0x12) = extraout_ECX;
        *(undefined4 *)(auStack_1a + iVar3 + -0x16) = extraout_ECX;
        fVar1 = *(float *)(auStack_1a + (int)__return_storage_ptr__ * 8 + iVar3 + -0xe);
        *(undefined4 *)(auStack_1a + iVar3 + -0x12) =
             *(undefined4 *)(auStack_1a + (int)__return_storage_ptr__ * 8 + iVar3 + -10);
        *(float *)(auStack_1a + iVar3 + -0x16) = fVar1;
        *(undefined4 *)(auStack_1a + iVar3 + -0x1a) = 0x4fc031bd;
        fVar5 = TerrainFindFloor(*(float *)(auStack_1a + iVar3 + -0x16),
                                 *(float *)(auStack_1a + iVar3 + -0x12));
        fVar2 = *(float *)(auStack_1a + (int)__return_storage_ptr__ * 8 + iVar3 + -10);
        in_ECX->x = fVar1;
        in_ECX->y = fVar5;
        in_ECX->z = fVar2;
      }
    }
  }
  return in_ECX;
}


// ---------------------------------------------------------------------
// GetRandomTeam  @ 4fc031e9  lines 1441-1475


int __cdecl GetRandomTeam(int param_1,int param_2,bool param_3,bool param_4)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int in_EDX;
  int unaff_ESI;
  int iVar4;
  int unaff_EDI;
  
  iVar2 = GetRandomInt(unaff_EDI,unaff_ESI);
  iVar4 = iVar2;
  do {
    if ((((in_EDX < 0) || (bVar1 = TeamFilterCheck(in_EDX,unaff_EDI,unaff_ESI), bVar1)) &&
        ((((char)param_1 == '\0' ||
          ((((iVar3 = GetPlayerHandle(iVar4), iVar3 != 0 ||
             (iVar3 = GetObjectByTeamSlot(iVar4,1), iVar3 != 0)) ||
            (iVar3 = GetObjectByTeamSlot(iVar4,2), iVar3 != 0)) ||
           ((iVar3 = GetObjectByTeamSlot(iVar4,3), iVar3 != 0 ||
            (iVar3 = GetObjectByTeamSlot(iVar4,9), iVar3 != 0)))))) ||
         ((iVar3 = GetObjectByTeamSlot(iVar4,10), iVar3 != 0 ||
          (((iVar3 = GetObjectByTeamSlot(iVar4,0xb), iVar3 != 0 ||
            (iVar3 = GetObjectByTeamSlot(iVar4,0xc), iVar3 != 0)) ||
           ((iVar3 = GetObjectByTeamSlot(iVar4,0xd), iVar3 != 0 ||
            (iVar3 = GetObjectByTeamSlot(iVar4,0xe), iVar3 != 0)))))))))) && (0 < iVar4)) {
      return iVar4;
    }
    iVar3 = iVar4 + 1;
    iVar4 = 0;
    if (iVar3 < 0x10) {
      iVar4 = iVar3;
    }
  } while (iVar4 != iVar2);
  return -1;
}


// ---------------------------------------------------------------------
// GetWindingNumber  @ 4fc032b0  lines 1480-1503


int __cdecl GetWindingNumber(vector<VECTOR_2D,std::allocator<VECTOR_2D>_> *param_1,Vector *param_2)

{
  int iVar1;
  int iVar2;
  int extraout_EAX;
  int extraout_EAX_00;
  int *in_ECX;
  int iVar3;
  int in_EDX;
  int iVar4;
  int iVar5;
  int iVar6;
  float10 fVar7;
  float10 fVar8;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  
  iVar1 = *in_ECX;
  iVar5 = 0;
  iVar6 = in_ECX[1] - iVar1 >> 3;
  iVar2 = 1;
  iVar4 = 0;
  if (0 < iVar6) {
    fVar7 = (float10)*(float *)(in_EDX + 8);
    do {
      iVar3 = 0;
      if (iVar2 < iVar6) {
        iVar3 = iVar2;
      }
      fVar8 = (float10)*(float *)(iVar1 + 4 + iVar3 * 8);
      if (fVar7 < (float10)*(float *)(iVar1 + 4 + iVar4 * 8)) {
        if (fVar8 <= fVar7) {
          _ftol2_sse();
          fVar7 = extraout_ST0_00;
          if (extraout_EAX_00 < 0) {
            iVar5 = iVar5 + -1;
          }
        }
      }
      else if (fVar7 < fVar8) {
        _ftol2_sse();
        fVar7 = extraout_ST0;
        if (0 < extraout_EAX) {
          iVar5 = iVar5 + 1;
        }
      }
      iVar4 = iVar4 + 1;
      iVar2 = iVar3 + 1;
    } while (iVar4 < iVar6);
  }
  return iVar5;
}


// ---------------------------------------------------------------------
// GetWindingNumber  @ 4fc03386  lines 1507-1534


/* WARNING: Function: _alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Unable to track spacebase fully for stack */

int __cdecl GetWindingNumber(char *param_1,Vector param_2)

{
  int iVar1;
  bool bVar2;
  undefined4 *puVar3;
  char *in_ECX;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined4 uStackY_48;
  undefined1 auStack_2a [2];
  uint local_28 [3];
  vector<VECTOR_2D,std::allocator<VECTOR_2D>_> local_1c;
  uint local_10;
  uint local_c;
  undefined1 auStack_8 [4];
  
  local_c = __security_cookie ^ (uint)(auStack_8 + 4);
  iVar5 = 0;
  local_10 = 0;
  if (in_ECX != (char *)0x0) {
    uStackY_48 = 0x4fc033b4;
    GetPathPoints(in_ECX,&local_10,(float *)0x0);
    if (local_10 != 0) {
      iVar6 = 0;
      local_1c._0_4_ = 0;
      local_1c._8_4_ = 0;
      local_1c._4_4_ = 0;
      iVar1 = local_10 * -8;
      *(undefined1 **)(auStack_2a + iVar1 + -0x12) = auStack_2a + iVar1 + -0xe;
      *(uint **)(auStack_2a + iVar1 + -0x16) = &local_10;
      *(char **)(auStack_2a + iVar1 + -0x1a) = in_ECX;
      *(undefined4 *)(auStack_2a + iVar1 + -0x1e) = 0x4fc033e6;
      bVar2 = GetPathPoints(*(char **)(auStack_2a + iVar1 + -0x1a),
                            *(uint **)(auStack_2a + iVar1 + -0x16),
                            *(float **)(auStack_2a + iVar1 + -0x12));
      if ((bVar2) && (uVar4 = 0, local_10 != 0)) {
        do {
          local_28[1] = *(undefined4 *)(auStack_2a + uVar4 * 8 + iVar1 + -0xe);
          local_28[2] = *(undefined4 *)(auStack_2a + uVar4 * 8 + iVar1 + -10);
          if (iVar6 == iVar5) {
            *(uint **)(auStack_2a + iVar1 + -0x12) = local_28 + 1;
            *(int *)(auStack_2a + iVar1 + -0x16) = iVar5;
            *(undefined4 *)(auStack_2a + iVar1 + -0x1a) = 0x4fc03437;
            std::vector<VECTOR_2D,std::allocator<VECTOR_2D>_>::
            _Emplace_reallocate<VECTOR_2D_const_&>
                      (&local_1c,*(VECTOR_2D **)(auStack_2a + iVar1 + -0x16),
                       *(VECTOR_2D **)(auStack_2a + iVar1 + -0x12));
            iVar6 = local_1c._8_4_;
          }
          else {
            *(undefined4 *)(auStack_2a + iVar1 + -0x12) = 0x4fc03417;
            puVar3 = operator_new(*(uint *)(auStack_2a + iVar1 + -0xe),
                                  *(void **)(auStack_2a + iVar1 + -10));
            local_1c._4_4_ = iVar5 + 8;
            *puVar3 = local_28[1];
            puVar3[1] = local_28[2];
          }
          uVar4 = uVar4 + 1;
          iVar5 = local_1c._4_4_;
        } while (uVar4 < local_10);
        iVar5 = local_1c._0_4_;
      }
      *(undefined4 *)(auStack_2a + iVar1 + -0x12) = 0x4fc03451;
      iVar6 = GetWindingNumber(*(vector<VECTOR_2D,std::allocator<VECTOR_2D>_> **)
                                (auStack_2a + iVar1 + -0xe),*(Vector **)(auStack_2a + iVar1 + -10));
      if (iVar5 != 0) {
        *(undefined4 *)(auStack_2a + iVar1 + -0x12) = 0x4fc03465;
        std::_Deallocate<8,0>
                  (*(void **)(auStack_2a + iVar1 + -0xe),*(uint *)(auStack_2a + iVar1 + -10));
      }
      return iVar6;
    }
  }
  return 0;
}


// ---------------------------------------------------------------------
// DoesPathExist  @ 4fc0347d  lines 1565-1571


int __cdecl DoesPathExist(char *param_1)

{
  uint uVar1;
  char *in_ECX;
  uint local_8;
  
  local_8 = 0;
  uVar1 = 0;
  if (in_ECX != (char *)0x0) {
    GetPathPoints(in_ECX,&local_8,(float *)0x0);
    uVar1 = local_8;
  }
  return uVar1;
}


// ---------------------------------------------------------------------
// SetAmmo  @ 4fc0349e  lines 1661-1671


void __cdecl SetAmmo(int param_1,float param_2)

{
  long lVar1;
  long extraout_EAX;
  int in_ECX;
  
  lVar1 = GetMaxAmmo(in_ECX);
  if (lVar1 != -0x4d2) {
    _ftol2_sse();
    SetCurAmmo(in_ECX,extraout_EAX);
  }
  return;
}


// ---------------------------------------------------------------------
// GiveWeapon  @ 4fc03500  lines 1675-1753


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool __cdecl GiveWeapon(int param_1,char *param_2,int param_3)

{
  bool bVar1;
  int iVar2;
  int in_ECX;
  char *in_EDX;
  char *unaff_ESI;
  bool *unaff_EDI;
  char *pcVar3;
  float fVar4;
  float *pfVar5;
  undefined1 uStack_220;
  char local_21f;
  char local_21e;
  char local_21d;
  float local_21c [21];
  char local_1c8 [64];
  char local_188 [64];
  char local_148 [324];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)&uStack_220;
  if (*in_EDX == '\0') {
    GiveWeapon(in_ECX,param_1,in_EDX);
    bVar1 = true;
  }
  else {
    bVar1 = DoesODFExist(in_EDX);
    if (bVar1) {
      local_21c[0] = 0.0;
      local_21c[1] = 0.0;
      local_21c[2] = 0.0;
      local_21c[3] = 0.0;
      local_21c[4] = 0.0;
      memset(local_148,0,0x140);
      local_21f = '\0';
      memset(local_21c + 5,0,0x40);
      CombineStrings(in_EDX,(char *)0x40,unaff_EDI,(uint)unaff_ESI);
      memset(local_188,0,0x40);
      sprintf_s<64>(&local_188,"weaponAssault%d");
      GetODFBool((int)local_188,&local_21f,(char *)0x0,unaff_EDI,SUB41(unaff_ESI,0));
      if (local_21f != '\0') {
        local_21e = '\0';
        GetODFBool("WeaponClass","isAssault",&local_21e,(char *)0x0,unaff_EDI,SUB41(unaff_ESI,0));
        if (local_21e == '\0') {
          memset(local_1c8,0,0x40);
          iVar2 = GetODFString("WeaponClass","altName",(char *)0x40,local_1c8,0,unaff_EDI,unaff_ESI)
          ;
          if (iVar2 != 0) {
            local_21d = '\0';
            GetODFBool("WeaponClass","isAssault",&local_21d,(char *)0x0,unaff_EDI,SUB41(unaff_ESI,0)
                      );
            if (local_21d != '\0') {
              CombineStrings(local_1c8,(char *)0x40,unaff_EDI,(uint)unaff_ESI);
            }
          }
        }
      }
      iVar2 = 0;
      pcVar3 = local_148;
      do {
        bVar1 = GetObjInfo(in_ECX,iVar2 + Get_Weapon0Config,pcVar3);
        if (!bVar1) goto LAB_4fc03545;
        fVar4 = GetCurLocalAmmo(in_ECX,iVar2);
        local_21c[iVar2] = fVar4;
        iVar2 = iVar2 + 1;
        pcVar3 = pcVar3 + 0x40;
      } while (iVar2 < 5);
      iVar2 = _stricmp(local_148 + param_1 * 0x40,(char *)(local_21c + 5));
      if (iVar2 != 0) {
        local_21c[param_1] = 0.0;
        pfVar5 = local_21c + 5;
        pcVar3 = (char *)0x40;
        CombineStrings((char *)pfVar5,(char *)0x40,unaff_EDI,(uint)unaff_ESI);
        bVar1 = ReplaceWeapons((int)local_21c,(char (*) [64])0x0,pfVar5,pcVar3);
        return bVar1;
      }
    }
    else {
      FormatLogMessage("ERROR: Weapon ODF \'%s\' doesn\'t exist! Fix DLL\'s GiveWeapon() call!");
    }
LAB_4fc03545:
    bVar1 = false;
  }
  return bVar1;
}


// ---------------------------------------------------------------------
// GetObjectByBaseSlot  @ 4fc0373a  lines 1795-1807


int __cdecl GetObjectByBaseSlot(int param_1,int param_2)

{
  int iVar1;
  uint in_ECX;
  int in_EDX;
  
  if ((8 < in_EDX - 1U) || (0xf < in_ECX)) {
    return 0;
  }
  iVar1 = in_EDX + 5;
  if (in_EDX < 4) {
    iVar1 = in_EDX;
  }
  iVar1 = GetObjectByTeamSlot(in_ECX,iVar1);
  return iVar1;
}


// ---------------------------------------------------------------------
// GetTapCount  @ 4fc0375e  lines 1811-1832


int __cdecl GetTapCount(int param_1,bool param_2,bool param_3)

{
  int iVar1;
  long lVar2;
  int in_ECX;
  char in_DL;
  int iVar3;
  int iVar4;
  
  iVar3 = 0;
  iVar4 = 0;
  do {
    iVar1 = GetTap(in_ECX,iVar4);
    if (iVar1 != 0) {
      if (in_DL != '\0') {
        lVar2 = GetMaxHealth(iVar1);
        if (lVar2 < 1) goto LAB_4fc03789;
      }
      iVar3 = iVar3 + 1;
    }
LAB_4fc03789:
    iVar4 = iVar4 + 1;
    if (7 < iVar4) {
      return iVar3;
    }
  } while( true );
}


// ---------------------------------------------------------------------
// GetTapCount  @ 4fc03796  lines 1836-1864


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl GetTapCount(char *param_1,char *param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  bool *unaff_EBP;
  char *unaff_EDI;
  int iVar4;
  char (*pacVar5) [64];
  char *pcVar6;
  undefined1 auStack_88 [3];
  char local_85;
  char local_84 [64];
  char local_44 [64];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)auStack_88;
  iVar4 = 0;
  bVar1 = IsBuilding(unaff_EDI);
  if (bVar1) {
    local_85 = '\x01';
    iVar2 = GetODFBool("PoweredBuildingClass","PoweredByTaps",&local_85,(char *)0x1,unaff_EBP,
                       SUB41(unaff_EDI,0));
    if (iVar2 == 0) {
      GetODFBool("TurretCraftClass","PoweredByTaps",&local_85,(char *)0x1,unaff_EBP,
                 SUB41(unaff_EDI,0));
    }
    if (local_85 != '\0') {
      iVar2 = 0;
      do {
        memset(local_84,0,0x40);
        memset(local_44,0,0x40);
        iVar2 = iVar2 + 1;
        pacVar5 = &local_84;
        pcVar6 = "powerTap%d";
        sprintf_s<64>(pacVar5,"powerTap%d");
        iVar3 = GetODFString("PoweredBuildingClass",local_84,(char *)0x40,local_44,0,*pacVar5,pcVar6
                            );
        if ((iVar3 != 0) ||
           (iVar3 = GetODFString("TurretCraftClass",local_84,(char *)0x40,local_44,0,unaff_EBP,
                                 unaff_EDI), iVar3 != 0)) {
          iVar4 = iVar4 + 1;
        }
      } while (iVar2 < 8);
    }
  }
  return iVar4;
}


// ---------------------------------------------------------------------
// SetRandomHeadingAngle2  @ 4fc0389d  lines 1870-1875


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl SetRandomHeadingAngle2(int param_1)

{
  Vector VVar1;
  int in_ECX;
  Vector *unaff_ESI;
  float unaff_EDI;
  Matrix *__return_storage_ptr__;
  Matrix local_54;
  Vector local_10;
  
  local_10.x = 0.0;
  local_10.y = 0.0;
  local_10.z = 0.0;
  __return_storage_ptr__ = (Matrix *)GetRandomFloat(___real_40c90fdb);
  Build_Yaw_Matrix(__return_storage_ptr__,unaff_EDI,unaff_ESI);
  GetPosition(in_ECX,&local_10);
  local_54.posit.x = local_10.x;
  local_54.posit.y = local_10.y;
  local_54.posit.z = local_10.z;
  SetPosition(in_ECX,&local_54);
  VVar1.y = local_54.posit.y;
  VVar1.x = local_54.posit.x;
  VVar1.z = local_54.posit.z;
  SetVectorPosition(in_ECX,VVar1);
  return;
}


// ---------------------------------------------------------------------
// TeamFilterCheck  @ 4fc0390a  lines 1879-1887


bool __cdecl TeamFilterCheck(int param_1,int param_2,int param_3)

{
  bool bVar1;
  uint in_ECX;
  uint in_EDX;
  
  if (((in_EDX < 0x10) && ((uint)param_1 < 0x10)) &&
     ((((in_ECX & 1) != 0 && (in_EDX == param_1)) ||
      ((in_EDX != param_1 &&
       ((((in_ECX & 2) != 0 && (bVar1 = IsTeamAllied(in_EDX,param_1), bVar1)) ||
        (((in_ECX & 4) != 0 && (bVar1 = IsTeamAllied(in_EDX,param_1), !bVar1)))))))))) {
    return true;
  }
  return false;
}


// ---------------------------------------------------------------------
// GetEngageRange  @ 4fc0395c  lines 1956-2005


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float __cdecl GetEngageRange(int param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  char *unaff_EBX;
  float *unaff_EBP;
  float unaff_ESI;
  float *unaff_EDI;
  char (*pacVar4) [64];
  char *pcVar5;
  float local_d4;
  float local_d0;
  float local_cc;
  float local_c8;
  char local_c4 [64];
  char local_84 [64];
  char local_44 [64];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)&local_d4;
  bVar1 = IsAround(in_ECX);
  local_d4 = 0.0;
  if (bVar1) {
    local_d4 = 0.0;
    iVar2 = GetODFFloat(0x4fc5555c,(char *)&local_d4,(char *)0x0,unaff_EDI,unaff_ESI);
    if ((iVar2 == 0) &&
       (iVar2 = GetODFFloat(0x4fc55574,(char *)&local_d4,___real_43480000,unaff_EDI,unaff_ESI),
       iVar2 == 0)) {
      memset(local_c4,0,0x40);
      memset(local_84,0,0x40);
      memset(local_44,0,0x40);
      iVar2 = 0;
      do {
        local_d0 = 0.0;
        pacVar4 = &local_44;
        iVar2 = iVar2 + 1;
        pcVar5 = "weaponName%d";
        sprintf_s<64>(pacVar4,"weaponName%d");
        iVar3 = GetODFString((int)local_44,(char *)0x40,local_c4,0,*pacVar4,pcVar5);
        if ((iVar3 != 0) && (local_c4[0] != '\0')) {
          CombineStrings(".odf",(char *)0x40,(char *)unaff_EBP,(uint)unaff_EBX);
          bVar1 = OpenODF2((char *)unaff_EBP);
          if ((bVar1) &&
             ((iVar3 = GetODFFloat("WeaponClass","aiRange",(char *)&local_d0,(char *)0x0,unaff_EBP,
                                   (float)unaff_EBX), iVar3 == 0 &&
              (iVar3 = GetODFString("WeaponClass","ordName",(char *)0x40,local_84,0,
                                    (char *)unaff_EBP,unaff_EBX), iVar3 != 0)))) {
            CombineStrings(".odf",(char *)0x40,(char *)unaff_EBP,(uint)unaff_EBX);
            bVar1 = OpenODF2((char *)unaff_EBP);
            if (bVar1) {
              local_c8 = 0.0;
              local_cc = 0.0;
              GetODFFloat("OrdnanceClass","shotSpeed",(char *)&local_c8,(char *)0x0,unaff_EBP,
                          (float)unaff_EBX);
              GetODFFloat("OrdnanceClass","lifeSpan",(char *)&local_cc,(char *)0x0,unaff_EBP,
                          (float)unaff_EBX);
              local_d0 = local_cc * local_c8;
            }
          }
        }
        if (local_d4 < local_d0) {
          local_d4 = local_d0;
        }
      } while (iVar2 < 5);
    }
  }
  return local_d4;
}


// ---------------------------------------------------------------------
// GetMinFireAmmo  @ 4fc03b81  lines 2009-2074


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

long __cdecl GetMinFireAmmo(int param_1)

{
  bool bVar1;
  long lVar2;
  int iVar3;
  int in_ECX;
  int iVar4;
  char *unaff_EBP;
  char *pcVar5;
  char *unaff_EDI;
  char *pcVar6;
  char *pcVar7;
  long lVar8;
  int local_110;
  char local_10c [8];
  byte local_104 [64];
  char local_c4 [64];
  char local_84 [64];
  char local_44 [64];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)&local_110;
  bVar1 = IsAround(in_ECX);
  if (bVar1) {
    iVar4 = 0;
    local_10c[0] = '\0';
    local_10c[1] = '\0';
    local_10c[2] = '\0';
    local_10c[3] = '\0';
    local_10c[4] = '\0';
    local_10c[5] = '\0';
    lVar2 = 0;
    GetODFString(0x4fc555d0,(char *)0x6,local_10c,0x4fc555c8,unaff_EDI,unaff_EBP);
    pcVar5 = local_10c + 4;
    do {
      if (*pcVar5 != '0') {
        memset(local_c4,0,0x40);
        GetObjInfo(in_ECX,iVar4 + Get_Weapon0ODF,local_c4);
        if ((local_c4[0] != '\0') && (bVar1 = OpenODF2(unaff_EDI), bVar1)) {
          memset(local_104,0,0x40);
          memset(local_44,0,0x40);
          iVar3 = GetODFString(local_c4,"GameObjectClass","classlabel",0x40,local_44,(char *)0x0);
          if (iVar3 != 0) {
            CombineStrings(".odf",(char *)0x40,unaff_EDI,(uint)unaff_EBP);
            bVar1 = OpenODF2(unaff_EDI);
            local_104[0] = local_104[0] & -bVar1;
          }
          pcVar7 = local_84;
          pcVar6 = (char *)0x0;
          memset(pcVar7,0,0x40);
          iVar3 = GetODFString("WeaponClass","ordName",(char *)0x40,local_84,0,pcVar7,pcVar6);
          if ((iVar3 == 0) &&
             (iVar3 = GetODFString("DispenserClass","objectClass",(char *)0x40,local_84,0,unaff_EDI,
                                   unaff_EBP), iVar3 == 0)) {
            GetODFString("TorpedoLauncherClass","objectClass",(char *)0x40,local_84,0,unaff_EDI,
                         unaff_EBP);
          }
          if (local_84[0] != '\0') {
            lVar8 = 0x40;
            pcVar7 = ".odf";
            CombineStrings(".odf",(char *)0x40,unaff_EDI,(uint)unaff_EBP);
            local_110 = 0;
            iVar3 = GetODFLong("OrdnanceClass","ammoCost",(char *)&local_110,(char *)0x0,
                               (long *)pcVar7,lVar8);
            if (iVar3 != 0) {
              lVar2 = lVar2 + local_110;
            }
          }
        }
      }
      iVar4 = iVar4 + 1;
      pcVar5 = pcVar5 + -1;
    } while (iVar4 < 5);
  }
  else {
    lVar2 = 0;
  }
  return lVar2;
}


// ---------------------------------------------------------------------
// GetOrdnanceDamageDealt  @ 4fc03d97  lines 2078-2209


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

long __cdecl GetOrdnanceDamageDealt(int param_1,char *param_2,bool param_3)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  char *in_ECX;
  char *in_EDX;
  char *unaff_ESI;
  int *unaff_EDI;
  int iVar4;
  byte *pbVar5;
  char cVar6;
  ObjectInfoType OVar7;
  uint uVar8;
  char *pcVar9;
  undefined1 auStack_190 [2];
  char local_18e;
  char local_18d;
  char *local_18c;
  char *local_188;
  char local_184 [64];
  byte local_144 [64];
  char local_104 [64];
  char local_c4 [64];
  char local_84 [64];
  char local_44 [64];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)auStack_190;
  local_18c = in_EDX;
  bVar1 = IsAround((int)in_ECX);
  if (bVar1) {
    memset(local_c4,0,0x40);
    pbVar5 = local_144;
    cVar6 = '\0';
    memset(pbVar5,0,0x40);
    local_18e = '\0';
    GetODFChar(0x4fc5561c,&local_18e,(char *)0x4e,(char *)pbVar5,cVar6);
    iVar2 = toupper((int)local_18e);
    iVar4 = 0;
    do {
      memset(local_104,0,0x40);
      GetObjInfo((int)in_ECX,iVar4 + Get_Weapon0GOClass,local_104);
      iVar3 = _stricmp(local_104,"CLASS_SHIELDUP");
      if (iVar3 == 0) {
        memset(local_184,0,0x40);
        OVar7 = iVar4 + Get_Weapon0ODF;
        pcVar9 = in_ECX;
        GetObjInfo((int)in_ECX,OVar7,local_184);
        local_18d = '\0';
        GetODFChar("ShieldUpgradeClass","shieldClass",&local_18d,(char *)0x53,pcVar9,(char)OVar7);
        iVar4 = toupper((int)local_18d);
        goto LAB_4fc03eac;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < 5);
    iVar4 = 0;
LAB_4fc03eac:
    pcVar9 = local_84;
    uVar8 = 0;
    memset(pcVar9,0,0x40);
    CombineStrings(local_18c,(char *)0x40,pcVar9,uVar8);
    bVar1 = OpenODF2((char *)unaff_EDI);
    local_188 = (char *)0x0;
    if (bVar1) {
      memset(local_44,0,0x40);
      iVar3 = GetODFString(local_c4,"OrdnanceClass","classlabel",0x40,local_44,(char *)0x0);
      if (iVar3 != 0) {
        CombineStrings(".odf",(char *)0x40,(char *)unaff_EDI,(uint)unaff_ESI);
        bVar1 = OpenODF2((char *)unaff_EDI);
        local_144[0] = local_144[0] & -bVar1;
      }
      local_188 = (char *)0x0;
      local_18c = (char *)0x0;
      memset(local_184,0,0x40);
      memset(local_104,0,0x40);
      if (iVar4 != 0) {
        iVar2 = iVar4;
      }
      if (iVar2 == 0x41) {
        pcVar9 = "damageValue(A)";
      }
      else if (iVar2 == 0x44) {
        pcVar9 = "damageValue(D)";
      }
      else if (iVar2 == 0x48) {
        pcVar9 = "damageValue(H)";
      }
      else if (iVar2 == 0x4c) {
        pcVar9 = "damageValue(L)";
      }
      else if (iVar2 == 0x53) {
        pcVar9 = "damageValue(S)";
      }
      else {
        pcVar9 = "damageValue(N)";
      }
      strcpy_s(local_184,0x40,pcVar9);
      GetODFInt("OrdnanceClass",local_184,(char *)&local_188,(char *)0x0,unaff_EDI,(int)unaff_ESI);
      if ((char)param_1 != '\0') {
        bVar1 = IsBuilding((int)in_ECX);
        if (bVar1) {
          pcVar9 = "xplBuilding";
        }
        else {
          pcVar9 = "xplVehicle";
        }
        strcpy_s(local_104,0x40,pcVar9);
        iVar2 = GetODFString("OrdnanceClass",local_104,(char *)0x40,local_84,0,(char *)unaff_EDI,
                             unaff_ESI);
        if (iVar2 != 0) {
          CombineStrings(".odf",(char *)0x40,(char *)unaff_EDI,(uint)unaff_ESI);
          bVar1 = OpenODF2((char *)unaff_EDI);
          if (bVar1) {
            GetODFInt("ExplosionClass",local_184,(char *)&local_18c,(char *)0x0,unaff_EDI,
                      (int)unaff_ESI);
          }
        }
        local_188 = local_18c + (int)local_188;
      }
    }
  }
  else {
    local_188 = (char *)0xffffffff;
  }
  return (long)local_188;
}


// ---------------------------------------------------------------------
// GetODFPositionOffset  @ 4fc040cc  lines 2264-2284


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

Matrix * __cdecl
GetODFPositionOffset
          (Matrix *__return_storage_ptr__,int param_1,int param_2,Vector param_3,Vector param_4)

{
  undefined1 auVar1 [12];
  undefined1 auVar2 [12];
  float fVar3;
  bool bVar4;
  Matrix *in_ECX;
  Matrix *extraout_ECX;
  int iVar5;
  float in_EDX;
  Vector *unaff_ESI;
  Matrix *pMVar6;
  float unaff_EDI;
  Matrix *pMVar7;
  float local_f0;
  Matrix *local_ec;
  Matrix *local_e8;
  float local_e4;
  Matrix *local_e0;
  Matrix *local_dc;
  float local_d8;
  float local_d4;
  float local_d0;
  float local_cc;
  Matrix local_c8 [2];
  char local_48 [68];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)&local_f0;
  local_f0 = in_EDX;
  bVar4 = IsAround((int)in_EDX);
  if (bVar4) {
    local_cc = 0.0;
    local_d4 = 0.0;
    local_d0 = 0.0;
    memset(local_48,0,0x40);
    sprintf_s<64>((char (*) [64])local_48,"PositionOffset%d");
    local_ec = (Matrix *)0x0;
    local_e8 = (Matrix *)0x0;
    local_e4 = 0.0;
    auVar1._4_4_ = unaff_ESI;
    auVar1._0_4_ = unaff_EDI;
    auVar1._8_4_ = 0;
    GetODFVector((int)local_48,(char *)&local_d4,(char *)0x0,(Vector *)0x0,(Vector)(auVar1 << 0x20))
    ;
    local_ec = (Matrix *)((float)param_1 + local_d4);
    local_d8 = 0.0;
    local_e8 = (Matrix *)((float)param_2 + local_d0);
    local_e4 = param_3.x + local_cc;
    local_e0 = (Matrix *)0x0;
    local_dc = (Matrix *)0x0;
    local_d4 = (float)local_ec;
    local_d0 = (float)local_e8;
    local_cc = local_e4;
    sprintf_s<64>((char (*) [64])local_48,"RotationOffset%d");
    fVar3 = local_f0;
    local_ec = (Matrix *)0x0;
    local_e8 = (Matrix *)0x0;
    local_e4 = 0.0;
    auVar2._4_4_ = unaff_ESI;
    auVar2._0_4_ = unaff_EDI;
    auVar2._8_4_ = 0;
    GetODFVector((int)local_48,(char *)&local_e0,(char *)0x0,(Vector *)0x0,(Vector)(auVar2 << 0x20))
    ;
    local_e4 = (float)___real_3f91df46a0000000;
    local_ec = (Matrix *)((param_3.y + (float)local_e0) * local_e4);
    local_e8 = (Matrix *)((param_3.z + (float)local_dc) * local_e4);
    local_f0 = param_4.x + local_d8;
    local_e4 = local_e4 * local_f0;
    local_e0 = local_ec;
    local_dc = local_e8;
    local_d8 = local_e4;
    GetPosition((int)fVar3,local_c8);
    pMVar6 = local_e0;
    pMVar7 = local_dc;
    Build_Position_Rotation_Matrix(local_e0,(float)local_dc,local_d8,unaff_EDI,unaff_ESI);
    Matrix_Multiply(local_c8,pMVar6,pMVar7);
    pMVar6 = extraout_ECX;
  }
  else {
    pMVar6 = &Identity_Matrix;
  }
  pMVar7 = in_ECX;
  for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
    (pMVar7->right).x = (pMVar6->right).x;
    pMVar6 = (Matrix *)&(pMVar6->right).y;
    pMVar7 = (Matrix *)&(pMVar7->right).y;
  }
  return in_ECX;
}


// ---------------------------------------------------------------------
// GetPositionNearOrFar  @ 4fc042d6  lines 2288-2303


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

Vector * __cdecl
GetPositionNearOrFar
          (Vector *__return_storage_ptr__,Vector param_1,Vector param_2,float param_3,float param_4,
          bool param_5)

{
  Vector VVar1;
  Vector *in_ECX;
  char in_DL;
  Vector *unaff_ESI;
  Vector *unaff_EDI;
  float fVar2;
  float local_18;
  float local_14;
  float local_10;
  
  VVar1.y = param_2.x;
  VVar1.x = param_1.z;
  VVar1.z = param_2.y;
  GetPositionNear(in_ECX,VVar1,param_2.z,param_3);
  if ((((float)__return_storage_ptr__ != param_1.z) || (param_1.x != param_2.x)) ||
     (param_1.y != param_2.y)) {
    Normalize_Vector(unaff_EDI,unaff_ESI);
    fVar2 = (in_ECX->z - param_2.y) * local_10 +
            local_14 * (in_ECX->y - param_2.x) + local_18 * (in_ECX->x - param_1.z);
    if ((bool)in_DL != 0.0 < fVar2) {
      fVar2 = fVar2 * (float)___real_c000000000000000;
      in_ECX->x = local_18 * fVar2 + in_ECX->x;
      in_ECX->y = local_14 * fVar2 + in_ECX->y;
      in_ECX->z = in_ECX->z + local_10 * fVar2;
      fVar2 = TerrainFindFloor(in_ECX->x,in_ECX->z);
      in_ECX->y = fVar2;
    }
  }
  return in_ECX;
}


// ---------------------------------------------------------------------
// CheckODFName  @ 4fc0443e  lines 2307-2322


void __cdecl CheckODFName(char *param_1)

{
  bool bVar1;
  char *pcVar2;
  char *in_ECX;
  
  bVar1 = DoesODFExist(in_ECX);
  if (!bVar1) {
    pcVar2 = strchr(in_ECX,0x3a);
    if (pcVar2 != (char *)0x0) {
      *pcVar2 = '\0';
    }
    bVar1 = DoesODFExist(in_ECX);
    if (!bVar1) {
      pcVar2 = strrchr(in_ECX,0x2e);
      if (pcVar2 != (char *)0x0) {
        *pcVar2 = '\0';
      }
    }
  }
  return;
}


// ---------------------------------------------------------------------
// PlayVOMsg  @ 4fc0447f  lines 2374-2390


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __cdecl PlayVOMsg(int param_1,char *param_2,int param_3)

{
  bool bVar1;
  int iVar2;
  int in_ECX;
  int in_EDX;
  char *pcVar3;
  char *pcVar4;
  char local_48 [64];
  undefined4 local_8;
  
  local_8 = __security_cookie ^ (uint)(local_48 + 0x44);
  bVar1 = IsAround(in_ECX);
  if ((bVar1) && (in_EDX != 0)) {
    if (param_1 == -1) {
      param_1 = GetTeamNum(in_ECX);
    }
    iVar2 = GetLocalPlayerTeamNumber();
    if (param_1 == iVar2) {
      pcVar3 = local_48;
      pcVar4 = (char *)0x0;
      memset(pcVar3,0,0x40);
      iVar2 = GetODFString(in_EDX,(char *)0x40,local_48,0,pcVar3,pcVar4);
      if ((iVar2 != 0) && (local_48[0] != '\0')) {
        AudioMessage(local_48,false);
      }
    }
  }
  return;
}


// ---------------------------------------------------------------------
// PlayEventVO  @ 4fc0450d  lines 2394-2417


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __cdecl PlayEventVO(char param_1,int param_2,int param_3)

{
  bool bVar1;
  int iVar2;
  char *unaff_EDI;
  char local_c4 [64];
  char local_84 [64];
  char local_44 [64];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)local_c4;
  memset(local_84,0,0x40);
  memset(local_c4,0,0x40);
  sprintf_s<64>(&local_c4,"%cevent.odf");
  bVar1 = DoesFileExist(local_c4);
  if (!bVar1) {
    strcpy_s(local_c4,0x40,"aevent.odf");
  }
  memset(local_44,0,0x40);
  sprintf_s<64>(&local_44,"EVENT_SOUND_%d");
  bVar1 = OpenODF2(unaff_EDI);
  if (bVar1) {
    iVar2 = GetODFString(local_c4,"BettyVoice",local_44,0x40,local_84,(char *)0x0);
    if ((iVar2 != 0) && (local_84[0] != '\0')) {
      bVar1 = DoesFileExist(local_84);
      if (bVar1) {
        AudioMessage(local_84,false);
      }
      else {
        FormatLogMessage("ERROR: Sound file: \'%s\' doesn\'t exist! Fix %s in ODF: \'%s\'");
      }
    }
  }
  return;
}


// ---------------------------------------------------------------------
// IsBuildingOrGunTower  @ 4fc04633  lines 2453-2501


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool __cdecl IsBuildingOrGunTower(int param_1,int param_2)

{
  bool bVar1;
  uint uVar2;
  int in_ECX;
  uint in_EDX;
  uint unaff_ESI;
  uint uVar3;
  char *unaff_EDI;
  char local_48 [64];
  undefined4 local_8;
  
  local_8 = __security_cookie ^ (uint)(local_48 + 0x44);
  uVar3 = 0;
  if (in_EDX == 0) {
    memset(local_48,0,0x40);
    bVar1 = GetObjInfo(in_ECX,Get_GOClass,local_48);
    if (!bVar1) {
      return false;
    }
    in_EDX = Hash(unaff_EDI,unaff_ESI);
  }
  bVar1 = IsBuilding(in_ECX);
  if ((bVar1) || (in_EDX == 0xdf6dabba)) {
    uVar2 = 0;
    do {
      if (in_EDX == *(uint *)((int)MiscClass + uVar2)) {
        return false;
      }
      uVar2 = uVar2 + 4;
    } while (uVar2 < 0x28);
    while (in_EDX != *(uint *)((int)WeaponClass + uVar3)) {
      uVar3 = uVar3 + 4;
      if (0x2b < uVar3) {
        return true;
      }
    }
  }
  return false;
}


// ---------------------------------------------------------------------
// IsCraft  @ 4fc046c5  lines 2505-2532


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool __cdecl IsCraft(int param_1,int param_2)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  int in_ECX;
  int in_EDX;
  char local_48 [64];
  undefined4 local_8;
  
  local_8 = __security_cookie ^ (uint)(local_48 + 0x44);
  if (in_EDX == 0) {
    memset(local_48,0,0x40);
    bVar2 = GetObjInfo(in_ECX,Get_GOClass,local_48);
    bVar1 = false;
    if (bVar2) {
      bVar2 = IsCraftButNotPerson(in_ECX);
      bVar1 = false;
      if ((bVar2) && (iVar3 = _stricmp(local_48,"CLASS_TURRET"), iVar3 != 0)) {
        bVar1 = true;
      }
    }
  }
  else {
    bVar1 = IsCraftButNotPerson(in_ECX);
    if ((!bVar1) || (in_EDX == -0x20925446)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
  }
  return bVar1;
}


// ---------------------------------------------------------------------
// IsWeapon  @ 4fc04752  lines 2563-2583


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool __cdecl IsWeapon(int param_1,int param_2)

{
  bool bVar1;
  int in_ECX;
  uint in_EDX;
  uint unaff_ESI;
  uint uVar2;
  char *unaff_EDI;
  char local_48 [64];
  undefined4 local_8;
  
  local_8 = __security_cookie ^ (uint)(local_48 + 0x44);
  uVar2 = 0;
  if (in_EDX == 0) {
    memset(local_48,0,0x40);
    bVar1 = GetObjInfo(in_ECX,Get_GOClass,local_48);
    if (!bVar1) {
      return false;
    }
    in_EDX = Hash(unaff_EDI,unaff_ESI);
  }
  do {
    if (in_EDX == *(uint *)((int)WeaponClass + uVar2)) {
      return true;
    }
    uVar2 = uVar2 + 4;
  } while (uVar2 < 0x2c);
  return false;
}


// ---------------------------------------------------------------------
// IsMisc  @ 4fc047ba  lines 2587-2607


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool __cdecl IsMisc(int param_1,int param_2)

{
  bool bVar1;
  int in_ECX;
  uint in_EDX;
  uint unaff_ESI;
  uint uVar2;
  char *unaff_EDI;
  char local_48 [64];
  undefined4 local_8;
  
  local_8 = __security_cookie ^ (uint)(local_48 + 0x44);
  uVar2 = 0;
  if (in_EDX == 0) {
    memset(local_48,0,0x40);
    bVar1 = GetObjInfo(in_ECX,Get_GOClass,local_48);
    if (!bVar1) {
      return false;
    }
    in_EDX = Hash(unaff_EDI,unaff_ESI);
  }
  do {
    if (in_EDX == *(uint *)((int)MiscClass + uVar2)) {
      return true;
    }
    uVar2 = uVar2 + 4;
  } while (uVar2 < 0x28);
  return false;
}


// ---------------------------------------------------------------------
// IsFactory  @ 4fc04822  lines 2710-2719


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool __cdecl IsFactory(int param_1)

{
  bool bVar1;
  int iVar2;
  int in_ECX;
  bool bVar3;
  char *pcVar4;
  char *pcVar5;
  char local_88 [64];
  char local_48 [64];
  undefined4 local_8;
  
  local_8 = __security_cookie ^ (uint)(local_48 + 0x44);
  bVar3 = false;
  memset(local_48,0,0x40);
  bVar1 = GetObjInfo(in_ECX,Get_GOClass,local_48);
  if (bVar1) {
    pcVar4 = local_88;
    pcVar5 = (char *)0x0;
    memset(pcVar4,0,0x40);
    GetODFString(0x4fc552cc,(char *)0x40,local_88,0,pcVar4,pcVar5);
    iVar2 = _stricmp(local_48,"CLASS_FACTORY");
    if ((iVar2 == 0) || (iVar2 = _stricmp(local_88,"muf"), iVar2 == 0)) {
      bVar3 = true;
    }
    return bVar3;
  }
  return false;
}


// ---------------------------------------------------------------------
// IsArmory  @ 4fc048c3  lines 2722-2731


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool __cdecl IsArmory(int param_1)

{
  bool bVar1;
  int iVar2;
  int in_ECX;
  bool bVar3;
  char *pcVar4;
  char *pcVar5;
  char local_88 [64];
  char local_48 [64];
  undefined4 local_8;
  
  local_8 = __security_cookie ^ (uint)(local_48 + 0x44);
  bVar3 = false;
  memset(local_48,0,0x40);
  bVar1 = GetObjInfo(in_ECX,Get_GOClass,local_48);
  if (bVar1) {
    pcVar4 = local_88;
    pcVar5 = (char *)0x0;
    memset(pcVar4,0,0x40);
    GetODFString(0x4fc552cc,(char *)0x40,local_88,0,pcVar4,pcVar5);
    iVar2 = _stricmp(local_48,"CLASS_ARMORY");
    if ((iVar2 == 0) || (iVar2 = _stricmp(local_88,"slf"), iVar2 == 0)) {
      bVar3 = true;
    }
    return bVar3;
  }
  return false;
}


// ---------------------------------------------------------------------
// IsConstructor  @ 4fc04964  lines 2734-2753


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool __cdecl IsConstructor(int param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  int in_ECX;
  bool bVar3;
  char local_48 [64];
  undefined4 local_8;
  
  local_8 = __security_cookie ^ (uint)(local_48 + 0x44);
  bVar3 = false;
  memset(local_48,0,0x40);
  bVar1 = GetObjInfo(in_ECX,Get_GOClass,local_48);
  if (bVar1) {
    iVar2 = _stricmp(local_48,"CLASS_CONSTRUCTIONRIG");
    if ((iVar2 == 0) || (iVar2 = _stricmp(local_48,"CLASS_CONSTRUCTIONRIGT"), iVar2 == 0)) {
      bVar3 = true;
    }
    return bVar3;
  }
  return false;
}


// ---------------------------------------------------------------------
// IsServiceTruck  @ 4fc049d4  lines 2768-2777


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool __cdecl IsServiceTruck(int param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  int in_ECX;
  bool bVar3;
  char local_48 [64];
  undefined4 local_8;
  
  local_8 = __security_cookie ^ (uint)(local_48 + 0x44);
  bVar3 = false;
  memset(local_48,0,0x40);
  bVar1 = GetObjInfo(in_ECX,Get_GOClass,local_48);
  if (bVar1) {
    iVar2 = _stricmp(local_48,"CLASS_SERVICE");
    if ((iVar2 == 0) || (iVar2 = _stricmp(local_48,"CLASS_SERVICEH"), iVar2 == 0)) {
      bVar3 = true;
    }
    return bVar3;
  }
  return false;
}


// ---------------------------------------------------------------------
// IsPoweredBuilding  @ 4fc04a44  lines 3024-3054


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool __cdecl IsPoweredBuilding(char *param_1)

{
  int iVar1;
  char *pcVar2;
  char *in_ECX;
  char *unaff_EBP;
  uint uVar3;
  uint unaff_EDI;
  undefined1 local_44 [64];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)local_44;
  if (in_ECX != (char *)0x0) {
    uVar3 = 0;
    memset(local_44,0,0x40);
    do {
      pcVar2 = in_ECX;
      in_ECX = pcVar2 + 1;
    } while (*pcVar2 != '\0');
    iVar1 = _stricmp(pcVar2 + -4,".odf");
    if (iVar1 != 0) {
      CombineStrings(".odf",(char *)0x40,unaff_EBP,unaff_EDI);
    }
    memset(TempGetClasslabelString,0,0x40);
    pcVar2 = GetClasslabelString(unaff_EBP);
    do {
      iVar1 = _stricmp(pcVar2,*(char **)((int)ClassLabelPoweredBuildings + uVar3));
      if (iVar1 == 0) {
        return true;
      }
      uVar3 = uVar3 + 4;
    } while (uVar3 < 0x34);
  }
  return false;
}


// ---------------------------------------------------------------------
// IsBuilding  @ 4fc04af5  lines 3058-3088


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool __cdecl IsBuilding(char *param_1)

{
  int iVar1;
  char *pcVar2;
  char *in_ECX;
  char *unaff_EBP;
  uint uVar3;
  uint unaff_EDI;
  undefined1 local_44 [64];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)local_44;
  if (in_ECX != (char *)0x0) {
    uVar3 = 0;
    memset(local_44,0,0x40);
    do {
      pcVar2 = in_ECX;
      in_ECX = pcVar2 + 1;
    } while (*pcVar2 != '\0');
    iVar1 = _stricmp(pcVar2 + -4,".odf");
    if (iVar1 != 0) {
      CombineStrings(".odf",(char *)0x40,unaff_EBP,unaff_EDI);
    }
    memset(TempGetClasslabelString,0,0x40);
    pcVar2 = GetClasslabelString(unaff_EBP);
    do {
      iVar1 = _stricmp(pcVar2,*(char **)((int)ClassLabelBuildings + uVar3));
      if (iVar1 == 0) {
        return true;
      }
      uVar3 = uVar3 + 4;
    } while (uVar3 < 0x54);
  }
  return false;
}


// ---------------------------------------------------------------------
// GetODFName  @ 4fc04ba6  lines 3126-3137


bool __cdecl GetODFName(int param_1,char *param_2)

{
  bool bVar1;
  char *pcVar2;
  int in_ECX;
  char *in_EDX;
  
  if (in_EDX != (char *)0x0) {
    bVar1 = GetObjInfo(in_ECX,Get_ODF,in_EDX);
    if (bVar1) {
      pcVar2 = strrchr(in_EDX,0x2e);
      if (pcVar2 != (char *)0x0) {
        *pcVar2 = '\0';
      }
      return true;
    }
  }
  return false;
}


// ---------------------------------------------------------------------
// GetODFName  @ 4fc04bd8  lines 3141-3154


char * __cdecl GetODFName(int param_1)

{
  char *unaff_ESI;
  int unaff_EDI;
  
  memset(TempGetODFName,0,0x40);
  GetODFName(unaff_EDI,unaff_ESI);
  return TempGetODFName;
}


// ---------------------------------------------------------------------
// GetAndOpenODFNames  @ 4fc04bfc  lines 3158-3181


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool __cdecl GetAndOpenODFNames(int param_1,char *param_2,char *param_3,char *param_4)

{
  bool bVar1;
  int iVar2;
  char *pcVar3;
  int in_ECX;
  char *in_EDX;
  uint unaff_ESI;
  char *unaff_EDI;
  char local_48 [64];
  undefined4 local_8;
  
  local_8 = __security_cookie ^ (uint)(local_48 + 0x44);
  if ((param_1 != 0) && (bVar1 = GetObjInfo(in_ECX,Get_ODF,in_EDX), bVar1)) {
    memset(local_48,0,0x40);
    bVar1 = OpenODF2(unaff_EDI);
    if ((bVar1) &&
       (iVar2 = GetODFString(in_EDX,"GameObjectClass","classlabel",0x40,local_48,(char *)0x0),
       iVar2 != 0)) {
      CombineStrings(".odf",(char *)0x40,unaff_EDI,unaff_ESI);
      bVar1 = OpenODF2(unaff_EDI);
      if (!bVar1) {
        *(undefined1 *)param_1 = 0;
      }
    }
    if (param_2 != (char *)0x0) {
      CombineStrings(in_EDX,(char *)0x40,unaff_EDI,unaff_ESI);
      pcVar3 = strrchr(param_2,0x2e);
      if (pcVar3 != (char *)0x0) {
        *pcVar3 = '\0';
      }
    }
    return true;
  }
  return false;
}


// ---------------------------------------------------------------------
// GetClasslabelString  @ 4fc04cca  lines 3186-3229


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

char * __cdecl GetClasslabelString(char *param_1)

{
  bool bVar1;
  int iVar2;
  char *in_ECX;
  char *pcVar3;
  uint unaff_ESI;
  char *unaff_EDI;
  char *pcVar4;
  uint uVar5;
  char local_84 [64];
  char local_44 [64];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)local_84;
  memset(local_84,0,0x40);
  pcVar4 = in_ECX;
  do {
    pcVar3 = pcVar4;
    pcVar4 = pcVar3 + 1;
  } while (*pcVar3 != '\0');
  iVar2 = _stricmp(pcVar3 + -4,".odf");
  if (iVar2 != 0) {
    in_ECX = ".odf";
  }
  CombineStrings(in_ECX,(char *)0x40,unaff_EDI,unaff_ESI);
  bVar1 = OpenODF2(unaff_EDI);
  if ((bVar1) &&
     ((((iVar2 = GetODFString(local_84,"GameObjectClass","classlabel",0x40,TempGetClasslabelString,
                              (char *)0x0), iVar2 != 0 ||
        (iVar2 = GetODFString(local_84,"WeaponClass","classlabel",0x40,TempGetClasslabelString,
                              (char *)0x0), iVar2 != 0)) ||
       (iVar2 = GetODFString(local_84,"OrdnanceClass","classlabel",0x40,TempGetClasslabelString,
                             (char *)0x0), iVar2 != 0)) ||
      (iVar2 = GetODFString(local_84,"ExplosionClass","classlabel",0x40,TempGetClasslabelString,
                            (char *)0x0), iVar2 != 0)))) {
    while (bVar1 = DoesODFExist(TempGetClasslabelString), bVar1) {
      memset(local_44,0,0x40);
      pcVar4 = local_44;
      uVar5 = 0x40;
      strcpy_s(pcVar4,0x40,TempGetClasslabelString);
      CombineStrings(".odf",(char *)0x40,pcVar4,uVar5);
      bVar1 = OpenODF2(unaff_EDI);
      if ((((bVar1) &&
           (iVar2 = GetODFString(local_84,"GameObjectClass","classlabel",0x40,
                                 TempGetClasslabelString,(char *)0x0), iVar2 == 0)) &&
          ((iVar2 = GetODFString(local_84,"WeaponClass","classlabel",0x40,TempGetClasslabelString,
                                 (char *)0x0), iVar2 == 0 &&
           ((iVar2 = GetODFString(local_84,"OrdnanceClass","classlabel",0x40,TempGetClasslabelString
                                  ,(char *)0x0), iVar2 == 0 &&
            (iVar2 = GetODFString(local_84,"ExplosionClass","classlabel",0x40,
                                  TempGetClasslabelString,(char *)0x0), iVar2 == 0)))))) ||
         (iVar2 = _stricmp(local_44,TempGetClasslabelString), iVar2 == 0)) break;
    }
  }
  return TempGetClasslabelString;
}


// ---------------------------------------------------------------------
// GetPilotConfig  @ 4fc04eb3  lines 3333-3355


char * __cdecl GetPilotConfig(int param_1)

{
  char *pcVar1;
  int in_ECX;
  
  memset(TempGetPilotConfig,0,0x40);
  pcVar1 = GetPilotClass(in_ECX);
  if (pcVar1 != (char *)0x0) {
    strcpy_s(TempGetPilotConfig,0x40,pcVar1);
    pcVar1 = strrchr(TempGetPilotConfig,0x2e);
    if (pcVar1 != (char *)0x0) {
      *pcVar1 = '\0';
    }
  }
  return TempGetPilotConfig;
}


// ---------------------------------------------------------------------
// CombineStrings  @ 4fc04ef6  lines 3359-3381


bool __cdecl CombineStrings(char *param_1,char *param_2,char *param_3,uint param_4)

{
  char cVar1;
  char *in_ECX;
  char *in_EDX;
  char *pcVar2;
  char *pcVar3;
  
  if (((in_ECX != (char *)0x0) && (in_EDX != (char *)0x0)) && (param_1 != (char *)0x0)) {
    if (in_ECX == param_1) {
      pcVar3 = "ERROR: \'%s\' cannot append \'%s\', Return and String2 is itself!";
    }
    else {
      pcVar3 = in_EDX;
      do {
        cVar1 = *pcVar3;
        pcVar3 = pcVar3 + 1;
      } while (cVar1 != '\0');
      pcVar2 = param_1;
      do {
        cVar1 = *pcVar2;
        pcVar2 = pcVar2 + 1;
      } while (cVar1 != '\0');
      if (pcVar3 + (int)(pcVar2 + (-(int)(param_1 + 1) - (int)(in_EDX + 1))) <= param_2) {
        if (in_ECX == in_EDX) {
          strcat_s(in_ECX,(rsize_t)param_2,param_1);
        }
        else {
          sprintf_s(in_ECX,(uint)param_2,"%s%s");
        }
        return true;
      }
      pcVar3 = "ERROR: \'%s\' cannot append \'%s\', length too long. Make ODF Name shorter!";
    }
    FormatConsoleMessage(pcVar3);
  }
  return false;
}


// ---------------------------------------------------------------------
// GetWorldVariantODF  @ 4fc04f7d  lines 3405-3428


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool __cdecl GetWorldVariantODF(char *param_1)

{
  bool bVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  char *in_ECX;
  char *pcVar5;
  char *pcVar6;
  char cVar7;
  char local_49;
  char local_48 [64];
  undefined4 local_8;
  
  local_8 = __security_cookie ^ (uint)(local_48 + 0x44);
  iVar2 = tolower((int)in_ECX[1]);
  if (iVar2 == 0x76) {
    pcVar3 = strrchr(in_ECX,0x2e);
    if (pcVar3 != (char *)0x0) {
      *pcVar3 = '\0';
    }
    cVar7 = '\0';
    pcVar3 = &local_49;
    local_49 = '\0';
    pcVar6 = "WorldLetter";
    pcVar5 = "World";
    pcVar4 = GetMapTRNFilename();
    iVar2 = GetODFChar(pcVar4,pcVar5,pcVar6,pcVar3,cVar7);
    if (iVar2 != 0) {
      pcVar3 = in_ECX;
      do {
        cVar7 = *pcVar3;
        pcVar3 = pcVar3 + 1;
      } while (cVar7 != '\0');
      if ((uint)((int)pcVar3 - (int)(in_ECX + 1)) < 0x41) {
        memset(local_48,0,0x40);
        sprintf_s<64>(&local_48,"%s%c");
        bVar1 = DoesODFExist(local_48);
        if (bVar1) {
          strcpy_s(in_ECX,0x40,local_48);
          return true;
        }
      }
    }
  }
  return false;
}


// ---------------------------------------------------------------------
// GetPilotCost  @ 4fc05047  lines 3523-3575


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl GetPilotCost(char *param_1)

{
  bool bVar1;
  char *in_ECX;
  char *unaff_ESI;
  uint uVar2;
  char *pcVar3;
  uint uVar4;
  int *piVar5;
  int in_stack_ffffffb8;
  char acStack_42 [62];
  
  piVar5 = (int *)0x0;
  pcVar3 = acStack_42 + -6;
  uVar4 = 0;
  memset(pcVar3,0,0x40);
  uVar2 = 0x40;
  CombineStrings(in_ECX,(char *)0x40,pcVar3,uVar4);
  CheckODFName(in_ECX);
  CombineStrings(".odf",(char *)0x40,in_ECX,uVar2);
  bVar1 = OpenODF2(unaff_ESI);
  if (bVar1) {
    GetODFInt("GameObjectClass","pilotCost",acStack_42 + -10,(char *)0x0,piVar5,in_stack_ffffffb8);
  }
  return (int)piVar5;
}


// ---------------------------------------------------------------------
// GetScrapCost  @ 4fc050d0  lines 3579-3600


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl GetScrapCost(char *param_1)

{
  bool bVar1;
  char *in_ECX;
  char *unaff_ESI;
  uint uVar2;
  char *pcVar3;
  uint uVar4;
  int *piVar5;
  int in_stack_ffffffb8;
  char acStack_42 [62];
  
  piVar5 = (int *)0x0;
  pcVar3 = acStack_42 + -6;
  uVar4 = 0;
  memset(pcVar3,0,0x40);
  uVar2 = 0x40;
  CombineStrings(in_ECX,(char *)0x40,pcVar3,uVar4);
  CheckODFName(in_ECX);
  CombineStrings(".odf",(char *)0x40,in_ECX,uVar2);
  bVar1 = OpenODF2(unaff_ESI);
  if (bVar1) {
    GetODFInt("GameObjectClass","scrapCost",acStack_42 + -10,(char *)0x0,piVar5,in_stack_ffffffb8);
  }
  return (int)piVar5;
}


// ---------------------------------------------------------------------
// GetScrapValue  @ 4fc05159  lines 3604-3638


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl GetScrapValue(char *param_1)

{
  bool bVar1;
  int iVar2;
  char *in_ECX;
  int *unaff_ESI;
  uint uVar3;
  char *pcVar4;
  uint uVar5;
  char local_48 [2];
  char acStack_46 [62];
  undefined4 local_8;
  
  local_8 = __security_cookie ^ (uint)(acStack_46 + 0x42);
  if (in_ECX == (char *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = 0;
    pcVar4 = local_48;
    uVar5 = 0;
    memset(pcVar4,0,0x40);
    uVar3 = 0x40;
    CombineStrings(in_ECX,(char *)0x40,pcVar4,uVar5);
    CheckODFName(in_ECX);
    CombineStrings(".odf",(char *)0x40,in_ECX,uVar3);
    bVar1 = OpenODF2((char *)unaff_ESI);
    if (bVar1) {
      GetODFInt("GameObjectClass","scrapValue",local_48 + -4,(char *)0x0,unaff_ESI,iVar2);
    }
  }
  return iVar2;
}


// ---------------------------------------------------------------------
// GetNumWeapons  @ 4fc051ea  lines 3642-3680


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl GetNumWeapons(int param_1)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int in_ECX;
  uint unaff_ESI;
  char *unaff_EDI;
  int iVar6;
  char (*pacVar7) [64];
  char *pcVar8;
  char local_88 [64];
  char local_48 [7];
  byte local_41;
  undefined4 local_8;
  
  local_8 = __security_cookie ^ (uint)(local_48 + 0x44);
  bVar2 = IsAround(in_ECX);
  if (bVar2) {
    iVar3 = 0;
    iVar6 = 0;
    do {
      memset(local_48,0,0x40);
      memset(local_88,0,0x40);
      iVar6 = iVar6 + 1;
      pacVar7 = &local_88;
      pcVar8 = "weaponHard%d";
      sprintf_s<64>(pacVar7,"weaponHard%d");
      iVar4 = GetODFString((int)local_88,(char *)0x40,local_48,0,*pacVar7,pcVar8);
      if ((iVar4 != 0) && (iVar4 = _strnicmp(local_48,"HP_",3), iVar4 == 0)) {
        pcVar8 = strchr(local_48 + 3,0x5f);
        if (pcVar8 != (char *)0x0) {
          *pcVar8 = '\0';
        }
        pcVar8 = local_48;
        do {
          cVar1 = *pcVar8;
          pcVar8 = pcVar8 + 1;
        } while (cVar1 != '\0');
        local_41 = local_41 & -((uint)((int)pcVar8 - (int)(local_48 + 1)) < 6);
        uVar5 = Hash(unaff_EDI,unaff_ESI);
        if ((((uVar5 == 0xe1884a5e) || (uVar5 == 0xfc91ae57)) || (uVar5 == 0x3a26ab6c)) ||
           (((uVar5 == 0x46956389 || (uVar5 == 0x8fe971f7)) ||
            ((uVar5 == 0x9ac3c813 || (uVar5 == 0xf661135c)))))) {
          iVar3 = iVar3 + 1;
        }
      }
    } while (iVar6 < 5);
  }
  else {
    iVar3 = -1;
  }
  return iVar3;
}


// ---------------------------------------------------------------------
// CheckBuildRequirements_PowerCost  @ 4fc05304  lines 3693-3702


int __cdecl CheckBuildRequirements_PowerCost(int param_1,char *param_2,char *param_3)

{
  bool bVar1;
  int iVar2;
  int in_ECX;
  char *unaff_ESI;
  int *unaff_EDI;
  int local_8;
  
  local_8 = 0;
  iVar2 = GetODFInt("GameObjectClass","powerCost",(char *)&local_8,(char *)0x0,unaff_EDI,
                    (int)unaff_ESI);
  if (((iVar2 == 0) && (iVar2 = GetTapCount((char *)unaff_EDI,unaff_ESI), iVar2 == 0)) &&
     (bVar1 = IsPoweredBuilding((char *)unaff_EDI), bVar1)) {
    local_8 = 1;
  }
  iVar2 = GetPower(in_ECX);
  return iVar2 - local_8;
}


// ---------------------------------------------------------------------
// GetConfigODF  @ 4fc05365  lines 3707-3736


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

char * __cdecl GetConfigODF(int param_1)

{
  bool bVar1;
  char *in_ECX;
  char *unaff_ESI;
  char *unaff_EDI;
  char *pcVar2;
  uint uVar3;
  undefined1 local_44 [64];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)local_44;
  memset(TempGetConfigODFName,0,0x40);
  memset(local_44,0,0x40);
  bVar1 = GetODFName((int)unaff_EDI,unaff_ESI);
  if (bVar1) {
    CombineStrings("_config.odf",(char *)0x40,unaff_EDI,(uint)unaff_ESI);
    bVar1 = DoesFileExist(TempGetConfigODFName);
    if (!bVar1) {
      uVar3 = 0x40;
      pcVar2 = "classlabel";
      GetODFString(0x4fc52e8c,(char *)0x40,TempGetConfigODFName,0,unaff_EDI,unaff_ESI);
      CombineStrings("_config.odf",(char *)0x40,pcVar2,uVar3);
      bVar1 = DoesFileExist(TempGetConfigODFName);
      if (!bVar1) {
        uVar3 = 2;
        GetObjInfo((int)in_ECX,Get_GOClass_gCfg,TempGetConfigODFName);
        CombineStrings("_config.odf",(char *)0x40,in_ECX,uVar3);
        bVar1 = DoesFileExist(TempGetConfigODFName);
        if (!bVar1) goto LAB_4fc0541f;
      }
    }
    pcVar2 = TempGetConfigODFName;
  }
  else {
LAB_4fc0541f:
    pcVar2 = (char *)0x0;
  }
  return pcVar2;
}


// ---------------------------------------------------------------------
// OpenODF2  @ 4fc05434  lines 3815-3863


bool __cdecl OpenODF2(char *param_1)

{
  bool bVar1;
  _List_iterator<std::_List_val<std::_List_simple_types<std::pair<unsigned_long_const_,ODFName>_>_>_>
  _Var2;
  _List_const_iterator<std::_List_val<std::_List_simple_types<unsigned_long>_>_> _Var3;
  ulong *puVar4;
  _Hash<std::_Uset_traits<unsigned_long,std::_Uhash_compare<unsigned_long,std::hash<unsigned_long>,std::equal_to<unsigned_long>_>,std::allocator<unsigned_long>,0>_>
  *in_ECX;
  _Hash<std::_Uset_traits<unsigned_long,std::_Uhash_compare<unsigned_long,std::hash<unsigned_long>,std::equal_to<unsigned_long>_>,std::allocator<unsigned_long>,0>_>
  *this;
  _Hash<std::_Umap_traits<unsigned_long,ODFName,std::_Uhash_compare<unsigned_long,std::hash<unsigned_long>,std::equal_to<unsigned_long>_>,std::allocator<std::pair<unsigned_long_const_,ODFName>_>,0>_>
  *this_00;
  _Hash<std::_Umap_traits<unsigned_long,ODFName,std::_Uhash_compare<unsigned_long,std::hash<unsigned_long>,std::equal_to<unsigned_long>_>,std::allocator<std::pair<unsigned_long_const_,ODFName>_>,0>_>
  *this_01;
  _Hash<std::_Uset_traits<unsigned_long,std::_Uhash_compare<unsigned_long,std::hash<unsigned_long>,std::equal_to<unsigned_long>_>,std::allocator<unsigned_long>,0>_>
  *p_Var5;
  ulong *local_14 [2];
  ulong *local_c;
  ulong local_8;
  
  if ((*(char *)&in_ECX->_Traitsobj != '\0') && (*(char *)&in_ECX->_Traitsobj != '.')) {
    p_Var5 = in_ECX;
    local_8 = CalcCRC((char *)in_ECX);
    _Var2 = std::
            _Hash<std::_Umap_traits<unsigned_long,ODFName,std::_Uhash_compare<unsigned_long,std::hash<unsigned_long>,std::equal_to<unsigned_long>_>,std::allocator<std::pair<unsigned_long_const_,ODFName>_>,0>_>
            ::find((_Hash<std::_Umap_traits<unsigned_long,ODFName,std::_Uhash_compare<unsigned_long,std::hash<unsigned_long>,std::equal_to<unsigned_long>_>,std::allocator<std::pair<unsigned_long_const_,ODFName>_>,0>_>
                    *)p_Var5,(ulong *)&local_c);
    if (*(int *)_Var2 != ODFNameMap._4_4_) {
      return true;
    }
    _Var3 = std::
            _Hash<std::_Uset_traits<unsigned_long,std::_Uhash_compare<unsigned_long,std::hash<unsigned_long>,std::equal_to<unsigned_long>_>,std::allocator<unsigned_long>,0>_>
            ::find(this,(ulong *)&local_c);
    if (*(int *)_Var3 == ODFNameBlackListMap._4_4_) {
      PetWatchdogThread();
      p_Var5 = in_ECX;
      bVar1 = OpenODF((char *)in_ECX);
      if (bVar1) {
        PetWatchdogThread();
        std::
        _Hash<std::_Umap_traits<unsigned_long,ODFName,std::_Uhash_compare<unsigned_long,std::hash<unsigned_long>,std::equal_to<unsigned_long>_>,std::allocator<std::pair<unsigned_long_const_,ODFName>_>,0>_>
        ::find(this_00,(ulong *)&local_c);
        puVar4 = local_c;
        if (local_c == (ulong *)ODFNameMap._4_4_) {
          local_c = &local_8;
          std::
          _Hash<std::_Umap_traits<unsigned_long,ODFName,std::_Uhash_compare<unsigned_long,std::hash<unsigned_long>,std::equal_to<unsigned_long>_>,std::allocator<std::pair<unsigned_long_const_,ODFName>_>,0>_>
          ::
          emplace<std::piecewise_construct_t_const_&,std::tuple<unsigned_long_const_&>,std::tuple<>_>
                    (this_01,(piecewise_construct_t *)local_14,
                     (tuple<unsigned_long_const_&> *)this_01,(tuple<> *)&local_c);
          puVar4 = local_14[0];
        }
        strcpy_s((char *)(puVar4 + 3),0x40,(char *)in_ECX);
        return true;
      }
      std::
      _Hash<std::_Uset_traits<unsigned_long,std::_Uhash_compare<unsigned_long,std::hash<unsigned_long>,std::equal_to<unsigned_long>_>,std::allocator<unsigned_long>,0>_>
      ::_Insert<unsigned_long_const_&,std::_Not_a_node_tag>
                (p_Var5,(ulong *)local_14,SUB41(&local_8,0));
    }
  }
  return false;
}


// ---------------------------------------------------------------------
// CloseOpenODFs  @ 4fc054fe  lines 3867-3873


void __cdecl CloseOpenODFs(void)

{
  int *piVar1;
  
  piVar1 = *(int **)ODFNameMap._4_4_;
  if (piVar1 != (int *)ODFNameMap._4_4_) {
    do {
      CloseODF((char *)(piVar1 + 3));
      piVar1 = (int *)*piVar1;
    } while (piVar1 != (int *)ODFNameMap._4_4_);
  }
  std::
  list<std::pair<unsigned_long_const_,ODFName>,std::allocator<std::pair<unsigned_long_const_,ODFName>_>_>
  ::clear((list<std::pair<unsigned_long_const_,ODFName>,std::allocator<std::pair<unsigned_long_const_,ODFName>_>_>
           *)&ODFNameMap.field_0x4);
  std::
  _Hash<std::_Umap_traits<unsigned_long,ODFName,std::_Uhash_compare<unsigned_long,std::hash<unsigned_long>,std::equal_to<unsigned_long>_>,std::allocator<std::pair<unsigned_long_const_,ODFName>_>,0>_>
  ::_Init((_Hash<std::_Umap_traits<unsigned_long,ODFName,std::_Uhash_compare<unsigned_long,std::hash<unsigned_long>,std::equal_to<unsigned_long>_>,std::allocator<std::pair<unsigned_long_const_,ODFName>_>,0>_>
           *)&ODFNameMap,8);
  return;
}


// ---------------------------------------------------------------------
// GetODFInt  @ 4fc05537  lines 3923-3967


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl GetODFInt(int param_1,char *param_2,char *param_3,int *param_4,int param_5)

{
  bool bVar1;
  int iVar2;
  int in_ECX;
  char *in_EDX;
  int unaff_ESI;
  int *unaff_EDI;
  char local_44 [64];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)local_44;
  memset(local_44,0,0x40);
  bVar1 = GetObjInfo(in_ECX,Get_ODF,local_44);
  if (((bVar1) && (in_EDX != (char *)0x0)) && (param_1 != 0)) {
    iVar2 = GetODFInt(in_EDX,(char *)param_1,param_2,param_3,unaff_EDI,unaff_ESI);
  }
  else {
    iVar2 = 0;
  }
  return iVar2;
}


// ---------------------------------------------------------------------
// GetODFFloat  @ 4fc055ac  lines 4014-4057


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl GetODFFloat(int param_1,char *param_2,char *param_3,float *param_4,float param_5)

{
  bool bVar1;
  int iVar2;
  int in_ECX;
  char *in_EDX;
  float unaff_ESI;
  float *unaff_EDI;
  char local_44 [64];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)local_44;
  memset(local_44,0,0x40);
  bVar1 = GetObjInfo(in_ECX,Get_ODF,local_44);
  if (((bVar1) && (in_EDX != (char *)0x0)) && (param_1 != 0)) {
    iVar2 = GetODFFloat(in_EDX,(char *)param_1,param_2,param_3,unaff_EDI,unaff_ESI);
  }
  else {
    iVar2 = 0;
  }
  return iVar2;
}


// ---------------------------------------------------------------------
// GetODFDouble  @ 4fc05625  lines 4059-4102


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl GetODFDouble(int param_1,char *param_2,char *param_3,double *param_4,double param_5)

{
  bool bVar1;
  int iVar2;
  int in_ECX;
  char *in_EDX;
  undefined4 unaff_EBP;
  undefined4 unaff_ESI;
  char local_4c [68];
  uint local_8;
  
  local_8 = __security_cookie ^ (uint)local_4c;
  memset(local_4c,0,0x40);
  bVar1 = GetObjInfo(in_ECX,Get_ODF,local_4c);
  if (((bVar1) && (in_EDX != (char *)0x0)) && (param_1 != 0)) {
    iVar2 = GetODFDouble(in_EDX,(char *)param_1,param_2,param_3,param_4,
                         (double)CONCAT44(unaff_EBP,unaff_ESI));
  }
  else {
    iVar2 = 0;
  }
  return iVar2;
}


// ---------------------------------------------------------------------
// GetODFChar  @ 4fc056a0  lines 4104-4147


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl GetODFChar(int param_1,char *param_2,char *param_3,char *param_4,char param_5)

{
  bool bVar1;
  int iVar2;
  int in_ECX;
  char *in_EDX;
  char unaff_SI;
  char *unaff_EDI;
  char local_44 [64];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)local_44;
  memset(local_44,0,0x40);
  bVar1 = GetObjInfo(in_ECX,Get_ODF,local_44);
  if (((bVar1) && (in_EDX != (char *)0x0)) && (param_1 != 0)) {
    iVar2 = GetODFChar(in_EDX,(char *)param_1,param_2,param_3,unaff_EDI,unaff_SI);
  }
  else {
    iVar2 = 0;
  }
  return iVar2;
}


// ---------------------------------------------------------------------
// GetODFBool  @ 4fc05715  lines 4149-4192


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl GetODFBool(int param_1,char *param_2,char *param_3,bool *param_4,bool param_5)

{
  bool bVar1;
  int iVar2;
  int in_ECX;
  char *in_EDX;
  undefined1 unaff_SI;
  bool *unaff_EDI;
  char local_44 [64];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)local_44;
  memset(local_44,0,0x40);
  bVar1 = GetObjInfo(in_ECX,Get_ODF,local_44);
  if (((bVar1) && (in_EDX != (char *)0x0)) && (param_1 != 0)) {
    iVar2 = GetODFBool(in_EDX,(char *)param_1,param_2,param_3,unaff_EDI,(bool)unaff_SI);
  }
  else {
    iVar2 = 0;
  }
  return iVar2;
}


// ---------------------------------------------------------------------
// GetODFString  @ 4fc0578a  lines 4194-4237


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl
GetODFString(int param_1,char *param_2,char *param_3,uint param_4,char *param_5,char *param_6)

{
  bool bVar1;
  int iVar2;
  int in_ECX;
  char *in_EDX;
  char *unaff_ESI;
  char *unaff_EDI;
  uint local_48;
  char local_44 [64];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)&local_48;
  local_48 = param_4;
  memset(local_44,0,0x40);
  bVar1 = GetObjInfo(in_ECX,Get_ODF,local_44);
  if (((bVar1) && (in_EDX != (char *)0x0)) && (param_1 != 0)) {
    iVar2 = GetODFString(in_EDX,(char *)param_1,param_2,param_3,local_48,unaff_EDI,unaff_ESI);
  }
  else {
    iVar2 = 0;
  }
  return iVar2;
}


// ---------------------------------------------------------------------
// GetODFVector  @ 4fc0580b  lines 4284-4327


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl GetODFVector(int param_1,char *param_2,char *param_3,Vector *param_4,Vector param_5)

{
  Vector VVar1;
  bool bVar2;
  int iVar3;
  int in_ECX;
  char *in_EDX;
  float unaff_ESI;
  undefined4 unaff_EDI;
  char *local_48;
  char local_44 [64];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)&local_48;
  local_48 = param_2;
  memset(local_44,0,0x40);
  bVar2 = GetObjInfo(in_ECX,Get_ODF,local_44);
  if (((bVar2) && (in_EDX != (char *)0x0)) && (param_1 != 0)) {
    VVar1.y = (float)unaff_EDI;
    VVar1.x = param_5.x;
    VVar1.z = unaff_ESI;
    iVar3 = GetODFVector(in_EDX,(char *)param_1,local_48,param_3,param_4,VVar1);
  }
  else {
    iVar3 = 0;
  }
  return iVar3;
}


// ---------------------------------------------------------------------
// GetODFHexInt  @ 4fc0588f  lines 4332-4360


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl
GetODFHexInt(char *param_1,char *param_2,char *param_3,char *param_4,int *param_5,int param_6)

{
  char *pcVar1;
  bool bVar2;
  int iVar3;
  char *in_ECX;
  char *pcVar4;
  uint unaff_ESI;
  char *unaff_EDI;
  char local_84 [64];
  char local_44 [64];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)local_84;
  if ((in_ECX == (char *)0x0) ||
     (iVar3 = GetODFHexInt(in_ECX,param_1,param_2,(int *)param_3,(int)param_4), iVar3 == 0)) {
    memset(local_84,0,0x40);
    pcVar1 = in_ECX;
    do {
      pcVar4 = pcVar1;
      pcVar1 = pcVar4 + 1;
    } while (*pcVar4 != '\0');
    iVar3 = _stricmp(pcVar4 + -4,".odf");
    if (iVar3 != 0) {
      in_ECX = ".odf";
    }
    CombineStrings(in_ECX,(char *)0x40,unaff_EDI,unaff_ESI);
    memset(local_44,0,0x40);
    while (bVar2 = OpenODF2(unaff_EDI), bVar2) {
      iVar3 = GetODFHexInt(local_84,param_1,param_2,(int *)param_3,(int)param_4);
      if (iVar3 != 0) goto LAB_4fc059ee;
      iVar3 = GetODFString(local_84,"GameObjectClass","classlabel",0x40,local_44,(char *)0x0);
      if (iVar3 == 0) break;
      CombineStrings(".odf",(char *)0x40,unaff_EDI,unaff_ESI);
      iVar3 = _stricmp(local_84,local_44);
      if (iVar3 == 0) break;
      strcpy_s(local_84,0x40,local_44);
    }
    iVar3 = 0;
  }
  else {
LAB_4fc059ee:
    iVar3 = 1;
  }
  return iVar3;
}


// ---------------------------------------------------------------------
// GetODFInt  @ 4fc059f3  lines 4362-4390


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl
GetODFInt(char *param_1,char *param_2,char *param_3,char *param_4,int *param_5,int param_6)

{
  char *pcVar1;
  bool bVar2;
  int iVar3;
  char *in_ECX;
  char *pcVar4;
  char *in_EDX;
  uint unaff_ESI;
  char *unaff_EDI;
  char *local_90;
  char *local_8c;
  int *local_88;
  char local_84 [64];
  char local_44 [64];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)&local_90;
  local_90 = param_1;
  local_8c = param_2;
  local_88 = (int *)param_3;
  if ((in_ECX != (char *)0x0) &&
     (iVar3 = GetODFInt(in_ECX,param_1,param_2,(int *)param_3,(int)param_4), iVar3 != 0)) {
    return 1;
  }
  if ((in_EDX != (char *)0x0) &&
     (iVar3 = GetODFInt(in_EDX,local_90,local_8c,local_88,(int)param_4), iVar3 != 0)) {
    return 1;
  }
  memset(local_84,0,0x40);
  if (in_EDX == (char *)0x0) {
    pcVar1 = in_ECX;
    do {
      pcVar4 = pcVar1;
      pcVar1 = pcVar4 + 1;
    } while (*pcVar4 != '\0');
    iVar3 = _stricmp(pcVar4 + -4,".odf");
    if (iVar3 == 0) {
      in_EDX = in_ECX;
      goto LAB_4fc05af7;
    }
  }
  else {
    pcVar1 = in_EDX;
    do {
      pcVar4 = pcVar1;
      pcVar1 = pcVar4 + 1;
    } while (*pcVar4 != '\0');
    iVar3 = _stricmp(pcVar4 + -4,".odf");
    if (iVar3 == 0) goto LAB_4fc05af7;
  }
  in_EDX = ".odf";
LAB_4fc05af7:
  CombineStrings(in_EDX,(char *)0x40,unaff_EDI,unaff_ESI);
  memset(local_44,0,0x40);
  bVar2 = OpenODF2(unaff_EDI);
  pcVar4 = local_8c;
  pcVar1 = local_90;
  if (bVar2) {
    do {
      iVar3 = GetODFInt(local_84,pcVar1,pcVar4,local_88,(int)param_4);
      if (iVar3 != 0) {
        return 1;
      }
      iVar3 = GetODFString(local_84,"GameObjectClass","classlabel",0x40,local_44,(char *)0x0);
      if (iVar3 == 0) {
        return 0;
      }
      CombineStrings(".odf",(char *)0x40,unaff_EDI,unaff_ESI);
      iVar3 = _stricmp(local_84,local_44);
      if (iVar3 == 0) {
        return 0;
      }
      strcpy_s(local_84,0x40,local_44);
      bVar2 = OpenODF2(unaff_EDI);
    } while (bVar2);
  }
  return 0;
}


// ---------------------------------------------------------------------
// GetODFLong  @ 4fc05bdb  lines 4392-4420


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl
GetODFLong(char *param_1,char *param_2,char *param_3,char *param_4,long *param_5,long param_6)

{
  char *pcVar1;
  bool bVar2;
  int iVar3;
  char *in_ECX;
  char *pcVar4;
  char *in_EDX;
  uint unaff_ESI;
  char *unaff_EDI;
  char *local_90;
  char *local_8c;
  long *local_88;
  char local_84 [64];
  char local_44 [64];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)&local_90;
  local_90 = param_1;
  local_8c = param_2;
  local_88 = (long *)param_3;
  if ((in_ECX != (char *)0x0) &&
     (iVar3 = GetODFLong(in_ECX,param_1,param_2,(long *)param_3,(long)param_4), iVar3 != 0)) {
    return 1;
  }
  if ((in_EDX != (char *)0x0) &&
     (iVar3 = GetODFLong(in_EDX,local_90,local_8c,local_88,(long)param_4), iVar3 != 0)) {
    return 1;
  }
  memset(local_84,0,0x40);
  if (in_EDX == (char *)0x0) {
    pcVar1 = in_ECX;
    do {
      pcVar4 = pcVar1;
      pcVar1 = pcVar4 + 1;
    } while (*pcVar4 != '\0');
    iVar3 = _stricmp(pcVar4 + -4,".odf");
    if (iVar3 == 0) {
      in_EDX = in_ECX;
      goto LAB_4fc05cdf;
    }
  }
  else {
    pcVar1 = in_EDX;
    do {
      pcVar4 = pcVar1;
      pcVar1 = pcVar4 + 1;
    } while (*pcVar4 != '\0');
    iVar3 = _stricmp(pcVar4 + -4,".odf");
    if (iVar3 == 0) goto LAB_4fc05cdf;
  }
  in_EDX = ".odf";
LAB_4fc05cdf:
  CombineStrings(in_EDX,(char *)0x40,unaff_EDI,unaff_ESI);
  memset(local_44,0,0x40);
  bVar2 = OpenODF2(unaff_EDI);
  pcVar4 = local_8c;
  pcVar1 = local_90;
  if (bVar2) {
    do {
      iVar3 = GetODFLong(local_84,pcVar1,pcVar4,local_88,(long)param_4);
      if (iVar3 != 0) {
        return 1;
      }
      iVar3 = GetODFString(local_84,"GameObjectClass","classlabel",0x40,local_44,(char *)0x0);
      if (iVar3 == 0) {
        return 0;
      }
      CombineStrings(".odf",(char *)0x40,unaff_EDI,unaff_ESI);
      iVar3 = _stricmp(local_84,local_44);
      if (iVar3 == 0) {
        return 0;
      }
      strcpy_s(local_84,0x40,local_44);
      bVar2 = OpenODF2(unaff_EDI);
    } while (bVar2);
  }
  return 0;
}


// ---------------------------------------------------------------------
// GetODFFloat  @ 4fc05dc3  lines 4422-4450


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl
GetODFFloat(char *param_1,char *param_2,char *param_3,char *param_4,float *param_5,float param_6)

{
  char *pcVar1;
  bool bVar2;
  int iVar3;
  char *in_ECX;
  char *pcVar4;
  char *in_EDX;
  uint unaff_ESI;
  char *unaff_EDI;
  char *local_90;
  char *local_8c;
  float *local_88;
  char local_84 [64];
  char local_44 [64];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)&local_90;
  local_90 = param_1;
  local_8c = param_2;
  local_88 = (float *)param_3;
  if ((in_ECX != (char *)0x0) &&
     (iVar3 = GetODFFloat(in_ECX,param_1,param_2,(float *)param_3,(float)param_4), iVar3 != 0)) {
    return 1;
  }
  if ((in_EDX != (char *)0x0) &&
     (iVar3 = GetODFFloat(in_EDX,local_90,local_8c,local_88,(float)param_4), iVar3 != 0)) {
    return 1;
  }
  memset(local_84,0,0x40);
  if (in_EDX == (char *)0x0) {
    pcVar1 = in_ECX;
    do {
      pcVar4 = pcVar1;
      pcVar1 = pcVar4 + 1;
    } while (*pcVar4 != '\0');
    iVar3 = _stricmp(pcVar4 + -4,".odf");
    if (iVar3 == 0) {
      in_EDX = in_ECX;
      goto LAB_4fc05ed1;
    }
  }
  else {
    pcVar1 = in_EDX;
    do {
      pcVar4 = pcVar1;
      pcVar1 = pcVar4 + 1;
    } while (*pcVar4 != '\0');
    iVar3 = _stricmp(pcVar4 + -4,".odf");
    if (iVar3 == 0) goto LAB_4fc05ed1;
  }
  in_EDX = ".odf";
LAB_4fc05ed1:
  CombineStrings(in_EDX,(char *)0x40,unaff_EDI,unaff_ESI);
  memset(local_44,0,0x40);
  bVar2 = OpenODF2(unaff_EDI);
  pcVar4 = local_8c;
  pcVar1 = local_90;
  if (bVar2) {
    do {
      iVar3 = GetODFFloat(local_84,pcVar1,pcVar4,local_88,(float)param_4);
      if (iVar3 != 0) {
        return 1;
      }
      iVar3 = GetODFString(local_84,"GameObjectClass","classlabel",0x40,local_44,(char *)0x0);
      if (iVar3 == 0) {
        return 0;
      }
      CombineStrings(".odf",(char *)0x40,unaff_EDI,unaff_ESI);
      iVar3 = _stricmp(local_84,local_44);
      if (iVar3 == 0) {
        return 0;
      }
      strcpy_s(local_84,0x40,local_44);
      bVar2 = OpenODF2(unaff_EDI);
    } while (bVar2);
  }
  return 0;
}


// ---------------------------------------------------------------------
// GetODFDouble  @ 4fc05fb4  lines 4452-4480


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl
GetODFDouble(char *param_1,char *param_2,char *param_3,char *param_4,double *param_5,double param_6)

{
  char *pcVar1;
  bool bVar2;
  int iVar3;
  char *in_ECX;
  char *pcVar4;
  uint unaff_ESI;
  char *unaff_EDI;
  char local_88 [64];
  char local_48 [68];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)local_88;
  if ((in_ECX == (char *)0x0) ||
     (iVar3 = GetODFDouble(in_ECX,param_1,param_2,(double *)param_3,
                           (double)CONCAT44(param_5,param_4)), iVar3 == 0)) {
    memset(local_88,0,0x40);
    pcVar1 = in_ECX;
    do {
      pcVar4 = pcVar1;
      pcVar1 = pcVar4 + 1;
    } while (*pcVar4 != '\0');
    iVar3 = _stricmp(pcVar4 + -4,".odf");
    if (iVar3 != 0) {
      in_ECX = ".odf";
    }
    CombineStrings(in_ECX,(char *)0x40,unaff_EDI,unaff_ESI);
    memset(local_48,0,0x40);
    while (bVar2 = OpenODF2(unaff_EDI), bVar2) {
      iVar3 = GetODFDouble(local_88,param_1,param_2,(double *)param_3,
                           (double)CONCAT44(param_5,param_4));
      if (iVar3 != 0) goto LAB_4fc06004;
      iVar3 = GetODFString(local_88,"GameObjectClass","classlabel",0x40,local_48,(char *)0x0);
      if (iVar3 == 0) break;
      CombineStrings(".odf",(char *)0x40,unaff_EDI,unaff_ESI);
      iVar3 = _stricmp(local_88,local_48);
      if (iVar3 == 0) break;
      strcpy_s(local_88,0x40,local_48);
    }
    iVar3 = 0;
  }
  else {
LAB_4fc06004:
    iVar3 = 1;
  }
  return iVar3;
}


// ---------------------------------------------------------------------
// GetODFChar  @ 4fc06126  lines 4482-4510


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl
GetODFChar(char *param_1,char *param_2,char *param_3,char *param_4,char *param_5,char param_6)

{
  char *pcVar1;
  bool bVar2;
  int iVar3;
  char *in_ECX;
  char *pcVar4;
  char *in_EDX;
  uint unaff_ESI;
  char *unaff_EDI;
  char cVar5;
  char *local_90;
  char *local_8c;
  char *local_88;
  char local_84 [64];
  char local_44 [64];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)&local_90;
  local_90 = param_1;
  local_8c = param_2;
  local_88 = param_3;
  cVar5 = (char)param_4;
  if ((in_ECX != (char *)0x0) &&
     (iVar3 = GetODFChar(in_ECX,param_1,param_2,param_3,cVar5), iVar3 != 0)) {
    return 1;
  }
  if ((in_EDX != (char *)0x0) &&
     (iVar3 = GetODFChar(in_EDX,local_90,local_8c,local_88,cVar5), iVar3 != 0)) {
    return 1;
  }
  memset(local_84,0,0x40);
  if (in_EDX == (char *)0x0) {
    pcVar1 = in_ECX;
    do {
      pcVar4 = pcVar1;
      pcVar1 = pcVar4 + 1;
    } while (*pcVar4 != '\0');
    iVar3 = _stricmp(pcVar4 + -4,".odf");
    if (iVar3 == 0) {
      in_EDX = in_ECX;
      goto LAB_4fc0622a;
    }
  }
  else {
    pcVar1 = in_EDX;
    do {
      pcVar4 = pcVar1;
      pcVar1 = pcVar4 + 1;
    } while (*pcVar4 != '\0');
    iVar3 = _stricmp(pcVar4 + -4,".odf");
    if (iVar3 == 0) goto LAB_4fc0622a;
  }
  in_EDX = ".odf";
LAB_4fc0622a:
  CombineStrings(in_EDX,(char *)0x40,unaff_EDI,unaff_ESI);
  memset(local_44,0,0x40);
  bVar2 = OpenODF2(unaff_EDI);
  pcVar4 = local_8c;
  pcVar1 = local_90;
  if (bVar2) {
    do {
      iVar3 = GetODFChar(local_84,pcVar1,pcVar4,local_88,cVar5);
      if (iVar3 != 0) {
        return 1;
      }
      iVar3 = GetODFString(local_84,"GameObjectClass","classlabel",0x40,local_44,(char *)0x0);
      if (iVar3 == 0) {
        return 0;
      }
      CombineStrings(".odf",(char *)0x40,unaff_EDI,unaff_ESI);
      iVar3 = _stricmp(local_84,local_44);
      if (iVar3 == 0) {
        return 0;
      }
      strcpy_s(local_84,0x40,local_44);
      bVar2 = OpenODF2(unaff_EDI);
    } while (bVar2);
  }
  return 0;
}


// ---------------------------------------------------------------------
// GetODFBool  @ 4fc0630e  lines 4512-4540


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl
GetODFBool(char *param_1,char *param_2,char *param_3,char *param_4,bool *param_5,bool param_6)

{
  char *pcVar1;
  bool bVar2;
  int iVar3;
  char *in_ECX;
  char *pcVar4;
  char *in_EDX;
  uint unaff_ESI;
  char *unaff_EDI;
  bool bVar5;
  char *local_90;
  char *local_8c;
  bool *local_88;
  char local_84 [64];
  char local_44 [64];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)&local_90;
  local_90 = param_1;
  local_8c = param_2;
  local_88 = (bool *)param_3;
  bVar5 = SUB41(param_4,0);
  if ((in_ECX != (char *)0x0) &&
     (iVar3 = GetODFBool(in_ECX,param_1,param_2,(bool *)param_3,bVar5), iVar3 != 0)) {
    return 1;
  }
  if ((in_EDX != (char *)0x0) &&
     (iVar3 = GetODFBool(in_EDX,local_90,local_8c,local_88,bVar5), iVar3 != 0)) {
    return 1;
  }
  memset(local_84,0,0x40);
  if (in_EDX == (char *)0x0) {
    pcVar1 = in_ECX;
    do {
      pcVar4 = pcVar1;
      pcVar1 = pcVar4 + 1;
    } while (*pcVar4 != '\0');
    iVar3 = _stricmp(pcVar4 + -4,".odf");
    if (iVar3 == 0) {
      in_EDX = in_ECX;
      goto LAB_4fc06412;
    }
  }
  else {
    pcVar1 = in_EDX;
    do {
      pcVar4 = pcVar1;
      pcVar1 = pcVar4 + 1;
    } while (*pcVar4 != '\0');
    iVar3 = _stricmp(pcVar4 + -4,".odf");
    if (iVar3 == 0) goto LAB_4fc06412;
  }
  in_EDX = ".odf";
LAB_4fc06412:
  CombineStrings(in_EDX,(char *)0x40,unaff_EDI,unaff_ESI);
  memset(local_44,0,0x40);
  bVar2 = OpenODF2(unaff_EDI);
  pcVar4 = local_8c;
  pcVar1 = local_90;
  if (bVar2) {
    do {
      iVar3 = GetODFBool(local_84,pcVar1,pcVar4,local_88,bVar5);
      if (iVar3 != 0) {
        return 1;
      }
      iVar3 = GetODFString(local_84,"GameObjectClass","classlabel",0x40,local_44,(char *)0x0);
      if (iVar3 == 0) {
        return 0;
      }
      CombineStrings(".odf",(char *)0x40,unaff_EDI,unaff_ESI);
      iVar3 = _stricmp(local_84,local_44);
      if (iVar3 == 0) {
        return 0;
      }
      strcpy_s(local_84,0x40,local_44);
      bVar2 = OpenODF2(unaff_EDI);
    } while (bVar2);
  }
  return 0;
}


// ---------------------------------------------------------------------
// GetODFString  @ 4fc064f6  lines 4542-4570


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl
GetODFString(char *param_1,char *param_2,char *param_3,char *param_4,uint param_5,char *param_6,
            char *param_7)

{
  char *pcVar1;
  bool bVar2;
  int iVar3;
  char *in_ECX;
  char *pcVar4;
  char *in_EDX;
  uint unaff_ESI;
  char *unaff_EDI;
  code *pcVar5;
  char *local_94;
  char *local_90;
  char *local_8c;
  char *local_88;
  char local_84 [64];
  char local_44 [64];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)&local_94;
  local_94 = param_1;
  local_8c = param_2;
  local_90 = param_4;
  local_88 = (char *)param_5;
  if ((in_ECX != (char *)0x0) &&
     (iVar3 = GetODFString(in_ECX,param_1,param_2,(uint)param_3,param_4,(char *)param_5), iVar3 != 0
     )) {
    return 1;
  }
  if ((in_EDX != (char *)0x0) &&
     (iVar3 = GetODFString(in_EDX,local_94,local_8c,(uint)param_3,local_90,(char *)param_5),
     iVar3 != 0)) {
    return 1;
  }
  memset(local_84,0,0x40);
  pcVar5 = _stricmp_exref;
  if (in_EDX == (char *)0x0) {
    pcVar1 = in_ECX;
    do {
      pcVar4 = pcVar1;
      pcVar1 = pcVar4 + 1;
    } while (*pcVar4 != '\0');
    iVar3 = _stricmp(pcVar4 + -4,".odf");
    pcVar5 = _stricmp_exref;
    if (iVar3 == 0) {
      in_EDX = in_ECX;
      goto LAB_4fc06611;
    }
  }
  else {
    pcVar1 = in_EDX;
    do {
      pcVar4 = pcVar1;
      pcVar1 = pcVar4 + 1;
    } while (*pcVar4 != '\0');
    iVar3 = _stricmp(pcVar4 + -4,".odf");
    if (iVar3 == 0) goto LAB_4fc06611;
  }
  in_EDX = ".odf";
LAB_4fc06611:
  CombineStrings(in_EDX,(char *)0x40,unaff_EDI,unaff_ESI);
  memset(local_44,0,0x40);
  bVar2 = OpenODF2(unaff_EDI);
  pcVar1 = local_94;
  if (bVar2) {
    do {
      iVar3 = GetODFString(local_84,pcVar1,local_8c,(uint)param_3,local_90,local_88);
      if (iVar3 != 0) {
        return 1;
      }
      iVar3 = GetODFString(local_84,"GameObjectClass","classlabel",0x40,local_44,(char *)0x0);
      if (iVar3 == 0) {
        return 0;
      }
      CombineStrings(".odf",(char *)0x40,unaff_EDI,unaff_ESI);
      iVar3 = (*pcVar5)(local_84,local_44);
      if (iVar3 == 0) {
        return 0;
      }
      strcpy_s(local_84,0x40,local_44);
      bVar2 = OpenODF2(unaff_EDI);
    } while (bVar2);
  }
  return 0;
}


// ---------------------------------------------------------------------
// GetODFColor  @ 4fc066f0  lines 4572-4600


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl
GetODFColor(char *param_1,char *param_2,char *param_3,char *param_4,ulong *param_5,ulong param_6)

{
  char *pcVar1;
  bool bVar2;
  int iVar3;
  char *in_ECX;
  char *pcVar4;
  char *in_EDX;
  uint unaff_ESI;
  char *unaff_EDI;
  char *local_90;
  char *local_8c;
  ulong *local_88;
  char local_84 [64];
  char local_44 [64];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)&local_90;
  local_90 = param_1;
  local_8c = param_2;
  local_88 = (ulong *)param_3;
  if ((in_ECX != (char *)0x0) &&
     (iVar3 = GetODFColor(in_ECX,param_1,param_2,(ulong *)param_3,(ulong)param_4), iVar3 != 0)) {
    return 1;
  }
  if ((in_EDX != (char *)0x0) &&
     (iVar3 = GetODFColor(in_EDX,local_90,local_8c,local_88,(ulong)param_4), iVar3 != 0)) {
    return 1;
  }
  memset(local_84,0,0x40);
  if (in_EDX == (char *)0x0) {
    pcVar1 = in_ECX;
    do {
      pcVar4 = pcVar1;
      pcVar1 = pcVar4 + 1;
    } while (*pcVar4 != '\0');
    iVar3 = _stricmp(pcVar4 + -4,".odf");
    if (iVar3 == 0) {
      in_EDX = in_ECX;
      goto LAB_4fc067f4;
    }
  }
  else {
    pcVar1 = in_EDX;
    do {
      pcVar4 = pcVar1;
      pcVar1 = pcVar4 + 1;
    } while (*pcVar4 != '\0');
    iVar3 = _stricmp(pcVar4 + -4,".odf");
    if (iVar3 == 0) goto LAB_4fc067f4;
  }
  in_EDX = ".odf";
LAB_4fc067f4:
  CombineStrings(in_EDX,(char *)0x40,unaff_EDI,unaff_ESI);
  memset(local_44,0,0x40);
  bVar2 = OpenODF2(unaff_EDI);
  pcVar4 = local_8c;
  pcVar1 = local_90;
  if (bVar2) {
    do {
      iVar3 = GetODFColor(local_84,pcVar1,pcVar4,local_88,(ulong)param_4);
      if (iVar3 != 0) {
        return 1;
      }
      iVar3 = GetODFString(local_84,"GameObjectClass","classlabel",0x40,local_44,(char *)0x0);
      if (iVar3 == 0) {
        return 0;
      }
      CombineStrings(".odf",(char *)0x40,unaff_EDI,unaff_ESI);
      iVar3 = _stricmp(local_84,local_44);
      if (iVar3 == 0) {
        return 0;
      }
      strcpy_s(local_84,0x40,local_44);
      bVar2 = OpenODF2(unaff_EDI);
    } while (bVar2);
  }
  return 0;
}


// ---------------------------------------------------------------------
// GetODFVector  @ 4fc068d8  lines 4602-4630


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl
GetODFVector(char *param_1,char *param_2,char *param_3,char *param_4,Vector *param_5,Vector param_6)

{
  Vector VVar1;
  Vector VVar2;
  Vector VVar3;
  char *pcVar4;
  bool bVar5;
  int iVar6;
  char *in_ECX;
  char *pcVar7;
  char *in_EDX;
  code *pcVar8;
  uint unaff_ESI;
  char *unaff_EDI;
  char *local_90;
  Vector *local_8c;
  char *local_88;
  char local_84 [64];
  char local_44 [64];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)&local_90;
  local_90 = param_1;
  local_88 = param_2;
  local_8c = (Vector *)param_3;
  if ((in_ECX != (char *)0x0) &&
     (VVar1.y = (float)param_5, VVar1.x = (float)param_4, VVar1.z = param_6.x,
     iVar6 = GetODFVector(in_ECX,param_1,param_2,(Vector *)param_3,VVar1), iVar6 != 0)) {
    return 1;
  }
  if ((in_EDX != (char *)0x0) &&
     (VVar2.y = (float)param_5, VVar2.x = (float)param_4, VVar2.z = param_6.x,
     iVar6 = GetODFVector(in_EDX,local_90,local_88,local_8c,VVar2), iVar6 != 0)) {
    return 1;
  }
  memset(local_84,0,0x40);
  pcVar8 = _stricmp_exref;
  if (in_EDX == (char *)0x0) {
    pcVar4 = in_ECX;
    do {
      pcVar7 = pcVar4;
      pcVar4 = pcVar7 + 1;
    } while (*pcVar7 != '\0');
    iVar6 = _stricmp(pcVar7 + -4,".odf");
    pcVar8 = _stricmp_exref;
    if (iVar6 == 0) {
      in_EDX = in_ECX;
      goto LAB_4fc069f8;
    }
  }
  else {
    pcVar4 = in_EDX;
    do {
      pcVar7 = pcVar4;
      pcVar4 = pcVar7 + 1;
    } while (*pcVar7 != '\0');
    iVar6 = _stricmp(pcVar7 + -4,".odf");
    if (iVar6 == 0) goto LAB_4fc069f8;
  }
  in_EDX = ".odf";
LAB_4fc069f8:
  CombineStrings(in_EDX,(char *)0x40,unaff_EDI,unaff_ESI);
  memset(local_44,0,0x40);
  bVar5 = OpenODF2(unaff_EDI);
  pcVar4 = local_90;
  if (bVar5) {
    do {
      VVar3.y = (float)param_5;
      VVar3.x = (float)param_4;
      VVar3.z = param_6.x;
      iVar6 = GetODFVector(local_84,pcVar4,local_88,local_8c,VVar3);
      if (iVar6 != 0) {
        return 1;
      }
      iVar6 = GetODFString(local_84,"GameObjectClass","classlabel",0x40,local_44,(char *)0x0);
      if (iVar6 == 0) {
        return 0;
      }
      CombineStrings(".odf",(char *)0x40,unaff_EDI,unaff_ESI);
      iVar6 = (*pcVar8)(local_84,local_44);
      if (iVar6 == 0) {
        return 0;
      }
      strcpy_s(local_84,0x40,local_44);
      bVar5 = OpenODF2(unaff_EDI);
    } while (bVar5);
  }
  return 0;
}


// ---------------------------------------------------------------------
// GetBuildItem  @ 4fc06ae7  lines 4635-4775


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool __cdecl
GetBuildItem(int param_1,char *param_2,int *param_3,int param_4,char *param_5,char *param_6,
            char *param_7)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int in_ECX;
  char *in_EDX;
  int iVar5;
  char *unaff_ESI;
  int *unaff_EDI;
  int iVar6;
  char (*pacVar7) [64];
  char *pcVar8;
  uint local_210 [2];
  char *local_208;
  char local_204 [64];
  char local_1c4 [64];
  char local_184 [64];
  char local_144 [64];
  char local_104 [64];
  char local_c4 [64];
  char local_84 [64];
  char local_44 [64];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)local_210;
  local_208 = in_EDX;
  memset(local_c4,0,0x40);
  bVar1 = GetObjInfo(in_ECX,Get_GOClass,local_c4);
  if (bVar1) {
    uVar2 = Hash((char *)unaff_EDI,(uint)unaff_ESI);
    local_210[0] = 0;
    if (param_3 != (int *)0x0) {
      local_210[0] = Hash((char *)unaff_EDI,(uint)unaff_ESI);
    }
    if ((((uVar2 == 0x63ae241a) || (uVar2 == 0xe39ee1ae)) || (uVar2 == 0x8a0a1ead)) ||
       ((uVar2 == 0x77f02e21 || (uVar2 == 0x2418efcf)))) {
      iVar6 = 0;
      do {
        memset(local_1c4,0,0x40);
        if (uVar2 == 0x63ae241a) {
          if (iVar6 == 0) {
            pcVar8 = "ArmoryClass";
            goto LAB_4fc06be8;
          }
          pcVar8 = "ArmoryGroup%d";
LAB_4fc06bfc:
          sprintf_s<64>(&local_1c4,pcVar8);
        }
        else {
          if (iVar6 != 0) {
            pcVar8 = "BuildGroup%d";
            goto LAB_4fc06bfc;
          }
          if (uVar2 == 0x77f02e21) {
            pcVar8 = "ConstructionRigClass";
          }
          else {
            pcVar8 = "ConstructionRigTClass";
            if (uVar2 != 0x2418efcf) {
              pcVar8 = "FactoryClass";
            }
          }
LAB_4fc06be8:
          sprintf_s<64>(&local_1c4,pcVar8);
        }
        iVar5 = 0;
        do {
          memset(local_104,0,0x40);
          memset(local_184,0,0x40);
          memset(local_204,0,0x40);
          memset(local_144,0,0x40);
          memset(local_44,0,0x40);
          memset(local_84,0,0x40);
          pacVar7 = &local_84;
          iVar5 = iVar5 + 1;
          pcVar8 = "buildItem%d";
          sprintf_s<64>(pacVar7,"buildItem%d");
          iVar3 = GetODFString((int)local_84,(char *)0x40,local_104,0,*pacVar7,pcVar8);
          if ((iVar3 != 0) && (local_104[0] != '\0')) {
            CombineStrings(".odf",(char *)0x40,(char *)unaff_EDI,(uint)unaff_ESI);
            bVar1 = OpenODF2((char *)unaff_EDI);
            if ((bVar1) &&
               (iVar3 = GetODFString(local_184,"GameObjectClass","classlabel",0x40,local_144,
                                     (char *)0x0), iVar3 != 0)) {
              CombineStrings(".odf",(char *)0x40,(char *)unaff_EDI,(uint)unaff_ESI);
              bVar1 = OpenODF2((char *)unaff_EDI);
              if (bVar1) {
                GetODFString(local_204,"GameObjectClass","classlabel",0x40,local_144,(char *)0x0);
              }
              else {
                local_204[0] = '\0';
              }
            }
            GetODFString("WeaponPowerupClass","weaponName",(char *)0x40,local_44,0,(char *)unaff_EDI
                         ,unaff_ESI);
            if ((((((uint)param_2 & 1) != 0) && ((uVar2 == 0x4b970310 || (uVar2 == 0x33fe0a68)))) ||
                ((((uint)param_2 & 2) != 0 && ((uVar2 == 0xa662aa60 || (uVar2 == 0x33fe0a68)))))) ||
               ((((uint)param_2 & 4) != 0 &&
                ((param_3 != (int *)0x0 &&
                 (uVar4 = Hash((char *)unaff_EDI,(uint)unaff_ESI), uVar4 == local_210[0])))))) {
              GetODFInt("GameObjectClass","scrapCost",(char *)0x0,(char *)0x0,unaff_EDI,
                        (int)unaff_ESI);
              strcpy_s(local_208,0x40,local_104);
              return true;
            }
          }
        } while (iVar5 < 10);
        iVar6 = iVar6 + 1;
      } while (iVar6 < 0xb);
    }
  }
  return false;
}


// ---------------------------------------------------------------------
// ReplaceWeapons  @ 4fc06e46  lines 4780-5059


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool __cdecl ReplaceWeapons(int param_1,char (*param_2) [64],float *param_3,char *param_4)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  uint uVar5;
  char *pcVar6;
  int in_ECX;
  char cVar7;
  char *in_EDX;
  char *unaff_ESI;
  bool *unaff_EDI;
  int iVar8;
  float fVar9;
  char (*pacVar10) [64];
  undefined1 auStack_70c [7];
  char local_705;
  code *local_704;
  char *local_700;
  char *local_6fc;
  int local_6f4;
  code *local_6f0;
  int local_6ec;
  uint local_6e8 [10];
  uint local_6c0 [15];
  float local_684 [4];
  char cStack_674;
  char cStack_673;
  char cStack_672;
  char acStack_671 [8];
  char acStack_669 [9];
  char local_660 [8];
  char local_658 [8];
  undefined1 local_650 [64];
  char local_610 [64];
  char local_5d0 [64];
  char local_590 [7];
  byte local_589;
  byte local_550 [64];
  char local_510 [7];
  byte local_509;
  byte local_4d0 [64];
  undefined1 local_490 [64];
  char local_450 [64];
  char local_410 [64];
  char local_3d0 [256];
  char local_2d0 [64];
  char local_290 [320];
  char local_150 [324];
  uint local_c;
  
  local_c = __security_cookie ^ (uint)auStack_70c;
  local_6fc = *param_2;
  local_6ec = 0;
  local_700 = in_EDX;
  local_6f4 = in_ECX;
  memset(local_410,0,0x40);
  local_6f0 = GetObjInfo_exref;
  bVar1 = GetObjInfo(in_ECX,Get_ODF,local_410);
  if (!bVar1) {
    return false;
  }
  iVar2 = GetVarItemInt("network.session.ivar115");
  if (iVar2 == 0) {
    iVar2 = GetVarItemInt("network.session.civar5");
    local_705 = '\0';
    if (iVar2 == 0) goto LAB_4fc06ed7;
  }
  local_705 = '\x01';
LAB_4fc06ed7:
  memset(local_650,0,0x40);
  pcVar4 = local_410;
  if (local_6fc != (char *)0x0) {
    pcVar4 = local_6fc;
  }
  CombineStrings(pcVar4,(char *)0x40,unaff_EDI,(uint)unaff_ESI);
  CheckODFName(unaff_EDI);
  if (local_705 != '\0') {
    FormatLogMessage("Replace Weapons: ODF: %s NewWeapons: \'%s\' \'%s\' \'%s\' \'%s\' \'%s\'");
  }
  CombineStrings(".odf",(char *)0x40,unaff_EDI,(uint)unaff_ESI);
  memset(local_3d0,0,0x140);
  local_660[0] = '\0';
  local_660[1] = '\0';
  local_660[2] = '\0';
  local_660[3] = '\0';
  local_660[4] = 0;
  local_6c0[10] = 0;
  local_6c0[0xb] = 0;
  local_6c0[0xc] = 0;
  local_6c0[0xd] = 0;
  local_6c0[0xe] = 0;
  memset(local_150,0,0x140);
  local_658[0] = '\0';
  local_658[1] = '\0';
  local_658[2] = '\0';
  local_658[3] = '\0';
  local_658[4] = 0;
  local_684[0] = 0.0;
  local_684[1] = 0.0;
  local_684[2] = 0.0;
  local_684[3] = 0.0;
  cStack_674 = '\0';
  cStack_673 = '\0';
  cStack_672 = '\0';
  acStack_671[0] = '\0';
  local_6e8[0] = 0;
  local_6e8[1] = 0;
  local_6e8[2] = 0;
  local_6e8[3] = 0;
  local_6e8[4] = 0;
  memset(local_290,0,0x140);
  acStack_669[1] = '\0';
  acStack_669[2] = '\0';
  acStack_669[3] = '\0';
  acStack_669[4] = '\0';
  acStack_669[5] = 0;
  local_6c0[5] = 0;
  acStack_671[1] = '\0';
  acStack_671[2] = '\0';
  acStack_671[3] = '\0';
  acStack_671[4] = '\0';
  acStack_671[5] = 0;
  local_6c0[6] = 0;
  local_6c0[7] = 0;
  local_6c0[8] = 0;
  local_6c0[9] = 0;
  local_6e8[5] = 0;
  local_6e8[6] = 0;
  local_6e8[7] = 0;
  local_6e8[8] = 0;
  local_6e8[9] = 0;
  local_6c0[0] = 0;
  local_6c0[1] = 0;
  local_6c0[2] = 0;
  local_6c0[3] = 0;
  local_6c0[4] = 0;
  memset(local_550,0,0x40);
  memset(local_490,0,0x40);
  memset(local_4d0,0,0x40);
  bVar1 = OpenODF2(unaff_EDI);
  local_704 = GetODFString_exref;
  if (bVar1) {
    memset(local_5d0,0,0x40);
    iVar2 = (*local_704)(local_650,"GameObjectClass","classlabel",0x40,local_5d0,0);
    if (iVar2 != 0) {
      CombineStrings(".odf",(char *)0x40,unaff_EDI,(uint)unaff_ESI);
      bVar1 = OpenODF2(unaff_EDI);
      local_550[0] = local_550[0] & -bVar1;
    }
    local_6fc = (char *)0x5;
    iVar8 = 1;
    iVar2 = 0;
    do {
      memset(local_590,0,0x40);
      memset(local_610,0,0x40);
      sprintf_s<64>(&local_610,"weaponHard%d");
      iVar3 = GetODFString("GameObjectClass",local_610,(char *)0x40,local_590,0,unaff_EDI,unaff_ESI)
      ;
      if (iVar3 == 0) {
LAB_4fc071d1:
        sprintf_s<64>(&local_610,"weaponAssault%d");
        GetODFBool("GameObjectClass",local_610,acStack_669 + iVar8,(char *)0x0,unaff_EDI,
                   SUB41(unaff_ESI,0));
        sprintf_s<64>(&local_610,"weaponGroup%d");
        iVar3 = GetODFInt("GameObjectClass",local_610,(char *)((int)local_6c0 + iVar2),(char *)0x0,
                          (int *)unaff_EDI,(int)unaff_ESI);
        if (iVar3 != 0) {
          acStack_671[iVar8] = '\x01';
        }
      }
      else {
        iVar3 = _strnicmp(local_590,"HP_",3);
        if (iVar3 == 0) {
          pcVar4 = strchr(local_590 + 3,0x5f);
          if (pcVar4 != (char *)0x0) {
            *pcVar4 = '\0';
          }
          pcVar4 = local_590;
          do {
            cVar7 = *pcVar4;
            pcVar4 = pcVar4 + 1;
          } while (cVar7 != '\0');
          local_589 = local_589 & -((uint)((int)pcVar4 - (int)(local_590 + 1)) < 6);
          uVar5 = Hash(unaff_EDI,(uint)unaff_ESI);
          *(uint *)((int)local_6e8 + iVar2 + 0x14) = uVar5;
          goto LAB_4fc071d1;
        }
      }
      iVar8 = iVar8 + 1;
      iVar2 = iVar2 + 4;
      local_6fc = (char *)((int)local_6fc + -1);
    } while (local_6fc != (char *)0x0);
    local_6fc = (char *)0x0;
    in_EDX = local_700;
  }
  bVar1 = OpenODF2(unaff_EDI);
  if (bVar1) {
    pcVar4 = (char *)0x0;
    do {
      memset(local_510,0,0x40);
      memset(local_5d0,0,0x40);
      local_6fc = pcVar4 + 1;
      sprintf_s<64>(&local_5d0,"weaponHard%d");
      iVar2 = GetODFString((int)local_5d0,(char *)0x40,local_510,0,unaff_EDI,unaff_ESI);
      if ((iVar2 != 0) && (iVar2 = _strnicmp(local_510,"HP_",3), iVar2 == 0)) {
        pcVar6 = strchr(local_510 + 3,0x5f);
        if (pcVar6 != (char *)0x0) {
          *pcVar6 = '\0';
        }
        pcVar6 = local_510;
        do {
          cVar7 = *pcVar6;
          pcVar6 = pcVar6 + 1;
        } while (cVar7 != '\0');
        local_509 = local_509 & -((uint)((int)pcVar6 - (int)(local_510 + 1)) < 6);
        uVar5 = Hash(unaff_EDI,(uint)unaff_ESI);
        local_6c0[(int)(pcVar4 + 5)] = uVar5;
      }
      pcVar4 = local_6fc;
    } while ((int)local_6fc < 5);
    in_EDX = local_700;
  }
  iVar2 = 0;
  do {
    if (*(int *)((int)local_6e8 + iVar2 + 0x14) != *(int *)((int)local_6c0 + iVar2 + 0x14)) {
      return false;
    }
    iVar2 = iVar2 + 4;
  } while (iVar2 < 0x14);
  iVar2 = 0;
  local_700 = (char *)0x0;
  do {
    local_6fc = local_3d0 + (int)local_700;
    CombineStrings(local_6fc + ((int)in_EDX - (int)local_3d0),(char *)0x40,unaff_EDI,(uint)unaff_ESI
                  );
    if (param_1 == 0) {
      fVar9 = (float)__real_49742400;
    }
    else {
      fVar9 = *(float *)(param_1 + iVar2 * 4);
    }
    local_684[iVar2] = fVar9;
    CombineStrings(".odf",(char *)0x40,unaff_EDI,(uint)unaff_ESI);
    bVar1 = OpenODF2(unaff_EDI);
    if (bVar1) {
      memset(local_5d0,0,0x40);
      iVar8 = (*local_704)(local_490,"WeaponClass","classlabel",0x40,local_5d0,0);
      if (iVar8 != 0) {
        CombineStrings(".odf",(char *)0x40,unaff_EDI,(uint)unaff_ESI);
        bVar1 = OpenODF2(unaff_EDI);
        local_4d0[0] = local_4d0[0] & -bVar1;
      }
      pcVar6 = "isAssault";
      pcVar4 = "WeaponClass";
      GetODFBool("WeaponClass","isAssault",local_660 + iVar2,(char *)0x0,unaff_EDI,
                 SUB41(unaff_ESI,0));
      GetODFString("WeaponClass","altName",(char *)0x40,local_150 + (int)local_700,0,pcVar4,pcVar6);
      memset(local_450,0,0x40);
      iVar8 = GetODFString("WeaponClass","wpnCategory",(char *)0x40,local_450,0,unaff_EDI,unaff_ESI)
      ;
      if (iVar8 != 0) {
        memset(local_610,0,0x40);
        pcVar4 = local_450;
        pacVar10 = &local_610;
        sprintf_s<64>(pacVar10,pcVar4);
        CombineStrings(local_610,(char *)0x40,*pacVar10,(uint)pcVar4);
        uVar5 = Hash(unaff_EDI,(uint)unaff_ESI);
        local_6c0[iVar2 + 10] = uVar5;
      }
    }
    iVar8 = local_6f4;
    iVar2 = iVar2 + 1;
    local_700 = (char *)((int)local_700 + 0x40);
  } while ((int)local_700 < 0x140);
  iVar2 = 0;
  pcVar4 = local_290;
  do {
    (*local_6f0)(iVar8,iVar2 + 5,pcVar4);
    pcVar4 = pcVar4 + 0x40;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 5);
  iVar2 = 0;
  do {
    iVar8 = 0;
    local_704 = (code *)0x0;
    do {
      if (((local_6e8[iVar2 + 5] != 0) && (local_6e8[iVar8 + 5] != 0)) &&
         (local_6e8[iVar2 + 5] == local_6e8[iVar8 + 5])) {
        cVar7 = acStack_671[iVar2 + 1];
        local_700 = local_150;
        local_6fc = (char *)0x0;
        do {
          if (((cVar7 == '\0') && ((acStack_671 + 1)[(int)local_6fc] == '\0')) &&
             (local_6e8[iVar8 + 5] == local_6e8[(int)(local_6fc + 5)])) {
            if (((acStack_669[iVar2 + 1] == (acStack_669 + 1)[(int)local_6fc]) &&
                (0 < (int)local_6e8[(int)local_6fc])) && ((int)local_6fc < iVar2)) {
LAB_4fc07696:
              if (local_705 == '\0') goto LAB_4fc076be;
              pcVar4 = 
              "Assault Matchs, Weapon:%d, CompareWeapon:%d, NumHardTypesS: %d, T < C Skipping S. WeaponClassT: \'%d\'"
              ;
              goto LAB_4fc076ae;
            }
            if ((((local_660[(int)local_6fc] != '\0') && (*local_700 == '\0')) &&
                (iVar8 < (int)local_6fc)) && (acStack_669[iVar8 + 1] == '\0')) {
              iVar3 = _stricmp(local_3d0 + (int)local_704,local_290 + (int)local_704);
              if (iVar3 == 0) goto LAB_4fc07696;
              cVar7 = acStack_671[iVar2 + 1];
            }
          }
          local_6fc = local_6fc + 1;
          local_700 = local_700 + 0x40;
        } while ((int)local_6fc < 5);
        uVar5 = local_6c0[iVar8];
        if (local_6c0[iVar2] == uVar5) {
          if (((cVar7 == '\0') && (acStack_671[iVar8 + 1] == '\0')) || (iVar8 != iVar2))
          goto LAB_4fc076f9;
LAB_4fc0773b:
          local_6e8[iVar2] = local_6e8[iVar2] + 1;
        }
        else {
          if (iVar8 <= iVar2) goto LAB_4fc0773b;
LAB_4fc076f9:
          if (cVar7 == '\0') {
            if (acStack_669[iVar2 + 1] == acStack_669[iVar8 + 1]) {
              if (((acStack_671[iVar8 + 1] == '\0') && (iVar2 <= iVar8)) &&
                 ((int)local_6e8[iVar2] <= (int)local_6e8[iVar8])) goto LAB_4fc0773b;
            }
            else if ((acStack_671[iVar8 + 1] == '\0') &&
                    ((int)local_6e8[iVar2] < (int)local_6e8[iVar8])) goto LAB_4fc0773b;
          }
        }
        if (local_705 != '\0') {
          if (local_6c0[iVar2] == uVar5) {
            if (((cVar7 != '\0') || (acStack_671[iVar8 + 1] != '\0')) && (iVar8 == iVar2))
            goto LAB_4fc077a8;
          }
          else if (iVar8 <= iVar2) {
LAB_4fc077a8:
            FormatLogMessage(
                            "Using Groups, Groups Dont Match, S<C, or We are Ourselves, Weapon:%d, CompareWeapon:%d"
                            );
            goto LAB_4fc076be;
          }
          if (acStack_669[iVar2 + 1] == acStack_669[iVar8 + 1]) {
            if (((cVar7 == '\0') && (acStack_671[iVar8 + 1] == '\0')) && (iVar2 <= iVar8)) {
              pcVar4 = 
              "Assault Matchs, Weapon:%d, CompareWeapon:%d, NumHardTypesS: %d, NumHardTypesC: %d";
              goto LAB_4fc076ae;
            }
          }
          else if (((cVar7 == '\0') && (acStack_671[iVar8 + 1] == '\0')) &&
                  ((int)local_6e8[iVar2] < (int)local_6e8[iVar8])) {
            pcVar4 = 
            "Assault NOT Matches,Weapon:%d, CompareWeapon:%d, NumHardTypesC: %d < NumHardTypesS: %d"
            ;
LAB_4fc076ae:
            FormatLogMessage(pcVar4);
          }
        }
      }
LAB_4fc076be:
      local_704 = (code *)((int)local_704 + 0x40);
      iVar8 = iVar8 + 1;
    } while ((int)local_704 < 0x140);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 5);
  iVar2 = 0;
  local_700 = (char *)0x0;
  do {
    iVar8 = 0;
    uVar5 = local_6e8[iVar2 + 5];
    local_704 = (code *)iVar8;
    do {
      if (local_705 == '\0') {
LAB_4fc07834:
        if (((((uVar5 != 0) && (local_6e8[iVar8 + 5] != 0)) && (uVar5 == local_6e8[iVar8 + 5])) &&
            ((uVar5 == local_6c0[iVar2 + 10] &&
             ((iVar2 != iVar8 ||
              (iVar3 = _stricmp(local_3d0 + (int)local_700,local_290 + (int)local_700), iVar3 != 0))
             )))) && ((iVar3 = _stricmp(local_3d0 + (int)local_700,local_290 + (int)local_700),
                      iVar3 != 0 ||
                      ((0 < iVar8 &&
                       (iVar3 = _stricmp(local_3d0 + (int)local_704,local_290 + (int)local_704),
                       iVar3 != 0)))))) {
          if (local_705 != '\0') {
            FormatLogMessage(
                            "Build Weapons C: Weapon Class C: %d is: \'%d\', Weapon Class S: %d Is: \'%d\'"
                            );
          }
          local_658[iVar2] = '\x01';
        }
      }
      else if (uVar5 != 0) {
        FormatLogMessage("Weapon Class C: %d is: \'%d\', Weapon Class S: %d Is: \'%d\'");
        goto LAB_4fc07834;
      }
      iVar3 = local_6f4;
      local_704 = (code *)((int)local_704 + 0x40);
      iVar8 = iVar8 + 1;
    } while ((int)local_704 < 0x140);
    iVar2 = iVar2 + 1;
    local_700 = (char *)((int)local_700 + 0x40);
    iVar8 = 0;
    if (4 < iVar2) {
      iVar2 = 4;
      cVar7 = local_705;
      do {
        if ((cVar7 != '\0') && (local_2d0[iVar8] != '\0')) {
          FormatLogMessage(
                          "Index: %d Original Weapon: \'%s\', New Weapon: \'%s\', Number of Hardpoints: %d"
                          );
          cVar7 = local_705;
        }
        if ((local_2d0[iVar8] != '\0') && (local_658[iVar2] != '\0')) {
          GiveWeapon(iVar3,iVar2,local_2d0 + iVar8);
          cVar7 = local_705;
          if (local_705 != '\0') {
            FormatLogMessage("Giving Weapon: \'%s\', index: %d");
            cVar7 = local_705;
          }
        }
        iVar8 = iVar8 + -0x40;
        iVar2 = iVar2 + -1;
      } while (-0x140 < iVar8);
      iVar2 = local_6ec;
      do {
        SetCurLocalAmmo(local_6f4,local_684[iVar2],iVar2);
        iVar2 = iVar2 + 1;
      } while (iVar2 < 5);
      return true;
    }
  } while( true );
}

