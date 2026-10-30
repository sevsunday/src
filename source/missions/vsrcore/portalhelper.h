// PROVENANCE: ancestor reference/ancestor-bz1helper-2015/Shared/PortalHelper.h @6fda4f5 (field comments and the effect-controller doc) | declarations original/missions/Strategy02.pdb via tools/pdb_types.py (SetPortalEffectVeh_Internal's parameter order corrected from the shipped code: Index, FxNumber, unused, Matrix); the two operator==s from reference/decompiled/strategy02-ghidra12.2/src/missions/vsrcore/portalhelper.h.decomp.c (lines 95-421, 436-477) | status: ported
#ifndef _portalhelper_
#define _portalhelper_

#include "ScriptUtils.h"
#include <vector>
#include "objecthelper.h"

class BZ1Helper;

enum PortalEffectState
{
	PortalEffectState_None = 0, // Effect is off.
	PortalEffectState_Opening = 1,
	PortalEffectState_Open = 2,
	PortalEffectState_Closing = 3,
};

// VSR: how a portal picks its destination.
enum PortalMatchType
{
	PortalMatchType_Distance = 0, // The nearest valid portal (own team preferred).
	PortalMatchType_Cycle = 1, // The next portal on the channel, in cycle order.
	PortalMatchType_Random = 2,
};

enum PostTeleportReturnCodes
{
	PostTeleport_DEFAULT = 0, // The DLL may re-aim a Goto that was headed for the entrance.
	PostTeleport_OVERRIDE = 1, // The mission handled it.
};

enum PreTeleportReturnCodes
{
	PreTeleport_DEFAULT = 0, // Normal checks (ammo, filters, tug).
	PreTeleport_ALLOW = 1, // Teleport regardless.
	PreTeleport_DENY = 2,
};

// Teleportals: portals pair up by channel (or by distance / cycle / random), ship things standing in the entrance to the exit matrix of the destination
// with their velocity rotated along, run the emitter-based portal effects, and VSR's portal mines (a pair dropped by one host, one-shot).
class PortalHelper
{
	friend struct VsrLayoutCheck_PortalHelper; // scaffold: QA gate 2 hook (layout asserts); not GBD's
public:
	struct PortalClass
	{
		friend struct VsrLayoutCheck_PortalHelper__PortalClass; // scaffold: QA gate 2 hook (layout asserts); not GBD's
		Handle TeleporterObject; // This Teleporter Object.
		Handle TeleporterDestination; // This Teleporter's Destination Portal.
		int TeleporterEffectSlot; // VSR: the emitter slot (1-based) the current portal effect runs on; 0 = none.
		Handle PortalMineHost; // VSR: the unit that dropped this portal mine (its handle is also the mine's channel); 0 for a building portal.
		bool CanEnter; // Can this Teleporter be entered?
		bool CanExit; // Can this Teleporter be exited?
		bool MatchTypeUsesChannels; // Does the match type respect channels?
		bool ExitForwardOnly; // Ships exit Forward facing only?
		bool ShowChannel; // Show Channel in Name?
		bool NameFlash; // Bool for toggling name flash back and forth.
		bool UseCenter; // Use center or Tap location?
		bool KickAI; // Kick out AI reguardless of entry velocity?
		bool ContinuousFx; // Flag for if this portal uses a continous effect while "connected".
		bool EnterGotoIsExit; // VSR: a unit told to go to this portal goes to its exit point instead.
		bool ScriptOverrideDest; // VSR: a script set the destination (SetPortalDest / ClearPortalDest); the match type is skipped.
		bool FxOnVehicle; // VSR: play the teleport effect at the vehicle instead of on the portal's emitters.
		int MatchType; // PortalMatchType.
		int MatchCycleIndex; // VSR: cycle order.
		int Channel; // Teleporter Channel #.
		int DestTeamFilter; // Team Filter for Destination Locking.
		int TargetTeamFilter; // Team Filter for What to teleport.
		int TeleportFilter; // Filter what types can be teleported, (vehicles, pilots, both).
		int EffectType; // Effect Type. 0 = None? (One Way), 1 = Continuous On, 2 = Build.
		int EffectNumber; // Which Effect number this is currently using.
		int EffectState; // PortalEffectState.
		int EffectTimer[16]; // VSR: remaining turns per emitter slot before it is stopped.
		float EnterRange; // Range for things to be teleported.
		float ExitSpeed; // How fast things exit, if forced out.
		float DestMinRange; // VSR: destinations closer than this are skipped.
		float DestMaxRange; // VSR: destinations farther than this are skipped.
		float CollisionRadius;
		Vector Position; // This portal's position.
		Vector GotoPoint; // Goto nav? (imaginary)
		Matrix ExitPoint; // Point things come out.
		int DestinationIndex; // Index for which Portal object we're locked onto.
		int InEffect; // Which Effect is used for Entering the portal. (during normal operations)
		int OutEffect; // Which Effect is used for Exiting the portal. (during normal operations)
		int OnEffect; // Which Effect is used for ContinousFx. (during normal operations)
		int VehInEffect; // VSR: FxOnVehicle effects.
		int VehOutEffect;
		float ContinuousFxRange; // Distance from which a ship must be for this portal Effect to activate.
		unsigned long TeleportColorFade; // VSR: the player's screen fade colour on teleport.
		char TeleporterName[256]; // Save it's name for NameFlash.
		char EffectBaseODF[MAX_ODF_LENGTH]; // Effect to spawn for Portal. Modified at runtime.
		int EffectHardLifeTime[16]; // VSR: lifeTime of each EffectName%d, in turns.
		char TooFarSound[MAX_ODF_LENGTH]; // VSR: portal mine pair too far apart.
		char TooCloseSound[MAX_ODF_LENGTH];
		char ActivateSound[MAX_ODF_LENGTH];
		char DeactivateSound[MAX_ODF_LENGTH];
		int SoundHandle;

		PortalClass() { memset(this, 0, sizeof(PortalClass)); };

		// GBD: member-by-member compare for PostLoad's resync report; the first difference is logged and ends the compare. TeleportColorFade is not compared (shipped).
		friend bool operator==(const PortalClass &a, const PortalClass &b)
		{
			if (a.TeleporterObject != b.TeleporterObject)
			{
				char ODFNameA[MAX_ODF_LENGTH] = { 0 };
				char ODFNameB[MAX_ODF_LENGTH] = { 0 };
				GetODFName(a.TeleporterObject, ODFNameA);
				GetODFName(b.TeleporterObject, ODFNameB);
				FormatLogMessage("PORTALCLASS MISMATCH: TeleporterObject: %08x '%s' and %08x '%s'", a.TeleporterObject, ODFNameA, b.TeleporterObject, ODFNameB);
				return false;
			}
			if (a.TeleporterDestination != b.TeleporterDestination)
			{
				char ODFNameA[MAX_ODF_LENGTH] = { 0 };
				char ODFNameB[MAX_ODF_LENGTH] = { 0 };
				GetODFName(a.TeleporterDestination, ODFNameA);
				GetODFName(b.TeleporterDestination, ODFNameB);
				FormatLogMessage("PORTALCLASS MISMATCH: TeleporterDestination: %08x '%s' and %08x '%s'", a.TeleporterDestination, ODFNameA, b.TeleporterDestination, ODFNameB);
				return false;
			}
			if (a.TeleporterEffectSlot != b.TeleporterEffectSlot)
			{
				FormatLogMessage("PORTALCLASS MISMATCH: TeleporterEffectSlot: %d and %d", a.TeleporterEffectSlot, b.TeleporterEffectSlot);
				return false;
			}
			if (a.PortalMineHost != b.PortalMineHost)
			{
				char ODFNameA[MAX_ODF_LENGTH] = { 0 };
				char ODFNameB[MAX_ODF_LENGTH] = { 0 };
				GetODFName(a.PortalMineHost, ODFNameA);
				GetODFName(b.PortalMineHost, ODFNameB);
				FormatLogMessage("PORTALCLASS MISMATCH: PortalMineHost: %08x '%s' and %08x '%s'", a.PortalMineHost, ODFNameA, b.PortalMineHost, ODFNameB);
				return false;
			}
#define VSR_PORTAL_BOOL(field) if (a.field != b.field) { FormatLogMessage("PORTALCLASS MISMATCH: " #field ": %d and %d", a.field, b.field); return false; }
			VSR_PORTAL_BOOL(CanEnter)
			VSR_PORTAL_BOOL(CanExit)
			VSR_PORTAL_BOOL(MatchTypeUsesChannels)
			VSR_PORTAL_BOOL(ExitForwardOnly)
			VSR_PORTAL_BOOL(ShowChannel)
			VSR_PORTAL_BOOL(NameFlash)
			VSR_PORTAL_BOOL(UseCenter)
			VSR_PORTAL_BOOL(KickAI)
			VSR_PORTAL_BOOL(ContinuousFx)
			VSR_PORTAL_BOOL(EnterGotoIsExit)
			VSR_PORTAL_BOOL(ScriptOverrideDest)
			VSR_PORTAL_BOOL(FxOnVehicle)
			VSR_PORTAL_BOOL(MatchType)
			VSR_PORTAL_BOOL(MatchCycleIndex)
			VSR_PORTAL_BOOL(Channel)
			VSR_PORTAL_BOOL(DestTeamFilter)
			VSR_PORTAL_BOOL(TargetTeamFilter)
			VSR_PORTAL_BOOL(TeleportFilter)
			VSR_PORTAL_BOOL(EffectType)
			VSR_PORTAL_BOOL(EffectNumber)
			VSR_PORTAL_BOOL(EffectState)
#undef VSR_PORTAL_BOOL
			for (int i = 0; i < 16; i++)
			{
				if (a.EffectTimer[i] != b.EffectTimer[i])
				{
					FormatLogMessage("PORTALCLASS MISMATCH: EffectTimer[%d]: %d and %d", i, a.EffectTimer[i], b.EffectTimer[i]);
					return false;
				}
			}
#define VSR_PORTAL_FLOAT(field) if (a.field != b.field) { FormatLogMessage("PORTALCLASS MISMATCH: " #field ": %f and %f", a.field, b.field); return false; }
			VSR_PORTAL_FLOAT(EnterRange)
			VSR_PORTAL_FLOAT(ExitSpeed)
			VSR_PORTAL_FLOAT(DestMinRange)
			VSR_PORTAL_FLOAT(DestMaxRange)
			VSR_PORTAL_FLOAT(CollisionRadius)
#undef VSR_PORTAL_FLOAT
			if ((a.Position.x != b.Position.x) || (a.Position.y != b.Position.y) || (a.Position.z != b.Position.z))
			{
				FormatLogMessage("PORTALCLASS MISMATCH: Position: %f %f %f and %f %f %f", a.Position.x, a.Position.y, a.Position.z, b.Position.x, b.Position.y, b.Position.z);
				return false;
			}
			if ((a.GotoPoint.x != b.GotoPoint.x) || (a.GotoPoint.y != b.GotoPoint.y) || (a.GotoPoint.z != b.GotoPoint.z))
			{
				FormatLogMessage("PORTALCLASS MISMATCH: GotoPoint: %f %f %f and %f %f %f", a.GotoPoint.x, a.GotoPoint.y, a.GotoPoint.z, b.GotoPoint.x, b.GotoPoint.y, b.GotoPoint.z);
				return false;
			}
			const Matrix &ma = a.ExitPoint;
			const Matrix &mb = b.ExitPoint;
			if ((ma.front.x != mb.front.x) || (ma.front.y != mb.front.y) || (ma.front.z != mb.front.z) ||
				(ma.right.x != mb.right.x) || (ma.right.y != mb.right.y) || (ma.right.z != mb.right.z) ||
				(ma.up.x != mb.up.x) || (ma.up.y != mb.up.y) || (ma.up.z != mb.up.z) ||
				(ma.posit.x != mb.posit.x) || (ma.posit.y != mb.posit.y) || (ma.posit.z != mb.posit.z))
			{
				FormatLogMessage("PORTALCLASS MISMATCH: ExitPoint Front: %f %f %f and %f %f %f, ExitPoint Right: %f %f %f and %f %f %f, ExitPoint Up: %f %f %f and %f %f %f, ExitPoint Posit: %f %f %f and %f %f %f",
					ma.front.x, ma.front.y, ma.front.z, mb.front.x, mb.front.y, mb.front.z,
					ma.right.x, ma.right.y, ma.right.z, mb.right.x, mb.right.y, mb.right.z,
					ma.up.x, ma.up.y, ma.up.z, mb.up.x, mb.up.y, mb.up.z,
					ma.posit.x, ma.posit.y, ma.posit.z, mb.posit.x, mb.posit.y, mb.posit.z);
				return false;
			}
#define VSR_PORTAL_INT(field) if (a.field != b.field) { FormatLogMessage("PORTALCLASS MISMATCH: " #field ": %d and %d", a.field, b.field); return false; }
			VSR_PORTAL_INT(DestinationIndex)
			VSR_PORTAL_INT(InEffect)
			VSR_PORTAL_INT(OutEffect)
			VSR_PORTAL_INT(OnEffect)
			VSR_PORTAL_INT(VehInEffect)
			VSR_PORTAL_INT(VehOutEffect)
#undef VSR_PORTAL_INT
			if (a.ContinuousFxRange != b.ContinuousFxRange)
			{
				FormatLogMessage("PORTALCLASS MISMATCH: ContinuousFxRange: %f and %f", a.ContinuousFxRange, b.ContinuousFxRange);
				return false;
			}
			if (_stricmp(a.TeleporterName, b.TeleporterName) != 0)
			{
				FormatLogMessage("PORTALCLASS MISMATCH: TeleporterName: '%s' and '%s'", a.TeleporterName, b.TeleporterName);
				return false;
			}
			if (_stricmp(a.EffectBaseODF, b.EffectBaseODF) != 0)
			{
				FormatLogMessage("PORTALCLASS MISMATCH: EffectBaseODF: '%s' and '%s'", a.EffectBaseODF, b.EffectBaseODF);
				return false;
			}
			for (int i = 0; i < 16; i++)
			{
				if (a.EffectHardLifeTime[i] != b.EffectHardLifeTime[i])
				{
					FormatLogMessage("PORTALCLASS MISMATCH: EffectHardLifeTime[%d]: %d and %d", i, a.EffectHardLifeTime[i], b.EffectHardLifeTime[i]);
					return false;
				}
			}
#define VSR_PORTAL_STR(field) if (_stricmp(a.field, b.field) != 0) { FormatLogMessage("PORTALCLASS MISMATCH: " #field ": '%s' and '%s'", a.field, b.field); return false; }
			VSR_PORTAL_STR(TooFarSound)
			VSR_PORTAL_STR(TooCloseSound)
			VSR_PORTAL_STR(ActivateSound)
			VSR_PORTAL_STR(DeactivateSound)
#undef VSR_PORTAL_STR
			if (a.SoundHandle != b.SoundHandle)
			{
				FormatLogMessage("PORTALCLASS MISMATCH: SoundHandle: %d and %d", a.SoundHandle, b.SoundHandle);
				return false;
			}
			return true;
		}
	};

	struct TeleportTargetClass
	{
		friend struct VsrLayoutCheck_PortalHelper__TeleportTargetClass; // scaffold: QA gate 2 hook (layout asserts); not GBD's
		Handle TeleportTarget; // This Teleported Object.
		Handle TeleportTargetDestination; // This Teleported Object's Destination Portal.
		int DestinationIndex; // VSR: index of that portal in PortalList.
		float DestEnterRange; // Entrance range, used to tell if this object has left range and is removed from teleporter target list.
		float DistanceFromDestination; // Save its distance so we can remove it sanely. (Squared.)

		TeleportTargetClass() { memset(this, 0, sizeof(TeleportTargetClass)); };

		friend bool operator==(const TeleportTargetClass &a, const TeleportTargetClass &b)
		{
			if (a.TeleportTarget != b.TeleportTarget)
			{
				char ODFNameA[MAX_ODF_LENGTH] = { 0 };
				char ODFNameB[MAX_ODF_LENGTH] = { 0 };
				GetODFName(a.TeleportTarget, ODFNameA);
				GetODFName(b.TeleportTarget, ODFNameB);
				FormatLogMessage("TELEPORTTARGETCLASS MISMATCH: TeleportTarget: %08x '%s' and %08x '%s'", a.TeleportTarget, ODFNameA, b.TeleportTarget, ODFNameB);
				return false;
			}
			if (a.TeleportTargetDestination != b.TeleportTargetDestination)
			{
				char ODFNameA[MAX_ODF_LENGTH] = { 0 };
				char ODFNameB[MAX_ODF_LENGTH] = { 0 };
				GetODFName(a.TeleportTargetDestination, ODFNameA);
				GetODFName(b.TeleportTargetDestination, ODFNameB);
				FormatLogMessage("TELEPORTTARGETCLASS MISMATCH: TeleportTargetDestination: %08x '%s' and %08x '%s'", a.TeleportTargetDestination, ODFNameA, b.TeleportTargetDestination, ODFNameB);
				return false;
			}
			if (a.DestinationIndex != b.DestinationIndex)
			{
				FormatLogMessage("TELEPORTTARGETCLASS MISMATCH: DestinationIndex: %d and %d", a.DestinationIndex, b.DestinationIndex);
				return false;
			}
			if (a.DestEnterRange != b.DestEnterRange)
			{
				FormatLogMessage("TELEPORTTARGETCLASS MISMATCH: DestEnterRange: %f and %f", a.DestEnterRange, b.DestEnterRange);
				return false;
			}
			if (a.DistanceFromDestination != b.DistanceFromDestination)
			{
				FormatLogMessage("TELEPORTTARGETCLASS MISMATCH: DistanceFromDestination: %f and %f", a.DistanceFromDestination, b.DistanceFromDestination);
				return false;
			}
			return true;
		}
	};

private:

	static PortalHelper *m_PortalHelper;

	std::vector<PortalClass> PortalList;
	std::vector<TeleportTargetClass> TeleportTargetList; // Things that just teleported, until they clear the destination's entrance range (+5 m).

	static bool ShouldRemoveTeleportTarget(const TeleportTargetClass &entry);

public:
	PortalHelper();
	~PortalHelper();
	static PortalHelper &Get() { return *m_PortalHelper; }

	// A dead allied portal gets its name back (the channel flash stops).
	void DeadObject(Handle h);

	void AddPortalObject(const Handle h, const char* TempODF1, const char* TempODF2, const int BZCClassHash);
	void AddPortalSwitchObject(const Handle h, const char* TempODF1, const char* TempODF2);

	// Sets and Gets a portal's channel. Get returns -1 if not a valid portal object.
	void SetPortalChannel(const Handle h, const int Channel);
	int GetPortalChannel(const Handle h);

	// Portal Effect controllers. FxNumber is which emitter set to use; Type: 0 = None? Oneway? 1 = Continuous On, 2 = Build (Open then Close).
	// The last parameter is the PDB's; the shipped bodies never read it.
	void SetPortalEffectStart(const Handle h, const int FxNumber = 0, const int Type = 0, const bool UnusedArg = true);
	void SetPortalEffectOn(const Handle h, const int FxNumber = 0, const int Type = 0, const bool UnusedArg = true);
	void SetPortalEffectEnd(const Handle h, const int FxNumber = 0, const int Type = 0, const bool UnusedArg = true);
	void SetPortalEffectVeh(const Handle h, const int FxNumber = 0, const int UnusedArg = 0, const int UnusedArg2 = 0);
	void SetPortalEffectStart_Internal(const int Index, const int FxNumber, const int Type, const bool UnusedArg);
	void SetPortalEffectOn_Internal(const int Index, const int FxNumber, const int Type, const bool UnusedArg);
	void SetPortalEffectEnd_Internal(const int Index, const int FxNumber, const int Type, const bool ReplaceEffect);
	void SetPortalEffectVeh_Internal(const int Index, const int FxNumber, const int UnusedArg, const Matrix pos);
	bool IsPortalEffectActive(const Handle h);

	// VSR: scripted destinations and the cycle order.
	Handle GetPortalDest(const Handle h);
	bool SetPortalDest(const Handle me, const Handle him);
	void ClearPortalDest(const Handle h, const bool ScriptOverride);
	void SwapPortalIndex(const Handle h1, const Handle h2);
	void ShufflePortalUp(const Handle h);
	void ShufflePortalDown(const Handle h);

	bool Load(bool missionSave);
	bool PostLoad(bool missionSave);
	bool Save(bool missionSave);

	void Execute(BZ1Helper &bz1Helper);
	// Teleports one object if it stands in a connected portal's entrance (called from ObjectHelper::Execute for every CanTeleport object).
	void ExecuteObject(const ObjectHelper::ObjectClass &objectInfo);

private:
	void SortCycleList(const int Channel);
	void ShufflePortalUpInternal(const int Index);
	void ShufflePortalDownInternal(const int Index);
	bool PlayPortalSoundFx(const int Index, const int Type, const bool UnusedArg); // Type 0 = activate, else deactivate.
	void ResetPortalDestinations(const int Channel);
};

#define VSR_LAYOUT_CHECK_PortalHelper
#include "vsr_layout_asserts.h"
#undef VSR_LAYOUT_CHECK_PortalHelper

#endif // _portalhelper_
