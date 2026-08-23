# 0x005af780 screen_title_menu_input

| field | value |
|---|---|
| Original address | 0x005af780 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005af780 |
| Resolved name | screen_title_menu_input |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005af4d0
**Callees:** FUN_005b09b0, FUN_005b14b0
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x900 input state; +0x907 selection; +0x918

## Behavioral explanation
Sub-FSM for the title menu (state at +0x900): drives cursor selection via cursor_nav_byte and confirm/back via input_pressed, transitioning the screen when a choice commits.

## Notes / uncertainty
Input sub-FSM on screen+0x900; returns 1 only in committed state (1). Confirm=input_pressed(0x10)->state1,+0x918=2; cancel=0x200 polled but effect not stored locally (handled by outer dispatcher).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005af780.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
