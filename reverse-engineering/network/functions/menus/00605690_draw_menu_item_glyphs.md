# 0x00605690 draw_menu_item_glyphs

| field | value |
|---|---|
| Original address | 0x00605690 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00605690 |
| Resolved name | draw_menu_item_glyphs |
| Subsystem | menus |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005af1e0, FUN_005af2c0, FUN_005af2e0, FUN_0062fdf0
**Referenced globals:** node+2 (item index); node+3 (clip flag)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Draw callback rendering a run of glyph/text records fetched from the menu-string table (FUN_0062fdf0 index 6+item), with optional scroll-clip when +3 flag set.

## Notes / uncertainty
Title/subtitle draw callback; marquee scroll (attr 0x400, color 0xff804000, mod 0x40) when flag3 set; walks 0xc-byte glyph records from FUN_0062fdf0(index+6). gfx palette/attr enum values opaque.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00605690.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
