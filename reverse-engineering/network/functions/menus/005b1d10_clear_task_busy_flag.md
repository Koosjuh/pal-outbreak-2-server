# 0x005b1d10 clear_task_busy_flag

| field | value |
|---|---|
| Original address | 0x005b1d10 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b1d10 |
| Resolved name | clear_task_busy_flag |
| Subsystem | menus |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005acab0, FUN_005ae3e0, FUN_005ae770, FUN_005b1fa0, FUN_005b20c0, FUN_005b2260, FUN_005f6970, FUN_005fb670, FUN_005ff830, FUN_00616bd0
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** struct+0x42c busy flag

## Behavioral explanation
One-liner: clears the modal-task busy flag at struct+0x42c.

## Notes / uncertainty
One-liner: ctx+0x42c = 0 (release modal). Called from terminal phase of every msgbox task. Boolean vs small enum unconfirmed (all writes 0).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b1d10.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
