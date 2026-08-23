# 0x00628f00 charsel_task_init

| field | value |
|---|---|
| Original address | 0x00628f00 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00628f00 |
| Resolved name | charsel_task_init |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00628e10
**Callees:** FUN_005af400, FUN_00629a40, FUN_00629d00
**Referenced globals:** param+0x9ce mode-flag
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Sub-step 0 of the charsel machine: seeds the msg timer (8 frames unless +0x9ce set), then builds the widget list (FUN_00629a40) and render callback (FUN_00629d00).

## Notes / uncertainty
Charsel substep 0: advance substep, arm timer +0xa=8 (or 0 when obj+0x9ce set), clear +0xc..+0xf, SE cue, build widgets (FUN_00629a40) + render cb (FUN_00629d00). +0x9ce mode-flag meaning inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00628f00.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
