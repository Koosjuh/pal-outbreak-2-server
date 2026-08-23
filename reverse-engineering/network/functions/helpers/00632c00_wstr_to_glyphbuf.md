# 0x00632c00 wstr_to_glyphbuf

| field | value |
|---|---|
| Original address | 0x00632c00 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00632c00 |
| Resolved name | wstr_to_glyphbuf |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00632390, FUN_00633c10, FUN_00634ab0
**Callees:** FUN_00637d10
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Converts a wide-char (short[]) string to a packed glyph/draw byte buffer, encoding each code via FUN_00637d10 and appending.

## Notes / uncertainty
UTF-16 string -> packed glyph byte buffer via FUN_00637d10 encode + byte strcat. func_0x00109ab0 assumed strcat.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00632c00.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
