# 0x005f3cc0 draw_text_justify_c

| field | value |
|---|---|
| Original address | 0x005f3cc0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f3cc0 |
| Resolved name | draw_text_justify_c |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ef0e0
**Callees:** FUN_005ec170, FUN_005ef780, FUN_005f3420, FUN_005f3930, FUN_005f39d0
**Referenced globals:** iRam007012a0(0x188, 0x1540, 0xd894, 0xd8ce, 0x2518, 0x04)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** iRam007012a0+0x186, 0xd8ce

## Behavioral explanation
Text draw entry (justify variant C): word-wrap + line-flush, conditional newline over text context.

## Notes / uncertainty
Like B but newline conditional on pen-X(0xd8ce)!=0 to suppress blank line on empty line. Only structural diff from B.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f3cc0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
