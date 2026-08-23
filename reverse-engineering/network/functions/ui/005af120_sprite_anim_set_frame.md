# 0x005af120 sprite_anim_set_frame

| field | value |
|---|---|
| Original address | 0x005af120 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005af120 |
| Resolved name | sprite_anim_set_frame |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005acd60, FUN_005acda0, FUN_005acea0, FUN_005f74d0, FUN_005f7570, FUN_0062e440
**Callees:** —
**Referenced globals:** 0x34363e PAL timing flag; 0x692670 timing scale
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x1468 timer; +0x146a redraw; +0x146b enable; +0x146c frame index

## Behavioral explanation
Initializes a sprite animation to frame index param_2: loads that frame's duration from the table (+0x1464, region-scaled), stores the index, clears redraw and enables the animation.

## Notes / uncertainty
Seeks sprite-anim to frame: loads duration table[+0x1464], PAL-scales via DAT_00692670 when cRam0034363e==1, stores index/timer, clears event flag, enables. PAL scale value not read (inferred ~5/6).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005af120.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
