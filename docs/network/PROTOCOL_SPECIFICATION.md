# PAL protocol specification

Date: 2026-07-28
Status: evidence-led partial specification

Unknown fields deliberately remain `unknown_*`. Lengths include the complete
wire frame unless a row says “payload” or “SN@P encoded length.” See
`OPCODE_MATRIX.md` for command-by-command status.

## 1. Service topology

| Service | Transport | Client phase | Status |
|---|---|---|---|
| DNS | UDP/TCP 53 as provided by local network | Resolve HTTP/DNAS and selected server endpoints | Runtime-compatible; full fallback policy unknown. |
| HTTP/DNAS | HTTP plus DNAS compatibility path | Pre-login/account/session bootstrap | Runtime-compatible; production auth semantics unknown. |
| PAL application/list service | TCP 10127 | Authentication/session, server/area data and server selection | Demonstrated. |
| SN@P interactive service | UDP 9090 | Area population, lobby, room and pre-game application messages | Demonstrated through partial create/join. |
| Gameplay service | Unknown for PAL | In-game synchronization | Not demonstrated. KDDI TCP 8590 is reference-only. |

Evidence: current server composition in `server/start_all.js`; PAL/KDDI separation
in `docs/specs/L3-app-protocol-spec.md:17-21` and
`docs/spec/kddi-reference-spec.md:40`.

## 2. TCP 10127 frame

```text
0x00  u16be payload_length
0x02  u8    direction
0x03  u16be command
0x05  u8    p5
0x06  u8    error
0x07  u8    p7
0x08  u8[payload_length] payload
```

Total frame length is `8 + payload_length`. Direction values observed/decoded:

- `0x01`: client query/request.
- `0x02`: server tell/reply.
- `0x10`: server challenge/broadcast class.
- `0x28`: game-server class exists in reference code/current constants but is
  not proven as a PAL TCP 10127 flow.

The client treats header error `0xff` as failure in command handlers. The server
must buffer TCP bytes until a complete frame exists and retain surplus bytes
for subsequent frames (`server/snap_server.js:284-338,1713-1736`).

### 2.1 TCP numeric serialization

Decoded numeric readers and all demonstrated manifest/count layouts use
big-endian integers. Do not generalize this to opaque blobs or UDP application
records without a specific read/write trace (`server/snap_server.js:340-349`).

### 2.2 `snapField`

```text
u16be encoded_length_plus_2  // plain_length + 2
u16be checksum               // (sum(plain) + p5 * 0x101) & 0x7fff
u8[plain_length] encoded

encoded[i] = plain[i] XOR "MINAMIOH"[i & 7]
                       XOR ((salt + p5 + i) & 0xff)
```

Evidence: decoded `FUN_001c3b90` mirrored at
`server/snap_server.js:363-390`. The demonstrated server uses salt zero; the
complete origin/lifecycle of client state salt is not proven for every command.

## 3. UDP 9090 SN@P frame

```text
0x00  u16be flags_and_length
0x02  u8    sub_or_selector_byte
0x03  u8    opcode
0x04  u8[4] session_token_word0
0x08  u32be reliable_sequence_or_zero
0x0c  u32be ack_or_session_token_word2
0x10  u8[]  body
...   u8[4] trailer = ba 47 66 11
```

`flags_and_length & 0x03ff` is the encoded length from wire `0x00` through the
body, including the 16-byte header and excluding the trailer. Minimum ordinary
datagram length is 20 bytes. Evidence:
`docs/specs/L1-snap-transport-spec.md:40-79`.

### 3.1 Flags

| Mask | Proven effect |
|---:|---|
| `0x8000` | Reliable/reorder channel |
| `0x4000` | Carries ACK information |
| `0x0800` | Coalesced SN@P subframes follow |
| `0x2000` | Routing attribute; general semantic name unknown |
| `0x1000` | Callback-slot/routing selector; general semantic name unknown |

Observed high-byte forms include `0x30`, `0x60`, `0xa0`, `0xb0`, `0xb8`,
`0xf0`, `0xa1`, and `0xe1`. The low byte also contains encoded-length bits, so
these values must not be parsed as an independent one-byte “packet type” without
reconstructing the full BE word
(`docs/specs/L1-snap-transport-spec.md:58-74`;
`analysis/op06-accept-criterion-RE-2026-07-26.txt:82-91`).

### 3.2 Trailer and crypto

The receiver rejects unexpected source, short datagrams or invalid trailer
before application dispatch. Body encryption uses Blowfish in 8-byte blocks
with connection key material associated with `SNAP-SWAN`; serialized header
and trailer remain plaintext. Coalesced inner headers are parsed after
decryption (`docs/specs/L1-snap-transport-spec.md:83-113`).

Registration has an additional identity/password-derived decrypt/compare path
in `FUN_001d9678`; do not assume all messages share identical key derivation
(`analysis/snap-focused-callgraph.md:116-155`).

No UDP compression format is known.

### 3.3 Reliable receive contract

For every client reliable message, the server sends an exact-ID ACK:

```text
0x00  60 10
0x02  00 00
0x04  inbound token word0
0x08  00 00 00 00              // unless reverse data semantics require otherwise
0x0c  u32be acknowledged_id
0x10  ba 47 66 11
```

Total length: 20 bytes. Evidence:
`docs/specs/L1-snap-transport-spec.md:143-175`.

Server reliable transmissions must use a contiguous per-session sequence. On
the client, `FUN_001d6988` accepts reliable `msgSeq >= expected` into reorder
handling, and in-order release advances the expected sequence. A below-expected
message is freed without an ACK. Transport acceptance occurs before opcode
dispatch (`analysis/op06-accept-criterion-RE-2026-07-26.txt:42-107`).

The server must retain unacknowledged reliable frames and retransmit the
original sequence; creating a new sequence for every retry changes ordering
semantics. The current server contains a reliability window implementation,
but not every experimental send path uses a single production abstraction
(`server/game_udp_server.js:827-1015`).

### 3.4 Client resource constraints

Client message allocation has three subpools. op48/op49 request the largest
subpool. Its hysteresis disables allocations at free count ≤2 and only clears
at ≥4. Prompt exact ACKing across the area-to-lobby transition prevents the
one-shot op49 allocation failure
(`docs/specs/L1-snap-transport-spec.md:218-259,342-359`).

### 3.5 Identity across services

The client presents one 32-byte DNAS token twice per login, and that token is the
only source-address-independent link between the services (R-020):

- HTTP: `GET /mhweb/index.jsp?DNAS=<base64>` on the client's first request.
- TCP 10127: the `0x1007` payload is one opaque lead byte followed by one
  `FUN_001c3f40` field whose 44-byte plaintext is the same base64 string. The
  field's checksum verifies with codec byte zero, so the decode is
  self-validating rather than assumed.

It is byte-identical across three emulator captures and one real PS2 capture, so
it identifies the account, not the console or the address.

V2 therefore keeps three separate identities
(`server-v2/src/sessions/connection-identity.js`):

| Identity | Established by | Key |
|---|---|---|
| Connection | the server, per TCP socket | server-minted reference; never sent by the client |
| Authenticated session | the HTTP login flow | the DNAS token the client presents |
| Player | the account the session authenticated | account userid, reached only through a valid session |

Source address is recorded for diagnostics and is never a lookup key. V1
correlated its post-lobby resume window by source IP with a 60 s TTL, which
cannot distinguish two consoles behind one NAT and cannot survive a rebind.

The captured later connections carry no `0x1007` and therefore no token, so they
remain anonymous. That is consistent with what they do: they walk the server list
(`0x6501`/`0x6510`/`0x1004`), which is server-global data needing no player
identity. V2 allows anonymous connections to exist and refuses any player-scoped
operation on them. How a later connection could be bound to a session if one were
ever needed remains **Unknown**.

## 4. Session establishment

### 4.1 TCP bootstrap

The working minimal sequence is:

1. server `0x6001` challenge/connection check;
2. client `0x6110`;
3. server `0x6101` login seed on boot path;
4. client continues the PAL manifest/list command walk;
5. after `0x1004`, the TCP socket can close and a second connection can issue
   `0x6110`;
6. server responds `0x6110` with session/endpoint fields.

Code/evidence: `server/snap_server.js:855-903,1585-1603`. Exact credential,
account and replay/security semantics are unknown.

The locally reconstructed V2 lobby-initialization sub-ladder now has six
independently bounded exchanges:

1. client `0x1007`, 49 opaque bytes → server mode `0`;
2. client payload-less `0x6103` → server `countBE16=0`;
3. client payload-less `0x6212` → server one BE32 field;
4. client `0x6203` variable encoded-field envelope → server mode byte `0x02`;
5. client payload-less `0x6211` → server one BE32 field;
6. client payload-less `0x6213` → server eight ordered BE16 fields.

For step 3, main-EE `FUN_001c42d0 @ 0x001c42d0` is the request builder and
`FUN_001c4360 @ 0x001c4360` consumes the BE32 through `FUN_001c3b10`, then
sets `conn+0xd=0x10`. Twelve saved exchanges contain two unique request/reply
pairs and next emit `0x6203`
(`captures/snap_session2_{in_4,out_5,in_5}_*.bin`;
`docs/findings/protocol/SESSION-LOG-2026-08-01.md` T3).

The BE32 field's domain is **Unknown in PAL code**. BioServer calls command
`0x6212` `AGLPLAYERCNT` and derives a membership count, but its payload is
two bytes. V2 emits the PAL width when an explicit server-state provider exists.
Without one, it sends a payload-less status-`0xff` response; `FUN_001c4360`
then stores its executable-owned zero default and advances unconditionally
(`server-v2/src/tcp/lobby-initialization-session.js:201-274`).

For step 4, main-EE `FUN_001c48c0 @ 0x001c48c0` calls
`FUN_001c4020`/`FUN_001c3f40`. The latter writes BE16 `sourceLength+2`, a
second BE16 returned by `FUN_001c3650`, then `sourceLength` encoded bytes.
Only that envelope is assigned: the second u16, encoded content, and field
meaning remain **Unknown**. Main-EE `FUN_001c4960 @ 0x001c4960` reads one
response byte; `0x02` sets `conn+0xd=0x14` without another payload read.
Twelve saved triplets contain two exact request/reply variants and then
payload-less `0x6211` (`captures/snap_session2_{in_5,out_6,in_6}_*.bin`; T4).
V2 implements only this mode-2 branch. It does not copy V1's rejected mode-1
experiment with invented cache contents.

For step 5, main-EE `FUN_001c4560 @ 0x001c4560` builds internal operation
`0x16`, appends no payload, and sets `conn+0xd=0x15`. Dispatch reply slot
`0x17` maps wire `0x6211` to `FUN_001c45f0 @ 0x001c45f0`, which invokes
`FUN_001c3b10` for one BE32, stores it at `0x0036847c`, and routes next state
by major state: `{0,1,7}->0x0e`, `2->0x2d`, other->0x31`. This is corroborated
directly from tracked SLES instructions `0x001c45f0..0x001c4688` (T5).
The BE32 domain meaning and source remain **Unknown**. Twelve V1-backed saved
triplets contain two exact zero-valued replies and next `0x6213`; they prove
client tolerance in those runs, not that zero is universally correct. With no
explicit provider, V2 instead selects `FUN_001c45f0`'s decoded payload-less
status-`0xff` branch, which stores zero and follows the same major-state routing.

For step 6, main-EE `FUN_001c43c0 @ 0x001c43c0` builds internal operation
`0x1a`, appends no payload, and sets `conn+0xd=0x0f`. Dispatch reply slot
`0x1b` maps wire `0x6213` to `FUN_001c4450 @ 0x001c4450`. The parser calls
BE16 reader `FUN_001c3ab0` eight times and stores the ordered words at
`0x00368484..0x00368492`, then unconditionally writes `conn+0xd=0x04`; that
scheduler path emits `0x6501`. Direct tracked-SLES disassembly corroborates
the builder, all eight calls/stores, and the state write (`0x001c43c0..0x001c455c`).
The canonical explicit-value response payload is the 16 bytes consumed by the parser;
whether trailing response bytes are tolerated is **Unknown**.

Decoded overlay consumers establish partial neutral data flow: words 0-3 feed
configuration state, words 4-5 are copied and clamped to `0xfa`, and words 6-7
seed a two-stage countdown path only when both are nonzero. Complete semantic
names and the normal server producer remain **Unknown**. The parser's status-`0xff`
branch consumes no payload, assigns executable-owned fallback values, and advances.
V2 selects that decoded branch when no explicit `resolveCommand6213Words` override
exists; it does not serialize those constants as a claimed normal server payload.
Twelve V1-backed zero replies prove only tolerance of the separate explicit-value
branch (T6-T7).

For step 7, `FUN_001c6dc0 @ 0x001c6dc0` builds internal operation `0x1c`,
appends exactly one BE32 from `0x00365e00`, and waits in substate 5. Reply
parser `FUN_001c6e80 @ 0x001c6e80` treats response status `0xff` as an error/reset.
With status zero it reads a mode byte. Mode 0 reads no additional payload and
routes by client major state toward `0x6502` or `0x6510`; its canonical/minimal
response is 9 bytes total. Mode 1 reads two BE32 in order, stores the first at
`0x00365e04` and second at `0x00365e00`, then routes toward `0x6503`; its
canonical/minimal response is 17 bytes total. Other modes reset/error. Trailing
reply-byte tolerance, the request/response field meanings, and production mode
selection remain **Unknown**. V2 therefore requires a tagged resolver and does
not default to V1's captured mode 0 or its mode-1 zero placeholders (T8).

For step 8, `FUN_001c7580 @ 0x001c7580` builds internal operation `0x1e` and
appends a record BE32 followed by one variable `FUN_001c4020` encoded field.
The request is therefore at least 16 bytes total; the payload BE16 at offset 4
equals payload length minus 6. In the normal-status branch, reply parser
`FUN_001c7680 @ 0x001c7680` reads a mode byte. Mode 0 reads no more data and
either loops to `0x6502` or completes toward `0x6510`. Mode 1 reads two BE32 in
order and advances toward `0x6504`. Canonical/minimal replies are 9 and 17 bytes
total respectively; trailing tolerance remains **Unknown**. Other-mode and
status-`0xff` branches exist but are not implemented by T9. V2 requires a tagged
resolver and does not default to the V1-captured mode 1 values `1,1`.

For step 9, `FUN_001c7980 @ 0x001c7980` builds internal selector `0x22`,
appends two BE16 values and one complete variable encoded field, then waits in
substate `0x0b`. The normal response consumed by `FUN_001c7a70 @ 0x001c7a70`
starts with `unknown_total:u16be`, `unknown_start:u16be`, and
`record_count:u8`. Each record is consumed as variable field (decoded maximum
`0x0f`), variable field (maximum `0x0f`), eight raw bytes, variable field
(maximum `0xff`), two BE16, and one BE32. The paired
`FUN_001c3f40`/`FUN_001c3650` encoder and `FUN_001c3b90`/`FUN_001c3750`
decoder prove the `MINAMIOH` transform and plaintext checksum. Runtime PINE
evidence proves codec-state byte zero for the captured path and confirms all
fields were decoded into the client record pool. V2 accepts an explicit codec
byte, does not hard-code that observation, and requires neutral record Buffers
and integers from `resolveCommand6504Response`. A server-side safety/liveness
policy caps the first value at the client's 64-record storage limit, requires a
nonempty in-range batch, and emits no trailing bytes. The parser/scheduler route
an incomplete batch to another `0x6504`; completion may route to `0x6502` or
`0x6510`. Field meanings, production data, nonzero-status behavior, and
real-client V2 acceptance remain **Unknown** (T10).

For step 10, `FUN_001c85c0 @ 0x001c85c0` builds command-index `0x24`, which the
SLES_533.19 tables `DAT_002484c0`/`DAT_00248510` map to wire command `0x6510`
with client direction `0x01`. Direct disassembly `0x001c85c0..0x001c8720` shows
the batch size loaded as `li v0,12`, lowered only to the remaining record count
(`total - sent`), stored at `0x00365e1a`, and then written as one count byte via
`FUN_001c3da0`. The builder appends that many `FUN_001c4020` encoded fields taken
from the page record-pointer array at `0x00365f80`, then one further encoded field
from the page block at `+0x20`, and parks in substate `0x0d`.

Reply parser `FUN_001c8790 @ 0x001c8790` is bound to direction `0x02` of `0x6510`
by receive-dispatch entry `0x25` at `DAT_00248600`. In the normal-status branch it
reads one count byte and compares it with the batch count the builder stored
(`bne s3,v0` at `0x001c8884`). Only an equal count makes it read `count` BE16
values and store each at record offset `+0x12c`, decimal 300 (`sh v0,300(v1)` at
`0x001c8900`). It then decodes exactly one trailing field bounded to `0x3e`
decoded bytes (`li a2,62` at `0x001c892c`; `FUN_001c3b90` returns `-2` above that
bound). The cursor then advances by the returned count: while it remains below the
page total the parser selects substate `0x0c` for another `0x6510`; otherwise it
routes by connection major state — `4` selects substate `0x10` (`FUN_001c48c0`,
command index `0x12` = `0x6203`), major `5/1/7/0` advances the page and either
loops at `0x0c` or reaches substate `0x31` (`FUN_001c8dd0`, command index `0x05`
= `0x1004`), and any other major state resets.

Unlike the `0x6212`/`0x6211`/`0x6213` receivers, `0x6510` has no safe status-`0xff`
client-default branch: at `0x001c87bc` the `0xff` path falls through to the cursor
block at `0x001c898c` with `s2`/`s3` still holding caller-saved values. V2 therefore
requires `resolveCommand6510Response`, always echoes the request count, supplies
exactly one word per requested record, and never answers `0x6510` with `0xff`. The
request's encoded fields are kept opaque by V2. The server cannot observe the
client's connection state at `+0x4c` that `FUN_001c3b90` decodes with, so treating
them as opaque is the conservative choice; it is not strictly forced, since R-016
established codec byte zero on the captured walks and both captured `0x6510`
requests decode cleanly with it. The
meaning of the stored BE16, the contents of the page trailer, their production
source, the count-mismatch branch, and real-client V2 acceptance remain
**Unknown** (T11).

For step 11, substate `0x31` calls `FUN_001c8dd0 @ 0x001c8dd0`, which builds
command index `0x05` — wire command `0x1004` — with direction `0x01` and appends
no fields, so the terminal request is exactly the eight-byte header; the scheduler
then parks at substate `0x33`. Receive-dispatch entry `0x06` binds direction
`0x02` of `0x1004` to `FUN_001c8e90 @ 0x001c8e90`, which disassembles to
`jr ra` / `li v0,1`: it reads no reply payload at all. In `FUN_001c9b00` a handler
return of 1 increments the connection top-level state byte at `+0x0c` (unless it
is already 7) rather than selecting another substate, so this reply completes the
lobby-initialization phase. Entry `0x07` binds direction `0x10` of the same
command to `FUN_001c8ea0` (`li v0,-1`, an error return), so the reply must use
direction `0x02`. `FUN_001c8dd0` additionally guards on `cRam0035ccb4`: when set
it resets to state 7 and sends nothing. Two receivers set that flag -- the
status-`0xff` major-4 branches of `FUN_001c7680` (store at `0x001c7714`) and
`FUN_001c7a70` (store at `0x001c7b14`) -- and `FUN_001c9b00` clears it at
`0x001c983c`. V2 answers neither `0x6502` nor `0x6504` with `0xff`, so the guard
stays clear in the V2 flow. V2 answers the
payload-less request with an empty status-zero frame and then decodes nothing
further on the connection.

The termination is no longer Unknown. Capture R-019 shows the CLIENT ends the
connection and the server never closes first: on real PS2 the client sends RST
70 ms after the reply (`0x1004` reply at t=10.392, RST at t=10.462); on the
emulator it sends a graceful FIN at the same point and the server FINs back. V2
therefore holds the connection open after the completion, writes nothing more,
and treats a post-completion reset as normal termination rather than a fault.

The same captures show the client opening a NEW connection ~17 s later on a fresh
source port, in which the SERVER speaks first with an unsolicited
`0000106001010000` (`0x6001`, direction `0x10`) and the client then runs
`0x6501 -> 0x6510 -> 0x1004`. That second ladder does not begin with `0x1007`, so
connection purpose cannot be inferred from the first client frame. What still
remains **Unknown** is the meaning of the incremented top-level state, how the
second connection is correlated to the first beyond V1's source-IP-keyed
`post-lobby-resume` window, and real-client V2 acceptance (T12, T15).

### 4.2 UDP registration

Client `0x2c` registration:

- `FUN_001db7e8` allocates a body capacity of `0x86`;
- body `+0x00` carries a bounded identity string;
- body `+0x28` carries an optional second string;
- network/order fields occur at `+0x64..+0x74`;
- TLV-like LC/MR tail begins at `+0x78`.

Server responds with `0x2d`. `FUN_001d9678` decrypts body, compares the leading
identity to client state, reads endpoint/session fields and advances registration
state to 2 (`analysis/snap-module-map.md:66-119`;
`analysis/snap-focused-callgraph.md:116-155`).

Observed registration datagrams are 154 bytes total with encoded length `0x96`,
but exact optional-tail contents and all server reply fields remain partial
(`docs/specs/L1-snap-transport-spec.md:274-278`).

A kind `0x31` opcode `0x01` bind follows registration in the working flow.
Its 570-byte observed request and every field have not been fully specified;
the server treats it as an establishment/bind event
(`server/game_udp_server.js:1283-1311,3027-3048`).

## 5. Application data layouts

### 5.1 op48 named/area query

Confirmed response family:

```text
body+0x00  u32       request/status identifier (byte order per traced builder/parser)
body+0x04  u32       status_or_unknown
body+0x08  u32       record_count
body+0x0c  record[record_count], stride 0x24

record+0x00 char[16] identifier/name
record+0x10 u32be    displayed area/player count in the area query path
record+0x14 u32be    unknown_14
record+0x18 u32be    unknown_18
record+0x1c u32be    unknown_1c
record+0x20 u32be    unknown_20
```

The query/tag variants and all five numeric meanings are not universally
proven. The currently demonstrated area-count consumer reads the value at
record `+0x10`; preserve the rest as unknown. Evidence:
`server/game_udp_server.js:602-625,728-779`;
`docs/findings/protocol/G12-count-displays-RE-2026-07-17.md`.

### 5.2 op49 room-list query/reply

Captured request body begins with zero and term count, followed by tags such as
`LOID` and `STAT!`; the client sends four subqueries. A representative captured
layout is recorded at `docs/specs/L3-app-protocol-spec.md:25-43`.

Confirmed success reply:

```text
body+0x00  u8        status (0 success; 0x27 failure in parser path)
body+0x01  u8        continuation/unknown_01
body+0x02  u16       continuation_count_or_unknown_02
body+0x04  u32       query_id / match key (exact placement depends on callback wrapper)
body+0x08  u32       record_count
body+0x0c  record[record_count], stride 0x28

record+0x00 char[?]  room name/identifier region
record+0x14 numeric  current players
record+0x18 numeric  unknown_18
record+0x1c numeric  status/flags
record+0x20 numeric  maximum players
record+0x24 u32      opaque room handle
```

The client byte-swaps the displayed numeric fields, so current server records
write those values BE. The opaque handle is round-tripped in the observed native
byte order and must not be normalized without evidence. Parser and UI evidence:
`docs/specs/L3-app-protocol-spec.md:45-79`;
`docs/findings/protocol/SPEC-DECOMPILE-CLOSEOUT-2026-07-18.md:26-37`;
server writer `server/game_udp_server.js:2250-2346`.

### 5.3 op28 completion multiplexer

op28 is a server response multiplexer, not one application entity. Its body
starts with a BE selector used by `FUN_001d9f78`; the sub byte at wire `+0x02`
can be a generation/match key. Proven selectors in current paths:

| Selector | Completes |
|---:|---|
| `4` | op04 create acceptance |
| `6` | op06 area/room entry |
| `7` | op07 leave |
| `8` | op08 create/leave stage |
| `12` | op0c prepare/query |

For repeated area cycles the reply sub byte must echo the request generation;
hard-coding zero causes later completions not to fire (`GOLDENS.md:53-69`;
`server/game_udp_server.js:1653-1680,1691-1728,1981-2002,2377-2407`).

### 5.4 op06 member-JOIN

Confirmed server-to-client body:

```text
body+0x00  u32le      member_id / player number
body+0x04  unknown[?]
body+0x0c  char[16]   display/login name     // wire +0x1c
body+0x18  u8[0xf0]   character/stat blob    // wire +0x28
```

The production builder currently emits a 284-byte total frame. The handler
`FUN_005bb4d0` copies the record to scratch and causes the event that inserts
the row. Exact intermediate reserved bytes should remain unknown
(`analysis/roster-row-draw-RE-2026-07-25.txt:53-...`;
`server/game_udp_server.js:1127-1163`;
`docs/findings/protocol/SESSION-LOG-2026-07-25.md:206-229`).

Client-to-server opcode `0x06` is also used for area/room entry. Those request
bodies are phase-dependent and must be separated by connection state and
handle, not treated as the same record layout
(`server/game_udp_server.js:1653-1680,1764-1868,1981-2002`).

### 5.5 op07 member-LEAVE

Confirmed server-to-client frame fixture:

```text
SN@P encoded length 0x20; total datagram 0x24
opcode 0x07, sub 0
body+0x00 u32le leaver_member_id
body+0x04..0x0f unknown/reserved
trailer ba 47 66 11
```

Decoded client consumer reads the native/LE ID and compacts the roster.
Evidence: `server/leave-op07-wire.test.cjs:34-60`;
`docs/findings/protocol/SPEC-DECOMPILE-CLOSEOUT-2026-07-18.md:48-53`.
The full client leave request/ack/broadcast order remains unproven.

### 5.6 op0a member list

The current whole-list record stride is `0x118`:

```text
record+0x00 char[16] member name
record+0x10 u32      member_id
record+0x14 u32      unknown_14 / record length candidate
record+0x18 u8[0xf0] character/stat blob
```

It feeds a durable member-data buffer used by member detail, not the visible
roster insertion path. Exact outer reply count/status fields and byte order
should be taken from the builder/parser for each test
(`analysis/roster-row-draw-RE-2026-07-25.txt:13-19`;
`server/game_udp_server.js:1071-1110,2105-2203`).

### 5.7 op10 room subcommands

The client routes on the byte at wire `+0x18` (body `+0x08`). Mapped values:

| Sub | Current evidence-led role | Status |
|---:|---|---|
| `0x01` | room/member descriptor (`0x300`-byte data region in current reply) | Decoded/partial |
| `0x02` | join request | Both for July 16 path |
| `0x03` | configuration reset/update candidate | Decoded/partial |
| `0x05` | room current/max limits | Both for maximum display; complete fields partial |
| `0x06` | rule names | Decoded/partial |
| `0x07` | rule descriptions | Decoded/partial |
| `0x08` | rule attributes | Decoded/partial |
| `0x09` | fixed rule values | Decoded/partial |
| `0x0c` | join acceptance with current count | Both for room-screen entry |
| `0x0e` | liveness/query | Runtime-observed, response semantics probable |
| `0x0f` | liveness reply candidate | Probable |
| `0x11` | current-player count update | Decoded |

Evidence: overlay projection map and current router
(`docs/spec/client-memory-ui-projection-map.md:49-88`;
`server/game_udp_server.js:1871-2000`). A subcommand label does not imply the
entire packet layout is known.

## 6. Unspecified protocol regions

The following must not be implemented from KDDI names alone:

- PAL lobby chat command and broadcast;
- password publication and comparison;
- complete room-rule negotiation;
- character selection/stat publication;
- ready/unready and start authorization;
- gameplay endpoint/session handoff;
- `2.DAT` in-game message framing and state synchronization;
- reconnect/resume semantics for lobby or gameplay.

All are `Unknown`. The KDDI reference can supply testable lifecycle hypotheses,
but PAL behavior remains authoritative.
