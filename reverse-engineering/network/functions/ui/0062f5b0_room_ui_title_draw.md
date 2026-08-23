# 0x0062f5b0 room_ui_title_draw

| field | value |
|---|---|
| Original address | 0x0062f5b0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062f5b0 |
| Resolved name | room_ui_title_draw |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005af1e0, FUN_005af2c0, FUN_005af2e0, FUN_005fe4b0, FUN_00618c20, FUN_0062fea0
**Referenced globals:** 0x6c4b94 selected char slot; 0x6c4baa/bab/bac char fields; 0x68ae30 string-ptr table
**Referenced strings:** 0x66af60 fmt
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
UI task update: draws room title/label text via FUN_005af1e0 using char-slot data at sRam006c4b94 (0x6c4baa/bac), formatting strings from 0x66af60 / PTR table 0x68ae30.

## Notes / uncertainty
Room header draw callback: self-frees on dead owner; draws title icon + selected-slot name label from 0x6c4baa/bab/bac arrays with A/B name-source modes. Mechanics High, domain of slot arrays (char/area/scenario) Medium.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062f5b0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
