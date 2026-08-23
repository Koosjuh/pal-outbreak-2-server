# 0x001ee1a0 netstate_is_phase3

| field | value |
|---|---|
| Original address | 0x001ee1a0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ee1a0 |
| Resolved name | netstate_is_phase3 |
| Subsystem | initialization |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** —
**Referenced globals:** 0x0037a288 phase
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x0037a288 phase

## Behavioral explanation
Predicate: true when global net phase (0x37a288) == 3 (fully-up/connected state).

## Notes / uncertainty
Predicate phase==3 (link-up gate). No callers recorded, so consumer of the gate not pinned.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ee1a0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
