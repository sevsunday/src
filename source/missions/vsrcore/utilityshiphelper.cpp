// PROVENANCE: ancestor reference/ancestor-bz1helper-2015/Shared/UtilityShipHelper.cpp @6fda4f5 | decompile reference/decompiled/strategy02-ghidra12.2/src/missions/vsrcore/utilityshiphelper.cpp.decomp.c (PostLoad 43-66, AddUtilityShipObject 84-200, Execute 203-270, GetEscortTarget 273-299, FindServiceTruck 302-366) + dumpbin of 4fc150a7 / 4fc15490 / 4fc156ca / 4fc1579e for the register-passed arguments and local defaults | status: ported
#include "bz1helper.h"
#include "utilityshiphelper.h"
#include "bzcscriptutils.h"
#include <algorithm>

std::vector<UtilityShipHelper::UtilityShipClass> TempUtilityShipBuffer; // GBD: the list as it stood before a Load, for PostLoad's resync report.

UtilityShipHelper *UtilityShipHelper::m_UtilityShipHelper;

UtilityShipHelper::UtilityShipHelper()
{
	m_UtilityShipHelper = this;
}

UtilityShipHelper::~UtilityShipHelper()
{
	 m_UtilityShipHelper = NULL;
}

bool UtilityShipHelper::Load(bool missionSave)
{
	if(!missionSave)
	{
		TempUtilityShipBuffer = UtilityShipList;

		int size = 0;
		bool ret = Read(&size, 1);
		UtilityShipList.resize(size);
		if(size)
			ret = ret && Read(&UtilityShipList.front(), sizeof(UtilityShipClass)*size);
		return ret;
	}
	return true;
}

bool UtilityShipHelper::PostLoad(bool missionSave)
{
	if (!missionSave)
	{
		for (std::vector<UtilityShipClass>::iterator iter = UtilityShipList.begin(); iter != UtilityShipList.end(); ++iter)
		{
			UtilityShipClass &sao = *iter;
			ConvertHandles(&sao.UtilityShipObject, 1);
		}

		if (TempUtilityShipBuffer.size() == UtilityShipList.size())
		{
			for (int i = 0; i < int(UtilityShipList.size()); ++i)
			{
				if (!(TempUtilityShipBuffer[i] == UtilityShipList[i]))
				{
					FormatLogMessage("UtilityShipList Index Mismatch: %d", i);
					return true;
				}
			}
		}
		else
		{
			FormatLogMessage("UtilityShipList Size Mismatch! Old: %d New: %d", TempUtilityShipBuffer.size(), UtilityShipList.size());
		}
	}
	return true;
}

bool UtilityShipHelper::Save(bool missionSave)
{
	if (!missionSave)
	{
		int size = int(UtilityShipList.size());
		bool ret = Write(&size, 1);
		if(size)
			ret = ret && Write(&UtilityShipList.front(), sizeof(UtilityShipClass)*size);
		return ret;
	}
	return true;
}

void UtilityShipHelper::AddUtilityShipObject(const Handle h, const int Team, const Vector Position, const int ObjClassHash, const int BZCClassHash, const char *TempODF1, const char *TempODF2, const int TempEscortPriority)
{
	for (std::vector<UtilityShipClass>::iterator iter = UtilityShipList.begin(); iter != UtilityShipList.end(); ++iter)
	{
		if(iter->UtilityShipObject == h)
			return;
	}

	UtilityShipList.resize(UtilityShipList.size()+1);
	UtilityShipClass &sao = UtilityShipList[UtilityShipList.size()-1]; // No temporary being created, *much* faster
	memset(&sao, 0, sizeof(UtilityShipClass)); // Zero things out at start.

	sao.UtilityShipObject = h;
	sao.CurTeamNum = Team;
	sao.ObjClassHash = ObjClassHash;
	sao.Position = Position;

	GetODFBool(TempODF1, TempODF2, "CraftClass", "DoDLLDispatch", &sao.DoDLLDispatch, true);

	// GBD: per-class ODF flags. Scavengers: which drop buildings; service trucks: who they serve.
	bool doDropRecycler = true;
	bool doDropExtractor = true;
	bool doDropSilo = true;
	bool ServiceSTs = false;
	bool serviceCraft = true;
	bool serviceBuildings = true;
	bool servicePilots = false;
	bool serviceOther = false;

	switch (ObjClassHash)
	{
	case CLASS_SCAVENGER:
		{
			if (GetODFBool(TempODF1, TempODF2, "ScavengerClass", "doDrop", &sao.DoDrop, false))
			{
				GetODFBool(TempODF1, TempODF2, "ScavengerClass", "doDropRecycler", &doDropRecycler, true);
				GetODFBool(TempODF1, TempODF2, "ScavengerClass", "doDropExtractor", &doDropExtractor, true);
				GetODFBool(TempODF1, TempODF2, "ScavengerClass", "doDropSilo", &doDropSilo, true);
			}
		}
		break;
	case CLASS_SCAVENGERH:
		{
			if (GetODFBool(TempODF1, TempODF2, "ScavengerHClass", "doDrop", &sao.DoDrop, false))
			{
				GetODFBool(TempODF1, TempODF2, "ScavengerHClass", "doDropRecycler", &doDropRecycler, true);
				GetODFBool(TempODF1, TempODF2, "ScavengerHClass", "doDropExtractor", &doDropExtractor, true);
				GetODFBool(TempODF1, TempODF2, "ScavengerHClass", "doDropSilo", &doDropSilo, true);
			}
		}
		break;
	case CLASS_SERVICE:
		{
			GetODFBool(TempODF1, TempODF2, "ServiceTruck", "ServiceAllies", &sao.ServiceAllies, false);
			GetODFBool(TempODF1, TempODF2, "ServiceTruck", "ServiceSTs", &ServiceSTs, false);
			GetODFBool(TempODF1, TempODF2, "ServiceTruck", "serviceCraft", &serviceCraft, true);
			GetODFBool(TempODF1, TempODF2, "ServiceTruck", "serviceBuildings", &serviceBuildings, true);
			GetODFBool(TempODF1, TempODF2, "ServiceTruck", "servicePilots", &servicePilots, false);
			GetODFBool(TempODF1, TempODF2, "ServiceTruck", "serviceOther", &serviceOther, false);
		}
		break;
	case CLASS_SERVICEH:
		{
			GetODFBool(TempODF1, TempODF2, "ServiceTruckH", "ServiceAllies", &sao.ServiceAllies, false);
			GetODFBool(TempODF1, TempODF2, "ServiceTruckH", "ServiceSTs", &ServiceSTs, false);
			GetODFBool(TempODF1, TempODF2, "ServiceTruckH", "serviceCraft", &serviceCraft, true);
			GetODFBool(TempODF1, TempODF2, "ServiceTruckH", "serviceBuildings", &serviceBuildings, true);
			GetODFBool(TempODF1, TempODF2, "ServiceTruckH", "servicePilots", &servicePilots, false);
			GetODFBool(TempODF1, TempODF2, "ServiceTruckH", "serviceOther", &serviceOther, false);
		}
		break;
	}

	if (doDropRecycler)
		sao.DropClassMask |= 1;
	if (doDropExtractor)
		sao.DropClassMask |= 2;
	if (doDropSilo)
		sao.DropClassMask |= 4;

	// GBD (sic): the enum values are already bit masks, but this shifts by them (ST -> 2, Craft -> 4, Building -> 0x10, Person -> 0x100, Other -> 0x10000)
	// while FindServiceTruck tests the plain enum values. Kept as shipped for parity; see utilityshiphelper notes in STATUS.md.
	sao.ServiceTypes = 0;
	if (ServiceSTs)
		sao.ServiceTypes |= (1 << ServiceType_ST);
	if (serviceCraft)
		sao.ServiceTypes |= (1 << ServiceType_Craft);
	if (serviceBuildings)
		sao.ServiceTypes |= (1 << ServiceType_Building);
	if (servicePilots)
		sao.ServiceTypes |= (1 << ServiceType_Person);
	if (serviceOther)
		sao.ServiceTypes |= (1 << ServiceType_Other);

	if(TempEscortPriority)
	{
		sao.EscortPriority = TempEscortPriority;
	}
	else
	{
		if(IsProducer(h))
			sao.EscortPriority = 3; // High
		else if((ObjClassHash == CLASS_SCAVENGERH) || (ObjClassHash == CLASS_SCAVENGER))
			sao.EscortPriority = 2; // Medium
		else if((ObjClassHash == CLASS_MINELAYER) || (ObjClassHash == CLASS_TUG) || (BZCClassHash == BZCCLASS_APC) || (ObjClassHash == CLASS_APC) || (ObjClassHash == CLASS_SERVICEH) || (ObjClassHash == CLASS_SERVICE))
			sao.EscortPriority = 1; // Low
		else
			sao.EscortPriority = 0; // None
	}
}

void UtilityShipHelper::Execute(BZ1Helper &bz1Helper)
{
	// pre-clean the vector
	UtilityShipList.erase(std::remove_if(UtilityShipList.begin(), UtilityShipList.end(), ShouldRemoveUtilityShip), UtilityShipList.end());

	// Loop over all lists, doing stuff.
	for (std::vector<UtilityShipClass>::iterator iter = UtilityShipList.begin(); iter != UtilityShipList.end(); ++iter)
	{
		const Handle h = iter->UtilityShipObject;
		iter->CurTeamNum = GetTeamNum(h);

		if((iter->ObjClassHash == CLASS_SCAVENGERH) || (iter->ObjClassHash == CLASS_SCAVENGER))
		{
			const int TempScrap = GetScavengerCurScrap(h);

			// GBD: a dropping scavenger shows its hold on the ammo gauge, and says user3Msg once when it is full with nowhere to drop.
			if (iter->DoDrop)
			{
				const int MaxScrap = GetScavengerMaxScrap(h);
				if (MaxScrap && GetMaxAmmo(h) == MaxScrap)
					SetAmmo(h, float(TempScrap) / float(MaxScrap));

				if (GetCurrentCommand(h) == CMD_SCAVENGE && MaxScrap == TempScrap)
				{
					bool CanDrop = false;
					const BZ1Helper::TeamInfo &cmdrInfo = bz1Helper.GetTeamInfo(GetCommanderTeam(iter->CurTeamNum));
					if (((iter->DropClassMask & 1) && cmdrInfo.DropoffRecylcers > 0) ||
						((iter->DropClassMask & 2) && cmdrInfo.DropoffExtractors > 0) ||
						((iter->DropClassMask & 4) && cmdrInfo.DropoffSilos > 0))
						CanDrop = true;

					BZ1Helper::TeamInfo &teamInfo = bz1Helper.RefTeamInfo(iter->CurTeamNum);
					if (!teamInfo.PlayedScrapDropVO)
					{
						if (!CanDrop)
						{
							PlayVOMsg(h, "user3Msg", iter->CurTeamNum);
							teamInfo.PlayedScrapDropVO = true;
						}
					}
					else if (CanDrop)
					{
						teamInfo.PlayedScrapDropVO = false;
					}
				}
			}

			// If this is a Scavenger, perform Scrap Multiplication here. Only if MP is enabled!
			if(IsNetworkOn())
			{
				if(TempScrap < iter->ScrapAmount)
				{
					int GivenScrap = (iter->ScrapAmount - TempScrap) * bz1Helper.RefScrapMult();
					AddScrap(GetCommanderTeam(iter->CurTeamNum), GivenScrap);
				}
				iter->ScrapAmount = TempScrap;
			}
		}
	}
}

Handle UtilityShipHelper::GetEscortTarget(const int Team, const int TeamFilter)
{
	const int NewTeamFilter = TeamFilter ? TeamFilter : -1; // folded: every shipped call site passes 3, so LTCG baked that in; the ancestor's fallback is kept.

	float TotalPriorities = 0.0f;

	for (std::vector<UtilityShipClass>::iterator iter = UtilityShipList.begin(); iter != UtilityShipList.end(); ++iter)
	{
		if((Team < 0) || (TeamFilterCheck(NewTeamFilter, iter->CurTeamNum, Team))) // Team Filter matches.
			TotalPriorities += iter->EscortPriority;
	}

	float Random = GetRandomFloat(0.0f, TotalPriorities);

	for (std::vector<UtilityShipClass>::iterator iter = UtilityShipList.begin(); iter != UtilityShipList.end(); ++iter)
	{
		if((Team < 0) || (TeamFilterCheck(NewTeamFilter, iter->CurTeamNum, Team))) // Team Filter matches.
		{
			Random = (Random - float(iter->EscortPriority));
			if((Random <= 0) || (iter == UtilityShipList.end()))
			{
				//FormatLogMessage("Random is: %f, Index is: %d Priority is: %d", Random, iter-UtilityShipList.begin(), iter->EscortPriority);
				return iter->UtilityShipObject;
			}
		}
	}
	return 0; // This should be impossible, but if all else fails, just return nothing.
}

Handle UtilityShipHelper::FindServiceTruck(const Handle me, const int Team, const bool IgnoreBusy, const float MaxRange, const int /*_Parg*/)
{
	const int NewTeam = (Team == -1) ? GetTeamNum(me) : Team;
	Handle Best = 0;
	const Vector MyPos = GetPosition(me);
	float BestDist = (MaxRange > 0.0f) ? MaxRange * MaxRange : FLT_MAX;

	for (std::vector<UtilityShipClass>::iterator iter = UtilityShipList.begin(); iter != UtilityShipList.end(); ++iter)
	{
		if (!IsServiceTruck(iter->UtilityShipObject))
			continue;
		if (!IsTeamAllied(NewTeam, iter->CurTeamNum))
			continue;
		if (!iter->ServiceAllies && NewTeam != Team) // as shipped: a truck that only serves its own team qualifies only when the caller named the team.
			continue;
		if (!IgnoreBusy && !IsIdle(iter->UtilityShipObject))
			continue;
		if (!iter->DoDLLDispatch)
			continue;

		bool Serves;
		if (IsServiceTruck(me))
			Serves = (iter->ServiceTypes & ServiceType_ST) != 0;
		else if (IsCraftButNotPerson(me))
			Serves = (iter->ServiceTypes & ServiceType_Craft) != 0;
		else if (IsBuilding(me))
			Serves = (iter->ServiceTypes & ServiceType_Building) != 0;
		else if (IsPerson(me))
			Serves = (iter->ServiceTypes & ServiceType_Person) != 0;
		else
			Serves = (iter->ServiceTypes & ServiceType_Other) != 0;
		if (!Serves)
			continue;

		const float Dist = GetDistance3DSquared(iter->Position, MyPos);
		if (Dist < BestDist)
		{
			Best = iter->UtilityShipObject;
			BestDist = Dist;
		}
	}
	return Best;
}
