// PROVENANCE: ancestor reference/ancestor-1.3/Missions/LuaMission/LuaMission.cpp @353698f (the Lua state setup, the metatables, the script callbacks, the Load / Save value streams) | decompile reference/decompiled/luamission-ghidra12.2/src/missions/luamission/luamission.cpp.decomp.c (ctor 13-32, dtor 35-42, BuildMission 47-49, Setup 53-73, InitialSetup 76-285, Load 288-350, PostLoad 353-363, Save 366-413, PreOrdnanceHit 416-439, PreGetIn 442-482, PreSnipe 484-525, PrePickupPowerup 528-567, PostTargetChangedCallback 571-591, AddObject 594-627, DeleteObject 630-650, AddPlayer 653-680, DeletePlayer 683-699, PlayerEjected 702-734, ObjectKilled 737-779, ObjectSniped 782-820, GetNextRandomVehicleODF 823-841, Execute 845-872, PostRun 875-890, ProcessCommand 893-909, SetRandomSeed 912-928, CreateLuaStringTable 931-943, PreTeleport 947-985) + dumpbin of 4fc4023e-4fc41d60 for the register-passed arguments (InitTaunts, the lua_pcallk nargs / nresults, the global names, the string-table counts) | status: ported
#include "luamission.h"
#include "luabindings.h"
#include "bzcscriptutils.h"
#include "trnallies.h"
#include "taunts.h"
#include <math.h>
#include <string.h>
#include <stdlib.h>

LuaMission::LuaMission(void)
{
	m_GameTPS = 20;
	EnableHighTPS(m_GameTPS);
	AllowRandomTracks(true);
	b_count = &b_last - &b_first - 1;
	b_array = &b_first + 1;

	i_count = &i_last - &i_first - 1;
	i_array = &i_first + 1;

	TRNAllies::SetupTRNAllies(GetMapTRNFilename());

	// Zero things out first off. If you don't assign a default value, then it will be assigned whatever value was in that memory it is assigned to use. Essentially it would be filled with random values. We don't want that. This zero's out everything under each array at the very beginning.
	if(i_array)
		memset(i_array, 0, i_count*sizeof(int));
	if(b_array)
		memset(b_array, 0, b_count*sizeof(bool));

	L = NULL;
}

LuaMission::~LuaMission()
{
	CloseOpenODFs();
	CloseOpenFiles();
	CleanupTaunts();

	if (L)
		lua_close(L);
}

#ifndef LUA_LIB  // LuaMissionLib.lib (built -DLUA_LIB) must not define it: each DLL has its own
DLLBase * BuildMission(void)
{
	return new LuaMission();
}
#endif

void LuaMission::Setup(void)
{
	DidSetup = true;

	InitTaunts(&m_ElapsedGameTime, &m_LastTauntPrintedAt, &m_GameTPS);

	if (!L)
		return;

	// if the script has a Start function...
	lua_getglobal(L, "Start");
	if (lua_isfunction(L, -1))
	{
		// call the Start function
		LuaBindings::LuaCheckStatus(lua_pcall(L, 0, 0, 0), L, "Lua script Start error: %s");
	}
	else
	{
		lua_pop(L, 1);
	}
}

void LuaMission::InitialSetup(void)
{
	// Setup some initial stuff.
	EnableHighTPS(m_GameTPS);

	SetAutoGroupUnits(false);

	// Lua file initial loading. Look for a script named after the mission file.
	char script_filename[2 * MAX_ODF_LENGTH] = {0};

	strcpy_s(script_filename, GetMissionFilename());

	if (char *dot = strchr(script_filename, '.'))
		*dot = '\0';
	strcat_s(script_filename, ".lua");

	// Skip setup if there isn't a script
	if (!DoesFileExist(script_filename))
	{
		FormatConsoleMessage("No Lua script: '%s'", script_filename);
		return;
	}

	// Create a new Lua state with default memory allocator.
	L = luaL_newstate();
	if (!L)
		return;

	// Load standard libraries
	luaL_openlibs(L);

	// Remove io and os for security.
	lua_pushnil(L);
	lua_setglobal(L, "io");
	lua_pushnil(L);
	lua_setglobal(L, "os");

	// Register a panic handler
	lua_atpanic(L, LuaPanic);

	// Hijack the print function
	lua_register(L, "print", LuaPrint);

	// Register our functions
	// (into the global table)
	lua_pushglobaltable(L);
	luaL_setfuncs(L, LuaBindings::sLuaScriptUtils, 0);

	// Create a metatable for handles
	lua_pushlightuserdata(L, NULL);
	luaL_newmetatable(L, "Handle");
	lua_pushstring(L, "Handle");
	lua_setfield(L, -2, "__type");
	lua_pushcfunction(L, LuaBindings::Handle_ToString);
	lua_setfield(L, -2, "__tostring");
	lua_pushcfunction(L, LuaBindings::Handle_ToInteger);
	lua_setfield(L, -2, "__tosinteger"); // sic
	lua_setmetatable(L, -2);

	// Create a metatable for Vector
	luaL_newmetatable(L, "Vector");
	lua_pushstring(L, "Vector");
	lua_setfield(L, -2, "__type");
	lua_pushcfunction(L, LuaBindings::Vector_Index);
	lua_setfield(L, -2, "__index");
	lua_pushcfunction(L, LuaBindings::Vector_NewIndex);
	lua_setfield(L, -2, "__newindex");
	lua_pushcfunction(L, LuaBindings::Vector_Neg);
	lua_setfield(L, -2, "__unm");
	lua_pushcfunction(L, LuaBindings::Vector_Add);
	lua_setfield(L, -2, "__add");
	lua_pushcfunction(L, LuaBindings::Vector_Sub);
	lua_setfield(L, -2, "__sub");
	lua_pushcfunction(L, LuaBindings::Vector_Mul);
	lua_setfield(L, -2, "__mul");
	lua_pushcfunction(L, LuaBindings::Vector_Div);
	lua_setfield(L, -2, "__div");
	lua_pushcfunction(L, LuaBindings::Vector_Eq);
	lua_setfield(L, -2, "__eq");
	lua_pushcfunction(L, LuaBindings::Vector_ToString);
	lua_setfield(L, -2, "__tostring");
	// Vector is a struct so it doesn't need __gc
	lua_pop(L, 1);

	// Create a metatable for Matrix
	luaL_newmetatable(L, "Matrix");
	lua_pushstring(L, "Matrix");
	lua_setfield(L, -2, "__type");
	lua_pushcfunction(L, LuaBindings::Matrix_Index);
	lua_setfield(L, -2, "__index");
	lua_pushcfunction(L, LuaBindings::Matrix_NewIndex);
	lua_setfield(L, -2, "__newindex");
	lua_pushcfunction(L, LuaBindings::Matrix_Mul);
	lua_setfield(L, -2, "__mul");
	lua_pushcfunction(L, LuaBindings::Matrix_ToString);
	lua_setfield(L, -2, "__tostring");
	// Matrix is a struct so it doesn't need __gc
	lua_pop(L, 1);

	// Create a metatable for Quaternion
	luaL_newmetatable(L, "Quaternion");
	lua_pushstring(L, "Quaternion");
	lua_setfield(L, -2, "__type");
	lua_pushcfunction(L, LuaBindings::Quaternion_Index);
	lua_setfield(L, -2, "__index");
	lua_pushcfunction(L, LuaBindings::Quaternion_NewIndex);
	lua_setfield(L, -2, "__newindex");
	lua_pushcfunction(L, LuaBindings::Quaternion_Mul);
	lua_setfield(L, -2, "__mul");
	lua_pushcfunction(L, LuaBindings::Quaternion_ToString);
	lua_setfield(L, -2, "__tostring");
	// Quaternion is a struct so it doesn't need __gc
	lua_pop(L, 1);

	// identity matrix
	*LuaBindings::NewMatrix(L) = Identity_Matrix;
	lua_setglobal(L, "IdentityMatrix");

	// Enum tables.
	CreateLuaStringTable(L, CommandList, NUM_CMD, "AiCommand");
	CreateLuaStringTable(L, TauntTypesList, TAUNTS_MAX, "TauntTypes");
	CreateLuaStringTable(L, DeathmatchGameSubtypesList, 8, "DMSubGameTypes");
	CreateLuaStringTable(L, PreSnipeReturnCodesList, 2, "PreSnipeReturnValues");
	CreateLuaStringTable(L, PreGetInReturnCodesList, 2, "PreGetInReturnValues");
	CreateLuaStringTable(L, PrePickupPowerupReturnCodesList, 2, "PrePickupPowerupReturnValues");
	CreateLuaStringTable(L, RandomizeTypeList, 3, "RandomizeTypes");
	CreateLuaStringTable(L, TeamRelationshipList, 4, "TeamRelationshipTypes");
	CreateLuaStringTable(L, EjectKillRetCodeList, 4, "EjectKillRetCodes");

	// Version of this DLL's Lua API.
	lua_pushnumber(L, 186);
	lua_setglobal(L, "LuaMissionVersion");

	// get file data
	char* FileBuffer;
	size_t bufSize = 0;
	LoadFile(script_filename, NULL, bufSize);
	FileBuffer = static_cast<char *>(malloc(bufSize+1));
	LoadFile(script_filename, FileBuffer, bufSize);
	FileBuffer[bufSize] = '\0';

	// load and run the script
	LuaBindings::LuaCheckStatus(luaL_loadbuffer(L, FileBuffer, bufSize, script_filename), L, "Lua script load error: %s") &&
	LuaBindings::LuaCheckStatus(lua_pcall(L, 0, LUA_MULTRET, 0), L, "Lua script run error: %s");

	// release file data
	free(FileBuffer);

	if (!L)
		return;

	FormatConsoleMessage("Lua script: '%s' loaded", script_filename);

	// if the script has an Initial Setup function
	lua_getglobal(L, "InitialSetup");
	if (lua_isfunction(L, -1))
	{
		// call the InitialSetup function.
		LuaBindings::LuaCheckStatus(lua_pcall(L, 0, 0, 0), L, "Lua script InitialSetup error: %s");
	}
	else
	{
		lua_pop(L, 1);
	}
}

bool LuaMission::Load(bool missionSave)
{
	bool ret = BZ1Helper::Load(missionSave);

	if (missionSave) {
		int i = 0;

		// init bools
		for (i = 0; i < b_count; i++)
			b_array[i] = false;

		// init ints
		for (i = 0; i < i_count; i++)
			i_array[i] = 0;

		return true;
	}

	// bools
	if(b_count)
		ret = ret && Read(b_array, b_count);

	// ints
	if(i_count)
		ret = ret && Read(i_array, i_count);

	if (L)
	{
		// if the script has a Load function...
		lua_getglobal(L, "Load");
		if (lua_isfunction(L, -1))
		{
			// read argument values from the file
			int count = 0;
			ret = ret && Read(&count, 1);
			for (int i = 0; i < count; ++i)
			{
				ret = ret && LuaBindings::LoadValue(L, true);
			}

			// call the Load function
			LuaBindings::LuaCheckStatus(lua_pcall(L, count, 0, 0), L, "Lua script Load error: %s");
		}
		else
		{
			// skip argument values from the file
			// to prevent a missing Load function
			// from derailing the entire load process
			int count = 0;
			ret = ret && Read(&count, 1);
			for (int i = 0; i < count; ++i)
			{
				ret = ret && LuaBindings::LoadValue(L, false);
			}

			lua_pop(L, 1);
		}
	}

	return ret;
}

bool LuaMission::PostLoad(bool missionSave)
{
	bool ret = BZ1Helper::PostLoad(missionSave);

	if (missionSave)
		return true;

	return ret;
}

bool LuaMission::Save(bool missionSave)
{
	bool ret = BZ1Helper::Save(missionSave);

	if (missionSave)
		return ret;

	// bools
	if(b_count)
		ret = ret && Write(b_array, b_count);

	// ints
	if(i_count)
		ret = ret && Write(i_array, i_count);

	if (L)
	{
		// if the script has a Save function...
		lua_getglobal(L, "Save");
		if (lua_isfunction(L, -1))
		{
			// call the Save function
			int level = lua_gettop(L);
			if (LuaBindings::LuaCheckStatus(lua_pcall(L, 0, LUA_MULTRET, 0), L, "Lua script Save error: %s"))
			{
				// write return values to the file
				int count = lua_gettop(L) - level + 1;
				ret = ret && Write(&count, 1);
				for (int i = level; i < level + count; ++i)
				{
					ret = ret && LuaBindings::SaveValue(L, i);
				}
			}
		}
		else
		{
			// write zero return values
			int count = 0;
			ret = ret && Write(&count, 1);

			lua_pop(L, 1);
		}
	}

	return ret;
}

void LuaMission::PreOrdnanceHit(Handle shooterHandle, Handle victimHandle, int ordnanceTeam, const char* pOrdnanceODF)
{
	if(!StopScript)
		BZ1Helper::PreOrdnanceHit(shooterHandle, victimHandle, ordnanceTeam, pOrdnanceODF);

	if(!L)
		return;

	// if the script has a PreOrdnanceHit function...
	lua_getglobal(L, "PreOrdnanceHit");
	if (lua_isfunction(L, -1))
	{
		// call the PreOrdnanceHit function
		LuaBindings::PushHandle(L, shooterHandle);
		LuaBindings::PushHandle(L, victimHandle);
		lua_pushinteger(L, ordnanceTeam);
		lua_pushstring(L, pOrdnanceODF);
		LuaBindings::LuaCheckStatus(lua_pcall(L, 4, 0, 0), L, "Lua script PreOrdnanceHit error: %s");
	}
	else
	{
		lua_pop(L, 1);
	}
}

PreGetInReturnCodes LuaMission::PreGetIn(const int curWorld, Handle pilotHandle, Handle emptyCraftHandle)
{
	// Default value;
	PreGetInReturnCodes returnvalue = PREGETIN_ALLOW;

	if(!StopScript)
		returnvalue = BZ1Helper::PreGetIn(curWorld, pilotHandle, emptyCraftHandle);

	// Use Default.
	if(!L)
		return returnvalue;

	// if the script has a PreGetIn function...
	lua_getglobal(L, "PreGetIn");
	if (lua_isfunction(L, -1))
	{
		// call the PreGetIn function
		lua_pushnumber(L, curWorld);
		LuaBindings::PushHandle(L, pilotHandle);
		LuaBindings::PushHandle(L, emptyCraftHandle);
		LuaBindings::LuaCheckStatus(lua_pcall(L, 3, 1, 0), L, "Lua script PreGetIn error: %s");

		// If the Lua returned a number, let Lua Override.
		if (lua_isnumber(L, -1))
			returnvalue = PreGetInReturnCodes(lua_tointeger(L, -1));
		else if (!lua_isnone(L, -1))
			PrintConsoleMessage("Lua script PreGetIn error: invalid return param.");
	}

	lua_pop(L, 1);

	return returnvalue;
}

PreSnipeReturnCodes LuaMission::PreSnipe(const int curWorld, Handle shooterHandle, Handle victimHandle, int ordnanceTeam, const char* pOrdnanceODF)
{
	// Default value.
	PreSnipeReturnCodes returnvalue = PRESNIPE_KILLPILOT;

	if(!StopScript)
		returnvalue = BZ1Helper::PreSnipe(curWorld, shooterHandle, victimHandle, ordnanceTeam, pOrdnanceODF);

	if(!L)
		return returnvalue;

	// if the script has a PreSnipe function...
	lua_getglobal(L, "PreSnipe");
	if (lua_isfunction(L, -1))
	{
		// call the PreSnipe function
		lua_pushinteger(L, curWorld);
		LuaBindings::PushHandle(L, shooterHandle);
		LuaBindings::PushHandle(L, victimHandle);
		lua_pushinteger(L, ordnanceTeam);
		lua_pushstring(L, pOrdnanceODF);
		LuaBindings::LuaCheckStatus(lua_pcall(L, 5, 1, 0), L, "Lua script PreSnipe error: %s");

		if (lua_isnumber(L, -1))
			returnvalue = PreSnipeReturnCodes(lua_tointeger(L, -1));
		else if (!lua_isnone(L, -1))
			PrintConsoleMessage("Lua script PreSnipe error: invalid return param.");
	}

	lua_pop(L, 1);

	return returnvalue;
}

PrePickupPowerupReturnCodes LuaMission::PrePickupPowerup(const int curWorld, Handle me, Handle powerupHandle)
{
	// Default.
	PrePickupPowerupReturnCodes returnvalue = PREPICKUPPOWERUP_ALLOW;

	if(!StopScript)
		returnvalue = BZ1Helper::PrePickupPowerup(curWorld, me, powerupHandle);

	if (!L)
		return returnvalue;

	// if the script has a PrePickupPowerup function...
	lua_getglobal(L, "PrePickupPowerup");
	if (lua_isfunction(L, -1))
	{
		// call the PrePickupPowerup function
		lua_pushinteger(L, curWorld);
		LuaBindings::PushHandle(L, me);
		LuaBindings::PushHandle(L, powerupHandle);
		LuaBindings::LuaCheckStatus(lua_pcall(L, 3, 1, 0), L, "Lua script PrePickupPowerup error: %s");

		if (lua_isnumber(L, -1))
			returnvalue = PrePickupPowerupReturnCodes(lua_tointeger(L, -1));
		else if (!lua_isnone(L, -1))
			PrintConsoleMessage("Lua script PrePickupPowerup error: invalid return param.");
	}

	lua_pop(L, 1);

	return returnvalue;
}

// Notification to the DLL: called when a pilot/craft has changed targets
void LuaMission::PostTargetChangedCallback(Handle craft, Handle previousTarget, Handle currentTarget)
{
	if (!L)
		return;

	// if the script has a PostTargetChangedCallback function...
	lua_getglobal(L, "PostTargetChangedCallback");
	if (lua_isfunction(L, -1))
	{
		// call the PostTargetChangedCallback function
		LuaBindings::PushHandle(L, craft);
		LuaBindings::PushHandle(L, previousTarget);
		LuaBindings::PushHandle(L, currentTarget);
		LuaBindings::LuaCheckStatus(lua_pcall(L, 3, 0, 0), L, "Lua script PostTargetChangeCallback error: %s");
	}
	else
	{
		lua_pop(L, 1);
	}
}

void LuaMission::AddObject(Handle h)
{
	if(!StopScript)
		BZ1Helper::AddObject(h);

	if (!L)
		return;

	// Add CreateObject in ontop of AddObject, since BZ2 doesn't have CreateObject.
	lua_getglobal(L, "CreateObject");
	if (lua_isfunction(L, -1))
	{
		// call the CreateObject function with the game object handle
		LuaBindings::PushHandle(L, h);
		LuaBindings::LuaCheckStatus(lua_pcall(L, 1, 0, 0), L, "Lua script CreateObject error: %s");
	}
	else
	{
		lua_pop(L, 1);
	}

	// if the script has an AddObject function
	lua_getglobal(L, "AddObject");
	if (lua_isfunction(L, -1))
	{
		// call the AddObject function with the game object handle
		LuaBindings::PushHandle(L, h);
		LuaBindings::LuaCheckStatus(lua_pcall(L, 1, 0, 0), L, "Lua script AddObject error: %s");
	}
	else
	{
		lua_pop(L, 1);
	}
}

void LuaMission::DeleteObject(Handle h)
{
	if(!StopScript)
		BZ1Helper::DeleteObject(h);

	if (!L)
		return;

	// if the script has a DeleteObject function
	lua_getglobal(L, "DeleteObject");
	if (lua_isfunction(L, -1))
	{
		// call the DeleteObject function with the game object handle
		LuaBindings::PushHandle(L, h);
		LuaBindings::LuaCheckStatus(lua_pcall(L, 1, 0, 0), L, "Lua script DeleteObject error: %s");
	}
	else
	{
		lua_pop(L, 1);
	}
}

bool LuaMission::AddPlayer(DPID id, int Team, bool IsNewPlayer)
{
	if(!DidSetup)
		Setup();

	if (!L)
		return true;

	bool returnvalue = true;

	// if the script has an AddPlayer function...
	lua_getglobal(L, "AddPlayer");
	if (lua_isfunction(L, -1))
	{
		// call the AddPlayer function
		lua_pushinteger(L, id);
		lua_pushinteger(L, Team);
		lua_pushboolean(L, IsNewPlayer);
		LuaBindings::LuaCheckStatus(lua_pcall(L, 3, 1, 0), L, "Lua script AddPlayer error: %s");
		returnvalue = LuaBindings::luaL_optboolean(L, 1, returnvalue);
	}

	lua_pop(L, 1);

	return true;
}

void LuaMission::DeletePlayer(DPID id)
{
	if (!L)
		return;

	// if the script has a DeletePlayer function...
	lua_getglobal(L, "DeletePlayer");
	if (lua_isfunction(L, -1))
	{
		// call the DeletePlayer function
		lua_pushinteger(L, id);
		LuaBindings::LuaCheckStatus(lua_pcall(L, 1, 0, 0), L, "Lua script DeletePlayer error: %s");
	}
	else
	{
		lua_pop(L, 1);
	}
}

EjectKillRetCodes LuaMission::PlayerEjected(Handle DeadObjectHandle)
{
	if (!L)
		return DoEjectPilot;

	EjectKillRetCodes returnvalue = DoEjectPilot;

	// if the script has a PlayerEjected function...
	lua_getglobal(L, "PlayerEjected");
	if (lua_isfunction(L, -1))
	{
		// call the PlayerEjected function
		LuaBindings::PushHandle(L, DeadObjectHandle);
		LuaBindings::LuaCheckStatus(lua_pcall(L, 1, 1, 0), L, "Lua script PlayerEjected error: %s");

		if (lua_isnumber(L, -1))
			returnvalue = EjectKillRetCodes(lua_tointeger(L, -1));
		else if (!lua_isnone(L, -1))
			PrintConsoleMessage("Lua script PlayerEjected error: invalid return param.");
	}

	lua_pop(L, 1);

	return returnvalue;
}

EjectKillRetCodes LuaMission::ObjectKilled(int DeadObjectHandle, int KillersHandle)
{
	if(!StopScript)
		DeadObject(DeadObjectHandle);

	if (!L)
	{
		if(!IsPlayer(DeadObjectHandle)) // J.Random AI-controlled Object is toast
			return DLLHandled;
		else // Player dead
			return DoEjectPilot;
	}

	EjectKillRetCodes returnvalue = IsPlayer(DeadObjectHandle) ? DoEjectPilot : DLLHandled;

	// if the script has an ObjectKilled function...
	lua_getglobal(L, "ObjectKilled");
	if (lua_isfunction(L, -1))
	{
		// call the ObjectKilled function
		LuaBindings::PushHandle(L, DeadObjectHandle);
		LuaBindings::PushHandle(L, KillersHandle);
		LuaBindings::LuaCheckStatus(lua_pcall(L, 2, 1, 0), L, "Lua script ObjectKilled error: %s");

		if (lua_isnumber(L, -1))
			returnvalue = EjectKillRetCodes(lua_tointeger(L, -1));
		else if (!lua_isnone(L, -1))
			PrintConsoleMessage("Lua script ObjectKilled error: invalid return param.");
	}

	lua_pop(L, 1);

	return returnvalue;
}

EjectKillRetCodes LuaMission::ObjectSniped(int DeadObjectHandle, int KillersHandle)
{
	if (!L)
	{
		if(!IsPlayer(DeadObjectHandle)) // J.Random AI-controlled Object is toast
			return DLLHandled;
		else // Player dead
			return DoGameOver; //DoRespawnSafest;
	}

	EjectKillRetCodes returnvalue = IsPlayer(DeadObjectHandle) ? DoGameOver : DLLHandled;

	// if the script has an ObjectSniped function...
	lua_getglobal(L, "ObjectSniped");
	if (lua_isfunction(L, -1))
	{
		// call the ObjectSniped function
		LuaBindings::PushHandle(L, DeadObjectHandle);
		LuaBindings::PushHandle(L, KillersHandle);
		LuaBindings::LuaCheckStatus(lua_pcall(L, 2, 1, 0), L, "Lua script ObjectSniped error: %s");

		if (lua_isnumber(L, -1))
			returnvalue = EjectKillRetCodes(lua_tointeger(L, -1));
		else if (!lua_isnone(L, -1))
			PrintConsoleMessage("Lua script ObjectSniped error: invalid return param.");
	}

	lua_pop(L, 1);

	return returnvalue;
}

const char * LuaMission::GetNextRandomVehicleODF(int Team)
{
	if (L)
	{
		// if the script has a GetNextRandomVehicleODF function...
		lua_getglobal(L, "GetNextRandomVehicleODF");
		if (lua_isfunction(L, -1))
		{
			// call the GetNextRandomVehicleODF function
			lua_pushinteger(L, Team);
			LuaBindings::LuaCheckStatus(lua_pcall(L, 1, 1, 0), L, "Lua script GetNextRandomVehicleODF error: %s");
		}
		else
		{
			lua_pop(L, 1);
		}
	}

	return GetPlayerODF(Team, Randomize_None);
}

void LuaMission::Execute(void)
{
	if(!StopScript)
		BZ1Helper::Execute();

	// Do init first! -GBD
	if (!DidSetup)
		Setup();

	// Count the turns each tick. Multiply or Divide by m_GameTPS to translate into seconds. (divide to turn m_ElapsedGameTime into seconds,
	// Multiply # of seconds by m_GameTPS to turn it into ticks per second.
	m_ElapsedGameTime++;

	if (!L)
		return;

	// if the script has an Update function...
	lua_getglobal(L, "Update");
	if (lua_isfunction(L, -1))
	{
		// call the Update function
		LuaBindings::LuaCheckStatus(lua_pcall(L, 0, 0, 0), L, "Lua script Update error: %s");
	}
	else
	{
		lua_pop(L, 1);
	}
}

void LuaMission::PostRun(void)
{
	if (!L)
		return;

	// if the script has a PostRun function...
	lua_getglobal(L, "PostRun");
	if (lua_isfunction(L, -1))
	{
		// call the PostRun function
		LuaBindings::LuaCheckStatus(lua_pcall(L, 0, 0, 0), L, "Lua script PostRun error: '%s'");
	}
	else
	{
		lua_pop(L, 1);
	}
}

void LuaMission::ProcessCommand(unsigned long crc)
{
	if (!L)
		return;

	// if the script has a ProcessCommand function...
	lua_getglobal(L, "ProcessCommand");
	if (lua_isfunction(L, -1))
	{
		// call the ProcessCommand function
		lua_pushinteger(L, crc);
		LuaBindings::LuaCheckStatus(lua_pcall(L, 1, 0, 0), L, "Lua script ProcessCommand error: '%s'");
	}
	else
	{
		lua_pop(L, 1);
	}
}

void LuaMission::SetRandomSeed(unsigned long seed)
{
	if (!L)
		return;

	// if the script has a SetRandomSeed function...
	lua_getglobal(L, "SetRandomSeed");
	if (lua_isfunction(L, -1))
	{
		// call the SetRandomSeed function
		lua_pushinteger(L, seed);
		LuaBindings::LuaCheckStatus(lua_pcall(L, 1, 0, 0), L, "Lua script SetRandomSeed error: '%s'");
	}
	else
	{
		lua_pop(L, 1);
	}
}

// Builds a global table that maps both ways: table[index] = name and table[name] = index.
void LuaMission::CreateLuaStringTable(lua_State* L1, const char** StringArray, const int Count, const char* TableName)
{
	lua_createtable(L1, Count, Count);
	for (int i = 0; i < Count; ++i)
	{
		lua_pushnumber(L1, i);
		lua_pushstring(L1, StringArray[i]);
		lua_pushvalue(L1, -1);
		lua_pushvalue(L1, -3);
		lua_rawset(L1, -5);
		lua_rawset(L1, -3);
	}
	lua_setglobal(L1, TableName);
}

PreTeleportReturnCodes LuaMission::PreTeleport(const Handle portalHandle, const Handle shipHandle)
{
	// Default.
	PreTeleportReturnCodes returnvalue = PreTeleport_DEFAULT;

	if (!L)
		return returnvalue;

	// if the script has a PreTeleport function...
	lua_getglobal(L, "PreTeleport");
	if (lua_isfunction(L, -1))
	{
		// call the PreTeleport function
		LuaBindings::PushHandle(L, portalHandle);
		LuaBindings::PushHandle(L, shipHandle);
		LuaBindings::LuaCheckStatus(lua_pcall(L, 2, 1, 0), L, "Lua script PreTeleport error: %s");

		if (lua_isnumber(L, -1))
			returnvalue = PreTeleportReturnCodes(lua_tointeger(L, -1));
		else if (!lua_isnone(L, -1))
			PrintConsoleMessage("Lua script PreTeleport error: invalid return param.");
	}

	lua_pop(L, 1);

	return returnvalue;
}
