// PROVENANCE: ancestors reference/ancestor-1.3/Missions/Shared/ScriptUtilsExtention.h + reference/ancestor-bz1helper-2015/Shared/BZCScriptUtils.h @6fda4f5 | declarations/enums original/missions/Strategy02.pdb via tools/pdb_types.py | status: ported
#ifndef _BZCScriptUtils_
#define _BZCScriptUtils_

// Battlezone 2 ScriptUtils Extention written by General BlackDragon, Ken Miller, and Nielk1.
//
// Reconstruction notes (tools/pdb_types.py over the four shipped PDBs is the authority):
// - Every enum below carries the PDB's exact enumerator names and values (several differ from
//   the 2015 ancestor: Category_Type / TeamFilter_Type / Difficulty / PortalType were renamed,
//   HP_Types / Armor_Type / Shield_Type / ServiceTypes / SearchMatchMask / Independence_Type are new,
//   Hash_GOClass gained the *H / *T classes and Hash_BZCClass the VSR classes).
// - Every function the binary exports from BZCScriptUtils.obj is declared with the PDB signature
//   (see reference/manifest/pdb/strategy02.procs.tsv). Functions that only the ancestors carry are
//   kept (they compile and the line table leaves room for them) and marked "ancestor; not in the
//   shipped binary".
// - The ancestors' const_cast wrappers around the old `Name` SDK API are gone: the current
//   ScriptUtils.h takes const char* itself, and the shipped code calls the SDK directly.
// - The PDB line table places these inlines in this header: GetDistance (849), StartAudio3D (870),
//   CameraObject (883), TerrainFindFloor (885), IsEmpty (1033), IsProducer (1146),
//   GetPositionNearOrFar (1204), Hash (1313), Identity_Matrix (625). Line numbers are not reproduced.

#include "ScriptUtils.h"
#include "mathutils.h"
#include <math.h>
#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <ctype.h>

// Get parellels to RGBA_CREATE().
#ifndef RGBA_GETALPHA
#define RGBA_GETALPHA(rgb)      ((rgb) >> 24)
#define RGBA_GETRED(rgb)        (((rgb) >> 16) & 0xff)
#define RGBA_GETGREEN(rgb)      (((rgb) >> 8) & 0xff)
#define RGBA_GETBLUE(rgb)       ((rgb) & 0xff)
#endif

// Custom RGB Colors.
#define GREY RGB(127,127,127)
#define BLACK RGB(0,0,0)
#define BLUE RGB(0,0,255)
#define YELLOW RGB(255,255,0)
#define PURPLE RGB(255,0,255)
#define CYAN RGB(0,255,255)
#define ALLYBLUE RGB(0,127,255)
#define LAVACOLOR RGB(255,64,0)

#define DKGREY RGB(100,100,100)
#define DKGREEN RGB(0,127,0)
#define DKRED RGB(127,0,0)
#define DKBLUE RGB(0,0,127)
#define DKYELLOW RGB(127,127,0)

// BZ2 hardcoded values.
#define MAX_TAPS 8 // Max number of vehicle taps.
#define MAX_BASE_SLOTS 9 // Max number of base slots.
#define MAX_GROUPS 10 // Max number of Groups to have. 0 - 9.
#define MAX_HARDPOINTS 5 // This is the max number of hardpoints a ship can have. Maybe it'll go up some day? :)
#define MAX_SPRITES 64 // Max Sprites.
#define MAX_LOCAL_FOGVOLUMES 16 // Max Local Fog volumes.
#define MAX_PROVIDES 32 // Max number of ProvideCount.
#define MAX_LAVA_FIELDS 64 // Max number of lava fields.
#define MAX_CLOUD_TYPES 16 // Max Clouds to possibly look at. Double the BZ1 value, yay! -GBD
#define MAX_CLOUD_OBJECTS 64 // Max Clouds per Tile, Double the BZ1 value, yay? -GBD
#define MAX_SHIELDS 16 // Max number of Shield Emitters.
#define MAX_MINES 64 // number of mines to track. SP only.
#define MAX_DROPSHIP_CARGO 10 // Number of ships that can be carried in a dropship.
#define MAX_GRAVITY_TYPES 16 // Max number of Gravity types to Cycle through.
#define INVALID_VALUE -1234 // The code returned by the game on Invalid Values, such as GetMaxHealth() of a killed thing/invalid Handle in DeleteObject.
#define HUGE_NUMBER 1e+30 // The distance returned by GetDistance with invalid handles.
// String lengths.
#define MAX_ODF_LENGTH 64 // Max ODF Length.
#define MAX_NAME_LENGTH 256 // Max Objective Name/AIP file Length.
#define MAX_CONSOLE_MSG_LENGTH 512 // Max length of Console Message/AddObjective msg.
#define MAX_MESSAGE_LENGTH 2048 // Max Length of a message string.
// Math stuff.
#define PI 3.141592654f // Because Pie R Square.
#define DEG_2_RAD 0.0174532925222222f // Degrees to Radians.
//#define RAD_2_DEG 57.2957877f // Radians to Degrees. // Defined in MathUtils.h.
#define GLOBAL_MULT 0.8f // Scale for things. Put here to quickly change it.

// PDB: every object file that includes this header carries a `const float FLAT_MAX_HEIGHT_DIFF` in .data,
// zero in the image and never referenced by shipped code; its intended value is not recoverable.
const float FLAT_MAX_HEIGHT_DIFF = 0.0f;

// String for who modified this DLL, for printing in console of misisons. If you make changes, simply add your name here.
static const char *DLLAuthors = "General BlackDragon, Ken Miller, & Nielk1";

typedef int PilotValue;

// FNV-1a Hash's of Get_EntityType strings, for faster comparisons. (Fowler-Noll-Vo 1a) // ancestor; not in any PDB (unused by shipped code).
enum Hash_EntityType
{
	CLASS_ID_NONE = 0x08ade38c,			//	"CLASS_ID_NONE",		// undefined object (default)
	CLASS_ID_CRAFT = 0xf2070008,		// 	"CLASS_ID_CRAFT",		// hovering vehicle
	CLASS_ID_VEHICLE = 0x27d612aa,		// 	"CLASS_ID_VEHICLE",		// tracked vehicle
	CLASS_ID_TORPEDO = 0xfcbb9395,		// 	"CLASS_ID_TORPEDO",		// miniature vehicle
	CLASS_ID_POWERUP = 0x8f2b1662,		// 	"CLASS_ID_POWERUP",		// power up pod
	CLASS_ID_PERSON = 0xa7a2704b,		// 	"CLASS_ID_PERSON",		// pilot or soldier
	CLASS_ID_ANIMAL = 0x2988eee2,		// 	"CLASS_ID_ANIMAL",		// animal
	CLASS_ID_STRUCT = 0xfea184f3,		// 	"CLASS_ID_STRUCT",		// generic building
	CLASS_ID_BUILDING = 0xc07bf472,		// 	"CLASS_ID_BUILDING",	// important building
	CLASS_ID_SIGN = 0x1f71f513,			// 	"CLASS_ID_SIGN",		// mine object
	CLASS_ID_SCRAP = 0xaff3780b,		// 	"CLASS_ID_SCRAP",		// scrap piece
	CLASS_ID_DEPOSIT = 0xe120e5e8,		// 	"CLASS_ID_DEPOSIT",		// scrap deposit
	CLASS_ID_BEACON = 0x4c47d522,		// 	"CLASS_ID_BEACON",		// nav beacon
	CLASS_ID_PLANT = 0x6c6effbb,		// 	"CLASS_ID_PLANT",		// plant object
	CLASS_ID_TERRAIN = 0xb6789db7,		// 	"CLASS_ID_TERRAIN",		// terrain object
	CLASS_ID_WEAPON = 0xefa88fd6,		// 	"CLASS_ID_WEAPON",		// weapon object
	CLASS_ID_ORDNANCE = 0x5ac64c32,		// 	"CLASS_ID_ORDNANCE",	// ordnance object
	CLASS_ID_EXPLOSION = 0x4366a7c9,	// 	"CLASS_ID_EXPLOSION",	// explosion object
	CLASS_ID_CHUNK = 0x28e135b3,		// 	"CLASS_ID_CHUNK",		// chunk object
	CLASS_ID_CRASH = 0xdc273111,		// 	"CLASS_ID_CRASH",		// crash object
	CLASS_ID_COLLAPSE = 0x9592e289,		// 	"CLASS_ID_COLLAPSE",	// collapsing object
};

// ---- enums exactly as the PDB spells them (tools/pdb_types.py) ----

enum Armor_Type {
    ArmorType_None = 78,
    ArmorType_Low = 76,
    ArmorType_High = 72,
    ArmorType_Energy = 69,
};

enum Category_Type {
    CategoryType_NONE = 0,
    CategoryType_Craft = 1,
    CategoryType_Building = 2,
    CategoryType_Person = 4,
    CategoryType_Powerup = 8,
    CategoryType_Weapon = 16,
    CategoryType_Scrap = 32,
    CategoryType_Other = 64,
};

enum Difficulty {
    Difficulty_None = 0,
    Difficulty_Easy = 1,
    Difficulty_Normal = 2,
    Difficulty_Hard = 3,
    Difficulty_Extreme = 4,
};

enum GameTypes {
    GameType_ALL = 0,
    GameType_DM = 1,
    GameType_ST = 2,
};

enum HP_Types {
    HPType_CANN = (int)0xE1884A5E,
    HPType_ROCK = (int)0xFC91AE57,
    HPType_MORT = 0x3A26AB6C,
    HPType_SPEC = 0x46956389,
    HPType_HAND = (int)0x9AC3C813,
    HPType_PACK = (int)0x8FE971F7,
    HPType_GUN = (int)0xF661135C,
};

enum Hash_BZCClass {
    BZCCLASS_ARMORY = (int)0xC6385024,
    BZCCLASS_APC = 0x326AA115,
    BZCCLASS_ATTACHERWEAPON = (int)0xDC72CD43,
    BZCCLASS_CARRIER = (int)0xD7241CF7,
    BZCCLASS_CARRIER_DRONE = (int)0xFCD48611,
    BZCCLASS_CERBERUS = (int)0xFBA971DE,
    BZCCLASS_CERBERUS_TAIL = (int)0xC17AC6E3,
    BZCCLASS_COMMTOWER = (int)0xF542AFC9,
    BZCCLASS_CONSTRUCTOR = 0x6B5974E3,
    BZCCLASS_CONSTRUCTOR_TOGGLE = 0x6C765F38,
    BZCCLASS_CONSTRUCTOR_ROTATE = (int)0xCFA406D3,
    BZCCLASS_DROPSHIP = (int)0xE5A66DF6,
    BZCCLASS_FACTORY = (int)0xE184DDC3,
    BZCCLASS_FURY = (int)0xF09C2DE1,
    BZCCLASS_GEYSER = 0x63D063D8,
    BZCCLASS_HQCP = 0x06F63E29,
    BZCCLASS_HUNT_SHIP = 0x44AD0C90,
    BZCCLASS_JAMM = 0x2C5846A2,
    BZCCLASS_LAUNCH_PAD = (int)0x89FA26AC,
    BZCCLASS_LAUNCH_PAD_SWITCH = (int)0xB704FAD8,
    BZCCLASS_MINELAYER = 0x53179125,
    BZCCLASS_MORPH_OBJECT = 0x2411D97A,
    BZCCLASS_MORPH_OBJECT_TOGGLE = (int)0xB8846ED2,
    BZCCLASS_ORDNANCE_ANCHOR = 0x5EA3580A,
    BZCCLASS_ORDNANCE_ATTACHER = (int)0xB4661B05,
    BZCCLASS_ORDNANCE_SWITCH = (int)0x93E05F71,
    BZCCLASS_ORDNANCE_VAMPIRE = 0x123EA3CF,
    BZCCLASS_ORDNANCE_REMOTE = 0x2BD81172,
    BZCCLASS_PATROL_SHIP = 0x6F5FF9AB,
    BZCCLASS_PERSON_PILOT = 0x1E627A4F,
    BZCCLASS_PERSON_SOLDIER = (int)0xE0633D1F,
    BZCCLASS_PORTAL = 0x150C5D8B,
    BZCCLASS_PORTAL_MINE = (int)0xF08724A8,
    BZCCLASS_PORTAL_SWITCH = (int)0xB472C1EE,
    BZCCLASS_POWERPLANT = (int)0xF54F2346,
    BZCCLASS_RECYCLER = (int)0xDDE43890,
    BZCCLASS_SCAVENGER = (int)0xD4E81320,
    BZCCLASS_SHIELD_TOWER = (int)0xBA4A3B96,
};

enum Hash_GOClass {
    CLASS_AIR = 0x04DE8A34,
    CLASS_ANCHORROCKET = 0x2503FBF9,
    CLASS_APC = 0x0DA4ACCE,
    CLASS_ARCCANNON = (int)0xE91CB08D,
    CLASS_ARMORY = 0x63AE241A,
    CLASS_ARTIFACT = 0x3EB9E3B2,
    CLASS_ARTILLERY = (int)0xF9DF4E76,
    CLASS_ASSAULTTANK = 0x1AEFD513,
    CLASS_ASSAULTHOVER = (int)0xC864A6EF,
    CLASS_BARRACKS = (int)0xB18EF1C3,
    CLASS_BEAM = 0x20CEC93F,
    CLASS_BLINK = 0x5C09179E,
    CLASS_BOID = (int)0xA9238CE6,
    CLASS_BOMBER = 0x4606B887,
    CLASS_BOMBERBAY = 0x6D0DF679,
    CLASS_BOUNCEBOMB = (int)0xFCE344E8,
    CLASS_BUILDING = (int)0x98264CE8,
    CLASS_BULLET = (int)0xD97930D0,
    CLASS_CANNON = (int)0xA54F6FFD,
    CLASS_CANNON_MACHINEGUN = (int)0x9203C82B,
    CLASS_CANNON_TARGETING = 0x071C0CA1,
    CLASS_CHARGEGUN = (int)0xFA593446,
    CLASS_COMMBUNKER = (int)0xABF8E42D,
    CLASS_COMMTOWER = (int)0xFCC7B3DD,
    CLASS_COMMVEHICLE = (int)0xB6F61CE0,
    CLASS_COMMVEHICLEH = (int)0x8D6EEA18,
    CLASS_CONSTRUCTIONRIG = 0x77F02E21,
    CLASS_CONSTRUCTIONRIGT = 0x2418EFCF,
    CLASS_CLASS_CRAFT = (int)0xCF98ABE1,
    CLASS_CLASS_DAMAGEFIELD = (int)0x8AC14F6C,
    CLASS_DAYWRECKER = (int)0x998A9793,
    CLASS_DEPLOYABLE = 0x22B50B1F,
    CLASS_DEPLOYBUILDING = (int)0xF1656077,
    CLASS_DEPLOYBUILDINGH = 0x219650CD,
    CLASS_DEPOSIT = (int)0xDC5F98C6,
    CLASS_DISPENSER = (int)0xD566B803,
    CLASS_EXPLOSION = 0x79DFD297,
    CLASS_EXTRACTOR = 0x490DD218,
    CLASS_FACTORY = (int)0xE39EE1AE,
    CLASS_FLAG = (int)0xF2ECD752,
    CLASS_FLAREMINE = (int)0x88799827,
    CLASS_GAMEOBJECT = (int)0xD840F319,
    CLASS_GRENADE = (int)0x9E8CC54E,
    CLASS_GRENADE_LASERPOPPER = 0x6255D3B4,
    CLASS_GRENADE_POPPER = (int)0xAB9D3E35,
    CLASS_HOVER = (int)0xBB81D932,
    CLASS_HOWITZER = 0x25FD9EE0,
    CLASS_I76BUILDING = 0x3A9268D2,
    CLASS_JAMMER = 0x41FB32EC,
    CLASS_JETPACK = (int)0x834F248A,
    CLASS_KINGOFHILL = (int)0xA9A32AE5,
    CLASS_LAUNCHER = (int)0xC3CF9E70,
    CLASS_LAUNCHER_IMAGE = (int)0x9D350762,
    CLASS_LAUNCHER_MULTI = (int)0xD264F7EA,
    CLASS_LAUNCHER_RADAR = (int)0xA905D923,
    CLASS_LAUNCHER_THERMAL = 0x46577898,
    CLASS_LAUNCHER_TORPEDO = 0x2B57E4D0,
    CLASS_LOCKSHELL = (int)0xC878487B,
    CLASS_MAGNETGUN = 0x7EB95E20,
    CLASS_MAGNETSHELL = 0x700207A4,
    CLASS_MINE = 0x17900F9B,
    CLASS_MINELAYER = 0x32493554,
    CLASS_MINE_MAGNET = 0x6E0A7E06,
    CLASS_MINE_PROXIMITY = 0x3A1B5A15,
    CLASS_MINE_TRIP = (int)0x9558C8AF,
    CLASS_MINE_WEAPON = 0x175A2AB0,
    CLASS_MISSILE = (int)0xE1DE9178,
    CLASS_MISSILE_IMAGE = 0x778DAF1A,
    CLASS_MISSILE_LASER = 0x61E8EAAC,
    CLASS_MISSILE_RADAR = 0x6A0A773B,
    CLASS_MISSILE_THERMAL = 0x2BC381E0,
    CLASS_MORPHTANK = 0x1C628D2E,
    CLASS_MORTAR = 0x3170EA1D,
    CLASS_MORTAR_REMOTE = (int)0xF75934F4,
    CLASS_MOTIONSENSOR = 0x6DD673E4,
    CLASS_NAVBEACON = 0x33E33CD9,
    CLASS_OBJECTSPAWN = (int)0xCCF5A072,
    CLASS_ORDNANCE = 0x0DCF99A8,
    CLASS_PERSON = 0x5768DCA5,
    CLASS_PLANT = (int)0xDD054DA5,
    CLASS_POWERED = (int)0xD68D4890,
    CLASS_POWERUP_CAMERA = (int)0x8D7C8912,
    CLASS_POWERUP_MONEY = (int)0xB163057B,
    CLASS_POWERUP_RELOAD = (int)0xA662AA60,
    CLASS_POWERUP_REPAIR = 0x4B970310,
    CLASS_POWERUP_SERVICE = 0x33FE0A68,
    CLASS_PULSESHELL = 0x27CD147D,
    CLASS_RECYCLER = (int)0x8A0A1EAD,
    CLASS_RECYCLERVEHICLE = (int)0xC9CD7077,
    CLASS_RECYCLERVEHICLEH = (int)0xCD6780CD,
    CLASS_SALVOLAUNCHER = (int)0xE8CE53BB,
    CLASS_SATCHELCHARGE = (int)0xC7788A0E,
    CLASS_SATCHELPACK = 0x2695D937,
    CLASS_SAV = (int)0xA7275DAA,
    CLASS_SCAVENGER = 0x33A01170,
    CLASS_SCAVENGERH = 0x5CFAE8C8,
    CLASS_SCRAP = 0x6EE4C53D,
    CLASS_SEEKER = (int)0xD888605F,
    CLASS_SEISMICWAVE = (int)0xA6DFC78E,
    CLASS_SERVICE = 0x28E4D573,
    CLASS_SERVICEH = 0x7B3B7981,
    CLASS_SHIELDTOWER = (int)0x9A4A949E,
    CLASS_SHIELDUP = (int)0xE5A9CAFC,
    CLASS_SIGN = (int)0x81ED3511,
    CLASS_SILO = (int)0x80F9FF71,
    CLASS_SNIPERSHELL = (int)0xAAA6237F,
    CLASS_SPAWNBUOY = 0x4A25DBB6,
    CLASS_SPECIAL = (int)0xC4F1F17B,
    CLASS_SPECIAL_FORCEFIELD = (int)0x81E62D61,
    CLASS_SPECIAL_IMAGEREFRACT = (int)0xBEFE3DE0,
    CLASS_SPECIAL_RADARDAMPER = 0x364CE6F5,
    CLASS_SPECIAL_TERRAINEXPOSE = 0x02C0CBED,
    CLASS_SPRAYBOMB = (int)0xBE8A7C31,
    CLASS_SPRAYBUILDING = (int)0xF4C70715,
    CLASS_SUPPLYDEPOT = (int)0xDADCB21B,
    CLASS_TELEPORTAL = 0x7D9B0716,
    CLASS_TERRAIN = 0x6E47E5F1,
    CLASS_TORPEDO = (int)0xCD066DB7,
    CLASS_TRACKEDDEPLOYABLE = 0x07257E15,
    CLASS_TRACKEDVEHICLE = 0x57B8478A,
    CLASS_TUG = 0x04E12224,
    CLASS_TURRET = (int)0xDF6DABBA,
    CLASS_TURRETTANK = 0x4A7AEF92,
    CLASS_WALKER = (int)0xEDB121BA,
    CLASS_WEAPON = 0x16164674,
    CLASS_WINGMAN = (int)0x83416D25,
    CLASS_UNKNOWN = 0x1418355A,
};

enum Independence_Type {
    Independence_Off = 0,
    Independence_On = 1,
};

enum Patch_Names {
    vStock = 20185,
    v1012 = 1012,
    v1200 = 1200,
    v13PB1 = 1310,
    v13PB2 = 1320,
    v13PB3 = 1330,
    v13PB4 = 1340,
    v13PB5 = 1350,
    v13PB51 = 1351,
    v13PB6 = 1360,
    v13PB61 = 1361,
    v13PB62 = 1362,
    v13PB63 = 1363,
    v13PB64 = 1364,
    v13PB65 = 1365,
    v13PB7 = 1370,
    v13PB71 = 1371,
    v13PB72 = 1372,
};

enum PathType {
    ONE_WAY_PATH = 0,
    ROUND_TRIP_PATH = 1,
    LOOP_PATH = 2,
    BAD_PATH = 3,
};

enum PortalType {
    PortalType_None = 0,
    PortalType_On = 1,
    PortalType_Build = 2,
};

enum PowerTypes {
    PType_None = 0,
    PType_BZ1 = 1,
    PType_BZ2 = 2,
    PType_Lung = 4,
};

enum SearchMatchMask {
    MatchMask_All = 0,
    MatchMask_Category = 1,
    MatchMask_ObjClass = 2,
    MatchMask_ODFName = 4,
};

enum ServiceTypes {
    ServiceType_ST = 1,
    ServiceType_Craft = 2,
    ServiceType_Building = 4,
    ServiceType_Person = 8,
    ServiceType_Other = 16,
};

enum Shield_Type {
    ShieldType_S = 83,
    ShieldType_A = 65,
    ShieldType_D = 68,
};

enum TeamFilter_Type {
    TeamFilter_All = 0,
    TeamFilter_SameTeam = 1,
    TeamFilter_Allies = 2,
    TeamFilter_Enemies = 4,
};

// Static Const Char lists.
extern const char *CommandList[NUM_CMD];
// Enum name tables the Lua side registers (PDB: defined in this object, right after CommandList).
extern const char *RandomizeTypeList[3];
extern const char *PreGetInReturnCodesList[2];
extern const char *TauntTypesList[16];
extern const char *EjectKillRetCodeList[4];
extern const char *PrePickupPowerupReturnCodesList[2];
extern const char *PreSnipeReturnCodesList[2];
extern const char *DeathmatchGameSubtypesList[8];
extern const char *TeamRelationshipList[4];
// Game classes that are buildings / powered buildings, by classlabel (used by the ODF-name IsBuilding / IsPoweredBuilding).
extern const char *ClassLabelBuildings[21];
extern const char *ClassLabelPoweredBuildings[13];
extern const Hash_GOClass WeaponClass[11];
extern const Hash_GOClass MiscClass[10];
// ancestor lists; not in the shipped binary (their users are unreferenced there).
extern const char *DefaultAlignToTerrainList[];
extern const char *PreloadRaceList[];
extern const char *OffensiveShipList[];
extern const char *DefensiveShipList[];
extern const char *UtilityShipList[];

// Saved open ODF Files on this machine.
struct ODFName {
    friend struct VsrLayoutCheck_ODFName; // scaffold: QA gate 2 hook (layout asserts); not GBD's
	char name[MAX_ODF_LENGTH];
}; // The ODF.
extern std::unordered_map<unsigned long, ODFName> ODFNameMap;
// Non saved, list of files that code attempted to open but don't exist, such as classlabel strings, e.g. "turret.odf", or "flare.odf"
extern std::unordered_set<unsigned long> ODFNameBlackListMap; // PDB: std::unordered_set<unsigned long> (the 2015 ancestor used a second ODFName map).
// Saved open Files on this machine.
extern std::unordered_map<const char*, FILE*> FileNameMap;
typedef std::unordered_map<const char*, FILE*>::iterator FileMapIt;
// This stores the filename of the Log file for this game.
extern FILE* LogFile;
extern char LogFileName[MAX_ODF_LENGTH];

// The Matrix. Free Your Mind...
static Matrix Identity_Matrix = Matrix(Vector(1, 0, 0), Vector(0, 1, 0), Vector(0, 0, 1), Vector(0, 0, 0));

// Things moved from DLLUtils.h

// Returns true if h is a recycler or recycler vehicle, false if h is invalid, or not a recycler.
extern bool IsRecycler(const Handle h);

// Formats a string with optional parameters, and prints it to the console. 
// Use with %d, %s, %f, %08x, etc, like with sprintf_s().
extern void FormatConsoleMessage(const char *format, ...);

// Writes a message to a file. Returns true if it succeeded, false if it failed. If Append is true, it appends to the existing file, if False then it whipes the existing file before writing. 
// This auotmatically opens the file name and stores it's name. Must call CloseOpenFiles() in destructor or postload.
extern bool FormatFileMessage(const char *Filename, const bool Append, const char *format, ...);
// Formats a message for the MessageBox with color. // Prints the specified string to the messages box (where chat messages, etc go). Color is a RGBA value, use the RGB() or RGBA() macros to make them, e.g. AddToMessagesBox2("Hello, World!", RGB(255,0,255)); // bright purple
extern void FormatToMessagesBox(const char *format, const unsigned long color, ...);
// Resolves a format source: a .txt/.inf/.des/.brf/.otf/.odf file name is loaded from disk, anything else is looked up
// as a "mission" localized string. Returns a malloc'd copy (the shipped callers never free it).
extern char *FormatFromFile(const char *formatsource);

// Get a Vector from a Path point. Code from Nielk1. Height is the Terrain height at the position. Returns Vector(0, 0, 0) if path is invalid.
extern Vector GetVectorFromPath(const char* path, const int point = 0);
// Center of the map's "edge_path", on the terrain.
extern Vector GetCenterOfMap();

// Gets a position as a Matrix.
inline Matrix GetMatrixPosition(const Handle h) { Matrix m; GetPosition(h, m); return m; }

// Function Overloads, these are various name overloads for stock functions that take in different types of arguments by default. Does back end fiddly work for you.
// Sets a handle to the position of another Handle.
inline void SetPosition(const Handle h, const Vector v) { SetVectorPosition(h, v); } // Name Overload for SetVectorPosition.
inline void SetPosition(const Handle h1, const Handle h2) { SetVectorPosition(h1, GetPosition(h2)); }
inline void SetPositionPath(const Handle h1, const char* Path, const int Point = 0) { SetVectorPosition(h1, GetVectorFromPath(Path, Point)); }
// Version that uses a Matrix to take rotation into account.
inline void SetPositionM(const Handle h1, const Handle h2) { Matrix Position = GetMatrixPosition(h2); SetPosition(h1, Position); }
// Gets the distance between a Handle and a Vector/Matrix.
inline float GetDistance(const Handle h, const Vector v) { return GetDistance2D(GetPosition(h), v); }
inline float GetDistance(const Handle h, const Matrix m) { return GetDistance2D(GetPosition(h), m.posit); }
// Goto that takes a Matrix/Path Point.
inline void Goto(const Handle h, const Matrix Position, const int Priority = 1) { Goto(h, Position.posit, Priority); }
inline void Goto(const Handle h, const char* Path, const int Point, const int Priority) { Goto(h, GetVectorFromPath(Path, Point), Priority); }
// Command for Mine that take a Handle/Vector/Matrix/Path Point.
inline void Mine(const Handle h, const Matrix Where, const int Priority = 1) { Mine(h, Where.posit, Priority); }
inline void Mine(const Handle me, const Handle him, int Priority = 1) { Mine(me, GetPosition(him), Priority); }
inline void Mine(const Handle h, const char* Path, const int Point, const int Priority) { Mine(h, GetVectorFromPath(Path, Point), Priority); }
// Command for Dropoff that take a Handle/Vector/Matrix/Path Point.
inline void Dropoff(const Handle h, const Matrix Where, const int Priority = 1) { Dropoff(h, Where.posit, Priority); }
inline void Dropoff(const Handle me, const Handle him, const int Priority = 1) { Dropoff(me, GetPosition(him), Priority); }
inline void Dropoff(const Handle h, const char* Path, const int Point, const int Priority) { Dropoff(h, GetVectorFromPath(Path, Point), Priority); }
// Command for Retreat that take a Vector/Matrix/Path Point.
inline void Retreat(const Handle h, const Vector Where, const int Priority = 1) { SetIndependence(h, Independence_Off); Goto(h, Where, Priority); }
inline void Retreat(const Handle h, const Matrix Where, const int Priority = 1) { Retreat(h, Where.posit, Priority); }
inline void Retreat(const Handle h, const char* Path, const int Point, const int Priority) { Retreat(h, GetVectorFromPath(Path, Point), Priority); }
// GetCircularPos.
inline Vector GetCircularPos(const Vector &CenterPos, const float Radius, const float Angle) { Vector Pos(0,0,0);	SetCircularPos(CenterPos, Radius, Angle, Pos); return Pos; }
// Version of StartAudio3D that takes a Vector and a Matrix.
inline DLLAudioHandle StartAudio3D(const char *const name, const Vector Pos, const DLLAudioCategory cat = AUDIO_CAT_UNKNOWN, const bool loop = false) { return StartAudio3D(name, Pos.x, Pos.y, Pos.z, cat, loop); }
inline DLLAudioHandle StartAudio3D(const char *const name, const Matrix Mat, const DLLAudioCategory cat = AUDIO_CAT_UNKNOWN, const bool loop = false) { return StartAudio3D(name, Mat.posit, cat, loop); }
// Version that returns a Vector.
inline Vector GetPosition2(const Handle h) { Vector v(0, 0, 0); GetPosition2(h, v); return v; }
// Version that takes a Handle, Matrix, and Path name/point.
inline Vector GetPositionNear(const Handle h, const float MinRadiusAway, const float MaxRadiusAway) { return GetPositionNear(GetPosition(h), MinRadiusAway, MaxRadiusAway); }
inline Vector GetPositionNear(const Matrix m, const float MinRadiusAway, const float MaxRadiusAway) { return GetPositionNear(m.posit, MinRadiusAway, MaxRadiusAway); }
inline Vector GetPositionNear(const char* Path, const int Point, const float MinRadiusAway, const float MaxRadiusAway) { return GetPositionNear(GetVectorFromPath(Path, Point), MinRadiusAway, MaxRadiusAway); }
// Version of CameraObject that takes a Vector for position.
inline bool CameraObject(const Handle object_handle, const Vector pos, const Handle target_handle) { return CameraObject(object_handle, pos.x, pos.y, pos.z, target_handle); }
// Version that takes a Vector, a Matrix, and a Path/Point.
inline float TerrainFindFloor(const Vector pos) { return TerrainFindFloor(pos.x, pos.z); }
inline float TerrainFindFloor(const Matrix mat) { return TerrainFindFloor(mat.posit.x, mat.posit.z); }
inline float TerrainFindFloor(const char* Path, const int Point = 0) { Vector Test = GetVectorFromPath(Path, Point); return TerrainFindFloor(Test.x, Test.z); }
inline float TerrainFindFloor(const Handle h) { return TerrainFindFloor(GetPosition(h)); }
// Version that takes a Matrix and Path/Point.
inline bool TerrainIsWater(const Matrix mat) { return TerrainIsWater(mat.posit); }
inline bool TerrainIsWater(const char* Path, const int Point = 0) { return TerrainIsWater(GetVectorFromPath(Path, Point)); }
inline bool TerrainIsWater(const Handle h) { return TerrainIsWater(GetPosition(h)); }
// Version that takes a Matrix and Path/Point.
inline bool TerrainGetHeightAndNormal(const Matrix& mat, float& outHeight, Vector& outNormal, const bool useWater) { return TerrainGetHeightAndNormal(mat.posit, outHeight, outNormal, useWater); }
inline bool TerrainGetHeightAndNormal(const char* Path, const int Point, float& outHeight, Vector& outNormal, const bool useWater) { return TerrainGetHeightAndNormal(GetVectorFromPath(Path, Point), outHeight, outNormal, useWater); }
inline bool TerrainGetHeightAndNormal(const Handle h, float& outHeight, Vector& outNormal, const bool useWater) { return TerrainGetHeightAndNormal(GetPosition(h), outHeight, outNormal, useWater); }
// Version of SetTeamColor that takes a DWORD Color and Vector Color.
inline void SetTeamColor(const int Team, const DWORD Color) { SetTeamColor(Team, RGBA_GETRED(Color), RGBA_GETGREEN(Color), RGBA_GETBLUE(Color)); }
inline void SetTeamColor(const int Team, const Vector Color) { SetTeamColor(Team, int(Color.x), int(Color.y), int(Color.z)); }
// Version that returns a Vector Color
inline Vector GetFFATeamColor(const TEAMCOLOR_TYPE Type, const int Team) { int r = 0, g = 0, b = 0; GetFFATeamColor(Type, Team, r, g, b); return Vector(float(r),float(g),float(b)); }
inline Vector GetTeamStratColor(const TEAMCOLOR_TYPE Type, const int Team) { int r = 0, g = 0, b = 0; GetTeamStratColor(Type, Team, r, g, b); return Vector(float(r),float(g),float(b)); }
inline Vector GetTeamStratIndividualColor(const TEAMCOLOR_TYPE Type, const int Team) { int r = 0, g = 0, b = 0; GetTeamStratIndividualColor(Type, Team, r, g, b); return Vector(float(r),float(g),float(b)); }
// Version that takes a float for the Height.
inline bool CameraPath(const char* path_name, const float height, const int speed, const Handle target_handle) { return CameraPath(path_name, int(height), speed, target_handle); }

// Custom GetODF functions that Handle opening/closing the ODF, as well as one level of ODF Inheritence. Use Spairingly or by themselves.
extern int GetODFHexInt(const Handle h, const char* block, const char* name, int* value = NULL, const int defval = 0); // ancestor; not in the shipped binary
extern int GetODFInt(const Handle h, const char* block, const char* name, int* value = NULL, const int defval = 0);
extern int GetODFLong(const Handle h, const char* block, const char* name, long* value = NULL, const long defval = 0); // ancestor; not in the shipped binary
extern int GetODFFloat(const Handle h, const char* block, const char* name, float* value = NULL, const float defval = 0.0f);
extern int GetODFDouble(const Handle h, const char* block, const char* name, double* value = NULL, const double defval = 0.0);
extern int GetODFChar(const Handle h, const char* block, const char* name, char* value = NULL, const char defval = '\0');
extern int GetODFBool(const Handle h, const char* block, const char* name, bool* value = NULL, const bool defval = false);
extern int GetODFString(const Handle h, const char* block, const char* name, size_t ValueLen = 0, char* value = NULL, const char* defval = NULL);
extern int GetODFColor(const Handle h, const char* block, const char* name, DWORD* value = NULL, const DWORD defval = 0); // ancestor; not in the shipped binary
extern int GetODFVector(const Handle h, const char* block, const char* name, Vector* value = NULL, const Vector defval = Vector(0.0f, 0.0f, 0.0f));

// Versions that use built-in single level of ODF Inheritence, pass in ODFName as file1, and the classlabel string with .odf appended as file2, and it returns the value. NOTE: These assume the ODF is already Open. 
extern int GetODFHexInt(const char* file1, const char* file2, const char* block, const char* name, int* value = NULL, const int defval = 0);
extern int GetODFInt(const char* file1, const char* file2, const char* block, const char* name, int* value = NULL, const int defval = 0);
extern int GetODFLong(const char* file1, const char* file2, const char* block, const char* name, long* value = NULL, const long defval = 0);
extern int GetODFFloat(const char* file1, const char* file2, const char* block, const char* name, float* value = NULL, const float defval = 0.0f);
extern int GetODFDouble(const char* file1, const char* file2, const char* block, const char* name, double* value = NULL, const double defval = 0.0);
extern int GetODFChar(const char* file1, const char* file2, const char* block, const char* name, char* value = NULL, const char defval = '\0');
extern int GetODFBool(const char* file1, const char* file2, const char* block, const char* name, bool* value = NULL, const bool defval = false);
extern int GetODFString(const char* file1, const char* file2, const char* block, const char* name, size_t ValueLen = 0, char* value = NULL, const char* defval = NULL);
extern int GetODFColor(const char* file1, const char* file2, const char* block, const char* name, DWORD* value = NULL, const DWORD defval = 0);
extern int GetODFVector(const char* file1, const char* file2, const char* block, const char* name, Vector* value = NULL, const Vector defval = Vector(0.0f, 0.0f, 0.0f));

////////// Things from BZScriptor tool.
// Sets the angle of an object, in centigrees. 
extern void SetAngle(const Handle h, const float Degrees);
// Internal math functions used in setting the Angle of an object in the BuildAngleObject functions, and the SetAngle function.
extern Vector HRotateFront(const Vector Front, const float HAngleDifference);

// Camera Pos function from Bob "BS-er" Stewert, moves the camera between two positions at the speed (in CM/s). Tweaked by GBD and Ken Miller.
extern bool CameraPos(const Handle me, const Handle him, const Vector &PosA, const Vector &PosB, const float Speed);

// Positions the camera from the perspective of the handle with the specified offset.
extern void CameraOf(const Handle me, const Vector &Offset);
// Version that takes a Z offset float.
inline void CameraOf(const Handle me, const float ZOffset) { CameraOf(me, Vector(0, 0, ZOffset)); }

// Code from WhosDr, Camera function that rotates around an object, at Offset position, at the speed of Speed.
extern bool CameraCircle(const Handle me, const Vector Offset, const Handle him, const Vector &Speed);

// Move function from Bob "BS-ser" Stewert, moves the object to the Dest Position at the specified MoveSpeed. Rotates the object at the specified RotateSpeed in deg/sec. Returns true when the object has arrived.
// PDB: two trailing bools the 2015/1.3 ancestors lack. The shipped bodies show them folded to their defaults
// (LTCG; the Lua binding is the only caller), matching the literals the ancestor passed: SetVel gates the
// SetVelocity() nudge, SetPos is SetInterpolablePosition()'s bSetPosition. Names are reconstructed.
extern bool Move(const Handle h, const float TurnSpeed, const float MoveSpeed, const Vector &Dest, const bool SetVel = true, const bool SetPos = true);
// Move function, spins the object in place until the specified GetTime(). Returns true when the game time has exceeded the specified time.
extern bool Move(const Handle h, const float TurnSpeed, const float Time, const bool SetPos = false);
//////////

////////// New things used by BZScriptor Tool functions.
// Returns the current TPS rate in use. 
inline int GetTPS(void) { return SecondsToTurns(1.0f); }
inline float GetTimeStep(void) { return TurnsToSeconds(1); }

// Version that gets/sets a percent. // ancestor; not in the shipped binary
extern float GetScavengerScrap(const Handle h);
extern void SetScavengerScrap(const Handle h, const float Percent);

// Parellels to GetHealth / GetAmmo, sets them to a % of max.
extern void SetHealth(const Handle h, const float Percent); // ancestor; not in the shipped binary
extern void SetAmmo(const Handle h, const float Percent);

// IsEmpty, returns true if it is a vehicle and empty, else returns false.
inline bool IsEmpty(const Handle h) { if (!IsAround(h)) return false; else return (IsCraftOrPerson(h) && !IsAlive2(h) && !IsPlayer(h)); }; //!IsNotDeadAndPilot2(h) && !IsPlayer(h)); };

// Counts the number of taps on an object. Special note: If using this in AddObject, set AddObject to true to properly count taps. AddObject creation makes a dummy tap on the end that requires more detailed check to skip.
extern int GetTapCount(const Handle h, const bool IgnoreInvincible = false, const bool AddObject = false);
// Counts the powerTap# entries of a building ODF (zero when the ODF is not a building or is not PoweredByTaps).
extern int GetTapCount(const char* filename1, const char* filename2);

// This function is similar to GetPilotClass, but 1: Strips off the .odf file extention, if present, and 2: Doesn't return NULL.
extern bool GetPilotConfig(const Handle h, char *ODFName); // ancestor; not in the shipped binary
// Version that returns a const char *. NOTE: This value gets stomped over the next call, so save it off locally, not via const char * if you plan to use more then one value retrieved by this function.
extern const char *GetPilotConfig(const Handle h);

// Replace an object's weapons, with optional 2nd object ODF. Takes a Handle and an array of PreviousWeapons[MAX_HARDPOINTS]. Returns false if the handle passed in doesn't exist.
// NOTE: The array passed into these MUST have a size of 5. NewWeapons[MAX_HARDPOINTS] is optional, if not present it will restore old weapons from PreviousODF, if present.
extern bool ReplaceWeapons(const Handle h, const char NewWeapons[][MAX_ODF_LENGTH], const float PreviousLocalAmmo[] = NULL, const char *PreviousODF = NULL);

// This function checks the validity of a CFG name retrieved by GetObjInfo Get_CFG/Get_ODF, and cuts off the :## and/or .odf from the end. 
// Useful for checking things built by factories.
extern void CheckODFName(char *ODFName);
//////////

////////// New Things //////////////

// Returns the number of times a position is encircled by the specified path.
extern int GetWindingNumber(const std::vector<VECTOR_2D> &areaPath, const Vector &vector);
extern int GetWindingNumber(const char* path, const Vector vector);
inline int GetWindingNumber(const char* path, const Handle h) { return GetWindingNumber(path, GetPosition(h)); }
inline int GetWindingNumber(const char* path, const Matrix pos) { return GetWindingNumber(path, pos.posit); }
// Polypoly. Takes in a saved std:Vector of a path. Code from Nielk1/Ken Miller.
inline bool IsInsideArea(const std::vector<VECTOR_2D> &areaPath, const Vector &vector) { return GetWindingNumber(areaPath, vector) != 0; }
// Version that takes in a path name, e.g. "area_path", but it may be slightly more expensive to call this each tick. 
inline bool IsInsideArea(const char* path, const Vector vector) { return GetWindingNumber(path, vector) != 0; }
inline bool IsInsideArea(const char* path, const Handle h) { return IsInsideArea(path, GetPosition(h)); }
inline bool IsInsideArea(const char* path, const Matrix pos) { return IsInsideArea(path, pos.posit); }

// Returns the number of points in the path, (true) if a path exists. 0 (false) if it doesn't exist.
extern int DoesPathExist(const char* path);

// IsInfo that takes in a handle. // ancestor; not in the shipped binary
extern bool IsInfo(const Handle h);
// Returns true if Handle me is following Handle him. // ancestor; not in the shipped binary
extern bool IsFollowing(const Handle me, const Handle him);

// Get CanCommand, backported from BZ1. //[11 / 13 / 2016 7:55 : 55 PM] Kenneth Miller : It returns true if it's not the player, not destroyed, not empty, and not running a priority command
inline bool CanCommand(const Handle h) { if (!IsAround(h)) return false; else return (!IsPlayer(h) && IsAliveAndPilot2(h) && GetGroup(h) != -1); }; //!GetPriority(h)); };

// This function checks the validity of an ODF name retrieved by GetObjInfo Get_ODF, and cuts off the .odf from the end. Returns true if successful, otherwise returns false.
extern bool GetODFName(const Handle h, char *ODFName);
// Version that returns a char *. NOTE: This value gets stomped over the next call.
extern const char *GetODFName(const Handle h);

// Combines String1 and String2 into the ReturnString value. Returns true if successful, returns false if it failed. This prevents a buffer ovreflow internally. 
extern bool CombineStrings(char *ReturnString, const char *String1, const char *String2, const size_t MaxSize = MAX_ODF_LENGTH);
// Version that returns a char *. // ancestor; not in the shipped binary
extern const char *CombineStrings(const char *String1, const char *String2);

// Special OpenODF that only opens it if it isn't in the below ODFNames list. 
// Note: If you use this, or the below GetODF* functions, please do NOT use the traditional OpenODF(), and do NOT use the CloseODF() functions.
extern bool OpenODF2(const char *name);

// Closes all ODFs in memory opened via OpenODF2. 
// Note: If you use OpenODF2, or the below GetODF* functions, this MUST be called before the mission closes! Either in the ~Destructor, or in PostRun(). 
extern void CloseOpenODFs(void);

// Opens/Closes and writes a message to a specified file.
extern bool FileOpen(const char *Filename, const bool Append = true);
extern void FileClose(const char *Filename); // ancestor; not in the shipped binary
extern void CloseOpenFiles();

// Opens/Closes the BZClassic.Log file for writing. Automatically appends the current Date and Time to the end of the file name.
extern bool OpenLogFile();
extern void CloseLogFile(); // ancestor; not in the shipped binary
// Formats a string with optional parameters, writes it to a log file and prints it to the console if Logging is enabled.
extern bool FormatLogMessage(const char *format, ...);
extern bool SimpleLogMessage(const char *format, ...); // ancestor; not in the shipped binary

// Inputs an IFace_ConsoleCmd with variable argument list. // ancestor; not in the shipped binary
// For example: IFace_FormatConsoleCmd("sky.fogColor %d %d %d", colorR, colorG, colorB);
extern void IFace_FormatConsoleCmd(const char *format, ...);

// Gets a Matrix position based on ODF Position and Rotation Offset relative to the handle.
extern Matrix GetODFPositionOffset(const Handle h, const int Index = 0, const Vector AddPosition = Vector(0, 0, 0), const Vector AddRotation = Vector(0, 0, 0));
// Gets a Vector position based on ODF Position Offset relative to the handle.
inline Vector GetODFPositionOffset2(const Handle h, const int Index = 0, const Vector AddPosition = Vector(0, 0, 0)) { return GetODFPositionOffset(h, Index, AddPosition).posit; }

// Determins if Handle 1 is facing Handle 2, within the coneAngle margin of error. Higher cone angle (1.0) means facing exactly, lower cone angle means less.
extern bool IsObjectFacingObject(const Handle h1, const Handle h2, const float ConeAngle);
// Version that takes Vectors and a Position. // ancestor; not in the shipped binary
extern bool IsObjectFacingObject(const Vector FrontA, const Vector PositionA, const Vector PositionB, const float ConeAngle);
// Version that takes Matrix's and a coneAngle.
inline bool IsObjectFacingObject(const Matrix PositionA, const Matrix PositionB, const float ConeAngle) { return IsObjectFacingObject(PositionA.front, PositionA.posit, PositionB.posit, ConeAngle); }

// Determins if Handle 2 is to the right of Handle 1, or to the Left. True = Right, False = Left. Rare case of either = Left. // ancestor; not in the shipped binary
extern bool IsObjectFacingObjectRight(const Handle me, const Handle him);

// Checks the Team Filter settings, given a Team filter and two Team numbers. Returns true if the teams match the TeamFilter. 1 = Same Team, 2 = Allies, 4 = Enemies.
extern bool TeamFilterCheck(const int TeamFilter, const int Team1, const int Team2);

// Gets a random Team, based on filters. TeamFilter is 0 = All, 1 = SameTeam, 2 = Allies, 4 = Enemies. 
// ActiveTeamsOnly will only pass if this team has a BaseSlot item, or a Player. If SkipTeamZero is true, it skips Team 0.
extern int GetRandomTeam(const int TeamFilter = 0, const int Team = -1, const bool ActiveTeamsOnly = false, const bool SkipTeamZero = true);

// Base slot 1-9 of a team (slots 4-9 map onto DLL_TEAM_SLOT_BASE4..9). 0 for a bad slot / team.
extern Handle GetObjectByBaseSlot(const int Team, const int Slot);

// Gives an object a random heading (keeps its position).
extern void SetRandomHeadingAngle2(const Handle h);

// Scales for BZ1 > BZ2 distances. 
inline float ScaleDistance(const float dist) { return float(dist * GLOBAL_MULT); }
inline int ScaleDistance(const int dist) { return int(dist * GLOBAL_MULT); }

// Allies two teams together. (paired ally/unally)
inline void AllyTeams(const int t1, const int t2) { Ally(t1, t2); Ally(t2, t1); }
inline void UnAllyTeams(const int t1, const int t2) { UnAlly(t1, t2); UnAlly(t2, t1); }

// Things inspired from TRO functions: // ancestor; not in the shipped binary
// Gets the size of the path, and returns true when the Handle has reached < 12.0f of the final point.
extern bool IsFinishedWithPath(const Handle h, const char* path);
// Recycle command.
extern void Recycle(const Handle h, const int priority);
// Returns true if Handle h does not have full Health. // Same as BZ1.5's IsDamaged(Handle h)
extern bool NeedsHealth(const Handle h);
// Returns true if Handle h does not have full Ammo.
extern bool NeedsAmmo(const Handle h);
// IsDamaged that takes a float.
extern bool IsDamaged(const Handle h, const float Threshold = 0.95f);

// Function to make a BZC Production unit Undeploy. // ancestor; not in the shipped binary
extern void PackUp(const Handle h);

// Command for Hunt/Bailout/Stage.
inline void Hunt(const Handle h, const int Priority = 1) { SetCommand(h, CMD_HUNT, Priority); }
inline void Bailout(const Handle h, const int Priority = 1) { SetCommand(h, CMD_BAILOUT, Priority); }
inline void Stage(const Handle h, const int Priority = 1) { SetCommand(h, CMD_STAGE, Priority); }

// Version that adds to the current amounts. // ancestor; not in the shipped binary
extern void AddScavengerCurScrap(const Handle h, const int aNewScrap);
extern void AddScavengerMaxScrap(const Handle h, const int aNewScrap);

// Spawns a scrap field of specified amount at a position. // ancestor; not in the shipped binary
extern void SpawnScrapField(const Vector Pos, const int Amount = 1, const float Radius = 0.0f, const char Race = 'n');
inline void SpawnScrapField(const char* Path, const int Point = 0, const int Amount = 1, const float Radius = 0.0f, const char Race = 'n') { SpawnScrapField(GetVectorFromPath(Path, Point), Amount, Radius, Race); }
inline void SpawnScrapField(const Handle h, const int Amount = 1, const float Radius = 0.0f, const char Race = 'n') { SpawnScrapField(GetPosition(h), Amount, Radius, Race); }
inline void SpawnScrapField(const Matrix Mat, const int Amount = 1, const float Radius = 0.0f, const char Race = 'n') { SpawnScrapField(Mat.posit, Amount, Radius, Race); }

// Returns how much damage an ordnance odf does to a particular Target. (NOTE: Does not include Explosion damage.)
extern long GetOrdnanceDamageDealt(const Handle h, const char *OrdnanceODF, const bool UseExplosion = true);

// Gets the EngageRange of a target, based on EngageRange, Rangescan, or Weapon Range, in that order.
extern float GetEngageRange(const Handle h);

// Gets the minimum amount of ammo needed to fire the selected weapons of an AI ship.
extern long GetMinFireAmmo(const Handle h);

// Gets the Current UnitName, without the Skill Modifier in it. // ancestor; not in the shipped binary
extern const char *GetUnitName(const Handle h);

// Applies the Skill modifier to the unit's Name. // ancestor; not in the shipped binary
extern void SetSkillName(const Handle h, const int Skill = -1);

// Attempts to emulate the VO register by playing a VO from a unit's ODF. If a team is specified, it plays for that Team, otherwise uses Team from unit.
extern void PlayVOMsg(const Handle h, const char *MsgString, const int Team = -1);
// Plays EVENT_SOUND_<Event> from <Race>event.odf (aevent.odf when the race has none) [BettyVoice], for the local player when he is on Team.
extern void PlayEventVO(const char Race, const int Event, const int Team);

// Adds a world letter to the ODF, if the ODF exists.
extern bool GetWorldVariantODF(char *ODFName);
extern const char *GetWorldVariantODF(const Handle h); // ancestor; not in the shipped binary

// Function that gets the ODF, Attempts to Open it, and fills TempODF1 and 2 with the .ODF names of the object and it's classlabel.
extern bool GetAndOpenODFNames(const Handle h, char *TempODF1, char *TempODF2, char *ODFName = NULL);

// Walks an ODF's classlabel chain and returns the engine classlabel at its end. NOTE: This value gets stomped over the next call.
extern const char *GetClasslabelString(const char *ODFName);

// From SPMission: //#define IsOdf2(h,name) (_strnicmp(ODFName,name,strlen(name)) == 0)
inline bool IsOdf2(const Handle h, const char *name) { return (_strnicmp(GetODFName(h), name, strlen(name)) == 0); }

// Gets a random ODF of the specified race, if it exists. // ancestor; not in the shipped binary
extern const char *GetRandomOffensiveODF(const char Race);
extern const char *GetRandomDefensiveODF(const char Race);
extern const char *GetRandomUtilityODF(const char Race);
// Returns a random ship ODF name, out of the above functions. (Randomly picks one of the 3 above to use, so an even chance of Offense, Defense, or Utility.)
extern const char *GetRandomShipODF(const char Race);

// Preloads a Race given a race char. // ancestor; not in the shipped binary
extern void PreloadRace(const char Race);

// Generalized Class Filters. The SDK's own IsBuilding(Handle) / IsPowerup(Handle) / IsCraftButNotPerson(Handle) replaced the 2015 ancestor's.
// Returns true if it is a Building (SDK IsBuilding) or a Gun Tower (CLASS_TURRET) that is not in the Misc / Weapon class lists. Pass the GOClass hash if you already have it.
extern bool IsBuildingOrGunTower(const Handle h, const int ObjClassHash = 0);
// Returns true if it is a Craft (SDK IsCraftButNotPerson) that is not a Gun Tower (CLASS_TURRET).
extern bool IsCraft(const Handle h, const int ObjClassHash = 0);
// Returns true if it is a Weapon. (Mine/Torpedo)
extern bool IsWeapon(const Handle h, const int ObjClassHash = 0);
// Catchall for the rest, Scrap, KoTH, Flags, Spawnbouys, etc...
extern bool IsMisc(const Handle h, const int ObjClassHash = 0);

// Tests for more specific types out of the above. // ancestor; not in the shipped binary unless noted
// Is it scrap? // CLASS_SCRAP
extern bool IsScrap(const Handle h);
// Is it a turret? (Tank kind, not GunTower kind) CLASS_TURRETTANK
extern bool IsTurret(const Handle h);
// Is it a scavenger? // CLASS_SCAVENGER or CLASS_SCAVENGERH
extern bool IsScavenger(const Handle h);
// Is it a barracks? // CLASS_BARRACKS
extern bool IsBarracks(const Handle h);
// Is it a gun tower? // CLASS_TURRET
extern bool IsGunTower(const Handle h);
// Is it a Geyser/Pool? // CLASS_DEPOSIT
extern bool IsGeyser(const Handle h);
// Is it a Spawnpoint? // CLASS_SPAWNBUOY
extern bool IsSpawnPoint(const Handle h);
// Is it a Silo? // CLASS_SILO or CLASS_EXTRACTOR
extern bool IsSilo(const Handle h);
// Is this a Factory? // BZCclasslabel "muf" or CLASS_FACTORY
extern bool IsFactory(const Handle h);
// Is this an Armory? // BZCClasslabel "slf" or CLASS_ARMORY
extern bool IsArmory(const Handle h);
// Is it a Constructor? // CLASS_CONSTRUCTIONRIG or CLASS_CONSTRUCTIONRIGT. Pass the GOClass hash if you already have it.
extern bool IsConstructor(const Handle h, const int ObjClassHash = 0);
// Is it a Service Truck? // CLASS_SERVICE or CLASS_SERVICEH.
extern bool IsServiceTruck(const Handle h, const int ObjClassHash = 0);
// Is this object a producer? (IsRecycler/IsFactory/IsArmory/IsConstructor?)
inline bool IsProducer(const Handle h) { return IsRecycler(h) || IsFactory(h) || IsArmory(h) || IsConstructor(h); }
// Is this object a power plant? //BZCclasslabel "power", or CLASS_POWERPLANT with -powerCost.
extern bool IsPower(const Handle h);
// Is this object a Tug? // CLASS_TUG
extern bool IsTug(const Handle h);
// Is this object an APC? // BZCclasslabel "apc" or CLASS_APC
extern bool IsAPC(const Handle h);
// Is this a Walker? // CLASS_WALKER
extern bool IsWalker(const Handle h);
// Is it Artillary? // CLASS_HOWITZER or CLASS_ARTILLARY
extern bool IsArtillary(const Handle h);
// Is it a Comm Tower? // BZCClasslabel "comm", or CLASS_COMMBUNKER or CLASS_COMMTOWER
extern bool IsCommTower(const Handle h);
// Is it a Portal? // BZCClasslabel "portal" or CLASS_TELEPORTAL
extern bool IsPortal(const Handle h);
// Is it a fury? // BZCClasslabel "fury" or CLASS_SAV
extern bool IsFury(const Handle h);
// Is this a Carrier? // BZCClasslabel "carrier"
extern bool IsCarrier(const Handle h);
// Is this a Drone? // BZCClasslabel "drone"
extern bool IsDrone(const Handle h);
// Is this a DropShip? // BZCClasslabel "dropship"
extern bool IsDropShip(const Handle h);
// Is this an HQCP? // BZCClasslabel "hqcp" or CLASS_MOTIONSENSOR
extern bool IsHQCP(const Handle h);
// Is this a Jammer? // CLASS_JAMMER
extern bool IsJammer(const Handle h);
// Is this a MorphObject? // BZCClasslabel "morphobject"
extern bool IsMorphObject(const Handle h);
// Is this an LPad? // BZCClasslabel "lpad"
extern bool IsLPad(const Handle h);
// Is this a Shield? // BZCClasslabel "shld" or CLASS_SHIELDTOWER
extern bool IsShield(const Handle h);
// Is this a Minelayer?
extern bool IsMinelayer(const Handle h);
// ODF-name versions: is the ODF's engine classlabel one of the (powered) building classlabels?
extern bool IsPoweredBuilding(const char *ODFName);
extern bool IsBuilding(const char *ODFName);

// Does it default to align to terrain? // ancestor; not in the shipped binary
extern bool DefaultAlignToTerrain(const char *ODFName);
inline bool DefaultAlignToTerrain(const Handle h) { return DefaultAlignToTerrain(GetODFName(h)); }

// Similar to GetPositionNear, only tries to find one that is further away then the current position. If Near is true, it picks a position <= distance closer, if false, it picks a position further.
extern Vector GetPositionNearOrFar(const Vector v1, const Vector v2, const float MinRadius, const float MaxRadius, const bool Near = true);
// Handles.
inline Vector GetPositionNearOrFar(const Handle me, const Handle him, const float MinRadius, const float MaxRadius, const bool Near = true) { return GetPositionNearOrFar(GetPosition(me), GetPosition(him), MinRadius, MaxRadius, Near); }
inline Vector GetPositionNearOrFar(const Handle me, const char* Path, const int Point, const float MinRadius, const float MaxRadius, const bool Near = true) { return GetPositionNearOrFar(GetPosition(me), GetVectorFromPath(Path, Point), MinRadius, MaxRadius, Near); }
inline Vector GetPositionNearOrFar(const Handle me, const Vector v2, const float MinRadius, const float MaxRadius, const bool Near = true) { return GetPositionNearOrFar(GetPosition(me), v2, MinRadius, MaxRadius, Near); }
inline Vector GetPositionNearOrFar(const Handle me, const Matrix m2, const float MinRadius, const float MaxRadius, const bool Near = true) { return GetPositionNearOrFar(GetPosition(me), m2.posit, MinRadius, MaxRadius, Near); }
// Rediculous type variations. :)
inline Vector GetPositionNearOrFar(const Matrix m1, const Matrix m2, const float MinRadius, const float MaxRadius, const bool Near = true) { return GetPositionNearOrFar(m1.posit, m2.posit, MinRadius, MaxRadius, Near); }
inline Vector GetPositionNearOrFar(const Vector v1, const Matrix m2, const float MinRadius, const float MaxRadius, const bool Near = true) { return GetPositionNearOrFar(v1, m2.posit, MinRadius, MaxRadius, Near); }
inline Vector GetPositionNearOrFar(const Matrix m1, const Vector v2, const float MinRadius, const float MaxRadius, const bool Near = true) { return GetPositionNearOrFar(m1.posit, v2, MinRadius, MaxRadius, Near); }

// Gets the pilot cost of an odf.
extern int GetPilotCost(const char* ODF);
// Version that takes a Handle.
inline int GetPilotCost(const Handle h) { return GetPilotCost(GetODFName(h)); }
// Gets the scrap cost / scrap value of an odf.
extern int GetScrapCost(const char* ODF);
extern int GetScrapValue(const char* ODF);

// Returns the number of weapon hardpoints an object has. Returns -1 if the handle is invalid.
extern int GetNumWeapons(const Handle h);

// Power left on Team after paying for the ODF: GetPower(Team) minus its powerCost (1 for a tapless powered building without one).
extern int CheckBuildRequirements_PowerCost(const int Team, const char* filename1, const char* filename2);

// Gets a random player, out of all current players. // ancestor; not in the shipped binary
extern Handle GetRandomPlayer(void);

// Gets the _config.odf of a handle.
extern const char *GetConfigODF(const Handle h);

// This function gets an item from an objects's BuildMenu list. It returns true if successful, and fills the ScrapCost and ReturnODF with the first found items info.
// Type is: 0 = Any. 1 = Repair, 2 = Reload, 4 = Match Classlabel, 8 = Match ODFName, 16 = Match WeaponName.
extern bool GetBuildItem(const Handle h, char *ReturnODF, int *ScrapCost, const int Type = 0, const char *Classlabel = NULL, const char *ODFName = NULL, const char *WeaponName = NULL);

// GiveWeapon that takes a slot. (Uses ReplaceWeapons; an empty Weapon falls through to the SDK's slot GiveWeapon.) Returns false if the weapon ODF is missing or nothing changed.
extern bool GiveWeapon(const Handle h, const char* Weapon, const int Slot);

// fnv-1a hash
inline unsigned int Hash(const unsigned char byte, unsigned int hash = 2166136261u)
{
	hash ^= byte;
	hash *= 16777619u;
	return hash;
}
inline unsigned int Hash(const void *data, size_t len, unsigned int hash = 2166136261u)
{
	const unsigned char * d = static_cast<const unsigned char *>(data);
	const unsigned char * const e = d + len;
	while (d < e)
		hash = Hash(*d++, hash);
	return hash;
}
inline unsigned int Hash(const char *string, unsigned int hash = 2166136261u)
{
	if (string == 0)
    return 0;
	for (const char *s = string; *s != 0; ++s)
		hash = Hash(unsigned char(tolower(*s)), hash);
	return hash;
}

// Function that switches two variables.
template <class T>
inline void SwitchVariables(T &v1, T &v2) { T tempvar = v1; v2 = v1; v1 = tempvar; }

#define VSR_LAYOUT_CHECK_ODFName
#include "vsr_layout_asserts.h"
#undef VSR_LAYOUT_CHECK_ODFName

#endif
