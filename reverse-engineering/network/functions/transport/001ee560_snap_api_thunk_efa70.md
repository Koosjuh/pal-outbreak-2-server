# 0x001ee560 snap_api_thunk_efa70

| field | value |
|---|---|
| Original address | 0x001ee560 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ee560 |
| Resolved name | snap_api_thunk_efa70 |
| Subsystem | transport |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001c3880
**Callees:** FUN_001ee150, FUN_001efa70
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Thin SN@P API thunk: calls FUN_001efa70(arg) then post-processes result via FUN_001ee150; sets no state.

## Notes / uncertainty
post(inner(u16 selector)) two-call thunk; both callees opaque so domain role undetermined.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ee560.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
