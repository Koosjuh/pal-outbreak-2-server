# 0x0062e3c0 lobby_state3_substate_dispatch

| field | value |
|---|---|
| Original address | 0x0062e3c0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062e3c0 |
| Resolved name | lobby_state3_substate_dispatch |
| Subsystem | lobby |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0062d640
**Callees:** FUN_0062e440, FUN_0062e5b0, FUN_0062e720, FUN_0062e800
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** struct+0xf sub-state (0-3)

## Behavioral explanation
Major-state 3 sub-dispatcher on struct+0xf: 0->e440(join flow), 1->e5b0(member gate), 2->e720(leave), 3->e800(back/exit).

## Notes / uncertainty
Thin jump table for major-state-3 (in-room) on state+0xf: 0→e440(join),1→e5b0(member gate),2→e720(leave),3→e800(back). Keys on +0xf (major sub-selector), distinct from +0x10 nested step. Sub-handler labels inferred from SM order, not yet decoded.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062e3c0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
