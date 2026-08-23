# 0x005d9ac0 ui_draw_bordered_box

| field | value |
|---|---|
| Original address | 0x005d9ac0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d9ac0 |
| Resolved name | ui_draw_bordered_box |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f2280
**Callees:** FUN_005cab10, FUN_005da650
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
UI overlay: optional kind 0x0d frame then emits draw kind 0x0f for a bordered box.

## Notes / uncertainty
Simpler sibling of labeled_box: optional label + single kind0x0f fill. param_7 accepted but unused (dead arg).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d9ac0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
