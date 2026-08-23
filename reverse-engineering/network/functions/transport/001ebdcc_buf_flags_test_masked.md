# 0x001ebdcc buf_flags_test_masked

| field | value |
|---|---|
| Original address | 0x001ebdcc |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ebdcc |
| Resolved name | buf_flags_test_masked |
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
**State vars:** +0xe buffer flags

## Behavioral explanation
Tests buffer flags against a packed arg: high16 = mask, low16 = expected value, returning true when (flags & mask)==value.

## Notes / uncertainty
Packed arg high16=mask low16=value; (flags&mask)==value; bit semantics undecoded.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ebdcc.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
