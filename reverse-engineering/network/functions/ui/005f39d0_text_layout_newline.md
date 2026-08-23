# 0x005f39d0 text_layout_newline

| field | value |
|---|---|
| Original address | 0x005f39d0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f39d0 |
| Resolved name | text_layout_newline |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f3bc0, FUN_005f3cc0
**Callees:** FUN_005ec170, FUN_005ed1a0, FUN_005ed430, FUN_005ef780
**Referenced globals:** iRam007012a0(0xd894 line-idx, 0x16 x-accum, 0x180 height, 0xd8d2 pen)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** iRam007012a0+0x186

## Behavioral explanation
Emits a newline in text layout, seeding line height from the char metric when unset.

## Notes / uncertainty
Hard newline: place-mode writes line-start X + seeds zero line-height from char metric 0x180; pen trio + block descriptor emit. out-rec +2 as line_h inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f39d0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
