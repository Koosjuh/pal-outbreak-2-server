# 0x005d9520 ui_draw_prim_k0c_inset

| field | value |
|---|---|
| Original address | 0x005d9520 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d9520 |
| Resolved name | ui_draw_prim_k0c_inset |
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
UI overlay primitive: insets bounds by +0x14, updates extent, emits draw kind 0x0c subtype 1.

## Notes / uncertainty
20px square marker kind0x0c; byte-twin of k0b, same caller FUN_005ed6e0 (adjacent glyph pair).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d9520.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
