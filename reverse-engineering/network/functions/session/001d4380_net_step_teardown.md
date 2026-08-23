# 0x001d4380 net_step_teardown

| field | value |
|---|---|
| Original address | 0x001d4380 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d4380 |
| Resolved name | net_step_teardown |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001f26e0, FUN_001f2728, FUN_001f2778, FUN_001f33e8
**Referenced globals:** 0x36d648 active flag; 0x36d5a8/0x36d5a0 mode flags
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam0036d648; uRam0036d5a8; uRam0036d5a0

## Behavioral explanation
State step: when active flag set, calls FUN_001f26e0/2728/2778/33e8 (close/reset) and advances when all succeed.

## Notes / uncertainty
Teardown step gated by 0x36d648: issues 4 net-close calls (FUN_001f26e0/2728/2778/33e8) with closing-mode flags 0x36d5a8=1/0x36d5a0=0, advances only when all four return 0. Callee split inferred.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d4380.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
