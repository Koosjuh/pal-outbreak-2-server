# 0x006277a0 roster_display_table_init

| field | value |
|---|---|
| Original address | 0x006277a0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006277a0 |
| Resolved name | roster_display_table_init |
| Subsystem | roster |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ac610, FUN_006195b0
**Callees:** FUN_00604810
**Referenced globals:** 0x715500 roster-disp-table(0x14x50); 0x7154e0 local-slot; 0x694700 master-roster(0x38x50)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Clears the room roster display tables (0x715500 stride-0x14 x50, plus 0x7154e0) and seeds the first N slots' 16-byte ids from the master roster 0x694700+0x10.

## Notes / uncertainty
(Re)builds 0x715500 display table (50 x 0x14: id16,in_use,status,timer) from registry 0x694700 valid-count; clears selected-slot buffer. Entry stride corroborated by 3 sibling fns. No runtime.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006277a0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
