# 0x005b1fa0 msgbox_task_notice

| field | value |
|---|---|
| Original address | 0x005b1fa0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b1fa0 |
| Resolved name | msgbox_task_notice |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005b1a30
**Callees:** FUN_005b14b0, FUN_005b1d10, FUN_005b8cf0, FUN_005b9110
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** struct+0x430 phase; struct+0x431 timer; struct+0x42d task type

## Behavioral explanation
Modal notice-box task (1a30 case 5/10): 4-phase build/hold/teardown at +0x430 with countdown +0x431, builds the box via 0x5b8cf0/9110 and clears busy on exit.

## Notes / uncertainty
Modal notice/OK box: 4-phase machine on ctx+0x430 (init/intro/wait-dismiss/teardown), dismiss mask 0x8200, msg string ids 0x1f (taskType+0x42d==5) / 0x8a. String-id->text and taskType==5 meaning unresolved.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b1fa0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
