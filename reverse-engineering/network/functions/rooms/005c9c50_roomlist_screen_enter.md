# 0x005c9c50 roomlist_screen_enter

| field | value |
|---|---|
| Original address | 0x005c9c50 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c9c50 |
| Resolved name | roomlist_screen_enter |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ca6a0, FUN_005cccf0, FUN_005d5640, FUN_005d60a0
**Referenced globals:** 0x701068+0x5ffc0 display-list ptr array[500]; 0x701070+0x22/0x24/0x26/0x28 cursor geom; 0x701068+0x68e7e list-mode; 0x701068+0x68e85 phase; 0x701070+0x43b saved room name; 0x701070+4/8 scroll xy
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x701070+0x30; 0x701070+0x34; 0x701068+0x68e85; 0x701068+0x60dcb; 0x701068+0x60dc7

## Behavioral explanation
Enters/refreshes the room-list screen: inits cursor geometry, drains a queued result (FUN_005d5640), scans the 500-entry display list for room ('\r') and type-0x0e rows, and positions the cursor on the row whose name matches the saved room name at +0x43b.

## Notes / uncertainty
Room-list screen tick: drains detail query, computes list-mode from 500-slot display list, kicks per-room query dispatch, centers viewport on saved room (row type 0x0e, name at +0x60). Row +0x60 vs +0x64 name-ptr discrepancy vs 0x005cccf0 unresolved.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c9c50.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
