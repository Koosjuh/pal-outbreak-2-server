# 0x005f76f0 lobby_screen_dispatch

| field | value |
|---|---|
| Original address | 0x005f76f0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f76f0 |
| Resolved name | lobby_screen_dispatch |
| Subsystem | lobby |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005acab0
**Callees:** FUN_005aec70, FUN_005f5ec0, FUN_005f5f80, FUN_005f7800, FUN_00603e40, FUN_00627d60, FUN_00628e10, FUN_00628ee0, FUN_0062ba00, FUN_0062ba70
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** param+1 (screen id)

## Behavioral explanation
Per-frame dispatcher (gated by busy-check FUN_005aec70) routing on screen-id *(param+1): 0->room page router FUN_005f7800, 1/2/3/9/0xa to area/scenario/room handlers.

## Notes / uncertainty
Per-frame lobby sub-screen dispatcher gated by busy-check FUN_005aec70(==0 proceed); routes on screen-id byte (0x00 room-page,0x01,0x02,0x03,0x09,0x0a room-list) with 3 guarded branches. Screen-id meanings inferred from callee roles; FUN_005aec70 gate condition opaque.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f76f0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
