# 0x005f1a80 ui_column_edge_reconcile

| field | value |
|---|---|
| Original address | 0x005f1a80 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f1a80 |
| Resolved name | ui_column_edge_reconcile |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f1da0
**Callees:** —
**Referenced globals:** column-edge arrays (params); flag bit 0x1/0x8
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Reconciles two column-edge arrays, propagating min-width increases forward across cells and honoring a no-shrink flag bit (0x8).

## Notes / uncertainty
Folds a row's cumulative column edges into the running max accumulator honoring span flag 0x1 and no-shrink 0x8. Spanned-column inner walk (LAB_005f1c88) control-flow-preserved; intricate corners.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f1a80.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
