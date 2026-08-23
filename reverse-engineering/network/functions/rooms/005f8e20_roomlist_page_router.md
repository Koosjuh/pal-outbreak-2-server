# 0x005f8e20 roomlist_page_router

| field | value |
|---|---|
| Original address | 0x005f8e20 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f8e20 |
| Resolved name | roomlist_page_router |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f8d40
**Callees:** FUN_005f8ec0, FUN_005f8fc0, FUN_005f9150, FUN_005fa0b0, FUN_005fb710
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** param+0xe (page)

## Behavioral explanation
Routes the room-list screen on page byte +0xe (0-4) to sub-handlers FUN_005f8ec0/8fc0/fa0b0/f9150/fb710.

## Notes / uncertainty
Routes lobby_sm(+0xe) 0..4; 4=browse(FUN_005fb710), 3=join_room_router, 0=init/build. Pages 1/2 roles not traced.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f8e20.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
