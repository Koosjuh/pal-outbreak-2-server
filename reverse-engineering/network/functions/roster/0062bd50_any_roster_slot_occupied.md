# 0x0062bd50 any_roster_slot_occupied

| field | value |
|---|---|
| Original address | 0x0062bd50 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062bd50 |
| Resolved name | any_roster_slot_occupied |
| Subsystem | roster |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0062a6d0, FUN_0062bbc0
**Callees:** —
**Referenced globals:** +0x1055 roster occupancy
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Returns 1 if any of the 3 roster slots (+0x1055, stride 0x25) is non-empty, else 0.

## Notes / uncertainty
Predicate: returns 1 if any of 3 member sub-records (stride 0x25, flag@+0x1055) occupied; scans all 3, no early-out. Enclosing-block identity (a third, 0x25-stride roster representation) set by callers, not resolved here.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062bd50.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
