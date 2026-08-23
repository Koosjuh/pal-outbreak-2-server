# 0x005d7310 cur_room_whobytes_ptr

| field | value |
|---|---|
| Original address | 0x005d7310 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d7310 |
| Resolved name | cur_room_whobytes_ptr |
| Subsystem | helpers |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005d7320, FUN_005d73c0, FUN_005d76b0, FUN_005d7a30
**Callees:** —
**Referenced globals:** 0x00701018 current room
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** iRam00701018

## Behavioral explanation
Accessor returning current-room node + 0x108 (its who/id byte pair).

## Notes / uncertainty
Pure getter: g_current_room(0x701018)+0x108 who/id block. +0x108 field width/layout (single pair vs N-slot array) unproven; label inferred from sibling accessors + caller cluster, no PINE trace.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d7310.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
