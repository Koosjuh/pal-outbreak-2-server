# 0x00636f90 kbd_keypress_action_dispatch

| field | value |
|---|---|
| Original address | 0x00636f90 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00636f90 |
| Resolved name | kbd_keypress_action_dispatch |
| Subsystem | menus |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00630c90, FUN_00634ab0
**Callees:** FUN_00631670, FUN_006322c0, FUN_00632330, FUN_00634970, FUN_00635bb0, FUN_00637140, FUN_00637430, FUN_00637540, FUN_006375d0, FUN_00637690, FUN_006378b0
**Referenced globals:** 0x715da8 state struct
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x2f mode; 0x48; 0x35 flags; 0x36; 0x248 status

## Behavioral explanation
Central key-action dispatch: validates key via 637430 then switches on key subtype (param+3, cases 0-9) to nav/commit/backspace/space/OK handlers with per-case redraws.

## Notes / uncertainty
Central keypress dispatch on action class *(param_1+3)=0-9 (NOT opcodes); validate via FUN_00637430, switch to select/space/special/page handlers. Busy-guard +0x2f. Case-3 kanji finalize path.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00636f90.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
