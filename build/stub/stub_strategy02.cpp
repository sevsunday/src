// Toolchain proof (task 4). NOT part of the reconstruction and never shipped.
//
// A minimal mission DLL that exports GetMisnAPI, fills MisnExport with the
// version magic the engine checks, and supplies no-op callbacks. If this
// compiles against %BZCC_DIR%\ScriptUtils.h, links against battlezone2.lib,
// shows a single "GetMisnAPI" export, and the game loads it from the addon
// override folder without crashing, the toolchain is proven.
//
// The only visible behaviour: one console line in InitialSetup, and on
// AddPlayer(ShouldCreateThem) the player's chosen vehicle is built at
// "Player_1" so the operator can see the DLL is alive. Everything else is
// a safe default.

#include <string.h>
#include "ScriptUtils.h"

// Declared `extern` by ScriptUtils.h under MISN_INTERNAL; the DLL owns it.
MisnImport misnImport;
static MisnExport s_misnExport;

static void DLLAPI Stub_InitialSetup(void)
{
    PrintConsoleMessage("[VSR_DLL_Source] stub Strategy02.dll loaded: GetMisnAPI OK");
}

static bool DLLAPI Stub_Save(bool /*missionSave*/)      { return true; }
static bool DLLAPI Stub_Load(bool /*missionSave*/)      { return true; }
static bool DLLAPI Stub_PostLoad(bool /*missionSave*/)  { return true; }
static void DLLAPI Stub_AddObject(Handle /*h*/)         {}
static void DLLAPI Stub_DeleteObject(Handle /*h*/)      {}
static void DLLAPI Stub_Update(void)                    {}
static void DLLAPI Stub_PostRun(void)                   {}

static bool DLLAPI Stub_AddPlayer(DPID /*id*/, int Team, bool ShouldCreateThem)
{
    if (ShouldCreateThem && GetCurWorld() == 0)
    {
        const char* odf = GetPlayerODF(Team);
        if (odf && odf[0])
        {
            Handle h = BuildObject(odf, Team, "Player_1");
            if (h)
                SetAsUser(h, Team);
        }
    }
    return true;
}

static void DLLAPI Stub_DeletePlayer(DPID /*id*/) {}

static EjectKillRetCodes DLLAPI Stub_PlayerEjected(Handle /*dead*/)                     { return DoEjectPilot; }
static EjectKillRetCodes DLLAPI Stub_ObjectKilled(Handle /*dead*/, Handle /*killer*/)   { return DoEjectPilot; }
static EjectKillRetCodes DLLAPI Stub_ObjectSniped(Handle /*dead*/, Handle /*killer*/)   { return DoEjectPilot; }

static const char* DLLAPI Stub_GetNextRandomVehicleODF(int ForTeam) { return GetPlayerODF(ForTeam); }
static void DLLAPI Stub_SetWorld(int /*nextWorld*/)                  {}
static void DLLAPI Stub_ProcessCommand(unsigned long /*crc*/)       {}
static void DLLAPI Stub_SetRandomSeed(unsigned long /*seed*/)       {}

// Same shape as the 1.3 pack's DllBase.cpp::GetMisnAPI and the decompiled
// VSR dllbase.cpp (version 0x4C89322E, modifier 'BAL1').
extern "C" MisnExport* DLLAPI GetMisnAPI(MisnImport* import)
{
    misnImport = *import;
    memset(&s_misnExport, 0, sizeof(s_misnExport));
    s_misnExport.misnImport              = &misnImport;
    s_misnExport.version                 = LATEST_DLL_VERSION;
    s_misnExport.VersionModifier         = LATEST_DLL_VERSION_MODIFIER;
    s_misnExport.InitialSetup            = Stub_InitialSetup;
    s_misnExport.Save                    = Stub_Save;
    s_misnExport.Load                    = Stub_Load;
    s_misnExport.PostLoad                = Stub_PostLoad;
    s_misnExport.AddObject               = Stub_AddObject;
    s_misnExport.DeleteObject            = Stub_DeleteObject;
    s_misnExport.Update                  = Stub_Update;
    s_misnExport.PostRun                 = Stub_PostRun;
    s_misnExport.AddPlayer               = Stub_AddPlayer;
    s_misnExport.DeletePlayer            = Stub_DeletePlayer;
    s_misnExport.PlayerEjected           = Stub_PlayerEjected;
    s_misnExport.ObjectKilled            = Stub_ObjectKilled;
    s_misnExport.ObjectSniped            = Stub_ObjectSniped;
    s_misnExport.GetNextRandomVehicleODF = Stub_GetNextRandomVehicleODF;
    s_misnExport.SetWorld                = Stub_SetWorld;
    s_misnExport.ProcessCommand          = Stub_ProcessCommand;
    s_misnExport.SetRandomSeed           = Stub_SetRandomSeed;
    return &s_misnExport;
}
