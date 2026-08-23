# 0x001ebd04 buf_get_capacity

| field | value |
|---|---|
| Original address | 0x001ebd04 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ebd04 |
| Resolved name | buf_get_capacity |
| Subsystem | transport |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d5ae4, FUN_001ec9e0, FUN_001ed360, FUN_001ed6ec, FUN_001ed924
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Returns the buffer's allocated capacity/size field (u16 at +8).

## Notes / uncertainty
Reads capacity +0x8; allocation site that sets it is outside this batch.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ebd04.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
