# 0x005ba570 spawn_room_header_widget

| field | value |
|---|---|
| Original address | 0x005ba570 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ba570 |
| Resolved name | spawn_room_header_widget |
| Subsystem | rooms |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005b3cb0, FUN_005b3ed0, FUN_005b41b0, FUN_005b45f0, FUN_005b47a0, FUN_005f62e0, FUN_005f8340, FUN_005fba80, FUN_005fc850, FUN_00604af0, FUN_00605430, FUN_00607f70, FUN_00628760, FUN_00629a40, FUN_0062b670, FUN_0062cd20
**Callees:** FUN_00618ba0
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Allocates a display node with callback FUN_005ba5b0 and stores param in +3 (row/kind selector).

## Notes / uncertainty
Allocates a widget-pool node (64 slots @0x7133f0 stride 0x54 via FUN_00618ba0), installs render cb 0x005ba5b0, stores row selector in node[3]; NULL on pool-full = no-op. 16 room/lobby screen callers.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ba570.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
