# 0x001f0560 snap_rpc_get_word

| field | value |
|---|---|
| Original address | 0x001f0560 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001f0560 |
| Resolved name | snap_rpc_get_word |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001ee9d0
**Callees:** FUN_001ef3e0, FUN_001ef3f0, FUN_001ef400
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
No-arg SIF-RPC selector 0x24, returns single reply word (0x37bf1c)+status. Same 0x4c recv as 0x23 but only word0 used; which scalar is unresolved.

## Raw decompilation
`sources/executables/netstack-decompile/FUN_001f0560.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
