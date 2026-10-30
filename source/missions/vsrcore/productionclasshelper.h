// PROVENANCE: ancestor reference/ancestor-bz1helper-2015/Shared/ProductionClassHelper.h @6fda4f5 (the class shape; the 2015 camera-pod list and the per-team arrays moved into BZ1Helper::TeamInfo) | declarations original/missions/Strategy02.pdb via tools/pdb_types.py (empty class; AddProductionClassObject / Execute are its only procedures) | status: ported
#ifndef _ProductionClassHelper_
#define _ProductionClassHelper_

#include "ScriptUtils.h"

class BZ1Helper;

// This code handles scraphold management, production-unit build animations and sounds, the base-slot bookkeeping, and production class team switching.
// All of its state lives in BZ1Helper::TeamInfo (BaseSlot / BaseSlotScrap / BaseSlotName / BaseSlotBuildCount / BaseSlotPlayingAnim / BaseSlotAnimationFrames ...).
class ProductionClassHelper
{
	friend struct VsrLayoutCheck_ProductionClassHelper; // scaffold: QA gate 2 hook (layout asserts); not GBD's
private:

	static ProductionClassHelper *m_ProductionClassHelper;

public:
	ProductionClassHelper();
	~ProductionClassHelper();
	static ProductionClassHelper &Get() { return *m_ProductionClassHelper; }

	// Registers a production unit (recycler / factory / armory / constructor / base slot 5-9) on its team: slot handle + name, scrap hold, the limits / pilots / pools
	// flags, the command-panel cost table, the build-animation state, the undeploy ODF preload, and the Recycler / Factory / Armory / Constructor handle.
	void AddProductionClassObject(const Handle h, const char* TempODF1, const char* TempODF2, const int Team, const int ObjClassHash, const int BZCClassHash, const int TeamSlot);

	void Execute(BZ1Helper &bz1Helper);
};

#define VSR_LAYOUT_CHECK_ProductionClassHelper
#include "vsr_layout_asserts.h"
#undef VSR_LAYOUT_CHECK_ProductionClassHelper

#endif
