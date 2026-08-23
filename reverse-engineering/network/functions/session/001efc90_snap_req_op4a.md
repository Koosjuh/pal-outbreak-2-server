# 0x001efc90 snap_req_op4a

| field | value |
|---|---|
| Original address | 0x001efc90 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001efc90 |
| Resolved name | snap_req_op4a |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001ee680
**Callees:** FUN_001ef3e0, FUN_001ef3f0, FUN_001ef400
**Referenced globals:** 0x37cf1c (id, 2B); 0x37bf18 (result)
**Referenced strings:** —
**Referenced opcodes:** 0x4a
**State vars:** —

## Behavioral explanation
SN@P RPC stub: sends app opcode 0x4a with a single 16-bit id, returns result.

## Notes / uncertainty
Single-u16-id stub. Opcode 0x4a in directory band (0x48/0x49); likely list-control. Semantics inferred.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001efc90.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
