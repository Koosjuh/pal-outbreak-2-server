# SERVER BLUEPRINT — STARTING NOTES (NOT validated, NOT canonical)

> **STATUS (owner directive 2026-07-18): this is a STARTING document, not proof the model is complete,
> and NOT canonical.** It is superseded by the PHASE-1 specification campaign, whose output is the 10
> validated deliverables in `docs/spec/` (state-transition graph, packet catalogue, domain model,
> client-memory/UI map, timeout/heartbeat/cleanup model, KDDI↔SN@P gap register, evidence index,
> contradiction/unknowns register, Codex review, and — only then — a proposed implementation
> architecture DERIVED from the completed model). **No implementation and no implementation order until
> Phase 1 is complete.** The subsystem boundaries must come from the reference server's ARCHITECTURE,
> not from observed symptoms. The content below is retained as evidence-in-progress, to be folded into
> `docs/spec/` and validated (or corrected) there — not trusted as-is.

KDDI Bioserver = the behavioral specification; SN@P/PAL = the wire it is realized on. Every multiplayer
screen is a PROJECTION of one authoritative state machine.

**Method (locked 2026-07-18):** blueprint a slice → test offline → compare vs the reference →
Codex co-RE review → deploy to rig. Codex challenges assumptions continuously; divergences are
investigated until evidence explains them; SN@P≠KDDI differences are documented GAPS, not assumptions.

**Per-transition fields (required):** Preconditions · State mutation · Packets sent · Recipients ·
Ordering · Client memory changes · KDDI reference evidence (file:line) · SN@P impl notes · Confidence
(Confirmed/Likely/Hypothesis/Unknown) · Gaps.

**Evidence roots:** KDDI = `references/bioserver/.../bioserv2/bioserver/*.java`. SN@P decompile =
`analysis/claude-helper-module-full-2026-05-29.txt` (`helper:LINE`) + Ghidra MCP (main ELF analyzed;
netwk overlay via savestate disasm). RE docs = `docs/findings/protocol/G12-*-RE-2026-07-1{6,7,8}.md`.

---

## PART 1 — THE AUTHORITATIVE STATE MODEL (the one source of truth)

Single owner: `server/lobby_state.js`. Mirrors KDDI `ClientList`+`Slots` (behavior, not bytes).

### Entities
- **player** (KDDI `Client.java:29-55`): identity key (userid/handle), live TCP+UDP transport
  bindings, **position triple `(area, room, slot)`**, `playerNo` (1-4; 1=host), `host` flag,
  `hnpair`/displayName, `charStats` (opaque blob → char-id), liveness (`connAlive`,
  `lastLivenessAt`). **The triple is the sole source for all counts and broadcast audiences.**
- **area** (KDDI `Area.java`): static config (10 areas); NO membership stored — counts are scans.
- **room/slot** (KDDI `Slot.java:26-50`): server-owned handle, name, password/protection, scenario,
  rules, `maxPlayers`, **status FREE=1/INCREATE=2/GAMESET=3/BUSY=4**, hostId, ordered members.
- **counts**: NEVER stored — computed by scanning the triple (KDDI `ClientList.java:178-227`):
  `countArea`, `countRoom`, `countSlot`, `countOnline`.

### Broadcast audiences (position-triple filters — KDDI `PacketHandler.java:176-330`)
`areaSelectViewers` (area==0), `viewersOfArea(a)` (area==a,room==0), `membersOf(handle)`,
`roomAndListViewers(handle)` (members + same-area room-list viewers = broadcastInSlotNRoom).

### The two universal rules (from the RE, apply to EVERY projection)
1. **Every state change is PUSHED to every affected client** (KDDI broadcasts on transition), from the
   authoritative count/roster — never a snapshot the client happens to re-pull.
2. **A client display is a projection of specific client memory.** To change a display you must know
   (a) the memory it reads, (b) the packet+field that writes it, (c) whether it's a pull-reply or a
   proactive push, (d) any render-trigger the write depends on. (This is what symptom-first missed.)

---

## PART 2 — CLIENT-MEMORY ↔ DISPLAY MAP (the projections, so we never guess a vehicle again)

| Display | Client memory | Written by | Pull/Push | Confidence | Doc |
|---|---|---|---|---|---|
| Server-select "N players" | `slot+0x12c` | TCP 0x6510 reply u16 | PULL (snapshot) | Confirmed | count-displays-RE |
| Server-select "/max" | `slot+0x12a` | TCP 0x6504 trail+2 | PULL | Confirmed | count-displays-RE |
| Area-select per-area count | `0x6ce5de[area]` | UDP op48 record+0x10 (`FUN_005c1220`) | PULL + push-on-join/leave (`FUN_005bb8e0/980`) | Confirmed | count-displays-RE |
| Room-list occupancy "N/M" | op49 record +0x14/+0x20 (BE) | UDP op49 reply | PULL | Confirmed (endian bug) | op49-fields-RE |
| In-room VISIBLE roster rows | `0x6c7c2c[i]` name (stride 0x3b0) | op06 member-JOIN → `FUN_005bb4d0`→event0x1f→`FUN_005b5ac0` | PUSH (live) | Confirmed | render-pipeline-RE |
| In-room roster (durable) | op0a buffer `0x6cdbe6` → redraw `FUN_00600de0` | op0a REPLY to client query (completes session-open) | PULL-reply → redraw | Confirmed | render-pipeline-RE |
| In-room "N players" | `0x6cfb62[handle-1]` | op06 join `+1`/leave `-1` | PUSH | Confirmed | render-pipeline-RE |
| In-room character/cast | charstats blob +0xc8=char-id | op06 record charstats / `FUN_005bc430` update | PUSH | Confirmed | render-pipeline + identity |
| Roster DEDUP KEY | `(char-id 0x6c7d18, type 0x6c7d1a)` | charstats — **must be DISTINCT per member** | — | Confirmed (ROOT CAUSE) | render-pipeline-RE T27 |
| Displayed member name | roster row +0x10 name[16] | op06 record +0x00 (client renders verbatim) | PUSH | Confirmed | identity-RE |

**Key invariants proven:** op0a can NEVER draw a row or count (it takes the `0x6cbc7e==2`
completion path); op06 is the only live roster+count vehicle; the roster dedups by character so members
MUST have distinct char-ids; op0a-as-reply completes a session-open whose continuation is the redraw
`FUN_00600de0` (durable); op0a-proactive accumulates + never renders.

---

## PART 3 — LIFECYCLE TRANSITIONS

_Populated from current evidence. Each slice is verified (offline + reference + Codex) before build.
Confidence + Gaps are explicit. Slices marked ⏳ need the named capture/decompile before build._

### L0 Connect / Register / Auth  — Confidence: Confirmed (golden)
- **Precond:** client resolves DNS to Pi. **Mutation:** `lobby_state.bindEndpoint(identity)` on the
  post-register-bind (handle @UDP register+0x10 / bind+0x20). **Packets:** UDP 154B Blowfish
  register-OK; TCP boot seq + 0x6110/0x6101 seeds. **Recipients:** requester. **Client memory:**
  session/regN state. **KDDI:** `PacketHandler.java:401-548` (login handshake). **SN@P:** golden
  (`g2-solved`, `g10-g11`). **Gaps:** none for connect; the identity handshake (IDHNPAIRS/HNSELECT)
  is NOT used by PAL — names come from the member record (§Part 2).

### L1 Server-select  — Confidence: Confirmed vehicle, snapshot-only
- **Precond:** in TCP lobby. **Mutation:** none. **Packets:** TCP 0x6510 (current→slot+0x12c),
  0x6504 (max→slot+0x12a), 0x6503/0x6502 headers. **Recipients:** requester (PULL). **KDDI:**
  slot list + `countPlayersInSlot` (`PacketHandler.java:749-948`). **SN@P:** `SNAP_SERVER_COUNT`
  feeds `countOnline()`. **Gap:** snapshot only — KDDI broadcasts the count on join/leave; PAL has no
  server-select push vehicle proven (a re-pull is the only refresh). **NEEDS-DECOMPILE:** whether any
  push updates slot+0x12c without a re-query.

### L2 Area-select + area counts  — Confidence: Confirmed vehicle, fix un-deployed
- **Precond:** area==0. **Mutation (enter):** `enterArea` sets `player.area`. **Packets:** area list
  TCP 0x6203/0x6204 (blob) + UDP op48 records (name + count@+0x10 → `0x6ce5de`). **Recipients:**
  KDDI broadcasts AREAPLAYERCNT to the area + area-select viewers on AREASELECT/EXITAREA
  (`PacketHandler.java:733-747/1136-1147`). **Client memory:** `0x6ce5de[area]` (count),
  `0x6ce5f0` (status/un-grey). **Ordering:** un-grey record must not be the count sentinel `0xffff`.
  **SN@P:** we send `0x6ce5de` = `NAMEDSLOT_WORD0` (0xffff sentinel) → draws 0. FIX = real count in the
  AREA records. Live update possible via op10-family join/leave (`FUN_005bb8e0/980` bump `0x6ce5de`).
  **Gap:** the AREA-record `+0x10` also feeds the connect join-gate accumulator — change AREA records
  only; **rig-verify no box re-greying** (held back for this reason). **NEEDS-RIG.**

### L3 Room discovery (room list)  — Confidence: Confirmed vehicle + endian bug
- **Packets:** UDP op49 records (stride 0x28: name@+0, current@+0x14, flags@+0x1c, max@+0x20,
  handle@+0x24). **Client memory:** the room-list rows. **SN@P bug:** numerics written LE but the
  transport byteswaps → client reads 0/0. FIX = BE for +0x14/+0x1c/+0x20 (handle @+0x24 stays LE —
  proven ENTER round-trip). No status byte: INCREATE/GAMESET → full(current==max)/locked(bit16)/open.
  **KDDI:** ROOMPLAYERCNT/SLOTSTATUS (`PacketHandler.java:758-961`). **Confidence:** Confirmed;
  BE flip NEEDS-RIG.

### L4 Room CREATE + go-live  — Confidence: Mixed
- **Precond:** vacant slot. **Mutation:** `createRoom` status=INCREATE, host, playerNo=1; **go-live
  (6504 burst) → GAMESET** (KDDI `PacketHandler.java:1305-1343`). **Packets:** op04→op28 sel4
  (unlock 0x6ff2b1=1) [local-replay only, NOT rig-verified]; then op09 USER/MAXI, op08 STAT.
  **SN@P:** `SNAP_CREATE_SLOT_ACCEPT`/`SNAP_CREATE_FLOW`. **Gap ⏳:** the config handshake interleave
  (scene/name/password/rules) is HOST-OWNED + relayed — **NEEDS-CAPTURE** (create→configure). Max
  `0x6cfa2c` writer **NEEDS-DECOMPILE**.

### L5 Room JOIN  — Confidence: Confirmed
- **Precond:** target GAMESET (INCREATE/BUSY reject — KDDI `PacketHandler.java:1642-1703`).
  **Mutation:** `joinRoom` + assign playerNo (lowest free 2-4). **Packets:** op06 ENTER→op28 sel6
  accept; the joiner's op10 sub-0x02 join-request → sub-0x0C accept (fires `FUN_00601300`, room
  renders — T22 rig-confirmed). **SN@P:** `SNAP_ROOM_ENTER_ACCEPT` + `SNAP_JOIN_OP10_SUBC`.
  **Confidence:** Confirmed (rig).

### L6 Member roster + count (the projection all clients must converge on)  — Confidence: Confirmed model
- **On any membership change:** push op06 member-JOIN (DISTINCT char-id per member — ROOT CAUSE T27)
  to EVERY in-room client (draws row `0x6c7c2c` + count `0x6cfb62`); answer op0a QUERIES with the
  complete deduped list (durable buffer → redraw via the session-open continuation `FUN_00600de0`).
  **Recipients:** all room members (+ list viewers for the count). **Ordering:** op06 (live) then
  keep op0a-reply consistent. **Never** push op0a proactively; **never** re-send sub-1 room-blob to an
  in-room client. **Count index = handle-1** — align room handle to list-position+1 (seed room takes 1
  → real room gets 2 = the scatter). **KDDI:** PLAYERSTATBC + SLOTPLRSTATUS. **Confidence:** Confirmed
  (char-id fix made the member list correct on rig 2026-07-18); the CREATOR live-update + count-index
  alignment are the open build items (see L6-build). **Gap:** real char-ids need the charstats capture
  (synthetic distinct in the interim).

### L7 Character / cast select  — Confidence: Confirmed store, vehicle ⏳
- charstats 0xf0 blob @rec+0x18; char-id @charstats+0xc8. In-room update relay = `FUN_005bc430`.
  **Gap ⏳:** the client→server charstats-send vehicle **NEEDS-CAPTURE** (character-select). Interim:
  synthetic distinct char-ids (roster converges, characters arbitrary).

### L8 Room configuration / rules / scenario  — Confidence: Host-owned, relay, ⏳
- HOST-OWNED; the host bursts op10 sub-3/5/6/7/8/9; server RELAYS to joiners + echoes the host's TCP
  0x6509/0x6609/0x660B/6504 picks (KDDI `PacketHandler.java:1211-1343`). **Gap ⏳:** interleave +
  pump gate (`screen+0x97e`) **NEEDS-CAPTURE + NEEDS-DECOMPILE**.

### L9 Member LEAVE / CANCEL  — Confidence: mechanism known, vehicle ⏳
- op06-leave `FUN_005bb670` decrements count + event 0x20 removes/compacts the row; KDDI broadcasts
  LEAVESLOT[handle] to survivors, host-leave dissolves (no migration). **Gap ⏳:** survivor-notify SN@P
  vehicle + the in-room EXIT completion (see L10) **NEEDS-CAPTURE**.

### L10 Room EXIT (the can't-leave bug)  — Confidence: mechanism known, ⏳
- The screen-6 freeze = a SN@P `0xb000` type-2 transport CLOSE the server never completes
  (`FUN_005be7b0` needs state 2). Server-side satisfiable. **Gap ⏳:** exact close response
  **NEEDS-CAPTURE + NEEDS-DECOMPILE** (`FUN_001dbd0c` receive path).

### L11 Disconnect / Timeout  — Confidence: KDDI clear, PAL unbuilt (the PS2 kick)
- **KDDI:** 30s heartbeat + 60s CONNCHECK; one miss → `removeClient` (full leave cleanup + broadcasts)
  (`HeartBeatThread.java:50-78`, `PacketHandler.java:343-364/1945-2028`). **SN@P:** op40 transport
  keepalive (golden) is socket-death; the ROOM-level liveness = the joiner's op10 sub-0x0e ping which
  we answer WRONG (sub-1 room-blob) → the client self-ejects ~60s = **the PS2 kick**. FIX = reply op10
  sub-0x0f to sub-0x0e; and disconnect must be a lifecycle event (removeClient + broadcasts), not a
  5-min TTL. **Confidence:** Confirmed diagnosis; build pending.

### L12 Ready / Game-start / Handoff / Cleanup  — Confidence: Unknown ⏳
- KDDI STARTGAME→GETREADY→gameserver handoff (`PacketHandler.java:2171` + start queries). **Gap ⏳:**
  entire PAL start flow **NEEDS-CAPTURE + NEEDS-DECOMPILE**. Out of scope until L0-L11 converge.

---

## PART 4 / 5 — REMOVED (premature)

The build-order "slices" (Presence&Counts, Roster, Liveness, Exit, Config, Start) were organized around
observed SYMPTOMS, not the reference server's architecture — deleted per the owner directive. The
implementation architecture + order will be DERIVED from the completed Phase-1 spec (`docs/spec/`),
after the full model is reconstructed and Codex-reviewed. The open gaps/unknowns move to the spec's
`gap-register.md` and `unknowns-register.md`. The observed symptoms (counts, roster, kick, exit, config)
are TEST CASES the final model must explain — not the structure of the work.
