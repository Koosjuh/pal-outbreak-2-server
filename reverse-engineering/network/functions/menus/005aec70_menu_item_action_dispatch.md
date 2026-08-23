# 0x005aec70 menu_item_action_dispatch

| field | value |
|---|---|
| Original address | 0x005aec70 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005aec70 |
| Resolved name | menu_item_action_dispatch |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005acab0, FUN_005f76f0, FUN_005f8d40, FUN_005fe620, FUN_005ff950, FUN_00616c40, FUN_00617a50, FUN_0062d5e0
**Callees:** FUN_005f7690, FUN_005f8c20, FUN_005ff830, FUN_00616bd0, FUN_006179e0, FUN_0062d560
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x455 gate; +0x45a enable; +0x45b/45c/45d edge flags; +0x991 pending

## Behavioral explanation
Per-widget action dispatcher: gated by enable byte +0x45a, routes on pending-action (+0x991) then on the item TYPE byte (*param_1 = 0x0e/0x04/0x03/0x02) plus edge flags (+0x45b..45d) to type-specific handlers.

## Notes / uncertainty
Per-frame submit dispatcher: gate +0x45a, sub-panel +0x455, pending +0x991, then widget KIND (*obj 0x02/0x03/0x04/0x0e) + edge flags +0x45b/c/d -> type handlers. KIND bytes are UI item types, NOT wire opcodes. Human kind names inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005aec70.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
