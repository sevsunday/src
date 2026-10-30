// PROVENANCE: ancestor reference/ancestor-bz1helper-2015/Shared/BZ1Helper.cpp @6fda4f5 (Execute's master-handle loop, lines 1605-1680: the Hunt work-arounds + skill display) | decompile reference/decompiled/strategy02-ghidra12.2/src/missions/vsrcore/vehiclehelper.cpp.decomp.c (PostLoad 26-47, Save 50-59, Execute 68-310; Load inlined into BZ1Helper::Load) + dumpbin of 4fc24243 for the register-passed arguments | status: ported
#include "bz1helper.h"
#include "vehiclehelper.h"
#include "bzcscriptutils.h"
#include <algorithm>

std::vector<VehicleHelper::VehicleClass> TempVehicleBuffer; // GBD: the list as it stood before a Load, for PostLoad's resync report.

VehicleHelper::VehicleHelper()
{
}
VehicleHelper::~VehicleHelper()
{
}

bool VehicleHelper::Load(bool missionSave)
{
	if (!missionSave)
	{
		TempVehicleBuffer = VehicleList;

		int size = 0;
		bool ret = Read(&size, 1);
		VehicleList.resize(size);
		if(size)
			ret = ret && Read(&VehicleList.front(), sizeof(VehicleClass)*size);
		return ret;
	}
	return true;
}

bool VehicleHelper::PostLoad(bool missionSave)
{
	if (!missionSave)
	{
		for (std::vector<VehicleClass>::iterator iter = VehicleList.begin(); iter != VehicleList.end(); ++iter)
		{
			VehicleClass &sao = *iter;
			ConvertHandles(&sao.ObjectHandle, 1);
		}

		if (TempVehicleBuffer.size() == VehicleList.size())
		{
			for (int i = 0; i < int(VehicleList.size()); ++i)
			{
				if (!(TempVehicleBuffer[i] == VehicleList[i]))
				{
					FormatLogMessage("VehicleList Index Mismatch: %d", i);
					return true;
				}
			}
		}
		else
		{
			FormatLogMessage("VehicleList Size Mismatch! Old: %d New: %d", TempVehicleBuffer.size(), VehicleList.size());
		}
	}
	return true;
}

bool VehicleHelper::Save(bool missionSave)
{
	if (!missionSave)
	{
		int size = int(VehicleList.size());
		bool ret = Write(&size, 1);
		if(size)
			ret = ret && Write(&VehicleList.front(), sizeof(VehicleClass)*size);
		return ret;
	}
	return true;
}

void VehicleHelper::Execute(BZ1Helper &bz1Helper)
{
	// pre-clean the vector
	VehicleList.erase(std::remove_if(VehicleList.begin(), VehicleList.end(), ShouldRemoveVehicle), VehicleList.end());

	for (std::vector<VehicleClass>::iterator iter = VehicleList.begin(); iter != VehicleList.end(); ++iter)
	{
		const Handle h = iter->ObjectHandle;
		iter->CurTeamNum = GetTeamNum(h); // Update this, every tick.
		iter->Position = GetPosition(h);
		const AiCommand CurrentCommand = GetCurrentCommand(h);
		iter->PTeam = GetPerceivedTeam(h);

		// Create a couple of custom Command work arounds utilizing the Hunt command.
		if (CurrentCommand == CMD_HUNT)
		{
			const Handle PlayerH = GetPlayerHandle(iter->CurTeamNum);
			BZ1Helper::TeamInfo &teamInfo = bz1Helper.RefTeamInfo(iter->CurTeamNum);

			// GBD: Hunt on a remote-controllable unit hands it to the team's player: they hop in, their old craft becomes an AI pilot (or is removed when they were on foot).
			if (iter->AllowRemoteControl && PlayerH && !teamInfo.TookControlThisTurn)
			{
				if (PlayerH == teamInfo.SatellitePlayer || PlayerH == h)
				{
					SetCommand(h, CMD_NONE, 0);
				}
				else
				{
					SetAsUser(h, iter->CurTeamNum);
					SetPilotClass(h, GetPilotConfig(PlayerH));
					teamInfo.TookControlThisTurn = true;
					if (IsPerson(PlayerH))
					{
						RemoveObject(PlayerH);
					}
					else
					{
						AddPilotByHandle(PlayerH);
						SetBestGroup(PlayerH);
					}
				}
			}
			else if (PlayerH != h)
			{
				if (iter->HuntIsResupply) // GBD: "go top up whichever is lower".
				{
					if (GetAmmo(h) < GetHealth(h))
						SetCommand(h, CMD_GET_RELOAD, 0);
					else
						SetCommand(h, CMD_GET_REPAIR, 0);
				}
				else
				{
					switch (iter->ObjClassHash)
					{
					case CLASS_RECYCLERVEHICLE:
					case CLASS_RECYCLERVEHICLEH:
					case CLASS_DEPLOYBUILDING:
					case CLASS_DEPLOYBUILDINGH:
					case CLASS_TRACKEDDEPLOYABLE:
						{
							SetCommand(h, CMD_DEPLOY, 0); // A "Deploy Now" command, to remotely tell a recycler to deploy without using the aim reticle.
						}
						break;
					case CLASS_CONSTRUCTIONRIG:
					case CLASS_CONSTRUCTIONRIGT:
						{
							SetCommand(h, CMD_STOP, 0); // Yay! A "Hold" command.
						}
						break;
					case CLASS_TUG:
						{
							Handle TempH = bz1Helper.GetNearestObject(h, 100.0f, -1, 0, false, 1, true, false, 3, "CLASS_ARTIFACT"); // IgnoreInvincible / ObeyIdleVictim are LTCG placeholders at this call site (folded defaults). // We want Artifacts. Time to us a fancy feature I made :)
							if (TempH)
							{
								SetCommand(h, CMD_PICKUP, 0, TempH); //Pickup(iter->ObjectHandle, TempH, 0);
							}
							else
							{
								SetCommand(h, CMD_NO_DEPLOY, 0);
								PlayVOMsg(h, "user2Msg", iter->CurTeamNum); // Play user2Msg, if possible.
							}
						}
						break;
					}
				}
			}
		}

		// Custom Skill Function. Only tick the refresh timer when the TeamFilter is set to show it for this unit.
		// (The 2015 code renamed the unit here; the shipped binary only keeps the timer — the engine shows skill itself now.)
		if (bz1Helper.GetUseSkillLevels())
		{
			if (iter->ShowSkill && iter->ShowSkillTimer <= 0)
			{
				if (TeamFilterCheck(iter->ShowSkillTeamFilter, GetLocalPlayerTeamNumber(), iter->CurTeamNum))
					iter->ShowSkillTimer = BZ1Helper::m_GameTPS;
			}
			iter->ShowSkillTimer--;
		}

		// GBD: cloak energy. Deployed = cloaked, drains CloakCostEnergy a second; undeployed regains CloakAddEnergy a second. The remainder carries the fraction between ticks.
		if (iter->CloakMaxEnergy > 0)
		{
			const bool Deployed = IsDeployed(h);
			const Handle LocalPlayerH = GetPlayerHandle();
			long CurEnergy = iter->CloakCurEnergy;

			if (Deployed)
			{
				if (CurEnergy > 0)
				{
					const float Drain = float(iter->CloakCostEnergy) / float(BZ1Helper::m_GameTPS) + iter->CloakCurEnergyRemainder;
					const int Whole = int(Drain);
					CurEnergy -= Whole;
					iter->CloakCurEnergyRemainder = Drain - float(Whole);
					if (CurEnergy < 0)
						CurEnergy = 0;
					else if (CurEnergy > iter->CloakMaxEnergy)
						CurEnergy = iter->CloakMaxEnergy;
					iter->CloakCurEnergy = CurEnergy;
				}

				if (iter->BlockDeploy || CurEnergy == 0)
				{
					if (IsPlayer(h))
						Deploy(h);
					else
						SetCommand(h, CMD_MORPH_SETUNDEPLOYED, 0);

					if (h == LocalPlayerH)
					{
						char CloakFailSound[MAX_ODF_LENGTH];
						memset(CloakFailSound, 0, sizeof(CloakFailSound));
						GetODFString(h, "GameObjectClass", "CloakFailSound", MAX_ODF_LENGTH, CloakFailSound);
						if (CloakFailSound[0] && DoesFileExist(CloakFailSound))
							StartAudio2D(CloakFailSound, -1.0f, 0.0f, 11025.0f, false, false);
					}
				}
			}
			else
			{
				if (CurEnergy < iter->CloakMaxEnergy)
				{
					const float Gain = float(iter->CloakAddEnergy) / float(BZ1Helper::m_GameTPS) + iter->CloakCurEnergyRemainder;
					const int Whole = int(Gain);
					CurEnergy += Whole;
					iter->CloakCurEnergyRemainder = Gain - float(Whole);
					if (CurEnergy < 0)
						CurEnergy = 0;
					else if (CurEnergy > iter->CloakMaxEnergy)
						CurEnergy = iter->CloakMaxEnergy;
					iter->CloakCurEnergy = CurEnergy;
				}

				if (!iter->BlockDeploy && CurEnergy < iter->CloakMaxEnergy)
					iter->BlockDeploy = true;
				else if (CurEnergy >= iter->CloakMaxEnergy)
					iter->BlockDeploy = false;
			}

			if (h == LocalPlayerH)
			{
				BZ1Helper::CloakGauge = float(iter->CloakCurEnergy) / float(iter->CloakMaxEnergy);
				BZ1Helper::CloakGaugeSet = true;
			}
		}

		iter->LastCommand = CurrentCommand;
	}
}
