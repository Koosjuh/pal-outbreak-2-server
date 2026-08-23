# 0x001ebd2c buf_get_prev

| field | value |
|---|---|
| Original address | 0x001ebd2c |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ebd2c |
| Resolved name | buf_get_prev |
| Subsystem | transport |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Returns the pointer/word at buffer +4 (list prev link).

## Notes / uncertainty
Renamed from buf_get_field4: +0x4 prev link of intrusive dlist node; next/prev orientation by convention.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ebd2c.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
