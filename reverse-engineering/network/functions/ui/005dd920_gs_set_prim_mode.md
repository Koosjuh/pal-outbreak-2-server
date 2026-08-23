# 0x005dd920 gs_set_prim_mode

| field | value |
|---|---|
| Original address | 0x005dd920 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005dd920 |
| Resolved name | gs_set_prim_mode |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005c8ed0, FUN_005c9460, FUN_005ca6a0, FUN_005cd390, FUN_005d5b60, FUN_005dd960, FUN_005dda30
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Thin wrapper: for arg 0x14 or 1, forwards low byte to GS/draw primitive func_0x0018c8d0 (set draw mode).

## Notes / uncertainty
GS prim-begin guard: forwards only modes 0x14/0x1 to func_0x0018c8d0. Exact GS PRIM mapping inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005dd920.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
