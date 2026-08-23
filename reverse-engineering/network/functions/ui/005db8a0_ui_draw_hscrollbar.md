# 0x005db8a0 ui_draw_hscrollbar

| field | value |
|---|---|
| Original address | 0x005db8a0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005db8a0 |
| Resolved name | ui_draw_hscrollbar |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005dfee0, FUN_005e07c0
**Referenced globals:** iRam00701070+0x1a/0x20/0x26/0x28: scroll geometry; iRam00701070+0x2b: overflow flag; iRam00701070+0x18
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x18; 0x2b; 0x28

## Behavioral explanation
UI draw callback: renders a horizontal scrollbar (track + thumb) via FUN_005e07c0, computing thumb X from scroll offset +4 and content width ratios.

## Notes / uncertainty
Draw cb: track+thumb sprites via FUN_005e07c0, thumb X = left+(scroll*552/content_w)+16, gated by view+0x18 bit1. FUN_005e07c0 arg contract (w vs kind) inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005db8a0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
