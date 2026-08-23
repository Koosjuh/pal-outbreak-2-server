# 0x005f9d40 arealist_recompute_cursor_bounds

| field | value |
|---|---|
| Original address | 0x005f9d40 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f9d40 |
| Resolved name | arealist_recompute_cursor_bounds |
| Subsystem | menus |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f9540, FUN_005f9e50
**Callees:** —
**Referenced globals:** 0x6970a0 area/scenario list base (stride 0x14a8); 0x69713a-0x69713c cursor/min/max bytes; 0x006970f4 entry count
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** bRam006970f4 list count; 0x69713a cursor byte

## Behavioral explanation
Recomputes per-entry cursor clamp bounds for the 0x20-slot area/scenario list (stride 0x14a8 @0x6970a0).

## Notes / uncertainty
Two-pass cursor-bound recompute over 32-slot area/scenario model (stride 0x14a8) with cross-slot dependency triples (target,min,max) at slot+cursor*0x60. Arithmetic exact; dependency domain (area->scenario/difficulty) inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f9d40.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
