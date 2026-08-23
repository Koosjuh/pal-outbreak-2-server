# 0x005d9ca0 ui_draw_prim_k12

| field | value |
|---|---|
| Original address | 0x005d9ca0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d9ca0 |
| Resolved name | ui_draw_prim_k12 |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005eca10
**Callees:** FUN_005cab10, FUN_005da650
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
UI overlay primitive: updates extent then emits draw kind 0x12 with caller color/flags.

## Notes / uncertainty
Kind0x12 twin of k11, same caller (paired swatch element). Palette-resolved. Visual diff vs k11 inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d9ca0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
