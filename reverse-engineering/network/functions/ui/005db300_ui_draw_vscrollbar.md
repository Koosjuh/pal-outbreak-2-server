# 0x005db300 ui_draw_vscrollbar

| field | value |
|---|---|
| Original address | 0x005db300 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005db300 |
| Resolved name | ui_draw_vscrollbar |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005dfee0, FUN_005e07c0
**Referenced globals:** iRam00701070+0x1a/0x1c/0x20/0x22/0x24: scroll geometry; iRam00701070+0x18: flag word; iRam00701070+0x2a: overflow flag
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x18; 0x2a; 0x24

## Behavioral explanation
UI draw callback: renders a vertical scrollbar (track + thumb) via FUN_005e07c0 sprite draws, computing thumb position from scroll offset +8 and content height ratios.

## Notes / uncertainty
Draw cb: up/down arrows (tiles 0xa/0xe,0xb/0xf normal/pressed), track 0x12, proportional thumb 0x13 gated on overflow flag +0x2a; thumb-y from scroll*track/maxheight. Style bit 0x04 compact-layout mapping (380 vs 416) inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005db300.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
