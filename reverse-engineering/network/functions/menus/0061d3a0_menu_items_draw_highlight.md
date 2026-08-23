# 0x0061d3a0 menu_items_draw_highlight

| field | value |
|---|---|
| Original address | 0x0061d3a0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0061d3a0 |
| Resolved name | menu_items_draw_highlight |
| Subsystem | menus |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00619800
**Callees:** FUN_0061cc80
**Referenced globals:** 0x665e10 item-string table; 0x666870 item-layout table; 0x6668c0 item counts; cRam003c98a0/003c9580 enable flags
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam003c98a0; cRam003c9580

## Behavioral explanation
Renders menu item rows from table DAT_00665e10/PTR_DAT_00666870, greying out specific rows when feature flags (cRam003c98a0/003c9580) are off.

## Notes / uncertainty
Draws selectable item page (<0x11) from 0x665e10/0x666870, count 0x6668c0, palette 0x669c00. Page1 greys items 1/2 (colour->4) when enable flags cRam003c98a0/cRam003c9580 clear (draw-side unlock gating). Two arms use different 8-byte layout field orders (decompiler-emitted, unreconciled); which features the flags gate unknown.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0061d3a0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
