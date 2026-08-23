# 0x00601d50 render_room_detail_screen

| field | value |
|---|---|
| Original address | 0x00601d50 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00601d50 |
| Resolved name | render_room_detail_screen |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005adc80, FUN_005af1e0, FUN_005af2c0, FUN_005af2e0, FUN_005f54d0, FUN_005fe4b0, FUN_00603940, FUN_00618c20, FUN_0062fdf0, FUN_0062fea0
**Referenced globals:** 0x6c0762/0x6c0764 room fields; 0x6c0602 host field; iRam003435d4+0xcf688 selected-name idx
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** param_1+4 render-step; param_1+2/+3 mode

## Behavioral explanation
Renders the room-detail screen text: room field 0x6c0762/0x6c0764 or 0x6c0602 (host name path), scenario/host labels, and player-name lookups (FUN_005fe4b0/func_0x001b68b0) via the string table, using FUN_005af1e0 draws.

## Notes / uncertainty
Room-detail text renderer. Layout descriptor via FUN_0062fdf0(3); draws count (0x6c0762/64), room name (0x6c0778) or host (0x6c0602), scenario (0x6c8afc), selected player-name w/ FUN_005fe4b0 resolve, page indicator. Prime candidate for '(null)' symptom: fallback fmt 0x649d90 on name-resolve fail. layout field names inferred; runtime-unvalidated.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00601d50.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
