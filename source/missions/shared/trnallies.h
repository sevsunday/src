// PROVENANCE: ancestor reference/ancestor-1.3/Missions/Shared/TRNAllies.h @353698f | declarations original/missions/Strategy02.pdb via tools/pdb_types.py | status: ported
#ifndef TRNAllies_H__
#define TRNAllies_H__

#include "ScriptUtils.h"

class TRNAllies
{
	friend struct VsrLayoutCheck_TRNAllies; // scaffold: QA gate 2 hook (layout asserts); not GBD's
	public:

	// Pass in a trn file name, e.g. "bridges2i.trn", and it'll set up
	// default team allies specified in the trn file. See changelog
	// for exact specs of what needs to be in the TRN.
	static void SetupTRNAllies(const char* pTRNName);

};

#define VSR_LAYOUT_CHECK_TRNAllies
#include "vsr_layout_asserts.h"
#undef VSR_LAYOUT_CHECK_TRNAllies

#endif // #ifndef TRNAllies_H__
