# 0x001e366c socket_send_or_recv

| field | value |
|---|---|
| Original address | 0x001e366c |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001e366c |
| Resolved name | socket_send_or_recv |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_00103de8, FUN_001e2a28, FUN_001e4bec, FUN_001eb434, FUN_001ec9e0, FUN_001ed7e0, FUN_001efb80
**Referenced globals:** PTR_0025b798 table; 0x25b79c device
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** state 0x7f/0xff4; slot+2 type

## Behavioral explanation
send()/recv-ish: for stream(type1, state 0x7f/0xff4) transmits via FUN_001efb80 after pumping e4bec; for dgram(type2) dequeues a buffered packet (eb434) and reads it out via FUN_001ed7e0.

## Notes / uncertainty
Renamed from socket_send: dual-mode by slot type - stream(1) pumps e4bec + transmits efb80 when connected(0x7f/0xff4); dgram(2) dequeues one buffered packet (eb434) and reads it out (ed7e0), freeing to device pool DAT_0025b79c. -0x1b56->0. Send-vs-recv asymmetry means the pure 'send' name over-committed; no recorded callers.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001e366c.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
