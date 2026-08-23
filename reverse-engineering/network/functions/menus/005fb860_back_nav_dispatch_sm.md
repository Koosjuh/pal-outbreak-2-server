# 0x005fb860 back_nav_dispatch_sm

| field | value |
|---|---|
| Original address | 0x005fb860 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005fb860 |
| Resolved name | back_nav_dispatch_sm |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005fb710
**Callees:** FUN_005b14b0, FUN_005b8cf0, FUN_005b9060, FUN_005b9110, FUN_005fba80
**Referenced globals:** +0x97c result code; +0x448/+0x449/+0x440 flags
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x10 sub-state; +0x97c result

## Behavioral explanation
Back/exit confirm SM: on OK button (0x210) resolves the return target from result code +0x97c and pops page state.

## Notes / uncertainty
Back/return dispatcher: on confirm (input 0x210) routes to a destination page by result code +0x97c (4=room list via FUN_005fba80; 3=page(2,1); 0/1/2=page(1,0)). Page-selector byte semantics (+0xe/f/10/11) only partially mapped; 0x210 mask inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005fb860.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
