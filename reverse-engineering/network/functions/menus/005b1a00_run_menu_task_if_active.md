# 0x005b1a00 run_menu_task_if_active

| field | value |
|---|---|
| Original address | 0x005b1a00 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b1a00 |
| Resolved name | run_menu_task_if_active |
| Subsystem | menus |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005acab0
**Callees:** FUN_005b1a30
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** struct+0x438 task-active flag

## Behavioral explanation
Thin guard: if the task-active flag at +0x438 is set, run the dialog/task dispatcher 0x5b1a30.

## Notes / uncertainty
Per-frame guard: if ctx+0x438 (task-active) set, call dispatcher 0x5b1a30. +0x438 vs +0x42c(busy) relationship inferred; dispatcher not reconstructed here.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b1a00.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
