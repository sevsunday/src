// PROVENANCE: ancestor reference/ancestor-1.3/Missions/Shared/SubMission.h (verbatim; include path only) | class layout original/missions/Strategy02.pdb (SubMission 0x24, vtable Setup/Execute/AddObject/DeleteObject/ProcessCommand; header-only in every DLL, no SubMission:: proc survives) | status: ported
#ifndef _SubMission_
#define _SubMission_

#include "ScriptUtils.h"

#define MAX_TEAMS 16

//
// NUMERICAL FUNCTIONS
//

// return the minimum of two values
template <class T>
inline T min(const T a, const T b) { return (a < b) ? (a) : (b); }

// return the maximum of two values
template <class T>
inline T max(const T a, const T b) { return (a < b) ? (b) : (a); }

// clamp a value between a minimum and maximum
template <class T>
inline T clamp(const T x, const T min, const T max)
{
	if (x < min)
		return min;
	if (x > max)
		return max;
	return x;
}

class SubMission {
	friend struct VsrLayoutCheck_SubMission; // scaffold: QA gate 2 hook (layout asserts); not GBD's
public:
	SubMission(void)
	{
		b_array = NULL;
		b_count = 0;

		f_array = NULL;
		f_count = 0;

		h_array = NULL;
		h_count = 0;

		i_array = NULL;
		i_count = 0;	
	}

	virtual void Setup(void) = 0;
	virtual void Execute(bool *pTeamIsSetUp, Handle *m_RecyclerHandles) = 0;

	virtual void AddObject(Handle, bool IsStartingVehicles=false, Handle *m_RecyclerHandles = NULL)
	{
		(void)(IsStartingVehicles);
		(void)(m_RecyclerHandles);
	}
	virtual void DeleteObject(Handle)
	{
	}
	virtual void ProcessCommand(unsigned long)
	{
	}

	bool Save(bool missionSave);
	bool Load(bool missionSave);
	bool PostLoad(bool missionSave);

	bool *b_array;
	int b_count;

	float *f_array;
	int f_count;

	int *h_array;
	int h_count;

	int *i_array;
	int i_count;
};

extern SubMission *BuildSubMission(void);

#define VSR_LAYOUT_CHECK_SubMission
#include "vsr_layout_asserts.h"
#undef VSR_LAYOUT_CHECK_SubMission

#endif
