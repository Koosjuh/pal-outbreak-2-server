# 0x005ae9b0 screen_fsm_list_draw

| field | value |
|---|---|
| Original address | 0x005ae9b0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ae9b0 |
| Resolved name | screen_fsm_list_draw |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ae770
**Callees:** FUN_005af1e0, FUN_005af2c0, FUN_005af2e0, FUN_005b14b0, FUN_005b9060, FUN_005b9110, FUN_0062fea0
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x5198 state; +0x519a countdown

## Behavioral explanation
Companion per-frame FSM for the same list overlay: state 0 loads a resource, state 1 runs a countdown (+0x519a) and draws a centered localized string via ui_draw_text, state 2 counts down and advances.

## Notes / uncertainty
Phase-1 of 5197: draw+confirm-wait, structurally identical to ae630 but on +0x5198/+0x519a; marquee id 0x14, loc string 0xd centered, 6-frame dismiss. Same font-scaling caveat.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ae9b0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
