# 0x005ff690 screen_confirm_dialog_0x18_sm

| field | value |
|---|---|
| Original address | 0x005ff690 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ff690 |
| Resolved name | screen_confirm_dialog_0x18_sm |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005fe730
**Callees:** FUN_005b68e0, FUN_005b6900, FUN_005c44a0, FUN_005ff830
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** param_1+0x10 sub-step; param_1+0x16 timer; param_1+0x907 cursor; param_1+0x42b screen-id=0x18

## Behavioral explanation
4-state confirm/exit screen: sets screen-id 0x18, registers render cb 0x601390, and on timeout resets state via FUN_005ff830.

## Notes / uncertainty
4-state auto-dismiss confirm dialog: enter overlay 0x18 (cb 0x601390, mode 0), idle, arm (cursor=0,timer=10), on timeout hard-reset to base screen 8 via FUN_005ff830. State 1->2 driver (render cb/confirm) external.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ff690.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
