// Reconstructed by Ghidra from Strategy02.dll + Strategy02.pdb
// Original source file: /e:/github/vsr_dll_source/missions/vsrcore/scraphelper.h
// Functions are ordered by original source line. This is decompiler
// output, not the author's source: names/types come from the PDB,
// local variable names and control flow are reconstructed.


// ---------------------------------------------------------------------
// ScrapHelper::GetNumScrapObjects  @ 4fc1fdf9  lines 47-47


int __thiscall ScrapHelper::GetNumScrapObjects(ScrapHelper *this)

{
  return *(int *)&(this->ScrapList).field_0x4 - *(int *)&this->ScrapList >> 2;
}

