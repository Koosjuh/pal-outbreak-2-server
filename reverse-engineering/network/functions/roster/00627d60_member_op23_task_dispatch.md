# 0x00627d60 member_op23_task_dispatch

| field | value |
|---|---|
| Original address | 0x00627d60 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00627d60 |
| Resolved name | member_op23_task_dispatch |
| Subsystem | roster |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f76f0, FUN_005f8d40
**Callees:** FUN_00627ea0, FUN_00627f20, FUN_00628110, FUN_00628210, FUN_00628690, FUN_00628710, FUN_00628750
**Referenced globals:** 0x695ce0 op23-substate-block
**Referenced strings:** —
**Referenced opcodes:** 0x23
**State vars:** uRam00695ce0 substate

## Behavioral explanation
Per-frame task dispatcher for the op-0x23 member-list machine: runs sub-state uRam00695ce0 (cases 0-6) across the send/wait/process/refresh/leave sub-steps and resets the task record on completion.

## Notes / uncertainty
Per-frame driver of the op-0x23 roster SM; init-guard ctx+0xe, memset(0x695ce0,0x18), switch(0x695ce0[0]) 7 handlers, reset task on handler==1. Substate block 0x695ce0 passed to all cases (register artifact confirmed by case 6). status var undefined for out-of-range selector.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00627d60.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
