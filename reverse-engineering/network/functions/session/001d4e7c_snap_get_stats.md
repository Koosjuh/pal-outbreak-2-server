# 0x001d4e7c snap_get_stats

| field | value |
|---|---|
| Original address | 0x001d4e7c |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d4e7c |
| Resolved name | snap_get_stats |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001eccd8
**Referenced globals:** 0x0025b78c conn-ptr
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** conn+0x520 pool; conn+0x524..0x544 counters

## Behavioral explanation
Snapshots the 9 running counters at conn+0x524..0x544 into the caller struct and reads pool stats from conn+0x520.

## Notes / uncertainty
Snapshots pool(conn+0x520 via 001eccd8) + 9 u32 counters conn+0x524..0x544 into dst+0x34; 0/-1. Counter meanings + pool-snapshot head layout undecoded.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d4e7c.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
