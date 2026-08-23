# 0x005d9d70 ui_draw_prim_k13

| field | value |
|---|---|
| Original address | 0x005d9d70 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d9d70 |
| Resolved name | ui_draw_prim_k13 |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005e9440
**Callees:** FUN_005cab10
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
UI overlay primitive: emits draw kind 0x13 subtype 1 at origin, sentinel color, flag 0x10.

## Notes / uncertainty
Parameterless zero-extent marker node kind0x13 flags0x10. Marker role (separator/section token) inferred; twin of k14.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d9d70.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
