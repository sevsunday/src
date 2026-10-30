# ODF access: public 2.0.185 interface and native wrappers

This reference documents the mission-visible ODF reader: the SDK declaration,
the exported native symbol set, the literal wrapper bodies measured on the
public 2.0.185 capture, and — new in this revision — the shared implementation
they all call. That implementation identifies itself as **ParameterDB**
(`fun3d\parameterdb.cpp`), and it is now recovered far enough to state its key
hash, its three-level cache, its grammar, its duplicate policy and the exact
coercion each typed getter applies. Two behaviours matter to authors and had no
public description: keys are case-insensitive CRC-32, and stored values are
inlined into a 16-byte field with `...` truncation, while seven label names are
diverted to a separate 32-byte table.

Reviewed **2026-10-27**. **SDK** means a declaration in the installed header;
**observed** means instruction bytes read from the named capture; **inference**
marks a comparison no execution confirms. Carrier and address rules are in
[Binary carriers](BINARY-CARRIERS.md). Existing [IFACE](../IFACE_REFERENCE.md)
and [BZN](../BZN_COMPAT_SPEC.md) references are not repeated here.

## Declared interface

Installed `ScriptUtils.h`
(`c60cb3bdc8a5e9ff342f1239cc4b197713a621e4640a55b4240ca0f6b77a65f7`), lines
1785–1814. Parameter names are the header's own.

| Declaration | Signature |
| --- | --- |
| `OpenODF` (1813) | `bool OpenODF(const char *name)` |
| `CloseODF` (1814) | `bool CloseODF(const char *name)` |
| `GetODFHexInt` (1799) | `int GetODFHexInt(file, block, name, int* value, int defval)` |
| `GetODFInt` (1800) | `int GetODFInt(file, block, name, int* value, int defval)` |
| `GetODFLong` (1801) | `int GetODFLong(file, block, name, long* value, long defval)` |
| `GetODFFloat` (1802) | `int GetODFFloat(file, block, name, float* value, float defval)` |
| `GetODFDouble` (1803) | `int GetODFDouble(file, block, name, double* value, double defval)` |
| `GetODFChar` (1804) | `int GetODFChar(file, block, name, char* value, char defval)` |
| `GetODFBool` (1805) | `int GetODFBool(file, block, name, bool* value, bool defval)` |
| `GetODFString` (1806) | `int GetODFString(file, block, name, size_t ValueLen, char* value, const char* defval)` |
| `GetODFColor` (1807) | `int GetODFColor(file, block, name, DWORD* value, DWORD defval)` |
| `GetODFVector` (1808) | `int GetODFVector(file, block, name, Vector* value, Vector defval)` |

The header's contract comment (1785–1798) states that an accessor returns true
when the value was retrieved, and false otherwise **after copying `defval`**;
its own example calls `OpenODF("ivscav.odf")`, then `GetODFFloat(...)`, then
`CloseODF("ivscav.odf")`. Note the declaration returns `int`, not `bool` — the
native shims return `MOVZX EAX, AL`, i.e. the low byte zero-extended.

## Exported native symbol set

Symbol values are capture absolute addresses; the RVA (capture base
`0xde0000`) is the portable form. The list is complete for **names containing
`ODF`** in the capture's procedure/symbol inventory, not a claim that these are
all ODF-related code.

| Symbol | Capture address | RVA |
| --- | --- | --- |
| `GetPilotOdf` | `0xeb2365` | `0xd2365` |
| `CloseODF` | `0xeb3f8a` | `0xd3f8a` |
| `OpenODF` | `0xeb3f96` | `0xd3f96` |
| `GetODFVector` | `0xeb3fa4` | `0xd3fa4` |
| `GetODFColor` | `0xeb400b` | `0xd400b` |
| `GetODFString` | `0xeb402a` | `0xd402a` |
| `GetODFBool` | `0xeb404c` | `0xd404c` |
| `GetODFChar` | `0xeb406b` | `0xd406b` |
| `GetODFDouble` | `0xeb40ad` | `0xd40ad` |
| `GetODFFloat` | `0xeb40f8` | `0xd40f8` |
| `GetODFLong` | `0xeb4142` | `0xd4142` |
| `GetODFInt` | `0xeb4161` | `0xd4161` |
| `GetODFHexInt` | `0xeb4180` | `0xd4180` |
| `DoesODFExist` | `0xeb4463` | `0xd4463` |
| `GetPlayerODF` | `0xeb4992` | `0xd4992` |
| `PreloadODF` | `0xeb5cf5` | `0xd5cf5` |
| `IsOdf` | `0xeb8b0a` | `0xd8b0a` |

All seventeen now have a measured wrapper body. Nine were analysed in the
first pass; the rest were added with the ParameterDB pass, which also settled
the two dispatch shapes below.

## Measured wrapper bodies

All nine bodies are contiguous and entry-aligned on the capture. Every getter
ends by returning the low byte of its callee's result; the two open/close
shims tail-jump and pass the callee's `bool` through. None contains parsing,
file I/O or a cache lookup in its own frame — the work is in the shared
implementations named in the table.

| Function | RVA | Body | Calls (capture addresses) | Return |
| --- | --- | ---: | --- | --- |
| `CloseODF` | `0xd3f8a` | 12 B | tail `JMP 0xf4a9f8` | callee's `bool` |
| `OpenODF` | `0xd3f96` | 14 B | tail `JMP 0xf4a8b3` | callee's `bool` |
| `GetODFVector` | `0xd3fa4` | 103 B | `0x110dd81` ×3 → `0xf4a83c` | `AL` → `EAX` |
| `GetODFColor` | `0xd400b` | 31 B | `0xdf08a4` | `AL` → `EAX` |
| `GetODFString` | `0xd402a` | 34 B | `0xdf08e5` | `AL` → `EAX` |
| `GetODFBool` | `0xd404c` | 31 B | `0xdf0929` | `AL` → `EAX` |
| `GetODFChar` | `0xd406b` | 66 B | `0x110dd81` ×3 → `0xf4a810` | `AL` → `EAX` |
| `GetODFDouble` | `0xd40ad` | 75 B | `0x110dd81` ×3 → `0xf4a7d5` | `AL` → `EAX` |
| `GetODFFloat` | `0xd40f8` | 74 B | `0x110dd81` ×3 → `0xf4b0a5` | `AL` → `EAX` |
| `GetODFLong` | `0xd4142` | 31 B | `0xdf096a` | `AL` → `EAX` |
| `GetODFInt` | `0xd4161` | 31 B | `0xdf09ab` | `AL` → `EAX` |
| `GetODFHexInt` | `0xd4180` | 66 B | `0x110dd81` ×3 → `0xf4a77f` | `AL` → `EAX` |

Two observed shapes:

1. **Direct re-dispatch** (`GetODFBool`, `GetODFInt`, `GetODFString`). The
   `cdecl` export reloads `file` into `ECX` and `block` into `EDX`, pushes
   `name`, `value` and `defval` (plus `ValueLen` for the string form), then
   calls a single implementation. That register/stack split is the Microsoft
   fastcall argument order for the same five or six parameters — an
   **inference** from the observed setup, not a recovered prototype.
2. **Staged resolution** (`GetODFFloat`, `GetODFDouble`, `GetODFHexInt`,
   `GetODFVector`). Three successive calls to `0x110dd81` consume the declared
   name/value/default arguments first and then `block` and `file`; the staged
   results are placed in `ECX`/`EDX` before the typed implementation runs.
   `0x110dd81` is now identified: a case-folded CRC-32 (see
   [keys](#keys-case-folded-crc-32)). The pre-push is not padding — the
   wrapper leaves the first hash on the stack so it becomes the third
   argument of the typed core while `value` and `defval` ride below it.

`OpenODF` and `CloseODF` are 12–14-byte tail-call shims: `ECX` receives the
`name` argument (`OpenODF` additionally zeroes `DL`) and control transfers
without a return instruction of their own.

## The shared implementation is ParameterDB

The `OpenODF` callee `0x00f4a8b3` names its own source file. It refuses a blank
name by writing a diagnostic record and calling the log routine `0x110d6a8`:

| Field | Value |
| --- | --- |
| Source literal | `e:\bigboat\bz2\source\fun3d\parameterdb.cpp` at `0x11a23b0` |
| Build stamp | `Sun Feb 25 13:10:45 2018` at `0x1190d44` |
| Line | `0x13a` = 314 |
| Severity | `3` |
| Message | `Requested opening of a blank ODF filename. Ignoring.` at `0x11a2408` |

So the whole ODF surface is one object — ParameterDB — created per file and
stored under the file's hashed name. The parser, cache and getters in this
document are facets of that object, and every diagnostic it emits carries the
same four-field record (file, line, stamp, severity).

## Keys: case-folded CRC-32

`0x110dd81` is the single key routine. Its instruction sequence is
`state = ~seed; for each byte: state = (state << 8) ^ table[fold[byte] ^ (state >> 24)]; return ~state`,
with two static tables:

| Table | Address | Size | Content |
| --- | --- | --- | --- |
| CRC | `0x11821c0` | 256 × 4 B | MSB-first CRC-32, polynomial `0x04c11db7` |
| Fold | `0x11825c0` | 256 B | `A`–`Z` → `a`–`z`, identity elsewhere (230 distinct) |

Both were checked against independently generated tables, and a Python
reimplementation of the instruction sequence reproduces the routine's output;
`tools/verify_crc_table.py` repeats that check and writes
`evidence/deep/odf-paramdb/crc-tables.json`. Measured keys at seed 0:

| Text | Key |
| --- | --- |
| `ivscav.odf` / `IVSCAV.ODF` | `ca2ef1e5` |
| `GameObjectClass` / `gameobjectclass` | `f153e306` |
| `CraftClass` | `41e9e7fd` |
| `[CraftClass]` | `5158663a` |
| `` (empty) | `00000000` |

The fold table is the whole case-insensitivity story: two names that differ
only in ASCII case collide by design, and no other normalisation happens. An
empty string hashes to zero, so a zero key is indistinguishable from an empty
name — an **inference** about a collision surface, not an observed failure.

**Seven labels are special-cased at parse time.** The parser compares a
label's hash against `0x363caa63`, `0x5d87b525`, `0x6036dc4d`, `0x6d75fa94`,
`0x69b4e723`, `0x77f3b726` and `0xf96a4250` before choosing how to index it.
Hashing the 2,528 distinct labels of the 4,435 ODF files installed with the
game and with VRV identifies all seven: `unitName`, `wpnName`, `requireText1`,
`requireText2`, `requireText3`, `requireText4` and `buildLabel`. The folded
spelling `requiretext1` produces the same key, which is the case-insensitivity
claim demonstrated on real content. None of the 722 distinct section names in
that corpus matches a special value.

## Cache: three hash levels plus a name list

A key is hashed a second time for the table that stores it. The file-level
lookup (`0x00dfe17b`) is the one measured in full: it computes an FNV-1a
32-bit hash of the four key bytes
(offset basis `0x811c9dc5`) and uses it masked by `0x0b65bda8` as a bucket
index into `0x0b65bd9c`. Buckets are 8 bytes; a node chains through `[0]`
and carries its key at `[2]`; `0x0b65bd94` is the empty sentinel. The lookup
therefore costs CRC-32 over the name text plus FNV-1a over the key. The two
inner lookups go through a generic helper (`0x00dedb5b`) whose bucket function
was not measured, so only the file level is proved to be FNV-1a.

Three levels are visible in `0x00f4979a`, which resolves file, then block, then
label:

| Level | Where the table is reached | Evidence |
| --- | --- | --- |
| File | global table keyed by `CRC(filename)` | `0x00dfe17b` called from `0x00f4a8b3` and `0x00f4979a` |
| Block | object field `+0x4a4` | `*(int *)(db + 0x4a4)` in `0x00f4979a`; the field is written by `0x00f4982c` |
| Label | block field `+0x30` | `*(int *)(block + 0x30)` in `0x00f4979a` |

A hit returns a copy of the 20-byte value record at node `+0xc`; a miss returns
null, and each typed getter then writes the caller's default and reports
missing. The getter itself never opens a file: the record is read from memory
or not at all.

Independently of the hash tables, the module keeps a **list of open file
names** (`0x01586d5c`..`0x01586d60`, elements 0x18 bytes = `std::string`).
It is the filelist whose insertion failure logs `Could not add to filelist :(`
(`0x11a2440`, line `0x185`, severity 1) and whose removal shifts elements down
(`0x00df7866`). It is also the diagnostic source for `0xf4a6c0`, which prints
`Last few opened ODFs:` (`0x11a23dc`) followed by at most four ` %d : %s`
lines (`0x11a23f4`), newest first, at line `0xd1`/`0xd6` and severity 3.

## Typed value semantics

All typed getters share one shape: resolve the record, and on a miss copy the
caller's default into the output pointer and return false. The differences
below are the whole of the coercion policy, measured per implementation.

| Getter | Implementation | Coercion | Quirk |
| --- | --- | --- | --- |
| Bool | `0xf4b037` | first character only: `y Y t T 1` → true, `n N f F 0` → false | any other first character writes `defval` **and still returns 1** |
| Int | `0xf4aad6` | `atoi` | no range check, no error signal |
| HexInt | `0xf4a77f` | `0x` prefix → `sscanf(..., "%x")` (`0x11a251c`), else `atoi` | lowercase `0x` only |
| Float | `0xf4b0a5` | `atof`, narrowed to `float` | overflow becomes `inf` |
| Double | `0xf4a7d5` | `atof` | — |
| Vector | `0xf4a83c` | writes `defval` components first, then `sscanf("%f %f %f")` (`0x11a1ed0`) | partial text leaves trailing components at `defval` |
| String | `0xf4ac31` | `strncpy_s(dst, ValueLen, src, _TRUNCATE)` | then `%n` → `%d` (below) |
| Char | `0xeb406b` → `0xf4a810` | takes the **first character** of the stored text, no numeric conversion | `defval` copied on a miss; returns 0 |
| Long | `0xeb4142` → `0xdf096a` → `0xf4aa9f` | `atol` | direct re-dispatch like Bool |
| Color | `0xeb400b` → `0xdf08a4` → `0xf4af97` | `sscanf("%d %d %d %d")` into four bytes | see colour packing below |

### Colours are four text components packed into one DWORD

`0xf4af97` seeds four temporaries from the caller's default DWORD
(`def>>16 & 0xff`, `def>>8 & 0xff`, `def & 0xff`, `def>>24`), parses
`"%d %d %d %d"` (`0x11a1eb8`) over them, and packs the result as
`v3<<24 | v0<<16 | v1<<8 | v2`. Reading the DWORD as `0xAARRGGBB`, that makes
the ODF text order **R G B A**: `color = 255 128 64 255` stores `0xffff8040`.
The default round-trips exactly, and a short text keeps the default's remaining
bytes because the temporaries start from the default rather than from zero.
The core's decompiled body is `void`; the export's `int` "found" result is not
recovered, so only the packing is measured here.

### `GetODFChar` reads a character, not a number

Its core `0xf4a810` resolves the record and writes `*value = text[0]`; it never
calls `atoi` and never inspects a second byte. The declared type is `char`, and
the behaviour matches that literally. A caller that expected a numeric byte
from text such as `"255"` receives `'2'` (0x32), and an empty stored string
yields `'\0'` while still reporting success.

### Inline values and truncation

The stored record is 20 bytes: a `char text[16]` followed by one 32-bit
companion. The insertion routine `0xf4a43b` zeroes all 16 bytes,
`strncpy_s(text, 0x10, source, _TRUNCATE)`, forces `text[15] = 0`, and — when
the sixteenth byte would have been overwritten — writes `...` at offsets 12–14.
So a value longer than 15 characters is stored **truncated with a literal
ellipsis**, and every typed getter sees at most 15 characters. That reading is
in tension with the corpus: of 180,243 assignments in the same 4,435 files,
13,073 (7.3%) carry a value longer than 15 characters. Either those values are
truncated at runtime — a real engine limitation — or a second insertion path
exists that this parse path does not reach. No such path was found in the code
analysed here, and the static evidence does not distinguish the two readings.

The seven special labels take a different record: `0xf4a3a7` builds a 0x38-byte
association with a 32-byte name field, a `1.0f` at `+0x20` and a pointer at
`+0x24`, with the same `...` truncation at offsets 28–30. That is consistent
with display strings (`unitName`, `wpnName`, `requireText*`, `buildLabel`)
being kept apart from short machine values, but the semantic reading is an
**inference** from the layout.

### String hardening: `%n` becomes `%d`

`0xf4ac31` copies the value (or the default) and then scans the destination for
the two-byte sequence `%n`, replacing the `n` with `d`. ODF strings are handed
to printf-style consumers, and `%n` writes through a pointer; the engine
neutralises it on the way out. The scan is literal: it does not consider `%%n`
escaping, does not touch other conversions, and applies to the default value as
well. This is an observed behaviour of the getter, not a documented contract.

## Grammar, as implemented by `0x00f4982c`

The parser walks one in-memory buffer (base `+8`, length `+0xc` of the loader
object) and recognises:

| Element | Rule |
| --- | --- |
| Line comment | `;` … end of line |
| Line comment | `//` … end of line |
| Block comment | `/*` … `*/` |
| Section | `[` … `]` or newline, at most 253 (`0xfd`) characters |
| Label | characters until one below `0x21`, `=`, or newline, at most 253 |
| Assignment | `=` optional; without it the rest of the line is skipped |
| Blank skips | bytes `<= ' '` before the value, except newline |
| Null value | first four bytes equal `NULL`, case-insensitive → value not stored |
| Quoted value | `"`…`"` or `'`…`'`, ending at the matching quote, newline or CR |
| Bare value | ends at a byte below `0x21` or a CR — a single token, spaces included only inside quotes |

No backslash escape handling appears in the quoted-value loops, so a quote
character cannot be embedded in a quoted value. A label or section at the 253
character limit is truncated without a diagnostic in the observed code.
Section names are hashed and looked up in the object's block list; a label is
hashed, and — unless it is one of the seven special names — indexed under the
current block with a second hash.

## Diagnostics and duplicate policy

Each diagnostic binds a line number to a message by immediate address in the
same basic block. The duplicate policy is therefore readable without running
the game:

| Line | Message | Address | Severity | Behaviour |
| ---: | --- | --- | ---: | --- |
| `0x13a` | `Requested opening of a blank ODF filename. Ignoring.` | `0x11a2408` | 3 | `OpenODF` returns without opening |
| `0x185` | `Could not add to filelist :(` | `0x11a2440` | 1 | open-name list insert failed; parse aborts |
| `0x1f8` | `Duplicate block ['%s'] in file '%s'` | `0x11a2468` | 2 | a repeated `[Section]` is reported |
| `0x206` | `Couldn't insert block for '%s' into list` | `0x11a248c` | 1 | block list insert failed |
| `0x26e` | `Uhoh - malformed ODF '%s'. Recently opened ODFs:` | `0x11a24b8` | 1 | calls `CloseODF` and stops the parse |
| `0x27a` | `Duplicate label '%s' in file '%s' block ['%s']` | `0x11a24ec` | 2 | a repeated label in one block is reported |

Two readings follow. A duplicated section or label is **reported but not
necessarily fatal** — severity 2 is not the malformed-ODF path, which is
severity 1 and closes the file. And the "malformed" message is followed by the
`Last few opened ODFs:` dump, so a parse failure names its file and its
neighbours in the same log record.

The same register file-literal/message pairing appears for class checks, but
no code site was decoded for them, so their trigger conditions are **inferred
from text only**:

- `ERROR: ODF %s, [%s]::%s is supposed to be an GameObjectClass, but isn't.` (`0x11a20a0`), with follow-ups ` .. looks like WeaponClass instead` (`0x11a20fc`) and ` .. looks like GameObejctClass instead` (`0x11a2218`, the binary's own typo).
- `WARNING: … tries to point to %s %s, but couldn't find it.` / `… but found a prototype class.` (`0x11a1fb0`).
- `INFO: Tried to find %s, [%s]::%s, but it's missing. Most of the time this is intentional.` (`0x11a2148`).

The strings imply that a reference label is resolved, checked against an
expected base class, and distinguished from a prototype; the exact resolution
order remains unproven.

## Lifetime and reference counting

`OpenODF` on an already-open name increments a counter at `db + 0x494` and
returns. `CloseODF` (`0x00f4a9f8`) decrements it; at zero it linearly scans the
open-name list with `_stricmp`, erases the matching `std::string` and destroys
the object. The name comparison is case-insensitive on the literal text while
the cache is keyed on the folded hash, so both paths agree about case.

On the first open, the shim allocates an object, records the source filename
(`0x00df6406` assigns it into the object's `std::string`), parses and indexes
the buffer (`0x00f4982c`), then releases the loader. The typed getters contain
no reference-count change: they look up and return, so a value read after
`CloseODF` depends on whatever else still holds the object. Nothing observed
here shows an implicit open on get.

## The exported helpers around the getters

Five exports are not typed getters. Their bodies answer the lifetime and
selection questions the earlier revision left open.

| Export | Address | Observed body |
| --- | --- | --- |
| `DoesODFExist` | `0xeb4463` | formats `%s.odf` into a 264-byte buffer when the name is shorter than 257 characters, then calls `0x00e4502c` |
| `PreloadODF` | `0xeb5cf5` | a two-instruction tail call into `0x00f3cc6c`; behaviour not established |
| `IsOdf` | `0xeb8b0a` | reads craft ODF-name fields from world slots and compares with `_stricmp`; the handle value `0xDEADBEEF` takes a separate existence-check path |
| `GetPilotOdf` | `0xeb2365` | current world → virtual slot `+0x18c` → returns the `char*` at `+0x68` (the craft's ODF name) |
| `GetPlayerODF` | `0xeb4992` | CVar item → id → name lookup, or a filtered multiplayer vehicle list; every failure returns the literal `ivscout` |

**`DoesODFExist` appends the extension.** The installed declaration is
`DoesODFExist(const char* odf)`, and the body formats `%s.odf` before the
check. A caller that passes a name already ending in `.odf` therefore tests
`name.odf.odf` — an **inference** from the format string, and a trap the header
does not warn about. The returned boolean is the callee's; the decompiler's
view of it is obscured by the epilogue's stack-cookie call, so only the
forwarding is measured.

**`IsOdf` matches a craft's ODF.** The header's own example is
`if (IsOdf(enemy1, "svturr"))`, and the body is consistent with it: it
resolves the current world, reads name fields from object records
(`+0x28`, `+0x68`, `+0x620`) and compares them with `_stricmp`. A handle equal
to `0xDEADBEEF` instead checks that `<name>.odf` exists. One detail is not
settled: the decompiler reads the first byte of the name argument as a small
selector, which contradicts the documented signature and is most plausibly a
lost fastcall register, so the selector is reported as unresolved rather than
as behaviour.

**`GetPlayerODF` is the mission-facing random vehicle picker, and it fails
softly.** `Randomize_None` reads a CVar item and resolves the id through
`0x00fa6432`. `Randomize_Team`/`Randomize_Any` enumerate a multiplayer vehicle
bitmask (`0x0129b320`, count `0x0160c804`), keep ids whose ODF resolves and
— for the team variant — whose name starts with a race character obtained from
`0x00fb5dcc`, then pick one. Four failure paths log and return the literal
`ivscout` (`0x118d9d0`):

| Line | Logged text | Severity |
| ---: | --- | ---: |
| `0x147f` | `Valid MP vehicle list was empty when trying to find a craft! Falling back to ivscout` | 2 |
| `0x1484` | `Valid MP vehicle list filtered by race '%c' was empty when trying to find a craft! Falling back to ivscout` | 2 |
| `0x14a6` | `CODE BUG, Randomizer out of range! Falling back to ivscout` | 1 |
| `0x14af` | `Mission DLL ERROR.  Randomization type invalid!` | 1 |

Those messages name `e:\bigboat\bz2\source\fun3d\scriptutils.cpp` (`0x118d808`,
stamp `Mon Apr 29 01:59:47 2019` at `0x118d834`), which places the mission API
implementation in the `scriptutils` translation unit rather than in
`parameterdb`. The selection index itself is unresolved: the code seeds a
512-entry table (`& 0x1ff` at `0x012a8e18 + 0x60`) and calls a helper
(`0x01002262`) whose return the decompiler does not expose, so the mapping from
that helper to the chosen entry is not established.

## Why the earlier on-disk analysis was invalid

An earlier REA/Ghidra pass over the **shipped** `battlezone2.exe` analyzed
`GetODFBool` at disk `0x4d404c` and reported a non-contiguous 145-byte body
spanning 411 bytes with `Control flow encountered bad instruction data`. That
result is consistent with the carrier measurement: the shipped code section
is protected, so RVA `0xd404c` is not readable instruction bytes there — an
inference, since no protection mechanism was established or reversed. The
capture at the same RVA is a clean 31-byte body. See [Binary carriers](BINARY-CARRIERS.md) for the
section-level measurement. The earlier record stays in `_BZ_REA` as evidence
of the failure mode, not as a description of `GetODFBool`.

## Evidence

Per-function records live under `_BZ_REA/evidence/deep/odf-185/`; the REA
bundle `evidence-bundle.json` hashes to
`893249a552c8ae805ebdf6858de3c9a1c00dfaf52defc290e7b64a8aa8c3163d`.
Per-function Evidence IDs:

| Record | Evidence ID |
| --- | --- |
| `odf-open.json` | `ev_70b7d531608008436bf3fa797e2390528d831830495b1c1dec8a116a5361087c` |
| `odf-close.json` | `ev_9533ac8e23b758388567bd592affe807004d3c4d12978c2d51901861184bd07b` |
| `odf-vector.json` | `ev_e3d1cbed6bddbe6b60fd396995d858e54204bf30345fa64cd00d89eb9b3184cd` |
| `odf-string.json` | `ev_dd4861739ee8ecb31d5ebe7e2dd88ec6783af7c2f175164b09e1c6dcaf2eeeb1` |
| `odf-bool.json` | `ev_9703e77cfc459d04d1d3de8d95c59de4263325e9249d51665282d85849a51e3a` |
| `odf-double.json` | `ev_6a1c046db8169d8d08941234d05098891818adf8192b68c4e837bc4755726b6a` |
| `odf-float.json` | `ev_4cc77a34a4d0413e2e8a78b6a146fb14892e58533ee3938e8071dfd5247d2487` |
| `odf-hex.json` | `ev_61d7ed7d865d76d2de14c8a7d5590d4683e0088290e3851ce8393edf25f6e908` |
| `odf-int.json` | `ev_e70a5acc46a0d02d2fbd8dfc265d3b6f13b7d0bfb1025fe64fe0e0431070beed` |

The implementation pass adds six sessions, each with a journal and, except
for the aborted first attempt, an `evidence-bundle.json`:

| Session | Contents | Bundle SHA-256 |
| --- | --- | --- |
| `evidence/deep/odf-internals/` | open, close, bool/int/string/vector/float/double/hex cores, hash routine | `29fcf432970923d72bbe1889b2cc1a1b817b27c1c3bf8e66ad00a7d0469d6470` |
| `evidence/deep/odf-paramdb/` | parser, cache lookup, map find/erase, value insertion, allocation | `fc688aa53ccbf65782d9b88dcb53dbf39c78d98626a77b8541a8b86ac28b4595` |
| `evidence/deep/odf-exports/` | value insertion, association record, open-file dump (no bundle: the session stopped on a mis-addressed export) | — |
| `evidence/deep/odf-lifetime/` | DoesODFExist, PreloadODF, IsOdf, GetPilotOdf, GetPlayerODF | `b93e3ce423b47e32ab4c733cb578ef12baf7f2cc6a3dc7fddeae547f36f1a6a0` |
| `evidence/deep/odf-typed/` | GetODFChar, GetODFLong, GetODFColor wrapper bodies | `ff365745780c184960a4ac8c60f43953787108f404a7bd85be735baecba944fc` |
| `evidence/deep/odf-cores/` | char core, long and colour dispatch shims | `642a46b3b0644e07a16a5375d1b5a1ff524b71b7dfe40915fa577304db697355` |
| `evidence/deep/odf-cores2/` | long (`atol`) and colour packing cores | `4e57b6429b960427be26a40c4da143b1aababeed11e6293ac2cccf531163d61f` |

Two derived records are produced by scripts and cited above:

| Record | Generator | SHA-256 |
| --- | --- | --- |
| `evidence/deep/odf-paramdb/crc-tables.json` | `tools/verify_crc_table.py` | `4a5a5ebbc58c944f967d96cc8d32e801b76a440823297952fc75232eaaf2a880` |
| `evidence/deep/odf-paramdb/label-census.json` | `tools/odf_label_census.py` | `b0092cff730989ed85c585d0ba34267371478aa22cbb684440c52ed91d2dd2c4` |

Both claims are reproducible without Ghidra. `verify_crc_table.py` re-reads the
two tables, compares them with a generated CRC-32 table and prints the sample
keys; `odf_label_census.py` hashes the 2,528 labels of the 4,435 installed and
VRV ODF files and names all seven special hashes. Neither script runs the game.
The census also classifies the 152 label-hash groups it finds: all are
ASCII-case variants that the fold table is designed to merge, and there are no
collisions between differently-spelled labels.

## Remaining gaps

- **Long values.** The insertion path analysed caps inline text at 15
  characters and marks truncation with `...`. Whether a second path stores
  longer values, and how `GetODFString` would reach them, is unresolved.
- **The 32-bit companion** in the 20-byte record (offset `+0x10`) has an
  unknown role; candidates are a length or a type tag, and no consumer was
  decoded.
- **The 0x38-byte association** used for the seven special labels has a
  `1.0f` at `+0x20` and a pointer at `+0x24`; neither meaning is established,
  and no reader of that table was analysed.
- **Severity semantics.** Values 1, 2 and 3 are observed at the diagnostic
  sites; whether they select log/assert levels or something else is unproven.
- **Class validation.** The `GameObjectClass`/`WeaponClass`/`OrdnanceClass`
  messages and the "prototype class" warning have no decoded trigger site.
- **`OpenODF`'s zeroed `DL`.** The shim sets it, and the callee reads a
  `EDX`-passed argument; the meaning of the pair is not established.
- **The post-open calls** `0x00f9f4ad`, `0x00f9f4f8`, `0x00f9f52b` on the
  already-open path are unanalysed; they are the remaining unexplained step
  in the lifetime sequence.
- **`GetODFColor`'s "found" result.** The packing core decompiles as `void`
  and the export's `int` return is not recovered, although the miss path does
  write the default. Whether the function reports found/missing like its
  siblings is therefore unproven.
- **`GetPlayerODF`'s selection index.** The 512-entry seed table and the
  helper `0x01002262` are visible, but the mapping from that helper's result
  to the chosen entry is not, so the distribution (and whether it matches the
  documented randomisation) is unmeasured.
- **`DoesODFExist`'s boolean.** Only the `%s.odf` formatting and the call to
  `0x00e4502c` are measured; the return path is hidden behind the stack-cookie
  epilogue in the decompiler's view.
- **No runtime observation.** Nothing here shows a mission calling these, a
  file being read from disk, or a cache being walked; static shape is not a
  behaviour test. In particular, the 15-character truncation is read from the
  insertion code and is not confirmed against a running mission.
