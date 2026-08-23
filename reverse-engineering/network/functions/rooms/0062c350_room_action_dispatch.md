# 0x0062c350 room_action_dispatch

| field | value |
|---|---|
| Original address | 0x0062c350 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062c350 |
| Resolved name | room_action_dispatch |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0062ba70
**Callees:** FUN_0062c3f0, FUN_0062c580, FUN_0062c750, FUN_0062c7b0, FUN_0062c870, FUN_0062c970
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Sub-dispatcher on the task's +1 state (0..5): detail-load, name-entry, validate, result-branch, dialog-anim, launch.

## Notes / uncertainty
6-way switch on task+1 (0..5) trampoline for the member-action step machine. Per-step role labels inferred from callee shapes; only step2 (FUN_0062c750) confirmed in this batch. param_1 pass-through certain by ABI.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062c350.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
