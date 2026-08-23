# 0x005b3070 screen_roomlist

| field | value |
|---|---|
| Original address | 0x005b3070 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b3070 |
| Resolved name | screen_roomlist |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005b24e0
**Callees:** FUN_005af2f0, FUN_005af300, FUN_005af310, FUN_005b3c30, FUN_005b68e0, FUN_005b6900, FUN_005ba7b0, FUN_005bd720, FUN_005bd730, FUN_005bd740, FUN_005bd790, FUN_005bd7e0, FUN_00618b60
**Referenced globals:** 0x6c4630 bRam006c4630 room count; 0x6c4634 room-name table (stride 0x10); 0x6c4674 room-meta/player table (stride 0x14); 0x6c46c4 room-detail table (stride 0xf0); 0x874f38/0x874f3a/0x874f37 selected-room host info; 0x343625 flag
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** struct+0xf sub-state; struct+0x907 selected room index; 0x6c4630

## Behavioral explanation
Screen-3 room-list machine: loads the room-list arrays (count 0x6c4630; name/meta/detail tables 0x6c4634/0x6c4674/0x6c46c4), drives selection, and delegates join/create to 0x5b3c30.

## Notes / uncertainty
Room-list screen SM: fills 3 parallel per-room tables (name 0x10 / meta 0x14 / detail 0xf0) from count FUN_005bd730; empty->screen 9; delegates interactive join/create to FUN_005b3c30 (advance on ret==1). 0x14 meta contents & 0x874f3x host globals unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b3070.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
