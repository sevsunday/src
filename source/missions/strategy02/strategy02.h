// PROVENANCE: ancestor reference/ancestor-1.3/Missions/Strategy02/Strategy02.h @353698f (the list structs, the inline ShouldRemove* predicates, the i_/b_/f_/h_ array convention and comments) | declarations original/missions/Strategy02.pdb via tools/pdb_types.py (member order and types kept verbatim; predicate bodies from reference/decompiled/strategy02-attempt2/src/missions/strategy02/strategy02.h.decomp.c) | gbd-lua-port original/lua/Lua-Stock-Missions_ea4173f/Upload/VSR/Missions/Scripts/Strategy.lua | status: ported
#ifndef _strategy02_
#define _strategy02_

#include "ScriptUtils.h"
#include <vector>
#include "luamission.h"

class DLLBase;

class Strategy02 : public LuaMission {
    friend struct VsrLayoutCheck_Strategy02; // scaffold: QA gate 2 hook (layout asserts); not GBD's
public:
    // Thug Scavenger Objects. -GBD
    struct ThugScavengerClass {
        friend struct VsrLayoutCheck_Strategy02__ThugScavengerClass; // scaffold: QA gate 2 hook (layout asserts); not GBD's
        Handle ThugScavengerObject; // This ThugScavenger.
        int ScavengerTeam; // Save its team.
    };

    // Thug Pilot Objects.-GBD
    struct ThugPilotClass {
        friend struct VsrLayoutCheck_Strategy02__ThugPilotClass; // scaffold: QA gate 2 hook (layout asserts); not GBD's
        Handle ThugPilotObject; // This ThugPilot.
        int SwitchTickTimer; // Timer (in ticks) for switching them to their commander's Team.
    };

    // Empty ships built by the recycler, invulnerable until a pilot gets in. -GBD
    struct EmptyShipClass {
        friend struct VsrLayoutCheck_Strategy02__EmptyShipClass; // scaffold: QA gate 2 hook (layout asserts); not GBD's
        Handle EmptyShipObject; // This Empty Ship.
        int InvulnerabilityTime; // Ticks of invulnerability left.
        int SavedHealth; // MaxHealth to restore afterwards.
    };

    // Morph tanks that get the auto deploy command. -GBD
    struct MorphTankClass {
        friend struct VsrLayoutCheck_Strategy02__MorphTankClass; // scaffold: QA gate 2 hook (layout asserts); not GBD's
        Handle MorphTankObject; // This Morph Tank.
        bool CmdSet; // Command has been given.
    };

    // Comm bunkers / towers that own a base slot. -GBD
    struct CommBunkerClass {
        friend struct VsrLayoutCheck_Strategy02__CommBunkerClass; // scaffold: QA gate 2 hook (layout asserts); not GBD's
        Handle CommBunkerObject; // This Comm Bunker.
        int CommBunkerBaseSlot; // Its base slot (category type).
    };

private:
    std::vector<Strategy02::ThugScavengerClass> ThugScavengerList;
    std::vector<Strategy02::ThugPilotClass> ThugPilotList;
    std::vector<Strategy02::EmptyShipClass> EmptyShipList;
    std::vector<Strategy02::MorphTankClass> MorphTankList;
    std::vector<Strategy02::CommBunkerClass> CommBunkerList;

    // Saved player data for the restore-players option (ivar119). -GBD
    char PlayerShipODF[MAX_TEAMS][MAX_ODF_LENGTH];
    char SavedPilotODF[MAX_TEAMS][MAX_ODF_LENGTH];
    char PlayerSavedName[MAX_TEAMS][MAX_ODF_LENGTH];
    char PlayerShipWeapons[MAX_TEAMS][MAX_HARDPOINTS][MAX_ODF_LENGTH];
    char PlayerPilotWeapons[MAX_TEAMS][MAX_HARDPOINTS][MAX_ODF_LENGTH];
    float PlayerPilotLocalAmmo[MAX_TEAMS][MAX_HARDPOINTS];
    Matrix PlayerMatrix[MAX_TEAMS];
    Vector PlayerVelocity[MAX_TEAMS];
    Vector PlayerOmega[MAX_TEAMS];
    char MapAmbientSound[MAX_ODF_LENGTH];
    char EmptyShipODF[MAX_TEAMS][MAX_ODF_LENGTH];

    int m_GameTPS; // How many turns per second there are (10, 15, 20, or 30)

    // Note: in a DLL with per-player arrays, be *SURE* to properly shuffle
    // their contents down in the DeletePlayer() call. Arrays based on
    // MAX_TEAMS are not shuffled by default on player deletion.
    int i_first;
    int m_TotalGameTime;
    int m_RemainingGameTime;
    int m_ElapsedGameTime;
    int m_KillLimit; // As specified from the shell
    int m_PointsForAIKill; // ivar14
    int m_KillForAIKill; // ivar15
    int m_RespawnWithSniper; // ivar16
    int m_TurretAISkill; // ivar17
    int m_NonTurretAISkill; // ivar18
    int m_StartingVehiclesMask; // ivar7
    int m_SpawnedAtTime[MAX_TEAMS];
    int m_AllyTeams[MAX_TEAMS]; // New alliance var setting. Yay! -GBD
    int m_RecyInvulnerabilityTime; // ivar25, if >0, this is currently active
    int m_NumSpawnPoints; // Number of Spawn Points. -GBD
    int NumCommanders;
    int NextAutoAssignTeam;
    int CommanderTeam[MAX_TEAMS];
    int ThugCounter[MAX_TEAMS];
    int m_AIRace[5]; // MPI: ivar13, ivar96..99
    int m_HumanForce; // ivar23
    int m_CPUForce; // ivar24
    int m_CPUTurretAISkill; // ivar21
    int m_CPUNonTurretAISkill; // ivar22
    int m_LastTauntPrintedAt;
    int m_PlayersSpawned;
    int m_NumCaptureGoals;
    int m_CaptureGoalTime[MAX_TEAMS];
    int m_CaptureGoalTeam[MAX_TEAMS];
    int m_GoalBeingCaptured[MAX_TEAMS];
    int m_CaptureTime; // ivar54, in ticks
    int m_GameType; // ivar53, 4 = Capture
    int m_PilotInvunerability; // ivar120, in ticks
    int m_PilotInvTime[MAX_TEAMS];
    int m_SavedPilotInvHealth[MAX_TEAMS];
    int m_SavedPlayerHealth[MAX_TEAMS];
    int m_SavedPlayerAmmo[MAX_TEAMS];
    int m_SavedPlayerTeamGroup[MAX_TEAMS];
    int m_SavedPlayerScrap[MAX_TEAMS];
    int m_RestorePlayers; // ivar119
    int BuildEmpty[MAX_TEAMS]; // Recycler's buildEmptyItem index per team.
    int m_MorphTankAutoDeployType; // ivar121
    int i_last;

    bool b_first;
    bool m_DidInit;
    bool StopScript; // The whole-game switch for the BZ1Helper / Lua layers.
    bool m_HadMultipleFunctioningTeams;
    bool m_TeamIsSetUp[MAX_TEAMS];
    bool m_NotedRecyclerLocation[MAX_TEAMS];
    bool m_HasAllies[MAX_TEAMS]; // Allied Team Flag. -GBD
    bool m_GameOver;
    bool m_CreatingStartingVehicles;
    bool m_RespawnAtLowAltitude;
    bool m_bIsFriendlyFireOn;
    bool m_ThugFlag[MAX_TEAMS]; // ivar81..95
    bool m_TeamHasCommander[MAX_TEAMS];
    bool m_SetThugPilotFlag; // ivar55
    bool CheckedSVar3;
    bool m_IsMPI; // ivar12
    bool m_SetFirstAIP;
    bool m_MissionStart;
    bool SpawnAI;
    bool m_CaptureGoalObjectify[MAX_TEAMS];
    bool m_CaptureGoalIsSwitching[MAX_TEAMS][MAX_TEAMS];
    bool m_DualCapture[MAX_TEAMS];
    bool m_TeamIsCapturing[MAX_TEAMS];
    bool m_GiveWeaponsBack[MAX_TEAMS];
    bool m_SavedPlayerDeployed[MAX_TEAMS];
    bool IsCameraPod[MAX_TEAMS];
    bool m_SpawnFacingCenter; // ivar118
    bool b_last;

    float f_first;
    float m_TeamPos[3*MAX_TEAMS+3]; // Where each team spawned in (xyz).
    float m_FRIENDLY_SPAWNPOINT_MAX_ALLY;
    float m_FRIENDLY_SPAWNPOINT_MIN_ENEMY;
    float m_RANDOM_SPAWNPOINT_MIN_ENEMY;
    float m_SavedPlayerLocalAmmo[MAX_TEAMS][MAX_HARDPOINTS];
    float f_last;

    Handle h_first;
    Handle m_RecyclerHandles[MAX_TEAMS];
    Handle m_CaptureGoals[MAX_TEAMS];
    Handle UserTarget[MAX_TEAMS];
    Handle m_PilotInvUser[MAX_TEAMS];
    Handle h_last;
protected:
    bool* b_array;
    int b_count;
    float* f_array;
    int f_count;
    Handle* h_array;
    int h_count;
    int* i_array;
    int i_count;
private:
    static bool ShouldRemoveThugScavengerObject(const Strategy02::ThugScavengerClass& entry) {
        char ObjClass[MAX_ODF_LENGTH] = {0};
        GetObjInfo(entry.ThugScavengerObject, Get_GOClass, ObjClass);
        return !IsAround(entry.ThugScavengerObject) || (_stricmp(ObjClass, "CLASS_EXTRACTOR") == 0) || (_stricmp(ObjClass, "CLASS_SILO") == 0); }
    static bool ShouldRemoveThugPilotObject(const Strategy02::ThugPilotClass& entry) { return !IsAround(entry.ThugPilotObject) || entry.SwitchTickTimer < 0 || IsPlayer(entry.ThugPilotObject); }
    static bool ShouldRemoveEmptyShipObject(const Strategy02::EmptyShipClass& entry) { return !IsAround(entry.EmptyShipObject) || GetMaxHealth(entry.EmptyShipObject) > 0; }
    static bool ShouldRemoveMorphTankObject(const Strategy02::MorphTankClass& entry) { return !IsAround(entry.MorphTankObject) || entry.CmdSet; }
    static bool ShouldRemoveCommBunkerObject(const Strategy02::CommBunkerClass& entry) { return !IsAround(entry.CommBunkerObject); }
public:
    Strategy02();
    virtual ~Strategy02();
    virtual bool Load(bool missionSave);
    virtual bool PostLoad(bool missionSave);
    virtual bool Save(bool missionSave);
    virtual void AddObject(Handle h);
    virtual void DeleteObject(Handle h);
    virtual bool AddPlayer(DPID id, int Team, bool IsNewPlayer);
    virtual void DeletePlayer(DPID id);
    virtual EjectKillRetCodes PlayerEjected(Handle DeadObjectHandle);
    virtual EjectKillRetCodes ObjectKilled(int DeadObjectHandle, int KillersHandle);
    virtual EjectKillRetCodes ObjectSniped(int DeadObjectHandle, int KillersHandle);
    virtual void Execute();
    virtual const char* GetNextRandomVehicleODF(int Team);
    virtual PreGetInReturnCodes PreGetIn(const int curWorld, Handle pilotHandle, Handle emptyCraftHandle);
private:
    void Init(); // Internal one-time setup
    const char* GetInitialPlayerVehicleODF(int Team);
    const char* GetInitialPlayerPilotODF(char Race, int Team, bool IsRespawning);
    const char* GetInitialRecyclerODF(char Race);
    const char* GetInitialScavengerODF(char Race);
    const char* GetInitialConstructorODF(char Race);
    const char* GetInitialHealerODF(char Race);
    void SetupTeam(int Team);
    Handle SetupPlayer(int Team);
    void UpdateGameTime();
    void ExecuteCheckIfGameOver();
    void ExecuteRecyInvulnerability();
    void ExecuteST_Capture(); // ST: Capture game type (ivar53 == 4).
    void ScavengerManagementCode(); // FFA thug scavs / pilots.
    void SetCPUAIPlan(int Team, int NameOverride);
    Handle BuildStartingVehicle(int aTeam, int aRace, char* ODF1, char* ODF2, Vector Where, int aGrp = -1);
    Handle BuildStartingVehicle(int aTeam, int aRace, char* ODF1, char* ODF2, char* Where, int aGrp = -1);
    void UpdateObjectives();
    EjectKillRetCodes RespawnPilot(Handle DeadObjectHandle, int Team);
    EjectKillRetCodes DeadObject(int DeadObjectHandle, int KillersHandle, bool isDeadPerson, bool isDeadAI);
    Vector GetSpawnpointForTeam(int Team);
};

DLLBase* BuildMission();

#define VSR_LAYOUT_CHECK_Strategy02
#include "vsr_layout_asserts.h"
#undef VSR_LAYOUT_CHECK_Strategy02

#endif // _strategy02_
