# 0x001e3880 socket_recvfrom

| field | value |
|---|---|
| Original address | 0x001e3880 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001e3880 |
| Resolved name | socket_recvfrom |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d72a8
**Callees:** FUN_00103de8, FUN_001069a8, FUN_001e2a28, FUN_001eb434, FUN_001ec9e0, FUN_001ed3f4, FUN_001ed4fc, FUN_001ed7e0
**Referenced globals:** PTR_0025b798 table; 0x25b79c device
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** slot+2 type2; state -1 closed

## Behavioral explanation
recvfrom() for a dgram socket(type2): dequeues an inbound packet (eb434), copies payload (ed7e0) and fills the source sockaddr (ed3f4/ed4fc) into param_5.

## Notes / uncertainty
recvfrom() for dgram socket: dequeue inbound from slot+8, copy payload (ed7e0 -> byte count), fill 0x10 source sockaddr from ip(ed3f4)/port(ed4fc) into param_5, free to DAT_0025b79c. -0x1b56->0, errno 0x6c/0xe/0x6b. Used by transport-tick recv path; ip/port accessor offsets inferred.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001e3880.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
