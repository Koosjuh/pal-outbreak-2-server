# 0x0017f818 dbcman_transact

| field | value |
|---|---|
| Original address | 0x0017f818 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_0017f818 |
| Resolved name | dbcman_transact |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_00115c68, FUN_0017fd00
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
Semaphore-guarded sync RPC fn0x319: sends 2 arg words + payload (0x27b00c), returns status at +0x20c and length back. Send-with-status; arg-word roles unresolved.

## Raw decompilation
`sources/executables/netstack-decompile/FUN_0017f818.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
