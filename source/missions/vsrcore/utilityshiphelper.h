// PROVENANCE: ancestor reference/ancestor-bz1helper-2015/Shared/UtilityShipHelper.h @6fda4f5 | declarations original/missions/Strategy02.pdb via tools/pdb_types.py; operator== from reference/decompiled/strategy02-ghidra12.2/src/missions/vsrcore/utilityshiphelper.h.decomp.c (lines 32-96) | status: ported
#ifndef _UtilityShipHelper_
#define _UtilityShipHelper_

#include "ScriptUtils.h"
#include "bzcscriptutils.h"
#include <vector>

class BZ1Helper;

// Scavengers, service trucks, tugs, minelayers, APCs: the ships the AI escorts and the dispatcher serves.
class UtilityShipHelper
{
	friend struct VsrLayoutCheck_UtilityShipHelper; // scaffold: QA gate 2 hook (layout asserts); not GBD's
public:

	struct UtilityShipClass {
		friend struct VsrLayoutCheck_UtilityShipHelper__UtilityShipClass; // scaffold: QA gate 2 hook (layout asserts); not GBD's
		Handle UtilityShipObject; // This UtilityShip Object.
		bool DoDrop; // Scavenger: can it drop its scrap hold as a building (doDrop)?
		bool ServiceAllies; // Service truck: does it serve allied teams too?
		bool DoDLLDispatch; // Does the DLL's idle dispatcher drive it?
		unsigned int ObjClassHash; // FNV-1a Hash of the ObjClass.
		int CurTeamNum; // Current Team num, stored to preseve calls to GetTeamNum. Updated once every tick.
		int ScrapAmount; // This Scavenger's scraphold.
		int EscortPriority; // How important is this? 0 = None, 1 = Low, 2 = Medium, 3 = High.
		int DropClassMask; // Scavenger: which drop buildings it may become. 1 = recycler, 2 = extractor, 4 = silo.
		int ServiceTypes; // Service truck: what it serves (see AddUtilityShipObject for the bit layout).
		Vector Position; // It's current position.

		UtilityShipClass() { memset(this, 0, sizeof(UtilityShipClass)); };

		// GBD: member-by-member compare for PostLoad's resync report; the first difference is logged and ends the compare.
		// The shipped compare skips ServiceTypes, and its Position message says BUILDINGCLASS (copy-paste; kept for parity).
		friend bool operator==(const UtilityShipClass &a, const UtilityShipClass &b)
		{
			if (a.UtilityShipObject != b.UtilityShipObject)
			{
				char ODFNameA[MAX_ODF_LENGTH] = { 0 };
				char ODFNameB[MAX_ODF_LENGTH] = { 0 };
				GetODFName(a.UtilityShipObject, ODFNameA);
				GetODFName(b.UtilityShipObject, ODFNameB);
				FormatLogMessage("UTILITYSHIPCLASS MISMATCH: UtilityShipObject: %08x '%s' and %08x '%s'", a.UtilityShipObject, ODFNameA, b.UtilityShipObject, ODFNameB);
				return false;
			}
			if (a.DoDrop != b.DoDrop)
			{
				FormatLogMessage("UTILITYSHIPCLASS MISMATCH: DoDrop: %d and %d", a.DoDrop, b.DoDrop);
				return false;
			}
			if (a.ServiceAllies != b.ServiceAllies)
			{
				FormatLogMessage("UTILITYSHIPCLASS MISMATCH: ServiceAllies: %d and %d", a.ServiceAllies, b.ServiceAllies);
				return false;
			}
			if (a.DoDLLDispatch != b.DoDLLDispatch)
			{
				FormatLogMessage("UTILITYSHIPCLASS MISMATCH: DoDLLDispatch: %d and %d", a.DoDLLDispatch, b.DoDLLDispatch);
				return false;
			}
			if (a.ObjClassHash != b.ObjClassHash)
			{
				FormatLogMessage("UTILITYSHIPCLASS MISMATCH: ObjClassHash: %d and %d", a.ObjClassHash, b.ObjClassHash);
				return false;
			}
			if (a.CurTeamNum != b.CurTeamNum)
			{
				FormatLogMessage("UTILITYSHIPCLASS MISMATCH: CurTeamNum: %d and %d", a.CurTeamNum, b.CurTeamNum);
				return false;
			}
			if (a.ScrapAmount != b.ScrapAmount)
			{
				FormatLogMessage("UTILITYSHIPCLASS MISMATCH: ScrapAmount: %d and %d", a.ScrapAmount, b.ScrapAmount);
				return false;
			}
			if (a.EscortPriority != b.EscortPriority)
			{
				FormatLogMessage("UTILITYSHIPCLASS MISMATCH: EscortPriority: %d and %d", a.EscortPriority, b.EscortPriority);
				return false;
			}
			if (a.DropClassMask != b.DropClassMask)
			{
				FormatLogMessage("UTILITYSHIPCLASS MISMATCH: DropClassMask: %d and %d", a.DropClassMask, b.DropClassMask);
				return false;
			}
			if (a.Position != b.Position)
			{
				FormatLogMessage("BUILDINGCLASS MISMATCH: Position: %f %f %f and %f %f %f", a.Position.x, a.Position.y, a.Position.z, b.Position.x, b.Position.y, b.Position.z);
				return false;
			}
			return true;
		}
	};

private:

	static UtilityShipHelper *m_UtilityShipHelper;

	std::vector<UtilityShipClass> UtilityShipList;
	static bool ShouldRemoveUtilityShip(const UtilityShipClass &entry) { return !IsAround(entry.UtilityShipObject); }

public:
	UtilityShipHelper();
	~UtilityShipHelper();
	static UtilityShipHelper &Get() { return *m_UtilityShipHelper; }

	int GetNumUtilityShipObjects() { return int(UtilityShipList.size()); }
	Handle &RefUtilityShipHandle(const int index) { return UtilityShipList[index].UtilityShipObject; }

	void AddUtilityShipObject(const Handle h, const int Team, const Vector Position, const int ObjClassHash, const int BZCClassHash, const char *TempODF1, const char *TempODF2, const int TempEscortPriority);

	// A weighted-random escort target (EscortPriority is the weight) among the ships Team may escort.
	Handle GetEscortTarget(const int Team = -1, const int TeamFilter = 0);
	// The nearest service truck that will come to `me` (allied, idle unless IgnoreBusy, DLL-dispatched, serving me's kind). 0 if none.
	Handle FindServiceTruck(const Handle me, const int Team = -1, const bool IgnoreBusy = false, const float MaxRange = 0.0f, const int _Parg = 0); // _Parg: PDB name; the shipped body never reads it.

	bool Load(bool missionSave);
	bool PostLoad(bool missionSave);
	bool Save(bool missionSave);

	void Execute(BZ1Helper &bz1Helper);
};

#define VSR_LAYOUT_CHECK_UtilityShipHelper
#include "vsr_layout_asserts.h"
#undef VSR_LAYOUT_CHECK_UtilityShipHelper

#endif
