# 0x005f0340 ui_layout_cursor_reset

| field | value |
|---|---|
| Original address | 0x005f0340 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f0340 |
| Resolved name | ui_layout_cursor_reset |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005eb7d0
**Callees:** FUN_005ef640, FUN_005ef780
**Referenced globals:** +0xd8ce/+0xd8d0/+0xd8d2/+0xd8d4/+0xd8d6/+0xd8d8/+0xd8dc layout cursors; +0x16 running height; node+0x1c/+0x28/+0x2a box
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x186; +0xd8d4; +0xd8dc

## Behavioral explanation
Seeds the global layout cursors (ctx+0xd8ce..+0xd8de) from a node's box, zeros running positions, then (draw mode) computes h/v align offsets.

## Notes / uncertainty
Seeds layout cursor block (ctx+0xd8ce..+0xd8de) from node box, zeroes accumulators; draw-pass calls align helpers ef640/ef780. Sub-cursor roles partly inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f0340.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
