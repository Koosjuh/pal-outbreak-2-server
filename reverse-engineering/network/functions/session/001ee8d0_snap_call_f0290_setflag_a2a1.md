# 0x001ee8d0 snap_call_f0290_setflag_a2a1

| field | value |
|---|---|
| Original address | 0x001ee8d0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ee8d0 |
| Resolved name | snap_call_f0290_setflag_a2a1 |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001c0f40
**Callees:** FUN_001f0290
**Referenced globals:** 0x37a2a1 (SNAP mode flag=1)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x37a2a1

## Behavioral explanation
Calls FUN_001f0290() and sets mode flag 0x37a2a1=1 (enable-something).

## Notes / uncertainty
Calls 001f0290, latches feature flag 0x37a2a1=1 (paired clear in 001eed90). Feature gated + callee return meaning unknown.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ee8d0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
