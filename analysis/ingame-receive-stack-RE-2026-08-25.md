# In-game network receive stack — RE (live Ghidra, 2026-08-25)

Traced the full in-game packet RECEIVE path in the main-EE (SLES_533.19), bottom-up from the
transport ring to the peer-routing layer. This is the plumbing under the 0xa036 game packets
(24000100 / 24100200) — uncharted before (game engine, not the net corpus).

## The stack (each Confirmed, decompiled live)
1. **Transport receivers** (registered by `FUN_001cadc0` via `FUN_001d4d24` = snap_set_callback_slot):
   slot 0x12 → `0x1cac70` (RELIABLE), slot 0x14 → `FUN_001cad10` (UNRELIABLE), slot 0x13/0x15 →
   `0x1cadb0`. They memcpy received bytes into a **ring buffer at 0x36a900** (4KB, to 0x36b900),
   write ptr `DAT_00248850`, count `iRam003688c8`.
2. `FUN_001cab70(dst, max)` — reads/consumes up to `max` bytes from the ring into `dst`, shifts the
   ring. The game's "receive from net" primitive.
3. `FUN_001caed0(_, queueObj)` — drains the ring into a per-conn queue (buffer@+8, wptr@+0xc,
   cap@+0x10), capped at **900 bytes/drain**.
4. `FUN_001caf60(dst)` — reassembles COMPLETE messages from queue `0x35a690`
   (FUN_001bf140 peek-len / FUN_001bf170 peek-data / FUN_001bf230 pop) into dst.
5. **`FUN_001beb90` — THE PEER ROUTER** (the key layer): reads messages from queue `0x354080`;
   each message header word (`thunk_FUN_001bfff0`) splits **top 4 bits = PEER INDEX**
   (`>>0xc`, checked < peer count `bRam003540a5`), **low 12 bits = length**. Active peers tracked
   at `peer*0x3c + 0x3540ec`; message bodies copied to per-peer accumulator **`0x351fe0`**
   (`thunk_FUN_001bfe30`). Ends with a **peer-timeout sweep**: an active peer with no data for
   `DAT_00248338` is marked inactive and disconnected (`FUN_001befc0`).
6. The game engine reads `0x351fe0` (per-peer data) and applies it — the 24000100/24100200
   SEMANTICS (player pos vs enemy vs per-peer) is the NEXT level, not yet traced.

## The sync insight (Inference, strong)
The messages are **PEER-INDEXED** (top 4 bits of the header). Decoding the wire types under this:
- `24000100` bytes [24,00,..] → peer index 0
- `24100200` bytes [24,10,..] → peer index 1
Wire (ingame2.pcap): the HOST (.129) sends ONLY peer-0 (`24000100`); the JOINER (.248) sends
peer-0 AND peer-1 (`24000100` + `24100200`). So each console tags its outbound game state with a
peer index, and the two sides do NOT send a symmetric set — a strong candidate for why enemy/
per-peer state diverges. Combined with the LOSSY reliable relay (1727 sent / 791 relayed) and the
peer-timeout sweep, dropped peer-indexed messages could also silently deactivate a peer.

## Next (the actual sync model)
Trace the consumer of `0x351fe0` (the game engine's per-peer apply) to learn what 24000100 vs
24100200 carry (player transform vs enemy/AI vs input) and whether enemies are host-authoritative
or deterministic. Then decide the relay fix (unreliable vs reliable, and whether the server must
preserve/repair the peer-index routing). Entry points for the next trace: xrefs to `0x351fe0` and
the game-state globals `0x3540xx` (peer table, stride 0x3c).

## SEND path + state machine (live Ghidra, cont.)
- **`FUN_001bde80`** — the per-frame NET UPDATE TICK: runs the peer router `FUN_001beb90`
  (receive), dispatches the **network state machine** `(*PTR_LAB_00248370[bRam003540a6])()`
  (state at `0x3540a6`; state 7 = terminal), then the send step. Rate/timeout managed by floats
  at `0x3540bx`.
- **`FUN_001be9c0`** (send step) — builds the outbound header **`(myPeerIndex & 0xf) << 0xc`**
  (`bRam003540a4` = MY peer index) — CONFIRMS the wire framing (top-4-bits = sender's peer index).
  Each client tags its own outbound game packets with its own index.
- **`FUN_001be7a0`** (send drain) — drains the OUTBOUND queue `0x352c20` and transmits via
  `FUN_001caa30`, rate-limited (`0x354248` vs `DAT_00248358`). The game logic APPENDS serialized
  state to `0x352c20`; the receive side accumulates per-peer data at `0x351fe0`.

## ACTIONABLE CONCLUSION — the relay must be LOSSLESS (the server fix)
The receive reassembler `FUN_001beb90` is length-framed and **fails on any gap**: a short/negative
length or a peer-index over the count calls `FUN_001bef70(2|4|5,...)` and drives the net state to
`0x10`/`0x15` (error/disconnect). So the in-game game-packet stream **cannot tolerate loss**.
- Wire: emulator emitted ~890 reliable 0xa036 game packets; the relay carried far fewer
  (census 1727 op-0f sent / 791 relayed) — the SN@P reliable 32-message window overflows and
  DROPS (nora's SNAP_GAME_RELAY hazard 2). bioserver relayed these raw over LOSSLESS TCP.
- **Fix direction (server, testable):** make the game-packet relay lossless — do NOT drop op-0x0F
  game packets on window-full. Options: (a) a much larger reliable window for the in-game phase,
  (b) a dedicated per-peer relay queue that back-pressures instead of dropping, (c) verify whether
  the client's own ARUDP layer already retransmits (making a best-effort forward acceptable). The
  peer-index in the header must be PRESERVED byte-for-byte by the relay (it already is —
  byte-identical relay).

## Remaining RE (for full semantics, not required for the relay fix)
What `24000100` (peer 0) vs `24100200` (peer 1) CARRY (player transform / enemy / input) and
host-authoritative-vs-deterministic lives in the state-machine handlers (`PTR_LAB_00248370`, first
entry `FUN_001be070`) that read `0x351fe0` and write `0x352c20`. Next trace target if the lossless
relay alone does not fully sync enemies.

## CORRECTION (same session, discipline) — lossless-relay is a CANDIDATE, not confirmed
I overstated "the relay MUST be lossless -> that is the fix." CONFIRMED: the reassembler fails on
loss (FUN_001bef70 error paths). NOT confirmed: that our relay actually drops game packets in the
successful run. The "1727 sent / 791 relayed" was a loose census across DIFFERENT op-0f subsets
(0x2012 beacons, 0xa04c, 0xa036), not a clean game-packet measurement; the journal for the working
run showed the relay working (relayed=1, T22) with 0 refusals captured. So loss is a HYPOTHESIS.

Re-reading the SYMPTOM: the JOINER sees a zombie the HOST does NOT (its OWN, not the host's). If
enemies were host-authoritative + relayed, the joiner would see the HOST's enemies. It has its own
-> enemies are almost certainly NOT in the 24000100/24100200 packets (those are per-peer PLAYER
state, peer-indexed; that is why MOVEMENT syncs). Enemies are either (a) DETERMINISTIC (RNG seed)
and the two sims diverged, or (b) synced on a mechanism we have not decoded.

## DECISIVE next step (not a relay tweak)
Trace the net state-machine handlers (PTR_LAB_00248370[0..7], first FUN_001be070) + the consumer
of 0x351fe0 / builder of 0x352c20: what 24000100 carries, whether an RNG SEED is exchanged at game
start, whether enemies are deterministic. THAT decides the fix. Do NOT ship a relay change until
the game-state semantics are read.

## RE-CONFIRMED (wire+journal, 2026-08-25 pm) — the relay IS lossy after all
Live 2-console game (char.pcap + journal): both consoles send ~equally (emu 369 / PS2 364
reliable 0xa036 game packets), the EMULATOR receives ~all (369), but the real PS2 receives only
230 of the emulator's 369 — **~38% loss in the emu->PS2 direction**. Journal confirms the
mechanism: "the reliable channel refused the send" (WINDOW_FULL). The higher-latency console (real
PS2) drains its reliable window slower -> window fills -> the relay REFUSES (drops) new game
packets. So my earlier "loss is unproven" caution is now RESOLVED: the relay drops, asymmetrically,
on the slower peer. Lockstep determinism cannot survive this -> enemy/state divergence.

Character asymmetry (owner: emulator does NOT render the PS2's character; PS2 DOES render the
emulator's): the emulator RECEIVED all the PS2's position packets (369) yet shows no PS2 character
-> not a delivery problem; the emulator never got the PS2's CHARACTER MODEL (the game-start
sub-6/sub-7 charstats hand-off did not complete emu-ward). Separate from the relay loss. Ties to
the long-standing "Jim"/charstats gap.

## THE FIX (two, evidence-backed)
1. **Lossless game-packet relay** — do NOT drop op-0x0F game packets on WINDOW_FULL. The reliable
   channel refuses beyond `maximumUnacknowledged` (default 32); at the PS2's latency that fills.
   Raise the in-game window substantially (the channel already RETRANSMITS unacked -> lossless,
   just latency; the client's own 16 recv-window paces consumption) OR give the game-packet relay
   a dedicated non-dropping queue. bioserver relayed these over lossless TCP.
2. **Complete the charstats hand-off both directions** — ensure each console receives the other's
   sub-6/sub-7 charstats so both render both characters (fixes the asymmetry + "Jim").
