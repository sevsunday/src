// PROVENANCE: ancestor reference/ancestor-bz1helper-2015/Shared/BZ1Helper.h @6fda4f5 (comments, accessors, default arguments) | declarations + layouts original/missions/Strategy02.pdb via tools/pdb_types.py (MapInfo 0x48, TeamInfo 0xa14, BZ1Helper 0xa428, 26-slot vtable); operator== / ShouldRemove* from reference/decompiled/strategy02-ghidra12.2/src/missions/vsrcore/bz1helper.h.decomp.c (lines 105-1277) | status: ported
#ifndef _BZ1Helper_
#define _BZ1Helper_

# pragma once

#include "dllbase.h"
#include "ScriptUtils.h"
#include "bzcscriptutils.h"
#include "objecthelper.h"
#include "vehiclehelper.h"
#include "buildinghelper.h"
#include "portalhelper.h"
#include <vector>
#include <utility>

//BZC Additions by GSH, adapted by Avatar. Modified extensively by GBD.

// forward declarations
class ProductionClassHelper;
class PowerHelper;
class PowerupHelper;
class AttacherHelper;
class UtilityShipHelper;
class ScrapHelper;
class DispatchHelper;
class UndeployHelper;
class AIWeaponHelper;
class MorphObjectHelper;
class CarrierHelper;
class GravityHelper;
class AmbientSoundHelper;

// Counts the PDB only carries as array bounds (names are ours).
#define MAX_BASE_SLOTS 9 // Recycler / factory / armory / constructor build-list slots a team tracks.
#define MAX_BASE_SLOT_ITEMS 10 // Build items per slot.

// Event VO ids (PlayEventVO's Event argument; `<race>event.odf` [BettyVoice] EVENT_SOUND_%d).
enum EventODFIDs {
	EVENT_ID_NONE = 0,
	EVENT_ID_GENERIC_UNIT_LOST = 1,
	EVENT_ID_DEFENSIVE_UNIT_LOST = 2,
	EVENT_ID_OFFENSIVE_UNIT_LOST = 3,
	EVENT_ID_SCAVENGER_LOST = 4,
	EVENT_ID_UNIT_AMMO_DEPLETED = 5,
	EVENT_ID_BASE_UNDER_ATTACK = 6,
	EVENT_ID_USER_AMMO_DEPLETED = 7,
	EVENT_ID_UNIT_HEALTH_LOW = 8,
	EVENT_ID_USER_HEALTH_LOW = 9,
	EVENT_ID_SATELLITE_ACTIVATED = 10,
	EVENT_ID_LOST_POWERPLANT = 11,
	EVENT_ID_PILOTS_DEPLETED = 12,
	EVENT_ID_SATELLITE_ENABLED = 13,
	EVENT_ID_BUILDING_LOST = 14,
	EVENT_ID_SATELLITE_DEACTIVATED = 15,
	EVENT_ID_SATELLITE_DISABLED = 16,
};

class BZ1Helper : public DLLBase {
	friend struct VsrLayoutCheck_BZ1Helper; // scaffold: QA gate 2 hook (layout asserts); not GBD's

public:

	// General map info.
	struct MapInfo {
		friend struct VsrLayoutCheck_BZ1Helper__MapInfo; // scaffold: QA gate 2 hook (layout asserts); not GBD's
		float Height;
		float MapWidth;
		float MapDepth;
		float MPG;
		float HeightGranularity;
		float MinX;
		float MinZ;
		float MaxWidth;
		float MaxDepth;
		float MinWidth;
		float MinDepth;
		float Gravity;
		int GravityState;
		float MinScrapHeight;
		float MaxScrapHeight;
		bool RestrictAllScrap; // Keep every scrap piece inside the Min/Max scrap height band, not just the restricted ODFs.
		bool RespawnAtLowAltitude;
		float SpawnMinRadius;
		float SpawnMaxRadius;

		MapInfo() { memset(this, 0, sizeof(MapInfo)); };

		// GBD: member-by-member compare for Load's resync report; the first difference is logged and ends the compare.
		friend bool operator==(const MapInfo &a, const MapInfo &b)
		{
			if (a.Height != b.Height) { FormatLogMessage("MAPINFO MISMATCH: Height: %f and %f", a.Height, b.Height); return false; }
			if (a.MapWidth != b.MapWidth) { FormatLogMessage("MAPINFO MISMATCH: MapWidth: %f and %f", a.MapWidth, b.MapWidth); return false; }
			if (a.MapDepth != b.MapDepth) { FormatLogMessage("MAPINFO MISMATCH: MapDepth: %f and %f", a.MapDepth, b.MapDepth); return false; }
			if (a.MPG != b.MPG) { FormatLogMessage("MAPINFO MISMATCH: MPG: %f and %f", a.MPG, b.MPG); return false; }
			if (a.HeightGranularity != b.HeightGranularity) { FormatLogMessage("MAPINFO MISMATCH: HeightGranularity: %f and %f", a.HeightGranularity, b.HeightGranularity); return false; }
			if (a.MinX != b.MinX) { FormatLogMessage("MAPINFO MISMATCH: MinX: %f and %f", a.MinX, b.MinX); return false; }
			if (a.MinZ != b.MinZ) { FormatLogMessage("MAPINFO MISMATCH: MinZ: %f and %f", a.MinZ, b.MinZ); return false; }
			if (a.MaxWidth != b.MaxWidth) { FormatLogMessage("MAPINFO MISMATCH: MaxWidth: %f and %f", a.MaxWidth, b.MaxWidth); return false; }
			if (a.MaxDepth != b.MaxDepth) { FormatLogMessage("MAPINFO MISMATCH: MaxDepth: %f and %f", a.MaxDepth, b.MaxDepth); return false; }
			if (a.MinWidth != b.MinWidth) { FormatLogMessage("MAPINFO MISMATCH: MinWidth: %f and %f", a.MinWidth, b.MinWidth); return false; }
			if (a.MinDepth != b.MinDepth) { FormatLogMessage("MAPINFO MISMATCH: MinDepth: %f and %f", a.MinDepth, b.MinDepth); return false; }
			if (a.Gravity != b.Gravity) { FormatLogMessage("MAPINFO MISMATCH: Gravity: %f and %f", a.Gravity, b.Gravity); return false; }
			if (a.MinScrapHeight != b.MinScrapHeight) { FormatLogMessage("MAPINFO MISMATCH: MinScrapHeight: %f and %f", a.MinScrapHeight, b.MinScrapHeight); return false; }
			if (a.MaxScrapHeight != b.MaxScrapHeight) { FormatLogMessage("MAPINFO MISMATCH: MaxScrapHeight: %f and %f", a.MaxScrapHeight, b.MaxScrapHeight); return false; }
			if (a.RestrictAllScrap != b.RestrictAllScrap) { FormatLogMessage("MAPINFO MISMATCH: RestrictAllScrap: %d and %d", a.RestrictAllScrap, b.RestrictAllScrap); return false; }
			if (a.RespawnAtLowAltitude != b.RespawnAtLowAltitude) { FormatLogMessage("MAPINFO MISMATCH: RespawnAtLowAltitude: %d and %d", a.RespawnAtLowAltitude, b.RespawnAtLowAltitude); return false; }
			if (a.SpawnMinRadius != b.SpawnMinRadius) { FormatLogMessage("MAPINFO MISMATCH: SpawnMinRadius: %f and %f", a.SpawnMinRadius, b.SpawnMinRadius); return false; }
			if (a.SpawnMaxRadius != b.SpawnMaxRadius) { FormatLogMessage("MAPINFO MISMATCH: SpawnMaxRadius: %f and %f", a.SpawnMaxRadius, b.SpawnMaxRadius); return false; }
			if (a.GravityState != b.GravityState) { FormatLogMessage("MAPINFO MISMATCH: GravityState: %d and %d", a.GravityState, b.GravityState); return false; }
			return true;
		}
	};

	// Store team based data. This is where we put all of our [MAX_TEAM] entries together.
	struct TeamInfo {
		friend struct VsrLayoutCheck_BZ1Helper__TeamInfo; // scaffold: QA gate 2 hook (layout asserts); not GBD's
		// Player stuff.
		Handle RealPlayer; // Keep track of what the player actually is (because of satellite mode). 
		Handle Player; // Store a player's ship if they're in satellite. NOTE: This is ONLY used in Satellite Code!
		Handle SatellitePlayer; // Sat Object for the player. 
		// This Team's production units.
		Handle Recycler;
		Handle Factory;
		Handle Armory;
		Handle Constructor;
		// VSR: the base's build-list slots and their off-map scrap holds.
		Handle BaseSlot[MAX_BASE_SLOTS];
		Handle BaseSlotScrap[MAX_BASE_SLOTS]; // OFF MAP!
		// Satellite stuff.
		Handle CommTower; // Save the Primary Selectable CommTower. -GBD
		Handle SatelliteOn; // Satellite! OFF MAP!
		Handle SatelliteOff; // Satellite! // OFF MAP!
		Handle SatelliteLock; // Satellite! // OFF MAP!
		Handle SatelliteLastShooter;
		// Limiter Stuff
		Handle ImaPilot; // Pilot Locker. // OFF MAP!
		Handle Transport; 
		Handle LimiterObject[3]; // For limits. Yay! // OFF MAP!
		Handle LimitPlayer; // For limit code.
		// This Team's Resources.
		int MaxPilots; // Max pilot count.
		int CurrPilots; // Current pilot count.
		// AI Stuff.
		int m_CPUAIDifficulty; // Difficulty, 0 = none, 1 = Easy, 2 = Medium, 3 = Hard, 4 = Extreme.
		int m_CPUPilotCheatAmount; // Pilot cheat from AIP file, just like their money cheat. 
		int m_CPUMaxPatrolUnits; // Max Number of Patrol units to have.
		int m_CPUMaxHuntUnits; // Max Number of Hunt units to have.
		int m_CPUMaxEscortUnits; // Max Number of Escort units to have.
		int m_CPUNumPatrolUnits; // Number of Patrol units.
		int m_CPUNumHuntUnits; // Number of Hunt units.
		int m_CPUNumEscortUnits; // Number of Escort units.
		// Counts.
		int ReinforcementCount; // Transport timer per Team.
		int NumBarracks; // Check number of Barracks. -GBD
		int NumTeamObjects; // Total number of items on this team.
		// Satellite mode switches.
		int SatelliteViewActive; // Store if satellite is on/off for deactivation/cleaning up. Multi Stage flag. -GBD
		int SatelliteOutOfAmmo; // Counter to delay Satellite deactivation some.
		long SatelliteSiteCamAmmo; // How much Ammo the SiteCam requires.
		int SatellitePrevIndependence;
		// Player Lives stuff.
		int PlayerLives; // How many lives are remaining.
		int RespawnTime;
		// Scavenger drop-off buildings alive on this team (UtilityShipHelper reads them).
		int DropoffRecylcers;
		int DropoffExtractors;
		int DropoffSilos;
		int BaseSlotBuildCount[MAX_BASE_SLOTS];
		// Bools
		bool PlayedScrapDropVO;
		bool TeamIsDead; // Is this player's team out of lives?
		bool RespawnPlayer;
		bool m_UsePilots; // Flag to pop it up with the recy. -GBD
		bool m_HadPilots; // Flag to flag if we once Used Pilots, to tell if we play "pilots depleted" or not. -GBD
		bool m_UseLimits; // Does it use BZ1 Limits? 
		bool NoPlayerPilot;
		bool TookControlThisTurn; // Remote control (VehicleHelper) already moved this team's player this tick.
		bool BaseSlotUseScrapHold[MAX_BASE_SLOTS];
		// AI Stuff.
		bool m_CPUUnitsCanService; // Tells if this AI's units automatically Repair/Reload.
		bool m_CPUDoDispatch; // Flag if AIP does Dispatching.
		// Satellite Stuff.
		bool CommTowerAround; // Get a flag as to if the team has any commtowers. -GBD
		bool PlayerWasPilot; // Save this, or else DIE!!!!
		bool GiveBackWeapons; // Flag to restore a pilot's weapons, if they picked some up.
		bool PlayCommTowerSound; // Flag to play CommTower sound.
		bool UseSiteCamera; // Flag to use site camera or not?
		bool SatelliteObjectify;
		// Floats
		float m_CPUDayWreckerChance; // Chance for dayWeckerage.
		float m_CPUDayWreckerInterval;
		float m_CPUPilotCheatDelay; // Interval of the pilot cheat.
		float m_CPUBuildingRepairChance;
		float m_CPUBuildingRepairInterval;
		float m_CPUBuildingRepairHealthRatio;
		float m_CPUBuildPodMinDelay;
		float m_CPUBuildPodMaxDelay;
		Vector PlayerSpawnPos; // Store the Team's Spawn Vector.
		Vector ReinforcementPos; // Store the Reinforcement Spawn Vector.
		Vector GoalPos; // Store the team's CTF Goal position Vector.
		// Chars
		char TeamRace; // Race.
		char ArmoryBuildClass[MAX_ODF_LENGTH];
		char PlayerName[MAX_ODF_LENGTH];
		char TeamAIPFile[MAX_NAME_LENGTH];
		char PilotWeapon[MAX_HARDPOINTS][MAX_ODF_LENGTH];
		char PlayerPilotODF[MAX_ODF_LENGTH];
		char SatelliteODF[MAX_ODF_LENGTH];
		char BaseSlotName[MAX_BASE_SLOTS][MAX_ODF_LENGTH];
		int BaseSlotPilotCost[MAX_BASE_SLOTS][MAX_BASE_SLOT_ITEMS];
		int BaseSlotScrapCost[MAX_BASE_SLOTS][MAX_BASE_SLOT_ITEMS];
		bool ShowPilotCosts[MAX_BASE_SLOTS];
		int BaseSlotPlayingAnim[MAX_BASE_SLOTS];
		float BaseSlotAnimationFrames[MAX_BASE_SLOTS];

		// This converts all the Handles. (RealPlayer .. LimitPlayer are contiguous: 36 handles, as PostLoad's ConvertHandles(&RealPlayer, 0x24) shows.)
		void ConvertHandles() { ::ConvertHandles( &RealPlayer, &LimitPlayer - &RealPlayer + 1); }

		TeamInfo() { memset(this, 0, sizeof(TeamInfo)); };

		// GBD: member-by-member compare for Load's resync report; the first difference is logged and ends the compare.
		// Message quirks kept for parity: the m_CPU* floats after the day-wrecker pair print with %d, TeamRace prints as "MaxPilots: %c and %c".
		friend bool operator==(const TeamInfo &a, const TeamInfo &b)
		{
			char ODFNameA[MAX_ODF_LENGTH] = { 0 };
			char ODFNameB[MAX_ODF_LENGTH] = { 0 };
#define VSR_TEAMINFO_HANDLE(field, label) \
			if (a.field != b.field) { GetODFName(a.field, ODFNameA); GetODFName(b.field, ODFNameB); FormatLogMessage("TEAMINFO MISMATCH: " label ": %08x '%s' and %08x '%s'", a.field, ODFNameA, b.field, ODFNameB); return false; }
#define VSR_TEAMINFO_INT(field) \
			if (a.field != b.field) { FormatLogMessage("TEAMINFO MISMATCH: " #field ": %d and %d", a.field, b.field); return false; }
#define VSR_TEAMINFO_FLOAT(field) \
			if (a.field != b.field) { FormatLogMessage("TEAMINFO MISMATCH: " #field ": %f and %f", a.field, b.field); return false; }
#define VSR_TEAMINFO_VECTOR(field) \
			if (a.field != b.field) { FormatLogMessage("TEAMINFO MISMATCH: " #field ": %f %f %f and %f %f %f", a.field.x, a.field.y, a.field.z, b.field.x, b.field.y, b.field.z); return false; }
#define VSR_TEAMINFO_STRING(field) \
			if (_stricmp(a.field, b.field)) { FormatLogMessage("TEAMINFO MISMATCH: " #field ": '%s' and '%s'", a.field, b.field); return false; }
			// Handles
			VSR_TEAMINFO_HANDLE(RealPlayer, "RealPlayer")
			VSR_TEAMINFO_HANDLE(Player, "Player")
			VSR_TEAMINFO_HANDLE(SatellitePlayer, "SatellitePlayer")
			VSR_TEAMINFO_HANDLE(Recycler, "Recycler")
			VSR_TEAMINFO_HANDLE(Factory, "Factory")
			VSR_TEAMINFO_HANDLE(Armory, "Armory")
			VSR_TEAMINFO_HANDLE(Constructor, "Constructor")
			for (int i = 0; i < MAX_BASE_SLOTS; i++)
			{
				if (a.BaseSlot[i] != b.BaseSlot[i]) { GetODFName(a.BaseSlot[i], ODFNameA); GetODFName(b.BaseSlot[i], ODFNameB); FormatLogMessage("TEAMINFO MISMATCH: BaseSlot: %d, %08x '%s' and %08x '%s'", i, a.BaseSlot[i], ODFNameA, b.BaseSlot[i], ODFNameB); return false; }
				if (a.BaseSlotScrap[i] != b.BaseSlotScrap[i]) { GetODFName(a.BaseSlotScrap[i], ODFNameA); GetODFName(b.BaseSlotScrap[i], ODFNameB); FormatLogMessage("TEAMINFO MISMATCH: BaseSlotScrap: %d, %08x '%s' and %08x '%s'", i, a.BaseSlotScrap[i], ODFNameA, b.BaseSlotScrap[i], ODFNameB); return false; }
			}
			VSR_TEAMINFO_HANDLE(CommTower, "CommTower")
			VSR_TEAMINFO_HANDLE(SatelliteOn, "SatelliteOn")
			VSR_TEAMINFO_HANDLE(SatelliteOff, "SatelliteOff")
			VSR_TEAMINFO_HANDLE(SatelliteLock, "SatelliteLock")
			VSR_TEAMINFO_HANDLE(SatelliteLastShooter, "SatelliteLastShooter")
			VSR_TEAMINFO_HANDLE(ImaPilot, "ImaPilot")
			VSR_TEAMINFO_HANDLE(Transport, "Transport")
			for (int i = 0; i < 3; i++)
			{
				if (a.LimiterObject[i] != b.LimiterObject[i]) { GetODFName(a.LimiterObject[i], ODFNameA); GetODFName(b.LimiterObject[i], ODFNameB); FormatLogMessage("TEAMINFO MISMATCH: LimiterObject: %d, %08x '%s' and %08x '%s'", i, a.LimiterObject[i], ODFNameA, b.LimiterObject[i], ODFNameB); return false; }
			}
			VSR_TEAMINFO_HANDLE(LimitPlayer, "LimitPlayer")
			// Ints.
			VSR_TEAMINFO_INT(MaxPilots)
			VSR_TEAMINFO_INT(CurrPilots)
			VSR_TEAMINFO_INT(m_CPUAIDifficulty)
			VSR_TEAMINFO_INT(m_CPUPilotCheatAmount)
			VSR_TEAMINFO_INT(m_CPUMaxPatrolUnits)
			VSR_TEAMINFO_INT(m_CPUMaxHuntUnits)
			VSR_TEAMINFO_INT(m_CPUMaxEscortUnits)
			VSR_TEAMINFO_INT(m_CPUNumPatrolUnits)
			VSR_TEAMINFO_INT(m_CPUNumHuntUnits)
			VSR_TEAMINFO_INT(m_CPUNumEscortUnits)
			VSR_TEAMINFO_INT(ReinforcementCount)
			VSR_TEAMINFO_INT(NumBarracks)
			VSR_TEAMINFO_INT(NumTeamObjects)
			VSR_TEAMINFO_INT(SatelliteViewActive)
			VSR_TEAMINFO_INT(SatelliteOutOfAmmo)
			VSR_TEAMINFO_INT(SatelliteSiteCamAmmo)
			VSR_TEAMINFO_INT(SatellitePrevIndependence)
			VSR_TEAMINFO_INT(PlayerLives)
			VSR_TEAMINFO_INT(RespawnTime)
			VSR_TEAMINFO_INT(DropoffRecylcers)
			VSR_TEAMINFO_INT(DropoffExtractors)
			VSR_TEAMINFO_INT(DropoffSilos)
			for (int i = 0; i < MAX_BASE_SLOTS; i++)
			{
				if (a.BaseSlotBuildCount[i] != b.BaseSlotBuildCount[i]) { FormatLogMessage("TEAMINFO MISMATCH: BaseSlotBuildCount: %d and %d", a.BaseSlotBuildCount[i], b.BaseSlotBuildCount[i]); return false; }
			}
			// Bools
			VSR_TEAMINFO_INT(PlayedScrapDropVO)
			VSR_TEAMINFO_INT(TeamIsDead)
			VSR_TEAMINFO_INT(RespawnPlayer)
			VSR_TEAMINFO_INT(m_UsePilots)
			VSR_TEAMINFO_INT(m_HadPilots)
			VSR_TEAMINFO_INT(m_UseLimits)
			VSR_TEAMINFO_INT(NoPlayerPilot)
			VSR_TEAMINFO_INT(TookControlThisTurn)
			for (int i = 0; i < MAX_BASE_SLOTS; i++)
			{
				if (a.BaseSlotUseScrapHold[i] != b.BaseSlotUseScrapHold[i]) { FormatLogMessage("TEAMINFO MISMATCH: BaseSlotUseScrapHold:, %d, %d and %d", i, a.BaseSlotUseScrapHold[i], b.BaseSlotUseScrapHold[i]); return false; }
			}
			VSR_TEAMINFO_INT(m_CPUUnitsCanService)
			VSR_TEAMINFO_INT(m_CPUDoDispatch)
			VSR_TEAMINFO_INT(CommTowerAround)
			VSR_TEAMINFO_INT(PlayerWasPilot)
			VSR_TEAMINFO_INT(GiveBackWeapons)
			VSR_TEAMINFO_INT(PlayCommTowerSound)
			VSR_TEAMINFO_INT(UseSiteCamera)
			VSR_TEAMINFO_INT(SatelliteObjectify)
			// Floats
			VSR_TEAMINFO_FLOAT(m_CPUDayWreckerChance)
			VSR_TEAMINFO_FLOAT(m_CPUDayWreckerInterval)
			VSR_TEAMINFO_INT(m_CPUPilotCheatDelay) // sic: %d
			VSR_TEAMINFO_INT(m_CPUBuildingRepairChance) // sic: %d
			VSR_TEAMINFO_INT(m_CPUBuildingRepairInterval) // sic: %d
			VSR_TEAMINFO_INT(m_CPUBuildingRepairHealthRatio) // sic: %d
			VSR_TEAMINFO_INT(m_CPUBuildPodMinDelay) // sic: %d
			VSR_TEAMINFO_INT(m_CPUBuildPodMaxDelay) // sic: %d
			// Vector
			VSR_TEAMINFO_VECTOR(PlayerSpawnPos)
			VSR_TEAMINFO_VECTOR(ReinforcementPos)
			VSR_TEAMINFO_VECTOR(GoalPos)
			// Char
			if (a.TeamRace != b.TeamRace) { FormatLogMessage("TEAMINFO MISMATCH: MaxPilots: %c and %c", a.TeamRace, b.TeamRace); return false; } // sic: label
			// Char arrays.
			VSR_TEAMINFO_STRING(ArmoryBuildClass)
			VSR_TEAMINFO_STRING(PlayerName)
			VSR_TEAMINFO_STRING(TeamAIPFile)
			for (int i = 0; i < MAX_HARDPOINTS; i++)
			{
				if (_stricmp(a.PilotWeapon[i], b.PilotWeapon[i])) { FormatLogMessage("TEAMINFO MISMATCH: PilotWeapon: %d, '%s' and '%s'", i, a.PilotWeapon[i], b.PilotWeapon[i]); return false; }
			}
			VSR_TEAMINFO_STRING(PlayerPilotODF)
			VSR_TEAMINFO_STRING(SatelliteODF)
			for (int i = 0; i < MAX_BASE_SLOTS; i++)
			{
				if (_stricmp(a.BaseSlotName[i], b.BaseSlotName[i])) { FormatLogMessage("TEAMINFO MISMATCH: BaseSlotName%d: '%s' and '%s'", i, a.BaseSlotName[i], b.BaseSlotName[i]); return false; }
			}
			for (int i = 0; i < MAX_BASE_SLOTS; i++)
			{
				for (int j = 0; j < MAX_BASE_SLOT_ITEMS; j++)
				{
					if (a.BaseSlotPilotCost[i][j] != b.BaseSlotPilotCost[i][j]) { FormatLogMessage("TEAMINFO MISMATCH: BaseSlotPilotCost%d_%d: %d and %d", i, j, a.BaseSlotPilotCost[i][j], b.BaseSlotPilotCost[i][j]); return false; }
					if (a.BaseSlotScrapCost[i][j] != b.BaseSlotScrapCost[i][j]) { FormatLogMessage("TEAMINFO MISMATCH: BaseSlotScrapCost%d_%d: %d and %d", i, j, a.BaseSlotScrapCost[i][j], b.BaseSlotScrapCost[i][j]); return false; }
				}
				if (a.ShowPilotCosts[i] != b.ShowPilotCosts[i]) { FormatLogMessage("TEAMINFO MISMATCH: ShowPilotCosts%d: %d and %d", i, a.ShowPilotCosts[i], b.ShowPilotCosts[i]); return false; }
				if (a.BaseSlotPlayingAnim[i] != b.BaseSlotPlayingAnim[i]) { FormatLogMessage("TEAMINFO MISMATCH: BaseSlotPlayingAnim: %d and %d", a.BaseSlotPlayingAnim[i], b.BaseSlotPlayingAnim[i]); return false; }
				if (a.BaseSlotAnimationFrames[i] != b.BaseSlotAnimationFrames[i]) { FormatLogMessage("TEAMINFO MISMATCH: BaseSlotAnimationFrames: %f and %f", a.BaseSlotAnimationFrames[i], b.BaseSlotAnimationFrames[i]); return false; }
			}
#undef VSR_TEAMINFO_HANDLE
#undef VSR_TEAMINFO_INT
#undef VSR_TEAMINFO_FLOAT
#undef VSR_TEAMINFO_VECTOR
#undef VSR_TEAMINFO_STRING
			return true;
		}
	};

	// Align Terrain Replace objects.
	struct AlignTerrainReplaceClass {
		friend struct VsrLayoutCheck_BZ1Helper__AlignTerrainReplaceClass; // scaffold: QA gate 2 hook (layout asserts); not GBD's
		Handle AlignHandle; // The handle.
		Vector NormalVec; // Normals for TerrainReplace.

		AlignTerrainReplaceClass() { memset(this, 0, sizeof(AlignTerrainReplaceClass)); };

		friend bool operator==(const AlignTerrainReplaceClass &a, const AlignTerrainReplaceClass &b)
		{
			if (a.AlignHandle != b.AlignHandle)
			{
				char ODFNameA[MAX_ODF_LENGTH] = { 0 };
				char ODFNameB[MAX_ODF_LENGTH] = { 0 };
				GetODFName(a.AlignHandle, ODFNameA);
				GetODFName(b.AlignHandle, ODFNameB);
				FormatLogMessage("ALIGNTERRAINREPLACE MISMATCH: AlignHandle: %08x '%s' and %08x '%s'", a.AlignHandle, ODFNameA, b.AlignHandle, ODFNameB);
				return false;
			}
			if (a.NormalVec != b.NormalVec)
			{
				FormatLogMessage("ALIGNTERRAINREPLACE MISMATCH: NormalVec: %f %f %f and %f %f %f", a.NormalVec.x, a.NormalVec.y, a.NormalVec.z, b.NormalVec.x, b.NormalVec.y, b.NormalVec.z);
				return false;
			}
			return true;
		}
	};

	// Delete on Load objects.
	struct DeleteAfterDelayClass {
		friend struct VsrLayoutCheck_BZ1Helper__DeleteAfterDelayClass; // scaffold: QA gate 2 hook (layout asserts); not GBD's
		Handle DeleteAfterDelayHandle; // The handle.
		int TurnsRemaining; // How many turns left until it's deletion.

		DeleteAfterDelayClass() { memset(this, 0, sizeof(DeleteAfterDelayClass)); };

		friend bool operator==(const DeleteAfterDelayClass &a, const DeleteAfterDelayClass &b)
		{
			if (a.DeleteAfterDelayHandle != b.DeleteAfterDelayHandle)
			{
				char ODFNameA[MAX_ODF_LENGTH] = { 0 };
				char ODFNameB[MAX_ODF_LENGTH] = { 0 };
				GetODFName(a.DeleteAfterDelayHandle, ODFNameA);
				GetODFName(b.DeleteAfterDelayHandle, ODFNameB);
				FormatLogMessage("DELETEAFTERDELAYLIST MISMATCH: DeleteAfterDelayHandle: %08x '%s' and %08x '%s'", a.DeleteAfterDelayHandle, ODFNameA, b.DeleteAfterDelayHandle, ODFNameB);
				return false;
			}
			if (a.TurnsRemaining != b.TurnsRemaining)
			{
				FormatLogMessage("DELETEAFTERDELAY MISMATCH: TurnsRemaining: %d and %d", a.TurnsRemaining, b.TurnsRemaining);
				return false;
			}
			return true;
		}
	};

	// VSR: a deploy / undeploy sound played (once or looping) on an object after a delay.
	struct DeploySoundClass {
		friend struct VsrLayoutCheck_BZ1Helper__DeploySoundClass; // scaffold: QA gate 2 hook (layout asserts); not GBD's
		Handle ObjectHandle; // The handle.
		bool DoesLoop;
		DLLAudioHandle AudioHandle;
		int StartDelay; // Turns until it starts.
		int RepeatDelay; // Turns between repeats.
		int AudioFileTurns; // Length of the file in turns.
		char DeploySound[MAX_ODF_LENGTH];

		DeploySoundClass() { memset(this, 0, sizeof(DeploySoundClass)); };

		friend bool operator==(const DeploySoundClass &a, const DeploySoundClass &b)
		{
			if (a.ObjectHandle != b.ObjectHandle)
			{
				char ODFNameA[MAX_ODF_LENGTH] = { 0 };
				char ODFNameB[MAX_ODF_LENGTH] = { 0 };
				GetODFName(a.ObjectHandle, ODFNameA);
				GetODFName(b.ObjectHandle, ODFNameB);
				FormatLogMessage("DEPLOYSOUNDCLASS MISMATCH: ObjectHandle: %08x '%s' and %08x '%s'", a.ObjectHandle, ODFNameA, b.ObjectHandle, ODFNameB);
				return false;
			}
			if (a.DoesLoop != b.DoesLoop) { FormatLogMessage("DEPLOYSOUNDCLASS MISMATCH: DoesLoop: %d and %d", a.DoesLoop, b.DoesLoop); return false; }
			if (a.AudioHandle != b.AudioHandle) { FormatLogMessage("DEPLOYSOUNDCLASS MISMATCH: AudioHandle: %d and %d", a.AudioHandle, b.AudioHandle); return false; }
			if (a.StartDelay != b.StartDelay) { FormatLogMessage("DEPLOYSOUNDCLASS MISMATCH: StartDelay: %d and %d", a.StartDelay, b.StartDelay); return false; }
			if (a.RepeatDelay != b.RepeatDelay) { FormatLogMessage("DEPLOYSOUNDCLASS MISMATCH: RepeatDelay: %d and %d", a.RepeatDelay, b.RepeatDelay); return false; }
			if (a.AudioFileTurns != b.AudioFileTurns) { FormatLogMessage("DEPLOYSOUNDCLASS MISMATCH: AudioFileTurns: %d and %d", a.AudioFileTurns, b.AudioFileTurns); return false; }
			if (_stricmp(a.DeploySound, b.DeploySound)) { FormatLogMessage("DEPLOYSOUNDCLASS MISMATCH: DeploySound: '%s' and '%s'", a.DeploySound, b.DeploySound); return false; }
			return true;
		}
	};

	// VSR: a pending "build this at that position" order for a builder (BuildAt).
	struct BuildAtClass {
		friend struct VsrLayoutCheck_BZ1Helper__BuildAtClass; // scaffold: QA gate 2 hook (layout asserts); not GBD's
		Handle BuilderHandle; // The handle.
		Vector DropoffPos;
		int BuildTurn; // The turn the order expires.
		int Priority;
		int BuilderType;

		BuildAtClass() { memset(this, 0, sizeof(BuildAtClass)); };

		friend bool operator==(const BuildAtClass &a, const BuildAtClass &b)
		{
			if (a.BuilderHandle != b.BuilderHandle)
			{
				char ODFNameA[MAX_ODF_LENGTH] = { 0 };
				char ODFNameB[MAX_ODF_LENGTH] = { 0 };
				GetODFName(a.BuilderHandle, ODFNameA);
				GetODFName(b.BuilderHandle, ODFNameB);
				FormatLogMessage("BUILDATCLASS MISMATCH: BuilderHandle: %08x '%s' and %08x '%s'", a.BuilderHandle, ODFNameA, b.BuilderHandle, ODFNameB);
				return false;
			}
			if (a.DropoffPos != b.DropoffPos) { FormatLogMessage("BUILDATCLASS MISMATCH: DropoffPos: %f %f %f and %f %f %f", a.DropoffPos.x, a.DropoffPos.y, a.DropoffPos.z, b.DropoffPos.x, b.DropoffPos.y, b.DropoffPos.z); return false; }
			if (a.BuildTurn != b.BuildTurn) { FormatLogMessage("BUILDATCLASS MISMATCH: BuildTurn: %d and %d", a.BuildTurn, b.BuildTurn); return false; }
			if (a.Priority != b.Priority) { FormatLogMessage("BUILDATCLASS MISMATCH: Priority: %d and %d", a.Priority, b.Priority); return false; }
			if (a.BuilderType != b.BuilderType) { FormatLogMessage("BUILDATCLASS MISMATCH: BuilderType: %d and %d", a.BuilderType, b.BuilderType); return false; }
			return true;
		}
	};

private:
	static BZ1Helper *m_BZ1Helper;

public:
// Public Variables. These are saved across network.
	static int m_GameTPS; // Store it.
	static int m_TurnCounter; // Count each game tick. -GBD
	static int TotalMapObjects; // Save this too.
	static Vector OffMapPos; // Constant vector used for off-map objects. (ScrapHolds and Limiters)
	static char WorldSetting; // What world are we on?
	static int m_GameType; // Game Type Variable.
	static int m_GameVersion; // The version of the game, should be the same across all machines.
	static float m_ModVersion; // The version of the game, should be the same across all machines.

// Local variables not saved.
	static bool Logging; // Logging flag, not saved, only used for console/log file logging.
	static bool InEditor;

	// BZ1 Interface 2ndary Health/Ammo bars.
	static float HullGauge2;
	static float AmmoGauge2;
	static float AuxGauge;
	static float CloakGauge;
	static bool HullGaugeSet;
	static bool AmmoGaugeSet;
	static bool AuxGaugeSet;
	static bool CloakGaugeSet;

	// Death camera (VSR).
	static bool DeathCameraOn;
	static int DeathCameraTime;
	static int DeathCameraTeam;

private:
	ObjectHelper *m_ObjectHelper;
	VehicleHelper *m_VehicleHelper;
	ProductionClassHelper *m_ProductionClassHelper;
	PowerHelper *m_PowerHelper;
	PowerupHelper *m_PowerupHelper;
	BuildingHelper *m_BuildingHelper;
	PortalHelper *m_PortalHelper;
	AttacherHelper *m_AttacherHelper;
	UtilityShipHelper *m_UtilityShipHelper;
	ScrapHelper *m_ScrapHelper;
	DispatchHelper *m_DispatchHelper;
	UndeployHelper *m_UndeployHelper;
	AIWeaponHelper *m_AIWeaponHelper;
	MorphObjectHelper *m_MorphObjectHelper;
	CarrierHelper *m_CarrierHelper;
	GravityHelper *m_GravityHelper;
	AmbientSoundHelper *m_AmbientSoundHelper;

	// Private vars for the above structs.
	MapInfo mapInfo;

	// Team info var.
	TeamInfo teamInfo[MAX_TEAMS];

	std::vector<AlignTerrainReplaceClass> AlignTerrainReplaceList;
	std::vector<DeleteAfterDelayClass> DeleteAfterDelayList;
	std::vector<DeploySoundClass> DeploySoundList;
	std::vector<BuildAtClass> BuildAtList;

int i_first,
	// MP Scrap Multiplier.
	m_ScrapMultiplier, 
	// MP Max Lives.
	m_MaxLives,

	m_LastObjectListCount, // Counts the number of ObjectList items at the end of each tick.

	// Reinforcement stuff.
	m_ReinforcementTime, // Interval of arrival.
	m_ReinforcementAmount, // Amount per arrival.

	MissionAudioHandle, // The handle.
	MissionAudioFile[16], // RUDE HACK! Storing a char string as int's. 16 == char [64];

	i_last;

bool b_first,
	m_DidInit, // Flag for initial setup. Internal only. -GBD
	m_DidSetup, // Flag for onload setup. Internal only. -GBD
	m_IsFriendlyFireOn, // Global network var. Moved here to reduce duplicate code. -GBD
	m_EnableSiteCamMP, // Bool if to use SiteCam in MP.
	m_UseSkillLevels, // Flag for the skill-level display timer (VehicleHelper).

	m_BuildPools, // Flag to add BZ2 Pools.
	m_SetupPools, // Flag if we already have BZ2 Pools.

	// AIP stuff.
	m_CPUUseDayWreckers, // Flag for if the AI can use day wreckers or not.

	StopAddObject, // RUDE HACK!!!
	StopDeleteObject,
	StopAddMorphObject,

	b_last;

float f_first,
	// MP Damage Multiplier.
	m_DamageMultiplier,

	// Reinforcements. 
	m_ReinforcementMinRadius, // Map set min radius for reinfrocement landing.
	m_ReinforcementMaxRadius, // Map set max radius for reinforcement landing.
	m_ReinforcementMaxCliff, // Map set height differance tollerance for cliff detection.

	f_last;

	bool *b_array;
	int b_count;

	float *f_array;
	int f_count;

	int *i_array;
	int i_count;

public:
	// Path data called once from BZ1 Helper. Shared across all DLLs. NOT Saved across network, must be fetched each game Start/Load.
	int AIpathCount;
	const char **AIpathNames;
	// Saved list of paths.
	std::vector<const char*> MLayPathList[MAX_TEAMS];
	std::vector<const char*> PatrolPathList[MAX_TEAMS];

private:
	static bool ShouldRemoveAlignTerrainReplace(const AlignTerrainReplaceClass &entry) { return !IsAround(entry.AlignHandle); }
	static bool ShouldRemoveDeleteAfterDelay(const DeleteAfterDelayClass &entry) { return !IsAround(entry.DeleteAfterDelayHandle); }
	static bool ShouldRemoveDeploySound(const DeploySoundClass &entry) { return !IsAround(entry.ObjectHandle) || (!entry.DoesLoop && entry.StartDelay < 1); }
	static bool ShouldRemoveBuildAt(const BuildAtClass &entry) { return !IsAround(entry.BuilderHandle) || m_TurnCounter > entry.BuildTurn; }

public:
	BZ1Helper(void);
	virtual ~BZ1Helper();
	static BZ1Helper &Get() { return *m_BZ1Helper; }

	// Normal game functions.
	virtual bool Save(bool missionSave);
	virtual bool Load(bool missionSave);
	virtual bool PostLoad(bool missionSave);
	virtual void AddObject(Handle h);
	virtual void DeleteObject(Handle h);
	virtual void Execute(void);

	virtual PreSnipeReturnCodes PreSnipe(const int curWorld, Handle shooterHandle, Handle victimHandle, int ordnanceTeam, const char* pOrdnanceODF);
	virtual void PreOrdnanceHit(Handle shooterHandle, Handle victimHandle, int ordnanceTeam, const char* pOrdnanceODF);
	virtual PreGetInReturnCodes PreGetIn(const int curWorld, Handle pilotHandle, Handle emptyCraftHandle);
	virtual PrePickupPowerupReturnCodes PrePickupPowerup(const int curWorld, Handle me, Handle powerupHandle);

	// Setup Functions.
	void Init(void);
	void Setup(void);

	// Called by the mission when an object died (the helpers that track it get told).
	void DeadObject(Handle DeadObjectHandle);

	// Portal hooks (PortalHelper does the work).
	virtual PreTeleportReturnCodes PreTeleport(const Handle portalHandle, const Handle shipHandle);
	virtual PostTeleportReturnCodes PostTeleport(const Handle portalHandle, const Handle shipHandle);

	// Note: BZ1 made clouds around the player in a 3x3 TileSize grid, with CloudCount # of clouds placed randomly in each Tile. It then moved them around when 
	// the player got into the next tile area.
	// Clouds.
	void SetupClouds(const char *mapTrnFile);

	// Team Acessories
	const TeamInfo &GetTeamInfo(int Team) const { return teamInfo[Team]; } // Read only version.
	TeamInfo &RefTeamInfo(int Team) { return teamInfo[Team]; }

	// Map Accessors, Read only from data retrieved during initial load.
	const MapInfo &GetMapInfo() const { return mapInfo; }
	MapInfo &RefMapInfo() { return mapInfo; }

	// ST ScrapMult.
	int &RefScrapMult() { return m_ScrapMultiplier; }

	// ST DamageMult.
	float &RefDamageMult() { return m_DamageMultiplier; }

	// ST/DM Max Lives.
	int &RefMaxLives() { return m_MaxLives; }

	// IA/ST Reinforcement stuff.
	int &RefReinforcementTime() {return m_ReinforcementTime;}
	int &RefReinforcementAmount() {return m_ReinforcementAmount;}

	// Flags for BZ2 style Pools.
	bool &RefBuildPools() { return m_BuildPools; }
	bool &RefSetupPools() { return m_SetupPools; }

	// Accessor for this flag.
	bool &RefEnableSiteCamMP() { return m_EnableSiteCamMP; }

	// Skill-level display.
	bool GetUseSkillLevels() const { return m_UseSkillLevels; }
	bool &RefUseSkillLevels() { return m_UseSkillLevels; }

	// Rude Hack!
	bool &RefStopAddObject() { return StopAddObject; }
	bool &RefStopDeleteObject() { return StopDeleteObject; }
	bool &RefStopAddMorphObject() { return StopAddMorphObject; }

	// Master Object List accessors.
	int GetNumHandles() { return m_ObjectHelper->GetNumHandles(); }
	const ObjectHelper::ObjectClass &GetHandleInfo(int index) const { return m_ObjectHelper->GetHandleInfo(index); } // Read only version.
	ObjectHelper::ObjectClass &RefHandleInfo(int index) { return m_ObjectHelper->RefHandleInfo(index); }

	// Vehicle list accessors.
	int GetNumVehicles() { return m_VehicleHelper->GetNumVehicles(); }
	const VehicleHelper::VehicleClass &GetVehicleInfo(int index) const { return m_VehicleHelper->GetVehicleInfo(index); } // Read only version.
	VehicleHelper::VehicleClass &RefVehicleInfo(int index) { return m_VehicleHelper->RefVehicleInfo(index); }

	// Gets the number of objects the last tick.
	int GetNumObjectsLastTick() { return m_LastObjectListCount; }

	// Delete this item the next Execute Step.
	void DeleteAfterDelay(const Handle h, const float Delay = 0.0f);

	// These are various exterior functions that allow missions to see/control some things. 
	// These are Pilot Resource interface functions, they function like GetScrap, SetScrap, AddScrap. 
	// To call these from an exterior DLL you must #include BZ1Helper.h.
	int GetTurnCount(void) {return m_TurnCounter;}

	// Pilot Reousrce Functions. For use by mission DLLs.
	int AddPilot(const int Team, const int Value) {return teamInfo[Team].CurrPilots += Value;}
	int SetPilot(const int Team, const int Value) {return teamInfo[Team].CurrPilots = Value;}
	int GetPilot(const int Team) {return teamInfo[Team].CurrPilots;}
	int GetMaxPilot(const int Team) {return teamInfo[Team].MaxPilots;}
	int AddMaxPilot(const int Team, const int Value) {return teamInfo[Team].MaxPilots += Value;}
	int SetMaxPilot(const int Team, const int Value) {return teamInfo[Team].MaxPilots = Value;}

	// BZ1 Interface Health/Ammo Gauge2 settings.
	void SetHullGauge(const float Amount) { HullGauge2 = Amount; HullGaugeSet = true; }
	void SetAmmoGauge(const float Amount) { AmmoGauge2 = Amount; AmmoGaugeSet = true; }
	void SetAuxGauge(const float Amount) { AuxGauge = Amount; AuxGaugeSet = true; }
	void SetCloakGauge(const float Amount) { CloakGauge = Amount; CloakGaugeSet = true; }

	// Production Unit Handles. BZC Production units can undeploy, meaning their handle is lost. Use this in SP mission scripts to keep track of production units.
	Handle GetRecyclerHandle(const int Team) { return teamInfo[Team].Recycler; }
	Handle GetFactoryHandle(const int Team) { return teamInfo[Team].Factory; }
	Handle GetArmoryHandle(const int Team) { return teamInfo[Team].Armory; }
	Handle GetConstructorHandle(const int Team) { return teamInfo[Team].Constructor; }

	// Get/Set if a team is using pilots. 
	bool GetUsePilots(const int Team) { return teamInfo[Team].m_UsePilots; }
	void SetUsePilots(const int Team, const bool Value) { teamInfo[Team].m_UsePilots = Value; }

	// Sets an AIP file and uses "Pilot resource cheat" numbers, and advanced Dispatch functions. Returns true if successful, false if the AIP file doesn't exist.
	bool SetAIPFile(const char* Value, const int Team = -1);
	bool UpdateTeamAIP(const char* AIPFile, const int Team);

	// Adds a unit to a BZ1 Unit Dispatcher. Defaults to requiring an AIP to be running, can be overridden with SkipAIPCheck. If CloakPriority is 1, Dispatcher 
	// doesnt change cloak state. If IsFleer is true, unit will flee unless the ODF says it can't. If CloakNow is true, it will cloak ASAP. If Hunt is true, unit will 
	// begin hunting. If CanGetService is true, it will get ammo on its own (interrupting previous orders/dispatch duties). Returns true if successful, false if 
	// an invalid handle or no BZC AIP is running.
	bool AddToDispatch(const Handle h, const float IdleTime = 15.0f, const bool SkipAIPCheck = false, const int CloakPriority = 0, const bool CanFlee = true, 
		const bool CloakNow = false, const bool Hunt = false, const bool CanGetService = false);

	// Cloak Commands, used to interface with DispatchHelper's Dispatch code.
	void Cloak(const Handle h, const int Priority = 0);
	void Decloak(const Handle h, const int Priority = 0);
	bool IsCloaked(const Handle h);
	// Special SP ability to disable cloak. Returns the handle if it switched the objects, or the handle passed in if it did nothing.
	Handle SetCloakAllowed(const Handle h, const bool IsAllowed, const bool PlaySound = false);
	// VSR: the cloak energy gauge (VehicleHelper's CloakCurEnergy / CloakMaxEnergy).
	int GetCurCloakEnergy(const Handle h);
	void SetCurCloakEnergy(const Handle h, const int Energy);
	int GetMaxCloakEnergy(const Handle h);
	void SetMaxCloakEnergy(const Handle h, const int Energy);
	// DLL Hunt, passes units from mission scripts into Dispatcher code.
	void DLLHunt(const Handle h, const int Priority = 0);
	// DLL command to set a unit's UseService status.
	void SetUseService(const Handle h, const bool Service = true);

	// Gets a random Escort Target, based on escort priority. By default, Production units are High, Scavs are Medium, APCs/TUGs/Minelayers are Low.
	Handle GetEscortTarget(const int Team = -1, const int TeamFilter = 0);

	// Sets the channel of a Portal.
	void SetPortalChannel(const Handle h, const int Channel);
	int GetPortalChannel(const Handle h);
	// Portal Effect controllers. FxNumber is which EffectODF to make, 0, 1, or 2. Type: 0 = Exit (Close Fx), 1 = Continuous On (Open Fx), 2 = Build (Open then Close Fx)
	void SetPortalEffectStart(const Handle h, const int FxNumber = 0, const int Type = 0);
	void SetPortalEffectOn(const Handle h, const int FxNumber = 0, const int Type = 0);
	void SetPortalEffectEnd(const Handle h, const int FxNumber = 0, const int Type = 0);
	bool IsPortalEffectActive(const Handle h);
	// VSR: portal destination list management.
	void SwapPortalIndex(const Handle h1, const Handle h2);
	void ShufflePortalUp(const Handle h);
	void ShufflePortalDown(const Handle h);
	Handle GetPortalDest(const Handle h);
	bool SetPortalDest(const Handle h, const Handle Dest);
	void ClearPortalDest(const Handle h, const bool ScriptOverride); // Drops the channel's destinations; ScriptOverride leaves the portal under script control.

	// Returns true if a building is Powered.
	bool IsBuildingPowered(const Handle h);
	// Sets a building's power state. -1 = Autodetermine, 0 = Off, 1 = On. (Only effects above function and related DLL code)
	void SetBuildingPowered(const Handle h, const int Powered);

	// Replaces an object with another object, retaining as much information about it as possible, with optional team switching, height offset, replacing of 
	// weapons with what it currently has, group, and current command info (may not work for all commands).
	Handle ReplaceObject(const Handle h, const char *ODF = NULL, const int Team = -1, const float HeightOffset = 0.0f, const int Empty = -1, 
		const bool RestoreWeapons = true, const int Group = -1, const int CanSnipe = -1, const bool KeepCommand = true, const int NewCommand = -1, const int Priority = 0, const Handle NewWho = -1, const Vector NewWhere = Vector(0.0f, 0.0f, 0.0f));

	// Gets a random object on the map, with filtering options. IncludeItemsAddedThisTurn is a bool for if the check includes items added this game turn. 
	// "Team" is an optional Team to compare against with TeamFilter. TeamFilter is 0 = All, 1 = SameTeam, 2 = Allies, 4 = Enemies. UsePTeam compares perceived teams.
	// CategoryMask is a bitmask for: 0 = All, 1 = Vehicle, 2 = Building, 4 = Person, 8 = Powerup, 16 = Weapon, 32 = Scrap, 64 = Other. 
	// MatchMask is a bitmask for match type. 0 = Any, 1 = Match CategoryMask, 2 = Match ObjClass, 4 = Match ODF Name. ObjClass is a string returned by Get_GOClass, i.e. CLASS_WINGMAN. ODFName is the ODFName, without the .odf extension.
	// MinDistance / Position: only objects at least MinDistance from Position (VSR).
	// TODO(tier 3): parameter names after UsePTeam are reconstructed from the 2015 signature; confirm against the decompile when the body is ported.
	Handle GetRandomObject(const int Team = -1, const int TeamFilter = 0, const bool UsePTeam = false, const int CategoryMask = 0, const bool IncludeItemsAddedThisTurn = false, const bool IgnoreInvincible = true, const bool ObeyIdleVictim = false, const int MatchMask = 0, const char *ObjClass = NULL, const char *ODFName = NULL, const float MinDistance = 0.0f, const Vector Position = Vector(0.0f, 0.0f, 0.0f));

	// Gets the number of objects on a team, with filtering options (same filters as GetRandomObject).
	int GetNumObjects(const int Team = -1, const int TeamFilter = 0, const bool UsePTeam = false, const int CategoryMask = 0, const bool IncludeItemsAddedThisTurn = false, const bool IgnoreInvincible = true, const bool ObeyIdleVictim = false, const int MatchMask = 0, const char *ObjClass = NULL, const char *ODFName = NULL);

	// Gets the nearest object to a position, with filtering options (same filters as GetRandomObject; Me is excluded from the search).
	Handle GetNearestObject(const Matrix Position, const float MaxRange = 0.0f, const int Team = -1, const int TeamFilter = 0, const bool UsePTeam = false, const int CategoryMask = 0, const bool IgnoreInvincible = true, const bool ObeyIdleVictim = false, const int MatchMask = 0, const char *ObjClass = NULL, const char *ODFName = NULL);
	Handle GetNearestObject(const Handle h, const float MaxRange = 0.0f, const int Team = -1, const int TeamFilter = 0, const bool UsePTeam = false, const int CategoryMask = 0, const bool IgnoreInvincible = true, const bool ObeyIdleVictim = false, const int MatchMask = 0, const char *ObjClass = NULL, const char *ODFName = NULL);
	Handle GetNearestObject(const Name Path, const int Point = 0, const float MaxRange = 0.0f, const int Team = -1, const int TeamFilter = 0, const bool UsePTeam = false, int CategoryMask = 0, const bool IgnoreInvincible = true, const bool ObeyIdleVictim = false, const int MatchMask = 0, const char *ObjClass = NULL, const char *ODFName = NULL);
	Handle GetNearestObject(const Vector Position, const float MaxRange = 0.0f, const int Team = -1, const int TeamFilter = 0, const bool UsePTeam = false, const int CategoryMask = 0, const bool IgnoreInvincible = true, const bool ObeyIdleVictim = false, const Handle Me = 0, const int MatchMask = 0, const char *ObjClass = NULL, const char *ODFName = NULL);

	// VSR: the same searches over the vehicle list (VehicleHelper) and the building list (BuildingHelper).
	// TODO(tier 3): the fourth bool of the vehicle searches is unnamed in the PDB; name it from the body.
	Handle GetRandomVehicle(const int Team = -1, const int TeamFilter = 0, const bool UsePTeam = false, const bool IncludeItemsAddedThisTurn = false, const bool IgnoreInvincible = true, const bool ObeyIdleVictim = false, const int MatchMask = 0, const char *ObjClass = NULL, const char *ODFName = NULL, const float MinDistance = 0.0f, const Vector Position = Vector(0.0f, 0.0f, 0.0f));
	int GetNumVehicle(const int Team = -1, const int TeamFilter = 0, const bool UsePTeam = false, const bool IncludeItemsAddedThisTurn = false, const bool IgnoreInvincible = true, const bool ObeyIdleVictim = false, const int MatchMask = 0, const char *ObjClass = NULL, const char *ODFName = NULL);
	Handle GetNearestVehicle(const Matrix Position, const float MaxRange = 0.0f, const int Team = -1, const int TeamFilter = 0, const bool UsePTeam = false, const bool IgnoreInvincible = true, const bool ObeyIdleVictim = false, const bool IgnoreDeployed = false, const int MatchMask = 0, const char *ObjClass = NULL, const char *ODFName = NULL);
	Handle GetNearestVehicle(const Handle h, const float MaxRange = 0.0f, const int Team = -1, const int TeamFilter = 0, const bool UsePTeam = false, const bool IgnoreInvincible = true, const bool ObeyIdleVictim = false, const bool IgnoreDeployed = false, const int MatchMask = 0, const char *ObjClass = NULL, const char *ODFName = NULL);
	Handle GetNearestVehicle(const Name Path, const int Point = 0, const float MaxRange = 0.0f, const int Team = -1, const int TeamFilter = 0, const bool UsePTeam = false, const bool IgnoreInvincible = true, const bool ObeyIdleVictim = false, const bool IgnoreDeployed = false, const int MatchMask = 0, const char *ObjClass = NULL, const char *ODFName = NULL);
	Handle GetNearestVehicle(const Vector Position, const float MaxRange = 0.0f, const int Team = -1, const int TeamFilter = 0, const bool UsePTeam = false, const bool IgnoreInvincible = true, const bool ObeyIdleVictim = false, const bool IgnoreDeployed = false, const Handle Me = 0, const int MatchMask = 0, const char *ObjClass = NULL, const char *ODFName = NULL);
	Handle GetRandomBuilding(const int Team = -1, const int TeamFilter = 0, const bool UsePTeam = false, const bool IgnoreInvincible = true, const bool ObeyIdleVictim = false, const int MatchMask = 0, const char *ObjClass = NULL, const char *ODFName = NULL, const float MinDistance = 0.0f, const Vector Position = Vector(0.0f, 0.0f, 0.0f));
	int GetNumBuildings(const int Team = -1, const int TeamFilter = 0, const bool UsePTeam = false, const bool IgnoreInvincible = true, const bool ObeyIdleVictim = false, const int MatchMask = 0, const char *ObjClass = NULL, const char *ODFName = NULL);
	Handle GetNearestBuilding(const Matrix Position, const float MaxRange = 0.0f, const int Team = -1, const int TeamFilter = 0, const bool UsePTeam = false, const bool IgnoreInvincible = true, const bool ObeyIdleVictim = false, const int MatchMask = 0, const char *ObjClass = NULL, const char *ODFName = NULL);
	Handle GetNearestBuilding(const Handle h, const float MaxRange = 0.0f, const int Team = -1, const int TeamFilter = 0, const bool UsePTeam = false, const bool IgnoreInvincible = true, const bool ObeyIdleVictim = false, const int MatchMask = 0, const char *ObjClass = NULL, const char *ODFName = NULL);
	Handle GetNearestBuilding(const Name Path, const int Point = 0, const float MaxRange = 0.0f, const int Team = -1, const int TeamFilter = 0, const bool UsePTeam = false, const bool IgnoreInvincible = true, const bool ObeyIdleVictim = false, const int MatchMask = 0, const char *ObjClass = NULL, const char *ODFName = NULL);
	Handle GetNearestBuilding(const Vector Position, const float MaxRange = 0.0f, const int Team = -1, const int TeamFilter = 0, const bool UsePTeam = false, const bool IgnoreInvincible = true, const bool ObeyIdleVictim = false, const Handle Me = 0, const int MatchMask = 0, const char *ObjClass = NULL, const char *ODFName = NULL);

	// BuildAngleObject functions, Builds an object, with optional label (checks to see that it doesnt exist already), optionally at the desired 
	// Angle(in degrees), in the desired Group, spawn Empty, Deploy on build, HeightOffset, and if they're spread out or not (Defaults to true for paths, only works on non buildings)
	Handle BuildAngleObject(const char* ODF, const int Team, const Vector &pos, const char* Label = NULL, const float Degrees = 0.0f, const int Group = -1, const bool Empty = false, const bool StartDeploy = false, const float HeightOffset = 0.0, const bool SpreadOut = false, const int AlignToTerrain = -1, const bool AlignUseWater = false);
	Handle BuildAngleObject(const char* ODF, const int Team, const AiPath *APath, const char* Label = NULL, const float Degrees = 0.0f, const int Group = -1, const bool Empty = false, const bool StartDeploy = false, const float HeightOffset = 0.0, const bool SpreadOut = true, const int AlignToTerrain = -1, const bool AlignUseWater = false);
	Handle BuildAngleObject(const char* ODF, const int Team, const Name APath, const char* Label = NULL, const float Degrees = 0.0f, const int Group = -1, const bool Empty = false, const bool StartDeploy = false, const float HeightOffset = 0.0, const bool SpreadOut = true, const int AlignToTerrain = -1, const bool AlignUseWater = false);
	Handle BuildAngleObject(const char* ODF, const int Team, const Handle him, const char* Label = NULL, const float Degrees = 0.0f, const int Group = -1, const bool Empty = false, const bool StartDeploy = false, const float HeightOffset = 0.0, const bool SpreadOut = false, const int AlignToTerrain = -1, const bool AlignUseWater = false);
	Handle BuildAngleObject(const char* ODF, const int Team, const Matrix &mat, const char* Label = NULL, const float Degrees = 0.0f, const int Group = -1, const bool Empty = false, const bool StartDeploy = false, const float HeightOffset = 0.0, const bool SpreadOut = false, const int AlignToTerrain = -1, const bool AlignUseWater = false);

	// Sets an AIP via BZC's SetAIPFile command, with proper formatting. Used by ST/IA DLLs to format the correct AIP File name.
	void SetCPUPlan(const char *AIPBaseName, const char Race, const int Team);

	// Rude Hack to add ability to RepeatAudioMessage via Script Command, Saves the last audiomessage played by thi command.
	int MissionAudioMessage(const char* msg);
	// Repeats the last audio message played by MissionAudioMessage().
	int RepeatAudioMessage(void);
	// IsAudioMessagePlaying
	inline bool IsAudioMessagePlaying(void) { return !IsAudioMessageDone(MissionAudioHandle); }

	// VSR: queue a build order for a producer at a drop-off position (the BuildAtList; Execute moves the finished unit there). Priority is the Build() priority —
	// LTCG-folded to 1 at every shipped call site, so its PDB symbol is gone.
	void BuildAt(const Handle me, const char *ODF, const Handle Pos, const int Priority = 1);
	void BuildAt(const Handle me, const char *ODF, const Name Path, const int Point = 0, const int Priority = 1);
	void BuildAt(const Handle me, const char *ODF, const Matrix Pos, const int Priority = 1);
	void BuildAt(const Handle me, const char *ODF, const Vector Pos, const int Priority = 1);

	// VSR: can Team build ODFName? Scrap (unless IgnoreScrapCost), power, pilots and the requireName list. The two trailing bools are dead in the shipped
	// binary (every call site passes false, false; the PDB lost their names) — kept for the signature.
	bool CheckBuildRequirements(const char *ODFName, const int Team, const bool IgnoreScrapCost = false, const bool UnusedArg4 = false, const bool UnusedArg5 = false);
	// Counts the requireName entries Team does not own (0 = may build). The first argument is dead in the shipped binary.
	int CheckBuildRequirements_RequireCount(char **UnusedArg, const int Team, const char *filename1, const char *filename2);

	// BZ1 Function for backwards compatability.
	void GetRidOfSomeScrap(const int ScrapLimit = 1000); // Upped scrap limit from BZ1's 300, as BZ2 can have 4096 entities instead of 512.
	// Clears Scrap around a specified position.
	void ClearScrapAround(Dist d, const Vector &pos, const float Percent = 1.0f);
	void ClearScrapAround(Dist d, const Matrix &mat, const float Percent = 1.0f) { return ClearScrapAround(d, mat.posit, Percent); }
	void ClearScrapAround(Dist d, const Handle h, const float Percent = 1.0f) { return ClearScrapAround(d, GetPosition(h), Percent); }
	void ClearScrapAround(Dist d, const Name path, const int point = 0, const float Percent = 1.0f) { return ClearScrapAround(d, GetVectorFromPath(path, point), Percent); }

	// Determine if there are any buildings between Handle 1 and Handle 2, within the Width Padding, taking into account the Building's CollisionRadius odf 
	// setting. Returns the handle of what is blocking the two.
	Handle IsBlockedByBuilding(const Handle h1, const Handle h2, const float WidthPadding, const Vector FrontA = Vector(0, 0, 0), const Vector FrontB = Vector(0, 0, 0), const bool IgnoreInvincible = true);

	// VSR: base-placement helpers (the CPU's constructor and the Lua bindings use them).
	Vector FindClusterCenter(const Vector &Position, const int Team, const int MatchMask);
	bool IsTerrainFlat(const Vector &Position, const int Width, const int Depth);
	std::vector<std::pair<int, BuildingHelper::BuildingClass>> IsTerrainOccupied(const Vector &Position, const float Width, const float Depth, const bool IncludeVehicles, const bool IncludeDeployed);

	// VSR: death camera (watch the killer for a while after dying).
	bool SetDeathCamera(const Handle h, const float Time);
	void ClearDeathCamera(void);
	bool PlayDeathCamera(void);

private:

	// Controls BZ1 pilots or BZ2 Power min/max gauges. 
	void BZ1Interface(void);

	// Run environmental effects, gravity, water, sky, hazards, etc.
	void EnvironmentalSystems(void);

	// Life management code.
	void BZ1Lives(void);
};

// Handy Time Conversion Stuffs. Done here because Game_Version and m_GameTPS are saved here.
inline int ConvertToTurns(const float Seconds) { return SecondsToTurns(Seconds); }
inline int ConvertToTurns(const int Seconds) { return SecondsToTurns(float(Seconds)); }
inline float ConvertToSeconds(const int Turns)  { return TurnsToSeconds(Turns); }
inline float ConvertToSeconds(const float Turns) { return TurnsToSeconds(int(Turns)); }

#define VSR_LAYOUT_CHECK_BZ1Helper
#include "vsr_layout_asserts.h"
#undef VSR_LAYOUT_CHECK_BZ1Helper

#endif
