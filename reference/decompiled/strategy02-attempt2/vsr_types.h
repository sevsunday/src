typedef unsigned char   undefined;

typedef unsigned char    bool;
typedef unsigned char    byte;
typedef unsigned int    dword;
float10
typedef unsigned long long    GUID;
typedef pointer32 ImageBaseOffset32;

typedef long long    longlong;
typedef signed char    schar;
typedef unsigned char    uchar;
typedef unsigned int    uint;
typedef unsigned long    ulong;
typedef unsigned long long    ulonglong;
typedef unsigned char    undefined1;
typedef unsigned short    undefined2;
typedef unsigned int    undefined4;
typedef unsigned long long    undefined8;
typedef unsigned short    ushort;
typedef unsigned short    wchar16;
typedef unsigned int    wchar32;
typedef short    wchar_t;
typedef unsigned short    word;
typedef struct AIWeaponHelper AIWeaponHelper, *PAIWeaponHelper;

struct AIWeaponHelper {
    undefined field0_0x0;
};

typedef struct AlignTerrainReplaceClass AlignTerrainReplaceClass, *PAlignTerrainReplaceClass;

typedef struct Vector Vector, *PVector;

struct Vector {
    float x;
    float y;
    float z;
};

struct AlignTerrainReplaceClass {
    int AlignHandle;
    struct Vector NormalVec;
};

typedef struct AmbientAudioInfo AmbientAudioInfo, *PAmbientAudioInfo;

struct AmbientAudioInfo {
    int AudioHandle;
    char AudioFile[64];
    int MinDelay;
    int MaxDelay;
    bool IsMusic;
    float BasePan;
    float PanVariance;
    float Rate;
    int TriggerTurn;
    int AudioLength;
    struct Vector Position;
};

typedef struct AmbientSoundHelper AmbientSoundHelper, *PAmbientSoundHelper;

struct AmbientSoundHelper {
    struct AmbientAudioInfo ambientAudioInfo[32];
};

typedef struct AttacherClass AttacherClass, *PAttacherClass;

typedef struct AttacherTapClass AttacherTapClass, *PAttacherTapClass;

typedef struct Matrix Matrix, *PMatrix;

struct Matrix {
    struct Vector right;
    float rightw;
    struct Vector up;
    float upw;
    struct Vector front;
    float frontw;
    struct Vector posit;
    float positw;
};

struct AttacherTapClass {
    int TapObject;
    bool TapIndependance;
    bool TapIsAttacking;
    bool BuiltAttacherTap;
    bool TapShutOff;
    bool TapCoordinateFire;
    bool PDSMode;
    bool IsHostDeployed;
    int TapDeployBehavior;
    float TapEngageRange;
    struct Vector TapOffset;
    struct Vector TapRotation;
    char TapWeaponSymmetryMask[6];
    bool IsCerberusTail;
    bool IsCerberusTailAnimated;
    int CerbTailSwinging;
    float CerbTailConeAngle;
    float CerbAnimLength;
    struct Matrix TapPosition;
};

struct AttacherClass {
    int AttacherObject;
    int NumberOfTaps;
    bool IsCerberus;
    struct AttacherTapClass Tap[8];
};

typedef struct AttacherHelper AttacherHelper, *PAttacherHelper;

typedef struct vector<AttacherHelper::AttacherClass,std::allocator<AttacherHelper::AttacherClass>_> vector<AttacherHelper::AttacherClass,std::allocator<AttacherHelper::AttacherClass>_>, *Pvector<AttacherHelper::AttacherClass,std::allocator<AttacherHelper::AttacherClass>_>;

struct vector<AttacherHelper::AttacherClass,std::allocator<AttacherHelper::AttacherClass>_> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
};

struct AttacherHelper {
    struct vector<AttacherHelper::AttacherClass,std::allocator<AttacherHelper::AttacherClass>_> AttacherList;
};

typedef struct BuildAtClass BuildAtClass, *PBuildAtClass;

struct BuildAtClass {
    int BuilderHandle;
    struct Vector DropoffPos;
    int BuildTurn;
    int Priority;
    int BuilderType;
};

typedef struct BuildingClass BuildingClass, *PBuildingClass;

struct BuildingClass {
    int BuildingObject;
    int BuildingTap[8];
    bool TapAnimated[8];
    bool PlayTapAnim[8];
    struct Matrix TapOffsetMatrix[8];
    bool IsPowered;
    bool IsAnimated;
    bool PlayAnim;
    bool CanCollide;
    bool CanBeIdleVictim;
    bool IsAPCRefill;
    bool IsRecyclePoint;
    bool GunTowerOff;
    bool CanDemolish;
    bool PoweredByTaps;
    bool autoBuildTaps;
    bool OwnsTerrain;
    uint ObjClassHash;
    uint ODFNameHash;
    int PowerType;
    int AnimDir[9];
    int TapNumber;
    int PowerState;
    int PowerMask;
    int PowerMatch;
    int PowerProvide;
    int PowerupAcceptMask;
    int CurTeamNum;
    int PTeam;
    long MaxHealth;
    long MaxAmmo;
    int NumWeapons;
    int TerrainSizeRatio[2];
    int BuildSupport;
    float CollisionRadius;
    char UpgradeName[64];
    char WeaponNames[5][64];
    struct Vector Position;
    struct Vector BuildingFront;
    float HealthRate;
    float AmmoRate;
    float LocalAmmoRate;
    float ServiceRate;
    bool ServiceCraft;
};

typedef struct BuildingHelper BuildingHelper, *PBuildingHelper;

typedef struct vector<BuildingHelper::BuildingClass,std::allocator<BuildingHelper::BuildingClass>_> vector<BuildingHelper::BuildingClass,std::allocator<BuildingHelper::BuildingClass>_>, *Pvector<BuildingHelper::BuildingClass,std::allocator<BuildingHelper::BuildingClass>_>;

struct vector<BuildingHelper::BuildingClass,std::allocator<BuildingHelper::BuildingClass>_> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
};

struct BuildingHelper {
    struct vector<BuildingHelper::BuildingClass,std::allocator<BuildingHelper::BuildingClass>_> BuildingList;
};

typedef struct BZ1Helper BZ1Helper, *PBZ1Helper;

typedef struct DLLBase DLLBase, *PDLLBase;

typedef struct ObjectHelper ObjectHelper, *PObjectHelper;

typedef struct VehicleHelper VehicleHelper, *PVehicleHelper;

typedef struct ProductionClassHelper ProductionClassHelper, *PProductionClassHelper;

typedef struct PowerHelper PowerHelper, *PPowerHelper;

typedef struct PowerupHelper PowerupHelper, *PPowerupHelper;

typedef struct PortalHelper PortalHelper, *PPortalHelper;

typedef struct UtilityShipHelper UtilityShipHelper, *PUtilityShipHelper;

typedef struct ScrapHelper ScrapHelper, *PScrapHelper;

typedef struct DispatchHelper DispatchHelper, *PDispatchHelper;

typedef struct UndeployHelper UndeployHelper, *PUndeployHelper;

typedef struct MorphObjectHelper MorphObjectHelper, *PMorphObjectHelper;

typedef struct CarrierHelper CarrierHelper, *PCarrierHelper;

typedef struct GravityHelper GravityHelper, *PGravityHelper;

typedef struct MapInfo MapInfo, *PMapInfo;

typedef struct TeamInfo TeamInfo, *PTeamInfo;

typedef struct vector<BZ1Helper::AlignTerrainReplaceClass,std::allocator<BZ1Helper::AlignTerrainReplaceClass>_> vector<BZ1Helper::AlignTerrainReplaceClass,std::allocator<BZ1Helper::AlignTerrainReplaceClass>_>, *Pvector<BZ1Helper::AlignTerrainReplaceClass,std::allocator<BZ1Helper::AlignTerrainReplaceClass>_>;

typedef struct vector<BZ1Helper::DeleteAfterDelayClass,std::allocator<BZ1Helper::DeleteAfterDelayClass>_> vector<BZ1Helper::DeleteAfterDelayClass,std::allocator<BZ1Helper::DeleteAfterDelayClass>_>, *Pvector<BZ1Helper::DeleteAfterDelayClass,std::allocator<BZ1Helper::DeleteAfterDelayClass>_>;

typedef struct vector<BZ1Helper::DeploySoundClass,std::allocator<BZ1Helper::DeploySoundClass>_> vector<BZ1Helper::DeploySoundClass,std::allocator<BZ1Helper::DeploySoundClass>_>, *Pvector<BZ1Helper::DeploySoundClass,std::allocator<BZ1Helper::DeploySoundClass>_>;

typedef struct vector<BZ1Helper::BuildAtClass,std::allocator<BZ1Helper::BuildAtClass>_> vector<BZ1Helper::BuildAtClass,std::allocator<BZ1Helper::BuildAtClass>_>, *Pvector<BZ1Helper::BuildAtClass,std::allocator<BZ1Helper::BuildAtClass>_>;

typedef struct vector<char_const_*,std::allocator<char_const_*>_> vector<char_const_*,std::allocator<char_const_*>_>, *Pvector<char_const_*,std::allocator<char_const_*>_>;

typedef struct vector<ObjectHelper::ObjectClass,std::allocator<ObjectHelper::ObjectClass>_> vector<ObjectHelper::ObjectClass,std::allocator<ObjectHelper::ObjectClass>_>, *Pvector<ObjectHelper::ObjectClass,std::allocator<ObjectHelper::ObjectClass>_>;

typedef struct vector<VehicleHelper::VehicleClass,std::allocator<VehicleHelper::VehicleClass>_> vector<VehicleHelper::VehicleClass,std::allocator<VehicleHelper::VehicleClass>_>, *Pvector<VehicleHelper::VehicleClass,std::allocator<VehicleHelper::VehicleClass>_>;

typedef struct vector<PowerHelper::PowerClass,std::allocator<PowerHelper::PowerClass>_> vector<PowerHelper::PowerClass,std::allocator<PowerHelper::PowerClass>_>, *Pvector<PowerHelper::PowerClass,std::allocator<PowerHelper::PowerClass>_>;

typedef struct vector<PowerupHelper::PowerupClass,std::allocator<PowerupHelper::PowerupClass>_> vector<PowerupHelper::PowerupClass,std::allocator<PowerupHelper::PowerupClass>_>, *Pvector<PowerupHelper::PowerupClass,std::allocator<PowerupHelper::PowerupClass>_>;

typedef struct vector<PortalHelper::PortalClass,std::allocator<PortalHelper::PortalClass>_> vector<PortalHelper::PortalClass,std::allocator<PortalHelper::PortalClass>_>, *Pvector<PortalHelper::PortalClass,std::allocator<PortalHelper::PortalClass>_>;

typedef struct vector<PortalHelper::TeleportTargetClass,std::allocator<PortalHelper::TeleportTargetClass>_> vector<PortalHelper::TeleportTargetClass,std::allocator<PortalHelper::TeleportTargetClass>_>, *Pvector<PortalHelper::TeleportTargetClass,std::allocator<PortalHelper::TeleportTargetClass>_>;

typedef struct vector<UtilityShipHelper::UtilityShipClass,std::allocator<UtilityShipHelper::UtilityShipClass>_> vector<UtilityShipHelper::UtilityShipClass,std::allocator<UtilityShipHelper::UtilityShipClass>_>, *Pvector<UtilityShipHelper::UtilityShipClass,std::allocator<UtilityShipHelper::UtilityShipClass>_>;

typedef struct vector<ScrapHelper::ScrapClass,std::allocator<ScrapHelper::ScrapClass>_> vector<ScrapHelper::ScrapClass,std::allocator<ScrapHelper::ScrapClass>_>, *Pvector<ScrapHelper::ScrapClass,std::allocator<ScrapHelper::ScrapClass>_>;

typedef struct vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_> vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>, *Pvector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_>;

typedef struct vector<UndeployHelper::UndeployClass,std::allocator<UndeployHelper::UndeployClass>_> vector<UndeployHelper::UndeployClass,std::allocator<UndeployHelper::UndeployClass>_>, *Pvector<UndeployHelper::UndeployClass,std::allocator<UndeployHelper::UndeployClass>_>;

typedef struct vector<MorphObjectHelper::MorphObjectClass,std::allocator<MorphObjectHelper::MorphObjectClass>_> vector<MorphObjectHelper::MorphObjectClass,std::allocator<MorphObjectHelper::MorphObjectClass>_>, *Pvector<MorphObjectHelper::MorphObjectClass,std::allocator<MorphObjectHelper::MorphObjectClass>_>;

typedef struct vector<CarrierHelper::CarrierClass,std::allocator<CarrierHelper::CarrierClass>_> vector<CarrierHelper::CarrierClass,std::allocator<CarrierHelper::CarrierClass>_>, *Pvector<CarrierHelper::CarrierClass,std::allocator<CarrierHelper::CarrierClass>_>;

typedef struct vector<CarrierHelper::DroneClass,std::allocator<CarrierHelper::DroneClass>_> vector<CarrierHelper::DroneClass,std::allocator<CarrierHelper::DroneClass>_>, *Pvector<CarrierHelper::DroneClass,std::allocator<CarrierHelper::DroneClass>_>;

typedef struct GravityInfo GravityInfo, *PGravityInfo;

struct vector<UtilityShipHelper::UtilityShipClass,std::allocator<UtilityShipHelper::UtilityShipClass>_> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
};

struct UtilityShipHelper {
    struct vector<UtilityShipHelper::UtilityShipClass,std::allocator<UtilityShipHelper::UtilityShipClass>_> UtilityShipList;
};

struct GravityInfo {
    float TranPeriod;
    float OnPeriod;
    float Gravitation;
    float Gravity;
    int OnCounter;
};

struct GravityHelper {
    struct GravityInfo gravityInfo[16];
};

struct vector<char_const_*,std::allocator<char_const_*>_> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
};

struct vector<MorphObjectHelper::MorphObjectClass,std::allocator<MorphObjectHelper::MorphObjectClass>_> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
};

struct MorphObjectHelper {
    int vfptr;
    struct vector<MorphObjectHelper::MorphObjectClass,std::allocator<MorphObjectHelper::MorphObjectClass>_> MorphObjectList;
};

struct vector<UndeployHelper::UndeployClass,std::allocator<UndeployHelper::UndeployClass>_> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
};

struct UndeployHelper {
    struct vector<UndeployHelper::UndeployClass,std::allocator<UndeployHelper::UndeployClass>_> UndeployList;
};

struct vector<ScrapHelper::ScrapClass,std::allocator<ScrapHelper::ScrapClass>_> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
};

struct ScrapHelper {
    struct vector<ScrapHelper::ScrapClass,std::allocator<ScrapHelper::ScrapClass>_> ScrapList;
};

struct vector<CarrierHelper::DroneClass,std::allocator<CarrierHelper::DroneClass>_> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
};

struct DLLBase {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
};

struct vector<PowerupHelper::PowerupClass,std::allocator<PowerupHelper::PowerupClass>_> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
};

struct vector<CarrierHelper::CarrierClass,std::allocator<CarrierHelper::CarrierClass>_> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
};

struct CarrierHelper {
    int vfptr;
    struct vector<CarrierHelper::CarrierClass,std::allocator<CarrierHelper::CarrierClass>_> CarrierList;
    struct vector<CarrierHelper::DroneClass,std::allocator<CarrierHelper::DroneClass>_> DroneList;
};

struct vector<VehicleHelper::VehicleClass,std::allocator<VehicleHelper::VehicleClass>_> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
};

struct VehicleHelper {
    struct vector<VehicleHelper::VehicleClass,std::allocator<VehicleHelper::VehicleClass>_> VehicleList;
};

struct vector<BZ1Helper::BuildAtClass,std::allocator<BZ1Helper::BuildAtClass>_> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
};

struct vector<BZ1Helper::AlignTerrainReplaceClass,std::allocator<BZ1Helper::AlignTerrainReplaceClass>_> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
};

struct TeamInfo {
    int RealPlayer;
    int Player;
    int SatellitePlayer;
    int Recycler;
    int Factory;
    int Armory;
    int Constructor;
    int BaseSlot[9];
    int BaseSlotScrap[9];
    int CommTower;
    int SatelliteOn;
    int SatelliteOff;
    int SatelliteLock;
    int SatelliteLastShooter;
    int ImaPilot;
    int Transport;
    int LimiterObject[3];
    int LimitPlayer;
    int MaxPilots;
    int CurrPilots;
    int m_CPUAIDifficulty;
    int m_CPUPilotCheatAmount;
    int m_CPUMaxPatrolUnits;
    int m_CPUMaxHuntUnits;
    int m_CPUMaxEscortUnits;
    int m_CPUNumPatrolUnits;
    int m_CPUNumHuntUnits;
    int m_CPUNumEscortUnits;
    int ReinforcementCount;
    int NumBarracks;
    int NumTeamObjects;
    int SatelliteViewActive;
    int SatelliteOutOfAmmo;
    long SatelliteSiteCamAmmo;
    int SatellitePrevIndependence;
    int PlayerLives;
    int RespawnTime;
    int DropoffRecylcers;
    int DropoffExtractors;
    int DropoffSilos;
    int BaseSlotBuildCount[9];
    bool PlayedScrapDropVO;
    bool TeamIsDead;
    bool RespawnPlayer;
    bool m_UsePilots;
    bool m_HadPilots;
    bool m_UseLimits;
    bool NoPlayerPilot;
    bool TookControlThisTurn;
    bool BaseSlotUseScrapHold[9];
    bool m_CPUUnitsCanService;
    bool m_CPUDoDispatch;
    bool CommTowerAround;
    bool PlayerWasPilot;
    bool GiveBackWeapons;
    bool PlayCommTowerSound;
    bool UseSiteCamera;
    bool SatelliteObjectify;
    undefined field58_0x125;
    undefined field59_0x126;
    undefined field60_0x127;
    float m_CPUDayWreckerChance;
    float m_CPUDayWreckerInterval;
    float m_CPUPilotCheatDelay;
    float m_CPUBuildingRepairChance;
    float m_CPUBuildingRepairInterval;
    float m_CPUBuildingRepairHealthRatio;
    float m_CPUBuildPodMinDelay;
    float m_CPUBuildPodMaxDelay;
    struct Vector PlayerSpawnPos;
    struct Vector ReinforcementPos;
    struct Vector GoalPos;
    char TeamRace;
    char ArmoryBuildClass[64];
    char PlayerName[64];
    char TeamAIPFile[256];
    char PilotWeapon[5][64];
    char PlayerPilotODF[64];
    char SatelliteODF[64];
    char BaseSlotName[9][64];
    undefined field80_0x6ed;
    undefined field81_0x6ee;
    undefined field82_0x6ef;
    int BaseSlotPilotCost[9][10];
    int BaseSlotScrapCost[9][10];
    bool ShowPilotCosts[9];
    undefined field86_0x9c9;
    undefined field87_0x9ca;
    undefined field88_0x9cb;
    int BaseSlotPlayingAnim[9];
    float BaseSlotAnimationFrames[9];
};

struct vector<BZ1Helper::DeploySoundClass,std::allocator<BZ1Helper::DeploySoundClass>_> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
};

struct MapInfo {
    float Height;
    float MapWidth;
    float MapDepth;
    float MPG;
    float HeightGranularity;
    float MinX;
    float MinZ;
    float MaxWidth;
    float MaxDepth;
    float MinWidth;
    float MinDepth;
    float Gravity;
    int GravityState;
    float MinScrapHeight;
    float MaxScrapHeight;
    bool RestrictAllScrap;
    bool RespawnAtLowAltitude;
    float SpawnMinRadius;
    float SpawnMaxRadius;
};

struct vector<BZ1Helper::DeleteAfterDelayClass,std::allocator<BZ1Helper::DeleteAfterDelayClass>_> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
};

struct BZ1Helper {
    struct DLLBase super_DLLBase;
    struct ObjectHelper *m_ObjectHelper;
    struct VehicleHelper *m_VehicleHelper;
    struct ProductionClassHelper *m_ProductionClassHelper;
    struct PowerHelper *m_PowerHelper;
    struct PowerupHelper *m_PowerupHelper;
    struct BuildingHelper *m_BuildingHelper;
    struct PortalHelper *m_PortalHelper;
    struct AttacherHelper *m_AttacherHelper;
    struct UtilityShipHelper *m_UtilityShipHelper;
    struct ScrapHelper *m_ScrapHelper;
    struct DispatchHelper *m_DispatchHelper;
    struct UndeployHelper *m_UndeployHelper;
    struct AIWeaponHelper *m_AIWeaponHelper;
    struct MorphObjectHelper *m_MorphObjectHelper;
    struct CarrierHelper *m_CarrierHelper;
    struct GravityHelper *m_GravityHelper;
    struct AmbientSoundHelper *m_AmbientSoundHelper;
    struct MapInfo mapInfo;
    struct TeamInfo teamInfo[16];
    struct vector<BZ1Helper::AlignTerrainReplaceClass,std::allocator<BZ1Helper::AlignTerrainReplaceClass>_> AlignTerrainReplaceList;
    struct vector<BZ1Helper::DeleteAfterDelayClass,std::allocator<BZ1Helper::DeleteAfterDelayClass>_> DeleteAfterDelayList;
    struct vector<BZ1Helper::DeploySoundClass,std::allocator<BZ1Helper::DeploySoundClass>_> DeploySoundList;
    struct vector<BZ1Helper::BuildAtClass,std::allocator<BZ1Helper::BuildAtClass>_> BuildAtList;
    int i_first;
    int m_ScrapMultiplier;
    int m_MaxLives;
    int m_LastObjectListCount;
    int m_ReinforcementTime;
    int m_ReinforcementAmount;
    int MissionAudioHandle;
    int MissionAudioFile[16];
    int i_last;
    bool b_first;
    bool m_DidInit;
    bool m_DidSetup;
    bool m_IsFriendlyFireOn;
    bool m_EnableSiteCamMP;
    bool m_UseSkillLevels;
    bool m_BuildPools;
    bool m_SetupPools;
    bool m_CPUUseDayWreckers;
    bool StopAddObject;
    bool StopDeleteObject;
    bool StopAddMorphObject;
    bool b_last;
    undefined field46_0xa26d;
    undefined field47_0xa26e;
    undefined field48_0xa26f;
    float f_first;
    float m_DamageMultiplier;
    float m_ReinforcementMinRadius;
    float m_ReinforcementMaxRadius;
    float m_ReinforcementMaxCliff;
    float f_last;
    bool *b_array;
    int b_count;
    float *f_array;
    int f_count;
    int *i_array;
    int i_count;
    int AIpathCount;
    char **AIpathNames;
    struct vector<char_const_*,std::allocator<char_const_*>_> MLayPathList[16];
    struct vector<char_const_*,std::allocator<char_const_*>_> PatrolPathList[16];
};

struct vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
};

struct vector<ObjectHelper::ObjectClass,std::allocator<ObjectHelper::ObjectClass>_> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
};

struct ObjectHelper {
    struct vector<ObjectHelper::ObjectClass,std::allocator<ObjectHelper::ObjectClass>_> HandleList;
};

struct vector<PowerHelper::PowerClass,std::allocator<PowerHelper::PowerClass>_> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
};

struct PowerHelper {
    struct vector<PowerHelper::PowerClass,std::allocator<PowerHelper::PowerClass>_> PowerList;
};

struct ProductionClassHelper {
    undefined field0_0x0;
};

struct vector<PortalHelper::PortalClass,std::allocator<PortalHelper::PortalClass>_> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
};

struct vector<PortalHelper::TeleportTargetClass,std::allocator<PortalHelper::TeleportTargetClass>_> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
};

struct PortalHelper {
    struct vector<PortalHelper::PortalClass,std::allocator<PortalHelper::PortalClass>_> PortalList;
    struct vector<PortalHelper::TeleportTargetClass,std::allocator<PortalHelper::TeleportTargetClass>_> TeleportTargetList;
};

struct PowerupHelper {
    struct vector<PowerupHelper::PowerupClass,std::allocator<PowerupHelper::PowerupClass>_> PowerupList;
};

struct DispatchHelper {
    int vfptr;
    struct vector<DispatchHelper::DispatchClass,std::allocator<DispatchHelper::DispatchClass>_> DispatchList;
};

typedef struct CarrierClass CarrierClass, *PCarrierClass;

struct CarrierClass {
    int CarrierObject;
    float DroneControlRange;
    float DroneRepairRange;
    float DroneDefendRange;
    float DroneRecallRange;
    float DroneIdleTime;
    int MaxDrones;
    int CurDrones;
    int MinAttackForce;
    long HealthRepairAmount;
    long AmmoRepairAmount;
    bool ServiceAllies;
    undefined field12_0x2d;
    undefined field13_0x2e;
    undefined field14_0x2f;
};

typedef struct CarrierClass.conflict CarrierClass.conflict, *PCarrierClass.conflict;

struct CarrierClass.conflict {
    int CarrierObject;
    float DroneControlRange;
    float DroneRepairRange;
    float DroneDefendRange;
    float DroneRecallRange;
    float DroneIdleTime;
    int MaxDrones;
    int CurDrones;
    int MinAttackForce;
    long HealthRepairAmount;
    long AmmoRepairAmount;
    bool ServiceAllies;
};

typedef struct CloudInfo CloudInfo, *PCloudInfo;

struct CloudInfo {
    int CloudType;
    int CloudTypeCount;
    int CloudCount;
    int CloudTileSize;
    int CloudRandomTypes[16];
    float CloudMaxX;
    float CloudMaxZ;
    float CloudMinX;
    float CloudMinZ;
    int CloudTeam[16];
    float CloudHeight[16];
    char CloudName[16][16][64];
};

typedef struct CommBunkerClass CommBunkerClass, *PCommBunkerClass;

struct CommBunkerClass {
    int CommBunkerObject;
    int CommBunkerBaseSlot;
};

typedef struct DeleteAfterDelayClass DeleteAfterDelayClass, *PDeleteAfterDelayClass;

struct DeleteAfterDelayClass {
    int DeleteAfterDelayHandle;
    int TurnsRemaining;
};

typedef struct DeploySoundClass DeploySoundClass, *PDeploySoundClass;

struct DeploySoundClass {
    int ObjectHandle;
    bool DoesLoop;
    int AudioHandle;
    int StartDelay;
    int RepeatDelay;
    int AudioFileTurns;
    char DeploySound[64];
};

typedef struct DispatchClass DispatchClass, *PDispatchClass;

struct DispatchClass {
    int DispatchObject;
    int DispatchTarget;
    int FleeTarget;
    struct Vector DispatchSpot;
    int CurrTeam;
    int DispatchType;
    int DispatchState;
    bool SkipAIPCheck;
    bool IsCloaker;
    bool IsMorpher;
    bool CanFlee;
    bool CanGetReload;
    bool CanGetRepair;
    bool MorphIsAssault;
    bool IsCloaked;
    bool CloakLocked;
    bool CloakNextTick;
    bool DecloakNextTick;
    int IdleTime;
    int CloakIdleTime;
    int DeployTimer;
    int ServiceTimer;
    float RandomDist;
    float EngageRange;
    float TimeDeploy;
    float CloakChance[54];
    float FleeHealthRatio;
    float GetRepairRatio;
    float ServiceChance;
    long MinFireAmmo;
    long MaxHealth;
    long MaxAmmo;
    int Command;
    int FleeHealthValue;
    int CloakPriority;
};

typedef struct DroneClass DroneClass, *PDroneClass;

struct DroneClass {
    int DroneObject;
    int DroneTarget;
    int CarrierIndex;
    int DroneState;
    int IdleTimer;
    int CarrierWeaponSlot;
    bool UseLocalAmmo;
    bool canSwitchCarrier;
    float RandomTargetDist;
    struct Vector Position;
};

typedef struct EmptyShipClass EmptyShipClass, *PEmptyShipClass;

struct EmptyShipClass {
    int EmptyShipObject;
    int InvulnerabilityTime;
    int SavedHealth;
};

typedef struct LuaMission LuaMission, *PLuaMission;

typedef struct lua_State lua_State, *Plua_State;

struct lua_State {
};

struct LuaMission {
    struct BZ1Helper super_BZ1Helper;
    int m_GameTPS;
    struct lua_State *L;
    bool b_first;
    bool DidSetup;
    bool StopScript;
    bool b_last;
    int i_first;
    int m_ElapsedGameTime;
    int m_LastTauntPrintedAt;
    int Difficulty;
    int i_last;
    bool *b_array;
    int b_count;
    int *i_array;
    int i_count;
};

typedef struct MorphObjectClass MorphObjectClass, *PMorphObjectClass;

struct MorphObjectClass {
    int MorphObject;
    int CurrentWho;
    bool WeaponActive;
    bool ObjectSwitch;
    bool CanFire;
    bool IsCloaker;
    int IdleTime;
    int NormalAmmo;
    int MaxAmmo;
    int Command;
    int PTeam;
    float LocalAmmo[5];
    float MaxLocalAmmo[5];
    float EngageRange;
    float CloakChance[54];
    struct Vector CurrentWhere;
    bool BlockDeploy;
    long CloakMaxEnergy;
    long CloakCurEnergy;
    long CloakCostEnergy;
    long CloakAddEnergy;
    float CloakCurEnergyRemainder;
};

typedef struct MorphTankClass MorphTankClass, *PMorphTankClass;

struct MorphTankClass {
    int MorphTankObject;
    bool CmdSet;
};

typedef struct ObjectClass ObjectClass, *PObjectClass;

struct ObjectClass {
    int ObjectHandle;
    uint ODFNameHash;
    uint ObjClassHash;
    uint BZCClassHash;
    int CategoryID;
    bool CanObjectify;
    bool CanObjectifyDeployed;
    bool CanTeleport;
    bool CanBeIdleVictim;
    int OriginalTeam;
    int CurTeamNum;
    int PTeam;
    float EngageRange;
    bool IsObjectified[16];
    bool IsBeingJammed[16];
    struct Vector Position;
    long MaxHealth;
    long MaxAmmo;
};

typedef struct PortalClass PortalClass, *PPortalClass;

struct PortalClass {
    int TeleporterObject;
    int TeleporterDestination;
    int TeleporterEffectSlot;
    int PortalMineHost;
    bool CanEnter;
    bool CanExit;
    bool MatchTypeUsesChannels;
    bool ExitForwardOnly;
    bool ShowChannel;
    bool NameFlash;
    bool UseCenter;
    bool KickAI;
    bool ContinuousFx;
    bool EnterGotoIsExit;
    bool ScriptOverrideDest;
    bool FxOnVehicle;
    int MatchType;
    int MatchCycleIndex;
    int Channel;
    int DestTeamFilter;
    int TargetTeamFilter;
    int TeleportFilter;
    int EffectType;
    int EffectNumber;
    int EffectState;
    int EffectTimer[16];
    float EnterRange;
    float ExitSpeed;
    float DestMinRange;
    float DestMaxRange;
    float CollisionRadius;
    struct Vector Position;
    struct Vector GotoPoint;
    struct Matrix ExitPoint;
    int DestinationIndex;
    int InEffect;
    int OutEffect;
    int OnEffect;
    int VehInEffect;
    int VehOutEffect;
    float ContinuousFxRange;
    ulong TeleportColorFade;
    char TeleporterName[256];
    char EffectBaseODF[64];
    int EffectHardLifeTime[16];
    char TooFarSound[64];
    char TooCloseSound[64];
    char ActivateSound[64];
    char DeactivateSound[64];
    int SoundHandle;
};

typedef struct PowerClass PowerClass, *PPowerClass;

struct PowerClass {
    int PowerObject;
    bool WasDemolished;
    bool DoBettyLost;
    bool IsPowered;
    int PowerTeam;
    float PowerRange;
    int PowerMask;
    int PowerMatch;
    int PowerProvide;
    struct Vector Position;
};

typedef struct PowerupClass PowerupClass, *PPowerupClass;

struct PowerupClass {
    int PowerupObject;
    uint ObjClassHash;
    long HealthUp;
    long AmmoUp;
    long LocalAmmoUp;
    char WeaponUp[64];
    char SoundPickup[64];
    char SoundReject[64];
    int DelayTime;
    int HitMask;
    struct Vector Position;
    int CurrCommand;
    struct Vector CurrWhere;
    struct Vector Velocity;
};

typedef struct ScrapClass ScrapClass, *PScrapClass;

struct ScrapClass {
    int ScrapObject;
};

typedef struct Strategy02 Strategy02, *PStrategy02;

typedef struct vector<Strategy02::ThugScavengerClass,std::allocator<Strategy02::ThugScavengerClass>_> vector<Strategy02::ThugScavengerClass,std::allocator<Strategy02::ThugScavengerClass>_>, *Pvector<Strategy02::ThugScavengerClass,std::allocator<Strategy02::ThugScavengerClass>_>;

typedef struct vector<Strategy02::ThugPilotClass,std::allocator<Strategy02::ThugPilotClass>_> vector<Strategy02::ThugPilotClass,std::allocator<Strategy02::ThugPilotClass>_>, *Pvector<Strategy02::ThugPilotClass,std::allocator<Strategy02::ThugPilotClass>_>;

typedef struct vector<Strategy02::EmptyShipClass,std::allocator<Strategy02::EmptyShipClass>_> vector<Strategy02::EmptyShipClass,std::allocator<Strategy02::EmptyShipClass>_>, *Pvector<Strategy02::EmptyShipClass,std::allocator<Strategy02::EmptyShipClass>_>;

typedef struct vector<Strategy02::MorphTankClass,std::allocator<Strategy02::MorphTankClass>_> vector<Strategy02::MorphTankClass,std::allocator<Strategy02::MorphTankClass>_>, *Pvector<Strategy02::MorphTankClass,std::allocator<Strategy02::MorphTankClass>_>;

typedef struct vector<Strategy02::CommBunkerClass,std::allocator<Strategy02::CommBunkerClass>_> vector<Strategy02::CommBunkerClass,std::allocator<Strategy02::CommBunkerClass>_>, *Pvector<Strategy02::CommBunkerClass,std::allocator<Strategy02::CommBunkerClass>_>;

struct vector<Strategy02::CommBunkerClass,std::allocator<Strategy02::CommBunkerClass>_> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
};

struct vector<Strategy02::ThugScavengerClass,std::allocator<Strategy02::ThugScavengerClass>_> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
};

struct vector<Strategy02::ThugPilotClass,std::allocator<Strategy02::ThugPilotClass>_> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
};

struct vector<Strategy02::EmptyShipClass,std::allocator<Strategy02::EmptyShipClass>_> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
};

struct vector<Strategy02::MorphTankClass,std::allocator<Strategy02::MorphTankClass>_> {
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
};

struct Strategy02 {
    struct LuaMission super_LuaMission;
    struct vector<Strategy02::ThugScavengerClass,std::allocator<Strategy02::ThugScavengerClass>_> ThugScavengerList;
    struct vector<Strategy02::ThugPilotClass,std::allocator<Strategy02::ThugPilotClass>_> ThugPilotList;
    struct vector<Strategy02::EmptyShipClass,std::allocator<Strategy02::EmptyShipClass>_> EmptyShipList;
    struct vector<Strategy02::MorphTankClass,std::allocator<Strategy02::MorphTankClass>_> MorphTankList;
    struct vector<Strategy02::CommBunkerClass,std::allocator<Strategy02::CommBunkerClass>_> CommBunkerList;
    char PlayerShipODF[16][64];
    char SavedPilotODF[16][64];
    char PlayerSavedName[16][64];
    char PlayerShipWeapons[16][5][64];
    char PlayerPilotWeapons[16][5][64];
    float PlayerPilotLocalAmmo[16][5];
    struct Matrix PlayerMatrix[16];
    struct Vector PlayerVelocity[16];
    struct Vector PlayerOmega[16];
    char MapAmbientSound[64];
    char EmptyShipODF[16][64];
    int m_GameTPS;
    int i_first;
    int m_TotalGameTime;
    int m_RemainingGameTime;
    int m_ElapsedGameTime;
    int m_KillLimit;
    int m_PointsForAIKill;
    int m_KillForAIKill;
    int m_RespawnWithSniper;
    int m_TurretAISkill;
    int m_NonTurretAISkill;
    int m_StartingVehiclesMask;
    int m_SpawnedAtTime[16];
    int m_AllyTeams[16];
    int m_RecyInvulnerabilityTime;
    int m_NumSpawnPoints;
    int NumCommanders;
    int NextAutoAssignTeam;
    int CommanderTeam[16];
    int ThugCounter[16];
    int m_AIRace[5];
    int m_HumanForce;
    int m_CPUForce;
    int m_CPUTurretAISkill;
    int m_CPUNonTurretAISkill;
    int m_LastTauntPrintedAt;
    int m_PlayersSpawned;
    int m_NumCaptureGoals;
    int m_CaptureGoalTime[16];
    int m_CaptureGoalTeam[16];
    int m_GoalBeingCaptured[16];
    int m_CaptureTime;
    int m_GameType;
    int m_PilotInvunerability;
    int m_PilotInvTime[16];
    int m_SavedPilotInvHealth[16];
    int m_SavedPlayerHealth[16];
    int m_SavedPlayerAmmo[16];
    int m_SavedPlayerTeamGroup[16];
    int m_SavedPlayerScrap[16];
    int m_RestorePlayers;
    int BuildEmpty[16];
    int m_MorphTankAutoDeployType;
    int i_last;
    bool b_first;
    bool m_DidInit;
    bool StopScript;
    bool m_HadMultipleFunctioningTeams;
    bool m_TeamIsSetUp[16];
    bool m_NotedRecyclerLocation[16];
    bool m_HasAllies[16];
    bool m_GameOver;
    bool m_CreatingStartingVehicles;
    bool m_RespawnAtLowAltitude;
    bool m_bIsFriendlyFireOn;
    bool m_ThugFlag[16];
    bool m_TeamHasCommander[16];
    bool m_SetThugPilotFlag;
    bool CheckedSVar3;
    bool m_IsMPI;
    bool m_SetFirstAIP;
    bool m_MissionStart;
    bool SpawnAI;
    bool m_CaptureGoalObjectify[16];
    bool m_CaptureGoalIsSwitching[16][16];
    bool m_DualCapture[16];
    bool m_TeamIsCapturing[16];
    bool m_GiveWeaponsBack[16];
    bool m_SavedPlayerDeployed[16];
    bool IsCameraPod[16];
    bool m_SpawnFacingCenter;
    bool b_last;
    float f_first;
    float m_TeamPos[51];
    float m_FRIENDLY_SPAWNPOINT_MAX_ALLY;
    float m_FRIENDLY_SPAWNPOINT_MIN_ENEMY;
    float m_RANDOM_SPAWNPOINT_MIN_ENEMY;
    float m_SavedPlayerLocalAmmo[16][5];
    float f_last;
    int h_first;
    int m_RecyclerHandles[16];
    int m_CaptureGoals[16];
    int UserTarget[16];
    int m_PilotInvUser[16];
    int h_last;
    bool *b_array;
    int b_count;
    float *f_array;
    int f_count;
    int *h_array;
    int h_count;
    int *i_array;
    int i_count;
};

typedef struct TeamInfo.conflict TeamInfo.conflict, *PTeamInfo.conflict;

struct TeamInfo.conflict {
    int RealPlayer;
    int Player;
    int SatellitePlayer;
    int Recycler;
    int Factory;
    int Armory;
    int Constructor;
    int BaseSlot[9];
    int BaseSlotScrap[9];
    int CommTower;
    int SatelliteOn;
    int SatelliteOff;
    int SatelliteLock;
    int SatelliteLastShooter;
    int ImaPilot;
    int Transport;
    int LimiterObject[3];
    int LimitPlayer;
    int MaxPilots;
    int CurrPilots;
    int m_CPUAIDifficulty;
    int m_CPUPilotCheatAmount;
    int m_CPUMaxPatrolUnits;
    int m_CPUMaxHuntUnits;
    int m_CPUMaxEscortUnits;
    int m_CPUNumPatrolUnits;
    int m_CPUNumHuntUnits;
    int m_CPUNumEscortUnits;
    int ReinforcementCount;
    int NumBarracks;
    int NumTeamObjects;
    int SatelliteViewActive;
    int SatelliteOutOfAmmo;
    long SatelliteSiteCamAmmo;
    int SatellitePrevIndependence;
    int PlayerLives;
    int RespawnTime;
    int DropoffRecylcers;
    int DropoffExtractors;
    int DropoffSilos;
    int BaseSlotBuildCount[9];
    bool PlayedScrapDropVO;
    bool TeamIsDead;
    bool RespawnPlayer;
    bool m_UsePilots;
    bool m_HadPilots;
    bool m_UseLimits;
    bool NoPlayerPilot;
    bool TookControlThisTurn;
    bool BaseSlotUseScrapHold[9];
    bool m_CPUUnitsCanService;
    bool m_CPUDoDispatch;
    bool CommTowerAround;
    bool PlayerWasPilot;
    bool GiveBackWeapons;
    bool PlayCommTowerSound;
    bool UseSiteCamera;
    bool SatelliteObjectify;
    float m_CPUDayWreckerChance;
    float m_CPUDayWreckerInterval;
    float m_CPUPilotCheatDelay;
    float m_CPUBuildingRepairChance;
    float m_CPUBuildingRepairInterval;
    float m_CPUBuildingRepairHealthRatio;
    float m_CPUBuildPodMinDelay;
    float m_CPUBuildPodMaxDelay;
    struct Vector PlayerSpawnPos;
    struct Vector ReinforcementPos;
    struct Vector GoalPos;
    char TeamRace;
    char ArmoryBuildClass[64];
    char PlayerName[64];
    char TeamAIPFile[256];
    char PilotWeapon[5][64];
    char PlayerPilotODF[64];
    char SatelliteODF[64];
    char BaseSlotName[9][64];
    int BaseSlotPilotCost[9][10];
    int BaseSlotScrapCost[9][10];
    bool ShowPilotCosts[9];
    int BaseSlotPlayingAnim[9];
    float BaseSlotAnimationFrames[9];
};

typedef struct TeleportTargetClass TeleportTargetClass, *PTeleportTargetClass;

struct TeleportTargetClass {
    int TeleportTarget;
    int TeleportTargetDestination;
    int DestinationIndex;
    float DestEnterRange;
    float DistanceFromDestination;
};

typedef struct ThugPilotClass ThugPilotClass, *PThugPilotClass;

struct ThugPilotClass {
    int ThugPilotObject;
    int SwitchTickTimer;
};

typedef struct ThugScavengerClass ThugScavengerClass, *PThugScavengerClass;

struct ThugScavengerClass {
    int ThugScavengerObject;
    int ScavengerTeam;
};

typedef struct TRNAllies TRNAllies, *PTRNAllies;

struct TRNAllies {
    undefined field0_0x0;
};

typedef struct UndeployClass UndeployClass, *PUndeployClass;

struct UndeployClass {
    int UndeployingObject;
    bool IsAnimated;
    int UndeployTime;
    float UndeployFrames;
};

typedef struct UtilityShipClass UtilityShipClass, *PUtilityShipClass;

struct UtilityShipClass {
    int UtilityShipObject;
    bool DoDrop;
    bool ServiceAllies;
    bool DoDLLDispatch;
    uint ObjClassHash;
    int CurTeamNum;
    int ScrapAmount;
    int EscortPriority;
    int DropClassMask;
    int ServiceTypes;
    struct Vector Position;
};

typedef struct VehicleClass VehicleClass, *PVehicleClass;

struct VehicleClass {
    int ObjectHandle;
    uint ODFNameHash;
    uint ObjClassHash;
    uint BZCClassHash;
    int LastCommand;
    int MaxHealth;
    bool ShowSkill;
    bool BlockDeploy;
    bool AllowRemoteControl;
    bool HuntIsResupply;
    bool CanBeIdleVictim;
    int ShowSkillTeamFilter;
    int ShowSkillTimer;
    int CurTeamNum;
    int PTeam;
    long CloakMaxEnergy;
    long CloakCurEnergy;
    long CloakCostEnergy;
    long CloakAddEnergy;
    float CloakCurEnergyRemainder;
    float EngageRange;
    struct Vector Position;
};

