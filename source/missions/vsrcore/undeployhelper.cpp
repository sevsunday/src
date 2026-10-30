// PROVENANCE: ancestor reference/ancestor-bz1helper-2015/Shared/UndeployHelper.cpp @6fda4f5 | decompile reference/decompiled/strategy02-ghidra12.2/src/missions/vsrcore/undeployhelper.cpp.decomp.c (PostLoad 42-65, AddUndeployObject 83-175, Execute 178-301; Load / Save inlined into BZ1Helper::Load / Save) | status: ported
#include "bz1helper.h"
#include "undeployhelper.h"
#include "bzcscriptutils.h"
#include <algorithm>

UndeployHelper *UndeployHelper::m_UndeployHelper;
std::vector<UndeployHelper::UndeployClass> TempUndeployBuffer; // GBD: the list as it stood before a Load, for PostLoad's resync report.

UndeployHelper::UndeployHelper()
{
	m_UndeployHelper = this;
}
UndeployHelper::~UndeployHelper()
{
	m_UndeployHelper = NULL;
}

bool UndeployHelper::Load(bool missionSave)
{
	if (!missionSave)
	{
		TempUndeployBuffer = UndeployList;

		int size = 0;
		bool ret = Read(&size, 1);
		UndeployList.resize(size);
		if(size)
			ret = ret && Read(&UndeployList.front(), sizeof(UndeployClass)*size);
		return ret;
	}
	return true;
}

bool UndeployHelper::PostLoad(bool missionSave)
{
	if (!missionSave)
	{
		for (std::vector<UndeployClass>::iterator iter = UndeployList.begin(); iter != UndeployList.end(); ++iter)
		{
			UndeployClass &sao = *iter;
			ConvertHandles(&sao.UndeployingObject, 1);
		}

		if (TempUndeployBuffer.size() == UndeployList.size())
		{
			for (int i = 0; i < int(UndeployList.size()); ++i)
			{
				if (!(TempUndeployBuffer[i] == UndeployList[i]))
				{
					FormatLogMessage("UndeployList Index Mismatch: %d", i);
					return true;
				}
			}
		}
		else
		{
			FormatLogMessage("UndeployList Size Mismatch! Old: %d New: %d", TempUndeployBuffer.size(), UndeployList.size());
		}
	}
	return true;
}

bool UndeployHelper::Save(bool missionSave)
{
	if (!missionSave)
	{
		int size = int(UndeployList.size());
		bool ret = Write(&size, 1);
		if(size)
			ret = ret && Write(&UndeployList.front(), sizeof(UndeployClass)*size);
		return ret;
	}
	return true;
}

// GBD: the slot comes off the powerup's name ("BZCundep<slot>" -> GetObjectByBaseSlot), the building's current command is cancelled (and the
// player's command panel with it when it is the selected object), the undeploy time is read in seconds and converted here, and the add is logged.
void UndeployHelper::AddUndeployObject(const Handle /*h*/, const int Team, const char *ODFName)
{
	if (strlen(ODFName) <= 7) // At least "BZCundep"; the slot digit follows it.
		return;

	const int Slot = atoi(ODFName + 8);
	Handle hbuild = GetObjectByBaseSlot(Team, Slot);
	if (!hbuild)
		return;

	SetCommand(hbuild, CMD_CANCEL);
	if (IsSelected(hbuild))
		IFace_ConsoleCmd("control.command.cancel");

	for (std::vector<UndeployClass>::iterator iter = UndeployList.begin(); iter != UndeployList.end(); ++iter)
	{
		if(iter->UndeployingObject == hbuild)
			return;
	}

	UndeployList.resize(UndeployList.size()+1);
	UndeployClass &sao = UndeployList[UndeployList.size()-1]; // No temporary being created, *much* faster
	memset(&sao, 0, sizeof(UndeployClass)); // Zero things out at start.

	char TempODF1[MAX_ODF_LENGTH] = {0};
	char TempODF2[MAX_ODF_LENGTH] = {0};
	GetAndOpenODFNames(hbuild, TempODF1, TempODF2);

	bool IsAnimated = false;
	float UndeployTime = 5.0f; // Default.

	char AnimationName[MAX_ODF_LENGTH] = {0};
	int AnimationCount = 0;
	GetODFInt(TempODF1, TempODF2, "GameObjectClass", "animCount", &AnimationCount);
	// Find out if it is animated!
	for (int i = 1; i < AnimationCount+1; i++) // Look through 16 animnames. If you made a unit that has more then 16 anims, 1: Congratulations, and 2: The deploy/undeploy one better be between 1 and 16.
	{
		char DesiredValue[MAX_ODF_LENGTH] = {0};
		sprintf_s(DesiredValue, "animName%d", i);
		if(GetODFString(TempODF1, TempODF2, "GameObjectClass", DesiredValue, MAX_ODF_LENGTH, AnimationName))
		{
			if(((_stricmp(AnimationName,"deploy") == 0) && (AnimationCount == 1)) || (_stricmp(AnimationName,"undeploy") == 0))
			{
				IsAnimated = true;
				break; // We found it, abort!
			}
		}
	}

	// Pull out DeployTime. Look in Vehicle ODF.
	char UnDepTempODF[MAX_ODF_LENGTH] = {0};
	char UnDepTempODF2[MAX_ODF_LENGTH] = {0};
	GetObjInfo(hbuild, Get_ODF, UnDepTempODF);
	UnDepTempODF[1] = 'v';
	if(OpenODF2(UnDepTempODF))
	{
		char TempClassString[MAX_ODF_LENGTH] = {0};
		if(GetODFString(UnDepTempODF, "GameObjectClass", "classlabel", MAX_ODF_LENGTH, TempClassString)) // Grab the classlabel.
		{
			CombineStrings(UnDepTempODF2, TempClassString, ".odf"); // Add .odf to the end.
			if(!OpenODF2(UnDepTempODF2))
				UnDepTempODF2[0] = '\0';
		}

		// Look in Non Tracked (Scavenger/ScavengerH) form first.
		if((GetODFFloat(UnDepTempODF, UnDepTempODF2, "DeployableClass", "timeUndeploy", &UndeployTime, 5.0f)) || 
			(GetODFFloat(UnDepTempODF, UnDepTempODF2, "TrackedDeployableClass", "timeUndeploy", &UndeployTime, 5.0f)))
			if(UndeployTime < 0) // Sanity check.
				UndeployTime = 0;
	}

	sao.UndeployingObject = hbuild;
	sao.UndeployTime = SecondsToTurns(UndeployTime); // Now dependant on ODF setting. :) //50; // 5 seconds, 10 ticks per second

	// Special note: The Game will AV if there isn't an animation to play, but the engine seems to be able to use "deploy" anim, and simply reverses it, ONLY if it is the *ONLY* animation on the object. If there is > 1 animations, it won't work.
	if(IsAnimated)
	{
		sao.UndeployFrames = SetAnimation(sao.UndeployingObject,"undeploy", 1);
		StartAnimation(sao.UndeployingObject);
		sao.IsAnimated = true;
	}

	FormatLogMessage("Adding UndeployObject: '%s', Class: '%s', Time: %d, Frames: %f", TempODF1, TempODF2, sao.UndeployTime, sao.UndeployFrames);
}

// GBD: the building's command stays cancelled while it packs up, a finished animation is paused, the replacement ODF's CategoryTypeOverride comes
// from the engine, the "no free groups" chat line is localized, and the recycler test knows CLASS_RECYCLERVEHICLEH.
void UndeployHelper::Execute(BZ1Helper &bz1Helper)
{
	// pre-clean the vector
	UndeployList.erase(std::remove_if(UndeployList.begin(), UndeployList.end(), ShouldRemoveUndeployObject), UndeployList.end());

	//BZC Undeploy additions by GSH, adapted by General BlackDragon.
	for (std::vector<UndeployClass>::iterator iter = UndeployList.begin(); iter != UndeployList.end(); ++iter)
	{
		--iter->UndeployTime;

		SetCommand(iter->UndeployingObject, CMD_CANCEL);

		if (BZ1Helper::Logging)
		{
			const float CurrFrame = GetAnimationFrame(iter->UndeployingObject, "undeploy");
			FormatLogMessage("UnbdeployObject %08d '%s' UndeployFrames: %f, CurrFrame: %f", iter->UndeployingObject, GetODFName(iter->UndeployingObject), iter->UndeployFrames, CurrFrame);
		}

		if ((iter->IsAnimated) && (GetAnimationFrame(iter->UndeployingObject, "undeploy") >= iter->UndeployFrames-1))
		{
			PauseAnimation(iter->UndeployingObject);
			iter->IsAnimated = false;
		}

		if((iter->UndeployTime < 0) && // Wait for undeploy time, and if it's got an undeploy animation, wait for the animation to finish.
			((!iter->IsAnimated) || (GetAnimationFrame(iter->UndeployingObject, "undeploy") >= iter->UndeployFrames-1)))
		{
			//replace building form with vehicle form
			int SaveTeam = GetTeamNum(iter->UndeployingObject);

			int SaveScrap = GetScrap(SaveTeam);
			int SavePilots = bz1Helper.GetPilot(SaveTeam);

			char NewODF[MAX_ODF_LENGTH] = {0};
			Handle NewUnit = 0;

			// Look for a specified UndeployClass = "odf" line in this objects ODF. If you DON'T find one, use traditional naming method.
			if((!GetODFString(iter->UndeployingObject, "GameObjectClass", "UndeployClass", MAX_ODF_LENGTH, NewODF)) || (!NewODF[0]))
			{
				char TempODF[MAX_ODF_LENGTH] = {0};
				GetODFName(iter->UndeployingObject, TempODF);
				strcpy_s(NewODF, TempODF);
				NewODF[1] = 'v';
			}

			const int CategoryType = GetCategoryTypeOverride(iter->UndeployingObject);
			bool AddToGroup = true;
			bool AddScrap = false;

			if((CategoryType > 0) && (CategoryType < 10))
				AddToGroup = false;

			// Build the new unit and restore as much information as possible. Also add it to a group if it needs to be in one.
			if((NewODF[0]) && (DoesODFExist(NewODF)) && ((!AddToGroup) || (GetFirstEmptyGroup(SaveTeam) >= 0)))
			{
				NewUnit = bz1Helper.ReplaceObject(iter->UndeployingObject, NewODF);

				if(AddToGroup)
					SetBestGroup(NewUnit);

				char ObjClass[MAX_ODF_LENGTH] = {0};
				GetObjInfo(NewUnit, Get_GOClass, ObjClass);
				if((GetODFBool(NewUnit, "ScavengerClass", "AddScrapHoldToTotal", &AddScrap)) || 
					(GetODFBool(NewUnit, "ScavengerHClass", "AddScrapHoldToTotal", &AddScrap)))
				{
					if((AddScrap) || (_stricmp(ObjClass, "CLASS_RECYCLERVEHICLE") == 0) || (_stricmp(ObjClass, "CLASS_RECYCLERVEHICLEH") == 0))
						SetScrap(SaveTeam, SaveScrap);
				}

				bz1Helper.SetPilot(SaveTeam, SavePilots);
			}
			else
			{
				if(!DoesODFExist(NewODF))
				{
					FormatLogMessage("ERROR: ODF '%s' Doesn't Exist! Cannot Undeploy!", NewODF); 
				}
				else
				{
					FormatLogMessage("ERROR: No Free Group! Cannot Undeploy!");

					if((GetLocalPlayerTeamNumber() == SaveTeam) && (IsNetworkOn()))
						AddToMessagesBox2(GetBZCCLocalizedString("mission", "-- Can't Undeploy, No Free Groups."), RED);
				}
			}
		}
	}
}
