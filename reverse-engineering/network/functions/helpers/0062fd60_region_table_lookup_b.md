# 0x0062fd60 region_table_lookup_b

| field | value |
|---|---|
| Original address | 0x0062fd60 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062fd60 |
| Resolved name | region_table_lookup_b |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005b4da0
**Callees:** —
**Referenced globals:** 0x68ac60 table base; 0x34359d region index
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Generic resource-table accessor: returns *(base[0x68ac60][region] + param*4), region byte 0x34359d.

## Notes / uncertainty
Same twin idiom, base DAT_0068ac60, single caller 005b4da0. No bounds check.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062fd60.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
