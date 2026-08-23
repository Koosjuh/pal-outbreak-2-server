# V1 versus corpus functional coverage

Date: 2026-07-31  
Target: PAL `SLES_533.19`

This audit compares what V1 actually implements with the completed network corpus. V1 is a runtime
reference, not a specification. A source-code opcode match is only lexical coverage; it does not prove
the packet layout, state transition, timing, or response.

Regenerate the lexical inventory:

```text
node server-v2/tools/audit-v1-coverage.js
```

## Immediate verified mismatches

### DNS and endpoint selection

- V1 contains a DNS server, but project runtime documentation says the UniFi gateway normally answers
  DNS. Therefore local `dns_server.js` success is not demonstrated by the working Pi flow.
- V1 wildcard-redirects all `*.yav4.com` and `*.dnas.playstation.org`. The corpus confirms resolver and
  endpoint use but does not support treating every name in those domains as a game endpoint.
- V2 must use an explicit configured hostname set extracted from the executable/captures, with
  wildcard behavior opt-in rather than protocol fact.

Evidence:

- `server/dns_server.js`
- `server/README.md`
- `reverse-engineering/network/functions/session/001c08e0_resolve_hostname_cached.md`
- `reverse-engineering/iso/reports/ISO_COVERAGE.md`

### HTTP/account flow

- V1's `COMP-SIGNUP` and `INPUT-IDS` markers are runtime-confirmed and preserved in V2.
- The decoded overlay proves LBS CSV field 2 is the TCP 10127 endpoint. V1 field 5
  (`hex-address,lobby-name`) is stored/displayed but has no decoded UDP endpoint consumer.
- V1's `/reweb/*` empty response is explicitly a capture placeholder and is not implemented as a V2
  fact.
- V1 stores the password because UDP register compatibility requires the exact typed secret. V2
  retains this requirement in a private atomic account store.

Evidence:

- `docs/_archive/reverse-engineering/protocols/http-auth.md`
- `docs/findings/protocol/_archive/http-lbs-provisioning-to-ba98-RE-2026-06-15.md`
- `server/http_server.js`
- `server-v2/src/http/web-service.js`

### DNAS

- V1 implements a hand-built SSLv2/TLS 1.0 endpoint and adapts previously captured DNAS response
  packets. The captured response store is ignored by Git and is currently empty in this checkout.
- Runtime evidence proves a missing replay response causes DNAS rejection; the repository does not
  yet contain a deterministic V2 DNAS fixture.
- The corpus inventory now includes the EE DNAS/HTTP/dbc boundary, but several individual records still
  say deep reconstruction is pending, and `DNAS280.IMG` is not shown as deeply reconstructed in the
  ISO coverage report. V2 DNAS production readiness is therefore blocked on reconciling the Pi's
  working packet assets/captures with those client functions and, where needed, decoding the DNAS
  module.
- V1's successful behavior is valuable runtime evidence, but replay-file presence, TLS transcript,
  response transformation, and accepted client transition must all become fixtures before V2 adopts
  it.

Evidence:

- `server/dnas_server.js`
- `docs/findings/server-behavior/dnas-replay-packets.md`
- `reverse-engineering/iso/reports/ISO_COVERAGE.md`
- `reverse-engineering/network/functions/session/0017e5f8_dbcsock_open.md`
- `reverse-engineering/network/functions/session/001c0f40_auth_conn_sm_modeA.md`
- `reverse-engineering/network/functions/session/001c19e0_auth_conn_sm_modeB.md`

### TCP 10127

V1 declares these commands but has no dispatch handler:

| V1 symbol | Command | Corpus/V2 impact |
|---|---:|---|
| `IDHNPAIRS` | `0x6131` | Identity/handle selection path missing. |
| `HNSELECT` | `0x6132` | Selected handle transition missing. |
| `CHARSELECT` | `0x6190` | Character selection not persisted through this service. |
| `HEARTBEAT` | `0x6202` | TCP heartbeat handling/broadcast missing. |
| `AREASELECT` | `0x6207` | Area selection mutation missing in TCP V1. |
| `ROOMSCOUNT` | `0x6301` | Room-count query missing. |
| `SLOTCOUNT` | `0x6401` | Symbol collides with V1's chunk-list reuse; semantics require state-specific proof. |
| `GO_ONLINE` | `0x6002` | Online transition request missing. |
| `ENTERAGL` | `0x6210` | Aftergame/alternate lobby entry missing. |

Other TCP findings:

- V1 sends a three-packet boot sequence before reading a proven client state, then decides boot versus
  lobby by a pending session keyed primarily by source IP. That is an implementation policy, not a
  decoded client protocol identity.
- V1 uses numerous default-off branches and synthetic/zero data. Examples include area scenario mask
  `0x1f`, rules byte `0xF7` explicitly marked unknown, `snapField` salt zero, hard-coded slot host, and
  empty chunk/status tables.
- V2 must model the decoded client state machine and request order explicitly; it will not copy the
  IP-armed phase heuristic.

Evidence:

- `server/snap_server.js` (`CMD`, `HANDLERS`, boot/lobby connection split)
- `reverse-engineering/network/functions/session/001c9b00_snap_app_sm_pump.md`
- `reverse-engineering/network/BUILD_GUIDE.md`

### SN@P UDP 9090

V1 explicitly branches on a narrow core: registration/control plus opcodes `0x02`, `0x04`, `0x06`,
`0x07`, `0x08`, `0x09`, `0x0a`, `0x10`, `0x48`, and `0x49`. Much of it is gated by experimental
`SNAP_*` flags; unclassified reliable packets can fall into generic suppression/echo behavior.

Decoded client behavior absent or incomplete in V1 includes:

- Fixed session ladder: op `0x00`, `0x18`, `0x1a`, `0x16`, `0x0f`, register information, session
  parameters, and session configuration.
- Full room pager: op `0x1c`, `0x20`, `0x1e`, `0x22` (V1 mainly uses the alternate op49 record).
- Create prepare op `0x26` and its exact reply/state relationship.
- Chat send/relay: reliable op `0x0f` with the decoded name/payload record and in-room scope gate.
- Multiple download/config machines (`0x39/0x3b`, `0x3d/0x3f`, `0x45/0x47`) that must be classified as
  required or unreachable for the production PAL path rather than silently omitted.
- Key exchange op `0x3d/0x41` and other session operations not represented by a stateful V1 handler.
- Gameplay-session establishment and in-game synchronization.

Known contradiction:

- `SERVER_BUILD_PUNCHLIST.md` says a delayed self-op06 re-emit should repaint the creator roster.
  The 2026-07-30 full capture showed the delayed packet was accepted and row memory populated but the
  visible roster remained stale. V2 rejects this timing workaround as a completed mechanism.

Evidence:

- `reverse-engineering/network/protocols/PACKET_INDEX.md`
- `reverse-engineering/network/protocols/SUBCOMMAND_INDEX.md`
- `reverse-engineering/network/BUILD_GUIDE.md`
- `server/game_udp_server.js`
- `docs/findings/protocol/SESSION-LOG-2026-07-30-ROSTER-SETTLE.md`

### Chat

The corpus proves the outgoing chat entry calls op0f and builds
`[type, unknown_0, name_len, payload_len, unknown_1, unknown_2, name, payload]`. It also proves local
echo is client-side, while received in-room sub-event 7 writes fragments into a member record.
V1 has no authoritative chat registry or op0f relay handler. Exact meaning of the type byte and the
sub-event fragment purpose remain unresolved and block production chat implementation.

Evidence:

- `reverse-engineering/network/functions/chat/005c4af0_send_chat_message.md`
- `reverse-engineering/network/functions/chat/005c4bd0_build_send_chat_datagram.md`
- `reverse-engineering/network/functions/chat/005bc1c0_inroom_recv_chat_text.md`

## Corpus elements requiring deeper work

The corpus is inventory-complete but not uniformly reconstruction-complete:

- roughly 600 core functions still lack corrected pseudocode;
- formal runtime-validation tags are sparse;
- the DNAS context structure remains incomplete;
- the roster repaint chain reaches an ntgui function outside the overlay dump;
- IOP modules are inventoried but not all deeply reconstructed.

These are not reasons to guess. Each becomes a bounded RE task when its behavior is required by a V2
vertical slice.

Evidence: `reverse-engineering/network/UNRESOLVED.md`,
`reverse-engineering/iso/reports/ISO_COVERAGE.md`.

## Next audit expansion

1. Generate the lexical opcode/command inventory and check it into the evidence register.
2. Map every V1 reply builder to exact client read offsets and acceptance branches.
3. Classify every corpus opcode/function as required for the normal PAL path, optional feature,
   error/retry path, middleware-only plumbing, or unresolved.
4. Add a V2 test fixture before implementing each required handler.

