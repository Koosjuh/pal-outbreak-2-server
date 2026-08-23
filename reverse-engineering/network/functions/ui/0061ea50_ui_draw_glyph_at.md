# 0x0061ea50 ui_draw_glyph_at

| field | value |
|---|---|
| Original address | 0x0061ea50 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0061ea50 |
| Resolved name | ui_draw_glyph_at |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_0061eab0
**Callees:** FUN_0061c940, FUN_0061cc80
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Draws one text/label element: obtains a slot (c940), builds it (cc80, param_3), then extern 0x1af080/0x1af0d0 to submit; helper for the keyboard renderer eab0.

## Notes / uncertainty
Draws one glyph/paging-arrow: acquire handle(c940) -> measure/center(cc80,x) -> setpos(0x1af080,y) -> submit(0x1af0d0). Params (glyph_sel,y,x_anchor) inferred from eab0 call sites; extern names inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0061ea50.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
