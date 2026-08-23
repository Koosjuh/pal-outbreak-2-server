# 0x005b1420 input_pressed_L

| field | value |
|---|---|
| Original address | 0x005b1420 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b1420 |
| Resolved name | input_pressed_L |
| Subsystem | menus |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005fb270, FUN_00628210, FUN_00629200, FUN_006293f0, FUN_006296a0, FUN_0062a8c0, FUN_0062b020, FUN_0062c580
**Callees:** —
**Referenced globals:** 0x6c4618/0x6c4620 pad masks; 0x6c462a pad button-char latch
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Button-edge query: returns true if pad mask bit 0x10 (across held/repeat sets) is set, or the current button-char latch equals '(' (an L-shoulder edge).

## Notes / uncertainty
Inlined input_pressed(0x10): L auto-repeats (edge|repeat) or softkey=='('. Asymmetry vs R (which is edge-only) is real in decompile.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b1420.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
