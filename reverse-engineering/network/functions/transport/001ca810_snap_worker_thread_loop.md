# 0x001ca810 snap_worker_thread_loop

| field | value |
|---|---|
| Original address | 0x001ca810 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ca810 |
| Resolved name | snap_worker_thread_loop |
| Subsystem | transport |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001ca8c0
**Callees:** FUN_001cae70
**Referenced globals:** 0x3688e0=stop flag; 0x248868=wake sema; 0x248848=mutex; 0x248860=done sema
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
The transport worker thread body: repeatedly runs the datagram dispatch tick (FUN_001cae70), arms a 0x100-tick alarm and waits on the wake sema; cleans up sema/thread on exit.

## Notes / uncertainty
Worker body: while(!stop && wake!=-1){ tick FUN_001cae70; SetAlarm(0x100,snap_alarm_signal); WaitSema(wake); } then deletes wake+mutex sema, SignalSema(done), ExitDeleteThread. FUN_001cae70 tick internals documented separately.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ca810.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
