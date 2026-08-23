# 0x001c2670 conn_teardown_sm

| field | value |
|---|---|
| Original address | 0x001c2670 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c2670 |
| Resolved name | conn_teardown_sm |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001c2770
**Referenced globals:** 0x35b74c/0x35b74d retry
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** *param_2 state

## Behavioral explanation
Small 2-state wrapper that spins the shutdown sub-machine FUN_001c2770; on completion returns code 4 and clears all out-fields.

## Notes / uncertainty
2-phase driver around shutdown worker FUN_001c2770: arms (phase0->1), pumps until worker done, returns terminal code 4 zero-clearing the out-tuple; saturating retry bump 0x35b74d toward 0x35b74c. Retry ceiling use inferred.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c2670.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
