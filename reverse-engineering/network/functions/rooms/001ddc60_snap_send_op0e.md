# 0x001ddc60 snap_send_op0e

| field | value |
|---|---|
| Original address | 0x001ddc60 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ddc60 |
| Resolved name | snap_send_op0e |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001d4d24, FUN_001d5288, FUN_001e180c
**Referenced globals:** 0x0025b78c(conn-ptr); 0x0025b790(errno); conn+0x50c
**Referenced strings:** —
**Referenced opcodes:** 0x0e
**State vars:** 0x50c(send-lock); DAT_0025b790(errno)

## Behavioral explanation
Builds/sends a zero-length reliable (who 0xb000) opcode-0xe; completion cb 0x1a, seq arg 0.

## Notes / uncertainty
op0e zero-length, who 0xb000; cb 0x1a, literal seq 0, returns 0. No subpool_free on failure (no reserve step). App role inferred.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ddc60.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
