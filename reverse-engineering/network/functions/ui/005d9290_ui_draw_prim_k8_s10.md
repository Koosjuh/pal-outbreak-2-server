# 0x005d9290 ui_draw_prim_k8_s10

| field | value |
|---|---|
| Original address | 0x005d9290 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d9290 |
| Resolved name | ui_draw_prim_k8_s10 |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ede30
**Callees:** FUN_005cab10
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
UI overlay primitive wrapper: emits draw kind 8 subtype 0x0a at origin, color sentinel, flag 0x10 (no coords).

## Notes / uncertainty
Menu/list group-begin (kind8 sub10): allocates DL slot, group-id=prev+1, type 0x0b. Group type-byte lifecycle (0x0b->0x15->0x16) read from emitter, not runtime-validated.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d9290.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
