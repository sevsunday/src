// PROVENANCE: ancestor reference/ancestor-bz1helper-2015/Shared/MorphObjectHelper.h @6fda4f5 (field comments and accessors) | declarations original/missions/Strategy02.pdb via tools/pdb_types.py; operator== from reference/decompiled/strategy02-ghidra12.2/src/missions/vsrcore/morphobjecthelper.h.decomp.c (lines 41-178) | status: ported
#ifndef _morphobjecthelper_
#define _morphobjecthelper_

#include "ScriptUtils.h"
#include <vector>

class BZ1Helper;

// Morph Objects: a host unit that swaps itself for its SwitchODF (and its weapons for their altNames) when its MorphObjectToggle weapon is fired,
// e.g. the cloaking units. VSR adds a cloak energy budget and the player's ammo / cloak gauges.
class MorphObjectHelper
{
	friend struct VsrLayoutCheck_MorphObjectHelper; // scaffold: QA gate 2 hook (layout asserts); not GBD's
public:
	struct MorphObjectClass
	{
		friend struct VsrLayoutCheck_MorphObjectHelper__MorphObjectClass; // scaffold: QA gate 2 hook (layout asserts); not GBD's
		Handle MorphObject; // This Morph Object.
		Handle CurrentWho; // This Morph Object's current GetWho.
		bool WeaponActive; // Flag for active status.
		bool ObjectSwitch; // Did we build it yet?
		bool CanFire; // Can fire while switched?
		bool IsCloaker; // Is cloaked while switched?
		int IdleTime; // Idle time.
		int NormalAmmo; // Normal Ammo amount.
		int MaxAmmo; // Max Normal Ammo amount.
		int Command; // Current Command. Used to trigger AI Cloaking.
		int PTeam; // VSR: the perceived team to restore when it decloaks.
		float LocalAmmo[MAX_HARDPOINTS]; // Saved Local Ammo.
		float MaxLocalAmmo[MAX_HARDPOINTS]; // VSR: the caps for the saved local ammo.
		float EngageRange; // Engage Range.
		float CloakChance[NUM_CMD]; // Chacnes to Cloak, per AI Command.
		Vector CurrentWhere; // VSR: the current command's position, for commands that have one.
		bool BlockDeploy; // VSR: out of cloak energy; the toggle is refused until it refills.
		long CloakMaxEnergy; // VSR: MaxCloakEnergy.
		long CloakCurEnergy;
		long CloakCostEnergy; // VSR: CloakEnergyCost per second while cloaked.
		long CloakAddEnergy; // VSR: AddCloakEnergy per second while decloaked.
		float CloakCurEnergyRemainder; // Sub-unit carry between ticks.

		MorphObjectClass() { memset(this, 0, sizeof(MorphObjectClass)); };

		// GBD: member-by-member compare for PostLoad's resync report; the first difference is logged and ends the compare. MaxLocalAmmo is not compared (shipped).
		friend bool operator==(const MorphObjectClass &a, const MorphObjectClass &b)
		{
			if (a.MorphObject != b.MorphObject)
			{
				char ODFNameA[MAX_ODF_LENGTH] = { 0 };
				char ODFNameB[MAX_ODF_LENGTH] = { 0 };
				GetODFName(a.MorphObject, ODFNameA);
				GetODFName(b.MorphObject, ODFNameB);
				FormatLogMessage("MORPHOBJECTCLASS MISMATCH: MorphObject: %08x '%s' and %08x '%s'", a.MorphObject, ODFNameA, b.MorphObject, ODFNameB);
				return false;
			}
			if (a.CurrentWho != b.CurrentWho)
			{
				char ODFNameA[MAX_ODF_LENGTH] = { 0 };
				char ODFNameB[MAX_ODF_LENGTH] = { 0 };
				GetODFName(a.CurrentWho, ODFNameA);
				GetODFName(b.CurrentWho, ODFNameB);
				FormatLogMessage("MORPHOBJECTCLASS MISMATCH: CurrentWho: %08x '%s' and %08x '%s'", a.CurrentWho, ODFNameA, b.CurrentWho, ODFNameB);
				return false;
			}
			if (a.WeaponActive != b.WeaponActive)
			{
				FormatLogMessage("MORPHOBJECTCLASS MISMATCH: WeaponActive: %d and %d", a.WeaponActive, b.WeaponActive);
				return false;
			}
			if (a.ObjectSwitch != b.ObjectSwitch)
			{
				FormatLogMessage("MORPHOBJECTCLASS MISMATCH: ObjectSwitch: %d and %d", a.ObjectSwitch, b.ObjectSwitch);
				return false;
			}
			if (a.CanFire != b.CanFire)
			{
				FormatLogMessage("MORPHOBJECTCLASS MISMATCH: CanFire: %d and %d", a.CanFire, b.CanFire);
				return false;
			}
			if (a.IsCloaker != b.IsCloaker)
			{
				FormatLogMessage("MORPHOBJECTCLASS MISMATCH: IsCloaker: %d and %d", a.IsCloaker, b.IsCloaker);
				return false;
			}
			if (a.IdleTime != b.IdleTime)
			{
				FormatLogMessage("MORPHOBJECTCLASS MISMATCH: IdleTime: %d and %d", a.IdleTime, b.IdleTime);
				return false;
			}
			if (a.NormalAmmo != b.NormalAmmo)
			{
				FormatLogMessage("MORPHOBJECTCLASS MISMATCH: NormalAmmo: %d and %d", a.NormalAmmo, b.NormalAmmo);
				return false;
			}
			if (a.MaxAmmo != b.MaxAmmo)
			{
				FormatLogMessage("MORPHOBJECTCLASS MISMATCH: MaxAmmo: %d and %d", a.MaxAmmo, b.MaxAmmo);
				return false;
			}
			if (a.Command != b.Command)
			{
				FormatLogMessage("MORPHOBJECTCLASS MISMATCH: Command: %d and %d", a.Command, b.Command);
				return false;
			}
			if (a.PTeam != b.PTeam)
			{
				FormatLogMessage("MORPHOBJECTCLASS MISMATCH: PTeam: %d and %d", a.PTeam, b.PTeam);
				return false;
			}
			for (int i = 0; i < MAX_HARDPOINTS; i++)
			{
				if (a.LocalAmmo[i] != b.LocalAmmo[i])
				{
					FormatLogMessage("MORPHOBJECTCLASS MISMATCH: LocalAmmo%d: %f and %f", i, a.LocalAmmo[i], b.LocalAmmo[i]);
					return false;
				}
			}
			if (a.EngageRange != b.EngageRange)
			{
				FormatLogMessage("MORPHOBJECTCLASS MISMATCH: EngageRange: %f and %f", a.EngageRange, b.EngageRange);
				return false;
			}
			for (int i = 0; i < NUM_CMD; i++)
			{
				if (a.CloakChance[i] != b.CloakChance[i])
				{
					FormatLogMessage("MORPHOBJECTCLASS MISMATCH: CloakChance%d: %f and %f", i, a.CloakChance[i], b.CloakChance[i]);
					return false;
				}
			}
			if ((a.CurrentWhere.x != b.CurrentWhere.x) || (a.CurrentWhere.y != b.CurrentWhere.y) || (a.CurrentWhere.z != b.CurrentWhere.z))
			{
				FormatLogMessage("MORPHOBJECTCLASS MISMATCH: CurrentWhere: %f %f %f and %f %f %f", a.CurrentWhere.x, a.CurrentWhere.y, a.CurrentWhere.z, b.CurrentWhere.x, b.CurrentWhere.y, b.CurrentWhere.z);
				return false;
			}
			if (a.BlockDeploy != b.BlockDeploy)
			{
				FormatLogMessage("MORPHOBJECTCLASS MISMATCH: BlockDeploy: %d and %d", a.BlockDeploy, b.BlockDeploy);
				return false;
			}
			if (a.CloakMaxEnergy != b.CloakMaxEnergy)
			{
				FormatLogMessage("MORPHOBJECTCLASS MISMATCH: CloakMaxEnergy: %d and %d", a.CloakMaxEnergy, b.CloakMaxEnergy);
				return false;
			}
			if (a.CloakCurEnergy != b.CloakCurEnergy)
			{
				FormatLogMessage("MORPHOBJECTCLASS MISMATCH: CloakCurEnergy: %d and %d", a.CloakCurEnergy, b.CloakCurEnergy);
				return false;
			}
			if (a.CloakCostEnergy != b.CloakCostEnergy)
			{
				FormatLogMessage("MORPHOBJECTCLASS MISMATCH: CloakCostEnergy: %d and %d", a.CloakCostEnergy, b.CloakCostEnergy);
				return false;
			}
			if (a.CloakAddEnergy != b.CloakAddEnergy)
			{
				FormatLogMessage("MORPHOBJECTCLASS MISMATCH: CloakAddEnergy: %d and %d", a.CloakAddEnergy, b.CloakAddEnergy);
				return false;
			}
			if (a.CloakCurEnergyRemainder != b.CloakCurEnergyRemainder)
			{
				FormatLogMessage("MORPHOBJECTCLASS MISMATCH: CloakCurEnergyRemainder: %f and %f", a.CloakCurEnergyRemainder, b.CloakCurEnergyRemainder);
				return false;
			}
			return true;
		}
	};

private:

	static MorphObjectHelper *m_MorphObjectHelper;

	// The morph object list.
	std::vector<MorphObjectClass> MorphObjectList;

	static bool ShouldRemoveMorphObject(const MorphObjectClass &entry) { return !IsAround(entry.MorphObject); }

public:
	MorphObjectHelper();
	virtual ~MorphObjectHelper();
	static MorphObjectHelper &Get() { return *m_MorphObjectHelper; }

	int GetNumMorphObjects() { return int(MorphObjectList.size()); }
	Handle &RefMorphObjectHandle(const int Index) { return MorphObjectList[Index].MorphObject; }
	bool GetMorphObjectCloaker(const int Index) { return MorphObjectList[Index].IsCloaker; }
	bool GetMorphObjectIsActive(const int Index) { return MorphObjectList[Index].WeaponActive; }

	// In BZ1Helper, if morph object.
	void AddMorphObjectHostObject(const Handle h, const char* TempODF1, const char* TempODF2);
	// Toggle activators for the replacement of the walker object.
	void AddMorphObjectToggleObject(const Handle h);

	bool Load(bool missionSave);
	bool PostLoad(bool missionSave);
	bool Save(bool missionSave);

	void Execute(BZ1Helper &bz1Helper);

	// VSR: an active, non-firing morph object with full stored ammo refuses reload pods.
	virtual PrePickupPowerupReturnCodes PrePickupPowerup(const int curWorld, Handle me, Handle powerupHandle, const int ObjClassHash, const char* PowerupODF);

private:
	// Gets the first "morphobjecttoggle" weapon in a unit.
	void GetSwitchMineODF(const Handle h, char *Value);
};

#define VSR_LAYOUT_CHECK_MorphObjectHelper
#include "vsr_layout_asserts.h"
#undef VSR_LAYOUT_CHECK_MorphObjectHelper

#endif // _morphobjecthelper_
