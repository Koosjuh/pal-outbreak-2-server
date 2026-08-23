# 0x001f25e0 iopdev_rpc_set_mode

| field | value |
|---|---|
| Original address | 0x001f25e0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001f25e0 |
| Resolved name | iopdev_rpc_set_mode |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001d4450
**Callees:** FUN_00114ac8, FUN_00115c68
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
Async RPC fno 5 (set device[index].mode 0..2); mirrors mode into local block+0x00; bounds index<count & mode<3; pending-op=5. Returns 0/-0xc/-0xb/-2/-1. Confirms 0x38 stride/table base 0x37e944.

## Raw decompilation
`sources/executables/netstack-decompile/FUN_001f25e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
