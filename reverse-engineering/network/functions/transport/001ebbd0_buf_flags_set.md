# 0x001ebbd0 buf_flags_set

| field | value |
|---|---|
| Original address | 0x001ebbd0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ebbd0 |
| Resolved name | buf_flags_set |
| Subsystem | transport |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d5460, FUN_001d5ae4, FUN_001d6468, FUN_001d72a8, FUN_001e16b4, FUN_001e180c, FUN_001e1ac8, FUN_001ed924
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0xe buffer flags

## Behavioral explanation
OR-sets bits in a buffer's flags word (+0xe).

## Notes / uncertainty
OR-set bits into +0x0e flags; 8 callers across send/reorder/ack/retransmit stages each stamp state bits. Per-stage bit meanings need caller traces.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ebbd0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
