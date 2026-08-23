# 0x00629330 charsel_step_wait_dispatch_to2

| field | value |
|---|---|
| Original address | 0x00629330 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00629330 |
| Resolved name | charsel_step_wait_dispatch_to2 |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00628e10
**Callees:** FUN_0062a5e0
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Sub-step: polls FUN_0062a5e0 and, when done, sets msg state to 2.

## Notes / uncertainty
Step handler: pumps overlay_menu_dispatch_695d10; on done sets task state 2/step 0; returns -1. Meaning of terminal state 2 untraced.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00629330.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
