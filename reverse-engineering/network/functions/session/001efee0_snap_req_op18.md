# 0x001efee0 snap_req_op18

| field | value |
|---|---|
| Original address | 0x001efee0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001efee0 |
| Resolved name | snap_req_op18 |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001e3100
**Callees:** FUN_001ef3e0, FUN_001ef3f0, FUN_001ef400
**Referenced globals:** 0x37cf1c (param1, 4B); 0x37cf20 (2B); 0x37cf22 (2B); 0x37bf18 (result)
**Referenced strings:** —
**Referenced opcodes:** 0x18
**State vars:** —

## Behavioral explanation
SN@P RPC stub: sends app opcode 0x18 with a 32-bit word plus two 16-bit fields, returns result.

## Notes / uncertainty
id32+a16+b16 (leave-family body shape), result-only, opcode 0x18. Likely membership/room mutation. Semantics inferred.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001efee0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
