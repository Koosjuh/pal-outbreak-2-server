# 0x005f7800 room_page_router

| field | value |
|---|---|
| Original address | 0x005f7800 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f7800 |
| Resolved name | room_page_router |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f76f0
**Callees:** FUN_005af1a0, FUN_005f78c0, FUN_005f7c80, FUN_005f7f30, FUN_005f8030, FUN_005f8220
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** param+0xe (page); param+0x45a (busy)

## Behavioral explanation
Routes the room-detail screen on page byte *(param+0xe) (0-4) to sub-handlers FUN_005f78c0/7c80/7f30/8030/8220; sets busy +0x45a and re-arms input FUN_005af1a0.

## Notes / uncertainty
Per-tick in-room router: busy +0x45a=1, dispatch page byte +0xe (0=roster,1=?,2=slot-select,3=leave-gate,4=leave-send), then input re-arm 005af1a0. Pages 0/1 not decoded.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f7800.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
