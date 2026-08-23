# 0x0061d210 menu_labelgroup_draw

| field | value |
|---|---|
| Original address | 0x0061d210 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0061d210 |
| Resolved name | menu_labelgroup_draw |
| Subsystem | menus |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00619800
**Callees:** FUN_0061cc80, FUN_0061cce0
**Referenced globals:** 0x666910 label table; 0x665e30 per-lang string-ptr table
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** bRam0034359d

## Behavioral explanation
Same shape as menu_msglist_draw but for label table DAT_00666910 (index<0x10), rendering each string via text_draw_tokens.

## Notes / uncertainty
Identical shape to d080 for 16-entry label table 0x666910 + per-lang array 0x665e30 (id<0x10). Which screens map to which group not dumped.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0061d210.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
