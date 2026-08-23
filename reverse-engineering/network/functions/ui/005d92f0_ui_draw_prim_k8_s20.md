# 0x005d92f0 ui_draw_prim_k8_s20

| field | value |
|---|---|
| Original address | 0x005d92f0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d92f0 |
| Resolved name | ui_draw_prim_k8_s20 |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ede80
**Callees:** FUN_005cab10
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
UI overlay primitive wrapper: emits draw kind 8 subtype 0x14, color sentinel, flag 0x10.

## Notes / uncertainty
Group-commit (kind8 sub20): counts items, writes count byte 0x5f, promotes type to 0x15. Count semantics inferred from emitter.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d92f0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
