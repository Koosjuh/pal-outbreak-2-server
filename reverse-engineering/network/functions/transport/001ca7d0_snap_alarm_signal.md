# 0x001ca7d0 snap_alarm_signal

| field | value |
|---|---|
| Original address | 0x001ca7d0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ca7d0 |
| Resolved name | snap_alarm_signal |
| Subsystem | transport |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** iSignalSema, SYNC, EI
**Referenced globals:** 0x248868=wake sema
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Alarm/interrupt callback that signals the worker wake semaphore (iSignalSema) and issues SYNC/EI.

## Notes / uncertainty
Alarm ISR paced by SetAlarm(0x100) from worker loop: iSignalSema(wake 0x248868) if live, then SYNC(0)/EI(). Decompiler drops the explicit sema arg (inferred from the guard). Alarm period unit assumed hsync.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ca7d0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
