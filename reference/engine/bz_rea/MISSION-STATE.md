# Mission state, compatibility stubs and scoreboard access

<!-- procedure-contracts: 0xd5e8b 0xd5e7c 0xd5fbd 0xd5b05 0xd5aff 0xd5ae7 0xd5af1 0xd5b0b 0xd5ae1 0xd5aeb 0xd5f26 0xd5bc4 0xd4242 0xd5f09 0xd5fd6 0xd6174 0xd5ce6 0xd5ce9 0xd498c 0xd593a 0xd532f 0x1683f0 0xd5ee9 0xd5ec9 0xd5ea9 0x156c88 0x1d5ec1 0x1d5edd 0x1d5ef9 0x1d5f49 0x1d5f99 0x1d6049 0x1d60a9 0x100a2 0x18099e 0x1df39d 0x182705 0x1de736 0x1de745 0x1de754 -->

This page describes **25 exported functions and 15 internal helpers** in the
recorded public **2.0.185** capture. It adds native contracts to declarations
whose SDK entries have no explanatory comment. Signatures and export rows stay
in the [API reference](API-REFERENCE.md); world scheduling remains open in the
[research plan](RESEARCH-PLAN.md).

All code locations below are **RVAs in the recorded capture**, SHA-256
`b3f07e6ca3d6a53f2dcdb2b2b2d9875d75cc3c30e25a36e921e78d23d06ee2c7`,
image base `0xde0000`. Data addresses explicitly marked **VA** use that base.
The [carrier rules](BINARY-CARRIERS.md) apply. These are static instruction
observations, without a new game run. Descriptive helper names are authored
labels, not recovered C++ symbols.

## Direct state reads and compatibility stubs

These functions have no nested call, allocation, handle validation or refresh.
The direct getters return the stored value at the time of the call. Their
writers, valid enum domains and initialization order are not established here.

| Function | RVA | Native contract |
| --- | --- | --- |
| `GetCurWorld()` | `0xd5fbd` | Returns the DWORD at VA `0x123d730` in `EAX`. The scoreboard write paths below permit mutation only when this value is zero. This read alone does not identify every nonzero world's role. |
| `GetInstantType()` | `0xd5aeb` | Returns the DWORD at VA `0x126b318`, unchanged. |
| `GetInstantDifficulty()` | `0xd5aff` | Returns the DWORD at VA `0x126b31c`, unchanged. |
| `GetInstantCompForce()` | `0xd5b05` | Returns the DWORD at VA `0x126b320`, unchanged. |
| `GetInstantMySide()` | `0xd5ae1` | Returns the DWORD at VA `0x126b324`, unchanged. |
| `GetInstantMyForce()` | `0xd5b0b` | Returns the DWORD at VA `0x126b328`, unchanged. |
| `GetInstantFlag()` | `0xd5ae7` | Always returns integer **2** (`PUSH 2; POP EAX; RET`). It reads no Instant Action option. |
| `GetInstantGoal()` | `0xd5af1` | Reads the signed DWORD at VA `0x123d58c`; returns **1** if negative, otherwise the original value. Zero is preserved. This is a negative-value fallback, not a minimum-one clamp. |
| `GetLocalPlayerDPID()` | `0xd5bc4` | Returns the DWORD at VA `0x123d9f4`, unchanged. There is no connection-state check in the wrapper. |
| `GetLocalUserSelectHandle()` | `0xd4242` | Returns the DWORD at VA `0x1290e0c`, unchanged; it does not resolve or validate the handle. |
| `ImServer()` | `0xd5ce9` | Returns the byte at VA `0x129aa0d` in `AL`; upper `EAX` bits are not defined by this body. |
| `IsTeamplayOn()` | `0xd498c` | Returns the byte at VA `0x129aa29` in `AL`; upper `EAX` bits are not defined by this body. |
| `ImDedicatedServer()` | `0xd5ce6` | Always returns false (`XOR AL,AL; RET`). It performs no dedicated-server detection in this build. |
| `LogFloat(float)` | `0xd593a` | A single `RET`. No argument read, logging, formatting or side effect. |
| `PurgeMusicMessage(...)` | `0x1683f0` | A single `RET`. No purge occurs in this exported body. |

The constants and empty bodies are version-specific compatibility behavior.
An exported name or a historical SDK declaration would not reveal these
results. C++ `bool` callers consume `AL`; assembly must not test all of `EAX`
for the three boolean functions above (see the existing
[native command ABI](../DEVELOPMENT.md#native-command-abi)).

## Scoreboard object and player lookup

The following internal chain explains both invalid-handle behavior and the
scope of score updates. It also supplies useful partial data layouts.

| Helper | RVA | Input and result |
| --- | --- | --- |
| Handle filter | `0x156c88` | Calls VA `0xfd0eb1` with the incoming `ECX`. Null returns null. Otherwise invokes the object's vtable slot at byte offset `+0x60`; false in `AL` returns null, true returns the original pointer. The predicate's semantic name and the upstream resolver remain unproved. |
| Player-key lookup | `0x1df39d` | Scans the array at VA `0x129aa54` for `record[+0] == ECX`, using signed count at VA `0x129aa58` and stride `0xf70`. Returns the first index, or **`0xa5a5a5a5`** if none/count nonpositive. The miss sentinel is negative as a signed 32-bit integer. |
| Kills read | `0x1d5ec1` | Looks up the incoming player key; negative index returns zero, otherwise reads DWORD `+0x50` of that player's record. |
| Score read | `0x1d5edd` | Same lookup and miss return; reads DWORD `+0x58`. |
| Team-to-side lookup | `0x182705` | Unsigned team ID `ECX <= 15` and teamplay enabled: returns DWORD at VA `0x117a068 + 4*ECX`. Otherwise returns `0xffffffff`. Only the two aggregate update slots below are established; the table's full meaning is not decoded. |

The handle filter forwards to code outside this extraction. Its null and
predicate branches are measured; calling it an unrestricted handle resolver
would lose the extra type/predicate check.

Observed layout used by this chain:

| Structure | Field | Observed use |
| --- | --- | --- |
| Filtered object | `+0x420`, DWORD | Player key passed to the scoreboard lookup. |
| Filtered object | `+0x2e8`, DWORD, low four bits | Team ID used by **add** paths for aggregate updates. |
| Player record, stride `0xf70` | `+0`, DWORD | Lookup key. |
| Player record | `+0x12`, byte | Team ID used by **set** paths for aggregate updates. |
| Player record | `+0x50`, DWORD | Kills. |
| Player record | `+0x54`, DWORD | Deaths. |
| Player record | `+0x58`, DWORD | Score. |
| Aggregate record, stride `0xc` | `+0/+4/+8`, DWORD | Kills/deaths/score; two accepted side indices, 0 and 1. |

The record is not a full structure definition. No upper-bound validation is
added after a successful player search: the search itself bounds the index.

## Exported score operations

| Function | RVA | Contract |
| --- | --- | --- |
| `GetKills(h)` | `0xd5f26` | Filter `h`; failure returns zero. On success read object `+0x420` and tail-dispatch to kills-read. Missing player also returns zero. No world-zero guard. |
| `GetScore(h)` | `0xd5f09` | Same path, through score-read. Zero therefore cannot distinguish a genuine zero score from lookup failure. |
| `SetDeaths(h,value)` | `0xd5ee9` | Filter `h`; failure does nothing. Pass player key and replacement value to deaths-set below. |
| `SetKills(h,value)` | `0xd5ec9` | Same wrapper, through kills-set. |
| `SetScore(h,value)` | `0xd5ea9` | Same wrapper, through score-set. |
| `AddKills(h,delta)` | `0xd5e8b` | Move `h` to `ECX` and delta to `EDX`; tail-dispatch to kills-add, which performs the checks. |
| `AddScore(h,delta)` | `0xd5e7c` | Same register adaptation, through score-add. |
| `MoneyScore(amount,bagman)` | `0xd532f` | Move **second** argument `bagman` to `ECX` and **first** argument `amount` to `EDX`; tail-dispatch to the **same score-add** helper as `AddScore`. No separate money conversion appears in this wrapper or the shared helper. |

`MoneyScore(amount,h)` and `AddScore(h,amount)` thus share the same native
implementation after swapping the C argument order. This is a measured
equivalence of these paths, without a claim about external callers or UI text.

## Internal score writes and aggregate propagation

All five write helpers below first reject `GetCurWorld()`'s underlying DWORD
when it is nonzero. They perform 32-bit integer assignment/addition without
saturation or negative-value rejection. VA `0x129a9fc` is set to byte 1 after
a successful player-record update; its downstream consumer is not traced.

| Helper | RVA | Update and failure paths |
| --- | --- | --- |
| Deaths set | `0x1d5ef9` | Nonzero world or missing player: no write. Otherwise replace record `+0x54`; if teamplay, use record team byte `+0x12` and propagate **new minus old** to the deaths aggregate. Then set the notification byte. |
| Kills set | `0x1d5f49` | Same steps, record `+0x50`, kills aggregate. |
| Score set | `0x1d5f99` | Same steps, record `+0x58`, score aggregate. |
| Kills add | `0x1d6049` | Nonzero world or rejected object: return. In teamplay, map the object's low-four-bit team and add delta to its aggregate **before** looking up the player record. Missing player then returns; otherwise set notification byte and add delta to record `+0x50`. |
| Score add | `0x1d60a9` | Same ordering, record `+0x58`, score aggregate. Shared by `MoneyScore` and `AddScore`. |
| Aggregate deaths add | `0x1de736` | If unsigned `ECX <= 1`, add `EDX` to DWORD at VA `0x12a1a64 + 0xc*ECX`; otherwise do nothing. |
| Aggregate kills add | `0x1de745` | Same bounds, DWORD at VA `0x12a1a60 + 0xc*ECX`. |
| Aggregate score add | `0x1de754` | Same bounds, DWORD at VA `0x12a1a68 + 0xc*ECX`. |

There is a real ordering difference: a valid filtered object with no matching
player record can still affect an aggregate through an **add** operation.
The **set** operations look up the player first and cannot take that path.
Whether such an object occurs during normal gameplay is untested. The two
team sources also differ: object bits on add, player-record byte on set.

## Other state wrappers

| Function/helper | RVA | Contract |
| --- | --- | --- |
| `GetSpawnpointHandle(team)` | `0xd5fd6` | Adapts the first argument to `ECX` and tail-dispatches to spawnpoint-lookup. |
| Spawnpoint lookup | `0x18099e` | Null global container at VA `0x126d934` returns zero. Otherwise scan its `[begin,end)` pointer array; first record whose DWORD `+0xc` equals the requested team returns DWORD `+0x10`. No match returns zero. No explicit team-range check or handle validation. |
| `HideCockpitTimer()` | `0xd6174` | Tail jump to cockpit-hide; it has no independent body logic. |
| Cockpit hide | `0x100a2` | If flag byte at VA `0x126e053` is zero, return. Otherwise clear it and invoke VA `0xf2f4c6` with token `0xf7b1dd` and selectors **0, 1, 2, 4**. The last dispatch is a tail jump. Token spelling and downstream UI registration semantics remain open. |

## Reproduction and limits

`_BZ_REA/tools/mission_state_surface.py` saves all 40 bodies, their individual
SHA-256 hashes, exact SDK declarations for the exports, capture hash and
inventory/API source hashes to
`_BZ_REA/evidence/deep/surface/mission-state.json`. It decodes each complete
inventory span using Capstone and refuses missing, non-entry-aligned or
partially decoded procedures. This record is ordinary file-backed evidence,
**not an REA Evidence record**.

Run `python tools/mission_state_surface.py` to regenerate the record, then
`python tools/verify_mission_state.py` to compare it with the current sources
and check this page's function coverage. The inventory spans inspected here
end at returns/tail jumps; no observed branch in these 40 bodies escapes into
an unrecorded continuation of the same body. The upstream handle resolver,
virtual predicate, UI dispatcher, global writers and live multiplayer behavior
are outside this pass. Existing [network evidence](NETWORK.md) supplies the
wider model; these static world guards do not prove multiplayer determinism.
