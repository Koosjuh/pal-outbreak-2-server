# 0x005d5ba0 menu_state_set_dialog

| field | value |
|---|---|
| Original address | 0x005d5ba0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d5ba0 |
| Resolved name | menu_state_set_dialog |
| Subsystem | menus |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005c85d0, FUN_005c9690, FUN_005ca560, FUN_005ca5c0, FUN_005d6460
**Callees:** —
**Referenced globals:** 0x701078+1; 0x701070 menu state; 0x701068+0x68e85/0x68e86
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x701068+0x68e85

## Behavioral explanation
Helper: sets a dialog/notice menu state (0x68e85=0x0b, render fields).

## Notes / uncertainty
Modal dialog park: screen_major=0, render (1,5,0), dialog_kind=0x0b, dialog_sub=2. Raised by form_dispatch failure. Dialog-kind meaning inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d5ba0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
