# 0x00637ca0 is_digit_or_dialpad_symbol

| field | value |
|---|---|
| Original address | 0x00637ca0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00637ca0 |
| Resolved name | is_digit_or_dialpad_symbol |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00630910, FUN_006379e0
**Callees:** FUN_00637c40
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Char predicate: returns 1 for '-'(0x2d),'*'(0x2a),'#'(0x23) unless mode-check FUN_00637c40==1 forces 1.

## Notes / uncertainty
Renamed from is_special_punct_char: digit (via 637c40) or - * #. Dialpad page-7 filter.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00637ca0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
