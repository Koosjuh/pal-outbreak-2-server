# 0x001eee60 snap_call_f0750

| field | value |
|---|---|
| Original address | 0x001eee60 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001eee60 |
| Resolved name | snap_call_f0750 |
| Subsystem | transport |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001c19e0
**Callees:** FUN_001f0750
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Bare thunk over FUN_001f0750(); returns its result. No state.

## Notes / uncertainty
nullary forwarder to undecompiled f0750 (0x1f0xxx family); role (poll status accessor) inferred from 0x1c19e0 caller cluster.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001eee60.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
