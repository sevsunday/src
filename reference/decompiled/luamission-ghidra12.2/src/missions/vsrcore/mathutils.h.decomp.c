// Reconstructed by Ghidra from LuaMission.dll + LuaMission.pdb
// Original source file: /e:/github/vsr_dll_source/missions/vsrcore/mathutils.h
// Functions are ordered by original source line. This is decompiler
// output, not the author's source: names/types come from the PDB,
// local variable names and control flow are reconstructed.


// ---------------------------------------------------------------------
// close_enough  @ 4fc1660f  lines 111-111


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
// close_enough  @ 4fc16636  lines 112-112


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
// GetDistance3DSquared  @ 4fc01c09  lines 126-126


float __cdecl GetDistance3DSquared(Vector *param_1,Vector *param_2)

{
  float10 in_ST0;
  
  return (float)in_ST0;
}


// ---------------------------------------------------------------------
// GetDistance3DSquared  @ 4fc01c3a  lines 128-128


float __cdecl GetDistance3DSquared(int param_1,int param_2)

{
  bool bVar1;
  int in_ECX;
  int in_EDX;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 extraout_ST0_01;
  float10 fVar2;
  Vector local_1c;
  Vector local_10;
  
  bVar1 = IsAround(in_ECX);
  fVar2 = extraout_ST0;
  if ((bVar1) && (bVar1 = IsAround(in_EDX), fVar2 = extraout_ST0_00, bVar1)) {
    GetPosition(in_EDX,&local_10);
    GetPosition(in_ECX,&local_1c);
    fVar2 = extraout_ST0_01;
  }
  return (float)fVar2;
}


// ---------------------------------------------------------------------
// GetDistance2DSquared<Vector,Vector>  @ 4fc01d16  lines 131-131


float __cdecl GetDistance2DSquared<Vector,Vector>(Vector *param_1,Vector *param_2)

{
  float10 in_ST0;
  
  return (float)in_ST0;
}


// ---------------------------------------------------------------------
// Squared<float>  @ 4fc260b6  lines 166-166


float __cdecl Squared<float>(float param_1)

{
  return param_1 * param_1;
}

