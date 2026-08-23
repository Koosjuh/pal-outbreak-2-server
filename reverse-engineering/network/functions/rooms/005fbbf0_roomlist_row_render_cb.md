# 0x005fbbf0 roomlist_row_render_cb

| field | value |
|---|---|
| Original address | 0x005fbbf0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005fbbf0 |
| Resolved name | roomlist_row_render_cb |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005af1e0, FUN_005af2c0, FUN_005af2e0, FUN_005bac80, FUN_00618c20, FUN_0062fdf0
**Referenced globals:** 0x6c076e/0x6c0774/0x6c0760/0x6c0762/0x6c0778 room-slot record; cRam006c4fd9 selected row; cRam006c4fd8 base idx
**Referenced strings:** 0x649878; 0x649870; 0x649880; 0x649888
**Referenced opcodes:** —
**State vars:** cRam006c4fd9 selection

## Behavioral explanation
Per-frame room/roster row callback: renders each room row (name/scenario/status) from the slot table, highlighting the selected index cRam006c4fd9.

## Notes / uncertainty
Per-frame row draw cb; phase SM (0 init/1 draw/2 teardown); reads 0x15c-stride room-slot record (count 0x6c0760, type 0x6c076e, flags 0x6c0774 lock/pw bits 0x10000/0x20000, name 0x6c0778). Record base/offset split (0x6c0618 vs 0x6c0760) unresolved; layout_t field names inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005fbbf0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
