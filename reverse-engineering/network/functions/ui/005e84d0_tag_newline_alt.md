# 0x005e84d0 tag_newline_alt

| field | value |
|---|---|
| Original address | 0x005e84d0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e84d0 |
| Resolved name | tag_newline_alt |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ef040
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Markup tag handler identical to 0x5e84b0: emits newline/flush (FUN_005ef040).

## Notes / uncertainty
Duplicate of 0x005e84b0 — second tag code bound to same flush+line-feed primitive.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e84d0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
