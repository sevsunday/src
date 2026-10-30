// PROVENANCE: ancestor reference/ancestor-bz1helper-2015/Shared/DispatchHelper.cpp @6fda4f5 (the dispatch types / states, the turret / patrol / minelayer / hunter / escort logic, flee, service, cloaking) | decompile reference/decompiled/strategy02-ghidra12.2/src/missions/vsrcore/dispatchhelper.cpp.decomp.c (PostLoad 40-65, AddToDispatch 68-368, DeleteDispatchObject 371-394, Execute 397-1857, PreOrdnanceHit 1860-1939, ReadChanceValues 1942-1948, Cloak 1952-2027, Decloak 2029-2076, ClearDispatch 2174-2183; Load / Save inlined into BZ1Helper) + dumpbin of 4fc208a9 / 4fc2375b for the register-passed arguments (GetRandomTeam, GetRandomInt, the Near flag of every GetPositionNearOrFar, the loop bounds) | status: ported
#include "bz1helper.h"
#include "dispatchhelper.h"
#include "buildinghelper.h"
#include "scraphelper.h"
#include "utilityshiphelper.h"
#include "morphobjecthelper.h"
#include "bzcscriptutils.h"
#include <algorithm>

DispatchHelper *DispatchHelper::m_DispatchHelper;

std::vector<DispatchHelper::DispatchClass> TempDispatchBuffer; // GBD: the list as it stood before a Load, for PostLoad's resync report.

DispatchHelper::DispatchHelper()
{
	m_DispatchHelper = this;
}
DispatchHelper::~DispatchHelper()
{
	m_DispatchHelper = NULL;
}

bool DispatchHelper::Load(bool missionSave)
{
	if (!missionSave)
	{
		TempDispatchBuffer = DispatchList;

		int size = 0;
		bool ret = Read(&size, 1);
		DispatchList.resize(size);
		if(size)
			ret = ret && Read(&DispatchList.front(), sizeof(DispatchClass)*size);
		return ret;
	}
	return true;
}

bool DispatchHelper::PostLoad(bool missionSave)
{
	if (!missionSave)
	{
		for (std::vector<DispatchClass>::iterator iter = DispatchList.begin(); iter != DispatchList.end(); ++iter)
		{
			DispatchClass &sao = *iter;
			ConvertHandles(&sao.DispatchObject, 1);
			ConvertHandles(&sao.DispatchTarget, 1);
			ConvertHandles(&sao.FleeTarget, 1);
		}

		// GBD: resync report — compare what we had against what we loaded.
		if (TempDispatchBuffer.size() == DispatchList.size())
		{
			for (int i = 0; i < int(DispatchList.size()); i++)
			{
				if (!(TempDispatchBuffer[i] == DispatchList[i]))
				{
					FormatLogMessage("DispatchList Index Mismatch: %d", i);
					break;
				}
			}
		}
		else
		{
			FormatLogMessage("DispatchList Size Mismatch! Old: %d New: %d", TempDispatchBuffer.size(), DispatchList.size());
		}
	}
	return true;
}

bool DispatchHelper::Save(bool missionSave)
{
	if (!missionSave)
	{
		int size = int(DispatchList.size());
		bool ret = Write(&size, 1);
		if(size)
			ret = ret && Write(&DispatchList.front(), sizeof(DispatchClass)*size);
		return ret;
	}
	return true;
}

bool DispatchHelper::AddToDispatch(const Handle h, const float IdleTime, const bool SkipAIPCheck, const int CloakPriority, const bool CanFlee, const bool CloakNow, const bool Hunt, const bool CanGetService)
{
	char ObjClass[MAX_ODF_LENGTH] = {0};
	if(!GetObjInfo(h, Get_GOClass, ObjClass))
		return false; // Invalid Handle, bail.

	unsigned int ObjClassHash = Hash(ObjClass);

	char TempODF1[MAX_ODF_LENGTH] = {0};
	char TempODF2[MAX_ODF_LENGTH] = {0};
	GetAndOpenODFNames(h, TempODF1, TempODF2);

	// Flag to disable dispatch entirely.
	bool DoDispatch = true;
	GetODFBool(TempODF1, TempODF2, "CraftClass", "DoDLLDispatch", &DoDispatch, true);
	if (!DoDispatch)
		return false; // Don't dispatch this object esplicity.

	const char * Label = GetLabel(h);
	if((Label) && (_strnicmp(Label,"nodispatch",10) == 0))
		return false;

	// Grab out the ODF, and look inside it. Pull out all vars we might need. -GBD
	char BZCClass[MAX_ODF_LENGTH] = {0};
	GetODFString(TempODF1, TempODF2, "GameObjectClass", "BZCClasslabel", MAX_ODF_LENGTH, BZCClass);
	unsigned int BZCClassHash = Hash(BZCClass);

	// Skip this object if it isn't a valid class to dispatch. (If it doesn't do dispatchy stuff)
	if((ObjClassHash != CLASS_AIR) && (ObjClassHash != CLASS_MORPHTANK) && (ObjClassHash != CLASS_WINGMAN) &&
		(ObjClassHash != CLASS_ASSAULTHOVER) && (ObjClassHash != CLASS_ASSAULTTANK) && (ObjClassHash != CLASS_SAV) &&
		(ObjClassHash != CLASS_TURRETTANK) && (ObjClassHash != CLASS_MINELAYER) && (ObjClassHash != CLASS_WALKER) &&
		(ObjClassHash != CLASS_ARTILLERY) && (ObjClassHash != CLASS_HOWITZER)) // Include Howitzers for AI sending them ammo.
		return false; // Skip it.
	if (BZCClassHash == BZCCLASS_APC) // Skip APCs.
		return false;

	// If we got this far, DoDispatch is true.
	for (std::vector<DispatchClass>::iterator iter = DispatchList.begin(); iter != DispatchList.end(); ++iter)
	{
		if(iter->DispatchObject == h)
			return false;
	}

	DispatchList.resize(DispatchList.size()+1);
	DispatchClass &sao = DispatchList[DispatchList.size()-1]; // No temporary being created, *much* faster
	memset(&sao, 0, sizeof(DispatchClass)); // Zero things out at start.

	// Pull out this unit's _config.odf.
	const char *BaseODFName = GetConfigODF(h);

	// Does this unit do stuff even if no AIP is running?
	sao.SkipAIPCheck = SkipAIPCheck;
	sao.MaxHealth = GetMaxHealth(h);
	sao.MaxAmmo = GetMaxAmmo(h);

	int Team = GetTeamNum(h);
	BZ1Helper::TeamInfo &teamInfo = BZ1Helper::Get().RefTeamInfo(Team);
	bool AICloaker = true;
	float HuntChance = 0.0f;
	float PatrolChance = 0.0f;
	float SniperChance = 0.0f;
	float EscortChance = 0.0f;

	if (BaseODFName)
	{
		if (OpenODF2(BaseODFName))
		{
			// VSR: every difficulty slot is read, 5 down to 1, without stopping (the lowest slot present wins).
			char DesiredValue[MAX_ODF_LENGTH] = {0};
			for(int i = 5; i >= 1; i--)
			{
				// "<Difficulty>WeaponSlot%d" is the block the CPU reads its per-difficulty tuning from; an unknown difficulty keeps the previous name.
				if (teamInfo.m_CPUAIDifficulty == 1)
					sprintf_s(DesiredValue, "EasyWeaponSlot%d", i);
				else if (teamInfo.m_CPUAIDifficulty == 2)
					sprintf_s(DesiredValue, "MediumWeaponSlot%d", i);
				else if (teamInfo.m_CPUAIDifficulty == 3)
					sprintf_s(DesiredValue, "HardWeaponSlot%d", i);
				else if (teamInfo.m_CPUAIDifficulty == 4)
					sprintf_s(DesiredValue, "ExtremeWeaponSlot%d", i);
				GetODFFloat(BaseODFName, DesiredValue, "AIHuntChance", &HuntChance, 0.0f);
				GetODFFloat(BaseODFName, DesiredValue, "AIPatrolChance", &PatrolChance, 0.0f);
				GetODFFloat(BaseODFName, DesiredValue, "AISniperChance", &SniperChance, 0.0f);
				GetODFFloat(BaseODFName, DesiredValue, "AIEscortChance", &EscortChance, 0.0f);
				GetODFFloat(BaseODFName, DesiredValue, "AIRepairHealthRatio", &sao.GetRepairRatio, 0.15f); // 15% default.
				GetODFFloat(BaseODFName, DesiredValue, "AIServiceChance", &sao.ServiceChance, 0.0f); // 0% chance default.
			}
			ReadChanceValues(BaseODFName, "CloakChances", sao.CloakChance, 0.0f);
		}
		HuntChance = clamp(HuntChance, 0.0f, 1.0f);
	}
	PatrolChance = clamp(PatrolChance, 0.0f, 1.0f);
	SniperChance = clamp(SniperChance, 0.0f, 1.0f);
	EscortChance = clamp(EscortChance, 0.0f, 1.0f);

	// Decide which type of unit this will be.
	if(ObjClassHash == CLASS_TURRETTANK)
	{
		sao.DispatchType = DispatchType_Turret;
	}
	else if(BZCClassHash == BZCCLASS_MINELAYER)
	{
		sao.DispatchType = DispatchType_Minelayer;
	}
	else if((ObjClassHash == CLASS_ARTILLERY) || (ObjClassHash == CLASS_HOWITZER))
	{
		sao.DispatchType = DispatchType_Howitzer; // Only influences how these ships get Reload/Repair atm.
	}
	else if ((Hunt) || ((Label) && (_strnicmp(Label,"hunter",6) == 0)))
	{
		sao.DispatchType = DispatchType_Hunter;
	}
	else if ((Label) && (_strnicmp(Label,"patrol",6) == 0))
	{
		sao.DispatchType = DispatchType_Patrol;
	}
	else if ((Label) && (_strnicmp(Label,"escort",6) == 0))
	{
		sao.DispatchType = DispatchType_Escort;
	}
	else // If the above didn't catch anything, pick randomly.
	{
		int Choice = GetRandomInt(0, 2);

		switch (Choice)
		{
			case  0: // First try Hunter.
			{
				if(GetRandomFloat(1.0f) < HuntChance)
					sao.DispatchType = DispatchType_Hunter;
				else if(GetRandomFloat(1.0f) < PatrolChance)
					sao.DispatchType = DispatchType_Patrol;
				else if(GetRandomFloat(1.0f) < EscortChance)
					sao.DispatchType = DispatchType_Escort;
			}
			break;
			case  1: // Next try Patrol.
			{
				if(GetRandomFloat(1.0f) < PatrolChance)
					sao.DispatchType = DispatchType_Patrol;
				else if(GetRandomFloat(1.0f) < HuntChance)
					sao.DispatchType = DispatchType_Hunter;
				else if(GetRandomFloat(1.0f) < EscortChance)
					sao.DispatchType = DispatchType_Escort;
			}
			break;
			case  2: // Finally, try Escort.
			{
				if(GetRandomFloat(1.0f) < EscortChance)
					sao.DispatchType = DispatchType_Escort;
				else if(GetRandomFloat(1.0f) < HuntChance)
					sao.DispatchType = DispatchType_Hunter;
				else if(GetRandomFloat(1.0f) < PatrolChance)
					sao.DispatchType = DispatchType_Patrol;
			}
			break;
		}
	}

	// Will it Snipe?
	if(GetRandomFloat(1.0f) < SniperChance)
	{
		char PilotODF[MAX_ODF_LENGTH] = {0};
		sprintf_s(PilotODF, "%csuser", GetRace(h));
		SetPilotClass(h, PilotODF);
	}

	// Claoker?
	GetODFBool(TempODF1, TempODF2, "MorphTankClass", "HiddenWhenMorphed", &sao.IsCloaker, false);
	// Flag to disable AI cloaking. (VSR: defaults to the cloaker flag itself.)
	GetODFBool(TempODF1, TempODF2, "CraftClass", "CanAICloak", &AICloaker, sao.IsCloaker);
	if(!AICloaker)
		sao.IsCloaker = false;

	// Get the deploy time for how long it takes to cloak.
	GetODFFloat(TempODF1, TempODF2, "DeployableClass", "timeDeploy", &sao.TimeDeploy, 5.0f);

	// Does it flee? // Only these classes can flee. (hovercraft derived)
	if( (ObjClassHash == CLASS_WINGMAN) ||
		(ObjClassHash == CLASS_MORPHTANK) ||
		(ObjClassHash == CLASS_ASSAULTHOVER) ||
		(ObjClassHash == CLASS_AIR))
	{
		GetODFBool(TempODF1, TempODF2, "CraftClass", "CanAIFlee", &sao.CanFlee, CanFlee);
		if(sao.CanFlee) // Flee Minimum Health Lost Ratio.
			GetODFFloat(TempODF1, TempODF2, "CraftClass", "AIFleeHealthRatio", &sao.FleeHealthRatio, 0.75f);
	}
	else
	{
		sao.CanFlee = false; // Nope, doesn't Flee.
	}

	// If the AIP is set to UnitsService, or the dispatch caller specifically set it.
	if((teamInfo.m_CPUUnitsCanService) || (CanGetService))
	{
		// Can this unit automatically repair?
		GetODFBool(TempODF1, TempODF2, "CraftClass", "CanAIRepair", &sao.CanGetRepair, sao.MaxHealth != 0);
		// Can this unit automatically reload?
		GetODFBool(TempODF1, TempODF2, "CraftClass", "CanAIReload", &sao.CanGetReload, sao.MaxAmmo != 0);
	}

	if(_stricmp(BZCClass, "morphobject") == 0)
	{
		sao.IsMorpher = true;
		GetODFBool(TempODF1, TempODF2, "MorphObjectClass", "MorphIsAssault", &sao.MorphIsAssault, true);
	}

	sao.GetRepairRatio = clamp(sao.GetRepairRatio, 0.0f, 1.0f);
	sao.ServiceChance = clamp(sao.ServiceChance, 0.0f, 1.0f);

	sao.DispatchObject = h; // Add the object to the list.
	sao.FleeHealthValue = GetCurHealth(h);
	sao.EngageRange = GetEngageRange(h);
	sao.IdleTime = (BZ1Helper::m_TurnCounter + SecondsToTurns(IdleTime));
	sao.ServiceTimer = SecondsToTurns(10.0f);
	sao.CloakPriority = CloakPriority;
	sao.CurrTeam = Team;

	if(sao.IsCloaker)
	{
		if(CloakNow)
			Cloak(h, CloakPriority);
		else
			sao.CloakIdleTime = (BZ1Helper::m_TurnCounter + SecondsToTurns(IdleTime));
	}

	return true;
}

void DispatchHelper::DeleteDispatchObject(Handle h, int Team)
{
	BZ1Helper::TeamInfo &teamInfo = BZ1Helper::Get().RefTeamInfo(Team);

	for (std::vector<DispatchClass>::iterator iter = DispatchList.begin(); iter != DispatchList.end(); ++iter)
	{
		if(iter->DispatchObject == h)
		{
			switch (iter->DispatchType)
			{
			case DispatchType_Patrol:
				--teamInfo.m_CPUNumPatrolUnits;
				break;
			case DispatchType_Hunter:
				--teamInfo.m_CPUNumHuntUnits;
				break;
			case DispatchType_Escort:
				--teamInfo.m_CPUNumEscortUnits;
				break;
			}
			return;
		}
	}
}

void DispatchHelper::Execute(BZ1Helper &bz1Helper)
{
	const bool Logging = BZ1Helper::Logging;

	// These should be stationary for this run.
	const int numObjects = bz1Helper.GetNumHandles();
	const int numBuildings = BuildingHelper::Get().GetNumBuildingObjects();

	// Daywreckers: the CPU's armory drops one on a random enemy building that one of its units can see.
	for(int Team = 0; Team<MAX_TEAMS; Team++)
	{
		BZ1Helper::TeamInfo &teamInfo = bz1Helper.RefTeamInfo(Team);
		if ((teamInfo.m_CPUDayWreckerChance == 0.0f) || (!teamInfo.TeamAIPFile[0]) || (!teamInfo.Armory))
			continue;
		if (BZ1Helper::m_TurnCounter % SecondsToTurns(teamInfo.m_CPUDayWreckerInterval) != 0)
			continue;
		if (GetRandomFloat(1.0f) >= teamInfo.m_CPUDayWreckerChance)
			continue;

		char DayWreckerODF[MAX_ODF_LENGTH] = {0};
		if (!GetBuildItem(teamInfo.Armory, DayWreckerODF, NULL, 4, "daywrecker"))
			continue;
		if (GetScrap(Team) < 0)
			continue;
		if (!DoesODFExist(DayWreckerODF))
			continue;
		// This is a valid target team! Lock onto one of their stuffs...
		if (BuildingHelper::Get().GetNumBuildings(Team, TeamFilter_Enemies, false, true, false, 0, NULL, NULL) <= 0)
			continue;

		// Choose a target.
		Handle TempTarget = BuildingHelper::Get().GetRandomBuilding(Team, TeamFilter_Enemies, true, true, true, 0, NULL, NULL, 0.0f, Vector(0.0f, 0.0f, 0.0f));
		const Vector TargetPos = GetPosition(TempTarget);
		for(int i = 0; i < numObjects; i++)
		{
			const ObjectHelper::ObjectClass &objectInfo = bz1Helper.GetHandleInfo(i);
			if((objectInfo.CurTeamNum == Team) && (GetDistance3DSquared(TargetPos, objectInfo.Position) < Squared(objectInfo.EngageRange)))
			{
				bz1Helper.BuildAt(teamInfo.Armory, DayWreckerODF, TargetPos, 1);
				break;
			}
		}
	}

	// pre-clean the vector
	DispatchList.erase(std::remove_if(DispatchList.begin(), DispatchList.end(), ShouldRemoveDispatch), DispatchList.end());

	// Turrets, randomly go to either A: Near Our Base, B: Scrap Fields, or C: Near Enemy Base. Units, just pick a random target.
	for (std::vector<DispatchClass>::iterator iter = DispatchList.begin(); iter != DispatchList.end(); ++iter)
	{
		const int DispatchIndex = int(iter - DispatchList.begin());
		const int Team = GetTeamNum(iter->DispatchObject);
		BZ1Helper::TeamInfo &teamInfo = bz1Helper.RefTeamInfo(Team);
		const Vector Position = GetPosition(iter->DispatchObject);
		const bool TargetAround = IsAround(iter->DispatchTarget);
		const bool Independent = GetIndependence(iter->DispatchObject) != 0;
		const Handle Who = GetCurrentWho(iter->DispatchObject);

		// VSR: a unit that changed team takes its Patrol / Hunt / Escort slot with it and starts over.
		if (iter->CurrTeam != Team)
		{
			BZ1Helper::TeamInfo &oldInfo = bz1Helper.RefTeamInfo(iter->CurrTeam);
			switch (iter->DispatchType)
			{
			case DispatchType_Patrol:
				--oldInfo.m_CPUNumPatrolUnits;
				++teamInfo.m_CPUNumPatrolUnits;
				break;
			case DispatchType_Hunter:
				--oldInfo.m_CPUNumHuntUnits;
				++teamInfo.m_CPUNumHuntUnits;
				break;
			case DispatchType_Escort:
				--oldInfo.m_CPUNumEscortUnits;
				++teamInfo.m_CPUNumEscortUnits;
				break;
			}
			ClearDispatch(DispatchIndex);
			iter->CurrTeam = Team;
		}

		if (IsPlayer(iter->DispatchObject))
			continue;

		// The dispatch and service logic runs for CPU teams only, and leaves alone a unit a script took control of (unless it is fleeing).
		if ((GetPlayerHandle(Team) == 0) && ((Independent) || (iter->DispatchState == DispatchState_Flee)))
		{
			switch (iter->DispatchState)
			{
			case DispatchState_Idle:
				{
					// If it's idle timer's up, and it's not currently doing something, lets figure out what to tell it to do.
					if( (iter->IdleTime <= BZ1Helper::m_TurnCounter) &&
						(IsIdle(iter->DispatchObject)) &&
						((iter->SkipAIPCheck) || (teamInfo.m_CPUDoDispatch)))
					{
						switch (iter->DispatchType)
						{
						case DispatchType_Turret:
							{
								// If it's a Turret, and there are no enemies nearby.
								const Handle Enemy = GetNearestEnemy(iter->DispatchObject);
								const Vector EnemyPos = GetPosition(Enemy);
								if (GetDistance2DSquared(Position, EnemyPos) <= Squared(iter->EngageRange + 25.0f))
									break;

								/*
								Type 0: Friendly Base Defence.
								- Method 0: Furthest away building.
								- Method 1: Random friendly building.
								- Method 2: Random base slot building (recy/fact/armory)
								Type 1: Goto Scrap.
								- Method 0: Closest.
								- Method 1: Random.
								- Method 2: Farthest.
								Type 2: Siege Enemy Base.
								- Method 0: Closest enemy building.
								- Method 1: Random Enemy building.
								- Method 2: Enemy base slot building.
								*/
								const int DispatchMode = GetRandomInt(0, 2);
								const int DispatchMethod = GetRandomInt(0, 2);
								iter->DispatchTarget = 0; // Don't save a target to compare distance to for base defence.
								Handle TempTarget = 0;

								// VSR: an enemy team's production unit anchors the spot selection (defend the side facing it, or siege it).
								int RandomTeam = GetRandomTeam(TeamFilter_Enemies, Team, true, true);
								if (RandomTeam < 0)
									RandomTeam = GetRandomTeam(TeamFilter_Enemies, Team, false, true);
								if (RandomTeam < 0)
									RandomTeam = 0;
								Vector ProdPos(0.0f, 0.0f, 0.0f);
								const BZ1Helper::TeamInfo &randomInfo = bz1Helper.RefTeamInfo(RandomTeam);
								Handle ProdUnit = randomInfo.Recycler;
								if (!ProdUnit)
									ProdUnit = randomInfo.Factory;
								if (!ProdUnit)
									ProdUnit = randomInfo.Constructor;
								if (!ProdUnit)
									ProdUnit = randomInfo.Armory;
								if (ProdUnit)
									ProdPos = GetPosition(ProdUnit);

								if(Logging)
									FormatLogMessage("Index is: %d, DispatchMode is: %d, DispatchMethod is: %d, RandomTargetTeam: %d", DispatchIndex, DispatchMode, DispatchMethod, RandomTeam);

								switch (DispatchMode)
								{
								case 0: // Friendly Base Guard Duty. Find a spot near edge of base.
									{
										// Choose the type of defence selection. A: Furthest, B: Random Building, or C: Random Production Unit.
										switch (DispatchMethod)
										{
										case  0: // Select based on Furthest Away. (Each building has a 50% chance of being considered, so turrets spread out.)
											{
												float TempDist = 0.0f; //Start off small, we're looking for further away.
												for(int b = 0; b < numBuildings; b++)
												{
													if ((numBuildings > 1) && (GetRandomFloat(1.0f) >= 0.5f))
														continue;
													const BuildingHelper::BuildingClass buildingInfo = BuildingHelper::Get().GetBuildingInfo(b);
													if((buildingInfo.CurTeamNum == Team) && (buildingInfo.CanBeIdleVictim) && (buildingInfo.MaxHealth > 0))
													{
														const float DistSquared = GetDistance2DSquared(Position, buildingInfo.Position);
														if (TempDist < DistSquared) // This is a more desirable base "edge".
														{
															TempTarget = buildingInfo.BuildingObject;
															TempDist = DistSquared;
														}
													}
												}
											}
											break;
										case 1: // Select Random Friendly Building.
											TempTarget = BuildingHelper::Get().GetRandomBuilding(Team, TeamFilter_SameTeam, true, true, true, 0, NULL, NULL, 0.0f, Vector(0.0f, 0.0f, 0.0f));
											break;
										case 2: // Choose from Friendly Production Units.
											{
												TempTarget = teamInfo.Recycler;
												if (!TempTarget)
													TempTarget = teamInfo.Factory;
												if (!TempTarget)
													TempTarget = teamInfo.Constructor;
												if (!TempTarget)
													TempTarget = teamInfo.Armory;
												if (!TempTarget) // No production units? Pick random then.
													TempTarget = BuildingHelper::Get().GetRandomBuilding(Team, TeamFilter_SameTeam, true, true, true, 0, NULL, NULL, 0.0f, Vector(0.0f, 0.0f, 0.0f));
											}
											break;
										}

										if (!TempTarget)
										{
											iter->IdleTime = (BZ1Helper::m_TurnCounter + SecondsToTurns(5.0f));
											if(Logging)
												FormatLogMessage("Index is: %d Mode is: %d Method is: %d No Valid Target, IdleTime: %d", DispatchIndex, DispatchMode, DispatchMethod, iter->IdleTime);
											break;
										}

										if (!iter->DispatchTarget)
											iter->DispatchTarget = TempTarget;
										const Vector TargetPos = GetPosition(iter->DispatchTarget);
										iter->DispatchSpot = GetPositionNearOrFar(ProdPos, TargetPos, 50.0f, 250.0f, true);
										Goto(iter->DispatchObject, iter->DispatchSpot, 0);
										iter->RandomDist = GetRandomFloat(10.0f) + 10.0f;
										iter->IdleTime = 0; // Flag this to force one-time action.
										iter->DispatchState = DispatchState_Goto;

										if(Logging)
											FormatLogMessage("Index is: %d Mode is: %d Method is: %d Spot is: %f %f %f Target Is: '%s'", DispatchIndex, DispatchMode, DispatchMethod, iter->DispatchSpot.x, iter->DispatchSpot.y, iter->DispatchSpot.z, GetODFName(TempTarget));
									}
									break;
								case 1: // Scrap Field, Go to a position "near" a Random piece of Scrap. :)
									{
										float TempDist = FLT_MAX; //Start off big, we're looking for closest.
										const int NumScrap = ScrapHelper::Get().GetNumScrapObjects();

										switch (DispatchMethod)
										{
										case  0: // Select based on Closest. (50% chance per piece to be considered.)
											{
												for(int b = 0; b < NumScrap; b++)
												{
													if ((NumScrap > 1) && (GetRandomFloat(1.0f) >= 0.5f))
														continue;
													const Handle ScrapPiece = ScrapHelper::Get().RefScrapHandle(b);
													const float DistSquared = GetDistance2DSquared(Position, GetPosition(ScrapPiece));
													if (DistSquared < TempDist) // This scrap is closer.
													{
														iter->DispatchTarget = ScrapPiece;
														TempDist = DistSquared;
													}
												}
											}
											break;
										case 1: // Select Random Scrap to go to.
											{
												if (NumScrap > 0)
													iter->DispatchTarget = ScrapHelper::Get().RefScrapHandle(GetRandomInt(0, NumScrap-1));
											}
											break;
										case 2: // Choose based on furthest away.
											{
												TempDist = 0.0f; // Start off small, we're looking for Further away.
												for(int b = 0; b < NumScrap; b++)
												{
													if ((NumScrap > 1) && (GetRandomFloat(1.0f) >= 0.5f))
														continue;
													const Handle ScrapPiece = ScrapHelper::Get().RefScrapHandle(b);
													const float DistSquared = GetDistance2DSquared(Position, GetPosition(ScrapPiece));
													if (TempDist < DistSquared) // This scrap is further away.
													{
														iter->DispatchTarget = ScrapPiece;
														TempDist = DistSquared;
													}
												}
											}
											break;
										}

										iter->DispatchSpot = GetPositionNear(GetPosition(iter->DispatchTarget), 10.0f, 50.0f);

										if(Logging)
											FormatLogMessage("Index is: %d Mode is: %d Method is: %d Spot is: %f %f %f", DispatchIndex, DispatchMode, DispatchMethod, iter->DispatchSpot.x, iter->DispatchSpot.y, iter->DispatchSpot.z);

										if(IsNullVector(iter->DispatchSpot))
										{
											// Pick a random object.
											iter->DispatchTarget = bz1Helper.GetRandomObject(-1, 0, false, 0, false, true, true);
											iter->DispatchSpot = GetPositionNear(GetPosition(iter->DispatchTarget), 10.0f, 50.0f);
											if(Logging)
												FormatLogMessage("Pathing Failed, using random object. Index is: %d Mode is: %d Method is: %d Spot is: %f %f %f.", DispatchIndex, DispatchMode, DispatchMethod, iter->DispatchSpot.x, iter->DispatchSpot.y, iter->DispatchSpot.z);
										}

										Goto(iter->DispatchObject, iter->DispatchSpot, 0);
										iter->RandomDist = GetRandomFloat(50.0f) + 10.0f;
										iter->IdleTime = 0; // Flag this to force one-time action.
										iter->DispatchState = DispatchState_Goto;
									}
									break;
								case 2: // Enemy Base, pick their closest building...
									{
										float TempDist = FLT_MAX;

										switch (DispatchMethod)
										{
										case 0: // Select Closest Enemy Building. (50% chance per building to be considered.)
											{
												for(int b = 0; b < numBuildings; b++)
												{
													if ((numBuildings > 1) && (GetRandomFloat(1.0f) >= 0.5f))
														continue;
													const BuildingHelper::BuildingClass buildingInfo = BuildingHelper::Get().GetBuildingInfo(b);
													if((!IsTeamAllied(Team, buildingInfo.CurTeamNum)) && (buildingInfo.CanBeIdleVictim) && (buildingInfo.MaxHealth > 0))
													{
														const float DistSquared = GetDistance2DSquared(Position, buildingInfo.Position);
														if (DistSquared < TempDist) // This is a more desirable enemy base "edge".
														{
															TempTarget = buildingInfo.BuildingObject;
															TempDist = DistSquared;
														}
													}
												}
											}
											break;
										case 1: // Select Random Enemy Building.
											TempTarget = BuildingHelper::Get().GetRandomBuilding(Team, TeamFilter_Enemies, true, true, true, 0, NULL, NULL, 0.0f, Vector(0.0f, 0.0f, 0.0f));
											break;
										case 2: // Select the random enemy team's Production Unit, else any enemy building.
											{
												TempTarget = ProdUnit;
												if (!TempTarget)
													TempTarget = BuildingHelper::Get().GetRandomBuilding(Team, TeamFilter_Enemies, true, true, true, 0, NULL, NULL, 0.0f, Vector(0.0f, 0.0f, 0.0f));
											}
											break;
										}

										if (!TempTarget)
										{
											iter->IdleTime = (BZ1Helper::m_TurnCounter + SecondsToTurns(5.0f));
											if(Logging)
												FormatLogMessage("Index is: %d Mode is: %d Method is: %d No Valid Target, IdleTime: %d", DispatchIndex, DispatchMode, DispatchMethod, iter->IdleTime);
											break;
										}

										// Spice it up so all our turrets don't go to the same place: a random enemy building within 200 m of the one we picked.
										iter->DispatchTarget = BuildingHelper::Get().GetRandomBuilding(Team, TeamFilter_Enemies, true, true, true, 0, NULL, NULL, 200.0f, GetPosition(TempTarget));
										if (!iter->DispatchTarget)
											iter->DispatchTarget = TempTarget;
										const Vector TargetPos = GetPosition(iter->DispatchTarget);
										iter->DispatchSpot = GetPositionNearOrFar(Position, TargetPos, 50.0f, 250.0f, true);
										Goto(iter->DispatchObject, iter->DispatchSpot, 0);
										iter->RandomDist = GetRandomFloat(iter->EngageRange) + 100.0f;
										iter->IdleTime = 0; // Flag this to force one-time action.
										iter->DispatchState = DispatchState_Goto;

										if(Logging)
											FormatLogMessage("Index is: %d Mode is: %d Method is: %d Spot is: %f %f %f Target Is: '%s'", DispatchIndex, DispatchMode, DispatchMethod, iter->DispatchSpot.x, iter->DispatchSpot.y, iter->DispatchSpot.z, GetODFName(TempTarget));
									}
									break;
								} // End case statements.
							} // It's a Turret.
							break;
						case DispatchType_Patrol:
							{
								if((teamInfo.m_CPUMaxPatrolUnits > 0) && (teamInfo.m_CPUNumPatrolUnits < teamInfo.m_CPUMaxPatrolUnits))
								{
									++teamInfo.m_CPUNumPatrolUnits;

									const int NumPatrolPaths = int(bz1Helper.PatrolPathList[Team].size());
									if(NumPatrolPaths > 0)
									{
										// Choose a pathpoint, random out of "#Patrol*" where # is Team number and * is an index #, 1 - #, in order.
										const int Random = GetRandomInt(0, NumPatrolPaths-1);
										const char * PathName = bz1Helper.PatrolPathList[Team][Random];
										size_t NumPoints = 0;
										if((PathName) && (GetPathPoints(PathName, NumPoints, NULL), NumPoints != 0))
										{
											Patrol(iter->DispatchObject, PathName, 0);
											iter->DispatchState = DispatchState_Goto;
											iter->IdleTime = 0; // Never time out, use CMD to trigger release.

											if(Logging)
												FormatLogMessage("Index: %d sent to Patrol path: '%s', TurnCount: %d", DispatchIndex, PathName, BZ1Helper::m_TurnCounter);
										}
									}
									else // No patrol paths set, use dynamic Patrol between same-team buildings.
									{
										const float Chance = GetRandomFloat(1.0f);
										const Handle Target = BuildingHelper::Get().GetRandomBuilding(Team, (Chance < 0.2f) ? (TeamFilter_SameTeam + TeamFilter_Allies) : TeamFilter_SameTeam, true, true, true, 0, NULL, NULL, 0.0f, Vector(0.0f, 0.0f, 0.0f));

										if((Chance < 0.1f) || (!Target)) // 10% chance, or if the above search failed, Goto a random spot, 100m - 5x EngageRange away.
											iter->DispatchSpot = GetPositionNear(Position, 100.0f, 5 * iter->EngageRange);
										else // 90% chance Goto near a same-team/allied building.
											iter->DispatchSpot = GetPositionNear(GetPosition(Target), 50.0f, 100.0f);

										Goto(iter->DispatchObject, iter->DispatchSpot, 0);
										iter->DispatchState = DispatchState_Goto;
										iter->IdleTime = 0; // Never time out, use CMD to trigger release.

										if(Logging)
											FormatLogMessage("Index: %d sent to Dynamic Patrol Near Handle: %08x, ODF: '%s', Position: %f %f %f", DispatchIndex, Target, GetODFName(Target), iter->DispatchSpot.x, iter->DispatchSpot.y, iter->DispatchSpot.z);
									}
								}
							}// It's a patrol ship.
							break;
						case DispatchType_Minelayer:
							{
								const int NumMLayPaths = int(bz1Helper.MLayPathList[Team].size());
								if(NumMLayPaths > 0)
								{
									const int Random = GetRandomInt(0, NumMLayPaths-1);
									const char * PathName = bz1Helper.MLayPathList[Team][Random];
									size_t NumPoints = 0;
									if((PathName) && (GetPathPoints(PathName, NumPoints, NULL), NumPoints != 0))
									{
										iter->DispatchSpot = GetPositionNear(GetVectorFromPath(PathName, 0), 25.0f, 50.0f);

										if(Logging)
											FormatLogMessage("Index: %d sent to Lay Mines at path: '%s'", DispatchIndex, PathName);
									}
								}
								else // Dynamic Minelayer commands.
								{
									const int MineMode = GetRandomInt(0, 2);

									switch (MineMode)
									{
									case 0: // Friendly Base Guard Duty. Find a spot near edge of base.
										{
											const Handle EnemyBuilding = BuildingHelper::Get().GetRandomBuilding(Team, TeamFilter_Enemies, true, true, true, 0, NULL, NULL, 0.0f, Vector(0.0f, 0.0f, 0.0f));
											const Handle FriendlyBuilding = BuildingHelper::Get().GetRandomBuilding(Team, TeamFilter_SameTeam, true, true, true, 0, NULL, NULL, 0.0f, Vector(0.0f, 0.0f, 0.0f));
											iter->DispatchSpot = GetPositionNearOrFar(GetPosition(EnemyBuilding), GetPosition(FriendlyBuilding), 100.0f, 200.0f, true);
										}
										break;
									case 1: // Random Spot in Field.
										{
											const float MapDepth = bz1Helper.GetMapInfo().MapDepth;
											const float MapWidth = bz1Helper.GetMapInfo().MapWidth;
											iter->DispatchSpot = Vector(GetRandomFloat(-MapDepth, MapDepth), 0.0f, GetRandomFloat(-MapWidth, MapWidth));
											iter->DispatchSpot.y = TerrainFindFloor(iter->DispatchSpot.x, iter->DispatchSpot.z);
										}
										break;
									case 2: // Enemy Base Siege, near enemy.
										{
											const Handle EnemyBuilding = BuildingHelper::Get().GetRandomBuilding(Team, TeamFilter_Enemies, true, true, true, 0, NULL, NULL, 0.0f, Vector(0.0f, 0.0f, 0.0f));
											iter->DispatchSpot = GetPositionNearOrFar(Position, GetPosition(EnemyBuilding), 100.0f, 200.0f, true);
										}
										break;
									}

									if(Logging)
										FormatLogMessage("Index: %d sent to Dynamic Minelaying, DispatchState: %d, Position: %f %f %f", DispatchIndex, MineMode, iter->DispatchSpot.x, iter->DispatchSpot.y, iter->DispatchSpot.z);
								}

								if (!IsNullVector(iter->DispatchSpot))
								{
									Goto(iter->DispatchObject, iter->DispatchSpot, 0);
									iter->DispatchState = DispatchState_Goto;
									iter->IdleTime = (BZ1Helper::m_TurnCounter + SecondsToTurns(300.0f)); // Timeout after 5 minutes of travel.

									if(Logging) // sic: the shipped message for a spot that WAS found.
										FormatLogMessage("Index is: %d Minelayer No Valid Target, IdleTime: %d", DispatchIndex, iter->IdleTime);
								}
							}// Its a minelayer.
							break;
						case DispatchType_Hunter:
							{
								if((teamInfo.m_CPUMaxHuntUnits > 0) && (teamInfo.m_CPUNumHuntUnits < teamInfo.m_CPUMaxHuntUnits))
								{
									++teamInfo.m_CPUNumHuntUnits;

									SetCommand(iter->DispatchObject, CMD_HUNT, 0);
									iter->DispatchState = DispatchState_Goto;
									iter->IdleTime = (BZ1Helper::m_TurnCounter + SecondsToTurns(300.0f)); // Timeout after 5 minutes of travel.

									if(Logging)
										FormatLogMessage("Index: %d Hunt Task Starting, Hunt Command issued. IdleTime: %d", DispatchIndex, iter->IdleTime);
								}
							}// Its an Hunt unit.
							break;
						case DispatchType_Escort:
							{
								if((teamInfo.m_CPUMaxEscortUnits > 0) && (teamInfo.m_CPUNumEscortUnits < teamInfo.m_CPUMaxEscortUnits))
								{
									// Pick a random object to Escort.
									iter->DispatchTarget = UtilityShipHelper::Get().GetEscortTarget(Team, TeamFilter_SameTeam + TeamFilter_Allies);

									if(iter->DispatchTarget)
									{
										Defend2(iter->DispatchObject, iter->DispatchTarget, 0);
										iter->DispatchState = DispatchState_Goto;
										iter->IdleTime = 0; // Never time out, use CMD to trigger release.

										if(Logging)
											FormatLogMessage("Index: %d Escort Task Starting, Target: '%s'", DispatchIndex, GetODFName(iter->DispatchTarget));

										++teamInfo.m_CPUNumEscortUnits;
									}
								}
							}// It's an escort unit.
							break;
						} // End Switch DispatchType.
					} // Idle timer is up. (And AIP is Running OR SkipAIP is true)
				}
				break;
			case DispatchState_Goto: // It's doing something, track when it's there.
				{
					// Special case for Turrets, they might get interrupted en-route.
					if(iter->DispatchType == DispatchType_Turret)
					{
						// If Timeout was never set, Set it once we undeploy and get moving, else watch for us to get interrupted.
						if((!iter->IdleTime) && (!IsDeployed(iter->DispatchObject)))
							iter->IdleTime = (BZ1Helper::m_TurnCounter + SecondsToTurns(300.0f)); // Timeout after 5 minutes of travel.
						else if((iter->IdleTime) && (IsDeployed(iter->DispatchObject)))
							iter->DispatchState = DispatchState_Idle; // It got interrupted.
					}

					if((iter->SkipAIPCheck) || (teamInfo.m_CPUDoDispatch))
					{
						// If this unit's timeout has passed, re-dispatch it.
						if((iter->IdleTime > 0) && (iter->IdleTime <= BZ1Helper::m_TurnCounter))
							ClearDispatch(DispatchIndex);

						switch (iter->DispatchType)
						{
						case DispatchType_Turret:
							{
								if (IsDeployed(iter->DispatchObject))
									break;

								bool Stop = false;
								bool Return = false;
								// If it encounters enemy building's early, stop here.
								for(int p = 0; p < numObjects; p++)
								{
									const ObjectHelper::ObjectClass &objectInfo = bz1Helper.GetHandleInfo(p);
									Handle TempH = objectInfo.ObjectHandle;

									if( (!IsTeamAllied(Team, objectInfo.CurTeamNum)) && // It's an Enemy.
										((objectInfo.CategoryID == CategoryType_Building) || ((objectInfo.ObjClassHash == unsigned int(CLASS_TURRETTANK)) && (IsDeployed(TempH)))) && // It's a Building or a Deployed Turret.
										(GetDistance2DSquared(Position, objectInfo.Position) < Squared(objectInfo.EngageRange + 25.0f))) // We're close, stop here.
									{
										Stop = true;
										// 50% chance that it will decide to go someplace else instead.
										if(GetRandomFloat(1.0f) < 0.5f)
											Return = true;

										if(Logging)
											FormatLogMessage("Index: %d Turret Encountered an Enemy on Team: %d Distance Is: %f, Return is: %d", DispatchIndex, objectInfo.CurTeamNum, GetDistance(iter->DispatchObject, TempH), Return);

										break;
									}
								}

								// If our target is around and we're within randomDist+5, or we encountered an enemy.
								if(((TargetAround) && (GetDistance2DSquared(Position, iter->DispatchSpot) <= Squared(iter->RandomDist + 5.0f))) || (Stop))
								{
									if(Return)
									{
										ClearDispatch(DispatchIndex);
									}
									else
									{
										if(Stop)
										{
											iter->DispatchSpot = GetPositionNear(Position, 10.0f, 30.0f);
											Goto(iter->DispatchObject, iter->DispatchSpot, 0);

											if(Logging)
												FormatLogMessage("Index is: %d Spot is: %f %f %f", DispatchIndex, iter->DispatchSpot.x, iter->DispatchSpot.y, iter->DispatchSpot.z);
										}
										else
										{
											Defend(iter->DispatchObject, 0); // Sit here until I decide to tell you otherwise.
										}
										iter->DispatchState = DispatchState_Idle;
										iter->IdleTime = (BZ1Helper::m_TurnCounter + SecondsToTurns(300.0f)); // Wait 5 minutes before trying to move again.

										if(Logging)
											FormatLogMessage("Index is: %d Turret Encountered an Enemy, IdleTime: %d", DispatchIndex, iter->IdleTime);
									}
								}
							} // It's a turret.
							break;
						case DispatchType_Patrol:
							{
								if(IsIdle(iter->DispatchObject))
								{
									if(bz1Helper.PatrolPathList[Team].empty())
									{
										iter->IdleTime = 0; // Throw it back on the pile...

										if(Logging)
											FormatLogMessage("Index: %d sent to Dynamic Patrol Reset, Cmd == CMD_NONE", DispatchIndex);
									}
									else // Unit got interrupted on path-based Patrol, reset it.
									{
										iter->IdleTime = (BZ1Helper::m_TurnCounter + SecondsToTurns(15.0f)); // Wait 15 seconds before trying to move again.

										if(Logging)
											FormatLogMessage("Patrol Unit %d interrupted, resetting idle timer. TurnCount: %d, IdleTime: %d", DispatchIndex, BZ1Helper::m_TurnCounter, iter->IdleTime);
									}

									iter->DispatchState = DispatchState_Idle;
								}
							}// Its a patrol ship.
							break;
						case DispatchType_Minelayer:
							{
								// We're here. Activate mining beams!  EVE Online referance. :P
								if(GetDistance2DSquared(Position, iter->DispatchSpot) < Squared(10.0f))
								{
									SetCommand(iter->DispatchObject, CMD_LAY_MINES, 0);
									iter->DispatchState = DispatchState_Idle;
									iter->IdleTime = (BZ1Helper::m_TurnCounter + SecondsToTurns(300.0f)); // Wait 5 minutes before trying to move again.

									if(Logging)
										FormatLogMessage("Index: %d Minelayer reached Spot: %f %f %f, laying mines..., IdleTime: %d", DispatchIndex, iter->DispatchSpot.x, iter->DispatchSpot.y, iter->DispatchSpot.z, iter->IdleTime);
								}
							}// Its a minelayer.
							break;
						case DispatchType_Hunter:
							{
								if(IsIdle(iter->DispatchObject)) // It's not doing anything, reset Hunt.
								{
									SetCommand(iter->DispatchObject, CMD_HUNT, 0);
									iter->IdleTime = (BZ1Helper::m_TurnCounter + SecondsToTurns(300.0f)); // Wait 5 minutes before trying to move again.

									if(Logging)
										FormatLogMessage("Index: %d Hunt Task Continuing, Re-Issueing Hunt Command. IdleTime: %d", DispatchIndex, iter->IdleTime);
								}
							}// Its a hunt unit.
							break;
						case DispatchType_Escort: // If this unit was told to Escort a scavenger (or minelayer?) Do it.
							{
								if(!TargetAround) // Uh Oh, you Escort Target Died! Do something!
								{
									// Go escort again.
									if(GetRandomFloat(1.0f) < 0.5f)
									{
										iter->DispatchTarget = UtilityShipHelper::Get().GetEscortTarget(Team, TeamFilter_SameTeam + TeamFilter_Allies);
										Defend2(iter->DispatchObject, iter->DispatchTarget, 0);

										if(Logging)
											FormatLogMessage("Index: %d Escort Target lost, picking new Target: '%s'", DispatchIndex, GetODFName(iter->DispatchTarget));
									}
									else // Do something else.
									{
										iter->DispatchType = DispatchType_None;
										ClearDispatch(DispatchIndex);
										--teamInfo.m_CPUNumEscortUnits;
										// Go attack the nearest thing, chances are it's what killed your escort target, Bezerk mode. :)
										Attack(iter->DispatchObject, GetNearestEnemy(iter->DispatchObject, true, false, 450.0f), 0);

										if(Logging)
											FormatLogMessage("Index: %d Escort Target lost, Going Bezerk!", DispatchIndex);
									}
								}
							}
							break;
						} // End Switch over DispatchType.
					}
				}
				break;
			case DispatchState_Flee: // Unit Fleeing Code.
				{
					if(iter->IdleTime <= BZ1Helper::m_TurnCounter)
					{
						SetIndependence(iter->DispatchObject, 1); // Return normal AI control.
						iter->FleeHealthValue = GetCurHealth(iter->DispatchObject);
						ClearDispatch(DispatchIndex); // Reset orders.
						iter->IdleTime = (BZ1Helper::m_TurnCounter + SecondsToTurns(15.0f)); // Wait 15 seconds before trying to move again.

						if(IsAround(iter->FleeTarget))
							Attack(iter->DispatchObject, iter->FleeTarget, 0);

						if(Logging)
							FormatLogMessage("Index: %d Flee State Ending. Last Target: '%s', IdleTime: %d", DispatchIndex, GetODFName(iter->DispatchObject), iter->IdleTime);
					}
				}
				break;
			case DispatchState_Reload:
			case DispatchState_Repair:
				{
					// If this unit was reloading or repairing, and it's done, clear it's orders so it can continue.
					if( ((iter->DispatchState == DispatchState_Repair) && (GetHealth(iter->DispatchObject) > iter->GetRepairRatio)) || // If they were repairing and their health is better now.
						((iter->DispatchState == DispatchState_Reload) && (GetCurAmmo(iter->DispatchObject) > iter->MinFireAmmo)) || // They were reloading and can fire again. :)
						(iter->IdleTime <= BZ1Helper::m_TurnCounter) || // Idle Timer has passed,
						((iter->DispatchType != DispatchType_Turret) && (iter->DispatchType != DispatchType_Howitzer) && (!TargetAround))) // or a mobile unit's destination went poof.
					{
						if(Logging)
							FormatLogMessage("Index: %d Unit: '%s' Rearmed/Repaired, resuming duties", DispatchIndex, GetODFName(iter->DispatchObject));

						SetIndependence(iter->DispatchObject, 1);
						ClearDispatch(DispatchIndex);
						iter->IdleTime = (BZ1Helper::m_TurnCounter + SecondsToTurns(15.0f)); // Wait 15 seconds before trying to move again.

						if(Logging)
							FormatLogMessage("Index is: %d Repair/Repaid finished, IdleTime: %d", DispatchIndex, iter->IdleTime);
					}
				}
				break;
			} // DispatchState Switch.

			// VSR: the service checks run on a 10 second cycle per unit.
			iter->ServiceTimer--;
			if (iter->ServiceTimer < 0)
				iter->ServiceTimer = SecondsToTurns(10.0f);

			// If these units can get service, and are not currently doing so.
			if( (teamInfo.m_CPUUnitsCanService) &&
				(iter->ServiceTimer <= 0) &&
				(iter->DispatchState != DispatchState_Repair) &&
				(iter->DispatchState != DispatchState_Reload)) // If this unit isn't currently performing a reload or repair function.
			{
				if( (iter->CanGetRepair) && // It can repair.
					(GetHealth(iter->DispatchObject) < iter->GetRepairRatio)) // If its health is < the threshold.
				{
					// This is a stationary deployed item, have the Armory send a repair pod to it.
					if(((iter->DispatchType == DispatchType_Turret) || (iter->DispatchType == DispatchType_Howitzer)) && (IsDeployed(iter->DispatchObject)))
					{
						if (teamInfo.Armory)
						{
							char RepairPodODF[MAX_ODF_LENGTH] = {0};
							if ((GetBuildItem(teamInfo.Armory, RepairPodODF, NULL, 1)) && (GetScrap(Team) >= 0))
							{
								bz1Helper.BuildAt(teamInfo.Armory, RepairPodODF, Position, 1);

								iter->DispatchState = DispatchState_Repair;
								const int TempIdleTime = (BZ1Helper::m_TurnCounter + SecondsToTurns(60.0f));
								if(iter->IdleTime < TempIdleTime)
									iter->IdleTime = TempIdleTime; // Let the powerup land, don't want to drive off while it's landing on us.

								if(Logging)
									FormatLogMessage("Index is: %d Deployable Waiting for Repair Powerup to land, IdleTime: %d", DispatchIndex, iter->IdleTime);
							}
						}
					}
					// Random % chance this unit will go get service.
					else if(GetRandomFloat(1.0f) < iter->ServiceChance)
					{
						const Handle TempTarget = BuildingHelper::Get().GetNearestServiceObject(1, Position);
						// If the above found something.
						if(TempTarget)
						{
							if(Logging)
								FormatLogMessage("Index: %d Unit: '%s' going to get Repair", DispatchIndex, GetODFName(iter->DispatchObject));

							iter->DispatchTarget = TempTarget;
							Goto(iter->DispatchObject, iter->DispatchTarget, 0);
							SetIndependence(iter->DispatchObject, 0);
							iter->DispatchState = DispatchState_Repair;
							iter->IdleTime = (BZ1Helper::m_TurnCounter + SecondsToTurns(300.0f)); // Timeout after 5 minutes of travel.

							if(Logging)
								FormatLogMessage("Index is: %d Unit going to Repair Service, IdleTime: %d", DispatchIndex, iter->IdleTime);
						}
					}
				}
				// Get Ammo code, this makes AI ships get ammo when they run out.
				if( (iter->CanGetReload) && // Can reload.
					(GetAmmo(iter->DispatchObject) < 1.0f)) // If it's not currently full.
				{
					// Calculate this unit's minimum required ammo to fire.
					iter->MinFireAmmo = GetMinFireAmmo(iter->DispatchObject);

					// It doesn't have enough to fire it's main weapons, send it to reload.
					if(GetCurAmmo(iter->DispatchObject) < iter->MinFireAmmo)
					{
						// This is a stationary deployed item, have the Armory send an ammo pod to it.
						if(((iter->DispatchType == DispatchType_Turret) || (iter->DispatchType == DispatchType_Howitzer)) && (IsDeployed(iter->DispatchObject)))
						{
							if (teamInfo.Armory)
							{
								char AmmoPodODF[MAX_ODF_LENGTH] = {0};
								if ((GetBuildItem(teamInfo.Armory, AmmoPodODF, NULL, 2)) && (GetScrap(Team) >= 0))
								{
									bz1Helper.BuildAt(teamInfo.Armory, AmmoPodODF, Position, 1);

									iter->DispatchState = DispatchState_Reload;
									const int TempIdleTime = (BZ1Helper::m_TurnCounter + SecondsToTurns(60.0f));
									if(iter->IdleTime < TempIdleTime)
										iter->IdleTime = TempIdleTime; // Let the powerup land.

									if(Logging)
										FormatLogMessage("Index is: %d Deployable Waiting for Reload Powerup to land, IdleTime: %d", DispatchIndex, iter->IdleTime);
								}
							}
						}
						else // its mobile.
						{
							const Handle TempTarget = BuildingHelper::Get().GetNearestServiceObject(2, Position);
							if(TempTarget)
							{
								if(Logging)
									FormatLogMessage("Index: %d Unit: '%s' going to get Reload", DispatchIndex, GetODFName(iter->DispatchObject));

								iter->DispatchTarget = TempTarget;
								Goto(iter->DispatchObject, iter->DispatchTarget, 0);
								SetIndependence(iter->DispatchObject, 0);
								iter->DispatchState = DispatchState_Reload;
								iter->IdleTime = (BZ1Helper::m_TurnCounter + SecondsToTurns(30.0f)); // Wait 30 seconds before trying to attack again.

								if(Logging)
									FormatLogMessage("Index is: %d Unit going to Reload Service, IdleTime: %d", DispatchIndex, iter->IdleTime);
							}
						}
					}
				}
			} // end can get service.
		} // There's no players on this team, and the unit is ours to command.

		if(iter->IsCloaker)
		{
			if(!iter->IsCloaked)
			{ // If it isn't cloaked, or it's orders have changed.
				if(iter->CloakNextTick)
				{
					if(!IsDeployed(iter->DispatchObject))
					{
						SetCommand(iter->DispatchObject, CMD_MORPH_SETDEPLOYED, 0); // Cloak the object.
						iter->DeployTimer = (BZ1Helper::m_TurnCounter + SecondsToTurns(iter->TimeDeploy) + 1);
						iter->CloakLocked = true;

						if(Logging)
							FormatLogMessage("Index: %d Cloaking Activating, Time: %d, DeployTimer: %d, DeployTime: %f", DispatchIndex, BZ1Helper::m_TurnCounter, iter->DeployTimer, iter->TimeDeploy);
					}
					iter->IsCloaked = true;
					iter->CloakNextTick = false;
				} // End Cloak Command.
				// This handles manual Cloaking AI behavior. If AIPCheck, and IdleTime passed OR Command Changed, Not Player Team, independent, CloakPriority = 0, re-calculate if we should cloak.
				else if(((iter->SkipAIPCheck) || (teamInfo.m_CPUDoDispatch)) &&
					((iter->CloakIdleTime <= BZ1Helper::m_TurnCounter) || (GetCurrentCommand(iter->DispatchObject) != iter->Command)) &&
					(GetPlayerHandle(Team) == 0) && (Independent) && (!iter->CloakPriority))
				{
					const float Chance = GetRandomFloat(1.0f);
					const Handle Enemy = GetNearestEnemy(iter->DispatchObject);
					// If its not deployed, and there are no enemies in range.
					if(((!IsDeployed(iter->DispatchObject)) || (iter->IsMorpher)) &&
						((!Enemy) || (GetDistance3DSquared(Position, GetPosition(Enemy)) > Squared(iter->EngageRange))))
					{
						if(Logging)
							FormatLogMessage("Index: %d AI Attempting to Cloak unit, Chance: %f, CloakCommand: %d Chance: %f", DispatchIndex, Chance, iter->Command, iter->CloakChance[iter->Command]);
						if(Chance < iter->CloakChance[GetCurrentCommand(iter->DispatchObject)])
						{
							if(Logging)
								FormatLogMessage("Index: %d AI Cloak Successful", DispatchIndex);
							Cloak(iter->DispatchObject, iter->CloakPriority);
						}
						iter->CloakIdleTime = (BZ1Helper::m_TurnCounter + SecondsToTurns(15.0f)); // Wait 15 seconds before trying to cloak again.
					} // Unit is not deployed and there are no enemies around.
				} // Cloak idle time is up.
			} // Unit is not cloaked.
			else // Unit is cloaked.
			{
				if((IsDeployed(iter->DispatchObject)))
				{
					// DLL Ordered us to Decloak.
					if(iter->DecloakNextTick)
					{
						SetCommand(iter->DispatchObject, CMD_MORPH_SETUNDEPLOYED, 0); // Decloak the object.
						iter->DecloakNextTick = false;
					}
					else
					{
						// If AI Can manually Decloak, Unlock ability for AI to decloak on it's own when an enemy is nearby.
						if((Independent) && (!iter->CloakPriority))
						{
							const Handle Enemy = GetNearestEnemy(iter->DispatchObject);
							if((iter->CloakLocked) && (GetDistance3DSquared(iter->DispatchObject, Enemy) < Squared(iter->EngageRange)))
							{
								if(Logging)
									FormatLogMessage("Index: %d Unit is Cloaked, Enemy detected, Unlocking Cloak", DispatchIndex);
								SetCommand(iter->DispatchObject, CMD_MORPH_UNLOCK, 0); // Unlock morph state so it can Attack something.
								iter->CloakLocked = false;
							}
						}
						// If we were ordered to Attack, and are now within range of our target, Decloak.
						if(GetCurrentCommand(iter->DispatchObject) == CMD_ATTACK)
						{
							if (GetDistance3DSquared(Position, GetPosition(Who)) < Squared(iter->EngageRange))
							{
								if(Logging)
									FormatLogMessage("Index: %d Unit is Cloaked, Target In Range, Decloaking", DispatchIndex);
								if (IsAround(iter->DispatchObject))
									Decloak(iter->DispatchObject, iter->CloakPriority);
								iter->CloakLocked = false;
							}
						}
					}
				}
				// If it becomes uncloaked, for whatever reason, flag as not cloaked and reset timer.
				else if(iter->DeployTimer < BZ1Helper::m_TurnCounter)
				{
					if(((iter->SkipAIPCheck) || (teamInfo.m_CPUDoDispatch)) && (GetPlayerHandle(Team) == 0))
					{
						if(GetCurrentCommand(iter->DispatchObject) == iter->Command)
						{
							if(Logging)
								FormatLogMessage("Index: %d Command Identicle, setting CloakIdle time for 15 seconds.", DispatchIndex);
							iter->CloakIdleTime = (BZ1Helper::m_TurnCounter + SecondsToTurns(15.0f)); // Wait 15 seconds before trying to cloak again.
						}
						else
						{
							if(Logging)
								FormatLogMessage("Index: %d Command Different, Setting CloakIdle time for NOW.", DispatchIndex);
							iter->CloakIdleTime = BZ1Helper::m_TurnCounter; // Command changed, dont wait to recalculate cloak.
						}
					}

					iter->IsCloaked = false; // It's past the deployTimer, this unit has Decloaked.
					if(Logging)
						FormatLogMessage("Index: %d Unit was not cloaked! DeployTimer: %d, Time: %d, DeployTime: %f, Time: %d", DispatchIndex, iter->DeployTimer, BZ1Helper::m_TurnCounter, iter->TimeDeploy, BZ1Helper::m_TurnCounter);
				}
			} // Unit is cloaked.
		} // Its a cloaker.

		// Update the unit's saved command for comparison.
		if(GetCurrentCommand(iter->DispatchObject) != iter->Command)
			iter->Command = GetCurrentCommand(iter->DispatchObject);
	}
}

void DispatchHelper::PreOrdnanceHit(const Handle shooterHandle, const Handle victimHandle, const int /*ordnanceTeam*/, const char* pOrdnanceODF)
{
	const bool Logging = BZ1Helper::Logging;

	if (GetIndependence(victimHandle) == 0) // A unit a script controls is left alone.
		return;

	for (std::vector<DispatchClass>::iterator iter = DispatchList.begin(); iter != DispatchList.end(); ++iter)
	{
		if(victimHandle != iter->DispatchObject)
			continue;
		const int DispatchIndex = int(iter - DispatchList.begin());

		// This turret got shot on it's way to where it was going. Make it stop and deploy.
		if((iter->DispatchType == DispatchType_Turret) && (!IsDeployed(iter->DispatchObject)))
		{
			Defend(iter->DispatchObject, 0); // Sit here until I decide to tell you otherwise.
			iter->DispatchState = DispatchState_Idle;
			iter->IdleTime = (BZ1Helper::m_TurnCounter + SecondsToTurns(30.0f)); // Wait 30 seconds before trying to move again.

			if(Logging)
				FormatLogMessage("Index is: %d Turret Shot, Deploying, IdleTime: %d", DispatchIndex, iter->IdleTime);
			return; // We're done, exit early.
		}
		if((iter->DispatchType == DispatchType_Minelayer) && ((iter->DispatchState == DispatchState_Goto) || (iter->DispatchState == DispatchState_Idle)))
		{
			SetCommand(iter->DispatchObject, CMD_LAY_MINES, 0);
			iter->DispatchState = DispatchState_Idle;
			iter->IdleTime = (BZ1Helper::m_TurnCounter + SecondsToTurns(30.0f)); // Wait 30 seconds before trying to move again.

			if(Logging)
				FormatLogMessage("Index is: %d Minelayer Shot, Mining, IdleTime: %d", DispatchIndex, iter->IdleTime);
			return; // We're done, exit early.
		}

		if (!iter->CanFlee) // It can Flee.
			return;
		if (iter->DispatchState == DispatchState_Flee) // It's not already Fleeing.
			return;
		if (BZ1Helper::m_TurnCounter <= iter->IdleTime) // Flee Timeout is up.
			return;
		if (iter->DispatchState == DispatchState_Repair) // It's not repairing.
			return;
		if (iter->DispatchState == DispatchState_Reload) // It's not reloading.
			return;
		if (GetHealth(iter->DispatchObject) >= iter->FleeHealthRatio) // Minimum Health Ratio is met.
			return;

		const long CurHealth = GetCurHealth(iter->DispatchObject);
		const long Damage = GetOrdnanceDamageDealt(iter->DispatchObject, pOrdnanceODF, true);
		if ((iter->FleeHealthValue - CurHealth) < (iter->MaxHealth / 10)) // Has lost 10% of it's health since last Flee state ended.
			return;
		if (GetRandomFloat(float(max(4 * Damage, CurHealth))) >= Damage) // % chance, based on ordnance damage. Can't be > 25%.
			return;

		iter->IdleTime = (BZ1Helper::m_TurnCounter + SecondsToTurns(3.0f + GetRandomFloat(2.0f))); // Flee for 3-5 seconds.
		iter->FleeTarget = GetTarget(iter->DispatchObject);
		// If there is no target, return fire!
		bool Retarget = false;
		GetODFBool(iter->DispatchObject, "CraftClass", "RetargetOnStrafe", &Retarget, false);
		if((!iter->FleeTarget) && (Retarget))
			iter->FleeTarget = shooterHandle;

		SetIndependence(iter->DispatchObject, 0); // Dont let the AI do stuff on its own.
		const Vector FleePosition = GetPositionNearOrFar(iter->DispatchObject, shooterHandle, 40.0f, 75.0f, false);
		Goto(iter->DispatchObject, FleePosition, 0);
		if((iter->IsCloaker) && (GetRandomFloat(1.0f) < 0.5f)) // 50% chance of cloaking, if we can cloak. :P
			Deploy(iter->DispatchObject);
		iter->DispatchState = DispatchState_Flee;

		if(Logging)
			FormatLogMessage("Flee Target Shot, Target is: '%s', IdleTime: %d", GetODFName(iter->DispatchObject), iter->IdleTime);
		return; // We're done, exit early.
	}
}

void DispatchHelper::ReadChanceValues(const char* const file, const char* const block, float* value, const float defval)
{
	if(OpenODF2(file))
	{
		for (int i = 0; i < NUM_CMD; ++i)
			GetODFFloat(file, block, CommandList[i], &value[i], defval);
	}
}

void DispatchHelper::Cloak(const Handle h, const int Priority)
{
	const bool Logging = BZ1Helper::Logging;

	if(!IsAround(h))
		return;

	// A morph-object cloaker cloaks through its toggle.
	for(int t = 0; t < MorphObjectHelper::Get().GetNumMorphObjects();t++)
	{
		if((MorphObjectHelper::Get().RefMorphObjectHandle(t) == h) && (MorphObjectHelper::Get().GetMorphObjectCloaker(t)))
		{
			SetCommand(h, CMD_HUNT, 0); // Cloak.
			return;
		}
	}

	for (std::vector<DispatchClass>::iterator iter = DispatchList.begin(); iter != DispatchList.end(); ++iter)
	{
		if(iter->DispatchObject == h)
		{
			if(IsPlayer(h))
			{
				if(!IsDeployed(h))
					Deploy(h);
			}
			else
			{
				iter->CloakPriority = Priority;
				iter->CloakNextTick = true;

				if(Logging)
					FormatLogMessage("Cloak Command Given, Time: %d", BZ1Helper::m_TurnCounter);
			}
			return;
		}
	}

	AddToDispatch(h, 0.0f, true, Priority, true, true, false, false);
}

void DispatchHelper::Decloak(const Handle h, const int /*UnusedArg*/)
{
	for(int t = 0; t < MorphObjectHelper::Get().GetNumMorphObjects();t++)
	{
		if((MorphObjectHelper::Get().RefMorphObjectHandle(t) == h) && (MorphObjectHelper::Get().GetMorphObjectCloaker(t)))
		{
			SetCommand(h, CMD_HUNT, 0); // Decloak.
			return;
		}
	}

	for (std::vector<DispatchClass>::iterator iter = DispatchList.begin(); iter != DispatchList.end(); ++iter)
	{
		if(iter->DispatchObject == h)
		{
			if(IsPlayer(h))
			{
				if(IsDeployed(h))
					Deploy(h);
			}
			else
			{
				iter->DecloakNextTick = true;
			}
			return;
		}
	}
}

// DECOMPILE: declared in the PDB, no procedure in any shipped DLL (never called); ancestor body.
bool DispatchHelper::IsCloaked(const Handle h)
{
	if(!IsAround(h))
		return false;

	for(int t = 0; t < MorphObjectHelper::Get().GetNumMorphObjects();t++)
	{
		if((MorphObjectHelper::Get().RefMorphObjectHandle(t) == h) && (MorphObjectHelper::Get().GetMorphObjectCloaker(t)))
			return MorphObjectHelper::Get().GetMorphObjectIsActive(t);
	}

	for (std::vector<DispatchClass>::iterator iter = DispatchList.begin(); iter != DispatchList.end(); ++iter)
	{
		if(iter->DispatchObject == h)
			return ((BZ1Helper::m_TurnCounter <= iter->DeployTimer)) || IsDeployed(iter->DispatchObject);
	}

	return false;
}

// DECOMPILE: declared in the PDB, no procedure in any shipped DLL (never called); ancestor body.
void DispatchHelper::DLLHunt(const Handle h, const int Priority)
{
	if(!IsAround(h))
		return;

	for (std::vector<DispatchClass>::iterator iter = DispatchList.begin(); iter != DispatchList.end(); ++iter)
	{
		if(iter->DispatchObject == h)
		{
			iter->DispatchType = DispatchType_Hunter;
			++BZ1Helper::Get().RefTeamInfo(GetTeamNum(h)).m_CPUNumHuntUnits;
			return;
		}
	}

	AddToDispatch(h, 0.0f, true, Priority, true, false, true);
}

// DECOMPILE: declared in the PDB, no procedure in any shipped DLL (never called); the DLLHunt shape for the Patrol type.
void DispatchHelper::DLLPatrol(const Handle h, const int Priority)
{
	if(!IsAround(h))
		return;

	for (std::vector<DispatchClass>::iterator iter = DispatchList.begin(); iter != DispatchList.end(); ++iter)
	{
		if(iter->DispatchObject == h)
		{
			iter->DispatchType = DispatchType_Patrol;
			++BZ1Helper::Get().RefTeamInfo(GetTeamNum(h)).m_CPUNumPatrolUnits;
			return;
		}
	}

	AddToDispatch(h, 0.0f, true, Priority, true, false, false);
}

// DECOMPILE: declared in the PDB, no procedure in any shipped DLL (never called); ancestor body.
void DispatchHelper::SetUseService(const Handle h, const bool Service)
{
	if(!IsAround(h))
		return;

	for (std::vector<DispatchClass>::iterator iter = DispatchList.begin(); iter != DispatchList.end(); ++iter)
	{
		if(iter->DispatchObject == h)
		{
			iter->CanGetReload = Service;
			iter->CanGetRepair = Service;
			return;
		}
	}

	AddToDispatch(h, 0.0f, true, 0, true, false, false, true);
}

// Resets a unit's orders. (sic, ancestor and shipped alike: the resets land on a COPY of the entry; only the SetCommand reaches the unit.)
void DispatchHelper::ClearDispatch(const int Index)
{
	DispatchClass Object = DispatchList[Index];

	Object.IdleTime = 0;
	Object.DispatchState = DispatchState_Idle;
	Object.DispatchTarget = 0;
	Object.DispatchSpot = Vector(0, 0, 0);
	if (!IsPlayer(Object.DispatchObject))
		SetCommand(Object.DispatchObject, CMD_NONE, 0);
}
