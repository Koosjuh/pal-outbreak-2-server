# 0x005e5910 draw_tiled_glyph_fill

| field | value |
|---|---|
| Original address | 0x005e5910 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e5910 |
| Resolved name | draw_tiled_glyph_fill |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005e2760
**Callees:** FUN_005ddb40
**Referenced globals:** iRam00701068+0x68dd8 (glyph sheet handles), +0x68e28 (tile widths), +0x68e50 (tile heights); iRam00701070+4/+8 (scroll origin)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Fills an element's rect by tiling a glyph/pattern (sheet id param_2) across rows/cols using per-tile width/height tables @+0x68e28/+0x68e50, edge-clipping the last row/col.

## Notes / uncertainty
Tiles a glyph sheet (id&0xff) across element rect using width/height tables +0x68e28/+0x68e50, handle +0x68dd8, 0x200-tile cap. Decompiler degenerate guards + removed blocks make exact edge-clip math Medium confidence; counter &0xff vs 0x200 compare is a narrowing artifact.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e5910.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
