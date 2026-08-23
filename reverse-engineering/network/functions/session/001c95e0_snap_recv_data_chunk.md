# 0x001c95e0 snap_recv_data_chunk

| field | value |
|---|---|
| Original address | 0x001c95e0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c95e0 |
| Resolved name | snap_recv_data_chunk |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_00106b60, FUN_0010a338, FUN_001c3b10, FUN_001c3b90
**Referenced globals:** 0x365dd1=expected id; 0x365df0=download buffer
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** piVar3[0x1c]=total len; piVar3[3]=topstate; piVar3+0xd=substate

## Behavioral explanation
Receives a data-download chunk: reads a 10-byte id, memcmp's it against 0x365dd1, then reads up to 0x8000 into iRam00365df0; loops (substate 0x17) until total (+0x1c) reached, then 0x31.

## Notes / uncertainty
Download counterpart: cur_msg[6]==0xff EOF->result 9; id memcmp vs 0x365dd1 (miss=-63); copies body into 0x365df0[offset] bounded 0x8000; complete->0x31 else 0x17. Uncertainty: cur_msg[6] flag role.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c95e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
