# 0x006375d0 kbd_navigate_to_key

| field | value |
|---|---|
| Original address | 0x006375d0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006375d0 |
| Resolved name | kbd_navigate_to_key |
| Subsystem | menus |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00635c60, FUN_00636f90
**Callees:** FUN_006322c0, FUN_00634470, FUN_00637140, FUN_00637540, FUN_00637570, FUN_00637690
**Referenced globals:** 0x715da8 state struct
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x1e active-key; 0x24/0x25 cursor; 0x248 status

## Behavioral explanation
Navigates selection to the key mapped from 0x1e (via 637570); on valid, updates active key, rebuilds layout/cursor and redraws preserving cursor col/row.

## Notes / uncertainty
Resolve cell then rebuild type/layout/cursor, status +0x248=1(ok)/5(err), restores cursor col/row. Callees 6322c0/634470 (redraw) not traced.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006375d0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
