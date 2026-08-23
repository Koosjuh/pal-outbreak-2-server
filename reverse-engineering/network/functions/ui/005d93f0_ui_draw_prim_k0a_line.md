# 0x005d93f0 ui_draw_prim_k0a_line

| field | value |
|---|---|
| Original address | 0x005d93f0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d93f0 |
| Resolved name | ui_draw_prim_k0a_line |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ed1f0, FUN_005f2450
**Callees:** FUN_005cab10
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
UI overlay primitive wrapper: emits draw kind 0x0a subtype 1 with 4 coords, color sentinel, flag 0.

## Notes / uncertainty
Renamed from ui_draw_prim_k10 (kind is 0x0a not screen 0x10). Generic line/rule primitive, NO bounds grow, flags=0. Not wire op0a.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d93f0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
