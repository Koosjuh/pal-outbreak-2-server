# 0x005b2410 init_overlay_subsystems

| field | value |
|---|---|
| Original address | 0x005b2410 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b2410 |
| Resolved name | init_overlay_subsystems |
| Subsystem | initialization |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ac610, FUN_005ac6f0, FUN_006069b0
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Overlay bring-up/reset: calls a fixed sequence of engine init thunks (alloc 0x12c0 arena + several 001a9xxx setup calls).

## Notes / uncertainty
Straight-line overlay bring-up: arena_alloc(0x12c0) then 6 resident-kernel init thunks (001a9xxx/003b3530). Individual thunk identities unresolved (live outside overlay); subsys_init_* names are placeholders.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b2410.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
