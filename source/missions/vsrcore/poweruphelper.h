// PROVENANCE: ancestor none (decompile-only; the 2015 tree only had IsPowerup) | declarations original/missions/Strategy02.pdb via tools/pdb_types.py; operator== from reference/decompiled/strategy02-ghidra12.2/src/missions/vsrcore/poweruphelper.h.decomp.c (lines 32-90) | status: ported
#ifndef _PowerupHelper_
#define _PowerupHelper_

#include "ScriptUtils.h"
#include "bzcscriptutils.h"
#include <vector>

class BZ1Helper;

// Every powerup on the map: what it gives (for the pickup code elsewhere), its sounds, and the random velocity kick it gets a second after it appears.
class PowerupHelper
{
	friend struct VsrLayoutCheck_PowerupHelper; // scaffold: QA gate 2 hook (layout asserts); not GBD's
public:

	struct PowerupClass {
		friend struct VsrLayoutCheck_PowerupHelper__PowerupClass; // scaffold: QA gate 2 hook (layout asserts); not GBD's
		Handle PowerupObject; // This Powerup Object.
		unsigned int ObjClassHash; // FNV-1a Hash of the ObjClass.
		long HealthUp; // healthUp / serviceUp.
		long AmmoUp; // ammo powerup's healthUp / serviceUp (sic, see AddPowerupObject).
		long LocalAmmoUp; // localAmmoUp.
		char WeaponUp[MAX_ODF_LENGTH]; // weaponName of a weapon powerup.
		char SoundPickup[MAX_ODF_LENGTH];
		char SoundReject[MAX_ODF_LENGTH];
		int DelayTime; // Turns until the velocity kick; counts down from one second.
		int HitMask;
		Vector Position; // It's current position.
		int CurrCommand; // Its command last tick, so PostLoad can re-issue a Go.
		Vector CurrWhere; // Where that command points.
		Vector Velocity; // Its velocity last tick.

		PowerupClass() { memset(this, 0, sizeof(PowerupClass)); };

		// GBD: member-by-member compare for PostLoad's resync report; the first difference is logged and ends the compare.
		// The shipped compare stops at DelayTime (HitMask, Position, CurrCommand, CurrWhere, Velocity are not compared) and its handle message says RepairPowerupObject.
		friend bool operator==(const PowerupClass &a, const PowerupClass &b)
		{
			if (a.PowerupObject != b.PowerupObject)
			{
				char ODFNameA[MAX_ODF_LENGTH] = { 0 };
				char ODFNameB[MAX_ODF_LENGTH] = { 0 };
				GetODFName(a.PowerupObject, ODFNameA);
				GetODFName(b.PowerupObject, ODFNameB);
				FormatLogMessage("POWERUPCLASS MISMATCH: RepairPowerupObject: %08x '%s' and %08x '%s'", a.PowerupObject, ODFNameA, b.PowerupObject, ODFNameB);
				return false;
			}
			if (a.ObjClassHash != b.ObjClassHash)
			{
				FormatLogMessage("POWERUPCLASS MISMATCH: ObjClassHash: %d and %d", a.ObjClassHash, b.ObjClassHash);
				return false;
			}
			if (a.HealthUp != b.HealthUp)
			{
				FormatLogMessage("POWERUPCLASS MISMATCH: HealthUp: %d and %d", a.HealthUp, b.HealthUp);
				return false;
			}
			if (a.AmmoUp != b.AmmoUp)
			{
				FormatLogMessage("POWERUPCLASS MISMATCH: AmmoUp: %d and %d", a.AmmoUp, b.AmmoUp);
				return false;
			}
			if (a.LocalAmmoUp != b.LocalAmmoUp)
			{
				FormatLogMessage("POWERUPCLASS MISMATCH: LocalAmmoUp: %d and %d", a.LocalAmmoUp, b.LocalAmmoUp);
				return false;
			}
			if (_stricmp(a.WeaponUp, b.WeaponUp) != 0)
			{
				FormatLogMessage("POWERUPCLASS MISMATCH: WeaponUp: '%s' and '%s'", a.WeaponUp, b.WeaponUp);
				return false;
			}
			if (_stricmp(a.SoundPickup, b.SoundPickup) != 0)
			{
				FormatLogMessage("POWERUPCLASS MISMATCH: SoundPickup: '%s' and '%s'", a.SoundPickup, b.SoundPickup);
				return false;
			}
			if (_stricmp(a.SoundReject, b.SoundReject) != 0)
			{
				FormatLogMessage("POWERUPCLASS MISMATCH: SoundReject: '%s' and '%s'", a.SoundReject, b.SoundReject);
				return false;
			}
			if (a.DelayTime != b.DelayTime)
			{
				FormatLogMessage("POWERUPCLASS MISMATCH: DelayTime: %d and %d", a.DelayTime, b.DelayTime);
				return false;
			}
			return true;
		}
	};

private:

	static PowerupHelper *m_PowerupHelper;

	std::vector<PowerupClass> PowerupList;
	static bool ShouldRemovePowerup(const PowerupClass &entry) { return !IsAround(entry.PowerupObject); }

public:
	PowerupHelper();
	~PowerupHelper();
	static PowerupHelper &Get() { return *m_PowerupHelper; }

	int GetNumPowerupObjects() { return int(PowerupList.size()); }
	const PowerupClass &GetPowerupInfo(int index) const { return PowerupList[index]; } // Read only version.

	// The 4th argument is dead in the shipped binary (its PDB symbol is gone and every call site pushes a placeholder); the long is the ObjClass hash the body reads.
	void AddPowerupObject(const Handle h, const char *TempODF1, const char *TempODF2, const int UnusedArg, const long ObjClassHash);

	bool Load(bool missionSave);
	bool PostLoad(bool missionSave);
	bool Save(bool missionSave);

	void Execute(BZ1Helper &bz1Helper);
};

#define VSR_LAYOUT_CHECK_PowerupHelper
#include "vsr_layout_asserts.h"
#undef VSR_LAYOUT_CHECK_PowerupHelper

#endif
