# 0x005ca380 room_name_request_menu_action

| field | value |
|---|---|
| Original address | 0x005ca380 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ca380 |
| Resolved name | room_name_request_menu_action |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ca6a0, FUN_005cce30, FUN_005d5a40, FUN_005d74a0, FUN_005dedf0
**Referenced globals:** 0x701068+0x4f97c work/room buffer; 0x701070+0x3b room name; 0x700fe8 flag; 0x701070+0x2e sub-state
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x701070+0x2e; 0x700fe8

## Behavioral explanation
State-10 handler that copies the room name (FUN_005dedf0 from +0x3b into 0x4f97c), triggers FUN_005d74a0/FUN_005d5a40, sets a flag; state-8 runs the roster pass.

## Notes / uncertainty
ACTION copies room name (menu_ctx+0x3b) into arena+0x4f97c, builds request (005d74a0), sets armed flag 0x700fe8=1, submits (005d5a40). Final wire op (enter 0x2b vs list 0x49) not decoded in this batch.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ca380.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
