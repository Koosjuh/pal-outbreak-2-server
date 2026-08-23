# 0x00628750 member_task_reset

| field | value |
|---|---|
| Original address | 0x00628750 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00628750 |
| Resolved name | member_task_reset |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00627d60
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Trivial sub-step: resets the msg task record to state 0 and returns -1.

## Notes / uncertainty
Trivial leaf: zeroes task record state(+0)/substate(+1) and returns -1 (dispatcher done-sentinel). Called from member-task dispatcher FUN_00627d60; layout confirmed by sibling FUN_00627ea0 bumping same bytes.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00628750.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
