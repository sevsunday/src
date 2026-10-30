// PROVENANCE: ancestor reference/ancestor-bz1helper-2015/Shared/PortalHelper.cpp @6fda4f5 (registration, destination lock, the Ken Miller teleport math, the effect controllers) | decompile reference/decompiled/strategy02-ghidra12.2/src/missions/vsrcore/portalhelper.cpp.decomp.c (Load 26-50, PostLoad 53-101, Save 104-121, AddPortalSwitchObject 124-148, AddPortalObject 151-359, Execute 362-839, ExecuteObject 842-1187, SetPortalEffectStart_Internal 1234-1333, SetPortalEffectOn_Internal 1351-1409, SetPortalEffectEnd 1413-1425, SetPortalEffectEnd_Internal 1427-1514, SetPortalEffectVeh_Internal 1536-1562, SetPortalDest 1603-1643, ShufflePortalDownInternal 1754-1821, ShufflePortalUpInternal 1851-1897, ResetPortalDestinations 1901-1914, SortCycleList 1918-1935, PlayPortalSoundFx 1939-1985) + the LuaBindings decompile for the inlined public members + dumpbin of 4fc27c26 / 4fc284f1 / 4fc28fec / 4fc2a209 for the register-passed arguments | status: ported
#include "bz1helper.h"
#include "portalhelper.h"
#include "buildinghelper.h"
#include "bzcscriptutils.h"
#include <algorithm>

PortalHelper *PortalHelper::m_PortalHelper;

std::vector<PortalHelper::PortalClass> TempPortalBuffer; // GBD: the lists as they stood before a Load, for PostLoad's resync report.
std::vector<PortalHelper::TeleportTargetClass> TempTeleportTargetBuffer;

PortalHelper::PortalHelper()
{
	m_PortalHelper = this;
}
PortalHelper::~PortalHelper()
{
	m_PortalHelper = NULL;
}

// A teleported object is tracked until it leaves the destination's entrance range (+5 m), so it can't bounce straight back.
bool PortalHelper::ShouldRemoveTeleportTarget(const TeleportTargetClass &entry)
{
	return !((entry.DistanceFromDestination <= Squared(entry.DestEnterRange + 5.0f)) && (IsAround(entry.TeleportTarget)) && (IsAround(entry.TeleportTargetDestination)));
}

bool PortalHelper::Load(bool missionSave)
{
	if (!missionSave)
	{
		TempPortalBuffer = PortalList;
		TempTeleportTargetBuffer = TeleportTargetList;

		int size = 0;
		bool ret = Read(&size, 1);
		PortalList.resize(size);
		if(size)
			ret = ret && Read(&PortalList.front(), sizeof(PortalClass)*size);

		size = 0;
		ret = ret && Read(&size, 1);
		TeleportTargetList.resize(size);
		if(size)
			ret = ret && Read(&TeleportTargetList.front(), sizeof(TeleportTargetClass)*size);
		return ret;
	}
	return true;
}

bool PortalHelper::PostLoad(bool missionSave)
{
	if (!missionSave)
	{
		for (std::vector<PortalClass>::iterator iter = PortalList.begin(); iter != PortalList.end(); ++iter)
		{
			PortalClass &sao = *iter;
			ConvertHandles(&sao.TeleporterObject, 1);
			ConvertHandles(&sao.TeleporterDestination, 1);
			ConvertHandles(&sao.PortalMineHost, 1);
			if (sao.PortalMineHost) // A portal mine's channel is its host's handle, so it follows the converted handle.
				sao.Channel = sao.PortalMineHost;
		}

		for (std::vector<TeleportTargetClass>::iterator iter = TeleportTargetList.begin(); iter != TeleportTargetList.end(); ++iter)
		{
			TeleportTargetClass &sao = *iter;
			ConvertHandles(&sao.TeleportTarget, 1);
			ConvertHandles(&sao.TeleportTargetDestination, 1);
		}

		// GBD: resync report — compare what we had against what we loaded.
		if (TempPortalBuffer.size() == PortalList.size())
		{
			for (int i = 0; i < int(PortalList.size()); i++)
			{
				if (!(TempPortalBuffer[i] == PortalList[i]))
				{
					FormatLogMessage("PortalList Index Mismatch: %d", i);
					break;
				}
			}
		}
		else
		{
			FormatLogMessage("PortalList Size Mismatch! Old: %d New: %d", TempPortalBuffer.size(), PortalList.size());
		}

		if (TempTeleportTargetBuffer.size() == TeleportTargetList.size())
		{
			for (int i = 0; i < int(TeleportTargetList.size()); i++)
			{
				if (!(TempTeleportTargetBuffer[i] == TeleportTargetList[i]))
				{
					FormatLogMessage("TeleportTargetList Index Mismatch: %d", i);
					break;
				}
			}
		}
		else
		{
			FormatLogMessage("TeleportTargetList Size Mismatch! Old: %d New: %d", TempTeleportTargetBuffer.size(), TeleportTargetList.size());
		}
	}
	return true;
}

bool PortalHelper::Save(bool missionSave)
{
	if (!missionSave)
	{
		int size = int(PortalList.size());
		bool ret = Write(&size, 1);
		if(size)
			ret = ret && Write(&PortalList.front(), sizeof(PortalClass)*size);

		size = int(TeleportTargetList.size());
		ret = ret && Write(&size, 1);
		if(size)
			ret = ret && Write(&TeleportTargetList.front(), sizeof(TeleportTargetClass)*size);
		return ret;
	}
	return true;
}

// A portal switch sets the nearest portal's channel, then goes away.
void PortalHelper::AddPortalSwitchObject(const Handle h, const char* TempODF1, const char* TempODF2)
{
	int TempChannel = -1;
	// Look for new ODF Parameters.
	GetODFInt(TempODF1, TempODF2, "TeleportalSwitchClass", "PortalChannel", &TempChannel, -1);
	if(TempChannel >= 0)
	{
		float BestDistSquared = FLT_MAX;
		int Choice = -1;

		for (std::vector<PortalClass>::iterator iter = PortalList.begin(); iter != PortalList.end(); ++iter)
		{
			// Loop through and compare distances. If it finds one closer, save it.
			float DistSquared = GetDistance3DSquared(h, iter->TeleporterObject);
			if(DistSquared < BestDistSquared)
			{
				Choice = int(iter - PortalList.begin());
				BestDistSquared = DistSquared; // Compare new distance.
			}
		}
		if(Choice >= 0)
			PortalList[Choice].Channel = TempChannel;
	}
	BZ1Helper::Get().DeleteAfterDelay(h, 0.0f);
}

void PortalHelper::AddPortalObject(const Handle h, const char* TempODF1, const char* TempODF2, const int BZCClassHash)
{
	// A portal that is re-added (its ODF changed) re-reads everything into its existing slot.
	int Index = -1;
	for (std::vector<PortalClass>::iterator iter = PortalList.begin(); iter != PortalList.end(); ++iter)
	{
		if(iter->TeleporterObject == h)
		{
			Index = int(iter - PortalList.begin());
			break;
		}
	}
	if (Index < 0)
	{
		PortalList.resize(PortalList.size()+1);
		Index = int(PortalList.size())-1;
	}
	PortalClass &sao = PortalList[Index]; // No temporary being created, *much* faster
	memset(&sao, 0, sizeof(PortalClass)); // Zero things out at start.

	GetODFFloat(TempODF1, TempODF2, "GameObjectClass", "CollisionRadius", &sao.CollisionRadius, 0.0f);
	GetODFString(TempODF1, TempODF2, "TeleportalClass", "PortalEffect", MAX_ODF_LENGTH, sao.EffectBaseODF);
	GetODFInt(TempODF1, TempODF2, "TeleportalClass", "InEffect", &sao.InEffect, 0);
	GetODFInt(TempODF1, TempODF2, "TeleportalClass", "OutEffect", &sao.OutEffect, 0);
	GetODFInt(TempODF1, TempODF2, "TeleportalClass", "OnEffect", &sao.OnEffect, 0);
	GetODFInt(TempODF1, TempODF2, "TeleportalClass", "VehInEffect", &sao.VehInEffect, 0);
	GetODFInt(TempODF1, TempODF2, "TeleportalClass", "VehOutEffect", &sao.VehOutEffect, 0);
	GetODFBool(TempODF1, TempODF2, "TeleportalClass", "FxOnVehicle", &sao.FxOnVehicle, false);
	GetODFString(TempODF1, TempODF2, "TeleportalClass", "soundActivate", MAX_ODF_LENGTH, sao.ActivateSound);
	GetODFString(TempODF1, TempODF2, "TeleportalClass", "soundDeactivate", MAX_ODF_LENGTH, sao.DeactivateSound);

	// VSR: the portal effects are the object's own emitters; mask them off until they are started.
	unsigned long EffectsMask = 0xffff;
	if ((GetODFInt(TempODF1, TempODF2, "GameObjectClass", "effectsMask", (int *)&EffectsMask, 0)) && (GetEmitterMask(h) == 0xffff))
		MaskEmitter(h, EffectsMask);

	// How long each emitter's effect lives, from its ODF (EffectNameN = "odf" or "odf.block").
	for (int i = 1; i <= 16; i++)
	{
		char DesiredValue[MAX_ODF_LENGTH] = {0};
		sprintf_s(DesiredValue, "EffectName%d", i);
		char EffectName[MAX_ODF_LENGTH] = {0};
		if (GetODFString(TempODF1, TempODF2, "GameObjectClass", DesiredValue, MAX_ODF_LENGTH, EffectName))
		{
			char *Dot = strrchr(EffectName, '.');
			char EffectODF[MAX_ODF_LENGTH] = {0};
			char EffectBlock[MAX_ODF_LENGTH] = {0};
			float LifeTime = 0.0f;
			if (!Dot)
			{
				sprintf_s(EffectODF, "%s.odf", EffectName);
				if ((OpenODF2(EffectODF)) && (GetODFFloat(EffectODF, EffectName, "lifeTime", &LifeTime, 0.0f)))
					sao.EffectHardLifeTime[i-1] = SecondsToTurns(LifeTime);
			}
			else
			{
				strcpy_s(EffectBlock, Dot+1);
				*Dot = '\0';
				strncpy_s(EffectODF, EffectName, _TRUNCATE);
				sprintf_s(EffectODF, "%s.odf", EffectName);
				if ((OpenODF2(EffectODF)) && (GetODFFloat(EffectODF, EffectBlock, "lifeTime", &LifeTime, 0.0f)))
					sao.EffectHardLifeTime[i-1] = SecondsToTurns(LifeTime);
			}
		}
	}

	strcpy_s(sao.TeleporterName, GetObjectiveName(h));
	GetODFInt(TempODF1, TempODF2, "TeleportalClass", "TeleporterChannel", &sao.Channel, 0);
	GetODFBool(TempODF1, TempODF2, "TeleportalClass", "ShowChannel", &sao.ShowChannel, true);
	GetODFBool(TempODF1, TempODF2, "TeleportalClass", "CanEnter", &sao.CanEnter, true);
	GetODFBool(TempODF1, TempODF2, "TeleportalClass", "CanExit", &sao.CanExit, true);
	GetODFInt(TempODF1, TempODF2, "TeleportalClass", "MatchType", &sao.MatchType, 0);
	GetODFBool(TempODF1, TempODF2, "TeleportalClass", "MatchTypeUsesChannels", &sao.MatchTypeUsesChannels, true);
	GetODFBool(TempODF1, TempODF2, "TeleportalClass", "ContinuousFx", &sao.ContinuousFx, false);
	GetODFFloat(TempODF1, TempODF2, "TeleportalClass", "ContinuousFxRange", &sao.ContinuousFxRange, 0.0f);
	GetODFColor(TempODF1, TempODF2, "TeleportalClass", "TeleportColorFade", &sao.TeleportColorFade, 0);
	GetODFInt(TempODF1, TempODF2, "TeleportalClass", "TeleportFilter", &sao.TeleportFilter, 15);
	// Make 0 All Types.
	if(sao.TeleportFilter == 0)
		sao.TeleportFilter = 31;

	GetODFFloat(TempODF1, TempODF2, "TeleportalClass", "ExitVelocity", &sao.ExitSpeed, 0.0f);
	GetODFBool(TempODF1, TempODF2, "TeleportalClass", "ExitForwardOnly", &sao.ExitForwardOnly, false);
	GetODFBool(TempODF1, TempODF2, "TeleportalClass", "ExitKickAI", &sao.KickAI, false);
	GetODFBool(TempODF1, TempODF2, "TeleportalClass", "ExitUsesCenter", &sao.UseCenter, true);
	GetODFBool(TempODF1, TempODF2, "TeleportalClass", "EnterGotoIsExit", &sao.EnterGotoIsExit, false);
	GetODFFloat(TempODF1, TempODF2, "TeleportalClass", "EnterRange", &sao.EnterRange, 10.0f);
	GetODFFloat(TempODF1, TempODF2, "TeleportalClass", "DestinationMinRange", &sao.DestMinRange, 0.0f);
	GetODFFloat(TempODF1, TempODF2, "TeleportalClass", "DestinationMaxRange", &sao.DestMaxRange, 0.0f);
	GetODFInt(TempODF1, TempODF2, "TeleportalClass", "TeleportTeamFilter", &sao.TargetTeamFilter, 7);
	// Make 0 all teams.
	if(sao.TargetTeamFilter == 0)
		sao.TargetTeamFilter = 7;

	GetODFInt(TempODF1, TempODF2, "TeleportalClass", "DestinationTeamFilter", &sao.DestTeamFilter, 3);
	// Make 0 all teams.
	if(sao.DestTeamFilter == 0)
		sao.DestTeamFilter = 7;

	sao.ExitPoint = GetODFPositionOffset(h, 0);
	sao.GotoPoint = GetODFPositionOffset(h, 1).posit;
	sao.Position = GetPosition(h);
	sao.DestinationIndex = -1;

	if (BZCClassHash == BZCCLASS_PORTAL_MINE)
	{
		// VSR: a portal mine pairs with the other mine its host dropped: the host's handle is the channel.
		sao.PortalMineHost = GetNearestVehicle(h);
		sao.Channel = sao.PortalMineHost;
		GetODFString(TempODF1, TempODF2, "TeleportalMineClass", "TooFarSound", MAX_ODF_LENGTH, sao.TooFarSound);
		GetODFString(TempODF1, TempODF2, "TeleportalMineClass", "TooCloseSound", MAX_ODF_LENGTH, sao.TooCloseSound);
	}
	else
	{
		//!! Get Label set function for Map Makers.
		const char *Label = GetLabel(h);
		if (Label)
		{
			if (_strnicmp(Label, "channel_", 8) == 0)
			{
				char ChannelNum[MAX_ODF_LENGTH] = {0};
				const char *pUnderscore = strchr(Label, '_');
				CombineStrings(ChannelNum, "", pUnderscore+1);
				sao.Channel = atoi(ChannelNum);
			}
			else if ((_strnicmp(Label, "Portal", 6) == 0) && (isalpha(Label[6])) && (isdigit(Label[7]))) // VSR: "Portal<letter><digit>" labels: the letter is the channel, the digit the cycle position.
			{
				sao.Channel = Label[6];
				if (sao.MatchType == PortalMatchType_Cycle)
					sao.DestinationIndex = Label[7] - '0';
			}
		}
	}

	sao.TeleporterObject = h;

	// VSR: AllowOnlyTwo keeps one other portal on this team's channel; any further ones are removed. (sic: it runs when the KEY is present, whatever its value.)
	bool AllowOnlyTwo = false;
	if (GetODFBool(TempODF1, TempODF2, "TeleportalClass", "AllowOnlyTwo", &AllowOnlyTwo, false))
	{
		sao.Channel += GetTeamNum(h);
		bool FoundOther = false;
		for (int i = int(PortalList.size()) - 1; i >= 0; i--)
		{
			PortalClass &other = PortalList[i];
			if ((other.Channel == sao.Channel) && (other.TeleporterObject != h))
			{
				if (!FoundOther)
				{
					FoundOther = true;
				}
				else
				{
					BZ1Helper::Get().DeleteAfterDelay(other.TeleporterObject, 0.0f);
					SetPortalEffectEnd(other.TeleporterObject, 0, 0, true);
				}
			}
		}
	}

	if (sao.MatchType == PortalMatchType_Cycle)
		SortCycleList(sao.Channel);
}

void PortalHelper::Execute(BZ1Helper &bz1Helper)
{
	const bool Logging = BZ1Helper::Logging;

	// Sweep through the list and remove any of them that are no longer around; a dead cycle portal re-sorts its channel.
	int ChannelToSort = -1;
	std::vector<PortalClass>::iterator validEnd = PortalList.begin();
	std::vector<PortalClass>::iterator lastValid = PortalList.begin();
	for (std::vector<PortalClass>::iterator iter = PortalList.begin(); iter != PortalList.end(); ++iter)
	{
		if (IsAround(iter->TeleporterObject))
		{
			// Copy the valid entry into the valid portion
			if (lastValid != iter)
				*validEnd = *iter;
			++validEnd;
		}
		else if (iter->MatchType == PortalMatchType_Cycle)
		{
			ChannelToSort = iter->Channel;
		}
	}
	// Now erase any invalid entries left behind
	PortalList.erase(validEnd, PortalList.end());
	if (ChannelToSort >= 0)
		SortCycleList(ChannelToSort);

	// pre-clean the vector
	TeleportTargetList.erase(std::remove_if(TeleportTargetList.begin(), TeleportTargetList.end(), ShouldRemoveTeleportTarget), TeleportTargetList.end());

	// Loop over all teleporters, and lock their destinations.
	for (std::vector<PortalClass>::iterator iter = PortalList.begin(); iter != PortalList.end(); ++iter)
	{
		const int Index = int(iter - PortalList.begin());
		const int Team = GetTeamNum(iter->TeleporterObject);
		const Vector OldPosition = iter->Position;
		iter->Position = GetPosition(iter->TeleporterObject);
		Handle Nearest = 0;
		if ((iter->ContinuousFx) && (iter->ContinuousFxRange != 0.0f))
			Nearest = GetNearestVehicle(iter->TeleporterObject);

		// VSR: a portal that holds still refreshes its exit / goto points (as shipped: while it moves they are left alone).
		if ((fabsf(iter->Position.x - OldPosition.x) < 0.01f) && (fabsf(iter->Position.y - OldPosition.y) < 0.01f) && (fabsf(iter->Position.z - OldPosition.z) < 0.01f))
		{
			iter->ExitPoint = GetODFPositionOffset(iter->TeleporterObject, 0);
			iter->GotoPoint = GetODFPositionOffset(iter->TeleporterObject, 1).posit;
		}

		// Set it's Name for allies only.
		if(iter->ShowChannel)
		{
			// Make the name switch back and forth every 3 seconds.
			if(((BZ1Helper::m_TurnCounter % SecondsToTurns(1.0f)) == 0) && (!iter->NameFlash))
			{
				if(IsTeamAllied(GetLocalPlayerTeamNumber(), Team))
					SetObjectiveName(iter->TeleporterObject, iter->TeleporterName);

				iter->NameFlash = true;
			}
			if(((BZ1Helper::m_TurnCounter % SecondsToTurns(3.0f)) == 0) && (iter->NameFlash))
			{
				if(IsTeamAllied(GetLocalPlayerTeamNumber(), Team))
				{
					char Name[256] = {0};
					sprintf_s(Name, GetBZCCLocalizedString("cfg", "Channel %d"), iter->Channel);
					SetObjectiveName(iter->TeleporterObject, Name);
				}
				iter->NameFlash = false;
			}
		}

		// If this teleporter can be entered, and IsPowered (a portal mine always is), run this code.
		if((iter->CanEnter) && ((iter->PortalMineHost != 0) || (BuildingHelper::Get().IsBuildingPowered(iter->TeleporterObject))))
		{
			if (!iter->ScriptOverrideDest)
			{
				const Handle OldDestination = iter->TeleporterDestination;
				const int OldDestinationIndex = iter->DestinationIndex;
				iter->TeleporterDestination = 0; // Zero this out to remove old, possibly obsolete destinations.
				iter->DestinationIndex = 0;

				if (iter->MatchType == PortalMatchType_Distance) // Lock on based on distance.
				{
					float TeleDistanceSquared = FLT_MAX;
					Handle TeamTeleporter = 0;
					int TeamIndex = -1;
					int DestTeam = -1;
					// Loop over all portals. Find one that is closest, and allied.
					for (std::vector<PortalClass>::iterator iterB = PortalList.begin(); iterB != PortalList.end(); ++iterB)
					{
						int t = GetTeamNum(iterB->TeleporterObject);

						// This is a portal we care about...
						if( ((!iter->MatchTypeUsesChannels) || (iter->Channel == iterB->Channel)) && // The channels match.
							(iterB->CanExit) && // It can be exited.
							(TeamFilterCheck(iter->DestTeamFilter, t, Team)) && // Team Matches.
							((iterB->PortalMineHost != 0) || (BuildingHelper::Get().IsBuildingPowered(iterB->TeleporterObject)))) // Target Portal has power.
						{
							if (iter->TeleporterObject == iterB->TeleporterObject) // This teleporter is not itself.
								continue;
							float DistSquared = GetDistance3DSquared(iter->Position, iterB->Position); // Compare new distance.
							if (TeleDistanceSquared <= DistSquared) // This one is not closer.
								continue;
							if ((iter->DestMinRange != 0.0f) && (DistSquared <= Squared(iter->DestMinRange))) // Too close.
								continue;
							if ((iter->DestMaxRange != 0.0f) && (Squared(iter->DestMaxRange) <= DistSquared)) // Too far.
								continue;

							if(t == Team) // Only look on our team.
							{
								TeamTeleporter = iterB->TeleporterObject;
								TeamIndex = int(iterB - PortalList.begin());
							}

							iter->TeleporterDestination = iterB->TeleporterObject;
							iter->DestinationIndex = int(iterB - PortalList.begin());
							DestTeam = t;
							TeleDistanceSquared = DistSquared; // Compare new distance.
						}
					}
					// If the closest one is not on our team, try to find one that is.
					if((DestTeam != Team) && ((iter->DestTeamFilter & 1) == 1) && (TeamTeleporter)) // If teamfilter includes Same Team, look there first.
					{
						iter->TeleporterDestination = TeamTeleporter;
						iter->DestinationIndex = TeamIndex;
					}
				}
				else if (iter->MatchType == PortalMatchType_Cycle) // The next portal on the channel.
				{
					if (IsAround(OldDestination))
					{
						iter->TeleporterDestination = OldDestination;
						iter->DestinationIndex = OldDestinationIndex;
					}
					else
					{
						const int Last = int(PortalList.size()) - 1;
						if ((Last >= 0) && (Last > 0))
						{
							const int Start = (Index <= Last) ? Index : 0;
							int i = Start;
							do
							{
								const PortalClass &other = PortalList[i];
								GetTeamNum(other.TeleporterObject); // sic: read, not used.
								if( ((!iter->MatchTypeUsesChannels) || (iter->Channel == other.Channel)) &&
									(other.CanExit) &&
									(TeamFilterCheck(iter->DestTeamFilter, GetTeamNum(other.TeleporterObject), Team)) &&
									((other.PortalMineHost != 0) || (BuildingHelper::Get().IsBuildingPowered(other.TeleporterObject))) &&
									(iter->TeleporterObject != other.TeleporterObject))
								{
									iter->TeleporterDestination = other.TeleporterObject;
									iter->DestinationIndex = i;
									break;
								}
								i = (i + 1 <= Last) ? i + 1 : 0;
							} while (i != Start);
						}
					}
				}
				else if (iter->MatchType == PortalMatchType_Random) // Pick a Random one.
				{
					if (IsAround(OldDestination))
					{
						iter->TeleporterDestination = OldDestination;
						iter->DestinationIndex = OldDestinationIndex;
					}
					const int Random = GetRandomInt(0, int(PortalList.size())-1);
					const PortalClass &other = PortalList[Random];
					GetTeamNum(other.TeleporterObject); // sic: read, not used.
					if( ((!iter->MatchTypeUsesChannels) || (iter->Channel == other.Channel)) && // If Channels, channels match.
						(other.CanExit) &&  // Can be exited.
						(TeamFilterCheck(iter->DestTeamFilter, GetTeamNum(other.TeleporterObject), Team)) && // Teamfilter matches.
						((other.PortalMineHost != 0) || (BuildingHelper::Get().IsBuildingPowered(other.TeleporterObject))) && // Target Portal Has Power.
						(iter->TeleporterObject != other.TeleporterObject)) //It is not itself.
					{
						const float DistSquared = GetDistance3DSquared(iter->Position, other.Position);
						if (((iter->DestMinRange == 0.0f) || (Squared(iter->DestMinRange) < DistSquared)) &&
							((iter->DestMaxRange == 0.0f) || (DistSquared < Squared(iter->DestMaxRange))))
						{
							iter->TeleporterDestination = other.TeleporterObject;
							iter->DestinationIndex = Random;
						}
					}
				}
			}

			// If it found something, run the continuous effect.
			if((iter->TeleporterDestination) && (iter->ContinuousFx))
			{
				if (!IsEmitterOn(iter->TeleporterObject, iter->TeleporterEffectSlot))
				{
					if (iter->ContinuousFxRange == 0.0f)
						SetPortalEffectStart_Internal(Index, iter->OnEffect, 1, true);
					else if ((Nearest) && (GetDistance3DSquared(iter->Position, GetPosition(Nearest)) < Squared(iter->ContinuousFxRange)))
						SetPortalEffectStart_Internal(Index, iter->OnEffect, 1, true);
				}
			}
		} // Tele can be entered.

		// Count the emitter timers down; a slot whose time is up is stopped, unless it is the one the current effect runs on.
		for (int i = 0; i < 16; i++)
		{
			if (iter->EffectTimer[i] < 2)
			{
				if ((iter->EffectTimer[i] > 0) && (i != iter->TeleporterEffectSlot - 1))
					StopEmitter(iter->TeleporterObject, i + 1);
			}
			else
			{
				iter->EffectTimer[i]--;
			}
		}
		const bool SlotTimerDone = (iter->TeleporterEffectSlot != 0) && (iter->EffectTimer[iter->TeleporterEffectSlot - 1] <= 1);

		// Generate and Switch Effect states here.
		switch (iter->EffectState)
		{
		case PortalEffectState_Opening:
			switch (iter->EffectType)
			{
			case 0: // One way: the opening is all there is.
				if (SlotTimerDone)
				{
					StopEmitter(iter->TeleporterObject, iter->TeleporterEffectSlot);
					if (Logging)
						FormatConsoleMessage("Clearing Portal FX: Mode PortalType_NONE Slot: %d, EmitterMask: %d", iter->TeleporterEffectSlot, GetEmitterMask(iter->TeleporterObject));
					iter->TeleporterEffectSlot = 0;
					iter->EffectState = PortalEffectState_None;
				}
				break;
			case 1: // Continuously On: switch to the On effect.
				if (SlotTimerDone)
					SetPortalEffectOn_Internal(Index, iter->EffectNumber, 1, true);
				break;
			case 2: // Build effect (open then close).
				if (SlotTimerDone)
					SetPortalEffectEnd_Internal(Index, iter->EffectNumber, 2, true);
				break;
			}
			break;
		case PortalEffectState_Open:
			if(iter->ContinuousFx)
			{
				if (iter->TeleporterDestination == 0) // If the destination isn't around, or FxRange > 0 and nearest unit is > Range.
					SetPortalEffectEnd_Internal(Index, iter->EffectNumber, iter->EffectType, true);
				else if ((iter->ContinuousFxRange != 0.0f) && (Nearest) && (Squared(iter->ContinuousFxRange) < GetDistance3DSquared(iter->Position, GetPosition(Nearest))))
					SetPortalEffectEnd_Internal(Index, iter->EffectNumber, iter->EffectType, true);
			}
			break;
		case PortalEffectState_Closing:
			if (SlotTimerDone)
			{
				if (IsEmitterOn(iter->TeleporterObject, iter->TeleporterEffectSlot))
				{
					StopEmitter(iter->TeleporterObject, iter->TeleporterEffectSlot);
					if (Logging)
						FormatConsoleMessage("Clearing Portal FX: Mode PortalType_Closing, Slot: %d, EffectMask: %d", iter->TeleporterEffectSlot, GetEmitterMask(iter->TeleporterObject));
					iter->TeleporterEffectSlot = 0;
				}
				iter->EffectState = PortalEffectState_None;
			}
			break;
		}
	} // loop over all Teleporters.

	// Loop over all Targets, and see if they cleared a teleporter.
	for (std::vector<TeleportTargetClass>::iterator iter = TeleportTargetList.begin(); iter != TeleportTargetList.end(); ++iter)
	{
		if(IsAround(iter->TeleportTargetDestination))
		{
			iter->DistanceFromDestination = GetDistance3DSquared(GetPosition(iter->TeleportTarget), PortalList[iter->DestinationIndex].Position);

			if(Logging)
				FormatLogMessage("Teleporter Target Index: %d Just Teleported, Distnace is: %f", int(iter-TeleportTargetList.begin()), iter->DistanceFromDestination);
		}
	}
}

void PortalHelper::ExecuteObject(const ObjectHelper::ObjectClass &objectInfo)
{
	const bool Logging = BZ1Helper::Logging;

	const Handle TempH = objectInfo.ObjectHandle;
	Handle Tugee = 0;
	Vector Velocity(0, 0, 0);
	int MineHostHits = 0;

	for (std::vector<TeleportTargetClass>::iterator iter = TeleportTargetList.begin(); iter != TeleportTargetList.end(); ++iter)
	{
		if(iter->TeleportTarget == TempH)
			return; // Skip this object, it's already a Teleporter Target.
	}
	if (PortalList.empty())
		return;

	std::vector<PortalClass>::iterator iter = PortalList.begin();
	float TempDistSquared = 0.0f;
	int Team = 0;
	int t = 0;
	for (;; ++iter)
	{
		if (iter == PortalList.end())
			return;

		if(iter->TeleporterObject == TempH)
			return; // Skip this object, it's a teleporter.

		for(int x = 0; x < MAX_TAPS;x++)
		{
			if(TempH == GetTap(iter->TeleporterObject, x))
				return; // Skip this object, it's a tap of a Teleporter.
		}

		if ((iter->PortalMineHost != 0) && (TempH == iter->PortalMineHost))
			MineHostHits++;

		// VSR: a unit sent to the portal is sent to its entrance (or straight to the exit point).
		if (WhoFollowing(TempH) == iter->TeleporterObject)
		{
			if (iter->EnterGotoIsExit)
				Goto(TempH, iter->ExitPoint.posit, 0);
			else
				Goto(TempH, iter->TeleporterObject, 0);
		}

		if (iter->TeleporterDestination == 0)
		{
			// VSR: the host of an unpaired second mine dropped it too far from (or too close to) the first: tell him and remove them.
			if ((iter->PortalMineHost != 0) && (TempH == iter->PortalMineHost) && (MineHostHits > 1))
			{
				float Dist = 0.0f;
				for (std::vector<PortalClass>::iterator iterB = PortalList.begin(); iterB != PortalList.end(); ++iterB)
				{
					if (TempH == iterB->PortalMineHost)
					{
						Dist = GetDistance(iter->TeleporterObject, iterB->TeleporterObject);
						break;
					}
				}
				if (TempH == GetPlayerHandle())
				{
					const char *Sound = NULL;
					if (Dist > iter->DestMaxRange)
						Sound = iter->TooFarSound;
					else if (Dist < iter->DestMinRange)
						Sound = iter->TooCloseSound;
					if (Sound)
						StartAudio2D(Sound, -1.0f, 0.0f, -1.0f, false, false);
				}
				BZ1Helper::Get().DeleteAfterDelay(iter->TeleporterObject, 0.0f);
				BZ1Helper::Get().DeleteAfterDelay(PortalList[iter->DestinationIndex].TeleporterObject, 0.0f);
			}
			continue; // This teleporter has no destination, skip it.
		}

		const long TempCurAmmo = GetCurAmmo(iter->TeleporterObject);
		const long TempMaxAmmo = GetMaxAmmo(iter->TeleporterObject);
		Team = GetTeamNum(iter->TeleporterObject);
		t = objectInfo.CurTeamNum;
		if (iter->PortalMineHost == 0)
			TempDistSquared = GetDistance3DSquared(objectInfo.Position, iter->Position);
		else
			TempDistSquared = GetDistance2DSquared(objectInfo.Position, iter->ExitPoint.posit); // A mine's entrance is its exit point.

		if (TempDistSquared < Squared(iter->EnterRange)) // Its within Range.
		{
			const PreTeleportReturnCodes Pre = BZ1Helper::Get().PreTeleport(iter->TeleporterObject, TempH);
			if (Pre == PreTeleport_ALLOW)
				break;
			// Conditions for Teleportation.
			if( (Pre == PreTeleport_DEFAULT) &&
				(TempCurAmmo == TempMaxAmmo) && // Its ammo is fully recharged.
				(TeamFilterCheck(iter->TargetTeamFilter, t, Team)) && // Teamfilter passes.
				((((iter->TeleportFilter & 1) == 1) && (objectInfo.CategoryID == CategoryType_Craft)) || // Teleport Ships.
				(((iter->TeleportFilter & 2) == 2) && (objectInfo.CategoryID == CategoryType_Person)) || // Teleport Pilots.
				(((iter->TeleportFilter & 4) == 4) && (objectInfo.CategoryID == CategoryType_Powerup)) || // Teleport Powerups.
				(((iter->TeleportFilter & 8) == 8) && (objectInfo.CategoryID == CategoryType_Weapon)) || // Teleport Weapons.
				(((iter->TeleportFilter & 16) == 16) && (objectInfo.CategoryID == CategoryType_Other))) && // Teleport Misc.
				(GetTug(TempH) == 0) && // Target isn't being tugged.
				((iter->PortalMineHost == 0) || (TempH == iter->PortalMineHost)) && // A mine only takes its host.
				(!IsNullVector(PortalList[iter->DestinationIndex].ExitPoint.posit))) // It's position isn't NULL.
			{
				break;
			}
		}
	} // loop over all Portals

	if(Logging)
		FormatLogMessage("Locking onto Object: %08x, ODF: '%s', Distance is: %f", TempH, GetODFName(TempH), sqrtf(TempDistSquared));

	// Look for this object to be tugging something, if so, save it.
	for (std::vector<TeleportTargetClass>::iterator iterB = TeleportTargetList.begin(); iterB != TeleportTargetList.end(); ++iterB)
	{
		if(GetTug(iterB->TeleportTarget) == TempH)
		{
			Tugee = iterB->TeleportTarget;
			break;
		}
	}

	const int DestIndex = iter->DestinationIndex;
	// We're good to Teleport, add the Teleportee to the List.
	TeleportTargetList.resize(TeleportTargetList.size()+1);
	{
		TeleportTargetClass &sao = TeleportTargetList[TeleportTargetList.size()-1]; // No temporary being created, *much* faster
		memset(&sao, 0, sizeof(TeleportTargetClass)); // Zero things out at start.
		sao.TeleportTarget = TempH; // Save it.
		sao.DestEnterRange = PortalList[DestIndex].EnterRange; // Save it.
		sao.TeleportTargetDestination = iter->TeleporterDestination; // Save it.
		sao.DestinationIndex = DestIndex;
	}
	const PortalClass &dest = PortalList[DestIndex];

	const Matrix &StartPortal = iter->ExitPoint;
	const Matrix ShipSpawn = GetMatrixPosition(TempH);
	const Vector ShipVelocity = GetVelocity(TempH);
	Matrix NewMatrix = dest.ExitPoint;
	Matrix Teleport;

	if (!dest.ExitForwardOnly)
	{
		// New code from Ken Miller: the exit is turned around, so the ship keeps its heading relative to the portal.
		NewMatrix.right = Neg_Vector(NewMatrix.right);
		NewMatrix.front = Neg_Vector(NewMatrix.front);
		Teleport = Matrix_Multiply(Matrix_Inverse(StartPortal), NewMatrix);
		NewMatrix = Matrix_Multiply(ShipSpawn, Teleport);
		Velocity = Vector_Rotate(Teleport, ShipVelocity);
	}
	else
	{
		// VSR: the ship leaves facing exactly the way the exit points, at its own speed.
		Teleport = Matrix_Multiply(Matrix_Inverse(StartPortal), dest.ExitPoint);
		const Vector Offset = Vector_TransformInv(ShipSpawn, StartPortal.posit);
		NewMatrix.posit = Vector_Transform(dest.ExitPoint, Offset);
		Velocity = Vector_Scale(dest.ExitPoint.front, GetLength3D(ShipVelocity));
	}

	// Override position floating, use root exit position.
	if(dest.UseCenter)
		NewMatrix.posit = dest.ExitPoint.posit;

	if(Logging)
	{
		FormatLogMessage("Entrance Front Vector Is %f %f %f", StartPortal.front.x, StartPortal.front.y, StartPortal.front.z);
		FormatLogMessage("Exit Front Vector Is %f %f %f", dest.ExitPoint.front.x, dest.ExitPoint.front.y, dest.ExitPoint.front.z);
		FormatLogMessage("Player Front Vector Is %f %f %f", ShipSpawn.front.x, ShipSpawn.front.y, ShipSpawn.front.z);
		FormatLogMessage("Player Up Vector Is %f %f %f", ShipSpawn.up.x, ShipSpawn.up.y, ShipSpawn.up.z);
		FormatLogMessage("Player Right Vector Is %f %f %f", ShipSpawn.right.x, ShipSpawn.right.y, ShipSpawn.right.z);
		FormatLogMessage("Player Velocity Vector Is %f %f %f", ShipVelocity.x, ShipVelocity.y, ShipVelocity.z);
		FormatLogMessage("New Front Vector Is %f %f %f", NewMatrix.front.x, NewMatrix.front.y, NewMatrix.front.z);
		FormatLogMessage("New Up Vector Is %f %f %f", NewMatrix.up.x, NewMatrix.up.y, NewMatrix.up.z);
		FormatLogMessage("New Right Vector Is %f %f %f", NewMatrix.right.x, NewMatrix.right.y, NewMatrix.right.z);
		FormatLogMessage("New Velocity Vector Is %f %f %f", Velocity.x, Velocity.y, Velocity.z);
	}

	// Speed Bost, override the ship's velocity.
	if(dest.ExitSpeed != 0.0f)
	{
		if(dest.ExitForwardOnly)
			Velocity = dest.ExitPoint.front;
		Velocity = Vector_Scale(Velocity, dest.ExitSpeed);
	}

	const bool Player = IsPlayer(TempH);
	// They're not moving. Kick them out a little.
	if((IsNullVector(Velocity)) || ((dest.KickAI) && (!Player)))
		Velocity = Vector_Scale(dest.ExitPoint.front, 20.0f);

	SetCurAmmo(iter->TeleporterObject, 0);

	// Release target just before teleport.
	if(Tugee)
		Deploy(TempH);

	SetPosition(TempH, NewMatrix);
	SetVelocity(TempH, Velocity);

	// Rude hacky/fix for tugs. Copy/paste of code above, note: THIS OVERWRITES NewMatrix!
	// Need to rotate the TugOffset to match it's new orientation... :-/
	if(Tugee)
	{
		const Matrix TugSpawn = GetMatrixPosition(Tugee);
		const Vector TugOffset = Vector_TransformInv(ShipSpawn, TugSpawn.posit);
		const Vector TugPosition = NewMatrix.posit;
		NewMatrix = Matrix_Multiply(TugSpawn, Teleport);
		if (!dest.ExitForwardOnly)
		{
			NewMatrix.right = Neg_Vector(NewMatrix.right);
			NewMatrix.front = Neg_Vector(NewMatrix.front);
		}
		NewMatrix.posit = TugPosition;
		NewMatrix.posit = Vector_Transform(NewMatrix, TugOffset);

		TeleportTargetList.resize(TeleportTargetList.size()+1);
		TeleportTargetClass &saoB = TeleportTargetList[TeleportTargetList.size()-1]; // No temporary being created, *much* faster
		memset(&saoB, 0, sizeof(TeleportTargetClass)); // Zero things out at start.
		saoB.TeleportTarget = Tugee;
		saoB.DestEnterRange = dest.EnterRange; // Save it.
		saoB.TeleportTargetDestination = iter->TeleporterDestination; // Save it.

		SetPosition(Tugee, NewMatrix);
		SetVelocity(Tugee, Velocity);

		Pickup(TempH, Tugee, 1);
	}

	// VSR: the player's screen flashes the portal's colour.
	if ((TempH == GetPlayerHandle()) && (iter->TeleportColorFade != 0))
	{
		SetColorFade(1.0f, 5.0f, iter->TeleportColorFade);
		StartAudio2D(iter->ActivateSound, -1.0f, 0.0f, -1.0f, false, false);
	}

	// Trigger the Effects.
	BZ1Helper::Get().RefStopAddObject() = true; // RUDE HACK!
	const int Index = int(iter - PortalList.begin());
	if (!iter->FxOnVehicle)
		SetPortalEffectEnd_Internal(Index, iter->InEffect, 0, !iter->ContinuousFx);
	else
		SetPortalEffectVeh_Internal(Index, iter->VehInEffect, 0, ShipSpawn);
	if (!dest.FxOnVehicle)
		SetPortalEffectEnd_Internal(DestIndex, dest.OutEffect, 0, !dest.ContinuousFx);
	else
		SetPortalEffectVeh_Internal(DestIndex, dest.VehOutEffect, 0, NewMatrix);
	BZ1Helper::Get().RefStopAddObject() = false; // RUDE HACK!

	// Nerf any commands, such as the "goto" the teleporter we just entered: re-aim it at the destination's goto point.
	const PostTeleportReturnCodes Post = BZ1Helper::Get().PostTeleport(iter->TeleporterDestination, TempH);
	if ((!Tugee) && (!Player) && (Post == PostTeleport_DEFAULT) && (GetCurrentCommand(TempH) == CMD_GO))
	{
		const Vector Where = GetCurrentCommandWhere(TempH);
		bool ReAim = false;
		if (GetCurrentWho(TempH) == iter->TeleporterObject)
		{
			ReAim = true;
		}
		else if (!IsNullVector(Where))
		{
			const float Dist2D = sqrtf(Squared(iter->ExitPoint.posit.z - Where.z) + Squared(iter->ExitPoint.posit.x - Where.x));
			if ((Dist2D < 0.1f) || (GetDistance(TempH, Where) < iter->EnterRange + 25.0f))
				ReAim = true;
		}
		if (ReAim)
		{
			Goto(TempH, PortalList[DestIndex].GotoPoint, 0);
			SetCommand(TempH, CMD_NONE, 0);
		}
	}

	if(Logging)
		FormatLogMessage("Teleporter on Team: %d Index: %d Aquired Target on Team: %d Handle: %08x Label: %s Distance is: %f", Team, Index, t, TempH, GetLabel(objectInfo.ObjectHandle), sqrtf(TempDistSquared));

	// VSR: portal mines are one-shot.
	if (iter->PortalMineHost != 0)
	{
		BZ1Helper::Get().DeleteAfterDelay(iter->TeleporterObject, 0.0f);
		BZ1Helper::Get().DeleteAfterDelay(PortalList[iter->DestinationIndex].TeleporterObject, 0.0f);
	}
}

// DECOMPILE: inlined into BZ1Helper::DeadObject (bz1helper.cpp 2969-2971).
void PortalHelper::DeadObject(Handle h)
{
	for (std::vector<PortalClass>::iterator iter = PortalList.begin(); iter != PortalList.end(); ++iter)
	{
		if(iter->TeleporterObject == h)
		{
			if (IsTeamAllied(GetLocalPlayerTeamNumber(), GetTeamNum(iter->TeleporterObject)))
				SetObjectiveName(iter->TeleporterObject, iter->TeleporterName);
			return;
		}
	}
}

// DECOMPILE: inlined into LuaBindings::SetPortalChannel; ancestor body.
void PortalHelper::SetPortalChannel(const Handle h, const int Channel)
{
	if(!IsAround(h))
		return;

	for (std::vector<PortalClass>::iterator iter = PortalList.begin(); iter != PortalList.end(); ++iter)
	{
		if(iter->TeleporterObject == h)
		{
			iter->Channel = Channel;
			break;
		}
	}
}

// DECOMPILE: inlined into LuaBindings::GetPortalChannel; ancestor body.
int PortalHelper::GetPortalChannel(const Handle h)
{
	if(!IsAround(h))
		return -1;

	for (std::vector<PortalClass>::iterator iter = PortalList.begin(); iter != PortalList.end(); ++iter)
	{
		if(iter->TeleporterObject == h)
			return iter->Channel;
	}
	return -1;
}

// Portal Effect Controllers. The emitter sets: FxNumber is the opening emitter, FxNumber+1 the on emitter, FxNumber+2 the closing emitter.

// DECOMPILE: inlined into LuaBindings::SetPortalEffectStart and the BZ1Helper forwarder.
void PortalHelper::SetPortalEffectStart(const Handle h, const int FxNumber, const int Type, const bool /*UnusedArg*/)
{
	if(!IsAround(h))
		return;

	for (std::vector<PortalClass>::iterator iter = PortalList.begin(); iter != PortalList.end(); ++iter)
	{
		if(iter->TeleporterObject == h)
		{
			SetPortalEffectStart_Internal(int(iter - PortalList.begin()), FxNumber, Type, true);
			return;
		}
	}
}

// DECOMPILE: inlined into LuaBindings::SetPortalEffectOn and the BZ1Helper forwarder.
void PortalHelper::SetPortalEffectOn(const Handle h, const int FxNumber, const int Type, const bool /*UnusedArg*/)
{
	if(!IsAround(h))
		return;

	for (std::vector<PortalClass>::iterator iter = PortalList.begin(); iter != PortalList.end(); ++iter)
	{
		if(iter->TeleporterObject == h)
		{
			SetPortalEffectOn_Internal(int(iter - PortalList.begin()), FxNumber, Type, true);
			return;
		}
	}
}

void PortalHelper::SetPortalEffectEnd(const Handle h, const int FxNumber, const int Type, const bool /*UnusedArg*/)
{
	if(!IsAround(h))
		return;

	for (std::vector<PortalClass>::iterator iter = PortalList.begin(); iter != PortalList.end(); ++iter)
	{
		if(iter->TeleporterObject == h)
		{
			SetPortalEffectEnd_Internal(int(iter - PortalList.begin()), FxNumber, Type, true);
			return;
		}
	}
}

// DECOMPILE: declared in the PDB, no procedure in any shipped DLL (never called); the shape of its siblings, at the portal's own matrix.
void PortalHelper::SetPortalEffectVeh(const Handle h, const int FxNumber, const int UnusedArg, const int /*UnusedArg2*/)
{
	if(!IsAround(h))
		return;

	for (std::vector<PortalClass>::iterator iter = PortalList.begin(); iter != PortalList.end(); ++iter)
	{
		if(iter->TeleporterObject == h)
		{
			SetPortalEffectVeh_Internal(int(iter - PortalList.begin()), FxNumber, UnusedArg, GetMatrixPosition(h));
			return;
		}
	}
}

void PortalHelper::SetPortalEffectStart_Internal(const int Index, const int FxNumber, const int Type, const bool /*UnusedArg*/)
{
	const bool Logging = BZ1Helper::Logging;
	PortalClass &portal = PortalList[Index];

	if (IsEmitterOn(portal.TeleporterObject, portal.TeleporterEffectSlot)) // An Effect is already running. Should we override it?
	{
		if (Type == 2)
			SetPortalEffectEnd_Internal(Index, FxNumber, 2, true);
		else if (Type == 1)
			SetPortalEffectOn_Internal(Index, FxNumber, 1, true);
		return;
	}

	if (Type == 0)
	{
		SetPortalEffectEnd_Internal(Index, FxNumber, 0, true);
		return;
	}

	if (portal.EffectHardLifeTime[FxNumber - 1] < 1)
		return;

	StartEmitter(portal.TeleporterObject, FxNumber);
	StopEmitter(portal.TeleporterObject, portal.TeleporterEffectSlot);
	portal.TeleporterEffectSlot = FxNumber;
	portal.EffectType = Type;
	portal.EffectState = PortalEffectState_Opening;
	portal.EffectNumber = FxNumber;
	portal.EffectTimer[FxNumber - 1] = portal.EffectHardLifeTime[FxNumber - 1] + 1;
	PlayPortalSoundFx(Index, 0, true);
	if (Logging)
		FormatConsoleMessage("PortalFx_Start FxNum: %d, Type: %d, EffectHard%d, LifeTime: %d, EffectMask: %d", FxNumber, Type, FxNumber, portal.EffectHardLifeTime[FxNumber - 1], GetEmitterMask(portal.TeleporterObject));
}

void PortalHelper::SetPortalEffectOn_Internal(const int Index, const int FxNumber, const int Type, const bool /*UnusedArg*/)
{
	const bool Logging = BZ1Helper::Logging;
	PortalClass &portal = PortalList[Index];

	if (IsEmitterOn(portal.TeleporterObject, portal.TeleporterEffectSlot))
		StopEmitter(portal.TeleporterObject, portal.TeleporterEffectSlot);
	StartEmitter(portal.TeleporterObject, FxNumber + 1);
	portal.TeleporterEffectSlot = FxNumber + 1;
	portal.EffectType = Type;
	portal.EffectState = PortalEffectState_Open;
	portal.EffectNumber = FxNumber;
	if (Logging)
		FormatConsoleMessage("PortalFx_On FxNum: %d, Type: %d, EffectHard%d, LifeTime: %d, EffectMask: %d", FxNumber, Type, FxNumber + 1, portal.EffectHardLifeTime[FxNumber], GetEmitterMask(portal.TeleporterObject));
}

void PortalHelper::SetPortalEffectEnd_Internal(const int Index, const int FxNumber, const int Type, const bool ReplaceEffect)
{
	const bool Logging = BZ1Helper::Logging;
	PortalClass &portal = PortalList[Index];

	if (portal.EffectHardLifeTime[FxNumber + 1] < 1)
		return;

	StartEmitter(portal.TeleporterObject, FxNumber + 2);
	if (ReplaceEffect)
	{
		StopEmitter(portal.TeleporterObject, portal.TeleporterEffectSlot);
		portal.TeleporterEffectSlot = FxNumber + 2;
		portal.EffectType = Type;
		portal.EffectState = PortalEffectState_Closing;
		portal.EffectNumber = FxNumber;
	}
	portal.EffectTimer[FxNumber + 1] = portal.EffectHardLifeTime[FxNumber + 1] + 1;
	// A one-shot portal plays its deactivate sound; a continuous one plays activate when it is only adding the closing effect.
	if (!portal.ContinuousFx)
		PlayPortalSoundFx(Index, 1, true);
	else if (!ReplaceEffect)
		PlayPortalSoundFx(Index, 0, true);
	if (Logging)
		FormatConsoleMessage("PortalFx_End FxNum: %d, Type: %d, EffectHard%d, LifeTime: %d, EffectMask: %d", FxNumber, Type, FxNumber + 2, portal.EffectHardLifeTime[FxNumber + 1], GetEmitterMask(portal.TeleporterObject));
}

// Spawns the "<EffectBaseODF><FxNumber>End" effect object at pos (used for FxOnVehicle portals). The PDB lists the parameters as (Index, Matrix, FxNumber, int); the shipped code reads them in this order.
void PortalHelper::SetPortalEffectVeh_Internal(const int Index, const int FxNumber, const int /*UnusedArg*/, const Matrix pos)
{
	PortalClass &portal = PortalList[Index];

	if ((unsigned int)strlen(portal.EffectBaseODF) < (unsigned int)(MAX_ODF_LENGTH - 7 - FxNumber))
	{
		char TempEffectODF[MAX_ODF_LENGTH] = {0};
		sprintf_s(TempEffectODF, "%s%dEnd", portal.EffectBaseODF, FxNumber);
		if (DoesODFExist(TempEffectODF))
		{
			BZ1Helper::Get().RefStopAddObject() = true; // RUDE HACK!
			Handle Effect = BuildObject(TempEffectODF, 0, pos);
			BZ1Helper::Get().RefStopAddObject() = false;

			CombineStrings(TempEffectODF, TempEffectODF, ".odf"); // Add .odf to the end.
			float TempLifeTime = 0.0f;
			if ((OpenODF2(TempEffectODF)) && (GetODFFloat(TempEffectODF, "Render", "lifeTime", &TempLifeTime, 0.0f)))
				SetLifespan(Effect, TempLifeTime);
		}
		else if (portal.EffectBaseODF[0])
		{
			FormatLogMessage("Teleport Effect '%s' does not exist. Fix ODFs!", TempEffectODF);
		}
	}
	else if (portal.EffectBaseODF[0])
	{
		FormatLogMessage("Teleport Effect ODF '%s' is too long. Fix ODFs!", portal.EffectBaseODF);
	}
}

// DECOMPILE: inlined into LuaBindings::IsPortalEffectActive and the BZ1Helper forwarder.
bool PortalHelper::IsPortalEffectActive(const Handle h)
{
	if(!IsAround(h))
		return false;

	for (std::vector<PortalClass>::iterator iter = PortalList.begin(); iter != PortalList.end(); ++iter)
	{
		if(iter->TeleporterObject == h)
			return IsEmitterOn(iter->TeleporterObject, iter->TeleporterEffectSlot);
	}
	return false;
}

// DECOMPILE: inlined into LuaBindings::GetPortalDest and the BZ1Helper forwarder.
Handle PortalHelper::GetPortalDest(const Handle h)
{
	if(!IsAround(h))
		return 0;

	for (std::vector<PortalClass>::iterator iter = PortalList.begin(); iter != PortalList.end(); ++iter)
	{
		if(iter->TeleporterObject == h)
			return IsAround(iter->TeleporterDestination) ? iter->TeleporterDestination : 0;
	}
	return 0;
}

// VSR: a script locks me onto him; the match type is skipped until ClearPortalDest.
bool PortalHelper::SetPortalDest(const Handle me, const Handle him)
{
	if ((!IsAround(me)) || (!IsAround(him)))
		return false;

	int MyIndex = -1;
	int HisIndex = -1;
	for (std::vector<PortalClass>::iterator iter = PortalList.begin(); iter != PortalList.end(); ++iter)
	{
		if (iter->TeleporterObject == me)
		{
			MyIndex = int(iter - PortalList.begin());
			break;
		}
	}
	for (std::vector<PortalClass>::iterator iter = PortalList.begin(); iter != PortalList.end(); ++iter)
	{
		if (iter->TeleporterObject == him)
		{
			HisIndex = int(iter - PortalList.begin());
			break;
		}
	}
	if ((MyIndex == -1) || (HisIndex == -1))
		return false;

	PortalList[MyIndex].TeleporterDestination = PortalList[HisIndex].TeleporterObject;
	PortalList[MyIndex].DestinationIndex = HisIndex;
	PortalList[MyIndex].ScriptOverrideDest = true;
	return true;
}

// DECOMPILE: inlined into LuaBindings::ClearPortalDest and the BZ1Helper forwarder. Clears the channel's destinations and sets the script-override flag as asked.
void PortalHelper::ClearPortalDest(const Handle h, const bool ScriptOverride)
{
	if(!IsAround(h))
		return;

	for (std::vector<PortalClass>::iterator iter = PortalList.begin(); iter != PortalList.end(); ++iter)
	{
		if(iter->TeleporterObject == h)
		{
			const int Index = int(iter - PortalList.begin());
			if (Index == -1)
				return;
			ResetPortalDestinations(PortalList[Index].Channel);
			PortalList[Index].ScriptOverrideDest = ScriptOverride;
			return;
		}
	}
}

// DECOMPILE: inlined into LuaBindings::SwapPortalIndex and the BZ1Helper forwarder. The shipped body finds both cycle portals and does nothing more (sic).
void PortalHelper::SwapPortalIndex(const Handle h1, const Handle h2)
{
	std::vector<PortalClass>::iterator iter1 = PortalList.begin();
	for (; iter1 != PortalList.end(); ++iter1)
	{
		if (iter1->TeleporterObject == h1)
			break;
	}
	if (iter1 == PortalList.end())
		return;
	if (iter1->MatchType != PortalMatchType_Cycle)
		return;
	if (int(iter1 - PortalList.begin()) < 0)
		return;
	for (std::vector<PortalClass>::iterator iter2 = PortalList.begin(); iter2 != PortalList.end(); ++iter2)
	{
		if (iter2->TeleporterObject == h2)
			return;
	}
}

// DECOMPILE: inlined into LuaBindings::ShufflePortalUp and the BZ1Helper forwarder.
void PortalHelper::ShufflePortalUp(const Handle h)
{
	for (std::vector<PortalClass>::iterator iter = PortalList.begin(); iter != PortalList.end(); ++iter)
	{
		if (iter->TeleporterObject == h)
		{
			if (iter->MatchType != PortalMatchType_Cycle)
				return;
			const int Index = int(iter - PortalList.begin());
			if (Index < 0)
				return;
			ShufflePortalUpInternal(Index);
			ResetPortalDestinations(PortalList[Index].Channel);
			return;
		}
	}
}

// DECOMPILE: inlined into LuaBindings::ShufflePortalDown and the BZ1Helper forwarder.
void PortalHelper::ShufflePortalDown(const Handle h)
{
	for (std::vector<PortalClass>::iterator iter = PortalList.begin(); iter != PortalList.end(); ++iter)
	{
		if (iter->TeleporterObject == h)
		{
			if (iter->MatchType != PortalMatchType_Cycle)
				return;
			const int Index = int(iter - PortalList.begin());
			if (Index < 0)
				return;
			ShufflePortalDownInternal(Index);
			ResetPortalDestinations(PortalList[Index].Channel);
			return;
		}
	}
}

// Swaps the cycle portal at Index with the next cycle portal on its channel (wrapping), so it moves one place down the cycle.
void PortalHelper::ShufflePortalDownInternal(const int Index)
{
	if (Index < 0)
		return;
	const int Last = int(PortalList.size()) - 1;
	if ((Last < 0) || (Last <= 0))
		return;

	const PortalClass &me = PortalList[Index];
	const int Start = (Index <= Last) ? Index : 0;
	int i = Start;
	do
	{
		const PortalClass &other = PortalList[i];
		if ((other.MatchType == PortalMatchType_Cycle) &&
			((!me.MatchTypeUsesChannels) || (me.Channel == other.Channel)) &&
			(me.TeleporterObject != other.TeleporterObject))
		{
			if (i < 0)
				return;
			PortalClass Temp = PortalList[i];
			PortalList[i] = PortalList[Index];
			PortalList[Index] = Temp;
			return;
		}
		i = (i + 1 <= Last) ? i + 1 : 0;
	} while (i != Start);
}

// Swaps the cycle portal at Index with the previous cycle portal on its channel (wrapping), so it moves one place up the cycle.
void PortalHelper::ShufflePortalUpInternal(const int Index)
{
	if (Index < 0)
		return;
	const int Count = int(PortalList.size());
	const int Last = Count - 1;
	if ((Last < 0) || (Last <= 0))
		return;

	const PortalClass &me = PortalList[Index];
	const int Start = (Index <= Last) ? Index : 0;
	int i = Start;
	do
	{
		const PortalClass &other = PortalList[i];
		if ((other.MatchType == PortalMatchType_Cycle) &&
			((!me.MatchTypeUsesChannels) || (me.Channel == other.Channel)) &&
			(me.TeleporterObject != other.TeleporterObject))
		{
			if (i < 0)
				return;
			PortalClass Temp = PortalList[i];
			PortalList[i] = PortalList[Index];
			PortalList[Index] = Temp;
			return;
		}
		i = ((i - 1 >= 0) ? i : Count) - 1;
	} while (i != Start);
}

// Drops the locked destination of every non-scripted portal on the channel (all of them when channels are not used), so the next tick re-locks.
void PortalHelper::ResetPortalDestinations(const int Channel)
{
	for (std::vector<PortalClass>::iterator iter = PortalList.begin(); iter != PortalList.end(); ++iter)
	{
		if ((!iter->ScriptOverrideDest) && ((!iter->MatchTypeUsesChannels) || (iter->Channel == Channel)))
		{
			iter->TeleporterDestination = 0;
			iter->DestinationIndex = 0;
		}
	}
}

// Orders the channel's cycle portals by MatchCycleIndex (one bubble pass), then resets their destinations.
void PortalHelper::SortCycleList(const int Channel)
{
	int LastCycleIndex = -1;
	for (std::vector<PortalClass>::iterator iter = PortalList.begin(); iter != PortalList.end(); ++iter)
	{
		int CycleIndex = LastCycleIndex;
		if ((iter->MatchType == PortalMatchType_Cycle) && ((!iter->MatchTypeUsesChannels) || (iter->Channel == Channel)))
		{
			CycleIndex = iter->MatchCycleIndex;
			if (CycleIndex < LastCycleIndex)
			{
				ShufflePortalDownInternal(int(iter - PortalList.begin()));
				CycleIndex = iter->MatchCycleIndex;
			}
		}
		LastCycleIndex = CycleIndex;
	}
	ResetPortalDestinations(Channel);
}

// Type 0 plays the activate sound on the portal; anything else the deactivate sound on its mine host (else the portal). True when a sound started.
bool PortalHelper::PlayPortalSoundFx(const int Index, const int Type, const bool /*UnusedArg*/)
{
	PortalClass &portal = PortalList[Index];
	if (Type == 0)
	{
		if (DoesFileExist(portal.ActivateSound))
		{
			portal.SoundHandle = StartAudio3D(portal.ActivateSound, portal.TeleporterObject, AUDIO_CAT_EXPLOSION, false, false);
			return true;
		}
		if (portal.ActivateSound[0])
			FormatLogMessage("ERROR: Portal SoundActivate '%s' Doesn't Exist! FIX ODFs!", portal.ActivateSound);
		return false;
	}

	if (DoesFileExist(portal.DeactivateSound))
	{
		portal.SoundHandle = StartAudio3D(portal.DeactivateSound, portal.PortalMineHost ? portal.PortalMineHost : portal.TeleporterObject, AUDIO_CAT_EXPLOSION, false, false);
		return true;
	}
	if (portal.DeactivateSound[0])
		FormatLogMessage("ERROR: Portal SoundDeactivate '%s' Doesn't Exist! FIX ODFs!", portal.DeactivateSound);
	return false;
}
