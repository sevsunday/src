# LuaMission.dll — symbol parity (tools/check_symbol_parity.py)

GBD: 843 project functions (+95 Lua/CRT/STL). Ours: 824 (+708).
missing 30 · extra 11 · moved 2 · allow-listed 43

## Missing (in GBD's, not in ours) — 30

### BZ1Helper.obj
- `bool __cdecl BZ1Helper::ShouldRemoveAlignTerrainReplace(const BZ1Helper::AlignTerrainReplaceClass&)`
- `bool __cdecl BZ1Helper::ShouldRemoveDeleteAfterDelay(const BZ1Helper::DeleteAfterDelayClass&)`
- `int __thiscall BuildingHelper::GetNumBuildingObjects()`
- `int __thiscall ObjectHelper::GetNumHandles()`

### BZCScriptUtils.obj
- `bool __cdecl IsEmpty(const int)`
- `const bool __cdecl close_enough(const float&, const float&, const float)`

### BuildingHelper.obj
- `bool __cdecl BuildingHelper::ShouldRemoveBuilding(const BuildingHelper::BuildingClass&)`

### CarrierHelper.obj
- `bool __cdecl CarrierHelper::ShouldRemoveCarrier(const CarrierHelper::CarrierClass&)`
- `bool __cdecl CarrierHelper::ShouldRemoveDrone(const CarrierHelper::DroneClass&)`

### DispatchHelper.obj
- `bool __cdecl DispatchHelper::ShouldRemoveDispatch(const DispatchHelper::DispatchClass&)`
- `Vector __cdecl GetPositionNearOrFar(const int, const int, const float, const float, const bool)`
- `int __thiscall ScrapHelper::GetNumScrapObjects()`

### LuaBindings.obj
- `float __cdecl GetDistance3DSquared(const Vector&, const Vector&)`
- `Vector __cdecl GetPosition(int)`
- `int __cdecl LuaBindings::GetHandle(lua_State*, int)`
- `Matrix* __cdecl LuaBindings::GetMatrix(lua_State*, int)`
- `Quaternion* __cdecl LuaBindings::GetQuaternion(lua_State*, int)`
- `Vector* __cdecl LuaBindings::GetVector(lua_State*, int)`
- `Matrix* __cdecl LuaBindings::RequireMatrix(lua_State*, int)`
- `Quaternion* __cdecl LuaBindings::RequireQuaternion(lua_State*, int)`
- `Vector* __cdecl LuaBindings::RequireVector(lua_State*, int)`

### MorphObjectHelper.obj
- `bool __cdecl MorphObjectHelper::ShouldRemoveMorphObject(const MorphObjectHelper::MorphObjectClass&)`

### ObjectHelper.obj
- `bool __cdecl ObjectHelper::ShouldRemoveObject(const ObjectHelper::ObjectClass&)`

### PortalHelper.obj
- `void __thiscall PortalHelper::SetPortalEffectVeh_Internal(const int, const Matrix, const int, const int)`

### PowerupHelper.obj
- `bool __cdecl PowerupHelper::ShouldRemovePowerup(const PowerupHelper::PowerupClass&)`

### ScrapHelper.obj
- `bool __cdecl ScrapHelper::ShouldRemoveScrap(const ScrapHelper::ScrapClass&)`

### Taunts.obj
- `void __cdecl SetTauntCPUName(const char*)`

### UndeployHelper.obj
- `bool __cdecl UndeployHelper::ShouldRemoveUndeployObject(const UndeployHelper::UndeployClass&)`

### UtilityShipHelper.obj
- `bool __cdecl UtilityShipHelper::ShouldRemoveUtilityShip(const UtilityShipHelper::UtilityShipClass&)`

### VehicleHelper.obj
- `bool __cdecl VehicleHelper::ShouldRemoveVehicle(const VehicleHelper::VehicleClass&)`

## Extra (in ours, not in GBD's) — 11

### attacherhelper.obj
- `bool __thiscall AttacherHelper::Load(bool)`

### buildinghelper.obj
- `bool __thiscall BuildingHelper::Load(bool)`

### dispatchhelper.obj
- `bool __thiscall DispatchHelper::Load(bool)`

### morphobjecthelper.obj
- `bool __thiscall MorphObjectHelper::Load(bool)`

### objecthelper.obj
- `bool __thiscall ObjectHelper::Load(bool)`

### portalhelper.obj
- `void __thiscall PortalHelper::SetPortalEffectVeh_Internal(const int, const int, const int, const Matrix)`
- `void __thiscall PortalHelper::~PortalHelper()`

### powerhelper.obj
- `bool __thiscall PowerHelper::Load(bool)`

### poweruphelper.obj
- `bool __thiscall PowerupHelper::Load(bool)`

### utilityshiphelper.obj
- `bool __thiscall UtilityShipHelper::Load(bool)`

### vehiclehelper.obj
- `bool __thiscall VehicleHelper::Load(bool)`

## Moved (different module) — 2

### BZCScriptUtils.obj
- `const bool __cdecl close_enough(const Vector&, const Vector&, const float)`  (ours: buildinghelper.obj)

### LuaMission.obj
- `void __thiscall Matrix::Matrix(const Vector, const Vector, const Vector, const Vector)`  (ours: luabindings.obj)

