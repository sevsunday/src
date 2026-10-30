// PROVENANCE: ancestor reference/ancestor-bz1helper-2015/Shared/ProductionClassHelper.cpp @6fda4f5 (scrap holds, limits / pilots / pools flags, undeploy preload, deployed message) | decompile reference/decompiled/strategy02-ghidra12.2/src/missions/vsrcore/productionclasshelper.cpp.decomp.c (AddProductionClassObject 20-237, Execute 240-758; Ghidra passes `h` where it prints `this` — the class is empty) + strings.tsv for the key names | status: ported
#include "bz1helper.h"
#include "productionclasshelper.h"
#include "undeployhelper.h"
#include "bzcscriptutils.h"
#include <algorithm>

ProductionClassHelper *ProductionClassHelper::m_ProductionClassHelper;

ProductionClassHelper::ProductionClassHelper()
{
	m_ProductionClassHelper = this;
}
ProductionClassHelper::~ProductionClassHelper()
{
	m_ProductionClassHelper = NULL;
}

void ProductionClassHelper::AddProductionClassObject(const Handle h, const char* TempODF1, const char* TempODF2, const int Team, const int ObjClassHash, const int BZCClassHash, const int TeamSlot)
{
	if(TempODF1 == NULL)
		return;

	BZ1Helper::TeamInfo &teamInfo = BZ1Helper::Get().RefTeamInfo(Team);

	SetIndependence(h, 0); // Don't let AI do stuff on it's own.

	// VSR: the base slot (1-9) this unit occupies, and the name the command panel shows for it (shellName, else the slot's stock name).
	teamInfo.BaseSlot[TeamSlot-1] = h;
	if (!GetODFString(TempODF1, TempODF2, "GameObjectClass", "shellName", MAX_ODF_LENGTH, teamInfo.BaseSlotName[TeamSlot-1]))
	{
		const char *DefaultName = NULL;
		if ((TeamSlot == 1) || (TeamSlot == 5))
			DefaultName = "Recycler";
		else if ((TeamSlot == 2) || (TeamSlot == 6))
			DefaultName = "Factory";
		else if ((TeamSlot == 3) || (TeamSlot == 7))
			DefaultName = "Armory";
		else if ((TeamSlot == 4) || (TeamSlot == 8))
			DefaultName = "Constructor";
		else if (TeamSlot == 9)
			DefaultName = "Satellite";
		if (DefaultName)
			strcpy_s(teamInfo.BaseSlotName[TeamSlot-1], DefaultName);
	}

	if (teamInfo.TeamRace == 0)
		teamInfo.TeamRace = GetRace(h);

	// Look for Scrap Holds for production units.
	char ScrapHoldName[MAX_ODF_LENGTH] = {0};
	if((GetODFString(TempODF1, TempODF2, "GameObjectClass", "ScrapHold", MAX_ODF_LENGTH, ScrapHoldName)) && (ScrapHoldName[0])) // Grab the value.
	{
		teamInfo.BaseSlotUseScrapHold[TeamSlot-1] = true;
		if((!IsAround(teamInfo.BaseSlotScrap[TeamSlot-1])) && (BZ1Helper::m_TurnCounter > 0))
		{
			if(!DoesODFExist(ScrapHoldName))
				sprintf_s(ScrapHoldName, "base%dshold", TeamSlot);
			teamInfo.BaseSlotScrap[TeamSlot-1] = BuildObject(ScrapHoldName, Team, BZ1Helper::OffMapPos);
		}
	}

	// If we havn't determined if we're using limits, look in production units to tell. 
	if(!teamInfo.m_UseLimits)
		GetODFBool(TempODF1, TempODF2, "GameObjectClass", "UseBZ1Limits", &teamInfo.m_UseLimits, false);

	// If we havn't determined if we're using pilots, look in production units to tell.
	if(!teamInfo.m_UsePilots)
		GetODFBool(TempODF1, TempODF2, "GameObjectClass", "UseBZ1Pilots", &teamInfo.m_UsePilots, false);

	if(!teamInfo.NoPlayerPilot)
		GetODFBool(TempODF1, TempODF2, "GameObjectClass", "NoPlayerPilot", &teamInfo.NoPlayerPilot, false);

	if(!BZ1Helper::Get().RefBuildPools())
		GetODFBool(TempODF1, TempODF2, "GameObjectClass", "UseBZ2Pools", &BZ1Helper::Get().RefBuildPools(), false);

	// VSR: the command panel's pilot / scrap cost labels for this slot's ten build items.
	if (GetODFBool(TempODF1, TempODF2, "GameObjectClass", "ShowPilotCosts", &teamInfo.ShowPilotCosts[TeamSlot-1], false) && teamInfo.ShowPilotCosts[TeamSlot-1])
	{
		const char *BuildClass = NULL;
		if ((ObjClassHash == CLASS_RECYCLER) || (ObjClassHash == CLASS_FACTORY))
			BuildClass = "FactoryClass";
		else if (ObjClassHash == CLASS_CONSTRUCTIONRIG)
			BuildClass = "ConstructionRigClass";
		else if (ObjClassHash == CLASS_CONSTRUCTIONRIGT)
			BuildClass = "ConstructionRigTClass";
		else if (ObjClassHash == CLASS_ARMORY)
			BuildClass = "ArmoryClass";
		if (BuildClass)
		{
			char ClassName[MAX_ODF_LENGTH] = {0};
			strcpy_s(ClassName, BuildClass);
			for (int i = 1; i <= MAX_BASE_SLOT_ITEMS; i++)
			{
				char DesiredValue[MAX_ODF_LENGTH] = {0};
				sprintf_s(DesiredValue, "buildItem%d", i);
				char BuildItem[MAX_ODF_LENGTH] = {0};
				GetODFString(TempODF1, TempODF2, ClassName, DesiredValue, MAX_ODF_LENGTH, BuildItem);
				teamInfo.BaseSlotPilotCost[TeamSlot-1][i-1] = GetPilotCost(BuildItem);
				teamInfo.BaseSlotScrapCost[TeamSlot-1][i-1] = GetScrapCost(BuildItem);
			}
		}
	}

	// VSR: a unit with both a "build" and a "BZCLoop" animation animates while building (-1 = no animation, 0 = idle, 1 = building).
	teamInfo.BaseSlotPlayingAnim[TeamSlot-1] = -1;
	int animCount = 0;
	GetODFInt(TempODF1, TempODF2, "GameObjectClass", "animCount", &animCount, 0);
	bool HasBuild = false;
	bool HasLoop = false;
	for (int i = 1; i <= animCount; i++)
	{
		char DesiredValue[MAX_ODF_LENGTH] = {0};
		sprintf_s(DesiredValue, "animName%d", i);
		char AnimName[MAX_ODF_LENGTH] = {0};
		if (!GetODFString(TempODF1, TempODF2, "GameObjectClass", DesiredValue, MAX_ODF_LENGTH, AnimName))
			break;
		if (_stricmp(AnimName, "build") == 0)
			HasBuild = true;
		if (_stricmp(AnimName, "BZCLoop") == 0)
			HasLoop = true;
		if (HasBuild && HasLoop)
		{
			teamInfo.BaseSlotPlayingAnim[TeamSlot-1] = 0;
			break;
		}
	}

	char DeployODF[MAX_ODF_LENGTH] = {0};
	GetODFString(TempODF1, TempODF2, "GameObjectClass", "UndeployClass", MAX_ODF_LENGTH, DeployODF);
	if((DeployODF[0]) && (DoesODFExist(DeployODF)))
	{
		PetWatchdogThread();
		PreloadODF(DeployODF);
	}

	// The production handles. A BZCClasslabel decides; without one the stock classes do, for the first three slots only.
	if (BZCClassHash == 0)
	{
		if (TeamSlot > 3)
			return;
		switch (ObjClassHash)
		{
		case CLASS_RECYCLER:
			teamInfo.Recycler = h;
			teamInfo.TeamRace = GetRace(h); // Save the team's race. Note: Placing a new RECY will override the previous Race letter. -GBD
			break;
		case CLASS_FACTORY:
			teamInfo.Factory = h;
			break;
		case CLASS_ARMORY:
			teamInfo.Armory = h;
			break;
		case CLASS_CONSTRUCTIONRIG:
		case CLASS_CONSTRUCTIONRIGT:
			teamInfo.Constructor = h;
			break;
		}
	}
	else
	{
		switch (BZCClassHash)
		{
		case BZCCLASS_RECYCLER:
			teamInfo.Recycler = h;
			teamInfo.TeamRace = GetRace(h);
			break;
		case BZCCLASS_FACTORY:
			teamInfo.Factory = h;
			break;
		case BZCCLASS_ARMORY:
			teamInfo.Armory = h;
			break;
		case BZCCLASS_CONSTRUCTOR:
			teamInfo.Constructor = h;
			break;
		}
	}
}

void ProductionClassHelper::Execute(BZ1Helper &bz1Helper)
{
	const bool Logging = BZ1Helper::Logging;

	for (int Team = 0; Team < MAX_TEAMS; Team++)
	{
		BZ1Helper::TeamInfo &teamInfo = bz1Helper.RefTeamInfo(Team);
		bool ArmoryQueuedOne = false; // The armory just queued its first item: play reloadMsg.
		bool ArmoryDone = false; // The armory finished an item: play that powerup's sound.

		for (int Slot = 0; Slot < MAX_BASE_SLOTS; Slot++)
		{
			Handle &h = teamInfo.BaseSlot[Slot];

			// A production unit that changed team takes its slot, scrap hold, name and flags with it.
			if (IsAround(h))
			{
				const int NewTeam = GetTeamNum(h);
				if (NewTeam != Team)
				{
					BZ1Helper::TeamInfo &newInfo = bz1Helper.RefTeamInfo(NewTeam);
					if (h == teamInfo.Recycler)
					{
						newInfo.Recycler = teamInfo.Recycler;
						teamInfo.Recycler = 0;
					}
					else if (h == teamInfo.Factory)
					{
						newInfo.Factory = teamInfo.Factory;
						teamInfo.Factory = 0;
					}
					else if (h == teamInfo.Armory)
					{
						newInfo.Armory = teamInfo.Armory;
						teamInfo.Armory = 0;
					}
					else if (h == teamInfo.Constructor)
					{
						newInfo.Constructor = teamInfo.Constructor;
						teamInfo.Constructor = 0;
					}
					newInfo.BaseSlot[Slot] = h;
					h = 0;
					if (!newInfo.m_UsePilots)
						newInfo.m_UsePilots = teamInfo.m_UsePilots;
					if (!newInfo.m_UseLimits)
						newInfo.m_UseLimits = teamInfo.m_UseLimits;
					strcpy_s(newInfo.BaseSlotName[Slot], teamInfo.BaseSlotName[Slot]);
					memset(teamInfo.BaseSlotName[Slot], 0, MAX_ODF_LENGTH);
					if (IsAround(teamInfo.BaseSlotScrap[Slot]))
					{
						char ScrapHoldODF[MAX_ODF_LENGTH] = {0};
						GetODFName(teamInfo.BaseSlotScrap[Slot], ScrapHoldODF);
						const Vector Position = GetPosition(teamInfo.BaseSlotScrap[Slot]);
						RemoveObject(teamInfo.BaseSlotScrap[Slot]);
						const Handle OldScrapHold = newInfo.BaseSlotScrap[Slot];
						newInfo.BaseSlotScrap[Slot] = BuildObject(ScrapHoldODF, NewTeam, Position);
						if (IsAround(OldScrapHold))
							RemoveObject(OldScrapHold);
						teamInfo.BaseSlotScrap[Slot] = 0;
					}
				}
			}

			if (IsAround(h))
			{
				// Rebuild a missing scrap hold.
				if (teamInfo.BaseSlotUseScrapHold[Slot] && !IsAround(teamInfo.BaseSlotScrap[Slot]))
				{
					char ScrapHoldName[MAX_ODF_LENGTH] = {0};
					GetODFString(h, "GameObjectClass", "ScrapHold", MAX_ODF_LENGTH, ScrapHoldName);
					if (ScrapHoldName[0] && !DoesODFExist(ScrapHoldName))
						sprintf_s(ScrapHoldName, "base%dshold", Slot+1);
					teamInfo.BaseSlotScrap[Slot] = BuildObject(ScrapHoldName, Team, BZ1Helper::OffMapPos);
				}

				// Track the build queue: the count drops when an item finishes (-> build animation), the armory's current class is remembered for its sounds.
				const bool Busy = IsBuilding(h) && IsBusy(h);
				bool PlayBuildAnim = false;
				if (Busy)
				{
					const char *BuildClass = GetBuildClass(h);
					if (BuildClass && (_strnicmp(BuildClass, "BZCundep", 8) == 0))
					{
						if (Logging)
							FormatConsoleMessage("Team Slot: %d building Undeploy: %s", Slot+1, BuildClass);
						UndeployHelper::Get().AddUndeployObject(h, Team, BuildClass);
					}

					int Count = 0;
					while (GetQueuedItem(teamInfo.Armory, Count)) // sic: the armory's queue is counted for every slot.
						Count++;

					if ((h == teamInfo.Armory) && (_stricmp(BuildClass, teamInfo.ArmoryBuildClass) != 0))
						strcpy_s(teamInfo.ArmoryBuildClass, BuildClass);

					const int OldCount = teamInfo.BaseSlotBuildCount[Slot];
					if (Count != OldCount)
					{
						if (Logging)
							FormatLogMessage("BaseSlot Qued Item: BuildClass: '%s', Count is: %d", BuildClass, Count);
						teamInfo.BaseSlotBuildCount[Slot] = Count;
						PlayBuildAnim = Count < OldCount;
						if (h == teamInfo.Armory)
						{
							ArmoryQueuedOne = (Count == 1);
							ArmoryDone = false;
						}
					}
				}
				else if (teamInfo.BaseSlotBuildCount[Slot] > 0)
				{
					if (Logging)
						FormatLogMessage("BaseSlot Done, ArmoryBuildClass: '%s', BaseSlotCount is: %d", teamInfo.ArmoryBuildClass, teamInfo.BaseSlotBuildCount[Slot]);
					teamInfo.BaseSlotBuildCount[Slot]--;
					PlayBuildAnim = true;
					if (h == teamInfo.Armory)
						ArmoryDone = true;
				}

				// The build animation, then back to the BZCloop idle.
				int PlayingAnim = teamInfo.BaseSlotPlayingAnim[Slot];
				if ((PlayingAnim == 0) && PlayBuildAnim)
				{
					teamInfo.BaseSlotAnimationFrames[Slot] = SetAnimation(h, "build", 1);
					StartAnimation(h);
					PlayingAnim = 1;
					teamInfo.BaseSlotPlayingAnim[Slot] = 1;
				}
				if ((PlayingAnim > 0) && (GetAnimationFrame(h, "build") >= teamInfo.BaseSlotAnimationFrames[Slot] - 1.0f))
				{
					teamInfo.BaseSlotAnimationFrames[Slot] = SetAnimation(h, "BZCloop", 0);
					StartAnimation(h);
					teamInfo.BaseSlotPlayingAnim[Slot] = 0;
				}
			}
			else
			{
				// Gone: clear the production handle and the scrap hold.
				if (h == teamInfo.Recycler)
					teamInfo.Recycler = 0;
				else if (h == teamInfo.Factory)
					teamInfo.Factory = 0;
				else if (h == teamInfo.Armory)
					teamInfo.Armory = 0;
				else if (h == teamInfo.Constructor)
					teamInfo.Constructor = 0;
				h = 0;
				if (IsAround(teamInfo.BaseSlotScrap[Slot]))
				{
					RemoveObject(teamInfo.BaseSlotScrap[Slot]);
					teamInfo.BaseSlotScrap[Slot] = 0;
				}
			}
		}

		// Armory voice-overs for the local player's team.
		if (IsBuilding(teamInfo.Armory))
		{
			if (ArmoryDone)
			{
				const char *ClassLabel = GetClasslabelString(teamInfo.ArmoryBuildClass);
				int PowerupClass = 0; // Hash_GOClass values
				if (_stricmp(ClassLabel, "ammopack") == 0)
					PowerupClass = CLASS_POWERUP_RELOAD;
				else if ((_stricmp(ClassLabel, "repairkit") == 0) || (_stricmp(ClassLabel, "servicepod") == 0))
					PowerupClass = CLASS_POWERUP_REPAIR;
				else if (_stricmp(ClassLabel, "wpnpower") == 0)
					PowerupClass = CLASS_WEAPON;
				else if (_stricmp(ClassLabel, "camerapod") == 0)
					PowerupClass = CLASS_POWERUP_CAMERA;
				else if (_stricmp(ClassLabel, "daywrecker") == 0)
					PowerupClass = CLASS_DAYWRECKER;

				char Sound[MAX_ODF_LENGTH] = {0};
				char TempODF1[MAX_ODF_LENGTH] = {0};
				char TempODF2[MAX_ODF_LENGTH] = {0};
				GetAndOpenODFNames(teamInfo.Armory, TempODF1, TempODF2);
				const char *SoundKey = "rescueMsg";
				if (PowerupClass == CLASS_POWERUP_CAMERA)
					SoundKey = "navSound";
				else if (PowerupClass == CLASS_DAYWRECKER)
					SoundKey = "bombSound";
				else if (PowerupClass == CLASS_POWERUP_RELOAD)
					SoundKey = "ammoSound";
				else if (PowerupClass == CLASS_WEAPON)
					SoundKey = "weaponSound";
				else if (PowerupClass == CLASS_POWERUP_REPAIR)
					SoundKey = "repaSound";
				GetODFString(TempODF1, TempODF2, "ArmoryClass", SoundKey, MAX_ODF_LENGTH, Sound);
				if (Sound[0])
				{
					if (Logging)
						FormatLogMessage("Sound Is: '%s'", Sound);
					if (GetLocalPlayerTeamNumber() == Team)
					{
						if (DoesFileExist(Sound))
							AudioMessage(Sound, false);
						else
							FormatLogMessage("ERROR: Sound file: '%s' doesn't exist! Fix ODF: '%s'", Sound, GetODFName(teamInfo.Armory));
					}
				}
			}
			if (ArmoryQueuedOne)
			{
				char Sound[MAX_ODF_LENGTH] = {0};
				char TempODF1[MAX_ODF_LENGTH] = {0};
				char TempODF2[MAX_ODF_LENGTH] = {0};
				GetAndOpenODFNames(teamInfo.Armory, TempODF1, TempODF2);
				GetODFString(TempODF1, TempODF2, "ArmoryClass", "reloadMsg", MAX_ODF_LENGTH, Sound);
				if (Sound[0] && (GetLocalPlayerTeamNumber() == Team))
				{
					if (DoesFileExist(Sound))
						AudioMessage(Sound, false);
					else
						FormatLogMessage("ERROR: Sound file: '%s' doesn't exist! Fix ODF: '%s'", Sound, GetODFName(teamInfo.Armory));
				}
			}
		}
	}
}
