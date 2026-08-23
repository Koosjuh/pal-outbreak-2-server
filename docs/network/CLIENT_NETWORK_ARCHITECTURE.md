# Client network architecture

Date: 2026-07-28
Target: PAL `SLES_533.19`

## Scope and method

This reconstructs the client architecture from decoded PAL code plus runtime
evidence. It does not assign semantic names merely because a decompiler or the
KDDI reference used one. Addresses in `0x001xxxxx` are main-ELF virtual
addresses. Functions in `0x005ac300...` are identified with their active
overlay; the same address range is reused by `2.DAT` and `3.DAT`.

## Architectural layers

```text
Network setup / pre-login
  NTGUI.ELF + 9.DAT/netaq + IOP IRXs
             |
             v
DNS + HTTP/DNAS compatibility services
             |
             v
PAL TCP application service (TCP 10127, main ELF 0x001c....)
  authentication/session bootstrap -> server records -> endpoint choice
             |
             v
SN@P transport (UDP 9090, main ELF 0x001d.... / 0x001e....)
  registration -> reliability/crypto -> opcode dispatcher
             |
             v
Lobby/room application (3.DAT/netwk.bin, base 0x005ac300)
  area -> room list -> create/join -> roster/rules/ready
             |
             v
In-game networking (2.DAT/game.bin, same overlay base)
  decoded code exists; PAL session establishment and wire messages remain unmapped
```

The IOP side supplies AVE-TCP socket plumbing. SN@P framing, registration,
reliability, crypto and opcode dispatch live in the EE main ELF
(`analysis/snap-module-map.md:33-51,137-160`). `3.DAT` is the only code overlay
that selects/opens the lobby/room SN@P connection; `2.DAT` consumes an already
established connection for in-game networking
(`docs/findings/protocol/_archive/RE-overlays-2026-06-15.md:50-76`).

## Initialization and shutdown

### Network stack initialization

- `9.DAT`/`netaq.bin` loads the SNAVETCP, SNIOPINT, DHCP, DEVGLUE and SMAP
  modules and runs the network acquisition queue. It does not choose the game
  service endpoint (`docs/findings/protocol/_archive/RE-overlays-2026-06-15.md:78-82`).
- `SNIOPINT.IRX` identifies itself as the AVE-TCP EE↔IOP interface; the
  SNAVETCP/AVETCP modules contain generic UDP/TCP send/receive paths
  (`analysis/snap-module-map.md:137-160`). Class: `Decoded`.
- `FUN_001d46ec @ 0x001d46ec` allocates a `0x624`-byte SN@P connection,
  initializes delivery/send/retransmit queues and the three-subpool message
  allocator, creates a UDP socket, and binds a local port beginning at 2000
  (`docs/specs/L1-snap-transport-spec.md:263-272`). Class: `Decoded`.

The exact boot-to-IOP call sequence and all shutdown functions have not been
given stable semantic names. This is `Unknown`; the available evidence proves
the module boundary and per-SN@P-connection construction, not every global
network-stack transition.

### Endpoint selection and DNS

- The TCP server-selection records ultimately supply a connect host. The current
  server places its host in `0x6504`/`0x6510` fields
  (`server/snap_server.js:1333-1359,1411-1431`).
- `3.DAT` connect configuration uses globals around `0x35bed8`, `0x35bee0` and
  `0x35ba98`. `FUN_006150b0` configures them; `FUN_00626900` opens the session;
  main-ELF `FUN_001e2928` resolves the name/address
  (`docs/_archive/reverse-engineering/evidence/function-index.md:11-23`;
  `docs/findings/protocol/_archive/RE-overlays-2026-06-15.md:61-68`).
- No other code overlay was found to establish an alternate lobby/room endpoint
  (`docs/findings/protocol/_archive/RE-overlays-2026-06-15.md:86-101`).

Class: `Decoded`; the exact priority between cached IP, hostname and all fallback
fields is `Probable`.

### Connection, retry, timeout and teardown

`FUN_00626900` polls `FUN_0061e7f0` for established bit `0x10`, has a
300-tick timeout and approximately three retries. Its completion callback
`FUN_00626730` maps result code to visible `820 + result`
(`docs/_archive/reverse-engineering/evidence/function-index.md:11-20`).

At transport level, `FUN_001d5460` applies a +200 ms retransmission backoff and
sets connection latch `+0x50c` after retry exhaustion. Runtime work showed pool
allocation failure `0x65`, rather than this `0x66` retry latch, caused the early
lobby walls (`docs/specs/L1-snap-transport-spec.md:198-215`). Class: `Both`.

Server op40 refreshes client liveness at connection `+0x7c`; without it the
client reaches error 840 after about 57 seconds
(`docs/specs/L1-snap-transport-spec.md:280-287`). Class: `Both`.

Room exit is not fully proven. The client sends a reliable type-2 close
represented in notes as `0xb000`; simply echoing it does not dispatch. A screen-6
fallback advances after roughly 930 frames, or socket-drop, but runtime has
shown both a graceful disband dialog and connection errors
(`docs/findings/protocol/SPEC-DECOMPILE-CLOSEOUT-2026-07-18.md:7-24`;
`docs/findings/protocol/SESSION-LOG-2026-07-25.md:181-201`). Class: `Unknown`.

## TCP 10127 application plane

### Framing and buffering

`FUN_001c3880` parses:

| Offset | Size | Encoding | Meaning |
|---:|---:|---|---|
| `0x00` | 2 | BE | Payload length |
| `0x02` | 1 | byte | Direction (`0x01` client query, `0x02` server tell, `0x10` server challenge/broadcast) |
| `0x03` | 2 | BE | Command |
| `0x05` | 1 | byte | Command parameter / `p5` |
| `0x06` | 1 | byte | Error; `0xff` takes client error paths |
| `0x07` | 1 | byte | Parameter / `p7` |
| `0x08` | variable | command-specific | Payload |

Evidence: client decode and current parser/builder
(`server/snap_server.js:284-338`). Class: `Decoded`; runtime command walk makes
the framing `Both`.

The server accumulates stream bytes and only dispatches after
`recvBuf.length >= 8 + payloadLen`, so fragmented frames and multiple buffered
frames are handled by the parsing loop (`server/snap_server.js:1713-1736`).
That is verified server behavior; a dedicated fragmentation fixture is still
missing.

### Variable fields and byte order

`FUN_001c3b90` fields contain a BE length, BE checksum, then bytes XORed with
`MINAMIOH`, `(salt + p5 + i)`. Numeric TCP payload readers/builders use BE
unless a specific handler proves otherwise (`server/snap_server.js:340-390`).
Class: `Decoded`.

### Authentication/session establishment

The observed PAL boot uses a server challenge/CONNCHECK and client
`0x6110` session verification. On the boot path the server returns a `0x6101`
login seed; on the post-lobby resume path it returns a `0x6110` endpoint/session
payload (`server/snap_server.js:855-903`). The current server uses minimal zero
values that are known to advance the client, not a production account-security
scheme.

HTTP/DNAS services are implemented in `server/http_server.js` and
`server/dnas_server.js`, but this audit found no evidence that they provide
cryptographic authentication suitable for an Internet-facing production
service. Their compatibility role is demonstrated by successful login flows;
their security/session semantics remain `Unknown`.

### Server-list and data walk

The client walks PAL-specific commands:

- `0x6103/0x6104`: keyed chunk manifest/fetch, not PAL CHECKVERSION.
- `0x6203/0x6204`: area-data manifest and chunks.
- `0x1007`, `0x6211..0x6213`, `0x6501..0x6504`, `0x6510`, `0x1004`:
  lobby/server-record initialization and completion.

Command-to-handler code and decoded comments are in
`server/snap_server.js:59-119,941-1083,1085-1435,1437-1603`.
Rig goldens prove this walk reaches server selection and the UDP service
(`GOLDENS.md:53-118`). Class: `Both` for the demonstrated path; unused branches
such as `0x6401/0x6402` are `Decoded` or `Unknown` rather than runtime-proven.

## UDP 9090 SN@P transport plane

### Wire framing

The serialized frame is:

| Offset | Size | Encoding | Meaning |
|---:|---:|---|---|
| `0x00` | 2 | BE | Upper flag bits plus low-10-bit SN@P length |
| `0x02` | 2 | BE as a word; commonly viewed as sub byte + opcode byte | Message selector/opcode |
| `0x04` | 4 | bytes | Session/source token word |
| `0x08` | 4 | BE | Reliable message sequence/id |
| `0x0c` | 4 | BE | ACK/session token word, meaning depends on frame class |
| `0x10` | variable | opcode-specific | Body |
| after encoded length | 4 | bytes | Trailer `ba 47 66 11` |

The low-10-bit length includes the 16-byte header and body, but excludes the
4-byte trailer. Client packet-object `+0x2c` maps to wire `+0x00`, and object
`+0x3c` maps to wire body `+0x10`
(`docs/specs/L1-snap-transport-spec.md:40-79`;
`analysis/snap-packet-struct.md:43-58,145-173`). Class: `Both`.

Confirmed flag bits are reliable `0x8000`, carries-ACK `0x4000`, and coalesced
`0x0800`. The general meanings of `0x2000` and `0x1000` are not known; they
select routing/callback behavior case by case
(`docs/specs/L1-snap-transport-spec.md:58-74`). Preserve them as flags rather
than naming unsupported peer roles.

### Encryption, integrity, compression

`FUN_001d72a8` checks the trailer before reliable acceptance. The relevant body
is processed in 8-byte Blowfish blocks using connection key material associated
with `SNAP-SWAN`; header and trailer remain plaintext
(`docs/specs/L1-snap-transport-spec.md:83-113`). Registration reply processing
also has a password/identity-derived Blowfish step in `FUN_001d9678`
(`analysis/snap-focused-callgraph.md:116-155`).

There is no evidence of a checksum beyond the trailer/magic checks on UDP, and
no evidence of compression. Those features are `Unknown`, not absent by proof.

### Receive buffering, fragmentation and coalescing

UDP datagrams below 20 bytes, from an unexpected source, or with an invalid
trailer are dropped before dispatch. `FUN_001d6988` handles SN@P subframes and
reliable ordering. Coalesced subframes are walked only after body decryption;
raw ciphertext must not be interpreted as inner headers
(`docs/specs/L1-snap-transport-spec.md:83-113`;
`analysis/op06-accept-criterion-RE-2026-07-26.txt:27-68`).

No application-level fragmentation/reassembly format beyond coalesced SN@P
subframes is proven. Large messages are bounded by the receive allocation path
and observed message sizes; an independent fragmented-app-message contract is
`Unknown`.

### Reliability, ACKs and ordered delivery

There are two related but distinct mechanisms:

1. For client-sent reliable data, an inbound frame carrying ACK information
   causes an exact message-ID lookup/removal in the client send queues
   (`FUN_001e1ac8`). The server therefore ACKs every client reliable ID
   individually. This behavior is decompile- and runtime-verified
   (`docs/specs/L1-snap-transport-spec.md:143-175,342-359`).
2. For server-sent reliable data, `FUN_001d6988` accepts a message into the
   reorder path only when `msgSeq >= expected`. Contiguous delivery advances
   expected sequence; late/below-expected frames are freed and never
   acknowledged. ACK bookkeeping occurs before application dispatch
   (`analysis/op06-accept-criterion-RE-2026-07-26.txt:42-107`).

The July 26 op06 experiment proved the practical contract: making op06 the first
contiguous message after create acceptance caused the ACK base to advance across
both messages and populated client memory
(`docs/findings/protocol/SESSION-LOG-2026-07-25.md:206-229`). Class: `Both`.

## Lobby and room application (`3.DAT` / `netwk.bin`)

### Area selection

The TCP plane supplies the ten area boxes/rule metadata. The live area-select
population query is UDP op48, not the old TCP `0x6205` assumption. The current
server answers op48 and a selector-6 completion for area entry; golden evidence
proves repeated area enter/back cycles (`GOLDENS.md:53-84`;
`server/game_udp_server.js:602-625,1653-1680,1981-2002`). Class: `Both`.

### Lobby and room list

The in-area client sends four reliable op49 queries built by
`FUN_005c14a0`. Replies are matched by registered query ID and parsed by
`FUN_005c3da0`/`FUN_005c13e0`. Records have a `0x28` stride and carry current,
flags, max, and an opaque room handle
(`docs/specs/L3-app-protocol-spec.md:25-79`;
`docs/findings/protocol/SPEC-DECOMPILE-CLOSEOUT-2026-07-18.md:26-37`).

The room handle is intentionally treated as opaque and round-tripped in the
captured byte order. Numeric record fields consumed through byte swaps are BE;
the current server has a flag-controlled BE writer
(`server/game_udp_server.js:2250-2346`). Class: `Both` for displayed vacant/list
behavior; exact semantics of every LOID/STAT request term remain `Probable`.

### Room creation

The client performs two op0c prepare stages before op04. Server op28 selector 12
completes each op0c stage; op28 selector 4/status 0 accepts op04 and releases
the create ownership/UI gate (`server/game_udp_server.js:1684-1759,2377-2437`;
`docs/findings/protocol/G12-create-accept-wireformat-RE-2026-07-12.md`).

Current runtime can create a room and place the creator in the registry. The
July 26 run proved a contiguous server op06 self-join populates the roster row,
current count and max in client memory. The displayed roster still does not
refresh at that boundary (`docs/findings/protocol/SESSION-LOG-2026-07-25.md:206-229`).
Class: `Both` for memory/state; visible completion is not proven.

### Room joining and roster synchronization

The July 16 golden proves a second client can join and reach its room screen,
using op10 sub-`0x0c` join acceptance. It does not prove correct mutual roster,
counts or subsequent lifecycle (`GOLDENS.md:28-51`).

Mapped roster vehicles:

- op06: member-JOIN delta, consumed by `FUN_005bb4d0`, then roster-add event.
- op07: member-LEAVE delta, consumed by `FUN_005bb670`, then compaction.
- op0a: whole member-list/durable member-data buffer; it is not the visible-row
  insertion vehicle.
- op10 sub-`0x11`: count update.

Evidence: `analysis/roster-row-draw-RE-2026-07-25.txt:13-54`;
`docs/findings/protocol/SPEC-DECOMPILE-CLOSEOUT-2026-07-18.md:48-53`.
Class: `Decoded`; op06 create-self and join acceptance are `Both`; a complete
join/leave synchronization cycle is `Unknown`.

### Password, rules, character, scenario, ready and start

Area rule/modifier bytes and some op09/op10 consumers have been decoded, and
the server contains corresponding experimental replies. However:

- password comparison/storage wire semantics are not proven;
- the full room-rule publication/acknowledgement order is not captured;
- outbound character/charstats publication is not mapped;
- ready-state opcode and authoritative start condition are not mapped;
- game-start session handoff is not mapped.

These remain `Unknown` despite partial parsers and reference-server names.
Current golden evidence explicitly reports chat, scenario/cast/rules and start
as incomplete (`GOLDENS.md:38-47`).

### Chat

KDDI uses commands in a `0x67xx` family, but no PAL lobby-chat wire vehicle has
been proven. Treating KDDI IDs as PAL IDs would violate observed PAL command
reuse. Class: `Unknown`
(`docs/spec/kddi-vs-snap-gap-register.md`; `docs/specs/L3-app-protocol-spec.md:17-21`).

## In-game networking (`2.DAT` / `game.bin`)

Static evidence proves `2.DAT` contains in-game networking, including multiple
`nbSendPlayerOther` paths and calls into the main-ELF SN@P region. It uses an
established connection rather than selecting a new endpoint
(`docs/findings/protocol/_archive/RE-overlays-2026-06-15.md:70-76`;
`analysis/claude-game-module-full-2026-05-29.txt`).

The KDDI reference has a separate TCP 8590 opaque relay and GSLOGIN, but that is
not PAL proof (`docs/spec/kddi-reference-spec.md:40,447-453,676`). No successful
PAL game-start capture links the decoded `game.bin` sends to a server endpoint,
framing, opcode, host/relay topology or synchronization authority. Therefore:

- peer vs dedicated relay vs host-mediated topology: `Unknown`;
- gameplay session establishment: `Unknown`;
- in-game synchronization message layouts/opcodes: `Unknown`;
- reconnection during gameplay: `Unknown`.

This is the largest unincorporated decoded-code area and must be traced only
after the pre-game start transition is reproducible.
