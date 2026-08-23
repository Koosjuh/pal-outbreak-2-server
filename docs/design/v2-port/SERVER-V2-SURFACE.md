# SERVER-V2 IMPLEMENTATION SURFACE — inventory for the bioserver-logic port

Written 2026-08-08 by a survey subagent. Source of truth is the working tree at
`db60236b` (branch `exp/t33-nonce-only`; the handoff's deployed code commit is
`68b1a59f`, which is an ancestor — the files surveyed here are identical to the
deployed set except where noted). Every claim below is classified:
**Observation** (read from code / test run today), **Inference**, **Hypothesis**.
Rig-confirmed status is copied from `docs/handoff/COLD-START-2026-08-08.md` §3,
never asserted independently.

---

## 0. Process topology (Observation)

One process, composed in `server-v2/src/app/application.js`
(`createApplication`), launched by `server-v2/bin/pal-server-v2.js`. Listeners
bind in a fixed order and fail-closed as a group (all or none):

| Listener | Port | Module | Role |
|---|---|---|---|
| `tcp10127` | 10127 | `src/tcp/tcp10127-service.js` + `src/tcp/lobby-initialization-session.js` | boot-auth transcript OR the lobby-initialization ladder, selected by the arming registry |
| `http` | (config) | `src/http/web-service.js` | `lbs.jsp` browser sign-in, account provisioning |
| `dnas` | (config) | `src/dnas/*` | DNAS platform auth replay (TLS), token issue |
| `dns` | (config) | `src/dns/*` | name resolution pointing consoles here |
| `udp9090` | 9090 | `src/udp/register-service.js` → `src/udp/snap-lobby-sessions.js` | the SN@P register/bind AND the entire post-selection lobby phase |

Shared infrastructure: one `TimingWheel` (`src/transport/timing-wheel.js`) for
every timer in the UDP phase; `openProductionRepositories`
(`src/database/production-repositories.js`, SQLite + scrypt accounts); a
`PublishableDirectoryProvider` over the operator directory file; a
`ConnectionIdentityRegistry` + `AccountSessionRegistry` +
`LobbyArmingRegistry` for identity; and — central to this survey — one
`PresenceRegistry` and one `LobbyRoomRegistry` shared between the UDP lobby
subsystem and the TCP counts.

---

## 1. SN@P opcode inventory — UDP :9090

Two phases, two dispatchers.

### 1.1 Register phase — `src/udp/register-service.js`

Handles raw datagrams before a lobby session exists. Opcode constants live in
`src/protocol/snap-udp-register-codec.js`.

| Opcode | Dir | Handler | What it does | Status |
|---|---|---|---|---|
| `0x2c` REGISTER | in | `register-service.js` (`#onRegister` path, reply ~line 560) | Account lookup by login identity; reply `0x2d` Blowfish-encrypted with the account password; opens a fresh epoch in `RegisterSessionTable` (`register-sessions.js`), captures the client's `LC` TLV (watchdog budget), optionally mints a 16-byte attachment nonce (`registration-nonces.js`, default ON since T33) | rig-confirmed (whole sign-in path works) |
| `0x2d` REGISTER-REPLY | out | same | The encrypted reply; tail carries the attachment nonce | rig-confirmed |
| `0x00` TRANSPORT-ACK | in/out | dispatch loop ~line 393 | 20-byte transport acknowledgement; sent for the bind and the post-lobby snapshot | rig-confirmed |
| `0x01` BIND (326 B) | in | `#onBind` (~line 775) | The post-register bind. Verifies the nonce echo (the ONLY attachment proof — address/port/token are all client-supplied), answers transport ACK + the slot-0x1c push (op-0x28 selector 1, CONSTANT sequence), arms the TCP lobby, establishes the account session, and **opens the `SnapLobbySession`** — which is also where the presence record is created (depth `server`) | rig-confirmed |
| `0x01` POST-LOBBY SNAPSHOT (566 B) | in | `#onPostLobbySnapshot` (~line 640) | Same opcode, distinguished by length. Answered with ACK + slot-0x1c push; deliberately does NOT arm TCP and does NOT consume a stamped sequence | rig-confirmed (38 archived sessions) |
| `0x02` APP-ACK | in | dispatch ~line 384 | Client's application acknowledgement of the register reply — the success signal | rig-confirmed |
| anything else | in | dispatch ~line 402 | Observed and logged, never answered (silence, not `0x31`) | design decision |

Once a lobby session exists for the source, every non-register/bind datagram is
routed to `SnapLobbySessions.get(routingKey).accept(datagram)` (dispatch, ~line
340).

### 1.2 Post-selection lobby phase — `src/udp/snap-lobby-session.js`

`SnapLobbySession#dispatch` (line 568) is THE opcode switch of the lobby.
Payload encode/decode is entirely in `src/udp/snap-lobby-codec.js`
(`LOBBY_OPCODE`, `COMPLETION_SELECTOR`, `ROOM_STATE_SUB`); framing (who/flags/
sequence/ack/trailer) is entirely in `src/transport/reliable-channel.js`.

Inbound (client → server), in dispatch order:

| Opcode | Name | Handler | Reply | What it does |
|---|---|---|---|---|
| `0x48` | NAME_QUERY | `#onNameQuery` | direct op-0x48, sub echoed | Area Select. Returns 10 area records from `AreaDirectory` with **live per-area populations** from `playerCountFor` (presence). Polled ~25 Hz; logs once per session. Record `+0x10` = population (the "Server full" gate operand), `+0x20` = area key. **Rig-confirmed T37: all 10 areas + live counters.** |
| `0x0c` | ROOM_QUERY | `#onRoomQuery` | op-0x28 sel `0x0c`, sub (= match key) echoed | Answers BOTH the connect-screen query and the create-PREPARE (classified by server context, `#classifyRoomQuery`; the ANSWER is identical). Rig-confirmed. |
| `0x0d` | REENTRY_QUERY | `#onReentryQuery` | op-0x28 sel `0x0d` | Second trip to the lobby; no key match exists on this client path. Rig-confirmed (re-entry works once — see B3). |
| `0x06` | AREA_ENTER (inbound) | `#onAreaEnter` | op-0x28 sel 6 status 0 | Resolves the request's `+0x20` key against the directory, then `presence.moveTo(record, {boxId})` — **mutate first, then emit** (rule L1). Rig-confirmed. |
| `0x07` | AREA_LEAVE | `#onLeave` | op-0x28 sel 7 | Zero-length reliable LEAVE. One message means both "leave room" and "leave area"; server ascends the presence cursor by exactly ONE level (`presence.ascend`). Rig-confirmed once per session; **B3: the client never sends a second one** (client-side suspect). |
| `0x04` | CREATE_ROOM | `#onCreateRoom` | accept: op-0x28 sel 4 `[BE32 4][BE32 handle]`; reject: op-**0x27** sel 4 | Decodes the 0x2c-byte request; `rooms.openFor({presence, host, boxId, name, max})` mints a handle and moves the host into the room (slot 0) atomically; then `#sendCreateFollowUps` pushes op-0x06 member-JOIN + op-0x10 sub-5 room limits. Reject is an OPCODE change (0x27), not a status field. **Rig-confirmed working on real PS2.** |
| `0x0f` | CHAT | `#onChat` | none to sender; relay op-0x0f to peers | Selector 0 = chat text, relayed verbatim via the `relayChat` seam (scope = sender's presence location: room, else area; sender excluded). Selector 1/2 = area-name probe, consumed. 2-byte short variant (~230/session, meaning Unknown) consumed at debug. Bounds-checked hard (client memcpys unchecked). Deployed, NOT yet observed 2-console. |
| `0x0a` | MEMBER_LIST | `#onMemberList` | **direct** op-0x0a, sub MUST be 0 | One of the three post-create batched queries. Handle resolved in EITHER byte order (`resolveRoomHandleBytes`); members = `presence.rosterOf(handle)`. Fills the client's DATA table, not the drawn roster. Fired in T37. |
| `0x09` | AREA_COUNT_QUERY | `#onAreaCountQuery` | direct op-0x09, handle+tag echoed | `"USER"`/`"MAXI"` counted query. **First field is a BOX ID** (corrected 2026-08-08 from T37 wire; the spec's "handle" label was wrong). USER = presence count in area (room-handle fallback accepted); MAXI = room capacity (unexercised on a real console). Deployed post-T37, untested on rig. |
| `0x08` | NAMED_CHANNEL_QUERY | `#onNamedChannelQuery` | op-0x28 sel 8 status 0 | The `"STAT"` query. Its reply is the ONLY exit from the 14-phase roster SM's phase-1 unbounded wait (`FUN_005c6500`) — the doorway to game start (B1). NOT the exit button. Fired in T37. |
| `0x49` | ROOM_LIST | `#onRoomList` | direct op-0x49 | Rooms of the asker's own presence area (`roomListProvider(boxId)`); empty list is a real state. Display fields BE, handle LE at `+0x24` (both rig-derived). Answered correctly in T37 (B2: the JOINING client freezes after receiving it — client-side unknown next message). |
| `0x41` | KEEPALIVE_RESPONSE | `#onKeepaliveResponse` | none (channel ack only) | Counted; V1's archive shows ack-and-nothing-else. |
| `0x14` | RTT_PROBE | `#onRttProbe` | none | 68 bytes of 0x55, absorbed at debug. |
| other | — | default | none | Logged `lobby-observed-message`, unanswered. |

Outbound-only messages (server → client):

| Opcode | Built by | When | Status |
|---|---|---|---|
| `0x40` KEEPALIVE | `buildKeepalivePayload` (0x110 B Blowfish-ECB zeros under key `SNAP-SWAN` + 4 zero bytes), timer in `#sendKeepalive` | every 5 s per session, UNRELIABLE, period validated against the client's declared `LC*32+4000` budget | **rig-confirmed; the entire 840 defence** |
| `0x06` MEMBER_JOIN (outbound) | `buildMemberJoinPayload` (0x108 B record) | first in-window reliable after the create accept (`#sendCreateFollowUps`) | rig-confirmed to populate roster row 0. **DELTA — client accumulates; emit only from transitions** (V1's T19 bug) |
| `0x10` ROOM_STATE sub-5 | `buildRoomLimitsPayload` (max/current) | after create accept | rig-confirmed to render "MAX/CURRENT P" header. Must be re-asserted after every screen rebuild |
| `0x10` sub-0x11 | `buildMemberCountPayload` | built, deliberately NOT sent at create | codec only |
| `0x28` COMPLETION / `0x27` REJECT | `buildCompletionPayload` / `buildCreateRoomAcceptPayload` | replies above | rig-confirmed (sel 1, 4, 6, 7, 8, 0x0c, 0x0d) |
| `0x29` SUCCESS_TRANSITION | `buildSuccessTransitionPayload` | NEVER sent by default; disassembly-only, gated behind explicit config | never captured |
| `0x0f` chat relay | `buildChatRelayPayload` → `deliverChat` | fan-out from `SnapLobbySessions.#relayChat` | deployed, unobserved 2-console |

Transport rules that are load-bearing (Observation, `reliable-channel.js` +
handoff §4 — **do not "simplify"**):

- Every app reply is a windowed reliable DATA message that STAMPS its own
  sequence; the slot-0x1c push alone carries a CONSTANT sequence.
- The batch walk: an aggregated (`0x0800`) datagram is walked sub-message by
  sub-message and **degrades to the outer message when a sub-header will not
  parse** (the create batch must walk; the op-0x48 batch's second sub-header is
  Blowfish ciphertext and must not). `TOO_MANY_MESSAGES` fails closed.
- A thrown handler is converted to a `HANDLER_THREW` refusal inside
  `accept()` — no peer bytes may kill the process.
- Refused sends: first logged in full, then one rollup per 100, except
  `everyRefusalMatters` sends (ENTER/LEAVE/CREATE accepts — asked once, parked
  on forever).

### 1.3 TCP :10127 command inventory — `src/tcp/lobby-initialization-session.js`

Not SN@P-framed, but part of the same client conversation. Purpose per
connection is selected by `LobbyArmingRegistry` (armed by `lbs.jsp` or by the
UDP bind): unarmed = boot auth, armed = lobby ladder.

| Command | Role | Status |
|---|---|---|
| `0x1001`/`0x1002`/`0x1004` | boot-auth transcript (server speaks first) | rig-confirmed |
| `0x6001` | lobby challenge (server-first) | rig-confirmed |
| `0x6103` | keyed manifest request | rig-confirmed |
| `0x6212` | pre-area handshake (one BE u32) | rig-confirmed |
| `0x6203` | AREACOUNT — area-table version + chunk table; version match lets the client skip `0x6204` (why the handoff says power-cycle the PS2 after a table bump) | rig-confirmed |
| `0x6204` | AREANAME — the area blob (`src/state/area-table.js`, `OBAREA-V3`) in fixed slices; carries the rule masks, `+0x16c` min/max, `+0x12fc` option table | rig-confirmed for rendering; rule-mask publication (68b1a59f) NOT yet rig-tested |
| `0x6211`, `0x6213` | payload-less ladder steps | rig-confirmed |
| `0x6501` | mode selector; also THE resume frame (a `0x6501`-first connection reattaches the retained `LobbySession`/projection) | rig-confirmed |
| `0x6502` | entry select | rig-confirmed |
| `0x6503` | server-entry list (the only command that writes the client's entry table); batched | rig-confirmed |
| `0x6504` | per-entry records incl. "max players" (the Server-full gate's right operand) | rig-confirmed |
| `0x6510` | "current players" — **derived live** from `presence.countInServer('self')` via `createDirectoryBackedProviders` | rig-confirmed ("1/ 2" pagination works) |

---

## 2. The state model (Observation)

### 2.1 PresenceRegistry — `src/state/presence.js` — the single home of WHERE

Location is a **path with a depth**:

```
depth 0 detached | 1 server(serverEntryId) | 2 area(boxId) | 3 room(roomHandle) | 4 slot(slot)
```

- **Invariant P1 (prefix-closure):** a non-null level implies every shallower
  level non-null; enforced by throwing, and applied as a consequence
  (clearing a level clears everything below).
- **Invariant P2 (single home):** nothing else stores location — not the
  session, not the room. `SnapLobbySession.enteredBoxId` is a getter over the
  presence record.
- **Sets, not counters:** `#byServer/#byArea/#byRoom` are `Map<key,
  Set<Presence>>` indexes over the one `#presences` map (keyed on
  `accountSessionId`, never the source address). `assertConsistent()` rebuilds
  and compares (invariant I1).
- **Three mutations only:** `attach` (at bind-accept, depth server — the
  ordering fix: four of six count sites are asked before any ENTER),
  `moveTo` (one synchronous function; the only writer of location+indices),
  `detach`. Plus `ascend` (one level up — matches the single op-0x07 message).
- **Rule L1: mutate first, then emit** — every count is a query over the set,
  so any message built after the mutation is automatically correct.
- **No `await` anywhere** on a transition or count path — that is the whole
  concurrency design.
- `onRoomEmptied(handle)` fires synchronously when the last member leaves a
  room → the room registry closes it. This — not a sweeper — is what replaces
  bioserver's `cleanGhostRooms`.
- `areaPopulationVersion` — a memo key for the 25 Hz op-0x48 reply (unused by
  the current reply builder; available for caching).
- The journal event `presence-detached` with `{boxId, roomHandle, slot}` the
  task brief mentions is `detach()`'s debug line (line ~400).

### 2.2 LobbyRoomRegistry — `src/state/lobby-rooms.js` — identity and capacity only

- A `LobbyRoom` is frozen: `handle` (minted, monotonic, never reused, non-zero
  — 0 is the client's empty-slot marker), `boxId`, `name` (≤0x13 bytes),
  `max`, `flags`, `ownerAccountSessionId`. **`current` is a getter** over
  `presence.countInRoom(handle)` — the derivation rule: *a field is derived
  iff deleting a session must change it.*
- `openFor({presence, host, boxId, name, max})` — the ONLY creation path used
  in production: mints the handle, opens the room, and `presence.moveTo(host,
  {roomHandle, slot: 0})` in one operation, so a room can never exist with
  zero members. Closed by `onRoomEmptied`.
- Per-area room cap = `MAXIMUM_ROOM_LIST_RECORDS` (what one op-0x49 datagram
  can carry), fail-closed at open.
- `byHandle(handle)` is how a later ENTER/join resolves; callers accept both
  byte orders via `resolveRoomHandleBytes`.
- **Slot semantics today:** presence supports depth 4 and validates
  non-negative integer slots, but the only assignment in the codebase is the
  host's `slot: 0` at `openFor`. There is **no slot allocator, no slot
  vacancy model, no per-slot state** — that is greenfield for the port.

### 2.3 Session layers (identity, not location)

| Layer | Module | Keyed on | Holds |
|---|---|---|---|
| `RegisterSessionTable` | `udp/register-sessions.js` | address:port epoch | endpoint token, login identity, `LC` |
| `RegistrationNonceTable` | `udp/registration-nonces.js` | **the nonce** (the only server-minted, client-echoed value; no address fallback ever) | pending registration → bind attachment proof |
| `AccountSessionRegistry` | `sessions/account-session.js` | account | proof level (`PASSWORD_VERIFIED` / `REGISTRATION_NONCE` / `NONE`), one live session per account, displacement rules, 30-min idle sweep (touched by TCP traffic) |
| `LobbySession` (+`lobbySessions` map in application.js) | `sessions/lobby-session.js` | accountSessionId | the retained `ClientDirectoryProjection` (survives TCP resets; resume reattaches it) |
| `SnapLobbySessions` | `udp/snap-lobby-sessions.js` | routingKey (+ `#routingKeyByIdentity` for displacement) | the live UDP sessions; owns keepalive ciphertext (built once), the fan-out (`#relayChat`), open/close/displacement (detach-then-attach, close-orphan-first), idle release (120 s), `closeAll` |
| `ConnectionIdentityRegistry` / `LobbyArmingRegistry` | `sessions/*` | DNAS token / remote address | TCP connection→account association; boot-auth vs lobby purpose |

### 2.4 Content state

- `AreaDirectory` (`udp/area-directory.js`): exactly 10 areas, each `{boxId,
  name (ends in the 2-digit box id), key (unique — the ENTER token)}`, stated
  provenance (operator / v1-observed / test-fixture); live counts injected per
  reply, never stored. `createV1ObservedAreaDirectory()` is what production
  wires.
- `AreaTable` (`state/area-table.js`): the `0x6204` blob (`OBAREA-V3`),
  rule masks, `+0x16c` limits block.
- `DirectoryState`/`directory-source`/`client-directory-projection`
  (`state/`): the Server-Select entry/record document, per-session projection
  with batch cursors; fail-closed startup validation (≥2 entries, every entry
  has records, capacity is a decision, rig-fixture gate).

---

## 3. Rig-confirmed paths — DO-NOT-DESTABILIZE

Copied from handoff §3 (owner-confirmed T37 unless noted), mapped to code.
Changes that touch these files/paths need nora review and must not be bundled
with port work:

| Confirmed capability | Implementing surface |
|---|---|
| Area Select renders all 10 areas + second lines | `area-table.js` blob, `0x6203/0x6204` ladder, op-0x48 reply (`buildNameQueryReplyPayload`) |
| Area Select population counters LIVE and correct | op-0x48 record `+0x10` ← `playersIn(boxId)` ← `presence.countInArea` |
| Server Select paginates "1/ 2" | `0x6501–0x6510` ladder, `client-directory-projection.js`, `resolveCurrentPlayers` seam |
| Create room works on real PS2 (cursor unfreezes) | `#onCreateRoom` → `rooms.openFor` → sel-4 accept (BE handle) → `#sendCreateFollowUps` (op-0x06 join, op-0x10 sub-5) |
| The three post-create queries answered; batch walked | `#onMemberList`, `#onAreaCountQuery`, `#onNamedChannelQuery`; the batch-walk-with-degrade rule in `reliable-channel.js` |
| Sign-in / register / bind / nonce echo (T33) | `register-service.js`, `registration-nonces.js` |
| op-0x40 keepalive defers 840 indefinitely | `#sendKeepalive`, key `SNAP-SWAN`, unreliable, 5 s, budget check |
| Enter area → in-area lobby; leave once | `#onAreaEnter` (sel 6, who `0xB0`), `#onLeave` (sel 7) |
| Chat implemented (deployed, not yet 2-console-observed) | `#onChat` + `#relayChat` + `deliverChat` |

Also protected by explicit code comments (Observation): the constant-vs-stamped
sequence split; the who-byte forms (`0xB0` ENTER accept, `0xA0` member-JOIN /
success-transition); the op-0x49 handle LE exception; sub-byte echo rules
(`0x0a` sub MUST be 0; `0x0c` sub is the match key); member-JOIN as a
transition-only delta.

---

## 4. Seams for a transport-agnostic bioserver Room/Slot/game-lifecycle port

The architecture already separates transport (reliable-channel), payload codec
(snap-lobby-codec), per-client dispatch (snap-lobby-session), fan-out/ownership
(snap-lobby-sessions), and transport-free state (`src/state/*`). Bioserver
logic (`references/bioserver/` — the app protocol the PAL client speaks)
belongs in the state layer plus new dispatch cases. Concrete plug points:

1. **The constructor seams of `SnapLobbySession`** (all REQUIRED, no defaults —
   an unwired seam refuses to construct): `playerCountFor(area)`,
   `roomListProvider(boxId)`, `relayChat(from, payload)`, `presence`,
   `presenceRecord`, `rooms`. A game-lifecycle port adds seams here the same
   way (e.g. `gameFor(roomHandle)`, `broadcastToRoom(...)`), wired in
   `SnapLobbySessions.open()`. Inference: this is the intended extension
   pattern — the docstrings say exactly this about the zero-default removal.

2. **`#dispatch` (snap-lobby-session.js:568)** — new inbound opcodes (room
   JOIN, game start, scenario select, roster sync sub-ops) are new cases +
   codec functions. The unhandled-opcode default already logs what the client
   sends, so the T37 pcap tells you which case to add next (B2: the joiner's
   next message after the room list is the open question).

3. **`PresenceRegistry.moveTo` / `ascend` / `onRoomEmptied`** — bioserver's
   Room/Slot membership maps directly onto the depth path. The slot level
   (depth 4) exists but is unmanaged: a bioserver-style slot allocator (slot
   status, host migration, per-slot character/NPC state) should be a new
   `state/` module that OWNS slot assignment and calls `presence.moveTo(p,
   {roomHandle, slot})`, keeping P2 (presence stays the single home of the
   assignment itself, the allocator holds the per-slot *attributes*).
   `onRoomEmptied` is the model for further lifecycle hooks (Hypothesis: an
   `onRoomStateChanged`/`onSlotChanged` hook set is the least invasive way to
   drive push messages from transitions, matching rule L1 and the
   "delta only from a transition" constraint on op-0x06).

4. **Room lifecycle state machine** — bioserver rooms carry a status
   (recruiting/full/in-game/post-game). `LobbyRoom` today has `flags` (shipped
   in op-0x49 `+0x1c`) and nothing else. A port would extend the room record
   (kept derived-vs-authored discipline: status is authored by transitions,
   population stays derived), and B1 (game start) hangs off the roster SM,
   whose only currently-served message is the op-0x08 STAT reply. Everything
   past that (the 14-phase `FUN_005c6500` machine, screen 5) is **unmapped
   protocol — nothing is known about what the server must send for an actual
   scenario start** (handoff B1, Observation).

5. **Fan-out** — `SnapLobbySessions.#relayChat` is the template for any
   room-scoped broadcast: scope from the sender's presence, never from the
   message; skip full-window peers; count deliveries. A generalized
   `#broadcast(scope, payload)` extracted from it is the natural first
   refactor for roster/state pushes (Inference).

6. **The TCP side needs nothing for the port** (Inference): rooms/games are
   entirely on UDP :9090; TCP touches shared state only through
   `presence.countInServer` and the projections.

7. **Byte-order and identity hygiene the port must inherit:** handles are
   opaque round-tripped bytes (`resolveRoomHandleBytes` accepts both orders;
   replies echo the request's bytes); identity is the account session, never
   the address; every table is bounded and fail-closed (refuse new, never
   evict live).

---

## 5. Test infrastructure (Observation — run today)

- Runner: `cd server-v2 && npm test` → `node --test` (Node ≥ 22.5, ESM,
  zero dependencies). No config; it auto-discovers `test/*.test.js`.
- **Result 2026-08-08 on this tree: 644 tests, 637 pass, 0 fail, 7 skipped,
  ~33 s.** Matches the handoff's expectation exactly.
- 44 test files. Directly relevant to the port surface:
  `presence.test.js`, `lobby-rooms.test.js`, `snap-lobby-session.test.js`,
  `snap-lobby-codec.test.js`, `snap-lobby-create-room.test.js`,
  `snap-lobby-roster-sync.test.js`, `snap-lobby-chat.test.js`,
  `reliable-channel.test.js`, `timing-wheel.test.js`,
  `udp-register-service.test.js`, `udp-bind-service.test.js`,
  `udp-post-lobby-snapshot.test.js`, `registration-nonces.test.js`,
  `composition.test.js` (whole-application wiring), plus the TCP ladder
  (`tcp10127-*.test.js`) and directory/DNAS/DNS/account suites.
- Determinism comes from injection: the timing wheel is injectable and
  manually advanceable, registries construct side-by-side with no module
  state, `transmit` is a function so tests capture datagrams, and codecs are
  pure. New port modules should follow the same pattern (state module + unit
  tests + a session-level test that drives `accept()` with encoded datagrams).
- The methodology requirement (handoff §0.3): a new test must be shown to
  FAIL when the fix is reverted — a test that cannot discriminate is how a
  dead-code "fix" shipped this session.

---

## 6. Evidence gaps relevant to the port

- **Game start (B1):** no wire, no decompile-complete map of what follows the
  op-0x08 STAT reply. The 14-phase roster SM (`analysis/ROSTER-SYNC-SUBSYSTEM.md`)
  is the entry point; phases 2–14 are unserved and their triggering messages
  unknown.
- **Join (B2):** the message a joining client sends after a correct op-0x49
  `rooms:1` list is unknown — it sent nothing in T37. The answer is in
  `captures/v2-live/T37-20260808-090328.pcap` (both consoles captured).
- **MAXI tag (op-0x09):** never exercised by a real console.
- **op-0x0F short variant:** semantics Unknown (~230/session, consumed).
- **Keepalive key:** raw `SNAP-SWAN` is runtime-proven; the decompile note
  claiming SHA-1 keying disagrees and is outranked, but the ciphertext itself
  has never been captured.
- **op-0x29:** never captured; disabled by default.
- **This tree vs the deployed Pi:** verified today — `git diff 68b1a59f..HEAD
  -- server-v2/src server-v2/test` is EMPTY and `git status` shows no
  uncommitted server-v2 changes, so this inventory describes exactly the code
  deployed to the Pi (`68b1a59f`, md5-verified per the handoff). Observation.
