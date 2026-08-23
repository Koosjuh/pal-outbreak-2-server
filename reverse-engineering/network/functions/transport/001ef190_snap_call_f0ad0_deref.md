# 0x001ef190 snap_call_f0ad0_deref

| field | value |
|---|---|
| Original address | 0x001ef190 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ef190 |
| Resolved name | snap_call_f0ad0_deref |
| Subsystem | transport |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001c2770
**Callees:** FUN_001f0ad0
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Dereferences param_1 and forwards *param_1 to FUN_001f0ad0.

## Notes / uncertainty
deref *param_1 -> f0ad0(by-value); teardown-only caller (0x1c2770) => inferred close/shutdown, callee undecompiled.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ef190.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
