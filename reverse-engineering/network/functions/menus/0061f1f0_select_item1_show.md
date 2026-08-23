# 0x0061f1f0 select_item1_show

| field | value |
|---|---|
| Original address | 0x0061f1f0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0061f1f0 |
| Resolved name | select_item1_show |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0061fd70, FUN_00622d60, FUN_00624850, FUN_00625670, FUN_00625ea0, FUN_00626900
**Callees:** —
**Referenced globals:** 0x715310 (selected item idx); 0x71530c (redraw mask)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x715310; 0x71530c

## Behavioral explanation
Sets selected-item index uRam00715310=1 and requests draw (0x71530c|=0x400).

## Notes / uncertainty
ui_selected_item=1; mask|=0x400. Byte-identical to f1d0/f220 except index.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0061f1f0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
