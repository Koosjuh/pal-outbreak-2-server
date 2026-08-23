# 0x0061f1d0 select_item0_show

| field | value |
|---|---|
| Original address | 0x0061f1d0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0061f1d0 |
| Resolved name | select_item0_show |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00620250, FUN_006205c0, FUN_00620b60, FUN_00620d60, FUN_006231b0, FUN_00623800, FUN_00624c70, FUN_00625670, FUN_00625ea0, FUN_006265f0, FUN_00626900, FUN_00626e70, FUN_00627400, FUN_00627540
**Callees:** —
**Referenced globals:** 0x715310 (selected item idx); 0x71530c (redraw mask)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x715310; 0x71530c

## Behavioral explanation
Sets selected-item index uRam00715310=0 and requests draw (uRam0071530c|=0x400).

## Notes / uncertainty
ui_selected_item(0x715310)=0; mask|=0x400 (selection repaint). Trio with f1f0/f220.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0061f1d0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
