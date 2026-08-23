# 0x001e05c8 snap_send_op3e

| field | value |
|---|---|
| Original address | 0x001e05c8 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001e05c8 |
| Resolved name | snap_send_op3e |
| Subsystem | chat |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001069a8, FUN_001d5288, FUN_001e180c, FUN_001ec9e0, FUN_001ed2c0
**Referenced globals:** 0x0025b78c(conn-ptr); 0x0025b790(errno); conn+0x50c; conn+0x520
**Referenced strings:** —
**Referenced opcodes:** 0x3e
**State vars:** 0x50c(send-lock); DAT_0025b790(errno)

## Behavioral explanation
Builds/sends reliable (who 0xb000) opcode-0x3e: copies a param_3-length blob clamped to 0x36c; no completion cb.

## Notes / uncertainty
Reliable op3e large-blob sender, clamp 0x36c, flags 0xb000. Control flow High; no caller, domain (bulk data vs chat) inferred. Off-by-one clamp (>0x36b→0x36c) preserved as decompiled.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001e05c8.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
