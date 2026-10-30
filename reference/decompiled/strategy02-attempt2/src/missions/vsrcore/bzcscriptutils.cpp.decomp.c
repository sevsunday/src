// Reconstructed by Ghidra from Strategy02.dll + Strategy02.pdb
// Original source file: /e:/github/vsr_dll_source/missions/vsrcore/bzcscriptutils.cpp
// Functions are ordered by original source line. This is decompiler
// output, not the author's source: names/types come from the PDB,
// local variable names and control flow are reconstructed.

// ---------------------------------------------------------------------
// `dynamic_initializer_for_'ODFNameMap''  @ 4fc010e2  lines 24-24

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
// `dynamic_initializer_for_'ODFNameBlackListMap''  @ 4fc01126  lines 26-26

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
// `dynamic_initializer_for_'FileNameMap''  @ 4fc0116a  lines 28-28

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
// IsRecycler  @ 4fc02393  lines 298-311

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool __cdecl IsRecycler(int h)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  char BZCClass [64];
  char ObjClass [64];
  uint local_8;
  
  local_8 = __security_cookie ^ (uint)&stack0xfffffffc;
  memset(ObjClass,0,0x40);
  bVar1 = GetObjInfo(h,Get_GOClass,ObjClass);
  bVar2 = false;
  if (bVar1) {
    memset(BZCClass,0,0x40);
    GetODFString(h,"GameObjectClass","BZCClasslabel",0x40,BZCClass,(char *)0x0);
    iVar3 = _stricmp(ObjClass,"CLASS_RECYCLER");
    if ((((iVar3 == 0) || (iVar3 = _stricmp(ObjClass,"CLASS_RECYCLERVEHICLE"), iVar3 == 0)) ||
        (iVar3 = _stricmp(ObjClass,"CLASS_RECYCLERVEHICLEH"), iVar3 == 0)) ||
       (iVar3 = _stricmp(BZCClass,"recy"), bVar2 = false, iVar3 == 0)) {
      bVar2 = true;
    }
  }
  return bVar2;
}


// ---------------------------------------------------------------------
// HRotateFront  @ 4fc02456  lines 615-630

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
// SetAngle  @ 4fc024dd  lines 633-641

void __cdecl SetAngle(int h,float Degrees)

{
  Vector VVar1;
  Vector VVar2;
  bool bVar3;
  float unaff_EDI;
  Vector *pVVar4;
  Vector *pVVar5;
  Matrix Position;
  Vector local_24;
  float Front;
  float local_14;
  float local_10;
  float local_c;
  
  bVar3 = IsAround(h);
  if (bVar3) {
    local_c = Degrees * 0.017453292;
    Front = 0.0;
    local_14 = 0.0;
    local_10 = 1.0;
    VVar1.z = local_c;
    VVar1.x = 0.0;
    VVar1.y = 1.0;
    HRotateFront((Vector *)0x0,VVar1,unaff_EDI);
    pVVar5 = &local_24;
    pVVar4 = (Vector *)h;
    GetPosition(h,pVVar5);
    Build_Directinal_Matrix((Matrix *)&Front,pVVar4,pVVar5);
    SetPosition(h,&Position);
    VVar2.y = Position.posit.y;
    VVar2.x = Position.posit.x;
    VVar2.z = Position.posit.z;
    SetVectorPosition(h,VVar2);
  }
  return;
}


// ---------------------------------------------------------------------
// CameraPos  @ 4fc02569  lines 647-673

bool __cdecl CameraPos(int me,int him,Vector *PosA,Vector *PosB,float Speed)

{
  float fVar1;
  float fVar2;
  float fVar3;
  Vector v;
  bool bVar4;
  int iVar5;
  float fVar6;
  undefined8 local_c;
  float local_4;
  
  fVar1 = PosB->x - PosA->x;
  fVar2 = PosB->y - PosA->y;
  local_c._4_4_ = fVar2;
  local_c._0_4_ = fVar1;
  fVar3 = PosB->z - PosA->z;
  v.y = fVar2;
  v.x = fVar1;
  v.z = fVar3;
  local_4 = fVar3;
  fVar6 = GetLength3D(v);
  local_c = (double)Speed;
  if (0.0 <= CameraTime) {
    iVar5 = SecondsToTurns(1.0);
    PosA = (Vector *)&local_c;
    fVar6 = (float)local_c / (fVar6 * 100.0 * (float)iVar5);
    local_c = (double)CONCAT44(fVar2 * fVar6 + CameraPosition.y,fVar1 * fVar6 + CameraPosition.x);
    local_4 = fVar6 * fVar3 + CameraPosition.z;
  }
  else {
    CameraTime = fVar6 / (Speed * 0.01) + misnImport.time;
  }
  CameraPosition.x = PosA->x;
  CameraPosition.y = PosA->y;
  CameraPosition.z = PosA->z;
  bVar4 = CameraObject(me,*PosA,him);
  if (((!bVar4) && (misnImport.time <= CameraTime)) && (bVar4 = IsAround(him), bVar4)) {
    return false;
  }
  CameraTime = -1.0;
  return true;
}


// ---------------------------------------------------------------------
// CameraOf  @ 4fc026d2  lines 677-682

void __cdecl CameraOf(int me,Vector *Offset)

{
  bool bVar1;
  Vector *pVVar2;
  Vector *unaff_EDI;
  Matrix *pMVar3;
  Matrix local_5c;
  Vector local_10;
  
  bVar1 = IsAround(me);
  if (bVar1) {
    GetFront(me,&local_10);
    GetPosition(me,&local_5c);
    pMVar3 = (Matrix *)&local_10;
    pVVar2 = Vector_Transform(Offset,pMVar3,unaff_EDI);
    SetCameraPosition(pVVar2,&pMVar3->right);
  }
  return;
}


// ---------------------------------------------------------------------
// Move  @ 4fc02723  lines 686-747

bool __cdecl Move(int param_1,float param_2,float param_3,Vector *param_4,bool param_5,bool param_6)

{
  float fVar1;
  Vector VVar2;
  Vector v;
  bool bVar3;
  int iVar4;
  Matrix *pMVar5;
  Vector *pVVar6;
  int in_ECX;
  int iVar7;
  float *in_EDX;
  Vector *unaff_ESI;
  Vector *unaff_EDI;
  Matrix *pMVar8;
  float fVar9;
  Vector local_f8;
  Matrix local_ec;
  Vector local_a8 [3];
  Matrix local_84 [2];
  
  bVar3 = IsAround(in_ECX);
  if (bVar3) {
    iVar4 = SecondsToTurns(1.0);
    GetPosition(in_ECX,&local_ec);
    pMVar5 = &local_ec;
    pMVar8 = local_84;
    for (iVar7 = 0x10; iVar7 != 0; iVar7 = iVar7 + -1) {
      (pMVar8->right).x = (pMVar5->right).x;
      pMVar5 = (Matrix *)&(pMVar5->right).y;
      pMVar8 = (Matrix *)&(pMVar8->right).y;
    }
    if ((float)param_1 != 0.0) {
      GetFront(in_ECX,local_a8);
      VVar2.y = local_a8[0].z;
      VVar2.x = local_a8[0].y;
      VVar2.z = (float)param_1 * (1.0 / (float)iVar4) * 0.017453292;
      pMVar5 = (Matrix *)HRotateFront((Vector *)local_a8[0].x,VVar2,(float)unaff_EDI);
      pMVar5 = Build_Directinal_Matrix(pMVar5,(Vector *)local_a8[0].x,(Vector *)local_a8[0].y);
      pMVar8 = local_84;
      for (iVar7 = 0x10; iVar7 != 0; iVar7 = iVar7 + -1) {
        (pMVar8->right).x = (pMVar5->right).x;
        pMVar5 = (Matrix *)&(pMVar5->right).y;
        pMVar8 = (Matrix *)&(pMVar8->right).y;
      }
    }
    if (param_2 != 0.0) {
      local_f8.x = *in_EDX - local_ec.posit.x;
      local_f8.y = in_EDX[1] - local_ec.posit.y;
      local_f8.z = in_EDX[2] - local_ec.posit.z;
      fVar1 = (1.0 / (float)iVar4) * param_2;
      v.y = local_f8.y;
      v.x = local_f8.x;
      v.z = local_f8.z;
      fVar9 = GetLength3D(v);
      if (fVar1 <= fVar9) {
        pVVar6 = Normalize_Vector(unaff_EDI,unaff_ESI);
        local_84[0].posit.x = local_ec.posit.x + pVVar6->x * fVar1;
        local_84[0].posit.y = pVVar6->y * fVar1 + local_ec.posit.y;
        local_84[0].posit.z = pVVar6->z * fVar1 + local_ec.posit.z;
        fVar1 = fVar1 / 10.0;
        local_f8.x = fVar1 * pVVar6->x;
        local_f8.y = pVVar6->y * fVar1;
        local_f8.z = pVVar6->z * fVar1;
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
// Move  @ 4fc0295f  lines 750-780

bool __cdecl Move(int param_1,float param_2,float param_3,bool param_4)

{
  Vector VVar1;
  bool bVar2;
  int iVar3;
  Matrix *pMVar4;
  int in_ECX;
  float unaff_EDI;
  Matrix *pMVar5;
  Matrix OldMat;
  Matrix NewMat;
  Vector local_14;
  float local_8;
  
  bVar2 = IsAround(in_ECX);
  if ((bVar2) && (misnImport.time < param_2)) {
    iVar3 = SecondsToTurns(1.0);
    local_8 = 1.0 / (float)iVar3;
    GetPosition(in_ECX,&OldMat);
    pMVar4 = &OldMat;
    pMVar5 = &NewMat;
    for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
      (pMVar5->right).x = (pMVar4->right).x;
      pMVar4 = (Matrix *)&(pMVar4->right).y;
      pMVar5 = (Matrix *)&(pMVar5->right).y;
    }
    if ((float)param_1 != 0.0) {
      GetFront(in_ECX,&local_14);
      local_8 = local_8 * (float)param_1 * 0.017453292;
      VVar1.y = local_14.z;
      VVar1.x = local_14.y;
      VVar1.z = local_8;
      pMVar4 = (Matrix *)HRotateFront((Vector *)local_14.x,VVar1,unaff_EDI);
      pMVar4 = Build_Directinal_Matrix(pMVar4,(Vector *)local_14.x,(Vector *)local_14.y);
      pMVar5 = &NewMat;
      for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
        (pMVar5->right).x = (pMVar4->right).x;
        pMVar4 = (Matrix *)&(pMVar4->right).y;
        pMVar5 = (Matrix *)&(pMVar5->right).y;
      }
      SetLastCurrentPosition(in_ECX,&OldMat,&NewMat);
      SetInterpolablePosition(in_ECX,&NewMat,&OldMat,false);
      return false;
    }
  }
  return true;
}


// ---------------------------------------------------------------------
// CameraCircle  @ 4fc02a66  lines 789-829

bool __cdecl CameraCircle(int me,Vector Offset,int him,Vector *Speed)

{
  float fVar1;
  float fVar2;
  float fVar3;
  bool bVar4;
  int iVar5;
  float fVar6;
  float fVar7;
  
  fVar6 = GetLength3D(Offset);
  fVar7 = Speed->x;
  fVar1 = Speed->y;
  fVar2 = Speed->z;
  if (0.0 <= CameraTime) {
    iVar5 = SecondsToTurns(1.0);
    fVar3 = 1.0 / (float)iVar5;
    CircleCalculation.x = (fVar7 + fVar1) * fVar3 + CircleCalculation.x;
    CircleCalculation.y = (fVar2 + fVar1) * fVar3 + CircleCalculation.y;
    CircleCalculation.z = CircleCalculation.z + (fVar2 + fVar7) * fVar3;
    fVar7 = portable_sin(CircleCalculation.x * 0.017453292);
    CameraPosition.x = fVar7 * fVar6;
    fVar7 = portable_cos(CircleCalculation.y * 0.017453292);
    CameraPosition.y = fVar7 * fVar6;
    fVar7 = portable_cos(CircleCalculation.z * 0.017453292);
    CameraPosition.z = fVar7 * fVar6;
  }
  else {
    CameraTime = 1.0;
    CameraPosition.x = Offset.x;
    CameraPosition.y = Offset.y;
    CameraPosition.z = Offset.z;
    CircleCalculation.x = 0.0;
    CircleCalculation.y = 0.0;
    CircleCalculation.z = 0.0;
  }
  bVar4 = CameraObject(me,CameraPosition.x,CameraPosition.y,CameraPosition.z,him);
  if ((!bVar4) && (bVar4 = IsAround(him), bVar4)) {
    return false;
  }
  CameraTime = -1.0;
  return true;
}


// ---------------------------------------------------------------------
// FormatConsoleMessage  @ 4fc02c53  lines 833-872

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __cdecl FormatConsoleMessage(char *format)

{
  char cVar1;
  char *pcVar2;
  ulong64 *puVar3;
  char *pcVar4;
  char *pcVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined1 *puVar9;
  char local_804 [2048];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)local_804;
  pcVar2 = FormatFromFile(format);
  memset(local_804,0,0x800);
  puVar9 = &stack0x00000008;
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
      if (0x1ff < (int)pcVar5 - (int)pcVar4) goto LAB_4fc02d2e;
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
LAB_4fc02d2e:
      PrintConsoleMessage(pcVar4);
    }
  }
  return;
}


// ---------------------------------------------------------------------
// FileOpen  @ 4fc02d4b  lines 876-936

/* WARNING: Function: _chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Type propagation algorithm not settling */

bool __cdecl FileOpen(char *Filename,bool Append)

{
  int iVar1;
  undefined4 uVar2;
  bool bVar3;
  _List_iterator<std::_List_val<std::_List_simple_types<std::pair<char_const_*_const,_iobuf_*>_>_>_>
  _Var4;
  char *pcVar5;
  wchar_t *pwVar6;
  FILE *pFVar7;
  _iobuf **pp_Var8;
  _Hash<std::_Umap_traits<char_const_*,_iobuf_*,std::_Uhash_compare<char_const_*,std::hash<char_const_*>,std::equal_to<char_const_*>_>,std::allocator<std::pair<char_const_*_const,_iobuf_*>_>,0>_>
  *in_ECX;
  unordered_map<char_const_*,_iobuf_*,std::hash<char_const_*>,std::equal_to<char_const_*>,std::allocator<std::pair<char_const_*_const,_iobuf_*>_>_>
  *this;
  char in_DL;
  int aiStackY_1050 [6];
  undefined1 auStackY_1038 [4];
  int aiStackY_1034 [2];
  _Hash<std::_Umap_traits<char_const_*,_iobuf_*,std::_Uhash_compare<char_const_*,std::hash<char_const_*>,std::equal_to<char_const_*>_>,std::allocator<std::pair<char_const_*_const,_iobuf_*>_>,0>_>
  **pp_Stack_1024;
  char *local_1014;
  uint local_1010;
  _Hash<std::_Umap_traits<char_const_*,_iobuf_*,std::_Uhash_compare<char_const_*,std::hash<char_const_*>,std::equal_to<char_const_*>_>,std::allocator<std::pair<char_const_*_const,_iobuf_*>_>,0>_>
  *local_100c;
  undefined1 local_1008 [116];
  undefined1 local_f94 [3980];
  uint local_8;
  
  uVar2 = FileNameMap._4_4_;
  local_8 = __security_cookie ^ (uint)local_f94;
  pp_Stack_1024 = &local_100c;
  local_100c = in_ECX;
  _Var4 = std::
          _Hash<std::_Umap_traits<char_const_*,_iobuf_*,std::_Uhash_compare<char_const_*,std::hash<char_const_*>,std::equal_to<char_const_*>_>,std::allocator<std::pair<char_const_*_const,_iobuf_*>_>,0>_>
          ::find(in_ECX,&local_1014);
  if (*(int *)_Var4 != uVar2) {
    return true;
  }
  aiStackY_1034[1] = 0x4fc02da0;
  pcVar5 = strstr((char *)in_ECX,"..");
  if (pcVar5 == (char *)0x0) {
    aiStackY_1034[1] = 0x4fc02db4;
    pcVar5 = strstr((char *)local_100c,":");
    if (pcVar5 == (char *)0x0) {
      local_1010 = 0;
      aiStackY_1034[1] = 0x4fc02dce;
      GetOutputPath(&local_1010,(wchar_t *)0x0);
      iVar1 = local_1010 * -2;
      *(int *)(local_1008 + iVar1 + -0x20) = (int)&pp_Stack_1024 + iVar1;
      *(uint **)(&stack0xffffefd4 + iVar1) = &local_1010;
      *(undefined4 *)((int)aiStackY_1034 + iVar1 + 4) = 0x4fc02de3;
      bVar3 = GetOutputPath(*(uint **)(&stack0xffffefd4 + iVar1),
                            *(wchar_t **)(local_1008 + iVar1 + -0x20));
      if (!bVar3) {
        return false;
      }
      *(undefined4 *)(local_1008 + iVar1 + -0x20) = 0x1000;
      *(undefined4 *)(&stack0xffffefd4 + iVar1) = 0;
      *(undefined1 **)((int)aiStackY_1034 + iVar1 + 4) = local_1008;
      *(undefined4 *)((int)aiStackY_1034 + iVar1) = 0x4fc02df9;
      memset(*(void **)((int)aiStackY_1034 + iVar1 + 4),*(int *)(&stack0xffffefd4 + iVar1),
             *(size_t *)(local_1008 + iVar1 + -0x20));
      *(_Hash<std::_Umap_traits<char_const_*,_iobuf_*,std::_Uhash_compare<char_const_*,std::hash<char_const_*>,std::equal_to<char_const_*>_>,std::allocator<std::pair<char_const_*_const,_iobuf_*>_>,0>_>
        **)((int)aiStackY_1034 + iVar1) = local_100c;
      *(int *)(auStackY_1038 + iVar1) = (int)&pp_Stack_1024 + iVar1;
      *(wchar_t **)((int)aiStackY_1050 + iVar1 + 0x14) = L"%slogs\\%S";
      *(undefined1 **)((int)aiStackY_1050 + iVar1 + 0x10) = local_1008;
      *(undefined4 *)((int)aiStackY_1050 + iVar1 + 0xc) = 0x4fc02e0b;
      swprintf_s<2048>(*(wchar_t (**) [2048])((int)aiStackY_1050 + iVar1 + 0x10),
                       *(wchar_t **)((int)aiStackY_1050 + iVar1 + 0x14));
      pwVar6 = L"a+";
      if (in_DL == '\0') {
        pwVar6 = L"w+";
      }
      *(undefined4 *)((int)aiStackY_1050 + iVar1 + 0xc) = 0x20;
      *(wchar_t **)((int)aiStackY_1050 + iVar1 + 8) = pwVar6;
      *(undefined1 **)((int)aiStackY_1050 + iVar1 + 4) = local_1008;
      *(undefined4 *)((int)aiStackY_1050 + iVar1) = 0x4fc02e27;
      pFVar7 = _wfsopen(*(wchar_t **)((int)aiStackY_1050 + iVar1 + 4),
                        *(wchar_t **)((int)aiStackY_1050 + iVar1 + 8),
                        *(int *)((int)aiStackY_1050 + iVar1 + 0xc));
      if (pFVar7 == (FILE *)0x0) {
        *(undefined1 **)(local_1008 + iVar1 + -0x20) = local_1008;
        *(char **)(&stack0xffffefd4 + iVar1) = "ERROR: Could not open File: \'%s\'";
        *(undefined4 *)((int)aiStackY_1034 + iVar1 + 4) = 0x4fc02e4e;
        FormatLogMessage(*(char **)(&stack0xffffefd4 + iVar1));
        return false;
      }
      *(_Hash<std::_Umap_traits<char_const_*,_iobuf_*,std::_Uhash_compare<char_const_*,std::hash<char_const_*>,std::equal_to<char_const_*>_>,std::allocator<std::pair<char_const_*_const,_iobuf_*>_>,0>_>
        ***)(local_1008 + iVar1 + -0x20) = &local_100c;
      *(undefined4 *)(&stack0xffffefd4 + iVar1) = 0x4fc02e39;
      pp_Var8 = std::
                unordered_map<char_const_*,_iobuf_*,std::hash<char_const_*>,std::equal_to<char_const_*>,std::allocator<std::pair<char_const_*_const,_iobuf_*>_>_>
                ::operator[](this,*(char ***)(local_1008 + iVar1 + -0x20));
      *pp_Var8 = (_iobuf *)pFVar7;
      return true;
    }
  }
  aiStackY_1034[1] = 0x4fc02e5d;
  FormatConsoleMessage
            ("ERROR: Invalid name format for File: \'%s\', \':\' or \'..\' not allowed.",
             (char *)local_100c);
  return false;
}


// ---------------------------------------------------------------------
// FormatFileMessage  @ 4fc02e7f  lines 940-952

bool __cdecl FormatFileMessage(char *Filename,bool Append,char *format)

{
  FILE *_File;
  bool bVar1;
  _iobuf **pp_Var2;
  ulong64 *puVar3;
  unordered_map<char_const_*,_iobuf_*,std::hash<char_const_*>,std::equal_to<char_const_*>,std::allocator<std::pair<char_const_*_const,_iobuf_*>_>_>
  *this;
  char *unaff_EBP;
  bool unaff_retaddr;
  FILE *pFVar4;
  char *pcVar5;
  undefined4 uVar6;
  undefined1 *puVar7;
  
  bVar1 = FileOpen(unaff_EBP,unaff_retaddr);
  if (bVar1) {
    pp_Var2 = std::
              unordered_map<char_const_*,_iobuf_*,std::hash<char_const_*>,std::equal_to<char_const_*>,std::allocator<std::pair<char_const_*_const,_iobuf_*>_>_>
              ::operator[](this,&Filename);
    _File = (FILE *)*pp_Var2;
    puVar7 = &stack0x00000010;
    uVar6 = 0;
    pFVar4 = _File;
    pcVar5 = format;
    puVar3 = __local_stdio_printf_options();
    __stdio_common_vfprintf
              ((int)*puVar3,*(undefined4 *)((int)puVar3 + 4),pFVar4,pcVar5,uVar6,puVar7);
    fputs("\n",_File);
    return true;
  }
  return false;
}


// ---------------------------------------------------------------------
// CloseOpenFiles  @ 4fc02ecf  lines 967-976

void __cdecl CloseOpenFiles(void)

{
  _List_iterator<std::_List_val<std::_List_simple_types<std::pair<char_const_*_const,_iobuf_*>_>_>_>
  _Var1;
  
  _Var1 = *(_List_iterator<std::_List_val<std::_List_simple_types<std::pair<char_const_*_const,_iobuf_*>_>_>_>
            *)FileNameMap._4_4_;
  if (_Var1 != (_List_iterator<std::_List_val<std::_List_simple_types<std::pair<char_const_*_const,_iobuf_*>_>_>_>
                )FileNameMap._4_4_) {
    do {
      if (*(int *)((int)_Var1 + 0xc) != 0) {
        fclose(*(FILE **)((int)_Var1 + 0xc));
      }
      _Var1 = std::
              _Hash<std::_Umap_traits<char_const_*,_iobuf_*,std::_Uhash_compare<char_const_*,std::hash<char_const_*>,std::equal_to<char_const_*>_>,std::allocator<std::pair<char_const_*_const,_iobuf_*>_>,0>_>
              ::
              erase<std::_List_iterator<std::_List_val<std::_List_simple_types<std::pair<char_const_*_const,_iobuf_*>_>_>_>,void>
                        ((_Hash<std::_Umap_traits<char_const_*,_iobuf_*,std::_Uhash_compare<char_const_*,std::hash<char_const_*>,std::equal_to<char_const_*>_>,std::allocator<std::pair<char_const_*_const,_iobuf_*>_>,0>_>
                          *)&FileNameMap,_Var1);
      _Var1 = *(_List_iterator<std::_List_val<std::_List_simple_types<std::pair<char_const_*_const,_iobuf_*>_>_>_>
                *)_Var1;
    } while (_Var1 != (_List_iterator<std::_List_val<std::_List_simple_types<std::pair<char_const_*_const,_iobuf_*>_>_>_>
                       )FileNameMap._4_4_);
  }
  return;
}


// ---------------------------------------------------------------------
// OpenLogFile  @ 4fc02f09  lines 987-1012

/* WARNING: Function: _chkstk replaced with injection: alloca_probe */
/* WARNING: Function: _alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Unable to track spacebase fully for stack */

bool __cdecl OpenLogFile(void)

{
  int iVar1;
  bool bVar2;
  undefined4 Time;
  undefined4 local_10b4;
  uint bufSize;
  tm LocalTimestamp;
  undefined1 outPath [4096];
  char FileName [64];
  char TimeStamp [64];
  uint local_8;
  
  local_8 = __security_cookie ^ (uint)&stack0xfffffffc;
  Time = 0;
  local_10b4 = 0;
  _time64((__time64_t *)&Time);
  _localtime64_s(&LocalTimestamp,(__time64_t *)&Time);
  memset(FileName,0,0x40);
  memset(TimeStamp,0,0x40);
  strftime(TimeStamp,0x40,"%Y-%m-%d %H.%M.%S %p.log",&LocalTimestamp);
  if (LogFileName[0] == '\0') {
    sprintf_s<64>(&FileName,"BZClassic_%s",TimeStamp);
  }
  else {
    sprintf_s<64>(&FileName,"%s_%s",LogFileName,TimeStamp);
  }
  bufSize = 0;
  GetOutputPath(&bufSize,(wchar_t *)0x0);
  iVar1 = bufSize * -2;
  *(undefined1 **)(&stack0xffffef3c + iVar1) = &stack0xffffef40 + iVar1;
  *(uint **)(&stack0xffffef38 + iVar1) = &bufSize;
  *(undefined4 *)(&stack0xffffef34 + iVar1) = 0x4fc02fef;
  bVar2 = GetOutputPath(*(uint **)(&stack0xffffef38 + iVar1),*(wchar_t **)(&stack0xffffef3c + iVar1)
                       );
  if (bVar2) {
    *(undefined4 *)(&stack0xffffef3c + iVar1) = 0x1000;
    *(undefined4 *)(&stack0xffffef38 + iVar1) = 0;
    *(undefined1 **)(&stack0xffffef34 + iVar1) = outPath;
    *(undefined4 *)(&stack0xffffef30 + iVar1) = 0x4fc03007;
    memset(*(void **)(&stack0xffffef34 + iVar1),*(int *)(&stack0xffffef38 + iVar1),
           *(size_t *)(&stack0xffffef3c + iVar1));
    *(char **)(&stack0xffffef30 + iVar1) = FileName;
    *(undefined1 **)(&stack0xffffef2c + iVar1) = &stack0xffffef40 + iVar1;
    *(wchar_t **)(&stack0xffffef28 + iVar1) = L"%slogs/%S";
    *(undefined1 **)(&stack0xffffef24 + iVar1) = outPath;
    *(undefined4 *)(&stack0xffffef20 + iVar1) = 0x4fc03020;
    swprintf_s<2048>(*(wchar_t (**) [2048])(&stack0xffffef24 + iVar1),
                     *(wchar_t **)(&stack0xffffef28 + iVar1));
    *(undefined4 *)(&stack0xffffef20 + iVar1) = 0x20;
    *(wchar_t **)(&stack0xffffef1c + iVar1) = L"a+";
    *(undefined1 **)(&stack0xffffef18 + iVar1) = outPath;
    *(undefined4 *)(&stack0xffffef14 + iVar1) = 0x4fc03034;
    LogFile = (_iobuf *)
              _wfsopen(*(wchar_t **)(&stack0xffffef18 + iVar1),
                       *(wchar_t **)(&stack0xffffef1c + iVar1),*(int *)(&stack0xffffef20 + iVar1));
  }
  return bVar2;
}


// ---------------------------------------------------------------------
// FormatLogMessage  @ 4fc03056  lines 1015-1049

/* WARNING: Function: _chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool __cdecl FormatLogMessage(char *format)

{
  ulong64 *puVar1;
  int iVar2;
  char *unaff_EDI;
  char *pcVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined1 *puVar7;
  undefined4 Time;
  undefined4 local_107c;
  tm LocalTimestamp;
  char Message [2048];
  char tempstr [2048];
  char TimeStamp [68];
  uint local_c;
  undefined4 uStack_8;
  
  uStack_8 = 0x4fc03063;
  local_c = __security_cookie ^ (uint)&stack0xfffffffc;
  memset(tempstr,0,0x800);
  puVar7 = &stack0x00000008;
  uVar6 = 0;
  pcVar3 = tempstr;
  uVar5 = 0xffffffff;
  uVar4 = 0x800;
  puVar1 = __local_stdio_printf_options();
  __stdio_common_vsnprintf_s
            ((int)*puVar1,*(undefined4 *)((int)puVar1 + 4),pcVar3,uVar4,uVar5,format,uVar6,puVar7);
  Time = 0;
  local_107c = 0;
  _time64((__time64_t *)&Time);
  _localtime64_s(&LocalTimestamp,(__time64_t *)&Time);
  memset(TimeStamp,0,0x40);
  strftime(TimeStamp,0x40,"%H:%M:%S",&LocalTimestamp);
  if ((LogFile == (_iobuf *)0x0) && (OpenLogFile(), LogFile == (_iobuf *)0x0)) {
    memset(Message,0,0x800);
    sprintf_s<2048>(&Message,"ERROR: Unable to open Log File! Reporting: \'%s\'",tempstr);
    FormatConsoleMessage(Message);
    return false;
  }
  fprintf(LogFile,"%s | %f \t| %s\n",TimeStamp,
          (double)CONCAT44(tempstr,(int)((ulonglong)(double)misnImport.time >> 0x20)),unaff_EDI);
  iVar2 = GetVarItemInt("network.session.ivar115");
  if ((iVar2 != 0) || (iVar2 = GetVarItemInt("network.session.civar5"), iVar2 != 0)) {
    FormatConsoleMessage(tempstr);
  }
  return true;
}


// ---------------------------------------------------------------------
// FormatToMessagesBox  @ 4fc031ab  lines 1080-1088

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __cdecl FormatToMessagesBox(char *format,ulong color)

{
  char *pcVar1;
  ulong64 *puVar2;
  char *pcVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined1 *puVar7;
  char tempstr [2048];
  uint local_8;
  
  local_8 = __security_cookie ^ (uint)&stack0xfffffffc;
  pcVar1 = FormatFromFile(format);
  memset(tempstr,0,0x800);
  puVar7 = &stack0x0000000c;
  uVar6 = 0;
  uVar5 = 0xffffffff;
  pcVar3 = tempstr;
  uVar4 = 0x800;
  puVar2 = __local_stdio_printf_options();
  __stdio_common_vsnprintf_s
            ((int)*puVar2,*(undefined4 *)((int)puVar2 + 4),pcVar3,uVar4,uVar5,pcVar1,uVar6,puVar7);
  AddToMessagesBox2(tempstr,color);
  return;
}


// ---------------------------------------------------------------------
// FormatFromFile  @ 4fc03223  lines 1142-1180

char * __cdecl FormatFromFile(char *formatsource)

{
  char cVar1;
  int iVar2;
  char *_Dst;
  char *_Src;
  char *pcVar3;
  char *bufSize;
  
  pcVar3 = formatsource;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  bufSize = formatsource;
  if ((uint)((int)pcVar3 - (int)(formatsource + 1)) < 0x41) {
    pcVar3 = formatsource + (((int)pcVar3 - (int)(formatsource + 1)) - 4);
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
              if (iVar2 != 0) goto LAB_4fc032d6;
            }
          }
        }
      }
    }
    bufSize = (char *)0x0;
    LoadFile(formatsource,(void *)0x0,(uint *)&bufSize);
    _Dst = malloc((size_t)(bufSize + 1));
    LoadFile(formatsource,_Dst,(uint *)&bufSize);
    _Dst[(int)bufSize] = '\0';
  }
  else {
LAB_4fc032d6:
    _Src = GetBZCCLocalizedString("mission",formatsource);
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
// IsObjectFacingObject  @ 4fc03311  lines 1278-1286

bool __cdecl IsObjectFacingObject(int h1,int h2,float ConeAngle)

{
  bool bVar1;
  float10 fVar2;
  float fVar3;
  Matrix PositionB;
  Matrix PositionA;
  double local_20;
  double local_18;
  float local_c;
  
  bVar1 = IsAround(h1);
  if ((bVar1) && (bVar1 = IsAround(h2), bVar1)) {
    GetPosition(h1,&PositionA);
    GetPosition(h2,&PositionB);
    local_c = (PositionA.posit.z - PositionB.posit.z) * (PositionA.posit.z - PositionB.posit.z) +
              (PositionA.posit.x - PositionB.posit.x) * (PositionA.posit.x - PositionB.posit.x);
    local_20 = (double)((PositionB.posit.x - PositionA.posit.x) * PositionA.front.x +
                       PositionA.front.z * (PositionB.posit.z - PositionA.posit.z));
    fVar3 = portable_cos(ConeAngle);
    local_18 = (double)fVar3;
    fVar2 = (float10)__CIsqrt();
    if ((float)fVar2 * (float)local_18 < (float)local_20) {
      return true;
    }
  }
  return false;
}


// ---------------------------------------------------------------------
// GetVectorFromPath  @ 4fc033be  lines 1379-1399

/* WARNING: Function: _alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Unable to track spacebase fully for stack */

Vector * __cdecl GetVectorFromPath(Vector *__return_storage_ptr__,char *param_1,int param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  uint uVar4;
  bool bVar5;
  Vector *in_ECX;
  undefined4 extraout_ECX;
  char *in_EDX;
  float fVar6;
  undefined4 uStackY_38;
  uint bufSize;
  uint local_8;
  
  local_8 = __security_cookie ^ (uint)&stack0xfffffffc;
  bufSize = 0;
  in_ECX->x = 0.0;
  in_ECX->y = 0.0;
  in_ECX->z = 0.0;
  if (in_EDX != (char *)0x0) {
    uStackY_38 = 0x4fc033f7;
    GetPathPoints(in_EDX,&bufSize,(float *)0x0);
    uVar4 = bufSize;
    if ((bufSize != 0) && ((int)__return_storage_ptr__ < (int)bufSize)) {
      iVar3 = bufSize * -8;
      *(undefined1 **)(&stack0xffffffd4 + iVar3) = &stack0xffffffd8 + iVar3;
      *(uint **)(&stack0xffffffd0 + iVar3) = &bufSize;
      *(char **)(&stack0xffffffcc + iVar3) = in_EDX;
      (&uStackY_38)[uVar4 * -2] = 0x4fc0341b;
      bVar5 = GetPathPoints(*(char **)(&stack0xffffffcc + iVar3),
                            *(uint **)(&stack0xffffffd0 + iVar3),
                            *(float **)(&stack0xffffffd4 + iVar3));
      if (bVar5) {
        *(undefined4 *)(&stack0xffffffd4 + iVar3) = extraout_ECX;
        *(undefined4 *)(&stack0xffffffd0 + iVar3) = extraout_ECX;
        fVar1 = *(float *)(&stack0xffffffd8 + (int)__return_storage_ptr__ * 8 + iVar3);
        *(undefined4 *)(&stack0xffffffd4 + iVar3) =
             *(undefined4 *)(&stack0xffffffdc + (int)__return_storage_ptr__ * 8 + iVar3);
        *(float *)(&stack0xffffffd0 + iVar3) = fVar1;
        *(undefined4 *)(&stack0xffffffcc + iVar3) = 0x4fc0344d;
        fVar6 = TerrainFindFloor(*(float *)(&stack0xffffffd0 + iVar3),
                                 *(float *)(&stack0xffffffd4 + iVar3));
        fVar2 = *(float *)(&stack0xffffffdc + (int)__return_storage_ptr__ * 8 + iVar3);
        in_ECX->x = fVar1;
        in_ECX->y = fVar6;
        in_ECX->z = fVar2;
      }
    }
  }
  return in_ECX;
}


// ---------------------------------------------------------------------
// GetCenterOfMap  @ 4fc03479  lines 1403-1437

/* WARNING: Function: _alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Unable to track spacebase fully for stack */

Vector * __cdecl GetCenterOfMap(Vector *__return_storage_ptr__)

{
  int iVar1;
  float fVar2;
  bool bVar3;
  Vector *in_ECX;
  uint extraout_ECX;
  uint uVar4;
  uint uVar5;
  float fVar6;
  undefined4 uStackY_54;
  float EdgePoints;
  float local_30;
  float local_2c;
  float local_28;
  float maxVal;
  float local_20;
  float minVal;
  float local_18;
  uint bufSize;
  float local_c;
  uint local_8;
  
  local_8 = __security_cookie ^ (uint)&stack0xfffffffc;
  uVar5 = 0;
  in_ECX->x = 0.0;
  in_ECX->y = 0.0;
  in_ECX->z = 0.0;
  bufSize = 0;
  EdgePoints = 0.0;
  local_30 = 0.0;
  local_2c = 0.0;
  local_28 = 0.0;
  uStackY_54 = 0x4fc034bc;
  GetPathPoints("edge_path",&bufSize,(float *)0x0);
  uVar4 = bufSize;
  iVar1 = bufSize * -8;
  *(undefined1 **)(&stack0xffffffb8 + iVar1) = &stack0xffffffbc + iVar1;
  *(uint **)(&stack0xffffffb4 + iVar1) = &bufSize;
  *(char **)(&stack0xffffffb0 + iVar1) = "edge_path";
  (&uStackY_54)[uVar4 * -2] = 0x4fc034d8;
  bVar3 = GetPathPoints(*(char **)(&stack0xffffffb0 + iVar1),*(uint **)(&stack0xffffffb4 + iVar1),
                        *(float **)(&stack0xffffffb8 + iVar1));
  uVar4 = extraout_ECX;
  if ((bVar3) && (uVar4 = bufSize, 1 < bufSize)) {
    minVal = 3.4028235e+38;
    local_18 = 3.4028235e+38;
    maxVal = -3.4028235e+38;
    local_20 = -3.4028235e+38;
    if (bufSize != 0) {
      do {
        fVar6 = *(float *)(&stack0xffffffbc + uVar5 * 8 + iVar1);
        local_c = fVar6;
        if (fVar6 < minVal) {
          minVal = fVar6;
        }
        local_c = *(float *)(&stack0xffffffc0 + uVar5 * 8 + iVar1);
        if (local_c < local_18) {
          local_18 = local_c;
        }
        if (maxVal < fVar6) {
          maxVal = fVar6;
        }
        if (local_20 < local_c) {
          local_20 = local_c;
        }
        uVar5 = uVar5 + 1;
      } while (uVar5 < bufSize);
    }
    EdgePoints = minVal;
    local_30 = local_18;
    local_2c = maxVal;
    local_28 = local_20;
  }
  *(uint *)(&stack0xffffffb8 + iVar1) = uVar4;
  *(uint *)(&stack0xffffffb4 + iVar1) = uVar4;
  fVar6 = (EdgePoints + local_2c) * 0.5;
  local_c = fVar6;
  in_ECX->x = fVar6;
  fVar2 = (local_30 + local_28) * 0.5;
  in_ECX->z = fVar2;
  *(float *)(&stack0xffffffb8 + iVar1) = fVar2;
  *(float *)(&stack0xffffffb4 + iVar1) = fVar6;
  *(undefined4 *)(&stack0xffffffb0 + iVar1) = 0x4fc035be;
  fVar6 = TerrainFindFloor(*(float *)(&stack0xffffffb4 + iVar1),*(float *)(&stack0xffffffb8 + iVar1)
                          );
  in_ECX->y = fVar6;
  return in_ECX;
}


// ---------------------------------------------------------------------
// GetRandomTeam  @ 4fc035d7  lines 1441-1475

int __cdecl GetRandomTeam(int param_1,int param_2,bool param_3,bool param_4)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int in_EDX;
  int Team1;
  
  iVar2 = GetRandomInt(0,0xf);
  Team1 = iVar2;
  do {
    if ((((in_EDX < 0) || (bVar1 = TeamFilterCheck(4,Team1,in_EDX), bVar1)) &&
        ((((char)param_1 == '\0' ||
          ((((iVar3 = GetPlayerHandle(Team1), iVar3 != 0 ||
             (iVar3 = GetObjectByTeamSlot(Team1,1), iVar3 != 0)) ||
            (iVar3 = GetObjectByTeamSlot(Team1,2), iVar3 != 0)) ||
           ((iVar3 = GetObjectByTeamSlot(Team1,3), iVar3 != 0 ||
            (iVar3 = GetObjectByTeamSlot(Team1,9), iVar3 != 0)))))) ||
         ((iVar3 = GetObjectByTeamSlot(Team1,10), iVar3 != 0 ||
          (((iVar3 = GetObjectByTeamSlot(Team1,0xb), iVar3 != 0 ||
            (iVar3 = GetObjectByTeamSlot(Team1,0xc), iVar3 != 0)) ||
           ((iVar3 = GetObjectByTeamSlot(Team1,0xd), iVar3 != 0 ||
            (iVar3 = GetObjectByTeamSlot(Team1,0xe), iVar3 != 0)))))))))) && (0 < Team1)) {
      return Team1;
    }
    iVar3 = Team1 + 1;
    Team1 = 0;
    if (iVar3 < 0x10) {
      Team1 = iVar3;
    }
  } while (Team1 != iVar2);
  return -1;
}


// ---------------------------------------------------------------------
// GetWindingNumber  @ 4fc0369e  lines 1480-1503

int __cdecl GetWindingNumber(vector<VECTOR_2D,std::allocator<VECTOR_2D>_> *areaPath,Vector *vector)

{
  int iVar1;
  int iVar2;
  int extraout_EAX;
  int extraout_EAX_00;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  float10 fVar7;
  float10 fVar8;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  
  iVar1 = *(int *)areaPath;
  iVar5 = 0;
  iVar6 = *(int *)&areaPath->field_0x4 - iVar1 >> 3;
  iVar2 = 1;
  iVar4 = 0;
  if (0 < iVar6) {
    fVar7 = (float10)vector->z;
    do {
      iVar3 = 0;
      if (iVar2 < iVar6) {
        iVar3 = iVar2;
      }
      fVar8 = (float10)*(float *)(iVar1 + 4 + iVar3 * 8);
      if (fVar7 < (float10)*(float *)(iVar1 + 4 + iVar4 * 8)) {
        if ((fVar8 <= fVar7) && (_ftol2_sse(), fVar7 = extraout_ST0_00, extraout_EAX_00 < 0)) {
          iVar5 = iVar5 + -1;
        }
      }
      else if ((fVar7 < fVar8) && (_ftol2_sse(), fVar7 = extraout_ST0, 0 < extraout_EAX)) {
        iVar5 = iVar5 + 1;
      }
      iVar4 = iVar4 + 1;
      iVar2 = iVar3 + 1;
    } while (iVar4 < iVar6);
  }
  return iVar5;
}


// ---------------------------------------------------------------------
// GetWindingNumber  @ 4fc03774  lines 1507-1534

/* WARNING: Function: _alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Unable to track spacebase fully for stack */

int __cdecl GetWindingNumber(char *path,Vector vector)

{
  int iVar1;
  bool bVar2;
  undefined4 *puVar3;
  int iVar4;
  uint uVar5;
  void *_Ptr;
  void *pvVar6;
  void *pvVar7;
  undefined4 uStackY_48;
  undefined4 newPoint;
  undefined4 local_20;
  void *areaPath;
  void *local_18;
  void *local_14;
  uint bufSize;
  uint local_c;
  
  local_c = __security_cookie ^ (uint)&stack0xfffffffc;
  _Ptr = (void *)0x0;
  bufSize = 0;
  if (path != (char *)0x0) {
    uStackY_48 = 0x4fc037a2;
    GetPathPoints(path,&bufSize,(float *)0x0);
    uVar5 = bufSize;
    if (bufSize != 0) {
      pvVar7 = (void *)0x0;
      areaPath = (void *)0x0;
      local_14 = (void *)0x0;
      local_18 = (void *)0x0;
      iVar1 = bufSize * -8;
      *(undefined1 **)(&stack0xffffffc4 + iVar1) = &stack0xffffffc8 + iVar1;
      *(uint **)(&stack0xffffffc0 + iVar1) = &bufSize;
      *(char **)(&stack0xffffffbc + iVar1) = path;
      (&uStackY_48)[uVar5 * -2] = 0x4fc037d4;
      bVar2 = GetPathPoints(*(char **)(&stack0xffffffbc + iVar1),
                            *(uint **)(&stack0xffffffc0 + iVar1),
                            *(float **)(&stack0xffffffc4 + iVar1));
      if ((bVar2) && (uVar5 = 0, pvVar6 = _Ptr, bufSize != 0)) {
        do {
          newPoint = *(undefined4 *)(&stack0xffffffc8 + uVar5 * 8 + iVar1);
          local_20 = *(undefined4 *)(&stack0xffffffcc + uVar5 * 8 + iVar1);
          if (pvVar7 == pvVar6) {
            *(undefined4 **)(&stack0xffffffc4 + iVar1) = &newPoint;
            *(void **)(&stack0xffffffc0 + iVar1) = pvVar6;
            *(undefined4 *)(&stack0xffffffbc + iVar1) = 0x4fc03825;
            std::vector<VECTOR_2D,std::allocator<VECTOR_2D>_>::
            _Emplace_reallocate<VECTOR_2D_const_&>
                      ((vector<VECTOR_2D,std::allocator<VECTOR_2D>_> *)&areaPath,
                       *(VECTOR_2D **)(&stack0xffffffc0 + iVar1),
                       *(VECTOR_2D **)(&stack0xffffffc4 + iVar1));
            pvVar7 = local_14;
          }
          else {
            *(undefined4 *)(&stack0xffffffc4 + iVar1) = 0x4fc03805;
            puVar3 = operator_new(*(uint *)(&stack0xffffffc8 + iVar1),
                                  *(void **)(&stack0xffffffcc + iVar1));
            local_18 = (void *)((int)pvVar6 + 8);
            *puVar3 = newPoint;
            puVar3[1] = local_20;
          }
          uVar5 = uVar5 + 1;
          _Ptr = areaPath;
          pvVar6 = local_18;
        } while (uVar5 < bufSize);
      }
      *(undefined4 *)(&stack0xffffffc4 + iVar1) = 0x4fc0383f;
      iVar4 = GetWindingNumber((vector<VECTOR_2D,std::allocator<VECTOR_2D>_> *)&areaPath,&vector);
      if (_Ptr == (void *)0x0) {
        return iVar4;
      }
      *(undefined4 *)(&stack0xffffffc4 + iVar1) = 0x4fc03853;
      std::_Deallocate<8,0>(_Ptr,(int)pvVar7 - (int)_Ptr & 0xfffffff8);
      return iVar4;
    }
  }
  return 0;
}


// ---------------------------------------------------------------------
// DoesPathExist  @ 4fc0386b  lines 1565-1571

int __cdecl DoesPathExist(char *path)

{
  uint uVar1;
  uint bufSize;
  
  bufSize = 0;
  uVar1 = 0;
  if (path != (char *)0x0) {
    GetPathPoints(path,&bufSize,(float *)0x0);
    uVar1 = bufSize;
  }
  return uVar1;
}


// ---------------------------------------------------------------------
// SetAmmo  @ 4fc0388c  lines 1661-1671

void __cdecl SetAmmo(int h,float Percent)

{
  long lVar1;
  long extraout_EAX;
  
  lVar1 = GetMaxAmmo(h);
  if (lVar1 != -0x4d2) {
    _ftol2_sse();
    SetCurAmmo(h,extraout_EAX);
  }
  return;
}


// ---------------------------------------------------------------------
// GiveWeapon  @ 4fc038ee  lines 1675-1753

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool __cdecl GiveWeapon(int h,char *Weapon,int Slot)

{
  bool bVar1;
  int iVar2;
  char *pcVar3;
  float fVar4;
  undefined1 uStack_220;
  bool local_21f;
  bool local_21e;
  bool local_21d;
  float local_21c [5];
  char local_208 [64];
  char local_1c8 [64];
  char local_188 [64];
  char local_148 [324];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)&uStack_220;
  if (*Weapon == '\0') {
    GiveWeapon(h,Slot,Weapon);
    bVar1 = true;
  }
  else {
    bVar1 = DoesODFExist(Weapon);
    if (bVar1) {
      local_21c[0] = 0.0;
      local_21c[1] = 0.0;
      local_21c[2] = 0.0;
      local_21c[3] = 0.0;
      local_21c[4] = 0.0;
      memset(local_148,0,0x140);
      local_21f = false;
      memset(local_208,0,0x40);
      CombineStrings(local_208,"",Weapon,0x40);
      memset(local_188,0,0x40);
      sprintf_s<64>(&local_188,"weaponAssault%d",Slot + 1);
      GetODFBool(h,"GameObjectClass",local_188,&local_21f,false);
      if (local_21f != false) {
        local_21e = false;
        GetODFBool(Weapon,(char *)0x0,"WeaponClass","isAssault",&local_21e,false);
        if (local_21e == false) {
          memset(local_1c8,0,0x40);
          iVar2 = GetODFString(Weapon,(char *)0x0,"WeaponClass","altName",0x40,local_1c8,(char *)0x0
                              );
          if (iVar2 != 0) {
            local_21d = false;
            GetODFBool(local_1c8,(char *)0x0,"WeaponClass","isAssault",&local_21d,false);
            if (local_21d != false) {
              CombineStrings(local_208,"",local_1c8,0x40);
            }
          }
        }
      }
      iVar2 = 0;
      pcVar3 = local_148;
      do {
        bVar1 = GetObjInfo(h,iVar2 + Get_Weapon0Config,pcVar3);
        if (!bVar1) goto LAB_4fc03933;
        fVar4 = GetCurLocalAmmo(h,iVar2);
        local_21c[iVar2] = fVar4;
        iVar2 = iVar2 + 1;
        pcVar3 = pcVar3 + 0x40;
      } while (iVar2 < 5);
      iVar2 = _stricmp(local_148 + Slot * 0x40,local_208);
      if (iVar2 != 0) {
        local_21c[Slot] = 0.0;
        CombineStrings(local_148 + Slot * 0x40,"",local_208,0x40);
        bVar1 = ReplaceWeapons(h,(char (*) [64])local_148,local_21c,(char *)0x0);
        return bVar1;
      }
    }
    else {
      FormatLogMessage("ERROR: Weapon ODF \'%s\' doesn\'t exist! Fix DLL\'s GiveWeapon() call!",
                       Weapon);
    }
LAB_4fc03933:
    bVar1 = false;
  }
  return bVar1;
}


// ---------------------------------------------------------------------
// GetObjectByBaseSlot  @ 4fc03b28  lines 1795-1807

int __cdecl GetObjectByBaseSlot(int Team,int Slot)

{
  int iVar1;
  
  if ((Slot - 1U < 9) && ((uint)Team < 0x10)) {
    iVar1 = Slot + 5;
    if (Slot < 4) {
      iVar1 = Slot;
    }
    iVar1 = GetObjectByTeamSlot(Team,iVar1);
    return iVar1;
  }
  return 0;
}


// ---------------------------------------------------------------------
// GetTapCount  @ 4fc03b4c  lines 1811-1832

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
        if (lVar2 < 1) goto LAB_4fc03b77;
      }
      iVar3 = iVar3 + 1;
    }
LAB_4fc03b77:
    iVar4 = iVar4 + 1;
    if (7 < iVar4) {
      return iVar3;
    }
  } while( true );
}


// ---------------------------------------------------------------------
// GetTapCount  @ 4fc03b84  lines 1836-1864

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl GetTapCount(char *filename1,char *filename2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined1 auStack_88 [3];
  bool local_85;
  char local_84 [64];
  char local_44 [64];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)auStack_88;
  iVar4 = 0;
  bVar1 = IsBuilding(filename1);
  if (bVar1) {
    local_85 = true;
    iVar2 = GetODFBool(filename1,filename2,"PoweredBuildingClass","PoweredByTaps",&local_85,true);
    if (iVar2 == 0) {
      GetODFBool(filename1,filename2,"TurretCraftClass","PoweredByTaps",&local_85,true);
    }
    if (local_85 != false) {
      iVar2 = 0;
      do {
        memset(local_84,0,0x40);
        memset(local_44,0,0x40);
        iVar2 = iVar2 + 1;
        sprintf_s<64>(&local_84,"powerTap%d",iVar2);
        iVar3 = GetODFString(filename1,filename2,"PoweredBuildingClass",local_84,0x40,local_44,
                             (char *)0x0);
        if ((iVar3 != 0) ||
           (iVar3 = GetODFString(filename1,filename2,"TurretCraftClass",local_84,0x40,local_44,
                                 (char *)0x0), iVar3 != 0)) {
          iVar4 = iVar4 + 1;
        }
      } while (iVar2 < 8);
    }
  }
  return iVar4;
}


// ---------------------------------------------------------------------
// SetRandomHeadingAngle2  @ 4fc03c8b  lines 1870-1875

void __cdecl SetRandomHeadingAngle2(int h)

{
  Vector VVar1;
  Vector *unaff_ESI;
  float unaff_EDI;
  Matrix *__return_storage_ptr__;
  Matrix M;
  Vector local_10;
  
  local_10.x = 0.0;
  local_10.y = 0.0;
  local_10.z = 0.0;
  __return_storage_ptr__ = (Matrix *)GetRandomFloat(6.2831855);
  Build_Yaw_Matrix(__return_storage_ptr__,unaff_EDI,unaff_ESI);
  GetPosition(h,&local_10);
  M.posit.x = local_10.x;
  M.posit.y = local_10.y;
  M.posit.z = local_10.z;
  SetPosition(h,&M);
  VVar1.y = M.posit.y;
  VVar1.x = M.posit.x;
  VVar1.z = M.posit.z;
  SetVectorPosition(h,VVar1);
  return;
}


// ---------------------------------------------------------------------
// TeamFilterCheck  @ 4fc03cf8  lines 1879-1887

bool __cdecl TeamFilterCheck(int TeamFilter,int Team1,int Team2)

{
  bool bVar1;
  
  if ((((uint)Team1 < 0x10) && ((uint)Team2 < 0x10)) &&
     ((((TeamFilter & 1U) != 0 && (Team1 == Team2)) ||
      ((Team1 != Team2 &&
       ((((TeamFilter & 2U) != 0 && (bVar1 = IsTeamAllied(Team1,Team2), bVar1)) ||
        (((TeamFilter & 4U) != 0 && (bVar1 = IsTeamAllied(Team1,Team2), !bVar1)))))))))) {
    return true;
  }
  return false;
}


// ---------------------------------------------------------------------
// GetEngageRange  @ 4fc03d4a  lines 1956-2005

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

float __cdecl GetEngageRange(int h)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  float local_d4;
  float local_d0;
  float local_cc;
  float local_c8;
  char local_c4 [64];
  char local_84 [64];
  char local_44 [64];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)&local_d4;
  bVar1 = IsAround(h);
  local_d4 = 0.0;
  if (bVar1) {
    local_d4 = 0.0;
    iVar2 = GetODFFloat(h,"CraftClass","EngageRange",&local_d4,0.0);
    if ((iVar2 == 0) &&
       (iVar2 = GetODFFloat(h,"CraftClass","RangeScan",&local_d4,200.0), iVar2 == 0)) {
      memset(local_c4,0,0x40);
      memset(local_84,0,0x40);
      memset(local_44,0,0x40);
      iVar2 = 0;
      do {
        local_d0 = 0.0;
        iVar2 = iVar2 + 1;
        sprintf_s<64>(&local_44,"weaponName%d",iVar2);
        iVar3 = GetODFString(h,"GameObjectClass",local_44,0x40,local_c4,(char *)0x0);
        if ((iVar3 != 0) && (local_c4[0] != '\0')) {
          CombineStrings(local_c4,local_c4,".odf",0x40);
          bVar1 = OpenODF2(local_c4);
          if ((bVar1) &&
             ((iVar3 = GetODFFloat(local_c4,(char *)0x0,"WeaponClass","aiRange",&local_d0,0.0),
              iVar3 == 0 &&
              (iVar3 = GetODFString(local_c4,(char *)0x0,"WeaponClass","ordName",0x40,local_84,
                                    (char *)0x0), iVar3 != 0)))) {
            CombineStrings(local_84,local_84,".odf",0x40);
            bVar1 = OpenODF2(local_84);
            if (bVar1) {
              local_c8 = 0.0;
              local_cc = 0.0;
              GetODFFloat(local_84,(char *)0x0,"OrdnanceClass","shotSpeed",&local_c8,0.0);
              GetODFFloat(local_84,(char *)0x0,"OrdnanceClass","lifeSpan",&local_cc,0.0);
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
// GetMinFireAmmo  @ 4fc03f6f  lines 2009-2074

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

long __cdecl GetMinFireAmmo(int h)

{
  bool bVar1;
  long lVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  long local_110;
  char local_10c [8];
  byte local_104 [64];
  char local_c4 [64];
  char local_84 [64];
  char local_44 [64];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)&local_110;
  bVar1 = IsAround(h);
  if (bVar1) {
    iVar4 = 0;
    local_10c[0] = '\0';
    local_10c[1] = '\0';
    local_10c[2] = '\0';
    local_10c[3] = '\0';
    local_10c[4] = '\0';
    local_10c[5] = '\0';
    lVar2 = 0;
    GetODFString(h,"GameObjectClass","weaponMask",6,local_10c,"11111");
    pcVar5 = local_10c + 4;
    do {
      if (*pcVar5 != '0') {
        memset(local_c4,0,0x40);
        GetObjInfo(h,iVar4 + Get_Weapon0ODF,local_c4);
        if ((local_c4[0] != '\0') && (bVar1 = OpenODF2(local_c4), bVar1)) {
          memset(local_104,0,0x40);
          memset(local_44,0,0x40);
          iVar3 = GetODFString(local_c4,"GameObjectClass","classlabel",0x40,local_44,(char *)0x0);
          if (iVar3 != 0) {
            CombineStrings((char *)local_104,local_44,".odf",0x40);
            bVar1 = OpenODF2((char *)local_104);
            local_104[0] = local_104[0] & -bVar1;
          }
          memset(local_84,0,0x40);
          iVar3 = GetODFString(local_c4,(char *)local_104,"WeaponClass","ordName",0x40,local_84,
                               (char *)0x0);
          if ((iVar3 == 0) &&
             (iVar3 = GetODFString(local_c4,(char *)local_104,"DispenserClass","objectClass",0x40,
                                   local_84,(char *)0x0), iVar3 == 0)) {
            GetODFString(local_c4,(char *)local_104,"TorpedoLauncherClass","objectClass",0x40,
                         local_84,(char *)0x0);
          }
          if (local_84[0] != '\0') {
            CombineStrings(local_84,local_84,".odf",0x40);
            local_110 = 0;
            iVar3 = GetODFLong(local_84,(char *)0x0,"OrdnanceClass","ammoCost",&local_110,0);
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
// GetOrdnanceDamageDealt  @ 4fc04185  lines 2078-2209

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

long __cdecl GetOrdnanceDamageDealt(int h,char *OrdnanceODF,bool UseExplosion)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
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
  local_18c = OrdnanceODF;
  bVar1 = IsAround(h);
  if (bVar1) {
    memset(local_c4,0,0x40);
    memset(local_144,0,0x40);
    local_18e = '\0';
    GetODFChar(h,"GameObjectClass","armorClass",&local_18e,'N');
    iVar2 = toupper((int)local_18e);
    iVar4 = 0;
    do {
      memset(local_104,0,0x40);
      GetObjInfo(h,iVar4 + Get_Weapon0GOClass,local_104);
      iVar3 = _stricmp(local_104,"CLASS_SHIELDUP");
      if (iVar3 == 0) {
        memset(local_184,0,0x40);
        GetObjInfo(h,iVar4 + Get_Weapon0ODF,local_184);
        local_18d = '\0';
        GetODFChar(local_184,(char *)0x0,"ShieldUpgradeClass","shieldClass",&local_18d,'S');
        iVar4 = toupper((int)local_18d);
        goto LAB_4fc0429a;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < 5);
    iVar4 = 0;
LAB_4fc0429a:
    memset(local_84,0,0x40);
    CombineStrings(local_c4,"",local_18c,0x40);
    bVar1 = OpenODF2(local_c4);
    local_188 = (char *)0x0;
    if (bVar1) {
      memset(local_44,0,0x40);
      iVar3 = GetODFString(local_c4,"OrdnanceClass","classlabel",0x40,local_44,(char *)0x0);
      if (iVar3 != 0) {
        CombineStrings((char *)local_144,local_44,".odf",0x40);
        bVar1 = OpenODF2((char *)local_144);
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
        pcVar5 = "damageValue(A)";
      }
      else if (iVar2 == 0x44) {
        pcVar5 = "damageValue(D)";
      }
      else if (iVar2 == 0x48) {
        pcVar5 = "damageValue(H)";
      }
      else if (iVar2 == 0x4c) {
        pcVar5 = "damageValue(L)";
      }
      else if (iVar2 == 0x53) {
        pcVar5 = "damageValue(S)";
      }
      else {
        pcVar5 = "damageValue(N)";
      }
      strcpy_s(local_184,0x40,pcVar5);
      GetODFInt(local_c4,(char *)local_144,"OrdnanceClass",local_184,(int *)&local_188,0);
      if (UseExplosion) {
        bVar1 = IsBuilding(h);
        if (bVar1) {
          pcVar5 = "xplBuilding";
        }
        else {
          pcVar5 = "xplVehicle";
        }
        strcpy_s(local_104,0x40,pcVar5);
        iVar2 = GetODFString(local_c4,(char *)local_144,"OrdnanceClass",local_104,0x40,local_84,
                             (char *)0x0);
        if (iVar2 != 0) {
          CombineStrings(local_84,local_84,".odf",0x40);
          bVar1 = OpenODF2(local_84);
          if (bVar1) {
            GetODFInt(local_84,(char *)0x0,"ExplosionClass",local_184,(int *)&local_18c,0);
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
// GetODFPositionOffset  @ 4fc044ba  lines 2264-2284

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

Matrix * __cdecl
GetODFPositionOffset
          (Matrix *__return_storage_ptr__,int param_1,int param_2,Vector param_3,Vector param_4)

{
  bool bVar1;
  Matrix *in_ECX;
  Matrix *extraout_ECX;
  int iVar2;
  int in_EDX;
  undefined1 *fmtarg1;
  Vector *unaff_ESI;
  Matrix *pMVar3;
  float unaff_EDI;
  Matrix *pMVar4;
  Matrix *local_f0;
  Matrix *local_ec;
  float local_e8;
  Vector local_e4;
  int local_d8;
  Vector local_d4;
  Matrix local_c8 [2];
  char local_48 [68];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)&local_f0;
  local_d8 = in_EDX;
  bVar1 = IsAround(in_EDX);
  if (bVar1) {
    local_d4.x = 0.0;
    local_d4.y = 0.0;
    local_d4.z = 0.0;
    memset(local_48,0,0x40);
    fmtarg1 = (undefined1 *)((int)&(__return_storage_ptr__->right).x + 1);
    sprintf_s<64>((char (*) [64])local_48,"PositionOffset%d",(int)fmtarg1);
    local_f0 = (Matrix *)0x0;
    local_ec = (Matrix *)0x0;
    local_e8 = 0.0;
    GetODFVector(local_d8,"GameObjectClass",local_48,&local_d4,(Vector)ZEXT812(0));
    local_f0 = (Matrix *)((float)param_1 + local_d4.x);
    local_e4.x = 0.0;
    local_e4.y = 0.0;
    local_e4.z = 0.0;
    local_ec = (Matrix *)((float)param_2 + local_d4.y);
    local_e8 = param_3.x + local_d4.z;
    local_d4.x = (float)local_f0;
    local_d4.y = (float)local_ec;
    local_d4.z = local_e8;
    sprintf_s<64>((char (*) [64])local_48,"RotationOffset%d",(int)fmtarg1);
    local_f0 = (Matrix *)0x0;
    local_ec = (Matrix *)0x0;
    local_e8 = 0.0;
    GetODFVector(local_d8,"GameObjectClass",local_48,&local_e4,(Vector)ZEXT812(0));
    local_f0 = (Matrix *)((param_3.y + local_e4.x) * 0.017453292);
    local_ec = (Matrix *)((param_3.z + local_e4.y) * 0.017453292);
    local_e8 = (param_4.x + local_e4.z) * 0.017453292;
    local_e4.x = (float)local_f0;
    local_e4.y = (float)local_ec;
    local_e4.z = local_e8;
    GetPosition(local_d8,local_c8);
    pMVar3 = (Matrix *)local_e4.x;
    pMVar4 = (Matrix *)local_e4.y;
    Build_Position_Rotation_Matrix((Matrix *)local_e4.x,local_e4.y,local_e4.z,unaff_EDI,unaff_ESI);
    Matrix_Multiply(local_c8,pMVar3,pMVar4);
    pMVar3 = extraout_ECX;
  }
  else {
    pMVar3 = &Identity_Matrix;
  }
  pMVar4 = in_ECX;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    (pMVar4->right).x = (pMVar3->right).x;
    pMVar3 = (Matrix *)&(pMVar3->right).y;
    pMVar4 = (Matrix *)&(pMVar4->right).y;
  }
  return in_ECX;
}


// ---------------------------------------------------------------------
// GetPositionNearOrFar  @ 4fc046d8  lines 2288-2303

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
  float dir;
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
            local_14 * (in_ECX->y - param_2.x) + dir * (in_ECX->x - param_1.z);
    if ((bool)in_DL != 0.0 < fVar2) {
      fVar2 = fVar2 * -2.0;
      in_ECX->x = dir * fVar2 + in_ECX->x;
      in_ECX->y = local_14 * fVar2 + in_ECX->y;
      in_ECX->z = in_ECX->z + local_10 * fVar2;
      fVar2 = TerrainFindFloor(in_ECX->x,in_ECX->z);
      in_ECX->y = fVar2;
    }
  }
  return in_ECX;
}


// ---------------------------------------------------------------------
// CheckODFName  @ 4fc04840  lines 2307-2322

void __cdecl CheckODFName(char *ODFName)

{
  bool bVar1;
  char *pcVar2;
  
  bVar1 = DoesODFExist(ODFName);
  if (!bVar1) {
    pcVar2 = strchr(ODFName,0x3a);
    if (pcVar2 != (char *)0x0) {
      *pcVar2 = '\0';
    }
    bVar1 = DoesODFExist(ODFName);
    if (!bVar1) {
      pcVar2 = strrchr(ODFName,0x2e);
      if (pcVar2 != (char *)0x0) {
        *pcVar2 = '\0';
      }
    }
  }
  return;
}


// ---------------------------------------------------------------------
// PlayVOMsg  @ 4fc04881  lines 2374-2390

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __cdecl PlayVOMsg(int h,char *MsgString,int Team)

{
  bool bVar1;
  int iVar2;
  char MsgSound [64];
  uint local_8;
  
  local_8 = __security_cookie ^ (uint)&stack0xfffffffc;
  bVar1 = IsAround(h);
  if ((bVar1) && (MsgString != (char *)0x0)) {
    if (Team == -1) {
      Team = GetTeamNum(h);
    }
    iVar2 = GetLocalPlayerTeamNumber();
    if (Team == iVar2) {
      memset(MsgSound,0,0x40);
      iVar2 = GetODFString(h,"CraftClass",MsgString,0x40,MsgSound,(char *)0x0);
      if ((iVar2 != 0) && (MsgSound[0] != '\0')) {
        AudioMessage(MsgSound,false);
      }
    }
  }
  return;
}


// ---------------------------------------------------------------------
// PlayEventVO  @ 4fc0490f  lines 2394-2417

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __cdecl PlayEventVO(char param_1,int param_2,int param_3)

{
  bool bVar1;
  int iVar2;
  char in_CL;
  char local_c4 [64];
  char local_84 [64];
  char local_44 [64];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)local_c4;
  memset(local_84,0,0x40);
  memset(local_c4,0,0x40);
  sprintf_s<64>(&local_c4,"%cevent.odf",(int)in_CL);
  bVar1 = DoesFileExist(local_c4);
  if (!bVar1) {
    strcpy_s(local_c4,0x40,"aevent.odf");
  }
  memset(local_44,0,0x40);
  sprintf_s<64>(&local_44,"EVENT_SOUND_%d",0xb);
  bVar1 = OpenODF2(local_c4);
  if (bVar1) {
    iVar2 = GetODFString(local_c4,"BettyVoice",local_44,0x40,local_84,(char *)0x0);
    if ((iVar2 != 0) && (local_84[0] != '\0')) {
      bVar1 = DoesFileExist(local_84);
      if (bVar1) {
        AudioMessage(local_84,false);
      }
      else {
        FormatLogMessage("ERROR: Sound file: \'%s\' doesn\'t exist! Fix %s in ODF: \'%s\'",local_84,
                         local_44,local_c4);
      }
    }
  }
  return;
}


// ---------------------------------------------------------------------
// IsBuildingOrGunTower  @ 4fc04a35  lines 2453-2501

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool __cdecl IsBuildingOrGunTower(int h,int ObjClassHash)

{
  bool bVar1;
  uint uVar2;
  uint unaff_ESI;
  uint uVar3;
  char *unaff_EDI;
  char ObjClass [64];
  uint local_8;
  
  local_8 = __security_cookie ^ (uint)&stack0xfffffffc;
  uVar3 = 0;
  if (ObjClassHash == 0) {
    memset(ObjClass,0,0x40);
    bVar1 = GetObjInfo(h,Get_GOClass,ObjClass);
    if (!bVar1) {
      return false;
    }
    ObjClassHash = Hash(unaff_EDI,unaff_ESI);
  }
  bVar1 = IsBuilding(h);
  if ((bVar1) || (ObjClassHash == 0xdf6dabba)) {
    uVar2 = 0;
    do {
      if (ObjClassHash == *(uint *)((int)MiscClass + uVar2)) {
        return false;
      }
      uVar2 = uVar2 + 4;
    } while (uVar2 < 0x28);
    while (ObjClassHash != *(uint *)((int)WeaponClass + uVar3)) {
      uVar3 = uVar3 + 4;
      if (0x2b < uVar3) {
        return true;
      }
    }
  }
  return false;
}


// ---------------------------------------------------------------------
// IsCraft  @ 4fc04ac7  lines 2505-2532

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool __cdecl IsCraft(int h,int ObjClassHash)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  char ObjClass [64];
  uint local_8;
  
  local_8 = __security_cookie ^ (uint)&stack0xfffffffc;
  if (ObjClassHash == 0) {
    memset(ObjClass,0,0x40);
    bVar2 = GetObjInfo(h,Get_GOClass,ObjClass);
    bVar1 = false;
    if (((bVar2) && (bVar2 = IsCraftButNotPerson(h), bVar1 = false, bVar2)) &&
       (iVar3 = _stricmp(ObjClass,"CLASS_TURRET"), iVar3 != 0)) {
      bVar1 = true;
    }
  }
  else {
    bVar1 = IsCraftButNotPerson(h);
    if ((bVar1) && (ObjClassHash != -0x20925446)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
  }
  return bVar1;
}


// ---------------------------------------------------------------------
// IsWeapon  @ 4fc04b54  lines 2563-2583

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool __cdecl IsWeapon(int h,int ObjClassHash)

{
  bool bVar1;
  uint unaff_ESI;
  uint uVar2;
  char *unaff_EDI;
  char ObjClass [64];
  uint local_8;
  
  local_8 = __security_cookie ^ (uint)&stack0xfffffffc;
  uVar2 = 0;
  if (ObjClassHash == 0) {
    memset(ObjClass,0,0x40);
    bVar1 = GetObjInfo(h,Get_GOClass,ObjClass);
    if (!bVar1) {
      return false;
    }
    ObjClassHash = Hash(unaff_EDI,unaff_ESI);
  }
  do {
    if (ObjClassHash == *(uint *)((int)WeaponClass + uVar2)) {
      return true;
    }
    uVar2 = uVar2 + 4;
  } while (uVar2 < 0x2c);
  return false;
}


// ---------------------------------------------------------------------
// IsMisc  @ 4fc04bbc  lines 2587-2607

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool __cdecl IsMisc(int h,int ObjClassHash)

{
  bool bVar1;
  uint unaff_ESI;
  uint uVar2;
  char *unaff_EDI;
  char ObjClass [64];
  uint local_8;
  
  local_8 = __security_cookie ^ (uint)&stack0xfffffffc;
  uVar2 = 0;
  if (ObjClassHash == 0) {
    memset(ObjClass,0,0x40);
    bVar1 = GetObjInfo(h,Get_GOClass,ObjClass);
    if (!bVar1) {
      return false;
    }
    ObjClassHash = Hash(unaff_EDI,unaff_ESI);
  }
  do {
    if (ObjClassHash == *(uint *)((int)MiscClass + uVar2)) {
      return true;
    }
    uVar2 = uVar2 + 4;
  } while (uVar2 < 0x28);
  return false;
}


// ---------------------------------------------------------------------
// IsFactory  @ 4fc04c24  lines 2710-2719

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool __cdecl IsFactory(int h)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  char BZCClass [64];
  char ObjClass [64];
  uint local_8;
  
  local_8 = __security_cookie ^ (uint)&stack0xfffffffc;
  memset(ObjClass,0,0x40);
  bVar1 = GetObjInfo(h,Get_GOClass,ObjClass);
  bVar2 = false;
  if (bVar1) {
    memset(BZCClass,0,0x40);
    GetODFString(h,"GameObjectClass","BZCClasslabel",0x40,BZCClass,(char *)0x0);
    iVar3 = _stricmp(ObjClass,"CLASS_FACTORY");
    if ((iVar3 == 0) || (iVar3 = _stricmp(BZCClass,"muf"), bVar2 = false, iVar3 == 0)) {
      bVar2 = true;
    }
  }
  return bVar2;
}


// ---------------------------------------------------------------------
// IsArmory  @ 4fc04cc5  lines 2722-2731

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool __cdecl IsArmory(int h)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  char BZCClass [64];
  char ObjClass [64];
  uint local_8;
  
  local_8 = __security_cookie ^ (uint)&stack0xfffffffc;
  memset(ObjClass,0,0x40);
  bVar1 = GetObjInfo(h,Get_GOClass,ObjClass);
  bVar2 = false;
  if (bVar1) {
    memset(BZCClass,0,0x40);
    GetODFString(h,"GameObjectClass","BZCClasslabel",0x40,BZCClass,(char *)0x0);
    iVar3 = _stricmp(ObjClass,"CLASS_ARMORY");
    if ((iVar3 == 0) || (iVar3 = _stricmp(BZCClass,"slf"), bVar2 = false, iVar3 == 0)) {
      bVar2 = true;
    }
  }
  return bVar2;
}


// ---------------------------------------------------------------------
// IsConstructor  @ 4fc04d66  lines 2734-2753

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool __cdecl IsConstructor(int param_1,int param_2)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  int in_ECX;
  char ObjClass [64];
  uint local_8;
  
  local_8 = __security_cookie ^ (uint)&stack0xfffffffc;
  memset(ObjClass,0,0x40);
  bVar1 = GetObjInfo(in_ECX,Get_GOClass,ObjClass);
  bVar2 = false;
  if ((bVar1) &&
     ((iVar3 = _stricmp(ObjClass,"CLASS_CONSTRUCTIONRIG"), iVar3 == 0 ||
      (iVar3 = _stricmp(ObjClass,"CLASS_CONSTRUCTIONRIGT"), bVar2 = false, iVar3 == 0)))) {
    bVar2 = true;
  }
  return bVar2;
}


// ---------------------------------------------------------------------
// IsServiceTruck  @ 4fc04dd6  lines 2768-2777

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool __cdecl IsServiceTruck(int param_1,int param_2)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  int in_ECX;
  char ObjClass [64];
  uint local_8;
  
  local_8 = __security_cookie ^ (uint)&stack0xfffffffc;
  memset(ObjClass,0,0x40);
  bVar1 = GetObjInfo(in_ECX,Get_GOClass,ObjClass);
  bVar2 = false;
  if ((bVar1) &&
     ((iVar3 = _stricmp(ObjClass,"CLASS_SERVICE"), iVar3 == 0 ||
      (iVar3 = _stricmp(ObjClass,"CLASS_SERVICEH"), bVar2 = false, iVar3 == 0)))) {
    bVar2 = true;
  }
  return bVar2;
}


// ---------------------------------------------------------------------
// IsPoweredBuilding  @ 4fc04e46  lines 3024-3054

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool __cdecl IsPoweredBuilding(char *ODFName)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  uint uVar4;
  char local_44 [64];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)local_44;
  if (ODFName != (char *)0x0) {
    uVar4 = 0;
    memset(local_44,0,0x40);
    pcVar2 = ODFName;
    do {
      pcVar3 = pcVar2;
      pcVar2 = pcVar3 + 1;
    } while (*pcVar3 != '\0');
    iVar1 = _stricmp(pcVar3 + -4,".odf");
    if (iVar1 != 0) {
      CombineStrings(local_44,ODFName,".odf",0x40);
    }
    memset(TempGetClasslabelString,0,0x40);
    pcVar2 = GetClasslabelString(local_44);
    do {
      iVar1 = _stricmp(pcVar2,*(char **)((int)ClassLabelPoweredBuildings + uVar4));
      if (iVar1 == 0) {
        return true;
      }
      uVar4 = uVar4 + 4;
    } while (uVar4 < 0x34);
  }
  return false;
}


// ---------------------------------------------------------------------
// IsBuilding  @ 4fc04ef7  lines 3058-3088

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool __cdecl IsBuilding(char *ODFName)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  uint uVar4;
  char local_44 [64];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)local_44;
  if (ODFName != (char *)0x0) {
    uVar4 = 0;
    memset(local_44,0,0x40);
    pcVar2 = ODFName;
    do {
      pcVar3 = pcVar2;
      pcVar2 = pcVar3 + 1;
    } while (*pcVar3 != '\0');
    iVar1 = _stricmp(pcVar3 + -4,".odf");
    if (iVar1 != 0) {
      CombineStrings(local_44,ODFName,".odf",0x40);
    }
    memset(TempGetClasslabelString,0,0x40);
    pcVar2 = GetClasslabelString(local_44);
    do {
      iVar1 = _stricmp(pcVar2,*(char **)((int)ClassLabelBuildings + uVar4));
      if (iVar1 == 0) {
        return true;
      }
      uVar4 = uVar4 + 4;
    } while (uVar4 < 0x54);
  }
  return false;
}


// ---------------------------------------------------------------------
// GetODFName  @ 4fc04fa8  lines 3126-3137

bool __cdecl GetODFName(int h,char *ODFName)

{
  bool bVar1;
  char *pcVar2;
  
  if (ODFName != (char *)0x0) {
    bVar1 = GetObjInfo(h,Get_ODF,ODFName);
    if (bVar1) {
      pcVar2 = strrchr(ODFName,0x2e);
      if (pcVar2 != (char *)0x0) {
        *pcVar2 = '\0';
      }
      return true;
    }
  }
  return false;
}


// ---------------------------------------------------------------------
// GetODFName  @ 4fc04fda  lines 3141-3154

char * __cdecl GetODFName(int h)

{
  memset(TempGetODFName,0,0x40);
  GetODFName(h,TempGetODFName);
  return TempGetODFName;
}


// ---------------------------------------------------------------------
// GetAndOpenODFNames  @ 4fc04ffe  lines 3158-3181

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool __cdecl GetAndOpenODFNames(int h,char *TempODF1,char *TempODF2,char *ODFName)

{
  bool bVar1;
  int iVar2;
  char *pcVar3;
  char TempODFString [64];
  uint local_8;
  
  local_8 = __security_cookie ^ (uint)&stack0xfffffffc;
  if ((TempODF2 != (char *)0x0) && (bVar1 = GetObjInfo(h,Get_ODF,TempODF1), bVar1)) {
    memset(TempODFString,0,0x40);
    bVar1 = OpenODF2(TempODF1);
    if ((bVar1) &&
       (iVar2 = GetODFString(TempODF1,"GameObjectClass","classlabel",0x40,TempODFString,(char *)0x0)
       , iVar2 != 0)) {
      CombineStrings(TempODF2,TempODFString,".odf",0x40);
      bVar1 = OpenODF2(TempODF2);
      if (!bVar1) {
        *TempODF2 = '\0';
      }
    }
    if (ODFName != (char *)0x0) {
      CombineStrings(ODFName,"",TempODF1,0x40);
      pcVar3 = strrchr(ODFName,0x2e);
      if (pcVar3 != (char *)0x0) {
        *pcVar3 = '\0';
      }
    }
    return true;
  }
  return false;
}


// ---------------------------------------------------------------------
// GetClasslabelString  @ 4fc050cc  lines 3186-3229

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

char * __cdecl GetClasslabelString(char *ODFName)

{
  bool bVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  char local_84 [64];
  char local_44 [64];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)local_84;
  memset(local_84,0,0x40);
  pcVar4 = ODFName;
  do {
    pcVar3 = pcVar4;
    pcVar4 = pcVar3 + 1;
  } while (*pcVar3 != '\0');
  iVar2 = _stricmp(pcVar3 + -4,".odf");
  if (iVar2 == 0) {
    pcVar4 = "";
  }
  else {
    pcVar4 = ODFName;
    ODFName = ".odf";
  }
  CombineStrings(local_84,pcVar4,ODFName,0x40);
  bVar1 = OpenODF2(local_84);
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
      strcpy_s(local_44,0x40,TempGetClasslabelString);
      CombineStrings(local_84,TempGetClasslabelString,".odf",0x40);
      bVar1 = OpenODF2(local_84);
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
// GetPilotConfig  @ 4fc052b5  lines 3333-3355

char * __cdecl GetPilotConfig(int h)

{
  char *pcVar1;
  
  memset(TempGetPilotConfig,0,0x40);
  pcVar1 = GetPilotClass(h);
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
// CombineStrings  @ 4fc052f8  lines 3359-3381

bool __cdecl CombineStrings(char *ReturnString,char *String1,char *String2,uint MaxSize)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  
  if (((ReturnString != (char *)0x0) && (String1 != (char *)0x0)) && (String2 != (char *)0x0)) {
    if (ReturnString == String2) {
      pcVar3 = "ERROR: \'%s\' cannot append \'%s\', Return and String2 is itself!";
    }
    else {
      pcVar3 = String1;
      do {
        cVar1 = *pcVar3;
        pcVar3 = pcVar3 + 1;
      } while (cVar1 != '\0');
      pcVar2 = String2;
      do {
        cVar1 = *pcVar2;
        pcVar2 = pcVar2 + 1;
      } while (cVar1 != '\0');
      if (pcVar3 + (int)(pcVar2 + (-(int)(String2 + 1) - (int)(String1 + 1))) <= MaxSize) {
        if (ReturnString == String1) {
          strcat_s(ReturnString,MaxSize,String2);
        }
        else {
          sprintf_s(ReturnString,MaxSize,"%s%s",String1,String2);
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
// GetWorldVariantODF  @ 4fc0537f  lines 3405-3428

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool __cdecl GetWorldVariantODF(char *ODFName)

{
  bool bVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  char cVar7;
  char WorldSetting;
  char TempWorldODF [64];
  uint local_8;
  
  local_8 = __security_cookie ^ (uint)&stack0xfffffffc;
  iVar2 = tolower((int)ODFName[1]);
  if (iVar2 == 0x76) {
    pcVar3 = strrchr(ODFName,0x2e);
    if (pcVar3 != (char *)0x0) {
      *pcVar3 = '\0';
    }
    cVar7 = '\0';
    pcVar3 = &WorldSetting;
    WorldSetting = '\0';
    pcVar6 = "WorldLetter";
    pcVar5 = "World";
    pcVar4 = GetMapTRNFilename();
    iVar2 = GetODFChar(pcVar4,pcVar5,pcVar6,pcVar3,cVar7);
    if (iVar2 != 0) {
      pcVar3 = ODFName;
      do {
        cVar7 = *pcVar3;
        pcVar3 = pcVar3 + 1;
      } while (cVar7 != '\0');
      if ((uint)((int)pcVar3 - (int)(ODFName + 1)) < 0x41) {
        memset(TempWorldODF,0,0x40);
        sprintf_s<64>(&TempWorldODF,"%s%c",ODFName,(int)WorldSetting);
        bVar1 = DoesODFExist(TempWorldODF);
        if (bVar1) {
          strcpy_s(ODFName,0x40,TempWorldODF);
          return true;
        }
      }
    }
  }
  return false;
}


// ---------------------------------------------------------------------
// GetPilotCost  @ 4fc05449  lines 3523-3575

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl GetPilotCost(char *ODF)

{
  bool bVar1;
  int TempPilotCost;
  char PilotODF [64];
  uint local_8;
  
  local_8 = __security_cookie ^ (uint)&stack0xfffffffc;
  TempPilotCost = 0;
  memset(PilotODF,0,0x40);
  CombineStrings(PilotODF,"",ODF,0x40);
  CheckODFName(PilotODF);
  CombineStrings(PilotODF,PilotODF,".odf",0x40);
  bVar1 = OpenODF2(PilotODF);
  if (bVar1) {
    GetODFInt(PilotODF,(char *)0x0,"GameObjectClass","pilotCost",&TempPilotCost,0);
  }
  return TempPilotCost;
}


// ---------------------------------------------------------------------
// GetScrapCost  @ 4fc054d2  lines 3579-3600

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl GetScrapCost(char *ODF)

{
  bool bVar1;
  int TempScrapCost;
  char TempODF [64];
  uint local_8;
  
  local_8 = __security_cookie ^ (uint)&stack0xfffffffc;
  TempScrapCost = 0;
  memset(TempODF,0,0x40);
  CombineStrings(TempODF,"",ODF,0x40);
  CheckODFName(TempODF);
  CombineStrings(TempODF,TempODF,".odf",0x40);
  bVar1 = OpenODF2(TempODF);
  if (bVar1) {
    GetODFInt(TempODF,(char *)0x0,"GameObjectClass","scrapCost",&TempScrapCost,0);
  }
  return TempScrapCost;
}


// ---------------------------------------------------------------------
// GetScrapValue  @ 4fc0555b  lines 3604-3638

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl GetScrapValue(char *ODF)

{
  bool bVar1;
  int TempScrapValue;
  char TempODF [64];
  uint local_8;
  
  local_8 = __security_cookie ^ (uint)&stack0xfffffffc;
  if (ODF == (char *)0x0) {
    TempScrapValue = 0;
  }
  else {
    TempScrapValue = 0;
    memset(TempODF,0,0x40);
    CombineStrings(TempODF,"",ODF,0x40);
    CheckODFName(TempODF);
    CombineStrings(TempODF,TempODF,".odf",0x40);
    bVar1 = OpenODF2(TempODF);
    if (bVar1) {
      GetODFInt(TempODF,(char *)0x0,"GameObjectClass","scrapValue",&TempScrapValue,0);
    }
  }
  return TempScrapValue;
}


// ---------------------------------------------------------------------
// GetNumWeapons  @ 4fc055ec  lines 3642-3680

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl GetNumWeapons(int h)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  uint uVar6;
  uint unaff_ESI;
  char *unaff_EDI;
  int fmtarg1;
  char DesiredName [64];
  char WeaponHard [7];
  byte local_41;
  uint local_8;
  
  local_8 = __security_cookie ^ (uint)&stack0xfffffffc;
  bVar2 = IsAround(h);
  if (bVar2) {
    iVar3 = 0;
    fmtarg1 = 0;
    do {
      memset(WeaponHard,0,0x40);
      memset(DesiredName,0,0x40);
      fmtarg1 = fmtarg1 + 1;
      sprintf_s<64>(&DesiredName,"weaponHard%d",fmtarg1);
      iVar4 = GetODFString(h,"GameObjectClass",DesiredName,0x40,WeaponHard,(char *)0x0);
      if ((iVar4 != 0) && (iVar4 = _strnicmp(WeaponHard,"HP_",3), iVar4 == 0)) {
        pcVar5 = strchr(WeaponHard + 3,0x5f);
        if (pcVar5 != (char *)0x0) {
          *pcVar5 = '\0';
        }
        pcVar5 = WeaponHard;
        do {
          cVar1 = *pcVar5;
          pcVar5 = pcVar5 + 1;
        } while (cVar1 != '\0');
        local_41 = local_41 & -((uint)((int)pcVar5 - (int)(WeaponHard + 1)) < 6);
        uVar6 = Hash(unaff_EDI,unaff_ESI);
        if ((((uVar6 == 0xe1884a5e) || (uVar6 == 0xfc91ae57)) || (uVar6 == 0x3a26ab6c)) ||
           (((uVar6 == 0x46956389 || (uVar6 == 0x8fe971f7)) ||
            ((uVar6 == 0x9ac3c813 || (uVar6 == 0xf661135c)))))) {
          iVar3 = iVar3 + 1;
        }
      }
    } while (fmtarg1 < 5);
  }
  else {
    iVar3 = -1;
  }
  return iVar3;
}


// ---------------------------------------------------------------------
// CheckBuildRequirements_PowerCost  @ 4fc05706  lines 3693-3702

int __cdecl CheckBuildRequirements_PowerCost(int Team,char *filename1,char *filename2)

{
  bool bVar1;
  int iVar2;
  int PowerCost;
  
  PowerCost = 0;
  iVar2 = GetODFInt(filename1,filename2,"GameObjectClass","powerCost",&PowerCost,0);
  if (((iVar2 == 0) && (iVar2 = GetTapCount(filename1,filename2), iVar2 == 0)) &&
     (bVar1 = IsPoweredBuilding(filename1), bVar1)) {
    PowerCost = 1;
  }
  iVar2 = GetPower(Team);
  return iVar2 - PowerCost;
}


// ---------------------------------------------------------------------
// GetConfigODF  @ 4fc05767  lines 3707-3736

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

char * __cdecl GetConfigODF(int h)

{
  bool bVar1;
  char *pcVar2;
  char local_44 [64];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)local_44;
  memset(TempGetConfigODFName,0,0x40);
  memset(local_44,0,0x40);
  bVar1 = GetODFName(h,local_44);
  if (bVar1) {
    CombineStrings(TempGetConfigODFName,local_44,"_config.odf",0x40);
    bVar1 = DoesFileExist(TempGetConfigODFName);
    if (!bVar1) {
      GetODFString(h,"GameObjectClass","classlabel",0x40,TempGetConfigODFName,(char *)0x0);
      CombineStrings(TempGetConfigODFName,TempGetConfigODFName,"_config.odf",0x40);
      bVar1 = DoesFileExist(TempGetConfigODFName);
      if (!bVar1) {
        GetObjInfo(h,Get_GOClass_gCfg,TempGetConfigODFName);
        CombineStrings(TempGetConfigODFName,TempGetConfigODFName,"_config.odf",0x40);
        bVar1 = DoesFileExist(TempGetConfigODFName);
        if (!bVar1) goto LAB_4fc05821;
      }
    }
    pcVar2 = TempGetConfigODFName;
  }
  else {
LAB_4fc05821:
    pcVar2 = (char *)0x0;
  }
  return pcVar2;
}


// ---------------------------------------------------------------------
// OpenODF2  @ 4fc05836  lines 3815-3863

bool __cdecl OpenODF2(char *name)

{
  undefined4 uVar1;
  bool bVar2;
  _List_iterator<std::_List_val<std::_List_simple_types<std::pair<unsigned_long_const_,ODFName>_>_>_>
  _Var3;
  _List_const_iterator<std::_List_val<std::_List_simple_types<unsigned_long>_>_> _Var4;
  ulong *puVar5;
  _Hash<std::_Uset_traits<unsigned_long,std::_Uhash_compare<unsigned_long,std::hash<unsigned_long>,std::equal_to<unsigned_long>_>,std::allocator<unsigned_long>,0>_>
  *this;
  _Hash<std::_Umap_traits<unsigned_long,ODFName,std::_Uhash_compare<unsigned_long,std::hash<unsigned_long>,std::equal_to<unsigned_long>_>,std::allocator<std::pair<unsigned_long_const_,ODFName>_>,0>_>
  *this_00;
  _Hash<std::_Umap_traits<unsigned_long,ODFName,std::_Uhash_compare<unsigned_long,std::hash<unsigned_long>,std::equal_to<unsigned_long>_>,std::allocator<std::pair<unsigned_long_const_,ODFName>_>,0>_>
  *this_01;
  _Hash<std::_Uset_traits<unsigned_long,std::_Uhash_compare<unsigned_long,std::hash<unsigned_long>,std::equal_to<unsigned_long>_>,std::allocator<unsigned_long>,0>_>
  *this_02;
  _Hash<std::_Umap_traits<unsigned_long,ODFName,std::_Uhash_compare<unsigned_long,std::hash<unsigned_long>,std::equal_to<unsigned_long>_>,std::allocator<std::pair<unsigned_long_const_,ODFName>_>,0>_>
  *this_03;
  ulong *local_14 [2];
  ulong *local_c;
  ulong nameHash;
  
  if ((*name != '\0') && (*name != '.')) {
    this_03 = (_Hash<std::_Umap_traits<unsigned_long,ODFName,std::_Uhash_compare<unsigned_long,std::hash<unsigned_long>,std::equal_to<unsigned_long>_>,std::allocator<std::pair<unsigned_long_const_,ODFName>_>,0>_>
               *)name;
    nameHash = CalcCRC(name);
    uVar1 = ODFNameMap._4_4_;
    _Var3 = std::
            _Hash<std::_Umap_traits<unsigned_long,ODFName,std::_Uhash_compare<unsigned_long,std::hash<unsigned_long>,std::equal_to<unsigned_long>_>,std::allocator<std::pair<unsigned_long_const_,ODFName>_>,0>_>
            ::find(this_03,(ulong *)&local_c);
    if (*(int *)_Var3 != uVar1) {
      return true;
    }
    _Var4 = std::
            _Hash<std::_Uset_traits<unsigned_long,std::_Uhash_compare<unsigned_long,std::hash<unsigned_long>,std::equal_to<unsigned_long>_>,std::allocator<unsigned_long>,0>_>
            ::find(this,(ulong *)&local_c);
    if (*(int *)_Var4 == ODFNameBlackListMap._4_4_) {
      PetWatchdogThread();
      this_02 = (_Hash<std::_Uset_traits<unsigned_long,std::_Uhash_compare<unsigned_long,std::hash<unsigned_long>,std::equal_to<unsigned_long>_>,std::allocator<unsigned_long>,0>_>
                 *)name;
      bVar2 = OpenODF(name);
      if (bVar2) {
        PetWatchdogThread();
        std::
        _Hash<std::_Umap_traits<unsigned_long,ODFName,std::_Uhash_compare<unsigned_long,std::hash<unsigned_long>,std::equal_to<unsigned_long>_>,std::allocator<std::pair<unsigned_long_const_,ODFName>_>,0>_>
        ::find(this_00,(ulong *)&local_c);
        puVar5 = local_c;
        if (local_c == (ulong *)ODFNameMap._4_4_) {
          local_c = &nameHash;
          std::
          _Hash<std::_Umap_traits<unsigned_long,ODFName,std::_Uhash_compare<unsigned_long,std::hash<unsigned_long>,std::equal_to<unsigned_long>_>,std::allocator<std::pair<unsigned_long_const_,ODFName>_>,0>_>
          ::
          emplace<std::piecewise_construct_t_const_&,std::tuple<unsigned_long_const_&>,std::tuple<>_>
                    (this_01,(piecewise_construct_t *)local_14,
                     (tuple<unsigned_long_const_&> *)this_01,(tuple<> *)&local_c);
          puVar5 = local_14[0];
        }
        strcpy_s((char *)(puVar5 + 3),0x40,name);
        return true;
      }
      std::
      _Hash<std::_Uset_traits<unsigned_long,std::_Uhash_compare<unsigned_long,std::hash<unsigned_long>,std::equal_to<unsigned_long>_>,std::allocator<unsigned_long>,0>_>
      ::_Insert<unsigned_long_const_&,std::_Not_a_node_tag>
                (this_02,(ulong *)local_14,SUB41(&nameHash,0));
    }
  }
  return false;
}


// ---------------------------------------------------------------------
// CloseOpenODFs  @ 4fc05900  lines 3867-3873

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
// GetODFInt  @ 4fc05939  lines 3923-3967

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl GetODFInt(int h,char *block,char *name,int *value,int defval)

{
  bool bVar1;
  int iVar2;
  char local_44 [64];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)local_44;
  memset(local_44,0,0x40);
  bVar1 = GetObjInfo(h,Get_ODF,local_44);
  if (((bVar1) && (block != (char *)0x0)) && (name != (char *)0x0)) {
    iVar2 = GetODFInt(local_44,(char *)0x0,block,name,value,defval);
  }
  else {
    iVar2 = 0;
  }
  return iVar2;
}


// ---------------------------------------------------------------------
// GetODFFloat  @ 4fc059ae  lines 4014-4057

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl GetODFFloat(int h,char *block,char *name,float *value,float defval)

{
  bool bVar1;
  int iVar2;
  char local_44 [64];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)local_44;
  memset(local_44,0,0x40);
  bVar1 = GetObjInfo(h,Get_ODF,local_44);
  if (((bVar1) && (block != (char *)0x0)) && (name != (char *)0x0)) {
    iVar2 = GetODFFloat(local_44,(char *)0x0,block,name,value,defval);
  }
  else {
    iVar2 = 0;
  }
  return iVar2;
}


// ---------------------------------------------------------------------
// GetODFDouble  @ 4fc05a27  lines 4059-4102

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl GetODFDouble(int h,char *block,char *name,double *value,double defval)

{
  bool bVar1;
  int iVar2;
  undefined4 unaff_EBP;
  undefined4 unaff_ESI;
  char local_4c [68];
  uint local_8;
  
  local_8 = __security_cookie ^ (uint)local_4c;
  memset(local_4c,0,0x40);
  bVar1 = GetObjInfo(h,Get_ODF,local_4c);
  if (((bVar1) && (block != (char *)0x0)) && (name != (char *)0x0)) {
    iVar2 = GetODFDouble(block,name,(char *)value,SUB84(defval,0),
                         (double *)((ulonglong)defval >> 0x20),(double)CONCAT44(unaff_EBP,unaff_ESI)
                        );
  }
  else {
    iVar2 = 0;
  }
  return iVar2;
}


// ---------------------------------------------------------------------
// GetODFChar  @ 4fc05aa2  lines 4104-4147

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl GetODFChar(int h,char *block,char *name,char *value,char defval)

{
  bool bVar1;
  int iVar2;
  char local_44 [64];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)local_44;
  memset(local_44,0,0x40);
  bVar1 = GetObjInfo(h,Get_ODF,local_44);
  if (((bVar1) && (block != (char *)0x0)) && (name != (char *)0x0)) {
    iVar2 = GetODFChar(local_44,(char *)0x0,block,name,value,defval);
  }
  else {
    iVar2 = 0;
  }
  return iVar2;
}


// ---------------------------------------------------------------------
// GetODFBool  @ 4fc05b17  lines 4149-4192

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl GetODFBool(int h,char *block,char *name,bool *value,bool defval)

{
  bool bVar1;
  int iVar2;
  char local_44 [64];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)local_44;
  memset(local_44,0,0x40);
  bVar1 = GetObjInfo(h,Get_ODF,local_44);
  if (((bVar1) && (block != (char *)0x0)) && (name != (char *)0x0)) {
    iVar2 = GetODFBool(local_44,(char *)0x0,block,name,value,defval);
  }
  else {
    iVar2 = 0;
  }
  return iVar2;
}


// ---------------------------------------------------------------------
// GetODFString  @ 4fc05b8c  lines 4194-4237

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl GetODFString(int h,char *block,char *name,uint ValueLen,char *value,char *defval)

{
  bool bVar1;
  int iVar2;
  char *local_48;
  char local_44 [64];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)&local_48;
  local_48 = defval;
  memset(local_44,0,0x40);
  bVar1 = GetObjInfo(h,Get_ODF,local_44);
  if (((bVar1) && (block != (char *)0x0)) && (name != (char *)0x0)) {
    iVar2 = GetODFString(local_44,(char *)0x0,block,name,ValueLen,value,local_48);
  }
  else {
    iVar2 = 0;
  }
  return iVar2;
}


// ---------------------------------------------------------------------
// GetODFVector  @ 4fc05c0d  lines 4284-4327

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl GetODFVector(int h,char *block,char *name,Vector *value,Vector defval)

{
  bool bVar1;
  int iVar2;
  Vector *local_48;
  char local_44 [64];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)&local_48;
  local_48 = value;
  memset(local_44,0,0x40);
  bVar1 = GetObjInfo(h,Get_ODF,local_44);
  if (((bVar1) && (block != (char *)0x0)) && (name != (char *)0x0)) {
    iVar2 = GetODFVector(local_44,(char *)0x0,block,name,local_48,defval);
  }
  else {
    iVar2 = 0;
  }
  return iVar2;
}


// ---------------------------------------------------------------------
// GetODFHexInt  @ 4fc05c91  lines 4332-4360

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl
GetODFHexInt(char *param_1,char *param_2,char *param_3,char *param_4,int *param_5,int param_6)

{
  bool bVar1;
  int iVar2;
  char *in_ECX;
  char *pcVar3;
  char *pcVar4;
  char local_84 [64];
  char local_44 [64];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)local_84;
  if ((in_ECX != (char *)0x0) &&
     (iVar2 = GetODFHexInt(in_ECX,param_1,param_2,(int *)param_3,(int)param_4), iVar2 != 0)) {
    return 1;
  }
  memset(local_84,0,0x40);
  pcVar3 = in_ECX;
  do {
    pcVar4 = pcVar3;
    pcVar3 = pcVar4 + 1;
  } while (*pcVar4 != '\0');
  iVar2 = _stricmp(pcVar4 + -4,".odf");
  if (iVar2 == 0) {
    pcVar3 = "";
    pcVar4 = in_ECX;
  }
  else {
    pcVar4 = ".odf";
    pcVar3 = in_ECX;
  }
  CombineStrings(local_84,pcVar3,pcVar4,0x40);
  memset(local_44,0,0x40);
  while( true ) {
    bVar1 = OpenODF2(local_84);
    if (!bVar1) {
      return 0;
    }
    iVar2 = GetODFHexInt(local_84,param_1,param_2,(int *)param_3,(int)param_4);
    if (iVar2 != 0) {
      return 1;
    }
    iVar2 = GetODFString(local_84,"GameObjectClass","classlabel",0x40,local_44,(char *)0x0);
    if (iVar2 == 0) {
      return 0;
    }
    CombineStrings(local_44,local_44,".odf",0x40);
    iVar2 = _stricmp(local_84,local_44);
    if (iVar2 == 0) break;
    strcpy_s(local_84,0x40,local_44);
  }
  return 0;
}


// ---------------------------------------------------------------------
// GetODFInt  @ 4fc05df5  lines 4362-4390

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl GetODFInt(char *file1,char *file2,char *block,char *name,int *value,int defval)

{
  bool bVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  char *local_90;
  char *local_8c;
  int *local_88;
  char local_84 [64];
  char local_44 [64];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)&local_90;
  local_90 = block;
  local_8c = name;
  local_88 = value;
  if (((file1 != (char *)0x0) && (iVar2 = GetODFInt(file1,block,name,value,defval), iVar2 != 0)) ||
     ((file2 != (char *)0x0 &&
      (iVar2 = GetODFInt(file2,local_90,local_8c,local_88,defval), iVar2 != 0)))) {
    return 1;
  }
  memset(local_84,0,0x40);
  pcVar4 = file1;
  pcVar3 = file2;
  if (file2 == (char *)0x0) {
    do {
      pcVar3 = pcVar4;
      pcVar4 = pcVar3 + 1;
    } while (*pcVar3 != '\0');
    iVar2 = _stricmp(pcVar3 + -4,".odf");
    if (iVar2 == 0) {
      pcVar4 = "";
      file2 = file1;
      goto LAB_4fc05ef9;
    }
  }
  else {
    do {
      pcVar4 = pcVar3;
      pcVar3 = pcVar4 + 1;
    } while (*pcVar4 != '\0');
    iVar2 = _stricmp(pcVar4 + -4,".odf");
    file1 = file2;
    if (iVar2 == 0) {
      pcVar4 = "";
      goto LAB_4fc05ef9;
    }
  }
  file2 = ".odf";
  pcVar4 = file1;
LAB_4fc05ef9:
  CombineStrings(local_84,pcVar4,file2,0x40);
  memset(local_44,0,0x40);
  bVar1 = OpenODF2(local_84);
  pcVar3 = local_8c;
  pcVar4 = local_90;
  if (bVar1) {
    do {
      iVar2 = GetODFInt(local_84,pcVar4,pcVar3,local_88,defval);
      if (iVar2 != 0) {
        return 1;
      }
      iVar2 = GetODFString(local_84,"GameObjectClass","classlabel",0x40,local_44,(char *)0x0);
      if (iVar2 == 0) {
        return 0;
      }
      CombineStrings(local_44,local_44,".odf",0x40);
      iVar2 = _stricmp(local_84,local_44);
      if (iVar2 == 0) {
        return 0;
      }
      strcpy_s(local_84,0x40,local_44);
      bVar1 = OpenODF2(local_84);
    } while (bVar1);
  }
  return 0;
}


// ---------------------------------------------------------------------
// GetODFLong  @ 4fc05fdd  lines 4392-4420

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl GetODFLong(char *file1,char *file2,char *block,char *name,long *value,long defval)

{
  bool bVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  char *local_90;
  char *local_8c;
  long *local_88;
  char local_84 [64];
  char local_44 [64];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)&local_90;
  local_90 = block;
  local_8c = name;
  local_88 = value;
  if (((file1 != (char *)0x0) && (iVar2 = GetODFLong(file1,block,name,value,defval), iVar2 != 0)) ||
     ((file2 != (char *)0x0 &&
      (iVar2 = GetODFLong(file2,local_90,local_8c,local_88,defval), iVar2 != 0)))) {
    return 1;
  }
  memset(local_84,0,0x40);
  pcVar4 = file1;
  pcVar3 = file2;
  if (file2 == (char *)0x0) {
    do {
      pcVar3 = pcVar4;
      pcVar4 = pcVar3 + 1;
    } while (*pcVar3 != '\0');
    iVar2 = _stricmp(pcVar3 + -4,".odf");
    if (iVar2 == 0) {
      pcVar4 = "";
      file2 = file1;
      goto LAB_4fc060e1;
    }
  }
  else {
    do {
      pcVar4 = pcVar3;
      pcVar3 = pcVar4 + 1;
    } while (*pcVar4 != '\0');
    iVar2 = _stricmp(pcVar4 + -4,".odf");
    file1 = file2;
    if (iVar2 == 0) {
      pcVar4 = "";
      goto LAB_4fc060e1;
    }
  }
  file2 = ".odf";
  pcVar4 = file1;
LAB_4fc060e1:
  CombineStrings(local_84,pcVar4,file2,0x40);
  memset(local_44,0,0x40);
  bVar1 = OpenODF2(local_84);
  pcVar3 = local_8c;
  pcVar4 = local_90;
  if (bVar1) {
    do {
      iVar2 = GetODFLong(local_84,pcVar4,pcVar3,local_88,defval);
      if (iVar2 != 0) {
        return 1;
      }
      iVar2 = GetODFString(local_84,"GameObjectClass","classlabel",0x40,local_44,(char *)0x0);
      if (iVar2 == 0) {
        return 0;
      }
      CombineStrings(local_44,local_44,".odf",0x40);
      iVar2 = _stricmp(local_84,local_44);
      if (iVar2 == 0) {
        return 0;
      }
      strcpy_s(local_84,0x40,local_44);
      bVar1 = OpenODF2(local_84);
    } while (bVar1);
  }
  return 0;
}


// ---------------------------------------------------------------------
// GetODFFloat  @ 4fc061c5  lines 4422-4450

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl GetODFFloat(char *file1,char *file2,char *block,char *name,float *value,float defval)

{
  bool bVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  char *local_90;
  char *local_8c;
  float *local_88;
  char local_84 [64];
  char local_44 [64];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)&local_90;
  local_90 = block;
  local_8c = name;
  local_88 = value;
  if (((file1 != (char *)0x0) && (iVar2 = GetODFFloat(file1,block,name,value,defval), iVar2 != 0))
     || ((file2 != (char *)0x0 &&
         (iVar2 = GetODFFloat(file2,local_90,local_8c,local_88,defval), iVar2 != 0)))) {
    return 1;
  }
  memset(local_84,0,0x40);
  pcVar4 = file1;
  pcVar3 = file2;
  if (file2 == (char *)0x0) {
    do {
      pcVar3 = pcVar4;
      pcVar4 = pcVar3 + 1;
    } while (*pcVar3 != '\0');
    iVar2 = _stricmp(pcVar3 + -4,".odf");
    if (iVar2 == 0) {
      pcVar4 = "";
      file2 = file1;
      goto LAB_4fc062d3;
    }
  }
  else {
    do {
      pcVar4 = pcVar3;
      pcVar3 = pcVar4 + 1;
    } while (*pcVar4 != '\0');
    iVar2 = _stricmp(pcVar4 + -4,".odf");
    file1 = file2;
    if (iVar2 == 0) {
      pcVar4 = "";
      goto LAB_4fc062d3;
    }
  }
  file2 = ".odf";
  pcVar4 = file1;
LAB_4fc062d3:
  CombineStrings(local_84,pcVar4,file2,0x40);
  memset(local_44,0,0x40);
  bVar1 = OpenODF2(local_84);
  pcVar3 = local_8c;
  pcVar4 = local_90;
  if (bVar1) {
    do {
      iVar2 = GetODFFloat(local_84,pcVar4,pcVar3,local_88,defval);
      if (iVar2 != 0) {
        return 1;
      }
      iVar2 = GetODFString(local_84,"GameObjectClass","classlabel",0x40,local_44,(char *)0x0);
      if (iVar2 == 0) {
        return 0;
      }
      CombineStrings(local_44,local_44,".odf",0x40);
      iVar2 = _stricmp(local_84,local_44);
      if (iVar2 == 0) {
        return 0;
      }
      strcpy_s(local_84,0x40,local_44);
      bVar1 = OpenODF2(local_84);
    } while (bVar1);
  }
  return 0;
}


// ---------------------------------------------------------------------
// GetODFDouble  @ 4fc063b6  lines 4452-4480

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl
GetODFDouble(char *param_1,char *param_2,char *param_3,char *param_4,double *param_5,double param_6)

{
  bool bVar1;
  int iVar2;
  char *in_ECX;
  char *pcVar3;
  char *pcVar4;
  char local_88 [64];
  char local_48 [68];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)local_88;
  if ((in_ECX == (char *)0x0) ||
     (iVar2 = GetODFDouble(in_ECX,param_1,param_2,(double *)param_3,
                           (double)CONCAT44(param_5,param_4)), iVar2 == 0)) {
    memset(local_88,0,0x40);
    pcVar3 = in_ECX;
    do {
      pcVar4 = pcVar3;
      pcVar3 = pcVar4 + 1;
    } while (*pcVar4 != '\0');
    iVar2 = _stricmp(pcVar4 + -4,".odf");
    if (iVar2 == 0) {
      pcVar3 = "";
      pcVar4 = in_ECX;
    }
    else {
      pcVar4 = ".odf";
      pcVar3 = in_ECX;
    }
    CombineStrings(local_88,pcVar3,pcVar4,0x40);
    memset(local_48,0,0x40);
    while (bVar1 = OpenODF2(local_88), bVar1) {
      iVar2 = GetODFDouble(local_88,param_1,param_2,(double *)param_3,
                           (double)CONCAT44(param_5,param_4));
      if (iVar2 != 0) goto LAB_4fc06406;
      iVar2 = GetODFString(local_88,"GameObjectClass","classlabel",0x40,local_48,(char *)0x0);
      if (iVar2 == 0) break;
      CombineStrings(local_48,local_48,".odf",0x40);
      iVar2 = _stricmp(local_88,local_48);
      if (iVar2 == 0) break;
      strcpy_s(local_88,0x40,local_48);
    }
    iVar2 = 0;
  }
  else {
LAB_4fc06406:
    iVar2 = 1;
  }
  return iVar2;
}


// ---------------------------------------------------------------------
// GetODFChar  @ 4fc06528  lines 4482-4510

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl GetODFChar(char *file1,char *file2,char *block,char *name,char *value,char defval)

{
  bool bVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  char *local_90;
  char *local_8c;
  char *local_88;
  char local_84 [64];
  char local_44 [64];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)&local_90;
  local_90 = block;
  local_8c = name;
  local_88 = value;
  if (((file1 != (char *)0x0) && (iVar2 = GetODFChar(file1,block,name,value,defval), iVar2 != 0)) ||
     ((file2 != (char *)0x0 &&
      (iVar2 = GetODFChar(file2,local_90,local_8c,local_88,defval), iVar2 != 0)))) {
    return 1;
  }
  memset(local_84,0,0x40);
  pcVar4 = file1;
  pcVar3 = file2;
  if (file2 == (char *)0x0) {
    do {
      pcVar3 = pcVar4;
      pcVar4 = pcVar3 + 1;
    } while (*pcVar3 != '\0');
    iVar2 = _stricmp(pcVar3 + -4,".odf");
    if (iVar2 == 0) {
      pcVar4 = "";
      file2 = file1;
      goto LAB_4fc0662c;
    }
  }
  else {
    do {
      pcVar4 = pcVar3;
      pcVar3 = pcVar4 + 1;
    } while (*pcVar4 != '\0');
    iVar2 = _stricmp(pcVar4 + -4,".odf");
    file1 = file2;
    if (iVar2 == 0) {
      pcVar4 = "";
      goto LAB_4fc0662c;
    }
  }
  file2 = ".odf";
  pcVar4 = file1;
LAB_4fc0662c:
  CombineStrings(local_84,pcVar4,file2,0x40);
  memset(local_44,0,0x40);
  bVar1 = OpenODF2(local_84);
  pcVar3 = local_8c;
  pcVar4 = local_90;
  if (bVar1) {
    do {
      iVar2 = GetODFChar(local_84,pcVar4,pcVar3,local_88,defval);
      if (iVar2 != 0) {
        return 1;
      }
      iVar2 = GetODFString(local_84,"GameObjectClass","classlabel",0x40,local_44,(char *)0x0);
      if (iVar2 == 0) {
        return 0;
      }
      CombineStrings(local_44,local_44,".odf",0x40);
      iVar2 = _stricmp(local_84,local_44);
      if (iVar2 == 0) {
        return 0;
      }
      strcpy_s(local_84,0x40,local_44);
      bVar1 = OpenODF2(local_84);
    } while (bVar1);
  }
  return 0;
}


// ---------------------------------------------------------------------
// GetODFBool  @ 4fc06710  lines 4512-4540

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl GetODFBool(char *file1,char *file2,char *block,char *name,bool *value,bool defval)

{
  bool bVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  char *local_90;
  char *local_8c;
  bool *local_88;
  char local_84 [64];
  char local_44 [64];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)&local_90;
  local_90 = block;
  local_8c = name;
  local_88 = value;
  if (((file1 != (char *)0x0) && (iVar2 = GetODFBool(file1,block,name,value,defval), iVar2 != 0)) ||
     ((file2 != (char *)0x0 &&
      (iVar2 = GetODFBool(file2,local_90,local_8c,local_88,defval), iVar2 != 0)))) {
    return 1;
  }
  memset(local_84,0,0x40);
  pcVar4 = file1;
  pcVar3 = file2;
  if (file2 == (char *)0x0) {
    do {
      pcVar3 = pcVar4;
      pcVar4 = pcVar3 + 1;
    } while (*pcVar3 != '\0');
    iVar2 = _stricmp(pcVar3 + -4,".odf");
    if (iVar2 == 0) {
      pcVar4 = "";
      file2 = file1;
      goto LAB_4fc06814;
    }
  }
  else {
    do {
      pcVar4 = pcVar3;
      pcVar3 = pcVar4 + 1;
    } while (*pcVar4 != '\0');
    iVar2 = _stricmp(pcVar4 + -4,".odf");
    file1 = file2;
    if (iVar2 == 0) {
      pcVar4 = "";
      goto LAB_4fc06814;
    }
  }
  file2 = ".odf";
  pcVar4 = file1;
LAB_4fc06814:
  CombineStrings(local_84,pcVar4,file2,0x40);
  memset(local_44,0,0x40);
  bVar1 = OpenODF2(local_84);
  pcVar3 = local_8c;
  pcVar4 = local_90;
  if (bVar1) {
    do {
      iVar2 = GetODFBool(local_84,pcVar4,pcVar3,local_88,defval);
      if (iVar2 != 0) {
        return 1;
      }
      iVar2 = GetODFString(local_84,"GameObjectClass","classlabel",0x40,local_44,(char *)0x0);
      if (iVar2 == 0) {
        return 0;
      }
      CombineStrings(local_44,local_44,".odf",0x40);
      iVar2 = _stricmp(local_84,local_44);
      if (iVar2 == 0) {
        return 0;
      }
      strcpy_s(local_84,0x40,local_44);
      bVar1 = OpenODF2(local_84);
    } while (bVar1);
  }
  return 0;
}


// ---------------------------------------------------------------------
// GetODFString  @ 4fc068f8  lines 4542-4570

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl
GetODFString(char *file1,char *file2,char *block,char *name,uint ValueLen,char *value,char *defval)

{
  bool bVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  code *pcVar5;
  char *local_94;
  char *local_90;
  char *local_8c;
  char *local_88;
  char local_84 [64];
  char local_44 [64];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)&local_94;
  local_94 = block;
  local_8c = name;
  local_90 = value;
  local_88 = defval;
  if (((file1 != (char *)0x0) &&
      (iVar2 = GetODFString(file1,block,name,ValueLen,value,defval), iVar2 != 0)) ||
     ((file2 != (char *)0x0 &&
      (iVar2 = GetODFString(file2,local_94,local_8c,ValueLen,local_90,defval), iVar2 != 0)))) {
    return 1;
  }
  memset(local_84,0,0x40);
  pcVar5 = _stricmp_exref;
  pcVar4 = file1;
  pcVar3 = file2;
  if (file2 == (char *)0x0) {
    do {
      pcVar3 = pcVar4;
      pcVar4 = pcVar3 + 1;
    } while (*pcVar3 != '\0');
    iVar2 = _stricmp(pcVar3 + -4,".odf");
    pcVar5 = _stricmp_exref;
    if (iVar2 == 0) {
      pcVar4 = "";
      file2 = file1;
      goto LAB_4fc06a13;
    }
  }
  else {
    do {
      pcVar4 = pcVar3;
      pcVar3 = pcVar4 + 1;
    } while (*pcVar4 != '\0');
    iVar2 = _stricmp(pcVar4 + -4,".odf");
    file1 = file2;
    if (iVar2 == 0) {
      pcVar4 = "";
      goto LAB_4fc06a13;
    }
  }
  file2 = ".odf";
  pcVar4 = file1;
LAB_4fc06a13:
  CombineStrings(local_84,pcVar4,file2,0x40);
  memset(local_44,0,0x40);
  bVar1 = OpenODF2(local_84);
  pcVar4 = local_94;
  if (bVar1) {
    do {
      iVar2 = GetODFString(local_84,pcVar4,local_8c,ValueLen,local_90,local_88);
      if (iVar2 != 0) {
        return 1;
      }
      iVar2 = GetODFString(local_84,"GameObjectClass","classlabel",0x40,local_44,(char *)0x0);
      if (iVar2 == 0) {
        return 0;
      }
      CombineStrings(local_44,local_44,".odf",0x40);
      iVar2 = (*pcVar5)(local_84,local_44);
      if (iVar2 == 0) {
        return 0;
      }
      strcpy_s(local_84,0x40,local_44);
      bVar1 = OpenODF2(local_84);
    } while (bVar1);
  }
  return 0;
}


// ---------------------------------------------------------------------
// GetODFColor  @ 4fc06af2  lines 4572-4600

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl GetODFColor(char *file1,char *file2,char *block,char *name,ulong *value,ulong defval)

{
  bool bVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  char *local_90;
  char *local_8c;
  ulong *local_88;
  char local_84 [64];
  char local_44 [64];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)&local_90;
  local_90 = block;
  local_8c = name;
  local_88 = value;
  if (((file1 != (char *)0x0) && (iVar2 = GetODFColor(file1,block,name,value,defval), iVar2 != 0))
     || ((file2 != (char *)0x0 &&
         (iVar2 = GetODFColor(file2,local_90,local_8c,local_88,defval), iVar2 != 0)))) {
    return 1;
  }
  memset(local_84,0,0x40);
  pcVar4 = file1;
  pcVar3 = file2;
  if (file2 == (char *)0x0) {
    do {
      pcVar3 = pcVar4;
      pcVar4 = pcVar3 + 1;
    } while (*pcVar3 != '\0');
    iVar2 = _stricmp(pcVar3 + -4,".odf");
    if (iVar2 == 0) {
      pcVar4 = "";
      file2 = file1;
      goto LAB_4fc06bf6;
    }
  }
  else {
    do {
      pcVar4 = pcVar3;
      pcVar3 = pcVar4 + 1;
    } while (*pcVar4 != '\0');
    iVar2 = _stricmp(pcVar4 + -4,".odf");
    file1 = file2;
    if (iVar2 == 0) {
      pcVar4 = "";
      goto LAB_4fc06bf6;
    }
  }
  file2 = ".odf";
  pcVar4 = file1;
LAB_4fc06bf6:
  CombineStrings(local_84,pcVar4,file2,0x40);
  memset(local_44,0,0x40);
  bVar1 = OpenODF2(local_84);
  pcVar3 = local_8c;
  pcVar4 = local_90;
  if (bVar1) {
    do {
      iVar2 = GetODFColor(local_84,pcVar4,pcVar3,local_88,defval);
      if (iVar2 != 0) {
        return 1;
      }
      iVar2 = GetODFString(local_84,"GameObjectClass","classlabel",0x40,local_44,(char *)0x0);
      if (iVar2 == 0) {
        return 0;
      }
      CombineStrings(local_44,local_44,".odf",0x40);
      iVar2 = _stricmp(local_84,local_44);
      if (iVar2 == 0) {
        return 0;
      }
      strcpy_s(local_84,0x40,local_44);
      bVar1 = OpenODF2(local_84);
    } while (bVar1);
  }
  return 0;
}


// ---------------------------------------------------------------------
// GetODFVector  @ 4fc06cda  lines 4602-4630

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl GetODFVector(char *file1,char *file2,char *block,char *name,Vector *value,Vector defval)

{
  bool bVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  code *pcVar5;
  char *local_90;
  Vector *local_8c;
  char *local_88;
  char local_84 [64];
  char local_44 [64];
  uint local_4;
  
  local_4 = __security_cookie ^ (uint)&local_90;
  local_90 = block;
  local_88 = name;
  local_8c = value;
  if (((file1 != (char *)0x0) && (iVar2 = GetODFVector(file1,block,name,value,defval), iVar2 != 0))
     || ((file2 != (char *)0x0 &&
         (iVar2 = GetODFVector(file2,local_90,local_88,local_8c,defval), iVar2 != 0)))) {
    return 1;
  }
  memset(local_84,0,0x40);
  pcVar5 = _stricmp_exref;
  pcVar4 = file1;
  pcVar3 = file2;
  if (file2 == (char *)0x0) {
    do {
      pcVar3 = pcVar4;
      pcVar4 = pcVar3 + 1;
    } while (*pcVar3 != '\0');
    iVar2 = _stricmp(pcVar3 + -4,".odf");
    pcVar5 = _stricmp_exref;
    if (iVar2 == 0) {
      pcVar4 = "";
      file2 = file1;
      goto LAB_4fc06dfa;
    }
  }
  else {
    do {
      pcVar4 = pcVar3;
      pcVar3 = pcVar4 + 1;
    } while (*pcVar4 != '\0');
    iVar2 = _stricmp(pcVar4 + -4,".odf");
    file1 = file2;
    if (iVar2 == 0) {
      pcVar4 = "";
      goto LAB_4fc06dfa;
    }
  }
  file2 = ".odf";
  pcVar4 = file1;
LAB_4fc06dfa:
  CombineStrings(local_84,pcVar4,file2,0x40);
  memset(local_44,0,0x40);
  bVar1 = OpenODF2(local_84);
  pcVar4 = local_90;
  if (bVar1) {
    do {
      iVar2 = GetODFVector(local_84,pcVar4,local_88,local_8c,defval);
      if (iVar2 != 0) {
        return 1;
      }
      iVar2 = GetODFString(local_84,"GameObjectClass","classlabel",0x40,local_44,(char *)0x0);
      if (iVar2 == 0) {
        return 0;
      }
      CombineStrings(local_44,local_44,".odf",0x40);
      iVar2 = (*pcVar5)(local_84,local_44);
      if (iVar2 == 0) {
        return 0;
      }
      strcpy_s(local_84,0x40,local_44);
      bVar1 = OpenODF2(local_84);
    } while (bVar1);
  }
  return 0;
}


// ---------------------------------------------------------------------
// GetBuildItem  @ 4fc06ee9  lines 4635-4775

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
  int fmtarg1;
  uint unaff_ESI;
  char *unaff_EDI;
  int iVar5;
  char *pcVar6;
  uint local_210;
  int local_20c;
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
  
  local_4 = __security_cookie ^ (uint)&local_210;
  local_20c = in_ECX;
  local_208 = in_EDX;
  memset(local_c4,0,0x40);
  bVar1 = GetObjInfo(in_ECX,Get_GOClass,local_c4);
  if (bVar1) {
    uVar2 = Hash(unaff_EDI,unaff_ESI);
    local_210 = 0;
    if (param_3 != (int *)0x0) {
      local_210 = Hash(unaff_EDI,unaff_ESI);
    }
    if ((((uVar2 == 0x63ae241a) || (uVar2 == 0xe39ee1ae)) || (uVar2 == 0x8a0a1ead)) ||
       ((uVar2 == 0x77f02e21 || (uVar2 == 0x2418efcf)))) {
      iVar5 = 0;
      do {
        memset(local_1c4,0,0x40);
        if (uVar2 == 0x63ae241a) {
          if (iVar5 == 0) {
            pcVar6 = "ArmoryClass";
            goto LAB_4fc06fea;
          }
          pcVar6 = "ArmoryGroup%d";
LAB_4fc06ffe:
          sprintf_s<64>(&local_1c4,pcVar6);
        }
        else {
          if (iVar5 != 0) {
            pcVar6 = "BuildGroup%d";
            goto LAB_4fc06ffe;
          }
          if (uVar2 == 0x77f02e21) {
            pcVar6 = "ConstructionRigClass";
          }
          else {
            pcVar6 = "ConstructionRigTClass";
            if (uVar2 != 0x2418efcf) {
              pcVar6 = "FactoryClass";
            }
          }
LAB_4fc06fea:
          sprintf_s<64>(&local_1c4,pcVar6);
        }
        fmtarg1 = 0;
        do {
          memset(local_104,0,0x40);
          memset(local_184,0,0x40);
          memset(local_204,0,0x40);
          memset(local_144,0,0x40);
          memset(local_44,0,0x40);
          memset(local_84,0,0x40);
          fmtarg1 = fmtarg1 + 1;
          sprintf_s<64>(&local_84,"buildItem%d",fmtarg1);
          iVar3 = GetODFString(local_20c,local_1c4,local_84,0x40,local_104,(char *)0x0);
          if ((iVar3 != 0) && (local_104[0] != '\0')) {
            CombineStrings(local_184,local_104,".odf",0x40);
            bVar1 = OpenODF2(local_184);
            if ((bVar1) &&
               (iVar3 = GetODFString(local_184,"GameObjectClass","classlabel",0x40,local_144,
                                     (char *)0x0), iVar3 != 0)) {
              CombineStrings(local_204,local_144,".odf",0x40);
              bVar1 = OpenODF2(local_204);
              if (bVar1) {
                GetODFString(local_204,"GameObjectClass","classlabel",0x40,local_144,(char *)0x0);
              }
              else {
                local_204[0] = '\0';
              }
            }
            GetODFString(local_184,local_204,"WeaponPowerupClass","weaponName",0x40,local_44,
                         (char *)0x0);
            if ((((((uint)param_2 & 1) != 0) && ((uVar2 == 0x4b970310 || (uVar2 == 0x33fe0a68)))) ||
                ((((uint)param_2 & 2) != 0 && ((uVar2 == 0xa662aa60 || (uVar2 == 0x33fe0a68)))))) ||
               ((((uint)param_2 & 4) != 0 &&
                ((param_3 != (int *)0x0 && (uVar4 = Hash(unaff_EDI,unaff_ESI), uVar4 == local_210)))
                ))) {
              GetODFInt(local_184,local_204,"GameObjectClass","scrapCost",(int *)0x0,0);
              strcpy_s(local_208,0x40,local_104);
              return true;
            }
          }
        } while (fmtarg1 < 10);
        iVar5 = iVar5 + 1;
      } while (iVar5 < 0xb);
    }
  }
  return false;
}


// ---------------------------------------------------------------------
// ReplaceWeapons  @ 4fc07248  lines 4780-5059

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool __cdecl
ReplaceWeapons(int h,char (*NewWeapons) [64],float *PreviousLocalAmmo,char *PreviousODF)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  uint uVar5;
  char *pcVar6;
  char cVar7;
  int iVar8;
  uint unaff_ESI;
  char *unaff_EDI;
  int iVar9;
  float fVar10;
  undefined1 auStack_70c [7];
  char local_705;
  code *local_704;
  char (*local_700) [64];
  char *local_6fc;
  int local_6f4;
  code *local_6f0;
  int local_6ec;
  uint local_6e8 [25];
  float local_684 [4];
  char cStack_674;
  char cStack_673;
  char cStack_672;
  char acStack_671 [8];
  bool bStack_669;
  char local_668 [8];
  bool local_660 [8];
  char local_658 [8];
  char local_650 [64];
  char local_610 [64];
  char local_5d0 [64];
  char local_590 [7];
  byte local_589;
  byte local_550 [64];
  char local_510 [7];
  byte local_509;
  byte local_4d0 [64];
  char local_490 [64];
  char local_450 [64];
  char local_410 [64];
  char local_3d0 [256];
  char local_2d0 [64];
  char local_290 [256];
  char local_190 [64];
  char local_150 [324];
  uint local_c;
  
  local_c = __security_cookie ^ (uint)auStack_70c;
  local_6fc = PreviousODF;
  local_6ec = 0;
  local_700 = NewWeapons;
  local_6f4 = h;
  memset(local_410,0,0x40);
  local_6f0 = GetObjInfo_exref;
  bVar1 = GetObjInfo(h,Get_ODF,local_410);
  if (!bVar1) {
    return false;
  }
  iVar2 = GetVarItemInt("network.session.ivar115");
  if (iVar2 == 0) {
    iVar2 = GetVarItemInt("network.session.civar5");
    local_705 = '\0';
    if (iVar2 == 0) goto LAB_4fc072d9;
  }
  local_705 = '\x01';
LAB_4fc072d9:
  memset(local_650,0,0x40);
  pcVar4 = local_410;
  if (local_6fc != (char *)0x0) {
    pcVar4 = local_6fc;
  }
  CombineStrings(local_650,"",pcVar4,0x40);
  CheckODFName(local_650);
  if (local_705 != '\0') {
    FormatLogMessage("Replace Weapons: ODF: %s NewWeapons: \'%s\' \'%s\' \'%s\' \'%s\' \'%s\'",
                     local_650,*NewWeapons,NewWeapons[1],NewWeapons[2],NewWeapons[3],NewWeapons[4]);
  }
  CombineStrings(local_650,local_650,".odf",0x40);
  memset(local_3d0,0,0x140);
  local_660[0] = false;
  local_660[1] = false;
  local_660[2] = false;
  local_660[3] = false;
  local_660[4] = false;
  local_6e8[0x14] = 0;
  local_6e8[0x15] = 0;
  local_6e8[0x16] = 0;
  local_6e8[0x17] = 0;
  local_6e8[0x18] = 0;
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
  local_668[0] = '\0';
  local_668[1] = '\0';
  local_668[2] = '\0';
  local_668[3] = '\0';
  local_668[4] = 0;
  local_6e8[0xf] = 0;
  acStack_671[1] = '\0';
  acStack_671[2] = '\0';
  acStack_671[3] = '\0';
  acStack_671[4] = '\0';
  acStack_671[5] = 0;
  local_6e8[0x10] = 0;
  local_6e8[0x11] = 0;
  local_6e8[0x12] = 0;
  local_6e8[0x13] = 0;
  local_6e8[5] = 0;
  local_6e8[6] = 0;
  local_6e8[7] = 0;
  local_6e8[8] = 0;
  local_6e8[9] = 0;
  local_6e8[10] = 0;
  local_6e8[0xb] = 0;
  local_6e8[0xc] = 0;
  local_6e8[0xd] = 0;
  local_6e8[0xe] = 0;
  memset(local_550,0,0x40);
  memset(local_490,0,0x40);
  memset(local_4d0,0,0x40);
  bVar1 = OpenODF2(local_650);
  local_704 = GetODFString_exref;
  if (bVar1) {
    memset(local_5d0,0,0x40);
    iVar2 = (*local_704)(local_650,"GameObjectClass","classlabel",0x40,local_5d0,0);
    if (iVar2 != 0) {
      CombineStrings((char *)local_550,local_5d0,".odf",0x40);
      bVar1 = OpenODF2((char *)local_550);
      local_550[0] = local_550[0] & -bVar1;
    }
    local_6fc = (char *)0x5;
    iVar9 = 1;
    iVar2 = 0;
    do {
      memset(local_590,0,0x40);
      memset(local_610,0,0x40);
      sprintf_s<64>(&local_610,"weaponHard%d",iVar9);
      iVar3 = GetODFString(local_650,(char *)local_550,"GameObjectClass",local_610,0x40,local_590,
                           (char *)0x0);
      if (iVar3 == 0) {
LAB_4fc075d3:
        sprintf_s<64>(&local_610,"weaponAssault%d",iVar9);
        GetODFBool(local_650,(char *)local_550,"GameObjectClass",local_610,&bStack_669 + iVar9,false
                  );
        sprintf_s<64>(&local_610,"weaponGroup%d",iVar9);
        iVar3 = GetODFInt(local_650,(char *)local_550,"GameObjectClass",local_610,
                          (int *)((int)local_6e8 + iVar2 + 0x28),0);
        if (iVar3 != 0) {
          acStack_671[iVar9] = '\x01';
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
          uVar5 = Hash(unaff_EDI,unaff_ESI);
          *(uint *)((int)local_6e8 + iVar2 + 0x14) = uVar5;
          goto LAB_4fc075d3;
        }
      }
      iVar9 = iVar9 + 1;
      iVar2 = iVar2 + 4;
      local_6fc = (char *)((int)local_6fc + -1);
    } while (local_6fc != (char *)0x0);
    local_6fc = (char *)0x0;
    NewWeapons = local_700;
  }
  bVar1 = OpenODF2(local_410);
  if (bVar1) {
    pcVar4 = (char *)0x0;
    do {
      memset(local_510,0,0x40);
      memset(local_5d0,0,0x40);
      local_6fc = pcVar4 + 1;
      sprintf_s<64>(&local_5d0,"weaponHard%d",(int)local_6fc);
      iVar2 = GetODFString(local_6f4,"GameObjectClass",local_5d0,0x40,local_510,(char *)0x0);
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
        uVar5 = Hash(unaff_EDI,unaff_ESI);
        local_6e8[(int)(pcVar4 + 0xf)] = uVar5;
      }
      NewWeapons = local_700;
      pcVar4 = local_6fc;
    } while ((int)local_6fc < 5);
  }
  iVar2 = 0;
  do {
    if (*(int *)((int)local_6e8 + iVar2 + 0x14) != *(int *)((int)local_6e8 + iVar2 + 0x3c)) {
      return false;
    }
    iVar2 = iVar2 + 4;
  } while (iVar2 < 0x14);
  iVar2 = 0;
  local_700 = (char (*) [64])0x0;
  do {
    local_6fc = local_3d0 + (int)local_700;
    CombineStrings(local_6fc,"",local_6fc + ((int)NewWeapons - (int)local_3d0),0x40);
    if (PreviousLocalAmmo == (float *)0x0) {
      fVar10 = 1e+06;
    }
    else {
      fVar10 = PreviousLocalAmmo[iVar2];
    }
    local_684[iVar2] = fVar10;
    CombineStrings(local_490,local_6fc,".odf",0x40);
    bVar1 = OpenODF2(local_490);
    if (bVar1) {
      memset(local_5d0,0,0x40);
      iVar9 = (*local_704)(local_490,"WeaponClass","classlabel",0x40,local_5d0,0);
      if (iVar9 != 0) {
        CombineStrings((char *)local_4d0,local_5d0,".odf",0x40);
        bVar1 = OpenODF2((char *)local_4d0);
        local_4d0[0] = local_4d0[0] & -bVar1;
      }
      GetODFBool(local_490,(char *)local_4d0,"WeaponClass","isAssault",local_660 + iVar2,false);
      GetODFString(local_490,(char *)local_4d0,"WeaponClass","altName",0x40,
                   local_150 + (int)local_700,(char *)0x0);
      memset(local_450,0,0x40);
      iVar9 = GetODFString(local_490,(char *)local_4d0,"WeaponClass","wpnCategory",0x40,local_450,
                           (char *)0x0);
      if (iVar9 != 0) {
        memset(local_610,0,0x40);
        sprintf_s<64>(&local_610,local_450);
        CombineStrings(local_450,"HP_",local_610,0x40);
        uVar5 = Hash(unaff_EDI,unaff_ESI);
        local_6e8[iVar2 + 0x14] = uVar5;
      }
    }
    iVar9 = local_6f4;
    iVar2 = iVar2 + 1;
    local_700 = (char (*) [64])((int)local_700 + 0x40);
  } while ((int)local_700 < 0x140);
  iVar2 = 0;
  pcVar4 = local_290;
  do {
    (*local_6f0)(iVar9,iVar2 + 5,pcVar4);
    pcVar4 = pcVar4 + 0x40;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 5);
  iVar2 = 0;
  do {
    iVar9 = 0;
    local_704 = (code *)0x0;
    do {
      if (((local_6e8[iVar2 + 5] != 0) && (local_6e8[iVar9 + 5] != 0)) &&
         (local_6e8[iVar2 + 5] == local_6e8[iVar9 + 5])) {
        cVar7 = acStack_671[iVar2 + 1];
        local_700 = (char (*) [64])local_150;
        local_6fc = (char *)0x0;
        do {
          if (((cVar7 == '\0') && (local_6fc[(int)(acStack_671 + 1)] == '\0')) &&
             (local_6e8[iVar9 + 5] == local_6e8[(int)(local_6fc + 5)])) {
            if (((local_668[iVar2] == local_668[(int)local_6fc]) &&
                (0 < (int)local_6e8[(int)local_6fc])) && ((int)local_6fc < iVar2)) {
LAB_4fc07a98:
              if (local_705 == '\0') goto LAB_4fc07ac0;
              pcVar4 = 
              "Assault Matchs, Weapon:%d, CompareWeapon:%d, NumHardTypesS: %d, T < C Skipping S. WeaponClassT: \'%d\'"
              ;
              goto LAB_4fc07ab0;
            }
            if ((((local_660[(int)local_6fc] != false) && ((*local_700)[0] == '\0')) &&
                (iVar9 < (int)local_6fc)) && (local_668[iVar9] == '\0')) {
              iVar3 = _stricmp(local_3d0 + (int)local_704,local_290 + (int)local_704);
              if (iVar3 == 0) goto LAB_4fc07a98;
              cVar7 = acStack_671[iVar2 + 1];
            }
          }
          local_6fc = local_6fc + 1;
          local_700 = (char (*) [64])((int)local_700 + 0x40);
        } while ((int)local_6fc < 5);
        uVar5 = local_6e8[iVar9 + 10];
        if (local_6e8[iVar2 + 10] == uVar5) {
          if (((cVar7 == '\0') && (acStack_671[iVar9 + 1] == '\0')) || (iVar9 != iVar2))
          goto LAB_4fc07afb;
LAB_4fc07b3d:
          local_6e8[iVar2] = local_6e8[iVar2] + 1;
        }
        else {
          if (iVar9 <= iVar2) goto LAB_4fc07b3d;
LAB_4fc07afb:
          if (cVar7 == '\0') {
            if (local_668[iVar2] == local_668[iVar9]) {
              if (((acStack_671[iVar9 + 1] == '\0') && (iVar2 <= iVar9)) &&
                 ((int)local_6e8[iVar2] <= (int)local_6e8[iVar9])) goto LAB_4fc07b3d;
            }
            else if ((acStack_671[iVar9 + 1] == '\0') &&
                    ((int)local_6e8[iVar2] < (int)local_6e8[iVar9])) goto LAB_4fc07b3d;
          }
        }
        if (local_705 != '\0') {
          if (local_6e8[iVar2 + 10] == uVar5) {
            if (((cVar7 != '\0') || (acStack_671[iVar9 + 1] != '\0')) && (iVar9 == iVar2))
            goto LAB_4fc07baa;
          }
          else if (iVar9 <= iVar2) {
LAB_4fc07baa:
            FormatLogMessage("Using Groups, Groups Dont Match, S<C, or We are Ourselves, Weapon:%d, CompareWeapon:%d"
                             ,iVar2,iVar9);
            goto LAB_4fc07ac0;
          }
          if (local_668[iVar2] == local_668[iVar9]) {
            if (((cVar7 == '\0') && (acStack_671[iVar9 + 1] == '\0')) && (iVar2 <= iVar9)) {
              pcVar4 = 
              "Assault Matchs, Weapon:%d, CompareWeapon:%d, NumHardTypesS: %d, NumHardTypesC: %d";
              goto LAB_4fc07ab0;
            }
          }
          else if (((cVar7 == '\0') && (acStack_671[iVar9 + 1] == '\0')) &&
                  ((int)local_6e8[iVar2] < (int)local_6e8[iVar9])) {
            pcVar4 = 
            "Assault NOT Matches,Weapon:%d, CompareWeapon:%d, NumHardTypesC: %d < NumHardTypesS: %d"
            ;
LAB_4fc07ab0:
            FormatLogMessage(pcVar4);
          }
        }
      }
LAB_4fc07ac0:
      local_704 = (code *)((int)local_704 + 0x40);
      iVar9 = iVar9 + 1;
    } while ((int)local_704 < 0x140);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 5);
  iVar2 = 0;
  local_700 = (char (*) [64])0x0;
  do {
    local_704 = (code *)0x0;
    uVar5 = local_6e8[iVar2 + 5];
    iVar9 = (int)local_704;
    do {
      if (local_705 == '\0') {
LAB_4fc07c36:
        if ((((((uVar5 != 0) && (local_6e8[iVar9 + 5] != 0)) && (uVar5 == local_6e8[iVar9 + 5])) &&
             (uVar5 == local_6e8[iVar2 + 0x14])) &&
            ((iVar2 != iVar9 ||
             (iVar3 = _stricmp(local_3d0 + (int)local_700,local_290 + (int)local_700), iVar3 != 0)))
            ) && ((iVar3 = _stricmp(local_3d0 + (int)local_700,local_290 + (int)local_700),
                  iVar3 != 0 ||
                  ((0 < iVar9 &&
                   (iVar3 = _stricmp(local_3d0 + (int)local_704,local_290 + (int)local_704),
                   iVar3 != 0)))))) {
          if (local_705 != '\0') {
            FormatLogMessage("Build Weapons C: Weapon Class C: %d is: \'%d\', Weapon Class S: %d Is: \'%d\'"
                             ,iVar2,uVar5,iVar9,local_6e8[iVar9 + 5]);
          }
          local_658[iVar2] = '\x01';
        }
      }
      else if (uVar5 != 0) {
        FormatLogMessage("Weapon Class C: %d is: \'%d\', Weapon Class S: %d Is: \'%d\'",iVar2,uVar5,
                         iVar9,local_6e8[iVar9 + 5]);
        goto LAB_4fc07c36;
      }
      iVar3 = local_6f4;
      local_704 = (code *)((int)local_704 + 0x40);
      iVar9 = iVar9 + 1;
    } while ((int)local_704 < 0x140);
    iVar2 = iVar2 + 1;
    local_700 = (char (*) [64])((int)local_700 + 0x40);
    iVar9 = 0;
    if (4 < iVar2) {
      iVar2 = 4;
      cVar7 = local_705;
      do {
        if ((cVar7 != '\0') && (local_2d0[iVar9] != '\0')) {
          FormatLogMessage("Index: %d Original Weapon: \'%s\', New Weapon: \'%s\', Number of Hardpoints: %d"
                           ,iVar2,local_190 + iVar9,local_2d0 + iVar9,local_6e8[iVar2]);
          cVar7 = local_705;
        }
        if (((local_2d0[iVar9] != '\0') && (local_658[iVar2] != '\0')) &&
           (GiveWeapon(iVar3,iVar2,local_2d0 + iVar9), cVar7 = local_705, local_705 != '\0')) {
          FormatLogMessage("Giving Weapon: \'%s\', index: %d",local_2d0 + iVar9,iVar2);
          cVar7 = local_705;
        }
        iVar9 = iVar9 + -0x40;
        iVar2 = iVar2 + -1;
        iVar8 = local_6ec;
      } while (-0x140 < iVar9);
      do {
        SetCurLocalAmmo(local_6f4,local_684[iVar8],iVar8);
        iVar8 = iVar8 + 1;
      } while (iVar8 < 5);
      return true;
    }
  } while( true );
}


