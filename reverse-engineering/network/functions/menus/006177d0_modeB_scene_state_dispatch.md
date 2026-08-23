# 0x006177d0 modeB_scene_state_dispatch

| field | value |
|---|---|
| Original address | 0x006177d0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006177d0 |
| Resolved name | modeB_scene_state_dispatch |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005acab0
**Callees:** FUN_00617870, FUN_006178a0, FUN_00617910, FUN_00617980, FUN_00617a00
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0xe major-state (0..5)

## Behavioral explanation
Per-tick dispatcher for a type-0x0b scene object: routes major-state +0xe (0..5) to six sub-handlers.

## Notes / uncertainty
6-way switch on obj+0xe routing type-0x0b scene states 0-3 to sub-handlers, 4/5 to re-init trampoline. Control flow fully recovered. Recycle states 4 vs 5 identical (likely compiler artifact).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006177d0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
