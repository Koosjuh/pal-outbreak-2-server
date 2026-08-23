# 0x005b1460 input_pressed_R

| field | value |
|---|---|
| Original address | 0x005b1460 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b1460 |
| Resolved name | input_pressed_R |
| Subsystem | menus |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005fb270, FUN_00628210, FUN_00629200, FUN_006293f0, FUN_006296a0, FUN_0062a8c0, FUN_0062b020, FUN_0062c580
**Callees:** —
**Referenced globals:** 0x6c4618 pad mask; 0x6c462a pad button-char latch
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Button-edge query: returns true if pad mask bit 0x200 is set or the button-char latch equals ')' (R-shoulder edge).

## Notes / uncertainty
Inlined input_pressed(0x200): edge-only (no repeat) or softkey==')'.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b1460.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
