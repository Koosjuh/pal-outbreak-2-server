# 0x005d5b10 menu_state_set_err

| field | value |
|---|---|
| Original address | 0x005d5b10 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d5b10 |
| Resolved name | menu_state_set_err |
| Subsystem | menus |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005c9690, FUN_005ca1a0, FUN_005d0960, FUN_005d09d0, FUN_005d0a40
**Callees:** —
**Referenced globals:** 0x701070+0x2e screen; 0x701068+0x68e85; 0x701070+1/2
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x701070+0x2e

## Behavioral explanation
Helper: sets menu to state 0x2e=10 (error/notice) with render sub-state.

## Notes / uncertainty
Error/notice screen: screen_id=10, dialog_kind=1, render (1,5). No transition anim. 'error' inferred from post-failure callers.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d5b10.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
