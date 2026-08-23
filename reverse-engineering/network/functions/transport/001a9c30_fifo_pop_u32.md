# 0x001a9c30 fifo_pop_u32

| field | value |
|---|---|
| Original address | 0x001a9c30 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001a9c30 |
| Resolved name | fifo_pop_u32 |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d1d90, FUN_001d2900
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
Linear FIFO pop from 0x52c400: clears slot, advances head, decrements len 0x52d610; returns 0 when empty (ambiguous with popped 0). Producer not in scope.

## Raw decompilation
`sources/executables/netstack-decompile/FUN_001a9c30.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
