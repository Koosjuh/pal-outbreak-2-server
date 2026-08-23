# 0x0062fdf0 region_table_lookup_e

| field | value |
|---|---|
| Original address | 0x0062fdf0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062fdf0 |
| Resolved name | region_table_lookup_e |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f6610, FUN_005f6790, FUN_005f84c0, FUN_005fbbf0, FUN_00601d50, FUN_00602340, FUN_00604e70, FUN_006050d0, FUN_00605690, FUN_00605790
**Callees:** —
**Referenced globals:** 0x68acc0 table base; 0x34359d region index
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Generic resource-table accessor: returns *(base[0x68acc0][region] + param*4), region byte 0x34359d; widely reused (10 callers).

## Notes / uncertainty
Same twin idiom, base DAT_0068acc0, most-used (10 callers, 0x5f-0x60 room-list/roster UI). No bounds check.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062fdf0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
