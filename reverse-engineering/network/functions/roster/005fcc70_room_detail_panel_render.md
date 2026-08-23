# 0x005fcc70 room_detail_panel_render

| field | value |
|---|---|
| Original address | 0x005fcc70 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005fcc70 |
| Resolved name | room_detail_panel_render |
| Subsystem | roster |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005af1e0, FUN_005af2c0, FUN_005af2e0, FUN_005bac80, FUN_005fe4b0, FUN_00618c20, FUN_0062fea0
**Referenced globals:** 0x6970a0 member/area model; bRam006970f4 member count; 0x6970f6 name str; cRam006c5498 cursor; sRam006c4b94 sel slot; 0x6c4bac area id
**Referenced strings:** 0x649878; 0x649880; 0x649888; 0x649ae0; 0x649ae8
**Referenced opcodes:** —
**State vars:** cRam006c5498 selection; bRam006970f4 count

## Behavioral explanation
Renders the room detail / member-list panel: iterates bRam006970f4 member rows drawing name+char, plus scenario/difficulty/area fields, highlighting cRam006c5498 cursor.

## Notes / uncertainty
Joiner room-detail draw callback: renders member roster (0x6970f6 stride 0x14a8, count bRam006970f4) + title/scenario/difficulty/area/footer with cursor highlight cRam006c5498. Cursor->field index map, empty-string placeholder colors, and footer centering rounding transcribed but not runtime-verified.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005fcc70.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
