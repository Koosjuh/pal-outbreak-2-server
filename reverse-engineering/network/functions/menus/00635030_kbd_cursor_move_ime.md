# 0x00635030 kbd_cursor_move_ime

| field | value |
|---|---|
| Original address | 0x00635030 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00635030 |
| Resolved name | kbd_cursor_move_ime |
| Subsystem | menus |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00634ab0
**Callees:** FUN_00631ac0, FUN_00631bb0, FUN_00633930, FUN_00633ab0, FUN_00634470
**Referenced globals:** 0x715da8 kbd/text-entry state struct
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x24 cursor-col; 0x25 cursor-row; 0x26 confirm-flag; 0x28; 0x2e redraw-tick; 0x2f mode/preedit

## Behavioral explanation
D-pad cursor navigation for the soft-keyboard/IME grid: moves col(+0x24, wrap 0x14)/row(+0x25, wrap 3), toggles confirm(0x26) and preedit(0x2f) modes, triggers redraw.

## Notes / uncertainty
21x3 grid cursor nav (col wrap 0x14) w/ confirm-cell detection + IME-candidate regime. d-pad bit up-vs-down assignment inferred; candidate helpers not reconstructed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00635030.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
