# 0x005d5cc0 set_display_label_text

| field | value |
|---|---|
| Original address | 0x005d5cc0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d5cc0 |
| Resolved name | set_display_label_text |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005c9460, FUN_005c9690, FUN_005cc980, FUN_005d0960, FUN_005d09d0, FUN_005d0a40, FUN_005d1e80, FUN_005d3930, FUN_005d47f0, FUN_005d5640, FUN_005d60a0, FUN_005d6390
**Callees:** FUN_005dedf0, FUN_005dfb00
**Referenced globals:** 0x701070+0x3b label buf; 0x701068+0x4f97c text sink; 0x701068+0x60dcb filter flag; 0x35ba00 filter tbl
**Referenced strings:** str@0x642fc8
**Referenced opcodes:** —
**State vars:** 0x701068+0x60dcb

## Behavioral explanation
Helper: copies a string into the 0x3b label buffer (with optional filter pass), then pushes it to the on-screen text field.

## Notes / uncertainty
memset+strcpy into 0x100 label buf +0x3b, optional formatted append when filter_enable(+0x60dcb) set & marker 0x642fc8 present, binds to text field 0x4f97c. strstr identity + format-table contents inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d5cc0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
