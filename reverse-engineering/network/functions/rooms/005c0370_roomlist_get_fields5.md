# 0x005c0370 roomlist_get_fields5

| field | value |
|---|---|
| Original address | 0x005c0370 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c0370 |
| Resolved name | roomlist_get_fields5 |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005b58e0, FUN_005fc0c0, FUN_00601170, FUN_0062e9b0
**Callees:** —
**Referenced globals:** 0x6cfa22 room-list-table field block (5 u16)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Accessor: reads 5 consecutive u16 room fields (+0x6cfa22..+0x6cfa2a) of room-list entry param_1 into 5 out-pointers.

## Notes / uncertainty
Reads 5 u16 at rec+0x22..+0x2a into out-ptrs. Field identities (cur/max/scenario/etc) not runtime-confirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c0370.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
