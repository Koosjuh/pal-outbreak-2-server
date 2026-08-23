# 0x001e2a90 socket_by_id

| field | value |
|---|---|
| Original address | 0x001e2a90 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001e2a90 |
| Resolved name | socket_by_id |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001e3a3c
**Callees:** —
**Referenced globals:** PTR_0025b798 socket table
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** slot+0 low-level id

## Behavioral explanation
Linear-scans the socket table for the slot whose id field(+0) matches the given short, returns entry pointer or NULL.

## Notes / uncertainty
Linear scan of 64 slots for [+0] short id match; RX demux reverse lookup. 0xffff=free would match first free slot if queried.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001e2a90.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
