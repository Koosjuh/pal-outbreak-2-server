# 0x0062fc40 ui_task_alpha_animate

| field | value |
|---|---|
| Original address | 0x0062fc40 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062fc40 |
| Resolved name | ui_task_alpha_animate |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0062f990, FUN_0062fa80
**Callees:** —
**Referenced globals:** 0x694630 sin-scale const
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
UI helper: advances widget phase +0x3a by 0x400 and computes sin-based alpha into color byte of +0x2c (same math as f710).

## Notes / uncertainty
Per-frame sin alpha animator into +0x2c; byte-identical math to f710 tail. Companion step to fc20.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062fc40.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
