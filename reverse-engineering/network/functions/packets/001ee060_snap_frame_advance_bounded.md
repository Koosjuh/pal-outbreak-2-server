# 0x001ee060 snap_frame_advance_bounded

| field | value |
|---|---|
| Original address | 0x001ee060 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ee060 |
| Resolved name | snap_frame_advance_bounded |
| Subsystem | packets |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001edbb8, FUN_001edd9c
**Callees:** FUN_001ebca8, FUN_001ed6bc
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** buf used-length

## Behavioral explanation
Returns param_2+param_3 (next frame ptr) only if it stays within [payload_base, payload_base+used-length); else 0 (end-of-buffer sentinel).

## Notes / uncertainty
cur+step returned only if inside half-open payload window [base,base+used_len); else 0. Window locked by payload_ptr+used_len getters.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ee060.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
