# 0x005d9dd0 ui_draw_prim_k14

| field | value |
|---|---|
| Original address | 0x005d9dd0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d9dd0 |
| Resolved name | ui_draw_prim_k14 |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ed6e0, FUN_005edc40
**Callees:** FUN_005cab10
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
UI overlay primitive: emits draw kind 0x14 subtype 1 at origin, sentinel color, flag 0x10.

## Notes / uncertainty
Zero-extent marker kind0x14; twin of k13, two callers incl FUN_005ed6e0 (the inset-glyph screen). Role vs k13 inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d9dd0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
