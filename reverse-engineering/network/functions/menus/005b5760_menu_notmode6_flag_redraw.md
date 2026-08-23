# 0x005b5760 menu_notmode6_flag_redraw

| field | value |
|---|---|
| Original address | 0x005b5760 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b5760 |
| Resolved name | menu_notmode6_flag_redraw |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005be9a0
**Referenced globals:** cRam006c4b90 (screen/menu mode); uRam006c50fa (menu flag); 0x6c517c (dialog redraw buffer)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006c4b90; uRam006c50fa

## Behavioral explanation
If screen-mode!=6, set flag uRam006c50fa=2 and redraw dialog buffer 0x6c517c.

## Notes / uncertainty
Broadest redraw hook: any screen_id!=6 -> flag 0x6c50fa=2 + redraw 0x6c517c. Logic exact; callee role inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b5760.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
