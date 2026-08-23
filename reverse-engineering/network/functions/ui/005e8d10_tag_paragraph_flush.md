# 0x005e8d10 tag_paragraph_flush

| field | value |
|---|---|
| Original address | 0x005e8d10 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e8d10 |
| Resolved name | tag_paragraph_flush |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005eef70
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Markup tag handler: consumes the tag arg and does nothing else (no-op placeholder tag).

## Notes / uncertainty
Not a no-op: tail-calls FUN_005eef70 = paragraph flush + pen restore (+0xd8c0/c2 -> +0xd8bc/be). Suggest rename tag_paragraph_flush.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e8d10.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
