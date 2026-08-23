# 0x001e3a3c socket_rx_demux_pump

| field | value |
|---|---|
| Original address | 0x001e3a3c |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001e3a3c |
| Resolved name | socket_rx_demux_pump |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001e3ba8, FUN_001e3f98
**Callees:** FUN_00114ac8, FUN_001e2a90, FUN_001eb3b8, FUN_001ec1f8, FUN_001ec9e0, FUN_001ed41c, FUN_001ed524, FUN_001ed74c, FUN_001f0070
**Referenced globals:** 0x25b79c device; 0x259640/0x259660 log
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Receive worker: pulls raw datagrams off the device (FUN_001f0070), matches the destination socket by id (e2a90), allocates a pool buffer, copies payload+addr+flags and appends it to that socket's RX queue (sock+8).

## Notes / uncertainty
Inbound datagram demux: recvfrom via FUN_001f0070, endpoint lookup e2a90, subpool_alloc(best-fit,latch-bypass), enqueue to sock+8. Single early-return on alloc/enqueue fail can throttle RX under a full pool. sockaddr/flags layout unvalidated.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001e3a3c.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
