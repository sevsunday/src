// Reconstructed by Ghidra from Strategy02.dll + Strategy02.pdb
// Original source file: /e:/github/vsr_dll_source/missions/vsrcore/mathutils.h
// Functions are ordered by original source line. This is decompiler
// output, not the author's source: names/types come from the PDB,
// local variable names and control flow are reconstructed.


// ---------------------------------------------------------------------
// close_enough  @ 4fc02185  lines 111-111


bool __cdecl close_enough(float *param_1,float *param_2,float param_3)

{
  float *in_ECX;
  float *in_EDX;
  
  if (ABS(*in_EDX - *in_ECX) < (float)param_1) {
    return true;
  }
  return false;
}


// ---------------------------------------------------------------------
// close_enough  @ 4fc021ac  lines 112-112


bool __cdecl close_enough(Vector *param_1,Vector *param_2,float param_3)

{
  bool bVar1;
  float unaff_ESI;
  float *unaff_EDI;
  
  bVar1 = close_enough(&param_1->x,unaff_EDI,unaff_ESI);
  if (((bVar1) && (bVar1 = close_enough(&param_1->x,unaff_EDI,unaff_ESI), bVar1)) &&
     (bVar1 = close_enough(&param_1->x,unaff_EDI,unaff_ESI), bVar1)) {
    return true;
  }
  return false;
}


// ---------------------------------------------------------------------
// IsNullVector  @ 4fc02203  lines 116-116


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool __cdecl IsNullVector(Vector param_1)

{
  if (param_1.z * param_1.z + param_1.y * param_1.y + param_1.x * param_1.x <
      (float)___real_3fb99999a0000000) {
    return true;
  }
  return false;
}


// ---------------------------------------------------------------------
// GetDistance3DSquared  @ 4fc09729  lines 126-126


float __cdecl GetDistance3DSquared(Vector *param_1,Vector *param_2)

{
  float *in_ECX;
  float *in_EDX;
  
  return (in_EDX[2] - in_ECX[2]) * (in_EDX[2] - in_ECX[2]) +
         (in_EDX[1] - in_ECX[1]) * (in_EDX[1] - in_ECX[1]) +
         (*in_EDX - *in_ECX) * (*in_EDX - *in_ECX);
}


// ---------------------------------------------------------------------
// GetDistance3DSquared  @ 4fc160a1  lines 128-128


float __cdecl GetDistance3DSquared(int param_1,int param_2)

{
  bool bVar1;
  int in_ECX;
  int in_EDX;
  Vector local_20;
  Vector local_14;
  
  bVar1 = IsAround(in_ECX);
  if ((bVar1) && (bVar1 = IsAround(in_EDX), bVar1)) {
    GetPosition(in_EDX,&local_14);
    GetPosition(in_ECX,&local_20);
    return (local_14.z - local_20.z) * (local_14.z - local_20.z) +
           (local_14.x - local_20.x) * (local_14.x - local_20.x) +
           (local_14.y - local_20.y) * (local_14.y - local_20.y);
  }
  return __real_7f7fffff;
}


// ---------------------------------------------------------------------
// GetDistance2DSquared<Vector,Vector>  @ 4fc1f4d2  lines 131-131


float __cdecl GetDistance2DSquared<Vector,Vector>(Vector *param_1,Vector *param_2)

{
  float *in_ECX;
  float *in_EDX;
  
  return (in_EDX[2] - in_ECX[2]) * (in_EDX[2] - in_ECX[2]) +
         (*in_EDX - *in_ECX) * (*in_EDX - *in_ECX);
}


// ---------------------------------------------------------------------
// GetLength3D  @ 4fc0222d  lines 138-138


float __cdecl GetLength3D(Vector param_1)

{
  float10 fVar1;
  
  fVar1 = (float10)__CIsqrt();
  return (float)fVar1;
}


// ---------------------------------------------------------------------
// FrontToRadian  @ 4fc09753  lines 144-144


float __cdecl FrontToRadian(Vector param_1)

{
  float fVar1;
  
  fVar1 = portable_atan2(param_1.x,param_1.z);
  return fVar1;
}


// ---------------------------------------------------------------------
// Squared<float>  @ 4fc123be  lines 166-166


float __cdecl Squared<float>(float param_1)

{
  return param_1 * param_1;
}

