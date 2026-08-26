# Charstats → sub-7 SOURCE buffer RE (2026-08-26)

Closes the gap left open by `analysis/charstats-propagation-RE-2026-08-26.md`: **where the host's
game-start sub-7 reads each seat's charstats FROM**, and **what one server message makes the
joiner's seat on the host carry the joiner's real op-0c character** — without re-seating and without
touching a display-only copy.

Method: traced every buffer in the sub-7 source chain to a decompile line (overlay-3dat corpus
`reverse-engineering/network/sources/overlays/overlay-3dat-decompile/`), grep-verified the set of
writers of the seat table, and cross-checked the bioserv2 analogue. Evidence-graded per link.

---

## TL;DR — the ONE emission

Fill the **0xf0 charstats blob at op-06 record+0x18 (wire offset 0x28)** with the seat member's
**latest stored inbound op-0c blob**, and emit/defer the **host-directed op-06 member-JOIN for the
joiner AFTER the server has received+stored the joiner's op-0c** (never a zeros placeholder before
it). Do the same symmetrically for the host's op-06 delivered to the joiner. This is **Path A,
corrected** (rec+0x18 = the captured op-0c bytes, not zeros; timing = after op-0c). Path B (a
translated op-0c relay) is **display-only and does NOT fix the splash** — it writes a different
buffer. See §4 for the exact frame and §6 for the re-seat caveat.

---

## Q1 — WHERE the sub-7 builder reads charstats FROM (Confirmed, decompile-cited)

The task's premise ("offsets 0x00/0x32/0x64/0x96/0xc8 into 0x6fffd1+slot*0x114") points at the
DESTINATION of a late copy, not the source. The real **sub-7 SOURCE is `0x700734 + seat*0x114`**.

Sub-7 builder = **FUN_005c5e30** (`FUN_005c5e30.c`): `memcpy(auStack_30c, param_2, 0x36)` then
`func_0x001df380(conn, 0x8000, buf{[0]=7}, 0x3a, 1, param_1)`. So `param_2` = the source pointer,
`param_1` = the target member id. The caller supplies both.

Caller = **FUN_005c6500** (host start SM) phase `0x0b` (`FUN_005c6500.c`, the `cRam006cbb90 == '\v'`
block):
```
src = f0*0x32 + f8*0x114 + 0x700734      // (uStack_7e = f0*0x32; (f8*0x44+f8)*4 = f8*0x114)
memcpy(auStack_7c, src, 0x32 or 0x28)    // one of 5 chunks; f0 = chunk 0..4, f8 = source seat
id  = decode(0x700b60 + f00700700*0x114) // FUN_005c5120 -> recipient id
FUN_005c5e30(id, &bStack_80)             // send sub-7 (chunk header @+0, 0x36 bytes)
```
So the sub-7 charstats bytes come from **base `0x700734`, stride `0x114`, per source seat `f8`**,
sliced into 5 chunks (offsets 0x00/0x32/0x64/0x96/0xc8, lengths 0x32×4 + 0x28). `0x700734` =
`0x700710 + 0x24` — i.e. the **charstats field (+0x24) of a 0x114-stride member record based at
`0x700710`**.

`0x6fffd1` (the task's candidate) is the **DESTINATION** of phase `0x0d`
(`cRam006cbb90 == '\r'`), which runs AFTER all sub-7 sends and copies the local roster out for
later use:
```
memcpy(0x6fffd1 + i*0x114, 0x700734 + i*0x114, 0xf0)   // 0x700734 -> 0x6fffd1, not the reverse
```
So `0x6fffd1` is a post-handoff snapshot, never the sub-7 source.

### The full source chain (every link Confirmed)
| # | buffer (charstats field) | written by | from |
|---|---|---|---|
| 1 | op-06 wire **rec+0x18** (0xf0) | server | (server must fill) |
| 2 | scratch **0x6cd696** | `FUN_005bb4d0:22` `memcpy(0x6cd696, rec+0x18, 0xf0)` | rec+0x18 |
| 3 | seat **0x6c7c50** (=0x6c7c2c[slot]+0x24, stride 0x3b0) | `FUN_005b5ac0:70` `memcpy(seat+0x24, scratch, 0xf0)` via **event 0x1f** | 0x6cd696 |
| 4 | candidate **0x6ff2e1** (=0x6ff2bd[slot]+0x24, stride 0x114) | `FUN_005c6210` (create/enter arm) | 0x6c7c2c seat |
| 5 | member **0x6ff731** (=0x6ff70d[slot]+0x24) | `FUN_005c6500` phase 0 (compacts 0x6ff2bd→0x6ff70d) | 0x6ff2bd |
| 6 | **0x700734** (=0x700710[n]+0x24) | `FUN_005c6360` `memcpy(0x700734, 0x6ff731, 0xf0)` | 0x6ff70d (accepted only) |
| 7 | **sub-7 wire** | `FUN_005c5e30` | 0x700734 |

`FUN_005c6360.c` is the decisive middle link — it builds the sub-7 source `0x700710`/`0x700b60`
tables straight from the seated member table `0x6ff70d` (name←+0x00, id←+0x10, **charstats←+0x24**),
compacting only accepted members (`0x6ff2b5[i]==1`).

**Answer Q1:** the sub-7 charstats source is `0x700734+seat*0x114`, transitively the **op-06
rec+0x18 seated at `0x6c7c50`**. Not a live "landing zone" — the persistent seat table `0x6c7c2c`.

---

## Q2 — how the peer (joiner) seat charstats is populated on the HOST (Confirmed)

Only link #2→#3 above: the host's op-06 handler `FUN_005bb4d0` copies **rec+0x18** into scratch
`0x6cd696` and fires **event 0x1f → FUN_005b5ac0**, which seats the 0xf0 charstats at `0x6c7c50`.
There is no other producer of a peer's seat charstats (grep of all `0x6c7c2c` writers = only
`FUN_005b5ac0` seat + `FUN_005b5d20`/`FUN_005b6570` remove-compaction copies + read-only
`FUN_005b53f0`; nothing else). So **the joiner's seat charstats on the host is exactly whatever the
op-06 that seated the joiner carried in rec+0x18.**

Because the current server (`game_udp_server.js` `sendMemberJoinBroadcast` :1195-1220 and the create
op-06 :1000-1020) leaves rec+0x18 ZEROED (only writes a synthetic char-id at +0xf0 for the dedup),
the joiner's seat charstats on the host is zeros → the sub-7 renders Jim. If the op-06 that seats
the joiner is sent before the joiner's op-0c is known, rec+0x18 is necessarily stale — **Confirmed**.

---

## Q3 — THE CRUX: does the inbound-op-0c apply path write the sub-7 source? (Confirmed: NO)

Inbound op-0c apply = **FUN_005bc430** (slot 0x0a). It writes **only the DISPLAY table `0x6cdbe6`**
(stride 0x118): id-matched entry+0x24 = `0x6cdc0a`, plus scratch `0x6cd696`; then redraws via
`FUN_005bc370` (compacts `0x6cdbe6` → visible roster `0x6ce046`). **It never touches `0x6c7c2c`**
(`FUN_005bc430.c`, verified — the loop base is `0x6cdbe6`, stride 0x118, not the 0x3b0 seat table).

Grep of every `0x6c7c2c` writer confirms **no post-seat charstats updater exists**: the seat field
`0x6c7c50` is written only by the seat itself (`FUN_005b5ac0`, event 0x1f) and by the two
remove-compaction functions (`FUN_005b5d20`/`FUN_005b6570`, which shift a neighbour's charstats down
when a member leaves). No opcode does an in-place "update this seat's charstats."

**Answer Q3:** op-0c and the sub-7 source are DIFFERENT buffers (0x6cdbe6 vs 0x6c7c2c). A peer's
op-0c can NEVER, by itself, change what the host sends in sub-7. The only vehicle into the sub-7
source is op-06 (event 0x1f). Since op-06 seats (and does not update in place), the joiner's real
charstats must be present in rec+0x18 of the op-06 that seats the joiner. This is why a translated
op-0c relay (prior-doc Path B) cannot fix the splash — **Path B is display-only. Refuted as a splash
fix; keep it only for live mid-room character swaps that need the visible roster row redrawn.**

---

## Q4 — bioserver analogue and its SN@P translation (Confirmed from bioserv2)

- **CHARSELECT (0x6190)** — client sends chosen char+stats; server STORES on the client
  (`cl.setCharacterStats`, PacketHandler.java:563), replies empty TELL, **never relays the SET**.
  Comment: *"send once before entering area selection and then when a slot is created"* → in
  bioserver the character is known **BEFORE** the player joins a slot. = PAL **op-0c** (ACK-only).
- **PLAYERSTATBC (0x6503, BROADCAST)** on **JOINGAME**: `status = cl.getCharacterStat();
  broadcastInSlot(...)` (PacketHandler.java:1693-1695) — server broadcasts the joining player's
  **stored** stats to everyone in the slot. Because CHARSELECT precedes JOINGAME, the broadcast
  always carries the real character. = PAL **op-06 member-JOIN with rec+0x18 = stored stats**.
- **PLAYERSTAT (0x6913)** / **PLAYERSTATS (0x640A)** — targeted / bulk PULLs answered from the
  server's stored stats (`getPreGameStat(player)`, :1451). The PAL sub-6/sub-7 handoff is instead
  HOST-BUILT from the host's local seated roster (0x6c7c2c), so there is no live server pull to hook
  — which is exactly why the seat data must be correct at op-06 time.

**Translation:** the bioserver mechanism = *store on select, broadcast the stored blob at join,
select-before-join ordering*. The faithful SN@P form is: server stores each client's op-0c 0xf0
blob; the joiner's **op-06 to the host** (and the host's op-06 to the joiner) carries that stored
blob in **rec+0x18**; the op-06 is emitted **after** the sender's op-0c is stored (mirroring
CHARSELECT-before-JOINGAME).

---

## THE DELIVERABLE — the single server emission

**Opcode 0x06 (member-JOIN), reliable, targeted to the recipient session** (who byte 0xA0 → SN@P
slot 2 → `FUN_005bb4d0`). Record based at wire+0x10:

| wire off | field | value |
|---|---|---|
| +0x00 | SN@P header | who/len/`00 06`; token+ack mirror at +0x04..+0x0f; in-order txSeq @+0x08 |
| +0x10 | rec+0x00 name[16] | member display name |
| +0x20 | rec+0x10 id | the member's minted memberId (as today) |
| **+0x28** | **rec+0x18 charstats[0xf0]** | **the member's latest STORED inbound op-0c 0xf0 blob** (carries char-id @+0xc8 = wire+0xf0 and class @+0xca = wire+0xf2) |
| +0x118 | trailer | `ba 47 66 11` |

Recipient / timing:
1. **Server captures** each client's latest in-room op-0c 0xf0 charstats blob (disambiguated from
   the near-empty select-time room-query op-0c by non-empty body + in-room state — classifier
   already exists at `game_udp_server.js:1336`).
2. **Joiner→host op-06:** fill rec+0x18 with the JOINER's stored op-0c blob, and **do not send it
   before the joiner's op-0c is stored.** Defer the host-directed seat broadcast until the op-0c has
   arrived (bioserver's select-before-join order). One clean seat, real data.
3. **Host→joiner op-06** (roster-to-joiner): fill rec+0x18 with the HOST's stored op-0c blob, so the
   joiner's splash also shows the host's real character.

This fixes the splash (chain #1→#7) AND the in-room seated roster render (FUN_00605790 draws the
seated table 0x6c7c2c, which now carries the real charstats). Routes to slot 0x02 only — zero
slot-0x26 risk.

### Bonus: the real charstats FIX the dedup, don't fight it
`FUN_005b5ac0` dedups by **char-id (charstats+0xc8) with the special pair 6↔0x5b**: an incoming
char-id equal to a seated one → seat DROPPED. The current synthetic `char-id = playernum` hack
(`SNAP_DISTINCT_CHARID`) never collides (1 vs 2) so both always seat — but it also hides Outbreak's
real "two players can't pick the same character" rule. Feeding the **real** char-id via the stored
op-0c blob is both correct data AND correct dedup: if both players legitimately pick different
characters they seat; the client already prevents duplicate live selection.

---

## The re-seat caveat (why this must be TIMING, not a second op-06)

op-06 **seats**; it has **no in-place update**. If a zeros/placeholder op-06 already seated the
joiner before op-0c, you cannot fix it with another op-06:
- same char-id as the placeholder → `FUN_005b5ac0` dedup-**drops** the second op-06 (no update);
- different char-id → it seats a **DUPLICATE** into the next empty 0x6c7c2c slot.

So the correct shape is **defer the first host-directed op-06 until op-0c is known**. If the game
flow forces the seat to appear before selection (seat-then-select), the only decompile-supported
refresh is **member-remove then op-06 re-add** (drive `FUN_005b5d20`/`FUN_005b6570` compaction via
the leave event, then re-seat with real rec+0x18) — heavier, roster flicker, and the leave opcode
needs confirming (see Needs-Ghidra). Prefer the timing fix.

---

## Corrections to `analysis/charstats-propagation-RE-2026-08-26.md`
- §3A said game-start reads `0x6c7c2c` directly. **Refined:** game-start reads `0x700734`
  (`FUN_005c5e30`←`FUN_005c6360`←`0x6ff70d+0x24`←`0x6ff2bd+0x24`←`0x6c7c2c+0x24`). The seat table is
  the ULTIMATE source but two compaction copies sit between it and the wire; both are Confirmed.
- The doc left rec+0x18 = zeros as the plan and implied a later op-0c or op-06 could refresh the
  seat. **Refined:** rec+0x18 must equal the STORED op-0c blob, and the op-06 must be emitted AFTER
  op-0c (or preceded by a remove). No later message updates the seat charstats — Confirmed by the
  full 0x6c7c2c-writer grep.
- Path B (translated op-0c) is **Refuted as a splash fix** (writes 0x6cdbe6, not 0x6c7c2c); retain
  only for live in-room row redraw.

---

## Grades
- Q1 sub-7 source = `0x700734+seat*0x114` ← `0x6ff70d+0x24` (FUN_005c6360/6500/5e30): **Confirmed**.
- `0x6fffd1` is the phase-0x0d DESTINATION, not the source: **Confirmed**.
- Q2 peer seat charstats set only by op-06 rec+0x18 via event 0x1f (FUN_005bb4d0:22 → FUN_005b5ac0:70):
  **Confirmed**.
- Q3 op-0c apply (FUN_005bc430) writes 0x6cdbe6 display, NOT 0x6c7c2c; no post-seat updater exists:
  **Confirmed** (handler body + exhaustive 0x6c7c2c-writer grep).
- Q4 bioserver = store-on-select + PLAYERSTATBC-on-join, select-before-join: **Confirmed** (bioserv2).
- Deliverable = op-06 rec+0x18 filled from stored op-0c, timed after op-0c (Path A corrected):
  buffer identity **Confirmed**; that it renders the real splash char **Likely** (needs rig/PINE).
- Dedup on real char-id is correct (not the synthetic hack): **Confirmed** (FUN_005b5ac0 branch).

## Needs fresh Ghidra (ranked)
1. **The join/select ORDER on the joiner** — decompile the joiner's room-entry vs op-0c emission
   sequence (which screen 0x6c4b90 sends op-0c) to confirm the timing fix is sufficient (op-0c
   before the seat is required) vs whether remove+re-add is unavoidable. Highest leverage.
2. **The member-LEAVE opcode/event** that drives `FUN_005b5d20`/`FUN_005b6570` compaction — needed
   only for the fallback remove+re-add path (both have CALLERS(0) = event-table dispatched).
3. **FUN_005c0920** — confirm it assembles the seat scratch (`auStack_fc` = 0x6cd696 0xf0 charstats,
   `sStack_138`/`sStack_136` = char-id/class dedup keys) so rec+0x18 layout ⇒ dedup keys is exact.
4. **FUN_00605790 render source** — confirm the in-room roster row draws charstats from the seated
   0x6c7c2c (so Path A also fixes the in-room render), independent of the 0x6cdbe6 display copy.

## Highest-leverage next experiment
Behind a flag (default OFF), (a) capture each client's in-room op-0c 0xf0 blob into its room profile;
(b) fill op-06 **rec+0x18** (wire+0x28) with that blob in BOTH the host→joiner roster op-06 and the
joiner→host seat broadcast; (c) gate the joiner→host seat broadcast so it fires only after the
joiner's op-0c is stored. Verify LOCALLY (no Pi) after a 2-console join+select via PINE/savestate:
1. host `0x6c7c50` (seat1 charstats) `+0xc8` char-id == the JOINER's chosen character;
2. after game-start, host `0x700734+1*0x114` `+0xc8` == same (the sub-7 source);
3. splash renders the joiner's real character, not Jim.
Falsifier: if (1) holds but (3) fails, the sub-7 chunk slicing (offsets/lengths in FUN_005c5e30) or
the recipient's sub-7 apply is the next suspect, not the source buffer. nora review before any Pi
deploy.

## ORDERING RESOLVED (wire, 2026-08-26) — no defer needed
The RE's top open question ("op-0c vs room-entry op-06 ordering — decides whether defer alone
suffices") is answered by the wire. rig3 + rig4, BOTH consoles, EVERY time:
  op-0c (char-select) arrives ~1-3 s BEFORE op-06 (room-entry).
  rig3: PC op-0c 29.14 < op-06 32.22 ; PS2 op-0c 48.75 < op-06 49.98.
  rig4: PC op-0c 610.32 < op-06 612.01 ; PS2 op-0c 629.49 < op-06 630.69.
PAL is SELECT-BEFORE-JOIN, exactly like bioserver's CHARSELECT-before-JOINGAME. So when the server
seats a member (its room-entry op-06) it ALREADY holds that member's op-0c charstats. NO defer, NO
re-seat: capture the op-0c blob per session, and fill rec+0x18 with the SUBJECT session's stored
blob at every member-record emission (joiner's own record, roster-to-joiner existing members, and
the join fanout).

## IMPLEMENTATION PLAN (SNAP_CHARSTATS_SEED, default OFF) — for a focused next pass
1. CAPTURE: on inbound op-0c in the CHAR-SELECT form (0xf0/240-byte charstats body, distinct from
   the 260-byte room-query op-0c), store the 0xf0 blob on the session (#charstatsBlob). VERIFY the
   discriminator (size and/or flags) so a room-query op-0c is never mistaken for charstats.
2. EMIT: extend buildMemberJoinPayload with an optional charstats(0xf0) -> write at record+0x18
   (wire +0x28). In #sendJoinFollowUps fill each record with the SUBJECT member's stored blob:
   - joiner's own member-JOIN  -> this session's blob
   - roster-to-joiner existing -> each existing member's blob
   - join fanout to existing    -> this (joiner's) blob
3. VERIFY byte-mapping BEFORE deploy: confirm the op-0c 0xf0 body maps 1:1 into rec+0x18 (char-id
   @+0xc8, class @+0xca land where FUN_005b5ac0 dedups). Cross-check against a savestate seat
   (0x6c7c2c+0x24 / 0x700734) for a correctly-rendered member.
4. nora review, then rig: both consoles show the RIGHT character on the splash + in-room roster.
Risk note: this writes real bytes into the working member-JOIN path; a wrong offset = wrong/MARK
char (the T24/T25 failure mode). Hence flag-gated + byte-mapping verified + nora BEFORE deploy.

## CAPTURE POINT + full op-0c timeline (wire rig4, 2026-08-26)
op-0c is overloaded on opcode 0x0c: the char-select CHANGE_USER_PROPERTY (body 0xf0/240 bytes) vs
the connect/create ROOM_QUERY (body 244) and create-prepare. Discriminate the char-select by
**body length == 0xf0 (240)**. Full joiner (PS2) timeline last cycle:
  +629.49 op-0c 240 | +630.69 op-06 4 (AREA enter) | +635.33 op-0c 240 (char-select) |
  +635.37 op-06 24=0x18 (ROOM-ENTER / the seat) .
The seat op-06 (0x18 body) is 40 ms AFTER the joiner's last char-select op-0c -> the server holds
the joiner's 0xf0 blob when it seats -> the fanout member-JOIN to the host can carry it with NO
defer. (Host PC same shape: op-0c 240 precedes its op-06.)

CAPTURE: in #onRoomQuery, when message.payload.length === 0xf0, store Buffer.from(message.payload)
as the session's latest charstats (this is where the reverted SNAP_PROPERTY_RELAY hooked - but we
STORE, never relay). EMIT (behind SNAP_CHARSTATS_SEED) at the 3 member-record sites in
#sendJoinFollowUps, each with the SUBJECT session's stored blob (joiner-own = this; roster-to-joiner
= each existing member's; fanout = this). Edge case (char change AFTER the seat op-06): not covered
by seat-time capture; the last-before-seat blob is used. buildMemberJoinPayload already accepts the
charstats param (committed 7585f4b3); wiring waits on the BYTE-MAP VERIFICATION (payload 0xf0 ->
rec+0x18, char-id @+0xc8).

---

# BYTE-MAP VERIFICATION (2026-08-26) — verdict for SNAP_CHARSTATS_SEED

Traced to the actual copy loops on BOTH sides (not xref counts). All offset arithmetic checked.

## VERDICT (one line)
`rec+0x18[0x00..0xf0) = op0c_body[0x00..0xf0)` **VERBATIM. No offset, no transform, no fixed byte.**
char-id lands at rec+0x18[+0xc8], class at rec+0x18[+0xca] — exactly where FUN_005b5ac0 dedups and
where the sub-7 slicer reads. **Confirmed** on both sides.

## SEND side — op-0c app body layout (Confirmed)
`FUN_005b3790.c` case0/sub2 builds the char-select blob `auStack_f0` (base −0xf0), then
`FUN_005bd940(auStack_f0, 0xd4, 0x5b52e0)`:
- `memset(auStack_f0, 0, 0xd4)` then `func_0x007de670(auStack_f0)` fills the stat body.
- Explicit tail writes (offsets derived from the stack frame, verified by arithmetic):
  - `uStack_28 = uRam00874f38` -> **buf+0xc8 = char-id (u16)**
  - `sStack_26 = cRam00874f3a` -> **buf+0xca = class (u16/s16)**
  - `uStack_24 = bRam00874f37` -> buf+0xcc
  - `uStack_22 = bRam00343625` -> buf+0xce
- `FUN_005bd940` (`FUN_005bd940.c`): `memset(0x7004d0,0,0xf0)`; `memcpy(0x7004d0, buf, 0xd4)`;
  `memcpy(0x7005b0=body+0xe0, 0x7005c0, 0x10)`; then `func_0x001de470(conn, 0x7004d0, cb=0x5bd8c0)`.
  So the transmitted scratch at 0x7004d0 is a **0xf0** buffer: `[0x00..0xd4)`=charstats,
  `[0xd4..0xe0)`=zero pad, `[0xe0..0xf0)`=16 aux bytes.
- Wire framing = `FUN_001de470.c`: cmd **0x0c**, who **0xa000**, body copied **verbatim (no swap)**,
  length = `*(u16*)(conn+0x64)`.

### 0xd4 vs 0xf0 — RECONCILED
- 0xd4 = the internal build buffer / the `memcpy` length inside FUN_005bd940. It is NOT the wire len.
- 0xf0 = the transmitted scratch size (`memset 0xf0` + the `+0xe0..+0xf0` aux copy). The presence of
  the `+0xe0` aux copy proves bytes past 0xd4 are meant to go on the wire, so **the app body is 0xf0**,
  matching the task's pcap observation (240 bytes). Grade: wire=0xf0 **Confirmed** (pcap + 0xf0 scratch
  construction). Residual: the literal value of `conn+0x64` isn't read in these decompiles; if it were
  0xd4 the last 0x1c bytes wouldn't transmit. This does NOT affect the verdict — char-id(0xc8)/
  class(0xca) sit inside [0..0xd4), covered under either length. (See "Uncertainty" below.)
- **No id/len prefix.** The app body starts at charstats[0]; the task's wire heads
  (`7229000019000000...` / `775b000019000000...`) are `func_0x007de670`'s stat bytes at body[0], not a
  header. char-id is deep at +0xc8, not visible in the head.

## RECEIVE side — what rec+0x18 must contain (Confirmed)
`FUN_005bb4d0.c` (op-06 handler): `memset(0x6cd672,0,0x114)`; fills name; then
`memcpy(0x6cd696, param_2+0x18, 0xf0)`. `0x6cd696 = 0x6cd672 + 0x24`, i.e. **wire rec+0x18 becomes the
record's charstats field at internal +0x24**. Fires event 0x1f -> FUN_005b5ac0.

`FUN_005b5ac0.c` (seat/dedup): `FUN_005c0920(auStack_120)` copies the whole 0x114 record from
0x6cd672 into the stack (name@+0, id/flags@+0x10, charstats@+0x24=`auStack_fc`). Then
`memcpy(auStack_200, auStack_fc, 0xd4)` — this aliases the dedup keys:
- `sStack_138` (char-id key) = auStack_200+0xc8 = **charstats+0xc8**
- `sStack_136` (class key)  = auStack_200+0xca = **charstats+0xca**
Dedup compares against seated entries at `0x6c7d18`/`0x6c7d1a` = seat charstats(0x6c7c50)+0xc8/+0xca.
On seat: `memcpy(0x6c7c50 + slot*0x3b0, auStack_fc, 0xf0)` — the full **0xf0** charstats blob is stored
at seat+0x24. So the seat needs a full 0xf0 blob and reads char-id/class at +0xc8/+0xca.

Arithmetic (shell-verified): send char-id buf+0xc8 / class buf+0xca == recv key blob+0xc8/+0xca ==
seated seatcs+0xc8/+0xca. Record charstats field = rec+0x24 (internal), seat charstats = seat+0x24.

## THE COPY SPEC (implement exactly)
```
rec+0x18[0x00 .. 0xf0)  =  captured_inbound_op0c_body[0x00 .. 0xf0)   // verbatim, byte-for-byte
```
- src offset 0, dest offset 0 (within rec+0x18), length 0xf0.
- char-id (u16 LE) at rec+0x18[+0xc8]; class (u16 LE) at rec+0x18[+0xca]. No swap (PS2 LE both sides).
- **No fixed bytes.** The `body[0xe5]=1` marker from the prior RE belongs to Path B (the translated
  op-0c relay into the 0x6cdbe6 DISPLAY table so the redraw fires); the op-06 seat path (FUN_005b5ac0)
  needs no marker in charstats — the seat "takes" on the record+0x10 flag region and the empty-slot
  search, independent of charstats content. Do NOT set body[0xe5] in rec+0x18.
- If the server only captured a 0xd4-long inbound body, pad `[0xd4..0xf0)` with zeros; char-id/class
  still land correctly. Preferred: capture and echo the full inbound body length (0xf0) verbatim so the
  sub-7 slicer's last chunk (0xc8..0xf0) carries the client's real aux bytes rather than zeros.

## Grades
- Send layout char-id@0xc8 / class@0xca (FUN_005b3790 tail writes): **Confirmed** (frame-offset verified).
- Wire = cmd 0x0c, verbatim, len=conn+0x64 (FUN_001de470): **Confirmed**; app body = 0xf0: **Confirmed**
  (0xf0 scratch + `+0xe0` aux copy + task pcap).
- Recv rec+0x18 -> record+0x24 -> seat+0x24, dedup keys at +0xc8/+0xca (FUN_005bb4d0/005c0920/005b5ac0):
  **Confirmed** (copy loops, offset arithmetic).
- 1:1 verbatim map, no transform, no fixed byte: **Confirmed**.
- That the full-0xf0 verbatim blob also renders the correct splash (sub-7 5-chunk slice over 0x00..0xf0):
  **Likely** (byte source correct; end render still needs the rig/PINE check already in the plan).

## Uncertainty (what a wire/PINE check would nail, not blocking)
- Literal `conn+0x64` value at op-0c send time (0xd4 vs 0xf0) — decides whether bytes [0xd4..0xf0) of
  the client's op-0c actually reach the server. Confirm from the existing 240-byte pcap body (task
  states 0xf0; a `wc -c` on the captured app body settles it). Irrelevant to char-id/class placement.
- Whether the sub-7 render meaningfully consumes [0xd4..0xf0) — if the splash is correct with a
  0xd4-real + 0x1c-zero blob, capture length is moot. Falsifier already in the plan's experiment.
