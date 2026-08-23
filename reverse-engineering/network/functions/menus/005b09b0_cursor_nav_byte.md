# 0x005b09b0 cursor_nav_byte

| field | value |
|---|---|
| Original address | 0x005b09b0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b09b0 |
| Resolved name | cursor_nav_byte |
| Subsystem | menus |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005af780, FUN_005b1b10, FUN_005b2260, FUN_005b3d80, FUN_005b3ed0, FUN_005b4860, FUN_005f9540, FUN_005fa490, FUN_005faa60, FUN_005fec30, FUN_005fede0, FUN_005ff1b0, FUN_00600200, FUN_00604180, FUN_00607bd0, FUN_00607dc0, FUN_00628f70, FUN_0062a6d0, FUN_0062bbc0, FUN_0062cfd0, FUN_0062d730, FUN_0062e5b0
**Callees:** FUN_005b14b0
**Referenced globals:** 0x6c462a pad button-char latch
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Menu cursor navigation with auto-repeat over a byte index: reads Up/Down (and secondary) pad edges via input_pressed, increments/decrements *param_1 with wrap at count param_2, direction/mode param_3; returns 1 when the cursor moved.

## Notes / uncertainty
Two-way byte cursor; mode = axis(0/2 vert,1/3 horiz)+wrap(<2)/clamp(>=2); dual edge+latch test = auto-repeat. Horizontal guard chars (P/O) crossed vs masks (O/P) — held-repeat left/right sense ambiguous, net axis behavior unaffected. 22 callers.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b09b0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
