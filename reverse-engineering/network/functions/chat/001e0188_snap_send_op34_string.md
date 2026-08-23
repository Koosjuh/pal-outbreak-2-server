# 0x001e0188 snap_send_op34_string

| field | value |
|---|---|
| Original address | 0x001e0188 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001e0188 |
| Resolved name | snap_send_op34_string |
| Subsystem | chat |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_0010a050, FUN_0010a4f0, FUN_001d4d24, FUN_001d5288, FUN_001e180c, FUN_001ec9e0, FUN_001ed2c0
**Referenced globals:** 0x0025b78c(conn-ptr); 0x0025b790(errno); conn+0x50c; conn+0x520
**Referenced strings:** —
**Referenced opcodes:** 0x34
**State vars:** 0x50c(send-lock); DAT_0025b790(errno)

## Behavioral explanation
Builds/sends reliable (who 0xb000) opcode-0x34: copies a length-prefixed blob (FUN_0010a050 measured, clamped to 0x368); completion cb 0x2a.

## Notes / uncertainty
Reliable op34 C-string sender: strlen+clamp 0x368, flags 0xb000, and (unique in this set) arms completion callback slot 0x2a via snap_set_callback_slot on enqueue success. Callback consumer not traced.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001e0188.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
