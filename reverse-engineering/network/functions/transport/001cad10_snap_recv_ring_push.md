# 0x001cad10 snap_recv_ring_push

| field | value |
|---|---|
| Original address | 0x001cad10 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001cad10 |
| Resolved name | snap_recv_ring_push |
| Subsystem | transport |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001069a8
**Referenced globals:** 0x36a900=recv ring; 0x248850=write ptr; 0x3688c8=fill
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x3688d0/d8=busy guards

## Behavioral explanation
Datagram receive callback (registered as handler 0x14): appends a packet's payload (len at +4) into the 0x36a900 ring buffer if space remains, bumping the write ptr and fill counter.

## Notes / uncertainty
Ring producer / datagram type-0x14 handler: appends payload (len at pkt+4,u16) into 0x36a900 if healthy and fits before 0x36b900, bumps wptr+fill; silent drop on overflow (linear, no wrap). memcpy source ptr in descriptor elided by decompiler.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001cad10.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
