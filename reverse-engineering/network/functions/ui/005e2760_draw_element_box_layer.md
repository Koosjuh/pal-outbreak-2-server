# 0x005e2760 draw_element_box_layer

| field | value |
|---|---|
| Original address | 0x005e2760 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e2760 |
| Resolved name | draw_element_box_layer |
| Subsystem | ui |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005daf30
**Callees:** FUN_005e0440, FUN_005e0510, FUN_005e19b0, FUN_005e1a30, FUN_005e5910
**Referenced globals:** iRam00701070+4/+8 (scroll origin), +0x14, +0x20/+0x1c (margins)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Element renderer for sprite/tile element types 0x0d/0x0f/0x10: viewport-culls then draws filled/beveled boxes or delegates tiled fill (type 0x0d -> FUN_005e5910).

## Notes / uncertainty
Renamed from draw_element_sprite_types: second draw pass for box element kinds 0x0d/0x0f/0x10 only (beveled panels/buttons; 0x0d delegates to tiled fill). Types are UI kinds not wire ops. Decompiler collapsed a jump table (18 removed blocks).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e2760.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
