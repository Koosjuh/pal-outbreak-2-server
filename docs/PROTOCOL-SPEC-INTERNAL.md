# PROTOCOL-SPEC-INTERNAL — the one doc to build the server from

**Status as of 2026-08-25.** INTERNAL (our repo, not an upstream/openSNAP contribution). Purpose:
replace re-reading 23+ session-log entries. A builder should be able to implement/extend the
server from this document alone, cross-referencing the cited sources only when a claim needs
re-verification. Vocabulary is openSNAP's (command names, flag bits, sub-selectors) because it
gives PAL's numeric ops readable names; every claim is graded **PAL-Confirmed** (our own
decompile/wire/PINE/rig evidence), **AM-Inference** (named only by the Auto Modellista/openSNAP
tables, PAL check pending), or **PAL-Divergent** (PAL demonstrably differs). Do not upgrade a
grade without the evidence this doc or its sources cite.

**Synthesized strictly from:** `docs/findings/protocol/SESSION-LOG-2026-08-24.md` (T1-T23),
`OPENSNAP-CROSSREF-2026-08-24.md`, `OPENSNAP-DEEP-DIVE-2026-08-24.md`,
`reverse-engineering/network/indexes/OPCODE-NAME-MAP.md`,
`analysis/op28-channel-bit-dispatch-2026-08-24.md`, `analysis/op10-gamechannel-blobs-RE-2026-08-24.md`,
`analysis/area-table-scenario-mask-LE-2026-08-24.md`, `analysis/seated-slot-roster-RE-2026-08-25.md`,
`docs/design/v2-port/RIG-PINE-2026-08-25/{MILESTONE-multiplayer-works.md,FINDING.md}`,
`docs/design/v2-port/RULES-MASK-RE.md`, `docs/design/v2-port/BIOSERVER-CONTRACT.md`,
`server-v2/src/config/server-config.js`. Ground truth for goal status: `GOALS.md`/`FACTS.md`.

---

## 1. Overview + status table

Full flow, each stage graded on the live (2026-08-25) Pi build (`server-v2`, branch
`feat/v2-bioserver-port`):

| Stage | Status | One-line |
|---|---|---|
| Bootstrap (DNS → DNAS → HTTP `lbs.jsp`) | **DONE** | v2 serves DNS records, DNAS handshake, HTTP directory; rig-confirmed sign-in path. |
| TCP 10127 lobby ladder (login/select) | **DONE** | Sign-in → server select → area select all work on real PS2 + emulator. |
| SN@P UDP register (game port 9090) | **DONE** | Register/re-register solid (G10 SOLVED 2026-07-06); attachment-nonce session reclaim ON by default. |
| Area select (grid, per-area counts) | **DONE (render) / PARTIAL (counts)** | All 10 areas render; rule/cast/scenario rows now selectable (OBAREA-W5); area/server-select player counts still show wrong values (0 or stale) — vehicle known, not wired (G5/G12-7). |
| Room create (op-04, RULE screen) | **DONE** | Create-slot accept (`0x6ff2b1=1`), rules+cast+scenario all selectable on the rig (OBAREA-W5/W... fixes, 2026-08-24/25). |
| Room join (op-06 ladder, seating) | **DONE** | Joiner room-render, seating (`0x6c7c2c`), memberId, host-reseat all rig-confirmed 2026-08-25 (count=2, both seated with right ids). |
| Game-start handshake (op-10 sub-3..8) | **DONE (2-player)** | Owner-confirmed 2026-08-25: both consoles start with correct characters (PS2=host, PC=joiner run). Role-swapped (PC=host) run still failed a readiness race (T23) — not fully closed for all role orders. |
| In-game entity sync | **OPEN — the new frontier** | Player movement syncs (position relay works); enemy/zombie state does NOT — each console runs an independent simulation. Reliable game-channel relay is lossy under load (1727 sent / 791 relayed). |
| Room chat | **PARTIAL** | Lobby chat works both ways (2026-08-24 rig). In-room/room chat does not — vehicle un-RE'd (`SNAP_ROOM_CHAT_SUB7` held, NOT GROUNDED — nora). |
| Room exit / leave | **DONE** | C3 channel-bit-echo fix rig-confirmed 2026-08-24: Exit releases the room (was a permanent park). |
| Lobby polish (counts, member list, buddy) | **OPEN** | Lobby shows "4P" with 2 clients; in-room member list shows no members (roster-vs-drawn-list gap); buddy list server gap (G6). |

---

## 2. Transport (SN@P)

### 2.1 Wire header (16 bytes) + trailer

Both our own L1 spec and openSNAP's independent clean-room implementation (Auto Modellista,
SLUS_206.42) describe the **same wire protocol** — cross-validated, not merely analogous
(`OPENSNAP-CROSSREF-2026-08-24.md` §1, Observation both sides):

| Offset | Size | Field | Notes |
|---|---|---|---|
| `+0x00` | u16 BE | flags\|len | high bits = flag word (see §2.2); low 10 bits (`&0x3ff`) = length **including the 16-byte header, excluding the trailer** |
| `+0x02` | u8 | "SUB byte" / `packet_number` | our G2 discovery: op-0x28 completions must echo this |
| `+0x03` | u8 | opcode/`command` | |
| `+0x04` | u32 | session token (first 4 of a 12-byte token) / `session_id` | |
| `+0x08` | u32 BE | reliable seq / `sequence_number` | |
| `+0x0c` | u32 BE | ack field / `acknowledge_number` | |
| trailer | 4 bytes | `0xBA476611` (`FUN_001d6468`) | openSNAP: `FOOTER_MARKER` (+ a `...10` KAGE bootstrap-era variant, not used post-login) |

### 2.2 Flag bits (PAL-Confirmed via decompile `FUN_001d9f78`, cross-validated by openSNAP)

| Bit | Name | Meaning |
|---|---|---|
| `0x8000` | RELIABLE | needs ack/retransmit |
| `0x4000` | RESPONSE | carries an ack; per-command duplicate/response semantics |
| `0x2000` | **ROOM** | room-channel context |
| `0x1000` | **LOBBY** | lobby-channel context — **lobby context = BOTH 0x2000 and 0x1000 set (`0x3000`)**; room-only context = `0x2000` alone |
| `0x0800` | MULTI | coalesced/multi sub-frame datagram |
| `0x0400` | RELAY | chat/relay traffic — room chat `0xA400`, lobby/area chat `0xB400` |

**The confirmed channel-context rule (production rule, applies across the whole command
table):** for op-0x28 result-wrapper completions, **the reply's `0x3000` mask must equal the
request's `0x3000` mask** — `FUN_001d9f78` selects the completion callback slot by the
**received** frame's `0x1000` bit for sub-selectors 0x05 (delete), 0x06 (join), 0x07 (leave),
0x09, 0x0a; no split for sub 0x04 (create) or 0x08 (STAT), which are single-slot/don't-care.
This is PAL-Confirmed by decompile (`analysis/op28-channel-bit-dispatch-2026-08-24.md`) and
matches the AM/openSNAP `<>&1000` dispatch table exactly.

Observed kind bytes decode cleanly under this model: `0xB0` = reliable+lobby-context, `0x60` =
openSNAP's bare transport ACK (`0x6000`, cmd `0x00`, our 20-byte ACK frame), `0xF0` =
reliable+response+lobby (the historic "who=0xF0 op48" G2 mystery frames — now explained as
response-channel reliable frames, consistent with why `SNAP_ACK_OP48_F0` was required),
`0xa036` = reliable ROOM in-game game packet (`0x8000|0x2000|len`, 2026-08-25 in-game evidence).

### 2.3 Reliable window / ack / dedup (AM-Inference, openSNAP byte-level, PAL check pending
per-item — treat as design oracle, not yet all individually PAL-decompile-confirmed)

- Per-session **inbound seq window**: reject `seq <= last_incoming_sequence`, else advance it.
- **Outbound seq allocation is split per channel**: reliable messages use a
  post-increment counter; unreliable use a separate `++sequence_number`. PAL-Confirmed
  analogue: **separate per-channel reliable counters exist on the PAL client** —
  `conn+0x61a` (lobby) vs `conn+0x61b` (room) — runtime-confirmed via savestate
  (T5: `conn+0x61a=11`, `conn+0x61b=1`, explaining the room-leave's observed seq-0).
- **Duplicate policy**: a duplicate reliable SEND/SEND_TARGET → ACK only, do not re-execute;
  LEAVE has its own stale-duplicate ACK-only rule. Create/join/leave handlers additionally
  keep **exact-replay caches** keyed by (session, seq) so a retransmit gets the byte-identical
  original reply, never a fresh side effect.
- **Bare ACK**: `CMD_ACK`(0x00) with empty payload, `sequence_number=0, packet_number=0`; only
  the ack field carries state. **PAL-Confirmed anti-pattern to avoid:** do not separately
  bare-ACK an *embedded* multi-child (child of a `0x0800`-flagged datagram) — the outer
  reliable owns the bundle's only transport ACK; embedded children carry a legal seq-0 and a
  garbage ack word (T2, watch-item — not yet independently proven as a PAL bug, kept as H2).
- **Reply ack number** = the request's sequence_number by default; for embedded seq-0 requests
  use the latest accepted inbound seq; unsolicited pushes ack the session's last inbound seq.
- Window/retry shape (AM numbers, oracle only): 16-deep receive window
  (`kkCreateARUDPRevWindow(0x10)`), ≥16 in-flight or a seq-gap ≥16 defers/retransmits, 200ms
  retry cadence, 4 counted retries then park-until-timeout.

### 2.4 SN@P-SWAN keepalive (PAL-Divergent from openSNAP's bootstrap 0x40)

**Do not conflate two different `0x40` usages.** openSNAP's AM client uses cmd `0x40` as a
**bootstrap-channel Blowfish challenge** (`CMD_BOOTSTRAP_LOGIN_SWAN`) during the UDP-9090
login handshake, answered by `0x41`. **PAL's `op-0x40` is a distinct, later, phase-3
GAME-phase keepalive** (`0x30xx` flags, Blowfish body keyed with the same literal
`SNAP-SWAN` string but at a different protocol phase) — this is the fix for error `840`
(connection timeout). Same crypto key discovered independently by both projects; different
phase. `SNAP_APP_KEEPALIVE` (server-v2, default ON) additionally answers a **separate
application-level liveness watchdog** — the lobby overlay's ~145.7s silence timer, reset only
by lobby-overlay traffic, NOT by op-0x40 — with a 30s op-0x10 who-`0xA000` push
(app-payload `0x00`, a pure watchdog reset the client's dispatch switch has no case for).

---

## 3. Command table

Grades and evidence per `reverse-engineering/network/indexes/OPCODE-NAME-MAP.md`
(the corpus index; consult it for the full evidence chain per row).

| Op | openSNAP/AM name | PAL-confirmed meaning | Grade |
|---|---|---|---|
| 0x00 | CMD_ACK | bare transport ack (our 20-byte `0x6010` frames) | PAL-Confirmed |
| 0x01 | CMD_LOGIN_TO_KICS | KICS = KDDI service name; explains Bioserver kinship | AM-Inference |
| 0x02 | CMD_LOGOUT_CLIENT | client session close at give-up | PAL-Confirmed (role) |
| 0x04 | CMD_CREATE_GAME_ROOM | op-04 create-slot mints the room; cb `FUN_005c3a40` sets `0x6ff2b1=1` (title/pw/scenario/character unlock) | PAL-Confirmed |
| 0x05 | CMD_DELETE (0x1000-split) | channel split confirmed at dispatcher (slots 0x1e/0x20) | AM-Inference (role split PAL-Confirmed) |
| 0x06 | CMD_JOIN (0x1000-split) | dual forms observed: DATA-clear room-ENTER → slot 0x22 (join ladder); member-add/seat vehicle for `0x6c7c2c` | PAL-Confirmed |
| 0x07 | CMD_LEAVE (0x1000-split) | matched pair `FUN_001dd07c` (lobby, `0xb000`, slot 0x23) / `FUN_001dd1dc` (room, `0xa000`, slot 0x24) | PAL-Confirmed |
| 0x08 | CMD_CHANGE_ATTRIBUTE | our "STAT@" named-channel query; sel-8 completion → slot 0x25, single-slot (no channel split) | PAL-Confirmed (role) |
| 0x09 | CMD_QUERY_ATTRIBUTE | USER/MAXI room-count queries; channel-split (slots `0x5a4/0x5a0`) | PAL-Confirmed (role) |
| 0x0A | CMD_QUERY_USER | op-0a member-list (record layout PAL-specific: name16@+0x00, id_u32@+0x10, len@+0x14, charstats[0xf0]@+0x18) | PAL-Confirmed |
| 0x0B | CMD_QUERY_GAME_ROOMS | candidate; PAL room list actually rides op-0x49 instead | AM-Inference |
| 0x0E | CMD_QUERY_LOBBIES | | AM-Inference |
| 0x0F | CMD_SEND (chat/game, by 0x0400+context) | chat = `0xA4xx` room / `0xB4xx` lobby/area; `0x0400`-clear = in-game reliable/unreliable channel | PAL-Confirmed |
| 0x10 | CMD_SEND_TARGET (payload sub-selectors) | our op-10 sub-selector family, dispatcher case 0xD → slot 0x13 `FUN_005bba20`, switch on body+0x08 | PAL-Confirmed |
| 0x11 | CMD_SEND_GAME_PACKET_TO_GAME_SERVER | | AM-Inference |
| 0x14 | CMD_SEND_ECHO | mirrors payload; T8 found 8 unanswered probes in a game-start window (small open item) | AM-Inference |
| 0x27 | (result wrapper, FAIL) | create-reject uses opcode 0x27, not a status field | PAL-Confirmed |
| 0x28 | CMD_RESULT_WRAPPER (sub=GameTag) | our op-28 completions; sub echo at wire+0x02 = packet number; routing by `0x1000` (`FUN_001d9f78`) | PAL-Confirmed |
| 0x29 | CMD_RESULT_LOGIN_TO_KICS | v2 op-29 success transition, never captured on PAL wire | AM-Inference |
| 0x2C/2D/2E/31 | bootstrap LOGIN_CLIENT/SUCCESS/FAIL/FAILURE | RS1 wire frames decode exactly (0x3096 002c → 0xb096 002d); fail reason 0x13 = bad password | PAL-Confirmed (0x2C/0x2D) |
| 0x40/0x41 | CMD_BOOTSTRAP_LOGIN_SWAN / _CHECK | **PAL op-0x40 is a different, later, game-phase keepalive** — see §2.4 | **PAL-Divergent** |
| 0x48/0x49 | (absent from AM tables) | our area-grid NAME query / LOID-STAT room-list; Outbreak-specific | PAL-only |
| 0x6E | kkSetJoinGameClassCallBack | our 0x6e ENTER reply, sets `0x6ff2b1` | PAL-Confirmed (role) |
| 0x78 | kkSetLeaveGameClassCallBack | candidate for the leave/park-death path family | AM-Inference |

### 3.1 op-10 sub-selector table (game-channel `CMD_SEND_TARGET`)

Wire framing (Confirmed): body = `[BE32 swapCount=1][BE32 target handle][u8 sub +3pad][payload]`.
Dispatch: `FUN_001d9f78` case 0xD → slot 0x13 (`FUN_005bba20`), switch on `sub` (body+0x08).
Callback signature: `handler(hdr+8 = frame connHandle word, body+8)`. **The connHandle word is
the LINK id (`conn+0x44`, the RECEIVING link's own handle), not the originating peer** — load
bearing for the accept-scan mechanism below.

| sub | Name/role | Body | Grade |
|---|---|---|---|
| 0x01 | selector stream (NOT room-info) | u32 selector@+0x00: sel-0 = char-choice-OK (value@+0x04); sel-1 + screen `0xc` = mail/message chunk reassembly | PAL-Confirmed (corrects an earlier "room-info blob" reading) |
| 0x02 | join-request (joiner→host) | none | PAL-Confirmed |
| 0x03 | start-reset (host→all) | none; gate `0x6ff2b1==1` | PAL-Confirmed |
| 0x04 | accept | `0x300` zero bytes (correct — nothing to fill) | PAL-Confirmed |
| 0x05 | roster index | `{myIdx, total}` | PAL-Confirmed |
| 0x06 | roster name | `{peerIdx, 0, handle16, name16}` | PAL-Confirmed |
| 0x07 | charstats chunks | `{slot, len, u16 off, data}`, 5 chunks × `4×0x32+0x28 = 0xF0` bytes into `0x6fffd1+slot*0x114` (per-player 0xf0 charstats blob) | PAL-Confirmed |
| 0x08 | download barrier | sets `0x6ff2af` (joiner's start-wait gate) | PAL-Confirmed |
| 0x09 | abort | | PAL-Confirmed (role) |
| 0x0A/0x0B | time-limit | | PAL-Confirmed (role) |
| 0x0C | member count / join-confirm | `[0x0C][count LE]` — fires the joiner's stored continuation (`FUN_005bbe00`) | PAL-Confirmed (rig-proven 2026-07-16) |
| 0x0D | event | | PAL-Confirmed (role) |
| 0x0E | ping | 6s-fallback escalation query (`thunk_FUN_005c61b0`), distinct message not a retry-param | PAL-Confirmed |
| 0x0F | pong | `0x6ff2b2=3` | PAL-Confirmed |
| 0x10 | refuse | sets `0x6ff2b5[slot]=2` | PAL-Confirmed |
| 0x11 | member count (leave-side) | new count push, same vehicle join uses | PAL-Confirmed |

**Host start sequence** (`FUN_005c6500`): sub-3 (all) → op-08 STAT hide (`|0x40000000`, hides
the room) → wait for accepts → sub-5/6 → sub-7×5 per player (charstats) → sub-8 → op-0x0D
barrier. Joiner waits unbounded on `0x6ff2af`.

---

## 4. Lobby/area

- **Area table (op-49 NAME/records):** stride confusion corrected — the op-49 room-list
  record stride is **0x28**, NOT 0x24 (0x24 belongs to the separate op-48 named-slot
  subsystem). Fields the client reads: `name@+0x00`, `current@+0x14`, `aux@+0x18`,
  `flags@+0x1c`, `max@+0x20`, `handle(ENTER token)@+0x24`.
- **Endianness bug (fixed, `SNAP_OP49_BE`):** every op-49 numeric field `+0x10..+0x24` is
  byteswapped by the transport (`FUN_001d7d20`) before the app reads it. Fix flips only the 3
  **display** fields (`current`, `flags`, `max`) to `writeUInt32BE`; **`handle@+0x24` stays
  LE deliberately** (opaque round-trip ENTER token, proven working LE — flipping it would
  perturb the rig-proven join). Do NOT flip all four.
- **No status/joinable byte in the op-49 record.** Status is client-derived: `current==max` →
  FULL, else open; **locked** = flags bit16; **hidden** = flags bit30 (this is exactly the bit
  the host's game-start STAT-hide sets, `|0x40000000`).
- **`+0x1c` (op-49 room flags) = the create-time optionsWord/STAT** (`SNAP_ROOM_STAT`, fixed
  2026-08-24): host packs `max/time/pw/area` then `optionsWord = febe4<<1` at create
  (op-04 body `+0x28` BE32); joiner's room-list read (`FUN_005c19d0` record `+0x1c`) decodes
  `scenario=(STAT>>1)&0xFF`, `&0x8000`=locked, `&0x40000000`=hidden. **This is how a joiner
  learns the host's chosen scenario** — server's job is capture-at-create + serve-in-op49, not
  authoring the value itself.
- **OBAREA-W5 mode masks / LE fix (`SNAP_RULE_MASKS_AUTHENTIC` + the scenario byte-order fix,
  both DONE, rig-confirmed 2026-08-24/25):**
  - The `0x6204` TCP area-table download path is **memcpy-verbatim, no byteswap** (unlike UDP
    SN@P, which does swap) — so multi-byte scalar fields inside that blob must be served
    **native little-endian**, not BE. The scenario ring masks at record `+0x14`/`+0x18` were
    served BE32 (`0x000007FF` → loaded natively as `0xFF070000` → zero testable bits →
    `Scenario (null)`); fixed to `writeUInt32LE`. Rules/cast fields are byte reads, unaffected
    by this bug — that's why they fixed first while scenario stayed dead.
  - Rule-row settability = one byte per row, `row+0x42 == 1` (Confirmed decompile,
    `FUN_005fcc70`/`FUN_005f9bb0`/`FUN_005f9e50`). Character/cast row = an 8-bit mask at
    record `+0x03` gating the 8 base characters with **no savedata term** (fully
    server-controllable); `+0x04..0x13` gates *extra* cast, ANDed with savedata (server can
    only permit, never grant). Room title/password settable = `rec+0x16b` bits 0/1.
  - Ring-count PINE falsifier (corrected address, `area-table-scenario-mask-LE-2026-08-24.md`
    §5): screen ctx base `0x6c4b90` → count = `0x6c50CA` (NOT `0x6c4fca`), scenario id ring
    id at `0x6c4b96`, cursor `0x6c50CC`.
  - Version-string bump required on every blob-content change (`OBAREA-V*`→`W*`) — the
    client caches by version string and silently skips the fetch on a match.
- **op-48 name grid**: renders all 10 areas in one frame (G1, solid since 2026-07-06).
- **Player counts (OPEN, G5/G12-7):** area-select per-area count vehicle = UDP op-48/NAME
  reply record `+0x10` (u32) → client `0x6ce5de[box]`; server-select current-players vehicle =
  TCP `0x6510` (LOBBY_LIST_CHUNK) reply u16 → slot `+0x12c` — **NOT** `0x6205`/`0x6504`, both
  previously-assumed vehicles are REFUTED (T25, `G12-count-displays-RE-2026-07-17.md`). Neither
  is wired to real counts yet on 2026-08-25's build (owner-observed "4P" with 2 clients).

---

## 5. Room create/join/seating

### 5.1 Create (op-04)

Op-04 create-slot (`func_0x001dc508`, cb `FUN_005c3a40` @ slot 0x1f, **no channel-bit split**
— single slot). Reply op-28/selector-4/status-0 sets `0x6cba7d=1` → `FUN_005c3490` sets
`0x6ff2b1=1`, the single gate unlocking title/password/scenario/character (NOT a "needs to
reach 3" gate — `0x6ff2b1=3` is a later, separate "applied/locked" finalize state set by
`FUN_005c4580`). optionsWord (STAT) = body `+0x28` BE32, captured for `SNAP_ROOM_STAT` above.
Fix flag `SNAP_CREATE_SLOT_ACCEPT` — **DONE**, superseded/subsumed by the broader
`SNAP_RULE_MASKS_AUTHENTIC` create-screen work, rig-confirmed 2026-08-24.

### 5.2 Join ladder (op-06 room-ENTER)

DATA-clear (room-context) op-06 room-ENTER routes through slot-allocator guards (v2's
`SNAP_JOIN_LADDER`, default ON). The joiner's screen-4 sub-SM parks at major `0x6c4b9f==5`
after sending op-10 sub-0x02 (join-request); a real host answers with op-10 sub-0x0C
(`[0x0C][count LE]`) which fires the joiner's stored continuation → major 5→6 → room renders
(`SNAP_JOIN_OP10_SUBC`, rig-confirmed 2026-07-16, folded into `SNAP_JOIN_LADDER`).

### 5.3 The SEATED-slot roster model (Confirmed, 2026-08-25 — the decisive correction of T19)

**op-06 member-add is the ONLY seat vehicle** for the **4-slot SEATED table `0x6c7c2c`**
(stride `0x3b0`), which BOTH the game-start accept scan AND the in-room member-list renderer
(`FUN_00605790`) read — **NOT op-0a**. Slot layout: `+0x00` 16B ASCII id, `+0x10` name
(occupancy = `name[0]!=0`), `+0x24` 0xf0 charstats.

**Two seat gates:**
1. **G-screen** (Inference, strong): host must be in-room (`0x6c4b90` ∈ {4, 0xe}) at op-06
   receipt for the seater (`FUN_005b5ac0`, fired off op-06's event `0x1f`) to run.
2. **G-dedup** (the once-suspected blocker): on screen 4/0xe the seater scans occupied slots
   and refuses to seat if the incoming charstats dedup key (`charId@charstats+0xc8` /
   `class@+0xca`) collides with an already-seated slot. A fully-zeroed charstats block →
   key 0 → collides → refused. v2 sets `characterId=playernum` (host=1, joiner=2) so `+0xc8`
   differs, avoiding this — confirmed working on the rig (2026-08-25 seating success).

**memberId identity (Confirmed, endianness settled 2026-08-25 — corrects an earlier wrong
causal story):** the accept scan (`FUN_005bbfc0`, sub-4 receiver `FUN_005bba20` case 4)
compares `a0 = frame+0x30 = conn+0x44` (the RECEIVING link's own endpoint token, a per-link
CONSTANT stamped by `FUN_001e180c` — NOT the relayed wire token as first hypothesized) against
a roster entry ASCII-decoded from the op-06 `+0x10` memberId field
(`FUN_005c50a0`/`FUN_005c5120` roundtrip). **Fix `SNAP_MEMBER_ID_TOKEN`:** write
memberId = the RECIPIENT's own endpointToken, BE32 on the wire (`FUN_001d80c8` swaps
wire-BE → native on receipt) — savestate-confirmed the match closes (`a0 == conn+0x44 ==
roster-decoded id`).

**Roster-to-joiner + host-reseat (why count must be 2, Confirmed 2026-08-25):**
`SNAP_ROSTER_TO_JOINER` pushes EVERY existing member's op-06 to a new joiner (not just the
joiner's own record) so the joiner's `0x6c7c2c` gets both entries. `SNAP_HOST_RESEAT`
re-seats the host itself when a joiner arrives, because the join screen-rebuild
(`FUN_005aec20`) clears `0x6c7c2c` and a naive seat sequence loses the host. Both flags
together are what produced the rig-confirmed **count=2, both seated with correct ids**
(2026-08-25 live PINE: `08:21:57 screen=4 count=2 SEAT0=test123 id=00000001 SEAT1=real
id=02f807d0`).

**Deep topology caveat (Inference, strong, `seated-slot-roster-RE-2026-08-25.md`):** a single
host↔server relay link makes `a0` (=`conn+0x44`) CONSTANT per accept, so on a pure relay
topology the accept scan can structurally only ever mark ONE slot — capping non-solo accepts
at 1 unless the client allocates per-peer connection objects for server-relay mode (unconfirmed
in the overlay dumps; a ranked open Ghidra item). **This caveat did NOT block the 2026-08-25
success** — the observed run shows the relay CAN complete a 2-player accept over a single link
(see §6 below); the caveat remains a watch-item for 3+ players, not a currently-blocking fact.

---

## 6. Game-start handshake

Trigger: host op-10 sub-3 to all, after `0x6ff2b1==1`. Joiner's sub-3 receiver
(`FUN_005bbf20`, Confirmed): **iff `0x6c4b90 ∈ {4, 0xe}` (in-room) at the instant sub-3
arrives**, sends sub-4 ACCEPT (`FUN_005c5c10`); else sends sub-0x10 REFUSE (`FUN_005c5c70`,
`0x300` zeros). `0x6ff2b5[i]`: 0 pending / 1 accepted / 2 refused. `0x6ff2b3` (accepted count,
recomputed each check) `< 2` at states 6/7/8/0xa → **solo shortcut** — every accepted-but-
undercounted state routes here, regardless of how many are actually seated.

**Sequence of fixes that closed the 2-player start (all Confirmed/rig-confirmed, in
chronological order this session):**
1. Seating (`SNAP_ROSTER_TO_JOINER` + `SNAP_HOST_RESEAT`) — both host and joiner present in
   `0x6c7c2c`.
2. `SNAP_MEMBER_ID_TOKEN` — recipient's own endpointToken as memberId, so the accept scan's
   `a0` comparison matches.
3. `SNAP_ROOM_STAT` — joiner sees the real scenario (was "Training" / id 0) via op-49 `+0x1c`.
4. Readiness timing — **the one item resolved only by role choice, not a flag**: a
   PC-hosts/PS2-joins run still refused (T23, `0x6ff2b5=01020000`: host accepted-by-default,
   joiner refused) because the joiner's screen was not 4/0xe at the instant sub-3 arrived.
   The **PS2-hosts/PC-joins** run (2026-08-25) succeeded. Whether this is a genuine
   role-dependent timing asymmetry or coincidental readiness on that run is **unconfirmed**
   (PINE timed out during the in-game transition on the successful run, so the joiner's exact
   accept-instant screen state was not captured live).

**Live-PINE evidence the fix chain works (2026-08-25, `RIG-PINE-2026-08-25/FINDING.md` +
`MILESTONE-multiplayer-works.md`):**
```
08:21:45 screen=4 count=1                         (host alone)
08:21:57 screen=4 count=2  SEAT0=test123 id=00000001  SEAT1=real id=02f807d0   <- seating closed
08:22:30 screen=5 count=1 accepts=01020000         (T23 run: joiner refused — role PC=host)
```
vs the **owner-confirmed successful run** (role PS2=host, PC=joiner, same day): **both clients
started the game, with the right characters, and player movement synced across consoles.**
This is the session's culmination milestone (commit `357425f6`).

**Character identity ("Jim" bug) shares the exact same root as solo-start:** the host only
runs the non-solo start branch (sub-5/6/7/8, which includes the sub-7 charstats hand-off) when
the start is genuinely non-solo. On a solo-shortcut start, charstats never exchange, so every
console renders the default character. The memberId/seating fix that unblocks the 2-player
start therefore *also* unblocks correct character identity — confirmed on the successful
2026-08-25 run ("BOTH clients started the game, with the RIGHT characters").

---

## 7. In-game sync (OPEN frontier)

**This is the actual remaining build, not polish.** Wire evidence (`ingame2.pcap`, ~29k
frames, MILESTONE doc):

- In-game packets are **reliable, room-channel, flags `0xa036`** (`0x8000|0x2000|len`) —
  op-0x0F on the game channel. Both consoles emit them; the Pi relays them
  (`SNAP_GAME_RELAY`, matches the bioserver `GameServerPacketHandler` default-branch: broadcast
  raw bytes to every client sharing the gamenumber, excluding the sender — a pure dumb relay,
  no parsing). Plus unreliable `0x2012` beacon frames (`0xa04c`/`0xa05c`).
- **The lossy relay problem:** the emulator emitted ~890 reliable `0xa036` game packets in one
  session; census shows **1727 total op-0x0F from the emulator vs only 791 relayed to the
  PS2**. The reliable channel's 32-message window is a candidate overflow point (nora's
  `SNAP_GAME_RELAY` hazard #2, flagged not yet fixed).
- **Symptom (owner):** the joiner (emulator) sees a zombie the host (PS2) does not, and can't
  interact with it. Player MOVEMENT syncs (explicit position relay works); ENEMY state does
  not — **the two consoles run independent enemy simulations** (diverged RNG seed and/or lost
  enemy-state packets), not one shared authoritative sim.
- **Bioserver contrast (the reference behavior to converge toward):** JP's game server (port
  8590) is a **dumb length-prefixed TCP relay** — lossless by transport choice (TCP), whereas
  our relay rides the SAME reliable-UDP channel that already has known window/overflow
  behavior under load. This is the concrete difference to close: either an **unreliable relay
  for game packets** (matching TCP's "just deliver everything, framing only" behavior via a
  channel that doesn't drop on overflow) or a **larger in-game reliable window**.
- **What's needed, not yet in the corpus:** the in-game packet PAYLOAD semantics (what
  `0xa036` actually carries — player input vs enemy state vs an RNG seed) and the game-engine
  memory map for enemy state. Neither is RE'd yet. NEW GOAL for the next session per the
  MILESTONE doc.

---

## 8. Our server flags → protocol map

(`server-v2/src/config/server-config.js`, `snapLobby` block. All default OFF unless noted.)

| Flag | Implements | Status |
|---|---|---|
| `SNAP_CHANNEL_BIT_ECHO` | op-28 sel-7/8 completions echo the request's `0x1000` DATA bit — §2.2/§6 in-room Exit fix | **DONE**, rig-confirmed 2026-08-24 (Exit releases the room) |
| `SNAP_ROOM_CHAT_SUB7` | (attempted) room chat via op-10 sub-7 | **HELD/NOT GROUNDED** — sub-7 is Confirmed elsewhere as the charstats vehicle; flipping it risks corrupting the rule screen (nora). In-room chat vehicle is OPEN again. |
| `SNAP_GAME_RELAY` | reliable game-channel op-0x0F relay to room members (bioserver default-branch) | **DONE (scope proven) / lossy under load** — §7 |
| `SNAP_ROOM_STAT` | op-49 `+0x1c` carries the create optionsWord so joiners see the real scenario | **DONE**, rig-confirmed |
| `SNAP_MEMBER_ID_TOKEN` | op-06 memberId = recipient's own endpointToken | **DONE**, rig-confirmed (part of the seating fix chain) |
| `SNAP_ROSTER_TO_JOINER` | push every existing member's op-06 to a new joiner | **DONE**, rig-confirmed |
| `SNAP_HOST_RESEAT` | re-seat the host on join so `0x6c7c2c` holds both | **DONE**, rig-confirmed |
| `SNAP_JOIN_LADDER` (default ON) | op-06 room-ENTER guards + op-10 sub-0x0C join-confirm | **DONE**, rig-confirmed (folds in the older `SNAP_JOIN_OP10_SUBC`) |
| `SNAP_OP10_RELAY` (default ON) | op-10 recipient-addressed relay, except-sender | **DONE**, verified by the 2-player start itself |
| `SNAP_OP0A_COUNT0` (default ON) | op-0a member-list answered with the 12-byte count-0 body | **DONE** — avoids the "Getting information" starve |
| `SNAP_MEMBER_INFO` (default ON) | op-28 sel-0x0a roster records + op-10 sub-1 pushes | **DONE** |
| `SNAP_COUNT_PUSH` (default ON) | unsolicited op-0x09 USER count re-broadcast on area enter/leave | **DONE** (mechanism) — actual displayed counts still wrong (§4, G5/G12-7 separate gap) |
| `SNAP_APP_KEEPALIVE` (default ON) | 30s op-10 who-`0xA000` app-liveness push, holds off the ~145.7s watchdog | **DONE** |
| `SNAP_ROOMFLAGS_PUBLISH` | publish authored room status in op-49 flags `+0x1c` | OFF — superseded/subsumed by `SNAP_ROOM_STAT`'s STAT publish |
| `SNAP_CREATE_CONFIG` (default ON) | TCP create-config rows 0x6407..0x6504 post-ladder | **DONE (wire-inert path unobserved)** — no rig capture has yet exercised this exact TCP path; safe no-op until it does |
| `SNAP_OPTION_LABELS` | `+0x12fc` option-label table, zero records, OBAREA-W4 | OFF (isolation policy — one suspect per deploy) |
| `SNAP_RULE_MASKS_AUTHENTIC` (default ON) | the whole create-screen unlock: rule rows, `+0x03`/`+0x04..0x13` cast, `+0x16b` title/pw, `+0x14`/`+0x18` scenario ring (served as OBAREA-W5, LE-fixed) | **DONE**, rig-confirmed 2026-08-24/25 (rules, cast, scenario all selectable) |
| `SNAP_LOBBY_BUTTONS` (default ON) | RANKINGS/GETINFO/BUDDYLIST/CHECKBUDDY post-ladder | wire-inert until the client sends one (G6/G7 — not yet observed) |
| `SNAP_EXIT_CLOSE_MIRROR` | mirror op-0x02 close, release session | OFF — the exit park was actually fixed by `SNAP_CHANNEL_BIT_ECHO`, not this |
| `SNAP_COMPLETION_SEQ_ECHO` | echo request send-seq at completion `+0xc` | OFF — superseded reasoning, kept for reference |
| `SNAP_GAME_BEACON_ECHO` / `_RELAY` | echo/relay the `0x2012` in-game beacon | OFF — **tested and made things WORSE** (RS1-A: faster, harder failure); must stay OFF |

---

## 9. What's left for the working game (ranked)

1. **In-game entity/enemy sync (the big one, §7).** Player movement already syncs; enemy
   state does not. Needs: (a) payload semantics of the `0xa036` reliable game packets
   (input vs state vs seed), (b) a fix for the relay's message loss under load (unreliable
   relay for game packets, or a larger reliable window — bioserver's TCP relay is lossless by
   transport choice, ours currently is not under load), (c) confirmation of whether enemies
   are meant to be host-authoritative-broadcast or independently-seeded-deterministic.
2. **Lobby/room polish (secondary, all have a known vehicle):**
   - Real player counts everywhere (area-select `op-48 record +0x10`, server-select TCP
     `0x6510` reply u16 → `+0x12c`) — vehicles Confirmed, not yet wired to live counts (G5/G12-7).
   - In-room member list showing joiners — same seated-table vehicle already fixed for
     game-start; the *drawn* list (`FUN_00605790`) reads the same `0x6c7c2c` table, so this
     should already track once seating renders — needs a rig check specifically on the
     member-list UI, not just the accept mechanism.
   - Room/in-room chat (the sub-7 vehicle is disproven; the real vehicle is un-RE'd — OPEN,
     needs a targeted capture of a chat send while in a room).
   - Buddy/friend list (G6, server gap, unimplemented).
   - End/results-screen character display still wrong (savestate 10 note, likely same
     charstats-timing family as "Jim" but on a different screen/state — unconfirmed).
3. **Latency.** ~1s input→render latency through the Pi relay, noted by the owner as real but
   not currently a blocker; no root-cause work done yet — lowest priority until (1) and (2)
   are further along.

---

## Appendix: what openSNAP did NOT resolve for us (recorded so nobody re-asks)

- No Outbreak plugin exists upstream (AM-only); every Outbreak-specific payload (area records,
  room records, charstats blobs, create-slot 0x65xx/0x66xx TCP handshake) remains our own
  corpus + Bioserver-semantics work — openSNAP only gave us transport/flag vocabulary and
  design oracles for edge cases (dedup, windowing, ack semantics).
- Room chat's real PAL vehicle (not sub-7) is still unknown — openSNAP's `0x0F`+`0x0400`+
  context-bit chat model is Confirmed as PAL's *outer* shape, but the in-room *rendering* path
  is still unproven wrong/right on PAL (nora explicitly disputed the sub-7 hypothesis).
- Bootstrap `0x40` is AM-specific (SWAN challenge) and explicitly does NOT describe PAL's
  game-phase `0x40` keepalive — do not let the shared opcode number imply shared semantics
  (§2.4, §3 table row).
