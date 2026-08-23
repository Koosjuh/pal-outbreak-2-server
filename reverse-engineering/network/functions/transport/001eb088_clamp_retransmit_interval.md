# 0x001eb088 clamp_retransmit_interval

| field | value |
|---|---|
| Original address | 0x001eb088 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001eb088 |
| Resolved name | clamp_retransmit_interval |
| Subsystem | transport |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001e19c4
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Computes a reliable-transport interval/timeout from send/ack offsets, clamped to [0x11,32000] and capped to 10x the prior value.

## Notes / uncertainty
Retransmit/RTO interval: 3-way delta select on param_5/param_4, clamp [0x11,32000], cap growth 10x prior, +0x22 bias branch. Timestamp arg semantics inferred by position, not traced; needs caller FUN_001e19c4 to pin fields/units.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001eb088.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
