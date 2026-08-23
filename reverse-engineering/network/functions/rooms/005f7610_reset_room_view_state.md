# 0x005f7610 reset_room_view_state

| field | value |
|---|---|
| Original address | 0x005f7610 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f7610 |
| Resolved name | reset_room_view_state |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005fc610, FUN_0062d730
**Callees:** FUN_005aec20
**Referenced globals:** 0x6c4b90 (screen state, mode=2); 0x6c5490; 0x70b410 (slot table, 0xff=empty); 0x6c4600
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x6c4b90; 0x70b410

## Behavioral explanation
Partial reset of the room view: sets 0x6c4b90 mode=2, clears 0x6c5490 (0x20) and fills the slot-assignment table 0x70b410 (8 bytes = 0xff empty).

## Notes / uncertainty
Resets lobby_state_block to screen_id=2 (room-detail), zeroes SM cursor, memsets 0x6c5490 (0x20) and fills 8-byte slot table 0x70b410 with 0xFF (SLOT_EMPTY). Offsets from struct doc, not a live read.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f7610.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
