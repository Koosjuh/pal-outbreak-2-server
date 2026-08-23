# 0x005acd60 screen_obj_init_substate0

| field | value |
|---|---|
| Original address | 0x005acd60 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005acd60 |
| Resolved name | screen_obj_init_substate0 |
| Subsystem | menus |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005b3790, FUN_00600d10
**Callees:** FUN_005af120, FUN_00637180
**Referenced globals:** 0x6c4b90
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Initializes a screen-object struct: sets tag=1, substate fields [0xe]/[0xf]=0, then arms input/render.

## Notes / uncertainty
Renamed from screen_struct_init_kind1. Screen-object ctor: kind[0]=1, substate-major[0xe]=0 (-> dispatch branch 0 FUN_005acea0), arm input(637180)+render bind(5af120,0x6c4b90). Full struct layout beyond touched offsets not decoded.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005acd60.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
