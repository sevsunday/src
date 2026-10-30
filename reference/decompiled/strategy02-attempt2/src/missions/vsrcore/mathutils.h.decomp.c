// Reconstructed by Ghidra from Strategy02.dll + Strategy02.pdb
// Original source file: /e:/github/vsr_dll_source/missions/vsrcore/mathutils.h
// Functions are ordered by original source line. This is decompiler
// output, not the author's source: names/types come from the PDB,
// local variable names and control flow are reconstructed.

// ---------------------------------------------------------------------
// close_enough  @ 4fc02185  lines 111-111

bool __cdecl close_enough(float *F1,float *F2,float Tolerance)

{
  if (ABS(*F2 - *F1) < Tolerance) {
    return true;
  }
  return false;
}


// ---------------------------------------------------------------------
// close_enough  @ 4fc021ac  lines 112-112

bool __cdecl close_enough(Vector *V1,Vector *V2,float Tolerance)

{
  bool bVar1;
  
  bVar1 = close_enough(&V1->x,&V2->x,Tolerance);
  if (((bVar1) && (bVar1 = close_enough(&V1->y,&V2->y,Tolerance), bVar1)) &&
     (bVar1 = close_enough(&V1->z,&V2->z,Tolerance), bVar1)) {
    return true;
  }
  return false;
}


// ---------------------------------------------------------------------
// IsNullVector  @ 4fc02203  lines 116-116

bool __cdecl IsNullVector(Vector v)

{
  if (v.z * v.z + v.y * v.y + v.x * v.x < 0.1) {
    return true;
  }
  return false;
}


// ---------------------------------------------------------------------
// GetDistance3DSquared  @ 4fc09729  lines 126-126

float __cdecl GetDistance3DSquared(Vector *v1,Vector *v2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  
  fVar1 = v2->y - v1->y;
  fVar3 = v2->x - v1->x;
  fVar2 = v2->z - v1->z;
  return fVar2 * fVar2 + fVar1 * fVar1 + fVar3 * fVar3;
}


// ---------------------------------------------------------------------
// GetDistance3DSquared  @ 4fc160a1  lines 128-128

float __cdecl GetDistance3DSquared(int h1,int h2)

{
  bool bVar1;
  Vector local_20;
  Vector local_14;
  
  bVar1 = IsAround(h1);
  if ((bVar1) && (bVar1 = IsAround(h2), bVar1)) {
    GetPosition(h2,&local_14);
    GetPosition(h1,&local_20);
    return (local_14.z - local_20.z) * (local_14.z - local_20.z) +
           (local_14.x - local_20.x) * (local_14.x - local_20.x) +
           (local_14.y - local_20.y) * (local_14.y - local_20.y);
  }
  return 3.4028235e+38;
}


// ---------------------------------------------------------------------
// GetDistance2DSquared<Vector,Vector>  @ 4fc1f4d2  lines 131-131

float __cdecl GetDistance2DSquared<Vector,Vector>(Vector *v1,Vector *v2)

{
  float fVar1;
  float fVar2;
  
  fVar1 = v2->z - v1->z;
  fVar2 = v2->x - v1->x;
  return fVar1 * fVar1 + fVar2 * fVar2;
}


// ---------------------------------------------------------------------
// GetLength3D  @ 4fc0222d  lines 138-138

float __cdecl GetLength3D(Vector v)

{
  float10 fVar1;
  
  fVar1 = (float10)__CIsqrt();
  return (float)fVar1;
}


// ---------------------------------------------------------------------
// FrontToRadian  @ 4fc09753  lines 144-144

float __cdecl FrontToRadian(Vector front)

{
  float fVar1;
  
  fVar1 = portable_atan2(front.x,front.z);
  return fVar1;
}


// ---------------------------------------------------------------------
// Squared<float>  @ 4fc123be  lines 166-166

float __cdecl Squared<float>(float x)

{
  return x * x;
}


