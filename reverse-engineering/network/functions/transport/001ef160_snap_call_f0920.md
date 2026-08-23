# 0x001ef160 snap_call_f0920

| field | value |
|---|---|
| Original address | 0x001ef160 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ef160 |
| Resolved name | snap_call_f0920 |
| Subsystem | transport |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001c19e0
**Callees:** FUN_001f0920
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Bare thunk over FUN_001f0920(); no state.

## Notes / uncertainty
nullary forwarder to undecompiled f0920; poll-status read inferred.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ef160.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
