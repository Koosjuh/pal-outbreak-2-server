# 0x006333b0 enter_predictive_mode

| field | value |
|---|---|
| Original address | 0x006333b0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006333b0 |
| Resolved name | enter_predictive_mode |
| Subsystem | menus |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00631d60, FUN_00633470
**Callees:** FUN_00633390
**Referenced globals:** 0x715da8+0x36; 0x715da8+0x2f (mode); 0x715da8+0x26
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x715da8+0x2f; 0x715da8+0x36

## Behavioral explanation
If predictive flag set, clears candidate buffers (+0x260/+0x47c/+0x48c/+0x46c), sets row-count, and switches input mode to 1 (predictive).

## Notes / uncertainty
Gated on kbd+0x36; clears preview/candidate fields, sets count ceiling, mode kbd+0x2f=1, flag kbd+0x26=1. Field roles named from cross-fn usage.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006333b0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
