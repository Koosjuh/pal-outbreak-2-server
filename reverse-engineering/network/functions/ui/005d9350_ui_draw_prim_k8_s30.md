# 0x005d9350 ui_draw_prim_k8_s30

| field | value |
|---|---|
| Original address | 0x005d9350 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d9350 |
| Resolved name | ui_draw_prim_k8_s30 |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ee010, FUN_005f2b10
**Callees:** FUN_005cab10, FUN_005da650
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
UI overlay primitive: updates extent then emits draw kind 8 subtype 0x1e over x0,y0,x1,y1 bounds.

## Notes / uncertainty
Group-activate (kind8 sub30): grows bounds + binds hit-rect, activates committed group, demotes stale 0x15->0x16. Selection semantics inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d9350.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
