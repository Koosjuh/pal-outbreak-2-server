# 0x005ba190 deco_widget_cb

| field | value |
|---|---|
| Original address | 0x005ba190 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ba190 |
| Resolved name | deco_widget_cb |
| Subsystem | menus |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005b9120, FUN_00618c20
**Referenced globals:** 0x639d80 x-pos table; 0x639da0 y-pos table; 0x006c4fd0 cRam=destroy gate
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006c4fd0

## Behavioral explanation
Decoration-widget callback: positions from tables 0x639d80/0x639da0 indexed by (*+0x10)*4 + (+3)*8, sets color 0xff00ff00, runs the +4 lifecycle and optional +0x38 animation.

## Notes / uncertainty
Deco/frame callback; positions from tables 0x639d80/0x639da0 keyed by mode(*+0x10)/subtype(+3); +0x38 node animates (0xff00ff00). Table contents not dumped.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ba190.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
