# In-game peer vanish (host loses joiner after cutscene) — savestate diagnosis 2026-08-26

## Symptom (owner, rig, PC=host/PCSX2, PS2=joiner)
Both chars present at game open. After a cutscene the JOINER's character VANISHES on the HOST
(PCSX2); the real PS2 still sees BOTH. Host also does not see the enemy; enemy is FROZEN on PS2.
Savestates: slot1 = char-vanished state, slot2 = enemy area (both host/PCSX2).

## Confirmed (both savestates, host EE memory, 1:1 map)
Peer table (0x3540ec, stride 0x3c) + globals:
- `myPeerIdx 0x3540a4 = 0` (host is peer0), `peerCount 0x3540a5 = 2`, `netState 0x3540a6 = 0x05`.
- `peer[0] active=1`, last-activity `+8` ADVANCES between slots (0x4480d351 -> 0x449358a7).
- **`peer[1] active=0`** (the JOINER), `+4=0x0000000a`, last-activity `+8=0x446ef913` FROZEN
  (identical in both slots).
- Per-peer accumulator `0x351fe0`: slot0 has data, **slot1 (joiner) = ALL ZEROS** in both.
- Timeout threshold `DAT_00248338 = 0x41f80000` (float 31.0).

=> The host SWEPT the joiner peer inactive (FUN_001beb90 -> FUN_001befc0 timeout path) and holds no
joiner data. peerCount stays 2 but peer[1] is dead.

## Server ruled OUT (Confirmed)
- Pi journal (in-game window): 1336 game-channel-0f relayed, EVERY one `relayed:1`, ZERO WINDOW_FULL,
  zero drops/abandons. The relay is lossless here.
- Wire (rig4, reliable op-0f by direction): the JOINER sent (PS2>Pi present) AND the server relayed
  to the HOST (Pi>PC present). So the host RECEIVED joiner packets, yet peer[1] stayed inactive with
  an empty accumulator.

## Conclusion + open question
The peer vanish is a CLIENT-SIDE peer deactivation on the host, not a server relay drop. The host
either (a) timed peer[1] out during a cutscene gap and then IGNORES an inactive peer's later packets
(no re-activation path), or (b) never routed the joiner's packets into slot1 (peer-index/framing
mismatch) so the accumulator stayed zero and the timeout fired. Deciding a/b needs a live in-game
trace of FUN_001beb90 on the host: does an inbound peer-1 message re-activate peer[1] and write
0x351fe0 slot1, or is it dropped because peer[1].active==0 / peer-index != 1?

This is the in-game ENTITY/PEER-SYNC frontier (milestone 357425f6 "next frontier"), SEPARATE from the
now-fixed solo-start and from the splash-charstats issue. The enemy behaviour (frozen on PS2, absent
on host) is the same layer: 24000100/24100200 peer-indexed state whose consumer (0x351fe0 apply) is
not yet traced. NEXT: trace the 0x351fe0 consumer + the peer re-activation logic; only then decide
whether the server can help (e.g. preserve peer-index framing, or a cutscene-window keepalive) or
whether it is purely client-timing.
