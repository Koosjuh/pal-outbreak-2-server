# 0x0017f2b8 dbcman_bind

| field | value |
|---|---|
| Original address | 0x0017f2b8 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_0017f2b8 |
| Resolved name | dbcman_bind |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0017eb98
**Callees:** FUN_00113198, FUN_00115c68, FUN_0011b8e0, FUN_0011b938, FUN_0017fd00
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
Sync RPC fn0x303 BIND with link-state guard: snapshots IOP-updated flag table 0x27e480->0x27e500 under interrupt-disable, returns 0xfffffff4 if snapshot flag[idx]!=1, else RPC returns bind handle. '1==active' inferred.

## Raw decompilation
`sources/executables/netstack-decompile/FUN_0017f2b8.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
