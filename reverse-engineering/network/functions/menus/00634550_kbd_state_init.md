# 0x00634550 kbd_state_init

| field | value |
|---|---|
| Original address | 0x00634550 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00634550 |
| Resolved name | kbd_state_init |
| Subsystem | menus |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ac610, FUN_005ac6f0, FUN_005c80a0, FUN_005f3e30, FUN_006069b0, FUN_0060f910
**Callees:** FUN_00634540, FUN_006345a0
**Referenced globals:** 0x715da8 (kbd state base ptr); 0x715de7
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x715da8

## Behavioral explanation
Initializes the keyboard state pointer (0x715da8=0x715db0), clears +0x4a8, and sets the keyboard type via FUN_006345a0.

## Notes / uncertainty
Aims g_kbd_state(0x715da8) at default block 0x715db0, clears block+0x37, resets, sets type. Purpose of the +0x37 flag byte unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00634550.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
