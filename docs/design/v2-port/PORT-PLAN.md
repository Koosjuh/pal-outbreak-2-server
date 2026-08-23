# PORT PLAN — bioserver application logic into server-v2 over SN@P

Date: 2026-08-08. Synthesized from the five grounding docs in this directory
(`BIOSERVER-CONTRACT.md`, `SERVER-V2-SURFACE.md`, `B2-JOIN-FREEZE-EVIDENCE.md`,
`B1-GAME-START-MODEL.md`, `B3-LEAVE-TWICE-EVIDENCE.md`), the handoff
(`docs/handoff/COLD-START-2026-08-08.md`) and the earlier mapping
(`docs/design/FOUNDATION-MAP-2026-07-17.md`). Every mapping below is tagged with its
evidence class (Observation / Inference / Hypothesis / Conclusion) or, for wire
vehicles, **GROUNDED** (with its evidence) vs **EVIDENCE-GATED** (with the exact
capture / PINE read / decompile that settles it).

**Strategy (agreed):** port the COMPLETE bioserver app logic as a transport-agnostic
engine — systematic, tested locally against reference semantics — but wire it to SN@P
vehicles MILESTONE-FIRST, one grounded message at a time. The vehicle mapping is the
risky part; the engine port is not. Slice 1 = B2 join freeze; slice 2 = B1 game start
(THE milestone); B3 folded in flag-gated alongside slice 1 (rationale in §B.3).

**Owner's constraints, binding:** every slice ends with a player-visible capability;
rules/options/cosmetics (B4's option labels, B5, rankings, buddy, MOTD) are DEFERRED;
handoff §3's rig-confirmed paths are DO-NOT-DESTABILIZE and this plan proposes no
change to any of them (the one file both a fix and a protected rule live in is called
out explicitly in §B.1).

---

## A. The transport-agnostic engine

### A.0 The topology mapping (the one load-bearing modeling decision)

Bioserver's world is area → room → slot(game); PAL's presence path is
server → area(box) → room → slot. The PAL **room the client creates and joins maps to
the bioserver SLOT** (the game unit: status lifecycle, host, playernum 1–4, rules,
password, scenario). Bioserver's intermediate "room" layer (6 per area, only "free"
active) collapses: the PAL client browses rooms directly in the area, and
`LobbyRoomRegistry` already IS the per-area slot list.
**Class: Conclusion** — from the surface doc's state model (Observation of code) plus
the contract's slot semantics; consistent with every rig-confirmed exchange (create =
CREATESLOT-dialogue analogue, op-0x49 list = slot browse, op-0x0a = PLAYERSTATS).

Consequence: bioserver `Slot`/`Slots` port onto extensions of `LobbyRoom`/
`LobbyRoomRegistry` + presence depth 4 (which exists but has no allocator —
greenfield per the surface doc §2.2). Bioserver `Area` is already `AreaDirectory` +
`AreaTable`. Nothing in the port re-models what exists.

### A.1 Module map — bioserver class → server-v2 module

| Bioserver source | server-v2 module | Status / action |
|---|---|---|
| `Packet.java` framing, XOR string obfuscation, pid echo | `src/protocol/snap-codec.js`, `src/transport/reliable-channel.js`, `src/udp/snap-lobby-codec.js` | **NOT PORTED — transport differs by design.** The pid-echo discipline's PAL analogue is the sub-byte echo rules already enforced (Observation, surface §1.2). |
| `ServerMain`, `HeartBeatThread` (HEARTBEAT/CONNCHECK, ghost sweep) | `app/application.js`, `TimingWheel`, `#sendKeepalive` (op-0x40), `onRoomEmptied` | **EXISTS — do not touch.** op-0x40 is the 840 defence (rig-confirmed); `onRoomEmptied` replaces `cleanGhostRooms` (Observation, surface §2.1). |
| `Client` — location half (`area/room/slot`) | `state/presence.js` (`PresenceRegistry`) | **EXISTS.** Single home of WHERE (invariant P2). The port never stores location anywhere else. |
| `Client` — identity/attribute half (`playernum`, `hostflag`, HNPair, `characterstats` 0xD0/0xF0 blob, `gamenumber`) | **NEW `state/player-profile.js`** keyed on accountSessionId | Attributes only, never location (preserves P2). Name source = login handle echoed into member records — the FOUNDATION-MAP's still-valid finding (IDHNPAIRS/HNSELECT refuted for PAL; client renders our bytes verbatim). Charstats: store-and-echo whatever blob the client supplies; today op-0x0a ships zeros (Observation) — see gap E-9. |
| `ClientList` audience filters (`broadcastInArea/InRoom/InSlot/InAgl`) | **NEW generalized `SnapLobbySessions#broadcast(scope, buildPayload)`** extracted from `#relayChat` | The surface doc names this the natural first refactor (Inference there; adopted here). Scope always derived from presence sets, never from message content. |
| `Areas`/`Area` | `udp/area-directory.js`, `state/area-table.js` | **EXISTS — rig-confirmed rendering; do not touch.** |
| `Rooms`/`Room` (6-per-area layer) | — (collapsed, §A.0) | NOT PORTED. |
| `Slot`/`Slots` — status FREE/INCREATE/GAMESET/BUSY, host, livetime wait-timer, password/protection, scenario/slotType | **NEW `state/room-lifecycle.js`** wrapping/extending `LobbyRoom` | Authored status via explicit transitions (create → INCREATE → GAMESET at create-complete; → BUSY at start/full; recompute on leave per contract §6); population stays DERIVED (the registry's rule). Wait-timer on the shared `TimingWheel`. |
| `getFreePlayerNum` (host 1, joiners first-free of 2–4), join guards (BUSY→"full", ≠GAMESET→"not possible", password) | **NEW `state/slot-allocator.js`** (may live inside room-lifecycle) | Owns slot/playernum assignment; calls `presence.moveTo(p,{roomHandle,slot})` — allocator holds attributes, presence holds the assignment (surface §4.3 pattern). |
| `RuleSet` (per-area rule tables, values, changeable flags) | **NEW `state/rule-set.js`** | Engine-side only for now: B1 needs difficulty/FF/nightmare/infinity at start (GAMEDIFF analogue is client-local in PAL, but room flags/masks feed op-0x49 records and the area blob). The rule *browse/edit UI* surface is owner-DEFERRED — the module exists so the engine is complete, not to wire new messages. |
| `broadcastGetReady` (gamenumber mint, party set, slot→BUSY, GETREADY) + AGL membership | **NEW `state/game-session.js`** | Gamenumber = the thread tying party → in-game relay group → meeting room (contract §9.5). In PAL the GETREADY equivalent is the HOST's op-0x10 sub-3, not a server push (B1 §3, Observation both sides) — the module's job is party bookkeeping, BUSY transition, and the relay scope, NOT sending GETREADY. In-memory only; DB persistence deferred (T37 shows post-game re-entry on the SAME session via op-0x0D `0xf7e00001`, no fresh login — Observation — so the reconnect-routing half of gamenumber is not yet needed). |
| `GameServerThread`/`GameServerPacketHandler` (dumb same-gamenumber relay, length-byte framing) | **NEW relay path in `SnapLobbySessions`**: op-0x10 recipient-addressed relay + (experimental) in-game beacon echo/relay | No second connection exists in PAL: zero GSINFO analogue in the lobby corpus, in-game traffic observed on UDP 9090 (B1 §3, Observation). The relay-not-interpret principle carries over verbatim. |
| `MessageOfTheDay`, rankings 0x6145, buddy/private-msg 0x67xx, GETINFO 0x6801, 0x6881/6882 blobs | — | **NOT PORTED** (owner deferral; no PAL vehicle evidence). Recorded as pending, per the owner's standing instruction. |
| DB (`userid`, sessions, gamenumber persistence) | `AccountSessionRegistry` + SQLite repos (exist) | No new persistence in this plan. |

New seams on `SnapLobbySession` (required-constructor pattern, surface §4.1):
`profiles` (player-profile lookup), `roomLifecycle` (status/join guards),
`gameSessionFor(roomHandle)`, `broadcast(scope, payload)`. Wired in
`SnapLobbySessions.open()` like the existing five.

### A.2 Local test strategy — reference semantics without a transport

1. **Contract-row tables.** Each behavioural row of `BIOSERVER-CONTRACT.md` that the
   engine ports becomes a table-driven `node --test` case against the state modules
   directly (no transport): join-guard ordering and messages (contract §6), playernum
   first-free-of-2-3-4 and host=1, status recompute on leave (0 players → FREE;
   non-full + host remains → GAMESET), create-dialogue "joinable only at the final
   step", getReady ordering (gamenumber minted once → BUSY → party set), AGL
   membership by gamenumber. The reference Java is the oracle; where the reference
   itself is TODO-flagged (contract §10) the test asserts our chosen value and links
   the gap.
2. **Transition-emit tests.** Rule L1 (mutate first, then emit) is testable: every
   lifecycle hook fires exactly once per transition, with the post-mutation counts —
   the op-0x06 member-JOIN "delta only from a transition" constraint generalized.
3. **Session-level byte tests.** Drive `SnapLobbySession#accept()` with encoded
   datagrams (existing pattern, surface §5) — including **byte-exact replays of the
   T37 aggregates** (the 215-byte op-41+op-49 coalesced datagram with sub-seq
   `0x76000000`, and the 68-byte create batch with sub-seq 0) as regression fixtures
   for slice 1.
4. **Discriminating tests only** (handoff §0.3): every new test is shown to FAIL with
   the fix reverted before it counts. This is the rule that would have caught the
   dead-code fix.
5. Zero new dependencies; injectable timing wheel; codecs pure. `cd server-v2 && npm
   test` stays the single command; baseline today 644/637/0/7 (Observation).

---

## B. The wiring slices — milestone order

Common to every slice: GROUND → IMPLEMENT → TEST → **nora** → DEPLOY (md5 + port-bind
verify, backup dir per the runbook) → RIG RUN (pcap both consoles + journal window,
power-cycled PS2) → RECORD. Rollback baseline before any port work: **`68b1a59f`**
(deployed, md5-verified; Pi backups `src-backup-d1686428-20260808-093122` and T34
`src-backup-1576e09f-20260807-234636` per the handoff).

### Slice 1 — B2: the join freeze

#### 1a. The transport sub-message fix (the proven blocker — do this first)

Not bioserver logic, but it gates every later message and killed a session outright.

- **Change** (`src/transport/reliable-channel.js`): deliver reliable sub-messages of
  a walked `0x0800` aggregate under the OUTER message's sequence acceptance; never
  gap-buffer a sub-message; never count one toward `gap-abandoned`; ack only the
  outer seq. **GROUNDED:** client decompile `FUN_001d6988.c:44-88` (outer-seq gating,
  sub-seq dead weight) + T37 wire (acked-never-answered `0x76000000`/`0x7A000000`) +
  journal arithmetic (`gap-abandoned buffered:[134217728]` = `0x08000000`) — B2 doc
  §1/§3, Conclusion grade.
- **Protected-path caution:** this file also implements the batch-walk-**degrade**
  rule and `TOO_MANY_MESSAGES` fail-closed, which are load-bearing for rig-confirmed
  paths (handoff §4 — "do not simplify"). The fix must leave both intact; the
  session-level byte tests of §A.2.3 (create batch MUST walk; op-0x48 ciphertext
  batch MUST degrade) are the regression guard. This is exactly the kind of change
  that needs nora on the specific diff, unbundled from everything else.
- **Free side effects:** the batched post-create op-0x09 USER/MAXI replies start
  flowing (their sub-seq 0 becomes irrelevant) — plausible B4 "No. of Players"
  contributor, answered by the rig run at no extra cost (B2 doc §3, Hypothesis).
- **Player-visible outcome:** a joining console's room-list sweep completes at ~100 ms
  cadence instead of freezing; the lobby UI stays live.
- **Rig verification:** PS2 enters a box containing a room; journal shows a
  `lobby-room-list` event for EVERY op-0x49 query including coalesced ones; no
  gap-buffer entries for sub-messages; sweep cadence matches the healthy box-9
  reference (B2 doc §2). Then watch what the PS2 sends next (feeds 1b).
- **Rollback:** single commit; revert + redeploy `68b1a59f` files (they are on the Pi
  backup dir already).

#### 1b. The join ladder — bioserver JOINGAME wired to SN@P

Engine rows implemented (contract §6 Join): `JOINGAME 0x6406` guards + playernum
assignment; `PLAYERSTATBC 0x6503` (announce joiner to the room);
`SLOTPLRSTATUS`/`SLOTSTATUS`/`SLOTATTRIB2` refresh broadcasts;
`PLAYEROK 0x6506` readiness signal.

Vehicle map (join ladder per B2 doc §5, numbering kept):

| Step | Message | Vehicle status |
|---|---|---|
| 1–4 | area ENTER, op-0x49 sweep, op-0x09 USER, op-0x0a member-list | **GROUNDED** — all rig/wire-confirmed T37 (with 1a fixing step 2). No change. |
| 5 | joiner → op-0x06 ENTER with the ROOM handle (JOINGAME request analogue) | **EVIDENCE-GATED**: never observed in T37 (the second stall). July RE (`G12-joiner-tag17-RE-2026-07-16.md`) says `who=0xa0` op-0x06; the post-1a rig run shows what the PS2 actually sends once its sweep completes. Settles: H-A/H-B/H-C of B2 §5, or the PINE read set `0x6c4b90/0x6c4b9f/0x6c4ba0/0x6cbc7e` at a stalled moment. Handler skeleton can be written against the July shape but ships flag-gated until the wire confirms. |
| 6 | joiner → op-0x10 app-payload[0]=0x02 join-request | **EVIDENCE-GATED** (same run). |
| 7 | server → op-0x10 `0C000000 <count>000000` join-confirm | **GROUNDED** — the rig-confirmed V1 fix (`SNAP_JOIN_OP10_SUBC`, Pi `cead951e`, 2-device); port the exact bytes. |
| 8 | server → op-0x06 member-JOIN records (PLAYERSTATBC analogue) + op-0x10 sub-5 / sub-0x11 (SLOTPLRSTATUS analogue) to room members | **GROUNDED** for the payload builders (rig-confirmed on the create path: `buildMemberJoinPayload` fills roster row 0; sub-5 renders "MAX/CURRENT P") — **EVIDENCE-GATED** for the push-to-existing-members fan-out (H-A predicts it is exactly what the frozen preview needs; delta-only-from-transition constraint applies). |

Join guards map (engine, all GROUNDED in the reference contract, PAL rejection
vehicle **EVIDENCE-GATED**): bioserver rejects with err-flag + markup text; PAL's
only observed reject vehicle is the op-0x27 opcode-swap on create (Observation). H:
join reject = op-0x27 selector 6. Do not guess on the wire — until a real rejection
is captured, the server can simply not-reject (rooms are open; password rooms
deferred with B5).

- **Player-visible outcome:** the second console JOINS a room; both consoles see the
  roster (names from login handles, not PLAYERn).
- **Rig verification:** two consoles; create on one, join on the other; roster
  renders both sides; journal shows allocator transitions; chat relay observed
  2-console for the first time (deployed but unobserved — surface §1.2).
- **Rollback:** engine modules are additive; the dispatch cases and pushes are
  flag-gated (`SNAP_JOIN_*`); revert = flags off, then commit revert.

### Slice 2 — B1: game start (THE milestone)

The lobby-side start path is ALREADY COMPLETE for solo (B1 doc, Conclusion): op-0x08
STAT reply (roster SM phase-1 exit) and op-0x0D body-1 barrier reply both served and
consumed in T37. **Do not touch either.** What remains:

#### 2a. op-0x10 recipient-addressed relay (multiplayer start plumbing)

- **Change:** inbound op-0x10 case in `#dispatch` + relay in `SnapLobbySessions`:
  parse `[BE32 nRecipients][BE32 recipientId]…[sub @+0x08][data @+0x0C]`, byteswap
  only the recipient words, forward verbatim to the addressed room members (scope
  checked against sender's presence room). This carries the host-driven roster SM
  bursts: sub-3 (the PAL GETREADY), sub-4 (accept, joiner→host), sub-5/6/7/8 (counts,
  ids/names, charstats chunks, all-data-delivered), sub-9/0x10 (decline paths).
- **GROUNDED:** the sub-event sequence and per-phase sender/receiver duties are
  decompile-complete (B1 §1 B-i, `FUN_005c6500` all 14 phases + joiner handlers
  `FUN_005bbf20`/`FUN_005bbfc0`); the body format is from the same trace. What has
  never been seen is an op-0x10 ON THE WIRE (zero in T37 — solo sends none;
  Observation). So: format decompile-grounded, runtime **EVIDENCE-GATED on the first
  2-player start attempt** — which is also the slice's verification step. Relay =
  copy verbatim (the bioserver dumb-relay principle), so payload-format risk is
  confined to the recipient-word parse.
- **Bioserver rows covered:** GETREADY 0x6910 → host sub-3 (server relays);
  PLAYERCOUNT/PLAYERNUMBER 0x6911/0x6912 → host sub-5 push; PLAYERSTAT 0x6913 →
  sub-6 + sub-7; end-of-detail → sub-8; STARTGAME 0x6508 → no wire message (start
  press is local, B1 Stage A). GAMESESSION/GSINFO/GSLOGIN → **no PAL analogue**
  (Observation: in-game stays on UDP 9090).

#### 2b. Room status → BUSY + list refresh (bioserver broadcastGetReady step 2)

- **Change:** `game-session.js` marks the room BUSY (nobody else joins) when the
  start is detected server-side. PAL detection point: the op-0x0D **body 1** barrier
  (each member sends it entering the game — GROUNDED, T37 + decompile of
  `FUN_005c4760` state 4) — the earliest server-visible start signal since the press
  itself emits nothing.
- Vehicle for "others see it as closed": op-0x49 record fields `+0x18`/`+0x1c` flags
  — **EVIDENCE-GATED** (never exercised with non-zero values on a real console; H-B
  of the B2 doc even suspects zeroed flags gate the join UI). Ship the status in the
  engine regardless; publish to the wire behind a flag until one rig run shows the
  client's rendering of non-zero flags.

#### 2c. The in-game beacon experiment (the single blocking unknown for solo start)

- T37: after the game-module handoff, an **unreliable op-0x0F, flags 0x2012, body
  `00 00`, 1 Hz, own seq counter** for ~119 s, all 115 refused as `CHAT_RUNT` (a
  server-side misfile — it routes to uninstalled slot 0x14, not chat; Observation),
  then abort → post-game meeting room. **What it expects is Unknown** (game module,
  outside the 2549-function corpus, stubbed in REOF2).
- **Change (two steps):** (i) stop misclassifying it — route flags-0x2012 op-0x0F to
  its own handler, consume at debug (removes 115 refusals/session of noise; no
  behaviour claim). (ii) **flag-gated experiment**: echo the beacon back verbatim to
  the sender AND/OR relay it room-scoped (the JP dumb-relay hypothesis — solo JP
  relays nothing yet PAL solo still beacons, so a server echo is the live
  hypothesis). **EVIDENCE-GATED** — settled by, cheapest first: (c) this one-line
  echo/relay experiment on the rig (does the scenario load?); (b) PINE breakpoint on
  `0x1e180c` during the black screen to capture `ra`; (a) Ghidra on the game module:
  the `FUN_001d4d24(conn, 0x12/0x14, cb)` installers and the
  `FUN_001e180c(..., 0x2000, 2, 0x0F, ...)` call site in `game.bin`.
- **Player-visible outcome (the milestone):** pressing START loads the scenario —
  first solo, then 2-player with 2a relaying the roster bursts.
- **Rig verification:** solo start with the echo flag on → black screen replaced by
  scenario load (or a discriminating new symptom + captured beacon exchange). Then
  2-player start → joiner teleports to screen 5 on sub-3, host phase-5 gate passes
  on relayed sub-4, both load. Confirms on the way: whether phase-0 sub-3 includes
  the host (harmless either way — B1 gap 5) and `0x6FF2B4` semantics.
- **Rollback:** relay + echo + BUSY-publication all individually flag-gated; engine
  commit separate from wire commits; baseline restore = flags off.

### Slice 3 — B3: leave twice (folded in alongside slice 1's deploy)

**Where it belongs and why here:** B3 is independent of the join/start ladder, both
fixes are small and flag-gated, and — decisively — every slice-1/2 rig session does
repeated enter/leave, so the un-fixed B3 wedge (client stops answering keepalives,
full re-register, sometimes permanent) taxes exactly the runs this plan depends on.
Implement with slice 1, verify in the same rig session, keep as separate commits.

Engine rows: bioserver EXITSLOTLIST/EXITAREA/CANCELSLOT/LEAVESLOT semantics are
already half-present (`presence.ascend`, `onRoomEmptied`); the room-lifecycle module
adds the status recompute + survivor refresh hooks (vehicle for survivor
member-LEAVE push: **EVIDENCE-GATED** — the exit-contract RE points at a
game-channel class-6 leave event + op-0x10 sub-0x11 count; no capture yet; deferred
until a 2-console leave is observed post-slice-1).

The two server-side fixes (B3 doc §7, both **Hypothesis until rig-confirmed**,
both decompile-grounded):

1. **Answer the op-0x02 close.** In the post-selection phase: keep the transport ack
   and mirror a zero-body server→client op-0x02 (flags 0xb, len 16, stamped seq),
   then release the server-side session (client re-registers cleanly — T37 proves
   that recovery path lands on a working Area Select). GROUNDING: the exit-contract
   RE's bidirectional-0xb000 note + the wire-confirmed close (3 clean T37 instances);
   the exact close-confirm shape the client needs (`cRam006cbbe0 := 2` writer) is
   still needs-decompile — hence flag-gated.
2. **Make the +0xc echo real.** Extend op-0x28 sel-6/sel-7 completion payloads from 8
   to 0x10 bytes with the request's send-seq echoed at +0xc — the only observed
   deviation from the RE'd reply contract in the whole first-leave exchange; if M1
   (dead re-arm) is the mechanism this is the actual root-cause fix. Flag-gated;
   touches the completion builder used by rig-confirmed sel-6/7 replies, so nora on
   the diff and the flag defaults OFF until the rig run.

- **Player-visible outcome:** leaving an area works every time; no wedge, no forced
  re-register.
- **Rig verification:** the B3 repro (enter→leave→enter→leave) with both flags on and
  the §C PINE watch set; success = `0x6cbbe0 → 2` (or better: exit #2 goes op-0x07
  again under fix 2), second exit returns to Area Select. The watch set discriminates
  M1 vs M2 regardless of outcome.
- **Rollback:** flags off; separate commits.

### Slice 4 (folds into B1's tail) — post-game meeting room

Already mostly served (op-0x0D `0xf7e00001` answered; chat works there — screen 0xC
observed T37). Bioserver AGL rows (ENTERAGL/AGLSTATS/AGLJOIN/AGLLEAVE) wait until a
REAL game completion produces a meeting-room session worth mapping; the meeting-room
exit stall is expected to be the same op-0x02 close as B3 (T37: leave answered, then
op-0x02 85 s later — Observation) and is covered by fix 3.1. The remaining unknown
(what completion the client still needed between the answered leave and the give-up)
is an OFFLINE pcap diff — §C. No new wire messages proposed here.

---

## C. Consolidated evidence-gated reads — ordered for one rig session

**Offline first (no rig time consumed), before the session:**

| # | Read | Settles |
|---|---|---|
| O1 | T37 pcap diff: meeting-room leave datagram flags (0x1000 a/b-variant, slots 0x23 vs 0x24) vs the server reply's flags | the meeting-room exit stall's missing completion (B1 gap 3) |
| O2 | Corpus/decompile lookup: sender of the bare reliable op-0x02 at give-up time | confirms the "client-side abort" reading (B2 gap) — likely same answer as B3's close, may already be settled by the B3 doc's `FUN_001dbd0c` identification |
| O3 | Ghidra: op-0x28 slot dispatch (`FUN_001d9f78` → conn+0x548 table) — where the completion callback's param points | whether +0xc reads payload or header offset; de-risks slice-3 fix 2 before deploying it |
| O4 | Ghidra (game module): `FUN_001d4d24(conn,0x12/0x14,cb)` installers + the `FUN_001e180c(...,0x2000,2,0x0F,...)` call site in `game.bin` | the B1 beacon's expectation — only needed if the C5 echo experiment is ambiguous |

**The rig session** (deployed: slice 1a+1b skeleton + slice 3 flags + the beacon
flags; power-cycled PS2; pcap both consoles; journal window; PINE sampler armed on
the emulator):

| # | Step | Reads / observations | Clears |
|---|---|---|---|
| R1 | Sign-in both consoles, PS2 to Area Select | rules selectable? room counts still `1/0p`? | B4 rules half (68b1a59f masks — deployed, never rig-tested) |
| R2 | While on the area screen: PINE read `bRam006ce5cf` + `cRam007006a5` | the `FUN_005c4f00` selector-0 branch question — whether `+0x16c` min/max can EVER bind on Free Area | B4 players half (guessed at twice; one read decides) |
| R3 | Emulator creates a room; PS2 enters that box | sweep completes (1a fix); the batched op-0x09s now answered → does "No. of Players" change?; then **what the PS2 sends after the op-0x0a reply** | B2 second stall H-A/H-B/H-C + join step-5/6 vehicle; B4 count contribution |
| R4 | If the PS2 stalls again at R3: PINE `0x6c4b90`, `0x6c4b9f`, `0x6c4ba0`, `0x6cbc7e` at the stalled moment | discriminates H-A/H-B/H-C directly |
| R5 | In the room, open the count screen | op-0x09 MAXI tag exercised for the first time | the untested room-capacity reply branch |
| R6 | Solo start with the beacon echo/relay flag ON | scenario loads? capture the beacon exchange either way | THE B1 blocker (cheapest discriminator) |
| R7 | If R6 loads and a 2-player room is joinable (R3 succeeded): 2-player start | op-0x10 on the wire for the first time; sub-3-to-host?; `0x6FF2B4` | slice-2a runtime grounding; B1 gaps 5–6 |
| R8 | After any game return: PINE watch `0x6C4B9E` | writer of meeting-room majors 0x0a/0x0b (B1 gap 2) |
| R9 | B3 repro on the emulator (enter→leave→enter→exit-press#2) with slice-3 flags ON; PINE at four moments (after enter#1 / leave#1 / enter#2 / at press#2): `0x6ce5ce`, `0x6ce5cf`, `0x6ce5d0`, `0x6c4fbb`, `0x6cbb6c`, `0x6cbb68`, `0x6cbbe0`, `0x6cbbe4`, `0x6cbc80` | M1 vs M2 (`0x6ce5ce` == 0 vs box id after enter#2); G3 (`0x6cbc80 == 0x47ba` ⇒ the +0xc read lands on the trailer); whether the close-mirror completes (`0x6cbbe0 → 2`) — validates or kills both B3 fixes in one pass |
| R10 | One op-0x40 keepalive captured on the wire (falls out of the pcap for free) | decrypt offline under raw `SNAP-SWAN` vs the hashed-key claim — closes the keepalive-key discrepancy |

Ordering rationale: R1–R2 are passive and answer the two oldest guessed-at questions
before anything else can confound them; R3–R5 are the slice-1 acceptance run and
produce the join-vehicle evidence slice 1b needs; R6–R8 are the milestone attempt and
only consume rig time if R3 leaves a joinable path (solo R6 works regardless); R9 is
last because a B3 wedge ends a console's session. Everything else on the gap list
(op-0x0F short variant, `+0x309C` writer, `FUN_005b6070` invoker, op-0x29,
sub-seq stale-value origin, client give-up state) is explicitly NOT in this session:
either offline-settleable, not load-bearing for any slice, or owner-deferred.

---

## D. What the FOUNDATION-MAP still contributes vs what this plan supersedes

Still valid and reused: the identity finding (no IDHNPAIRS/HNSELECT on PAL — echo the
login handle into member records); JOINGAME → op-0x06/op-0x28-sel-6 + op-0x10
sub-0x0C (PROVEN T22, now slice-1b step 7); the host-owned config model (SCENESELECT/
SETRULE ride the host's op-0x10 bursts — matches B1's client-local scenario finding);
the exit = 0xb000 close diagnosis (now wire-confirmed by the B3 doc); the build
discipline (local replay → nora → one rig check → owner; flag retirement as steps are
rig-confirmed).

Superseded by the new docs: the V1 target architecture (`lobby_engine.js` /
`lobby_state` — replaced by server-v2's PresenceRegistry/LobbyRoomRegistry); the
op-0x49 BE fix (shipped; byte orders now rig-derived facts); "CHATIN→CHATOUT
NEEDS-VEHICLE" (chat = op-0x0F, implemented); "SLOTTIMER/GETREADY/gameserver handoff
out of scope / unmapped" (now mapped: host-driven sub-events + no second connection —
B1 §3); the TCP 0x62xx/0x63xx port actions (PAL drives these surfaces over UDP; the
TCP ladder needs nothing — surface §4.6).
