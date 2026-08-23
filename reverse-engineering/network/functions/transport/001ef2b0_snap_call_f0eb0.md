# 0x001ef2b0 snap_call_f0eb0

| field | value |
|---|---|
| Original address | 0x001ef2b0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ef2b0 |
| Resolved name | snap_call_f0eb0 |
| Subsystem | transport |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001c0ca0
**Callees:** FUN_001f0eb0
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Bare thunk over FUN_001f0eb0(); no state.

## Notes / uncertainty
nullary forwarder to undecompiled f0eb0; setup-only caller (0x1c0ca0) => inferred one-shot init/query.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ef2b0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
