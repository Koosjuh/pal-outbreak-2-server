# 0x0061e810 cursor_index_step

| field | value |
|---|---|
| Original address | 0x0061e810 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0061e810 |
| Resolved name | cursor_index_step |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0061e860
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Adjusts a selection/cursor index by flag bits (bit0 -> decrement, bit1 -> increment up to max) — menu cursor step math.

## Notes / uncertainty
Clamped cursor step: bit0x1 dec / bit0x2 inc within [0,max], no wrap; physical direction of bits inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0061e810.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
