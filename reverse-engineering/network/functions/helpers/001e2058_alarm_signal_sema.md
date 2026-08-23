# 0x001e2058 alarm_signal_sema

| field | value |
|---|---|
| Original address | 0x001e2058 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001e2058 |
| Resolved name | alarm_signal_sema |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** iSignalSema
**Referenced globals:** 0x25b800 alarm sema id
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
SetAlarm callback: signals the wait semaphore whose id is in the context (iSignalSema(*param_3)).

## Notes / uncertainty
SetAlarm ISR callback: iSignalSema(*common) wakes the nanosleep waiter; wiring confirmed by e20a0's SetAlarm(...,0x1e2058,0x25b800).

## Raw decompilation
`sources/executables/transport-decompile/FUN_001e2058.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
