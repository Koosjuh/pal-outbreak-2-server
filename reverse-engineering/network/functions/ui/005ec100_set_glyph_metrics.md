# 0x005ec100 set_glyph_metrics

| field | value |
|---|---|
| Original address | 0x005ec100 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ec100 |
| Resolved name | set_glyph_metrics |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005e7710, FUN_005e8580, FUN_005e8600, FUN_005ea900, FUN_005eb5a0, FUN_005eb640, FUN_005ebd20, FUN_005ef220, FUN_005ef380, FUN_005ef3f0
**Callees:** —
**Referenced globals:** iRam007012a0; 0x6494c0/0x6494d0 (font metric tables); +0x180/+0x181 (glyph w/h); +0x124/+0x168 (font sel)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Sets current glyph width/height (ctx +0x180/+0x181) by indexing font-metric tables at 0x6494c0/0x6494d0 by style byte and current font (+0x124/+0x168).

## Notes / uncertainty
Loads glyph w/h (+0x180/+0x181) from parallel tables 0x6494c0/0x6494d0 indexed by [font_byte + style*8]. 10 callers across text renderer.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ec100.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
