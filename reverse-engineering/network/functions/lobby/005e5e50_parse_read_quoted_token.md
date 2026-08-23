# 0x005e5e50 parse_read_quoted_token

| field | value |
|---|---|
| Original address | 0x005e5e50 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e5e50 |
| Resolved name | parse_read_quoted_token |
| Subsystem | lobby |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005e60c0, FUN_005e67a0
**Callees:** —
**Referenced globals:** iRam007012a0+0xd964 (parse cursor ptr)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** iRam007012a0+0xd964

## Behavioral explanation
Text-protocol tokenizer: reads a double-quoted string value from the server-message parse cursor (@0x7012a0+0xd964) into a caller buffer, honoring CR/LF and length limit; returns 0 on success, 1 on '<' tag, -1 on EOF.

## Notes / uncertainty
Reads next double-quoted value from parser cursor (iRam007012a0+0xd964) into buf[cap]; modes find-quote/copy/drain, folds CR/LF, truncates on overflow. Returns 0 ok / 1 hit '<' tag / -1 EOF. CRLF-fold pairing edge preserved as-decompiled.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e5e50.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
