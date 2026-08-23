# 0x00614c80 draw_icon_with_pulse

| field | value |
|---|---|
| Original address | 0x00614c80 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00614c80 |
| Resolved name | draw_icon_with_pulse |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00612120, FUN_00612ae0, FUN_00613b10
**Callees:** FUN_00614e60
**Referenced globals:** 0x64c2b0 (icon descriptor table); 0x64b9b0 (sprite base); DAT_00693928 (beat scale); iRam0070d1c0+0x29
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** iRam0070d1c0+0x29 (audio level)

## Behavioral explanation
Draws an icon/sprite from descriptor table &DAT_0064c2b0[param_1*4], with an optional audio/beat-reactive alpha tint overlay.

## Notes / uncertainty
Icon desc table 0x64c2b0 (4B/entry), base sprite + optional additive-blend sine-pulse overlay driven by DAT_00693928 * beat(ui+0x29); all constants exact, beat-source semantics inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00614c80.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
