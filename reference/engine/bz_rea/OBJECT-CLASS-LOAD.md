# GameObjectClass construction and ODF inheritance

<!-- procedure-contracts: 0x157a45 -->

The procedure at **RVA `0x157a45`** is a `GameObjectClass` construction and
configuration path in the recorded public **2.0.185** capture. Its 20,206-byte
body was previously the largest entry in the [gap worklist](GAP-TOP.md).
This page gives a bounded implementation account: type identity, initialization,
selected ODF fields and fallback rules. Many later resource and geometry paths
remain undecoded; this is not a complete reconstruction of that body.

The carrier is `public-2.0.185-live.exe`, SHA-256
`b3f07e6ca3d6a53f2dcdb2b2b2d9875d75cc3c30e25a36e921e78d23d06ee2c7`,
base `0xde0000`. Code addresses below are RVAs; explicitly marked data VAs
refer to this capture. No new game process was run. See the
[carrier rules](BINARY-CARRIERS.md), [RTTI object model](OBJECT-MODEL.md)
and [ParameterDB implementation](ODF.md).

## Identity, boundary and calling convention

REA/Ghidra reports one contiguous body, capture VA `0xf37a45` through
`0xf3c932` inclusive, exactly matching the inventory's 20,206 bytes. Evidence:
`_BZ_REA/evidence/deep/object-class-185/class-load.json`,
`ev_5783c4c8f69da82ab4a8a787a6b453e050b4bff89b88c53ac3d2704dccc3ea52`.

The instruction at RVA `0x157aa0` stores VA `0x119fcfc` at object offset zero.
That is vftable RVA `0x3bfcfc`, which the independently parsed
[`object-model.json`](object-model.json) associates with **GameObjectClass**,
derived from `EntityClass`. The type attribution therefore has a vtable/RTTI
binding as well as ODF key matches.

This is class metadata construction, not an ordinary per-frame object's
update. The body initializes member arrays, installs a class vtable, reads
`[GameObjectClass]` fields and constructs resource names. The exact C++
signature remains open: Ghidra warns that it cannot fully track the stack
spacebase and emits a misleading `void ...(void)` with `unaff_EBX` and
`extraout_ECX`. The assembly reads two inputs through incoming `EBX + 8/+0xc`
after its exception prologue. Treating the decompiler's missing parameters as
an actual no-argument ABI would be unsafe.

## Initialization and partial layout

The constructor creates **two arrays of 32 elements**, each element `0x18`
bytes, at object offsets `+0x20d0` and `+0x23d0`. This establishes a storage
lower bound of **`0x26d0` bytes**, not the complete allocation size. The
element constructor/destructor identities are not decoded here; `0x18`
matches the string element width already encountered in [ODF](ODF.md), but
width alone does not prove that these members are strings.

It also zeroes a `0x1594`-byte region starting at `+0x61c`, initializes
several fixed arrays, and allocates a five-DWORD block. The allocation is
encoded into object field `+0x614` using XOR with the object address and
constant `0x822381e4`; this field must not be treated as a plain pointer.
At `+0x618`, the body combines masked `GetTickCount()` bits and bits of the
object address. The semantic purpose of that value is unknown. This clock
read in metadata construction does not by itself prove simulation divergence.

The ODF reader receives the file/database key from object `+0xac`, block key
**`0xf153e306`**, and a label key. The measured engine CRC maps the block key
to `GameObjectClass`. Registers matter: many lookup calls have their block
and file arguments in `EDX`/`ECX`, so pseudocode omitting those arguments
also omits most field names. The assembly retains them.

## Selected fields and conversion rules

For these fields, the code first saves the corresponding value from a
template object, queries ParameterDB, and either copies the saved value on
a miss or converts the returned text. Offsets below are **byte offsets in
GameObjectClass**, not in a live `GameObject` instance.

| ODF label | CRC key | Destination | Native conversion / special fallback |
| --- | --- | --- | --- |
| `baseName` | `1592aac9` | `+0x620`, buffer `0x40` bytes | String getter defaults to template `+0x620`, or current object `+0x28` when template `+0x18c` points to itself; resulting text is hashed into `+0x61c`. |
| `scrapCost` | `cf311744` | `+0x660`, signed DWORD | `atol`; template value when absent. |
| `scrapValue` | `4936b846` | `+0x664`, signed DWORD | `atol`; template value when absent. |
| `scrapReturn` | `641f060d` | `+0x668`, signed DWORD | `atol`; normally template value on miss. If the template's `+0x18c` points to itself, a miss copies the newly selected `scrapValue` instead. |
| `powerCost` | `eb4a68e0` | `+0x66c`, signed DWORD | `atol`; template value when absent. |
| `buildTime` | `c4afa50b` | `+0x670`, float | `atof` narrowed to float; template value when absent. |
| `customCost` | `b468f6be` | `+0x67c`, signed DWORD | `atol`; on a miss and self-pointing template `+0x18c`, replaces the template fallback with signed integer **`(scrapCost * 6) / 5`**. The denominator temporary is initialized to 5 before this path. |
| `customTime` | `6c326f44` | `+0x680`, float | `atof` narrowed to float; on a miss and self-pointing template `+0x18c`, uses **`buildTime * 1.2f`** instead. |
| `maxHealth` | `fe81b442` | `+0x684`, float | `atof` narrowed to float; template value when absent. |
| `addHealth` | `28b2bbba` | `+0x688`, float | Same conversion and template fallback. |
| `aiAddHealth` | `24f74dc1` | `+0x68c`, float | Same conversion on hit. On miss, copies the **current object's `addHealth`**, overriding the initially copied template value. |
| `maxAmmo` | `09720a64` | `+0x690`, float | `atof` narrowed to float; template value when absent. |
| `addAmmo` | `d6907e60` | `+0x694`, float | Same conversion and template fallback. |
| `aiAddAmmo` | `1060dd81` | `+0x698`, float | On miss, uses the **current object's `addAmmo`**, overriding the initially copied template value. |
| `DAMAGE_SCALE` | `e444af60` | `+0x17c0`, float | `atof` narrowed to float; template value when absent. |
| `Mass` | `f83d02ab` | `+0x17c4`, float | `atof` narrowed to float; template value when absent. |
| `CollisionType` | `f28d02a2` | `+0x148`, signed DWORD | `atoi`; values below 0 or above 7 become **0**. Missing uses the template before the same range check. |

Thus an inherited AI repair/ammo rate is not necessarily retained when the
AI-specific key is absent: these two fields fall back to the object's newly
resolved general rate. Likewise, the custom-cost/time defaults depend on the
template self-pointer condition. Describing every absent key as simply
"use the parent's value" would miss both mechanisms. The self-pointer test
suggests a root/default template, but its construction and ownership have not
been traced far enough to give that interpretation symbol-level certainty.

No range rejection is observed on the listed `atol`/`atof` paths themselves.
These are native coercions, not a promise that every parsed value is usable
by later gameplay code. Damage application and physical mass consumption
remain separate investigations.

## Remaining phases in this body

Later code formats and queries indexed keys for weapons, hardpoints, lights,
effects, chunk counts and conditional health additions. It also constructs
`icon_%s.tga`, `wire_%s.tga`, `%s.inf`, and chunk model filenames. A missing
interactive info resource takes a diagnostic branch. The complete quoted
strings and call/reference lists are retained in the dossier. Their presence
does not establish file-search priority, cache semantics or every array bound.

The tail constructs numeric tables and weighted spatial samples. The called
geometry builder and its packed data model are now described in
[mesh spatial data](GEOMETRY-SPATIAL.md). Remaining geometry paths, exception cleanup, the full member layout,
all indexed field families, constructor callers and actual object creation
still need analysis. The full body's citation now supplies a place to read;
it does not mean all 20,206 bytes have a reviewed semantic contract.

## Reproduction

The read-only REA plan is `_BZ_REA/tools/plans/object-class-185.json`;
`tools/rea_batch.py` retains complete JSON, journal, tool schemas and the
exported evidence bundle. `tools/native_key_annotations.py` annotates a
**derived copy** of the pseudocode and assembly using the measured CRC tables,
embedded identifier strings and the recorded ODF label census. Its
`key-candidates.json` binds those matches to evidence and carrier hashes.
Case variants remain listed because the engine folds case. A hash match alone
is a candidate; each label above was also checked at its lookup instruction,
destination store and conversion/fallback branch.
