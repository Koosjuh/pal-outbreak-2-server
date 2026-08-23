# 0x00634ab0 kbd_input_tick

| field | value |
|---|---|
| Original address | 0x00634ab0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00634ab0 |
| Resolved name | kbd_input_tick |
| Subsystem | menus |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005b45f0, FUN_005dc2b0, FUN_005f4be0, FUN_005f97c0, FUN_005faa60, FUN_00614ad0, FUN_00625190, FUN_0062adb0, FUN_0062d430
**Callees:** FUN_00630010, FUN_00630f20, FUN_00631ff0, FUN_006320f0, FUN_00632c00, FUN_00632ce0, FUN_00633350, FUN_00634460, FUN_00634970, FUN_00634a50, FUN_00635030, FUN_006352e0, FUN_00635940, FUN_00635ab0, FUN_00635c60, FUN_00635cb0, FUN_00635ed0, FUN_00635f80, FUN_00636f90, FUN_006371f0, FUN_00637da0
**Referenced globals:** 0x715da8 (kbd state; +0x2f mode, +0x1d charset, +0x28 tick, +0x32 result, +0x248 redraw, +0x4c text); 0x715b68/0x715b70 (repeat/preset); 0x715bb0 (draw scratch)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x715da8+0x2f (mode); 0x715da8+0x32 (commit/close result); 0x715da8+0x28

## Behavioral explanation
Main per-frame on-screen-keyboard input handler: applies pad-repeat, dispatches d-pad/face buttons (move cursor / select key / confirm / cancel) to layout+candidate handlers, commits or renders text, and returns the commit/close state (+0x32).

## Notes / uncertainty
Per-frame software-keyboard driver; params are pad masks. Big nav/confirm switch, key-record category dispatch (ev+2=0..4), commit path renders text to owner sink, returns +0x32. Several leaf handlers named-by-position only; key_record layout inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00634ab0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
