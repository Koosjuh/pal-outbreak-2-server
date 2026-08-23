# 0x005b7f00 utf8_char_len

| field | value |
|---|---|
| Original address | 0x005b7f00 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b7f00 |
| Resolved name | utf8_char_len |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005b6ea0, FUN_005b7270, FUN_005b7320, FUN_005b7cd0, FUN_005b7de0, FUN_005b7f70
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Return the byte-length (1-5) of a multibyte/UTF-8-style lead byte, or -1 (0xff) for an invalid continuation-only byte.

## Notes / uncertainty
UTF-8 lead-byte width 1..5, -1(0xff) for stray continuation; error sentinel for tokenizer. Whether text is UTF-8 vs SJIS-like unresolved but irrelevant to the classifier.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b7f00.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
