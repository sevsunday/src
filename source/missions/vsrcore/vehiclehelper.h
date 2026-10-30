// PROVENANCE: no ancestor file (the 2015 BZ1Helper kept these fields on ObjectClass; reference/ancestor-bz1helper-2015/Shared/BZ1Helper.h @6fda4f5 lines 348-376) | declarations original/missions/Strategy02.pdb via tools/pdb_types.py; operator== from reference/decompiled/strategy02-ghidra12.2/src/missions/vsrcore/vehiclehelper.h.decomp.c (lines 46-164) | status: ported
#ifndef _VehicleHelper_
#define _VehicleHelper_

#include "ScriptUtils.h"
#include "bzcscriptutils.h"
#include <vector>

class BZ1Helper;

// Per-vehicle state the per-tick loop needs: the Hunt-command work-arounds, remote control, skill display and the cloak energy gauge.
class VehicleHelper
{
	friend struct VsrLayoutCheck_VehicleHelper; // scaffold: QA gate 2 hook (layout asserts); not GBD's
public:

	struct VehicleClass {
		friend struct VsrLayoutCheck_VehicleHelper__VehicleClass; // scaffold: QA gate 2 hook (layout asserts); not GBD's
		Handle ObjectHandle; // The handle.
		unsigned int ODFNameHash; // FNV-1a Hash of the ODF Name.
		unsigned int ObjClassHash; // FNV-1a Hash of the ObjClass.
		unsigned int BZCClassHash; // FNV-1a Hash of the BZCClasslabel.
		int LastCommand; // The command it had last tick.
		int MaxHealth; // Its health capacity when added.
		bool ShowSkill; // Show the skill level in the name?
		bool BlockDeploy; // Cloak ran dry: keep it undeployed until the energy is back to full.
		bool AllowRemoteControl; // Hunt on this unit hands it to the team's player (satellite remote control).
		bool HuntIsResupply; // Hunt on this unit means "go get repaired / reloaded".
		bool CanBeIdleVictim; // Can the idle-unit code pick on this?
		int ShowSkillTeamFilter; // Which teams see the skill level.
		int ShowSkillTimer; // Turns until the next skill refresh.
		int CurTeamNum; // Current Team num, stored to preseve calls to GetTeamNum. Updated once every tick.
		int PTeam; // Current perceived team. Updated once every tick.
		long CloakMaxEnergy; // Cloak energy capacity; 0 = no cloak gauge on this unit.
		long CloakCurEnergy; // Current cloak energy.
		long CloakCostEnergy; // Energy drained per second while deployed (cloaked).
		long CloakAddEnergy; // Energy regained per second while undeployed.
		float CloakCurEnergyRemainder; // Sub-unit carry between ticks.
		float EngageRange; // Store it's engageRange.
		Vector Position; // It's current position.

		VehicleClass() { memset(this, 0, sizeof(VehicleClass)); };

		// GBD: member-by-member compare for PostLoad's resync report; the first difference is logged and ends the compare.
		// The shipped compare skips HuntIsResupply and CloakCurEnergyRemainder (kept that way for parity).
		friend bool operator==(const VehicleClass &a, const VehicleClass &b)
		{
			if (a.ObjectHandle != b.ObjectHandle)
			{
				char ODFNameA[MAX_ODF_LENGTH] = { 0 };
				char ODFNameB[MAX_ODF_LENGTH] = { 0 };
				GetODFName(a.ObjectHandle, ODFNameA);
				GetODFName(b.ObjectHandle, ODFNameB);
				FormatLogMessage("VEHICLELIST MISMATCH: ObjectHandle: %08x '%s' and %08x '%s'", a.ObjectHandle, ODFNameA, b.ObjectHandle, ODFNameB);
				return false;
			}
			if (a.ODFNameHash != b.ODFNameHash)
			{
				FormatLogMessage("VEHICLELIST MISMATCH: ODFNameHash: %d and %d", a.ODFNameHash, b.ODFNameHash);
				return false;
			}
			if (a.ObjClassHash != b.ObjClassHash)
			{
				FormatLogMessage("VEHICLELIST MISMATCH: ObjClassHash: %d and %d", a.ObjClassHash, b.ObjClassHash);
				return false;
			}
			if (a.BZCClassHash != b.BZCClassHash)
			{
				FormatLogMessage("VEHICLELIST MISMATCH: BZCClassHash: %d and %d", a.BZCClassHash, b.BZCClassHash);
				return false;
			}
			if (a.LastCommand != b.LastCommand)
			{
				FormatLogMessage("VEHICLELIST MISMATCH: LastCommand: %d and %d", a.LastCommand, b.LastCommand);
				return false;
			}
			if (a.MaxHealth != b.MaxHealth)
			{
				FormatLogMessage("VEHICLELIST MISMATCH: MaxHealth: %d and %d", a.MaxHealth, b.MaxHealth);
				return false;
			}
			if (a.ShowSkill != b.ShowSkill)
			{
				FormatLogMessage("VEHICLELIST MISMATCH: ShowSkill: %d and %d", a.ShowSkill, b.ShowSkill);
				return false;
			}
			if (a.BlockDeploy != b.BlockDeploy)
			{
				FormatLogMessage("VEHICLELIST MISMATCH: BlockDeploy: %d and %d", a.BlockDeploy, b.BlockDeploy);
				return false;
			}
			if (a.AllowRemoteControl != b.AllowRemoteControl)
			{
				FormatLogMessage("VEHICLELIST MISMATCH: AllowRemoteControl: %d and %d", a.AllowRemoteControl, b.AllowRemoteControl);
				return false;
			}
			if (a.CanBeIdleVictim != b.CanBeIdleVictim)
			{
				FormatLogMessage("VEHICLELIST MISMATCH: CanBeIdleVictim: %d and %d", a.CanBeIdleVictim, b.CanBeIdleVictim);
				return false;
			}
			if (a.ShowSkillTeamFilter != b.ShowSkillTeamFilter)
			{
				FormatLogMessage("VEHICLELIST MISMATCH: ShowSkillTeamFilter: %d and %d", a.ShowSkillTeamFilter, b.ShowSkillTeamFilter);
				return false;
			}
			if (a.ShowSkillTimer != b.ShowSkillTimer)
			{
				FormatLogMessage("VEHICLELIST MISMATCH: ShowSkillTimer: %d and %d", a.ShowSkillTimer, b.ShowSkillTimer);
				return false;
			}
			if (a.CurTeamNum != b.CurTeamNum)
			{
				FormatLogMessage("VEHICLELIST MISMATCH: CurTeamNum: %d and %d", a.CurTeamNum, b.CurTeamNum);
				return false;
			}
			if (a.PTeam != b.PTeam)
			{
				FormatLogMessage("VEHICLELIST MISMATCH: PTeam: %d and %d", a.PTeam, b.PTeam);
				return false;
			}
			if (a.CloakMaxEnergy != b.CloakMaxEnergy)
			{
				FormatLogMessage("VEHICLELIST MISMATCH: CloakMaxEnergy: %d and %d", a.CloakMaxEnergy, b.CloakMaxEnergy);
				return false;
			}
			if (a.CloakCurEnergy != b.CloakCurEnergy)
			{
				FormatLogMessage("VEHICLELIST MISMATCH: CloakCurEnergy: %d and %d", a.CloakCurEnergy, b.CloakCurEnergy);
				return false;
			}
			if (a.CloakCostEnergy != b.CloakCostEnergy)
			{
				FormatLogMessage("VEHICLELIST MISMATCH: CloakCostEnergy: %d and %d", a.CloakCostEnergy, b.CloakCostEnergy);
				return false;
			}
			if (a.CloakAddEnergy != b.CloakAddEnergy)
			{
				FormatLogMessage("VEHICLELIST MISMATCH: CloakAddEnergy: %d and %d", a.CloakAddEnergy, b.CloakAddEnergy);
				return false;
			}
			if (a.EngageRange != b.EngageRange)
			{
				FormatLogMessage("VEHICLELIST MISMATCH: EngageRange: %f and %f", a.EngageRange, b.EngageRange);
				return false;
			}
			if (a.Position != b.Position)
			{
				FormatLogMessage("VEHICLELIST MISMATCH: Position: %f %f %f and %f %f %f", a.Position.x, a.Position.y, a.Position.z, b.Position.x, b.Position.y, b.Position.z);
				return false;
			}
			return true;
		}
	};

private:

	std::vector<VehicleClass> VehicleList;
	static bool ShouldRemoveVehicle(const VehicleClass &entry) { return !IsAround(entry.ObjectHandle); }

public:
	VehicleHelper();
	~VehicleHelper();

	bool Load(bool missionSave);
	bool PostLoad(bool missionSave);
	bool Save(bool missionSave);

	int GetNumVehicles() { return int(VehicleList.size()); }
	const VehicleClass &GetVehicleInfo(int index) const { return VehicleList[index]; } // Read only version.
	VehicleClass &RefVehicleInfo(int index) { return VehicleList[index]; }

	// Appends a zeroed entry and returns its index (BZ1Helper::AddObject fills it in).
	int NewVehicle() { VehicleList.emplace_back(); return int(VehicleList.size()) - 1; }

	// Drops the vehicles that are gone, then per vehicle: team / position / perceived team, the Hunt work-arounds, skill display, cloak energy.
	void Execute(BZ1Helper &bz1Helper);
};

#define VSR_LAYOUT_CHECK_VehicleHelper
#include "vsr_layout_asserts.h"
#undef VSR_LAYOUT_CHECK_VehicleHelper

#endif
