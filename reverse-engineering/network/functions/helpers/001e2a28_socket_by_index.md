# 0x001e2a28 socket_by_index

| field | value |
|---|---|
| Original address | 0x001e2a28 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001e2a28 |
| Resolved name | socket_by_index |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001e2b3c, FUN_001e2c7c, FUN_001e2ffc, FUN_001e3100, FUN_001e332c, FUN_001e34dc, FUN_001e366c, FUN_001e3880, FUN_001e3f98, FUN_001e40b0
**Callees:** —
**Referenced globals:** PTR_0025b798 socket table
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Bounds-checks a socket fd (0..0x3f) and returns the table-entry pointer (base + fd*0x24), else NULL.

## Notes / uncertainty
fd bounds check 0..0x3f -> base+fd*0x24 else NULL. Does not check slot open/bound.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001e2a28.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
