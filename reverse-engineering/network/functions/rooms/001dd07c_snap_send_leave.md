# 0x001dd07c snap_send_leave

| field | value |
|---|---|
| Original address | 0x001dd07c |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001dd07c |
| Resolved name | snap_send_leave |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001d4d24, FUN_001d5288, FUN_001e180c
**Referenced globals:** 0x0025b78c(conn-ptr); 0x0025b790(errno); conn+0x50c; conn+0x61a(seq)
**Referenced strings:** —
**Referenced opcodes:** 0x07
**State vars:** 0x50c(send-lock); 0x61a(seq); DAT_0025b790(errno)

## Behavioral explanation
Builds/sends a zero-length reliable (who 0xb000) opcode-7 (leave room); completion cb 0x23, seq conn+0x61a.

## Notes / uncertainty
op07 leave, zero-length, who 0xb000; cb 0x23, seq 0x61a. Wire shape certain; server-side slot-free semantics live in receive handlers.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001dd07c.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
