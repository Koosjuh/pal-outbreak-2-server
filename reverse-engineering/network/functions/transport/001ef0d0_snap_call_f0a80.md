# 0x001ef0d0 snap_call_f0a80

| field | value |
|---|---|
| Original address | 0x001ef0d0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ef0d0 |
| Resolved name | snap_call_f0a80 |
| Subsystem | transport |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001c19e0, FUN_001c2770, FUN_001ee1e0
**Callees:** FUN_001f0a80
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Bare thunk over FUN_001f0a80(); no state.

## Notes / uncertainty
nullary forwarder to undecompiled f0a80; broadest caller set (setup+teardown) => inferred pump/drain, unconfirmed.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ef0d0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
