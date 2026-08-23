# Server v2 status

Operational handoff: `handoff/V2_IMPLEMENTATION_HANDOFF_2026-08-02.md` records the exact implementation
anchor, repeatable evidence-to-code workflow, completion definition, and safe deployment/capture loop.

## Proven locally

- SN@P 16-byte header, fixed observed trailer, flag/length fields, opcode selector, source token,
  sequence, and acknowledgment codec.
- Byte-exact recorded op28 selector-6 and `0x6010` ACK fixtures.
- Reliable gap buffering, cascade release, duplicate suppression, and one shared outbound sequence
  allocator.
- Atomic account and session persistence.
- Account create/login browser flow backed by encrypted-at-rest compatibility secrets.
- Evidence-locked PAL DNAS application messages, legacy TLS transcript, and bounded socket service.
- Explicit fail-closed DNS over UDP and TCP.
- TCP 10127 eight-byte frame codec and fragmented/coalesced stream reassembly.
- Byte-exact pre-browser `02 10 01` → `02 10 02` → `02 10 04` transcript on a real local socket when
  an external resolver assigns the connection `pre-browser` purpose.
- Captured PAL client `0x1007` lobby-initialization request handling when an external resolver assigns
  `lobby-initialization`: three recorded 57-byte variants produce the decoded nine-byte mode-0 response,
  fragmented and early delivery are preserved, and later framed commands are logged without guessed replies.
- Captured payload-less `0x6103` requests produce the decoded empty keyed-manifest branch
  (`countBE16=0`) with no V1 synthetic key/data; coalesced input advances the V2 session to observation
  of `0x6212`.
- Twelve saved sessions and main-EE `FUN_001c42d0`/`FUN_001c4360` ground the canonical `0x6212`
  exchange: V2 accepts the payload-less request and emits one BE32 field supplied by the
  `resolveCommand6212Value` state dependency. Two unique captured replies and the coalesced socket
  ladder are byte-exact.
- Main-EE `FUN_001c48c0`/`FUN_001c3f40`/`FUN_001c4960` and twelve saved triplets ground the
  neutral `0x6203` mode-2 exchange. V2 validates only the variable encoded-field envelope, leaves
  the second u16/content/meaning opaque, emits the captured one-byte mode `0x02`, and preserves
  payload-less `0x6211` as the next command.
- Main-EE `FUN_001c4560`/`FUN_001c45f0`/`FUN_001c3b10`, direct disassembly from the tracked PAL
  executable, and twelve saved triplets ground the canonical `0x6211` exchange. V2 accepts the
  payload-less request, emits one BE32 from required `resolveCommand6211Value` state, and preserves
  payload-less `0x6213` as the next command. V1's zero is a fixture value, not a default.
- Main-EE `FUN_001c43c0`/`FUN_001c4450`/`FUN_001c3ab0`, direct disassembly from the tracked PAL
  executable, decoded overlay consumers, and twelve saved triplets ground canonical `0x6213`.
  V2 accepts the payload-less request, emits eight ordered BE16 words from required
  `resolveCommand6213Words` state, and preserves `0x6501` as the following command boundary.
- The three decoded receivers for `0x6212`, `0x6211`, and `0x6213` each have an instruction-verified
  status-`0xff` branch that consumes no payload, installs client-owned defaults, and advances.
  V2 uses that branch when the corresponding explicit provider is absent; this is not a generic rule.
- Main-EE `FUN_001c6dc0`/`FUN_001c6e80` and direct disassembly ground `0x6501`. V2 decodes its
  request BE32 neutrally, requires `resolveCommand6501Response`, emits only parser-supported mode 0
  or mode 1 layouts, and handles the branch-specific follow-up of each: `0x6502` after mode 0,
  `0x6503` after mode 1.
- Main-EE `FUN_001c7000`/`FUN_001c70b0` ground `0x6503`, the ONLY command that writes the client's
  entry table at `0x365e20` and its total at `0x365e1e`. V2 answers the four-byte request window,
  bounds `total` to 1..16 (the parser treats 0 as terminal and routes >16 on a state word V2 cannot
  see), serves the entries the client asked for rather than the whole list, and encodes
  host/name/8 raw/description at the parser's own `0x3e`/`0x0f`/8/`0xff` bounds. Implemented T32,
  2026-08-06. **Never yet answered by a real client.**
- Main-EE `FUN_001c7580`/`FUN_001c7680` and direct disassembly ground normal-status `0x6502`.
  V2 validates its BE32-plus-dynamic-field envelope, requires `resolveCommand6502Response`, and
  handles mode-0 loops and mode-1 `0x6504`, while preserving `0x6510` unanswered.
- Main-EE `FUN_001c7980`/`FUN_001c7a70`, the paired variable-field codec helpers, direct
  disassembly, and PINE-backed V1 runtime evidence ground normal-status `0x6504`. V2 requires
  `resolveCommand6504Response`, serializes only neutral bounded records, repeats `0x6504` for an
  incomplete server batch, and preserves `0x6502`/`0x6510` after completion.
- Main-EE `FUN_001c85c0`/`FUN_001c8790`, scheduler `FUN_001c9b00` cases `0x0c`/`0x0d`/`0x10`/`0x31`,
  direct disassembly, and the SLES_533.19 command-index and receive-dispatch tables read straight from
  the executable ground normal-status `0x6510`. V2 validates the count byte, its record fields, and the
  trailing field as an exact payload consumption, requires `resolveCommand6510Response`, echoes the
  request count so the client's batch-count gate passes, emits one BE16 per record plus one field
  bounded to `0x3e`, answers repeated batches, and answers the decoded `0x6203` major-state-4 route
  by re-entering the existing `0x6211` -> `0x6213` -> `0x6501` sub-ladder.
- Capture R-020 grounds the identity model: the client presents the same 32-byte DNAS token as
  `?DNAS=` on HTTP and inside the `0x1007` payload's variable field, byte-identical across three
  emulator captures and one real PS2 capture. `server-v2/src/sessions/connection-identity.js` keeps
  connection, authenticated-session and player identity separate, keys nothing on source address, and
  fails closed on unknown, expired or conflicting associations. The `0x1007` decode is self-validating
  through its checksum.
- The four TCP providers are backed by server state rather than fixtures. `src/state/directory-state.js`
  holds one authoritative, immutable structure - entries of stride `0x260` each owning records of
  stride `0x134` - proved in T17 from `FUN_001c7a70`, `FUN_001c8790` and direct disassembly, with the
  `0x6510` word at record `+0x12c` sitting inside the `0x6504` record and reached through the same
  pointer array. `src/state/client-directory-projection.js` holds everything per connection: the field
  codec word, traversal position, the 64-record client residency budget with entry eviction, and the
  `0x6510` correlation. Four limits are kept apart: 64 records per entry (proven), 64 records resident
  in one client (proven), no limit on authoritative state (unknown, so none imposed), and nothing at
  all modelled for rooms or players. A connection never mutates authoritative state and a disconnect
  removes only its projection.
- The field codec word is known, not guessed. `FUN_001c3b90` and `FUN_001c3f40` both pass
  `*(u16 *)(connection + 0x4c)`; its only writer is `FUN_001c4100`, reachable only by a `0x1002` frame
  carrying direction `0x01`. No captured session contains one - the captured server sent `0x1002` with
  direction `0x02`, which the ELF tables map to a handler-less entry - so `+0x4c` kept its initialized
  value, and all four captured `0x1007` fields decode and checksum with zero and with nothing else.
  Setting the client's codec word would require sending `0x1002` with direction `0x01`; untested.
  `0x6510` keys are decoded under that one word, matched to a record the connection actually holds,
  answered in request order, and failed closed otherwise; V2 never searches codec values until one
  verifies.
- Real PS2 and emulator captures (R-019) ground the connection termination: the client always ends
  the connection after the `0x1004` reply, so V2 holds it open, writes nothing further, and classifies
  a post-completion reset as normal termination instead of a socket fault.
- Main-EE `FUN_001c8dd0`/`FUN_001c8e90` and direct disassembly ground the terminal `0x1004`
  lobby-initialization completion. V2 accepts only the payload-less request and answers with an empty
  status-zero frame, then observes without answering anything that follows. A real local socket walks
  one complete path `0x1007 -> 0x6103 -> 0x6212 -> 0x6203 -> 0x6211 -> 0x6213 -> 0x6501(mode 1) ->
  0x6503 -> 0x6502(mode 1) -> 0x6504 -> 0x6510 -> 0x1004` byte-exactly. A two-entry directory is
  walked through `0x6503 -> (0x6502 -> 0x6504) x2 -> 0x6510 x2 -> 0x1004`; that one is checked on
  frame order, total length and decoded fields, NOT byte-exactly. The mode-0 route is still served
  too, on the connection that opens at `0x6501`. What no test can establish is whether a REAL
  client accepts the `0x6503` reply; that is T32's open gate.

- One composed executable exists. `server-v2/bin/pal-server-v2.js` runs DNS, DNAS, HTTP and the TCP
  lobby service in one ordinary Node.js process over one validated configuration, one authoritative
  directory snapshot and one identity registry. Startup validates everything reachable without a
  socket, then binds TCP, HTTP, DNAS and DNS in order, rolling every started listener back if any
  enabled one fails so the process never serves a partial endpoint set. Shutdown reverses that and
  closes the database last. Zero runtime dependencies: persistence is built-in `node:sqlite`, so the
  Pi needs no native compilation - but it requires Node >= 22.5 for `node:sqlite`, and the Pi's
  recorded runtime is 20.19.2, so a runtime upgrade is an outstanding prerequisite and nothing here
  has been executed on the Pi. See `docs/runbooks/v2-server.md`.
- The identity model is now actually wired, and was not before. `associateDnasToken` was never passed
  to the lobby session, so the `0x1007` token was decoded, checksum-verified and then discarded, and
  any client was served. The composed integration suite caught it on its first run. HTTP binds a
  token to a session at login; TCP associates a connection presenting that token in `0x1007`;
  unknown, released, malformed and expired-session tokens are refused without a byte being served.
  Source address is used for diagnostics only, so two clients behind one NAT stay separable. The
  token also cannot be rebound to a different account while the account holding it has a live
  session, and bindings expire; both are implementation security controls, not captured behaviour.

## Not yet proven

- Real-client V2 DNAS, DNS, HTTP, TCP, or UDP exchange.
- Connection-purpose selection is still external. The captures show BOTH TCP 10127 connections opening
  with a server-sent `0x6001`, after which the first client frame differs (`0x1007` versus `0x6501`),
  so purpose follows the first client frame rather than anything knowable at accept time. V2 does not
  yet implement that, nor the server-first `0x6001`.
- How a later, `0x1007`-less connection could be bound to a session, if that is ever required. The
  captured ones only walk server-global data, so V2 serves them anonymously and refuses player-scoped
  operations.
- Domain meanings and authoritative explicit-provider values for `0x6212`, `0x6211`, and `0x6213`.
  These no longer block production composition because the exact PAL receivers define payload-less
  status-`0xff` client-default branches; real-client V2 acceptance remains untested.
- Production mode/values for `0x6501` and `0x6502`, production `0x6504` record contents, and the
  production `0x6510` record words and page trailer. The state layer now decides where those values
  come from - operator configuration, failing closed when absent - but their MEANINGS remain Unknown.
  The `0x6510` word has a consumer (the Area-Select status `u16`, read from an entry's first record)
  at overlay-decompile grade only; the entry `+0x00` field is not called a page name anywhere in V2.
  `0x6501` now answers mode 1 on a `0x1007`-initiated connection and mode 0 on a `0x6501`-first one
  (T32); which connection deserves which is an INFERENCE from the entry path, because V2 cannot see
  the client's state word. V2 refuses V1 defaults. The `0x6510` count-mismatch branch and
  nonzero-status/fallback behavior remain unimplemented.
- How the second TCP connection correlates to the authenticated session. Capture R-019 settles the
  mechanics: the client ends the first connection (RST on real PS2, FIN on emulator) and reopens ~17 s
  later on a fresh source port, where the server speaks first with `0x6001` and the client runs
  `0x6501 -> 0x6510 -> 0x1004`. V1 armed that resume window per source IP with a 60 s TTL, which is
  not a durable identity. The meaning of the incremented connection top-level state also remains
  Unknown.
- The per-connection projection is a PREDICTION of client state the server cannot observe: the
  client's slot table, per-entry counts and cursors live in its memory. A divergence surfaces as a
  `0x6510` window mismatch that V2 fails closed, and the diagnostic says the cause may be the model
  rather than the client. Only a real-client capture can settle which. The eviction order itself is
  proven (descending scan from slot `0x3f`, `0x001c7d18`/`0x001c7e1c`); what is untested is whether
  V2's reconstruction stays in step over a long walk.
- `0x6501` mode selection is not state: it is chosen from the connection's ENTRY PATH - mode 1 when
  the connection presented `0x1007`, mode 0 when it opened at `0x6501`. `FUN_001c6e80` proves mode
  SELECTS the route (Observation); which route each connection should get is an Inference, since the
  client's state word is not on the wire. It lives in one function, `selectCommand6501Mode`, but
  flipping it to unconditional mode 1 is NOT a one-line change: the resumed connection's projection
  is already COMPLETE, so it would also need a phase and cursor reset. See OQ-016 and T32.
- `test/tcp10127-service.test.js` still drives its ladder with V1's `SLOT0001`, `OPEN` and `Test Slot`
  and with codec byte `0x17`. Those are fixture inputs to a wire-boundary test, not production state,
  but `0x17` would fail against a real client, since the client verifies server fields with the codec
  word it holds. The state-backed ladder in `test/tcp10127-state-backed-ladder.test.js` uses neutral
  values and the connection's real codec byte; the older fixtures are scheduled for the composition
  slice.
- UDP 9090 registration and session establishment in V2.
- Server/area/lobby/room flow.
- Two-client co-location, gameplay start, synchronization, disconnect, and reconnect.

## Current work

Steps 3 and 4 are done: server state behind the four providers, and one composed, state-backed
executable with the identity model wired end to end. Step 4's criterion was a server ready to receive
a first real client, NOT a complete lobby server.

Next is the first real-client capture against the composed server, and recording the first exact
divergence without working around it. The likely candidates, in the order a client would meet them:
the server-first `0x6001` V2 does not send; connection purpose, which the evidence says follows the
first client frame; and `0x6501`, where V2 answered mode 0 while the captures took mode 1 into the
then-unimplemented `0x6503` (implemented T32, 2026-08-06, and not yet exercised by a real client).

**This document is otherwise STALE and owes a full pass.** It still describes identity as gated on
an HTTP-bound DNAS token and UDP 9090 as unimplemented; both were superseded at T24-T27. Only the
`0x6501`/`0x6503` claims above were corrected in T32, because those are the ones T32 falsified.

Two divergences a real client will hit immediately remain unpatched on purpose: the server speaks
first with `0x6001` on both captured connections, and connection purpose follows the first client
frame rather than anything knowable at accept time.
