# 0x005e8ad0 tag_oneshot_flush_18d

| field | value |
|---|---|
| Original address | 0x005e8ad0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e8ad0 |
| Resolved name | tag_oneshot_flush_18d |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ef040, FUN_005ef0e0
**Referenced globals:** +0x18d (one-shot latch); +0x188/+0x153c
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x18d; +0x188

## Behavioral explanation
Markup tag handler: one-shot flush guarded by latch +0x18d (flushes once, sets +0x18d=1).

## Notes / uncertainty
One-shot break latched by +0x18d (fires once, sets latch=1); reset by 0x5e8b40. Owning tag-string unresolved.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e8ad0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
