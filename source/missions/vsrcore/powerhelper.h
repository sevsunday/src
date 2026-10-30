// PROVENANCE: ancestor reference/ancestor-bz1helper-2015/Shared/PowerHelper.h @6fda4f5 | declarations original/missions/Strategy02.pdb via tools/pdb_types.py; operator== from reference/decompiled/strategy02-ghidra12.2/src/missions/vsrcore/powerhelper.h.decomp.c (lines 28-96) | status: ported
#ifndef _PowerHelper_
#define _PowerHelper_

#include "ScriptUtils.h"
#include "bzcscriptutils.h"
#include <vector>

class BZ1Helper;

class PowerHelper
{
	friend struct VsrLayoutCheck_PowerHelper; // scaffold: QA gate 2 hook (layout asserts); not GBD's
public:

	struct PowerClass {
		friend struct VsrLayoutCheck_PowerHelper__PowerClass; // scaffold: QA gate 2 hook (layout asserts); not GBD's
		Handle PowerObject; // This Power Object.
		bool WasDemolished; // Was it demolished?
		bool DoBettyLost; // Voice over for Lost?
		bool IsPowered; // Is this currently powered? (if it needs power. Power is power, so does power power?
		int PowerTeam; // What team was this on?
		float PowerRange; // How far it supplies power.
		int PowerMask; // Bitmask for what bits to look at.
		int PowerMatch; // Bitmask for what the bits need to be.
		int PowerProvide; // Bitmask for what kind of power this provides.
		Vector Position; // It's current position.

		PowerClass() { memset(this, 0, sizeof(PowerClass)); };

		// GBD: member-by-member compare for PostLoad's resync report; the first difference is logged and ends the compare.
		friend bool operator==(const PowerClass &a, const PowerClass &b)
		{
			if (a.PowerObject != b.PowerObject)
			{
				char ODFNameA[MAX_ODF_LENGTH] = { 0 };
				char ODFNameB[MAX_ODF_LENGTH] = { 0 };
				GetODFName(a.PowerObject, ODFNameA);
				GetODFName(b.PowerObject, ODFNameB);
				FormatLogMessage("POWERCLASS MISMATCH: ObjectHandle: %08x '%s' and %08x '%s'", a.PowerObject, ODFNameA, b.PowerObject, ODFNameB);
				return false;
			}
			if (a.WasDemolished != b.WasDemolished)
			{
				FormatLogMessage("POWERCLASS MISMATCH: WasDemolished: %d and %d", a.WasDemolished, b.WasDemolished);
				return false;
			}
			if (a.DoBettyLost != b.DoBettyLost)
			{
				FormatLogMessage("POWERCLASS MISMATCH: DoBettyLost: %d and %d", a.DoBettyLost, b.DoBettyLost);
				return false;
			}
			if (a.IsPowered != b.IsPowered)
			{
				FormatLogMessage("POWERCLASS MISMATCH: IsPowered: %d and %d", a.IsPowered, b.IsPowered);
				return false;
			}
			if (a.PowerTeam != b.PowerTeam)
			{
				FormatLogMessage("POWERCLASS MISMATCH: PowerTeam: %d and %d", a.PowerTeam, b.PowerTeam);
				return false;
			}
			if (a.PowerRange != b.PowerRange)
			{
				FormatLogMessage("POWERCLASS MISMATCH: PowerRange: %f and %f", a.PowerRange, b.PowerRange);
				return false;
			}
			if (a.PowerMask != b.PowerMask)
			{
				FormatLogMessage("POWERCLASS MISMATCH: PowerMask: %d and %d", a.PowerMask, b.PowerMask);
				return false;
			}
			if (a.PowerMatch != b.PowerMatch)
			{
				FormatLogMessage("POWERCLASS MISMATCH: PowerMatch: %d and %d", a.PowerMatch, b.PowerMatch);
				return false;
			}
			if (a.PowerProvide != b.PowerProvide)
			{
				FormatLogMessage("POWERCLASS MISMATCH: PowerProvide: %d and %d", a.PowerProvide, b.PowerProvide);
				return false;
			}
			if (a.Position != b.Position)
			{
				FormatLogMessage("POWERCLASS MISMATCH: Position: %f %f %f and %f %f %f", a.Position.x, a.Position.y, a.Position.z, b.Position.x, b.Position.y, b.Position.z);
				return false;
			}
			return true;
		}
	};

private:

	static PowerHelper *m_PowerHelper;
	std::vector<PowerClass> PowerList;
	//static bool ShouldRemovePower(const PowerClass &entry) { return !IsAround(entry.PowerObject); }

public:
	PowerHelper();
	~PowerHelper();
	static PowerHelper &Get() { return *m_PowerHelper; }

	void AddPowerObject(const Handle h, const char* TempODF1, const char* TempODF2);
	void DeletePowerObject(const Handle h);

	int GetNumPowerObjects() { return int(PowerList.size()); }
	const PowerClass &GetPowerInfo(int index) const { return PowerList[index]; } // Read only version.
	PowerClass &RefPowerInfo(int index) { return PowerList[index]; } // BZ1Helper::DeleteObject marks a dying power plant demolished (the shipped code reaches the list directly).

	bool Load(bool missionSave);
	bool PostLoad(bool missionSave);
	bool Save(bool missionSave);

	void Execute(BZ1Helper &bz1Helper);
};

#define VSR_LAYOUT_CHECK_PowerHelper
#include "vsr_layout_asserts.h"
#undef VSR_LAYOUT_CHECK_PowerHelper

#endif
