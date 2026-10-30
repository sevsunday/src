// PROVENANCE: ancestor reference/ancestor-1.3/Missions/LuaMission/LuaMission.h @353698f | declarations original/missions/Strategy02.pdb via tools/pdb_types.py (BZ1Helper base, m_LastTauntPrintedAt, CreateLuaStringTable, PreTeleport, GetNextRandomVehicleODF; member offsets confirmed against dumpbin of the ctor / Setup) | status: ported
#ifndef _luamission_
#define _luamission_

#include "ScriptUtils.h"
#include "lua.hpp"
#include "bz1helper.h"
#include "portalhelper.h"

class DLLBase;

class LuaMission : public BZ1Helper {
    friend struct VsrLayoutCheck_LuaMission; // scaffold: QA gate 2 hook (layout asserts); not GBD's
    int m_GameTPS; // How many turns per second there are (10, 15, 20, or 30)
    lua_State* L;

    // bools
    bool b_first;
    bool DidSetup; // This is the flag that turns off our "Setup" once it's been run.
    bool StopScript; // This is a flag to spawn all pre-placed objects on the map and nothing else.
    bool b_last;

    // integers
    int i_first;
    int m_ElapsedGameTime;
    int m_LastTauntPrintedAt;
    int Difficulty;
    int i_last;
protected:
    bool* b_array;
    int b_count;
    int* i_array;
    int i_count;
public:
    LuaMission();
    virtual ~LuaMission();
    virtual void InitialSetup(); // For initialization for LUA code.
    void Setup(); // This is an optional function, called within Execute. It could be called anything, but since it's run once at start, we use it to setup things for the mission.
    virtual void AddObject(int h);
    virtual void DeleteObject(int h);
    virtual void Execute();
    virtual void PostRun();
    virtual bool Load(bool missionSave);
    virtual bool PostLoad(bool missionSave);
    virtual bool Save(bool missionSave);
    virtual bool AddPlayer(unsigned long id, int Team, bool IsNewPlayer);
    virtual void DeletePlayer(unsigned long id);
    virtual EjectKillRetCodes PlayerEjected(int DeadObjectHandle);
    virtual EjectKillRetCodes ObjectKilled(int DeadObjectHandle, int KillersHandle);
    virtual EjectKillRetCodes ObjectSniped(int DeadObjectHandle, int KillersHandle);
    virtual const char* GetNextRandomVehicleODF(int Team);
    virtual void ProcessCommand(unsigned long crc);
    virtual void SetRandomSeed(unsigned long seed);
    virtual void PreOrdnanceHit(int shooterHandle, int victimHandle, int ordnanceTeam, const char* pOrdnanceODF);
    virtual PreSnipeReturnCodes PreSnipe(const int curWorld, int shooterHandle, int victimHandle, int ordnanceTeam, const char* pOrdnanceODF);
    virtual PreGetInReturnCodes PreGetIn(const int curWorld, int pilotHandle, int emptyCraftHandle);
    virtual PrePickupPowerupReturnCodes PrePickupPowerup(const int curWorld, int me, int powerupHandle);
    virtual void PostTargetChangedCallback(int craft, int previousTarget, int currentTarget);
    // Builds a global table mapping index -> name and name -> index.
    void CreateLuaStringTable(lua_State* L1, const char** StringArray, const int Count, const char* TableName);
    virtual PreTeleportReturnCodes PreTeleport(const int portalHandle, const int shipHandle);
};

DLLBase* BuildMission();

#define VSR_LAYOUT_CHECK_LuaMission
#include "vsr_layout_asserts.h"
#undef VSR_LAYOUT_CHECK_LuaMission

#endif // _luamission_
