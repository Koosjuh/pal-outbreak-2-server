# RS1 TCP-10127 command inventory — capture `RS1-20260808-172534.pcap`

**Source:** `captures/v2-live/RS1-20260808-172534.pcap` (libpcap LE, linktype 276
LINUX_SLL2, 5299 packets, span 17:26:30.985 – 17:48:05.043 UTC-in-capture-clock).
Hosts: PS2 = `192.0.2.129`, emulator = `192.0.2.248`, V2 server = `192.0.2.121`.
Parsed with a scratch Node parser (seq-based per-direction TCP reassembly, retransmit
dedup, then the V2 stream framing). Rig context: `RIG-SESSION-1.md` — owner created
rooms and touched the rules screen ~17:44–17:50; create screens also up earlier.

**Framing (grounded against what V2 actually parses, not the JP bioserver header):**
`server-v2/src/protocol/tcp10127-codec.js` — **8-byte** header
`{len BE16 @0, direction @2 (0x01 QUERY / 0x02 TELL / 0x10 PUSH), cmd BE16 @3, seq @5, err @6, 0xFF @7}`,
payload follows. The 12-byte `{who,qsw,cmd,len,pid,err,3×FF}` header in
`BIOSERVER-CONTRACT.md` is the JP transport; the PAL SN@P TCP wire uses the 8-byte
form above. Every byte of every TCP-10127 stream tonight framed cleanly under it:
**0 leftover bytes, 0 sequence gaps, in all 40 directional streams.**

## Traffic census (Observation)

| flow | packets | span |
|---|---|---|
| TCP 10127 | 722 | 17:26:33.418 – **17:44:30.362** |
| UDP 9090 (SN@P lobby transport) | 4298 | 17:30:47.768 – **17:48:04.770** |
| TCP 443 (DNAS) | 106 | 17:26:31 – 17:30:12 |

20 TCP-10127 connections:

- **8 pre-browser** connections (client silent; server pushes `0x1001`, `0x1002`,
  `0x1004` at the 50/100/150 ms cadence): 17:26:33 emu, 17:30:14 PS2, 17:36:12,
  17:38:49 emu, 17:40:29 PS2, 17:41:30, 17:43:15, 17:43:40 emu.
- **6 full lobby-initialization ladders** (server `0x6001` challenge, then 22 client
  queries: `1007, 6103, 6212, 6203, 7×6204, 6211, 6213, 6501, 6503, 6502, 6504,
  6502, 6504, 6510, 6510, 1004`): emu :1608 17:30:49, PS2 :1889 17:32:52,
  emu :1612 17:38:57, PS2 :1892 17:40:36, emu :1615 17:41:38, emu :1619 17:44:14.
- **6 short re-entry ladders** (challenge, then 9 client queries: `6501, 6503,
  6502, 6504, 6502, 6504, 6510, 6510, 1004`): each ~15 s after its full ladder —
  emu :1609/:1613/:1616/:1620, PS2 :1890/:1893.

## The complete client command inventory (direction 0x01 QUERY)

186 client queries total. **Every one received a same-cmd, same-seq TELL
(direction 0x02). The UNANSWERED set is EMPTY** — V2 IGNORED nothing on TCP 10127
tonight. (V2's `unimplemented-frame` no-reply path never fired on the wire.)

| cmd | count | answered | unanswered | reply err | clients | first / last |
|---|---|---|---|---|---|---|
| 0x1004 | 12 | 12 | 0 | 0 | both | 17:30:49 / 17:44:30 |
| 0x1007 | 6 | 6 | 0 | 0 | both | 17:30:49 / 17:44:15 |
| 0x6103 | 6 | 6 | 0 | 0 | both | 17:30:49 / 17:44:15 |
| 0x6203 | 6 | 6 | 0 | 0 | both | 17:30:49 / 17:44:15 |
| 0x6204 | 42 | 42 | 0 | 0 | both | 17:30:49 / 17:44:15 |
| 0x6211 | 6 | 6 | 0 | **0xFF** | both | 17:30:49 / 17:44:15 |
| 0x6212 | 6 | 6 | 0 | **0xFF** | both | 17:30:49 / 17:44:15 |
| 0x6213 | 6 | 6 | 0 | **0xFF** | both | 17:30:49 / 17:44:15 |
| 0x6501 | 12 | 12 | 0 | 0 | both | 17:30:49 / 17:44:29 |
| 0x6502 | 24 | 24 | 0 | 0 | both | 17:30:49 / 17:44:30 |
| 0x6503 | 12 | 12 | 0 | 0 | both | 17:30:49 / 17:44:30 |
| 0x6504 | 24 | 24 | 0 | 0 | both | 17:30:49 / 17:44:30 |
| 0x6510 | 24 | 24 | 0 | 0 | both | 17:30:49 / 17:44:30 |

Server-initiated (never in reply to a query): `0x6001` push ×12 (one per lobby
connection), `0x1001`/`0x1002`/`0x1004` ×8 each (pre-browser transcript).
Reply latency was ~1–6 ms throughout.

### The only non-zero-status replies: the 0x6211 / 0x6212 / 0x6213 trio

These three were **answered**, but with `err=0xFF` and an empty body — the
deliberate "client-default branch" status (`lobby-initialization-session.js`:
0x6212 status 0xFF → client-default value; 0x6211 status 0xFF → client stores
zero; 0x6213 status 0xFF → client installs its default words). The resolvers
(`resolveCommand6211Value`/`6212`/`6213Words`) exist in the service surface but
are **not wired in `src/app/application.js`**, so the default branch is what the
deployed build serves. Example exchange (emu :1608):

```
17:30:49.199 C  0000016212d100ff          (0x6212 QUERY, seq 0xd1, empty)
17:30:49.201 S  0000026212d1ffff          (TELL, err=0xFF, empty)
17:30:49.559 C  0000016211da00ff
17:30:49.560 S  0000026211daffff
17:30:49.599 C  0000016213db00ff
17:30:49.600 S  0000026213dbffff
```

**Inference:** if any TCP-served value gates the rules screen, these three
default-branch replies are the only TCP candidates — but they are answered
frames, not ignored ones.

## Where the create/rules dialogue actually was (Observation)

The last TCP-10127 client byte is **17:44:30.362** (the 0x1004 close of emu
:1620's ladder). The owner's create/rules window ~17:44–17:50 shows **zero TCP
traffic** and heavy **UDP 9090** traffic — 194+131 c2s packets from the emulator
in 17:44–17:45 alone, continuing to 17:48:04 (capture end). Per-minute UDP
histogram confirms both consoles spoke UDP 9090 continuously 17:30–17:48, and
the 17:44+ window is emulator-only c2s.

**Conclusion (from the wire): on this PAL/V2 hybrid, the room-create and rules
dialogue does not ride TCP 10127 at all — it rides the UDP 9090 SN@P transport.
The red-rules / ????-button queries therefore cannot be "unanswered TCP cmds";
there are none. They are either (a) inside the encrypted UDP 9090 SN@P opcodes,
or (b) never sent because a value already served (rule masks, area table,
or the 0x6211/0x6212/0x6213 defaults) tells the client not to.**

## Cross-map against BIOSERVER-CONTRACT.md create-dialogue rows

| contract row | cmd | on TCP tonight? | note |
|---|---|---|---|
| CREATESLOT | 0x6407 | **ABSENT** | create happened (owner + emu created rooms) yet no 0x64xx on TCP → the create dialogue is not on this transport |
| SCENESELECT | 0x6509 | **ABSENT** | — |
| SLOTNAME | 0x6609 | **ABSENT** | — |
| SLOTPASSWD | 0x660A | **ABSENT** | — |
| SETRULE | 0x660B | **ABSENT** | owner touched the rules screen 17:44–17:50; zero TCP-10127 traffic in that window — the rules queries did not use TCP |
| UNKN660C | 0x660C | **ABSENT** | — |
| CHARSELECT | 0x6190 | **ABSENT** | contract says "sent once before area select" — the PAL client sent no 0x6190 on TCP in any of the 6 pre-area-select ladders. Divergence from the JP contract worth its own trace |
| UNKN6504 | 0x6504 | present ×24, all answered err=0 | **different usage**: tonight's 0x6504 is the lobby-initialization ladder step (payload `{u32, u32, len-prefixed encrypted string}`, paired with 6501/6502/6503/6510), not the contract's "last packet from slot creator". The create-row 0x6504 is not evidenced on TCP |

Byte-pattern discovery scan of the raw UDP 9090 payloads for `64 07`, `65 09`,
`66 09`–`66 0C`, `61 90`, `65 04`: two isolated 2-byte hits (`65 09` at 17:31:37,
`64 07` at 17:34:17) in ~596 KB of SN@P-encoded/encrypted payload — discovery
noise, not identifications. Decoding the UDP 9090 SN@P layer is where these
commands must be looked for next; that is outside this TCP inventory's scope.

## G6/G7 button queries

Same verdict: no TCP-10127 query went unanswered, so the non-working
"view the service / national ranking" buttons (RIG-SESSION-1.md R1 observations)
are not explained by an ignored TCP command in this capture. Whatever those
buttons send (if anything) is on UDP 9090 or suppressed client-side.

## Method / reproducibility

Scratch parser (session scratchpad `rs1-parse.mjs`, `rs1-deep.mjs`,
`rs1-udpwin.mjs`): libpcap reader → SLL2 → IPv4/TCP filter on port 10127 →
per-direction seq-ordered reassembly with retransmit dedup (keep-longest per
seq) → 8-byte framing per `tcp10127-codec.js` → per-connection QUERY/TELL
pairing by (cmd, ts-order); replies verified to echo the request seq byte.
Integrity: 0 leftover bytes, 0 gaps, every reassembled stream framed exactly.
