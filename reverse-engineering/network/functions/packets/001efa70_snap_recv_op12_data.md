# 0x001efa70 snap_recv_op12_data

| field | value |
|---|---|
| Original address | 0x001efa70 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001efa70 |
| Resolved name | snap_recv_op12_data |
| Subsystem | packets |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001ee560
**Callees:** FUN_001069a8, FUN_00106b60, FUN_00107dc8, FUN_001ef3e0, FUN_001ef3f0, FUN_001ef400
**Referenced globals:** 0x37cf1c (id); 0x37cf1e (max len); 0x37bf00 (reply buf); 0x37bf18 (reply len); 0x37bf20 (reply payload); 0x24e3c0 (error msg ptr)
**Referenced strings:** ptr 0x24e3c0 (overflow/error msg)
**Referenced opcodes:** 0x12
**State vars:** —

## Behavioral explanation
SN@P RPC stub: sends app opcode 0x12 and copies the reply payload into the caller buffer, returning received length.

## Notes / uncertainty
Transport op 0x12 receive/fetch-reply: memset RX header, request {id,want}, txn, FlushCache, copy min(want,got) to caller, warn+truncate on overflow (str 0x24e3c0). Clamp want to 0xfd9. Control flow exact.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001efa70.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
