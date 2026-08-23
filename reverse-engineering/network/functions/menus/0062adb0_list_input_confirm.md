# 0x0062adb0 list_input_confirm

| field | value |
|---|---|
| Original address | 0x0062adb0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062adb0 |
| Resolved name | list_input_confirm |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_0062a5e0
**Callees:** FUN_006345e0, FUN_00634ab0, FUN_00637180, FUN_006371d0
**Referenced globals:** 0x6c4610/4618/4620 pad edges; 0x6c4fd3 confirm flag; +0xfc4 list ctx
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** uRam006c4fd3

## Behavioral explanation
Screen-3 handler: on state1 evaluates FUN_00634ab0 (list select, ret -1/0/1) over +0xfc4 with pad globals, then commits (uRam006c4fd3=1) and plays SE; state0 initializes the list widget.

## Notes / uncertainty
2-step scrolling-list input front-end; FUN_00634ab0 tri-state (-1 cancel/0 idle/1 confirm) over list ctx +0xfc4; sets global confirm latch uRam006c4fd3=1 and tears down on decision. 0x42980000=float 76.0 layout. Which concrete list and downstream reader of 0x6c4fd3 not pinned.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062adb0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
