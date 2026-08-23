# 0x005cd320 hud_draw_layers_enable

| field | value |
|---|---|
| Original address | 0x005cd320 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005cd320 |
| Resolved name | hud_draw_layers_enable |
| Subsystem | ui |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005c9460
**Callees:** FUN_005da8e0, FUN_005dae40, FUN_005db130, FUN_005db6d0, FUN_005dbb10, FUN_005dbf00, FUN_005dc3b0, FUN_005dca70, FUN_005dd3b0, FUN_005e0270
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Enables/initializes the overlay's draw layers and sprite groups (FUN_005e0270 + FUN_005da8e0..FUN_005dd3b0 each with arg 1).

## Notes / uncertainty
Arms HUD: FUN_005e0270(3),(4) + 9 sprite-group draws (arg1). Routines = legend glyph tables of 005ca6a0 + 0x10 (cross-ref confirmed). arg1=enable inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005cd320.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
