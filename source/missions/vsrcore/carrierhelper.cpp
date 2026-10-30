// PROVENANCE: ancestor reference/ancestor-bz1helper-2015/Shared/CarrierHelper.cpp @6fda4f5 (carrier / drone registration, repair, the 2015 flag-based drone control) | decompile reference/decompiled/strategy02-ghidra12.2/src/missions/vsrcore/carrierhelper.cpp.decomp.c (Load 20-44, PostLoad 47-86, Save 89-106, AddCarrierDroneObject 109-185, AddCarrierObject 188-223, Execute 226-475, PreOrdnanceHit 478-505, DroneFindTarget 511-562, DroneRecall 566-591, DroneActivate 595-600, DroneDeactivate 604-612, DroneIdle 616-622, DroneAttack 626-637; DroneDefend inlined into Execute) + dumpbin of 4fc18f3b for the GetRandomObject arguments | status: ported
#include "bz1helper.h"
#include "carrierhelper.h"
#include "bzcscriptutils.h"
#include <algorithm>

std::vector<CarrierHelper::CarrierClass> TempCarrierBuffer; // GBD: the lists as they stood before a Load, for PostLoad's resync report.
std::vector<CarrierHelper::DroneClass> TempDroneBuffer;

CarrierHelper::CarrierHelper()
{
}
CarrierHelper::~CarrierHelper()
{
}

bool CarrierHelper::Load(bool missionSave)
{
	if (!missionSave)
	{
		TempCarrierBuffer = CarrierList;
		TempDroneBuffer = DroneList;

		int size = 0;
		bool ret = Read(&size, 1);
		CarrierList.resize(size);
		if(size)
			ret = ret && Read(&CarrierList.front(), sizeof(CarrierClass)*size);

		size = 0;
		ret = ret && Read(&size, 1);
		DroneList.resize(size);
		if(size)
			ret = ret && Read(&DroneList.front(), sizeof(DroneClass)*size);
		return ret;
	}
	return true;
}

bool CarrierHelper::PostLoad(bool missionSave)
{
	if (!missionSave)
	{
		for (std::vector<CarrierClass>::iterator iter = CarrierList.begin(); iter != CarrierList.end(); ++iter)
		{
			CarrierClass &sao = *iter;
			ConvertHandles(&sao.CarrierObject, 1);
		}

		for (std::vector<DroneClass>::iterator iter = DroneList.begin(); iter != DroneList.end(); ++iter)
		{
			DroneClass &sao = *iter;
			ConvertHandles(&sao.DroneObject, 1);
			ConvertHandles(&sao.DroneTarget, 1);
		}

		// GBD: resync report — compare what we had against what we loaded.
		if (TempCarrierBuffer.size() == CarrierList.size())
		{
			for (int i = 0; i < int(CarrierList.size()); i++)
			{
				if (!(TempCarrierBuffer[i] == CarrierList[i]))
				{
					FormatLogMessage("CarrierList Index Mismatch: %d", i);
					break;
				}
			}
		}
		else
		{
			FormatLogMessage("CarrierList Size Mismatch! Old: %d New: %d", TempCarrierBuffer.size(), CarrierList.size());
		}

		if (TempDroneBuffer.size() == DroneList.size())
		{
			for (int i = 0; i < int(DroneList.size()); i++)
			{
				if (!(TempDroneBuffer[i] == DroneList[i]))
				{
					FormatLogMessage("DroneList Index Mismatch: %d", i);
					break;
				}
			}
		}
		else
		{
			FormatLogMessage("DroneList Size Mismatch! Old: %d New: %d", TempDroneBuffer.size(), DroneList.size());
		}
	}
	return true;
}

bool CarrierHelper::Save(bool missionSave)
{
	if (!missionSave)
	{
		int size = int(CarrierList.size());
		bool ret = Write(&size, 1);
		if(size)
			ret = ret && Write(&CarrierList.front(), sizeof(CarrierClass)*size);

		size = int(DroneList.size());
		ret = ret && Write(&size, 1);
		if(size)
			ret = ret && Write(&DroneList.front(), sizeof(DroneClass)*size);
		return ret;
	}
	return true;
}

void CarrierHelper::AddCarrierDroneObject(const Handle h, const int Team, const char* TempODF1, const char* TempODF2, const char* ODFName)
{
	for (std::vector<DroneClass>::iterator iter = DroneList.begin(); iter != DroneList.end(); ++iter)
	{
		if(iter->DroneObject == h)
			return;
	}

	DroneList.resize(DroneList.size()+1);
	const int DroneIndex = int(DroneList.size())-1;
	DroneClass &sao = DroneList[DroneIndex]; // No temporary being created, *much* faster
	memset(&sao, 0, sizeof(DroneClass)); // Zero things out at start.

	// Find which carrier launched this drone.
	float BestDistanceSquared = FLT_MAX;
	int CarrierIndex = -1;
	for (std::vector<CarrierClass>::iterator iter = CarrierList.begin(); iter != CarrierList.end(); ++iter)
	{
		float DistanceSquared = GetDistance3DSquared(GetPosition(iter->CarrierObject), GetPosition(h));
		if((DistanceSquared < BestDistanceSquared) && (h != iter->CarrierObject) && (GetTeamNum(iter->CarrierObject) == Team))
		{
			CarrierIndex = int(iter-CarrierList.begin());
			BestDistanceSquared = DistanceSquared;
		}
	}

	sao.DroneObject = h;

	// We have a winner? This Drone is close enough to be considered come from an Carrier.
	bool Activated = false;
	if (CarrierIndex >= 0)
	{
		const CarrierClass &carrier = CarrierList[CarrierIndex];
		if( ((carrier.DroneControlRange == 0.0f) || (BestDistanceSquared < carrier.DroneControlRange)) && // Infinite Range, or it's within control range. (sic: squared distance against the plain range, as the ancestor.)
			((carrier.MaxDrones == 0) || (carrier.CurDrones < carrier.MaxDrones))) // Max Drones is infinite, or less then max drones.
		{
			Activated = true;
			DroneActivate(DroneIndex, CarrierIndex);

			// Read ODFs to find which WeaponSlot this Drone came out of.
			if (ODFName)
			{
				for(int i = 0; i < MAX_HARDPOINTS; i++)
				{
					char WeaponODF[MAX_ODF_LENGTH] = {0};
					GetObjInfo(carrier.CarrierObject, ObjectInfoType(Get_Weapon0ODF+i), WeaponODF);

					char DispenserName[MAX_ODF_LENGTH] = {0};
					if((OpenODF2(WeaponODF)) &&
						(GetODFString(WeaponODF, "DispenserClass", "objectClass", MAX_ODF_LENGTH, DispenserName)) &&
						(_stricmp(ODFName, DispenserName) == 0)) // We found a match.
					{
						int TempLocalAmmo = 0;
						sao.CarrierWeaponSlot = i;
						GetODFInt(WeaponODF, "WeaponClass", "localAmmo", &TempLocalAmmo, 0);
						if(TempLocalAmmo > 0)
							sao.UseLocalAmmo = true;

						break;
					}
				}
			}
		}
	}
	if (!Activated)
		DroneDeactivate(DroneIndex, false); // Shut down.

	GetODFFloat(TempODF1, TempODF2, "DroneClass", "RandomTargetRange", &sao.RandomTargetDist, 0.0f);
	GetODFBool(TempODF1, TempODF2, "DroneClass", "canSwitchCarrier", &sao.canSwitchCarrier, true);
}

void CarrierHelper::AddCarrierObject(const Handle h, const char* TempODF1, const char* TempODF2)
{
	for (std::vector<CarrierClass>::iterator iter = CarrierList.begin(); iter != CarrierList.end(); ++iter)
	{
		if(iter->CarrierObject == h)
			return;
	}

	CarrierList.resize(CarrierList.size()+1);
	CarrierClass &sao = CarrierList[CarrierList.size()-1]; // No temporary being created, *much* faster
	memset(&sao, 0, sizeof(CarrierClass)); // Zero things out at start.

	// Look for new ODF Parameters.
	GetODFFloat(TempODF1, TempODF2, "CarrierClass", "controlRange", &sao.DroneControlRange, 0.0f);
	GetODFFloat(TempODF1, TempODF2, "CarrierClass", "defendRange", &sao.DroneDefendRange, sao.DroneControlRange);
	GetODFFloat(TempODF1, TempODF2, "CarrierClass", "recallRange", &sao.DroneRecallRange, 50.0f);
	GetODFFloat(TempODF1, TempODF2, "CarrierClass", "droneIdleTime", &sao.DroneIdleTime, 120.0f);
	GetODFInt(TempODF1, TempODF2, "CarrierClass", "maxDrones", &sao.MaxDrones, 0);
	GetODFInt(TempODF1, TempODF2, "CarrierClass", "minAttackForce", &sao.MinAttackForce, 0);
	if (sao.MaxDrones == 0)
	{
		if (sao.MinAttackForce < 0)
			sao.MinAttackForce = 0;
	}
	else
	{
		sao.MinAttackForce = clamp(sao.MinAttackForce, 0, sao.MaxDrones);
	}

	GetODFFloat(TempODF1, TempODF2, "CarrierClass", "repairRange", &sao.DroneRepairRange, 100.0f);
	GetODFLong(TempODF1, TempODF2, "CarrierClass", "healthRepairAmount", &sao.HealthRepairAmount, 0);
	GetODFLong(TempODF1, TempODF2, "CarrierClass", "ammoRepairAmount", &sao.AmmoRepairAmount, 0);
	GetODFBool(TempODF1, TempODF2, "CarrierClass", "serviceAllies", &sao.ServiceAllies, false);

	sao.CarrierObject = h;
}

void CarrierHelper::Execute(BZ1Helper &bz1Helper)
{
	const bool Logging = BZ1Helper::Logging;

	// pre-clean the vectors
	CarrierList.erase(std::remove_if(CarrierList.begin(), CarrierList.end(), ShouldRemoveCarrier), CarrierList.end());
	DroneList.erase(std::remove_if(DroneList.begin(), DroneList.end(), ShouldRemoveDrone), DroneList.end());

	// Loop over all Drones.
	for (int d = 0; d < int(DroneList.size()); d++)
	{
		DroneClass &drone = DroneList[d];
		const int Team = GetTeamNum(drone.DroneObject);
		drone.Position = GetPosition(drone.DroneObject);

		// If it's low on health or ammo, and nearby a Carrier that services it, repair it.
		if((NeedsHealth(drone.DroneObject)) || (NeedsAmmo(drone.DroneObject)))
		{
			for (int c = 0; c < int(CarrierList.size()); c++)
			{
				const CarrierClass &carrier = CarrierList[c];
				if(((carrier.ServiceAllies) || (c == drone.CarrierIndex)) && (carrier.DroneRepairRange != 0.0f) &&
					(GetDistance3DSquared(drone.Position, GetPosition(carrier.CarrierObject)) < Squared(carrier.DroneRepairRange))) // It's within repair range.
				{
					if(carrier.HealthRepairAmount)
						AddHealth(drone.DroneObject, (carrier.HealthRepairAmount / BZ1Helper::m_GameTPS));
					if(carrier.AmmoRepairAmount)
						AddAmmo(drone.DroneObject, (carrier.AmmoRepairAmount / BZ1Helper::m_GameTPS));
				}
			}
		}

		// A player in the drone flies it himself.
		if (IsPlayer(drone.DroneObject))
			continue;

		Handle Target = 0;
		Handle NearestEnemy = 0;
		if (drone.DroneState != DroneState_Inactive)
		{
			const CarrierClass &carrier = CarrierList[drone.CarrierIndex];
			// If this Drone's carrier is Dead, or it is outside of range, shut it down.
			if((!IsAround(carrier.CarrierObject)) &&
				((carrier.DroneControlRange == 0.0f) || (GetDistance3DSquared(drone.Position, GetPosition(carrier.CarrierObject)) > Squared(carrier.DroneControlRange))))
			{
				DroneDeactivate(d, true);
				if (Logging)
					FormatLogMessage("Drone %08x '%s' Set to DroneState: %d, Carrier Dead or Outside of Range", drone.DroneObject, GetODFName(drone.DroneObject), drone.DroneState);
			}
			else
			{
				Target = DroneFindTarget(bz1Helper, d, carrier.CarrierObject);
				NearestEnemy = bz1Helper.GetNearestObject(carrier.CarrierObject, carrier.DroneDefendRange, Team, TeamFilter_Enemies, true);
			}
		}

		switch (drone.DroneState)
		{
		case DroneState_Inactive: // No carriers around, look for a new one to come into range.
			if ((drone.canSwitchCarrier) || (IsAround(CarrierList[drone.CarrierIndex].CarrierObject)))
			{
				for (int c = 0; c < int(CarrierList.size()); c++)
				{
					const CarrierClass &carrier = CarrierList[c];
					if (GetTeamNum(carrier.CarrierObject) != Team) // Team matches.
						continue;
					if ((carrier.DroneControlRange != 0.0f) && (Squared(carrier.DroneControlRange) <= GetDistance3DSquared(drone.Position, GetPosition(carrier.CarrierObject)))) // It's within control range.
						continue;
					if ((carrier.MaxDrones == 0) || (carrier.CurDrones < carrier.MaxDrones)) // Less then max drones.
					{
						DroneActivate(d, c);
						if (Logging)
						{
							char DroneODF[MAX_ODF_LENGTH] = {0};
							char CarrierODF[MAX_ODF_LENGTH] = {0};
							GetODFName(drone.DroneObject, DroneODF);
							GetODFName(carrier.CarrierObject, CarrierODF);
							FormatLogMessage("Drone %08x '%s' INACTIVE: Set to DroneState: %d, Reassigned to Carrier: %08x '%s'", drone.DroneObject, DroneODF, drone.DroneState, carrier.CarrierObject, CarrierODF);
						}
						break;
					}
				}
			}
			break;

		case DroneState_Idle:
			if (Target)
			{
				DroneAttack(d, Target, Team);
				if (Logging)
				{
					char DroneODF[MAX_ODF_LENGTH] = {0};
					char TargetODF[MAX_ODF_LENGTH] = {0};
					char CarrierODF[MAX_ODF_LENGTH] = {0};
					GetODFName(drone.DroneObject, DroneODF);
					GetODFName(Target, TargetODF);
					GetODFName(CarrierList[drone.CarrierIndex].CarrierObject, CarrierODF);
					FormatLogMessage("Drone %08x '%s' IDLE: Set to DroneState %d, Target: %08x '%s', Carrier: %08x '%s'", drone.DroneObject, DroneODF, drone.DroneState, Target, TargetODF, CarrierList[drone.CarrierIndex].CarrierObject, CarrierODF);
				}
			}
			else if (NearestEnemy)
			{
				DroneDefend(d);
				if (Logging)
				{
					char DroneODF[MAX_ODF_LENGTH] = {0};
					char CarrierODF[MAX_ODF_LENGTH] = {0};
					GetODFName(drone.DroneObject, DroneODF);
					GetODFName(CarrierList[drone.CarrierIndex].CarrierObject, CarrierODF);
					FormatLogMessage("Drone %08x '%s' IDLE: Set to DroneState %d, Carrier: %08x '%s'", drone.DroneObject, DroneODF, drone.DroneState, CarrierList[drone.CarrierIndex].CarrierObject, CarrierODF);
				}
			}
			else if (drone.IdleTimer < 1)
			{
				if ((DroneRecall(d)) && (Logging))
				{
					char DroneODF[MAX_ODF_LENGTH] = {0};
					char CarrierODF[MAX_ODF_LENGTH] = {0};
					GetODFName(drone.DroneObject, DroneODF);
					GetODFName(CarrierList[drone.CarrierIndex].CarrierObject, CarrierODF);
					FormatLogMessage("Drone %08x '%s' IDLE: Drone Recalled, Carrier: %08x '%s'", drone.DroneObject, DroneODF, CarrierList[drone.CarrierIndex].CarrierObject, CarrierODF);
				}
			}
			else
			{
				drone.IdleTimer--;
			}
			break;

		case DroneState_Attacking:
			if (!IsAlive(drone.DroneTarget))
			{
				DroneIdle(d);
				if (Logging)
				{
					char DroneODF[MAX_ODF_LENGTH] = {0};
					char CarrierODF[MAX_ODF_LENGTH] = {0};
					GetODFName(drone.DroneObject, DroneODF);
					GetODFName(CarrierList[drone.CarrierIndex].CarrierObject, CarrierODF);
					FormatLogMessage("Drone %08x '%s' ATTACKING: Set to DroneState %d, Carrier: %08x '%s'", drone.DroneObject, DroneODF, drone.DroneState, CarrierList[drone.CarrierIndex].CarrierObject, CarrierODF);
				}
			}
			break;

		case DroneState_Defending:
			if (!IsAlive(drone.DroneTarget))
			{
				if (Target)
				{
					DroneAttack(d, Target, Team);
					if (Logging)
					{
						char DroneODF[MAX_ODF_LENGTH] = {0};
						char TargetODF[MAX_ODF_LENGTH] = {0};
						char CarrierODF[MAX_ODF_LENGTH] = {0};
						GetODFName(drone.DroneObject, DroneODF);
						GetODFName(Target, TargetODF);
						GetODFName(CarrierList[drone.CarrierIndex].CarrierObject, CarrierODF);
						FormatLogMessage("Drone %08x '%s' DEFENDING: Set to DroneState %d, Target: %08x '%s', Carrier: %08x '%s'", drone.DroneObject, DroneODF, drone.DroneState, Target, TargetODF, CarrierList[drone.CarrierIndex].CarrierObject, CarrierODF);
					}
				}
				else if (!NearestEnemy)
				{
					DroneIdle(d);
					if (Logging)
					{
						char DroneODF[MAX_ODF_LENGTH] = {0};
						char CarrierODF[MAX_ODF_LENGTH] = {0};
						GetODFName(drone.DroneObject, DroneODF);
						GetODFName(CarrierList[drone.CarrierIndex].CarrierObject, CarrierODF);
						FormatLogMessage("Drone %08x '%s' DEFENDING: Set to DroneState %d, Carrier: %08x '%s'", drone.DroneObject, DroneODF, drone.DroneState, CarrierList[drone.CarrierIndex].CarrierObject, CarrierODF);
					}
				}
			}
			break;
		}
	}
}

void CarrierHelper::PreOrdnanceHit(Handle shooterHandle, Handle victimHandle, int /*ordnanceTeam*/, const char* /*pOrdnanceODF*/)
{
	const bool Logging = BZ1Helper::Logging;

	if (CarrierList.empty())
		return;

	for (std::vector<DroneClass>::iterator iter = DroneList.begin(); iter != DroneList.end(); ++iter)
	{
		const Handle Carrier = CarrierList[iter->CarrierIndex].CarrierObject;
		if((victimHandle == Carrier) && (iter->DroneState != DroneState_Defending) && (iter->DroneTarget != shooterHandle)) // The Carrier is under attack, all drones engage ShooterHandle.
		{
			Attack(iter->DroneObject, shooterHandle, 1);
			iter->DroneState = DroneState_Defending;
			iter->DroneTarget = shooterHandle;
			if (Logging)
			{
				char DroneODF[MAX_ODF_LENGTH] = {0};
				char CarrierODF[MAX_ODF_LENGTH] = {0};
				GetODFName(iter->DroneObject, DroneODF);
				GetODFName(Carrier, CarrierODF);
				FormatLogMessage("Drone %08x '%s' PREORDNANCEHIT: Set to DroneState: %d, Carrier: %08x '%s'", iter->DroneObject, DroneODF, iter->DroneState, Carrier, CarrierODF);
			}
		}
	}
}

// UnusedArg is the PDB's third parameter; the shipped body never reads it (Execute passes the carrier handle).
Handle CarrierHelper::DroneFindTarget(BZ1Helper &bz1Helper, int index, int /*UnusedArg*/)
{
	DroneClass &drone = DroneList[index];
	if (drone.DroneState == DroneState_Inactive)
		return 0;

	if (IsAlive(drone.DroneTarget))
		return drone.DroneTarget;

	const CarrierClass &carrier = CarrierList[drone.CarrierIndex];
	Handle Target = 0;
	if(IsPlayer(carrier.CarrierObject))
		Target = GetUserTarget(GetTeamNum(carrier.CarrierObject));
	else
		Target = GetTarget(carrier.CarrierObject);

	// VSR: spread the drones over a random object near the carrier's target. (As shipped: the search is seeded with the TARGET's team and the Enemies filter.)
	if ((drone.RandomTargetDist != 0.0f) && (Target))
	{
		const Vector TargetPosition = GetPosition(Target);
		Target = bz1Helper.GetRandomObject(GetTeamNum(Target), TeamFilter_Enemies, true, 0, false, true, false, 0, NULL, NULL, drone.RandomTargetDist, TargetPosition);
	}

	// Only go once the carrier has its attack force up.
	if (carrier.CurDrones >= carrier.MinAttackForce)
		return Target;
	return 0;
}

bool CarrierHelper::DroneRecall(int index)
{
	const bool Logging = BZ1Helper::Logging;
	DroneClass &drone = DroneList[index];
	CarrierClass &carrier = CarrierList[drone.CarrierIndex];

	if (carrier.DroneRecallRange == 0.0f)
		return false;

	// This drone is returning, watch for it to get close enough to Remove it.
	if (GetDistance(drone.DroneObject, carrier.CarrierObject) < carrier.DroneRecallRange)
	{
		if(!drone.UseLocalAmmo)
			AddAmmo(carrier.CarrierObject, GetMaxHealth(drone.DroneObject));
		else
			AddLocalAmmo(carrier.CarrierObject, float(GetMaxHealth(drone.DroneObject)), drone.CarrierWeaponSlot);

		if (Logging)
		{
			char DroneODF[MAX_ODF_LENGTH] = {0};
			char CarrierODF[MAX_ODF_LENGTH] = {0};
			GetODFName(drone.DroneObject, DroneODF);
			GetODFName(carrier.CarrierObject, CarrierODF);
			FormatLogMessage("Drone %08x '%s' PACKUP: Set to Recall to Carrier: %08x '%s'", drone.DroneObject, DroneODF, carrier.CarrierObject, CarrierODF);
		}

		carrier.CurDrones--;
		RemoveObject(drone.DroneObject);
		return true;
	}
	return false;
}

void CarrierHelper::DroneActivate(int index, int carrierindex)
{
	DroneClass &drone = DroneList[index];
	SetIndependence(drone.DroneObject, 1);
	drone.CarrierIndex = carrierindex;
	DroneIdle(index);
	CarrierList[drone.CarrierIndex].CurDrones++;
}

void CarrierHelper::DroneDeactivate(int index, bool resize)
{
	DroneClass &drone = DroneList[index];
	SetIndependence(drone.DroneObject, 0);
	Stop(drone.DroneObject, 1);
	drone.DroneState = DroneState_Inactive;
	if (resize)
		CarrierList[drone.CarrierIndex].CurDrones--;
}

void CarrierHelper::DroneIdle(int index)
{
	DroneClass &drone = DroneList[index];
	const CarrierClass &carrier = CarrierList[drone.CarrierIndex];
	SetIndependence(drone.DroneObject, 0);
	Follow(drone.DroneObject, carrier.CarrierObject, 1);
	drone.IdleTimer = SecondsToTurns(carrier.DroneIdleTime);
	drone.DroneState = DroneState_Idle;
}

void CarrierHelper::DroneAttack(int index, Handle target, int team)
{
	DroneClass &drone = DroneList[index];
	SetIndependence(drone.DroneObject, 1);
	if (IsTeamAllied(team, GetTeamNum(target)))
		Defend2(drone.DroneObject, target, 1);
	else
		Attack(drone.DroneObject, target, 1);
	drone.DroneTarget = target;
	drone.DroneState = DroneState_Attacking;
}

// DECOMPILE: no procedure of its own (inlined into Execute's idle branch).
void CarrierHelper::DroneDefend(int index)
{
	DroneClass &drone = DroneList[index];
	SetIndependence(drone.DroneObject, 1);
	Defend2(drone.DroneObject, CarrierList[drone.CarrierIndex].CarrierObject, 1);
	drone.DroneState = DroneState_Defending;
}
