# 0x005ba5b0 room_header_render_cb

| field | value |
|---|---|
| Original address | 0x005ba5b0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ba5b0 |
| Resolved name | room_header_render_cb |
| Subsystem | rooms |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005af1e0, FUN_005af2c0, FUN_005af2e0, FUN_005bafc0, FUN_005bb060, FUN_00618c20, FUN_0062fea0, FUN_0062fed0
**Referenced globals:** 0x639dc0 flag table by row; 0x006c45f8 bRam=selected room index; 0x006c3878 room-name record base (stride 0x15c); 0x006c547d uRam=password/label buffer; 0x874f3c/0x639e10/0x639d68 strings
**Referenced strings:** 0x874f3c; 0x639e10; 0x639d68
**Referenced opcodes:** —
**State vars:** bRam006c45f8

## Behavioral explanation
Renders the selected-room header: reads flags table 0x639dc0 by +3; on bit0x8000 draws room name via FUN_005bb060(sel) with fmt 0x639d68 and, if FUN_005bafc0(sel) password flag set, draws a lock string with FUN_0062fea0(0x60); bit0x4000 draws a simple icon.

## Notes / uncertainty
Widget SM callback (states 0 init/1 render/2 destroy). Row flag word from 0x639dc0[node[3]]: bit0x8000=room-name row (draws name + conditional password lock via FUN_005bb060/FUN_005bafc0, room record stride 0x1e4), 0x4000=icon row, 0x2000 grouped. HUD renderer, not protocol path; draw-helper signatures inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ba5b0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
