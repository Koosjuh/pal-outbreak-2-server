# 0x00617fa0 draw_text_scaled_centered

| field | value |
|---|---|
| Original address | 0x00617fa0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00617fa0 |
| Resolved name | draw_text_scaled_centered |
| Subsystem | menus |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00617c30
**Callees:** FUN_005af1e0
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Text-draw helper: scales x/y by 1.25, optionally centers by measured string width, and emits via FUN_005af1e0.

## Notes / uncertainty
Text primitive: scale x/y by 1.25, optional horizontal centering via width measure func_0x001ae3e0, blit FUN_005af1e0. param_5 is font size (per caller 0x617c30). Exact.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00617fa0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
