# 0x005c9460 room_enter_reset_member_fields

| field | value |
|---|---|
| Original address | 0x005c9460 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c9460 |
| Resolved name | room_enter_reset_member_fields |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005cd320, FUN_005cd760, FUN_005d59f0, FUN_005d5cc0, FUN_005dd920
**Referenced globals:** 0x701068+0x68e80/81/82/84 (room mode/role flags); 0x701070+0x57f/0x590/0x55d/0x56e/0x5a1/0x5b2 (six 17-byte name fields); 0x701070+0x2e (menu kind)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x68e84

## Behavioral explanation
Room enter/create reset: clears the six 17-byte member/chat name fields and status flags, seeds host name (FUN_0010a4f0), sets mode flags (0x68e80-82,0x68e84=2), and registers redraw (FUN_005dd920(0x14,..)).

## Notes / uncertainty
Room-panel enter reset: memsets the six 17-byte member/chat name slots, seeds slot 0 with local player name (memcpy from 0x3c9580), sets role/phase bytes 0x68e80..84, schedules redraw tag 0x14. Exact meaning of role bytes 0x68e80/81/82 not runtime-confirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c9460.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
