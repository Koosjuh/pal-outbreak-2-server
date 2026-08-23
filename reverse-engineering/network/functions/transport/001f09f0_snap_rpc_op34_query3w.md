# 0x001f09f0 snap_rpc_op34_query3w

| field | value |
|---|---|
| Original address | 0x001f09f0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001f09f0 |
| Resolved name | snap_rpc_op34_query3w |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001ef100
**Callees:** FUN_001ef3e0, FUN_001ef3f0, FUN_001ef400
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
fno 0x34, query returning three u32 @+0x1c/+0x20/+0x24 (rsize 0x2c). Caller FUN_001ef100 keeps first two (adjacent struct fields), discards third. Meaning unknown.

## Raw decompilation
`sources/executables/netstack-decompile/FUN_001f09f0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
