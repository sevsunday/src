// PROVENANCE: ancestor none (decompile-only) | decompile reference/decompiled/strategy02-ghidra12.2/src/missions/vsrcore/poweruphelper.cpp.decomp.c (PostLoad 42-73, AddPowerupObject 91-140, Execute 143-192; Load / Save inlined into BZ1Helper) + dumpbin of 4fc25766 / 4fc2596c for the register-passed arguments and the log-message operands | status: ported
#include "bz1helper.h"
#include "poweruphelper.h"
#include "bzcscriptutils.h"
#include "mathutils.h"
#include <algorithm>

std::vector<PowerupHelper::PowerupClass> TempPowerupBuffer; // GBD: the list as it stood before a Load, for PostLoad's resync report.

PowerupHelper *PowerupHelper::m_PowerupHelper;

PowerupHelper::PowerupHelper()
{
	m_PowerupHelper = this;
}

PowerupHelper::~PowerupHelper()
{
	m_PowerupHelper = NULL;
}

bool PowerupHelper::Load(bool missionSave)
{
	if(!missionSave)
	{
		TempPowerupBuffer = PowerupList;

		int size = 0;
		bool ret = Read(&size, 1);
		PowerupList.resize(size);
		if(size)
			ret = ret && Read(&PowerupList.front(), sizeof(PowerupClass)*size);
		return ret;
	}
	return true;
}

bool PowerupHelper::PostLoad(bool missionSave)
{
	if (!missionSave)
	{
		for (std::vector<PowerupClass>::iterator iter = PowerupList.begin(); iter != PowerupList.end(); ++iter)
		{
			PowerupClass &sao = *iter;
			ConvertHandles(&sao.PowerupObject, 1);

			// GBD: a powerup that was flying to a point keeps flying there after a resync.
			if (sao.CurrCommand == CMD_GO)
			{
				SetCommand(sao.PowerupObject, CMD_GO, 0, 0, sao.CurrWhere, 0);
				SetVelocity(sao.PowerupObject, sao.Velocity);
			}
		}

		if (TempPowerupBuffer.size() == PowerupList.size())
		{
			for (int i = 0; i < int(PowerupList.size()); ++i)
			{
				if (!(TempPowerupBuffer[i] == PowerupList[i]))
				{
					FormatLogMessage("PowerupList Index Mismatch: %d", i);
					return true;
				}
			}
		}
		else
		{
			FormatLogMessage("PowerupList Size Mismatch! Old: %d New: %d", TempPowerupBuffer.size(), PowerupList.size());
		}
	}
	return true;
}

bool PowerupHelper::Save(bool missionSave)
{
	if (!missionSave)
	{
		int size = int(PowerupList.size());
		bool ret = Write(&size, 1);
		if(size)
			ret = ret && Write(&PowerupList.front(), sizeof(PowerupClass)*size);
		return ret;
	}
	return true;
}

void PowerupHelper::AddPowerupObject(const Handle h, const char *TempODF1, const char *TempODF2, const int /*UnusedArg*/, const long ObjClassHash)
{
	for (std::vector<PowerupClass>::iterator iter = PowerupList.begin(); iter != PowerupList.end(); ++iter)
	{
		if(iter->PowerupObject == h)
			return;
	}

	PowerupList.resize(PowerupList.size()+1);
	PowerupClass &sao = PowerupList[PowerupList.size()-1]; // No temporary being created, *much* faster
	memset(&sao, 0, sizeof(PowerupClass)); // Zero things out at start.

	sao.PowerupObject = h;
	sao.ObjClassHash = ObjClassHash;

	// GBD: the stock classes keep their values under their own class, a service powerup under ServicePowerupClass.
	if ((ObjClassHash == CLASS_POWERUP_REPAIR) || (ObjClassHash == CLASS_POWERUP_SERVICE))
	{
		if (!GetODFLong(TempODF1, TempODF2, "HealthPowerupClass", "healthUp", &sao.HealthUp, 0))
			GetODFLong(TempODF1, TempODF2, "ServicePowerupClass", "serviceUp", &sao.HealthUp, 0);
	}
	if ((ObjClassHash == CLASS_POWERUP_RELOAD) || (ObjClassHash == CLASS_POWERUP_SERVICE))
	{
		if (!GetODFLong(TempODF1, TempODF2, "AmmoPowerupClass", "healthUp", &sao.AmmoUp, 0)) // sic: the ammo powerup's value is read from healthUp.
			GetODFLong(TempODF1, TempODF2, "ServicePowerupClass", "serviceUp", &sao.AmmoUp, 0);
		if (!GetODFLong(TempODF1, TempODF2, "AmmoPowerupClass", "localAmmoUp", &sao.LocalAmmoUp, 0))
			GetODFLong(TempODF1, TempODF2, "ServicePowerupClass", "localAmmoUp", &sao.LocalAmmoUp, 0);
	}
	if (ObjClassHash == CLASS_WEAPON)
		GetODFString(TempODF1, TempODF2, "WeaponPowerupClass", "weaponName", MAX_ODF_LENGTH, sao.WeaponUp, NULL);

	GetODFString(TempODF1, TempODF2, "PowerUpClass", "soundPickup", MAX_ODF_LENGTH, sao.SoundPickup, NULL);
	GetODFString(TempODF1, TempODF2, "PowerUpClass", "soundReject", MAX_ODF_LENGTH, sao.SoundReject, NULL);
	GetODFInt(TempODF1, TempODF2, "PowerUpClass", "HitMask", &sao.HitMask, -1);
	sao.DelayTime = SecondsToTurns(1.0f);
}

void PowerupHelper::Execute(BZ1Helper & /*bz1Helper*/)
{
	const bool Logging = BZ1Helper::Logging;

	// pre-clean the vector
	PowerupList.erase(std::remove_if(PowerupList.begin(), PowerupList.end(), ShouldRemovePowerup), PowerupList.end());

	for (std::vector<PowerupClass>::iterator iter = PowerupList.begin(); iter != PowerupList.end(); ++iter)
	{
		const Handle h = iter->PowerupObject;
		iter->Position = GetPosition(h);
		iter->CurrCommand = GetCurrentCommand(h);
		if ((iter->CurrCommand == CMD_GO) || (iter->CurrCommand == CMD_DEPLOY) || (iter->CurrCommand == CMD_GET_IN) || (iter->CurrCommand == CMD_LAY_MINES))
			iter->CurrWhere = GetCurrentCommandWhere(h);
		iter->Velocity = GetVelocity(h);

		// GBD: one second after it appeared, kick it with a random velocity offset in its own frame (MinVelocityOffset .. MaxVelocityOffset).
		if (iter->DelayTime > 0)
		{
			if (iter->DelayTime == SecondsToTurns(1.0f))
			{
				Vector MaxVelocityOffset(0.0f, 0.0f, 0.0f);
				if (GetODFVector(h, "PowerUpClass", "MaxVelocityOffset", &MaxVelocityOffset, Vector(0.0f, 0.0f, 0.0f)) && !IsNullVector(MaxVelocityOffset))
				{
					Vector MinVelocityOffset(0.0f, 0.0f, 0.0f);
					GetODFVector(h, "PowerUpClass", "MinVelocityOffset", &MinVelocityOffset, Vector(0.0f, 0.0f, 0.0f));

					const Matrix Pos = GetMatrixPosition(h);
					const Vector Velocity = GetVelocity(h);
					const float x = GetRandomFloat(MinVelocityOffset.x, MaxVelocityOffset.x);
					const float y = GetRandomFloat(MinVelocityOffset.y, MaxVelocityOffset.y);
					const float z = GetRandomFloat(MinVelocityOffset.z, MaxVelocityOffset.z);
					const Vector NewVelocity = (Pos.right * x) + Velocity + (Pos.up * y) + (Pos.front * z);
					SetVelocity(h, NewVelocity);
					if (Logging)
						FormatLogMessage("Powerup Vel: %f %f %f, OffSet: %f %f %f, NewVel: %f %f %f", Velocity.x, Velocity.y, Velocity.z, x, y, z, NewVelocity.x, NewVelocity.y, NewVelocity.z);
				}
			}
			iter->DelayTime--;
		}
	}
}
