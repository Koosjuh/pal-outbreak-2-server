# 0x001c2770 conn_shutdown_sm

| field | value |
|---|---|
| Original address | 0x001c2770 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c2770 |
| Resolved name | conn_shutdown_sm |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001c0100, FUN_001c0f40, FUN_001c19e0, FUN_001c2670
**Callees:** FUN_00106b60, FUN_001c0670, FUN_001ee190, FUN_001ee5f0, FUN_001ee6e0, FUN_001ee770, FUN_001eeb30, FUN_001eeb50, FUN_001eed60, FUN_001eed90, FUN_001eeec0, FUN_001eef50, FUN_001eef80, FUN_001ef000, FUN_001ef070, FUN_001ef0d0, FUN_001ef190
**Referenced globals:** 0x35c3d8 mode; 0x35bec8 src-sel; 0x35a6c0/0x35a6d0 ctx; 0x35a6f4; 0x35ba88/0x35ba98
**Referenced strings:** (fmt 0x2484a0)
**Referenced opcodes:** —
**State vars:** *param_1 state; 0x35c3d8

## Behavioral explanation
Connection close/retry sub-state machine (states 0x00-0x14): tears down socket, retries DNS/connect via FUN_001ee190/ef0d0/eeb50, mode-branches on 0x35c3d8 and src-sel 0x35bec8.

## Notes / uncertainty
Rewrote from classified stub to full 0x00-0x14 graceful-close/drain SM; return 1=drained (confirmed by modeA/B 'd' caller gating). mode(0x35c3d8)/src-sel(0x35bec8) fork closes direct vs query transport. Teardown-helper specifics and link_status codes 0/2/3 inferred.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c2770.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
