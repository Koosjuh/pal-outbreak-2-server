# 0x001ca610 util_int_to_ascii_fixed

| field | value |
|---|---|
| Original address | 0x001ca610 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ca610 |
| Resolved name | util_int_to_ascii_fixed |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001ca6b0
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Generic integer→ASCII decimal converter writing param_3 digits right-to-left into a buffer.

## Notes / uncertainty
Fixed-width zero-padded right-aligned unsigned-decimal formatter; no NUL; truncates high digits. Exact. Signedness of value input unproven.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ca610.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
