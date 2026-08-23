# 0x001ef5c0 snap_req_op02

| field | value |
|---|---|
| Original address | 0x001ef5c0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ef5c0 |
| Resolved name | snap_req_op02 |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001eeec0
**Callees:** FUN_001ef3e0, FUN_001ef3f0, FUN_001ef400
**Referenced globals:** 0x37cf00 (request buf); 0x37bf18 (result)
**Referenced strings:** —
**Referenced opcodes:** 0x02
**State vars:** —

## Behavioral explanation
SN@P RPC stub: sends app opcode 0x02 with empty body (likely session close/status), returns result.

## Notes / uncertainty
SIF-RPC op02, empty body (cmd2, len 0x20). Close/status role inferred -> Medium. Parallel EE op02 handlers exist.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ef5c0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
