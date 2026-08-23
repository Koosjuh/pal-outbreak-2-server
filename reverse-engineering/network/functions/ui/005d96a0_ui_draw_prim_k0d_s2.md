# 0x005d96a0 ui_draw_prim_k0d_s2

| field | value |
|---|---|
| Original address | 0x005d96a0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d96a0 |
| Resolved name | ui_draw_prim_k0d_s2 |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ee220
**Callees:** FUN_005cab10, FUN_005da650, FUN_005da730
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
UI overlay primitive: if positive width/height and drag inactive, updates extent and emits draw kind 0x0d subtype 2.

## Notes / uncertainty
Guarded positive-rect kind0x0d sub2 (w>0,h>0,clip-gate==0). Paired with sub3. Visual role of sub2 vs sub3 inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d96a0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
