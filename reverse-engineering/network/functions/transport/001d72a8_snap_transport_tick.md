# 0x001d72a8 snap_transport_tick

| field | value |
|---|---|
| Original address | 0x001d72a8 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d72a8 |
| Resolved name | snap_transport_tick |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001cae70
**Callees:** FUN_001069a8, FUN_001d53cc, FUN_001d5460, FUN_001d6468, FUN_001d6988, FUN_001d6dfc, FUN_001d7104, FUN_001e1c10, FUN_001e3880, FUN_001e3ba8, FUN_001e40b0, FUN_001eb2d4, FUN_001ebb90, FUN_001ebbd0, FUN_001ebcd0, FUN_001ebd54, FUN_001ec1f8, FUN_001ec9e0, FUN_001ed6ec, FUN_001edd9c
**Referenced globals:** 0x0025b78c conn-ptr; 0x0025b790 last-error (0x27 result / +7000/+8000 offsets)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** conn+0x143 err; conn+0x149..0x151 tick counters; conn+0x13f now-ms

## Behavioral explanation
Main per-poll transport dispatcher: stamps the clock, pumps the handshake (001d7104), receives datagrams, validates source and the 0xba476600 magic, runs the accept-gate (001d6988), flushes sends (001d6468), delivers messages (001d6dfc), and scans retransmits (001d5460).

## Notes / uncertainty
Main pump (param_1==1): now clock, keepalive FUN_001d7104, select read=recvfd(conn+4)/write=sendfd(conn+0), window cap 9, recvfrom+validate (src id/port match conn+0x4c/0x4a, len>=0x14, trailer 0xba476600, decrypt edd9c), accept-gate d6988, delivery e1c10->d6dfc, retransmit d5460. Errors bias +7000/+8000 in DAT_0025b790, return 0x27. ioctl 0x71045ead=bytes-avail inferred; trailer offset arithmetic best-fit.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d72a8.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
