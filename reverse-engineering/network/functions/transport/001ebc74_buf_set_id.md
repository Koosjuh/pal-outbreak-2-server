# 0x001ebc74 buf_set_id

| field | value |
|---|---|
| Original address | 0x001ebc74 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ebc74 |
| Resolved name | buf_set_id |
| Subsystem | transport |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001ec9e0
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Sets the buffer's id/pool-index field (u16 at +10).

## Notes / uncertainty
Writes pool-tier index +0xa; tier MTUs 0xec/0x22c/0x3ac from subpool_free.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ebc74.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
