# 0x005b3510 screen_advance_to_state6

| field | value |
|---|---|
| Original address | 0x005b3510 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b3510 |
| Resolved name | screen_advance_to_state6 |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005b24e0
**Callees:** FUN_005ba7b0, FUN_00606da0, FUN_00618b60
**Referenced globals:** 0x874f35 cRam00874f35 mode
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** struct+0xe screen id; 0x874f35

## Behavioral explanation
Screen-5 tiny handler: on sub-state 1 finalizes (0x606da0), bumps mode 0x874f35 to 1 if unset, and jumps to screen 6.

## Notes / uncertainty
On screen_obj substate(+0xf)==1: runs 3 finalize hooks, latches lobby mode 0->1 (the value the can_enter_* tables read), routes to screen_id(+0xe)=6. SM skeleton exact; hook callee roles inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b3510.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
