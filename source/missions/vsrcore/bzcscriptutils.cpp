// PROVENANCE: ancestors reference/ancestor-1.3/Missions/Shared/ScriptUtilsExtention.cpp + reference/ancestor-bz1helper-2015/Shared/BZCScriptUtils.cpp @6fda4f5 | decompile reference/decompiled/strategy02-ghidra12.2/src/missions/vsrcore/bzcscriptutils.cpp.decomp.c + original/missions/Strategy02.pdb (functions in the PDB's file order) | status: ported
#include "bzcscriptutils.h"
#include <math.h>
#include <memory.h>
#include <malloc.h>
#include <stdarg.h>
#include <stdio.h>
#include <share.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

// Battlezone 2 ScriptUtils Extention written by General BlackDragon, Ken Miller, and Nielk1.
//
// Reconstruction notes. The shipped Strategy02.dll keeps 93 functions from this file; the PDB line
// table gives their order and extents and the Ghidra decompile their bodies. Bodies that match an
// ancestor (1.3 ScriptUtilsExtention.cpp, then the 2015 BZCScriptUtils.cpp) use the ancestor text;
// where the decompile disagrees the decompile wins and the spot is marked "GBD:". The whole-program
// optimizer (/GL + /LTCG) folds parameters that every caller passes as constants, so a parameter the
// decompile never reads is kept when an ancestor reads it ("folded"). Functions that only the
// ancestors carry are kept where the line table leaves a gap of the right size; they vanish from the
// image when nothing references them, exactly as they did for GBD.

// This stores a list of all currently open ODFs for this session.
std::unordered_map<unsigned long, ODFName> ODFNameMap;
// This stores all the failed attempted open ODFs so we don't try them more then once. // GBD: a set (PDB), not a second name map.
std::unordered_set<unsigned long> ODFNameBlackListMap;
// This stored a list of all currently open Files for this session.
std::unordered_map<const char*, FILE*> FileNameMap;
// This stores the Log file for this game, and the name prefix it is opened under.
FILE* LogFile = NULL;
char LogFileName[MAX_ODF_LENGTH] = { 0 };

// List all AI Commands. !!! Update based on aiCommands.h should it ever change! NOTE: # of entries must == NUM_CMD.
const char *CommandList[NUM_CMD] = { "CMD_NONE", "CMD_SELECT", "CMD_STOP", "CMD_GO", "CMD_ATTACK", "CMD_FOLLOW", "CMD_FORMATION", "CMD_PICKUP",
"CMD_DROPOFF", "CMD_UNDEPLOY", "CMD_DEPLOY", "CMD_NO_DEPLOY", "CMD_GET_REPAIR", "CMD_GET_RELOAD", "CMD_GET_WEAPON", "CMD_GET_CAMERA", "CMD_GET_BOMB",
"CMD_DEFEND", "CMD_RESCUE", "CMD_RECYCLE", "CMD_SCAVENGE", "CMD_HUNT", "CMD_BUILD", "CMD_PATROL", "CMD_STAGE", "CMD_SEND", "CMD_GET_IN",
"CMD_LAY_MINES", "CMD_LOOK_AT", "CMD_SERVICE", "CMD_UPGRADE", "CMD_DEMOLISH", "CMD_POWER", "CMD_BACK", "CMD_DONE", "CMD_CANCEL", "CMD_SET_GROUP",
"CMD_SET_TEAM", "CMD_SEND_GROUP", "CMD_TARGET", "CMD_INSPECT", "CMD_SWITCHTEAM", "CMD_INTERFACE", "CMD_LOGOFF", "CMD_AUTOPILOT", "CMD_MESSAGE",
"CMD_CLOSE", "CMD_MORPH_SETDEPLOYED", "CMD_MORPH_SETUNDEPLOYED", "CMD_MORPH_UNLOCK", "CMD_BAILOUT", "CMD_BUILD_ROTATE", "CMD_CMDPANEL_SELECT",
"CMD_CMDPANEL_DESELECT" };

// Enum name tables the Lua side registers (PDB: initialized data of this object, right after CommandList).
const char *RandomizeTypeList[3] = { "Randomize_None", "Randomize_ByRace", "Randomize_Any" };
const char *PreGetInReturnCodesList[2] = { "PREGETIN_DENY", "PREGETIN_ALLOW" };
const char *TauntTypesList[16] = { "TAUNTS_GameStart", "TAUNTS_NewHuman", "TAUNTS_LeftHuman", "TAUNTS_HumanShipDestroyed", "TAUNTS_HumanRecyDestroyed",
	"TAUNTS_CPURecyDestroyed", "TAUNTS_Random", "TAUNTS_Category7", "TAUNTS_Category8", "TAUNTS_Category9", "TAUNTS_Category10", "TAUNTS_Category11",
	"TAUNTS_Category12", "TAUNTS_Category13", "TAUNTS_Category14", "TAUNTS_Category15" };
const char *EjectKillRetCodeList[4] = { "EJECTKILLRETCODES_DOEJECTPILOT", "EJECTKILLRETCODES_DORESPAWNSAFEST", "EJECTKILLRETCODES_DLLHANDLED", "EJECTKILLRETCODES_DOGAMEOVER" };
const char *PrePickupPowerupReturnCodesList[2] = { "PREPICKUPPOWERUP_DENY", "PREPICKUPPOWERUP_ALLOW" };
const char *PreSnipeReturnCodesList[2] = { "PRESNIPE_KILLPILOT", "PRESNIPE_ONLYBULLETHIT" };
const char *DeathmatchGameSubtypesList[8] = { "DMSubtype_Normal", "DMSubtype_KOH", "DMSubtype_CTF", "DMSubtype_Loot", "DMSubtype_RESERVED1", "DMSubtype_Race1", "DMSubtype_Race2", "DMSubtype_Normal2" };
const char *TeamRelationshipList[4] = { "TEAMRELATIONSHIP_INVALIDHANDLE", "TEAMRELATIONSHIP_SAMETEAM", "TEAMRELATIONSHIP_ALLIEDTEAM", "TEAMRELATIONSHIP_ENEMYTEAM" };

// Engine classlabels that are buildings / powered buildings (PDB .rdata; used by the ODF-name IsBuilding / IsPoweredBuilding).
const char *ClassLabelBuildings[21] = { "powered", "turret", "silo", "supplydepot", "barracks", "factory", "armory", "recycler", "shieldtower", "extractor",
	"commbunker", "commtower", "powerplant", "powerlung", "jammer", "sensor", "techcenter", "bomberbay", "teleportal", "terrain", "i76building" };
const char *ClassLabelPoweredBuildings[13] = { "powered", "turret", "supplydepot", "barracks", "factory", "armory", "shieldtower", "commbunker", "commtower",
	"sensor", "techcenter", "bomberbay", "teleportal" };

// Weapons (Only physical objects, DLL can't see ordnance yet. :( ) // GBD: CLASS_MINE joined the list.
const Hash_GOClass WeaponClass[11] = { CLASS_MINE_PROXIMITY, CLASS_MINE_MAGNET, CLASS_MINE_WEAPON, CLASS_MINE_TRIP, CLASS_FLAREMINE,
		CLASS_SPRAYBOMB, CLASS_SPRAYBUILDING, CLASS_TORPEDO, CLASS_SEEKER, CLASS_SATCHELCHARGE, CLASS_MINE };

// Misc items, usually the unimportant stuff, on team 0. // GBD: CLASS_PLANT (the power plant class) left the list.
const Hash_GOClass MiscClass[10] = { CLASS_SCRAP, CLASS_DEPOSIT, CLASS_NAVBEACON, CLASS_OBJECTSPAWN, CLASS_SIGN, CLASS_SPAWNBUOY, CLASS_ARTIFACT,
		CLASS_FLAG, CLASS_KINGOFHILL, CLASS_BOID };

// ancestor lists; not in the shipped binary (their users are unreferenced there).
// List of Deafult Classlabel = "" strings that align to terrain by "default".
const char *DefaultAlignToTerrainList[] = { "scrap", "powered", "turret", "silo", "supplydepot", "barracks", "deposit", "factory", "armory", "recycler", 
		"shieldtower", "extractor", "commbunker", "commtower", "powerplant", "powerlung", "jammer", "sensor", "bomberbay", "teleportal", "terrain", 
		"i76building", "i76sign", "proximity", "magnet", "weaponmine", "tripmine", "flare", "spraybomb", "spraybuilding", "torpedo", "seeker", 
		"satchel" };

// List of ODF names, in reverse load order, for smooth loading. Race Letter is added on to the front.
const char *PreloadRaceList[] = { "spilo", "ssold", "suser", "vapc", "vartl", "vfigh", "vhaul", "vhraz", "vhtnk", "vltnk", "vmine", "vrckt", "vrdev", 
		"vsav", "vscav", "vtank", "vturr", "vwalk", "vatank", "vmbike", "vmisl", "vsent", "varch", // Units.
		"bmuf", "vmuf", // Factory.
		"bbarr", "bcafe", "bcomm", "bhang", "bhqcp", "blpad", "blpow", "bmbld", "bshld", "bsilo", "bspow", "bsupp", "btowe", "bwpow", 
		"barmo", "bsbay", "bbomb", "btrain", "bgtow", "bspir", // Buildings.
		"vcnst", // Constructor
		"bslf", "vslf", "brecy", "vrecy", }; // SLF/Recy.

// Common ODF Lists.
const char *OffensiveShipList[] = { "avfigh", "avltnk", "avtank", "avrckt", "avhraz", "avwalk", "avhtnk", "avapc" };
const char *DefensiveShipList[] = { "avartl", "avmine", "avturr" };
const char *UtilityShipList[] = { "avscav", "avhaul", "avserv" };

// Scratch buffers the const char* getters return (PDB: all 64 bytes, zero in the image).
extern char TempGetClasslabelString[MAX_ODF_LENGTH];

// Things moved from DLLUtils.

// Returns true if h is a recycler or recycler vehicle, false if h is invalid, or not a recycler
bool IsRecycler(const Handle h)
{
	char ObjClass[MAX_ODF_LENGTH] = {0};
	if(!GetObjInfo(h, Get_GOClass, ObjClass))
		return false;

	char BZCClass[MAX_ODF_LENGTH] = {0};
	GetODFString(h, "GameObjectClass", "BZCClasslabel", MAX_ODF_LENGTH, BZCClass);

	// GBD: CLASS_RECYCLERVEHICLEH joined the test.
	return (_stricmp(ObjClass, "CLASS_RECYCLER") == 0) || (_stricmp(ObjClass, "CLASS_RECYCLERVEHICLE") == 0) || (_stricmp(ObjClass, "CLASS_RECYCLERVEHICLEH") == 0) || (_stricmp(BZCClass, "recy") == 0); // Look for ScavH's too. -GBD
}

/////////////////////////////////////////////////////////////
// Things from Bob "BS-ser" Stewert's DLL Scriptor.
/////////////////////////////////////////////////////////////

// Code from Bob "BS-er" Stewart. Slight tweaks by General BlackDragon. (portable_sin/atan2)
Vector HRotateFront(const Vector Front, const float HAngleDifference)
{
	Vector FinalVector(0, 0, 0);
	float Angle = 0.0f;
	float Scale = sqrt(1.0f - Front.y * Front.y);

	// Get the horizontal angle of the initial directional vector.
	Angle = portable_atan2(Front.x, Front.z);

	// Add the rotation amount to the current angle, and convert back into a directional vector.
	Angle += HAngleDifference;
	FinalVector.x = portable_sin(Angle) * Scale;
	FinalVector.y = Front.y;
	FinalVector.z = portable_cos(Angle) * Scale;

	return FinalVector;
}
// Code from Bob "BS-er" Stewart.
void SetAngle(const Handle h, const float Degrees)
{
	if (!IsAround(h))
		return;

	Vector Front = HRotateFront(Vector(0.0f, 0.0f, 1.0f), Degrees * DEG_2_RAD);
	Matrix Position = Build_Directinal_Matrix(GetPosition(h), Front); // GetPosition2?
	SetPosition(h, Position);
	SetVectorPosition(h, Position.posit);
}

// Code originally from Bob "BS-er" Stewart. Re-write by Ken Miller and General BlackDragon.
float CameraTime = -1.0f;
Vector CameraPosition(0, 0, 0);
bool CameraPos(const Handle me, const Handle him, const Vector &PosA, const Vector &PosB, const float Speed)
{
	// Compute the difference vector between the starting and ending positions
	Vector CameraDiffVector = Sub_Vectors(PosB, PosA);
	// Advance the camera position
	float Distance = GetLength3D(CameraDiffVector);

	// Compute the time when the camera shot must end
	if (CameraTime < 0.0f)
	{
		float Time = Distance / (Speed * 0.01f);
		CameraPosition = PosA;
		CameraTime = (GetTime() + Time);
	}
	else
	{
		float Scale = Speed / (Distance * 100 * GetTPS());
		CameraPosition = Add_Mult_Vectors(CameraPosition, CameraDiffVector, Scale); // Increment the Position.
	}

	if ((CameraObject(me, CameraPosition.x, CameraPosition.y, CameraPosition.z, him)) || (GetTime() > CameraTime) || (!IsAround(him)))
	{
		CameraTime = -1.0f;
		return true; // Done here.
	}

	return false;
}

// Sets the Camera to the specified Pos offset, facing the direction of the handle.
void CameraOf(const Handle me, const Vector &Offset)
{
	if (!IsAround(me))
		return;

	SetCameraPosition(Vector_Transform(GetMatrixPosition(me), Offset), GetFront(me));
}

// Moves the handle from it's current position to it's final position at the specified speed, optionally rotating the object the direction while moving it.
// GBD: two trailing bools (PDB). Every shipped caller leaves them at their defaults, so the optimizer folded them out of the image;
// the names and what they gate are reconstructed from the two literals the 1.3 body carried at those spots.
bool Move(const Handle h, const float TurnSpeed, const float MoveSpeed, const Vector &Dest, const bool SetVel, const bool SetPos)
{
	if (!IsAround(h))
		return true; // Handle is gone, abort.

	float dt = 1.0f / GetTPS(); // Delta time, per turn.

	// Get the object's current position and rotation.
	Matrix OldMat = GetMatrixPosition(h);
	Matrix NewMat = OldMat; // Fill this in for now.

	// Rotate the object's new matrix.
	if (TurnSpeed)
	{
		NewMat = Build_Directinal_Matrix(OldMat.posit, HRotateFront(GetFront(h), (TurnSpeed * dt) * DEG_2_RAD));
	}

	// If the object is moving, move it's new matrix.
	if (MoveSpeed)
	{
		// Get the difference vector between the object and the destination
		Vector DiffVector = Sub_Vectors(Dest, OldMat.posit);
		// Get the length.
		float DiffLength = GetLength3D(DiffVector);

		// See if the object is about to go past the destination
		float Speed = MoveSpeed * dt;

		// If we're not here yet...
		if (DiffLength >= Speed)
		{
			// Normalize the Vector.
			DiffVector = Normalize_Vector(DiffVector);
			NewMat.posit = Add_Mult_Vectors(OldMat.posit, DiffVector, Speed);
			//SetVectorPosition(h, Pos);

			//float MPS = MoveSpeed * 0.001f; // What is this exactly? does it need to scale with TPS? -GBD
			float MPS = Speed / 10.0f;
			DiffVector *= MPS; // Apply speed?
			if (SetVel)
				SetVelocity(h, DiffVector);
		}
		else
		{
			return true; // We're here, return true.
		}
	}
	else
	{
		return true; // No movement speed specified, return true.
	}

	SetLastCurrentPosition(h, OldMat, NewMat);
	SetInterpolablePosition(h, &NewMat, &OldMat, SetPos); // Move the object.

	return false;
}
// Rotates the handle at the specified speed, for the specified time.
bool Move(const Handle h, const float TurnSpeed, const float Time, const bool SetPos)
{
	if (!IsAround(h))
		return true; // Handle is gone, abort.

	if (GetTime() >= Time)
		return true; // Timer done.

	float dt = 1.0f / GetTPS(); // Delta time, per turn.

	// Get the object's current position and rotation.
	Matrix OldMat = GetMatrixPosition(h);
	Matrix NewMat = OldMat; // Fill this in for now.

	// Rotate the object's new matrix.
	if (TurnSpeed)
	{
		NewMat = Build_Directinal_Matrix(NewMat.posit, HRotateFront(GetFront(h), (TurnSpeed * dt) * DEG_2_RAD));
	}
	else
	{
		return true; // No movement speed specified, return true.
	}

	SetLastCurrentPosition(h, OldMat, NewMat);
	SetInterpolablePosition(h, &NewMat, &OldMat, SetPos); // Move the object.

	return false;
}

Vector CircleCalculation(0, 0, 0);
// Camera Circle function created by General BlackDragon and WhosDr. Circles around an object.
// GBD: shares CameraPos's -1 "idle" sentinel in CameraTime, resets CircleCalculation on start, and pairs the speed components (x+y, y+z, x+z).
bool CameraCircle(const Handle me, const Vector Offset, const Handle him, const Vector &Speed)
{
	// Calculate the radius, the origin is always 0, 0, 0. 
	float Radius = GetLength3D(Offset);

	if (CameraTime < 0.0f)
	{
		CameraPosition = Offset;
		CircleCalculation = Vector(0, 0, 0);
		CameraTime = 1.0f; // Set this here to flag this off.
	}
	else
	{
		Vector speed(Speed.x + Speed.y, Speed.y + Speed.z, Speed.x + Speed.z);

		CircleCalculation = Add_Mult_Vectors(CircleCalculation, speed, 1.0f / GetTPS());

		CameraPosition.x = (portable_sin(CircleCalculation.x * DEG_2_RAD) * Radius);
		CameraPosition.y = (portable_cos(CircleCalculation.y * DEG_2_RAD) * Radius);
		CameraPosition.z = (portable_cos(CircleCalculation.z * DEG_2_RAD) * Radius);
	}

	if ((CameraObject(me, CameraPosition.x, CameraPosition.y, CameraPosition.z, him)) || (!IsAround(him)))
	{
		CameraTime = -1.0f;
		return true;
	}

	return false;
}

// New things :)

// Formatted console message.
// GBD: the format may name a text file or a localized string (FormatFromFile); truncating vsnprintf_s.
// NOTE(port): FormatFromFile's malloc'd copy is never freed by the shipped binary; kept for parity, flagged for review.
void FormatConsoleMessage(const char *format, ...)
{
	va_list ap;
	va_start(ap, format);
	const char *formatstr = FormatFromFile(format);
	char tempstr[MAX_MESSAGE_LENGTH] = {0};
	vsnprintf_s(tempstr, sizeof(tempstr), _TRUNCATE, formatstr, ap);
	size_t len = strlen(tempstr);
	if (len < MAX_CONSOLE_MSG_LENGTH)
	{
		PrintConsoleMessage(tempstr);
	}
	else
	{
		char *start = tempstr, *end = tempstr;
		for (char *ptr = tempstr; *ptr != '\0'; ++ptr)
		{
			if (end - start >= MAX_CONSOLE_MSG_LENGTH)
			{
				PrintConsoleMessage(start);
				return; // Message too long, dump string and move on.
			}
			if (*ptr == '\n') // End of line.
			{
				end = ptr;
				*end = '\0';
				if (end > tempstr && *(end - 1) == '\r')
					*(end - 1) = '\0';

				PrintConsoleMessage(start);
				start = end + 1;
			}
		}
		if ((start <= end + 1) && (end - start < 512)) // If we're not at end of file yet, print last line.
		{
			PrintConsoleMessage(start);
		}
	}
	va_end(ap);
}

// Opens a file and remembers the file name for later closure.
// GBD: an already-open name is simply reused (no reopen); names with ':' or '..' are refused; files live under <output>\logs\.
bool FileOpen(const char *Filename, const bool Append)
{
	// already open
	if(FileNameMap.find(Filename) != FileNameMap.end())
		return true;

	if ((strstr(Filename, "..") == NULL) && (strstr(Filename, ":") == NULL))
	{
		// get the output path
		wchar_t* pRootOutputDir = NULL;
		size_t bufSize = 0;
		GetOutputPath(bufSize, pRootOutputDir);
		wchar_t *pData = static_cast<wchar_t *>(alloca(bufSize*sizeof(wchar_t)));
		if (!GetOutputPath(bufSize, pData))
			return false;

		// generate a full path name
		wchar_t outPath[MAX_MESSAGE_LENGTH] = {0};
		swprintf_s(outPath, L"%slogs\\%S", pData, Filename);
		FILE *file = _wfsopen(outPath, Append ? L"a+" : L"w+", _SH_DENYWR);

		// try to open the file for append
		if (file)
		{
			// opened successfully
			FileNameMap[Filename] = file;
			return true;
		}

		FormatLogMessage("ERROR: Could not open File: '%s'", outPath); // (sic: wide path through %s, as shipped)
		return false;
	}

	FormatConsoleMessage("ERROR: Invalid name format for File: '%s', ':' or '..' not allowed.", Filename);
	return false;
}

// Formatted Logfile message. Writes a char string to a log file.
bool FormatFileMessage(const char *Filename, const bool Append, const char *format, ...)
{
	if (FileOpen(Filename, Append))
	{
		va_list ap;
		va_start(ap, format);
		FILE *file = FileNameMap[Filename];
		vfprintf(file, format, ap); // GBD: vfprintf (the 1.3 fprintf took the va_list as an argument).
		fputs("\n", file);
		va_end(ap);
		return true;
	}
	return false;
}

// Closes a specific file. // ancestor; not in the shipped binary
void FileClose(const char *Filename)
{
	FileMapIt it = FileNameMap.find(Filename);
	if(it != FileNameMap.end())
	{
		fclose(it->second);
		FileNameMap.erase(it);
	}
}

// Close all open files.
void CloseOpenFiles()
{
	FileMapIt it = FileNameMap.begin();
	while(it != FileNameMap.end())
	{
		if (it->second)
			fclose(it->second);

		it = FileNameMap.erase(it);
	}
}

// Opens the Log file. GBD: "<LogFileName>_<stamp>.log", or "BZClassic_<stamp>.log" when no name is set; returns whether the output path resolved.
bool OpenLogFile()
{
	time_t Time = 0;
	time(&Time);
	struct tm LocalTimestamp;
	localtime_s(&LocalTimestamp, &Time);

	char LogName[MAX_ODF_LENGTH] = {0};
	char TimeStamp[MAX_ODF_LENGTH] = {0};
	strftime(TimeStamp, sizeof(TimeStamp), "%Y-%m-%d %H.%M.%S %p.log", &LocalTimestamp);
	if (LogFileName[0] == '\0')
		sprintf_s(LogName, "BZClassic_%s", TimeStamp);
	else
		sprintf_s(LogName, "%s_%s", LogFileName, TimeStamp);

	// get the output path
	size_t bufSize = 0;
	GetOutputPath(bufSize, NULL);
	wchar_t *pData = static_cast<wchar_t *>(alloca(bufSize*sizeof(wchar_t)));
	const bool GotPath = GetOutputPath(bufSize, pData);
	if (GotPath)
	{
		// generate a full path name
		wchar_t outPath[MAX_MESSAGE_LENGTH] = {0};
		swprintf_s(outPath, L"%slogs/%S", pData, LogName);
		LogFile = _wfsopen(outPath, L"a+", _SH_DENYWR);
	}
	return GotPath;
}

// Formatted Logfile message. Writes a char string to a log file.
bool FormatLogMessage(const char *format, ...)
{
	va_list ap;
	va_start(ap, format);
	char tempstr[MAX_MESSAGE_LENGTH] = {0};
	vsnprintf_s(tempstr, sizeof(tempstr), _TRUNCATE, format, ap);
	va_end(ap);

	time_t Time = 0;
	time(&Time);
	struct tm LocalTimestamp;
	localtime_s(&LocalTimestamp, &Time);

	char TimeStamp[MAX_ODF_LENGTH] = {0};
	strftime(TimeStamp, sizeof(TimeStamp), "%H:%M:%S", &LocalTimestamp);

	if(!LogFile)
		OpenLogFile();

	if(!LogFile)
	{
		char Message[MAX_MESSAGE_LENGTH] = {0};
		sprintf_s(Message, "ERROR: Unable to open Log File! Reporting: '%s'", tempstr);
		FormatConsoleMessage(Message);
		return false;
	}

	fprintf(LogFile, "%s | %f \t| %s\n", TimeStamp, GetTime(), tempstr);

	if ((GetVarItemInt("network.session.ivar115")) || (GetVarItemInt("network.session.civar5"))) // If logging is on, print to console. GBD: civar5 too.
		FormatConsoleMessage(tempstr);

	return true;
}
// ancestor; not in the shipped binary
bool SimpleLogMessage(const char *format, ...)
{
	va_list ap;
	va_start(ap, format);
	char tempstr[MAX_MESSAGE_LENGTH] = { 0 };
	vsnprintf_s(tempstr, sizeof(tempstr), _TRUNCATE, format, ap);
	va_end(ap);

	if (!LogFile)
		OpenLogFile();

	if (LogFile)
	{
		fprintf(LogFile, "%s", tempstr);

		if (GetVarItemInt("network.session.ivar115")) // If logging is on, print to console.
			PrintConsoleMessage(tempstr);

		return true;
	}
	else
	{
		char Message[MAX_MESSAGE_LENGTH] = { 0 };
		sprintf_s(Message, "ERROR: Unable to open Log File! Reporting: %s", tempstr);
		PrintConsoleMessage(Message);
		return false;
	}
}

// Closes the Log file. // ancestor; not in the shipped binary
void CloseLogFile()
{
	if(LogFile)
		fclose(LogFile);
}

// Prints an IFace_ConsoleCmd like FormatConsoleMessage. // ancestor; not in the shipped binary
void IFace_FormatConsoleCmd(const char *format, ...)
{
	va_list ap;
	va_start(ap, format);
	char tempstr[MAX_MESSAGE_LENGTH] = {0};
	vsnprintf_s(tempstr, sizeof(tempstr), _TRUNCATE, format, ap);
	IFace_ConsoleCmd(tempstr);
	va_end(ap);

	if(GetVarItemInt("network.session.ivar115")) // If logging is on, log any console commands inputted.
		FormatLogMessage("IFace Console Command: %s", tempstr);
}

// Like AddToMessagesBox2, but takes a formatted string. GBD: the format goes through FormatFromFile like the console message.
void FormatToMessagesBox(const char *format, const unsigned long color, ...)
{
	va_list ap;
	va_start(ap, color);
	const char *formatstr = FormatFromFile(format);
	char tempstr[MAX_MESSAGE_LENGTH] = { 0 };
	vsnprintf_s(tempstr, sizeof(tempstr), _TRUNCATE, formatstr, ap);
	AddToMessagesBox2(tempstr, color);
	va_end(ap);
}

// Resolves a format source. A short name ending in .txt / .inf / .des / .brf / .otf / .odf is a file to load whole; anything else is a
// "mission" localized string key (GetBZCCLocalizedString). Returns a malloc'd copy either way.
char *FormatFromFile(const char *formatsource)
{
	char *Result = NULL;
	const size_t len = strlen(formatsource);
	if (len <= MAX_ODF_LENGTH)
	{
		const char *ext = formatsource + len - 4;
		if ((_stricmp(ext, ".txt") == 0) || (_stricmp(ext, ".inf") == 0) || (_stricmp(ext, ".des") == 0) ||
			(_stricmp(ext, ".brf") == 0) || (_stricmp(ext, ".otf") == 0) || (_stricmp(ext, ".odf") == 0))
		{
			size_t bufSize = 0;
			LoadFile(formatsource, NULL, bufSize);
			Result = static_cast<char *>(malloc(bufSize + 1));
			LoadFile(formatsource, Result, bufSize);
			Result[bufSize] = '\0';
			return Result;
		}
	}

	const char *Localized = GetBZCCLocalizedString("mission", formatsource);
	const size_t Size = strlen(Localized) + 1;
	Result = static_cast<char *>(malloc(Size));
	strcpy_s(Result, Size, Localized);
	return Result;
}

// Is this object facing another object?
bool IsObjectFacingObject(const Handle h1, const Handle h2, const float ConeAngle)
{
	if((!IsAround(h1)) || (!IsAround(h2)))
		return false;

	Matrix PositionA = GetMatrixPosition(h1);
	Matrix PositionB = GetMatrixPosition(h2);

	return (PositionA.front.x * (PositionB.posit.x - PositionA.posit.x) + PositionA.front.z * (PositionB.posit.z - PositionA.posit.z)) > (portable_cos(ConeAngle) * GetDistance2D(PositionB.posit, PositionA.posit));
}

// Is this Vector facing an object based on two Positions and a ConeAngle? // ancestor; not in the shipped binary
bool IsObjectFacingObject(const Vector FrontA, const Vector PositionA, const Vector PositionB, const float ConeAngle)
{
	return (FrontA.x * (PositionB.x - PositionA.x) + FrontA.z * (PositionB.z - PositionA.z)) > (portable_cos(ConeAngle) * GetDistance2D(PositionB, PositionA));
}

// Is the object to the Right, or to the Left? // ancestor; not in the shipped binary
bool IsObjectFacingObjectRight(const Handle me, const Handle him)
{
	if((!IsAround(me)) || (!IsAround(him)))
		return false;

	Matrix PositionA = GetMatrixPosition(me);
	Matrix PositionB = GetMatrixPosition(him);

	return (PositionA.right.x * (PositionB.posit.x - PositionA.posit.x) + PositionA.right.z * (PositionB.posit.z - PositionA.posit.z)) > 0.0f;
}

// Get Vector from a Path point: By Nielk1/Ken Miller.
Vector GetVectorFromPath(const char* path, const int point)
{
	// New code from Ken Miller.
	Vector retVal(0, 0, 0);
	size_t bufSize = 0;

	if (path)
		GetPathPoints(path, bufSize, NULL);

	// Bad Path, abort!
	if(!bufSize)
		return retVal;

	if(point < int(bufSize))
	{
		float *pData = static_cast<float *>(_alloca(sizeof(float) * 2 * bufSize));
		if(GetPathPoints(path, bufSize, pData)) 
			retVal = Vector(pData[2*point+0], TerrainFindFloor(pData[2*point+0], pData[2*point+1]), pData[2*point+1]); 
	}

	return retVal;
}

// Center of the map's "edge_path" bounding box, on the terrain. (0, floor, 0) when the path has fewer than two points.
Vector GetCenterOfMap()
{
	Vector Center(0, 0, 0);
	float MinX = 0.0f, MinZ = 0.0f, MaxX = 0.0f, MaxZ = 0.0f;
	size_t bufSize = 0;

	GetPathPoints("edge_path", bufSize, NULL);
	float *pData = static_cast<float *>(_alloca(sizeof(float) * 2 * bufSize));
	if ((GetPathPoints("edge_path", bufSize, pData)) && (bufSize > 1))
	{
		float LowX = FLT_MAX, LowZ = FLT_MAX, HighX = -FLT_MAX, HighZ = -FLT_MAX;
		for (size_t i = 0; i < bufSize; ++i)
		{
			const float x = pData[2 * i + 0];
			const float z = pData[2 * i + 1];
			if (x < LowX)
				LowX = x;
			if (z < LowZ)
				LowZ = z;
			if (x > HighX)
				HighX = x;
			if (z > HighZ)
				HighZ = z;
		}
		MinX = LowX;
		MinZ = LowZ;
		MaxX = HighX;
		MaxZ = HighZ;
	}

	Center.x = (MinX + MaxX) * 0.5f;
	Center.z = (MinZ + MaxZ) * 0.5f;
	Center.y = TerrainFindFloor(Center.x, Center.z);
	return Center;
}

// Gets a random Team, with teamfilter options.
// GBD: the SkipTeamZero clause is AND-ed with the rest (the 2015 OR let any team > 0 through), base-slot items need only be non-zero, and the
// search wraps through team 15.
int GetRandomTeam(const int TeamFilter, const int Team, const bool ActiveTeamsOnly, const bool SkipTeamZero)
{
	const int TempTeamFilter = TeamFilter ? TeamFilter : -1;

	int Start = GetRandomInt(MAX_TEAMS-1);
	int x = Start;
	do
	{
		if(((Team < 0) || (TeamFilterCheck(TempTeamFilter, x, Team))) && // Team matches.
			((!ActiveTeamsOnly) || ( // ActiveTeamOnly, If they have any BaseSlot 1 - 9 items, or a Player.
			(GetPlayerHandle(x)) || 
			(GetObjectByTeamSlot(x, DLL_TEAM_SLOT_RECYCLER)) || 
			(GetObjectByTeamSlot(x, DLL_TEAM_SLOT_FACTORY)) || 
			(GetObjectByTeamSlot(x, DLL_TEAM_SLOT_ARMORY)) || 
			(GetObjectByTeamSlot(x, DLL_TEAM_SLOT_BASE4)) || 
			(GetObjectByTeamSlot(x, DLL_TEAM_SLOT_BASE5)) || 
			(GetObjectByTeamSlot(x, DLL_TEAM_SLOT_BASE6)) || 
			(GetObjectByTeamSlot(x, DLL_TEAM_SLOT_BASE7)) || 
			(GetObjectByTeamSlot(x, DLL_TEAM_SLOT_BASE8)) || 
			(GetObjectByTeamSlot(x, DLL_TEAM_SLOT_BASE9)))) && 
			((!SkipTeamZero) || (x > 0))) // SkipTeamZero matches.
		{
			return x;
		}
		++x;
		if (x >= MAX_TEAMS)
			x = 0;
	}
	while (x != Start);

	return -1; // Didn't find anything.
}

// Alternate PointInPoly code Ken Miller found online: http://geomalgorithms.com/a03-_inclusion.html
// Ken's LUA Implementation: http://pastebin.com/nhtkYEpN
int GetWindingNumber(const std::vector<VECTOR_2D> &areaPath, const Vector &vector)
{
	int wn = 0; // the  winding number counter.
	int numOfSides = int(areaPath.size());

	// Iterate through each line.
	for (int i = 0, j = 1; i < numOfSides; i++, j++)
	{
		if (j >= numOfSides)
			j = 0;

		if (areaPath[i].z <= vector.z) // start z <= Vector.z
		{
			if ((areaPath[j].z > vector.z) && (IsLeftOnRight(areaPath[i], areaPath[j], vector) > 0))  // An upward crossing and Vector left of  edge.
				++wn; // have  a valid up intersect
		}
		else // start z > Vector.z (no test needed)
		{
			if ((areaPath[j].z <= vector.z) && (IsLeftOnRight(areaPath[i], areaPath[j], vector) < 0)) // A downward crossing and Vector right of  edge.
				--wn; // have  a valid down intersect
		}
	}

	return wn;
}

// Version that takes a Path Name.
int GetWindingNumber(const char* path, const Vector vector)
{
	size_t bufSize = 0;

	if (path)
		GetPathPoints(path, bufSize, NULL);

	// Bad Path, abort!
	if (!bufSize)
		return 0;

	std::vector<VECTOR_2D> areaPath;
	areaPath.clear();

	float *pData = static_cast<float *>(_alloca(sizeof(float) * 2 * bufSize));
	if (GetPathPoints(path, bufSize, pData))
	{
		for (size_t i = 0; i < bufSize; ++i)
		{
			VECTOR_2D newPoint; // does this need to be a pointer?
			newPoint.x = pData[2 * i + 0];
			newPoint.z = pData[2 * i + 1];
			areaPath.push_back(newPoint);
		}
	}

	return GetWindingNumber(areaPath, vector);
}

// Checks if a pathpoint exists. Returns the number of points in the path.
int DoesPathExist(const char* path)
{
	size_t bufSize = 0;
	if (path)
		GetPathPoints(path, bufSize, NULL);

	return int(bufSize);
}

// IsInfo that uses a handle. No need to know exact ODF name :) // ancestor; not in the shipped binary
bool IsInfo(const Handle h)
{
	char ODFName[MAX_ODF_LENGTH] = { 0 };
	if (!GetODFName(h, ODFName))
		return false;

	return IsInfo(ODFName); //GetLocalUserInspectHandle() == h
}

// Is something following something? // ancestor; not in the shipped binary
bool IsFollowing(const Handle me, const Handle him)
{
	if (!IsAround(him)) // IsAround(me) checked by WhoFollowing. :)
		return false;

	return WhoFollowing(me) == him;
}

// Determines if the Handle is damaged beyond the threshold. // ancestor; not in the shipped binary
bool IsDamaged(const Handle h, const float Threshold)
{
	if(!IsAround(h))
		return false; // Invalid Handle.

	return GetHealth(h) < Threshold;
}

// Checks if a handle is done going down a path. // ancestor; not in the shipped binary
bool IsFinishedWithPath(const Handle h, const char* path)
{
	if(!IsAround(h))
		return false;

	size_t bufSize = 0;
	GetPathPoints(path, bufSize, NULL);

	Handle me = h; // the SDK's path-distance overload takes the handle by reference
	return bufSize > 0 && GetDistance(me, path, int(bufSize)) < 12.0f; //5.0f;
}

// Command a unit to Recycle. // ancestor; not in the shipped binary
void Recycle(const Handle h, const int priority)
{
	SetCommand(h, CMD_RECYCLE, 1, priority);
}

// Finds out if a handle needs Health. // ancestor; not in the shipped binary
bool NeedsHealth(const Handle h)
{
	if(!IsAround(h))
		return false;

	return GetCurHealth(h) < GetMaxHealth(h);
}

// Finds out if a handle needs Ammo. // ancestor; not in the shipped binary
bool NeedsAmmo(const Handle h)
{
	if(!IsAround(h))
		return false;

	return GetMaxAmmo(h) < GetCurAmmo(h);
}

// Gets the current percentage of scrap inside the scavenger. // ancestor; not in the shipped binary
float GetScavengerScrap(const Handle h)
{
	int MaxScrap = GetScavengerMaxScrap(h);
	if (MaxScrap <= 0)
		return -1.0f; // Not a Scavvy Thing.

	return float(GetScavengerCurScrap(h) / MaxScrap);
}
// Sets the current percentage of scrap in a Scav. // ancestor; not in the shipped binary
void SetScavengerScrap(const Handle h, const float Percent)
{
	int MaxScrap = GetScavengerMaxScrap(h);
	if (MaxScrap <= 0)
		return; // Not a Scavvy Thing.

	float NewP = clamp(Percent, 0.0f, 1.0f);
	SetScavengerCurScrap(h, int(MaxScrap * NewP));
}

// Parellel to GetHealth, Sets the health as a % of MaxHealth. // ancestor; not in the shipped binary
void SetHealth(const Handle h, const float Percent)
{
	long Health = GetMaxHealth(h);

	if (Health == INVALID_VALUE)
		return; // Invalid Handle, bail.

	float TempP = clamp(Percent, 0.0f, 1.0f);
	SetCurHealth(h, long(Health * TempP));
}

// Parellel to GetAmmo, Sets the ammo as a % of MaxAmmo.
void SetAmmo(const Handle h, const float Percent)
{
	long Ammo = GetMaxAmmo(h);

	if (Ammo == INVALID_VALUE)
		return; // Invalid Handle, bail.

	float TempP = clamp(Percent, 0.0f, 1.0f);
	SetCurAmmo(h, long(Ammo * TempP));
}

// Version of GiveWeapon that utilizes ReplaceWeapon to only switch out one slot.
// GBD: an empty name falls through to the engine's slot GiveWeapon; a weaponAssault# slot gets the weapon's assault twin (altName) when the
// weapon itself is not an assault one; returns whether anything was replaced.
bool GiveWeapon(const Handle h, const char* Weapon, const int Slot)
{
	if (Weapon[0] == '\0')
	{
		GiveWeapon(h, Slot, Weapon);
		return true;
	}

	if(!DoesODFExist(Weapon))
	{
		FormatLogMessage("ERROR: Weapon ODF '%s' doesn't exist! Fix DLL's GiveWeapon() call!", Weapon);
		return false;
	}

	float LocalAmmo[MAX_HARDPOINTS] = {0};
	char Weapons[MAX_HARDPOINTS][MAX_ODF_LENGTH] = {0};

	// Pick the variant that fits this hardpoint.
	bool WeaponAssault = false;
	char TempWeapon[MAX_ODF_LENGTH] = {0};
	CombineStrings(TempWeapon, "", Weapon);
	char DesiredValue[MAX_ODF_LENGTH] = {0};
	sprintf_s(DesiredValue, "weaponAssault%d", Slot + 1);
	GetODFBool(h, "GameObjectClass", DesiredValue, &WeaponAssault, false);
	if (WeaponAssault)
	{
		bool IsAssault = false;
		GetODFBool(TempWeapon, NULL, "WeaponClass", "isAssault", &IsAssault, false);
		if (!IsAssault)
		{
			char AltName[MAX_ODF_LENGTH] = {0};
			if (GetODFString(TempWeapon, NULL, "WeaponClass", "altName", MAX_ODF_LENGTH, AltName))
			{
				bool AltAssault = false;
				GetODFBool(AltName, NULL, "WeaponClass", "isAssault", &AltAssault, false);
				if (AltAssault)
					CombineStrings(TempWeapon, "", AltName);
			}
		}
	}

	for(int i = 0; i < MAX_HARDPOINTS; i++)
	{
		if (!GetObjInfo(h, ObjectInfoType(Get_Weapon0Config+i), Weapons[i]))
			return false;
		LocalAmmo[i] = GetCurLocalAmmo(h, i);
	}

	if (_stricmp(Weapons[Slot], TempWeapon) != 0)
	{
		LocalAmmo[Slot] = 0;
		CombineStrings(Weapons[Slot], "", TempWeapon);
		return ReplaceWeapons(h, Weapons, LocalAmmo);
	}

	return false;
}

// Triggers a BZC Production Unit to Undeploy, if possible. // ancestor; not in the shipped binary
void PackUp(const Handle h)
{
	if(!IsAround(h))
		return;

	int Team = GetTeamNum(h);

	// Loop through all 9 Base Slots, find the one that matches this undeploy item.
	for(int x = 0; x < 9; x++)
	{
		int i = x+1;
		if(x>2)
			i = x+6;

		if(GetObjectByTeamSlot(Team, i) == h)
		{
			char DesiredValue[MAX_ODF_LENGTH] = {0};
			sprintf_s(DesiredValue, "BZCundep%d", x+1);
			BuildObject(DesiredValue, Team, h);
			return; // We found it.
		}
	}
}

// Base slot 1-9 of a team: slots 1-3 are the recycler / factory / armory, 4-9 map onto DLL_TEAM_SLOT_BASE4..9.
Handle GetObjectByBaseSlot(const int Team, const int Slot)
{
	if ((Slot < 1) || (Slot > MAX_BASE_SLOTS) || (Team < 0) || (Team >= MAX_TEAMS))
		return 0;

	int i = Slot;
	if (Slot >= 4)
		i = Slot + 5;

	return GetObjectByTeamSlot(Team, i);
}

// Gets the number of Taps a handle has, optionally excluding invulnerable ones. (The AddObject path is folded out of the image: no shipped caller sets it.)
int GetTapCount(const Handle h, const bool IgnoreInvincible, const bool AddObject)
{
	int Taps = 0;
	for (int x = 0; x < MAX_TAPS; x++)
	{
		Handle TempTap = GetTap(h, x);
		if (!AddObject)
		{
			if ((TempTap) && ((!IgnoreInvincible) || (GetMaxHealth(TempTap) > 0)))
				++Taps;
		}
		else
		{
			// Special note: It appears AddObject adds a dummy tap to the end of the tap list. This was causing if(TapH) to pass true and save an invalid thing. -GBD
			//	if(TapH) // BAD! Returns true for a second (dummy?) handle of ffffffff (or -1)???? Unsafe. Used ODFName existance to verify tap reality. -GBD
			char TapODFName[MAX_ODF_LENGTH] = { 0 };
			GetObjInfo(TempTap, Get_ODF, TapODFName);
			if (TapODFName[0])
				++Taps;
		}
	}
	return Taps;
}

// Counts the powerTap# entries of a building ODF (zero unless the ODF is a building and PoweredByTaps).
int GetTapCount(const char* filename1, const char* filename2)
{
	int Taps = 0;
	if (IsBuilding(filename1))
	{
		bool PoweredByTaps = true;
		if (!GetODFBool(filename1, filename2, "PoweredBuildingClass", "PoweredByTaps", &PoweredByTaps, true))
			GetODFBool(filename1, filename2, "TurretCraftClass", "PoweredByTaps", &PoweredByTaps, true);

		if (PoweredByTaps)
		{
			for (int x = 0; x < MAX_TAPS; x++)
			{
				char DesiredValue[MAX_ODF_LENGTH] = { 0 };
				char TapName[MAX_ODF_LENGTH] = { 0 };
				sprintf_s(DesiredValue, "powerTap%d", x + 1);
				if ((GetODFString(filename1, filename2, "PoweredBuildingClass", DesiredValue, MAX_ODF_LENGTH, TapName)) ||
					(GetODFString(filename1, filename2, "TurretCraftClass", DesiredValue, MAX_ODF_LENGTH, TapName)))
					++Taps;
			}
		}
	}
	return Taps;
}

// Gives an object a random heading, keeping its position.
void SetRandomHeadingAngle2(const Handle h)
{
	Matrix Position = Build_Yaw_Matrix(GetRandomFloat(PI * 2.0f));
	Position.posit = GetPosition(h);
	SetPosition(h, Position);
	SetVectorPosition(h, Position.posit);
}

// Determine TeamFilter passing.
bool TeamFilterCheck(const int TeamFilter, const int Team1, const int Team2)
{
	if(Team1 < 0 || Team1 > 15 || Team2 < 0 || Team2 > 15)
		return false;

	return ((((TeamFilter & 1) == 1) && Team1 == Team2) ||  // Same Team Only
			((Team1 != Team2) && // Not same Team.
			((((TeamFilter & 2) == 2) && (IsTeamAllied(Team1, Team2))) ||  // Allies Only
			(((TeamFilter & 4) == 4) && (!IsTeamAllied(Team1, Team2))))));  // Enemies Only
}

// Sets the position of an object to the position of another object. // ancestor; the shipped binary inlines it from the header.
// (kept inline in bzcscriptutils.h)

// Adds to the total of the Scavenger's current scrap. // ancestor; not in the shipped binary
void AddScavengerCurScrap(const Handle h, const int aNewScrap)
{
	if((!IsAround(h)) || (!IsScavenger(h)))
		return;

	int ScavScrap = GetScavengerCurScrap(h);
	ScavScrap += aNewScrap;
	SetScavengerCurScrap(h, ScavScrap);
}

// Adds to the total of the Scavengers max's scrap. // ancestor; not in the shipped binary
void AddScavengerMaxScrap(const Handle h, const int aNewScrap)
{
	if((!IsAround(h)) || (!IsScavenger(h)))
		return;

	int ScavScrap = GetScavengerMaxScrap(h);
	ScavScrap += aNewScrap;
	SetScavengerMaxScrap(h, ScavScrap);
}

// Generates an artifical scrap field. :) // ancestor; not in the shipped binary
void SpawnScrapField(const Vector Pos, const int Amount, const float Radius, const char Race)
{
	if(IsNullVector(Pos))
		return;

	// Randomize the scrap.
	char ScrapODF[MAX_ODF_LENGTH] = {0};
	float MaxDist = 10.0f * sqrtf(float(Amount));

	if(Radius > 0) // If there is a specified radius, use that.
		MaxDist = Radius;

	for(int i = 0; i < Amount; i++)
	{
		sprintf_s(ScrapODF, "%cpscr%d", Race, GetRandomInt(2)+1);
		BuildObject(ScrapODF, 0, Build_Directinal_Matrix(GetPositionNear(Pos, 0, MaxDist), HRotateFront(Vector(0.0f, 0.0f, 1.0f), GetRandomFloat(360.0f) * DEG_2_RAD)));
	}
}

// Gets the EngageRange of a handle.
float GetEngageRange(const Handle h)
{
	if(!IsAround(h))
		return 0;

	float TempVal = 0.0f;

	if((GetODFFloat(h, "CraftClass", "EngageRange", &TempVal, 0.0f)) || 
		(GetODFFloat(h, "CraftClass", "RangeScan", &TempVal, 200.0f))) // || (GetODFFloat(h, "PoweredBuildingClass", "detectRange", &TempVal, 100.0f)))
	{
		// Got it.
	}
	else // Not specified, go into Weapons and compare ranges. Choose the highest one.
	{
		char WeaponODF[MAX_ODF_LENGTH] = {0};
		char OrdODF[MAX_ODF_LENGTH] = {0};
		char DesiredValue[MAX_ODF_LENGTH] = {0};
		for(int i = 0; i < MAX_HARDPOINTS; i++)
		{
			float TestVal = 0.0f;
			sprintf_s(DesiredValue, "weaponName%d", i+1);
			if((GetODFString(h, "GameObjectClass", DesiredValue, MAX_ODF_LENGTH, WeaponODF)) && (WeaponODF[0]))
			{
				CombineStrings(WeaponODF, WeaponODF, ".odf"); // Add .odf to the end.
				if(OpenODF2(WeaponODF))
				{
					if(GetODFFloat(WeaponODF, NULL, "WeaponClass", "aiRange", &TestVal))
					{
						// Got it.
					}
					else if(GetODFString(WeaponODF, NULL, "WeaponClass", "ordName", MAX_ODF_LENGTH, OrdODF))
					{
						CombineStrings(OrdODF, OrdODF, ".odf"); // Add .odf to the end.
						if(OpenODF2(OrdODF))
						{
							float ShotSpeed = 0.0f;
							float LifeSpan = 0.0f;
							GetODFFloat(OrdODF, NULL, "OrdnanceClass", "shotSpeed", &ShotSpeed);
							GetODFFloat(OrdODF, NULL, "OrdnanceClass", "lifeSpan", &LifeSpan);

							TestVal = ShotSpeed * LifeSpan;
						}
					}
				}
			}
			if(TestVal > TempVal)
				TempVal = TestVal;
		}
	}
	return TempVal;
}

// Gets the minimum amount of ammo needed to fire an AI's Weapons.
long GetMinFireAmmo(const Handle h)
{
	if(!IsAround(h))
		return 0;

	long MinFireAmmo = 0;

	char WeaponMask[MAX_HARDPOINTS+1] = {0};
	GetODFString(h, "GameObjectClass", "weaponMask", MAX_HARDPOINTS+1, WeaponMask, "11111"); // GBD: defaults to all on.

	// Loop over all weapons, if they're set in weaponMask, add their required ammo together.
	for(int i = 0; i < MAX_HARDPOINTS; i++)
	{
		bool WeaponMasks = (WeaponMask[4-i] != '0'); // A function to GetWeaponMask(h) would be nice. 
		if(WeaponMasks)
		{
			char WeaponODF[MAX_ODF_LENGTH] = {0};
			GetObjInfo(h, ObjectInfoType(Get_Weapon0ODF+i), WeaponODF);

			if((WeaponODF[0]) && (OpenODF2(WeaponODF)))
			{
				char TempODF2[MAX_ODF_LENGTH] = {0};
				char TempClassString[MAX_ODF_LENGTH] = {0};
				if(GetODFString(WeaponODF, "GameObjectClass", "classlabel", MAX_ODF_LENGTH, TempClassString))
				{
					CombineStrings(TempODF2, TempClassString, ".odf"); // Add .odf to the end.
					if(!OpenODF2(TempODF2))
						TempODF2[0] = '\0';
				}

				char TempODF3[MAX_ODF_LENGTH] = {0};
				if((GetODFString(WeaponODF, TempODF2, "WeaponClass", "ordName", MAX_ODF_LENGTH, TempODF3)) || 
					(GetODFString(WeaponODF, TempODF2, "DispenserClass", "objectClass", MAX_ODF_LENGTH, TempODF3)) || 
					(GetODFString(WeaponODF, TempODF2, "TorpedoLauncherClass", "objectClass", MAX_ODF_LENGTH, TempODF3)))
				{
					// Got it.
				}

				if(TempODF3[0])
				{
					CombineStrings(TempODF3, TempODF3, ".odf"); // Add .odf to the end.
					long TempAmmoCost = 0;
					if(GetODFLong(TempODF3, NULL, "OrdnanceClass", "ammoCost", &TempAmmoCost)) // GBD: the two-file getter opens and inherits by itself.
						MinFireAmmo += TempAmmoCost;
				}
			}
		}
	}

	return MinFireAmmo;
}

// Gets the damage an ordnance should do to the specified handle.
// GBD: classes are compared upper-cased, the ordnance classlabel is read from [OrdnanceClass], the explosion's damage from [ExplosionClass].
long GetOrdnanceDamageDealt(const Handle h, const char *OrdnanceODF, const bool UseExplosion)
{
	if(!IsAround(h))
		return -1; // Return invalid.

	long Damage = 0;

	char TempODF[MAX_ODF_LENGTH] = {0};
	char TempODF2[MAX_ODF_LENGTH] = {0};

	int ArmorClass = 78; // N = 78, n = 110, L = 76, l = 108, H = 72, h = 104
	int ShieldClass = 0; // A = 65, a = 97, D = 68, d = 100, S = 83, s = 115
	// Get it's Armor class for later use.
	char TempArmorClass = 0;
	GetODFChar(h, "GameObjectClass", "armorClass", &TempArmorClass, 'N');
	ArmorClass = toupper(TempArmorClass);

	for(int i = 0; i < MAX_HARDPOINTS; i++)
	{
		char HostWeaponClass[MAX_ODF_LENGTH] = {0};
		GetObjInfo(h, ObjectInfoType(Get_Weapon0GOClass+i), HostWeaponClass);

		if(_stricmp(HostWeaponClass,"CLASS_SHIELDUP") == 0)
		{
			char HostWeapon[MAX_ODF_LENGTH] = {0};
			GetObjInfo(h, ObjectInfoType(Get_Weapon0ODF+i), HostWeapon);

			char TempShieldClass = 0;
			GetODFChar(HostWeapon, NULL, "ShieldUpgradeClass", "shieldClass", &TempShieldClass, 'S'); // Grab the value.
			ShieldClass = toupper(TempShieldClass);

			break;
		}
	} // Shield Check.

	char ExplosionODF[MAX_ODF_LENGTH] = {0}; // A place to store our desired variable. 
	CombineStrings(TempODF, "", OrdnanceODF);
	if(OpenODF2(TempODF))
	{
		char TempClassString[MAX_ODF_LENGTH] = {0};
		if(GetODFString(TempODF, "OrdnanceClass", "classlabel", MAX_ODF_LENGTH, TempClassString))
		{
			CombineStrings(TempODF2, TempClassString, ".odf");
			if(!OpenODF2(TempODF2))
				TempODF2[0] = '\0';
		}

		int RealDamage = 0;
		int xplRealDamage = 0;

		char DesiredValue[MAX_ODF_LENGTH] = {0};
		char ExplosionType[MAX_ODF_LENGTH] = {0};

		// A shield class takes precedence over the armor class.
		const int DamageClass = ShieldClass ? ShieldClass : ArmorClass;
		if(DamageClass == 'A')
			strcpy_s(DesiredValue, "damageValue(A)");
		else if(DamageClass == 'D')
			strcpy_s(DesiredValue, "damageValue(D)");
		else if(DamageClass == 'H')
			strcpy_s(DesiredValue, "damageValue(H)");
		else if(DamageClass == 'L')
			strcpy_s(DesiredValue, "damageValue(L)");
		else if(DamageClass == 'S')
			strcpy_s(DesiredValue, "damageValue(S)");
		else
			strcpy_s(DesiredValue, "damageValue(N)");

		// Retrieve Damage Values here.
		GetODFInt(TempODF, TempODF2, "OrdnanceClass", DesiredValue, &RealDamage);

		if(UseExplosion)
		{
			// Pull Explosion ODF Damage, and include it.
			if(IsBuilding(h))
				strcpy_s(ExplosionType, "xplBuilding");
			else
				strcpy_s(ExplosionType, "xplVehicle");

			if(GetODFString(TempODF, TempODF2, "OrdnanceClass", ExplosionType, MAX_ODF_LENGTH, ExplosionODF))
			{
				CombineStrings(ExplosionODF, ExplosionODF, ".odf");
				if(OpenODF2(ExplosionODF))
					GetODFInt(ExplosionODF, NULL, "ExplosionClass", DesiredValue, &xplRealDamage);
			}

			// Combine the damage types.
			Damage = RealDamage + xplRealDamage;
		}
	}
	return Damage;
}

// Gets a Matrix based off an ODF Position Offset, and ODF Rotation Offset. GBD: the rotation key is RotationOffset# (2015 read AddRotation#).
Matrix GetODFPositionOffset(const Handle h, const int Index, const Vector AddPosition, const Vector AddRotation)
{
	if(!IsAround(h))
		return Identity_Matrix;

	Vector Position(0, 0, 0);
	char DesiredValue[MAX_ODF_LENGTH] = {0};
	sprintf_s(DesiredValue, "PositionOffset%d", Index+1);
	GetODFVector(h, "GameObjectClass", DesiredValue, &Position);
	Position = Add_Vectors(Position, AddPosition);

	Vector Rotation(0, 0, 0);
	sprintf_s(DesiredValue, "RotationOffset%d", Index+1);
	GetODFVector(h, "GameObjectClass", DesiredValue, &Rotation);
	Rotation = Add_Vectors(Rotation, AddRotation);
	Rotation = Vector_Scale(Rotation, DEG_2_RAD);

	const Matrix BaseMat = GetMatrixPosition(h);
	const Matrix LocalMat = Build_Position_Rotation_Matrix(Rotation.x, Rotation.y, Rotation.z, Position);
	const Matrix WorldMat = Matrix_Multiply(LocalMat, BaseMat);
	return WorldMat;
}

// Gets a Vector further away from v1 then v2, with min/max radius's.
Vector GetPositionNearOrFar(const Vector v1, const Vector v2, const float MinRadius, const float MaxRadius, const bool Near)
{
	Vector v3 = GetPositionNear(v2, MinRadius, MaxRadius);

	if(v1 != v2)
	{
		Vector dir = Normalize_Vector(v1 - v2);
		float alongDir = Dot_Product(v3 - v2, dir);

		if((alongDir > 0) ^ Near)
		{
			v3 = Add_Mult_Vectors(v3, dir, -2.0f * alongDir);
			v3.y = TerrainFindFloor(v3.x, v3.z); // Recompute terrain height.
		}
	}
	return v3; //Go directly to Jail, Do not pass Go, Do not collect $200.
}

// Conforms an ODFName retrieved with Get_CFG to cutoff the :## appended to it if it was built by a factory. Also removes the . if there's a .odf attached.
void CheckODFName(char *ODFName)
{
	if (!ODFName)
		return; // Null pointer, bad. return! return!

	if (!DoesODFExist(ODFName))
	{
		if (char *dot = strchr(ODFName, ':'))
			*dot = '\0';

		if (!DoesODFExist(ODFName))
		{
			if (char *dot = strrchr(ODFName, '.'))
				*dot = '\0';
		}
	}
}

// Gets the unit's Name, without the Skill modifier " ****" applied. // ancestor; not in the shipped binary
char TempGetUnitName[MAX_NAME_LENGTH];
const char *GetUnitName(const Handle h)
{
	 strcpy_s(TempGetUnitName, GetObjectiveName(h));
	// Step through backwards, removing any previous skill level " ****" on the end of the name. Code from Ken.
	size_t len = strlen(TempGetUnitName)-1;
	for (size_t pos = len; pos > 0; --pos)
	{
		if (TempGetUnitName[pos] != '*')
		{
			if (pos < len && TempGetUnitName[pos] == ' ')
			{
				TempGetUnitName[pos] = '\0';
				len = pos;
			}
			break;
		}
	}

	return TempGetUnitName;
}
// Applies the Skill Name to the unit's name. // ancestor; not in the shipped binary
void SetSkillName(const Handle h, const int Skill)
{
	int CurSkill = Skill;

	if(Skill < 0)
		CurSkill = GetSkill(h);

	if(CurSkill <= 0)
		return; // Don't bother

	char UnitName[MAX_ODF_LENGTH] = {0};
	strcpy_s(UnitName, GetUnitName(h));
	// If our length is long enough, add the " ****" to the end. If it's not, don't do anything. Code from Ken.
	if(!IsPlayer(h))
	{
		size_t len = strlen(UnitName)-1;
		if((len + 1 + CurSkill + 1) < MAX_ODF_LENGTH)
		{
			UnitName[++len] = ' ';
			for (int i = 0; i < CurSkill; ++i)
				UnitName[++len] = '*';
			UnitName[++len] = '\0';
		}
	}

	SetObjectiveName(h, UnitName); // Update the name.
}

// Attempts to play a VO msg from a unit's [CraftClass] section.
void PlayVOMsg(const Handle h, const char *MsgString, const int Team)
{
	if((!IsAround(h)) || (!MsgString))
		return;

	const int TempTeam = Team == -1 ? GetTeamNum(h) : Team;

	// Play user2Msg, if possible.
	if(TempTeam == GetLocalPlayerTeamNumber())
	{
		char MsgSound[MAX_ODF_LENGTH] = {0};
		if(GetODFString(h, "CraftClass", MsgString, MAX_ODF_LENGTH, MsgSound))
		{
			if(MsgSound[0])
				AudioMessage(MsgSound);
		}
	}

}

// Plays EVENT_SOUND_<Event> of the race's event ODF ("<race>event.odf", falling back to aevent.odf) from its [BettyVoice] block.
// (Team is reconstructed: the shipped body never reads it.)
void PlayEventVO(const char Race, const int Event, const int /*Team*/)
{
	char EventODF[MAX_ODF_LENGTH] = {0};
	char Sound[MAX_ODF_LENGTH] = {0};
	sprintf_s(EventODF, "%cevent.odf", Race);
	if (!DoesFileExist(EventODF))
		strcpy_s(EventODF, "aevent.odf");

	char DesiredValue[MAX_ODF_LENGTH] = {0};
	sprintf_s(DesiredValue, "EVENT_SOUND_%d", Event);

	if (OpenODF2(EventODF))
	{
		if ((GetODFString(EventODF, "BettyVoice", DesiredValue, MAX_ODF_LENGTH, Sound)) && (Sound[0]))
		{
			if (DoesFileExist(Sound))
				AudioMessage(Sound);
			else
				FormatLogMessage("ERROR: Sound file: '%s' doesn't exist! Fix %s in ODF: '%s'", Sound, DesiredValue, EventODF);
		}
	}
}

// Generalized Class Filters. The engine's IsBuilding(Handle) / IsCraftButNotPerson(Handle) / IsPowerup(Handle) carry the broad tests now;
// these refine them. ObjClassHash is the FNV-1a hash of Get_GOClass, read here when 0.

// Is it a Building, or a Gun Tower (CLASS_TURRET)? Misc and Weapon classes never are.
bool IsBuildingOrGunTower(const Handle h, const int ObjClassHash)
{
	int ClassHash = ObjClassHash;
	if (ClassHash == 0)
	{
		char ObjClass[MAX_ODF_LENGTH] = {0};
		if(!GetObjInfo(h, Get_GOClass, ObjClass))
			return false;

		ClassHash = int(Hash(ObjClass));
	}

	if ((IsBuilding(h)) || (ClassHash == CLASS_TURRET))
	{
		for(int i = 0; i < sizeof(MiscClass)/sizeof(MiscClass[0]); i++)
			if(ClassHash == MiscClass[i])
				return false;

		for(int i = 0; i < sizeof(WeaponClass)/sizeof(WeaponClass[0]); i++)
			if(ClassHash == WeaponClass[i])
				return false;

		return true;
	}

	return false;
}

// Is it a Craft? (Excludes CLASS_TURRET gun towers.)
bool IsCraft(const Handle h, const int ObjClassHash)
{
	if (ObjClassHash == 0)
	{
		char ObjClass[MAX_ODF_LENGTH] = {0};
		if(!GetObjInfo(h, Get_GOClass, ObjClass))
			return false;

		return (IsCraftButNotPerson(h)) && (_stricmp(ObjClass, "CLASS_TURRET") != 0);
	}

	return (IsCraftButNotPerson(h)) && (ObjClassHash != CLASS_TURRET);
}

// Is it a Weapon?
bool IsWeapon(const Handle h, const int ObjClassHash)
{
	int ClassHash = ObjClassHash;
	if (ClassHash == 0)
	{
		char ObjClass[MAX_ODF_LENGTH] = {0};
		if(!GetObjInfo(h, Get_GOClass, ObjClass))
			return false;

		ClassHash = int(Hash(ObjClass));
	}

	for(int i = 0; i < sizeof(WeaponClass)/sizeof(WeaponClass[0]); i++)
		if(ClassHash == WeaponClass[i])
			return true;

	return false;
}

// Is it something else?
bool IsMisc(const Handle h, const int ObjClassHash)
{
	int ClassHash = ObjClassHash;
	if (ClassHash == 0)
	{
		char ObjClass[MAX_ODF_LENGTH] = {0};
		if(!GetObjInfo(h, Get_GOClass, ObjClass))
			return false;

		ClassHash = int(Hash(ObjClass));
	}

	for(int i = 0; i < sizeof(MiscClass)/sizeof(MiscClass[0]); i++)
		if(ClassHash == MiscClass[i])
			return true;

	return false;
}

// Test for common types. // ancestor; not in the shipped binary (through IsSilo)
// Is it a scrap?
bool IsScrap(const Handle h)
{
	char ObjClass[MAX_ODF_LENGTH] = {0};
	if(!GetObjInfo(h, Get_GOClass, ObjClass))
		return false;

	return (_stricmp(ObjClass, "CLASS_SCRAP") == 0);
}
// Is it a turret? (Tank kind, not GunTower kind)
bool IsTurret(const Handle h)
{
	char ObjClass[MAX_ODF_LENGTH] = {0};
	if(!GetObjInfo(h, Get_GOClass, ObjClass))
		return false;

	return (_stricmp(ObjClass, "CLASS_TURRETTANK") == 0);
}
// Is it a scavenger?
bool IsScavenger(const Handle h)
{
	char ObjClass[MAX_ODF_LENGTH] = {0};
	if(!GetObjInfo(h, Get_GOClass, ObjClass))
		return false;

	char BZCClass[MAX_ODF_LENGTH] = {0};
	GetODFString(h, "GameObjectClass", "BZCClasslabel", MAX_ODF_LENGTH, BZCClass);
	unsigned int BZCClassHash = Hash(BZCClass);

	return ((_stricmp(ObjClass, "CLASS_SCAVENGER") == 0) || (_stricmp(ObjClass, "CLASS_SCAVENGERH") == 0)) && // Is a Scav
		(BZCClassHash != BZCCLASS_RECYCLER) && (BZCClassHash != BZCCLASS_FACTORY) && (BZCClassHash != BZCCLASS_ARMORY); // Is NOT a BZC Production unit.
}
// Is it a barracks?
bool IsBarracks(const Handle h)
{
	char ObjClass[MAX_ODF_LENGTH] = {0};
	if(!GetObjInfo(h, Get_GOClass, ObjClass))
		return false;

	return (_stricmp(ObjClass, "CLASS_BARRACKS") == 0);
}
// Is it a gun tower? (The Turret kind)
bool IsGunTower(const Handle h)
{
	char ObjClass[MAX_ODF_LENGTH] = {0};
	if(!GetObjInfo(h, Get_GOClass, ObjClass))
		return false;

	return (_stricmp(ObjClass, "CLASS_TURRET") == 0);
}
// Is it a Geyser/Pool?
bool IsGeyser(const Handle h)
{
	char ObjClass[MAX_ODF_LENGTH] = {0};
	if(!GetObjInfo(h, Get_GOClass, ObjClass))
		return false;

	return (_stricmp(ObjClass, "CLASS_DEPOSIT") == 0);
}
// Is it a Spawnpoint?
bool IsSpawnPoint(const Handle h)
{
	char ObjClass[MAX_ODF_LENGTH] = {0};
	if(!GetObjInfo(h, Get_GOClass, ObjClass))
		return false;

	return (_stricmp(ObjClass, "CLASS_SPAWNBUOY") == 0);
}
// Is it a Silo/Extractor?
bool IsSilo(const Handle h)
{
	char ObjClass[MAX_ODF_LENGTH] = {0};
	if(!GetObjInfo(h, Get_GOClass, ObjClass))
		return false;

	return (_stricmp(ObjClass, "CLASS_SILO") == 0) || (_stricmp(ObjClass, "CLASS_EXTRACTOR") == 0);
}
// Is it a Factory?
bool IsFactory(const Handle h)
{
	char ObjClass[MAX_ODF_LENGTH] = {0};
	if(!GetObjInfo(h, Get_GOClass, ObjClass))
		return false;

	char BZCClass[MAX_ODF_LENGTH] = {0};
	GetODFString(h, "GameObjectClass", "BZCClasslabel", MAX_ODF_LENGTH, BZCClass);

	return (_stricmp(ObjClass, "CLASS_FACTORY") == 0) || (_stricmp(BZCClass, "muf") == 0); // Look for Factory
}
// Is it an Armory?
bool IsArmory(const Handle h)
{
	char ObjClass[MAX_ODF_LENGTH] = {0};
	if(!GetObjInfo(h, Get_GOClass, ObjClass))
		return false;

	char BZCClass[MAX_ODF_LENGTH] = {0};
	GetODFString(h, "GameObjectClass", "BZCClasslabel", MAX_ODF_LENGTH, BZCClass);

	return (_stricmp(ObjClass, "CLASS_ARMORY") == 0) || (_stricmp(BZCClass, "slf") == 0); // Look for Armory.
}
// Is it a Constructor? GBD: CLASS_CONSTRUCTIONRIGT too. (The hash shortcut is reconstructed: every shipped caller leaves it 0.)
bool IsConstructor(const Handle h, const int ObjClassHash)
{
	if (ObjClassHash != 0)
		return (ObjClassHash == CLASS_CONSTRUCTIONRIG) || (ObjClassHash == CLASS_CONSTRUCTIONRIGT);

	char ObjClass[MAX_ODF_LENGTH] = {0};
	if(!GetObjInfo(h, Get_GOClass, ObjClass))
		return false;

	return (_stricmp(ObjClass, "CLASS_CONSTRUCTIONRIG") == 0) || (_stricmp(ObjClass, "CLASS_CONSTRUCTIONRIGT") == 0);
}
// Is it a Service Truck? (The hash parameter is unused in the shipped body.)
bool IsServiceTruck(const Handle h, const int /*ObjClassHash*/)
{
	char ObjClass[MAX_ODF_LENGTH] = {0};
	if(!GetObjInfo(h, Get_GOClass, ObjClass))
		return false;

	return (_stricmp(ObjClass, "CLASS_SERVICE") == 0) || (_stricmp(ObjClass, "CLASS_SERVICEH") == 0);
}
// Is it a Power Plant? // ancestor; not in the shipped binary (through DefaultAlignToTerrain)
bool IsPower(const Handle h)
{
	char ObjClass[MAX_ODF_LENGTH] = {0};
	if(!GetObjInfo(h, Get_GOClass, ObjClass))
		return false;

	char BZCClass[MAX_ODF_LENGTH] = {0};
	GetODFString(h, "GameObjectClass", "BZCClasslabel", MAX_ODF_LENGTH, BZCClass);

	int PowerCost = 0;
	if(_stricmp(ObjClass, "CLASS_POWERPLANT") == 0)
		GetODFInt(h, "GameObjectClass", "powerCost", &PowerCost, -3);

	return ((_stricmp(BZCClass, "power") == 0) || ((_stricmp(ObjClass, "CLASS_POWERPLANT") == 0) && (PowerCost < 0)));
}
// Is it a Tug?
bool IsTug(const Handle h)
{
	char ObjClass[MAX_ODF_LENGTH] = {0};
	if(!GetObjInfo(h, Get_GOClass, ObjClass))
		return false;

	return (_stricmp(ObjClass, "CLASS_TUG") == 0);
}
// Is it an APC?
bool IsAPC(const Handle h)
{
	char ObjClass[MAX_ODF_LENGTH] = {0};
	if(!GetObjInfo(h, Get_GOClass, ObjClass))
		return false;

	char BZCClass[MAX_ODF_LENGTH] = {0};
	GetODFString(h, "GameObjectClass", "BZCClasslabel", MAX_ODF_LENGTH, BZCClass);

	return (_stricmp(BZCClass,"apc") == 0) || (_stricmp(ObjClass, "CLASS_APC") == 0);
}
// Is it a Walker?
bool IsWalker(const Handle h)
{
	char ObjClass[MAX_ODF_LENGTH] = {0};
	if(!GetObjInfo(h, Get_GOClass, ObjClass))
		return false;

	return (_stricmp(ObjClass, "CLASS_WALKER") == 0);
}
// Is it an Artillary? 
bool IsArtillary(const Handle h)
{
	char ObjClass[MAX_ODF_LENGTH] = {0};
	if(!GetObjInfo(h, Get_GOClass, ObjClass))
		return false;

	return (_stricmp(ObjClass,"CLASS_HOWITZER") == 0) || (_stricmp(ObjClass,"CLASS_ARTILLERY") == 0);
}
// Is it a CommTower? BZC, BZ2, or BZ2 other Class?
bool IsCommTower(const Handle h)
{
	char ObjClass[MAX_ODF_LENGTH] = {0};
	if(!GetObjInfo(h, Get_GOClass, ObjClass))
		return false;

	char BZCClass[MAX_ODF_LENGTH] = {0};
	GetODFString(h, "GameObjectClass", "BZCClasslabel", MAX_ODF_LENGTH, BZCClass);

	return (_stricmp(BZCClass,"comm") == 0) || (_stricmp(ObjClass, "CLASS_COMMBUNKER") == 0) || (_stricmp(ObjClass, "CLASS_COMMTOWER") == 0);
}
// Is it a portal? (BZCClasslabel = "portal" or CLASS_TELEPORTAL
bool IsPortal(const Handle h)
{
	char ObjClass[MAX_ODF_LENGTH] = {0};
	if(!GetObjInfo(h, Get_GOClass, ObjClass))
		return false;

	char BZCClass[MAX_ODF_LENGTH] = {0};
	GetODFString(h, "GameObjectClass", "BZCClasslabel", MAX_ODF_LENGTH, BZCClass);

	return (_stricmp(BZCClass,"portal") == 0) || (_stricmp(ObjClass, "CLASS_TELEPORTAL") == 0);
}
// Is it a Fury?
bool IsFury(const Handle h)
{
	char ObjClass[MAX_ODF_LENGTH] = {0};
	if(!GetObjInfo(h, Get_GOClass, ObjClass))
		return false;

	char BZCClass[MAX_ODF_LENGTH] = {0};
	GetODFString(h, "GameObjectClass", "BZCClasslabel", MAX_ODF_LENGTH, BZCClass);

	return (_stricmp(ObjClass, "CLASS_SAV") == 0) || (_stricmp(BZCClass,"fury") == 0);
}
// Is it a Carrier?
bool IsCarrier(const Handle h)
{
	char BZCClass[MAX_ODF_LENGTH] = {0};
	if(!GetODFString(h, "GameObjectClass", "BZCClasslabel", MAX_ODF_LENGTH, BZCClass))
		return false;

	return (_stricmp(BZCClass,"carrier") == 0);
}
// Is it a Drone?
bool IsDrone(const Handle h)
{
	char BZCClass[MAX_ODF_LENGTH] = {0};
	if(!GetODFString(h, "GameObjectClass", "BZCClasslabel", MAX_ODF_LENGTH, BZCClass))
		return false;

	return (_stricmp(BZCClass,"drone") == 0);
}
// Is it a DropShip? 
bool IsDropShip(const Handle h)
{
	char BZCClass[MAX_ODF_LENGTH] = {0};
	if(!GetODFString(h, "GameObjectClass", "BZCClasslabel", MAX_ODF_LENGTH, BZCClass))
		return false;

	return (_stricmp(BZCClass,"dropship") == 0);
}
// Is it an HQCP? 
bool IsHQCP(const Handle h)
{
	char ObjClass[MAX_ODF_LENGTH] = {0};
	if(!GetObjInfo(h, Get_GOClass, ObjClass))
		return false;

	char BZCClass[MAX_ODF_LENGTH] = {0};
	GetODFString(h, "GameObjectClass", "BZCClasslabel", MAX_ODF_LENGTH, BZCClass);

	return (_stricmp(ObjClass, "CLASS_MOTIONSENSOR") == 0) || (_stricmp(BZCClass,"hqcp") == 0);
}
// Is it a Jammer?
bool IsJammer(const Handle h)
{
	char ObjClass[MAX_ODF_LENGTH] = {0};
	if(!GetObjInfo(h, Get_GOClass, ObjClass))
		return false;

	char BZCClass[MAX_ODF_LENGTH] = {0};
	GetODFString(h, "GameObjectClass", "BZCClasslabel", MAX_ODF_LENGTH, BZCClass);

	return (_stricmp(ObjClass, "CLASS_JAMMER") == 0) || (_stricmp(BZCClass,"jamm") == 0);
}
// Is it a Morph Object?
bool IsMorphObject(const Handle h)
{
	char BZCClass[MAX_ODF_LENGTH] = {0};
	if(!GetODFString(h, "GameObjectClass", "BZCClasslabel", MAX_ODF_LENGTH, BZCClass))
		return false;

	return (_stricmp(BZCClass,"morphobject") == 0);
}
// Is it a LaunchPad?
bool IsLPad(const Handle h)
{
	char BZCClass[MAX_ODF_LENGTH] = {0};
	if(!GetODFString(h, "GameObjectClass", "BZCClasslabel", MAX_ODF_LENGTH, BZCClass))
		return false;

	return (_stricmp(BZCClass,"lpad") == 0);
}
// Is it a Shield?
bool IsShield(const Handle h)
{
	char ObjClass[MAX_ODF_LENGTH] = {0};
	if(!GetObjInfo(h, Get_GOClass, ObjClass))
		return false;

	char BZCClass[MAX_ODF_LENGTH] = {0};
	GetODFString(h, "GameObjectClass", "BZCClasslabel", MAX_ODF_LENGTH, BZCClass);

	return (_stricmp(ObjClass, "CLASS_SHIELDTOWER") == 0) || (_stricmp(BZCClass,"shld") == 0);
}
// Is it a Minelayer?
bool IsMinelayer(const Handle h)
{
	char ObjClass[MAX_ODF_LENGTH] = {0};
	if(!GetObjInfo(h, Get_GOClass, ObjClass))
		return false;

	return (_stricmp(ObjClass,"CLASS_MINELAYER") == 0);
}

// Is it something that can AlignToTerrain? (Note: We pass in it's Classlabel string here, due to it's first usage.)
bool DefaultAlignToTerrain(const char *ODFName)
{
	if(!ODFName)
		return false;

	char TempODF[MAX_ODF_LENGTH] = {0};
	char TempODF2[MAX_ODF_LENGTH] = {0};
	char Classlabel[MAX_ODF_LENGTH] = {0};

	const char *ext = strrchr(ODFName, '.');
	if(!ext)
		sprintf_s(TempODF, "%s.odf", ODFName); // Add odf to the end.

	if(GetODFString(TempODF, "GameObjectClass", "classlabel", MAX_ODF_LENGTH, TempODF2))
	{
		if(DoesODFExist(TempODF2)) // This classlabel points to an odf, it's inherited, go deeper.
		{
			strcat_s(TempODF2, ".odf"); // Add .odf to the end.
			if(!GetODFString(TempODF2, "GameObjectClass", "classlabel", MAX_ODF_LENGTH, Classlabel))
				return false; // No classlabel string in this odf, your ODF is invalid.
		}
	}

	for(int i = 0; i < sizeof(DefaultAlignToTerrainList)/sizeof(DefaultAlignToTerrainList[0]); i++)
		if(_stricmp(Classlabel, DefaultAlignToTerrainList[i]) == 0)
			return true;

	return false;
}

// Is this ODF's engine classlabel a powered building's?
bool IsPoweredBuilding(const char *ODFName)
{
	if (!ODFName)
		return false;

	char TempODF[MAX_ODF_LENGTH] = {0};
	const char *ODF = ODFName;
	if (_stricmp(ODFName + strlen(ODFName) - 4, ".odf") != 0)
	{
		CombineStrings(TempODF, ODFName, ".odf");
		ODF = TempODF;
	}

	memset(TempGetClasslabelString, 0, sizeof(TempGetClasslabelString)); // Clear this before use.
	const char *Classlabel = GetClasslabelString(ODF);
	for (int i = 0; i < sizeof(ClassLabelPoweredBuildings)/sizeof(ClassLabelPoweredBuildings[0]); i++)
		if (_stricmp(Classlabel, ClassLabelPoweredBuildings[i]) == 0)
			return true;

	return false;
}

// Is this ODF's engine classlabel a building's?
bool IsBuilding(const char *ODFName)
{
	if (!ODFName)
		return false;

	char TempODF[MAX_ODF_LENGTH] = {0};
	const char *ODF = ODFName;
	if (_stricmp(ODFName + strlen(ODFName) - 4, ".odf") != 0)
	{
		CombineStrings(TempODF, ODFName, ".odf");
		ODF = TempODF;
	}

	memset(TempGetClasslabelString, 0, sizeof(TempGetClasslabelString)); // Clear this before use.
	const char *Classlabel = GetClasslabelString(ODF);
	for (int i = 0; i < sizeof(ClassLabelBuildings)/sizeof(ClassLabelBuildings[0]); i++)
		if (_stricmp(Classlabel, ClassLabelBuildings[i]) == 0)
			return true;

	return false;
}

// Conforms an ODFName retrieved with Get_ODF to cutoff the .odf.
bool GetODFName(const Handle h, char *ODFName)
{
	if (!ODFName)
		return false; // Null pointer, bad. return! return!

	if (!GetObjInfo(h, Get_ODF, ODFName))
		return false; // Invalid Handle.

	if (char *dot = strrchr(ODFName, '.'))
		*dot = '\0';

	return true;
}
// Version that returns a char *.
char TempGetODFName[MAX_ODF_LENGTH];
const char *GetODFName(const Handle h)
{
	memset(TempGetODFName, 0, sizeof(TempGetODFName)); // Clear this before use.

	GetODFName(h, TempGetODFName); // Don't return NULL, since we don't want a char * null pointer, instead return an empty string, "".

	return TempGetODFName;
}

// Function that gets the ODFName, as well as a TempODF of the name with .odf and the classlabel string with .odf extention.
// GBD: returns whether the handle resolved; a classlabel ODF that does not open leaves TempODF2 empty.
bool GetAndOpenODFNames(const Handle h, char *TempODF1, char *TempODF2, char *ODFName)
{
	if((!TempODF1) || (!TempODF2))
		return false; // Null pointers, bad. return! return!

	if(!GetObjInfo(h, Get_ODF, TempODF1))
		return false; // Invalid Handle.

	char TempClassString[MAX_ODF_LENGTH] = {0};
	if((OpenODF2(TempODF1)) && (GetODFString(TempODF1, "GameObjectClass", "classlabel", MAX_ODF_LENGTH, TempClassString)))
	{
		CombineStrings(TempODF2, TempClassString, ".odf"); // Add .odf to the end.
		if(!OpenODF2(TempODF2))
			TempODF2[0] = '\0';
	}

	if(ODFName) // If ODFName is != NULL.
	{
		CombineStrings(ODFName, "", TempODF1); // Copy the retrieved ODF to ODFName too, and cutoff the .odf.
		if (char *dot = strrchr(ODFName, '.'))
			*dot = '\0';
	}

	return true;
}

// Walks an ODF's classlabel chain (GameObjectClass / WeaponClass / OrdnanceClass / ExplosionClass) down to the engine classlabel.
char TempGetClasslabelString[MAX_ODF_LENGTH];
const char *GetClasslabelString(const char *ODFName)
{
	char TempODF[MAX_ODF_LENGTH] = {0};
	(_stricmp(ODFName + strlen(ODFName) - 4, ".odf") == 0) ? CombineStrings(TempODF, "", ODFName) : CombineStrings(TempODF, ODFName, ".odf");

	if ((OpenODF2(TempODF)) &&
		((GetODFString(TempODF, "GameObjectClass", "classlabel", MAX_ODF_LENGTH, TempGetClasslabelString)) ||
		(GetODFString(TempODF, "WeaponClass", "classlabel", MAX_ODF_LENGTH, TempGetClasslabelString)) ||
		(GetODFString(TempODF, "OrdnanceClass", "classlabel", MAX_ODF_LENGTH, TempGetClasslabelString)) ||
		(GetODFString(TempODF, "ExplosionClass", "classlabel", MAX_ODF_LENGTH, TempGetClasslabelString))))
	{
		while (DoesODFExist(TempGetClasslabelString)) // The classlabel names another ODF, go deeper.
		{
			char TempODF2[MAX_ODF_LENGTH] = {0};
			strcpy_s(TempODF2, TempGetClasslabelString);
			CombineStrings(TempODF, TempODF2, ".odf");
			if (((OpenODF2(TempODF)) &&
				(!GetODFString(TempODF, "GameObjectClass", "classlabel", MAX_ODF_LENGTH, TempGetClasslabelString)) &&
				(!GetODFString(TempODF, "WeaponClass", "classlabel", MAX_ODF_LENGTH, TempGetClasslabelString)) &&
				(!GetODFString(TempODF, "OrdnanceClass", "classlabel", MAX_ODF_LENGTH, TempGetClasslabelString)) &&
				(!GetODFString(TempODF, "ExplosionClass", "classlabel", MAX_ODF_LENGTH, TempGetClasslabelString))) ||
				(_stricmp(TempODF2, TempGetClasslabelString) == 0)) // Nothing further down, or it names itself. Done.
				break;
		}
	}

	return TempGetClasslabelString;
}

// Gets the Pilot CFG of the object. // ancestor; not in the shipped binary
bool GetPilotConfig(const Handle h, char *ODFName)
{
	if (!ODFName)
		return false; // Null pointer, bad. return! return!

	if (const char *pilotcfg = GetPilotConfig(h))
		CombineStrings(ODFName, "", pilotcfg);
	else
		return false;

	return true;
}
// Version that returns a char *.
char TempGetPilotConfig[MAX_ODF_LENGTH];
const char *GetPilotConfig(const Handle h)
{
	memset(TempGetPilotConfig, 0, sizeof(TempGetPilotConfig)); // Clear this before use.

	if (const char *pilotOdf = GetPilotClass(h))
	{
		strcpy_s(TempGetPilotConfig, pilotOdf);
		if (char *dot = strrchr(TempGetPilotConfig, '.'))
			*dot = '\0';
	} // else { return NULL; } // Don't return NULL, since we don't want a char * null pointer, instead return an empty string, "".

	return TempGetPilotConfig;
}

// Combines two strings into one. Used to append things to a string safely.
bool CombineStrings(char *ReturnString, const char *String1, const char *String2, const size_t MaxSize)
{
	if ((!ReturnString) || (!String1) || (!String2))
		return false; // Null pointer, bad. return! return!

	if (ReturnString == String2)
	{
		FormatConsoleMessage("ERROR: '%s' cannot append '%s', Return and String2 is itself!", String1, String2);
		return false; // Bad! Pointer string overwrite!
	}

	if ((strlen(String1) + strlen(String2)) > MaxSize)
	{
		FormatConsoleMessage("ERROR: '%s' cannot append '%s', length too long. Make ODF Name shorter!", String1, String2);
		return false;
	}

	if (ReturnString == String1)
		strcat_s(ReturnString, MaxSize, String2);
	else
		sprintf_s(ReturnString, MaxSize, "%s%s", String1, String2);

	return true;
}
// Version that returns a char *. // ancestor; not in the shipped binary
char TempCombineStrings[MAX_ODF_LENGTH];
const char *CombineStrings(const char *String1, const char *String2)
{
	memset(TempCombineStrings, 0, sizeof(TempCombineStrings)); // Clear this before use.
	CombineStrings(TempCombineStrings, String1, String2);

	return TempCombineStrings;
}

// Sets the world variant ODF, if it exists. GBD: only *v* vehicle ODFs are touched at all, and only names of 64 or fewer characters.
bool GetWorldVariantODF(char *ODFName)
{
	if(!ODFName)
		return false;

	if(tolower(ODFName[1]) == 'v') // If it's a *v* odf, vehicle, apply world letter. -GBD
	{
		if (char *dot = strrchr(ODFName, '.'))
			*dot = '\0';

		char WorldSetting = 0;
		if(GetODFChar(GetMapTRNFilename(), "World", "WorldLetter", &WorldSetting)) // Grab the world letter.
		{
			if (strlen(ODFName) <= MAX_ODF_LENGTH)
			{
				char TempWorldODF[MAX_ODF_LENGTH] = {0};
				sprintf_s(TempWorldODF, "%s%c", ODFName, WorldSetting);

				if(DoesODFExist(TempWorldODF))
				{
					strcpy_s(ODFName, sizeof(TempWorldODF), TempWorldODF);
					return true;
				}
			}
		}
	}
	return false;
}
// ancestor; not in the shipped binary
char TempWorldVariantODFName[MAX_ODF_LENGTH];
const char *GetWorldVariantODF(const Handle h)
{
	memset(TempWorldVariantODFName, 0, sizeof(TempWorldVariantODFName)); // Clear this before use.

	if(!GetObjInfo(h, Get_ODF, TempWorldVariantODFName))
		return TempWorldVariantODFName; // Don't return NULL, since we don't want a char * null pointer, instead return an empty string, "".

	GetWorldVariantODF(TempWorldVariantODFName);

	return TempWorldVariantODFName;
}

// Gets a random ODF of the specified race, if it exists. // ancestor; not in the shipped binary (through PreloadRace)
char TempRandomOffensiveODFName[MAX_ODF_LENGTH];
const char *GetRandomOffensiveODF(const char Race)
{
	memset(TempRandomOffensiveODFName, 0, sizeof(TempRandomOffensiveODFName)); // Clear this before use.

	for(int i = 0; i < 256; i++) // Try 256 times to get a valid ODF.
	{
		strcpy_s(TempRandomOffensiveODFName, OffensiveShipList[GetRandomInt(sizeof(OffensiveShipList)/sizeof(OffensiveShipList[0])-1)]);
		TempRandomOffensiveODFName[0] = Race; // Assign Race lettr.
		if(DoesODFExist(TempRandomOffensiveODFName))
			return TempRandomOffensiveODFName;
	}
	return NULL; // Failed. :(
}
char TempRandomDefensiveODFName[MAX_ODF_LENGTH];
const char *GetRandomDefensiveODF(const char Race)
{
	memset(TempRandomDefensiveODFName, 0, sizeof(TempRandomDefensiveODFName)); // Clear this before use.

	for(int i = 0; i < 256; i++) // Try 256 times to get a valid ODF.
	{
		strcpy_s(TempRandomDefensiveODFName, DefensiveShipList[GetRandomInt(sizeof(DefensiveShipList)/sizeof(DefensiveShipList[0])-1)]);
		TempRandomDefensiveODFName[0] = Race; // Assign Race lettr.
		if(DoesODFExist(TempRandomDefensiveODFName))
			return TempRandomDefensiveODFName;
	}
	return NULL; // Failed. :(
}
char TempRandomUtilityODFName[MAX_ODF_LENGTH];
const char *GetRandomUtilityODF(const char Race)
{
	memset(TempRandomUtilityODFName, 0, sizeof(TempRandomUtilityODFName)); // Clear this before use.

	for(int i = 0; i < 256; i++) // Try 256 times to get a valid ODF.
	{
		strcpy_s(TempRandomUtilityODFName, UtilityShipList[GetRandomInt(sizeof(UtilityShipList)/sizeof(UtilityShipList[0])-1)]);
		TempRandomUtilityODFName[0] = Race; // Assign Race lettr.
		if(DoesODFExist(TempRandomUtilityODFName))
			return TempRandomUtilityODFName;
	}
	return NULL; // Failed. :(
}
// Gets any random, out of a random choice of the above.
const char *GetRandomShipODF(const char Race)
{
	// This is a switch case. :)
	switch(GetRandomInt(2)) // 1 of 3...
	{
	case 0:
		{
			return GetRandomOffensiveODF(Race);
		}
	case 1:
		{
			return GetRandomDefensiveODF(Race);
		}
	case 2:
		{
			return GetRandomUtilityODF(Race);
		}
	}
	return NULL; // Failed. :(
}

// Preloads a race given a race char.
void PreloadRace(const char Race)
{
	char TestODF[MAX_ODF_LENGTH] = {0};
	for(int i = 0; i < sizeof(PreloadRaceList)/sizeof(PreloadRaceList[0]); i++)
	{
		sprintf_s(TestODF, "%c%s", Race, PreloadRaceList[i]);
		if(DoesODFExist(TestODF))
			PreloadODF(TestODF);
	}
}

// Gets the Pilot Cost out of an ODF. GBD: the two-file getter walks the classlabel chain by itself.
int GetPilotCost(const char* ODF)
{
	if(!ODF)
		return 0;

	int TempPilotCost = 0; //Default of 0.
	char PilotODF[MAX_ODF_LENGTH] = {0};
	CombineStrings(PilotODF, "", ODF);
	// If this ODF does not exist, it might have been built by a factory, check for that.
	CheckODFName(PilotODF); // strips any .odf off if it already has it.
	CombineStrings(PilotODF, PilotODF, ".odf"); // Add .odf to the end.
	// Look for new ODF Parameter pilotCost. 
	if(OpenODF2(PilotODF))
		GetODFInt(PilotODF, NULL, "GameObjectClass", "pilotCost", &TempPilotCost); // Grab the value.

	return TempPilotCost;
}

// Gets the Scrap Cost out of an ODF.
int GetScrapCost(const char* ODF)
{
	if(!ODF)
		return 0;

	int TempScrapCost = 0;
	char TempODF[MAX_ODF_LENGTH] = {0};
	CombineStrings(TempODF, "", ODF);
	CheckODFName(TempODF); // strips any .odf off if it already has it.
	CombineStrings(TempODF, TempODF, ".odf"); // Add .odf to the end.
	if(OpenODF2(TempODF))
		GetODFInt(TempODF, NULL, "GameObjectClass", "scrapCost", &TempScrapCost); // Grab the value.

	return TempScrapCost;
}

// Gets the Scrap Value out of an ODF.
int GetScrapValue(const char* ODF)
{
	if(!ODF)
		return 0;

	int TempScrapValue = 0;
	char TempODF[MAX_ODF_LENGTH] = {0};
	CombineStrings(TempODF, "", ODF);
	CheckODFName(TempODF); // strips any .odf off if it already has it.
	CombineStrings(TempODF, TempODF, ".odf"); // Add .odf to the end.
	if(OpenODF2(TempODF))
		GetODFInt(TempODF, NULL, "GameObjectClass", "scrapValue", &TempScrapValue); // Grab the value.

	return TempScrapValue;
}

// Gets the number of Weapon Hardpoints an object has. GBD: the hardpoint type is hashed like ReplaceWeapons does it.
int GetNumWeapons(const Handle h)
{
	if(!IsAround(h))
		return -1;

	int count = 0;

	for(int i = 0; i < MAX_HARDPOINTS; i++)
	{
		char WeaponHard[MAX_ODF_LENGTH] = {0};
		char DesiredName[MAX_ODF_LENGTH] = {0};
		sprintf_s(DesiredName, "weaponHard%d", i+1);
		if((GetODFString(h, "GameObjectClass", DesiredName, MAX_ODF_LENGTH, WeaponHard)) && (_strnicmp(WeaponHard, "HP_", 3) == 0))
		{
			char * pUnderscore2 = strchr(WeaponHard + 3, '_');
			if (pUnderscore2 != NULL)
				*pUnderscore2 = '\0'; // Truncate everything after the 2nd _ on.

			if (strlen(WeaponHard) >= 6) // Only if it's still too long. This handles case "HP_GUN".
				WeaponHard[7] = '\0';

			const unsigned int HardHash = Hash(WeaponHard);
			if ((HardHash == HPType_CANN) || (HardHash == HPType_ROCK) || (HardHash == HPType_MORT) || (HardHash == HPType_SPEC) ||
				(HardHash == HPType_PACK) || (HardHash == HPType_HAND) || (HardHash == HPType_GUN)) // Verify valid Hardpoint types.
				count++;
		}
	}

	return count;
}

// Power left on the team after this ODF: its powerCost, or 1 for a powered building that has neither a powerCost nor power taps.
int CheckBuildRequirements_PowerCost(const int Team, const char* filename1, const char* filename2)
{
	int PowerCost = 0;
	if ((!GetODFInt(filename1, filename2, "GameObjectClass", "powerCost", &PowerCost)) && (!GetTapCount(filename1, filename2)) && (IsPoweredBuilding(filename1)))
		PowerCost = 1;

	return GetPower(Team) - PowerCost;
}

// Gets back the _Config.odf of an object. GBD: <odf>_config.odf, then <classlabel>_config.odf, then <gCfg>_config.odf.
char TempGetConfigODFName[MAX_ODF_LENGTH];
const char *GetConfigODF(const Handle h)
{
	memset(TempGetConfigODFName, 0, sizeof(TempGetConfigODFName)); // Clear this before use.

	char ODFName[MAX_ODF_LENGTH] = {0};
	if(!GetODFName(h, ODFName))
		return NULL;

	CombineStrings(TempGetConfigODFName, ODFName, "_config.odf"); // Try for ODF_config.odf

	if(!DoesFileExist(TempGetConfigODFName))
	{
		GetODFString(h, "GameObjectClass", "classlabel", MAX_ODF_LENGTH, TempGetConfigODFName); // Look for it's Classlabel_config.odf first.
		CombineStrings(TempGetConfigODFName, TempGetConfigODFName, "_config.odf");

		if(!DoesFileExist(TempGetConfigODFName)) // If no ODF exists, then it must not be inherited, look for BaseName_config.odf.
		{
			GetObjInfo(h, Get_GOClass_gCfg, TempGetConfigODFName); // Look for basename_config.odf next.
			CombineStrings(TempGetConfigODFName, TempGetConfigODFName, "_config.odf");

			if(!DoesFileExist(TempGetConfigODFName)) // If no ODF exists, then return NULL.
				return NULL;
		}
	}
	return TempGetConfigODFName;
}

// Gets a random player handle, out of all possible players. // ancestor; not in the shipped binary
Handle GetRandomPlayer(void)
{
	Handle playerArray[MAX_TEAMS - 1];
	int playerCount = 0;
	for (int team = 1; team < MAX_TEAMS; ++team)
	{
		Handle player = GetPlayerHandle(team);
		if (IsAround(player))
			playerArray[playerCount++] = player;
	}
	if (playerCount > 0)
		return playerArray[GetRandomInt(0, playerCount-1)];

	return 0;
}

// Checks to see if this ODF is already open, then opens it and adds it to the list of currently open odfs. Note: You MUST call CloseOpenODFs() at the end of the mission, in the ~Destructor or PostRun.
bool OpenODF2(const char *name)
{
	if((!name[0]) || (name[0] == '.'))
		return false;

	// get the CRC hash of the name.
	unsigned long nameHash = CalcCRC(name);

	// check if the name is already open.
	if(ODFNameMap.find(nameHash) != ODFNameMap.end())
		return true; // already open.

	// check if we already tried and failed.
	if (ODFNameBlackListMap.find(nameHash) != ODFNameBlackListMap.end())
		return false; // previously tried and failed.

	PetWatchdogThread();
	// open the file.
	if(OpenODF(name))
	{
		PetWatchdogThread();
		// add it to the open files.
		strcpy_s(ODFNameMap[nameHash].name, name);
		return true;
	}

	// add it to the failed files.
	ODFNameBlackListMap.insert(nameHash);

	return false; // file not found.
}

// Closes all ODFs opened by OpenODF. Note: This MUST be called at the end of the mission, in the ~Destructor or PostRun().
void CloseOpenODFs(void)
{
	// Close all ODFs we've opened this game.
	for (std::unordered_map<unsigned long, ODFName>::iterator iter = ODFNameMap.begin(); iter != ODFNameMap.end(); ++iter)
		CloseODF(iter->second.name);

	ODFNameMap.clear();
}

// Custom GetODF functions that OpenODF2 the ODF, and include ODF Inhertience. GBD: each hands its object's ODF to the two-file getter.
int GetODFHexInt(const Handle h, const char* block, const char* name, int* value, const int defval) // ancestor; not in the shipped binary
{
	char TempODF[MAX_ODF_LENGTH] = {0};
	if((!GetObjInfo(h, Get_ODF, TempODF)) || (!block) || (!name))
		return false;

	return GetODFHexInt(TempODF, NULL, block, name, value, defval);
}
int GetODFInt(const Handle h, const char* block, const char* name, int* value, const int defval)
{
	char TempODF[MAX_ODF_LENGTH] = {0};
	if((!GetObjInfo(h, Get_ODF, TempODF)) || (!block) || (!name))
		return false;

	return GetODFInt(TempODF, NULL, block, name, value, defval);
}
int GetODFLong(const Handle h, const char* block, const char* name, long* value, const long defval) // ancestor; not in the shipped binary
{
	char TempODF[MAX_ODF_LENGTH] = {0};
	if((!GetObjInfo(h, Get_ODF, TempODF)) || (!block) || (!name))
		return false;

	return GetODFLong(TempODF, NULL, block, name, value, defval);
}
int GetODFFloat(const Handle h, const char* block, const char* name, float* value, const float defval)
{
	char TempODF[MAX_ODF_LENGTH] = {0};
	if((!GetObjInfo(h, Get_ODF, TempODF)) || (!block) || (!name))
		return false;

	return GetODFFloat(TempODF, NULL, block, name, value, defval);
}
int GetODFDouble(const Handle h, const char* block, const char* name, double* value, const double defval)
{
	char TempODF[MAX_ODF_LENGTH] = {0};
	if((!GetObjInfo(h, Get_ODF, TempODF)) || (!block) || (!name))
		return false;

	return GetODFDouble(TempODF, NULL, block, name, value, defval);
}
int GetODFChar(const Handle h, const char* block, const char* name, char* value, const char defval)
{
	char TempODF[MAX_ODF_LENGTH] = {0};
	if((!GetObjInfo(h, Get_ODF, TempODF)) || (!block) || (!name))
		return false;

	return GetODFChar(TempODF, NULL, block, name, value, defval);
}
int GetODFBool(const Handle h, const char* block, const char* name, bool* value, const bool defval)
{
	char TempODF[MAX_ODF_LENGTH] = {0};
	if((!GetObjInfo(h, Get_ODF, TempODF)) || (!block) || (!name))
		return false;

	return GetODFBool(TempODF, NULL, block, name, value, defval);
}
int GetODFString(const Handle h, const char* block, const char* name, size_t ValueLen, char* value, const char* defval)
{
	char TempODF[MAX_ODF_LENGTH] = {0};
	if((!GetObjInfo(h, Get_ODF, TempODF)) || (!block) || (!name))
		return false;

	return GetODFString(TempODF, NULL, block, name, ValueLen, value, defval);
}
int GetODFColor(const Handle h, const char* block, const char* name, DWORD* value, const DWORD defval) // ancestor; not in the shipped binary
{
	char TempODF[MAX_ODF_LENGTH] = {0};
	if((!GetObjInfo(h, Get_ODF, TempODF)) || (!block) || (!name))
		return false;

	return GetODFColor(TempODF, NULL, block, name, value, defval);
}
int GetODFVector(const Handle h, const char* block, const char* name, Vector* value, const Vector defval)
{
	char TempODF[MAX_ODF_LENGTH] = {0};
	if((!GetObjInfo(h, Get_ODF, TempODF)) || (!block) || (!name))
		return false;

	return GetODFVector(TempODF, NULL, block, name, value, defval);
}

// Versions that use built-in single level of ODF Inheritence, pass in ODFName as file1, and the classlabel string with .odf appended as file2, and it returns the value. NOTE: These assume the ODF is already Open. 
// Modified to also do fully recursive, though the original single level intended use is still faster. -GBD
// GBD: the recursion opens each classlabel ODF through OpenODF2 and stops when the chain ends or names itself (no DoesODFExist probe).
// The HexInt and Double variants never read file2 (PDB: no local for it; the image reads file1 only).
int GetODFHexInt(const char* file1, const char* /*file2*/, const char* block, const char* name, int* value, const int defval)
{
	if ((file1 && GetODFHexInt(file1, block, name, value, defval)))
		return true; // It was in the first odf passed in, woohoo!

	// Nope, go fully recursive.
	// First step: Does this odf have the .odf appended?
	char TempODF[MAX_ODF_LENGTH] = { 0 };
	(_stricmp(file1 + strlen(file1) - 4, ".odf") == 0) ? CombineStrings(TempODF, "", file1) : CombineStrings(TempODF, file1, ".odf");

	char TempODF2[MAX_ODF_LENGTH] = { 0 };
	while (OpenODF2(TempODF)) // Go all the way until you can't go any further.
	{
		if (GetODFHexInt(TempODF, block, name, value, defval))
			return true; // Got it.

		if (!GetODFString(TempODF, "GameObjectClass", "classlabel", MAX_ODF_LENGTH, TempODF2))
			return false; // No "Classlabel" string in ODF, abort.
		CombineStrings(TempODF2, TempODF2, ".odf"); // Add .odf to the end.

		if (_stricmp(TempODF, TempODF2) == 0)
			return false; // This ODF is the same as it's Classlabel. Abort!

		strcpy_s(TempODF, TempODF2); // Copy TempODF2 into TempODF to try again.
	}
	return false; // Nope, didn't find it.
}
int GetODFInt(const char* file1, const char* file2, const char* block, const char* name, int* value, const int defval)
{
	if ((file1 && GetODFInt(file1, block, name, value, defval)) || (file2 && GetODFInt(file2, block, name, value, defval)))
		return true;

	// Nope, go fully recursive.
	// First step: Does this odf have the .odf appended?
	char TempODF[MAX_ODF_LENGTH] = { 0 };
	if (file2)
		(_stricmp(file2 + strlen(file2) - 4, ".odf") == 0) ? CombineStrings(TempODF, "", file2) : CombineStrings(TempODF, file2, ".odf");
	else
		(_stricmp(file1 + strlen(file1) - 4, ".odf") == 0) ? CombineStrings(TempODF, "", file1) : CombineStrings(TempODF, file1, ".odf");

	char TempODF2[MAX_ODF_LENGTH] = { 0 };
	while (OpenODF2(TempODF)) // Go all the way until you can't go any further.
	{
		if (GetODFInt(TempODF, block, name, value, defval))
			return true; // Got it.

		if (!GetODFString(TempODF, "GameObjectClass", "classlabel", MAX_ODF_LENGTH, TempODF2))
			return false; // No "Classlabel" string in ODF, abort.
		CombineStrings(TempODF2, TempODF2, ".odf"); // Add .odf to the end.

		if (_stricmp(TempODF, TempODF2) == 0)
			return false; // This ODF is the same as it's Classlabel. Abort!

		strcpy_s(TempODF, TempODF2); // Copy TempODF2 into TempODF to try again.
	}
	return false; // Nope, didn't find it.
}
int GetODFLong(const char* file1, const char* file2, const char* block, const char* name, long* value, const long defval)
{
	if ((file1 && GetODFLong(file1, block, name, value, defval)) || (file2 && GetODFLong(file2, block, name, value, defval)))
		return true;

	// Nope, go fully recursive.
	// First step: Does this odf have the .odf appended?
	char TempODF[MAX_ODF_LENGTH] = { 0 };
	if (file2)
		(_stricmp(file2 + strlen(file2) - 4, ".odf") == 0) ? CombineStrings(TempODF, "", file2) : CombineStrings(TempODF, file2, ".odf");
	else
		(_stricmp(file1 + strlen(file1) - 4, ".odf") == 0) ? CombineStrings(TempODF, "", file1) : CombineStrings(TempODF, file1, ".odf");

	char TempODF2[MAX_ODF_LENGTH] = { 0 };
	while (OpenODF2(TempODF)) // Go all the way until you can't go any further.
	{
		if (GetODFLong(TempODF, block, name, value, defval))
			return true; // Got it.

		if (!GetODFString(TempODF, "GameObjectClass", "classlabel", MAX_ODF_LENGTH, TempODF2))
			return false; // No "Classlabel" string in ODF, abort.
		CombineStrings(TempODF2, TempODF2, ".odf"); // Add .odf to the end.

		if (_stricmp(TempODF, TempODF2) == 0)
			return false; // This ODF is the same as it's Classlabel. Abort!

		strcpy_s(TempODF, TempODF2); // Copy TempODF2 into TempODF to try again.
	}
	return false; // Nope, didn't find it.
}
int GetODFFloat(const char* file1, const char* file2, const char* block, const char* name, float* value, const float defval)
{
	if ((file1 && GetODFFloat(file1, block, name, value, defval)) || (file2 && GetODFFloat(file2, block, name, value, defval)))
		return true;

	// Nope, go fully recursive.
	// First step: Does this odf have the .odf appended?
	char TempODF[MAX_ODF_LENGTH] = { 0 };
	if (file2)
		(_stricmp(file2 + strlen(file2) - 4, ".odf") == 0) ? CombineStrings(TempODF, "", file2) : CombineStrings(TempODF, file2, ".odf");
	else
		(_stricmp(file1 + strlen(file1) - 4, ".odf") == 0) ? CombineStrings(TempODF, "", file1) : CombineStrings(TempODF, file1, ".odf");

	char TempODF2[MAX_ODF_LENGTH] = { 0 };
	while (OpenODF2(TempODF)) // Go all the way until you can't go any further.
	{
		if (GetODFFloat(TempODF, block, name, value, defval))
			return true; // Got it.

		if (!GetODFString(TempODF, "GameObjectClass", "classlabel", MAX_ODF_LENGTH, TempODF2))
			return false; // No "Classlabel" string in ODF, abort.
		CombineStrings(TempODF2, TempODF2, ".odf"); // Add .odf to the end.

		if (_stricmp(TempODF, TempODF2) == 0)
			return false; // This ODF is the same as it's Classlabel. Abort!

		strcpy_s(TempODF, TempODF2); // Copy TempODF2 into TempODF to try again.
	}
	return false; // Nope, didn't find it.
}
int GetODFDouble(const char* file1, const char* /*file2*/, const char* block, const char* name, double* value, const double defval)
{
	if ((file1 && GetODFDouble(file1, block, name, value, defval)))
		return true;

	// Nope, go fully recursive.
	// First step: Does this odf have the .odf appended?
	char TempODF[MAX_ODF_LENGTH] = { 0 };
	(_stricmp(file1 + strlen(file1) - 4, ".odf") == 0) ? CombineStrings(TempODF, "", file1) : CombineStrings(TempODF, file1, ".odf");

	char TempODF2[MAX_ODF_LENGTH] = { 0 };
	while (OpenODF2(TempODF)) // Go all the way until you can't go any further.
	{
		if (GetODFDouble(TempODF, block, name, value, defval))
			return true; // Got it.

		if (!GetODFString(TempODF, "GameObjectClass", "classlabel", MAX_ODF_LENGTH, TempODF2))
			return false; // No "Classlabel" string in ODF, abort.
		CombineStrings(TempODF2, TempODF2, ".odf"); // Add .odf to the end.

		if (_stricmp(TempODF, TempODF2) == 0)
			return false; // This ODF is the same as it's Classlabel. Abort!

		strcpy_s(TempODF, TempODF2); // Copy TempODF2 into TempODF to try again.
	}
	return false; // Nope, didn't find it.
}
int GetODFChar(const char* file1, const char* file2, const char* block, const char* name, char* value, const char defval)
{
	if ((file1 && GetODFChar(file1, block, name, value, defval)) || (file2 && GetODFChar(file2, block, name, value, defval)))
		return true;

	// Nope, go fully recursive.
	// First step: Does this odf have the .odf appended?
	char TempODF[MAX_ODF_LENGTH] = { 0 };
	if (file2)
		(_stricmp(file2 + strlen(file2) - 4, ".odf") == 0) ? CombineStrings(TempODF, "", file2) : CombineStrings(TempODF, file2, ".odf");
	else
		(_stricmp(file1 + strlen(file1) - 4, ".odf") == 0) ? CombineStrings(TempODF, "", file1) : CombineStrings(TempODF, file1, ".odf");

	char TempODF2[MAX_ODF_LENGTH] = { 0 };
	while (OpenODF2(TempODF)) // Go all the way until you can't go any further.
	{
		if (GetODFChar(TempODF, block, name, value, defval))
			return true; // Got it.

		if (!GetODFString(TempODF, "GameObjectClass", "classlabel", MAX_ODF_LENGTH, TempODF2))
			return false; // No "Classlabel" string in ODF, abort.
		CombineStrings(TempODF2, TempODF2, ".odf"); // Add .odf to the end.

		if (_stricmp(TempODF, TempODF2) == 0)
			return false; // This ODF is the same as it's Classlabel. Abort!

		strcpy_s(TempODF, TempODF2); // Copy TempODF2 into TempODF to try again.
	}
	return false; // Nope, didn't find it.
}
int GetODFBool(const char* file1, const char* file2, const char* block, const char* name, bool* value, const bool defval)
{
	if ((file1 && GetODFBool(file1, block, name, value, defval)) || (file2 && GetODFBool(file2, block, name, value, defval)))
		return true;

	// Nope, go fully recursive.
	// First step: Does this odf have the .odf appended?
	char TempODF[MAX_ODF_LENGTH] = { 0 };
	if (file2)
		(_stricmp(file2 + strlen(file2) - 4, ".odf") == 0) ? CombineStrings(TempODF, "", file2) : CombineStrings(TempODF, file2, ".odf");
	else
		(_stricmp(file1 + strlen(file1) - 4, ".odf") == 0) ? CombineStrings(TempODF, "", file1) : CombineStrings(TempODF, file1, ".odf");

	char TempODF2[MAX_ODF_LENGTH] = { 0 };
	while (OpenODF2(TempODF)) // Go all the way until you can't go any further.
	{
		if (GetODFBool(TempODF, block, name, value, defval))
			return true; // Got it.

		if (!GetODFString(TempODF, "GameObjectClass", "classlabel", MAX_ODF_LENGTH, TempODF2))
			return false; // No "Classlabel" string in ODF, abort.
		CombineStrings(TempODF2, TempODF2, ".odf"); // Add .odf to the end.

		if (_stricmp(TempODF, TempODF2) == 0)
			return false; // This ODF is the same as it's Classlabel. Abort!

		strcpy_s(TempODF, TempODF2); // Copy TempODF2 into TempODF to try again.
	}
	return false; // Nope, didn't find it.
}
int GetODFString(const char* file1, const char* file2, const char* block, const char* name, size_t ValueLen, char* value, const char* defval)
{
	if ((file1 && GetODFString(file1, block, name, ValueLen, value, defval)) || (file2 && GetODFString(file2, block, name, ValueLen, value, defval)))
		return true;

	// Nope, go fully recursive.
	// First step: Does this odf have the .odf appended?
	char TempODF[MAX_ODF_LENGTH] = { 0 };
	if (file2)
		(_stricmp(file2 + strlen(file2) - 4, ".odf") == 0) ? CombineStrings(TempODF, "", file2) : CombineStrings(TempODF, file2, ".odf");
	else
		(_stricmp(file1 + strlen(file1) - 4, ".odf") == 0) ? CombineStrings(TempODF, "", file1) : CombineStrings(TempODF, file1, ".odf");

	char TempODF2[MAX_ODF_LENGTH] = { 0 };
	while (OpenODF2(TempODF)) // Go all the way until you can't go any further.
	{
		if (GetODFString(TempODF, block, name, ValueLen, value, defval))
			return true; // Got it.

		if (!GetODFString(TempODF, "GameObjectClass", "classlabel", MAX_ODF_LENGTH, TempODF2))
			return false; // No "Classlabel" string in ODF, abort.
		CombineStrings(TempODF2, TempODF2, ".odf"); // Add .odf to the end.

		if (_stricmp(TempODF, TempODF2) == 0)
			return false; // This ODF is the same as it's Classlabel. Abort!

		strcpy_s(TempODF, TempODF2); // Copy TempODF2 into TempODF to try again.
	}
	return false; // Nope, didn't find it.
}
int GetODFColor(const char* file1, const char* file2, const char* block, const char* name, DWORD* value, const DWORD defval)
{
	if ((file1 && GetODFColor(file1, block, name, value, defval)) || (file2 && GetODFColor(file2, block, name, value, defval)))
		return true;

	// Nope, go fully recursive.
	// First step: Does this odf have the .odf appended?
	char TempODF[MAX_ODF_LENGTH] = { 0 };
	if (file2)
		(_stricmp(file2 + strlen(file2) - 4, ".odf") == 0) ? CombineStrings(TempODF, "", file2) : CombineStrings(TempODF, file2, ".odf");
	else
		(_stricmp(file1 + strlen(file1) - 4, ".odf") == 0) ? CombineStrings(TempODF, "", file1) : CombineStrings(TempODF, file1, ".odf");

	char TempODF2[MAX_ODF_LENGTH] = { 0 };
	while (OpenODF2(TempODF)) // Go all the way until you can't go any further.
	{
		if (GetODFColor(TempODF, block, name, value, defval))
			return true; // Got it.

		if (!GetODFString(TempODF, "GameObjectClass", "classlabel", MAX_ODF_LENGTH, TempODF2))
			return false; // No "Classlabel" string in ODF, abort.
		CombineStrings(TempODF2, TempODF2, ".odf"); // Add .odf to the end.

		if (_stricmp(TempODF, TempODF2) == 0)
			return false; // This ODF is the same as it's Classlabel. Abort!

		strcpy_s(TempODF, TempODF2); // Copy TempODF2 into TempODF to try again.
	}
	return false; // Nope, didn't find it.
}
int GetODFVector(const char* file1, const char* file2, const char* block, const char* name, Vector* value, const Vector defval)
{
	if ((file1 && GetODFVector(file1, block, name, value, defval)) || (file2 && GetODFVector(file2, block, name, value, defval)))
		return true;

	// Nope, go fully recursive.
	// First step: Does this odf have the .odf appended?
	char TempODF[MAX_ODF_LENGTH] = { 0 };
	if (file2)
		(_stricmp(file2 + strlen(file2) - 4, ".odf") == 0) ? CombineStrings(TempODF, "", file2) : CombineStrings(TempODF, file2, ".odf");
	else
		(_stricmp(file1 + strlen(file1) - 4, ".odf") == 0) ? CombineStrings(TempODF, "", file1) : CombineStrings(TempODF, file1, ".odf");

	char TempODF2[MAX_ODF_LENGTH] = { 0 };
	while (OpenODF2(TempODF)) // Go all the way until you can't go any further.
	{
		if (GetODFVector(TempODF, block, name, value, defval))
			return true; // Got it.

		if (!GetODFString(TempODF, "GameObjectClass", "classlabel", MAX_ODF_LENGTH, TempODF2))
			return false; // No "Classlabel" string in ODF, abort.
		CombineStrings(TempODF2, TempODF2, ".odf"); // Add .odf to the end.

		if (_stricmp(TempODF, TempODF2) == 0)
			return false; // This ODF is the same as it's Classlabel. Abort!

		strcpy_s(TempODF, TempODF2); // Copy TempODF2 into TempODF to try again.
	}
	return false; // Nope, didn't find it.
}

// This function gets info from an object's buildItem# list, and returns it's Scrap Cost and ODFName.
// GBD: constructors of both kinds (ConstructionRigClass / ConstructionRigTClass); the item's classlabel ODF is opened through OpenODF2 rather
// than probed with DoesODFExist. (The ODFName / WeaponName filters are folded out of the image: every shipped caller passes NULL for them.)
bool GetBuildItem(const Handle h, char *ReturnODF, int *ScrapCost, const int Type, const char *Classlabel, const char *ODFName, const char *WeaponName)
{
	char ObjClass[MAX_ODF_LENGTH] = {0};
	if(!GetObjInfo(h, Get_GOClass, ObjClass))
		return false;
	unsigned int ObjClassHash = Hash(ObjClass);

	unsigned int ClasslabelHash = 0;
	unsigned int ODFNameHash = 0;
	unsigned int WeaponNameHash = 0;

	if(Classlabel)
		ClasslabelHash = Hash(Classlabel);

	if(ODFName)
		ODFNameHash = Hash(ODFName);

	if(WeaponName)
		WeaponNameHash = Hash(WeaponName);

	// int Type, bitmask return type. 0 = Any. 1 = Repair, 2 = Reload, 4 = Match Classlabel, 8 = Match ODFName, 16 = Match WeaponName.
	 const int NewType = Type ? Type : -1;

	if((ObjClassHash == CLASS_ARMORY)  || (ObjClassHash == CLASS_FACTORY) || (ObjClassHash == CLASS_RECYCLER) || (ObjClassHash == CLASS_CONSTRUCTIONRIG) || (ObjClassHash == CLASS_CONSTRUCTIONRIGT))
	{
		// Loops through all 10 Item#'s, looking for a the specified type of thing.
		for(int i = 0; i<11;i++)
		{
			char DesiredValue[MAX_ODF_LENGTH] = {0};

			if(ObjClassHash == CLASS_ARMORY)
			{
				if(i == 0)
					sprintf_s(DesiredValue, "ArmoryClass");
				else
					sprintf_s(DesiredValue, "ArmoryGroup%d", i);
			}
			else
			{
				if(i == 0)
				{
					if(ObjClassHash == CLASS_CONSTRUCTIONRIG)
						sprintf_s(DesiredValue, "ConstructionRigClass");
					else if(ObjClassHash == CLASS_CONSTRUCTIONRIGT)
						sprintf_s(DesiredValue, "ConstructionRigTClass");
					else
						sprintf_s(DesiredValue, "FactoryClass");
				}
				else
				{
					sprintf_s(DesiredValue, "BuildGroup%d", i);
				}
			}
			// Loop over all BuildItems.
			for(int x = 0; x<10;x++)
			{
				char TempBuildODF[MAX_ODF_LENGTH] = {0};
				char ItemODF[MAX_ODF_LENGTH] = {0};
				char ItemODF2[MAX_ODF_LENGTH] = {0};
				// Filter info.
				char TempItemClass[MAX_ODF_LENGTH] = {0};
				char TempWeaponName[MAX_ODF_LENGTH] = {0};

				char DesiredValue2[MAX_ODF_LENGTH] = {0};
				sprintf_s(DesiredValue2, "buildItem%d", x+1);
				if((GetODFString(h, DesiredValue, DesiredValue2, MAX_ODF_LENGTH, TempBuildODF)) && (TempBuildODF[0]))
				{
					CombineStrings(ItemODF, TempBuildODF, ".odf"); // Add .odf to the end.
					if((OpenODF2(ItemODF)) && (GetODFString(ItemODF, "GameObjectClass", "classlabel", MAX_ODF_LENGTH, TempItemClass)))
					{
						CombineStrings(ItemODF2, TempItemClass, ".odf"); // Add .odf to the end.
						if(OpenODF2(ItemODF2)) // If this classlabel ODF does exist, then it's not a true game classlabel.
							GetODFString(ItemODF2, "GameObjectClass", "classlabel", MAX_ODF_LENGTH, TempItemClass);
						else
							ItemODF2[0] = '\0';
					}

					// Pull info used in filters here.
					GetODFString(ItemODF, ItemODF2, "WeaponPowerupClass", "weaponName", MAX_ODF_LENGTH, TempWeaponName);

					// Filter conditions here.
					if(
						(
						((NewType & 1) == 1) && // Look for a Repair pod.
						((ObjClassHash == CLASS_POWERUP_REPAIR) || (ObjClassHash == CLASS_POWERUP_SERVICE))
						) || 
						(
						((NewType & 2) == 2) && // Look for an Ammo Pod.
						((ObjClassHash == CLASS_POWERUP_RELOAD) || (ObjClassHash == CLASS_POWERUP_SERVICE))
						) || 
						(
						((NewType & 4) == 4) && // Look for a specific Classlabel.
						(Classlabel) && (Hash(TempItemClass) == ClasslabelHash)
						) || 
						(
						((NewType & 8) == 8) && // Look for a specific ODFName.
						(ODFName) && (Hash(TempBuildODF) == ODFNameHash)
						) || 
						(
						((NewType & 16) == 16) && // Look for a specific WeaponName.
						(WeaponName) && (Hash(TempWeaponName) == WeaponNameHash)
						) )
					{
						// Get Scrap Cost.
						GetODFInt(ItemODF, ItemODF2, "GameObjectClass", "scrapCost", ScrapCost);

						// Copy the variable into the string and return true.
						strcpy_s(ReturnODF, sizeof(TempBuildODF), TempBuildODF);
						return true;
					}
				}
			}
		}
	}

	// Returns false if we got here.
	return false;
}

// Replace an object's weapons, with optional 2nd object ODF. Takes a Handle and an array of PreviousWeapons[MAX_HARDPOINTS]. Returns false if the handle passed in doesn't exist.
// NOTE: The array passed into these MUST have a size of 5. NewWeapons[MAX_HARDPOINTS] is optional, if not present it will restore old weapons from PreviousODF, if present.
// GBD: logging follows ivar115 / civar5 and goes to the log file; each replaced hardpoint gets ONE engine GiveWeapon(h, slot, weapon) (the 1.3
// loop gave the weapon once per hardpoint of the type); classlabel ODFs are opened through OpenODF2 and dropped when they do not open.
bool ReplaceWeapons(const Handle h, const char NewWeapons[][MAX_ODF_LENGTH], const float PreviousLocalAmmo[], const char *PreviousODF)
{
	char ODFName[MAX_ODF_LENGTH] = { 0 };
	if (!GetObjInfo(h, Get_ODF, ODFName)) // Get the ODF.
		return false;

	const bool Logging = (GetVarItemInt("network.session.ivar115") != 0) || (GetVarItemInt("network.session.civar5") != 0);

	char OldODFName[MAX_ODF_LENGTH] = { 0 };
	CombineStrings(OldODFName, "", PreviousODF ? PreviousODF : ODFName);

	CheckODFName(OldODFName); // Removes the :# or .odf appended to file name.

	if (Logging)
		FormatLogMessage("Replace Weapons: ODF: %s NewWeapons: '%s' '%s' '%s' '%s' '%s'", OldODFName, NewWeapons[0], NewWeapons[1], NewWeapons[2], NewWeapons[3], NewWeapons[4]);

	CombineStrings(OldODFName, OldODFName, ".odf"); // Add .odf to the end.

	// New weapon info.
	char ReplaceWeapon[MAX_HARDPOINTS][MAX_ODF_LENGTH] = { 0 };
	unsigned long ReplaceWeaponClass[MAX_HARDPOINTS] = { 0 };
	bool ReplaceWeaponAssault[MAX_HARDPOINTS] = { 0 };
	char ReplaceWeaponAltName[MAX_HARDPOINTS][MAX_ODF_LENGTH] = { 0 };
	float ReplacementLocalAmmo[MAX_HARDPOINTS] = { 0 };

	int NumHardPointTypes[MAX_HARDPOINTS] = { 0 };
	bool BuildWeapons[MAX_HARDPOINTS] = { 0 };
	char CurrWeapon[MAX_HARDPOINTS][MAX_ODF_LENGTH] = { 0 };
	unsigned long CurrWeaponClass[MAX_HARDPOINTS] = { 0 };
	unsigned long PrevWeaponClass[MAX_HARDPOINTS] = { 0 };
	bool PrevWeaponAssault[MAX_HARDPOINTS] = { 0 };
	int PrevWeaponGroup[MAX_HARDPOINTS] = { 0 };
	bool UseGroups[MAX_HARDPOINTS] = { 0 };
	char TempODF2[MAX_ODF_LENGTH] = { 0 }; // Second temp odf, for grabbing out classlabel.

	char TempWeaponODF[MAX_ODF_LENGTH] = { 0 }; // Second temp odf, for grabbing out classlabel.
	char TempWeaponODF2[MAX_ODF_LENGTH] = { 0 }; // Second temp odf, for grabbing out classlabel.

	// Get our old ship's Hardpoint info.
	if (OpenODF2(OldODFName))
	{
		char TempClassString[MAX_ODF_LENGTH] = { 0 };
		if ((GetODFString(OldODFName, "GameObjectClass", "classlabel", MAX_ODF_LENGTH, TempClassString)))
		{
			CombineStrings(TempODF2, TempClassString, ".odf"); // Add .odf to the end.
			if (!OpenODF2(TempODF2))
				TempODF2[0] = '\0';
		}

		for (int w = 0; w < MAX_HARDPOINTS; w++)
		{
			char WeaponHard[MAX_ODF_LENGTH] = { 0 };
			char DesiredValue[MAX_ODF_LENGTH] = { 0 };
			// Get Weapon Class.
			sprintf_s(DesiredValue, "weaponHard%d", w + 1);
			if (GetODFString(OldODFName, TempODF2, "GameObjectClass", DesiredValue, MAX_ODF_LENGTH, WeaponHard))
			{
				if (_strnicmp(WeaponHard, "HP_", 3) != 0)
					continue; // Misformat! No HP_ found! Bail!

				char * pUnderscore2 = strchr(WeaponHard + 3, '_');
				if (pUnderscore2 != NULL)
					*pUnderscore2 = '\0'; // Truncate everything after the 2nd _ on.

				if (strlen(WeaponHard) >= 6) // Only if it's still too long. This handles case "HP_GUN".
					WeaponHard[7] = '\0';

				PrevWeaponClass[w] = Hash(WeaponHard);
			}

			// Get Weapon Assault.
			sprintf_s(DesiredValue, "weaponAssault%d", w + 1);
			GetODFBool(OldODFName, TempODF2, "GameObjectClass", DesiredValue, &PrevWeaponAssault[w]);

			// Get Weapon Groups.
			sprintf_s(DesiredValue, "weaponGroup%d", w + 1);
			if (GetODFInt(OldODFName, TempODF2, "GameObjectClass", DesiredValue, &PrevWeaponGroup[w]))
				UseGroups[w] = true;
		}
	}
	// Look up the current weaponHard's of the handle we're giving weapons to.
	if (OpenODF2(ODFName))
	{
		for (int w = 0; w < MAX_HARDPOINTS; w++)
		{
			char WeaponHard[MAX_ODF_LENGTH] = { 0 };
			char DesiredValue[MAX_ODF_LENGTH] = { 0 };
			sprintf_s(DesiredValue, "weaponHard%d", w + 1);
			if (GetODFString(h, "GameObjectClass", DesiredValue, MAX_ODF_LENGTH, WeaponHard))
			{
				if (_strnicmp(WeaponHard, "HP_", 3) != 0)
					continue; // Misformat! No HP_ found! Bail!

				char * pUnderscore2 = strchr(WeaponHard + 3, '_');
				if (pUnderscore2 != NULL)
					*pUnderscore2 = '\0'; // Truncate everything after the 2nd _ on.

				if (strlen(WeaponHard) >= 6) // Only if it's still too long. This handles case "HP_GUN".
					WeaponHard[7] = '\0';

				CurrWeaponClass[w] = Hash(WeaponHard);
			}
		}
	}
	// If the hardpoints don't match, don't continue.
	for (int c = 0; c < MAX_HARDPOINTS; c++)
	{
		if (PrevWeaponClass[c] != CurrWeaponClass[c])
			return false; // Done here.
	}

	// Look up our Replacement Weapon's isAssault, altName, and wpnCategory.
	for (int w = 0; w < MAX_HARDPOINTS; w++)
	{
		CombineStrings(ReplaceWeapon[w], "", NewWeapons[w]);
		if (!PreviousLocalAmmo)
			ReplacementLocalAmmo[w] = 1e6; //1.0f;
		else
			ReplacementLocalAmmo[w] = PreviousLocalAmmo[w];

		// Read Each Weapon's Assault Flag/AltName/wpnCategory
		CombineStrings(TempWeaponODF, ReplaceWeapon[w], ".odf"); // Add .odf to the end.
		if (OpenODF2(TempWeaponODF))
		{
			char TempClassString[MAX_ODF_LENGTH] = { 0 };
			if ((GetODFString(TempWeaponODF, "WeaponClass", "classlabel", MAX_ODF_LENGTH, TempClassString))) // Grab the classlabel.
			{
				CombineStrings(TempWeaponODF2, TempClassString, ".odf"); // Add .odf to the end.
				if (!OpenODF2(TempWeaponODF2))
					TempWeaponODF2[0] = '\0';
			}

			GetODFBool(TempWeaponODF, TempWeaponODF2, "WeaponClass", "isAssault", &ReplaceWeaponAssault[w]);
			GetODFString(TempWeaponODF, TempWeaponODF2, "WeaponClass", "altName", MAX_ODF_LENGTH, ReplaceWeaponAltName[w]);

			char WeaponCat[MAX_ODF_LENGTH] = { 0 };
			if (GetODFString(TempWeaponODF, TempWeaponODF2, "WeaponClass", "wpnCategory", MAX_ODF_LENGTH, WeaponCat))
			{
				char TempWeaponCat[MAX_ODF_LENGTH] = { 0 };
				sprintf_s(TempWeaponCat, WeaponCat);
				CombineStrings(WeaponCat, "HP_", TempWeaponCat);
				ReplaceWeaponClass[w] = Hash(WeaponCat);
			}
		}
	}

	// Get the current ship's weapons.
	for (int i = 0; i < MAX_HARDPOINTS; i++)
		GetObjInfo(h, ObjectInfoType(Get_Weapon0Config + i), CurrWeapon[i]);

	// Count how many hardpoints are in each weaponGroup.
	for (int c = 0; c < MAX_HARDPOINTS; c++)
	{
		for (int s = 0; s < MAX_HARDPOINTS; s++)
		{
			if ((PrevWeaponClass[c]) && (PrevWeaponClass[s]) && (PrevWeaponClass[c] == PrevWeaponClass[s])) // Weapon Classes Match.
			{
				bool Skip = false;
				for (int t = 0; t < MAX_HARDPOINTS; t++)
				{
					if (((!UseGroups[c]) && (!UseGroups[t]) && (PrevWeaponClass[s] == PrevWeaponClass[t])) && // Both are not using groups, and classes match.
						(((PrevWeaponAssault[c] == PrevWeaponAssault[t]) && (NumHardPointTypes[t] > 0) && (t < c)) || // Assault matches, number of hardpoints > 0, and t < c.
						((ReplaceWeaponAssault[t]) && (!ReplaceWeaponAltName[t][0]) && (t > s) && (!PrevWeaponAssault[s]) && (_stricmp(ReplaceWeapon[s], CurrWeapon[s]) == 0)))) // Make this skip a previous non assault hardpoint if this weapon is Assault Only.
					{
						if (Logging)
							FormatLogMessage("Assault Matchs, Weapon:%d, CompareWeapon:%d, NumHardTypesS: %d, T < C Skipping S. WeaponClassT: '%d'", c, t, NumHardPointTypes[t], PrevWeaponClass[t]);

						Skip = true;
						break;
					}
				}
				if (Skip)
					continue;

				if (
					// Restrict to, If assault matches, and Group Matches, then restrict to 1, else don't !numhardpointtypes.
					// Works for BZ1 stuff. (Groups)
					((((PrevWeaponGroup[c] != PrevWeaponGroup[s]) && (s <= c)) || ((PrevWeaponGroup[c] == PrevWeaponGroup[s]) && ((UseGroups[c]) || (UseGroups[s])) && (s == c))) || // Both dont match, or we our ourselves. count this as a new group.
					// BZ2 Assault combinations.
					((PrevWeaponAssault[c] != PrevWeaponAssault[s]) && (!UseGroups[c]) && (!UseGroups[s]) && (NumHardPointTypes[c] < NumHardPointTypes[s])) || // Weapon assaults dont match, but group overrides.
					// BZ2 Grouped Combat Weapons. (works for isdf rocket tank).
					((PrevWeaponAssault[c] == PrevWeaponAssault[s]) && (!UseGroups[c]) && (!UseGroups[s]) && (s >= c) && (NumHardPointTypes[c] <= NumHardPointTypes[s])))) // Weapon assaults match and groups match, treat as 1 group.
					++NumHardPointTypes[c];

				if (Logging)
				{
					if (((PrevWeaponGroup[c] != PrevWeaponGroup[s]) && (s <= c)) || ((PrevWeaponGroup[c] == PrevWeaponGroup[s]) && ((UseGroups[c]) || (UseGroups[s])) && (s == c)))
						FormatLogMessage("Using Groups, Groups Dont Match, S<C, or We are Ourselves, Weapon:%d, CompareWeapon:%d", c, s);
					else if ((PrevWeaponAssault[c] != PrevWeaponAssault[s]) && (!UseGroups[c]) && (!UseGroups[s]) && (NumHardPointTypes[c] < NumHardPointTypes[s]))
						FormatLogMessage("Assault NOT Matches,Weapon:%d, CompareWeapon:%d, NumHardTypesC: %d < NumHardTypesS: %d", c, s, NumHardPointTypes[c], NumHardPointTypes[s]);
					else if ((PrevWeaponAssault[c] == PrevWeaponAssault[s]) && (!UseGroups[c]) && (!UseGroups[s]) && (s >= c))
						FormatLogMessage("Assault Matchs, Weapon:%d, CompareWeapon:%d, NumHardTypesS: %d, NumHardTypesC: %d", c, s, NumHardPointTypes[s], NumHardPointTypes[c]);
				}
			}
		}
	}

	for (int c = 0; c < MAX_HARDPOINTS; c++)
	{
		for (int s = 0; s < MAX_HARDPOINTS; s++)
		{
			if ((Logging) && (PrevWeaponClass[c] != 0))
				FormatLogMessage("Weapon Class C: %d is: '%d', Weapon Class S: %d Is: '%d'", c, PrevWeaponClass[c], s, PrevWeaponClass[s]);

			if ((PrevWeaponClass[c] != 0) &&  // Weapon Class is not null.
				(PrevWeaponClass[s] != 0) &&  // Weapon Compare class is not null.
				(PrevWeaponClass[c] == PrevWeaponClass[s]) && // Weapon Classes Match.
				(PrevWeaponClass[c] == ReplaceWeaponClass[c]) && // Weapon is for this type of Hardpoint. !!= New 11/28/16 Test me.
				((c != s) || (_stricmp(ReplaceWeapon[c], CurrWeapon[c]) != 0)) && // This is not the same as itself, or a different weapon then we used to have here.
				((_stricmp(ReplaceWeapon[c], CurrWeapon[c]) != 0) || // New Weapon does not match Original Weapon.
				((s > 0) && (_stricmp(ReplaceWeapon[s], CurrWeapon[s]) != 0)))) // 2nd+ New Weapon doesn't match Original Weapon.
			{
				if (Logging)
					FormatLogMessage("Build Weapons C: Weapon Class C: %d is: '%d', Weapon Class S: %d Is: '%d'", c, PrevWeaponClass[c], s, PrevWeaponClass[s]);

				BuildWeapons[c] = true;
			}
		}
	}

	// Handle the weapon replacement. This must go in reverse order. -GBD
	for (int x = 4; x > -1; x--)
	{
		if ((Logging) && (ReplaceWeapon[x][0]))
			FormatLogMessage("Index: %d Original Weapon: '%s', New Weapon: '%s', Number of Hardpoints: %d", x, CurrWeapon[x], ReplaceWeapon[x], NumHardPointTypes[x]);

		if ((ReplaceWeapon[x][0]) && (BuildWeapons[x]))
		{
			GiveWeapon(h, x, ReplaceWeapon[x]);

			if (Logging)
				FormatLogMessage("Giving Weapon: '%s', index: %d", ReplaceWeapon[x], x);
		}
	}
	for (int x = 0; x < MAX_HARDPOINTS; x++)
		SetCurLocalAmmo(h, ReplacementLocalAmmo[x], x);

	return true; // Assume it worked...
}
