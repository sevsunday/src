// PROVENANCE: ancestor reference/ancestor-bz1helper-2015/Shared/MorphObjectHelper.cpp @6fda4f5 (host / toggle registration, the switch and ammo logic, AI cloaking, GetSwitchMineODF) | decompile reference/decompiled/strategy02-ghidra12.2/src/missions/vsrcore/morphobjecthelper.cpp.decomp.c (PostLoad 60-85, AddMorphObjectHostObject 88-134, AddMorphObjectToggleObject 137-177, Execute 180-514, GetSwitchMineODF 518-542, PrePickupPowerup 546-577; Load / Save inlined into BZ1Helper) | status: ported
#include "bz1helper.h"
#include "morphobjecthelper.h"
#include "dispatchhelper.h"
#include "bzcscriptutils.h"
#include <algorithm>

MorphObjectHelper *MorphObjectHelper::m_MorphObjectHelper;

std::vector<MorphObjectHelper::MorphObjectClass> TempMorphObjectBuffer; // GBD: the list as it stood before a Load, for PostLoad's resync report.

MorphObjectHelper::MorphObjectHelper()
{
	m_MorphObjectHelper = this;
}
MorphObjectHelper::~MorphObjectHelper()
{
	m_MorphObjectHelper = NULL;
}

bool MorphObjectHelper::Load(bool missionSave)
{
	if (!missionSave)
	{
		TempMorphObjectBuffer = MorphObjectList;

		int size = 0;
		bool ret = Read(&size, 1);
		MorphObjectList.resize(size);
		if(size)
			ret = ret && Read(&MorphObjectList.front(), sizeof(MorphObjectClass)*size);
		return ret;
	}
	return true;
}

bool MorphObjectHelper::PostLoad(bool missionSave)
{
	if (!missionSave)
	{
		for (std::vector<MorphObjectClass>::iterator iter = MorphObjectList.begin(); iter != MorphObjectList.end(); ++iter)
		{
			MorphObjectClass &sao = *iter;
			ConvertHandles(&sao.MorphObject, 1);
			ConvertHandles(&sao.CurrentWho, 1);
		}

		// GBD: resync report — compare what we had against what we loaded.
		if (TempMorphObjectBuffer.size() == MorphObjectList.size())
		{
			for (int i = 0; i < int(MorphObjectList.size()); i++)
			{
				if (!(TempMorphObjectBuffer[i] == MorphObjectList[i]))
				{
					FormatLogMessage("MorphObjectList Index Mismatch: %d", i);
					break;
				}
			}
		}
		else
		{
			FormatLogMessage("MorphObjectList Size Mismatch! Old: %d New: %d", TempMorphObjectBuffer.size(), MorphObjectList.size());
		}
	}
	return true;
}

bool MorphObjectHelper::Save(bool missionSave)
{
	if (!missionSave)
	{
		int size = int(MorphObjectList.size());
		bool ret = Write(&size, 1);
		if(size)
			ret = ret && Write(&MorphObjectList.front(), sizeof(MorphObjectClass)*size);
		return ret;
	}
	return true;
}

// In BZ1Helper, if morph object.
void MorphObjectHelper::AddMorphObjectHostObject(const Handle h, const char* TempODF1, const char* TempODF2)
{
	if(!BZ1Helper::Get().RefStopAddMorphObject()) // RUDE HACK! (the ReplaceObject of a switching morph object re-adds it)
	{
		for (std::vector<MorphObjectClass>::iterator iter = MorphObjectList.begin(); iter != MorphObjectList.end(); ++iter)
		{
			if(iter->MorphObject == h)
				return;
		}

		MorphObjectList.resize(MorphObjectList.size()+1);
		MorphObjectClass &sao = MorphObjectList[MorphObjectList.size()-1]; // No temporary being created, *much* faster
		memset(&sao, 0, sizeof(MorphObjectClass)); // Zero things out at start.

		// Get the _config.odf. (fills baseODFName)
		const char *BaseODFName = GetConfigODF(h);

		if(DoesFileExist(BaseODFName))
			DispatchHelper::Get().ReadChanceValues(BaseODFName, "CloakChance", sao.CloakChance, 0.0f);

		GetODFBool(TempODF1, TempODF2, "CraftClass", "CanAICloak", &sao.IsCloaker, false);

		// VSR: the cloak energy budget.
		if (sao.IsCloaker)
		{
			GetODFLong(TempODF1, TempODF2, "GameObjectClass", "MaxCloakEnergy", &sao.CloakMaxEnergy, 0);
			sao.CloakCurEnergy = sao.CloakMaxEnergy;
			GetODFLong(TempODF1, TempODF2, "GameObjectClass", "CloakEnergyCost", &sao.CloakCostEnergy, 0);
			GetODFLong(TempODF1, TempODF2, "GameObjectClass", "AddCloakEnergy", &sao.CloakAddEnergy, 0);
		}

		// Save EngageRange.
		sao.EngageRange = GetEngageRange(h);

		// Preload the ODF here, just in case.
		char SwitchODF[MAX_ODF_LENGTH] = {0};
		GetODFString(TempODF1, TempODF2, "MorphObjectClass", "SwitchODF", MAX_ODF_LENGTH, SwitchODF);
		if((SwitchODF[0]) && (DoesODFExist(SwitchODF)))
			PreloadODF(SwitchODF);

		sao.MorphObject = h; // Save it.
		sao.MaxAmmo = GetMaxAmmo(h);
		sao.IdleTime = (BZ1Helper::m_TurnCounter + SecondsToTurns(30.0f));
		for (int i = 0; i < MAX_HARDPOINTS; i++)
			sao.MaxLocalAmmo[i] = GetMaxLocalAmmo(h, i);
	}
}

// Toggle activators for the replacement of the walker object.
void MorphObjectHelper::AddMorphObjectToggleObject(const Handle h)
{
	float BestDistanceSquared = FLT_MAX;
	for (std::vector<MorphObjectClass>::iterator iter = MorphObjectList.begin(); iter != MorphObjectList.end(); ++iter)
	{
		float DistanceSquared = GetDistance3DSquared(h, iter->MorphObject);
		if((DistanceSquared < BestDistanceSquared) && (h != iter->MorphObject))
		{
			BestDistanceSquared = DistanceSquared;
			if(BestDistanceSquared < Squared(5.0f)) // This is toggle distance.
			{
				if(iter->WeaponActive) // Toggle it off.
				{
					iter->WeaponActive = false;
					iter->ObjectSwitch = true; // Flag this to trigger swapping.
				}
				else if ((!iter->IsCloaker) || (!iter->BlockDeploy)) // VSR: a cloaker out of energy can't switch on.
				{
					iter->WeaponActive = true; // toggle it back on.
					iter->ObjectSwitch = true; // Flag this to trigger swapping.
				}
				else if (iter->MorphObject == GetPlayerHandle())
				{
					char CloakFailSound[MAX_ODF_LENGTH] = {0};
					GetODFString(iter->MorphObject, "GameObjectClass", "CloakFailSound", MAX_ODF_LENGTH, CloakFailSound);
					if (DoesFileExist(CloakFailSound))
						StartAudio2D(CloakFailSound, -1.0f, 0.0f, 11025.0f, false, false);
				}

				break;
			}
		}
	}
	BZ1Helper::Get().DeleteAfterDelay(h, 0.0f);
}

void MorphObjectHelper::Execute(BZ1Helper &bz1Helper)
{
	// pre-clean the vector
	MorphObjectList.erase(std::remove_if(MorphObjectList.begin(), MorphObjectList.end(), ShouldRemoveMorphObject), MorphObjectList.end());

	for (std::vector<MorphObjectClass>::iterator iter = MorphObjectList.begin(); iter != MorphObjectList.end(); ++iter)
	{
		const int Team = GetTeamNum(iter->MorphObject);
		const int PTeam = GetPerceivedTeam(iter->MorphObject);
		if (PTeam > 0)
			iter->PTeam = PTeam;
		const Handle Enemy = GetNearestEnemy(iter->MorphObject);

		if(iter->ObjectSwitch)
		{
			char SwitchODF[MAX_ODF_LENGTH] = {0}; // A place to store our desired variable.
			bool SwitchAllWeapons = false;

			GetODFString(iter->MorphObject, "MorphObjectClass", "SwitchODF", MAX_ODF_LENGTH, SwitchODF);
			GetODFBool(iter->MorphObject, "MorphObjectClass", "CanFireWhenSwitched", &iter->CanFire, true);
			GetODFBool(iter->MorphObject, "MorphObjectClass", "SwitchAllWeapons", &SwitchAllWeapons, true);

			// Upon activation, save these.
			if(iter->WeaponActive)
			{
				GetODFBool(iter->MorphObject, "MorphObjectClass", "CanFireWhenSwitched", &iter->CanFire, true);
				iter->NormalAmmo = GetCurAmmo(iter->MorphObject);
			}

			char NewWeapon[MAX_HARDPOINTS][MAX_ODF_LENGTH] = {0};
			for(int x = 0; x < MAX_HARDPOINTS; x++)
			{
				GetObjInfo(iter->MorphObject, ObjectInfoType(Get_Weapon0Config+x), NewWeapon[x]);

				bool SwapWeapon = false;
				char WeaponODF[MAX_ODF_LENGTH] = {0};
				GetObjInfo(iter->MorphObject, ObjectInfoType(Get_Weapon0ODF+x), WeaponODF);

				if(iter->WeaponActive) // Upon activation, save this.
				{
					iter->LocalAmmo[x] = GetCurLocalAmmo(iter->MorphObject, x);
					iter->MaxLocalAmmo[x] = GetMaxLocalAmmo(iter->MorphObject, x);
				}

				if(OpenODF2(WeaponODF))
				{
					char MineODF[MAX_ODF_LENGTH] = {0};
					if(GetODFString(WeaponODF, "DispenserClass", "objectClass", MAX_ODF_LENGTH, MineODF)) // Grab the value.
					{
						char TempBZCClass[MAX_ODF_LENGTH] = {0};
						CombineStrings(MineODF, MineODF, ".odf"); // Add .odf to the end.
						if((OpenODF2(MineODF)) && (GetODFString(MineODF, "GameObjectClass", "BZCClasslabel", MAX_ODF_LENGTH, TempBZCClass))) // Grab the value.
						{
							if(_stricmp(TempBZCClass,"MorphObjecttoggle") == 0)
								SwapWeapon = true;
						}
					}
				}
				if(!SwitchAllWeapons) // Only swap this one morph weapon.
				{
					if((SwapWeapon) && (GetODFString(WeaponODF, "WeaponClass", "altName", MAX_ODF_LENGTH, NewWeapon[x]))) // Grab the value.
						break;
				}
				else // Switch all weapons.
				{
					GetODFString(WeaponODF, "WeaponClass", "altName", MAX_ODF_LENGTH, NewWeapon[x]); // Grab the value.
				}
			}

			if(SwitchODF[0])
			{
				if(DoesODFExist(SwitchODF))
				{
					bz1Helper.RefStopAddMorphObject() = true; // RUDE HACK!
					if(GetCurrentCommand(iter->MorphObject) == CMD_HUNT)
					{
						if((iter->Command != GetCurrentCommand(iter->MorphObject)) && (iter->Command != CMD_HUNT))
							iter->MorphObject = bz1Helper.ReplaceObject(iter->MorphObject, SwitchODF, -1, 0.0f, -1, false, -1, -1, true, iter->Command, 0, iter->CurrentWho, iter->CurrentWhere);
						else
							iter->MorphObject = bz1Helper.ReplaceObject(iter->MorphObject, SwitchODF, -1, 0.0f, -1, false, -1, -1, false);
					}
					else
					{
						iter->MorphObject = bz1Helper.ReplaceObject(iter->MorphObject, SwitchODF, -1, 0.0f, -1, false);
					}
					bz1Helper.RefStopAddMorphObject() = false; // RUDE HACK!

					// Play a Sound here.
					char SoundFile[MAX_ODF_LENGTH] = {0};
					GetODFString(iter->MorphObject, "DeployableClass", iter->WeaponActive ? "soundDeploy" : "soundUndeploy", MAX_ODF_LENGTH, SoundFile);

					if(DoesFileExist(SoundFile))
						StartAudio3D(SoundFile, iter->MorphObject, AUDIO_CAT_ENGINE, false, true);
					else if(SoundFile[0])
						FormatLogMessage("ERROR: Morph Object SoundDeploy '%s' Doesn't Exist! FIX ODFs!", SoundFile);

					if(iter->IsCloaker)
						SetPerceivedTeam(iter->MorphObject, iter->WeaponActive ? 0 : iter->PTeam);

					if(!iter->CanFire)
						SetCurAmmo(iter->MorphObject, iter->WeaponActive ? 0 : iter->NormalAmmo);

					iter->ObjectSwitch = false;

					ReplaceWeapons(iter->MorphObject, NewWeapon, iter->LocalAmmo);
				}
				else
				{
					FormatLogMessage("ERROR: SwitchODF '%s' does not exist. Fix ODFs!", SwitchODF);
				}
			}
		}
		else // Object is switched, or waiting to be.
		{
			if(iter->WeaponActive)
			{
				const long CurAmmo = GetCurAmmo(iter->MorphObject);
				if(!iter->CanFire)
				{
					// While cloaked, prevent ammo pickup, but add it to the current ammo if its greater then the max of our stored values.
					if(CurAmmo > 0)
					{
						if(iter->NormalAmmo + CurAmmo <= iter->MaxAmmo)
							iter->NormalAmmo += CurAmmo;
						else
							iter->NormalAmmo = iter->MaxAmmo;

						SetCurAmmo(iter->MorphObject, 0);
					}
					// VSR: show the player his stored ammo.
					if (iter->MorphObject == GetPlayerHandle())
					{
						if (iter->MaxAmmo > 0)
						{
							BZ1Helper::AmmoGauge2 = float(iter->NormalAmmo) / float(iter->MaxAmmo);
							BZ1Helper::AmmoGaugeSet = true;
						}
					}
					// VSR: the same for local ammo.
					for (int i = 0; i < MAX_HARDPOINTS; i++)
					{
						iter->MaxLocalAmmo[i] = GetMaxLocalAmmo(iter->MorphObject, i);
						const float Sum = iter->LocalAmmo[i] + GetCurLocalAmmo(iter->MorphObject, i);
						iter->LocalAmmo[i] = (Sum < iter->MaxLocalAmmo[i]) ? Sum : iter->MaxLocalAmmo[i];
						SetCurLocalAmmo(iter->MorphObject, 0.0f, i);
					}
				}
				else // Remember our current ammo when we switch again.
				{
					if(iter->NormalAmmo != CurAmmo)
						iter->NormalAmmo = CurAmmo;
					for (int i = 0; i < MAX_HARDPOINTS; i++)
					{
						const float CurLocalAmmo = GetCurLocalAmmo(iter->MorphObject, i);
						if (iter->LocalAmmo[i] != CurLocalAmmo)
							iter->LocalAmmo[i] = CurLocalAmmo;
					}
				}
				// Keep us hidden, even if we hop out / back in.
				if(iter->IsCloaker)
					SetPerceivedTeam(iter->MorphObject, 0);
			}

			if (iter->IsCloaker)
			{
				// Watch for AI Cloaking / Decloaking.
				if((!IsPlayer(iter->MorphObject)) && (GetPlayerHandle(Team) == 0))
				{
					if(iter->WeaponActive)
					{
						// Watch for nearby enemies, and switch back if they're near.
						if(GetDistance3DSquared(iter->MorphObject, Enemy) < Squared(iter->EngageRange))
						{
							SetCommand(iter->MorphObject, CMD_HUNT, 0); // Decloak.
							iter->IdleTime = (BZ1Helper::m_TurnCounter + SecondsToTurns(15.0f)); // Wait 15 seconds before trying to cloak again.
						}
					}
					else
					{
						// Set Cloak Idle time, and Cloak if we want to.
						if(BZ1Helper::m_TurnCounter >= iter->IdleTime)
						{
							int CurrentCommand = GetCurrentCommand(iter->MorphObject);
							float Chance = GetRandomFloat(1.0f);
							// If there are no enemies in range.
							if((!Enemy) || (GetDistance3DSquared(iter->MorphObject, Enemy) > Squared(iter->EngageRange+50.0f)))
							{
								if(Chance < iter->CloakChance[CurrentCommand])
									SetCommand(iter->MorphObject, CMD_HUNT, 0);

								iter->IdleTime = (BZ1Helper::m_TurnCounter + SecondsToTurns(30.0f)); // Wait 30 seconds before trying to cloak again.
							} // Unit is not deployed and there are no enemies around.
						} // Cloak idle time is up.
					}
				}

				// VSR: the cloak energy budget — drains while cloaked, refills while not; running dry forces a decloak and blocks the toggle until full.
				if (iter->CloakMaxEnergy > 0)
				{
					if (!iter->WeaponActive)
					{
						if (iter->CloakCurEnergy < iter->CloakMaxEnergy)
						{
							const float Add = float(iter->CloakAddEnergy) / float(BZ1Helper::m_GameTPS) + iter->CloakCurEnergyRemainder;
							const long AddInt = long(Add);
							iter->CloakCurEnergyRemainder = Add - float(AddInt);
							iter->CloakCurEnergy += AddInt;
							if (iter->CloakCurEnergy < 0)
								iter->CloakCurEnergy = 0;
							else if (iter->CloakCurEnergy > iter->CloakMaxEnergy)
								iter->CloakCurEnergy = iter->CloakMaxEnergy;
						}
						if (!iter->BlockDeploy)
						{
							if (iter->CloakCurEnergy < iter->CloakMaxEnergy)
								iter->BlockDeploy = true;
						}
						else if (iter->CloakCurEnergy >= iter->CloakMaxEnergy)
							iter->BlockDeploy = false;
					}
					else
					{
						if (iter->CloakCurEnergy > 0)
						{
							const float Cost = float(iter->CloakCostEnergy) / float(BZ1Helper::m_GameTPS) + iter->CloakCurEnergyRemainder;
							const long CostInt = long(Cost);
							iter->CloakCurEnergyRemainder = Cost - float(CostInt);
							iter->CloakCurEnergy -= CostInt;
							if (iter->CloakCurEnergy < 0)
								iter->CloakCurEnergy = 0;
							else if (iter->CloakCurEnergy > iter->CloakMaxEnergy)
								iter->CloakCurEnergy = iter->CloakMaxEnergy;
						}
						if ((iter->BlockDeploy) || (iter->CloakCurEnergy == 0))
						{
							SetCommand(iter->MorphObject, CMD_HUNT, 0); // Out of energy: decloak.
							if (iter->MorphObject == GetPlayerHandle())
							{
								char CloakFailSound[MAX_ODF_LENGTH] = {0};
								GetODFString(iter->MorphObject, "GameObjectClass", "CloakFailSound", MAX_ODF_LENGTH, CloakFailSound);
								if (DoesFileExist(CloakFailSound))
									StartAudio2D(CloakFailSound, -1.0f, 0.0f, 11025.0f, false, false);
							}
						}
					}
					if (iter->MorphObject == GetPlayerHandle())
					{
						BZ1Helper::CloakGauge = float(iter->CloakCurEnergy) / float(iter->CloakMaxEnergy);
						BZ1Helper::CloakGaugeSet = true;
					}
				}
			}

			// Watch for Deactivation.
			if(GetCurrentCommand(iter->MorphObject) == CMD_HUNT)
			{
				char MineObject[MAX_ODF_LENGTH] = {0};
				GetSwitchMineODF(iter->MorphObject, MineObject);
				BuildObject(MineObject, Team, iter->MorphObject); // Toggle the switch.
			}
		}

		if(GetCurrentCommand(iter->MorphObject) != CMD_HUNT)
		{
			iter->Command = GetCurrentCommand(iter->MorphObject);
			iter->CurrentWho = GetCurrentWho(iter->MorphObject);
			// VSR: the commands that carry a position.
			if ((iter->Command == CMD_GO) || (iter->Command == CMD_DEPLOY) || (iter->Command == CMD_GET_IN) || (iter->Command == CMD_LAY_MINES))
				iter->CurrentWhere = GetCurrentCommandWhere(iter->MorphObject);
		}
	}
}

// Gets the first "morphobjecttoggle" weapon in a unit.
void MorphObjectHelper::GetSwitchMineODF(const Handle h, char *Value)
{
	static char MineObject[MAX_ODF_LENGTH] = {0};

	for(int x = 0; x < MAX_HARDPOINTS; x++)
	{
		char WeaponODF[MAX_ODF_LENGTH] = {0};
		GetObjInfo(h, ObjectInfoType(Get_Weapon0ODF+x), WeaponODF);
		if(OpenODF2(WeaponODF))
		{
			char MineODF[MAX_ODF_LENGTH] = {0};
			if(GetODFString(WeaponODF, "DispenserClass", "objectClass", MAX_ODF_LENGTH, MineObject)) // Grab the value.
			{
				char TempBZCClass[MAX_ODF_LENGTH] = {0};
				CombineStrings(MineODF, MineObject, ".odf"); // Add .odf to the end.
				if((OpenODF2(MineODF)) && (GetODFString(MineODF, "GameObjectClass", "BZCClasslabel", MAX_ODF_LENGTH, TempBZCClass))) // Grab the value.
				{
					if(_stricmp(TempBZCClass,"MorphObjectToggle") == 0)
						break;
				}
			}
		}
	}

	strcpy_s(Value, sizeof(MineObject), MineObject);
}

PrePickupPowerupReturnCodes MorphObjectHelper::PrePickupPowerup(const int curWorld, Handle me, Handle /*powerupHandle*/, const int ObjClassHash, const char* /*PowerupODF*/)
{
	if (curWorld != 0)
		return PREPICKUPPOWERUP_ALLOW;

	for (std::vector<MorphObjectClass>::iterator iter = MorphObjectList.begin(); iter != MorphObjectList.end(); ++iter)
	{
		if (iter->MorphObject != me)
			continue;

		if (!iter->WeaponActive)
			return PREPICKUPPOWERUP_ALLOW;
		if (iter->CanFire)
			return PREPICKUPPOWERUP_ALLOW;
		if (iter->NormalAmmo != iter->MaxAmmo)
			return PREPICKUPPOWERUP_ALLOW;

		// Stored ammo is full: refuse a reload pod. (sic: the service pod branch reads the health and allows regardless.)
		if (ObjClassHash == CLASS_POWERUP_RELOAD)
			return PREPICKUPPOWERUP_DENY;
		if (ObjClassHash == CLASS_POWERUP_SERVICE)
		{
			GetHealth(me);
			return PREPICKUPPOWERUP_ALLOW;
		}
		return PREPICKUPPOWERUP_ALLOW;
	}
	return PREPICKUPPOWERUP_ALLOW;
}
