// Reconstructed by Ghidra from deathmatch01.dll + deathmatch01.pdb
// Original source file: /e:/github/vsr_dll_source/missions/shared/pupmgr.cpp
// Functions are ordered by original source line. This is decompiler
// output, not the author's source: names/types come from the PDB,
// local variable names and control flow are reconstructed.


// ---------------------------------------------------------------------
// PUPMgr::Init  @ 4fc4324b  lines 22-79


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __cdecl PUPMgr::Init(void)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  char *pcVar4;
  char **local_54;
  int local_50;
  int local_4c;
  char local_48 [64];
  undefined4 local_8;
  
  local_8 = __security_cookie ^ (uint)(local_48 + 0x44);
  memset(pup,0,14000);
  PUPCount = 0;
  memset(pupHandle,0,400);
  GetAiPaths(&local_50,&local_54);
  local_4c = 0;
  pcVar4 = pup[0].odf;
  iVar1 = PUPCount;
  if (0 < local_50) {
    do {
      if (iVar1 < 100) {
        pcVar2 = local_54[local_4c];
        iVar1 = strncmp(pcVar2,"king",4);
        if (((((iVar1 != 0) && (iVar1 = strncmp(pcVar2,"edge_path",9), iVar1 != 0)) &&
             (iVar1 = strncmp(pcVar2,"spawntank8",9), iVar1 != 0)) &&
            ((iVar1 = strncmp(pcVar2,"spawnrocket8",0xb), iVar1 != 0 &&
             (iVar1 = strncmp(pcVar2,"base1",5), iVar1 != 0)))) &&
           ((iVar1 = strncmp(pcVar2,"base2",5), iVar1 != 0 &&
            ((iVar1 = strncmp(pcVar2,"path",4), iVar1 != 0 && ((uint)PUPCount < 100)))))) {
          strncpy_s(pup[PUPCount].str,0x40,pcVar2,0x3f);
          strncpy_s(pup[PUPCount].odf,0x40,pcVar2,0x3f);
          pcVar2 = strchr(pup[PUPCount].odf,0x5f);
          if (pcVar2 != (char *)0x0) {
            *pcVar2 = '\0';
            strcpy_s(local_48,0x40,pcVar2 + 1);
            pcVar2 = strchr(local_48,0x5f);
            if (pcVar2 != (char *)0x0) {
              *pcVar2 = '\0';
            }
            iVar1 = atoi(local_48);
            if (iVar1 < 1) {
              pup[PUPCount].dt = 10.0;
            }
            else {
              pup[PUPCount].dt = (float)iVar1;
            }
            PUPCount = PUPCount + 1;
          }
        }
        iVar1 = PUPCount;
      }
      local_4c = local_4c + 1;
    } while (local_4c < local_50);
  }
  iVar3 = 0;
  if (0 < iVar1) {
    do {
      iVar1 = BuildObject(pcVar4,0,pcVar4 + -0x40);
      pupHandle[iVar3] = iVar1;
      pcVar4[0x40] = false;
      iVar3 = iVar3 + 1;
      pcVar4 = pcVar4 + 0x8c;
    } while (iVar3 < PUPCount);
  }
  return;
}


// ---------------------------------------------------------------------
// PUPMgr::Execute  @ 4fc43128  lines 82-106


void __cdecl PUPMgr::Execute(void)

{
  float fVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  myprup *pmVar5;
  
  fVar1 = misnImport.time;
  LogFloat(misnImport.time);
  iVar4 = 0;
  if (0 < PUPCount) {
    pmVar5 = pup;
    do {
      bVar2 = IsAlive(pupHandle + iVar4);
      LogFloat((float)bVar2);
      LogFloat((float)pmVar5->waiting);
      LogFloat(pmVar5->dt);
      if (pmVar5->waiting != false) {
        LogFloat(pmVar5->time);
      }
      bVar2 = IsAlive(pupHandle + iVar4);
      if ((!bVar2) && (pmVar5->waiting == false)) {
        LogFloat(1.1);
        pmVar5->waiting = true;
        pmVar5->time = fVar1 + pmVar5->dt;
      }
      if ((pmVar5->waiting != false) && (pmVar5->time <= fVar1 && fVar1 != pmVar5->time)) {
        LogFloat(2.2);
        iVar3 = BuildObject(pmVar5->odf,0,pmVar5->str);
        pupHandle[iVar4] = iVar3;
        pmVar5->waiting = false;
      }
      iVar4 = iVar4 + 1;
      pmVar5 = pmVar5 + 1;
    } while (iVar4 < PUPCount);
  }
  return;
}


// ---------------------------------------------------------------------
// PUPMgr::Load  @ 4fc430e7  lines 109-121


bool __cdecl PUPMgr::Load(bool param_1)

{
  Read(&PUPCount,1);
  if (PUPCount != 0) {
    Read(pup,PUPCount * 0x8c);
    Read(pupHandle,PUPCount);
  }
  return true;
}


// ---------------------------------------------------------------------
// PUPMgr::Save  @ 4fc430a6  lines 124-136


bool __cdecl PUPMgr::Save(bool param_1)

{
  Write(&PUPCount,1);
  if (PUPCount != 0) {
    Write(pup,PUPCount * 0x8c);
    Write(pupHandle,PUPCount);
  }
  return true;
}


// ---------------------------------------------------------------------
// PUPMgr::PostLoad  @ 4fc4308c  lines 139-144


bool __cdecl PUPMgr::PostLoad(bool param_1)

{
  char in_CL;
  
  if (in_CL == '\0') {
    ConvertHandles(pupHandle,PUPCount);
  }
  return true;
}

