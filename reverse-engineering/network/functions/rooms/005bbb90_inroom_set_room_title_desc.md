# 0x005bbb90 inroom_set_room_title_desc

| field | value |
|---|---|
| Original address | 0x005bbb90 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bbb90 |
| Resolved name | inroom_set_room_title_desc |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005bba20
**Callees:** FUN_005bdfe0, FUN_005c50a0
**Referenced globals:** 0x6fc2d8 (room block hdr); 0x6fc2e8 (0x300 title/desc); 0x6febe8 (room owner id); 0x6cbc7e/0x6cbc84 (UI status)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Sub-event 1: zero-fills then loads a 0x300-byte room title/description block (0x6fc2d8/0x6fc2e8) from the payload, records owner id (0x6febe8), and enqueues a UI refresh (FUN_005bdfe0(0xc)).

## Notes / uncertainty
op0x13 sub-1: clears 0x310 title block, encodes owner id (FUN_005c50a0) at 0x6fc2d8, copies 0x300 text from body+4 to 0x6fc2e8, sets room_mode 0x6cbc7e=0x10, redraw FUN_005bdfe0(0xc). body param passed via register at callsite.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bbb90.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
