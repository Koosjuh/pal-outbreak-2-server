# 0x001ca590 snap_close_get_hostid

| field | value |
|---|---|
| Original address | 0x001ca590 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ca590 |
| Resolved name | snap_close_get_hostid |
| Subsystem | transport |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001ee650, FUN_001ee680
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** param_1+0x1c=socket; param_1+0x30=conn ctx; param_1+0xd8=phase

## Behavioral explanation
Tears down the socket and returns the 3-byte host/server id (bytes at conn+2..4) while advancing the phase field to 4.

## Notes / uncertainty
Establish close-out: extracts 3-byte host id (pkt[2]<<16|pkt[3]<<8|pkt[4]) from conn+0x30 handshake packet, closes socket if open, phase(+0xd8)=4, returns id. Byte order/id meaning inferred from position, not pcap-confirmed.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ca590.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
