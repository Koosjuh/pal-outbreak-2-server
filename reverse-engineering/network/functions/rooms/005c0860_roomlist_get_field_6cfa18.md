# 0x005c0860 roomlist_get_field_6cfa18

| field | value |
|---|---|
| Original address | 0x005c0860 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c0860 |
| Resolved name | roomlist_get_field_6cfa18 |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005b5970, FUN_005fc0c0, FUN_00600e90, FUN_0062e9b0, FUN_0062edc0
**Callees:** —
**Referenced globals:** 0x6cfa18 room-list-table u32 field
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Accessor: reads the u32 room field at +0x6cfa18 of room-list entry param_1 (0x144 stride) into caller pointer.

## Notes / uncertainty
Reads u32 rec+0x18; likely room handle/id (ENTER target / registry-B key) but not runtime-confirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c0860.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
