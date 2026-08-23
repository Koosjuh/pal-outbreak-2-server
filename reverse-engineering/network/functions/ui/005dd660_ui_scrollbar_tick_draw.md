# 0x005dd660 ui_scrollbar_tick_draw

| field | value |
|---|---|
| Original address | 0x005dd660 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005dd660 |
| Resolved name | ui_scrollbar_tick_draw |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ddc20, FUN_005de330, FUN_005dfee0, FUN_005e4af0, FUN_005e4b00, FUN_005e4f10, FUN_005e5200, FUN_005e5650
**Referenced globals:** iRam00701068 (+0x60dc4 mode-c counter)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** param_1+6 mode; param_1+7 direction; param_1+0xc scroll pos; param_1+10 anim timer

## Behavioral explanation
Per-tick update/draw callback for the slider widget: animates position (+/-0xf, timer to 600) by mode byte at +6, dispatches to sub-draw fns, and in mode 1/2 draws two localized labels via FUN_005ddc20.

## Notes / uncertainty
Slider tick: ping-pong scroll pos +0xc by +/-0xf in [0,0xff], per-phase(3..7) sub-draw dispatch, phase1/2 arrow draw. Sub-draw fn contents not decoded.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005dd660.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
