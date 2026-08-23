# 0x001a4cd0 rpc_call_sync_2arg

| field | value |
|---|---|
| Original address | 0x001a4cd0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001a4cd0 |
| Resolved name | rpc_call_sync_2arg |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001d31b0
**Callees:** FUN_00111668, FUN_0019eb00, FUN_0019ec60, FUN_001a2430, FUN_001a2490, FUN_001a5550
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
Blocking wrapper of FUN_001a5550(a,b): arm 0x8000000c flag, run op, on rc>=0 drain events (FUN_0019eb00/FUN_00111668 yield) then flag, return rc unchanged. Underlying op semantics inferred.

## Raw decompilation
`sources/executables/netstack-decompile/FUN_001a4cd0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
