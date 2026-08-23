# 0x001efe00 snap_req_op1c_roomlist

| field | value |
|---|---|
| Original address | 0x001efe00 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001efe00 |
| Resolved name | snap_req_op1c_roomlist |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001eefb0
**Callees:** FUN_001ef3e0, FUN_001ef3f0, FUN_001ef400
**Referenced globals:** 0x37cf1c (param1, 4B); 0x37cf20 (param2, 4B); 0x37bf18 (result)
**Referenced strings:** —
**Referenced opcodes:** 0x1c
**State vars:** —

## Behavioral explanation
SN@P RPC stub: sends app opcode 0x1c with two 32-bit words, returns result.

## Notes / uncertainty
Renamed +roomlist. Two u32 words in, result-only. 0x1c = transport room-list band (0x1c/0x1e/0x20); words likely (cursor,count). op1d twin.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001efe00.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
