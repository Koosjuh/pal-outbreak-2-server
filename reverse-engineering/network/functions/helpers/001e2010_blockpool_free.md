# 0x001e2010 blockpool_free

| field | value |
|---|---|
| Original address | 0x001e2010 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001e2010 |
| Resolved name | blockpool_free |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d46ec, FUN_001d5138, FUN_001e14e8, FUN_001e1608, FUN_001eb918, FUN_001ebe28, FUN_001ecdc0, FUN_001ee024
**Callees:** —
**Referenced globals:** arena block magic
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** block magic 0xfafafafa

## Behavioral explanation
Frees a block by writing the free magic (0xfafafafa) into its header word (ptr-8).

## Notes / uncertainty
Writes FREE magic 0xfafafafa to (payload-8); exact inverse of alloc. No double-free guard.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001e2010.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
