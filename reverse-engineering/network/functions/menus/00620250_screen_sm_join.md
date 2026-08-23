# 0x00620250 screen_sm_join

| field | value |
|---|---|
| Original address | 0x00620250 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00620250 |
| Resolved name | screen_sm_join |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_00622180
**Callees:** FUN_0061e750, FUN_0061e7f0, FUN_0061e800, FUN_0061e910, FUN_0061e940, FUN_0061ea20, FUN_0061f0d0, FUN_0061f0e0, FUN_0061f0f0, FUN_0061f1d0, FUN_0061f2d0, FUN_0061f8c0, FUN_0061f970, FUN_0061f9d0
**Referenced globals:** 0x7152e1 substate; 0x7152e4 timer; 0x7152e8 cursor; 0x7152e6 timer
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam007152e1; sRam007152e4; sRam007152e6; sRam007152e8

## Behavioral explanation
Switch-based screen state machine for a join/enter flow: window transitions (e940/e960), input (e7f0/e800), timers; returns 1 accept / -1 abort.

## Notes / uncertainty
Yes/No join confirm; Yes (e8==0) calls func_0x001a6910 net-start + func_0x001a6780 commit -> return 1. Clean switch 0..7. Wire op behind func_0x001a6910 unverified.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00620250.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
