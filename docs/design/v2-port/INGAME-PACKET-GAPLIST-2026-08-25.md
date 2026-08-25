# In-game packet gap list (wire vs openSNAP vs corpus) — 2026-08-25

The multiplayer game START works; PLAYER MOVEMENT syncs; ENEMY/entity state does NOT (zombie on
joiner not on host). These in-game packets are NOT in openSNAP (Auto Modellista has no such
traffic) nor decoded in our corpus (which covers the NET/transport layer, not the game engine).
This is the to-RE list for the gameplay-sync layer.

## Wire evidence (ingame2.pcap, PS2=host .129 / PC=joiner .248)
Reliable room-channel op-0x0F, flags **0xa036**, body 58 bytes (0x3a). Structure:
```
+0x00 24 00 01 00   packet type (24000100 = PLAYER STATE; both consoles send it -> syncs)
+0x04 04 24 XX YY   frame counter (increments per packet)
+0x08 00 00 01 00   const
+0x0c 00 00 00 18   const (0x18)
+0x10 00 00 02 14   const (0x214 - scenario/map id? fixed)
+0x14 00 00 00 00   const
+0x18 .. 12 bytes   VARYING position/state (changes as the player moves)
+0x24 00 00         trailer
```
- HOST (.129) sends ONLY `24000100` (381).
- JOINER (.248) sends `24000100` (558) AND **`24100200` (332)** — an EXTRA type the host never
  sends. byte[1]=0x10, byte[2]=0x02. Prime suspect for the entity/enemy or per-player channel that
  is not shared symmetrically -> the desync.
- Relay is LOSSY (reliable 32-window overflow): fewer relayed than sent.

## To-RE (our own, via Ghidra — the game engine, not the net corpus)
1. **0x001cac70** = slot 0x12 GamePacketRUDP handler (from slot-4 savestate conn+0x590). What it
   does with the 58-byte payload: switch on the `24xxxx` type? write player/entity tables?
2. The `24000100` vs `24100200` payload consumers — what each type updates (player pos vs enemy
   vs per-player), and whether enemy state is host-authoritative (broadcast) or client-local
   (deterministic seed).
3. The seed/init: is there a game-start packet carrying an RNG seed? If the enemy sim is
   deterministic and the seed differs, that alone explains the divergence.
4. The relay fix: should 0xa036 game packets be relayed UNRELIABLY (fire-and-forget continuous
   state) rather than reliable-with-drops? (bioserver relays raw over lossless TCP.)

## Status
Ghidra MCP was disconnected this session; needs Ghidra started (owner) OR a headless decompile of
0x001cac70 + the type consumers. The wire catalog above is the input.
