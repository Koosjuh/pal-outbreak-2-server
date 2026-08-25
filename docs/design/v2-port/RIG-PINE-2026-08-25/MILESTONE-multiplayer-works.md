# MILESTONE 2026-08-25: MULTIPLAYER GAME START WORKS (both consoles in-game, movement syncs)

**Owner-confirmed on the rig (2-console: PS2 host + PC/emulator joiner):**
- **BOTH clients started the game.** The game starts, with the RIGHT characters, for both consoles.
- **Player movement SYNCS** across consoles ("I see movement when I walk with characters").
- ~1s input->render latency (relay through the Pi) — noted for later optimization, not a blocker.

This is the culmination of the whole session's protocol work, all flags now live on the Pi:
OBAREA-W5 (rules/cast/scenario selectable), SNAP_ROOM_STAT (joiner scenario), SNAP_CHANNEL_BIT_ECHO
(exit), SNAP_GAME_RELAY (in-game packet relay), SNAP_ROSTER_TO_JOINER + SNAP_MEMBER_ID_TOKEN +
SNAP_HOST_RESEAT (seating -> count 2 -> non-solo start). The game-start accept handshake
(FUN_005bbf20 sub-4) now completes for the joiner.

Role note: the successful run was **PS2 = HOST, PC = JOINER** (earlier PC-host runs went solo).
Whether the role or the joiner-readiness timing was decisive is unconfirmed (PINE timed out during
the in-game phase, so the joiner's accept transition was not captured live).

## The new frontier: IN-GAME ENTITY SYNC (not the lobby/start protocol)
Owner: "Zombie on emulator can't hurt my character and I do not see the zombie on my real ps2."
So PLAYER state (position/movement) relays and syncs, but ENEMY/entity state (zombies, damage,
interactions) does NOT sync between clients. Each console runs its own enemy simulation. This is
the in-game synchronization layer (the "gameplay-session/in-game sync services" in ARCHITECTURE.md)
— a NEW phase beyond the lobby/room/start protocol just completed.

## Remaining lobby/room polish (secondary to the two above)
- Lobby player count shows "4P" with only 2 clients (op-09/op-0a count display).
- In-room member list shows no members (roster visibility — SNAP_ROSTER_TO_JOINER seat vs the
  drawn list; op-0a count-0).
- Chat only works on the host (room chat render — in-room text path still un-RE'd, sub-7 = charstats).
- Wrong character on the end/results screen (savestate 10).

## Next investigation (in-game sync)
Census the in-game packet channels (op-0x0F game-channel vs op-0x10 targeted vs op-0x11
send-to-gameserver) and which are relayed. Cross-ref bioserver GameServerPacketHandler (relays raw
to same gamenumber) + openSNAP game-packet model: enemy state likely rides a channel we don't relay,
or is host-authoritative and its broadcast is dropped. This is the gameplay-sync build.

## In-game sync — wire evidence (ingame2.pcap, ~29k frames)
- Game packets are RELIABLE room-channel op-0x0F, flags **0xa036** (0x8000|0x2000|len). Both
  consoles emit them; the Pi relays (SNAP_GAME_RELAY). Plus unreliable 0x2012 beacons, 0xa04c/0xa05c.
- ASYMMETRY/LOSS: the emulator emitted ~890 reliable 0xa036 game packets; the relay to the PS2 does
  not carry all of them (census: 1727 total op-0f from .248 vs 791 relayed to .129). The reliable
  channel's 32-message window drops on overflow (nora's SNAP_GAME_RELAY hazard 2) — a candidate.
- SYMPTOM (owner): the JOINER (emulator) sees a zombie the HOST (PS2) does not, and it can't
  interact. Player MOVEMENT syncs (explicit position relay), ENEMY state does not → the two
  consoles run INDEPENDENT enemy simulations (diverged RNG seed and/or lost enemy-state packets),
  not one shared authoritative sim.
- This is the gameplay-sync layer (uncharted): needs the in-game packet PAYLOAD semantics
  (what 0xa036 carries: player input vs enemy state vs a seed) and the game-engine memory map,
  neither in the corpus yet. bioserver relays raw over TCP (lossless) — our reliable-UDP relay
  dropping under load is a real difference to close (unreliable relay for game packets, or a larger
  in-game window). NEW GOAL for the next session.
