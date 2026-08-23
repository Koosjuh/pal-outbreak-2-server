# 0x0061f220 select_item2_show

| field | value |
|---|---|
| Original address | 0x0061f220 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0061f220 |
| Resolved name | select_item2_show |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0061fd70, FUN_00625190
**Callees:** —
**Referenced globals:** 0x715310 (selected item idx); 0x71530c (redraw mask)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x715310; 0x71530c

## Behavioral explanation
Sets selected-item index uRam00715310=2 and requests draw (0x71530c|=0x400).

## Notes / uncertainty
ui_selected_item=2; mask|=0x400. 2 callers.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0061f220.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
