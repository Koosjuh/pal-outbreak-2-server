# 0x005f82a0 on_room_action_reply

| field | value |
|---|---|
| Original address | 0x005f82a0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f82a0 |
| Resolved name | on_room_action_reply |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005b9110, FUN_005f8b50
**Referenced globals:** 0x6c4fbb (pending-op type ==5); 0x6c4b9e; 0x6c4b9f; 0x6c4ba0; 0x6c4b90 (mode)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x6c4fbb

## Behavioral explanation
Reply handler gated on pending flag cRam006c4fbb=='\x05': on result 0 enters the room-list screen FUN_005f8b50(0); on failure resets the 0x6c4b9e state block and tears down net FUN_005b9110(0x4c).

## Notes / uncertainty
Async reply cb gated on pending 0x6c4fbb==5, screen!=6: result 0 -> enter_roomlist_screen; else reset nav block + set_msg_channel(0x4c). Which request arms tag 5 (paired sender FUN_005f8220) not pinned.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f82a0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
