# 0x005eee00 text_flush_keep_trailing_char

| field | value |
|---|---|
| Original address | 0x005eee00 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005eee00 |
| Resolved name | text_flush_keep_trailing_char |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005e7a30, FUN_005ea520, FUN_005ea5a0, FUN_005ea620, FUN_005ea6a0, FUN_005ea720, FUN_005ea7a0
**Callees:** FUN_005eef70
**Referenced globals:** iRam007012a0; +0x4 (buffer length)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Word-break helper: scans a text buffer (len at +0x4) to find a trailing multibyte word, splits it off into a temp, renders the head via render_text_token, and leaves the split word back in the buffer.

## Notes / uncertainty
Auto-flush splitter: renders head text run then carries the final multibyte glyph (0x80-lead scan) forward so a glyph is never split across a flush. Renamed from split_trailing_word. Buffer capacity/trigger unvalidated.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005eee00.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
