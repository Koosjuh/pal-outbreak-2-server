# 0x001eff60 snap_send_op19_data_padded

| field | value |
|---|---|
| Original address | 0x001eff60 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001eff60 |
| Resolved name | snap_send_op19_data_padded |
| Subsystem | packets |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001e34dc
**Callees:** FUN_001069a8, FUN_00107dc8, FUN_001ef3e0, FUN_001ef3f0, FUN_001ef400
**Referenced globals:** 0x37cf1c (id); 0x37cf1e (pad count); 0x37cf20 (4B field); 0x37cf24 (2B field); 0x37cf26 (len); 0x37cf28 (payload); 0x37bf18 (result); 0x24e3f0 (error msg ptr)
**Referenced strings:** ptr 0x24e3f0 (error msg)
**Referenced opcodes:** 0x19
**State vars:** —

## Behavioral explanation
SN@P RPC stub: sends app opcode 0x19 with id, extra 4B+2B header fields and a length-prefixed, 4-byte-aligned payload; returns result (negative -> error).

## Notes / uncertainty
Transport op 0x19 structured send: header adds field1(u32@+0x20), field2(u16@+0x24), pad=(4-(len&3))&3, payload@+0x28, txlen=len+0x30, fixed rxlen 0x20 (small ack); negative reply -> warn(0x24e3f0)+return 0. Meaning of field1/field2 and the 4-byte alignment reason unknown -> Medium.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001eff60.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
