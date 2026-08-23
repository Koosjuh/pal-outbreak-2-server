# 0x00604940 roster_aggregate_status

| field | value |
|---|---|
| Original address | 0x00604940 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00604940 |
| Resolved name | roster_aggregate_status |
| Subsystem | roster |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00604180
**Callees:** —
**Referenced globals:** 0x70b4d0 (member status)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x70b4d0

## Behavioral explanation
Scans the 0x32-entry status array (0x70b4d0): returns 1 if any status==1 (pending), else 2 if any status==3 (present/remote), else 0.

## Notes / uncertainty
Tri-state summary of status column 0x70b4d0 (0x32/0x38): 1 any PENDING(state1), else 2 any PRESENT(state3), else 0. Enum labels inferred from short-circuit priority.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00604940.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
