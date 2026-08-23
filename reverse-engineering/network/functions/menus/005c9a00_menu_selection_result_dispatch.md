# 0x005c9a00 menu_selection_result_dispatch

| field | value |
|---|---|
| Original address | 0x005c9a00 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c9a00 |
| Resolved name | menu_selection_result_dispatch |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ca6a0, FUN_005d6460, FUN_005de160, FUN_005de170
**Referenced globals:** 0x701070+0x2e sub-state; 0x701068+0x68e85 lobby phase; 0x701070+2 step; 0x701070+0x18 pad; 0x701068+0x4f8a4 buttons; 0x701070+0x37 flag
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x701070+0x2e; 0x701068+0x68e85; 0x701070+0x2f; 0x701070+0x30

## Behavioral explanation
Reads a menu-result record (FUN_005de170) and switches on its short code 0..3 to set the next screen sub-state (0x2e) and lobby phase (0x68e85).

## Notes / uncertainty
Switch on menu-result code 0..3 -> sets submenu kind(0x2e 3/4/5/6) + phase(0x68e85); code0 has 5-term confirm fastpath (pad 0x20, button 0x8000). Screen identity per kind inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c9a00.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
