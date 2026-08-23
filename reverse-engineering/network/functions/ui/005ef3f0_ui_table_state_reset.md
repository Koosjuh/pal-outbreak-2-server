# 0x005ef3f0 ui_table_state_reset

| field | value |
|---|---|
| Original address | 0x005ef3f0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ef3f0 |
| Resolved name | ui_table_state_reset |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005e9360
**Callees:** FUN_005d8a70, FUN_005d95f0, FUN_005ec100, FUN_005ec4f0
**Referenced globals:** +0x124 col count; +0x120/+0x128/+0x178 values; +0x168 attr; +0x186 render-pass mode; +0xe96b draw-suppress flag
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x186 render pass; +0xe96b

## Behavioral explanation
Resets column counter to 0, sets attr[0]=3, loads three converted values (+0x128/+0x120/+0x178) and, in draw mode, kicks a draw-region init pair (0x5d8a70/0x5d95f0).

## Notes / uncertainty
Begin table/row: col_count=0, attr[0]=3, three guarded int-attr loads (+0x2a3/+0x193/+0x2b3); draw-pass-only draw_region init pair. +0x120/+0x178 roles uncertain.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ef3f0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
