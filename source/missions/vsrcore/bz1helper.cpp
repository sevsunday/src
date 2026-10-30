// PROVENANCE: ancestor reference/ancestor-bz1helper-2015/Shared/BZ1Helper.cpp @6fda4f5 | declarations original/missions/Strategy02.pdb via tools/pdb_types.py | decompile reference/decompiled/strategy02-ghidra12.2/src/missions/vsrcore/bz1helper.cpp.decomp.c (the 36 surviving procedures) + dumpbin of Strategy02.dll for register-passed arguments; functions with no procedure in any shipped DLL carry a DECOMPILE note saying so (2015 body kept, or reconstructed) | status: ported
#include "bz1helper.h"
#include "objecthelper.h"
#include "vehiclehelper.h"
#include "productionclasshelper.h"
#include "powerhelper.h"
#include "poweruphelper.h"
#include "buildinghelper.h"
#include "portalhelper.h"
#include "attacherhelper.h"
#include "utilityshiphelper.h"
#include "scraphelper.h"
#include "dispatchhelper.h"
#include "undeployhelper.h"
#include "aiweaponhelper.h"
#include "morphobjecthelper.h"
#include "carrierhelper.h"
#include "gravityhelper.h"
#include "ambientsoundhelper.h"
#include "trnallies.h"
#include "taunts.h"
#include "bzcscriptutils.h"
#include <algorithm>
#include <malloc.h>

BZ1Helper* BZ1Helper::m_BZ1Helper;
int BZ1Helper::m_GameTPS;
int BZ1Helper::m_TurnCounter;
int BZ1Helper::TotalMapObjects;
Vector BZ1Helper::OffMapPos;
char BZ1Helper::WorldSetting;
int BZ1Helper::m_GameType;
int BZ1Helper::m_GameVersion;
float BZ1Helper::m_ModVersion;
bool BZ1Helper::Logging;
bool BZ1Helper::InEditor;
float BZ1Helper::HullGauge2;
float BZ1Helper::AmmoGauge2;
float BZ1Helper::AuxGauge;
float BZ1Helper::CloakGauge;
bool BZ1Helper::HullGaugeSet;
bool BZ1Helper::AmmoGaugeSet;
bool BZ1Helper::AuxGaugeSet;
bool BZ1Helper::CloakGaugeSet;
bool BZ1Helper::DeathCameraOn;
int BZ1Helper::DeathCameraTime;
int BZ1Helper::DeathCameraTeam;

// Globals that are NOT saved. -GBD
int m_SwitchTeamA[MAX_TEAMS]; // VSR: `.trn [DLL] MPISwitchTeams%d = "A_B"` — team pairs swapped for MPI / aware-1.3 games.
int m_SwitchTeamB[MAX_TEAMS];

// Constrctor. (No, not the NSDF kind...)
// DECOMPILE: bz1helper.cpp:109-109  @4fc0b0c0  (reference/decompiled/strategy02-ghidra12.2/src/missions/vsrcore/bz1helper.cpp.decomp.c)
BZ1Helper::BZ1Helper(void)
{
	// create helper classes
	m_ObjectHelper = new ObjectHelper();
	m_VehicleHelper = new VehicleHelper();
	m_ProductionClassHelper = new ProductionClassHelper();
	m_PowerHelper = new PowerHelper();
	m_PowerupHelper = new PowerupHelper();
	m_BuildingHelper = new BuildingHelper();
	m_PortalHelper = new PortalHelper();
	m_AttacherHelper = new AttacherHelper();
	m_UtilityShipHelper = new UtilityShipHelper();
	m_ScrapHelper = new ScrapHelper();
	m_DispatchHelper = new DispatchHelper();
	m_UndeployHelper = new UndeployHelper();
	m_AIWeaponHelper = new AIWeaponHelper();
	m_MorphObjectHelper = new MorphObjectHelper();
	m_CarrierHelper = new CarrierHelper();
	m_GravityHelper = new GravityHelper();
	m_AmbientSoundHelper = new AmbientSoundHelper();

	//m_GameTPS = 10; // default
	EnableHighTPS(m_GameTPS);
	TRNAllies::SetupTRNAllies(GetMapTRNFilename()); // GBD: the .trn [DefaultAllies] pairs, read once here.

	b_count = &b_last - &b_first - 1;
	b_array = &b_first + 1;

	f_count = &f_last - &f_first - 1;
	f_array = &f_first + 1;

	i_count = &i_last - &i_first - 1;
	i_array = &i_first + 1;

	// Zero things out first off.
	if(i_array)
		memset(i_array, 0, i_count*sizeof(int));
	if(f_array)
		memset(f_array, 0, f_count*sizeof(float));
	if(b_array)
		memset(b_array, 0, b_count*sizeof(bool));

	// Special things, zero them out too.

	HullGauge2 = 0;
	AmmoGauge2 = 0;
	AuxGauge = 0;

	m_TurnCounter = 0;
	TotalMapObjects = 0;
	WorldSetting = 0;

	AIpathCount = 0;
	AIpathNames = NULL;

	HullGaugeSet = false;
	AmmoGaugeSet = false;
	AuxGaugeSet = false;

	OffMapPos = Vector(-4000, 0, -4000);

	char mapTrnFile[2*MAX_ODF_LENGTH] = {0};
	strcpy_s(mapTrnFile, GetMapTRNFilename());
	if(OpenODF2(mapTrnFile))
	{
		GetODFChar(mapTrnFile, "World", "WorldLetter", &WorldSetting); // Grab the world letter.

		// GBD: MPI (ivar53 == 2 / ivar12 == 1) and the 1.3-aware instant option may swap team pairs: [DLL] MPISwitchTeams1..16 = "A_B".
		if ((IsNetworkOn() && ((GetVarItemInt("network.session.ivar53") == 2) || (GetVarItemInt("network.session.ivar12") == 1))) ||
			(!IsNetworkOn() && IFace_GetInteger("options.instant.awarev13")))
		{
			for (int i = 0; i < MAX_TEAMS; i++)
			{
				char TempODF[MAX_ODF_LENGTH] = {0};
				char DesiredValue[MAX_ODF_LENGTH] = {0};
				sprintf_s(DesiredValue, "MPISwitchTeams%d", i+1);
				if (!GetODFString(mapTrnFile, "DLL", DesiredValue, MAX_ODF_LENGTH, TempODF) || !TempODF[0])
					break;
				m_SwitchTeamA[i] = atoi(TempODF);
				if (char *ptr = strchr(TempODF, '_'))
					m_SwitchTeamB[i] = atoi(ptr + 1);
			}
		}
	}

	Logging = GetVarItemInt("network.session.ivar115") || GetVarItemInt("network.session.civar5"); // Logging Flag.

	// Memset these to 0.
	memset(&mapInfo, 0, sizeof(mapInfo));
	memset(&teamInfo, 0, sizeof(teamInfo));

	m_GameVersion = 20185; // GBD: BZCC 2.0.185, the build this DLL targets (replaced 1.3's Get13Version()).
	float ModVersion = 0.0f;
	if (OpenODF2("PatchData.txt"))
		GetODFFloat("PatchData.txt", "VersionInfo", "Version", &ModVersion, 0.0f);
	m_ModVersion = ModVersion;

	sprintf_s(LogFileName, "VSR"); // GBD: the log file opens later, as "VSR_<date>.log" (OpenLogFile).

	m_BZ1Helper = this;

	PrintConsoleMessage("VSR BZCC DLL Created by General BlackDragon");
	if (DoesFileExist("vsrbasesetup.cfg"))
		IFace_Exec("vsrbasesetup.cfg");
}

// DECOMPILE: bz1helper.cpp:262-327  @4fc0b66b  (reference/decompiled/strategy02-ghidra12.2/src/missions/vsrcore/bz1helper.cpp.decomp.c)
BZ1Helper::~BZ1Helper()
{
	if (Logging)
		FormatLogMessage("Game Ended.\n");

	CloseOpenODFs();
	if (LogFile)
		fclose(LogFile);
	CloseOpenFiles();
	CleanupTaunts();

	if (DeathCameraOn && IsNetworkOn())
		ClearDeathCamera();

	// delete helper classes
	delete m_ObjectHelper;
	delete m_VehicleHelper;
	delete m_ProductionClassHelper;
	delete m_PowerHelper;
	delete m_PowerupHelper;
	delete m_BuildingHelper;
	delete m_PortalHelper;
	delete m_AttacherHelper;
	delete m_UtilityShipHelper;
	delete m_ScrapHelper;
	delete m_DispatchHelper;
	delete m_UndeployHelper;
	delete m_AIWeaponHelper;
	delete m_MorphObjectHelper;
	delete m_CarrierHelper;
	delete m_GravityHelper;
	delete m_AmbientSoundHelper;

	 m_BZ1Helper = NULL;
}

// GBD: the lists and tables as they stood before a Load, for PostLoad's resync report.
std::vector<BZ1Helper::AlignTerrainReplaceClass> TempAlignBuffer;
std::vector<BZ1Helper::DeleteAfterDelayClass> TempDeleteBuffer;
std::vector<BZ1Helper::DeploySoundClass> TempDeploySoundBuffer;
std::vector<BZ1Helper::BuildAtClass> TempBuiltAtBuffer;
BZ1Helper::TeamInfo TempTeamInfoBuffer[MAX_TEAMS];
BZ1Helper::MapInfo TempMapInfoBuffer;

// Load data.
// DECOMPILE: bz1helper.cpp:331-545  @4fc0b943  (reference/decompiled/strategy02-ghidra12.2/src/missions/vsrcore/bz1helper.cpp.decomp.c)
bool BZ1Helper::Load(bool missionSave)
{
	if(missionSave)
		return true;

	// GBD: snapshot everything a resync may change, for PostLoad's reports.
	TempMapInfoBuffer = mapInfo;
	TempAlignBuffer = AlignTerrainReplaceList;
	TempDeleteBuffer = DeleteAfterDelayList;
	TempDeploySoundBuffer = DeploySoundList;
	TempBuiltAtBuffer = BuildAtList;
	for (int i = 0; i < MAX_TEAMS; i++)
		TempTeamInfoBuffer[i] = teamInfo[i];

	bool ret = true;

	ret = ret && Read(&mapInfo, sizeof(mapInfo));

	ret = ret && m_ObjectHelper->Load(missionSave);
	ret = ret && m_VehicleHelper->Load(missionSave);

	int size = 0;
	ret = ret && Read(&size, 1);
	AlignTerrainReplaceList.resize(size);
	if(size)
		ret = ret && Read(&AlignTerrainReplaceList.front(), sizeof(AlignTerrainReplaceClass)*size);

	size = 0;
	ret = ret && Read(&size, 1);
	DeleteAfterDelayList.resize(size);
	if(size)
		ret = ret && Read(&DeleteAfterDelayList.front(), sizeof(DeleteAfterDelayClass)*size);

	size = 0;
	ret = ret && Read(&size, 1);
	DeploySoundList.resize(size);
	if(size)
		ret = ret && Read(&DeploySoundList.front(), sizeof(DeploySoundClass)*size);

	size = 0;
	ret = ret && Read(&size, 1);
	BuildAtList.resize(size);
	if(size)
		ret = ret && Read(&BuildAtList.front(), sizeof(BuildAtClass)*size);

	for (int i = 0; i < MAX_TEAMS; i++)
		ret = ret && Read(&teamInfo[i], sizeof(TeamInfo));

	if(b_array)
		ret = ret && Read(b_array, b_count);
	if(f_array)
		ret = ret && Read(f_array, f_count);
	if(i_array)
		ret = ret && Read(i_array, i_count);

	ret = ret && m_PowerHelper->Load(missionSave);
	ret = ret && m_PowerupHelper->Load(missionSave);
	ret = ret && m_BuildingHelper->Load(missionSave);
	ret = ret && m_PortalHelper->Load(missionSave);
	ret = ret && m_AttacherHelper->Load(missionSave);
	ret = ret && m_UtilityShipHelper->Load(missionSave);
	ret = ret && m_ScrapHelper->Load(missionSave);
	ret = ret && m_DispatchHelper->Load(missionSave);
	ret = ret && m_UndeployHelper->Load(missionSave);
	ret = ret && m_MorphObjectHelper->Load(missionSave);
	ret = ret && m_CarrierHelper->Load(missionSave);
	ret = ret && m_GravityHelper->Load(missionSave);
	ret = ret && m_AmbientSoundHelper->Load(missionSave);

	ret = ret && Read(&m_TurnCounter, 1);
	ret = ret && Read(&TotalMapObjects, 1);
	ret = ret && Read(&OffMapPos, sizeof(OffMapPos));
	ret = ret && Read(&WorldSetting, 1);
	ret = ret && Read(&m_GameType, 1);
	ret = ret && Read(&m_GameVersion, 1);
	ret = ret && Read(&m_ModVersion, 1);

	SetGravity(mapInfo.Gravity);

	// Do onload setup.
	Setup();

	return ret;
}

// DECOMPILE: bz1helper.cpp:549-697  @4fc0c1bd  (reference/decompiled/strategy02-ghidra12.2/src/missions/vsrcore/bz1helper.cpp.decomp.c)
bool BZ1Helper::PostLoad(bool missionSave)
{
	if(missionSave)
		return true;

	bool ret = true;

	ret = ret && m_ObjectHelper->PostLoad(missionSave);
	ret = ret && m_VehicleHelper->PostLoad(missionSave);

	for (std::vector<AlignTerrainReplaceClass>::iterator iter = AlignTerrainReplaceList.begin(); iter != AlignTerrainReplaceList.end(); ++iter)
		ConvertHandles(&iter->AlignHandle, 1);
	for (std::vector<DeleteAfterDelayClass>::iterator iter = DeleteAfterDelayList.begin(); iter != DeleteAfterDelayList.end(); ++iter)
		ConvertHandles(&iter->DeleteAfterDelayHandle, 1);
	for (std::vector<DeploySoundClass>::iterator iter = DeploySoundList.begin(); iter != DeploySoundList.end(); ++iter)
		ConvertHandles(&iter->ObjectHandle, 1);
	for (std::vector<BuildAtClass>::iterator iter = BuildAtList.begin(); iter != BuildAtList.end(); ++iter)
		ConvertHandles(&iter->BuilderHandle, 1);

	for (int i = 0; i < MAX_TEAMS; i++)
		teamInfo[i].ConvertHandles();

	// GBD: report what the resync changed.
	if (!(TempMapInfoBuffer == mapInfo))
		FormatLogMessage("MapInfo Load Mismatch");

	if (TempAlignBuffer.size() == AlignTerrainReplaceList.size())
	{
		for (int i = 0; i < int(AlignTerrainReplaceList.size()); ++i)
		{
			if (!(TempAlignBuffer[i] == AlignTerrainReplaceList[i]))
			{
				FormatLogMessage("AlignTerrainReplaceList Index Mismatch: %d", i);
				break;
			}
		}
	}
	else
	{
		FormatLogMessage("AlignTerrainReplaceList Size Mismatch! Old: %d New: %d", TempAlignBuffer.size(), AlignTerrainReplaceList.size());
	}

	if (TempDeleteBuffer.size() == DeleteAfterDelayList.size())
	{
		for (int i = 0; i < int(DeleteAfterDelayList.size()); ++i)
		{
			if (!(TempDeleteBuffer[i] == DeleteAfterDelayList[i]))
			{
				FormatLogMessage("DeleteAfterDelayList Index Mismatch: %d", i);
				break;
			}
		}
	}
	else
	{
		FormatLogMessage("DeleteAfterDelayList Size Mismatch! Old: %d New: %d", TempDeleteBuffer.size(), DeleteAfterDelayList.size());
	}

	if (TempDeploySoundBuffer.size() == DeploySoundList.size())
	{
		for (int i = 0; i < int(DeploySoundList.size()); ++i)
		{
			if (!(TempDeploySoundBuffer[i] == DeploySoundList[i]))
			{
				FormatLogMessage("DeploySoundList Index Mismatch: %d", i);
				break;
			}
		}
	}
	else
	{
		FormatLogMessage("DeploySoundList Size Mismatch! Old: %d New: %d", TempDeploySoundBuffer.size(), DeploySoundList.size());
	}

	if (TempBuiltAtBuffer.size() == BuildAtList.size())
	{
		for (int i = 0; i < int(BuildAtList.size()); ++i)
		{
			if (!(TempBuiltAtBuffer[i] == BuildAtList[i]))
			{
				FormatLogMessage("BuildAtList Index Mismatch: %d", i);
				break;
			}
		}
	}
	else
	{
		FormatLogMessage("BuildAtList Size Mismatch! Old: %d New: %d", TempBuiltAtBuffer.size(), BuildAtList.size());
	}

	for (int i = 0; i < MAX_TEAMS; i++)
	{
		if (!(TempTeamInfoBuffer[i] == teamInfo[i]))
		{
			FormatLogMessage("TeamInfo Load Mismatch Team: %d", i);
			break;
		}
	}

	ret = ret && m_PowerHelper->PostLoad(missionSave);
	ret = ret && m_PowerupHelper->PostLoad(missionSave);
	ret = ret && m_BuildingHelper->PostLoad(missionSave);
	ret = ret && m_PortalHelper->PostLoad(missionSave);
	ret = ret && m_AttacherHelper->PostLoad(missionSave);
	ret = ret && m_UtilityShipHelper->PostLoad(missionSave);
	ret = ret && m_ScrapHelper->PostLoad(missionSave);
	ret = ret && m_DispatchHelper->PostLoad(missionSave);
	ret = ret && m_UndeployHelper->PostLoad(missionSave);
	ret = ret && m_MorphObjectHelper->PostLoad(missionSave);
	ret = ret && m_CarrierHelper->PostLoad(missionSave);

	return ret;
}

// Save data.
// DECOMPILE: bz1helper.cpp:701-811  @4fc0c58f  (reference/decompiled/strategy02-ghidra12.2/src/missions/vsrcore/bz1helper.cpp.decomp.c)
bool BZ1Helper::Save(bool missionSave)
{
	if(missionSave)
		return true;

	bool ret = true;

	ret = ret && Write(&mapInfo, sizeof(mapInfo));

	ret = ret && m_ObjectHelper->Save(missionSave);
	ret = ret && m_VehicleHelper->Save(missionSave);

	int size = int(AlignTerrainReplaceList.size());
	ret = ret && Write(&size, 1);
	if(size)
		ret = ret && Write(&AlignTerrainReplaceList.front(), sizeof(AlignTerrainReplaceClass)*size);

	size = int(DeleteAfterDelayList.size());
	ret = ret && Write(&size, 1);
	if(size)
		ret = ret && Write(&DeleteAfterDelayList.front(), sizeof(DeleteAfterDelayClass)*size);

	size = int(DeploySoundList.size());
	ret = ret && Write(&size, 1);
	if(size)
		ret = ret && Write(&DeploySoundList.front(), sizeof(DeploySoundClass)*size);

	size = int(BuildAtList.size());
	ret = ret && Write(&size, 1);
	if(size)
		ret = ret && Write(&BuildAtList.front(), sizeof(BuildAtClass)*size);

	for (int i = 0; i < MAX_TEAMS; i++)
		ret = ret && Write(&teamInfo[i], sizeof(TeamInfo));

	if(b_array)
		ret = ret && Write(b_array, b_count);
	if(f_array)
		ret = ret && Write(f_array, f_count);
	if(i_array)
		ret = ret && Write(i_array, i_count);

	ret = ret && m_PowerHelper->Save(missionSave);
	ret = ret && m_PowerupHelper->Save(missionSave);
	ret = ret && m_BuildingHelper->Save(missionSave);
	ret = ret && m_PortalHelper->Save(missionSave);
	ret = ret && m_AttacherHelper->Save(missionSave);
	ret = ret && m_UtilityShipHelper->Save(missionSave);
	ret = ret && m_ScrapHelper->Save(missionSave);
	ret = ret && m_DispatchHelper->Save(missionSave);
	ret = ret && m_UndeployHelper->Save(missionSave);
	ret = ret && m_MorphObjectHelper->Save(missionSave);
	ret = ret && m_CarrierHelper->Save(missionSave);
	ret = ret && m_GravityHelper->Save(missionSave);
	ret = ret && m_AmbientSoundHelper->Save(missionSave);

	ret = ret && Write(&m_TurnCounter, 1);
	ret = ret && Write(&TotalMapObjects, 1);
	ret = ret && Write(&OffMapPos, sizeof(OffMapPos));
	ret = ret && Write(&WorldSetting, 1);
	ret = ret && Write(&m_GameType, 1);
	ret = ret && Write(&m_GameVersion, 1);
	ret = ret && Write(&m_ModVersion, 1);

	return ret;
}

// Every new object passes through here: its master-list entry, the vehicle / building / utility / power / portal / carrier / morph / attacher / undeploy /
// powerup helper registrations, the team counters and the ODF-driven one-offs (unitName2, HeightOffset, AlignToTerrain, PerceivedTeam, DeleteOnLoad, AI weapons).
// DECOMPILE: bz1helper.cpp:817-1524  @4fc0cbb6  (reference/decompiled/strategy02-ghidra12.2/src/missions/vsrcore/bz1helper.cpp.decomp.c) + dumpbin for the
// register-passed arguments and the call list; the helper arguments the decompile lost to LTCG placeholders take the helpers' defaults.
void BZ1Helper::AddObject(Handle h)
{
	PetWatchdogThread();
	TotalMapObjects++;

	if (StopAddObject)
		return;

	char ObjClass[MAX_ODF_LENGTH] = {0};
	if (!GetObjInfo(h, Get_GOClass, ObjClass))
		return;
	const unsigned int ObjClassHash = Hash(ObjClass);
	const bool Network = IsNetworkOn();

	char ODFName[MAX_ODF_LENGTH] = {0};
	GetODFName(h, ODFName);
	const unsigned int ODFNameHash = Hash(ODFName);
	int Team = GetTeamNum(h);
	int HandleIndex = -1;

	if (ObjClassHash == CLASS_SCRAP)
	{
		if (Network)
			SetRandomHeadingAngle2(h);
	}
	else
	{
		const int NumHandles = m_ObjectHelper->GetNumHandles();
		for (int i = 0; i < NumHandles; i++)
		{
			const ObjectHelper::ObjectClass &obj = m_ObjectHelper->GetHandleInfo(i);
			if (obj.ObjectHandle == h)
			{
				if (obj.ODFNameHash == ODFNameHash)
				{
					FormatLogMessage("FIXME: AddObject Skipping Duplicate: %08x, ODF: '%s', Team is: %d, Index is: %d", h, ODFName, Team, i);
					return;
				}
				HandleIndex = i; // Same handle, new ODF: re-use the entry.
				break;
			}
		}
	}

	OffMapPos.x = -4000.0f;
	OffMapPos.z = -4000.0f;
	OffMapPos.y = TerrainFindFloor(-4000.0f, -4000.0f);

	char TempODF1[MAX_ODF_LENGTH] = {0};
	char TempODF2[MAX_ODF_LENGTH] = {0};
	GetAndOpenODFNames(h, TempODF1, TempODF2);

	Vector Position = GetPosition(h);
	char BZCClass[MAX_ODF_LENGTH] = {0};
	GetODFString(TempODF1, TempODF2, "GameObjectClass", "BZCClasslabel", MAX_ODF_LENGTH, BZCClass);
	const unsigned int BZCClassHash = Hash(BZCClass);
	const char *Label = GetLabel(h);
	const long MaxHealth = GetMaxHealth(h);
	const long MaxAmmo = GetMaxAmmo(h);
	int CategoryType = GetCategoryTypeOverride(h);
	if (CategoryType == -1)
		CategoryType = GetCategoryType(h);
	if (CategoryType < 1 || CategoryType > 9)
		CategoryType = 0;

	// GBD: MPI / 1.3-aware games may swap the pre-placed teams ([DLL] MPISwitchTeams%d) — only before Init, only for non-players.
	if (!m_DidInit && (Team > 0) && !IsPlayer(h) &&
		((Network && ((GetVarItemInt("network.session.ivar53") == 2) || (GetVarItemInt("network.session.ivar12") == 1))) || IFace_GetInteger("options.instant.awarev13")))
	{
		for (int i = 0; i < MAX_TEAMS; i++)
		{
			if ((m_SwitchTeamA[i] == Team) && (m_SwitchTeamA[i] != m_SwitchTeamB[i]))
			{
				SetTeamNum(h, m_SwitchTeamB[i]);
				Team = m_SwitchTeamB[i];
			}
		}
	}

	if (MaxHealth > 0)
		teamInfo[Team].NumTeamObjects++;

	char UnitName2[MAX_ODF_LENGTH] = {0};
	GetODFString(TempODF1, TempODF2, "GameObjectClass", "unitName2", MAX_ODF_LENGTH, UnitName2);
	if (UnitName2[0])
		SetObjectiveName(h, UnitName2);

	float HeightOffset = 0.0f;
	if (GetODFFloat(TempODF1, TempODF2, "GameObjectClass", "HeightOffset", &HeightOffset, 0.0f) && HeightOffset != 0.0f)
		Position = Position + Vector(0.0f, HeightOffset, 0.0f);

	bool AlignToTerrain = false;
	if ((m_TurnCounter > 0) && GetODFBool(TempODF1, TempODF2, "GameObjectClass", "AlignToTerrain", &AlignToTerrain, false) && AlignToTerrain)
	{
		// A building that died here aligned to the terrain left its normal behind; else read the terrain.
		Vector Normal(0.0f, 0.0f, 0.0f);
		bool Found = false;
		for (std::vector<AlignTerrainReplaceClass>::iterator iter = AlignTerrainReplaceList.begin(); iter != AlignTerrainReplaceList.end(); ++iter)
		{
			if (iter->AlignHandle == h)
			{
				Normal = iter->NormalVec;
				AlignTerrainReplaceList.erase(iter);
				Found = true;
				break;
			}
		}
		if (!Found)
		{
			float Height = 0.0f;
			TerrainGetHeightAndNormal(Position, Height, Normal, false);
		}
		Vector Front(0.0f, 0.0f, 0.0f);
		GetFront(h, Front);
		Matrix Mat = Build_Orthogonal_Matrix(Normal, Front, Position);
		SetPosition(h, Mat);
		SetVectorPosition(h, Position);
	}
	else if (HeightOffset != 0.0f)
	{
		SetVectorPosition(h, Position);
	}

	const int NumWeapons = GetNumWeapons(h);

	if (ObjClassHash == CLASS_SCRAP)
	{
		m_ScrapHelper->AddScrapObject(h, TempODF1, TempODF2, mapInfo.RestrictAllScrap);
		return; // Scrap goes no further (and skips the dead-team hand-over below).
	}

	// Master Object List entry.
	if (HandleIndex < 0)
		HandleIndex = m_ObjectHelper->NewObject();
	ObjectHelper::ObjectClass &obj = m_ObjectHelper->RefHandleInfo(HandleIndex);
	memset(&obj, 0, sizeof(ObjectHelper::ObjectClass));
	obj.ODFNameHash = ODFNameHash;
	obj.BZCClassHash = BZCClassHash;
	obj.MaxHealth = MaxHealth;
	obj.ObjClassHash = ObjClassHash;
	obj.MaxAmmo = MaxAmmo;

	if (IsCraft(h, ObjClassHash))
		obj.CategoryID = CategoryType_Craft;
	else if (IsBuildingOrGunTower(h, ObjClassHash))
		obj.CategoryID = CategoryType_Building;
	else if (IsPerson(h))
		obj.CategoryID = CategoryType_Person;
	else if (IsPowerup(h))
		obj.CategoryID = CategoryType_Powerup;
	else if (IsWeapon(h, ObjClassHash))
		obj.CategoryID = CategoryType_Weapon;
	else
	{
		bool IsScrapClass = false;
		if (ObjClassHash == 0)
		{
			char TempClass[MAX_ODF_LENGTH] = {0};
			IsScrapClass = GetObjInfo(h, Get_GOClass, TempClass) && (_stricmp(TempClass, "CLASS_SCRAP") == 0);
		}
		if (IsScrapClass)
			obj.CategoryID = CategoryType_Scrap;
		else if (IsMisc(h, ObjClassHash))
			obj.CategoryID = CategoryType_Other;
	}

	// HQCP objectify defaults: not for scrap / misc, and not for detectors that scan every team (scanTeamLimit 3).
	bool DefaultObjectify = !((obj.CategoryID == CategoryType_Other) || (obj.CategoryID == CategoryType_Scrap));
	bool CanDetect = true;
	int ScanTeamLimit = 0;
	GetODFBool(TempODF1, TempODF2, "GameObjectClass", "canDetect", &CanDetect, DefaultObjectify);
	GetODFInt(TempODF1, TempODF2, "GameObjectClass", "scanTeamLimit", &ScanTeamLimit, 0);
	if (CanDetect && (ScanTeamLimit == 3))
		DefaultObjectify = false;
	GetODFBool(TempODF1, TempODF2, "GameObjectClass", "CanHQCPObjectify", &obj.CanObjectify, DefaultObjectify);
	if (obj.CanObjectify)
		GetODFBool(TempODF1, TempODF2, "GameObjectClass", "CanHQCPObjectifyDeployed", &obj.CanObjectifyDeployed, true);

	// Teleport default: craft, powerups, pilots and the ordnance-like classes — never camera pods, nav beacons, portals or portal switches.
	bool DefaultTeleport = false;
	if (((obj.CategoryID == CategoryType_Craft) || (obj.CategoryID == CategoryType_Powerup) || (obj.CategoryID == CategoryType_Person) ||
		(ObjClassHash == CLASS_TORPEDO) || (ObjClassHash == CLASS_SEEKER) || (ObjClassHash == CLASS_ARTIFACT) || (ObjClassHash == CLASS_BOID) || (ObjClassHash == CLASS_FLAG)) &&
		(ObjClassHash != CLASS_POWERUP_CAMERA) && (ObjClassHash != CLASS_NAVBEACON) && (BZCClassHash != BZCCLASS_PORTAL))
		DefaultTeleport = (BZCClassHash != BZCCLASS_PORTAL_SWITCH);
	GetODFBool(TempODF1, TempODF2, "GameObjectClass", "CanTeleport", &obj.CanTeleport, DefaultTeleport);
	GetODFBool(TempODF1, TempODF2, "GameObjectClass", "CanBeIdleVictim", &obj.CanBeIdleVictim, true);

	if (IsCraftOrPerson(h))
	{
		if (MaxAmmo != 0)
			obj.EngageRange = GetEngageRange(h);
		bool AutoSetGroup = false;
		if (GetODFBool(TempODF1, TempODF2, "GameObjectClass", "AutoSetGroup", &AutoSetGroup, false) && AutoSetGroup)
			SetBestGroup(h);
	}

	obj.ObjectHandle = h;
	obj.OriginalTeam = Team;
	obj.CurTeamNum = Team;
	obj.Position = Position;

	if ((obj.CategoryID == CategoryType_Craft) || (obj.CategoryID == CategoryType_Person))
	{
		// Vehicle list entry.
		int VehicleIndex = -1;
		for (int i = 0; i < m_VehicleHelper->GetNumVehicles(); i++)
		{
			if (m_VehicleHelper->GetVehicleInfo(i).ObjectHandle == h)
			{
				VehicleIndex = i;
				break;
			}
		}
		if (VehicleIndex < 0)
			VehicleIndex = m_VehicleHelper->NewVehicle();
		VehicleHelper::VehicleClass &veh = m_VehicleHelper->RefVehicleInfo(VehicleIndex);
		memset(&veh, 0, sizeof(VehicleHelper::VehicleClass));
		veh.ODFNameHash = ODFNameHash;
		veh.ObjClassHash = ObjClassHash;
		veh.BZCClassHash = BZCClassHash;

		bool CanAICloak = false;
		if (ObjClassHash == CLASS_MORPHTANK)
		{
			bool HiddenWhenMorphed = false;
			if (GetODFBool(TempODF1, TempODF2, "MorphTankClass", "HiddenWhenMorphed", &HiddenWhenMorphed, false) && HiddenWhenMorphed)
			{
				GetODFBool(TempODF1, TempODF2, "CraftClass", "CanAICloak", &CanAICloak, HiddenWhenMorphed);
				GetODFLong(TempODF1, TempODF2, "GameObjectClass", "MaxCloakEnergy", &veh.CloakMaxEnergy, 0);
				veh.CloakCurEnergy = veh.CloakMaxEnergy;
				GetODFLong(TempODF1, TempODF2, "GameObjectClass", "CloakEnergyCost", &veh.CloakCostEnergy, 0);
				GetODFLong(TempODF1, TempODF2, "GameObjectClass", "AddCloakEnergy", &veh.CloakAddEnergy, 0);
			}
		}
		else if (BZCClassHash == BZCCLASS_MORPH_OBJECT)
		{
			GetODFBool(TempODF1, TempODF2, "CraftClass", "CanAICloak", &CanAICloak, false);
		}

		GetODFBool(TempODF1, TempODF2, "GameObjectClass", "ShowSkill", &veh.ShowSkill, MaxAmmo > 0);
		GetODFInt(TempODF1, TempODF2, "GameObjectClass", "ShowSkillTeamFilter", &veh.ShowSkillTeamFilter, 3);
		if (veh.ShowSkillTeamFilter == 0)
			veh.ShowSkillTeamFilter = -1;
		GetODFBool(TempODF1, TempODF2, "CraftClass", "CanRemoteControl", &veh.AllowRemoteControl, false);
		GetODFBool(TempODF1, TempODF2, "CraftClass", "HuntIsResupply", &veh.HuntIsResupply, false);
		int TempEscortPriority = 0;
		GetODFInt(TempODF1, TempODF2, "CraftClass", "AIEscortPriority", &TempEscortPriority, 0);
		TempEscortPriority = clamp(TempEscortPriority, 0, 3);

		if (MaxAmmo != 0)
			veh.EngageRange = obj.EngageRange;
		veh.CurTeamNum = Team;
		veh.MaxHealth = MaxHealth;
		veh.ObjectHandle = h;
		veh.Position = Position;
		veh.CanBeIdleVictim = obj.CanBeIdleVictim;

		// Cloakers, minelayers, patrol / hunt ships and anything labelled escort* / patrol* / hunter* go to the dispatcher.
		if (CanAICloak || (BZCClassHash == BZCCLASS_MINELAYER) || (Label && (_strnicmp(Label, "escort", 6) == 0)) ||
			(BZCClassHash == BZCCLASS_PATROL_SHIP) || (Label && (_strnicmp(Label, "patrol", 6) == 0)) ||
			(BZCClassHash == BZCCLASS_HUNT_SHIP) || (Label && (_strnicmp(Label, "hunter", 6) == 0)))
			m_DispatchHelper->AddToDispatch(h, 5.0f, false, 0, true, false, false, false);

		if ((ObjClassHash == CLASS_SCAVENGER) || (ObjClassHash == CLASS_SCAVENGERH) || (ObjClassHash == CLASS_MINELAYER) || (ObjClassHash == CLASS_TUG) ||
			(ObjClassHash == CLASS_CONSTRUCTIONRIG) || (ObjClassHash == CLASS_CONSTRUCTIONRIGT) || (BZCClassHash == BZCCLASS_APC) || (ObjClassHash == CLASS_APC) ||
			(ObjClassHash == CLASS_SERVICE) || (ObjClassHash == CLASS_SERVICEH) || TempEscortPriority) // APC, or ODF override.
			m_UtilityShipHelper->AddUtilityShipObject(h, Team, Position, ObjClassHash, BZCClassHash, TempODF1, TempODF2, TempEscortPriority);
	}
	else
	{
		bool IsDeposit = false;
		if (ObjClassHash == 0)
		{
			char TempClass[MAX_ODF_LENGTH] = {0};
			IsDeposit = GetObjInfo(h, Get_GOClass, TempClass) && (_stricmp(TempClass, "CLASS_DEPOSIT") == 0);
		}
		else
		{
			IsDeposit = (ObjClassHash == CLASS_DEPOSIT);
		}

		if ((obj.CategoryID == CategoryType_Building) || IsDeposit)
		{
			m_BuildingHelper->AddBuildingObject(h, TempODF1, TempODF2, Team, ODFNameHash, ObjClassHash, BZCClassHash, obj.CanBeIdleVictim, NumWeapons, false); // the last argument is an LTCG placeholder at this call site.

			// VSR: a building's deploy sound — delayed or looping ones go to the DeploySoundList, immediate ones play now.
			char DeploySound[MAX_ODF_LENGTH] = {0};
			if (GetODFString(TempODF1, TempODF2, "BuildingClass", "DeploySound", MAX_ODF_LENGTH, DeploySound))
			{
				float StartDelay = 0.0f;
				bool DoesLoop = false;
				GetODFFloat(TempODF1, TempODF2, "BuildingClass", "DeploySoundStartDelay", &StartDelay, 0.0f);
				GetODFBool(TempODF1, TempODF2, "BuildingClass", "DeploySoundLoop", &DoesLoop, false);
				if ((StartDelay > 0.0f) || DoesLoop)
				{
					DeploySoundList.resize(DeploySoundList.size()+1);
					DeploySoundClass &sao = DeploySoundList[DeploySoundList.size()-1]; // No temporary being created, *much* faster
					memset(&sao, 0, sizeof(DeploySoundClass)); // Zero things out at start.

					float RepeatDelay = 0.0f;
					GetODFFloat(TempODF1, TempODF2, "BuildingClass", "DeploySoundRepeatDelay", &RepeatDelay, 0.0f);
					sao.ObjectHandle = h;
					strcpy_s(sao.DeploySound, DeploySound);
					sao.DoesLoop = DoesLoop;
					sao.StartDelay = SecondsToTurns(StartDelay);
					sao.RepeatDelay = SecondsToTurns(RepeatDelay);
				}
				else
				{
					StartAudio3D(DeploySound, h, AUDIO_CAT_AMBIENT, false, false);
				}
			}
		}
	}

	int PerceivedTeam = -1;
	if (GetODFInt(TempODF1, TempODF2, "GameObjectClass", "PerceivedTeam", &PerceivedTeam, -1) && (PerceivedTeam >= 0) && (GetPerceivedTeam(h) != PerceivedTeam))
		SetPerceivedTeam(h, PerceivedTeam);

	bool DeleteOnLoad = false;
	if (GetODFBool(TempODF1, TempODF2, "GameObjectClass", "DeleteOnLoad", &DeleteOnLoad, false) && DeleteOnLoad)
		DeleteAfterDelay(h, 0.0f);

	// An AI team with an armory hands its new armed units random weapons.
	if (teamInfo[Team].m_CPUAIDifficulty && NumWeapons && GetObjectByTeamSlot(Team, DLL_TEAM_SLOT_ARMORY))
		m_AIWeaponHelper->AIGiveWeapons(h, Team, NumWeapons);

	m_AttacherHelper->AddAttacherObject(h, TempODF1, TempODF2, BZCClassHash, ODFName);

	if (_strnicmp(ODFName, "BZCundep", 8) == 0)
		m_UndeployHelper->AddUndeployObject(h, Team, ODFName);

	if (CategoryType || (BZCClassHash == BZCCLASS_RECYCLER) || (BZCClassHash == BZCCLASS_FACTORY) || (BZCClassHash == BZCCLASS_ARMORY) || (BZCClassHash == BZCCLASS_CONSTRUCTOR))
		m_ProductionClassHelper->AddProductionClassObject(h, TempODF1, TempODF2, Team, ObjClassHash, BZCClassHash, CategoryType);

	switch (BZCClassHash)
	{
	case BZCCLASS_CARRIER:
		m_CarrierHelper->AddCarrierObject(h, TempODF1, TempODF2);
		break;
	case BZCCLASS_PORTAL:
	case BZCCLASS_PORTAL_MINE:
		m_PortalHelper->AddPortalObject(h, TempODF1, TempODF2, BZCClassHash);
		break;
	case BZCCLASS_MORPH_OBJECT:
		m_MorphObjectHelper->AddMorphObjectHostObject(h, TempODF1, TempODF2);
		break;
	case BZCCLASS_PORTAL_SWITCH:
		m_PortalHelper->AddPortalSwitchObject(h, TempODF1, TempODF2);
		break;
	case BZCCLASS_MORPH_OBJECT_TOGGLE:
		m_MorphObjectHelper->AddMorphObjectToggleObject(h);
		break;
	case BZCCLASS_POWERPLANT:
		m_PowerHelper->AddPowerObject(h, TempODF1, TempODF2);
		break;
	case BZCCLASS_CARRIER_DRONE:
		m_CarrierHelper->AddCarrierDroneObject(h, Team, TempODF1, TempODF2, ODFName);
		break;
	}

	bool ScrapDropPoint = true;
	switch (ObjClassHash)
	{
	case CLASS_SILO:
		GetODFBool(TempODF1, TempODF2, "SiloClass", "ScrapDropPoint", &ScrapDropPoint, true);
		if (ScrapDropPoint)
			teamInfo[Team].DropoffSilos++;
		break;
	case CLASS_EXTRACTOR:
		GetODFBool(TempODF1, TempODF2, "ExtractorClass", "ScrapDropPoint", &ScrapDropPoint, true);
		if (ScrapDropPoint)
			teamInfo[Team].DropoffExtractors++;
		break;
	case CLASS_RECYCLER:
		GetODFBool(TempODF1, TempODF2, "RecyclerClass", "ScrapDropPoint", &ScrapDropPoint, true);
		if (ScrapDropPoint)
			teamInfo[Team].DropoffRecylcers++;
		break;
	case CLASS_BARRACKS:
		teamInfo[Team].NumBarracks++;
		break;
	case CLASS_RECYCLERVEHICLE:
	case CLASS_RECYCLERVEHICLEH:
		if (!teamInfo[Team].TeamRace)
			teamInfo[Team].TeamRace = GetRace(h);
		if (!m_BuildPools)
			GetODFBool(TempODF1, TempODF2, "GameObjectClass", "UseBZ2Pools", &m_BuildPools, false);
		break;
	case CLASS_SCAVENGER:
	case CLASS_SCAVENGERH:
		{
			// Preload the drop building so the first deploy doesn't stall.
			char DeployClass[MAX_ODF_LENGTH] = {0};
			GetODFString(TempODF1, TempODF2, (ObjClassHash == CLASS_SCAVENGER) ? "ScavengerClass" : "ScavengerHClass", "deployClass", MAX_ODF_LENGTH, DeployClass);
			if (DeployClass[0] && DoesODFExist(DeployClass))
			{
				PetWatchdogThread();
				PreloadODF(DeployClass);
				PetWatchdogThread();
			}
		}
		break;
	case CLASS_WEAPON:
	case CLASS_POWERUP_SERVICE:
	case CLASS_POWERUP_REPAIR:
	case CLASS_POWERUP_RELOAD:
		m_PowerupHelper->AddPowerupObject(h, TempODF1, TempODF2, 1, ObjClassHash);
		break;
	}

	// A dead team's new object goes to the commander team (teamplay) or to team 15.
	if (teamInfo[Team].TeamIsDead)
	{
		if (IsTeamplayOn())
		{
			SetTeamNum(h, GetCommanderTeam(Team));
		}
		else
		{
			Stop(h, 1);
			SetTeamNum(h, 15);
		}
	}
}

// DECOMPILE: bz1helper.cpp:1528-1695  @4fc0e0b1  (reference/decompiled/strategy02-ghidra12.2/src/missions/vsrcore/bz1helper.cpp.decomp.c) + dumpbin for the register-passed arguments
// Object removed: the counters, the dispatcher, a dying power plant's WasDemolished flag, the scrap drop-off / barracks counts, and the terrain-restore
// entry a deployed producer / scavenger leaves behind when its deploy building aligns to terrain.
void BZ1Helper::DeleteObject(Handle h)
{
	TotalMapObjects--;
	m_LastObjectListCount--;

	if (StopDeleteObject)
		return;

	char ObjClass[MAX_ODF_LENGTH] = {0};
	GetObjInfo(h, Get_GOClass, ObjClass);
	const unsigned int ObjClassHash = Hash(ObjClass);
	if (ObjClassHash == CLASS_SCRAP)
		return;

	char ODFName[MAX_ODF_LENGTH] = {0};
	char TempODF1[MAX_ODF_LENGTH] = {0};
	char TempODF2[MAX_ODF_LENGTH] = {0};
	GetAndOpenODFNames(h, TempODF1, TempODF2, ODFName);

	const int Team = GetTeamNum(h);
	const long MaxHealth = GetMaxHealth(h);
	Vector Position(0.0f, 0.0f, 0.0f);
	GetPosition2(h, Position);

	char BZCClass[MAX_ODF_LENGTH] = {0};
	GetODFString(TempODF1, TempODF2, "GameObjectClass", "BZCClasslabel", MAX_ODF_LENGTH, BZCClass);
	const unsigned int BZCClassHash = Hash(BZCClass);

	if (MaxHealth > 0)
		teamInfo[Team].NumTeamObjects--;

	if (IsCraft(h, ObjClassHash) || IsPerson(h))
		m_DispatchHelper->DeleteDispatchObject(h, Team);

	if (BZCClassHash == BZCCLASS_POWERPLANT)
	{
		for (int i = 0; i < m_PowerHelper->GetNumPowerObjects(); i++)
		{
			if (m_PowerHelper->GetPowerInfo(i).PowerObject == h)
			{
				if (IsAround(h))
					m_PowerHelper->RefPowerInfo(i).WasDemolished = true;
				break;
			}
		}
	}

	bool ScrapDropPoint = true;
	switch (ObjClassHash)
	{
	case CLASS_RECYCLER:
		if (!GetODFBool(TempODF1, TempODF2, "RecyclerClass", "ScrapDropPoint", &ScrapDropPoint, true) || !ScrapDropPoint)
			return;
		teamInfo[Team].DropoffRecylcers--;
		return;
	case CLASS_EXTRACTOR:
		if (!GetODFBool(TempODF1, TempODF2, "ExtractorClass", "ScrapDropPoint", &ScrapDropPoint, true) || !ScrapDropPoint)
			return;
		teamInfo[Team].DropoffExtractors--;
		return;
	case CLASS_SILO:
		if (!GetODFBool(TempODF1, TempODF2, "SiloClass", "ScrapDropPoint", &ScrapDropPoint, true) || !ScrapDropPoint)
			return;
		teamInfo[Team].DropoffSilos--;
		return;
	case CLASS_BARRACKS:
		teamInfo[Team].NumBarracks--;
		return;
	case CLASS_RECYCLERVEHICLE:
	case CLASS_RECYCLERVEHICLEH:
	case CLASS_DEPLOYBUILDING:
	case CLASS_DEPLOYBUILDINGH:
	case CLASS_SCAVENGER:
	case CLASS_SCAVENGERH:
		break;
	default:
		return;
	}

	if (!IsDeployed(h))
		return;

	// The deployed producer / scavenger is gone: if its deploy building aligned to the terrain, remember to put the terrain back.
	char DeployODF[MAX_ODF_LENGTH] = {0};
	if ((ObjClassHash == CLASS_RECYCLERVEHICLE) || (ObjClassHash == CLASS_RECYCLERVEHICLEH) || (ObjClassHash == CLASS_DEPLOYBUILDING) || (ObjClassHash == CLASS_DEPLOYBUILDINGH))
	{
		GetODFString(TempODF1, TempODF2, "DeployBuildingClass", "deployName", MAX_ODF_LENGTH, DeployODF);
	}
	else if (!GetODFString(TempODF1, TempODF2, "ScavengerClass", "deployClass", MAX_ODF_LENGTH, DeployODF))
	{
		GetODFString(TempODF1, TempODF2, "ScavengerHClass", "deployClass", MAX_ODF_LENGTH, DeployODF);
	}

	if (DeployODF[0])
	{
		bool AlignToTerrain = false;
		char DeployODFFile[MAX_ODF_LENGTH] = {0};
		CombineStrings(DeployODFFile, DeployODF, ".odf", MAX_ODF_LENGTH);
		if (GetODFBool(DeployODFFile, NULL, "GameObjectClass", "AlignToTerrain", &AlignToTerrain, false) && AlignToTerrain)
		{
			for (std::vector<AlignTerrainReplaceClass>::iterator iter = AlignTerrainReplaceList.begin(); iter != AlignTerrainReplaceList.end(); ++iter)
			{
				if (iter->AlignHandle == h)
					return;
			}

			AlignTerrainReplaceList.resize(AlignTerrainReplaceList.size()+1);
			AlignTerrainReplaceClass &sao = AlignTerrainReplaceList[AlignTerrainReplaceList.size()-1]; // No temporary being created, *much* faster
			memset(&sao, 0, sizeof(AlignTerrainReplaceClass)); // Zero things out at start.

			Vector Normal(0.0f, 0.0f, 0.0f);
			float Height = 0.0f;
			TerrainGetHeightAndNormal(Position, Height, Normal, false);
			sao.NormalVec = Normal;
			sao.AlignHandle = h;
		}
	}
}

// Static bullocks, These are NOT saved. -GBD
static bool GotPaths = false;

// DECOMPILE: bz1helper.cpp:2029-2432  @4fc0f04b  (reference/decompiled/strategy02-ghidra12.2/src/missions/vsrcore/bz1helper.cpp.decomp.c)
// The per-tick driver: path tables once, Init / Setup once, the four BZ1Helper lists, per-team housekeeping, then every helper's Execute in the shipped order.
void BZ1Helper::Execute(void)
{
	// This is here to get the MLay/Patrol paths at every start/load, since this isn't saved.
	if(!GotPaths)
	{
		GetAiPaths(AIpathCount, const_cast<char **&>(AIpathNames));
		GotPaths = true;

		for (int i = 0; i < AIpathCount; ++i)
		{
			const char *label = AIpathNames[i];

			int teamNum = 0, pathNum = 0;

			if (sscanf_s(label, "%dMLay%d", &teamNum, &pathNum) == 2)
				MLayPathList[teamNum].push_back(label);
			else if (sscanf_s(label, "%dPatrol%d", &teamNum, &pathNum) == 2)
				PatrolPathList[teamNum].push_back(label);
		}
	}
	// Do one time server init.
	if(!m_DidInit)
		Init();
	// Do this too? Just in case Load didn't call it for some reason.
	if(!m_DidSetup)
		Setup();

	m_TurnCounter++; // Count Stuff, just because.

	if(m_TurnCounter < SecondsToTurns(60.0f)) // Wait 60 seconds before letting the Watchdog Thread close the game. -[GBD]
		PetWatchdogThread();

	// Cleanup Structs here.
	AlignTerrainReplaceList.erase(std::remove_if(AlignTerrainReplaceList.begin(), AlignTerrainReplaceList.end(), ShouldRemoveAlignTerrainReplace), AlignTerrainReplaceList.end());
	DeleteAfterDelayList.erase(std::remove_if(DeleteAfterDelayList.begin(), DeleteAfterDelayList.end(), ShouldRemoveDeleteAfterDelay), DeleteAfterDelayList.end());
	DeploySoundList.erase(std::remove_if(DeploySoundList.begin(), DeploySoundList.end(), ShouldRemoveDeploySound), DeploySoundList.end());
	BuildAtList.erase(std::remove_if(BuildAtList.begin(), BuildAtList.end(), ShouldRemoveBuildAt), BuildAtList.end());

	// Run DeleteObject loading here.
	for (std::vector<DeleteAfterDelayClass>::iterator iter = DeleteAfterDelayList.begin(); iter != DeleteAfterDelayList.end(); ++iter)
	{
		--iter->TurnsRemaining;

		if(iter->TurnsRemaining < 0)
			RemoveObject(iter->DeleteAfterDelayHandle);
	}

	// VSR: deploy sounds. A one-shot plays when its delay runs out; a looping one follows the building's power (restarted every RepeatDelay turns when it is a repeat, not a true loop).
	for (std::vector<DeploySoundClass>::iterator iter = DeploySoundList.begin(); iter != DeploySoundList.end(); ++iter)
	{
		if (iter->StartDelay < 1)
		{
			if (!iter->DoesLoop)
			{
				StartAudio3D(iter->DeploySound, iter->ObjectHandle, AUDIO_CAT_AMBIENT, false, false);
			}
			else
			{
				DLLAudioHandle AudioHandle = iter->AudioHandle;
				const bool Playing = IsAudioPlaying(AudioHandle);
				if (m_BuildingHelper->IsBuildingPowered(iter->ObjectHandle))
				{
					if (!Playing)
					{
						if (iter->RepeatDelay < 1)
						{
							iter->AudioHandle = StartAudio3D(iter->DeploySound, iter->ObjectHandle, AUDIO_CAT_AMBIENT, true, false);
							iter->AudioFileTurns = SecondsToTurns(GetAudioFileDuration(iter->AudioHandle));
						}
						else
						{
							iter->AudioHandle = StartAudio3D(iter->DeploySound, iter->ObjectHandle, AUDIO_CAT_AMBIENT, false, false);
							iter->AudioFileTurns = SecondsToTurns(GetAudioFileDuration(iter->AudioHandle));
							iter->StartDelay = iter->RepeatDelay + iter->AudioFileTurns;
						}
					}
				}
				else if (Playing)
				{
					StopAudio(iter->AudioHandle);
					iter->AudioHandle = 0;
				}
			}
		}
		else
		{
			iter->StartDelay--;
		}
	}

	// VSR: BuildAt orders come due the turn after they were queued: deploy (constructor), done (recycler / factory) or drop off (armory) at the drop-off position.
	for (std::vector<BuildAtClass>::iterator iter = BuildAtList.begin(); iter != BuildAtList.end(); ++iter)
	{
		if (iter->BuildTurn == m_TurnCounter)
		{
			int Command;
			switch (iter->BuilderType)
			{
			case 0: Command = CMD_DEPLOY; break;
			case 1: Command = CMD_DONE; break;
			case 2: Command = CMD_DROPOFF; break;
			default: continue;
			}
			SetCommand(iter->BuilderHandle, Command, iter->Priority, 0, iter->DropoffPos, 0);
		}
	}

	// VSR: a player that changed team takes their TeamInfo player slot, lives and dead flag with them.
	for (int i = 0; i < MAX_TEAMS; i++)
	{
		if (IsPlayer(teamInfo[i].RealPlayer))
		{
			const int NewTeam = GetTeamNum(teamInfo[i].RealPlayer);
			if ((NewTeam != i) && (NewTeam > 0))
			{
				if (Logging)
					FormatLogMessage("Switching Player TeamInfo from Team: %d to Team: %d", i, NewTeam);
				std::swap(teamInfo[NewTeam].RealPlayer, teamInfo[i].RealPlayer);
				std::swap(teamInfo[NewTeam].PlayerLives, teamInfo[i].PlayerLives);
				std::swap(teamInfo[NewTeam].TeamIsDead, teamInfo[i].TeamIsDead);
			}
		}
	}

	for (int i = 0; i < MAX_TEAMS; i++)
	{
		if (!IsPlayer(teamInfo[i].RealPlayer))
			teamInfo[i].RealPlayer = GetPlayerHandle(i);

		// Keep the team's AIP record in step with the plan the engine is running.
		const char *Plan = GetPlan(i);
		if (Plan[0] && _stricmp(Plan, teamInfo[i].TeamAIPFile) != 0)
			UpdateTeamAIP(Plan, i);

		// VSR: a team with no player pilot keeps its on-foot player at the spawn point.
		if (teamInfo[i].NoPlayerPilot && IsPerson(teamInfo[i].RealPlayer) && !IsNullVector(teamInfo[i].PlayerSpawnPos))
		{
			if (GetDistance2D(teamInfo[i].PlayerSpawnPos, GetPosition(teamInfo[i].RealPlayer)) > 5.0f)
				SetVectorPosition(teamInfo[i].RealPlayer, teamInfo[i].PlayerSpawnPos);
		}

		teamInfo[i].TookControlThisTurn = false;
	}

	BZ1Interface();
	BZ1Lives();

	m_GravityHelper->Execute(*this);
	m_AmbientSoundHelper->Execute(*this);
	m_ObjectHelper->Execute(*this, m_PortalHelper);
	m_VehicleHelper->Execute(*this);
	m_PowerHelper->Execute(*this);
	m_PowerupHelper->Execute(*this);
	m_BuildingHelper->Execute(*this);
	m_ProductionClassHelper->Execute(*this);
	m_UndeployHelper->Execute(*this);
	m_UtilityShipHelper->Execute(*this);
	m_PortalHelper->Execute(*this);
	m_AttacherHelper->Execute(*this);
	m_ScrapHelper->Execute(*this);
	m_DispatchHelper->Execute(*this);
	m_MorphObjectHelper->Execute(*this);
	m_CarrierHelper->Execute(*this);

	m_LastObjectListCount = m_ObjectHelper->GetNumHandles(); // Count the number of items at the end of the tick.
}

// DECOMPILE: bz1helper.cpp:2443-2525  @4fc0f75a  (reference/decompiled/strategy02-ghidra12.2/src/missions/vsrcore/bz1helper.cpp.decomp.c) + dumpbin for the register-passed arguments
// Snipe gate: the sniper shell's TeamFilter (its classlabel ODF, else the ordnance ODF; 7 = everyone when there is no ordnance team or no filter), MP friendly-fire
// protection for allied players / teams, and the satellite hand-back when the victim is a team's parked ship.
PreSnipeReturnCodes BZ1Helper::PreSnipe(const int curWorld, Handle shooterHandle, Handle victimHandle, int ordnanceTeam, const char* pOrdnanceODF)
{
	if (curWorld != 0)
		return PRESNIPE_ONLYBULLETHIT;

	PreSnipeReturnCodes ret = PRESNIPE_KILLPILOT;
	int TeamFilter = 0;
	const int VictimTeam = GetTeamNum(victimHandle);
	if (ordnanceTeam == 0)
		ordnanceTeam = GetTeamNum(shooterHandle);

	char OrdnanceODF[MAX_ODF_LENGTH] = {0};
	char ClassODF[MAX_ODF_LENGTH] = {0};
	strcpy_s(OrdnanceODF, pOrdnanceODF);
	char ClassLabel[MAX_ODF_LENGTH] = {0};
	if (OpenODF2(OrdnanceODF) && GetODFString(OrdnanceODF, "OrdnanceClass", "classlabel", MAX_ODF_LENGTH, ClassLabel))
	{
		CombineStrings(ClassODF, ClassLabel, ".odf", MAX_ODF_LENGTH);
		if (!OpenODF2(ClassODF))
			ClassODF[0] = '\0';
	}
	GetODFInt(OrdnanceODF, ClassODF, "SniperShellClass", "TeamFilter", &TeamFilter, 0);
	if ((ordnanceTeam == 0) || (TeamFilter == 0))
		TeamFilter = 7;

	if ((IsNetworkOn() && !m_IsFriendlyFireOn && (GetTeamRelationship(shooterHandle, victimHandle) == TEAMRELATIONSHIP_ALLIEDTEAM) && (IsPlayer(victimHandle) || (VictimTeam != 0))) ||
		!TeamFilterCheck(TeamFilter, VictimTeam, ordnanceTeam))
	{
		ret = PRESNIPE_ONLYBULLETHIT;
	}
	else
	{
		SetPerceivedTeam(victimHandle, 0);
		// GBD: the victim was a player's parked ship while they were in the satellite — give it back to them.
		if ((victimHandle == teamInfo[VictimTeam].Player) && (GetPlayerHandle(VictimTeam) == teamInfo[VictimTeam].SatellitePlayer))
			SetAsUser(teamInfo[VictimTeam].Player, VictimTeam);
	}
	return ret;
}

// DECOMPILE: bz1helper.cpp:2533-2673  @4fc0f94b  (reference/decompiled/strategy02-ghidra12.2/src/missions/vsrcore/bz1helper.cpp.decomp.c) + dumpbin for the register-passed arguments
// MP damage multiplier (game type 2, m_DamageMultiplier > 1): the extra share of the ordnance's damage is dealt here, with the bounce-bomb / spray-bomb
// detonation rules; then the dispatcher (teams without a player) and the carriers hear about enemy hits.
void BZ1Helper::PreOrdnanceHit(Handle shooterHandle, Handle victimHandle, int ordnanceTeam, const char* pOrdnanceODF)
{
	if (!victimHandle)
		return;

	char OrdnanceODF[MAX_ODF_LENGTH] = {0};
	char ClassODF[MAX_ODF_LENGTH] = {0};
	strcpy_s(OrdnanceODF, pOrdnanceODF);
	char ClassLabel[MAX_ODF_LENGTH] = {0};
	if (OpenODF2(OrdnanceODF) && GetODFString(OrdnanceODF, "OrdnanceClass", "classlabel", MAX_ODF_LENGTH, ClassLabel))
	{
		CombineStrings(ClassODF, ClassLabel, ".odf", MAX_ODF_LENGTH);
		if (!OpenODF2(ClassODF))
			ClassODF[0] = '\0';
	}

	if (IsNetworkOn() && (m_GameType == 2) && (m_DamageMultiplier > 1.0f))
	{
		bool DoExtraDamage = true;
		if (_stricmp(ClassLabel, "bouncebomb") == 0)
		{
			int AllowDetonation = -1;
			GetODFInt(victimHandle, "GameObjectClass", "allowMDMCollisionDetonation", &AllowDetonation, -1);
			if ((AllowDetonation == 0) || ((AllowDetonation == -1) && IsBuilding(victimHandle)))
				DoExtraDamage = false;
		}
		else if (_stricmp(ClassLabel, "spraybomb") == 0)
		{
			bool ExplodeOnHit = false;
			GetODFBool(OrdnanceODF, ClassODF, "SprayBombClass", "ExplodeOnHit", &ExplodeOnHit, false);
			if (!ExplodeOnHit)
			{
				DoExtraDamage = false;
			}
			else
			{
				int HitExplodeTypes = 0;
				GetODFInt(OrdnanceODF, ClassODF, "SprayBombClass", "HitExplodeTypes", &HitExplodeTypes, 0);
				if (HitExplodeTypes)
				{
					int VictimType = IsBuilding(victimHandle) ? 1 : 0;
					if (IsCraftButNotPerson(victimHandle))
						VictimType |= 2;
					if (IsPerson(victimHandle))
						VictimType |= 4;
					if (!VictimType)
						VictimType = 8;
					if (!(HitExplodeTypes & VictimType))
						DoExtraDamage = false;
				}
			}
		}

		if (DoExtraDamage)
		{
			const long DamageDealt = GetOrdnanceDamageDealt(victimHandle, OrdnanceODF, false);
			const long ExtraDamage = long(float(DamageDealt) * m_DamageMultiplier) - DamageDealt;
			if (GetCurWorld() == 0)
				Damage(victimHandle, shooterHandle, ExtraDamage);
		}
	}

	const int VictimTeam = GetTeamNum(victimHandle);
	const int OrdTeam = ordnanceTeam ? ordnanceTeam : GetTeamNum(shooterHandle);
	if (!IsTeamAllied(VictimTeam, OrdTeam))
	{
		if (!GetPlayerHandle(VictimTeam))
			m_DispatchHelper->PreOrdnanceHit(shooterHandle, victimHandle, ordnanceTeam, pOrdnanceODF);
		m_CarrierHelper->PreOrdnanceHit(shooterHandle, victimHandle, ordnanceTeam, pOrdnanceODF);
	}
}

// DECOMPILE: bz1helper.cpp:2677-2705  @4fc0fc31  (reference/decompiled/strategy02-ghidra12.2/src/missions/vsrcore/bz1helper.cpp.decomp.c)
// A pilot taking a craft from another team re-homes it (OriginalTeam) and, when the pilot's team has a player, cancels the craft's orders.
PreGetInReturnCodes BZ1Helper::PreGetIn(const int curWorld, Handle pilotHandle, Handle emptyCraftHandle)
{
	if (curWorld == 0)
	{
		const int PilotTeam = GetTeamNum(pilotHandle);
		if (GetTeamNum(emptyCraftHandle) != PilotTeam)
		{
			const int NumHandles = m_ObjectHelper->GetNumHandles();
			for (int i = 0; i < NumHandles; i++)
			{
				if (m_ObjectHelper->GetHandleInfo(i).ObjectHandle == emptyCraftHandle)
				{
					m_ObjectHelper->RefHandleInfo(i).OriginalTeam = PilotTeam;
					break;
				}
			}
		}
		if (GetPlayerHandle(PilotTeam))
			SetCommand(emptyCraftHandle, CMD_NONE, 0);
	}
	return PREGETIN_ALLOW;
}

// DECOMPILE: bz1helper.cpp:2709-2951  @4fc0fca9  (reference/decompiled/strategy02-ghidra12.2/src/missions/vsrcore/bz1helper.cpp.decomp.c)
// Reload / service powerups are the morph helper's call (it may refuse one that would undo a morph).
PrePickupPowerupReturnCodes BZ1Helper::PrePickupPowerup(const int curWorld, Handle me, Handle powerupHandle)
{
	if (curWorld == 0)
	{
		char PowerupODF[MAX_ODF_LENGTH] = {0};
		if (GetObjInfo(powerupHandle, Get_ODF, PowerupODF))
		{
			char MeODF[MAX_ODF_LENGTH] = {0};
			if (GetObjInfo(me, Get_ODF, MeODF))
			{
				char PowerupClass[MAX_ODF_LENGTH] = {0};
				if (GetObjInfo(powerupHandle, Get_GOClass, PowerupClass))
				{
					const unsigned int ObjClassHash = Hash(PowerupClass);
					if ((ObjClassHash == CLASS_POWERUP_RELOAD) || (ObjClassHash == CLASS_POWERUP_SERVICE))
						return m_MorphObjectHelper->PrePickupPowerup(curWorld, me, powerupHandle, ObjClassHash, MeODF);
				}
			}
		}
	}
	return PREPICKUPPOWERUP_ALLOW;
}

// Setup Functions. Init runs once, from the first Execute: the map .trn, the game options / network ivars, clouds, the asset check.
// DECOMPILE: bz1helper.cpp:1699-1988  @4fc0e560  (reference/decompiled/strategy02-ghidra12.2/src/missions/vsrcore/bz1helper.cpp.decomp.c)
void BZ1Helper::Init(void)
{
	const bool Network = IsNetworkOn();

	char mapTrnFile[2*MAX_ODF_LENGTH] = {0};
	strcpy_s(mapTrnFile, GetMapTRNFilename());
	if(OpenODF2(mapTrnFile))
	{
		GetODFFloat(mapTrnFile, "Size", "Height", &mapInfo.Height, 0.0f);
		GetODFFloat(mapTrnFile, "Size", "MetersPerGrid", &mapInfo.MPG, 0.0f);
		GetODFFloat(mapTrnFile, "Size", "HeightGranularity", &mapInfo.HeightGranularity, 0.0f);
		const bool GotSize = GetODFFloat(mapTrnFile, "Size", "Width", &mapInfo.MapWidth, 0.0f) &&
			GetODFFloat(mapTrnFile, "Size", "Depth", &mapInfo.MapDepth, 0.0f) &&
			GetODFFloat(mapTrnFile, "Size", "MinX", &mapInfo.MinX, 0.0f) &&
			GetODFFloat(mapTrnFile, "Size", "MinZ", &mapInfo.MinZ, 0.0f);
		GetODFFloat(mapTrnFile, "World", "Gravity", &mapInfo.Gravity, 12.5f);
		if (!GotSize)
		{
			FormatConsoleMessage("ERROR! '%s' missing [Size] section! Out of bounds area not calibrated! FIXME!", mapTrnFile);
			mapInfo.MapWidth = 4096.0f;
			mapInfo.MapDepth = 4096.0f;
			mapInfo.MinX = -2048.0f;
			mapInfo.MinZ = -2048.0f;
		}

		// [DLL] map settings.
		GetODFFloat(mapTrnFile, "DLL", "ReinforcementMinRadius", &m_ReinforcementMinRadius, 150.0f);
		GetODFFloat(mapTrnFile, "DLL", "ReinforcementMaxRadius", &m_ReinforcementMaxRadius, 250.0f);
		GetODFFloat(mapTrnFile, "DLL", "ReinforcementCliffTolerance", &m_ReinforcementMaxCliff, 100.0f);
		GetODFFloat(mapTrnFile, "DLL", "MinScrapHeight", &mapInfo.MinScrapHeight, -1000000.0f);
		GetODFFloat(mapTrnFile, "DLL", "MaxScrapHeight", &mapInfo.MaxScrapHeight, 1000000.0f);
		GetODFBool(mapTrnFile, "DLL", "RestrictAllScrap", &mapInfo.RestrictAllScrap, false);
		GetODFBool(mapTrnFile, "DLL", "RespawnAtLowAltitude", &mapInfo.RespawnAtLowAltitude, false);
		GetODFFloat(mapTrnFile, "DLL", "SpawnMinRadius", &mapInfo.SpawnMinRadius, 20.0f);
		GetODFFloat(mapTrnFile, "DLL", "SpawnMaxRadius", &mapInfo.SpawnMaxRadius, 50.0f);

		m_GravityHelper->LoadGravityInfo(mapTrnFile);
		m_AmbientSoundHelper->LoadAmbientSoundInfo(mapTrnFile);

		// The playable area: the bounding box of every edge_path point, else half the map size each way.
		size_t bufSize = 0;
		GetPathPoints("edge_path", bufSize, NULL);
		float *pData = static_cast<float *>(_alloca(sizeof(float) * 2 * bufSize));
		float EdgeMinX = 0.0f, EdgeMinZ = 0.0f, EdgeMaxX = 0.0f, EdgeMaxZ = 0.0f;
		if(GetPathPoints("edge_path", bufSize, pData) && (bufSize > 1))
		{
			EdgeMinX = FLT_MAX;
			EdgeMinZ = FLT_MAX;
			EdgeMaxX = -FLT_MAX;
			EdgeMaxZ = -FLT_MAX;
			for(size_t i = 0; i < bufSize; ++i)
			{
				const float x = pData[2*i+0];
				const float z = pData[2*i+1];
				if (x < EdgeMinX) EdgeMinX = x;
				if (z < EdgeMinZ) EdgeMinZ = z;
				if (x > EdgeMaxX) EdgeMaxX = x;
				if (z > EdgeMaxZ) EdgeMaxZ = z;
			}
		}
		if((EdgeMinX + EdgeMinZ + EdgeMaxX + EdgeMaxZ) != 0.0f)
		{
			mapInfo.MaxWidth = max(EdgeMinX, EdgeMaxX);
			mapInfo.MaxDepth = max(EdgeMinZ, EdgeMaxZ);
			mapInfo.MinWidth = min(EdgeMinX, EdgeMaxX);
			mapInfo.MinDepth = min(EdgeMinZ, EdgeMaxZ);
		}
		else
		{
			mapInfo.MaxWidth = (mapInfo.MapWidth * 0.5f);
			mapInfo.MaxDepth = (mapInfo.MapDepth * 0.5f);
			mapInfo.MinWidth = -mapInfo.MaxWidth;
			mapInfo.MinDepth = -mapInfo.MaxDepth;
		}
	}

	if (!Network)
	{
		m_CPUUseDayWreckers = IFace_GetInteger("options.instant.bool2") != 0;
		const int UseSkillLevels = IFace_GetInteger("options.instant.bool4");
		m_DamageMultiplier = 1.0f;
		m_ScrapMultiplier = 1;
		m_UseSkillLevels = UseSkillLevels != 0;
	}
	else
	{
		m_IsFriendlyFireOn = GetVarItemInt("network.session.ivar32") != 0;
		m_MaxLives = GetVarItemInt("network.session.ivar60");
		m_ScrapMultiplier = GetVarItemInt("network.session.ivar81");
		m_GameType = GetVarItemInt("network.session.ivar5");
		const int DamagePercent = GetVarItemInt("network.session.ivar26");
		m_DamageMultiplier = float(clamp(DamagePercent, 10, 100)) / 10.0f;
		m_CPUUseDayWreckers = GetVarItemInt("network.session.ivar89") != 0;
		m_EnableSiteCamMP = GetVarItemInt("network.session.ivar90") != 0;
		m_UseSkillLevels = GetVarItemInt("network.session.ivar91") != 0;
		const float Gravity = float(GetVarItemInt("network.session.ivar31")) * 0.5f;
		if (Gravity > 0.0f)
		{
			mapInfo.Gravity = Gravity;
			SetGravity(Gravity);
		}
	}

	OffMapPos.x = -4000.0f;
	OffMapPos.z = -4000.0f;
	OffMapPos.y = TerrainFindFloor(-4000.0f, -4000.0f);

	SetupClouds(mapTrnFile);

	char MapName[2*MAX_ODF_LENGTH] = {0};
	strcpy_s(MapName, Network ? GetVarItemStr("network.session.svar0") : mapTrnFile);
	if (char *dot = strrchr(MapName, '.'))
		*dot = '\0';
	if (Logging)
		FormatLogMessage("Game Started on map: '%s' by %s. Version: %d\n", MapName, GetPlayerName(GetPlayerHandle()), m_GameVersion);

	// GBD: the VSR asset check — every file the mod needs must be present or the game is aborted.
	if (!DoesFileExist("MPIVSRCheck.odf") || !DoesFileExist("STvsrcheck.odf") || !DoesFileExist("aip_VSR.autoreg") || !DoesFileExist("vsrbasesetup.cfg") ||
		!DoesFileExist("vsra.txt") || !DoesFileExist("evlegs_vsr.odf") || !DoesFileExist("BZCundep1.odf") || !DoesFileExist("BZCundep2.odf") ||
		!DoesFileExist("ivcamr_vsr.odf") || !DoesFileExist("hbport_vsr.odf") || !DoesFileExist("evmine_vsr.odf") || !DoesFileExist("BZCNullCube.msh") ||
		!DoesFileExist("apserv_vsr.odf") || !DoesFileExist("ivrbomb_vsr.inf") || !DoesFileExist("vsr_bh_e_new_e6_0.aip") || !DoesFileExist("apvsrbldg.odf") ||
		!DoesFileExist("iweapon_12svsr.odf") || !DoesFileExist("fweapon_12xvsr.odf") || !DoesFileExist("aplmg.inf") || !DoesFileExist("racename_e.txt") ||
		!DoesFileExist("evscout00_s.dds") || !DoesFileExist("evscav00_s.dds") || !DoesFileExist("evcons00_s.dds") || !DoesFileExist("ivscout12smartvsr.odf"))
	{
		AddToMessagesBox2("-- Aborting!", RED);
		if (IsNetworkOn())
		{
			NoteGameoverByNoBases();
			DoGameover(10.0f);
		}
		else
		{
			FailMission(GetTime() + 10.0f, "instantl.txt");
		}
	}

	m_DidInit = true;
}

// DECOMPILE: bz1helper.cpp:1992-2025  @4fc0eec7  (reference/decompiled/strategy02-ghidra12.2/src/missions/vsrcore/bz1helper.cpp.decomp.c)
// Onload setup: the off-map position gets its floor height and every off-map helper object is parked there.
void BZ1Helper::Setup(void)
{
	m_DidSetup = true;

	OffMapPos.y = TerrainFindFloor(OffMapPos.x, OffMapPos.z);

	for (int i = 0; i < MAX_TEAMS; i++)
	{
		TeamInfo &team = teamInfo[i];
		for (int x = 0; x < MAX_BASE_SLOTS; x++)
			if (IsAround(team.BaseSlotScrap[x]))
				SetVectorPosition(team.BaseSlotScrap[x], OffMapPos);
		for (int x = 0; x < 3; x++)
			if (IsAround(team.LimiterObject[x]))
				SetVectorPosition(team.LimiterObject[x], OffMapPos);
		if (IsAround(team.ImaPilot))
			SetVectorPosition(team.ImaPilot, OffMapPos);
		if (IsAround(team.SatelliteOn))
			SetVectorPosition(team.SatelliteOn, OffMapPos);
		if (IsAround(team.SatelliteOff))
			SetVectorPosition(team.SatelliteOff, OffMapPos);
		if (IsAround(team.SatelliteLock))
			SetVectorPosition(team.SatelliteLock, OffMapPos);
	}
}

// DECOMPILE: bz1helper.cpp:2969-2971  @4fc0fdaa  (reference/decompiled/strategy02-ghidra12.2/src/missions/vsrcore/bz1helper.cpp.decomp.c)
void BZ1Helper::DeadObject(Handle DeadObjectHandle)
{
	m_PortalHelper->DeadObject(DeadObjectHandle); // inlined in the shipped binary: a dead allied portal gets its name back.
}

// DECOMPILE: ICF-folded with PostTeleport @4fc0fda5 (the vtable's slots 23 and 24 share the body): both return their DEFAULT.
PreTeleportReturnCodes BZ1Helper::PreTeleport(const Handle /*portalHandle*/, const Handle /*shipHandle*/)
{
	return PreTeleport_DEFAULT;
}

// DECOMPILE: bz1helper.cpp:2955-2965  @4fc0fda5  (reference/decompiled/strategy02-ghidra12.2/src/missions/vsrcore/bz1helper.cpp.decomp.c)
PostTeleportReturnCodes BZ1Helper::PostTeleport(const Handle /*portalHandle*/, const Handle /*shipHandle*/)
{
	return PostTeleport_DEFAULT;
}

// Note: BZ1 made clouds around the player in a 3x3 TileSize grid, with CloudCount # of clouds placed randomly in each Tile. It then moved them around when 
// the player got into the next tile area. VSR places them all at Init: [Clouds] Type / Count / TileSize, Name%d (or Name%d_%d variants) / Height%d / Team%d.
// DECOMPILE: bz1helper.cpp:3392-3586  @4fc105c7  (reference/decompiled/strategy02-ghidra12.2/src/missions/vsrcore/bz1helper.cpp.decomp.c); the log-message
// operands of the "too many clouds" correction are reconstructed from the 2015 totals formula.
void BZ1Helper::SetupClouds(const char *mapTrnFile)
{
	float CloudMaxX = 0, CloudMaxZ = 0, CloudMinX = 0, CloudMinZ = 0;
	int Type = 0, CloudTypes = 0, CloudCount = 0, TileSize = 0;
	int CloudRandomTotal[MAX_CLOUD_TYPES] = {0};
	int CloudTeam[MAX_CLOUD_TYPES] = {0};
	float CloudHeight[MAX_CLOUD_TYPES] = {0};
	char CloudName[MAX_CLOUD_TYPES][MAX_CLOUD_TYPES][MAX_ODF_LENGTH] = {0};

	GetODFInt(mapTrnFile, "Clouds", "Type", &Type, 0); // 0 = absolute heights, else above the terrain.
	GetODFInt(mapTrnFile, "Clouds", "Count", &CloudCount, 0); // Grab the number of clouds per tile, defaults to 0 (none). 
	CloudCount = clamp(CloudCount, 0, MAX_CLOUD_OBJECTS);
	GetODFInt(mapTrnFile, "Clouds", "TileSize", &TileSize, 0); // How big each tile is.

	char DesiredValue[MAX_ODF_LENGTH] = {0};
	for (int i = 0; i < MAX_CLOUD_TYPES; i++)
	{
		// Find out how many cloud variations there are for this entry; a plain Name%d lands in the first slot.
		bool GotName = false;
		for (int x = 0; x < MAX_CLOUD_TYPES; x++)
		{
			sprintf_s(DesiredValue, "Name%d_%d", i+1, x+1);
			if (GetODFString(mapTrnFile, "Clouds", DesiredValue, MAX_ODF_LENGTH, CloudName[i][x]))
			{
				++CloudRandomTotal[i];
			}
			else
			{
				sprintf_s(DesiredValue, "Name%d", i+1);
				if (!GetODFString(mapTrnFile, "Clouds", DesiredValue, MAX_ODF_LENGTH, CloudName[i][0]))
					break;
			}
			GotName = true;
		}
		if (!GotName)
			break; // Stop reading if there's a gap.
		++CloudTypes;

		// Get the Height.
		sprintf_s(DesiredValue, "Height%d", i+1);
		GetODFFloat(mapTrnFile, "Clouds", DesiredValue, &CloudHeight[i], 100.0f);

		// Get the Team.
		sprintf_s(DesiredValue, "Team%d", i+1);
		GetODFInt(mapTrnFile, "Clouds", DesiredValue, &CloudTeam[i], 0);
	}

	// GBD: cap the total at 1024 objects by trimming the per-tile count.
	const int TileCountZ = int(floorf(mapInfo.MaxDepth / float(TileSize)) - floorf(mapInfo.MinDepth / float(TileSize)) + 1.0f);
	const int TileCountX = int(floorf(mapInfo.MaxWidth / float(TileSize)) - floorf(mapInfo.MinWidth / float(TileSize)) + 1.0f);
	const int TotalClouds = TileCountX * TileCountZ * CloudTypes * CloudCount;
	if (TotalClouds > 1024)
	{
		const int Difference = TotalClouds - 1024;
		const int DiffZ = Difference / TileCountZ;
		const int DiffX = DiffZ / TileCountX;
		const int DiffType = DiffX / CloudTypes;
		if (Logging)
			FormatLogMessage("Total Clouds: %d, TileCountX: %d, TileCountZ: %d, Difference: %d, DiffX: %d DiffZ: %d, DiffType: %d", TotalClouds, TileCountX, TileCountZ, Difference, DiffX, DiffZ, DiffType);
		const int OldCount = CloudCount;
		CloudCount -= DiffType;
		FormatLogMessage("ERROR: Too many Clouds: (%d > %d), Count Per Tile: %d. Correcting to: %d, %d Per Tile.", TotalClouds, 1024, OldCount, TileCountX * TileCountZ * CloudTypes * CloudCount, CloudCount);
	}

	const float EdgeMinX = mapInfo.MinWidth;
	const float EdgeMaxX = mapInfo.MaxWidth;
	const float EdgeMinZ = mapInfo.MinDepth;
	const float EdgeMaxZ = mapInfo.MaxDepth;

	const float CloudTilesX = TileSize * floorf((EdgeMaxX - EdgeMinX) / TileSize);
	const float CloudTilesZ = TileSize * floorf((EdgeMaxZ - EdgeMinZ) / TileSize);
	const float CloudCenterX = 0.5f * (EdgeMaxX + EdgeMinX);
	const float CloudCenterZ = 0.5f * (EdgeMaxZ + EdgeMinZ);
	CloudMinX = CloudCenterX - CloudTilesX * 0.5f;
	CloudMaxX = CloudCenterX + CloudTilesX * 0.5f;
	CloudMinZ = CloudCenterZ - CloudTilesZ * 0.5f;
	CloudMaxZ = CloudCenterZ + CloudTilesZ * 0.5f;

	// Initialize a NESW directional matrix array. :)
	Matrix FacingMatrix[4] = { Matrix(Vector(1, 0, 0),Vector(0, 1, 0), Vector(0, 0, 1), Vector(0, 0, 0)), 
		Matrix(Vector(0, 0, 1), Vector(0, 1, 0), Vector(-1, 0, 0), Vector(0, 0, 0)), 
		Matrix(Vector(-1, 0, 0), Vector(0, 1, 0), Vector(0, 0, -1), Vector(0, 0, 0)), 
		Matrix(Vector(0, 0, -1), Vector(0, 1, 0), Vector(1, 0, 0), Vector(0, 0, 0)) };

	// For each Type, place clouds for each Count.
	int PlacedClouds = 0;
	for(int i = 0; i < CloudTypes; ++i)
	{
		for(float tileX = CloudMinX; tileX <= CloudMaxX; tileX += TileSize)
		{
			for(float tileZ = CloudMinZ; tileZ <= CloudMaxZ; tileZ += TileSize)
			{
				for(int Count = 0; Count < CloudCount; Count++)
				{
					const int Random = GetRandomInt(0, CloudRandomTotal[i] > 0 ? CloudRandomTotal[i]-1 : 0);
					if (Logging)
						FormatLogMessage("Placing Cloud: Random is: %d Cloud ODF is: '%s'", Random, CloudName[i][Random]);

					Matrix Position = FacingMatrix[GetRandomInt(0, 3)];
					Position.posit.x = tileX + GetRandomFloat(float(TileSize)) - (TileSize * 0.5f);
					Position.posit.z = tileZ + GetRandomFloat(float(TileSize)) - (TileSize * 0.5f);
					if(Type)
						Position.posit.y = TerrainFindFloor(Position.posit.x, Position.posit.z) + CloudHeight[i];
					else
						Position.posit.y = CloudHeight[i];

					StopAddObject = true; // Clouds don't enter the object lists.
					BuildObject(CloudName[i][Random], CloudTeam[i], Position);
					StopAddObject = false;
					++PlacedClouds;
				}
			}
		}
	}

	if(Logging)
	{
		FormatLogMessage("Map Width Is: %f", mapInfo.MapWidth);
		FormatLogMessage("Map Depth Is: %f", mapInfo.MapDepth);
		FormatLogMessage("Clouds Specified Are: %d", CloudTypes);
		FormatLogMessage("Cloud Count Per Type is: %d", CloudCount);
		FormatLogMessage("Cloud Type Count is: %d", CloudTypes);
		FormatLogMessage("Total Clouds are: %d", PlacedClouds);
	}
}

// Adds an object to the DeleteObject class list to be removed the next Execute() call.
// DECOMPILE: bz1helper.cpp:4019-4035  @4fc111c4  (reference/decompiled/strategy02-ghidra12.2/src/missions/vsrcore/bz1helper.cpp.decomp.c)
void BZ1Helper::DeleteAfterDelay(const Handle h, const float Delay)
{
	if(!IsAround(h))
		return;

	for (std::vector<DeleteAfterDelayClass>::iterator iter = DeleteAfterDelayList.begin(); iter != DeleteAfterDelayList.end(); ++iter)
	{
		if(iter->DeleteAfterDelayHandle == h)
			return;
	}

	DeleteAfterDelayList.resize(DeleteAfterDelayList.size()+1);
	DeleteAfterDelayClass &sao = DeleteAfterDelayList[DeleteAfterDelayList.size()-1]; // No temporary being created, *much* faster
	memset(&sao, 0, sizeof(DeleteAfterDelayClass)); // Zero things out at start.

	sao.DeleteAfterDelayHandle = h;
	sao.TurnsRemaining = SecondsToTurns(Delay);
}

// Public Accessories. These allow other DLL's to do stuff. 
// DECOMPILE: bz1helper.cpp:3698-3712  @4fc10f10  (reference/decompiled/strategy02-ghidra12.2/src/missions/vsrcore/bz1helper.cpp.decomp.c)
bool BZ1Helper::SetAIPFile(const char* Value, const int Team)
{
	if (Team < 0 || Team >= MAX_TEAMS) // GBD: one unsigned compare; it also rejects the -1 default, so the fallback below never fires.
		return false;

	const int NewTeam = (Team == -1) ? 2 : Team;
	SetPlan(Value, NewTeam);

	return UpdateTeamAIP(Value, NewTeam);
}

// DECOMPILE: bz1helper.cpp:3714-3749  @4fc10f49  (reference/decompiled/strategy02-ghidra12.2/src/missions/vsrcore/bz1helper.cpp.decomp.c)
bool BZ1Helper::UpdateTeamAIP(const char* AIPFile, const int Team)
{
	if(OpenODF2(AIPFile))
	{
		strcpy_s(teamInfo[Team].TeamAIPFile, AIPFile);
		{
			GetODFInt(AIPFile, "Cheat", "pilotAmount", &teamInfo[Team].m_CPUPilotCheatAmount, 0); // Grab the value.
			GetODFFloat(AIPFile, "Cheat", "pilotDelay", &teamInfo[Team].m_CPUPilotCheatDelay, 15.0f); // Grab the value.
			GetODFInt(AIPFile, "Start", "Difficulty", &teamInfo[Team].m_CPUAIDifficulty, 0); // Grab the value.
			teamInfo[Team].m_CPUAIDifficulty = clamp(teamInfo[Team].m_CPUAIDifficulty, 0, 4);
			GetODFBool(AIPFile, "Start", "UnitsService", &teamInfo[Team].m_CPUUnitsCanService, false); // Grab the value.
			GetODFBool(AIPFile, "IdleDispatcher", "DoDLLDispatch", &teamInfo[Team].m_CPUDoDispatch, true); // Grab the value.
			GetODFInt(AIPFile, "IdleDispatcher", "MaxPatrolUnits", &teamInfo[Team].m_CPUMaxPatrolUnits, 0); // Grab the value.
			GetODFInt(AIPFile, "IdleDispatcher", "MaxHuntUnits", &teamInfo[Team].m_CPUMaxHuntUnits, 0); // Grab the value.
			GetODFInt(AIPFile, "IdleDispatcher", "MaxEscortUnits", &teamInfo[Team].m_CPUMaxEscortUnits, 0); // Grab the value.

			// VSR: the CPU's building-repair and build-pod timers.
			GetODFFloat(AIPFile, "Start", "BuildingRepairChance", &teamInfo[Team].m_CPUBuildingRepairChance, 0.8f);
			GetODFFloat(AIPFile, "Start", "BuildingRepairInterval", &teamInfo[Team].m_CPUBuildingRepairInterval, 30.0f);
			GetODFFloat(AIPFile, "Start", "BuildingRepairHealthRatio", &teamInfo[Team].m_CPUBuildingRepairHealthRatio, 0.5f);
			GetODFFloat(AIPFile, "Start", "BuildPodMinDelay", &teamInfo[Team].m_CPUBuildPodMinDelay, 5.0f);
			GetODFFloat(AIPFile, "Start", "BuildPodMaxDelay", &teamInfo[Team].m_CPUBuildPodMaxDelay, 60.0f);

			if(m_CPUUseDayWreckers)
			{
				GetODFFloat(AIPFile, "Start", "DayWreckerChance", &teamInfo[Team].m_CPUDayWreckerChance, 0.0f); // Grab the value.
				GetODFFloat(AIPFile, "Start", "DayWreckerInterval", &teamInfo[Team].m_CPUDayWreckerInterval, 30.0f);
				if (teamInfo[Team].m_CPUDayWreckerInterval <= 0.0f)
					teamInfo[Team].m_CPUDayWreckerInterval = 1.0f;
			}
		}
		return true;
	}
	return false;
}

// Adds a unit to BZC's custom AI Dispatch code, with options.
// DECOMPILE: bz1helper.cpp:3752-3754  @4fc11199  (reference/decompiled/strategy02-ghidra12.2/src/missions/vsrcore/bz1helper.cpp.decomp.c)
bool BZ1Helper::AddToDispatch(const Handle h, const float IdleTime, const bool SkipAIPCheck, const int CloakPriority, const bool CanFlee, const bool CloakNow, const bool Hunt, const bool CanGetService)
{
	return m_DispatchHelper->AddToDispatch(h, IdleTime, SkipAIPCheck, CloakPriority, CanFlee, CloakNow, Hunt, CanGetService);
}

// Cloak functions.
// DECOMPILE: not emitted as a symbol in the binary (forwarder, inlined into its callers)
void BZ1Helper::Cloak(const Handle h, const int Priority) { m_DispatchHelper->Cloak(h, Priority); }

void BZ1Helper::Decloak(const Handle h, const int Priority) { m_DispatchHelper->Decloak(h, Priority); }

bool BZ1Helper::IsCloaked(const Handle h) { return m_DispatchHelper->IsCloaked(h); }

// DECOMPILE: not emitted as a symbol in the binary (no shipped caller; the 2015 body is kept)
Handle BZ1Helper::SetCloakAllowed(const Handle h, const bool IsAllowed, const bool PlaySound)
{
	bool CanCloak = false;
	if(!GetODFBool(h, "MorphTankClass", "HiddenWhenMorphed", &CanCloak, false))
		return h; // Not a cloak tank, return original Handle.

	if(((IsAllowed) && (CanCloak)) || ((!IsAllowed) && (!CanCloak)))
		return h; // Setting already matches, abort early and notify that the function didn't do anything.

	char ODFName[MAX_ODF_LENGTH] = {0};
	GetODFString(h, "GameObjectClass", "CloakSwitchODF", MAX_ODF_LENGTH, ODFName);

	char CloakFailSound[MAX_ODF_LENGTH] = {0};
	GetODFString(h, "GameObjectClass", "CloakFailSound", MAX_ODF_LENGTH, CloakFailSound, "cloakfail.wav");

	// If this isn't set, try the alternate method of using file name schemes.
	if(!DoesODFExist(ODFName))
	{
		// If this ODF does not exist, it might have been built by a factory, check for that.
		GetODFName(h, ODFName);

		// Remove the "World Letter", if it exists.
		char TestODF[MAX_ODF_LENGTH] = {0};
		int length = strlen(ODFName)-1;
		strncpy_s(TestODF, ODFName, length);

		if((TestODF[0]) && (DoesODFExist(TestODF)))
			strncpy_s(ODFName, TestODF, length); // If this had a world letter, copy in the new ODFName, otherwise leave it as is.

		strcat_s(ODFName, "NC");
	}

	if((h == GetPlayerHandle()) && (ODFName[0]) && (DoesODFExist(ODFName)) && (PlaySound) && (!IsAllowed) && (IsCloaked(h)) && (DoesFileExist(CloakFailSound)))
		AudioMessage(CloakFailSound);
	
	if((ODFName[0]) && (DoesODFExist(ODFName)))
		return ReplaceObject(h, ODFName);
	else
		return h;
}

// VSR: the cloak energy gauge lives on the VehicleHelper entry (reconstructed accessors; no shipped caller survives, the Lua table has no binding for them).
// DECOMPILE: not emitted as a symbol in the binary
int BZ1Helper::GetCurCloakEnergy(const Handle h)
{
	for (int i = 0; i < m_VehicleHelper->GetNumVehicles(); i++)
		if (m_VehicleHelper->GetVehicleInfo(i).ObjectHandle == h)
			return m_VehicleHelper->GetVehicleInfo(i).CloakCurEnergy;
	return 0;
}

void BZ1Helper::SetCurCloakEnergy(const Handle h, const int Energy)
{
	for (int i = 0; i < m_VehicleHelper->GetNumVehicles(); i++)
		if (m_VehicleHelper->GetVehicleInfo(i).ObjectHandle == h)
			m_VehicleHelper->RefVehicleInfo(i).CloakCurEnergy = Energy;
}

int BZ1Helper::GetMaxCloakEnergy(const Handle h)
{
	for (int i = 0; i < m_VehicleHelper->GetNumVehicles(); i++)
		if (m_VehicleHelper->GetVehicleInfo(i).ObjectHandle == h)
			return m_VehicleHelper->GetVehicleInfo(i).CloakMaxEnergy;
	return 0;
}

void BZ1Helper::SetMaxCloakEnergy(const Handle h, const int Energy)
{
	for (int i = 0; i < m_VehicleHelper->GetNumVehicles(); i++)
		if (m_VehicleHelper->GetVehicleInfo(i).ObjectHandle == h)
			m_VehicleHelper->RefVehicleInfo(i).CloakMaxEnergy = Energy;
}

// Other Dispatch related functions.
void BZ1Helper::DLLHunt(const Handle h, const int Priority) { m_DispatchHelper->DLLHunt(h, Priority); }

void BZ1Helper::SetUseService(const Handle h, const bool Service) { m_DispatchHelper->SetUseService(h, Service); }

// Gets an Escort Target.
Handle BZ1Helper::GetEscortTarget(const int Team, const int TeamFilter) { return m_UtilityShipHelper->GetEscortTarget(Team, TeamFilter); }

// Portal functions. 
// Sets Channel Get/Set.
void BZ1Helper::SetPortalChannel(const Handle h, const int Channel) { m_PortalHelper->SetPortalChannel(h, Channel); }

int BZ1Helper::GetPortalChannel(const Handle h) { return m_PortalHelper->GetPortalChannel(h); }

// Portal Effects. VSR: PortalHelper's versions grew a ReplaceEffect flag; the Lua bindings (LuaBindings::SetPortalEffectStart / On) pass true through here, End's is dead.
void BZ1Helper::SetPortalEffectStart(const Handle h, const int FxNumber, const int Type) { m_PortalHelper->SetPortalEffectStart(h, FxNumber, Type, true); }

void BZ1Helper::SetPortalEffectOn(const Handle h, const int FxNumber, const int Type) { m_PortalHelper->SetPortalEffectOn(h, FxNumber, Type, true); }

void BZ1Helper::SetPortalEffectEnd(const Handle h, const int FxNumber, const int Type) { m_PortalHelper->SetPortalEffectEnd(h, FxNumber, Type, false); }

bool BZ1Helper::IsPortalEffectActive(const Handle h) { return m_PortalHelper->IsPortalEffectActive(h); }

// VSR: portal destination list management.
void BZ1Helper::SwapPortalIndex(const Handle h1, const Handle h2) { m_PortalHelper->SwapPortalIndex(h1, h2); }

void BZ1Helper::ShufflePortalUp(const Handle h) { m_PortalHelper->ShufflePortalUp(h); }

void BZ1Helper::ShufflePortalDown(const Handle h) { m_PortalHelper->ShufflePortalDown(h); }

Handle BZ1Helper::GetPortalDest(const Handle h) { return m_PortalHelper->GetPortalDest(h); }

bool BZ1Helper::SetPortalDest(const Handle h, const Handle Dest) { return m_PortalHelper->SetPortalDest(h, Dest); }

void BZ1Helper::ClearPortalDest(const Handle h, const bool ScriptOverride) { m_PortalHelper->ClearPortalDest(h, ScriptOverride); }

// Is a building Powered? 
bool BZ1Helper::IsBuildingPowered(const Handle h) { return m_BuildingHelper->IsBuildingPowered(h); }

// Set a building as Powered/Unpowered/Autodetermine. 0 = Unpowered, 1 = Powered, -1 = Autodetermine.
void BZ1Helper::SetBuildingPowered(const Handle h, const int Powered) { return m_BuildingHelper->SetBuildingPowered(h, Powered); }

// Replaces an object with another object, retaining as much information from the original as desired. 
// VSR additions over 2015: the tug carrying it, its target, its taps (unless DestroyTapsWithParent), omega, can-snipe, eject ratio, the scrap hold as a ratio,
// health as a ratio of the new max, command priority / where, and the -2 / 10+ group sentinels (leave the group alone).
// DECOMPILE: bz1helper.cpp:5071-5248  @4fc11a43  (reference/decompiled/strategy02-ghidra12.2/src/missions/vsrcore/bz1helper.cpp.decomp.c) + dumpbin for the register-passed arguments
Handle BZ1Helper::ReplaceObject(const Handle H, const char *ODF, const int Team, const float HeightOffset, const int Empty, const bool RestoreWeapons, const int Group, const int CanSnipe, const bool KeepCommand, const int NewCommand, const int Priority, const Handle NewWho, const Vector NewWhere)
{
	if(!IsAround(H))
		return 0;

	char NewODF[MAX_ODF_LENGTH] = {0};
	if(!ODF)
	{
		GetODFName(H, NewODF);
	}
	else
	{
		CombineStrings(NewODF, "", ODF, MAX_ODF_LENGTH);
		GetWorldVariantODF(NewODF);
	}

	const Handle Tug = GetTug(H);
	const Handle Target = GetTarget(H);
	const Handle Who = GetCurrentWho(H);
	Handle Taps[8] = {0};
	for (int i = 0; i < 8; i++)
		Taps[i] = GetTap(H, i);

	char Label[MAX_NAME_LENGTH] = {0};
	CombineStrings(Label, "", GetLabel(H), MAX_NAME_LENGTH);
	char ObjectiveName[MAX_NAME_LENGTH] = {0};
	CombineStrings(ObjectiveName, "", GetObjectiveName(H), MAX_NAME_LENGTH);
	char PilotODF[MAX_ODF_LENGTH] = {0};
	if (const char *pilotOdf = GetPilotConfig(H))
		CombineStrings(PilotODF, "", pilotOdf, MAX_ODF_LENGTH);

	const int NewTeam = Team >= 0 ? Team : GetTeamNum(H);
	const int PercievedTeam = GetPerceivedTeam(H);
	const float HealthP = GetHealth(H);
	const float AmmoP = GetAmmo(H);

	char Weapon[MAX_HARDPOINTS][MAX_ODF_LENGTH] = {0};
	float WeaponLocalAmmo[MAX_HARDPOINTS] = {0};
	for(int i = 0; i < MAX_HARDPOINTS; i++)
	{
		WeaponLocalAmmo[i] = GetCurLocalAmmo(H, i);
		GetObjInfo(H, ObjectInfoType(Get_Weapon0Config+i), Weapon[i]);
	}
	const long WeaponMask = GetWeaponMask(H);

	const int MaxScrap = GetScavengerMaxScrap(H);
	const float ScrapRatio = (MaxScrap < 1) ? -1.0f : float(GetScavengerCurScrap(H) / MaxScrap); // sic: integer division before the cast.

	Matrix BuildLoc = GetMatrixPosition(H);
	const Vector Velocity = GetVelocity(H);
	const Vector Omega = GetOmega(H);
	const bool Deployed = IsDeployed(H);
	const float LifeSpan = GetRemainingLifespan(H);
	const int Independence = GetIndependence(H);
	const int Skill = GetSkill(H);
	const int NewGroup = (Group < 0) ? GetGroup(H) : Group;
	const bool NewCanSnipe = (CanSnipe < 0) ? GetCanSnipe(H) : (CanSnipe != 0);
	const AiCommand Command = GetCurrentCommand(H);
	Vector Where(0.0f, 0.0f, 0.0f);
	if ((Command == CMD_GO) || (Command == CMD_DEPLOY) || (Command == CMD_GET_IN) || (Command == CMD_LAY_MINES))
		Where = GetCurrentCommandWhere(H);
	const bool WasPlayer = IsPlayer(H);
	const float EjectRatio = GetEjectRatio(H);
	const int ScrapValue = GetScrapValue(GetODFName(H)); // read, not used further (as shipped).
	(void)ScrapValue;
	const int TempPilotCost = GetPilotCost(NewODF);
	const int TapCount = GetTapCount(H);
	const bool IsEmptyCraft = (Empty < 0) ? IsEmpty(H) : (Empty != 0);

	if(HeightOffset != 0)
		BuildLoc.posit.y += HeightOffset;

	if(!DoesODFExist(NewODF))
	{
		FormatLogMessage("ERROR: ReplaceODF '%s' doesn't exist! Fix DLLs!", NewODF);
		return H; // Report back the same handle, didn't work.
	}

	if((!IsEmptyCraft) && (m_TurnCounter > 1))
		AddPilot(NewTeam, TempPilotCost);

	bool DestroyTapsWithParent = true;
	if (!GetODFBool(H, "PoweredBuildingClass", "DestroyTapsWithParent", &DestroyTapsWithParent, true))
		GetODFBool(H, "TurretCraftClass", "DestroyTapsWithParent", &DestroyTapsWithParent, true);

	RemoveObject(H);
	Handle h = BuildObject(NewODF, NewTeam, BuildLoc);

	if (Tug)
		Pickup(Tug, h, 1);
	if (Target)
		SetTarget(h, Target);
	if (!DestroyTapsWithParent)
	{
		for (int i = 0; i < TapCount; i++)
			SetTap(h, i, Taps[i]);
	}

	SetLabel(h, Label);
	if (PilotODF[0] && DoesODFExist(PilotODF))
		SetPilotClass(h, PilotODF);
	SetObjectiveName(h, ObjectiveName);
	SetPerceivedTeam(h, PercievedTeam);

	const long MaxHealth = GetMaxHealth(h);
	if (MaxHealth != INVALID_VALUE)
		SetCurHealth(h, long(float(MaxHealth) * clamp(HealthP, 0.0f, 1.0f)));
	SetAmmo(h, AmmoP);

	if(RestoreWeapons)
		ReplaceWeapons(h, Weapon, WeaponLocalAmmo, NewODF);
	SetWeaponMask(h, WeaponMask);

	const int NewMaxScrap = GetScavengerMaxScrap(h);
	if (NewMaxScrap > 0)
		SetScavengerCurScrap(h, long(float(NewMaxScrap) * clamp(ScrapRatio, 0.0f, 1.0f)));

	SetVelocity(h, Velocity);
	SetOmega(h, Omega);
	if(Deployed)
		Deploy(h);
	if (LifeSpan >= 0.0f)
		SetLifespan(h, LifeSpan);
	if (Independence > -1)
		SetIndependence(h, Independence);
	SetSkill(h, Skill);

	// Group: -1 = best group, <= -2 or >= 10 = leave it, 0..9 = that group.
	if (Group == -1)
		SetBestGroup(h);
	else if (Group >= 0 && Group < 10)
		SetGroup(h, NewGroup);

	SetCanSnipe(h, NewCanSnipe);
	SetEjectRatio(h, EjectRatio);

	if(WasPlayer)
	{
		SetAsUser(h, NewTeam);
	}
	else if (IsEmptyCraft)
	{
		RemovePilotAI(h);
	}
	else
	{
		if(NewCommand >= 0)
			SetCommand(h, NewCommand, Priority, NewWho, NewWhere, 0);
		else if(KeepCommand)
			SetCommand(h, Command, Priority, Who, Where, 0);
	}

	return h;
}

// Gets a random object, with optional type filter masks, teamfilters, team, includetiemsthisturn, and ignoreinvincible options.
// DECOMPILE: bz1helper.cpp:4039-4102  @4fc11237  (reference/decompiled/strategy02-ghidra12.2/src/missions/vsrcore/bz1helper.cpp.decomp.c) + dumpbin for GetRandomInt(0, Size)
// VSR: UsePTeam, ObeyIdleVictim and the MinDistance / Position pair are live; CategoryMask (0 = all), IncludeItemsAddedThisTurn (false), IgnoreInvincible (true),
// MatchMask (0) and ObjClass / ODFName (NULL) are LTCG-folded at every shipped call site — the ancestor logic for them is kept. Note: the distance test keeps
// objects CLOSER than MinDistance (the PDB's name for it); a MinDistance of 0 skips the test.
Handle BZ1Helper::GetRandomObject(const int Team, const int TeamFilter, const bool UsePTeam, const int CategoryMask, const bool IncludeItemsAddedThisTurn, const bool IgnoreInvincible, const bool ObeyIdleVictim, const int MatchMask, const char *ObjClass, const char *ODFName, const float MinDistance, const Vector Position)
{
	const int NewCategoryMask = CategoryMask ? CategoryMask : -1;
	const int NewTeamFilter = TeamFilter ? TeamFilter : -1;
	const int NewMatchMask = MatchMask ? MatchMask : -1;
	const float MinDistanceSquared = MinDistance * MinDistance;

	unsigned int ObjClassHash = 0;
	unsigned int ODFNameHash = 0;

	if(ObjClass)
		ObjClassHash = Hash(ObjClass);

	if(ODFName)
		ODFNameHash = Hash(ODFName);

	const int NumHandles = m_ObjectHelper->GetNumHandles();
	int Size = IncludeItemsAddedThisTurn ? NumHandles-1 : m_LastObjectListCount-1;
	Size = clamp(Size, 0, NumHandles-1);

	int Start = GetRandomInt(0, Size);
	int x = Start;
	do
	{
		const ObjectHelper::ObjectClass &obj = m_ObjectHelper->GetHandleInfo(x);
		Handle Target = obj.ObjectHandle;

		if( ((Team < 0) || (TeamFilterCheck(NewTeamFilter, Team, UsePTeam ? obj.PTeam : obj.CurTeamNum))) && // Team Filter matches.
			((!IgnoreInvincible) || (obj.MaxHealth > 0)) && // Health matches.
			((!ObeyIdleVictim) || (obj.CanBeIdleVictim)) && // Idle-unit victims only, if asked.
			((MinDistance <= 0.0f) || (GetDistance3DSquared(Position, obj.Position) < MinDistanceSquared)) && // Within range of Position, if asked.
			(
			(((NewMatchMask & MatchMask_Category) == MatchMask_Category) && ((obj.CategoryID & NewCategoryMask) != 0)) || // Category matches.
			(((NewMatchMask & MatchMask_ObjClass) == MatchMask_ObjClass) && (ObjClass) && (obj.ObjClassHash == ObjClassHash)) || // Look for a specific Classlabel.
			(((NewMatchMask & MatchMask_ODFName) == MatchMask_ODFName) && (ODFName) && (obj.ODFNameHash == ODFNameHash)) // Look for a specific ODFName.
			))
		{
			return Target;
		}

		x++;
		if (x > Size)
			x = 0;
	} while (x != Start);

	return 0;
}

// Gets the number of objects matching the filters (same filters as GetRandomObject).
// DECOMPILE: not emitted as a symbol in the binary (inlined into its callers); ancestor logic + the VSR filters of GetRandomObject
int BZ1Helper::GetNumObjects(const int Team, const int TeamFilter, const bool UsePTeam, const int CategoryMask, const bool IncludeItemsAddedThisTurn, const bool IgnoreInvincible, const bool ObeyIdleVictim, const int MatchMask, const char *ObjClass, const char *ODFName)
{
	const int NewCategoryMask = CategoryMask ? CategoryMask : -1;
	const int NewTeamFilter = TeamFilter ? TeamFilter : -1;
	const int NewMatchMask = MatchMask ? MatchMask : -1;

	unsigned int ObjClassHash = 0;
	unsigned int ODFNameHash = 0;

	if(ObjClass)
		ObjClassHash = Hash(ObjClass);

	if(ODFName)
		ODFNameHash = Hash(ODFName);

	const int NumHandles = m_ObjectHelper->GetNumHandles();
	int Size = IncludeItemsAddedThisTurn ? NumHandles : m_LastObjectListCount;
	Size = clamp(Size, 0, NumHandles);

	int Count = 0;
	for (int x = 0; x < Size; x++)
	{
		const ObjectHelper::ObjectClass &obj = m_ObjectHelper->GetHandleInfo(x);

		if( ((Team < 0) || (TeamFilterCheck(NewTeamFilter, Team, UsePTeam ? obj.PTeam : obj.CurTeamNum))) && // Team Filter matches.
			((!IgnoreInvincible) || (obj.MaxHealth > 0)) && // Health matches.
			((!ObeyIdleVictim) || (obj.CanBeIdleVictim)) &&
			(
			(((NewMatchMask & MatchMask_Category) == MatchMask_Category) && ((obj.CategoryID & NewCategoryMask) != 0)) ||
			(((NewMatchMask & MatchMask_ObjClass) == MatchMask_ObjClass) && (ObjClass) && (obj.ObjClassHash == ObjClassHash)) ||
			(((NewMatchMask & MatchMask_ODFName) == MatchMask_ODFName) && (ODFName) && (obj.ODFNameHash == ODFNameHash))
			))
		{
			Count++;
		}
	}

	return Count;
}

// DECOMPILE: bz1helper.cpp:4163-4221  @4fc11323  (reference/decompiled/strategy02-ghidra12.2/src/missions/vsrcore/bz1helper.cpp.decomp.c) + dumpbin for the register-passed TeamFilterCheck / Hash arguments
// Gets the nearest object to a Vector position, with filtering options. "Team" is an optional Team to compare against with TeamFilter.
// VSR: UsePTeam compares the perceived team; CategoryID is a bit mask now so the category test is one AND; the stored MaxHealth replaces GetMaxHealth(h).
// IgnoreInvincible (true), ObeyIdleVictim (false) and ODFName (NULL) are LTCG-folded at every shipped call site; the ancestor logic for them is kept.
Handle BZ1Helper::GetNearestObject(const Vector Position, const float MaxRange, const int Team, const int TeamFilter, const bool UsePTeam, const int CategoryMask, const bool IgnoreInvincible, const bool ObeyIdleVictim, const Handle Me, const int MatchMask, const char *ObjClass, const char *ODFName)
{
	const int NewCategoryMask = CategoryMask ? CategoryMask : -1;
	const int NewTeamFilter = TeamFilter ? TeamFilter : -1;
	const int NewMatchMask = MatchMask ? MatchMask : -1;
	Handle TempH = 0;

	unsigned int ObjClassHash = 0;
	unsigned int ODFNameHash = 0;

	if(ObjClass)
		ObjClassHash = Hash(ObjClass);

	if(ODFName)
		ODFNameHash = Hash(ODFName);

	float BestDistSquared = MaxRange <= 0 ? FLT_MAX : Squared(MaxRange); // Start out with MaxRange, or infinite.
	const int NumHandles = m_ObjectHelper->GetNumHandles();
	for (int i = 0; i < NumHandles; ++i)
	{
		const ObjectHelper::ObjectClass &obj = m_ObjectHelper->GetHandleInfo(i);
		if( ((!Me) || (Me != obj.ObjectHandle)) && // It's not itself, if we passed in a handle.
			((Team < 0) || (TeamFilterCheck(NewTeamFilter, Team, UsePTeam ? obj.PTeam : obj.CurTeamNum))) && // Team Filter matches.
			((!IgnoreInvincible) || (obj.MaxHealth > 0)) && // Health matches.
			((!ObeyIdleVictim) || (obj.CanBeIdleVictim)) && // folded: reconstructed from the field + the PDB name; inert at the shipped default.
			(
			(((NewMatchMask & MatchMask_Category) == MatchMask_Category) && ((obj.CategoryID & NewCategoryMask) != 0)) || // Category matches.
			(((NewMatchMask & MatchMask_ObjClass) == MatchMask_ObjClass) && (ObjClass) && (obj.ObjClassHash == ObjClassHash)) || // Look for a specific Classlabel.
			(((NewMatchMask & MatchMask_ODFName) == MatchMask_ODFName) && (ODFName) && (obj.ODFNameHash == ODFNameHash)) // Look for a specific ODFName.
			))
		{
			float DistSquared = GetDistance3DSquared(obj.Position, Position);
			if (BestDistSquared > DistSquared) // It is closer then our last found Handle.
			{
				BestDistSquared = DistSquared;
				TempH = obj.ObjectHandle;
			}
		}
	}

	return TempH;
}
// Inspired by TRO function, gets the nearest object to a path point, with filtering options.
// DECOMPILE: inlined into its callers (no procedure of its own in any of the four DLLs)
Handle BZ1Helper::GetNearestObject(const Name Path, const int Point, const float MaxRange, const int Team, const int TeamFilter, const bool UsePTeam, int CategoryMask, const bool IgnoreInvincible, const bool ObeyIdleVictim, const int MatchMask, const char *ObjClass, const char *ODFName)
{
	if(!DoesPathExist(Path))
		return 0;

	return GetNearestObject(GetVectorFromPath(Path, Point), MaxRange, Team, TeamFilter, UsePTeam, CategoryMask, IgnoreInvincible, ObeyIdleVictim, 0, MatchMask, ObjClass, ODFName);
}
// Version that takes a Handle.
// DECOMPILE: bz1helper.cpp:4232-4237  @4fc11490  (reference/decompiled/strategy02-ghidra12.2/src/missions/vsrcore/bz1helper.cpp.decomp.c)
Handle BZ1Helper::GetNearestObject(const Handle h, const float MaxRange, const int Team, const int TeamFilter, const bool UsePTeam, const int CategoryMask, const bool IgnoreInvincible, const bool ObeyIdleVictim, const int MatchMask, const char *ObjClass, const char *ODFName)
{
	if(!IsAround(h))
		return 0;

	return GetNearestObject(GetPosition(h), MaxRange, Team, TeamFilter, UsePTeam, CategoryMask, IgnoreInvincible, ObeyIdleVictim, h, MatchMask, ObjClass, ODFName);
}
// Version that takes a Matrix
// DECOMPILE: inlined into its callers (no procedure of its own in any of the four DLLs)
Handle BZ1Helper::GetNearestObject(const Matrix Position, const float MaxRange, const int Team, const int TeamFilter, const bool UsePTeam, const int CategoryMask, const bool IgnoreInvincible, const bool ObeyIdleVictim, const int MatchMask, const char *ObjClass, const char *ODFName)
{
	return GetNearestObject(Position.posit, MaxRange, Team, TeamFilter, UsePTeam, CategoryMask, IgnoreInvincible, ObeyIdleVictim, 0, MatchMask, ObjClass, ODFName);
}

// VSR: the same searches over the vehicle list. No procedure and no caller survive in any shipped DLL (the Lua GetNearestVehicle binding calls the engine's), so these mirror the object searches; the fourth bool is named IgnoreDeployed by reconstruction.
// DECOMPILE: not emitted as a symbol in the binary
Handle BZ1Helper::GetRandomVehicle(const int Team, const int TeamFilter, const bool UsePTeam, const bool IncludeItemsAddedThisTurn, const bool IgnoreInvincible, const bool ObeyIdleVictim, const int MatchMask, const char *ObjClass, const char *ODFName, const float MinDistance, const Vector Position)
{
	const int NewTeamFilter = TeamFilter ? TeamFilter : -1;
	const int NewMatchMask = MatchMask ? MatchMask : -1;
	const float MinDistanceSquared = MinDistance * MinDistance;

	unsigned int ObjClassHash = 0;
	unsigned int ODFNameHash = 0;

	if(ObjClass)
		ObjClassHash = Hash(ObjClass);

	if(ODFName)
		ODFNameHash = Hash(ODFName);

	const int NumVehicles = m_VehicleHelper->GetNumVehicles();
	if (NumVehicles <= 0)
		return 0;
	int Size = IncludeItemsAddedThisTurn ? NumVehicles-1 : NumVehicles-1;
	Size = clamp(Size, 0, NumVehicles-1);

	int Start = GetRandomInt(0, Size);
	int x = Start;
	do
	{
		const VehicleHelper::VehicleClass &veh = m_VehicleHelper->GetVehicleInfo(x);

		if( ((Team < 0) || (TeamFilterCheck(NewTeamFilter, Team, UsePTeam ? veh.PTeam : veh.CurTeamNum))) &&
			((!IgnoreInvincible) || (veh.MaxHealth > 0)) &&
			((!ObeyIdleVictim) || (veh.CanBeIdleVictim)) &&
			((MinDistance <= 0.0f) || (GetDistance3DSquared(Position, veh.Position) < MinDistanceSquared)) &&
			(
			((NewMatchMask & MatchMask_Category) == MatchMask_Category) ||
			(((NewMatchMask & MatchMask_ObjClass) == MatchMask_ObjClass) && (ObjClass) && (veh.ObjClassHash == ObjClassHash)) ||
			(((NewMatchMask & MatchMask_ODFName) == MatchMask_ODFName) && (ODFName) && (veh.ODFNameHash == ODFNameHash))
			))
		{
			return veh.ObjectHandle;
		}

		x++;
		if (x > Size)
			x = 0;
	} while (x != Start);

	return 0;
}

// DECOMPILE: not emitted as a symbol in the binary
int BZ1Helper::GetNumVehicle(const int Team, const int TeamFilter, const bool UsePTeam, const bool /*IncludeItemsAddedThisTurn*/, const bool IgnoreInvincible, const bool ObeyIdleVictim, const int MatchMask, const char *ObjClass, const char *ODFName)
{
	const int NewTeamFilter = TeamFilter ? TeamFilter : -1;
	const int NewMatchMask = MatchMask ? MatchMask : -1;

	unsigned int ObjClassHash = 0;
	unsigned int ODFNameHash = 0;

	if(ObjClass)
		ObjClassHash = Hash(ObjClass);

	if(ODFName)
		ODFNameHash = Hash(ODFName);

	int Count = 0;
	const int NumVehicles = m_VehicleHelper->GetNumVehicles();
	for (int x = 0; x < NumVehicles; x++)
	{
		const VehicleHelper::VehicleClass &veh = m_VehicleHelper->GetVehicleInfo(x);

		if( ((Team < 0) || (TeamFilterCheck(NewTeamFilter, Team, UsePTeam ? veh.PTeam : veh.CurTeamNum))) &&
			((!IgnoreInvincible) || (veh.MaxHealth > 0)) &&
			((!ObeyIdleVictim) || (veh.CanBeIdleVictim)) &&
			(
			((NewMatchMask & MatchMask_Category) == MatchMask_Category) ||
			(((NewMatchMask & MatchMask_ObjClass) == MatchMask_ObjClass) && (ObjClass) && (veh.ObjClassHash == ObjClassHash)) ||
			(((NewMatchMask & MatchMask_ODFName) == MatchMask_ODFName) && (ODFName) && (veh.ODFNameHash == ODFNameHash))
			))
		{
			Count++;
		}
	}

	return Count;
}

// DECOMPILE: not emitted as a symbol in the binary
Handle BZ1Helper::GetNearestVehicle(const Matrix Position, const float MaxRange, const int Team, const int TeamFilter, const bool UsePTeam, const bool IgnoreInvincible, const bool ObeyIdleVictim, const bool IgnoreDeployed, const int MatchMask, const char *ObjClass, const char *ODFName)
{
	return GetNearestVehicle(Position.posit, MaxRange, Team, TeamFilter, UsePTeam, IgnoreInvincible, ObeyIdleVictim, IgnoreDeployed, 0, MatchMask, ObjClass, ODFName);
}

Handle BZ1Helper::GetNearestVehicle(const Handle h, const float MaxRange, const int Team, const int TeamFilter, const bool UsePTeam, const bool IgnoreInvincible, const bool ObeyIdleVictim, const bool IgnoreDeployed, const int MatchMask, const char *ObjClass, const char *ODFName)
{
	if(!IsAround(h))
		return 0;

	return GetNearestVehicle(GetPosition(h), MaxRange, Team, TeamFilter, UsePTeam, IgnoreInvincible, ObeyIdleVictim, IgnoreDeployed, h, MatchMask, ObjClass, ODFName);
}

Handle BZ1Helper::GetNearestVehicle(const Name Path, const int Point, const float MaxRange, const int Team, const int TeamFilter, const bool UsePTeam, const bool IgnoreInvincible, const bool ObeyIdleVictim, const bool IgnoreDeployed, const int MatchMask, const char *ObjClass, const char *ODFName)
{
	if(!DoesPathExist(Path))
		return 0;

	return GetNearestVehicle(GetVectorFromPath(Path, Point), MaxRange, Team, TeamFilter, UsePTeam, IgnoreInvincible, ObeyIdleVictim, IgnoreDeployed, 0, MatchMask, ObjClass, ODFName);
}

Handle BZ1Helper::GetNearestVehicle(const Vector Position, const float MaxRange, const int Team, const int TeamFilter, const bool UsePTeam, const bool IgnoreInvincible, const bool ObeyIdleVictim, const bool IgnoreDeployed, const Handle Me, const int MatchMask, const char *ObjClass, const char *ODFName)
{
	const int NewTeamFilter = TeamFilter ? TeamFilter : -1;
	const int NewMatchMask = MatchMask ? MatchMask : -1;
	Handle TempH = 0;

	unsigned int ObjClassHash = 0;
	unsigned int ODFNameHash = 0;

	if(ObjClass)
		ObjClassHash = Hash(ObjClass);

	if(ODFName)
		ODFNameHash = Hash(ODFName);

	float BestDistSquared = MaxRange <= 0 ? FLT_MAX : Squared(MaxRange); // Start out with MaxRange, or infinite.
	const int NumVehicles = m_VehicleHelper->GetNumVehicles();
	for (int i = 0; i < NumVehicles; ++i)
	{
		const VehicleHelper::VehicleClass &veh = m_VehicleHelper->GetVehicleInfo(i);
		if( ((!Me) || (Me != veh.ObjectHandle)) && // It's not itself, if we passed in a handle.
			((Team < 0) || (TeamFilterCheck(NewTeamFilter, Team, UsePTeam ? veh.PTeam : veh.CurTeamNum))) && // Team Filter matches.
			((!IgnoreInvincible) || (veh.MaxHealth > 0)) && // Health matches.
			((!ObeyIdleVictim) || (veh.CanBeIdleVictim)) &&
			((!IgnoreDeployed) || (!IsDeployed(veh.ObjectHandle))) &&
			(
			((NewMatchMask & MatchMask_Category) == MatchMask_Category) ||
			(((NewMatchMask & MatchMask_ObjClass) == MatchMask_ObjClass) && (ObjClass) && (veh.ObjClassHash == ObjClassHash)) ||
			(((NewMatchMask & MatchMask_ODFName) == MatchMask_ODFName) && (ODFName) && (veh.ODFNameHash == ODFNameHash))
			))
		{
			float DistSquared = GetDistance3DSquared(veh.Position, Position);
			if (BestDistSquared > DistSquared) // It is closer then our last found Handle.
			{
				BestDistSquared = DistSquared;
				TempH = veh.ObjectHandle;
			}
		}
	}

	return TempH;
}

// VSR: the building searches live on BuildingHelper; these forward.
// DECOMPILE: not emitted as a symbol in the binary (forwarder)
Handle BZ1Helper::GetRandomBuilding(const int Team, const int TeamFilter, const bool UsePTeam, const bool IgnoreInvincible, const bool ObeyIdleVictim, const int MatchMask, const char *ObjClass, const char *ODFName, const float MinDistance, const Vector Position)
{
	return m_BuildingHelper->GetRandomBuilding(Team, TeamFilter, UsePTeam, IgnoreInvincible, ObeyIdleVictim, MatchMask, ObjClass, ODFName, MinDistance, Position);
}

int BZ1Helper::GetNumBuildings(const int Team, const int TeamFilter, const bool UsePTeam, const bool IgnoreInvincible, const bool ObeyIdleVictim, const int MatchMask, const char *ObjClass, const char *ODFName)
{
	return m_BuildingHelper->GetNumBuildings(Team, TeamFilter, UsePTeam, IgnoreInvincible, ObeyIdleVictim, MatchMask, ObjClass, ODFName);
}

Handle BZ1Helper::GetNearestBuilding(const Matrix Position, const float MaxRange, const int Team, const int TeamFilter, const bool UsePTeam, const bool IgnoreInvincible, const bool ObeyIdleVictim, const int MatchMask, const char *ObjClass, const char *ODFName)
{
	return m_BuildingHelper->GetNearestBuilding(Position, MaxRange, Team, TeamFilter, UsePTeam, IgnoreInvincible, ObeyIdleVictim, MatchMask, ObjClass, ODFName);
}

Handle BZ1Helper::GetNearestBuilding(const Handle h, const float MaxRange, const int Team, const int TeamFilter, const bool UsePTeam, const bool IgnoreInvincible, const bool ObeyIdleVictim, const int MatchMask, const char *ObjClass, const char *ODFName)
{
	return m_BuildingHelper->GetNearestBuilding(h, MaxRange, Team, TeamFilter, UsePTeam, IgnoreInvincible, ObeyIdleVictim, MatchMask, ObjClass, ODFName);
}

Handle BZ1Helper::GetNearestBuilding(const Name Path, const int Point, const float MaxRange, const int Team, const int TeamFilter, const bool UsePTeam, const bool IgnoreInvincible, const bool ObeyIdleVictim, const int MatchMask, const char *ObjClass, const char *ODFName)
{
	return m_BuildingHelper->GetNearestBuilding(Path, Point, MaxRange, Team, TeamFilter, UsePTeam, IgnoreInvincible, ObeyIdleVictim, MatchMask, ObjClass, ODFName);
}

Handle BZ1Helper::GetNearestBuilding(const Vector Position, const float MaxRange, const int Team, const int TeamFilter, const bool UsePTeam, const bool IgnoreInvincible, const bool ObeyIdleVictim, const Handle Me, const int MatchMask, const char *ObjClass, const char *ODFName)
{
	return m_BuildingHelper->GetNearestBuilding(Position, MaxRange, Team, TeamFilter, UsePTeam, IgnoreInvincible, ObeyIdleVictim, Me, MatchMask, ObjClass, ODFName);
}

// Builds a vehicle, with options.
// DECOMPILE: no procedure of its own in any shipped DLL (inlined into the mission DLLs); the 2015 bodies are kept.
Handle BZ1Helper::BuildAngleObject(const char *ODF, const int Team, const Vector &pos, const char *Label, const float Degrees, const int Group, const bool Empty, const bool StartDeploy, const float HeightOffset, const bool SpreadOut, const int AlignToTerrain, const bool AlignUseWater)
{
	Handle h = Label ? GetHandle(Label) : 0;
	if(!IsAround(h))
	{
		Matrix BuildLoc = Matrix(Vector(1, 0, 0),Vector(0, 1, 0), Vector(0, 0, 1), pos); // Initialize default Matrix.

		h = BuildAngleObject(ODF, Team, BuildLoc, Label, Degrees, Group, Empty, StartDeploy, HeightOffset, SpreadOut, AlignToTerrain, AlignUseWater);
	}
	return h;
}

Handle BZ1Helper::BuildAngleObject(const char *ODF, const int Team, const AiPath *APath, const char *Label, const float Degrees, const int Group, const bool Empty, const bool StartDeploy, const float HeightOffset, const bool SpreadOut, const int AlignToTerrain, const bool AlignUseWater)
{
	Handle h = Label ? GetHandle(Label) : 0;
	if(!IsAround(h))
	{
		Handle TempH = BuildObject("abstor",0,const_cast<AiPath *>(APath)); // the SDK takes a non-const AiPath*
		if(!IsAround(TempH))
			return 0;
		Matrix BuildLoc = GetMatrixPosition(TempH);
		RemoveObject(TempH);

		h = BuildAngleObject(ODF, Team, BuildLoc, Label, Degrees, Group, Empty, StartDeploy, HeightOffset, SpreadOut, AlignToTerrain, AlignUseWater);
	}
	return h;
}

Handle BZ1Helper::BuildAngleObject(const char *ODF, const int Team, const Name APath, const char *Label, const float Degrees, const int Group, const bool Empty, const bool StartDeploy, const float HeightOffset, const bool SpreadOut, const int AlignToTerrain, const bool AlignUseWater)
{
	Handle h = Label ? GetHandle(Label) : 0;
	if(!IsAround(h))
	{
		if(!DoesPathExist(APath))
		{
			FormatLogMessage("ERROR: Pathpoint %s missing, cannot build ODF %s", APath, ODF); 
			return 0;
		}
		Matrix BuildLoc = Matrix(Vector(1, 0, 0),Vector(0, 1, 0), Vector(0, 0, 1), GetVectorFromPath(APath)); // Initialize default Matrix.

		h = BuildAngleObject(ODF, Team, BuildLoc, Label, Degrees, Group, Empty, StartDeploy, HeightOffset, SpreadOut, AlignToTerrain, AlignUseWater);
	}
	return h;
}

Handle BZ1Helper::BuildAngleObject(const char *ODF, const int Team, const Handle him, const char *Label, const float Degrees, const int Group, const bool Empty, const bool StartDeploy, const float HeightOffset, const bool SpreadOut, const int AlignToTerrain, const bool AlignUseWater)
{
	Handle h = Label ? GetHandle(Label) : 0;
	if(!IsAround(h))
	{
		if(!IsAround(him))
		{
			FormatLogMessage("ERROR: BuildObject Failed, Handle missing, cannot build ODF %s", ODF); 
			return 0;
		}
		Matrix BuildLoc = Matrix(Vector(1, 0, 0),Vector(0, 1, 0), Vector(0, 0, 1), Vector(0, 0, 0)); // Initialize default Matrix.
		// Special case for Portals.
		if(IsPortal(him))
			BuildLoc = GetODFPositionOffset(him, 0);
		else
			GetPosition(him, BuildLoc);

		h = BuildAngleObject(ODF, Team, BuildLoc, Label, Degrees, Group, Empty, StartDeploy, HeightOffset, SpreadOut, AlignToTerrain, AlignUseWater);
	}
	return h;
}

Handle BZ1Helper::BuildAngleObject(const char *ODF, const int Team, const Matrix &mat, const char *Label, const float Degrees, const int Group, const bool Empty, const bool StartDeploy, const float HeightOffset, const bool SpreadOut, const int AlignToTerrain, const bool AlignUseWater)
{
	Handle h = Label ? GetHandle(Label) : 0;
	if(!IsAround(h))
	{
		if(!ODF[0])
			return 0;

		int TempPilotCost = 0; //Default of 0.
		char TempODF[MAX_ODF_LENGTH] = {0};
		strcpy_s(TempODF, ODF);
		Matrix BuildLoc = mat;
		if(Degrees > 0.0f)
		{
			Vector Front(0.0f, 0.0f, 1.0f);
			Front = HRotateFront(Front, Degrees * DEG_2_RAD);
			BuildLoc = Build_Directinal_Matrix(BuildLoc.posit, Front);
		}

		if((SpreadOut) && (GetTurnCount() > 1) && ((_strnicmp(TempODF+1,"v",1) == 0) || (_strnicmp(TempODF+1,"s",1) == 0))) // It's a vehicle, try to spread out position.
			BuildLoc.posit = GetPositionNear(BuildLoc.posit, 2.0f, 10.0f);

		if(AlignToTerrain) // If not set to 0 (False) by script. e.g. -1 (default) or 1 (True).
		{
			// Read ODF Parameter, that overrides the "Default" setting. Script can override everything.
			bool ODFOverride = false;
			bool UseAlign = true;
			char TempODF2[MAX_ODF_LENGTH] = {0};
			char TempODF3[MAX_ODF_LENGTH] = {0};
			char ClassLabel[MAX_ODF_LENGTH] = {0};
			sprintf_s(TempODF2, "%s.odf", ODF); // Add odf to the end.

			if(OpenODF2(TempODF2))
			{
				if(GetODFString(TempODF2, "GameObjectClass", "classlabel", MAX_ODF_LENGTH, ClassLabel))
				{
					sprintf_s(TempODF3, "%s.odf", ClassLabel); // Add odf to the end.
					OpenODF2(TempODF3);
				}

				if(GetODFBool(TempODF2, TempODF3, "GameObjectClass", "AlignToTerrain", &UseAlign, false))
					ODFOverride = true;
			}

			if(AlignToTerrain < 0) // Auto Determine
			{
				if((!ODFOverride) && (DefaultAlignToTerrain(ODF)))	
					UseAlign = true;
			}
			else // Force on via script command. (If script wanted it off, none of this code section runs)
			{
				UseAlign = true;
			}

			// If the above code checks didn't disable aligntoterrain.
			if(UseAlign)
			{
				Vector ANormal(0, 0, 0);
				float Height = 0.0f;
				TerrainGetHeightAndNormal(BuildLoc.posit, Height, ANormal, AlignUseWater);
				BuildLoc = Build_Orthogonal_Matrix(ANormal, BuildLoc.front, BuildLoc.posit);
			}
		}

		BuildLoc.posit.y += HeightOffset;

		GetWorldVariantODF(TempODF);

		if(DoesODFExist(TempODF))
		{
			TempPilotCost = GetPilotCost(TempODF);
			if((!Empty) && (GetTurnCount() > 1))
				AddPilot(Team,TempPilotCost);
			h = BuildObject(TempODF, Team, BuildLoc);
		}
		else
		{
			FormatLogMessage("ERROR: ODF %s doesn't exist, Fix DLLs!", TempODF);
			return 0;
		}

		if(h != 0)
		{
			if(_strnicmp(TempODF+1,"v",1) == 0) // It's a vehicle, set it's group and rotate it.
			{
				if(Group < 0)
					SetBestGroup(h);
				if(Group > 0)
					SetGroup(h,Group-1);
			}
			else if(_strnicmp(TempODF+1, "s", 1) == 0) // This is a pilot. By Default, don't add it to PilotDispatch code.
			{
				SetIndependence(h, 1); // 2015: SetPilotIndependence(h, 0) through the PilotResourceHelper VSR no longer has — the pilot keeps the game's own AI.
			}

			// Special for class Turret. They snap to center of terrain square, in cases of SP missions this is not desirable.
			if(IsGunTower(h))
			{
				bool Snappy = false;
				GetODFBool(h, "TurretCraftClass", "DLLSnapToPosition", &Snappy, false);
				if(Snappy)
					SetPosition(h, BuildLoc);
			}

			if(StartDeploy)
				Deploy(h);

			if(Empty)
				RemovePilotAI(h);

			if(Label && Label[0])
				SetLabel(h, Label);
		}
	}
	return h;
}

// Sets the CPU Plan based on var options. Includes Race Team# and World Variant.
// DECOMPILE: not emitted as a symbol in the binary (inlined into the mission DLLs; the 2015 body is kept)
void BZ1Helper::SetCPUPlan(const char *AIPBaseName, const char Race, const int Team)
{
	if((Team < 0) || (Team > MAX_TEAMS))
		return; // ByeBye.

	char AIPBaseFile[256] = {0};
	strcpy_s(AIPBaseFile, AIPBaseName);

	// Use the default BZC naming scheme if not specified.
	if((AIPBaseFile == NULL) || (AIPBaseFile[0] == '\0'))
		strcpy_s(AIPBaseFile, "bzcnorm_");

	char AIPFile[256] = {0};

	if(WorldSetting)
		sprintf_s(AIPFile, "%s%c%d%c.aip", AIPBaseFile, Race, Team, WorldSetting); // Removed the Herobine element. -GBD

	if((!WorldSetting) || (!DoesFileExist(AIPFile)))
		sprintf_s(AIPFile, "%s%c%d.aip", AIPBaseFile, Race, Team); // Try without the World Setting.

	// Make the Team Number optional.
	if(!DoesFileExist(AIPFile))
	{
		if(WorldSetting)
			sprintf_s(AIPFile, "%s%c%c.aip", AIPBaseFile, Race, WorldSetting); // Try without the Team number.

		if((!WorldSetting) || (!DoesFileExist(AIPFile)))
			sprintf_s(AIPFile, "%s%c.aip", AIPBaseFile, Race); // Try without the World Setting.
	}

	SetAIPFile(AIPFile, Team);
}

// Attempts to play an AudioMessage, and saves it as the last one played.
// DECOMPILE: not emitted as a symbol in the binary (inlined into the mission DLLs; the 2015 body is kept)
int BZ1Helper::MissionAudioMessage(const char* msg)
{
	if(!msg)
		return 0;

	strcpy_s((char *)MissionAudioFile, sizeof(MissionAudioFile), msg);
	MissionAudioHandle = AudioMessage(msg);
	return MissionAudioHandle;
}

// Repeats the last message played via MissionAudioMessage.
int BZ1Helper::RepeatAudioMessage(void)
{
	if(MissionAudioFile[0])
	{ 
		MissionAudioHandle = AudioMessage((char*)(&MissionAudioFile[0]));
		return MissionAudioHandle;
	}
	else
	{ 
		return 0;
	}
}

// VSR: queue a build order for a producer at a drop-off position (Execute moves the finished unit there); recyclers / factories are type 1, armories type 2.
// DECOMPILE: inlined forwarders (no procedure of their own); the Vector version is bz1helper.cpp:4734-4767  @4fc114f2
void BZ1Helper::BuildAt(const Handle me, const char *ODF, const Handle Pos, const int Priority)
{
	if (!IsAround(Pos))
		return;
	BuildAt(me, ODF, GetPosition(Pos), Priority);
}

void BZ1Helper::BuildAt(const Handle me, const char *ODF, const Name Path, const int Point, const int Priority)
{
	if (!DoesPathExist(Path))
		return;
	BuildAt(me, ODF, GetVectorFromPath(Path, Point), Priority);
}

void BZ1Helper::BuildAt(const Handle me, const char *ODF, const Matrix Pos, const int Priority)
{
	BuildAt(me, ODF, Pos.posit, Priority);
}

// DECOMPILE: bz1helper.cpp:4734-4767  @4fc114f2  (reference/decompiled/strategy02-ghidra12.2/src/missions/vsrcore/bz1helper.cpp.decomp.c)
// Priority is LTCG-folded to 1 at every shipped call site (the stored Priority and the Build() priority are both the constant 1).
void BZ1Helper::BuildAt(const Handle me, const char *ODF, const Vector Pos, const int Priority)
{
	if (!IsAround(me) || !DoesODFExist(ODF))
		return;

	for (std::vector<BuildAtClass>::iterator iter = BuildAtList.begin(); iter != BuildAtList.end(); ++iter)
	{
		if (iter->BuilderHandle == me)
			return;
	}

	BuildAtList.resize(BuildAtList.size()+1);
	BuildAtClass &sao = BuildAtList[BuildAtList.size()-1]; // No temporary being created, *much* faster
	memset(&sao, 0, sizeof(BuildAtClass)); // Zero things out at start.

	sao.BuilderHandle = me;
	sao.BuildTurn = m_TurnCounter + 1;
	sao.DropoffPos = Pos;
	sao.Priority = Priority;

	char ObjClass[MAX_ODF_LENGTH] = {0};
	GetObjInfo(me, Get_GOClass, ObjClass);
	const unsigned int ObjClassHash = Hash(ObjClass);
	if ((ObjClassHash == CLASS_RECYCLER) || (ObjClassHash == CLASS_FACTORY))
		sao.BuilderType = 1;
	else if (ObjClassHash == CLASS_ARMORY)
		sao.BuilderType = 2;

	Build(me, ODF, Priority);
}

// VSR: can Team build ODFName? Scrap (unless IgnoreScrapCost), power (CheckBuildRequirements_PowerCost), pilots and the requireName list must all pass.
// The two trailing bools are dead in the shipped binary (every call site passes false, false; their PDB symbols are gone).
// DECOMPILE: bz1helper.cpp:4770-4972  @4fc11627  (reference/decompiled/strategy02-ghidra12.2/src/missions/vsrcore/bz1helper.cpp.decomp.c) + dumpbin for the register-passed arguments
bool BZ1Helper::CheckBuildRequirements(const char *ODFName, const int Team, const bool IgnoreScrapCost, const bool /*IgnoreRequireCount*/, const bool /*IgnorePowerCost*/)
{
	if (!ODFName)
		return false;

	char TempODF[MAX_ODF_LENGTH] = {0};
	char ClassODF[MAX_ODF_LENGTH] = {0};
	if (_stricmp(ODFName + strlen(ODFName) - 4, ".odf") != 0)
		CombineStrings(TempODF, ODFName, ".odf", MAX_ODF_LENGTH);
	else
		CombineStrings(TempODF, "", ODFName, MAX_ODF_LENGTH);

	if (!OpenODF2(TempODF))
		return false;

	char ClassLabel[MAX_ODF_LENGTH] = {0};
	if (GetODFString(TempODF, "GameObjectClass", "classlabel", MAX_ODF_LENGTH, ClassLabel))
	{
		CombineStrings(ClassODF, ClassLabel, ".odf", MAX_ODF_LENGTH);
		if (!OpenODF2(ClassODF))
			ClassODF[0] = '\0';
	}

	if (!IgnoreScrapCost)
	{
		int ScrapCost = 0;
		GetODFInt(TempODF, ClassODF, "GameObjectClass", "scrapCost", &ScrapCost, 0);
		if (GetScrap(Team) - ScrapCost < 0)
			return false;
	}

	if (CheckBuildRequirements_PowerCost(Team, TempODF, ClassODF) < 0)
		return false;

	int PilotCost = 0;
	GetODFInt(TempODF, ClassODF, "GameObjectClass", "pilotCost", &PilotCost, 0);
	if (PilotCost > teamInfo[Team].CurrPilots)
		return false;

	if (CheckBuildRequirements_RequireCount(NULL, Team, TempODF, ClassODF) > 0)
		return false;

	return true;
}

// Counts the requireName1..N entries Team does not own: an object's own ODF, its baseName, or one of its provideName1..N entries satisfies a requirement.
// The first argument is dead in the shipped binary (its PDB symbol is gone; call sites push a placeholder).
// DECOMPILE: bz1helper.cpp:4976-5067  @4fc117e4  (reference/decompiled/strategy02-ghidra12.2/src/missions/vsrcore/bz1helper.cpp.decomp.c) + dumpbin for the register-passed arguments
int BZ1Helper::CheckBuildRequirements_RequireCount(char ** /*UnusedArg*/, const int Team, const char *filename1, const char *filename2)
{
	int Unmet = 0;
	int RequireCount = 0;
	if (GetODFInt(filename1, filename2, "GameObjectClass", "requireCount", &RequireCount, 0) && RequireCount > 0)
	{
		for (int i = 1; i <= RequireCount; i++)
		{
			char RequireName[MAX_ODF_LENGTH] = {0};
			char DesiredValue[MAX_ODF_LENGTH] = {0};
			sprintf_s(DesiredValue, "requireName%d", i);
			bool Found = false;
			if (GetODFString(filename1, filename2, "GameObjectClass", DesiredValue, MAX_ODF_LENGTH, RequireName))
			{
				const int NumHandles = m_ObjectHelper->GetNumHandles();
				for (int x = 0; x < NumHandles && !Found; x++)
				{
					const ObjectHelper::ObjectClass &obj = m_ObjectHelper->GetHandleInfo(x);
					if (obj.CurTeamNum != Team)
						continue;

					const char *ODFName = GetODFName(obj.ObjectHandle);
					if (ODFName && _stricmp(RequireName, ODFName) == 0)
					{
						Found = true;
						break;
					}

					char BaseName[MAX_ODF_LENGTH] = {0};
					GetODFString(obj.ObjectHandle, "GameObjectClass", "baseName", MAX_ODF_LENGTH, BaseName);
					if (!BaseName[0])
					{
						int ProvideCount = 0;
						GetODFInt(obj.ObjectHandle, "GameObjectClass", "provideCount", &ProvideCount, 0);
						for (int j = 1; j <= ProvideCount; j++)
						{
							char ProvideValue[MAX_ODF_LENGTH] = {0};
							sprintf_s(ProvideValue, "provideName%d", j);
							GetODFString(obj.ObjectHandle, "GameObjectClass", ProvideValue, MAX_ODF_LENGTH, BaseName);
							if (_stricmp(RequireName, BaseName) == 0)
							{
								Found = true;
								break;
							}
						}
					}
					else if (_stricmp(RequireName, BaseName) == 0)
					{
						Found = true;
					}
				}
			}
			if (!Found)
				Unmet++;
		}
	}
	return Unmet;
}

// Scrap Accessor Functions.
void BZ1Helper::GetRidOfSomeScrap(const int ScrapLimit) { return m_ScrapHelper->GetRidOfSomeScrap(ScrapLimit); }

void BZ1Helper::ClearScrapAround(const Dist d, const Vector &v, const float Percent) { return m_ScrapHelper->ClearScrapAround(d, v, Percent); }

// Is this object blocked by a building?
// DECOMPILE: no procedure of its own in any shipped DLL; the 2015 body is kept (the building list is BuildingHelper's).
Handle BZ1Helper::IsBlockedByBuilding(const Handle h1, const Handle h2, const float WidthPadding, const Vector FrontA, const Vector FrontB, const bool IgnoreInvincible)
{
	if(!IsAround(h1) || !IsAround(h2))
		return 0;

	Matrix PositionA = GetMatrixPosition(h1);
	Matrix PositionB = GetMatrixPosition(h2);
	Handle TempH = 0;

	if(!IsNullVector(FrontA))
		PositionA = Build_Directinal_Matrix(PositionA.posit, FrontA);

	if(!IsNullVector(FrontB))
		PositionB = Build_Directinal_Matrix(PositionB.posit, FrontB);

	for (int i = 0; i < m_BuildingHelper->GetNumBuildingObjects(); i++)
	{
		const BuildingHelper::BuildingClass &buildingInfo = m_BuildingHelper->GetBuildingInfo(i);
		Handle Building = buildingInfo.BuildingObject;
		bool Proceed = true;
		// Loop over, make sure we ignore these object's Taps.
		for(int x = 0; x < buildingInfo.TapNumber; x++)
		{
			Handle tap = GetTap(Building, x);
			if((tap == h1) || (tap == h2) || (GetTap(h1, x) == Building) || (GetTap(h2, x) == Building))
			{
				Proceed = false;
				break;
			}
		}
		if(!Proceed)
			continue; // Skip to next building.

		// Make sure we don't include ourselves, or invincibles if we're ignoring them.
		if((Building != h1) && (Building != h2) && ((!IgnoreInvincible) || (buildingInfo.MaxHealth > 0)))
		{
			Vector buildingLocalPositionA = Vector_TransformInv(PositionA, buildingInfo.Position);
			const float buildingRadius = buildingInfo.CollisionRadius;
			const float totalLength = GetDistance2D(PositionA.posit, PositionB.posit);

			if ((fabsf(buildingLocalPositionA.x) < WidthPadding + buildingRadius) && (buildingLocalPositionA.z > -buildingRadius) && (buildingLocalPositionA.z < totalLength + buildingRadius))
			{
				TempH = Building;
				break;
			}
		}
	}
	return TempH;
}

// VSR base-placement helpers. None of the three has a procedure or a caller in any shipped DLL (declared in the PDB, never emitted), so the bodies below
// are RECONSTRUCTIONS from the names, the BuildingClass fields and the per-object-file FLAT_MAX_HEIGHT_DIFF constant — parity does not depend on them.
// DECOMPILE: not emitted in any shipped DLL — reconstructed
Vector BZ1Helper::FindClusterCenter(const Vector &Position, const int Team, const int MatchMask)
{
	// The mean position of Team's buildings (any building when MatchMask is 0, else those whose CategoryID bits match), or Position when it has none.
	Vector Sum(0.0f, 0.0f, 0.0f);
	int Count = 0;
	for (int i = 0; i < m_BuildingHelper->GetNumBuildingObjects(); i++)
	{
		const BuildingHelper::BuildingClass &building = m_BuildingHelper->GetBuildingInfo(i);
		if (building.CurTeamNum != Team)
			continue;
		if (MatchMask && !(MatchMask & CategoryType_Building))
			continue;
		Sum = Sum + building.Position;
		Count++;
	}
	if (!Count)
		return Position;
	return Sum / float(Count);
}

// DECOMPILE: not emitted in any shipped DLL — reconstructed
bool BZ1Helper::IsTerrainFlat(const Vector &Position, const int Width, const int Depth)
{
	// Flat when the terrain under a Width x Depth footprint (metres, sampled every grid step) varies by no more than FLAT_MAX_HEIGHT_DIFF.
	const float Step = (mapInfo.MPG > 0.0f) ? mapInfo.MPG : 1.0f;
	float MinY = FLT_MAX, MaxY = -FLT_MAX;
	for (float x = -Width * 0.5f; x <= Width * 0.5f; x += Step)
	{
		for (float z = -Depth * 0.5f; z <= Depth * 0.5f; z += Step)
		{
			const float y = TerrainFindFloor(Position.x + x, Position.z + z);
			if (y < MinY) MinY = y;
			if (y > MaxY) MaxY = y;
		}
	}
	return (MaxY - MinY) <= FLAT_MAX_HEIGHT_DIFF;
}

// DECOMPILE: not emitted in any shipped DLL — reconstructed
std::vector<std::pair<int, BuildingHelper::BuildingClass>> BZ1Helper::IsTerrainOccupied(const Vector &Position, const float Width, const float Depth, const bool IncludeVehicles, const bool IncludeDeployed)
{
	// Every building (optionally also deployed craft / vehicles) whose collision circle touches the Width x Depth footprint centred on Position.
	std::vector<std::pair<int, BuildingHelper::BuildingClass>> Occupants;
	for (int i = 0; i < m_BuildingHelper->GetNumBuildingObjects(); i++)
	{
		const BuildingHelper::BuildingClass &building = m_BuildingHelper->GetBuildingInfo(i);
		if (!IsAround(building.BuildingObject))
			continue;
		if (!IncludeDeployed && IsCraftButNotPerson(building.BuildingObject) && IsDeployed(building.BuildingObject))
			continue;
		if (!IncludeVehicles && IsCraftButNotPerson(building.BuildingObject) && !IsDeployed(building.BuildingObject))
			continue;
		const float dx = fabsf(building.Position.x - Position.x);
		const float dz = fabsf(building.Position.z - Position.z);
		if ((dx <= Width * 0.5f + building.CollisionRadius) && (dz <= Depth * 0.5f + building.CollisionRadius))
			Occupants.push_back(std::make_pair(i, building));
	}
	return Occupants;
}

// VSR: watch a dead team's player ship from a circling camera for Time seconds (PlayDeathCamera runs it; nothing in the four shipped DLLs calls this).
// DECOMPILE: no procedure and no caller in any shipped DLL — reconstructed from PlayDeathCamera / ClearDeathCamera's use of the three statics.
bool BZ1Helper::SetDeathCamera(const Handle h, const float Time)
{
	if (!IsNetworkOn() || !IsAround(h) || DeathCameraOn)
		return false;

	DeathCameraTeam = GetTeamNum(h);
	DeathCameraTime = m_TurnCounter + SecondsToTurns(Time);
	DeathCameraOn = true;
	CameraReady();
	return true;
}

// DECOMPILE: bz1helper.cpp:3252-3263  @4fc104a0  (reference/decompiled/strategy02-ghidra12.2/src/missions/vsrcore/bz1helper.cpp.decomp.c)
void BZ1Helper::ClearDeathCamera(void)
{
	if (DeathCameraOn)
	{
		DeathCameraTime = 0;
		DeathCameraTeam = -1;
		DeathCameraOn = false;
		CameraFinish();
	}
}

// DECOMPILE: bz1helper.cpp:3267-3291  @4fc104c5  (reference/decompiled/strategy02-ghidra12.2/src/missions/vsrcore/bz1helper.cpp.decomp.c) + dumpbin for CameraCircle's register arguments
// Circles the camera around the dead team's player ship until the circle finishes or DeathCameraTime passes. Returns true when it ended.
bool BZ1Helper::PlayDeathCamera(void)
{
	if (IsNetworkOn() && DeathCameraTeam > 0)
	{
		Handle PlayerH = GetPlayerHandle(DeathCameraTeam);
		if (DeathCameraOn && IsAround(PlayerH) && DeathCameraTeam > 0)
		{
			SetVelocity(PlayerH, Vector(0.0f, 0.0f, 0.0f));
			SetOmega(PlayerH, Vector(0.0f, 0.0f, 0.0f));
			if (CameraCircle(PlayerH, Vector(10.0f, 0.0f, 0.0f), PlayerH, Vector(10.0f, 10.0f, 10.0f)) || DeathCameraTime < m_TurnCounter)
			{
				if (IsNetworkOn())
					ClearDeathCamera();
				return true;
			}
		}
	}
	return false;
}

// Controls BZ1 pilots or BZ2 Power min/max gauges. 
// DECOMPILE: bz1helper.cpp:2975-3144  @4fc0fdfc  (reference/decompiled/strategy02-ghidra12.2/src/missions/vsrcore/bz1helper.cpp.decomp.c)
// Feeds the script.dll.* interface vars: repeat-audio request, the escape prompt for a dead team, per-base-slot hull / name / pilot-cost labels on the
// selected building's command panel, the pilot (or power) counter, and the four secondary gauges.
void BZ1Helper::BZ1Interface(void)
{
	const Handle PlayerH = GetPlayerHandle();
	if (!PlayerH)
		return;

	const int CmdrTeam = GetCommanderTeam(GetTeamNum(PlayerH));
	const int EscapeActive = IFace_GetInteger("script.dll.escape.active");

	if (IFace_GetInteger("script.dll.repeataudio"))
	{
		if (!EscapeActive && IsAudioMessageDone(MissionAudioHandle) && MissionAudioFile[0])
			MissionAudioHandle = AudioMessage((char *)MissionAudioFile, false);
		IFace_SetInteger("script.dll.repeataudio", 0);
	}

	if ((m_MaxLives > 0) && !EscapeActive && teamInfo[GetLocalPlayerTeamNumber()].TeamIsDead && !teamInfo[GetLocalPlayerTeamNumber()].RespawnPlayer)
		IFace_ConsoleCmd("mission.escape", true);

	char VarName[MAX_ODF_LENGTH] = {0};
	for (int i = 1; i <= MAX_BASE_SLOT_ITEMS; i++)
	{
		sprintf_s(VarName, "script.dll.pilotcost%d", i);
		IFace_SetString(VarName, "");
	}

	for (int Slot = 1; Slot < 10; Slot++)
	{
		const Handle BaseH = GetObjectByBaseSlot(CmdrTeam, Slot);
		if (!BaseH)
			continue;

		sprintf_s(VarName, "script.dll.base%dhull", Slot);
		IFace_SetFloat(VarName, GetHealth(BaseH));
		sprintf_s(VarName, "script.dll.basename%d", Slot);
		IFace_SetString(VarName, teamInfo[CmdrTeam].BaseSlotName[Slot-1]);

		if (teamInfo[CmdrTeam].ShowPilotCosts[Slot-1] && IsBuilding(BaseH) && IsSelected(BaseH))
		{
			for (int Item = 0; Item < MAX_BASE_SLOT_ITEMS; Item++)
			{
				sprintf_s(VarName, "script.dll.pilotcost%d", Item+1);
				const int PilotCost = teamInfo[CmdrTeam].BaseSlotPilotCost[Slot-1][Item];
				if (PilotCost == 1)
				{
					IFace_SetString(VarName, "P");
				}
				else if (PilotCost > 1)
				{
					char Cost[10] = {0};
					_snprintf_s(Cost, _TRUNCATE, "%d", PilotCost);
					IFace_SetString(VarName, Cost);
				}

				// The command panel's key for the tenth item is 0: the shipped build formats Item+1 and then overwrites with the
				// literal Command0 name (kept in that shape so the four literals match the binary's string table).
				if ((teamInfo[CmdrTeam].CurrPilots < PilotCost) || (GetScrap(CmdrTeam) < teamInfo[CmdrTeam].BaseSlotScrapCost[Slot-1][Item]) || IsBusy(BaseH))
				{
					sprintf_s(VarName, "CommandPanel.Command%d.Item.Cost.PilotCost", Item+1);
					if (Item == 9)
						sprintf_s(VarName, "CommandPanel.Command0.Item.Cost.PilotCost");
					IFace_Deactivate(VarName);
					sprintf_s(VarName, "CommandPanel.Command%d.Item.Cost.PilotCostDisabled", Item+1);
					if (Item == 9)
						sprintf_s(VarName, "CommandPanel.Command0.Item.Cost.PilotCostDisabled");
				}
				else
				{
					sprintf_s(VarName, "CommandPanel.Command%d.Item.Cost.PilotCostDisabled", Item+1);
					if (Item == 9)
						sprintf_s(VarName, "CommandPanel.Command0.Item.Cost.PilotCostDisabled");
					IFace_Deactivate(VarName);
					sprintf_s(VarName, "CommandPanel.Command%d.Item.Cost.PilotCost", Item+1);
					if (Item == 9)
						sprintf_s(VarName, "CommandPanel.Command0.Item.Cost.PilotCost");
				}
				IFace_Activate(VarName);
			}
		}
	}

	if (!teamInfo[CmdrTeam].m_UsePilots)
	{
		IFace_SetInteger("script.dll.currpilots", GetPower(CmdrTeam));
		IFace_SetInteger("script.dll.maxpilots", GetMaxPower(CmdrTeam));
		IFace_SetString("script.dll.pilotname", "Power");
	}
	else
	{
		IFace_SetInteger("script.dll.currpilots", teamInfo[CmdrTeam].CurrPilots);
		IFace_SetInteger("script.dll.maxpilots", teamInfo[CmdrTeam].MaxPilots);
		IFace_SetString("script.dll.pilotname", "Pilot");
	}

	if (HullGaugeSet)
	{
		IFace_SetFloat("script.dll.hull2", HullGauge2);
		HullGaugeSet = false;
	}
	else
	{
		IFace_SetFloat("script.dll.hull2", 0.0f);
	}
	if (AmmoGaugeSet)
	{
		IFace_SetFloat("script.dll.ammo2", AmmoGauge2);
		AmmoGaugeSet = false;
	}
	else
	{
		IFace_SetFloat("script.dll.ammo2", 0.0f);
	}
	if (AuxGaugeSet)
	{
		IFace_SetFloat("script.dll.gauge", AuxGauge);
		AuxGaugeSet = false;
	}
	else
	{
		IFace_SetFloat("script.dll.gauge", 0.0f);
	}
	if (CloakGaugeSet)
	{
		IFace_SetFloat("script.dll.cloak", CloakGauge);
		CloakGaugeSet = false;
	}
	else
	{
		IFace_SetFloat("script.dll.cloak", 0.0f);
	}
}

// Run environmental effects, gravity, water, sky, hazards, etc.
// DECOMPILE: not called and not emitted in any shipped DLL — the gravity cycle it held in 2015 is GravityHelper::Execute now; kept as a declared, empty hook.
void BZ1Helper::EnvironmentalSystems(void)
{
}

// Life management code.
// DECOMPILE: bz1helper.cpp:3148-3222  @4fc102f5  (reference/decompiled/strategy02-ghidra12.2/src/missions/vsrcore/bz1helper.cpp.decomp.c)
// A dead team out of lives hands its units to the commander team (teamplay) or to team 15; a dead team with lives left takes back what it parked on 15.
void BZ1Helper::BZ1Lives(void)
{
	PlayDeathCamera();

	for (int i = 0; i < MAX_TEAMS; i++)
	{
		if (!teamInfo[i].TeamIsDead)
			continue;

		const int NumHandles = m_ObjectHelper->GetNumHandles();
		if (teamInfo[i].PlayerLives < 1)
		{
			for (int x = 0; x < NumHandles; x++)
			{
				ObjectHelper::ObjectClass &obj = m_ObjectHelper->RefHandleInfo(x);
				if ((obj.CurTeamNum == i) && !IsPlayer(obj.ObjectHandle))
				{
					int NewTeam = 15;
					if (IsTeamplayOn())
					{
						NewTeam = GetCommanderTeam(i);
						if (NewTeam == i)
							NewTeam = 15;
					}
					SetTeamNum(obj.ObjectHandle, NewTeam);
					obj.CurTeamNum = NewTeam;
					Stop(obj.ObjectHandle, 0);
					SetBestGroup(obj.ObjectHandle);
				}
			}
		}
		else
		{
			for (int x = 0; x < NumHandles; x++)
			{
				ObjectHelper::ObjectClass &obj = m_ObjectHelper->RefHandleInfo(x);
				if ((obj.CurTeamNum == 15) && (obj.OriginalTeam == i) && !IsPlayer(obj.ObjectHandle))
				{
					SetTeamNum(obj.ObjectHandle, i);
					obj.CurTeamNum = i;
				}
				Stop(obj.ObjectHandle, 0); // sic: outside the if — every object is stopped while a dead team still has lives.
			}
		}
	}
}

