# Game-start wire analysis — 2026-08-24 rig session (NOT yet committed by the analysis fork)

Evidence: `scratchpad/rig2-%02d.pcap0` (full session, 18,679 UDP rows) + `journal-snap.log`.
Host = emulator `.248` "test123" (loaded into game). Joiner = PS2 `.129` "real" (stuck on
"Game to begin shortly", then died). Times CEST. Model reference: `B1-GAME-START-MODEL.md`
(the roster-sync SM phases + download SM), `BIOSERVER-CONTRACT.md` §7 (broadcastGetReady),
`PCAP-OPENSNAP-GAPS-2026-08-24.md` F2/F3.

## 1. Timeline (Observation, frame numbers from the TSV)

| # | t | dir | bytes | meaning |
|---|---|---|---|---|
| 17944 | 23:16:03 | SRV→host | op-06 `a118` "test123", id 1 | create-self member record |
| 17945/17956 | 23:16:03 | SRV→host | op-10 sub-5 (max 4 cur 1), sub-1 room-info 0x314 | create follow-ups |
| 18353 | 23:16:23 | joiner→SRV | op-06 `e028` (DATA-clear room-ENTER form) | the join |
| 18356/18359 | 23:16:23 | SRV→both | op-06 `a118` "real", id 2 | member-JOIN pushed to BOTH ✓ |
| 18357/18360 | 23:16:23 | SRV→both | op-10 **sub-5, max 4 cur 2** | count push ✓ |
| 18364 | 23:16:23 | SRV→joiner | op-10 sub-1 relay + 0x314 pushes | member-info channel ✓ |
| 18379..18588 | 23:16:24..:17:03 | both | sub-0a/0b/0e/0f ping-pong, relayed both ways | SNAP_OP10_RELAY working ✓ |
| **18867** | **23:17:14** | host→SRV | op-10 **sub-3** in a MULTI datagram (flags 0x81c) with an **op-08 "STAT" rider** (`a018 0008`) | **START pressed — roster-sync phase 0, exactly per B1** |
| 18871 | 23:17:14 | SRV→joiner | **sub-3 relayed** (len 0x1c) | ✓ — this is what moved the PS2 to the standby screen |
| 18873 | 23:17:14 | joiner→SRV | **sub-4 ACCEPT, len 0x31c** (the 0x304 accept body) | joiner accepted ✓ |
| 18876 | 23:17:14 | SRV→host | **sub-4 relayed to host** | ✓ |
| **18881** | **23:17:15** | host→SRV | **op-0x0D `a014` body BE32(1), seq 0x57** | the download-SM barrier — **only ONE SECOND after sub-3: the host took the SOLO SHORTCUT** |
| 18883 | 23:17:15 | SRV→host | op-28 sel-0x0D **flags `0xB018`** status 0 | wrong class (0xA0 req → 0xB0 reply) — but sub-0x0D dispatch is single-slot (`FUN_001d9f78` case 0xC → 0x5e4), so the host proceeded |
| 18923+ | 23:17:25.. | host→SRV | 10× unreliable beacons `2012 000f` + **239 reliable room-channel op-0x0F game packets** (seq 0x5b→0x138+, ~0.5–2 s cadence, structured LE bodies `2800 0600 0414…`, `2400 0100 0424…`) | ALL bare-acked, **NONE relayed** |
| 18945.. | 23:17:32.. | SRV→joiner | only 30 s app-keepalives (op-10 sub-0) | the joiner receives NOTHING else |
| 20375 | **23:19:42** | joiner→SRV | **op-0x02 session close** (147 s after the start = the 144.8 s per-screen watchdog) | the PS2 gave up; SRV mirrored the close (20377) |

No op-0x14 SEND_ECHO probes this session (T37's pattern absent). The host's earlier room
chat (`a428 000f`, 23:16:46) is out of scope here (chat fork).

## 2. What the PS2 was waiting for (Inference from B1, wire-corroborated)

The joiner sent NOTHING un-answered — it was waiting on a **server-relayed host push that
never existed**. Per B1: after sub-4 accept, the joiner parks in download-SM state 3 waiting
UNBOUNDED on `0x6FF2AF`, set ONLY by the host's op-10 **sub-8** ("all data delivered"),
preceded by sub-5 (player numbers), sub-6 (ids/names), sub-7 (charstats). The host emitted
**none of them**: one second after sub-3 it was already at the op-0x0D barrier — the
**solo shortcut** (`phase 8: 0x6FF2B3 < 2 → 13`). The host client believed **members = 1**
at START despite having RECEIVED the joiner's op-06 "real" record and the sub-5 cur=2 push
40 s earlier. So the blocker is the HOST'S ROSTER COUNT (`0x6FF2B3`), not the relay layer —
sub-3/sub-4 relaying demonstrably works.

This also matches the owner's "joiner sees Training scenario": the same member/room-info
supply the joiner renders from is incomplete (room scenario id not carried in what we push).

## 3. The host's op-0x0F pump — relay spec (openSNAP model, F2)

239 reliable `0xA0xx` op-0x0F frames, seq-continuous, each bare-acked by us, none relayed.
Required behavior once a joiner is in-game (and harmless before): for a reliable op-0x0F
with STRING (0x0400) clear from a room member:
- **Recipients:** every other session in the sender's room (presence scope, sender excluded).
- **Frame:** byte-identical payload; flags = the sender's channel bits + RELIABLE
  (`0xA000`-family), stamped on EACH recipient's own outbound reliable sequence (their
  channel counter), never the sender's seq.
- **Ack:** we still bare-ack the sender (unchanged); recipients ack us and our channel
  retransmits per recipient as normal.
- **Dedup:** the inbound window already suppresses sender retransmits (re-ACK, no re-relay).
- Distinct from `SNAP_GAME_BEACON_RELAY` (the UNRELIABLE `2012` beacon relay, default OFF,
  falsified as an echo-to-sender experiment in RS1-A — the openSNAP model says relay to
  OTHERS, never the sender).

## 4. Recommended fixes (ranked)

1. **Host roster count (THE blocker).** Find the `0x6FF2B3` writer (top Ghidra ask) and feed
   it. Prime candidate per the G12-roster thread: the op-0a member list must return REAL
   member records to room members (we currently answer `members:0` every time — journal,
   8×). Evidence: host solo-shortcut despite op-06+sub-5 arriving → those two do NOT write
   the count the start SM reads. Risk: op-0a record layout is the known rejected-create-self
   territory — decompile before serving.
2. **Relay reliable room-channel op-0x0F** (spec §3, new flag). Needed for any in-game
   traffic to reach the joiner once fix 1 lands; zero effect on solo. Low risk (relay
   pattern already proven for op-10).
3. **Channel-echo the op-0x0D completion** (extend `SNAP_CHANNEL_BIT_ECHO` to sel-0x0D —
   single-slot today, cosmetic, but the confirmed invariant says echo).
4. Nothing needed for sub-3/4 relaying (works) or 0x14 echoes (absent tonight; keep F3 as a
   contingency for the solo-start variant).

Watchdog note: the joiner's 147 s death is the SAME per-screen watchdog class as C3 — fixing
the start data flow removes the park; no separate watchdog work needed here.
