# 0x00613da0 menu_render_list_full

| field | value |
|---|---|
| Original address | 0x00613da0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00613da0 |
| Resolved name | menu_render_list_full |
| Subsystem | menus |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00613c30
**Callees:** FUN_0060f830, FUN_0060f860, FUN_006146e0, FUN_006147a0
**Referenced globals:** iRam0070d1c0 (+0x4e page idx); 0x653ff0 (layout table); 0x654010 (row count)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** iRam0070d1c0+0x4e

## Behavioral explanation
Iterates a menu layout table (0x653ff0/0x654010) for the current page (iRam+0x4e) and emits each row's text element.

## Notes / uncertainty
Table-driven list: rows 0x653ff0 / count 0x654010 keyed ctx+0x4e; 8-byte row {s16 x;s16 y;char* str}; x==-1 auto-centers via 0x6147a0(str,0x16).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00613da0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
