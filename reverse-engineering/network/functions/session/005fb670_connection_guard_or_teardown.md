# 0x005fb670 connection_guard_or_teardown

| field | value |
|---|---|
| Original address | 0x005fb670 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005fb670 |
| Resolved name | connection_guard_or_teardown |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005fa490, FUN_005faa60, FUN_005fada0, FUN_005fb010, FUN_005fb060, FUN_005fb270, FUN_0062dc40
**Callees:** FUN_005adc80, FUN_005b1d10, FUN_005b9110, FUN_00637180
**Referenced globals:** 0x6c076e slot conn-state; 0x6c4fce/0x6c4fd3 teardown flags; 0x6c4b90 mode
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x6c076e conn state (3/4=up)

## Behavioral explanation
Connection guard: returns 0 if active-slot state (@0x6c076e) is 3/4 (connected); otherwise tears the session down and returns 1.

## Notes / uncertainty
Shared 'still connected?' gate: reads active slot state at (slot-1)*0x15c+0x6c076e; 3/4=up→return 0, else teardown+msg 0x4c→return 1. The 3/4=up mapping is from the tag corpus, not a live read.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005fb670.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
