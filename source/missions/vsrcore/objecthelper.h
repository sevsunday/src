// PROVENANCE: ancestor reference/ancestor-bz1helper-2015/Shared/BZ1Helper.h @6fda4f5 (ObjectClass, lines 348-376 — the master object list lived inside BZ1Helper in 2015) | declarations original/missions/Strategy02.pdb via tools/pdb_types.py; operator== from reference/decompiled/strategy02-ghidra12.2/src/missions/vsrcore/objecthelper.h.decomp.c (lines 55-174) | status: ported
#ifndef _ObjectHelper_
#define _ObjectHelper_

#include "ScriptUtils.h"
#include "bzcscriptutils.h"
#include <vector>

class BZ1Helper;
class PortalHelper;

// The master list of every game object the DLL tracks (one entry per AddObject). Split out of BZ1Helper after 2015.
class ObjectHelper
{
	friend struct VsrLayoutCheck_ObjectHelper; // scaffold: QA gate 2 hook (layout asserts); not GBD's
public:

	// Master Object Class filters.
	struct ObjectClass {
		friend struct VsrLayoutCheck_ObjectHelper__ObjectClass; // scaffold: QA gate 2 hook (layout asserts); not GBD's
		Handle ObjectHandle; // The handle.
		unsigned int ODFNameHash; // FNV-1a Hash of the ODF Name.
		unsigned int ObjClassHash; // FNV-1a Hash of the ObjClass.
		unsigned int BZCClassHash; // FNV-1a Hash of the BZCClasslabel.
		int CategoryID; // Custom Class ID #, based on Enum CategoryType.
		bool CanObjectify; // Can this be objectified?
		bool CanObjectifyDeployed; // Can this be objectified while deployed?
		bool CanTeleport; // Can this object Teleport?
		bool CanBeIdleVictim; // Can the idle-unit code pick on this?
		int OriginalTeam; // Store it's original Team number for ST Mission code.
		int CurTeamNum; // Current Team num, stored to preseve calls to GetTeamNum. Updated once every tick.
		int PTeam; // Current perceived team. Updated once every tick.
		float EngageRange; // Store it's engageRange.
		bool IsObjectified[MAX_TEAMS]; // Is it objectified? (per team)
		bool IsBeingJammed[MAX_TEAMS]; // Flag for if this object is being jammed or not. (per team)
		Vector Position; // It's current position.
		long MaxHealth; // Its health and ammo capacity when added.
		long MaxAmmo;

		ObjectClass() { memset(this, 0, sizeof(ObjectClass)); };

		// GBD: member-by-member compare for PostLoad's resync report; the first difference is logged and ends the compare.
		friend bool operator==(const ObjectClass &a, const ObjectClass &b)
		{
			if (a.ObjectHandle != b.ObjectHandle)
			{
				char ODFNameA[MAX_ODF_LENGTH] = { 0 };
				char ODFNameB[MAX_ODF_LENGTH] = { 0 };
				GetODFName(a.ObjectHandle, ODFNameA);
				GetODFName(b.ObjectHandle, ODFNameB);
				FormatLogMessage("OBJECTLIST MISMATCH: ObjectHandle: %08x '%s' and %08x '%s'", a.ObjectHandle, ODFNameA, b.ObjectHandle, ODFNameB);
				return false;
			}
			if (a.ODFNameHash != b.ODFNameHash)
			{
				FormatLogMessage("OBJECTLIST MISMATCH: ODFNameHash: %d and %d", a.ODFNameHash, b.ODFNameHash);
				return false;
			}
			if (a.ObjClassHash != b.ObjClassHash)
			{
				FormatLogMessage("OBJECTLIST MISMATCH: ObjClassHash: %d and %d", a.ObjClassHash, b.ObjClassHash);
				return false;
			}
			if (a.BZCClassHash != b.BZCClassHash)
			{
				FormatLogMessage("OBJECTLIST MISMATCH: BZCClassHash: %d and %d", a.BZCClassHash, b.BZCClassHash);
				return false;
			}
			if (a.CategoryID != b.CategoryID)
			{
				FormatLogMessage("OBJECTLIST MISMATCH: CategoryID: %d and %d", a.CategoryID, b.CategoryID);
				return false;
			}
			if (a.CanObjectify != b.CanObjectify)
			{
				FormatLogMessage("OBJECTLIST MISMATCH: CanObjectify: %d and %d", a.CanObjectify, b.CanObjectify);
				return false;
			}
			if (a.CanObjectifyDeployed != b.CanObjectifyDeployed)
			{
				FormatLogMessage("OBJECTLIST MISMATCH: CanObjectifyDeployed: %d and %d", a.CanObjectifyDeployed, b.CanObjectifyDeployed);
				return false;
			}
			if (a.CanTeleport != b.CanTeleport)
			{
				FormatLogMessage("OBJECTLIST MISMATCH: CanTeleport: %d and %d", a.CanTeleport, b.CanTeleport);
				return false;
			}
			if (a.CanBeIdleVictim != b.CanBeIdleVictim)
			{
				FormatLogMessage("OBJECTLIST MISMATCH: CanBeIdleVictim: %d and %d", a.CanBeIdleVictim, b.CanBeIdleVictim);
				return false;
			}
			if (a.OriginalTeam != b.OriginalTeam)
			{
				FormatLogMessage("OBJECTLIST MISMATCH: OriginalTeam: %d and %d", a.OriginalTeam, b.OriginalTeam);
				return false;
			}
			if (a.CurTeamNum != b.CurTeamNum)
			{
				FormatLogMessage("OBJECTLIST MISMATCH: CurTeamNum: %d and %d", a.CurTeamNum, b.CurTeamNum);
				return false;
			}
			if (a.PTeam != b.PTeam)
			{
				FormatLogMessage("OBJECTLIST MISMATCH: PTeam: %d and %d", a.PTeam, b.PTeam);
				return false;
			}
			if (a.EngageRange != b.EngageRange)
			{
				FormatLogMessage("OBJECTLIST MISMATCH: EngageRange: %f and %f", a.EngageRange, b.EngageRange);
				return false;
			}
			for (int i = 0; i < MAX_TEAMS; i++)
			{
				if (a.IsObjectified[i] != b.IsObjectified[i])
				{
					FormatLogMessage("OBJECTLIST MISMATCH: IsObjectified%d: %d and %d", i, a.IsObjectified[i], b.IsObjectified[i]);
					return false;
				}
				if (a.IsBeingJammed[i] != b.IsBeingJammed[i])
				{
					FormatLogMessage("OBJECTLIST MISMATCH: IsBeingJammed%d: %d and %d", i, a.IsBeingJammed[i], b.IsBeingJammed[i]);
					return false;
				}
			}
			if (a.Position != b.Position)
			{
				FormatLogMessage("OBJECTLIST MISMATCH: Position: %f %f %f and %f %f %f", a.Position.x, a.Position.y, a.Position.z, b.Position.x, b.Position.y, b.Position.z);
				return false;
			}
			if (a.MaxHealth != b.MaxHealth)
			{
				FormatLogMessage("OBJECTLIST MISMATCH: MaxHealth: %d and %d", a.MaxHealth, b.MaxHealth);
				return false;
			}
			if (a.MaxAmmo != b.MaxAmmo)
			{
				FormatLogMessage("OBJECTLIST MISMATCH: MaxAmmo: %d and %d", a.MaxAmmo, b.MaxAmmo);
				return false;
			}
			return true;
		}
	};

private:

	std::vector<ObjectClass> HandleList;
	static bool ShouldRemoveObject(const ObjectClass &entry) { return !IsAround(entry.ObjectHandle); }

public:
	ObjectHelper();
	~ObjectHelper();

	bool Load(bool missionSave);
	bool PostLoad(bool missionSave);
	bool Save(bool missionSave);

	int GetNumHandles() { return int(HandleList.size()); }
	const ObjectClass &GetHandleInfo(int index) const { return HandleList[index]; } // Read only version.
	ObjectClass &RefHandleInfo(int index) { return HandleList[index]; }

	// Appends a zeroed entry and returns its index (BZ1Helper::AddObject fills it in).
	int NewObject() { HandleList.emplace_back(); return int(HandleList.size()) - 1; }

	// Drops the objects that are gone, refreshes team / position / perceived team, and runs the portal check on the ones that can teleport.
	void Execute(BZ1Helper &bz1Helper, PortalHelper *pPortalHelper);
};

#define VSR_LAYOUT_CHECK_ObjectHelper
#include "vsr_layout_asserts.h"
#undef VSR_LAYOUT_CHECK_ObjectHelper

#endif
