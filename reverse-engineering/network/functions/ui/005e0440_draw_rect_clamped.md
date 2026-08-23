# 0x005e0440 draw_rect_clamped

| field | value |
|---|---|
| Original address | 0x005e0440 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e0440 |
| Resolved name | draw_rect_clamped |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005daf30, FUN_005e2030, FUN_005e2060, FUN_005e2760, FUN_005e2fa0, FUN_005e3a80
**Callees:** FUN_005dda30
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Clamps a rectangle to the 640x448 screen and draws it filled via FUN_005dda30.

## Notes / uncertainty
Clamps rect to 640x448 and fills via FUN_005dda30. Note asymmetry: top-left y capped at 640 while bottom y capped at 448 (relies on caller y0<y1 or source quirk); preserved.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e0440.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
