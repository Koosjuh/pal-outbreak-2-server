# 0x001c0e60 conn_mode_dispatch

| field | value |
|---|---|
| Original address | 0x001c0e60 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c0e60 |
| Resolved name | conn_mode_dispatch |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001c0670
**Referenced globals:** 0x248460 mode-vtable
**Referenced strings:** (fmt 0x248470)
**Referenced opcodes:** —
**State vars:** *param_1 conn-type

## Behavioral explanation
Dispatcher: logs then jumps through PTR_FUN_00248460[type] (type = *param_1) to the per-mode connection state machine (e.g. FUN_001c0f40/19e0).

## Notes / uncertainty
Verified against raw: trace-log (tag 0x1b) then unbounded vtable dispatch PTR_FUN_00248460[*param_1], 8 args forwarded. Full vtable membership beyond mode A/B not enumerated.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c0e60.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
