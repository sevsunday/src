// Reconstructed by Ghidra from deathmatch01.dll + deathmatch01.pdb
// Original source file: /e:/github/vsr_dll_source/missions/vsrcore/mathutils.cpp
// Functions are ordered by original source line. This is decompiler
// output, not the author's source: names/types come from the PDB,
// local variable names and control flow are reconstructed.


// ---------------------------------------------------------------------
// Cross_Product  @ 4fc12770  lines 10-16


Vector * __cdecl Cross_Product(Vector *__return_storage_ptr__,Vector *param_1,Vector *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  Vector *in_ECX;
  float *in_EDX;
  
  fVar1 = in_EDX[1];
  fVar2 = __return_storage_ptr__->z;
  fVar3 = in_EDX[2];
  fVar4 = __return_storage_ptr__->y;
  in_ECX->x = fVar2 * fVar1 - fVar4 * fVar3;
  fVar5 = __return_storage_ptr__->x;
  fVar6 = *in_EDX;
  in_ECX->y = fVar5 * fVar3 - fVar6 * fVar2;
  in_ECX->z = fVar4 * fVar6 - fVar5 * fVar1;
  return in_ECX;
}


// ---------------------------------------------------------------------
// Build_Directinal_Matrix  @ 4fc127af  lines 20-52


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

Matrix * __cdecl
Build_Directinal_Matrix(Matrix *__return_storage_ptr__,Vector *param_1,Vector *param_2)

{
  float fVar1;
  float fVar2;
  Vector *pVVar3;
  Vector *pVVar4;
  Matrix *in_ECX;
  float *in_EDX;
  Vector *unaff_ESI;
  Vector *unaff_EDI;
  
  (in_ECX->posit).x = *in_EDX;
  (in_ECX->posit).y = in_EDX[1];
  (in_ECX->posit).z = in_EDX[2];
  in_ECX->positw = 1.0;
  pVVar3 = Normalize_Vector(unaff_EDI,unaff_ESI);
  pVVar4 = &in_ECX->front;
  pVVar4->x = pVVar3->x;
  (in_ECX->front).y = pVVar3->y;
  (in_ECX->front).z = pVVar3->z;
  fVar1 = (in_ECX->front).z;
  fVar2 = pVVar4->x;
  in_ECX->frontw = 0.0;
  if ((float)___real_3f947ae147ae147b <= fVar1 * fVar1 + fVar2 * fVar2) {
    (in_ECX->up).z = 0.0;
    (in_ECX->up).x = 0.0;
    (in_ECX->up).y = 1.0;
    pVVar4 = Cross_Product(pVVar4,unaff_EDI,unaff_ESI);
    (in_ECX->right).x = pVVar4->x;
    (in_ECX->right).y = pVVar4->y;
    (in_ECX->right).z = pVVar4->z;
    pVVar4 = Normalize_Vector(unaff_EDI,unaff_ESI);
    (in_ECX->right).x = pVVar4->x;
    (in_ECX->right).y = pVVar4->y;
    (in_ECX->right).z = pVVar4->z;
  }
  else {
    (in_ECX->right).y = 0.0;
    (in_ECX->right).z = 0.0;
    (in_ECX->right).x = 1.0;
  }
  in_ECX->rightw = 0.0;
  pVVar4 = Cross_Product(&in_ECX->right,unaff_EDI,unaff_ESI);
  (in_ECX->up).x = pVVar4->x;
  (in_ECX->up).y = pVVar4->y;
  (in_ECX->up).z = pVVar4->z;
  in_ECX->upw = 0.0;
  return in_ECX;
}


// ---------------------------------------------------------------------
// Normalize_Vector  @ 4fc1286c  lines 56-65


Vector * __cdecl Normalize_Vector(Vector *__return_storage_ptr__,Vector *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  Vector *in_ECX;
  float *in_EDX;
  float10 fVar5;
  
  fVar1 = in_EDX[1];
  fVar2 = *in_EDX;
  fVar3 = in_EDX[2];
  fVar5 = (float10)__CIsqrt();
  fVar4 = 1.0 / (float)fVar5;
  in_ECX->x = fVar4 * fVar2;
  in_ECX->y = fVar4 * fVar1;
  in_ECX->z = fVar4 * fVar3;
  return in_ECX;
}


// ---------------------------------------------------------------------
// Interpolate_Quaternion  @ 4fc128cd  lines 74-127


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

Quaternion * __cdecl
Interpolate_Quaternion
          (Quaternion *__return_storage_ptr__,Quaternion *param_1,Quaternion *param_2,float param_3)

{
  Quaternion *in_ECX;
  float *in_EDX;
  float10 fVar1;
  float10 fVar2;
  float10 fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  
  fVar5 = (__return_storage_ptr__->v).x;
  fVar6 = __return_storage_ptr__->s;
  fVar4 = (__return_storage_ptr__->v).y;
  fVar7 = (__return_storage_ptr__->v).z;
  fVar3 = (float10)in_EDX[3] * (float10)fVar7 +
          (float10)fVar4 * (float10)in_EDX[2] +
          (float10)*in_EDX * (float10)fVar6 + (float10)fVar5 * (float10)in_EDX[1];
  if (fVar3 < (float10)0) {
    fVar3 = -fVar3;
    fVar4 = (float)((uint)fVar4 ^ __xmm_80000000800000008000000080000000);
    fVar5 = (float)((uint)fVar5 ^ __xmm_80000000800000008000000080000000);
    fVar6 = (float)((uint)fVar6 ^ __xmm_80000000800000008000000080000000);
    fVar7 = (float)((uint)fVar7 ^ __xmm_80000000800000008000000080000000);
  }
  fVar1 = (float10)(float)param_1;
  (in_ECX->v).z = fVar7;
  in_ECX->s = fVar6;
  (in_ECX->v).x = fVar5;
  (in_ECX->v).y = fVar4;
  fVar2 = (float10)1 - fVar1;
  if ((float10)___real_3f50624de0000000 < (float10)1 - fVar3) {
    __CIacos();
    fVar3 = (float10)__CIsin();
    fVar2 = (float10)__CIsin();
    fVar1 = (float10)__CIsin();
    fVar1 = fVar1 * (float10)(double)((float10)1 / fVar3);
    fVar2 = (float10)(double)(fVar2 * (float10)(double)((float10)1 / fVar3));
  }
  in_ECX->s = (float)((float10)*in_EDX * fVar2 + (float10)in_ECX->s * fVar1);
  (in_ECX->v).x = (float)((float10)in_EDX[1] * fVar2 + (float10)(in_ECX->v).x * fVar1);
  (in_ECX->v).y = (float)((float10)(in_ECX->v).y * fVar1 + (float10)in_EDX[2] * fVar2);
  (in_ECX->v).z = (float)(fVar1 * (float10)(in_ECX->v).z + (float10)in_EDX[3] * fVar2);
  return in_ECX;
}


// ---------------------------------------------------------------------
// Normalize_Quaternion  @ 4fc12a12  lines 130-148


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

Quaternion * __cdecl Normalize_Quaternion(Quaternion *__return_storage_ptr__,Quaternion *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  Quaternion *in_ECX;
  float *in_EDX;
  float10 fVar5;
  
  fVar1 = in_EDX[1];
  fVar2 = *in_EDX;
  fVar3 = in_EDX[2];
  fVar4 = in_EDX[3];
  if (fVar4 * fVar4 + fVar3 * fVar3 + fVar1 * fVar1 + fVar2 * fVar2 == 0.0) {
    fVar5 = (float10)___real_408f3fffe0000000;
  }
  else {
    fVar5 = (float10)__CIsqrt();
    fVar5 = (float10)1 / fVar5;
  }
  in_ECX->s = (float)((float10)fVar2 * fVar5);
  (in_ECX->v).x = (float)((float10)fVar1 * fVar5);
  (in_ECX->v).y = (float)((float10)fVar3 * fVar5);
  (in_ECX->v).z = (float)(fVar5 * (float10)fVar4);
  return in_ECX;
}


// ---------------------------------------------------------------------
// Matrix_to_QuatPos  @ 4fc12aa3  lines 154-191


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl Matrix_to_QuatPos(Matrix *param_1,Quaternion *param_2,Vector *param_3)

{
  uint uVar1;
  uint uVar2;
  float fVar3;
  float *in_ECX;
  float *in_EDX;
  uint uVar4;
  float10 fVar5;
  
  if (*in_ECX + in_ECX[5] + in_ECX[10] <= 0.0) {
    uVar4 = (uint)(*in_ECX < in_ECX[5]);
    if (in_ECX[uVar4 * 5] < in_ECX[10]) {
      uVar4 = 2;
    }
    uVar1 = next[uVar4];
    uVar2 = next[uVar1];
    fVar5 = (float10)__CIsqrt();
    fVar3 = (float)___real_3fe0000000000000;
    in_EDX[uVar4 + 1] = (float)fVar5 * fVar3;
    fVar3 = fVar3 / (float)fVar5;
    *in_EDX = (in_ECX[uVar1 + uVar2 * 4] - in_ECX[uVar2 + uVar1 * 4]) * fVar3;
    in_EDX[uVar1 + 1] = (in_ECX[uVar1 * 4 + uVar4] + in_ECX[uVar1 + uVar4 * 4]) * fVar3;
    in_EDX[uVar2 + 1] = (in_ECX[uVar2 * 4 + uVar4] + in_ECX[uVar2 + uVar4 * 4]) * fVar3;
  }
  else {
    fVar5 = (float10)__CIsqrt();
    fVar3 = (float)___real_3fe0000000000000;
    *in_EDX = (float)fVar5 * fVar3;
    fVar3 = fVar3 / (float)fVar5;
    in_EDX[1] = (in_ECX[9] - in_ECX[6]) * fVar3;
    in_EDX[2] = (in_ECX[2] - in_ECX[8]) * fVar3;
    in_EDX[3] = (in_ECX[4] - in_ECX[1]) * fVar3;
  }
  (param_1->right).x = in_ECX[0xc];
  (param_1->right).y = in_ECX[0xd];
  (param_1->right).z = in_ECX[0xe];
  return;
}


// ---------------------------------------------------------------------
// QuatPos_to_Matrix  @ 4fc12be7  lines 211-242


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl QuatPos_to_Matrix(Quaternion *param_1,Vector *param_2,Matrix *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float *in_ECX;
  float *in_EDX;
  
  fVar1 = in_ECX[2];
  fVar2 = in_ECX[1];
  fVar3 = in_ECX[3];
  fVar4 = *in_ECX;
  (param_1->v).z = 0.0;
  fVar7 = (float)___real_4000000000000000 /
          (fVar3 * fVar3 + fVar1 * fVar1 + fVar2 * fVar2 + fVar4 * fVar4);
  fVar5 = fVar7 * fVar1;
  fVar6 = fVar7 * fVar3;
  param_1->s = 1.0 - (fVar5 * fVar1 + fVar6 * fVar3);
  (param_1->v).x = fVar2 * fVar5 - fVar4 * fVar6;
  (param_1->v).y = fVar4 * fVar5 + fVar2 * fVar6;
  param_1[1].s = fVar4 * fVar6 + fVar2 * fVar5;
  fVar8 = fVar2 * fVar7 * fVar2;
  param_1[1].v.z = 0.0;
  param_1[2].v.z = 0.0;
  param_1[1].v.x = 1.0 - (fVar6 * fVar3 + fVar8);
  fVar3 = fVar4 * fVar7 * fVar2;
  param_1[1].v.y = fVar1 * fVar6 - fVar3;
  param_1[2].s = fVar2 * fVar6 - fVar4 * fVar5;
  param_1[2].v.x = fVar1 * fVar6 + fVar3;
  param_1[2].v.y = 1.0 - (fVar8 + fVar5 * fVar1);
  param_1[3].s = *in_EDX;
  param_1[3].v.x = in_EDX[1];
  param_1[3].v.y = in_EDX[2];
  param_1[3].v.z = 1.0;
  return;
}


// ---------------------------------------------------------------------
// Interpolate_Matrix  @ 4fc12d23  lines 247-271


Matrix * __cdecl
Interpolate_Matrix(Matrix *__return_storage_ptr__,Matrix *param_1,Matrix *param_2,float param_3)

{
  Matrix *in_ECX;
  Quaternion *unaff_ESI;
  Quaternion *__return_storage_ptr___00;
  Matrix *pMVar1;
  Vector *in_stack_ffffffb0;
  Quaternion local_2c;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  local_c = 0.0;
  local_8 = 0.0;
  local_10 = 0.0;
  Matrix_to_QuatPos((Matrix *)&local_10,unaff_ESI,in_stack_ffffffb0);
  local_14 = 0.0;
  local_1c = 0.0;
  local_18 = 0.0;
  Matrix_to_QuatPos((Matrix *)&local_1c,unaff_ESI,in_stack_ffffffb0);
  __return_storage_ptr___00 = &local_2c;
  pMVar1 = param_1;
  Interpolate_Quaternion
            (__return_storage_ptr___00,(Quaternion *)param_1,unaff_ESI,(float)in_stack_ffffffb0);
  local_2c.v.x = (local_1c - local_10) * (float)param_1 + local_10;
  local_2c.v.y = (local_18 - local_c) * (float)param_1 + local_c;
  local_2c.v.z = local_8 + (local_14 - local_8) * (float)param_1;
  QuatPos_to_Matrix((Quaternion *)in_ECX,(Vector *)__return_storage_ptr___00,pMVar1);
  return in_ECX;
}


// ---------------------------------------------------------------------
// Vector_Rotate  @ 4fc12dc0  lines 276-284


Vector * __cdecl Vector_Rotate(Vector *__return_storage_ptr__,Matrix *param_1,Vector *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  Vector *in_ECX;
  float *in_EDX;
  
  fVar1 = __return_storage_ptr__->y;
  fVar2 = __return_storage_ptr__->x;
  fVar3 = __return_storage_ptr__->z;
  in_ECX->x = in_EDX[8] * fVar3 + *in_EDX * fVar2 + in_EDX[4] * fVar1;
  in_ECX->y = in_EDX[9] * fVar3 + in_EDX[5] * fVar1 + in_EDX[1] * fVar2;
  in_ECX->z = fVar3 * in_EDX[10] + in_EDX[2] * fVar2 + in_EDX[6] * fVar1;
  return in_ECX;
}


// ---------------------------------------------------------------------
// Vector_TransformInv  @ 4fc12e0f  lines 299-311


Vector * __cdecl Vector_TransformInv(Vector *__return_storage_ptr__,Matrix *param_1,Vector *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  Vector *in_ECX;
  float *in_EDX;
  
  fVar1 = __return_storage_ptr__->y - in_EDX[0xd];
  fVar2 = __return_storage_ptr__->x - in_EDX[0xc];
  fVar3 = __return_storage_ptr__->z - in_EDX[0xe];
  in_ECX->x = in_EDX[2] * fVar3 + *in_EDX * fVar2 + in_EDX[1] * fVar1;
  in_ECX->y = in_EDX[6] * fVar3 + in_EDX[5] * fVar1 + in_EDX[4] * fVar2;
  in_ECX->z = fVar3 * in_EDX[10] + in_EDX[8] * fVar2 + in_EDX[9] * fVar1;
  return in_ECX;
}


// ---------------------------------------------------------------------
// Vector_Transform  @ 4fc12e7c  lines 314-322


Vector * __cdecl Vector_Transform(Vector *__return_storage_ptr__,Matrix *param_1,Vector *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  Vector *in_ECX;
  float *in_EDX;
  
  fVar1 = __return_storage_ptr__->y;
  fVar2 = __return_storage_ptr__->x;
  fVar3 = __return_storage_ptr__->z;
  in_ECX->x = in_EDX[8] * fVar3 + *in_EDX * fVar2 + in_EDX[4] * fVar1 + in_EDX[0xc];
  in_ECX->y = in_EDX[9] * fVar3 + in_EDX[5] * fVar1 + in_EDX[1] * fVar2 + in_EDX[0xd];
  in_ECX->z = fVar3 * in_EDX[10] + in_EDX[2] * fVar2 + in_EDX[6] * fVar1 + in_EDX[0xe];
  return in_ECX;
}


// ---------------------------------------------------------------------
// Matrix_Multiply  @ 4fc12ed4  lines 325-351


Matrix * __cdecl Matrix_Multiply(Matrix *__return_storage_ptr__,Matrix *param_1,Matrix *param_2)

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
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  Matrix *in_ECX;
  float *in_EDX;
  
  fVar1 = in_EDX[1];
  fVar2 = (__return_storage_ptr__->up).x;
  fVar3 = *in_EDX;
  fVar4 = (__return_storage_ptr__->right).x;
  fVar5 = (__return_storage_ptr__->front).x;
  fVar6 = in_EDX[2];
  fVar7 = (__return_storage_ptr__->posit).x;
  fVar8 = in_EDX[3];
  (in_ECX->right).x = fVar8 * fVar7 + fVar2 * fVar1 + fVar4 * fVar3 + fVar6 * fVar5;
  fVar9 = (__return_storage_ptr__->up).y;
  fVar10 = (__return_storage_ptr__->right).y;
  fVar11 = (__return_storage_ptr__->front).y;
  fVar12 = (__return_storage_ptr__->posit).y;
  (in_ECX->right).y = fVar12 * fVar8 + fVar11 * fVar6 + fVar9 * fVar1 + fVar10 * fVar3;
  fVar13 = (__return_storage_ptr__->up).z;
  fVar14 = (__return_storage_ptr__->right).z;
  fVar15 = (__return_storage_ptr__->front).z;
  fVar16 = (__return_storage_ptr__->posit).z;
  (in_ECX->right).z = fVar8 * fVar16 + fVar6 * fVar15 + fVar1 * fVar13 + fVar3 * fVar14;
  fVar17 = __return_storage_ptr__->upw;
  fVar18 = __return_storage_ptr__->rightw;
  fVar19 = __return_storage_ptr__->frontw;
  fVar20 = __return_storage_ptr__->positw;
  in_ECX->rightw = fVar6 * fVar19 + fVar17 * fVar1 + fVar3 * fVar18 + fVar8 * fVar20;
  fVar1 = in_EDX[5];
  fVar3 = in_EDX[4];
  fVar6 = in_EDX[6];
  fVar8 = in_EDX[7];
  (in_ECX->up).x = fVar7 * fVar8 + fVar5 * fVar6 + fVar2 * fVar1 + fVar4 * fVar3;
  (in_ECX->up).y = fVar12 * fVar8 + fVar11 * fVar6 + fVar9 * fVar1 + fVar10 * fVar3;
  (in_ECX->up).z = fVar8 * fVar16 + fVar6 * fVar15 + fVar1 * fVar13 + fVar3 * fVar14;
  in_ECX->upw = fVar8 * fVar20 + fVar19 * fVar6 + fVar18 * fVar3 + fVar17 * fVar1;
  fVar1 = in_EDX[9];
  fVar3 = in_EDX[8];
  fVar6 = in_EDX[10];
  fVar8 = in_EDX[0xb];
  (in_ECX->front).x = fVar7 * fVar8 + fVar5 * fVar6 + fVar2 * fVar1 + fVar4 * fVar3;
  (in_ECX->front).y = fVar12 * fVar8 + fVar11 * fVar6 + fVar9 * fVar1 + fVar10 * fVar3;
  (in_ECX->front).z = fVar8 * fVar16 + fVar6 * fVar15 + fVar1 * fVar13 + fVar3 * fVar14;
  in_ECX->frontw = fVar8 * fVar20 + fVar18 * fVar3 + fVar17 * fVar1 + fVar6 * fVar19;
  fVar1 = in_EDX[0xd];
  fVar3 = in_EDX[0xc];
  fVar6 = in_EDX[0xe];
  fVar8 = in_EDX[0xf];
  (in_ECX->posit).x = fVar3 * fVar4 + fVar1 * fVar2 + fVar6 * fVar5 + fVar8 * fVar7;
  (in_ECX->posit).y = fVar8 * fVar12 + fVar6 * fVar11 + fVar1 * fVar9 + fVar3 * fVar10;
  (in_ECX->posit).z = fVar8 * fVar16 + fVar6 * fVar15 + fVar1 * fVar13 + fVar3 * fVar14;
  in_ECX->positw = fVar8 * fVar20 + fVar6 * fVar19 + fVar18 * fVar3 + fVar17 * fVar1;
  return in_ECX;
}


// ---------------------------------------------------------------------
// Matrix_Inverse  @ 4fc131c6  lines 356-391


Matrix * __cdecl Matrix_Inverse(Matrix *__return_storage_ptr__,Matrix *param_1)

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
  Matrix *in_ECX;
  float *in_EDX;
  
  fVar1 = *in_EDX;
  fVar10 = in_EDX[0xd];
  fVar11 = in_EDX[0xc];
  fVar12 = in_EDX[0xe];
  (in_ECX->right).x = fVar1;
  fVar2 = in_EDX[4];
  (in_ECX->right).y = fVar2;
  fVar3 = in_EDX[8];
  (in_ECX->right).z = fVar3;
  fVar4 = in_EDX[1];
  (in_ECX->up).x = fVar4;
  fVar5 = in_EDX[5];
  (in_ECX->up).y = fVar5;
  fVar6 = in_EDX[9];
  (in_ECX->up).z = fVar6;
  fVar7 = in_EDX[2];
  (in_ECX->front).x = fVar7;
  fVar8 = in_EDX[6];
  in_ECX->rightw = 0.0;
  in_ECX->upw = 0.0;
  in_ECX->frontw = 0.0;
  (in_ECX->front).y = fVar8;
  fVar9 = in_EDX[10];
  (in_ECX->front).z = fVar9;
  (in_ECX->posit).x = -(fVar7 * fVar12 + fVar1 * fVar11 + fVar4 * fVar10);
  in_ECX->positw = 1.0;
  (in_ECX->posit).y = -(fVar8 * fVar12 + fVar2 * fVar11 + fVar5 * fVar10);
  (in_ECX->posit).z = -(fVar6 * fVar10 + fVar3 * fVar11 + fVar9 * fVar12);
  return in_ECX;
}


// ---------------------------------------------------------------------
// Build_Orthogonal_Matrix  @ 4fc132bb  lines 394-414


Matrix * __cdecl
Build_Orthogonal_Matrix
          (Matrix *__return_storage_ptr__,Vector *param_1,Vector *param_2,Vector *param_3)

{
  Vector *pVVar1;
  Matrix *in_ECX;
  Vector *unaff_ESI;
  Vector *unaff_EDI;
  
  pVVar1 = Normalize_Vector(unaff_EDI,unaff_ESI);
  (in_ECX->up).x = pVVar1->x;
  (in_ECX->up).y = pVVar1->y;
  (in_ECX->up).z = pVVar1->z;
  in_ECX->upw = 0.0;
  pVVar1 = Cross_Product(&__return_storage_ptr__->right,unaff_EDI,unaff_ESI);
  (in_ECX->right).x = pVVar1->x;
  (in_ECX->right).y = pVVar1->y;
  (in_ECX->right).z = pVVar1->z;
  pVVar1 = Normalize_Vector(&__return_storage_ptr__->right,unaff_EDI);
  (in_ECX->right).x = pVVar1->x;
  (in_ECX->right).y = pVVar1->y;
  (in_ECX->right).z = pVVar1->z;
  in_ECX->rightw = 0.0;
  pVVar1 = Cross_Product(&in_ECX->up,&__return_storage_ptr__->right,unaff_EDI);
  (in_ECX->front).x = pVVar1->x;
  (in_ECX->front).y = pVVar1->y;
  (in_ECX->front).z = pVVar1->z;
  in_ECX->frontw = 0.0;
  (in_ECX->posit).x = param_1->x;
  (in_ECX->posit).y = param_1->y;
  (in_ECX->posit).z = param_1->z;
  in_ECX->positw = 1.0;
  return in_ECX;
}


// ---------------------------------------------------------------------
// Build_Yaw_Matrix  @ 4fc1333d  lines 420-448


Matrix * __cdecl Build_Yaw_Matrix(Matrix *__return_storage_ptr__,float param_1,Vector *param_2)

{
  Matrix *in_ECX;
  float *in_EDX;
  float fVar1;
  float fVar2;
  
  fVar1 = portable_sin((float)__return_storage_ptr__);
  fVar2 = portable_cos((float)__return_storage_ptr__);
  (in_ECX->right).y = 0.0;
  in_ECX->rightw = 0.0;
  (in_ECX->up).x = 0.0;
  (in_ECX->up).z = 0.0;
  in_ECX->upw = 0.0;
  (in_ECX->front).y = 0.0;
  in_ECX->frontw = 0.0;
  (in_ECX->posit).x = *in_EDX;
  (in_ECX->right).x = fVar2;
  (in_ECX->posit).y = in_EDX[1];
  (in_ECX->front).x = fVar1;
  (in_ECX->posit).z = in_EDX[2];
  (in_ECX->right).z = -fVar1;
  (in_ECX->up).y = 1.0;
  (in_ECX->front).z = fVar2;
  in_ECX->positw = 1.0;
  return in_ECX;
}


// ---------------------------------------------------------------------
// Build_Position_Rotation_Matrix  @ 4fc133c1  lines 453-483


Matrix * __cdecl
Build_Position_Rotation_Matrix
          (Matrix *__return_storage_ptr__,float param_1,float param_2,float param_3,Vector *param_4)

{
  Matrix *in_ECX;
  float *in_EDX;
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  
  fVar2 = portable_sin(param_2);
  fVar3 = portable_cos(param_2);
  fVar4 = portable_sin((float)__return_storage_ptr__);
  fVar5 = portable_cos((float)__return_storage_ptr__);
  fVar6 = portable_sin(param_1);
  fVar7 = portable_cos(param_1);
  fVar1 = (float)((uint)fVar4 ^ __xmm_80000000800000008000000080000000);
  in_ECX->rightw = 0.0;
  in_ECX->upw = 0.0;
  (in_ECX->front).y = fVar1;
  (in_ECX->right).x = fVar2 * fVar6 * fVar4 + fVar3 * fVar7;
  (in_ECX->right).y = fVar5 * fVar2;
  (in_ECX->right).z = fVar7 * fVar2 * fVar4 - fVar3 * fVar6;
  (in_ECX->up).x = fVar3 * fVar6 * fVar4 - fVar7 * fVar2;
  (in_ECX->up).y = fVar5 * fVar3;
  (in_ECX->up).z = fVar4 * fVar3 * fVar7 + fVar2 * fVar6;
  (in_ECX->front).x = fVar5 * fVar6;
  (in_ECX->front).z = fVar5 * fVar7;
  in_ECX->frontw = 0.0;
  (in_ECX->posit).x = *in_EDX;
  in_ECX->positw = 1.0;
  (in_ECX->posit).y = in_EDX[1];
  (in_ECX->posit).z = in_EDX[2];
  return in_ECX;
}


// ---------------------------------------------------------------------
// GetRandomInt  @ 4fc134e6  lines 511-519


int __cdecl GetRandomInt(int param_1,int param_2)

{
  int extraout_EAX;
  int iVar1;
  int in_ECX;
  int in_EDX;
  
  if (in_ECX <= in_EDX) {
    GetRandomFloat((float)((in_EDX - in_ECX) + 1));
    _ftol2_sse();
    iVar1 = extraout_EAX + in_ECX;
    if ((in_ECX <= iVar1) && (in_ECX = iVar1, in_EDX < iVar1)) {
      in_ECX = in_EDX;
    }
  }
  return in_ECX;
}


// ---------------------------------------------------------------------
// GetRandomFloat  @ 4fc1351d  lines 522-529


float __cdecl GetRandomFloat(float param_1,float param_2)

{
  float fVar1;
  
  if (param_1 <= param_2) {
    fVar1 = GetRandomFloat((param_2 - param_1) + (float)__real_3ff0000000000000);
    fVar1 = fVar1 + param_1;
    if (param_1 <= fVar1) {
      if (param_2 < fVar1) {
        fVar1 = param_2;
      }
    }
    else {
      fVar1 = param_1;
    }
    return fVar1;
  }
  return param_1;
}

