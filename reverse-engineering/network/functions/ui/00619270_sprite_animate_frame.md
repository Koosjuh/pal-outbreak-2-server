# 0x00619270 sprite_animate_frame

| field | value |
|---|---|
| Original address | 0x00619270 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00619270 |
| Resolved name | sprite_animate_frame |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00619220
**Callees:** —
**Referenced globals:** 0x6543d0 anim-rate table
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** *(obj+4) anim init flag

## Behavioral explanation
Advances a sprite's animation: on first tick seeds rate/size from a table, then accumulates a float frame counter into the X-cell field, wrapping at 0x200.

## Notes / uncertainty
Horizontal scroll/frame anim: lazy-init (state +0x04:0->1) loads rate DAT_006543d0[+0x03], seeds override rect (+0x44/+0x46=0x200) and sets flag 0x400; then float acc(+0x50)+=rate, cell(+0x40)=floor, wrap at 512. Override fields exactly match sprite_draw_entry's 0x400 branch. Rate table contents unread.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00619270.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
