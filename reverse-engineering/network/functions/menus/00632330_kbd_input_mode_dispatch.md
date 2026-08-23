# 0x00632330 kbd_input_mode_dispatch

| field | value |
|---|---|
| Original address | 0x00632330 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00632330 |
| Resolved name | kbd_input_mode_dispatch |
| Subsystem | menus |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00630c90, FUN_006352e0, FUN_00636f90
**Callees:** FUN_00633470, FUN_006334f0, FUN_00637140
**Referenced globals:** 0x715da8 (kbd state block; +0x2f input-mode, +0x248 redraw flag)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x715da8+0x2f (input mode); 0x715da8+0x248 (redraw)

## Behavioral explanation
Per-frame branch on name-entry input mode (state+0x2f): mode0 rebuilds predictive candidates, else commits predictive selection and clears redraw flag.

## Notes / uncertainty
Per-mode dispatcher on +0x2f: direct (rebuild candidates + apply) vs converting (apply conversion + clear redraw). Callee roles inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00632330.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
