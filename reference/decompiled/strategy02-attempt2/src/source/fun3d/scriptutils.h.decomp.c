// Reconstructed by Ghidra from Strategy02.dll + Strategy02.pdb
// Original source file: /e:/github/vsr_dll_source/source/fun3d/scriptutils.h
// Functions are ordered by original source line. This is decompiler
// output, not the author's source: names/types come from the PDB,
// local variable names and control flow are reconstructed.

// ---------------------------------------------------------------------
// Matrix::Matrix  @ 4fc01c64  lines 181-183

Matrix * __thiscall Matrix::Matrix(Matrix *this,Vector vr,Vector vu,Vector vf,Vector vp)

{
  this->rightw = 0.0;
  this->upw = 0.0;
  this->frontw = 0.0;
  this->positw = 1.0;
  (this->right).x = vr.x;
  (this->right).y = vr.y;
  (this->right).z = vr.z;
  (this->up).x = vu.x;
  (this->up).y = vu.y;
  (this->up).z = vu.z;
  (this->front).x = vf.x;
  (this->front).y = vf.y;
  (this->front).z = vf.z;
  (this->posit).x = vp.x;
  (this->posit).y = vp.y;
  (this->posit).z = vp.z;
  return this;
}


