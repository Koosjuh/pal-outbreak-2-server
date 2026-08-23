# 0x005c1c80 pump_room_enter_sequence

| field | value |
|---|---|
| Original address | 0x005c1c80 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c1c80 |
| Resolved name | pump_room_enter_sequence |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005bf130, FUN_005bf180, FUN_005bf1e0, FUN_005bfe00, FUN_005c0750
**Referenced globals:** 0x6cbb6c/0x6cbb68 SM guard/step; 0x6cbb4c completion ctx; 0x6cbb6d step-signal; 0x6ce5c4 abort flag; 0x70047c slot-mode flag
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x6cbb68 step; 0x6cbb6d signal; 0x70047c

## Behavioral explanation
Enter-room state machine (guard 0x6cbb6c, step 0x6cbb68 cases 0-5): probes room slots via FUN_005bf1e0, drives sub-steps FUN_005c0750 (STAT commit) and FUN_005bfe00, releases slots (bf180/bf130) on completion, and fires the completion callback 0x6cbb4c with ok/err.

## Notes / uncertainty
6-step enter-room driver: step0 STAT-commit (0750) unless no room, step2 second enter sub-send (FUN_005bfe00), step4 success commits/clears slot regs per 0x70047c then cb(ok), step5 cb(err). Wire content of the bfe00 sub-request not decoded here.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c1c80.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
