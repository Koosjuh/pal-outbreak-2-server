# 0x001efb80 snap_recv_op13_data

| field | value |
|---|---|
| Original address | 0x001efb80 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001efb80 |
| Resolved name | snap_recv_op13_data |
| Subsystem | packets |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001e366c
**Callees:** FUN_001069a8, FUN_00106b60, FUN_00107dc8, FUN_001ef3e0, FUN_001ef3f0, FUN_001ef400
**Referenced globals:** 0x37cf1c (id); 0x37cf1e (max len); 0x37bf18 (reply len); 0x37bf20 (reply payload); 0x24e3c0 (error msg ptr)
**Referenced strings:** ptr 0x24e3c0 (overflow/error msg)
**Referenced opcodes:** 0x13
**State vars:** —

## Behavioral explanation
SN@P RPC stub: sends app opcode 0x13 and copies reply payload into caller buffer, returning received length (op12 variant).

## Notes / uncertainty
Byte-identical twin of op12 but opcode 0x13 = second receive channel/queue (distinct caller FUN_001e366c). Logical distinction between 0x12/0x13 lives in callers, not the stub.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001efb80.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
