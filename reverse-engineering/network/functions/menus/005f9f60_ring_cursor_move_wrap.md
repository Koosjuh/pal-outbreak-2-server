# 0x005f9f60 ring_cursor_move_wrap

| field | value |
|---|---|
| Original address | 0x005f9f60 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f9f60 |
| Resolved name | ring_cursor_move_wrap |
| Subsystem | menus |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f9540
**Callees:** FUN_005b14b0
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x53c ring cursor index

## Behavioral explanation
Left/Right wrap-around cursor move over an 11-slot selectable ring (validity flags @+0x4ba, index @+0x53c).

## Notes / uncertainty
Left/Right 1-based 11-slot ring selector; skips negative(invalid) slots @+0x4ba, wraps, mirrors value to +6. What the ring selects (char/scenario) inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f9f60.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
