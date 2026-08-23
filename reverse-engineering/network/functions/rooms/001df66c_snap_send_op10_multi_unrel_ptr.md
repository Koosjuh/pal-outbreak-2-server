# 0x001df66c snap_send_op10_multi_unrel_ptr

| field | value |
|---|---|
| Original address | 0x001df66c |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001df66c |
| Resolved name | snap_send_op10_multi_unrel_ptr |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001069a8, FUN_001d5288, FUN_001e180c, FUN_001ec9e0, FUN_001ed2c0
**Referenced globals:** 0x0025b78c(conn-ptr); 0x0025b790(errno); conn+0x50c; conn+0x520
**Referenced strings:** —
**Referenced opcodes:** 0x10
**State vars:** 0x50c(send-lock); DAT_0025b790(errno)

## Behavioral explanation
Builds/sends opcode-0x10 with who param_2|0x2000 (unreliable): recipient ids from array descriptor param_5 (count+ptr) + param_4 blob; no completion cb.

## Notes / uncertainty
Unreliable pointer-array op10 multicast; reserve null-checked+freed here (unlike df380). No caller.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001df66c.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
