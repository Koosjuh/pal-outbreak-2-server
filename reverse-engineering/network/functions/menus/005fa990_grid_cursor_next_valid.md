# 0x005fa990 grid_cursor_next_valid

| field | value |
|---|---|
| Original address | 0x005fa990 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005fa990 |
| Resolved name | grid_cursor_next_valid |
| Subsystem | menus |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005fa490
**Callees:** FUN_005b14b0, FUN_005fa890, FUN_005faa30
**Referenced globals:** +4 cursor index
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +4 cursor

## Behavioral explanation
Advances the grid cursor (btn 0x40004/0x80008) to the next occupied+matching slot via modulo wrap + match test.

## Notes / uncertainty
Advances grid cursor +4 to next non-skipped slot via wrap_index_mod + predicate FUN_005fa890, direction from 0x40004/0x80008. Decompile folded per-step +/- into register extraout_t1_lo -> exact step/direction inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005fa990.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
