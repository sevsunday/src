// PROVENANCE: ancestor reference/ancestor-bz1helper-2015/Shared/AttacherHelper.cpp @6fda4f5 (tap build / ride / aim / Cerberus tail logic) | decompile reference/decompiled/strategy02-ghidra12.2/src/missions/vsrcore/attacherhelper.cpp.decomp.c (PostLoad 35-60, AddAttacherObject 79-194, Execute 197-686; Load / Save inlined into BZ1Helper) + dumpbin of 4fc1a485 for the register-passed arguments | status: ported
#include "bz1helper.h"
#include "attacherhelper.h"
#include "objecthelper.h"
#include "bzcscriptutils.h"
#include <algorithm>

std::vector<AttacherHelper::AttacherClass> TempAttacherBuffer; // GBD: the list as it stood before a Load, for PostLoad's resync report.

AttacherHelper::AttacherHelper()
{
}
AttacherHelper::~AttacherHelper()
{
}

bool AttacherHelper::Load(bool missionSave)
{
	if (!missionSave)
	{
		TempAttacherBuffer = AttacherList;

		int size = 0;
		bool ret = Read(&size, 1);
		AttacherList.resize(size);
		if(size)
			ret = ret && Read(&AttacherList.front(), sizeof(AttacherClass)*size);
		return ret;
	}
	return true;
}

bool AttacherHelper::PostLoad(bool missionSave)
{
	if (!missionSave)
	{
		for (std::vector<AttacherClass>::iterator iter = AttacherList.begin(); iter != AttacherList.end(); ++iter)
		{
			AttacherClass &sao = *iter;
			ConvertHandles(&sao.AttacherObject, 1);
			for(int x = 0;x<MAX_TAPS;x++)
				ConvertHandles(&sao.Tap[x].TapObject, 1);
		}

		// GBD: resync report — compare what we had against what we loaded.
		if (TempAttacherBuffer.size() == AttacherList.size())
		{
			for (int i = 0; i < int(AttacherList.size()); i++)
			{
				if (!(TempAttacherBuffer[i] == AttacherList[i]))
				{
					FormatLogMessage("AttacherList Index Mismatch: %d", i);
					break;
				}
			}
		}
		else
		{
			FormatLogMessage("AttacherList Size Mismatch! Old: %d New: %d", TempAttacherBuffer.size(), AttacherList.size());
		}
	}
	return true;
}

bool AttacherHelper::Save(bool missionSave)
{
	if (!missionSave)
	{
		int size = int(AttacherList.size());
		bool ret = Write(&size, 1);
		if(size)
			ret = ret && Write(&AttacherList.front(), sizeof(AttacherClass)*size);
		return ret;
	}
	return true;
}

void AttacherHelper::AddAttacherObject(const Handle h, const char* TempODF1, const char* TempODF2, const int BZCClassHash, const char* ODFName)
{
	// If it has a first entry, continue, else don't bother.
	char TempAttacherODF[MAX_ODF_LENGTH] = {0};
	if ((!GetODFString(TempODF1, TempODF2, "GameObjectClass", "AttachedObject1", MAX_ODF_LENGTH, TempAttacherODF)) || (!TempAttacherODF[0]))
		return;

	for (std::vector<AttacherClass>::iterator iter = AttacherList.begin(); iter != AttacherList.end(); ++iter)
	{
		if(iter->AttacherObject == h)
			return;
	}

	// VSR: the attached ODFs are read once here and kept for the per-tap pass below.
	char AttacherODFs[MAX_TAPS][MAX_ODF_LENGTH] = {0};
	strcpy_s(AttacherODFs[0], TempAttacherODF);
	int NumberOfTaps = 1;
	for(int i = 0; i < MAX_TAPS; i++)
	{
		char DesiredValue[MAX_ODF_LENGTH] = {0};
		sprintf_s(DesiredValue, "AttachedObject%d", i+1);
		if (i > 0)
		{
			if((!GetODFString(TempODF1, TempODF2, "GameObjectClass", DesiredValue, MAX_ODF_LENGTH, AttacherODFs[i])) || (!AttacherODFs[i][0])) // Grab the value.
				break; // We have a gap, abort here.
			NumberOfTaps++;
		}

		// If this object is trying to attach itself to itself, prevent an infinite loop.
		if(_stricmp(AttacherODFs[i], ODFName) == 0)
		{
			FormatConsoleMessage("ERROR: ODF '%s', '%s' attempted to attach itself, preventing infinite loop.", ODFName, DesiredValue);
			return;
		}
	}
	if(!NumberOfTaps) // No taps, exit early.
		return;

	AttacherList.resize(AttacherList.size()+1);
	AttacherClass &sao = AttacherList[AttacherList.size()-1]; // No temporary being created, *much* faster
	memset(&sao, 0, sizeof(AttacherClass)); // Zero things out at start.

	// Is this unit a Cerberus?
	if(BZCClassHash == BZCCLASS_CERBERUS)
		sao.IsCerberus = true;

	// Save how many taps we have.
	sao.NumberOfTaps = NumberOfTaps;

	// Attacher Code added because I got tired of waiting for N1's version... -GBD
	for(int i = 0; i < NumberOfTaps; i++)
	{
		AttacherTapClass &tap = sao.Tap[i];
		char DesiredValue[MAX_ODF_LENGTH] = {0};

		// Grab independance settings.
		sprintf_s(DesiredValue, "AttachedIndependent%d", i+1);
		GetODFBool(TempODF1, TempODF2, "GameObjectClass", DesiredValue, &tap.TapIndependance, true);

		// Grab targeting independance settings.
		sprintf_s(DesiredValue, "AttachedCoordinateFire%d", i+1);
		GetODFBool(TempODF1, TempODF2, "GameObjectClass", DesiredValue, &tap.TapCoordinateFire, false);

		// Grab deploy behavior setting. // -1 = always on, 0 = only exist while undeployed, 1 = only exist while deployed
		sprintf_s(DesiredValue, "AttachedDeployState%d", i+1);
		GetODFInt(TempODF1, TempODF2, "GameObjectClass", DesiredValue, &tap.TapDeployBehavior, -1);
		if((tap.TapDeployBehavior < -1) || (tap.TapDeployBehavior > 1))
			tap.TapDeployBehavior = -1; // Fallback to default.

		// Is this tap in PDS mode?
		sprintf_s(DesiredValue, "AttachedPDSMode%d", i+1);
		GetODFBool(TempODF1, TempODF2, "GameObjectClass", DesiredValue, &tap.PDSMode, false);

		// Weapon Symmetry Mask?
		sprintf_s(DesiredValue, "AttachedWeaponSymmetryMask%d", i+1);
		GetODFString(TempODF1, TempODF2, "GameObjectClass", DesiredValue, MAX_HARDPOINTS+1, tap.TapWeaponSymmetryMask, "00000");

		// Grab XYZ Offset.
		sprintf_s(DesiredValue, "AttachedOffset%d", i+1);
		GetODFVector(TempODF1, TempODF2, "GameObjectClass", DesiredValue, &tap.TapOffset);

		sprintf_s(DesiredValue, "AttachedRotation%d", i+1);
		GetODFVector(TempODF1, TempODF2, "GameObjectClass", DesiredValue, &tap.TapRotation);
		tap.TapRotation = Vector_Scale(tap.TapRotation, DEG_2_RAD);

		CombineStrings(TempAttacherODF, AttacherODFs[i], ".odf"); // Add .odf to the end.
		if(OpenODF2(TempAttacherODF))
		{
			char TempAttacherODF2[MAX_ODF_LENGTH] = {0};
			char Classlabel[MAX_ODF_LENGTH] = {0};
			// If this ODF is inherited, then try that ODF.
			if(GetODFString(TempAttacherODF, "GameObjectClass", "classlabel", MAX_ODF_LENGTH, Classlabel)) // Grab the classlabel.
			{
				CombineStrings(TempAttacherODF2, Classlabel, ".odf"); // Add .odf to the end.
				if (!OpenODF2(TempAttacherODF2))
					TempAttacherODF2[0] = '\0';
			}

			// Get it's engage range.
			if((GetODFFloat(TempAttacherODF, TempAttacherODF2, "CraftClass", "EngageRange", &tap.TapEngageRange, 0.0f)) ||
				(GetODFFloat(TempAttacherODF, TempAttacherODF2, "CraftClass", "RangeScan", &tap.TapEngageRange, 0.0f))) // Must be 0, for False shooty stuff.
			{
				// Got it.
			}
		}
	} // Loop over Taps.

	sao.AttacherObject = h; // Save it.
}

void AttacherHelper::Execute(BZ1Helper &bz1Helper)
{
	const bool Logging = BZ1Helper::Logging;

	// Sweep through the attachers and remove any of them that are no longer around
	std::vector<AttacherClass>::iterator validEnd = AttacherList.begin();
	std::vector<AttacherClass>::iterator lastValid = AttacherList.begin();
	for (std::vector<AttacherClass>::iterator iter = AttacherList.begin(); iter != AttacherList.end(); ++iter)
	{
		// If the host is around...
		if (IsAround(iter->AttacherObject))
		{
			// Copy the valid entry into the valid portion
			if (lastValid != iter)
				*validEnd = *iter;
			++validEnd;
		}
		else
		{
			for(int x = 0; x < iter->NumberOfTaps; x++)
				RemoveObject(iter->Tap[x].TapObject);
		}
	}
	// Now erase any invalid entries left behind
	AttacherList.erase(validEnd, AttacherList.end());

	for (std::vector<AttacherClass>::iterator iter = AttacherList.begin(); iter != AttacherList.end(); ++iter)
	{
		const Vector HostVelocity = GetVelocity(iter->AttacherObject);
		const Vector HostOmega = GetOmega(iter->AttacherObject);
		const Handle HostTarget = GetTarget(iter->AttacherObject);
		const Matrix HostMatrix = GetMatrixPosition(iter->AttacherObject);
		const int Team = GetTeamNum(iter->AttacherObject);
		bool TargetIsAllied = false;
		if (HostTarget)
			TargetIsAllied = IsTeamAllied(Team, GetTeamNum(HostTarget));
		Handle TempTapTarget[MAX_TAPS] = {0};
		const bool HostDeployed = IsDeployed(iter->AttacherObject);

		// Loop over each of our valid taps for this object.
		for(int x = 0; x < iter->NumberOfTaps; x++)
		{
			AttacherTapClass &tap = iter->Tap[x];

			// If this tap hasn't been built yet, do it here. Originally was done in AddObject but was suggested to move it to Execute.
			if((!tap.BuiltAttacherTap) && ((tap.TapDeployBehavior < 0) || (((tap.TapDeployBehavior) && (HostDeployed)) || ((!tap.TapDeployBehavior) && (!HostDeployed)))))
			{
				char TempAttacherODF[MAX_ODF_LENGTH] = {0}; // Temp store our variable.
				char DesiredValue[MAX_ODF_LENGTH] = {0};
				sprintf_s(DesiredValue, "AttachedObject%d", x+1);

				if(GetODFString(iter->AttacherObject, "GameObjectClass", DesiredValue, MAX_ODF_LENGTH, TempAttacherODF))
				{
					if(TempAttacherODF[0])
					{
						// Add it if so.
						if(DoesODFExist(TempAttacherODF))
						{
							tap.TapPosition = Matrix_Multiply(Build_Position_Rotation_Matrix(tap.TapRotation.x, tap.TapRotation.y, tap.TapRotation.z, tap.TapOffset), GetMatrixPosition(iter->AttacherObject));
							tap.TapObject = BuildObject(TempAttacherODF, Team, tap.TapPosition);
							SetIndependence(tap.TapObject, 0);

							char BZCClass[MAX_ODF_LENGTH] = {0};
							GetODFString(tap.TapObject, "GameObjectClass", "BZCClasslabel", MAX_ODF_LENGTH, BZCClass);
							unsigned int BZCClassHash = Hash(BZCClass);

							// Is this unit a Cerberus Tail?
							if(BZCClassHash == BZCCLASS_CERBERUS_TAIL)
							{
								tap.IsCerberusTail = true;

								GetODFFloat(tap.TapObject, "GameObjectClass", "CerbTailFireAngle", &tap.CerbTailConeAngle, 0.60f);

								bool HasAnim1 = false;
								bool HasAnim2 = false;
								bool HasAnim3 = false;
								char AnimationName[MAX_ODF_LENGTH] = {0};
								int AnimationCount = 0;
								GetODFInt(tap.TapObject, "GameObjectClass", "animCount", &AnimationCount, 0);
								for (int i = 1; i < AnimationCount+1; i++)
								{
									char AnimDesiredValue[MAX_ODF_LENGTH] = {0};
									sprintf_s(AnimDesiredValue, "animName%d", i);
									if(GetODFString(tap.TapObject, "GameObjectClass", AnimDesiredValue, MAX_ODF_LENGTH, AnimationName)) // Grab the animation name.
									{
										if((_stricmp(AnimationName,"CerbTailIdle")) == 0)
											HasAnim1 = true;
										else if((_stricmp(AnimationName,"CerbTailLeft")) == 0)
											HasAnim2 = true;
										else if((_stricmp(AnimationName,"CerbTailRight")) == 0)
											HasAnim3 = true;

										if((HasAnim1) && (HasAnim2) && (HasAnim3))
										{
											tap.IsCerberusTailAnimated = true;
											break; // We found it, abort!
										}
									}
								}

								if(tap.IsCerberusTailAnimated)
								{
									tap.CerbAnimLength = SetAnimation(tap.TapObject, "CerbTailIdle", 0); // Restart the animation.
									StartAnimation(tap.TapObject);

									if(Logging)
										FormatLogMessage("Playing Tail Loop Anim");
								}
							}
						}
						else
						{
							FormatLogMessage("ERROR: Attacher ODF '%s' Doesn't Exist!", TempAttacherODF);
						}
					}
					tap.BuiltAttacherTap = true;
				}
			}

			// If the attached object is around.
			if(!IsAround(tap.TapObject))
				continue;

			// If this tap is only supposed to be around in a certain Deploy state, remove it if it doesn't match.
			if( (tap.TapDeployBehavior >= 0) && // Deploy State not -1 (no special behavior)
				((tap.TapDeployBehavior != 0) == HostDeployed)) // Deployed state doesn't match.
			{
				RemoveObject(tap.TapObject);
				// Zero this tap's settings out.
				tap.IsHostDeployed = false;
				tap.TapIsAttacking = false;
				tap.TapShutOff = false;
				continue; // Skip this one.
			}

			Matrix TapMatrix = Matrix_Multiply(Build_Position_Rotation_Matrix(tap.TapRotation.x, tap.TapRotation.y, tap.TapRotation.z, tap.TapOffset), HostMatrix);

			// VSR: craft and pilots are teleported; everything else is also given the interpolation pair (as shipped: the new matrix as "last", the stored one as "true").
			if ((IsCraft(tap.TapObject)) || (IsPerson(tap.TapObject)))
			{
				SetLastCurrentPosition(tap.TapObject, tap.TapPosition, TapMatrix);
			}
			else
			{
				SetLastCurrentPosition(tap.TapObject, tap.TapPosition, TapMatrix);
				SetInterpolablePosition(tap.TapObject, &TapMatrix, &tap.TapPosition, true);
			}

			// VSR: the tap's velocity is the host's plus the spin about the host (its omega in world space, crossed with the host-to-tap offset as shipped).
			const Vector Offset = HostMatrix.posit - TapMatrix.posit;
			const Vector TapVelocity = HostVelocity + Cross_Product(Vector_Rotate(HostMatrix, HostOmega), Offset);
			SetVelocity(tap.TapObject, TapVelocity);
			tap.TapPosition = TapMatrix; // Save this for next tick.

			// Weapon Symmetry. Compare weapons from Host/Taps, and if this tap should mirror that weapon, copy it over if it's different.
			bool ShouldSwapWeapons = false;
			int CurIndex = 0;
			char NewTapWeapons[MAX_HARDPOINTS][MAX_ODF_LENGTH] = {0};
			float PrevLocalAmmo[MAX_HARDPOINTS] = {0};
			for(int i = 0; i < MAX_HARDPOINTS; i++)
			{
				if((tap.TapWeaponSymmetryMask[4-i]) && (tap.TapWeaponSymmetryMask[4-i] != '0')) // A function to GetWeaponMask(h) would be nice.
				{
					char HostWeapon[MAX_ODF_LENGTH] = {0};
					char TapWeapon[MAX_ODF_LENGTH] = {0};
					if((GetObjInfo(iter->AttacherObject, ObjectInfoType(Get_Weapon0Config+i), HostWeapon)) &&
						(GetObjInfo(tap.TapObject, ObjectInfoType(Get_Weapon0Config+i), TapWeapon)))
					{
						PrevLocalAmmo[i] = GetCurLocalAmmo(iter->AttacherObject, i);
						if(_stricmp(HostWeapon, TapWeapon) != 0) // They don't match.
						{
							ShouldSwapWeapons = true;

							// Build a new weapon list to use with ReplaceWeapons.
							strcpy_s(NewTapWeapons[CurIndex++], HostWeapon);
						}
					}
				}
			}
			if(ShouldSwapWeapons)
				ReplaceWeapons(tap.TapObject, NewTapWeapons, PrevLocalAmmo);

			if(!TempTapTarget[x])
				TempTapTarget[x] = GetTarget(tap.TapObject);

			// VSR: a player in the tap aims it himself.
			if (!IsPlayer(tap.TapObject))
			{
				// If this tap is a shooty thing, do shooty stuff, and is NOT a cerberus tail.
				if(!tap.IsCerberusTail)
				{
					if(tap.TapEngageRange != 0.0f)
					{
						// If tap is not independant, focus fire on host Target, stop when not around.
						if( (HostTarget) && // Target is around.
							(!TargetIsAllied) && // It's an Enemy!
							((!tap.PDSMode) || ((IsPerson(HostTarget)) || (IsWeapon(HostTarget))))) // PDS Mode settings.
						{
							Attack(tap.TapObject, HostTarget, 1);
							tap.TapIsAttacking = true;

							if(Logging)
								FormatLogMessage("Tap %x Attacking Host Target: %08x '%s'", x, HostTarget, GetODFName(HostTarget));
						}
						else // Find our own Target.
						{
							if(tap.TapIsAttacking) // We were shooting at the Host's target, but they dis-engaged, Stop firing at it.
							{
								SetCommand(tap.TapObject, CMD_STOP, 1);
								tap.TapIsAttacking = false;

								if(Logging)
									FormatLogMessage("Tap %x Switching to own AI control", x);
							}

							// If there's no Target, choose your own target.
							if((tap.TapIndependance) && (!TempTapTarget[x])) // If we don't already have our own Target, Pick a new one.
							{
								const int CategoryMask = tap.PDSMode ? (CategoryType_Weapon + CategoryType_Person) : (CategoryType_Weapon + CategoryType_Person + CategoryType_Building + CategoryType_Craft);
								TempTapTarget[x] = bz1Helper.GetNearestObject(TapMatrix.posit, tap.TapEngageRange, Team, TeamFilter_Enemies, true, CategoryMask);

								if(TempTapTarget[x]) // If the above found something.
								{
									Attack(tap.TapObject, TempTapTarget[x], 1);

									if(Logging)
										FormatLogMessage("Tap %x Set to Attack %08x '%s'", x, TempTapTarget[x], GetODFName(TempTapTarget[x]));
								}
							}
						}

						// If coordinated fire is false, make each tap try to pick its own target, unless the host is Targeting something.
						if((!tap.TapCoordinateFire) && ((!HostTarget) || (TargetIsAllied)) && (TempTapTarget[x]))
						{
							// We already have a Target, find out if other Taps are also shooting at it.
							for(int d = 0; d < iter->NumberOfTaps; d++)
							{
								if((d != x) && (TempTapTarget[x] == TempTapTarget[d]) && (iter->Tap[d].TapObject) && (TempTapTarget[d]))
								{
									if(Logging)
										FormatLogMessage("Tap %d Target: %08x '%s', picking new target...", d, TempTapTarget[d], GetODFName(TempTapTarget[d]));

									// This is already being shot at by another Tap. Retarget: loop over all possible targets.
									const float EngageRangeSquared = Squared(tap.TapEngageRange);
									for(int t = 0; t < bz1Helper.GetNumHandles(); t++)
									{
										const ObjectHelper::ObjectClass &objectInfo = bz1Helper.GetHandleInfo(t);
										Handle NewTarget = objectInfo.ObjectHandle;

										if((IsTeamAllied(Team, objectInfo.CurTeamNum)) || // If this team is allied.
											(GetMaxHealth(NewTarget) <= 0) || // If it's health is 0.
											(GetDistance3DSquared(TapMatrix.posit, objectInfo.Position) > EngageRangeSquared) || // If it's outside of range.
											((tap.PDSMode) && ((objectInfo.CategoryID != CategoryType_Person) && (objectInfo.CategoryID != CategoryType_Weapon)))) // If PDSMode and not a weapon or person.
											continue; // Skip this object.

										bool Skip = false;
										for(int d2 = 0; d2 < iter->NumberOfTaps; d2++)
										{
											if((IsAround(iter->Tap[d2].TapObject)) && (TempTapTarget[d2]) && (NewTarget == TempTapTarget[d2]))
											{
												if(Logging)
												{
													char NewTargetODF[MAX_ODF_LENGTH] = {0};
													char TapTargetODF[MAX_ODF_LENGTH] = {0};
													GetODFName(NewTarget, NewTargetODF);
													GetODFName(TempTapTarget[d2], TapTargetODF);
													FormatLogMessage("Tap: %d Target %08x '%s' matches existing Target, Tap %d Target: %08x '%s'", x, NewTarget, NewTargetODF, d2, TempTapTarget[d2], TapTargetODF);
												}

												Skip = true;
												break;
											}
										}
										if(Skip)
											continue; // Skip to next item in the list.

										char ObjClass[MAX_ODF_LENGTH] = {0};
										GetObjInfo(tap.TapObject, Get_GOClass, ObjClass);

										// This object is within range, and is facing close enough to us, and it's health is > 0.
										if((_stricmp(ObjClass, "CLASS_WALKER") != 0) || (IsObjectFacingObject(tap.TapObject, NewTarget, 3.141592f))) // Object is facing close to us. ~180 degrees
										{
											TempTapTarget[x] = NewTarget;
											Attack(tap.TapObject, TempTapTarget[x], 1);

											if(Logging)
												FormatLogMessage("Tap %d Targeting New Target: %08x '%s'", x, NewTarget, GetODFName(NewTarget));

											break;
										}
									}
									break;
								}
							}
						}

						// Shutoff Tap fire if the host is empty. Ken Code (TM)
						bool tapShutOff = !IsAliveAndPilot2(iter->AttacherObject) && !IsPlayer(iter->AttacherObject);
						if(tapShutOff != tap.TapShutOff)
						{
							if(tapShutOff)
								SetCommand(tap.TapObject, CMD_STOP, 1);
							tap.TapShutOff = tapShutOff;
						}
					} // This is something that can shoot
				} // end NOT a Cerberus Tail.
				else // Do Cerberus Tail stuff here.
				{
					Handle CerbTailTarget = 0;
					const float EngageRangeSquared = Squared(tap.TapEngageRange);

					for(int t = 0; t < bz1Helper.GetNumHandles(); t++)
					{
						const ObjectHelper::ObjectClass &objectInfo = bz1Helper.GetHandleInfo(t);
						Handle TempTarget = objectInfo.ObjectHandle;

						if( (objectInfo.CategoryID == CategoryType_Craft) && // It's a Vehicle.
							(!IsTeamAllied(Team, objectInfo.CurTeamNum)) && // It's an Enemy!
							(GetDistance3DSquared(TapMatrix.posit, objectInfo.Position) < EngageRangeSquared) && // Distance is within Range.
							(IsObjectFacingObject(tap.TapObject, TempTarget, tap.CerbTailConeAngle))) // It's facing the correct direction.
						{
							CerbTailTarget = TempTarget;

							// The tail isn't currently swinging, and the target is within range, and towards the front of the Tail tap.
							float AnimationFrame = 0;
							switch (tap.CerbTailSwinging)
							{
							case 0:
								AnimationFrame = GetAnimationFrame(tap.TapObject, "CerbTailIdle");
								break;
							case 1:
								AnimationFrame = GetAnimationFrame(tap.TapObject, "CerbTailLeft");
								break;
							case 2:
								AnimationFrame = GetAnimationFrame(tap.TapObject, "CerbTailRight");
								break;
							}

							if(AnimationFrame == tap.CerbAnimLength)
							{
								// Is it to the right or left?
								if(IsObjectFacingObjectRight(tap.TapObject, TempTarget))
								{
									tap.CerbTailSwinging = 2; // Right
									tap.CerbAnimLength = SetAnimation(tap.TapObject, "CerbTailRight", 0); // Restart the animation.
								}
								else
								{
									tap.CerbTailSwinging = 1; // Left
									tap.CerbAnimLength = SetAnimation(tap.TapObject, "CerbTailLeft", 0); // Restart the animation.
								}

								StartAnimation(tap.TapObject);
								Attack(tap.TapObject, TempTarget, 1);

								if(Logging)
									FormatLogMessage("Playing Tail Swing Anim");
							}
							break; // We found a target, stop looking.
						}
					}
					if((tap.CerbTailSwinging) && (!CerbTailTarget))
					{
						// Wait till anim is done, then resume idle looping animation.
						float AnimationFrame = 0;
						switch (tap.CerbTailSwinging)
						{
						case 1:
							AnimationFrame = GetAnimationFrame(tap.TapObject, "CerbTailLeft");
							break;
						case 2:
							AnimationFrame = GetAnimationFrame(tap.TapObject, "CerbTailRight");
							break;
						}

						if(AnimationFrame == tap.CerbAnimLength)
						{
							SetCommand(tap.TapObject, CMD_STOP, 1); // Stop shooting now, anims done.
							tap.CerbTailSwinging = 0; // Nope.
							tap.CerbAnimLength = SetAnimation(tap.TapObject, "CerbTailIdle", 0); // Restart the animation.
							StartAnimation(tap.TapObject);

							if(Logging)
								FormatLogMessage("Playing Tail Idle Anim");
						}
					}
				}
			}

			// Play Deploy animations for taps when this host deploys.
			if((!tap.IsHostDeployed) && (HostDeployed)) // Only proceed if the object is still around and working.
			{
				tap.IsHostDeployed = true;
				SetAnimation(tap.TapObject, "deploy", 1); // Restart the animation.
				StartAnimation(tap.TapObject);
				Deploy(tap.TapObject);
			}
			else if((tap.IsHostDeployed) && (!HostDeployed))
			{
				tap.IsHostDeployed = false;
				SetAnimation(tap.TapObject, "undeploy", 1); // Restart the animation.
				StartAnimation(tap.TapObject);
				Deploy(tap.TapObject);
			}
		}
	}
}
