# 0x001d44d0 net_state_init

| field | value |
|---|---|
| Original address | 0x001d44d0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d44d0 |
| Resolved name | net_state_init |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** —
**Referenced globals:** 0x36d560 state-ready flag; 0x36d578 flag
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** uRam0036d560; uRam0036d578

## Behavioral explanation
Init step: clears *param_1 and sets state-machine ready flags 0x36d560/0x36d578=1.

## Notes / uncertainty
Trivial: clears *param_1, arms 0x36d560/0x36d578=1 (state-machine gate later tested by 001d44f0). No caller found; meaning of 0x36d578 unproven.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d44d0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
