// PROVENANCE: ancestor reference/ancestor-bz1helper-2015/Shared/BuildingHelper.h @6fda4f5 (BuildingClass comments, the accessors; RepairPowerupClass moved to PowerupHelper) | declarations original/missions/Strategy02.pdb via tools/pdb_types.py; operator== from reference/decompiled/strategy02-ghidra12.2/src/missions/vsrcore/buildinghelper.h.decomp.c (lines 69-341) | status: ported
#ifndef _buildinghelper_
#define _buildinghelper_

#include "ScriptUtils.h"
#include <vector>

class BZ1Helper;

// This code handles the BZ1 style power network, the building / tap animations, tap team and position upkeep, gun tower power-down, powerup acceptance
// for non-colliding buildings, and the CPU's building repair orders.
class BuildingHelper
{
	friend struct VsrLayoutCheck_BuildingHelper; // scaffold: QA gate 2 hook (layout asserts); not GBD's
public:
	// The Building Object class.
	struct BuildingClass
	{
		friend struct VsrLayoutCheck_BuildingHelper__BuildingClass; // scaffold: QA gate 2 hook (layout asserts); not GBD's
		Handle BuildingObject; // This Building Object.
		Handle BuildingTap[MAX_TAPS]; // Each tap handle.
		bool TapAnimated[MAX_TAPS]; // Is Each Tap animated?
		bool PlayTapAnim[MAX_TAPS]; // Is each Tap playing its animation?
		Matrix TapOffsetMatrix[MAX_TAPS]; // Offset for each Tap.
		bool IsPowered; // Is it currently powered?
		bool IsAnimated; // Is it Animated?
		bool PlayAnim; // Is it playing its animation?
		bool CanCollide; // Can it be collideded?
		bool CanBeIdleVictim; // Can this be an idle victim of dispatch?
		bool IsAPCRefill; // Is it an APC Refill point?
		bool IsRecyclePoint; // Is this a recycle point?
		bool GunTowerOff; // If it's a guntower, flag for swithcing on/off.
		bool CanDemolish; // VSR: canDemolish.
		bool PoweredByTaps; // VSR: PoweredByTaps; lung power only needs every tap when this is set.
		bool autoBuildTaps; // VSR: autoBuildTaps; a building that grows its own taps keeps the tap count it was added with.
		bool OwnsTerrain; // VSR: ownsTerrain.
		unsigned int ObjClassHash; // FNV-1a Hash of the ObjClass.
		unsigned int ODFNameHash; // FNV-1a Hash of the ODF Name.
		int PowerType; // Bitmask for Power Type. 0 = None, 1 = BZ1 Power, 2 = BZ2 Power, 4 = Lung power.
		int AnimDir[MAX_TAPS+1]; // VSR: the animation direction each animation was paused at. 0 = Host object, rest for 8 taps.
		int TapNumber; // Number of Taps this building has.
		int PowerState; // This building's default power state.
		int PowerMask; // Bitmask for what bits to look at.
		int PowerMatch; // Bitmask for what the bits need to be.
		int PowerProvide; // Bitmask for what kind of power this provides.
		int PowerupAcceptMask; // VSR: AcceptPowerupMask (0x20 = repair / reload / service pods, 0x40 = weapon powerups); -1 when CanAcceptPowerups.
		int CurTeamNum; // Current Team number, used in place of GetTeamNum. Updated once per tick.
		int PTeam; // Perceived team.
		long MaxHealth; // Store it's max health.
		long MaxAmmo; // Store it's max ammo.
		int NumWeapons; // VSR: gun towers only; how many weapon hardpoints it has.
		int TerrainSizeRatio[2]; // VSR: SizeRatioX / SizeRatioZ.
		int BuildSupport; // VSR: buildSupport letter, upper-cased.
		float CollisionRadius; // Collision Radius.
		char UpgradeName[MAX_ODF_LENGTH]; // VSR: upgradeName; a gun tower re-added under it keeps its weapons.
		char WeaponNames[5][MAX_ODF_LENGTH]; // VSR: gun towers only; the weapon configs, refreshed every tick.
		Vector Position; // It's current position. (NOT updated, since buildings should never move)
		Vector BuildingFront; // Front vector for building.
		float HealthRate; // VSR: SupplyDepotClass rates (see AddBuildingObject).
		float AmmoRate;
		float LocalAmmoRate;
		float ServiceRate;
		bool ServiceCraft;

		BuildingClass() { memset(this, 0, sizeof(BuildingClass)); };

		// GBD: member-by-member compare for PostLoad's resync report; the first difference is logged and ends the compare.
		// The shipped compare skips autoBuildTaps and NumWeapons, and compares the AnimDir ARRAYS (their addresses), kept that way for parity.
		friend bool operator==(const BuildingClass &a, const BuildingClass &b)
		{
			if (a.BuildingObject != b.BuildingObject)
			{
				char ODFNameA[MAX_ODF_LENGTH] = { 0 };
				char ODFNameB[MAX_ODF_LENGTH] = { 0 };
				GetODFName(a.BuildingObject, ODFNameA);
				GetODFName(b.BuildingObject, ODFNameB);
				FormatLogMessage("BUILDINGCLASS MISMATCH: BuildingObject: %08x '%s' and %08x '%s'", a.BuildingObject, ODFNameA, b.BuildingObject, ODFNameB);
				return false;
			}
			for (int i = 0; i < MAX_TAPS; i++)
			{
				if (a.BuildingTap[i] != b.BuildingTap[i])
				{
					char ODFNameA[MAX_ODF_LENGTH] = { 0 };
					char ODFNameB[MAX_ODF_LENGTH] = { 0 };
					GetODFName(a.BuildingTap[i], ODFNameA);
					GetODFName(b.BuildingTap[i], ODFNameB);
					FormatLogMessage("BUILDINGCLASS MISMATCH: BuildingTap%d: %08x '%s' and %08x '%s'", i, a.BuildingTap[i], ODFNameA, b.BuildingTap[i], ODFNameB);
					return false;
				}
				if (a.TapAnimated[i] != b.TapAnimated[i])
				{
					FormatLogMessage("BUILDINGCLASS MISMATCH: TapAnimated%d: %d and %d", i, a.TapAnimated[i], b.TapAnimated[i]);
					return false;
				}
				if (a.PlayTapAnim[i] != b.PlayTapAnim[i])
				{
					FormatLogMessage("BUILDINGCLASS MISMATCH: PlayTapAnim%d: %d and %d", i, a.PlayTapAnim[i], b.PlayTapAnim[i]);
					return false;
				}
				const Matrix &ma = a.TapOffsetMatrix[i];
				const Matrix &mb = b.TapOffsetMatrix[i];
				if ((ma.front.x != mb.front.x) || (ma.front.y != mb.front.y) || (ma.front.z != mb.front.z) ||
					(ma.right.x != mb.right.x) || (ma.right.y != mb.right.y) || (ma.right.z != mb.right.z) ||
					(ma.up.x != mb.up.x) || (ma.up.y != mb.up.y) || (ma.up.z != mb.up.z) ||
					(ma.posit.x != mb.posit.x) || (ma.posit.y != mb.posit.y) || (ma.posit.z != mb.posit.z))
				{
					FormatLogMessage("BUILDINGCLASS MISMATCH: TapOffsetMatrix%d Front: %f %f %f and %f %f %f, TapOffsetMatrix%d Right: %f %f %f and %f %f %f, TapOffsetMatrix%d Up: %f %f %f and %f %f %f, TapOffsetMatrix%d Posit: %f %f %f and %f %f %f",
						i, ma.front.x, ma.front.y, ma.front.z, mb.front.x, mb.front.y, mb.front.z,
						i, ma.right.x, ma.right.y, ma.right.z, mb.right.x, mb.right.y, mb.right.z,
						i, ma.up.x, ma.up.y, ma.up.z, mb.up.x, mb.up.y, mb.up.z,
						i, ma.posit.x, ma.posit.y, ma.posit.z, mb.posit.x, mb.posit.y, mb.posit.z);
					return false;
				}
			}
			if (a.IsPowered != b.IsPowered)
			{
				FormatLogMessage("BUILDINGCLASS MISMATCH: IsPowered: %d and %d", a.IsPowered, b.IsPowered);
				return false;
			}
			if (a.IsAnimated != b.IsAnimated)
			{
				FormatLogMessage("BUILDINGCLASS MISMATCH: IsAnimated: %d and %d", a.IsAnimated, b.IsAnimated);
				return false;
			}
			if (a.PlayAnim != b.PlayAnim)
			{
				FormatLogMessage("BUILDINGCLASS MISMATCH: PlayAnim: %d and %d", a.PlayAnim, b.PlayAnim);
				return false;
			}
			if (a.CanCollide != b.CanCollide)
			{
				FormatLogMessage("BUILDINGCLASS MISMATCH: CanCollide: %d and %d", a.CanCollide, b.CanCollide);
				return false;
			}
			if (a.CanBeIdleVictim != b.CanBeIdleVictim)
			{
				FormatLogMessage("BUILDINGCLASS MISMATCH: CanBeIdleVictim: %d and %d", a.CanBeIdleVictim, b.CanBeIdleVictim);
				return false;
			}
			if (a.IsAPCRefill != b.IsAPCRefill)
			{
				FormatLogMessage("BUILDINGCLASS MISMATCH: IsAPCRefill: %d and %d", a.IsAPCRefill, b.IsAPCRefill);
				return false;
			}
			if (a.IsRecyclePoint != b.IsRecyclePoint)
			{
				FormatLogMessage("BUILDINGCLASS MISMATCH: IsRecyclePoint: %d and %d", a.IsRecyclePoint, b.IsRecyclePoint);
				return false;
			}
			if (a.GunTowerOff != b.GunTowerOff)
			{
				FormatLogMessage("BUILDINGCLASS MISMATCH: GunTowerOff: %d and %d", a.GunTowerOff, b.GunTowerOff);
				return false;
			}
			if (a.CanDemolish != b.CanDemolish)
			{
				FormatLogMessage("BUILDINGCLASS MISMATCH: CanDemolish: %d and %d", a.CanDemolish, b.CanDemolish);
				return false;
			}
			if (a.PoweredByTaps != b.PoweredByTaps)
			{
				FormatLogMessage("BUILDINGCLASS MISMATCH: PoweredByTaps: %d and %d", a.PoweredByTaps, b.PoweredByTaps);
				return false;
			}
			if (a.OwnsTerrain != b.OwnsTerrain)
			{
				FormatLogMessage("BUILDINGCLASS MISMATCH: OwnsTerrain: %d and %d", a.OwnsTerrain, b.OwnsTerrain);
				return false;
			}
			if (a.ObjClassHash != b.ObjClassHash)
			{
				FormatLogMessage("BUILDINGCLASS MISMATCH: ObjClassHash: %d and %d", a.ObjClassHash, b.ObjClassHash);
				return false;
			}
			if (a.ODFNameHash != b.ODFNameHash)
			{
				FormatLogMessage("BUILDINGCLASS MISMATCH: ODFNameHash: %d and %d", a.ODFNameHash, b.ODFNameHash);
				return false;
			}
			if (a.PowerType != b.PowerType)
			{
				FormatLogMessage("BUILDINGCLASS MISMATCH: PowerType: %d and %d", a.PowerType, b.PowerType);
				return false;
			}
			if (&a.AnimDir[0] != &b.AnimDir[0]) // sic: the shipped compare is `a.AnimDir != b.AnimDir` on the arrays, i.e. their addresses, so two distinct entries never get past this line.
			{
				FormatLogMessage("BUILDINGCLASS MISMATCH: AnimDir: %d and %d", &a.AnimDir[0], &b.AnimDir[0]);
				return false;
			}
			if (a.TapNumber != b.TapNumber)
			{
				FormatLogMessage("BUILDINGCLASS MISMATCH: TapNumber: %d and %d", a.TapNumber, b.TapNumber);
				return false;
			}
			if (a.PowerState != b.PowerState)
			{
				FormatLogMessage("BUILDINGCLASS MISMATCH: PowerState: %d and %d", a.PowerState, b.PowerState);
				return false;
			}
			if (a.PowerMask != b.PowerMask)
			{
				FormatLogMessage("BUILDINGCLASS MISMATCH: PowerMask: %d and %d", a.PowerMask, b.PowerMask);
				return false;
			}
			if (a.PowerMatch != b.PowerMatch)
			{
				FormatLogMessage("BUILDINGCLASS MISMATCH: PowerMatch: %d and %d", a.PowerMatch, b.PowerMatch);
				return false;
			}
			if (a.PowerProvide != b.PowerProvide)
			{
				FormatLogMessage("BUILDINGCLASS MISMATCH: PowerProvide: %d and %d", a.PowerProvide, b.PowerProvide);
				return false;
			}
			if (a.PowerupAcceptMask != b.PowerupAcceptMask)
			{
				FormatLogMessage("BUILDINGCLASS MISMATCH: PowerupAcceptMask: %d and %d", a.PowerupAcceptMask, b.PowerupAcceptMask);
				return false;
			}
			if (a.CurTeamNum != b.CurTeamNum)
			{
				FormatLogMessage("BUILDINGCLASS MISMATCH: CurTeamNum: %d and %d", a.CurTeamNum, b.CurTeamNum);
				return false;
			}
			if (a.PTeam != b.PTeam)
			{
				FormatLogMessage("BUILDINGCLASS MISMATCH: PTeam: %d and %d", a.PTeam, b.PTeam);
				return false;
			}
			if (a.MaxHealth != b.MaxHealth)
			{
				FormatLogMessage("BUILDINGCLASS MISMATCH: MaxHealth: %d and %d", a.MaxHealth, b.MaxHealth);
				return false;
			}
			if (a.MaxAmmo != b.MaxAmmo)
			{
				FormatLogMessage("BUILDINGCLASS MISMATCH: MaxAmmo: %d and %d", a.MaxAmmo, b.MaxAmmo);
				return false;
			}
			for (int i = 0; i < 2; i++)
			{
				if (a.TerrainSizeRatio[i] != b.TerrainSizeRatio[i])
				{
					FormatLogMessage("BUILDINGCLASS MISMATCH: TerrainSizeRatio%d: %d and %d", i, a.TerrainSizeRatio[i], b.TerrainSizeRatio[i]);
					return false;
				}
			}
			if (a.BuildSupport != b.BuildSupport)
			{
				FormatLogMessage("BUILDINGCLASS MISMATCH: BuildSupport: %d and %d", a.BuildSupport, b.BuildSupport);
				return false;
			}
			if (a.CollisionRadius != b.CollisionRadius)
			{
				FormatLogMessage("BUILDINGCLASS MISMATCH: CollisionRadius: %f and %f", a.CollisionRadius, b.CollisionRadius);
				return false;
			}
			if (_stricmp(a.UpgradeName, b.UpgradeName) != 0)
			{
				FormatLogMessage("BUILDINGCLASS MISMATCH: UpgradeName: '%s' and '%s'", a.UpgradeName, b.UpgradeName);
				return false;
			}
			for (int i = 0; i < 5; i++)
			{
				if (_stricmp(a.WeaponNames[i], b.WeaponNames[i]) != 0)
				{
					FormatLogMessage("BUILDINGCLASS MISMATCH: WeaponNames%d: '%s' and '%s'", i, a.WeaponNames[i], b.WeaponNames[i]);
					return false;
				}
			}
			if ((a.Position.x != b.Position.x) || (a.Position.y != b.Position.y) || (a.Position.z != b.Position.z))
			{
				FormatLogMessage("BUILDINGCLASS MISMATCH: Position: %f %f %f and %f %f %f", a.Position.x, a.Position.y, a.Position.z, b.Position.x, b.Position.y, b.Position.z);
				return false;
			}
			if ((a.BuildingFront.x != b.BuildingFront.x) || (a.BuildingFront.y != b.BuildingFront.y) || (a.BuildingFront.z != b.BuildingFront.z))
			{
				FormatLogMessage("BUILDINGCLASS MISMATCH: BuildingFront: %f %f %f and %f %f %f", a.BuildingFront.x, a.BuildingFront.y, a.BuildingFront.z, b.BuildingFront.x, b.BuildingFront.y, b.BuildingFront.z);
				return false;
			}
			if (a.HealthRate != b.HealthRate)
			{
				FormatLogMessage("OBJECTLIST MISMATCH: HealthRate: %f and %f", a.HealthRate, b.HealthRate);
				return false;
			}
			if (a.AmmoRate != b.AmmoRate)
			{
				FormatLogMessage("OBJECTLIST MISMATCH: AmmoRate: %f and %f", a.AmmoRate, b.AmmoRate);
				return false;
			}
			if (a.LocalAmmoRate != b.LocalAmmoRate)
			{
				FormatLogMessage("OBJECTLIST MISMATCH: LocalAmmoRate: %f and %f", a.LocalAmmoRate, b.LocalAmmoRate);
				return false;
			}
			if (a.ServiceRate != b.ServiceRate)
			{
				FormatLogMessage("OBJECTLIST MISMATCH: ServiceRate: %f and %f", a.ServiceRate, b.ServiceRate);
				return false;
			}
			if (a.ServiceCraft != b.ServiceCraft)
			{
				FormatLogMessage("OBJECTLIST MISMATCH: ServiceCraft: %d and %d", a.ServiceCraft, b.ServiceCraft);
				return false;
			}
			return true;
		}
	};

private:

	static BuildingHelper *m_BuildingHelper;

	// The building list.
	std::vector<BuildingClass> BuildingList;

	static bool ShouldRemoveBuilding(const BuildingClass &entry) { return !IsAround(entry.BuildingObject); }

public:
	BuildingHelper();
	~BuildingHelper();
	static BuildingHelper &Get() { return *m_BuildingHelper; }

	int GetNumBuildingObjects() { return int(BuildingList.size()); }
	const BuildingClass &GetBuildingInfo(int index) const { return BuildingList[index]; } // Read only version.

	// Is this building powered?
	bool IsBuildingPowered(const Handle h);
	// Powered state: -1 = Autodetermine, 0 = Off, 1 = On.
	void SetBuildingPowered(const Handle h, const int PoweredState);

	// VSR: the searches over the building list (the BZ1Helper object searches, restricted to buildings). Every entry stores its
	// perceived team, so UsePTeam compares that; MinDistance is really the search radius (0 = any), as on BZ1Helper::GetRandomObject.
	Handle GetRandomBuilding(const int Team = -1, const int TeamFilter = 0, const bool UsePTeam = false, const bool IgnoreInvincible = true, const bool ObeyIdleVictim = false, const int MatchMask = 0, const char *ObjClass = NULL, const char *ODFName = NULL, const float MinDistance = 0.0f, const Vector Position = Vector(0.0f, 0.0f, 0.0f));
	int GetNumBuildings(const int Team = -1, const int TeamFilter = 0, const bool UsePTeam = false, const bool IgnoreInvincible = true, const bool ObeyIdleVictim = false, const int MatchMask = 0, const char *ObjClass = NULL, const char *ODFName = NULL);
	Handle GetNearestBuilding(const Matrix Position, const float MaxRange = 0.0f, const int Team = -1, const int TeamFilter = 0, const bool UsePTeam = false, const bool IgnoreInvincible = true, const bool ObeyIdleVictim = false, const int MatchMask = 0, const char *ObjClass = NULL, const char *ODFName = NULL);
	Handle GetNearestBuilding(const Handle h, const float MaxRange = 0.0f, const int Team = -1, const int TeamFilter = 0, const bool UsePTeam = false, const bool IgnoreInvincible = true, const bool ObeyIdleVictim = false, const int MatchMask = 0, const char *ObjClass = NULL, const char *ODFName = NULL);
	Handle GetNearestBuilding(const Name Path, const int Point, const float MaxRange = 0.0f, const int Team = -1, const int TeamFilter = 0, const bool UsePTeam = false, const bool IgnoreInvincible = true, const bool ObeyIdleVictim = false, const int MatchMask = 0, const char *ObjClass = NULL, const char *ODFName = NULL);
	Handle GetNearestBuilding(const Vector Position, const float MaxRange = 0.0f, const int Team = -1, const int TeamFilter = 0, const bool UsePTeam = false, const bool IgnoreInvincible = true, const bool ObeyIdleVictim = false, const Handle Me = 0, const int MatchMask = 0, const char *ObjClass = NULL, const char *ODFName = NULL);
	// VSR: the nearest thing that can service a unit: a powerup of the kind ServiceMask asks for (1 = repair, 2 = reload, 4 = local ammo), or a building.
	Handle GetNearestServiceObject(const int ServiceMask, const Matrix Position, const float MaxRange = 0.0f, const int Team = -1, const int TeamFilter = 0, const bool UsePTeam = false, const bool IgnoreInvincible = true, const bool ObeyIdleVictim = false, const int MatchMask = 0, const char *ObjClass = NULL, const char *ODFName = NULL);
	Handle GetNearestServiceObject(const int ServiceMask, const Handle h, const float MaxRange = 0.0f, const int Team = -1, const int TeamFilter = 0, const bool UsePTeam = false, const bool IgnoreInvincible = true, const bool ObeyIdleVictim = false, const int MatchMask = 0, const char *ObjClass = NULL, const char *ODFName = NULL);
	Handle GetNearestServiceObject(const int ServiceMask, const Name Path, const int Point, const float MaxRange = 0.0f, const int Team = -1, const int TeamFilter = 0, const bool UsePTeam = false, const bool IgnoreInvincible = true, const bool ObeyIdleVictim = false, const int MatchMask = 0, const char *ObjClass = NULL, const char *ODFName = NULL);
	Handle GetNearestServiceObject(const int ServiceMask, const Vector Position, const float MaxRange = 0.0f, const int Team = -1, const int TeamFilter = 0, const bool UsePTeam = false, const bool IgnoreInvincible = true, const bool ObeyIdleVictim = false, const Handle Me = 0, const int MatchMask = 0, const char *ObjClass = NULL, const char *ODFName = NULL);

	// Registers (or re-registers, when its ODF changed) a building. NumWeapons is read for gun towers only; the last parameter is the PDB's _Parg,
	// an LTCG placeholder the shipped body never reads.
	void AddBuildingObject(const Handle h, const char* TempODF1, const char* TempODF2, const int Team, const int ODFNameHash, const int ObjClassHash, const int BZCClassHash, const bool CanBeIdleVictim, const int NumWeapons, const bool UnusedArg = false);

	bool Load(bool missionSave);
	bool PostLoad(bool missionSave);
	bool Save(bool missionSave);

	void Execute(BZ1Helper &bz1Helper);
};

#define VSR_LAYOUT_CHECK_BuildingHelper
#include "vsr_layout_asserts.h"
#undef VSR_LAYOUT_CHECK_BuildingHelper

#endif // _buildinghelper_
