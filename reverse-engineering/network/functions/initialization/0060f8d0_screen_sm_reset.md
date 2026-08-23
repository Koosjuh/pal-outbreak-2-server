# 0x0060f8d0 screen_sm_reset

| field | value |
|---|---|
| Original address | 0x0060f8d0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0060f8d0 |
| Resolved name | screen_sm_reset |
| Subsystem | initialization |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_006101a0, FUN_00623090
**Callees:** —
**Referenced globals:** uRam0070d1d8 (screen SM state); uRam0070d1d0 (mode arg)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** iRam0070d1d8 screen state

## Behavioral explanation
Resets the top screen state machine: uRam0070d1d8=0, uRam0070d1d0=param, then func_0x001af050 / func_0x001ad8b0(1) (reinit render/audio context).

## Notes / uncertainty
Resets network-menu screen SM: substate=0, mode=param, render_ctx_init (001af050), render_ctx_step(1) (001ad8b0). mode seeds dispatcher FUN_0060f910 case 0. Returns const 0.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0060f8d0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
