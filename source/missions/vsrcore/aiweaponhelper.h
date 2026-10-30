// PROVENANCE: ancestor reference/ancestor-bz1helper-2015/Shared/AIWeaponHelper.h @6fda4f5 | declarations original/missions/Strategy02.pdb via tools/pdb_types.py | status: ported
#ifndef _AIWeaponHelper_
#define _AIWeaponHelper_

#include "ScriptUtils.h"

class BZ1Helper;

class AIWeaponHelper
{
	friend struct VsrLayoutCheck_AIWeaponHelper; // scaffold: QA gate 2 hook (layout asserts); not GBD's
private:

public:
	AIWeaponHelper();

	// GBD: NumWeapons (-1 = count the hardpoints) only gates the call; Max is in the signature but the shipped body never branches on it
	// (every caller leaves it at its default, so whatever it gated was folded away). Defaults reconstructed.
	void AIGiveWeapons(const Handle h, const int Team, const int NumWeapons = -1, const bool Max = false);
};

#define VSR_LAYOUT_CHECK_AIWeaponHelper
#include "vsr_layout_asserts.h"
#undef VSR_LAYOUT_CHECK_AIWeaponHelper

#endif
