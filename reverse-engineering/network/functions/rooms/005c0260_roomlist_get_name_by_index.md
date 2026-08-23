# 0x005c0260 roomlist_get_name_by_index

| field | value |
|---|---|
| Original address | 0x005c0260 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c0260 |
| Resolved name | roomlist_get_name_by_index |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005b5820, FUN_005f9280, FUN_005fc0c0, FUN_006010d0, FUN_0062e9b0
**Callees:** —
**Referenced globals:** 0x6cfb76 room-list-table name field (30*0x144)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Accessor: strcpy the room name field (offset +0x6cfb76) of room-list entry param_1 (0x144 stride) into caller buffer.

## Notes / uncertainty
strcpy room name; (idx-1)*0x144+0x6cfb76 == rec[idx]+0x32. Unifies room-list table base 0x6cfa00 stride 0x144; this accessor is 1-based while siblings are 0-based.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c0260.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
