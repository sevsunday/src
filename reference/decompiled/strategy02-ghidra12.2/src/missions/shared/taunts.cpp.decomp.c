// Reconstructed by Ghidra from Strategy02.dll + Strategy02.pdb
// Original source file: /e:/github/vsr_dll_source/missions/shared/taunts.cpp
// Functions are ordered by original source line. This is decompiler
// output, not the author's source: names/types come from the PDB,
// local variable names and control flow are reconstructed.


// ---------------------------------------------------------------------
// `dynamic_initializer_for_'TauntList''  @ 4fc011ae  lines 9-9


void __cdecl _dynamic_initializer_for__TauntList__(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = 0x10;
  puVar1 = (undefined4 *)&TauntList[0].field_0x8;
  do {
    puVar1[-2] = 0;
    puVar1[-1] = 0;
    *puVar1 = 0;
    puVar1 = puVar1 + 3;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  atexit(_dynamic_atexit_destructor_for__TauntList__);
  return;
}


// ---------------------------------------------------------------------
// InitTaunts  @ 4fc090da  lines 35-128


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __cdecl InitTaunts(int *param_1,int *param_2,int *param_3,char *param_4)

{
  char *pcVar1;
  char cVar2;
  bool bVar3;
  char *pcVar4;
  int iVar5;
  int *in_ECX;
  int iVar6;
  int *in_EDX;
  char (*pacVar7) [16];
  char *pcVar8;
  int *piVar9;
  vector<char_*,std::allocator<char_*>_> *this;
  uint local_150;
  char *local_14c;
  char (*local_148) [16];
  char local_144 [64];
  char local_104 [64];
  char local_c4 [64];
  char local_84 [128];
  uint local_4;
  
  bVar3 = ReadTaunts;
  local_4 = __security_cookie ^ (uint)&local_150;
  g_pTPS = param_1;
  piVar9 = LastTauntPrinted;
  g_pElapsedTime = in_ECX;
  g_pLastTauntPrintedAt = in_EDX;
  for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
    *piVar9 = -1;
    piVar9 = piVar9 + 1;
  }
  if (!bVar3) {
    pcVar4 = GetMapTRNFilename();
    strcpy_s(local_84,0x80,pcVar4);
    bVar3 = OpenODF(local_84);
    if (bVar3) {
      memset(local_c4,0,0x40);
      GetODFString(local_84,"DLL","TauntODFFile",0x40,local_c4,"Taunts");
      memset(local_104,0,0x40);
      strncpy_s(local_104,0x40,local_c4,0x40);
      pcVar4 = local_104;
      do {
        cVar2 = *pcVar4;
        pcVar4 = pcVar4 + 1;
      } while (cVar2 != '\0');
      strncat_s(local_104,0x40,".odf",0x3f - ((int)pcVar4 - (int)(local_104 + 1)));
      bVar3 = OpenODF(local_104);
      pacVar7 = TauntHeaders;
      local_148 = TauntHeaders;
      if (bVar3) {
        iVar6 = 0;
        do {
          memset(local_144,0,0x40);
          sprintf_s<64>(&local_144,"Category%d");
          iVar5 = GetODFString(local_104,"TauntCategories",local_144,0x40,*pacVar7,(char *)0x0);
          if (iVar5 == 0) break;
          TauntHeaderCount = TauntHeaderCount + 1;
          iVar5 = strncmp(*pacVar7,"_rand",5);
          if (iVar5 == 0) {
            TauntRandomHeader = iVar6;
          }
          pacVar7 = pacVar7 + 1;
          iVar6 = iVar6 + 1;
        } while ((int)pacVar7 < 0x4fc70000);
        CloseODF(local_104);
      }
      pacVar7 = TauntHeaders;
      iVar6 = 0;
      if (0 < TauntHeaderCount) {
        this = TauntList;
        do {
          memset(local_144,0,0x40);
          strncpy_s(local_144,0x40,local_c4,0x40);
          pcVar4 = local_144;
          do {
            cVar2 = *pcVar4;
            pcVar4 = pcVar4 + 1;
          } while (cVar2 != '\0');
          strncat_s(local_144,0x40,*pacVar7,0x3f - ((int)pcVar4 - (int)(local_144 + 1)));
          pcVar4 = local_144;
          do {
            cVar2 = *pcVar4;
            pcVar4 = pcVar4 + 1;
          } while (cVar2 != '\0');
          strncat_s(local_144,0x40,".otf",0x3f - ((int)pcVar4 - (int)(local_144 + 1)));
          TauntBuffer[iVar6] = (char *)0x0;
          local_150 = 0;
          LoadFile(local_144,(void *)0x0,&local_150);
          pcVar4 = malloc(local_150 + 1);
          TauntBuffer[iVar6] = pcVar4;
          LoadFile(local_144,pcVar4,&local_150);
          pcVar4 = TauntBuffer[iVar6];
          pcVar4[local_150] = '\0';
          if ((pcVar4 != (char *)0x0) &&
             (pcVar1 = pcVar4 + local_150, local_14c = pcVar4, pcVar4 < pcVar1)) {
            pcVar8 = pcVar4;
            do {
              cVar2 = *pcVar8;
              if (((cVar2 == '\r') || (cVar2 == '\n')) || (cVar2 == '\0')) {
                *pcVar8 = '\0';
                if (pcVar4 < pcVar8) {
                  std::vector<char_*,std::allocator<char_*>_>::push_back(this,&local_14c);
                }
                pcVar4 = pcVar8 + 1;
                local_14c = pcVar4;
              }
              pacVar7 = local_148;
              pcVar8 = pcVar8 + 1;
            } while (pcVar8 < pcVar1);
            if (pcVar4 < pcVar1) {
              std::vector<char_*,std::allocator<char_*>_>::push_back(this,&local_14c);
            }
          }
          iVar6 = iVar6 + 1;
          pacVar7 = pacVar7 + 1;
          this = this + 1;
          local_148 = pacVar7;
        } while (iVar6 < TauntHeaderCount);
      }
    }
    CloseODF(local_84);
    ReadTaunts = true;
  }
  return;
}


// ---------------------------------------------------------------------
// DoTaunt  @ 4fc093ff  lines 135-204


void __cdecl DoTaunt(int param_1)

{
  char cVar1;
  char *pcVar2;
  int extraout_EAX;
  int iVar3;
  int in_ECX;
  int iVar4;
  int iVar5;
  float fVar6;
  
  if (in_ECX < TauntHeaderCount) {
    fVar6 = GetRandomFloat(__real_41a00000);
    if (fVar6 < 1.0) {
      in_ECX = TauntRandomHeader;
    }
    if (DeterminedCPUTeamName == false) {
      pcVar2 = GetVarItemStr("network.session.svar2");
      if (pcVar2 != (char *)0x0) {
        strcpy_s(CPUTeamName,0x100,pcVar2);
      }
      DeterminedCPUTeamName = true;
    }
    iVar4 = 0;
    iVar5 = *(int *)&TauntList[in_ECX].field_0x4 - *(int *)(TauntList + in_ECX) >> 2;
    if (0 < iVar5) {
      if (1 < iVar5) {
        GetRandomFloat((float)iVar5);
        _ftol2_sse();
        if (extraout_EAX < 0) {
          iVar3 = 0;
        }
        else {
          iVar3 = extraout_EAX;
          if (iVar5 + -1 < extraout_EAX) {
            iVar3 = iVar5 + -1;
          }
        }
        iVar4 = iVar3 + 1;
        if (iVar3 != LastTauntPrinted[in_ECX]) {
          iVar4 = iVar3;
        }
        if (iVar5 <= iVar4) {
          iVar4 = 0;
        }
      }
      LastTauntPrinted[in_ECX] = iVar4;
      pcVar2 = CPUTeamName;
      do {
        cVar1 = *pcVar2;
        pcVar2 = pcVar2 + 1;
      } while (cVar1 != '\0');
      sprintf_s<512>(&TempBuffer,"%.255s : %.*s\n");
      if ((((g_pElapsedTime != (int *)0x0) && (g_pLastTauntPrintedAt != (int *)0x0)) &&
          (g_pTPS != (int *)0x0)) && (*g_pTPS * 0x14 <= *g_pElapsedTime - *g_pLastTauntPrintedAt)) {
        *g_pLastTauntPrintedAt = *g_pElapsedTime;
        iVar4 = IFace_GetInteger("options.play.taunts");
        if (iVar4 != 0) {
          AddToMessagesBox(TempBuffer);
        }
      }
    }
  }
  return;
}


// ---------------------------------------------------------------------
// CleanupTaunts  @ 4fc09550  lines 214-220


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

