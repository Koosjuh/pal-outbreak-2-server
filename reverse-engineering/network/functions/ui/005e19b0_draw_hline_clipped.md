# 0x005e19b0 draw_hline_clipped

| field | value |
|---|---|
| Original address | 0x005e19b0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e19b0 |
| Resolved name | draw_hline_clipped |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005e2760, FUN_005e2fa0
**Callees:** FUN_005dda30, FUN_005e1f30
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Clips a horizontal 1px line to screen (FUN_005e1f30) then draws it via FUN_005dda30.

## Notes / uncertainty
Thin clipped filled-rect line; clips via FUN_005e1f30, pads BOTH far coords +1.0. param_5=color. Orientation naming inferred from +1.0 pattern / pairing with 0x1a30.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e19b0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
