// PROVENANCE: ancestor reference/ancestor-bz1helper-2015/Shared/Taunts.cpp @6fda4f5 + decompile strategy02-ghidra12.2 taunts.cpp:9-220 (InitTaunts @4fc090da, DoTaunt @4fc093ff, CleanupTaunts @4fc09550; SetTauntCPUName inlined into LuaBindings::SetTauntCPUName @4fc4b28d; %.*s precision from the disassembly at 4fc094ca-4fc094e6; initial values from the .data image; the pCPUTeamName branch of InitTaunts from the Instant build, instant-ghidra12.2 taunts.cpp:35-128, where it is not folded) | status: ported
#include "submission.h"
#include "taunts.h"
#include <string.h>
#include <stdlib.h>
#include <vector>

// Ain't data-driven code a great way to go? In VSR the taunt tables moved out of the DLL:
// the .trn names an ODF (default "Taunts") whose [TauntCategories] lists up to 16 category
// names, and each "<base><category>.otf" holds one taunt per line. "_rand" marks the
// category used for the 5% random taunt.

std::vector<char*> TauntList[16];       // one line-pointer list per category (into TauntBuffer[i])
char* TauntBuffer[16];                  // the loaded .otf files (malloc'd, NUL-terminated)
char TauntHeaders[64][16];              // category names, 16-char rows (only the first 16 rows are ever filled)
int TauntHeaderCount;                   // categories found in the .odf
int TauntRandomHeader;                  // index of the "_rand" category (0 if none)
int LastTauntPrinted[16] = { -1 };

static int *g_pElapsedTime = NULL;
static int *g_pLastTauntPrintedAt = NULL;
static int *g_pTPS = NULL;

static bool DeterminedCPUTeamName = false;
static bool ReadTaunts = false;
static char CPUTeamName[256] = "Team Computer";
static char TempBuffer[512];


// Required setup call before you call DoTaunt(). pGameTime is used to squelch too-often messages. [It should be the # of calls to
// Execute]. pLastMessagePrintedAt is a scratchpad variable used to note things, should be saved. pTPS should be a pointer to the TPS
// in use. pCPUTeamName, if given, names the CPU team for the taunts (Instant passes "Computer Team"; Strategy / Deathmatch pass
// nothing and the name comes from svar2 or SetTauntCPUName()). The Strategy02 build folded the NULL and dropped this branch;
// the Instant build (instant-ghidra12.2 taunts.cpp:35-128) keeps it.
void InitTaunts(int* pGameTime, int* pLastMessagePrintedAt, int* pTPS, const char* pCPUTeamName)
{
	g_pElapsedTime = pGameTime;
	g_pLastTauntPrintedAt = pLastMessagePrintedAt;
	g_pTPS = pTPS;

	// Clear last printed to ensure everyone sees the same.
	for(int i = 0; i < 16; i++)
		LastTauntPrinted[i] = -1; // won't ever match

	if(pCPUTeamName)
	{
		strcpy_s(CPUTeamName, pCPUTeamName);
		DeterminedCPUTeamName = true;
	}

	if(!ReadTaunts)
	{
		char TRNFile[128];
		strcpy_s(TRNFile, GetMapTRNFilename());
		if(OpenODF(TRNFile))
		{
			// Which ODF names the categories? .trn [DLL] TauntODFFile, default "Taunts".
			char TauntODFBase[64];
			memset(TauntODFBase, 0, sizeof(TauntODFBase));
			GetODFString(TRNFile, "DLL", "TauntODFFile", sizeof(TauntODFBase), TauntODFBase, "Taunts");

			char TauntODF[64];
			memset(TauntODF, 0, sizeof(TauntODF));
			strncpy_s(TauntODF, sizeof(TauntODF), TauntODFBase, sizeof(TauntODF));
			strncat_s(TauntODF, sizeof(TauntODF), ".odf", sizeof(TauntODF) - 1 - strlen(TauntODF));

			if(OpenODF(TauntODF))
			{
				char TempStr[64];
				for(int i = 0; i < 16; i++)
				{
					memset(TempStr, 0, sizeof(TempStr));
					sprintf_s(TempStr, "Category%d", i);
					if(!GetODFString(TauntODF, "TauntCategories", TempStr, 64, TauntHeaders[i], NULL))
						break;
					TauntHeaderCount++;
					if(strncmp(TauntHeaders[i], "_rand", 5) == 0)
						TauntRandomHeader = i;
				}
				CloseODF(TauntODF);
			}

			// Load each category's .otf and split it into lines.
			for(int i = 0; i < TauntHeaderCount; i++)
			{
				char TauntFile[64];
				memset(TauntFile, 0, sizeof(TauntFile));
				strncpy_s(TauntFile, sizeof(TauntFile), TauntODFBase, sizeof(TauntFile));
				strncat_s(TauntFile, sizeof(TauntFile), TauntHeaders[i], sizeof(TauntFile) - 1 - strlen(TauntFile));
				strncat_s(TauntFile, sizeof(TauntFile), ".otf", sizeof(TauntFile) - 1 - strlen(TauntFile));

				TauntBuffer[i] = NULL;
				size_t BufSize = 0;
				LoadFile(TauntFile, NULL, BufSize);
				TauntBuffer[i] = (char*)malloc(BufSize + 1);
				LoadFile(TauntFile, TauntBuffer[i], BufSize);
				TauntBuffer[i][BufSize] = 0;

				char* pBuffer = TauntBuffer[i];
				char* pEnd = pBuffer + BufSize;
				if((pBuffer != NULL) && (pBuffer < pEnd))
				{
					char* pLine = pBuffer;
					for(char* p = pBuffer; p < pEnd; p++)
					{
						if((*p == '\r') || (*p == '\n') || (*p == 0))
						{
							*p = 0;
							if(pLine < p)
								TauntList[i].push_back(pLine);
							pLine = p + 1;
						}
					}
					if(pLine < pEnd)
						TauntList[i].push_back(pLine);
				}
			}
		}
		CloseODF(TRNFile);
		ReadTaunts = true;
	}
}

// Note: this function does all of the work of building up a taunt, and decides what to do with it only at the last step. This is by
// design-- it keeps taunt messages more in sync across network games, even if the local setting is to not display them.
void DoTaunt(int Taunt)
{
	if(Taunt >= TauntHeaderCount)
		return;

	// 5% chance of showing a random taunt instead...
	if(GetRandomFloat(20) < 1.0f)
		Taunt = TauntRandomHeader;

	// Make sure we get the CPU's team name from game at least once.
	if(!DeterminedCPUTeamName)
	{
		const char *TempName = GetVarItemStr("network.session.svar2");
		if(TempName != NULL)
			strcpy_s(CPUTeamName, TempName);
		DeterminedCPUTeamName = true;
	}

	int Which = 0;
	int TauntsInCategory = int(TauntList[Taunt].size());
	if(TauntsInCategory <= 0)
		return;

	if(TauntsInCategory > 1)
	{
		// Pick one, making sure we don't print the same thing twice in a row.
		Which = int(GetRandomFloat(float(TauntsInCategory)));
		if(Which < 0)
			Which = 0;
		else if(Which > TauntsInCategory - 1)
			Which = TauntsInCategory - 1;
		if(Which == LastTauntPrinted[Taunt])
			Which++;
		if(Which >= TauntsInCategory)
			Which = 0;
	}
	LastTauntPrinted[Taunt] = Which;

	// Fit the taunt into TempBuffer after the (at most 255-char) name, " : " and "\n".
	int MaxTauntLen = int(sizeof(TempBuffer) - 5 - strlen(CPUTeamName));
	if(MaxTauntLen < int(sizeof(TempBuffer) - 5 - 255))
		MaxTauntLen = int(sizeof(TempBuffer) - 5 - 255);
	sprintf_s(TempBuffer, "%.255s : %.*s\n", CPUTeamName, MaxTauntLen, TauntList[Taunt][Which]);

	// Message squelching -- only do this *AFTER* all calls to Random() and things that can affect gamestate. Need to do null pointer checks.
	// -- if this is the case, then InitTaunts() was not called correctly.
	if((g_pElapsedTime == NULL) ||
		(g_pLastTauntPrintedAt == NULL) ||
		(g_pTPS == NULL) ||
		((*g_pElapsedTime) - (*g_pLastTauntPrintedAt)) < ((*g_pTPS) * 20))
		return;

	// Note when we printed a taunt
	*g_pLastTauntPrintedAt = *g_pElapsedTime;

	// Always re-read pref; it might have changed during play.
	if(IFace_GetInteger("options.play.taunts"))
		AddToMessagesBox(TempBuffer);
}

// Lua: SetTauntCPUName(name). The binary passes the name straight through as the format string.
void SetTauntCPUName(const char* Name)
{
	sprintf_s(CPUTeamName, Name);
}

void CleanupTaunts(void)
{
	for(int i = 0; i < TauntHeaderCount; i++)
	{
		free(TauntBuffer[i]);
		TauntBuffer[i] = NULL;
	}
}
