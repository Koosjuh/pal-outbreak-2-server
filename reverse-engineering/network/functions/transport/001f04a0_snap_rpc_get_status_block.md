# 0x001f04a0 snap_rpc_get_status_block

| field | value |
|---|---|
| Original address | 0x001f04a0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001f04a0 |
| Resolved name | snap_rpc_get_status_block |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001ee930, FUN_001eeb50
**Callees:** FUN_001ef3e0, FUN_001ef3f0, FUN_001ef400
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
No-arg SIF-RPC selector 0x23, returns 11-word (0x2c) info block from reply. Consumed by FUN_001eeb50 (two enum fields 0-9/0-13) for link/session status. Per-word meaning partial.

## Raw decompilation
`sources/executables/netstack-decompile/FUN_001f04a0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
