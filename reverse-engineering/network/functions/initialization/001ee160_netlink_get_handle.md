# 0x001ee160 netlink_get_handle

| field | value |
|---|---|
| Original address | 0x001ee160 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ee160 |
| Resolved name | netlink_get_handle |
| Subsystem | initialization |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001ee1e0
**Callees:** FUN_001ef2e0
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Thin wrapper returning FUN_001ef2e0() (fetch a link/socket handle or id, u16).

## Notes / uncertainty
Returns FUN_001ef2e0() u16 as a link handle; used as non-zero validity gate by poller 1ee1e0. handle-vs-status meaning of 1ef2e0 inferred.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ee160.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
