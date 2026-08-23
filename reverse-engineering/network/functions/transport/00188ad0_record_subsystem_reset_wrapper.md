# 0x00188ad0 record_subsystem_reset_wrapper

| field | value |
|---|---|
| Original address | 0x00188ad0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_00188ad0 |
| Resolved name | record_subsystem_reset_wrapper |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001d0510, FUN_001d06d0
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
Trivial shim: calls thunk_FUN_00197ae0 (tagged-record ctx select/init), always returns 1. Purpose of the callee inferred, not decompiled here.

## Raw decompilation
`sources/executables/netstack-decompile/FUN_00188ad0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
