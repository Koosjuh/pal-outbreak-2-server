# 0x005f85e0 draw_room_slot_row

| field | value |
|---|---|
| Original address | 0x005f85e0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f85e0 |
| Resolved name | draw_room_slot_row |
| Subsystem | roster |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005af1e0, FUN_005af2c0, FUN_005af2e0, FUN_0062fea0
**Referenced globals:** 0x70b410 (slot->player table); 0x6c5497 (cursor slot); 0x6c4600; 0x6c45fc; 0x6c3032 (member name field); 0x649780/0x6497e0/0x6497f8/0x649818/0x649828 (coord/id tables)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** param+3 (slot index); 0x70b410

## Behavioral explanation
Draw callback for one of the 10 room player-slot rows (slot=param+3, <6): selects coords/ids from DAT tables by slot occupancy in 0x70b410, draws the player's name (from 0x6970a0 region) or an 'empty/vacant' label, and highlights the cursor slot cRam006c5497.

## Notes / uncertainty
Per-slot renderer (slot<6): empty vs occupied vs selected-alt layouts from DAT coord/label tables; slot 0 = host/creator special case (always draws). func_0x001b6f50 name-resolve backing table not traced; DAT label captions unresolved.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f85e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
