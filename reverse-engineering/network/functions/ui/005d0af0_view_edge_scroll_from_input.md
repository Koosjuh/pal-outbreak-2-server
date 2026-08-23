# 0x005d0af0 view_edge_scroll_from_input

| field | value |
|---|---|
| Original address | 0x005d0af0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d0af0 |
| Resolved name | view_edge_scroll_from_input |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005d5db0
**Referenced globals:** 0x701070+0x4/0x8 scroll offset; 0x701070+0x1a..0x20 margins; 0x701070+0x18 flags; 0x701068+0x4f8a0 input; 0x701068+0x4f8aa/ab stick2; 0x715da8+0x49c key; 0x36d6dc button
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x701070+0x18; 0x701068+0x4f8a0; 0x36d6dc

## Behavioral explanation
Pans the view/scroll offset when cursor nears screen edges or per analog-stick/pad direction keys (K/N/J/M).

## Notes / uncertainty
View pan (flags&2) from cursor-edge push, 2nd analog stick (16-entry byte tables @0x642de0/df0, x4 if stick2==3 else x2), D-pad repeat, K/N/J/M page keys via 5db0. Table values not dumped.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d0af0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
