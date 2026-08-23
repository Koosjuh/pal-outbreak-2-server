# 0x005eeca0 flush_text_buffer

| field | value |
|---|---|
| Original address | 0x005eeca0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005eeca0 |
| Resolved name | flush_text_buffer |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005eef70, FUN_005ef040, FUN_005ef0e0
**Callees:** FUN_005ed0c0
**Referenced globals:** iRam007012a0; +0x1c (buf idx); +0x20 (glyph buf); +0xd8c0/+0xd8bc/+0xd8c8 (cursor)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
If glyphs are pending (+0x1c!=0), records run width, NUL-terminates the buffer, draws it via layout_and_draw_rule, resets cursor/index.

## Notes / uncertainty
Terminal run flush (no line advance): if glyphs pending, record width, NUL-terminate, draw FUN_005ed0c0, reset run_start/len/word-state. Counterpart to ee840 minus wrap.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005eeca0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
