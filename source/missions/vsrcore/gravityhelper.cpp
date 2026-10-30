// PROVENANCE: ancestor reference/ancestor-bz1helper-2015/Shared/BZ1Helper.cpp @6fda4f5 (gravity code: Load 330-331, Save 574-575, trn read 1286-1298, EnvironmentalSystems 2463-2545) | decompile reference/decompiled/strategy02-ghidra12.2/src/missions/vsrcore/gravityhelper.cpp.decomp.c (Load 17-40, LoadGravityInfo 56-73, Execute 76-163; Save inlined into BZ1Helper::Save) | status: ported
#include "bz1helper.h"
#include "gravityhelper.h"
#include "bzcscriptutils.h"

GravityHelper::GravityInfo TempGravityBuffer[MAX_GRAVITY_TYPES]; // GBD: the states as they stood before a Load, for the resync report.

GravityHelper::GravityHelper()
{
	memset(&gravityInfo, 0, sizeof(gravityInfo));
}

// GBD: snapshots the states, reads them one by one (every Read's result counts), then reports the first state that changed.
bool GravityHelper::Load(bool missionSave)
{
	if (missionSave)
		return true;

	for (int i = 0; i < MAX_GRAVITY_TYPES; i++)
		TempGravityBuffer[i] = gravityInfo[i];

	bool ret = true;
	for (int i = 0; i < MAX_GRAVITY_TYPES; i++)
		ret = ret && Read(&gravityInfo[i], sizeof(GravityInfo));

	for (int i = 0; i < MAX_GRAVITY_TYPES; i++)
	{
		if (!(TempGravityBuffer[i] == gravityInfo[i]))
		{
			FormatLogMessage("GravityHelper Load Mismatch Index: %d", i);
			break;
		}
	}

	return ret;
}

bool GravityHelper::Save(bool missionSave)
{
	if (missionSave)
		return true;

	bool ret = true;
	for (int i = 0; i < MAX_GRAVITY_TYPES; i++)
		ret = ret && Write(&gravityInfo[i], sizeof(GravityInfo));

	return ret;
}

// read in gravity info from map trn.
void GravityHelper::LoadGravityInfo(const char *mapTrnFile)
{
	if (OpenODF2(mapTrnFile))
	{
		for(int i = 0; i < MAX_GRAVITY_TYPES; i++)
		{
			char DesiredValue[MAX_ODF_LENGTH] = {0};
			sprintf_s(DesiredValue, "Gravity%d", i+1);
			GetODFFloat(mapTrnFile, "Gravity", DesiredValue, &gravityInfo[i].Gravity, 12.5f);

			sprintf_s(DesiredValue, "OnPeriod%d", i+1);
			GetODFFloat(mapTrnFile, "Gravity", DesiredValue, &gravityInfo[i].OnPeriod, 0.0f);

			sprintf_s(DesiredValue, "TranPeriod%d", i+1);
			GetODFFloat(mapTrnFile, "Gravity", DesiredValue, &gravityInfo[i].TranPeriod, 0.0f);
		}
	}
}

// Run the Gravity, and etc systems. GBD: the search for the next state with an OnPeriod wraps at MAX_GRAVITY_TYPES (2015 wrapped one early).
void GravityHelper::Execute(BZ1Helper &bz1Helper)
{
	bool Logging = BZ1Helper::Logging;
	BZ1Helper::MapInfo &mapInfo = bz1Helper.RefMapInfo();

	int CurrState = mapInfo.GravityState;
	int onperiod = SecondsToTurns(gravityInfo[CurrState].OnPeriod);
	int NextState = (mapInfo.GravityState + 1) % MAX_GRAVITY_TYPES;

	if(gravityInfo[NextState].OnPeriod <= 0)
	{
		// Find our next gravity state.
		int x = NextState;
		do
		{
			if(gravityInfo[x].OnPeriod > 0)
				break;

			if (++x >= MAX_GRAVITY_TYPES)
				x = 0;
		}
		while (x != NextState);

		NextState = x;
	}

	if(onperiod <= 0) // || ((mapInfo.GravityState + 1) % MAX_GRAVITY_TYPES == 0))
	{
		// Time to switch. 
		mapInfo.GravityState = (mapInfo.GravityState + 1) % MAX_GRAVITY_TYPES;
	}
	else
	{
		int tranperiod = SecondsToTurns(gravityInfo[NextState].TranPeriod);

		if(BZ1Helper::m_TurnCounter == 1) // This is our first time run, set intial gravity here.
		{
			mapInfo.Gravity = gravityInfo[CurrState].Gravity;
			SetGravity(mapInfo.Gravity);
		}

		// Count the on period time.
		gravityInfo[CurrState].OnCounter++;

		// our on time is up, time to switch.
		if(gravityInfo[CurrState].OnCounter >= onperiod)
		{
			// If we haven't calculated our deltaGravity, do it now.
			if(!gravityInfo[NextState].Gravitation)
			{
				if(tranperiod > 0)
					gravityInfo[NextState].Gravitation = ((gravityInfo[NextState].Gravity - mapInfo.Gravity) / tranperiod);
				else
					gravityInfo[NextState].Gravitation = (gravityInfo[NextState].Gravity - mapInfo.Gravity);

				if(Logging)
					FormatLogMessage("Gravity: %d NextGravity: %d, CurGravity: %f, NextGravity: %f, Gravitation is: %f, TranPeriod is: %f", CurrState, NextState, mapInfo.Gravity, gravityInfo[NextState].Gravity, gravityInfo[NextState].Gravitation, gravityInfo[NextState].TranPeriod);
			}

			// If our gravity is not == to it yet, do it.
			if(fabsf(mapInfo.Gravity - gravityInfo[NextState].Gravity) > 0.001f)
			{
				mapInfo.Gravity += gravityInfo[NextState].Gravitation;
				SetGravity(mapInfo.Gravity);
			}
			else
			{
				// Reset these.
				gravityInfo[CurrState].OnCounter = 0;
				gravityInfo[CurrState].Gravitation = 0;
				// Time to switch. 
				mapInfo.GravityState = (mapInfo.GravityState + 1) % MAX_GRAVITY_TYPES;

				if(Logging)
					FormatLogMessage("Gravity State over, next Gravity State: %d", mapInfo.GravityState);
			}
		}
	}
}
