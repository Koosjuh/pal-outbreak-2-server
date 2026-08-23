# RS1 — Question C: chat not rendered, count not decrementing, room-exit stall

Evidence doc, 2026-08-08 (RS1 rig session, window 17:25–17:50 UTC).
Sources: `captures/v2-live/RS1-20260808-172534.pcap` (PS2 = 192.0.2.129 `real`, emulator =
192.0.2.248 `test123`, server = 192.0.2.121, UDP 9090), the Pi journal for the same window
(`journalctl -u pal-server-v2 --since '2026-08-08 19:25'`), the deployed
`feat/v2-bioserver-port` code (ea972c74), `analysis/LOBBY-CHAT-AND-ACTIONS.md` (the op-0x0F
receive-path RE), `docs/design/v2-port/B3-LEAVE-TWICE-EVIDENCE.md` (the exit contract), and the
JP reference `references/bioserver/.../bioserv2/bioserver/PacketHandler.java`.
Owner observations: `docs/design/v2-port/RIG-SESSION-1.md` Results.

Every claim is graded **O**bservation / **I**nference / **H**ypothesis / **C**onclusion.
Evidence ranking: wire > decompile > corpus notes. No server code was changed for this doc.

---

## C1 — chat is relayed, delivered, transport-acked … and silently dropped by the client dispatcher

### The wire, byte for byte (O)

One real chat line was typed in RS1 (emulator, lobby screen, text `1234`):

```
17:34:09.618  .248 → server   flags=0xB421  sub=0 op=0x0F seq=276
              body[17] = 02 00 07 04 00 00 "test123" "1234"
17:34:09.621  server → .129   flags=0xB021  sub=0 op=0x0F seq=61      ← the relay
              body[17] = 02 00 07 04 00 00 "test123" "1234"
17:34:09.644  .129 → server   transport ack of seq 61                 ← PS2 received it
```

Diff of the relayed copy against the original:

| field | inbound (.248→srv) | relayed (srv→.129) | verdict |
|---|---|---|---|
| body (all 17 bytes: type=2, sel=0, nameLen=7, textLen=4, name, text) | `0200070400007465737431323331323334` | identical | **byte-perfect** (O) |
| sub-selector | 0 | 0 | correct (O) |
| sequence | 276 (sender's channel) | 61 (recipient's channel, correctly re-stamped) | correct (O) |
| flags word | **0xB421** = `0x8000 RELIABLE \| 0x2000 \| 0x1000 \| 0x0400 \| len 0x21` | **0xB021** = `0x8000 \| 0x2000 \| 0x1000 \| len 0x21` | **the `0x0400` bit is missing** (O) |

The journal line (`17:34:09.620 lobby-chat … textBytes:4 relayed:1`) and the pcap agree: the
server did everything the relay spec asks — verbatim body, sender excluded, correct scope
(both consoles were in box 4, area scope), fresh sequence — except the flags. (O)

### Why the missing bit is fatal (decompile — `LOBBY-CHAT-AND-ACTIONS.md` §3.1)

The client's op-0x0F receive dispatcher `FUN_001D9F78` case 0x0C routes **on the flags**:

```
if ((flags & 0x1000) == 0) {
    if (flags & 0x0400)  → slot 0x0B  FUN_005BC590   (the chat parser)
    else if (flags & 0x8000) → slot 0x12  (not installed)
    else                     → slot 0x14  (not installed)
} else if (flags & 0x0400) → slot 0x0D  FUN_005BC590   (same parser)
```

Our relay has `0x1000` SET and `0x0400` CLEAR — the `else if (flags & 0x0400)` fails and there
is **no branch at all**: the datagram is consumed by the transport (hence the ack at +23 ms)
and never handed to any application slot. `FUN_005BC590` never runs, the display block at
`0x6FC05A` is never written, UI event 5 never fires. "Chat doesn't work" on the receiving
screen with a clean ack on the wire is exactly this. (**C** — wire + decompile agree, no other
difference exists between the two datagrams.)

### Where the bit is lost in our code (O)

- `server-v2/src/protocol/snap-codec.js:14-19` defines `FLAG_AGGREGATE 0x0800`, `FLAG_DATA
  0x1000`, `FLAG_SET 0x2000`, `FLAG_ACK 0x4000`, `FLAG_RELIABLE 0x8000` — **there is no
  0x0400 constant anywhere in server-v2.** The "string body" bit the chat path needs was never
  modelled.
- `snap-lobby-session.js:1457-1465` `deliverChat()` calls `#send` without a `flags` argument;
- `snap-lobby-session.js:2077-2081` `#send` defaults to `FLAG_SET | FLAG_DATA` = 0x3000, and
  `transport/reliable-channel.js:816` ORs in `FLAG_RELIABLE` → wire 0xB0xx.

Note the near-miss: the corpus relay spec (`LOBBY-CHAT-AND-ACTIONS.md` §1.1/§2.2) is
`0xB400|len` (area) / `0xA400|len` (room). Our default 0xB000 *happens* to carry the area-scope
`0x1000` bit — because our unrelated `FLAG_DATA` constant has the same value — so for area chat
the flags are wrong by exactly one bit. For ROOM chat the current default would be wrong by two
bits (`0x0400` missing AND `0x1000` wrongly set, which reroutes to slot 0x0D — same handler, so
probably harmless, but not what the client itself emits). (O for the values; **I** for the
room-scope harmlessness.)

### Fix (concrete, not yet applied)

1. `snap-codec.js`: add `export const FLAG_STRING = 0x0400;` (the client's "string body /
   NUL-terminate and route to chat slots" bit).
2. `snap-lobby-session.js` `deliverChat()`: send with
   `flags: FLAG_SET | FLAG_STRING | (areaScope ? FLAG_DATA : 0)` — scope taken from the same
   presence decision `#relayChat` already makes (`snap-lobby-sessions.js:379-390`: room if the
   sender is in one, else area). Result on the wire: `0xB4xx` area / `0xA4xx` room — exactly
   the datagrams the client itself emits and the JP `broadcastChatOut` equivalence in the
   corpus doc §4.
3. Falsifier on the next rig line: the relayed datagram shows `flags & 0x0400` set, and the
   line appears once on the receiving console (PINE: `0x6FC06A` = sender name, `0x6FC07E` =
   text, ring index `iRam003435D4+0xC9358` increments).

Room-chat caveat, unchanged from the corpus doc §3.3: even with the flags fixed, a line typed
**inside a room** renders only if the sender's name strcmp-matches a populated row of the
4-slot member table filled by the op-0x0a reply — lobby (screen 2) chat has no such gate, so
the flags fix alone should make LOBBY chat visible. (O from decompile.)

---

## C2 — the lobby count: the server decrements correctly; nothing ever tells the client

Owner report (R1): "When leaving the lobby the count stays 2 so it doesnt go down."

### The server side is not the defect (O, wire + journal + code)

- All **15** op-0x07 leaves in the journal were `answered:true` and each moved the presence up
  one level (`depth 2 → 1`, or `4 → 2` for the in-room one). Handler:
  `snap-lobby-session.js:1949-1984` `#onLeave` → `presence.ascend()`
  (`state/presence.js:380-389`), which routes through the single `#write`
  (`presence.js:458-477`) that removes the presence from the `#byArea` bucket. Counts are
  derived live from those buckets (`countInArea`, `presence.js:249-251`;
  `playersIn`, `snap-lobby-sessions.js:325-327`) — there is no stored counter to go stale.
- **Wire proof that the published counts decrement:** the op-0x48 reply records (per-area
  population at record `+0x10`) tracked every membership change within one poll:

  ```
  17:33:25.755 → .129  AREA0004=1                      (test123 entered box 4)
  17:35:44.858 → .248  AREA0004=1                      (after test123's own leave — its next
                                                        reply already excludes itself)
  17:37:06.915 → .129  AREA0004=0  AREA0001=1          ← 233 ms after real's 17:37:06.681 leave
  17:44:34.866 → .248  all ten areas = 0               (everything drained)
  ```

- The op-0x09 `USER` replies were also correct at every query instant. The one that looks
  wrong at first sight — `real` querying box 1 at 17:37:09 and getting **2** three seconds
  after leaving box 4 — is correct: the journal shows `real`'s op-0x06 ENTER into box 1 at
  17:37:08.477, before the query. Both consoles were in box 1. (O)

**Conclusion: presence IS detached on every leave path; the count the server publishes goes
down within a poll interval. The stale "2" is a display that nothing refreshes.** (C)

### What actually goes stale (I + reference)

The number the owner watches on the lobby screen is populated by the client's own **op-0x09
`USER` query, issued once at lobby entry** (journal: every `lobby-area-count` sits in the
enter → probe → query volley; none is ever re-issued while a client sits in the lobby). The
op-0x48 poll that carries live populations only runs on **Area Select**. So when the OTHER
player leaves, the remaining player's "2" is a client-side latch with no refresh stimulus.
(**I** — consistent with every query in the journal; the client-side render source is corpus
`FUN_005c0060` slot-0x16, a reply handler, not a spontaneously polled channel.)

The JP server closes exactly this gap with a push. `bioserv2 PacketHandler.java`:

- `sendExitArea` (line 1136) → **`broadcastAreaPlayerCnt`** (line 661): builds
  `AREAPLAYERCNT = 0x6205` with the fresh counts and **broadcasts it to everyone in the area
  and on Area Select** (`broadcastInAreaNAreaSelect`) — comment in source: *"let other clients
  know in area selection screen and area"*. The same broadcast fires on area JOIN (line 746)
  and its room-level sibling `broadcastRoomPlayerCnt` fires on every slot/room transition
  (lines 836, 1133, 1936, 2019). (O — reference source)

Our v2 server answers count queries and pushes nothing. That is the architectural difference,
and it reproduces the owner's symptom exactly. (**C** for the difference; **H** for it being
the whole symptom.)

### Fix direction (needs one RE answer first)

The PAL vehicle for an unsolicited count update is **not yet identified** — candidates, in
order of plausibility:

1. an unsolicited op-0x09-shaped `USER` reply (works only if the client's slot-0x16 callback
   `FUN_005c0060` is installed persistently rather than armed per request — one Ghidra look at
   `FUN_001d84cc`'s task matching settles it);
2. the op-0x10 sub-0x11 / sub-0x05 member-count pushes for the ROOM-level counts (already
   RE'd, `LOBBY-CHAT-AND-ACTIONS.md` §7) — these do not cover the area-lobby header;
3. no push exists in PAL and the JP behaviour was TCP-era only — in which case the count is
   refreshed on the next screen rebuild and the correct statement to the owner is "the number
   updates when you re-enter the screen".

Do the slot-0x16 persistence check before writing any code; pushing an op-0x09 reply at an
unarmed client is exactly the kind of guess CLAUDE.md rule 3 forbids. (**H** throughout.)

---

## C3 — the room-exit stall: a THIRD exit message class, answered but not accepted

Owner report (R9 note): "When creating a lobby and pressing Exit though i couldnt leave that
is in save state slot 7."

### The window (O — journal + pcap agree to the millisecond)

```
17:45:24.083  .248 op-0x04 create  → accepted: room handle 5, box 3, "ROOM",
                                     requestedMaximum 1, options 0xfffffffe
17:45:24.086  server: op-0x28 sel-4 accept + op-0x06 create-self echo + op-0x10 sub-5 (max 4 / cur 1)
17:45:24.163  .248 op-0x0a member list (answered, 1 member) + op-0x09 USER/MAXI for 5
              (resolved as room: 1 / 4, answered)
17:45:31.762  .248 op-0x08 "STAT@" (flags 0xA818)            ← the Exit press
17:45:31.762  .248 op-0x07 ZERO body, flags 0xA010, seq 0    ← the Exit press, part 2
17:45:31.767  server: op-0x28 sel-8 STAT completion (seq 152)
              server: op-0x28 sel-7 status 0, echo +0xc = 0  (seq 153)
              journal: lobby-leave from {box 3, room 5, slot 0, depth 4} → depth 2, answered:true
17:45:31.842  .248 transport-acks seq 152
17:45:31.861  .248 transport-acks seq 153                    ← the client RECEIVED both replies
17:45:34 – 17:47:44   NOTHING but op-0x40/0x41 keepalive ping-pong (39 exchanges) and one
                      op-0x14 probe at 17:46:43. No chat-probe, no op-0x48, no op-0x02,
                      no retransmit of the op-0x07 — the lobby SM is parked.
17:47:44      last client datagram (the owner froze the VM into savestate 7 around here — I)
17:50:34      server idle-release, presence 8 detached from {box 3, depth 2}
```

### This is a different message class from both of tonight's fixed paths (O)

Every one of the **14 area leaves** in RS1 — including the owner-confirmed-working R9
leave-enter-leave sequence — looks like this:

```
op-0x07  flags 0xB010  seq = live transport sequence (15, 25, 37, 48, … / 255 on the PS2)
```

The in-room Exit is the only one of its kind in the capture:

```
op-0x07  flags 0xA010  seq = 0
```

- `0xB010` vs `0xA010`: the **`0x1000` bit is CLEAR** on the in-room variant. This is the
  same DATA/scope bit that distinguishes area-scoped from room-scoped chat (§C1), and matches
  `snap_send_leave`'s `who = 0xB000` being replaced by a `who = 0xA000` call site the corpus
  has not yet identified. (O for the bytes; the sender call site is **Unknown**.)
- **`seq = 0`**: every other reliable message from this client in this epoch carries a live
  sequence (the STAT sent in the same millisecond is seq 170). Whatever emits the 0xA000
  variant does not stamp the transport sequence. (O)
- It is **not** an op-0x02 transport close, so `SNAP_EXIT_CLOSE_MIRROR` (which only answers
  op-0x02 — `snap-lobby-session.js:199,292,391` / `config/server-config.js:355`) never
  engages and is irrelevant to this stall. B3's area-side exit contract
  (`B3-LEAVE-TWICE-EVIDENCE.md` §1: op-0x07 once, op-0x02 ever after) was owner-confirmed
  WORKING tonight (R9) — this in-ROOM Exit is a third path that doc did not cover. (C)

### Why the answered leave did not release the client (H — two candidates, one discriminator)

The server answered with the deployed B3 fix 2 shape: op-0x28 sel-7 status 0, 16-byte payload,
**request send-seq echoed at `+0xc`** (`SNAP_COMPLETION_SEQ_ECHO`, `#onLeave`
`snap-lobby-session.js:1957-1970`). Tonight's working area leaves show the echo live and
little-endian (`seq 15 → 0f000000`, `seq 255 → ff000000`) — and for THIS leave the wire
sequence was 0, so we echoed **0**.

Per the B3 doc §3, the client's release path is: `FUN_005bfe90` latches
`0x6cbc80 = (u16)reply[+0xc]`, then `FUN_005be120` sweeps the 128-slot request pool at
`0x6ca980` for `sendSeq == 0x6cbc80 && id == 0x6cbc7c` — **only a match fires the parked
continuation** (the leave pump `FUN_005c1c80` step-3 release).

- **H1 (echo-key mismatch):** the 0xA000-variant leave's pool entry carries a real, nonzero
  internal send-seq that this variant simply does not stamp into the wire header. Our faithful
  echo of the wire field (0) then never matches, the sweep fails, the slot leaks, and the
  client parks in step 3 forever — music on, keepalives answered, cursor dead. This is
  exactly the observed behaviour.
- **H2 (wrong completion class):** the room-scoped leave expects a completion the server has
  never sent — e.g. the sel-7 reply mirrored with the request's `0x1000` bit CLEAR (ours went
  out `0xB020`, DATA set — the op-0x28 inner dispatch is documented as "selector − 1, with
  the DATA flag set" (`snap-lobby-session.js:1936`), so a DATA-clear request may want a
  different slot entirely), or an op-0x10 room-membership push, or a room-close notification.

Nothing on the wire discriminates H1 from H2. **Savestate slot 7 does** — it was frozen at
the exact stall. One PINE read set against it:

| addr | meaning | H1 predicts | H2 predicts |
|---|---|---|---|
| `0x6cbb6c` / `0x6cbb68` | leave pump armed / step | 1 / 3 (parked in the wait) | pump never armed (0 / –) |
| `0x6cbc80` | latched reply word | 0 (our echo) | 0 or unset |
| `0x6cbc7e` / `0x6cbc7c` | completion kind / id | 2 / id | – |
| pool `0x6ca980` (stride 0x20, id `+0x1c`, sendSeq `+0x1e`) | the leave txn's slot | a LIVE entry whose sendSeq ≠ 0 | no op-0x07 entry at all |

If the pool holds a live op-0x07 slot with a nonzero sendSeq, H1 is confirmed and the fix is
knowable (answer the 0xA000-variant with that key — which requires finding where the client
puts it, likely the sub-selector or a body field of a sibling message; NOT guessable). If the
pump never armed, this exit never was an op-0x07-pump transaction and the whole in-room exit
flow needs its own RE pass (the `who=0xA000` sender call site first).

### Server-side status quo for this path (O)

`#onLeave` treated the 0xA010 leave identically to an area leave: one `ascend()` (which
correctly cleared slot+room in one move, room 5 emptied and closed via `onRoomEmptied`) and a
sel-7 completion. The presence side is right; the reply contract for this variant is the open
question. **Do not "fix" this by echoing a guessed nonzero value** — a wrong key that happens
to match a stale pool slot would fire the wrong continuation.

---

## Summary

| break | root cause | grade | fix |
|---|---|---|---|
| C1 chat not rendered | relay flags `0xB021` lack the `0x0400` routing bit; client dispatcher has no branch for `0x1000+RELIABLE` without `0x0400` → dropped after transport ack | **Conclusion** (wire + decompile) | add `FLAG_STRING 0x0400` to `snap-codec.js`; `deliverChat` sends `0xB4xx` area / `0xA4xx` room |
| C2 count stays 2 | server counts are live and decrement on the wire (proven); the client's lobby-header count is latched from its one op-0x09 query at entry and NOTHING pushes an update — JP bioserver broadcasts `AREAPLAYERCNT 0x6205` on every area enter/exit, v2 has no analogue | **Conclusion** (server correct) + **Hypothesis** (push is the cure) | first RE: is client slot 0x16 persistent? then port `broadcastAreaPlayerCnt` on the enter/leave paths |
| C3 room-exit stall | in-room Exit = a third exit class: op-0x07 `flags 0xA010, seq 0` (not `0xB010`, not op-0x02); answered sel-7 with echo 0, client acked but never released | **Observation** (class) + two **Hypotheses** (echo-key mismatch vs wrong completion class) | PINE-read savestate slot 7 (table above) — one read set decides; no server change until then |

Not covered here (parked): the rules-still-red and scenario-lock complaints in the owner's
Result note — separate causes already identified in `snap-lobby-session.js:1360-1366`
(mode masks in `state/area-table.js`; savedata bitmap `0x341AD0`), outside Question C's scope.
