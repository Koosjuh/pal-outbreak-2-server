# 0x005e1a30 draw_vline_clipped

| field | value |
|---|---|
| Original address | 0x005e1a30 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e1a30 |
| Resolved name | draw_vline_clipped |
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
Clips a vertical 1px line to screen (FUN_005e1f30) then draws it via FUN_005dda30.

## Notes / uncertainty
Sibling of 0x19b0 but pads only far Y +1.0 (x1 unpadded) - the axis difference. Clips via FUN_005e1f30. Orientation naming inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e1a30.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
