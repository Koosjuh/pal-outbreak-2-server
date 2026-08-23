# 0x005d5c20 menu_screen_change_guarded

| field | value |
|---|---|
| Original address | 0x005d5c20 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d5c20 |
| Resolved name | menu_screen_change_guarded |
| Subsystem | menus |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005c8530, FUN_005c85d0, FUN_005c9690, FUN_005ca0a0, FUN_005cd1d0, FUN_005ce530, FUN_005cf010, FUN_005cf1e0, FUN_005d1e80, FUN_005d3930, FUN_005d47f0
**Callees:** FUN_005d8930
**Referenced globals:** 0x701070+0x38/0x3a lock; 0x701070+2 state
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x701070+0x38/0x3a

## Behavioral explanation
Helper: screen-change variant gated on lock flags (or specific screen params 0x0b-0x0f) calling 5d8930.

## Notes / uncertainty
Lock-gated screen change: swaps only if screen in forced set 0x0b-0x0f OR busy_lock(+0x38)==0 && input_lock(+0x3a)==0, else no-op (won't interrupt in-flight op). busy_lock label inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d5c20.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
