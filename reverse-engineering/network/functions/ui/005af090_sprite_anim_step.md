# 0x005af090 sprite_anim_step

| field | value |
|---|---|
| Original address | 0x005af090 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005af090 |
| Resolved name | sprite_anim_step |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005acab0
**Callees:** —
**Referenced globals:** 0x34363e PAL timing flag; 0x692670 timing scale
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x1468 frame timer; +0x146a redraw; +0x146b enable; +0x146c frame index

## Behavioral explanation
Advances a sprite frame animation: when enabled (+0x146b), decrements the frame timer (+0x1468) and on expiry loads the next frame duration from the frame table (+0x1464) and raises the redraw flag (+0x146a).

## Notes / uncertainty
Per-frame sprite clock: counts +0x1468, on expiry reloads from u16 frame-duration table +0x1464[+0x146c], PAL-scaled, raises redraw +0x146a. Does NOT advance frame index +0x146c (done by render consumer); table wrap behavior unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005af090.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
