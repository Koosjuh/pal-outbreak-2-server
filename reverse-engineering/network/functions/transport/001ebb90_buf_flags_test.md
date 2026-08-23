# 0x001ebb90 buf_flags_test

| field | value |
|---|---|
| Original address | 0x001ebb90 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ebb90 |
| Resolved name | buf_flags_test |
| Subsystem | transport |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d5688, FUN_001d5ae4, FUN_001d6468, FUN_001d72a8, FUN_001e16b4
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0xe buffer flags

## Behavioral explanation
Tests whether all mask bits are set in a buffer's flags word (+0xe).

## Notes / uncertainty
ALL-bits-set test ((flags&mask)==mask) on +0x0e; gates reliable send/reorder/ack/retransmit paths. Exact bit map of +0x0e not pinned.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ebb90.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
