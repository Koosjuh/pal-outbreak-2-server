# 0x005d9790 ui_draw_prim_k0d_s3

| field | value |
|---|---|
| Original address | 0x005d9790 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d9790 |
| Resolved name | ui_draw_prim_k0d_s3 |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ee220, FUN_005ee470
**Callees:** FUN_005cab10, FUN_005da650, FUN_005da730
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
UI overlay primitive: if positive extent and drag inactive, emits draw kind 0x0d subtype 3.

## Notes / uncertainty
Same triple-guard as s2 but kind0x0d sub3; two callers. Sub distinction inferred (paired frame edges).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d9790.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
