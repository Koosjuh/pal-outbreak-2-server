# 0x005d59f0 menu_state_reset_a

| field | value |
|---|---|
| Original address | 0x005d59f0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d59f0 |
| Resolved name | menu_state_reset_a |
| Subsystem | menus |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005c9460, FUN_005ca320, FUN_005cc980, FUN_005cd1d0, FUN_005d1e80, FUN_005d3930, FUN_005d47f0, FUN_005d60a0, FUN_005d6390
**Callees:** —
**Referenced globals:** 0x701078+0x20 selected; 0x701068+0x69014 redraw; 0x701070+1/2/3 menu state
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x701070+1; 0x701068+0x69014

## Behavioral explanation
Small helper: clears selection and sets menu render state (mode 1, sub 0) plus redraw.

## Notes / uncertainty
Leaf: clears selection + redraw latch, sets render tuple (1,0,0). Does NOT touch cursor/lock fields (contrast 5a40). Field labels inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d59f0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
