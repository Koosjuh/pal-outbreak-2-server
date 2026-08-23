# 0x005aca50 menu_state4_enter

| field | value |
|---|---|
| Original address | 0x005aca50 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005aca50 |
| Resolved name | menu_state4_enter |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ac8a0
**Callees:** FUN_006063a0, FUN_00618b60
**Referenced globals:** 0x6c4fab; 0x6c4faa; 0x874f7c
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** uRam006c4fab; uRam006c4faa

## Behavioral explanation
Top-state 4 handler: tears down then transitions to state 5 (fab=0, faa=5), clears 874f7c.

## Notes / uncertainty
Top-state 4: one-shot bridge - teardown + FUN_006063a0 state-5 setup, then top_screen=5/top_substate=0, clear 0x874f7c. Identity of screen 5 / 006063a0 payload inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005aca50.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
