# 0x001c94c0 snap_send_op0d_data_chunk

| field | value |
|---|---|
| Original address | 0x001c94c0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c94c0 |
| Resolved name | snap_send_op0d_data_chunk |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001c9b00
**Callees:** FUN_0010a050, FUN_001c3840, FUN_001c3c90, FUN_001c3e10, FUN_001c3ea0, FUN_001c4020, FUN_001ee590
**Referenced globals:** 0x365dd1=transfer id
**Referenced strings:** —
**Referenced opcodes:** 0x0d
**State vars:** piVar3[0x1c]=total len; piVar3[0x12]=offset; piVar3+0xd=substate

## Behavioral explanation
Builds and sends an op-0x0d data-upload chunk (10-byte id + offset + length, capped to fit 0x300) advancing the sent offset (+0x12) and substate to 0x18.

## Notes / uncertainty
op0d upload chunk: chunk=0x300-(strlen(id)+0xc) clamped to remaining; body id+offset(u32)+len(u16); advances offset, substate 0x18. Uncertainty: exact 0xc overhead split; server-echo of offset.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c94c0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
