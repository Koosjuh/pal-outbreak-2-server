# 0x001ee930 snap_get_info6_f04a0

| field | value |
|---|---|
| Original address | 0x001ee930 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ee930 |
| Resolved name | snap_get_info6_f04a0 |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001c0b20
**Callees:** FUN_001f04a0
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Queries via FUN_001f04a0 into a local struct and, on success (>=0), copies 6 dwords out into the caller's struct (info-getter).

## Notes / uncertainty
Queries 001f04a0 into scratch, on >=0 marshals 6 reordered dwords (src +4,+0,+24,+28,+1c,+20) into caller struct; void return = no failure signal. Field semantics unknown, offsets recovered.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ee930.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
