// PROVENANCE: ancestor reference/ancestor-1.3/Missions/Instant/InstantMission.h @353698f (enums, the i_/b_/f_/h_ array convention, comments) | declarations original/missions/Instant.pdb via tools/pdb_types.py (member order and types kept verbatim; offsets confirmed against dumpbin of the ctor: b_count 0x75, h_count 0x106, i_count 200, sizeof 0xac50) | gbd-lua-port original/lua/Lua-Stock-Missions_ea4173f/Upload/VSR/Missions/Scripts/InstantMission.lua | status: ported
#ifndef _instantmission_
#define _instantmission_

#include "ScriptUtils.h"
#include "luamission.h"

class DLLBase;

class instantMission : public LuaMission {
    friend struct VsrLayoutCheck_instantMission; // scaffold: QA gate 2 hook (layout asserts); not GBD's
public:
    enum {
        // Number of CPU Scavs that'll trigger a cleanup
        MAX_CPU_SCAVS = 15,
        // Number of scavs (vehicles) that'll be left around after a cleanup.
        MIN_CPU_SCAVS_AFTER_CLEANUP = 5,
    };
    enum AIPType {
        AIPType0 = 0,
        AIPType1 = 1,
        AIPType2 = 2,
        AIPType3 = 3,
        AIPTypeA = 4,
        AIPTypeL = 5,
        AIPTypeS = 6,
        MAX_AIP_TYPE = 7,
    };
private:
    // bools
    bool b_first;
    bool m_StartDone;
    bool StopScript; // The whole-game switch for the BZ1Helper / Lua layers.
    bool m_SiegeOn[MAX_TEAMS]; // Per CPU team.
    bool m_AntiAssault[MAX_TEAMS];
    bool m_LateGame[MAX_TEAMS];
    bool m_HaveArmory[MAX_TEAMS];
    bool m_SetFirstAIP;
    bool m_PastAIP0; // true when they've built a recyler building, or we get bored
    bool m_CanRespawn; // true if the user can respawn if died (kill/snipe)
    bool m_HasAllies[MAX_TEAMS];
    bool m_CPUUnitsCanService[MAX_TEAMS];
    bool m_CPUDoDispatch[MAX_TEAMS];
    bool b_last;

    // floats
    float f_first;
    float f;
    float f_last;

    // handles
    Handle h_first;
    Handle m_Obj1;
    Handle m_Player;
    Handle m_Recycler[MAX_TEAMS]; // Each team's recycler (human's at m_StratTeam, CPUs' at m_CompTeam..).
    Handle m_Powerup1;
    Handle m_Powerup2;
    Handle m_Powerup3;
    Handle m_Powerup4;
    Handle m_CPUScavList[MAX_TEAMS][MAX_CPU_SCAVS]; // List of CPU scav handles per team, used during cleanup.
    Handle h_last;

    int m_GameTPS; // How many turns per second there are (10, 15, 20, or 30)

    // integers
    int i_first;
    int m_StratTeam;
    int m_SiegeCounter[MAX_TEAMS];
    int m_AssaultCounter[MAX_TEAMS];
    int m_TimeCount;
    int m_FriendReinforcementTime;
    int m_EndCounter;
    int m_CompTeam; // First CPU team (6).
    int m_PowerupCounter;
    int m_TurnCounter;
    int m_MyForce;
    int m_MyGoal;
    int m_AwareV13;
    int m_CPUTeamRace[MAX_TEAMS]; // replaced mySide
    int m_HumanTeamRace;
    int m_AllyTeams[MAX_TEAMS];
    int m_CompForce;
    int m_Difficulty;
    int m_GoalVal;
    int m_NumCPUScavs[MAX_TEAMS];
    int m_ElapsedGameTime;
    int m_LastTauntPrintedAt;
    int m_CPUCommBunkerCount[MAX_TEAMS];
    int m_LastCPUPlan[MAX_TEAMS];
    // UGLY CODE ALERT -- storing a string in an array of ints. Done
    // because that simplifies the load/save code quite a lot.
    // Avert your eyes if you're with the coding style police.
    int m_CustomAIPInts[8]; // == 32 bytes
    int m_CPUAIDifficultyAddon[MAX_TEAMS];
    int m_CPUMaxPatrolUnits[MAX_TEAMS];
    int m_CPUMaxHuntUnits[MAX_TEAMS];
    int m_CPUMaxEscortUnits[MAX_TEAMS];
    int i_last;
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
    char* m_CustomAIPStr; // Points at m_CustomAIPInts.
    int m_CustomAIPStrLen;
public:
    instantMission();
    virtual ~instantMission();
    virtual bool Load(bool missionSave);
    virtual bool PostLoad(bool missionSave);
    virtual bool Save(bool missionSave);
    virtual void AddObject(Handle h);
    virtual void DeleteObject(Handle h);
    virtual EjectKillRetCodes PlayerEjected(Handle DeadObjectHandle);
    virtual EjectKillRetCodes ObjectKilled(int DeadObjectHandle, int KillersHandle);
    virtual EjectKillRetCodes ObjectSniped(int DeadObjectHandle, int KillersHandle);
    virtual void Execute();
    virtual void DoGenericStrategy();
    virtual PreGetInReturnCodes PreGetIn(const int curWorld, Handle pilotHandle, Handle emptyCraftHandle);
    Handle GetRecyclerHandle(int Team) { return m_Recycler[Team]; }
    void SetRecyclerHandle(int Team, Handle h) { m_Recycler[Team] = h; }
private:
    virtual void Setup();
    virtual void CreateObjectives();
    virtual void TestObjectives();
    void SetCPUAIPlan(instantMission::AIPType Type, int Team);
    void SetupExtraVehicles();
    Handle BuildStartingVehicle(int aTeam, int aRace, char* ODF1, char* ODF2, char* Where, int aGrp = -1, char* Variant = NULL);
    Handle BuildStartingVehicle(int aTeam, int aRace, char* ODF1, char* ODF2, Vector Where, int aGrp = -1, char* Variant = NULL);
    EjectKillRetCodes PlayerDied(int DeadObjectHandle, bool bSniped);
    void AddCPUScav(Handle scavHandle, int Team);
};

DLLBase* BuildMission();

#define VSR_LAYOUT_CHECK_instantMission
#include "vsr_layout_asserts.h"
#undef VSR_LAYOUT_CHECK_instantMission

#endif // _instantmission_
