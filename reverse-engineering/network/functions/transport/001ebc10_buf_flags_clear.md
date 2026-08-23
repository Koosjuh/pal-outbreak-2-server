# 0x001ebc10 buf_flags_clear

| field | value |
|---|---|
| Original address | 0x001ebc10 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ebc10 |
| Resolved name | buf_flags_clear |
| Subsystem | transport |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d5460, FUN_001d5ae4, FUN_001ed034, FUN_001ed924
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0xe buffer flags

## Behavioral explanation
AND-clears bits in a buffer's flags word (+0xe).

## Notes / uncertainty
AND-NOT clears bits in buffer flags word +0xe; individual bit meanings undecoded.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ebc10.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
