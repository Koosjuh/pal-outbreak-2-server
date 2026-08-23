# 0x0061f180 redraw_flags_clear_bits

| field | value |
|---|---|
| Original address | 0x0061f180 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0061f180 |
| Resolved name | redraw_flags_clear_bits |
| Subsystem | ui |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0061fd70, FUN_00620d60, FUN_00624850, FUN_00625190
**Callees:** —
**Referenced globals:** 0x71530c (UI redraw/visibility mask)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x71530c

## Behavioral explanation
Clears param bits from uRam0071530c (hide/deselect element).

## Notes / uncertainty
mask &= ~param, no transition — plain immediate hide.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0061f180.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
