# 0x001ebc4c buf_get_id

| field | value |
|---|---|
| Original address | 0x001ebc4c |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ebc4c |
| Resolved name | buf_get_id |
| Subsystem | transport |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d5ae4
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Returns the buffer's id/pool-index field (u16 at +10).

## Notes / uncertainty
Reads pool-tier index at +0xa {0,1,2}; possible unpooled sentinel unconfirmed.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ebc4c.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
