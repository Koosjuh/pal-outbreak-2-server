# RS1-A — Why the beacon ECHO killed the solo start

Question A of the RS1 post-mortem (2026-08-08). Evidence: RS1 pcap
`captures/v2-live/RS1-20260808-172534.pcap`, T37 pcap
`captures/v2-live/T37-20260808-090328.pcap` (its capture kept running and also
holds a SECOND echo event at 15:02:47 UTC), Pi journal (`pal-server-v2`,
local = UTC+2), transport decompile
`reverse-engineering/network/sources/executables/transport-decompile/FUN_001d9f78.c`,
server code `server-v2/src/udp/snap-lobby-session.js` /
`server-v2/src/transport/reliable-channel.js` (deployed ea972c74,
`SNAP_GAME_BEACON_ECHO=ON`, `SNAP_GAME_BEACON_RELAY=OFF`).

Wire frames below are SN@P inner segments:
`[flags|len u16BE][sub u8][op u8][token u32][seq u32BE][ack u32BE][body][trailer ba476611]`.

---

## 1. The exchange, byte-exact (Observation — wire)

**RS1, 17:43:04 UTC** (solo start of gamenumber 2, room 0x4, party [test123],
op-0x0D barrier answered at 17:42:54.327):

```
17:43:04.826  .248 -> server   2012 00 0f 02f807d0 00000001 00000000 | 00 00 | ba476611   (beacon, client unreliable seq 1)
17:43:04.827  server -> .248   2012 00 0f 02f807d0 00000007 00000000 | 00 00 | ba476611   (echo,   server unreliable seq 7)
```

**Diff: bytes +0x08..+0x0B (the sequence field) and NOTHING else.**
Flags word `0x2012` identical (SET only; len 0x12 = 18). Sub `0x00`, op `0x0f`,
token `02f807d0`, ack field `00000000`, 2-byte body `00 00`, trailer — all
identical. The server stamped its own shared unreliable counter (the op-0x40
keepalives had consumed 4, 5, 6; the echo took 7; the next keepalive took 8).

**Second sample, 15:02:47 UTC** (an earlier solo start the same day, gamenumber 1,
room 0x1, start barrier 15:02:36.436 — captured in the still-running T37 pcap):

```
15:02:47.108  .248 -> server   2012 00 0f 02f807d0 00000001 00000000 | 00 00 |   (beacon, seq 1)
15:02:47.113  server -> .248   2012 00 0f 02f807d0 00000224 00000000 | 00 00 |   (echo,   seq 548)
```

Same diff: only the sequence field.

Both starts sent the beacon ~10.5 s after the op-0x0D barrier (module load time),
and in both the beacon count stopped at ONE. Baseline T37 (echo OFF,
07:06:35–07:08:34): seq 1..115 at ~1.03 s cadence, 119 s, then a clean abort.

## 2. What the client did AFTER receiving the echo (Observation — wire + journal)

The two echoed runs died differently; neither reached the meeting room.

**Sample RS1 (17:43):**

| t (UTC) | event |
|---|---|
| 17:43:04.827 | echo delivered |
| — | **no beacon #2 ever** (next was due ~17:43:05.8 on the T37 cadence) |
| 17:43:07.6, 17:43:12.6 | client still answers op-0x40 keepalives seq 8, 9 with op-0x41 — the transport is alive and accepting the server's unreliable stream AFTER the echo |
| 17:43:15.545 | client opens **TCP :10127**, server greets as pre-browser (cmds 4097/4098/4100), client **RST**s it at .765 |
| 17:43:17.566 | client sends reliable **op-0x02 SESSION_CLOSE**; server mirrors; presence detached (session stats: gameBeacons 1, keepaliveResponses 8/8, unacknowledged 0) |

Owner (RIG-SESSION-1.md R6): "Picture of a Zombie and network error. then
loading and a connection error occurred"; R8: "Did not return to the meeting
room this time."

**Sample 15:02:**

| t (UTC) | event |
|---|---|
| 15:02:47.113 | echo delivered |
| 15:02:47.430 | client sends a **reliable op-0x0F**, flags `0xa03a` (RELIABLE+SET, DATA clear, 0x400 clear), seq 2742, 42-byte body:<br>`2800 0600 0414 0200 0000 0600 0100 0108 0000 0000 0000 0600 0414 2200 0000 0600 0100 0108 0000 0000 0000`<br>— structured game-module data (repeated `06 00`-length blocks around `04 14 02` / `04 14 22`), **not** the beacon shape and **not** lobby chat |
| 15:02:47.433 | server MISFILES it as chat (`lobby-chat`, screenType 40 = body[0] 0x28, relayed 0) — it went into the void |
| 15:02:47.448 | client answers one keepalive (op-0x41 seq 2743), then **total silence** — no beacon #2, no close, nothing |
| 15:05:12.410 | server idle-kills the session (120 s) |

**Baseline T37 (echo OFF) for contrast:** 115 beacons / 119 s of silence-in-return,
then the SAME TCP :10127 attempt + client RST (07:08:47.5), but then op-0x0D
body `0xf7e00001` re-open on the SAME session and a working post-game meeting
room. The TCP-probe-then-RST is part of the client's normal abort path; the echo
did not cause it — it ran it after ONE beacon instead of after a ~120 s timeout,
and the post-abort recovery was worse (session close / hard silence instead of
the meeting room).

## 3. Was the stamped sequence the poison? (the specific hypothesis to verify)

**No — at both layers we can see. (Conclusion for transport; Inference for the app layer.)**

- Transport (Observation, wire + decompile): the client's unreliable acceptance
  is the monotonic high-water test against the server's OWN unreliable stream
  (`conn+0x10 <= seq`, `FUN_001d6988.c:25`), shared with the op-0x40 keepalives.
  7 follows 6 and 548 follows 547, so both echoes pass; and the client provably
  kept accepting that same stream afterwards (it answered keepalive seq 8 and 9
  in RS1). A client-counter-shaped echo (seq 1) would actually have RISKED
  rejection here (1 < 6). The server's stamped value is the transport-correct form.
- App layer (Observation from decompile, then Inference): the receive dispatcher
  `FUN_001d9f78` switches on `opcode & 0x7f` minus 3; op-0x0F is case 0xc. With
  DATA (0x1000) clear, 0x400 clear and RELIABLE (0x8000) clear it invokes the
  callback at `conn+0x598` (handler id 0x14 in the `conn[0x548 + id*4]` table)
  as `cb(&ctx, body)`. The ctx the prologue builds (lines 22-41) carries the
  body length, the DATA bit, the sub byte, the token and the opcode — **it never
  reads the sequence field** (`param_2+0x34`), and the second argument points at
  the body (`param_2+0x3c`), past the header. So the game-module handler most
  likely cannot even observe the sequence value (Inference: it would need to
  index backwards from the body pointer). No flags validation happens beyond
  slot selection.

So the echo was a well-formed, transport-accepted, dispatcher-routable inbound
frame. The poison is not any byte of it in isolation — **it is the delivery
itself**: a beacon-shaped message arrived at handler 0x14, something a solo
client can otherwise never receive, and the game module's state machine visibly
changed within <1 s (beaconing stopped in both samples).

## 4. What would a "well-formed inbound in-game op-0x0F" look like?

**Unknown — there is no ground-truth sample** (Observation of absence: the game
module is outside the 2549-function lobby corpus, REOF2 stubs its netcode, and
no JP GSINFO analogue exists in the lobby corpus — B1 §3). The one wire clue we
now own is the 15:02 reaction frame: real in-game op-0x0F traffic from the
client is RELIABLE (flags 0xa000), DATA clear, 0x400 clear (so it routes to
handler id 0x12, `conn+0x590`, on a receiving client), with a structured body of
`06 00`-length blocks — nothing like the 2-byte `00 00` unreliable probe. That
makes "answer the beacon with its own bytes" a shape the client plausibly never
expects on this channel (Hypothesis).

Two readings fit the two samples; the wire cannot discriminate them (stated as
competing Hypotheses):

- **H-poison:** the handler read the 2-byte `00 00` as a peer/server message,
  failed validation, and aborted the establishment — fast-failing the scenario.
- **H-progress-then-starve:** the echo SATISFIED the wait (beaconing stopped =
  the state advanced), the client sent its next handshake step — the 15:02
  reliable op-0x0F — and died because the server misfiled that step as chat and
  answered nothing. Sample RS1 weakens but does not kill this (its state
  differed: second start of the evening, gamenumber 2, after the failed R3 join;
  it never sent the reliable frame).

## 5. RELAY-shape vs ECHO-shape — which experiment next?

**Neither, as a solo experiment; the cheap wire experiments are exhausted.**

- A room-scoped RELAY delivers NOTHING to a solo player — that is exactly the
  T37 silence arm, already run: 119 s of beaconing, abort (Observation).
- A relay-shape delivered TO the sender is byte-identical to the echo except the
  sequence stamp — the SN@P header has no sender field — and §3 shows the
  sequence is invisible to the handler. There is no third shape to send without
  knowing the handler's parser (Conclusion).
- Echo: two samples, both fatal, and strictly worse recovery than silence (no
  meeting-room fallback; one clean close, one hard hang) (Observation).

**The decisive next evidence is the game-module handler itself:**

1. During the zombie/loading screen, PINE-read the EE words at `conn+0x590` and
   `conn+0x598` (handler ids 0x12/0x14) to get the installed callback addresses,
   then decompile those functions in Ghidra (they live in the game overlay, not
   main EE — this is the `FUN_001d4d24(conn, 0x12/0x14, cb)` installer hunt of
   B1 gap #1, now with a concrete cheap read to shortcut the xref search).
2. Only after that decompile decides H-poison vs H-progress-then-starve is
   another rig arm worth owner time.

## 6. Server-side changes this analysis supports now

1. **Flip `SNAP_GAME_BEACON_ECHO` back OFF for owner-facing runs**
   (`server-v2/src/config/server-config.js:348`). Two samples show it converts a
   ~120 s soft-fail with a meeting-room recovery into a ≤13 s hard-fail with
   none. (Grounded in §2.)
2. **Stop misfiling reliable non-chat op-0x0F as chat.** The client's own
   dispatcher separates op-0x0F flavors by the 0x0400 flag (case 0xc,
   `FUN_001d9f78.c:143-166`): 0x400 set = chat (handler 0x0B/0x0D), 0x400 clear
   = game-module channel (0x12 reliable / 0x14 unreliable). The server currently
   splits only `!reliable && !data` to the beacon path
   (`snap-lobby-session.js:764`), so the 15:02 reaction frame (reliable, 0x400
   clear) fell into the chat parser (`lobby-chat` screenType 40). Route op-0x0F
   with `(flags & 0x0400) === 0` to a consumed-and-logged game-channel path
   regardless of the reliable bit — matching the client's own table. This is a
   prerequisite for ever answering the handshake step under H-progress.
3. Log the raw body hex on that path (the 15:02 42-byte body is currently only
   recoverable from the pcap).

## 7. Corpus/doc deltas

- `B1-GAME-START-MODEL.md` §5 gap 1 arm (c) ("cheapest rig experiment: echo") —
  **RUN, result negative, twice.** The echo is consumed (beaconing stops in
  <1 s) but the start dies faster and recovers worse than under silence. The gap
  remains open; its settle path narrows to the (a)/(b) decompile arms, with the
  `conn+0x590/598` PINE read (§5) as the new cheapest entry.
- New Observation for the corpus: in-game op-0x0F exists in a second, RELIABLE
  species (flags 0xa000, `06 00`-block body, handler id 0x12) — first captured
  15:02:47.430 UTC 2026-08-08.
- The B1 statement "the echo stamps the server's own counter ... a stamped value
  is the correct form" (`snap-lobby-session.js:1487-1493` comment) is CONFIRMED
  at transport level by this run (client answered keepalives seq 8/9 after
  accepting echo seq 7).
