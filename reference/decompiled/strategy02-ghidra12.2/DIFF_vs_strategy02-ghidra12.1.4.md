# DIFF: strategy02-ghidra12.2 vs strategy02-ghidra12.1.4 (tools/diff_decompile.py)

## 1. Function roster

old 1925 · new 1925 · added 25 · removed 25 · resized 0 · line-range changed 0

### Added (25)
- `__callnewh` @ 4fc403bb
- `__cexit` @ 4fc403f7
- `__configure_narrow_argv` @ 4fc403d3
- `__crt_atexit` @ 4fc403f1
- `__except1` @ 4fc552c1
- `__except_handler4_common` @ 4fc403a9
- `__execute_onexit_table` @ 4fc403eb
- `__initialize_narrow_environment` @ 4fc403d9
- `__initialize_onexit_table` @ 4fc403df
- `__initterm` @ 4fc403c1
- `__initterm_e` @ 4fc403c7
- `__libm_sse2_acos_precise` @ 4fc55273
- `__libm_sse2_asin_precise` @ 4fc55279
- `__libm_sse2_atan_precise` @ 4fc5527f
- `__libm_sse2_cos_precise` @ 4fc55285
- `__libm_sse2_exp_precise` @ 4fc5528b
- `__libm_sse2_log10_precise` @ 4fc55291
- `__libm_sse2_log_precise` @ 4fc55297
- `__libm_sse2_pow_precise` @ 4fc5529d
- `__libm_sse2_sin_precise` @ 4fc552a3
- `__libm_sse2_sqrt_precise` @ 4fc552a9
- `__libm_sse2_tan_precise` @ 4fc552af
- `__register_onexit_function` @ 4fc403e5
- `__seh_filter_dll` @ 4fc403cd
- `__setjmp3` @ 4fc55225

### Removed (25)
- `callnewh` @ 4fc403bb
- `cexit` @ 4fc403f7
- `configure_narrow_argv` @ 4fc403d3
- `crt_atexit` @ 4fc403f1
- `except1` @ 4fc552c1
- `except_handler4_common` @ 4fc403a9
- `execute_onexit_table` @ 4fc403eb
- `initialize_narrow_environment` @ 4fc403d9
- `initialize_onexit_table` @ 4fc403df
- `initterm` @ 4fc403c1
- `initterm_e` @ 4fc403c7
- `libm_sse2_acos_precise` @ 4fc55273
- `libm_sse2_asin_precise` @ 4fc55279
- `libm_sse2_atan_precise` @ 4fc5527f
- `libm_sse2_cos_precise` @ 4fc55285
- `libm_sse2_exp_precise` @ 4fc5528b
- `libm_sse2_log10_precise` @ 4fc55291
- `libm_sse2_log_precise` @ 4fc55297
- `libm_sse2_pow_precise` @ 4fc5529d
- `libm_sse2_sin_precise` @ 4fc552a3
- `libm_sse2_sqrt_precise` @ 4fc552a9
- `libm_sse2_tan_precise` @ 4fc552af
- `register_onexit_function` @ 4fc403e5
- `seh_filter_dll` @ 4fc403cd
- `setjmp3` @ 4fc55225

### Resized (0)

### Line range changed (0)

## 2. Per-file (user functions, max line)

| file | old fns | new fns | old max | new max |
|---|---:|---:|---:|---:|
| `/e:/github/vsr_dll_source/missions/luamission/luabindings.cpp` | 516 | 516 | 6656 | 6656 |
| `/e:/github/vsr_dll_source/missions/luamission/luamission.cpp` | 26 | 26 | 985 | 985 |
| `/e:/github/vsr_dll_source/missions/shared/dllbase.cpp` | 45 | 45 | 402 | 402 |
| `/e:/github/vsr_dll_source/missions/shared/dllutils.cpp` | 3 | 3 | 77 | 77 |
| `/e:/github/vsr_dll_source/missions/shared/startingvehicles.cpp` | 4 | 4 | 154 | 154 |
| `/e:/github/vsr_dll_source/missions/shared/taunts.cpp` | 4 | 4 | 220 | 220 |
| `/e:/github/vsr_dll_source/missions/shared/trnallies.cpp` | 1 | 1 | 53 | 53 |
| `/e:/github/vsr_dll_source/missions/strategy02/strategy02.cpp` | 34 | 34 | 3859 | 3859 |
| `/e:/github/vsr_dll_source/missions/strategy02/strategy02.h` | 4 | 4 | 58 | 58 |
| `/e:/github/vsr_dll_source/missions/vsrcore/aiweaponhelper.cpp` | 1 | 1 | 201 | 201 |
| `/e:/github/vsr_dll_source/missions/vsrcore/ambientsoundhelper.cpp` | 4 | 4 | 184 | 184 |
| `/e:/github/vsr_dll_source/missions/vsrcore/ambientsoundhelper.h` | 1 | 1 | 101 | 101 |
| `/e:/github/vsr_dll_source/missions/vsrcore/attacherhelper.cpp` | 4 | 4 | 686 | 686 |
| `/e:/github/vsr_dll_source/missions/vsrcore/attacherhelper.h` | 1 | 1 | 206 | 206 |
| `/e:/github/vsr_dll_source/missions/vsrcore/buildinghelper.cpp` | 8 | 8 | 1020 | 1020 |
| `/e:/github/vsr_dll_source/missions/vsrcore/buildinghelper.h` | 3 | 3 | 358 | 358 |
| `/e:/github/vsr_dll_source/missions/vsrcore/bz1helper.cpp` | 37 | 37 | 5248 | 5248 |
| `/e:/github/vsr_dll_source/missions/vsrcore/bz1helper.h` | 8 | 8 | 1277 | 1277 |
| `/e:/github/vsr_dll_source/missions/vsrcore/bzcscriptutils.cpp` | 85 | 85 | 5059 | 5059 |
| `/e:/github/vsr_dll_source/missions/vsrcore/bzcscriptutils.h` | 30 | 30 | 1319 | 1319 |
| `/e:/github/vsr_dll_source/missions/vsrcore/carrierhelper.cpp` | 16 | 16 | 637 | 637 |
| `/e:/github/vsr_dll_source/missions/vsrcore/carrierhelper.h` | 2 | 2 | 187 | 187 |
| `/e:/github/vsr_dll_source/missions/vsrcore/dispatchhelper.cpp` | 11 | 11 | 2183 | 2183 |
| `/e:/github/vsr_dll_source/missions/vsrcore/dispatchhelper.h` | 1 | 1 | 295 | 295 |
| `/e:/github/vsr_dll_source/missions/vsrcore/gravityhelper.cpp` | 4 | 4 | 163 | 163 |
| `/e:/github/vsr_dll_source/missions/vsrcore/gravityhelper.h` | 1 | 1 | 56 | 56 |
| `/e:/github/vsr_dll_source/missions/vsrcore/mathutils.cpp` | 18 | 18 | 529 | 529 |
| `/e:/github/vsr_dll_source/missions/vsrcore/mathutils.h` | 9 | 9 | 166 | 166 |
| `/e:/github/vsr_dll_source/missions/vsrcore/morphobjecthelper.cpp` | 8 | 8 | 577 | 577 |
| `/e:/github/vsr_dll_source/missions/vsrcore/morphobjecthelper.h` | 1 | 1 | 178 | 178 |
| `/e:/github/vsr_dll_source/missions/vsrcore/objecthelper.cpp` | 4 | 4 | 119 | 119 |
| `/e:/github/vsr_dll_source/missions/vsrcore/objecthelper.h` | 2 | 2 | 188 | 188 |
| `/e:/github/vsr_dll_source/missions/vsrcore/portalhelper.cpp` | 20 | 20 | 1985 | 1985 |
| `/e:/github/vsr_dll_source/missions/vsrcore/portalhelper.h` | 3 | 3 | 489 | 489 |
| `/e:/github/vsr_dll_source/missions/vsrcore/powerhelper.cpp` | 4 | 4 | 165 | 165 |
| `/e:/github/vsr_dll_source/missions/vsrcore/powerhelper.h` | 1 | 1 | 96 | 96 |
| `/e:/github/vsr_dll_source/missions/vsrcore/poweruphelper.cpp` | 4 | 4 | 192 | 192 |
| `/e:/github/vsr_dll_source/missions/vsrcore/poweruphelper.h` | 1 | 1 | 90 | 90 |
| `/e:/github/vsr_dll_source/missions/vsrcore/productionclasshelper.cpp` | 2 | 2 | 758 | 758 |
| `/e:/github/vsr_dll_source/missions/vsrcore/scraphelper.cpp` | 3 | 3 | 137 | 137 |
| `/e:/github/vsr_dll_source/missions/vsrcore/scraphelper.h` | 1 | 1 | 47 | 47 |
| `/e:/github/vsr_dll_source/missions/vsrcore/undeployhelper.cpp` | 4 | 4 | 301 | 301 |
| `/e:/github/vsr_dll_source/missions/vsrcore/undeployhelper.h` | 1 | 1 | 56 | 56 |
| `/e:/github/vsr_dll_source/missions/vsrcore/utilityshiphelper.cpp` | 6 | 6 | 366 | 366 |
| `/e:/github/vsr_dll_source/missions/vsrcore/utilityshiphelper.h` | 1 | 1 | 96 | 96 |
| `/e:/github/vsr_dll_source/missions/vsrcore/vehiclehelper.cpp` | 4 | 4 | 310 | 310 |
| `/e:/github/vsr_dll_source/missions/vsrcore/vehiclehelper.h` | 1 | 1 | 164 | 164 |
| `/e:/github/vsr_dll_source/source/fun3d/scriptutils.h` | 1 | 1 | 183 | 183 |

## 3. Strings (TerminatedCString)

old 2415 · new 2415 · added 0 · removed 0


## 4. Decompiled text (whitespace-normalized)

identical 731 · changed 222 · only in old 0 · only in new 0

| file | identical | changed |
|---|---:|---:|
| `missions/luamission/luabindings.cpp.decomp.c` | 437 | 79 |
| `missions/luamission/luamission.cpp.decomp.c` | 21 | 5 |
| `missions/shared/dllbase.cpp.decomp.c` | 42 | 3 |
| `missions/shared/dllutils.cpp.decomp.c` | 2 | 1 |
| `missions/shared/startingvehicles.cpp.decomp.c` | 3 | 1 |
| `missions/shared/taunts.cpp.decomp.c` | 3 | 1 |
| `missions/shared/trnallies.cpp.decomp.c` | 0 | 1 |
| `missions/strategy02/strategy02.cpp.decomp.c` | 13 | 21 |
| `missions/strategy02/strategy02.h.decomp.c` | 3 | 1 |
| `missions/vsrcore/aiweaponhelper.cpp.decomp.c` | 0 | 1 |
| `missions/vsrcore/ambientsoundhelper.cpp.decomp.c` | 2 | 2 |
| `missions/vsrcore/ambientsoundhelper.h.decomp.c` | 1 | 0 |
| `missions/vsrcore/attacherhelper.cpp.decomp.c` | 2 | 2 |
| `missions/vsrcore/attacherhelper.h.decomp.c` | 1 | 0 |
| `missions/vsrcore/buildinghelper.cpp.decomp.c` | 5 | 3 |
| `missions/vsrcore/buildinghelper.h.decomp.c` | 3 | 0 |
| `missions/vsrcore/bz1helper.cpp.decomp.c` | 22 | 15 |
| `missions/vsrcore/bz1helper.h.decomp.c` | 3 | 5 |
| `missions/vsrcore/bzcscriptutils.cpp.decomp.c` | 48 | 37 |
| `missions/vsrcore/bzcscriptutils.h.decomp.c` | 30 | 0 |
| `missions/vsrcore/carrierhelper.cpp.decomp.c` | 10 | 6 |
| `missions/vsrcore/carrierhelper.h.decomp.c` | 0 | 2 |
| `missions/vsrcore/dispatchhelper.cpp.decomp.c` | 5 | 6 |
| `missions/vsrcore/dispatchhelper.h.decomp.c` | 0 | 1 |
| `missions/vsrcore/gravityhelper.cpp.decomp.c` | 3 | 1 |
| `missions/vsrcore/gravityhelper.h.decomp.c` | 0 | 1 |
| `missions/vsrcore/mathutils.cpp.decomp.c` | 17 | 1 |
| `missions/vsrcore/mathutils.h.decomp.c` | 8 | 1 |
| `missions/vsrcore/morphobjecthelper.cpp.decomp.c` | 4 | 4 |
| `missions/vsrcore/morphobjecthelper.h.decomp.c` | 1 | 0 |
| `missions/vsrcore/objecthelper.cpp.decomp.c` | 3 | 1 |
| `missions/vsrcore/objecthelper.h.decomp.c` | 1 | 1 |
| `missions/vsrcore/portalhelper.cpp.decomp.c` | 13 | 7 |
| `missions/vsrcore/portalhelper.h.decomp.c` | 2 | 1 |
| `missions/vsrcore/powerhelper.cpp.decomp.c` | 3 | 1 |
| `missions/vsrcore/powerhelper.h.decomp.c` | 0 | 1 |
| `missions/vsrcore/poweruphelper.cpp.decomp.c` | 3 | 1 |
| `missions/vsrcore/poweruphelper.h.decomp.c` | 1 | 0 |
| `missions/vsrcore/productionclasshelper.cpp.decomp.c` | 0 | 2 |
| `missions/vsrcore/scraphelper.cpp.decomp.c` | 3 | 0 |
| `missions/vsrcore/scraphelper.h.decomp.c` | 1 | 0 |
| `missions/vsrcore/undeployhelper.cpp.decomp.c` | 4 | 0 |
| `missions/vsrcore/undeployhelper.h.decomp.c` | 0 | 1 |
| `missions/vsrcore/utilityshiphelper.cpp.decomp.c` | 4 | 2 |
| `missions/vsrcore/utilityshiphelper.h.decomp.c` | 0 | 1 |
| `missions/vsrcore/vehiclehelper.cpp.decomp.c` | 3 | 1 |
| `missions/vsrcore/vehiclehelper.h.decomp.c` | 0 | 1 |
| `source/fun3d/scriptutils.h.decomp.c` | 1 | 0 |

### Changed functions
- `LuaBindings::AddObjective` @ 4fc4fdd9 (missions/luamission/luabindings.cpp.decomp.c)
- `LuaBindings::AddToDispatch` @ 4fc527d7 (missions/luamission/luabindings.cpp.decomp.c)
- `LuaBindings::Add_Mult_Vectors` @ 4fc4a69f (missions/luamission/luabindings.cpp.decomp.c)
- `LuaBindings::BuildAxisRotationMatrix` @ 4fc504c5 (missions/luamission/luabindings.cpp.decomp.c)
- `LuaBindings::CameraPos` @ 4fc53e42 (missions/luamission/luabindings.cpp.decomp.c)
- `LuaBindings::CountThreats` @ 4fc4dbed (missions/luamission/luabindings.cpp.decomp.c)
- `LuaBindings::CrossProduct` @ 4fc4f2e6 (missions/luamission/luabindings.cpp.decomp.c)
- `LuaBindings::Distance2D` @ 4fc4fcf1 (missions/luamission/luabindings.cpp.decomp.c)
- `LuaBindings::Distance2DSquared` @ 4fc50ae3 (missions/luamission/luabindings.cpp.decomp.c)
- `LuaBindings::Distance3D` @ 4fc51b87 (missions/luamission/luabindings.cpp.decomp.c)
- `LuaBindings::Distance3DSquared` @ 4fc52b48 (missions/luamission/luabindings.cpp.decomp.c)
- `LuaBindings::DotProduct` @ 4fc4ca26 (missions/luamission/luabindings.cpp.decomp.c)
- `LuaBindings::Dropoff` @ 4fc4dab9 (missions/luamission/luabindings.cpp.decomp.c)
- `LuaBindings::FrontToDegrees` @ 4fc52de1 (missions/luamission/luabindings.cpp.decomp.c)
- `LuaBindings::FrontToRadian` @ 4fc50268 (missions/luamission/luabindings.cpp.decomp.c)
- `LuaBindings::GetAllGameObjectHandles` @ 4fc52751 (missions/luamission/luabindings.cpp.decomp.c)
- `LuaBindings::GetDistance` @ 4fc51f2f (missions/luamission/luabindings.cpp.decomp.c)
- `LuaBindings::GetFacingDirection` @ 4fc53010 (missions/luamission/luabindings.cpp.decomp.c)
- `LuaBindings::GetFacingDrection2D` @ 4fc4f985 (missions/luamission/luabindings.cpp.decomp.c)
- `LuaBindings::GetGroup` @ 4fc49858 (missions/luamission/luabindings.cpp.decomp.c)
- `LuaBindings::GetNearestEnemy` @ 4fc4b802 (missions/luamission/luabindings.cpp.decomp.c)
- `LuaBindings::GetNearestPerson` @ 4fc4a36d (missions/luamission/luabindings.cpp.decomp.c)
- `LuaBindings::GetNearestPowerup` @ 4fc4c09f (missions/luamission/luabindings.cpp.decomp.c)
- `LuaBindings::GetODFHexInt` @ 4fc5358a (missions/luamission/luabindings.cpp.decomp.c)
- `LuaBindings::GetODFString` @ 4fc4cdb9 (missions/luamission/luabindings.cpp.decomp.c)
- `LuaBindings::GetObjInfo_CFG` @ 4fc4d637 (missions/luamission/luabindings.cpp.decomp.c)
- `LuaBindings::GetObjInfo_EntityType` @ 4fc4ac66 (missions/luamission/luabindings.cpp.decomp.c)
- `LuaBindings::GetObjInfo_GOClass` @ 4fc4f3b4 (missions/luamission/luabindings.cpp.decomp.c)
- `LuaBindings::GetObjInfo_GOClass_gCfg` @ 4fc534f5 (missions/luamission/luabindings.cpp.decomp.c)
- `LuaBindings::GetObjInfo_ODF` @ 4fc539f0 (missions/luamission/luabindings.cpp.decomp.c)
- `LuaBindings::GetPathPoints` @ 4fc51cce (missions/luamission/luabindings.cpp.decomp.c)
- `LuaBindings::GetPositionNear` @ 4fc4bda6 (missions/luamission/luabindings.cpp.decomp.c)
- `LuaBindings::Get_WeaponConfig` @ 4fc4da15 (missions/luamission/luabindings.cpp.decomp.c)
- `LuaBindings::Get_WeaponGOClass` @ 4fc48f45 (missions/luamission/luabindings.cpp.decomp.c)
- `LuaBindings::Get_WeaponODF` @ 4fc4c5ad (missions/luamission/luabindings.cpp.decomp.c)
- `LuaBindings::GiveWeapon` @ 4fc5031f (missions/luamission/luabindings.cpp.decomp.c)
- `LuaBindings::Handle_ToString` @ 4fc4f33a (missions/luamission/luabindings.cpp.decomp.c)
- `LuaBindings::Interpolate_Matrix` @ 4fc4e691 (missions/luamission/luabindings.cpp.decomp.c)
- `LuaBindings::Interpolate_Quaternion` @ 4fc4b906 (missions/luamission/luabindings.cpp.decomp.c)
- `LuaBindings::IsInfo` @ 4fc4cc0d (missions/luamission/luabindings.cpp.decomp.c)
- `LuaBindings::IsNullVector` @ 4fc51135 (missions/luamission/luabindings.cpp.decomp.c)
- `LuaBindings::IsWithin` @ 4fc4b1ed (missions/luamission/luabindings.cpp.decomp.c)
- `LuaBindings::Length` @ 4fc536ba (missions/luamission/luabindings.cpp.decomp.c)
- `LuaBindings::LengthSquared` @ 4fc54201 (missions/luamission/luabindings.cpp.decomp.c)
- `LuaBindings::LoadValue` @ 4fc4cfb4 (missions/luamission/luabindings.cpp.decomp.c)
- `LuaBindings::Matrix_Inverse` @ 4fc542eb (missions/luamission/luabindings.cpp.decomp.c)
- `LuaBindings::Matrix_NewIndex` @ 4fc521ce (missions/luamission/luabindings.cpp.decomp.c)
- `LuaBindings::Matrix_to_QuatPos` @ 4fc4b63d (missions/luamission/luabindings.cpp.decomp.c)
- `LuaBindings::Matrix_to_Quaternion` @ 4fc51e91 (missions/luamission/luabindings.cpp.decomp.c)
- `LuaBindings::Normalize` @ 4fc51dd1 (missions/luamission/luabindings.cpp.decomp.c)
- `LuaBindings::Normalize_Quaternion` @ 4fc53da1 (missions/luamission/luabindings.cpp.decomp.c)
- `LuaBindings::QuatPos_to_Matrix` @ 4fc4d352 (missions/luamission/luabindings.cpp.decomp.c)
- `LuaBindings::Quaternion_Index` @ 4fc4d933 (missions/luamission/luabindings.cpp.decomp.c)
- `LuaBindings::Quaternion_Mul` @ 4fc5433c (missions/luamission/luabindings.cpp.decomp.c)
- `LuaBindings::Quaternion_ToString` @ 4fc52d3e (missions/luamission/luabindings.cpp.decomp.c)
- `LuaBindings::ReplaceWeapons` @ 4fc4a758 (missions/luamission/luabindings.cpp.decomp.c)
- `LuaBindings::RequireHandle` @ 4fc48e0d (missions/luamission/luabindings.cpp.decomp.c)
- `LuaBindings::RequireMatrix` @ 4fc48da4 (missions/luamission/luabindings.cpp.decomp.c)
- `LuaBindings::RequireQuaternion` @ 4fc48d88 (missions/luamission/luabindings.cpp.decomp.c)
- `LuaBindings::RequireVector` @ 4fc48df1 (missions/luamission/luabindings.cpp.decomp.c)
- `LuaBindings::SetCameraPosition` @ 4fc53f53 (missions/luamission/luabindings.cpp.decomp.c)
- `LuaBindings::SetGravity` @ 4fc524b8 (missions/luamission/luabindings.cpp.decomp.c)
- `LuaBindings::SetMatrix` @ 4fc54756 (missions/luamission/luabindings.cpp.decomp.c)
- `LuaBindings::SetOmega` @ 4fc5202d (missions/luamission/luabindings.cpp.decomp.c)
- `LuaBindings::SetQuaternion` @ 4fc54017 (missions/luamission/luabindings.cpp.decomp.c)
- `LuaBindings::SetVelocity` @ 4fc52a09 (missions/luamission/luabindings.cpp.decomp.c)
- `LuaBindings::Vector_Add` @ 4fc4c18f (missions/luamission/luabindings.cpp.decomp.c)
- `LuaBindings::Vector_Div` @ 4fc4c45d (missions/luamission/luabindings.cpp.decomp.c)
- `LuaBindings::Vector_Eq` @ 4fc53a86 (missions/luamission/luabindings.cpp.decomp.c)
- `LuaBindings::Vector_Mul` @ 4fc5389d (missions/luamission/luabindings.cpp.decomp.c)
- `LuaBindings::Vector_Neg` @ 4fc49c3c (missions/luamission/luabindings.cpp.decomp.c)
- `LuaBindings::Vector_Rotate` @ 4fc4b072 (missions/luamission/luabindings.cpp.decomp.c)
- `LuaBindings::Vector_RotateInv` @ 4fc4ae6c (missions/luamission/luabindings.cpp.decomp.c)
- `LuaBindings::Vector_Sub` @ 4fc4c810 (missions/luamission/luabindings.cpp.decomp.c)
- `LuaBindings::Vector_ToString` @ 4fc4fbea (missions/luamission/luabindings.cpp.decomp.c)
- `LuaBindings::Vector_Transform` @ 4fc4990f (missions/luamission/luabindings.cpp.decomp.c)
- `LuaBindings::Vector_TransformInv` @ 4fc4fad1 (missions/luamission/luabindings.cpp.decomp.c)
- `LuaBindings::WhoIsTargeting` @ 4fc52939 (missions/luamission/luabindings.cpp.decomp.c)
- `LuaPrint` @ 4fc54bc7 (missions/luamission/luabindings.cpp.decomp.c)
- `LuaMission::Load` @ 4fc47f3d (missions/luamission/luamission.cpp.decomp.c)
- `LuaMission::LuaMission` @ 4fc48bbe (missions/luamission/luamission.cpp.decomp.c)
- `LuaMission::PostLoad` @ 4fc47f1c (missions/luamission/luamission.cpp.decomp.c)
- `LuaMission::Save` @ 4fc47d92 (missions/luamission/luamission.cpp.decomp.c)
- `LuaMission::~LuaMission` @ 4fc48b57 (missions/luamission/luamission.cpp.decomp.c)
- `DLLBasePreGetInCallback` @ 4fc4070b (missions/shared/dllbase.cpp.decomp.c)
- `DLLBasePrePickupPowerupCallback` @ 4fc406e9 (missions/shared/dllbase.cpp.decomp.c)
- `DLLBasePreSnipeCallback` @ 4fc4074d (missions/shared/dllbase.cpp.decomp.c)
- `DLLUtils::IsRecycler` @ 4fc40876 (missions/shared/dllutils.cpp.decomp.c)
- `StartingVehicleManager::CreateVehicles` @ 4fc4095b (missions/shared/startingvehicles.cpp.decomp.c)
- `InitTaunts` @ 4fc090da (missions/shared/taunts.cpp.decomp.c)
- `TRNAllies::SetupTRNAllies` @ 4fc47061 (missions/shared/trnallies.cpp.decomp.c)
- `IsRecyclerODF` @ 4fc459c5 (missions/strategy02/strategy02.cpp.decomp.c)
- `Strategy02::AddObject` @ 4fc4616f (missions/strategy02/strategy02.cpp.decomp.c)
- `Strategy02::BuildStartingVehicle` @ 4fc458da (missions/strategy02/strategy02.cpp.decomp.c)
- `Strategy02::BuildStartingVehicle` @ 4fc4594d (missions/strategy02/strategy02.cpp.decomp.c)
- `Strategy02::DeadObject` @ 4fc417e7 (missions/strategy02/strategy02.cpp.decomp.c)
- `Strategy02::ExecuteCheckIfGameOver` @ 4fc43263 (missions/strategy02/strategy02.cpp.decomp.c)
- `Strategy02::ExecuteRecyInvulnerability` @ 4fc43854 (missions/strategy02/strategy02.cpp.decomp.c)
- `Strategy02::ExecuteST_Capture` @ 4fc40af6 (missions/strategy02/strategy02.cpp.decomp.c)
- `Strategy02::GetInitialPlayerPilotODF` @ 4fc45dc5 (missions/strategy02/strategy02.cpp.decomp.c)
- `Strategy02::GetInitialRecyclerODF` @ 4fc45d44 (missions/strategy02/strategy02.cpp.decomp.c)
- `Strategy02::GetSpawnpointForTeam` @ 4fc45a57 (missions/strategy02/strategy02.cpp.decomp.c)
- `Strategy02::Init` @ 4fc43b41 (missions/strategy02/strategy02.cpp.decomp.c)
- `Strategy02::PreGetIn` @ 4fc41614 (missions/strategy02/strategy02.cpp.decomp.c)
- `Strategy02::RespawnPilot` @ 4fc41be7 (missions/strategy02/strategy02.cpp.decomp.c)
- `Strategy02::Save` @ 4fc46776 (missions/strategy02/strategy02.cpp.decomp.c)
- `Strategy02::ScavengerManagementCode` @ 4fc413ca (missions/strategy02/strategy02.cpp.decomp.c)
- `Strategy02::SetCPUAIPlan` @ 4fc45f69 (missions/strategy02/strategy02.cpp.decomp.c)
- `Strategy02::SetupPlayer` @ 4fc44583 (missions/strategy02/strategy02.cpp.decomp.c)
- `Strategy02::SetupTeam` @ 4fc4512c (missions/strategy02/strategy02.cpp.decomp.c)
- `Strategy02::Strategy02` @ 4fc46ea4 (missions/strategy02/strategy02.cpp.decomp.c)
- `Strategy02::~Strategy02` @ 4fc46d77 (missions/strategy02/strategy02.cpp.decomp.c)
- `Strategy02::ShouldRemoveThugScavengerObject` @ 4fc01cdf (missions/strategy02/strategy02.h.decomp.c)
- `AIWeaponHelper::AIGiveWeapons` @ 4fc26132 (missions/vsrcore/aiweaponhelper.cpp.decomp.c)
- `AmbientSoundHelper::Execute` @ 4fc1434e (missions/vsrcore/ambientsoundhelper.cpp.decomp.c)
- `AmbientSoundHelper::Load` @ 4fc14017 (missions/vsrcore/ambientsoundhelper.cpp.decomp.c)
- `AttacherHelper::AddAttacherObject` @ 4fc19f7c (missions/vsrcore/attacherhelper.cpp.decomp.c)
- `AttacherHelper::Execute` @ 4fc1a485 (missions/vsrcore/attacherhelper.cpp.decomp.c)
- `BuildingHelper::AddBuildingObject` @ 4fc1dbee (missions/vsrcore/buildinghelper.cpp.decomp.c)
- `BuildingHelper::Execute` @ 4fc1e4a1 (missions/vsrcore/buildinghelper.cpp.decomp.c)
- `BuildingHelper::GetRandomBuilding` @ 4fc1f198 (missions/vsrcore/buildinghelper.cpp.decomp.c)
- `BZ1Helper::AddObject` @ 4fc0cbb6 (missions/vsrcore/bz1helper.cpp.decomp.c)
- `BZ1Helper::BZ1Helper` @ 4fc0b0c0 (missions/vsrcore/bz1helper.cpp.decomp.c)
- `BZ1Helper::BZ1Interface` @ 4fc0fdfc (missions/vsrcore/bz1helper.cpp.decomp.c)
- `BZ1Helper::BZ1Lives` @ 4fc102f5 (missions/vsrcore/bz1helper.cpp.decomp.c)
- `BZ1Helper::CheckBuildRequirements_RequireCount` @ 4fc117e4 (missions/vsrcore/bz1helper.cpp.decomp.c)
- `BZ1Helper::DeadObject` @ 4fc0fdaa (missions/vsrcore/bz1helper.cpp.decomp.c)
- `BZ1Helper::Execute` @ 4fc0f04b (missions/vsrcore/bz1helper.cpp.decomp.c)
- `BZ1Helper::GetNearestObject` @ 4fc11323 (missions/vsrcore/bz1helper.cpp.decomp.c)
- `BZ1Helper::Init` @ 4fc0e560 (missions/vsrcore/bz1helper.cpp.decomp.c)
- `BZ1Helper::Load` @ 4fc0b943 (missions/vsrcore/bz1helper.cpp.decomp.c)
- `BZ1Helper::PreSnipe` @ 4fc0f75a (missions/vsrcore/bz1helper.cpp.decomp.c)
- `BZ1Helper::ReplaceObject` @ 4fc11a43 (missions/vsrcore/bz1helper.cpp.decomp.c)
- `BZ1Helper::Setup` @ 4fc0eec7 (missions/vsrcore/bz1helper.cpp.decomp.c)
- `BZ1Helper::SetupClouds` @ 4fc105c7 (missions/vsrcore/bz1helper.cpp.decomp.c)
- `BZ1Helper::~BZ1Helper` @ 4fc0b66b (missions/vsrcore/bz1helper.cpp.decomp.c)
- `operator==` @ 4fc09ab1 (missions/vsrcore/bz1helper.h.decomp.c)
- `operator==` @ 4fc0ac7b (missions/vsrcore/bz1helper.h.decomp.c)
- `operator==` @ 4fc0ad6f (missions/vsrcore/bz1helper.h.decomp.c)
- `operator==` @ 4fc0ae15 (missions/vsrcore/bz1helper.h.decomp.c)
- `operator==` @ 4fc0af2d (missions/vsrcore/bz1helper.h.decomp.c)
- `CameraCircle` @ 4fc02a66 (missions/vsrcore/bzcscriptutils.cpp.decomp.c)
- `FileOpen` @ 4fc02d4b (missions/vsrcore/bzcscriptutils.cpp.decomp.c)
- `FormatConsoleMessage` @ 4fc02c53 (missions/vsrcore/bzcscriptutils.cpp.decomp.c)
- `FormatFileMessage` @ 4fc02e7f (missions/vsrcore/bzcscriptutils.cpp.decomp.c)
- `FormatLogMessage` @ 4fc03056 (missions/vsrcore/bzcscriptutils.cpp.decomp.c)
- `FormatToMessagesBox` @ 4fc031ab (missions/vsrcore/bzcscriptutils.cpp.decomp.c)
- `GetAndOpenODFNames` @ 4fc04ffe (missions/vsrcore/bzcscriptutils.cpp.decomp.c)
- `GetCenterOfMap` @ 4fc03479 (missions/vsrcore/bzcscriptutils.cpp.decomp.c)
- `GetNumWeapons` @ 4fc055ec (missions/vsrcore/bzcscriptutils.cpp.decomp.c)
- `GetODFBool` @ 4fc06710 (missions/vsrcore/bzcscriptutils.cpp.decomp.c)
- `GetODFChar` @ 4fc06528 (missions/vsrcore/bzcscriptutils.cpp.decomp.c)
- `GetODFColor` @ 4fc06af2 (missions/vsrcore/bzcscriptutils.cpp.decomp.c)
- `GetODFFloat` @ 4fc061c5 (missions/vsrcore/bzcscriptutils.cpp.decomp.c)
- `GetODFInt` @ 4fc05df5 (missions/vsrcore/bzcscriptutils.cpp.decomp.c)
- `GetODFLong` @ 4fc05fdd (missions/vsrcore/bzcscriptutils.cpp.decomp.c)
- `GetODFString` @ 4fc068f8 (missions/vsrcore/bzcscriptutils.cpp.decomp.c)
- `GetODFVector` @ 4fc06cda (missions/vsrcore/bzcscriptutils.cpp.decomp.c)
- `GetObjectByBaseSlot` @ 4fc03b28 (missions/vsrcore/bzcscriptutils.cpp.decomp.c)
- `GetPilotCost` @ 4fc05449 (missions/vsrcore/bzcscriptutils.cpp.decomp.c)
- `GetScrapCost` @ 4fc054d2 (missions/vsrcore/bzcscriptutils.cpp.decomp.c)
- `GetScrapValue` @ 4fc0555b (missions/vsrcore/bzcscriptutils.cpp.decomp.c)
- `GetVectorFromPath` @ 4fc033be (missions/vsrcore/bzcscriptutils.cpp.decomp.c)
- `GetWindingNumber` @ 4fc0369e (missions/vsrcore/bzcscriptutils.cpp.decomp.c)
- `GetWindingNumber` @ 4fc03774 (missions/vsrcore/bzcscriptutils.cpp.decomp.c)
- `GetWorldVariantODF` @ 4fc0537f (missions/vsrcore/bzcscriptutils.cpp.decomp.c)
- `IsArmory` @ 4fc04cc5 (missions/vsrcore/bzcscriptutils.cpp.decomp.c)
- `IsBuildingOrGunTower` @ 4fc04a35 (missions/vsrcore/bzcscriptutils.cpp.decomp.c)
- `IsConstructor` @ 4fc04d66 (missions/vsrcore/bzcscriptutils.cpp.decomp.c)
- `IsCraft` @ 4fc04ac7 (missions/vsrcore/bzcscriptutils.cpp.decomp.c)
- `IsFactory` @ 4fc04c24 (missions/vsrcore/bzcscriptutils.cpp.decomp.c)
- `IsMisc` @ 4fc04bbc (missions/vsrcore/bzcscriptutils.cpp.decomp.c)
- `IsRecycler` @ 4fc02393 (missions/vsrcore/bzcscriptutils.cpp.decomp.c)
- `IsServiceTruck` @ 4fc04dd6 (missions/vsrcore/bzcscriptutils.cpp.decomp.c)
- `IsWeapon` @ 4fc04b54 (missions/vsrcore/bzcscriptutils.cpp.decomp.c)
- `OpenLogFile` @ 4fc02f09 (missions/vsrcore/bzcscriptutils.cpp.decomp.c)
- `PlayVOMsg` @ 4fc04881 (missions/vsrcore/bzcscriptutils.cpp.decomp.c)
- `ReplaceWeapons` @ 4fc07248 (missions/vsrcore/bzcscriptutils.cpp.decomp.c)
- `CarrierHelper::AddCarrierDroneObject` @ 4fc1808e (missions/vsrcore/carrierhelper.cpp.decomp.c)
- `CarrierHelper::DroneRecall` @ 4fc1906b (missions/vsrcore/carrierhelper.cpp.decomp.c)
- `CarrierHelper::Execute` @ 4fc1852f (missions/vsrcore/carrierhelper.cpp.decomp.c)
- `CarrierHelper::Load` @ 4fc17dea (missions/vsrcore/carrierhelper.cpp.decomp.c)
- `CarrierHelper::Save` @ 4fc17feb (missions/vsrcore/carrierhelper.cpp.decomp.c)
- `CarrierHelper::~CarrierHelper` @ 4fc17dd0 (missions/vsrcore/carrierhelper.cpp.decomp.c)
- `operator==` @ 4fc17a45 (missions/vsrcore/carrierhelper.h.decomp.c)
- `operator==` @ 4fc17bda (missions/vsrcore/carrierhelper.h.decomp.c)
- `DispatchHelper::AddToDispatch` @ 4fc1fef3 (missions/vsrcore/dispatchhelper.cpp.decomp.c)
- `DispatchHelper::Cloak` @ 4fc23a78 (missions/vsrcore/dispatchhelper.cpp.decomp.c)
- `DispatchHelper::Decloak` @ 4fc23b5d (missions/vsrcore/dispatchhelper.cpp.decomp.c)
- `DispatchHelper::DeleteDispatchObject` @ 4fc2084b (missions/vsrcore/dispatchhelper.cpp.decomp.c)
- `DispatchHelper::Execute` @ 4fc208a9 (missions/vsrcore/dispatchhelper.cpp.decomp.c)
- `DispatchHelper::~DispatchHelper` @ 4fc1fe21 (missions/vsrcore/dispatchhelper.cpp.decomp.c)
- `operator==` @ 4fc1f889 (missions/vsrcore/dispatchhelper.h.decomp.c)
- `GravityHelper::Load` @ 4fc15d1a (missions/vsrcore/gravityhelper.cpp.decomp.c)
- `operator==` @ 4fc15c5b (missions/vsrcore/gravityhelper.h.decomp.c)
- `GetRandomFloat` @ 4fc13ddd (missions/vsrcore/mathutils.cpp.decomp.c)
- `GetDistance3DSquared` @ 4fc160a1 (missions/vsrcore/mathutils.h.decomp.c)
- `MorphObjectHelper::AddMorphObjectToggleObject` @ 4fc167a0 (missions/vsrcore/morphobjecthelper.cpp.decomp.c)
- `MorphObjectHelper::Execute` @ 4fc168ca (missions/vsrcore/morphobjecthelper.cpp.decomp.c)
- `MorphObjectHelper::PrePickupPowerup` @ 4fc1762e (missions/vsrcore/morphobjecthelper.cpp.decomp.c)
- `MorphObjectHelper::~MorphObjectHelper` @ 4fc164e8 (missions/vsrcore/morphobjecthelper.cpp.decomp.c)
- `ObjectHelper::Execute` @ 4fc24f8e (missions/vsrcore/objecthelper.cpp.decomp.c)
- `operator==` @ 4fc24c01 (missions/vsrcore/objecthelper.h.decomp.c)
- `PortalHelper::AddPortalObject` @ 4fc27c26 (missions/vsrcore/portalhelper.cpp.decomp.c)
- `PortalHelper::Execute` @ 4fc284f1 (missions/vsrcore/portalhelper.cpp.decomp.c)
- `PortalHelper::ExecuteObject` @ 4fc28fec (missions/vsrcore/portalhelper.cpp.decomp.c)
- `PortalHelper::Load` @ 4fc278a9 (missions/vsrcore/portalhelper.cpp.decomp.c)
- `PortalHelper::Save` @ 4fc27ace (missions/vsrcore/portalhelper.cpp.decomp.c)
- `PortalHelper::SetPortalDest` @ 4fc2a361 (missions/vsrcore/portalhelper.cpp.decomp.c)
- `PortalHelper::SetPortalEffectStart_Internal` @ 4fc29eeb (missions/vsrcore/portalhelper.cpp.decomp.c)
- `operator==` @ 4fc27708 (missions/vsrcore/portalhelper.h.decomp.c)
- `PowerHelper::Execute` @ 4fc1499e (missions/vsrcore/powerhelper.cpp.decomp.c)
- `operator==` @ 4fc145f9 (missions/vsrcore/powerhelper.h.decomp.c)
- `PowerupHelper::Execute` @ 4fc2596c (missions/vsrcore/poweruphelper.cpp.decomp.c)
- `ProductionClassHelper::AddProductionClassObject` @ 4fc1b92e (missions/vsrcore/productionclasshelper.cpp.decomp.c)
- `ProductionClassHelper::Execute` @ 4fc1bf02 (missions/vsrcore/productionclasshelper.cpp.decomp.c)
- `operator==` @ 4fc1c76c (missions/vsrcore/undeployhelper.h.decomp.c)
- `UtilityShipHelper::Execute` @ 4fc15490 (missions/vsrcore/utilityshiphelper.cpp.decomp.c)
- `UtilityShipHelper::GetEscortTarget` @ 4fc156ca (missions/vsrcore/utilityshiphelper.cpp.decomp.c)
- `operator==` @ 4fc14e5a (missions/vsrcore/utilityshiphelper.h.decomp.c)
- `VehicleHelper::Execute` @ 4fc24243 (missions/vsrcore/vehiclehelper.cpp.decomp.c)
- `operator==` @ 4fc23eb2 (missions/vsrcore/vehiclehelper.h.decomp.c)

