# 0x001ef540 snap_req_op01_session_open

| field | value |
|---|---|
| Original address | 0x001ef540 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ef540 |
| Resolved name | snap_req_op01_session_open |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001eedf0
**Callees:** FUN_001ef3e0, FUN_001ef3f0, FUN_001ef400
**Referenced globals:** 0x37cf1c (param1 field); 0x37cf20 (param2); 0x37cf24 (param3); 0x37bf18 (result)
**Referenced strings:** —
**Referenced opcodes:** 0x01
**State vars:** —

## Behavioral explanation
SN@P RPC stub: sends app opcode 0x01 carrying three 32-bit config words (likely session-open/login params), returns result.

## Notes / uncertainty
SIF-RPC op01, 3x u32 body at +0x1c/+0x20/+0x24 (cmd1, len 0x2c). Session-open/login role INFERRED (structure certain) -> Medium. Parallel EE path exists.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ef540.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
