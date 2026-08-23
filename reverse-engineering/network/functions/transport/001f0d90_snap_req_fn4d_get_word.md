# 0x001f0d90 snap_req_fn4d_get_word

| field | value |
|---|---|
| Original address | 0x001f0d90 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001f0d90 |
| Resolved name | snap_req_fn4d_get_word |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001ef1c0
**Callees:** FUN_001ef3e0, FUN_001ef3f0, FUN_001ef400
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
RPC stub fno 0x4d: no-arg getter, result word at rx+0x00 (distinct layout). Global SN@P value; identity inferred.

## Raw decompilation
`sources/executables/netstack-decompile/FUN_001f0d90.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
