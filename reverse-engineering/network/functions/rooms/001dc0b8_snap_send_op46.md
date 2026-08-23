# 0x001dc0b8 snap_send_op46

| field | value |
|---|---|
| Original address | 0x001dc0b8 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001dc0b8 |
| Resolved name | snap_send_op46 |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_0010a4f0, FUN_001d4d24, FUN_001d5288, FUN_001e180c, FUN_001e2304, FUN_001ec9e0, FUN_001ed2c0
**Referenced globals:** 0x0025b78c(conn-ptr); 0x0025b790(errno); conn+0x50c; conn+0x520; conn+0x614(seq)
**Referenced strings:** —
**Referenced opcodes:** 0x46
**State vars:** 0x50c(send-lock); 0x614(seq); DAT_0025b790(errno)

## Behavioral explanation
Builds/sends reliable opcode-0x46 (len 0x28): two 16-byte name fields, a short (param_4) and a u32 (param_5, htonl); completion cb 0x2f, seq conn+0x614.

## Notes / uncertainty
Reliable (0xb000) 0x28-byte builder: two 16-byte names + htonl(u16) + htonl(u32); cb tag 0x2f, seq conn+0x614. Two-name layout implies a directed/addressed request but app role is unproven (no caller/trace).

## Raw decompilation
`sources/executables/transport-decompile/FUN_001dc0b8.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
