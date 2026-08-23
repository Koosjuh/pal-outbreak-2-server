# 0x005aec20 menu_item_reset

| field | value |
|---|---|
| Original address | 0x005aec20 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005aec20 |
| Resolved name | menu_item_reset |
| Subsystem | menus |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f74d0, FUN_005f7570, FUN_005f7610, FUN_005f7690, FUN_005f8b50, FUN_005f8c20, FUN_005fe500, FUN_005ff830, FUN_005ff8d0, FUN_00616bd0, FUN_006179e0, FUN_00617a00, FUN_0062d4e0, FUN_0062d560, FUN_0062e800, FUN_0062e8e0
**Callees:** FUN_005be060, FUN_005be080
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x45b flags; +0x455 type; +0x991 pending-action; +0x42b enable

## Behavioral explanation
Resets a menu-item/widget control block: memset of the 3-byte flag field (+0x45b), clears type/select/enable bytes (+0x455/+0x991/+0x42b), and calls two child-reset helpers.

## Notes / uncertainty
Generic widget reset (16 callers): memset edge flags +0x45b..45d, clear +0x455/+0x991/+0x42b, two child resets FUN_005be060/080. Kind byte preserved. Render/anim split inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005aec20.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
