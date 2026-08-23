# 0x005d0f90 scrollbar_thumb_drag

| field | value |
|---|---|
| Original address | 0x005d0f90 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d0f90 |
| Resolved name | scrollbar_thumb_drag |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** —
**Referenced globals:** 0x701078+0x10/0x12 cursor; 0x701078+0x14..0x1c drag anchor; 0x701070+0x4/0x8 scroll; 0x701070+0x24/0x28 thumb pos; 0x701068+0x4f8a2 flags
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x701068+0x4f8a2; 0x701078+4 selected

## Behavioral explanation
Handles scrollbar thumb hit/drag in the edge regions and converts thumb position to view scroll offset.

## Notes / uncertainty
Grab/drag of vert(x 0x248..0x280)/horiz(y 0x17c..0x1c0) thumbs -> scroll via content*(thumb-16)/track; drag-mode bit ui+0x4f8a2&0x10; group>10 sub-thumb maps band->sub_index. End-clamp + group path summarized.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d0f90.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
