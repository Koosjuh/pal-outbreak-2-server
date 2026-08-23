# 0x0062d810 lobby_state1_enter

| field | value |
|---|---|
| Original address | 0x0062d810 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062d810 |
| Resolved name | lobby_state1_enter |
| Subsystem | lobby |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0062d640
**Callees:** FUN_005adc80, FUN_005b68e0, FUN_005b6900, FUN_005bfd80
**Referenced globals:** 0x6c45fc counter
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** struct+0xf sub-state; struct+0x42b screen-id(=5); struct+0x4b7 flag

## Behavioral explanation
Major-state 1 handler: sets screen +0x42b=5, timer +0x9a0=0x708, sends a request via FUN_005bfd80 registering reply callback 0x62d8b0.

## Notes / uncertainty
Major-state-1 2-step sub-SM: substate0 latches 0x6c45fc=sel+1, locks UI, screen id +0x42b=5, timeout +0x9a0=0x708, sends request FUN_005bfd80 reply-handler FUN_0062d8b0; substate1 polls. Which request (enter/create-confirm) depends on undecoded FUN_005bfd80 builder.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062d810.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
