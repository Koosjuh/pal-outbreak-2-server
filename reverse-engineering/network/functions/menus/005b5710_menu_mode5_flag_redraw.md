# 0x005b5710 menu_mode5_flag_redraw

| field | value |
|---|---|
| Original address | 0x005b5710 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b5710 |
| Resolved name | menu_mode5_flag_redraw |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005be9a0
**Referenced globals:** cRam006c4b90 (screen/menu mode); uRam006c5521 (menu flag); 0x6c517c (dialog redraw buffer)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006c4b90; uRam006c5521

## Behavioral explanation
If screen-mode==5 (and !=6), set flag uRam006c5521=2 and trigger menu redraw of dialog buffer 0x6c517c.

## Notes / uncertainty
Per-screen redraw hook: if screen_id==5 set flag 0x6c5521=2 and redraw 0x6c517c. Guard/writes exact; FUN_005be9a0 (redraw vs enqueue) and flag value semantics inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b5710.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
