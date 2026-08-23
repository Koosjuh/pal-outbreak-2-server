# 0x001f0920 snap_rpc_op2e_query_u32

| field | value |
|---|---|
| Original address | 0x001f0920 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001f0920 |
| Resolved name | snap_rpc_op2e_query_u32 |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001ef160
**Callees:** FUN_001ef3e0, FUN_001ef3f0, FUN_001ef400
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
fno 0x2e, query returning one u32 @+0x1c (rsize 0x24). Sole caller FUN_001ef160 discards the word, keeps status. Value meaning unknown.

## Raw decompilation
`sources/executables/netstack-decompile/FUN_001f0920.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
