# 0x00637c40 is_ascii_digit

| field | value |
|---|---|
| Original address | 0x00637c40 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00637c40 |
| Resolved name | is_ascii_digit |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00630910, FUN_006379e0, FUN_00637ca0
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Returns 1 if param is an ASCII digit '0'-'9' (0x30-0x39), else 0.

## Notes / uncertainty
Exact isdigit 0x30-0x39. No uncertainty.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00637c40.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
