// PROVENANCE: ancestor reference/ancestor-1.3/Missions/Shared/TRNAllies.cpp @353698f + decompile strategy02-ghidra12.2 trnallies.cpp:9-53 (TRNAllies::SetupTRNAllies @4fc47061) | status: ported
#include "dllbase.h"
#include "trnallies.h"
#include <string.h>
#include <stdlib.h>

// Pass in a trn file name, e.g. "bridges2i.trn", and it'll set up
// default team allies specified in the trn file. See changelog
// for exact specs of what needs to be in the TRN.
void TRNAllies::SetupTRNAllies(const char* pTRNName)
{
	// Sanity checks
	if((pTRNName == NULL) || (pTRNName[0] == 0))
	{
		return;
	}

	OpenODF(const_cast<char*>(pTRNName));

	bool moreEntries = true;
	int entryNum = 1;
	do
	{
		char tempStr[256];
		char keyName[256];
		sprintf_s(keyName, "Entry%d", entryNum);
		if(GetODFString(pTRNName, "DefaultAllies", keyName, sizeof(tempStr), tempStr, ""))
		{
			// Parse entry. Should look like "###_###".
			int teamA;
			int teamB = 0;
			teamA = atoi(tempStr);
			char* pUnderscore = strchr(tempStr, '_');
			if(pUnderscore != NULL)
			{
				teamB = atoi(pUnderscore + 1);
			}

			if(((teamA > 0) && (teamA < 16)) &&
			   ((teamB > 0) && (teamB < 16)))
			{
				Ally(teamA, teamB);
			}

			++entryNum;
		}
		else
		{
			// GetODFString couldn't find the entry. Exit the loop
			moreEntries = false;
		}
	} while (moreEntries);

	CloseODF(const_cast<char*>(pTRNName));
}
