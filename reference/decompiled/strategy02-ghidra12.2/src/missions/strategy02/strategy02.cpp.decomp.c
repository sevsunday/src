// Reconstructed by Ghidra from Strategy02.dll + Strategy02.pdb
// Original source file: /e:/github/vsr_dll_source/missions/strategy02/strategy02.cpp
// Functions are ordered by original source line. This is decompiler
// output, not the author's source: names/types come from the PDB,
// local variable names and control flow are reconstructed.


// ---------------------------------------------------------------------
// Strategy02::Strategy02  @ 4fc46ea4  lines 72-113


/* WARNING: Function: _EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: _EH_epilog3 replaced with injection: EH_epilog3 */

Strategy02 * __thiscall Strategy02::Strategy02(Strategy02 *this)

{
  char (*pacVar1) [64];
  char *in_stack_ffffffdc;
  
  LuaMission::LuaMission((LuaMission *)this);
  this->_padding_ = (int)_vftable_;
  pacVar1 = this->SavedPilotODF;
  *(char *)((int)(pacVar1 + 8) + 0x1c) = '\0';
  *(char *)((int)(pacVar1 + 8) + 0x1d) = '\0';
  *(char *)((int)(pacVar1 + 8) + 0x1e) = '\0';
  *(char *)((int)(pacVar1 + 8) + 0x1f) = '\0';
  pacVar1 = this->SavedPilotODF;
  *(char *)((int)(pacVar1 + 8) + 0x20) = '\0';
  *(char *)((int)(pacVar1 + 8) + 0x21) = '\0';
  *(char *)((int)(pacVar1 + 8) + 0x22) = '\0';
  *(char *)((int)(pacVar1 + 8) + 0x23) = '\0';
  pacVar1 = this->SavedPilotODF;
  *(char *)((int)(pacVar1 + 8) + 0x24) = '\0';
  *(char *)((int)(pacVar1 + 8) + 0x25) = '\0';
  *(char *)((int)(pacVar1 + 8) + 0x26) = '\0';
  *(char *)((int)(pacVar1 + 8) + 0x27) = '\0';
  pacVar1 = this->SavedPilotODF;
  *(char *)((int)(pacVar1 + 8) + 0x28) = '\0';
  *(char *)((int)(pacVar1 + 8) + 0x29) = '\0';
  *(char *)((int)(pacVar1 + 8) + 0x2a) = '\0';
  *(char *)((int)(pacVar1 + 8) + 0x2b) = '\0';
  pacVar1 = this->SavedPilotODF;
  *(char *)((int)(pacVar1 + 8) + 0x2c) = '\0';
  *(char *)((int)(pacVar1 + 8) + 0x2d) = '\0';
  *(char *)((int)(pacVar1 + 8) + 0x2e) = '\0';
  *(char *)((int)(pacVar1 + 8) + 0x2f) = '\0';
  pacVar1 = this->SavedPilotODF;
  *(char *)((int)(pacVar1 + 8) + 0x30) = '\0';
  *(char *)((int)(pacVar1 + 8) + 0x31) = '\0';
  *(char *)((int)(pacVar1 + 8) + 0x32) = '\0';
  *(char *)((int)(pacVar1 + 8) + 0x33) = '\0';
  pacVar1 = this->SavedPilotODF;
  *(char *)((int)(pacVar1 + 8) + 0x34) = '\0';
  *(char *)((int)(pacVar1 + 8) + 0x35) = '\0';
  *(char *)((int)(pacVar1 + 8) + 0x36) = '\0';
  *(char *)((int)(pacVar1 + 8) + 0x37) = '\0';
  pacVar1 = this->SavedPilotODF;
  *(char *)((int)(pacVar1 + 8) + 0x38) = '\0';
  *(char *)((int)(pacVar1 + 8) + 0x39) = '\0';
  *(char *)((int)(pacVar1 + 8) + 0x3a) = '\0';
  *(char *)((int)(pacVar1 + 8) + 0x3b) = '\0';
  pacVar1 = this->SavedPilotODF;
  *(char *)((int)(pacVar1 + 8) + 0x3c) = '\0';
  *(char *)((int)(pacVar1 + 8) + 0x3d) = '\0';
  *(char *)((int)(pacVar1 + 8) + 0x3e) = '\0';
  *(char *)((int)(pacVar1 + 8) + 0x3f) = '\0';
  *(char *)((int)(this->SavedPilotODF + 9) + 0) = '\0';
  *(char *)((int)(this->SavedPilotODF + 9) + 1) = '\0';
  *(char *)((int)(this->SavedPilotODF + 9) + 2) = '\0';
  *(char *)((int)(this->SavedPilotODF + 9) + 3) = '\0';
  pacVar1 = this->SavedPilotODF;
  *(char *)((int)(pacVar1 + 9) + 4) = '\0';
  *(char *)((int)(pacVar1 + 9) + 5) = '\0';
  *(char *)((int)(pacVar1 + 9) + 6) = '\0';
  *(char *)((int)(pacVar1 + 9) + 7) = '\0';
  pacVar1 = this->SavedPilotODF;
  *(char *)((int)(pacVar1 + 9) + 8) = '\0';
  *(char *)((int)(pacVar1 + 9) + 9) = '\0';
  *(char *)((int)(pacVar1 + 9) + 10) = '\0';
  *(char *)((int)(pacVar1 + 9) + 0xb) = '\0';
  pacVar1 = this->SavedPilotODF;
  *(char *)((int)(pacVar1 + 9) + 0xc) = '\0';
  *(char *)((int)(pacVar1 + 9) + 0xd) = '\0';
  *(char *)((int)(pacVar1 + 9) + 0xe) = '\0';
  *(char *)((int)(pacVar1 + 9) + 0xf) = '\0';
  pacVar1 = this->SavedPilotODF;
  *(char *)((int)(pacVar1 + 9) + 0x10) = '\0';
  *(char *)((int)(pacVar1 + 9) + 0x11) = '\0';
  *(char *)((int)(pacVar1 + 9) + 0x12) = '\0';
  *(char *)((int)(pacVar1 + 9) + 0x13) = '\0';
  pacVar1 = this->SavedPilotODF;
  *(char *)((int)(pacVar1 + 9) + 0x14) = '\0';
  *(char *)((int)(pacVar1 + 9) + 0x15) = '\0';
  *(char *)((int)(pacVar1 + 9) + 0x16) = '\0';
  *(char *)((int)(pacVar1 + 9) + 0x17) = '\0';
  this->m_TeamPos[0x24] = 2.8026e-44;
  EnableHighTPS((int *)(this->m_TeamPos + 0x24));
  AllowRandomTracks(true);
  this[1]._padding_ = 0x1be;
  this[1]._padding_ = (int)((int)&this[1]._padding_ + 1);
  this[1]._padding_ = (int)&this[1]._padding_;
  this[1]._padding_ = (int)&this[1]._padding_;
  this[1]._padding_ = 0x86;
  this[1]._padding_ = 0x40;
  this[1]._padding_ = 0xff;
  this[1]._padding_ = (int)(this->m_TeamPos + 0x26);
  GetMapTRNFilename();
  TRNAllies::SetupTRNAllies(in_stack_ffffffdc);
  if ((void *)this[1]._padding_ != (void *)0x0) {
    memset((void *)this[1]._padding_,0,this[1]._padding_ << 2);
  }
  if ((void *)this[1]._padding_ != (void *)0x0) {
    memset((void *)this[1]._padding_,0,this[1]._padding_ << 2);
  }
  if ((void *)this[1]._padding_ != (void *)0x0) {
    memset((void *)this[1]._padding_,0,this[1]._padding_ << 2);
  }
  if ((void *)this[1]._padding_ != (void *)0x0) {
    memset((void *)this[1]._padding_,0,this[1]._padding_);
  }
  memset(this->SavedPilotODF[9] + 0x18,0,0x3f00);
  return this;
}


// ---------------------------------------------------------------------
// Strategy02::~Strategy02  @ 4fc46d77  lines 115-117


void __thiscall Strategy02::~Strategy02(Strategy02 *this)

{
  char (*pacVar1) [64];
  void *pvVar2;
  uint unaff_EDI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 uStack_8;
  
  uStack_8 = 0xffffffff;
  puStack_c = &__ehhandler___1Strategy02__UAE_XZ;
  local_10 = ExceptionList;
  pvVar2 = (void *)(__security_cookie ^ (int)register0x00000010 - 4U);
  ExceptionList = &local_10;
  this->_padding_ = (int)_vftable_;
  CleanupTaunts();
  if (*(int *)(this->SavedPilotODF[9] + 0xc) != 0) {
    std::_Deallocate<8,0>(pvVar2,unaff_EDI);
    pacVar1 = this->SavedPilotODF;
    *(char *)((int)(pacVar1 + 9) + 0xc) = '\0';
    *(char *)((int)(pacVar1 + 9) + 0xd) = '\0';
    *(char *)((int)(pacVar1 + 9) + 0xe) = '\0';
    *(char *)((int)(pacVar1 + 9) + 0xf) = '\0';
    pacVar1 = this->SavedPilotODF;
    *(char *)((int)(pacVar1 + 9) + 0x10) = '\0';
    *(char *)((int)(pacVar1 + 9) + 0x11) = '\0';
    *(char *)((int)(pacVar1 + 9) + 0x12) = '\0';
    *(char *)((int)(pacVar1 + 9) + 0x13) = '\0';
    pacVar1 = this->SavedPilotODF;
    *(char *)((int)(pacVar1 + 9) + 0x14) = '\0';
    *(char *)((int)(pacVar1 + 9) + 0x15) = '\0';
    *(char *)((int)(pacVar1 + 9) + 0x16) = '\0';
    *(char *)((int)(pacVar1 + 9) + 0x17) = '\0';
  }
  if (*(int *)this->SavedPilotODF[9] != 0) {
    std::_Deallocate<8,0>(pvVar2,unaff_EDI);
    *(char *)((int)(this->SavedPilotODF + 9) + 0) = '\0';
    *(char *)((int)(this->SavedPilotODF + 9) + 1) = '\0';
    *(char *)((int)(this->SavedPilotODF + 9) + 2) = '\0';
    *(char *)((int)(this->SavedPilotODF + 9) + 3) = '\0';
    pacVar1 = this->SavedPilotODF;
    *(char *)((int)(pacVar1 + 9) + 4) = '\0';
    *(char *)((int)(pacVar1 + 9) + 5) = '\0';
    *(char *)((int)(pacVar1 + 9) + 6) = '\0';
    *(char *)((int)(pacVar1 + 9) + 7) = '\0';
    pacVar1 = this->SavedPilotODF;
    *(char *)((int)(pacVar1 + 9) + 8) = '\0';
    *(char *)((int)(pacVar1 + 9) + 9) = '\0';
    *(char *)((int)(pacVar1 + 9) + 10) = '\0';
    *(char *)((int)(pacVar1 + 9) + 0xb) = '\0';
  }
  if (*(int *)(this->SavedPilotODF[8] + 0x34) != 0) {
    std::_Deallocate<8,0>(pvVar2,unaff_EDI);
    pacVar1 = this->SavedPilotODF;
    *(char *)((int)(pacVar1 + 8) + 0x34) = '\0';
    *(char *)((int)(pacVar1 + 8) + 0x35) = '\0';
    *(char *)((int)(pacVar1 + 8) + 0x36) = '\0';
    *(char *)((int)(pacVar1 + 8) + 0x37) = '\0';
    pacVar1 = this->SavedPilotODF;
    *(char *)((int)(pacVar1 + 8) + 0x38) = '\0';
    *(char *)((int)(pacVar1 + 8) + 0x39) = '\0';
    *(char *)((int)(pacVar1 + 8) + 0x3a) = '\0';
    *(char *)((int)(pacVar1 + 8) + 0x3b) = '\0';
    pacVar1 = this->SavedPilotODF;
    *(char *)((int)(pacVar1 + 8) + 0x3c) = '\0';
    *(char *)((int)(pacVar1 + 8) + 0x3d) = '\0';
    *(char *)((int)(pacVar1 + 8) + 0x3e) = '\0';
    *(char *)((int)(pacVar1 + 8) + 0x3f) = '\0';
  }
  if (*(int *)(this->SavedPilotODF[8] + 0x28) != 0) {
    std::_Deallocate<8,0>(pvVar2,unaff_EDI);
    pacVar1 = this->SavedPilotODF;
    *(char *)((int)(pacVar1 + 8) + 0x28) = '\0';
    *(char *)((int)(pacVar1 + 8) + 0x29) = '\0';
    *(char *)((int)(pacVar1 + 8) + 0x2a) = '\0';
    *(char *)((int)(pacVar1 + 8) + 0x2b) = '\0';
    pacVar1 = this->SavedPilotODF;
    *(char *)((int)(pacVar1 + 8) + 0x2c) = '\0';
    *(char *)((int)(pacVar1 + 8) + 0x2d) = '\0';
    *(char *)((int)(pacVar1 + 8) + 0x2e) = '\0';
    *(char *)((int)(pacVar1 + 8) + 0x2f) = '\0';
    pacVar1 = this->SavedPilotODF;
    *(char *)((int)(pacVar1 + 8) + 0x30) = '\0';
    *(char *)((int)(pacVar1 + 8) + 0x31) = '\0';
    *(char *)((int)(pacVar1 + 8) + 0x32) = '\0';
    *(char *)((int)(pacVar1 + 8) + 0x33) = '\0';
  }
  if (*(int *)(this->SavedPilotODF[8] + 0x1c) != 0) {
    std::_Deallocate<8,0>(pvVar2,unaff_EDI);
    pacVar1 = this->SavedPilotODF;
    *(char *)((int)(pacVar1 + 8) + 0x1c) = '\0';
    *(char *)((int)(pacVar1 + 8) + 0x1d) = '\0';
    *(char *)((int)(pacVar1 + 8) + 0x1e) = '\0';
    *(char *)((int)(pacVar1 + 8) + 0x1f) = '\0';
    pacVar1 = this->SavedPilotODF;
    *(char *)((int)(pacVar1 + 8) + 0x20) = '\0';
    *(char *)((int)(pacVar1 + 8) + 0x21) = '\0';
    *(char *)((int)(pacVar1 + 8) + 0x22) = '\0';
    *(char *)((int)(pacVar1 + 8) + 0x23) = '\0';
    pacVar1 = this->SavedPilotODF;
    *(char *)((int)(pacVar1 + 8) + 0x24) = '\0';
    *(char *)((int)(pacVar1 + 8) + 0x25) = '\0';
    *(char *)((int)(pacVar1 + 8) + 0x26) = '\0';
    *(char *)((int)(pacVar1 + 8) + 0x27) = '\0';
  }
  LuaMission::~LuaMission((LuaMission *)this);
  ExceptionList = local_10;
  return;
}


// ---------------------------------------------------------------------
// Strategy02::Load  @ 4fc46a20  lines 120-222


bool __thiscall Strategy02::Load(Strategy02 *this,bool param_1)

{
  vector<Strategy02::MorphTankClass,std::allocator<Strategy02::MorphTankClass>_> *pvVar1;
  vector<Strategy02::EmptyShipClass,std::allocator<Strategy02::EmptyShipClass>_> *this_00;
  bool bVar2;
  bool bVar3;
  int *piVar4;
  int iVar5;
  int *extraout_ECX;
  char *unaff_ESI;
  int *unaff_EDI;
  Strategy02 *local_8;
  
  local_8 = this;
  bVar2 = LuaMission::Load((LuaMission *)this,param_1);
  EnableHighTPS((int *)(this->m_TeamPos + 0x24));
  SetAutoGroupUnits(false);
  if (!param_1) {
    StartingVehicleManager::Load(SUB41(unaff_ESI,0));
  }
  WantBotKillMessages();
  if (param_1) {
    if (((this[1]._padding_ != 0) && (this[1]._padding_ != 0)) && (iVar5 = 0, 0 < this[1]._padding_)
       ) {
      do {
        *(undefined1 *)(iVar5 + this[1]._padding_) = 0;
        iVar5 = iVar5 + 1;
      } while (iVar5 < this[1]._padding_);
    }
    if (((this[1]._padding_ != 0) && (this[1]._padding_ != 0)) && (iVar5 = 0, 0 < this[1]._padding_)
       ) {
      do {
        *(undefined4 *)(this[1]._padding_ + iVar5 * 4) = 0;
        iVar5 = iVar5 + 1;
      } while (iVar5 < this[1]._padding_);
    }
    if (((this[1]._padding_ != 0) && (this[1]._padding_ != 0)) && (iVar5 = 0, 0 < this[1]._padding_)
       ) {
      do {
        *(undefined4 *)(this[1]._padding_ + iVar5 * 4) = 0;
        iVar5 = iVar5 + 1;
      } while (iVar5 < this[1]._padding_);
    }
    if (((this[1]._padding_ != 0) && (this[1]._padding_ != 0)) && (iVar5 = 0, 0 < this[1]._padding_)
       ) {
      do {
        *(undefined4 *)(this[1]._padding_ + iVar5 * 4) = 0;
        iVar5 = iVar5 + 1;
      } while (iVar5 < this[1]._padding_);
    }
    return true;
  }
  Read((int *)&local_8,1);
  pvVar1 = (vector<Strategy02::MorphTankClass,std::allocator<Strategy02::MorphTankClass>_> *)
           (this->SavedPilotODF[8] + 0x1c);
  std::vector<Strategy02::MorphTankClass,std::allocator<Strategy02::MorphTankClass>_>::
  _Resize<<lambda_426a7d76e79c44efd532c0834072b57e>_>
            (pvVar1,(uint)local_8,(<lambda_426a7d76e79c44efd532c0834072b57e>)pvVar1);
  if (local_8 != (Strategy02 *)0x0) {
    Read(*(void **)(this->SavedPilotODF[8] + 0x1c),(int)local_8 << 3);
  }
  Read((int *)&local_8,1);
  pvVar1 = (vector<Strategy02::MorphTankClass,std::allocator<Strategy02::MorphTankClass>_> *)
           (this->SavedPilotODF[8] + 0x28);
  std::vector<Strategy02::MorphTankClass,std::allocator<Strategy02::MorphTankClass>_>::
  _Resize<<lambda_426a7d76e79c44efd532c0834072b57e>_>
            (pvVar1,(uint)local_8,(<lambda_426a7d76e79c44efd532c0834072b57e>)pvVar1);
  if (local_8 != (Strategy02 *)0x0) {
    Read(*(void **)(this->SavedPilotODF[8] + 0x28),(int)local_8 << 3);
  }
  Read((int *)&local_8,1);
  this_00 = (vector<Strategy02::EmptyShipClass,std::allocator<Strategy02::EmptyShipClass>_> *)
            (this->SavedPilotODF[8] + 0x34);
  std::vector<Strategy02::EmptyShipClass,std::allocator<Strategy02::EmptyShipClass>_>::
  _Resize<<lambda_4b06d8c16eefdba86b4662f0678c82d0>_>
            (this_00,(uint)local_8,(<lambda_4b06d8c16eefdba86b4662f0678c82d0>)this_00);
  piVar4 = extraout_ECX;
  if (local_8 != (Strategy02 *)0x0) {
    piVar4 = (int *)((int)local_8 * 0xc);
    Read(*(void **)(this->SavedPilotODF[8] + 0x34),(int)piVar4);
  }
  if ((bool *)this[1]._padding_ != (bool *)0x0) {
    piVar4 = (int *)this[1]._padding_;
    Read((bool *)this[1]._padding_,(int)piVar4);
  }
  if ((float *)this[1]._padding_ != (float *)0x0) {
    piVar4 = (int *)this[1]._padding_;
    Read((float *)this[1]._padding_,(int)piVar4);
  }
  if ((int *)this[1]._padding_ != (int *)0x0) {
    piVar4 = (int *)this[1]._padding_;
    Read((int *)this[1]._padding_,(int)piVar4);
  }
  if ((int *)this[1]._padding_ != (int *)0x0) {
    piVar4 = (int *)this[1]._padding_;
    Read((int *)this[1]._padding_,(int)piVar4);
  }
  if (bVar2) {
    piVar4 = (int *)0x400;
    bVar2 = Read(this->SavedPilotODF[9] + 0x18,0x400);
    if (bVar2) {
      piVar4 = (int *)0x400;
      bVar2 = Read(this->PlayerSavedName[9] + 0x18,0x400);
      if (bVar2) {
        piVar4 = (int *)0x400;
        bVar2 = Read(this->PlayerShipWeapons[1][4] + 0x18,0x400);
        if (bVar2) {
          piVar4 = (int *)0x1400;
          bVar2 = Read(this->PlayerShipWeapons[5][0] + 0x18,0x1400);
          if (bVar2) {
            piVar4 = (int *)0x1400;
            bVar2 = Read(this->PlayerPilotWeapons[5][0] + 0x18,0x1400);
            if (bVar2) {
              piVar4 = (int *)0x140;
              bVar2 = Read(&this->PlayerOmega[7].y,0x140);
              if (bVar2) {
                piVar4 = (int *)0x400;
                bVar2 = Read(this->EmptyShipODF[2] + 0x18,0x400);
                if (bVar2) {
                  piVar4 = (int *)0xc0;
                  bVar2 = Read(this->m_AllyTeams + 10,0xc0);
                  if (bVar2) {
                    piVar4 = (int *)0xc0;
                    bVar2 = Read(&this->m_CPUForce,0xc0);
                    if (bVar2) {
                      piVar4 = (int *)0x40;
                      bVar2 = Read(this->m_GoalBeingCaptured + 10,0x40);
                      if (bVar2) {
                        piVar4 = (int *)0x400;
                        bVar2 = Read(this->m_PilotInvTime + 7,0x400);
                        if (bVar2) {
                          bVar2 = true;
                          goto LAB_4fc46cf1;
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  bVar2 = false;
LAB_4fc46cf1:
  if (*(char *)((int)&this[1]._padding_ + 2) != '\0') {
    InitTaunts((int *)(this->m_TeamPos + 0x24),piVar4,unaff_EDI,unaff_ESI);
  }
  if (*(char *)((int)&this[1]._padding_ + 1) != '\0') {
    bVar3 = DoesFileExist((char *)(this->m_GoalBeingCaptured + 10));
    if (bVar3) {
      StopAudio(EasterEggSound);
      EasterEggSound =
           StartAudio2D((char *)(this->m_GoalBeingCaptured + 10),-1.0,0.0,44100.0,true,false);
    }
  }
  UpdateObjectives(this);
  return bVar2;
}


// ---------------------------------------------------------------------
// Strategy02::PostLoad  @ 4fc46991  lines 225-255


bool __thiscall Strategy02::PostLoad(Strategy02 *this,bool param_1)

{
  bool bVar1;
  int *piVar2;
  
  bVar1 = LuaMission::PostLoad((LuaMission *)this,param_1);
  if (param_1) {
    bVar1 = true;
  }
  else {
    for (piVar2 = *(int **)(this->SavedPilotODF[8] + 0x1c);
        piVar2 != *(int **)(this->SavedPilotODF[8] + 0x20); piVar2 = piVar2 + 2) {
      ConvertHandles(piVar2,1);
    }
    for (piVar2 = *(int **)(this->SavedPilotODF[8] + 0x28);
        piVar2 != *(int **)(this->SavedPilotODF[8] + 0x2c); piVar2 = piVar2 + 2) {
      ConvertHandles(piVar2,1);
    }
    for (piVar2 = *(int **)(this->SavedPilotODF[8] + 0x34);
        piVar2 != *(int **)(this->SavedPilotODF[8] + 0x38); piVar2 = piVar2 + 3) {
      ConvertHandles(piVar2,1);
    }
    ConvertHandles((int *)this[1]._padding_,this[1]._padding_);
  }
  return bVar1;
}


// ---------------------------------------------------------------------
// Strategy02::Save  @ 4fc46776  lines 258-315


bool __thiscall Strategy02::Save(Strategy02 *this,bool param_1)

{
  bool bVar1;
  bool unaff_DI;
  Strategy02 *local_c;
  undefined4 uStack_8;
  
  local_c = this;
  uStack_8 = this;
  bVar1 = LuaMission::Save((LuaMission *)this,param_1);
  uStack_8 = (Strategy02 *)CONCAT13(bVar1,(undefined3)uStack_8);
  if (param_1) {
    return true;
  }
  StartingVehicleManager::Save(unaff_DI);
  local_c = (Strategy02 *)
            (*(int *)(this->SavedPilotODF[8] + 0x20) - *(int *)(this->SavedPilotODF[8] + 0x1c) >> 3)
  ;
  Write((int *)&local_c,1);
  if (local_c != (Strategy02 *)0x0) {
    Write(*(void **)(this->SavedPilotODF[8] + 0x1c),(int)local_c << 3);
  }
  local_c = (Strategy02 *)
            (*(int *)(this->SavedPilotODF[8] + 0x2c) - *(int *)(this->SavedPilotODF[8] + 0x28) >> 3)
  ;
  Write((int *)&local_c,1);
  if (local_c != (Strategy02 *)0x0) {
    Write(*(void **)(this->SavedPilotODF[8] + 0x28),(int)local_c << 3);
  }
  local_c = (Strategy02 *)
            ((*(int *)(this->SavedPilotODF[8] + 0x38) - *(int *)(this->SavedPilotODF[8] + 0x34)) /
            0xc);
  Write((int *)&local_c,1);
  if (local_c != (Strategy02 *)0x0) {
    Write(*(void **)(this->SavedPilotODF[8] + 0x34),(int)local_c * 0xc);
  }
  if ((bool *)this[1]._padding_ != (bool *)0x0) {
    Write((bool *)this[1]._padding_,this[1]._padding_);
  }
  if ((float *)this[1]._padding_ != (float *)0x0) {
    Write((float *)this[1]._padding_,this[1]._padding_);
  }
  if ((int *)this[1]._padding_ != (int *)0x0) {
    Write((int *)this[1]._padding_,this[1]._padding_);
  }
  if ((int *)this[1]._padding_ != (int *)0x0) {
    Write((int *)this[1]._padding_,this[1]._padding_);
  }
  if (((((uStack_8._3_1_ == '\0') || (bVar1 = Write(this->SavedPilotODF[9] + 0x18,0x400), !bVar1))
       || (bVar1 = Write(this->PlayerSavedName[9] + 0x18,0x400), !bVar1)) ||
      ((((bVar1 = Write(this->PlayerShipWeapons[1][4] + 0x18,0x400), !bVar1 ||
         (bVar1 = Write(this->PlayerShipWeapons[5][0] + 0x18,0x1400), !bVar1)) ||
        ((bVar1 = Write(this->PlayerPilotWeapons[5][0] + 0x18,0x1400), !bVar1 ||
         ((bVar1 = Write(&this->PlayerOmega[7].y,0x140), !bVar1 ||
          (bVar1 = Write(this->EmptyShipODF[2] + 0x18,0x400), !bVar1)))))) ||
       (bVar1 = Write(this->m_AllyTeams + 10,0xc0), !bVar1)))) ||
     (((bVar1 = Write(&this->m_CPUForce,0xc0), !bVar1 ||
       (bVar1 = Write(this->m_GoalBeingCaptured + 10,0x40), !bVar1)) ||
      (bVar1 = Write(this->m_PilotInvTime + 7,0x400), !bVar1)))) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  return bVar1;
}


// ---------------------------------------------------------------------
// Strategy02::GetNextRandomVehicleODF  @ 4fc46762  lines 318-320


char * __thiscall Strategy02::GetNextRandomVehicleODF(Strategy02 *this,int param_1)

{
  char *pcVar1;
  
  pcVar1 = GetPlayerODF(param_1,Randomize_None);
  return pcVar1;
}


// ---------------------------------------------------------------------
// Strategy02::UpdateObjectives  @ 4fc4672f  lines 323-329


void __thiscall Strategy02::UpdateObjectives(Strategy02 *this)

{
  char *pcVar1;
  
  ClearObjectives();
  if (this->UserTarget[9] == 4) {
    pcVar1 = "mpobjective_stcap.otf";
  }
  else {
    pcVar1 = "mpobjective_st.otf";
  }
  AddObjective(pcVar1,-1,-1.0);
  return;
}


// ---------------------------------------------------------------------
// Strategy02::AddObject  @ 4fc4616f  lines 332-648


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall Strategy02::AddObject(Strategy02 *this,int param_1)

{
  float *pfVar1;
  vector<Strategy02::MorphTankClass,std::allocator<Strategy02::MorphTankClass>_> *pvVar2;
  <lambda_4b06d8c16eefdba86b4662f0678c82d0> <Var3;
  vector<Strategy02::EmptyShipClass,std::allocator<Strategy02::EmptyShipClass>_> *this_00;
  bool bVar4;
  char *pcVar5;
  int iVar6;
  long lVar7;
  int *piVar8;
  int *piVar9;
  int iVar10;
  int unaff_ESI;
  int *unaff_EDI;
  code *pcVar11;
  char (*pacVar12) [64];
  Vector local_e8;
  code *local_dc;
  int local_d8;
  int *local_d4;
  int *local_d0;
  int local_cc;
  char local_c8 [64];
  char local_88 [64];
  char local_48 [64];
  undefined4 local_8;
  
  local_8 = __security_cookie ^ (uint)(local_48 + 0x44);
  if (*(char *)((int)&this[1]._padding_ + 2) == '\0') {
    LuaMission::AddObject((LuaMission *)this,param_1);
  }
  GetObjInfo(param_1,Get_CFG,local_88);
  bVar4 = DoesODFExist(local_88);
  if (!bVar4) {
    pcVar5 = strchr(local_88,0x3a);
    strncpy_s(local_88,0x40,local_88,(int)pcVar5 - (int)local_88);
  }
  local_d4 = (int *)this->m_TeamPos[0x2d];
  local_d0 = (int *)this->m_TeamPos[0x2e];
  GetObjInfo(param_1,Get_GOClass,local_48);
  pcVar11 = _stricmp_exref;
  local_dc = _stricmp_exref;
  iVar6 = _stricmp(local_48,"CLASS_TURRETTANK");
  local_d8 = CONCAT31((int3)((uint)-iVar6 >> 8),'\x01' - (iVar6 != 0));
  if (((this->m_TeamPos[0x28] == 0.0) &&
      (iVar6 = GetVarItemInt("network.session.ivar117"), iVar6 != 0)) &&
     (iVar6 = _stricmp(local_48,"CLASS_SCRAP"), iVar6 == 0)) {
    RemoveObject(param_1);
  }
  else {
    local_cc = GetTeamNum(param_1);
    if ((*(char *)((int)&this[1]._padding_ + 2) == '\0') || (local_cc < 0xb)) {
      iVar6 = _stricmp(local_48,"CLASS_NAVBEACON");
      if ((iVar6 == 0) &&
         (((GetPosition(param_1,&local_e8),
           (float)this->_padding_ <= local_e8.x && local_e8.x != (float)this->_padding_ ||
           (local_e8.x < (float)this->_padding_)) ||
          (((float)this->_padding_ <= local_e8.z && local_e8.z != (float)this->_padding_ ||
           (local_e8.z < (float)this->_padding_)))))) {
        RemoveObject(param_1);
      }
      piVar8 = local_d4;
      piVar9 = local_d0;
    }
    else {
      DispatchHelper::AddToDispatch
                ((DispatchHelper *)this->_padding_,param_1,15.0,false,0,false,false,false,false);
      piVar8 = (int *)this->m_SavedPlayerLocalAmmo[0xd][4];
      piVar9 = (int *)this->m_SavedPlayerLocalAmmo[0xe][0];
    }
    if ((char)local_d8 != '\0') {
      piVar9 = piVar8;
    }
    SetSkill(param_1,(int)piVar9);
    if (((int)this->m_TeamPos[0x28] < 1) &&
       (iVar6 = _stricmp(local_48,"CLASS_SPAWNBUOY"), iVar6 == 0)) {
      pfVar1 = this->m_SavedPlayerLocalAmmo[5] + 2;
      *pfVar1 = (float)((int)*pfVar1 + 1);
    }
    iVar6 = _stricmp(local_48,"CLASS_RECYCLERVEHICLE");
    if (((iVar6 == 0) || (iVar6 = _stricmp(local_48,"CLASS_RECYCLERVEHICLEH"), iVar6 == 0)) ||
       (iVar6 = _stricmp(local_48,"CLASS_RECYCLER"), iVar6 == 0)) {
      if ((*(int *)((int)(this[1].PlayerShipODF + -0x265) + (local_cc + 0xf) * 4) == 0) ||
         (bVar4 = IsAround(*(int *)((int)(this[1].PlayerShipODF + -0x265) + (local_cc + 0xf) * 4)),
         !bVar4)) {
        *(int *)((int)(this[1].PlayerShipODF + -0x265) + (local_cc + 0xf) * 4) = param_1;
      }
      local_d0 = (int *)((int)(this[1].PlayerShipODF + -0x275) + (local_cc + 4) * 4);
      if ((*local_d0 == 0) && (iVar6 = _stricmp(local_48,"CLASS_RECYCLER"), iVar6 == 0)) {
        GetODFInt(0x4fc56bc0,(char *)local_d0,(char *)0x0,unaff_EDI,unaff_ESI);
        local_d8 = *local_d0;
        if (0 < local_d8) {
          memset(local_c8,0,0x40);
          pacVar12 = &local_c8;
          pcVar5 = "BuildItem%d";
          sprintf_s<64>(pacVar12,"BuildItem%d");
          GetODFString((int)local_c8,(char *)0x40,
                       (char *)(this->m_PilotInvTime + local_cc * 0x10 + 7),0,*pacVar12,pcVar5);
        }
      }
    }
    bVar4 = IsTeamplayOn();
    if ((!bVar4) || (*(char *)((int)&this[1]._padding_ + 2) != '\0')) {
      iVar6 = _stricmp(local_48,"CLASS_SCAVENGER");
      if ((iVar6 == 0) || (iVar6 = _stricmp(local_48,"CLASS_SCAVENGERH"), iVar6 == 0)) {
        pvVar2 = (vector<Strategy02::MorphTankClass,std::allocator<Strategy02::MorphTankClass>_> *)
                 (this->SavedPilotODF[8] + 0x1c);
        for (piVar8 = *(int **)pvVar2; piVar8 != *(int **)(this->SavedPilotODF[8] + 0x20);
            piVar8 = piVar8 + 2) {
          if (*piVar8 == param_1) goto LAB_4fc46505;
        }
        std::vector<Strategy02::MorphTankClass,std::allocator<Strategy02::MorphTankClass>_>::
        _Resize<<lambda_426a7d76e79c44efd532c0834072b57e>_>
                  (pvVar2,(*(int *)(this->SavedPilotODF[8] + 0x20) - *(int *)pvVar2 >> 3) + 1,
                   (<lambda_426a7d76e79c44efd532c0834072b57e>)pvVar2);
        iVar6 = *(int *)(this->SavedPilotODF[8] + 0x1c);
        iVar10 = *(int *)(this->SavedPilotODF[8] + 0x20) - iVar6 >> 3;
        *(int *)(iVar6 + -8 + iVar10 * 8) = param_1;
        *(int *)(iVar6 + -4 + iVar10 * 8) = local_cc;
      }
      else {
        iVar6 = _stricmp(local_48,"CLASS_PERSON");
        if ((iVar6 == 0) && (bVar4 = IsPlayer(param_1), !bVar4)) {
          pvVar2 = (vector<Strategy02::MorphTankClass,std::allocator<Strategy02::MorphTankClass>_> *
                   )(this->SavedPilotODF[8] + 0x28);
          for (piVar8 = *(int **)pvVar2; piVar8 != *(int **)(this->SavedPilotODF[8] + 0x2c);
              piVar8 = piVar8 + 2) {
            if (*piVar8 == param_1) goto LAB_4fc46505;
          }
          std::vector<Strategy02::MorphTankClass,std::allocator<Strategy02::MorphTankClass>_>::
          _Resize<<lambda_426a7d76e79c44efd532c0834072b57e>_>
                    (pvVar2,(*(int *)(this->SavedPilotODF[8] + 0x2c) - *(int *)pvVar2 >> 3) + 1,
                     (<lambda_426a7d76e79c44efd532c0834072b57e>)pvVar2);
          iVar6 = *(int *)(this->SavedPilotODF[8] + 0x28);
          iVar10 = *(int *)(this->SavedPilotODF[8] + 0x2c) - iVar6 >> 3;
          *(undefined4 *)(iVar6 + -8 + iVar10 * 8) = 0;
          *(undefined4 *)(iVar6 + -4 + iVar10 * 8) = 0;
          *(int *)(iVar6 + -8 + iVar10 * 8) = param_1;
          *(int *)(iVar6 + -4 + iVar10 * 8) = (int)this->m_TeamPos[0x24] * 0xf;
        }
      }
    }
LAB_4fc46505:
    if (0 < this->UserTarget[10]) {
      bVar4 = IsAround(*(int *)((int)(this[1].PlayerShipODF + -0x265) + (local_cc + 0xf) * 4));
      if ((bVar4) && (0 < *(int *)((int)(this[1].PlayerShipODF + -0x275) + (local_cc + 4) * 4))) {
        iVar6 = _stricmp(local_88,(char *)(this->m_PilotInvTime + local_cc * 0x10 + 7));
        if (iVar6 == 0) {
          <Var3.__this = (vector<Strategy02::EmptyShipClass,std::allocator<Strategy02::EmptyShipClass>_>
                          *)(this->SavedPilotODF[8] + 0x34);
          for (piVar8 = *(int **)<Var3.__this; piVar8 != *(int **)(this->SavedPilotODF[8] + 0x38);
              piVar8 = piVar8 + 3) {
            if (*piVar8 == param_1) goto LAB_4fc4662b;
          }
          this_00 = (vector<Strategy02::EmptyShipClass,std::allocator<Strategy02::EmptyShipClass>_>
                     *)(this->SavedPilotODF[8] + 0x34);
          std::vector<Strategy02::EmptyShipClass,std::allocator<Strategy02::EmptyShipClass>_>::
          _Resize<<lambda_4b06d8c16eefdba86b4662f0678c82d0>_>
                    (this_00,(*(int *)(this->SavedPilotODF[8] + 0x38) - *(int *)<Var3.__this) / 0xc
                             + 1,<Var3);
          iVar6 = *(int *)this_00;
          iVar10 = ((*(int *)(this->SavedPilotODF[8] + 0x38) - iVar6) / 0xc) * 0xc;
          *(undefined4 *)(iVar10 + -8 + iVar6) = 0;
          *(undefined4 *)(iVar10 + -4 + iVar6) = 0;
          *(int *)(iVar10 + -0xc + iVar6) = param_1;
          *(int *)(iVar10 + -8 + iVar6) = this->UserTarget[10];
          lVar7 = GetMaxHealth(param_1);
          *(long *)(iVar10 + -4 + iVar6) = lVar7;
          SetMaxHealth(param_1,0);
          pcVar11 = local_dc;
        }
      }
    }
LAB_4fc4662b:
    if ((0 < this[1]._padding_) && (iVar6 = (*pcVar11)(local_48,"CLASS_MORPHTANK"), iVar6 == 0)) {
      pvVar2 = (vector<Strategy02::MorphTankClass,std::allocator<Strategy02::MorphTankClass>_> *)
               (this->SavedPilotODF + 9);
      for (piVar8 = *(int **)pvVar2; piVar8 != *(int **)(this->SavedPilotODF[9] + 4);
          piVar8 = piVar8 + 2) {
        if (*piVar8 == param_1) goto LAB_4fc46690;
      }
      std::vector<Strategy02::MorphTankClass,std::allocator<Strategy02::MorphTankClass>_>::
      _Resize<<lambda_426a7d76e79c44efd532c0834072b57e>_>
                (pvVar2,(*(int *)(this->SavedPilotODF[9] + 4) - *(int *)pvVar2 >> 3) + 1,
                 (<lambda_426a7d76e79c44efd532c0834072b57e>)pvVar2);
      iVar6 = *(int *)this->SavedPilotODF[9];
      iVar10 = *(int *)(this->SavedPilotODF[9] + 4) - iVar6 >> 3;
      *(undefined4 *)(iVar6 + -8 + iVar10 * 8) = 0;
      *(undefined4 *)(iVar6 + -4 + iVar10 * 8) = 0;
      *(int *)(iVar6 + -8 + iVar10 * 8) = param_1;
    }
LAB_4fc46690:
    local_d0 = (int *)GetCategoryTypeOverride(param_1);
    if (local_d0 == (int *)0xffffffff) {
      local_d0 = (int *)GetCategoryType(param_1);
    }
    if (((int)local_d0 - 1U < 9) &&
       ((iVar6 = (*pcVar11)(local_48,"CLASS_COMMBUKNER"), iVar6 == 0 ||
        (iVar6 = (*pcVar11)(local_48,"CLASS_COMMTOWER"), iVar6 == 0)))) {
      pvVar2 = (vector<Strategy02::MorphTankClass,std::allocator<Strategy02::MorphTankClass>_> *)
               (this->SavedPilotODF[9] + 0xc);
      for (piVar8 = *(int **)pvVar2; piVar8 != *(int **)(this->SavedPilotODF[9] + 0x10);
          piVar8 = piVar8 + 2) {
        if (*piVar8 == param_1) {
          return;
        }
      }
      std::vector<Strategy02::MorphTankClass,std::allocator<Strategy02::MorphTankClass>_>::
      _Resize<<lambda_426a7d76e79c44efd532c0834072b57e>_>
                (pvVar2,(*(int *)(this->SavedPilotODF[9] + 0x10) - *(int *)pvVar2 >> 3) + 1,
                 (<lambda_426a7d76e79c44efd532c0834072b57e>)pvVar2);
      iVar6 = *(int *)pvVar2;
      iVar10 = *(int *)(this->SavedPilotODF[9] + 0x10) - iVar6 >> 3;
      *(int *)(iVar6 + -8 + iVar10 * 8) = param_1;
      *(int **)(iVar6 + -4 + iVar10 * 8) = local_d0;
    }
  }
  return;
}


// ---------------------------------------------------------------------
// Strategy02::DeleteObject  @ 4fc460d9  lines 651-741


void __thiscall Strategy02::DeleteObject(Strategy02 *this,int param_1)

{
  int *piVar1;
  bool bVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  
  if (*(char *)((int)&this[1]._padding_ + 2) == '\0') {
    LuaMission::DeleteObject((LuaMission *)this,param_1);
  }
  iVar3 = GetTeamNum(param_1);
  iVar6 = 0;
  if (((this[1]._padding_ != 0) && (bVar2 = IsPlayer(param_1), bVar2)) &&
     (iVar3 = GetPlayerHandle(iVar3), iVar3 == 0)) {
    SetNoScrapFlagByHandle(param_1);
  }
  piVar4 = *(int **)(this->SavedPilotODF[9] + 0xc);
  piVar1 = *(int **)(this->SavedPilotODF[9] + 0x10);
  piVar5 = piVar4;
  do {
    if (piVar5 == piVar1) {
LAB_4fc4615a:
      while( true ) {
        if (piVar4 == piVar1) {
          return;
        }
        if ((param_1 != *piVar4) && (piVar4[1] == iVar6)) break;
        piVar4 = piVar4 + 2;
      }
      ResetTeamSlot(*piVar4);
      return;
    }
    if (param_1 == *piVar5) {
      iVar6 = piVar5[1];
      goto LAB_4fc4615a;
    }
    piVar5 = piVar5 + 2;
  } while( true );
}


// ---------------------------------------------------------------------
// Strategy02::SetCPUAIPlan  @ 4fc45f69  lines 744-776


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall Strategy02::SetCPUAIPlan(Strategy02 *this,int param_1,int param_2)

{
  bool bVar1;
  char *pcVar2;
  NETWORK_LIST_TYPE unaff_ESI;
  uint unaff_EDI;
  float fVar3;
  char local_188 [128];
  char local_108 [256];
  undefined4 local_8;
  
  local_8 = __security_cookie ^ (uint)(local_108 + 0x104);
  if (*(char *)((int)&this[1]._padding_ + 1) == '\0') {
    *(undefined1 *)((int)&this[1]._padding_ + 1) = 1;
    sprintf_s<128>(&local_188,"network.session.svar%d");
    pcVar2 = GetVarItemStr(local_188);
    if (((pcVar2 == (char *)0x0) ||
        (pcVar2 = DLLUtils::GetCheckedNetworkSvar(unaff_EDI,unaff_ESI), pcVar2 == (char *)0x0)) ||
       (*pcVar2 == '\0')) {
      pcVar2 = "VSR_";
    }
    strcpy_s(CustomAIPNameBase,0x100,pcVar2);
  }
  memset(local_108,0,0x100);
  fVar3 = GetRandomFloat(3.0);
  floor((double)fVar3);
  GetRace(*(int *)((int)(this[1].PlayerShipODF + -0x265) + (param_1 + 0xf) * 4));
  sprintf_s<256>(&local_108,"%s%c%d_%d.aip");
  bVar1 = DoesFileExist(local_108);
  if (!bVar1) {
    GetRace(*(int *)((int)(this[1].PlayerShipODF + -0x265) + (param_1 + 0xf) * 4));
    sprintf_s<256>(&local_108,"%s%c%d_0.aip");
  }
  BZ1Helper::SetAIPFile((BZ1Helper *)this,local_108,param_1);
  if (*(char *)((int)&this[1]._padding_ + 3) != '\0') {
    DoTaunt(unaff_EDI);
  }
  *(undefined1 *)((int)&this[1]._padding_ + 3) = 1;
  return;
}


// ---------------------------------------------------------------------
// Strategy02::GetInitialPlayerPilotODF  @ 4fc45dc5  lines 786-830


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

char * __thiscall
Strategy02::GetInitialPlayerPilotODF(Strategy02 *this,char param_1,int param_2,bool param_3)

{
  bool bVar1;
  int iVar2;
  char *unaff_ESI;
  char *unaff_EDI;
  char *pcVar3;
  char local_88 [64];
  char local_48 [64];
  undefined4 local_8;
  
  local_8 = __security_cookie ^ (uint)(local_48 + 0x44);
  if (0 < param_2) {
    bVar1 = IsTeamplayOn();
    if (bVar1) {
      param_2 = GetCommanderTeam(param_2);
    }
    memset(local_88,0,0x40);
    memset(local_48,0,0x40);
    GetObjInfo(*(int *)((int)(this[1].PlayerShipODF + -0x265) + (param_2 + 0xf) * 4),Get_ODF,
               local_88);
    bVar1 = OpenODF2(unaff_EDI);
    if ((bVar1) &&
       (iVar2 = GetODFString(local_88,"GameObjectClass","classlabel",0x40,local_48,(char *)0x0),
       iVar2 != 0)) {
      CombineStrings(".odf",(char *)0x40,unaff_EDI,(uint)unaff_ESI);
      OpenODF2(unaff_EDI);
    }
    if (param_3) {
      if (this->m_TeamPos[0x2c] != 1.4013e-45) goto LAB_4fc45ea0;
LAB_4fc45f36:
      pcVar3 = "PilotRespawnWithSniper";
    }
    else {
      if ((int)this->m_TeamPos[0x2c] < 2) goto LAB_4fc45f36;
LAB_4fc45ea0:
      pcVar3 = "PilotRespawnWithOutSniper";
    }
    GetODFString("GameObjectClass",pcVar3,(char *)0x40,TempODFName,0,unaff_EDI,unaff_ESI);
  }
  bVar1 = DoesODFExist(TempODFName);
  if ((bVar1) && (param_2 != 0)) goto LAB_4fc45f56;
  if (param_3) {
    if (this->m_TeamPos[0x2c] != 1.4013e-45) goto LAB_4fc45ee3;
LAB_4fc45f4a:
    pcVar3 = "ispilo";
  }
  else {
    if ((int)this->m_TeamPos[0x2c] < 2) goto LAB_4fc45f4a;
LAB_4fc45ee3:
    pcVar3 = "isuser_m";
  }
  strcpy_s(TempODFName,0x40,pcVar3);
  TempODFName[0] = param_1;
  bVar1 = DoesODFExist(TempODFName);
  if (!bVar1) {
    sprintf_s<1024>(&TempMsgString,
                    "ERROR: \'%s\' does not exist. Giving you pilot DEFAULT ISDF! FIX IT!");
    PrintConsoleMessage(TempMsgString);
    TempODFName[0] = 'i';
  }
LAB_4fc45f56:
  return TempODFName;
}


// ---------------------------------------------------------------------
// Strategy02::GetInitialRecyclerODF  @ 4fc45d44  lines 834-844


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

char * __thiscall Strategy02::GetInitialRecyclerODF(Strategy02 *this,char param_1)

{
  char *pcVar1;
  uint unaff_ESI;
  NETWORK_LIST_TYPE in_stack_ffffff78;
  char acStack_82 [126];
  
  sprintf_s<128>((char (*) [128])(acStack_82 + -6),"network.session.svar%d");
  pcVar1 = GetVarItemStr(acStack_82 + -6);
  if (((pcVar1 == (char *)0x0) ||
      (pcVar1 = DLLUtils::GetCheckedNetworkSvar(unaff_ESI,in_stack_ffffff78), pcVar1 == (char *)0x0)
      ) || (*pcVar1 == '\0')) {
    pcVar1 = "ivrecy_m";
  }
  strcpy_s(TempODFName,0x40,pcVar1);
  TempODFName[0] = param_1;
  return TempODFName;
}


// ---------------------------------------------------------------------
// Strategy02::GetSpawnpointForTeam  @ 4fc45a57  lines 872-1006


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Variable defined which should be unmapped: __return_storage_ptr__ */
/* WARNING: Type propagation algorithm not settling */

Vector * __thiscall
Strategy02::GetSpawnpointForTeam(Strategy02 *this,Vector *__return_storage_ptr__,int param_1)

{
  float *pfVar1;
  float fVar2;
  int iVar3;
  bool bVar4;
  uint uVar5;
  uint extraout_EAX;
  uint extraout_EAX_00;
  uint extraout_EAX_01;
  uint extraout_EAX_02;
  uint uVar6;
  uint extraout_ECX;
  int iVar7;
  uint uVar8;
  SpawnpointInfo *pSVar9;
  uint uVar10;
  undefined4 auStackY_44 [2];
  SpawnpointInfo local_28;
  
  local_28.m_DistanceToClosestEnemy = (float)(__security_cookie ^ (int)auStackY_44 + 0x40U);
  local_28.m_Position.z = 0.0;
  local_28.m_Position.y = 0.0;
  local_28.m_Position.x = 0.0;
  auStackY_44[1] = 0x4fc45a86;
  local_28.m_DistanceToClosestAlly = (float)this;
  uVar5 = GetAllSpawnpoints((SpawnpointInfo **)&local_28.m_DistanceToClosestTeamZero,param_1);
  if (uVar5 == 0) {
    pSVar9 = &local_28;
    goto LAB_4fc45a91;
  }
  iVar3 = uVar5 * -4;
  *(uint *)((int)auStackY_44 + iVar3 + 0xcU) = uVar5 * 4;
  uVar10 = 0;
  local_28.m_DistanceToClosestSameTeam = (float)((int)auStackY_44 + iVar3 + 0x10U);
  *(undefined4 *)((int)auStackY_44 + iVar3 + 8U) = 0;
  *(int *)((int)auStackY_44 + uVar5 * 0xfffffffc + 4) = (int)auStackY_44 + iVar3 + 0x10U;
  auStackY_44[-uVar5] = 0x4fc45ab9;
  memset(*(void **)((int)auStackY_44 + uVar5 * 0xfffffffc + 4),
         *(int *)((int)auStackY_44 + iVar3 + 8U),*(size_t *)((int)auStackY_44 + iVar3 + 0xcU));
  uVar8 = 0;
  uVar6 = 0;
  if (uVar5 == 0) {
LAB_4fc45b3b:
    *(undefined4 *)((int)auStackY_44 + iVar3 + 0xcU) = 0x4fc45b41;
    bVar4 = IsTeamplayOn();
    if (!bVar4) {
      *(int *)((int)auStackY_44 + iVar3 + 0xcU) =
           ((int *)((int)local_28.m_DistanceToClosestAlly + 0xe524))[param_1 + -0x48];
      *(int **)((int)auStackY_44 + iVar3 + 8U) = &local_28.m_Handle;
      *(undefined4 *)((int)auStackY_44 + uVar5 * 0xfffffffc + 4) = 0x4fc45b60;
      GetAllSpawnpoints(*(SpawnpointInfo ***)((int)auStackY_44 + iVar3 + 8U),
                        *(int *)((int)auStackY_44 + iVar3 + 0xcU));
      if (uVar5 != 0) {
        uVar6 = uVar10;
        uVar8 = uVar10;
        do {
          fVar2 = (float)((Strategy02 *)((int)local_28.m_DistanceToClosestAlly + 0xe648))->_padding_
          ;
          if (((fVar2 <= *(float *)(local_28.m_Handle + 0x18 + uVar10)) &&
              (fVar2 <= *(float *)((int)local_28.m_DistanceToClosestTeamZero + 0x1c + uVar10))) &&
             (fVar2 <= *(float *)((int)local_28.m_DistanceToClosestTeamZero + 0x20 + uVar10))) {
            *(uint *)((int)local_28.m_DistanceToClosestSameTeam + uVar8 * 4) = uVar6;
            uVar8 = uVar8 + 1;
          }
          uVar6 = uVar6 + 1;
          uVar10 = uVar10 + 0x24;
        } while (uVar6 < uVar5);
        *(undefined4 *)((int)auStackY_44 + iVar3 + 0xcU) = 0;
        uVar10 = *(uint *)((int)auStackY_44 + iVar3 + 0xcU);
        if (uVar8 != 0) {
          local_28.m_Team =
               (int)(float)((double)(int)uVar8 +
                           (double)(&__xmm_41f00000000000000000000000000000)[-((int)uVar8 >> 0x1f)])
          ;
          do {
            iVar7 = local_28.m_Team;
            *(uint *)((int)auStackY_44 + iVar3 + 0xcU) = uVar6;
            *(int *)((int)auStackY_44 + iVar3 + 0xcU) = iVar7;
            *(undefined4 *)((int)auStackY_44 + iVar3 + 8U) = 0x4fc45beb;
            local_28.m_DistanceToClosestAlly =
                 GetRandomFloat(*(float *)((int)auStackY_44 + iVar3 + 0xcU));
            *(undefined4 *)((int)auStackY_44 + iVar3 + 0xcU) = 0x4fc45bf9;
            _ftoui3();
            uVar5 = extraout_EAX_00;
            uVar6 = extraout_EAX_00;
          } while (uVar8 <= extraout_EAX_00);
          goto LAB_4fc45b2c;
        }
      }
    }
    if (uVar5 != 0) {
      uVar6 = uVar10;
      uVar8 = uVar10;
      do {
        fVar2 = (float)((Strategy02 *)((int)local_28.m_DistanceToClosestAlly + 0xe648))->_padding_;
        pfVar1 = (float *)((int)local_28.m_DistanceToClosestTeamZero + 0x18 + uVar10);
        if (((*pfVar1 <= fVar2 && fVar2 != *pfVar1) ||
            (pfVar1 = (float *)((int)local_28.m_DistanceToClosestTeamZero + 0x1c + uVar10),
            *pfVar1 <= fVar2 && fVar2 != *pfVar1)) &&
           ((float)((Strategy02 *)((int)local_28.m_DistanceToClosestAlly + 0xe648))->_padding_ <=
            *(float *)((int)local_28.m_DistanceToClosestTeamZero + 0x20 + uVar10))) {
          *(uint *)((int)local_28.m_DistanceToClosestSameTeam + uVar8 * 4) = uVar6;
          uVar8 = uVar8 + 1;
        }
        uVar6 = uVar6 + 1;
        uVar10 = uVar10 + 0x24;
      } while (uVar6 < uVar5);
      *(undefined4 *)((int)auStackY_44 + iVar3 + 0xcU) = 0;
      uVar10 = *(uint *)((int)auStackY_44 + iVar3 + 0xcU);
      if (uVar8 != 0) {
        local_28.m_Handle =
             (int)(float)((double)(int)uVar8 +
                         (double)(&__xmm_41f00000000000000000000000000000)[-((int)uVar8 >> 0x1f)]);
        do {
          iVar7 = local_28.m_Handle;
          *(uint *)((int)auStackY_44 + iVar3 + 0xcU) = uVar6;
          *(int *)((int)auStackY_44 + iVar3 + 0xcU) = iVar7;
          *(undefined4 *)((int)auStackY_44 + iVar3 + 8U) = 0x4fc45c86;
          local_28.m_Team = (int)GetRandomFloat(*(float *)((int)auStackY_44 + iVar3 + 0xcU));
          *(undefined4 *)((int)auStackY_44 + iVar3 + 0xcU) = 0x4fc45c94;
          _ftoui3();
          uVar6 = extraout_EAX_01;
          uVar5 = extraout_EAX_01;
        } while (uVar8 <= extraout_EAX_01);
        goto LAB_4fc45b2c;
      }
    }
    fVar2 = local_28.m_DistanceToClosestSameTeam;
    if (uVar5 == 0) {
LAB_4fc45d1f:
      *(int *)((int)auStackY_44 + iVar3 + 0xcU) = param_1;
      *(Vector **)((int)auStackY_44 + iVar3 + 8U) = __return_storage_ptr__;
      *(undefined4 *)((int)auStackY_44 + uVar5 * 0xfffffffc + 4) = 0x4fc45d2b;
      GetRandomSpawnpoint(*(Vector **)((int)auStackY_44 + iVar3 + 8U),
                          *(int *)((int)auStackY_44 + iVar3 + 0xcU));
      return __return_storage_ptr__;
    }
    uVar6 = uVar10;
    uVar8 = uVar10;
    do {
      if ((float)((Strategy02 *)((int)local_28.m_DistanceToClosestAlly + 0xe648))->_padding_ <=
          *(float *)((int)local_28.m_DistanceToClosestTeamZero + 0x20 + uVar6)) {
        *(uint *)((int)local_28.m_DistanceToClosestSameTeam + uVar8 * 4) = uVar10;
        uVar8 = uVar8 + 1;
      }
      uVar10 = uVar10 + 1;
      uVar6 = uVar6 + 0x24;
    } while (uVar10 < uVar5);
    if (uVar8 == 0) goto LAB_4fc45d1f;
    local_28.m_Handle =
         (int)(float)((double)(int)uVar8 +
                     (double)(&__xmm_41f00000000000000000000000000000)[-((int)uVar8 >> 0x1f)]);
    do {
      iVar7 = local_28.m_Handle;
      *(uint *)((int)auStackY_44 + iVar3 + 0xcU) = uVar10;
      *(int *)((int)auStackY_44 + iVar3 + 0xcU) = iVar7;
      *(undefined4 *)((int)auStackY_44 + iVar3 + 8U) = 0x4fc45cff;
      local_28.m_Team = (int)GetRandomFloat(*(float *)((int)auStackY_44 + iVar3 + 0xcU));
      *(undefined4 *)((int)auStackY_44 + iVar3 + 0xcU) = 0x4fc45d0d;
      _ftoui3();
      uVar10 = extraout_ECX;
    } while (uVar8 <= extraout_EAX_02);
    iVar3 = *(int *)((int)fVar2 + extraout_EAX_02 * 4);
  }
  else {
    iVar7 = 0;
    do {
      if (*(int *)((int)local_28.m_DistanceToClosestTeamZero + 0xc + iVar7) == param_1) {
        *(uint *)((int)local_28.m_DistanceToClosestSameTeam + uVar8 * 4) = uVar6;
        uVar8 = uVar8 + 1;
      }
      uVar6 = uVar6 + 1;
      iVar7 = iVar7 + 0x24;
    } while (uVar6 < uVar5);
    *(undefined4 *)((int)auStackY_44 + iVar3 + 0xcU) = 0;
    uVar10 = *(uint *)((int)auStackY_44 + iVar3 + 0xcU);
    if (uVar8 == 0) goto LAB_4fc45b3b;
    local_28.m_Handle =
         (int)(float)((double)(int)uVar8 +
                     (double)(&__xmm_41f00000000000000000000000000000)[-((int)uVar8 >> 0x1f)]);
    do {
      iVar7 = local_28.m_Handle;
      *(uint *)((int)auStackY_44 + iVar3 + 0xcU) = uVar6;
      *(int *)((int)auStackY_44 + iVar3 + 0xcU) = iVar7;
      *(undefined4 *)((int)auStackY_44 + iVar3 + 8U) = 0x4fc45b13;
      local_28.m_DistanceToClosestAlly = GetRandomFloat(*(float *)((int)auStackY_44 + iVar3 + 0xcU))
      ;
      *(undefined4 *)((int)auStackY_44 + iVar3 + 0xcU) = 0x4fc45b21;
      _ftoui3();
      uVar5 = extraout_EAX;
      uVar6 = extraout_EAX;
    } while (uVar8 <= extraout_EAX);
LAB_4fc45b2c:
    iVar3 = *(int *)((int)local_28.m_DistanceToClosestSameTeam + uVar5 * 4);
  }
  pSVar9 = (SpawnpointInfo *)((int)local_28.m_DistanceToClosestTeamZero + iVar3 * 0x24);
LAB_4fc45a91:
  __return_storage_ptr__->x = (pSVar9->m_Position).x;
  __return_storage_ptr__->y = (pSVar9->m_Position).y;
  __return_storage_ptr__->z = (pSVar9->m_Position).z;
  return __return_storage_ptr__;
}


// ---------------------------------------------------------------------
// IsRecyclerODF  @ 4fc459c5  lines 1011-1027


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl IsRecyclerODF(int param_1)

{
  int iVar1;
  int in_ECX;
  char local_88 [64];
  char local_48 [64];
  undefined4 local_8;
  
  local_8 = __security_cookie ^ (uint)(local_48 + 0x44);
  if (in_ECX == 0) {
    iVar1 = 0;
  }
  else {
    GetObjInfo(in_ECX,Get_GOClass,local_48);
    iVar1 = _stricmp(local_48,"CLASS_RECYCLERVEHICLE");
    if (((iVar1 == 0) || (iVar1 = _stricmp(local_48,"CLASS_RECYCLER"), iVar1 == 0)) ||
       (iVar1 = _stricmp(local_48,"CLASS_RECYCLERVEHICLEH"), iVar1 == 0)) {
      GetObjInfo(in_ECX,Get_CFG,local_88);
      iVar1 = (int)local_88[0];
    }
    else {
      iVar1 = 0;
    }
  }
  return iVar1;
}


// ---------------------------------------------------------------------
// Strategy02::BuildStartingVehicle  @ 4fc4594d  lines 1033-1049


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __thiscall
Strategy02::BuildStartingVehicle
          (Strategy02 *this,int param_1,int param_2,char *param_3,char *param_4,char *param_5,
          int param_6)

{
  bool bVar1;
  int iVar2;
  char local_48 [64];
  undefined4 local_8;
  
  local_8 = __security_cookie ^ (uint)(local_48 + 0x44);
  strcpy_s(local_48,0x40,param_3);
  local_48[0] = (char)param_2;
  bVar1 = DoesODFExist(local_48);
  if (!bVar1) {
    strcpy_s(local_48,0x40,param_4);
    local_48[0] = (char)param_2;
  }
  iVar2 = BuildObject(local_48,param_1,param_5);
  return iVar2;
}


// ---------------------------------------------------------------------
// Strategy02::BuildStartingVehicle  @ 4fc458da  lines 1053-1069


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __thiscall
Strategy02::BuildStartingVehicle
          (Strategy02 *this,int param_1,int param_2,char *param_3,char *param_4,Vector param_5,
          int param_6)

{
  bool bVar1;
  int iVar2;
  char local_48 [64];
  undefined4 local_8;
  
  local_8 = __security_cookie ^ (uint)(local_48 + 0x44);
  strcpy_s(local_48,0x40,param_3);
  local_48[0] = (char)param_2;
  bVar1 = DoesODFExist(local_48);
  if (!bVar1) {
    strcpy_s(local_48,0x40,param_4);
    local_48[0] = (char)param_2;
  }
  iVar2 = BuildObject(local_48,param_1,&param_5);
  return iVar2;
}


// ---------------------------------------------------------------------
// Strategy02::SetupTeam  @ 4fc4512c  lines 1082-1284


/* WARNING: Function: _alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Unable to track spacebase fully for stack */

void __thiscall Strategy02::SetupTeam(Strategy02 *this,int param_1)

{
  Vector VVar1;
  Vector VVar2;
  Vector VVar3;
  Vector VVar4;
  float *pfVar5;
  char cVar6;
  bool bVar7;
  int iVar8;
  Vector *pVVar9;
  int iVar10;
  char *pcVar11;
  Vector *pVVar12;
  char *pcVar13;
  float *pfVar14;
  undefined4 extraout_ECX;
  Strategy02 *this_00;
  Strategy02 *this_01;
  Strategy02 *this_02;
  Vector *unaff_ESI;
  Vector *unaff_EDI;
  float fVar15;
  double dVar16;
  int aiStackY_370 [128];
  Strategy02 *this_03;
  Matrix *pMVar17;
  undefined1 auStack_142 [2];
  float local_140 [3];
  Vector local_134;
  float *local_128;
  Vector local_124;
  int local_118;
  float *local_114;
  char local_110 [64];
  Matrix local_d0;
  char local_90 [64];
  char local_50 [68];
  uint local_c;
  undefined1 auStack_8 [4];
  
  local_c = __security_cookie ^ (uint)(auStack_8 + 4);
  if (0xe < param_1 - 1U) {
    return;
  }
  if (*(char *)((int)(this[1].PlayerShipODF + -0x274) + param_1 + 0x1c) != '\0') {
    return;
  }
  if ((param_1 == 1) && (*(char *)((int)&this[1]._padding_ + 2) != '\0')) {
    DoTaunt((int)unaff_EDI);
  }
  cVar6 = GetRaceOfTeam(param_1);
  local_118 = CONCAT31(local_118._1_3_,cVar6);
  bVar7 = IsTeamplayOn();
  if (bVar7) {
    iVar10 = local_118;
    iVar8 = WhichTeamGroup(param_1);
    SetMPTeamRace(iVar8,(char)iVar10);
  }
  local_124.x = 0.0;
  local_124.y = 0.0;
  local_124.z = 0.0;
  if (*(char *)((int)&this[1]._padding_ + 2) != '\0') {
    memset(&local_d0,0,0x40);
    sprintf_s<64>((char (*) [64])&local_d0,"Player_%d");
    local_114 = (float *)0x0;
    GetPathPoints((char *)&local_d0,(uint *)&local_114,(float *)0x0);
    pfVar5 = local_114;
    iVar10 = (int)local_114 * -8;
    *(undefined1 **)(auStack_142 + iVar10 + -0x12) = auStack_142 + iVar10 + -0xe;
    local_128 = (float *)(auStack_142 + iVar10 + -0xe);
    *(float ***)(auStack_142 + iVar10 + -0x16) = &local_114;
    aiStackY_370[(int)pfVar5 * -2 + 0x85] = (int)&local_d0;
    aiStackY_370[(int)pfVar5 * -2 + 0x84] = 0x4fc45245;
    bVar7 = GetPathPoints((char *)aiStackY_370[(int)pfVar5 * -2 + 0x85],
                          *(uint **)(auStack_142 + iVar10 + -0x16),
                          *(float **)(auStack_142 + iVar10 + -0x12));
    pfVar14 = local_128;
    if (bVar7) {
      *(undefined4 *)(auStack_142 + iVar10 + -0x12) = extraout_ECX;
      *(undefined4 *)(auStack_142 + iVar10 + -0x16) = extraout_ECX;
      fVar15 = *pfVar14;
      *(float *)(auStack_142 + iVar10 + -0x12) = pfVar14[1];
      local_134.x = fVar15;
      *(float *)(auStack_142 + iVar10 + -0x16) = fVar15;
      aiStackY_370[(int)pfVar5 * -2 + 0x85] = 0x4fc45276;
      local_134.y = TerrainFindFloor(*(float *)(auStack_142 + iVar10 + -0x16),
                                     *(float *)(auStack_142 + iVar10 + -0x12));
      local_134.z = pfVar14[1];
      local_124.x = local_134.x;
      local_124.y = local_134.y;
      local_124.z = local_134.z;
    }
    pfVar14 = this->m_SavedPlayerLocalAmmo[0xe] + 2;
    *pfVar14 = (float)((int)*pfVar14 + 1);
    if (__real_3dcccccd <=
        local_124.y * local_124.y + local_124.x * local_124.x + local_124.z * local_124.z)
    goto LAB_4fc4531a;
  }
  pVVar9 = GetSpawnpointForTeam(this,&local_134,param_1);
  local_124.x = pVVar9->x;
  local_124.y = pVVar9->y;
  local_124.z = pVVar9->z;
LAB_4fc4531a:
  *(float *)((int)(this[1].PlayerShipODF + -0x26d) + (param_1 * 3 + 7) * 4) = local_124.x;
  *(float *)((int)(this[1].PlayerShipODF + -0x26d) + (param_1 * 3 + 9) * 4) = local_124.z;
  *(float *)((int)(this[1].PlayerShipODF + -0x26d) + (param_1 * 3 + 8) * 4) = local_124.y;
  iVar10 = GetObjectByTeamSlot(param_1,1);
  if (iVar10 == 0) {
    if (*(char *)((int)&this[1]._padding_ + 2) == '\0') {
      VVar1.y = local_124.y;
      VVar1.x = local_124.x;
      VVar1.z = local_124.z;
      pVVar12 = GetPositionNear(&local_134,VVar1,20.0,40.0);
      pVVar9 = &local_124;
      local_124.x = pVVar12->x;
      local_124.y = pVVar12->y;
      local_124.z = pVVar12->z;
      iVar10 = param_1;
      pcVar11 = GetInitialRecyclerODF(this_00,(char)local_118);
      iVar10 = BuildObject(pcVar11,iVar10,pVVar9);
      SetRandomHeadingAngle(iVar10);
    }
    else {
      GetCenterOfMap(unaff_EDI);
      local_128 = (float *)(local_134.x - local_124.x);
      local_114 = (float *)(local_134.z - local_124.z);
      dVar16 = (double)((float)local_128 * (float)local_128 + (float)local_114 * (float)local_114);
      __libm_sse2_sqrt_precise();
      this_03 = (Strategy02 *)&local_134;
      local_134.y = 0.0;
      local_134.x = (float)local_128 / (float)dVar16;
      local_134.z = (float)local_114 / (float)dVar16;
      Build_Directinal_Matrix((Matrix *)this_03,unaff_EDI,unaff_ESI);
      pMVar17 = &local_d0;
      iVar10 = param_1;
      pcVar11 = GetInitialRecyclerODF(this_03,(char)local_118);
      iVar10 = BuildObject(pcVar11,iVar10,pMVar17);
    }
    *(int *)((int)(this[1].PlayerShipODF + -0x265) + (param_1 + 0xf) * 4) = iVar10;
    SetGroup(iVar10,0);
  }
  local_124.x = *(float *)((int)(this[1].PlayerShipODF + -0x26d) + (param_1 * 3 + 7) * 4);
  local_124.y = *(float *)((int)(this[1].PlayerShipODF + -0x26d) + (param_1 * 3 + 8) * 4);
  local_124.z = *(float *)((int)(this[1].PlayerShipODF + -0x26d) + (param_1 * 3 + 9) * 4);
  memset(local_50,0,0x40);
  memset(local_90,0,0x40);
  memset(local_110,0,0x40);
  pcVar11 = GetInitialRecyclerODF(this_01,(char)local_118);
  strcpy_s(local_50,0x40,pcVar11);
  pcVar11 = ".odf";
  CombineStrings(".odf",(char *)0x40,(char *)unaff_EDI,(uint)unaff_ESI);
  OpenODF2(pcVar11);
  iVar10 = GetODFString(local_50,"GameObjectClass","classlabel",0x40,local_90,(char *)0x0);
  if (iVar10 != 0) {
    CombineStrings(".odf",(char *)0x40,(char *)unaff_EDI,(uint)unaff_ESI);
    OpenODF2((char *)unaff_EDI);
  }
  iVar10 = GetODFString("GameObjectClass","startingVariant",(char *)0x40,local_110,0,
                        (char *)unaff_EDI,(char *)unaff_ESI);
  if (iVar10 == 0) {
    iVar10 = 0x5f;
    pcVar11 = GetInitialRecyclerODF(this_02,(char)local_118);
    pcVar11 = strchr(pcVar11,iVar10);
    if (pcVar11 != (char *)0x0) {
      pcVar11 = pcVar11 + 1;
      pcVar13 = strchr(pcVar11,0x5f);
      if (pcVar13 != (char *)0x0) {
        pcVar11 = pcVar13 + 1;
      }
      strcpy_s(local_110,0x40,pcVar11);
    }
  }
  *(undefined1 *)((int)&this[1]._padding_ + 1) = 1;
  VVar4.y = (float)unaff_EDI;
  VVar4.x = local_124.z;
  VVar4.z = (float)unaff_ESI;
  StartingVehicleManager::CreateVehicles
            ((int)local_110,SUB41(this->m_TeamPos[0x2f],0),(char *)local_124.x,(int)local_124.y,
             VVar4);
  *(undefined1 *)((int)&this[1]._padding_ + 1) = 0;
  (*misnImport.SetScrap)(param_1,0x28);
  bVar7 = IsTeamplayOn();
  if (bVar7) {
    pfVar14 = (float *)GetFirstAlliedTeam(param_1);
    local_128 = pfVar14;
    iVar10 = GetLastAlliedTeam(param_1);
    if ((int)pfVar14 <= iVar10) {
      local_114 = (float *)((int)pfVar14 * 0xc);
      do {
        pcVar11 = GetInitialPlayerPilotODF(this,(char)local_118,(int)pfVar14,false);
        iVar10 = GetPlayerHandle((int)pfVar14);
        SetPilotClass(iVar10,pcVar11);
        if (pfVar14 != (float *)param_1) {
          if (*(char *)((int)&this[1]._padding_ + 2) == '\0') {
            VVar2.y = local_124.y;
            VVar2.x = local_124.x;
            VVar2.z = local_124.z;
            GetPositionNear(&local_134,VVar2,30.0,60.0);
            *(float *)((int)(local_114 + 0x3a58) + (int)this) = local_134.x;
            *(float *)((int)&this[1]._padding_ + (int)local_114) = local_134.y;
            *(float *)((int)(local_114 + 0x3a5a) + (int)this) = local_134.z;
            pfVar14 = local_128;
          }
          else {
            *(float *)((int)(local_114 + 0x3a58) + (int)this) = local_124.x;
            *(float *)((int)&this[1]._padding_ + (int)local_114) = local_124.y;
            *(float *)((int)(local_114 + 0x3a5a) + (int)this) = local_124.z;
          }
        }
        local_114 = local_114 + 3;
        pfVar14 = (float *)((int)pfVar14 + 1);
        local_128 = pfVar14;
        iVar10 = GetLastAlliedTeam(param_1);
      } while ((int)pfVar14 <= iVar10);
    }
  }
  else {
    local_114 = this->m_SavedPlayerLocalAmmo[2] + 1;
    local_128 = (float *)0x1;
    local_118 = 0xc;
    do {
      if ((((local_128 != (float *)param_1) &&
           ((float)this->m_RecyclerHandles[param_1 + -0x48] == *local_114)) &&
          (*(char *)((int)(this[1].PlayerShipODF + -0x273) + (int)local_128 + 0x10) != '\0')) &&
         (*(char *)((int)(this[1].PlayerShipODF + -0x273) + param_1 + 0x10) == '\0')) {
        if (*(char *)((int)&this[1]._padding_ + 2) == '\0') {
          VVar3.y = local_124.y;
          VVar3.x = local_124.x;
          VVar3.z = local_124.z;
          GetPositionNear(&local_134,VVar3,30.0,60.0);
          *(float *)((int)(this[1].PlayerShipODF + -0x26d) + local_118 + 0x1c) = local_134.x;
          *(float *)((int)(this[1].PlayerShipODF + -0x26d) + local_118 + 0x20) = local_134.y;
          fVar15 = local_134.z;
        }
        else {
          *(float *)((int)(this[1].PlayerShipODF + -0x26d) + local_118 + 0x1c) = local_124.x;
          *(float *)((int)(this[1].PlayerShipODF + -0x26d) + local_118 + 0x20) = local_124.y;
          fVar15 = local_124.z;
        }
        *(float *)((int)(this[1].PlayerShipODF + -0x26d) + local_118 + 0x24) = fVar15;
      }
      local_118 = local_118 + 0xc;
      local_128 = (float *)((int)local_128 + 1);
      local_114 = local_114 + 1;
    } while (local_118 < 0xc0);
  }
  iVar10 = GetLocalPlayerTeamNumber();
  if (param_1 == iVar10) {
    UpdateObjectives(this);
  }
  *(undefined1 *)((int)(this[1].PlayerShipODF + -0x274) + param_1 + 0x1c) = 1;
  return;
}


// ---------------------------------------------------------------------
// Strategy02::SetupPlayer  @ 4fc44583  lines 1290-1630


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall Strategy02::SetupPlayer(Strategy02 *this,int param_1)

{
  Vector VVar1;
  Vector VVar2;
  undefined1 auVar3 [12];
  undefined1 auVar4 [12];
  code *pcVar5;
  bool bVar6;
  char cVar7;
  Vector *pVVar8;
  int iVar9;
  float fVar10;
  float fVar11;
  Matrix *pMVar12;
  char *pcVar13;
  float *pfVar14;
  float (*pafVar15) [5];
  float fVar16;
  Vector *unaff_ESI;
  Vector *unaff_EDI;
  float *pfVar17;
  int *piVar18;
  double dVar19;
  undefined1 auStack_b4 [7];
  char local_ad;
  Vector local_ac;
  Vector *local_a0;
  float local_9c;
  float local_98;
  code *local_94;
  float *local_90;
  float *local_8c;
  code *local_88;
  char *local_84;
  float local_80;
  float *local_7c;
  code *local_78;
  float local_74;
  float *local_70;
  int *local_6c;
  char *local_68;
  Matrix local_64;
  undefined4 local_20;
  undefined4 uStack_1c;
  float fStack_18;
  uint local_c;
  
  local_c = __security_cookie ^ (uint)auStack_b4;
  local_ac.x = 0.0;
  local_ac.y = 0.0;
  local_ac.z = 0.0;
  local_7c = (float *)param_1;
  local_70 = (float *)0x0;
  local_80 = 0.0;
  if (0xf < (uint)param_1) {
    return 0;
  }
  this->m_TeamPos[param_1 + 0x30] = this->m_TeamPos[0x28];
  local_94 = (code *)WhichTeamGroup(param_1);
  local_a0 = (Vector *)local_80;
  local_74 = local_80;
  local_98 = local_80;
  if (*(char *)((int)&this[1]._padding_ + 2) != '\0') {
    pVVar8 = GetCenterOfMap(unaff_EDI);
    local_80 = pVVar8->x;
    local_9c = pVVar8->y;
    local_74 = pVVar8->z;
    param_1 = (int)local_7c;
  }
  pcVar5 = local_94;
  local_a0 = (Vector *)local_80;
  local_98 = local_74;
  bVar6 = IsTeamplayOn();
  if ((!bVar6) || ((int)pcVar5 < 0)) {
    if (*(char *)((int)(param_1 + 0xe7d4) + (int)this) == '\0') {
      if ((int)this->m_SavedPlayerLocalAmmo[5][2] <= (int)this->m_SavedPlayerLocalAmmo[5][3]) {
        pfVar17 = (float *)0x1;
        do {
          if (pfVar17 != (float *)param_1) {
            UnAlly(param_1,(int)pfVar17);
            UnAlly((int)pfVar17,param_1);
          }
          pfVar17 = (float *)((int)pfVar17 + 1);
        } while ((int)pfVar17 < 0x10);
        *(undefined1 *)((int)(param_1 + 0xe7d4) + (int)this) = 1;
        pafVar15 = this->m_SavedPlayerLocalAmmo + 6;
        iVar9 = 0x10;
        fVar11 = -NAN;
        do {
          pfVar17 = *pafVar15;
          pafVar15 = (float (*) [5])(*pafVar15 + 1);
          fVar10 = *pfVar17;
          if ((int)*pfVar17 <= (int)fVar11) {
            fVar10 = fVar11;
          }
          iVar9 = iVar9 + -1;
          fVar11 = fVar10;
        } while (iVar9 != 0);
        fVar11 = this->m_SavedPlayerLocalAmmo[5][4];
        if ((int)fVar11 < 0x10) {
          piVar18 = this->m_RecyclerHandles + (int)fVar11 + -0x34;
          do {
            fVar16 = (float)((int)fVar11 + 1);
            if (*piVar18 != 0) {
              if ((int)fVar10 < (int)fVar16) {
                fVar16 = 0.0;
              }
              this->m_SavedPlayerLocalAmmo[5][4] = fVar16;
              goto LAB_4fc4481b;
            }
            piVar18 = piVar18 + 1;
            fVar11 = fVar16;
          } while ((int)fVar16 < 0x10);
        }
        fVar11 = 0.0;
LAB_4fc4481b:
        this->m_RecyclerHandles[(int)(param_1 + -0x48)] =
             this->m_RecyclerHandles[(int)fVar11 + -0x48];
        pfVar17 = (float *)0x1;
        local_8c = this->m_SavedPlayerLocalAmmo[2] + 1;
        do {
          if (((0 < (int)*local_8c) && (pfVar17 != (float *)param_1)) &&
             (*local_8c == (float)this->m_RecyclerHandles[(int)(param_1 + -0x48)])) {
            Ally((int)pfVar17,param_1);
            Ally(param_1,(int)pfVar17);
            *(undefined1 *)((int)&this[1]._padding_ + (int)pfVar17) = 1;
            *(undefined1 *)((int)(param_1 + 0xe7c0) + (int)this) = 1;
          }
          pfVar17 = (float *)((int)pfVar17 + 1);
          local_8c = local_8c + 1;
        } while ((int)pfVar17 < 0x10);
        local_ac.x = *(float *)((int)(this[1].PlayerShipODF + -0x26d) +
                               (this->m_RecyclerHandles
                                [this->m_RecyclerHandles[(int)(param_1 + -0x48)] + -0x34] * 3 + 7) *
                               4);
        local_ac.z = *(float *)((int)(this[1].PlayerShipODF + -0x26d) +
                               (this->m_RecyclerHandles
                                [this->m_RecyclerHandles[(int)(param_1 + -0x48)] + -0x34] * 3 + 9) *
                               4);
        local_ac.y = TerrainFindFloor(local_ac.x,local_ac.z);
        local_ac.y = local_ac.y + ___real_40200000;
        this->m_RecyclerHandles
        [this->m_RecyclerHandles[this->m_RecyclerHandles[(int)(param_1 + -0x48)] + -0x34] + -0x24] =
             this->m_RecyclerHandles
             [this->m_RecyclerHandles[this->m_RecyclerHandles[(int)(param_1 + -0x48)] + -0x34] +
              -0x24] + 1;
        if (*(char *)((int)&this[1]._padding_ + 2) == '\0') {
          VVar1.y = local_ac.y;
          VVar1.x = local_ac.x;
          VVar1.z = local_ac.z;
          pMVar12 = (Matrix *)GetPositionNear(&local_64.right,VVar1,30.0,60.0);
        }
        else {
          local_94 = (code *)(local_80 - local_ac.x);
          local_78 = (code *)(local_74 - local_ac.z);
          dVar19 = (double)((float)local_94 * (float)local_94 + (float)local_78 * (float)local_78);
          __libm_sse2_sqrt_precise();
          local_9c = 0.0;
          local_a0 = (Vector *)((float)local_94 / (float)dVar19);
          local_98 = (float)local_78 / (float)dVar19;
          auVar3._4_4_ = (float)this->m_RecyclerHandles
                                [this->m_RecyclerHandles
                                 [this->m_RecyclerHandles[(int)(param_1 + -0x48)] + -0x34] + -0x24]
                         * ___real_41700000 * __real_3c8efa35;
          auVar3._0_4_ = local_98;
          auVar3._8_4_ = 0;
          pVVar8 = HRotateFront(local_a0,(Vector)(auVar3 << 0x20),(float)unaff_EDI);
          pMVar12 = &local_64;
          local_64.right.x = pVVar8->x * __real_42480000 + local_ac.x;
          local_64.right.y = pVVar8->y * __real_42480000 + local_ac.y;
          local_64.right.z = pVVar8->z * __real_42480000 + local_ac.z;
        }
        local_a0 = (Vector *)(pMVar12->right).x;
        local_9c = (pMVar12->right).y;
        local_98 = (pMVar12->right).z;
        *(Vector **)((int)(this[1].PlayerShipODF + -0x26d) + ((int)local_7c * 3 + 7) * 4) = local_a0
        ;
        *(float *)((int)(this[1].PlayerShipODF + -0x26d) + ((int)local_7c * 3 + 8) * 4) = local_9c;
        *(float *)((int)(this[1].PlayerShipODF + -0x26d) + ((int)local_7c * 3 + 9) * 4) = local_98;
        param_1 = (int)local_7c;
        goto LAB_4fc44c47;
      }
      if (*(char *)((int)(param_1 + 0xe7a0) + (int)this) == '\0') {
        this->m_RecyclerHandles[this->m_RecyclerHandles[(int)(param_1 + -0x48)] + -0x34] = param_1;
        pfVar17 = this->m_SavedPlayerLocalAmmo[5] + 3;
        *pfVar17 = (float)((int)*pfVar17 + 1);
      }
      SetupTeam(this,param_1);
      local_ac.z = *(float *)((int)(this[1].PlayerShipODF + -0x26d) + (param_1 * 3 + 9) * 4);
      local_ac.x = *(float *)((int)(this[1].PlayerShipODF + -0x26d) + (param_1 * 3 + 7) * 4);
      local_ac.y = TerrainFindFloor(local_ac.x,local_ac.z);
      local_ac.y = local_ac.y + ___real_40200000;
    }
    else {
      this->m_RecyclerHandles
      [this->m_RecyclerHandles[this->m_RecyclerHandles[(int)(param_1 + -0x48)] + -0x34] + -0x24] =
           this->m_RecyclerHandles
           [this->m_RecyclerHandles[this->m_RecyclerHandles[(int)(param_1 + -0x48)] + -0x34] + -0x24
           ] + 1;
      local_ac.x = *(float *)((int)(this[1].PlayerShipODF + -0x26d) +
                             (this->m_RecyclerHandles
                              [this->m_RecyclerHandles[(int)(param_1 + -0x48)] + -0x34] * 3 + 7) * 4
                             );
      local_ac.z = *(float *)((int)(this[1].PlayerShipODF + -0x26d) +
                             (this->m_RecyclerHandles
                              [this->m_RecyclerHandles[(int)(param_1 + -0x48)] + -0x34] * 3 + 9) * 4
                             );
      local_ac.y = TerrainFindFloor(local_ac.x,local_ac.z);
      local_ac.y = local_ac.y + ___real_40200000;
      if (*(char *)((int)&this[1]._padding_ + 2) != '\0') {
        local_94 = (code *)(local_80 - local_ac.x);
        local_78 = (code *)(local_74 - local_ac.z);
        dVar19 = (double)((float)local_94 * (float)local_94 + (float)local_78 * (float)local_78);
        __libm_sse2_sqrt_precise();
        local_a0 = (Vector *)((float)local_94 / (float)dVar19);
        local_98 = (float)local_78 / (float)dVar19;
        iVar9 = this->m_RecyclerHandles
                [this->m_RecyclerHandles[this->m_RecyclerHandles[(int)(param_1 + -0x48)] + -0x34] +
                 -0x24];
        goto LAB_4fc44b66;
      }
      local_ac.z = *(float *)((int)(this[1].PlayerShipODF + -0x26d) + (param_1 * 3 + 9) * 4);
      local_ac.x = *(float *)((int)(this[1].PlayerShipODF + -0x26d) + (param_1 * 3 + 7) * 4);
      local_ac.y = TerrainFindFloor(local_ac.x,local_ac.z);
      local_ac.y = local_ac.y + ___real_40200000;
    }
  }
  else {
    iVar9 = GetCommanderTeam(param_1);
    SetupTeam(this,iVar9);
    local_ac.z = *(float *)((int)(this[1].PlayerShipODF + -0x26d) + (param_1 * 3 + 9) * 4);
    local_ac.x = *(float *)((int)(this[1].PlayerShipODF + -0x26d) + (param_1 * 3 + 7) * 4);
    local_ac.y = TerrainFindFloor(local_ac.x,local_ac.z);
    local_ac.y = local_ac.y + ___real_40200000;
    if (*(char *)((int)&this[1]._padding_ + 2) != '\0') {
      local_94 = (code *)(local_80 - local_ac.x);
      local_78 = (code *)(local_74 - local_ac.z);
      dVar19 = (double)((float)local_94 * (float)local_94 + (float)local_78 * (float)local_78);
      __libm_sse2_sqrt_precise();
      iVar9 = 1;
      if (5 < param_1) {
        iVar9 = 7;
      }
      iVar9 = param_1 - iVar9;
      local_a0 = (Vector *)((float)local_94 / (float)dVar19);
      local_98 = (float)local_78 / (float)dVar19;
LAB_4fc44b66:
      local_9c = 0.0;
      auVar4._4_4_ = (float)iVar9 * ___real_41700000 * __real_3c8efa35;
      auVar4._0_4_ = local_98;
      auVar4._8_4_ = 0;
      pVVar8 = HRotateFront(local_a0,(Vector)(auVar4 << 0x20),(float)unaff_EDI);
      local_a0 = (Vector *)pVVar8->x;
      local_9c = pVVar8->y;
      local_98 = pVVar8->z;
      local_ac.x = (float)local_a0 * __real_42480000 + local_ac.x;
      local_ac.y = local_9c * __real_42480000 + local_ac.y;
      local_ac.z = local_98 * __real_42480000 + local_ac.z;
      param_1 = (int)local_7c;
      local_64.right.x = local_ac.x;
      local_64.right.y = local_ac.y;
      local_64.right.z = local_ac.z;
    }
  }
LAB_4fc44c47:
  pcVar13 = GetPlayerODF(param_1,Randomize_None);
  local_ad = '\x01';
  local_68 = pcVar13;
  local_84 = GetCVarItemStr(param_1,0);
  local_78 = SetPilotClass_exref;
  local_94 = SetPosition_exref;
  local_88 = _stricmp_exref;
  local_64.up.x = (float)_strnicmp_exref;
  if (this[1]._padding_ == 0) {
    cVar7 = local_ad;
    goto LAB_4fc44d8a;
  }
  iVar9 = _strnicmp(pcVar13 + 1,"vcamr_vsr",9);
  if (iVar9 == 0) {
    cVar7 = '\x01';
  }
  else {
    local_90 = (float *)0x0;
    if (this[1]._padding_ == 1) {
      local_64.rightw = (float)(this->SavedPilotODF[9] + 0x18);
      local_8c = (float *)0x0;
      local_6c = &this[1]._padding_;
      do {
        iVar9 = (*local_88)(local_84,(int)local_64.rightw + 0x800);
        if ((iVar9 == 0) &&
           ((((bVar6 = IsTeamplayOn(), bVar6 &&
              (iVar9 = WhichTeamGroup(param_1), *local_6c == iVar9 + 1)) ||
             ((bVar6 = IsTeamplayOn(), !bVar6 && ((float *)*local_6c == (float *)param_1)))) &&
            (bVar6 = DoesODFExist((char *)local_64.rightw), bVar6)))) {
          local_90 = local_8c;
          local_ad = '\0';
          pfVar17 = local_8c;
          goto LAB_4fc44e87;
        }
        local_6c = local_6c + 1;
        local_8c = (float *)((int)local_8c + 1);
        local_64.rightw = (float)((int)local_64.rightw + 0x40);
      } while ((int)local_8c < 0x10);
      iVar9 = 0;
      pcVar13 = this->PlayerShipWeapons[1][4] + 0x18;
      do {
        if (*pcVar13 == '\0') {
          strcpy_s(this->PlayerShipWeapons[1][(int)(param_1 + 4)] + 0x18,0x40,local_84);
          goto LAB_4fc44e83;
        }
        iVar9 = iVar9 + 1;
        pcVar13 = pcVar13 + 0x40;
      } while (iVar9 < 0x10);
    }
    else if (this[1]._padding_ == 2) {
      bVar6 = IsTeamplayOn();
      if ((((!bVar6) ||
           (iVar9 = WhichTeamGroup(param_1),
           *(int *)((int)(this[1].PlayerShipODF + -0x277) + (undefined1 *)(param_1 + 3) * 4) !=
           iVar9 + 1)) &&
          ((bVar6 = IsTeamplayOn(), bVar6 ||
           (*(float **)((int)(this[1].PlayerShipODF + -0x277) + (undefined1 *)(param_1 + 3) * 4) !=
            (float *)param_1)))) ||
         (bVar6 = DoesODFExist(this->SavedPilotODF[(int)(param_1 + 9)] + 0x18), !bVar6)) {
        bVar6 = IsTeamplayOn();
        if (bVar6) {
          iVar9 = WhichTeamGroup(param_1);
          *(int *)((int)(this[1].PlayerShipODF + -0x277) + (undefined1 *)(param_1 + 3) * 4) =
               iVar9 + 1;
          goto LAB_4fc44d7e;
        }
        *(int *)((int)(this[1].PlayerShipODF + -0x277) + (undefined1 *)(param_1 + 3) * 4) = param_1;
LAB_4fc44e83:
        pfVar17 = (float *)0x0;
      }
      else {
        local_ad = '\0';
        pfVar17 = (float *)param_1;
        local_90 = (float *)param_1;
      }
LAB_4fc44e87:
      if (pfVar17 != (float *)0x0) {
        pMVar12 = (Matrix *)(this->EmptyShipODF[(int)((int)pfVar17 + 2)] + 0x18);
        pfVar14 = (float *)BuildObject(this->SavedPilotODF[(int)((int)pfVar17 + 9)] + 0x18,
                                       (int)local_7c,pMVar12);
        pcVar13 = this->PlayerSavedName[(int)((int)pfVar17 + 9)] + 0x18;
        pfVar17 = pfVar14;
        local_70 = pfVar14;
        (*local_78)();
        ReplaceWeapons((int)((int)(this[1].PlayerShipODF + -0x26a) + ((int)local_90 * 5 + 0xd) * 4),
                       (char (*) [64])0x0,pfVar17,pcVar13);
        SetCurHealth((int)pfVar14,
                     *(long *)((int)(this[1].PlayerShipODF + -0x279) + 0xc + (int)local_90 * 4));
        SetCurAmmo((int)pfVar14,
                   *(int *)((int)(this[1].PlayerShipODF + -0x278) +
                           (undefined1 *)((int)local_90 + 3) * 4));
        (*local_94)(pfVar14,pMVar12);
        pfVar17 = local_90;
        SetVelocity((int)pfVar14,(Vector *)(this->m_AllyTeams + (int)local_90 * 3 + 10));
        SetOmega((int)pfVar14,(Vector *)(this->m_AIRace + (int)pfVar17 * 3 + 6));
        memset(&local_64.up.y,0,0x40);
        GetObjInfo((int)pfVar14,Get_GOClass,(char *)&local_64.up.y);
        pcVar5 = local_88;
        iVar9 = (*local_88)(&local_64.up.y,"CLASS_SCAVENGER");
        if ((iVar9 == 0) || (iVar9 = (*pcVar5)(&local_64.up.y,"CLASS_SCAVENGERH"), iVar9 == 0)) {
          SetScavengerCurScrap
                    ((int)pfVar14,
                     *(int *)((int)(this[1].PlayerShipODF + -0x276) +
                             (undefined1 *)((int)local_90 + 3) * 4));
        }
        if (((undefined1 *)((int)&this[1]._padding_ + 2))[(int)local_90] != '\0') {
          Deploy((int)pfVar14);
        }
        bVar6 = IsTeamplayOn();
        param_1 = (int)local_7c;
        if (bVar6) {
          iVar9 = WhichTeamGroup((int)local_7c);
          pfVar17 = (float *)(iVar9 + 1);
        }
        else {
          pfVar17 = local_7c;
        }
        *(float **)((int)(this[1].PlayerShipODF + -0x277) + (undefined1 *)((int)local_90 + 3) * 4) =
             pfVar17;
        ((undefined1 *)((int)&this[1]._padding_ + 2))[(int)local_90] = 1;
      }
    }
LAB_4fc44d7e:
    pcVar13 = local_68;
    cVar7 = local_ad;
  }
LAB_4fc44d8a:
  if ((this[1]._padding_ == 0) || (cVar7 != '\0')) {
    iVar9 = (*local_88)(local_84,"Krohonus_Legs");
    if (iVar9 == 0) {
      local_70 = (float *)BuildObject("evlegs_vsr",param_1,&local_ac);
    }
    else {
      local_70 = (float *)BuildObject(pcVar13,param_1,&local_ac);
    }
    pfVar17 = local_70;
    iVar9 = (*(code *)local_64.up.x)(local_68 + 1,"vcamr_vsr",9);
    if (iVar9 == 0) {
      SetPerceivedTeam((int)pfVar17,0);
    }
    bVar6 = false;
    cVar7 = GetRaceOfTeam(param_1);
    pcVar13 = GetInitialPlayerPilotODF(this,cVar7,param_1,bVar6);
    (*local_78)(pfVar17,pcVar13);
    if (*(char *)((int)&this[1]._padding_ + 2) == '\0') {
      SetRandomHeadingAngle((int)pfVar17);
    }
    else {
      local_74 = local_74 - local_ac.z;
      local_80 = local_80 - local_ac.x;
      dVar19 = (double)(local_74 * local_74 + local_80 * local_80);
      __libm_sse2_sqrt_precise();
      local_64.right.y = 0.0;
      local_64.right.x = local_80 / (float)dVar19;
      local_64.right.z = local_74 / (float)dVar19;
      Build_Directinal_Matrix(&local_64,unaff_EDI,unaff_ESI);
      (*local_94)(pfVar17,&local_64.up.y);
      pfVar17 = local_70;
      VVar2.y = (float)uStack_1c;
      VVar2.x = (float)local_20;
      VVar2.z = fStack_18;
      SetVectorPosition((int)local_70,VVar2);
    }
  }
  else {
    pfVar17 = local_70;
  }
  if (local_7c == (float *)0x0) {
    MakeInert((int)pfVar17);
  }
  return (int)pfVar17;
}


// ---------------------------------------------------------------------
// Strategy02::Init  @ 4fc43b41  lines 1634-1999


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall Strategy02::Init(Strategy02 *this)

{
  int *piVar1;
  code *pcVar2;
  bool bVar3;
  char *pcVar4;
  int iVar5;
  float fVar6;
  float fVar7;
  int iVar8;
  float (*pafVar9) [5];
  int iVar10;
  char *unaff_ESI;
  int iVar11;
  float *pfVar12;
  code *pcVar13;
  int *unaff_EDI;
  float10 fVar14;
  float (*local_528) [5];
  undefined4 local_524;
  char *local_520;
  int local_51c;
  undefined8 local_518;
  int local_510;
  bool local_509;
  float (*local_508) [5];
  int local_504 [15];
  char local_4c8 [1024];
  char local_c8 [128];
  char local_48 [64];
  undefined4 local_8;
  
  local_8 = __security_cookie ^ (uint)(local_48 + 0x44);
  local_518 = (double)CONCAT44(this,(undefined4)local_518);
  pcVar4 = GetVarItemStr("network.session.svar6");
  if ((pcVar4 != (char *)0x0) && (*pcVar4 != '\0')) {
    StartingVehicleManager::Init();
  }
  memset(local_4c8,0,0x400);
  local_51c = 0;
  local_509 = false;
  pcVar4 = GetVarItemStr("network.session.svar0");
  strcpy_s(local_c8,0x80,pcVar4);
  pcVar4 = strrchr(local_c8,0x2e);
  if (pcVar4 != (char *)0x0) {
    *pcVar4 = '\0';
    pcVar4 = local_c8;
    strcat_s(pcVar4,0x80,".trn");
    OpenODF2(pcVar4);
    GetODFBool(local_c8,"DLL","RespawnAtLowAltitude",(bool *)((int)&this[1]._padding_ + 2),false);
    GetODFFloat(local_c8,"DLL","FriendlySpawnpointMaxAllyRange",(float *)&this[1]._padding_,100.0);
    GetODFFloat(local_c8,"DLL","FriendlySpawnpointMinEnemyRange",(float *)&this[1]._padding_,400.0);
    GetODFFloat(local_c8,"DLL","RandomSpawnpointMinEnemyRange",(float *)&this[1]._padding_,450.0);
    pcVar4 = local_4c8;
    iVar11 = 0;
    iVar10 = local_51c;
    do {
      iVar11 = iVar11 + 1;
      sprintf_s<64>(&local_48,"CaptureTarget%d");
      iVar5 = GetODFString(local_c8,"DLL",local_48,0x40,pcVar4,(char *)0x0);
      if (iVar5 == 0) break;
      iVar10 = iVar10 + 1;
      pcVar4 = pcVar4 + 0x40;
    } while (iVar11 < 0x10);
    local_51c = iVar10;
    GetODFBool(local_c8,"DLL","CaptureIsRandom",&local_509,false);
    this = local_518._4_4_;
    piVar1 = (local_518._4_4_)->m_GoalBeingCaptured + 10;
    GetODFString(local_c8,"VSR","MapAmbientSound",0x40,(char *)piVar1,(char *)0x0);
    bVar3 = DoesFileExist((char *)piVar1);
    if (bVar3) {
      EasterEggSound = StartAudio2D((char *)piVar1,-1.0,0.0,44100.0,true,false);
    }
  }
  pcVar13 = GetVarItemInt_exref;
  *(undefined1 *)((int)&this[1]._padding_ + 1) = 1;
  fVar6 = (float)GetVarItemInt("network.session.ivar0");
  this->m_TeamPos[0x29] = fVar6;
  fVar6 = (float)GetVarItemInt("network.session.ivar1");
  this->m_TeamPos[0x26] = fVar6;
  fVar6 = (float)GetVarItemInt("network.session.ivar7");
  this->m_TeamPos[0x2f] = fVar6;
  iVar10 = GetVarItemInt("network.session.ivar12");
  *(bool *)((int)&this[1]._padding_ + 2) = iVar10 != 0;
  fVar6 = 4.2039e-45;
  if (iVar10 != 0) {
    fVar7 = (float)GetVarItemInt("network.session.ivar13");
    this->m_SavedPlayerLocalAmmo[0xc][2] = fVar7;
    fVar7 = (float)GetVarItemInt("network.session.ivar96");
    this->m_SavedPlayerLocalAmmo[0xc][3] = fVar7;
    fVar7 = (float)GetVarItemInt("network.session.ivar97");
    this->m_SavedPlayerLocalAmmo[0xc][4] = fVar7;
    fVar7 = (float)GetVarItemInt("network.session.ivar98");
    this->m_SavedPlayerLocalAmmo[0xd][0] = fVar7;
    fVar7 = (float)GetVarItemInt("network.session.ivar99");
    this->m_SavedPlayerLocalAmmo[0xd][1] = fVar7;
    fVar7 = (float)GetVarItemInt("network.session.ivar21");
    if ((int)fVar7 < 0) {
      fVar7 = 0.0;
    }
    else if (3 < (int)fVar7) {
      fVar7 = fVar6;
    }
    this->m_SavedPlayerLocalAmmo[0xd][4] = fVar7;
    fVar7 = (float)GetVarItemInt("network.session.ivar22");
    if ((int)fVar7 < 0) {
      fVar7 = 0.0;
    }
    else if (3 < (int)fVar7) {
      fVar7 = fVar6;
    }
    this->m_SavedPlayerLocalAmmo[0xe][0] = fVar7;
    fVar7 = (float)GetVarItemInt("network.session.ivar23");
    if ((int)fVar7 < 0) {
      fVar7 = 0.0;
    }
    else if (3 < (int)fVar7) {
      fVar7 = fVar6;
    }
    this->m_SavedPlayerLocalAmmo[0xd][2] = fVar7;
    fVar7 = (float)GetVarItemInt("network.session.ivar24");
    if ((int)fVar7 < 0) {
      fVar7 = 0.0;
    }
    else if (3 < (int)fVar7) {
      fVar7 = fVar6;
    }
    this->m_SavedPlayerLocalAmmo[0xd][3] = fVar7;
  }
  iVar10 = GetVarItemInt("network.session.ivar53");
  this->UserTarget[9] = iVar10;
  iVar11 = GetVarItemInt("network.session.ivar54");
  iVar10 = 0x1e;
  if ((0x1d < iVar11) && (iVar10 = iVar11, 0x78 < iVar11)) {
    iVar10 = 0x78;
  }
  pfVar12 = this->m_TeamPos + 0x24;
  this->UserTarget[8] = (int)*pfVar12 * iVar10;
  iVar10 = GetVarItemInt("network.session.ivar14");
  this->m_TeamPos[0x2a] = (float)(uint)(iVar10 != 0);
  iVar10 = GetVarItemInt("network.session.ivar15");
  this->m_TeamPos[0x2b] = (float)(uint)(iVar10 != 0);
  fVar6 = (float)GetVarItemInt("network.session.ivar16");
  this->m_TeamPos[0x2c] = fVar6;
  iVar10 = GetVarItemInt("network.session.ivar32");
  *(bool *)((int)&this[1]._padding_ + 3) = iVar10 != 0;
  iVar10 = GetVarItemInt("network.session.ivar55");
  *(bool *)&this[1]._padding_ = iVar10 != 0;
  iVar10 = GetVarItemInt("network.session.ivar118");
  *(bool *)((int)&this[1]._padding_ + 2) = iVar10 != 0;
  iVar10 = GetVarItemInt("network.session.ivar119");
  if (iVar10 < 0) {
    iVar10 = 0;
  }
  else if (2 < iVar10) {
    iVar10 = 2;
  }
  this[1]._padding_ = iVar10;
  iVar10 = GetVarItemInt("network.session.ivar120");
  if (iVar10 < 0) {
    iVar10 = 0;
  }
  else if (0x78 < iVar10) {
    iVar10 = 0x78;
  }
  this->UserTarget[10] = (int)*pfVar12 * iVar10;
  iVar10 = GetVarItemInt("network.session.ivar121");
  if (iVar10 < 0) {
    iVar10 = 0;
  }
  else if (3 < iVar10) {
    iVar10 = 3;
  }
  this[1]._padding_ = iVar10;
  fVar6 = (float)GetVarItemInt("network.session.ivar17");
  if ((int)fVar6 < 0) {
    fVar6 = 0.0;
  }
  else if (3 < (int)fVar6) {
    fVar6 = 4.2039e-45;
  }
  this->m_TeamPos[0x2d] = fVar6;
  fVar6 = (float)GetVarItemInt("network.session.ivar18");
  if ((int)fVar6 < 0) {
    fVar6 = 0.0;
  }
  else if (3 < (int)fVar6) {
    fVar6 = 4.2039e-45;
  }
  this->m_TeamPos[0x2e] = fVar6;
  local_528 = this->m_SavedPlayerLocalAmmo + 2;
  memset(local_528,0,0x40);
  bVar3 = IsTeamplayOn();
  if ((!bVar3) || (*(char *)((int)&this[1]._padding_ + 2) != '\0')) {
    memset(local_48,0,0x40);
    local_508 = (float (*) [5])(this->m_SavedPlayerLocalAmmo[2] + 1);
    iVar10 = 0x51;
    do {
      sprintf_s<64>(&local_48,"network.session.ivar%d");
      fVar6 = (float)GetVarItemInt(local_48);
      (*local_508)[0] = fVar6;
      if ((int)fVar6 < 1) {
        *(int *)local_508 = iVar10 + -0x50;
      }
      sprintf_s<64>(&local_48,"network.session.ivar%d");
      iVar11 = GetVarItemInt(local_48);
      if (iVar11 < 0) {
        iVar11 = 0;
      }
      else if (1 < iVar11) {
        iVar11 = 1;
      }
      local_508 = (float (*) [5])((int)local_508 + 4);
      *(bool *)((int)(this[1].PlayerShipODF + -0x274) + iVar10) = iVar11 != 0;
      iVar11 = iVar10 + -0x4f;
      iVar10 = iVar10 + 1;
    } while (iVar11 < 0x10);
    bVar3 = IsTeamplayOn();
    if (bVar3) {
      local_504[0] = 0;
      local_504[1] = 0;
      local_504[2] = 0;
      local_504[3] = 0;
      local_504[4] = 0;
      local_504[5] = 0;
      local_504[6] = 0;
      local_504[7] = 0;
      local_504[8] = 0;
      local_504[9] = 0;
      local_504[10] = 0;
      local_504[0xb] = 0;
      local_504[0xc] = 0;
      local_504[0xd] = 0;
      local_504[0xe] = 0;
      iVar10 = 1;
      do {
        GetTeamStratIndividualColor
                  (TEAMCOLOR_TYPE_GAMEPREFS,iVar10,local_504 + iVar10,local_504 + iVar10 + 5,
                   local_504 + iVar10 + 10);
        iVar10 = iVar10 + 1;
      } while (iVar10 < 6);
      DefaultAllies();
      SetFFATeamColors(TEAMCOLOR_TYPE_GAMEPREFS);
      iVar10 = 1;
      pfVar12 = (float *)((int)local_518._4_4_ + 0xe408);
      do {
        SetTeamColor(iVar10,local_504[iVar10],local_504[iVar10 + 5],local_504[iVar10 + 10]);
        iVar11 = 1;
        local_508 = (float (*) [5])pfVar12;
        do {
          if ((iVar10 != iVar11) && (Ally(iVar10,iVar11), iVar10 == 1)) {
            (*local_508)[0] = *pfVar12;
          }
          iVar11 = iVar11 + 1;
          local_508 = (float (*) [5])((int)local_508 + 4);
        } while (iVar11 < 6);
        iVar10 = iVar10 + 1;
        this = local_518._4_4_;
      } while (iVar10 < 6);
    }
    iVar10 = 1;
    do {
      local_508 = (float (*) [5])(this->m_SavedPlayerLocalAmmo[2] + 1);
      iVar11 = 1;
      local_510 = 1;
      do {
        if (((0 < this->m_RecyclerHandles[iVar10 + -0x48]) && (iVar10 != iVar11)) &&
           ((float)this->m_RecyclerHandles[iVar10 + -0x48] == (*local_508)[0])) {
          Ally(iVar10,iVar11);
          *(undefined1 *)((int)(this[1].PlayerShipODF + -0x274) + iVar10 + 0x3c) = 1;
          bVar3 = IsTeamplayOn();
          if ((bVar3) && (iVar10 == 1)) {
            local_510 = GetFirstAlliedTeam(1);
            iVar5 = GetLastAlliedTeam(1);
            if (local_510 < iVar5 + 1) {
              iVar5 = local_510;
              do {
                Ally(iVar5,iVar11);
                iVar5 = iVar5 + 1;
                iVar8 = GetLastAlliedTeam(1);
              } while (iVar5 < iVar8 + 1);
              this = local_518._4_4_;
            }
          }
        }
        iVar11 = iVar11 + 1;
        local_508 = (float (*) [5])(*local_508 + 1);
      } while (iVar11 < 0x10);
      iVar10 = iVar10 + 1;
    } while (iVar10 < 0x10);
    iVar10 = -(int)this;
    local_510 = iVar10 + -0xe404;
    iVar11 = 1;
    pfVar12 = this->m_SavedPlayerLocalAmmo[2];
    pcVar13 = GetVarItemInt_exref;
    do {
      pcVar2 = GetVarItemInt_exref;
      pfVar12 = pfVar12 + 1;
      if (*(char *)((int)(this[1].PlayerShipODF + -0x273) + (int)*pfVar12 + 0x20) == '\0') {
        iVar5 = 0;
        local_520 = (char *)(iVar10 + (int)this);
        local_508 = this->m_SavedPlayerLocalAmmo + 2;
        do {
          if ((*(char *)((int)(this[1].PlayerShipODF + -0x273) + iVar5 + 0x10) == '\0') &&
             (pcVar13 = GetVarItemInt_exref,
             *(float *)((int)local_520 + (int)pfVar12) == (*local_508)[0])) {
            *(undefined1 *)((int)(this[1].PlayerShipODF + -0x273) + (int)*pfVar12 + 0x20) = 1;
            pcVar13 = pcVar2;
            break;
          }
          iVar5 = iVar5 + 1;
          local_508 = (float (*) [5])(*local_508 + 1);
        } while (iVar5 < 0x10);
        if (*(char *)((int)(this[1].PlayerShipODF + -0x273) + (int)*pfVar12 + 0x20) == '\0') {
          iVar5 = 0;
          pafVar9 = this->m_SavedPlayerLocalAmmo + 2;
          do {
            pcVar13 = GetVarItemInt_exref;
            this = local_518._4_4_;
            if ((*pafVar9)[0] == (*local_528)[iVar11]) {
              *(undefined1 *)((int)(local_518._4_4_[1].PlayerShipODF + -0x273) + iVar5 + 0x10) = 0;
              *(undefined1 *)
               ((int)(local_518._4_4_[1].PlayerShipODF + -0x273) + (int)*pfVar12 + 0x20) = 1;
              break;
            }
            iVar5 = iVar5 + 1;
            pafVar9 = (float (*) [5])(*pafVar9 + 1);
          } while (iVar5 < 0x10);
        }
      }
      iVar11 = iVar11 + 1;
    } while (iVar11 < 0x10);
    pfVar12 = this->m_TeamPos + 0x24;
  }
  iVar10 = (*pcVar13)();
  this->m_SavedPlayerLocalAmmo[5][1] = (float)((int)*pfVar12 * iVar10 * 0x3c);
  iVar10 = GetPlayerHandle();
  if (iVar10 != 0) {
    RemoveObject(iVar10);
  }
  bVar3 = ImServer();
  if ((bVar3) || (bVar3 = IsNetworkOn(), !bVar3)) {
    this->m_TeamPos[0x28] = 0.0;
    if (this->m_TeamPos[0x27] == 0.0) {
      this->m_TeamPos[0x27] = (float)((int)this->m_TeamPos[0x26] * (int)*pfVar12 * 0x3c);
    }
    if (*(char *)((int)&this[1]._padding_ + 2) != '\0') {
      this->m_SavedPlayerLocalAmmo[0xe][1] = -NAN;
      InitTaunts((int *)pfVar12,(int *)(this->m_TeamPos + 0x28),unaff_EDI,unaff_ESI);
    }
  }
  iVar10 = GetLocalPlayerTeamNumber();
  iVar11 = SetupPlayer(this,iVar10);
  SetAsUser(iVar11,iVar10);
  AddPilotByHandle(iVar11);
  if (this->UserTarget[9] == 4) {
    local_518 = (double)((ulonglong)local_518 & 0xffffffff);
    GetAiPaths(&local_510,(char ***)&local_528);
    iVar10 = 0;
    if (0 < local_510) {
      iVar11 = local_51c;
      do {
        local_520 = (char *)(*local_528)[iVar10];
        if (iVar11 < 1) {
          PrintConsoleMessage("Error: Map has no Capture ODF\'s set!");
        }
        else {
          local_524 = 0xffffffff;
          iVar5 = sscanf_s(local_520,"capturegoal%d");
          if ((0 < iVar5) && ((int)this->m_SavedPlayerLocalAmmo[0xe][3] < 0x10)) {
            if (local_509 == false) {
              fVar6 = (float)local_518._4_4_;
              if ((float)iVar11 < (float)local_518._4_4_) {
                fVar6 = 0.0;
                goto LAB_4fc444ab;
              }
            }
            else {
              fVar6 = GetRandomFloat((float)iVar11);
              fVar14 = floor((double)fVar6);
              local_518 = (double)fVar14;
              fVar6 = (float)iVar11;
              if ((float)fVar14 <= (float)iVar11) {
                fVar6 = (float)fVar14;
              }
LAB_4fc444ab:
              local_518 = (double)CONCAT44(fVar6,(undefined4)local_518);
            }
            bVar3 = DoesODFExist(local_4c8 + (int)fVar6 * 0x40);
            if (bVar3) {
              iVar11 = BuildObject(local_4c8 + (int)fVar6 * 0x40,0,local_520);
              *(int *)((int)(this[1].PlayerShipODF + -0x264) +
                      ((int)this->m_SavedPlayerLocalAmmo[0xe][3] + 0xf) * 4) = iVar11;
              bVar3 = IsAround(*(int *)((int)(this[1].PlayerShipODF + -0x264) +
                                       ((int)this->m_SavedPlayerLocalAmmo[0xe][3] + 0xf) * 4));
              if (bVar3) {
                SetObjectiveOn(*(int *)((int)(this[1].PlayerShipODF + -0x264) +
                                       ((int)this->m_SavedPlayerLocalAmmo[0xe][3] + 0xf) * 4));
                pfVar12 = this->m_SavedPlayerLocalAmmo[0xe] + 3;
                *pfVar12 = (float)((int)*pfVar12 + 1);
              }
              local_518 = (double)CONCAT44((float)local_518._4_4_ + __real_3f800000,
                                           (undefined4)local_518);
            }
            else {
              sprintf_s<1024>(&TempMsgString,"Error: ODF \'%s\' doesn\'t exist!");
              PrintConsoleMessage(TempMsgString);
            }
            iVar11 = local_51c;
          }
        }
        iVar10 = iVar10 + 1;
      } while (iVar10 < local_510);
    }
  }
  return;
}


// ---------------------------------------------------------------------
// Strategy02::UpdateGameTime  @ 4fc439c6  lines 2003-2074


void __thiscall Strategy02::UpdateGameTime(Strategy02 *this)

{
  float fVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  float fVar6;
  
  fVar6 = (float)((int)this->m_TeamPos[0x28] + 1);
  fVar1 = this->m_TeamPos[0x24];
  this->m_TeamPos[0x28] = fVar6;
  if ((int)this->m_TeamPos[0x27] < 1) {
    if ((int)fVar6 % (int)fVar1 == 0) {
      if (((int)fVar6 / (int)fVar1) / 0xe10 == 0) {
        pcVar4 = GetBZCCLocalizedString("mission","Mission Time %d:%02d");
        sprintf_s<1024>(&TempMsgString,pcVar4);
      }
      else {
        pcVar4 = GetBZCCLocalizedString("mission","Mission Time %d:%02d:%02d");
        sprintf_s<1024>(&TempMsgString,pcVar4);
      }
      SetTimerBox(TempMsgString);
    }
  }
  else {
    fVar6 = (float)((int)this->m_TeamPos[0x27] + -1);
    this->m_TeamPos[0x27] = fVar6;
    if ((int)fVar6 % (int)fVar1 == 0) {
      iVar2 = ((int)fVar6 / (int)fVar1) / 0x3c;
      iVar5 = ((int)fVar6 / (int)fVar1) % 0x3c;
      iVar3 = iVar2 / 0x3c;
      iVar2 = iVar2 % 0x3c;
      if (iVar3 == 0) {
        pcVar4 = GetBZCCLocalizedString("mission","Time Left %d:%02d\n");
        sprintf_s<1024>(&TempMsgString,pcVar4);
      }
      else {
        pcVar4 = GetBZCCLocalizedString("mission","Time Left %d:%02d:%02d\n");
        sprintf_s<1024>(&TempMsgString,pcVar4);
      }
      SetTimerBox(TempMsgString);
      if ((iVar3 == 0) &&
         (((iVar5 == 0 && ((iVar2 < 0xb || (iVar2 % 5 == 0)))) || ((iVar2 == 0 && (iVar5 % 5 == 0)))
          ))) {
        AddToMessagesBox(TempMsgString);
      }
    }
    if (this->m_TeamPos[0x27] == 0.0) {
      NoteGameoverByTimelimit();
      DoGameover(10.0);
    }
  }
  return;
}


// ---------------------------------------------------------------------
// Strategy02::ExecuteRecyInvulnerability  @ 4fc43854  lines 2078-2136


void __thiscall Strategy02::ExecuteRecyInvulnerability(Strategy02 *this)

{
  int *piVar1;
  bool bVar2;
  int iVar3;
  long lVar4;
  char *pcVar5;
  int unaff_EBX;
  float fVar6;
  int iVar7;
  Strategy02 *local_c;
  int *local_8;
  
  if ((char)this[1]._padding_ != '\0') {
    return;
  }
  iVar7 = 0;
  if (this->m_SavedPlayerLocalAmmo[5][1] == 0.0) {
    return;
  }
  local_8 = &this[1]._padding_;
  local_c = this;
  do {
    piVar1 = local_8;
    if (*(char *)((int)(this[1].PlayerShipODF + -0x274) + iVar7 + 0x1c) != '\0') {
      local_c = (Strategy02 *)*local_8;
      bVar2 = IsAlive((int *)&local_c);
      if ((!bVar2) || (local_c == (Strategy02 *)0x0)) {
        iVar3 = GetObjectByTeamSlot(iVar7,1);
      }
      else {
        iVar3 = *piVar1;
      }
      if ((iVar3 != 0) && (bVar2 = DLLUtils::IsRecycler(unaff_EBX), bVar2)) {
        lVar4 = GetMaxHealth(iVar3);
        SetCurHealth(iVar3,lVar4);
      }
    }
    iVar7 = iVar7 + 1;
    local_8 = local_8 + 1;
  } while (iVar7 < 0x10);
  fVar6 = this->m_SavedPlayerLocalAmmo[5][1];
  if (fVar6 == 1.4013e-45) {
    pcVar5 = GetBZCCLocalizedString("strat","recyclersVulnerable");
    sprintf_s<1024>(&TempMsgString,pcVar5);
  }
  else {
    local_c = (Strategy02 *)((int)this->m_TeamPos[0x24] * 0x3c);
    if (((int)fVar6 % (int)local_c != 0) &&
       (((int)local_c <= (int)fVar6 || ((int)fVar6 % ((int)this->m_TeamPos[0x24] * 0xf) != 0))))
    goto LAB_4fc439b8;
    if ((int)local_c < (int)fVar6) {
      pcVar5 = GetBZCCLocalizedString("strat","invulnerableExpiresMin");
    }
    else {
      pcVar5 = GetBZCCLocalizedString("strat","invulnerableExpiresSec");
    }
    sprintf_s<1024>(&TempMsgString,pcVar5);
  }
  AddToMessagesBox2(TempMsgString,0xffff00ff);
  fVar6 = this->m_SavedPlayerLocalAmmo[5][1];
LAB_4fc439b8:
  this->m_SavedPlayerLocalAmmo[5][1] = (float)((int)fVar6 + -1);
  return;
}


// ---------------------------------------------------------------------
// Strategy02::ExecuteCheckIfGameOver  @ 4fc43263  lines 2139-2426


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall Strategy02::ExecuteCheckIfGameOver(Strategy02 *this)

{
  char cVar1;
  float fVar2;
  uint uVar3;
  bool bVar4;
  char cVar5;
  int iVar6;
  int iVar7;
  float (*pafVar8) [5];
  uint uVar9;
  char *pcVar10;
  char cVar11;
  int iVar12;
  Strategy02 *pSVar13;
  int unaff_EDI;
  int *piVar14;
  int iVar15;
  Vector local_98;
  Strategy02 *local_8c;
  int local_88;
  int local_84;
  uint local_80;
  int local_7c;
  int *local_78;
  float (*local_74) [5];
  float (*local_70) [5];
  char local_6a;
  char local_69;
  char local_68 [64];
  char local_28 [32];
  undefined4 local_8;
  
  local_8 = __security_cookie ^ (uint)(local_28 + 0x24);
  if (((char)this[1]._padding_ == '\0') &&
     ((int)this->m_TeamPos[0x24] <= (int)this->m_TeamPos[0x28])) {
    iVar12 = 0;
    local_80 = (uint)this->m_TeamPos[0x28] & 0xffffff00;
    local_8c = this;
    local_69 = IsTeamplayOn();
    local_28[0] = '\0';
    local_28[1] = '\0';
    local_28[2] = '\0';
    local_28[3] = '\0';
    local_28[4] = '\0';
    local_28[5] = '\0';
    local_28[6] = '\0';
    local_28[7] = '\0';
    local_28[8] = '\0';
    local_28[9] = '\0';
    local_28[10] = '\0';
    local_28[0xb] = '\0';
    local_28[0xc] = '\0';
    local_28[0xd] = '\0';
    local_28[0xe] = '\0';
    local_28[0xf] = '\0';
    local_28[0x10] = '\0';
    local_28[0x11] = '\0';
    local_28[0x12] = '\0';
    local_28[0x13] = '\0';
    local_28[0x14] = '\0';
    local_28[0x15] = '\0';
    local_28[0x16] = '\0';
    local_28[0x17] = '\0';
    local_28[0x18] = '\0';
    local_28[0x19] = '\0';
    local_28[0x1a] = '\0';
    local_28[0x1b] = '\0';
    local_28[0x1c] = '\0';
    local_28[0x1d] = '\0';
    local_28[0x1e] = '\0';
    local_28[0x1f] = '\0';
    local_74 = this->m_SavedPlayerLocalAmmo + 2;
    local_78 = &this[1]._padding_;
    local_70 = local_74;
    do {
      pafVar8 = local_74;
      if (*(char *)((int)(this[1].PlayerShipODF + -0x274) + iVar12 + 0x1c) != '\0') {
        local_6a = '\0';
        local_84 = *(int *)((int)(local_74 + 0x5f) + 0x10);
        bVar4 = IsAround(local_84);
        if (!bVar4) {
          local_84 = GetObjectByTeamSlot(iVar12,1);
        }
        if ((local_84 == 0) || (bVar4 = IsAlive(&local_84), !bVar4)) {
          *(undefined4 *)((int)(pafVar8 + 0x5f) + 0x10) = 0;
        }
        else {
          local_6a = '\x01';
        }
        bVar4 = IsAlive(&local_84);
        iVar6 = local_84;
        if (bVar4) {
LAB_4fc43365:
          if ((iVar6 != 0) || (iVar6 = GetObjectByTeamSlot(iVar12,2), iVar6 != 0))
          goto LAB_4fc4337a;
          cVar11 = local_6a;
        }
        else {
          if (local_84 == 0) {
            iVar6 = GetObjectByTeamSlot(iVar12,1);
            goto LAB_4fc43365;
          }
LAB_4fc4337a:
          if (*(char *)((int)&this[1]._padding_ + 2) != '\0') {
            local_80 = local_80 & 0xff;
            if (iVar12 < 0xb) {
              local_80 = 1;
            }
          }
          cVar11 = '\x01';
        }
        fVar2 = (*local_74)[0];
        if ((local_28[(int)fVar2 + 0x10] == '\0') && (cVar11 == '\0')) {
          cVar5 = '\0';
        }
        else {
          cVar5 = '\x01';
        }
        cVar1 = *(char *)((int)(this[1].PlayerShipODF + -0x274) + iVar12 + 0x2c);
        local_28[(int)fVar2 + 0x10] = cVar5;
        local_28[iVar12] = cVar11;
        if ((cVar1 == '\0') || (*(char *)(this->m_TeamPos + 0x28) == '\0')) {
          if (local_69 == '\0') {
            if ((iVar6 == 0) &&
               (iVar6 = GetObjectByTeamSlot(this->m_RecyclerHandles[(int)fVar2 + -0x34],1),
               iVar6 == 0)) {
              iVar6 = GetObjectByTeamSlot(this->m_RecyclerHandles[(int)(*local_74)[0] + -0x34],2);
              goto LAB_4fc43414;
            }
          }
          else {
LAB_4fc43414:
            if (iVar6 == 0) {
              local_7c = 1;
              do {
                if (((iVar12 != local_7c) && (bVar4 = IsTeamAllied(iVar12,local_7c), bVar4)) &&
                   ((iVar6 = GetObjectByTeamSlot(local_7c,1), iVar6 != 0 ||
                    (iVar6 = GetObjectByTeamSlot(local_7c,2), iVar6 != 0)))) goto LAB_4fc4346c;
                local_7c = local_7c + 1;
              } while (local_7c < 0x10);
              if (iVar6 == 0) goto LAB_4fc43526;
            }
          }
LAB_4fc4346c:
          *(undefined1 *)((int)(this[1].PlayerShipODF + -0x274) + iVar12 + 0x2c) = 1;
          GetPosition(iVar6,&local_98);
          local_78[-1] = (int)local_98.x;
          *local_78 = (int)local_98.y;
          local_78[1] = (int)local_98.z;
          if (local_69 != '\0') {
            iVar6 = GetFirstAlliedTeam(iVar12);
            local_7c = iVar6;
            iVar7 = GetLastAlliedTeam(iVar12);
            if (iVar6 <= iVar7) {
              iVar7 = local_7c;
              piVar14 = (int *)((int)(this[1].PlayerShipODF + -0x26d) + (iVar6 * 3 + 8) * 4);
              do {
                iVar7 = iVar7 + 1;
                piVar14[-1] = (int)local_98.x;
                *piVar14 = (int)local_98.y;
                piVar14[1] = (int)local_98.z;
                iVar6 = GetLastAlliedTeam(iVar12);
                piVar14 = piVar14 + 3;
              } while (iVar7 <= iVar6);
              this = local_8c;
            }
          }
        }
      }
LAB_4fc43526:
      pSVar13 = local_8c;
      iVar12 = iVar12 + 1;
      local_74 = (float (*) [5])(*local_74 + 1);
      local_78 = local_78 + 3;
    } while (iVar12 < 0x10);
    cVar11 = *(char *)((int)&this[1]._padding_ + 2);
    iVar12 = 0;
    local_88 = 0;
    do {
      if ((cVar11 == '\0') && (local_69 != '\0')) {
        iVar6 = local_88 + 1;
        if (local_28[iVar12] == '\0') {
          iVar6 = local_88;
        }
        local_88 = iVar6;
      }
      else if (local_28[iVar12 + 0x10] != '\0') {
        local_88 = local_88 + 1;
      }
      iVar12 = iVar12 + 1;
    } while (iVar12 < 0x10);
    if ((cVar11 != '\0') && ((char)local_80 == '\0')) {
      NoteGameoverWithCustomMessage("All Human bases destroyed!");
      DoGameover(10.0);
      *(undefined1 *)&pSVar13[1]._padding_ = 1;
    }
    if (local_88 < 2) {
      if ((local_88 == 0) && ((int)pSVar13->m_TeamPos[0x24] * 5 < (int)pSVar13->m_TeamPos[0x28])) {
        NoteGameoverByNoBases();
        DoGameover(10.0);
      }
      else {
        if (*(char *)((int)&pSVar13[1]._padding_ + 3) == '\0') {
          return;
        }
        if (local_88 != 1) {
          return;
        }
        if (local_69 == '\0') {
          local_28[0] = '\0';
          local_28[1] = '\0';
          local_28[2] = '\0';
          local_28[3] = '\0';
          local_28[4] = '\0';
          local_28[5] = '\0';
          local_28[6] = '\0';
          local_28[7] = '\0';
          local_28[8] = '\0';
          local_28[9] = '\0';
          local_28[10] = '\0';
          local_28[0xb] = '\0';
          local_28[0xc] = '\0';
          local_28[0xd] = '\0';
          local_28[0xe] = '\0';
          local_28[0xf] = '\0';
          pafVar8 = pSVar13->m_SavedPlayerLocalAmmo + 2;
          iVar12 = 0;
          do {
            if (*(char *)((int)&pSVar13[1]._padding_ + 2) != '\0') {
              DoTaunt(unaff_EDI);
              pafVar8 = local_70;
            }
            fVar2 = (*pafVar8)[0];
            if (local_28[(int)fVar2 + 0x10] != '\0') {
              if ((*(char *)((int)&pSVar13[1]._padding_ + 2) == '\0') || (iVar12 < 0xb)) {
                if (*(char *)((int)(pSVar13[1].PlayerShipODF + -0x274) + iVar12 + 0x3c) == '\0') {
                  iVar6 = GetPlayerHandle(iVar12);
                  NoteGameoverByLastWithBase(iVar6);
                }
                else {
                  GetBZCCLocalizedString("cfg","Team");
                  sprintf_s<64>(&local_68,"%s %d");
                  pcVar10 = GetBZCCLocalizedString("Network","HitLastWithBaseStr");
                  sprintf_s<1024>(&TempMsgString,pcVar10);
                  iVar6 = 0;
                  do {
                    if ((iVar12 != iVar6) && (bVar4 = IsTeamAllied(iVar12,iVar6), bVar4)) {
                      iVar15 = 100;
                      iVar7 = GetPlayerHandle(iVar6);
                      AddScore(iVar7,iVar15);
                    }
                    iVar6 = iVar6 + 1;
                  } while (iVar6 < 0x10);
                  pSVar13 = local_8c;
                }
              }
              else {
                if (*(char *)((int)(pSVar13[1].PlayerShipODF + -0x274) + iVar12 + 0x3c) != '\0') {
                  if (local_28[(int)fVar2] != '\0') goto LAB_4fc43804;
                  local_28[(int)fVar2] = '\x01';
                }
                sprintf_s<1024>(&TempMsgString,
                                "Computer Team %d has won, destroyed all enemy bases.");
                NoteGameoverWithCustomMessage(TempMsgString);
              }
LAB_4fc43804:
              iVar7 = 100;
              iVar6 = GetPlayerHandle(iVar12);
              AddScore(iVar6,iVar7);
            }
            iVar12 = iVar12 + 1;
            pafVar8 = (float (*) [5])(*local_70 + 1);
            local_70 = pafVar8;
          } while (iVar12 < 0x10);
        }
        else {
          local_80 = 0xffffffff;
          local_28[0x10] = '\0';
          local_28[0x11] = '\0';
          local_28[0x12] = '\0';
          local_28[0x13] = '\0';
          local_28[0x14] = '\0';
          local_28[0x15] = '\0';
          local_28[0x16] = '\0';
          local_28[0x17] = '\0';
          local_28[0x18] = '\0';
          local_28[0x19] = '\0';
          local_28[0x1a] = '\0';
          local_28[0x1b] = '\0';
          local_28[0x1c] = '\0';
          local_28[0x1d] = '\0';
          local_28[0x1e] = '\0';
          local_28[0x1f] = '\0';
          pafVar8 = pSVar13->m_SavedPlayerLocalAmmo + 2;
          iVar12 = 0;
          do {
            if (local_28[iVar12] != '\0') {
              if (*(char *)((int)&pSVar13[1]._padding_ + 2) != '\0') {
                DoTaunt(unaff_EDI);
              }
              if (local_80 == 0xffffffff) {
                if ((*(char *)((int)&pSVar13[1]._padding_ + 2) == '\0') || (iVar12 < 0xb)) {
                  local_80 = WhichTeamGroup(iVar12);
                  NoteGameoverByLastTeamWithBase(local_80);
                }
                else {
                  if (*(char *)((int)(pSVar13[1].PlayerShipODF + -0x274) + iVar12 + 0x3c) != '\0') {
                    if (local_28[(int)(*local_70)[0] + 0x10] != '\0') goto LAB_4fc436a5;
                    local_28[(int)(*local_70)[0] + 0x10] = '\x01';
                  }
                  sprintf_s<1024>(&TempMsgString,
                                  "Computer Team %d has won, destroyed all enemy bases.");
                  NoteGameoverWithCustomMessage(TempMsgString);
                }
              }
LAB_4fc436a5:
              pafVar8 = local_70;
            }
            uVar3 = local_80;
            iVar12 = iVar12 + 1;
            pafVar8 = (float (*) [5])(*pafVar8 + 1);
            local_70 = pafVar8;
          } while (iVar12 < 0x10);
          iVar12 = 0;
          do {
            uVar9 = WhichTeamGroup(iVar12);
            if (uVar9 == uVar3) {
              iVar7 = 100;
              iVar6 = GetPlayerHandle(iVar12);
              AddScore(iVar6,iVar7);
            }
            iVar12 = iVar12 + 1;
          } while (iVar12 < 0x10);
        }
        DoGameover(10.0);
      }
      *(undefined1 *)&pSVar13[1]._padding_ = 1;
    }
    else {
      *(undefined1 *)((int)&pSVar13[1]._padding_ + 3) = 1;
    }
  }
  return;
}


// ---------------------------------------------------------------------
// Strategy02::Execute  @ 4fc41f90  lines 2429-3019

/* DECOMPILE FAILED: Exception while decompiling 4fc41f90: process: timeout
 */

// ---------------------------------------------------------------------
// Strategy02::AddPlayer  @ 4fc41f1e  lines 3022-3045


bool __thiscall Strategy02::AddPlayer(Strategy02 *this,ulong param_1,int param_2,bool param_3)

{
  int iVar1;
  int unaff_ESI;
  
  if (*(char *)((int)&this[1]._padding_ + 2) == '\0') {
    LuaMission::AddPlayer((LuaMission *)this,param_1,param_2,param_3);
  }
  if (*(char *)((int)&this[1]._padding_ + 1) == '\0') {
    Init(this);
  }
  else {
    if (!param_3) {
      return true;
    }
    if (*(char *)((int)&this[1]._padding_ + 2) != '\0') {
      DoTaunt(unaff_ESI);
    }
  }
  if (param_3) {
    iVar1 = SetupPlayer(this,param_2);
    SetAsUser(iVar1,param_2);
    AddPilotByHandle(iVar1);
  }
  return true;
}


// ---------------------------------------------------------------------
// Strategy02::DeletePlayer  @ 4fc41ef1  lines 3048-3054


void __thiscall Strategy02::DeletePlayer(Strategy02 *this,ulong param_1)

{
  int unaff_EBP;
  
  if (*(char *)((int)&this[1]._padding_ + 2) == '\0') {
    LuaMission::DeletePlayer((LuaMission *)this,param_1);
  }
  if (*(char *)((int)&this[1]._padding_ + 2) != '\0') {
    DoTaunt(unaff_EBP);
  }
  return;
}


// ---------------------------------------------------------------------
// Strategy02::RespawnPilot  @ 4fc41be7  lines 3058-3154


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

EjectKillRetCodes __thiscall Strategy02::RespawnPilot(Strategy02 *this,int param_1,int param_2)

{
  char cVar1;
  Vector *pVVar2;
  char *pcVar3;
  int iVar4;
  long lVar5;
  int unaff_EDI;
  double dVar6;
  float fVar7;
  uint uVar8;
  float fVar9;
  bool bVar10;
  int iVar11;
  float local_34;
  Vector local_2c;
  Vector local_20;
  Vector local_14;
  
  local_2c.y = 0.0;
  local_2c.z = 0.0;
  if (param_2 - 1U < 0xf) {
    local_2c.x = *(float *)((int)(this[1].PlayerShipODF + -0x26d) + (param_2 * 3 + 7) * 4);
    local_2c.y = *(float *)((int)(this[1].PlayerShipODF + -0x26d) + (param_2 * 3 + 8) * 4);
    local_2c.z = *(float *)((int)(this[1].PlayerShipODF + -0x26d) + (param_2 * 3 + 9) * 4);
    this->m_TeamPos[param_2 + 0x30] = this->m_TeamPos[0x28];
  }
  else {
    pVVar2 = GetSafestSpawnpoint(&local_14);
    local_2c.x = pVVar2->x;
    local_2c.y = pVVar2->y;
    local_2c.z = pVVar2->z;
  }
  GetPosition2(param_1,&local_20);
  local_34 = __real_43480000;
  uVar8 = (uint)((ulonglong)__xmm_7fffffffffffffff7fffffffffffffff >> 0x20);
  if ((__real_3c23d70a <
       (float)(double)CONCAT44((uint)((ulonglong)(double)local_20.x >> 0x20) & uVar8,
                               SUB84((double)local_20.x,0) &
                               (uint)__xmm_7fffffffffffffff7fffffffffffffff)) &&
     (__real_3c23d70a <
      (float)(double)CONCAT44((uint)((ulonglong)(double)local_20.z >> 0x20) & uVar8,
                              SUB84((double)local_20.z,0) &
                              (uint)__xmm_7fffffffffffffff7fffffffffffffff))) {
    dVar6 = (double)((local_20.z - local_2c.z) * (local_20.z - local_2c.z) +
                    (local_20.x - local_2c.x) * (local_20.x - local_2c.x));
    __libm_sse2_sqrt_precise();
    if (__real_42c80000 <= (float)dVar6) {
      dVar6 = (double)(float)dVar6;
      __libm_sse2_sqrt_precise();
      fVar9 = (float)dVar6 * ___real_3fa00000 + ___real_41f00000;
      iVar4 = DLLUtils::CountAlliedPlayers(unaff_EDI);
      local_34 = __real_42200000;
      fVar7 = (float)iVar4 * ___real_41700000 + ___real_428c0000;
      if ((__real_42200000 <= fVar9) && (local_34 = fVar7, fVar9 <= fVar7)) {
        local_34 = fVar9;
      }
    }
    else {
      local_34 = __real_420c0000;
    }
  }
  if (*(char *)((int)&this[1]._padding_ + 2) != '\0') {
    local_34 = __real_40000000;
  }
  fVar9 = GetRandomFloat(1.0);
  local_2c.x = (fVar9 - __real_3f000000) * ___real_42800000 + local_2c.x;
  fVar9 = GetRandomFloat(1.0);
  local_2c.z = (fVar9 - __real_3f000000) * ___real_42800000 + local_2c.z;
  fVar9 = TerrainFindFloor(local_2c.x,local_2c.z);
  if (local_2c.y < fVar9 + ___real_40200000) {
    local_2c.y = fVar9 + ___real_40200000;
  }
  local_2c.y = local_34 + local_2c.y;
  fVar9 = GetRandomFloat(1.0);
  pVVar2 = &local_2c;
  bVar10 = true;
  local_2c.y = fVar9 * ___real_41000000 + local_2c.y;
  iVar4 = param_2;
  iVar11 = param_2;
  cVar1 = GetRaceOfTeam(param_2);
  pcVar3 = GetInitialPlayerPilotODF(this,cVar1,iVar4,bVar10);
  iVar4 = BuildObject(pcVar3,iVar11,pVVar2);
  if (0 < this->UserTarget[10]) {
    this->UserTarget[param_2 + 0xb] = this->UserTarget[10];
    lVar5 = GetMaxHealth(iVar4);
    this->m_PilotInvUser[param_2 + 0xb] = lVar5;
    *(int *)((int)(this[1].PlayerShipODF + -0x262) + (param_2 + 0xf) * 4) = iVar4;
    SetMaxHealth(iVar4,0);
  }
  SetAsUser(iVar4,param_2);
  AddPilotByHandle(iVar4);
  SetRandomHeadingAngle(iVar4);
  if (param_2 == 0) {
    MakeInert(iVar4);
  }
  return DLLHandled;
}


// ---------------------------------------------------------------------
// Strategy02::DeadObject  @ 4fc417e7  lines 3158-3303


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

EjectKillRetCodes __thiscall
Strategy02::DeadObject(Strategy02 *this,int param_1,int param_2,bool param_3,bool param_4)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  TEAMRELATIONSHIP TVar5;
  EjectKillRetCodes EVar6;
  int unaff_EDI;
  float10 fVar7;
  char local_48 [64];
  undefined4 local_8;
  
  local_8 = __security_cookie ^ (uint)(local_48 + 0x44);
  iVar3 = GetTeamNum(param_1);
  GetObjInfo(param_1,Get_GOClass,local_48);
  iVar4 = _stricmp(local_48,"CLASS_TORPEDO");
  if (iVar3 == 0) {
    return DoEjectPilot;
  }
  bVar1 = IsPowerup(param_1);
  if (bVar1) {
    return DoEjectPilot;
  }
  if (iVar4 == 0) {
    return DoEjectPilot;
  }
  bVar1 = IsPlayer(param_1);
  bVar2 = IsPlayer(param_2);
  TVar5 = GetTeamRelationship(param_1,param_2);
  iVar4 = GetActualScrapCost(param_1);
  if (bVar1) {
    if (this->UserTarget[9] != 4) {
      fVar7 = floor((double)((float)iVar4 / __real_41a00000));
      AddScore(param_1,-(int)fVar7);
    }
    if (param_3) {
      AddDeaths(param_1,1);
    }
  }
  else {
    if (this->m_TeamPos[0x2b] != 0.0) {
      AddDeaths(param_1,1);
    }
    if ((this->m_TeamPos[0x2a] != 0.0) && (this->UserTarget[9] != 4)) {
      fVar7 = floor((double)((float)iVar4 / __real_41a00000));
      AddScore(param_1,-(int)fVar7);
    }
  }
  if (bVar2) {
    if ((TVar5 == TEAMRELATIONSHIP_SAMETEAM) || (TVar5 == TEAMRELATIONSHIP_ALLIEDTEAM)) {
      if (param_1 == param_2) goto LAB_4fc41b69;
      AddKills(param_2,-1);
      if (this->UserTarget[9] != 4) {
        fVar7 = floor((double)((float)iVar4 / __real_41200000));
        goto LAB_4fc41ade;
      }
    }
    else {
      AddKills(param_2,1);
      if (this->UserTarget[9] != 4) {
        fVar7 = floor((double)((float)iVar4 / __real_41200000));
LAB_4fc419c1:
        iVar4 = (int)fVar7;
LAB_4fc41ae8:
        AddScore(param_2,iVar4);
      }
    }
  }
  else if ((TVar5 == TEAMRELATIONSHIP_SAMETEAM) || (TVar5 == TEAMRELATIONSHIP_ALLIEDTEAM)) {
    if (this->m_TeamPos[0x2b] != 0.0) {
      AddKills(param_2,-1);
    }
    if ((this->m_TeamPos[0x2a] != 0.0) && (this->UserTarget[9] != 4)) {
      fVar7 = floor((double)((float)iVar4 / __real_41200000));
LAB_4fc41ade:
      iVar4 = -(int)fVar7;
      goto LAB_4fc41ae8;
    }
  }
  else {
    if (this->m_TeamPos[0x2b] != 0.0) {
      AddKills(param_2,1);
    }
    if ((this->m_TeamPos[0x2a] != 0.0) && (this->UserTarget[9] != 4)) {
      fVar7 = floor((double)((float)iVar4 / __real_41200000));
      goto LAB_4fc419c1;
    }
  }
  if ((((param_1 != param_2) && (!param_4)) && (iVar3 - 1U < 0xf)) &&
     ((0 < (int)this->m_TeamPos[iVar3 + 0x30] &&
      ((int)this->m_TeamPos[0x28] - (int)this->m_TeamPos[iVar3 + 0x30] <
       (int)this->m_TeamPos[0x24] * 0xf)))) {
    GetPlayerName(param_1);
    GetPlayerName(param_2);
    sprintf_s<1024>(&TempMsgString,"Spawn kill by %s on %s\n");
    AddToMessagesBox(TempMsgString);
    AddScore(param_2,-500);
  }
LAB_4fc41b69:
  if ((this->m_TeamPos[0x29] != 0.0) &&
     (iVar4 = GetKills(param_2), (int)this->m_TeamPos[0x29] <= iVar4)) {
    NoteGameoverByKillLimit(param_2);
    DoGameover(10.0);
  }
  if (param_4) {
    if (param_3) {
      return DLLHandled;
    }
  }
  else {
    if ((*(char *)((int)&this[1]._padding_ + 2) != '\0') && (iVar3 - 1U < 10)) {
      DoTaunt(unaff_EDI);
    }
    if (param_3) {
      EVar6 = RespawnPilot(this,param_1,iVar3);
      return EVar6;
    }
  }
  return DoEjectPilot;
}


// ---------------------------------------------------------------------
// Strategy02::PlayerEjected  @ 4fc41798  lines 3306-3323


EjectKillRetCodes __thiscall Strategy02::PlayerEjected(Strategy02 *this,int param_1)

{
  bool bVar1;
  int iVar2;
  EjectKillRetCodes EVar3;
  
  if (*(char *)((int)&this[1]._padding_ + 2) == '\0') {
    LuaMission::PlayerEjected((LuaMission *)this,param_1);
  }
  iVar2 = GetTeamNum(param_1);
  if (iVar2 == 0) {
    EVar3 = DLLHandled;
  }
  else {
    bVar1 = IsPlayer(param_1);
    EVar3 = DeadObject(this,param_1,param_1,false,(bool)('\x01' - bVar1));
  }
  return EVar3;
}


// ---------------------------------------------------------------------
// Strategy02::ObjectKilled  @ 4fc41736  lines 3326-3345


EjectKillRetCodes __thiscall Strategy02::ObjectKilled(Strategy02 *this,int param_1,int param_2)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  EjectKillRetCodes EVar4;
  
  if (*(char *)((int)&this[1]._padding_ + 2) == '\0') {
    LuaMission::ObjectKilled((LuaMission *)this,param_1,param_2);
  }
  bVar1 = IsPlayer(param_1);
  bVar2 = IsPerson(param_1);
  iVar3 = GetCurWorld();
  if (iVar3 == 0) {
    EVar4 = DeadObject(this,param_1,param_2,bVar2,(bool)('\x01' - bVar1));
  }
  else {
    EVar4 = DoEjectPilot;
  }
  return EVar4;
}


// ---------------------------------------------------------------------
// Strategy02::ObjectSniped  @ 4fc416e2  lines 3349-3368


EjectKillRetCodes __thiscall Strategy02::ObjectSniped(Strategy02 *this,int param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  EjectKillRetCodes EVar3;
  
  if (*(char *)((int)&this[1]._padding_ + 2) == '\0') {
    LuaMission::ObjectSniped((LuaMission *)this,param_1,param_2);
  }
  bVar1 = IsPlayer(param_1);
  iVar2 = GetCurWorld();
  if (iVar2 == 0) {
    EVar3 = DeadObject(this,param_1,param_2,true,(bool)('\x01' - bVar1));
  }
  else {
    EVar3 = DLLHandled;
  }
  return EVar3;
}


// ---------------------------------------------------------------------
// Strategy02::PreGetIn  @ 4fc41614  lines 3424-3455


PreGetInReturnCodes __thiscall
Strategy02::PreGetIn(Strategy02 *this,int param_1,int param_2,int param_3)

{
  bool bVar1;
  PreGetInReturnCodes PVar2;
  TEAMRELATIONSHIP TVar3;
  int iVar4;
  
  if (param_1 == 0) {
    PVar2 = LuaMission::PreGetIn((LuaMission *)this,0,param_2,param_3);
    TVar3 = GetTeamRelationship(param_2,param_3);
    if (((TVar3 == TEAMRELATIONSHIP_ALLIEDTEAM) && (bVar1 = IsPlayer(param_2), !bVar1)) &&
       ((char)this[1]._padding_ == '\0')) {
      iVar4 = GetTeamNum(param_3);
      SetTeamNum(param_2,iVar4);
    }
    iVar4 = GetTeamNum(param_2);
    if (*(int *)((int)(this[1].PlayerShipODF + -0x262) + (iVar4 + 0xf) * 4) == param_2) {
      iVar4 = GetTeamNum(param_2);
      SetMaxHealth(param_2,this->m_PilotInvUser[iVar4 + 0xb]);
      iVar4 = GetTeamNum(param_2);
      this->UserTarget[iVar4 + 0xb] = 0;
    }
    if (((PVar2 == PREGETIN_ALLOW) && (*(char *)((int)&this[1]._padding_ + 2) != '\0')) &&
       (iVar4 = GetTeamNum(param_3), 10 < iVar4)) {
      DispatchHelper::AddToDispatch
                ((DispatchHelper *)this->_padding_,param_3,15.0,false,0,false,false,false,false);
    }
  }
  else {
    PVar2 = PREGETIN_ALLOW;
  }
  return PVar2;
}


// ---------------------------------------------------------------------
// BuildMission  @ 4fc47036  lines 3459-3461


/* WARNING: Function: _EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: _EH_epilog3 replaced with injection: EH_epilog3 */

DLLBase * __cdecl BuildMission(void)

{
  Strategy02 *pSVar1;
  
  pSVar1 = operator_new(0xeca4);
  pSVar1 = Strategy02::Strategy02(pSVar1);
  return (DLLBase *)pSVar1;
}


// ---------------------------------------------------------------------
// Strategy02::ScavengerManagementCode  @ 4fc413ca  lines 3465-3604


void __thiscall Strategy02::ScavengerManagementCode(Strategy02 *this)

{
  ThugScavengerClass *pTVar1;
  ThugPilotClass *pTVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  ThugScavengerClass *pTVar9;
  ThugPilotClass *pTVar10;
  size_t sVar11;
  int *piVar12;
  ThugScavengerClass *pTVar13;
  ThugPilotClass *pTVar14;
  float *pfVar15;
  
  pTVar1 = *(ThugScavengerClass **)(this->SavedPilotODF[8] + 0x20);
  pTVar13 = *(ThugScavengerClass **)(this->SavedPilotODF[8] + 0x1c);
  while ((pTVar13 != pTVar1 && (bVar3 = ShouldRemoveThugScavengerObject(pTVar13), !bVar3))) {
    pTVar13 = pTVar13 + 1;
  }
  if (pTVar13 == pTVar1) {
LAB_4fc41452:
    piVar6 = *(int **)(this->SavedPilotODF[8] + 0x20);
  }
  else {
    pTVar9 = pTVar13 + 1;
    if (pTVar9 != pTVar1) {
      do {
        bVar3 = ShouldRemoveThugScavengerObject(pTVar9);
        if (!bVar3) {
          pTVar13->ThugScavengerObject = pTVar9->ThugScavengerObject;
          pTVar13->ScavengerTeam = pTVar9->ScavengerTeam;
          pTVar13 = pTVar13 + 1;
        }
        pTVar9 = pTVar9 + 1;
      } while (pTVar9 != pTVar1);
    }
    if (pTVar13 == pTVar1) goto LAB_4fc41452;
    sVar11 = *(int *)(this->SavedPilotODF[8] + 0x20) - (int)pTVar1;
    memmove(pTVar13,pTVar1,sVar11);
    piVar6 = (int *)(sVar11 + (int)pTVar13);
    *(int **)(this->SavedPilotODF[8] + 0x20) = piVar6;
  }
  piVar12 = *(int **)(this->SavedPilotODF[8] + 0x1c);
  if (piVar12 != piVar6) {
    do {
      iVar4 = GetTeamNum(*piVar12);
      if ((*(char *)((int)(this[1].PlayerShipODF + -0x273) + iVar4 + 0x10) == '\0') &&
         (piVar12[1] != iVar4)) {
        piVar12[1] = iVar4;
      }
      else {
        bVar3 = IsTeamplayOn();
        if (!bVar3) {
          iVar7 = GetScavengerCurScrap(*piVar12);
          if (0 < iVar7) {
            iVar8 = (*misnImport.GetScrap)(piVar12[1]);
            iVar5 = (*misnImport.GetMaxScrap)(piVar12[1]);
            if (iVar5 < iVar8 + iVar7) {
              (*misnImport.AddScrap)(piVar12[1],iVar5 - iVar8);
              iVar7 = iVar7 - (iVar5 - iVar8);
            }
            else {
              (*misnImport.AddScrap)(piVar12[1],iVar7);
              iVar7 = 0;
            }
            SetScavengerCurScrap(*piVar12,iVar7);
          }
          if ((iVar4 != piVar12[1]) && (bVar3 = IsDeployed(*piVar12), bVar3)) {
            SetTeamNum(*piVar12,piVar12[1]);
          }
        }
      }
      piVar12 = piVar12 + 2;
    } while (piVar12 != *(int **)(this->SavedPilotODF[8] + 0x20));
  }
  pTVar2 = *(ThugPilotClass **)(this->SavedPilotODF[8] + 0x2c);
  pTVar14 = *(ThugPilotClass **)(this->SavedPilotODF[8] + 0x28);
  while ((pTVar14 != pTVar2 && (bVar3 = ShouldRemoveThugPilotObject(pTVar14), !bVar3))) {
    pTVar14 = pTVar14 + 1;
  }
  if (pTVar14 != pTVar2) {
    pTVar10 = pTVar14 + 1;
    if (pTVar10 != pTVar2) {
      do {
        bVar3 = ShouldRemoveThugPilotObject(pTVar10);
        if (!bVar3) {
          pTVar14->ThugPilotObject = pTVar10->ThugPilotObject;
          pTVar14->SwitchTickTimer = pTVar10->SwitchTickTimer;
          pTVar14 = pTVar14 + 1;
        }
        pTVar10 = pTVar10 + 1;
      } while (pTVar10 != pTVar2);
    }
    if (pTVar14 != pTVar2) {
      sVar11 = *(int *)(this->SavedPilotODF[8] + 0x2c) - (int)pTVar2;
      memmove(pTVar14,pTVar2,sVar11);
      piVar6 = (int *)(sVar11 + (int)pTVar14);
      *(int **)(this->SavedPilotODF[8] + 0x2c) = piVar6;
      goto LAB_4fc415a0;
    }
  }
  piVar6 = *(int **)(this->SavedPilotODF[8] + 0x2c);
LAB_4fc415a0:
  piVar12 = *(int **)(this->SavedPilotODF[8] + 0x28);
  if (piVar12 != piVar6) {
    do {
      iVar4 = GetTeamNum(*piVar12);
      if ((*(char *)((int)(this[1].PlayerShipODF + -0x273) + iVar4 + 0x10) != '\0') &&
         (piVar12[1] < 1)) {
        pfVar15 = this->m_SavedPlayerLocalAmmo[2];
        iVar7 = 1;
        iVar8 = 1;
        do {
          pfVar15 = pfVar15 + 1;
          if (((float)this->m_RecyclerHandles[iVar4 + -0x48] == *pfVar15) &&
             (*(char *)((int)(this[1].PlayerShipODF + -0x273) + iVar8 + 0x10) == '\0')) {
            iVar7 = iVar8;
          }
          iVar8 = iVar8 + 1;
        } while (iVar8 < 0x10);
        if (iVar4 != iVar7) {
          SetTeamNum(*piVar12,iVar7);
        }
      }
      piVar12[1] = piVar12[1] + -1;
      piVar12 = piVar12 + 2;
    } while (piVar12 != *(int **)(this->SavedPilotODF[8] + 0x2c));
  }
  return;
}


// ---------------------------------------------------------------------
// Strategy02::ExecuteST_Capture  @ 4fc40af6  lines 3607-3859


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall Strategy02::ExecuteST_Capture(Strategy02 *this)

{
  int *piVar1;
  bool bVar2;
  int iVar3;
  undefined1 *puVar4;
  int iVar5;
  long extraout_EAX;
  long extraout_EAX_00;
  float fVar6;
  float fVar7;
  int *piVar8;
  undefined1 *puVar9;
  char *pcVar10;
  int iVar11;
  long lVar12;
  undefined1 auStack_8c [3];
  char local_89;
  int *local_88;
  float local_84;
  int *local_80;
  undefined1 *local_7c;
  int *local_78;
  int *local_74;
  double local_70;
  float *local_64;
  undefined1 *local_60;
  undefined1 *local_5c;
  int local_58;
  int local_54;
  char local_50 [68];
  uint local_c;
  
  local_c = __security_cookie ^ (uint)auStack_8c;
  local_89 = '\0';
  local_5c = (undefined1 *)0x1;
  do {
    puVar9 = local_5c;
    iVar3 = GetUserTarget((int)local_5c);
    *(int *)((int)(this[1].PlayerShipODF + -0x263) + (puVar9 + 0xf) * 4) = iVar3;
    if ((int)this->m_SavedPlayerLocalAmmo[0xe][3] < 1) {
      if ((char)this[1]._padding_ == '\0') {
        pcVar10 = "-- No Capture Goals! Game will be over very soon!";
LAB_4fc4138b:
        AddToMessagesBox2(pcVar10,0xffffff00);
        DoGameover(10.0);
        goto LAB_4fc4139f;
      }
    }
    else {
      local_74 = this->m_RecyclerHandles + 8;
      iVar3 = 0;
      local_60 = (undefined1 *)((int)&this[1]._padding_ + 2);
      local_78 = this->m_CaptureGoals + 8;
      local_88 = &this[1]._padding_;
      local_64 = this->m_SavedPlayerLocalAmmo[0xe] + 4;
      local_70 = (double)((ulonglong)local_70 & 0xffffffff00000000);
      do {
        GetObjInfo(*local_88,Get_ODF,local_50);
        bVar2 = IsAround(*local_88);
        if (bVar2) {
          SetObjectiveOn(*local_88);
        }
        else {
          fVar7 = this->m_SavedPlayerLocalAmmo[0xe][3];
          if (iVar3 < (int)fVar7 + -1) {
            local_7c = local_60;
            local_84 = (float)(-0xe7fa - (int)this);
            piVar8 = local_88;
            local_80 = (int *)((int)(this[1].PlayerShipODF + -0x272) +
                              iVar3 + (int)puVar9 * 0x10 + 6);
            do {
              puVar9 = local_7c + 1;
              *piVar8 = piVar8[1];
              piVar8[-0x1af] = piVar8[-0x1ae];
              piVar8[-0x19f] = piVar8[-0x19e];
              piVar8[-399] = piVar8[-0x18e];
              *local_7c = *puVar9;
              piVar1 = (int *)((int)local_80 + 1);
              *(undefined1 *)local_80 = *(undefined1 *)piVar1;
              local_7c[0x110] = local_7c[0x111];
              fVar7 = this->m_SavedPlayerLocalAmmo[0xe][3];
              piVar8 = piVar8 + 1;
              local_80 = piVar1;
              local_7c = puVar9;
            } while ((int)(puVar9 + (int)local_84) < (int)fVar7 + -1);
            puVar9 = local_5c;
            iVar3 = local_70._0_4_;
          }
          local_64 = local_64 + -1;
          iVar3 = iVar3 + -1;
          local_78 = local_78 + -1;
          local_74 = local_74 + -1;
          local_88 = local_88 + -1;
          local_60 = local_60 + -1;
          this->m_SavedPlayerLocalAmmo[0xe][3] = (float)((int)fVar7 + -1);
        }
        bVar2 = IsAround(*local_88);
        if (bVar2) {
          local_58 = GetPlayerHandle((int)puVar9);
          local_80 = &this[1]._padding_;
          local_7c = (undefined1 *)0x1;
          do {
            local_54 = GetPlayerHandle((int)local_7c);
            if ((((local_7c != puVar9) && (bVar2 = IsTeamAllied((int)puVar9,(int)local_7c), !bVar2))
                && (*(int *)((int)(this[1].PlayerShipODF + -0x263) + (puVar9 + 0xf) * 4) ==
                    *local_88)) &&
               (((*local_80 == *local_88 &&
                 (local_84 = (*misnImport.GetDistanceObject)(local_88,&local_58),
                 local_84 < __real_42c80000)) &&
                (local_84 = (*misnImport.GetDistanceObject)(local_88,&local_54),
                local_84 < __real_42c80000)))) {
              SetTeamNum(*local_88,*local_74);
              if (*(char *)((int)(this[1].PlayerShipODF + -0x26e) + iVar3 + 6) == '\0') {
                *(undefined1 *)((int)(this[1].PlayerShipODF + -0x26e) + iVar3 + 6) = 1;
              }
              goto LAB_4fc40d51;
            }
            local_80 = local_80 + 1;
            local_7c = local_7c + 1;
          } while ((int)local_7c < 0x10);
          *(undefined1 *)((int)(this[1].PlayerShipODF + -0x26e) + iVar3 + 6) = 0;
LAB_4fc40d51:
          if (((*(int *)((int)(this[1].PlayerShipODF + -0x263) + (puVar9 + 0xf) * 4) == *local_88)
              && ((undefined1 *)*local_74 != puVar9)) &&
             (((*local_74 == 0 || (bVar2 = IsTeamAllied(*local_74,(int)puVar9), !bVar2)) &&
              (((*local_78 == 0 || ((undefined1 *)*local_78 == puVar9)) &&
               (local_84 = (*misnImport.GetDistanceObject)(local_88,&local_58),
               local_84 < __real_42c80000)))))) {
            if (this->m_CaptureGoals[iVar3 + 8] == 0) {
              iVar5 = GetPlayerHandle((int)puVar9);
              GetPlayerName(iVar5);
              sprintf_s<1024>(&TempMsgString,"-- A Goal is being Captured by %s!");
              AddToMessagesBox2(TempMsgString,0xffffff00);
            }
            local_84 = (float)((int)(this->PlayerShipODF + -0x279) + 4 + (int)puVar9 * 0x10);
            *(undefined1 *)((int)local_84 + 0xe80a + iVar3) = 1;
            if (*(char *)((int)(this[1].PlayerShipODF + -0x26e) + iVar3 + 6) == '\0') {
              this->m_RecyclerHandles[iVar3 + -8] = this->m_RecyclerHandles[iVar3 + -8] + 1;
            }
            this->m_CaptureGoals[iVar3 + 8] = (int)puVar9;
            ((undefined1 *)((int)&this[1]._padding_ + 2))[(int)puVar9] = 1;
            local_80 = (int *)((this->UserTarget[8] - this->m_RecyclerHandles[iVar3 + -8]) /
                              (int)this->m_TeamPos[0x24]);
            puVar4 = (undefined1 *)GetLocalPlayerTeamNumber();
            if (puVar4 == puVar9) {
              local_70 = (double)((int)((int)local_80 + ((int)local_80 >> 0x1f & 3U)) >> 2);
              floor(local_70);
              _ftol2_sse();
              local_70 = (double)((int)local_80 / 2);
              lVar12 = extraout_EAX;
              floor(local_70);
              _ftol2_sse();
              StartCockpitTimer((long)local_80,extraout_EAX_00,lVar12);
            }
            if (this->m_RecyclerHandles[iVar3 + -8] % (int)this->m_TeamPos[0x24] == 0) {
              if (*(char *)((int)(this[1].PlayerShipODF + -0x273) + iVar3 + 0x36) == '\0') {
                SetTeamNum(*(int *)((int)(this[1].PlayerShipODF + -0x264) + (iVar3 + 0xf) * 4),
                           (int)puVar9);
                SetObjectiveOn(*(int *)((int)(this[1].PlayerShipODF + -0x264) + (iVar3 + 0xf) * 4));
                *(undefined1 *)((int)(this[1].PlayerShipODF + -0x273) + iVar3 + 0x36) = 1;
              }
              else {
                SetTeamNum(*(int *)((int)(this[1].PlayerShipODF + -0x264) + (iVar3 + 0xf) * 4),
                           this->m_RecyclerHandles[iVar3 + 8]);
                SetObjectiveOff(*(int *)((int)(this[1].PlayerShipODF + -0x264) + (iVar3 + 0xf) * 4))
                ;
                *(undefined1 *)((int)(this[1].PlayerShipODF + -0x273) + iVar3 + 0x36) = 0;
              }
            }
            if (this->m_RecyclerHandles[iVar3 + -8] == this->UserTarget[8]) {
              iVar5 = 0;
              if (this->m_RecyclerHandles[iVar3 + 8] != 0) {
                iVar11 = -1;
                iVar5 = GetPlayerHandle(this->m_RecyclerHandles[iVar3 + 8]);
                AddScore(iVar5,iVar11);
                iVar5 = this->m_RecyclerHandles[iVar3 + 8];
              }
              local_80 = (int *)GetPlayerHandle(iVar5);
              iVar5 = *(int *)((int)(this[1].PlayerShipODF + -0x264) + (iVar3 + 0xf) * 4);
              this->m_RecyclerHandles[iVar3 + 8] = (int)puVar9;
              SetTeamNum(iVar5,(int)puVar9);
              iVar5 = 0;
              local_70 = (double)((ulonglong)local_70 & 0xffffffff00000000);
              do {
                iVar5 = GetTap(*(int *)((int)(this[1].PlayerShipODF + -0x264) + (iVar3 + 0xf) * 4),
                               iVar5);
                if (iVar5 != 0) {
                  SetTeamNum(iVar5,(int)puVar9);
                }
                iVar5 = local_70._0_4_ + 1;
                local_70 = (double)CONCAT44(local_70._4_4_,iVar5);
              } while (iVar5 < 8);
              iVar11 = 1;
              iVar5 = GetPlayerHandle((int)puVar9);
              AddScore(iVar5,iVar11);
              this->m_CaptureGoals[iVar3 + 8] = 0;
              puVar4 = (undefined1 *)GetLocalPlayerTeamNumber();
              if (puVar4 == puVar9) {
                StopCockpitTimer();
                HideCockpitTimer();
              }
              SetObjectiveOff(*(int *)((int)(this[1].PlayerShipODF + -0x264) + (iVar3 + 0xf) * 4));
              this->m_RecyclerHandles[iVar3 + -8] = 0;
              *(undefined1 *)((int)local_84 + 0xe80a + iVar3) = 0;
              ((undefined1 *)((int)&this[1]._padding_ + 2))[(int)puVar9] = 0;
              if (local_80 == (int *)0x0) {
                iVar3 = GetPlayerHandle((int)puVar9);
                GetPlayerName(iVar3);
                sprintf_s<1024>(&TempMsgString,"-- %s Captured a Goal!");
              }
              else {
                GetPlayerName((int)local_80);
                iVar3 = GetPlayerHandle((int)puVar9);
                GetPlayerName(iVar3);
                sprintf_s<1024>(&TempMsgString,"-- %s Captured a Goal from %s!");
              }
              AddToMessagesBox2(TempMsgString,0xffffff00);
            }
            break;
          }
          local_84 = (float)((int)(this->PlayerShipODF + -0x279) + 4 + (int)puVar9 * 0x10);
          if (*(char *)((int)local_84 + 0xe80a + iVar3) != '\0') {
            *local_78 = 0;
            *local_64 = 0.0;
            SetTeamNum(*local_88,*local_74);
            puVar4 = (undefined1 *)GetLocalPlayerTeamNumber();
            if (puVar4 == puVar9) {
              StopCockpitTimer();
              HideCockpitTimer();
            }
            if (*(int *)((int)(this[1].PlayerShipODF + -0x263) + (puVar9 + 0xf) * 4) == *local_88) {
              iVar11 = 0;
              iVar5 = GetPlayerHandle((int)puVar9);
              SetTarget(iVar5,iVar11);
            }
            *(undefined1 *)((int)local_84 + 0xe80a + iVar3) = 0;
            ((undefined1 *)((int)&this[1]._padding_ + 2))[(int)puVar9] = 0;
          }
        }
        iVar3 = iVar3 + 1;
        local_64 = local_64 + 1;
        local_88 = local_88 + 1;
        local_78 = local_78 + 1;
        local_74 = local_74 + 1;
        local_60 = local_60 + 1;
        local_70 = (double)CONCAT44(local_70._4_4_,iVar3);
      } while (iVar3 < (int)this->m_SavedPlayerLocalAmmo[0xe][3]);
      if (this->m_TeamPos[0x29] == 0.0) {
        local_70 = (double)((ulonglong)local_70 & 0xffffffff00000000);
        local_89 = '\x01';
        if (0 < (int)this->m_SavedPlayerLocalAmmo[0xe][3]) {
          piVar8 = this->m_RecyclerHandles + 8;
          do {
            if (((piVar8[0x10] != 0) || (*piVar8 == 0)) ||
               (((undefined1 *)*piVar8 != puVar9 ||
                (bVar2 = IsTeamAllied((int)puVar9,*piVar8), !bVar2)))) {
              local_89 = '\0';
              goto LAB_4fc411cc;
            }
            piVar8 = piVar8 + 1;
            iVar3 = local_70._0_4_ + 1;
            local_70 = (double)CONCAT44(local_70._4_4_,iVar3);
          } while (iVar3 < (int)this->m_SavedPlayerLocalAmmo[0xe][3]);
        }
      }
      else {
        iVar3 = GetPlayerHandle((int)puVar9);
        iVar3 = GetScore(iVar3);
        if ((int)this->m_TeamPos[0x29] <= iVar3) {
          local_89 = '\x01';
        }
LAB_4fc411cc:
        if (local_89 == '\0') goto LAB_4fc413a7;
      }
      if ((char)this[1]._padding_ == '\0') {
        bVar2 = IsTeamplayOn();
        if (!bVar2) {
          if (*(char *)((int)&this[1]._padding_ + (int)puVar9) == '\0') {
            if (this->m_TeamPos[0x29] == 0.0) {
              GetPlayerName(*(int *)((int)(this[1].PlayerShipODF + -0x265) + (puVar9 + 0xf) * 4));
              sprintf_s<1024>(&TempMsgString,"-- %s has won! Captured All Goals!");
            }
            else {
              GetPlayerName(*(int *)((int)(this[1].PlayerShipODF + -0x265) + (puVar9 + 0xf) * 4));
              sprintf_s<1024>(&TempMsgString,"-- %s has won! Captured %d Goals!");
            }
            iVar5 = 100;
            iVar3 = GetPlayerHandle((int)puVar9);
            AddScore(iVar3,iVar5);
            iVar3 = GetPlayerHandle((int)puVar9);
            NoteGameoverByScore(iVar3);
          }
          else {
            if (this->m_TeamPos[0x29] == 0.0) {
              sprintf_s<1024>(&TempMsgString,"-- Team %d has won! Captured All Goals!");
            }
            else {
              sprintf_s<1024>(&TempMsgString,"-- Team %d has won! Captured %d Goals!");
            }
            iVar5 = 100;
            iVar3 = GetPlayerHandle((int)puVar9);
            AddScore(iVar3,iVar5);
            NoteGameoverWithCustomMessage(TempMsgString);
          }
          pcVar10 = TempMsgString;
          goto LAB_4fc4138b;
        }
        local_84 = (float)WhichTeamGroup((int)puVar9);
        if (this->m_TeamPos[0x29] == 0.0) {
          sprintf_s<1024>(&TempMsgString,"-- Team %d has won! Captured all Goals!");
        }
        else {
          sprintf_s<1024>(&TempMsgString,"-- Team %d has won! Captured %d Goals!");
        }
        iVar5 = 100;
        iVar3 = GetPlayerHandle((int)puVar9);
        AddScore(iVar3,iVar5);
        NoteGameoverWithCustomMessage(TempMsgString);
        fVar7 = local_84;
        iVar3 = 0;
        do {
          fVar6 = (float)WhichTeamGroup(iVar3);
          if (fVar6 == fVar7) {
            iVar11 = 100;
            iVar5 = GetPlayerHandle(iVar3);
            AddScore(iVar5,iVar11);
          }
          iVar3 = iVar3 + 1;
        } while (iVar3 < 0x10);
        AddToMessagesBox2(TempMsgString,0xffffff00);
        DoGameover(10.0);
        puVar9 = local_5c;
LAB_4fc4139f:
        *(undefined1 *)&this[1]._padding_ = 1;
      }
    }
LAB_4fc413a7:
    local_5c = puVar9 + 1;
    if (0xf < (int)local_5c) {
      return;
    }
  } while( true );
}

