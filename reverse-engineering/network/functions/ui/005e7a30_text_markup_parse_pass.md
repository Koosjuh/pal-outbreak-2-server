# 0x005e7a30 text_markup_parse_pass

| field | value |
|---|---|
| Original address | 0x005e7a30 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e7a30 |
| Resolved name | text_markup_parse_pass |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005e7e30
**Callees:** FUN_005e6d50, FUN_005e7070, FUN_005eee00, FUN_005ef040, FUN_005f1570
**Referenced globals:** iRam007012a0 (text-render ctx base); 0x647850/0x647858 (mode-table entry, *0xc stride); 0x6481e8 (escape-tag dispatch table)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** iRam007012a0+0xc (raw/escape mode); +4 (out length); +0x18c (skip flag); +0xd968 (pass counter)

## Behavioral explanation
Main text tokenizer loop: copies chars to layout buffer (+0xd8e4), handles CR/LF/TAB (emits 4x 0x07), word-wrap, and escape-tag dispatch via strchr table 0x6481e8.

## Notes / uncertainty
Message-box text tokenizer/layout pass: copies glyphs to buffer +0xd8e4, handles CR/LF/TAB(->4x 0x07), word-wrap (thresh 0x7d/0x7a), escape-tag dispatch table 0x6481e8. Returns 1 paused/0 done/-1 error. Not network; CR/LF/TAB/0x07 are glyph codes. Multibyte decoder semantics of FUN_005e6d50 unpinned.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e7a30.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
