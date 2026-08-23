# 0x005b59b0 menu_mode2_once_redraw

| field | value |
|---|---|
| Original address | 0x005b59b0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b59b0 |
| Resolved name | menu_mode2_once_redraw |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005be9a0
**Referenced globals:** cRam006c4b90 (mode); cRam006c4feb (once-latch); 0x6c517c (redraw buffer)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006c4b90; cRam006c4feb

## Behavioral explanation
In screen-mode==2, once-only (guard cRam006c4feb): set latch and redraw dialog 0x6c517c.

## Notes / uncertainty
One-shot redraw on screen_id==2 via latch cRam006c4feb. Logic exact; latch-reset site external; callee role inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b59b0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
