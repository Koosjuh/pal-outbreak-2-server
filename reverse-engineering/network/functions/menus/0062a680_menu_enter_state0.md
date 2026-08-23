# 0x0062a680 menu_enter_state0

| field | value |
|---|---|
| Original address | 0x0062a680 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062a680 |
| Resolved name | menu_enter_state0 |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0062a5e0
**Callees:** FUN_00618b60, FUN_00629d00, FUN_0062b670
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Enter handler for screen 0: bumps state byte, builds widget task list (FUN_0062b670 idx0), schedules FUN_00629d00(2).

## Notes / uncertainty
Phase-0 enter: bumps task step, clears UI list, builds widgets (FUN_0062b670 idx0), installs FUN_00629d60 render in mode 2. FUN_0062b670 widget set not reconstructed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062a680.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
