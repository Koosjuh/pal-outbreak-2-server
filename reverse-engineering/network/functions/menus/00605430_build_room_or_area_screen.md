# 0x00605430 build_room_or_area_screen

| field | value |
|---|---|
| Original address | 0x00605430 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00605430 |
| Resolved name | build_room_or_area_screen |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_006052f0
**Callees:** FUN_005ba570, FUN_005ba7b0, FUN_006053e0, FUN_00618b60
**Referenced globals:** &DAT_0064a050/0x64a060/0x64a064/0x64a072 (id/x tables); bRam006970f4 (list length); +0x309c (per-entry active flag)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** bRam006970f4

## Behavioral explanation
Builds a full screen's worth of draw nodes (title id 0x71/0x72, list rows id 0x4d, cursors 0xce) with callbacks FUN_00605690/005790/005a90; param2==0 lays out one screen (4 slots), else a room-list/area screen sized by bRam006970f4.

## Notes / uncertainty
Two-branch screen builder: param2==0 = in-room 4-player roster (rows gated by slot-active +0x309c, stride 0x3b0), param2!=0 = room/area list sized by bRam006970f4. Element ids 0x71/0x72/0x4d/0xce, cursor-menu 0x22/0x21. Uncertain whether nonzero branch is room-list vs area-select (shared builder).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00605430.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
