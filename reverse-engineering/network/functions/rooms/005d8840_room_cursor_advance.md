# 0x005d8840 room_cursor_advance

| field | value |
|---|---|
| Original address | 0x005d8840 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d8840 |
| Resolved name | room_cursor_advance |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ca1a0
**Callees:** FUN_005d67d0, FUN_005d6810, FUN_005d68e0
**Referenced globals:** 0x004f588 roomlist head; 0x00701018 current room; 0x00701000 pending kind
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** uRam00701018; uRam00701000

## Behavioral explanation
Advances the current-room cursor iRam00701018 through the room-list pool according to the pending request kind uRam00701000 (1/2 forward+skip, 3 forward, 4 reverse) using the room iterators.

## Notes / uncertainty
Advances current-room cursor 0x701018 by pending kind: 1/2 reverse+skip, 3 reverse, 4 forward, 5(op06)/default no-move. FUN_005d68e0 skip semantics named by role.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d8840.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
