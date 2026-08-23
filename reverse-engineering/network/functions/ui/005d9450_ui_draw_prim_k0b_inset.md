# 0x005d9450 ui_draw_prim_k0b_inset

| field | value |
|---|---|
| Original address | 0x005d9450 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d9450 |
| Resolved name | ui_draw_prim_k0b_inset |
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
UI overlay primitive: insets bounds by +0x14, updates extent, emits draw kind 0x0b subtype 1.

## Notes / uncertainty
Fixed 20x20px (+0x14) marker box kind0x0b; grows bounds. Twin of k0c. Rendered appearance not runtime-confirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d9450.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
