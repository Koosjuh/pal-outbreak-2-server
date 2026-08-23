# 0x0062ff00 get_localized_table_e_entry

| field | value |
|---|---|
| Original address | 0x0062ff00 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062ff00 |
| Resolved name | get_localized_table_e_entry |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00628860
**Callees:** —
**Referenced globals:** DAT_0068ad80 (lang table ptr array); bRam0034359d (language index)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** bRam0034359d

## Behavioral explanation
Returns entry param_1 from per-language resource table DAT_0068ad80.

## Notes / uncertainty
tableE[lang][index], base 0x68ad80. Family bases contiguous 0x68ad20/40/60/80. Entry semantics untraced.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062ff00.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
