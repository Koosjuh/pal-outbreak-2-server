# 0x001e2c7c socket_accept

| field | value |
|---|---|
| Original address | 0x001e2c7c |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001e2c7c |
| Resolved name | socket_accept |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_00103de8, FUN_001e20a0, FUN_001e2a28, FUN_001e4bec, FUN_001ef710, FUN_001efcf0
**Referenced globals:** PTR_0025b798 table
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** state 0x7f established; 0xff5/0xff6 listen; slot+2 type

## Behavioral explanation
accept() for a listening stream socket (state 0xff5/0xff6): drives the accept handshake loop (FUN_001efcf0 + nanosleep), claims a free table slot for the new peer, sets it established(state 0x7f) and fills the returned sockaddr.

## Notes / uncertainty
accept() on listening slot (0xff5/0xff6): blocking poll loop (FUN_001efcf0 + sleep), claim free slot, state->0x7f, fill sockaddr(len 8). FUN_001ef710 return discarded (always-true test).

## Raw decompilation
`sources/executables/transport-decompile/FUN_001e2c7c.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
