# Network variable keys, remapping and replication

The public185 bytes support eighteen bounded function contracts for session
variables. This recovers the key-array sizes, case-folded name hashing, player
index remapping, two receive layouts, integer/string setters and storage
lifetime. It does not establish a per-turn simulation checksum.

<!-- procedure-contracts: 0x1cec70 0x1d2b41 0x1d78f6 0x1d7d7f 0x1d7e42 0x1d7e83 0x1d7ec3 0x1d7eff 0x1d7f79 0x1d7f96 0x1d7fd0 0x1d811a 0x1d81d3 0x1d843e 0x1d86ab 0x1d89bc 0x1d89fb 0x1d8ac4 -->

Evidence: `_BZ_REA/evidence/deep/network/variable-contracts.json`, extracted by
`_BZ_REA/tools/network_vars.py`, verified by
`_BZ_REA/tools/verify_network_vars.py`. Each entry retains its exact inventory
span, bytes, SHA-256, decoded instruction addresses, direct calls and string
operands. This is ordinary file-backed Capstone extraction, **not REA Evidence**
and not a live multiplayer test. The carrier SHA-256 is
`b3f07e6ca3d6a53f2dcdb2b2b2d9875d75cc3c30e25a36e921e78d23d06ee2c7`.
Addresses are RVAs unless explicitly marked VA; see [carrier conventions](BINARY-CARRIERS.md).

## Address and field vocabulary

The labels below describe use, not recovered debug symbols. `U8`, `U16` and
`U32` are little-endian loads. Integer assignments use the low 32 bits; signed
tests are identified separately. A variable index is different from its name
hash and from a player's eight-bit identifier. The identifier-to-slot helper
is called at VA `0xfc0187`; its internal mapping is outside these contracts.

| Storage VA | Meaning established by the instructions | Extent |
|---|---|---|
| `0x129b910` | integer variable name hashes | 384 dwords |
| `0x129b310` | cached integer values | 384 dwords |
| `0x129bf10` | integer override-present flags | one byte per index |
| `0x129b090` | string variable name hashes | 160 dwords |
| `0x129c110` | cached string buffers | 160 slots of 128 bytes |
| `0x12a1390` | string cache-present flags | one byte per index |
| `0x12a1430` | cached integer registry-item pointers | 384 dwords |
| `0x12a1110` | cached string registry-item pointers | 160 dwords |
| `0x129c090` / `0x129c0d0` | client-local integer hashes / cached values | 16 dwords each |
| `0x12a1a30` | client-local string hashes | 8 dwords |
| `0x129b086` | forces refresh past unchanged-value shortcuts | byte |
| `0x129a612` | bracket around periodic cache-to-registry writes | byte |
| `0x129aa0d` | selects server-style broadcast versus upstream send | byte |
| `0x129aa10` | suppresses sends in both setters | byte |
| `0x123da00` | current local slot, with negative meaning unavailable | signed dword |
| `0x123d9fc` | upstream destination value supplied to the send wrapper | dword |
| `0x129aa54` | allocated player-record array | pointer; stride `0xf70` |

These arrays are beyond `.data`'s file-backed range, inside its virtual
zero-fill tail. **Their live contents are not present in this file.** Reading
the same numeric offset from later file bytes would read another section.
The retained derived keys are algorithm outputs, not observed live arrays.

## Key derivation

The session registrar at RVA `0x1cee6a` formats
`network.session.ivar%d` and `network.session.svar%d`, hashes each whole name
with seed zero through the already recovered [ODF key hash](ODF.md#keys-case-folded-crc-32),
and stores the result in the arrays above. The stores are at RVAs `0x1cf4f2`
and `0x1cf5be`. This is the same case-folded, MSB-first CRC-32 table with
polynomial `0x04c11db7`, not evidence of CRCs over variable **values**.

The audit routine independently hashes only the decimal suffix, seeded with
the prefix hash: `network.session.ivar` gives `0xe5e9edeb`, and
`network.session.svar` gives `0x570d709b`. The extractor reproduces both
routes and requires equality for all 544 derived keys. Examples:

| Name | Derived key |
|---|---|
| `network.session.ivar0` | `0x5e448bc9` |
| `network.session.ivar1` | `0x5a85967e` |
| `network.session.ivar383` | `0x0c28c625` |
| `network.session.svar0` | `0x0e654dd9` |
| `network.session.svar159` | `0x3683b6d2` |

The registrar is retained as supporting evidence; this page does not claim
to describe every console variable that its larger body registers.

## Per-function contracts

### `0x1d7e83` — remap_integer_index (64 bytes)

Input: signed index in ECX and an eight-bit player identifier in DL. If the
index is below 128 or DL is `0xff`, return the index unchanged. Otherwise
resolve the identifier to a signed slot. A negative result returns
`0xa5a5a5a5`; a successful lookup returns
`128 + 16*slot + ((index-128) % 16)`. The division/remainder correction in the
machine code implements signed arithmetic, though this path's index is already
at least 128. EAX is the result. There is no upper-bound check on the input
index or successful slot in this body, and negative indices pass through.

### `0x1d7ec3` — remap_string_index (60 bytes)

The same calling shape and failure sentinel apply, with threshold 32 and
eight strings per player: `32 + 8*slot + ((index-32) % 8)`. Below 32, or
with identifier `0xff`, the index is unchanged. The unsigned-looking mask
sequence is compiler code for signed remainder; it is not a second hash.
Callers still own the check that the final index fits their table.

### `0x1d7eff` — integer_default (122 bytes)

ECX selects an integer index. The base result is zero, with exceptions:
2 maps to 4; 4 to -1; 9 to 30; 10, 14 and 15 to 1; 20 to 6. Index 33
reads the byte at `U32(VA 0x12a2ec0)+0x8d4`. Index 34 reads the signed
dword at that pointer plus `0xdc` and divides it by 1000 with truncation
toward zero. Finally, a nonzero override flag at `VA 0x129bf10+index`
replaces any base result with the cached value at `VA 0x129b310+4*index`.
No range check protects those final array reads. These numeric cases do not
by themselves recover the gameplay names of indices 33 and 34.

### `0x1d78f6` — classify_small_integer (25 bytes)

Returns AL=0 for signed ECX in 0 through 4, and also for 7. All other signed
values return AL=1, including 5, 6 and negative inputs. Upper EAX is not
defined as a C++ boolean result. The body has no memory access or calls;
its caller's interpretation of this classification remains unidentified.

### `0x1cec70` — restore_session_variables (380 bytes)

Sets the refresh-forcing byte, calls a preparatory helper, then visits all
384 integer keys. A missing registry item is logged and skipped. A found
item has flag bit 0 set at item offset `+0x18`; its reset value comes from
`integer_default`, overridden again by the cached value when the corresponding
override flag is nonzero. Index 20 is skipped after lookup/flagging/default
calculation. Other indices are written through the integer setter helper and
stored into the integer-value cache.

The string loop starts at the incoming **unsigned CL**, not necessarily zero,
and ends before 160. Each found string is set to its 128-byte cache slot
when cache-present is set, or to the empty string otherwise; misses are
logged. It then writes 32 other integer keys from the table at
VA `0x129a6a0`, setting index zero to 1 and the remainder to 0. It clears
the refresh-forcing byte, invokes two further cleanup/update helpers and
zeroes the 256-byte region at VA `0x129a7a0` and the 64-byte region at
VA `0x129a8a0`. The names of those two cleared regions are not recovered.
It is a restore/reset worker, not merely a hash lookup error reporter.

### `0x1d7d7f` — periodic_integer_restore (195 bytes)

ECX is a caller-supplied time value. It returns without work if ECX is zero
or unsigned `(ECX-last) < 3000`; `last` is the dword at VA `0xb6d8e88`.
The time unit is unknown. Otherwise it stores ECX as the new last value and
loops over 384 integer hashes. Missing items produce the recorded diagnostic.
A found item's integer value is read and compared to the corresponding cached
dword. A mismatch writes the cached value back to the registry, with the byte
at VA `0x129a612` set to 1 around that setter and then cleared to zero.
It does not refresh the cache from the registry. Thus an out-of-band local
edit can be undone at this periodic check; no turn CRC or packet comparison
occurs here. The subtraction is 32-bit unsigned, including wraparound.

### `0x1d2b41` — audit_session_variable_cache (1,788 bytes)

Visits the 384 integer names and 160 string names using the seeded suffix
hash route above. It compares each derived hash to the cached hash and
reports a changed key through the diagnostic/assertion helpers. It also
compares the current registry-item pointer to the pointer cached by the
registrar, reporting removal, relocation and unexpected value types.

For integers, the current typed integer value is compared to the cached
dword and a mismatch is logged; the mismatch does **not** write a replacement
value. For strings this body checks pointer/type identity, not character-by-
character equality against the 128-byte string cache. Pointer-change paths
set the final error flag; a final diagnostic/assertion call handles that flag.
The helpers' termination behavior is outside this contract. A value-only
integer mismatch and a missing/moved variable are therefore different cases.
No observed data-flow edge here proves that these name hashes enter the
per-turn world checksum.

### `0x1d7e42` — assign_seven_slot_string (65 bytes)

ECX selects a 24-byte string object at `VA 0x160dac0+24*ECX`; EDX is a
source pointer. Signed ECX>=7 does nothing. Otherwise it empties the
selected string, choosing its inline buffer when capacity is below 16 and
its heap pointer otherwise. A null source leaves it empty. A non-null
source skips one leading double quote, obtains the remaining C-string length
through an imported function, and assigns those bytes. It does not remove
a trailing quote. **There is no negative-index guard.** The gameplay role
of these seven strings is not established from adjacency.

### `0x1d7f79` — clear_seven_slot_string (29 bytes)

Empties the same indexed string object: set length `+0x10` to zero, select
inline/heap storage using capacity `+0x14 >= 16`, and write a leading NUL.
Signed ECX>=7 does nothing; negative ECX is not rejected. The allocation and
capacity are retained. No free or network send occurs in this body.

### `0x1d7f96` — send_empty_variable_request (50 bytes)

Requires nonzero byte at VA `0x12a229a`, a nonnegative upstream destination
at VA `0x123d9fc`, and a nonnegative local slot. It asks the packet builder
for type `0x95` and sends a 4-byte packet through the envelope/send wrapper
at RVA `0x1d8c57` to the upstream destination. This body adds no variable
payload and has no retry or return-status check. The meaning of the first
gate is not recovered; calling this an unconditional reconnect request would
overstate the evidence.

### `0x1d7fd0` — receive_tagged_variables (330 bytes)

ECX points to a received packet. It maps the byte at packet `+4` to a sender
slot and stops on a negative result. Byte `+5` is the entry count; entries
start at `+6`. The byte at `+3` equal to `0x98` supplies the setters' force
argument. Each entry starts with a little-endian 16-bit tag:

| Tag part | Meaning in this reader |
|---|---|
| bits 0..13 | base variable index |
| bit 14 (`0x4000`) | string when set, integer when clear |
| bit 15 (`0x8000`) | sender-relative client-local index when set |

For sender-relative integers it uses `128 + 16*senderSlot + baseIndex`;
for strings, `32 + 8*senderSlot + baseIndex`. Otherwise indices at or above
128/32 consume one extra player-identifier byte and call the respective
remapper. A negative remapped index skips application while still advancing
past the entry. The string record then has a one-byte length and exactly
that many bytes; they are copied to scratch at VA `0xb6da400`, NUL-terminated
there and passed to the string setter. The integer record has a 32-bit
value, passed to the integer setter. Entry sizes are `3+extra+stringLength`
and `6+extra`, with `extra` zero or one.

Application uses `apply=1`, send mode from VA `0x129aa0d`, and the force
flag above. There is no total packet-length parameter or upper-table-index
guard in this body. The caller's envelope checks are separate; this contract
does not certify arbitrary untrusted byte buffers as safe inputs.

### `0x1d811a` — receive_integer_range (185 bytes)

ECX points to a compact integer packet and EDX is a signed sender slot. A
negative slot or zero byte at packet `+6` yields no application. The word
at `+4` carries a lower-15-bit range start plus a high-bit mode flag;
the count is byte `+6`. Dword values begin at `+0x17`.

In ordinary mode the index is rangeStart plus entry ordinal. Indices >=128
use the player-identifier byte at `packet+7+(index-128)/16` and the integer
remapper. Only final indices <=383 pass its unsigned guard. This ordinary
mode applies only when VA `0x129aa0d` is zero. In high-bit mode it reads
the key from the per-player table base VA `0x129bb10` using
`16*senderSlot+ordinal`; the low-15-bit range start does not contribute to
that key lookup. Both modes call the integer setter with apply=1 and force=1.
The code does not bound count or total source length here, and the high-bit
path has no corresponding final-index guard.

### `0x1d81d3` — send_client_variable_snapshot (619 bytes)

Runs only when VA `0x129aa0d` is zero and the local slot is nonnegative.
It sets the refresh-forcing byte and first builds type `0x96`: the range
word has bit 15 set, count 16 is written at `+6`, sixteen player identifiers
are copied into `+7..+0x16`, and sixteen current client-local integer values
are written from `+0x17`. The values are also applied locally to the
corresponding per-player integer keys. The resulting size is 87 bytes.

It then builds type `0x98` packets containing the eight client-local strings.
Each tag is `0xc000 | clientStringOrdinal`; the one-byte length is clamped
to 255, with that many bytes copied after it. A packet is flushed after
the accumulated size exceeds 256, or after the final string; this is a
post-append threshold, not proof of a 256-byte capacity. Destination is the
upstream value in ordinary mode, or the sentinel `0xedededed` in the other
branch. Finally it clears the refresh-forcing byte. Buffer allocation limits
remain the packet builder's contract, not this body’s.

### `0x1d843e` — set_string_variable (621 bytes)

ECX is a name hash and EDX a C-string pointer. Three stack arguments select
local apply, send and force, in that order. It searches the 160 session
string hashes, then the 8 client-local hashes; an unknown hash returns.
Session indices >=32 identify a player slot by `(index-32)/8`. A client-local
hash recursively applies to the current local slot's session key first,
when a local slot exists.

If force is false, it compares the old and new C-strings; an equal string
normally bypasses the registry write, unless the refresh-forcing byte is set.
Local apply gates that write. The send branch still has its separate gate:
send requested, a nonnegative local slot, and send-suppression byte clear.
It builds type `0x99` with one entry, uses bit 14 for a string and bit 15
for a client-local key, and inserts an explicit player byte for a session
index >=32. It clamps the encoded length to 255 without copying a trailing
NUL. Packet sizes are `9+length` or `10+length`. Server mode sends to every
slot below the current player-count bound except local; ordinary mode sends
upstream. This body does not itself validate the source pointer or recover
the wrapper's reliability settings.

### `0x1d86ab` — set_integer_variable (785 bytes)

ECX is a name hash, EDX the new dword; the same three stack arguments select
apply, send and force. It searches 384 session hashes, then 16 client-local
hashes. A match saves the old cache value and stores the incoming value in
that cache **before** most later policy checks. A client-local value also
recursively updates its per-player key when a local slot exists.

Session indices >=128 split into player slot `(index-128)/16` and field
ordinal `(index-128)%16`. In one guarded player-state-5 case, every ordinal
except 2 suppresses local apply and sending, and uses the old value for
subsequent processing; the early cache store has already occurred. Ordinal
0 sets VA `0x129a9fc`; ordinal 3 also writes bits 0 and 1 of the supplied
value to the player record's bytes `+0x36` and `+0x37`. Their gameplay
names remain unknown.

The ordinary unchanged-value shortcut is bypassed for force, refresh, the
client-local ordinal 2 and certain per-player ordinals. Apply calls the
registry integer writer; ordinary mode then invokes another notification
helper. Send requires its argument and the send-suppression byte clear.
Type `0x99` encodes one 16-bit index tag followed by the dword, plus a
player byte for a per-player session index. Client-local tags set bit 15.
Lengths are 12 or 13 bytes. Server mode broadcasts excluding local; other
mode sends upstream. A cache update, a registry write and a packet send
are distinct effects and do not necessarily all occur for one call.

### `0x1d89fb` — allocate_variable_storage (147 bytes)

Preserves and returns incoming ECX. It allocates `0x2000` bytes for 512
16-byte records and clears the first three dwords plus the following byte
in each record; the remaining padding is not explicitly initialized there.
The allocation pointer is stored at VA `0x129aa24`. It separately allocates
`0x10670` bytes, invokes a constructor 17 times at stride `0xf70`, stores
that pointer at VA `0x129aa54`, then zeroes the entire second allocation.
The helper identities are inferred allocator/free conventions corroborated
by the release worker. The final zeroing still executes after a null second
allocation: this body does not provide graceful out-of-memory recovery.

### `0x1d89bc` — release_variable_storage (63 bytes)

If VA `0x129aa24` is nonzero, passes it to the free helper, then stores the
poison value `0x8123` in that global. If VA `0x129aa54` is nonzero, frees
it and sets that pointer to zero. It does not iterate player destructors.
Because the first pointer becomes a nonzero poison value, calling this
worker repeatedly is not shown safe; the guarded wrapper below owns the
single-release condition.

### `0x1d8ac4` — release_variable_singleton (35 bytes)

Loads the owner pointer at VA `0x129b088`. If zero, returns. Otherwise calls
the storage-release worker, passes the owner pointer and constant 1 to a
second deallocation helper, then clears the owner pointer. Repeated calls
through this wrapper therefore skip release after the first normal completion.
There is no thread lock or exception recovery in this body.

## Implications and remaining boundary

The strings named `NetIVarCRCs` and `NetSVarCRCs` identify **name-key tables**.
Their values select registry items; they are not a digest of all synchronized
state. This distinguishes three mechanisms that previously shared the word
CRC: case-folded variable-name hashing, cache consistency checks, and the
separate world/state-transfer checks described in [the network model](NETWORK.md).

The packet readers and writers establish tagged integer/string record
layouts, but this is not a complete session protocol. Transport delivery,
packet-builder capacity, opcode dispatch to these readers, identifier lookup,
the meaning of all state/flag globals and runtime ordering remain unresolved.
The send wrapper is external; the record does not establish ACK policy,
channel selection, deduplication or authorization at these entry points.

All eighteen spans decode completely, contain return instructions and have no
immediate jump escaping the retained span. This is a structural check, not proof that
every dynamic call succeeds or that historical inventory lengths capture
every function in the subsystem. Supporting registry helpers show type tags
1=string, 2=integer and 3=float, but their error-handler exits remain outside
the contracts counted here.
