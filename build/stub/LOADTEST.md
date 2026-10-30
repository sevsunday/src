# Toolchain proof — stub Strategy02.dll load test (task 4)

Date: 2026-10-28. Build machine = test machine.

## What was built

`build\build.cmd stub` → `out\Win32\Release\bin\stub\Strategy02.dll`
(9,728 bytes, SHA-256 `c3466c14141c927b0f4468ee764285198d9c54d235e42c8fe39f8042836f1a09`)
from `stub_strategy02.cpp` against `%BZCC_DIR%\ScriptUtils.h` + `battlezone2.lib`.

- MSVC 19.44.35222 for x86 (VS 2022 17.14, toolset 14.44.35207), Windows SDK 10.0.26100.0.
- Flags: `/MD /O2 /Oy- /std:c++17 /W4 /Zi` — zero warnings in our code
  (`/wd4471` silences one SDK-header warning). Link: `/DLL /MACHINE:X86 /BASE:0x4FC00000`.
- `dumpbin /exports`: one export, `GetMisnAPI = _GetMisnAPI`.
- `dumpbin /dependents`: `battlezone2.exe`, `KERNEL32.dll`, `VCRUNTIME140.dll`,
  `api-ms-win-crt-runtime-l1-1-0.dll` — the same CRT family GBD's DLLs import.

## What the originals told us (corrections to the plan)

`dumpbin` on `original/missions/*.dll` (all four):

| Property | Value |
|---|---|
| Linker | 14.16 (Visual Studio 2017 15.9) |
| CRT | **dynamic**: `MSVCP140.dll`, `VCRUNTIME140.dll`, `api-ms-win-crt-*` (→ `/MD`, not `/MT`) |
| Image base | `0x4FC00000` on every DLL (matches the decompile's VAs) |
| DLL characteristics | `0x140` = DYNAMIC_BASE + NX_COMPAT |
| Subsystem | Windows GUI |
| Export | `GetMisnAPI` only |

`build.cmd` was changed from `/MT` to `/MD` and gained `/BASE:0x4FC00000`.

## How it was loaded

The engine's own log shows the search path: `Config: 'AddDirRecurse' :: '@mydocsdir\addon'`
is added **before** the Workshop content (`AddLocalWorkshopDirRecurse 'VSR'`). On this
machine `@mydocsdir` is the (OneDrive-redirected) Documents folder's
`My Games\Battlezone Combat Commander`. The `addon`
folder did not exist before the test (`(EMPTY)` in the previous session's log).

1. Operator exited BZCC.
2. Stub copied to `…\addon\missions\Strategy02.dll` (+ `.pdb`); hash re-checked after copy.
3. `steam.exe -applaunch 624970`; log confirmed `AddDirRecurse ** Adding Recurse …\addon`
   (no longer `(EMPTY)`).
4. Operator hosted a LAN Strategy session ("test") on `vsroverlook.bzn`, recycler variant
   "VSR BZCC", and started it.

## Evidence

- **Module lock**: while in-game, `…\addon\missions\Strategy02.dll` could not be opened for
  write (image-mapped), while the Workshop `…\1325933293\VSR\Missions\Strategy02.dll`,
  the Workshop `LuaMission.dll` and the stock `BZ2R\Missions\Strategy02.dll` all could.
  Only our DLL was loaded. (External module enumeration of the game process returns
  just 7 modules — consistent with the exe's protection layer — so the lock test is the
  reliable check.)
- **Console** (`loadtest-2026-10-28.jpg`):
  `[VSR_DLL_Source] stub Strategy02.dll loaded: GetMisnAPI OK` — the stub's `InitialSetup`
  ran. The player's vehicle was built (stub `AddPlayer`); no recycler (expected — the stub
  has no game logic). Engine note `FIXME: 'active' team 6 couldn't find user` is the
  engine reacting to the absent team setup, not an error in the DLL.
- **No crash**: `[Mission] Entering run code [RUN]` … `[Main] Entering run code [QUIT]` …
  `System shutdown normally`; the log was renamed from `Battlezone-Crashed …` to
  `Battlezone …` on exit.

## Cleanup

Stub and `.pdb` deleted after the game exited; `addon\missions` and `addon` removed
(neither existed before). The Steam install was never touched.

## Verdict

Toolchain proven: SDK + MSVC x86 compile the game's header, link against `battlezone2.lib`,
produce a DLL with the right export and version magic, and the engine loads it from the
user addon override folder and runs a VSR map on it.
