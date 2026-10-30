// PROVENANCE: ancestor reference/ancestor-bz1helper-2015/Shared/Taunts.h @6fda4f5 | declarations original/missions/Strategy02.pdb via tools/pdb_types.py (TauntTypes values, function signatures) | status: ported
#ifndef _TAUNTS_H_
#define _TAUNTS_H_

// VSR: taunt text lives in <TauntODFFile><Category>.otf files, one line per taunt; the
// category list comes from <TauntODFFile>.odf [TauntCategories] Category0..N (TauntODFFile
// is read from the map .trn [DLL] section, default "Taunts"). Up to 16 categories.
enum TauntTypes {
	TAUNTS_GameStart,
	TAUNTS_NewHuman,
	TAUNTS_LeftHuman,
	TAUNTS_HumanShipDestroyed,
	TAUNTS_HumanRecyDestroyed,
	TAUNTS_CPURecyDestroyed,
	TAUNTS_Random,
	TAUNTS_Category7,
	TAUNTS_Category8,
	TAUNTS_Category9,
	TAUNTS_Category10,
	TAUNTS_Category11,
	TAUNTS_Category12,
	TAUNTS_Category13,
	TAUNTS_Category14,
	TAUNTS_Category15,
	TAUNTS_MAX,
};

// Required setup call before you call DoTaunt(). pGameTime is used to
// squelch too-often messages. [It should be the # of calls to
// Execute]. pLastMessagePrintedAt is a scratchpad variable used to
// note things, should be saved. pTPS should be a pointer to the TPS
// in use. pCPUTeamName is kept for the old callers; the CPU name now
// comes from network.session.svar2 or SetTauntCPUName().
void InitTaunts(int* pGameTime, int* pLastMessagePrintedAt, int* pTPS, const char* pCPUTeamName = NULL);

// Prints a taunt from the specified category (an index into the .odf's categories).
void DoTaunt(int Taunt);

// Overrides the "<name> : " prefix (Lua: SetTauntCPUName).
void SetTauntCPUName(const char* Name);

// Frees the loaded .otf buffers.
void CleanupTaunts(void);

#endif // _TAUNTS_H_
