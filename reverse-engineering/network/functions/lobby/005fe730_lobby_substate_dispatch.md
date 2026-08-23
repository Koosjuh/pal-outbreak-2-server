# 0x005fe730 lobby_substate_dispatch

| field | value |
|---|---|
| Original address | 0x005fe730 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005fe730 |
| Resolved name | lobby_substate_dispatch |
| Subsystem | lobby |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005fe620
**Callees:** FUN_005fe800, FUN_005fe8d0, FUN_005fec10, FUN_005fec30, FUN_005fed10, FUN_005fed70, FUN_005fede0, FUN_005ff690, FUN_005ff760
**Referenced globals:** +0xf sub-state
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0xf sub-state

## Behavioral explanation
Dispatches the base lobby screen sub-state (+0xf, 0-8) to its per-step handler (init FUN_005fe800 .. FUN_005ff760).

## Notes / uncertainty
Flat 0..8 jump table for base-lobby substate ctx+0xf → step handlers FUN_005fe800..FUN_005ff760; default no-op. Per-step semantic roles not labeled (needs deep read of each handler).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005fe730.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
