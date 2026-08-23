# 0x005eca10 draw_text_decoration_line

| field | value |
|---|---|
| Original address | 0x005eca10 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005eca10 |
| Resolved name | draw_text_decoration_line |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005ed0c0, FUN_005f3150
**Callees:** FUN_005d8b90, FUN_005d8c90, FUN_005d9bd0, FUN_005d9ca0
**Referenced globals:** iRam007012a0; +0x17f (rule style); +0x180 (glyph w); +0xd8c8 (x adj)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x17f; +0x17d/+0x17e

## Behavioral explanation
Draws a horizontal rule/underline styled by +0x17f (0..3) and border flags +0x17d/+0x17e, dispatching to line-draw primitives (FUN_005d8b90/8c90/9bd0/9ca0) at the current cursor.

## Notes / uncertainty
Underline/rule/border stroke gated by href(+0x20) or force(+0xe96b); 4-way style switch (+0x17f) x border flags (+0x17d/17e) selecting 8b90/8c90/9bd0/9ca0. Primitive signatures & style labels inferred. Renamed from draw_hrule_or_underline.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005eca10.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
