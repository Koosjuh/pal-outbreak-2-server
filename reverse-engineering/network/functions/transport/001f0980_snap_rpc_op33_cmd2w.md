# 0x001f0980 snap_rpc_op33_cmd2w

| field | value |
|---|---|
| Original address | 0x001f0980 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001f0980 |
| Resolved name | snap_rpc_op33_cmd2w |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001ef0a0
**Callees:** FUN_001ef3e0, FUN_001ef3f0, FUN_001ef400
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
fno 0x33, command with two u32 in-words @+0x1c/+0x20 (ssize 0x28). Caller FUN_001ef0a0 passes no args; word meanings unknown.

## Raw decompilation
`sources/executables/netstack-decompile/FUN_001f0980.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
