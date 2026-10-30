// PROVENANCE: ancestor reference/ancestor-bz1helper-2015/Shared/BZ1Helper.cpp @6fda4f5 (HandleList Load / PostLoad / Save / sweep — the list lived inside BZ1Helper in 2015) | decompile reference/decompiled/strategy02-ghidra12.2/src/missions/vsrcore/objecthelper.cpp.decomp.c (PostLoad 31-52, Save 55-64, Execute 77-119; Load inlined into BZ1Helper::Load, bz1helper.cpp.decomp.c:818-846) | status: ported
#include "bz1helper.h"
#include "objecthelper.h"
#include "portalhelper.h"
#include "bzcscriptutils.h"
#include <algorithm>

std::vector<ObjectHelper::ObjectClass> TempHandleBuffer; // GBD: the list as it stood before a Load, for PostLoad's resync report.

ObjectHelper::ObjectHelper()
{
}
ObjectHelper::~ObjectHelper()
{
}

bool ObjectHelper::Load(bool missionSave)
{
	if (!missionSave)
	{
		TempHandleBuffer = HandleList;

		int size = 0;
		bool ret = Read(&size, 1);
		HandleList.resize(size);
		if(size)
			ret = ret && Read(&HandleList.front(), sizeof(ObjectClass)*size);
		return ret;
	}
	return true;
}

bool ObjectHelper::PostLoad(bool missionSave)
{
	if (!missionSave)
	{
		for (std::vector<ObjectClass>::iterator iter = HandleList.begin(); iter != HandleList.end(); ++iter)
		{
			ObjectClass &sao = *iter;
			ConvertHandles(&sao.ObjectHandle, 1);
		}

		if (TempHandleBuffer.size() == HandleList.size())
		{
			for (int i = 0; i < int(HandleList.size()); ++i)
			{
				if (!(TempHandleBuffer[i] == HandleList[i]))
				{
					FormatLogMessage("HandleList Index Mismatch: %d", i);
					return true;
				}
			}
		}
		else
		{
			FormatLogMessage("HandleList Size Mismatch! Old: %d New: %d", TempHandleBuffer.size(), HandleList.size());
		}
	}
	return true;
}

bool ObjectHelper::Save(bool missionSave)
{
	if (!missionSave)
	{
		int size = int(HandleList.size());
		bool ret = Write(&size, 1);
		if(size)
			ret = ret && Write(&HandleList.front(), sizeof(ObjectClass)*size);
		return ret;
	}
	return true;
}

void ObjectHelper::Execute(BZ1Helper & /*bz1Helper*/, PortalHelper *pPortalHelper)
{
	// pre-clean the vector
	HandleList.erase(std::remove_if(HandleList.begin(), HandleList.end(), ShouldRemoveObject), HandleList.end());

	for (std::vector<ObjectClass>::iterator iter = HandleList.begin(); iter != HandleList.end(); ++iter)
	{
		iter->CurTeamNum = GetTeamNum(iter->ObjectHandle);
		iter->Position = GetPosition(iter->ObjectHandle);
		iter->PTeam = GetPerceivedTeam(iter->ObjectHandle);

		if (iter->CanTeleport)
			pPortalHelper->ExecuteObject(*iter);
	}
}
