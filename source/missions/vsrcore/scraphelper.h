// PROVENANCE: ancestor reference/ancestor-bz1helper-2015/Shared/ScrapHelper.h @6fda4f5 | declarations original/missions/Strategy02.pdb via tools/pdb_types.py | status: ported
#ifndef _ScrapHelper_
#define _ScrapHelper_

#include "ScriptUtils.h"
#include <vector>

class BZ1Helper;

class ScrapHelper
{
	friend struct VsrLayoutCheck_ScrapHelper; // scaffold: QA gate 2 hook (layout asserts); not GBD's
public:
	// GBD: public (the file-scope TempScrapBuffer snapshot is a vector of these).
	struct ScrapClass {
		friend struct VsrLayoutCheck_ScrapHelper__ScrapClass; // scaffold: QA gate 2 hook (layout asserts); not GBD's
		Handle ScrapObject; // This Scrap Object.

		ScrapClass() { memset(this, 0, sizeof(ScrapClass)); };
	};

private:

	static ScrapHelper *m_ScrapHelper;

	std::vector<ScrapClass> ScrapList;
	static bool ShouldRemoveScrap(const ScrapClass &entry) { return !IsAround(entry.ScrapObject); }

public:
	ScrapHelper();
	~ScrapHelper();
	static ScrapHelper &Get() { return *m_ScrapHelper; }

	int GetNumScrapObjects() { return int(ScrapList.size()); }
	Handle &RefScrapHandle(const int index) { return ScrapList[index].ScrapObject; }

//	void RemoveScrapHandle(const int index);
	void GetRidOfSomeScrap(const int ScrapLimit = 1000);
	void ClearScrapAround(const Dist d, const Vector &pos, const float Percent = 1.0f);

	// GBD: RestrictAllScrap applies the map's scrap height band even when the ODF does not ask for it (default reconstructed).
	void AddScrapObject(const Handle h, const char* TempODF1, const char* TempODF2, const bool RestrictAllScrap = false);

	bool Load(bool missionSave);
	bool PostLoad(bool missionSave);
	bool Save(bool missionSave);

	void Execute(BZ1Helper &bz1Helper);
};

#define VSR_LAYOUT_CHECK_ScrapHelper
#include "vsr_layout_asserts.h"
#undef VSR_LAYOUT_CHECK_ScrapHelper

#endif
