# 0x001ef1c0 snap_once_latch_cache

| field | value |
|---|---|
| Original address | 0x001ef1c0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ef1c0 |
| Resolved name | snap_once_latch_cache |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001c0ca0, FUN_001ee1e0
**Callees:** FUN_001f0d90
**Referenced globals:** 0x37a278 (latch guard); 0x37a280 (cached value)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x37a278; 0x37a280

## Behavioral explanation
One-time latch: on first call, if FUN_001f0d90() succeeds sets guard 0x37a278=1 and caches *param_1 into 0x37a280; on subsequent calls returns 1 and hands the cached value back.

## Notes / uncertainty
Memoize-once: first success latches guard a278=1 and caches *param_1->a280; later calls serve cached value + return 1. FUN_001f0d90 is a readiness gate (value comes from caller, not query). Reset by FUN_001ef230. Cached value's meaning unconfirmed.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ef1c0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
