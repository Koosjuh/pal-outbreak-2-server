# 0x005c2e90 get_menu_label_by_playercount

| field | value |
|---|---|
| Original address | 0x005c2e90 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c2e90 |
| Resolved name | get_menu_label_by_playercount |
| Subsystem | menus |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005c2f40, FUN_005c3b10
**Callees:** —
**Referenced globals:** 0x34359d (player-count selector); 0x640480 / 0x6404a0 (label pointer tables)
**Referenced strings:** No. of Players; defficulity control
**Referenced opcodes:** —
**State vars:** cRam0034359d

## Behavioral explanation
Returns a UI label string pointer selected by player-count (cRam0034359d, 2..5): param0 -> 'No. of Players' table, param1 -> difficulty table.

## Notes / uncertainty
Pure lookup: cRam0034359d (count 2..5 -> idx 1..4, else 0) x param table (0x640480 player-count / 0x6404a0 difficulty). Runtime-unvalidated; index-0 caption meaning unproven.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c2e90.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
