# 0x005dd960 gs_draw_line6

| field | value |
|---|---|
| Original address | 0x005dd960 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005dd960 |
| Resolved name | gs_draw_line6 |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005e0510
**Callees:** FUN_005dd920, FUN_006383e0
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Packs 6 float coords (truncated to shorts) plus a color into a stack struct and submits a line/poly draw via func_0x006383e0.

## Notes / uncertainty
Packs 3 vertices (6 floats->s16) + color into stack packet, prim mode 1, submits via func_0x006383e0. Line-strip vs tri semantics uncertain.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005dd960.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
