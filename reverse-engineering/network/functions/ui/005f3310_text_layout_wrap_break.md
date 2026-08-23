# 0x005f3310 text_layout_wrap_break

| field | value |
|---|---|
| Original address | 0x005f3310 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f3310 |
| Resolved name | text_layout_wrap_break |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f3420
**Callees:** FUN_005ec170, FUN_005ed1a0, FUN_005ed430, FUN_005ef780, FUN_005f3150
**Referenced globals:** iRam007012a0(text ctx: 0xd894 line-idx, 0xd8c8/0xd8ce/0xd8d2 pen, 0x1c cursor)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** iRam007012a0+0x186

## Behavioral explanation
Inserts a line break in the text layout: flushes current line width, resets pen to margin.

## Notes / uncertainty
Word-wrap line-break: terminates pending run in run-buf, flushes via 005f3150, resets pen, emits block descriptor at blockBase+0x24e0 (stride 0x5c). FUN_005f3150 flush semantics inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f3310.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
