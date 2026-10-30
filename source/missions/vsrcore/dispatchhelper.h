// PROVENANCE: ancestor reference/ancestor-bz1helper-2015/Shared/DispatchHelper.h @6fda4f5 (field comments and the public-member doc) | declarations original/missions/Strategy02.pdb via tools/pdb_types.py; operator== from reference/decompiled/strategy02-ghidra12.2/src/missions/vsrcore/dispatchhelper.h.decomp.c | status: ported
#ifndef _dispatchhelper_
#define _dispatchhelper_

#include "ScriptUtils.h"
#include <vector>

class BZ1Helper;

// Dispatch States.
enum DispatchState
{
	DispatchState_Idle = 0,
	DispatchState_Goto = 1,
	DispatchState_Flee = 2,
	DispatchState_Reload = 3,
	DispatchState_Repair = 4,
};

// Dispatch Types.
enum DispatchType
{
	DispatchType_None = 0,
	DispatchType_Turret = 1,
	DispatchType_Patrol = 2,
	DispatchType_Minelayer = 3,
	DispatchType_Hunter = 4,
	DispatchType_Escort = 5,
	DispatchType_Howitzer = 6, // Only influences how these ships get Reload/Repair atm.
};

// The CPU commander's unit AI: turrets pick a guard / scrap / siege spot, patrols and minelayers walk their paths, hunters hunt, escorts guard the
// utility ships; units flee a bad strafe, go for repair / reload (or get a pod dropped on them), and cloakers cloak and decloak on their own.
class DispatchHelper
{
	friend struct VsrLayoutCheck_DispatchHelper; // scaffold: QA gate 2 hook (layout asserts); not GBD's
public:
	struct DispatchClass
	{
		friend struct VsrLayoutCheck_DispatchHelper__DispatchClass; // scaffold: QA gate 2 hook (layout asserts); not GBD's
		Handle DispatchObject; // This Dispatch Object.
		Handle DispatchTarget; // Handle its Targeting.
		Handle FleeTarget; // Fleeing unit's Target.
		Vector DispatchSpot; // Saved vector for it's designated location.
		int CurrTeam; // VSR: the team it was counted on; a team change moves the Patrol / Hunt / Escort counters.
		int DispatchType; // DispatchType.
		int DispatchState; // DispatchState.
		bool SkipAIPCheck; // Does this unit work even without an AIP running?
		bool IsCloaker; // Is it a Cloaker?
		bool IsMorpher; // Is it a Morpher?
		bool CanFlee; // can this unit flee?
		bool CanGetReload; // Can this unit go get ammo on it's own?
		bool CanGetRepair; // Can this unit get repairs on its own?
		bool MorphIsAssault; // Does morph switch to attack IsAssault units?
		bool IsCloaked; // Is it cloaked?
		bool CloakLocked; // Is the cloak locked?
		bool CloakNextTick; // Flag to cloak this unit next execute, reguardless of AIP/auto cloaking.
		bool DecloakNextTick; // Flag to decloak this unit next execute, reguardless of AIP/auto cloaking.
		int IdleTime; // Idle time to wait before dispatching.
		int CloakIdleTime; // Idle time for cloaking.
		int DeployTimer; // Timer for seeing if this unit is finished deploying. m_TurnCounter+TimeDeploy.
		int ServiceTimer; // VSR: turns until the next service check (10 s cycle).
		float RandomDist; // Random distance to stop from.
		float EngageRange; // This unit's EngageRange, to see if enemies are nearby.
		float TimeDeploy; // Time to Deploy, used for calculating cloak timing.
		float CloakChance[NUM_CMD]; // Cloak Chances, per AI Command.
		float FleeHealthRatio; // Flee Health Lost Ratio.
		float GetRepairRatio; // Ratio at which it goes to get repair.
		float ServiceChance; // % Chance this unit will service.
		long MinFireAmmo; // Minimum ammo needed to fire it's current weapons.
		long MaxHealth; // VSR: stored when added.
		long MaxAmmo;
		int Command; // What its current command is.
		int FleeHealthValue; // Health value since last Flee exited.
		int CloakPriority; // Priority for Cloaking/Hunting.

		DispatchClass() { memset(this, 0, sizeof(DispatchClass)); };

		// GBD: member-by-member compare for PostLoad's resync report; the first difference is logged and ends the compare.
		friend bool operator==(const DispatchClass &a, const DispatchClass &b)
		{
#define VSR_DISPATCH_HANDLE(field) if (a.field != b.field) { char ODFNameA[MAX_ODF_LENGTH] = { 0 }; char ODFNameB[MAX_ODF_LENGTH] = { 0 }; GetODFName(a.field, ODFNameA); GetODFName(b.field, ODFNameB); FormatLogMessage("DISPATCHCLASS MISMATCH: " #field ": %08x '%s' and %08x '%s'", a.field, ODFNameA, b.field, ODFNameB); return false; }
#define VSR_DISPATCH_INT(field) if (a.field != b.field) { FormatLogMessage("DISPATCHCLASS MISMATCH: " #field ": %d and %d", a.field, b.field); return false; }
#define VSR_DISPATCH_FLOAT(field) if (a.field != b.field) { FormatLogMessage("DISPATCHCLASS MISMATCH: " #field ": %f and %f", a.field, b.field); return false; }
			VSR_DISPATCH_HANDLE(DispatchObject)
			VSR_DISPATCH_HANDLE(DispatchTarget)
			VSR_DISPATCH_HANDLE(FleeTarget)
			if ((a.DispatchSpot.x != b.DispatchSpot.x) || (a.DispatchSpot.y != b.DispatchSpot.y) || (a.DispatchSpot.z != b.DispatchSpot.z))
			{
				FormatLogMessage("DISPATCHCLASS MISMATCH: DispatchSpot: %f %f %f and %f %f %f", a.DispatchSpot.x, a.DispatchSpot.y, a.DispatchSpot.z, b.DispatchSpot.x, b.DispatchSpot.y, b.DispatchSpot.z);
				return false;
			}
			VSR_DISPATCH_INT(CurrTeam)
			VSR_DISPATCH_INT(DispatchType)
			VSR_DISPATCH_INT(DispatchState)
			VSR_DISPATCH_INT(SkipAIPCheck)
			VSR_DISPATCH_INT(IsCloaker)
			VSR_DISPATCH_INT(IsMorpher)
			VSR_DISPATCH_INT(CanFlee)
			VSR_DISPATCH_INT(CanGetReload)
			VSR_DISPATCH_INT(CanGetRepair)
			VSR_DISPATCH_INT(MorphIsAssault)
			VSR_DISPATCH_INT(IsCloaked)
			VSR_DISPATCH_INT(CloakLocked)
			VSR_DISPATCH_INT(CloakNextTick)
			VSR_DISPATCH_INT(DecloakNextTick)
			VSR_DISPATCH_INT(IdleTime)
			VSR_DISPATCH_INT(CloakIdleTime)
			VSR_DISPATCH_INT(DeployTimer)
			VSR_DISPATCH_INT(ServiceTimer)
			VSR_DISPATCH_FLOAT(RandomDist)
			VSR_DISPATCH_FLOAT(EngageRange)
			VSR_DISPATCH_FLOAT(TimeDeploy)
			for (int i = 0; i < NUM_CMD; i++)
			{
				if (a.CloakChance[i] != b.CloakChance[i])
				{
					FormatLogMessage("DISPATCHCLASS MISMATCH: CloakChance%d: %f and %f", i, a.CloakChance[i], b.CloakChance[i]);
					return false;
				}
			}
			VSR_DISPATCH_FLOAT(FleeHealthRatio)
			VSR_DISPATCH_FLOAT(GetRepairRatio)
			VSR_DISPATCH_FLOAT(ServiceChance)
			VSR_DISPATCH_INT(MinFireAmmo)
			VSR_DISPATCH_INT(MaxHealth)
			VSR_DISPATCH_INT(MaxAmmo)
			VSR_DISPATCH_INT(Command)
			VSR_DISPATCH_INT(FleeHealthValue)
			VSR_DISPATCH_INT(CloakPriority)
#undef VSR_DISPATCH_HANDLE
#undef VSR_DISPATCH_INT
#undef VSR_DISPATCH_FLOAT
			return true;
		}
	};

private:

	static DispatchHelper *m_DispatchHelper;

	// The dispatch list.
	std::vector<DispatchClass> DispatchList;

	static bool ShouldRemoveDispatch(const DispatchClass &entry) { return !IsAround(entry.DispatchObject); }

public:
	DispatchHelper();
	virtual ~DispatchHelper();
	static DispatchHelper &Get() { return *m_DispatchHelper; }

	// If Priority is 1, it doesn't let DispatchHelper control cloaking.
	bool AddToDispatch(const Handle h, const float IdleTime, const bool SkipAIPCheck = false, const int CloakPriority = 0, const bool CanFlee = true, const bool CloakNow = false, const bool Hunt = false, const bool CanGetService = false);
	void Cloak(const Handle h, const int Priority = 0); // Adds a unit to dispatch if not present, otherwise cloaks it.
	void Decloak(const Handle h, const int UnusedArg = 0); // Decloaks a unit if its already in dispatch. (The PDB's second parameter is never read.)
	bool IsCloaked(const Handle h);
	void DLLHunt(const Handle h, const int Priority); // DLL driven Hunt command.
	void DLLPatrol(const Handle h, const int Priority); // DLL driven Patrol command.
	void SetUseService(const Handle h, const bool Service = true); // DLL switch to set a unit's UseService status.

	// Reads block.<every AI command name> into value[] (NUM_CMD floats), defval where missing.
	void ReadChanceValues(const char* const file, const char* const block, float* value, const float defval = 0.0f);

	virtual void PreOrdnanceHit(const Handle shooterHandle, const Handle victimHandle, const int ordnanceTeam, const char* pOrdnanceODF);

	bool Load(bool missionSave);
	bool PostLoad(bool missionSave);
	bool Save(bool missionSave);

	void DeleteDispatchObject(Handle h, int Team);
	void Execute(BZ1Helper &bz1Helper);

private:
	void ClearDispatch(const int Index);
};

#define VSR_LAYOUT_CHECK_DispatchHelper
#include "vsr_layout_asserts.h"
#undef VSR_LAYOUT_CHECK_DispatchHelper

#endif // _dispatchhelper_
