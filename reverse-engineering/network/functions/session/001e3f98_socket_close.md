# 0x001e3f98 socket_close

| field | value |
|---|---|
| Original address | 0x001e3f98 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001e3f98 |
| Resolved name | socket_close |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d4de0
**Callees:** FUN_00103de8, FUN_001e2654, FUN_001e2a28, FUN_001e3a3c, FUN_001ef770, FUN_001f0230
**Referenced globals:** PTR_0025b798 table
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** state 0xff3 closing / 0xffff free; slot+2 type

## Behavioral explanation
close(): for stream sockets initiates teardown (FUN_001ef770, state->0xff3); for dgram flushes the RX pump thrice, tears down the endpoint (FUN_001f0230) and frees the slot (0xffff).

## Notes / uncertainty
close(): stream FIN (FUN_001ef770)->0xff3 closing; dgram drains RX x3, destroys endpoint, frees slot (type/state 0xffff); both reinit (FUN_001e2654). errno 0x6c bad fd.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001e3f98.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
