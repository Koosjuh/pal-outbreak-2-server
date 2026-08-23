# 0x005ca6a0 menu_frame_button_legend_draw

| field | value |
|---|---|
| Original address | 0x005ca6a0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ca6a0 |
| Resolved name | menu_frame_button_legend_draw |
| Subsystem | ui |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005c9690, FUN_005c9900, FUN_005c9a00, FUN_005c9c50, FUN_005ca0a0, FUN_005ca1a0, FUN_005ca290, FUN_005ca320, FUN_005ca380, FUN_005ca420, FUN_005ca480, FUN_005ca4f0
**Callees:** FUN_005dd920, FUN_005dff90, FUN_005e0320
**Referenced globals:** 0x701070+0x36 flag; 0x701070+0x2e sub-state; 0x701070+0x3a flag; 0x701068+0x68e85 phase; 0x701068+0x60dca/0x60dcb flags; 0x701068+0x68e84 sub-phase
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x701070+0x36; 0x701070+0x2e; 0x701068+0x68e85; 0x701068+0x60dca; 0x701068+0x60dcb

## Behavioral explanation
Common per-screen render: sets the top color bar (FUN_005dd920 0x14) and draws the context-dependent button-legend / sprite tables (0x5da8d0..0x5dd3a0) based on current phase and flags.

## Notes / uncertainty
Shared soft-key legend renderer (12 callers): tint via FUN_005dd920(0x14) + context glyph tables 0x5da8d0..0x5dd3a0 gated on frame/kind/phase flags. Per-table glyph identity inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ca6a0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
