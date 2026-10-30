// PROVENANCE: ancestor reference/ancestor-1.3/Missions/Deathmatch01/deathmatch01.cpp @353698f (the deathmatch skeleton: spawnpoints, CTF flags, race checkpoints, rabbit, weenie, bots, animals, empty-vehicle tracking, scoring) | decompile reference/decompiled/deathmatch01-ghidra12.2/src/missions/deathmatch01/deathmatch01.cpp.decomp.c (ctor 84-100, dtor 102-104, AddObject 107-139, DeleteObject 142-146, GetCanEject 152-170, GetRespawnInVehicle 175-188, GetInitialFlagODF 193-197, GetInitialFlagStandODF 201-205, GetInitialPlayerPilotODF 210-214, GetNextVehicleODF 219-230, GetNextRandomVehicleODF 233-235, GetSpawnpointForTeam 240-338, SetupTeam 352-493, FindGoodAITarget 498-671, BuildBotCraft 675-725, SetupAnimal 729-755, ObjectifyFlag 760-783, ObjectifyRabbit 788-802, SetNewRabbit 807-886, SetupPlayer 890-971, InitialSetup 974-980, CrunchEmptyVehicleList 985-1013, UpdateEmptyVehicles 1019-1076, AddEmptyVehicle 1081-1109, Init 1113-1285, ObjectifyRacePoint 1290-1319, ExecuteRabbit 1324-1490, ExecuteRace 1494-1627, ExecuteWeenie 1630-1682, ExecuteTrackPlayers 1688-1741, UpdateGameTime 1746-1817, UpdateAIUnits 1820-1944, UpdateAnimals 1947-1999, Execute 2002-2141, AddPlayer 2144-2163, DeletePlayer 2166-2169, RespawnPilot 2173-2261, DeadObject 2264-2486, PlayerEjected 2489-2521, ObjectKilled 2524-2546, ObjectSniped 2549-2568, CreateObjectives 2571-2597, Load 2600-2666, PostLoad 2670-2706, Save 2710-2738, BuildMission 2776-2778) + dumpbin of 4fc3f88e-4fc42c40 annotated with the PDB member offsets (InitTaunts, the flag-stand BuildObject overloads, the ctor counts) | gbd-lua-port original/lua/Lua-Stock-Missions_ea4173f/Upload/VSR/Missions/Scripts/Deathmatch.lua (names, comments, cross-check) | status: ported
//
// Deathmatch01.cpp
// 
// Deathmatch DLL code for a simple multiplay game. Requires map with
// spawnpoints, optional powerups. 
//
// Converted to new DLL interface spec by Nathan Mates 2/23/99
//

#include "deathmatch01.h"
#include "pupmgr.h"
#include "taunts.h"
#include "trace.h"
#include "dllutils.h"
#include "trnallies.h"
#include "bzcscriptutils.h"

#include <math.h>
#include <string.h>
#include <stdio.h>
#include <malloc.h>

//#define DEBUG_RABBIT 
const float MAX_FLOAT    =   3.4028e+38f;


const float VEHICLE_SPACING_DISTANCE = 20.0f;

// How many seconds sniped AI craft will stick around before
// going boom.
const float SNIPED_AI_LIFESPAN = 300.0f; 

// How far away a new craft will be from the old one
const float RespawnMinRadiusAway = 10.0f;
const float RespawnMaxRadiusAway = 20.0f;

// How high up to respawn a pilot
const float RespawnPilotHeight = 200.0f;

// How far allies will be from the commander's position
const float AllyMinRadiusAway = 10.0f;
const float AllyMaxRadiusAway = 30.0f;

const float BotMinRadiusAway = 30.0f;
const float BotMaxRadiusAway = 100.0f;

// Tuning distances for GetSpawnpointForTeam(). These are the defaults;
// the map's .trn [DLL] block can override them (see Init()).

// Friendly spawnpoint: Max distance away for ally
const float FRIENDLY_SPAWNPOINT_MAX_ALLY = 100.f;
// Friendly spawnpoint: Min distance away for enemy
const float FRIENDLY_SPAWNPOINT_MIN_ENEMY = 300.f;

// Random spawnpoint: min distance away for enemy
const float RANDOM_SPAWNPOINT_MIN_ENEMY = 150.f;

const int FIRST_AI_TEAM = 11;
const int LAST_AI_TEAM = 15;

// ---------- Scoring Values-- these are delta scores, added to current score --------
const int ScoreForKillingCraft = 5;
const int ScoreForKillingPerson = 5;
const int ScoreForDyingAsCraft = -1;
const int ScoreForDyingAsPerson = -1;

// Unlike Strat/MPI, these are always on.
const bool PointsForAIKill = true;
const bool KillForAIKill = true;

// -----------------------------------------------


char TempMsgString[1024];
char StaticTempMsgStr[1024];

// Temporary name for blasting ODF names into while building
// them. *not* saved, do *not* count on its contents being valid
// next time the dll is called.
static char TempODFName[64];
static bool RaceSetObjective = false; // Done separately from regularly loaded varbs, done per-machine

// Every SetNewRabbit call site looks the new rabbit's ODF up for the
// trace line first, and skips a 0 handle.
#define SET_NEW_RABBIT(h) { char RabbitODF[64]; GetObjInfo((h), Get_CFG, RabbitODF); Trace(("SetNewRabbit(%08X...), odf %s\n", (h), RabbitODF)); if(h) SetNewRabbit(h); }

// Don't do much at class creation; do in InitialSetup()
Deathmatch01::Deathmatch01(void) 
{
	m_GameTPS = 20; // default
	EnableHighTPS(m_GameTPS);

	AllowRandomTracks(true); // If the user wants random music, we're fine with that.
	b_count = &b_last - &b_first - 1;
	b_array = &b_first + 1;

	f_array = &f_first + 1;
	f_count = &f_last - &f_first - 1;

	h_array = &h_first + 1;
	h_count = &h_last - &h_first - 1;

	i_count = &i_last - &i_first - 1;
	i_array = &i_first + 1;
}

Deathmatch01::~Deathmatch01()
{
	CleanupTaunts();
}

void Deathmatch01::AddObject(Handle h)
{
	if(!StopScript)
		LuaMission::AddObject(h);

	// Changed NM 11/22/01 - all AI is at skill 3 now by default.
	if(!IsPlayer(h)) 
	{
		// Always get a random # to keep things in sync
		int UseSkill = (int)GetRandomFloat(4);
		if(UseSkill == 4)
			UseSkill = 3;

		if(m_AIUnitSkill<4)
			UseSkill = m_AIUnitSkill;

		SetSkill(h, UseSkill);
	}
}

void Deathmatch01::DeleteObject(Handle h)
{
	if(!StopScript)
		LuaMission::DeleteObject(h);
}

// Returns true if players can eject (or bail out) of their vehicles
// depending on the game type, false if they should be killed when
// they try and do so.
bool Deathmatch01::GetCanEject(Handle h)
{
	if(m_ShipOnlyMode)
		return false;

	// Can't eject if the rabbit
	if((m_RabbitMode) && (h == m_RabbitTargetHandle))
		return false;

	switch (m_MissionType)
	{
	case DMSubtype_Normal:
	case DMSubtype_KOH:
	case DMSubtype_Loot:
		return true;

	default:
		return false;
	}
}

// Returns true if players shouldn't be respawned as a pilot, but in
// a piloted vehicle instead, i.e. during race mode
bool Deathmatch01::GetRespawnInVehicle(void)
{
	if(m_ShipOnlyMode)
		return true;

	switch (m_MissionType)
	{
	case DMSubtype_Race2:
	case DMSubtype_Normal2:
		return true;

	default:
		return false;
	}
}


// Given a race identifier, get the flag odf back
const char *Deathmatch01::GetInitialFlagODF(char Race)
{
	strcpy_s(TempODFName, "ioflag01");
	TempODFName[0] = Race;
	return TempODFName;
}

// Given a race identifier, get the flag stand odf back
const char *Deathmatch01::GetInitialFlagStandODF(char Race)
{
	strcpy_s(TempODFName, "iostand01");
	TempODFName[0] = Race;
	return TempODFName;
}


// Given a race identifier, get the pilot odf back
const char *Deathmatch01::GetInitialPlayerPilotODF(char Race)
{
	strcpy_s(TempODFName, "isuser");
	TempODFName[0] = Race;
	return TempODFName;
}


// Gets the next vehicle ODF for the player on a given team.
const char *Deathmatch01::GetNextVehicleODF(int TeamNum, bool Randomize)
{
	RandomizeType RType = Randomize_None; // Default
	if(Randomize)
	{
		if(m_RespawnType == 1)
			RType = Randomize_ByRace;
		else if(m_RespawnType == 2)
			RType = Randomize_Any;
	}

	return GetPlayerODF(TeamNum, RType);
}

const char *Deathmatch01::GetNextRandomVehicleODF(int Team)
{
	return GetPlayerODF(Team);
}


// Helper function for SetupTeam(), returns an appropriate spawnpoint.
Vector Deathmatch01::GetSpawnpointForTeam(int Team)
{
	Vector spawnpointPosition;
	spawnpointPosition.x = spawnpointPosition.y = spawnpointPosition.z = 0.f;

	// Pick a random, ideally safe spawnpoint.
	SpawnpointInfo* pSpawnPointInfo;
	size_t i,count = GetAllSpawnpoints(pSpawnPointInfo, Team);

	// Designer didn't seem to put any spawnpoints on the map :(
	if(count == 0)
	{
		return spawnpointPosition;
	}

	// First pass: see if a spawnpoint exists with this team #
	//
	// Note: using a temporary array allocated on stack to keep track
	// of indices.
	size_t* pIndices = reinterpret_cast<size_t*>(_alloca(count * sizeof(size_t)));
	memset(pIndices, 0, count * sizeof(size_t));
	size_t indexCount = 0;
	for(i=0; i<count; ++i)
	{
		if(pSpawnPointInfo[i].m_Team == Team)
		{
			pIndices[indexCount++] = i;
		}
	}

	// Did we find any spawnpoints in the above search? If so,
	// randomize out of that list and return that
	if(indexCount > 0)
	{
		size_t index = 0;
		// Might be unnecessary, but make sure we return a valid index
		// in [0,indexCount)
		do
		{
			index = static_cast<size_t>(GetRandomFloat(static_cast<float>(indexCount)));
		} while(index >= indexCount);
		return pSpawnPointInfo[pIndices[index]].m_Position;
	}

	// Second pass: build up a list of spawnpoints that appear to have
	// allies close, randomly pick one of those.
	indexCount = 0;
	for(i=0; i<count; ++i)
	{
		if(((pSpawnPointInfo[i].m_DistanceToClosestSameTeam < m_FRIENDLY_SPAWNPOINT_MAX_ALLY) ||
			(pSpawnPointInfo[i].m_DistanceToClosestAlly < m_FRIENDLY_SPAWNPOINT_MAX_ALLY)) &&
		   (pSpawnPointInfo[i].m_DistanceToClosestEnemy >= m_FRIENDLY_SPAWNPOINT_MIN_ENEMY))
		{
			pIndices[indexCount++] = i;
		}
	}

	// Did we find any spawnpoints in the above search? If so,
	// randomize out of that list and return that
	if(indexCount > 0)
	{
		size_t index = 0;
		// Might be unnecessary, but make sure we return a valid index
		// in [0,indexCount)
		do
		{
			index = static_cast<size_t>(GetRandomFloat(static_cast<float>(indexCount)));
		} while(index >= indexCount);
		return pSpawnPointInfo[pIndices[index]].m_Position;
	}

	// Third pass: Make up a list of spawnpoints that appear to have
	// no enemies close.
	indexCount = 0;
	for(i=0; i<count; ++i)
	{
		if(pSpawnPointInfo[i].m_DistanceToClosestEnemy >= m_RANDOM_SPAWNPOINT_MIN_ENEMY)
		{
			pIndices[indexCount++] = i;
		}
	}

	// Did we find any spawnpoints in the above search? If so,
	// randomize out of that list and return that
	if(indexCount > 0)
	{
		size_t index = 0;
		// Might be unnecessary, but make sure we return a valid index
		// in [0,indexCount)
		do
		{
			index = static_cast<size_t>(GetRandomFloat(static_cast<float>(indexCount)));
		} while(index >= indexCount);
		return pSpawnPointInfo[pIndices[index]].m_Position;
	}

	// If here, all spawnpoints have an enemy within
	// RANDOM_SPAWNPOINT_MIN_ENEMY.  Fallback to old code.
	return GetRandomSpawnpoint(Team);
}


// Sets up the side's commander's extra vehicles, such a recycler or
// more. Does *not* create the player vehicle for them, 
// however. [That's to be done in SetupPlayer.] Safe to be called
// multiple times for each player on that team. 
//
// If Teamplay is off, this function is called once per player.
//
// If Teamplay is on, this function is called only on the
// _defensive_ team number for an alliance. 

void Deathmatch01::SetupTeam(int Team)
{
	// Sanity checks: don't do anything that looks invalid
	if((Team < 0) || (Team >= MAX_TEAMS))
		return;
	// Also, if we've already set up this team group, don't do anything
	if((IsTeamplayOn()) && (m_TeamIsSetUp[Team]))
		return;

	char TeamRace = GetRaceOfTeam(Team);

	if(IsTeamplayOn())
	{
		SetMPTeamRace(WhichTeamGroup(Team), TeamRace); // Lock this down to prevent changes.
	}

	Vector Where;

	if(DMIsRaceSubtype[m_MissionType])
	{
		// Race-- everyone starts off at spawnpoint 0's position
		Where = GetSpawnpoint(0);
	}
	else
	{
		Where = GetSpawnpointForTeam(Team);

		// And randomize around the spawnpoint slightly so we'll
		// hopefully never spawn in two pilots in the same place
		Where = GetPositionNear(Where, AllyMinRadiusAway, AllyMaxRadiusAway);
	}

	// Store position we created them at for later
	m_TeamPos[3*Team+0] = Where.x;
	m_TeamPos[3*Team+1] = Where.y;
	m_TeamPos[3*Team+2] = Where.z;

	// Find location to place flag at
	if (m_MissionType == DMSubtype_CTF)
	{
		// CTF
		// Find place to drop flag from AIPaths list
		char DesiredName[64];
		sprintf_s(DesiredName, "base%d", Team);
		char StandName[64];
		sprintf_s(StandName, "m_base%d", Team);

		int i, pathCount;
		char **pathNames;
		GetAiPaths(pathCount, pathNames);
		for (i = 0; i<pathCount; ++i)
		{
			char *label = pathNames[i];
			if(strcmp(label, DesiredName) == 0)
			{
				// The flag stand: a pre-placed one named m_base#, else build one on the path. -GBD
				Handle StandH = GetHandle(StandName);
				if(!StandH)
					StandH = BuildObject(GetInitialFlagStandODF(TeamRace), Team, label);
				SetAnimation(StandH, "loop", 0);

				// The flag sits on the stand.
				Handle FlagH;
				if(StandH)
					FlagH = BuildObject(GetInitialFlagODF(TeamRace), Team, StandH);
				else
					FlagH = BuildObject(GetInitialFlagODF(TeamRace), Team, label);
				SetAnimation(FlagH, "loop", 0);

				if(Team == 1)
				{
					m_Base1 = StandH;
					m_Flag1 = FlagH;
				}
				else if(Team == 6)
				{
					m_Base2 = StandH;
					m_Flag2 = FlagH;
				}
			}
		}
	} // CTF Flag setup

	else if ((DMIsRaceSubtype[m_MissionType]) && (!m_RaceIsSetup)) 
	{
		int intCheckpointCount = 0;
		Handle hdlCheckpoint = 0;
		do {
			intCheckpointCount++;
			sprintf_s(TempODFName, "checkpoint%d", intCheckpointCount);
			hdlCheckpoint = GetHandle(TempODFName);
		} while(hdlCheckpoint);
		m_TotalCheckpoints = intCheckpointCount-1;

		m_RaceIsSetup = true;
	}

	if(IsTeamplayOn()) 
	{
		for(int i = GetFirstAlliedTeam(Team);i<= GetLastAlliedTeam(Team);i++) 
		{
			if(i!= Team)
			{
				// Get a new position near the team's central position
				Vector NewPosition = GetPositionNear(Where, AllyMinRadiusAway, AllyMaxRadiusAway);

				// In teamplay, store where offense players were created for respawns later
				m_TeamPos[3*i+0] = NewPosition.x;
				m_TeamPos[3*i+1] = NewPosition.y;
				m_TeamPos[3*i+2] = NewPosition.z;
			} // Loop over allies not the commander
		}
	}

	m_TeamIsSetUp[Team] = true;
}

// Tries to return a good target for the AI unit, orders them to go
// after it.
void Deathmatch01::FindGoodAITarget(const int index)
{
	// Sanity check - if this AI craft went MIA, clear handle
	if(!IsAliveAndPilot2(m_AICraftHandles[index]))
	{
		m_AICraftHandles[index] = 0;
		return;
	}

	// Rabbit mode? Hammer the "it" player, nothing else to do
	if((m_RabbitMode) && (m_AICraftHandles[index] != m_RabbitTargetHandle))
	{
		Handle TargetH = m_RabbitTargetHandle;
		if(IsAlive(TargetH))
			Attack(m_AICraftHandles[index], m_RabbitTargetHandle);
		return;
	}

	Handle nearestEnemy = GetNearestEnemy(m_AICraftHandles[index]);
	int i;
	for(i = 1;i<MAX_TEAMS;i++)
	{
		Handle PlayerH = GetPlayerHandle(i);
		// Ignore any close-by pilots.
		if((nearestEnemy == PlayerH) && (IsAliveAndPilot(PlayerH)))
			nearestEnemy = 0;
	}

	// Was our last action an attack? Consider powerups now.
	if(nearestEnemy && (!m_AILastWentForPowerup[index]))
	{
		Handle nearestPerson = GetNearestPerson(m_AICraftHandles[index], true, 100.0f);

		float distToEnemy = GetDistance(m_AICraftHandles[index], nearestEnemy);

		if(nearestPerson)
		{
			float distToPerson = GetDistance(m_AICraftHandles[index], nearestPerson);

			// Consider objects a bit farther away than closest enemy
			if(distToPerson < (distToEnemy * 1.2f))
			{
				Goto(m_AICraftHandles[index], nearestPerson);
				m_AILastWentForPowerup[index] = true;
				m_PowerupGotoTime[index] = 0;
				m_AITargetHandles[index] = nearestPerson;
				return; // exit...
			} // Powerup is close
		} // nearestPerson exists

		Handle nearestPowerup = GetNearestPowerup(m_AICraftHandles[index], true, 100.0f);
		if(nearestPowerup)
		{
			float distToPowerup = GetDistance(m_AICraftHandles[index], nearestPowerup);

			// Consider objects a bit farther away than closest enemy
			if(distToPowerup < (distToEnemy * 1.2f))
			{
				Goto(m_AICraftHandles[index], nearestPowerup);
				m_AILastWentForPowerup[index] = true;
				m_PowerupGotoTime[index] = 0;
				m_AITargetHandles[index] = nearestPowerup;
				return; // exit...
			} // Powerup is close
		} // nearestPerson exists
	}

	if(nearestEnemy)
	{
		// Nothing to do here-- Got the target
	}
	else
	{
		// Nearest enemy scan failed (found pilot, too far, 
		// something). Try harder.
		float BestDist = 1e10f;
		Handle BestHandle = 0;
		if(!m_HumansVsBots)
		{
			// Scan botlist..
			for(i = 0;i<m_NumAIUnits;i++)
			{
				// Can't attack self.
				if(i == index)
					continue;
				// If don't have a craft for self, skip.
				if(!m_AICraftHandles[index])
					continue;

				Handle ThisBotH = m_AICraftHandles[i];
				// If bot died, skip them.
				if(!IsAlive(ThisBotH))
					continue;
				// Skip friendly AIs
				if(IsAlly(m_AICraftHandles[index], m_AICraftHandles[i]))
					continue;
				ThisBotH = m_AICraftHandles[i];
				Handle MyH = m_AICraftHandles[index];
				float ThisDist = GetDistance(MyH, ThisBotH);
				if((ThisDist > 0.01f) && (ThisDist < BestDist))
				{
					// Winner (of sorts). Store them.
					BestDist = ThisDist;
					BestHandle = m_AICraftHandles[i];
				}
			} // Loop over all AI units.
		} // Isn't humans vs bots, so need to consider bots.

		for(i = 1;i<MAX_TEAMS;i++)
		{
			Handle PlayerH = GetPlayerHandle(i);
			if(!PlayerH)
				continue;
			Handle PlayerH2 = PlayerH;

			// Skip human pilots in this phase (GetWhoShotMe will pick up other attacks)
			if(IsAliveAndPilot(PlayerH2))
				continue;

			Handle MyH = m_AICraftHandles[index];
			float ThisDist = GetDistance(MyH, PlayerH);
			if((ThisDist > 0.01f) && (ThisDist < BestDist))
			{
				// Winner (of sorts). Store them.
				BestDist = ThisDist;
				BestHandle = PlayerH;
			}
		}// loop over all teams.

		if(BestHandle)
		{
			nearestEnemy = BestHandle;
		}
	} // Fallback for things.

	m_AITargetHandles[index] = nearestEnemy;
	// Charge!
	if(nearestEnemy)
	{
		Attack(m_AICraftHandles[index], m_AITargetHandles[index]);
	}
	m_AILastWentForPowerup[index] = false; // In combat mode!
}

// Sets up the specified AI unit, first time or later.
void Deathmatch01::BuildBotCraft(int index)
{
	int i;

	int theirTeam;

	if(m_RabbitMode)
		theirTeam = 14; // until they become 'it', and on team 15
	else if(m_HumansVsBots)
		theirTeam = 15;
	else
	{
		// Put them on a consistent team # based on their slot, so they'll
		// respawn with the same team # later, etc.
		const int NUM_AI_TEAMS = LAST_AI_TEAM - FIRST_AI_TEAM + 1;
		theirTeam = FIRST_AI_TEAM + (index % NUM_AI_TEAMS);
	}

	// Find a valid human user, and use them to read the vehicles list.
	int APlayerTeam = 1; // Absolute fallback, if you must
	for(i = 0;i<MAX_TEAMS;i++)
	{
		if((m_TeamIsSetUp[i]) && (GetPlayerHandle(i)))
			APlayerTeam = i;
	}

	Vector Where = GetRandomSpawnpoint(theirTeam);
	// Somewhere near the spawnpoint..
	Where = GetPositionNear(Where, BotMinRadiusAway, BotMaxRadiusAway);
	// Bounce them up a little.
	Where.y += 2+GetRandomFloat(4);
	const char *NewCraftsODF = GetPlayerODF(APlayerTeam, Randomize_Any);

	m_AICraftHandles[index] = BuildObject(NewCraftsODF, theirTeam, Where);
	SetRandomHeadingAngle(m_AICraftHandles[index]);
	SetNoScrapFlagByHandle(m_AICraftHandles[index]);
	AddPilotByHandle(m_AICraftHandles[index]);

	Trace(("Spawning AI craft index %d '%s' on team %d. Handle = %08X\n", 
		index, NewCraftsODF, theirTeam, m_AICraftHandles[index]));

	// Ok, find a 'victim' for this AI unit. :)
	FindGoodAITarget(index);
} // BuildBotCraft()

// Sets up the specified Animal unit, first time or later.
void Deathmatch01::SetupAnimal(int index)
{
	int AnimalTeam = 8 + (int)GetRandomFloat(6);

	// Don't make animals allied w/ humans, go to another team
	if(m_HumansVsBots || m_RabbitMode)
		AnimalTeam = 13;

	Vector Where = GetRandomSpawnpoint();
	// Somewhere near the spawnpoint..
	Where = GetPositionNear(Where, AllyMinRadiusAway, AllyMaxRadiusAway);
	// Bounce them up in the air a little.
	Where.y += 2+GetRandomFloat(4);
	char *AnimalODF = (char*)(&m_AnimalConfig[0]);

	m_AnimalHandles[index] = BuildObject(AnimalODF, AnimalTeam, Where);
	SetRandomHeadingAngle(m_AnimalHandles[index]);
	SetNoScrapFlagByHandle(m_AnimalHandles[index]);
} // SetupAnimal()


// For CTF, objectifies the other team's flag
void Deathmatch01::ObjectifyFlag(void)
{
	const Handle PlayerH = GetPlayerHandle();
	if(PlayerH == 0)
	{
		// Shouldn't happen, but be safe in case it does
		return;
	}

	const int team = GetTeamNum(PlayerH);
	const int TeamBlock = WhichTeamGroup(team);
	if((IsTeamplayOn()) && (TeamBlock >= 0))
	{
		const Handle myFlag = (TeamBlock == 0) ? m_Flag1 : m_Flag2;
		const Handle opponentFlag = (TeamBlock == 0) ? m_Flag2 : m_Flag1;

		SetObjectiveOff(myFlag);
		SetObjectiveOn(myFlag);
		SetObjectiveName(myFlag, GetBZCCLocalizedString("cfg", "Defend Flag!"));

		SetObjectiveOff(opponentFlag);
		SetObjectiveOn(opponentFlag);
		SetObjectiveName(opponentFlag, GetBZCCLocalizedString("cfg", "Capture Flag!"));
	}
}



void Deathmatch01::ObjectifyRabbit(void)
{
	Handle PlayerH = GetPlayerHandle();
	if(PlayerH == m_RabbitTargetHandle)
	{
		ClearObjectives();
	}
	else
	{
		// Force-reset this.
		SetObjectiveOff(m_RabbitTargetHandle);
		SetObjectiveOn(m_RabbitTargetHandle);
		SetObjectiveName(m_RabbitTargetHandle, GetBZCCLocalizedString("cfg", "Wabbit!"));
	}
}


// This handle is the new rabbit. Target them!
void Deathmatch01::SetNewRabbit(const Handle h)
{
	// Ignore invalid handle.
	if(!IsAround(h))
	{
		Trace(("ERROR: don't set the rabbit to something that doesn't exist!\n"));
		return;
	}

	m_RabbitMissingTurns = 0; // always clear this

	// Remove old objectification
	SetObjectiveOff(m_RabbitTargetHandle);

	m_RabbitTargetHandle = h;
	m_RabbitShooterHandle = 0;

	if(!IsPlayer(h))
	{
		m_RabbitWasHuman = false;
		m_RabbitTeam = 0;
		SetTeamNum(h, 15); // Force a different team #, so AI will target them.
	}
	else
	{
		m_RabbitWasHuman = true;
		m_RabbitTeam = GetTeamNum(h);
	}

	int i;

	bool FoundIt = false;
	for(i = 1;i<MAX_TEAMS;i++)
	{
		Handle PlayerH = GetPlayerHandle(i);
		if(PlayerH == m_RabbitTargetHandle)
		{
			Trace(("New Rabbit is human, team %d\n", i));
			FoundIt = true;
		}
	}

	if(!FoundIt)
	{
		Trace(("New Rabbit isn't human, handle %08X\n", m_RabbitTargetHandle));
	}

	// Reset targets for all bots
	for(i = 0;i<m_NumAIUnits;i++)
	{
		if(m_AICraftHandles[i] == h)
			continue; // do nothing...
		FindGoodAITarget(i);
	}

	// Also, reset objectives the local player.
	Handle PlayerH = GetPlayerHandle();
	if(PlayerH == m_RabbitTargetHandle)
	{
		// We're the victim. Let them know.
		AddToMessagesBox(GetBZCCLocalizedString("mission", "It's wabbit hunting season. Do you feel lucky?"));
	}
	else
	{
		ObjectifyRabbit();
	}
} // end of SetNewRabbit.


Handle Deathmatch01::SetupPlayer(int Team)
{
	Handle PlayerH = 0;
	Vector Where;
	memset(&Where, 0, sizeof(Where));

	if((Team < 0) || (Team >= MAX_TEAMS))
		return 0; // Sanity check... do NOT proceed

	m_SpawnedAtTime[Team] = m_ElapsedGameTime; // Note when they spawned in.

	int TeamBlock = WhichTeamGroup(Team);

	if((!IsTeamplayOn()) || (TeamBlock<0))
	{

		if(DMIsRaceSubtype[m_MissionType])
			Where = GetSpawnpoint(0); // Start at spawnpoint 0
		else
			Where = GetRandomSpawnpoint();

		// And randomize around the spawnpoint slightly so we'll
		// hopefully never spawn in two pilots in the same place
		Where = GetPositionNear(Where, AllyMinRadiusAway, AllyMaxRadiusAway);
		Where.y += 1.0f;

		// This player is their own commander; set up their equipment.
		SetupTeam(Team);
	}
	else
	{
		// Teamplay. Gotta put them near their commander. Also, always
		// ensure the recycler/etc has been set up for this team if we
		// know who they are
		SetupTeam(GetCommanderTeam(Team));

		// SetupTeam will fill in the m_TeamPos[] array of positions
		// for both the commander and offense players, so read out the
		// results
		Where.x = m_TeamPos[3*Team+0];
		Where.z = m_TeamPos[3*Team+2];
		Where.y = TerrainFindFloor(Where.x, Where.z) + 1.0f;
	} // Teamplay setup

	if(DMIsRaceSubtype[m_MissionType]) 
	{
		// Race. Start off near spawnpoint 0
		Where = GetSpawnpoint(0);
		Where = GetPositionNear(Where, AllyMinRadiusAway, AllyMaxRadiusAway);
		Where.y += 1.0f;
		m_NextRaceCheckpoint[Team] = 1; // Heading towards sp 1
		m_TotalCheckpointsCompleted[Team] = 0; // None so far
		m_LapNumber[Team] = 0; // None so far
		m_RaceWinerCount = 0; // None so far
		RaceSetObjective = false;
	}

	PlayerH = BuildObject(GetPlayerODF(Team), Team, Where);
	if(!DMIsRaceSubtype[m_MissionType]) 
		SetRandomHeadingAngle(PlayerH);
	SetNoScrapFlagByHandle(PlayerH);

	// Make their pilot match the respawn pilot. -GBD
	SetPilotClass(PlayerH, GetInitialPlayerPilotODF(GetRaceOfTeam(Team)));

	// If on team 0 (dedicated server team), make this object gone from the world
	if(!Team)
		MakeInert(PlayerH);

	if((IsTeamplayOn()) && (TeamBlock >= 0))
	{
		// Also set up the other side too now, in case it wasn't done earlier.
		// This puts both CTF flags on the map when the first player joins.
		SetupTeam(7 - GetCommanderTeam(Team));
	}

	return PlayerH;
}

void Deathmatch01::InitialSetup(void)
{
	LuaMission::InitialSetup();

	m_DidOneTimeInit = false;
	m_FirstTime = true;
	m_DMSetup = false;
}

// Collapses the tracked vehicle list so there are no holes (values
// of 0) in it, puts the updated count in m_NumVehiclesTracked
void Deathmatch01::CrunchEmptyVehicleList(void)
{
	int i, j = 0;
	for(i = 0;i<MAX_VEHICLES_TRACKED;i++)
	{
		if(m_EmptyVehicles[i])
		{
			m_EmptyVehicles[j] = m_EmptyVehicles[i];
			j++;
		}
	}

	m_NumVehiclesTracked = j; // idx of the first empty slot

	// Zero out the rest of the array
	for(j = m_NumVehiclesTracked;j<MAX_VEHICLES_TRACKED;j++)
	{
		m_EmptyVehicles[j] = 0;
	}
}

// Designed to be called from Execute(), updates list of empty
// vehicles, killing some if there are too many, and forgetting
// about any if they've been entered.
void Deathmatch01::UpdateEmptyVehicles(void)
{
	// Early-exit if no vehicles tracked.
	if(!m_NumVehiclesTracked)
		return;

	int i;
	bool anyChanges = false;
	for(i = 0;i<MAX_VEHICLES_TRACKED;i++)
	{
		if(m_EmptyVehicles[i])
		{
			// Side effect to note: IsAliveAndPilot zeroes the handle if
			// pilot missing; that'd be bad for us here if we want to
			// manually remove it. Thus, we have a sacrificial varb
			Handle TempH = m_EmptyVehicles[i];
			if(!IsAround(m_EmptyVehicles[i]))
			{
				m_EmptyVehicles[i] = 0; // craft died. Forget about it.
				anyChanges = true;
			}
			else if(IsPlayer(m_EmptyVehicles[i]))
			{
				m_EmptyVehicles[i] = 0; // Human entered this. No longer empty
				anyChanges = true;
			}
			else if(IsAliveAndPilot(TempH))
			{
				m_EmptyVehicles[i] = 0; // AI pilot entered this. No longer empty
				anyChanges = true;
			}
		}
	} // i loop over MAX_VEHICLES_TRACKED

	// Tweak the list if needed.
	if(anyChanges)
	{
		CrunchEmptyVehicleList();
		anyChanges = false;
	}

	// If there's too many craft floating around, then kill the oldest.
	// Above code ensures that m_EmptyVehicles[0] is valid.
	int CurNumPlayers = CountPlayers();
	int MaxEmpties = CurNumPlayers + (CurNumPlayers>>1) + 1; // 150% of # of players on map
	if(m_NumVehiclesTracked > MaxEmpties)
	{
		SelfDamage(m_EmptyVehicles[0], 1e+20f);
		m_EmptyVehicles[0] = 0; // forget about this craft, as it better not exist anymore
		anyChanges = true;
	}

	// Tweak the list if needed.
	if(anyChanges)
	{
		CrunchEmptyVehicleList();
		anyChanges = false;
	}
}

// Adds a vehicle to the tracking list, and kills the oldest unpiloted
// one if list full
void Deathmatch01::AddEmptyVehicle(Handle NewCraft)
{
	if(NewCraft == 0)
		return;

	// Don't overflow buffer!
	if(m_NumVehiclesTracked >= MAX_VEHICLES_TRACKED)
	{
		UpdateEmptyVehicles();

		// Kill oldest one, NOW.
		if(m_EmptyVehicles[0])
		{
			SelfDamage(m_EmptyVehicles[0], 1e+20f);
			m_EmptyVehicles[0] = 0; // forget about this craft, as it better not exist anymore
			CrunchEmptyVehicleList();
		}
	}

	// This better succeed after the above.
	if(m_NumVehiclesTracked < MAX_VEHICLES_TRACKED)
	{
		m_EmptyVehicles[m_NumVehiclesTracked++] = NewCraft;
	}
} // AddEmptyVehicle()


void Deathmatch01::Init(void)
{
	if(i_array)
		memset(i_array, 0, i_count*sizeof(int));
	if(f_array)
		memset(f_array, 0, f_count*sizeof(float));
	if(h_array)
		memset(h_array, 0, h_count*sizeof(Handle));
	if(b_array)
		memset(b_array, 0, b_count*sizeof(bool));

	RaceSetObjective = false;

	// Read from the map's .trn file whether we respawn at altitude or
	// not, and the spawnpoint tunables.
	{
		char mapTrnFile[128];
		strcpy_s(mapTrnFile, GetMapTRNFilename());
		OpenODF2(mapTrnFile);
		GetODFBool(mapTrnFile, "DLL", "RespawnAtLowAltitude", &m_RespawnAtLowAltitude, false);
		GetODFFloat(mapTrnFile, "DLL", "CheckpointRadius", &m_RaceCheckpointRadius, 35.0f);
		GetODFFloat(mapTrnFile, "DLL", "FriendlySpawnpointMaxAllyRange", &m_FRIENDLY_SPAWNPOINT_MAX_ALLY, FRIENDLY_SPAWNPOINT_MAX_ALLY);
		GetODFFloat(mapTrnFile, "DLL", "FriendlySpawnpointMinEnemyRange", &m_FRIENDLY_SPAWNPOINT_MIN_ENEMY, FRIENDLY_SPAWNPOINT_MIN_ENEMY);
		GetODFFloat(mapTrnFile, "DLL", "RandomSpawnpointMinEnemyRange", &m_RANDOM_SPAWNPOINT_MIN_ENEMY, RANDOM_SPAWNPOINT_MIN_ENEMY);
	}
	TRNAllies::SetupTRNAllies(GetMapTRNFilename());

	m_LastTeamInLead = DPID_UNKNOWN;

	m_KillLimit = GetVarItemInt("network.session.ivar0");
	m_TotalGameTime = GetVarItemInt("network.session.ivar1");
	// Skip ivar2-- player limit. Assume the netmgr takes care of that.
	int MissionTypePrefs = GetVarItemInt("network.session.ivar7");
	m_TotalRaceLaps = GetVarItemInt("network.session.ivar9"); // Just in case we're using this
	m_Gravity = GetVarItemInt("network.session.ivar31");
	m_ScoreLimit = GetVarItemInt("network.session.ivar35");
	// Set this for the server now. Clients get this set from Load().
	SetGravity(static_cast<float>(m_Gravity) * 0.5f);

	m_bIsFriendlyFireOn = (GetVarItemInt("network.session.ivar32") != 0);

	m_MaxSpawnKillTime = GetVarItemInt("network.session.ivar13") * m_GameTPS; // convert seconds to ticks
	if(m_MaxSpawnKillTime < 0)
		m_MaxSpawnKillTime = 0; // sanity check

	m_NumAIUnits = 0;
	m_MaxAIUnits = 0;
	m_MissionType = MissionTypePrefs&0xFF;
	m_RespawnType = (MissionTypePrefs>>8) &0xFF;

	if(!DMIsRaceSubtype[m_MissionType])
	{
		m_MaxAIUnits = GetVarItemInt("network.session.ivar9");
		if(m_MaxAIUnits >= MAX_AI_UNITS)
			m_MaxAIUnits = MAX_AI_UNITS; 

		// If the network is not on, this map was probably started from the
		// commandline, and therefore, ivars are not at the defaults expected.
		// Switch to some sane defaults.
		if(!IsNetworkOn())
		{
			m_MaxAIUnits = 0;
			m_Gravity = 25; // default
			SetGravity(static_cast<float>(m_Gravity) * 0.5f);
		}
	}

	m_AIUnitSkill = GetVarItemInt("network.session.ivar22");
	if((m_AIUnitSkill < 0) || (m_AIUnitSkill >4))
		m_AIUnitSkill = 3;

	if(!IsNetworkOn())
		m_AIUnitSkill = 3;

	m_HumansVsBots = GetVarItemInt("network.session.ivar16") != 0;

	// If it's vs bots, make all humans allied (but not with animals
	// (team 13))
	if(m_HumansVsBots)
	{
		int i, j;
		for(i = 1;i<12;i++)
		{
			for(j = 1;j<12;j++)
			{
				if(i != j)
				{
					Ally(i, j);
				}
			}
		}
	}

	m_RabbitMode = GetVarItemInt("network.session.ivar23") != 0;

	m_WeenieMode = GetVarItemInt("network.session.ivar19") != 0;
	m_ShipOnlyMode = GetVarItemInt("network.session.ivar25") != 0;

	m_NumAnimals = 0;
	m_MaxAnimals = GetVarItemInt("network.session.ivar27");
	if(m_MaxAnimals >= MAX_ANIMALS)
		m_MaxAnimals = MAX_ANIMALS; 

	if(m_MaxAnimals > 0)
	{
		const char* pAnimalConfig = DLLUtils::GetCheckedNetworkSvar(12, NETLIST_Animals);
		if((pAnimalConfig == NULL) || (strlen(pAnimalConfig) < 2))
			pAnimalConfig = "mcjak01";

		char *pStoreConfig = (char*)&m_AnimalConfig[0];
		size_t len = sizeof(m_AnimalConfig);
		strcpy_s(pStoreConfig, len, pAnimalConfig);
	}

	Handle PlayerH = 0;
	Handle playerEntryH = 0;
	int LocalTeamNum = GetLocalPlayerTeamNumber(); // Query this from game

	// As the .bzn has a vehicle which may not be appropriate, we
	// must zap that player object and recreate them the way we want
	// them when the game starts up.
	playerEntryH = GetPlayerHandle();
	if(playerEntryH) 
		RemoveObject(playerEntryH);

	// Do One-time server side init of varbs for everyone
	if((ImServer()) || (!IsNetworkOn()))
	{
		if(!m_RemainingGameTime)
			m_RemainingGameTime = m_GameTPS * m_TotalGameTime * 60; // convert minutes to ticks

		// And build local player
		PlayerH = SetupPlayer(LocalTeamNum);
		SetAsUser(PlayerH, LocalTeamNum);
		AddPilotByHandle(PlayerH);

		// First player becomes the rabbit target
		if((m_RabbitMode) && (m_RabbitTargetHandle == 0))
		{
			SET_NEW_RABBIT(PlayerH);
		}

	} // Server or no network

	CreateObjectives();

	PUPMgr::Init();
	m_FirstTime = false;
	m_DidOneTimeInit = true;
}


// Flags the appropriately 'next' spawnpoint as the objective
void Deathmatch01::ObjectifyRacePoint(void)
{
	// First, clear all previous objectives
	for(int i = 0;i<m_TotalCheckpoints;i++)
	{
		sprintf_s(TempODFName, "checkpoint%d", i+1);
		SetObjectiveOff(GetHandle(TempODFName)); // Ensure these are all cleared off.
	}
	int Idx = GetLocalPlayerTeamNumber();
	if(Idx >= 0)
	{
		if(!m_TotalRaceLaps || (m_LapNumber[Idx] < m_TotalRaceLaps))
		{
			sprintf_s(TempODFName, "checkpoint%d", m_NextRaceCheckpoint[Idx]);
			Handle NextCheckpoint = GetHandle(TempODFName);
			if(NextCheckpoint)
				SetObjectiveOn(NextCheckpoint);
		}
	}
}


// Rabbit-specific execute stuff. Kill da wabbit! Kill da wabbit!
void Deathmatch01::ExecuteRabbit(void)
{
	// Rebuild the rabbit if they're missing for more than a half
	// second...
	Handle RabbitH = m_RabbitTargetHandle;
	if(IsAround(RabbitH))
	{

		m_RabbitMissingTurns = 0;
		// Account for human hopping out of craft (which would keep the
		// rabbit designation, while the pilot is the true rabbit)
		if((m_RabbitWasHuman) && (RabbitH != GetPlayerHandle(m_RabbitTeam)))
		{
			// Unobjectify the old craft.
			Handle NewRabbit = GetPlayerHandle(m_RabbitTeam);
			SET_NEW_RABBIT(NewRabbit);
		}
	}
	else
	{
		Trace(("Rabbit (%08X) has gone missing :(\n", RabbitH));
		m_RabbitMissingTurns++;
	}

	// Track the rabbit shooter in case they died/switched vehicles, etc
	if((m_RabbitShooterWasHuman) && (m_RabbitShooterHandle != GetPlayerHandle(m_RabbitShooterTeam)))
	{
		m_RabbitShooterHandle = GetPlayerHandle(m_RabbitShooterTeam);
		Trace(("Resetting shooter to be handle %08X on team %d\n", m_RabbitShooterHandle, m_RabbitShooterTeam));
	}

	if(m_RabbitMissingTurns > 1)
	{
		// Do the in-depth search for a new target
		RabbitH = m_RabbitTargetHandle;
		if(!IsAround(RabbitH))
		{
			// Uhoh. Lost the target. :(
			if((m_RabbitWasHuman) && (m_RabbitTeam != m_ForbidRabbitTeam))
			{
				// Move to current vehicle on that team.
				Handle NewRabbit = GetPlayerHandle(m_RabbitTeam);
				SET_NEW_RABBIT(NewRabbit);
			}
		}

		RabbitH = m_RabbitTargetHandle;
		if(!IsAround(RabbitH))
		{
			// Still gone? Gotta rebuild target.
			RabbitH = m_RabbitShooterHandle; // last person to shoot them...
			if(IsAround(RabbitH))
			{
				SET_NEW_RABBIT(m_RabbitShooterHandle);
			}
			else
			{
				// Gone, no known shooter. Pick a semi-random human to take
				// over. The timestep at which this occurrs should be fairly
				// random
				int i;
				bool foundNewRabbit = false;
				for(i = 0;i<MAX_TEAMS;i++)
				{
					int T2 = (m_ElapsedGameTime+i) % MAX_TEAMS;
					Handle PlayerH = GetPlayerHandle(T2);
					if((T2 && PlayerH) && (T2 != m_ForbidRabbitTeam))
					{
						SET_NEW_RABBIT(PlayerH);
						foundNewRabbit = true;
						m_ForbidRabbitTeam = 0;
						break; // out of this for loop
					}
				}

				// If we didn't find a human, pick a random AI
				if(!foundNewRabbit)
				{
					for(i = 0;i<MAX_AI_UNITS;i++) 
					{
						int index2 = (m_ElapsedGameTime+i) % MAX_AI_UNITS;
						if(m_AICraftHandles[index2])
						{
							SET_NEW_RABBIT(m_AICraftHandles[index2]);
							foundNewRabbit = true;
							m_ForbidRabbitTeam = 0;
							break; // out of this for loop
						}
					} // i loop over MAX_AI_UNITS
				} // Still hadn't found a human player to be the rabbit


				AddToMessagesBox(GetBZCCLocalizedString("mission", "Reset the rabbit... it's hunting season!"));
				Trace(("Reset the rabbit... it's hunting season!"));
			}
		}
	}

	// If the rabbit's MIA, skip this.
	RabbitH = m_RabbitTargetHandle;
	if(!IsAround(RabbitH))
		return; // Can't do a thing here.

	// Update the last *other* person to hit me, only overriding if
	// valid data
	Handle LastShooter = GetWhoShotMe(m_RabbitTargetHandle);
	int i;
	if((LastShooter) && (LastShooter != m_RabbitTargetHandle) && (LastShooter != m_RabbitShooterHandle))
	{

		// Workaround- if player (craft) was rabbit shooter, but they
		// died as a pilot, LastShooter will the craft that did the
		// shooting. So, reassign to player if they're still around.
		int LastShooterTeam = GetTeamNum(LastShooter);
		if((LastShooterTeam == m_RabbitShooterTeam) || (m_RabbitShooterTeam == 0))
		{
			Handle temph = GetPlayerHandle(m_RabbitShooterTeam);
			if(temph)
				LastShooter = temph;
		}

		m_RabbitShooterHandle = LastShooter;

		// Preclear this...
		m_RabbitShooterWasHuman = false;
		m_RabbitShooterTeam = 0;

		bool FoundIt = false;
		for(i = 1;i<MAX_TEAMS;i++)
		{
			Handle PlayerH = GetPlayerHandle(i);
			if(PlayerH == m_RabbitShooterHandle)
			{
				m_RabbitShooterWasHuman = true;
				m_RabbitShooterTeam = i;
				FoundIt = true;

				Trace(("Rabbit shooter is human, team %d\n", i));
			}
		}
	}

	// Have a known rabbit. Update scores for them, 1 point every 5 seconds
	if(((m_ElapsedGameTime % (5 * m_GameTPS)) == 0) && ((CountPlayers() > 1) || (m_NumAIUnits > 0)))
	{
		AddScore(m_RabbitTargetHandle, 1); // Staying alive....
	}

	if(!(m_ElapsedGameTime % m_GameTPS))
	{
		ObjectifyRabbit();
	}
} // ExecuteRabbit

// Race-specific execute stuff.
void Deathmatch01::ExecuteRace(void)
{
	if((!RaceSetObjective) || (!(m_ElapsedGameTime % m_GameTPS))) 
	{
		// Race. Gotta set objectives properly
		RaceSetObjective = true;
		ObjectifyRacePoint();
	} // Periodic re-objectifying

	// Also, check if everyone's near their next checkpoint
	bool Advanced[MAX_TEAMS];
	bool AnyAdvanced = false;
	int i, j;

	for(i = 0;i<MAX_TEAMS;i++)
	{
		Advanced[i] = false;
		Handle PlayerH = GetPlayerHandle(i);
		if(!PlayerH)
			continue; // Do nothing for them.

		sprintf_s(TempODFName, "checkpoint%d", m_NextRaceCheckpoint[i]);
		Handle NextCheckpoint = GetHandle(TempODFName);
		if(NextCheckpoint)
		{
			//Player is close enough AND (0 laps OR not finished already)
			if((GetDistance(PlayerH, NextCheckpoint) < (m_RaceCheckpointRadius)) && ((!m_TotalRaceLaps) || (m_LapNumber[i] < m_TotalRaceLaps)))
			{
				m_NextRaceCheckpoint[i]++;
				if(m_NextRaceCheckpoint[i] > m_TotalCheckpoints)
				{
					m_NextRaceCheckpoint[i] = 1;
					m_LapNumber[i]++;
				}
				ObjectifyRacePoint();
				Advanced[i] = true;
				AnyAdvanced = AnyAdvanced || Advanced[i];
				m_TotalCheckpointsCompleted[i]++;

				// Print out a message for local player upon lap completion
				if((m_NextRaceCheckpoint[i]==1) && (i == GetLocalPlayerTeamNumber()))
				{
					if(m_TotalRaceLaps) 
						sprintf_s(StaticTempMsgStr, GetBZCCLocalizedString("mission", "Lap %d/%d Completed"), m_LapNumber[i], m_TotalRaceLaps);
					else
						sprintf_s(StaticTempMsgStr, GetBZCCLocalizedString("mission", "Lap %d Completed"), m_LapNumber[i]);

					AddToMessagesBox(StaticTempMsgStr);
				}
			}
		} // NextCheckpoint exists
	} // Loop over all players

	// Give a point to someone if they made it to a checkpoint before anyone else did.
	if(AnyAdvanced)
	{
		for(i = 0;i<MAX_TEAMS;i++) 
			if(Advanced[i])
			{
				Handle PlayerH = GetPlayerHandle(i);

				bool LeadingPlayer = true;
				for(j = 0;j<MAX_TEAMS;j++)
					if((i!= j) && (m_TotalCheckpointsCompleted[i]<= m_TotalCheckpointsCompleted[j]))
						LeadingPlayer = false;
				if(LeadingPlayer)
				{
					if(i != m_LastTeamInLead)
					{
						sprintf_s(StaticTempMsgStr, GetBZCCLocalizedString("mission", "%s takes the lead"), GetPlayerName(PlayerH));
						AddToMessagesBox(StaticTempMsgStr);
						m_LastTeamInLead = i;
					}
				}

				// Also check if leader completed a full lap
				LeadingPlayer = true;
				for(j = 0;j<MAX_TEAMS;j++)
					if((i!= j) && (m_TotalCheckpointsCompleted[i]<m_TotalCheckpointsCompleted[j]))
						LeadingPlayer = false;
				if((LeadingPlayer) && (m_NextRaceCheckpoint[i] == 1))
				{
					AddScore(PlayerH, 1);

					if(m_TotalRaceLaps)
					{
						if(!m_RaceWinerCount)
							sprintf_s(StaticTempMsgStr, GetBZCCLocalizedString("mission", "Lap %d/%d completed by %s"), m_LapNumber[i], m_TotalRaceLaps, GetPlayerName(PlayerH));
					}
					else
					{
						if(!m_RaceWinerCount)
							sprintf_s(StaticTempMsgStr, GetBZCCLocalizedString("mission", "Lap %d completed by %s"), m_LapNumber[i], GetPlayerName(PlayerH));
					}

					AddToMessagesBox(StaticTempMsgStr);
					if(m_LapNumber[i] == m_TotalRaceLaps)
					{
						m_RaceWinerCount++;
						switch ( m_RaceWinerCount )
						{
						case 1:
							sprintf_s(StaticTempMsgStr, GetBZCCLocalizedString("mission", "%s finished in 1st place"), GetPlayerName(PlayerH));
							AddScore(PlayerH, 100);
							break;
						case 2:
							sprintf_s(StaticTempMsgStr, GetBZCCLocalizedString("mission", "%s finished in 2nd place"), GetPlayerName(PlayerH));
							AddScore(PlayerH, 75);
							break;
						case 3:
							sprintf_s(StaticTempMsgStr, GetBZCCLocalizedString("mission", "%s finished in 3rd place"), GetPlayerName(PlayerH));
							AddScore(PlayerH, 50);
							break;
						default:
							sprintf_s(StaticTempMsgStr, GetBZCCLocalizedString("mission", "%s finished in %dth place"), GetPlayerName(PlayerH), m_RaceWinerCount);
							AddScore(PlayerH, 25);
						}
						if(m_RaceWinerCount <= 1)
						{
							NoteGameoverWithCustomMessage(StaticTempMsgStr);
							strcpy_s(StaticTempMsgStr, GetBZCCLocalizedString("mission", "10 seconds left..."));
						}
						else
						{
							AddToMessagesBox(StaticTempMsgStr);
						}
						DoGameover(10.0f);
					}

				}
			}
	}
} // ExecuteRace()

void Deathmatch01::ExecuteWeenie(void)
{
	int i;
	// Go over all humans first
	for(i = 1;i<MAX_TEAMS;i++)
	{
		Handle p = GetPlayerHandle(i);
		if(p)
		{
			// self-fire doesn't count; neither does friendly fire when it's off
			Handle h = GetWhoShotMe(p);
			if(h && (h != p) && ((GetLastEnemyShot(p) >= 0.0f) || (m_bIsFriendlyFireOn)))
				DamageF(p, MAX_FLOAT);
		}
	}

	for(i = 0;i<m_NumAIUnits;i++)
	{
		Handle p = m_AICraftHandles[i];
		if(p)
		{
			// self-fire doesn't count
			Handle h = GetWhoShotMe(p);
			if(h && (h != p) && ((GetLastEnemyShot(p) >= 0.0f) || (m_bIsFriendlyFireOn)))
				DamageF(p, MAX_FLOAT);
		}
	}

	for(i = 0;i<m_NumAnimals;i++)
	{
		Handle p = m_AnimalHandles[i];
		if(p)
		{
			// self-fire doesn't count
			Handle h = GetWhoShotMe(p);
			if(h && (h != p) && ((GetLastEnemyShot(p) >= 0.0f) || (m_bIsFriendlyFireOn)))
				DamageF(p, MAX_FLOAT);
		}
	}

	for(i = 0;i<m_NumVehiclesTracked;i++)
	{
		Handle p = m_EmptyVehicles[i];
		if(p)
		{
			// self-fire doesn't count
			Handle h = GetWhoShotMe(p);
			if(h && (h != p) && ((GetLastEnemyShot(p) >= 0.0f) || (m_bIsFriendlyFireOn)))
				DamageF(p, MAX_FLOAT);
		}
	}
}

// Notices what ships all the human players are currently in. If they
// hop out, then their old craft is pushed onto the empties list. If
// this is 'ship only' mode, then other penalties are applied.
void Deathmatch01::ExecuteTrackPlayers(void)
{
	int i;
	// Go over all humans first
	for(i = 1;i<MAX_TEAMS;i++)
	{
		Handle p = GetPlayerHandle(i);
		if(p)
		{
			SetLifespan(p, -1.0f); // Ensure there's no lifespan killing this craft

			if(IsAliveAndPilot(p))
			{
				// Make sure the 'spawn kill' doesn't get triggered.
				if(m_ShipOnlyMode)
				{
					m_SpawnedAtTime[i] = -4096;

					if((m_MissionType == DMSubtype_Normal) || (m_MissionType == DMSubtype_Normal2))
						AddScore(p, -ScoreForKillingCraft); // Ouch. Don't do that!
					SelfDamage(p, 1e+20f);
				}

				// Did they just hop out, leaving that craft w/o a pilot? Nuke that craft too.
				Handle lastp = m_LastPlayerCraftHandle[i];
				if(IsAround(lastp))
				{
					lastp = m_LastPlayerCraftHandle[i];
					if(!IsAliveAndPilot(lastp))
					{
						if(m_ShipOnlyMode)
						{
							SelfDamage(m_LastPlayerCraftHandle[i], 1e+20f);
						}
						else
						{
							// Not ship-only mode. Add this to empties list
							if(m_NumVehiclesTracked < MAX_VEHICLES_TRACKED)
								m_EmptyVehicles[m_NumVehiclesTracked++] = m_LastPlayerCraftHandle[i];
						}
						m_LastPlayerCraftHandle[i] = 0; // 'forget' about this.
					} // last craft is now an empty
				} // lastp is still around
			} // p is currently a pilot.
			else
			{
				// Must be in a craft. Store it.
				m_LastPlayerCraftHandle[i] = p;
			}
		} // p valid (i.e. human is playing on that team)
	} // i loop over MAX_TEAMS
} // ExecuteTrackPlayers


// Called via execute, m_GameTPS of a second has elapsed. Update everything.
void Deathmatch01::UpdateGameTime(void)
{
	m_ElapsedGameTime++;

	// Are we in a time limited game?
	if(m_RemainingGameTime>0)
	{
		m_RemainingGameTime--;
		if(!(m_RemainingGameTime % m_GameTPS))
		{
			// Convert tenth-of-second ticks to hour/minutes/seconds format.
			int Seconds = m_RemainingGameTime / m_GameTPS;
			int Minutes = Seconds / 60;
			int Hours = Minutes / 60;
			// Lop seconds and minutes down to 0..59 once we've grabbed
			// non-remainder out.
			Seconds %= 60;
			Minutes %= 60;

			if(Hours)
				sprintf_s(TempMsgString, GetBZCCLocalizedString("mission", "Time Left %d:%02d:%02d\n"), Hours, Minutes, Seconds);
			else
				sprintf_s(TempMsgString, GetBZCCLocalizedString("mission", "Time Left %d:%02d\n"), Minutes, Seconds);
			SetTimerBox(TempMsgString);

			// Also print this out more visibly at important times....
			if(Hours == 0)
			{
				// Every 5 minutes down to 10 minutes, then every minute
				// thereafter.
				if((Seconds == 0) && ((Minutes <= 10) || (!(Minutes % 5))))
					AddToMessagesBox(TempMsgString);
				else
				{
					// Every 5 seconds when under a minute is remaining.
					if((Minutes == 0) && (!(Seconds % 5)))
						AddToMessagesBox(TempMsgString);
				}
			}
		}

		// Game over due to timeout?
		if(!m_RemainingGameTime)
		{
			NoteGameoverByTimelimit();
			DoGameover(10.0f);
		}

	}
	else
	{
		// Infinite time game. Periodically update ingame clock.
		if(!(m_ElapsedGameTime % m_GameTPS))
		{
			// Convert tenth-of-second ticks to hour/minutes/seconds format.
			int Seconds = m_ElapsedGameTime / m_GameTPS;
			int Minutes = Seconds / 60;
			int Hours = Minutes / 60;
			// Lop seconds and minutes down to 0..59 once we've grabbed
			// non-remainder out.
			Seconds %= 60;
			Minutes %= 60;

			if(Hours)
				sprintf_s(TempMsgString, GetBZCCLocalizedString("mission", "Mission Time %d:%02d:%02d"), Hours, Minutes, Seconds);
			else
				sprintf_s(TempMsgString, GetBZCCLocalizedString("mission", "Mission Time %d:%02d"), Minutes, Seconds);
			SetTimerBox(TempMsgString);
		}
	}
}

void Deathmatch01::UpdateAIUnits()
{
	int i;

	// Need to spawn in a new craft at the start of the game
	// (staggered every second)
	const int InitialSpawnInFrequency = 5; // 10 ticks per second

	if(!(m_ElapsedGameTime % InitialSpawnInFrequency))
	{
		if(m_NumAIUnits < m_MaxAIUnits)
		{
			BuildBotCraft(m_NumAIUnits);
			m_NumAIUnits++;
		}
		else
		{
			for(i = 0;i<m_NumAIUnits;i++) 
			{
				// Fix for mantis #400 - if a bot craft is sniped,
				// 'forget' about it and build another in its slot.
				if(!IsNotDeadAndPilot2(m_AICraftHandles[i]))
				{
					SetLifespan(m_AICraftHandles[i], SNIPED_AI_LIFESPAN);
					m_AICraftHandles[i] = 0;
				}

				if(m_AICraftHandles[i] == 0) 
				{
					BuildBotCraft(i);
					break;
				}
			}
		}
	}

	// Periodically, update all the AI tasks. This is set to 3.2
	// seconds by default. It rotates thru all bots, one per tick.
	for(i = 0;i<m_NumAIUnits;i++)
	{
		if(((m_ElapsedGameTime + i) & 0x1F) == 0)
		{

			if(m_AILastWentForPowerup[i])
			{
				Handle Target = m_AITargetHandles[i];
				m_PowerupGotoTime[i]++;
				// Max of 15 seconds to pick up a powerup, then we go again
				if((!IsAlive(Target)) || (m_PowerupGotoTime[i] > 150) ||
					(GetDistance(m_AICraftHandles[i], m_AITargetHandles[i]) < 2.0f))
				{
					// Need to retarget.
					FindGoodAITarget(i);
				}
			}
			// combat mode, not going for powerups: nothing to do (not multiworld friendly).
		} // Time to recalculate this.
	} // loop over AI units
} // UpdateAIUnits();

void Deathmatch01::UpdateAnimals()
{
	int i;

	// Have to manually check on animals; they won't trigger a call to
	// DeadObject(). If any died, note that.
	for(i = 0;i<m_NumAnimals;i++)
	{
		if(m_AnimalHandles[i] != 0)
		{
			Handle h = m_AnimalHandles[i];
			if(!IsAlive(h))
				m_AnimalHandles[i] = 0;
		}
	} // loop over all objects

	// Spawn in animals at the start of the game (staggered every 4
	// seconds)
	const int InitialSpawnInFrequency = 4 * m_GameTPS; // m_GameTPS ticks per second

	if(!(m_ElapsedGameTime % InitialSpawnInFrequency))
	{
		if(m_NumAnimals < m_MaxAnimals)
		{
			SetupAnimal(m_NumAnimals);
			m_NumAnimals++;
		}
		else
		{
			// 'Full' set of animals. Do respawns as needed.
			for(i = 0;i<m_NumAnimals;i++)
			{
				if(m_AnimalHandles[i] == 0)
				{
					SetupAnimal(i);
					break;
				}
			}
		}
	} // periodic check
} // UpdateAnimals()

void Deathmatch01::Execute(void)
{
	int i;

	if(!StopScript)
		LuaMission::Execute();

	// Always ensure we did this
	if (!m_DidOneTimeInit)
		Init();

	// Always see if any empties are filled or need to be killed
	UpdateEmptyVehicles();

	if(DMIsRaceSubtype[m_MissionType]) 
		ExecuteRace();

	if((m_RabbitMode) && ((m_MissionType == DMSubtype_Normal) || (m_MissionType == DMSubtype_Normal2)))
		ExecuteRabbit();

	if(m_WeenieMode)
		ExecuteWeenie();

	// CTF - periodically re-objectify the opponent's flag
	if(m_MissionType == DMSubtype_CTF)
	{
		if(!(m_ElapsedGameTime % m_GameTPS))
		{
			ObjectifyFlag();
		}
	}

	ExecuteTrackPlayers();

	// Do this as well...
	UpdateGameTime();

	if(m_MaxAIUnits)
		UpdateAIUnits();

	if(m_MaxAnimals)
		UpdateAnimals();

	// Keep powerups going, etc
	PUPMgr::Execute();

	// Check to see if someone was flagged as flying, and if they've
	// landed, build a new craft for them
	for(i = 0;i<MAX_TEAMS;i++)
	{
		if(m_Flying[i])
		{
			Handle PlayerH = GetPlayerHandle(i);
			if((PlayerH != 0) && (!IsFlying(PlayerH)))
			{
				m_Flying[i] = false; // clear flag so we don't check until they're dead
				if(PlayerH)
				{
					const char *ODF = GetNextVehicleODF(i, true);
					Handle h = BuildEmptyCraftNear(PlayerH, ODF, i, RespawnMinRadiusAway, RespawnMaxRadiusAway);
					if(h)
					{
						SetTeamNum(h, 0); // flag as neutral so AI won't immediately hit it

						AddEmptyVehicle(h); // Clean things up if there are too many around
					}
				}
			}
		}
	}

	// Mission scoring for KOH/CTF now done in main game, so we
	// don't need to do anything here. Except gameover. In teamplay
	// the two team groups' scores are summed. -GBD

	if((m_ScoreLimit > 0) && (!m_bDidGameOverByScore))
	{
		const bool TeamPlayOn = IsTeamplayOn();
		Handle TeamPlayer[2] = { 0, 0 };
		int TeamScore[2] = { 0, 0 };
		for(i=0;i<MAX_TEAMS;i++)
		{
			const Handle playerH = GetPlayerHandle(i);
			if(playerH == 0)
			{
				continue;
			}

			if(!TeamPlayOn)
			{
				if(GetScore(playerH) >= m_ScoreLimit)
				{
					NoteGameoverByScore(playerH);
					DoGameover(5.0f);
					m_bDidGameOverByScore = true;
					break;
				}
			}
			else
			{
				const int TeamGroup = WhichTeamGroup(i);
				if(TeamGroup < 2)
				{
					TeamScore[TeamGroup] += GetScore(playerH);
					if(TeamPlayer[TeamGroup] == 0)
						TeamPlayer[TeamGroup] = playerH;
				}
			}
		}

		if(TeamPlayOn)
		{
			for(i=0;i<2;i++)
			{
				if(TeamScore[i] >= m_ScoreLimit)
				{
					NoteGameoverByScore(TeamPlayer[i]);
					DoGameover(5.0f);
					m_bDidGameOverByScore = true;
					return;
				}
			}
		}
	}
}

bool Deathmatch01::AddPlayer(DPID id, int Team, bool IsNewPlayer)
{
	if(!StopScript)
		LuaMission::AddPlayer(id, Team, IsNewPlayer);

	if (!m_DidOneTimeInit)
		Init();

	// Server does all building; client doesn't need to do anything
	if (IsNewPlayer)
	{
		Handle PlayerH = SetupPlayer(Team);
		SetAsUser(PlayerH, Team);
		AddPilotByHandle(PlayerH);
		SetNoScrapFlagByHandle(PlayerH);
	}

	return 1; // BOGUS: always assume successful
}

void Deathmatch01::DeletePlayer(DPID id)
{
	if(!StopScript)
		LuaMission::DeletePlayer(id);
}

// Rebuilds pilot
EjectKillRetCodes Deathmatch01::RespawnPilot(Handle DeadObjectHandle, int Team)
{
	Vector Where; // Where they
	bool RespawnInVehicle = (GetRespawnInVehicle()) || (m_RabbitMode && (DeadObjectHandle == m_RabbitTargetHandle));

	if(m_RabbitMode && (DeadObjectHandle == m_RabbitTargetHandle))
	{
		m_ForbidRabbitTeam = m_RabbitTeam;
		m_RabbitTargetHandle = 0;
	}

	if(DMIsRaceSubtype[m_MissionType]) 
	{
		// Race-- spawn back at last spawnpoint they were at.
		int LastSpawnAt = m_NextRaceCheckpoint[Team]-1;
		if(LastSpawnAt > 0)
		{
			sprintf_s(TempODFName, "checkpoint%d", LastSpawnAt);
			GetPosition(GetHandle(TempODFName), Where);
		}
		else
		{
			Where = GetSpawnpoint(0);
		}
	}
	else if((!IsTeamplayOn()) || (Team<1))
	{
		Where = GetRandomSpawnpoint();
		// And randomize around the spawnpoint slightly so we'll
		// hopefully never spawn in two pilots in the same place
		Where = GetPositionNear(Where, AllyMinRadiusAway, AllyMaxRadiusAway);
	}
	else
	{
		// Place them back where originally created
		Where.x = m_TeamPos[3*Team+0];
		Where.y = m_TeamPos[3*Team+1];
		Where.z = m_TeamPos[3*Team+2];
		// And randomize around the spawnpoint slightly so we'll
		// hopefully never spawn in two pilots in the same place
		Where = GetPositionNear(Where, AllyMinRadiusAway, AllyMaxRadiusAway);
	}

	if((Team>0) && (Team<MAX_TEAMS))
		m_SpawnedAtTime[Team] = m_ElapsedGameTime; // Note when they spawned in.

	// Randomize starting position somewhat
	Where = GetPositionNear(Where, RespawnMinRadiusAway, RespawnMaxRadiusAway);

	Handle NewPerson;
	if(RespawnInVehicle) 
		NewPerson = BuildObject(GetNextVehicleODF(Team, true), Team, Where);
	else
	{
		if(!m_RespawnAtLowAltitude)
			Where.y += RespawnPilotHeight; // Bounce them in the air to prevent multi-kills

		// If the player picked a pilot as their "vehicle", respawn as that. -GBD
		const char *VehicleODF = GetNextVehicleODF(Team, true);
		if(_strnicmp(VehicleODF+1, "s", 1) == 0)
		{
			NewPerson = BuildObject(VehicleODF, Team, Where);
		}
		else
		{
			char Race = GetRaceOfTeam(Team);
			NewPerson = BuildObject(GetInitialPlayerPilotODF(Race), Team, Where);
		}
	}

	SetAsUser(NewPerson, Team);
	SetNoScrapFlagByHandle(NewPerson);

	AddPilotByHandle(NewPerson);
	SetRandomHeadingAngle(NewPerson);
	if(!RespawnInVehicle) 
		m_Flying[Team] = true; // build a craft when they land.

	// If on team 0 (dedicated server team), make this object gone from the world
	if(!Team)
		MakeInert(NewPerson);

	return DLLHandled; // Dead pilots get handled by DLL
}

EjectKillRetCodes Deathmatch01::DeadObject(int DeadObjectHandle, int KillersHandle, bool WasDeadPerson, bool WasDeadAI)
{
	char ODFName[64];
	GetObjInfo(DeadObjectHandle, Get_CFG, ODFName);
	Trace(("DeadObject(%08X...), odf %s\n", DeadObjectHandle, ODFName));

	// Rabbit mode, for non-rabbit players, special scoring. Normal
	// scoring for the rabbit below, as in other modes.
	bool KilledRabbit = false;
	bool UseRabbitScoring = false;
	bool Wasm_RabbitShooterHandle = (DeadObjectHandle == m_RabbitShooterHandle);
	if((m_RabbitMode) && (KillersHandle != m_RabbitTargetHandle))
	{
		UseRabbitScoring = true;
		KilledRabbit = (DeadObjectHandle == m_RabbitTargetHandle);
		if(KilledRabbit)
		{
			// Clear the objective set on them...
			SetObjectiveOff(m_RabbitTargetHandle);

			// See if the rabbit's last shooter is still alive. If so, 
			// make them the new target asap. Else, the next
			// ExecuteRabbit ought to pick it up.
			Handle RabbitH = KillersHandle;
			if(IsAlive(RabbitH)) 
			{
				SET_NEW_RABBIT(RabbitH); // Update for everyone
			}
			else
			{
				RabbitH = m_RabbitShooterHandle;
				if(IsAlive(RabbitH)) 
				{
					SET_NEW_RABBIT(RabbitH); // Update for everyone
				}
			}
		}
		else
		{
			Trace(("Killed Object wasn't rabbit(%08X)\n", m_RabbitTargetHandle));
		}
	} // Rabbit mode tweaks

	// Get team number of who got waxed.
	int DeadTeam = GetTeamNum(DeadObjectHandle);
	bool IsSpawnKill = false;
	// Flip scoring if this is a spawn kill.
	int SpawnKillMultiplier = 1;
	bool KillerIsAI = !IsPlayer(KillersHandle);

	// Give positive or negative points to killer, depending on
	// whether they killed enemy or ally

	// Spawnkill is a non-suicide, on a human by another human.
	if((DeadObjectHandle != KillersHandle) && 
		(DeadTeam > 0) && (DeadTeam < MAX_TEAMS) && (m_SpawnedAtTime[DeadTeam] > 0))
	{
		IsSpawnKill = (m_ElapsedGameTime - m_SpawnedAtTime[DeadTeam]) < m_MaxSpawnKillTime;
	}

	if((UseRabbitScoring) && (!KilledRabbit))
	{
		SpawnKillMultiplier = -1; // Force the score down!
		sprintf_s(TempMsgString, GetBZCCLocalizedString("mission", "%s killed the wrong target, %s\n"), 
			GetPlayerName(KillersHandle), GetPlayerName(DeadObjectHandle));
		AddToMessagesBox(TempMsgString);
	}
	else if((UseRabbitScoring) && (KilledRabbit))
	{
		SpawnKillMultiplier = -1; // Force the score down!
		sprintf_s(TempMsgString, GetBZCCLocalizedString("mission", "Rabbit kill by %s on %s\n"), 
			GetPlayerName(KillersHandle), GetPlayerName(DeadObjectHandle));
		AddToMessagesBox(TempMsgString);
	}
	else if(IsSpawnKill)
	{
		SpawnKillMultiplier = -1;
		sprintf_s(TempMsgString, GetBZCCLocalizedString("mission", "Spawn kill by %s on %s\n"), 
			GetPlayerName(KillersHandle), GetPlayerName(DeadObjectHandle));
		AddToMessagesBox(TempMsgString);
	}

	// Powerups and torpedos don't count for anything. -GBD
	char ObjClass[64];
	GetObjInfo(DeadObjectHandle, Get_GOClass, ObjClass);
	const bool isTorpedo = (_stricmp(ObjClass, "CLASS_TORPEDO") == 0);

	if(DeadTeam == 0)
		return DoEjectPilot; // Someone on neutral team always gets default behavior
	if(IsPowerup(DeadObjectHandle))
		return DoEjectPilot;
	if(isTorpedo)
		return DoEjectPilot;

	// Points only count in the plain deathmatch types. -GBD
	const bool ScoreCounts = (m_MissionType == DMSubtype_Normal) || (m_MissionType == DMSubtype_Normal2);

	if((DeadObjectHandle != KillersHandle) && (!IsAlly(DeadObjectHandle, KillersHandle)))
	{
		// Killed enemy...
		if((!WasDeadAI) || (KillForAIKill))
			AddKills(KillersHandle, 1*SpawnKillMultiplier); // Give them a kill

		if(((!WasDeadAI) || (PointsForAIKill)) && (ScoreCounts))
		{
			if(WasDeadPerson)
				AddScore(KillersHandle, ScoreForKillingPerson*SpawnKillMultiplier);
			else
				AddScore(KillersHandle, ScoreForKillingCraft*SpawnKillMultiplier);
		}
	}
	else
	{
		if((!WasDeadAI) || (KillForAIKill))
			AddKills(KillersHandle, -1*SpawnKillMultiplier); // Suicide or teamkill counts as -1 kill

		if((UseRabbitScoring) && (!KilledRabbit))
			SpawnKillMultiplier = 0; // no deaths count here...
		if(((!WasDeadAI) || (PointsForAIKill)) && (ScoreCounts))
		{
			if(WasDeadPerson)
				AddScore(KillersHandle, -ScoreForKillingPerson*SpawnKillMultiplier);
			else
				AddScore(KillersHandle, -ScoreForKillingCraft*SpawnKillMultiplier);
		}
	}

	if(!WasDeadAI)
	{
		if((UseRabbitScoring) && (!KilledRabbit))
			SpawnKillMultiplier = 0; // no deaths count here...

		// Give points to killee-- this always increases
		AddDeaths(DeadObjectHandle, 1*SpawnKillMultiplier);
		if(ScoreCounts)
		{
			if(WasDeadPerson)
				AddScore(DeadObjectHandle, ScoreForDyingAsPerson*SpawnKillMultiplier);
			else
				AddScore(DeadObjectHandle, ScoreForDyingAsCraft*SpawnKillMultiplier);
		}

		// Neener neener!
		if((KillerIsAI) && (m_NumAIUnits > 0))
			DoTaunt(TAUNTS_HumanShipDestroyed);
	}

	// Check to see if we have a m_KillLimit winner
	if((m_KillLimit) && (GetKills(KillersHandle) >= m_KillLimit))
	{
		NoteGameoverByKillLimit(KillersHandle);
		DoGameover(10.0f);
	}

	if(WasDeadAI)
	{
		int i;

		for(i = 0;i<m_NumAIUnits;i++)
		{
			if(DeadObjectHandle == m_AICraftHandles[i])
			{
				m_AICraftHandles[i] = 0;
				BuildBotCraft(i); // Respawn them asap.
				if(Wasm_RabbitShooterHandle)
				{
					m_RabbitShooterHandle = m_AICraftHandles[i];
				}
				break; // out of i loop
			}
		}

		for(i = 0;i<m_NumAnimals;i++)
		{
			if(DeadObjectHandle == m_AnimalHandles[i])
			{
				SetupAnimal(i); // Respawn them asap.
				return DLLHandled;
			}
		}

		return DLLHandled;
	}
	else 
	{
		// Not DeadAI, i.e. a human!

		// For a player-piloted craft, always respawn a new craft;
		// respawn pilot if needed as well.
		if((WasDeadPerson) || (m_RabbitMode && KilledRabbit))
		{
			return RespawnPilot(DeadObjectHandle, DeadTeam);
		}
		else
		{
			// Don't build anything for them until they land.
			m_Flying[DeadTeam] = true;
			return DoEjectPilot;
		}
	}
}

EjectKillRetCodes Deathmatch01::PlayerEjected(Handle DeadObjectHandle)
{
	if(!StopScript)
		LuaMission::PlayerEjected(DeadObjectHandle);

	bool WasDeadAI = !IsPlayer(DeadObjectHandle);

	int DeadTeam = GetTeamNum(DeadObjectHandle);
	if(DeadTeam == 0)
		return DLLHandled; // Invalid team. Do nothing

	// Flags saying if they can eject or not
	const bool CanEject = GetCanEject(DeadObjectHandle);
	if(CanEject)
		m_Flying[DeadTeam] = true; // They're flying; create craft when they land

	// Bailing out scores like a suicide; if they can't eject, it's an insta-kill as pilot. -GBD
	return DeadObject(DeadObjectHandle, DeadObjectHandle, !CanEject, WasDeadAI);
}

EjectKillRetCodes Deathmatch01::ObjectKilled(int DeadObjectHandle, int KillersHandle)
{
	if(!StopScript)
		LuaMission::ObjectKilled(DeadObjectHandle, KillersHandle);

	bool WasDeadAI = !IsPlayer(DeadObjectHandle);

	// We don't care about dead craft, only dead pilots, and also only
	// care about things in the lockstep world
	if(GetCurWorld() != 0)
	{
		return DoEjectPilot;
	}

	bool WasDeadPerson = IsPerson(DeadObjectHandle);
	if(GetRespawnInVehicle()) // CTF-- force a "kill" back to base
		WasDeadPerson = true;

	return DeadObject(DeadObjectHandle, KillersHandle, WasDeadPerson, WasDeadAI);
}

EjectKillRetCodes Deathmatch01::ObjectSniped(int DeadObjectHandle, int KillersHandle)
{
	if(!StopScript)
		LuaMission::ObjectSniped(DeadObjectHandle, KillersHandle);

	bool WasDeadAI = !IsPlayer(DeadObjectHandle);

	// We don't care about dead craft, only dead pilots, and also only
	// care about things in the lockstep world
	if(GetCurWorld() != 0)
	{
		return DoRespawnSafest;
	}

	// Dead person means we must always respawn a new person
	return DeadObject(DeadObjectHandle, KillersHandle, true, WasDeadAI);
}

// The objective text for the game type. -GBD
void Deathmatch01::CreateObjectives(void)
{
	ClearObjectives();
	const char *pObjective = "mpobjective_dm.otf";
	switch (m_MissionType)
	{
	case DMSubtype_KOH:
		pObjective = "mpobjective_dmkoth.otf";
		break;
	case DMSubtype_CTF:
		pObjective = "mpobjective_dmctf.otf";
		break;
	case DMSubtype_Loot:
		pObjective = "mpobjective_dmloot.otf";
		break;
	case DMSubtype_Race1:
	case DMSubtype_Race2:
		pObjective = "mpobjective_dmrace.otf";
		break;
	default:
		break;
	}
	AddObjective(pObjective, WHITE, -1.0f); // negative time means don't change display to show it
}

bool Deathmatch01::Load(bool missionSave)
{
	bool ret = LuaMission::Load(missionSave);

	SetAutoGroupUnits(false);
	EnableHighTPS(m_GameTPS);

	// Always do this to hook up clients with the taunt engine as well.
	InitTaunts(&m_ElapsedGameTime, &m_LastTauntPrintedAt, &m_GameTPS, "Bots");

	// We're a 1.3 DLL.
	WantBotKillMessages();

	if (missionSave)
	{
		int i;

		// init bools
		if((b_array) && (b_count))
			for (i = 0; i < b_count; i++)
				b_array[i] = false;

		// init floats
		if((f_array) && (f_count))
			for (i = 0; i < f_count; i++)
				f_array[i] = 0.0f;

		// init handles
		if((h_array) && (h_count))
			for (i = 0; i < h_count; i++)
				h_array[i] = 0;

		// init ints
		if((i_array) && (i_count))
			for (i = 0; i < i_count; i++)
				i_array[i] = 0;

		// Do this for everyone as well.
		CreateObjectives();
		return true;
	}

	// bools
	if (b_array != NULL)
		ret = ret && Read(b_array, b_count);

	// floats
	if (f_array != NULL)
		ret = ret && Read(f_array, f_count);

	// Handles
	if (h_array != NULL)
		ret = ret && Read(h_array, h_count);

	// ints
	if (i_array != NULL)
		ret = ret && Read(i_array, i_count);

	// Set this right after reading -- we might be on a client.  Safe
	// to call this multiple times on the server.
	SetGravity(static_cast<float>(m_Gravity) * 0.5f);

	PUPMgr::Load(missionSave);
	return ret;
}


bool Deathmatch01::PostLoad(bool missionSave)
{
	bool ret = LuaMission::PostLoad(missionSave);

	if (missionSave)
		return true;

	ConvertHandles(h_array, h_count);

	ret = ret && PUPMgr::PostLoad(missionSave);

	if(m_RabbitMode)
	{
		// Clear, 
		Handle OrigRabbit = m_RabbitTargetHandle;
		Handle NoRabbit = 0;
		SET_NEW_RABBIT(NoRabbit); // Clear.
		SET_NEW_RABBIT(OrigRabbit); // re-aim everyone
	}

	return ret;
}


bool Deathmatch01::Save(bool missionSave)
{
	bool ret = LuaMission::Save(missionSave);

	if (missionSave)
		return true;

	// bools
	if (b_array != NULL)
		ret = ret && Write(b_array, b_count);

	// floats
	if (f_array != NULL)
		ret = ret && Write(f_array, f_count);

	// Handles
	if (h_array != NULL)
		ret = ret && Write(h_array, h_count);

	// ints
	if (i_array != NULL)
		ret = ret && Write(i_array, i_count);

	ret = ret && PUPMgr::Save(missionSave);

	return ret;
}


DLLBase *BuildMission(void)
{
	return new Deathmatch01;
}
