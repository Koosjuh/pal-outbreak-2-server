# 0x005f3150 ui_draw_inline_at_cursor

| field | value |
|---|---|
| Original address | 0x005f3150 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f3150 |
| Resolved name | ui_draw_inline_at_cursor |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f3310, FUN_005f3930
**Callees:** FUN_005eca10, FUN_005ef780
**Referenced globals:** +0x186 draw mode; +0xd894 node idx; +0xd8ce/+0xd8d0/+0xd8d6/+0xd8d8 cursors; node+0x251a/+0x251c/+0x251e pad/offset
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x186; +0xd8ce

## Behavioral explanation
In draw mode computes the current inline cursor position (h-align + line cursors) and renders content there via FUN_005eca10.

## Notes / uncertainty
Draw-only leaf: computes pen x/y from indent+align+pad cursors, pushes element style (5ef780), draws content (5eca10). Payload param opaque.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f3150.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
