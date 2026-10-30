// Reconstructed by Ghidra from Instant.dll + Instant.pdb
// Original source file: /e:/github/vsr_dll_source/missions/shared/taunts.cpp
// Functions are ordered by original source line. This is decompiler
// output, not the author's source: names/types come from the PDB,
// local variable names and control flow are reconstructed.


// ---------------------------------------------------------------------
// `dynamic_initializer_for_'TauntList''  @ 4fc01071  lines 9-9


void __cdecl _dynamic_initializer_for__TauntList__(void)

{
  _eh_vector_constructor_iterator_
            (TauntList,0xc,0x10,
             std::vector<char_*,std::allocator<char_*>_>::vector<char_*,std::allocator<char_*>_>,
             std::vector<char_*,std::allocator<char_*>_>::~vector<char_*,std::allocator<char_*>_>);
  atexit(_dynamic_atexit_destructor_for__TauntList__);
  return;
}


// ---------------------------------------------------------------------
// InitTaunts  @ 4fc4293b  lines 35-128


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __cdecl InitTaunts(int *param_1,int *param_2,int *param_3,char *param_4)

{
  char *pcVar1;
  char cVar2;
  char **ppcVar3;
  bool bVar4;
  char *pcVar5;
  int iVar6;
  int *in_ECX;
  int iVar7;
  int *in_EDX;
  char (*_Str1) [16];
  vector<char_*,std::allocator<char_*>_> *this;
  int *piVar8;
  char *pcVar9;
  int local_158;
  char (*local_154) [16];
  char *local_150;
  uint local_14c;
  char local_148 [128];
  char local_c8 [64];
  char local_88 [64];
  char local_48 [64];
  undefined4 local_8;
  
  local_8 = __security_cookie ^ (uint)(local_48 + 0x44);
  g_pTPS = param_1;
  piVar8 = LastTauntPrinted;
  g_pElapsedTime = in_ECX;
  g_pLastTauntPrintedAt = in_EDX;
  for (iVar7 = 0x10; iVar7 != 0; iVar7 = iVar7 + -1) {
    *piVar8 = -1;
    piVar8 = piVar8 + 1;
  }
  if (param_2 != (int *)0x0) {
    strcpy_s(CPUTeamName,0x100,(char *)param_2);
    DeterminedCPUTeamName = true;
  }
  if (ReadTaunts == false) {
    pcVar5 = GetMapTRNFilename();
    strcpy_s(local_148,0x80,pcVar5);
    bVar4 = OpenODF(local_148);
    if (bVar4) {
      memset(local_c8,0,0x40);
      GetODFString(local_148,"DLL","TauntODFFile",0x40,local_c8,"Taunts");
      memset(local_88,0,0x40);
      strncpy_s(local_88,0x40,local_c8,0x40);
      pcVar5 = local_88;
      do {
        cVar2 = *pcVar5;
        pcVar5 = pcVar5 + 1;
      } while (cVar2 != '\0');
      strncat_s(local_88,0x40,".odf",0x3f - ((int)pcVar5 - (int)(local_88 + 1)));
      bVar4 = OpenODF(local_88);
      local_154 = TauntHeaders;
      if (bVar4) {
        iVar7 = 0;
        _Str1 = TauntHeaders;
        do {
          memset(local_48,0,0x40);
          sprintf_s<64>(&local_48,"Category%d");
          iVar6 = GetODFString(local_88,"TauntCategories",local_48,0x40,*_Str1,(char *)0x0);
          if (iVar6 == 0) break;
          TauntHeaderCount = TauntHeaderCount + 1;
          iVar6 = strncmp(*_Str1,"_rand",5);
          if (iVar6 == 0) {
            TauntRandomHeader = iVar7;
          }
          _Str1 = _Str1 + 1;
          iVar7 = iVar7 + 1;
        } while ((int)_Str1 < 0x4fc69e80);
        CloseODF(local_88);
      }
      local_158 = 0;
      if (0 < TauntHeaderCount) {
        this = TauntList;
        do {
          memset(local_48,0,0x40);
          strncpy_s(local_48,0x40,local_c8,0x40);
          pcVar5 = local_48;
          do {
            cVar2 = *pcVar5;
            pcVar5 = pcVar5 + 1;
          } while (cVar2 != '\0');
          strncat_s(local_48,0x40,*local_154,0x3f - ((int)pcVar5 - (int)(local_48 + 1)));
          pcVar5 = local_48;
          do {
            cVar2 = *pcVar5;
            pcVar5 = pcVar5 + 1;
          } while (cVar2 != '\0');
          strncat_s(local_48,0x40,".otf",0x3f - ((int)pcVar5 - (int)(local_48 + 1)));
          TauntBuffer[local_158] = (char *)0x0;
          local_14c = 0;
          LoadFile(local_48,(void *)0x0,&local_14c);
          pcVar5 = malloc(local_14c + 1);
          TauntBuffer[local_158] = pcVar5;
          LoadFile(local_48,pcVar5,&local_14c);
          pcVar5 = TauntBuffer[local_158];
          pcVar5[local_14c] = '\0';
          if (pcVar5 != (char *)0x0) {
            pcVar1 = pcVar5 + local_14c;
            local_150 = pcVar5;
            if (pcVar5 < pcVar1) {
              pcVar9 = pcVar5;
              do {
                cVar2 = *pcVar9;
                if (((cVar2 == '\r') || (cVar2 == '\n')) || (cVar2 == '\0')) {
                  *pcVar9 = '\0';
                  if (pcVar5 < pcVar9) {
                    ppcVar3 = *(char ***)&this->field_0x4;
                    if (*(char ***)&this->field_0x8 == ppcVar3) {
                      std::vector<char_*,std::allocator<char_*>_>::
                      _Emplace_reallocate<char_*_const_&>(this,ppcVar3,&local_150);
                    }
                    else {
                      *ppcVar3 = pcVar5;
                      *(int *)&this->field_0x4 = *(int *)&this->field_0x4 + 4;
                    }
                  }
                  pcVar5 = pcVar9 + 1;
                  local_150 = pcVar5;
                }
                pcVar9 = pcVar9 + 1;
              } while (pcVar9 < pcVar1);
              if (pcVar5 < pcVar1) {
                ppcVar3 = *(char ***)&this->field_0x4;
                if (*(char ***)&this->field_0x8 == ppcVar3) {
                  std::vector<char_*,std::allocator<char_*>_>::_Emplace_reallocate<char_*_const_&>
                            (this,ppcVar3,&local_150);
                }
                else {
                  *ppcVar3 = pcVar5;
                  *(int *)&this->field_0x4 = *(int *)&this->field_0x4 + 4;
                }
              }
            }
          }
          local_154 = local_154 + 1;
          local_158 = local_158 + 1;
          this = this + 1;
        } while (local_158 < TauntHeaderCount);
      }
    }
    CloseODF(local_148);
    ReadTaunts = true;
  }
  return;
}


// ---------------------------------------------------------------------
// DoTaunt  @ 4fc42caa  lines 135-204


void __cdecl DoTaunt(int param_1)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  int in_ECX;
  int iVar4;
  int iVar5;
  float fVar6;
  
  if (in_ECX < TauntHeaderCount) {
    fVar6 = GetRandomFloat(20.0);
    if (fVar6 < __real_3f800000) {
      in_ECX = TauntRandomHeader;
    }
    if (DeterminedCPUTeamName == false) {
      pcVar2 = GetVarItemStr("network.session.svar2");
      if (pcVar2 != (char *)0x0) {
        strcpy_s(CPUTeamName,0x100,pcVar2);
      }
      DeterminedCPUTeamName = true;
    }
    iVar5 = 0;
    iVar4 = *(int *)&TauntList[in_ECX].field_0x4 - *(int *)(TauntList + in_ECX) >> 2;
    if (0 < iVar4) {
      if (1 < iVar4) {
        fVar6 = GetRandomFloat((float)iVar4);
        iVar3 = (int)fVar6;
        if (iVar3 < 0) {
          iVar3 = 0;
        }
        else if (iVar4 + -1 < iVar3) {
          iVar3 = iVar4 + -1;
        }
        iVar5 = iVar3 + 1;
        if (iVar3 != LastTauntPrinted[in_ECX]) {
          iVar5 = iVar3;
        }
        if (iVar4 <= iVar5) {
          iVar5 = 0;
        }
      }
      LastTauntPrinted[in_ECX] = iVar5;
      pcVar2 = CPUTeamName;
      do {
        cVar1 = *pcVar2;
        pcVar2 = pcVar2 + 1;
      } while (cVar1 != '\0');
      sprintf_s<512>(&TempBuffer,"%.255s : %.*s\n");
      if ((((g_pElapsedTime != (int *)0x0) && (g_pLastTauntPrintedAt != (int *)0x0)) &&
          (g_pTPS != (int *)0x0)) && (*g_pTPS * 0x14 <= *g_pElapsedTime - *g_pLastTauntPrintedAt)) {
        *g_pLastTauntPrintedAt = *g_pElapsedTime;
        iVar5 = IFace_GetInteger("options.play.taunts");
        if (iVar5 != 0) {
          AddToMessagesBox(TempBuffer);
        }
      }
    }
  }
  return;
}


// ---------------------------------------------------------------------
// SetTauntCPUName  @ 4fc4292d  lines 208-210


void __cdecl SetTauntCPUName(char *param_1)

{
  char *in_ECX;
  
  sprintf_s<256>(&CPUTeamName,in_ECX);
  return;
}


// ---------------------------------------------------------------------
// CleanupTaunts  @ 4fc42e12  lines 214-220


void __cdecl CleanupTaunts(void)

{
  int iVar1;
  
  iVar1 = 0;
  if (0 < TauntHeaderCount) {
    do {
      free(TauntBuffer[iVar1]);
      TauntBuffer[iVar1] = (char *)0x0;
      iVar1 = iVar1 + 1;
    } while (iVar1 < TauntHeaderCount);
  }
  return;
}

