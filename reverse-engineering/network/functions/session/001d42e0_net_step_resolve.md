# 0x001d42e0 net_step_resolve

| field | value |
|---|---|
| Original address | 0x001d42e0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d42e0 |
| Resolved name | net_step_resolve |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001f22a0, FUN_001f27c8
**Referenced globals:** 0x36d640 target; 0x36d598 handle; 0x36d644 result
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** iRam0036d598; iRam0036d644

## Behavioral explanation
State step: queries FUN_001f22a0/FUN_001f27c8 (resolve/status), stores handle 0x36d598, advances on success.

## Notes / uncertainty
DNS/resolve step: primes FUN_001f22a0(0x36d640), polls FUN_001f27c8(&busy)->handle 0x36d598; when done & ready-flag 0x36d644 set -> advance, else reset. Library-call directions inferred.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d42e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
