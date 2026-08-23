# 0x005b5a00 menu_mode3_once_redraw

| field | value |
|---|---|
| Original address | 0x005b5a00 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b5a00 |
| Resolved name | menu_mode3_once_redraw |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005be9a0
**Referenced globals:** cRam006c4b90 (mode); cRam006c4fec (once-latch); 0x6c517c
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006c4b90; cRam006c4fec

## Behavioral explanation
In screen-mode==3, once-only (guard cRam006c4fec): set latch and redraw dialog 0x6c517c.

## Notes / uncertainty
One-shot redraw on screen_id==3 via latch cRam006c4fec (consecutive per-screen latch bytes with feb/fed). Logic exact.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b5a00.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
