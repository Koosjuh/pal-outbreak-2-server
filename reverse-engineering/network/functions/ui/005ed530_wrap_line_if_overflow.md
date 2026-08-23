# 0x005ed530 wrap_line_if_overflow

| field | value |
|---|---|
| Original address | 0x005ed530 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ed530 |
| Resolved name | wrap_line_if_overflow |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ed6e0
**Callees:** FUN_005eced0, FUN_005ed460, FUN_005f2710
**Referenced globals:** iRam007012a0; +0x10 (container width); +0xd8bc/+0xd8c4/+0xd8be (cursor); +0x186 (pass)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x186; +0xd892

## Behavioral explanation
Advances x by indent/center offset; on the draw pass triggers layout_newline when the next glyph would overflow the container width (+0x10).

## Notes / uncertainty
Word-wrap decision: render pass positions x (indent+center), measure pass breaks via layout_newline when cur_x+glyph_w>box_width and line non-empty; nested->FUN_005f2710.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ed530.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
