// PROVENANCE: ancestor reference/ancestor-bz1helper-2015/Shared/AttacherHelper.h @6fda4f5 (field comments; the per-tap arrays became an AttacherTapClass) | declarations original/missions/Strategy02.pdb via tools/pdb_types.py; operator== from reference/decompiled/strategy02-ghidra12.2/src/missions/vsrcore/attacherhelper.h.decomp.c (lines 50-206) | status: ported
#ifndef _attacherhelper_
#define _attacherhelper_

#include "ScriptUtils.h"
#include <vector>

class BZ1Helper;

// Attacher Code added because I got tired of waiting for N1's version... -GBD
// A host ODF names up to MAX_TAPS AttachedObject%d ODFs; this builds them, rides them on the host (position, velocity, team, weapon symmetry),
// aims them (host target, own AI target, PDS mode, coordinated fire) and runs the Cerberus tail swings.
class AttacherHelper
{
	friend struct VsrLayoutCheck_AttacherHelper; // scaffold: QA gate 2 hook (layout asserts); not GBD's
public:
	struct AttacherTapClass
	{
		friend struct VsrLayoutCheck_AttacherHelper__AttacherTapClass; // scaffold: QA gate 2 hook (layout asserts); not GBD's
		Handle TapObject; // This Attacher's Attached Object.
		bool TapIndependance; // Independance setting.
		bool TapIsAttacking; // Is it attacking currently?
		bool BuiltAttacherTap; // Has the object been built? (we build objects in execute, not addobject)
		bool TapShutOff; // Shutoff flag if the host object is empty.
		bool TapCoordinateFire; // Coordinate fire or try to find seperate Targets?
		bool PDSMode; // Is this Tap in PDS mode? (Only target Weapons and Persons)
		bool IsHostDeployed; // Bool for playing animation.
		int TapDeployBehavior; // -1 = always on, 0 = only exist while undeployed, 1 = only exist while deployed.
		float TapEngageRange; // Engage Range :D
		Vector TapOffset; // XYZ Offset for this tap.
		Vector TapRotation; // XYZ Rotation for this tap.
		char TapWeaponSymmetryMask[MAX_HARDPOINTS+1]; // Bitmask weaponmask flag for which weapons from host to symmetry copy over to tap.
		// Special Cerberus functions.
		bool IsCerberusTail; // Flag for if this tap is a Cerberus Tail.
		bool IsCerberusTailAnimated; // Flag for if the Cerberus unit has the 3 Tail animations.
		int CerbTailSwinging; // Is it swinging? 0 = No, 1 = Left, 2 = Right.
		float CerbTailConeAngle; // Cone Angle for firing the Tail.
		float CerbAnimLength; // Current Animation Length;
		Matrix TapPosition; // It's last known Position Matrix.

		AttacherTapClass() { memset(this, 0, sizeof(AttacherTapClass)); };
	};

	struct AttacherClass
	{
		friend struct VsrLayoutCheck_AttacherHelper__AttacherClass; // scaffold: QA gate 2 hook (layout asserts); not GBD's
		Handle AttacherObject; // This Attacher Object Object.
		int NumberOfTaps; // Save the number of taps.
		bool IsCerberus; // Is this host a Cerberus class ship?
		AttacherTapClass Tap[MAX_TAPS];

		AttacherClass() { memset(this, 0, sizeof(AttacherClass)); };

		// GBD: member-by-member compare for PostLoad's resync report; the first difference is logged and ends the compare.
		// All MAX_TAPS taps are compared, not just NumberOfTaps; the TapPosition message says REPLACEONDEATHCLASS (sic), kept for parity.
		friend bool operator==(const AttacherClass &a, const AttacherClass &b)
		{
			if (a.AttacherObject != b.AttacherObject)
			{
				char ODFNameA[MAX_ODF_LENGTH] = { 0 };
				char ODFNameB[MAX_ODF_LENGTH] = { 0 };
				GetODFName(a.AttacherObject, ODFNameA);
				GetODFName(b.AttacherObject, ODFNameB);
				FormatLogMessage("ATTACHERCLASS MISMATCH: AttacherObject: %08x '%s' and %08x '%s'", a.AttacherObject, ODFNameA, b.AttacherObject, ODFNameB);
				return false;
			}
			if (a.NumberOfTaps != b.NumberOfTaps)
			{
				FormatLogMessage("ATTACHERCLASS MISMATCH: NumberOfTaps: %d and %d", a.NumberOfTaps, b.NumberOfTaps);
				return false;
			}
			if (a.IsCerberus != b.IsCerberus)
			{
				FormatLogMessage("ATTACHERCLASS MISMATCH: IsCerberus: %d and %d", a.IsCerberus, b.IsCerberus);
				return false;
			}
			for (int i = 0; i < MAX_TAPS; i++)
			{
				const AttacherTapClass &ta = a.Tap[i];
				const AttacherTapClass &tb = b.Tap[i];
				if (ta.TapObject != tb.TapObject)
				{
					char ODFNameA[MAX_ODF_LENGTH] = { 0 };
					char ODFNameB[MAX_ODF_LENGTH] = { 0 };
					GetODFName(ta.TapObject, ODFNameA);
					GetODFName(tb.TapObject, ODFNameB);
					FormatLogMessage("ATTACHERTAPCLASS MISMATCH: Tap%d TapObject: %08x '%s' and %08x '%s'", i, ta.TapObject, ODFNameA, tb.TapObject, ODFNameB);
					return false;
				}
				if (ta.TapIndependance != tb.TapIndependance)
				{
					FormatLogMessage("ATTACHERTAPCLASS MISMATCH: Tap%d TapIndependance: %d and %d", i, ta.TapIndependance, tb.TapIndependance);
					return false;
				}
				if (ta.TapIsAttacking != tb.TapIsAttacking)
				{
					FormatLogMessage("ATTACHERTAPCLASS MISMATCH: Tap%d TapIsAttacking: %d and %d", i, ta.TapIsAttacking, tb.TapIsAttacking);
					return false;
				}
				if (ta.BuiltAttacherTap != tb.BuiltAttacherTap)
				{
					FormatLogMessage("ATTACHERTAPCLASS MISMATCH: Tap%d BuiltAttacherTap: %d and %d", i, ta.BuiltAttacherTap, tb.BuiltAttacherTap);
					return false;
				}
				if (ta.TapShutOff != tb.TapShutOff)
				{
					FormatLogMessage("ATTACHERTAPCLASS MISMATCH: Tap%d TapShutOff: %d and %d", i, ta.TapShutOff, tb.TapShutOff);
					return false;
				}
				if (ta.TapCoordinateFire != tb.TapCoordinateFire)
				{
					FormatLogMessage("ATTACHERTAPCLASS MISMATCH: Tap%d TapCoordinateFire: %d and %d", i, ta.TapCoordinateFire, tb.TapCoordinateFire);
					return false;
				}
				if (ta.PDSMode != tb.PDSMode)
				{
					FormatLogMessage("ATTACHERTAPCLASS MISMATCH: Tap%d PDSMode: %d and %d", i, ta.PDSMode, tb.PDSMode);
					return false;
				}
				if (ta.IsHostDeployed != tb.IsHostDeployed)
				{
					FormatLogMessage("ATTACHERTAPCLASS MISMATCH: Tap%d IsHostDeployed: %d and %d", i, ta.IsHostDeployed, tb.IsHostDeployed);
					return false;
				}
				if (ta.TapDeployBehavior != tb.TapDeployBehavior)
				{
					FormatLogMessage("ATTACHERTAPCLASS MISMATCH: Tap%d TapDeployBehavior: %d and %d", i, ta.TapDeployBehavior, tb.TapDeployBehavior);
					return false;
				}
				if (ta.TapEngageRange != tb.TapEngageRange)
				{
					FormatLogMessage("ATTACHERTAPCLASS MISMATCH: Tap%d TapEngageRange: %f and %f", i, ta.TapEngageRange, tb.TapEngageRange);
					return false;
				}
				if ((ta.TapOffset.x != tb.TapOffset.x) || (ta.TapOffset.y != tb.TapOffset.y) || (ta.TapOffset.z != tb.TapOffset.z))
				{
					FormatLogMessage("ATTACHERTAPCLASS MISMATCH: Tap%d TapOffset: %f %f %f and %f %f %f", i, ta.TapOffset.x, ta.TapOffset.y, ta.TapOffset.z, tb.TapOffset.x, tb.TapOffset.y, tb.TapOffset.z);
					return false;
				}
				if ((ta.TapRotation.x != tb.TapRotation.x) || (ta.TapRotation.y != tb.TapRotation.y) || (ta.TapRotation.z != tb.TapRotation.z))
				{
					FormatLogMessage("ATTACHERTAPCLASS MISMATCH: Tap%d TapRotation: %f %f %f and %f %f %f", i, ta.TapRotation.x, ta.TapRotation.y, ta.TapRotation.z, tb.TapRotation.x, tb.TapRotation.y, tb.TapRotation.z);
					return false;
				}
				if (_stricmp(ta.TapWeaponSymmetryMask, tb.TapWeaponSymmetryMask) != 0)
				{
					FormatLogMessage("ATTACHERTAPCLASS MISMATCH: Tap%d TapWeaponSymmetryMask: '%s' and '%s'", i, ta.TapWeaponSymmetryMask, tb.TapWeaponSymmetryMask);
					return false;
				}
				if (ta.IsCerberusTail != tb.IsCerberusTail)
				{
					FormatLogMessage("ATTACHERTAPCLASS MISMATCH: Tap%d IsCerberusTail: %d and %d", i, ta.IsCerberusTail, tb.IsCerberusTail);
					return false;
				}
				if (ta.IsCerberusTailAnimated != tb.IsCerberusTailAnimated)
				{
					FormatLogMessage("ATTACHERTAPCLASS MISMATCH: Tap%d IsCerberusTailAnimated: %d and %d", i, ta.IsCerberusTailAnimated, tb.IsCerberusTailAnimated);
					return false;
				}
				if (ta.CerbTailSwinging != tb.CerbTailSwinging)
				{
					FormatLogMessage("ATTACHERTAPCLASS MISMATCH: Tap%d CerbTailSwinging: %d and %d", i, ta.CerbTailSwinging, tb.CerbTailSwinging);
					return false;
				}
				if (ta.CerbTailConeAngle != tb.CerbTailConeAngle)
				{
					FormatLogMessage("ATTACHERTAPCLASS MISMATCH: Tap%d CerbTailConeAngle: %f and %f", i, ta.CerbTailConeAngle, tb.CerbTailConeAngle);
					return false;
				}
				if (ta.CerbAnimLength != tb.CerbAnimLength)
				{
					FormatLogMessage("ATTACHERTAPCLASS MISMATCH: Tap%d CerbAnimLength: %f and %f", i, ta.CerbAnimLength, tb.CerbAnimLength);
					return false;
				}
				const Matrix &ma = ta.TapPosition;
				const Matrix &mb = tb.TapPosition;
				if ((ma.front.x != mb.front.x) || (ma.front.y != mb.front.y) || (ma.front.z != mb.front.z) ||
					(ma.right.x != mb.right.x) || (ma.right.y != mb.right.y) || (ma.right.z != mb.right.z) ||
					(ma.up.x != mb.up.x) || (ma.up.y != mb.up.y) || (ma.up.z != mb.up.z) ||
					(ma.posit.x != mb.posit.x) || (ma.posit.y != mb.posit.y) || (ma.posit.z != mb.posit.z))
				{
					FormatLogMessage("REPLACEONDEATHCLASS MISMATCH: Tap%d TapPosition Front: %f %f %f and %f %f %f, Tap%d TapPosition Right: %f %f %f and %f %f %f, Tap%d TapPosition Up: %f %f %f and %f %f %f, Tap%d TapPosition Posit: %f %f %f and %f %f %f",
						i, ma.front.x, ma.front.y, ma.front.z, mb.front.x, mb.front.y, mb.front.z,
						i, ma.right.x, ma.right.y, ma.right.z, mb.right.x, mb.right.y, mb.right.z,
						i, ma.up.x, ma.up.y, ma.up.z, mb.up.x, mb.up.y, mb.up.z,
						i, ma.posit.x, ma.posit.y, ma.posit.z, mb.posit.x, mb.posit.y, mb.posit.z);
					return false;
				}
			}
			return true;
		}
	};

private:

	// The attacher list.
	std::vector<AttacherClass> AttacherList;

public:
	AttacherHelper();
	~AttacherHelper();

	// Registers a host that names at least one AttachedObject%d. ODFName is the host's own ODF (so it can't attach itself).
	void AddAttacherObject(const Handle h, const char* TempODF1, const char* TempODF2, const int BZCClassHash, const char* ODFName);

	bool Load(bool missionSave);
	bool PostLoad(bool missionSave);
	bool Save(bool missionSave);

	void Execute(BZ1Helper &bz1Helper);
};

#define VSR_LAYOUT_CHECK_AttacherHelper
#include "vsr_layout_asserts.h"
#undef VSR_LAYOUT_CHECK_AttacherHelper

#endif // _attacherhelper_
