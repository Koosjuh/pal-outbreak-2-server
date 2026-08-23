# 0x001ee900 snap_call_f05c0_1_4

| field | value |
|---|---|
| Original address | 0x001ee900 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ee900 |
| Resolved name | snap_call_f05c0_1_4 |
| Subsystem | transport |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001c0f40
**Callees:** FUN_001f05c0
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Fixed-argument wrapper: FUN_001f05c0(1,4,param_1). Passes constants 1 and 4 plus a caller pointer.

## Notes / uncertainty
forwards (1,4,ptr) to undecompiled 0x1f0xxx-family f05c0; (1,4) selector meaning inferred from connect-SM caller only.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ee900.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
