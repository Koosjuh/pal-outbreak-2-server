# 0x001efe70 snap_req_op1d_roomlist

| field | value |
|---|---|
| Original address | 0x001efe70 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001efe70 |
| Resolved name | snap_req_op1d_roomlist |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001ef000
**Callees:** FUN_001ef3e0, FUN_001ef3f0, FUN_001ef400
**Referenced globals:** 0x37cf1c (param1, 4B); 0x37cf20 (param2, 4B); 0x37bf18 (result)
**Referenced strings:** —
**Referenced opcodes:** 0x1d
**State vars:** —

## Behavioral explanation
SN@P RPC stub: sends app opcode 0x1d with two 32-bit words, returns result (op1c twin).

## Notes / uncertainty
Renamed +roomlist. Byte-identical body to op1c, opcode 0x1d. Room-list request/continue twin; distinct caller (FUN_001ef000). Role split inferred.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001efe70.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
