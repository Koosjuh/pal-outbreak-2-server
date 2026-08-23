# 0x001e34dc socket_sendto

| field | value |
|---|---|
| Original address | 0x001e34dc |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001e34dc |
| Resolved name | socket_sendto |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d6468
**Callees:** FUN_00103de8, FUN_001e2a28, FUN_001eff60
**Referenced globals:** PTR_0025b798 table
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** state 0x7f; slot+2 type2

## Behavioral explanation
sendto() for an established dgram socket (state 0x7f,type2): sends payload to the sockaddr(len 0x10) via FUN_001eff60.

## Notes / uncertainty
sendto() for connected dgram socket (slot state 0x7f, type 2, addrlen 0x10); UDP transmit via FUN_001eff60(fd,len,ip@+4,port@+2,buf); returns len or -1 with errno 0x6c/0xe/0x6b/0x7d. errno numbering inferred from PS2 SDK.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001e34dc.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
