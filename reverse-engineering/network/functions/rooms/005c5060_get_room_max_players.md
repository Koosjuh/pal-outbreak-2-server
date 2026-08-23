# 0x005c5060 get_room_max_players

| field | value |
|---|---|
| Original address | 0x005c5060 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c5060 |
| Resolved name | get_room_max_players |
| Subsystem | rooms |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005bc990
**Callees:** —
**Referenced globals:** 0x365f80 room-record-table
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Returns u16 at offset +0x12a of the room record for (param-1) from table 0x365f80 (stride 0x260).

## Notes / uncertainty
Renamed from get_room_field_0x12a. Returns detail_ptr->max_players (+0x12a) for 1-based room idx via 0x365e20/0x260 table, +0x160 detail_ptr. cur/max labeling inferred from sibling 0x005c7bd0, not runtime-confirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c5060.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
