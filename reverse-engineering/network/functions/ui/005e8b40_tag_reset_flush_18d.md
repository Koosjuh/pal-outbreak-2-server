# 0x005e8b40 tag_reset_flush_18d

| field | value |
|---|---|
| Original address | 0x005e8b40 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e8b40 |
| Resolved name | tag_reset_flush_18d |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ef040, FUN_005ef0e0
**Referenced globals:** +0x18d (latch); +0x188/+0x153c
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x18d; +0x188

## Behavioral explanation
Markup tag handler: clears latch +0x18d then flushes if per-page value +0x153c non-zero.

## Notes / uncertainty
Re-arm half of the one-shot pair: clears latch +0x18d then break-if-pending. 'group' boundary inferred from latch pairing.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e8b40.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
