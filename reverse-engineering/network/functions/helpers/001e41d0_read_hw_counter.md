# 0x001e41d0 read_hw_counter

| field | value |
|---|---|
| Original address | 0x001e41d0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001e41d0 |
| Resolved name | read_hw_counter |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001e41fc
**Callees:** —
**Referenced globals:** Count hw tick
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Returns the free-running hardware tick counter (global Count).

## Notes / uncertainty
Returns EE 'Count' free-running tick; delta-accumulated by e41fc. Raw COP0 vs kernel mirror + freq unpinned.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001e41d0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
