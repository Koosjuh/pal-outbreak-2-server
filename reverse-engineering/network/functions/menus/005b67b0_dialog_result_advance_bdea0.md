# 0x005b67b0 dialog_result_advance_bdea0

| field | value |
|---|---|
| Original address | 0x005b67b0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b67b0 |
| Resolved name | dialog_result_advance_bdea0 |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005bdea0, FUN_005be9a0
**Referenced globals:** cRam006c4b90 (mode); uRam006c4ba0/cRam006c4b9f (step); 0x6c9c28 (arg block)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006c4b90; cRam006c4b9f

## Behavioral explanation
If mode!=6: on result 0 advance menu step and run FUN_005bdea0(0x6c9c28); else redraw 0x6c517c and advance step.

## Notes / uncertainty
Dialog-completion callback stepping create/join SM: both branches reset screen_step(0x6c4ba0)=0 and bump screen_major(0x6c4b9f); result 0 commits via 0x5bdea0(0x6c9c28), nonzero redraws. SM-counter updates exact; commit action (opcode?) not expanded.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b67b0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
