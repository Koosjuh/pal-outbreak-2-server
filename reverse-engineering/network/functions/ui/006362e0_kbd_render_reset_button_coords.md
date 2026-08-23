# 0x006362e0 kbd_render_reset_button_coords

| field | value |
|---|---|
| Original address | 0x006362e0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006362e0 |
| Resolved name | kbd_render_reset_button_coords |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_006345e0
**Callees:** —
**Referenced globals:** 0x715da8 state struct; 0x691188..0x691c3c display coord globals; 0x6921c8..0x6921fa icon coord table
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Render setup: writes X/Y coords and 9999 sentinels into many display globals (DAT_00691xxx) from the page descriptor's icon indices (+0x20/+0x28).

## Notes / uncertainty
Render-prep: seeds X/Y + 9999 off-screen sentinel for 2 buttons across 6 unrolled glyph-render instances. Why 6 instances inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006362e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
