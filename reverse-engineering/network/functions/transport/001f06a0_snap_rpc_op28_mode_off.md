# 0x001f06a0 snap_rpc_op28_mode_off

| field | value |
|---|---|
| Original address | 0x001f06a0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001f06a0 |
| Resolved name | snap_rpc_op28_mode_off |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001eef80
**Callees:** FUN_001ef3e0, FUN_001ef3f0, FUN_001ef400
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
fno 0x28 (transport space, distinct from app op28 wire selector), parameterless. Wrapper FUN_001eef80 clears 0x37a2a2:=0. Disable half of op27/op28 pair.

## Raw decompilation
`sources/executables/netstack-decompile/FUN_001f06a0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
