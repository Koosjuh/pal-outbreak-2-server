# 0x001f2348 iopdev_rpc_open

| field | value |
|---|---|
| Original address | 0x001f2348 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001f2348 |
| Resolved name | iopdev_rpc_open |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001d44f0
**Callees:** FUN_00114ac8, FUN_00115c68
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
Async RPC fno 2 (open/select device[index]); bounds index<count; recv0x50; pending-op=2. Returns 0/-0xb/-2/-1. Domain unknown.

## Raw decompilation
`sources/executables/netstack-decompile/FUN_001f2348.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
