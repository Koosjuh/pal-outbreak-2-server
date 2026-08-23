# 0x005c7bd0 get_room_list_entry

| field | value |
|---|---|
| Original address | 0x005c7bd0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c7bd0 |
| Resolved name | get_room_list_entry |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00606fc0
**Callees:** —
**Referenced globals:** 0x365e20 (room table, stride 0x260); 0x365f80 (per-room detail ptr); 0x86f800/0x86f7f8 (live-selected override)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Fills a room-list-entry struct for the UI: copies room name/strings and current/max player counts from the room table (0x365e20, stride 0x260).

## Notes / uncertainty
Fills UI room-list-entry: 3 strcpy'd strings + cur(+0x12c)/max(+0x12a) from detail_ptr; live override 0x86f7f8 for selected row. String field names and strcpy identity of func_0x00109eb8 inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c7bd0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
