# 0x00600200 room_detail_screen_sm_variant2

| field | value |
|---|---|
| Original address | 0x00600200 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00600200 |
| Resolved name | room_detail_screen_sm_variant2 |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ff9f0
**Callees:** FUN_005b09b0, FUN_005b0b40, FUN_005b14b0, FUN_005f4b80, FUN_005f4be0, FUN_00600b60, FUN_006020e0, FUN_00602230, FUN_00602700
**Referenced globals:** iRam003435d4+0xc942c slots; +0xcb4ec current-slot copy; +0xcb51c name/host; 0x70b460/0x70b468 counters
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** param_1+0xf step; param_1+0x907 cursor; param_1+0x908 slot; param_1+0x3f6c compare key; param_1+0x43a render-req

## Behavioral explanation
Second in-room detail screen state-machine (parallels FUN_005fede0 for the 0x10 room variant): syncs the selected member slot 0x908, copies the current-slot record into cb4ec/cf5c0/2e1c display buffers, advances via FUN_00600b60, and renders roster via FUN_00602700.

## Notes / uncertainty
Variant-2 (room-mode 0x10 toggle) detail SM. Extra 0x830 player-data block (4x @0xc942c) mirrored to 0xcb4ec; de-dup scan finds local player's own slot via memcmp vs 0xcb4f0; paged reliable sends behind guards 0x10/0x200/0x80/0x40; confirm/cancel ladder w/ SFX. Guard-pool->op mapping and self-match key length inferred; runtime-unvalidated.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00600200.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
