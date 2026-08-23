# 0x001d4fa4 snap_reset_stats

| field | value |
|---|---|
| Original address | 0x001d4fa4 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d4fa4 |
| Resolved name | snap_reset_stats |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001ecd28
**Referenced globals:** 0x0025b78c conn-ptr
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** conn+0x520 pool; conn+0x524..0x544 counters

## Behavioral explanation
Resets the pool stats (conn+0x520) and zeroes the 9 counters at conn+0x524..0x544.

## Notes / uncertainty
Write counterpart to get_stats: resets pool (001ecd28) + zeroes 9 counters conn+0x524..0x544. Counter semantics undecoded.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d4fa4.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
