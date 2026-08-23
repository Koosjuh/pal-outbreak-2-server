# 0x005b6e10 draw_indexed_string_from_table

| field | value |
|---|---|
| Original address | 0x005b6e10 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b6e10 |
| Resolved name | draw_indexed_string_from_table |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005b7de0, FUN_0062fe70
**Referenced globals:** cRam006c4fe4 (draw-enable); DAT_00638e90/e94 (position/color table)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006c4fe4

## Behavioral explanation
If enabled (cRam006c4fe4): resolve a string table via FUN_0062fe70(id) and render it at a palette/position picked from DAT_00638e90 by param2, via the markup renderer FUN_005b7de0.

## Notes / uncertainty
Renamed from draw_indexed_glyph_string (renders a full markup string, not one glyph). Gated by cRam006c4fe4; anchor from DAT_00638e90 (8B stride). No decompiled caller found.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b6e10.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
