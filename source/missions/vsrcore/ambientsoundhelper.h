// PROVENANCE: ancestor none (decompile-only; the 2015 tree has no ambient-sound code) | declarations original/missions/Strategy02.pdb via tools/pdb_types.py; operator== from reference/decompiled/strategy02-ghidra12.2/src/missions/vsrcore/ambientsoundhelper.h.decomp.c (lines 30-101) | status: ported
#ifndef _AmbientSoundHelper_
#define _AmbientSoundHelper_

#include "ScriptUtils.h"
#include "bzcscriptutils.h"

class BZ1Helper;

#define MAX_AMBIENT_SOUNDS 32

// Map-authored ambient sounds ([Audio] AmbientSound1..32 in the .trn): looping beds, or one-shots re-fired after a random delay, 2D or placed in the world.
class AmbientSoundHelper
{
	friend struct VsrLayoutCheck_AmbientSoundHelper; // scaffold: QA gate 2 hook (layout asserts); not GBD's
public:

	struct AmbientAudioInfo {
		friend struct VsrLayoutCheck_AmbientSoundHelper__AmbientAudioInfo; // scaffold: QA gate 2 hook (layout asserts); not GBD's
		DLLAudioHandle AudioHandle; // The playing sound, 0 when none.
		char AudioFile[MAX_ODF_LENGTH]; // The sound file; empty = unused slot.
		int MinDelay; // Turns between plays, random in [MinDelay, MaxDelay]. MaxDelay <= 0 = one looping bed.
		int MaxDelay;
		bool IsMusic; // Music volume slider / category instead of ambient.
		float BasePan; // 2D only: -1 .. 1.
		float PanVariance; // 2D only: random pan offset, 0 .. 1.
		float Rate; // Sample rate, 0 .. 44100.
		int TriggerTurn; // Turn of the next play.
		int AudioLength; // Length of the last play in turns.
		Vector Position; // Null vector = 2D sound.

		AmbientAudioInfo() { memset(this, 0, sizeof(AmbientAudioInfo)); };

		// GBD: member-by-member compare for Load's resync report; the first difference is logged and ends the compare.
		friend bool operator==(const AmbientAudioInfo &a, const AmbientAudioInfo &b)
		{
			if (a.AudioHandle != b.AudioHandle)
			{
				FormatLogMessage("AMBIENTAUDIOCLASS MISMATCH: AudioHandle: %d and %d", a.AudioHandle, b.AudioHandle);
				return false;
			}
			if (_stricmp(a.AudioFile, b.AudioFile) != 0)
			{
				FormatLogMessage("AMBIENTAUDIOCLASS MISMATCH: AudioFile: '%s' and '%s'", a.AudioFile, b.AudioFile);
				return false;
			}
			if (a.MinDelay != b.MinDelay)
			{
				FormatLogMessage("AMBIENTAUDIOCLASS MISMATCH: MinDelay: %d and %d", a.MinDelay, b.MinDelay);
				return false;
			}
			if (a.MaxDelay != b.MaxDelay)
			{
				FormatLogMessage("AMBIENTAUDIOCLASS MISMATCH: MaxDelay: %d and %d", a.MaxDelay, b.MaxDelay);
				return false;
			}
			if (a.IsMusic != b.IsMusic)
			{
				FormatLogMessage("AMBIENTAUDIOCLASS MISMATCH: IsMusic: %d and %d", a.IsMusic, b.IsMusic);
				return false;
			}
			if (a.BasePan != b.BasePan)
			{
				FormatLogMessage("AMBIENTAUDIOCLASS MISMATCH: BasePan: %f and %f", a.BasePan, b.BasePan);
				return false;
			}
			if (a.PanVariance != b.PanVariance)
			{
				FormatLogMessage("AMBIENTAUDIOCLASS MISMATCH: PanVariance: %f and %f", a.PanVariance, b.PanVariance);
				return false;
			}
			if (a.Rate != b.Rate)
			{
				FormatLogMessage("AMBIENTAUDIOCLASS MISMATCH: Rate: %f and %f", a.Rate, b.Rate);
				return false;
			}
			if (a.TriggerTurn != b.TriggerTurn)
			{
				FormatLogMessage("AMBIENTAUDIOCLASS MISMATCH: TriggerTurn: %d and %d", a.TriggerTurn, b.TriggerTurn);
				return false;
			}
			if (a.AudioLength != b.AudioLength)
			{
				FormatLogMessage("AMBIENTAUDIOCLASS MISMATCH: AudioLength: %d and %d", a.AudioLength, b.AudioLength);
				return false;
			}
			if (a.Position != b.Position)
			{
				FormatLogMessage("AMBIENTAUDIOCLASS MISMATCH: Position: %f %f %f and %f %f %f", a.Position.x, a.Position.y, a.Position.z, b.Position.x, b.Position.y, b.Position.z);
				return false;
			}
			return true;
		}
	};

private:

	AmbientAudioInfo ambientAudioInfo[MAX_AMBIENT_SOUNDS];

public:
	AmbientSoundHelper();

	bool Load(bool missionSave);
	bool Save(bool missionSave);

	void Execute(BZ1Helper &bz1Helper);

	// read in the ambient sound list from the map trn.
	void LoadAmbientSoundInfo(const char *mapTrnFile);
};

#define VSR_LAYOUT_CHECK_AmbientSoundHelper
#include "vsr_layout_asserts.h"
#undef VSR_LAYOUT_CHECK_AmbientSoundHelper

#endif
