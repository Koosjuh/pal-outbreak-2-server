# Facts

## CURRENT MODEL — goal-tagged (2026-07-04 consolidation)
Single source of the *current* confirmed model. Where the chronological archive below conflicts with
this section, **this section wins.** Full technical detail:
`docs/findings/protocol/LOBBY-UNIFIED-ARCHITECTURE-RE-2026-07-03.md`. Goals: `GOALS.md`.

**G1/G2 — lobby + re-entry**
- Lobby nav: top `FUN_005acab0` on screen byte `0x6c4b90` (1=Area-Select, 2=Lobby, 0xe=Room/Slot);
  Area-Select sub-nav `FUN_005ace00` on `0x6c4b9e`.
- Cursor-lock root = sub-pool-2 watermark latch (op49 can't transmit); ack lobby op48 to free sub2.
- Area-Select renders all 10 areas (op48 reply = all records in one frame).
- **Validated golden (Confirmed, rig 2026-07-05):** `ec69007` (gudp md5 `25a5c956` / snap md5
  `8e01d0dc`, tag `golden-lobby-full-2026-07-05`) — all 10 areas, Free-first, X-on-area advances into
  the lobby, on a clean PINE-silent (passive-pcap) rig pass. Checkable record: `GOLDENS.md`.
- **Regressor — CORRECTED (2026-07-05 late): `d3dacf3`/scenario is NOT confirmed as the area-enter
  regressor.** Earlier this session it was called the regressor because reverting to `ec69007` seemed
  to fix enter — but that was a **confound**: `ec69007` (scenario code absent) *also* stalled ("75%
  Healing cursor stuck") and only advanced once `SNAP_ACK_OP48_F0=1` was added (next bullet). The real
  wall was the sub-pool-2 latch. Decompile agrees the scenario byte is **enter-safe**: the enter gate
  `FUN_005ad350` reads area rec `+0x01/+0x02/+0x14c` but **never `+0x03/+0x04`** (only `FUN_005fe300`
  reads +0x03; see `G8-createslot-handshake-RE-2026-07-05.md`). Open test to settle it: deploy `d3dacf3`
  **with** `SNAP_ACK_OP48_F0=1`. `ec69007` remains the recorded golden regardless; scenario drop-in
  stays disabled until that test (belt-and-suspenders).
- **First-area-enter advance FIX (Confirmed, rig 2026-07-05):** `SNAP_ACK_OP48_F0=1` (commit `4720f2c`,
  gudp md5 `ed19d816`, tag `golden-area-enter-advances-2026-07-05`). Root cause: during area-select the
  client sends ~55% of its op48 as `who=0xF0`; the server excluded `0xF0` op48 from acking (stale guard
  against a since-removed bug) → those sub2 buffers never freed → sub2 free dipped below watermark →
  latched disabled → op49's one-shot alloc refused (PINE `0x0025b790=0x65`) → lobby SM never advances
  past state 0 (cursor locked, screen stuck at 1). Fix: ack `who=0xF0` op48 by outer id too. Rig-verified:
  sub2 stays healthy, op49 transmits, screen `0x6c4b90` 1→2 — first area-enter now advances.
- **Re-entry stall (G2, OPEN — root cause Confirmed, fix not yet found):** from an in-area lobby,
  Triangle-back → select a NEW area → stalls (screen stays 1). Same sub-pool-2 watermark latch (PINE
  `0x0025b790=0x65`), but the F0-ack fix is NOT sufficient: the re-entry op48 burst is ~3x bigger
  (~126 vs ~40) and it is **circular** — latch → op49 refused → SM doesn't advance → client keeps
  flooding op48 → free never climbs back above watermark → stays latched. All sends ARE acked (no leak);
  box-enable bytes (`0x6ce5f0`/`0x6c386e`) are all `=3` (not the box-reactivation latch). Sub-pool struct
  (Confirmed, decompile): `conn` (deref `0x0025b78c`) `+0x520`; sub2 at `pool+0x28`; disable-bit
  `pool+0x36` (`sub2+0xe`); watermark `pool+0x74`; alloc-refuse `FUN_001ec1f8` (sets disable-bit via
  `FUN_001eb33c` when `free<pool[0x74]`), clears via free path `FUN_001e1ac8`/`FUN_001eb37c` when
  `free>watermark`. A PINE poke (lower `pool+0x74` to 0 + clear `pool+0x36` bit0) is STAGED, not yet run,
  to prove sub2 is the sole re-entry wall.
- **Ruled out (corrections):** the op06 who-byte (`0xf8` vs `0xb0`) is a red herring — dispatcher ignores
  those bits, server ignores op06 who. The earlier "op48 flood on first-entry" was PINE observer-effect,
  not a real flood. `G2-area-reentry-RE-2026-07-04.md`'s "WALL A = txSeq out-of-window" and token-echo
  theories are REFUTED — op48 replies are delivered+acked in-order; that doc is archived. Full session
  writeup: `docs/findings/protocol/G2-SESSION-2026-07-05.md`.

**G12 — create-a-room session-open (2026-07-12, decompile + savestate confirmed; rig-verify pending)**
- Create-a-room = **`FUN_005f99c0`** SM (NOT `FUN_005fada0`, the op06-ENTER path earlier work targeted —
  that SM is unused by this flow). It registers the room via **op04** (create-slot, `func_0x001dc508`,
  cb `FUN_005c3a40` @ slot 0x1f). The field-unlock gate `0x6ff2b1` (title/password/scenario/character) is
  set by `FUN_005c3490` when `0x6cba7d=1`, which the op04 completion (server reply op28/selector-4/
  status-0) sets via `FUN_005c3a40`. Evidence: post-Finish savestate slot 4 (frozen `0x6ff2b1=0`,
  `0x6cba7d=0`, `0x6cba7c=1` pending) + decompile trace + a local replay of the real captured op04 bytes.
  Fix `SNAP_CREATE_SLOT_ACCEPT` (commit `781f496`). **NOT yet rig-verified** (no Pi deploy-with-flag test,
  no `GOLDENS.md` entry) — see `GOALS.md` G12 for the to-MET checklist. Ordered sub-goal tracker:
  `docs/findings/protocol/G12-SUBGOALS-2026-07-12.md`.

**G12-5 — joiner ROOM RENDER: game-channel op10 join sub-selector protocol (Confirmed, owner-witnessed
2-device rig, 2026-07-16 22:48)**
- The join session's game-channel op10 is dispatched by slot **0x13 = `FUN_005bba20`**, installed via
  `func_0x001d4d24`, on the received app-payload **byte[0]** (wire+0x18, the op10 body's third 32-bit word) —
  a sub-selector, not a numeric param: `0x01`=member/player-info (`FUN_005bbb90`), `0x02`=**join-request**
  (`FUN_005bbc20`, host-side accept — sent by the joiner via `FUN_005c5ff0`), `0x0C`=**join-confirm**
  (`FUN_005bbe00`, fires the joiner's stored continuation — sent by the host via `FUN_005c6050`),
  `0x0E`=a separate 6s-fallback escalation query (`thunk_FUN_005c61b0`, distinct message, not a retry-param
  of 0x02).
- The joiner's screen-4 sub-SM (`FUN_005fe620`→`FUN_005fe730`, major `0x6c4b9f`, step `0x6c4ba0`) parks at
  **major=5** (`FUN_005fed70`, advances only when step==1) after `FUN_005fed10` sends the op10 sub-0x02
  join-request and stores continuation `FUN_00601300` in `uRam006fec00` under screen-local marker
  `0x6c4fbb=0x17` (NOT a session-open pool id — the `FUN_005be120` dual-key pool is idle at the stall,
  savestate-confirmed). `FUN_005bbe00` (the sub-0x0C receiver) fires `FUN_005bf230(uRam006fec00)`, which on
  status=0 sets step=1 → major 5→6 → the room renders locally (`FUN_005fede0`). The CREATOR never stalls
  here because `FUN_005c44a0`'s host branch (`0x6ff2b0!=0`) fires the continuation inline, no network
  round-trip (`FUN_005c44a0`, helper:18700-18726).
- Prior op10 sub-1 proactive push (from the earlier `SNAP_ROOM_INFO_OP10` work) DOES reach slot 0x13 and run
  its handler (savestate: `0x6fc2d8`/`uRam006febe8` show sub-1's side effects) — it was never "discarded";
  it is simply the wrong sub-selector to advance the join SM.
- **Fix `SNAP_JOIN_OP10_SUBC=1`** (`server/game_udp_server.js`, inside the existing `SNAP_ROOM_INFO_OP10`
  op10 branch): on a game-channel op10 with wire+0x18==0x02 from a joiner, reply one op10 with app-payload
  `[0x0C][count LE]` (count from the `lobby_state` registry, fallback 1), same reliable in-window delivery
  path as the sub-1 push. Commits: `bb03ff5` (T21 trace evidence) → `e7757e0` (fix) → `e1d4a09` (flag ON in
  tracked drop-in) → `27941b4` (T22 2-device rig evidence) → `2594d02` (owner verdict doc).
- **Rig-confirmed (Confirmed, owner-witnessed, 2-device: emulator creator + real PS2 joiner, 2026-07-16
  22:48):** Pi gudp md5 `cead951e` == repo; journal shows `OUT #1251 [JOIN-ACCEPT op10 sub=0x0c count=2
  seq=0x26a]`; the PS2 joiner's room screen LOADED for the first time ever ("we made a room, we are both in
  now" — owner). nora pre-deploy review: GROUNDED-WITH-CAVEATS.
- **CORRECTS the 2026-07-16 `G12-joiner-render-RE-2026-07-16.md` model** (joiner waits on a SECOND
  session-open under tag `0x14`; the op10 push is silently discarded because screen never reaches `0xc`;
  joiner stuck in an op0a poll loop). T21 (`SESSION-LOG-2026-07-12.md`) showed op0a IS answered and passed,
  tag 0x14 never arms, and the sub-1 push DOES land (`0x6cbc7e`→0x10); the real stall is tag 0x17. That doc
  now carries a correction banner pointing here and to `G12-joiner-tag17-RE-2026-07-16.md`; its content is
  kept (not deleted) for history.
- **Owner verdict (2026-07-16 22:48, T22 addendum + addendum 2): G12-5 NOT MET overall.** Render mechanism
  works, but the joined room is not yet functional: (1) roster/count mismatch (PS2 joiner shows "1 play",
  emulator creator shows 2; members don't SEE each other beyond the count mismatch — maps to the known
  op0a-lists-all-registry-members + fire-count-once work, T19 items 2/3); also SERVER SELECT and AREA SELECT
  both show 0 players on this run — the known hardcoded TCP `0x6205` / registry-cross-population gap (G5),
  not new; (2) chat does not work (NEW, un-RE'd); (3) scenario not selectable + (4) other cast members not
  selectable (the known `0x6ff2b1` 1→3 RULE-screen/create-config unlock layer, T13/T17, G8 create-slot
  handshake). Parking lot (not this goal): cannot EXIT a lobby room (screen=6 freeze) — candidate G13/G14.
- Owner asked nora to evaluate this deployed state (Pi `cead951e`, `e7757e0`+`e1d4a09`) as a possible new
  golden baseline; **that review has not happened yet** — no `GOLDENS.md` entry exists. Flag
  `SNAP_JOIN_OP10_SUBC` remains experimental/unpinned until it does.

**G12 — identity vehicle: names + character (Confirmed, snap-re 2026-07-17,
`docs/findings/protocol/G12-identity-vehicle-RE-2026-07-17.md`, commit `dc4a6df`)**
- PAL does **NOT** run the JP Bioserver TCP identity handshake (no `0x6131`/`0x6132`/`0x6190` sent by
  the client; no NO-HANDLER lines for them). **Refutes the "needs three new IDHNPAIRS/HNSELECT/
  CHARSELECT handlers" assumption.**
- Every displayed name is simply the **16-byte string at member-record offset `+0x00`** (record layout
  `name[16]@+0x00 | id_u32@+0x10 | len@+0x14 | charstats[0xf0]@+0x18`, shared by op06 member-JOIN and
  the op0a member-list); the client renders exactly the bytes the server sends — no separate
  handle/nickname split. **Fix (zero client risk, copy-ready):** replace the `PLAYERn`/`CREATOR`
  literals with the real login handle (`p.handle`, already captured at UDP register body offset `0x10`
  and post-register-bind offset `0x20`) at the member-name write sites (`sendMemberJoinOp06`,
  `sendMemberJoinBroadcast`, op0a member-list rows). The engine's `displayName()` (`lobby_state.js`,
  commit `2b7e13c`) already routes names this way — wiring the engine emissions gets this for free.
- **Character = the 0xf0 charstats blob at member-record `+0x18`** (relayed in-room via a dedicated
  update op → `FUN_005bc430`); the server currently sends it zeroed → "wrong character". **Capture-gated
  (NEEDS-VEHICLE):** no confirmed in-room outbound client→server charstats op yet — a create→
  character-select UDP capture is needed to find the send op and store-and-echo it.

**G12 — op49 room-list record fields + endianness (Confirmed, snap-re 2026-07-17,
`docs/findings/protocol/G12-op49-fields-RE-2026-07-17.md`, commit `83c95b9`)**
- op49 record stride = **0x28** (not 0x24 — that stride belongs to the op48 named-slot subsystem, a
  different message; do not conflate). Fields the client reads: name`@+0x00`, current`@+0x14`,
  aux`@+0x18`, flags`@+0x1c`, max`@+0x20`, handle(ENTER target)`@+0x24`.
- **THE BUG:** every op49 numeric field `+0x10..+0x24` is **byteswapped by the transport**
  (`FUN_001d7d20`) before the app reads it. The server wrote current/aux/flags/max/handle
  **little-endian** (`game_udp_server.js` REGISTRY builder ~1938-1943) — after the client's byteswap
  this reads as 0. This CORRECTS the 07-11 "rig-validated" op49 render note — that test only confirmed
  a *named row* rendered (name bytes are endian-agnostic), never the displayed count/max digits.
- **FIX (implemented `665994d`, flag `SNAP_OP49_BE`): flip only the 3 DISPLAY fields** current`@+0x14` /
  flags`@+0x1c` / max`@+0x20` to `writeUInt32BE`. **The handle`@+0x24` is DELIBERATELY kept LE** — it is
  an opaque round-trip ENTER token (client stores it, ENTERs it back, we read `readUInt32LE`), and join
  is rig-proven working with LE (journal `JOIN handle=0x2`). The per-field byteswap is independent, so
  display-BE + handle-LE coexist safely; keeping the handle bytes identical to the proven build = zero
  delta to the proven ENTER. Flipping the handle to BE is the change that WOULD perturb the round-trip →
  deferred to its own rig check. **Do NOT "flip all four" — that regresses the join.** (nora 2026-07-17;
  the record `count`@body`+0x08` is already correctly BE.)
- **No status/joinable byte exists in the record.** Status is derived client-side: `current==max` →
  FULL (glyph 4), else open (glyph 3); a separate **locked** flag = flags **bit16**; flags **bit30** =
  hide the record entirely. INCREATE/GAMESET have no direct op49 encoding — map INCREATE (not-yet-
  joinable) → full or locked; GAMESET (open) → `current<max`, flags=0.

**G12 — config/rules/scenario/cast: HOST-OWNED, RELAY not server-authored (Confirmed, snap-re
2026-07-17, `docs/findings/protocol/G12-config-unlock-RE-2026-07-17.md`, commit `973fe33`)**
- Rule/scenario/description text is **client-owned**, sourced from the HOST's own room-config screen
  buffer, and distributed **host→members** as a game-channel **op10 sub-selector burst**: sub-3 reset →
  sub-5 values → sub-6 names → sub-7 descs → sub-8 attr → sub-9 fixed (message layout: selector
  `wire+0x18`, data starting `wire+0x1c`, same framing as the rig-proven sub-0x0c). The server's role is
  a **relay/host-proxy** — for a joiner to see any config the server must forward the host's op10 config
  sub-messages, and echo the host's TCP `0x6509`(SCENESELECT)/`0x6609`(SLOTNAME)/`0x660B`(SETRULE)/
  `6504`(finalize). None of the TCP handlers nor the op10 relay exist today.
- **CORRECTION:** the unlock gate `0x6ff2b1` reaches **1** on the **op04 create-slot accept**
  (`FUN_005c3490`, `SNAP_CREATE_SLOT_ACCEPT`) and that single value **enables every config receiver** —
  it is **NOT** a "needs to reach 3" gate as the 2026-07-16 owner-verdict note framed it (T13/T17,
  `GOALS.md` G12-5). `0x6ff2b1=3` is set later by `FUN_005c4580`, from a different, later case — a
  late "applied/locked" finalize state, not the unlock threshold. Both host and joiner sit at 1 while
  configuring.
- Character/cast is **not a rule** — it's roster-derived (member handle + per-player charstats), gated
  by the same scenario-unset problem; the scenario→cast-mask table is not in any dump (RE flag if cast
  stays wrong after the scenario fix).
- **`max-players` writer (`0x6cfa2c`) is ABSENT from every dump** (only cleared/read, never
  non-zero-written) — a hard blocker; do not guess the vehicle, needs the writer decompile or a
  create→configure capture.

**G12 — exit contract: room-exit freeze is an unanswered SN@P transport close (Confirmed, snap-re
2026-07-17, `docs/findings/protocol/G12-exit-contract-RE-2026-07-17.md`, commit `973fe33`)**
- Exiting a room is a **two-stage teardown**. The freeze the owner sees at screen `0x6c4b90==6`
  ("moving background", never advances) is **stage 2**: the client sends a SN@P **`0xb000` control
  packet, type 2 (transport session CLOSE)** on the game UDP connection (`func_0x001dbe60` →
  `FUN_001dbd0c` → `FUN_001e180c(conn,...,0xb000,0,2,0)`); the screen-6 SM (`FUN_005f6b00`/
  `FUN_005f7270`) parks until the transport signals disconnect-complete (`cRam006cbbe0` reaches state
  **2**, fired by `FUN_005be7b0`). **Our server never completes this close handshake, so the state never
  reaches 2** and the screen never advances. This is **server-side satisfiable** — the client initiates,
  the server only has to answer (unlike the ACK'd-but-undelivered server-push class of bug).
- **Stage 1 (tag `0x6c4fbb=0x19`, app-level "leaving"):** the screen-4 create/config SM sends a
  session-open/STAT (`FUN_005c0750`, dual-key pool `0x6cbc80`/`0x6cbc7c`) completed by an **op28
  who=0xA0 selector-8 status-0** reply echoing the client's send-seq at body `+0xc` (mirrors the
  create-accept contract). **Not proven** whether stage 1 arms on a plain joined-room exit (vs.
  create/config-only) — needs the targeted capture.
- Survivor notify (Bioserver LEAVESLOT mirror) = a game-channel **class-6** leave message (leaver id,
  `FUN_005bb670`→event 0x20, roster compaction) **+ op10 sub-0x11** (new count) to each remaining
  member — the same sub-0x11 vehicle join already uses.
- Highest-leverage next step: handle the client's `0xb000` type-2 close server-side (flag
  `SNAP_ROOM_LEAVE_CLOSE`, default OFF) — drive the SN@P close handshake to completion; needs one
  full-logged (pcap + PINE `0x6c4fbb`/`cRam006cbbe0` + journal) exit capture to confirm the exact
  server reply shape and whether stage-1 op28 sel-8 is also required.

**G12 — FOUNDATION room engine (2026-07-17, plan of record + RE sweep complete)**
- Owner decision (T24/T24-addendum, `docs/findings/protocol/SESSION-LOG-2026-07-12.md`): stop
  per-message flag patching; port the Bioserver reference server wholesale (ClientList/Slots/
  PacketHandler → JS around `lobby_state`), mapped via `docs/design/FOUNDATION-MAP-2026-07-17.md`
  (per-phase Bioserver-contract ↔ PAL-vehicle dictionary, status legend COPY-READY/PROVEN/PARTIAL/
  UNHANDLED/NEEDS-VEHICLE/STUB) and `docs/design/ROOM-ENGINE-DESIGN-2026-07-17.md` (the in-room
  component, three-review final: nora × second_opinion × Codex).
- **Step 1 landed (commit `2b7e13c`): `server/lobby_engine.js` (new) + `server/lobby_state.js`
  extensions** — SLOT status lifecycle (FREE/INCREATE/GAMESET/BUSY), playerNo assignment, identity
  fields (hnpair/charStats/displayName landing zone), liveness fields, live-scan count triple, audience
  filters. **INERT** — no frontend routes to it yet, no wire/behavior change, 41/41 existing
  `lobby_state` tests still pass.
- **RE sweep complete (5 findings docs, 2026-07-17, snap-re, commits `111e93b`/`dc4a6df`/`83c95b9`/
  `973fe33`):** turned most FOUNDATION-MAP unknowns into COPY-READY fixes (counts, names, op49
  endianness) or vehicle-known+capture-gated items (character charstats, config interleave, exit
  stages, max-players writer) — see the four blocks above and
  `docs/findings/protocol/G12-count-displays-RE-2026-07-17.md` /
  `G12-identity-vehicle-RE-2026-07-17.md` / `G12-op49-fields-RE-2026-07-17.md` /
  `G12-config-unlock-RE-2026-07-17.md` / `G12-exit-contract-RE-2026-07-17.md` for full detail.

**G3 — area description box** — `+0x4c` loads to `0x6ce616`→`0x6c38b9` but no client function draws it.
Dead pipeline, not server-fixable (Confirmed).

**G4 — two message boxes** — client requests `0x6103` (not `0x6105`); needs the `0x6103`/`0x6104` text path.

**G5 — multiplayer presence** — **CORRECTED 2026-07-17 (snap-re, T25 journal evidence +
`docs/findings/protocol/G12-count-displays-RE-2026-07-17.md`): "area count = TCP `0x6205`" is
REFUTED.** T25 (`SESSION-LOG-2026-07-12.md`) observed the client send ZERO `0x6205` queries while
area-select showed 0 players, and a live `0x6504` currentPlayers value did not move the server-select
display either — both previously assumed vehicles are wrong. Confirmed vehicles (decompile):
- **Area-select per-area count** = fed by the **UDP `op48`/NAME reply record `+0x10`** (u32, consumed
  by `FUN_005c1220`) → client memory `0x6ce5de[box]` (u16); we send `NAMEDSLOT_WORD0=0xffff` (the
  "unset" sentinel) there, which draws 0. Fix = write the real per-area count at record `+0x10`.
- **Server-select current-players** = the **`0x6510` (LOBBY_LIST_CHUNK) reply u16 → slot `+0x12c`**
  (`FUN_001c8790`), **NOT** the `0x6504` trail `field_d` (lands at slot `+0x128`, undrawn; only
  `field_e`/max at `+0x12a` draws the "/4"). `snap_server.js:1381` sends `payloadBE16(0)` — that zero
  IS the displayed 0. Fix = send the real count there.
In-lobby list = UDP `op49` still stands as the room-list vehicle (see the G12 op49-fields correction
above for the endianness bug). Needs a server session/room registry cross-populating both — still
true, now vehicle-correct.

**G8 — scenario / create-slot**
- Scenario carrier = area record `+0x03` (group bitmask; server-controllable, confirmed landing `0x1F`).
- Per-group scenario table `0x341ac8` = network-only, **no code writer** in dumps; title resolver
  `func_0x001b6950` external → titles are disc/runtime.
- Scenarios are **client-owned** (Bioserver: `SCENESELECT` 0x6509 only, no list command). Rules ARE
  server-sent (`0x66xx`). Online list = 11 (WT,UB,FB,DT,EOTR + Elim×3 + Showdown×3), Training excluded.
- Scenario + rules + character are gated on the **create-slot handshake** (`0x65xx`/`0x66xx`); they
  populate together, not individually. CREATESLOT: create=0x70 (`FUN_005c0750`), enter=0x6e (`FUN_005c04f0`).
- **UPDATE 2026-07-17:** the *in-room* config layer (post-create rules/scenario/cast) is HOST-OWNED and
  delivered peer-to-peer over a game-channel op10 sub-3/5/6/7/8/9 burst that the server must RELAY (not
  author) + echo the host's TCP `0x6509`/`0x6609`/`0x660B`/`6504`; the unlock gate `0x6ff2b1` reaches
  **1** (not 3) on op04 accept. Full contract in the G12 config/rules/scenario/cast block above
  (`G12-config-unlock-RE-2026-07-17.md`); this G8 entry is unchanged/still correct for the create-slot
  handshake itself.

**Rig / tooling**
- PINE "refused" = zombie clients hogging its single slot; clear Established:28011 before probing.
- No persistent-PINE-interactive emulator launch mode: harness `--poke` exits (kills PCSX2 child),
  sampler mode hogs PINE. Independent `Start-Process` launch persists + leaves PINE free. Tool gaps
  (rig-doctor, persistent-PINE launch, labeled create-screen dump, journal↔PINE↔pcap correlator) noted.

---
## Archive — chronological updates (historical; superseded by CURRENT MODEL above)
_Findings docs referenced below were moved to `docs/findings/protocol/_archive/` (2026-07-04 consolidation)._

### Update 2026-07-02 — LOBBY CURSOR-LOCK ROOT = sub-pool 2 watermark latch (Conf High, Ghidra+PINE)
- The in-area lobby renders but the cursor is locked because the room-list query **op49** never
  transmits. **CORRECTION: it is NOT pool exhaustion** (the entire 2026-07-01 "drain the
  conn+0x520 pool via cumulative-ACK" premise is FALSIFIED — T7 PINE showed sub-pool free counts
  110/15/3 with SNAP_ACK_OPS=all, i.e. free blocks available).
- Real cause: a **watermark-hysteresis latch on connection sub-pool 2**. Pool init
  `FUN_001ebed0` (via conn init `FUN_001d46ec`) = 3 sub-pools: sub0 110×236B(wm6), sub1
  15×556B(wm3), **sub2 10×940B(wm3)**. op48 (`FUN_001e094c`) and op49 (`FUN_001e0ed8`) both alloc
  `FUN_001d5288(conn,0x2a8)` = req 700B → fits ONLY sub2. `FUN_001ec1f8` param5=1 refuses a
  sub-pool whose disable-bit (`subpool+0xe` bit0) is set; bit SETS when free<3 after alloc
  (`FUN_001eb33c`), CLEARS only when free>3 after a free (`FUN_001eb37c`). The lobby op48 poll
  keeps ~7 of sub2's 10 blocks in flight, dips free to ≤2, latches sub2 → op49 alloc refused
  (`0x25b790=0x65`).
- Cursor gate `FUN_005aec70` reads input only if lobby-struct `+0x45a!=0`; lobby state0
  `FUN_005f78c0` zeroes it every frame → cursor dead until the SM advances past state0, which
  needs the op49 completion cb `FUN_005f7b30`. ⇒ op49 IS the gate (confirmed).
- FIX (deployed, md5 e5482a82, awaiting rig): ACK the game's lobby op48 (`0xB0/0xB8`) sends so
  their sub2 buffers free (`FUN_001e1ac8`), keeping sub2≥4, clearing the latch. Prior SNAP_ACK_OPS
  code EXCLUDED klass named-slot-query so op48 was never acked = the bug. Safe now: op48 also gets
  a valid structured reply (ready_6ce5be=10), no T3 re-arm flood. See
  HANDOFF-2026-07-02-lobby-cursor-watermark-latch.md + LOBBY-STATE-MACHINE-RE-2026-07-02.md.

## Project

- Name: PAL Resident Evil Outbreak File 2 Server / SN@P.
- Type: reverse engineering, coding, and research project.
- Goal: create a production-capable private server path for PAL Resident Evil Outbreak File 2 using original hardware and original games with DNS-only client configuration.
- Project folder: `D:\projects\pal-outbreak-2-server`.
- Previous active workspace: `C:\dnas`.

## Constraints

- The end product must not alter the ISO.
- The end product must not require game patches.
- The intended client path is original hardware and original game disc compatibility.
- Client-side setup should be DNS-only.
- Original inputs must be preserved.
- Reverse-engineering evidence must record hashes, versions, offsets, addresses, protocol observations, and assumptions.
- Static evidence, dynamic evidence, and inference must be separated.

## Current Milestones

- Milestone 1: successful login in controlled test.
- Milestone 2: create a lobby with one emulator client and one PS2/original-hardware client.
- Milestone 3: create account creation and persistent account storage, possibly with a website or local server.

## Confirmed (2026-06-29) — Area Select renders on REAL PS2 + Emulator

- **VERIFIED ON HARDWARE:** the Area-Select grid renders on both the real PS2 and the PCSX2 emulator.
- Deployed server = `pal-deploy.git` commit `261947c` ("VERIFIED BASELINE: UNIFY seq fix"); Pi md5 `ed7a763ca8b11136b2524ae42526919c`. Env: `SNAP_CMD0C_SELECTOR12=1`, `SNAP_LOBBY_SLOTS=2`.
- **Root cause (fixed):** reliable SN@P (UDP 9090) seqs came from TWO colliding counters — `nextTxSeq` (reset on every re-register) for register/op48 replies, and `gameAck+N` for the cmd0c render pushes. On real PS2 (RTT + repeated re-registration) the same reliable seq carried two packets → receive-base oscillated → selector-12 render push never delivered in-order → no grid. Emulator (RTT≈0, no re-register) tolerated it → rendered. Explains "renders on emulator, not PS2".
- **Fix (3 lines on 31dd79b):** route the cmd0c selector-12 + memberlist pushes through `nextTxSeq` (one monotonic counter) and seed `s.txSeqNext` ONCE (no rewind on re-register). One unified, never-rewinding reliable stream → PS2 receive-base advances cleanly.
- **Evidence:** `docs/findings/protocol/MILESTONE-2026-06-29-PS2-AREA-SELECT-RENDERS.md`; pre-fix `tests/results/ps2.pcap`; 5 code-aware reviewers `PS2-REVIEW-{31dd79b,b66b21d,1772355,ca3ffa1,4d38024}.md` (unanimous).
- **Known next problem (NOT a regression):** 840 connection error at ~57s — this base has no phase-3 keepalive, so the SN@P session times out. Keepalive (inbound op 0x40 refresh) is the next fix. Render first (done), 840 next.
- Milestone 4: run a beta with users from around Europe.
- Milestone 5: production operation.

## Existing Workspace

- Active server launcher is `C:\dnas\active\server\start_all.js`.
- The launcher starts DNS `:53`, DNAS `:443`, HTTP `:80`, SN@P TCP `:10127`, and UDP game server `:9090`.
- The observed local Node.js version is `v24.15.0`.
- No `package.json` or lockfile was found at `C:\dnas\active` or `C:\dnas\active\server` during inventory.
- Server files are under `C:\dnas\active\server\*.js`.
- Active server stack is under `C:\dnas\active\server`.
- Pure JavaScript Blowfish implementation is `C:\dnas\active\server\blowfish.js`.
- PINE tools are under `C:\dnas\active\tools`.
- Project tools written during prior work are under `C:\dnas\active\tools`.
- Ghidra scripts are under `C:\dnas\active\ghidra_scripts`.
- Reference work is under `C:\dnas\references`.
- ISO files are under `C:\dnas\iso`.
- The Japanese Resident Evil Outbreak server reference works, but uses KDDI middleware rather than SN@P.
- The Japanese server reference is useful for reference architecture only and must not be trusted as exact PAL/SN@P protocol behavior.
- Known PINE tools include `pine_client`, `auto_inspect`, `dump_snap_state`, `dump_at_addr`, and `dump_range`.
- Auto-inspect fires on REGISTER and is wired into `C:\dnas\active\server\game_udp_server.js`.
- PAL EE Ghidra project is `C:\dnas\active\ghidra_pal_ee`.
- Decompile dumps include:
  - `C:\dnas\active\ghidra_exports\udp9090_candidates.txt`
  - `C:\dnas\active\ghidra_exports\udp9090_recv.txt`
  - `C:\dnas\active\ghidra_exports\udp9090_callback.txt`
- Findings docs include:
  - `C:\dnas\active\captures\udp9090_findings.md`
  - `C:\dnas\active\captures\udp9090_followup.md`
  - `C:\dnas\active\captures\netaq_findings.md`

## Claude Memory Entries To Preserve

- `project_udp9090_protocol.md`: UDP 9090 / SN@P REGISTER protocol facts.
- `project_snap_frame_format.md`: 8-byte frame layout; bytes 0-1 are payload length big-endian, byte 6 is error flag.
- `project_pine_injector_root_cause.md`: why PINE was needed and how to remove dependency.
- `feedback_research_before_fix.md`: verify decompile assumptions before pushing code changes.
- `feedback_username_is_handle.md`: PAL has no separate handle prompt.
- `feedback_continuous_server.md`: do not restart between attempts.
- `project_re_outbreak_pal_server.md`: 36-handler parallel-array matcher table.

## Verified Protocol Findings From Handoff

- First-ever login runs the full HTTP browser flow, writes a handle to the memory card, then uses SN@P/UDP for session.
- Subsequent boots with memory card skip HTTP, use the cached handle, prompt for password locally, and send handle/password over UDP `9090`.
- UDP `9090` is both session bind and credential check in one packet.
- In the private-server model, the password typed locally arrives at UDP `9090`; the server validates it against `accounts.json`.
- The server response encodes accept/reject and next-port assignment.
- The current HTTP server path uses a PINE injection to make the game go online.
- The current PINE injection writes or supplies handle/login-name information so the game unlocks/proceeds.
- The current PINE injection writes handle buffer `0x870870` and flags at `0x00701F30`, `0x00701F28`, `0x00029F280`, and `0x0035A279`.
- Production cannot depend on PINE injection because original hardware must work with DNS-only client configuration.
- PAL UI error `840` means could not connect / timeout.
- PAL UI error `d909` means could not transmit/receive after `840`.
- The `Invalid password` UI is fired by slot-`0x1c` callback when `FUN_001d9678` `strcmp` fails with errcode `0x13`.

## Latest Test Facts

- The latest user test produced a black screen/crash after pressing Enter.
- After that failed attempt, `node C:\dnas\active\tools\dump_range.js 0x36dc0c 0x20` returned all zero bytes.
- Address `0x36dc0c` corresponds to the state area described in the handoff as `state+0x4ac`, the `strcmp` target.

## Hashes

- `C:\dnas\iso\extracted\outbreak2\SLES_533.19` SHA256: `282F774BD0D89790DDFA81D0C6948594ADA56BFABE10D4BAA4F30A25DA33F9F1`.
- `C:\dnas\iso\extracted\outbreak2\BIN\9.DAT` SHA256: `BA103DA5C60D91C6F7F623D239489C7C07C0B728FEF75C653BB9322687951DAC`.
- `C:\dnas\active\server\game_udp_server.js` SHA256 at inventory time: `2FAC26C62316EE37570598C0BE5BBF6719D46127758B9A906B24052C1AC06AF9`.
- `C:\dnas\active\server\http_server.js` SHA256 at inventory time: `2B29BF0897F8E93FFCFB38687F41A3D8D0D9D5D5F290688C71DE699396A9180F`.
- `C:\dnas\active\server\blowfish.js` SHA256 at inventory time: `B57A81C7CE6DA74221023540EC73DC705903CB95A3683D361293AFE78996FAF1`.
- After the 2026-05-17 Codex UDP REGISTER-OK patch, `C:\dnas\active\server\game_udp_server.js` SHA256 is `70FA1E4B2878D5B1355250A17FF0593F246C0DA7DD8B47D3CE1929C2824F02BD`.
- After the 2026-05-17 Codex UDP REGISTER-OK handle echo patch, `C:\dnas\active\server\game_udp_server.js` SHA256 is `43F3A8228A96E702586C0BC0D12E10F44871EBCC16DE53FDCA9257C4C28E5013`.
- After the 2026-05-17 Codex UDP Blowfish direction patch, `C:\dnas\active\server\game_udp_server.js` SHA256 is `F03EC3D9E3FB42F5D30C651F144C84C73CC4C54C338378DDA0BFF3278CB9BF8A`.
- After rolling back the Blowfish direction experiment, `C:\dnas\active\server\game_udp_server.js` SHA256 is `9F000F383811442179EFD67628B7294F0733F851EF269364715F7E9F6DCB9752`.
- User PINE dump of inferred `state+0x484` at `0x36dbe4` showed `12345678` followed by zeros, proving the REGISTER-OK Blowfish key buffer is the first 8 password bytes for the `12345` test account.
- User PINE dump of inferred `state+0x4ac` region showed `12345`, proving the REGISTER-OK plaintext must start with the handle for the `12345` test account.
- After the 2026-05-17 key source patch, `C:\dnas\active\server\game_udp_server.js` SHA256 is `97C22673EA05501DA2E05462004BA83473663E284A284134CF883963CE782E98`.
- After the 2026-05-17 wire cipher byte-order patch, `C:\dnas\active\server\game_udp_server.js` SHA256 is `6FD41A1EAADFA3991B210690E389EE0F29BA5A443584E43F2FB7D45F62218DBF`.
- After the 2026-05-17 REGISTER-OK body wire offset patch, `C:\dnas\active\server\game_udp_server.js` SHA256 is `41B286BFFFDF9154300502274E447CE67A18E7DB7867A8375855A17223D3F387`.
- In `FUN_001d9678`, decompile pointer `param_2 + 0x3c` maps to captured wire offset `0x10` when `param_2 + 0x2c` maps to the wire length field at offset `0x00`.
- After rolling back the body wire offset experiment and adding REGISTER-OK variant controls, `C:\dnas\active\server\game_udp_server.js` SHA256 is `54D801533493D63333400849F6669E8C404316F46CEFE996DA41F883C26A2A91`.
- The body wire offset experiment removed the wrong-password UI but did not set inferred `state+0x80` to `2`, so it is not confirmed as authentication success.
- Codex read-only probe observed `state+0x484 = "1234567890"` and `state+0x4ac = "12345"` with inferred state base `0x36d760`.
- `FUN_001d9678` uses `strlen(state+0x484)` for the Blowfish key length, so REGISTER-OK key length is the full non-NUL password string length, not a fixed 8 bytes.
- After the REGISTER-OK default key length correction, `C:\dnas\active\server\game_udp_server.js` SHA256 is `E8E4051B4724FC004BB88D5AA5A579A98FC972E2E967ADC7454349AE261F765C`.
- `FUN_001d72a8` receives raw UDP bytes into `packet+0x2c`, validates a four-byte trailer, subtracts four from the received length, then sets the internal packet length with `FUN_001ebcd0`.
- `FUN_001d6988` can split the stripped receive datagram into inner SN@P chunks and queue fresh packet objects at `state+0x68`.
- `FUN_001d9678` decrypts REGISTER-OK from `packet+0x3c` with decrypt length `(*(u16 *)(packet+0x2c) & 0x3ff) - 0x10`.
- Claude's latest test proved REGISTER auth succeeds: `state+0x500` contains the server IP from REGISTER-OK plaintext and `state+0x80` advanced to `3`.
- The first post-REGISTER client packet is `kind 0x31`, opcode `0x0001`, 330 bytes, low length `0x146`.
- The `kind 0x31` / opcode `0x01` packet matches EE sender `FUN_001d6ee0`, which copies body bytes from `state+0x84` and finalizes with flags `0x3000`, opcode `1`.
- `FUN_001d6ee0` does not arm a `FUN_001d4d24` callback, so the first server response to test is a transport ACK, not an application-level encrypted reply.
- Claude's 20-byte transport ACK for post-REGISTER opcode `0x01` was accepted; the client did not retransmit the packet.
- After that ACK, the client stayed silent for roughly 120 seconds with `state+0x80 == 3`.
- `FUN_001d7104 @ 0x001d7104` is the SN@P state pump that reads `state+0x80`.
- `FUN_001d7104` advances `state+0x80` from `2` to `3` by calling `FUN_001d6ee0`; when already in state `3`, it only checks for timeout and calls `FUN_001d94b0`.
- The state-3 wait must be satisfied by a normal inbound dispatcher packet through `FUN_001d9f78`, not by another reply to opcode `0x01`.
- Initial callback registration in `FUN_001cadc0` installs slots `0x12`, `0x14`, `0x13`, and `0x15`.
- The initial callback slots `0x12` and `0x14` point to `0x1cac70` and `0x1cad10`; both copy inbound data into the buffer starting at `0x36a900`.
- The initial callback slots `0x13` and `0x15` point to no-op stub `0x1cadb0`.
- Claude's live state-3 callback table showed slots `0x12` and `0x14` were not registered in the current blocked state.
- Claude's live state-3 callback table showed slot `0x19` was the only live entry in the relevant range, pointing to `0x00626730`.
- `FUN_001ddee8 @ 0x001ddee8` registers callback slot `0x19` by calling `FUN_001d4d24(1, 0x19, param_3)`.
- `FUN_001ddee8` sends actual opcode `0x0a` with flags `0xb000` and a four-byte body before registering slot `0x19`.
- `FUN_001d9f78` routes actual opcode `0x0a` with header flag `0x1000` set to callback slot `0x19` at `state+0x5ac`.
- `FUN_001d9f78` routes actual opcode `0x0a` without header flag `0x1000` to callback slot `0x18` at `state+0x5a8`.
- Static Ghidra projects for `SLES_533.19` and imported `NTGUI.ELF` do not contain initialized bytes or a function at `0x00626730`.
- Runtime dump `captures/runtime_0x626000_4k.bin` is 4096 bytes with SHA256 `E10DC8235D775CD73510B4CD309ADD6356885242801599388EABE6D4595E0571`.
- Runtime callback `0x00626730` increments byte `0x007152e1` and returns when dispatcher metadata byte `arg0[0]` is `0`.
- Runtime callback `0x00626730` enters an error/status path when dispatcher metadata byte `arg0[0]` is `0x27`; that path reads `u32` at body offset `+4`.
- `FUN_001d8848` parses opcode `0x0a` body before slot `0x19` callback and loops on the count at body offset `+8`.
- Claude confirmed an actual opcode `0x0a` / flags `0xb000` / 12-zero-byte body server push reaches the EE, is transport-ACKed by the game, and fires slot `0x19`.
- After the confirmed slot-`0x19` push, Claude observed `0x007152e1 = 0x02` and `0x0087f7e0 = 0x00`.
- Runtime function `0x00626900` switches on `0x007152e1` through jump table `0x006943c0`.
- Runtime code `0x00626a70..0x00626b14` builds the SN@P login/session parameters, passes callback `0x00626730`, and calls `FUN_001db7e8`.
- Runtime function `0x00626e70` branches on `0x007152e1`; value `2` branches to `0x00627040`.
- Address `0x00627040` is outside the current `captures/runtime_0x626000_4k.bin` dump.
- `FUN_001db7e8` writes `state+0x8c = bswap32(param_10)`, so observed `state+0x8f = 0x01` is likely byte 3 of that staged 32-bit field rather than a standalone progression flag.
- User live dump confirmed `DAT_0025b78c = 0x0036d760`.
- With state base `0x0036d760`, callback table base is `0x0036dca8`.
- A callback pointer at `0x0036dd18` is `state+0x5b8`, slot `0x1c`.
- `FUN_001d4d24(1, 0x1c, param_11)` is present in the larger REGISTER/session setup path.
- `FUN_001d4d24(1, 0x19, param_3)` is present in `FUN_001ddee8`, paired with a local send of actual opcode `0x0a`.
- Plain actual opcode `0x0a` with flag `0x1000` routes to `state+0x5ac`, slot `0x19`, not to current slot `0x1c`.
- Slot `0x1c` at `state+0x5b8` is reached by the selector-family dispatcher path, most directly actual opcode `0x28` with parsed selector `1`.
- Runtime branch `0x00627040` first calls helper `0x0061e910`; if that helper returns nonzero, the branch exits without incrementing `0x007152e1` past `2`.
- If helper `0x0061e910` returns zero, branch `0x00627040` calls `0x0061f0e0`, optionally copies a 4KB-ish buffer from pointer `0x00365dcc` into `0x0086f864`, increments `0x007152e1`, and sets `0x007152d0 = 1`.
- Later operand-scan/decompile corrected the runtime destination buffer from older `0x0087f864` notes to `0x0086f864` (`0x00870000 - 0x79c`).
- A separate server-select/chunked-list family populates `0x00365cf0`, `0x00365cf4`, `0x00365d34`, `0x00365db4`, and `0x00365db8`; runtime `FUN_00627540` navigates it using selected index `0x007152ea`.
- Focused 2026-05-26 Ghidra scan showed `FUN_001c2f80` can seed `0x00365cf0`, `0x00365d34[]`, and `0x00365cf4[]` from helper accessors `0x0061c8e0`, `0x0061c900`, and `0x0061c920`, so the visible server-select list may have a static/runtime source before network chunks are valid.
- Focused 2026-05-26 Ghidra scan verified the `0x2d`/`0x2f` chunk path: `0x2d` fills `0x00365d74[]` and `0x00365cf4[]`, while `0x2f` requests chunks with key `0x00365d74[index]`, offset `0x00365db8`, and chunk size `0x02d2`.
- Claude's seven-snapshot timeline proved slot `0x19` stays NULL from PRE-PUSH through T+2s; it is not transiently registered in the current test.
- Claude's seven-snapshot timeline proved slot `0x1c` stays populated with `0x00626730` throughout the current post-bind wait.
- The current opcode `0x0a` push no-ops at dispatcher slot lookup in the current state because it routes to NULL slot `0x19`.
- Parser `FUN_001d7f6c` byte-swaps only the first two 32-bit words of the opcode `0x28` selector body.
- A slot-`0x1c` test push should use actual opcode `0x28`, body bytes `00 00 00 01 00 00 00 00`, and first bytes `b0 18 00 28` under the current server-push wire convention.
- Runtime helper `0x0061e910` calls `FUN_001b3d90`, stores the full return at `0x00715268`, and returns the low signed byte from `0x00715268`.
- Claude confirmed the actual opcode `0x28` / selector `1` slot-`0x1c` push clears the UDP `9090` state-3 plateau and advances the game to the in-game lobby UI.
- After the successful slot-`0x1c` transition, `DAT_0025b78c` is nulled, SN@P callback table memory is zeroed, and the game opens TCP connection to port `10127`.
- After the successful slot-`0x1c` transition, the game sends an extra UDP `9090` application ACK packet: `b0 10 00 02 02 64 07 d0 00 00 00 00 00 00 00 00 ba 47 66 11`.
- After IN #5 suppression, `C:\dnas\active\server\game_udp_server.js` SHA256 is `73ED0C81E8D4A1573E031BE2E0531F46830A68C6195C94E7165F782208E424EB`.
- Claude Update #11 captured the first TCP `10127` lobby frame: 57 bytes, payload length `0x0031`, direction `0x01`, command `0x1007`, `err=0`, `p7=0xff`.
- Three TCP `10127` cmd `0x1007` retries were captured with `p5` values `0xcf`, `0xd0`, and `0xd1`.
- `FUN_001c4100 @ 0x001c4100` builds and sends the client-side TCP `10127` cmd `0x1007` packet.
- `FUN_001c9030 @ 0x001c9030` handles server reply `02 10 07`.
- Cmd `0x1007` client payload bytes `5..48` decode with `plain[i] = encoded[i] ^ ((p5 + i - 5) & 0xff)`.
- The decoded cmd `0x1007` tail is stable across all three captured retries: `06 05 2f 71 17 26 2c 19 7b 04 19 02 7e 08 0b 2f 1b 10 2c 36 7f 21 79 71 39 79 03 32 00 27 09 7d 17 7d 01 2c 3a 27 27 11 7e 33 2d 7c`.
- `FUN_001c9030` treats reply `err=0xff` as an error path.
- `FUN_001c9030` moves the lobby state to `0x29` when the first reply payload byte is `0x00`.
- The minimal statically supported reply to inbound `01 10 07` is `00 01 02 10 07 <same-p5> 00 <same-p7> 00`.
- Codex added `scripts/tools/codex/analyze_cmd1007_payloads.js` and copied it to `C:\dnas\active\tools\codex\analyze_cmd1007_payloads.js`.
- Codex added `scripts/ghidra/codex/DecompileCmd1007.java` and copied it to `C:\dnas\active\ghidra_scripts\codex\DecompileCmd1007.java`; the first headless run was blocked by a Ghidra project lock.
- Claude Update #13 confirmed the minimal TCP `10127` cmd `0x1007` reply `00 01 02 10 07 <p5> 00 <p7> 00` was accepted.
- After `0x1007`, the game sent TCP `10127` cmd `0x6103` CHECKVERSION and accepted the existing version reply.
- The next TCP `10127` blocker is inbound cmd `0x6212` with zero-byte payload.
- The PAL EE handler for server reply `02 62 12` is `FUN_001c4360 @ 0x001c4360`.
- Bio-Serv names `0x6212` as `AGLPLAYERCNT`, the number of players in the aftergame lobby.
- PAL `FUN_001c4360` reads one big-endian `u32` payload value with `FUN_001c3b10()` and then sets lobby state byte `+0xd` to `0x10`.
- The recommended first TCP `10127` reply for inbound `0x6212` is `00 04 02 62 12 <p5> 00 <p7> 00 00 00 01`.
- The likely next command after `0x6212` is `0x6213` / `AGLSTATS`.
- PAL `FUN_001c4450 @ 0x001c4450` handles server reply `02 62 13`, reads eight big-endian `u16` values, and then sets lobby state byte `+0xd` to `4`.
- Claude Update #14 confirmed the `0x6212` reply with big-endian `u32` value `1` was accepted.
- After `0x6212`, the live PAL command sequence sent `0x6203` AREACOUNT, not `0x6213`.
- The captured `0x6203` request was `00 04 01 62 03 d2 00 ff 00 02 52 d2`.
- The existing Bio-Serv-era `0x6203` reply `00 04 02 62 03 00 00 00 00 00 00 02` caused an immediate FIN and UI bounce back to Go Online.
- The PAL EE handler for server reply `02 62 03` is `FUN_001c4960 @ 0x001c4960`.
- PAL `FUN_001c4960` reads a one-byte mode first; mode `0x00` is an error/reset branch, mode `0x02` advances lobby state byte `+0xd` to `0x14`, and mode `0x01` enters a larger area-list/cache branch.
- The recommended first TCP `10127` reply for inbound `0x6203` is `00 01 02 62 03 <p5> 00 <p7> 02`.
- Claude Update #15 confirmed the PAL `0x6203` mode-`0x02` reply was accepted and the UI loading bar advanced from 5% to 9%.
- After `0x6203`, the next TCP `10127` blocker is inbound cmd `0x6211` with zero-byte payload.
- The captured `0x6211` request was `00 00 01 62 11 2d 00 ff`.
- The PAL EE handler for server reply `02 62 11` is `FUN_001c45f0 @ 0x001c45f0`.
- Bio-Serv names `0x6211` as `LEAVEAGL`, but PAL is using it in the current boot-lobby progression after `AREACOUNT`, so the name is only loose reference.
- PAL `FUN_001c45f0` reads one big-endian `u32` payload value with `FUN_001c3b10()` unless `err=0xff`, then stores the value at `uRam0036847c`.
- PAL `FUN_001c45f0` sets lobby state byte `+0xd` based on major mode: modes `0`, `1`, and `7` set `0x0e`; mode `2` sets `0x2d`; all other modes set `0x31`.
- The recommended first TCP `10127` reply for inbound `0x6211` is `00 04 02 62 11 <p5> 00 <p7> 00 00 00 00`.
- Claude Update #16 confirmed the `0x6211` reply with big-endian `u32` value `0` was accepted.
- Claude Update #16 confirmed the pre-staged `0x6213` AGLSTATS reply with eight big-endian `u16` zero values was accepted.
- After `0x6213`, the next TCP `10127` blocker is inbound cmd `0x6501` with four-byte payload `00 00 00 00`.
- The captured `0x6501` request was `00 04 01 65 01 d5 00 ff 00 00 00 00`.
- The PAL EE handler for server reply `02 65 01` is `FUN_001c6e80 @ 0x001c6e80`.
- PAL export labels `0x6501` as `lobby header`; Bio-Serv names it `CANCELSLOT`, but the Bio-Serv name is only loose reference for PAL initial lobby population.
- PAL `FUN_001c6e80` reads a one-byte mode first.
- PAL `FUN_001c6e80` mode `0x00` is a clean non-error empty/no-entry path and sets lobby state byte `+0xd` to `0x08` or `0x0c` depending on major mode.
- PAL `FUN_001c6e80` mode `0x01` reads two big-endian `u32` values and sets lobby state byte `+0xd` to `0x06`.
- The recommended first TCP `10127` reply for inbound `0x6501` is `00 01 02 65 01 <p5> 00 <p7> 00`.
- Claude Update #17 confirmed the `0x6501` mode-`0x00` reply was accepted.
- After `0x6501`, the next TCP `10127` blocker is inbound cmd `0x6502` with eight-byte payload `00 00 00 00 00 02 56 d6`.
- The captured `0x6502` request was `00 08 01 65 02 d6 00 ff 00 00 00 00 00 02 56 d6`.
- The PAL EE handler for server reply `02 65 02` is `FUN_001c7680 @ 0x001c7680`.
- PAL export labels `0x6502` as `lobby slot`; Bio-Serv names it `LEAVESLOT`, but the Bio-Serv name is only loose reference for PAL initial lobby population.
- PAL `FUN_001c7680` reads a one-byte mode first on non-error replies.
- PAL `FUN_001c7680` mode `0x00` is a clean empty/no-slot-entry branch; it either loops to state byte `+0xd = 0x08` for another slot index or completes the empty slot path at state byte `+0xd = 0x0c`.
- PAL `FUN_001c7680` mode `0x01` reads two big-endian `u32` values and sets lobby state byte `+0xd` to `0x0a`.
- The recommended first TCP `10127` reply for inbound `0x6502` is `00 01 02 65 02 <p5> 00 <p7> 00`.
- The client-side token pattern observed in `0x6203` and `0x6502` requests is empirically `[0x00, 0x02, p5 & 0x7f, p5]`; this is not yet statically confirmed from the EE ask-side builder.
- Claude Update #18 confirmed the `0x6502` mode-`0x00` reply was accepted.
- After `0x6502`, the next TCP `10127` blocker is inbound cmd `0x6510` with five-byte payload `00 00 02 57 d7`.
- The captured `0x6510` request was `00 05 01 65 10 d7 00 ff 00 00 02 57 d7`.
- The PAL EE handler for server reply `02 65 10` is `FUN_001c8790 @ 0x001c8790`.
- PAL `FUN_001c8790` reads a one-byte count first; if that count equals `uRam00365e1a`, it then reads that many big-endian `u16` values.
- PAL `FUN_001c8790` always reads a fixed `0x3e` byte string after the count and optional `u16` values.
- The recommended first TCP `10127` reply for inbound `0x6510` is `00 3f 02 65 10 <p5> 00 <p7>` plus payload `00` followed by `0x3e` zero bytes.
- The `0x6510` request token again matches `[0x00, 0x02, p5 & 0x7f, p5]`; the `02 65 10` reply handler does not read or echo that token.
- Claude Update #19 confirmed the `0x6510` count-`0` plus `0x3e` zero-byte reply was TCP-ACKed and advanced the UI from 13% to 14%, then the game closed the TCP connection about 75 ms later with error `d901`.
- The post-`0x6510` fast FIN is different from earlier blockers: the game did not wait for a missing reply, so the packet was structurally accepted but likely drove a bad or terminal lobby state.
- If `current_entry+0x365f78` is zero, `FUN_001c8790` with count `0` can complete the empty list path and drive state byte `+0xd` to `0x31`.
- The current empty path likely leaves `current_entry+0x365f78 == 0`; changing only the `0x6510` count is unlikely to fix the fast FIN.
- The recommended next branch test is `0x6502` mode `0x01` with two zero big-endian `u32` values to drive state byte `+0xd = 0x0a`, likely exposing `0x6504`.
- PAL `FUN_001c7a70` handles server reply `02 65 04` and can set `current_entry+0x365f78` to a nonzero slot count.
- The recommended first `0x6504` reply, if requested, is a one-slot minimal payload with length `0x132`.
- If `0x6510` is requested after a one-slot `0x6504`, the recommended reply is count `0x08`, one zero big-endian `u16`, and `0x3e` zero bytes: payload length `0x41`.
- Claude Update #20 confirmed `0x6502` mode `0x01` worked and exposed cmd `0x6504`; UI advanced from 14% to 16%.
- The captured `0x6504` request was `00 08 01 65 04 31 00 ff 00 00 00 08 00 02 31 31`.
- The `0x6504` request payload is a big-endian requested window/capacity `8` plus token `[00, 02, p5 & 0x7f, p5]`; it does not force the reply to contain eight slot-detail records.
- The `0x6504` reply payload header is `u16 total_slot_count`, `u16 batch_start_or_offset`, `u8 batch_count`.
- Each `0x6504` slot-detail record is `0x12d` wire bytes: `0x0f + 0x0f + 0x08 + 0xff + u16 + u16 + u32`.
- The minimum non-rejected `0x6504` reply should use `total_slot_count=1`, `batch_start_or_offset=0`, `batch_count=1`, then one zero-filled `0x12d` byte slot-detail record.
- Claude Update #21 confirmed the `0x6504 total_slot_count=1,batch_count=1` all-zero record was ACKed but caused a fast FIN about 76 ms later; UI stayed at 16% and the client did not ask `0x6510`.
- In `FUN_001c7a70`, `total_slot_count=1,batch_count=1` completes the current `0x6504` list immediately because `uRam00365e18` becomes equal to `current_entry.slot_count_365f78`.
- In `FUN_001c7a70`, `total_slot_count=0` takes an explicit reset/error-style branch and is unlikely to be a progress path.
- The recommended next `0x6504` diagnostic is `total_slot_count=8,batch_start_or_offset=0,batch_count=1` with one structurally valid slot record, to keep `state+0xd=0x0a` after the reply.
- Claude Update #22 confirmed `0x6504 total_slot_count=8,batch_count=1` with one all-zero `0x12d` record was ACKed but caused the same fast FIN about 74 ms later; UI stayed at 16%.
- `FUN_001c7a70` re-check confirms the `0x6504` record wire size is exactly `0x12d`; the client-side memory stride is `0x134`, so the difference is in-memory padding/alignment.
- `FUN_001c7a70` does not show a direct slot-content validation gate such as a required non-empty string, nonzero slot ID, nonzero status field, or long-text requirement.
- The next `0x6504` diagnostic should capture pre/post memory state around `0x365ac0`, `0x365e00`, `0x3619d0`, and `0x35ccd0` to prove whether the slot-detail record is stored and which branch follows.
- User test on 2026-05-18 confirmed `0x6504 total_slot_count=1,batch_count=1` with non-empty fields `SLOT0001`, `OPEN`, `Test Slot`, and trailing values `1/1/1` still fast-FINs at about 65-75 ms and UI stays at 16%.
- The current `0x6504` failure is therefore unlikely to be caused only by all-zero slot content.
- The current working hypothesis is that `0x6501 mode=0` skipped required lobby header/list population before the later forced `0x6502 mode=1` / `0x6504` slot-detail path.
- `FUN_001c70b0 @ 0x001c70b0` handles server reply `02 65 03`; it reads `u16 total_header_count`, `u16 batch_start_or_offset`, `u8 batch_count`, then `batch_count` records of `0x154` wire bytes.
- User has had a UniFi DNS override in place since early in the project, not newly added: `snap01.capcom.client.sf.yav4.com` Host A -> `192.0.2.196`, Auto TTL. If the game still hits Winsock `10049`, likely causes include the game/emulator not using UniFi/router DNS, a cached/alternate DNS answer, or the queried name differing from this exact hostname.
- `FUN_001c7a70` only decodes and stores `0x6504` slot-detail fields; it does not visibly resolve `field_a`, parse it as a hostname, or initiate the post-lobby DNS/UDP path.
- Current best interpretation is that `0x6504 field_a` is a slot/server id string such as `SLOT0001`, while `field_e/f` are endpoint-looking stored values when set to UDP port `0x2382` and the sanitized IPv4 `0xc00002c4`.
- The post-lobby DNS lookup is better explained by the separate initialized host global `0x35bee0 = "snap01.capcom.client.sf.yav4.com"` and the UDP path that targets port `0x2382`, not by `field_a`.
- After the accepted full lobby walk and accepted slim refresh, the next protocol blocker is the post-lobby `snap01`/UDP `9090` service or its response semantics, not another `0x6504` slot text/content variant.
- The 570-byte post-lobby UDP `9090` packet `32 36 00 01 ...` is another `FUN_001d6ee0` reliable opcode `0x0001` send, not a REGISTER variant and not visibly encrypted menu-data.
- For the 570-byte post-lobby packet, `0x3236` means the same `0x3000` reliable family with inner length `0x236`; body+tail length is `0x226`, copied state body length is `0x218`, and the LC/MR tail is `00 02 4d 52 00 00 00 30 4c 43 00 00 06 40`.
- The byte at raw offset `0x17` in the 570-byte packet is the visible bswapped `state+0x88 = 0xf0` length seed, not a session/resume token.
- The recommended first response to the 570-byte post-lobby opcode `0x0001` packet is the same 20-byte transport ACK shape as post-register-bind: `60 10 00 00 + inbound[0x04..0x0f] + ba 47 66 11`.
- User test confirmed the 20-byte ACK for the 570-byte post-lobby opcode `0x0001` packet is accepted, but the game cycles back to REGISTER about 4-5 seconds later with the menu still empty.
- After `FUN_001d6ee0` sends opcode `0x0001` and `state+0x80` becomes `3`, `FUN_001d7104` only checks timeout; it does not have a visible branch that advances when the ACK is received.
- The post-lobby retry after ACK is consistent with `state+0x7c + state+0x51c < state+0x4fc` calling `FUN_001d94b0`; the missing piece is likely a server-pushed application packet before that timeout, not an application body reply to opcode `0x0001`.
- `state+0x88 = 0xf0` controls the copied body length for `FUN_001d6ee0`; the retry timer is controlled separately by `state+0x51c = state+0x510 * 0x20 + 4000`.
- The post-570B slot1c push can advance the game to a new UDP `9090` reliable packet: `kind=0xf0`, inner length `0x42`, opcode `0x0048`, raw length `70`.
- The PAL sender for UDP `9090` opcode `0x48` is `FUN_001e094c @ 0x001e094c`; it registers callback slot `0x31`, which maps to `state+0x60c`.
- The apparent `NAMEDSLOT*` / `NAMEFSLOT*` strings in opcode `0x48` are actually `NAME` key entries with flag bytes `0x44` (`D`) and `0x46` (`F`), each carrying a 16-byte string value such as `SLOT000101`.
- Incoming opcode `0x48` application responses route through `FUN_001d8c10 @ 0x001d8c10`, then invoke callback slot `0x31` at `state+0x60c`.
- `FUN_001d8c10` expects a response body with a 12-byte header and `record_count` at body offset `+0x08`; each optional record is `0x24` bytes.
- User test confirmed the zero-count UDP `9090` opcode `0x48` application response `b0 1c 00 48 ... 00 00 00 0a 00 00 00 00 00 00 00 00` is accepted: the game ACKed it and stopped the 15-query retry loop.
- `FUN_001d81a4 @ 0x001d81a4` parses each opcode `0x48` response record as `0x24` fixed bytes: bytes `0x00..0x0f` untouched, then five big-endian `u32` words at offsets `0x10,0x14,0x18,0x1c,0x20`.
- The recommended next UDP `9090` opcode `0x48` test is a one-record response with `b0 40 00 48`, body header `request_id=10,status=0,record_count=1`, 16-byte id `SLOT0001`, `word0=1`, and remaining words zero.
- User test confirmed a two-record opcode `0x48` response echoing queried ids `SLOT000101` and `SLOT000110`, each with `word0=1` and remaining words zero, is accepted and ACKed by the game without retry.
- Because accepted opcode `0x48` responses still leave no visible menu entries, `word0..word4` semantics must be determined from the actual named-slot-query reply consumer, not from `FUN_001d81a4` alone.
- Static/runtime-code-page disassembly of `0x005bc990` is valid: if invoked with normal metadata, it reads opcode `0x48` response `record_count` at body offset `+0x08`, sums `lhu(record+0x10)` across `0x24`-byte records into `0x0087f7f8`, then compares that sum against `FUN_005c5060(lhu(0x0087f800))`.
- Timed named-slot-query snapshot `namedslotq_192_0_2_196_2000_1779205038328.log` (sanitized filename) disproves the prior runtime inference that `0x005bc990` consumes the tested `word0=5+5` reply: `0x0087f7f8` never accumulates the reply records, and `state+0x60c` is not `0x005bc990` at the reply-consumption moment.
- At PRE-PUSH in that named-slot-query snapshot, `state+0x60c = 0x00374fa0`, which dereferences to data containing endpoint/session-looking bytes, not executable code.
- `0x0087f800` is not a stable threshold during the named-slot-query window; at PRE-PUSH it contains transient endpoint-looking data including port `0x07d0` and the start of an IP string, then clears to zero after the reply.
- `state+0x60c` is reused across protocol phases: in the named-slot-query window it is a data pointer or cleared/garbage value, while `0x005bc990` only reappears later at `T+5000ms`.
- Runtime function `0x005bca90` is still a relevant opcode `0x48` query builder: it constructs `NAME` entries with flag bytes `D` and `F`, clears `0x0087f7f8`, passes selector/target `0x0a`, and can register callback `0x005bc990`; however, the latest timed snapshot shows this is not the active consumer for the tested named-slot-query reply.

## Open Questions

- Did the latest black screen indicate a server-side response format error, emulator/client crash, or a newly reached protocol stage?
- Is the current Blowfish key schedule using the correct endianness and key length?
- What exact packet fields must be encrypted for the REGISTER response body?
- What exact inner packet length and encrypted REGISTER-OK body length does the PAL client expect?
- What exact server-push packet in the opcode `0x0f` family should be sent while the client is in `state+0x80 == 3`?
- What does the runtime branch at `0x00627040` do when `0x007152e1 == 2`?
- What condition is helper `0x0061e910` checking, and why does it block the `0x007152e1 == 2` branch in Claude's latest run?
- What entries are in the runtime jump table at `0x006943c0`?
- Are new callback slots registered after slot `0x19` increments `0x007152e1`?
- Does a minimal `02 10 07` reply with one-byte payload `00` advance the game from "loading 5%" to the next lobby protocol stage?
- What does lobby state `0x14` send or expect after cmd `0x6203` succeeds with payload mode `0x02`?
- What exact semantic fields are contained in cmd `0x1007` payload bytes `0..4` and in the decoded 44-byte tail?
- What payload belongs in the `0x36a900` buffer, and how does the app decide this initial copied data transfer is complete?
- How does the PAL game normally receive, store, validate, and reuse the login name / handle during the HTTP flow?
- What server-side HTTP response or state is missing that currently requires PINE handle injection?

## Current Model — Select→Connect / 840 (2026-06-21)

State-based snapshot (see docs/findings/protocol/SESSION-LOG-2026-06-21.md for the test trail).

### Confirmed (evidence cited)
- The 840/820/839/837 displayed error = `event.f4 + 820 (0x334)`, computed in connect-SM callback
  `FUN_00626730` (overlay 0x626730). `event.f4` = byteswap(establish-push payload[2]). Evidence:
  overlay disasm + runtime (f4=0/0x11/0x13 → 820/837/839). Conf: High.
- Connect-SM success = `cs_result (0x86f7e0) == 1`, set ONLY by `FUN_00626730`'s conn-table-match branch
  (`conn_table 0x365bb0` entry.f4 == event.f4 == 0x13). Evidence: disasm + SM decision at 0x626c5c. Conf: High.
- `conn_table 0x365bb0` is never populated in our flow (PINE: count stays 0); no EE overlay/ELF code
  writes it except the SM's own init/clear. Population is connect-SM/IOP-internal. Conf: High.
- SN@P UDP transport works: in-order delivery via shared seq counter (`SNAP_ROOM_SEQ_ADVANCE`, commit
  823b168) and f0/op2 reliable-control ACK (reply 0x60, seqB=game seqA; commit 76f2e3a). Evidence:
  wire + journal (game stops retransmitting, ACKs in order). Conf: High.
- op 0x27 establish-push (body0=0) is a dispatcher no-op; op 0x31 is the real establish (calls
  `FUN_001dbd0c` → sends 0xb000 accept + connect-SM callback). Evidence: FUN_001d9f78 disasm. Conf: High.
- `FUN_001d46ec` (ELF) = sceSnap conn allocator: malloc(0x624), UDP socket bind:2000, "SNAP-SWAN" magic,
  DAT_0025b78c = conn (PINE snap_conn_ptr). Conf: High.

### Rejected hypotheses (do not retry)
- "Tuning establish-push f4 advances the connect." REJECTED — f4 is display-only (error = f4+820). Conf: High.
- "op 0x31 establish-push is net progress." REJECTED — it triggers the connect-SM callback prematurely
  (empty conn-table → error 839) BEFORE render; baseline (no push) reaches the black-screen render →
  840, which is further. The establish-push is a detour. Conf: High (run 2026-06-21_13-26-52).
- "Synthesizing a conn-table entry via PINE poke yields cs_result=1." INCONCLUSIVE/RACE — SM zeroes the
  count at connect-init; a 25ms external poke loses the race (cs_result stayed 0). Conf: Med.

### Open questions
- What populates `conn_table 0x365bb0` with an established entry (connect-SM/IOP path)?
- Why does the baseline (no establish-push) black-screen path 840 at the render/connect stage?

### Current baseline vs delta
- Baseline (SNAP_ROOM_ENTER_PUSH=0): lobby → select → black screen → 840 (furthest-reaching).
- Delta to KEEP: seq-advance + f0/op2 ACK (transport fixes). Delta to DROP: op 0x31 + f4 (detour).

### Update 2026-06-21 PM (T11–T13)
- CONFIRMED: with establish-push OFF, BOTH selections → black-screen→840 (clean repeatable baseline).
  cs_result stays 0; conn_table_cnt stays 0; conn alloc→free ~58s (300-tick timeout). The connect-SM
  runs a retry loop and never receives an establishment event. (T11, run 18-51-29.)
- CONFIRMED: cs_result=1 is written ONLY inside callback FUN_00626730 (0x6267d8 match, 0x62683c
  post-loop), both gated on the a0==0x27 result-event with event.f4==0x13. In baseline that event never
  fires → cs_result can never reach 1. (T12.)
- CONFIRMED: cs_matchidx (0x7152ea) is a shared SM field (many writers) — its 1/2 values are NOT
  conn-table matches. conn-table-never-populated stands. (T12.)
- REJECTED (major): "conn-table 0x365bb0 is populated by EE code / triggerable purely via the existing
  EE select path." Exhaustive static search (Ghidra xref, register-tracked stores, offset-0xbb0 scan,
  ELF+overlays) finds NO EE writer. Inference: it is IOP-DMA-populated on connection establish. (T13.)
- OPEN: the cs_result=1 success condition is gated by the IOP network module marking the connection
  established (DMA into conn_table). EE-side select-connect code is exhausted. Next = IOP module RE.
- OPEN (contradiction): static says FUN_00626730 post-loop f4==0x13→cs_result=1, runtime says 839; runtime authoritative.

### Update 2026-06-21 late (T14–T15)
- CONFIRMED: game (NTGUI.ELF, holds SN@P FUN_001dxxxx) loads the Sony INET stack (INET/INETCTL/SMAP/DEV9);
  AVE stack unused. SN@P reliable transport = EE over INET UDP. (T14.)
- REJECTED (major): "conn_table 0x365bb0 is written transiently by EE during connect." A read-only tight
  poll (~5500 reads/s, 1.66M reads over the full connect) saw it NEVER non-zero; cs_result never non-zero;
  cs_substate only walked 0/1/2. Combined with T13 (no static writer): conn_table is NEVER populated in
  our flow. (T15, run 19-49-58.)
- CONSEQUENCE: conn_table-match route to cs_result=1 is DEAD here. Only other EE route is post-loop
  f4==0x13 (FUN_00626730 0x62683c) — static says it sets cs_result=1, but runtime (T7, op-0x31 f4=0x13)
  gave 839, NOT cs_result=1. Unresolved disasm-vs-runtime contradiction; runtime authoritative.
- NET: NO exercised path yields cs_result=1. The connect-SM never receives a result-event that sets it.
  The establishment that would set cs_result=1 is not triggered by anything we send or by EE-internal code.

### Update 2026-06-21 — CRUXES RESOLVED (T16/T17)
- CRUX #1 (Conf High, raw-byte disasm): FUN_00626730 with a0==0x27 AND f4==0x13 → cs_result=1 (SUCCESS),
  via post-loop (0x62683c) even with empty conn_table ($t0 zero-init confirmed @0x626788). f4==0x14 →
  +820 → matches baseline 840. conn_table is OPTIONAL, not required. This SUPERSEDES "conn_table match is
  the only success route."
- CRUX #2 (Conf High, decompile): the connect-SM result-event is ALWAYS packet-borne — inbound op-0x31
  (case 0x2e) → FUN_00626730 result branch with f4 = packet payload[2] (param_2+0x44). op-0x29 → progress
  (cs_substate++), not result. SUCCESS CONDITION = deliver inbound op-0x31 with f4==0x13 to the
  connect-SM conn (DAT_0025b78c) BEFORE its 300-tick (~58s) timeout. Baseline 840 = the SM's own timeout
  (FUN_00626900), a path SEPARATE from FUN_00626730 — no establishment packet arrives → cs_result stays 0.
- MODEL UPDATE: op 0x31 IS the correct establishment opcode (routes to the result branch). The earlier
  "detour" was wrong DELIVERY (T7 → 839), not a wrong opcode.
- RESIDUAL (runtime-only): T7 op-0x31 payload[2]=0x13 gave 839, but FUN_00626730 cannot output 839 for
  f4==0x13 (→cs_result=1 always; 0x11→817/0x13→812 special-cased, never 837/839). So 837/839 originate
  from a DIFFERENT error path, OR op-0x31 hit a conn whose +0x5b8 != FUN_00626730. Resolve by watching
  cs_result + the error global during one op-0x31 drive.

### Update 2026-06-21 — RESIDUAL RESOLVED (T18): slot-0x1c callback is multiplexed (timing)
- CONFIRMED (PINE timing correlation, Conf High): conn+0x5b8 (slot-0x1c callback) is MULTIPLEXED over the
  session. FUN_00626730 (connect-SM result handler) owns it ONLY briefly early in the connect (cs_substate
  ~2-4, first ~1.5s). Our op-0x31 establish-push fires AFTER the first cmd0c (~+24s), by which time
  conn+0x5b8 = 0x5bca90 (slot-0x1c room-query TX builder). So op-0x31 (case 0x2e DID run; f0/op2 fired)
  invoked the WRONG callback → no a0==0x27 result branch → cs_result never 1 → 839.
- This RECONCILES disasm vs runtime: FUN_00626730 f4=0x13→cs_result=1 is correct; we just never delivered
  the result-event while FUN_00626730 was the registered slot-0x1c callback.
- FIX HYPOTHESIS (untested): re-time the op-0x31 establish-push to fire during the connect-SM callback
  window (conn+0x5b8==0x626730, early connect), not after cmd0c. Then f4=0x13 should reach FUN_00626730
  → cs_result=1 → SM success @0x626c5c.
- Session success criteria met: identified a previously-unknown state transition (slot-0x1c callback
  multiplexing + the connect-SM ownership window) and the exact reason the establishment fails.

### Update 2026-06-21 — MAJOR CORRECTION (T20): two distinct connects; select-840 = 0x5bca90, not cs_result
- The connect-SM FUN_00626900/FUN_00626730 (cs_result=1, conn+0x5b8=0x626730) is the LOGIN lobby-connect
  (runs +0..1.1s). Its success is NOT required to reach server-select (baseline T15: cs_result=0 yet grid
  renders). T16-T19 proved cs_result=1 is achievable (re-timed op-0x31) but that is the LOGIN connect.
- The SELECT-840 is a DIFFERENT path: at server-select (+24s) conn+0x5b8 = 0x5bca90 (overlay slot-0x1c
  room-query state-driven TX builder), cs_result=0, and the cmd0c loop (who=0xe1/0xa1 cmd=0xc) times out
  → 840. Confirmed by PINE cb timeline (run 2026-06-21_20-43-35): login cb=0x626730, select cb=0x5bca90.
- THEREFORE the milestone (select→rendered room) hinges on the 0x5bca90 room-query/join path, NOT
  FUN_00626730/cs_result. Refocus RE on 0x5bca90 (selector *arg0: 0x00→op48 name-query cb 0x5bc990;
  0x27→cmd0c room-query via vtable 0x5bdf90 sel2, vtable 0x6caaa0). estab-on-bind is login-targeted = off.
- Keep: login renders server-select grid fine; seq-advance + f0/op2 ACK are still good transport fixes.

### Update 2026-06-22 — 0x5bca90 select-SM RE'd (static, Conf High); see SESSION-LOG-2026-06-22.md
- The select room SM is a vtable-driven state machine: `FUN_0x5bdf90(sel)` calls
  `(*(0x6ca8a0 + sel*4))(&{1,sel})`. States in use: {1,2,5,7,8,0xb,0x18,0x19,0x1a,0x1d,0x1e,0x29,0x2b}.
  sel 2 = error/UI display state.
- conn+0x5b8 slot-0x1c callback at select = `0x5bca90`, an EVENT handler on `*arg0`:
  `*arg0==0` → send op48 NAME query (FUN_001e094c, target 0xa); `*arg0==0x27` (result event) →
  show error = `*(arg1+4)<0x19 ? *(arg1+4)+820 : 818`, then dispatch sel 2. **840 ⟺ result code
  *(arg1+4)==0x14 (timeout).** 0x5bca90 does NOT send cmd0c. CORRECTS prior "0x27→cmd0c via sel2" note.
- op48 completion cb `0x5bc990`: `acc(0x87f7f8)=Σ lhu(rec+0x10)` over `*(arg1+8)` records;
  `T=FUN_005c5060(lhu 0x87f800)`; `acc<T`→re-query `0x5bdc70(0xd)`; `acc>=T`→advance `sel 8`.
- Observed order (T1 wire): register → op48 (once, seq1) → cmd0c LOOP (seq2+). op48 advances to sel 8,
  so the **cmd0c room-query is sent by vtable state 8 = `*(0x6ca8c0)`**; the loop = that state never
  meeting its advance condition. cmd = readUInt16BE(payload+2) = 0x000c.
- BLOCKER: vtable `0x6ca8a0` is BSS (overlay image ends VA 0x694700; dumps end 0x680000). vtable[8]'s
  address is runtime-only. Next = read `*(0x6ca8c0)` via PINE at server-select, then disasm it.
- Room-overlay slot→cb map (FUN_001d4d24 block @0x5bc860): 0x2→0x5bb4d0,0x3→0x5bb8e0,0x4→0x5c54e0,
  0x5→0x5c5610,0x6→0x5bb670,0x7→0x5bb980,0x8→0x5c56a0,0xa→0x5bc430,0xb/0xd→0x5bc590,0xe→0x5bc790,
  0x13→0x5bba20,0x15→0x5bc360.
- The select path HAS its own established-latch (answers prior open-Q "does select have a result latch
  like cs_result?"): continuation fn ptr `0x6cb96c` + ready flag `0x6cb98c`. ARMED at 0x5bd458
  (`*0x6cb96c=cont, *0x6cb98c=flag`); FIRED by `0x5bdc70` (if flag set → call `*0x6cb96c`, then read room
  params 0x368xxx). Select SUCCESS = the query completion reaches `acc<T → 0x5bdc70` with flag set;
  840 = the 0x5bca90 0x27 result event (code 0x14) instead.

### Update 2026-06-22 PM — LIVE vtable capture + SELECT ADVANCE CONDITION (Conf High)
- RUNTIME (PINE sampler, run 11-36-33, 231 live samples): two-connect model confirmed live
  (slot1c_cb conn+0x5b8: 0x626730 login → 0x5bca90 select); conn=0x36d760; cs_result=0. vtable base
  0x6ca8a0 CONFIRMED; full live table captured (handlers all 0x5b53xx-0x5b6570), e.g. vtable[2]=0x5b53b0,
  vtable[8]=0x5b5760. Latch flag 0x6cb98c=1 (ARMED) all loop, cont 0x6cb96c=0x5b6070. (Static 0x639xxx
  guess = RED HERRING.) cmd0c loop = continuation 0x5b6070 re-firing (op48 acc<T branch), NOT vtable[8].
- ADVANCE CONDITION (loop-exit), from 0x5bc990 + FUN_005c5060 raw disasm:
  exit requires  Σ lhu(reply_rec+0x10) ≥ T,  N=lhu(0x0086f800) (room idx, set @0x5c79d8),
  T=*(u16)(0x00365e00 + (N-1)*0x260 + 0x12a) = that room's expected member/slot count. acc@0x0086f7f8.
  acc≥T → 0x5bdf90(8) advance; acc<T → re-loop → 0x5bca90 0x27 (code 0x14) → 840.
- ADDR CORRECTION: 0x0086f800/0x0086f7f8 (lui0x87−0x800/−0x808), NOT 0x0087f800/0x0087f7f8 (older typo;
  prior "0x87f800 transient" likely read wrong addr).
- Server-fixable: fill room rec (N-1)@0x365e00 +0x12a (via area/slot-list replies) AND answer the op48
  NAME query with records whose +0x10 words sum ≥ that count.
- Live-read method = harness PINE sampler (watch file + pineSample), NEVER hand-rolled unbounded reads
  (they wedge PINE). See memory [[pine-sampler-is-the-test-method]].

### Update 2026-06-22 PM (T-ACC, run 16-34-40) — op48 count gate REJECTED as the select wall (Conf High)
- Live sampler at the CORRECTED addresses during the select loop: acc(0x0086f7f8)=0 always; N(0x86f800)=1;
  T=record[0]+0x12a=0. If 0x5bc990 were the consumer, acc(0)≥T(0) would advance — it 840s instead.
  ⇒ 0x5bc990 / the op48-count gate is NOT the wall; the server op48 reply is not consumed here. DO NOT
  tune op48 word0/count. (Confirms the old "0x5bc990 not the active consumer", now at the right address.)
- OPEN: what consumes the cmd0c (who=0xe1/0xa1 cmd=0x000c) reply. Registered room slots are 0x2-0x15;
  0xc is NOT among them. Next RE = pcap of run 16-34-40 (exact cmd0c bytes + op48-reply in-order
  delivery) + map cmd 0x0c → dispatcher slot.

### Update 2026-06-22 PM (R9) — cmd0c IS the wall; reply consumer 0x5bc430 advances the SM (Conf High)
- Wire (run 16-34-40): loop = game sends `a1 00 00 0c | 02f807d0 | seq=1(PINNED) | 256 zero bytes`
  (opcode 0x0c re-poll); server replies `b0 40 00 0c | seq=2..(advancing) | count=1 | "192.0.2.121"`;
  game ACKs (28B) then re-polls → 840. Game ACKs transport but rejects the answer.
- Dispatch (Ghidra FUN_001d9f78): opcode 0x0c → case 9 → conn+0x570 (NO DATA-bit branch ⇒ A0/B0
  irrelevant for cmd0c). conn+0x570 = slot 0xa = overlay cb 0x5bc430. cmd0c reply IS consumed by a live
  handler (NOT dropped, NOT "0x5bd8c0 ack-only").
- Consumer 0x5bc430 ADVANCE path (raw disasm): gate lbu(0x0070047c)!=0; loop reply entries vs local
  record table 0x6ca950 (stride 0x38, id match via 0x5c5120); per entry, if id matches AND reply
  lbu(entry+0xdd)==1 → jal 0x5bdfe0(0x24) + state 0x6cbc7e=0x10 (ADVANCE) + 0x5bc370.
- cmd0c ADVANCE CONDITION: reply must (1) count 0x70047c!=0, (2) entry id matches a local record
  (0x6ca950, filled by area/slot-list replies), (3) entry byte[0xdd]=1. Our zero/IP reply matches none.
- RELATION to [[cmd0c-reply-content-irrelevant]] (real-PS2 runtime): NOT contradicted — that test used
  count=0 / count=1-bare-IP, neither meets 0x5bc430's match, so both correctly no-op'd. R9 REFINES: a
  specific untested reply shape advances. Static Conf High on trigger; UNTESTED at runtime (verify next).
  Corrects only the routing claim (opcode 0xc → slot 0xa = 0x5bc430, a live handler, not 0x5bd8c0/dropped).

### Update 2026-06-22 (R11) — RUNTIME: cmd0c gate is count 0x70047c=0; member table never populated
- Sampler run 22-03-27 (live, during select loop, cb=0x5bca90, N=1): count 0x70047c=0 always; adv state
  0x6cbc7e never leaves 0; member table 0x6cdbe6 ZERO. ⇒ 0x5bc430 takes the EMPTY path (count==0) every
  iter, never reaching the match/advance branch — so cmd0c reply content is irrelevant UNTIL 0x70047c!=0
  (reconciles R9 with the "content irrelevant" runtime memory). 0x70047c is set=1 only by member-list
  handler 0x5c2460, which never ran (memtbl zero) ⇒ the GAME never sent the member-list query. WALL is
  UPSTREAM: what makes the game emit the member-list query / become enter-capable (lobby-walk descriptor
  / SNAP_LOBBY_SLOTS=2 mode=1; *conn kind 4=ENTER vs re-list). Game re-lists (cmd0c poll) not enters.
- TOOLING: the sampler "socket closed" storm was caused by 6 ZOMBIE PINE clients from prior sessions
  (bed8_watch --pin ×3, connect_desc, watch-callback, dump_range) contending PCSX2's PINE. Kill all stray
  node PINE clients before a sampler run. See [[pine-sampler-is-the-test-method]].

### Update 2026-06-22 (R12-R14) — render gated by a STATE-BYTE CASCADE; not a single-packet fix (Conf High)
- Lobby walk runs mode-1 full-header (0x6501 m1→0x6503 total=2→0x6504), descriptors populate, then game
  RE-LISTS (not enter). Select→UDP→op48 once→cmd0c poll loop→840.
- RUNTIME (SNAP_ROOM_RENDER=1): adv 0x6cbc7e flipped 0→0x10 (but 0x6cbc7e has ~30 writers = shared state,
  NOT proof of cmd0c advance). 0x6ff2b1(render arm)=0 ALL loop; 0x7006d4(join)=0xd0 (op-10 subcmd2 DID
  land). count 0x70047c=0, member table empty.
- ROUTING: server op-28 room-enter(slot 0x22)/member-list(slot 0x18) → UNREGISTERED slots → DROPPED.
  Only op-10 → slot 0x13 room-manager 0x5bba20 lands. 0x5c2460 (count setter) has NO findable caller
  (runtime BSS table). cmd0c/0x5bc430/count path likely vestigial here.
- ARM CASCADE: render needs 0x6ff2b1 armed ⟸ byte 0x6ce5cf>=2 (FUN_005c4f00 gate, F_be400→FUN_005bf1e0)
  ⟸ 0x6ce5c5>=2 (copied @0x5bf1c8) ⟸ … The room render is a DEEP multi-state SM walked during the full
  room create/join flow; the game is stuck in the cmd0c query state and never walks it. No single packet
  arms it.

### Update 2026-06-23 (R16) — CORRECTED FINAL MODEL: render arm is downstream; wall = select list query
- op48-reply consumer = 0x5bc990 (CONFIRMED Ghidra FUN_001e094c `FUN_001d4d24(1,0x31,param_4)`; 0x5bca90
  passes a3=0x5bc990), NOT 0x5c2460. op48 COMPLETES (acc=0 since Pi NAMEDSLOT_WORD0=0; T=0; 0>=0 →
  advances to vtable sel 8 = cmd0c state 0x5b5760). op48 is fine; hands off to cmd0c.
- The render arm (0x6ff2b1) + cascade (0x6ce5cf/0x6ce5c5) + the cmd0c sel-8 gate (0x6c4b90==6) are ALL
  written ONLY by the UI/room-flow region (0x5f6xxx-0x62exxx), which SELF-RUNS after the room LIST renders
  (F_arm@0x5c0e30 ← UI callers 0x617ad4 etc.). So the render machinery is DOWNSTREAM/self-driven, NOT the
  wall. The R12-R15 render pushes (op-28/op-10, SNAP_ROOM_RENDER) were off-target; SNAP_ROOM_RENDER
  reverted to 0.
- TRUE WALL: the select-time SN@P UDP queries (op48 done → cmd0c poll) never yield the AREA/ROOM LIST, so
  the list never renders, so the UI SM never runs. LEVER = the list-data path (cmd0c sender vtable[8] +
  what inbound populates 0x365e00/0x6cdbe6), NOT the downstream render arm. See
  HANDOFF-2026-06-23-select-840-render-is-downstream.md + memory [[select-840-render-arm-is-downstream]].
- bioserver caveat (user 2026-06-23): KDDI middleware ≠ SN@P; use ONLY for app-layer 0x6XXX intent,
  never for SN@P transport/SM; cross-check everything against our wire/disasm.

### Update 2026-06-23 PM — UNIFYING ROOT: select connection never establishes (Conf High)
- Live poke tests (poke_render/poke_cmd0c, runtime): forcing UI mode 0x6c4b90=0xc RENDERS the in-area
  room screen (empty frame: "black box, blue border") — the full render chain (0x5bc430 build → state 0x24
  0x5b6460 add → 0x616d30 render) is reachable. But it's EMPTY: 0x5bc430's cmd0c room-match never succeeds
  at runtime despite ALL verified conditions (count=1, 8-byte id, reply word0=0, byte0xf5=1, in-order
  delivery, consumer registered) — a static-vs-runtime discrepancy needing a debugger.
- NATURAL enter (#2) = 0x619330 PHASE MACHINE (dispatch on phase 0x6c5490=UIstruct+0x900, phases 0..4 →
  0x6193e0/430/5b0/680/750). These are connection/session steps (phase1 strcmp-validates vs 0x874fc0). The
  phase is stuck low because the connection never completes.
- UNIFYING ROOT (user insight "no connection", confirmed): the SELECT connection to the room service
  (0x5bca90 conn) never reaches ESTABLISHED. This ONE fact explains every wall: cmd0c loop→840, 0x619330
  phase stuck, 0x5bc430 match fails (no real conn/room data), empty room list. Render+UI are reachable;
  the missing primitive is CONNECTION ESTABLISHMENT for the select connect. Forced pokes bypass the UI but
  not the connection. #2 = (a) map 0x619330 phase machine; (b) find the select-connect established
  condition + why it never fires; (c) make the server complete it → phases advance → natural render.
  Pokes (mode/ready/count/id, SNAP_CMD0C_TEST) were diagnostics; clears on reboot / flag opt-in.
- RESUME POINT: docs/findings/protocol/HANDOFF-2026-06-23-v2-render-reachable-conn-establish-root.md.
  Two remaining gaps are DEBUGGER-GATED (PINE/static can't crack): (1) 0x5bc430 match contradiction
  (static says it must match with our poked conditions; runtime never matches — checked 0x5c7d00 entry
  call (not the cause), 8-byte id, word0, byte0xe5, delivery, registration); (2) 0x7df500 phase-data
  source in an unstable/paged region. NEXT = PCSX2 EE debugger: exec-bp at 0x5bc4a8 (the match `bne`),
  inspect a0(local-id parse) vs v1(reply word0) to see why they differ → resolves the whole select-840.
