# 0x005f16b0 ui_column_width_distribute

| field | value |
|---|---|
| Original address | 0x005f16b0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f16b0 |
| Resolved name | ui_column_width_distribute |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f1da0
**Callees:** —
**Referenced globals:** node+0x1c width, +0x32 margin, +0x45 border, +0x46 flags
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Distributes surplus/deficit horizontal space across up to 32 columns proportionally (two 32-entry stack arrays min/pref), writing accumulated column x-edges back.

## Notes / uncertainty
HTML-table surplus distribution solver: iterative proportional fit of column deltas toward preferred widths, re-accumulated into param_2. Integer rounding preserved verbatim; carry reload in while-header is a decompiler artifact.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f16b0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
