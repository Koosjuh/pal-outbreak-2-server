# 0x005c5610 roster_remove_member

| field | value |
|---|---|
| Original address | 0x005c5610 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c5610 |
| Resolved name | roster_remove_member |
| Subsystem | roster |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005c5390, FUN_005c5460
**Referenced globals:** 0x6fee8c roster-connid-key
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Finds the roster slot whose connID matches param, clears it (roster_slot_clear) and refreshes the member-list UI.

## Notes / uncertainty
Leave counterpart: scans 30 connID slots, clears match (1-based), fires UI refresh. Coexists with alt leave handler 0x005bb670 for a different leave representation; which dispatch code binds is uncertain.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c5610.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
