# 0x001ca660 util_ascii_to_int

| field | value |
|---|---|
| Original address | 0x001ca660 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ca660 |
| Resolved name | util_ascii_to_int |
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
Generic ASCII→integer parser over param_2 characters (digits only).

## Notes / uncertainty
Fixed-width base-10 parser; non-digits skipped (not terminators); no sign/overflow guard. Exact.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ca660.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
