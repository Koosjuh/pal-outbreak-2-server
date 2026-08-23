# RS1 Question B — the join starve and the host's death (2026-08-08)

Evidence: `captures/v2-live/RS1-20260808-172534.pcap` (both consoles; PS2 = 192.0.2.129
"real", emulator = 192.0.2.248 "test123", server = 192.0.2.121, SN@P on UDP 9090,
D904 on TCP 10127), Pi journal (`pal-server-v2`, deployed `ea972c74`,
branch `feat/v2-bioserver-port`), the July V1 reference capture
`captures/g12-joiner/join-window-packets-2026-07-16.txt`, and the deployed code
(`server-v2/src/udp/snap-lobby-session.js`, `snap-lobby-sessions.js`, `snap-lobby-codec.js`).
All times UTC. Framing: 16-byte header `[flags u8][innerLen u8][sub u8][op u8][token u32]
[seq u32][ack u32]`, flag bit 0 = length bit 8, flag 0x08 = aggregate walk, trailer `ba476611`.

Every claim is classified. Evidence rank: wire > decompile > corpus notes.

---

## TL;DR (Conclusion)

1. **The PS2 starved one step further down the ladder than T37** — the B2 §3 transport fix
   is live and working (no coalesced query was swallowed tonight; the op-49 sweep completed
   on both consoles; even the batched post-create op-09 USER/MAXI were answered). The PS2
   selected the host's room, sent the op-0x0a member-list query, **received and acked the
   answer** — and then sent nothing, ever: no op-0x0c, no op-0x06 room-ENTER, no op-0x10
   sub-2. "Getting information" is the client waiting, after a member-list that says
   `count = 1`, for **member information the V2 server never supplies**. 142.6 s later it
   closed its own session (op-0x02) and re-logged — the same give-up interval as T37's
   emulator (141.6 s). This **refutes H-C**, **weakens H-A**, and **supports a refined H-B**
   (§5).

2. **Nothing killed the host from outside — the host killed itself, twice, the same way.**
   At both host deaths the transport was perfect (journal: `keepalivesSent == 
   keepaliveResponses` 86/86 and 28/28, `unacknowledged: 0`, `sendRefusals: 0`; wire: every
   op-40 answered to the last one, no unacked reliable seq, no server push preceding the
   close). Each host session sat silently in its own freshly created room, emitted one
   op-0x14 probe partway, then a **voluntary op-0x02 session close** (72.5 s and 128.4 s
   after create). The "connection error ~5–10 s after the PS2's attempt" is a timing
   coincidence: **zero bytes traversed server→host as a consequence of anything the PS2
   did** (Observation). The host client is starving in its own room on the same
   member-info silence — its op-0x10 sub-1 player-info broadcast got a transport ack and
   no application answer, and it retransmitted it exactly the way the July client
   retransmitted op-0x10s that V1 answered.

3. **The op-0x10 "recipient" word is not a recipient.** Both wire observations that exist
   (July `02f807d0`, tonight `00000003`) are the **sender's own handle** (the value the
   client holds at `0x6febe8` — the room handle from the create path for a creator, the
   member handle delivered by the sub-1 push for a joiner). It is the `handle` argument of
   the client's send frame `func_0x001df380(conn, 0x8000, payload, len, count, handle)`.
   V2's relay (`#relayRoomEvent`) resolves it against roster members' `presenceId` /
   `endpointToken` and skips `target === from` — under the wire-observed semantics that
   construction can **never deliver anything**, and `relayed: 0` is structural, not
   situational.

---

## 1. The PS2's full sequence from room selection (Observation, byte level)

Box-1 context: the PS2 entered box 1 at 17:37:08.476 (op-06 sub-1, key `00000001` →
op-28 sel-6 accept), probed `OBAREA-V3` (op-0F), and ran its op-49 STAT-mask sweep —
**8 standalone queries, 17:37:08.643–09.875, every one answered** with the same 68-byte
rooms:1 record (name "ROOM", current 1, max 4, handle `02000000` LE = room 2, the
emulator's room). op-09 `USER` answered (value 2), a second sweep and op-09 at
17:37:12–13 likewise. Slow poll continued (17:37:57.237 op-49 → rooms:1). No query was
lost anywhere — the T37 §1 aggregate-swallowing signature is absent from the entire
session (Observation; the B2 §3 fix on `ea972c74` is doing its job on the wire).

Then the room selection:

```
17:37:59.560  PS2→S  op-0a MEMBER-LIST, seq 0x123, 24B
              a0 14 00 0a | 028107d0 | 00000123 | 00000000 | 02000000 | ba476611
              (handle bytes 02 00 00 00 — LE room handle 2, the T37 §2 byte-order fact)
17:37:59.562  S→PS2  transport ack of 0x123
17:37:59.562  S→PS2  op-0a REPLY seq 0xea, 296B (fl b1 → innerLen 0x124 = 292):
              02000000            handle echo, verbatim
              00000000            unknownWord 0
              00000001            count = 1  (BE)
              "test123\0"+pad     member name (0x10)
              00000004            memberId
              000000f0            declared blob length 0xF0
              f0 bytes of 00      charstats — ALL ZERO
17:37:59.610  PS2→S  transport ack of 0xea      ← the reply WAS received and accepted
```

Journal cross-check: `lobby-member-list … loginIdentity:"real" handle:"0x02000000"
resolved:true members:1 answered:true` at 17:37:59.562 — and **no further event for
"real"** until the close.

**Where the exchange stops:** right there. From 17:37:59.610 the PS2 sent, for 142
seconds, nothing but op-41 keepalive-responses (seq 0x124…0x140, every server op-40
answered within ~40 ms), plus:

```
17:39:09.318  PS2→S  op-14, fl 0x20 (unreliable), body 01   — probe, absorbed by V2
                     (journal: "lobby-rtt-probe … no reply is known to be expected")
17:40:22.161  PS2→S  op-02, reliable, empty                 — CLIENT-SIDE SESSION CLOSE
17:40:22.163  S→PS2  op-02 mirror (SNAP_EXIT_CLOSE_MIRROR); journal lobby-session-close,
                     presence-detached presenceId:3 reason:client-close
17:40:29–53   PS2 TCP reconnect + full D904 sign-in; 17:40:35 fresh op-2c register
17:41:00.4–01.6  the re-logged PS2 re-sweeps box 1: 8 standalone op-49s, all answered
                 rooms:1 (now room 3), op-09 USER answered 2 — the transport path healthy
```

There was **no op-0x0a retry, no op-0x0c, no op-0x09 after selection, no op-0x06
room-ENTER, no op-0x10 join-request sub-2** — the July ladder (steps 5–7 of
`B2-JOIN-FREEZE-EVIDENCE.md` §5) was never entered (Observation).

Give-up cadence (Observation): selection → op-14 at +69.8 s → op-02 at +142.6 s.
T37's emulator, stalled at the identical point, closed at +141.6 s (07:07:47.649 →
07:10:09.206). Same ~142 s application give-up timer, two consoles, two nights.

Note also: the room the PS2 was "getting information" about died mid-wait — the host's
first in-room session closed at 17:38:12 and its presence detached from room 2
(journal). The PS2 was already starved 12 s before that, so this is aggravation, not
cause (Observation).

## 2. The host's op-0x10 sub-1 datagram, byte by byte (Observation + code)

Host session 3 signed in 17:39:07, created room **3** at 17:39:18.019 (op-04 → op-28
sel-4 `00000004 00000003`; op-06 member-JOIN self-push seq 0x15; op-10 sub-5 limits
push seq 0x16; the post-create aggregate op-0a + op-09 USER + op-09 MAXI **all
answered** — another T37 defect now fixed on the wire). 40 ms later:

```
17:39:18.059  EMU→S  40B
  e0 24 00 10   flags 0xe0, innerLen 0x24, sub 0, op 0x10
  02 f8 07 d0   endpoint token
  00 00 00 19   seq 0x19
  00 00 00 15   header ack word = 0x15 — the op-06 member-JOIN push's seq. This is a
                live cumulative ack, NOT stack garbage (the retransmit 40 ms later
                carries 0x18 — it advanced as server pushes 0x16..0x18 arrived).
  00 00 00 01   body word0: count = 1
  00 00 00 03   body word1: THE WORD IN QUESTION = 0x00000003, read BE
  01 00 00 00   app payload[0] = sub 0x01 (member/player-info, FUN_005bbb90's case)
  00 00 00 00
  00 00 00 00   app data (zeros)
  ba 47 66 11   trailer

17:39:18.061  S→EMU  transport ack of 0x19
17:39:18.099  EMU→S  the SAME op-10, seq 0x19 again, only the header ack word changed
              (0x15→0x18) — an application-level re-send despite the transport ack;
              the neighbouring reliable messages (op-04 seq 0x17, op-0a seq 0x18) were
              NOT re-sent, so this is not a transport-ack miss (Inference).
```

**What the word 0x00000003 is** (Conclusion from two wire observations + the July
decompile): it equals the **room handle minted 40 ms earlier** — not the host's
presenceId (journal: presenceId **5** for this session), not its player number, not the
endpoint token (`0x02f807d0`). The client's op-10 send frame is
`func_0x001df380(conn, 0x8000, payload, len, count, handle)` with `handle` =
`uRam006febe8` (`G12-joiner-tag17-RE-2026-07-16.md`); for a **creator** `0x6febe8` holds
the create-path room handle (3, here), for a **joiner** it holds the member handle the
sub-1 push delivered (July: `02f807d0`). Both observed instances are therefore the
**sender's own handle** — a "this is me / my room" scope word — not an addressee list.
Byte order: reads as a big-endian 3; with only small values and `02f807d0` observed, BE
vs LE cannot be fully discriminated on the wire (`02f807d0` is order-ambiguous, 3 reads
clean only as BE) (Observation + Inference).

**How the deployed relay resolved it** (`snap-lobby-sessions.js:428-448`,
`snap-lobby-codec.js:891-912`): `decodeRoomEvent` parses
`[BE32 nRecipients][BE32 recipientId]…[sub]` → `recipients: [3]`. `#relayRoomEvent`
walks the sender's room roster (only the host itself), matches each recipient word
against `member.presenceId` (5) or `session.endpointToken` (`0x02f807d0`) — no match —
and would `continue` on `target === from` even if it had matched. Journal:
`lobby-room-event-relayed roomHandle:0x3 sub:0x1 recipients:1 relayed:0` at
17:39:18.061. **Under the wire-observed semantics (word = sender's own handle) this
relay delivers to nobody by construction** — the only entity the word can ever name is
the sender, which is excluded (Conclusion). Latent hazard worth recording: the PS2's
presenceId tonight was **3**, the same number as room handle 3 — a cross-type id
collision that would cause a false match if a joiner were ever in the roster
(Observation → hazard note).

What the relay should be (Inference, high confidence — bioserver dumb-relay +
`#relayChat`'s proven scope model): treat the message as room-scoped — fan the payload
out verbatim to the sender's room membership **except the sender**, exactly like chat —
and, per the July V1 behaviour (§4), answer the sender's game-channel op-10 with the
server's own sub-1 push. Tonight the roster held nobody else, so even the correct relay
delivers 0 here; the bug is structural, not tonight's proximate failure (Observation).

## 3. What killed the host (Observation-led)

Checked, per the task, for all three candidate killers between 17:39:18 and the
17:41:26 close (and equally for host session 2, 17:36:59 → 17:38:12):

- **Host retransmits of an unacked reliable seq:** none. The only duplicate is the
  op-10 seq 0x19 pair 40 ms apart (§2), acked both times; nothing else was ever re-sent.
- **Server pushes the host never acked:** none. Wire shows the host acking every push
  (…0x16, 0x17, 0x18, 0x19); journal `unacknowledged: 0`, `sendRefusals: 0` at close.
- **Keepalive gap:** none. Every op-40 answered ≤40 ms to the very last exchange
  (17:41:22 window); journal `keepalivesSent: 28, keepaliveResponses: 28` (session 3)
  and `86/86` for the PS2's parallel session. After the client's op-02 the server
  stopped keepalives because it released the session (`SNAP_EXIT_CLOSE_MIRROR` close
  path) — that is a consequence, not a cause.

What actually happened, both times (Observation):

```
session 2:  17:36:59.513 create room 2 → in-room SILENCE (keepalives only)
            17:37:35.612 op-14 probe (+36.1 s) — absorbed, no reply
            17:38:12.030 op-02 voluntary close (+72.5 s) → TCP reconnect 17:38:49 →
            re-register 17:38:56
session 3:  17:39:18.019 create room 3 → op-10 sub-1 (×2, transport-acked, never
            answered) → in-room SILENCE
            17:40:13.528 op-14 probe (+55.5 s)
            17:41:26.367 op-02 voluntary close (+128.4 s) → TCP reconnect 17:41:30 →
            re-register 17:41:37   ← the owner's "~17:41 connection error"
```

So: **the host was not killed by the PS2's join and not by the transport — it timed
itself out while sitting in a V2-hosted room** (Conclusion for the mechanism class;
the precise armed timer is not pinned). The op-14-then-op-02 signature is identical to
the starving PS2's, so both consoles died of the same *application-silence* family. The
owner's "5–10 s after the PS2 tried to enter" maps to session 2's close at 17:38:12 —
12.5 s after the PS2's 17:37:59 op-0a — during which interval the server sent the host
**only op-40 keepalives** (Observation; the correlation is temporal, not causal).

What the host client was plausibly waiting for (Hypothesis, wire-motivated): the
member-info circulation of its own room. Its sub-1 self-info broadcast got no
application answer (V1 answered *every* client game-channel op-10 with an `a3` op-10
sub-1 push — §4 — and tonight's client re-sent the op-10 once, the behaviour July's
client showed until answered). Session 2 sent no op-10 at all and died sooner, so the
op-10 non-answer cannot be the whole story; "the in-room screen's data feed never
completes" is the honest granularity (Hypothesis).

## 4. The July V1 cross-check — what V1 supplied at these exact points (Observation)

From `join-window-packets-2026-07-16.txt` (V1, the rig-validated join era; solo join of
an empty seed room):

| client sends | V1 replied with | V2 (tonight) replies with |
|---|---|---|
| op-0x0c ROOM_QUERY sub-1/sub-2 (256B) | op-28 sel-0x0c **plus a 292B op-28 sel-0x0a roster record** ("PLAYER1", count 1, flag bytes `01 08 01`) — lines 499-500, 527-528 | op-28 sel-0x0c only |
| op-0x06 ENTER (peek 0xe0 and real 0xa0) | op-28 sel-6 **plus an `a3` op-10 sub-1 player-info push** (`00000001 00000000 01000000 …`) — lines 503-505, 533-534 | op-28 sel-6 only (no op-10 sub-1 push anywhere in V2) |
| op-0x0a member-list | **28-byte reply, body `00000000 00000000 00000000` — count 0, no records** — lines 514-516 | 296B reply, count 1, memberId, blobLen 0xF0, **charstats all zero** |
| op-0x10 (any, incl. join-request sub-2) | transport ack **plus an `a3` op-10 sub-1 push, every single time**; the client re-sends the op-10 until satisfied — lines 547-555 | transport ack only (sub-2 gets the sub-0x0C confirm; everything else is relay-to-nobody) |

Two structural deltas fall out (Conclusion): V1 ran a **member-info supply channel**
(sel-0x0a records + proactive op-10 sub-1 pushes) that V2 does not have; and V1's
member-list reply was **empty**, so July's joiner had nothing to wait on and proceeded
straight to op-06/op-10-sub-2. Tonight's PS2 got `count = 1` **plus** no member-info
channel — the first time any client has been put in that state — and it starved.

## 5. Verdict on the §5 hypotheses (B2-JOIN-FREEZE-EVIDENCE.md)

- **H-C (owner never pressed join): REFUTED** (Conclusion). The owner selected the room,
  the client issued the selection query (op-0a), displayed the waiting dialog, ran a
  give-up timer, and closed the session. An idle client does none of that.
- **H-A (drawn-roster table empty because op-06 member-JOIN pushes never reached the
  previewer): WEAKENED** (Inference). July's V1 also pushed no op-06 member records to
  the joiner before the join, and that joiner did not stall at this step. The op-06
  drawn-roster mechanism matters for in-room rendering, not provably for releasing
  this dialog.
- **H-B (reply content gates the join): SUPPORTED, refined** (Conclusion for the
  correlation; Hypothesis for the exact released-by datum). The discriminating variable
  across every observed run is the member-list content and its backing data:
  `count 0` → proceed (July, V1); `count 1` + zeroed 0xF0 blob + no sub-1/sel-0x0a
  member-info anywhere → starve ("Getting information", T37 emulator + RS1 PS2, 141.6 s
  and 142.6 s to op-02). The refined model: **the dialog completes when the client holds
  usable information for the members the list declared; V2 declares one member and
  supplies nothing to back it.** The codec's own annotation
  (`snap-lobby-codec.js:610-615`, "Answering this is what releases 'Getting
  information'") is **refuted by two nights of wire** and must be marked SUPERSEDED
  (corpus-methodology action).

## 6. Corpus / code corrections this run forces

1. `snap-lobby-codec.js:610-615` — "answering op-0a releases Getting information":
   SUPERSEDED (answered+acked twice, dialog never released). The release condition is
   downstream of the reply's *content* (§5).
2. `decodeRoomEvent`'s `[nRecipients][recipientId]…` layout
   (`snap-lobby-codec.js:874-912`, from B1-GAME-START-MODEL §2 item 5): both existing
   wire instances contradict the recipient-list reading — word1 is the sender's own
   `0x6febe8` handle (§2). Mark the recipient-list interpretation SUPERSEDED; the
   B1 doc's sender-frame note (`count` and `handle` words prefix the app payload)
   already contained the correct reading.
3. `#relayRoomEvent`'s presenceId/endpointToken match + self-exclusion
   (`snap-lobby-sessions.js:428-448`): delivers nothing under the observed semantics;
   plus the presenceId-vs-roomHandle small-integer collision hazard (PS2 presenceId 3
   vs room handle 3, tonight).
4. Positive confirmation for the record: the B2 §3 transport fix works on the wire
   (no swallowed aggregates; the batched post-create op-09 USER/MAXI are now answered —
   17:39:18.051-.053), and the T37 prediction "fix §3, the sweep completes, the wire
   shows what stalls next" resolved exactly as written: the stall moved to the
   member-list step.

## 7. Proposed next moves (server-side only, flag-gated)

1. **The discriminator for H-B (cheapest, one flag):** answer op-0x0a with the July
   V1 shape — count 0, 12-byte body — behind a flag, and re-run the join. If the
   joiner proceeds to op-06 ENTER / op-10 sub-2, H-B is runtime-confirmed and the
   sub-0x0C machinery (already deployed, `SNAP_JOIN_LADDER`) finally becomes reachable.
   (Diagnostic first; the honest fix is 2.)
2. **Restore the member-info supply channel V1 had:** on op-0x0c room queries, answer
   with sel-0x0c *plus* the op-28 sel-0x0a roster record; on op-0x06 acceptance and on
   any inbound game-channel op-10, push the `a3` op-10 sub-1 player-info for the room's
   members (V1's exact, rig-validated behaviour, §4). This addresses both the joiner's
   starve (with real member data rather than an empty-list workaround) and the host's
   in-room silence, and is the precondition for a populated (non-zero-charstats) op-0a
   reply being safe.
3. **Fix the op-0x10 relay semantics** (`snap-lobby-sessions.js:428-448` + codec):
   treat body word1 as the sender's handle, scope the fan-out to the sender's room
   except the sender (chat's model), and answer the sender per item 2. Do not ship a
   presenceId==word match — the collision hazard is live (§6.3).
4. **Evidence still wanted:** a PINE read at the stalled moment with the EMULATOR as
   the joiner (`0x6c4b90`, `0x6c4b9f`, `0x6c4ba0`, `0x6cbc7e`, plus the drawn-roster
   `0x6c7c2c` region) to pin the waiting SM; decompile of `FUN_005c0ae0`'s completion
   path (what the member-list consumer does with count/blob) and of the op-0x02
   sender's arming site (what starts the ~142 s give-up timer). These close the last
   Hypothesis grades in §5.
