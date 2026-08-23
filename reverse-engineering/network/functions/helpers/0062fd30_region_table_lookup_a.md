# 0x0062fd30 region_table_lookup_a

| field | value |
|---|---|
| Original address | 0x0062fd30 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062fd30 |
| Resolved name | region_table_lookup_a |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005b5d20, FUN_005b9150, FUN_005bb380
**Callees:** —
**Referenced globals:** 0x68ac40 table base; 0x34359d region index
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Generic resource-table accessor: returns *(base[0x68ac40][region] + param*4), indexed by region/language byte 0x34359d.

## Notes / uncertainty
Localized-table accessor: g_localTableA[lang(0x34359d)][idx], base DAT_0068ac40. Twin family a-e. No bounds check; entry type (ptr vs id) caller-defined.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062fd30.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
