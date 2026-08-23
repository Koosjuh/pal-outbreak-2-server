# 0x001f0ad0 snap_rpc_op37_cmd2w

| field | value |
|---|---|
| Original address | 0x001f0ad0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001f0ad0 |
| Resolved name | snap_rpc_op37_cmd2w |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001ef190
**Callees:** FUN_001ef3e0, FUN_001ef3f0, FUN_001ef400
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
fno 0x37, two u32 in-words @+0x1c/+0x20 (ssize 0x28), same shape as op33. Caller FUN_001ef190 supplies only first word (*ptr); second effectively unused. Meaning unknown.

## Raw decompilation
`sources/executables/netstack-decompile/FUN_001f0ad0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
