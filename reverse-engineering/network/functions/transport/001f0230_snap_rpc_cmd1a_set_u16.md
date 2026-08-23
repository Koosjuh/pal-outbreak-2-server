# 0x001f0230 snap_rpc_cmd1a_set_u16

| field | value |
|---|---|
| Original address | 0x001f0230 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001f0230 |
| Resolved name | snap_rpc_cmd1a_set_u16 |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001e3f98
**Callees:** FUN_001ef3e0, FUN_001ef3f0, FUN_001ef400
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
SIF-RPC stub selector 0x1a, one u16 arg @req+0x1c, returns status. Setter/selector; exact command meaning unknown w/o runtime.

## Raw decompilation
`sources/executables/netstack-decompile/FUN_001f0230.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
