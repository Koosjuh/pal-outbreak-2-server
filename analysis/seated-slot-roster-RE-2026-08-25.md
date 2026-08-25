# Seated-slot roster RE (snap-re, 2026-08-25) — filed by goal session

**Corrects T19:** op-06 member-add IS the only seat vehicle for 0x6c7c2c (the 4x0x3b0 seated
table the start-roster AND the in-room member list both read). T19's "wrong table" was wrong.

## The seat path (Confirmed)
op06 `FUN_005bb4d0`: ASCII-encodes memberId(+0x10, post-FUN_001d80c8-swap) → 0x6cd672; name →
0x6cd682; charstats(+0x18, 0xf0) → 0x6cd696; fires event 0x1f → `FUN_005b5ac0` (SEAT into first
empty 0x6c7c2c slot) when screen 0x6c4b90 ∈ {4,0xe}. Slot layout: +0x00 16B ASCII id, +0x10
name (occupancy=name[0]≠0), +0x24 0xf0 charstats.

## The two seat GATES
- **G-screen:** host must be in-room (0x6c4b90 = 4 or 0xe) at op06 receipt. Mode 5 only announces,
  no seat. (Inference, strong.)
- **G-dedup (the suspected blocker):** on screen 4/0xe the seater scans occupied slots and RETURNS
  without seating if the incoming charstats dedup key (charId @charstats+0xc8 / class @+0xca)
  matches a seated slot (special pair 6↔0x5b). **A fully-zeroed 0xf0 block → key 0 → collides with
  slot-0 → seat refused.** v2 DOES set characterId=playernum (host 1/joiner 2) so +0xc8 differs —
  so THIS path may already pass; needs rig/savestate confirmation. class @+0xca is 0 for both (we
  never set it). (Inference.)

## The start roster + solo decision (Confirmed)
FUN_005c6210 (from FUN_00616d30 case 0) snapshots occupied 0x6c7c2c slots → 0x6ff2bd → (SM state 0)
0x6ff70d, counts into 0x6ff2b3. Accept scan FUN_005bbfc0 decodes 8 ASCII at 0x6ff70d+i*0x114 vs
a0, sets 0x6ff2b5[i]=1 on match. States 6/7: 0x6ff2b3 = count(accepts==1). State 8/0xa: <2 → SOLO.
So the identity that must seat = the op06 memberId (=recipient endpointToken, BE, per T18) — but
ONLY matters after the slot seats.

## THE DEEP BLOCKER (Inference, strong) — the non-solo accept is topology-gated
FUN_005bba20 case 4 → FUN_005bbfc0(a0 = op10 frame connHandle = the RECEIVING link's conn+0x44,
savestate-confirmed = host endpointToken, constant per link). On a SINGLE host↔server relay link
a0 is CONSTANT → the scan can only ever mark the ONE slot whose id == host token → accepted count
caps at 1 → SOLO, structurally, regardless of what the server relays. A non-solo start needs each
peer's sub-4 to arrive on a link whose conn+0x44 == that peer's seated id — i.e. PER-PEER
connection objects on the host. Whether the PAL client allocates per-peer conns in server-relay
mode is NOT in the overlay dumps (SN@P lib 0x1dxxxx/0x1exxxx) → Ghidra #1. If it does not, a pure
single-link relay CANNOT complete Outbreak's game-start accept (the client wants a P2P mesh).

## Member list (Confirmed)
The in-room member list (FUN_00605790) renders the SEATED table 0x6c7c2c, NOT op0a. "Member list
doesn't show joiners" = the SAME seat gap, distinct from SNAP_OP0A_COUNT0 (lobby count). Selector-5
(FUN_005b53f0→FUN_005f50d0) decorates already-seated members and DROPS non-seated records.

## Deliverable / next steps
1. Seating fix (implementable): push EVERY existing member's op06 to a joiner (v2 only sends the
   joiner its own — T15), + ensure distinct non-zero dedup key (charId+class) per member. Falsifier:
   emulator savestate after a join → 2 occupied 0x6c7c2c slots, ids decode to {host,joiner} tokens.
2. Non-solo accept: GHIDRA #1 (per-peer conns / conn+0x44 assignment). Decides if server-relay can
   ever produce a non-solo start, or if it needs per-peer sessions / is a client P2P expectation.

Sources: overlay-3dat FUN_005b5ac0/005bb4d0/005c0920/005c6210/00616d30/005c6500/005bbfc0/005bba20/
005bc0e0/00605790/005b53f0/005f50d0; rooms.md:7230-7310,22993-23034.
