# 0x001dff7c snap_send_op25_name2int

| field | value |
|---|---|
| Original address | 0x001dff7c |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001dff7c |
| Resolved name | snap_send_op25_name2int |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_0010a4f0, FUN_001d4d24, FUN_001d5288, FUN_001e180c, FUN_001ed2c0
**Referenced globals:** 0x0025b78c(conn-ptr); 0x0025b790(errno); conn+0x50c
**Referenced strings:** —
**Referenced opcodes:** 0x25
**State vars:** 0x50c(send-lock); DAT_0025b790(errno)

## Behavioral explanation
Builds/sends reliable (who 0xb000) opcode-0x25 (len 0x18): 16-byte field (param_2) + two htonl u32; completion cb 0x29, seq arg 0.

## Notes / uncertainty
Renamed from snap_send_op25. Reliable (who 0xb000) 0x18 body = char name[16]+2 htonl u32; completion tag 0x29. Reserve not null-checked. Exact op25 role and the two u32 params not runtime-confirmed.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001dff7c.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
