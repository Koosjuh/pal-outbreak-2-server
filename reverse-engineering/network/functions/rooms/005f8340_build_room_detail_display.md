# 0x005f8340 build_room_detail_display

| field | value |
|---|---|
| Original address | 0x005f8340 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f8340 |
| Resolved name | build_room_detail_display |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f78c0
**Callees:** FUN_005b6cf0, FUN_005ba570, FUN_005ba7b0, FUN_005ba7c0, FUN_00618ba0
**Referenced globals:** 0x649758 (widget id/coord table); param+0x907 (cursor slot)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Registers the room-detail/create-screen display list: 2 header widgets (IDs from 0x649758, cb FUN_005f84c0), 2 label widgets (LAB_005f8ab0), 2 cursor widgets (LAB_005f8960), and 10 player-slot rows (cb FUN_005f85e0).

## Notes / uncertainty
Builds in-room display list: 2 header + 2 label + 2 cursor + 10 player-slot rows (cb draw_room_slot_row 005f85e0). Early-return on any widget_alloc failure. The +0x30/+0x34 coord field mapping looks swapped in raw; copy is faithful, x/y labeling a guess.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f8340.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
