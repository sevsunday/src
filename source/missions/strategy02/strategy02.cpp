// PROVENANCE: ancestor reference/ancestor-1.3/Missions/Strategy02/Strategy02.cpp @353698f (the 1.3 strategy skeleton: spawnpoints, team setup, game-time clock, recycler invulnerability, gameover logic, respawn, scoring) | decompile reference/decompiled/strategy02-attempt2/src/missions/strategy02/strategy02.cpp.decomp.c (ctor 72-113, dtor 115-117, Load 120-222, PostLoad 225-255, Save 258-315, GetNextRandomVehicleODF 318-320, UpdateObjectives 323-329, AddObject 332-648, DeleteObject 651-741, SetCPUAIPlan 744-776, GetInitialPlayerPilotODF 786-830, GetInitialRecyclerODF 834-844, GetSpawnpointForTeam 872-1006, IsRecyclerODF 1011-1027, BuildStartingVehicle 1033-1069, SetupTeam 1082-1284, SetupPlayer 1290-1630, Init 1634-1999, UpdateGameTime 2003-2074, ExecuteRecyInvulnerability 2078-2136, ExecuteCheckIfGameOver 2139-2426, Execute 2429-3019, AddPlayer 3022-3045, DeletePlayer 3048-3054, RespawnPilot 3058-3154, DeadObject 3158-3303, PlayerEjected 3306-3323, ObjectKilled 3326-3345, ObjectSniped 3349-3368, PreGetIn 3424-3455, BuildMission 3459-3461, ScavengerManagementCode 3465-3604, ExecuteST_Capture 3607-3859) + dumpbin of 4fc43263-4fc47036 for the register-passed arguments (InitTaunts, AddToDispatch, the spawnpoint arrays, the capture-goal float compares, the second SetVectorPosition) | gbd-lua-port original/lua/Lua-Stock-Missions_ea4173f/Upload/VSR/Missions/Scripts/Strategy.lua (names, comments, cross-check) | status: ported
#include "strategy02.h"
#include "startingvehicles.h"
#include "trnallies.h"
#include "dllutils.h"
#include "taunts.h"
#include "dispatchhelper.h"
#include "bzcscriptutils.h"
#include "mathutils.h"

#include <math.h>
#include <string.h>
#include <stdio.h>
#include <malloc.h>
#include <algorithm>

#define VEHICLE_SPACING_DISTANCE (20.0f)

// ---------- Scoring Values-- these are delta scores, added to current score --------
const int ScoreDecrementForSpawnKill = 500;
const int ScoreForWinning = 100;

// How long a "spawn" kill lasts, in tenth of second ticks. If the
// time since they were spawned to current is less than this, it's a
// spawn kill, and not counted. Todo - Make this an ivar for dm?
const int MaxSpawnKillTime = 15;

// -----------------------------------------------

// Max distance (in x,z dimensions) on a pilot respawn. Actual value
// used will vary with random numbers, and will be +/- this value
const float RespawnDistanceAwayXZRange = 32.f;
// Max distance (in y dimensions) on a pilot respawn. Actual value
// used will vary with random numbers, and will be [0..this value)
const float RespawnDistanceAwayYRange = 8.f;

// How high up to respawn a pilot
const float RespawnPilotHeight = 200.0f;

// How far allies will be from the commander's position
const float AllyMinRadiusAway = 30.0f;
const float AllyMaxRadiusAway = 60.0f;

// How long (in seconds) from noticing gameover, to the actual kicking
// out back to the shell.
const float endDelta = 10.0f;

// Tuning distances for GetSpawnpointForTeam(). These are the defaults;
// the map's .trn [DLL] block can override them (see Init()).

// Friendly spawnpoint: Max distance away for ally
const float FRIENDLY_SPAWNPOINT_MAX_ALLY = 100.f;
// Friendly spawnpoint: Min distance away for enemy
const float FRIENDLY_SPAWNPOINT_MIN_ENEMY = 400.f;

// Random spawnpoint: min distance away for enemy
const float RANDOM_SPAWNPOINT_MIN_ENEMY = 450.f;

// Max # of AI teams in MPI. Used to size color scratch arrays.
const int MAX_AI_TEAMS = 5;

// Temporary strings for blasting stuff into for output. NOT to be
// used to store anything you care about.
static char TempMsgString[1024];

// Temporary name for blasting ODF names into while building
// them. *not* saved, do *not* count on its contents being valid
// next time the dll is called.
static char TempODFName[64];

// Base name of the AIP files for the CPU teams (svar3, "VSR_" default).
static char CustomAIPNameBase[256];

// Special Handle for Audio. -GBD
static DLLAudioHandle EasterEggSound = 0;

// Don't do much in constructor; do in Init()
Strategy02::Strategy02(void)
{
	m_GameTPS = 20;
	EnableHighTPS(m_GameTPS);
	AllowRandomTracks(true); // If the user wants random music, we're fine with that.

	b_count = &b_last - &b_first - 1;
	b_array = &b_first + 1;

	f_count = &f_last - &f_first - 1;
	f_array = &f_first + 1;

	h_array = &h_first + 1;
	h_count = &h_last - &h_first - 1;

	i_count = &i_last - &i_first - 1;
	i_array = &i_first + 1;
	TRNAllies::SetupTRNAllies(GetMapTRNFilename());

	// Zero things out first off.
	if(i_array)
		memset(i_array, 0, i_count*sizeof(int));
	if(f_array)
		memset(f_array, 0, f_count*sizeof(float));
	if(h_array)
		memset(h_array, 0, h_count*sizeof(Handle));
	if(b_array)
		memset(b_array, 0, b_count*sizeof(bool));

	memset(PlayerShipODF, 0, sizeof(PlayerShipODF));
	memset(SavedPilotODF, 0, sizeof(SavedPilotODF));
	memset(PlayerSavedName, 0, sizeof(PlayerSavedName));
	memset(PlayerShipWeapons, 0, sizeof(PlayerShipWeapons));
	memset(PlayerPilotWeapons, 0, sizeof(PlayerPilotWeapons));
	memset(PlayerPilotLocalAmmo, 0, sizeof(PlayerPilotLocalAmmo));
	memset(PlayerMatrix, 0, sizeof(PlayerMatrix));
	memset(PlayerVelocity, 0, sizeof(PlayerVelocity));
	memset(PlayerOmega, 0, sizeof(PlayerOmega));
	memset(MapAmbientSound, 0, sizeof(MapAmbientSound));
	memset(EmptyShipODF, 0, sizeof(EmptyShipODF));
}

Strategy02::~Strategy02()
{
	CleanupTaunts();
}

bool Strategy02::Load(bool missionSave)
{
	bool ret = LuaMission::Load(missionSave);

	EnableHighTPS(m_GameTPS);
	SetAutoGroupUnits(false);

	// Make sure we always call this
	if (!missionSave)
		StartingVehicleManager::Load(missionSave);

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

		return true;
	}

	// Load for FFA Thug helpers. -GBD
	int size;
	Read(&size, 1);
	ThugScavengerList.resize(size);
	if(size)
		Read(&ThugScavengerList.front(), sizeof(ThugScavengerClass)*size);

	Read(&size, 1);
	ThugPilotList.resize(size);
	if(size)
		Read(&ThugPilotList.front(), sizeof(ThugPilotClass)*size);

	Read(&size, 1);
	EmptyShipList.resize(size);
	if(size)
		Read(&EmptyShipList.front(), sizeof(EmptyShipClass)*size);

	// bools
	if (b_array != NULL)
		Read(b_array, b_count);

	// floats
	if (f_array != NULL)
		Read(f_array, f_count);

	// Handles
	if (h_array != NULL)
		Read(h_array, h_count);

	// ints
	if (i_array != NULL)
		Read(i_array, i_count);

	// Saved player data for the restore-players option. -GBD
	ret = ret && Read(PlayerShipODF, sizeof(PlayerShipODF));
	ret = ret && Read(SavedPilotODF, sizeof(SavedPilotODF));
	ret = ret && Read(PlayerSavedName, sizeof(PlayerSavedName));
	ret = ret && Read(PlayerShipWeapons, sizeof(PlayerShipWeapons));
	ret = ret && Read(PlayerPilotWeapons, sizeof(PlayerPilotWeapons));
	ret = ret && Read(PlayerPilotLocalAmmo, sizeof(PlayerPilotLocalAmmo));
	ret = ret && Read(PlayerMatrix, sizeof(PlayerMatrix));
	ret = ret && Read(PlayerVelocity, sizeof(PlayerVelocity));
	ret = ret && Read(PlayerOmega, sizeof(PlayerOmega));
	ret = ret && Read(MapAmbientSound, sizeof(MapAmbientSound));
	ret = ret && Read(EmptyShipODF, sizeof(EmptyShipODF));

	if(m_IsMPI)
		InitTaunts(&m_ElapsedGameTime, &m_LastTauntPrintedAt, &m_GameTPS);

	// Start playing the musics.
	if((m_DidInit) && (DoesFileExist(MapAmbientSound)))
	{
		StopAudio(EasterEggSound);
		EasterEggSound = StartAudio2D(MapAmbientSound, -1.0f, 0.0f, 44100.0f, true, false);
	}

	UpdateObjectives();

	return ret;
}

bool Strategy02::PostLoad(bool missionSave)
{
	bool ret = LuaMission::PostLoad(missionSave);

	if (missionSave)
		return true;

	// PostLoad for FFA Thug helpers. -GBD
	for (std::vector<ThugScavengerClass>::iterator iter = ThugScavengerList.begin(); iter != ThugScavengerList.end(); ++iter)
	{
		ThugScavengerClass &sao = *iter;
		ConvertHandles(&sao.ThugScavengerObject, 1);
	}
	for (std::vector<ThugPilotClass>::iterator iter = ThugPilotList.begin(); iter != ThugPilotList.end(); ++iter)
	{
		ThugPilotClass &sao = *iter;
		ConvertHandles(&sao.ThugPilotObject, 1);
	}
	for (std::vector<EmptyShipClass>::iterator iter = EmptyShipList.begin(); iter != EmptyShipList.end(); ++iter)
	{
		EmptyShipClass &sao = *iter;
		ConvertHandles(&sao.EmptyShipObject, 1);
	}

	ConvertHandles(h_array, h_count);

	return ret;
}

bool Strategy02::Save(bool missionSave)
{
	bool ret = LuaMission::Save(missionSave);

	if (missionSave)
		return true;

	// Make sure we always call this
	StartingVehicleManager::Save(missionSave);

	// Save for FFA Thug helpers. -GBD
	int size = int(ThugScavengerList.size());
	Write(&size, 1);
	if(size)
		Write(&ThugScavengerList.front(), sizeof(ThugScavengerClass)*size);

	size = int(ThugPilotList.size());
	Write(&size, 1);
	if(size)
		Write(&ThugPilotList.front(), sizeof(ThugPilotClass)*size);

	size = int(EmptyShipList.size());
	Write(&size, 1);
	if(size)
		Write(&EmptyShipList.front(), sizeof(EmptyShipClass)*size);

	// bools
	if (b_array != NULL)
		Write(b_array, b_count);

	// floats
	if (f_array != NULL)
		Write(f_array, f_count);

	// Handles
	if (h_array != NULL)
		Write(h_array, h_count);

	// ints
	if (i_array != NULL)
		Write(i_array, i_count);

	// Saved player data for the restore-players option. -GBD
	ret = ret && Write(PlayerShipODF, sizeof(PlayerShipODF));
	ret = ret && Write(SavedPilotODF, sizeof(SavedPilotODF));
	ret = ret && Write(PlayerSavedName, sizeof(PlayerSavedName));
	ret = ret && Write(PlayerShipWeapons, sizeof(PlayerShipWeapons));
	ret = ret && Write(PlayerPilotWeapons, sizeof(PlayerPilotWeapons));
	ret = ret && Write(PlayerPilotLocalAmmo, sizeof(PlayerPilotLocalAmmo));
	ret = ret && Write(PlayerMatrix, sizeof(PlayerMatrix));
	ret = ret && Write(PlayerVelocity, sizeof(PlayerVelocity));
	ret = ret && Write(PlayerOmega, sizeof(PlayerOmega));
	ret = ret && Write(MapAmbientSound, sizeof(MapAmbientSound));
	ret = ret && Write(EmptyShipODF, sizeof(EmptyShipODF));

	return ret;
}

const char *Strategy02::GetNextRandomVehicleODF(int Team)
{
	return GetPlayerODF(Team);
}

void Strategy02::UpdateObjectives(void)
{
	ClearObjectives();
	if(m_GameType == 4) // Capture mode.
		AddObjective("mpobjective_stcap.otf", WHITE, -1.0f); // negative time means don't change display to show it
	else
		AddObjective("mpobjective_st.otf", WHITE, -1.0f);
}

void Strategy02::AddObject(Handle h)
{
	if(!StopScript)
		LuaMission::AddObject(h);

	char ODFName[MAX_ODF_LENGTH];
	GetObjInfo(h, Get_CFG, ODFName);

	// Cutoff :# at the end.
	if(!DoesODFExist(ODFName))
	{
		char *colon = strchr(ODFName, ':');
		strncpy_s(ODFName, ODFName, colon - ODFName);
	}

	// Changed NM 10/19/01 - all AI is at skill 3 now by default.
	int UseTurretSkill=m_TurretAISkill;
	int UseNonTurretSkill=m_NonTurretAISkill;

	// Note: this is the proper way to determine if a handle points to a
	// turret. NM 1/29/05
	char ObjClass[MAX_ODF_LENGTH];
	GetObjInfo(h, Get_GOClass, ObjClass);
	bool isTurret = (_stricmp(ObjClass, "CLASS_TURRETTANK") == 0);

	// Start of game, remove scrap flag. -GBD
	if((m_ElapsedGameTime == 0) && (GetVarItemInt("network.session.ivar117")) && (_stricmp(ObjClass, "CLASS_SCRAP") == 0))
	{
		RemoveObject(h);
		return; // done here.
	}

	int Team = GetTeamNum(h);

	// If this is MPI, and not a human team. -GBD
	if((m_IsMPI) && (Team > 10))
	{
		AddToDispatch(h, 15.0f, false, 0, false); // Tie into DispatchHelper. -GBD

		UseTurretSkill = m_CPUTurretAISkill;
		UseNonTurretSkill = m_CPUNonTurretAISkill;
	}
	else
	{
		// Remove NAV cameras outside map bounds.
		if(_stricmp(ObjClass, "CLASS_NAVBEACON") == 0)
		{
			Vector Pos = GetPosition(h);
			const MapInfo &Map = GetMapInfo();
			if((Pos.x > Map.MaxWidth) ||
				(Pos.x < Map.MinWidth) ||
				(Pos.z > Map.MaxDepth) ||
				(Pos.z < Map.MinDepth))
			{
				RemoveObject(h);
			}
		}
	}

	// See if this is a turret, 
	if(isTurret)
		SetSkill(h, UseTurretSkill);
	else // Not a turret. Use regular skill level
		SetSkill(h, UseNonTurretSkill);

	// Count all spawnpoints on the map. -GBD
	if((m_ElapsedGameTime < 1) && (_stricmp(ObjClass, "CLASS_SPAWNBUOY") == 0))
		m_NumSpawnPoints++;

	// Also see if this is a new recycler vehicle (e.g. user upgraded
	// recycler building to vehicle)
	bool IsRecyVehicle = (_stricmp(ObjClass, "CLASS_RECYCLERVEHICLE") == 0) || (_stricmp(ObjClass, "CLASS_RECYCLERVEHICLEH") == 0) || (_stricmp(ObjClass, "CLASS_RECYCLER") == 0);
	if(IsRecyVehicle)
	{
		// If we're not tracking a recycler vehicle for this team right
		// now, store it.
		if((m_RecyclerHandles[Team] == 0) || (!IsAround(m_RecyclerHandles[Team])))
			m_RecyclerHandles[Team] = h;

		// Now crack her open, check the Empty Vehicle ODF for empty invulnerability. -GBD
		if((BuildEmpty[Team] == 0) && (_stricmp(ObjClass, "CLASS_RECYCLER") == 0))
		{
			GetODFInt(h, "FactoryClass", "buildEmptyItem", &BuildEmpty[Team], 0);
			if(BuildEmpty[Team] > 0)
			{
				char DesiredValue[MAX_ODF_LENGTH] = {0};
				sprintf_s(DesiredValue, "BuildItem%d", BuildEmpty[Team]);
				GetODFString(h, "FactoryClass", DesiredValue, MAX_ODF_LENGTH, EmptyShipODF[Team], NULL);
			}
		}
	}

	// Special things for FFA Mode with Thugs. -GBD
	bool AddToList = true;
	if((!IsTeamplayOn()) || (m_IsMPI))
	{
		// Scavenger code: added to handle thug scavs in FFA Alliance mode. -GBD
		if((_stricmp(ObjClass, "CLASS_SCAVENGER") == 0) || (_stricmp(ObjClass, "CLASS_SCAVENGERH") == 0))
		{
			for (std::vector<ThugScavengerClass>::iterator iter = ThugScavengerList.begin(); iter != ThugScavengerList.end(); ++iter)
			{
				if(iter->ThugScavengerObject == h)
				{
					AddToList = false;
					break;
				}
			}
			if(AddToList)
			{
				ThugScavengerList.resize(ThugScavengerList.size()+1);
				ThugScavengerClass &sao = ThugScavengerList[ThugScavengerList.size()-1]; // No temporary being created, *much* faster

				sao.ThugScavengerObject = h;
				sao.ScavengerTeam = Team;
			}
		}
		// Thug code, adding thugs to be thugified. (Thug pilots to switch to Commander's team after 15 seconds)
		else if((_stricmp(ObjClass, "CLASS_PERSON") == 0) && (!IsPlayer(h)))
		{
			for (std::vector<ThugPilotClass>::iterator iter = ThugPilotList.begin(); iter != ThugPilotList.end(); ++iter)
			{
				if(iter->ThugPilotObject == h)
				{
					AddToList = false;
					break;
				}
			}
			if(AddToList)
			{
				ThugPilotList.resize(ThugPilotList.size()+1);
				ThugPilotClass &sao = ThugPilotList[ThugPilotList.size()-1]; // No temporary being created, *much* faster
				memset(&sao, 0, sizeof(ThugPilotClass)); // Zero things out at start.

				sao.ThugPilotObject = h;
				sao.SwitchTickTimer = (15*m_GameTPS); // Set Timer, 15 seconds.
			}
		}
	}

	// VSR Empty Ship Invulnerability code. -GBD
	if((m_PilotInvunerability > 0) && (IsAround(m_RecyclerHandles[Team])) && (BuildEmpty[Team] > 0) &&
		(_stricmp(ODFName, EmptyShipODF[Team]) == 0)) // Checking ODFName Match from earlier GetObjInfo
	{
		AddToList = true;
		for (std::vector<EmptyShipClass>::iterator iter = EmptyShipList.begin(); iter != EmptyShipList.end(); ++iter)
		{
			if(iter->EmptyShipObject == h)
			{
				AddToList = false;
				break;
			}
		}
		if(AddToList)
		{
			EmptyShipList.resize(EmptyShipList.size()+1);
			EmptyShipClass &sao = EmptyShipList[EmptyShipList.size()-1]; // No temporary being created, *much* faster
			memset(&sao, 0, sizeof(EmptyShipClass)); // Zero things out at start.

			sao.EmptyShipObject = h;
			sao.InvulnerabilityTime = m_PilotInvunerability;
			sao.SavedHealth = GetMaxHealth(h);
			SetMaxHealth(h, 0);
		}
	}

	// Default morphtank behavior. -GBD
	if((m_MorphTankAutoDeployType > 0) && (_stricmp(ObjClass, "CLASS_MORPHTANK") == 0))
	{
		AddToList = true;
		for (std::vector<MorphTankClass>::iterator iter = MorphTankList.begin(); iter != MorphTankList.end(); ++iter)
		{
			if(iter->MorphTankObject == h)
			{
				AddToList = false;
				break;
			}
		}
		if(AddToList)
		{
			MorphTankList.resize(MorphTankList.size()+1);
			MorphTankClass &sao = MorphTankList[MorphTankList.size()-1]; // No temporary being created, *much* faster
			memset(&sao, 0, sizeof(MorphTankClass)); // Zero things out at start.

			sao.MorphTankObject = h;
		}
	}

	// Find which baseSlot# this is.
	int TeamSlot = GetCategoryTypeOverride(h);
	if(TeamSlot == -1)
		TeamSlot = GetCategoryType(h);

	// Commbunker teamslot re-assignment. -GBD
	if((TeamSlot > 0) && (TeamSlot < 10) && // Base Slot.
		((_stricmp(ObjClass, "CLASS_COMMBUKNER") == 0) || (_stricmp(ObjClass, "CLASS_COMMTOWER") == 0))) // sic: CLASS_COMMBUKNER
	{
		AddToList = true;
		for (std::vector<CommBunkerClass>::iterator iter = CommBunkerList.begin(); iter != CommBunkerList.end(); ++iter)
		{
			if(iter->CommBunkerObject == h)
			{
				AddToList = false;
				break;
			}
		}
		if(AddToList)
		{
			CommBunkerList.resize(CommBunkerList.size()+1);
			CommBunkerClass &sao = CommBunkerList[CommBunkerList.size()-1]; // No temporary being created, *much* faster

			sao.CommBunkerObject = h;
			sao.CommBunkerBaseSlot = TeamSlot;
		}
	}
}

void Strategy02::DeleteObject(Handle h)
{
	if(!StopScript)
		LuaMission::DeleteObject(h);

	int Team = GetTeamNum(h);

	// Dead player's ship doesn't leave scrap when we're restoring players. -GBD
	if((m_RestorePlayers) && (IsPlayer(h)) && (GetPlayerHandle(Team) == 0))
		SetNoScrapFlagByHandle(h);

	// If this was a commbunker that was remote activated...
	int PrevSlot = 0;
	for (std::vector<CommBunkerClass>::iterator iter = CommBunkerList.begin(); iter != CommBunkerList.end(); ++iter)
	{
		if(h == iter->CommBunkerObject)
		{
			PrevSlot = iter->CommBunkerBaseSlot;
			break; // found it.
		}
	}
	// Find a potential replacement slot.
	for (std::vector<CommBunkerClass>::iterator iter = CommBunkerList.begin(); iter != CommBunkerList.end(); ++iter)
	{
		if((h != iter->CommBunkerObject) && (iter->CommBunkerBaseSlot == PrevSlot))
		{
			ResetTeamSlot(iter->CommBunkerObject);
			break; // found it.
		}
	}
}

// Picks the AIP for a CPU team: <base><race><NameOverride>_<0..2>.aip, falling back to _0.
void Strategy02::SetCPUAIPlan(int Team, int NameOverride)
{
	if(!CheckedSVar3)
	{
		CheckedSVar3 = true;
		const char* pContents = DLLUtils::GetCheckedNetworkSvar(3, NETLIST_AIPs);
		if((pContents == NULL) || (pContents[0] == '\0'))
			pContents = "VSR_"; // Use the default naming scheme if not specified.
		strcpy_s(CustomAIPNameBase, pContents);
	}

	char AIPFile[256] = {0};
	int Random = int(floor(GetRandomFloat(3.0f)));
	if(Random > 2)
		Random = 2;
	sprintf_s(AIPFile, "%s%c%d_%d.aip", CustomAIPNameBase, GetRace(m_RecyclerHandles[Team]), NameOverride, Random);

	if(!DoesFileExist(AIPFile))
		sprintf_s(AIPFile, "%s%c%d_0.aip", CustomAIPNameBase, GetRace(m_RecyclerHandles[Team]), NameOverride);

	SetAIPFile(AIPFile, Team);

	if(m_SetFirstAIP)
		DoTaunt(TAUNTS_Random);

	m_SetFirstAIP = true;
}

// Gets the initial player vehicle as selected in the shell
const char *Strategy02::GetInitialPlayerVehicleODF(int Team)
{
	return GetPlayerODF(Team);
}

// Given a race identifier, get the pilot back (used during a respawn).
// The recycler's ODF (or its classlabel parent) may name the pilots.
const char *Strategy02::GetInitialPlayerPilotODF(char Race, int Team, bool IsRespawning)
{
	if(Team > 0)
	{
		if(IsTeamplayOn())
			Team = GetCommanderTeam(Team);

		char TempODF[MAX_ODF_LENGTH] = {0};
		char TempODF2[MAX_ODF_LENGTH] = {0};
		GetObjInfo(m_RecyclerHandles[Team], Get_ODF, TempODF);

		if((OpenODF2(TempODF)) && (GetODFString(TempODF, "GameObjectClass", "classlabel", MAX_ODF_LENGTH, TempODF2)))
		{
			CombineStrings(TempODF2, TempODF2, ".odf"); // Add .odf to the end.
			OpenODF2(TempODF2);
		}

		// 0 = Start w/ sniper, No respawn, 
		// 1 = Start w/ sniper, Respawn w/ sniper, 
		// 2 = Start No sniper, No respawn.
		const char* KeyName = "PilotRespawnWithOutSniper";
		if(((!IsRespawning) && (m_RespawnWithSniper < 2)) || ((IsRespawning) && (m_RespawnWithSniper == 1)))
			KeyName = "PilotRespawnWithSniper";

		GetODFString(TempODF, TempODF2, "GameObjectClass", KeyName, MAX_ODF_LENGTH, TempODFName);
	}

	if((!DoesODFExist(TempODFName)) || (Team == 0))
	{
		if(((!IsRespawning) && (m_RespawnWithSniper < 2)) || ((IsRespawning) && (m_RespawnWithSniper == 1)))
			strcpy_s(TempODFName, "ispilo"); // With sniper.
		else
			strcpy_s(TempODFName, "isuser_m"); // Note-- this is the sniper-less variant for a respawn
		TempODFName[0]=Race;

		if(!DoesODFExist(TempODFName))
		{
			sprintf_s(TempMsgString, "ERROR: '%s' does not exist. Giving you pilot DEFAULT ISDF! FIX IT!", TempODFName);
			PrintConsoleMessage(TempMsgString);

			TempODFName[0] = 'i';
		}
	}
	return TempODFName;
}

// Given a race identifier, get the recycler ODF back
const char *Strategy02::GetInitialRecyclerODF(char Race)
{
	const char* pContents = DLLUtils::GetCheckedNetworkSvar(5, NETLIST_Recyclers);
	if((pContents != NULL) && (pContents[0] != '\0'))
	{
		strcpy_s(TempODFName, pContents);
	}
	else
	{
		strcpy_s(TempODFName, "ivrecy_m");
	}
	TempODFName[0]=Race;
	return TempODFName;
}

// Given a race identifier, get the scavenger ODF back
const char *Strategy02::GetInitialScavengerODF(char Race)
{
	strcpy_s(TempODFName, "ivscav");
	TempODFName[0]=Race;
	return TempODFName;
}

// Given a race identifier, get the constructor ODF back
const char *Strategy02::GetInitialConstructorODF(char Race)
{
	strcpy_s(TempODFName, "ivcons");
	TempODFName[0]=Race;
	return TempODFName;
}

// Given a race identifier, get the healer (service truck) ODF back
const char *Strategy02::GetInitialHealerODF(char Race)
{
	strcpy_s(TempODFName, "ivserv");
	TempODFName[0]=Race;
	return TempODFName;
}

// Helper function for SetupTeam(), returns an appropriate spawnpoint.
Vector Strategy02::GetSpawnpointForTeam(int Team)
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

	// FFA pass: query the spawnpoints again as the alliance group, and
	// keep the ones that are far from everybody. -GBD
	if(!IsTeamplayOn())
	{
		SpawnpointInfo* pAllySpawnPointInfo;
		GetAllSpawnpoints(pAllySpawnPointInfo, m_AllyTeams[Team]);

		indexCount = 0;
		for(i=0; i<count; ++i)
		{
			if((pAllySpawnPointInfo[i].m_DistanceToClosestSameTeam >= m_FRIENDLY_SPAWNPOINT_MIN_ENEMY) &&
			   (pSpawnPointInfo[i].m_DistanceToClosestAlly >= m_FRIENDLY_SPAWNPOINT_MIN_ENEMY) &&
			   (pSpawnPointInfo[i].m_DistanceToClosestEnemy >= m_FRIENDLY_SPAWNPOINT_MIN_ENEMY))
			{
				pIndices[indexCount++] = i;
			}
		}

		if(indexCount > 0)
		{
			size_t index = 0;
			do
			{
				index = static_cast<size_t>(GetRandomFloat(static_cast<float>(indexCount)));
			} while(index >= indexCount);
			return pSpawnPointInfo[pIndices[index]].m_Position;
		}
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

// Sees if this is a m_HumanRecycler vehicle ODF, and returns the race
// ('a'..'z') if true. Returns 0 if not a m_HumanRecycler.
int IsRecyclerODF(Handle h)
{
	if(!h)
		return 0;

	char ObjClass[MAX_ODF_LENGTH];
	GetObjInfo(h, Get_GOClass, ObjClass);
	if((_stricmp(ObjClass, "CLASS_RECYCLERVEHICLE") == 0) || (_stricmp(ObjClass, "CLASS_RECYCLER") == 0) || (_stricmp(ObjClass, "CLASS_RECYCLERVEHICLEH") == 0))
	{
		char ODFName[MAX_ODF_LENGTH];
		GetObjInfo(h, Get_CFG, ODFName);
		return ODFName[0];
	}

	// fallback: not a m_HumanRecycler.
	return 0;
}

// Builds a starting vehicle on the specified team with either ODF1
// (preferred, if found) or ODF2 as its name, modified by the
// race. Sets group, if specified. Returns the handle
Handle Strategy02::BuildStartingVehicle(int aTeam, int aRace, char* ODF1, char* ODF2, char* Where, int aGrp)
{
	char TempODF[MAX_ODF_LENGTH];
	strcpy_s(TempODF, ODF1);
	TempODF[0] = (char)aRace;
	if(!DoesODFExist(TempODF))
	{
		strcpy_s(TempODF, ODF2);
		TempODF[0] = (char)aRace;
	}

	Handle h = BuildObject(TempODF, aTeam, Where);
	if(aGrp >= 0)
		SetGroup(h, aGrp);
	return h;
}

// Vector variant of the above.
Handle Strategy02::BuildStartingVehicle(int aTeam, int aRace, char* ODF1, char* ODF2, Vector Where, int aGrp)
{
	char TempODF[MAX_ODF_LENGTH];
	strcpy_s(TempODF, ODF1);
	TempODF[0] = (char)aRace;
	if(!DoesODFExist(TempODF))
	{
		strcpy_s(TempODF, ODF2);
		TempODF[0] = (char)aRace;
	}

	Handle h = BuildObject(TempODF, aTeam, Where);
	if(aGrp >= 0)
		SetGroup(h, aGrp);
	return h;
}

// Sets up the side's commander's extra vehicles, such a recycler or
// more.  Does *not* create the player vehicle for them, 
// however. [That's to be done in SetupPlayer.]  Safe to be called
// multiple times for each player on that team
//
// If Teamplay is off, this function is called once per player.
//
// If Teamplay is on, this function is called only on the
// _defensive_ team number for an alliance. 
void Strategy02::SetupTeam(int Team)
{
	if((Team<1) || (Team>=MAX_TEAMS))
		return;
	if(m_TeamIsSetUp[Team])
		return;

	if((Team == 1) && (m_IsMPI))
		DoTaunt(TAUNTS_GameStart);

	char TeamRace=GetRaceOfTeam(Team);
	if(IsTeamplayOn())
		SetMPTeamRace(WhichTeamGroup(Team), TeamRace); // Lock this down to prevent changes.

	Vector spawnpointPosition;
	spawnpointPosition.x = spawnpointPosition.y = spawnpointPosition.z = 0.f;

	if(m_IsMPI) // We Are MPI! Spawn on the "Player_#" path if the map has one. -GBD
	{
		char PathName[MAX_ODF_LENGTH] = {0};
		sprintf_s(PathName, "Player_%d", m_PlayersSpawned + 1);

		size_t bufSize = 0;
		GetPathPoints(PathName, bufSize, NULL);
		float* pData = reinterpret_cast<float*>(_alloca(2 * bufSize * sizeof(float)));
		if(GetPathPoints(PathName, bufSize, pData))
			spawnpointPosition = Vector(pData[0], TerrainFindFloor(pData[0], pData[1]), pData[1]);

		m_PlayersSpawned++;
	}

	// If this is a null vector, use old method.
	if((!m_IsMPI) || (Dot_Product(spawnpointPosition, spawnpointPosition) < 0.1f))
		spawnpointPosition = GetSpawnpointForTeam(Team);

	// Store position we created them at for later
	m_TeamPos[3*Team+0] = spawnpointPosition.x;
	m_TeamPos[3*Team+2] = spawnpointPosition.z;
	m_TeamPos[3*Team+1] = spawnpointPosition.y;

	// Build recycler some distance away, if it's not preplaced on the map.
	if(GetObjectByTeamSlot(Team, DLL_TEAM_SLOT_RECYCLER) == 0)
	{
		int VehicleH;
		if(!m_SpawnFacingCenter)
		{
			spawnpointPosition = GetPositionNear(spawnpointPosition, VEHICLE_SPACING_DISTANCE, 2*VEHICLE_SPACING_DISTANCE);
			VehicleH = BuildObject(GetInitialRecyclerODF(TeamRace), Team, spawnpointPosition);
			SetRandomHeadingAngle(VehicleH);
		}
		else // Spawn Directly on Spawn, facing Center. -GBD
		{
			Vector Center = GetCenterOfMap();
			Vector Front = GetFacingDrection2D(spawnpointPosition, Center);
			Matrix Pos = Build_Directinal_Matrix(spawnpointPosition, Front);
			VehicleH = BuildObject(GetInitialRecyclerODF(TeamRace), Team, Pos);
		}
		m_RecyclerHandles[Team] = VehicleH;
		SetGroup(VehicleH, 0);
	}

	// Build all optional vehicles for this team.
	spawnpointPosition.x = m_TeamPos[3*Team+0]; // restore default after we modified this for recy above
	spawnpointPosition.y = m_TeamPos[3*Team+1];
	spawnpointPosition.z = m_TeamPos[3*Team+2];

	// Look for the recycler's starting variant, else look for an _ in
	// there, and copy everything after it into the RecyVariant tag. -GBD
	char TempODF[MAX_ODF_LENGTH] = {0};
	char TempODF2[MAX_ODF_LENGTH] = {0};
	char VariantName[MAX_ODF_LENGTH] = {0};
	strcpy_s(TempODF, GetInitialRecyclerODF(TeamRace));
	CombineStrings(TempODF, TempODF, ".odf"); // Add .odf to the end.
	OpenODF2(TempODF);
	if(GetODFString(TempODF, "GameObjectClass", "classlabel", MAX_ODF_LENGTH, TempODF2)) // Grab the classlabel, if present.
	{
		CombineStrings(TempODF2, TempODF2, ".odf"); // Add .odf to the end.
		OpenODF2(TempODF2);
	}
	if(!GetODFString(TempODF, TempODF2, "GameObjectClass", "startingVariant", MAX_ODF_LENGTH, VariantName))
	{
		const char *pUnderscore = strchr(GetInitialRecyclerODF(TeamRace), '_');
		if(pUnderscore)
		{
			pUnderscore++;
			const char *pUnderscore2 = strchr(pUnderscore, '_');
			if(pUnderscore2) // 2 underscores, take what's after the second.
				pUnderscore = pUnderscore2 + 1;
			strcpy_s(VariantName, pUnderscore);
		}
	}

	// Drop skill level while we build things.
	m_CreatingStartingVehicles=true;
	StartingVehicleManager::CreateVehicles(Team, TeamRace, VariantName, m_StartingVehiclesMask, spawnpointPosition);
	m_CreatingStartingVehicles=false;

	SetScrap(Team, 40);

	// Modified spawn code to handle FFA Alliances with thugs. -GBD
	if(IsTeamplayOn()) 
	{
		for(int i=GetFirstAlliedTeam(Team); i <= GetLastAlliedTeam(Team); i++) 
		{
			// Make thier Pilots match the VSR ones, if present. -GBD
			SetPilotClass(GetPlayerHandle(i), GetInitialPlayerPilotODF(TeamRace, i, false));

			if(i!=Team)
			{
				if(!m_SpawnFacingCenter) // Old Method.
				{
					// Get a new position near the team's central position
					const Vector pos = GetPositionNear(spawnpointPosition, AllyMinRadiusAway, AllyMaxRadiusAway);

					// In teamplay, store where offense players were created for respawns later
					m_TeamPos[3*i+0] = pos.x;
					m_TeamPos[3*i+1] = pos.y;
					m_TeamPos[3*i+2] = pos.z;
				}
				else // Use directly on Spawns.
				{
					m_TeamPos[3*i+0] = spawnpointPosition.x;
					m_TeamPos[3*i+1] = spawnpointPosition.y;
					m_TeamPos[3*i+2] = spawnpointPosition.z;
				}
			} // Loop over allies not the commander
		}
	}
	else // FFA Mode. Setup based on allies position. -GBD
	{
		for(int i = 1; i<MAX_TEAMS; i++)
		{
			if((i!=Team) && (m_AllyTeams[Team] == m_AllyTeams[i]) && (m_ThugFlag[i]) && (!m_ThugFlag[Team]))
			{
				if(!m_SpawnFacingCenter) // Old method.
				{
					Vector NewPosition = GetPositionNear(spawnpointPosition, AllyMinRadiusAway, AllyMaxRadiusAway);

					m_TeamPos[3*i+0]=NewPosition.x;
					m_TeamPos[3*i+1]=NewPosition.y;
					m_TeamPos[3*i+2]=NewPosition.z;
				}
				else // Use directly on Spawns.
				{
					m_TeamPos[3*i+0]=spawnpointPosition.x;
					m_TeamPos[3*i+1]=spawnpointPosition.y;
					m_TeamPos[3*i+2]=spawnpointPosition.z;
				}
			}
		}
	}

	if(Team == GetLocalPlayerTeamNumber())
		UpdateObjectives();

	m_TeamIsSetUp[Team] = true;
}

// Given an index into the Player list, build everything for a given
// single player (i.e. a vehicle of some sorts), and set up the team
// as well as necessary
Handle Strategy02::SetupPlayer(int Team)
{
	Handle PlayerH = 0;
	Vector spawnpointPosition;
	memset(&spawnpointPosition, 0, sizeof(spawnpointPosition));

	if((Team<0) || (Team>=MAX_TEAMS))
		return 0; // Sanity check... do NOT proceed

	m_SpawnedAtTime[Team] = m_ElapsedGameTime; // Note when they spawned in.

	int TeamBlock=WhichTeamGroup(Team);

	Vector Center;
	Vector Front;
	memset(&Center, 0, sizeof(Center));
	memset(&Front, 0, sizeof(Front));
	if(m_SpawnFacingCenter)
		Center = GetCenterOfMap();

	if((!IsTeamplayOn()) || (TeamBlock<0))
	{
		// If not team play, do some fun stuff. -GBD
		if(!m_ThugFlag[Team]) // This person is a commander.
		{
			if(NumCommanders < m_NumSpawnPoints) // Still base slot available.
			{
				if(!m_TeamIsSetUp[Team])
				{
					CommanderTeam[m_AllyTeams[Team]] = Team;
					NumCommanders++;
				}

				// This player is their own commander; set up their equipment.
				SetupTeam(Team);

				// Now put player near his recycler
				spawnpointPosition.z = m_TeamPos[3*Team+2];
				spawnpointPosition.x = m_TeamPos[3*Team+0];
				spawnpointPosition.y = TerrainFindFloor(spawnpointPosition.x, spawnpointPosition.z) + 2.5f;
			}
			else // Uh Oh, this map can't support any more commanding Teams. Make them a thug.
			{
				// Remove previous alliances.
				for(int i = 1; i < MAX_TEAMS; i++)
				{
					if(i != Team)
					{
						UnAlly(Team, i);
						UnAlly(i, Team);
					}
				}

				m_ThugFlag[Team] = true;

				int HighestTeam = -1;
				for(int i = 0; i < MAX_TEAMS; i++)
				{
					if(CommanderTeam[i] > HighestTeam)
						HighestTeam = CommanderTeam[i];
				}

				// Auto assign them to the next commander's alliance.
				int NextAssignTeam = 0;
				for(int i = NextAutoAssignTeam; i < MAX_TEAMS; i++)
				{
					if(CommanderTeam[i] != 0)
					{
						NextAssignTeam = i;
						NextAutoAssignTeam = i + 1;
						if(NextAutoAssignTeam > HighestTeam)
							NextAutoAssignTeam = 0;
						break;
					}
				}

				m_AllyTeams[Team] = m_AllyTeams[NextAssignTeam];

				for(int i = 1; i < MAX_TEAMS; i++)
				{
					if((m_AllyTeams[i] > 0) && (i != Team) && (m_AllyTeams[i] == m_AllyTeams[Team]))
					{
						Ally(i, Team);
						Ally(Team, i);
						m_HasAllies[i] = true;
						m_HasAllies[Team] = true;
					}
				}

				// Re-initialize starting position off the commander's.
				spawnpointPosition.x = m_TeamPos[3*CommanderTeam[m_AllyTeams[Team]]+0];
				spawnpointPosition.z = m_TeamPos[3*CommanderTeam[m_AllyTeams[Team]]+2];
				spawnpointPosition.y = TerrainFindFloor(spawnpointPosition.x, spawnpointPosition.z) + 2.5f;

				ThugCounter[CommanderTeam[m_AllyTeams[Team]]]++;

				Vector NewPosition;
				if(!m_SpawnFacingCenter)
				{
					NewPosition = GetPositionNear(spawnpointPosition, AllyMinRadiusAway, AllyMaxRadiusAway);
				}
				else
				{
					Front = GetFacingDrection2D(spawnpointPosition, Center);
					Front = HRotateFront(Front, (15.0f * ThugCounter[CommanderTeam[m_AllyTeams[Team]]]) * DEG_2_RAD);
					NewPosition = spawnpointPosition + (Front * 50.0f);
				}

				// Note: the player is still built at the commander's position below;
				// only the respawn position moves. (As shipped.)
				m_TeamPos[3*Team+0]=NewPosition.x;
				m_TeamPos[3*Team+1]=NewPosition.y;
				m_TeamPos[3*Team+2]=NewPosition.z;
			}
		}
		else // Is a Thug. Put them near the commander.
		{
			ThugCounter[CommanderTeam[m_AllyTeams[Team]]]++;

			spawnpointPosition.x = m_TeamPos[3*CommanderTeam[m_AllyTeams[Team]]+0];
			spawnpointPosition.z = m_TeamPos[3*CommanderTeam[m_AllyTeams[Team]]+2];
			spawnpointPosition.y = TerrainFindFloor(spawnpointPosition.x, spawnpointPosition.z) + 2.5f;

			if(m_SpawnFacingCenter)
			{
				Front = GetFacingDrection2D(spawnpointPosition, Center);
				Front = HRotateFront(Front, (15.0f * ThugCounter[CommanderTeam[m_AllyTeams[Team]]]) * DEG_2_RAD);
				spawnpointPosition = spawnpointPosition + (Front * 50.0f);
			}
			else
			{
				spawnpointPosition.z = m_TeamPos[3*Team+2];
				spawnpointPosition.x = m_TeamPos[3*Team+0];
				spawnpointPosition.y = TerrainFindFloor(spawnpointPosition.x, spawnpointPosition.z) + 2.5f;
			}
		}
	}
	else
	{
		// Teamplay. Gotta put them near their defensive player. Also, 
		// always ensure the recycler/etc has been set up for this
		// team if we know who they are
		SetupTeam(GetCommanderTeam(Team));

		// SetupTeam will fill in the m_TeamPos[] array of positions
		// for both the commander and offense players, so read out the
		// results
		spawnpointPosition.z = m_TeamPos[3*Team+2];
		spawnpointPosition.x = m_TeamPos[3*Team+0];
		spawnpointPosition.y = TerrainFindFloor(spawnpointPosition.x, spawnpointPosition.z) + 2.5f;

		if(m_SpawnFacingCenter)
		{
			Front = GetFacingDrection2D(spawnpointPosition, Center);
			int ThugNumber = (Team < 6) ? (Team - 1) : (Team - 7);
			Front = HRotateFront(Front, (15.0f * ThugNumber) * DEG_2_RAD);
			spawnpointPosition = spawnpointPosition + (Front * 50.0f);
		}
	} // Teamplay setup

	// Custom code to Respawn the player... -GBD
	const char *PlayerODF = GetPlayerODF(Team);
	bool DoOldRespawn = true;
	const char *PlayerName = GetCVarItemStr(Team, 0);

	if(m_RestorePlayers)
	{
		if(_strnicmp(PlayerODF+1, "vcamr_vsr", 9) == 0) // Camera pods always do the old respawn.
		{
			DoOldRespawn = true;
		}
		else
		{
			int Index = 0;
			if(m_RestorePlayers == 1) // Match by player name.
			{
				for(int x = 0; x < MAX_TEAMS; x++)
				{
					if((_stricmp(PlayerName, PlayerSavedName[x]) == 0) &&
						(((IsTeamplayOn()) && (m_SavedPlayerTeamGroup[x] == WhichTeamGroup(Team)+1)) ||
						((!IsTeamplayOn()) && (m_SavedPlayerTeamGroup[x] == Team))) &&
						(DoesODFExist(PlayerShipODF[x])))
					{
						Index = x;
						DoOldRespawn = false;
						break;
					}
				}
				if(DoOldRespawn) // New player, claim a slot by name.
				{
					for(int x = 0; x < MAX_TEAMS; x++)
					{
						if(PlayerSavedName[x][0] == '\0')
						{
							strcpy_s(PlayerSavedName[Team], PlayerName);
							break;
						}
					}
				}
			}
			else if(m_RestorePlayers == 2) // Match by team.
			{
				if((((IsTeamplayOn()) && (m_SavedPlayerTeamGroup[Team] == WhichTeamGroup(Team)+1)) ||
					((!IsTeamplayOn()) && (m_SavedPlayerTeamGroup[Team] == Team))) &&
					(DoesODFExist(PlayerShipODF[Team])))
				{
					DoOldRespawn = false;
					Index = Team;
				}
				else
				{
					if(IsTeamplayOn())
						m_SavedPlayerTeamGroup[Team] = WhichTeamGroup(Team)+1;
					else
						m_SavedPlayerTeamGroup[Team] = Team;
				}
			}

			if(Index)
			{
				PlayerH = BuildObject(PlayerShipODF[Index], Team, PlayerMatrix[Index]);
				SetPilotClass(PlayerH, SavedPilotODF[Index]);
				ReplaceWeapons(PlayerH, PlayerShipWeapons[Index], m_SavedPlayerLocalAmmo[Index]);
				SetCurHealth(PlayerH, m_SavedPlayerHealth[Index]);
				SetCurAmmo(PlayerH, m_SavedPlayerAmmo[Index]);
				SetPosition(PlayerH, PlayerMatrix[Index]);
				SetVelocity(PlayerH, PlayerVelocity[Index]);
				SetOmega(PlayerH, PlayerOmega[Index]);

				char ObjClass[MAX_ODF_LENGTH] = {0};
				GetObjInfo(PlayerH, Get_GOClass, ObjClass);
				if((_stricmp(ObjClass, "CLASS_SCAVENGER") == 0) || (_stricmp(ObjClass, "CLASS_SCAVENGERH") == 0))
					SetScavengerCurScrap(PlayerH, m_SavedPlayerScrap[Index]);

				if(m_SavedPlayerDeployed[Index])
					Deploy(PlayerH);

				if(IsTeamplayOn())
					m_SavedPlayerTeamGroup[Index] = WhichTeamGroup(Team)+1;
				else
					m_SavedPlayerTeamGroup[Index] = Team;

				m_GiveWeaponsBack[Index] = true;
			}
		}
	}

	if((m_RestorePlayers == 0) || (DoOldRespawn))
	{
		if(_stricmp(PlayerName, "Krohonus_Legs") == 0)
			PlayerH = BuildObject("evlegs_vsr", Team, spawnpointPosition);
		else
			PlayerH = BuildObject(PlayerODF, Team, spawnpointPosition);

		if(_strnicmp(PlayerODF+1, "vcamr_vsr", 9) == 0) // Camera pod, perceived team 0.
			SetPerceivedTeam(PlayerH, 0);

		// Added to make your starting pilot match respawning pilot. -GBD
		SetPilotClass(PlayerH, GetInitialPlayerPilotODF(GetRaceOfTeam(Team), Team, false));

		if(!m_SpawnFacingCenter)
		{
			SetRandomHeadingAngle(PlayerH);
		}
		else
		{
			Front = GetFacingDrection2D(spawnpointPosition, Center);
			Matrix Pos = Build_Directinal_Matrix(spawnpointPosition, Front);
			SetPosition(PlayerH, Pos);
			SetVectorPosition(PlayerH, Pos.posit);
		}
	}

	// If on team 0 (dedicated server team), make this object gone from the world
	if(!Team)
		MakeInert(PlayerH);

	return PlayerH;
}

// Internal one-time setup
void Strategy02::Init(void)
{
	// StartingVehicle file. Set if specified.
	const char* Contents = GetVarItemStr("network.session.svar6");
	if((Contents != NULL) && (Contents[0] != '\0'))
		StartingVehicleManager::Init();

	// ST: Capture mode targets, read from the map's .trn file. -GBD
	char CaptureTarget[MAX_TEAMS][MAX_ODF_LENGTH];
	memset(CaptureTarget, 0, sizeof(CaptureTarget));
	int NumCaptureTargetODFs = 0;
	bool CaptureRandom = false;

	// Read from the map's .trn file
	char mapTrnFile[128];
	strcpy_s(mapTrnFile, GetVarItemStr("network.session.svar0"));
	char *pDot = strrchr(mapTrnFile, '.');
	if(pDot)
	{
		*pDot = '\0';
		strcat_s(mapTrnFile, ".trn");
		OpenODF2(mapTrnFile);

		GetODFBool(mapTrnFile, "DLL", "RespawnAtLowAltitude", &m_RespawnAtLowAltitude, false);
		GetODFFloat(mapTrnFile, "DLL", "FriendlySpawnpointMaxAllyRange", &m_FRIENDLY_SPAWNPOINT_MAX_ALLY, FRIENDLY_SPAWNPOINT_MAX_ALLY);
		GetODFFloat(mapTrnFile, "DLL", "FriendlySpawnpointMinEnemyRange", &m_FRIENDLY_SPAWNPOINT_MIN_ENEMY, FRIENDLY_SPAWNPOINT_MIN_ENEMY);
		GetODFFloat(mapTrnFile, "DLL", "RandomSpawnpointMinEnemyRange", &m_RANDOM_SPAWNPOINT_MIN_ENEMY, RANDOM_SPAWNPOINT_MIN_ENEMY);

		char DesiredValue[MAX_ODF_LENGTH];
		for(int x = 1; x <= MAX_TEAMS; x++)
		{
			sprintf_s(DesiredValue, "CaptureTarget%d", x);
			if(!GetODFString(mapTrnFile, "DLL", DesiredValue, MAX_ODF_LENGTH, CaptureTarget[x-1]))
				break;
			NumCaptureTargetODFs++;
		}
		GetODFBool(mapTrnFile, "DLL", "CaptureIsRandom", &CaptureRandom, false);

		// Start playing the musics. -GBD
		GetODFString(mapTrnFile, "VSR", "MapAmbientSound", MAX_ODF_LENGTH, MapAmbientSound);
		if(DoesFileExist(MapAmbientSound))
			EasterEggSound = StartAudio2D(MapAmbientSound, -1.0f, 0.0f, 44100.0f, true, false);
	}

	// Set up some variables based on how things appear in the world
	m_DidInit = true;
	m_KillLimit = GetVarItemInt("network.session.ivar0");
	m_TotalGameTime = GetVarItemInt("network.session.ivar1");
	// Skip ivar2-- player limit.

	m_StartingVehiclesMask = GetVarItemInt("network.session.ivar7");

	// Tell if this is an MPI based on ivar12. -GBD
	m_IsMPI = GetVarItemInt("network.session.ivar12") != 0;
	if(m_IsMPI)
	{
		// Get AI Team Races
		m_AIRace[0] = GetVarItemInt("network.session.ivar13");
		m_AIRace[1] = GetVarItemInt("network.session.ivar96");
		m_AIRace[2] = GetVarItemInt("network.session.ivar97");
		m_AIRace[3] = GetVarItemInt("network.session.ivar98");
		m_AIRace[4] = GetVarItemInt("network.session.ivar99");

		m_CPUTurretAISkill = GetVarItemInt("network.session.ivar21");
		if(m_CPUTurretAISkill < 0)
			m_CPUTurretAISkill = 0;
		else if(m_CPUTurretAISkill > 3)
			m_CPUTurretAISkill = 3;

		m_CPUNonTurretAISkill = GetVarItemInt("network.session.ivar22");
		if(m_CPUNonTurretAISkill < 0)
			m_CPUNonTurretAISkill = 0;
		else if(m_CPUNonTurretAISkill > 3)
			m_CPUNonTurretAISkill = 3;

		m_HumanForce = GetVarItemInt("network.session.ivar23");
		if(m_HumanForce < 0)
			m_HumanForce = 0;
		else if(m_HumanForce > 3)
			m_HumanForce = 3;

		m_CPUForce = GetVarItemInt("network.session.ivar24");
		if(m_CPUForce < 0)
			m_CPUForce = 0;
		else if(m_CPUForce > 3)
			m_CPUForce = 3;
	}

	m_GameType = GetVarItemInt("network.session.ivar53");

	int CaptureTime = GetVarItemInt("network.session.ivar54");
	if(CaptureTime < 30)
		CaptureTime = 30;
	else if(CaptureTime > 120)
		CaptureTime = 120;
	m_CaptureTime = m_GameTPS * CaptureTime;

	m_PointsForAIKill = GetVarItemInt("network.session.ivar14") != 0;
	m_KillForAIKill = GetVarItemInt("network.session.ivar15") != 0;
	m_RespawnWithSniper = GetVarItemInt("network.session.ivar16");

	m_bIsFriendlyFireOn = GetVarItemInt("network.session.ivar32") != 0;

	m_SetThugPilotFlag = GetVarItemInt("network.session.ivar55") != 0;

	m_SpawnFacingCenter = GetVarItemInt("network.session.ivar118") != 0;

	m_RestorePlayers = GetVarItemInt("network.session.ivar119");
	if(m_RestorePlayers < 0)
		m_RestorePlayers = 0;
	else if(m_RestorePlayers > 2)
		m_RestorePlayers = 2;

	int PilotInvunerability = GetVarItemInt("network.session.ivar120");
	if(PilotInvunerability < 0)
		PilotInvunerability = 0;
	else if(PilotInvunerability > 120)
		PilotInvunerability = 120;
	m_PilotInvunerability = m_GameTPS * PilotInvunerability;

	m_MorphTankAutoDeployType = GetVarItemInt("network.session.ivar121");
	if(m_MorphTankAutoDeployType < 0)
		m_MorphTankAutoDeployType = 0;
	else if(m_MorphTankAutoDeployType > 3)
		m_MorphTankAutoDeployType = 3;

	m_TurretAISkill = GetVarItemInt("network.session.ivar17");
	if(m_TurretAISkill < 0)
		m_TurretAISkill = 0;
	else if(m_TurretAISkill > 3)
		m_TurretAISkill = 3;

	m_NonTurretAISkill = GetVarItemInt("network.session.ivar18");
	if(m_NonTurretAISkill < 0)
		m_NonTurretAISkill = 0;
	else if(m_NonTurretAISkill > 3)
		m_NonTurretAISkill = 3;

	// Ally code. -GBD
	memset(m_AllyTeams, 0, sizeof(m_AllyTeams));
	if((!IsTeamplayOn()) || (m_IsMPI))
	{
		// Grab "Team" numbers
		char VarName[MAX_ODF_LENGTH] = {0};
		for(int i = 1; i < MAX_TEAMS; i++)
		{
			sprintf_s(VarName, "network.session.ivar%d", 34 + i);
			m_AllyTeams[i] = GetVarItemInt(VarName);
			if(m_AllyTeams[i] <= 0)
				m_AllyTeams[i] = i;

			sprintf_s(VarName, "network.session.ivar%d", 80 + i);
			int ThugFlag = GetVarItemInt(VarName);
			if(ThugFlag < 0)
				ThugFlag = 0;
			else if(ThugFlag > 1)
				ThugFlag = 1;
			m_ThugFlag[i] = ThugFlag != 0;
		}

		if(IsTeamplayOn()) // MPI Teamplay: the humans are all one alliance.
		{
			// Get Team Colors from Game Prefs
			int R[MAX_AI_TEAMS] = {0};
			int G[MAX_AI_TEAMS] = {0};
			int B[MAX_AI_TEAMS] = {0};
			for(int x = 1; x <= MAX_AI_TEAMS; x++)
				GetTeamStratIndividualColor(TEAMCOLOR_TYPE_GAMEPREFS, x, R[x], G[x], B[x]);

			DefaultAllies();

			SetFFATeamColors(TEAMCOLOR_TYPE_GAMEPREFS);

			// Re-ally Team 1-5
			for(int x = 1; x <= MAX_AI_TEAMS; x++)
			{
				SetTeamColor(x, R[x], G[x], B[x]);
				for(int y = 1; y <= MAX_AI_TEAMS; y++)
				{
					if(x != y)
					{
						Ally(x, y);
						if(x == 1)
							m_AllyTeams[y] = m_AllyTeams[x];
					}
				}
			}
		}

		// Loop over all teams and ally
		for(int x = 1; x < MAX_TEAMS; x++)
		{
			for(int y = 1; y < MAX_TEAMS; y++)
			{
				if((m_AllyTeams[x] > 0) && (x != y) && (m_AllyTeams[x] == m_AllyTeams[y]))
				{
					Ally(x, y);
					m_HasAllies[x] = true;

					if((IsTeamplayOn()) && (x == 1))
					{
						for(int j = GetFirstAlliedTeam(x); j <= GetLastAlliedTeam(x); j++)
							Ally(j, y);
					}
				}
			}
		}

		// Setup Commander: every alliance needs one.
		for(int i = 1; i < MAX_TEAMS; i++)
		{
			if(!m_TeamHasCommander[m_AllyTeams[i]])
			{
				// Find commander
				for(int x = 0; x < MAX_TEAMS; x++)
				{
					if((!m_ThugFlag[x]) && (m_AllyTeams[i] == m_AllyTeams[x]))
					{
						m_TeamHasCommander[m_AllyTeams[i]] = true;
						break;
					}
				}

				if(!m_TeamHasCommander[m_AllyTeams[i]])
				{
					// Pick first player
					for(int x = 0; x < MAX_TEAMS; x++)
					{
						if(m_AllyTeams[x] == m_AllyTeams[i])
						{
							m_ThugFlag[x] = false;
							m_TeamHasCommander[m_AllyTeams[i]] = true;
							break;
						}
					}
				}
			}
		}
	}

	m_RecyInvulnerabilityTime = m_GameTPS * GetVarItemInt("network.session.ivar25") * 60;

	// Spawn in players, if we're server.
	Handle PlayerEntryH = GetPlayerHandle();
	if(PlayerEntryH)
		RemoveObject(PlayerEntryH);

	if((ImServer()) || (!IsNetworkOn()))
	{
		m_ElapsedGameTime = 0;
		if(!m_RemainingGameTime)
			m_RemainingGameTime = m_TotalGameTime * m_GameTPS * 60;

		if(m_IsMPI)
		{
			m_LastTauntPrintedAt = -2000;
			InitTaunts(&m_ElapsedGameTime, &m_LastTauntPrintedAt, &m_GameTPS);
		}
	}

	int LocalTeamNum = GetLocalPlayerTeamNumber();
	Handle PlayerH = SetupPlayer(LocalTeamNum);
	SetAsUser(PlayerH, LocalTeamNum);
	AddPilotByHandle(PlayerH);

	// ST: Capture mode. Build the capture goals on the "capturegoal#" paths. -GBD
	if(m_GameType == 4)
	{
		int pathCount = 0;
		char **pathNames = NULL;
		GetAiPaths(pathCount, pathNames);

		float Random = 0.0f;
		for(int i = 0; i < pathCount; i++)
		{
			const char *label = pathNames[i];

			if(NumCaptureTargetODFs < 1)
			{
				PrintConsoleMessage("Error: Map has no Capture ODF's set!");
			}
			else
			{
				int num = -1;
				if((sscanf_s(label, "capturegoal%d", &num) > 0) && (m_NumCaptureGoals < MAX_TEAMS))
				{
					if(CaptureRandom)
					{
						Random = float(floor(GetRandomFloat(float(NumCaptureTargetODFs))));
						if(Random > float(NumCaptureTargetODFs))
							Random = float(NumCaptureTargetODFs);
					}
					else
					{
						if(Random > float(NumCaptureTargetODFs))
							Random = 0.0f;
					}

					const char *pODF = CaptureTarget[int(Random)];
					if(DoesODFExist(pODF))
					{
						m_CaptureGoals[m_NumCaptureGoals] = BuildObject(pODF, 0, label);
						if(IsAround(m_CaptureGoals[m_NumCaptureGoals]))
						{
							SetObjectiveOn(m_CaptureGoals[m_NumCaptureGoals]);
							m_NumCaptureGoals++;
						}
						Random += 1.0f;
					}
					else
					{
						sprintf_s(TempMsgString, "Error: ODF '%s' doesn't exist!", pODF);
						PrintConsoleMessage(TempMsgString);
					}
				}
			}
		}
	}
}

// Called from Execute, m_GameTPS of a second has elapsed. Update everything.
void Strategy02::UpdateGameTime(void)
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
			DoGameover(endDelta);
		}

	}
	else { 
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

// If Recycler invulnerability is on, then does the job of it.
void Strategy02::ExecuteRecyInvulnerability(void)
{
	// No need to do anything more...
	if((m_GameOver) || (m_RecyInvulnerabilityTime == 0))
		return;

	int i;
	Handle recyHandle = 0; // for this team, either vehicle or building
	for(i=0;i<MAX_TEAMS;i++)
	{
		if(m_TeamIsSetUp[i])
		{

			// Check if recycler vehicle still exists. Side effect to
			// note: IsAliveAndPilot zeroes the handle if pilot missing;
			// that'd be bad for us here if we want to manually remove
			// it. Thus, we have a sacrificial copy of it the game can
			// obliterate w/o hurting anything.
			Handle TempH = m_RecyclerHandles[i];
			if((!IsAlive(TempH)) || (TempH==0))
				recyHandle = GetObjectByTeamSlot(i, DLL_TEAM_SLOT_RECYCLER);
			else
				recyHandle = m_RecyclerHandles[i];

			if(recyHandle && DLLUtils::IsRecycler(recyHandle))
			{
				SetCurHealth(recyHandle, GetMaxHealth(recyHandle));
			}

		} // m_TeamIsSetUp[i]
	} // i loop over all teams

	// Print periodic message about recycler invulnerability time left
	if((m_RecyInvulnerabilityTime == 1) ||
		((m_RecyInvulnerabilityTime % (60 * m_GameTPS)) == 0) ||
		((m_RecyInvulnerabilityTime < (60 * m_GameTPS)) && ((m_RecyInvulnerabilityTime % (15 * m_GameTPS)) == 0)))
	{

		if(m_RecyInvulnerabilityTime == 1)
		{
			sprintf_s(TempMsgString, GetBZCCLocalizedString("strat", "recyclersVulnerable"));
		}
		else if(m_RecyInvulnerabilityTime > (60 * m_GameTPS))
		{
			sprintf_s(TempMsgString, GetBZCCLocalizedString("strat", "invulnerableExpiresMin"), m_RecyInvulnerabilityTime / (60 * m_GameTPS));
		}
		else
		{
			sprintf_s(TempMsgString, GetBZCCLocalizedString("strat", "invulnerableExpiresSec"), m_RecyInvulnerabilityTime / m_GameTPS);
		}

		AddToMessagesBox2(TempMsgString, RGB(255, 0, 255)); // bright purple (ARGB)
	}

	// Reduce timer
	--m_RecyInvulnerabilityTime;
}

// New Alliance TeamWinning Code. -GBD
void Strategy02::ExecuteCheckIfGameOver(void)
{
	// No need to do anything more...
	if((m_GameOver) || (m_ElapsedGameTime < (m_GameTPS)))
		return;

	// Check for a gameover by no recycler & factory
	int i, NumFunctioningTeams=0;
	bool TeamIsFunctioning[MAX_TEAMS];
	bool AlliesFunctioning[MAX_TEAMS]; // Ally Functioning Flag. -GBD
	bool HumansAlive = false; // MPI: is any human base still standing? -GBD
	const bool TeamPlayOn = IsTeamplayOn();

	memset(TeamIsFunctioning, 0, sizeof(TeamIsFunctioning));
	memset(AlliesFunctioning, 0, sizeof(AlliesFunctioning)); // Memset for ally flag. -GBD

	for(i=0;i<MAX_TEAMS;i++)
	{
		if(m_TeamIsSetUp[i])
		{
			bool Functioning=false; // Assume so for now.
			
			// Check if recycler vehicle still exists. Side effect to
			// note: IsAliveAndPilot zeroes the handle if pilot missing;
			// that'd be bad for us here if we want to manually remove
			// it. Thus, we have a sacrificial copy of it the game can
			// obliterate w/o hurting anything.
			Handle TempH = m_RecyclerHandles[i];

			// Added to allow recycler upgrading? -GBD
			if(!IsAround(TempH))
				TempH = GetObjectByTeamSlot(i, DLL_TEAM_SLOT_RECYCLER);

			// Use the side effect of IsAlive as well, hence the TempH == 0 -GBD
			if((!TempH) || (!IsAlive(TempH)))
				m_RecyclerHandles[i]=0; // Clear this out for later
			else
				Functioning=true;

			// Set this here. -GBD
			Handle RecyH = 0;

			// Check vehicle if it is around, else, check the buuilding -GBD
			if((IsAlive(TempH)) || (TempH!=0))
				RecyH = TempH;
			else
				RecyH = GetObjectByTeamSlot(i, DLL_TEAM_SLOT_RECYCLER);

			if(!RecyH) // Uh oh, no Recycler? Look for Factory. -GBD
				RecyH = GetObjectByTeamSlot(i, DLL_TEAM_SLOT_FACTORY);

			if(RecyH)
			{
				if((m_IsMPI) && (i < 11)) // Teams 1-10 are humans.
					HumansAlive = true;
				Functioning=true;
			}

			AlliesFunctioning[m_AllyTeams[i]] = AlliesFunctioning[m_AllyTeams[i]] || Functioning;
			TeamIsFunctioning[i] = Functioning;

			// Moved Respawn check here to look for allies too. -GBD
			// Note deployed location first time it deploys, also every 25.6 seconds
			if((!m_NotedRecyclerLocation[i]) || (!(m_ElapsedGameTime & 0xFF)))
			{
				if(!TeamPlayOn) // FFA only. First pass, look for Commander's Recycler/Factory.
				{
					if(!RecyH)
						RecyH = GetObjectByTeamSlot(CommanderTeam[m_AllyTeams[i]], DLL_TEAM_SLOT_RECYCLER);
					if(!RecyH)
						RecyH = GetObjectByTeamSlot(CommanderTeam[m_AllyTeams[i]], DLL_TEAM_SLOT_FACTORY);
				}

				// Grab out allie's Recy for respawn placement if ours is dead.
				if(!RecyH) // Uh oh, your recy+factory are dead. Look for ones on allied teams.
				{
					for(int x=1;x<MAX_TEAMS;x++) // Loop through all teams. 
					{
						// If the team is set, and it's not the same team as the first loop, and they're allied, then we found one. 
						if((i != x) && (IsTeamAllied(i, x)))
						{
							RecyH = GetObjectByTeamSlot(x, DLL_TEAM_SLOT_RECYCLER);
							if(!RecyH) // Uh oh, no Recycler? Look for Factory.
								RecyH = GetObjectByTeamSlot(x, DLL_TEAM_SLOT_FACTORY);

							if(RecyH)
								break; // We found one, and they're alive. Abort X loop early. 
						}
					}
				}

				if(RecyH) // The above functions found something...-GBD
				{
					m_NotedRecyclerLocation[i] = true;
					Vector RecyPos;
					GetPosition(RecyH, RecyPos);
					m_TeamPos[3*i+0] = RecyPos.x;
					m_TeamPos[3*i+1] = RecyPos.y;
					m_TeamPos[3*i+2] = RecyPos.z;
					// Apply this to thugs also.
					if(TeamPlayOn)
					{
						for(int jj=GetFirstAlliedTeam(i);jj<=GetLastAlliedTeam(i);jj++)
						{
							// In teamplay, store where offense players were created for respawns later
							m_TeamPos[3*jj+0]=RecyPos.x;
							m_TeamPos[3*jj+1]=RecyPos.y;
							m_TeamPos[3*jj+2]=RecyPos.z;
						} // Loop over allies not the commander
					}
				} // Note deployed location
			}
		} // Team is set up
	} // loop over functioning teams

	for(i=0;i<MAX_TEAMS;i++)
	{
		if((!m_IsMPI) && (TeamPlayOn))
		{
			if(TeamIsFunctioning[i])
				NumFunctioningTeams++;
		}
		else
		{
			if(AlliesFunctioning[i])
				NumFunctioningTeams++;
		}
	}

	// MPI, Special abort early if all humans are dead. -GBD
	if((m_IsMPI) && (!HumansAlive))
	{
		NoteGameoverWithCustomMessage("All Human bases destroyed!");
		DoGameover(endDelta);
		m_GameOver=true;
	}

	// Keep track if we ever had several teams playing. Don't need
	// to check for gameover if so-- 
	if(NumFunctioningTeams>1)
	{
		m_HadMultipleFunctioningTeams=true;
		return; // Exit function early
	}

	// Easy Gameover case: nobody's got a functioning base. End everything now.
	if((NumFunctioningTeams==0) && (m_ElapsedGameTime > (5 * m_GameTPS)))
	{
		NoteGameoverByNoBases();
		DoGameover(endDelta);
		m_GameOver=true;
	}
	else
	{
		if((m_HadMultipleFunctioningTeams) && (NumFunctioningTeams==1))
		{
			// Ok, at one point we had >1 teams playing, now we've got
			// 1. They're the winner.

			// In teamplay, report the team as the winner
			if(TeamPlayOn)
			{
				bool AIWon[MAX_TEAMS]; // MPI: which CPU alliances have already been announced.
				memset(AIWon, 0, sizeof(AIWon));
				int WinningTeamgroup=-1;
				for(i=0;i<MAX_TEAMS;i++)
				{
					if(TeamIsFunctioning[i])
					{
						if(m_IsMPI)
						{
							if(i < 11)
								DoTaunt(TAUNTS_CPURecyDestroyed);
							else
								DoTaunt(TAUNTS_HumanRecyDestroyed);
						}

						if(WinningTeamgroup == -1)
						{
							if((!m_IsMPI) || (i < 11))
							{
								WinningTeamgroup = WhichTeamGroup(i);
								NoteGameoverByLastTeamWithBase(WinningTeamgroup);
							}
							else // A CPU team won.
							{
								int WinTeam = i;
								if(m_HasAllies[i])
								{
									WinTeam = m_AllyTeams[i];
									if(AIWon[WinTeam])
										continue;
									AIWon[WinTeam] = true;
								}
								sprintf_s(TempMsgString, "Computer Team %d has won, destroyed all enemy bases.", WinTeam);
								NoteGameoverWithCustomMessage(TempMsgString);
							}
						}
					}
				}

				// Also, give all players on winning team points...
				for(i=0;i<MAX_TEAMS;i++)
				{
					if(WhichTeamGroup(i) == WinningTeamgroup)
						AddScore(GetPlayerHandle(i), ScoreForWinning);
				}
				DoGameover(endDelta);
				m_GameOver=true;
			} // Teamplay is on
			else // Non-teamplay, report individual winner
			{
				// With alliances, we may not have a winner unless the team
				// remaining isn't allied (or we would have caught it above)
				bool AIWon[MAX_TEAMS]; // MPI: which CPU alliances have already been announced.
				memset(AIWon, 0, sizeof(AIWon));

				for(i=0;i<MAX_TEAMS;i++) // Start at 0. Also give a more proper message if allies are on. -GBD
				{
					if(m_IsMPI)
					{
						if(i < 11)
							DoTaunt(TAUNTS_CPURecyDestroyed);
						else
							DoTaunt(TAUNTS_HumanRecyDestroyed);
					}

					if(AlliesFunctioning[m_AllyTeams[i]])
					{
						if((!m_IsMPI) || (i < 11))
						{
							if(m_HasAllies[i])
							{
								// Tell who won. -GBD (As shipped, the message is built but not shown.)
								char TeamName[MAX_ODF_LENGTH];
								sprintf_s(TeamName, "%s %d", GetBZCCLocalizedString("cfg", "Team"), m_AllyTeams[i]);
								sprintf_s(TempMsgString, GetBZCCLocalizedString("Network", "HitLastWithBaseStr"), TeamName);
								for(int j=0;j<MAX_TEAMS;j++) // Give score to allies. -GBD
								{
									if((i != j) && (IsTeamAllied(i, j)))
										AddScore(GetPlayerHandle(j), ScoreForWinning);
								}
							}
							else
								NoteGameoverByLastWithBase(GetPlayerHandle(i));
						}
						else // A CPU team won.
						{
							int WinTeam = i;
							if(m_HasAllies[i])
							{
								if(AIWon[m_AllyTeams[i]])
								{
									AddScore(GetPlayerHandle(i), ScoreForWinning);
									continue;
								}
								AIWon[m_AllyTeams[i]] = true;
								WinTeam = m_AllyTeams[i];
							}
							sprintf_s(TempMsgString, "Computer Team %d has won, destroyed all enemy bases.", WinTeam);
							NoteGameoverWithCustomMessage(TempMsgString);
						}

						AddScore(GetPlayerHandle(i), ScoreForWinning);
					} // Found winner team
				}
				DoGameover(endDelta);
				m_GameOver=true;
			} // Non-teamplay.

		} // Winner
	}
}

void Strategy02::Execute(void)
{
	if(!StopScript)
		LuaMission::Execute();

	if (!m_DidInit)
	{
		Init();
	}

	// If Recycler invulnerability is on, then does the job of it.
	ExecuteRecyInvulnerability();

	// Check for absence of recycler & factory, gameover if so.
	ExecuteCheckIfGameOver();

	// Do this as well...
	UpdateGameTime();

	// watch for winner.
	if(m_GameType == 4)
		ExecuteST_Capture();

	const bool TeamPlayOn = IsTeamplayOn();

	// VSR Specific stuff. -GBD
	for(int Team = 0; Team < MAX_TEAMS; Team++)
	{
		Handle TempPlayerH = GetPlayerHandle(Team);
		if(!IsAround(TempPlayerH))
			continue;

		// Pilot Invulnerability: the respawned pilot keeps 0 max health
		// until the timer runs out or they fire. -GBD
		if((m_PilotInvTime[Team] > 0) && (m_PilotInvUser[Team] == TempPlayerH))
		{
			m_PilotInvTime[Team]--;

			if(GetCurAmmo(m_PilotInvUser[Team]) < GetMaxAmmo(m_PilotInvUser[Team]))
				m_PilotInvTime[Team] = 0;

			if((m_PilotInvTime[Team] <= 0) && (IsAround(m_PilotInvUser[Team])))
				SetMaxHealth(m_PilotInvUser[Team], m_SavedPilotInvHealth[Team]);
		}

		char PlayerODF[MAX_ODF_LENGTH] = {0};
		GetObjInfo(TempPlayerH, Get_CFG, PlayerODF);
		// Cutoff :# at the end.
		if(!DoesODFExist(PlayerODF))
		{
			char *colon = strchr(PlayerODF, ':');
			strncpy_s(PlayerODF, PlayerODF, colon - PlayerODF);
		}

		// Camera Pod Alliance Stuff: a camera pod is unallied from everybody. -GBD
		if(_strnicmp(PlayerODF+1, "vcamr_vsr", 9) == 0)
		{
			SetPerceivedTeam(TempPlayerH, 0);

			if(!IsCameraPod[Team])
			{
				for(int x = 1; x < MAX_TEAMS; x++)
				{
					if(x != Team)
						UnAlly(x, Team);
				}
				IsCameraPod[Team] = true;
			}
		}
		else if(IsCameraPod[Team]) // Back in a real ship, restore the alliances.
		{
			if(!TeamPlayOn)
			{
				for(int x = 1; x < MAX_TEAMS; x++)
				{
					if((m_AllyTeams[x] > 0) && (x != Team) && (m_AllyTeams[x] == m_AllyTeams[Team]))
						Ally(x, Team);
				}
			}
			else
			{
				for(int x = GetFirstAlliedTeam(Team); x <= GetLastAlliedTeam(Team); x++)
					Ally(x, Team);
			}
			IsCameraPod[Team] = false;
		}

		// Restore Players code: remember what each player is flying. -GBD
		if((m_RestorePlayers > 0) && (_strnicmp(PlayerODF+1, "vcamr_vsr", 9) != 0) && (_strnicmp(PlayerODF+1, "vsatview_vsr", 12) != 0))
		{
			const char *PlayerName = GetCVarItemStr(Team, 0);
			char PilotODF[MAX_ODF_LENGTH] = {0};
			char ObjClass[MAX_ODF_LENGTH] = {0};
			GetObjInfo(TempPlayerH, Get_GOClass, ObjClass);
			const char *pPilotODF = GetPilotClass(TempPlayerH);
			if(pPilotODF)
			{
				strcpy_s(PilotODF, pPilotODF);
				char *dot = strrchr(PilotODF, '.');
				if(dot)
					*dot = '\0';
			}

			int Index = 0;
			if(m_RestorePlayers == 1) // Match by player name.
			{
				for(int x = 0; x < MAX_TEAMS; x++)
				{
					if(_stricmp(PlayerName, PlayerSavedName[x]) == 0)
					{
						Index = x;
						break;
					}
				}
			}
			else if(m_RestorePlayers == 2) // Match by team.
			{
				if(((!TeamPlayOn) && (m_SavedPlayerTeamGroup[Team] == Team)) ||
					((TeamPlayOn) && (m_SavedPlayerTeamGroup[Team] == WhichTeamGroup(Team)+1)))
					Index = Team;
			}

			if(Index)
			{
				strcpy_s(PlayerShipODF[Index], PlayerODF);
				strcpy_s(SavedPilotODF[Index], PilotODF);
				strcpy_s(PlayerSavedName[Index], PlayerName);

				for(int i = 0; i < MAX_HARDPOINTS; i++)
				{
					GetObjInfo(TempPlayerH, ObjectInfoType(Get_Weapon0Config + i), PlayerShipWeapons[Index][i]);
					m_SavedPlayerLocalAmmo[Index][i] = GetCurLocalAmmo(TempPlayerH, i);
				}

				m_SavedPlayerHealth[Index] = GetCurHealth(TempPlayerH);
				m_SavedPlayerAmmo[Index] = GetCurAmmo(TempPlayerH);
				GetPosition(TempPlayerH, PlayerMatrix[Index]);
				PlayerVelocity[Index] = GetVelocity(TempPlayerH);
				PlayerOmega[Index] = GetOmega(TempPlayerH);

				if((_stricmp(ObjClass, "CLASS_SCAVENGER") == 0) || (_stricmp(ObjClass, "CLASS_SCAVENGERH") == 0))
					m_SavedPlayerScrap[Index] = GetScavengerCurScrap(TempPlayerH);

				m_SavedPlayerDeployed[Index] = IsDeployed(TempPlayerH);

				if(TeamPlayOn)
					m_SavedPlayerTeamGroup[Index] = WhichTeamGroup(Team)+1;
				else
					m_SavedPlayerTeamGroup[Index] = Team;

				// Pilots: remember the pilot's weapons, or give them back after a restore.
				if(_stricmp(ObjClass, "CLASS_PERSON") == 0)
				{
					if(!m_GiveWeaponsBack[Index])
					{
						for(int i = 0; i < MAX_HARDPOINTS; i++)
						{
							GetObjInfo(TempPlayerH, ObjectInfoType(Get_Weapon0Config + i), PlayerPilotWeapons[Index][i]);
							PlayerPilotLocalAmmo[Index][i] = GetCurLocalAmmo(TempPlayerH, i);
						}
					}
					else
					{
						ReplaceWeapons(TempPlayerH, PlayerPilotWeapons[Index], PlayerPilotLocalAmmo[Index]);
						m_GiveWeaponsBack[Index] = false;
					}
				}
			}
		}
	} // Team Loop

	// Empty Ship Invulnerability. -GBD
	if(m_PilotInvunerability > 0)
	{
		EmptyShipList.erase(std::remove_if(EmptyShipList.begin(), EmptyShipList.end(), ShouldRemoveEmptyShipObject), EmptyShipList.end());

		for (std::vector<EmptyShipClass>::iterator iter = EmptyShipList.begin(); iter != EmptyShipList.end(); ++iter)
		{
			if(iter->InvulnerabilityTime > 0)
				iter->InvulnerabilityTime--;

			if((iter->InvulnerabilityTime <= 0) || (IsAliveAndPilot2(iter->EmptyShipObject)) || (IsPlayer(iter->EmptyShipObject)))
			{
				if(GetMaxHealth(iter->EmptyShipObject) == 0)
					SetMaxHealth(iter->EmptyShipObject, iter->SavedHealth);
			}
		}
	}

	// MorphTank default behavior. -GBD
	if(m_MorphTankAutoDeployType > 0)
	{
		MorphTankList.erase(std::remove_if(MorphTankList.begin(), MorphTankList.end(), ShouldRemoveMorphTankObject), MorphTankList.end());

		for (std::vector<MorphTankClass>::iterator iter = MorphTankList.begin(); iter != MorphTankList.end(); ++iter)
		{
			SetCommand(iter->MorphTankObject, CMD_CLOSE + m_MorphTankAutoDeployType);
			iter->CmdSet = true;
		}
	}

	// Clean up dead commbunkers. -GBD
	CommBunkerList.erase(std::remove_if(CommBunkerList.begin(), CommBunkerList.end(), ShouldRemoveCommBunkerObject), CommBunkerList.end());

	// Thug Scavenger / Pilot Management. -GBD
	if((!TeamPlayOn) || (m_IsMPI))
	{
		ScavengerManagementCode();

		// Spawn MPI AI. -GBD
		if(m_IsMPI)
		{
			if(!SpawnAI)
			{
				int PlayerLimit = GetVarItemInt("network.session.ivar2");
				int numCommanders = PlayerLimit;
				int MaxAI_Teams;
				if(!TeamPlayOn)
				{
					for(int i = 1; i <= PlayerLimit; i++)
					{
						if(m_ThugFlag[i])
							numCommanders--;
					}
					MaxAI_Teams = m_NumSpawnPoints - numCommanders;
				}
				else
				{
					MaxAI_Teams = m_NumSpawnPoints - 1;
				}

				if(MaxAI_Teams > (MAX_TEAMS-1) - PlayerLimit)
					MaxAI_Teams = (MAX_TEAMS-1) - PlayerLimit;
				if(MaxAI_Teams < 0)
					MaxAI_Teams = 0;
				else if(MaxAI_Teams > MAX_AI_TEAMS)
					MaxAI_Teams = MAX_AI_TEAMS;

				// Loop over AI. Teams 11-15.
				for(int i = 0; i < MAX_AI_TEAMS; i++)
				{
					const int CPUTeam = 11 + i;
					char PathName[MAX_ODF_LENGTH] = {0};

					if(m_AIRace[i] == 0)
						continue;

					if(i < MaxAI_Teams)
					{
						char CPURecy[MAX_ODF_LENGTH] = {0};
						const char* pContents = DLLUtils::GetCheckedNetworkSvar(12, NETLIST_Recyclers);
						if((pContents == NULL) || (pContents[0] == '\0'))
							sprintf_s(CPURecy, "%cvrecycpu_vsr", m_AIRace[i]);
						else
							strncpy_s(CPURecy, pContents, MAX_ODF_LENGTH-1);

						Handle TempH = GetObjectByTeamSlot(CPUTeam, DLL_TEAM_SLOT_RECYCLER);
						if(!TempH) // Not pre-placed, build it on the "Enemy_#" path.
						{
							sprintf_s(PathName, "Enemy_%d", CPUTeam);
							TempH = BuildObject(CPURecy, CPUTeam, PathName);
						}
						else // Pre-placed: take its race.
						{
							int Race = IsRecyclerODF(TempH);
							if(Race)
								m_AIRace[i] = Race;
						}

						if(!TempH)
						{
							m_AIRace[i] = 0;
						}
						else
						{
							SetScrap(CPUTeam, 40);
							SetCPUAIPlan(CPUTeam, CPUTeam - 5);

							char AITeamName[MAX_ODF_LENGTH] = {0};
							sprintf_s(AITeamName, "Computer Team %d", CPUTeam);
							SetTeamNameForStat(CPUTeam, GetBZCCLocalizedString("cfg", AITeamName));

							Vector Where;
							GetPosition(TempH, Where);

							// Look for the recycler's starting variant, else look for an _ in
							// there, and copy everything after it into the RecyVariant tag. -GBD
							char TempODF[MAX_ODF_LENGTH] = {0};
							char TempODF2[MAX_ODF_LENGTH] = {0};
							char VariantName[MAX_ODF_LENGTH] = {0};
							CombineStrings(TempODF, CPURecy, ".odf"); // Add .odf to the end.
							if(OpenODF2(TempODF))
							{
								if(GetODFString(TempODF, "GameObjectClass", "classlabel", MAX_ODF_LENGTH, TempODF2)) // Grab the classlabel, if present.
								{
									CombineStrings(TempODF2, TempODF2, ".odf"); // Add .odf to the end.
									OpenODF2(TempODF2);
								}
								if(!GetODFString(TempODF, TempODF2, "GameObjectClass", "startingVariant", MAX_ODF_LENGTH, VariantName))
								{
									const char *pUnderscore = strchr(CPURecy, '_');
									if(pUnderscore)
									{
										pUnderscore++;
										const char *pUnderscore2 = strchr(pUnderscore, '_');
										if(pUnderscore2) // 2 underscores, take what's after the second.
											pUnderscore = pUnderscore2 + 1;
										strcpy_s(VariantName, pUnderscore);
									}
								}
							}

							// Drop skill level while we build things.
							m_CreatingStartingVehicles = true;
							StartingVehicleManager::CreateVehicles(CPUTeam, (char)m_AIRace[i], VariantName, m_StartingVehiclesMask, Where);
							m_CreatingStartingVehicles = false;

							// Build Starting Vehicles
							char TurretODF[MAX_ODF_LENGTH] = {0};
							sprintf_s(TurretODF, "%cvturr%s", m_AIRace[i], VariantName);
							char GTowODF[MAX_ODF_LENGTH] = {0};
							sprintf_s(GTowODF, "%cbspir%s", m_AIRace[i], VariantName);
							char ScoutODF[MAX_ODF_LENGTH] = {0};
							sprintf_s(ScoutODF, "%cvscout%s", m_AIRace[i], VariantName);
							char SentODF[MAX_ODF_LENGTH] = {0};
							sprintf_s(SentODF, "%cvsent%s", m_AIRace[i], VariantName);
							char TankODF[MAX_ODF_LENGTH] = {0};
							sprintf_s(TankODF, "%cvtank%s", m_AIRace[i], VariantName);
							char ScavODF[MAX_ODF_LENGTH] = {0};
							sprintf_s(ScavODF, "%cvscav%s", m_AIRace[i], VariantName);

							for(int x = 0; x < 5; x++)
							{
								if(x < 1)
									BuildStartingVehicle(CPUTeam, m_AIRace[i], ScavODF, ScavODF, GetPositionNear(Where, AllyMinRadiusAway, AllyMaxRadiusAway));
								if(x < 2)
									BuildStartingVehicle(CPUTeam, m_AIRace[i], TurretODF, TurretODF, GetPositionNear(Where, AllyMinRadiusAway, AllyMaxRadiusAway));

								if(m_CPUForce > 0)
								{
									if(x < 2)
									{
										sprintf_s(PathName, "%dgtow%d", CPUTeam, x + 1);
										BuildStartingVehicle(CPUTeam, m_AIRace[i], GTowODF, TurretODF, PathName);
										BuildStartingVehicle(CPUTeam, m_AIRace[i], SentODF, ScoutODF, GetPositionNear(Where, AllyMinRadiusAway, AllyMaxRadiusAway));
									}
									if(m_CPUForce > 1)
									{
										if(x < 1)
											BuildStartingVehicle(CPUTeam, m_AIRace[i], SentODF, ScoutODF, GetPositionNear(Where, AllyMinRadiusAway, AllyMaxRadiusAway));
										if((x > 1) && (x < 4))
										{
											sprintf_s(PathName, "%dgtow%d", CPUTeam, x + 1);
											BuildStartingVehicle(CPUTeam, m_AIRace[i], GTowODF, TurretODF, PathName);
										}
										if(x < 3)
											BuildStartingVehicle(CPUTeam, m_AIRace[i], TankODF, TankODF, GetPositionNear(Where, AllyMinRadiusAway, AllyMaxRadiusAway));
									}
								}
							}

							m_TeamIsSetUp[CPUTeam] = true;
						}
					}
					else
					{
						sprintf_s(TempMsgString, "ERROR: CPU %d (Team: %d) spawn skipped: Too many possible Humans (%d) for map Spawns (%d). Reduce Player Limit or number of Commanders.", CPUTeam - 10, CPUTeam, numCommanders, m_NumSpawnPoints);
						FormatConsoleMessage(TempMsgString);
						AddToMessagesBox2(TempMsgString, RGB(255, 0, 0));
					}
				}
				SpawnAI = true;
			}

			// AI Scrap Cheat. -GBD
			int m_NumHumans = CountPlayers();
			for(int i = 1; i < MAX_TEAMS; i++)
			{
				if((i >= 6) && (m_CPUForce != 0))
				{
					int Turns = 0, Amount = 0;
					if(m_CPUForce == 0) { Turns = m_GameTPS * 3; Amount = 1; }
					else if(m_CPUForce == 1) { Turns = m_GameTPS * 2; Amount = 1; }
					else if(m_CPUForce == 2) { Turns = m_GameTPS * 1; Amount = 1; }
					else if(m_CPUForce == 3) { Turns = m_GameTPS / 5; Amount = 1; }

					if((Turns > 0) && ((m_ElapsedGameTime % Turns) == 0))
						AddScrap(i, Amount);

					// Humans scaling.
					if(m_NumHumans == 1) Turns = m_GameTPS;
					else if(m_NumHumans == 2) Turns = (m_GameTPS * 9) / 10;
					else if(m_NumHumans == 3) Turns = (m_GameTPS * 8) / 10;
					else if(m_NumHumans == 4) Turns = (m_GameTPS * 7) / 10;
					else if(m_NumHumans == 5) Turns = (m_GameTPS * 6) / 10;
					else continue;

					if((Turns > 0) && ((m_ElapsedGameTime % Turns) == 0))
						AddScrap(i, Amount);
				}
				else if(m_HumanForce != 0)
				{
					int Turns = 0, Amount = 0;
					if(m_HumanForce == 0) { Turns = m_GameTPS * 10; Amount = 1; }
					else if(m_HumanForce == 1) { Turns = m_GameTPS * 8; Amount = 1; }
					else if(m_HumanForce == 2) { Turns = m_GameTPS * 6; Amount = 1; }
					else if(m_HumanForce == 3) { Turns = m_GameTPS * 4; Amount = 1; }
					else continue;

					if((Turns > 0) && ((m_ElapsedGameTime % Turns) == 0))
						AddScrap(i, Amount);
				}
			}
		}
	}
}

bool Strategy02::AddPlayer(DPID id, int Team, bool IsNewPlayer)
{
	if(!StopScript)
		LuaMission::AddPlayer(id, Team, IsNewPlayer);

	if (!m_DidInit)
	{
		Init();
	}
	else
	{
		if(!IsNewPlayer)
			return true;

		if(m_IsMPI)
			DoTaunt(TAUNTS_NewHuman);
	}

	if(IsNewPlayer)
	{
		Handle PlayerH = SetupPlayer(Team);
		SetAsUser(PlayerH, Team);
		AddPilotByHandle(PlayerH);
	}

	return true; // true = ok
}

void Strategy02::DeletePlayer(DPID id)
{
	if(!StopScript)
		LuaMission::DeletePlayer(id);

	if(m_IsMPI)
		DoTaunt(TAUNTS_LeftHuman);
}

EjectKillRetCodes Strategy02::RespawnPilot(Handle DeadObjectHandle, int Team)
{
	Vector spawnpointPosition;

	// Only use safest place if invalid team #
	if((Team<1) || (Team>=MAX_TEAMS))
	{
		spawnpointPosition = GetSafestSpawnpoint();
	}
	else
	{
		// Use last noted position for the team
		spawnpointPosition.x = m_TeamPos[3*Team+0];
		spawnpointPosition.y = m_TeamPos[3*Team+1];
		spawnpointPosition.z = m_TeamPos[3*Team+2];
		m_SpawnedAtTime[Team] = m_ElapsedGameTime; // Note when they spawned in.
	}

	Vector OldPos;
	// As this object was just killed, gotta use the slower search for its
	// position.
	GetPosition2(DeadObjectHandle, OldPos);

	// Find out how far we are away from starting location... use
	// default if couldn't get position of DeadObjectHandle
	float respawnHeight = RespawnPilotHeight;
	if((fabsf(OldPos.x) > 0.01f) && (fabsf(OldPos.z) > 0.01f))
	{
		// Position valid. Use it.
		const float dx = OldPos.x - spawnpointPosition.x;
		const float dz = OldPos.z - spawnpointPosition.z;
		// How far this person died from where we'll respawn them
		const float distanceAway = sqrtf((dz * dz) + (dx * dx));
		if(distanceAway < 100.f)
		{
			respawnHeight = 35.f; // 1.2 used 25.f here
		}
		else
		{
			// Min of 40, max varies by # of allies. More penalty for
			// dying far away from your team
			respawnHeight = 30.f + (sqrtf(distanceAway) * 1.25f);
			const int numAllies = DLLUtils::CountAlliedPlayers(Team);
			const float minRespawnHeight = 40.0f;
			const float maxRespawnHeight = 70.0f + (15.0f * numAllies);

			if(respawnHeight < minRespawnHeight)
				respawnHeight = minRespawnHeight;
			else if(respawnHeight > maxRespawnHeight)
				respawnHeight = maxRespawnHeight;
		}
	}
	if(m_RespawnAtLowAltitude)
	{
		respawnHeight = 2.0f;
	}

	// Randomize starting position somewhat. This gives a range of +/-
	// RespawnDistanceAwayXZRange
	spawnpointPosition.x += (GetRandomFloat(1.f) - 0.5f) * (2.f * RespawnDistanceAwayXZRange);
	spawnpointPosition.z += (GetRandomFloat(1.f) - 0.5f) * (2.f * RespawnDistanceAwayXZRange);

	// Don't allow a spawn underground - just in case there's a cliff
	// near the starting spawnpointPosition position, we need to keep y above the
	// ground.
	{
		const float curFloor = TerrainFindFloor(spawnpointPosition.x, spawnpointPosition.z) + 2.5f;
		if(spawnpointPosition.y < curFloor)
		{
			spawnpointPosition.y = curFloor;
		}
	}
	spawnpointPosition.y += respawnHeight; // Bounce them in the air to prevent multi-kills
	spawnpointPosition.y += GetRandomFloat(1.f) * RespawnDistanceAwayYRange;

	Handle NewPerson = BuildObject(GetInitialPlayerPilotODF(GetRaceOfTeam(Team), Team, true), Team, spawnpointPosition);

	// Pilot Invulnerability: respawned pilots can't be hurt until the timer runs out. -GBD
	if(m_PilotInvunerability > 0)
	{
		m_PilotInvTime[Team] = m_PilotInvunerability;
		m_SavedPilotInvHealth[Team] = GetMaxHealth(NewPerson);
		m_PilotInvUser[Team] = NewPerson;
		SetMaxHealth(NewPerson, 0);
	}

	SetAsUser(NewPerson, Team);
	AddPilotByHandle(NewPerson);
	SetRandomHeadingAngle(NewPerson);

	// If on team 0 (dedicated server team), make this object gone from the world
	if(!Team)
	{
		MakeInert(NewPerson);
	}

	return DLLHandled; // Dead pilots get handled by DLL
}

// Helper function for ObjectKilled/Sniped
EjectKillRetCodes Strategy02::DeadObject(int DeadObjectHandle, int KillersHandle, bool isDeadPerson, bool isDeadAI)
{
	// Get team number of the dead object
	const int deadObjectTeam = GetTeamNum(DeadObjectHandle);

	char ObjClass[MAX_ODF_LENGTH];
	GetObjInfo(DeadObjectHandle, Get_GOClass, ObjClass);
	const bool isTorpedo = (_stricmp(ObjClass, "CLASS_TORPEDO") == 0);

	if(deadObjectTeam == 0)
		return DoEjectPilot; // Someone on neutral team always gets default behavior

	// Powerups and torpedos don't count for anything. -GBD
	if(IsPowerup(DeadObjectHandle))
		return DoEjectPilot;
	if(isTorpedo)
		return DoEjectPilot;

	// An object is a player if it's a local or remotely-controlled player
	// (i.e. not AI)
	const bool deadObjectIsPlayer = IsPlayer(DeadObjectHandle);
	const bool killerObjectIsPlayer = IsPlayer(KillersHandle);

	const TEAMRELATIONSHIP relationship = GetTeamRelationship(DeadObjectHandle, KillersHandle);

	const int deadObjectScrapCost = GetActualScrapCost(DeadObjectHandle);

	// If the dead unit is directly controlled by a player (i.e. not
	// one of their AI units)
	if(deadObjectIsPlayer)
	{
		// Score goes down by the scrap cost of unit that died. (Not in Capture mode.)
		if(m_GameType != 4)
			AddScore(DeadObjectHandle, -int(floor(deadObjectScrapCost / 20.0f)));

		// Scoring: One death for players if they die as a pilot.
		if(isDeadPerson)
		{
			AddDeaths(DeadObjectHandle, 1);
		}
	}
	else
	{
		if(m_KillForAIKill)
			AddDeaths(DeadObjectHandle, 1);
		if((m_PointsForAIKill) && (m_GameType != 4))
			AddScore(DeadObjectHandle, -int(floor(deadObjectScrapCost / 20.0f)));
	}

	// If the killer was a human (directly, not via their AI units), then
	// they get a kill and some score points.
	if(killerObjectIsPlayer)
	{
		if((relationship == TEAMRELATIONSHIP_SAMETEAM) || 
		   (relationship == TEAMRELATIONSHIP_ALLIEDTEAM))
		{
			// Suicide: no kill, no score, no spawn-kill check. -GBD
			if(DeadObjectHandle != KillersHandle)
			{
				// Being a jerk to same or allied team loses a kill
				AddKills(KillersHandle, -1);
				// And killer loses score
				if(m_GameType != 4)
					AddScore(KillersHandle, -int(floor(deadObjectScrapCost / 10.0f)));
			}
		}
		else
		{
			AddKills(KillersHandle, 1);
			// And, bump their score by the scrap cost of what they just killed
			if(m_GameType != 4)
				AddScore(KillersHandle, int(floor(deadObjectScrapCost / 10.0f)));
		}
	}
	else
	{
		if((relationship == TEAMRELATIONSHIP_SAMETEAM) || 
		   (relationship == TEAMRELATIONSHIP_ALLIEDTEAM))
		{
			if(m_KillForAIKill)
				AddKills(KillersHandle, -1);
			if((m_PointsForAIKill) && (m_GameType != 4))
				AddScore(KillersHandle, -int(floor(deadObjectScrapCost / 10.0f)));
		}
		else
		{
			if(m_KillForAIKill)
				AddKills(KillersHandle, 1);
			if((m_PointsForAIKill) && (m_GameType != 4))
				AddScore(KillersHandle, int(floor(deadObjectScrapCost / 10.0f)));
		}
	}

	// Was this a spawn kill?
	// Spawnkill is a non-suicide, on a human by another human.  Added
	// check for !isDeadAI NM 11/25/06 - APC soldiers dying around the
	// same time as their human player would trip this up.
	const int spawnKillTime = MaxSpawnKillTime * m_GameTPS; // 15 seconds
	const bool isSpawnKill = (DeadObjectHandle != KillersHandle) && 
		(!isDeadAI) &&
		(deadObjectTeam > 0) && (deadObjectTeam < MAX_TEAMS) && 
		(m_SpawnedAtTime[deadObjectTeam] > 0) &&
		((m_ElapsedGameTime - m_SpawnedAtTime[deadObjectTeam]) < spawnKillTime);

	// If this was a spawnkill, register that on the killers score
	if(isSpawnKill)
	{
		sprintf_s(TempMsgString, "Spawn kill by %s on %s\n", 
				  GetPlayerName(KillersHandle), GetPlayerName(DeadObjectHandle));
		AddToMessagesBox(TempMsgString);
		AddScore(KillersHandle, -ScoreDecrementForSpawnKill);
	}

	// Check to see if we have a m_KillLimit winner
	if((m_KillLimit) && (GetKills(KillersHandle) >= m_KillLimit))
	{
		NoteGameoverByKillLimit(KillersHandle);
		DoGameover(10.0f);
	}

	if(isDeadAI)
	{
		// Snipe?
		if(isDeadPerson)
			return DLLHandled;
		else // Nope. Eject.
			return DoEjectPilot;
	}
	else  // Not DeadAI, i.e. a human!
	{
		if((m_IsMPI) && (deadObjectTeam > 0) && (deadObjectTeam < 11))
			DoTaunt(TAUNTS_HumanShipDestroyed);

		// If this was a dead pilot, we need to build another pilot back
		// at base. Otherwise, we just eject a pilot from the
		// craft. [This is strat, nobody gets a craft for free when they
		// lose one.]
		if(isDeadPerson)
			return RespawnPilot(DeadObjectHandle, deadObjectTeam);
		else 
			return DoEjectPilot;
	}
}

EjectKillRetCodes Strategy02::PlayerEjected(Handle DeadObjectHandle)
{
	if(!StopScript)
		LuaMission::PlayerEjected(DeadObjectHandle);

	int deadObjectTeam=GetTeamNum(DeadObjectHandle);
	if(deadObjectTeam==0)
		return DLLHandled; // Invalid team. Do nothing

	// Bailing out counts like a death to yourself (score only). -GBD
	return DeadObject(DeadObjectHandle, DeadObjectHandle, false, !IsPlayer(DeadObjectHandle));
}

EjectKillRetCodes Strategy02::ObjectKilled(int DeadObjectHandle, int KillersHandle)
{
	if(!StopScript)
		LuaMission::ObjectKilled(DeadObjectHandle, KillersHandle);

	const bool isDeadAI = !IsPlayer(DeadObjectHandle);
	const bool isDeadPerson = IsPerson(DeadObjectHandle);

	// Sanity check for multiworld
	if(GetCurWorld() != 0)
		return DoEjectPilot;

	// If a person died, respawn them, etc
	return DeadObject(DeadObjectHandle, KillersHandle, isDeadPerson, isDeadAI);
}

EjectKillRetCodes Strategy02::ObjectSniped(int DeadObjectHandle, int KillersHandle)
{
	if(!StopScript)
		LuaMission::ObjectSniped(DeadObjectHandle, KillersHandle);

	bool isDeadAI=!IsPlayer(DeadObjectHandle);

	if(GetCurWorld() != 0)
	{
		return DLLHandled;
	}

	// Dead person means we must always respawn a new person
	return DeadObject(DeadObjectHandle, KillersHandle, true, isDeadAI);
}

// Notification to the DLL: called when a pilot tries to enter an
// empty craft, and all other checks (i.e. craft is empty, masks
// match, etc) have passed. DLLs can prevent that pilot from entering
// the craft if desired.
//
// !! Note : If DLLs want to do any actions to the world based on this
// PreSnipe callback, they should (1) Ensure curWorld == 0 (lockstep)
// -- do NOTHING if curWorld is != 0, and (2) probably queue up an
// action to do in the next Execute() call.
PreGetInReturnCodes Strategy02::PreGetIn(const int curWorld, Handle pilotHandle, Handle emptyCraftHandle)
{
	if(curWorld != 0)
		return PREGETIN_ALLOW;

	PreGetInReturnCodes returnvalue = LuaMission::PreGetIn(curWorld, pilotHandle, emptyCraftHandle);

	// Is this an AI pilot getting into an allied craft? If so, change
	// the pilot's team to be the same as the craft, so that the craft
	// remains with its owning team. If a local or remotely-controlled
	// player tries to get in, behave as before.
	const TEAMRELATIONSHIP relationship = GetTeamRelationship(pilotHandle, emptyCraftHandle);
	if((relationship == TEAMRELATIONSHIP_ALLIEDTEAM) &&
	   (!IsPlayer(pilotHandle)) && (!m_SetThugPilotFlag))
	{
		SetTeamNum(pilotHandle, GetTeamNum(emptyCraftHandle));
	}

	// An invulnerable respawned pilot gives it up when they get in a ship. -GBD
	if(m_PilotInvUser[GetTeamNum(pilotHandle)] == pilotHandle)
	{
		SetMaxHealth(pilotHandle, m_SavedPilotInvHealth[GetTeamNum(pilotHandle)]);
		m_PilotInvTime[GetTeamNum(pilotHandle)] = 0;
	}

	// MPI: a CPU ship that gets a pilot joins the dispatcher. -GBD
	if((returnvalue == PREGETIN_ALLOW) && (m_IsMPI) && (GetTeamNum(emptyCraftHandle) > 10))
		AddToDispatch(emptyCraftHandle, 15.0f, false, 0, false);

	return returnvalue;
}

DLLBase *BuildMission(void)
{
	return new Strategy02;
}

// Thug Scavenger Management code. -GBD
// This code micro manages FFA Alliance Thug's Scavengers, and pilots, to ensure they get treated properly.
// Scavenger. Handles swapping Team from Thug to Commander when it deploys into a pool.
void Strategy02::ScavengerManagementCode(void)
{
	ThugScavengerList.erase(std::remove_if(ThugScavengerList.begin(), ThugScavengerList.end(), ShouldRemoveThugScavengerObject), ThugScavengerList.end());

	for (std::vector<ThugScavengerClass>::iterator iter = ThugScavengerList.begin(); iter != ThugScavengerList.end(); ++iter)
	{
		int Team = GetTeamNum(iter->ThugScavengerObject);
		// First off, is this a commander's team?
		if ((!m_ThugFlag[Team]) && (iter->ScavengerTeam != Team))
		{
			iter->ScavengerTeam = Team;
		}
		else if(!IsTeamplayOn()) // Thug team, handle scrap swapping.
		{
			int ScavScrap = GetScavengerCurScrap(iter->ThugScavengerObject);

			if (ScavScrap > 0)
			{
				int CurrScrap = GetScrap(iter->ScavengerTeam);
				int MaxScrap = GetMaxScrap(iter->ScavengerTeam);

				if ((CurrScrap + ScavScrap) > MaxScrap)
				{
					int TempCurrScrap = (MaxScrap - CurrScrap);
					int TempScavScrap = (ScavScrap - TempCurrScrap);

					AddScrap(iter->ScavengerTeam, TempCurrScrap);
					SetScavengerCurScrap(iter->ThugScavengerObject, TempScavScrap);
				}
				else
				{
					AddScrap(iter->ScavengerTeam, ScavScrap);
					SetScavengerCurScrap(iter->ThugScavengerObject, 0);
				}
			}

			if ((Team != iter->ScavengerTeam) && (IsDeployed(iter->ThugScavengerObject)))
				SetTeamNum(iter->ThugScavengerObject, iter->ScavengerTeam);
		}
	}

	ThugPilotList.erase(std::remove_if(ThugPilotList.begin(), ThugPilotList.end(), ShouldRemoveThugPilotObject), ThugPilotList.end());

	// Loop over Thug Pilots.
	for (std::vector<ThugPilotClass>::iterator iter = ThugPilotList.begin(); iter != ThugPilotList.end(); ++iter)
	{
		int Team = GetTeamNum(iter->ThugPilotObject);

		if ((m_ThugFlag[Team]) && (iter->SwitchTickTimer <= 0))
		{
			int CommanderTeamNum = 1;
			for (int x = 1; x<MAX_TEAMS; x++)
			{
				if ((m_AllyTeams[Team] == m_AllyTeams[x]) && (!m_ThugFlag[x]))
					CommanderTeamNum = x;
			}

			if (Team != CommanderTeamNum)
				SetTeamNum(iter->ThugPilotObject, CommanderTeamNum);
		}
		--iter->SwitchTickTimer;
	}
}

// ST: Capture game type. Stand next to a goal you're targeting for
// m_CaptureTime to take it; hold every goal (or m_KillLimit of them) to win. -GBD
void Strategy02::ExecuteST_Capture(void)
{
	bool Winner = false;

	for(int i = 1; i < MAX_TEAMS; i++)
	{
		UserTarget[i] = GetUserTarget(i);

		if(m_NumCaptureGoals < 1)
		{
			if(!m_GameOver)
			{
				AddToMessagesBox2("-- No Capture Goals! Game will be over very soon!", RGB(255, 255, 0));
				DoGameover(endDelta);
				m_GameOver = true;
			}
			continue;
		}

		for(int x = 0; x < m_NumCaptureGoals; x++)
		{
			char GoalODF[MAX_ODF_LENGTH];
			GetObjInfo(m_CaptureGoals[x], Get_ODF, GoalODF);

			if(IsAround(m_CaptureGoals[x]))
			{
				SetObjectiveOn(m_CaptureGoals[x]);
			}
			else // CaptureGoal is not around, remove it and shift the rest down.
			{
				for(int y = x; y < m_NumCaptureGoals - 1; y++)
				{
					m_CaptureGoals[y] = m_CaptureGoals[y+1];
					m_CaptureGoalTime[y] = m_CaptureGoalTime[y+1];
					m_CaptureGoalTeam[y] = m_CaptureGoalTeam[y+1];
					m_GoalBeingCaptured[y] = m_GoalBeingCaptured[y+1];
					m_CaptureGoalObjectify[y] = m_CaptureGoalObjectify[y+1];
					m_CaptureGoalIsSwitching[i][y] = m_CaptureGoalIsSwitching[i][y+1];
					m_DualCapture[y] = m_DualCapture[y+1];
				}
				m_NumCaptureGoals--;
				x--; // (As shipped: the rest of this pass runs on the previous slot.)
			}

			if(IsAround(m_CaptureGoals[x]))
			{
				Handle TempP = GetPlayerHandle(i);

				// Dual capture: two enemies at the same goal cancel each other out.
				bool Flagoff = false;
				for(int t = 1; t < MAX_TEAMS; t++)
				{
					Handle TempP2 = GetPlayerHandle(t);
					if((t != i) && (!IsTeamAllied(i, t)) && (UserTarget[i] == m_CaptureGoals[x]) && (UserTarget[t] == m_CaptureGoals[x]) &&
						(GetDistance(m_CaptureGoals[x], TempP) < 100.0f) && (GetDistance(m_CaptureGoals[x], TempP2) < 100.0f))
					{
						SetTeamNum(m_CaptureGoals[x], m_CaptureGoalTeam[x]); // Restore to previous team
						Flagoff = true;
						break;
					}
				}
				if(Flagoff)
				{
					if(!m_DualCapture[x])
						m_DualCapture[x] = true;
				}
				else
					m_DualCapture[x] = false;

				// Capture procedures
				if((UserTarget[i] == m_CaptureGoals[x]) && (m_CaptureGoalTeam[x] != i) &&
					((m_CaptureGoalTeam[x] == 0) || (!IsTeamAllied(m_CaptureGoalTeam[x], i))) &&
					((m_GoalBeingCaptured[x] == 0) || (m_GoalBeingCaptured[x] == i)) &&
					(GetDistance(m_CaptureGoals[x], TempP) < 100.0f))
				{
					if(m_GoalBeingCaptured[x] == 0)
					{
						sprintf_s(TempMsgString, "-- A Goal is being Captured by %s!", GetPlayerName(GetPlayerHandle(i)));
						AddToMessagesBox2(TempMsgString, RGB(255, 255, 0));
					}

					m_CaptureGoalIsSwitching[i][x] = true;

					if(!m_DualCapture[x])
						m_CaptureGoalTime[x]++;

					m_GoalBeingCaptured[x] = i;
					m_TeamIsCapturing[i] = true;

					int TotalCaptureTime = (m_CaptureTime - m_CaptureGoalTime[x]) / m_GameTPS;
					if(GetLocalPlayerTeamNumber() == i)
						StartCockpitTimer(TotalCaptureTime, long(floor(double(TotalCaptureTime / 2))), long(floor(double(TotalCaptureTime / 4))));

					// Flash the goal between the capturing team and its owner.
					if((m_CaptureGoalTime[x] % m_GameTPS) == 0)
					{
						if(!m_CaptureGoalObjectify[x])
						{
							SetTeamNum(m_CaptureGoals[x], i);
							SetObjectiveOn(m_CaptureGoals[x]);
							m_CaptureGoalObjectify[x] = true;
						}
						else
						{
							SetTeamNum(m_CaptureGoals[x], m_CaptureGoalTeam[x]);
							SetObjectiveOff(m_CaptureGoals[x]);
							m_CaptureGoalObjectify[x] = false;
						}
					}

					if(m_CaptureGoalTime[x] == m_CaptureTime) // Captured!
					{
						if(m_CaptureGoalTeam[x] != 0)
							AddScore(GetPlayerHandle(m_CaptureGoalTeam[x]), -1);

						Handle OldPlayer = GetPlayerHandle(m_CaptureGoalTeam[x]);

						m_CaptureGoalTeam[x] = i;
						SetTeamNum(m_CaptureGoals[x], i);
						for(int v = 0; v < 8; v++)
						{
							Handle TempTap = GetTap(m_CaptureGoals[x], v);
							if(TempTap)
								SetTeamNum(TempTap, i);
						}

						AddScore(GetPlayerHandle(i), 1);
						m_GoalBeingCaptured[x] = 0;

						if(GetLocalPlayerTeamNumber() == i)
						{
							StopCockpitTimer();
							HideCockpitTimer();
						}

						SetObjectiveOff(m_CaptureGoals[x]);
						m_CaptureGoalTime[x] = 0;
						m_CaptureGoalIsSwitching[i][x] = false;
						m_TeamIsCapturing[i] = false;

						if(OldPlayer == 0)
							sprintf_s(TempMsgString, "-- %s Captured a Goal!", GetPlayerName(GetPlayerHandle(i)));
						else
							sprintf_s(TempMsgString, "-- %s Captured a Goal from %s!", GetPlayerName(GetPlayerHandle(i)), GetPlayerName(OldPlayer));
						AddToMessagesBox2(TempMsgString, RGB(255, 255, 0));
					}
					break; // One goal at a time.
				}
				else if(m_CaptureGoalIsSwitching[i][x]) // Walked away, reset it.
				{
					m_GoalBeingCaptured[x] = 0;
					m_CaptureGoalTime[x] = 0;
					SetTeamNum(m_CaptureGoals[x], m_CaptureGoalTeam[x]);

					if(GetLocalPlayerTeamNumber() == i)
					{
						StopCockpitTimer();
						HideCockpitTimer();
					}

					if(UserTarget[i] == m_CaptureGoals[x])
						SetTarget(GetPlayerHandle(i), 0);

					m_CaptureGoalIsSwitching[i][x] = false;
					m_TeamIsCapturing[i] = false;
				}
			}
		}

		// Look for a winner
		if(m_KillLimit == 0)
		{
			Winner = true;
			for(int t = 0; t < m_NumCaptureGoals; t++)
			{
				if((m_GoalBeingCaptured[t] != 0) || (m_CaptureGoalTeam[t] == 0) || (m_CaptureGoalTeam[t] != i) || (!IsTeamAllied(i, m_CaptureGoalTeam[t])))
				{
					Winner = false;
					break;
				}
			}
		}
		else
		{
			if(GetScore(GetPlayerHandle(i)) >= m_KillLimit)
				Winner = true;
		}

		if(!Winner)
			continue;

		if(!m_GameOver)
		{
			if(!IsTeamplayOn())
			{
				if(!m_HasAllies[i])
				{
					if(m_KillLimit == 0)
						sprintf_s(TempMsgString, "-- %s has won! Captured All Goals!", GetPlayerName(m_RecyclerHandles[i]));
					else
						sprintf_s(TempMsgString, "-- %s has won! Captured %d Goals!", GetPlayerName(m_RecyclerHandles[i]), m_KillLimit);
					AddScore(GetPlayerHandle(i), ScoreForWinning);
					NoteGameoverByScore(GetPlayerHandle(i));
				}
				else
				{
					if(m_KillLimit == 0)
						sprintf_s(TempMsgString, "-- Team %d has won! Captured All Goals!", m_AllyTeams[i]);
					else
						sprintf_s(TempMsgString, "-- Team %d has won! Captured %d Goals!", m_AllyTeams[i], m_KillLimit);
					AddScore(GetPlayerHandle(i), ScoreForWinning);
					NoteGameoverWithCustomMessage(TempMsgString);
				}
				AddToMessagesBox2(TempMsgString, RGB(255, 255, 0));
				DoGameover(endDelta);
				m_GameOver = true;
			}
			else
			{
				int WinningTeamgroup = WhichTeamGroup(i);
				if(m_KillLimit == 0)
					sprintf_s(TempMsgString, "-- Team %d has won! Captured all Goals!", WinningTeamgroup + 1);
				else
					sprintf_s(TempMsgString, "-- Team %d has won! Captured %d Goals!", WinningTeamgroup + 1, m_KillLimit);
				AddScore(GetPlayerHandle(i), ScoreForWinning);
				NoteGameoverWithCustomMessage(TempMsgString);

				// Also, give all players on winning team points...
				for(int k = 0; k < MAX_TEAMS; k++)
				{
					if(WhichTeamGroup(k) == WinningTeamgroup)
						AddScore(GetPlayerHandle(k), ScoreForWinning);
				}
				AddToMessagesBox2(TempMsgString, RGB(255, 255, 0));
				DoGameover(endDelta);
				m_GameOver = true;
			}
		}
	}
}
