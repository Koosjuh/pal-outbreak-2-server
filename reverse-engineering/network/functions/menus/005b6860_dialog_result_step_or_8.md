# 0x005b6860 dialog_result_step_or_8

| field | value |
|---|---|
| Original address | 0x005b6860 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b6860 |
| Resolved name | dialog_result_step_or_8 |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005be9a0
**Referenced globals:** cRam006c4b90 (mode); cRam006c4b9f (menu step); 0x6c517c
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006c4b90; cRam006c4b9f

## Behavioral explanation
If mode!=6: on result 0 set menu step cRam006c4b9f=8; else increment step and redraw 0x6c517c.

## Notes / uncertainty
Dialog-completion callback (registered by 0x5b4a50): result 0 jumps screen_major(0x6c4b9f)=8 (terminal, matches 0x5b4a50 state-8), nonzero increments + redraws. Branch logic + =8 write exact; route-8 equivalence inferred from shared registration.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b6860.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
