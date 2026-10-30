// Reconstructed by Ghidra from Strategy02.dll + Strategy02.pdb
// Original source file: /e:/github/vsr_dll_source/missions/vsrcore/mathutils.cpp
// Functions are ordered by original source line. This is decompiler
// output, not the author's source: names/types come from the PDB,
// local variable names and control flow are reconstructed.

// ---------------------------------------------------------------------
// Cross_Product  @ 4fc13030  lines 10-16

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
// Build_Directinal_Matrix  @ 4fc1306f  lines 20-52

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
  if (0.02 <= fVar1 * fVar1 + fVar2 * fVar2) {
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
// Normalize_Vector  @ 4fc1312c  lines 56-65

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
// Interpolate_Quaternion  @ 4fc1318d  lines 74-127

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
    fVar4 = -fVar4;
    fVar5 = -fVar5;
    fVar6 = -fVar6;
    fVar7 = -fVar7;
  }
  fVar1 = (float10)(float)param_1;
  (in_ECX->v).z = fVar7;
  in_ECX->s = fVar6;
  (in_ECX->v).x = fVar5;
  (in_ECX->v).y = fVar4;
  fVar2 = (float10)1 - fVar1;
  if ((float10)0.0010000000474974513 < (float10)1 - fVar3) {
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
// Normalize_Quaternion  @ 4fc132d2  lines 130-148

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
    fVar5 = (float10)999.9999389648438;
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
// Matrix_to_QuatPos  @ 4fc13363  lines 154-191

void __cdecl Matrix_to_QuatPos(Matrix *M,Quaternion *Q,Vector *P)

{
  float fVar1;
  float fVar2;
  float fVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  float10 fVar7;
  
  fVar1 = (M->up).y;
  fVar2 = (M->right).x;
  fVar3 = (M->front).z;
  if (fVar2 + fVar1 + fVar3 <= 0.0) {
    uVar6 = (uint)(fVar2 < fVar1);
    if (*(float *)((int)&M->right + uVar6 * 0x14) < fVar3) {
      uVar6 = 2;
    }
    uVar4 = next[uVar6];
    uVar5 = next[uVar4];
    fVar7 = (float10)__CIsqrt();
    (&(Q->v).x)[uVar6] = (float)fVar7 * 0.5;
    fVar1 = 0.5 / (float)fVar7;
    Q->s = (*(float *)((int)&M->right + (uVar4 + uVar5 * 4) * 4) -
           *(float *)((int)&M->right + (uVar5 + uVar4 * 4) * 4)) * fVar1;
    (&(Q->v).x)[uVar4] =
         (*(float *)((int)&M->right + (uVar4 * 4 + uVar6) * 4) +
         *(float *)((int)&M->right + (uVar4 + uVar6 * 4) * 4)) * fVar1;
    (&(Q->v).x)[uVar5] =
         (*(float *)((int)&M->right + (uVar5 * 4 + uVar6) * 4) +
         *(float *)((int)&M->right + (uVar5 + uVar6 * 4) * 4)) * fVar1;
  }
  else {
    fVar7 = (float10)__CIsqrt();
    Q->s = (float)fVar7 * 0.5;
    fVar1 = 0.5 / (float)fVar7;
    (Q->v).x = ((M->front).y - (M->up).z) * fVar1;
    (Q->v).y = ((M->right).z - (M->front).x) * fVar1;
    (Q->v).z = ((M->up).x - (M->right).y) * fVar1;
  }
  P->x = (M->posit).x;
  P->y = (M->posit).y;
  P->z = (M->posit).z;
  return;
}


// ---------------------------------------------------------------------
// QuatPos_to_Matrix  @ 4fc134a7  lines 211-242

void __cdecl QuatPos_to_Matrix(Quaternion *Q,Vector *P,Matrix *M)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  
  fVar1 = (Q->v).y;
  fVar2 = (Q->v).x;
  fVar3 = (Q->v).z;
  fVar4 = Q->s;
  M->rightw = 0.0;
  fVar7 = 2.0 / (fVar3 * fVar3 + fVar1 * fVar1 + fVar2 * fVar2 + fVar4 * fVar4);
  fVar5 = fVar7 * fVar1;
  fVar6 = fVar7 * fVar3;
  (M->right).x = 1.0 - (fVar5 * fVar1 + fVar6 * fVar3);
  (M->right).y = fVar2 * fVar5 - fVar4 * fVar6;
  (M->right).z = fVar4 * fVar5 + fVar2 * fVar6;
  (M->up).x = fVar4 * fVar6 + fVar2 * fVar5;
  fVar8 = fVar2 * fVar7 * fVar2;
  M->upw = 0.0;
  M->frontw = 0.0;
  (M->up).y = 1.0 - (fVar6 * fVar3 + fVar8);
  fVar3 = fVar4 * fVar7 * fVar2;
  (M->up).z = fVar1 * fVar6 - fVar3;
  (M->front).x = fVar2 * fVar6 - fVar4 * fVar5;
  (M->front).y = fVar1 * fVar6 + fVar3;
  (M->front).z = 1.0 - (fVar8 + fVar5 * fVar1);
  (M->posit).x = P->x;
  (M->posit).y = P->y;
  (M->posit).z = P->z;
  M->positw = 1.0;
  return;
}


// ---------------------------------------------------------------------
// Interpolate_Matrix  @ 4fc135e3  lines 247-271

Matrix * __cdecl
Interpolate_Matrix(Matrix *__return_storage_ptr__,Matrix *param_1,Matrix *param_2,float param_3)

{
  Matrix *in_ECX;
  Matrix *in_EDX;
  Quaternion *unaff_ESI;
  float in_stack_ffffffb0;
  Quaternion q;
  Quaternion q0;
  Quaternion q1;
  Vector p1;
  Vector p0;
  
  p0.y = 0.0;
  p0.z = 0.0;
  p0.x = 0.0;
  Matrix_to_QuatPos(in_EDX,&q0,&p0);
  p1.z = 0.0;
  p1.x = 0.0;
  p1.y = 0.0;
  Matrix_to_QuatPos(__return_storage_ptr__,&q1,&p1);
  Interpolate_Quaternion(&q1,(Quaternion *)param_1,unaff_ESI,in_stack_ffffffb0);
  q1.v.x = (p1.x - p0.x) * (float)param_1 + p0.x;
  q1.v.y = (p1.y - p0.y) * (float)param_1 + p0.y;
  q1.v.z = p0.z + (p1.z - p0.z) * (float)param_1;
  QuatPos_to_Matrix(&q,&q1.v,in_ECX);
  return in_ECX;
}


// ---------------------------------------------------------------------
// Vector_Rotate  @ 4fc13680  lines 276-284

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
// Vector_TransformInv  @ 4fc136cf  lines 299-311

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
// Vector_Transform  @ 4fc1373c  lines 314-322

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
// Matrix_Multiply  @ 4fc13794  lines 325-351

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
// Matrix_Inverse  @ 4fc13a86  lines 356-391

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
// Build_Orthogonal_Matrix  @ 4fc13b7b  lines 394-414

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
// Build_Yaw_Matrix  @ 4fc13bfd  lines 420-448

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
// Build_Position_Rotation_Matrix  @ 4fc13c81  lines 453-483

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
  
  fVar1 = portable_sin(param_2);
  fVar2 = portable_cos(param_2);
  fVar3 = portable_sin((float)__return_storage_ptr__);
  fVar4 = portable_cos((float)__return_storage_ptr__);
  fVar5 = portable_sin(param_1);
  fVar6 = portable_cos(param_1);
  in_ECX->rightw = 0.0;
  in_ECX->upw = 0.0;
  (in_ECX->front).y = -fVar3;
  (in_ECX->right).x = fVar1 * fVar5 * fVar3 + fVar2 * fVar6;
  (in_ECX->right).y = fVar4 * fVar1;
  (in_ECX->right).z = fVar6 * fVar1 * fVar3 - fVar2 * fVar5;
  (in_ECX->up).x = fVar2 * fVar5 * fVar3 - fVar6 * fVar1;
  (in_ECX->up).y = fVar4 * fVar2;
  (in_ECX->up).z = fVar3 * fVar2 * fVar6 + fVar1 * fVar5;
  (in_ECX->front).x = fVar4 * fVar5;
  (in_ECX->front).z = fVar4 * fVar6;
  in_ECX->frontw = 0.0;
  (in_ECX->posit).x = *in_EDX;
  in_ECX->positw = 1.0;
  (in_ECX->posit).y = in_EDX[1];
  (in_ECX->posit).z = in_EDX[2];
  return in_ECX;
}


// ---------------------------------------------------------------------
// GetRandomInt  @ 4fc13da6  lines 511-519

int __cdecl GetRandomInt(int Min,int Max)

{
  int extraout_EAX;
  int iVar1;
  
  if (Min <= Max) {
    GetRandomFloat((float)((Max - Min) + 1));
    _ftol2_sse();
    iVar1 = extraout_EAX + Min;
    if ((Min <= iVar1) && (Min = iVar1, Max < iVar1)) {
      Min = Max;
    }
  }
  return Min;
}


// ---------------------------------------------------------------------
// GetRandomFloat  @ 4fc13ddd  lines 522-529

float __cdecl GetRandomFloat(float Min,float Max)

{
  float fVar1;
  
  if (Min <= Max) {
    fVar1 = GetRandomFloat((Max - Min) + 1.0);
    fVar1 = fVar1 + Min;
    if ((Min <= fVar1) && (Min = fVar1, Max < fVar1)) {
      Min = Max;
    }
    return Min;
  }
  return Min;
}


