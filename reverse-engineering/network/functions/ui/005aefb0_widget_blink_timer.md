# 0x005aefb0 widget_blink_timer

| field | value |
|---|---|
| Original address | 0x005aefb0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005aefb0 |
| Resolved name | widget_blink_timer |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005acab0
**Callees:** —
**Referenced globals:** 0x34363e cRam0034363e PAL/50Hz timing flag; 0x692670 DAT_00692670 timing scale
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x984/+0x980/+0x988 timers; +0x97f redraw flag

## Behavioral explanation
Per-frame blink/interval timer for a widget: reloads counters (+0x984 to 0x1e/0x19, +0x988), scaling reload values by DAT_00692670 when the PAL/timing flag cRam0034363e is set, and raises a redraw flag (+0x97f).

## Notes / uncertainty
Per-frame blink timer: throttle +0x984 (0x1e/0x19), one-shot +0x980, blink +0x988 (0x14/0x10), raises redraw +0x97f; PAL scaling via cRam0034363e + DAT_00692670. Which visual element it drives not traced.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005aefb0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
