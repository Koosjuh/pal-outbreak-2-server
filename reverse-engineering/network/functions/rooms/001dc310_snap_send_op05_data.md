# 0x001dc310 snap_send_op05_data

| field | value |
|---|---|
| Original address | 0x001dc310 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001dc310 |
| Resolved name | snap_send_op05_data |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001d4d24, FUN_001d5288, FUN_001e180c, FUN_001ec9e0, FUN_001ed2c0
**Referenced globals:** 0x0025b78c(conn-ptr); 0x0025b790(errno); conn+0x50c; conn+0x520; conn+0x615(seq)
**Referenced strings:** —
**Referenced opcodes:** 0x04
**State vars:** 0x50c(send-lock); 0x615(seq); DAT_0025b790(errno)

## Behavioral explanation
Builds/sends reliable (who 0xb000) opcode-4 with a single htonl u32 payload (create-slot / room id); completion cb 0x1e, seq conn+0x615.

## Notes / uncertainty
CORRECTION: finalizer call passes opcode=5 (bodyLen=4), so this emits op05, NOT op04 as its old name/PACKET_INDEX bucket claimed. It is the 0xb000 (DATA) twin of dc804 (0xa000). Genuine create builder is dc508. Renamed snap_send_op05_data; verify op05 role on a live create capture.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001dc310.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
