# 0x00629d60 render_charsel_scenario_screen

| field | value |
|---|---|
| Original address | 0x00629d60 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00629d60 |
| Resolved name | render_charsel_scenario_screen |
| Subsystem | ui |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005af1e0, FUN_005af2c0, FUN_005af2e0, FUN_005b7cd0, FUN_0062fd90, FUN_0062fea0
**Referenced globals:** 0x6c555e player-count; 0x6c5562 slot-active; 0x6c5573 slot-name(0xa5); 0x6c5be5/0x6c5e5a scenario-text; 0x66acc8/0x66acd0 layout
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** bRam006c555e player-count

## Behavioral explanation
Large render callback for the character/scenario/room-info screen: draws roster rows with per-player names (0x6c5573) and ready-highlight, scenario titles, difficulty and the 'players in room' count derived from bRam006c555e.

## Notes / uncertainty
Master 4-mode draw cb (0 roster+count,1 briefing,2/3 scenario list,4 notes). Draws roster+player count from bRam006c555e and active-slot scan of 0x6c5562. Scenario/notes table strides (0x6c5be5/0x6c5e5a) and layout DAT pixels reconstructed schematically ([inferred]); highlight coord-table split inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00629d60.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
