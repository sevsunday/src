// PROVENANCE: ancestor reference/ancestor-1.3/Missions/Shared/PUPMgr.h @353698f (verbatim) | declarations original/missions/deathmatch01.pdb via tools/pdb_types.py (myprup 0x8c, PUPMgr statics) | status: ported
#ifndef _PUPMgr_h_
#define _PUPMgr_h_

//
// PUPMgr.cpp
// 
// Utility functions for DLLs-- 'PowerUP ManaGeR'-- handles the list
// of powerups given in the mission, respawns them as appropriate,
// etc.  Pulled out to a separate set of functions from a deathmatch
// cpp file to be more generic
//
// Converted to new DLL interface spec by Nathan Mates 2/23/99
//

#include "ScriptUtils.h"

// Max # of powerups we can have in the world at once.
#define MAX_POWERUPS 100

struct myprup {
	friend struct VsrLayoutCheck_myprup; // scaffold: QA gate 2 hook (layout asserts); not GBD's
	float time;
	float dt;
	char str[64];
	char odf[64];
	bool waiting;
};

class PUPMgr {
	friend struct VsrLayoutCheck_PUPMgr; // scaffold: QA gate 2 hook (layout asserts); not GBD's
private:
	static struct myprup pup[MAX_POWERUPS];
	static int pupHandle[MAX_POWERUPS];
	static int PUPCount; // How many are used in the above list.

public:
	// Scan over lists of AIPaths in the world, generate tables for powerups
	static void Init(void);

	// Run occasionally
	static void Execute(void);

	// Load & save functions
	static bool Load(bool missionSave);
	static bool Save(bool missionSave);
	static bool PostLoad(bool missionSave);
};

#define VSR_LAYOUT_CHECK_myprup
#define VSR_LAYOUT_CHECK_PUPMgr
#include "vsr_layout_asserts.h"
#undef VSR_LAYOUT_CHECK_myprup
#undef VSR_LAYOUT_CHECK_PUPMgr

#endif
