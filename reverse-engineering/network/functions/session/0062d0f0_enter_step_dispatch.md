# 0x0062d0f0 enter_step_dispatch

| field | value |
|---|---|
| Original address | 0x0062d0f0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062d0f0 |
| Resolved name | enter_step_dispatch |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0062cf50
**Callees:** FUN_0062d140, FUN_0062d1b0
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Two-way dispatch on task +1 (0/1) into the enter request-init (FUN_0062d140) or record-build/send (FUN_0062d1b0) step; returns success.

## Notes / uncertainty
2-way step selector on task+0x01 into FUN_0062d140(init,step0)/FUN_0062d1b0(build-send,step1); returns sub-step success. Default (non-0/1) path returns uninit v0 (decompiler artifact); which opcode the callees emit not confirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062d0f0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
