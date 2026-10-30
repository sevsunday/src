// PROVENANCE: ancestor reference/ancestor-bz1helper-2015/Shared/CarrierHelper.h @6fda4f5 (field comments; the IsActive / IsReturning / IsDefending flags became DroneState) | declarations original/missions/Strategy02.pdb via tools/pdb_types.py; the two operator==s from reference/decompiled/strategy02-ghidra12.2/src/missions/vsrcore/carrierhelper.h.decomp.c (lines 43-107, 127-187) | status: ported
#ifndef _carrierhelper_
#define _carrierhelper_

#include "ScriptUtils.h"
#include <vector>

class BZ1Helper;

// VSR: a drone's life under its carrier.
enum DroneStates
{
	DroneState_Inactive = 0, // No carrier in control; shut down.
	DroneState_Idle = 1, // Following its carrier, counting down to a recall.
	DroneState_Attacking = 2, // On a target of its own (or the carrier's).
	DroneState_Defending = 3, // Defending its carrier.
};

// This code handles Carrier ships and the drones they launch: control / repair / defend / recall ranges, the drone state machine, and packing drones back into the carrier's ammo.
class CarrierHelper
{
	friend struct VsrLayoutCheck_CarrierHelper; // scaffold: QA gate 2 hook (layout asserts); not GBD's
public:
	struct CarrierClass
	{
		friend struct VsrLayoutCheck_CarrierHelper__CarrierClass; // scaffold: QA gate 2 hook (layout asserts); not GBD's
		Handle CarrierObject; // This Carrier Object.
		float DroneControlRange; // How far can this Carrier control it's drones from? 0 = Unlimited.
		float DroneRepairRange; // How far to repair drones?
		float DroneDefendRange; // VSR: how far out an enemy puts idle drones on defense.
		float DroneRecallRange; // VSR: how close a recalled drone must get to be packed up.
		float DroneIdleTime; // VSR: seconds an idle drone waits before it is recalled.
		int MaxDrones; // This carrier's max drones. 0 = Unlimited.
		int CurDrones; // How many drones it currently has control over.
		int MinAttackForce; // VSR: drones wait for this many under control before taking the carrier's target.
		long HealthRepairAmount; // How much health to repair?
		long AmmoRepairAmount; // How much ammo to repair?
		bool ServiceAllies; // VSR: repair other carriers' drones too.

		CarrierClass() { memset(this, 0, sizeof(CarrierClass)); };

		// GBD: member-by-member compare for PostLoad's resync report; the first difference is logged and ends the compare. DroneIdleTime and MinAttackForce are not compared (shipped).
		friend bool operator==(const CarrierClass &a, const CarrierClass &b)
		{
			if (a.CarrierObject != b.CarrierObject)
			{
				char ODFNameA[MAX_ODF_LENGTH] = { 0 };
				char ODFNameB[MAX_ODF_LENGTH] = { 0 };
				GetODFName(a.CarrierObject, ODFNameA);
				GetODFName(b.CarrierObject, ODFNameB);
				FormatLogMessage("CARRIERCLASS MISMATCH: CarrierObject: %08x '%s' and %08x '%s'", a.CarrierObject, ODFNameA, b.CarrierObject, ODFNameB);
				return false;
			}
			if (a.DroneControlRange != b.DroneControlRange)
			{
				FormatLogMessage("CARRIERCLASS MISMATCH: DroneControlRange: %f and %f", a.DroneControlRange, b.DroneControlRange);
				return false;
			}
			if (a.DroneRepairRange != b.DroneRepairRange)
			{
				FormatLogMessage("CARRIERCLASS MISMATCH: DroneRepairRange: %f and %f", a.DroneRepairRange, b.DroneRepairRange);
				return false;
			}
			if (a.DroneDefendRange != b.DroneDefendRange)
			{
				FormatLogMessage("CARRIERCLASS MISMATCH: DroneDefendRange: %f and %f", a.DroneDefendRange, b.DroneDefendRange);
				return false;
			}
			if (a.DroneRecallRange != b.DroneRecallRange)
			{
				FormatLogMessage("CARRIERCLASS MISMATCH: DroneRecallRange: %f and %f", a.DroneRecallRange, b.DroneRecallRange);
				return false;
			}
			if (a.MaxDrones != b.MaxDrones)
			{
				FormatLogMessage("CARRIERCLASS MISMATCH: MaxDrones: %d and %d", a.MaxDrones, b.MaxDrones);
				return false;
			}
			if (a.CurDrones != b.CurDrones)
			{
				FormatLogMessage("CARRIERCLASS MISMATCH: CurDrones: %d and %d", a.CurDrones, b.CurDrones);
				return false;
			}
			if (a.HealthRepairAmount != b.HealthRepairAmount)
			{
				FormatLogMessage("CARRIERCLASS MISMATCH: HealthRepairAmount: %d and %d", a.HealthRepairAmount, b.HealthRepairAmount);
				return false;
			}
			if (a.AmmoRepairAmount != b.AmmoRepairAmount)
			{
				FormatLogMessage("CARRIERCLASS MISMATCH: AmmoRepairAmount: %d and %d", a.AmmoRepairAmount, b.AmmoRepairAmount);
				return false;
			}
			if (a.ServiceAllies != b.ServiceAllies)
			{
				FormatLogMessage("CARRIERCLASS MISMATCH: ServiceAllies: %d and %d", a.ServiceAllies, b.ServiceAllies);
				return false;
			}
			return true;
		}
	};

	struct DroneClass
	{
		friend struct VsrLayoutCheck_CarrierHelper__DroneClass; // scaffold: QA gate 2 hook (layout asserts); not GBD's
		Handle DroneObject; // This Drone Object.
		Handle DroneTarget; // This drone's current Target.
		int CarrierIndex; // VSR: index of its carrier in CarrierList.
		int DroneState; // VSR: DroneStates.
		int IdleTimer; // VSR: turns left idling before a recall.
		int CarrierWeaponSlot; // Which weapon slot this ship came out of.
		bool UseLocalAmmo; // Flag for if this Drone's Carrier's weapon uses local ammo or not.
		bool canSwitchCarrier; // VSR: may an inactive drone be picked up by another carrier?
		float RandomTargetDist; // VSR: DroneClass RandomTargetRange; picks a random object this close to the carrier's target instead of the target itself.
		Vector Position; // It's current position.

		DroneClass() { memset(this, 0, sizeof(DroneClass)); };

		// GBD: member-by-member compare for PostLoad's resync report; the first difference is logged and ends the compare.
		// The shipped order is DroneObject, DroneTarget, UseLocalAmmo, DroneState, CarrierIndex, CarrierWeaponSlot, RandomTargetDist, Position (IdleTimer / canSwitchCarrier are not compared).
		friend bool operator==(const DroneClass &a, const DroneClass &b)
		{
			if (a.DroneObject != b.DroneObject)
			{
				char ODFNameA[MAX_ODF_LENGTH] = { 0 };
				char ODFNameB[MAX_ODF_LENGTH] = { 0 };
				GetODFName(a.DroneObject, ODFNameA);
				GetODFName(b.DroneObject, ODFNameB);
				FormatLogMessage("DRONECLASS MISMATCH: DroneObject: %08x '%s' and %08x '%s'", a.DroneObject, ODFNameA, b.DroneObject, ODFNameB);
				return false;
			}
			if (a.DroneTarget != b.DroneTarget)
			{
				char ODFNameA[MAX_ODF_LENGTH] = { 0 };
				char ODFNameB[MAX_ODF_LENGTH] = { 0 };
				GetODFName(a.DroneTarget, ODFNameA);
				GetODFName(b.DroneTarget, ODFNameB);
				FormatLogMessage("DRONECLASS MISMATCH: DroneTarget: %08x '%s' and %08x '%s'", a.DroneTarget, ODFNameA, b.DroneTarget, ODFNameB);
				return false;
			}
			if (a.UseLocalAmmo != b.UseLocalAmmo)
			{
				FormatLogMessage("DRONECLASS MISMATCH: UseLocalAmmo: %d and %d", a.UseLocalAmmo, b.UseLocalAmmo);
				return false;
			}
			if (a.DroneState != b.DroneState)
			{
				FormatLogMessage("DRONECLASS MISMATCH: DroneState: %d and %d", a.DroneState, b.DroneState);
				return false;
			}
			if (a.CarrierIndex != b.CarrierIndex)
			{
				FormatLogMessage("DRONECLASS MISMATCH: CarrierIndex: %d and %d", a.CarrierIndex, b.CarrierIndex);
				return false;
			}
			if (a.CarrierWeaponSlot != b.CarrierWeaponSlot)
			{
				FormatLogMessage("DRONECLASS MISMATCH: CarrierWeaponSlot: %d and %d", a.CarrierWeaponSlot, b.CarrierWeaponSlot);
				return false;
			}
			if (a.RandomTargetDist != b.RandomTargetDist)
			{
				FormatLogMessage("DRONECLASS MISMATCH: RandomTargetDist: %f and %f", a.RandomTargetDist, b.RandomTargetDist);
				return false;
			}
			if ((a.Position.x != b.Position.x) || (a.Position.y != b.Position.y) || (a.Position.z != b.Position.z))
			{
				FormatLogMessage("DRONECLASS MISMATCH: Position: %f %f %f and %f %f %f", a.Position.x, a.Position.y, a.Position.z, b.Position.x, b.Position.y, b.Position.z);
				return false;
			}
			return true;
		}
	};

private:

	// The carrier and drone lists.
	std::vector<CarrierClass> CarrierList;
	std::vector<DroneClass> DroneList;

	static bool ShouldRemoveCarrier(const CarrierClass &entry) { return !IsAround(entry.CarrierObject); }
	static bool ShouldRemoveDrone(const DroneClass &entry) { return !IsAround(entry.DroneObject); }

	// VSR: the drone state machine. index is into DroneList, carrierindex into CarrierList.
	Handle DroneFindTarget(BZ1Helper &bz1Helper, int index, int UnusedArg); // The target this drone should go for: its own while alive, else its carrier's (randomized within RandomTargetDist), only once MinAttackForce drones are up.
	bool DroneRecall(int index); // Packs the drone back into the carrier's ammo once within DroneRecallRange. True when it was removed.
	void DroneActivate(int index, int carrierindex);
	void DroneDeactivate(int index, bool resize); // resize: also give the carrier its slot back.
	void DroneIdle(int index);
	void DroneAttack(int index, Handle target, int team);
	void DroneDefend(int index);

public:
	CarrierHelper();
	virtual ~CarrierHelper();

	virtual void PreOrdnanceHit(Handle shooterHandle, Handle victimHandle, int ordnanceTeam, const char* pOrdnanceODF);

	// ODFName is the drone's own ODF, matched against the carrier's dispenser weapons to find which slot it came out of.
	void AddCarrierDroneObject(const Handle h, const int Team, const char* TempODF1, const char* TempODF2, const char* ODFName);
	void AddCarrierObject(const Handle h, const char* TempODF1, const char* TempODF2);

	bool Load(bool missionSave);
	bool PostLoad(bool missionSave);
	bool Save(bool missionSave);

	void Execute(BZ1Helper &bz1Helper);
};

#define VSR_LAYOUT_CHECK_CarrierHelper
#include "vsr_layout_asserts.h"
#undef VSR_LAYOUT_CHECK_CarrierHelper

#endif // _carrierhelper_
