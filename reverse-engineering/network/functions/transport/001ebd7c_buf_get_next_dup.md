# 0x001ebd7c buf_get_next_dup

| field | value |
|---|---|
| Original address | 0x001ebd7c |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ebd7c |
| Resolved name | buf_get_next_dup |
| Subsystem | transport |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d5460, FUN_001d5ae4, FUN_001e16b4, FUN_001e1c10
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Returns *param_1 (next-link pointer) — duplicate of buf_get_next.

## Notes / uncertainty
Byte-identical twin of buf_get_next; source-level type distinction unrecoverable.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ebd7c.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
