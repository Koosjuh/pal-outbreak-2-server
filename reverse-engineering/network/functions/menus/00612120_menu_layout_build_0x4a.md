# 0x00612120 menu_layout_build_0x4a

| field | value |
|---|---|
| Original address | 0x00612120 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00612120 |
| Resolved name | menu_layout_build_0x4a |
| Subsystem | menus |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00614b90
**Callees:** FUN_0060ea60, FUN_00614c80
**Referenced globals:** ctx+0x4a (screen/layout id); ctx+0x10-0x1e (field values driving offsets)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** ctx+0x4a layout selector

## Behavioral explanation
Per-screen layout builder: switch(ctx+0x4a screen id) emits a sequence of UI element placements via FUN_00614c80 (element id, x, y) for each lobby/create/room panel; appends common elements 4 and 6.

## Notes / uncertainty
Rewrote from classified stub to full reconstruction. Layout builder switch on ctx+0x4a (0..0x11); emits element placements via FUN_00614c80(id,x,y), y from cursor/count fields; appends common elems 4+6. Element-id catalogue not decoded.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00612120.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
