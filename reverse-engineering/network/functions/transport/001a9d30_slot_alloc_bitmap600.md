# 0x001a9d30 slot_alloc_bitmap600

| field | value |
|---|---|
| Original address | 0x001a9d30 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001a9d30 |
| Resolved name | slot_alloc_bitmap600 |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d1740, FUN_001d24c0
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
First-free slot allocator over 600-byte busy array 0x52c1a0 (0=free,1=busy); returns 0 on full, colliding with valid index 0. Paired free routine not this fn.

## Raw decompilation
`sources/executables/netstack-decompile/FUN_001a9d30.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
