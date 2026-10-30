-- VSR Strategy code.
-- Based on 1.3 DLL Source code, extensively modified by General BlackDragon

--- @class ThugScavengerClass
--- @field ThugScavengerObject Handle
--- @field ScavengerTeam integer

    local ThugScavengerList = {};
    --- @param ThugScavengerClass entry
    --- @return boolean
    function ShouldRemoveThugScavengerObject(entry) { 
        local Get_GOClass, ObjClass = GetObjInfo(entry.ThugScavengerObject); -- this part probably isn't right but you can fix it easily
        return not IsAround(entry.ThugScavengerObject) or ObjClass == "CLASS_EXTRACTOR" or ObjClass == "CLASS_SILO"; }

--- @class ThugPilotClass
--- @field ThugPilotObject Handle
--- @field SwitchTickTimer integer

	local ThugPilotList = {};
	--- @param ThugPilotClass entry
	--- @return boolean
	function ShouldRemoveThugPilotObject(entry) {
		return not IsAround(entry.ThugPilotObject) or entry.SwitchTickTimer < 0 or IsPlayer(entry.ThugPilotObject); }
		
--- @class EmptyShipClass
--- @field EmptyShipObject Handle
--- @field InvulnerabilityTime integer
--- @field SavedHealth integer

	local EmptyShipList = {};
	--- @param EmptyShipClass entry
	--- @return boolean
	function ShouldRemoveEmptyShipObject(entry) {
		return not IsAround(entry.EmptyShipObject) or (GetMaxHealth(entry.EmptyShipObject) > 0); } --entry.InvulnerabilityTime == 0 or IsPlayer(entry.EmptyShipObject); }

	-- Stored Variables for Saved Player's Stuff. This is not *actually* tracked by team, just happens to be the same size. Tracked via TeamGroup and SavedName.
	local PlayerShipODF = { "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" };
	local SavedPilotODF = { "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" };
	local PlayerSavedName = { "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" }
	local PlayerShipWeapons = { "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" };
	local PlayerPilotWeapons = { "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" };
	local PlayerPilotLocalAmmo = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }; -- Saved local Ammo per player.
	local PlayerMatrix = { Matrix(), Matrix(), Matrix(), Matrix(), Matrix(), Matrix(), Matrix(), Matrix(), Matrix(), Matrix(), Matrix(), Matrix(), Matrix(), Matrix(), Matrix(), Matrix() };
	local PlayerVelocity = { Vector(), Vector(), Vector(), Vector(), Vector(), Vector(), Vector(), Vector(), Vector(), Vector(), Vector(), Vector(), Vector(), Vector(), Vector(), Vector() };
	local PlayerOmega = { Vector(), Vector(), Vector(), Vector(), Vector(), Vector(), Vector(), Vector(), Vector(), Vector(), Vector(), Vector(), Vector(), Vector(), Vector(), Vector() };
	local MapAmbientSound = "";

	local EmptyShipODF = { "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" }

	local m_GameTPS = 0; -- How many turns per second there are (10, 15, 20, 30, or 60)

	local Mission = {
		-- Ints
		m_TotalGameTime = 0,
		m_RemainingGameTime = 0,
		m_ElapsedGameTime = 0,
		m_KillLimit = 0, -- As specified from the shell
		m_PointsForAIKill = 0, -- ivar14
		m_KillForAIKill = 0, -- ivar15
		m_RespawnWithSniper = 0, -- ivar16 -- 0 = Start w/ sniper, No respawn, 1 = Start w/ sniper, Respawn w/ sniper, 2 = No sniper on start or respawn.
		m_TurretAISkill = 0, -- ivar17
		m_NonTurretAISkill = 0, -- ivar18
		m_StartingVehiclesMask = 0, -- ivar7
		m_SpawnedAtTime = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		--m_Alliances= 0, -- - Now used to tell if Alliances are in use or not, moved to a bool. -GBD -- ivar23 must be > 0 for allies to pass units to eachother.
		m_AllyTeams = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, -- New alliance var setting. Yaynot  -GBD
		m_RecyInvulnerabilityTime = 0, -- ivar25, if >0, this is currently active
		-- FFA With Thugs Code.
		m_NumSpawnPoints = 0, -- Number of Spawn Points. -GBD
		NumCommanders = 0, 
		NextAutoAssignTeam = 0,
		CommanderTeam = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		ThugCounter = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		-- MPI stuff.
		-- AI Race selection vars for AI #2, and #3. -GBD
		m_AIRace = { 0, 0, 0, 0, 0 }, -- Upped to support up to 5 AI for FFA. -GBD
		m_HumanForce = 0, 
		m_CPUForce = 0, 
		m_CPUTurretAISkill = 0, -- ivar21
		m_CPUNonTurretAISkill = 0, -- ivar22
		m_LastTauntPrintedAt = 0, 
		m_PlayersSpawned = 0, -- Number of playerz.
		--ST:Capture mode
		m_NumCaptureGoals = 0, -- ST:Capture, Number of goals. -GBD
		m_CaptureGoalTime = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, -- Timer per goal. -GBD
		m_CaptureGoalTeam = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, -- It's saved team. -GBD
		m_GoalBeingCaptured = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, -- Flagme.
		m_CaptureTime = 0, -- Flag for how long.
		m_GameType = 0, -- 0 = Normal, 4 = ST:Capture. 
		--Pilot Invulnerability code
		m_PilotInvunerability = 0, -- Setting for how long.
		m_PilotInvTime = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, -- Timer per player for invulnerability.
		m_SavedPilotInvHealth = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, -- Saved Health values.
		-- Player Restore Code.
		m_SavedPlayerHealth = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, -- Saved values for m_RestorePlayers.
		m_SavedPlayerAmmo = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 
		m_SavedPlayerTeamGroup = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 
		m_SavedPlayerScrap = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 
		m_RestorePlayers= 0, -- Flag for if we restore player ships/weapons on a disconnect/rejoin. 0 = Off, 1 = By Name, 2 = By Slot.
		-- Empty Invuln Code.
		BuildEmpty = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, -- Saved local for which vehicle slot is built empty in recycler.
		-- Special stuff for FFA MPI Team switching recyclers on Team 7-10.
	--	m_NextDropoffTeam, -- 0 = do nothing, else set the next dropoff spawned to this team.
	--	m_SetScrapNextTurn = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, -- 0 = do nothing, else reset initial scrap for this team next execute, stores what maxScrap is to set it to.
		-- Camera Pod stuff.
	--	m_CameraPodDeployTimer = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, -- Timer for deploying, must wait a tick.

		-- Bools
		m_DidInit = false,
		StopScript = false,
		m_HadMultipleFunctioningTeams = false,
		m_TeamIsSetUp = { false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false },
		m_NotedRecyclerLocation = { false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false }, -- of deployed recycler
		--m_Alliances = false, -- - Now used to tell if Alliances are in use or not. -GBD -- ivar23 must be > 0 for allies to pass units to eachother.
		m_HasAllies = { false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false }, -- Flag if they have any allies, so we know to } the game or not. -GBD
		m_GameOver = false,
		-- Flag that we're creating the staring vehicles, so AI skill levels
		-- need to be dropped a notch.
		m_CreatingStartingVehicles = false,
		m_RespawnAtLowAltitude = false,
		m_bIsFriendlyFireOn = false,
		-- FFA with Thugs Code.
		m_ThugFlag = { false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false }, -- Flag for if this player is a commander. -GBD
		m_TeamHasCommander = { false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false }, -- Flag for if we've chosen a commander. -GBD
		m_SetThugPilotFlag = false, --Flag to enable/disable the new Thug pilot pregetin call. -GBD
		-- MPI stuff.
		CheckedSVar3 = false,
		m_IsMPI = false,
		m_SetFirstAIP = false, 
		m_MissionStart = false,
		SpawnAI = false,
		-- ST:Capture stuff
		m_CaptureGoalObjectify = { false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false }, -- Timer flag. -GBD
		m_CaptureGoalIsSwitching = { {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {} }, -- blah.
		m_DualCapture = { false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false }, -- stuff.
		m_TeamIsCapturing = { false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false }, -- flag this for timer.
		-- Player Restore code.
		m_GiveWeaponsBack = { false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false }, -- Flag if the dll should give pilot weapons back on next hopout.
		m_SavedPlayerDeployed = { false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false }, 
		IsCameraPod = { false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false }, -- Was this person a Camera Pods?
		-- Stuff for Spawn Angle.
		m_SpawnFacingCenter = false,

		-- Vector
		m_TeamPos = { Vector(), Vector(), Vector(), Vector(), Vector(), Vector(), Vector(), Vector(), Vector(), Vector(), Vector(), Vector(), Vector(), Vector(), Vector(), Vector() }, -- Where they started out, used in respawning

		-- Floats
		m_FRIENDLY_SPAWNPOINT_MAX_ALLY = 0.0,
		m_FRIENDLY_SPAWNPOINT_MIN_ENEMY = 0.0,
		m_RANDOM_SPAWNPOINT_MIN_ENEMY = 0.0,
		-- Player Restore Code.
		m_SavedPlayerLocalAmmo = { {0.0, 0.0, 0.0, 0.0, 0.0}, {0.0, 0.0, 0.0, 0.0, 0.0}, {0.0, 0.0, 0.0, 0.0, 0.0}, {0.0, 0.0, 0.0, 0.0, 0.0}, {0.0, 0.0, 0.0, 0.0, 0.0}, {0.0, 0.0, 0.0, 0.0, 0.0}, {0.0, 0.0, 0.0, 0.0, 0.0}, {0.0, 0.0, 0.0, 0.0, 0.0}, {0.0, 0.0, 0.0, 0.0, 0.0}, {0.0, 0.0, 0.0, 0.0, 0.0}, {0.0, 0.0, 0.0, 0.0, 0.0}, {0.0, 0.0, 0.0, 0.0, 0.0}, {0.0, 0.0, 0.0, 0.0, 0.0}, {0.0, 0.0, 0.0, 0.0, 0.0}, {0.0, 0.0, 0.0, 0.0, 0.0}, {0.0, 0.0, 0.0, 0.0, 0.0} }, -- Saved local Ammo per player.

		-- Handles
		m_RecyclerHandles = { nil, nil, nil, nil, nil, nil, nil, nil, nil, nil, nil, nil, nil, nil, nil, nil },
		--ST:Capture mode
		m_CaptureGoals = { nil, nil, nil, nil, nil, nil, nil, nil, nil, nil, nil, nil, nil, nil, nil, nil}, -- Max Capture goals. -GBD
		UserTarget = { nil, nil, nil, nil, nil, nil, nil, nil, nil, nil, nil, nil, nil, nil, nil, nil }, -- Targeted thing.
		-- Pilot Invulnerability Code.
		m_PilotInvUser = { nil, nil, nil, nil, nil, nil, nil, nil, nil, nil, nil, nil, nil, nil, nil, nil }, -- Pilot Handle, to double check.

	}




local VEHICLE_SPACING_DISTANCE = 20.0;

-- ---------- Scoring Values-- these are delta scores, added to current score --------
local ScoreDecrementForSpawnKill = 500;
local ScoreForWinning = 100;

local MAX_AI_TEAMS = 5;

-- How long a "spawn" kill lasts, in tenth of second ticks. If the
-- time since they were spawned to current is less than this, it's a
-- spawn kill, and not counted. Todo - Make this an ivar for dm?
local MaxSpawnKillTime = 15;

-- -----------------------------------------------

-- Max distance (in x,z dimensions) on a pilot respawn. Actual value
-- used will vary with random numbers, and will be +/- this value
local RespawnDistanceAwayXZRange = 32.;
-- Max distance (in y dimensions) on a pilot respawn. Actual value
-- used will vary with random numbers, and will be [0..this value)
local RespawnDistanceAwayYRange = 8.;

-- How high up to respawn a pilot
local RespawnPilotHeight = 200.0;

-- How far allies will be from the commander's position
local AllyMinRadiusAway = 30.0;
local AllyMaxRadiusAway = 60.0;

-- How long (in seconds) from noticing gameover, to the actual kicking
-- out back to the shell.
local endDelta = 10.0;

-- Tuning distances for GetSpawnpointForTeam()

-- Friendly spawnpoint: Max distance away for ally
local FRIENDLY_SPAWNPOINT_MAX_ALLY = 100.0;
-- Friendly spawnpoint: Min distance away for enemy
local FRIENDLY_SPAWNPOINT_MIN_ENEMY = 400.0;

-- Random spawnpoint: min distance away for enemy
local RANDOM_SPAWNPOINT_MIN_ENEMY = 450.0;

-- Temporary strings for blasting stuff into for output. NOT to be
-- used to store anything you care about.
local TempMsgString;

-- Temporary name for blasting ODF names into while building
-- them. *not* saved, do *not* count on its contents being valid
-- next time the dll is called.
local TempODFName;

-- AIP Custom name string for MPI. -GBD
local CustomAIPNameBase;

-- Special Handle for Audio. -GBD
local EasterEggSound = 0;


function Save(missionSave)

	local ret = true;

	-- Make sure we always call this
	StartingVehicleManager.Save(missionSave);

	if (missionSave) then
		return true;
	end

	local size = int(ThugScavengerList.size());
	Write(&size, 1);
	if (size)
		Write(&ThugScavengerList.front(), sizeof(ThugScavengerClass)*size);

	size = int(ThugPilotList.size());
	Write(&size, 1);
	if (size)
		Write(&ThugPilotList.front(), sizeof(ThugPilotClass)*size);

	size = int(EmptyShipList.size());
	Write(&size, 1);
	if (size)
		Write(&EmptyShipList.front(), sizeof(EmptyShipClass)*size);

	-- bools
	if (b_array ~= NULL)
		Write(b_array, b_count);

	-- floats
	if (f_array ~= NULL)
		Write(f_array, f_count);

	-- Handles
	if (h_array ~= NULL)
		Write(h_array, h_count);

	-- ints
	if (i_array ~= NULL)
		Write(i_array, i_count);

	ret = ret and Write(&(PlayerShipODF[0]), sizeof(PlayerShipODF));
	ret = ret and Write(&(SavedPilotODF[0]), sizeof(SavedPilotODF));
	ret = ret and Write(&(PlayerSavedName[0]), sizeof(PlayerSavedName));
	ret = ret and Write(&(PlayerShipWeapons[0][0]), sizeof(PlayerShipWeapons));
	ret = ret and Write(&(PlayerPilotWeapons[0][0]), sizeof(PlayerPilotWeapons));
	ret = ret and Write(&(PlayerPilotLocalAmmo), sizeof(PlayerPilotLocalAmmo));
	ret = ret and Write(&(PlayerMatrix), sizeof(PlayerMatrix));
	ret = ret and Write(&(PlayerVelocity), sizeof(PlayerVelocity));
	ret = ret and Write(&(PlayerOmega), sizeof(PlayerOmega));
	ret = ret and Write(&(MapAmbientSound[0]), sizeof(MapAmbientSound));

	ret = ret and Write(&(EmptyShipODF[0]), sizeof(EmptyShipODF));

	return ret;
end

function Load(missionSave)

	local ret = true;

	m_GameTPS = EnableHighTPS();
	SetAutoGroupUnits(false);

	-- Make sure we always call this
	StartingVehicleManager.Load(missionSave);

	-- We're a 1.3 DLL.
	WantBotKillMessages();

	if (missionSave)
	then
		local i;

		-- init bools
		if ((b_array) and (b_count))
			for (i = 0; i < b_count; i++)
				b_array[i] = false;

		-- init floats
		if ((f_array) and (f_count))
			for (i = 0; i < f_count; i++)
				f_array[i] = 0.0;

		-- init handles
		if ((h_array) and (h_count))
			for (i = 0; i < h_count; i++)
				h_array[i] = 0;

		-- init ints
		if ((i_array) and (i_count))
			for (i = 0; i < i_count; i++)
				i_array[i] = 0;

		return true;
	end

	local size;
	Read(&size, 1);
	ThugScavengerList.resize(size);
	if (size)
		Read(&ThugScavengerList.front(), sizeof(ThugScavengerClass)*size);

	Read(&size, 1);
	ThugPilotList.resize(size);
	if (size)
		Read(&ThugPilotList.front(), sizeof(ThugPilotClass)*size);

	Read(&size, 1);
	EmptyShipList.resize(size);
	if (size)
		Read(&EmptyShipList.front(), sizeof(EmptyShipClass)*size);

	-- bools
	if (b_array ~= NULL)
		Read(b_array, b_count);

	-- floats
	if (f_array ~= NULL)
		Read(f_array, f_count);

	-- Handles
	if (h_array ~= NULL)
		Read(h_array, h_count);

	-- ints
	if (i_array ~= NULL)
		Read(i_array, i_count);

	ret = ret and Read(&(PlayerShipODF[0]), sizeof(PlayerShipODF));
	ret = ret and Read(&(SavedPilotODF[0]), sizeof(SavedPilotODF));
	ret = ret and Read(&(PlayerSavedName[0]), sizeof(PlayerSavedName));
	ret = ret and Read(&(PlayerShipWeapons[0][0]), sizeof(PlayerShipWeapons));
	ret = ret and Read(&(PlayerPilotWeapons[0][0]), sizeof(PlayerPilotWeapons));
	ret = ret and Read(&(PlayerPilotLocalAmmo), sizeof(PlayerPilotLocalAmmo));
	ret = ret and Read(&(PlayerMatrix), sizeof(PlayerMatrix));
	ret = ret and Read(&(PlayerVelocity), sizeof(PlayerVelocity));
	ret = ret and Read(&(PlayerOmega), sizeof(PlayerOmega));
	ret = ret and Read(&(MapAmbientSound[0]), sizeof(MapAmbientSound));

	ret = ret and Read(&(EmptyShipODF[0]), sizeof(EmptyShipODF));

	-- Start playing the musics.
	if ((Mission.m_DidInit) and (DoesFileExist(MapAmbientSound)))
	then
		StopAudio(EasterEggSound);
		EasterEggSound = StartAudio2D(MapAmbientSound, -1, 0.0, 44100.0f, true, false);
	end

	-- Do this for everyone as well.
	UpdateObjectives();

	return ret;
end

function GetNextRandomVehicleODF(Team)

	return GetPlayerODF(Team);
end

function UpdateObjectives()

	ClearObjectives();
	if (Mission.m_GameType == 4) then -- Capture mode.
		AddObjective("mpobjective_stcap.otf", WHITE, -1);
	else
		AddObjective("mpobjective_st.otf", WHITE, -1);
	end
end

function AddObject(h)

	local ODFName = GetObjInfo(h, Get_CFG);

	-- Cutoff :# at the end.
	if (not DoesODFExist(ODFName))
	then
		ODFName = ODFName:match("^([^:]+)") -- Remove everything from the : on.
	end

	-- Changed NM 10/19/01 - all AI is at skill 3 now by default.
	-- Changed NM 4/13/02 - except when starting things up. Then we drop a notch.

	local UseTurretSkill = Mission.m_TurretAISkill;
	local UseNonTurretSkill = Mission.m_NonTurretAISkill;

	-- Note: this is the proper way to determine if a handle points to a
	-- turret. NM 1/29/05
	local ObjClass = GetObjInfo(h, Get_GOClass);
	local isTurret = (ObjClass == "CLASS_TURRETTANK");

	-- Start of game, remove scrap flag.
	if (Mission.m_ElapsedGameTime == 0)
	then
		local RemoveScrap = GetVarItemInt("network.session.ivar117");

		if ((RemoveScrap) and (ObjClass == "CLASS_SCRAP"))
		then
			RemoveObject(h);
			return; -- done here.
		end
	end

	local Team = GetTeamNum(h);

	-- If this is MPI, and not a human team. -GBD
	if ((Mission.m_IsMPI) and (Team > 10))
	then
		AddToDispatch(h, 15.0, false, 0, false); -- Tie into DispatchHelper. -GBD

		UseTurretSkill = Mission.m_CPUTurretAISkill;
		UseNonTurretSkill = Mission.m_CPUNonTurretAISkill;

		--[[ -- Buggery Stuff. Not needed if CPU Recy has StayWithOwner = true like it should.
		-- Special code to prevent the Recyclers on team 7-10 from switching to Team 6. Caused by [DeployBuildingClass]::StayWithOwner = false? Thug Team's recy's stay put.
		if((IsTeamplayOn()) and (Team == 6))
		then
			for(local i = 7; i < 11; i++)
			then
				if(Team ~= i) -- This team does not match what we're looking for.
				then
					if(h == Mission.m_RecyclerHandles[i])
					then
						SetTeamNum(h, i);
						Team = i;
						Mission.m_NextDropoffTeam = i;

						-- Get ScrapHold value.
						local TempODF[MAX_ODF_LENGTH] = then0end;
						local TempODF2[MAX_ODF_LENGTH] = then0end;
						GetObjInfo(h, Get_ODF, TempODF);

						if (OpenODF2(TempODF))
						then
							-- Grab out the next ODF, if present.
							GetODFString(TempODF, "GameObjectClass", "classlabel", MAX_ODF_LENGTH, TempODF2); -- Grab the sound file, with allowance for a large filename.
							CombineStrings2(TempODF2, TempODF2, ".odf"); -- Add .odf to the end.

							while ((_stricmp(TempODF, TempODF2) ~= 0) and (not GetODFInt(TempODF, "RecyclerClass", "scrapHold", &Mission.m_SetScrapNextTurn[i])) and (OpenODF2(TempODF2))) -- Go all the way until you can't go any further.
							then
								strcpy_s(TempODF, TempODF2); -- Copy TempODF2 into TempODF, then re-grab TempODF2 to try again.
								GetODFString(TempODF, "GameObjectClass", "classlabel", MAX_ODF_LENGTH, TempODF2); -- Grab the sound file, with allowance for a large filename.
								CombineStrings2(TempODF2, TempODF2, ".odf"); -- Add .odf to the end.
							end
						end

					--	if((OpenODF2(TempODF)) and (GetODFString(TempODF, "GameObjectClass", "classlabel", MAX_ODF_LENGTH, TempODF2))) -- Grab the sound file, with allowance for a large filename.
					--	then
					--		CombineStrings2(TempODF2, TempODF2, ".odf"); -- Add .odf to the end.
					--		OpenODF2(TempODF2);
					--	end
					--	if((GetODFInt(TempODF, "RecyclerClass", "scrapHold", &Mission.m_SetScrapNextTurn[i])) or
					--		(GetODFInt(TempODF2, "RecyclerClass", "scrapHold", &Mission.m_SetScrapNextTurn[i])))
					--	then
					--		-- Got it.
					--	end

						break;
					end
					elseif((Mission.m_NextDropoffTeam > 0) and (_stricmp(ObjClass, "CLASS_NAVBEACON") == 0))
					then
						SetTeamNum(h, Mission.m_NextDropoffTeam);
						Mission.m_NextDropoffTeam = 0;
						break;
					end
				end
			end
		end
		--]]
	else -- NOT MPI
		-- Remove NAV cameras outside map bounds.
		if (ObjClass == "CLASS_NAVBEACON")
		then
			local Pos = GetPosition(h);
			if ((Pos.x > GetMapInfo().MaxWidth) or
				(Pos.x < GetMapInfo().MinWidth) or
				(Pos.z > GetMapInfo().MaxDepth) or
				(Pos.z < GetMapInfo().MinDepth))
			then
				RemoveObject(h);
			end
		end
	end

	-- See if this is a turret, 
	if (isTurret)
	then
		SetSkill(h, UseTurretSkill);
		--	return; -- We do more here now, lets continue just in case. -GBD
	else
		-- Not a turret. Use regular skill level
		SetSkill(h, UseNonTurretSkill);
	end

	-- Count all spawnpoints on the map, use to determine what to do with "Extra" players in FFA. -GBD
	if ((Mission.m_ElapsedGameTime < 1) and (ObjClass == "CLASS_SPAWNBUOY")) then
		Mission.m_NumSpawnPoints = Mission.m_NumSpawnPoints + 1;
	end

	-- Also see if this is a new recycler vehicle (e.g. user upgraded
	-- recycler building to vehicle)
	local IsRecyVehicle = ((ObjClass == "CLASS_RECYCLERVEHICLE") or (ObjClass == "CLASS_RECYCLERVEHICLEH") or (ObjClass == "CLASS_RECYCLER"));
	if (IsRecyVehicle)
	then
		-- If we're not tracking a recycler vehicle for this team right
		-- now, store it.
		if ((Mission.m_RecyclerHandles[Team] == 0) or (not IsAround(Mission.m_RecyclerHandles[Team]))) then -- Allow recycler undeploying. -GBD
			Mission.m_RecyclerHandles[Team] = h;
		end

		-- Now crack her open, check the Empty Vehicle ODF for empty invulnerability.
		if ((not Mission.BuildEmpty[Team]) and (ObjClass == "CLASS_RECYCLER"))
		then
			Mission.BuildEmpty[Team] = GetODFInt(h, "FactoryClass", "BuildEmptyItem");
			if (Mission.BuildEmpty[Team] > 0)
			then
				local DesiredValue = "BuildItem" .. tostring(Mission.BuildEmpty[Team])
				EmptyShipODF[Team] = GetODFString(h, "FactoryClass", DesiredValue);
			end
		end
	end

	local AddToList = true;
	-- Special things for FFA Mode with Thugs. -GBD
	if ((not IsTeamplayOn()) or (Mission.m_IsMPI))
	then
		-- Scavenger code: added to handle thug scavs in FFA Alliance mode. -GBD
		if (((ObjClass == "CLASS_SCAVENGER") or (ObjClass == "CLASS_SCAVENGERH")) and not ThugScavengerClass[h] 
		then
			ThugScavengerClass[h] = { ThugScavengerClass = h, ScavengerTeam = Team };
		-- Thug code, adding thugs to be thugified. (Thug pilots to switch to Commander's team after 15 seconds)
		elseif ((ObjClass == "CLASS_PERSON") and (not IsPlayer(h)) and not ThugPilotClass[h]) -- Pilots built by RespawnPilot aren't SetAsUser yet. This only catches player hopouts / bailouts. -GBD
		then
			ThugPilotClass[h] = { ThugPilotClass = h, SwitchTickTimer = (15 * m_GameTPS) };
		end
	end

	-- VSR Empty Ship Invulnerability code. -GBD
	if (Mission.m_PilotInvunerability > 0)
	then
		if ((IsAround(Mission.m_RecyclerHandles[Team])) and (Mission.BuildEmpty[Team] > 0))
		then
			--if((not IsAliveAndPilot2(h)) and (not IsPlayer(h)) and (not IsRecyVehicle)) -- This must be an empty. -- Crap, empty ships built don't trigger any of the 3 alive functions as false.
			if (ODFName == EmptyShipODF[Team] and not EmptyShipClass[h])
			then
				EmptyShipClass[h] = { EmptyShipClass = h, InvulnerabilityTime = Mission.m_PilotInvunerability, SavedHealth = GetMaxHealth(h) };
				SetMaxHealth(h, 0);
			end
		end
	end
end

function DeleteObject(h)

	local Team = GetTeamNum(h);
	if ((Mission.m_RestorePlayers) and (IsPlayer(h)) and (not GetPlayerHandle(Team)))
		SetNoScrapFlagByHandle(h);

	--[[ not not  Temp buggery. -GBD
	-- Special Scav stuff for MPI:
	if((Mission.m_IsMPI) and (IsTeamplayOn()))
	then
		for (std::vector<ThugScavengerClass>::iterator iter = ThugScavengerList.begin(); iter ~= ThugScavengerList.end(); ++iter)
		then
			-- This is before our clean up, make sure it's still around first.
			if(h == iter->ThugScavengerObject)
			then
				--local Team = GetTeamNum(iter->ThugScavengerObject);

				if((Team == 6) and (iter->ScavengerTeam > 6) and (iter->ScavengerTeam < 11)) -- This is an AI Team on "TeamPlay" Team 2.
				then
					local ObjClass[MAX_ODF_LENGTH] = then0end;
					GetObjInfo(iter->ThugScavengerObject, Get_GOClass, ObjClass);

					-- This deployed, it automatically switched to Team 6. Swap it back.
					if((Team ~= iter->ScavengerTeam) and (_stricmp(ObjClass, "CLASS_EXTRACTOR") == 0) or (_stricmp(ObjClass, "CLASS_SILO") == 0))
					then
						-- Get ScrapHold value.
						local TempHold = 0;
						local TempODF[MAX_ODF_LENGTH] = then0end;
						local TempODF2[MAX_ODF_LENGTH] = then0end;
						GetObjInfo(iter->ThugScavengerObject, Get_ODF, TempODF);

						if (OpenODF2(TempODF))
						then
							-- Grab out the next ODF, if present.
							GetODFString(TempODF, "GameObjectClass", "classlabel", MAX_ODF_LENGTH, TempODF2); -- Grab the sound file, with allowance for a large filename.
							CombineStrings2(TempODF2, TempODF2, ".odf"); -- Add .odf to the end.

							while ((_stricmp(TempODF, TempODF2) ~= 0) and
								(not GetODFInt(TempODF, "ExtractorClass", "scrapHold", &TempHold)) and
								(not GetODFInt(TempODF, "SiloClass", "scrapHold", &TempHold)) and
								(OpenODF2(TempODF2))) -- Go all the way until you can't go any further.
							then
								strcpy_s(TempODF, TempODF2); -- Copy TempODF2 into TempODF, then re-grab TempODF2 to try again.
								GetODFString(TempODF, "GameObjectClass", "classlabel", MAX_ODF_LENGTH, TempODF2); -- Grab the sound file, with allowance for a large filename.
								CombineStrings2(TempODF2, TempODF2, ".odf"); -- Add .odf to the end.
							end
						end

						local TempMaxTeam = GetMaxScrap(Team);
						local TempMaxScav = GetMaxScrap(iter->ScavengerTeam);

						SetTeamNum(iter->ThugScavengerObject, iter->ScavengerTeam); -- Set it to the correct Team.
						-- Correct scraphold.
						AddMaxScrap(iter->ScavengerTeam, -TempHold);
						AddMaxScrap(Team, TempHold);

						-- Lets log how much scrap to see if we need to mess with that manually.
						sprintf_s(TempMsgString, "DESTROYED SCAV Team: %d to Team: %d. OldMax: %d, %d NewMax: %d, %d, Curr: %d, %d", Team, iter->ScavengerTeam, TempMaxTeam, TempMaxScav, GetMaxScrap(Team), GetMaxScrap(iter->ScavengerTeam), GetScrap(Team), GetScrap(iter->ScavengerTeam));
						PrintConsoleMessage(TempMsgString);

					end
				end
				break; -- We found it.
			end
		end
	end
	--]]
end

function SetCPUAIPlan(Team, NameOverride)

	if (not Mission.CheckedSVar3)
	then
		Mission.CheckedSVar3 = true;
		local pContents = GetCheckedNetworkSvar(3, NETLIST_AIPs);
		if (not pContents or #pContents == 0)
		then
			-- Use the default 1.3 naming scheme if not specified.
			CustomAIPNameBase = "VSR_";
		else
			CustomAIPNameBase = pContents;
		end
	end

	local Random = GetRandomInt(2); --0, 1, 2
	if (Random > 2) then
		Random = 2;
	end
	local AIPFile = string.format("%s%c%d_%d.aip", CustomAIPNameBase, GetRace(Mission.m_RecyclerHandles[Team]), NameOverride, Random); ---6

	if (not DoesFileExist(AIPFile)) then
		AIPFile = string.format("%s%c%d_0.aip", CustomAIPNameBase, GetRace(Mission.m_RecyclerHandles[Team]), NameOverride); ---6
	end
	SetAIPFile(AIPFile, Team);

	if (Mission.m_SetFirstAIP) then
		DoTaunt(TAUNTS_Random);
	end
	Mission.m_SetFirstAIP = true;
end

-- Gets the initial player vehicle as selected in the shell
function GetInitialPlayerVehicleODF(Team)
	return GetPlayerODF(Team);
end

-- Given a race identifier, get the pilot back (used during a respawn)
function GetInitialPlayerPilotODF(Race, Team, IsRespawning)

	if (Team > 0)
	then
		if (IsTeamplayOn())
			Team = GetMission.CommanderTeam(Team);

		local TempODF[MAX_ODF_LENGTH] = {};
		local TempODF2[MAX_ODF_LENGTH] = {};
		GetObjInfo(Mission.m_RecyclerHandles[Team], Get_ODF, TempODF);

		if ((OpenODF2(TempODF)) and (GetODFString(TempODF, "GameObjectClass", "classlabel", MAX_ODF_LENGTH, &TempODF2[0]))) -- Grab the classlabel.
		then
			CombineStrings(TempODF2, TempODF2, ".odf"); -- Add .odf to the end.
			OpenODF2(TempODF2);
		end

		-- 0 = Start w/ sniper, No respawn, 
		-- 1 = Start w/ sniper, Respawn w/ sniper, 
		-- 2 = Start No sniper, No respawn.
		if (((not IsRespawning) and (Mission.m_RespawnWithSniper < 2)) or
			((IsRespawning) and (Mission.m_RespawnWithSniper == 1)))
		then
			TempODFName = GetODFString(TempODF, TempODF2, "GameObjectClass", "PilotRespawnWithSniper");
		else
			TempODFName = GetODFString(TempODF, TempODF2, "GameObjectClass", "PilotRespawnWithOutSniper");
		end
	end

	if ((not DoesODFExist(TempODFName)) or (Team == 0))
	then
		if (((not IsRespawning) and (Mission.m_RespawnWithSniper < 2)) or
			((IsRespawning) and (Mission.m_RespawnWithSniper == 1)))
			strcpy_s(TempODFName, "ispilo"); -- With sniper.
		else
			strcpy_s(TempODFName, "isuser_m"); -- Note-- this is the sniper-less variant for a respawn

		TempODFName[0] = Race;
		if (not DoesODFExist(TempODFName))
		then
			sprintf_s(TempMsgString, "ERROR: '%s' does not exist. Giving you pilot DEFAULT ISDFnot  FIX ITnot ", TempODFName);
			PrintConsoleMessage(TempMsgString);

			TempODFName[0] = 'i';
		end
	end
	return TempODFName;
end

-- Given a race identifier, get the recycler ODF back
function GetInitialRecyclerODF(Race)

--const local *Contents = GetVarItemStr("network.session.svar5");
	local pContents = GetCheckedNetworkSvar(5, NETLIST_Recyclers);

	if ((pContents ~= nil) and (#pContents ~= 0))
	then
		TempODFName = pContents;
	else
		TempODFName = "ivrecy_m";
	end
	TempODFName[0] = Race;
	return TempODFName;
end

-- Given a race identifier, get the scavenger ODF back
function GetInitialScavengerODF(Race)

	TempODFName = "ivscav";
	TempODFName[0] = Race;
	return TempODFName;
end

-- Given a race identifier, get the constructor ODF back
function GetInitialConstructorODF(Race)

	TempODFName = "ivcons";
	TempODFName[0] = Race;
	return TempODFName;
end

-- Given a race identifier, get the healer (service truck) ODF back
function GetInitialHealerODF(Race)

	TempODFName = "ivserv";
	TempODFName[0] = Race;
	return TempODFName;
end

-- Helper function for SetupTeam(), returns an appropriate spawnpoint.
local Strategy02::GetSpawnpointForTeam(local Team)
then
	local spawnpointPosition = Vector(0, 0, 0);

	-- Pick a random, ideally safe spawnpoint.
	SpawnpointInfo* pSpawnPointInfo;
	size_t i, count = GetAllSpawnpoints(pSpawnPointInfo, Team);

	-- Designer didn't seem to put any spawnpoints on the map :(
	if (count == 0)
	then
		return spawnpointPosition;
	end

	-- First pass: see if a spawnpolocal exists with this team #
	--
	-- Note: using a temporary array allocated on stack to keep track
	-- of indices.
	size_t* pIndices = reinterpret_cast<size_t*>(_alloca(count * sizeof(size_t)));
	memset(pIndices, 0, count * sizeof(size_t));
	size_t indexCount = 0;
	for (i = 0; i < count; ++i)
	then
		if (pSpawnPointInfo[i].m_Team == Team)
		then
			pIndices[indexCount++] = i;
		end
	end

	-- Did we find any spawnpoints in the above search? If so,
	-- randomize out of that list and return that
	if (indexCount > 0)
	then
		size_t index = 0;
		-- Might be unnecessary, but make sure we return a valid index
		-- in [0,indexCount)
		do
		then
			index = static_cast<size_t>(GetRandomFloat(static_cast<float>(indexCount)));
		end while (index >= indexCount);
		return pSpawnPointInfo[pIndices[index]].m_Position;
	end

	-- re-write to use Mission.m_AllyTeams[Team] values. -GBD

	-- Fix for FFA spawning. -BLYD/GBD
	if (not IsTeamplayOn())
	then
		SpawnpointInfo* pAllySpawnPointInfo;
		GetAllSpawnpoints(pAllySpawnPointInfo, Mission.m_AllyTeams[Team]);

		-- pass 1.5: build up a list of spawnpoints that have 
		-- no one close, randomly pick one of those.
		indexCount = 0;
		for (i = 0; i < count; ++i)
		then
			if ((pAllySpawnPointInfo[i].m_DistanceToClosestSameTeam >= Mission.m_FRIENDLY_SPAWNPOINT_MIN_ENEMY) and
				(pSpawnPointInfo[i].m_DistanceToClosestAlly >= Mission.m_FRIENDLY_SPAWNPOINT_MIN_ENEMY) and
				(pSpawnPointInfo[i].m_DistanceToClosestEnemy >= Mission.m_FRIENDLY_SPAWNPOINT_MIN_ENEMY))
			then
				pIndices[indexCount++] = i;
			end
		end

		-- Did we find any spawnpoints in the above search? If so,
		-- randomize out of that list and return that
		if (indexCount > 0)
		then
			size_t index = 0;
			-- Might be unnecessary, but make sure we return a valid index
			-- in [0,indexCount)
			do
			then
				index = static_cast<size_t>(GetRandomFloat(static_cast<float>(indexCount)));
			end while (index >= indexCount);
			return pSpawnPointInfo[pIndices[index]].m_Position;
		end
	end

	-- Second pass: build up a list of spawnpoints that appear to have
	-- allies close, randomly pick one of those.
	indexCount = 0;
	for (i = 0; i < count; ++i)
	then
		if (((pSpawnPointInfo[i].m_DistanceToClosestSameTeam < Mission.m_FRIENDLY_SPAWNPOINT_MAX_ALLY) or
			(pSpawnPointInfo[i].m_DistanceToClosestAlly < Mission.m_FRIENDLY_SPAWNPOINT_MAX_ALLY)) and
			(pSpawnPointInfo[i].m_DistanceToClosestEnemy >= Mission.m_FRIENDLY_SPAWNPOINT_MIN_ENEMY))
		then
			pIndices[indexCount++] = i;
		end
	end

	-- Did we find any spawnpoints in the above search? If so,
	-- randomize out of that list and return that
	if (indexCount > 0)
	then
		size_t index = 0;
		-- Might be unnecessary, but make sure we return a valid index
		-- in [0,indexCount)
		do
		then
			index = static_cast<size_t>(GetRandomFloat(static_cast<float>(indexCount)));
		end while (index >= indexCount);
		return pSpawnPointInfo[pIndices[index]].m_Position;
	end

	-- Third pass: Make up a list of spawnpoints that appear to have
	-- no enemies close.
	indexCount = 0;
	for (i = 0; i < count; ++i)
	then
		if (pSpawnPointInfo[i].m_DistanceToClosestEnemy >= Mission.m_RANDOM_SPAWNPOINT_MIN_ENEMY)
		then
			pIndices[indexCount++] = i;
		end
	end

	-- Did we find any spawnpoints in the above search? If so,
	-- randomize out of that list and return that
	if (indexCount > 0)
	then
		size_t index = 0;
		-- Might be unnecessary, but make sure we return a valid index
		-- in [0,indexCount)
		do
		then
			index = static_cast<size_t>(GetRandomFloat(static_cast<float>(indexCount)));
		end while (index >= indexCount);
		return pSpawnPointInfo[pIndices[index]].m_Position;
	end

	-- If here, all spawnpoints have an enemy within
	-- RANDOM_SPAWNPOINT_MIN_ENEMY.  Fallback to old code.
	return GetRandomSpawnpoint(Team);
end

-- Sees if this is a m_HumanRecycler vehicle ODF, and returns the race
-- ('a'..'z') if true. Returns 0 if not a m_HumanRecycler.
static local IsRecyclerODF(Handle h)
then
	if (h == 0)
		return 0;

	local ObjClass[MAX_ODF_LENGTH];
	GetObjInfo(h, Get_GOClass, ObjClass);

	if ((_stricmp(ObjClass, "CLASS_RECYCLERVEHICLE") == 0) or (_stricmp(ObjClass, "CLASS_RECYCLER") == 0) or (_stricmp(ObjClass, "CLASS_RECYCLERVEHICLEH") == 0))
	then
		local ODFName[MAX_ODF_LENGTH];
		GetObjInfo(h, Get_CFG, ODFName);
		return ODFName[0];
	end

	-- fallback: not a m_HumanRecycler.
	return 0;
end

-- Builds a starting vehicle on the specified team with either ODF1
-- (preferred, if found) or ODF2 as its name, modified by the
-- race. Sets group, if specified. Returns the handle
Handle Strategy02::BuildStartingVehicle(local aTeam, local aRace, local *ODF1, local *ODF2, local *Where, local aGrp)
then
	local TempODF[MAX_ODF_LENGTH];

	strcpy_s(TempODF, ODF1);
	TempODF[0] = (char)aRace;
	if (not DoesODFExist(TempODF))
	then
		-- fallback to ODF2
		strcpy_s(TempODF, ODF2);
		TempODF[0] = (char)aRace;
	end

	Handle h = BuildObject(TempODF, aTeam, Where);
	if ((h ~= 0) and (aGrp >= 0))
		SetGroup(h, aGrp);
	return h;
end

-- Add local version of buildStartingVehicle -GBD
Handle Strategy02::BuildStartingVehicle(local aTeam, local aRace, local *ODF1, local *ODF2, local Where, local aGrp)
then
	local TempODF[MAX_ODF_LENGTH];

	strcpy_s(TempODF, ODF1);
	TempODF[0] = (char)aRace;
	if (not DoesODFExist(TempODF))
	then
		-- fallback to ODF2
		strcpy_s(TempODF, ODF2);
		TempODF[0] = (char)aRace;
	end

	Handle h = BuildObject(TempODF, aTeam, Where);
	if ((h ~= 0) and (aGrp >= 0))
		SetGroup(h, aGrp);
	return h;
end


-- Sets up the side's commander's extra vehicles, such a recycler or
-- more.  Does *not* create the player vehicle for them, 
-- however. [That's to be done in SetupPlayer.]  Safe to be called
-- multiple times for each player on that team
--
-- If Teamplay is off, this function is called once per player.
--
-- If Teamplay is on, this function is called only on the
-- _defensive_ team number for an alliance. 
void Strategy02::SetupTeam(local Team)
then
#ifndef EDITOR
	if ((Team < 1) or (Team >= MAX_TEAMS))
		return;
	if (Mission.m_TeamIsSetUp[Team])
		return;

	if ((Team == 1) and (Mission.m_IsMPI))
		DoTaunt(TAUNTS_GameStart);

	local TeamRaceH = GetRaceOfTeam(Team);
	if (IsTeamplayOn())
		SetMPTeamRace(WhichTeamGroup(Team), TeamRaceH); -- Lock this down to prevent changes.

	local spawnpointPosition(0, 0, 0);

	if (not Mission.m_IsMPI)
	then
		-- First pass: see if a spawnpolocal exists with this team #
		spawnpointPosition = GetSpawnpointForTeam(Team);
	else -- We Are MPInot  
		local PathName[MAX_ODF_LENGTH];
		memset(PathName, 0, sizeof(PathName));
		sprintf_s(PathName, "Player_%d", Mission.m_PlayersSpawned + 1);
		size_t bufSize = 0;
		--float* pData = NULL;
		GetPathPoints(PathName, bufSize, NULL); --pData
		--pData = new float[2 * bufSize]; 
		local *pData = static_cast<local *>(_alloca(sizeof(float) * 2 * bufSize));
		if (GetPathPoints(PathName, bufSize, pData))
			spawnpointPosition = Vector(pData[0], TerrainFindFloor(pData[0], pData[1]), pData[1]);
		--delete[] pData;
		++Mission.m_PlayersSpawned;

		-- If this is a null vector, use old method.
		if (((spawnpointPosition.x * spawnpointPosition.x) + (spawnpointPosition.y * spawnpointPosition.y) + (spawnpointPosition.z * spawnpointPosition.z)) < 0.1f)
		then
			spawnpointPosition = GetSpawnpointForTeam(Team);
		end
	end

	-- Store position we created them at for later
	Mission.m_TeamPos[3 * Team + 0] = spawnpointPosition.x;
	Mission.m_TeamPos[3 * Team + 1] = spawnpointPosition.y;
	Mission.m_TeamPos[3 * Team + 2] = spawnpointPosition.z;

	-- Build recycler some distance away, if it's not preplaced on the map.
	if (GetObjectByTeamSlot(Team, DLL_TEAM_SLOT_RECYCLER) == 0)
	then
		Handle VehicleH = 0;
		if (Mission.m_SpawnFacingCenter)
		then
			--spawnpointPosition = GetPositionNear(spawnpointPosition, VEHICLE_SPACING_DISTANCE, 2 * VEHICLE_SPACING_DISTANCE);
			-- Spawn Directly on Spawn, facing Center.
			local Center = GetCenterOfMap();
			local Front = GetFacingDrection2D(spawnpointPosition, Center);
			local Pos = Build_Directinal_Matrix(spawnpointPosition, Front);
			VehicleH = BuildObject(GetInitialRecyclerODF(TeamRaceH), Team, Pos);
		else
			spawnpointPosition = GetPositionNear(spawnpointPosition, VEHICLE_SPACING_DISTANCE, 2 * VEHICLE_SPACING_DISTANCE);
			VehicleH = BuildObject(GetInitialRecyclerODF(TeamRaceH), Team, spawnpointPosition);
			SetRandomHeadingAngle(VehicleH);
		end

		Mission.m_RecyclerHandles[Team] = VehicleH;
		SetGroup(VehicleH, 0);
	end

	-- Build all optional vehicles for this team.
	spawnpointPosition.x = Mission.m_TeamPos[3 * Team + 0]; -- restore default after we modified this for recy above
	spawnpointPosition.y = Mission.m_TeamPos[3 * Team + 1];
	spawnpointPosition.z = Mission.m_TeamPos[3 * Team + 2];

	-- Look for an _ in there, and copy everything after it into the RecyVariant tag. -GBD
	local TempODF[MAX_ODF_LENGTH] = then 0 end;
	local TempODF2[MAX_ODF_LENGTH] = then 0 end;
	local VariantName[MAX_ODF_LENGTH] = then 0 end;

	strcpy_s(TempODF, GetInitialRecyclerODF(TeamRaceH));
	CombineStrings(TempODF, TempODF, ".odf"); -- Add .odf to the end.

	OpenODF2(TempODF);

	if (GetODFString(TempODF, "GameObjectClass", "classlabel", MAX_ODF_LENGTH, TempODF2)) -- Grab the classlabel.
	then
		CombineStrings(TempODF2, TempODF2, ".odf"); -- Add .odf to the end.
		OpenODF2(TempODF2);
	end

	if (not GetODFString(TempODF, TempODF2, "GameObjectClass", "startingVariant", MAX_ODF_LENGTH, VariantName)) -- Grab the value.
	then
		--[[
		-- Snagged.
	else -- If this ODF is inherited, and try that ODF. If still nothing, then it's nothing.
		if(GetODFString(TempODF, "GameObjectClass", "classlabel", MAX_ODF_LENGTH, TempODF2)) -- Grab the classlabel.
		then
			CombineStrings2(TempODF2, TempODF2, ".odf"); -- Add .odf to the end.

			OpenODF2(TempODF2);
			if(GetODFString(TempODF2, "GameObjectClass", "startingVariant", MAX_ODF_LENGTH, VariantName)) -- Grab the value.
			then
				-- Snagged.
			else -- It didn't find either? Revert to old method.
			--]]
		const local *pUnderscore = strchr(GetInitialRecyclerODF(TeamRaceH), '_');
		if (pUnderscore ~= NULL)
		then
			const local *pUnderscore2 = strchr(pUnderscore + 1, '_');
			if (pUnderscore2 == NULL)
			then
				-- Only 1 underscore in the name, e.g. (ivrecy_vsr). Copy
				-- everything after it to the Variant Name.
				strcpy_s(VariantName, pUnderscore + 1);
			else
				-- 2 underscores in the name, e.g. (ivrecy_12_vsr). Copy
				-- everything after the 2nd Underscore to Variant Name.
				strcpy_s(VariantName, pUnderscore2 + 1);
			end
		end
		--[[
	end
end
--]]
	end

	-- Drop skill level while we build things.
	Mission.m_CreatingStartingVehicles = true;
	StartingVehicleManager::CreateVehicles(Team, TeamRaceH, VariantName, Mission.m_StartingVehiclesMask, spawnpointPosition);
	Mission.m_CreatingStartingVehicles = false;

	SetScrap(Team, 40);

	if (IsTeamplayOn())
	then
		for (local i = GetFirstAlliedTeam(Team); i <= GetLastAlliedTeam(Team); i++)
		then
			-- Make thier Pilots match the VSR ones, if present. -GBD
			SetPilotClass(GetPlayerHandle(i), GetInitialPlayerPilotODF(TeamRaceH, i, false));

			if (i ~= Team)
			then
				if (Mission.m_SpawnFacingCenter)
				then
					-- Use directly on Spawns.
					Mission.m_TeamPos[3 * i + 0] = spawnpointPosition.x;
					Mission.m_TeamPos[3 * i + 1] = spawnpointPosition.y;
					Mission.m_TeamPos[3 * i + 2] = spawnpointPosition.z;
				else -- Old Method.
					-- Get a new position near the team's central position
					local NewPosition = GetPositionNear(spawnpointPosition, AllyMinRadiusAway, AllyMaxRadiusAway);

					-- In teamplay, store where offense players were created for respawns later
					Mission.m_TeamPos[3 * i + 0] = NewPosition.x;
					Mission.m_TeamPos[3 * i + 1] = NewPosition.y;
					Mission.m_TeamPos[3 * i + 2] = NewPosition.z;
				end
			end -- Loop over allies not the commander
		end
	else
		-- Setup based on allies position. -GBD
		for (local i = 1; i < MAX_TEAMS; i++)
		then
			if ((i ~= Team) and (Mission.m_AllyTeams[Team] == Mission.m_AllyTeams[i]) and (Mission.m_ThugFlag[i]) and (not Mission.m_ThugFlag[Team]))
			then
				if (Mission.m_SpawnFacingCenter)
				then
					-- Use directly on Spawns.
					Mission.m_TeamPos[3 * i + 0] = spawnpointPosition.x;
					Mission.m_TeamPos[3 * i + 1] = spawnpointPosition.y;
					Mission.m_TeamPos[3 * i + 2] = spawnpointPosition.z;
				else -- Old method.
					local NewPosition = GetPositionNear(spawnpointPosition, AllyMinRadiusAway, AllyMaxRadiusAway);

					Mission.m_TeamPos[3 * i + 0] = NewPosition.x;
					Mission.m_TeamPos[3 * i + 1] = NewPosition.y;
					Mission.m_TeamPos[3 * i + 2] = NewPosition.z;
				end
			end
		end
	end

	if(Team == GetLocalPlayerTeamNumber())
		UpdateObjectives();

	Mission.m_TeamIsSetUp[Team] = true;
#endif -- #ifndef EDITOR
end

-- Given an index into the Player list, build everything for a given
-- single player (i.e. a vehicle of some sorts), and set up the team
-- as well as necessary
Handle Strategy02::SetupPlayer(local Team)
then
#ifndef EDITOR
	Handle PlayerH = 0;
	local Where(0, 0, 0);

	if ((Team < 0) or (Team >= MAX_TEAMS))
		return 0; -- Sanity check... do NOT proceed

	Mission.m_SpawnedAtTime[Team] = Mission.m_ElapsedGameTime; -- Note when they spawned in.

	local TeamBlock = WhichTeamGroup(Team);

	local Center = Vector(0, 0, 0);
	if (Mission.m_SpawnFacingCenter) -- Only fetch this data if we're using it. -GBD
		Center = GetCenterOfMap();

	if ((not IsTeamplayOn()) or (TeamBlock < 0))
	then
		-- This player is their own commander; set up their equipment.
		--SetupTeam(Team);

		if (not Mission.m_ThugFlag[Team]) -- If this player isn't a Thug. -GBD
		then
			if (Mission.NumCommanders < Mission.m_NumSpawnPoints) -- There's still a base slot available, do commander stuff.
			then
				if (not Mission.m_TeamIsSetUp[Team])
				then
					Mission.CommanderTeam[Mission.m_AllyTeams[Team]] = Team;
					++Mission.NumCommanders;
				end
				SetupTeam(Team);

				-- Now put player near his recycler
				Where.x = Mission.m_TeamPos[3 * Team + 0];
				Where.z = Mission.m_TeamPos[3 * Team + 2];
				Where.y = TerrainFindFloor(Where.x, Where.z) + 2.5;
			else -- Uh Oh, this map can't support any more commanding Teams. Lets cycle assign them to the next allied team.
				-- Remove this team's previous allied commitments.
				for (local t = 1; t < MAX_TEAMS; t++)
				then
					if (t ~= Team)
					then
						UnAlly(Team, t);
						UnAlly(t, Team);
					end
				end

				Mission.m_ThugFlag[Team] = true; -- Make them a thug.

				-- Cycled through all possible teams, begin again.
				local HighestTeam = -1;
				local NextAssignTeam = 0;
				for (local s = 0; s < MAX_TEAMS; s++)
				then
					if (Mission.CommanderTeam[s] > HighestTeam)
						HighestTeam = Mission.CommanderTeam[s];
				end

				for (local n = Mission.NextAutoAssignTeam; n < MAX_TEAMS; n++)
				then
					if (Mission.CommanderTeam[n])
					then
						NextAssignTeam = n;
						Mission.NextAutoAssignTeam = n + 1;

						if (Mission.NextAutoAssignTeam > HighestTeam)
							Mission.NextAutoAssignTeam = 0;
						break;
					end
				end

				Mission.m_AllyTeams[Team] = Mission.m_AllyTeams[NextAssignTeam];

				for (local x = 1; x < MAX_TEAMS; x++)
				then
					if ((Mission.m_AllyTeams[x] > 0) and (x ~= Team) and (Mission.m_AllyTeams[x] == Mission.m_AllyTeams[Team]))
					then
						Ally(x, Team);
						Ally(Team, x);
						Mission.m_HasAllies[x] = true;
						Mission.m_HasAllies[Team] = true;
					end
				end

				-- Re-initialize their starting position.
				Where.x = Mission.m_TeamPos[3 * Mission.CommanderTeam[Mission.m_AllyTeams[Team]] + 0];
				--Where.y = Mission.m_TeamPos[3*Mission.CommanderTeam[Mission.m_AllyTeams[Team]]+1];
				Where.z = Mission.m_TeamPos[3 * Mission.CommanderTeam[Mission.m_AllyTeams[Team]] + 2];
				Where.y = TerrainFindFloor(Where.x, Where.z) + 2.5;
				local NewPosition = Vector(0, 0, 0);

				++Mission.ThugCounter[Mission.CommanderTeam[Mission.m_AllyTeams[Team]]]; -- Incrument this.

				-- New method, spawn them facing radially around the map.
				if (Mission.m_SpawnFacingCenter)
				then
					local Front = GetFacingDrection2D(Where, Center); -- Faces center of the map.
					Front = HRotateFront(Front, (15.0f * Mission.ThugCounter[Mission.CommanderTeam[Mission.m_AllyTeams[Team]]]) * DEG_2_RAD);
					-- Step out 50m from this position. Facing local will be corrected later.
					NewPosition = Add_Vectors(Where, Vector_Scale(Front, 50.0f));
				else -- Old method.
					NewPosition = GetPositionNear(Where, AllyMinRadiusAway, AllyMaxRadiusAway);
				end

				Mission.m_TeamPos[3 * Team + 0] = NewPosition.x;
				Mission.m_TeamPos[3 * Team + 1] = NewPosition.y;
				Mission.m_TeamPos[3 * Team + 2] = NewPosition.z;
			end

		else -- This is a Thug player.
			++Mission.ThugCounter[Mission.CommanderTeam[Mission.m_AllyTeams[Team]]]; -- Incrument this.

			-- Re-initialize their starting position.
			Where.x = Mission.m_TeamPos[3 * Mission.CommanderTeam[Mission.m_AllyTeams[Team]] + 0];
			--Where.y = Mission.m_TeamPos[3*Mission.CommanderTeam[Mission.m_AllyTeams[Team]]+1];
			Where.z = Mission.m_TeamPos[3 * Mission.CommanderTeam[Mission.m_AllyTeams[Team]] + 2];
			Where.y = TerrainFindFloor(Where.x, Where.z) + 2.5;

			-- New method, spawn them facing radially around the map.
			if (Mission.m_SpawnFacingCenter)
			then
				local Front = GetFacingDrection2D(Where, Center); -- Faces center of the map.
				Front = HRotateFront(Front, (15.0f * Mission.ThugCounter[Mission.CommanderTeam[Mission.m_AllyTeams[Team]]]) * DEG_2_RAD);
				-- Step out 50m from this position. Facing local will be corrected later.
				Where = Add_Vectors(Where, Vector_Scale(Front, 50.0f));
			else -- Old method.
				-- Now put player near his recycler
				Where.x = Mission.m_TeamPos[3 * Team + 0];
				Where.z = Mission.m_TeamPos[3 * Team + 2];
				Where.y = TerrainFindFloor(Where.x, Where.z) + 2.5;
			end
		end

		--[[
		if(Mission.m_AllyTeams[Team] > 0)
		then
			if(not Mission.m_TeamIsSetUp[Mission.m_AllyTeams[Team]])
				SetupTeam(m_Mission.CommanderTeam[Mission.m_AllyTeams[Team]]);
		else
			SetupTeam(Team);
		end
		--]]
	else -- TeamPlay, do normal Team Stuff.
		-- Teamplay. Gotta put them near their defensive player. Also, 
		-- always ensure the recycler/etc has been set up for this
		-- team if we know who they are
		SetupTeam(GetMission.CommanderTeam(Team));

		-- SetupTeam will fill in the Mission.m_TeamPos[] array of positions
		-- for both the commander and offense players, so read out the
		-- results
		Where.x = Mission.m_TeamPos[3 * Team + 0];
		Where.z = Mission.m_TeamPos[3 * Team + 2];
		Where.y = TerrainFindFloor(Where.x, Where.z) + 2.5;

		if (Mission.m_SpawnFacingCenter)
		then
			local Front = GetFacingDrection2D(Where, Center); -- Faces center of the map.
			local ThugNumber = 0;
			if (Team < 6)
			then
				ThugNumber = Team - 1;
			else
				ThugNumber = Team - 7;
			end
			Front = HRotateFront(Front, (15.0f * ThugNumber) * DEG_2_RAD);
			-- Step out 50m from this position. Facing local will be corrected later.
			Where = Add_Vectors(Where, Vector_Scale(Front, 50.0f));
		end
	end -- Teamplay setup

	-- Custom code to Respawn the player as their previous selves (Or the previous player in that slot). -GBD
	const local *PlayerODF = GetPlayerODF(Team);
	local DoOldRespawn = true;
	const local *PlayerName = GetCVarItemStr(Team, 0);
	if (Mission.m_RestorePlayers)
	then
		if (_strnicmp(PlayerODF + 1, "vcamr_vsr", 9) == 0)
		then
			DoOldRespawn = true;
		else
			local Index = 0;
			if (Mission.m_RestorePlayers == 1)
			then
				for (local x = 0; x < MAX_TEAMS; x++)
				then
					if ((_stricmp(PlayerName, PlayerSavedName[x]) == 0) and -- Name Matches
						(((IsTeamplayOn()) and (Mission.m_SavedPlayerTeamGroup[x] == WhichTeamGroup(Team) + 1)) or -- Teamplay on, TeamGroup Matches
						((not IsTeamplayOn()) and (Mission.m_SavedPlayerTeamGroup[x] == Team))) and -- Non Team Play, Team Matches
							(DoesODFExist(PlayerShipODF[x]))) -- ODF Exists.
					then
						Index = x;
						DoOldRespawn = false;
						break; -- We found a match, abort.
					end
				end
				if (DoOldRespawn)
				then
					for (local x = 0; x < MAX_TEAMS; x++)
					then
						if (not PlayerSavedName[x][0]) -- This one is empty.
						then
							strcpy_s(PlayerSavedName[Team], PlayerName);
							break;
						end
					end
				end
			elseif (Mission.m_RestorePlayers == 2)
			then
				--[[
				if(PlayerSavedName[Team][0])
				then
					DoOldRespawn = false;
					Index = Team;
				else
					-- New slot.
					strcpy_s(PlayerSavedName[Team], PlayerName);
				end
				--]]
				--	--[[
				if ((((IsTeamplayOn()) and (Mission.m_SavedPlayerTeamGroup[Team] == WhichTeamGroup(Team) + 1)) or  -- Teamplay on, TeamGroup Matches
					((not IsTeamplayOn()) and (Mission.m_SavedPlayerTeamGroup[Team] == Team))) and -- Non Team Play, Team Matches
					(DoesODFExist(PlayerShipODF[Team]))) -- ODF Exists.
				then
					DoOldRespawn = false;
					Index = Team;
				else
					if (IsTeamplayOn())
					then
						Mission.m_SavedPlayerTeamGroup[Team] = WhichTeamGroup(Team) + 1;
					else
						Mission.m_SavedPlayerTeamGroup[Team] = Team;
					end
				end
				--	--]]
			end

			if (Index)
			then
				--	if(Team == 2)
				--	then
				--		local tempstr[256] = then0end;
				--		sprintf_s(tempstr, "Index: %d Restore Method: %d SPAWNING Player: %s ODF: %s", Index, Mission.m_RestorePlayers, PlayerName, PlayerShipODF[Index]); 
				--		PrintConsoleMessage(tempstr);
				--	end

				PlayerH = BuildObject(PlayerShipODF[Index], Team, PlayerMatrix[Index]); -- Restore their ship.
				SetPilotClass(PlayerH, SavedPilotODF[Index]); -- Restore their pilot.
				ReplaceWeapons(PlayerH, PlayerShipWeapons[Index], Mission.m_SavedPlayerLocalAmmo[Index]); -- Pass weapons to ReplaceWeapon function.
				SetCurHealth(PlayerH, Mission.m_SavedPlayerHealth[Index]);
				SetCurAmmo(PlayerH, Mission.m_SavedPlayerAmmo[Index]);
				SetPosition(PlayerH, PlayerMatrix[Index]);
				SetVelocity(PlayerH, PlayerVelocity[Index]);
				SetOmega(PlayerH, PlayerOmega[Index]);
				local ObjClass[MAX_ODF_LENGTH] = then 0 end;
				GetObjInfo(PlayerH, Get_GOClass, ObjClass);
				if ((_stricmp(ObjClass, "CLASS_SCAVENGER") == 0) or (_stricmp(ObjClass, "CLASS_SCAVENGERH") == 0))
					SetScavengerCurScrap(PlayerH, Mission.m_SavedPlayerScrap[Index]);

				if (Mission.m_SavedPlayerDeployed[Index])
					Deploy(PlayerH);

			--	for (local t = 0; t < MAX_HARDPOINTS; t++)
			--		SetCurLocalAmmo(PlayerH, Mission.m_SavedPlayerLocalAmmo[Index][t], t);

				if (IsTeamplayOn())
				then
					Mission.m_SavedPlayerTeamGroup[Index] = WhichTeamGroup(Team) + 1;
				else
					Mission.m_SavedPlayerTeamGroup[Index] = Team;
				end

				Mission.m_GiveWeaponsBack[Index] = true;
			end
		end
	end
	if ((not Mission.m_RestorePlayers) or (DoOldRespawn))
	then
		--	--[[
		if (_stricmp(PlayerName, "Krohonus_Legs") == 0)
		then
			PlayerH = BuildObject("evlegs_vsr", Team, Where);
		else
			--	--]]
			PlayerH = BuildObject(PlayerODF, Team, Where);
		end

		-- Force PTeam 0 and Deploy.
		if (_strnicmp(PlayerODF + 1, "vcamr_vsr", 9) == 0)
		then
			SetPerceivedTeam(PlayerH, 0);

			-- Set a timer to trigger deploy. It doesn't work so early. 1 tick later.
			--Mission.m_CameraPodDeployTimer[Team] = Mission.m_ElapsedGameTime + m_GameTPS;

			--[[
			-- Force initial Deploy.
			if(not IsDeployed(PlayerH))
			then
				PrintConsoleMessage("Deploying SetupPlayer");
				Deploy(PlayerH);
			end
			--]]
		end

		SetPilotClass(PlayerH, GetInitialPlayerPilotODF(GetRaceOfTeam(Team), Team, false)); -- Added to make your starting pilot match respawning pilot. -GBD

		-- Face the center of the map.
		if (Mission.m_SpawnFacingCenter)
		then
			local Front = GetFacingDrection2D(Where, Center);
			local Pos = Build_Directinal_Matrix(Where, Front);
			SetPosition(PlayerH, Pos);
			SetVectorPosition(PlayerH, Pos.posit);
		else -- Old method.
			SetRandomHeadingAngle(PlayerH);
		end
	end

	-- If on team 0 (dedicated server team), make this object gone from the world
	if (not Team)
		MakeInert(PlayerH);

	return PlayerH;
#else
	return 0;
#endif -- #ifndef EDITOR
end

-- Internal one-time setup
void Strategy02::Init(void)
then
	Handle PlayerH = 0;
	Handle PlayerEntryH = 0;

	-- Ensure variables pre-init'd to zero at the start
#ifndef EDITOR

	-- StartingVehicle file. Set if specified.
	const local *Contents = GetVarItemStr("network.session.svar6");
	if ((Contents ~= NULL) and (Contents[0]))
		StartingVehicleManager::Init(); --Contents); -- 6.2 compatability.

	local CaptureTarget[MAX_TEAMS][MAX_ODF_LENGTH]; -- Store these. -GBD
	memset(CaptureTarget, 0, sizeof(CaptureTarget)); --zero this out first.
	local NumCaptureTargetODFs = 0;
	local CaptureRandom = false;

	-- Read from the map's .trn file whether we respawn at altitude or
	-- not.
	then
		const char* pMapName = GetVarItemStr("network.session.svar0");
		local mapTrnFile[128];
		strcpy_s(mapTrnFile, pMapName);
		char* pDot = strrchr(mapTrnFile, '.');
		if (pDot)
		then
			*pDot = 0;
			strcat_s(mapTrnFile, ".trn");
			OpenODF2(mapTrnFile);
			GetODFBool(mapTrnFile, "DLL", "RespawnAtLowAltitude", &Mission.m_RespawnAtLowAltitude, false);
			GetODFFloat(mapTrnFile, "DLL", "FriendlySpawnpointMaxAllyRange", &Mission.m_FRIENDLY_SPAWNPOINT_MAX_ALLY, FRIENDLY_SPAWNPOINT_MAX_ALLY);
			GetODFFloat(mapTrnFile, "DLL", "FriendlySpawnpointMinEnemyRange", &Mission.m_FRIENDLY_SPAWNPOINT_MIN_ENEMY, FRIENDLY_SPAWNPOINT_MIN_ENEMY);
			GetODFFloat(mapTrnFile, "DLL", "RandomSpawnpointMinEnemyRange", &Mission.m_RANDOM_SPAWNPOINT_MIN_ENEMY, RANDOM_SPAWNPOINT_MIN_ENEMY);

			for (local x = 0; x < 16; x++)
			then
				local DesiredValue[MAX_ODF_LENGTH];
				sprintf_s(DesiredValue, "CaptureTarget%d", x + 1);
				if (GetODFString(mapTrnFile, "DLL", DesiredValue, MAX_ODF_LENGTH, CaptureTarget[x])) then
					++NumCaptureTargetODFs;
				else
					break;
				end
			end
			GetODFBool(mapTrnFile, "DLL", "CaptureIsRandom", &CaptureRandom, false);

			GetODFString(mapTrnFile, "VSR", "MapAmbientSound", MAX_ODF_LENGTH, MapAmbientSound, 0);
			if (DoesFileExist(MapAmbientSound))
				EasterEggSound = StartAudio2D(MapAmbientSound, -1, 0.0, 44100.0f, true, false);

			--	CloseODF(mapTrnFile);
		end
	end

	-- Set up some variables based on how things appear in the world
	Mission.m_DidInit = true;
	Mission.m_KillLimit = GetVarItemInt("network.session.ivar0");
	Mission.m_TotalGameTime = GetVarItemInt("network.session.ivar1");
	-- Skip ivar2-- player limit. Assume the netmgr takes care of that.
	-- ivar4 (vehicle prefs 1) read elsewhere.
	Mission.m_StartingVehiclesMask = GetVarItemInt("network.session.ivar7");

	-- Allow host to pick whatever. -GBD
	--[[
	-- Override the bitfields set in the shell, so that you start with
	-- 2 turrets, or nothing.
	if(Mission.m_StartingVehiclesMask)
		Mission.m_StartingVehiclesMask = 3;
	--]]
	-- Tell if this is an MPI based on ivar12. -GBD
	Mission.m_IsMPI = GetVarItemInt("network.session.ivar12");
	if (Mission.m_IsMPI)
	then
		-- Get AI Team Races -- 105 = ISDF -- 102 = Scion -- 99  = Cerberi
		Mission.m_AIRace[0] = GetVarItemInt("network.session.ivar13");
		Mission.m_AIRace[1] = GetVarItemInt("network.session.ivar96");
		Mission.m_AIRace[2] = GetVarItemInt("network.session.ivar97");
		Mission.m_AIRace[3] = GetVarItemInt("network.session.ivar98");
		Mission.m_AIRace[4] = GetVarItemInt("network.session.ivar99");
	--	Mission.m_AIRace[5] = GetVarItemInt("network.session.ivar100");
	--	Mission.m_AIRace[6] = GetVarItemInt("network.session.ivar101");
	--	Mission.m_AIRace[7] = GetVarItemInt("network.session.ivar102");
	--	Mission.m_AIRace[8] = GetVarItemInt("network.session.ivar103");
	--	Mission.m_AIRace[9] = GetVarItemInt("network.session.ivar104");

		Mission.m_CPUTurretAISkill = GetVarItemInt("network.session.ivar21");
		Mission.m_CPUTurretAISkill = clamp(Mission.m_CPUTurretAISkill, 0, 3);

		Mission.m_CPUNonTurretAISkill = GetVarItemInt("network.session.ivar22");
		Mission.m_CPUNonTurretAISkill = clamp(Mission.m_CPUNonTurretAISkill, 0, 3);

		Mission.m_HumanForce = GetVarItemInt("network.session.ivar23");
		Mission.m_HumanForce = clamp(Mission.m_HumanForce, 0, 3);

		Mission.m_CPUForce = GetVarItemInt("network.session.ivar24");
		Mission.m_CPUForce = clamp(Mission.m_CPUForce, 0, 3);
	end
	Mission.m_GameType = GetVarItemInt("network.session.ivar53");

	Mission.m_CaptureTime = GetVarItemInt("network.session.ivar54");
	Mission.m_CaptureTime = clamp(Mission.m_CaptureTime, 30, 120);
	Mission.m_CaptureTime = Mission.m_CaptureTime * m_GameTPS; -- Convert from seconds to ticks.

	Mission.m_PointsForAIKill = (GetVarItemInt("network.session.ivar14") ~= 0);
	Mission.m_KillForAIKill = (GetVarItemInt("network.session.ivar15") ~= 0);
	Mission.m_RespawnWithSniper = GetVarItemInt("network.session.ivar16");

	Mission.m_bIsFriendlyFireOn = (GetVarItemInt("network.session.ivar32") ~= 0);

	Mission.m_SetThugPilotFlag = (GetVarItemInt("network.session.ivar55") ~= 0);

	Mission.m_SpawnFacingCenter = GetVarItemInt("network.session.ivar118");

	Mission.m_RestorePlayers = GetVarItemInt("network.session.ivar119");
	Mission.m_RestorePlayers = clamp(Mission.m_RestorePlayers, 0, 2);

	Mission.m_PilotInvunerability = GetVarItemInt("network.session.ivar120");
	Mission.m_PilotInvunerability = clamp(Mission.m_PilotInvunerability, 0, 120);
	Mission.m_PilotInvunerability = Mission.m_PilotInvunerability * m_GameTPS; -- Convert from seconds to ticks.

	Mission.m_TurretAISkill = GetVarItemInt("network.session.ivar17");
	Mission.m_TurretAISkill = clamp(Mission.m_TurretAISkill, 0, 3);
	Mission.m_NonTurretAISkill = GetVarItemInt("network.session.ivar18");
	Mission.m_NonTurretAISkill = clamp(Mission.m_NonTurretAISkill, 0, 3);

	-- Remvoed Mission.m_Alliances, now just uses "Mission.m_HasAllies[TEAM]" flag set below. -GBD
--	if(IsTeamplayOn())
--	then
--		Mission.m_Alliances = 0; -- clear this 
--	end

--	else -- Redone ally code. -GBD
	-- Note: currently ivar23 must be > 0 for allies to pass units to thugs to F10 only. -GBD
	memset(Mission.m_AllyTeams, 0, sizeof(Mission.m_AllyTeams));
	if ((not IsTeamplayOn()) or (Mission.m_IsMPI))
	then
		-- Grab the "Team" numbers. 
		local VarName[MAX_ODF_LENGTH] = then 0 end;
		for (local i = 1; i < MAX_TEAMS; i++)
		then
			sprintf_s(VarName, "network.session.ivar%d", 34 + i);
			Mission.m_AllyTeams[i] = GetVarItemInt(VarName);

			if (Mission.m_AllyTeams[i] <= 0) -- If this is set to 0 or invalid, map inf probably didn't set it, so use Defaults. -GBD
				Mission.m_AllyTeams[i] = i;

			sprintf_s(VarName, "network.session.ivar%d", 80 + i);
			Mission.m_ThugFlag[i] = (clamp(GetVarItemInt(VarName), 0, 1));
		end

		-- In case MPI w/ teamplay is on, and host didn't set up default allies properly, make sure they're set so AI know who they're allied with.
		if (IsTeamplayOn())
		then
			local R[5] = then 0 end;
			local G[5] = then 0 end;
			local B[5] = then 0 end;

			for (local x = 1; x < 6; x++)
				GetTeamStratIndividualColor(TEAMCOLOR_TYPE_GAMEPREFS, x, R[x], G[x], B[x]);

			DefaultAllies();

			SetFFATeamColors(TEAMCOLOR_TYPE_GAMEPREFS);
			--	ClearTeamColor(0);

				--[[
				-- Unally "Team 2" from eachother except themselves.
				for(local x = 6; x < 11; x++)
				then
					for(local y = 6; y < 11; y++)
					then
						if(x ~= y)
							UnAlly(x, y);
					--	else
					--		Ally(x, y);
					end
				end
				--]]

				-- Clear TeamColors?
				--for(local x = 6; x < 11; x++)
				--	ClearTeamColor(x);

				-- Re-Ally "Team 1", Teams 1-5 with eachother.
			for (local x = 1; x < 6; x++)
			then
				SetTeamColor(x, R[x], G[x], B[x]);
				for (local y = 1; y < 6; y++)
				then
					if (x ~= y)
					then
						Ally(x, y);
						-- Force Thug settings to match Commander.
						if (x == 1)
							Mission.m_AllyTeams[y] = Mission.m_AllyTeams[x];
					end
				end
			end
		end

		-- Loop over all teams, and ally them if they're set like that. 
		for (local x = 1; x < MAX_TEAMS; x++)
		then
			for (local y = 1; y < MAX_TEAMS; y++)
			then
				if ((Mission.m_AllyTeams[x] > 0) and (x ~= y) and (Mission.m_AllyTeams[x] == Mission.m_AllyTeams[y]))
				then
					Ally(x, y);
					--Ally(y, x);
					Mission.m_HasAllies[x] = true;
					--		Mission.m_Alliances = 1; -- Flag this if it's on for any teams. 

						--	sprintf_s(TempMsgString, "Allying %d with %d", x, y);
						--	PrintConsoleMessage(TempMsgString);

					-- If MPI is on, Ally Thugs with Commander's setting.
					if ((IsTeamplayOn()) and (x == 1))
					then
						for (local j = GetFirstAlliedTeam(x); j < GetLastAlliedTeam(x) + 1; j++)
						then
							Ally(j, y);

							--	sprintf_s(TempMsgString, "Allying Thug %d with %d", j, y);
							--	PrintConsoleMessage(TempMsgString);
						end
					end
				end
			end
		end	-- Finshed looping.

		-- Setup their commander.
		for (local i = 1; i < MAX_TEAMS; i++)
		then
			if (not Mission.m_TeamHasCommander[Mission.m_AllyTeams[i]]) --and (Mission.NumCommanders < Mission.m_NumSpawnPoints)) -- This team has no set commander, lets find one. 
			then
				for (local x = 0; x < MAX_TEAMS; x++)
				then
					if ((not Mission.m_ThugFlag[x]) and (Mission.m_AllyTeams[i] == Mission.m_AllyTeams[x])) -- This is a commander, set them for their team. 
					then
						--		m_Mission.CommanderTeam[Mission.m_AllyTeams[i]] = x;
						Mission.m_TeamHasCommander[Mission.m_AllyTeams[i]] = true;

						--	sprintf_s(TempMsgString, "Setting Commander for Team %d to Team %d", Mission.m_AllyTeams[i], x);
						--	PrintConsoleMessage(TempMsgString);

						break; --found one.
					end
				end

				if (not Mission.m_TeamHasCommander[Mission.m_AllyTeams[i]]) -- Uh oh, no commander set. Pick the first player.
				then
					for (local p = 0; p < MAX_TEAMS; p++)
					then
						if (Mission.m_AllyTeams[p] == Mission.m_AllyTeams[i]) -- This player is on same team. flag them.
						then
							Mission.m_ThugFlag[p] = false;
							--	m_Mission.CommanderTeam[Mission.m_AllyTeams[i]] = p;
							Mission.m_TeamHasCommander[Mission.m_AllyTeams[i]] = true;

							--	sprintf_s(TempMsgString, "UH-OHnot  No Commander for Team %d, Setting to Team %d", Mission.m_AllyTeams[i], p);
							--	PrintConsoleMessage(TempMsgString);

							break; -- found one.
						end
					end
				end
				--	++Mission.NumCommanders;
			end
		end
	end

	Mission.m_RecyInvulnerabilityTime = GetVarItemInt("network.session.ivar25");
	Mission.m_RecyInvulnerabilityTime *= 60 * m_GameTPS; -- convert from minutes to ticks (10 ticks per second)

	-- The BZN has a player in the world. We need to delete them, as
	-- this code (either on this machine or remote machines) handles
	-- creation of the proper vehicles in the right places for
	-- everyone.
	PlayerEntryH = GetPlayerHandle();
	if (PlayerEntryH)
		RemoveObject(PlayerEntryH);

	-- Do all the one-time server side init of varbs. These varbs are
	-- saved out and read in on clientside, if saved in the proper
	-- place above. This needs to be done after toasting the initial
	-- vehicle
	if ((ImServer()) or (not IsNetworkOn()))
	then
		Mission.m_ElapsedGameTime = 0;
		if (not Mission.m_RemainingGameTime)
			Mission.m_RemainingGameTime = Mission.m_TotalGameTime * 60 * m_GameTPS; -- convert minutes to 1/10 seconds

		if (Mission.m_IsMPI)
		then
			Mission.m_LastTauntPrintedAt = -2000; -- Force first message to be printed...
			-- Let the taunt system know where to find things it uses.
			InitTaunts(&Mission.m_ElapsedGameTime, &Mission.m_LastTauntPrintedAt, &m_GameTPS);
		end
	end

	-- And build the local player for the server
	local LocalTeamNum = GetLocalPlayerTeamNumber(); -- Query this from game
	PlayerH = SetupPlayer(LocalTeamNum);
	SetAsUser(PlayerH, LocalTeamNum);
	AddPilotByHandle(PlayerH);


	-- ST: Capture mode, spawn capture points. -GBD
	if (Mission.m_GameType == 4)
	then
		local pathCount;
		local **pathNames;

		local Random = 0.0;
		GetAiPaths(pathCount, pathNames);
		for (local i = 0; i < pathCount; ++i)
		then
			local *label = pathNames[i];

			if (NumCaptureTargetODFs > 0)
			then
				--PrintConsoleMessage(DesiredName);
				local num = -1;
				if ((sscanf_s(label, "capturegoal%d", &num) > 0) and (Mission.m_NumCaptureGoals < MAX_TEAMS))
				then
					if (CaptureRandom)
					then
						Random = (floor(GetRandomFloat((float)NumCaptureTargetODFs)));
						if (Random >= NumCaptureTargetODFs)
							Random = (float)NumCaptureTargetODFs;
					else
						if (Random > NumCaptureTargetODFs)
							Random = 0;
					end

					if (DoesODFExist(CaptureTarget[(int)Random]))
					then
						Mission.m_CaptureGoals[Mission.m_NumCaptureGoals] = BuildObject(CaptureTarget[(int)Random], 0, label);

						if (IsAround(Mission.m_CaptureGoals[Mission.m_NumCaptureGoals]))
						then
							SetObjectiveOn(Mission.m_CaptureGoals[Mission.m_NumCaptureGoals]);
							++Mission.m_NumCaptureGoals;
						end
						++Random;
					else
						sprintf_s(TempMsgString, "Error: ODF '%s' doesn't existnot ", CaptureTarget[(int)Random]);
						PrintConsoleMessage(TempMsgString);
					end
				end
			else
				PrintConsoleMessage("Error: Map has no Capture ODF's setnot ");
			end
		end
	end

#endif -- #ifndef EDITOR
end

-- Called from Execute, m_GameTPS of a second has elapsed. Update everything.
void Strategy02::UpdateGameTime(void)
then
#ifndef EDITOR
	Mission.m_ElapsedGameTime++;

	-- Are we in a time limited game?
	if (Mission.m_RemainingGameTime > 0)
	then
		Mission.m_RemainingGameTime--;
		if (not (Mission.m_RemainingGameTime % m_GameTPS))
		then
			-- Convert tenth-of-second ticks to hour/minutes/seconds format.
			local Seconds = Mission.m_RemainingGameTime / m_GameTPS;
			local Minutes = Seconds / 60;
			local Hours = Minutes / 60;
			-- Lop seconds and minutes down to 0..59 once we've grabbed
			-- non-remainder out.
			Seconds %= 60;
			Minutes %= 60;

			if (Hours)
			then
				sprintf_s(TempMsgString, GetBZCCLocalizedString("mission", "Time Left %d:%02d:%02d\n"), Hours, Minutes, Seconds);
			else
				sprintf_s(TempMsgString, GetBZCCLocalizedString("mission", "Time Left %d:%02d\n"), Minutes, Seconds);
			end
			SetTimerBox(TempMsgString);

			-- Also prlocal this out more visibly at important times....
			if (Hours == 0)
			then
				-- Every 5 minutes down to 10 minutes, then every minute
				-- thereafter.
				if ((Seconds == 0) and ((Minutes <= 10) or (not (Minutes % 5))))
				then
					AddToMessagesBox(TempMsgString);
				else
					-- Every 5 seconds when under a minute is remaining.
					if ((Minutes == 0) and (not (Seconds % 5)))
					then
						AddToMessagesBox(TempMsgString);
					end
				end
			end
		end

		-- Game over due to timeout?
		if (not Mission.m_RemainingGameTime)
		then
			NoteGameoverByTimelimit();
			DoGameover(10.0f);
		end

	else
		-- Infinite time game. Periodically update ingame clock.
		if (not (Mission.m_ElapsedGameTime % m_GameTPS))
		then

			-- Convert tenth-of-second ticks to hour/minutes/seconds format.
			local Seconds = Mission.m_ElapsedGameTime / m_GameTPS;
			local Minutes = Seconds / 60;
			local Hours = Minutes / 60;
			-- Lop seconds and minutes down to 0..59 once we've grabbed
			-- non-remainder out.
			Seconds %= 60;
			Minutes %= 60;

			if (Hours)
			then
				sprintf_s(TempMsgString, GetBZCCLocalizedString("mission", "Mission Time %d:%02d:%02d"), Hours, Minutes, Seconds);
			else
				sprintf_s(TempMsgString, GetBZCCLocalizedString("mission", "Mission Time %d:%02d"), Minutes, Seconds);
			end
			SetTimerBox(TempMsgString);
		end
	end
#endif -- #ifndef EDITOR
end

-- If Recycler invulnerability is on, then does the job of it.
void Strategy02::ExecuteRecyInvulnerability(void)
then
	-- No need to do anything more...
	if ((Mission.m_GameOver) or (Mission.m_RecyInvulnerabilityTime == 0))
		return;

	local i;
	Handle recyHandle; -- for this team, either vehicle or building
	for (i = 0; i < MAX_TEAMS; i++)
	then
		if (Mission.m_TeamIsSetUp[i])
		then

			-- Check if recycler vehicle still exists. Side effect to
			-- note: IsAliveAndPilot zeroes the handle if pilot missing;
			-- that'd be bad for us here if we want to manually remove
			-- it. Thus, we have a sacrificial copy of it the game can
			-- obliterate w/o hurting anything.
			Handle TempH = Mission.m_RecyclerHandles[i];
			if ((not IsAlive(TempH)) or (TempH == 0))
			then
				recyHandle = GetObjectByTeamSlot(i, DLL_TEAM_SLOT_RECYCLER);
			else
				recyHandle = Mission.m_RecyclerHandles[i];
			end

			if (recyHandle and DLLUtils::IsRecycler(recyHandle))
			then
				SetCurHealth(recyHandle, GetMaxHealth(recyHandle));
			end

		end -- Mission.m_TeamIsSetUp[i]
	end -- i loop over all teams

	-- Prlocal periodic message about recycler invulnerability time left
	if ((Mission.m_RecyInvulnerabilityTime == 1) or
		((Mission.m_RecyInvulnerabilityTime % (60 * m_GameTPS)) == 0) or
		((Mission.m_RecyInvulnerabilityTime < (60 * m_GameTPS)) and ((Mission.m_RecyInvulnerabilityTime % (15 * m_GameTPS)) == 0)))
	then

		if (Mission.m_RecyInvulnerabilityTime == 1)
		then
			const char* loc = GetBZCCLocalizedString("strat", "recyclersVulnerable");
			sprintf_s(TempMsgString, loc);
		elseif (Mission.m_RecyInvulnerabilityTime > (60 * m_GameTPS))
		then
			const char* loc = GetBZCCLocalizedString("strat", "invulnerableExpiresMin");
			sprintf_s(TempMsgString, loc, Mission.m_RecyInvulnerabilityTime / (60 * m_GameTPS));
		else
			const char* loc = GetBZCCLocalizedString("strat", "invulnerableExpiresSec");
			sprintf_s(TempMsgString, loc, Mission.m_RecyInvulnerabilityTime / m_GameTPS);
		end

		AddToMessagesBox2(TempMsgString, RGB_MAKE(255, 0, 255)); -- bright purple (ARGB)
	end

	-- Reduce timer
	--Mission.m_RecyInvulnerabilityTime;
end

void Strategy02::ExecuteCheckIfGameOver(void)
then
#ifndef EDITOR
	-- No need to do anything more...
	if ((Mission.m_GameOver) or (Mission.m_ElapsedGameTime < (m_GameTPS)))
		return;

	-- Check for a gameover by no recycler & factory
	local i, NumFunctioningTeams = 0;
	local TeamIsFunctioning[MAX_TEAMS];
	local AlliesFunctioning[MAX_TEAMS]; -- Ally Functioning Flag. -GBD
	local HumansAlive = false; -- Assume so for MPI.
	local TeamPlayOn = IsTeamplayOn();

	memset(TeamIsFunctioning, 0, sizeof(TeamIsFunctioning));
	memset(AlliesFunctioning, 0, sizeof(AlliesFunctioning)); -- Memset for ally flag. -GBD

	for (i = 0; i < MAX_TEAMS; i++)
	then
		if (Mission.m_TeamIsSetUp[i])
		then
			local Functioning = false; -- Assume so for now.


			-- Check if recycler vehicle still exists. Side effect to
			-- note: IsAliveAndPilot zeroes the handle if pilot missing;
			-- that'd be bad for us here if we want to manually remove
			-- it. Thus, we have a sacrificial copy of it the game can
			-- obliterate w/o hurting anything.
			Handle TempH = Mission.m_RecyclerHandles[i];

			-- Added to allow recycler upgrading?
			if (not IsAround(TempH))
				TempH = GetObjectByTeamSlot(i, DLL_TEAM_SLOT_RECYCLER);

			-- Use the side effect of IsAlive as well, hence the TempH == 0
			if ((not TempH) or (not IsAlive(TempH)))
			then
				Mission.m_RecyclerHandles[i] = 0; -- Clear this out for later
			else
				Functioning = true;
			end

			Handle RecyH = 0;
			-- Check vehicle if it is around, else, check the buuilding
			--if(IsAround(TempH)) -- This could let you drive it. :)
			if ((IsAlive(TempH)) or (TempH ~= 0))
			then
				RecyH = TempH;
			else
				RecyH = GetObjectByTeamSlot(i, DLL_TEAM_SLOT_RECYCLER);
			end

			-- Check RecyH is around (note that buildings are not "alive"
			if (not RecyH) -- Uh oh, no Recycler? Look for Factory. -GBD
			then
				RecyH = GetObjectByTeamSlot(i, DLL_TEAM_SLOT_FACTORY);
			end

			if (RecyH)
			then
				if ((Mission.m_IsMPI) and (i < 11))
				then
					HumansAlive = true;
				end

				Functioning = true;
			end

			AlliesFunctioning[Mission.m_AllyTeams[i]] = AlliesFunctioning[Mission.m_AllyTeams[i]] or Functioning;
			TeamIsFunctioning[i] = Functioning;


			-- Moved Respawn check here to look for allies too. -GBD
			-- Note deployed location first time it deploys, also every 25.6 seconds
			if ((not Mission.m_NotedRecyclerLocation[i]) or (not (Mission.m_ElapsedGameTime & 0xFF)))
			then
				if (not TeamPlayOn) -- FFA only.
				then
					-- First pass, look for Commander's Recycler/Factory.
					if (not RecyH)
						RecyH = GetObjectByTeamSlot(Mission.CommanderTeam[Mission.m_AllyTeams[i]], DLL_TEAM_SLOT_RECYCLER);
					if (not RecyH) -- Uh oh, no Recycler? Look for Factory. -GBD
						RecyH = GetObjectByTeamSlot(Mission.CommanderTeam[Mission.m_AllyTeams[i]], DLL_TEAM_SLOT_FACTORY);
				end

				-- Grab out allie's Recy for respawn placement if ours is dead.
				if (not RecyH) -- Uh oh, your recy+factory are dead. Look for ones on allied teams.
				then
					for (local x = 1; x < MAX_TEAMS; x++) -- Loop through all teams. 
					then
						-- If the team is set, and it's not the same team as the first loop, and they're allied, then we found one. 
						if ((i ~= x) and (IsTeamAllied(i, x)))
						then
							RecyH = GetObjectByTeamSlot(x, DLL_TEAM_SLOT_RECYCLER);
							if (not RecyH) -- Uh oh, no Recycler? Look for Factory.
								RecyH = GetObjectByTeamSlot(x, DLL_TEAM_SLOT_FACTORY);

							if (RecyH)
								break; --x = 16; -- We found one, and they're alive. Abort X loop early. 
						end
					end
				end


				if (RecyH) -- The above functions found something...-GBD
				then
					Mission.m_NotedRecyclerLocation[i] = true;
					local RecyPos;
					GetPosition(RecyH, RecyPos);
					Mission.m_TeamPos[3 * i + 0] = RecyPos.x;
					Mission.m_TeamPos[3 * i + 1] = RecyPos.y;
					Mission.m_TeamPos[3 * i + 2] = RecyPos.z;
					-- Apply this to thugs also.
					if (TeamPlayOn)
					then
						for (local jj = GetFirstAlliedTeam(i); jj <= GetLastAlliedTeam(i); jj++)
						then
							-- In teamplay, store where offense players were created for respawns later
							Mission.m_TeamPos[3 * jj + 0] = RecyPos.x;
							Mission.m_TeamPos[3 * jj + 1] = RecyPos.y;
							Mission.m_TeamPos[3 * jj + 2] = RecyPos.z;
						end -- Loop over allies not the commander
					end
				end -- Note deployed location
			end
		end -- Team is set up
	end -- loop over functioning teams

	for (i = 0; i < MAX_TEAMS; i++)
	then
		if ((not Mission.m_IsMPI) and (TeamPlayOn))
		then
			if (TeamIsFunctioning[i])
				NumFunctioningTeams++;
		else
			if (AlliesFunctioning[i])
				NumFunctioningTeams++;
		end
	end

	-- MPI, Special abort early if all humans are dead.
	if ((Mission.m_IsMPI) and (not HumansAlive))
	then
		NoteGameoverWithCustomMessage("All Human bases destroyednot ");

		DoGameover(endDelta);
		Mission.m_GameOver = true;
	end

	-- Keep track if we ever had several teams playing. Don't need
	-- to check for gameover if so-- 
	if (NumFunctioningTeams > 1)
	then
		Mission.m_HadMultipleFunctioningTeams = true;
		return; -- Exit function early
	end

	-- Easy Gameover case: nobody's got a functioning base. End everything now.
	if ((NumFunctioningTeams == 0) and (Mission.m_ElapsedGameTime > (5 * m_GameTPS)))
	then
		NoteGameoverByNoBases();
		DoGameover(endDelta);
		Mission.m_GameOver = true;
	else
		if ((Mission.m_HadMultipleFunctioningTeams) and (NumFunctioningTeams == 1))
		then
			-- Ok, at one polocal we had >1 teams playing, now we've got
			-- 1. They're the winner.

			-- In teamplay, report the team as the winner
			if (TeamPlayOn)
			then
				local AIWon[MAX_TEAMS] = then 0 end;
				local WinningTeamgroup = -1;
				for (i = 0; i < MAX_TEAMS; i++)
				then
					if (TeamIsFunctioning[i])
					then
						if (Mission.m_IsMPI)
						then
							if (i < 11)
							then
								DoTaunt(TAUNTS_CPURecyDestroyed);
							else
								DoTaunt(TAUNTS_HumanRecyDestroyed);
							end
						end
						if (WinningTeamgroup == -1)
						then
							if ((Mission.m_IsMPI) and (i > 10))
							then
								if (Mission.m_HasAllies[i])
								then
									if (not AIWon[Mission.m_AllyTeams[i]])
									then
										AIWon[Mission.m_AllyTeams[i]] = true;
										sprintf_s(TempMsgString, "Computer Team %d has won, destroyed all enemy bases.", Mission.m_AllyTeams[i]); -- Tell who wonnot  -GBD
										NoteGameoverWithCustomMessage(TempMsgString); -- Custom message ftw. -GBD
									end
								else
									sprintf_s(TempMsgString, "Computer Team %d has won, destroyed all enemy bases.", i); -- Tell who wonnot  -GBD
									NoteGameoverWithCustomMessage(TempMsgString); -- Custom message ftw. -GBD
								end
							else
								WinningTeamgroup = WhichTeamGroup(i);
								NoteGameoverByLastTeamWithBase(WinningTeamgroup);
							end
						end
					end
				end

				-- Also, give all players on winning team points...
				for (i = 0; i < MAX_TEAMS; i++)
				then
					if (WhichTeamGroup(i) == WinningTeamgroup)
						AddScore(GetPlayerHandle(i), ScoreForWinning);
				end
				DoGameover(endDelta);
				Mission.m_GameOver = true;
			-- Teamplay is on
			else -- Non-teamplay, report individual winner
				-- With alliances, we may not have a winner unless the team
				-- remaining isn't allied (or we would have caught it above)
				--[[ -- Removed old code. -GBD
				local FirstTeam=0;
				if(Mission.m_Alliances)
					FirstTeam = 5;
				--]]
				local AIWon[MAX_TEAMS] = then 0 end;

				for (i = 0; i < MAX_TEAMS; i++) -- Start at 0. Also give a more proper message if allies are on. -GBD
				then
					if (Mission.m_IsMPI)
					then
						if (i < 11)
						then
							DoTaunt(TAUNTS_CPURecyDestroyed);
						else
							DoTaunt(TAUNTS_HumanRecyDestroyed);
						end
					end

					if (AlliesFunctioning[Mission.m_AllyTeams[i]])
					then
						if ((Mission.m_IsMPI) and (i > 10))
						then
							if (Mission.m_HasAllies[i])
							then
								if (not AIWon[Mission.m_AllyTeams[i]])
								then
									AIWon[Mission.m_AllyTeams[i]] = true;
									sprintf_s(TempMsgString, "Computer Team %d has won, destroyed all enemy bases.", Mission.m_AllyTeams[i]); -- Tell who wonnot  -GBD
									NoteGameoverWithCustomMessage(TempMsgString); -- Custom message ftw. -GBD
								end
							else
								sprintf_s(TempMsgString, "Computer Team %d has won, destroyed all enemy bases.", i); -- Tell who wonnot  -GBD
								NoteGameoverWithCustomMessage(TempMsgString); -- Custom message ftw. -GBD
							end
						elseif (Mission.m_HasAllies[i])
						then
							local TeamName[MAX_ODF_LENGTH];
							sprintf_s(TeamName, "%s %d", GetBZCCLocalizedString("cfg", "Team"), Mission.m_AllyTeams[i]); -- Tell who won. -GBD
							sprintf_s(TempMsgString, GetBZCCLocalizedString("Network", "HitLastWithBaseStr"), TeamName);

							for (local j = 0; j < MAX_TEAMS; j++) -- Give score to allies. -GBD
							then
								if ((i ~= j) and (IsTeamAllied(i, j)))
									AddScore(GetPlayerHandle(j), ScoreForWinning);
							end
						else
							NoteGameoverByLastWithBase(GetPlayerHandle(i));
						end
						AddScore(GetPlayerHandle(i), ScoreForWinning);
					end
				end
				DoGameover(endDelta);
				Mission.m_GameOver = true;
			end -- Non-teamplay.

		end -- Winner
	end
#endif -- #ifndef EDITOR
end

void Strategy02::Execute(void)
then
	--and this -GBD
	if (not Mission.StopScript)
		LuaMission::Execute();

	if (not Mission.m_DidInit)
		Init();

#ifndef EDITOR

	-- If Recycler invulnerability is on, then does the job of it.
	ExecuteRecyInvulnerability();

	-- Check for absence of recycler & factory, gameover if so.
	ExecuteCheckIfGameOver();

	-- Do this as well...
	UpdateGameTime();

	-- watch for winner.
	if (Mission.m_GameType == 4)
		ExecuteST_Capture();

	local TeamPlayOn = IsTeamplayOn();

	-- VSR Specific stuff. -GBD
	for (local Team = 0; Team < MAX_TEAMS; Team++)
	then
		--[[ -- Buggery Stuffs. -GBD
		-- Special case for FFA MPI.
		if((Mission.m_IsMPI) and (Mission.m_SetScrapNextTurn[Team] > 0))
		then
			ResetTeamSlot(Mission.m_RecyclerHandles[Team]);
			if(Team ~= 6)
				ResetTeamSlot(Mission.m_RecyclerHandles[6]); -- We had to have to reset this too.

			AddMaxScrap(Team, Mission.m_SetScrapNextTurn[Team]);
			AddMaxScrap(6, -Mission.m_SetScrapNextTurn[Team]);
			SetScrap(Team, 40);
			Mission.m_SetScrapNextTurn[Team] = 0;

		--	sprintf_s(TempMsgString, "Recy Switching Team: %d, %d. Scrap: %d, %d, MaxScrap: %d, %d", 6, Team, GetScrap(6), GetScrap(Team), GetMaxScrap(6), GetMaxScrap(Team));
		--	PrintConsoleMessage(TempMsgString);
		end
		--]]

		Handle TempPlayerH = GetPlayerHandle(Team);

		-- Special note: IsAround is required here, (or GetCurHealth >= 0), as GetPlayerHandle(local Team) will return the handle one tick after it has died/expired,
		-- so the final update would pass in the Handle ID, but not all the information would be valid on the now Dead handle.
		if (IsAround(TempPlayerH)) -- If there is a player in this Team slot, otherwise don't bother updating anything.
		then
			-- Pilot Invulnerability.
			if ((Mission.m_PilotInvTime[Team] > 0) and (Mission.m_PilotInvUser[Team] == TempPlayerH)) -- Make sure they're actually there before counting down timer.
			then
				--Mission.m_PilotInvTime[Team];

				if (GetCurAmmo(Mission.m_PilotInvUser[Team]) < GetMaxAmmo(Mission.m_PilotInvUser[Team]))
					Mission.m_PilotInvTime[Team] = 0;

				--if((Mission.m_PilotInvUser[Team] == GetPlayerHandle(Team)) and (Mission.m_PilotInvTime[Team] <= 0))
				if ((Mission.m_PilotInvTime[Team] <= 0) and (IsAround(Mission.m_PilotInvUser[Team])))
					SetMaxHealth(Mission.m_PilotInvUser[Team], Mission.m_SavedPilotInvHealth[Team]);
			end

			-- Camera Pod Alliance Stuff.
			local PlayerODF[MAX_ODF_LENGTH] = then 0 end;
			GetObjInfo(TempPlayerH, Get_CFG, PlayerODF);
			if (not DoesODFExist(PlayerODF))
			then
				local *dot = strchr(PlayerODF, ':'); -- Remove everything from the : on.
				local len = dot - PlayerOD;
				strncpy_s(PlayerODF, PlayerODF, len);
			end
			-- If this person is in a "spectator" camera pod, constantly set them to percievedteam 0 so nothing shoots them.
			if (_strnicmp(PlayerODF + 1, "vcamr_vsr", 9) == 0)
			then
				SetPerceivedTeam(TempPlayerH, 0);

				-- No longer Deployable. Just non collidable now. -GBD
				--[[
				if (Team == GetLocalPlayerTeamNumber())
				then
					VehicleControls controls;
					controls.deploy = 0;
					controls.abandon = 0;
					SetControls(TempPlayerH, controls,
						CTRL_DEPLOY +
						CTRL_ABANDON
					);
				end

				-- If they undeploy, force re-deploy.
				if ((Mission.m_ElapsedGameTime >= Mission.m_CameraPodDeployTimer[Team]) and (not IsDeployed(TempPlayerH)))
				then
					Deploy(TempPlayerH);
					Mission.m_CameraPodDeployTimer[Team] = Mission.m_ElapsedGameTime + m_GameTPS; -- Reset Timer.
				end
				--]]

				if (not Mission.IsCameraPod[Team])
				then
					for (local t = 1; t < MAX_TEAMS; t++)
						if (t ~= Team)
							UnAlly(t, Team);

					Mission.IsCameraPod[Team] = true;
				end
			else
				if (Mission.IsCameraPod[Team])
				then
					if (TeamPlayOn)
					then
						for (local x = GetFirstAlliedTeam(Team); x <= GetLastAlliedTeam(Team); x++)
						then
							Ally(x, Team);
						end
					else
						for (local x = 1; x < MAX_TEAMS; x++)
						then
							if ((Mission.m_AllyTeams[x] > 0) and (x ~= Team) and (Mission.m_AllyTeams[x] == Mission.m_AllyTeams[Team]))
							then
								Ally(x, Team);
							end
						end
					end
					Mission.IsCameraPod[Team] = false;
				end
			end

			-- Restore Players code.
			if ((Mission.m_RestorePlayers > 0) and (_strnicmp(PlayerODF + 1, "vcamr_vsr", 9) ~= 0) and (_strnicmp(PlayerODF + 1, "vsatview_vsr", 12) ~= 0))
			then
				const local *PlayerName = GetCVarItemStr(Team, 0);
				local PilotODF[MAX_ODF_LENGTH] = then 0 end;
				local ObjClass[MAX_ODF_LENGTH] = then 0 end;
				GetObjInfo(TempPlayerH, Get_GOClass, ObjClass);
				if (const local *pilotOdf = GetPilotClass(TempPlayerH))
				then
					strcpy_s(PilotODF, pilotOdf);
					if (local *dot = strrchr(PilotODF, '.'))
						*dot = '\0';
				end

				local Index = 0;
				if (Mission.m_RestorePlayers == 1)
				then
					for (local x = 0; x < MAX_TEAMS; x++)
					then
						if (_stricmp(PlayerName, PlayerSavedName[x]) == 0)
						then
							Index = x;
							break; -- We found one.
						end
					end
				elseif (Mission.m_RestorePlayers == 2)
				then
					--	--[[
					if ((((TeamPlayOn) and (Mission.m_SavedPlayerTeamGroup[Team] == WhichTeamGroup(Team) + 1)) or  -- Teamplay on, TeamGroup Matches
						((not TeamPlayOn) and (Mission.m_SavedPlayerTeamGroup[Team] == Team)))) -- Non Team Play, Team Matches
					then
						Index = Team;
					end
					--	--]]
						--[[
						-- If this player was ever anything.
						if((PlayerName[0]) and (PlayerSavedName[Team][0]))
							Index = Team;
						--]]
				end

				if (Index)
				then
					strcpy_s(PlayerShipODF[Index], PlayerODF);
					strcpy_s(SavedPilotODF[Index], PilotODF);
					strcpy_s(PlayerSavedName[Index], PlayerName);

					for (local i = 0; i < MAX_HARDPOINTS; i++)
					then
						GetObjInfo(TempPlayerH, ObjectInfoType(Get_Weapon0Config + i), PlayerShipWeapons[Index][i]);
						Mission.m_SavedPlayerLocalAmmo[Index][i] = GetCurLocalAmmo(TempPlayerH, i);
					end

					Mission.m_SavedPlayerHealth[Index] = GetCurHealth(TempPlayerH);
					Mission.m_SavedPlayerAmmo[Index] = GetCurAmmo(TempPlayerH);
					GetPosition(TempPlayerH, PlayerMatrix[Index]);
					PlayerVelocity[Index] = GetVelocity(TempPlayerH);
					PlayerOmega[Index] = GetOmega(TempPlayerH);
					if ((_stricmp(ObjClass, "CLASS_SCAVENGER") == 0) or (_stricmp(ObjClass, "CLASS_SCAVENGERH") == 0))
						Mission.m_SavedPlayerScrap[Index] = GetScavengerCurScrap(TempPlayerH);

					if (IsDeployed(TempPlayerH))
					then
						Mission.m_SavedPlayerDeployed[Index] = true;
					else
						Mission.m_SavedPlayerDeployed[Index] = false;
					end

					if (TeamPlayOn)
					then
						Mission.m_SavedPlayerTeamGroup[Index] = WhichTeamGroup(Team) + 1;
					else
						Mission.m_SavedPlayerTeamGroup[Index] = Team;
					end

					if (_stricmp(ObjClass, "CLASS_PERSON") == 0)
					then
						if (not Mission.m_GiveWeaponsBack[Index])
						then
							for (local i = 0; i < MAX_HARDPOINTS; i++)
							then
								GetObjInfo(TempPlayerH, ObjectInfoType(Get_Weapon0Config + i), PlayerPilotWeapons[Index][i]);
								PlayerPilotLocalAmmo[Index][i] = GetCurLocalAmmo(TempPlayerH, i);
							end
						else
							ReplaceWeapons(TempPlayerH, PlayerPilotWeapons[Index], PlayerPilotLocalAmmo[Index]);
							Mission.m_GiveWeaponsBack[Index] = false;
						end
					end

					--[[
				   if(Team == 2)
				   then
					   local tempstr[256] = then0end;
					   sprintf_s(tempstr, "Index: %d Restore Method: %d Recording Player: %s ODF: %s, CurrHealth: %d CurrAmmo: %d", Index, Mission.m_RestorePlayers, PlayerName, PlayerODF, Mission.m_SavedPlayerHealth[Index], Mission.m_SavedPlayerAmmo[Index]);
					   PrintConsoleMessage(tempstr);
				   end
				   -- --]]

				end
			end
		end -- TempPlayerH exists.
	end -- Team Loop.

	-- Empty Ship invulnerability.
	if (Mission.m_PilotInvunerability > 0)
	then
		-- Empty ship invulnerability.
		EmptyShipList.erase(std::remove_if(EmptyShipList.begin(), EmptyShipList.end(), ShouldRemoveEmptyShipObject), EmptyShipList.end());
		-- Empty ship invulnerability.
		for (std::vector<EmptyShipClass>::iterator iter = EmptyShipList.begin(); iter ~= EmptyShipList.end(); ++iter)
		then
			if (iter->InvulnerabilityTime > 0)
				--iter->InvulnerabilityTime;

			if ((iter->InvulnerabilityTime <= 0) or (IsAliveAndPilot2(iter->EmptyShipObject)) or (IsPlayer(iter->EmptyShipObject)))
			then
				if (GetMaxHealth(iter->EmptyShipObject) == 0)
					SetMaxHealth(iter->EmptyShipObject, iter->SavedHealth);
			end
		end
	end

	if ((not TeamPlayOn) or (Mission.m_IsMPI))
		ScavengerManagementCode(); -- Scavenger Management, yay. -GBD

	-- Spawn MPI AI. -GBD
	if (Mission.m_IsMPI) -- or (not IsNetworkOn()))
	then
		if (not Mission.SpawnAI)
		then
			-- Calculate the max number of AI possible, reserve all possible Human slots for Humans.
			local MaxAI_Teams = Mission.m_NumSpawnPoints; -- max 5.
			local PlayerLimit = GetVarItemInt("network.session.ivar2"); -- number of players.
			local Mission.NumCommanders = PlayerLimit; -- Assume everyone is a commander.

			-- Possible addition for Mission.m_IsMPI to switch to determining if 2 teams or 1. For now VSR FFA w/ Teams is limited to standard 1 Team gorup.
			if (TeamPlayOn)
			then
				MaxAI_Teams = Mission.m_NumSpawnPoints - 1; -- Assume 1 team.
			else  -- FFA, count up how many Commanders.
				for (local i = 1; i < PlayerLimit + 1; i++)
				then
					if (Mission.m_ThugFlag[i])
					then
						--Mission.NumCommanders; -- subtract commanders.

					--	FormatConsoleMessage("Subtracting Commander of human team: %d, AI Teams: %d, Mission.NumCommanders: %d", i, MaxAI_Teams, Mission.NumCommanders);

					--	if (Mission.NumCommanders >= Mission.m_NumSpawnPoints)
					--		break; -- Too many counted. abort.
					end
				end
				MaxAI_Teams = Mission.m_NumSpawnPoints - Mission.NumCommanders;
			end
			-- Safety clamp. Total Player + AI Teams cannot be > 15.
			local MaxTeams = (MAX_TEAMS -1) - PlayerLimit; -- Player limit.
			if (MaxAI_Teams > MaxTeams)
				MaxAI_Teams = MaxTeams;
			MaxAI_Teams = clamp(MaxAI_Teams, 0, 5); -- Max 5. Don't allow more or buffer overflow.

		--	FormatConsoleMessage("MaxAI_Teams: %d, NumSpawnPoints: %d", MaxAI_Teams, Mission.m_NumSpawnPoints);

			-- Loop over AI, spawn them as needed.
			for (local i = 0; i < MAX_AI_TEAMS; i++)
			then
				local CPUTeam = 11 + i;

				Handle TempH = 0;
				local PathName[MAX_ODF_LENGTH] = then 0 end;

				if (Mission.m_AIRace[i])
				then
					if (i >= MaxAI_Teams)
					then
						sprintf_s(TempMsgString, "ERROR: CPU %d (Team: %d) spawn skipped: Too many possible Humans (%d) for map Spawns (%d). Reduce Player Limit or number of Commanders.", i + 1, CPUTeam, Mission.NumCommanders, Mission.m_NumSpawnPoints);
						FormatConsoleMessage(TempMsgString);
						AddToMessagesBox2(TempMsgString, RED);
						continue;
					end

					-- Functional Note: This checks svar12 against the HUMAN recycler List. If it doesn't exist there, it falls back to *vrecycpu. -GBD
					local CPURecy[MAX_ODF_LENGTH] = then 0 end;
					const char* pContents = DLLUtils::GetCheckedNetworkSvar(12, NETLIST_Recyclers);
					if ((pContents ~= NULL) and (pContents[0] ~= '\0'))
					then
						strncpy_s(CPURecy, pContents, sizeof(CPURecy) - 1);
					else
						sprintf_s(CPURecy, "%cvrecycpu_vsr", (char)Mission.m_AIRace[i]);
					end

					--look for preplaced CPU recy? -GBD
					TempH = GetObjectByTeamSlot(CPUTeam, DLL_TEAM_SLOT_RECYCLER);
					if (TempH ~= 0)
					then
						local cpuRace = IsRecyclerODF(TempH);
						if (cpuRace ~= 0)
							Mission.m_AIRace[i] = cpuRace;
					else
						sprintf_s(PathName, "Enemy_%d", CPUTeam);
						--local CPURecyODF[MAX_ODF_LENGTH] = then0end;
						--sprintf_s(CPURecyODF, "%cvrecycpu_12svsr", (char)Mission.m_AIRace[i]);
						--TempH = BuildObject(CPURecyODF, CPUTeam, PathName);
						TempH = BuildObject(CPURecy, CPUTeam, PathName);
					end

					if (TempH) -- Did this object exist?
					then
						SetScrap(CPUTeam, 40);
						SetCPUAIPlan(CPUTeam, CPUTeam - 5); -- NOTE: This jurry rigs the AIPs to use the same AIPs as Instant Action (Teams 6 - 15) so that path points match up with the old 10 AI supported system. -GBD

						local AITeamName[MAX_ODF_LENGTH] = then0end;
						sprintf_s(AITeamName, "Computer Team %d", CPUTeam);
						SetTeamNameForStat(CPUTeam, GetBZCCLocalizedString("cfg", AITeamName));

						local Where = GetPosition(TempH);

						-- Look for an _ in there, and copy everything after it into the RecyVariant tag. -GBD
						local TempODF[MAX_ODF_LENGTH] = then 0 end;
						local TempODF2[MAX_ODF_LENGTH] = then 0 end;
						local VariantName[MAX_ODF_LENGTH] = then 0 end;

						--strcpy_s(TempODF, GetInitialRecyclerODF((char)Mission.m_AIRace[i]));
						--strcat_s(TempODF, ".odf"); -- Add .odf to the end.
						CombineStrings(TempODF, CPURecy, ".odf"); --sprintf_s(TempODF, "%s.odf", GetInitialRecyclerODF((char)Mission.m_AIRace[i]));

						if (OpenODF2(TempODF))
						then
							if (GetODFString(TempODF, "GameObjectClass", "classlabel", MAX_ODF_LENGTH, TempODF2)) -- Grab the classlabel.
							then
								CombineStrings(TempODF2, TempODF2, ".odf"); -- Add .odf to the end.
								OpenODF2(TempODF2);
							end
							if (not GetODFString(TempODF, TempODF2, "GameObjectClass", "startingVariant", MAX_ODF_LENGTH, VariantName)) -- Grab the value.
							then
								--[[
								-- Snagged.
							else -- If this ODF is inherited, and try that ODF. If still nothing, then it's nothing.
								if(GetODFString(TempODF, "GameObjectClass", "classlabel", MAX_ODF_LENGTH, TempODF2)) -- Grab the classlabel.
								then
									CombineStrings2(TempODF2, TempODF2, ".odf"); -- Add .odf to the end.

									OpenODF2(TempODF2);
									if(GetODFString(TempODF2, "GameObjectClass", "startingVariant", MAX_ODF_LENGTH, VariantName)) -- Grab the value.
									then
										-- Snagged.
									else -- It didn't find either? Revert to old method.
									--]]
								local *pUnderscore = strchr(CPURecy, '_');
								if (pUnderscore ~= NULL)
								then
									local *pUnderscore2 = strchr(pUnderscore + 1, '_');
									if (pUnderscore2 == NULL)
									then
										-- Only 1 underscore in the name, e.g. (ivrecy_vsr). Copy
										-- everything after it to the Variant Name.
										strcpy_s(VariantName, pUnderscore + 1);
									else
										-- 2 underscores in the name, e.g. (ivrecy_gbd_vsr). Copy
										-- everything after the 2nd Underscore to Variant Name.
										strcpy_s(VariantName, pUnderscore2 + 1);
									end
								end
								--[[
							end
						end
						--]]
							end
						end

						Mission.m_CreatingStartingVehicles = true;
						StartingVehicleManager::CreateVehicles(CPUTeam, (char)Mission.m_AIRace[i], VariantName, Mission.m_StartingVehiclesMask, Where);
						Mission.m_CreatingStartingVehicles = false;

						local TurretODF[MAX_ODF_LENGTH] = then 0 end;
						sprintf_s(TurretODF, "%cvturr%s", (char)Mission.m_AIRace[i], VariantName);

						local GTowODF[MAX_ODF_LENGTH] = then 0 end;
						sprintf_s(GTowODF, "%cbspir%s", (char)Mission.m_AIRace[i], VariantName);

						local ScoutODF[MAX_ODF_LENGTH] = then 0 end;
						sprintf_s(ScoutODF, "%cvscout%s", (char)Mission.m_AIRace[i], VariantName);

						local SentODF[MAX_ODF_LENGTH] = then 0 end;
						sprintf_s(SentODF, "%cvsent%s", (char)Mission.m_AIRace[i], VariantName);

						local TankODF[MAX_ODF_LENGTH] = then 0 end;
						sprintf_s(TankODF, "%cvtank%s", (char)Mission.m_AIRace[i], VariantName);

						local ScavODF[MAX_ODF_LENGTH] = then 0 end;
						sprintf_s(ScavODF, "%cvscav%s", (char)Mission.m_AIRace[i], VariantName);

						-- Build this team's starting stuff. Personally, I think this naming scheme is awful, but I kept the names relatively 
						-- matching Stock for easy compatability and familiarity for map makers. -GBD
						for (local x = 0; x < 5; x++)
						then
							if (x < 1)
								BuildStartingVehicle(CPUTeam, Mission.m_AIRace[i], ScavODF, ScavODF, GetPositionNear(Where, AllyMinRadiusAway, AllyMaxRadiusAway));

							if (x < 2)
								BuildStartingVehicle(CPUTeam, Mission.m_AIRace[i], TurretODF, TurretODF, GetPositionNear(Where, AllyMinRadiusAway, AllyMaxRadiusAway));

							if (Mission.m_CPUForce > 0)
							then
								if (x < 2)
								then
									sprintf_s(PathName, "%dgtow%d", CPUTeam, x + 1);
									BuildStartingVehicle(CPUTeam, Mission.m_AIRace[i], GTowODF, TurretODF, PathName);

									BuildStartingVehicle(CPUTeam, Mission.m_AIRace[i], SentODF, ScoutODF, GetPositionNear(Where, AllyMinRadiusAway, AllyMaxRadiusAway));
								end


								if (Mission.m_CPUForce > 1)
								then
									if (x < 1)
										BuildStartingVehicle(CPUTeam, Mission.m_AIRace[i], SentODF, ScoutODF, GetPositionNear(Where, AllyMinRadiusAway, AllyMaxRadiusAway));

									if (x > 1 and x < 4)
									then
										sprintf_s(PathName, "%dgtow%d", CPUTeam, x + 1);
										BuildStartingVehicle(CPUTeam, Mission.m_AIRace[i], GTowODF, TurretODF, PathName);
									end

									if (x < 3)
										BuildStartingVehicle(CPUTeam, Mission.m_AIRace[i], TankODF, TankODF, GetPositionNear(Where, AllyMinRadiusAway, AllyMaxRadiusAway));
								end
							end
						end

						Mission.m_TeamIsSetUp[CPUTeam] = true;

						--sprintf_s(PathName, "%dturretEnemy1", CPUTeam);
						--sprintf_s(PathName, "%dturretEnemy2", CPUTeam);

						if (Mission.m_CPUForce > 0)
						then

							--sprintf_s(PathName, "%dSentryEnemy1", CPUTeam);
							--sprintf_s(PathName, "%dSentryEnemy2", CPUTeam);
						end
						if (Mission.m_CPUForce > 1)
						then
							--sprintf_s(PathName, "%dtankEnemy1", CPUTeam);
							--sprintf_s(PathName, "%dtankEnemy2", CPUTeam);
							--sprintf_s(PathName, "%dtankEnemy3", CPUTeam);
							--sprintf_s(PathName, "%dSentryEnemy3", CPUTeam);
							--BuildStartingVehicle(CPUTeam, Mission.m_AIRace[i], "*vsent_vsr", "*vscout_vsr", GetPositionNear(Where, AllyMinRadiusAway, AllyMaxRadiusAway));
						end
						--sprintf_s(PathName, "%dScavengerEnemy", CPUTeam);
					else
						Mission.m_AIRace[i] = 0; -- Blank, nothing, no AI spawning here today.
					end
				end
			end
			Mission.SpawnAI = true;
		end

		-- Do AI scrap cheat. -GBD
		local m_NumHumans = CountPlayers();
		for (local i = 1; i < MAX_TEAMS; i++)
		then
			-- Give CPU team bonus scrap based on CPU Force value
			if ((i >= 6) and (Mission.m_CPUForce))
			then
				-- Original:
				-- local CompForceSkew = Mission.m_CPUForce * m_GameTPS;
				-- if(CompForceSkew >= (3 * m_GameTPS))
				--    CompForceSkew = (3 * m_GameTPS) - 2;
				-- local CPUForceTurns = (3 * m_GameTPS) - CompForceSkew;

				-- Cleaned up and TPS-independent:
				-- local Turns = Max(m_GameTPS * (3 - Mission.m_CPUForce), m_GameTPS / 5);

				local Turns, Amount;
				switch (Mission.m_CPUForce)
				then
				default: Turns = 0;             Amount = 0; break;	-- disable
				case 0:  Turns = m_GameTPS * 3; Amount = 1; break;	-- 1 scrap every 3 seconds
				case 1:  Turns = m_GameTPS * 2; Amount = 1; break;	-- 1 scrap every 2 seconds
				case 2:  Turns = m_GameTPS * 1; Amount = 1; break;	-- 1 scrap every second
				case 3:  Turns = m_GameTPS / 5; Amount = 1; break;	-- 1 scrap every 0.2 seconds(not )
				end
				if ((Turns > 0) and (Mission.m_ElapsedGameTime % Turns == 0))
					AddScrap(i, Amount);

				-- Give CPU team bonus scrap based on the number of players
					-- Original:
					-- local Turns = m_GameTPS - m_NumHumans + 1;

					-- TPS-independent:
					-- local Turns = m_GameTPS * (10 - m_NumHumans + 1) / 10;

					--local Turns, Amount;
				switch (m_NumHumans)
				then
				default: Turns = 0;                  Amount = 0; break;	-- disable
				case 1:  Turns = m_GameTPS;          Amount = 1; break;	-- 1 scrap every second
				case 2:  Turns = m_GameTPS * 9 / 10; Amount = 1; break;	-- 1 scrap every 0.9 seconds
				case 3:  Turns = m_GameTPS * 8 / 10; Amount = 1; break;	-- 1 scrap every 0.8 seconds
				case 4:  Turns = m_GameTPS * 7 / 10; Amount = 1; break;	-- 1 scrap every 0.7 seconds
				case 5:  Turns = m_GameTPS * 6 / 10; Amount = 1; break;	-- 1 scrap every 0.6 seconds
				end
				if ((Turns > 0) and (Mission.m_ElapsedGameTime % Turns == 0))
					AddScrap(i, Amount);
			-- Give human team bonus scrap based on Human Force value
			elseif (Mission.m_HumanForce)
			then
				-- Original:
				-- local Turns = (10 * m_GameTPS) - (Mission.m_HumanForce * 20);

				-- Cleaned-up and TPS-independent:
				-- local Turns = m_GameTPS * (10 - Mission.m_HumanForce * 2);

				local Turns, Amount;
				switch (Mission.m_HumanForce)
				then
				default: Turns = 0;              Amount = 0; break;
				case 0:  Turns = m_GameTPS * 10; Amount = 1; break;	-- 1 scrap every 10 seconds
				case 1:  Turns = m_GameTPS * 8;  Amount = 1; break;	-- 1 scrap every 8 seconds
				case 2:  Turns = m_GameTPS * 6;  Amount = 1; break;	-- 1 scrap every 6 seconds
				case 3:  Turns = m_GameTPS * 4;  Amount = 1; break;	-- 1 scrap every 4 seconds
				end
				if ((Turns > 0) and (Mission.m_ElapsedGameTime % Turns == 0))
					AddScrap(i, Amount);
			end
		end
	end

#endif -- #ifndef EDITOR
end

local Strategy02::AddPlayer(DPID id, local Team, local IsNewPlayer)
then
	if (not Mission.m_DidInit)
	then
		Init();
	elseif ((IsNewPlayer) and (Mission.m_IsMPI))
	then
		DoTaunt(TAUNTS_NewHuman);
	end

	if (IsNewPlayer)
	then
		Handle PlayerH = SetupPlayer(Team);
		SetAsUser(PlayerH, Team);
		AddPilotByHandle(PlayerH);
	end

	return 1; -- BOGUS: always assume successful
end

void Strategy02::DeletePlayer(DPID id)
then
	if (Mission.m_IsMPI)
		DoTaunt(TAUNTS_LeftHuman);
end

-- Rebuilds pilot
EjectKillRetCodes Strategy02::RespawnPilot(Handle DeadObjectHandle, local Team)
then

	local spawnpointPosition = Vector(0, 0, 0);

	-- Only use safest place if invalid team #
	if ((Team < 1) or (Team >= MAX_TEAMS))
	then
		spawnpointPosition = GetSafestSpawnpoint();
	else
		-- Use last noted position for the team
		spawnpointPosition.x = Mission.m_TeamPos[3 * Team + 0];
		spawnpointPosition.y = Mission.m_TeamPos[3 * Team + 1];
		spawnpointPosition.z = Mission.m_TeamPos[3 * Team + 2];
		Mission.m_SpawnedAtTime[Team] = Mission.m_ElapsedGameTime; -- Note when they spawned in.
	end

	local OldPos;
	-- As this object was just killed, gotta use the slower search for its
	-- position.
	GetPosition2(DeadObjectHandle, OldPos);

	-- Find out how far we are away from starting location... use
	-- default if couldn't get position of DeadObjectHandle
	local respawnHeight = RespawnPilotHeight;
	if ((fabsf(OldPos.x) > 0.01f) and (fabsf(OldPos.z) > 0.01f))
	then
		-- Position valid. Use it.
		local dx = OldPos.x - spawnpointPosition.x;
		local dz = OldPos.z - spawnpointPosition.z;
		-- How far this person died from where we'll respawn them
		local distanceAway = sqrtf((dx * dx) + (dz * dz));
		if (distanceAway < 100.f)
		then
			respawnHeight = 35.; -- 1.2 used 25.f here
		else
			-- Min of 40, max varies by # of allies. More penalty for
			-- dying far away from your team
			local numAllies = DLLUtils::CountAlliedPlayers(Team);
			respawnHeight = 30.f + (sqrtf(distanceAway) * 1.25f);
			local minRespawnHeight = 40.0;
			local maxRespawnHeight = 70.0f + (15.0f * numAllies);

			if (respawnHeight < minRespawnHeight)
			then
				respawnHeight = minRespawnHeight;
			elseif (respawnHeight > maxRespawnHeight)
			then
				respawnHeight = maxRespawnHeight;
			end
		end
	end
	if (Mission.m_RespawnAtLowAltitude)
		respawnHeight = 2.0;

	-- Randomize starting position somewhat. This gives a range of +/-
	-- RespawnDistanceAwayXZRange
	spawnpointPosition.x += (GetRandomFloat(1.f) - 0.5f) * (2.f * RespawnDistanceAwayXZRange);
	spawnpointPosition.z += (GetRandomFloat(1.f) - 0.5f) * (2.f * RespawnDistanceAwayXZRange);

	-- Don't allow a spawn underground - just in case there's a cliff
	-- near the starting spawnpointPosition position, we need to keep y above the
	-- ground.
	then
		local curFloor = TerrainFindFloor(spawnpointPosition.x, spawnpointPosition.z) + 2.5;
		if (spawnpointPosition.y < curFloor)
		then
			spawnpointPosition.y = curFloor;
		end
	end
	spawnpointPosition.y += respawnHeight; -- Bounce them in the air to prevent multi-kills
	spawnpointPosition.y += GetRandomFloat(1.f) * RespawnDistanceAwayYRange;

	Handle NewPerson = BuildObject(GetInitialPlayerPilotODF(GetRaceOfTeam(Team), Team), Team, spawnpointPosition);

	-- Pilot invulnerability. -GBD
	if (Mission.m_PilotInvunerability > 0)
	then
		Mission.m_PilotInvTime[Team] = Mission.m_PilotInvunerability; -- Set the timer to the time set. 
		Mission.m_SavedPilotInvHealth[Team] = GetMaxHealth(NewPerson);
		Mission.m_PilotInvUser[Team] = NewPerson;
		SetMaxHealth(NewPerson, 0);
	end

	SetAsUser(NewPerson, Team);
	AddPilotByHandle(NewPerson);
	SetRandomHeadingAngle(NewPerson);

	-- If on team 0 (dedicated server team), make this object gone from the world
	if (not Team)
		MakeInert(NewPerson);

	return DLLHandled; -- Dead pilots get handled by DLL
end

-- Helper function for ObjectKilled/Sniped
EjectKillRetCodes Strategy02::DeadObject(local DeadObjectHandle, local KillersHandle, local isDeadPerson, local isDeadAI)
then
	if (not Mission.StopScript)
		LuaMission::DeadObject(DeadObjectHandle);

	-- Get team number of the dead object
	local deadObjectTeam = GetTeamNum(DeadObjectHandle);

	-- An object is a player if it's a local or remotely-controlled player
	-- (i.e. not AI)
	const local deadObjectIsPlayer = IsPlayer(DeadObjectHandle);
	const local killerObjectIsPlayer = IsPlayer(KillersHandle);

	const TEAMRELATIONSHIP relationship = GetTeamRelationship(DeadObjectHandle, KillersHandle);

	local deadObjectScrapCost = GetActualScrapCost(DeadObjectHandle);

	-- Jira 2445: Don't count score/kills/deaths for Team 0 (props). -GBD
	if (deadObjectTeam ~= 0)
	then
		-- If the dead unit is directly controlled by a player (i.e. not
		-- one of their AI units)
		if (deadObjectIsPlayer)
		then
			-- Score goes down by the scrap cost of unit that died
			if (Mission.m_GameType ~= 4)
				AddScore(DeadObjectHandle, -(int)(floor((float)deadObjectScrapCost / 20.0f)));

			-- Scoring: One death for players if they die as a pilot.
			if (isDeadPerson)
			then
				AddDeaths(DeadObjectHandle, 1);
			end
		else
			if (Mission.m_KillForAIKill)
				AddDeaths(DeadObjectHandle, 1);
			if ((Mission.m_PointsForAIKill) and (Mission.m_GameType ~= 4))
				AddScore(DeadObjectHandle, -(int)(floor((float)deadObjectScrapCost / 20.0f)));
		end

		-- If the killer was a human (directly, not via their AI units), then
		-- they get a kill and some score points.
		if (killerObjectIsPlayer)
		then
			if ((relationship == TEAMRELATIONSHIP_SAMETEAM) or
				(relationship == TEAMRELATIONSHIP_ALLIEDTEAM))
			then
				-- Being a jerk to same or allied team loses a kill
				AddKills(KillersHandle, -1);
				-- And killer loses score
				if (Mission.m_GameType ~= 4)
					AddScore(KillersHandle, -(int)(floor((float)deadObjectScrapCost / 10.0f)));
			else
				AddKills(KillersHandle, 1);
				-- And, bump their score by the scrap cost of what they just killed
				if (Mission.m_GameType ~= 4)
					AddScore(KillersHandle, (int)(floor((float)deadObjectScrapCost / 10.0f)));
			end
		else
			if ((relationship == TEAMRELATIONSHIP_SAMETEAM) or
				(relationship == TEAMRELATIONSHIP_ALLIEDTEAM))
			then
				if (Mission.m_KillForAIKill)
					AddKills(KillersHandle, -1);
				if ((Mission.m_PointsForAIKill) and (Mission.m_GameType ~= 4))
					AddScore(KillersHandle, -(int)(floor((float)deadObjectScrapCost / 10.0f)));
			else
				if (Mission.m_KillForAIKill)
					AddKills(KillersHandle, 1);
				if ((Mission.m_PointsForAIKill) and (Mission.m_GameType ~= 4))
					AddScore(KillersHandle, (int)(floor((float)deadObjectScrapCost / 10.0f)));
			end
		end

		-- Was this a spawn kill?
		-- Spawnkill is a non-suicide, on a human by another human.  Added
		-- check for not isDeadAI NM 11/25/06 - APC soldiers dying around the
		-- same time as their human player would trip this up.
		local spawnKillTime = MaxSpawnKillTime * m_GameTPS; -- 15 seconds
		const local isSpawnKill = (DeadObjectHandle ~= KillersHandle) and
			(not isDeadAI) and
			(deadObjectTeam > 0) and (deadObjectTeam < MAX_TEAMS) and
			(Mission.m_SpawnedAtTime[deadObjectTeam] > 0) and
			((Mission.m_ElapsedGameTime - Mission.m_SpawnedAtTime[deadObjectTeam]) < spawnKillTime);

		-- If this was a spawnkill, register that on the killers score
		if (isSpawnKill)
		then
			sprintf_s(TempMsgString, "Spawn kill by %s on %s\n",
				GetPlayerName(KillersHandle), GetPlayerName(DeadObjectHandle));
			AddToMessagesBox(TempMsgString);
			AddScore(KillersHandle, -ScoreDecrementForSpawnKill);
		end

		-- Check to see if we have a Mission.m_KillLimit winner
		if ((Mission.m_KillLimit) and (GetKills(KillersHandle) >= Mission.m_KillLimit))
		then
			NoteGameoverByKillLimit(KillersHandle);
			DoGameover(10.0f);
		end
	else
		return DoEjectPilot; -- Someone on neutral team always gets default behavior
	end

	if (isDeadAI)
	then
		-- Snipe?
		if (isDeadPerson)
		then
			return DLLHandled;
		else -- Nope. Eject.
			return DoEjectPilot;
		end
	else  -- Not DeadAI, i.e. a humannot 
		if ((Mission.m_IsMPI) and (deadObjectTeam > 0) and (deadObjectTeam < 11))
			DoTaunt(TAUNTS_HumanShipDestroyed);

		-- If this was a dead pilot, we need to build another pilot back
		-- at base. Otherwise, we just eject a pilot from the
		-- craft. [This is strat, nobody gets a craft for free when they
		-- lose one.]
		if (isDeadPerson)
		then
			return RespawnPilot(DeadObjectHandle, deadObjectTeam);
		else
			return DoEjectPilot;
		end
	end
end

EjectKillRetCodes Strategy02::PlayerEjected(Handle DeadObjectHandle)
then
	EjectKillRetCodes ret = DLLHandled;
	if (not Mission.StopScript)
		ret = LuaMission::PlayerEjected(DeadObjectHandle);

	local deadObjectTeam = GetTeamNum(DeadObjectHandle);
	if (deadObjectTeam == 0)
	then
		return DLLHandled; -- Invalid team. Do nothing
	end

	-- Tweaked scoring - if a player bails out, no deaths/kills are
	-- registered.  But, their score should go down by the scrap cost
	-- of the vehicle they just left.
	if (IsPlayer(DeadObjectHandle))
	then
		AddScore(DeadObjectHandle, -GetActualScrapCost(DeadObjectHandle));
	end

	return DoEjectPilot; -- Tell main code to allow the ejection
end

EjectKillRetCodes Strategy02::ObjectKilled(local DeadObjectHandle, local KillersHandle)
then
	if (not Mission.StopScript)
		return LuaMission::ObjectKilled(DeadObjectHandle, KillersHandle);

	const local isDeadAI = not IsPlayer(DeadObjectHandle);
	const local isDeadPerson = IsPerson(DeadObjectHandle);

	-- Sanity check for multiworld
	if (GetCurWorld() ~= 0)
	then
		return DoEjectPilot;
	end

	local deadObjectTeam = GetTeamNum(DeadObjectHandle);
	if (deadObjectTeam == 0)
	then
		return DoEjectPilot; -- Someone on neutral team always gets default behavior
	end

	-- If a person died, respawn them, etc
	return DeadObject(DeadObjectHandle, KillersHandle, isDeadPerson, isDeadAI);
end


EjectKillRetCodes Strategy02::ObjectSniped(local DeadObjectHandle, local KillersHandle)
then
	if (not Mission.StopScript)
		return LuaMission::ObjectSniped(DeadObjectHandle, KillersHandle);

	local isDeadAI = not IsPlayer(DeadObjectHandle);

	if (GetCurWorld() ~= 0)
	then
		return DLLHandled;
	end

	-- Dead person means we must always respawn a new person
	return DeadObject(DeadObjectHandle, KillersHandle, true, isDeadAI);
end

-- Moved to BZ1Helper. -GBD
-- Notification to the DLL: a sniper shell has hit a piloted
-- craft. The exe passes the current world, shooters handle, victim
-- handle, and the ODF string of the ordnance involved in the
-- snipe. Returns a code detailing what to do.
--
-- not not  Note : If DLLs want to do any actions to the world based on this
-- PreSnipe callback, they should (1) Ensure curWorld == 0 (lockstep)
-- -- do NOTHING if curWorld is ~= 0, and (2) probably queue up an
-- action to do in the next Execute() call.
--[[
PreSnipeReturnCodes Strategy02::PreSnipe(local curWorld, Handle shooterHandle, Handle victimHandle, local ordnanceTeam, const char* pOrdnanceODF)
then
	-- Default value.
	PreSnipeReturnCodes returnvalue = PRESNIPE_KILLPILOT;

	--and this -GBD
	if (not Mission.StopScript)
		returnvalue = LuaMission::PreSnipe(curWorld, shooterHandle, victimHandle, ordnanceTeam, pOrdnanceODF);

	-- If Friendly Fire is off, then see if we should disallow the snipe
	if (not Mission.m_bIsFriendlyFireOn)
	then
		const TEAMRELATIONSHIP relationship = GetTeamRelationship(shooterHandle, victimHandle);
		if (--(relationship == TEAMRELATIONSHIP_SAMETEAM) or -- Allow same Team. -GBD
			(relationship == TEAMRELATIONSHIP_ALLIEDTEAM))
		then
			-- Allow snipes of items on team 0/perceived team 0, as long
			-- as they're not a local/remote player
			if (IsPlayer(victimHandle) or GetTeamNum(victimHandle) ~= 0)
			then
				return PRESNIPE_ONLYBULLETHIT;
			end
		end
		-- Friendly fire is off, and we're about to kill the pilot of the hit object.
		-- Set its team to 0
		SetPerceivedTeam(victimHandle, 0);
	end

	-- If we got here, allow the pilot to be killed
	return PRESNIPE_KILLPILOT;
end
--]]

-- Notification to the DLL: called when a pilot tries to enter an
-- empty craft, and all other checks (i.e. craft is empty, masks
-- match, etc) have passed. DLLs can prevent that pilot from entering
-- the craft if desired.
--
-- not not  Note : If DLLs want to do any actions to the world based on this
-- PreGetIn callback, they should (1) Ensure curWorld == 0 (lockstep)
-- -- do NOTHING if curWorld is ~= 0, and (2) probably queue up an
-- action to do in the next Execute() call.
PreGetInReturnCodes Strategy02::PreGetIn(local curWorld, Handle pilotHandle, Handle emptyCraftHandle)
then
	if (curWorld)
	then
		return PREGETIN_ALLOW;
	end

	--and this -GBD
	PreGetInReturnCodes RetVal = LuaMission::PreGetIn(curWorld, pilotHandle, emptyCraftHandle);

	-- Is this an AI pilot getting into an allied craft? If so, change
	-- the pilot's team to be the same as the craft, so that the craft
	-- remains with its owning team. If a local or remotely-controlled
	-- player tries to get in, behave as before.
	local relationship = GetTeamRelationship(pilotHandle, emptyCraftHandle);
	if ((relationship == TEAMRELATIONSHIP_ALLIEDTEAM) and
		(not IsPlayer(pilotHandle)) and (not Mission.m_SetThugPilotFlag))
	then
		SetTeamNum(pilotHandle, GetTeamNum(emptyCraftHandle));
	end

	-- Added to stop invulnerability if the target gets inside a vehicle. -GBD
	if (Mission.m_PilotInvUser[GetTeamNum(pilotHandle)] == pilotHandle)
	then
		SetMaxHealth(pilotHandle, Mission.m_SavedPilotInvHealth[GetTeamNum(pilotHandle)]);
		Mission.m_PilotInvTime[GetTeamNum(pilotHandle)] = 0;
	end

	if((RetVal == PREGETIN_ALLOW) and (Mission.m_IsMPI) and GetTeamNum(emptyCraftHandle) > 10)
		AddToDispatch(emptyCraftHandle, 15.0f, false, 0, false); -- Tie into DispatchHelper. -GBD

	-- Always allow the entry
	return RetVal; --PREGETIN_ALLOW;
end

-- Scavenger. Handles swapping Team from Thug to Commander when it deploys into a pool.
void Strategy02::ScavengerManagementCode(void)
then
	--local Logging = false;
	--local tempstr[256];

	--[[ -- Temp Buggery. -GBD
	if((Mission.m_IsMPI) and (IsTeamplayOn())) -- Before we nuke the list of deployed Extractors, do Team Swapping if IsTeamPlayOn() on AI Teams.
	then
		for (std::vector<ThugScavengerClass>::iterator iter = ThugScavengerList.begin(); iter ~= ThugScavengerList.end(); ++iter)
		then
			-- This is before our clean up, make sure it's still around first.
			if(IsAround(iter->ThugScavengerObject))
			then
				local Team = GetTeamNum(iter->ThugScavengerObject);

				if((Team == 6) and (iter->ScavengerTeam > 6) and (iter->ScavengerTeam < 11)) -- This is an AI Team on "TeamPlay" Team 2.
				then
					local ObjClass[MAX_ODF_LENGTH] = then0end;
					GetObjInfo(iter->ThugScavengerObject, Get_GOClass, ObjClass);

					-- This deployed, it automatically switched to Team 6. Swap it back.
					if((Team ~= iter->ScavengerTeam) and (_stricmp(ObjClass, "CLASS_EXTRACTOR") == 0) or (_stricmp(ObjClass, "CLASS_SILO") == 0))
					then
						-- Get ScrapHold value.
						local TempHold = 0;
						local TempODF[MAX_ODF_LENGTH] = then0end;
						local TempODF2[MAX_ODF_LENGTH] = then0end;
						GetObjInfo(iter->ThugScavengerObject, Get_ODF, TempODF);

						if (OpenODF2(TempODF))
						then
							-- Grab out the next ODF, if present.
							GetODFString(TempODF, "GameObjectClass", "classlabel", MAX_ODF_LENGTH, TempODF2); -- Grab the sound file, with allowance for a large filename.
							CombineStrings2(TempODF2, TempODF2, ".odf"); -- Add .odf to the end.

							while ((_stricmp(TempODF, TempODF2) ~= 0) and
								(not GetODFInt(TempODF, "ExtractorClass", "scrapHold", &TempHold)) and
								(not GetODFInt(TempODF, "SiloClass", "scrapHold", &TempHold)) and
								(OpenODF2(TempODF2))) -- Go all the way until you can't go any further.
							then
								strcpy_s(TempODF, TempODF2); -- Copy TempODF2 into TempODF, then re-grab TempODF2 to try again.
								GetODFString(TempODF, "GameObjectClass", "classlabel", MAX_ODF_LENGTH, TempODF2); -- Grab the sound file, with allowance for a large filename.
								CombineStrings2(TempODF2, TempODF2, ".odf"); -- Add .odf to the end.
							end
						end

						local TempMaxTeam = GetMaxScrap(Team);
						local TempMaxScav = GetMaxScrap(iter->ScavengerTeam);

						SetTeamNum(iter->ThugScavengerObject, iter->ScavengerTeam); -- Set it to the correct Team.
						-- Correct scraphold.
						AddMaxScrap(iter->ScavengerTeam, TempHold);
						AddMaxScrap(Team, -TempHold);
						AddScrap(iter->ScavengerTeam, iter->ScavCurrScrap); -- Fill er up.

						-- Lets log how much scrap to see if we need to mess with that manually.
						sprintf_s(TempMsgString, "SWITCHING SCAV Team: %d to Team: %d. OldMax: %d, %d NewMax: %d, %d, Curr: %d, %d", Team, iter->ScavengerTeam, TempMaxTeam, TempMaxScav, GetMaxScrap(Team), GetMaxScrap(iter->ScavengerTeam), GetScrap(Team), GetScrap(iter->ScavengerTeam));
						PrintConsoleMessage(TempMsgString);

					end
				end
			end
		end
	end
	--]]

	ThugScavengerList.erase(std::remove_if(ThugScavengerList.begin(), ThugScavengerList.end(), ShouldRemoveThugScavengerObject), ThugScavengerList.end());

	for (std::vector<ThugScavengerClass>::iterator iter = ThugScavengerList.begin(); iter ~= ThugScavengerList.end(); ++iter)
	then
		local Team = GetTeamNum(iter->ThugScavengerObject);
		--iter->ScavCurrScrap = GetScavengerCurScrap(iter->ThugScavengerObject);
		-- First off, is this a commander's team?
		if ((not Mission.m_ThugFlag[Team]) and (iter->ScavengerTeam ~= Team))
		then
			iter->ScavengerTeam = Team;

			--	sprintf_s(TempMsgString, "Set Scavenger on Team: %d Index: %d as Commadner Team", Team, iter-ThugScavengerList.begin());
			--	PrintConsoleMessage(TempMsgString);
		elseif (not IsTeamplayOn()) --if (not Mission.m_IsMPI)-- Thug team, handle scrap swapping.
			local ScavScrap = GetScavengerCurScrap(iter->ThugScavengerObject);

			if (ScavScrap > 0)
			then
				local CurrScrap = GetScrap(iter->ScavengerTeam);
				local MaxScrap = GetMaxScrap(iter->ScavengerTeam);

				--	if(Logging)
				--		FormatConsoleMessage("Scrap Info for Scavenger on Team: %d Index: %d: ScavScrap: %d CurrScrap: %d MaxScrap: %d", Team, iter-ThugScavengerList.begin(), ScavScrap, CurrScrap, MaxScrap); 

				if ((CurrScrap + ScavScrap) > MaxScrap)
				then
					local TempCurrScrap = (MaxScrap - CurrScrap);
					local TempScavScrap = (ScavScrap - TempCurrScrap);

					AddScrap(iter->ScavengerTeam, TempCurrScrap);
					SetScavengerCurScrap(iter->ThugScavengerObject, TempScavScrap);

					--	sprintf_s(TempMsgString, "Scav Moving Scrap %d from Team: %d to Team: %d, Scrap: %d, %d", TempCurrScrap, Team, iter->ScavengerTeam, GetScrap(Team), GetScrap(iter->ScavengerTeam));
					--	PrintConsoleMessage(TempMsgString);
				else
					AddScrap(iter->ScavengerTeam, ScavScrap);
					SetScavengerCurScrap(iter->ThugScavengerObject, 0);
					--iter->ScavCurrScrap = 0; -- Clear this too.

				--	sprintf_s(TempMsgString, "Scav Moving Scrap %d from Team: %d to Team: %d, Scrap: %d, %d", ScavScrap, Team, iter->ScavengerTeam, GetScrap(Team), GetScrap(iter->ScavengerTeam));
				--	PrintConsoleMessage(TempMsgString);
				end
			end

			if ((Team ~= iter->ScavengerTeam) and (IsDeployed(iter->ThugScavengerObject))) then
				SetTeamNum(iter->ThugScavengerObject, iter->ScavengerTeam);
			end
		end
	end

	ThugPilotList.erase(std::remove_if(ThugPilotList.begin(), ThugPilotList.end(), ShouldRemoveThugPilotObject), ThugPilotList.end());

	-- Loop over Thug Pilots.
	for (std::vector<ThugPilotClass>::iterator iter = ThugPilotList.begin(); iter ~= ThugPilotList.end(); ++iter)
	then
		local Team = GetTeamNum(iter->ThugPilotObject);

		if ((Mission.m_ThugFlag[Team]) and (iter->SwitchTickTimer <= 0))
		then
			local TempCommanderTeam = 1;
			for (local x = 1; x < MAX_TEAMS; x++)
			then
				if ((Mission.m_AllyTeams[Team] == Mission.m_AllyTeams[x]) and (not Mission.m_ThugFlag[x]))
					TempCommanderTeam = x;
			end

			if (Team ~= TempCommanderTeam)
				SetTeamNum(iter->ThugPilotObject, TempCommanderTeam);
		end
		--iter->SwitchTickTimer;
	end
end

void Strategy02::ExecuteST_Capture(void)
then
	local Winner = false; -- Assume so for now. 

--	local tempstr[256];

	-- Loop over all teams, checking their scrap. Start at Team 1. 
	for (local i = 1; i < MAX_TEAMS; i++)
	then
		Mission.UserTarget[i] = GetMission.UserTarget(i);

		if (Mission.m_NumCaptureGoals > 0)
		then
			for (local x = 0; x < Mission.m_NumCaptureGoals; x++)
			then
				local ODFName[MAX_ODF_LENGTH];
				GetObjInfo(Mission.m_CaptureGoals[x], Get_ODF, ODFName);

				if (IsAround(Mission.m_CaptureGoals[x]))
				then
					SetObjectiveOn(Mission.m_CaptureGoals[x]);
				else
					--PrintConsoleMessage("CaptureGoal is not around");
					-- Now, delete out the i'th entry of this list
					local j;
					for (j = x; j < (Mission.m_NumCaptureGoals - 1); ++j)
					then
						Mission.m_CaptureGoals[j] = Mission.m_CaptureGoals[j + 1];
						Mission.m_CaptureGoalTime[j] = Mission.m_CaptureGoalTime[j + 1];
						Mission.m_CaptureGoalTeam[j] = Mission.m_CaptureGoalTeam[j + 1];
						Mission.m_GoalBeingCaptured[j] = Mission.m_GoalBeingCaptured[j + 1];
						Mission.m_CaptureGoalObjectify[j] = Mission.m_CaptureGoalObjectify[j + 1];
						Mission.m_CaptureGoalIsSwitching[i][j] = Mission.m_CaptureGoalIsSwitching[i][j + 1];
						Mission.m_DualCapture[j] = Mission.m_DualCapture[j + 1];
					end
					--x; -- back up, so we don't skip an object this pass
					--Mission.m_NumCaptureGoals; -- we deleted an entry
				end

				if (IsAround(Mission.m_CaptureGoals[x]))
				then
					Handle TempP = GetPlayerHandle(i);
					local Flagoff = false;

					for (local t = 1; t < MAX_TEAMS; t++)
					then
						Handle TempP2 = GetPlayerHandle(t);
						if ((t ~= i) and (not IsTeamAllied(i, t)) and (Mission.UserTarget[i] == Mission.m_CaptureGoals[x]) and (Mission.UserTarget[t] == Mission.m_CaptureGoals[x]) and (GetDistance(Mission.m_CaptureGoals[x], TempP) < 100) and (GetDistance(Mission.m_CaptureGoals[x], TempP2) < 100))
						then
							-- Restore it to it's previous Team.
							SetTeamNum(Mission.m_CaptureGoals[x], Mission.m_CaptureGoalTeam[x]);
							Flagoff = true;
							break;
						end
					end
					if ((Flagoff) and (not Mission.m_DualCapture[x]))
					then
						Mission.m_DualCapture[x] = true;
					end
					if (not Flagoff)
						Mission.m_DualCapture[x] = false;

					-- If this object is being targeted, and isn't already captured, start capture procedures. 
					if ((Mission.UserTarget[i] == Mission.m_CaptureGoals[x]) and (Mission.m_CaptureGoalTeam[x] ~= i) and ((Mission.m_CaptureGoalTeam[x] == 0) or (not IsTeamAllied(Mission.m_CaptureGoalTeam[x], i))) and ((Mission.m_GoalBeingCaptured[x] == 0) or (Mission.m_GoalBeingCaptured[x] == i)) and (GetDistance(Mission.m_CaptureGoals[x], TempP) < 100))
					then
						if (Mission.m_GoalBeingCaptured[x] == 0)
						then
							sprintf_s(TempMsgString, "-- A Goal is being Captured by %snot ", GetPlayerName(GetPlayerHandle(i)));
							AddToMessagesBox2(TempMsgString, RGB_MAKE(255, 255, 0));
						end

						Mission.m_CaptureGoalIsSwitching[i][x] = true;

						if (not Mission.m_DualCapture[x])
							Mission.m_CaptureGoalTime[x]++; -- Add 1.

						Mission.m_GoalBeingCaptured[x] = i;
						Mission.m_TeamIsCapturing[i] = true;

						--	sprintf_s(tempstr, "Time is %d", Mission.m_CaptureGoalTime[x]); 
						--	PrintConsoleMessage(tempstr);

						local TotalCaptureTime = ((Mission.m_CaptureTime - Mission.m_CaptureGoalTime[x]) / m_GameTPS);

						if (GetLocalPlayerTeamNumber() == i)
							StartCockpitTimer(TotalCaptureTime, int(floor(TotalCaptureTime / 2)), int(floor(TotalCaptureTime / 4)));

						if ((Mission.m_CaptureGoalTime[x] % (1 * m_GameTPS)) == 0) -- Every 1 seconds?
						then
							if (not Mission.m_CaptureGoalObjectify[x])
							then
								SetTeamNum(Mission.m_CaptureGoals[x], i);
								SetObjectiveOn(Mission.m_CaptureGoals[x]);
								Mission.m_CaptureGoalObjectify[x] = true;
							else
								SetTeamNum(Mission.m_CaptureGoals[x], Mission.m_CaptureGoalTeam[x]);
								SetObjectiveOff(Mission.m_CaptureGoals[x]);
								Mission.m_CaptureGoalObjectify[x] = false;
							end
						end

						if (Mission.m_CaptureGoalTime[x] == (Mission.m_CaptureTime))
						then
							if (Mission.m_CaptureGoalTeam[x] ~= 0) -- If this used to belong to somebody.
								AddScore(GetPlayerHandle(Mission.m_CaptureGoalTeam[x]), -1); -- Take a score away, they lost it.

							Handle OldPlayer = GetPlayerHandle(Mission.m_CaptureGoalTeam[x]);

							Mission.m_CaptureGoalTeam[x] = i; -- You got it. 
							SetTeamNum(Mission.m_CaptureGoals[x], i); -- Set it's team.
							for (local v = 0; v < 8; v++)
							then
								Handle TempTap = GetTap(Mission.m_CaptureGoals[x], v);
								if (TempTap)
									SetTeamNum(TempTap, i);
							end
							AddScore(GetPlayerHandle(i), 1); -- 1 up.
							Mission.m_GoalBeingCaptured[x] = 0;

							if (GetLocalPlayerTeamNumber() == i)
							then
								StopCockpitTimer();
								HideCockpitTimer();
							end

							SetObjectiveOff(Mission.m_CaptureGoals[x]);
							Mission.m_CaptureGoalTime[x] = 0;
							Mission.m_CaptureGoalIsSwitching[i][x] = false;
							Mission.m_TeamIsCapturing[i] = false;

							if (OldPlayer)
							then
								sprintf_s(TempMsgString, "-- %s Captured a Goal from %snot ", GetPlayerName(GetPlayerHandle(i)), GetPlayerName(OldPlayer));
							else
								sprintf_s(TempMsgString, "-- %s Captured a Goalnot ", GetPlayerName(GetPlayerHandle(i)));
							end

							AddToMessagesBox2(TempMsgString, RGB_MAKE(255, 255, 0));
						end

						break;
					elseif (Mission.m_CaptureGoalIsSwitching[i][x]) -- This object is not being captured. 
					then
						Mission.m_CaptureGoalTime[x] = 0;
						Mission.m_GoalBeingCaptured[x] = 0;
						SetTeamNum(Mission.m_CaptureGoals[x], Mission.m_CaptureGoalTeam[x]);

						if (GetLocalPlayerTeamNumber() == i)
						then
							StopCockpitTimer();
							HideCockpitTimer();
						end

						if (Mission.UserTarget[i] == Mission.m_CaptureGoals[x])
							SetTarget(GetPlayerHandle(i), 0); -- Clear out this user's target if they're trying to target the object from too far away.

						Mission.m_CaptureGoalIsSwitching[i][x] = false;
						Mission.m_TeamIsCapturing[i] = false;

						--		sprintf_s(tempstr, "Set Capture goal %d to Team %d for Team %d", x, Mission.m_CaptureGoalTeam[x], i); 
						--		PrintConsoleMessage(tempstr);
					end
				end -- It's around.
			end -- loop over all objects.

			-- Look for a winner.
			if (Mission.m_KillLimit)
			then
				if (GetScore(GetPlayerHandle(i)) >= Mission.m_KillLimit)
					Winner = true;
			else
				Winner = true; -- Assume so for now...
				-- See if our Team has captured all the goals.
				for (local t = 0; t < Mission.m_NumCaptureGoals; t++)
				then
					if ( --(iter->CaptureTime > 0) and 
						(Mission.m_GoalBeingCaptured[t]) or --(iter->IsSwitching[i]) or -- This item is currently being Captured.
						(Mission.m_CaptureGoalTeam[t] == 0) or -- This one is still on Team 0.
						((Mission.m_CaptureGoalTeam[t] ~= i) or (not IsTeamAllied(i, Mission.m_CaptureGoalTeam[t])))) -- This one isn't yours, or this item isn't allied to you.
					then
						Winner = false;
						break;
					end
				end
			end

			-- We have a winner.
			if ((Winner) and (not Mission.m_GameOver))
			then
				-- In teamplay, report the team as the winner
				if (IsTeamplayOn())
				then
					local WinningTeamgroup = WhichTeamGroup(i);

					if (Mission.m_KillLimit)
					then
						sprintf_s(TempMsgString, "-- Team %d has wonnot  Captured %d Goalsnot ", WinningTeamgroup + 1, Mission.m_KillLimit); -- Tell which Team wonnot  -GBD
					else
						sprintf_s(TempMsgString, "-- Team %d has wonnot  Captured all Goalsnot ", WinningTeamgroup + 1); -- Tell which Team wonnot  -GBD
					end
					AddScore(GetPlayerHandle(i), ScoreForWinning);
					NoteGameoverWithCustomMessage(TempMsgString);

					-- Also, give all players on winning team points...
					for (local k = 0; k < MAX_TEAMS; k++)
					then
						if (WhichTeamGroup(k) == WinningTeamgroup)
							AddScore(GetPlayerHandle(k), ScoreForWinning);
					end

					AddToMessagesBox2(TempMsgString, RGB_MAKE(255, 255, 0));
					DoGameover(10.0f);
					Mission.m_GameOver = true;
				-- Teamplay is on
				else -- Non-teamplay, report individual winner
					if (Mission.m_HasAllies[i])
					then
						if (Mission.m_KillLimit)
						then
							sprintf_s(TempMsgString, "-- Team %d has wonnot  Captured %d Goalsnot ", Mission.m_AllyTeams[i], Mission.m_KillLimit); -- Tell which Team wonnot  -GBD
						else
							sprintf_s(TempMsgString, "-- Team %d has wonnot  Captured All Goalsnot ", Mission.m_AllyTeams[i]); -- Tell which Team wonnot  -GBD
						end
						AddScore(GetPlayerHandle(i), ScoreForWinning);
						NoteGameoverWithCustomMessage(TempMsgString);
					else
						if (Mission.m_KillLimit)
						then
							sprintf_s(TempMsgString, "-- %s has wonnot  Captured %d Goalsnot ", GetPlayerName(Mission.m_RecyclerHandles[i]), Mission.m_KillLimit); -- Tell who wonnot  -GBD
						else
							sprintf_s(TempMsgString, "-- %s has wonnot  Captured All Goalsnot ", GetPlayerName(Mission.m_RecyclerHandles[i])); -- Tell who wonnot  -GBD
						end
						AddScore(GetPlayerHandle(i), ScoreForWinning);
						NoteGameoverByScore(GetPlayerHandle(i));
					end
					AddToMessagesBox2(TempMsgString, RGB_MAKE(255, 255, 0));
					DoGameover(10.0f);
					Mission.m_GameOver = true;
				end
			end -- Winner. 
		-- capture goals > 0.
		else
			if (not Mission.m_GameOver)
			then
				AddToMessagesBox2("-- No Capture Goalsnot  Game will be over very soonnot ", RGB_MAKE(255, 255, 0));
				DoGameover(10.0f);
				Mission.m_GameOver = true;
			end
		end
	end -- Loop over teams. 
end