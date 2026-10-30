// PROVENANCE: ancestor reference/ancestor-1.3/Missions/Deathmatch01/deathmatch01.h @353698f (enums, the i_/b_/f_/h_ array convention, comments) | declarations original/missions/deathmatch01.pdb via tools/pdb_types.py (member order and types kept verbatim; offsets confirmed against dumpbin of the ctor: b_count 0x12e, f_count 0x37, h_count 0x240, i_count 0x169, sizeof 0xb544) | gbd-lua-port original/lua/Lua-Stock-Missions_ea4173f/Upload/VSR/Missions/Scripts/Deathmatch.lua | status: ported
#ifndef _deathmatch01_
#define _deathmatch01_

#include "ScriptUtils.h"
#include "luamission.h"

class DLLBase;

class Deathmatch01 : public LuaMission {
    friend struct VsrLayoutCheck_Deathmatch01; // scaffold: QA gate 2 hook (layout asserts); not GBD's
public:
    enum {
        MAX_AI_UNITS = 256,
        MAX_ANIMALS = 8,
        MAX_VEHICLES_TRACKED = 32,
    };
private:
    int m_GameTPS; // How many turns per second there are (10, 15, 20, or 30)

    // integers
    int i_first;
    int StopScript; // The whole-game switch for the BZ1Helper / Lua layers (an int here, as in the PDB).
    int m_TotalGameTime;
    int m_ElapsedGameTime;
    int m_RemainingGameTime;
    int m_KillLimit; // As specified from the shell
    int m_MissionType; // ivar7 & 0xFF, a DMSubtype
    int m_RespawnType; // ivar7 >> 8
    int m_NumVehiclesTracked;
    int m_SpawnedAtTime[MAX_TEAMS];
    int m_MaxSpawnKillTime; // ivar13, in ticks
    int m_LastTauntPrintedAt;
    int m_NextRaceCheckpoint[MAX_TEAMS];
    int m_TotalCheckpointsCompleted[MAX_TEAMS];
    int m_TotalCheckpoints;
    int m_LapNumber[MAX_TEAMS];
    int m_LastTeamInLead;
    int m_TotalRaceLaps; // ivar9 in race
    int m_RaceWinerCount;
    int m_AIUnitSkill; // ivar22
    int m_NumAIUnits;
    int m_MaxAIUnits; // ivar9 outside race
    int m_NumAnimals;
    int m_MaxAnimals; // ivar27
    int m_AnimalConfig[16]; // The animal ODF stored as ints (see m_CustomAIPInts in Instant).
    int m_PowerupGotoTime[MAX_AI_UNITS];
    int m_RabbitTeam;
    int m_ForbidRabbitTeam;
    int m_RabbitShooterTeam;
    int m_RabbitMissingTurns;
    int m_Gravity; // ivar31
    int m_ScoreLimit; // ivar35
    int i_last;

    // bools
    bool b_first;
    bool m_DidOneTimeInit;
    bool m_FirstTime;
    bool m_GameWon;
    bool m_Flying[MAX_TEAMS]; // Pilot in the air; build a craft when they land.
    bool m_TeamIsSetUp[MAX_TEAMS];
    bool m_DMSetup;
    bool m_RaceIsSetup;
    bool m_HumansVsBots; // ivar16
    bool m_RabbitMode; // ivar23
    bool m_RabbitWasHuman;
    bool m_RabbitShooterWasHuman;
    bool m_AILastWentForPowerup[MAX_AI_UNITS];
    bool m_WeenieMode; // ivar19
    bool m_ShipOnlyMode; // ivar25
    bool m_RespawnAtLowAltitude;
    bool m_bIsFriendlyFireOn; // ivar32
    bool m_bDidGameOverByScore;
    bool b_last;

    // floats
    float f_first;
    float m_TeamPos[3*MAX_TEAMS+3]; // Where each team spawned in (xyz).
    float m_FRIENDLY_SPAWNPOINT_MAX_ALLY;
    float m_FRIENDLY_SPAWNPOINT_MIN_ENEMY;
    float m_RANDOM_SPAWNPOINT_MIN_ENEMY;
    float m_RaceCheckpointRadius;
    float f_last;

    // handles
    Handle h_first;
    Handle m_Flag1;
    Handle m_Flag2;
    Handle m_Carrier1;
    Handle m_Carrier2;
    Handle m_Base1;
    Handle m_Base2;
    Handle m_EmptyVehicles[MAX_VEHICLES_TRACKED];
    Handle m_AICraftHandles[MAX_AI_UNITS];
    Handle m_AITargetHandles[MAX_AI_UNITS];
    Handle m_LastPlayerCraftHandle[MAX_TEAMS];
    Handle m_AnimalHandles[MAX_ANIMALS];
    Handle m_RabbitTargetHandle;
    Handle m_RabbitShooterHandle;
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
public:
    Deathmatch01();
    virtual ~Deathmatch01();
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
private:
    void Init();
    virtual void InitialSetup();
    EjectKillRetCodes RespawnPilot(Handle DeadObjectHandle, int Team);
    EjectKillRetCodes DeadObject(int DeadObjectHandle, int KillersHandle, bool WasDeadPerson, bool WasDeadAI);
    bool GetCanEject(Handle h);
    bool GetRespawnInVehicle();
    const char* GetInitialFlagODF(char Race);
    const char* GetInitialFlagStandODF(char Race);
    const char* GetInitialPlayerPilotODF(char Race);
    const char* GetNextVehicleODF(int TeamNum, bool Randomize);
    void SetupTeam(int Team);
    void FindGoodAITarget(const int index);
    void BuildBotCraft(int index);
    void SetupAnimal(int index);
    void ObjectifyRabbit();
    void ObjectifyFlag();
    void CreateObjectives();
    void SetNewRabbit(const Handle h);
    Handle SetupPlayer(int Team);
    void CrunchEmptyVehicleList();
    void UpdateEmptyVehicles();
    void AddEmptyVehicle(Handle NewCraft);
    void ObjectifyRacePoint();
    void ExecuteRabbit();
    void ExecuteRace();
    void ExecuteWeenie();
    void ExecuteTrackPlayers();
    void UpdateGameTime();
    void UpdateAIUnits();
    void UpdateAnimals();
    Vector GetSpawnpointForTeam(int Team);
};

DLLBase* BuildMission();

#define VSR_LAYOUT_CHECK_Deathmatch01
#include "vsr_layout_asserts.h"
#undef VSR_LAYOUT_CHECK_Deathmatch01

#endif // _deathmatch01_
