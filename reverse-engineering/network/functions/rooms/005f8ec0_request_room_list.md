# 0x005f8ec0 request_room_list

| field | value |
|---|---|
| Original address | 0x005f8ec0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f8ec0 |
| Resolved name | request_room_list |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f8e20
**Callees:** FUN_005af190, FUN_005b68e0, FUN_005b6900, FUN_005b8cf0, FUN_005bff20, FUN_005fba80
**Referenced globals:** 0x6c0760 (room-list table); param+0xf (step); param+0x42b (fade); param+0x97c
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** param+0xf; 0x6c0760

## Behavioral explanation
SM on +0xf: initializes the room-list table 0x6c0760 (30 entries stride 0x15c, indexed), then sends the room-list query FUN_005bff20(0,0xb7,cb 0x5fc0c0) and waits.

## Notes / uncertainty
SM (+0xf): clears 30x0x15c room table 0x6c0760, pre-seeds ids 1..30, then start_txn(0,0xb7,cb roomlist_reply_refresh 0x5fc0c0) = op49 room-list query. Selector 0xb7 -> transport op inferred from reply path, not wire-observed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f8ec0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
