# 0x001d51e0 snap_alloc_subctx

| field | value |
|---|---|
| Original address | 0x001d51e0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d51e0 |
| Resolved name | snap_alloc_subctx |
| Subsystem | transport |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d46ec
**Callees:** FUN_001e1e4c, FUN_001eb22c
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Allocates and zero-inits a 0x1c sub-context struct with an embedded list head at +8.

## Notes / uncertainty
Allocates+zeroes 0x1c sub-context with list head at +8; two head words (+0/+4) purpose unconfirmed.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d51e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
