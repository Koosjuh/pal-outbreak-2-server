# 0x00602340 render_room_results_screen

| field | value |
|---|---|
| Original address | 0x00602340 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00602340 |
| Resolved name | render_room_results_screen |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005af1e0, FUN_005af2c0, FUN_005af2e0, FUN_005f54d0, FUN_005fe4b0, FUN_00618c20, FUN_0062fdf0, FUN_0062fea0
**Referenced globals:** 0x6c0602 host field; iRam003435d4+0xcb51c name table; +0xcb4ef list-present flag; 0x70b468 base index
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** param_1+4 render-step

## Behavioral explanation
Renders a room results/detail text screen: host field 0x6c0602, scenario labels, selected player name (FUN_005fe4b0), and up to 5 extra name rows from the 0xcb51c name table when 0xcb4ef set.

## Notes / uncertainty
3-way step SM (0 init/1 draw/2 teardown). Scenario-name resolved via lookup_id_to_index/PTR_DAT_0068ae30 + up-to-5 extra name rows. Format-string text @0x649d7x and func_0x007deb80/001b6950/001b68b0 thunks not fetched; not runtime-validated.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00602340.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
