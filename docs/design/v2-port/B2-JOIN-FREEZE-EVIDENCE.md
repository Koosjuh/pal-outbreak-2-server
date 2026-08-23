# B2 — the JOIN freeze: wire evidence and root-cause model (T37, 2026-08-08)

Investigated from `captures/v2-live/T37-20260808-090328.pcap` (contains BOTH consoles)
and `T37-20260808-090328.journal.log`. Server = 192.0.2.121 (`S`), PS2 = 192.0.2.129,
emulator = 192.0.2.248, SN@P on UDP 9090. All times UTC. Byte layouts per
`server-v2/src/protocol/snap-codec.js` (16-byte header `[flags+len u16 BE][sub u8][op u8]
[token u32][seq u32][ack u32]`, trailer `ba476611`).

Every claim below is classified. Evidence rank: runtime > memory > wire > decompile > notes.

---

## TL;DR (Conclusion)

**The PS2 was not waiting for a new, unknown message type. It was waiting for op-0x49
room-list replies to queries it HAD sent — queries the server acknowledged and then
silently swallowed.** The client coalesces some queries into an aggregate datagram behind
its op-0x41 keepalive-response; those sub-messages carry a garbage/stale sequence field.
The client's own transport ignores a reliable sub-message's sequence and gates the whole
walk on the OUTER message's sequence (`FUN_001d6988.c:44-88`); V2's `reliable-channel.js`
instead runs each walked sub-message through per-message sequence acceptance, so the
garbage sequence (`0x76000000`, `0x7A000000`) is treated as a far-future hole: the message
is **acked, gap-buffered forever, and never dispatched**. The PS2's room-list poll loop is
reply-driven; with every second poll unanswered it degraded from a ~100 ms sweep to 10 s
timeouts and then stopped — the frozen lobby UI.

The same defect is journal-proven to have **killed the emulator's first session outright**
(`gap-abandoned`, buffered `[0x08000000]`, 07:10:39) and to be why the batched post-create
op-0x09 USER/MAXI queries are never answered (their sub-seq is 0).

---

## 1. The exact freeze window — every datagram, byte level (Observation)

`.129` entered box 2 (the box where `.248` had created room handle 0x2 at 07:15:22) and:

```
07:15:27.355  .129→S  op-06 AREA-ENTER, key = box 2   (24B)
              b0140006 028107d0 0000007e 58000000 | 00000002 | ba476611
              (seq 126; the ack field 0x58000000 is stack garbage — healthy requests
               show the same, e.g. box-9's op-08 carried ack 0x0E000000)

07:15:27.356  S→.129  transport ack of seq 126
07:15:27.357  S→.129  op-28 selector 6 (AREA-ENTER ACCEPT), seq 112   (28B)
              b0180028 028107d0 00000070 00000000 | 00000006 00000000 | ba476611

07:15:27.405  .129→S  op-0F area-name probe (sel 1, "OBAREA-V2"), seq 127 — acked
07:15:27.505  .129→S  op-49 ROOM-LIST query #1, seq 128, STANDALONE   (63B)
              b03b0049 028107d0 00000080 00000000 |
              000000fa 0310388f "LOID" 01000000 02 "STAT" 21000800 00000800 00
                                                   "STAT" 21020000 00020000 00 | ba476611
07:15:27.506  S→.129  transport ack 128
07:15:27.507  S→.129  op-49 REPLY rooms:1, seq 113   (72B)
              b0440049 028107d0 00000071 00000000 |
              00000000 00000000 00000001            (hdr: 0, 0, count 1)
              "ROOM"+16×00                          (name, 0x14 bytes)
              00000001                              (+0x14 current = 1, BE)
              00000000 00000000                     (+0x18, +0x1c flags = 0)
              00000004                              (+0x20 max = 4, BE)
              02000000                              (+0x24 handle = 2, LE) | ba476611
07:15:27.555  .129→S  ack of 113                    (the reply WAS received)

07:15:27.560  S→.129  op-40 keepalive seq 0x10
07:15:27.600  .129→S  215B AGGREGATE — op-41 keepalive-response seq 129 (fl b898,
              0x0800 set, len 0x98) + op-49 ROOM-LIST query #2 as sub-message:
              ... 6a3c4b8e13e5bf24 | b03b0049 028107d0 76000000 00000000 |
              000000fa 0310388f "LOID" 01000000 02 "STAT" 21000800.. "STAT" 21040000..
              | ba476611
              → sub-message BYTE-IDENTICAL to a standalone query except
                seq = 76 00 00 00 (0x76000000 BE / 118 LE)
07:15:27.601  S→.129  ack 129        (the keepalive half — answered, journal logs it)
07:15:27.601  S→.129  ack 0x76000000 (the op-49 half — ACKED AND NEVER ANSWERED)

07:15:32.605  .129→S  op-41 seq 130 (plain keepalive-response) — acked
07:15:37.550  .129→S  op-49 query #3, seq 131, STANDALONE ("STAT" 214000.., 210200..)
07:15:37.555  S→.129  ack 131 + op-49 REPLY rooms:1, seq 114 (identical record) — acked
07:15:37.629  .129→S  215B AGGREGATE again: op-41 seq 132 + op-49 query #4 as
              sub-message, sub-seq = 7a000000 ("STAT" 21000800.., 21080000..)
07:15:37.630  S→.129  ack 132 + ack 0x7A000000 — again ACKED AND NEVER ANSWERED

07:15:42 → end of capture (07:22:17): .129 sends ONLY op-41 keepalive-responses
              (seq 133, 134, … ≥154) plus one non-reliable op-14 RTT probe at
              07:16:49.598. No op-49, no op-09, no op-0a, no op-06. UI frozen.
```

Journal cross-check (Observation): exactly two `lobby-room-list rooms:1` events for
`.129` box 2 (07:15:27.506, 07:15:37.554) — matching the two STANDALONE queries.
The two aggregated queries produced **no journal event at all**: walked, acked, dropped.
No refusal of any kind was logged for `.129` in the window.

So, precisely per the task deliverable:

- **The exact last non-keepalive thing `.129` sent** = the 215-byte aggregate at
  07:15:37.629: op-41 keepalive-response (seq 132) + op-49 room-list query
  (sub-seq `7a000000`, "LOID" box 2, "STAT" masks 0008/0800).
- **The exact server bytes it received afterwards** = transport acks (`60100000 …
  00000084`, `… 7a000000`) and op-40 keepalives every 5 s. Nothing else. No op-49
  reply for queries #2/#4, and no refusal.

---

## 2. What a WORKING selection looks like on the same wire (Observation)

Both consoles produced a healthy reference in the same capture, box 9:

`.129` box 9 (07:06:03, rooms:0): op-06 key 9 → op-28 sel-6 → op-0F probe → then a
reply-driven **sweep of 8 standalone op-49 queries ~85–120 ms apart**, each answered
(28B empty list), each next query fired ~60–120 ms after the previous REPLY. The sweep
walks the two "STAT" filter masks through 0x0008/0x4000 × 0x0200/0x0400/0x0800/0x1000.
Then op-09 `USER` (box count) → answered. Then a slow ~6–10 s op-49 poll. The owner
could navigate; he created a room from this screen at 07:06:18.

`.248` box 9 (07:07:42, rooms:1 — the identical 72B reply shape as the freeze window,
handle `01000000`): the same 9-query sweep, all standalone, all answered, then op-09
`USER`, then at 07:07:47.649 the room-selection query:

```
07:07:47.649  .248→S  op-0a MEMBER-LIST, seq 37: a0140006-style 24B, payload 01000000
              (room handle 1, LITTLE-endian — the handoff §4 byte-order fact)
07:07:47.652  S→.248  op-0a reply seq 33 (296B): handle echo, count 1, member "real",
              memberId 1, blobLen 0xF0, charstats ALL ZERO — acked by .248
07:07:47+     .248 sends NOTHING but keepalives for 142 s
07:10:09.206  .248→S  op-02, reliable, empty body (b0000002 … seq 67 ack-field 27) —
              server has no handler ("lobby-observed-message"); after this the client
              stopped answering keepalives entirely (5 unanswered op-40s)
07:10:39      server: transport-dead gap-abandoned → session closed, presence detached
```

Two facts fall out (Observation):

1. **The rooms:1 reply itself is not the freeze trigger** — `.248` received the same
   72B shape nine times and kept sweeping normally. What distinguishes `.129`'s frozen
   window is solely that its sweep queries #2/#4 were coalesced into keepalive
   aggregates and never answered, turning the ~1.2 s sweep into 10 s stalls.
2. **There is a SECOND, later stall on the join path**: after the op-0a member-list
   reply, `.248` sent nothing — no op-06 ENTER-with-handle, no op-10 sub-0x02
   join-request (the July flow in `G12-joiner-tag17-RE-2026-07-16.md` shows those as
   the next steps). See §5.

---

## 3. Root cause mechanism, server side (Conclusion — code + wire + journal)

`server-v2/src/transport/reliable-channel.js`:

- `acceptDatagram` walks a batch when the first message declares `0x0800` (correct), but
  then feeds EVERY walked sub-message through `#acceptReliable` individually
  (lines ~578-601).
- `#acceptReliable` acks the sub-message's own `seq`, and because `0x76000000` ≫
  `receiveBase` (~130), puts it in the **gap buffer** to await sequences 130 …
  0x75FFFFFF (line ~661). It is never delivered; `session.accept()` only dispatches
  `result.delivered`. The wire shows precisely this signature: **ack sent, no reply,
  no journal event**.
- The gap entry arms a 30 s expiry (`DEFAULT_GAP_EXPIRY_MS = 30_000`). Delivery
  progress re-arms it, so a client that keeps sending keepalives keeps the session
  alive with phantom holes — until any ≥30 s quiet spell. `.248`'s first session hit
  exactly this: its op-48 Area-Select poll at **07:07:37.729** was coalesced behind an
  op-41 with sub-seq `0x08000000`, gap-buffered; when the client wedged at 07:10:09
  the timer ran out → `gap-abandoned`, `buffered:[134217728]` (journal 07:10:39.086).
  134217728 = 0x08000000 — the arithmetic matches to the byte.

Related same-family defect (Observation): the post-create batch (op-0a + op-09 USER +
op-09 MAXI) carries sub-seq **0** on both op-09s. Seq 0 < receiveBase → classified
`duplicates` → acked, dropped. T37's journal confirms: **no `lobby-area-count` event
follows either create** (07:06:18 `.129`, 07:15:22 `.248`); the only area-count events
are standalone queries at other times. The handoff §3 claim "the three post-create
queries are answered" is true only for op-0a (the outer message). This is a plausible
contributor to B4's "No. of Players still reads 1" (Hypothesis).

### Why the garbage sub-seq is the CLIENT's normal behaviour (Conclusion — decompile)

`reverse-engineering/network/sources/executables/transport-decompile/FUN_001d6988.c`
(the client's own datagram acceptor), lines 44-88: when the first message declares
`0x0800` it iterates up to 0x38 sub-headers. For each **reliable** sub-message it uses
`uStack_30` — which was set from the **OUTER** message's `+0x34` sequence — for both the
ack (`FUN_001e16b4`, once, first reliable only) and the in-window test
(`**(param_2+0x5c) <= uStack_30`). **The sub-message's own sequence field
(`uStack_48`) is read only when the outer message was NOT reliable** (then the first
reliable sub's seq becomes the covering value). So on the real protocol, a reliable
sub-message behind a reliable outer is delivered purely on the outer's sequence, and
its own seq field is dead weight — which is why the client never bothers stamping it
(the observed values `0x08000000` / `0x76000000` / `0x7A000000` are deterministic stale
buffer content: `.248` produced the identical `0x08000000` in two separate sessions at
07:07:37 and 07:14:19, same outer seq 17 both times).

**V2's per-sub-message sequence gating is therefore a protocol violation**, not a
hardening: the client is entitled to expect coalesced queries to be processed whenever
the outer message is in-window.

### The fix this implies (Inference, high confidence)

In the walk path: deliver reliable sub-messages under the OUTER message's acceptance
(if the outer was delivered/accepted, dispatch the subs in order; dedupe on the outer
seq), never enter a sub-message into the gap buffer, never count one toward
`gap-abandoned`, and ack only the outer sequence (the client acks once per datagram —
the extra `ack 0x76000000` datagrams V2 sends match nothing on the client and are
noise). `TOO_MANY_MESSAGES` and the parse-degrade rule (handoff §4) stay as they are.

---

## 4. Causal chain for the observed freeze (classification per step)

1. `.129` enters box 2, is accepted, gets a correct rooms:1 list — **Observation**.
2. Its reply-driven op-49 STAT-mask sweep continues; polls that happen to coincide
   with a due keepalive-response are coalesced into one aggregate — **Observation**
   (three independent instances across both consoles).
3. Server acks but never answers the coalesced polls (gap-buffered) — **Conclusion**
   (wire + code + the matching `gap-abandoned` value on `.248`).
4. The sweep stalls 10 s per unanswered poll (27.600→37.550 gap, then 37.629→nothing),
   and after the second loss the client stops issuing queries; the lobby/room-list UI
   never completes and reads as frozen — **Inference** (cadence analysis; the client's
   internal give-up state was not memory-read).
5. `.129`'s transport stayed alive to capture end (keepalive-responses continue, no
   transport-dead for `.129` in the journal) — **Observation**. The freeze is a UI/SM
   stall, not a dead link.

Alternative considered and rejected: "the client was waiting for a push after the
rooms:1 reply" — rejected because `.248` received the identical reply nine times with
no push and progressed normally to room selection (**Observation**, §2).

---

## 5. The next expected exchange — the grounded join model

From `.248`'s healthy segment plus the July RE (`G12-joiner-tag17-RE-2026-07-16.md`,
`G12-joiner-render-RE-2026-07-16.md`), the full join ladder is:

| step | direction | message | T37 status |
|---|---|---|---|
| 1 | C→S | op-06 ENTER (area key) | works, answered op-28 sel-6 |
| 2 | C→S | op-49 sweep (~9 queries, "LOID"+box, "STAT" masks) | **breaks on `.129` — coalesced polls swallowed (§3)** |
| 3 | C→S | op-09 `USER` box count | reached by `.248` only |
| 4 | C→S | op-0a member-list, payload = room handle, **byte order varies** (`.248` sent `01000000` LE) | answered (members:1 "real", zero charstats) |
| 5 | C→S | op-06 ENTER with the ROOM handle (screen 3→4; July: `who=0xa0` op-06) | **never sent in T37 — the second stall** |
| 6 | C→S | op-10, app-payload[0] = 0x02 (join-request) | never reached |
| 7 | S→C | **op-10, app-payload `0C000000 <count>000000`** (join-confirm; fires continuation 0x601300, SM major 5→6) | never reached; this is the rig-confirmed V1 fix (`SNAP_JOIN_OP10_SUBC`, Pi cead951e) |
| 8 | S→C | op-06 member-JOIN records + op-10 sub-0x05/0x11 (roster + counts) | as on the create path |

Step 5's non-arrival on `.248` (142 s of silence after the op-0a reply, then a bare
op-0x02 — an unhandled opcode, plausibly a client-side close/error notice — after which
the client's transport wedged) is **not yet explained**. Hypotheses, unranked evidence:

- **H-A (user-visible dialog never completed):** the room-detail view draws from the
  drawn-roster table `0x6c7c2c`, which ONLY op-06 member-JOIN pushes fill (codec doc,
  `buildMemberJoinPayload`); V2 pushes op-06 only to the creator. A preview stuck on
  "Getting information" would freeze exactly here. (Hypothesis — consistent with the
  codec's data-table/drawn-table split, no direct proof.)
- **H-B (record content gates the join action):** the op-49 record fields V2 zeroes
  (`+0x18`, flags `+0x1c`) or the zeroed charstats in the op-0a reply fail a client
  check that arms the ENTER. (Hypothesis.)
- **H-C (the owner never pressed join there):** cannot be excluded from the wire, but
  the op-0x02 emission and subsequent transport wedge argue the client was stuck, not
  idle. (Hypothesis, weakened.)

**Order of work:** fix §3 first — it is the proven blocker, it also killed a session
outright, and it is upstream of everything else. Then re-run the join on the rig; the
PS2 will complete its sweep and the wire will show which of steps 4/5 fires next and
what (if anything) still stalls. Only then does the op-10 sub-0x0C machinery of step 7
become testable.

---

## 6. Evidence gaps

- `FUN_001d6988`'s walk was read from the archived decompile; the ack-once claim
  (`uStack_30`-gated `FUN_001e16b4`) is straight-line code, but the downstream effect
  of V2's extra garbage-seq acks on the client was not traced (graded harmless noise —
  Inference).
- Why the client's coalesce path leaves the sub-seq unstamped (and what the stale
  values point at) is unknown; irrelevant to the fix since the receiver must ignore it.
- The `.248` second stall (§5): a PINE read at the stalled moment (`0x6c4b90`,
  `0x6c4b9f/0x6c4ba0`, `0x6cbc7e`) or the post-fix rig run is needed to pick among
  H-A/H-B/H-C.
- op-0x02's meaning (client → server, empty, reliable, sent at give-up time) is not in
  the corpus notes consulted; a corpus lookup or decompile of its sender would confirm
  "client-side abort".
- Whether the dropped batched op-09 USER/MAXI replies contribute to B4 is untested
  (fix §3 also fixes those two — their sub-seq 0 becomes irrelevant — so the next rig
  run answers this for free).
