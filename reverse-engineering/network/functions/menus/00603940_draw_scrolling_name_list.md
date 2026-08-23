# 0x00603940 draw_scrolling_name_list

| field | value |
|---|---|
| Original address | 0x00603940 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00603940 |
| Resolved name | draw_scrolling_name_list |
| Subsystem | menus |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00601d50
**Callees:** FUN_005af1e0, FUN_005af2c0, FUN_005af2e0
**Referenced globals:** cRam006c553a (visible-item count); cRam006c555c (scroll offset); iRam003435d4 (overlay base ptr)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006c553a; cRam006c555c

## Behavioral explanation
Renders a scrolling list of up to 9 name entries (stride 0x80) from a UI table, one text row per item.

## Notes / uncertainty
Draws up to 9 scrolled rows from list @overlay_base+0xcd5ac (0x80 stride, scroll 0x6c555c); per-row color from node selector. Producer/consumer confirmed w/ 0x006038f0. Scroll-advance input not traced.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00603940.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
