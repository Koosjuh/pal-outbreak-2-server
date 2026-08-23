# 0x001f02e0 snap_rpc_cmd20

| field | value |
|---|---|
| Original address | 0x001f02e0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001f02e0 |
| Resolved name | snap_rpc_cmd20 |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001eed90
**Callees:** FUN_001ef3e0, FUN_001ef3f0, FUN_001ef400
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
No-arg SIF-RPC stub selector 0x20; briefing links op 0x20 to room-list family, so likely a list/enumerate trigger (entries drained via 0x1b pump). List association not runtime-confirmed.

## Raw decompilation
`sources/executables/netstack-decompile/FUN_001f02e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
