# 0x00627d40 msg_task_init_state9

| field | value |
|---|---|
| Original address | 0x00627d40 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00627d40 |
| Resolved name | msg_task_init_state9 |
| Subsystem | rooms |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f7f30
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** 0x09
**State vars:** —

## Behavioral explanation
Initializes a message/task descriptor: sets +1 opcode/state byte to 9 (register) and clears +0xe..+0x11 substate.

## Notes / uncertainty
Sibling of 0x27760: stamps selector +0x1=9, clears +0xe..+0x11, no render reset. Local task-machine id (not wire op 0x09). Handler for '9' not decoded.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00627d40.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
