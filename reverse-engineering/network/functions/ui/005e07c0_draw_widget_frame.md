# 0x005e07c0 draw_widget_frame

| field | value |
|---|---|
| Original address | 0x005e07c0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e07c0 |
| Resolved name | draw_widget_frame |
| Subsystem | ui |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005db300, FUN_005db8a0, FUN_005dbca0, FUN_005e2fa0, FUN_005e3a80, FUN_005e4840
**Callees:** FUN_005ddb40, FUN_005e00e0
**Referenced globals:** texture sheets via FUN_005e00e0
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Renders a widget frame/border/button in one of ~22 styles (switch on param_5=2..0x17), each a set of sprite blits (FUN_005ddb40); styles 0x16/0x17 recurse to compose scrollbar-arrow frames.

## Notes / uncertainty
Central widget renderer, switch(param_5) styles 2..0x17 (caption bars, capsule buttons, scrollbar strips, stretch panels, composite 0x16/0x17 recurse to style 7+arrow). Cull y<-32/>448; tint 0->-1. v-row state meaning (0x40/0x60/0x80/0xa0) and per-style visual mapping inferred; exact capsule mid-insets per case 6-9 preserved in raw.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e07c0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
