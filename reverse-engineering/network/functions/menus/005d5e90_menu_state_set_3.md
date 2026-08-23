# 0x005d5e90 menu_state_set_3

| field | value |
|---|---|
| Original address | 0x005d5e90 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d5e90 |
| Resolved name | menu_state_set_3 |
| Subsystem | menus |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005c8d10, FUN_005c8e70
**Callees:** —
**Referenced globals:** 0x700fe0; 0x701070+1/2/3 state
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x701070+1

## Behavioral explanation
Helper: stores a param into 0x700fe0 and sets menu render state 3.

## Notes / uncertainty
Leaf: stores selector to 0x700fe0, sets render mode 3 tuple. Selector/mode-3 meaning inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d5e90.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
