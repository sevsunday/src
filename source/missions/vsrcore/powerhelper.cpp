// PROVENANCE: ancestor reference/ancestor-bz1helper-2015/Shared/PowerHelper.cpp @6fda4f5 | decompile reference/decompiled/strategy02-ghidra12.2/src/missions/vsrcore/powerhelper.cpp.decomp.c (PostLoad 42-65, AddPowerObject 83-115, Execute 132-165; Load / Save inlined into BZ1Helper::Load / Save) | status: ported
#include "bz1helper.h"
#include "powerhelper.h"
#include "buildinghelper.h"
#include "bzcscriptutils.h"

PowerHelper *PowerHelper::m_PowerHelper;
std::vector<PowerHelper::PowerClass> TempPowerBuffer; // GBD: the list as it stood before a Load, for PostLoad's resync report.

PowerHelper::PowerHelper()
{
	m_PowerHelper = this;
}
PowerHelper::~PowerHelper()
{
	m_PowerHelper = NULL;
}

bool PowerHelper::Load(bool missionSave)
{
	if (!missionSave)
	{
		TempPowerBuffer = PowerList;

		int size = 0;
		bool ret = Read(&size, 1);
		PowerList.resize(size);
		if(size)
			ret = ret && Read(&PowerList.front(), sizeof(PowerClass)*size);
		return ret;
	}
	return true;
}

bool PowerHelper::PostLoad(bool missionSave)
{
	if (!missionSave)
	{
		for (std::vector<PowerClass>::iterator iter = PowerList.begin(); iter != PowerList.end(); ++iter)
		{
			PowerClass &sao = *iter;
			ConvertHandles(&sao.PowerObject, 1);
		}

		if (TempPowerBuffer.size() == PowerList.size())
		{
			for (int i = 0; i < int(PowerList.size()); ++i)
			{
				if (!(TempPowerBuffer[i] == PowerList[i]))
				{
					FormatLogMessage("PowerList Index Mismatch: %d", i);
					return true;
				}
			}
		}
		else
		{
			FormatLogMessage("PowerList Size Mismatch! Old: %d New: %d", TempPowerBuffer.size(), PowerList.size());
		}
	}
	return true;
}

bool PowerHelper::Save(bool missionSave)
{
	if (!missionSave)
	{
		int size = int(PowerList.size());
		bool ret = Write(&size, 1);
		if(size)
			ret = ret && Write(&PowerList.front(), sizeof(PowerClass)*size);
		return ret;
	}
	return true;
}

// GBD: a handle already in the list has its entry re-initialized in place (2015 returned without touching it).
void PowerHelper::AddPowerObject(const Handle h, const char* TempODF1, const char* TempODF2)
{
	int Index = -1;
	for (std::vector<PowerClass>::iterator iter = PowerList.begin(); iter != PowerList.end(); ++iter)
	{
		if(iter->PowerObject == h)
		{
			Index = int(iter - PowerList.begin());
			break;
		}
	}

	if (Index < 0)
	{
		PowerList.resize(PowerList.size()+1);
		Index = int(PowerList.size()) - 1;
	}
	PowerClass &sao = PowerList[Index]; // No temporary being created, *much* faster
	memset(&sao, 0, sizeof(PowerClass)); // Zero things out at start.

	GetODFBool(TempODF1, TempODF2, "BuildingClass", "DoBettyLost", &sao.DoBettyLost, true);

	if((GetODFFloat(TempODF1, TempODF2, "PowerPlantClass", "powerRadius", &sao.PowerRange, ScaleDistance(100.0f))) || 
		(GetODFFloat(TempODF1, TempODF2, "PowerPlantClass", "powerRange", &sao.PowerRange, ScaleDistance(100.0f))))
	{
		// Got it.
	}

	GetODFInt(TempODF1, TempODF2, "PowerPlantClass", "PowerClassMask", &sao.PowerMask, 0);
	GetODFInt(TempODF1, TempODF2, "PowerPlantClass", "PowerClassMatch", &sao.PowerMatch, 0);
	GetODFInt(TempODF1, TempODF2, "PowerPlantClass", "PowerClassProvides", &sao.PowerProvide, 0);

	sao.PowerObject = h;
	sao.Position = GetPosition(h);
}

void PowerHelper::DeletePowerObject(const Handle h)
{
	for (std::vector<PowerClass>::iterator iter = PowerList.begin(); iter != PowerList.end(); ++iter)
	{
		if(iter->PowerObject == h)
		{
			if(IsAround(iter->PowerObject)) // Note: IsAround passes true for objects being Recycled in DeleteObject() function.
				iter->WasDemolished = true;

			return;
		}
	}
}

// GBD: the "power plant lost" voice goes through PlayEventVO (event sound 11 of the team race's event ODF).
void PowerHelper::Execute(BZ1Helper & /*bz1Helper*/)
{
	//bool Logging = BZ1Helper::Logging;

	// Sweep through the Shield Towers and remove any of them that are no longer around
	std::vector<PowerClass>::iterator validEnd = PowerList.begin();
	std::vector<PowerClass>::iterator lastValid = PowerList.begin();
	for (std::vector<PowerClass>::iterator iter = PowerList.begin(); iter != PowerList.end(); ++iter)
	{
		// If the tower is around...
		if (IsAround(iter->PowerObject))
		{
			iter->PowerTeam = GetTeamNum(iter->PowerObject);
			iter->IsPowered = BuildingHelper::Get().IsBuildingPowered(iter->PowerObject);
			iter->Position = GetPosition(iter->PowerObject);

			// Copy the valid entry into the valid portion
			if (lastValid != iter)
				*validEnd = *iter;
			++validEnd;
		}
		else
		{
			// Play the proper destruction wave file for "supplydepot" power plants. Cna't do this in DeleteObject because it runs over all objects when a Resync happens in Multiplayer. (Basically a Resync deletes and re places all objects on the map)
			if((!iter->WasDemolished) && (!iter->DoBettyLost) && (iter->PowerTeam == GetLocalPlayerTeamNumber()))
				PlayEventVO(BZ1Helper::Get().RefTeamInfo(iter->PowerTeam).TeamRace, 11, iter->PowerTeam);
		}
	}
	// Now erase any invalid entries left behind
	PowerList.erase(validEnd, PowerList.end());

}
