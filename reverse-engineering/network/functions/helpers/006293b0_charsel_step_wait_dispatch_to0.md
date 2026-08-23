# 0x006293b0 charsel_step_wait_dispatch_to0

| field | value |
|---|---|
| Original address | 0x006293b0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006293b0 |
| Resolved name | charsel_step_wait_dispatch_to0 |
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
Sub-step: polls FUN_0062a5e0 and, when done, resets msg to state 0.

## Notes / uncertainty
Twin of 0x629330, terminal state 0 instead of 2. Which caller step selects to-0 vs to-2 untraced.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006293b0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
