// PROVENANCE: ancestor reference/ancestor-bz1helper-2015/Shared/BZ1Helper.h @6fda4f5 (GravityInfo, lines 462-472 — the gravity system lived inside BZ1Helper in 2015) | declarations original/missions/Strategy02.pdb via tools/pdb_types.py; operator== from reference/decompiled/strategy02-ghidra12.2/src/missions/vsrcore/gravityhelper.h.decomp.c (lines 25-56) | status: ported
#ifndef _GravityHelper_
#define _GravityHelper_

#include "ScriptUtils.h"
#include "bzcscriptutils.h"

class BZ1Helper;

// Cycles the map's gravity through the [Gravity] states of its .trn (Gravity#, OnPeriod#, TranPeriod#). Split out of BZ1Helper after 2015.
class GravityHelper
{
	friend struct VsrLayoutCheck_GravityHelper; // scaffold: QA gate 2 hook (layout asserts); not GBD's
public:

	struct GravityInfo {
		friend struct VsrLayoutCheck_GravityHelper__GravityInfo; // scaffold: QA gate 2 hook (layout asserts); not GBD's
		float TranPeriod;
		float OnPeriod;
		//float OffPeriod;
		float Gravitation;
		float Gravity;
		int OnCounter;

		GravityInfo() { memset(this, 0, sizeof(GravityInfo)); };

		// GBD: member-by-member compare for Load's resync report; the first difference is logged and ends the compare.
		friend bool operator==(const GravityInfo &a, const GravityInfo &b)
		{
			if (a.TranPeriod != b.TranPeriod)
			{
				FormatLogMessage("GRAVITYINFO MISMATCH: TranPeriod: %f and %f", a.TranPeriod, b.TranPeriod);
				return false;
			}
			if (a.OnPeriod != b.OnPeriod)
			{
				FormatLogMessage("GRAVITYINFO MISMATCH: OnPeriod: %f and %f", a.OnPeriod, b.OnPeriod);
				return false;
			}
			if (a.Gravitation != b.Gravitation)
			{
				FormatLogMessage("GRAVITYINFO MISMATCH: Gravitation: %f and %f", a.Gravitation, b.Gravitation);
				return false;
			}
			if (a.Gravity != b.Gravity)
			{
				FormatLogMessage("GRAVITYINFO MISMATCH: Gravity: %f and %f", a.Gravity, b.Gravity);
				return false;
			}
			if (a.OnCounter != b.OnCounter)
			{
				FormatLogMessage("GRAVITYINFO MISMATCH: OnCounter: %d and %d", a.OnCounter, b.OnCounter);
				return false;
			}
			return true;
		}
	};

private:

	GravityInfo gravityInfo[MAX_GRAVITY_TYPES];

public:
	GravityHelper();

	bool Load(bool missionSave);
	bool Save(bool missionSave);

	void Execute(BZ1Helper &bz1Helper);

	// Reads the [Gravity] block of the map's .trn (the .trn must already be open through OpenODF2).
	void LoadGravityInfo(const char *mapTrnFile);
};

#define VSR_LAYOUT_CHECK_GravityHelper
#include "vsr_layout_asserts.h"
#undef VSR_LAYOUT_CHECK_GravityHelper

#endif
