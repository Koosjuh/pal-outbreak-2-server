# 0x0062fdc0 region_table_lookup_d

| field | value |
|---|---|
| Original address | 0x0062fdc0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062fdc0 |
| Resolved name | region_table_lookup_d |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00628860, FUN_00629c20
**Callees:** —
**Referenced globals:** 0x68aca0 table base; 0x34359d region index
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Generic resource-table accessor: returns *(base[0x68aca0][region] + param*4), region byte 0x34359d.

## Notes / uncertainty
Same twin idiom, base DAT_0068aca0, callers 0x628/0x629. No bounds check.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062fdc0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
