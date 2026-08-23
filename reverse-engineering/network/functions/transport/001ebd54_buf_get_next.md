# 0x001ebd54 buf_get_next

| field | value |
|---|---|
| Original address | 0x001ebd54 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ebd54 |
| Resolved name | buf_get_next |
| Subsystem | transport |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d5460, FUN_001d5ae4, FUN_001d72a8, FUN_001e16b4, FUN_001e1c10, FUN_001e40b0
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Returns the first field (*param_1) of the node — the next-link pointer.

## Notes / uncertainty
+0x0 next link; NULL at tail; byte-identical to 0x001ebd7c.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ebd54.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
