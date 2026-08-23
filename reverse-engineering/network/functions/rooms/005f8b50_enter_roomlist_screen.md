# 0x005f8b50 enter_roomlist_screen

| field | value |
|---|---|
| Original address | 0x005f8b50 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f8b50 |
| Resolved name | enter_roomlist_screen |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f82a0, FUN_005fc6b0, FUN_00601420, FUN_0062c970
**Callees:** FUN_005aec20, FUN_00637180
**Referenced globals:** 0x6c4b90 (mode=3); 0x6c0760 (room-list table, 0x28c8); 0x6c4fd9/0x6c4fd8 (page cols); 0x6c4600
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x6c4b90; 0x6c0760

## Behavioral explanation
Initializes the room-list screen: sets 0x6c4b90 mode=3, clears the room-list table 0x6c0760 (0x28c8 bytes), and computes the page/column split (cRam006c4fd9/fd8) from the entry param.

## Notes / uncertainty
Browse-rooms entry: screen_id=3, clears roomlist table 0x6c0760 (0x28c8), positions column/row cursor 0x6c4fd9/0x6c4fd8 from 1-based param (5-per-column grid). Called by leave-reply handler 005f82a0. Cursor geometry read from branch constants, unvalidated; param ordinal-vs-page and table stride unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f8b50.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
