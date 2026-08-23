# 0x005d9160 ui_draw_box_style7

| field | value |
|---|---|
| Original address | 0x005d9160 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d9160 |
| Resolved name | ui_draw_box_style7 |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ed6e0
**Callees:** FUN_005cab10, FUN_005da650
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
UI overlay primitive: updates viewport extent then emits draw-primitive kind 7 (filled box/quad) with x0,y0,x1,y1 bounds, sentinel color 0xff000001, flag 0x10.

## Notes / uncertainty
Style-7 text widget, twin of mode6. Confirmed the leading 7 is a draw-style id NOT a wire opcode. param_5/strlen data path unresolved. Non-protocol (relevance=unrelated).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d9160.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
