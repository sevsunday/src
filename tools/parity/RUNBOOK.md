# tools/parity/RUNBOOK.md — proving behavioural parity (QA gate 8)

BZCC is lockstep: every machine in a session simulates the same turns from the same inputs and
compares a per-turn CRC. If GBD's DLL runs on one machine and ours on another, any behavioural
difference in the simulation shows up as a `CRC Mismatch` / resync within seconds. That is the
final test. The mechanical gates run first so a game is only launched once the cheap checks pass.

## 0. Pre-flight (mechanical, every time)

```
build\build.cmd                       rem all four DLLs, zero warnings, layout asserts
build\build.cmd check                 rem gates 2-5: no-third-party, status, symbols, strings
python tools\check_symbol_parity.py --strict
python tools\check_strings.py --strict
```

`reference\manifest\parity\<dll>.symbols.md` and `.strings.md` list every difference; each one is
either fixed or explained in `STATUS.md` and allow-listed in `tools\parity\symbol_allow.txt` /
`strings_allow.txt`. Also compare the export table and CRT family:

```
dumpbin /exports out\Win32\Release\bin\missions\Strategy02.dll      rem exactly GetMisnAPI
dumpbin /dependents out\Win32\Release\bin\missions\Strategy02.dll   rem battlezone2.exe, KERNEL32, VCRUNTIME140, MSVCP140, api-ms-win-crt-*
```

## 0b. Lessons from the first sessions (2026-10-29/30) — read before setting up

- **The DLL loads when the map starts, not in the lobby.** A lock test in the lobby shows every copy
  free; run it in-game. Console variables typed in the lobby *should* therefore reach the DLL's
  constructor — but a session `ivarN` set from the console did **not** (`ivar115 = 1` echoed `1` and
  `Logging` still read false). The per-machine `network.session.civar5 1`, set at the main menu or in
  the lobby on **each** machine, does work (the host's `VSR_*.log` then opens with
  `Game Started on map: … Version: 20185`). Use `civar5`, not `ivar115`.
- **`My Games\Battlezone Combat Commander` may be a OneDrive folder shared by both machines.** On
  this operator's PCs it was: the override DLL copied on B synced to A within minutes, so the first
  "A/B" was ours on both ends (`AddDirRecurse ** Adding Recurse …\addon` instead of `(EMPTY)` on A).
  Before a session either disable OneDrive sync on the machine that must run GBD's DLL or exclude the
  `addon` folder from sync there, and read `Executed by <MACHINE>\<user>` in every engine log to know
  which machine wrote it — OneDrive tags same-second collisions `-<MACHINE>`.
- **Prove which DLL loaded with an open-for-write test, in-game, on BOTH machines.** Renaming is not
  a test (Windows lets a mapped DLL be renamed), module enumeration is hidden by the exe's protection
  layer, and a missing path must not be reported as locked (`FileNotFoundException` is an
  `IOException`). The script below is the corrected one. Expected: on the GBD machine the Workshop
  copy is `LOCKED` and the override path `absent`; on ours the override copy is `LOCKED`.

```powershell
$docs = [Environment]::GetFolderPath('MyDocuments')   # follows a Documents redirect
$paths = @(
  "$docs\My Games\Battlezone Combat Commander\addon\missions\Strategy02.dll",
  "C:\Program Files (x86)\Steam\steamapps\workshop\content\624970\1325933293\VSR\Missions\Strategy02.dll",
  "C:\Program Files (x86)\Steam\steamapps\common\BZ2R\Missions\Strategy02.dll"
)
foreach ($p in $paths) {
  if (-not (Test-Path -LiteralPath $p)) { "absent  $p"; continue }
  try { $f = [IO.File]::Open($p, 'Open', 'ReadWrite', 'None'); $f.Close(); "free    $p" }
  catch [System.UnauthorizedAccessException] { "denied  $p   (ACL - run elevated)" }
  catch [System.IO.IOException] {
    $code = $_.Exception.HResult -band 0xFFFF
    if ($code -eq 32 -or $code -eq 1224) { "LOCKED  $p   <- loaded (win32 $code)" }
    else { "error   $p   ($($_.Exception.Message))" }
  }
}
```

- **The engine's own tells.** `AddDirRecurse ** Adding (EMPTY) Recurse …\addon` vs `** Adding Recurse`
  at launch says whether an override folder was seen; `Started/Finished LoadGame Type RequestSTJoinLoad`
  runs on *both* sides of a join and `-- Resynchronized gamestate to server at timestep N` on the client
  — N = 1 is the join itself, N ≫ 1 mid-game is the divergence signal (the word `CRC` may never appear);
  `[Mission] Entering run code [SUCCESS]` on the host is the DLL's game-over path; a clean exit renames
  `Battlezone-Crashed <ts>.log` to `Battlezone <ts>.log` and ends with `System shutdown normally`.
- **The DLL's `VSR_*.log` join reports are baseline, not failures.** On every join both DLLs write a
  `PostLoad` resync report: the host's file has the `Init` block, then 10 `… Index Mismatch` lines at
  game time `+0.05` (same object count, handles one generation stale); the client's has 12 lines at
  `-0.05` (`Size Mismatch` 3→55 / 3→5 / 0→48 / 0→45, `NumTeamObjects: -44 and 44`). They are written
  whether or not logging is on. What would matter is a report at a game time well past 0.
- **Version.** The community plays the Steam `devtest` beta (2.0.206.10, buildid 25009108), not 2.0.185;
  test on it — both machines on the identical build, whichever it is. Switching the build machine's
  branch replaces the SDK files in the game folder (see `DEPENDENCIES.md` D5).

## 1. Save-record sizes

`Strategy02::Save` writes `b_count` bools, `f_count` floats, `h_count` handles and `i_count` ints
from the `*_first`/`*_last` anchored ranges; `BZ1Helper` does the same for its own ranges and for
`TeamInfo[16]` (`TEAMINFO MISMATCH: <field>` strings audit the field order on load). The layout
asserts already pin every anchor offset; after porting `Save`/`Load`, additionally:

1. Host a game with ours, save (`F5`-style mission save or the MP save), note the `.sav` size.
2. Same map, same settings, original DLL: the `.sav` size must match byte for byte in length.
3. Load each save with the other DLL: both must load without a `*LIST MISMATCH` / `TEAMINFO MISMATCH`
   line in `VSR_<timestamp>.log`.

## 2. Log-string parity

Enable DLL logging (`network.session.civar5 1` in the console on each machine before the map starts — a
console-set `ivar115` did not reach the DLL, §0b) and compare the
`<My Games>\Battlezone Combat Commander\logs\VSR_<timestamp>.log` produced by each DLL for the same
scripted session (host, one map, 60 s, no input). Every line present with the original must be
present with ours, same order; extra lines are investigated.

## 3. Lockstep A/B (needs a second machine — operator-supplied)

Setup:

- Machine A: BZCC (the build the community plays — 2.0.206.10 `devtest` as of 2026-10-30; both machines
  on the identical build) + the nine Workshop items (DEPENDENCIES.md D9), **original** DLLs (nothing to
  do — the Workshop copy; hash it against `original/missions/SHA256SUMS.txt` first) and **no**
  `addon\missions\<dll>` under its `My Games` folder (`(EMPTY)` in the engine log).
- Machine B: same, plus ours in the user addon override:
  `%USERPROFILE%\Documents\My Games\Battlezone Combat Commander\addon\missions\<dll>` (the
  override folder is read first; verified in `build\stub\LOADTEST.md`; on this machine Documents is
  OneDrive-redirected). Copy the `.pdb` beside it so a crash dump resolves.
- Both: windowed mode, same mod (VSR), both run the game once so the user folder exists.

Procedure per DLL and per map:

1. A hosts a LAN Strategy (Strategy02 / LuaMission) or Deathmatch (deathmatch01) game; for Instant
   there is no lockstep — run the same Instant Action map on both and compare the `VSR_*.log` and
   the end-of-mission state instead.
2. B joins; A launches the map. Once in-game, **both** run the lock test from §0b (the Workshop copy
   must be the only `LOCKED` file on A, the override copy on B) — module enumeration does not work.
3. Play the agreed script (recorded as `tools\parity\scripts\<map>.md`: build order, 10 minutes,
   include one of each of: thug scavenger deposit, pilot respawn, camera pod, morph tank deploy,
   portal use where the map has one, recycler death → game over).
4. Any `CRC Mismatch` message, resync, or desync kick is a FAIL for that DLL; note the game time
   and what happened just before it (the divergent function is usually the one that ran that turn).
5. Repeat with the roles swapped (A ours, B original) so host-only code paths run under both.

Maps (from the Workshop items), at least:

| Mode | Maps |
|---|---|
| Strategy | `vsroverlook` (used for the task-4 load test), one Vearidons map, one Appel map, one ST:Capture map (`ivar53 = 4`), one MPI map (`ivar12 = 1`, `Enemy_%d` spawns) |
| Deathmatch | `dmcubes`, `pyramid` |
| Instant | `chilli`, `dunesi` |

Record results in `STATUS.md` → "Parity results" (per DLL: gates, lockstep, maps tested, date, build,
machines, hashes of both DLLs, lock-test results). Keep the session logs under `out\parity-logs\<date>\`
(gitignored; one folder per run and machine, engine log + `VSR_*.log`); quote line numbers, never paste
whole logs into the repo. Pin the exact binary + PDB that was tested / deployed under
`tools\_local\deployed\<date>\` with a `SHA256SUMS.txt` — `out\` is overwritten by the next build.

**Done so far:** `Strategy02.dll`, `vsroverlook`, team strat 1v1, both roles, 2026-10-29/30 — pass
(`STATUS.md` → Lockstep A/B record). Scope decision 2026-10-30: team strat only; `LuaMission`,
`Instant`, `deathmatch01` and the FFA / MPI / Capture paths are not lockstep-tested.

## 4. Footprint rule

The only thing written outside this repo during a test is the DLL (+ PDB) in the addon override
folder; it is removed after the session. The Steam install is never modified.
