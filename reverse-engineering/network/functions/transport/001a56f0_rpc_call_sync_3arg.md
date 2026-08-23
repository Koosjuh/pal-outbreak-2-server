# 0x001a56f0 rpc_call_sync_3arg

| field | value |
|---|---|
| Original address | 0x001a56f0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001a56f0 |
| Resolved name | rpc_call_sync_3arg |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001d3130
**Callees:** FUN_00111668, FUN_0019eb00, FUN_0019ec60, FUN_001a2430, FUN_001a2490, FUN_001a57c0
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
3-arg twin of a4cd0 wrapping FUN_001a57c0; identical 0x8000000c arm + drain skeleton. Op meaning inferred by analogy.

## Raw decompilation
`sources/executables/netstack-decompile/FUN_001a56f0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
