// PROVENANCE: ancestor reference/ancestor-bz1helper-2015/Shared/AIWeaponHelper.cpp @6fda4f5 | decompile reference/decompiled/strategy02-ghidra12.2/src/missions/vsrcore/aiweaponhelper.cpp.decomp.c (AIGiveWeapons 10-201) | status: ported
#include "bz1helper.h"
#include "aiweaponhelper.h"
#include "bzcscriptutils.h"

AIWeaponHelper::AIWeaponHelper()
{
}

// GBD vs 2015: the per-weapon requireName walk became BZ1Helper::CheckBuildRequirements (scrap, power, pilots, requires) with a
// per-slot SkipRequirements override; the AI now pays the weapon's scrapCost once; HardpointOverride gives the weapon to the
// hardpoint by index and stops; the console / log lines are new.
void AIWeaponHelper::AIGiveWeapons(const Handle h, const int Team, const int NumWeapons, const bool /*Max*/)
{
	int Weapons = NumWeapons;
	if (Weapons == -1)
		Weapons = GetNumWeapons(h);
	if (!Weapons)
		return;

	bool Logging = BZ1Helper::Logging;
	const char *BaseODFName = GetConfigODF(h);

	if (Logging)
		FormatConsoleMessage("AIWeaponHelper: ODF: '%s', Team: %d, Config ODF: '%s'", GetODFName(h), Team, BaseODFName);

	if((BaseODFName) && (OpenODF2(BaseODFName)))
	{
		int NumberOfWeapons[MAX_HARDPOINTS] = {0};
		char WeaponODFList[MAX_HARDPOINTS][16][MAX_ODF_LENGTH] = {0}; // Weapon [WEAPON SLOT][NUMBER OF ENTRIES]
		int MinWeaponMask = 0;
		bool WeaponMaskSet = false;
		bool SkipRequirements[MAX_HARDPOINTS] = {0};
		bool HardpointOverride[MAX_HARDPOINTS] = {0};
		int PossibleWeaponMasks[16] = {0};
		int NumWeaponMasks = {0};
		int Difficulty = BZ1Helper::Get().RefTeamInfo(Team).m_CPUAIDifficulty;

		if (Logging)
			FormatConsoleMessage("AIWeaponHelper: Opened ODF: '%s', Difficulty: %d", BaseODFName, Difficulty);

		for(int i = 4; i >= 0; i--) // Start at weaponSlot 5 and go up. 
		{
			char DesiredValue[MAX_ODF_LENGTH] = {0};
			if(Difficulty == 1)
				sprintf_s(DesiredValue, "EasyWeaponSlot%d", i+1);
			else if(Difficulty == 2)
				sprintf_s(DesiredValue, "MediumWeaponSlot%d", i+1);
			else if(Difficulty == 3)
				sprintf_s(DesiredValue, "HardWeaponSlot%d", i+1);
			else if(Difficulty == 4)
				sprintf_s(DesiredValue, "ExtremeWeaponSlot%d", i+1);

			if (Logging)
				FormatConsoleMessage("AIWeaponHelper: HardPoint %d Choosing Slot: '%s'", i+1, DesiredValue);

			for(int x = 0;x<16;x++)
			{
				char DesiredValue2[MAX_ODF_LENGTH] = {0};
				sprintf_s(DesiredValue2, "WeaponName%d", x+1);
				if(GetODFString(BaseODFName, DesiredValue, DesiredValue2, MAX_ODF_LENGTH, WeaponODFList[i][NumberOfWeapons[i]])) // Grab the value.
					++NumberOfWeapons[i];
				sprintf_s(DesiredValue2, "WeaponMask%d", x+1);
				if(GetODFInt(BaseODFName, DesiredValue, DesiredValue2, &PossibleWeaponMasks[NumWeaponMasks])) // Grab the value.
					++NumWeaponMasks;
			}
			if(!WeaponMaskSet)
				if(GetODFInt(BaseODFName, DesiredValue, "MinWeaponMask", &MinWeaponMask, 1))
					WeaponMaskSet = true;

			GetODFBool(BaseODFName, DesiredValue, "SkipRequirements", &SkipRequirements[i], false);
			GetODFBool(BaseODFName, DesiredValue, "HardpointOverride", &HardpointOverride[i], false);

			int RandomWeapon = -1; // Assume 0 for now, if it doesn't get set, it won't get used. 

			if(NumberOfWeapons[i])
			{
				// Now that we have the weapons, Randomly select one to give to the ships.
				// Check Requirements first, if not, pick another random one. Only try 16 times.
				for(int Tries = 0; Tries<16; Tries++)
				{
					int TempRandomWeapon = GetRandomInt(NumberOfWeapons[i]-1);

					if(Logging)
						FormatLogMessage("AIWeaponHelper: Number Of Weapons for HardPoint %d is: %d, Choice: %d WeaponName: '%s'", i, NumberOfWeapons[i], TempRandomWeapon, WeaponODFList[i][TempRandomWeapon]); 

					if((BZ1Helper::Get().CheckBuildRequirements(WeaponODFList[i][TempRandomWeapon], Team)) || (SkipRequirements[i]))
					{
						RandomWeapon = TempRandomWeapon;
						break;
					}
				} // End loop over 16 attempts to find a valid weapon.
			} // if NumberOfWeapons > 0.

			// Only try to give it if it passed the require check.
			if(RandomWeapon >= 0)
			{
				char TempWeaponODF[MAX_ODF_LENGTH] = {0}; // Store the actual weapon name.
				int ScrapCost = 0;

				if(WeaponODFList[i][RandomWeapon][0])
				{
					if(DoesODFExist(WeaponODFList[i][RandomWeapon]))
					{
						// Copy ODF name to find real ODF name. 
						char TempAPFileName[MAX_ODF_LENGTH] = {0};
						CombineStrings(TempAPFileName, WeaponODFList[i][RandomWeapon], ".odf");
						if(OpenODF2(TempAPFileName))
						{
							GetODFString(TempAPFileName, NULL, "WeaponPowerupClass", "weaponName", MAX_ODF_LENGTH, TempWeaponODF); // Grab the value.
							GetODFInt(TempAPFileName, NULL, "GameObjectClass", "scrapCost", &ScrapCost, 0);
						}
					}
					else
					{
						FormatLogMessage("ERROR: '%s' Weapon '%s' does not exist. Fix ODFs!", BaseODFName, WeaponODFList[i][RandomWeapon]); 
					}
				}

				for(int x = 0; x<=i;x++)
				{
					if(TempWeaponODF[0])
					{
						if(DoesODFExist(TempWeaponODF))
						{
							if((x == 0) && (!SkipRequirements[i]))
								AddScrap(Team, -ScrapCost); // The AI pays for it, once.

							if(HardpointOverride[i])
							{
								GiveWeapon(h, x, TempWeaponODF);
								break;
							}
							GiveWeapon(h, TempWeaponODF);
						}
						else // Only print this if the string is not empty.
							FormatLogMessage("ERROR: '%s' Weapon '%s' does not exist. Fix ODFs!", WeaponODFList[i][RandomWeapon], TempWeaponODF); 
					}
				}
			}
		}

		int WeaponMaskSetting = 1;
		if(NumWeaponMasks > 0)
		{
			int TempWeaponMask = GetRandomInt(NumWeaponMasks-1);
			WeaponMaskSetting = PossibleWeaponMasks[TempWeaponMask];
		}
		else
		{
			float WeaponMaskSelection = GetRandomFloat(5.0f);
			if(WeaponMaskSelection <= 1.0)
				WeaponMaskSetting = 31;
			else if(WeaponMaskSelection <= 2.0)
				WeaponMaskSetting = 15;
			else if(WeaponMaskSelection <= 3.0)
				WeaponMaskSetting = 7;
			else if(WeaponMaskSelection <= 4.0)
				WeaponMaskSetting = 3;
			else
				WeaponMaskSetting = 1;
		}

		if(WeaponMaskSetting < MinWeaponMask)
			WeaponMaskSetting = MinWeaponMask;

		SetWeaponMask(h, WeaponMaskSetting);
	}
}
