# 0x005b1a30 dialog_task_dispatch

| field | value |
|---|---|
| Original address | 0x005b1a30 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b1a30 |
| Resolved name | dialog_task_dispatch |
| Subsystem | menus |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005b1a00
**Callees:** FUN_005b1fa0, FUN_005b20c0, FUN_005b2260, FUN_005f6970, FUN_00603d30, FUN_00603d50, FUN_00603d70, FUN_00617a00, FUN_00618b60, FUN_00627760
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** struct+0x42c busy flag; struct+0x42d task type; struct+0x42f index

## Behavioral explanation
Modal-dialog/task dispatcher: clears busy flag +0x42c then switches on task-type +0x42d, running per-type handlers (msgbox/name-list/etc.).

## Notes / uncertainty
Already fully reconstructed. Task-type meanings inferred; types 5 and 10 share handler FUN_005b1fa0; case 2 early-returns.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b1a30.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
