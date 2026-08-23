# 0x0061f0d0 redraw_flags_clear_all

| field | value |
|---|---|
| Original address | 0x0061f0d0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0061f0d0 |
| Resolved name | redraw_flags_clear_all |
| Subsystem | ui |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005b2e40, FUN_0061f8d0, FUN_0061f970, FUN_0061f9f0, FUN_00620250, FUN_006205c0, FUN_00620b60, FUN_00620d60, FUN_00622f40, FUN_00623090, FUN_006231b0, FUN_00623600
**Callees:** —
**Referenced globals:** 0x71530c (UI redraw/visibility mask)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x71530c

## Behavioral explanation
Clears the UI redraw/visibility flag mask uRam0071530c to 0 (invalidate/reset all elements).

## Notes / uncertainty
ui_redraw_mask(0x71530c)=0; reset all element visibility on page enter/exit. Two identical thunks at 0x61e9f0/0x61ea00.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0061f0d0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
