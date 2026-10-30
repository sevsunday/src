// Reconstructed by Ghidra from LuaMission.dll + LuaMission.pdb
// Original source file: /e:/github/vsr_dll_source/source/fun3d/scriptutils.h
// Functions are ordered by original source line. This is decompiler
// output, not the author's source: names/types come from the PDB,
// local variable names and control flow are reconstructed.


// ---------------------------------------------------------------------
// Matrix::Matrix  @ 4fc01b60  lines 181-183


Matrix * __thiscall
Matrix::Matrix(Matrix *this,Vector param_1,Vector param_2,Vector param_3,Vector param_4)

{
  this->rightw = 0.0;
  this->upw = 0.0;
  this->frontw = 0.0;
  this->positw = 1.0;
  (this->right).x = param_1.x;
  (this->right).y = param_1.y;
  (this->right).z = param_1.z;
  (this->up).x = param_2.x;
  (this->up).y = param_2.y;
  (this->up).z = param_2.z;
  (this->front).x = param_3.x;
  (this->front).y = param_3.y;
  (this->front).z = param_3.z;
  (this->posit).x = param_4.x;
  (this->posit).y = param_4.y;
  (this->posit).z = param_4.z;
  return this;
}


// ---------------------------------------------------------------------
// GetPosition  @ 4fc01bf8  lines 751-755


Vector * __cdecl GetPosition(Vector *__return_storage_ptr__,int param_1)

{
  Vector *in_ECX;
  int in_EDX;
  
  GetPosition(in_EDX,in_ECX);
  return in_ECX;
}

