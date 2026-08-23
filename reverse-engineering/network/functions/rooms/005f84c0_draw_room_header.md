# 0x005f84c0 draw_room_header

| field | value |
|---|---|
| Original address | 0x005f84c0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f84c0 |
| Resolved name | draw_room_header |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005af1e0, FUN_005af2c0, FUN_005af2e0, FUN_005b0950, FUN_005f54d0, FUN_00618c20, FUN_0062fdf0
**Referenced globals:** 0x6c45f8 (local member id/count); 0x6c50fb; 0x6c4b90 (mode); 0x649768 (format str)
**Referenced strings:** (format string @0x649768)
**Referenced opcodes:** —
**State vars:** 0x6c4b90

## Behavioral explanation
Draw callback for the room header/count widget: formats a string (fmt 0x649768) with the member count (FUN_005b0950 over uRam006c45f8); flag+2 branch sets widget id 0x37 when in lobby/create mode (cRam006c4b90 in {2,0xe}).

## Notes / uncertainty
Room header/player-count draw callback (the on-screen count surface). Draw SM +4; sub-phase0 composes header via sprintf(fmt 0x649768) with count from 0x6c45f8; sub-phase1 shows widget (id 0x37) only when 0x6c50fb==0 and screen_id in {2,0x0e}. Whether count source is 0x6c45f8 vs 0x6c45fe needs a live read.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f84c0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
