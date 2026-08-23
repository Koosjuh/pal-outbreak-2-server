# 0x0062fe20 get_localized_table_a_entry

| field | value |
|---|---|
| Original address | 0x0062fe20 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062fe20 |
| Resolved name | get_localized_table_a_entry |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005b1e80
**Callees:** —
**Referenced globals:** DAT_0068ace0 (lang table A ptr array); DAT_0068ad00 (lang table A' ptr array); bRam0034359d (language/region index)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** bRam0034359d

## Behavioral explanation
Returns entry param_1 from a per-language resource table selected by param_2 (two candidate table arrays).

## Notes / uncertainty
Two-variant localized accessor: param_2==0->DAT_0068ace0 else DAT_0068ad00, then [lang][idx]. Caller 005b1e80 soft-keyboard/glyph; primary vs alternate glyph-table distinction (case/page) unproven.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062fe20.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
