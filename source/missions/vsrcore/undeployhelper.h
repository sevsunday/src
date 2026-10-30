// PROVENANCE: ancestor reference/ancestor-bz1helper-2015/Shared/UndeployHelper.h @6fda4f5 | declarations original/missions/Strategy02.pdb via tools/pdb_types.py; operator== from reference/decompiled/strategy02-ghidra12.2/src/missions/vsrcore/undeployhelper.h.decomp.c (lines 22-56) | status: ported
#ifndef _UndeployHelper_
#define _UndeployHelper_

#include "ScriptUtils.h"
#include "bzcscriptutils.h"
#include <vector>

class BZ1Helper;

class UndeployHelper
{
	friend struct VsrLayoutCheck_UndeployHelper; // scaffold: QA gate 2 hook (layout asserts); not GBD's
public:
	// GBD: public (the file-scope TempUndeployBuffer snapshot is a vector of these).
	struct UndeployClass {
		friend struct VsrLayoutCheck_UndeployHelper__UndeployClass; // scaffold: QA gate 2 hook (layout asserts); not GBD's
		Handle UndeployingObject; // This undeploying Object.
		bool IsAnimated; // Is it animated?
		int UndeployTime; // undeploying time.
		float UndeployFrames; // Animation frames.

		UndeployClass() { memset(this, 0, sizeof(UndeployClass)); };

		// GBD: member-by-member compare for PostLoad's resync report; the first difference is logged and ends the compare.
		friend bool operator==(const UndeployClass &a, const UndeployClass &b)
		{
			if (a.UndeployingObject != b.UndeployingObject)
			{
				char ODFNameA[MAX_ODF_LENGTH] = { 0 };
				char ODFNameB[MAX_ODF_LENGTH] = { 0 };
				GetODFName(a.UndeployingObject, ODFNameA);
				GetODFName(b.UndeployingObject, ODFNameB);
				FormatLogMessage("UNDEPLOYCLASS MISMATCH: UndeployingObject: %08x '%s' and %08x '%s'", a.UndeployingObject, ODFNameA, b.UndeployingObject, ODFNameB);
				return false;
			}
			if (a.IsAnimated != b.IsAnimated)
			{
				FormatLogMessage("UNDEPLOYCLASS MISMATCH: IsAnimated: %d and %d", a.IsAnimated, b.IsAnimated);
				return false;
			}
			if (a.UndeployTime != b.UndeployTime)
			{
				FormatLogMessage("UNDEPLOYCLASS MISMATCH: UndeployTime: %d and %d", a.UndeployTime, b.UndeployTime);
				return false;
			}
			if (a.UndeployFrames != b.UndeployFrames)
			{
				FormatLogMessage("UNDEPLOYCLASS MISMATCH: UndeployFrames: %f and %f", a.UndeployFrames, b.UndeployFrames);
				return false;
			}
			return true;
		}
	};

private:

	static UndeployHelper *m_UndeployHelper;

	std::vector<UndeployClass> UndeployList;
	static bool ShouldRemoveUndeployObject(const UndeployClass &entry) { return !IsAround(entry.UndeployingObject); }

public:
	UndeployHelper();
	~UndeployHelper();
	static UndeployHelper &Get() { return *m_UndeployHelper; }

	// GBD: ODFName is the "BZCundep<slot>" powerup; the base slot it names is read straight off it. h (the powerup) is no longer touched here.
	void AddUndeployObject(const Handle h, const int Team, const char *ODFName);

	bool Load(bool missionSave);
	bool PostLoad(bool missionSave);
	bool Save(bool missionSave);

	void Execute(BZ1Helper &bz1Helper);
};

#define VSR_LAYOUT_CHECK_UndeployHelper
#include "vsr_layout_asserts.h"
#undef VSR_LAYOUT_CHECK_UndeployHelper

#endif
