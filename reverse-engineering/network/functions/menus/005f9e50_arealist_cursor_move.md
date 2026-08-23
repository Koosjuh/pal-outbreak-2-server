# 0x005f9e50 arealist_cursor_move

| field | value |
|---|---|
| Original address | 0x005f9e50 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f9e50 |
| Resolved name | arealist_cursor_move |
| Subsystem | menus |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f9540
**Callees:** FUN_005b14b0, FUN_005f9d40
**Referenced globals:** 0x69713a-0x69713c cursor bytes (stride 0x14a8)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x69713a cursor byte

## Behavioral explanation
Up/Down cursor move within one area-list entry (btn 0x40004=up / 0x80008=down), then recomputes bounds.

## Notes / uncertainty
Up(0x40004)/Down(0x80008) cursor move within one area slot, wrap in [bound_min,bound_max], gated by enabled +0x98, then recomputes bounds. Control flow exact.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f9e50.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
