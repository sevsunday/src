// PROVENANCE: ancestor reference/ancestor-bz1helper-2015/Shared/BuildingHelper.cpp @6fda4f5 (power network, tap upkeep, gun tower, powerup acceptance) | decompile reference/decompiled/strategy02-ghidra12.2/src/missions/vsrcore/buildinghelper.cpp.decomp.c (PostLoad 45-70, AddBuildingObject 88-321, Execute 324-765, IsBuildingPowered 768-779, GetRandomBuilding 798-841, GetNumBuildings 845-878, GetNearestServiceObject 946-1020; Load / Save inlined into BZ1Helper) + dumpbin of 4fc1dbee / 4fc1e4a1 / 4fc1f198 / 4fc1f2eb for the register-passed arguments | status: ported
#include "bz1helper.h"
#include "buildinghelper.h"
#include "powerhelper.h"
#include "poweruphelper.h"
#include "utilityshiphelper.h"
#include "bzcscriptutils.h"
#include <algorithm>

BuildingHelper *BuildingHelper::m_BuildingHelper;

std::vector<BuildingHelper::BuildingClass> TempBuildingBuffer; // GBD: the list as it stood before a Load, for PostLoad's resync report.

BuildingHelper::BuildingHelper()
{
	m_BuildingHelper = this;
}
BuildingHelper::~BuildingHelper()
{
	m_BuildingHelper = NULL;
}

bool BuildingHelper::Load(bool missionSave)
{
	if (!missionSave)
	{
		TempBuildingBuffer = BuildingList;

		int size = 0;
		bool ret = Read(&size, 1);
		BuildingList.resize(size);
		if(size)
			ret = ret && Read(&BuildingList.front(), sizeof(BuildingClass)*size);
		return ret;
	}
	return true;
}

bool BuildingHelper::PostLoad(bool missionSave)
{
	if (!missionSave)
	{
		for (std::vector<BuildingClass>::iterator iter = BuildingList.begin(); iter != BuildingList.end(); ++iter)
		{
			BuildingClass &sao = *iter;
			ConvertHandles(&sao.BuildingObject, 1);
			for(int i = 0; i < MAX_TAPS; i++)
				ConvertHandles(&sao.BuildingTap[i], 1);
		}

		// GBD: resync report — compare what we had against what we loaded.
		if (TempBuildingBuffer.size() == BuildingList.size())
		{
			for (int i = 0; i < int(BuildingList.size()); i++)
			{
				if (!(TempBuildingBuffer[i] == BuildingList[i]))
				{
					FormatLogMessage("BuildingList Index Mismatch: %d", i);
					break;
				}
			}
		}
		else
		{
			FormatLogMessage("BuildingList Size Mismatch! Old: %d New: %d", TempBuildingBuffer.size(), BuildingList.size());
		}
	}
	return true;
}

bool BuildingHelper::Save(bool missionSave)
{
	if (!missionSave)
	{
		int size = int(BuildingList.size());
		bool ret = Write(&size, 1);
		if(size)
			ret = ret && Write(&BuildingList.front(), sizeof(BuildingClass)*size);
		return ret;
	}
	return true;
}

void BuildingHelper::AddBuildingObject(const Handle h, const char* TempODF1, const char* TempODF2, const int Team, const int ODFNameHash, const int ObjClassHash, const int BZCClassHash, const bool CanBeIdleVictim, const int NumWeapons, const bool /*UnusedArg*/)
{
	int BuildingListIndex = -1;
	for (std::vector<BuildingClass>::iterator iter = BuildingList.begin(); iter != BuildingList.end(); ++iter)
	{
		if(iter->BuildingObject == h)
		{
			// Temp re-count of taps. (VSR: a tap is real when it has an ODF; AddObject hands us a dummy tap at the end of the list.)
			int Taps = GetTapCount(iter->BuildingObject, true, true);
			// Now update tap number if it doesn't match.
			if(iter->TapNumber != Taps)
				iter->TapNumber = Taps;

			// VSR: a gun tower re-added as its own upgrade keeps the weapons it had.
			if ((iter->ObjClassHash == CLASS_TURRET) && (unsigned int(ODFNameHash) == Hash(iter->UpgradeName)))
				ReplaceWeapons(h, iter->WeaponNames);

			BuildingListIndex = int(iter - BuildingList.begin());

			break;
		}
	}

	if(BuildingListIndex < 0) // New Object, Increase list size to compensate.
	{
		BuildingList.resize(BuildingList.size()+1);
		BuildingListIndex = int(BuildingList.size())-1; // Use the new index.
	}
	BuildingClass &sao = BuildingList[BuildingListIndex]; // No temporary being created, *much* faster
	memset(&sao, 0, sizeof(BuildingClass)); // Zero things out at start.

	GetODFInt(TempODF1, TempODF2, "GameObjectClass", "RequirePowerMask", &sao.PowerType, 0);
	if (ObjClassHash == CLASS_TURRET)
	{
		GetODFBool(TempODF1, TempODF2, "TurretCraftClass", "PoweredByTaps", &sao.PoweredByTaps, true);
		GetODFBool(TempODF1, TempODF2, "TurretCraftClass", "autoBuildTaps", &sao.autoBuildTaps, true);
		GetODFBool(TempODF1, TempODF2, "TurretCraftClass", "canDemolish", &sao.CanDemolish, true);
		sao.NumWeapons = NumWeapons;
	}
	else
	{
		GetODFBool(TempODF1, TempODF2, "PoweredBuildingClass", "PoweredByTaps", &sao.PoweredByTaps, true);
		GetODFBool(TempODF1, TempODF2, "PoweredBuildingClass", "autoBuildTaps", &sao.autoBuildTaps, true);
		GetODFBool(TempODF1, TempODF2, "BuildingClass", "canDemolish", &sao.CanDemolish, true);
	}

	GetODFInt(TempODF1, TempODF2, "GameObjectClass", "GameObjectClassPowerMask", &sao.PowerMask, 0);
	GetODFInt(TempODF1, TempODF2, "GameObjectClass", "GameObjectClassPowerMatch", &sao.PowerMatch, 0);
	GetODFInt(TempODF1, TempODF2, "GameObjectClass", "GameObjectClassPowerProvides", &sao.PowerProvide, 0);

	GetODFFloat(TempODF1, TempODF2, "GameObjectClass", "CollisionRadius", &sao.CollisionRadius, 0.0f);
	GetODFBool(TempODF1, TempODF2, "GameObjectClass", "CanCollide", &sao.CanCollide, false);
	GetODFBool(TempODF1, TempODF2, "GameObjectClass", "ownsTerrain", &sao.OwnsTerrain, true);

	// VSR: CanAcceptPowerups means every kind; AcceptPowerupMask narrows it.
	bool CanAcceptPowerups = false;
	GetODFBool(TempODF1, TempODF2, "GameObjectClass", "CanAcceptPowerups", &CanAcceptPowerups, false);
	sao.PowerupAcceptMask = CanAcceptPowerups ? -1 : 0;
	GetODFInt(TempODF1, TempODF2, "GameObjectClass", "AcceptPowerupMask", &sao.PowerupAcceptMask, sao.PowerupAcceptMask);

	GetODFInt(TempODF1, TempODF2, "BuildingClass", "SizeRatioX", &sao.TerrainSizeRatio[0], 1);
	GetODFInt(TempODF1, TempODF2, "BuildingClass", "SizeRatioZ", &sao.TerrainSizeRatio[1], 1);
	char BuildSupport = 0;
	GetODFChar(TempODF1, TempODF2, "GameObjectClass", "buildSupport", &BuildSupport, 'A');
	sao.BuildSupport = toupper(BuildSupport);
	GetODFString(TempODF1, TempODF2, "GameObjectClass", "upgradeName", MAX_ODF_LENGTH, sao.UpgradeName);

	sao.CurTeamNum = Team;
	bool IsApcRefillDefault = (BZCClassHash == BZCCLASS_RECYCLER || ObjClassHash == CLASS_BARRACKS);
	GetODFBool(TempODF1, TempODF2, "GameObjectClass", "APCRefillPoint", &sao.IsAPCRefill, IsApcRefillDefault);

	// Keep track of dummy recycle points, we have to reset base slot 1.
	bool RecyclePoint = (((BZCClassHash == BZCCLASS_RECYCLER) && (IsBuilding(h))) || (ObjClassHash == CLASS_SILO) || (ObjClassHash == CLASS_EXTRACTOR));
	GetODFBool(TempODF1, TempODF2, "GameObjectClass", "RecyclePoint", &sao.IsRecyclePoint, RecyclePoint);

	// VSR: supply depot rates. sic: tests the entry's ObjClassHash, which is still 0 here (it is assigned at the end), so this block never runs.
	if (sao.ObjClassHash == unsigned int(CLASS_SUPPLYDEPOT))
	{
		GetODFFloat(TempODF1, TempODF2, "SupplyDepotClass", "healthRate", &sao.HealthRate, 0.0f);
		GetODFFloat(TempODF1, TempODF2, "SupplyDepotClass", "ammoRate", &sao.AmmoRate, 0.0f);
		GetODFFloat(TempODF1, TempODF2, "SupplyDepotClass", "localAmmoRate", &sao.LocalAmmoRate, 0.0f);
		GetODFFloat(TempODF1, TempODF2, "SupplyDepotClass", "supplyRate", &sao.ServiceRate, 0.0f);
		GetODFBool(TempODF1, TempODF2, "SupplyDepotClass", "serviceCraft", &sao.ServiceCraft, true);
	}

	sao.MaxHealth = GetMaxHealth(h);
	sao.MaxAmmo = GetMaxAmmo(h);
	sao.CanBeIdleVictim = CanBeIdleVictim;

	bool Animated = true;
	GetODFBool(TempODF1, TempODF2, "GameObjectClass", "IsAnimated", &Animated, true);

	if(Animated)
	{
		char AnimationName[MAX_ODF_LENGTH] = {0};
		int AnimationCount = 0;
		GetODFInt(TempODF1, TempODF2, "GameObjectClass", "animCount", &AnimationCount, 0);
		// VSR: a BZCloop animation is all it takes; the engine pauses / resumes it now, so there is no BZCoff.
		for (int i = 1; i < AnimationCount+1; i++)
		{
			char DesiredValue[MAX_ODF_LENGTH] = {0};
			sprintf_s(DesiredValue, "animName%d", i);
			if((GetODFString(TempODF1, TempODF2, "GameObjectClass", DesiredValue, MAX_ODF_LENGTH, AnimationName)) && (_stricmp(AnimationName, "BZCloop") == 0)) // Grab the animation name.
			{
				sao.IsAnimated = true;
				break; // We found it, abort!
			}
		}
	}

	Matrix HostMatrix = GetMatrixPosition(h);
	int Taps = 0;
	for(int x = 0; x < MAX_TAPS; x++)
	{
		Handle TempTap = GetTap(h, x);
		if (!TempTap)
			continue;

		char ODFName[MAX_ODF_LENGTH] = {0};
		char TempODF3[MAX_ODF_LENGTH] = {0};
		char TempODF4[MAX_ODF_LENGTH] = {0};
		GetAndOpenODFNames(TempTap, TempODF3, TempODF4, ODFName);
		//if(IsAround(TempTap)) // Bad, IsAround fails in AddObject since the tap kindof doesn't exist yet.

		if(ODFName[0])
		{
			++Taps;

			sao.BuildingTap[x] = TempTap;
			Matrix TapMatrix = GetMatrixPosition(TempTap);
			Matrix InvHostMatrix = Matrix_Inverse(HostMatrix);
			sao.TapOffsetMatrix[x] = Matrix_Multiply(TapMatrix, InvHostMatrix);

			// Find out if the taps are animated.
			bool TapAnimated = true;
			GetODFBool(TempODF3, TempODF4, "GameObjectClass", "IsAnimated", &TapAnimated, true);
			if (TapAnimated)
			{
				char AnimationName[MAX_ODF_LENGTH] = {0};
				int AnimationCount = 0;
				GetODFInt(TempODF3, TempODF4, "GameObjectClass", "animCount", &AnimationCount, 0);
				for (int a = 1; a < AnimationCount+1; a++)
				{
					char DesiredValue[MAX_ODF_LENGTH] = {0};
					sprintf_s(DesiredValue, "animName%d", a);
					if((GetODFString(TempODF3, TempODF4, "GameObjectClass", DesiredValue, MAX_ODF_LENGTH, AnimationName)) && (_stricmp(AnimationName, "BZCloop") == 0)) // Grab the animation name.
					{
						sao.TapAnimated[x] = true;
						break; // We found it, abort!
					}
				}
			}
		}
	}
	sao.PowerState = -1; // Autodetermine.
	sao.TapNumber = Taps;
	sao.ObjClassHash = ObjClassHash;
	sao.ODFNameHash = ODFNameHash;
	sao.BuildingObject = h;
	sao.Position = GetPosition(h);
	sao.BuildingFront = HostMatrix.front;
}

void BuildingHelper::Execute(BZ1Helper &bz1Helper)
{
	const bool Logging = BZ1Helper::Logging;

	// pre-clean the vector
	BuildingList.erase(std::remove_if(BuildingList.begin(), BuildingList.end(), ShouldRemoveBuilding), BuildingList.end());

	for (std::vector<BuildingClass>::iterator iter = BuildingList.begin(); iter != BuildingList.end(); ++iter)
	{
		iter->CurTeamNum = GetTeamNum(iter->BuildingObject); // Update this every tick once here.
		Matrix HostMatrix = GetMatrixPosition(iter->BuildingObject);
		const int PTeam = GetPerceivedTeam(iter->BuildingObject);

		// VSR: live tap count; a building that doesn't grow its own taps adopts a higher count (an upgrade added some).
		int Taps = 0;
		if (iter->TapNumber != 0)
			Taps = GetTapCount(iter->BuildingObject, true, true);
		if ((!iter->autoBuildTaps) && (iter->TapNumber < Taps))
			iter->TapNumber = Taps;

		// If we're on Autodetermine, use normal behavior.
		if(iter->PowerState < 0)
		{
			bool IsInRangeOfPower = false;
			if((iter->PowerType & 1) == PType_BZ1) // Requires BZ1 Power.
			{
				for(int i = 0; i < PowerHelper::Get().GetNumPowerObjects(); i++)
				{
					PowerHelper::PowerClass powerInfo = PowerHelper::Get().GetPowerInfo(i);
					if(	(powerInfo.IsPowered) && // Is this power plant powered?
						(IsTeamAllied(iter->CurTeamNum, powerInfo.PowerTeam)) && // Teams are allied.
						(((powerInfo.PowerProvide & iter->PowerMask) == iter->PowerMatch) && // Power Provides match Building requirements.
						((iter->PowerProvide & powerInfo.PowerMask) == powerInfo.PowerMatch)) && // Building Provides match Power requirements.
						(GetDistance3DSquared(iter->Position, powerInfo.Position) < Squared(powerInfo.PowerRange)) ) // Is in range of PowerPlant.
					{
						IsInRangeOfPower = true;
						break;
					}
				}
			}

			if( (iter->PowerType == PType_None) || // Power Type is 0 == None.
				(((iter->PowerType & 1) == PType_BZ1) && (IsInRangeOfPower)) || // PowerType is 1 == Requires BZ1 Power.
				(((iter->PowerType & 2) == PType_BZ2) && (GetPower(iter->CurTeamNum) >= 0)) || // PowerType is 2 == Requires BZ2 Power.
				(((iter->PowerType & 4) == PType_Lung) && ((!iter->PoweredByTaps) || (Taps == iter->TapNumber)))) // PowerType is 4 == Requires Lung Power.
				iter->IsPowered =  true;
			else
				iter->IsPowered =  false;
		}
		else
		{
			iter->IsPowered = iter->PowerState != 0; // Defer to DLL control.
		}

		// Main Building Animations. VSR: the engine's BZCloop is paused while unpowered and resumed in the direction it was paused at.
		if(iter->IsAnimated)
		{
			iter->PlayAnim = GetAnimationDirection(iter->BuildingObject) != 0;
			if(iter->IsPowered)
			{
				if(!iter->PlayAnim)
				{
					if (iter->AnimDir[0] != 0)
						ResumeAnimation(iter->BuildingObject, iter->AnimDir[0]);
					else
						iter->AnimDir[0] = GetAnimationDirection(iter->BuildingObject);
				}
			}
			else if(iter->PlayAnim)
			{
				iter->AnimDir[0] = PauseAnimation(iter->BuildingObject);
			}
		}

		// Tap animations.
		for(int x = 0; x < iter->TapNumber; x++)
		{
			// Make sure TAPS are on the same Team. (If DLL swaps the items team, the TAPS don't change with it.
			if(IsAround(iter->BuildingTap[x])) // If the tap is around, watch for it's position to move. Keep its position compared to its parent.
			{
				Matrix TapMatrix = GetMatrixPosition(iter->BuildingTap[x]);

				if(iter->CurTeamNum != GetTeamNum(iter->BuildingTap[x]))
					SetTeamNum(iter->BuildingTap[x], iter->CurTeamNum);

				if(GetPerceivedTeam(iter->BuildingTap[x]) != PTeam)
					SetPerceivedTeam(iter->BuildingTap[x], PTeam);

				if(iter->TapAnimated[x])
				{
					iter->PlayTapAnim[x] = GetAnimationDirection(iter->BuildingTap[x]) != 0;
					if(iter->IsPowered)
					{
						if(!iter->PlayTapAnim[x])
						{
							if (iter->AnimDir[x+1] != 0)
							{
								ResumeAnimation(iter->BuildingTap[x], iter->AnimDir[x+1]);
								iter->PlayTapAnim[x] = true;
							}
							else
								iter->AnimDir[x+1] = GetAnimationDirection(iter->BuildingTap[x]);
						}
					}
					else if(iter->PlayTapAnim[x])
					{
						iter->AnimDir[x+1] = PauseAnimation(iter->BuildingTap[x]);
						iter->PlayTapAnim[x] = false;
					}
				}

				// If its position is off from what we have stored, fix it.
				if((!close_enough(iter->TapOffsetMatrix[x].posit, Vector_TransformInv(HostMatrix, TapMatrix.posit), 0.01f)) ||
					(!close_enough(iter->BuildingFront, HostMatrix.front, 0.01f)))
				{
					Matrix NewMatrix = Matrix_Multiply(iter->TapOffsetMatrix[x], HostMatrix);
					SetPosition(iter->BuildingTap[x], NewMatrix);

					if(Logging)
					{
						char HostODF[MAX_ODF_LENGTH] = {0};
						char TapODF[MAX_ODF_LENGTH] = {0};
						GetODFName(iter->BuildingObject, HostODF);
						GetODFName(iter->BuildingTap[x], TapODF);
						FormatLogMessage("Tap Not Matching Host: %08x %s! Current Tap: %08x '%s' Old Offset: %f %f %f New Offset: %f %f %f, Old Building Front: %f %f %f New Building Front: %f %f %f", iter->BuildingObject, HostODF, iter->BuildingTap[x], TapODF, iter->TapOffsetMatrix[x].posit.x, iter->TapOffsetMatrix[x].posit.y, iter->TapOffsetMatrix[x].posit.z, (TapMatrix.posit.x - HostMatrix.posit.x), (TapMatrix.posit.y - HostMatrix.posit.y), (TapMatrix.posit.z - HostMatrix.posit.z), iter->BuildingFront.x, iter->BuildingFront.y, iter->BuildingFront.z, HostMatrix.front.x, HostMatrix.front.y, HostMatrix.front.z);
					}

					// Save new Offset Matrix.
					Matrix NewTapMatrix = GetMatrixPosition(iter->BuildingTap[x]);
					Matrix InvHostMatrix = Matrix_Inverse(HostMatrix);
					iter->TapOffsetMatrix[x] = Matrix_Multiply(NewTapMatrix, InvHostMatrix);
					// Save new Front.
					iter->BuildingFront = HostMatrix.front;
				}
			}
		}

		if(iter->ObjClassHash == unsigned int(CLASS_TURRET))
		{
			// VSR: remember the gun tower's weapons, so an upgrade of it can be re-armed.
			if (iter->NumWeapons != 0)
			{
				for (int i = 0; i < 5; i++)
					GetObjInfo(iter->BuildingObject, ObjectInfoType(Get_Weapon0Config + i), iter->WeaponNames[i]);
			}

			// VSR: an unpowered gun tower loses its pilot AI and stops steering / firing; power restores the pilot.
			if((iter->GunTowerOff) && (iter->IsPowered))
			{
				iter->GunTowerOff = false;
				AddPilotByHandle(iter->BuildingObject); // restore AI.
			}
			if((!iter->GunTowerOff) && (!iter->IsPowered))
			{
				iter->GunTowerOff = true;
				VehicleControls Controls;
				Controls.steer = 0.0f;
				Controls.fire = 0;
				SetControls(iter->BuildingObject, Controls, CTRL_STEER | CTRL_FIRE);
				RemovePilotAI(iter->BuildingObject); // Shutdown AI.
			}
		}

		// Powerup Repair code. BZ2 without bullet physics doesn't normally allow buildings to accept powerups unless canCollide = 1. So, here we emulate it via DLL. :)
		// VSR: PowerupAcceptMask says which kinds; gun towers also take weapon powerups and local-ammo pods.
		if((!iter->CanCollide) && (iter->PowerupAcceptMask != 0))
		{
			const long CurHealth = GetCurHealth(iter->BuildingObject);
			const long CurAmmo = GetCurAmmo(iter->BuildingObject);
			if ((((iter->MaxHealth != 0) || (iter->MaxAmmo != 0)) && ((CurHealth < iter->MaxHealth) || (CurAmmo < iter->MaxAmmo))) ||
				((iter->ObjClassHash == unsigned int(CLASS_TURRET)) && (iter->NumWeapons > 0)))
			{
				const float CollisionRadiusSquared = Squared(iter->CollisionRadius);
				for (int p = 0; p < PowerupHelper::Get().GetNumPowerupObjects(); p++)
				{
					PowerupHelper::PowerupClass powerupInfo = PowerupHelper::Get().GetPowerupInfo(p);
					if (powerupInfo.DelayTime > 0)
						continue;
					if (fabsf(powerupInfo.Velocity.y) >= 0.5f) // Resting.
						continue;

					bool NeedsLocalAmmo = false;
					if ((iter->ObjClassHash == unsigned int(CLASS_TURRET)) && (powerupInfo.LocalAmmoUp != 0))
					{
						for (int w = 0; w < 5; w++)
						{
							if (GetCurLocalAmmo(iter->BuildingObject, w) < GetMaxLocalAmmo(iter->BuildingObject, w))
							{
								NeedsLocalAmmo = true;
								break;
							}
						}
					}

					if ((((CurHealth < iter->MaxHealth) && (powerupInfo.HealthUp != 0)) ||
						((CurAmmo < iter->MaxAmmo) && (powerupInfo.AmmoUp != 0)) ||
						((iter->ObjClassHash == unsigned int(CLASS_TURRET)) && (powerupInfo.ObjClassHash == unsigned int(CLASS_WEAPON))) ||
						(NeedsLocalAmmo)) && // It has something we need,
						((((iter->PowerupAcceptMask & 0x20) != 0) && ((powerupInfo.ObjClassHash == unsigned int(CLASS_POWERUP_RELOAD)) || (powerupInfo.ObjClassHash == unsigned int(CLASS_POWERUP_REPAIR)) || (powerupInfo.ObjClassHash == unsigned int(CLASS_POWERUP_SERVICE)))) ||
						(((iter->PowerupAcceptMask & 0x40) != 0) && (powerupInfo.ObjClassHash == unsigned int(CLASS_WEAPON)))) && // and is a kind we accept,
						((powerupInfo.HitMask & 4) != 0)) // and can land on a building.
					{
						if (GetDistance2DSquared(powerupInfo.Position, iter->Position) < CollisionRadiusSquared)
						{
							bool Accepted = true;
							if (powerupInfo.ObjClassHash == unsigned int(CLASS_WEAPON))
							{
								Accepted = false;
								for (int w = 0; w < 5; w++)
								{
									if (GiveWeapon(iter->BuildingObject, powerupInfo.WeaponUp, w))
									{
										Accepted = true;
										break;
									}
								}
							}
							if (Accepted)
							{
								StartAudio3D(powerupInfo.SoundPickup, iter->BuildingObject, AUDIO_CAT_WEAPON);
								AddHealth(iter->BuildingObject, powerupInfo.HealthUp);
								AddAmmo(iter->BuildingObject, powerupInfo.AmmoUp);
								if (Logging)
								{
									char HostODF[MAX_ODF_LENGTH] = {0};
									GetODFName(iter->BuildingObject, HostODF);
									FormatLogMessage("POWERUP ACCEPTED: '%s' on Team %d at: %f %f %f w/ ColRad: %f Accepted Powerup: '%s' at: %f %f %f", HostODF, iter->CurTeamNum, iter->Position.x, iter->Position.y, iter->Position.z, iter->CollisionRadius, GetODFName(powerupInfo.PowerupObject), powerupInfo.Position.x, powerupInfo.Position.y, powerupInfo.Position.z);
								}
								if (NeedsLocalAmmo)
								{
									for (int w = 0; w < 5; w++)
										AddLocalAmmo(iter->BuildingObject, float(powerupInfo.LocalAmmoUp), w);
								}
								RemoveObject(powerupInfo.PowerupObject);
							}
						}
					}
				}
			}
		}

		// VSR: the CPU commander has its damaged buildings serviced — by a service truck, else an armory-built repair pod.
		const int Team = iter->CurTeamNum;
		const BZ1Helper::TeamInfo &teamInfo = bz1Helper.RefTeamInfo(Team);
		if ((GetPlayerHandle(Team) == 0) && (teamInfo.m_CPUUnitsCanService))
		{
			if (GetHealth(iter->BuildingObject) < teamInfo.m_CPUBuildingRepairHealthRatio)
			{
				if (BZ1Helper::m_TurnCounter % int(teamInfo.m_CPUBuildingRepairInterval * float(BZ1Helper::m_GameTPS)) == 0)
				{
					if (GetRandomFloat(1.0f) < teamInfo.m_CPUBuildingRepairChance)
					{
						if ((iter->PowerupAcceptMask & 0x20) != 0)
						{
							Handle ServiceTruck = UtilityShipHelper::Get().FindServiceTruck(iter->BuildingObject, Team, IsProducer(iter->BuildingObject), 0.0f);
							if (ServiceTruck)
							{
								Service(ServiceTruck, iter->BuildingObject, 0);
							}
							else if (teamInfo.Armory)
							{
								char BuildItem[MAX_ODF_LENGTH] = {0};
								if (GetBuildItem(teamInfo.Armory, BuildItem, NULL, 1))
								{
									if (GetScrap(Team) >= 0)
										bz1Helper.BuildAt(teamInfo.Armory, BuildItem, iter->Position);
								}
							}
						}
					}
				}
			}
		}
	}
}

bool BuildingHelper::IsBuildingPowered(const Handle h)
{
	if(!IsAround(h))
		return false;

	for (std::vector<BuildingClass>::iterator iter = BuildingList.begin(); iter != BuildingList.end(); ++iter)
	{
		if(iter->BuildingObject == h)
			return iter->IsPowered;
	}
	return true; // VSR: a building we don't track counts as powered.
}

// DECOMPILE: not emitted as a symbol in the binary (inlined into BZ1Helper::SetBuildingPowered); ancestor body
void BuildingHelper::SetBuildingPowered(const Handle h, const int PoweredState)
{
	if(!IsAround(h))
		return;

	for (std::vector<BuildingClass>::iterator iter = BuildingList.begin(); iter != BuildingList.end(); ++iter)
	{
		if(iter->BuildingObject == h)
		{
			iter->PowerState = PoweredState;
			return;
		}
	}
}

// VSR: UsePTeam (true), IgnoreInvincible (true) and ObeyIdleVictim (true) are LTCG-folded at every shipped call site (DispatchHelper), as are MatchMask (0) and
// ObjClass / ODFName (NULL); the BZ1Helper::GetRandomObject logic for them is kept and reduces to the shipped body there.
Handle BuildingHelper::GetRandomBuilding(const int Team, const int TeamFilter, const bool UsePTeam, const bool IgnoreInvincible, const bool ObeyIdleVictim, const int MatchMask, const char *ObjClass, const char *ODFName, const float MinDistance, const Vector Position)
{
	const int NewTeamFilter = TeamFilter ? TeamFilter : -1;
	const int NewMatchMask = MatchMask ? MatchMask : -1;
	const float MinDistanceSquared = MinDistance * MinDistance;

	unsigned int ObjClassHash = 0;
	unsigned int ODFNameHash = 0;

	if(ObjClass)
		ObjClassHash = Hash(ObjClass);

	if(ODFName)
		ODFNameHash = Hash(ODFName);

	int Size = int(BuildingList.size()) - 1;
	if (Size < 0)
		Size = 0;

	int Start = GetRandomInt(0, Size);
	int x = Start;
	do
	{
		const BuildingClass &building = BuildingList[x];

		if( ((Team < 0) || (TeamFilterCheck(NewTeamFilter, Team, UsePTeam ? building.PTeam : building.CurTeamNum))) && // Team Filter matches.
			((!IgnoreInvincible) || (building.MaxHealth > 0)) && // Health matches.
			((!ObeyIdleVictim) || (building.CanBeIdleVictim)) && // Idle-unit victims only, if asked.
			((MinDistance <= 0.0f) || (GetDistance3DSquared(building.Position, Position) < MinDistanceSquared)) && // Within range of Position, if asked.
			(
			((NewMatchMask & MatchMask_Category) == MatchMask_Category) ||
			(((NewMatchMask & MatchMask_ObjClass) == MatchMask_ObjClass) && (ObjClass) && (building.ObjClassHash == ObjClassHash)) ||
			(((NewMatchMask & MatchMask_ODFName) == MatchMask_ODFName) && (ODFName) && (building.ODFNameHash == ODFNameHash))
			))
		{
			return building.BuildingObject;
		}

		x++;
		if (x > Size)
			x = 0;
	} while (x != Start);

	return 0;
}

// VSR: UsePTeam (false), IgnoreInvincible (true) and ObeyIdleVictim (false) are LTCG-folded at every shipped call site, as are MatchMask (0) and
// ObjClass / ODFName (NULL); the GetRandomBuilding logic for them is kept and reduces to the shipped body there.
int BuildingHelper::GetNumBuildings(const int Team, const int TeamFilter, const bool UsePTeam, const bool IgnoreInvincible, const bool ObeyIdleVictim, const int MatchMask, const char *ObjClass, const char *ODFName)
{
	const int NewTeamFilter = TeamFilter ? TeamFilter : -1;
	const int NewMatchMask = MatchMask ? MatchMask : -1;

	unsigned int ObjClassHash = 0;
	unsigned int ODFNameHash = 0;

	if(ObjClass)
		ObjClassHash = Hash(ObjClass);

	if(ODFName)
		ODFNameHash = Hash(ODFName);

	int Count = 0;
	for (int x = 0; x < int(BuildingList.size()); x++)
	{
		const BuildingClass &building = BuildingList[x];

		if( ((Team < 0) || (TeamFilterCheck(NewTeamFilter, Team, UsePTeam ? building.PTeam : building.CurTeamNum))) && // Team Filter matches.
			((!IgnoreInvincible) || (building.MaxHealth > 0)) && // Health matches.
			((!ObeyIdleVictim) || (building.CanBeIdleVictim)) &&
			(
			((NewMatchMask & MatchMask_Category) == MatchMask_Category) ||
			(((NewMatchMask & MatchMask_ObjClass) == MatchMask_ObjClass) && (ObjClass) && (building.ObjClassHash == ObjClassHash)) ||
			(((NewMatchMask & MatchMask_ODFName) == MatchMask_ODFName) && (ODFName) && (building.ODFNameHash == ODFNameHash))
			))
		{
			Count++;
		}
	}

	return Count;
}

// DECOMPILE: declared in the PDB, no procedure in any shipped DLL (never called); the BZ1Helper::GetNearestVehicle shape over the building list.
Handle BuildingHelper::GetNearestBuilding(const Matrix Position, const float MaxRange, const int Team, const int TeamFilter, const bool UsePTeam, const bool IgnoreInvincible, const bool ObeyIdleVictim, const int MatchMask, const char *ObjClass, const char *ODFName)
{
	return GetNearestBuilding(Position.posit, MaxRange, Team, TeamFilter, UsePTeam, IgnoreInvincible, ObeyIdleVictim, 0, MatchMask, ObjClass, ODFName);
}

// DECOMPILE: declared in the PDB, no procedure in any shipped DLL (never called).
Handle BuildingHelper::GetNearestBuilding(const Handle h, const float MaxRange, const int Team, const int TeamFilter, const bool UsePTeam, const bool IgnoreInvincible, const bool ObeyIdleVictim, const int MatchMask, const char *ObjClass, const char *ODFName)
{
	if(!IsAround(h))
		return 0;

	return GetNearestBuilding(GetPosition(h), MaxRange, Team, TeamFilter, UsePTeam, IgnoreInvincible, ObeyIdleVictim, h, MatchMask, ObjClass, ODFName);
}

// DECOMPILE: declared in the PDB, no procedure in any shipped DLL (never called).
Handle BuildingHelper::GetNearestBuilding(const Name Path, const int Point, const float MaxRange, const int Team, const int TeamFilter, const bool UsePTeam, const bool IgnoreInvincible, const bool ObeyIdleVictim, const int MatchMask, const char *ObjClass, const char *ODFName)
{
	if(!DoesPathExist(Path))
		return 0;

	return GetNearestBuilding(GetVectorFromPath(Path, Point), MaxRange, Team, TeamFilter, UsePTeam, IgnoreInvincible, ObeyIdleVictim, 0, MatchMask, ObjClass, ODFName);
}

// DECOMPILE: declared in the PDB, no procedure in any shipped DLL (never called).
Handle BuildingHelper::GetNearestBuilding(const Vector Position, const float MaxRange, const int Team, const int TeamFilter, const bool UsePTeam, const bool IgnoreInvincible, const bool ObeyIdleVictim, const Handle Me, const int MatchMask, const char *ObjClass, const char *ODFName)
{
	const int NewTeamFilter = TeamFilter ? TeamFilter : -1;
	const int NewMatchMask = MatchMask ? MatchMask : -1;
	Handle TempH = 0;

	unsigned int ObjClassHash = 0;
	unsigned int ODFNameHash = 0;

	if(ObjClass)
		ObjClassHash = Hash(ObjClass);

	if(ODFName)
		ODFNameHash = Hash(ODFName);

	float BestDistSquared = MaxRange <= 0 ? FLT_MAX : Squared(MaxRange); // Start out with MaxRange, or infinite.
	for (std::vector<BuildingClass>::const_iterator iter = BuildingList.begin(); iter != BuildingList.end(); ++iter)
	{
		const BuildingClass &building = *iter;
		if( ((!Me) || (Me != building.BuildingObject)) && // It's not itself, if we passed in a handle.
			((Team < 0) || (TeamFilterCheck(NewTeamFilter, Team, UsePTeam ? building.PTeam : building.CurTeamNum))) && // Team Filter matches.
			((!IgnoreInvincible) || (building.MaxHealth > 0)) && // Health matches.
			((!ObeyIdleVictim) || (building.CanBeIdleVictim)) &&
			(
			((NewMatchMask & MatchMask_Category) == MatchMask_Category) ||
			(((NewMatchMask & MatchMask_ObjClass) == MatchMask_ObjClass) && (ObjClass) && (building.ObjClassHash == ObjClassHash)) ||
			(((NewMatchMask & MatchMask_ODFName) == MatchMask_ODFName) && (ODFName) && (building.ODFNameHash == ODFNameHash))
			))
		{
			float DistSquared = GetDistance3DSquared(building.Position, Position);
			if (BestDistSquared > DistSquared) // It is closer then our last found Handle.
			{
				BestDistSquared = DistSquared;
				TempH = building.BuildingObject;
			}
		}
	}

	return TempH;
}

// DECOMPILE: no procedure of its own in any shipped DLL (never called); forwards to the Vector version.
Handle BuildingHelper::GetNearestServiceObject(const int ServiceMask, const Matrix Position, const float MaxRange, const int Team, const int TeamFilter, const bool UsePTeam, const bool IgnoreInvincible, const bool ObeyIdleVictim, const int MatchMask, const char *ObjClass, const char *ODFName)
{
	return GetNearestServiceObject(ServiceMask, Position.posit, MaxRange, Team, TeamFilter, UsePTeam, IgnoreInvincible, ObeyIdleVictim, 0, MatchMask, ObjClass, ODFName);
}

// DECOMPILE: no procedure of its own in any shipped DLL (never called); forwards to the Vector version.
Handle BuildingHelper::GetNearestServiceObject(const int ServiceMask, const Handle h, const float MaxRange, const int Team, const int TeamFilter, const bool UsePTeam, const bool IgnoreInvincible, const bool ObeyIdleVictim, const int MatchMask, const char *ObjClass, const char *ODFName)
{
	if(!IsAround(h))
		return 0;

	return GetNearestServiceObject(ServiceMask, GetPosition(h), MaxRange, Team, TeamFilter, UsePTeam, IgnoreInvincible, ObeyIdleVictim, h, MatchMask, ObjClass, ODFName);
}

// DECOMPILE: no procedure of its own in any shipped DLL (never called); forwards to the Vector version.
Handle BuildingHelper::GetNearestServiceObject(const int ServiceMask, const Name Path, const int Point, const float MaxRange, const int Team, const int TeamFilter, const bool UsePTeam, const bool IgnoreInvincible, const bool ObeyIdleVictim, const int MatchMask, const char *ObjClass, const char *ODFName)
{
	if(!DoesPathExist(Path))
		return 0;

	return GetNearestServiceObject(ServiceMask, GetVectorFromPath(Path, Point), MaxRange, Team, TeamFilter, UsePTeam, IgnoreInvincible, ObeyIdleVictim, 0, MatchMask, ObjClass, ODFName);
}

// VSR: the nearest service powerup of the asked kind, or the nearest building. The shipped body filters the powerups by ServiceMask only and the buildings
// by nothing at all: every call site (DispatchHelper) passes Team -1 / Me 0, so the Team and Me tests below are reconstructed and fold away there, and
// IgnoreInvincible / ObeyIdleVictim / MatchMask / ObjClass / ODFName are accepted for the family's shape but never read (they are not in the shipped body).
Handle BuildingHelper::GetNearestServiceObject(const int ServiceMask, const Vector Position, const float MaxRange, const int Team, const int TeamFilter, const bool UsePTeam, const bool /*IgnoreInvincible*/, const bool /*ObeyIdleVictim*/, const Handle Me, const int /*MatchMask*/, const char * /*ObjClass*/, const char * /*ODFName*/)
{
	const int NewTeamFilter = TeamFilter ? TeamFilter : -1;
	Handle TempH = 0;

	float BestDistSquared = MaxRange <= 0 ? FLT_MAX : Squared(MaxRange); // Start out with MaxRange, or infinite.
	for (int p = 0; p < PowerupHelper::Get().GetNumPowerupObjects(); p++)
	{
		PowerupHelper::PowerupClass powerupInfo = PowerupHelper::Get().GetPowerupInfo(p);
		if ((((ServiceMask & 1) != 0) && (powerupInfo.HealthUp != 0)) ||
			(((ServiceMask & 2) != 0) && (powerupInfo.AmmoUp != 0)) ||
			(((ServiceMask & 4) != 0) && (powerupInfo.LocalAmmoUp != 0)))
		{
			float DistSquared = GetDistance3DSquared(Position, powerupInfo.Position);
			if (DistSquared < BestDistSquared)
			{
				BestDistSquared = DistSquared;
				TempH = powerupInfo.PowerupObject;
			}
		}
	}

	for (std::vector<BuildingClass>::const_iterator iter = BuildingList.begin(); iter != BuildingList.end(); ++iter)
	{
		const BuildingClass &building = *iter;
		if( ((!Me) || (Me != building.BuildingObject)) && // It's not itself, if we passed in a handle.
			((Team < 0) || (TeamFilterCheck(NewTeamFilter, Team, UsePTeam ? building.PTeam : building.CurTeamNum))) ) // Team Filter matches.
		{
			float DistSquared = GetDistance3DSquared(building.Position, Position);
			if (DistSquared < BestDistSquared)
			{
				BestDistSquared = DistSquared;
				TempH = building.BuildingObject;
			}
		}
	}

	return TempH;
}
