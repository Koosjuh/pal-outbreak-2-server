# 0x00633390 predictive_row_limit

| field | value |
|---|---|
| Original address | 0x00633390 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00633390 |
| Resolved name | predictive_row_limit |
| Subsystem | menus |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00631d60, FUN_006333b0, FUN_00633470
**Callees:** —
**Referenced globals:** 0x715da8+0x36 (predictive flag)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x715da8+0x36

## Behavioral explanation
Returns candidate/row count limit for the entry field: 0x1f when predictive flag (state+0x36) set, else 1.

## Notes / uncertainty
Returns 0x1f if predictive flag kbd+0x36 set else 1; stored as candidate count ceiling kbd+0x258.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00633390.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
