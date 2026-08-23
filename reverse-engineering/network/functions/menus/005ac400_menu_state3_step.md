# 0x005ac400 menu_state3_step

| field | value |
|---|---|
| Original address | 0x005ac400 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ac400 |
| Resolved name | menu_state3_step |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ac8a0
**Callees:** FUN_00605f80, FUN_00605fa0, FUN_00606f60, FUN_00618b60, FUN_00618c30
**Referenced globals:** 0x6c4fab(substate); 0x6c4faa; 0x6c4fac; 0x6c4fad; 0x6c4fde(busy flag); 0x6c4ba6(timer)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006c4fab; uRam006c4faa; uRam006c4fde

## Behavioral explanation
Top-state 3 step machine; drives substate fab through init/poll (FUN_00605fa0) with net-glue calls, then frame-commit 618c30.

## Notes / uncertainty
Top-state 3 SM: substate0 start async(605f80), substate1 poll(605fa0) tri-state (<0 err teardown / >0 done reset to state0 / 0 pending), substate2 idle; sets active flag 0x6c4fde, frame-commit each tick. Concrete async op not decoded.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ac400.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
