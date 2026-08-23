# 0x005d5db0 scroll_offset_add

| field | value |
|---|---|
| Original address | 0x005d5db0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d5db0 |
| Resolved name | scroll_offset_add |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005d0af0
**Callees:** —
**Referenced globals:** 0x701070+0x4/0x8 scroll; 0x701078+4 active
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Helper: adds dx/dy to the view scroll offset and clears the cursor-active flag.

## Notes / uncertainty
Leaf: scroll_x/+4 += dx, scroll_y/+8 += dy, clears cursor_active +4. cursor_active label inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d5db0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
