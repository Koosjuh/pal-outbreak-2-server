# 0x001ebe28 buf_free

| field | value |
|---|---|
| Original address | 0x001ebe28 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ebe28 |
| Resolved name | buf_free |
| Subsystem | transport |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001eb9a0
**Callees:** FUN_001e2010
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Frees a buffer/list node via the module allocator and returns 0.

## Notes / uncertainty
Heap-free path via FUN_001e2010; no NULL guard in wrapper.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ebe28.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
