# 0x005c0f00 get_current_area_index

| field | value |
|---|---|
| Original address | 0x005c0f00 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c0f00 |
| Resolved name | get_current_area_index |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005b57a0, FUN_005b57e0, FUN_005b5820, FUN_005b5860, FUN_005b58a0, FUN_005b58e0, FUN_005b5930, FUN_005b5970, FUN_005b5f60, FUN_00601060, FUN_0062eff0
**Callees:** —
**Referenced globals:** 0x6d2158 (u16 value)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Accessor: returns u16 global 0x6d2158 into caller pointer.

## Notes / uncertainty
Out-param accessor for current area index 0x6d2158 (written by create/enter pumps). 11 UI readers. Behavior certain.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c0f00.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
