# 0x0062d380 enter_step2_dispatch

| field | value |
|---|---|
| Original address | 0x0062d380 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062d380 |
| Resolved name | enter_step2_dispatch |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_0062cf50
**Callees:** FUN_0062d3d0, FUN_0062d430
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Two-way dispatch on task +1 (0/1) into FUN_0062d3d0 / FUN_0062d430 (enter submachine mode-2 steps; callees outside this slice).

## Notes / uncertainty
2-way dispatch on task+1: 0->FUN_0062d3d0, 1->FUN_0062d430, else 0 (room-enter submachine mode-2). Dispatch structure certain; per-step roles inferred (callees unread).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062d380.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
