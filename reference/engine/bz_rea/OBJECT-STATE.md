# Object state, handle gates and native SDK behavior

<!-- procedure-contracts: 0xd69a3 0xd6aeb 0xd290f 0xd6954 0xd6aa6 0xd342d 0xd2b21 0xd2be3 0xd28ed 0xd88b7 0xd68c0 0xd8aa9 0xd4433 0xd8a11 0xd692b 0xd6a7d 0xd71a1 0xd6902 0xd6a31 0xd33e3 0xd85b3 0xd33ad 0xd5a35 0xd880e 0xb37d 0x10886 0x10a78 0x155413 0x156ad3 0x15cc6c -->

This page adds instruction-backed contracts for **24 exported object APIs and
six internal helpers** in public **2.0.185**. Signatures and author comments
remain in the [API reference](API-REFERENCE.md). The additional information here
is the actual handle gates, data fields, invalid results, virtual call slots,
bit operations and exceptional branches in these bodies.

Every code address below is an **RVA** in the recorded capture, image base
`0xde0000`, SHA-256
`b3f07e6ca3d6a53f2dcdb2b2b2d9875d75cc3c30e25a36e921e78d23d06ee2c7`.
Data addresses marked **VA** are absolute addresses at that base. See
[carrier provenance](BINARY-CARRIERS.md). These are file-backed Capstone
observations, **not REA Evidence and not execution of the game**.

The retained record is `_BZ_REA/evidence/deep/surface/object-state.json`. It
contains complete recorded bodies, body bytes and SHA-256, disassembly,
capture/inventory/API identities, the floating-point constants and a PE import
resolved from this same capture. Descriptive helper labels are authored names.

## Two different handle gates

The existing handle filter is described in
[mission-state lookup](MISSION-STATE.md#scoreboard-object-and-player-lookup).
It calls an upstream resolver and requires the object's virtual predicate at
byte slot `+0x60` to return true in `AL`. Its upstream mapping remains outside
this page. A successful result is called **filtered object** below.

The additional helper at `0xb37d` (24 bytes) calls that filter and then rejects
the object when DWORD `object+0x2e8` has bit **`0x400`** set. Null also returns
null; otherwise it returns the same pointer. A result through this helper is
called **active-filtered object** here. The semantic name of that flag is not
recovered. Calling both paths merely "resolve a handle" would hide a real
difference: several getters use the first gate and their setters use the
second.

Both gates receive the handle in `ECX`. Export wrappers adapt the C argument to
that register. The gates do not themselves prove the object's full C++ type,
pointer lifetime, thread safety or network authority.

## Existence and the IsAlive family

| Export | RVA | Native contract |
| --- | --- | --- |
| `IsAround(h)` | `0xd8a11` | Calls the active-object filter and returns `pointer != 0` in `AL`. It reads no health, AI or player state in this wrapper. |
| `IsAlive2(h)` | `0xd4433` | Zero handle or failed active filter returns false. Otherwise read DWORD `object+0x2ec`. For values **1 or 2**, return false if `object+0x47c` is null. Every other value passes without that pointer check. Returns true/false in `AL`; the caller's handle is untouched. |
| `IsAlive(Handle &h)` | `0xd8aa9` | Uses the same filter and `+0x2ec`/`+0x47c` predicate as `IsAlive2`. On a nonzero handle that fails either check, writes **zero into the caller's handle** and returns false. Already-zero input remains zero. The reference address itself is dereferenced without a null-pointer check. |

The unsigned branch implements `(uint32(kind - 1) > 1) || ai_pointer != 0`
after successful filtering. There is **no health comparison** in either
`IsAlive` body. The SDK's "alive and still pilot controlled" description is a
high-level contract; the native predicate is conditional on two object-kind
numbers rather than an unconditional AI requirement. This page does not assign
C++ enum names to those numbers or conclude that `IsAlive` is a physical-health
test. `IsAround` and `IsAlive2` cannot clear an input handle because they receive
it by value.

## Health and ammo reads

All four getters below use the **active-object filter**. Failure returns signed
32-bit **`-1234`** (`0xfffffb2e`). Successful reads use this common conversion:

1. Obtain a binary32 value and widen it to binary64.
2. Subtract the binary64 constant at VA `0x1246530`, exact bits
   `c0ffbfffffffdf3f` in little-endian order, value `0.4999999997671658`.
3. Add the binary64 constant at VA `0x1246538`, bits `0000000000003843`,
   value `6755399441055744.0`.
4. Store the binary64 result and return its **low DWORD** in `EAX`.

That is a measured bias-and-bit-extraction conversion, not an x86 `CVTTSS2SI`
or a proven C++ truncating cast. Its floating-point rounding mode is not changed
by the wrappers. Behavior for NaN, infinity, out-of-range values and nondefault
MXCSR settings has no runtime acceptance test here. Invalid-handle `-1234`
therefore has a separate early branch and does not pass through this arithmetic.

| Export | RVA | Successful source before conversion |
| --- | --- | --- |
| `GetCurHealth(h)` | `0xd6aeb` | Binary32 directly at `object+0x560`. |
| `GetMaxHealth(h)` | `0xd6aa6` | Binary32 directly at `object+0x564`. The SDK comment says "max Ammo"; the native field is distinct from the ammo virtual dispatch below. |
| `GetCurAmmo(h)` | `0xd69a3` | Invoke vtable slot `+0x158` with `ECX=object`; store its x87 `ST(0)` result to binary32, then run the conversion. |
| `GetMaxAmmo(h)` | `0xd6954` | Same path through vtable slot `+0x160`. |

The two ammo slots are intentionally left as virtual calls: the wrapper does
not establish which concrete class supplies a value or whether computing it
has side effects. Direct health-field reads are a stronger observation than a
guessed shared health/ammo layout.

## Health and ammo writes

Each setter first uses the **active-object filter**; a failed gate does
nothing. Numeric arguments are signed 32-bit `long` in this x86 ABI, converted
to binary32 by `CVTDQ2PS`. No zero/lower/upper clamp precedes the operations in
these wrappers.

| Export | RVA | Successful action |
| --- | --- | --- |
| `SetCurHealth(h,value)` | `0xd6a7d` | Pass the converted float to object virtual slot `+0x144`. |
| `SetCurAmmo(h,value)` | `0xd692b` | Pass the converted float to slot `+0x154`. |
| `SetMaxAmmo(h,value)` | `0xd6902` | Pass the converted float to slot `+0x15c`. |
| `SetMaxHealth(h,value)` | `0xd6a31` | Write the converted float **directly to `object+0x564`**. Widen current health from `+0x560` and call `_finite`. A nonzero result tail-dispatches to the ratio-refresh helper below; zero returns without refreshing ratios. |

The `_finite` name is established by the capture's own PE import descriptor:
IAT VA **`0x11337c0`**, DLL `api-ms-win-crt-math-l1-1-0.dll`, symbol `_finite`.
It is not a symbol guessed from an indirect call or borrowed from another
binary's import addresses. The check is on **current health**, after the max
field has already been written. Even a failed check does not roll back the
new maximum. Final validation/clamping in the three virtual methods remains
unrecovered; absence of a wrapper clamp is not proof of absence everywhere.

### Ratio-refresh helper

`0x155413` (70 bytes) receives the object in `ECX`. It reads maximum at `+0x564`,
current at `+0x560`, and the binary32 **1.0** constant at VA `0x11fd27c`.
For ordinary finite operands it uses `current/maximum` when maximum is nonzero
and 1.0 when maximum equals zero. It stores the selected ratio at **`+0x558`**,
then executes `MAXSS ratio,0.0; MINSS ratio,1.0` and stores that result at
**`+0x55c`**. Thus the raw ratio and bounded display-like ratio are separate
fields; the name "display-like" is an inference, not a recovered symbol.

The zero test is specifically `UCOMISS maximum,0; LAHF; TEST AH,0x44; JNP`.
The full retained instructions define unordered/NaN cases; treating the helper
as a generic language-level `clamp` would erase SSE operand-order and NaN
behavior. Its public caller tested the current value with `_finite`, not every
possible caller or the complete floating-point environment.

## Team, perceived-team and skill bit fields

| Export | RVA | Native contract |
| --- | --- | --- |
| `GetTeamNum(h)` | `0xd88b7` | Use the first, filtered-object gate. Null returns zero; success returns `DWORD(object+0x2e8) & 0xf`. |
| `GetPerceivedTeam(h)` | `0xd2b21` | Use the same first gate. Null returns zero; success returns `(DWORD(object+0x46c) >> 10) & 0xf`. |
| `SetPerceivedTeam(h,t)` | `0xd85b3` | Use the active-object gate. Replace only bits **10..13** of DWORD `+0x46c` with `t`'s low four bits using mask **`0x3c00`**; preserve all other bits. Negative and oversized team values are bit-masked, not rejected. |
| `GetSkill(h)` | `0xd28ed` | Use the first gate. Null returns **-1**; success returns `(DWORD(object+0x46c) >> 8) & 3`. |
| `SetSkill(h,s)` | `0xd5a35` | Use the first gate. Null does nothing; otherwise pass `s` to the skill-bit writer at `0x10a78`. |
| `SetTeamNum(h,t)` | `0xd880e` | Use the first gate. Null does nothing. Usually call object virtual slot `+0x1a4` with the unmasked input `t`, subject to the multiplayer rejection branch below. |

### Skill-bit writer

`0x10a78` (38 bytes) takes the object in `ECX` and one stack DWORD. It compares
the input against **3** and uses **unsigned `CMOVA`** to select 3 for values above
3, then replaces only bits **8..9** of DWORD `+0x46c` with mask **`0x300`**.
It preserves the perceived-team bits. It returns with `RET 4`.

Consequently a **negative signed skill becomes 3**, because its unsigned
representation is above 3. The native clamp is not `max(0,min(s,3))`. Inputs
0, 1, 2 and 3 are preserved; 4 and `-1` both select 3. The SDK says invalid
values are clamped into 0..3, but does not specify which endpoint negative
values choose. This difference matters when adapting a script or replacing
this wrapper with a conventional signed clamp.

### Multiplayer team-change branch

Before the `SetTeamNum` virtual call, all three conditions select a separate
diagnostic path:

- byte at VA **`0x129aa0e`** is nonzero;
- the object's DWORD at `+0x2e8` has either of bits **`0xc0`** set;
- the full input `t` differs from `DWORD(object+0x2e8) & 0xf`.

That path supplies the diagnostic
`DLL attempted to change team of local|remote player from %d -> %d. Not allowed in MP; netcode needs to own this`
at VA `0x118d850` to two reporting calls and returns **without invoking the
team-changing virtual slot**. The multiplayer and player readings of these
flags come from that diagnostic; the flags' writers are not established here.
The branch compares the **full input** with the old four-bit team. For example,
17 and stored team 1 differ at this check even though their low four bits match.
Other objects, a zero global flag, or an identical full team input reach the
virtual call. No local team-range validation occurs before that dispatch.

## Ownership and last-shooter cache

| Export | RVA | Native contract |
| --- | --- | --- |
| `SetOwner(obj,owner)` | `0xd33e3` | Active-filter the target; failure does nothing. Active-filter the proposed owner independently, then call the owner writer with that pointer, **including null** on lookup failure. |
| `GetOwner(h)` | `0xd342d` | Active-filter the target; failure returns zero. Read its stored handle at `+0x2e4`, pass it through the first filter, and return that object's own handle at `+0x2e0`. Missing/unacceptable owner returns zero. It does not clear a stale stored owner. |
| `GetWhoShotMe(h)` | `0xd68c0` | Active-filter the target; failure returns zero. Success tail-dispatches to the last-shooter helper below. This getter can mutate the target's cached shooter handle. |

The owner writer `0x10886` (30 bytes) receives the target object in `ECX` and a
pointer on the stack. A nonnull pointer contributes its DWORD at `+0x2e0`;
null contributes zero. It writes that value into target **`+0x2e4`** and returns
with `RET 4`. Thus the object stores an owner **handle**, not the pointer passed
to this helper, and `SetOwner(h,invalid)` clears the field after resolving the
target. No ownership graph traversal, cycle check or team update occurs in
these reviewed bodies.

The last-shooter helper `0x156ad3` (72 bytes) works on the cached handle at
**`object+0x550`**:

1. A nonzero cached value that fails the **first filter** is cleared.
2. It then tries the active-object filter on the remaining value. If that
   succeeds and the returned object's virtual slot `+0xf4` returns true in
   `AL`, the cache is cleared too.
3. It returns the remaining cached DWORD.

The semantic name of predicate `+0xf4` is unresolved. Importantly, failure of
the *second* gate alone does **not** clear the cache. A handle that passes the
first filter but is rejected only by bit `0x400` can remain and be returned.
The getter is therefore neither a pure field read nor an unconditional
"return only active shooters" filter.

## AI independence and pilot-class replacement

| Export | RVA | Native contract |
| --- | --- | --- |
| `GetIndependence(h)` | `0xd290f` | Active-filter the object. Require nonnull pointer `object+0x47c` and a true `AL` result from that pointee's virtual slot `+0x24`. Failure at any gate returns **-1**; success reads the pointee's DWORD **`+0x1c`** unchanged. |
| `SetIndependence(h,value)` | `0xd71a1` | Apply the same three gates, then write the input DWORD directly to the pointee's `+0x1c`. There is no 0/1 clamp or normalization. Failure does nothing. |
| `GetPilotClass(h)` | `0xd2be3` | Use the first object filter. Null returns null. Otherwise call object virtual slot `+0x18c`; a null result returns null, a nonnull result returns **that pointer plus `0x28`**. No string allocation or copy occurs in the wrapper. |
| `SetPilotClass(h,odf)` | `0xd33ad` | Active-filter the object. Null or empty `odf` dispatches object virtual slot `+0x188` with **null**. A nonempty string first goes through class lookup `0x15cc6c`; lookup failure returns without the virtual call, success passes the found pointer to the slot. |

The SDK associates `+0x47c` and predicate `+0x24` with a UnitProcess-derived AI
process; the bytes establish the gates and field access, without recovering
every subtype. The getter exposes the stored independence value as-is, so it
does not prove the field contains only the two values named by the SDK. The
pilot getter's `const char*` return is an address inside the callback's result;
its lifetime and the absence of an `.odf` suffix are SDK statements, not proven
by adding `0x28` in this wrapper.

### Pilot-class lookup helper

`0x15cc6c` (123 bytes) receives the string pointer in `ECX` and calls another
lookup with key **`0xf153e306`** in `EDX`. It rejects a null result. For a
nonnull record it invokes that record's virtual slot `+0x10` and requires true
in `AL`; otherwise it emits the diagnostic
`GameObjectClass::Find('%s') found an EntityClass, but NOT a gameobj`
and returns null. Success returns the original record pointer. With an incoming
null string it sets byte VA `0x123dc5d` to 1 and returns null; the exported setter
does not take that helper branch because it handles null/empty strings first.

The diagnostic identifies the intended GameObjectClass restriction. The key's
meaning, lookup/cache mechanics, the full class layout and virtual method
`+0x188`'s non-craft behavior remain outside this extraction. A failed nonempty
lookup and an explicit clear request are distinguishable: only the latter is
forwarded as null to the object's virtual method.

## Observed field map

Offsets are relative to the pointer returned by the relevant object gate,
unless the row names the AI pointee. This is a partial layout, not a complete
C++ class definition.

| Location | Size | Measured use |
| --- | --- | --- |
| Object `+0x2e0` | DWORD | Own handle copied out by `GetOwner` and into the owner's target field. |
| Object `+0x2e4` | DWORD | Owner handle. |
| Object `+0x2e8` | DWORD | Team low nibble, multiplayer-sensitive bits `0xc0`, active-filter rejection bit `0x400`. |
| Object `+0x2ec` | DWORD | Kind discriminator in the `IsAlive` pair; values 1 and 2 require AI pointer. |
| Object `+0x46c` | DWORD | Skill bits 8..9 and perceived-team bits 10..13; other bits preserved by these writers. |
| Object `+0x47c` | pointer | AI pointee tested by `IsAlive` and independence accessors. |
| Object `+0x550` | DWORD | Last-shooter handle cache, sometimes cleared by its getter. |
| Object `+0x558` | binary32 | Raw current/max health ratio, with measured zero-maximum fallback. |
| Object `+0x55c` | binary32 | Result after `MAXSS`/`MINSS` against 0 and 1. |
| Object `+0x560`, `+0x564` | binary32 each | Current and maximum health sources. |
| AI pointee `+0x1c` | DWORD | Independence value, unnormalized read/write. |

## Reproduction and remaining boundaries

Run from `_BZ_REA`:

```powershell
python tools/object_state_surface.py
python tools/verify_object_state.py
python -m unittest discover -s tests -p test_object_state.py -v
```

The verifier requires byte-identical extraction from current source inputs,
the exact explicit per-function page scope, names and critical instruction
guards. It rejects a stale body, removed contract or escaped conditional branch.
Every reviewed recorded span decodes completely and ends at return or an
explicit tail jump; no conditional branch escapes it. That check does not
reconstruct missing procedures elsewhere in the inventory.

Unresolved: the base handle resolver; meanings and writers of the object-kind
and flag fields; concrete virtual implementations; object/string lifetimes;
all callers of the six helpers; runtime float modes and exceptional values;
network authority and deterministic behavior of nested virtual calls. No
simulation or multiplayer runtime result is claimed by these static contracts.
