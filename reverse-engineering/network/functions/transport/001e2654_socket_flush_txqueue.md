# 0x001e2654 socket_flush_txqueue

| field | value |
|---|---|
| Original address | 0x001e2654 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001e2654 |
| Resolved name | socket_flush_txqueue |
| Subsystem | transport |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001e270c, FUN_001e3f98
**Callees:** FUN_001eb434, FUN_001ec9e0
**Referenced globals:** 0x25b79c device handle
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Drains a socket's send queue (sock+8) to the network device (DAT_0025b79c) via FUN_001ec9e0, treating error -0x1b56 (would-block/empty) as success.

## Notes / uncertainty
Drains socket send list (+8) to device DAT_0025b79c; -0x1b56 empty normalized to success; backpressure/requeue behavior of FUN_001ec9e0 unconfirmed.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001e2654.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
