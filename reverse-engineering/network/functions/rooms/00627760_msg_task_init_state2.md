# 0x00627760 msg_task_init_state2

| field | value |
|---|---|
| Original address | 0x00627760 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00627760 |
| Resolved name | msg_task_init_state2 |
| Subsystem | rooms |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005b1a30, FUN_005f7f30
**Callees:** FUN_0062b9e0
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Initializes a message/task descriptor: sets +1 opcode/state byte to 2 and clears the +0xe..+0x11 substate fields.

## Notes / uncertainty
Task-descriptor init: resets render block (FUN_0062b9e0), sets selector +0x1=2, clears +0xe..+0x11. Selector is a local task-machine id, NOT a wire opcode (siblings stamp 5 and 9). Which handler '2' maps to not decoded.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00627760.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
