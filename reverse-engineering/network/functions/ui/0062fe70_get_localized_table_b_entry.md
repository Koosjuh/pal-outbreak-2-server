# 0x0062fe70 get_localized_table_b_entry

| field | value |
|---|---|
| Original address | 0x0062fe70 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062fe70 |
| Resolved name | get_localized_table_b_entry |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005b6e10
**Callees:** —
**Referenced globals:** DAT_0068ad20 (lang table B ptr array); bRam0034359d (language index)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** bRam0034359d

## Behavioral explanation
Returns word entry param_1 from per-language resource table DAT_0068ad20.

## Notes / uncertainty
Per-language resource getter: tableB[lang][index], single deref. Table base 0x68ad20. Element type (string ptr vs id) not traced through caller FUN_005b6e10; no bounds check.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062fe70.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
