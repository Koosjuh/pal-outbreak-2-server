# 0x001caf60 snap_recv_queue_drain

| field | value |
|---|---|
| Original address | 0x001caf60 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001caf60 |
| Resolved name | snap_recv_queue_drain |
| Subsystem | transport |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001069a8, FUN_001bf140, FUN_001bf170, FUN_001bf230, FUN_001caed0
**Referenced globals:** 0x35a690=recv queue
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Fills the 0x35a690 queue from the recv chunk source (FUN_001caed0) then dequeues all buffered segments into the caller buffer, returning total bytes copied.

## Notes / uncertainty
Refill then fully drain 0x35a690 queue to caller buf, return summed len. dst cursor not advanced in visible decompile — likely artifact (return is summed length).

## Raw decompilation
`sources/executables/transport-decompile/FUN_001caf60.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
