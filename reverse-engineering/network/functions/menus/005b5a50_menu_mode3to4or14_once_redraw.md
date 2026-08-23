# 0x005b5a50 menu_mode3to4or14_once_redraw

| field | value |
|---|---|
| Original address | 0x005b5a50 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b5a50 |
| Resolved name | menu_mode3to4or14_once_redraw |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005be9a0
**Referenced globals:** cRam006c4b90 (mode); cRam006c4fe5 (precondition flag); cRam006c4fed (once-latch); 0x6c517c
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006c4b90; cRam006c4fe5; cRam006c4fed

## Behavioral explanation
In modes 3-4 or 14 (gated by cRam006c4fe5), once-only (cRam006c4fed): latch and redraw dialog 0x6c517c.

## Notes / uncertainty
One-shot redraw for screen ids {3,4,14}, extra gate cRam006c4fe5, latch cRam006c4fed. Range test (id-3<2||id==0xe) and latch exact; gate meaning + create/config-screen mapping inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b5a50.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
