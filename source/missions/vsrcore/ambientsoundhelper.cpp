// PROVENANCE: ancestor none (decompile-only) | decompile reference/decompiled/strategy02-ghidra12.2/src/missions/vsrcore/ambientsoundhelper.cpp.decomp.c (Load 17-39, LoadAmbientSoundInfo 55-94, Execute 97-184; Save inlined into BZ1Helper::Save) + dumpbin of 4fc14017 / 4fc140d9 / 4fc1434e for the register-passed arguments | status: ported
#include "bz1helper.h"
#include "ambientsoundhelper.h"
#include "bzcscriptutils.h"
#include "mathutils.h"

AmbientSoundHelper::AmbientAudioInfo TempAmbientSoundBuffer[MAX_AMBIENT_SOUNDS]; // GBD: the slots as they stood before a Load, for the resync report.

AmbientSoundHelper::AmbientSoundHelper()
{
	memset(&ambientAudioInfo, 0, sizeof(ambientAudioInfo));
}

// GBD: snapshots the slots, reads them one by one (every Read's result counts), then reports the first slot that changed.
bool AmbientSoundHelper::Load(bool missionSave)
{
	if (missionSave)
		return true;

	for (int i = 0; i < MAX_AMBIENT_SOUNDS; i++)
		TempAmbientSoundBuffer[i] = ambientAudioInfo[i];

	bool ret = true;
	for (int i = 0; i < MAX_AMBIENT_SOUNDS; i++)
		ret = ret && Read(&ambientAudioInfo[i], sizeof(AmbientAudioInfo));

	for (int i = 0; i < MAX_AMBIENT_SOUNDS; i++)
	{
		if (!(TempAmbientSoundBuffer[i] == ambientAudioInfo[i]))
		{
			FormatLogMessage("AmbientAudioInfo Load Mismatch Index: %d", i);
			break;
		}
	}

	return ret;
}

bool AmbientSoundHelper::Save(bool missionSave)
{
	if (missionSave)
		return true;

	bool ret = true;
	for (int i = 0; i < MAX_AMBIENT_SOUNDS; i++)
		ret = ret && Write(&ambientAudioInfo[i], sizeof(AmbientAudioInfo));

	return ret;
}

// read in the ambient sound list from the map trn.
void AmbientSoundHelper::LoadAmbientSoundInfo(const char *mapTrnFile)
{
	if (OpenODF2(mapTrnFile))
	{
		const Vector NullVector(0.0f, 0.0f, 0.0f);
		for (int i = 0; i < MAX_AMBIENT_SOUNDS; i++)
		{
			AmbientAudioInfo &sao = ambientAudioInfo[i];
			char DesiredValue[MAX_ODF_LENGTH] = {0};

			sprintf_s(DesiredValue, "AmbientSound%d", i+1);
			GetODFString(mapTrnFile, "Audio", DesiredValue, MAX_ODF_LENGTH, sao.AudioFile, NULL);
			sprintf_s(DesiredValue, "Position%d", i+1);
			GetODFVector(mapTrnFile, "Audio", DesiredValue, &sao.Position, NullVector);
			sprintf_s(DesiredValue, "IsMusic%d", i+1);
			GetODFBool(mapTrnFile, "Audio", DesiredValue, &sao.IsMusic, false);

			sprintf_s(DesiredValue, "MinDelay%d", i+1);
			float MinDelay = 0.0f;
			GetODFFloat(mapTrnFile, "Audio", DesiredValue, &MinDelay, 0.0f);
			sao.MinDelay = SecondsToTurns(MinDelay);
			sprintf_s(DesiredValue, "MaxDelay%d", i+1);
			float MaxDelay = 0.0f;
			GetODFFloat(mapTrnFile, "Audio", DesiredValue, &MaxDelay, 0.0f);
			sao.MaxDelay = SecondsToTurns(MaxDelay);

			sprintf_s(DesiredValue, "BasePan%d", i+1);
			GetODFFloat(mapTrnFile, "Audio", DesiredValue, &sao.BasePan, 0.0f);
			sao.BasePan = clamp(sao.BasePan, -1.0f, 1.0f);
			sprintf_s(DesiredValue, "PanVariance%d", i+1);
			GetODFFloat(mapTrnFile, "Audio", DesiredValue, &sao.PanVariance, 0.0f);
			sao.PanVariance = clamp(sao.PanVariance, 0.0f, 1.0f);
			sprintf_s(DesiredValue, "Rate%d", i+1);
			GetODFFloat(mapTrnFile, "Audio", DesiredValue, &sao.Rate, 44100.0f);
			sao.Rate = clamp(sao.Rate, 0.0f, 44100.0f);
		}
	}
}

void AmbientSoundHelper::Execute(BZ1Helper & /*bz1Helper*/)
{
	for (int i = 0; i < MAX_AMBIENT_SOUNDS; i++)
	{
		AmbientAudioInfo &sao = ambientAudioInfo[i];

		if (!sao.AudioFile[0] || !DoesFileExist(sao.AudioFile) || sao.TriggerTurn > BZ1Helper::m_TurnCounter)
			continue;

		DLLAudioHandle AudioHandle = sao.AudioHandle;
		if (!IsAudioPlaying(AudioHandle))
		{
			if (sao.MaxDelay <= 0)
			{
				// A bed: start it looping and leave it alone.
				if (IsNullVector(sao.Position))
					sao.AudioHandle = StartAudio2D(sao.AudioFile, -1.0f, sao.BasePan, sao.Rate, true, sao.IsMusic);
				else
					sao.AudioHandle = StartAudio3D(sao.AudioFile, sao.Position, sao.IsMusic ? AUDIO_CAT_MUSIC : AUDIO_CAT_AMBIENT, true);
			}
			else
			{
				// A re-fired sound: play it, then schedule the next one a random delay after it ends.
				if (IsNullVector(sao.Position))
				{
					float Pan = sao.BasePan;
					float Variance = sao.PanVariance;
					if (Variance > 0.0f)
					{
						Variance = GetRandomFloat(0.0f, Variance);
						if (GetRandomFloat(1.0f) > 0.5f)
							Variance = -Variance;
						Pan = Variance + Pan;
						if (GetRandomFloat(1.0f) > 0.5f)
							Pan = -Pan;
						if (Pan < -1.0f)
							Pan = -1.0f;
						else if (Pan > 1.0f)
							Pan = 1.0f;
					}
					sao.AudioHandle = StartAudio2D(sao.AudioFile, -1.0f, Pan, sao.Rate, true, sao.IsMusic); // as shipped: the 2D re-fired sound is started looping, the 3D one is not.
				}
				else
				{
					sao.AudioHandle = StartAudio3D(sao.AudioFile, sao.Position, sao.IsMusic ? AUDIO_CAT_MUSIC : AUDIO_CAT_AMBIENT, false);
				}
				sao.AudioLength = SecondsToTurns(GetAudioFileDuration(sao.AudioHandle));
				sao.TriggerTurn = GetRandomInt(sao.MinDelay, sao.MaxDelay) + BZ1Helper::m_TurnCounter + sao.AudioLength;
			}
		}
		else if (sao.MaxDelay > 0)
		{
			// Still playing past its slot: forget the handle so the next tick re-fires it.
			if (sao.TriggerTurn - sao.AudioLength <= BZ1Helper::m_TurnCounter)
				sao.AudioHandle = 0;
		}
	}
}
