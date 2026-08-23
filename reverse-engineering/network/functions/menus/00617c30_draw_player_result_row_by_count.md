# 0x00617c30 draw_player_result_row_by_count

| field | value |
|---|---|
| Original address | 0x00617c30 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00617c30 |
| Resolved name | draw_player_result_row_by_count |
| Subsystem | menus |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005af2c0, FUN_005af2e0, FUN_005fe4b0, FUN_00617fa0, FUN_00618c20, FUN_0062fea0
**Referenced globals:** 0x6c5520 (player count 1..4); 0x654270/0x654340/0x654300/0x6542d0/0x6542b0 (per-count layout tables); 0x6c6e58/0x6c6e5a/0x6c6e5c/0x6c6d7c/0x6c6d94 (result record fields); 0x68ae30 (string ptr table)
**Referenced strings:** 0x654390; 0x654398; 0x6543a0; 0x6543a8 (printf fmt strings)
**Referenced opcodes:** —
**State vars:** +3 slot index; +4 minor-state; +0x26/+0x28 draw coords

## Behavioral explanation
Renders a multi-line confirm/summary dialog whose layout tables (0x654xxx) are selected by global player-count bRam006c5520 (1..4); formats name/score/time strings and positions them via FUN_00617fa0.

## Notes / uncertainty
Renamed. Draws one player's result-summary row; layout table (0x6542b0/d0/0x654300/340) chosen by player count bRam006c5520(1-4); record stride 0x3b0 matches roster rows. No static callers; string-helper identities inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00617c30.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
