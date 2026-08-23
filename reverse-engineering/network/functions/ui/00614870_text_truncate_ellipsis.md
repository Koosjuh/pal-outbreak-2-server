# 0x00614870 text_truncate_ellipsis

| field | value |
|---|---|
| Original address | 0x00614870 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00614870 |
| Resolved name | text_truncate_ellipsis |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_006130a0, FUN_00613600, FUN_006139c0, FUN_00613aa0, FUN_006140d0
**Callees:** —
**Referenced globals:** —
**Referenced strings:** "..." (0x2e2e2e)
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Copies a multibyte string into dst, truncating with '...' when it would exceed the given pixel/byte budget.

## Notes / uncertainty
Ellipsis bytes, budget-3 reserve, two-part truncate gate exact; exact units of budget/str-width helper (bytes vs px) unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00614870.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
