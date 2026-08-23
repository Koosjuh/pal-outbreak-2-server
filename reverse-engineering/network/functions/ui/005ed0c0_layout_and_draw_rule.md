# 0x005ed0c0 layout_and_draw_rule

| field | value |
|---|---|
| Original address | 0x005ed0c0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ed0c0 |
| Resolved name | layout_and_draw_rule |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ee840, FUN_005eeca0
**Callees:** FUN_005eca10, FUN_005eced0
**Referenced globals:** iRam007012a0; +0x12/+0xd8c4/+0xd8bc (position); +0x186 (pass)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x186

## Behavioral explanation
Computes rule position (margins + center offset) and calls draw_hrule_or_underline on the draw pass.

## Notes / uncertainty
Thin render-pass wrapper: x=margins+center_offset, y=cursor, calls draw_text_decoration_line. compute_center_offset arg passed in untracked register (inferred = line width).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ed0c0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
