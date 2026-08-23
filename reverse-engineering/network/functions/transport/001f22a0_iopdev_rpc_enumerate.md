# 0x001f22a0 iopdev_rpc_enumerate

| field | value |
|---|---|
| Original address | 0x001f22a0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001f22a0 |
| Resolved name | iopdev_rpc_enumerate |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001d42e0, FUN_001d4630, FUN_001f1fe0
**Callees:** FUN_00114ac8, FUN_00115c68
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
Async RPC fno 1 (mode 1, send0x10/recv0x90, cb 0x1f2868); guarded on init sema DAT_0024e430; stashes pending-op=1 + result ptr. Returns 0/-2/-1. Domain unknown.

## Raw decompilation
`sources/executables/netstack-decompile/FUN_001f22a0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
