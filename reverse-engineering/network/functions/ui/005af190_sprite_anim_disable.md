# 0x005af190 sprite_anim_disable

| field | value |
|---|---|
| Original address | 0x005af190 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005af190 |
| Resolved name | sprite_anim_disable |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f8ec0
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x146b enable

## Behavioral explanation
Clears the sprite-animation enable flag (+0x146b=0) to stop the animation.

## Notes / uncertainty
One-line setter: +0x146b enable=0, freezes anim on current frame. Trivial, no material uncertainty.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005af190.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
