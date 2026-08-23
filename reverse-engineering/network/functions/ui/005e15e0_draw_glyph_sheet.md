# 0x005e15e0 draw_glyph_sheet

| field | value |
|---|---|
| Original address | 0x005e15e0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e15e0 |
| Resolved name | draw_glyph_sheet |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005daba0, FUN_005e2fa0
**Callees:** FUN_005ddb40
**Referenced globals:** iRam00701068+0x68dd8 (glyph sheet handle table)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Blits a single glyph/tile from the font/glyph sheet table @+0x68dd8 indexed by param_5.

## Notes / uncertainty
Whole-texture blit (UV 0,0) of a font/glyph sheet from table base+0x68dd8 indexed by param_5&0xffff; no bounds check. Entries assumed prebuilt text/font pages.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e15e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
