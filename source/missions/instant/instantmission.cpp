// PROVENANCE: ancestor reference/ancestor-1.3/Missions/Instant/InstantMission.cpp @353698f (the instant-action skeleton: starting vehicles, mpi* path spawns, scav cleanup, AIP switching, objectives, respawn) | decompile reference/decompiled/instant-ghidra12.2/src/missions/instant/instantmission.cpp.decomp.c (ctor 62-83, dtor 86-88, BuildStartingVehicle 95-144, SetCPUAIPlan 149-189, SetupExtraVehicles 194-304, Setup 308-350, AddCPUScav 358-431, AddObject 438-646, DeleteObject 649-684, CreateObjectives 687-730, TestObjectives 733-879, Execute 931-944, Load 949-1003, Save 1006-1035, PostLoad 1038-1051, DoGenericStrategy 1059-1637, PlayerEjected 1640-1647, PlayerDied 1657-1694, ObjectKilled 1697-1715, ObjectSniped 1718-1731, PreGetIn 1743-1755, BuildMission 1758-1760) + dumpbin of 4fc3fc7e-4fc42902 annotated with the PDB member offsets (the sprintf_s arguments, the race constants, the AddScrap loop, InitTaunts) | gbd-lua-port original/lua/Lua-Stock-Missions_ea4173f/Upload/VSR/Missions/Scripts/InstantMission.lua (names, comments, cross-check) | status: ported
#include <string.h>
#include <stdio.h>
#include <math.h>

#include "taunts.h"
#include "instantmission.h"
#include "trnallies.h"
#include "bzcscriptutils.h"

/*
InstantMission

Just add water!!
*/

// Distance from enemy m_Recycler for enemies to be parked for siege
// mode to be triggered.
const float kfSIEGE_DISTANCE = 250.0f;

const int kRACE_ISDF = 105; // ascii for 'i'
const int kRACE_SCION = 102; // ascii for 'f'

// Base AIP name for the VSR AIPs. 
const char *kStockAIPNameBase="VSR_";

//
// Errant scav-cleaning code. Added by Nathan Mates 7/20/01.
//
// By the way, this is mostly based on the cleanup of extra ships in
// the DM DLL. 
//

const char *AIPTypeExtensions="0123als"; // AIPType enum is offset in this string table

// Constructor
instantMission::instantMission(void)
{
	m_GameTPS = 20;
	EnableHighTPS(m_GameTPS);
	AllowRandomTracks(true); // If the user wants random music, we're fine with that.
	b_count = &b_last - &b_first - 1;
	b_array = &b_first + 1;

	f_count = &f_last - &f_first - 1;
	f_array = &f_first + 1;

	h_count = &h_last - &h_first - 1;
	h_array = &h_first + 1;

	i_count = &i_last - &i_first - 1;
	i_array = &i_first + 1;

	m_CustomAIPStr = (char*)(&m_CustomAIPInts[0]);
	m_CustomAIPStrLen = sizeof(m_CustomAIPInts);
	TRNAllies::SetupTRNAllies(GetMapTRNFilename());
}

instantMission::~instantMission()
{
	CleanupTaunts();
}

// Builds a starting vehicle on the specified team with either ODF1
// (preferred, if found) or ODF2 as its name, modified by the
// race and the recycler's variant. Sets group, if specified. Returns the handle
Handle instantMission::BuildStartingVehicle(int aTeam, int aRace, char *ODF1, char *ODF2, char *Where, int aGrp, char *Variant)
{
	if(!DoesPathExist(Where))
		return 0;

	Vector Pos = GetVectorFromPath(Where);
	Pos.y = TerrainFindFloor(Pos.x, Pos.z) + 0.1f;
	return BuildStartingVehicle(aTeam, aRace, ODF1, ODF2, Pos, aGrp, Variant);
}

Handle instantMission::BuildStartingVehicle(int aTeam, int aRace, char *ODF1, char *ODF2, Vector Where, int aGrp, char *Variant)
{
	char TempODF[64];

	// Try the variant first, then the plain name. -GBD
	strcpy_s(TempODF, ODF1);
	TempODF[0] = (char)aRace;
	sprintf_s(TempODF, "%s%s", TempODF, Variant);
	if(!DoesODFExist(TempODF))
	{
		strcpy_s(TempODF, ODF1);
		TempODF[0] = (char)aRace;
	}
	if(!DoesODFExist(TempODF))
	{
		// doesn't exist, so fallback to ODF2
		strcpy_s(TempODF, ODF2);
		TempODF[0] = (char)aRace;
		sprintf_s(TempODF, "%s%s", TempODF, Variant);
		if(!DoesODFExist(TempODF))
		{
			strcpy_s(TempODF, ODF2);
			TempODF[0] = (char)aRace;
		}
	}

	Handle h = BuildObject(TempODF, aTeam, Where);
	if(h != 0)
	{
		if(aGrp == -2)
			SetBestGroup(h);
		else if(aGrp >= 0)
			SetGroup(h, aGrp);
	}
	return h;
}

// Sets the current AIP based on CPU's race, and AIP type.
void instantMission::SetCPUAIPlan(AIPType Type, int Team)
{
	// Clamp to legal value if not in range
	if((Type<0) || (Type >=MAX_AIP_TYPE))
		Type=AIPType3;

	// Try to keep AI from getting hung up if user rushes them - NM 7/15/05
	if(((Type > AIPType3) && (m_CPUCommBunkerCount[Team] == 0)) && (m_LastCPUPlan[Team] <= AIPType3))
		return;

	char AIPFile[256] = {0};

	// If custom AIPs were specified, use them.
	const char* AIPString = m_CustomAIPStr[0] ? m_CustomAIPStr : kStockAIPNameBase; // Reduces duplicate code. -GBD 6/15/17

	if(_strnicmp(AIPString, "VSR_", 4) == 0) // VSR AIPs: <base><race><team>_<0..2>.aip, like Strategy. -GBD
	{
		int Random = int(floor(GetRandomFloat(3.0f)));
		if(Random > 2)
			Random = 2;
		sprintf_s(AIPFile, "%s%c%d_%d.aip", m_CustomAIPStr, (char)m_CPUTeamRace[Team], Team, Random);
		if(!DoesFileExist(AIPFile))
			sprintf_s(AIPFile, "%s%c%d_0.aip", m_CustomAIPStr, (char)m_CPUTeamRace[Team], Team);
	}
	else
	{
		// First pass, try to find an AIP that is designed to use Provides for enemy team, thus it only cares about CPU Race. This makes adding races much easier. -GBD 6/15/17
		sprintf_s(AIPFile, "%s%c_%c.aip", AIPString, (char)m_CPUTeamRace[Team], AIPTypeExtensions[Type]);
		// Fallback to old method if none exists. -GBD 6/15/17
		if (!DoesFileExist(AIPFile)) 
			sprintf_s(AIPFile, "%s%c%c%c.aip", AIPString, (char)m_CPUTeamRace[Team], (char)m_HumanTeamRace, AIPTypeExtensions[Type]);
	}

	SetAIPFile(AIPFile, Team);

	m_LastCPUPlan[Team] = Type;

	if(m_SetFirstAIP)
		DoTaunt(TAUNTS_Random);
	m_SetFirstAIP=true;
}

// And set up extra race-specific vehicles at pathpoints in the map.
void instantMission::SetupExtraVehicles(void)
{
	int pathCount;
	char **pathNames;
	GetAiPaths(pathCount, pathNames);

	char cCPUTeamRace = (char) m_CPUTeamRace[m_CompTeam];
	char cHumanTeamRace = (char) m_HumanTeamRace;
	size_t len;

	memset(m_NumCPUScavs, 0, sizeof(m_NumCPUScavs)); // Nothing in these lists now.

	for (int i = 0; i < pathCount; ++i)
	{
		char *Label = pathNames[i];
		if(strncmp(Label, "mpi", 3)==0)
		{
			// Starts with MPI. Process it.
			const int MaxODFLen = 64;
			char ODF1[MaxODFLen];
			char ODF2[MaxODFLen];
			// MUST pre-clear these - compiler can't tell that ODF2 is
			// sometimes used uninitialized. NM 3/9/07
			memset(ODF1, 0, sizeof(ODF1));
			memset(ODF2, 0, sizeof(ODF2));

			char *pUnderscore = strchr(Label, '_');
			if(pUnderscore == NULL)
				continue; // Misformat! No _ found! Bail!

			char *pUnderscore2 = strchr(pUnderscore+1, '_');
			if(pUnderscore2 == NULL)
			{
				// Only 1 underscore in the name, e.g. (mpic#_ivturr). Copy
				// everything after it to the first name.
				strcpy_s(ODF1, pUnderscore+1);
			}
			else
			{
				// 2 underscores in the name, e.g. (mpic#_ivturr_fvturr). Copy
				// everything between them to ODF1, rest to ODF2.
				len = (pUnderscore2 - pUnderscore) - 1;
				if(len > (sizeof(ODF2) - 1))
					len = (sizeof(ODF2) - 1);
				strncpy_s(ODF1, pUnderscore+1, len);
				strcpy_s(ODF2, pUnderscore2+1);
			}

			len = strlen(ODF1);
			if((len > 0) && (ODF1[len-1] == '_'))
				ODF1[len-1] = '\0';
			len = strlen(ODF2);
			if((len > 0) && (ODF2[len-1] == '_'))
				ODF2[len-1] = '\0';

			// For the CPU?
			if(strncmp(Label, "mpic", 4)==0)
			{
				if(ODF1[0] == cCPUTeamRace)
					BuildObject(ODF1, m_CompTeam, Label);
				else if(ODF2[0] == cCPUTeamRace)
					BuildObject(ODF2, m_CompTeam, Label);
			}
			else if(strncmp(Label, "mpiC", 4)==0)
			{
				if(ODF1[0])
				{
					ODF1[0]= cCPUTeamRace;
					BuildObject(ODF1, m_CompTeam, Label);
				}
				else if(ODF2[0])
				{
					ODF2[0] = cCPUTeamRace;
					BuildObject(ODF2, m_CompTeam, Label);
				}
			}
			else if(strncmp(Label, "mpih", 4)==0)
			{ 
				// For the human side
				Handle h = 0;
				if(ODF1[0] == cHumanTeamRace)
				{
					h=BuildObject(ODF1, m_StratTeam, Label);
					SetBestGroup(h);
				}
				else if(ODF2[0] == cHumanTeamRace)
				{
					h=BuildObject(ODF2, m_StratTeam, Label);
					SetBestGroup(h);
				}
			}
			else if(strncmp(Label, "mpiH", 4)==0)
			{
				// For the human side
				Handle h = 0;
				if(ODF1[0])
				{
					ODF1[0] = cHumanTeamRace;
					h=BuildObject(ODF1, m_StratTeam, Label);
					SetBestGroup(h);
				}
				else if(ODF2[0])
				{
					ODF2[0] = cHumanTeamRace;
					h=BuildObject(ODF2, m_StratTeam, Label);
					SetBestGroup(h);
				}
			}
		}
	}
}

void instantMission::Setup(void)
{
	SetAutoGroupUnits(false);

	/*
	Here's where you set the values at the start.  
	*/
	m_StartDone=false;
	m_TimeCount=1;
	m_FriendReinforcementTime=2500;
	m_EndCounter=0;
	m_CompTeam=6; // CPU teams are 6 and up. -GBD
	m_StratTeam=1;  // the default
	m_Obj1=(-1);

	m_TurnCounter=0;

	for(int i = 0; i < MAX_TEAMS; i++)
	{
		m_NumCPUScavs[i]=0; // Nothing in this list now.

		m_SiegeOn[i]=false;
		m_AntiAssault[i]=false;
		m_SiegeCounter[i]=0;
		m_LateGame[i]=false;
		m_AssaultCounter[i]=0;
		m_HaveArmory[i]=false;
	}

	m_Powerup1=NULL;
	m_Powerup2=NULL;
	m_Powerup3=NULL;
	m_Powerup4=NULL;

	PreloadODF("ivrecy");
	PreloadODF("fvrecy");
	PreloadODF("ivrecycpu");
	PreloadODF("fvrecycpu");

	m_LastTauntPrintedAt=-2000; // Force first message to be printed...
	DoTaunt(TAUNTS_GameStart);
}

// h points to a CPU scav (regular or hover). Add it to the lists,
// delete some older ones as needed. Same rules as for AddObject--
// NEVER call RemoveObject(scavHandle) during this function.
void instantMission::AddCPUScav(Handle scavHandle, int Team)
{
	// Ok, adding in another scav. Add to list (and don't trash
	// memory) This is a fast operation in all cases.
	if(m_NumCPUScavs[Team] < MAX_CPU_SCAVS)
		m_CPUScavList[Team][m_NumCPUScavs[Team]++] = scavHandle;

	// If our lists aren't full, then we're done from this function.
	if(m_NumCPUScavs[Team] < MAX_CPU_SCAVS)
		return;

	// Spice things up.
	DoTaunt(TAUNTS_Random);

	// If we get here, it's cleanup time. First pass - cull CPU scav
	// list of any dead ones, ones that changed teams, or ones that
	// aren't scavs anymore.
	Handle newScavList[MAX_CPU_SCAVS];
	int newScavListCount = 0;
	memset(newScavList, 0, sizeof(newScavList));
	int i;

	for(i = 0; i < m_NumCPUScavs[Team]; i++)
	{
		bool keepIt = false;
		// Do quick checks first
		Handle checkScav = m_CPUScavList[Team][i];
		if(IsAround(checkScav) && (GetTeamNum(checkScav) == m_CompTeam))
		{
			char ObjClass[64];
			GetObjInfo(checkScav, Get_GOClass, ObjClass);
			keepIt = (_stricmp(ObjClass, "CLASS_SCAVENGER") == 0) || (_stricmp(ObjClass, "CLASS_SCAVENGERH") == 0);
		}
		// Always keep the scavHandle passed in to this function.
		keepIt |= (checkScav == scavHandle);

		if(keepIt)
		{
			newScavList[newScavListCount++] = checkScav;
		}
	} // i loop over m_NumCPUScavs

	// Copy culled list back into master list.
	// (As shipped: the copy is sized by the whole per-team table, so it
	// runs past newScavList into the following teams' lists.)
	m_NumCPUScavs[Team] = newScavListCount;
	memcpy(m_CPUScavList, newScavList, sizeof(m_CPUScavList));

	// Now, if there's still too many scavs, kill from the youngest
	// scavs. (m_CPUScavList[0] is the oldest scav). Theoretically,
	// the oldest scavs are the furthest from the m_HumanRecycler, so
	// killing them shouldn't affect the gameplay too much. You could
	// probably improve this algorithm by keeping, say 10-15 scavs,
	// that are more than 150 meters from the m_HumanRecycler. That is
	// left as an exercise for the reader. :)

	while(m_NumCPUScavs[Team] > MIN_CPU_SCAVS_AFTER_CLEANUP)
	{
		// Find newest scav that isn't the one that just got created.
		i = m_NumCPUScavs[Team] - 1; // in C, arrays count from 0, so last valid element is at [count-1]
		while((i > 0) && (m_CPUScavList[Team][i] == scavHandle))
			--i;
		if(m_CPUScavList[Team][i] == scavHandle)
			break; // extra sanity check.

		// Don't generate a scrapfield the AI might try and
		// build more scavs to pick up and loop infinitely.
		SetNoScrapFlagByHandle(m_CPUScavList[Team][i]);
		SelfDamage(m_CPUScavList[Team][i], 1e28f);

		// Forget about this scav, shuffle array down.
		for(; i<m_NumCPUScavs[Team]; ++i)
			m_CPUScavList[Team][i] = m_CPUScavList[Team][i+1];
		--m_NumCPUScavs[Team];
		m_CPUScavList[Team][m_NumCPUScavs[Team]] = 0; // zap what used to be in last slot.
	}
}

// Note: *NEVER* remove this object from within the AddObject() call.
// It can cause crashes. If you must delete it, wait until the next
// Execute() or something.  NM 3/22/02
void instantMission::AddObject(Handle h)
{
	if(!StopScript)
		LuaMission::AddObject(h);

	// Always grab the ODF name out, if possible. Makes life much easier
	// in here.
	char ODFName[64];
	if(GetObjInfo(h, Get_CFG, ODFName))
	{
		// Local varb is now setup... 
	}
	else
	{
		// Failed to get anything. Uhoh. Clear this so our strcmps will be
		// guaranteed to fail.
		ODFName[0] = 0;
	}

	char ObjClass[64];
	GetObjInfo(h, Get_GOClass, ObjClass);

	int Team = GetTeamNum(h);

	bool IsCommBunker = (_stricmp(ObjClass, "CLASS_COMMBUNKER") == 0) || 
		(_stricmp(ObjClass, "CLASS_COMMTOWER") == 0);
	if(IsCommBunker && (Team == m_CompTeam))
		++m_CPUCommBunkerCount[Team];

	bool IsRecyVehicle = (_stricmp(ObjClass, "CLASS_RECYCLERVEHICLE") == 0) || (_stricmp(ObjClass, "CLASS_RECYCLERVEHICLEH") == 0) || (_stricmp(ObjClass, "CLASS_RECYCLER") == 0);
	if(IsRecyVehicle)
	{
		// If we're not tracking a m_Recycler vehicle for this team right
		// now, store it.
		if(!IsAround(m_Recycler[Team]))
			m_Recycler[Team] = h;
	}

	if(Team >= m_CompTeam) // on a computer team
	{
		// Scav cleanup code added NM 7/20/01.

		// Better way to identify scavs added NM 1/29/05 -- checks for
		// regular & hoverscavs, no matter what their ODF is named.
		if((_stricmp(ObjClass, "CLASS_SCAVENGER") == 0) || 
		   (_stricmp(ObjClass, "CLASS_SCAVENGERH") == 0))
		{
			AddCPUScav(h, Team);
		}

		SetSkill(h, m_Difficulty+1);
		AddToDispatch(h, 15.0f, false, 0, false); // Tie into DispatchHelper. -GBD
	}
	else if((m_MyGoal==0) && (Team == m_StratTeam))
	{
		// if it's artillery bomber/ go to late game tactics
		if((_stricmp(ObjClass, "CLASS_ARTILLERY") == 0) ||
			(_stricmp(ObjClass, "CLASS_BOMBER") == 0))
		{
			for(int CTeam = m_CompTeam; CTeam < MAX_TEAMS; CTeam++)
			{
				if((!m_SiegeOn[CTeam]) && (!m_LateGame[CTeam]))
				{
					m_LateGame[CTeam]=true;
					SetCPUAIPlan(AIPTypeL, CTeam);
				}
			}
		}

		if( (_stricmp(ObjClass, "CLASS_HOVER") == 0) || // Seems depreciated. -GBD
			(_stricmp(ObjClass, "CLASS_WINGMAN") == 0) || // Use CLASS_WINGMAN now. -GBD
			(_stricmp(ObjClass, "CLASS_MORPHTANK") == 0) ||
			(_stricmp(ObjClass, "CLASS_ASSAULTTANK") == 0) ||
			(_stricmp(ObjClass, "CLASS_SERVICE") == 0) ||
			(_stricmp(ObjClass, "CLASS_WALKER") == 0))
		{
			SetTeamNum(h, 1);
		}
	}

	if(Team == m_StratTeam)
	{
		SetSkill(h, 3-m_Difficulty);

		if(_stricmp(ObjClass, "CLASS_RECYCLER") == 0)
		{
			if(!m_PastAIP0)
			{
				m_PastAIP0 = true;
				/*
				SetAip here based on m_TurnCounter
				*/
				for(int CTeam = m_CompTeam; CTeam < MAX_TEAMS; CTeam++)
				{
					if(!IsAround(m_Recycler[CTeam]))
						continue;

					int stratchoice = m_TurnCounter%2;
					if(m_CPUTeamRace[CTeam] == kRACE_SCION) { // CPU is scion
						stratchoice = m_TurnCounter%2;
						switch (stratchoice)
						{
						default:
						case 0:
							SetCPUAIPlan(AIPType1, CTeam);
							break;
						case 1:
							SetCPUAIPlan(AIPType3, CTeam);
							break;
						case 2:
							SetCPUAIPlan(AIPType2, CTeam);
							break;
						}
					}
					else { // CPU is human
						switch (stratchoice % 2)
						{
						default:
						case 0:
							SetCPUAIPlan(AIPType1, CTeam);
							break;
						case 1:
							SetCPUAIPlan(AIPType3, CTeam);
							break;
						}
					}
				}
			} // not past AIP 0
		} else
		{
			if((_stricmp(ObjClass, "CLASS_ASSAULTTANK") == 0) ||
				(_stricmp(ObjClass, "CLASS_WALKER") == 0))
			{
				++m_AssaultCounter[Team];
			}
		} // not a recy
	}

	if((!m_PastAIP0) && (m_TurnCounter > (180 * m_GameTPS)))
	{
		m_PastAIP0 = true;
		for(int CTeam = m_CompTeam; CTeam < MAX_TEAMS; CTeam++)
		{
			if(!IsAround(m_Recycler[CTeam]))
				continue;

			int stratchoice = m_TurnCounter%2;
			switch (stratchoice % 2)
			{
			default:
			case 0:
				SetCPUAIPlan(AIPType1, CTeam);
				break;
			case 1:
				SetCPUAIPlan(AIPType3, CTeam);
				break;
			}
		}
	}
}

void instantMission::DeleteObject(Handle h)
{
	if(!StopScript)
		LuaMission::DeleteObject(h);

	char ObjClass[64];
	GetObjInfo(h, Get_GOClass, ObjClass);

	int Team = GetTeamNum(h);
	if(GetTeamNum(h)==m_StratTeam)
	{
		// unit exists. Check its type.
		if((_stricmp(ObjClass, "CLASS_ASSAULTTANK") == 0) ||
			(_stricmp(ObjClass, "CLASS_WALKER") == 0))
		{
			--m_AssaultCounter[Team];
			if(m_AssaultCounter[Team] < 0)
				m_AssaultCounter[Team] = 0;
		}
	}
	else
	{
		bool IsCommBunker = (_stricmp(ObjClass, "CLASS_COMMBUNKER") == 0) || 
			(_stricmp(ObjClass, "CLASS_COMMTOWER") == 0);
		if(IsCommBunker)
			--m_CPUCommBunkerCount[Team];

		// CPU team.
		if(_stricmp(ObjClass, "CLASS_ARMORY") == 0)
		{
			m_HaveArmory[Team]=false;
		}
	}
}

void instantMission::CreateObjectives()
{
	m_GoalVal=GetInstantGoal();
	switch (m_GoalVal)
	{
	case 0:  //ctf
		m_Obj1=BuildObject("apcamr", 0, "flag");
		if(m_Obj1!=NULL)
		{
			SetObjectiveOn(m_Obj1);
			SetObjectiveName(m_Obj1, "Capture Target");
			ClearObjectives();
			AddObjective("inst0101.otf", WHITE, 8.0f);
		}
		break;
	case 1: // attack
		m_Obj1=BuildObject("mbruin01", m_CompTeam, "objective1");
		if(m_Obj1!=NULL)
		{
			SetObjectiveOn(m_Obj1);
			SetObjectiveName(m_Obj1, "Destroy Target");  // later this could be health/ ammo
			ClearObjectives();
			AddObjective("inst0102.otf", WHITE, 8.0f);
			// we need to know if the goal is 
			// protect-destory
		}
		else (m_Obj1=(-1));  // it never existed

		break;
	case 2: // defend
		m_Obj1=BuildObject("mbruin01", 1, "objective2");
		if(m_Obj1!=NULL)
		{
			SetObjectiveOn(m_Obj1);
			SetObjectiveName(m_Obj1, "Protect Target");
			ClearObjectives();
			AddObjective("inst0103.otf", WHITE, 8.0f);
		}
		break;
	}
	/*
	Again, if this is a strategy instant action..
	some variables should be passed
	*/
}

// Win when the human alliance is the last one standing; lose when it's gone. -GBD
void instantMission::TestObjectives()
{
	if(m_EndCounter!=0)
		return;

	int NumFunctioningTeams=0;
	bool AlliesFunctioning[MAX_TEAMS];
	memset(AlliesFunctioning, 0, sizeof(AlliesFunctioning));

	for(int Team = 1; Team < MAX_TEAMS; Team++)
	{
		if(m_Recycler[Team] == 0) // Never had one.
			continue;

		bool Functioning = false;

		// Fix for mantis #335 - track if recycler was upgraded or
		// otherwise changed handle.
		Handle TempH = m_Recycler[Team];
		if(!IsAround(TempH))
			TempH = GetObjectByTeamSlot(Team, DLL_TEAM_SLOT_RECYCLER);

		Handle RecyH = 0;
		if(IsAround(TempH) || (TempH != 0))
			RecyH = TempH;
		else
			RecyH = GetObjectByTeamSlot(Team, DLL_TEAM_SLOT_RECYCLER);

		if(RecyH)
			Functioning = true;
		else
			m_Recycler[Team] = 0; // Clear this out for later

		AlliesFunctioning[m_AllyTeams[Team]] = AlliesFunctioning[m_AllyTeams[Team]] || Functioning;
	}

	for(int i = 1; i < MAX_TEAMS; i++)
	{
		if(AlliesFunctioning[i])
			NumFunctioningTeams++;
	}

	if(NumFunctioningTeams == 0)
	{
		if(m_ElapsedGameTime > (5 * m_GameTPS))
		{
			DoTaunt(TAUNTS_HumanRecyDestroyed);
			FailMission(GetTime()+5.0f, "instantl.txt");
			m_EndCounter++;
		}
	}
	else if(NumFunctioningTeams == 1)
	{
		for(int i = 0; i < MAX_TEAMS; i++)
		{
			if(AlliesFunctioning[m_AllyTeams[i]])
			{
				if(i == m_StratTeam)
				{
					DoTaunt(TAUNTS_CPURecyDestroyed);
					SucceedMission(GetTime()+5.0f, "instantw.txt");
				}
				else
				{
					DoTaunt(TAUNTS_HumanRecyDestroyed);
					FailMission(GetTime()+5.0f, "instantl.txt");
				}
				m_EndCounter++;
				break;
			}
		}
	}
}

void instantMission::Execute(void)
{
	if(!StopScript)
		LuaMission::Execute();

	m_ElapsedGameTime++;
	m_Player=GetPlayerHandle();
	m_TurnCounter++;
	DoGenericStrategy();
}

bool instantMission::Load(bool missionSave)
{
	bool ret = LuaMission::Load(missionSave);

	// Always do this to hook up clients with the taunt engine as well.
	InitTaunts(&m_ElapsedGameTime, &m_LastTauntPrintedAt, &m_GameTPS, "Computer Team");

	if(missionSave)
	{
		int i;

		// init bools
		if((b_array) && (b_count))
			for (i = 0; i < b_count; i++)
				b_array[i] = false;

		// init floats
		if((f_array) && (f_count))
			for (i = 0; i < f_count; i++)
				f_array[i] = 0.0f;

		// init handles
		if((h_array) && (h_count))
			for (i = 0; i < h_count; i++)
				h_array[i] = 0;

		// init ints
		if((i_array) && (i_count))
			for (i = 0; i < i_count; i++)
				i_array[i] = 0;

		Setup();
		return true;
	}

	// bools
	if(b_array != NULL)
		ret=ret && Read(b_array, b_count);

	// floats
	if(f_array != NULL)
		ret=ret && Read(f_array, f_count);

	// Handles
	if(h_array != NULL)
		ret=ret && Read(h_array, h_count);

	// ints
	if(i_array != NULL)
		ret=ret && Read(i_array, i_count);

	return ret;
}

bool instantMission::Save(bool missionSave)
{
	bool ret = LuaMission::Save(missionSave);

	// Always do this to hook up clients with the taunt engine as well.
	InitTaunts(&m_ElapsedGameTime, &m_LastTauntPrintedAt, &m_GameTPS, "Computer Team");

	if(missionSave)
		return true;

	// bools
	if(b_array != NULL)
		ret=ret && Write(b_array, b_count);

	// floats
	if(f_array != NULL)
		ret=ret && Write(f_array, f_count);

	// Handles
	if(h_array != NULL)
		ret=ret && Write(h_array, h_count);

	// ints
	if(i_array != NULL)
		ret=ret && Write(i_array, i_count);

	return ret;
}

bool instantMission::PostLoad(bool missionSave)
{
	LuaMission::PostLoad(missionSave);

	if(missionSave)
		return true;

	if(h_array != NULL)
		ConvertHandles(h_array, h_count);

	return true;
}

void instantMission::DoGenericStrategy()
{
	m_TimeCount++;

	if(!m_StartDone)
	{
		m_StartDone=true;

		m_MyGoal=GetInstantGoal();

		// Style notes: we copy out all the options.instant.* varbs we
		// want into class member variables the first chance we get. If
		// the user exits to windows, and reloads a savegame, only these
		// class member variables will be reloaded. The options.* will be
		// lost.

		// true if the user can respawn if died (kill/snipe)
		m_CanRespawn = IFace_GetInteger("options.instant.bool0") != 0;

		// Clear this on entry. It might be filled in below.
		memset(m_CustomAIPStr, 0, sizeof(m_CustomAIPStr));

		m_AwareV13 = IFace_GetInteger("options.instant.awarev13");
		if(m_AwareV13)
		{
			// Using custom AIPs? Read from string.
			IFace_GetString("options.instant.string0", m_CustomAIPStr, m_CustomAIPStrLen);

			// CPU races and the alliance numbers for every CPU team. -GBD
			char VarName[64];
			for(int Team = m_CompTeam; Team < MAX_TEAMS; Team++)
			{
				if(Team == m_CompTeam)
				{
					m_CPUTeamRace[Team] = IFace_GetInteger("options.instant.hisrace");
				}
				else
				{
					sprintf_s(VarName, "options.instant.int%d", Team);
					m_CPUTeamRace[Team] = IFace_GetInteger(VarName);
				}

				m_AllyTeams[1] = IFace_GetInteger("options.instant.int16");
				if(m_AllyTeams[1] < 1)
					m_AllyTeams[1] = 1;

				memset(VarName, 0, sizeof(VarName));
				for(int i = 6; i < MAX_TEAMS; i++)
				{
					sprintf_s(VarName, "options.instant.int%d", 11 + i);
					m_AllyTeams[i] = IFace_GetInteger(VarName);
					if(m_AllyTeams[i] < 1)
						m_AllyTeams[i] = i - 4;
				}
			}

			m_HumanTeamRace = IFace_GetInteger("options.instant.myrace");

			// Loop over all teams and ally
			for(int x = 1; x < MAX_TEAMS; x++)
			{
				for(int y = 1; y < MAX_TEAMS; y++)
				{
					if((m_AllyTeams[x] > 0) && (x != y) && (m_AllyTeams[x] == m_AllyTeams[y]))
					{
						Ally(x, y);
						m_HasAllies[x] = true;
					}
				}
			}

			// Override whatever craft the BZN had for the m_Player, make them
			// a scout of the correct race.
			Handle PlayerH = GetPlayerHandle();
			int PlayerTeam = GetTeamNum(PlayerH);
			Vector PlayerPos;
			GetPosition(PlayerH, PlayerPos);

			char NewPlayerODF[64];
			sprintf_s(NewPlayerODF, "%cvscout_vsr", m_HumanTeamRace);
			if(!DoesODFExist(NewPlayerODF))
				sprintf_s(NewPlayerODF, "%cvscout", m_HumanTeamRace);

			char OldODFName[64];
			if(GetObjInfo(PlayerH, Get_CFG, OldODFName))
			{
				// Got their cfg. Check if it's a pilot, and change to that if
				// the BZN wanted them to start as that.
				if(OldODFName[1] == 's')
					sprintf_s(NewPlayerODF, "%cspilo", m_HumanTeamRace);
			}

			// Remove old object
			RemoveObject(PlayerH);
			// Build new object
			Handle NewPlayerH = BuildObject(NewPlayerODF, PlayerTeam, PlayerPos);

			SetAsUser(NewPlayerH, PlayerTeam);
		}
		else
		{
			// Old way of determining sides
			int mySide=GetInstantMySide();
			if(mySide == 1) { // CPU Scion, Human ISDF
				m_CPUTeamRace[m_CompTeam] = kRACE_SCION;
				m_HumanTeamRace = kRACE_ISDF;
			}
			else
			{
				m_CPUTeamRace[m_CompTeam] = kRACE_ISDF;
				m_HumanTeamRace = kRACE_SCION;
			}
		}

		m_MyForce=GetInstantMyForce();
		m_CompForce=GetInstantCompForce();
		m_Difficulty=GetInstantDifficulty();

		if(m_MyGoal==0)
		{
			m_StratTeam=3;
			Ally(3, 1);
			Ally(1, 3);

			Handle atk = 0;
			if(m_CPUTeamRace[m_CompTeam] == kRACE_SCION)
			{
				atk=BuildObject("fvsent", m_CompTeam, "tankEnemy1");
			}
			else
				atk=BuildObject("ivmisl", m_CompTeam, "tankEnemy1");

			Attack(atk, m_Player);  // spice up the start

			// add power ups here.. or have a function for it.  
		}
		else 
		{
			m_StratTeam=1;
		}

		SetupExtraVehicles();

		// Build initial items for the CPU teams based on selections. The first
		// ODF listed is preferred, the second one really should be there
		// as a fallback

		// Note: contents of options.instant.string# not copied to member
		// varbs, as recommended above. Why not? It's only used in
		// creating an object, and then that object will save enough data
		// to reload successfully later.
		for(int Team = m_CompTeam; Team < MAX_TEAMS; Team++)
		{
			if(m_CPUTeamRace[Team] == 0)
				continue;

			// Spawn on the "Enemy_#" path, else the old "RecyclerEnemy" path (first CPU only). -GBD
			char SpawnPath[64];
			sprintf_s(SpawnPath, "Enemy_%d", Team);
			size_t bufSize = 0;
			GetPathPoints(SpawnPath, bufSize, NULL);
			if(bufSize == 0)
			{
				if(Team > m_CompTeam)
					break;
				sprintf_s(SpawnPath, "RecyclerEnemy");
			}

			char CustomCPURecy[64];
			IFace_GetString("options.instant.string2", CustomCPURecy, sizeof(CustomCPURecy));
			if(!DoesODFExist(CustomCPURecy))
				sprintf_s(CustomCPURecy, "*vrecycpu");
			if(CustomCPURecy[0]) 
				m_Recycler[Team]=BuildStartingVehicle(Team, m_CPUTeamRace[Team], CustomCPURecy, "*vrecy", SpawnPath);
			else
				m_Recycler[Team]=BuildStartingVehicle(Team, m_CPUTeamRace[Team], "*vrecycpu", "*vrecy", SpawnPath);

			char AITeamName[64] = {0};
			sprintf_s(AITeamName, "Computer Team %d", Team);
			SetTeamNameForStat(Team, GetBZCCLocalizedString("cfg", AITeamName));

			// Look for the recycler's starting variant, else look for an _ in
			// there, and copy everything after it into the RecyVariant tag. -GBD
			char TempODF[64] = {0};
			char TempODF2[64] = {0};
			char VariantName[64] = {0};
			CombineStrings(TempODF, CustomCPURecy, ".odf"); // Add .odf to the end.
			if(OpenODF2(TempODF))
			{
				if(GetODFString(TempODF, "GameObjectClass", "classlabel", 64, TempODF2)) // Grab the classlabel, if present.
				{
					CombineStrings(TempODF2, TempODF2, ".odf"); // Add .odf to the end.
					OpenODF2(TempODF2);
				}
				if(!GetODFString(TempODF, TempODF2, "GameObjectClass", "startingVariant", 64, VariantName))
				{
					const char *pUnderscore = strchr(CustomCPURecy, '_');
					if(pUnderscore)
					{
						pUnderscore++;
						const char *pUnderscore2 = strchr(pUnderscore, '_');
						if(pUnderscore2) // 2 underscores, take what's after the second.
							pUnderscore = pUnderscore2 + 1;
						strcpy_s(VariantName, pUnderscore);
					}
				}
			}

			Vector RecPos;
			GetPosition(m_Recycler[Team], RecPos);

			BuildStartingVehicle(Team, m_CPUTeamRace[Team], "*vscav", "*vscav", GetPositionNear(RecPos, 30.0f, 60.0f), -1, VariantName);
			BuildStartingVehicle(Team, m_CPUTeamRace[Team], "*vturr", "*vturr", GetPositionNear(RecPos, 30.0f, 60.0f), -1, VariantName);
			BuildStartingVehicle(Team, m_CPUTeamRace[Team], "*vturr", "*vturr", GetPositionNear(RecPos, 30.0f, 60.0f), -1, VariantName);

			if(m_CompForce>0)
			{
				if(Team == m_CompTeam)
				{
					BuildStartingVehicle(Team, m_CPUTeamRace[Team], "*bspir", "*vturr", "gtow2", -1, VariantName);
					BuildStartingVehicle(Team, m_CPUTeamRace[Team], "*bspir", "*vturr", "gtow3", -1, VariantName);
				}
				BuildStartingVehicle(Team, m_CPUTeamRace[Team], "*vsent", "*vscout", GetPositionNear(RecPos, 30.0f, 60.0f), -1, VariantName);
				BuildStartingVehicle(Team, m_CPUTeamRace[Team], "*vsent", "*vscout", GetPositionNear(RecPos, 30.0f, 60.0f), -1, VariantName);
			}
			if(m_CompForce>1)
			{
				if(Team == m_CompTeam)
				{
					BuildStartingVehicle(Team, m_CPUTeamRace[Team], "*bspir", "*vturr", "gtow4", -1, VariantName);
					BuildStartingVehicle(Team, m_CPUTeamRace[Team], "*bspir", "*vturr", "gtow5", -1, VariantName);
				}
				BuildStartingVehicle(Team, m_CPUTeamRace[Team], "*vtank", "*vtank", GetPositionNear(RecPos, 30.0f, 60.0f), -1, VariantName);
				BuildStartingVehicle(Team, m_CPUTeamRace[Team], "*vtank", "*vtank", GetPositionNear(RecPos, 30.0f, 60.0f), -1, VariantName);
				BuildStartingVehicle(Team, m_CPUTeamRace[Team], "*vtank", "*vtank", GetPositionNear(RecPos, 30.0f, 60.0f), -1, VariantName);
				BuildStartingVehicle(Team, m_CPUTeamRace[Team], "*vtank", "*vtank", GetPositionNear(RecPos, 30.0f, 60.0f), -1, VariantName);
				BuildStartingVehicle(Team, m_CPUTeamRace[Team], "*vsent", "*vscout", GetPositionNear(RecPos, 30.0f, 60.0f), -1, VariantName);
			}
		}

		// --------------------------------------------------------
		// Build initial items for Human team based on selections

		// Spawn on the "Player_1" path, else the old "Recycler" path. -GBD
		char SpawnPath[64];
		sprintf_s(SpawnPath, "Player_1");
		size_t bufSize = 0;
		GetPathPoints(SpawnPath, bufSize, NULL);
		if(bufSize == 0)
			sprintf_s(SpawnPath, "Recycler");

		int grp=-2; // SetBestGroup.

		// Note: contents of options.instant.string# not copied to member
		// varbs, as recommended above. Why not? It's only used in
		// creating an object, and then that object will save enough data
		// to reload successfully later.

		// If there is a custom human m_Recycler, use that.
		char CustomHumanRecy[64];
		IFace_GetString("options.instant.string1", CustomHumanRecy, sizeof(CustomHumanRecy));
		if(CustomHumanRecy[0]) 
			m_Recycler[m_StratTeam]=BuildStartingVehicle(m_StratTeam, m_HumanTeamRace, CustomHumanRecy, "*vrecy", SpawnPath, grp);
		else
			m_Recycler[m_StratTeam]=BuildStartingVehicle(m_StratTeam, m_HumanTeamRace, "*vrecy", "*vrecy", SpawnPath, grp);

		// Look for the recycler's starting variant, else look for an _ in
		// there, and copy everything after it into the RecyVariant tag. -GBD
		char TempODF[64] = {0};
		char TempODF2[64] = {0};
		char VariantName[64] = {0};
		CombineStrings(TempODF, CustomHumanRecy, ".odf"); // Add .odf to the end.
		if(OpenODF2(TempODF))
		{
			if(GetODFString(TempODF, "GameObjectClass", "classlabel", 64, TempODF2)) // Grab the classlabel, if present.
			{
				CombineStrings(TempODF2, TempODF2, ".odf"); // Add .odf to the end.
				OpenODF2(TempODF2);
			}
			if(!GetODFString(TempODF, TempODF2, "GameObjectClass", "startingVariant", 64, VariantName))
			{
				const char *pUnderscore = strchr(CustomHumanRecy, '_');
				if(pUnderscore)
				{
					pUnderscore++;
					const char *pUnderscore2 = strchr(pUnderscore, '_');
					if(pUnderscore2) // 2 underscores, take what's after the second.
						pUnderscore = pUnderscore2 + 1;
					strcpy_s(VariantName, pUnderscore);
				}
			}
		}

		Vector RecPos;
		GetPosition(m_Recycler[m_StratTeam], RecPos);
		SetVectorPosition(GetPlayerHandle(), GetPositionNear(RecPos, 30.0f, 60.0f));

		BuildStartingVehicle(m_StratTeam, m_HumanTeamRace, "*vscav", "*vscav", GetPositionNear(RecPos, 30.0f, 60.0f), grp, VariantName);
		BuildStartingVehicle(m_StratTeam, m_HumanTeamRace, "*vturr", "*vturr", GetPositionNear(RecPos, 30.0f, 60.0f), grp, VariantName);
		BuildStartingVehicle(m_StratTeam, m_HumanTeamRace, "*vturr", "*vturr", GetPositionNear(RecPos, 30.0f, 60.0f), grp, VariantName);

		if(m_MyForce>0)
		{
			BuildStartingVehicle(m_StratTeam, m_HumanTeamRace, "*vturr", "*vturr", GetPositionNear(RecPos, 30.0f, 60.0f), grp, VariantName);
			BuildStartingVehicle(m_StratTeam, m_HumanTeamRace, "*vscout", "*vscout", GetPositionNear(RecPos, 30.0f, 60.0f), grp, VariantName);
			BuildStartingVehicle(m_StratTeam, m_HumanTeamRace, "*vscout", "*vscout", GetPositionNear(RecPos, 30.0f, 60.0f), grp, VariantName);
			BuildStartingVehicle(m_StratTeam, m_HumanTeamRace, "*vtank", "*vtank", GetPositionNear(RecPos, 30.0f, 60.0f), grp, VariantName);
			BuildStartingVehicle(m_StratTeam, m_HumanTeamRace, "*vtank", "*vtank", GetPositionNear(RecPos, 30.0f, 60.0f), grp, VariantName);
		}
		if(m_MyForce>1)
		{
			BuildStartingVehicle(m_StratTeam, m_HumanTeamRace, "*vscout", "*vscout", GetPositionNear(RecPos, 30.0f, 60.0f), grp, VariantName);
			BuildStartingVehicle(m_StratTeam, m_HumanTeamRace, "*vtank", "*vtank", GetPositionNear(RecPos, 30.0f, 60.0f), grp, VariantName);

			grp=GetFirstEmptyGroup();
			BuildStartingVehicle(m_StratTeam, m_HumanTeamRace, "*vtank", "*vtank", GetPositionNear(RecPos, 30.0f, 60.0f), grp, VariantName);
			BuildStartingVehicle(m_StratTeam, m_HumanTeamRace, "*vtank", "*vtank", GetPositionNear(RecPos, 30.0f, 60.0f), grp, VariantName);
			BuildStartingVehicle(m_StratTeam, m_HumanTeamRace, "*vtank", "*vtank", GetPositionNear(RecPos, 30.0f, 60.0f), grp, VariantName);
		}

		// Only old-style maps w/ opposite races can do thug mode
		if(!m_AwareV13)
		{
			if(m_MyGoal==0)
			{
				// check my team..
				if(m_HumanTeamRace == kRACE_ISDF)
				{
					SetPlan("isdfteam.aip", m_StratTeam);
				}
				else
				{
					SetPlan("scionteam.aip", m_StratTeam);
				}	
			}
		} // Not aware of 1.3

		// If we jumped to AIP 1/3 because there's a preplaced human
		// recy on the map, then don't go back to AIP 0
		if(!m_PastAIP0)
		{
			for(int Team = m_CompTeam; Team < MAX_TEAMS; Team++)
			{
				if(IsAround(m_Recycler[Team]))
					SetCPUAIPlan(AIPType0, Team);
			}
		}

		// power ups?
		BuildObject("apammo", 0, "ammo1");
		BuildObject("apammo", 0, "ammo2");
		BuildObject("apammo", 0, "ammo3");
		BuildObject("aprepa", 0, "repair1");
		BuildObject("aprepa", 0, "repair2");
		BuildObject("aprepa", 0, "repair3");
		// objectives .. later make this optional	
		//		CreateObjectives();
		SetScrap(m_CompTeam, 40);
		SetScrap(1, 40);
	}

	// Scrap cheats, like Strategy's. -GBD
	if(m_CompForce)
	{
		int Turns = 0, Amount = 0;
		if(m_CompForce == 0) { Turns = m_GameTPS * 3; Amount = 1; }
		else if(m_CompForce == 1) { Turns = m_GameTPS * 2; Amount = 1; }
		else if(m_CompForce == 2) { Turns = m_GameTPS * 1; Amount = 1; }

		if((Turns > 0) && ((m_TimeCount % Turns) == 0))
		{
			// (As shipped: every CPU team's share goes to m_CompTeam.)
			for(int Team = m_CompTeam; Team < MAX_TEAMS; Team++)
				AddScrap(m_CompTeam, Amount);
		}
	}
	if(m_MyForce)
	{
		int Turns = 0, Amount = 0;
		if(m_MyForce == 0) { Turns = m_GameTPS * 10; Amount = 1; }
		else if(m_MyForce == 1) { Turns = m_GameTPS * 8; Amount = 1; }
		else if(m_MyForce == 2) { Turns = m_GameTPS * 6; Amount = 1; }

		if((Turns > 0) && ((m_TimeCount % Turns) == 0))
			AddScrap(m_StratTeam, Amount);
	}

	if(m_TimeCount%m_FriendReinforcementTime==0)
	{
		// power ups?
		BuildObject("apammo", 0, "ammo1");
		BuildObject("apammo", 0, "ammo2");
		BuildObject("apammo", 0, "ammo3");
		BuildObject("aprepa", 0, "repair1");
		BuildObject("aprepa", 0, "repair2");
		BuildObject("aprepa", 0, "repair3");
	}

	if(m_MyGoal==0)
	{
		m_PowerupCounter++;
		if((m_PowerupCounter % (20 * m_GameTPS))==0)
		{
			if(!IsAround(m_Powerup1))
			{
				m_Powerup1=BuildObject("apshdw", 0, "power1");
			}
			if(!IsAround(m_Powerup2))
			{
				m_Powerup2=BuildObject("apsstb", 0, "power2");
			}
			if(!IsAround(m_Powerup3))
			{
				m_Powerup3=BuildObject("apffld", 0, "power3");
			}
			if(!IsAround(m_Powerup4))
			{
				m_Powerup4=BuildObject("apspln", 0, "power4");
			}
		}
	}

	// AIP switch logic, per CPU team. -GBD
	for(int Team = m_CompTeam; Team < MAX_TEAMS; Team++)
	{
		if(!IsAround(m_Recycler[Team]))
			continue;

		if(!m_SiegeOn[Team])
		{
			// Ignore scavs, pilots, and any craft > kfSIEGE_DISTANCE away.
			Handle enemy = GetNearestEnemy(m_Recycler[Team], true, true, kfSIEGE_DISTANCE);
			if(enemy) 
			{
				// under siege
				m_SiegeCounter[Team]++;
			}
			else
			{
				m_SiegeCounter[Team]=0;
			}

			if(m_SiegeCounter[Team] > (45 * m_GameTPS))
			{
				m_SiegeOn[Team] = true;
				SetCPUAIPlan(AIPTypeS, Team);
			}
		}  // !m_SiegeOn
		else
		{
			// Ignore scavs, pilots, and any craft > kfSIEGE_DISTANCE away.
			Handle enemy = GetNearestEnemy(m_Recycler[Team], true, true, kfSIEGE_DISTANCE);
			if(enemy == 0)
			{
				// no longer under siege
				SetCPUAIPlan(AIPTypeL, Team);
				// Move out only when it succeeds.
				if(m_LastCPUPlan[Team] == AIPTypeL)
				{
					m_SiegeOn[Team] = false;
					m_SiegeCounter[Team] = 0;
				}
			}
		}  // m_SiegeOn

		// assault_test
		if((!m_LateGame[Team]) && (!m_SiegeOn[Team]) && (!m_AntiAssault[Team]) && (m_AssaultCounter[m_StratTeam]>2))
		{
			m_AntiAssault[Team]=true;
			SetCPUAIPlan(AIPTypeA, Team);
		}
		else
		{
			if((m_AntiAssault[Team]) && (m_AssaultCounter[m_StratTeam]<3))
			{
				m_AntiAssault[Team]=false;
				SetCPUAIPlan(AIPTypeL, Team);
			}
		}
	}

	TestObjectives();
}

EjectKillRetCodes instantMission::PlayerEjected(Handle DeadObjectHandle)
{
	if(!StopScript)
		LuaMission::PlayerEjected(DeadObjectHandle);

	// The ODF's eject ratio decides. -GBD
	const float Roll = GetRandomFloat(1.0f);
	const float EjectRatio = GetEjectRatio(DeadObjectHandle);
	if(EjectRatio < Roll)
		return DLLHandled;

	return DoEjectPilot;
}

// Local user died. Do (optional) respawn or fail mission
EjectKillRetCodes instantMission::PlayerDied(int DeadObjectHandle, bool bSniped)
{

	// Player (local or remote human) is dead
	if(!IsPerson(DeadObjectHandle))
	{
		// Craft died. If it wasn't a snipe, then just kick the pilot out
		if(!bSniped)
			return DoEjectPilot;
	}

	// Local m_Player got killed (pilot or snipe). Do respawn as needed

	if(m_CanRespawn && IsAlive(m_Recycler[m_StratTeam]))
	{
		// Respawn them near their m_Recycler, up in the air.
		Vector Where;
		GetPosition(m_Recycler[m_StratTeam], Where);

		Where=GetPositionNear(Where, 10.0f, 50.0f);
		Where.y += 50.0f;

		char PlayerODF[64];
		sprintf_s(PlayerODF, "%cspilo", m_HumanTeamRace);
		Handle PlayerH=BuildObject(PlayerODF, 1, Where);
		SetAsUser(PlayerH, 1);
		AddPilotByHandle(PlayerH);

		DoTaunt(TAUNTS_HumanShipDestroyed);
	}
	else
	{
		// User can't respawn. Game over, man
		FailMission(GetTime() + 3.0f);
	}

	// Both cases of the above report that we handled things
	return DLLHandled;
}

EjectKillRetCodes instantMission::ObjectKilled(int DeadObjectHandle, int KillersHandle)
{
	if(!StopScript)
		LuaMission::ObjectKilled(DeadObjectHandle, KillersHandle);

	if(!IsPlayer(DeadObjectHandle)) { // J.Random AI-controlled Object is toast
		// Should we eject a pilot instead?
		bool bWasDeadPilot = IsPerson(DeadObjectHandle);

		if(!bWasDeadPilot)
			return DoEjectPilot;
		else
			return DLLHandled;
	}
	else
	{
		return PlayerDied(DeadObjectHandle, false);
	}
}

EjectKillRetCodes instantMission::ObjectSniped(int DeadObjectHandle, int KillersHandle)
{
	if(!StopScript)
		LuaMission::ObjectSniped(DeadObjectHandle, KillersHandle);

	if(!IsPlayer(DeadObjectHandle))
	{
		// J.Random AI-controlled Object is toast
		return DLLHandled;
	}
	else
	{
		return PlayerDied(DeadObjectHandle, true);
	} // Player dead
}

// Notification to the DLL: called when a pilot tries to enter an
// empty craft. A CPU ship that gets a pilot joins the dispatcher. -GBD
PreGetInReturnCodes instantMission::PreGetIn(const int curWorld, Handle pilotHandle, Handle emptyCraftHandle)
{
	if(curWorld != 0)
		return PREGETIN_ALLOW;

	PreGetInReturnCodes returnvalue = LuaMission::PreGetIn(curWorld, pilotHandle, emptyCraftHandle);

	if((returnvalue == PREGETIN_ALLOW) && (GetTeamNum(emptyCraftHandle) >= m_CompTeam))
		AddToDispatch(emptyCraftHandle, 15.0f, false, 0, false);

	return returnvalue;
}

DLLBase * BuildMission(void)
{
	return new instantMission();
}
