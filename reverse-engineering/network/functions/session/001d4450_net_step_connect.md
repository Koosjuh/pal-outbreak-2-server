# 0x001d4450 net_step_connect

| field | value |
|---|---|
| Original address | 0x001d4450 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d4450 |
| Resolved name | net_step_connect |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001f25e0, FUN_001f27c8
**Referenced globals:** 0x36d598 handle
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** iRam0036d598

## Behavioral explanation
State step: FUN_001f25e0 (connect/select), then FUN_001f27c8 status; advances when both report ready.

## Notes / uncertainty
Connect step: FUN_001f25e0(0,2) connect-select then FUN_001f27c8 poll into handle 0x36d598; advances when handle==0 && busy==0. No local failure-reset (relies on outer timeout/teardown). op-selector 2 and semantics inferred.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d4450.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
