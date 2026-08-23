# 0x00618c90 sprite_compositor_render

| field | value |
|---|---|
| Original address | 0x00618c90 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00618c90 |
| Resolved name | sprite_compositor_render |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_00618e30, FUN_00619170, FUN_00619220, FUN_00636890, FUN_00637170
**Referenced globals:** 0x7133f0 sprite table; cRam006c4fd7 draw-fixed flag; cRam006c5538 flag; sRam006c5524; cRam006c4fde flush flag
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006c4fd7; cRam006c5538; cRam006c4fde

## Behavioral explanation
Main 2D overlay render pass: draws the sprite table in three layer passes (+0x30 == 1,0,2) via sprite_draw_entry, plus fixed-list overlays, then flushes.

## Notes / uncertainty
Main overlay render: 3 layer passes (+0x30==1,0,2 order) via sprite_draw_entry, gated fixed pair (cRam6c4fd7) + partlist (cRam6c5538) passes, idle-flush, final flush (cRam6c4fde). Active test = byte0&byte1. Gates cross-confirmed w/ ui_reset_view_flags. GS reg semantics inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00618c90.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
