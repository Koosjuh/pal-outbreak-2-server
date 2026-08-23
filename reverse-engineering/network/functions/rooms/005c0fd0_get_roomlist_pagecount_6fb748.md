# 0x005c0fd0 get_roomlist_pagecount_6fb748

| field | value |
|---|---|
| Original address | 0x005c0fd0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c0fd0 |
| Resolved name | get_roomlist_pagecount_6fb748 |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00600ff0, FUN_0062ef80
**Callees:** —
**Referenced globals:** 0x6fb748 room-list page count
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Accessor: returns room-list page count 0x6fb748 into caller pointer.

## Notes / uncertainty
Pure getter of u16 page count 0x6fb748 (producer FUN_005c0f60). No uncertainty.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c0fd0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
