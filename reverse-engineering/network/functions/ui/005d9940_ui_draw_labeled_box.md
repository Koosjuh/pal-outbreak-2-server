# 0x005d9940 ui_draw_labeled_box

| field | value |
|---|---|
| Original address | 0x005d9940 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d9940 |
| Resolved name | ui_draw_labeled_box |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f21f0
**Callees:** FUN_005cab10, FUN_005da650
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
UI overlay: optionally draws kind 0x0d frame, then emits two kind 0x10 draws (inset + full) with an offset param for a labeled/bordered box.

## Notes / uncertainty
Composite: grow bounds, optional kind0x0d sub4 label, inner inset (p7&0xff px) + outer kind0x10 fills. Draw-kind 0x10 != wire op10. Compositing order not runtime-confirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d9940.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
